/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sccpchProcedureParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_sccpchProcedureParamValidate.h"
#include "l1IntEnums.h"
void sccpchPhyInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_SCCPCH_Phy_Info *pL1CSccpchPhyInfo)
{
    if (pL1CSccpchPhyInfo->sCCPCH_Chip_Offset > 149)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->sCCPCH_Chip_Offset;
      return;
    }
    
    if (pL1CSccpchPhyInfo->dl_ScramblingCode > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->dl_ScramblingCode;
      return;
    }    

    if (pL1CSccpchPhyInfo->dL_ChannelisationCodeNumber > 511 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->dL_ChannelisationCodeNumber;
      return;
    }    

    if (pL1CSccpchPhyInfo->sCCPCH_SlotFormat > 17 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->sCCPCH_SlotFormat;
      return;
    }    
    if ( pL1CSccpchPhyInfo->multiplexingPosition > L1CAPI_FLEXIBLE)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->multiplexingPosition;
      return;
    }
    
    if (pL1CSccpchPhyInfo->pO1_ForTFCI_Bits > 24 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_8;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->pO1_ForTFCI_Bits ;
      return;
    }    
    if (pL1CSccpchPhyInfo->pO3_ForPilotBits > 24 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->pO3_ForPilotBits;
      return;
    }    
    if (pL1CSccpchPhyInfo->sTTD_Indicator > L1CAPI_STTD_INDICATOR_INACTIVE )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLSCCPCH;
      msgStatus->additionalInfo0 = PARAM_10;
      msgStatus->additionalInfo1 = pL1CSccpchPhyInfo->sTTD_Indicator;
      return;
    }
}


void sccpchTrchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                            L1CAPI_SCCPCH_Trch_Info * pL1CTrchInfo)
{
    if (pL1CTrchInfo->maxFACH_PCH_Power > 150 || pL1CTrchInfo->maxFACH_PCH_Power < -350)
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHCOMMONDL;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CTrchInfo->maxFACH_PCH_Power;
      return;
    }
    
    if ( pL1CTrchInfo->toAWS > L1CAPI_TOAWS_MAX )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHCOMMONDL;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CTrchInfo->toAWS;
      return;
    }
    
    if ( pL1CTrchInfo->toAWE > L1CAPI_TOA_MAX)
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHCOMMONDL;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CTrchInfo->toAWE;
      return;
    }
}

void pichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_PICH_Params *  pL1CPichInfo)
{
    if ( pL1CPichInfo->dl_ChannelisationCodeNumber > 511 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLPICH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPichInfo->dl_ChannelisationCodeNumber;
      return;
    }
    
    if ( pL1CPichInfo->pICH_Power > 5 || pL1CPichInfo->pICH_Power <-10 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLPICH;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CPichInfo->pICH_Power;
      return;
    }
    
    if ( pL1CPichInfo->pICH_Mode > L1CAPI_PichMode_v144 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLPICH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CPichInfo->pICH_Mode;
      return;
    }

}
