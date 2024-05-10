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
* File Name   : llcHandler.c
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
extern gprsInfo	*llcInfo;
extern gsm_trx * trx_g;

void llcDataIndHandler();
void constructPDU(gprsInfo * info, tOCT_UINT8 msg);
extern void constructUplinkAckNack(gprsInfo *);
extern void pushGprsReqToTxDataQ(gprsInfo* info , const tOCT_UINT8 * const stdMsgBuf);

stateDataInd llcIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
pthread_cond_t       condLlcInd  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutexLlcInd = PTHREAD_MUTEX_INITIALIZER;

//tOCT_UINT8 tmpLlcBuf[GPRS_MACBLOCK_LEN];		//Temporary, Length TBD yet


const tOCT_UINT8 const llcGmmIdReq[GPRS_MACBLOCK_LEN] =
{
    0x00, 0x41, 0xC0, 0x01, 0x08, 0x15, 0x02, 0xDE, 0x8E, 0x9A,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

const tOCT_UINT8 const llcGmmAttachAccept[GPRS_MACBLOCK_LEN] =
{
    0x00, 0x01, 0xC0, 0x09, 0x08, 0x02, 0x01, 0x2A, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x2B, 
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

const tOCT_UINT8 const gmmAttachRej[GPRS_MACBLOCK_LEN] =
{
    0x01, 0xC0, 0x05, 0x08, 0x04, 0x07, 0xac, 0x30, 0xd2, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

const tOCT_UINT8 const gmmRauRej[GPRS_MACBLOCK_LEN] =
{
    0x01, 0xC0, 0x05, 0x08, 0x0b, 0x07, 0x00, 0xd9, 0xee, 0x89,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};




void * llcIndMsgHandler(void *nothing)
{
	int ret = 0 , dataAvailable = FALSE;
	logPrint(LOG_DEBUG , "LLC: llcIndMsgHandler Thread Initialized\n");
	while(1)
	{
		pthread_mutex_lock(&mutexLlcInd);

		while (llcIndRcvdstate != STATE_DATAIND_RECEIVED)
		pthread_cond_wait(&condLlcInd, &mutexLlcInd);

    if (exitGsmAppThreads)
    {
     llcIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
		 dataAvailable = FALSE;
		 pthread_mutex_unlock(&mutexLlcInd);
     pthread_exit(NULL);
    }
		
		dataAvailable = TRUE;
		llcIndRcvdstate = STATE_DATAIND_NOT_RECEIVED ;
		pthread_mutex_unlock(&mutexLlcInd);

		if(dataAvailable == TRUE)
		{
			llcDataIndHandler();
			dataAvailable = FALSE;
		}
	}
	return (void*)ret;
}

void constructPDU(gprsInfo * info, tOCT_UINT8 msg)
{
tOCT_UINT8 *sendMsg = NULL;

bzero(&info->tmpLlcBuf,GPRS_MACBLOCK_LEN);

switch(msg)
{
	case GMM_ID_REQ_IMEI:
	case GMM_ID_REQ_IMSI:
	{
		memcpy(&info->tmpLlcBuf[1], &llcGmmIdReq, GPRS_MACBLOCK_LEN);
		info->tmpLlcBuf[0] = 0x09;	//Length of LLC PDU

		if(msg == GMM_ID_REQ_IMEI)
			logPrint(LOG_DEBUG,"User = %p : LLC: GMM_ID_REQ_IMEI",info);
		else
		{
			info->tmpLlcBuf[5] = 0x01; 
			logPrint(LOG_DEBUG,"User = %p : LLC: GMM_ID_REQ_IMSI",info);
		}
			info->userPrevState = info->userState;
			info->userState = WAIT_FOR_GMM_ID_RSP; 
		  sendMsg = encodeRlcMacPdu(info,PKT_DATA_BLOCK);
	}
	break;

	case GMM_ATTACH_REJECT:
	{
		memcpy(&info->tmpLlcBuf[1], &gmmAttachRej, GPRS_MACBLOCK_LEN);
		info->tmpLlcBuf[0] = 0x09;	//Length of LLC PDU
		info->fbi = 1;		//Only LLC PDU, hence the last
		logPrint(LOG_DEBUG,"User = %p : LLC: GMM_ATTACH_REJ ",info);
		
		info->userPrevState = info->userState; 
		info->userState = WAIT_FOR_PKT_CNTRL_ACK; 
		sendMsg = encodeRlcMacPdu(info,PKT_DATA_BLOCK);
		
	}
	break;

	case GMM_RAU_REJECT:
	{
		memcpy(&info->tmpLlcBuf[1], &gmmRauRej, GPRS_MACBLOCK_LEN);
		//memcpy(&info->tmpLlcBuf[1], &info->llcBuf[0], LLC_HDR_LEN);
		info->tmpLlcBuf[0] = 0x0A;	//Length of LLC PDU
		//info->tmpLlcBuf[0] |= 0x40;	//COMMAND/RESPONSE
		info->fbi = 1;		//Only LLC PDU, hence the last
		logPrint(LOG_DEBUG,"User = %p : LLC: GMM_RAU_REJ ",info);
		
		info->userPrevState = info->userState; 
		info->userState = WAIT_FOR_PKT_CNTRL_ACK; 
		sendMsg = encodeRlcMacPdu(info,PKT_DATA_BLOCK);
		
	}
	break;


}//switch
  pushGprsReqToTxDataQ(info , sendMsg);
}

void llcDataIndHandler()
{
	if((llcInfo != NULL) && (llcInfo->llcBuf != NULL))
	{
		//Access llcInfo->llcBuf
		logPrint(LOG_DEBUG,"LLC: info->llcBuf : 0x_%x_%x_%x_%x_%x_%x_%x_%x",
	                        llcInfo->llcBuf[0],llcInfo->llcBuf[1],llcInfo->llcBuf[2],llcInfo->llcBuf[3],
                            llcInfo->llcBuf[4],llcInfo->llcBuf[5],llcInfo->llcBuf[6],llcInfo->llcBuf[7]);
	
		
		if(((llcInfo->llcBuf[LLC_HDR_LEN] & 0x0f) == 0x08) && ((llcInfo->llcBuf[LLC_HDR_LEN+1] & 0x0f) == 0x01))
			{
				logPrint(LOG_INFO,"User = %p : LLC:  ATTACH REQ PDU rcvd", llcInfo);
				constructPDU(llcInfo,GMM_ATTACH_REJECT);
				return;	
			}
		else if(((llcInfo->llcBuf[LLC_HDR_LEN] & 0x0f) == 0x08) && ((llcInfo->llcBuf[LLC_HDR_LEN+1] & 0x0f) == 0x08))
			{
				logPrint(LOG_INFO,"User = %p : LLC: RAU REQ PDU rcvd", llcInfo);
				constructPDU(llcInfo,GMM_RAU_REJECT);
				return;	
			}
	}
}

#endif // FEA_GPRS
