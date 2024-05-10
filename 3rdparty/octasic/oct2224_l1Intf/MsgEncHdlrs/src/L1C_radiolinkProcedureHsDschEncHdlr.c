/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure High Speed Dedicated Shared Channel Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureHsDschEncHdlr.h"
#include "L1C_radiolinkProcedureHsDschParamValidate.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"


static void macDPduSizeIndexProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_MACDPDU_Size_IndexItem *pL1CMacDPduSizeIndex = (L1CAPI_MACDPDU_Size_IndexItem *)pSrc;


    macDPduSizeIndexProcParamValidate(msgStatus,pL1CMacDPduSizeIndex);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMacDPduSizeIndex->sID);
    ADD_WORD_VAL(pL1CMacDPduSizeIndex->macdPDU_Size);
END_BLOCK_TRACE
}

static void priorityQInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;    
    L1CAPI_PriorityQueue_Info *pL1CPriQInfo = (L1CAPI_PriorityQueue_Info *)pSrc;
    void * pMacDPduSizeIndex;    


    priorityQInfoProcParamValidate(msgStatus,pL1CPriQInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPriQInfo->bit_mask);
    ADD_BYTE_VAL(pL1CPriQInfo->priorityQueueId);
    ADD_BYTE_VAL(pL1CPriQInfo->schedulingPriorityIndicator);    
    if(pL1CPriQInfo->bit_mask & t1_present){
      ADD_WORD_VAL(pL1CPriQInfo->t1);
    }
    if(pL1CPriQInfo->bit_mask & discardTimer_present){
      ADD_WORD_VAL(pL1CPriQInfo->discardTimer);
    }
    if(pL1CPriQInfo->bit_mask & mac_hsWindowSz_present){
      ADD_BYTE_VAL(pL1CPriQInfo->mAC_hsWindowSize);
    }
    if(pL1CPriQInfo->bit_mask & mAChsGuaranteedBitRate_present){
      ADD_LONG_VAL(pL1CPriQInfo->mAChsGuaranteedBitRate);
    }
    if(pL1CPriQInfo->bit_mask & rlMode_present){
      ADD_BYTE_VAL(pL1CPriQInfo->rLC_Mode);
    }
    if(pL1CPriQInfo->bit_mask & associatedHSDSCH_MACdFlow_present){
      ADD_BYTE_VAL(pL1CPriQInfo->associatedHSDSCH_MACdFlow);
    }
    ADD_BYTE_VAL(pL1CPriQInfo->macDPduIndexCount);
    for(i=0;i<pL1CPriQInfo->macDPduIndexCount;i++)
    {
      pMacDPduSizeIndex = &(pL1CPriQInfo->ptrMacdPDU_Size_Index[i]);
      macDPduSizeIndexProcEncHdlr(msgStatus,pMacDPduSizeIndex);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

static void priorityQReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_PriorityQueue_Reconfig_Info *pL1CPriQInfo = (L1CAPI_PriorityQueue_Reconfig_Info *)pSrc;
    void * priQInfoAddMod;
    L1CAPI_PriorityQueue_Id priQId;
    if(pL1CPriQInfo->priQueueAdjType == L1CAPI_PRI_QUEUE_ADD){
      priQInfoAddMod = pL1CPriQInfo->u.ptrPriorityQueueAdd_Info;
    }
    else if(pL1CPriQInfo->priQueueAdjType == L1CAPI_PRI_QUEUE_MOD){
      priQInfoAddMod = pL1CPriQInfo->u.ptrPriorityQueueMod_Info;
    }
    else{
      priQId = pL1CPriQInfo->u.priorityQueueDel_Info;
    }
    if(priQId > 7 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PRIORITYQUEUEINFO;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = priQId;
      return;
    } 
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPriQInfo->priQueueAdjType);
    if(pL1CPriQInfo->priQueueAdjType != L1CAPI_PRI_QUEUE_DEL)
    {
      priorityQInfoProcEncHdlr(msgStatus,priQInfoAddMod);
    }
    else{
      ADD_BYTE_VAL(priQId);
    }
END_BLOCK_TRACE
}

static void macDFlowConfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_HSDSCH_MACdFlow_ID flowId;
    L1CAPI_HSDSCH_MACdFlows_Info *pL1CMacDFlowInfo = (L1CAPI_HSDSCH_MACdFlows_Info *)pSrc;
    void * priQInfo;


    
    macDFlowConfigInfoProcParamValidate(msgStatus,pL1CMacDFlowInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMacDFlowInfo->macDFlowCount);
    ADD_BYTE_VAL(pL1CMacDFlowInfo->priorityQueueCount);
    for(i=0;i<pL1CMacDFlowInfo->macDFlowCount;i++)
    {
      flowId = pL1CMacDFlowInfo->ptrHDSCH_MACdFlow_Info[i];
      if(flowId > 7 )
      {
        msgStatus->l1MsgResult = L1_EMSG_MACDFLOWINFOSETUP;
        msgStatus->additionalInfo0 = PARAM_0;
        msgStatus->additionalInfo1 = flowId;
        return;
      }
      ADD_BYTE_VAL(flowId);
    }
    for(i=0;i<pL1CMacDFlowInfo->priorityQueueCount;i++)
    {
      priQInfo = &(pL1CMacDFlowInfo->ptrPriorityQueue_Info[i]);
      priorityQInfoProcEncHdlr(msgStatus,priQInfo);
    }
END_BLOCK_TRACE
}

static void macDFlowReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_HSDSCH_MACdFlow_ID flowId;
    L1CAPI_HSDSCH_MACdFlows_Reconfig_Info *pL1CMacDFlowInfo = (L1CAPI_HSDSCH_MACdFlows_Reconfig_Info *)pSrc;
    void * priQInfo;



    macDFlowReconfigInfoProcParamValidate(msgStatus,pL1CMacDFlowInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMacDFlowInfo->macDFlowCount);
    ADD_BYTE_VAL(pL1CMacDFlowInfo->priorityQueueCount);
    for(i=0;i<pL1CMacDFlowInfo->macDFlowCount;i++)
    {
      flowId = pL1CMacDFlowInfo->ptrHDSCH_MACdFlow_Info[i];
      if(flowId > 7 )
      {
        msgStatus->l1MsgResult = L1_EMSG_MACDFLOWINFOSETUP;
        msgStatus->additionalInfo0 = PARAM_0;
        msgStatus->additionalInfo1 = flowId;
        return;
      }
      ADD_BYTE_VAL(flowId);
    }
    for(i=0;i<pL1CMacDFlowInfo->priorityQueueCount;i++)
    {
      priQInfo = &(pL1CMacDFlowInfo->ptrPriorityQueue_Info[i]);
      priorityQReconfigInfoProcEncHdlr(msgStatus,priQInfo);
    }
END_BLOCK_TRACE
}

static void macDFlowDelInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_HSDSCH_MACdFlow_ID flowId;
    L1CAPI_HSDSCH_MACdFlows_Delete_Info *pL1CMacDFlowDelInfo = (L1CAPI_HSDSCH_MACdFlows_Delete_Info *)pSrc;


START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMacDFlowDelInfo->macDFlowCount);        
    for(i=0;i<pL1CMacDFlowDelInfo->macDFlowCount;i++)
    {
      flowId = pL1CMacDFlowDelInfo->ptrHDSCH_MACdFlow_Info[i];
      if(flowId > 7 )
      {
        msgStatus->l1MsgResult = L1_EMSG_HSDSCHMACDFLOWDEL;
        msgStatus->additionalInfo0 = PARAM_0;
        msgStatus->additionalInfo1 = flowId;
        return;
      }
START_BLOCK_TRACE
      ADD_BYTE_VAL(flowId);
END_BLOCK_TRACE
    }
END_BLOCK_TRACE
}


static void hsdschInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_RadioLink_HSDSCH_Info *pL1CHsdschInfo = (L1CAPI_RadioLink_HSDSCH_Info *)pSrc;
    void * pHsdschMacDFlowInfo;
	pHsdschMacDFlowInfo = &pL1CHsdschInfo->hsdschMacDFlowInfo;

    hsdschInfoProcParamValidate(msgStatus,pL1CHsdschInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CHsdschInfo->bit_mask);
    ADD_BYTE_VAL(pL1CHsdschInfo->hsdcschPhysCat);
    ADD_WORD_VAL(pL1CHsdschInfo->macHsReorderBuffSz);
    ADD_BYTE_VAL(pL1CHsdschInfo->cqiFeedback_CycleK);
    ADD_BYTE_VAL(pL1CHsdschInfo->cqiRepetitionFactor);
    ADD_BYTE_VAL(pL1CHsdschInfo->ackNackRepetitionFactor);
    ADD_BYTE_VAL(pL1CHsdschInfo->cqiPowerOffset);
    ADD_BYTE_VAL(pL1CHsdschInfo->ackPowerOffset);
    ADD_BYTE_VAL(pL1CHsdschInfo->nackPowerOffset);
    if(pL1CHsdschInfo->bit_mask & hsscch_PowerOffset_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->hsscch_PowerOffset);
    }
    if(pL1CHsdschInfo->bit_mask & measurement_Power_Offset_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->measurement_Power_Offset);
    }    
    macDFlowConfigInfoProcEncHdlr(msgStatus,pHsdschMacDFlowInfo);
END_BLOCK_TRACE
}

static void hsdschModifyInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_RadioLink_HSDSCH_Reconfig_Info *pL1CHsdschInfo = (L1CAPI_RadioLink_HSDSCH_Reconfig_Info *)pSrc;
    void * pMacDFlowReconfigInfo;

    pMacDFlowReconfigInfo = pL1CHsdschInfo->ptrHsdschMacDFlowReconfigInfo;

    hsdschModifyInfoProcParamValidate(msgStatus,pL1CHsdschInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_WORD_VAL(pL1CHsdschInfo->bit_mask);
    if(pL1CHsdschInfo->bit_mask & macHsReorderBufSz_present){
      ADD_WORD_VAL(pL1CHsdschInfo->macHsReorderBuffSz);
    }
    if(pL1CHsdschInfo->bit_mask & cqiFeedbackCycle_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->cqiFeedback_CycleK);
    }
    if(pL1CHsdschInfo->bit_mask & cqiRepetitionFactor_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->cqiRepetitionFactor);
    }
    if(pL1CHsdschInfo->bit_mask & ackNackRepetitionFactor_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->ackNackRepetitionFactor);
    }
    if(pL1CHsdschInfo->bit_mask & cqiPO_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->cqiPowerOffset);
    }
    if(pL1CHsdschInfo->bit_mask & ackPO_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->ackPowerOffset);
    }
    if(pL1CHsdschInfo->bit_mask & nackPO_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->nackPowerOffset);
    }
    if(pL1CHsdschInfo->bit_mask & hsscchPO_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->hsscch_PowerOffset);
    }
    if(pL1CHsdschInfo->bit_mask & measmentPO_present){
      ADD_BYTE_VAL(pL1CHsdschInfo->measurement_Power_Offset);
    }
    if(pL1CHsdschInfo->bit_mask & hsdschMacDFlowReconfigInfo_present){
      macDFlowReconfigInfoProcEncHdlr(msgStatus,pMacDFlowReconfigInfo);
    }
END_BLOCK_TRACE
}

void hsdschConfigProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig = (L1CAPI_Radiolink_HSDSCH_Config *)pSrc;
    void * pHsdschInfo;
    pHsdschInfo = pL1CHsdschConfig->ptrHdschInfo;

    hsdschConfigProcParamValidate(msgStatus,pL1CHsdschConfig);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CHsdschConfig->bit_mask);
    ADD_WORD_VAL(pL1CHsdschConfig->hsDschRnti);
    ADD_BYTE_VAL(pL1CHsdschConfig->hsPschRlId);
    if(pL1CHsdschConfig->bit_mask & HSDSCH_CONFIG_HsdschInfo_present){
      hsdschInfoProcEncHdlr(msgStatus,pHsdschInfo);
    }
END_BLOCK_TRACE
}

void hsdschReconfigProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig = (L1CAPI_Radiolink_HSDSCH_Reconfig *)pSrc;
    void * pHsdschInfo;
    void * pHsdschModifyInfo;
    void * pMacDAdd;
    void * pMacDDel;

    pHsdschInfo = pL1CHsdschReconfig->ptrHdschInfo;
    pHsdschModifyInfo = pL1CHsdschReconfig->ptrHsdschModify;
    pMacDAdd = pL1CHsdschReconfig->ptrHsdschMacDFlowAdd;
    pMacDDel = pL1CHsdschReconfig->ptrHsdschMacDFlowDel;
    hsdschReconfigProcParamValidate(msgStatus,pL1CHsdschReconfig);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CHsdschReconfig->bit_mask);
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_Rnti_present){
      ADD_WORD_VAL(pL1CHsdschReconfig->hsDschRnti);
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_Rlid_present){
      ADD_BYTE_VAL(pL1CHsdschReconfig->hsPschRlId);      
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschInfo_present){
      hsdschInfoProcEncHdlr(msgStatus,pHsdschInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschModify_present){
      hsdschModifyInfoProcEncHdlr(msgStatus,pHsdschModifyInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;      
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschMacDFlowAdd_present){
      macDFlowConfigInfoProcEncHdlr(msgStatus,pMacDAdd);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;      
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschMacDFlowDel_present){
      macDFlowDelInfoProcEncHdlr(msgStatus,pMacDDel);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;      
    }
END_BLOCK_TRACE
}

