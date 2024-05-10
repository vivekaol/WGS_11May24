/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_modemSetupDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Type definition for various data types

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_modemSetupDecHdlr.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"


void modemSetupProcDecHdlr(L1CAPI_Msg_Status *msgStatus)
{
	L1CAPI_Modem_Setup_Request *pL1CModemSetupRequest = 
      (L1CAPI_Modem_Setup_Request *)allocMem(sizeof(L1CAPI_Modem_Setup_Request), 0);
    pL1CModemSetupRequest->bit_mask = subByteVal();
	
	if (pL1CModemSetupRequest->bit_mask & mdmsetup_txattn_present)
	{
		pL1CModemSetupRequest->txAttn = subByteVal();
	}
	
    if (pL1CModemSetupRequest->bit_mask & mdmsetup_rxgain_present)
	{
		pL1CModemSetupRequest->rxGain = subByteVal();
	}
    
    if (pL1CModemSetupRequest->bit_mask & mdmsetup_rfport_present)
    {
        pL1CModemSetupRequest->txRfPort = subByteVal();
	pL1CModemSetupRequest->rxRfPort = subByteVal();
    }
	
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

