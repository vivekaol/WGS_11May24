/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_PrachRespProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Random Access Channel Response Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_PrachRespProcValidation.h"


/***********************
Octasic L1C API initial
************************/


static L1CAPI_Prach_Setup_Response l1c_PrachSetupResp = 
{
	0x80007,
	{
		L1_MSG_SUCCESS,
		0,
		0
	}
};

/***********************
Validation API
***********************/


L1CAPI_Prach_Setup_Response * getL1CPrachSetupResp()
{
	return &l1c_PrachSetupResp;
}

uint8_t validatePrachSetupRespCodecOutput(L1CAPI_Prach_Setup_Response * pCodecResult,L1CAPI_Prach_Setup_Response *pExpectedResult)
{
	if(pCodecResult->rAch_binding_id != pExpectedResult->rAch_binding_id)
		return 0;
	if(pCodecResult->msgStatus.l1MsgResult != pExpectedResult->msgStatus.l1MsgResult)
		return 0;
	return 1;
}
