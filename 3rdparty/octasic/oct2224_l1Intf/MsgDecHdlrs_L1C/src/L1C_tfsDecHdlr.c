/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_tfsDecHdlr.c

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

#include "L1C_tfsDecHdlr.h"
#include "msgGetPrimitives.h"

static __inline__ void tfDecHdlr(L1CAPI_Msg_Status *msgStatus,                       
                       L1CAPI_TFS_DynamicPartListItem *pL1CTf)
{
    pL1CTf->nrOfTransportBlocks = subByteVal();
    pL1CTf->transportBlockSize = subWordVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

void tfsDecHdlr(L1CAPI_Msg_Status *msgStatus,
                  L1CAPI_TransportFormatSet *pL1CTfsInfo)
{
    uint8_t i;
    pL1CTfsInfo->tfCount = subByteVal();
    pL1CTfsInfo->ptrTransFormat = 
      (L1CAPI_TFS_DynamicPartListItem *)allocMem(sizeof(L1CAPI_TFS_DynamicPartListItem) * pL1CTfsInfo->tfCount,0);
    pL1CTfsInfo->tti = subByteVal();
    pL1CTfsInfo->crcType = subByteVal();
    pL1CTfsInfo->codingType = subByteVal();
	pL1CTfsInfo->codingRate = subByteVal();
    pL1CTfsInfo->rmAttrib = subWordVal();
    for(i=0;i<pL1CTfsInfo->tfCount;i++)
    {
      tfDecHdlr(msgStatus,&(pL1CTfsInfo->ptrTransFormat[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
       return;   
    }
}


