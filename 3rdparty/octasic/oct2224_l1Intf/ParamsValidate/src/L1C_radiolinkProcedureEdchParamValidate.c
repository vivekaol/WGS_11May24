/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Enhanced Dedicated Channel 
   Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureEdchParamValidate.h"
#include "l1IntEnums.h"

void edchRlInfoExtProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                          L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt)
{
    if(pL1CEdchRlInfoExt->bit_mask & eDchRlInd_present)
    {
      if(pL1CEdchRlInfoExt->eDchRlInd > L1CAPI_RL_NON_EDCH)
	  {
        msgStatus->l1MsgResult = L1_EMSG_EDCHRLINFOEXTENSION;
        msgStatus->additionalInfo0 = PARAM_0;
        msgStatus->additionalInfo1 = pL1CEdchRlInfoExt->eDchRlInd;
        return;
      }
    }
}

void edpchConfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_Radiolink_EDpch_Info *pL1CEdpchInfo)
{
    if(pL1CEdpchInfo->maxSet_E_DPDCHs > L1CAPI_MAX_SET_EDPDCH_VN2XM2_PLUS_2XM4 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->maxSet_E_DPDCHs;
      return;
    }
	
    if(pL1CEdpchInfo->ul_PunctureLimit > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->ul_PunctureLimit;
      return;
    }

    if(pL1CEdpchInfo->e_TTI > L1CAPI_E_TTI_2MS )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_TTI;
      return;
    }
	
    if(pL1CEdpchInfo->e_DPCCH_PowerOFfset > 8 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_DPCCH_PowerOFfset;
      return;
    }

    if(pL1CEdpchInfo->e_RGCH_2_IndexStepThreshold > 37 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_RGCH_2_IndexStepThreshold ;
      return;
    }
	
    if(pL1CEdpchInfo->e_RGCH_3_IndexStepThreshold > 37 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_RGCH_3_IndexStepThreshold;
      return;
    }
	
    if(pL1CEdpchInfo->hARQ_Info_for_E_DCH > L1CAPI_HARQ_EDCH_RVTABLE )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->hARQ_Info_for_E_DCH ;
      return;
    }
	
    if(pL1CEdpchInfo->hSDSCH_Configured_Indicator > L1CAPI_NO_CONFIGURED_HS_DSCH )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFO;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->hSDSCH_Configured_Indicator;
      return;
    }
    
}

void edpchReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_Radiolink_EDpch_Reconfig_Info *pL1CEdpchInfo)
{
    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_MaxSetEdpchs_present) &&
      (pL1CEdpchInfo->maxSet_E_DPDCHs > L1CAPI_MAX_SET_EDPDCH_VN2XM2_PLUS_2XM4 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->maxSet_E_DPDCHs;
      return;
    }
	
    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_PuncLimit_present) &&
      (pL1CEdpchInfo->ul_PunctureLimit > 15 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->ul_PunctureLimit;
      return;
    }

    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_ETTI_present) &&
      (pL1CEdpchInfo->e_TTI > L1CAPI_E_TTI_2MS ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_TTI;
      return;
    }
	
    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_PwrOffset_present) &&
      (pL1CEdpchInfo->e_DPCCH_PowerOFfset > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_DPCCH_PowerOFfset;
      return;
    }

    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_Rgch2Threshold_present) &&
      (pL1CEdpchInfo->e_RGCH_2_IndexStepThreshold > 37 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_RGCH_2_IndexStepThreshold ;
      return;
    }
	
    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_Rgch3Threshold_present) &&
      (pL1CEdpchInfo->e_RGCH_3_IndexStepThreshold > 37 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->e_RGCH_3_IndexStepThreshold;
      return;
    }
	
    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_HarqInfo_present) &&
      (pL1CEdpchInfo->hARQ_Info_for_E_DCH > L1CAPI_HARQ_EDCH_RVTABLE ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->hARQ_Info_for_E_DCH ;
      return;
    }
	
    if((pL1CEdpchInfo->bit_mask & Edpch_Reconfig_HsdschConfigInd_present) &&
      (pL1CEdpchInfo->hSDSCH_Configured_Indicator > L1CAPI_NO_CONFIGURED_HS_DSCH ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDPCHINFORE;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CEdpchInfo->hSDSCH_Configured_Indicator;
      return;
    }
    
}

void edchFddConfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_FDD_Info *pL1CEdchFddInfo)
{
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Maximum_Bitrate_present)
	{
      if(pL1CEdchFddInfo->e_DCH_Maximum_Bitrate > 5742 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHFDDINFO;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = pL1CEdchFddInfo->e_DCH_Maximum_Bitrate;
        return;
      }
	}
	
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Reference_Pwr_Offset_present)
    {
      if(pL1CEdchFddInfo->e_DCH_Reference_Power_Offset > 6 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHFDDINFO;
        msgStatus->additionalInfo0 = PARAM_4;
        msgStatus->additionalInfo1 = pL1CEdchFddInfo->e_DCH_Reference_Power_Offset;
        return;
      }
    }
    if((pL1CEdchFddInfo->e_DCH_MacDFlow_Count < 1 ) || ( pL1CEdchFddInfo->e_DCH_MacDFlow_Count > L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHFDDINFO;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CEdchFddInfo->e_DCH_MacDFlow_Count;
      return;
    }

}

void edchFddReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_DCH_FDD_Reconfig_Info *pL1CEdchFddInfo)
{
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Maximum_Bitrate_present)
	{
      if(pL1CEdchFddInfo->e_DCH_Maximum_Bitrate > 5742 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHFDDINFORE;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = pL1CEdchFddInfo->e_DCH_Maximum_Bitrate;
        return;
      }
	}
	
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Reference_Pwr_Offset_present)
    {
      if(pL1CEdchFddInfo->e_DCH_Reference_Power_Offset > 6 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHFDDINFORE;
        msgStatus->additionalInfo0 = PARAM_4;
        msgStatus->additionalInfo1 = pL1CEdchFddInfo->e_DCH_Reference_Power_Offset;
        return;
      }
    }
    if((pL1CEdchFddInfo->e_DCH_MacDFlow_Count < 1 ) || ( pL1CEdchFddInfo->e_DCH_MacDFlow_Count > L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHFDDINFORE;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CEdchFddInfo->e_DCH_MacDFlow_Count;
      return;
    }

}

void edchMacDFlowInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_MACDFlow_Info *pL1CEdchMacDFlowInfo)
{
    if(pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID > (L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS - 1) )
    {
	  msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
	  msgStatus->additionalInfo0 = PARAM_1;
	  msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID;
	  return;
    }

    if(pL1CEdchMacDFlowInfo->payloadCRC_PresenceIndicator > L1CAPI_CRC_NOTINCLUDED )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->payloadCRC_PresenceIndicator;
      return;
    }


    if(pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH  > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH ;
      return;
    }

    if(pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset > 6 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset;
      return;
    }

    if(pL1CEdchMacDFlowInfo->eDCH_Grant_Type > L1CAPI_EDCH_GRANTTYPE_SCHEDULED )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDCH_Grant_Type;
      return;
    }

    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_bundlingModeIndicator_present)
    {
      if (pL1CEdchMacDFlowInfo->bundlingModeIndicator > L1CAPI_EDCH_NON_BUNDINGMODE )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
        msgStatus->additionalInfo0 = PARAM_7;
        msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->bundlingModeIndicator;
        return;
      }
    }
    if((pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels < 1 ) || (pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels > L1CAPI_MAX_NUM_LOGICAL_CHANS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFO;
      msgStatus->additionalInfo0 = PARAM_8;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels;
      return;
    }
	
}

void edchMacDFlowReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                          L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pL1CEdchMacDFlowInfo)
{
    if(pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID > (L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS - 1) )
    {
	  msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
	  msgStatus->additionalInfo0 = PARAM_1;
	  msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID;
	  return;
    }

    if((pL1CEdchMacDFlowInfo->bit_mask &  maxNrOfRetransmission_E_DCH_present) &&
      (pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH  > 15 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH ;
      return;
    }

    if((pL1CEdchMacDFlowInfo->bit_mask &  eDCH_HarqPowerOffset_present) &&
       (pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset > 6 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset;
      return;
    }

    if((pL1CEdchMacDFlowInfo->bit_mask &  eDCH_GrantType_present) &&
      (pL1CEdchMacDFlowInfo->eDCH_Grant_Type > L1CAPI_EDCH_GRANTTYPE_SCHEDULED ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDCH_Grant_Type;
      return;
    }

    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_Reconfig_bundlingModeIndicator_present)
    {
      if (pL1CEdchMacDFlowInfo->bundlingModeIndicator > L1CAPI_EDCH_NON_BUNDINGMODE )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
        msgStatus->additionalInfo0 = PARAM_6;
        msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->bundlingModeIndicator;
        return;
      }
    }
    if((pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd < 1 ) || (pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd > L1CAPI_MAX_NUM_LOGICAL_CHANS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
      msgStatus->additionalInfo0 = PARAM_8;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd;
      return;
    }
    if((pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod < 1 ) || (pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod > L1CAPI_MAX_NUM_LOGICAL_CHANS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod;
      return;
    }
    if((pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel < 1 ) || (pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel > L1CAPI_MAX_NUM_LOGICAL_CHANS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWSINFORE;
      msgStatus->additionalInfo0 = PARAM_10;
      msgStatus->additionalInfo1 = pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel;
      return;
    }
	
}

void edchNonSchedGrantInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                      L1CAPI_E_DCH_NonScheduled_TxGrantItems *pL1CEDchNonSchedGrantInfo)
{
    if((pL1CEDchNonSchedGrantInfo->maxBits_MACe_PDU_non_scheduled < 1 ) || (pL1CEDchNonSchedGrantInfo->maxBits_MACe_PDU_non_scheduled > 19982 ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHNONSCHEDGRANTINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CEDchNonSchedGrantInfo->maxBits_MACe_PDU_non_scheduled;
      return;
    }
}


void edchLogicChInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo)
{
    if(pL1CEdchLogicChInfo->logicalChannelId > 14 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CEdchLogicChInfo->logicalChannelId;
      return;
    }
    
    if((pL1CEdchLogicChInfo->bit_mask & schedulingPriorityIndicator_present) && 
	   pL1CEdchLogicChInfo->schedulingPriorityIndicator > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CEdchLogicChInfo->schedulingPriorityIndicator;
      return;
    }

    if((pL1CEdchLogicChInfo->bit_mask & schedulingInformation_present) &&
	   (pL1CEdchLogicChInfo->schedulingInformation > L1CAPI_EDCH_SCHEDULING_NOT_INCLUDED ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CEdchLogicChInfo->schedulingInformation;
      return;
    }

    if((pL1CEdchLogicChInfo->bit_mask & mACesGuaranteedBitRate_present)&&
       (pL1CEdchLogicChInfo->mACesGuaranteedBitRate > 0xffffff))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CEdchLogicChInfo->mACesGuaranteedBitRate;
      return;
    }
    if((pL1CEdchLogicChInfo->bit_mask |= eDCH_DDI_Value_present )&&
       (pL1CEdchLogicChInfo->e_DCH_DDI_Value > 62 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CEdchLogicChInfo->e_DCH_DDI_Value;
	  return;
    }

    if((pL1CEdchLogicChInfo->macD_PDU_Size_Count < 1 ) || ( pL1CEdchLogicChInfo->macD_PDU_Size_Count > L1CAPI_MAX_NR_OF_MACDPDU_IDX ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CEdchLogicChInfo->macD_PDU_Size_Count;
      return;
    }
	
}

void servingEdchRlInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_ServingEdch_Radiolink_Info * pL1CServingEdchRlInfo)
{
    if(pL1CServingEdchRlInfo->serving_edch_rl_location > L1CAPI_RL_NOT_IN_THIS_NODEB )
    {
      msgStatus->l1MsgResult = L1_EMSG_SERVINGEDCHRL;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CServingEdchRlInfo->serving_edch_rl_location;
      return;
    }

    if( pL1CServingEdchRlInfo->bit_mask  & serving_edch_rl_id_present)
    {
      if(pL1CServingEdchRlInfo->serving_edch_rl_id > L1CAPI_MAX_USERS)
      {
         msgStatus->l1MsgResult = L1_EMSG_SERVINGEDCHRL;
         msgStatus->additionalInfo0 = PARAM_1;
         msgStatus->additionalInfo1 = pL1CServingEdchRlInfo->serving_edch_rl_id;
         return;
      }
    }
}

