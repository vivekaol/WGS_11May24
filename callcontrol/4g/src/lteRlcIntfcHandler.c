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
* File Name   : lteRlcIntfcHandler.h
 *
* Description : Lte Rlc Interface Layer functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 17/04/2015          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/
#include <assert.h>
#include "lteRlcIntfcHandler.h"
#include "lteRlcEncDec.h"
#include "logManager.h"
#include "lteRrcIntfcHandler.h"
#include "lteMacIntfcHandler.h"

lteRlcAmdPduStruct              amd;
lteRlcStatusPduStruct           status;
ltePduMsgStruct dlPdu;

void lteRlcStatusPduHandler(ltePduMsgStruct* pdu, lteUserInfo* info);
void lteRlcReassemblePduAndSendToRrc(lteRlcAmdPduStruct *amd , lteUserInfo* info);
void lteRlcSendStatusPdu(lteUserInfo *info);
void lteRlcUpdateTransmissionBuffer(uint16 ack_sn , lteUserInfo* info);

uint8 lteRlcUlDchDataHandler(ltePduMsgStruct *pdu, lteUserInfo *info)
{
	if((info == NULL) || ((info != NULL)&&(info->crnti == 0)))
	{
		logPrint(LOG_ERR , "RLC-PDU DECODE FAILED No UserContext available \n");
		return TRUE;
	}
	memset(&amd , 0 , sizeof(lteRlcAmdPduStruct));
    if(decodeUlRlcAmPdu(pdu, &amd) != FALSE )
    {
    	logPrint(LOG_ERR , "RLC-PDU DECODE FAILED");
    	return TRUE;
    }

    if(amd.hdr.dc == LTE_RLC_DC_FIELD_CONTROL_PDU)
    {
        lteRlcStatusPduHandler(pdu, info);
    }
    else
    {
       	logPrint(LOG_DEBUG, "Decoded No. of RLC Pdus = %d , CRNTI = %d\n",amd.noOfPdus , info->crnti);
        if((info->rlc_vrr  <= amd.hdr.sn) && (amd.hdr.sn <  info->rlc_vrmr))
        {
            // Update VR(H)
            if(amd.hdr.sn >= info->rlc_vrh)
            {
            	info->rlc_vrh = amd.hdr.sn + 1;
            }

            // Update VR(R)/VR(MR) and reassemble
            if(amd.hdr.sn == info->rlc_vrr)
            {
            	info->rlc_vrr = amd.hdr.sn + 1 ;
            	info->rlc_vrmr = info->rlc_vrr + LTE_RLC_AM_WINDOW_SIZE;
            	lteRlcReassemblePduAndSendToRrc(&amd , info);
            }

            if(amd.hdr.p) //Polling Bit is set so send ACK
            {
                // Send a STATUS PDU to ACK/NACK SNs
            	lteRlcSendStatusPdu(info);
            }
            else
            {
            	buildAndSendRlcMsgToRrc(info , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
            }
        }
        else
        {
            if(amd.hdr.p)
            {
                // Send a STATUS PDU to ACK/NACK SNs
            	lteRlcSendStatusPdu(info);
            }
            else
            {
            	buildAndSendRlcMsgToRrc(info , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
            }
        }
    }
    return FALSE;
}

void lteRlcSendStatusPdu(lteUserInfo *info)
{
	dlPdu.msg = info->rlcLastSentDlPdu;
	dlPdu.N_bits = 0;
    memset(dlPdu.msg , 0 , MAX_SIZE_RLC_DL_PDU);
    memset(&status , 0 , sizeof(lteRlcStatusPduStruct));
    // Fill in the ACK_SN
    status.ack_sn = info->rlc_vrh;

    // Determine if any NACK_SNs are needed
    status.N_nack = 0;
    if(info->rlc_vrh != info->rlc_vrr) // Basically not expecting to send any NACK
    {
        // Update VR(R) if there are no missing frames
        if(0 == status.N_nack)
        {
        	info->rlc_vrr = info->rlc_vrh;
        	info->rlc_vrmr = info->rlc_vrr + LTE_RLC_AM_WINDOW_SIZE;
        }
    }

    encodeDlRlcStatusPdu(&status , &dlPdu);
    // Store the pdu
	info->rlcLastSendPduNoOfBits =  dlPdu.N_bits;
	assert((dlPdu.N_bits/8) < MAX_SIZE_RLC_DL_PDU);
	info->rlcLastSendPduMsgType = LTE_MSG_MAC_RLC_ACK_CTRL_PDU_E;
    buildAndScheduleDlDchRlcPdu(&dlPdu , info , LTE_MSG_MAC_RLC_ACK_CTRL_PDU_E);
    return;
}
void lteRlcReassemblePduAndSendToRrc(lteRlcAmdPduStruct *amd , lteUserInfo *info)
{
	uint8 i = 0;
	for(i = 0; i<amd->noOfPdus;i++)
	{
		if((amd->data[i].N_bits/8) < LTE_MAX_RRC_MSG_SIZE )
		{
			lteL2InftMsg_t *rrcMsg = (lteL2InftMsg_t*)getRrcDataBuffer();
			rrcMsg->msgType        = LTE_MSG_RRC_UL_DATA_IND_E;
			rrcMsg->l2Data.crnti = info->crnti;
			rrcMsg->l2Data.PF = info->timingAdvance;
			rrcMsg->l2Data.PO = info->ulRssiArr[0];
			rrcMsg->l2Data.snr = info->ulSnr;
            rrcMsg->l2Data.emeCallInd = info->emergencyCallAttempted;
			rrcMsg->l2Data.size          =  amd->data[i].N_bits/8;
			memcpy(rrcMsg->l2Data.dataBuf , amd->data[i].msg , rrcMsg->l2Data.size);
			ltePutMsgInRrcQ((void*)rrcMsg);
		}
		else
		{
			logPrint(LOG_DEBUG , "lteRlcReassemblePduAndSendToRrc Pdu Dropped Size = %d\n", (amd->data[i].N_bits/8));
		}
	}
}

void lteRlcStatusPduHandler(ltePduMsgStruct* pdu, lteUserInfo* info)
{
	if(decodeUlRlcStatusPdu(pdu, &status) == FALSE)
	{
		if(info != NULL)
		{
			lteRlcUpdateTransmissionBuffer(status.ack_sn , info); // Update and delete the pdu
			if(ACK_RECEIVED_FOR_RRC_CONN_REL == info->macLayerState)
			{
				userDeleteUsingCrnti(info->crnti , TRUE);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lteRlcUpdateTransmissionBuffer(uint16 ack_sn , lteUserInfo* info)
{
    info->rlc_vta = info->rlc_vta+1;
    info->rlc_vtms = info->rlc_vta + LTE_RLC_AM_WINDOW_SIZE;
    //logPrint(LOG_DEBUG , "lteRlcUpdateTransmissionBuffer , Ack_Sn = %d\n", ack_sn);
	memset((void*)info->rlcLastSentDlPdu , 0 , MAX_SIZE_RLC_DL_PDU);
	info->rlcLastSendPduNoOfBits = 0;
	info->rlcPollRetxCounter = 0;
	if(TRUE == isTimerRunning(&info->tmr))
   		timerStop(&info->tmr);
}

void lteBuildAndSendRlcPdu(lteL2InftMsg_t *rrcMsg)
{
	lteUserInfo* info  = (lteUserInfo* )userFindUsingCrnti(rrcMsg->l2Data.crnti);
	//logPrint(LOG_DEBUG , "lteBuildAndSendRlcPdu , CRNTI = %d , MsgType = %d\n", rrcMsg->l2Data.crnti , rrcMsg->msgId.msgType);
	if(info == NULL)
	{
		logPrint(LOG_DEBUG , "lteBuildAndSendRlcPdu User with CRNTI = %d already deleted \n", rrcMsg->l2Data.crnti);
		return;
	}
	dlPdu.N_bits = 0;
	dlPdu.msg = info->rlcLastSentDlPdu;
	memset(dlPdu.msg , 0 , MAX_SIZE_RLC_DL_PDU);
    amd.hdr.dc = LTE_RLC_DC_FIELD_DATA_PDU;
    amd.hdr.rf = LTE_RLC_RF_FIELD_AMD_PDU;
    amd.hdr.sn = info->rlc_vts++; // after sending update
    if((rrcMsg->msgType == LTE_MSG_ATTACH_REJ_DL_DCH_SDU_REQ_E) || (rrcMsg->msgType == LTE_MSG_TAU_REJ_DL_DCH_SDU_REQ_E)
    	/*|| (rrcMsg->msgType == LTE_MSG_RRC_MEAS_REQ_E)*/)//As attach/tau rej and Rrc Rel conn sent back to back
    {
    	amd.hdr.p  = LTE_RLC_P_FIELD_STATUS_REPORT_NOT_REQUESTED;
    }
    else
    {
    	amd.hdr.p  = LTE_RLC_P_FIELD_STATUS_REPORT_REQUESTED;
    }
    amd.hdr.fi = LTE_RLC_FI_FIELD_FULL_SDU;

    // Pack the PDU
    encodeDlRlcAmPdu(&amd, &dlPdu);

    if((dlPdu.N_bits/8 + rrcMsg->l2Data.size) > MAX_SIZE_RLC_DL_PDU)
    {
    	logPrint(LOG_ERR , "Ignoring RRC Pdu here as size if more =%d \n",(dlPdu.N_bits/8 + rrcMsg->l2Data.size) );
    	return;
    }
    memcpy((dlPdu.msg + dlPdu.N_bits/8) , &rrcMsg->l2Data.dataBuf[0] , rrcMsg->l2Data.size);
    dlPdu.N_bits += rrcMsg->l2Data.size*8 ;


    if((info->rlc_vta  <= amd.hdr.sn) && (amd.hdr.sn <  info->rlc_vtms))
    {
        // Store the pdu
    	 info->rlcLastSendPduNoOfBits =  dlPdu.N_bits;
    	//assert((dlPdu.N_bits/8) < MAX_SIZE_RLC_DL_PDU);
    	 info->rlcLastSendPduMsgType = rrcMsg->msgType;
    	 buildAndScheduleDlDchRlcPdu(&dlPdu , info , rrcMsg->msgType);
    }

    return;
}

