/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Coded Composite Transport Channel Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_cctrchConvHdlr.h"

void betaCDConvHdlr(L1CAPI_Msg_Status *msgStatus,
                         L1CAPI_TFC_Beta   * pL1BetaCDInfo,
                         l1api_cctrch_tfc_info_t * pOpCtfcInfo)
{
    pL1BetaCDInfo->gainFactor = pOpCtfcInfo->gain_factor_type;
    pL1BetaCDInfo->betaC = pOpCtfcInfo->beta_c;
    pL1BetaCDInfo->betaD = pOpCtfcInfo->beta_d;
    pL1BetaCDInfo->refTFCNumber = pOpCtfcInfo->tfc_ref_num;
}

void tfcsConvHdlr(L1CAPI_Msg_Status *msgStatus,
                    L1CAPI_TFCS_Info_Item   * pL1CCtfcInfo,
                    l1api_cctrch_tfc_info_t * pOpCtfcInfo,
                    uint8_t ulOrDl)
{
    pL1CCtfcInfo->bit_mask = (ulOrDl == 0)?tFC_Beta_present:0;
    if(pOpCtfcInfo->ctfc > 255)
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pOpCtfcInfo->ctfc;
      return;      
    }
    pL1CCtfcInfo->cTFC = (L1CAPI_TFCS_CTFC)pOpCtfcInfo->ctfc;
}

void cctrchConvHdlr(L1CAPI_Msg_Status *msgStatus,
                       L1CAPI_TFCS_Info      * pL1CCctrchInfo,
                       l1api_cctrch_params_t * pOpCctrchInfo)
{
     if(pOpCctrchInfo->n_tfc > 255)
    {
      msgStatus->l1MsgResult = L1_EMSG_CCTRCHULTFC;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pOpCctrchInfo->n_tfc;
      return;    
    }
    pL1CCctrchInfo->tfcsSize = (uint8_t)pOpCctrchInfo->n_tfc;    
}

void eTfciConvHdlr(L1CAPI_Msg_Status *msgStatus,
                      L1CAPI_Ref_E_TFCI_InfoItem *pL1CEtfci,
                      l1api_ref_etfci_t *pOpEtfci)
{
    pL1CEtfci->reference_E_TFCI = pOpEtfci->ref_etfci;
    pL1CEtfci->reference_E_TFCI_PO = pOpEtfci->ref_etfci_pwr_offset;
}

void eTfcsInfoConvHdlr(L1CAPI_Msg_Status *msgStatus,
                          L1CAPI_E_TFCS_Info *pL1CEtfcsInfo,
                          l1api_etfcs_info_t *pOpEtfcsInfo)
{
    pL1CEtfcsInfo->bit_mask = 0;
    if(((pOpEtfcsInfo->paramPresentFlag >>2 ) & 1) != 0){
      pL1CEtfcsInfo->bit_mask |= e_DCH_Min_Set_E_TFCI_present;
    }
    pL1CEtfcsInfo->e_DCH_TFCI_Table_Index = pOpEtfcsInfo->etfci_table_index;
    pL1CEtfcsInfo->e_DCH_Min_Set_E_TFCI = pOpEtfcsInfo->edch_min_set_etfci;
    pL1CEtfcsInfo->refETfciCount = pOpEtfcsInfo->ref_etfci_count;
}

