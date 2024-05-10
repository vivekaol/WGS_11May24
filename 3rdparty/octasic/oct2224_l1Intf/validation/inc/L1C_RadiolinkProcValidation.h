/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_RadiolinkProcValidation.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1C_RADIOLINKPROCVALIDATION_H_
#define _L1C_RADIOLINKPROCVALIDATION_H_

#include "l1capi_datastruct.h"


L1CAPI_Radiolink_Setup_Request * getL1CRadiolinkSetupRequest();

L1CAPI_Radiolink_Reconfig_Prepare * getL1CRadiolinkReconfigPrepare();

L1CAPI_Radiolink_ReconfigCommit * getL1CRadiolinkReconfigCommit();

L1CAPI_Radiolink_DeletionRequest * getL1CRadiolinkDeletion();

uint8_t validateRadiolinkSetupReqCodecOutput(L1CAPI_Radiolink_Setup_Request * pCodecResult,L1CAPI_Radiolink_Setup_Request *pExpectedResult);

uint8_t validateRadiolinkReconfigPrepareCodecOutput(L1CAPI_Radiolink_Reconfig_Prepare * pCodecResult,L1CAPI_Radiolink_Reconfig_Prepare *pExpectedResult);

uint8_t validateRadiolinkReconfigCommitCodecOutput(L1CAPI_Radiolink_ReconfigCommit * pCodecResult,L1CAPI_Radiolink_ReconfigCommit *pExpectedResult);

uint8_t validateRadiolinkDeletionCodecOutput(L1CAPI_Radiolink_DeletionRequest * pCodecResult,L1CAPI_Radiolink_DeletionRequest *pExpectedResult);

#endif
