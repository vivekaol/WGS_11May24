/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Enhanced Dedicated Channel 
   Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureEdchConvHdlr.h"


void edchRlInfoExtProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                     L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt,
                                     l1api_edch_rl_info_ext_t *pOpEdchRlInfoExt)
{
    uint16_t ppf = pOpEdchRlInfoExt->paramPresentFlag;
    uint16_t ppf2;
    pL1CEdchRlInfoExt->bit_mask =0;
    if((ppf & 1) !=0)
    {
      pL1CEdchRlInfoExt->bit_mask |= eDchRlInd_present;
      pL1CEdchRlInfoExt->eDchRlInd = pOpEdchRlInfoExt->edch_rl_ind;
    }
    ppf >>= 1;

    if ((ppf & 1) != 0 )
    {
      pL1CEdchRlInfoExt->bit_mask |= rlSpecificEDchInfo_present;
      ppf2 = pOpEdchRlInfoExt->rl_specific_edch_info.paramPresentFlag;
      pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask = 0;
      if((ppf2 & 1) != 0)
      {
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask |= e_AGCH_PowerOffset_present;
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_AGCH_PowerOffset = pOpEdchRlInfoExt->rl_specific_edch_info.eAGCH_power_offset;
      }
      ppf2 >>=1;
      if((ppf2 & 1) != 0)
      {
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask |= e_RGCH_PowerOffset_present;
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_RGCH_PowerOffset = pOpEdchRlInfoExt->rl_specific_edch_info.eRGCH_power_offset;
      }
      ppf2 >>=1;
      if((ppf2 & 1) != 0)
      {
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.bit_mask |= e_HICH_PowerOffset_present;
        pL1CEdchRlInfoExt->rlSpecificEDchInfo.e_HICH_PowerOffset = pOpEdchRlInfoExt->rl_specific_edch_info.eHICH_power_offset;
      }      
    }
    
}

void edpchConfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Radiolink_EDpch_Info *pL1CEdpchInfo,
                                        l1api_edpch_info_t *pOpEdchInfo)
{
    pL1CEdpchInfo->maxSet_E_DPDCHs = pOpEdchInfo->max_set_edpdch;
    pL1CEdpchInfo->ul_PunctureLimit = pOpEdchInfo->punct_lim;
    pL1CEdpchInfo->e_TTI = pOpEdchInfo->etti;
    pL1CEdpchInfo->e_DPCCH_PowerOFfset = pOpEdchInfo->edpcch_pwr_offset;
    pL1CEdpchInfo->e_RGCH_2_IndexStepThreshold = pOpEdchInfo->ergch2_index_step_thresh;
    pL1CEdpchInfo->e_RGCH_3_IndexStepThreshold = pOpEdchInfo->ergch3_index_step_thresh;
    pL1CEdpchInfo->hARQ_Info_for_E_DCH = pOpEdchInfo->harq_info_for_edch;    
    pL1CEdpchInfo->hSDSCH_Configured_Indicator = pOpEdchInfo->hsdsch_configured_ind;
}

void edpchReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Radiolink_EDpch_Reconfig_Info *pL1CEdpchInfo,
                                          l1api_edpch_info_re_t *pOpEdchInfo)
{
    pL1CEdpchInfo->bit_mask = 0;
    if(pOpEdchInfo->paramPresentFlag & 0x0001){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_MaxSetEdpchs_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0002){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_PuncLimit_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0004){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_ETTI_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0008){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_PwrOffset_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0010){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_Rgch2Threshold_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0020){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_Rgch3Threshold_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0040){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_HarqInfo_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0080){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_HsdschConfigInd_present;
    }
    if(pOpEdchInfo->paramPresentFlag & 0x0100){
      pL1CEdpchInfo->bit_mask |= Edpch_Reconfig_ETfcsInfo_present;
    }

    pL1CEdpchInfo->maxSet_E_DPDCHs = pOpEdchInfo->max_set_edpdch;
    pL1CEdpchInfo->ul_PunctureLimit = pOpEdchInfo->punct_lim;
    if(pOpEdchInfo->eTti == L1API_ETTI_2MS)
        pL1CEdpchInfo->e_TTI = L1CAPI_E_TTI_2MS;
    else
        pL1CEdpchInfo->e_TTI = L1CAPI_E_TTI_10MS;
    pL1CEdpchInfo->e_DPCCH_PowerOFfset = pOpEdchInfo->edpcch_pwr_offset;
    pL1CEdpchInfo->e_RGCH_2_IndexStepThreshold = pOpEdchInfo->ergch2_index_step_thresh;
    pL1CEdpchInfo->e_RGCH_3_IndexStepThreshold = pOpEdchInfo->ergch3_index_step_thresh;
    pL1CEdpchInfo->hARQ_Info_for_E_DCH = pOpEdchInfo->harq_info_for_edch;    
    pL1CEdpchInfo->hSDSCH_Configured_Indicator = pOpEdchInfo->hs_dsch_configured_ind;
}

void edchFddConfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_E_DCH_FDD_Info *pL1CEdchFddInfo,
                                           l1api_edch_fdd_info_t *pOpEdchFddInfo)
{
    uint16_t ppf = pOpEdchFddInfo->paramPresentFlag;
    pL1CEdchFddInfo->bit_mask = 0;
    
    if((ppf & 1) != 0 )
    {
      pL1CEdchFddInfo->bit_mask |= hARQ_Pc_Ac_Sd_2ms_EDCH_present;
      pL1CEdchFddInfo->hARQ_Proc_Alloc_Sched_2ms_EDCH = pOpEdchFddInfo->harq_proc_alloc_2ms_sched_tx_grant;
    }
    ppf >>= 1;
    
    if((ppf & 1) != 0 )
    {
      pL1CEdchFddInfo->bit_mask |=     e_DCH_Maximum_Bitrate_present;
      pL1CEdchFddInfo->e_DCH_Maximum_Bitrate = pOpEdchFddInfo->edch_max_bit_rate;
    }
    ppf >>= 1;
    
    if((ppf & 1) != 0)
    {
      pL1CEdchFddInfo->bit_mask |=  e_DCH_Reference_Pwr_Offset_present;
      pL1CEdchFddInfo->e_DCH_Reference_Power_Offset = pOpEdchFddInfo->edch_ref_pwr_offset;
    }
    ppf >>= 1;

    pL1CEdchFddInfo->e_DCH_MacDFlow_Count = pOpEdchFddInfo->edch_macd_flow_count;
}

void edchFddReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_E_DCH_FDD_Reconfig_Info *pL1CEdchFddInfo,
                                             l1api_edch_fdd_info_re_t *pOpEdchFddInfo)
{
    uint16_t ppf = pOpEdchFddInfo->paramPresentFlag;
    pL1CEdchFddInfo->bit_mask = 0;
    
    if((ppf & 1) != 0 )
    {
      pL1CEdchFddInfo->bit_mask |= e_DCH_Reconfig_hARQ_Pc_Ac_Sd_2ms_EDCH_present;
      pL1CEdchFddInfo->hARQ_Proc_Alloc_Sched_2ms_EDCH = pOpEdchFddInfo->harq_pro_calloc_2ms_scheduled_tx_grant;
    }
    ppf >>= 1;
    
    if((ppf & 1) != 0 )
    {
      pL1CEdchFddInfo->bit_mask |=     e_DCH_Reconfig_Maximum_Bitrate_present;
      pL1CEdchFddInfo->e_DCH_Maximum_Bitrate = pOpEdchFddInfo->edch_max_bit_rate;
    }
    ppf >>= 1;
    
    if((ppf & 1) != 0)
    {
      pL1CEdchFddInfo->bit_mask |=  e_DCH_Reconfig_Reference_Pwr_Offset_present;
      pL1CEdchFddInfo->e_DCH_Reference_Power_Offset = pOpEdchFddInfo->edch_ref_power_offset;
    }
    ppf >>= 1;

    pL1CEdchFddInfo->e_DCH_MacDFlow_Count = pOpEdchFddInfo->edch_macd_flow_count;
}

void edchMacDFlowInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_E_DCH_MACDFlow_Info *pL1CEdchMacDFlowInfo,
                                          l1api_edch_macd_flows_info_t * pOpEdchMadFlowInfo)
{
    uint16_t ppf = pOpEdchMadFlowInfo->paramPresentFlag;
    pL1CEdchMacDFlowInfo->bit_mask = 0;
    if((ppf>>4 & 1) != 0){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_MACdFlow_Multiplexing_present;        
    }
    if((ppf>>6 & 1) != 0){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_MACdFlow_bundlingModeIndicator_present;        
    }
    if((ppf>>8 & 1) != 0){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_MACdFlow_eDchNonSchedGrantInfo_present;        
    }
    pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID = pOpEdchMadFlowInfo->edch_macd_flows_id;
    pL1CEdchMacDFlowInfo->payloadCRC_PresenceIndicator = pOpEdchMadFlowInfo->payload_crc_pres;
    pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH = pOpEdchMadFlowInfo->max_num_re_tx_edch;
    pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset = pOpEdchMadFlowInfo->edch_harq_power_offset;
    pL1CEdchMacDFlowInfo->eDCH_MACdFlow_Multiplexing_List = pOpEdchMadFlowInfo->edch_macd_flow_mux_list;
    pL1CEdchMacDFlowInfo->eDCH_Grant_Type = pOpEdchMadFlowInfo->edch_grant_type;
    pL1CEdchMacDFlowInfo->bundlingModeIndicator = pOpEdchMadFlowInfo->bundling_mode_ind;
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannels = pOpEdchMadFlowInfo->edch_logical_chan_info_count;

}

void edchMacDFlowReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pL1CEdchMacDFlowInfo,
                                                     l1api_edch_macd_flows_info_re_t * pOpEdchMadFlowInfo)
{
    uint16_t ppf = pOpEdchMadFlowInfo->paramPresentFlag;

    pL1CEdchMacDFlowInfo->bit_mask = 0;
    if(ppf & 0x0002){
      pL1CEdchMacDFlowInfo->bit_mask |= maxNrOfRetransmission_E_DCH_present;        
    }
    if(ppf & 0x0004){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_HarqPowerOffset_present;        
    }
    if(ppf & 0x0008){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_MACdFlow_Reconfig_Multiplexing_present;        
    }
    if(ppf & 0x0010){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_GrantType_present;        
    }
    if(ppf & 0x0020){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_MACdFlow_Reconfig_bundlingModeIndicator_present;        
    }
    if(ppf & 0x0200){
      pL1CEdchMacDFlowInfo->bit_mask |= eDCH_MACdFlow_Reconfig_eDchNonSchedGrantInfo_present;        
    }
    pL1CEdchMacDFlowInfo->e_DCH_MACdFlow_ID = pOpEdchMadFlowInfo->edch_macd_flow_id;
    pL1CEdchMacDFlowInfo->maxNrOfRetransmission_E_DCH = pOpEdchMadFlowInfo->max_num_re_tx_edch;
    pL1CEdchMacDFlowInfo->eDCH_HarqPowerOffset = pOpEdchMadFlowInfo->edch_harq_pwr_offset;
    pL1CEdchMacDFlowInfo->eDCH_MACdFlow_Multiplexing_List = pOpEdchMadFlowInfo->edch_macd_flow_mux_list;
    pL1CEdchMacDFlowInfo->eDCH_Grant_Type = pOpEdchMadFlowInfo->edch_grant_Type;
    pL1CEdchMacDFlowInfo->bundlingModeIndicator = pOpEdchMadFlowInfo->bundling_mode_ind;
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsAdd = pOpEdchMadFlowInfo->edch_logical_chan_info_add_count;
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsMod = pOpEdchMadFlowInfo->edch_logical_chan_info_mod_count;
    pL1CEdchMacDFlowInfo->eDchNrOfLogicalChannelsDel = pOpEdchMadFlowInfo->edch_logical_chan_info_del_count;

}

void edchNonSchedGrantInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                 L1CAPI_E_DCH_NonScheduled_TxGrantItems *pL1CEDchNonSchedGrantInfo,
                                                 l1api_edch_non_sched_grant_info_t *pOpEdchNonSchedGrantInfo)
{
    pL1CEDchNonSchedGrantInfo->bit_mask = ((pOpEdchNonSchedGrantInfo->paramPresentFlag>>1) & 1)?hARQ_Ps_An_NnSchd_2ms_present:0;
    pL1CEDchNonSchedGrantInfo->maxBits_MACe_PDU_non_scheduled = pOpEdchNonSchedGrantInfo->max_bits_per_mac_epdu;
    pL1CEDchNonSchedGrantInfo->hARQ_Prcss_Allctn_NonSched_2ms = pOpEdchNonSchedGrantInfo->harq_proc_alloc_2ms_non_scheduled_tx_grant;    
}


void edchLogicChInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo,
                                        l1api_edch_logical_chan_info_t *pOpEdchLogicChInfo)
{
    pL1CEdchLogicChInfo->bit_mask = 0;
    if((pOpEdchLogicChInfo->paramPresentFlag & 0x01) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= schedulingPriorityIndicator_present;
    }
    if((pOpEdchLogicChInfo->paramPresentFlag & 0x02) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= schedulingInformation_present;
    }
    if((pOpEdchLogicChInfo->paramPresentFlag & 0x04) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= mACesGuaranteedBitRate_present;
    }
    if((pOpEdchLogicChInfo->paramPresentFlag& 0x08) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= eDCH_DDI_Value_present;
    }
    pL1CEdchLogicChInfo->logicalChannelId = pOpEdchLogicChInfo->logical_chan_id;
    pL1CEdchLogicChInfo->schedulingPriorityIndicator = pOpEdchLogicChInfo->sched_pri_ind;
    pL1CEdchLogicChInfo->schedulingInformation = pOpEdchLogicChInfo->sched_info;
    pL1CEdchLogicChInfo->mACesGuaranteedBitRate = pOpEdchLogicChInfo->mac_es_guaranteed_bit_rate;
    pL1CEdchLogicChInfo->e_DCH_DDI_Value = pOpEdchLogicChInfo->edch_ddi_val;
    pL1CEdchLogicChInfo->macD_PDU_Size_Count = pOpEdchLogicChInfo->macd_pdu_size_count;
    
}

void edchLogicChReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo,
                                                  l1api_edch_logical_chan_info_re_t *pOpEdchLogicChInfo)
{
    pL1CEdchLogicChInfo->bit_mask = 0;
    if((pOpEdchLogicChInfo->paramPresentFlag & 0x01) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= schedulingPriorityIndicator_present;
    }
    if((pOpEdchLogicChInfo->paramPresentFlag & 0x02) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= schedulingInformation_present;
    }
    if((pOpEdchLogicChInfo->paramPresentFlag & 0x04) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= mACesGuaranteedBitRate_present;
    }
    if((pOpEdchLogicChInfo->paramPresentFlag& 0x08) != 0)
    {
      pL1CEdchLogicChInfo->bit_mask |= eDCH_DDI_Value_present;
    }
    pL1CEdchLogicChInfo->logicalChannelId = pOpEdchLogicChInfo->logical_chan_id;
    pL1CEdchLogicChInfo->schedulingPriorityIndicator = pOpEdchLogicChInfo->sched_pri_ind;
    pL1CEdchLogicChInfo->schedulingInformation = pOpEdchLogicChInfo->sched_info;
    pL1CEdchLogicChInfo->mACesGuaranteedBitRate = pOpEdchLogicChInfo->mac_es_guaranteed_bit_rate;
    pL1CEdchLogicChInfo->e_DCH_DDI_Value = pOpEdchLogicChInfo->edch_ddi_val;
    pL1CEdchLogicChInfo->macD_PDU_Size_Count = pOpEdchLogicChInfo->macd_pdu_size_count;
    
}

void servingEdchRlInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_ServingEdch_Radiolink_Info * pL1CServingEdchRlInfo,
                                          l1api_serving_edch_rl_t * pOpServingEdchRlInfo)
{
    pL1CServingEdchRlInfo->bit_mask = (pOpServingEdchRlInfo->paramPresentFlag & 1)?serving_edch_rl_id_present:0;
    pL1CServingEdchRlInfo->serving_edch_rl_location = pOpServingEdchRlInfo->serving_edch_rl_location;
    pL1CServingEdchRlInfo->serving_edch_rl_id = pOpServingEdchRlInfo->serving_edch_rl_id;
}
