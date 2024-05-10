/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Enhanced Dedicated Channel Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include "L1C_radiolinkProcedureEdchEncHdlr.h"
#include "L1C_radiolinkProcedureEdchParamValidate.h"
#include "L1C_cctrchEncHdlr.h"
#include "L1C_tfsEncHdlr.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"


static void edchNonSchedGrantInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_E_DCH_NonScheduled_TxGrantItems  *pL1CEDchNonSchedGrantInfo = (L1CAPI_E_DCH_NonScheduled_TxGrantItems  *)pSrc;

    edchNonSchedGrantInfoProcParamValidate(msgStatus,pL1CEDchNonSchedGrantInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEDchNonSchedGrantInfo->bit_mask); 
    ADD_WORD_VAL(pL1CEDchNonSchedGrantInfo->maxBits_MACe_PDU_non_scheduled);
    if(pL1CEDchNonSchedGrantInfo->bit_mask & hARQ_Ps_An_NnSchd_2ms_present)
    {
      ADD_BYTE_VAL(pL1CEDchNonSchedGrantInfo->hARQ_Prcss_Allctn_NonSched_2ms);
    }
END_BLOCK_TRACE
}

static void edchLogicChInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    uint8_t i;
    uint16_t macDPduSize;
    L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo = (L1CAPI_E_DCH_LogicalChannelInfo *)pSrc;

    edchLogicChInfoProcParamValidate(msgStatus,pL1CEdchLogicChInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;

START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchLogicChInfo->bit_mask);
    ADD_BYTE_VAL(pL1CEdchLogicChInfo->logicalChannelId);
    if(pL1CEdchLogicChInfo->bit_mask & schedulingPriorityIndicator_present)
    {
      ADD_BYTE_VAL(pL1CEdchLogicChInfo->schedulingPriorityIndicator);
    }
    if(pL1CEdchLogicChInfo->bit_mask & schedulingInformation_present)
    {
      ADD_BYTE_VAL(pL1CEdchLogicChInfo->schedulingInformation);
    }
    if(pL1CEdchLogicChInfo->bit_mask & mACesGuaranteedBitRate_present)
    {
      ADD_LONG_VAL(pL1CEdchLogicChInfo->mACesGuaranteedBitRate);
    }
    if(pL1CEdchLogicChInfo->bit_mask & eDCH_DDI_Value_present)
    {
      ADD_BYTE_VAL(pL1CEdchLogicChInfo->e_DCH_DDI_Value);
    }
    ADD_BYTE_VAL(pL1CEdchLogicChInfo->macD_PDU_Size_Count);
    for(i=0;i<pL1CEdchLogicChInfo->macD_PDU_Size_Count;i++)
    {
      macDPduSize = pL1CEdchLogicChInfo->ptrMacDPduSize[i];
      if(macDPduSize > 4999 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
        msgStatus->additionalInfo0 = PARAM_6;
        msgStatus->additionalInfo1 = macDPduSize;
        return;
      }    
START_BLOCK_TRACE
      ADD_WORD_VAL(macDPduSize);
END_BLOCK_TRACE
    }
END_BLOCK_TRACE
}

static void edchLogicChReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    uint8_t i;
    uint16_t macDPduSize;
    L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo = (L1CAPI_E_DCH_LogicalChannelInfo *)pSrc;


    edchLogicChInfoProcParamValidate(msgStatus,pL1CEdchLogicChInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchLogicChInfo->bit_mask);
    ADD_BYTE_VAL(pL1CEdchLogicChInfo->logicalChannelId);
    if(pL1CEdchLogicChInfo->bit_mask & schedulingPriorityIndicator_present)
    {
      ADD_BYTE_VAL(pL1CEdchLogicChInfo->schedulingPriorityIndicator);
    }
    if(pL1CEdchLogicChInfo->bit_mask & schedulingInformation_present)
    {
      ADD_BYTE_VAL(pL1CEdchLogicChInfo->schedulingInformation);
    }
    if(pL1CEdchLogicChInfo->bit_mask & mACesGuaranteedBitRate_present)
    {
      ADD_LONG_VAL(pL1CEdchLogicChInfo->mACesGuaranteedBitRate);
    }
    if(pL1CEdchLogicChInfo->bit_mask & eDCH_DDI_Value_present)
    {
      ADD_BYTE_VAL(pL1CEdchLogicChInfo->e_DCH_DDI_Value);
    }
    ADD_BYTE_VAL(pL1CEdchLogicChInfo->macD_PDU_Size_Count);
    for(i=0;i<pL1CEdchLogicChInfo->macD_PDU_Size_Count;i++)
    {
      macDPduSize = pL1CEdchLogicChInfo->ptrMacDPduSize[i];
      if(macDPduSize > 4999 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFORE;
        msgStatus->additionalInfo0 = PARAM_6;
        msgStatus->additionalInfo1 = macDPduSize;
        return;
      }    
START_BLOCK_TRACE
      ADD_WORD_VAL(macDPduSize);
END_BLOCK_TRACE
    }
END_BLOCK_TRACE
}

static void edchMacDFlowDeleteProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i,madFlowId;
    L1CAPI_E_DCH_MACDFlow_Delete_Info *pL1CMacDFlowDel = (L1CAPI_E_DCH_MACDFlow_Delete_Info *)pSrc;    

    if((pL1CMacDFlowDel->e_DCH_MacDFlow_Count < 1 ) || (pL1CMacDFlowDel->e_DCH_MacDFlow_Count > L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS ) )
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWDEL;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CMacDFlowDel->e_DCH_MacDFlow_Count;
      return;
    }
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMacDFlowDel->e_DCH_MacDFlow_Count);        
    for(i=0;i<pL1CMacDFlowDel->e_DCH_MacDFlow_Count;i++)
    {
      madFlowId = pL1CMacDFlowDel->ptrE_DCH_MACdFlow_ID[i];
      if(madFlowId > (L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS - 1) )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWDEL;
        msgStatus->additionalInfo0 = PARAM_1;
        msgStatus->additionalInfo1 = madFlowId;
        return;
      }
START_BLOCK_TRACE
      ADD_BYTE_VAL(madFlowId);
END_BLOCK_TRACE
    }
END_BLOCK_TRACE
}

static void edchMacDFlowInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_E_DCH_MACDFlow_Info *pL1CEdchMacDFlowInfo = (L1CAPI_E_DCH_MACDFlow_Info *)pSrc;
    void * pNonSchedGrantInfo;
    void * pEdchLogicChInfo;
    pNonSchedGrantInfo = pL1CEdchMacDFlowInfo->ptrEDchNonSchedGrantInfo;
    edchMacDFlowInfoProcParamValidate(msgStatus,pL1CEdchMacDFlowInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->bit_mask);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->payloadCRC_PresenceIndicator);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset);
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_Multiplexing_present)
    {
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDCH_MACdFlow_Multiplexing_List);
    }
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDCH_Grant_Type);
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_bundlingModeIndicator_present)
    {
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->bundlingModeIndicator);
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_eDchNonSchedGrantInfo_present)
    {
      edchNonSchedGrantInfoProcEncHdlr(msgStatus,pNonSchedGrantInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels);
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels;i++)
    {
      pEdchLogicChInfo = &(pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelInformation[i]);
      edchLogicChInfoProcEncHdlr(msgStatus,pEdchLogicChInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

static void edchMacDFlowListProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i,count;
    void * pEdchMadFlowInfo;

    L1CAPI_E_DCH_MACDFlow_Add_Info *pL1CMacDFlowAdd = (L1CAPI_E_DCH_MACDFlow_Add_Info *)pSrc;    
    count = pL1CMacDFlowAdd->e_DCH_MacDFlow_Count;
    if(count > L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS)
    {
      msgStatus->l1MsgResult = L1_EMSG_EDCHMACDFLOWINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = count;
      return;
    }
START_BLOCK_TRACE
    ADD_BYTE_VAL(count);
    for(i=0;i<count;i++)
    {
      pEdchMadFlowInfo = &(pL1CMacDFlowAdd->ptrE_DCH_MACdFlows_Information[i]);
      edchMacDFlowInfoProcEncHdlr(msgStatus,pEdchMadFlowInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS )
        return;
    }
END_BLOCK_TRACE
}

static void edchMacDFlowReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pL1CEdchMacDFlowInfo = NULL;
    void * pNonSchedGrantInfo;
    void * pLogicChAddInfo;
    void * pLogicChModInfo;
    L1CAPI_LogicalChannelID logicChId;
    pNonSchedGrantInfo = pL1CEdchMacDFlowInfo->ptrEDchNonSchedGrantInfo;

    edchMacDFlowReconfigInfoProcParamValidate(msgStatus,pL1CEdchMacDFlowInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->bit_mask);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID);
    if(pL1CEdchMacDFlowInfo->bit_mask & maxNrOfRetransmission_E_DCH_present)
    {    
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH);
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_HarqPowerOffset_present)
    {    
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset);
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_Reconfig_Multiplexing_present)
    {
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDCH_MACdFlow_Multiplexing_List);
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_GrantType_present)
    {
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDCH_Grant_Type);
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_bundlingModeIndicator_present)
    {
      ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->bundlingModeIndicator);
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_eDchNonSchedGrantInfo_present)
    {
      edchNonSchedGrantInfoProcEncHdlr(msgStatus,pNonSchedGrantInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod);
    ADD_BYTE_VAL(pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel);
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd;i++)
    {
      pLogicChAddInfo = &(pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelAdd[i]);
      edchLogicChInfoProcEncHdlr(msgStatus,pLogicChAddInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod;i++)
    {
      pLogicChModInfo = &(pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelMod[i]);
      edchLogicChReconfigInfoProcEncHdlr(msgStatus,pLogicChModInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel;i++)
    {
      logicChId = pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelDel[i];
      if(logicChId > 14 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EDCHLOGICALCHANINFO;
        msgStatus->additionalInfo0 = PARAM_1;
        msgStatus->additionalInfo1 = logicChId ;
        return;
      }
      ADD_BYTE_VAL(logicChId);
    }    
END_BLOCK_TRACE
}

static void servingEdchRlInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_ServingEdch_Radiolink_Info *pL1CServingEdchRlInfo = (L1CAPI_ServingEdch_Radiolink_Info *)pSrc;

    servingEdchRlInfoProcParamValidate(msgStatus,pL1CServingEdchRlInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CServingEdchRlInfo->bit_mask);
    if(pL1CServingEdchRlInfo->bit_mask & serving_edch_rl_id_present)
    {
      ADD_BYTE_VAL(pL1CServingEdchRlInfo->serving_edch_rl_location);
    }
    ADD_BYTE_VAL(pL1CServingEdchRlInfo->serving_edch_rl_id);
END_BLOCK_TRACE
}

static void eDpchConfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_Radiolink_EDpch_Info *pL1CRlEdpchInfo = (L1CAPI_Radiolink_EDpch_Info *)pSrc;
    void * pEtfcsInfo = NULL;
	pEtfcsInfo = &pL1CRlEdpchInfo->e_TFCS_Information;
    edpchConfigInfoProcParamValidate(msgStatus,pL1CRlEdpchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    /*rl edch info*/
    ADD_BYTE_VAL(pL1CRlEdpchInfo->maxSet_E_DPDCHs);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->ul_PunctureLimit);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->e_TTI);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->e_DPCCH_PowerOFfset);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->e_RGCH_2_IndexStepThreshold);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->e_RGCH_3_IndexStepThreshold);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->hARQ_Info_for_E_DCH);
    ADD_BYTE_VAL(pL1CRlEdpchInfo->hSDSCH_Configured_Indicator);
    eTfcsInfoEncHdlr(msgStatus,pEtfcsInfo);
END_BLOCK_TRACE
}

static void eDpchReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_Radiolink_EDpch_Reconfig_Info *pL1CRlEdpchInfo = (L1CAPI_Radiolink_EDpch_Reconfig_Info *)pSrc;
    void * pEtfcsInfo;


    edpchReconfigInfoProcParamValidate(msgStatus,pL1CRlEdpchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_WORD_VAL(pL1CRlEdpchInfo->bit_mask);
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_MaxSetEdpchs_present){
      ADD_BYTE_VAL(pL1CRlEdpchInfo->maxSet_E_DPDCHs);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_PuncLimit_present){
      ADD_BYTE_VAL(pL1CRlEdpchInfo->ul_PunctureLimit);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_ETTI_present){
      ADD_BYTE_VAL(pL1CRlEdpchInfo->e_TTI);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_PwrOffset_present){
      ADD_BYTE_VAL(pL1CRlEdpchInfo->e_DPCCH_PowerOFfset);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_Rgch2Threshold_present){
      ADD_BYTE_VAL(pL1CRlEdpchInfo->e_RGCH_2_IndexStepThreshold);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_Rgch3Threshold_present){    
      ADD_BYTE_VAL(pL1CRlEdpchInfo->e_RGCH_3_IndexStepThreshold);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_HarqInfo_present){    
      ADD_BYTE_VAL(pL1CRlEdpchInfo->hARQ_Info_for_E_DCH);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_HsdschConfigInd_present){
      ADD_BYTE_VAL(pL1CRlEdpchInfo->hSDSCH_Configured_Indicator);
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_ETfcsInfo_present){      
      pEtfcsInfo = pL1CRlEdpchInfo->ptr_ETFCS_Information;
      eTfcsInfoEncHdlr(msgStatus,pEtfcsInfo);
    }
END_BLOCK_TRACE
}

static void edchFddConfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_E_DCH_FDD_Info *pL1CEdchFddInfo = (L1CAPI_E_DCH_FDD_Info *)pSrc;
    void * pEdchMacDPlowInfo;

    edchFddConfigInfoProcParamValidate(msgStatus,pL1CEdchFddInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchFddInfo->bit_mask);
    if(pL1CEdchFddInfo->bit_mask & hARQ_Pc_Ac_Sd_2ms_EDCH_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->hARQ_Proc_Alloc_Sched_2ms_EDCH);      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Maximum_Bitrate_present)
    {
      ADD_LONG_VAL(pL1CEdchFddInfo->e_DCH_Maximum_Bitrate);      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Processing_Overload_Level_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->e_DCH_Processing_Overload_Level);      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reference_Pwr_Offset_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->e_DCH_Reference_Power_Offset);      
    }
    ADD_BYTE_VAL(pL1CEdchFddInfo->e_DCH_MacDFlow_Count);
    for(i=0;i<pL1CEdchFddInfo->e_DCH_MacDFlow_Count;i++){
      pEdchMacDPlowInfo = &(pL1CEdchFddInfo->ptrE_DCH_MACdFlows_Information[i]);
      edchMacDFlowInfoProcEncHdlr(msgStatus,pEdchMacDPlowInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

static void edchFddReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    uint8_t i;
    L1CAPI_E_DCH_FDD_Reconfig_Info *pL1CEdchFddInfo = (L1CAPI_E_DCH_FDD_Reconfig_Info *)pSrc;
    void * pEdchMacDPlowInfo;


    edchFddReconfigInfoProcParamValidate(msgStatus,pL1CEdchFddInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchFddInfo->bit_mask);
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_hARQ_Pc_Ac_Sd_2ms_EDCH_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->hARQ_Proc_Alloc_Sched_2ms_EDCH);      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Maximum_Bitrate_present)
    {
      ADD_LONG_VAL(pL1CEdchFddInfo->e_DCH_Maximum_Bitrate);      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Processing_Overload_Level_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->e_DCH_Processing_Overload_Level);      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Reference_Pwr_Offset_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->e_DCH_Reference_Power_Offset);      
    }
    if(pL1CEdchFddInfo->bit_mask & macERestIndication_present)
    {
      ADD_BYTE_VAL(pL1CEdchFddInfo->macERestIndication);      
    }
    ADD_BYTE_VAL(pL1CEdchFddInfo->e_DCH_MacDFlow_Count);
    for(i=0;i<pL1CEdchFddInfo->e_DCH_MacDFlow_Count;i++){
      pEdchMacDPlowInfo = &(pL1CEdchFddInfo->ptrE_DCH_MACdFlows_Reconfig_Information[i]);
      edchMacDFlowReconfigInfoProcEncHdlr(msgStatus,pEdchMacDPlowInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

void edchExtConfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_Radiolink_EDCH_Config_Ext *pL1CEdchInfo = (L1CAPI_Radiolink_EDCH_Config_Ext *)pSrc;
    void * pEdpchInfo;
    void * pEdchFddInfo;
    void * pEdchServingRlInfo;

    pEdpchInfo = &(pL1CEdchInfo->eDpchInfo);
    pEdchFddInfo = &(pL1CEdchInfo->eDchFddInfo);
    pEdchServingRlInfo = pL1CEdchInfo->ptrServingEdchRlInfo;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchInfo->bit_mask);
    /*edpch info*/
    eDpchConfigInfoProcEncHdlr(msgStatus,pEdpchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;        
    /*edch fdd info*/
    edchFddConfigInfoProcEncHdlr(msgStatus,pEdchFddInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
    /*serving edch rl info*/
    if(pL1CEdchInfo->bit_mask & rl_Setup_servingEdchRlInfo_present)
    {
      servingEdchRlInfoProcEncHdlr(msgStatus,pEdchServingRlInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }    
END_BLOCK_TRACE
}

void edchExtReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_Radiolink_EDCH_Reconfig_Ext *pL1CEdchInfoReconfig = (L1CAPI_Radiolink_EDCH_Reconfig_Ext *)pSrc;
    void * pEdpchInfo;
    void * pEdchFddInfo;
    void * pEdchFddModifyInfo;
    void * pEdchServingRlInfo;
    void * pMacDFlowAdd;
    void * pMacDFlowDel;

    pEdpchInfo = pL1CEdchInfoReconfig->ptrEDpchInfo;
    pEdchFddInfo = pL1CEdchInfoReconfig->ptrEDchFddInfo;
    pEdchFddModifyInfo = pL1CEdchInfoReconfig->ptrEDchFddInfoModify;
    pEdchServingRlInfo = pL1CEdchInfoReconfig->ptrServingEdchRlInfo;
    pMacDFlowAdd = pL1CEdchInfoReconfig->ptrEdchMadDFlowsAdd;
    pMacDFlowDel = pL1CEdchInfoReconfig->ptrEdchMadDFlowsDel;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchInfoReconfig->bit_mask);
    /*edpch info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdpchInfo_present)
    {
      eDpchReconfigInfoProcEncHdlr(msgStatus,pEdpchInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }    
    /*edch fdd info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchFddInfo_present)
    {
      edchFddConfigInfoProcEncHdlr(msgStatus,pEdchFddInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*edch fdd modify info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchFddModifyInfo_present)
    {
      edchFddReconfigInfoProcEncHdlr(msgStatus,pEdchFddModifyInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*edch MacD Flow Add*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchMacDFlowAdd_present)
    {
      edchMacDFlowListProcEncHdlr(msgStatus,pMacDFlowAdd);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*edch MacD Flow Del*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchMacDFlowDel_present)
    {
      edchMacDFlowDeleteProcEncHdlr(msgStatus,pMacDFlowDel);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }    
    /*serving edch rl info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_servingEdchRlInfo_present)
    {
      servingEdchRlInfoProcEncHdlr(msgStatus,pEdchServingRlInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }    
END_BLOCK_TRACE
}

void edchRlInfoExtProcEncHdlr(L1CAPI_Msg_Status *msgStatus ,void *pSrc)
{
    L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt = (L1CAPI_EDCH_RL_InfoExtension *)pSrc;


    edchRlInfoExtProcParamValidate(msgStatus,pL1CEdchRlInfoExt);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CEdchRlInfoExt->bit_mask);
    if(pL1CEdchRlInfoExt->bit_mask & eDchRlInd_present){
      ADD_BYTE_VAL(pL1CEdchRlInfoExt->eDchRlInd);
    }
    if(pL1CEdchRlInfoExt->bit_mask & rlSpecificEDchInfo_present){
      ADD_BYTE_VAL(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask);
      if(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask & e_AGCH_PowerOffset_present)
      {
        ADD_BYTE_VAL(pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_AGCH_PowerOffset);
      }
      if(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask & e_RGCH_PowerOffset_present)
      {
        ADD_BYTE_VAL(pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_RGCH_PowerOffset);
      }
      if(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask & e_HICH_PowerOffset_present)
      {
        ADD_BYTE_VAL(pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_HICH_PowerOffset);
      }
    } 
END_BLOCK_TRACE
}

