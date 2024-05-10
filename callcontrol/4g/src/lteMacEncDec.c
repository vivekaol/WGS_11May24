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
* File Name   : lteMacEncDec.c
 *
* Description : Lte Mac Layer Encoder Decoder functions header
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 07/02/2015          				  Anand Kashikar			   Initial File Creation
*#############################################################################################
*/

#include <arpa/inet.h>
#include "lteMacEncDec.h"
#include "logManager.h"
#include "lteMacIntfcHandler.h"
#include "oct_ltefapimacphyinterface.h"

void buildLteRARPdu(lteUserInfo* userInfo , uint8 *rarPdu , eLteMacRarHdr rarHdrType)
{
	memset(rarPdu , 0 , 7);
	uint32 startPos = 0;
    if(LTE_MAC_RAR_HEADER_TYPE_BI == rarHdrType)
    {
        // Pack Header
        rarPdu[0] = 0x0F & LTE_RAR_BACKOFF_INDICATOR_VALUE;

    }else if(LTE_MAC_RAR_HEADER_TYPE_RAPID == rarHdrType){
        // Pack Header
    	setIE(0,             rarPdu, 1 , &startPos); // E
    	setIE(rarHdrType, rarPdu, 1, &startPos);
    	setIE(userInfo->preamble,    rarPdu, 6, &startPos);
        // Pack RAR
    	setIE(0,                   rarPdu, 1, &startPos); // R
    	setIE(userInfo->timingAdvance, rarPdu, 11, &startPos);
    	setIE(0,   rarPdu, 1, &startPos); // Hopping bit
    	setIE(userInfo->ulRiv,            rarPdu, 10, &startPos);
    	setIE(userInfo->ulMcs,            rarPdu, 4, &startPos);
    	setIE(3,    rarPdu, 3, &startPos); // TPC
    	//setIE(7,    rarPdu, 3, &startPos); // TPC
    	setIE(0,       rarPdu, 1, &startPos); // Ul Delay
    	setIE(0,        rarPdu, 1, &startPos); // CSI bit
    	setIE(userInfo->crnti,    rarPdu, 16, &startPos);
     }
}

uint8 lteMacDecodeCrntiCe(uint8 *ce_ptr,lteMacCrntiStruct  *c_rnti , uint32 *startPos)
{
    uint8 err = TRUE;

    if(ce_ptr != NULL &&
       c_rnti != NULL)
    {
        c_rnti->c_rnti = getIE(ce_ptr, 16 , startPos);

        err = FALSE;
    }

    return(err);
}

uint8 lteMacDecodePowerHeadroomCe(uint8                               *ce_ptr,
                                                      lteMacPowerHeadroomStruct  *power_headroom , uint32 *startPos)
{
    uint8 err = TRUE;
    if(ce_ptr         != NULL &&
       power_headroom != NULL)
    {
        getIE(ce_ptr, 1 , startPos); // R
        getIE(ce_ptr, 1 , startPos); // R
        power_headroom->ph = getIE(ce_ptr, 6 , startPos);

        err = FALSE;
    }

    return(err);
}

uint8 lteMacDecodeTruncatedBsrCe(uint8                              *ce_ptr,
                                                     lteMacTruncatedBsrStruct  *truncated_bsr , uint32 *startPos)
{
    uint8 err = TRUE;

    if(ce_ptr        != NULL &&
       truncated_bsr != NULL)
    {
        truncated_bsr->lcg_id          = getIE(ce_ptr, 2, startPos);
        getIE(ce_ptr, 6, startPos);
        err = FALSE;
    }

    return(err);
}

uint8 lteMacDecodeShortBsrCe(uint8                          *ce_ptr,
                                                 lteMacShortBsrStruct  *short_bsr ,  uint32 *startPos)
{
    return(lteMacDecodeTruncatedBsrCe(ce_ptr, short_bsr , startPos));
}

uint8 lteMacDecodeLongBsrCe(uint8                         *ce_ptr,
                                                lteMacLongBsrStruct  *long_bsr ,  uint32 *startPos)
{
    uint8 err = TRUE;
    if(ce_ptr   != NULL &&
       long_bsr != NULL)
    {
        long_bsr->buffer_size_0 = getIE(ce_ptr, 6 , startPos);
        long_bsr->buffer_size_1 = getIE(ce_ptr, 6 , startPos);
        long_bsr->buffer_size_2 = getIE(ce_ptr, 6 , startPos);
        long_bsr->buffer_size_3 = getIE(ce_ptr, 6 , startPos);

        err = FALSE;
    }

    return(err);
}

uint8 decodeUlMacPdu(ltePduMsgStruct *msg, lteMacPduStruct *pdu)
{
    uint8	  err     = TRUE;
    uint8             *msg_ptr = msg->msg;
    uint32             i , msgLen = 0;
    uint8              e_bit = 1;
    uint32 startPos = 0;

    if(msg != NULL &&
       pdu != NULL)
    {
        // Unpack the subheaders
        pdu->N_subheaders = 0;
        while(e_bit)
        {
            if(pdu->N_subheaders >= 15)
            {
                break;
            }

            getIE(msg_ptr, 2, &startPos); // R
            e_bit = getIE(msg_ptr, 1 , &startPos);
            pdu->subheader[pdu->N_subheaders].eBit = e_bit;
            pdu->subheader[pdu->N_subheaders].lcid = getIE(msg_ptr, 5 , &startPos);

            if(LTE_MAC_CHAN_TYPE_ULSCH == pdu->chan_type){
                if(LTE_MAC_ULSCH_EXT_POWER_HEADROOM_REPORT_LCID == pdu->subheader[pdu->N_subheaders].lcid)
                {
                	logPrint(LOG_ERR,"EXT_POWER_HEADROOM_REPORT is not supported \n");
                }else if(!(LTE_MAC_ULSCH_POWER_HEADROOM_REPORT_LCID == pdu->subheader[pdu->N_subheaders].lcid ||
                           LTE_MAC_ULSCH_C_RNTI_LCID                == pdu->subheader[pdu->N_subheaders].lcid ||
                           LTE_MAC_ULSCH_TRUNCATED_BSR_LCID         == pdu->subheader[pdu->N_subheaders].lcid ||
                           LTE_MAC_ULSCH_SHORT_BSR_LCID             == pdu->subheader[pdu->N_subheaders].lcid ||
                           LTE_MAC_ULSCH_LONG_BSR_LCID              == pdu->subheader[pdu->N_subheaders].lcid ||
                           LTE_MAC_ULSCH_PADDING_LCID               == pdu->subheader[pdu->N_subheaders].lcid)){
                    if(e_bit)
                    {
                        if(getIE(msg_ptr, 1 , &startPos)) // F
                        {
                            pdu->subheader[pdu->N_subheaders].payload.sdu.N_bits = getIE(msg_ptr, 15 ,&startPos) * 8;
                        }else{
                            pdu->subheader[pdu->N_subheaders].payload.sdu.N_bits = getIE(msg_ptr, 7 , &startPos) * 8;
                        }
                    }else{
                        pdu->subheader[pdu->N_subheaders].payload.sdu.N_bits = 0;
                    }
                }
            }
            pdu->N_subheaders++;
        }
        // Unpack the control elements and SDUs
        for(i=0; i<pdu->N_subheaders; i++)
        {
        	if(LTE_MAC_CHAN_TYPE_ULSCH == pdu->chan_type){
                if(LTE_MAC_ULSCH_EXT_POWER_HEADROOM_REPORT_LCID == pdu->subheader[i].lcid)
                {
                }else if(LTE_MAC_ULSCH_POWER_HEADROOM_REPORT_LCID == pdu->subheader[i].lcid){
                    lteMacDecodePowerHeadroomCe(msg_ptr, &pdu->subheader[i].payload.power_headroom , &startPos);
                }else if(LTE_MAC_ULSCH_C_RNTI_LCID == pdu->subheader[i].lcid){
                	lteMacDecodeCrntiCe(msg_ptr, &pdu->subheader[i].payload.c_rnti , &startPos);
                }else if(LTE_MAC_ULSCH_TRUNCATED_BSR_LCID == pdu->subheader[i].lcid){
                 	lteMacDecodeTruncatedBsrCe(msg_ptr, &pdu->subheader[i].payload.truncated_bsr , &startPos);
                }else if(LTE_MAC_ULSCH_SHORT_BSR_LCID == pdu->subheader[i].lcid){
                	lteMacDecodeShortBsrCe(msg_ptr, &pdu->subheader[i].payload.short_bsr , &startPos);
                }else if(LTE_MAC_ULSCH_LONG_BSR_LCID == pdu->subheader[i].lcid){
                	lteMacDecodeLongBsrCe(msg_ptr, &pdu->subheader[i].payload.long_bsr , &startPos);
                }else if(LTE_MAC_ULSCH_PADDING_LCID == pdu->subheader[i].lcid){
                }else{ // SDU
                    if(pdu->subheader[i].payload.sdu.N_bits == 0)
                    {
                        pdu->subheader[i].payload.sdu.N_bits = (msg->N_bits - startPos);
                        msgLen = msgLen + pdu->subheader[i].payload.sdu.N_bits/8;
                    }

					if(msgLen > LTE_MAC_UL_GRANT_SIZE_FOR_RRC_CONN_SETUP_COMPLETE)
					{
						pdu->subheader[i].payload.sdu.N_bits = 0;
						//continue;
						return TRUE;
					}

                    pdu->subheader[i].payload.sdu.msg = (msg_ptr + startPos/8);
                    msg_ptr += (pdu->subheader[i].payload.sdu.N_bits)/8;
                }
            }
        }

        err = FALSE;
    }

    return(err);
}

uint8 lteMacEncodeUeContentionResolutionIdCe(lteMacUeContResolnIdStruct  *ue_con_res_id,
                                                                 uint8 *sdu , uint32* startPos)
{
    uint8 err = TRUE;

    if(ue_con_res_id != NULL &&
       sdu        != NULL)
    {
		memcpy(sdu + (*startPos /8) , ue_con_res_id->id , LTE_SIZE_OF_CONTENTION_RES_ID);
		*startPos += 8*LTE_SIZE_OF_CONTENTION_RES_ID;
        err = FALSE;
    }

    return(err);
}

uint8 lteMacEncodeTaCommandCe(lteMacTaCommandStruct  *ta_command,
                                                uint8    *sdu , uint32* startPos)
{
    uint8 err = TRUE;

    if(ta_command != NULL &&
       sdu     != NULL)
    {
    	setIE(0,              sdu, 1 , startPos); // R
    	setIE(0,              sdu, 1 , startPos); // R
    	setIE(ta_command->ta, sdu, 6 , startPos);

        err = FALSE;
    }

    return(err);
}

uint8 encodeDlMacPdu(lteMacPduStruct *pdu, ltePduMsgStruct *msg)
{
    uint8  err    	 = TRUE;
    uint8             *msg_ptr = (uint8*)msg->msg;
    uint32             startPos = 0 ,i =0;

    if(pdu != NULL &&
       msg_ptr != NULL)
    {
        // Pack the subheaders
        for(i=0; i<pdu->N_subheaders; i++)
        {
            setIE(0, msg_ptr, 1 , &startPos); // R
            setIE(0, msg_ptr, 1 , &startPos); // R
            if(i != (pdu->N_subheaders-1))
            {
                setIE(1, msg_ptr, 1 , &startPos); // E
            }else{
                setIE(0, msg_ptr, 1 , &startPos); // E
            }
            setIE(pdu->subheader[i].lcid, msg_ptr, 5 , &startPos);

            if(LTE_MAC_CHAN_TYPE_DLSCH == pdu->chan_type)
            {
                if(!(LTE_MAC_DLSCH_DRX_COMMAND_LCID 				== pdu->subheader[i].lcid ||
                	 LTE_MAC_DLSCH_UE_CONTENTION_RESOLUTION_ID_LCID == pdu->subheader[i].lcid ||
                     LTE_MAC_DLSCH_TA_COMMAND_LCID                  == pdu->subheader[i].lcid ||
                     LTE_MAC_DLSCH_PADDING_LCID                     == pdu->subheader[i].lcid))
                {
                    if(i != (pdu->N_subheaders-1))
                    {
                        if((pdu->subheader[i].payload.sdu.N_bits/8) < 128)
                        {
                            setIE(0,                                      msg_ptr, 1, &startPos); // F
                            setIE(pdu->subheader[i].payload.sdu.N_bits/8, msg_ptr, 7, &startPos);
                        }else{
                            setIE(1,                                      msg_ptr,  1 , &startPos); // F
                            setIE(pdu->subheader[i].payload.sdu.N_bits/8, msg_ptr, 15 , &startPos);
                        }
                    }
                }
            }
        }

         // Pack the control elements and SDUs
        for(i=0; i<pdu->N_subheaders; i++)
        {
            if(LTE_MAC_CHAN_TYPE_DLSCH == pdu->chan_type)
            {
            	if(LTE_MAC_DLSCH_UE_CONTENTION_RESOLUTION_ID_LCID == pdu->subheader[i].lcid){
            		lteMacEncodeUeContentionResolutionIdCe(&pdu->subheader[i].payload.ue_con_res_id, msg_ptr , &startPos);
                }else if(LTE_MAC_DLSCH_TA_COMMAND_LCID == pdu->subheader[i].lcid){
                	lteMacEncodeTaCommandCe(&pdu->subheader[i].payload.ta_command, msg_ptr , &startPos);
                }else if(LTE_MAC_DLSCH_DRX_COMMAND_LCID == pdu->subheader[i].lcid){
                    // No content for DRX Command CE
                }else if(LTE_MAC_DLSCH_PADDING_LCID == pdu->subheader[i].lcid){
                }else{ // SDU
                	msg_ptr = (uint8*) pdu->subheader[i].payload.sdu.msg;
                    msg_ptr += pdu->subheader[i].payload.sdu.N_bits / 8;
                }
            }
        }

        msg->N_bits = startPos;
        err         = FALSE;
    }
    return(err);
}
