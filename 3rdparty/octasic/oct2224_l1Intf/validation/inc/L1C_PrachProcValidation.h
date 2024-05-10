/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_PrachProcValidation.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Prach Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1C_PRACHPROCVALIDATION_H_
#define _L1C_PRACHPROCVALIDATION_H_

#include "l1capi_datastruct.h"


L1CAPI_Prach_Setup_Request * getL1CPrachSetupRequest();

uint8_t validatePrachSetupReqCodecOutput(L1CAPI_Prach_Setup_Request * pCodecResult,L1CAPI_Prach_Setup_Request *pExpectedResult);

#endif
