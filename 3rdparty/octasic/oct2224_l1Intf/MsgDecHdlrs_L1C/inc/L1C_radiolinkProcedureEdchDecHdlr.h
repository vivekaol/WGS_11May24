/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchDecHdlr.h

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

#ifndef _L1C_RADIOLINKPROCEDUREEDCHDECHDLR_H_
#define _L1C_RADIOLINKPROCEDUREEDCHDECHDLR_H_
#include "l1MsgStatus.h"
#include "l1capi_datastruct.h"

void edchExtConfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Radiolink_EDCH_Config_Ext *pL1CEdchInfo);


void edchExtReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_Radiolink_EDCH_Reconfig_Ext *pL1CEdchInfoReconfig);

void edchRlInfoExtProcDecHdlr(L1CAPI_Msg_Status *msgStatus ,
                                   L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt);

#endif 
