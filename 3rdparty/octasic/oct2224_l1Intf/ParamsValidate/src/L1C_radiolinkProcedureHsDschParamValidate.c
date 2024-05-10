/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure HighSpeed Dedicated Shared Channel 
   Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureHsDschParamValidate.h"
#include "l1IntEnums.h"


void macDPduSizeIndexProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_MACDPDU_Size_IndexItem *pL1CMacDPduSizeIndex)
{
    if(pL1CMacDPduSizeIndex->sID > 7 )
    {
      msgStatus->l1MsgResult = L1_EMSG_MACDPDUSIZEINDEX;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CMacDPduSizeIndex->sID;
      return;
    }

    if ( pL1CMacDPduSizeIndex->macdPDU_Size > 4999 )
    {
      msgStatus->l1MsgResult = L1_EMSG_MACDPDUSIZEINDEX;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CMacDPduSizeIndex->macdPDU_Size;
      return;
    }    
}

void Discard_Tmr_ParamValidate(L1CAPI_Msg_Status *msgStatus,L1CAPI_DiscardTimer tmr)
{
    switch(tmr)
    {
        case L1CAPI_DISCARDTIMER_V20:
        case L1CAPI_DISCARDTIMER_V40: 
        case L1CAPI_DISCARDTIMER_V60: 
        case L1CAPI_DISCARDTIMER_V80: 
        case L1CAPI_DISCARDTIMER_V100:
        case L1CAPI_DISCARDTIMER_V120:
        case L1CAPI_DISCARDTIMER_V140:
        case L1CAPI_DISCARDTIMER_V160:
        case L1CAPI_DISCARDTIMER_V180:
        case L1CAPI_DISCARDTIMER_V200:
        case L1CAPI_DISCARDTIMER_V250:
        case L1CAPI_DISCARDTIMER_V300:
        case L1CAPI_DISCARDTIMER_V400:
        case L1CAPI_DISCARDTIMER_V500:
        case L1CAPI_DISCARDTIMER_V750:
        case L1CAPI_DISCARDTIMER_V1000:
        case L1CAPI_DISCARDTIMER_V1250:
        case L1CAPI_DISCARDTIMER_V1500:
        case L1CAPI_DISCARDTIMER_V1750:
        case L1CAPI_DISCARDTIMER_V2000:
        case L1CAPI_DISCARDTIMER_V2500:
        case L1CAPI_DISCARDTIMER_V3000:
        case L1CAPI_DISCARDTIMER_V3500:
        case L1CAPI_DISCARDTIMER_V4000:
        case L1CAPI_DISCARDTIMER_V4500:
        case L1CAPI_DISCARDTIMER_V5000:
        case L1CAPI_DISCARDTIMER_V7500:
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
            msgStatus->additionalInfo0 = PARAM_4;
            msgStatus->additionalInfo1 = tmr;
            break;
    }
}

void T1_Tmr_ParamValidate(L1CAPI_Msg_Status *msgStatus,L1CAPI_T1 t1)
{
    switch(t1)
    {
        case L1CAPI_T1_V10:
        case L1CAPI_T1_V20:
        case L1CAPI_T1_V30:
        case L1CAPI_T1_V40:
        case L1CAPI_T1_V50:
        case L1CAPI_T1_V60:
        case L1CAPI_T1_V70:
        case L1CAPI_T1_V80:
        case L1CAPI_T1_V90:
        case L1CAPI_T1_V100:
        case L1CAPI_T1_V120:
        case L1CAPI_T1_V140:
        case L1CAPI_T1_V160:
        case L1CAPI_T1_V200:
        case L1CAPI_T1_V300:
        case L1CAPI_T1_V400:
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
            msgStatus->additionalInfo0 = PARAM_3;
            msgStatus->additionalInfo1 = t1;
            break;
    }
}

void mACHS_WindowSize_ParamValidate(L1CAPI_Msg_Status *msgStatus,L1CAPI_MAC_hsWindowSize type)
{
    switch(type)
    {
        case L1CAPI_MAC_HSWINDOWSIZE_V4: 
        case L1CAPI_MAC_HSWINDOWSIZE_V6:
        case L1CAPI_MAC_HSWINDOWSIZE_V8: 
        case L1CAPI_MAC_HSWINDOWSIZE_V12:
        case L1CAPI_MAC_HSWINDOWSIZE_V16:
        case L1CAPI_MAC_HSWINDOWSIZE_V24:
        case L1CAPI_MAC_HSWINDOWSIZE_V32:
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
            msgStatus->additionalInfo0 = PARAM_5;
            msgStatus->additionalInfo1 = type;
            break;
    }
}

void priorityQInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_PriorityQueue_Info *pL1CPriQInfo)
{
    if(pL1CPriQInfo->priorityQueueId > 7 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CPriQInfo->priorityQueueId;
      return;
    }    
    if (pL1CPriQInfo->schedulingPriorityIndicator > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CPriQInfo->schedulingPriorityIndicator;
      return;
    }
    if(pL1CPriQInfo->bit_mask & t1_present){
      T1_Tmr_ParamValidate(msgStatus,pL1CPriQInfo->t1);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CPriQInfo->bit_mask & discardTimer_present){
      Discard_Tmr_ParamValidate(msgStatus,pL1CPriQInfo->discardTimer);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CPriQInfo->bit_mask & mac_hsWindowSz_present){
      mACHS_WindowSize_ParamValidate(msgStatus,pL1CPriQInfo->mAC_hsWindowSize);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CPriQInfo->bit_mask & mAChsGuaranteedBitRate_present){
      if(pL1CPriQInfo->mAChsGuaranteedBitRate > (((uint32_t)1<<24) - 1) )
      {
        msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
        msgStatus->additionalInfo0 = PARAM_6;
        msgStatus->additionalInfo1 = pL1CPriQInfo->mAChsGuaranteedBitRate;
        return;
      }    
    }
    if((pL1CPriQInfo->bit_mask & rlMode_present) && (pL1CPriQInfo->rLC_Mode > L1CAPI_RLC_UM ))
    {
      msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CPriQInfo->rLC_Mode;
      return;
    }    
    if((pL1CPriQInfo->bit_mask & associatedHSDSCH_MACdFlow_present) && (pL1CPriQInfo->associatedHSDSCH_MACdFlow > L1CAPI_MAX_NR_OF_HS_MACD_FLOWS ))
    {
      msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
      msgStatus->additionalInfo0 = PARAM_8;
      msgStatus->additionalInfo1 = pL1CPriQInfo->associatedHSDSCH_MACdFlow;
      return;
    }    
    if((pL1CPriQInfo->macDPduIndexCount < 1 ) || (pL1CPriQInfo->macDPduIndexCount > L1CAPI_MAX_NR_OF_MACDPDU_IDX) )
    {
      msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CPriQInfo->macDPduIndexCount;
      return;
    }
}

void macDFlowConfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_HSDSCH_MACdFlows_Info * pL1CMacDFlowInfo)
{
    if((pL1CMacDFlowInfo->macDFlowCount < 1 ) || ( pL1CMacDFlowInfo->macDFlowCount > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHMACDFLOWINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CMacDFlowInfo->macDFlowCount;
      return;
    }
    if((pL1CMacDFlowInfo->priorityQueueCount < 1 ) || ( pL1CMacDFlowInfo->priorityQueueCount > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHMACDFLOWINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CMacDFlowInfo->priorityQueueCount;
      return;
    }
    
}

void macDFlowReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                    L1CAPI_HSDSCH_MACdFlows_Reconfig_Info * pL1CMacDFlowInfo)
{
    if((pL1CMacDFlowInfo->macDFlowCount < 1 ) || ( pL1CMacDFlowInfo->macDFlowCount > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHMACDFLOWINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CMacDFlowInfo->macDFlowCount;
      return;
    }
    if((pL1CMacDFlowInfo->priorityQueueCount < 1 ) || ( pL1CMacDFlowInfo->priorityQueueCount > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHMACDFLOWINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CMacDFlowInfo->priorityQueueCount;
      return;
    }
}

void hsdschInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_RadioLink_HSDSCH_Info * pL1CHsdschInfo)
{
    if(pL1CHsdschInfo->hsdcschPhysCat > 63 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->hsdcschPhysCat;
      return;
    }
    if(pL1CHsdschInfo->macHsReorderBuffSz > 300 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->macHsReorderBuffSz;
      return;
    }
    if(pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V0 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V2 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V4 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V8 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V10 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V20 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V40 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V80 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V160 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V16 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V32 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V64)
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->cqiFeedback_CycleK;
      return;
    }
    if(pL1CHsdschInfo->cqiRepetitionFactor > 4 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->cqiRepetitionFactor;
      return;
    }
    if(pL1CHsdschInfo->ackNackRepetitionFactor > 3 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->ackNackRepetitionFactor;
      return;
    }
    if(pL1CHsdschInfo->cqiPowerOffset > 8 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->cqiPowerOffset;
      return;
    }
    if(pL1CHsdschInfo->ackPowerOffset > 8 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->ackPowerOffset;
      return;
    }
    if(pL1CHsdschInfo->nackPowerOffset > 8 )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->nackPowerOffset;
      return;
    }

    if(pL1CHsdschInfo->bit_mask & measurement_Power_Offset_present){
      if(pL1CHsdschInfo->measurement_Power_Offset > 38 )
      {
        msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFO;
        msgStatus->additionalInfo0 = PARAM_9;
        msgStatus->additionalInfo1 = pL1CHsdschInfo->measurement_Power_Offset;
        return;
      }
    }
}

void hsdschModifyInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_RadioLink_HSDSCH_Reconfig_Info * pL1CHsdschInfo)
{
   if((pL1CHsdschInfo->bit_mask & macHsReorderBufSz_present) &&
     (pL1CHsdschInfo->macHsReorderBuffSz > 300 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->macHsReorderBuffSz;
      return;
    }
    if((pL1CHsdschInfo->bit_mask & cqiFeedbackCycle_present) && (
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V0 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V2 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V4 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V8 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V10 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V20 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V40 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V80 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V160 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V16 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V32 &&
        pL1CHsdschInfo->cqiFeedback_CycleK != L1CAPI_CQI_FEEDBACK_CYCLE_V64))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->cqiFeedback_CycleK;
      return;
    }
    if((pL1CHsdschInfo->bit_mask & cqiRepetitionFactor_present) &&
      (pL1CHsdschInfo->cqiRepetitionFactor > 3 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->cqiRepetitionFactor;
      return;
    }
    if((pL1CHsdschInfo->bit_mask & ackNackRepetitionFactor_present) &&
      (pL1CHsdschInfo->ackNackRepetitionFactor > 3 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->ackNackRepetitionFactor;
      return;
    }
    if((pL1CHsdschInfo->bit_mask & cqiPO_present) &&
      (pL1CHsdschInfo->cqiPowerOffset > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->cqiPowerOffset;
      return;
    }
    if((pL1CHsdschInfo->bit_mask & ackPO_present) &&
      (pL1CHsdschInfo->ackPowerOffset > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_6;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->ackPowerOffset;
      return;
    }
    if((pL1CHsdschInfo->bit_mask & nackPO_present) &&
      (pL1CHsdschInfo->nackPowerOffset > 8 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_7;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->nackPowerOffset;
      return;
    }

    if((pL1CHsdschInfo->bit_mask & measmentPO_present) &&
      (pL1CHsdschInfo->measurement_Power_Offset > 38 ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHINFORE;
      msgStatus->additionalInfo0 = PARAM_9;
      msgStatus->additionalInfo1 = pL1CHsdschInfo->measurement_Power_Offset;
      return;
    }
}

void hsdschConfigProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig)
{
    if (pL1CHsdschConfig->hsPschRlId > L1CAPI_MAX_USERS )
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCH;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CHsdschConfig->hsPschRlId;
      return;
    }      
}

void hsdschReconfigProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig)
{
    if((pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_Rlid_present) && 
      (pL1CHsdschReconfig->hsPschRlId > L1CAPI_MAX_USERS ))
    {
      msgStatus->l1MsgResult = L1_EMSG_HSDSCHRE;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CHsdschReconfig->hsPschRlId;
      return;
    }      
}

