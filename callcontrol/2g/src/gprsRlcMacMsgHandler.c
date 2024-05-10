/*
*############################################################################
*
*                   *** FXLynx Technologies Ltd. ***
*
*     The information contained in this file is the property of FXLynx
*     Technologies Ltd. Except as specifically authorized in writing by
*     FXLynx Technologies Ltd. The user of this file shall keep information
*     contained herein confidential and shall protect same in whole or in
*     part from disclosure and dissemination to third parties.
*
*     Without prior written consent of FXLynx Technologies Ltd. you may not
*     reproduce, represent, or download through any means, the information
*     contained herein in any way or in any form.
*
*       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : gprsRlcMacMsgHandler.c
*
* Description : Function to support processing of incoming data received from the L1
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/

#include "dataIndMsgHandler.h"
#include "gprs.h"
#include "l1Constants.h"
#include "l1InterfaceManager.h"
#include "gsmData.h"
#include "sysInfo.h"
#include "lapdm.h"
#include "linkedlist.h"
#include <pthread.h>
#include <arpa/inet.h>
#include <assert.h>
#include "logManager.h"
#include "gsmCommon.h"
#include "fxLSocketInterfaceApi.h"
#include "ratSocketItf.h"
#include "transactionMemoryManager.h"
#include "sms.h"


#ifdef FEA_GPRS

extern int exitGsmAppThreads;
extern queue dataIndQ ;
extern stateDataInd llcIndRcvdstate;
extern pthread_cond_t       condLlcInd;
extern pthread_mutex_t     mutexLlcInd;
extern gsm_trx * trx_g;
extern signed int usf[8];

extern void clearGprsContext(gprsInfo* info);
extern gprsInfo* gprsFindUsingLogicalChannel(logicalChannelIdentity * ch_id, tOCT_UINT8 tfi, tOCT_UINT32 fn);
extern tOCT_UINT8* encodeRlcMacPdu(gprsInfo *info, tOCT_UINT8 msg);
void pushGprsReqToTxDataQ(gprsInfo* info , const tOCT_UINT8 * const stdMsgBuf);
void rlcMacDataIndHandler();
void gprsInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);

stateDataInd rlcIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
pthread_cond_t       condRlcInd  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutexRlcInd = PTHREAD_MUTEX_INITIALIZER;
unsigned int noOfAttemptedRegistrationInGprs;
gprsInfo	*llcInfo = NULL;		//Used in llcHandler.c
tOCT_UINT8 controlMsg = 2, pcaRcvd = 0, proc4Pua ;

void * rlcIndMsgHandler(void *nothing)
{
	int ret = 0 , dataAvailable = FALSE;
	noOfAttemptedRegistrationInGprs = 0;
	logPrint(LOG_DEBUG , "RLC: rlcIndMsgHandler Thread Initialized");
	while(1)
	{
		pthread_mutex_lock(&mutexRlcInd);

		while (rlcIndRcvdstate != STATE_DATAIND_RECEIVED)
		pthread_cond_wait(&condRlcInd, &mutexRlcInd);

        if (exitGsmAppThreads)
        {
             rlcIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
		     dataAvailable = FALSE;
		     pthread_mutex_unlock(&mutexRlcInd);
             pthread_exit(NULL);
        }
		
		dataAvailable = TRUE;
		rlcIndRcvdstate = STATE_DATAIND_NOT_RECEIVED ;
		pthread_mutex_unlock(&mutexRlcInd);

		if(dataAvailable == TRUE)
		{
			rlcMacDataIndHandler();
			dataAvailable = FALSE;
		}
	}
	return (void*)ret;
}

void rlcMacDataIndHandler()
{
	tOCT_UINT8 sapi, *sendMsg = NULL ;
	tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA * data_ind = NULL;
	data_ind = deQueue(&dataIndQ);
	do
	{
		if(data_ind != NULL)
		{
			sapi  = (tOCT_UINT8) data_ind->LchId.bySAPI;

			if(sapi == cOCTVC1_GSM_SAPI_ENUM_PDTCH)
			{
				gprsInfo* info = NULL;
				tOCT_UINT8   tfi = 0, cv = 0xFF;
				logicalChannelIdentity ch_id;
				ch_id.txSLotNum = data_ind->LchId.byTimeslotNb;;
				ch_id.subChNum = 0;
				
				proc4Pua = 1;
				if(((data_ind->Data.abyDataContent[PAYLOAD_TYPE_OCTET] >> 6) & 0x01) && (((data_ind->Data.abyDataContent[PAYLOAD_TYPE_OCTET+1] >> 2)& 0x01) == 0x01))
				{
					logPrint(LOG_DEBUG,"RLC: Pkt_Cntrl_Ack rcvd ulFrame 0x_%x",data_ind->Data.ulFrameNumber);
					info = gprsFindUsingLogicalChannel(&ch_id,tfi, data_ind->Data.ulFrameNumber);
					if((info != NULL))// && (info->userAltState == WAIT_FOR_PKT_CNTRL_ACK))
					{
						logPrint(LOG_DEBUG,"User = %p : RLC: Pkt_Cntrl_Ack rcvd ",info);
						if(info->userState == DOWNLINK_ASSGN_SENT)
						{
							sendMsg = encodeRlcMacPdu(info, PKT_UPLINK_ACK_NACK);
							pushGprsReqToTxDataQ(info , sendMsg);
						}
						else if((info->userState == PKT_UPLINK_ACK_NACK_SENT) && (info->userAltState == WAIT_FOR_PKT_CNTRL_ACK))
						{
							logPrint(LOG_DEBUG,"Unlocking LLC");
							pthread_mutex_lock(&mutexLlcInd);
						 	{
								info->cv = 0xFF;
								info->bufIndex = 0x00;
								llcInfo = info;
								llcIndRcvdstate = STATE_DATAIND_RECEIVED;

						 	}
							pthread_mutex_unlock(&mutexLlcInd);
							pthread_cond_signal(&condLlcInd);
						}
					}
					else
						logPrint(LOG_DEBUG,"RLC: INFO == NULL for PKT_CNTRL_ACK");

					return;
				}
				else
				{
					if((data_ind->Data.abyDataContent[PAYLOAD_TYPE_OCTET] >> 6) == UL_RLC_DATA_BLOCK)
					{
						tfi = ((data_ind->Data.abyDataContent[TFI_OCTET] & 0x3E) >> 1);
						cv = ((data_ind->Data.abyDataContent[CV_OCTET] & 0x3C) >> 2);
					}
					else if((data_ind->Data.abyDataContent[PAYLOAD_TYPE_OCTET] >> 6) == UL_RLC_MAC_MESSAGE)
					{
						tfi |= ((data_ind->Data.abyDataContent[TFI_OCTET] & 0x03) << 3);
						tfi |= ((data_ind->Data.abyDataContent[TFI_OCTET+1] & 0xE0) >> 5);
						controlMsg = 1;
					}
					logPrint(LOG_DEBUG,"RLC: Rcvd TFI %d cv %d",tfi,cv);
					info = gprsFindUsingLogicalChannel(&ch_id,tfi, 0);
				}
				if(info == NULL)
				{
					logPrint(LOG_ERR , "RLC: Could not find user for GPRS timeslot = %d tfi %d" , data_ind->LchId.byTimeslotNb,tfi);
					return;
				}
				else if((info != NULL) && (info->cv <= cv) && (controlMsg == 2))
				{
					//logPrint(LOG_DEBUG,"Ignore CV %d",cv);
					return;
				}
				if(isTimerRunning(&info->tmr))
					timerStop(&info->tmr);
				//Send PKT_UPLINK_ACK/NACK
				info->tfi = tfi;
				logPrint(LOG_DEBUG,"User : %p :RLC: _cv %d",info,cv);
				decodeRlcMacPdu(data_ind->Data.abyDataContent,info);
				if((info->cv != 0) && proc4Pua)
				{
					sendMsg = encodeRlcMacPdu(info, PKT_UPLINK_ACK_NACK);
					pushGprsReqToTxDataQ(info , sendMsg);
				}

				if((info->cv == 0) && (cv != 0xFF))
				{
					if(((info->llcBuf[LLC_HDR_LEN] & 0x0f) == 0x08) && ((info->llcBuf[LLC_HDR_LEN+1] & 0x0f) == 0x01))
					{
						logPrint(LOG_INFO,"User = %p : RLC: GRPS_ATTACH rcvd",info);
						info->userPrevState = info->userState;
						info->userState = ATTACH_REQ_RECEIVED;
						info->ulFrameNum = data_ind->Data.ulFrameNumber;
						logPrint(LOG_INFO,"User = %p : RLC: CV = 0 rvcd with frameNo 0x%x",info,data_ind->Data.ulFrameNumber);
						sendMsg = encodeRlcMacPdu(info, PKT_DOWNLINK_ASSGN);
						pushGprsReqToTxDataQ(info , sendMsg);
					}
					else if(((info->llcBuf[LLC_HDR_LEN] & 0x0f) == 0x08) && ((info->llcBuf[LLC_HDR_LEN+1] & 0x0f) == 0x08))
					{
						logPrint(LOG_INFO,"User = %p : RLC: GRPS_RAU_REQ rcvd",info);
						info->userPrevState = info->userState;
						info->userState = ATTACH_REQ_RECEIVED;
						info->ulFrameNum = data_ind->Data.ulFrameNumber;
						logPrint(LOG_INFO,"User = %p : RLC: CV = 0 rvcd with frameNo 0x%x",info,data_ind->Data.ulFrameNumber);
						sendMsg = encodeRlcMacPdu(info, PKT_DOWNLINK_ASSGN);
						pushGprsReqToTxDataQ(info , sendMsg);
					}

				 }
			}
		}
	  data_ind = NULL;
	  data_ind = deQueue(&dataIndQ);
	} while(data_ind != NULL);
}



void pushGprsReqToTxDataQ(gprsInfo* info , const tOCT_UINT8 * const sndMsg)
{
	 pushMsgToTransactionMemoryManager((void*)sndMsg , &info->userLogicalChannel, TRUE); // Put this message at end of Queue ie tail
	//Set the timer after sending the request to UE.
	return;
}

void gprsInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr)
{
    gprsInfo *info = (gprsInfo*)infoPtr;
    if(info != NULL) // For now just clean up that user
    {
		logPrint(LOG_INFO, "User = %p : RLC: Timer Expired UserState = %d , UserPrevState = %d" ,
												 info, (info->userState) , (info->userPrevState) );
        clearGprsContext(info);
    }
}


#endif //FEA_GPRS
