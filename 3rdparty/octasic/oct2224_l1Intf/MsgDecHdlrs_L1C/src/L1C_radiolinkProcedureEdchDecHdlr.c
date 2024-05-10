/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchDecHdlr.c

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

#include "L1C_radiolinkProcedureEdchDecHdlr.h"
#include "L1C_CctrchDecHdlr.h"
#include "msgGetPrimitives.h"

static void edchNonSchedGrantInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                      L1CAPI_E_DCH_NonScheduled_TxGrantItems  *pL1CEDchNonSchedGrantInfo)
{
    pL1CEDchNonSchedGrantInfo->bit_mask = subByteVal(); 
    pL1CEDchNonSchedGrantInfo->maxBits_MACe_PDU_non_scheduled = subWordVal();
    if(pL1CEDchNonSchedGrantInfo->bit_mask & hARQ_Ps_An_NnSchd_2ms_present)
    {
      pL1CEDchNonSchedGrantInfo->hARQ_Prcss_Allctn_NonSched_2ms = subByteVal();
    }
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void edchLogicChInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo)
{
    uint8_t i;
	
    pL1CEdchLogicChInfo->bit_mask = subByteVal();
    pL1CEdchLogicChInfo->logicalChannelId = subByteVal();
    if(pL1CEdchLogicChInfo->bit_mask & schedulingPriorityIndicator_present)
    {
      pL1CEdchLogicChInfo->schedulingPriorityIndicator = subByteVal();
    }
    if(pL1CEdchLogicChInfo->bit_mask & schedulingInformation_present)
    {
      pL1CEdchLogicChInfo->schedulingInformation = subByteVal();
    }
    if(pL1CEdchLogicChInfo->bit_mask & mACesGuaranteedBitRate_present)
    {
      pL1CEdchLogicChInfo->mACesGuaranteedBitRate = subLongVal();
    }
    if(pL1CEdchLogicChInfo->bit_mask & eDCH_DDI_Value_present)
    {
      pL1CEdchLogicChInfo->e_DCH_DDI_Value = subByteVal();
    }
    pL1CEdchLogicChInfo->macD_PDU_Size_Count = subByteVal();
    pL1CEdchLogicChInfo->ptrMacDPduSize = 
      (L1CAPI_MACdPDU_Size *)allocMem(sizeof(L1CAPI_MACdPDU_Size) * pL1CEdchLogicChInfo->macD_PDU_Size_Count,0);
    for(i=0;i<pL1CEdchLogicChInfo->macD_PDU_Size_Count;i++)
    {
      pL1CEdchLogicChInfo->ptrMacDPduSize[i] = subWordVal();
    }
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void edchMacDFlowDeleteProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_DCH_MACDFlow_Delete_Info *pL1CMacDFlowDel)
{
    uint8_t i;
	pL1CMacDFlowDel->e_DCH_MacDFlow_Count = subByteVal();
	
	pL1CMacDFlowDel->ptrE_DCH_MACdFlow_ID = 
		(L1CAPI_E_DCH_MACdFlow_ID *)allocMem(sizeof(L1CAPI_E_DCH_MACdFlow_ID)* pL1CMacDFlowDel->e_DCH_MacDFlow_Count,0); 
	
    for(i=0;i<pL1CMacDFlowDel->e_DCH_MacDFlow_Count;i++)
    {
      pL1CMacDFlowDel->ptrE_DCH_MACdFlow_ID[i] = subByteVal();
    }
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void edchMacDFlowInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_MACDFlow_Info *pL1CEdchMacDFlowInfo)
{
    uint8_t i;
    pL1CEdchMacDFlowInfo->bit_mask = subByteVal();
    pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID = subByteVal();
    pL1CEdchMacDFlowInfo->payloadCRC_PresenceIndicator = subByteVal();
    pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH = subByteVal();
    pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset = subByteVal();
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_Multiplexing_present)
    {
      pL1CEdchMacDFlowInfo->eDCH_MACdFlow_Multiplexing_List = subByteVal();
    }
    pL1CEdchMacDFlowInfo->eDCH_Grant_Type = subByteVal();
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_bundlingModeIndicator_present)
    {
      pL1CEdchMacDFlowInfo->bundlingModeIndicator = subByteVal();
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_eDchNonSchedGrantInfo_present)
    {
      pL1CEdchMacDFlowInfo->ptrEDchNonSchedGrantInfo = 
        (L1CAPI_E_DCH_NonScheduled_TxGrantItems *)allocMem(sizeof(L1CAPI_E_DCH_NonScheduled_TxGrantItems),0);
      edchNonSchedGrantInfoProcDecHdlr(msgStatus,pL1CEdchMacDFlowInfo->ptrEDchNonSchedGrantInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels = subByteVal();
    pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelInformation = 
      (L1CAPI_E_DCH_LogicalChannelInfo *)allocMem(sizeof(L1CAPI_E_DCH_LogicalChannelInfo) * pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels,0);
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels;i++)
    {
      edchLogicChInfoProcDecHdlr(msgStatus,&(pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelInformation[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
}

static void edchMacDFlowListProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_MACDFlow_Add_Info * pL1CEdchMacDFlowAdd)
{
    uint8_t i;
    pL1CEdchMacDFlowAdd->e_DCH_MacDFlow_Count = subByteVal();
    pL1CEdchMacDFlowAdd->ptrE_DCH_MACdFlows_Information = 
      (L1CAPI_E_DCH_MACDFlow_Info *)allocMem(sizeof(L1CAPI_E_DCH_MACDFlow_Info) * pL1CEdchMacDFlowAdd->e_DCH_MacDFlow_Count,0);
    for(i=0;i<pL1CEdchMacDFlowAdd->e_DCH_MacDFlow_Count;i++)
    {
      edchMacDFlowInfoProcDecHdlr(msgStatus,&(pL1CEdchMacDFlowAdd->ptrE_DCH_MACdFlows_Information[i]));
	  if(msgStatus->l1MsgResult != L1_MSG_SUCCESS )
        return;
    }
}

static void edchMacDFlowReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                          L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pL1CEdchMacDFlowInfo)
{
	uint8_t i;
	
    pL1CEdchMacDFlowInfo->bit_mask = subByteVal();
    pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID = subByteVal();
    if(pL1CEdchMacDFlowInfo->bit_mask & maxNrOfRetransmission_E_DCH_present)
    {    
      pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH = subByteVal();
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_HarqPowerOffset_present)
    {	
      pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset = subByteVal();
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_Reconfig_Multiplexing_present)
    {
      pL1CEdchMacDFlowInfo->eDCH_MACdFlow_Multiplexing_List = subByteVal();
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_GrantType_present)
    {
      pL1CEdchMacDFlowInfo->eDCH_Grant_Type = subByteVal();
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_bundlingModeIndicator_present)
    {
      pL1CEdchMacDFlowInfo->bundlingModeIndicator = subByteVal();
    }
    if(pL1CEdchMacDFlowInfo->bit_mask & eDCH_MACdFlow_eDchNonSchedGrantInfo_present)
    {
      pL1CEdchMacDFlowInfo->ptrEDchNonSchedGrantInfo = 
        (L1CAPI_E_DCH_NonScheduled_TxGrantItems *)allocMem(sizeof(L1CAPI_E_DCH_NonScheduled_TxGrantItems),0);
      edchNonSchedGrantInfoProcDecHdlr(msgStatus,pL1CEdchMacDFlowInfo->ptrEDchNonSchedGrantInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd = subByteVal();
    pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelAdd = 
      (L1CAPI_E_DCH_LogicalChannelInfo *)allocMem(sizeof(L1CAPI_E_DCH_LogicalChannelInfo) * pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd,0);
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod = subByteVal();
    pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelMod = 
      (L1CAPI_E_DCH_LogicalChannelInfo *)allocMem(sizeof(L1CAPI_E_DCH_LogicalChannelInfo) * pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod,0);
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel = subByteVal();    	
    pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelDel = 
      allocMem(sizeof(L1CAPI_LogicalChannelID) * pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel,0);

	
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd;i++)
    {
      edchLogicChInfoProcDecHdlr(msgStatus,&(pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelAdd[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod;i++)
    {
      edchLogicChInfoProcDecHdlr(msgStatus,&(pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelMod[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }

    for(i=0;i<pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel;i++)
    {
      pL1CEdchMacDFlowInfo->ptrEDCHLogicalChannelDel[i] = subByteVal();
    }	

}

static void servingEdchRlInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_ServingEdch_Radiolink_Info *pL1CServingEdchRlInfo)
{
    pL1CServingEdchRlInfo->bit_mask = subByteVal();
    if(pL1CServingEdchRlInfo->bit_mask & serving_edch_rl_id_present)
    {
      pL1CServingEdchRlInfo->serving_edch_rl_location = subByteVal();
    }
    pL1CServingEdchRlInfo->serving_edch_rl_id = subByteVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void eDpchConfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_Radiolink_EDpch_Info *pL1CRlEdpchInfo)
{
    pL1CRlEdpchInfo->maxSet_E_DPDCHs = subByteVal();
    pL1CRlEdpchInfo->ul_PunctureLimit = subByteVal();
    pL1CRlEdpchInfo->e_TTI = subByteVal();
    pL1CRlEdpchInfo->e_DPCCH_PowerOFfset = subByteVal();
    pL1CRlEdpchInfo->e_RGCH_2_IndexStepThreshold = subByteVal();
    pL1CRlEdpchInfo->e_RGCH_3_IndexStepThreshold = subByteVal();
    pL1CRlEdpchInfo->hARQ_Info_for_E_DCH = subByteVal();
    pL1CRlEdpchInfo->hSDSCH_Configured_Indicator = subByteVal();
    eTfcsInfoDecHdlr(msgStatus,&(pL1CRlEdpchInfo->e_TFCS_Information));
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void eDpchReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_Radiolink_EDpch_Reconfig_Info *pL1CRlEdpchInfo)
{
    pL1CRlEdpchInfo->bit_mask = subWordVal();
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_MaxSetEdpchs_present){
      pL1CRlEdpchInfo->maxSet_E_DPDCHs = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_PuncLimit_present){
      pL1CRlEdpchInfo->ul_PunctureLimit = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_ETTI_present){
      pL1CRlEdpchInfo->e_TTI = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_PwrOffset_present){
      pL1CRlEdpchInfo->e_DPCCH_PowerOFfset = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_Rgch2Threshold_present){
      pL1CRlEdpchInfo->e_RGCH_2_IndexStepThreshold = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_Rgch3Threshold_present){	
      pL1CRlEdpchInfo->e_RGCH_3_IndexStepThreshold = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_HarqInfo_present){	
      pL1CRlEdpchInfo->hARQ_Info_for_E_DCH = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_HsdschConfigInd_present){
      pL1CRlEdpchInfo->hSDSCH_Configured_Indicator = subByteVal();
    }
    if(pL1CRlEdpchInfo->bit_mask & Edpch_Reconfig_ETfcsInfo_present){
      pL1CRlEdpchInfo->ptr_ETFCS_Information = 
	  	(L1CAPI_E_TFCS_Info *)allocMem(sizeof(L1CAPI_E_TFCS_Info),0);
      eTfcsInfoDecHdlr(msgStatus,pL1CRlEdpchInfo->ptr_ETFCS_Information);
    }
}

static void edchFddConfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_FDD_Info *pL1CEdchFddInfo)
{
    uint8_t i;
    pL1CEdchFddInfo->bit_mask = subByteVal();
    if(pL1CEdchFddInfo->bit_mask & hARQ_Pc_Ac_Sd_2ms_EDCH_present)
    {
      pL1CEdchFddInfo->hARQ_Proc_Alloc_Sched_2ms_EDCH = subByteVal();
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Maximum_Bitrate_present)
    {
      pL1CEdchFddInfo->e_DCH_Maximum_Bitrate = subLongVal();
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Processing_Overload_Level_present)
    {
      pL1CEdchFddInfo->e_DCH_Processing_Overload_Level = subByteVal();
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reference_Pwr_Offset_present)
    {
      pL1CEdchFddInfo->e_DCH_Reference_Power_Offset = subByteVal();
    }
    pL1CEdchFddInfo->e_DCH_MacDFlow_Count = subByteVal();
    pL1CEdchFddInfo->ptrE_DCH_MACdFlows_Information = 
      (L1CAPI_E_DCH_MACDFlow_Info *)allocMem(sizeof(L1CAPI_E_DCH_MACDFlow_Info) * pL1CEdchFddInfo->e_DCH_MacDFlow_Count,0);
    for(i=0;i<pL1CEdchFddInfo->e_DCH_MacDFlow_Count;i++){
      edchMacDFlowInfoProcDecHdlr(msgStatus,&pL1CEdchFddInfo->ptrE_DCH_MACdFlows_Information[i]);
	  if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		return;
    }

}

static void edchFddReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_DCH_FDD_Reconfig_Info *pL1CEdchFddInfo)
{
    uint8_t i;
	
    pL1CEdchFddInfo->bit_mask = subByteVal();
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_hARQ_Pc_Ac_Sd_2ms_EDCH_present)
    {
      pL1CEdchFddInfo->hARQ_Proc_Alloc_Sched_2ms_EDCH = subByteVal();
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Maximum_Bitrate_present)
    {
      pL1CEdchFddInfo->e_DCH_Maximum_Bitrate = subLongVal();      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Processing_Overload_Level_present)
    {
      pL1CEdchFddInfo->e_DCH_Processing_Overload_Level = subByteVal();      
    }
    if(pL1CEdchFddInfo->bit_mask & e_DCH_Reconfig_Reference_Pwr_Offset_present)
    {
      pL1CEdchFddInfo->e_DCH_Reference_Power_Offset = subByteVal();      
    }
    if(pL1CEdchFddInfo->bit_mask & macERestIndication_present)
    {
      pL1CEdchFddInfo->macERestIndication = subByteVal();      
    }

    pL1CEdchFddInfo->e_DCH_MacDFlow_Count = subByteVal();
    pL1CEdchFddInfo->ptrE_DCH_MACdFlows_Reconfig_Information = 
      (L1CAPI_E_DCH_MACDFlow_Reconfig_Info *)allocMem(sizeof(L1CAPI_E_DCH_MACDFlow_Reconfig_Info) * pL1CEdchFddInfo->e_DCH_MacDFlow_Count,0);
    for(i=0;i<pL1CEdchFddInfo->e_DCH_MacDFlow_Count;i++){
      edchMacDFlowReconfigInfoProcDecHdlr(msgStatus,&(pL1CEdchFddInfo->ptrE_DCH_MACdFlows_Reconfig_Information[i]));
	  if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		return;
    }

}

void edchExtConfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Radiolink_EDCH_Config_Ext *pL1CEdchInfo)
{
    pL1CEdchInfo->bit_mask = subByteVal();

	/*edpch info*/
    eDpchConfigInfoProcDecHdlr(msgStatus,&(pL1CEdchInfo->eDpchInfo));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    	
    /*edch fdd info*/
    edchFddConfigInfoProcDecHdlr(msgStatus,&(pL1CEdchInfo->eDchFddInfo));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
	
	/*serving edch rl info*/
    if(pL1CEdchInfo->bit_mask & rl_Setup_servingEdchRlInfo_present)
    {
      pL1CEdchInfo->ptrServingEdchRlInfo = 
        (L1CAPI_ServingEdch_Radiolink_Info *)allocMem(sizeof(L1CAPI_ServingEdch_Radiolink_Info),0);
      servingEdchRlInfoProcDecHdlr(msgStatus,pL1CEdchInfo->ptrServingEdchRlInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;	
    }	
}

void edchExtReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_Radiolink_EDCH_Reconfig_Ext *pL1CEdchInfoReconfig)
{
    pL1CEdchInfoReconfig->bit_mask = subByteVal();
	/*edpch info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdpchInfo_present)
    {
      pL1CEdchInfoReconfig->ptrEDpchInfo = 
	    (L1CAPI_Radiolink_EDpch_Reconfig_Info *)allocMem(sizeof(L1CAPI_Radiolink_EDpch_Reconfig_Info),0);
      eDpchReconfigInfoProcDecHdlr(msgStatus,pL1CEdchInfoReconfig->ptrEDpchInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }	
    /*edch fdd info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchFddInfo_present)
    {
      pL1CEdchInfoReconfig->ptrEDchFddInfo = 
        (L1CAPI_E_DCH_FDD_Info *)allocMem(sizeof(L1CAPI_E_DCH_FDD_Info),0);
      edchFddConfigInfoProcDecHdlr(msgStatus,pL1CEdchInfoReconfig->ptrEDchFddInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*edch fdd modify info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchFddModifyInfo_present)
    {
      pL1CEdchInfoReconfig->ptrEDchFddInfoModify = 
        (L1CAPI_E_DCH_FDD_Reconfig_Info *)allocMem(sizeof(L1CAPI_E_DCH_FDD_Reconfig_Info),0);          
      edchFddReconfigInfoProcDecHdlr(msgStatus,pL1CEdchInfoReconfig->ptrEDchFddInfoModify);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*edch MacD Flow Add*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchMacDFlowAdd_present)
    {
      pL1CEdchInfoReconfig->ptrEdchMadDFlowsAdd = 
        (L1CAPI_E_DCH_MACDFlow_Add_Info *)allocMem(sizeof(L1CAPI_E_DCH_MACDFlow_Add_Info),0);		  
      edchMacDFlowListProcDecHdlr(msgStatus,pL1CEdchInfoReconfig->ptrEdchMadDFlowsAdd);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*edch MacD Flow Del*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_EdchMacDFlowDel_present)
    {
      pL1CEdchInfoReconfig->ptrEdchMadDFlowsDel = 
        (L1CAPI_E_DCH_MACDFlow_Delete_Info *)allocMem(sizeof(L1CAPI_E_DCH_MACDFlow_Delete_Info),0);
      edchMacDFlowDeleteProcDecHdlr(msgStatus,pL1CEdchInfoReconfig->ptrEdchMadDFlowsDel);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }	
    /*serving edch rl info*/
    if(pL1CEdchInfoReconfig->bit_mask & rl_Reconfig_servingEdchRlInfo_present)
    {
      pL1CEdchInfoReconfig->ptrServingEdchRlInfo = 
        (L1CAPI_ServingEdch_Radiolink_Info *)allocMem(sizeof(L1CAPI_ServingEdch_Radiolink_Info),0);    
      servingEdchRlInfoProcDecHdlr(msgStatus,pL1CEdchInfoReconfig->ptrServingEdchRlInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;	
    }	
}

void edchRlInfoExtProcDecHdlr(L1CAPI_Msg_Status *msgStatus ,
                                   L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt)
{
    pL1CEdchRlInfoExt->bit_mask = subByteVal();
    if(pL1CEdchRlInfoExt->bit_mask & eDchRlInd_present){
      pL1CEdchRlInfoExt->eDchRlInd = subByteVal();
    }
    if(pL1CEdchRlInfoExt->bit_mask & rlSpecificEDchInfo_present){
      pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask = subByteVal();
      if(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask & e_AGCH_PowerOffset_present)
      {
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_AGCH_PowerOffset = subByteVal();
      }
      if(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask & e_RGCH_PowerOffset_present)
      {
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_RGCH_PowerOffset = subByteVal();
      }
      if(pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask & e_HICH_PowerOffset_present)
      {
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_HICH_PowerOffset = subByteVal();
      }
    }
	msgStatus->l1MsgResult = L1_MSG_SUCCESS; 
}
