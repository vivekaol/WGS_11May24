/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Type definition for various data types

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_radiolinkProcedureHsDschDecHdlr.h"
#include "msgGetPrimitives.h"

static __inline__ void macDPduSizeIndexProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                 L1CAPI_MACDPDU_Size_IndexItem *pL1CMacDPduSizeIndex)
{
    pL1CMacDPduSizeIndex->sID = subByteVal();
    pL1CMacDPduSizeIndex->macdPDU_Size = subWordVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void FASTCALL priorityQInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_PriorityQueue_Info *pL1CPriQInfo)
{
    uint8_t i;
    pL1CPriQInfo->bit_mask = subByteVal();
    pL1CPriQInfo->priorityQueueId = subByteVal();
    pL1CPriQInfo->schedulingPriorityIndicator = subByteVal();    
    if(pL1CPriQInfo->bit_mask & t1_present){
      pL1CPriQInfo->t1 = subWordVal();
    }
    if(pL1CPriQInfo->bit_mask & discardTimer_present){
      pL1CPriQInfo->discardTimer = subWordVal();
    }
    if(pL1CPriQInfo->bit_mask & mac_hsWindowSz_present){
      pL1CPriQInfo->mAC_hsWindowSize = subByteVal();
    }
    if(pL1CPriQInfo->bit_mask & mAChsGuaranteedBitRate_present){
      pL1CPriQInfo->mAChsGuaranteedBitRate = subLongVal();
    }
    if(pL1CPriQInfo->bit_mask & rlMode_present){
      pL1CPriQInfo->rLC_Mode = subByteVal();
    }
    if(pL1CPriQInfo->bit_mask & associatedHSDSCH_MACdFlow_present){
      pL1CPriQInfo->associatedHSDSCH_MACdFlow = subByteVal();
    }
    pL1CPriQInfo->macDPduIndexCount = subByteVal();
    pL1CPriQInfo->ptrMacdPDU_Size_Index	= 
      (L1CAPI_MACDPDU_Size_IndexItem *)allocMem(sizeof(L1CAPI_MACDPDU_Size_IndexItem) * pL1CPriQInfo->macDPduIndexCount,0);
    for(i=0;i<pL1CPriQInfo->macDPduIndexCount;i++)
    {
      macDPduSizeIndexProcDecHdlr(msgStatus,&( pL1CPriQInfo->ptrMacdPDU_Size_Index[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }

}

static void priorityQReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_PriorityQueue_Reconfig_Info *pL1CPriQInfo)
{
    pL1CPriQInfo->priQueueAdjType = subByteVal();
    if(pL1CPriQInfo->priQueueAdjType == L1CAPI_PRI_QUEUE_ADD)
    {
      pL1CPriQInfo->u.ptrPriorityQueueAdd_Info = 
        (L1CAPI_PriorityQueue_Info *)allocMem(sizeof(L1CAPI_PriorityQueue_Info),0);
      priorityQInfoProcDecHdlr(msgStatus,pL1CPriQInfo->u.ptrPriorityQueueAdd_Info);
    }
    if(pL1CPriQInfo->priQueueAdjType == L1CAPI_PRI_QUEUE_MOD)
    {
      pL1CPriQInfo->u.ptrPriorityQueueMod_Info = 
        (L1CAPI_PriorityQueue_Info *)allocMem(sizeof(L1CAPI_PriorityQueue_Info),0);
      priorityQInfoProcDecHdlr(msgStatus,pL1CPriQInfo->u.ptrPriorityQueueMod_Info);
    }
    else{
      pL1CPriQInfo->u.priorityQueueDel_Info = subByteVal();
    }
}

static void macDFlowConfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_HSDSCH_MACdFlows_Info *pL1CMacDFlowInfo )
{
    uint8_t i;
	
    pL1CMacDFlowInfo->macDFlowCount = subByteVal();
    pL1CMacDFlowInfo->priorityQueueCount = subByteVal();
    pL1CMacDFlowInfo->ptrHDSCH_MACdFlow_Info = 
      allocMem(sizeof(L1CAPI_HSDSCH_MACdFlow_ID) * pL1CMacDFlowInfo->macDFlowCount,0);
    pL1CMacDFlowInfo->ptrPriorityQueue_Info = 
      (L1CAPI_PriorityQueue_Info *)allocMem(sizeof(L1CAPI_PriorityQueue_Info) * pL1CMacDFlowInfo->priorityQueueCount,0);
    for(i=0;i<pL1CMacDFlowInfo->macDFlowCount;i++)
    {
	  pL1CMacDFlowInfo->ptrHDSCH_MACdFlow_Info[i] = subByteVal();
    }
    for(i=0;i<pL1CMacDFlowInfo->priorityQueueCount;i++)
    {
      priorityQInfoProcDecHdlr(msgStatus,&(pL1CMacDFlowInfo->ptrPriorityQueue_Info[i]));
    }
}

static void macDFlowReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_HSDSCH_MACdFlows_Reconfig_Info *pL1CMacDFlowInfo)
{
    uint8_t i;
	
    pL1CMacDFlowInfo->macDFlowCount = subByteVal();
    pL1CMacDFlowInfo->priorityQueueCount = subByteVal();
    pL1CMacDFlowInfo->ptrHDSCH_MACdFlow_Info = 
      allocMem(sizeof(L1CAPI_HSDSCH_MACdFlow_ID) * pL1CMacDFlowInfo->macDFlowCount,0);
    pL1CMacDFlowInfo->ptrPriorityQueue_Info = 
      (L1CAPI_PriorityQueue_Reconfig_Info *)allocMem(sizeof(L1CAPI_PriorityQueue_Reconfig_Info) * pL1CMacDFlowInfo->priorityQueueCount,0);
    for(i=0;i<pL1CMacDFlowInfo->macDFlowCount;i++)
    {
      pL1CMacDFlowInfo->ptrHDSCH_MACdFlow_Info[i] = subByteVal();
    }
    for(i=0;i<pL1CMacDFlowInfo->priorityQueueCount;i++)
    {
      priorityQReconfigInfoProcDecHdlr(msgStatus,&(pL1CMacDFlowInfo->ptrPriorityQueue_Info[i]));
    }
}

static __inline__ void macDFlowDelInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_HSDSCH_MACdFlows_Delete_Info *pL1CMacDFlowDelInfo)
{
    uint8_t i;

    pL1CMacDFlowDelInfo->macDFlowCount = subByteVal();
    pL1CMacDFlowDelInfo->ptrHDSCH_MACdFlow_Info	= 
      allocMem(sizeof(L1CAPI_HSDSCH_MACdFlow_ID) * pL1CMacDFlowDelInfo->macDFlowCount,0);
    for(i=0;i<pL1CMacDFlowDelInfo->macDFlowCount;i++)
    {
	  pL1CMacDFlowDelInfo->ptrHDSCH_MACdFlow_Info[i] = subByteVal();
    }
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}


static void hsdschInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_RadioLink_HSDSCH_Info *pL1CHsdschInfo)
{
    pL1CHsdschInfo->bit_mask = subByteVal();
    pL1CHsdschInfo->hsdcschPhysCat = subByteVal();
    pL1CHsdschInfo->macHsReorderBuffSz = subWordVal();
    pL1CHsdschInfo->cqiFeedback_CycleK = subByteVal();
    pL1CHsdschInfo->cqiRepetitionFactor = subByteVal();
    pL1CHsdschInfo->ackNackRepetitionFactor = subByteVal();
    pL1CHsdschInfo->cqiPowerOffset = subByteVal();
    pL1CHsdschInfo->ackPowerOffset = subByteVal();
    pL1CHsdschInfo->nackPowerOffset = subByteVal();
    if(pL1CHsdschInfo->bit_mask & hsscch_PowerOffset_present){
      pL1CHsdschInfo->hsscch_PowerOffset = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & measurement_Power_Offset_present){
      pL1CHsdschInfo->measurement_Power_Offset = subByteVal();
    }	
    macDFlowConfigInfoProcDecHdlr(msgStatus,&(pL1CHsdschInfo->hsdschMacDFlowInfo));
}

static void hsdschModifyInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_RadioLink_HSDSCH_Reconfig_Info *pL1CHsdschInfo)
{
    pL1CHsdschInfo->bit_mask = subWordVal();
    if(pL1CHsdschInfo->bit_mask & macHsReorderBufSz_present){
      pL1CHsdschInfo->macHsReorderBuffSz = subWordVal();
    }
    if(pL1CHsdschInfo->bit_mask & cqiFeedbackCycle_present){
      pL1CHsdschInfo->cqiFeedback_CycleK = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & cqiRepetitionFactor_present){
      pL1CHsdschInfo->cqiRepetitionFactor = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & ackNackRepetitionFactor_present){
      pL1CHsdschInfo->ackNackRepetitionFactor = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & cqiPO_present){
      pL1CHsdschInfo->cqiPowerOffset = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & ackPO_present){
      pL1CHsdschInfo->ackPowerOffset = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & nackPO_present){
      pL1CHsdschInfo->nackPowerOffset = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & hsscchPO_present){
      pL1CHsdschInfo->hsscch_PowerOffset = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & measmentPO_present){
      pL1CHsdschInfo->measurement_Power_Offset = subByteVal();
    }
    if(pL1CHsdschInfo->bit_mask & hsdschMacDFlowReconfigInfo_present){
      pL1CHsdschInfo->ptrHsdschMacDFlowReconfigInfo = 
        (L1CAPI_HSDSCH_MACdFlows_Reconfig_Info *)allocMem(sizeof(L1CAPI_HSDSCH_MACdFlows_Reconfig_Info),0);
      macDFlowReconfigInfoProcDecHdlr(msgStatus,pL1CHsdschInfo->ptrHsdschMacDFlowReconfigInfo);
    }
}

void hsdschConfigProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig)
{
    pL1CHsdschConfig->bit_mask = subByteVal();
    pL1CHsdschConfig->hsDschRnti = subWordVal();
    pL1CHsdschConfig->hsPschRlId = subByteVal();
    if(pL1CHsdschConfig->bit_mask & HSDSCH_CONFIG_HsdschInfo_present){
      pL1CHsdschConfig->ptrHdschInfo = 
        (L1CAPI_RadioLink_HSDSCH_Info *)allocMem(sizeof(L1CAPI_RadioLink_HSDSCH_Info),0);
      hsdschInfoProcDecHdlr(msgStatus,pL1CHsdschConfig->ptrHdschInfo);
    }
}

void hsdschReconfigProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig)
{
    pL1CHsdschReconfig->bit_mask = subByteVal();
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_Rnti_present){
      pL1CHsdschReconfig->hsDschRnti = subWordVal();
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_Rlid_present){
      pL1CHsdschReconfig->hsPschRlId = subByteVal();	  
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschInfo_present){
      pL1CHsdschReconfig->ptrHdschInfo = 
        (L1CAPI_RadioLink_HSDSCH_Info *)allocMem(sizeof(L1CAPI_RadioLink_HSDSCH_Info),0);
      hsdschInfoProcDecHdlr(msgStatus,pL1CHsdschReconfig->ptrHdschInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschModify_present){
      pL1CHsdschReconfig->ptrHsdschModify = 
        (L1CAPI_RadioLink_HSDSCH_Reconfig_Info *)allocMem(sizeof(L1CAPI_RadioLink_HSDSCH_Reconfig_Info),0);
      hsdschModifyInfoProcDecHdlr(msgStatus,pL1CHsdschReconfig->ptrHsdschModify);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;      
    }
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschMacDFlowAdd_present){
      pL1CHsdschReconfig->ptrHsdschMacDFlowAdd = 
        (L1CAPI_HSDSCH_MACdFlows_Info *)allocMem(sizeof(L1CAPI_HSDSCH_MACdFlows_Info),0);
      macDFlowConfigInfoProcDecHdlr(msgStatus,pL1CHsdschReconfig->ptrHsdschMacDFlowAdd);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;	  
	}
    if(pL1CHsdschReconfig->bit_mask & HSDSCH_RECONFIG_HsdschMacDFlowDel_present){
      pL1CHsdschReconfig->ptrHsdschMacDFlowDel = 
        (L1CAPI_HSDSCH_MACdFlows_Delete_Info *)allocMem(sizeof(L1CAPI_HSDSCH_MACdFlows_Delete_Info),0);
      macDFlowDelInfoProcDecHdlr(msgStatus,pL1CHsdschReconfig->ptrHsdschMacDFlowDel);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;	  
    }
}

