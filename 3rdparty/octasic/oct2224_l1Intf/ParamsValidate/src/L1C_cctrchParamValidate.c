/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Coded Composite Transport Channel Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_cctrchParamValidate.h"
#include "l1IntEnums.h"
void betaCDParamValidate(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_TFC_Beta   * pL1BetaCDInfo)
{
    if(pL1BetaCDInfo->gainFactor > L1CAPI_COMPUTED_GF)
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1BetaCDInfo->gainFactor;    
      return;
    }
    if ( pL1BetaCDInfo->betaC > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1BetaCDInfo->betaC;
      return;
    }    
    if ( pL1BetaCDInfo->betaD > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1BetaCDInfo->betaD;
      return;
    }
    if ( pL1BetaCDInfo->refTFCNumber > 4 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1BetaCDInfo->refTFCNumber;
      return;
    }
}

void cctrchParamValidate(L1CAPI_Msg_Status *msgStatus,
                             L1CAPI_TFCS_Info  * pL1CCctrchInfo)
{
    if(pL1CCctrchInfo->tfcsSize > L1CAPI_MAX_NR_OF_TFCS_CTFC)
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CCctrchInfo->tfcsSize;
      return;    
    }
}

void eTfciParamValidate(L1CAPI_Msg_Status *msgStatus,
                           L1CAPI_Ref_E_TFCI_InfoItem *pL1CEtfci)
{
    if(pL1CEtfci->reference_E_TFCI > 127 )
    {
      msgStatus->l1MsgResult = L1_EMSG_REFETFCI;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CEtfci->reference_E_TFCI;
      return;
    }
    
    if(pL1CEtfci->reference_E_TFCI_PO > 29 )
    {
      msgStatus->l1MsgResult = L1_EMSG_REFETFCI;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CEtfci->reference_E_TFCI_PO;
      return;
    }

}

void eTfcsInfoParamValidate(L1CAPI_Msg_Status *msgStatus,
                                L1CAPI_E_TFCS_Info *pL1CEtfcsInfo)
{
    if(pL1CEtfcsInfo->e_DCH_TFCI_Table_Index > 7 )
    {
      msgStatus->l1MsgResult = L1_EMSG_ETFCSINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CEtfcsInfo->e_DCH_TFCI_Table_Index;
      return;
    }
    if(pL1CEtfcsInfo->bit_mask & e_DCH_Min_Set_E_TFCI_present)
    {
      if(pL1CEtfcsInfo->e_DCH_Min_Set_E_TFCI > 127 )
      {
        msgStatus->l1MsgResult = L1_EMSG_ETFCSINFO;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = pL1CEtfcsInfo->e_DCH_Min_Set_E_TFCI;
        return;
      }      
    }
    if(pL1CEtfcsInfo->refETfciCount > L1CAPI_MAX_REF_ETFCI_COUNT )
    {
      msgStatus->l1MsgResult = L1_EMSG_ETFCSINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CEtfcsInfo->refETfciCount;
      return;
    }

}

