/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchDecHdlr.c

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

#include "L1C_cctrchDecHdlr.h"
#include "msgGetPrimitives.h"

static __inline__ void betaCDDecHdlr(L1CAPI_Msg_Status *msgStatus,                              
							  L1CAPI_TFC_Beta  * pL1CBetaCDInfo)
{	
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
	pL1CBetaCDInfo->gainFactor = subByteVal();
	pL1CBetaCDInfo->betaC = subByteVal();
	pL1CBetaCDInfo->betaD = subByteVal();
	pL1CBetaCDInfo->refTFCNumber = subByteVal();
}

static __inline__ void tfcsDecHdlr(L1CAPI_Msg_Status * msgStatus,
                          L1CAPI_TFCS_Info_Item  *pL1CCtfcInfo)
{
    pL1CCtfcInfo->bit_mask = subByteVal();
    pL1CCtfcInfo->cTFC = subByteVal();
    if(pL1CCtfcInfo->bit_mask & tFC_Beta_present){
      pL1CCtfcInfo->ptrTFCBeta = (L1CAPI_TFC_Beta *)allocMem(sizeof(L1CAPI_TFC_Beta),0);
      betaCDDecHdlr(msgStatus,pL1CCtfcInfo->ptrTFCBeta);
	  if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		return;    
    }
}

static __inline__ void eTfciDecHdlr(L1CAPI_Msg_Status *msgStatus,                   
                           L1CAPI_Ref_E_TFCI_InfoItem *pL1CEtfci)
{
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    pL1CEtfci->reference_E_TFCI = subByteVal();
    pL1CEtfci->reference_E_TFCI_PO = subByteVal();	
}

void cctrchDecHdlr(L1CAPI_Msg_Status * msgStatus,
                      L1CAPI_TFCS_Info * pL1CCctrchInfo)
{
    uint8_t i;
	pL1CCctrchInfo->tfcsSize = subByteVal();
    pL1CCctrchInfo->ptrCctrchTfc = 
      (L1CAPI_TFCS_Info_Item * )allocMem(sizeof(L1CAPI_TFCS_Info_Item) * pL1CCctrchInfo->tfcsSize,0);
    for(i=0;i<pL1CCctrchInfo->tfcsSize;i++)
    {
       tfcsDecHdlr(msgStatus,&(pL1CCctrchInfo->ptrCctrchTfc[i]));
	   if(msgStatus->l1MsgResult != L1_MSG_SUCCESS){
         return;	
	   }
    }

}


void eTfcsInfoDecHdlr(L1CAPI_Msg_Status *msgStatus,
                         L1CAPI_E_TFCS_Info *pL1CEtfcsInfo)
{
	uint8_t i;
    pL1CEtfcsInfo->bit_mask = subByteVal();
    pL1CEtfcsInfo->e_DCH_TFCI_Table_Index = subByteVal();
    pL1CEtfcsInfo->e_DCH_Min_Set_E_TFCI = subByteVal();
    pL1CEtfcsInfo->refETfciCount = subByteVal();
    pL1CEtfcsInfo->ptrReference_E_TFCI_Information = 
      (L1CAPI_Ref_E_TFCI_InfoItem *)allocMem(sizeof(L1CAPI_Ref_E_TFCI_InfoItem) * pL1CEtfcsInfo->refETfciCount,0);
	for(i=0;i<pL1CEtfcsInfo->refETfciCount;i++)
    {
      eTfciDecHdlr(msgStatus,&(pL1CEtfcsInfo->ptrReference_E_TFCI_Information[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
	}
}

