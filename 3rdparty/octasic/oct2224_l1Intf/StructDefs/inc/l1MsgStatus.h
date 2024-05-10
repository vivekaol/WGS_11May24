/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: l1MsgStatus.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Message Status: Shared Data structure with L23

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1MSGSTATUS_H
#define _L1MSGSTATUS_H

#include "l1capi_typedef.h"
#include "l1IntEnums.h"

typedef struct
{
  L1MsgResult_e  l1MsgResult;
  uint32_t  additionalInfo0;
  uint32_t  additionalInfo1;
} L1MsgStatus_t;

typedef L1MsgStatus_t L1CAPI_Msg_Status;

#endif /* _L1MSGSTATUS_H */

