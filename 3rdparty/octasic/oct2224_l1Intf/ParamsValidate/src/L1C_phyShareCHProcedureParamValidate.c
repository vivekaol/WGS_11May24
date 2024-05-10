/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_phyShareCHProcedureParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Shared Channel Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_phyShareCHProcedureParamValidate.h"
#include "l1IntEnums.h"

void hspdschCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_HS_PDSCH_Code_Info * pL1CPdschCodeInfo)
{
    if(pL1CPdschCodeInfo->number_of_HS_PDSCH_codes > 15)
    {
      msgStatus->l1MsgResult = L1_EMSG_HSPDSCHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CPdschCodeInfo->number_of_HS_PDSCH_codes;
      return;
    }
    if ( ( pL1CPdschCodeInfo->hS_PDSCH_Start_code_number < 1 ) || ( pL1CPdschCodeInfo->hS_PDSCH_Start_code_number > 15 ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSPDSCHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPdschCodeInfo->hS_PDSCH_Start_code_number;
      return;
    }
}

void hsscchCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_HS_SCCH_Code_Info * pL1CScchCodeInfo)
{
    if(pL1CScchCodeInfo->codeChoice > L1CAPI_CODE_CHOICE_REPLACE )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSSCCHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CScchCodeInfo->codeChoice;
      return;
    }
    if ( ( pL1CScchCodeInfo->codeCount < 1 ) | ( pL1CScchCodeInfo->codeCount > 8 ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSSCCHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CScchCodeInfo->codeCount;
      return;
    }
}

void sharedCHExtAgchCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                         L1CAPI_E_AGCH_Code_Info *pL1CAgchCodeInfo)
{
    if(pL1CAgchCodeInfo->codeChoice > L1CAPI_CODE_CHOICE_REPLACE )
    {
      msgStatus->l1MsgResult = L1_EMSG_EAGCHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CAgchCodeInfo->codeChoice;
      return;
    }
    if(pL1CAgchCodeInfo->codeChoice == L1CAPI_CODE_CHOICE_REMOVE_NULL)
      return;
    if (pL1CAgchCodeInfo->codeCount > L1CAPI_MAX_NR_OF_E_AGCH )
    {
      msgStatus->l1MsgResult = L1_EMSG_EAGCHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CAgchCodeInfo->codeCount;
      return;
    }    
}

void sharedCHExtRgchHichCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                              L1CAPI_E_RGCH_HICH_Code_Info *pL1CRgchHichCodeInfo)
{
    if(pL1CRgchHichCodeInfo->codeChoice > L1CAPI_CODE_CHOICE_REPLACE )
    {
      msgStatus->l1MsgResult = L1_EMSG_ERGCHHICHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CRgchHichCodeInfo->codeChoice;
      return;
    }
    if(pL1CRgchHichCodeInfo->codeChoice == L1CAPI_CODE_CHOICE_REMOVE_NULL)
      return;
    if (pL1CRgchHichCodeInfo->codeCount > L1CAPI_MAX_NR_OF_E_RGCH_HICH)
    {
      msgStatus->l1MsgResult = L1_EMSG_ERGCHHICHCODEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CRgchHichCodeInfo->codeCount;
      return;
    }
}

void sharedCHExtProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_Physical_SharedCH_Reconfig_Ext *  pL1CExtInfo)
{
    if(pL1CExtInfo->bit_mask & hsScchCellPowerOffset_present)
    {
      if ( pL1CExtInfo->hsScchCellPowerOffset > 28 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSSHCHRCFGEXTENSIONS;
        msgStatus->additionalInfo0 = PARAM_0;
        msgStatus->additionalInfo1 = pL1CExtInfo->hsScchCellPowerOffset;
        return;
      }
    }
    if(pL1CExtInfo->bit_mask & eAgchRgchHichScramCode_present)
    {
      if (pL1CExtInfo->eAgchRgchHichScramCode > 15 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSSHCHRCFGEXTENSIONS;
        msgStatus->additionalInfo0 = PARAM_1;
        msgStatus->additionalInfo1 = pL1CExtInfo->eAgchRgchHichScramCode;
        return;
      }
    }

    if(pL1CExtInfo->bit_mask & maxTargetRTWP_present)
    {
      if (pL1CExtInfo->maxTargetRTWP > 721 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSSHCHRCFGEXTENSIONS;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = pL1CExtInfo->maxTargetRTWP;
        return;
      }
    }
    if(pL1CExtInfo->bit_mask & refRTWP_present)
    {
      if(pL1CExtInfo->refRTWP > 721 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSSHCHRCFGEXTENSIONS;
        msgStatus->additionalInfo0 = PARAM_3;
        msgStatus->additionalInfo1 = pL1CExtInfo->refRTWP;
        return;
      }
    }
}

