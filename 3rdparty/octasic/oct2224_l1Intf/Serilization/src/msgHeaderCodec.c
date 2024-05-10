/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgHeaderCodec.c

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

#include "msgGetPrimitives.h"
#include "msgPutPrimitives.h"
#include "msgHeaderDef.h"
#include "msgHeaderCodec.h"

void l1c_msgHdrMsgDecHdlr( L1CAPI_Msg_Status *msgStatus, L1CAPI_MsgHdr *msgHdr )
{
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    msgHdr->msgSize = subWordValHdr();
    /*No param range check required*/

    msgHdr->msgType = (L1CAPI_MsgType_e)subWordValHdr();
    if ( msgHdr->msgType > FP_MSG )
    {
      msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = msgHdr->msgType;
      return;
    }

    msgHdr->msgId = (L1MsgId_e)subWordValHdr();
    /*if ( msgHdr->msgId > FP_OLPC_MSG )*/
	if ( msgHdr->msgId > L1_INTERFACE_MSGID_LAST) /*_RK_:Support of FP_HS_CAP_REQ*/
    {
      msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = msgHdr->msgId;
      return;
    }

    msgHdr->transactionId = subWordValHdr();
    if ( msgHdr->transactionId > 32768 )
    {
      msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = msgHdr->transactionId;
      return;
    }


  return;

}

void l1c_msgHdrMsgEncHdlr( L1CAPI_Msg_Status *msgStatus, L1CAPI_MsgHdr *msgHdr )
{
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    addWordValHdr( msgHdr->msgSize );

    if ( msgHdr->msgType > FP_MSG )
    {
      msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = msgHdr->msgType;
      return;
    }
    addWordValHdr( (uint16_t)msgHdr->msgType );
/*if ( msgHdr->msgId > DEDICATED_MEAS_INIT_RSP)*/
	if ( msgHdr->msgId > L1_INTERFACE_MSGID_LAST) /*_RK_:Support of FP_HS_CAP_REQ*/
    {
      msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = msgHdr->msgId;
      return;
    }
    addWordValHdr( (uint16_t)msgHdr->msgId );

    if ( msgHdr->transactionId > 32768 )
    {
      msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = msgHdr->transactionId;
      return;
    }
    addWordValHdr( msgHdr->transactionId );

    return;
}



