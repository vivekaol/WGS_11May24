/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_phyShareCHProcedureConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Shared Channel Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_phyShareCHProcedureConvHdlr.h"


void hspdschCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_HS_PDSCH_Code_Info * pL1CPdschCodeInfo,
                                         l1api_hs_pdsch_code_info_t * pOpPdschCodeInfo)
{
    pL1CPdschCodeInfo->number_of_HS_PDSCH_codes = pOpPdschCodeInfo->n_pdsch_codes;
    pL1CPdschCodeInfo->hS_PDSCH_Start_code_number = (L1CAPI_HSPDSCH_Start_code_number)pOpPdschCodeInfo->pdsch_start_code;
}

void hsscchCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_HS_SCCH_Code_Info * pL1CScchCodeInfo,
                                       l1api_hs_scch_code_info_t * pOpScchCodeInfo)
{
    pL1CScchCodeInfo->codeChoice = pOpScchCodeInfo->hs_scch_choice;
    pL1CScchCodeInfo->codeCount = pOpScchCodeInfo->n_scch_codes;
}


void sharedCHExtRlCmnEdchProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                 L1CAPI_Rl_Cmn_Edch_info *  pL1CExtRlCmdEdchInfo,
                                                 l1api_rl_cmn_edch_info_t * pOpExtRlCmnEdchInfo)
{
    uint16_t paramPresentFlags = pOpExtRlCmnEdchInfo->paramPresentFlag;
    pL1CExtRlCmdEdchInfo->bit_mask = 0;

    if((paramPresentFlags & 1) != 0 )
    {
      pL1CExtRlCmdEdchInfo->bit_mask |= eAgchPwrOffset_present;
      pL1CExtRlCmdEdchInfo->eAgchPwrOffset = pOpExtRlCmnEdchInfo->eagch_pwr_offset;
    }
    paramPresentFlags >>= 1;
    if((paramPresentFlags & 1) != 0 )
    {
      pL1CExtRlCmdEdchInfo->bit_mask |= eRgchHichPwrOffset_present;
      pL1CExtRlCmdEdchInfo->eRgchHichPwrOffset = pOpExtRlCmnEdchInfo->ergch_and_hich_pwr_offset;
    }

}

void sharedCHExtAgchCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_AGCH_Code_Info *pL1CAgchCodeInfo,
                                                  l1api_eagch_code_info_t * pOpAgchCodeInfo)
{
    uint16_t ppf = pOpAgchCodeInfo->paramPresentFlag;
    pL1CAgchCodeInfo->codeChoice = L1CAPI_CODE_CHOICE_REMOVE_NULL;
    pL1CAgchCodeInfo->codeCount = 0;
    
    if((ppf & 1) !=0){
      pL1CAgchCodeInfo->codeChoice = pOpAgchCodeInfo->code_adj_choice;
    }
    if(pL1CAgchCodeInfo->codeChoice == L1CAPI_CODE_CHOICE_REMOVE_NULL)
      return;
    ppf >>= 1;
    
    if((ppf & 1) != 0)
    {
      pL1CAgchCodeInfo->codeCount = pOpAgchCodeInfo->code_count;
    }
    
}

void sharedCHExtRgchHichCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                       L1CAPI_E_RGCH_HICH_Code_Info *pL1CRgchHichCodeInfo,
                                                       l1api_ergch_high_code_info_t * pOpRgchHichCodeInfo)
{
    uint16_t ppf = pOpRgchHichCodeInfo->paramPresentFlag;
    pL1CRgchHichCodeInfo->codeChoice = L1CAPI_CODE_CHOICE_REMOVE_NULL;
    pL1CRgchHichCodeInfo->codeCount = 0;
    
    if((ppf & 1) !=0){
      pL1CRgchHichCodeInfo->codeChoice = pOpRgchHichCodeInfo->code_adj_choice;
    }
    if(pL1CRgchHichCodeInfo->codeChoice == L1CAPI_CODE_CHOICE_REMOVE_NULL)
      return;
    ppf >>= 1;
    
    if((ppf & 1) != 0)
    {
      pL1CRgchHichCodeInfo->codeCount = pOpRgchHichCodeInfo->code_count;
    }
    ppf >>= 1;
}

void sharedCHExtProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_Physical_SharedCH_Reconfig_Ext *  pL1CExtInfo,
                                    l1api_phys_sh_ch_rcfg_extensions_t * pOpExtInfo)
{
    uint16_t   paramPresentFlags = pOpExtInfo->paramPresentFlag;
    pL1CExtInfo->bit_mask = 0;
    
    if((paramPresentFlags & 1) != 0)
    {
      pL1CExtInfo->bit_mask |= hsScchCellPowerOffset_present;       
      pL1CExtInfo->hsScchCellPowerOffset = pOpExtInfo->hs_scch_cell_power_offset;
    }
    paramPresentFlags >>= 1;
    if((paramPresentFlags & 1) != 0 )
    {
      pL1CExtInfo->bit_mask |= eAgchRgchHichScramCode_present;
      pL1CExtInfo->eAgchRgchHichScramCode = pOpExtInfo->eagch_rgch_hich_scram_code;
     }
    paramPresentFlags >>= 1;

    if ((paramPresentFlags & 1) != 0)
    {
      pL1CExtInfo->bit_mask |= maxTargetRTWP_present;
      pL1CExtInfo->maxTargetRTWP = pOpExtInfo->max_target_rtwp;
    }
    paramPresentFlags >>= 1;
    if ((paramPresentFlags & 1) != 0)
    {
      pL1CExtInfo->bit_mask |= refRTWP_present;
      pL1CExtInfo->refRTWP = pOpExtInfo->ref_rtwp;
    }
    paramPresentFlags >>= 1;

    if ( (paramPresentFlags & 1) != 0 )
    {
/*    
      if ( physShChRcfgExtensions->dlHsDynamicPwrHeadroom > 1000 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSSHCHRCFGEXTENSIONS;
        msgStatus->additionalInfo0 = PARAM_4;
        msgStatus->additionalInfo1 = physShChRcfgExtensions->dlHsDynamicPwrHeadroom;
        return;
      }
      */
    }
    paramPresentFlags >>= 1;
    if ( (paramPresentFlags & 1) != 0 )
    {
      pL1CExtInfo->bit_mask |= rlCommonEDchInfo_present;
    }
    paramPresentFlags >>= 1;
    if ( (paramPresentFlags & 1) != 0 )
    {
      pL1CExtInfo->bit_mask |= eAgchCodeInfo_present;
    }
    paramPresentFlags >>= 1;
    if ( (paramPresentFlags & 1) != 0 )
    {
      pL1CExtInfo->bit_mask |= eRgchHichCodeInfo_present;
    }
        
}

