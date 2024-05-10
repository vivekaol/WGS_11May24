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
* File Name   : rtsTxMsgHandler.c
*
* Description : Function to support processing of readyToSend Ind from L1
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/

#include "rtsTxMsgHandler.h"
#include "l1Constants.h"
#include "l1InterfaceManager.h"
#include "gsmData.h"
#include "sysInfo.h"
#include "lapdm.h"
#include <pthread.h>
#include <arpa/inet.h>
#include "userManager.h"
#include "logManager.h"
#include <assert.h>
#include "transactionMemoryManager.h"
#include "../../../sls/inc/octvc1/gsm/octvc1_gsm_evt_swap.h"

#ifdef FEA_GPRS
#include "gprs.h"
#endif

// This buffer is used to send message to L1
tOCT_UINT8 rtsTxBuffer[GSM_TCHF_FRAME_LEN];
extern void userInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
extern int GsmTrxResetDigitalScaling( void );

extern const tOCT_UINT8 const channelRelease[GSM_MACBLOCK_LEN - 2];
extern rts_time * rts_time_g ;


#ifdef FEA_GPRS
extern gprsInfo* gprsFindUsingLogicalChannel(logicalChannelIdentity * ch_id, tOCT_UINT8 tfi, tOCT_UINT32 fn);
extern void gprsInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
tOCT_UINT8 rtsGprsTxBuffer[GPRS_MACBLOCK_LEN];
static tOCT_UINT8 cnt;
tOCT_UINT32	frameNum;
extern tOCT_UINT32 pcaRcvd;
tOCT_UINT8  retransmitPDA = 0;
#endif

const tOCT_UINT8 const fill_frame[GSM_MACBLOCK_LEN] =
{
    0x03, 0x03, 0x01, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B
};

tOCT_UINT8 usf_frame[GSM_MACBLOCK_LEN] =
{
    0x47, 0x94, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B
};

#if defined (FEA_SILENT_CALL) || defined (FEA_VOICE_CALL_TO_TARGET)
tOCT_UINT8 dummy_tch_frame[GSM_TCHF_FRAME_LEN] =
{
    0xFC, 0xAC, 0x9D, 0xD6, 0x74, 0x67, 0x42, 0x91, 0x57, 0x1D, 
    0x17, 0x91, 0x3E, 0x06, 0x4F, 0x52, 0x56, 0xB6, 0x93, 0x7A,
    0x36, 0xAA, 0xE3, 0xF0, 0x1A, 0x95, 0x2A, 0xfA, 0x7E, 0xDC,
    0xB0, 0xAC, 0xD5
};
#endif

extern tOCT_UINT8 usf_frame_tmp[GSM_MACBLOCK_LEN];
extern gsm_trx * trx_g;
extern void pushLayer3ReqToTxDataQ(userInfo* info , const tOCT_UINT8 * const stdMsgBuf, tOCT_UINT8 sapi);
extern void buildSendLogicalChannelDataCmd(tOCT_UINT8 msg[], 
                                           tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA *rtsInd,
                                           tOCTVC1_GSM_PAYLOAD_TYPE_ENUM payloadType);
extern void pushPagingReqToPageQ(blackListedUserInfo* info);

#ifdef FEA_VOICE_CALL_TO_TARGET
extern callContext targetVoiceCallCntxt;
#endif

#ifdef FEA_SILENT_CALL
/*
 * SACCH Header:
 *
 * Octet-1:
 * |  8  | 7 |   6   |    5   4   3   2   1   |
 * |Spare|SRO|FPC EPC| Ordered MS Power level |
 *
 * Octet-2: Timing Advance
 */
void buildSacchHeader(logicalChannelIdentity * ch_id)
{
	userInfo *info = NULL;
	tOCT_UINT8 orderedMSPowerLevel = 0;

	info = userFindUsingLogicalChannel(ch_id);
	if(info != NULL)
	{
		if( (info->userImsi[1] & 0x07) == 0x01)  // Imsi is present in the user Info
		{

			blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

            // Release the Channel if End Silent call command has received
			if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_END_SILENT_CALL) == SET_TRIGGER_FOR_END_SILENT_CALL) )
			{
                info->userState = END_SILENT_CALL;
				info->retransmissionCountForL3Msg = 0;
				// Send Channel Release here.
				if(  ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
                   && (isTimeSlotTypeSupportsTCHF(info->userTchChannel.txSLotNum) == TRUE))
				{
				    pushLayer3ReqToTxDataQ(info , channelRelease, SAPI_TCHF); // Send TCH Channel Release				    
				    logPrint(LOG_DEBUG , "User = %p : Sending channelRelease on TCH/F to End Silent Call\n" , info);
				}
                else if(  ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
                        && (isTimeSlotTypeSupportsTCHH(info->userTchChannel.txSLotNum) == TRUE))
				{
				    pushLayer3ReqToTxDataQ(info , channelRelease, SAPI_TCHH); // Send TCH Channel Release				    
				    logPrint(LOG_DEBUG , "User = %p : Sending channelRelease on TCH/H to End Silent Call\n" , info);
				}
				else
				{
				    if(info->userLogicalChannel.txSLotNum != 0)
                    {            
				        pushLayer3ReqToTxDataQ(info , channelRelease, SAPI_SDCCH); // Send SDCCH Channel Release
                        logPrint(LOG_DEBUG , "User = %p : Sending channelRelease to End Silent Call\n" , info);
                    }
                    else
                    {
                        return;
                    }
				}

				blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_SILENT_CALL;
				
			}
			else
			{
                // Power Control can be done only when silent call is in progress
                if( blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)
#ifdef FEA_2G_ENH_TCH_SILENT_CALL
                                          ||  ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
#endif
                   ))
			    {
				    orderedMSPowerLevel = ms_power_control(trx_g->bts.band, blackUserInfo->uplinkPowerdBm);
				    rtsTxBuffer[0] = orderedMSPowerLevel;
				    rtsTxBuffer[1] = info->newTimingAdvance;
				    //logPrint(LOG_DEBUG , "User = %p : buildSacchHeader: Ordered MS Power level is %d, dBm = %d\n", info, orderedMSPowerLevel ,blackUserInfo->uplinkPowerdBm);
			    }
			    else
			    {
				    rtsTxBuffer[0] = 0;
				    rtsTxBuffer[1] = info->newTimingAdvance;
			    }
		    }
		}
		else
		{
			rtsTxBuffer[0] = 0;
			rtsTxBuffer[1] = info->newTimingAdvance;
		}
	}
}
#endif /* FEA_SILENT_CALL */

void readyToSendIndHandler(tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA *rtsInd)
{
    tOCT_UINT32 fn;
    tOCT_UINT8 tsNum,sc,sapi ;
	userInfo *info = NULL;

	fn = rtsInd->ulFrameNumber;
    // Update our data structures with the current GSM time
    updateRtstime(rts_time_g, fn);

    // Retrive the data from the mask
    tsNum = (tOCT_UINT8) rtsInd->LchId.byTimeslotNb;
    sc    = (tOCT_UINT8) rtsInd->LchId.bySubChannelNb;
    sapi  = (tOCT_UINT8) rtsInd->LchId.bySAPI;

    switch (sapi)
    {
        case cOCTVC1_GSM_SAPI_ENUM_SDCCH:
        {
          	logicalChannelIdentity ch_id ;
            ch_id.txSLotNum = tsNum;
            ch_id.subChNum = sc;
            tOCT_UINT8 *sndMsg = NULL;

            if((sndMsg = popMsgFromTransactionMemoryManager((&ch_id), sapi)) != NULL)
        	{
			    info = userFindUsingLogicalChannel(&ch_id);
				if(info != NULL)
				{
                	memcpy((tOCT_UINT8*)rtsTxBuffer,(tOCT_UINT8*)sndMsg, GSM_MACBLOCK_LEN);
                	buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);

                    if(rtsTxBuffer[0] == 0x01) // This is either L2-ACk or UA frame sent
                    {
                        if(rtsTxBuffer[1] == 0x73)
                            logPrint(LOG_DEBUG , "User = %p : readyToSendIndHandler/SDCCH: Sending UA on TimeSlot = %d , SubChannel = %d\n", info, tsNum , sc );
                        else
                            logPrint(LOG_DEBUG , "User = %p : readyToSendIndHandler/SDCCH: Sending L2-ACK on TimeSlot = %d , SubChannel = %d\n", info, tsNum , sc );
                    }
                    else
                    {
                        logPrint(LOG_DEBUG , "User = %p : readyToSendIndHandler/SDCCH: Sending Message on TimeSlot = %d , SubChannel = %d\n", info, tsNum , sc );
                    }

        			if (info->userPrevState == DISC_RECEIVED)
                    {                        
                        // Wait for 500 ms before deactivating the channels, this is to make sure UA reaches the phone.
                        tOCT_UINT8 retVal = timerStart(&info->tmr , 500 , 0 , &userInfoTimerCbFunction, info);
                        assert(retVal == RC_TCB_OK);
                    }
        			else
        			{
        			    if(info->userState == WAITING_FOR_MT_CONNECT)
                        {
                            tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_FOR_MT_ALERT, 0 , &userInfoTimerCbFunction, info);
                            assert(retVal == RC_TCB_OK);
        			    }
                        else if(info->userState == CALL_CONF_RCVD)
        			    {
                            tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_FOR_RECEIVING_ALERT , 0 , &userInfoTimerCbFunction, info);
                            assert(retVal == RC_TCB_OK);
        			    }                       
                        else if(rtsTxBuffer[0] == 0x01) // This is either L2-ACk or UA frame sent
                        {
                           /* Dont start UE Response timer */
                        }
    				    else
    					{
                            tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
                            assert(retVal == RC_TCB_OK);
    					}
    				}
    			}
                else
                {
    				// User Context not found for this Ts & SubCh, send Fill Frame and Deactivate the channel.
    				memcpy(rtsTxBuffer, fill_frame, GSM_MACBLOCK_LEN);
    				buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);
                    
                    logPrint(LOG_DEBUG, "RTS Ind Received on SDCCH Channel for which User Context is not available, Deactivating the Channel\n");
                    deactivateLogicalChannel(ch_id.txSLotNum , ch_id.subChNum);                    
                    deallocateLogicalChannel(&ch_id);                    
                    logPrint(LOG_DEBUG , "All Logical Channels are DEACTIVATED for the SDCCH and SACCH , TimeSlot = %d , SubChannel = %d   \n", ch_id.txSLotNum , ch_id.subChNum);
                }
         	}
            else
            {
				// There is nothing to send on this Ts & SubCh so send Fill Frame
				memcpy(rtsTxBuffer, fill_frame, GSM_MACBLOCK_LEN);
				buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);
            }
        }
        
        break;

        case SAPI_SACCH:
        {
#ifndef FEA_SILENT_CALL
        	rtsTxBuffer[0] = 0;
        	rtsTxBuffer[1] = info->newTimingAdvance;
#else
            logicalChannelIdentity ch_id ;
        	ch_id.txSLotNum = tsNum;
        	if(isTimeSlotTypeSupportsTCHF(tsNum) == TRUE)
        	  ch_id.subChNum = 0;
        	else
              ch_id.subChNum = sc;

			buildSacchHeader(&ch_id);

            info = userFindUsingLogicalChannel(&ch_id);
            if(info != NULL)
            {
                blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

                if(blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL) ||
                                             ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)))
                {
                    static tOCT_UINT8 si5Sent = 0, si6Sent = 0, measInfoIndex = 0;

                    rtsTxBuffer[0] |= 0x40; // SACCH Repeating
                    rtsTxBuffer[2]  = 0x03; // LapDm Address Field
                    rtsTxBuffer[3]  = 0x03; // LapDm Control Field - UI Frame

        			if(!si5Sent)
                    {
                        memcpy(rtsTxBuffer + 4, blackUserInfo->si5Buf, GSM_MACBLOCK_LEN - 4);
                        si5Sent = TRUE;
                    }
                    else if(!si6Sent)
                    {
                        memcpy(rtsTxBuffer + 4, blackUserInfo->si6Buf, GSM_MACBLOCK_LEN - 4);
                        si6Sent = TRUE;
                    }
                    else
                    {
#ifdef FEA_2G_INTER_RAT_MEAS
                        if((measInfoIndex >= MAX_MI_INSTANCES) ||
                           (measInfoIndex >= blackUserInfo->noOfValidMIInstances))
                          measInfoIndex = 0;

                        memcpy(rtsTxBuffer + 2, &blackUserInfo->mi_buf[measInfoIndex][0], GSM_MACBLOCK_LEN - 2);
                        measInfoIndex++;
#else
                        memcpy(rtsTxBuffer + 2, fill_frame, GSM_MACBLOCK_LEN - 2);
#endif /* FEA_2G_INTER_RAT_MEAS */
                        si5Sent = FALSE;
                        si6Sent = FALSE;
                    }

                    //logPrint(LOG_DEBUG, "DL SACCH Block = %s", gsmL3PduHexdump(rtsTxBuffer, 23));
                }
                else
                {
                    memcpy(rtsTxBuffer + 2, fill_frame, GSM_MACBLOCK_LEN - 2);
                }
            }
            else
#endif /* FEA_SILENT_CALL */
			  memcpy(rtsTxBuffer + 2, fill_frame, GSM_MACBLOCK_LEN - 2);

			buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);
        }
        break;

        /* Starting from L1 Release B-3064, RTS Indication is not sent for FACCH sapi, but sent only for TCH sapi.
           We have to use RTS for TCH sapi as the trigger for sending FACCH messages as well */
        //case SAPI_FACCHF:
        //case SAPI_FACCHH:
        case SAPI_TCHF:
        case SAPI_TCHH:
        {
#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
            if((isTimeSlotTypeSupportsTCHF(tsNum) == TRUE) || 
               (isTimeSlotTypeSupportsTCHH(tsNum) == TRUE))
            {
                logicalChannelIdentity ch_id ;
                ch_id.txSLotNum = tsNum;

                if(sc == SUBCHF)
                  ch_id.subChNum = 0;
                else
                  ch_id.subChNum = sc;
                
                tOCT_UINT8 *sndMsg = NULL;                
                info = userFindUsingLogicalChannel(&ch_id);

                if(info != NULL)
                {
                    /* First check and send if there is any pending FACCH message */
                    if(  (info->userState != CALL_EST)
                      && ((sndMsg = popMsgFromTransactionMemoryManager((&ch_id), sapi)) != NULL))
                    {
                        memcpy((tOCT_UINT8*)rtsTxBuffer,(tOCT_UINT8*)sndMsg, GSM_MACBLOCK_LEN);
                        buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);

                        if(rtsTxBuffer[0] == 0x01) // This is either L2-ACk or UA frame sent
                        {
                            if(rtsTxBuffer[1] == 0x73)
                            {
                                logPrint(LOG_DEBUG , "User = %p : readyToSendIndHandler/FACCH: Sending UA on TimeSlot = %d , SubChannel = %d\n", info, tsNum , sc );
                            }
                            else
                            {
                                logPrint(LOG_DEBUG , "User = %p : readyToSendIndHandler/FACCH: Sending L2-ACK on TimeSlot = %d , SubChannel = %d\n", info, tsNum , sc );
#ifdef FEA_VOICE_CALL_TO_TARGET
                                if((targetVoiceCallCntxt.isOnGoingCall) && (targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum) &&
                                   (targetVoiceCallCntxt.moSubChan == info->userTchChannel.subChNum) && info->userState == WAITING_FOR_CALL_EST)
                                {
                                    info->userState = CALL_EST;
                                    logPrint(LOG_INFO,"User = %p :Target Voice Call ESTABLISHED !!!",info);
                                }
#endif /* FEA_VOICE_CALL_TO_TARGET */
                            }
                        }
                        else
                        {
                            logPrint(LOG_DEBUG , "User = %p : readyToSendIndHandler/FACCH: Sending Message on TimeSlot = %d , SubChannel = %d\n", info, tsNum , sc );
                        }
                        
                        if (info->userPrevState == DISC_RECEIVED)
                        {
                            blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
#ifdef FEA_SILENT_CALL
                            // Restart Silent Call if it has ended abnormally.
                            if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL))
                            {
                                /* Disable DL Mute temporarily if enabled during silent call */
                                if(blackUserInfo->muteDlPwrDuringSilentCall == TRUE)
                                {
                                    /* Reset TS Digital Scaling */
                                    GsmTrxResetDigitalScaling();
                                }
                                blackUserInfo->triggerPagingReq = TRUE;
#ifdef FEA_2G_ENH_TCH_SILENT_CALL
                                pushPagingReqToPageQ(blackUserInfo);
#endif
                            }
#endif
                            // Wait for 500 ms before deactivating the channels, this is to make sure UA reaches the phone.
                            tOCT_UINT8 retVal = timerStart(&info->tmr , 500 , 0 , &userInfoTimerCbFunction, info);
                            assert(retVal == RC_TCB_OK);
                        }
                        else
                        {
                            if(info->userState == WAITING_FOR_MT_CONNECT)
                            {
                                tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_FOR_MT_ALERT, 0 , &userInfoTimerCbFunction, info);
                                assert(retVal == RC_TCB_OK);
                            }
                            else if(info->userState == CALL_CONF_RCVD)
                            {
                                tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_FOR_RECEIVING_ALERT , 0 , &userInfoTimerCbFunction, info);
                                assert(retVal == RC_TCB_OK);
                            }
                            else if(rtsTxBuffer[0] == 0x01) // This is either L2-ACk or UA frame sent
                            {
                               /* Dont start UE Response timer */
                            }
                            else
                            {
                                tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
                                assert(retVal == RC_TCB_OK);
                            }
                        }
                    }
                    else /* No pending FACCH message, send TCH frames */
                    {
                        if(   (info->userState == CALL_EST) 
                           && (info->userPrevState != WAITING_FOR_REL_CMP)
                           && ((sndMsg = popMsgFromTransactionMemoryManager((&ch_id), sapi)) != NULL))
                        {                
                            memset(rtsTxBuffer, 0, sizeof(rtsTxBuffer));
                            memcpy((tOCT_UINT8*)rtsTxBuffer,(tOCT_UINT8*)sndMsg, GSM_TCHF_FRAME_LEN);
                            buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_FULL_RATE);
                        }
                        else
                        {
                            //logPrint(LOG_DEBUG, "TCH frame send\n");
                            memset(rtsTxBuffer, 0, sizeof(rtsTxBuffer));
                            memcpy((tOCT_UINT8*)rtsTxBuffer,(tOCT_UINT8*)dummy_tch_frame, GSM_TCHF_FRAME_LEN);
                            buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_FULL_RATE);
                        }
                    }
                }
                else
                {
#endif /* FEA_SILENT_CALL || FEA_VOICE_CALL_TO_TARGET */
                    // There is nothing to send on this Ts & SubCh so send Fill Frame
                    memcpy(rtsTxBuffer, dummy_tch_frame, GSM_MACBLOCK_LEN);
                    buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_FULL_RATE);
#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
                    // User Context not found for this Ts & SubCh, send Fill Frame and Deactivate the channel.
                    logPrint(LOG_ERR, "RTS Ind Received on TCH Channel(TS = %d, SC =%d) for which User Context is not available, Deactivating the Channel \n", ch_id.txSLotNum , ch_id.subChNum);
                    deactivateLogicalChannel(ch_id.txSLotNum , ch_id.subChNum);                   
                    if(isTimeSlotTypeSupportsTCHF(ch_id.txSLotNum) == TRUE) 
                    {
                        deallocateFullTrafficChannel(&ch_id);                    
                        logPrint(LOG_DEBUG , "All Logical Channels are DEACTIVATED for the TCH/F, FACCH/F and SACCH/F, TimeSlot = %d , SubChannel = %d \n", ch_id.txSLotNum , ch_id.subChNum);
                    }
                    else if(isTimeSlotTypeSupportsTCHH(ch_id.txSLotNum) == TRUE)
                    {
                        deallocateHalfTrafficChannel(&ch_id);
                        logPrint(LOG_DEBUG , "All Logical Channels are DEACTIVATED for the TCH/H, FACCH/H and SACCH/H, TimeSlot = %d , SubChannel = %d \n", ch_id.txSLotNum , ch_id.subChNum);

                    }
                    else
                    {}
                }
            }
            else
            {        
                logPrint(LOG_WARNING, "WARNING: RTS Ind Received on Invalid TCH Channel(TS = %d) !! \n", tsNum);
                // There is nothing to send on this Ts & SubCh so send Fill Frame
                memcpy(rtsTxBuffer, dummy_tch_frame, GSM_MACBLOCK_LEN);
                buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_FULL_RATE);
            }
#endif /* FEA_SILENT_CALL || FEA_VOICE_CALL_TO_TARGET */
        }
        break;
       
#ifdef FEA_GPRS
        case SAPI_PDTCH:
        {
            logicalChannelIdentity ch_id ;
            gprsInfo *info = NULL;
            ch_id.txSLotNum = tsNum;
            ch_id.subChNum = 0;
            tOCT_UINT8 *sndMsg = NULL, tfi = 0, tmrFlag = 0, usf ;

            //tfi = rtsTxBuffer[23];			//TFI To be Set in gprsHandler.c
            if((sndMsg = popGprsMsgFromTransactionMemoryManager(&ch_id, tfi)) != NULL)
            {
                memcpy((tOCT_UINT8*)rtsGprsTxBuffer,(tOCT_UINT8*)sndMsg, GPRS_MACBLOCK_LEN);
				tfi = rtsGprsTxBuffer[23];			//Length To be Set in gprsHandler.c

                logPrint(LOG_DEBUG,"PoppedMsg on TS %d sCh %d rtsGprsTxBuffer[0..1] 0x_%x 0x_%x TFI %d",tsNum, ch_id.subChNum,rtsGprsTxBuffer[0],rtsGprsTxBuffer[1],tfi);

                info = gprsFindUsingLogicalChannel(&ch_id,tfi,0);
                if(info != NULL)
                {
                   //logPrint(LOG_DEBUG,"Info != NULL on TS %d rtsTxBuffer[1] 0x_%x",tsNum,rtsTxBuffer[1]);
                    buildSendLogicalChannelDataCmd(rtsGprsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);

                    if((((rtsGprsTxBuffer[1] >> 2) & 0x0f) == 0x09))		//UplinkAckNack
                    {
                    	tmrFlag = 1;
                      info->userPrevState = info->userState;
                      info->userState = PKT_UPLINK_ACK_NACK_SENT;
                    	info->ulFrameNum = fn;
                    	info->ulAltFrameNum =  fn+13;	//((fn+13)mod2715648)
                    	info->userAltState = WAIT_FOR_PKT_CNTRL_ACK;
											logPrint(LOG_DEBUG,"User = %p : ulAltFrameNum 0x_%x",info,info->ulAltFrameNum);
											logPrint(LOG_DEBUG,"User = %p : UPLINK_ACK_NACK sent with USF %d userState %d userPrevState %d",
                    														info, (rtsGprsTxBuffer[0] & 0x07),(info->userState),(info->userPrevState));
                    }
                    else if((((rtsGprsTxBuffer[0]) & 0xf8) == 0x08))		//DB sent with valid RRBP
	                {
	                    tmrFlag = 1;
	                    info->userPrevState = info->userState;
	                    info->userState = WAIT_FOR_DWNLNK_ACK;
                        //info->userAltState = WAIT_FOR_DWNLNK_ACK;
                    	logPrint(LOG_DEBUG,"User = %p : DB sent with USF %d userState %d userPrevState %d",
                                            info, (rtsGprsTxBuffer[0] & 0x07),(info->userState),(info->userPrevState));
	            	}
                    else if((((rtsGprsTxBuffer[1] >> 2) & 0x0f) == 0x02))		//DownLinkAssignment
                    {
                    	tmrFlag = 1;
                    	info->userPrevState = info->userState;
                    	info->userState = DOWNLINK_ASSGN_SENT;
                    	info->userAltState = WAIT_FOR_PKT_CNTRL_ACK;
                    	info->ulFrameNum = fn;
                    	frameNum = fn;
                    	info->ulAltFrameNum =  fn+13;	//((fn+13)mod2715648)
						logPrint(LOG_DEBUG,"User = %p : ulAltFrameNum 0x_%x",info,info->ulAltFrameNum);
                    	logPrint(LOG_DEBUG,"User = %p : DWNLINK_ASSGN sent with USF %d userState %d userPrevState %d",
                    														info, (rtsGprsTxBuffer[0] & 0x07),(info->userState),(info->userPrevState));
                    }

                    else
                    {
                    	logPrint(LOG_DEBUG,"User = %p : JUNK sent with USF %d userState %d userPrevState %d",
                    														info, (rtsGprsTxBuffer[0] & 0x07),(info->userState),(info->userPrevState));
                    	logPrint(LOG_DEBUG,"User = %p : JUNK No Timers");
                    }

                    if(tmrFlag && (!isTimerRunning(&info->tmr)))		//isTimerRunning added since started on rcving Downlink_Ack/Nack
                    {
                        tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_GPRS_WAITING_FOR_UE_RSP , 0 , &gprsInfoTimerCbFunction, info);
                        assert(retVal == RC_TCB_OK);
                    }
                    //Timers to implemented with STATE Manipulation
                }
                else
                  logPrint(LOG_DEBUG,"Info == NULL");
            }
            else
            {
								// There is nothing to send on this Ts & SubCh so send Fill Frame
								if(usf_frame_tmp[0] != 0x00)
								{
										memcpy(rtsGprsTxBuffer, usf_frame_tmp, GSM_MACBLOCK_LEN);
										usf = usf_frame_tmp[0] & 0x07;
								}
								else
								{
										memcpy(rtsGprsTxBuffer, usf_frame, GSM_MACBLOCK_LEN);
										usf = usf_frame[0] & 0x07;
								}
								buildSendLogicalChannelDataCmd(rtsGprsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);
								if(cnt == 30)
								{
									logPrint(LOG_DEBUG,"DCB USF 0x%x on %d",usf,tsNum);
									cnt = 0;
								}
								else
									cnt++;
            }
        }
		break;
#endif // FEA_GPRS

       default:
       {
			memcpy(rtsTxBuffer, fill_frame, GSM_MACBLOCK_LEN);
			buildSendLogicalChannelDataCmd(rtsTxBuffer, rtsInd, cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE);
       }
       break;
    }

    return ;
}
