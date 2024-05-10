/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_SysInfoDecHdlr.c

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

#include "L1C_sysInfoDecHdlr.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"


void systemInfoUpdateRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_BCH_SIM_DATA *pL1CSysInfoUpdate = (L1CAPI_BCH_SIM_DATA * )allocMem(sizeof(L1CAPI_BCH_SIM_DATA),0);
    pL1CSysInfoUpdate = (L1CAPI_BCH_SIM_DATA *)subByteStream(2048);    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}
