/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_TFCS_CTFC_ProcValidation.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Transport Format Combination Sequence, Coded Transport Format 
   Combination Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1C_TFCS_CTFC_PROCVALIDATION_H_
#define _L1C_TFCS_CTFC_PROCVALIDATION_H_

#include "l1capi_datastruct.h"



uint8_t validateTFSCodecOutput(L1CAPI_TransportFormatSet * pCodecResult,L1CAPI_TransportFormatSet *pExpectedResult);
uint8_t validateCTFCCodecOutput(L1CAPI_TFCS_Info * pCodecResult,L1CAPI_TFCS_Info *pExpectedResult);
#endif
