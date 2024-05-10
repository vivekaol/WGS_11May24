/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureConvHdlr.h"

void rlCmnContextInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                         L1CAPI_RadioLink_CmnContextInfo *pL1NodeBCmnContextInfo,
                                         l1api_Nb_com_context_setup_info_t *pOpNBCmnContextInfo)
{
    pL1NodeBCmnContextInfo->rlCount = pOpNBCmnContextInfo->n_rl;
    pL1NodeBCmnContextInfo->coordTrchCount = pOpNBCmnContextInfo->n_coord;
    pL1NodeBCmnContextInfo->tgpsCount = pOpNBCmnContextInfo->n_tgps;    
}

void dlCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                 L1CAPI_DL_CodeInfo *pL1CDlCodeInfo,    
                                 l1api_dpch_dl_code_info_t *pOpDlCodeInfo)
{
    pL1CDlCodeInfo->dl_ScramblingCode = pOpDlCodeInfo->dl_scram_code;
    pL1CDlCodeInfo->dL_ChannelisationCodeNumber = pOpDlCodeInfo->chan_code;
    pL1CDlCodeInfo->TransGapPatternSequenceCodeInfo = pOpDlCodeInfo->tx_gap_pattern_sequence;
    if(pOpDlCodeInfo->tx_gap_pattern_sequence == L1API_FIELD_NOT_PRESENT){
      pL1CDlCodeInfo->TransGapPatternSequenceCodeInfo = L1CAPI_TX_GAP_NO_CODE_CHANGE;
    }
}

void rlInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                           L1CAPI_RadioLink_Info *pL1CRlInfo,
                           l1api_rl_params_t *pOpRlInfo)
{
    pL1CRlInfo->bit_mask = 0;
    pL1CRlInfo->dlCodeCount = pOpRlInfo->n_dl_codes;
    pL1CRlInfo->rL_ID = pOpRlInfo->rl_id;
    pL1CRlInfo->c_ID = pOpRlInfo->cell_id;
    pL1CRlInfo->firstRLS_indicator = (pOpRlInfo->first_rls_indicator == L1API_FIRST_RLS)?1:0;
    pL1CRlInfo->frameOffset = pOpRlInfo->frame_offset;
    pL1CRlInfo->chipOffset = pOpRlInfo->chip_offset;        
    pL1CRlInfo->propagationDelay = pOpRlInfo->propagation_delay;
    pL1CRlInfo->bit_mask |= propagationDelay_present;
    pL1CRlInfo->diversityControlField = pOpRlInfo->div_ctrl_field;
    pL1CRlInfo->bit_mask |= diversityControlField_present;
    pL1CRlInfo->initialDL_transmissionPower = pOpRlInfo->initial_power - 350;
    pL1CRlInfo->maximumDL_power = pOpRlInfo->max_tx_power - 350;
    pL1CRlInfo->minimumDL_power = pOpRlInfo->min_tx_power - 350;
    pL1CRlInfo->bit_mask |= rl_info_transmitDiverIndicator_present;
    pL1CRlInfo->transmitDiversityIndicator = pOpRlInfo->td_indicator;
    if ((pOpRlInfo->delayed_activation.activation_type == L1API_INDICATED_CFN) || 
        (pOpRlInfo->delayed_activation.activation_type == L1API_SEPARATE_MSG))
            pL1CRlInfo->bit_mask |= delayedActivation_present;
    pL1CRlInfo->delayedActivation.delayedActivationType = pOpRlInfo->delayed_activation.activation_type;
    pL1CRlInfo->delayedActivation.cfn = pOpRlInfo->delayed_activation.activation_cfn;
}

void rlReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                     L1CAPI_Radiolink_Reconfig_params *pL1CRlInfo,
                                     l1api_rl_reconfig_params_t *pOpRlInfo)
{
    pL1CRlInfo->bit_mask = 0;
    pL1CRlInfo->dlCodeCount = pOpRlInfo->n_dl_codes;
    pL1CRlInfo->rL_ID = pOpRlInfo->rl_id;
    pL1CRlInfo->bit_mask |= maxDlPower_present;
    pL1CRlInfo->maximumDL_power = pOpRlInfo->max_tx_power - 350;    
    pL1CRlInfo->bit_mask |= minDlPower_present;
    pL1CRlInfo->minimumDL_power = pOpRlInfo->min_tx_power - 350;    
    pL1CRlInfo->bit_mask |= rl_reconfig_transmitDiverIndicator_present;
    pL1CRlInfo->transmitDiversityIndicator = pOpRlInfo->td_indicator;
    if(pOpRlInfo->dpch_dl_timing_adj != 0xffff){/*CCPU set to ffff*/
      pL1CRlInfo->bit_mask |= dlDpchTimingAdj_present;
      pL1CRlInfo->dl_dpch_timing_adj = pOpRlInfo->dpch_dl_timing_adj;
    }
    if(pOpRlInfo->edch_rl_info_ext.paramPresentFlag != 0){
        pL1CRlInfo->bit_mask |= eDchRlReconfigInfoExtension_present;
    }        
}

void dchTrchProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                               L1CAPI_DCH_Info *pL1CDchInfo,    
                               l1api_dch_info_t* pOpDchInfo)
{
    pL1CDchInfo->bit_mask = 0;
    if(pOpDchInfo->uldl == L1API_BI_DIRECTIONAL_DCH)
    {
      pL1CDchInfo->bit_mask = tfsDL_present|tfsUL_present;
    }
    else if(pOpDchInfo->uldl == L1API_UPLINK_DCH_ONLY)
    {
      pL1CDchInfo->bit_mask = tfsUL_present;
    }
    else{
      msgStatus->l1MsgResult = L1_EMSG_DCHSPECIFICINFO;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pOpDchInfo->uldl;
      return;
    }
    pL1CDchInfo->dCH_ID = pOpDchInfo->dch_id;
    pL1CDchInfo->qE_Selector = pOpDchInfo->qe_selector;
}

void coordTrchProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                 L1CAPI_DCH_CoordTrchInfoListItem *pL1CCordInfo, 
                                 l1api_coord_trch_dch_t* pOpCordInfo)
{
    pL1CCordInfo->bit_mask = toAws_present|toAwe_present|payloadCRC_presenceIndicator_present|ulFpMode_present;
    pL1CCordInfo->dchCount = pOpCordInfo->n_dch;    
    pL1CCordInfo->toAWS = pOpCordInfo->toAWS;
    pL1CCordInfo->toAWE = pOpCordInfo->toAWE;
    pL1CCordInfo->payloadCRC_PresenceIndicator = pOpCordInfo->payload_crc_present;
    pL1CCordInfo->ul_FP_Mode= pOpCordInfo->ul_fp_mode;
}

void phyDlDpchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_DL_DPCH_PhyInfo *pL1CPhyDlDpchInfo,
                                      l1api_dpch_dl_params_t* pOpPhyDlDpchInfo)
{
    pL1CPhyDlDpchInfo->bit_mask = DL_DPCH_RL_Setup_tFCI_present;
       pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat = pOpPhyDlDpchInfo->slot_format;
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Setup_tFCI_present)
      pL1CPhyDlDpchInfo->tFCI_Presence = (pOpPhyDlDpchInfo->tfci_presence == L1API_TFCI_PRESENT)?1:0;    
    pL1CPhyDlDpchInfo->multiplexingPosition = pOpPhyDlDpchInfo->mux_position;
    pL1CPhyDlDpchInfo->powerOffsetInformation.pO1_ForTFCI_Bits = pOpPhyDlDpchInfo->po_tfci;
    pL1CPhyDlDpchInfo->powerOffsetInformation.pO2_ForTPC_Bits = pOpPhyDlDpchInfo->po_tpc;
    pL1CPhyDlDpchInfo->powerOffsetInformation.pO3_ForPilotBits = pOpPhyDlDpchInfo->po_pilot;
    pL1CPhyDlDpchInfo->tPC_DownlinkStepSize = pOpPhyDlDpchInfo->tpc_dl_step_size;
    pL1CPhyDlDpchInfo->limitedPowerIncrease = pOpPhyDlDpchInfo->limited_power_inc;
    pL1CPhyDlDpchInfo->innerLoopDLPCStatus = pOpPhyDlDpchInfo->inner_loop_dlpc_status;
}

void phyDlDpchReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_DL_DPCH_PhyInfo_Reconfig *pL1CPhyDlDpchInfo,
                                                l1api_dpch_dl_params_t* pOpPhyDlDpchInfo)
{
    pL1CPhyDlDpchInfo->bit_mask = DL_DPCH_RL_Reconfig_SlotFormat_present|DL_DPCH_RL_Reconfig_tFCI_present|
                                  DL_DPCH_RL_Reconfig_MuxPos_present|DL_DPCH_RL_Reconfig_LimitedPwrInc_present;
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_SlotFormat_present)
    {
         pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat = pOpPhyDlDpchInfo->slot_format;
    }
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_tFCI_present)
      pL1CPhyDlDpchInfo->tFCI_Presence = (pOpPhyDlDpchInfo->tfci_presence == L1API_TFCI_PRESENT)?1:0;

    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_MuxPos_present)
    {    
      pL1CPhyDlDpchInfo->multiplexingPosition = pOpPhyDlDpchInfo->mux_position;
    }
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Reconfig_LimitedPwrInc_present)
    {    
      pL1CPhyDlDpchInfo->limitedPowerIncrease = pOpPhyDlDpchInfo->limited_power_inc;
    }
}

void phyUlDpchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_UL_DPCH_PhyInfo *pL1CPhyUlDpchInfo,
                                      l1api_dpch_ul_params_t* pOpPhyUlDpchInfo)
{    
    pL1CPhyUlDpchInfo->bit_mask = UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present|
                                  UL_DPCH_Setup_DpcMode_present|UL_DPCH_Setup_IndEDch_present;    
    pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber = pOpPhyUlDpchInfo->scram_code_num;
    pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength = pOpPhyUlDpchInfo->scram_code_length;
    pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength = pOpPhyUlDpchInfo->min_chan_code_length;
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present){
      pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs = pOpPhyUlDpchInfo->max_n_ul_dpdch;
    }
    pL1CPhyUlDpchInfo->ul_PunctureLimit = pOpPhyUlDpchInfo->puncture_limit;
    pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat = pOpPhyUlDpchInfo->slot_format;
    pL1CPhyUlDpchInfo->ul_SIR_Target = pOpPhyUlDpchInfo->ul_sir_target;
    pL1CPhyUlDpchInfo->diversityMode = pOpPhyUlDpchInfo->diversity_mode;
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_DpcMode_present){
      pL1CPhyUlDpchInfo->dpcMode = pOpPhyUlDpchInfo->dpc_mode;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_IndEDch_present){
      pL1CPhyUlDpchInfo->ulDpdchIndEDch = pOpPhyUlDpchInfo->ul_dpch_ind_edch;
    }
}

void phyUlDpchReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_UL_DPCH_PhyInfo_Reconfig *pL1CPhyUlDpchInfo,
                                                l1api_dpch_ul_params_t* pOpPhyUlDpchInfo)
{            
    pL1CPhyUlDpchInfo->bit_mask = UL_DPCH_Reconfig_UlScramCodeInfo_present|UL_DPCH_Reconfig_MinChanCodeLen_present|
                                  UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present|UL_DPCH_Reconfig_UlPuncLimit_present|
                                  UL_DPCH_Reconfig_UlSlotFormat_present|UL_DPCH_Reconfig_UlSIR_present|
                                  UL_DPCH_Reconfig_DiversityMode_present|UL_DPCH_Reconfig_IndEDch_present;    
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlScramCodeInfo_present){    
      pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber = pOpPhyUlDpchInfo->scram_code_num;
      pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength = pOpPhyUlDpchInfo->scram_code_length;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MinChanCodeLen_present){        
      pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength = pOpPhyUlDpchInfo->min_chan_code_length;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present){
      pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs = pOpPhyUlDpchInfo->max_n_ul_dpdch;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlPuncLimit_present){
      pL1CPhyUlDpchInfo->ul_PunctureLimit = pOpPhyUlDpchInfo->puncture_limit;
    }    
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSlotFormat_present){
      pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat = pOpPhyUlDpchInfo->slot_format;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSIR_present){
      pL1CPhyUlDpchInfo->ul_SIR_Target = pOpPhyUlDpchInfo->ul_sir_target;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & L1CAPI_DIV_NOT_USE_CLOSED_LOOP_MODE2){
      pL1CPhyUlDpchInfo->diversityMode = pOpPhyUlDpchInfo->diversity_mode;
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_IndEDch_present){
      pL1CPhyUlDpchInfo->ulDpdchIndEDch = pOpPhyUlDpchInfo->ul_dpch_ind_edch;
    }    
}

void pwrBalanceInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_DL_PowerBalancing_Info *pL1CPwrBalanceInfo,
                                       l1api_dlpower_balancing_info_t* pOpPwrBalanceInfo)
{

}


void rlReconfigCmnInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo,
                                          l1api_Nb_com_context_reconfig_info_t * pOpRlReconfigCmnInfo)
{
    pL1CRlReconfigCmnInfo->rlCount = pOpRlReconfigCmnInfo->n_rl;
    pL1CRlReconfigCmnInfo->coorTrchCountAdd = pOpRlReconfigCmnInfo->n_coord_add;
    pL1CRlReconfigCmnInfo->coorTrchCountModify = pOpRlReconfigCmnInfo->n_coord_modify;
    pL1CRlReconfigCmnInfo->trchCountDelete = pOpRlReconfigCmnInfo->n_trch_del;
    pL1CRlReconfigCmnInfo->tgpsCount = pOpRlReconfigCmnInfo->n_tgps;
}

void activePatternInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Active_Pattern_Seq4 *pL1CActvPatternInfo,
                                        l1api_tgps_status_t *pOpActvPatternInfo)
{
    pL1CActvPatternInfo->tGPSID = pOpActvPatternInfo->tgps_id;
    pL1CActvPatternInfo->tGPRC = pOpActvPatternInfo->tgprc;
    pL1CActvPatternInfo->tGCFN = pOpActvPatternInfo->tg_cfn;
}

void tgpsGapInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_TxGap_SeqInfo *pL1CtgpsGapInfo,
                                  l1api_trans_gap_patt_seq_info_t *pOpTgpsGapInfo)
{
    pL1CtgpsGapInfo->tGPSID = pOpTgpsGapInfo->tgps_id;
    pL1CtgpsGapInfo->tGSN = pOpTgpsGapInfo->tg_sn;
    pL1CtgpsGapInfo->tGL1 = pOpTgpsGapInfo->tg_length1;
    pL1CtgpsGapInfo->tGL2 = pOpTgpsGapInfo->tg_length2;
    pL1CtgpsGapInfo->tGD = pOpTgpsGapInfo->tg_distance;
    pL1CtgpsGapInfo->tGSN = pOpTgpsGapInfo->tg_sn;
    pL1CtgpsGapInfo->tGPL1 = pOpTgpsGapInfo->tg_length1;
    pL1CtgpsGapInfo->uL_DL_mode = pOpTgpsGapInfo->uldl_mode;
    pL1CtgpsGapInfo->downlink_Compressed_Mode_Method = pOpTgpsGapInfo->dl_method;
    pL1CtgpsGapInfo->uplink_Compressed_Mode_Method = pOpTgpsGapInfo->ul_method;
    pL1CtgpsGapInfo->dL_FrameType = pOpTgpsGapInfo->cm_frame_type;
    pL1CtgpsGapInfo->delta_SIR1 = pOpTgpsGapInfo->d_sir1;
    pL1CtgpsGapInfo->delta_SIR_after1 = pOpTgpsGapInfo->d_sir_after1;
    pL1CtgpsGapInfo->delta_SIR2 = pOpTgpsGapInfo->d_sir2;
    pL1CtgpsGapInfo->delta_SIR_after2 = pOpTgpsGapInfo->d_sir_after2;
}

