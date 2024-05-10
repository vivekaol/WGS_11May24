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
* File Name   : lapdm.c
 *
* Description : This file provides the functionality of the GSM Layer-2
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/

#include "lapdm.h"
#include "transactionMemoryManager.h"
#include <assert.h>
#include "dataIndMsgHandler.h"
#include "logManager.h"
#include "linkedlist.h"
#include "sms.h"
/*
**  Physical frame for normal frame
*/
/*
address octet
control octet
length octet
info field 20 octets
*/

/* indexes to normal ph frame */
#define PH_NORMAL_FRAME_ADDRESS    0
#define PH_NORMAL_FRAME_CONTROL    1
#define PH_NORMAL_FRAME_LENGTH     2
#define PH_NORMAL_FRAME_INFO       3


#define PDU_MASK            0x0F

#define I_FRAME             0x00
#define RR                  0x01
#define SABM                0x3F
#define DM                  0x1F
#define UA                  0x73
#define DISC                0x53

#define NR_MASK             0xE0   /* Mask for nr value */
#define NS_MASK             0x0E   /* Mask for ns value */


extern const tOCT_UINT8 const fill_frame[GSM_MACBLOCK_LEN] ;
extern const tOCT_UINT8 const channelRelease[GSM_MACBLOCK_LEN - 2];
extern gsm_trx * trx_g;
extern void periodicTimerexpiry(tcbTimer_t *tmr , void *infoPtr);

void clearCounters(mLapdmStateVar* stateInfo)
{
    stateInfo->mRC = 0;
    stateInfo->mVA = 0;
    stateInfo->mVR = 0;
    stateInfo->mVS = 0;
    stateInfo->mLapdmstate = Initial;
}

/* common Address Field
Bit         8   7   6    5   4   3   2   1
      Spare  LPD         SAPI             C/R  EA=1
*/
void buildUAFrameHeader(userInfo *info)
{
    /* UA (unnumbered acknowledge)  0 1 1 F 0 0 1 1  */
    /* We are setting F bit=1 always*/
    info->lapdmParam[0] = 0x01;
    info->lapdmParam[1] = 0x73;
}

void buildISendFrameHeader(userInfo *info)
{
    /* 3*N ( R )  1* P 3*N ( S ) 0 */
    tOCT_UINT8 pbit = 1;
    info->lapdmParam[0] = 0x03;
    info->lapdmParam[1] = 0;
    info->lapdmParam[1] = (tOCT_UINT8)(info->userLapdmStateVars.mVR << 5 |  pbit << 4 | info->userLapdmStateVars.mVS << 1);

    info->userLapdmStateVars.mVS = (info->userLapdmStateVars.mVS +1)%8;

}

void buildSFrameRR(userInfo *info)
{
    /* 3*N ( R ) 1*P/F 0 0 0 1
    WE are taking P/F bit = 1 */
	info->lapdmParam[0] = 0x01;
	info->lapdmParam[1] = 0;
	info->lapdmParam[1] = (tOCT_UINT8)(info->userLapdmStateVars.mVR << 5 | info->userLapdmStateVars.receivedPFbit << 4 | 0x01) ;
}

void buildSFrameREJ(userInfo *info)
{

    /* 3*N ( R ) 1*P/F 0 0 0 1
    WE are taking P/F bit = 1 */
	info->lapdmParam[0] = 0x01;
	info->lapdmParam[1] = 0;
	info->lapdmParam[1] = (tOCT_UINT8)(info->userLapdmStateVars.mVR << 5 | info->userLapdmStateVars.receivedPFbit << 4 | 0x01) ;

}

void processReceiveSFrameREJ(userInfo *info)
{
	logPrint(LOG_DEBUG,"User = %p : processReceiveSFrameREJ \n ", info);
	timerStop(&info->tmr);
    /* 3*N ( R ) 1*P/F 1 0 0 1 */
}

void processReceiveSFrameRR(userInfo *info , tOCT_UINT8* inBuf, tOCT_UINT8 sapi)
{
    /*N ( R ) P/F 0 0 0 1 */
    if( (((inBuf[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x00) // SAPI = 0
    {
        tOCT_UINT8 control_pkt = inBuf[1];
        logPrint(LOG_DEBUG,"User = %p : processReceiveSFrameRR L2-ACK Received \n ", info);
        info->userLapdmStateVars.mVA = (0x07 & (control_pkt >> 5));
        if(info->userLapdmStateVars.mVA == info->userLapdmStateVars.mVS)
        {
        	info->userLapdmStateVars.mRC = 0;
        }
        timerStop(&info->tmr);
        setNextStateOnReceiptL2Ack(info, sapi);
    }

#if defined(FEA_MT_SMS) || defined(FEA_DECODE_MO_SMS)
    else if( (((inBuf[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x03) // SAPI = 3 , SMS
    {
        // L2-ACK received for previous L2-Frame, send next L2-Frame if data is still pending.

        /*N ( R ) P/F 0 0 0 1 */
    	tOCT_UINT8 bytesRemaining, L2length = 0;
        tOCT_UINT8 control_pkt = inBuf[1];
    	tOCT_UINT8 pbit = 1;

        logPrint(LOG_DEBUG,"User = %p : SAPI = 3, processReceiveSFrameRR L2-ACK Received\n ", info);
        info->userLapdmStateVarsSapi3.mVA = (0x07 & (control_pkt >> 5));
        if(info->userLapdmStateVarsSapi3.mVA == info->userLapdmStateVarsSapi3.mVS)
        {
        	info->userLapdmStateVarsSapi3.mRC = 0;
        }
        timerStop(&info->tmr);

#ifdef FEA_MT_SMS
        if(info->mtSmsL3Pdu != NULL && info->cpDataSentBytes != 0)
        {
    	    // Send next L2-Frame of CP-DATA if pending 
    	    bytesRemaining = info->mtSmsL3Pdu[2] - info->cpDataSentBytes; // CP_DATA Length - bytesSent

    		logPrint(LOG_DEBUG, "User = %p : CP-DATA Length = %d, cpDataSentBytes = %d, bytesRemaining = %d", info, info->mtSmsL3Pdu[2], info->cpDataSentBytes, bytesRemaining );

    	    if(bytesRemaining > 20)
    	      L2length = 20;
    	    else
    	      L2length = bytesRemaining;
    		
    	    tOCT_UINT8* cpData = getTxDataBuffer();
    	    assert(cpData != NULL);
    	    memcpy(cpData,  fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

    	    cpData[0] = 0x0F; // SAPI = 3, C/R = 1, EA = 1

    	    // Modify the control field based on the L2-ACK received for previous L2-Frame sent.
    	    cpData[1] = 0;
    	    cpData[1] = (tOCT_UINT8)(info->userLapdmStateVarsSapi3.mVR << 5 |  pbit << 4 | info->userLapdmStateVarsSapi3.mVS << 1);

    		info->userLapdmStateVarsSapi3.mVS = (info->userLapdmStateVarsSapi3.mVS +1)%8;

    	    //Length Indicator
    	    if(bytesRemaining > 20)
    	      cpData[2] = ((L2length << 2) | (0x01 << 1) | 0x01); // L = L2length, M = 1, EL =1
    	    else
              cpData[2] = ((L2length << 2) | 0x01); // L = L2length, M = 0, EL =1

    	    memcpy(&cpData[3], &(info->mtSmsL3Pdu[info->cpDataSentBytes + 3]), L2length);
    	    info->cpDataSentBytes+= L2length;
            transactMemoryParams params;
            params.pushToTail = TRUE;
            params.sapi       = sapi;

            pushMsgToTransactionMemoryManager((void*)cpData , &info->userLogicalChannel, params); // Put this message to tail

    	    if(info->cpDataSentBytes == info->mtSmsL3Pdu[2])
    	    {
                // Full L3 Frame is sent
                info->cpDataSentBytes = 0;
    	    }
        }
#endif /* FEA_MT_SMS */
    }

#endif /* FEA_MT_SMS || FEA_DECODE_MO_SMS */
    else
    {}
}
void processSabmFrameHeader(userInfo *info, tOCT_UINT8* inBuf)
{
    /* SABM   0 0 1 P 1 1 1 1 */
    if( (((inBuf[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x00) // SAPI = 0
    {
	    logPrint(LOG_DEBUG,"User = %p : processSabmFrameHeader \n ", info);
	    info->userLapdmStateVars.mLapdmstate = LinkEstablished;
    }

#ifdef FEA_DECODE_MO_SMS
    else if( (((inBuf[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x03) // SAPI = 3 , SMS
    {
	    logPrint(LOG_DEBUG,"User = %p : SAPI = 3, processSabmFrameHeader \n ", info);
	    info->userLapdmStateVarsSapi3.mLapdmstate = LinkEstablished;
    }
#endif /* FEA_DECODE_MO_SMS */

    else
    {}
}

void processDISCFrameHeader(userInfo *info, tOCT_UINT8* inBuf)
{
    /* DISC   0 1 0 P 0 0 1 1 */
		logPrint(LOG_DEBUG,"User = %p : processDISCFrameHeader \n ", info);
        clearCounters(&info->userLapdmStateVars);
        info->userLapdmStateVars.mLapdmstate = LinkReleased;
}

tOCT_UINT8 processReceiveIFrameHeader(userInfo *info, tOCT_UINT8* inBuf)
{
    /* 3*N ( R )  1* P 3*N ( S ) 0 */

    if( (((inBuf[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x00) // SAPI = 0
    {
        tOCT_UINT8 control_pkt = inBuf[1];
        tOCT_UINT8 recivedNS = 0x07&(control_pkt >> 1);
    	logPrint(LOG_DEBUG,"User = %p : processReceiveIFrameHeader \n ", info);
        if(info->userLapdmStateVars.mLapdmstate == LinkEstablished)
        {
            if(recivedNS == info->userLapdmStateVars.mVR )
            {
            	info->userLapdmStateVars.mVR = (info->userLapdmStateVars.mVR +1)%8;
            	info->userLapdmStateVars.receivedPFbit = 0x01 &(control_pkt >> 4);
                return 1 ; // Send RR
            }
            else
            {
                return 0; // Send REJ
            }
        }
        return 0; // Send REJ
    }

#if defined(FEA_MT_SMS) || defined(FEA_DECODE_MO_SMS)
    else if( (((inBuf[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x03) // SAPI = 3 , SMS
    {
        /* 3*N ( R )  1* P 3*N ( S ) 0 */
        tOCT_UINT8 control_pkt = inBuf[1];
        tOCT_UINT8 recivedNS = 0x07&(control_pkt >> 1);
    	logPrint(LOG_DEBUG,"User = %p : SAPI = 3, processReceiveIFrameHeader \n ", info);
        if(info->userLapdmStateVarsSapi3.mLapdmstate == LinkEstablished)
        {
            if(recivedNS == info->userLapdmStateVarsSapi3.mVR )
            {
            	info->userLapdmStateVarsSapi3.mVR = (info->userLapdmStateVarsSapi3.mVR +1)%8;
            	info->userLapdmStateVarsSapi3.receivedPFbit = 0x01 &(control_pkt >> 4);
                return 1 ; // Send RR
            }
            else
            {
                return 0; // Send REJ
            }
        }
        return 0; // Send REJ
    }
#endif /* FEA_MT_SMS || FEA_DECODE_MO_SMS */

    else
    {}
    
    return 0;
}

#ifdef FEA_MT_SMS

void buildSapi3SABMFrameHeader(tOCT_UINT8 *sapi3SabmFrame)
{
	
	sapi3SabmFrame[0] = 0x0F; // SAPI = 3, C/R = 1, EA = 1
	sapi3SabmFrame[1] = 0x3F; // SABM 0 0 1 F 1 1 1 1, We are setting F bit=1 always
	sapi3SabmFrame[2] = 0x01; // L = 0, M = 0, EL = 1
}

void processSapi3UAFrameHeader(userInfo *info, tOCT_UINT8* inBuf)
{
    /* SABM   0 1 1 F 0 0 1 1 */
	logPrint(LOG_DEBUG,"User = %p : SAPI = 3, processSapi3UAFrameHeader\n ", info);
	info->userLapdmStateVarsSapi3.mLapdmstate = LinkEstablished;
}
#endif /* FEA_MT_SMS */


/*
-------------------------------------------------------------------------
l2_frame_decode
-------------------------------------------------------------------------
*/
unsigned char lapdmMessageHandler(tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA *inData, userInfo * info, tOCT_UINT8 sapi)
{
	tOCT_UINT8 *evtDataContent = (tOCT_UINT8*)((tOCT_UINT8*)inData + sizeof(tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA));
    if(inData->Data.ulDataLength == 0)
    {
        return 1;
    }

    if( (((evtDataContent[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x00) // SAPI = 0
    {
        if( ((evtDataContent[PH_NORMAL_FRAME_CONTROL]) & 0x03) == 0x01)
        {
            processReceiveSFrameRR( info, evtDataContent, sapi );
		    return 1;
        }
        else if(evtDataContent[PH_NORMAL_FRAME_CONTROL] == 0x3F)
        {
            clearCounters(&info->userLapdmStateVars);
            processSabmFrameHeader( info, evtDataContent );
            buildUAFrameHeader( info );

            /* Copy the L3 message */
            tOCT_UINT8 L2length;
            
            L2length = evtDataContent[2] >> 2;
            
            if(L2length <= GSM_MACBLOCK_LEN-3)
            {
                memcpy(info->l3Msg, &evtDataContent[3], L2length);
                info->l3MsgLen = L2length;                
                logPrint(LOG_DEBUG, "User = %p : Full L3 Message(%d bytes) Received, Decoding starts . . .", info, info->l3MsgLen);
            }
            else
              logPrint(LOG_DEBUG, "User = %p : Invalid L2 Length(%d) in SABM message", info, L2length);
            
            info->l3MsgRecvdBytes = 0; /* Reset for the next L3-Message */
            return 0;
        }
        else if (evtDataContent[PH_NORMAL_FRAME_CONTROL] == 0x53)
        {
            processDISCFrameHeader(info, evtDataContent);
            buildUAFrameHeader( info );
        }
        else if (evtDataContent[PH_NORMAL_FRAME_CONTROL] == 0x03)
        {
            // Fill frame Do nothing
    	    logPrint(LOG_DEBUG,"User = %p : Fill Frame Received = %02x %02x %02x \n", info, evtDataContent[0], evtDataContent[1],evtDataContent[2] );
			return 1;
        }
        else if((info->userPrevState == SETUP_RECEIVED) || (info->userPrevState == CALL_PROC_SENT))
        {
    	    // Do nothing.
    	    // This is added to ignore the unknown packet(01 24 09 01 00 2b . . .) which UE was sending
    	    // after SETUP, this maybe UPLINK-FREE RR-short-PD message in unacknowledged mode.
    	    // Basically we don't need to process any I-frame after SETUP in MO-CALL Scenario,
    	    // only possibility is to handle Ack for RelaseComplete and DISC which is sent for ChannelRelease.
        }
        else
        {
    	    tOCT_UINT8 ret ;
            // I-Frame
            ret = processReceiveIFrameHeader( info, evtDataContent );

            if(ret)
            {
                buildSFrameRR( info );
            }
            else
            {
                buildSFrameREJ( info );
            }

		    tOCT_UINT8* l2Ack = getTxDataBuffer();
#ifndef NDEBUG
		    assert(l2Ack != NULL);
#else
		    if(l2Ack == NULL)
		    {
			    logPrint(LOG_ERR, "User = %p : lapdmMessageHandler: l2Ack == NULL\n", info);
			    exit(1);
		    }
#endif
		    memcpy(l2Ack,  fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

		    l2Ack[0] = info->lapdmParam[0];
		    l2Ack[1] = info->lapdmParam[1];
		    l2Ack[2] = 0x01;

            transactMemoryParams params;
            params.pushToTail = FALSE;
            params.sapi       = sapi;

		    if((sapi == SAPI_TCHF) || (sapi == SAPI_TCHH))
			{
                logPrint(LOG_DEBUG, "User = %p : Pushing l2Ack on Tch\n", info);
	            pushMsgToTransactionMemoryManager((void*)l2Ack , &info->userTchChannel, params); // Put this message to head
            }
		    else
            {
		        pushMsgToTransactionMemoryManager((void*)l2Ack , &info->userLogicalChannel, params); // Put this message to head
            }

            /* Handle the Segmentation */

            tOCT_UINT8 L2length, moreBit = 0;

            L2length = evtDataContent[2] >> 2;
            moreBit  = (evtDataContent[2] & 0x02) >> 1;

            if(info->l3MsgRecvdBytes + L2length <= GSM_L3_MSG_MAX_SIZE)
              memcpy(&info->l3Msg[info->l3MsgRecvdBytes], &evtDataContent[3], L2length);
            else
              logPrint(LOG_DEBUG, "User = %p : Ignore the L2 I-Frame, as the MAX L3 Msg size exceeds", info);

            if(moreBit)
            {
                logPrint(LOG_DEBUG, "User = %p : More Bit is set, Wait for Full L3 Message before decoding", info);
                info->l3MsgRecvdBytes += L2length;
                return 1;
            }
            else
            {        
                info->l3MsgLen = info->l3MsgRecvdBytes + L2length;
                logPrint(LOG_DEBUG, "User = %p : Full L3 Message(%d bytes) Received, Decoding starts . . .", info, info->l3MsgLen);
                info->l3MsgRecvdBytes = 0; /* Reset for the next L3-Message */
                return 0;
            }
        }
    }

#if defined(FEA_MT_SMS) || defined(FEA_DECODE_MO_SMS)
	else
	{
        if( (((evtDataContent[PH_NORMAL_FRAME_ADDRESS]) & 0x1C) >> 2) == 0x03) // SAPI = 3 , SMS
        {
            if(evtDataContent[PH_NORMAL_FRAME_CONTROL] == 0x3F)
            {
                clearCounters(&info->userLapdmStateVarsSapi3);
                processSabmFrameHeader( info, evtDataContent );

                // Build and send UA Frame
                tOCT_UINT8* UaFrame = getTxDataBuffer();
                assert(UaFrame != NULL);
                memcpy(UaFrame,  evtDataContent, GSM_MACBLOCK_LEN); // Copy standard message
 
                UaFrame[0] = 0x0D; // SAPI = 3, C/R = 0, EA = 1
                UaFrame[1] = 0x73; // UA
                
                transactMemoryParams params;
                params.pushToTail = FALSE;
                params.sapi       = sapi;
                
                pushMsgToTransactionMemoryManager((void*)UaFrame , &info->userLogicalChannel, params); // Put this message to head

                return 1;
            }

	        else if(evtDataContent[PH_NORMAL_FRAME_CONTROL] == 0x73)
            {   
		        timerStop(&info->tmr);
                clearCounters(&info->userLapdmStateVarsSapi3);
	            processSapi3UAFrameHeader( info, evtDataContent );

		        // Build and send first L2-Frame of CP-DATA
		        tOCT_UINT8* cpData = getTxDataBuffer();
	            assert(cpData != NULL);
		        memcpy(cpData,  fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

		        cpData[0] = 0x0F; // SAPI = 3, C/R = 1, EA = 1
		        cpData[1] = 0x10; // P = 1
		        cpData[2] = 0x53; // L = 20, M = 1, EL =1

		        info->userLapdmStateVarsSapi3.mVS = (info->userLapdmStateVarsSapi3.mVS +1)%8;

                if(info->mtSmsL3Pdu != NULL)
		          memcpy(&cpData[3], info->mtSmsL3Pdu, 20);
                transactMemoryParams params;
                params.pushToTail = TRUE;
                params.sapi       = sapi;

                pushMsgToTransactionMemoryManager((void*)cpData , &info->userLogicalChannel, params); // Put this message to tail

		        info->cpDataSentBytes = 17; // 20 bytes sent as part of first L2-frame, in which 3 bytes are L3-Header

		        return 1;
            }

		    else if( ((evtDataContent[PH_NORMAL_FRAME_CONTROL]) & 0x03) == 0x01)
            {
                processReceiveSFrameRR( info, evtDataContent, sapi );
	            return 1;
            }
		
		    else if (evtDataContent[PH_NORMAL_FRAME_CONTROL] == 0x03)
		    {
			    // Fill frame Do nothing
			    logPrint(LOG_DEBUG,"User = %p : SAPI = 3, Fill Frame Received = %02x %02x %02x \n", info, evtDataContent[0], evtDataContent[1], evtDataContent[2] );
			    return 1;
		    }
		    else
		    {
                /* I-Frame */
                processReceiveIFrameHeader( info, evtDataContent );
                timerStop(&info->tmr);

                /* Send L2-ACK */
                tOCT_UINT8* l2Ack = getTxDataBuffer();
                assert(l2Ack != NULL);

                memcpy(l2Ack,  fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

                l2Ack[0] = 0x0D; // SAPI = 3, C/R = 0, EA = 1

                /* 3*N ( R ) 1*P/F 0 0 0 1, WE are taking P/F bit = 1 */
                l2Ack[1] = 0;
                l2Ack[1] = (tOCT_UINT8)(info->userLapdmStateVarsSapi3.mVR << 5 | info->userLapdmStateVarsSapi3.receivedPFbit << 4 | 0x01) ;
            
                l2Ack[2] = 0x01;

                transactMemoryParams params;
                params.pushToTail = FALSE;
                params.sapi       = sapi;

                pushMsgToTransactionMemoryManager((void*)l2Ack , &info->userLogicalChannel, params); // Put this message to head

                /* Decode the Message Content */
                tOCT_UINT8 bytesRemaining, L2length, moreBit = 0;

                L2length = evtDataContent[2] >> 2;
                moreBit  = (evtDataContent[2] & 0x02) >> 1;
                
                if( ((evtDataContent[3] & 0x0F) == 0x09) && (evtDataContent[4] == 0x04 ) )  /* CP-ACK */
                {
                    timerStop(&info->tmr);
                    info->userPrevState = info->userState;
                    info->userState = CP_ACK_RECEIVED;
                    if((evtDataContent[3] & 0x80) == 0x00) // TI = 0, MS Originated, i.e., MO-SMS
                    { 
                        logPrint(LOG_DEBUG, "User = %p : CP-ACK for MO-SMS\n" , info);
                        if(info->moSmsAllPartsReceived == TRUE)
                        {
                            /* Send Channel Release */
                            info->retransmissionCountForL3Msg = 0;
                            pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
                            logPrint(LOG_DEBUG, "User = %p : MO-SMS, All Parts received and decoded, Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
                        }
                    }
                    else
                    {
                        /* Send Channel Release */
                        info->retransmissionCountForL3Msg = 0;
                        pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
                        logPrint(LOG_DEBUG, "User = %p : CP-ACK for MT-SMS, Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));

                        /* Clear SMS L3 PDU context and Reset the trigger */
                        blackListedUserInfo *blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
                        if(blackUserInfo != NULL)
                        {
                            blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_SMS;
                            if(blackUserInfo->mtSmsL3Pdu != NULL)
                            {
                                free(blackUserInfo->mtSmsL3Pdu);
                                blackUserInfo->mtSmsL3Pdu = NULL;
                            }

							/* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/ 
					        if(configUeIdList.defaultConfig == BLACKLIST)
					        {
							    tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
		                        if(retVal == RC_TCB_OK)
			                      logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on MT-SMS channel release ");
                            }
                        }
                    }
                }
                else if( ((evtDataContent[3] & 0x0F) == 0x09) && (evtDataContent[4] == 0x01) ) /* CP-DATA */
                {
                    if((evtDataContent[6] & 0x07) == 0x02)
                    {
                        logPrint(LOG_DEBUG, "User = %p : RP-ACK Received" , info);
                    }
                    else
                    {
                        info->userState = CP_DATA_RECEIVED;

                        info->moSmsL3Pdu = (tOCT_UINT8 *) malloc( SMS_CP_DATA_MAX_LENGTH );
                        assert(info->moSmsL3Pdu != NULL);
                        memset(info->moSmsL3Pdu, 0, SMS_CP_DATA_MAX_LENGTH);

                        memcpy(info->moSmsL3Pdu, &evtDataContent[3], L2length);

                        if(L2length == 20 && moreBit != 0)
                          info->cpDataRcvdBytes = 17; // 20 bytes received as part of first L2-frame, in which 3 bytes are L3-Header
                        else
                          info->cpDataRcvdBytes = L2length;
                    }
                }
                else
                { 
                    if(info->moSmsL3Pdu != NULL && info->cpDataRcvdBytes != 0)
                    {
                        // Received next L2-Frame of CP-DATA which was pending 
                        bytesRemaining = info->moSmsL3Pdu[2] - info->cpDataRcvdBytes; // CP_DATA Length - bytesReceived
                    
                        logPrint(LOG_DEBUG, "User = %p : CP-DATA Length = %d, cpDataRcvdBytes = %d, bytesRemaining = %d", info, info->moSmsL3Pdu[2], info->cpDataRcvdBytes, bytesRemaining );
                    
                        if(bytesRemaining > 20 && moreBit != 0)
                          L2length = 20;
                        else
                          L2length = bytesRemaining;
                                        
                        memcpy(&(info->moSmsL3Pdu[info->cpDataRcvdBytes + 3]),&evtDataContent[3],  L2length);
                        info->cpDataRcvdBytes+= L2length;
                                        
                        if(info->cpDataRcvdBytes == info->moSmsL3Pdu[2])
                        {
                            tOCT_UINT8 pbit = 1;

                            // Full L3 Frame is received
                            info->cpDataRcvdBytes = 0;

                            // Decode SMS PDU
                            decodeSmsPdu(info);

                            // Send CP_ACK
                            tOCT_UINT8* cpAck = getTxDataBuffer();
                            assert(cpAck != NULL);
                            memcpy(cpAck, fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

                            cpAck[0] = 0x0F; // SAPI = 3, C/R = 1, EA = 1
                            
                            // Modify the control field based on the L2-ACK received for previous L2-Frame sent.
                            cpAck[1] = 0;
                            cpAck[1] = (tOCT_UINT8)(info->userLapdmStateVarsSapi3.mVR << 5 |  pbit << 4 | info->userLapdmStateVarsSapi3.mVS << 1);

                            // L2 Length
                            cpAck[2] = 0x09;

                            cpAck[3] = info->moSmsL3Pdu[0]/* PD*/ | 0x80 /* TI(Nw->MS) */;
                            
                            cpAck[4] = 0x04; // Msg-Type
                            info->userLapdmStateVarsSapi3.mVS = (info->userLapdmStateVarsSapi3.mVS +1)%8;
            
                            params.pushToTail = TRUE;

                            pushMsgToTransactionMemoryManager((void*)cpAck , &info->userLogicalChannel, params); // Put this message to tail
            

                            // Send RP_ACK
                            tOCT_UINT8* rpAck = getTxDataBuffer();
                            assert(rpAck != NULL);
                            memcpy(rpAck, fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

                            rpAck[0] = 0x0F; // SAPI = 3, C/R = 1, EA = 1
                            
                            // Modify the control field based on the L2-ACK received for previous L2-Frame sent.
                            rpAck[1] = 0;
                            rpAck[1] = (tOCT_UINT8)(info->userLapdmStateVarsSapi3.mVR << 5 |  pbit << 4 | info->userLapdmStateVarsSapi3.mVS << 1);

                            // L2 Length
                            rpAck[2] = 0x15;

                            rpAck[3] = info->moSmsL3Pdu[0]/* PD*/ | 0x80 /* TI(Nw->MS) */;
                            
                            rpAck[4] = 0x01; // Msg-Type
                            rpAck[5] = 0x02; // RPDU Length
                            rpAck[6] = 0x03; // MTI(RP-ACK)
                            rpAck[7] = info->moSmsL3Pdu[4]; // RP-Message-Reference

                            info->userLapdmStateVarsSapi3.mVS = (info->userLapdmStateVarsSapi3.mVS +1)%8;
            
                            pushMsgToTransactionMemoryManager((void*)rpAck , &info->userLogicalChannel, params); // Put this message to tail
            
                            logPrint(LOG_DEBUG,"User = %p : MO SMS, full L3-Frame received, Sending CP and RP ACKs\n ", info);

                            info->userPrevState = CP_ACK_SENT;
                            info->userState     = WAITING_FOR_L2ACK;
                            
                            free(info->moSmsL3Pdu);
                            info->moSmsL3Pdu = NULL;

                        }
                    }
                }
                return 1;
            }
        }
	}
#endif /* FEA_MT_SMS || FEA_DECODE_MO_SMS */
    return 0;
}


