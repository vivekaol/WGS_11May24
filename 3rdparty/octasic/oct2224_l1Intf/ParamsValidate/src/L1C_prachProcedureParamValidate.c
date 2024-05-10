/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_prachProcedureParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Prach Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_prachProcedureParamValidate.h"
#include "l1IntEnums.h"

void prachPhyInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Prach_Phy_Info * pL1CPrachPhyInfo)
{
    uint8_t i;
	
    for(i=0;i<pL1CPrachPhyInfo->allowedSFCount;i++)
    {
	  if(pL1CPrachPhyInfo->allowedSlotFormatInfo[i] > L1CAPI_RACH_SlotFormat_v3)
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULPRACH;
        msgStatus->additionalInfo0 = PARAM_4;
        msgStatus->additionalInfo1 = pL1CPrachPhyInfo->allowedSlotFormatInfo[i];
        return;
      }
	}

    if ( pL1CPrachPhyInfo->scramblingCodeNumber > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULPRACH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPrachPhyInfo->scramblingCodeNumber;
      return;
    }
	
    if ( ( pL1CPrachPhyInfo->allowedSFCount < 1 ) | ( pL1CPrachPhyInfo->allowedSFCount > 4 ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULPRACH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CPrachPhyInfo->allowedSFCount;
      return;
    }
	
    if ( pL1CPrachPhyInfo->rACH_SubChannelNumbers  > 4095 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULPRACH;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CPrachPhyInfo->rACH_SubChannelNumbers ;
      return;
    }
	
    if ( pL1CPrachPhyInfo->ul_punctureLimit > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULPRACH;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CPrachPhyInfo->ul_punctureLimit;
      return;
    }
	
    if ( pL1CPrachPhyInfo->preambleThreshold > 72 )
	{
      msgStatus->l1MsgResult = L1_EMSG_PHYSULPRACH;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CPrachPhyInfo->preambleThreshold;
      return;
    }
}


void aichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_AICH_Phy_Info * pL1CAichInfo)
{
    if ( pL1CAichInfo->aICH_TransmissionTiming > L1CAPI_AICH_TRANSTIMING_V1 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLAICH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CAichInfo->aICH_TransmissionTiming;
      return;
    }

    if ( pL1CAichInfo->dl_ChannelisationCodeNumber > 511 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLAICH;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CAichInfo->dl_ChannelisationCodeNumber;
      return;
    }

    if ( pL1CAichInfo->aICH_Power > 5 || pL1CAichInfo->aICH_Power < -22)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLAICH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CAichInfo->aICH_Power;
      return;
    }

    if ( pL1CAichInfo->sTTD_Indicator > L1CAPI_STTD_INDICATOR_INACTIVE )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLAICH;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CAichInfo->sTTD_Indicator;
      return;
    }      
}

