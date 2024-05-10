/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureParamValidate.h"
#include "l1IntEnums.h"

void rlCmnContextInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                              L1CAPI_RadioLink_CmnContextInfo *pL1NodeBCmnContextInfo)
{
    if((pL1NodeBCmnContextInfo->rlCount < 1 ) || (pL1NodeBCmnContextInfo->rlCount > L1CAPI_MAX_RL ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1NodeBCmnContextInfo->rlCount;
      return;
    }

    if ((pL1NodeBCmnContextInfo->coordTrchCount < 1 ) || ( pL1NodeBCmnContextInfo->coordTrchCount > L1CAPI_MAX_NR_OF_COORDDCH ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1NodeBCmnContextInfo->coordTrchCount;
      return;
    }

    if(pL1NodeBCmnContextInfo->tgpsCount> L1CAPI_MAX_TGPS )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1NodeBCmnContextInfo->tgpsCount;
      return;
    }
    
}

void dlCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                       L1CAPI_DL_CodeInfo *pL1CDlCodeInfo)
{
    if (pL1CDlCodeInfo->dl_ScramblingCode > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_DLCODEINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CDlCodeInfo->dl_ScramblingCode;
      return;
    }
    if (pL1CDlCodeInfo->dL_ChannelisationCodeNumber > 511 )
    {
      msgStatus->l1MsgResult = L1_EMSG_DLCODEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CDlCodeInfo->dL_ChannelisationCodeNumber;
      return;
    }
    if(pL1CDlCodeInfo->TransGapPatternSequenceCodeInfo > L1CAPI_TX_GAP_NO_CODE_CHANGE)
    {
      msgStatus->l1MsgResult = L1_EMSG_DLCODEINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CDlCodeInfo->TransGapPatternSequenceCodeInfo;
      return;
    }

}

void rlInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                L1CAPI_RadioLink_Info *pL1CRlInfo)
{
    if((pL1CRlInfo->dlCodeCount < 1 ) || (pL1CRlInfo->dlCodeCount > L1CAPI_MANR_OF_DL_CODEDS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CRlInfo->dlCodeCount;
      return;
    }

    if(pL1CRlInfo->rL_ID > L1CAPI_MAX_USERS)
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CRlInfo->rL_ID;
      return;
    }
    if (pL1CRlInfo->firstRLS_indicator > 1)
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CRlInfo->firstRLS_indicator;
      return;
    }
    if(pL1CRlInfo->chipOffset > 38399 )
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CRlInfo->chipOffset;
      return;
    }
    if((pL1CRlInfo->bit_mask & diversityControlField_present) &&
      (pL1CRlInfo->diversityControlField > L1CAPI_DIV_MUST_NOT_COMBINE ))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CRlInfo->diversityControlField;
      return;
    }
    if((pL1CRlInfo->initialDL_transmissionPower < -350) || (pL1CRlInfo->initialDL_transmissionPower > 150))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_8;
      msgStatus->additionalInfo1 = pL1CRlInfo->initialDL_transmissionPower;
    }
    if((pL1CRlInfo->maximumDL_power < -350) ||(pL1CRlInfo->maximumDL_power >150))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CRlInfo->maximumDL_power;
      return;
    }
    if((pL1CRlInfo->minimumDL_power < -350) ||(pL1CRlInfo->minimumDL_power >150))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_10;
      msgStatus->additionalInfo1 = pL1CRlInfo->minimumDL_power;
      return;
    }
    if((pL1CRlInfo->bit_mask & rl_info_transmitDiverIndicator_present) &&
      (pL1CRlInfo->transmitDiversityIndicator > L1CAPI_TSTD_INDICATOR_INACTIVE))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFO;
      msgStatus->additionalInfo0 = PARAM_11;
      msgStatus->additionalInfo1 = pL1CRlInfo->transmitDiversityIndicator;
      return;
    }
    if((pL1CRlInfo->bit_mask & delayedActivation_present) &&
      (pL1CRlInfo->delayedActivation.delayedActivationType > separate_indication))
    {
      msgStatus->l1MsgResult = L1_EMSG_DELAYEDACTIVATION;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CRlInfo->delayedActivation.delayedActivationType;
      return;
    }    
}

void rlReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                          L1CAPI_Radiolink_Reconfig_params *pL1CRlInfo)
{
    if(pL1CRlInfo->rL_ID > L1CAPI_MAX_USERS)
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFORE;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CRlInfo->rL_ID;
      return;
    }
    if((pL1CRlInfo->bit_mask & maxDlPower_present) &&
      ((pL1CRlInfo->maximumDL_power < -350) ||(pL1CRlInfo->maximumDL_power >150)))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFORE;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CRlInfo->maximumDL_power;
      return;
    }
    if((pL1CRlInfo->bit_mask & minDlPower_present) &&
      ((pL1CRlInfo->minimumDL_power < -350) ||(pL1CRlInfo->minimumDL_power >150)))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFORE;
      msgStatus->additionalInfo0 = PARAM_10;
      msgStatus->additionalInfo1 = pL1CRlInfo->minimumDL_power;
      return;
    }
    if((pL1CRlInfo->bit_mask & rl_reconfig_transmitDiverIndicator_present) &&
      (pL1CRlInfo->transmitDiversityIndicator > L1CAPI_TSTD_INDICATOR_INACTIVE))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFORE;
      msgStatus->additionalInfo0 = PARAM_11;
      msgStatus->additionalInfo1 = pL1CRlInfo->transmitDiversityIndicator;
      return;
    }

    if((pL1CRlInfo->bit_mask & dlDpchTimingAdj_present) &&
      (pL1CRlInfo->dl_dpch_timing_adj > L1CAPI_DL_DPCH_TIMING_ADJ_DELAY))
    {
      msgStatus->l1MsgResult = L1_EMSG_RLINFORE;
      msgStatus->additionalInfo0 = PARAM_11;
      msgStatus->additionalInfo1 = pL1CRlInfo->transmitDiversityIndicator;
      return;
    }
}

void dchTrchProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_DCH_Info *pL1CDchInfo)
{
    if(pL1CDchInfo->qE_Selector > L1CAPI_QE_NON_SELECTED )
    {
      msgStatus->l1MsgResult = L1_EMSG_DCHSPECIFICINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CDchInfo->qE_Selector;
      return;
    }
}

void coordTrchProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_DCH_CoordTrchInfoListItem *pL1CCordInfo)
{
    if((pL1CCordInfo->dchCount < 1 ) || (pL1CCordInfo->dchCount > L1CAPI_MAX_TRCH_COUNT ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_COORDTRCHDCH;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CCordInfo->dchCount;
      return;
    }
    if(pL1CCordInfo->toAWS > L1CAPI_TOAWS_MAX )
    {
      msgStatus->l1MsgResult = L1_EMSG_COORDTRCHDCH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CCordInfo->toAWS;
      return;
    }
    if(pL1CCordInfo->toAWS > L1CAPI_TOA_MAX )
    {
      msgStatus->l1MsgResult = L1_EMSG_COORDTRCHDCH;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CCordInfo->toAWE;
      return;
    }
    if(pL1CCordInfo->payloadCRC_PresenceIndicator > L1CAPI_CRC_NOTINCLUDED )
    {
      msgStatus->l1MsgResult = L1_EMSG_COORDTRCHDCH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CCordInfo->payloadCRC_PresenceIndicator;
      return;
    }
    if(pL1CCordInfo->ul_FP_Mode > L1CAPI_FPMODE_SILENT )
    {
      msgStatus->l1MsgResult = L1_EMSG_COORDTRCHDCH;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CCordInfo->ul_FP_Mode;
      return;
    }    
}

void phyDlDpchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_DL_DPCH_PhyInfo *pL1CPhyDlDpchInfo)
{
    if(pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat > 16 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat;
      return;
    }
    if (pL1CPhyDlDpchInfo->multiplexingPosition > L1CAPI_FLEXIBLE )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->multiplexingPosition;
      return;
    }
    if(pL1CPhyDlDpchInfo->powerOffsetInformation.pO1_ForTFCI_Bits > 24 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->powerOffsetInformation.pO1_ForTFCI_Bits;
      return;
    }    
    if(pL1CPhyDlDpchInfo->powerOffsetInformation.pO2_ForTPC_Bits > 24 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->powerOffsetInformation.pO2_ForTPC_Bits;
      return;
    }    
    if(pL1CPhyDlDpchInfo->powerOffsetInformation.pO3_ForPilotBits > 24 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->powerOffsetInformation.pO3_ForPilotBits;
      return;
    }    
    if(pL1CPhyDlDpchInfo->tPC_DownlinkStepSize > L1CAPI_TPC_STEP_SIZE2)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->tPC_DownlinkStepSize;
      return;
    }
    if(pL1CPhyDlDpchInfo->limitedPowerIncrease > L1CAPI_LIMITED_PWR_INC_NOT_USED)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->limitedPowerIncrease;
      return;
    }
    if(pL1CPhyDlDpchInfo->innerLoopDLPCStatus > L1CAPI_INNERLOOPDLPC_INACTIVE)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCH;
      msgStatus->additionalInfo0 = PARAM_8;
      msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->innerLoopDLPCStatus;
      return;
    }
}

void phyDlDpchReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_DL_DPCH_PhyInfo_Reconfig *pL1CPhyDlDpchInfo)
{
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_SlotFormat_present)
    {
      if(pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat > 16 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCHRE;
        msgStatus->additionalInfo0 = PARAM_1;
        msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat;
        return;
      }
    }

    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_MuxPos_present)
    {    
      if (pL1CPhyDlDpchInfo->multiplexingPosition > L1CAPI_FLEXIBLE )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCHRE;
        msgStatus->additionalInfo0 = PARAM_3;
        msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->multiplexingPosition;
        return;
      }
    }
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_LimitedPwrInc_present)
    {    
      if(pL1CPhyDlDpchInfo->limitedPowerIncrease > L1CAPI_LIMITED_PWR_INC_NOT_USED)
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSDLDPCHRE;
        msgStatus->additionalInfo0 = PARAM_4;
        msgStatus->additionalInfo1 = pL1CPhyDlDpchInfo->limitedPowerIncrease;
        return;
      }
    }
}

void phyUlDpchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_UL_DPCH_PhyInfo *pL1CPhyUlDpchInfo)
{    
    if(pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber > ((uint32_t)(1<<24) - 1)){
      msgStatus->l1MsgResult = L1_EMSG_ULSCRAMCODEINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber;
      return;
    }
    if (pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength > L1CAPI_UL_SCRAMCODELENGTH_LONG)
    {
      msgStatus->l1MsgResult = L1_EMSG_ULSCRAMCODEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength;
      return;
    }    
    if(pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength > L1CAPI_MINUL_CHANNELCODE_LEN_v256 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength;
      return;
    }

    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present){
      if(pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs > 5 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
        msgStatus->additionalInfo0 = PARAM_3;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->ul_PunctureLimit > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_PunctureLimit;
      return;
    }
    if(pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat > 5)
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat;
      return;
    }    
    if((pL1CPhyUlDpchInfo->ul_SIR_Target > 173 || pL1CPhyUlDpchInfo->ul_SIR_Target <-82) && (pL1CPhyUlDpchInfo->ul_SIR_Target!= 400))
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_SIR_Target;
      return;
    }    
    if(pL1CPhyUlDpchInfo->diversityMode > L1CAPI_DIV_NOT_USE_CLOSED_LOOP_MODE2 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->diversityMode;
      return;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_DpcMode_present){
      if(pL1CPhyUlDpchInfo->dpcMode > L1CAPI_DPC_MODE1 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
        msgStatus->additionalInfo0 = PARAM_8;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->dpcMode;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_IndEDch_present){
      if(pL1CPhyUlDpchInfo->ulDpdchIndEDch > L1CAPI_UL_DPDCH_NOT_PRESENT )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCH;
        msgStatus->additionalInfo0 = PARAM_9;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ulDpdchIndEDch;
        return;
      }
    }
}

void phyUlDpchReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_UL_DPCH_PhyInfo_Reconfig *pL1CPhyUlDpchInfo)
{            
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlScramCodeInfo_present){    
      if(pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber> 0xffffff)
      {
        msgStatus->l1MsgResult = L1_EMSG_ULSCRAMCODEINFO;
        msgStatus->additionalInfo0 = PARAM_0;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber;
        return;
      }
      if (pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength > L1CAPI_UL_SCRAMCODELENGTH_LONG)
      {
        msgStatus->l1MsgResult = L1_EMSG_ULSCRAMCODEINFO;
        msgStatus->additionalInfo0 = PARAM_1;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MinChanCodeLen_present){        
      if(pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength > L1CAPI_MINUL_CHANNELCODE_LEN_v256 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present){
      if(pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs > 5 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_3;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlPuncLimit_present){
      if(pL1CPhyUlDpchInfo->ul_PunctureLimit > 15 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_4;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_PunctureLimit;
        return;
      }
    }    
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSlotFormat_present){
      if(pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat > 5)
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_5;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat;
        return;
      }    
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSIR_present){
      if((pL1CPhyUlDpchInfo->ul_SIR_Target > 173 || pL1CPhyUlDpchInfo->ul_SIR_Target <-82)&& (pL1CPhyUlDpchInfo->ul_SIR_Target!= 400))
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_6;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ul_SIR_Target;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->bit_mask & L1CAPI_DIV_NOT_USE_CLOSED_LOOP_MODE2){
      if(pL1CPhyUlDpchInfo->diversityMode > L1CAPI_DIV_NOT_USE_CLOSED_LOOP_MODE2 )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_7;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->diversityMode;
        return;
      }
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_IndEDch_present){
      if(pL1CPhyUlDpchInfo->ulDpdchIndEDch > L1CAPI_UL_DPDCH_NOT_PRESENT )
      {
        msgStatus->l1MsgResult = L1_EMSG_PHYSULDPCHRE;
        msgStatus->additionalInfo0 = PARAM_8;
        msgStatus->additionalInfo1 = pL1CPhyUlDpchInfo->ulDpdchIndEDch;
        return;
      }
    }    
}

void rlReconfigCmnInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo)
{
    if(pL1CRlReconfigCmnInfo->rlCount > L1CAPI_MAX_RL )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFORE;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CRlReconfigCmnInfo->rlCount;
      return;
    }
    
    if(pL1CRlReconfigCmnInfo->coorTrchCountAdd > L1CAPI_MAX_NR_OF_COORDDCH )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFORE;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CRlReconfigCmnInfo->coorTrchCountAdd;
      return;
    }
    if(pL1CRlReconfigCmnInfo->coorTrchCountModify > L1CAPI_MAX_NR_OF_COORDDCH )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFORE;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CRlReconfigCmnInfo->coorTrchCountModify;
      return;
    }
    if(pL1CRlReconfigCmnInfo->trchCountDelete > L1CAPI_MAX_TRCH_COUNT )
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFORE;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CRlReconfigCmnInfo->trchCountDelete;
      return;
    }
    if(pL1CRlReconfigCmnInfo->tgpsCount > L1CAPI_MAX_TGPS)
    {
      msgStatus->l1MsgResult = L1_EMSG_NBCOMCONTEXTSETUPINFORE;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CRlReconfigCmnInfo->tgpsCount;
      return;
    }
    
}

