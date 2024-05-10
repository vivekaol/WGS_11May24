/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchDecHdlr.h

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

#ifndef _L1C_CCTRCHDECHDLR_H_
#define _L1C_CCTRCHDECHDLR_H_
#include "l1capi_datastruct.h"
#include "l1MsgStatus.h"

void cctrchDecHdlr(L1CAPI_Msg_Status *msgStatus,
                      L1CAPI_TFCS_Info * pL1CCctrchInfo);
void eTfcsInfoDecHdlr(L1CAPI_Msg_Status *msgStatus,
                         L1CAPI_E_TFCS_Info *pL1CEtfcsInfo);


#endif 
