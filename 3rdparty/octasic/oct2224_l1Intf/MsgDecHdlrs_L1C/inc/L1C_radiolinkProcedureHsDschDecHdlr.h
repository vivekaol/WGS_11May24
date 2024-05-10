/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschDecHdlr.h

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

#ifndef _L1C_RADIOLINKPROCEDUREHSDSCHDECHDLR_H_
#define _L1C_RADIOLINKPROCEDUREHSDSCHDECHDLR_H_
#include "l1capi_datastruct.h"

void hsdschConfigProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig);

void hsdschReconfigProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig);

#endif 
