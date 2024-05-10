/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgHeaderDef.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Message Header Definition

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _MSGHEADERDEF_H_
#define _MSGHEADERDEF_H_

#include "l1capi_typedef.h"

typedef struct L1CAPI_MsgHdr
{
  uint16_t         msgSize;
  L1CAPI_MsgType_e msgType;
  L1CAPI_MsgId_e   msgId;
  uint16_t         transactionId;
} L1CAPI_MsgHdr;

/*#define L1CAPI_MSGHDR_BYTES (TSIZEOF(L1CAPI_MsgHdr))*/
/*WARNING: Temporarily hardcoded (as above structure is serialized)*/
/*         Change this constant if structure 'L1CAPI_MsgHdr' changes. */
#define L1CAPI_MSGHDR_BYTES (8)

#endif 
