/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_RadiolinkSetupRespProcValidation.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Setup Response Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1C_READIOLINKSETUPRESPPROCVALIDATION_H_
#define _L1C_READIOLINKSETUPRESPPROCVALIDATION_H_

#include "l1capi_datastruct.h"
uint8_t validateRlSetupRespCodecOutput(L1CAPI_Radiolink_Setup_Response * pCodecResult,L1CAPI_Radiolink_Setup_Response *pExpectedResult);

L1CAPI_Radiolink_Setup_Response * getL1CRlSetupResp();


#endif
