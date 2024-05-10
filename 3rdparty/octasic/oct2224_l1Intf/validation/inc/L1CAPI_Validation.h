/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1CAPI_Validation.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control API Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifdef __cplusplus
extern "C" {
#endif
#include "l1capi_typedef.h"
uint8_t cellSetupReqValidate();
uint8_t prachSetupReqValidate();
uint8_t sccpchSetupReqValidate();
uint8_t radiolinkSetupReqValidate();
uint8_t radiolinkReconfigPrepareValidate();
uint8_t radiolinkReconfigCommitValidate();
uint8_t rlDeleteValidate();
uint8_t phySharedCHReconfigReqValidate();
uint8_t genericRespValidate();
uint8_t prachSetupRespValidate();
uint8_t sccpchSetupRespValidate();
uint8_t rlSetupRespValidate();
uint8_t rlReconfigReadyValidate();


uint8_t fpR4UlDchDataValidate();
uint8_t fpR4DlPchDataValidate();
uint8_t fpR5HsdschDataValidate();
uint8_t fpR5HsCapReqValidate();
uint8_t fpR5HsCapAllocValidate();

#ifdef __cplusplus
 }
 #endif 
