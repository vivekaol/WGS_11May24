/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_modemSetupEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Modem Setup Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_modemSetupEncHdlr.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"



void modemSetupRequestProcEncHdlr( L1CAPI_Msg_Status  *msgStatus )
{
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
	uint8_t bit_mask;
	uint8_t txAttn;
	uint8_t rxGain;
	uint8_t txRfPort;
	uint8_t rxRfPort;

    L1CAPI_Modem_Setup_Request *pL1CModemSetupRequest = (L1CAPI_Modem_Setup_Request *)pHostDLMsg;
	bit_mask = pL1CModemSetupRequest->bit_mask;
	txAttn = pL1CModemSetupRequest->txAttn;
	rxGain = pL1CModemSetupRequest->rxGain;
    txRfPort = pL1CModemSetupRequest->txRfPort;
	rxRfPort = pL1CModemSetupRequest->rxRfPort;
    
	ADD_BYTE_VAL(bit_mask);
    if (bit_mask & mdmsetup_txattn_present)
    {
	    ADD_BYTE_VAL(txAttn);
    }
    if (bit_mask & mdmsetup_rxgain_present)
    {
	    ADD_BYTE_VAL(rxGain);
    }
    if (bit_mask & mdmsetup_rfport_present)
    {
	    ADD_BYTE_VAL(txRfPort);
		ADD_BYTE_VAL(rxRfPort);
    }
}

void modemSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

} 
