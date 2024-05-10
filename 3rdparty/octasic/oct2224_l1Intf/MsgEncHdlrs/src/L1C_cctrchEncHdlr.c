/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Coded Composite Transport Channel Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_cctrchEncHdlr.h"
#include "L1C_cctrchParamValidate.h"
#include "l1capi_datastruct.h"
#include "msgPutPrimitives.h"



static void betaCDEncHdlr(L1CAPI_Msg_Status *msgStatus,
                              void * pSrc)
{
    L1CAPI_TFC_Beta  * pL1CBetaCDInfo = (L1CAPI_TFC_Beta  *)pSrc;

    betaCDParamValidate(msgStatus,pL1CBetaCDInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CBetaCDInfo->gainFactor);
    ADD_BYTE_VAL(pL1CBetaCDInfo->betaC);
    ADD_BYTE_VAL(pL1CBetaCDInfo->betaD);
    ADD_BYTE_VAL(pL1CBetaCDInfo->refTFCNumber);
END_BLOCK_TRACE
}

static void tfcsEncHdlr(L1CAPI_Msg_Status *msgStatus,
                          void * pSrc,uint8_t ulOrDl)
{
    L1CAPI_TFCS_Info_Item   *pL1CCtfcInfo = (L1CAPI_TFCS_Info_Item *)pSrc;
	L1CAPI_TFC_Beta * pOpCtfcInfo = pL1CCtfcInfo->ptrTFCBeta;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CCtfcInfo->bit_mask);
    ADD_BYTE_VAL(pL1CCtfcInfo->cTFC);
    if(pL1CCtfcInfo->bit_mask & tFC_Beta_present){  
      betaCDEncHdlr(msgStatus,pOpCtfcInfo);
    }
END_BLOCK_TRACE    
}

void cctrchEncHdlr(L1CAPI_Msg_Status *msgStatus,
                      void * pSrc,uint8_t ulOrDl)
{
    uint8_t i;
    L1CAPI_TFCS_Info * pL1CCctrchInfo = (L1CAPI_TFCS_Info *)pSrc;
    void * pTfcInfo;


    cctrchParamValidate(msgStatus,pL1CCctrchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CCctrchInfo->tfcsSize);    
    for(i=0;i<pL1CCctrchInfo->tfcsSize;i++)
    {
       pTfcInfo = &(pL1CCctrchInfo->ptrCctrchTfc[i]);
       tfcsEncHdlr(msgStatus,pTfcInfo,ulOrDl);
       if(msgStatus->l1MsgResult != L1_MSG_SUCCESS){
         return;    
       }
    }
END_BLOCK_TRACE
}

static void eTfciEncHdlr(L1CAPI_Msg_Status *msgStatus,                   
                           void * pSrc)
{
    L1CAPI_Ref_E_TFCI_InfoItem *pL1CEtfci = (L1CAPI_Ref_E_TFCI_InfoItem *)pSrc;

    eTfciParamValidate(msgStatus,pL1CEtfci);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEtfci->reference_E_TFCI);
    ADD_BYTE_VAL(pL1CEtfci->reference_E_TFCI_PO);    
END_BLOCK_TRACE
}

void eTfcsInfoEncHdlr(L1CAPI_Msg_Status *msgStatus,
                         void *pSrc)
{
    L1CAPI_E_TFCS_Info *pL1CEtfcsInfo = (L1CAPI_E_TFCS_Info *)pSrc;
    void * pRefEtfci;
    uint8_t i;

    eTfcsInfoParamValidate(msgStatus,pL1CEtfcsInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEtfcsInfo->bit_mask);
    ADD_BYTE_VAL(pL1CEtfcsInfo->e_DCH_TFCI_Table_Index);
    ADD_BYTE_VAL(pL1CEtfcsInfo->e_DCH_Min_Set_E_TFCI);
    ADD_BYTE_VAL(pL1CEtfcsInfo->refETfciCount);
    for(i=0;i<pL1CEtfcsInfo->refETfciCount;i++)
    {
      pRefEtfci = &(pL1CEtfcsInfo->ptrReference_E_TFCI_Information[i]);
      eTfciEncHdlr(msgStatus,pRefEtfci);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

