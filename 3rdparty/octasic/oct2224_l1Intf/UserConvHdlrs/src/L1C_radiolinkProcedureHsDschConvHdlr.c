/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure High Speed Dedicated Shared Channel 
   Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureHsDschConvHdlr.h"

void macDPduSizeIndexProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_MACDPDU_Size_IndexItem *pL1CMacDPduSizeIndex,
                                         l1api_macd_pdu_size_index_t *pOpMacDPduSizeIndex)
{
    pL1CMacDPduSizeIndex->macdPDU_Size = pOpMacDPduSizeIndex->macD_pdu_size + 1; /*CCPU -1 so we add 1*/
    pL1CMacDPduSizeIndex->sID = pOpMacDPduSizeIndex->sid;
}

static L1CAPI_DiscardTimer Discard_Tmr_Mapping(L1CAPI_Msg_Status *msgStatus,l1api_discard_timer_t tmr)
{
    L1CAPI_DiscardTimer tmrRet = 0;
    switch(tmr)
    {
        case L1API_DIS_T1_20_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V20;
            break;
        case L1API_DIS_T1_40_MS: 
            tmrRet = L1CAPI_DISCARDTIMER_V40;
            break;
        case L1API_DIS_T1_60_MS: 
            tmrRet = L1CAPI_DISCARDTIMER_V60;
            break;
        case L1API_DIS_T1_80_MS: 
            tmrRet = L1CAPI_DISCARDTIMER_V80;
            break;
        case L1API_DIS_T1_100_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V100;
            break;
        case L1API_DIS_T1_120_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V120;
            break;
        case L1API_DIS_T1_140_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V140;
            break;
        case L1API_DIS_T1_160_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V160;
            break;
        case L1API_DIS_T1_180_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V180;
            break;
        case L1API_DIS_T1_200_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V200;
            break;
        case L1API_DIS_T1_250_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V250;
            break;
        case L1API_DIS_T1_300_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V300;
            break;
        case L1API_DIS_T1_400_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V400;
            break;
        case L1API_DIS_T1_500_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V500;
            break;
        case L1API_DIS_T1_750_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V750;
            break;
        case L1API_DIS_T1_1000_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V1000;
            break;
        case L1API_DIS_T1_1250_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V1250;
            break;
        case L1API_DIS_T1_1500_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V1500;
            break;
        case L1API_DIS_T1_1750_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V1750;
            break;
        case L1API_DIS_T1_2000_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V2000;
            break;
        case L1API_DIS_T1_2500_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V2500;
            break;
        case L1API_DIS_T1_3000_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V3000;
            break;
        case L1API_DIS_T1_3500_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V3500;
            break;
        case L1API_DIS_T1_4000_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V4000;
            break;
        case L1API_DIS_T1_4500_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V4500;
            break;
        case L1API_DIS_T1_5000_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V5000;
            break;
        case L1API_DIS_T1_7500_MS:
            tmrRet = L1CAPI_DISCARDTIMER_V7500;
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
            msgStatus->additionalInfo0 = PARAM_4;
            msgStatus->additionalInfo1 = tmr;
            break;
    }
    return tmrRet;
}

static L1CAPI_T1 Convert_T1_Tmr(L1CAPI_Msg_Status *msgStatus,l1api_t1_t t1)
{
    L1CAPI_T1 t1Ret;
    
    switch(t1)
    {
        case L1API_T1_10_MS:
            t1Ret = L1CAPI_T1_V10;
            break;
        case L1API_T1_20_MS:
            t1Ret = L1CAPI_T1_V20;        
            break;
        case L1API_T1_30_MS:
            t1Ret = L1CAPI_T1_V30;        
            break;
        case L1API_T1_40_MS:
            t1Ret = L1CAPI_T1_V40;        
            break;
        case L1API_T1_50_MS:
            t1Ret = L1CAPI_T1_V50;        
            break;
        case L1API_T1_60_MS:
            t1Ret = L1CAPI_T1_V60;        
            break;
        case L1API_T1_70_MS:
            t1Ret = L1CAPI_T1_V70;        
            break;
        case L1API_T1_80_MS:
            t1Ret = L1CAPI_T1_V80;        
            break;
        case L1API_T1_90_MS:
            t1Ret = L1CAPI_T1_V90;        
            break;
        case L1API_T1_100_MS:
            t1Ret = L1CAPI_T1_V100;        
            break;
        case L1API_T1_120_MS:
            t1Ret = L1CAPI_T1_V120;        
            break;
        case L1API_T1_140_MS:
            t1Ret = L1CAPI_T1_V140;        
            break;
        case L1API_T1_160_MS:
            t1Ret = L1CAPI_T1_V160;        
            break;
        case L1API_T1_200_MS:
            t1Ret = L1CAPI_T1_V200;        
            break;
        case L1API_T1_300_MS:
            t1Ret = L1CAPI_T1_V300;        
            break;
        case L1API_T1_400_MS:
            t1Ret = L1CAPI_T1_V400;        
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
            msgStatus->additionalInfo0 = PARAM_3;
            msgStatus->additionalInfo1 = t1;
            break;
    }
    return t1Ret;
}

static L1CAPI_CQI_Feedback_Cycle convertFeedbackCycle(L1CAPI_Msg_Status *msgStatus,l1api_cqi_fb_cycle_t feedbackC)
{
    L1CAPI_CQI_Feedback_Cycle feedbackCycleRet;
    switch(feedbackC)
    {
        case L1API_CQI_FEEDBACK_0:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V0;
            break;
        case L1API_CQI_FEEDBACK_2:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V2;
            break;
        case L1API_CQI_FEEDBACK_4:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V4;
            break;
        case L1API_CQI_FEEDBACK_8:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V8;
            break;
        case L1API_CQI_FEEDBACK_10:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V10;
            break;
        case L1API_CQI_FEEDBACK_20:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V20;
            break;
        case L1API_CQI_FEEDBACK_40:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V40;
            break;
        case L1API_CQI_FEEDBACK_80:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V80;
            break;
        case L1API_CQI_FEEDBACK_160:
            feedbackCycleRet = L1CAPI_CQI_FEEDBACK_CYCLE_V160;
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
            msgStatus->additionalInfo0 = PARAM_4;
            msgStatus->additionalInfo1 = feedbackC;
            break;
    }
    return feedbackCycleRet;
}

static L1CAPI_MAC_hsWindowSize Convert_MACHS_WindowSize(L1CAPI_Msg_Status *msgStatus,l1api_machs_window_size_t ccpuType)
{
    L1CAPI_MAC_hsWindowSize macHSWindowSize;
    
    switch(ccpuType)
    {
        case L1API_MACHS_WIN_SZ_4: 
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V4;
            break;
        case L1API_MACHS_WIN_SZ_6:
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V6;
            break;
        case L1API_MACHS_WIN_SZ_8: 
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V8;
            break;
        case L1API_MACHS_WIN_SZ_12:
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V12;
            break;
        case L1API_MACHS_WIN_SZ_16:
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V16;
            break;
        case L1API_MACHS_WIN_SZ_24:
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V24;
            break;
        case L1API_MACHS_WIN_SZ_32:
            macHSWindowSize = L1CAPI_MAC_HSWINDOWSIZE_V32;
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
            msgStatus->additionalInfo0 = PARAM_5;
            msgStatus->additionalInfo1 = ccpuType;
            break;
    }
    return macHSWindowSize;
}

void priorityQInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_PriorityQueue_Info *pL1CPriQInfo,
                                   l1api_priority_queue_info_t * pOpPriQInfo)
{
    pL1CPriQInfo->bit_mask = t1_present|mac_hsWindowSz_present|rlMode_present|associatedHSDSCH_MACdFlow_present;
    pL1CPriQInfo->priorityQueueId = pOpPriQInfo->priority_queue_id;
    pL1CPriQInfo->schedulingPriorityIndicator = pOpPriQInfo->sched_prio_ind;
    pL1CPriQInfo->t1= Convert_T1_Tmr(msgStatus,pOpPriQInfo->t1);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    if(pOpPriQInfo->m.l1api_discard_timer_present){
      pL1CPriQInfo->bit_mask |= discardTimer_present;
      pL1CPriQInfo->discardTimer = Discard_Tmr_Mapping(msgStatus,pOpPriQInfo->discard_timer);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    pL1CPriQInfo->mAC_hsWindowSize= Convert_MACHS_WindowSize(msgStatus,pOpPriQInfo->macHs_window_size);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    if(pOpPriQInfo->macHs_bit_rate != 0 && pOpPriQInfo->m.l1api_machs_bit_rate_present){
      pL1CPriQInfo->bit_mask |= mAChsGuaranteedBitRate_present;
      pL1CPriQInfo->mAChsGuaranteedBitRate = pOpPriQInfo->macHs_bit_rate;
    }
    pL1CPriQInfo->rLC_Mode = pOpPriQInfo->rlc_mode;
    pL1CPriQInfo->associatedHSDSCH_MACdFlow = pOpPriQInfo->associated_macD_flow_id.macD_flow_id;    
    pL1CPriQInfo->macDPduIndexCount = pOpPriQInfo->n_macD_pdu_index;
}

void macDFlowConfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                            L1CAPI_HSDSCH_MACdFlows_Info * pL1CMacDFlowInfo,
                                            l1api_hsdsch_macd_flow_info_t *pOpMacDFlowInfo)
{
    pL1CMacDFlowInfo->macDFlowCount = pOpMacDFlowInfo->n_macD_flow;
    pL1CMacDFlowInfo->priorityQueueCount = pOpMacDFlowInfo->n_priority_queue;    
}

void macDFlowReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_HSDSCH_MACdFlows_Reconfig_Info * pL1CMacDFlowInfo,
                                               l1api_hsdsch_macd_flow_reconfig_t *pOpMacDFlowInfo)
{
    pL1CMacDFlowInfo->macDFlowCount = pOpMacDFlowInfo->n_macD_flow;
    pL1CMacDFlowInfo->priorityQueueCount = pOpMacDFlowInfo->n_priority_queue;
}

void hsdschInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_RadioLink_HSDSCH_Info * pL1CHsdschInfo,
                                  l1api_hsdsch_info_t *pOpHsdschInfo)
{
    pL1CHsdschInfo->bit_mask = hsscch_PowerOffset_present|measurement_Power_Offset_present;
    pL1CHsdschInfo->hsdcschPhysCat = pOpHsdschInfo->hsdsch_phys_cat + 1; /*CCPU minus 1 so we add 1*/
    pL1CHsdschInfo->macHsReorderBuffSz = pOpHsdschInfo->macHs_reorder_buff_sz;
    pL1CHsdschInfo->cqiFeedback_CycleK = convertFeedbackCycle(msgStatus,pOpHsdschInfo->cqi_fb_cycle);
    pL1CHsdschInfo->cqiRepetitionFactor = pOpHsdschInfo->cqi_rep_factor + 1;/*CCPU +1 for RB setup message*/
    pL1CHsdschInfo->ackNackRepetitionFactor = pOpHsdschInfo->ack_nack_rep_factor + 1;/*CCPU +1 for RB setup message*/
    pL1CHsdschInfo->cqiPowerOffset = pOpHsdschInfo->cqi_power_offset;
    pL1CHsdschInfo->ackPowerOffset = pOpHsdschInfo->ack_power_offset;
    pL1CHsdschInfo->nackPowerOffset = pOpHsdschInfo->nack_power_offset;
    pL1CHsdschInfo->hsscch_PowerOffset = pOpHsdschInfo->hsscch_power_offset;
    pL1CHsdschInfo->measurement_Power_Offset = pOpHsdschInfo->meas_power_offset - 12;/*CCPU -12 for RB setup message*/
}

void hsdschModifyInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_RadioLink_HSDSCH_Reconfig_Info * pL1CHsdschInfo,
                                         l1api_hsdsch_info_reconfig_t *pOpHsdschInfo)
{
    pL1CHsdschInfo->bit_mask = macHsReorderBufSz_present|cqiFeedbackCycle_present|
                               cqiRepetitionFactor_present|ackNackRepetitionFactor_present|
                               cqiPO_present|ackPO_present|nackPO_present|hsscchPO_present|
                               measmentPO_present|hsdschMacDFlowReconfigInfo_present;
    pL1CHsdschInfo->macHsReorderBuffSz = pOpHsdschInfo->macHs_reorder_buff_sz;
    pL1CHsdschInfo->cqiFeedback_CycleK = convertFeedbackCycle(msgStatus,pOpHsdschInfo->cqi_fb_cycle);
    pL1CHsdschInfo->cqiRepetitionFactor = pOpHsdschInfo->cqi_rep_factor + 1;
    pL1CHsdschInfo->ackNackRepetitionFactor = pOpHsdschInfo->ack_nack_rep_factor + 1;
    pL1CHsdschInfo->cqiPowerOffset = pOpHsdschInfo->cqi_power_offset;
    pL1CHsdschInfo->ackPowerOffset = pOpHsdschInfo->ack_power_offset;
    pL1CHsdschInfo->nackPowerOffset = pOpHsdschInfo->nack_power_offset;
    pL1CHsdschInfo->hsscch_PowerOffset = pOpHsdschInfo->hsscch_power_offset;
    pL1CHsdschInfo->measurement_Power_Offset = pOpHsdschInfo->meas_power_offset - 12;
}

void hsdschConfigProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                     L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig,
                                     l1api_hsdsch_t *pOpHsdschConfig)
{
    pL1CHsdschConfig->bit_mask = HSDSCH_CONFIG_HsdschInfo_present;
    pL1CHsdschConfig->hsDschRnti = pOpHsdschConfig->hsdsch_rnti;
    pL1CHsdschConfig->hsPschRlId = pOpHsdschConfig->rl_id;
}

void hsdschReconfigProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig,
                                        l1api_hsdsch_reconfig_t *pOpHsdschConfig)
{
    pL1CHsdschReconfig->bit_mask = HSDSCH_RECONFIG_Rnti_present|HSDSCH_RECONFIG_Rlid_present|HSDSCH_RECONFIG_HsdschInfo_present;
    pL1CHsdschReconfig->hsDschRnti = pOpHsdschConfig->hsdsch_rnti;
    pL1CHsdschReconfig->hsPschRlId = pOpHsdschConfig->hs_psch_rl_id;

    if(pOpHsdschConfig->hsdsch_macD_add.n_macD_flow > 0){
      pL1CHsdschReconfig->bit_mask |= HSDSCH_RECONFIG_HsdschMacDFlowAdd_present;
    }    
    if(pOpHsdschConfig->hsdsch_macD_delete.n_macD_flow > 0){
      pL1CHsdschReconfig->bit_mask |= HSDSCH_RECONFIG_HsdschMacDFlowDel_present;
    }    
}

