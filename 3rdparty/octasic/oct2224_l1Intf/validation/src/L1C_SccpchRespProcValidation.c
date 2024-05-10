/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_SccpchRespProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel Response 
   Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_SccpchRespProcValidation.h"

/***********************
Octasic L1C API initial
************************/

static L1CAPI_BINDING_ID l1c_fachResp[2] = 
{
	0x80008,0x80009
};

static L1CAPI_Sccpch_Setup_Response l1c_SccpchSetupResp = 
{
	pchBindingId_present,
	2,
	l1c_fachResp,
	0x8000a,
	{
		L1_MSG_SUCCESS,
		0,
		0
	}
};

/***********************
Validation API
***********************/

L1CAPI_Sccpch_Setup_Response * getL1CSccpchSetupResp()
{
	return &l1c_SccpchSetupResp;
}

uint8_t validateSccpchSetupRespCodecOutput(L1CAPI_Sccpch_Setup_Response * pCodecResult,L1CAPI_Sccpch_Setup_Response *pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->n_FACH != pExpectedResult->n_FACH)
		return 0;
	if(pCodecResult->bit_mask & pchBindingId_present){
		if(pCodecResult->pCH_binding_id != pExpectedResult->pCH_binding_id)
			return 0;
	}
	if(memcmp(&pCodecResult->msgStatus,&pExpectedResult->msgStatus,sizeof(L1CAPI_Msg_Status)))
		return 0;
	if(memcmp(pCodecResult->ptrFACH_binding_id,pExpectedResult->ptrFACH_binding_id,sizeof(L1CAPI_BINDING_ID)*pCodecResult->n_FACH))
		return 0;
	return 1;
}
