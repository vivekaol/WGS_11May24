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
* File Name   : lteRlcEncDec.c
 *
* Description : Lte Rlc Layer Encoder/Decoder functions header
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 17/04/2015          				  Anand Kashikar			   Initial File Creation
*#############################################################################################
*/

#include "lteRlcEncDec.h"
#include "logManager.h"
#include "oct_ltefapimacphyinterface.h"


uint8 decodeUlRlcAmPdu(ltePduMsgStruct *pdu, lteRlcAmdPduStruct *amd)
{
	uint8  err    	 = TRUE , i = 0 ;
	uint8  *pPdu = pdu->msg;
	eLteRlcExtensionField  e_bit;
	uint32 startPos = 0 , totalLen = 0 , liField = 0;

	if((pPdu != NULL)&&(amd != NULL))
	{
		// Header
		amd->hdr.dc = (eLteRlcDcField)getIE(pPdu, 1 , &startPos);

		if(LTE_RLC_DC_FIELD_DATA_PDU == amd->hdr.dc)
		{
			// Header
			amd->hdr.rf = (eLteRlcRfField)getIE(pPdu, 1, &startPos);
			amd->hdr.p  = (eLteRlcPField)getIE(pPdu, 1, &startPos);
			amd->hdr.fi = (eLteRlcFiField)getIE(pPdu, 2, &startPos);
			e_bit       = (eLteRlcExtensionField)getIE(pPdu, 1, &startPos);
			amd->hdr.sn = getIE(pPdu, 10, &startPos);

			if(LTE_RLC_RF_FIELD_AMD_PDU_SEGMENT == amd->hdr.rf)
			{
				logPrint(LOG_DEBUG, "Not expecting AMD PDU segments , need to increase grant\n");
			}

            amd->noOfPdus = 0;
            pPdu = &pdu->msg[startPos/8];
            while(e_bit == LTE_RLC_E_FIELD_HEADER_EXTENDED)
			{
                if(amd->noOfPdus >= LTE_RLC_AMD_MAX_PDU)
                {
                    logPrint(LOG_DEBUG , "Not handling as more than expected RLC Pdus = %d\n", amd->noOfPdus);
                    return(err);
			}

                if((amd->noOfPdus % 2) == 0)//Even no. of E/Li
                {
                	e_bit   = (eLteRlcExtensionField)((*pPdu >> 7) & 0x01);
                	liField = ((*pPdu & 0x7F) << 4);
                    pPdu++;
                    liField |= ((*pPdu & 0xF0) >> 4);
                    amd->data[amd->noOfPdus].N_bits = 8*liField;//In Bits
				}
                else//Even no. of E/Li
                {
                	e_bit   = (eLteRlcExtensionField)((*pPdu >> 3) & 0x01);
                	liField = ((*pPdu & 0x07) << 8);
                    pPdu++;
                    liField |= (*pPdu);
                    pPdu++;
                    amd->data[amd->noOfPdus].N_bits = 8*liField;//In Bits
                }

                totalLen += amd->data[amd->noOfPdus].N_bits;
                amd->noOfPdus++;
                liField = 0;
            }

            if(LTE_RLC_AMD_MAX_PDU == amd->noOfPdus)
            {
                logPrint(LOG_DEBUG , "Not handling, as more than expected RLC Pdus\n");
                return(err);
            }

            amd->noOfPdus++;
            if((amd->noOfPdus % 2) == 0)
		{
                pPdu++;
            }
            amd->data[amd->noOfPdus-1].N_bits = pdu->N_bits - (pPdu - pdu->msg)*8 - totalLen;

            // Data
            for(i=0; i<amd->noOfPdus; i++)
            {
            	amd->data[i].msg = pPdu;
                pPdu += (amd->data[i].N_bits/8);
            }

		}
		err = FALSE;
	}

	return err;
}
uint8 encodeDlRlcAmPdu(lteRlcAmdPduStruct *amd, ltePduMsgStruct *pdu)
{
	uint8  err    	 = TRUE;
	uint8             *pPdu = pdu->msg;
	uint32             startPos = 0 ;

	if((amd  != NULL) && (pPdu  != NULL))
	{
		// Header
		setIE(amd->hdr.dc,                            pPdu,  1 , &startPos);
		setIE(amd->hdr.rf,                            pPdu,  1 , &startPos);
		setIE(amd->hdr.p,                             pPdu,  1 , &startPos);
		setIE(amd->hdr.fi,                            pPdu,  2 , &startPos);
		setIE(LTE_RLC_E_FIELD_HEADER_NOT_EXTENDED,    pPdu,  1 , &startPos);
		setIE(amd->hdr.sn,                            pPdu, 10 , &startPos);

		// Fill in the number of bits used
		pdu->N_bits = startPos;

		err = FALSE;
	}

	return err;
}

uint8  encodeDlRlcStatusPdu(lteRlcStatusPduStruct *status, ltePduMsgStruct *pdu)
{
	uint8  err    	 = TRUE ;
	uint8             *pPdu = pdu->msg;
	uint32             startPos = 0 , i;

	if((status != NULL) && (pPdu != NULL))
	{
		// D/C Field
		setIE(LTE_RLC_DC_FIELD_CONTROL_PDU, pPdu, 1, &startPos);;

		// CPT Field
		setIE(LTE_RLC_CPT_FIELD_STATUS_PDU, pPdu, 3, &startPos);

		// ACK SN
		setIE(status->ack_sn, pPdu, 10, &startPos);

		// E1
		if(status->N_nack == 0)
		{
			setIE(LTE_RLC_E1_FIELD_NOT_EXTENDED, pPdu, 1, &startPos);
		}
		else
		{
			setIE(LTE_RLC_E1_FIELD_EXTENDED, pPdu, 1, &startPos);
		}

		for(i=0; i<status->N_nack; i++)
		{
			// NACK SN
			setIE(status->nack_sn[i], pPdu, 10, &startPos);

			// E1
			if(i == (status->N_nack-1))
			{
				setIE(LTE_RLC_E1_FIELD_NOT_EXTENDED, pPdu, 1, &startPos);
			}
			else
			{
				setIE(LTE_RLC_E1_FIELD_EXTENDED, pPdu, 1, &startPos);
			}

			// E2
			setIE(LTE_RLC_E2_FIELD_NOT_EXTENDED, pPdu, 1, &startPos);

		}

		pdu->N_bits = startPos;

		// Padding
		if((pdu->N_bits % 8) != 0)
		{
			for(i=0; i<(8 - (pdu->N_bits % 8)); i++)
			{
				setIE(0, pPdu, 1, &startPos);
			}
			pdu->N_bits = startPos;
		}

		err = FALSE;
	}

	return err;
}
uint8 decodeUlRlcStatusPdu(ltePduMsgStruct *pdu, lteRlcStatusPduStruct *status)
{
	uint8  err    	 = TRUE;
	uint8                    *pPdu = pdu->msg;
	eLteRlcDcField  dc;
	eLteRlcE1Field  e_bit;
	uint8                     cpt;
	uint32 startPos = 0;
	if((pPdu != NULL) && (status != NULL))
	{
		// D/C Field
		dc = (eLteRlcDcField)getIE(pPdu, 1 ,&startPos);

		if(LTE_RLC_DC_FIELD_CONTROL_PDU == dc)
		{
			cpt = getIE(pPdu, 3, &startPos);

			if(LTE_RLC_CPT_FIELD_STATUS_PDU == cpt)
			{
				status->ack_sn = getIE(pPdu, 10 ,&startPos);
				e_bit              = (eLteRlcE1Field)getIE(pPdu, 1 ,&startPos);
				//assert(e_bit != LTE_RLC_E1_FIELD_EXTENDED);
				status->N_nack = 0;
				while(LTE_RLC_E1_FIELD_EXTENDED == e_bit)
				{
					status->nack_sn[status->N_nack++] = getIE(pPdu, 10 ,&startPos);
					e_bit   = (eLteRlcE1Field)getIE(pPdu, 1 ,&startPos);
					if(LTE_RLC_E2_FIELD_EXTENDED == getIE(pPdu, 1 ,&startPos))
					{
						getIE(pPdu, 29 ,&startPos);
					}
				}
			}
		}
		err = FALSE;
	}
	return err;
}
