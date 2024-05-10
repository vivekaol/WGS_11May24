/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cellProcedureParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Cell Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_cellProcedureParamValidate.h"
#include "l1capi_datastruct.h"
#include "l1IntEnums.h"

void cellInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_CellInfo *pL1CCellInfo)
{
    if ( pL1CCellInfo->tCell > L1CAPI_T_CELL_V9 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CCellInfo->tCell;
      return;
    }	
    if ( pL1CCellInfo->uarfcnUl > 16383)
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CCellInfo->tCell;
      return;
    }		
    if ( pL1CCellInfo->uarfcnUl > 16383)
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CCellInfo->tCell;
      return;
    }		
    if ( pL1CCellInfo->maxTxPower > 500 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CCellInfo->maxTxPower;
      return;
    }	
    if ( pL1CCellInfo->priScramCode > 511 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CCellInfo->priScramCode;
      return;
    }
    if ( pL1CCellInfo->dlTpc01Count > 30 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CCellInfo->dlTpc01Count;
      return;
    }
    if ( pL1CCellInfo->pwrRaiseLimit > 10 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_11;
      msgStatus->additionalInfo1 = pL1CCellInfo->pwrRaiseLimit;
      return;
    }
	
    if ( pL1CCellInfo->dlPwrAvrgWinSize > 60 )
    {
      msgStatus->l1MsgResult = L1_EMSG_CELLINFO;
      msgStatus->additionalInfo0 = PARAM_12;
      msgStatus->additionalInfo1 = pL1CCellInfo->dlPwrAvrgWinSize;
      return;
    }
}


void schInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_SCH_Info *pL1CSchInfo)
{
    if(pL1CSchInfo->sch_Power < -350 || pL1CSchInfo->sch_Power > 150)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CSchInfo->sch_Power;
      return;
    }	
    return;
}

void pCpichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_Primary_CPICH_Info *pL1CPCPichInfo)
{    
    if(pL1CPCPichInfo->cpich_Power < -100 || pL1CPCPichInfo->cpich_Power > 500)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLPCPICH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPCPichInfo->cpich_Power;
      return;
    }	
    return;
}

void sCpichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_Secondary_CPICH_Info *pL1CPCPichInfo)
{
    if(pL1CPCPichInfo->cpich_Power < -350 || pL1CPCPichInfo->cpich_Power > 150)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCPICH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPCPichInfo->cpich_Power;
      return;
    }	
     if(pL1CPCPichInfo->dL_ChannelisationCodeNumber > 511 )
	{
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCPICH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CPCPichInfo->dL_ChannelisationCodeNumber;
      return;
    }	
     if(pL1CPCPichInfo->dl_ScramblingCode > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCPICH;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CPCPichInfo->dl_ScramblingCode;
      return;
    }
	
    return;
}

 
void bchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_BCH_Info *pL1CBchInfo )
{
    if(pL1CBchInfo->bCH_Power < -350 || pL1CBchInfo->bCH_Power > 150)
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHCOMMONDLBASIC;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CBchInfo->bCH_Power;
      return;
    }	
}

