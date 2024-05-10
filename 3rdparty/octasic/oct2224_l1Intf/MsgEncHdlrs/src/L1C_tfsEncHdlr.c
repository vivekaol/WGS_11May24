/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_tfsEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Transport Format Set Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_tfsEncHdlr.h"
#include "L1C_tfsParamValidate.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"



static void tfEncHdlr(L1CAPI_Msg_Status *msgStatus,                       
                       void * pSrc)
{
    L1CAPI_TFS_DynamicPartListItem *pL1CTf = (L1CAPI_TFS_DynamicPartListItem *)pSrc;

    
    tfParamValidate(msgStatus,pL1CTf);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CTf->nrOfTransportBlocks);
    ADD_WORD_VAL(pL1CTf->transportBlockSize);
END_BLOCK_TRACE
}

void tfsEncHdlr(L1CAPI_Msg_Status *msgStatus,
                  void * pSrc)
{
    uint8_t i;
    L1CAPI_TransportFormatSet *pL1CTfsInfo = (L1CAPI_TransportFormatSet *)pSrc;
    void * pTfs; 

    tfsParamValidate(msgStatus,pL1CTfsInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CTfsInfo->tfCount);
    ADD_BYTE_VAL(pL1CTfsInfo->tti);
    ADD_BYTE_VAL(pL1CTfsInfo->crcType);
    ADD_BYTE_VAL(pL1CTfsInfo->codingType);
    ADD_BYTE_VAL(pL1CTfsInfo->codingRate);
    ADD_WORD_VAL(pL1CTfsInfo->rmAttrib);
    for(i=0;i<pL1CTfsInfo->tfCount;i++)
    {
      pTfs = &(pL1CTfsInfo->ptrTransFormat[i]);
      tfEncHdlr(msgStatus,pTfs);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
       return;   
    }
END_BLOCK_TRACE
}


