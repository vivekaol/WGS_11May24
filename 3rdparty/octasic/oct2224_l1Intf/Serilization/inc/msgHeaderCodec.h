/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgHeaderCodec.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Message Header Encoder/Decoder

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _MSGHEADERCODEC_H_
#define _MSGHEADERCODEC_H_

#include "l1IntEnums.h"
#include "l1capi_typedef.h"
#include "msgHeaderDef.h"
#include "l1MsgStatus.h"

void l1c_msgHdrMsgDecHdlr( L1CAPI_Msg_Status *msgStatus, L1CAPI_MsgHdr *msgHdr );
void l1c_msgHdrMsgEncHdlr( L1CAPI_Msg_Status *msgStatus, L1CAPI_MsgHdr *msgHdr );


#endif 
