/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_responseProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Response Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_responseProcedureConvHdlr.h"

void msgStatusConvHdlr(l1api_msg_status_t *pOpMsgStatus,L1CAPI_Msg_Status *pL1CMsgStatus)
{
    pOpMsgStatus->l1MsgStatusMsgResult = pL1CMsgStatus->l1MsgResult;
    if(pOpMsgStatus->l1MsgStatusMsgResult != SA_L1API_NO_ERROR){
      pOpMsgStatus->l1MsgStatusAdditional0 = pL1CMsgStatus->additionalInfo0;
      pOpMsgStatus->l1MsgStatusAdditional1 = pL1CMsgStatus->additionalInfo1;
    }
}

void cordTrchInfoRspConvHdlr(l1api_coord_trch_resp_t *pOpcordTrchInfoRsp,L1CAPI_CoordTrchRespItem *pL1CCordTrchInfo)
{
    pOpcordTrchInfoRsp->dch_id = pL1CCordTrchInfo->dchId;
    pOpcordTrchInfoRsp->binding_id = pL1CCordTrchInfo->binding_id;
}

void radiolinkInfoRspConvHdlr(l1api_rl_info_resp_t *pOpRlInfoRsp,L1CAPI_Radiolink_Info_Resp * pL1CRlInfoRsp)
{
    pOpRlInfoRsp->n_coord_trch = pL1CRlInfoRsp->coordTrchCount;
    pOpRlInfoRsp->rl_id = pL1CRlInfoRsp->rL_ID;
    pOpRlInfoRsp->rl_set_id = pL1CRlInfoRsp->rlSetId;
    pOpRlInfoRsp->reference_rl_id = pL1CRlInfoRsp->referenceRlId;
}

void edchFddCtrlChInfoConvHdlr(l1api_edch_fdd_ctrl_chan_info_t *pOpedchFddCtrlChInfo,L1CAPI_Edch_Fdd_Ctrl_Channel_Info *pCtrlChInfo)
{
    pOpedchFddCtrlChInfo->paramPresentFlag = 0;
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eAgchRgchHichScramCode_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<0);
      pOpedchFddCtrlChInfo->eagch_rgch_hich_scram_code = pCtrlChInfo->eAgchRgchHichScramCode;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eAgchChanCode_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<1);
      pOpedchFddCtrlChInfo->eagch_chan_code = pCtrlChInfo->eAgchChanCode;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_primaryErnti_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<2);
      pOpedchFddCtrlChInfo->primary_ernti = pCtrlChInfo->primaryErnti;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_secondaryErnti_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<3);
      pOpedchFddCtrlChInfo->secondary_ernti = pCtrlChInfo->secondaryErnti;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchHichChanCode_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<4);
      pOpedchFddCtrlChInfo->ergch_hich_chan_code = pCtrlChInfo->eRgchHichChanCode;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchSignatureSeq_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<5);
      pOpedchFddCtrlChInfo->ergch_signature_seq = pCtrlChInfo->eRgchSignatureSeq;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eHichSignatureSeq_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<6);
      pOpedchFddCtrlChInfo->ehich_signature_seq = pCtrlChInfo->eHichSignatureSeq;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_servingGrantVal_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<7);
      pOpedchFddCtrlChInfo->serving_grant_val = pCtrlChInfo->servingGrantVal;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_priSecGrantSelector_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<8);
      pOpedchFddCtrlChInfo->pri_sec_grant_selector = pCtrlChInfo->priSecGrantSelector;
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchReleaseInd_present)
    {
      pOpedchFddCtrlChInfo->paramPresentFlag |= (1<<1);
      pOpedchFddCtrlChInfo->ergch_release_ind = pCtrlChInfo->eRgchReleaseInd;
    }
}

void edchFddInfoRspConvHdlr(l1api_edch_fdd_info_resp_t *pOpEdchFddInfoRsp,L1CAPI_Edch_Fdd_Info_Resp * pEdchFddInfoRsp)
{
    pOpEdchFddInfoRsp->paramPresentFlag = 0;
    
    if(pEdchFddInfoRsp->bit_mask & edchRlSetId_present){
      pOpEdchFddInfoRsp->paramPresentFlag |= (1<<0);
      pOpEdchFddInfoRsp->edch_rl_set_id = pEdchFddInfoRsp->edchRlSetId;
    }
    if(pEdchFddInfoRsp->bit_mask & edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present){
      pOpEdchFddInfoRsp->paramPresentFlag |= (1<<2);
      pOpEdchFddInfoRsp->harq_proc_alloc_2ms_sched_tx_grant = pEdchFddInfoRsp->harqProcAlloc2ms_SchedTxGrant;
    }
    if(pEdchFddInfoRsp->bit_mask & edchFddCtrlChanInfo_present){
      pOpEdchFddInfoRsp->paramPresentFlag |= (1<<3);
    }
    pOpEdchFddInfoRsp->mac_d_flow_count = pEdchFddInfoRsp->mAcdFlowCount;
}

void edchMacDFlowInfoRspConvHdlr(l1api_edch_mac_d_flow_info_resp_t * pOpEdchMacDFlowInfo,L1CAPI_Edch_MacD_Flow_Info_resp * pEdchMacDFlowInfo)
{
    pOpEdchMacDFlowInfo->paramPresentFlag = 0;
    pOpEdchMacDFlowInfo->mac_d_flow_id = pEdchMacDFlowInfo->e_DCH_MACdFlow_ID;
    pOpEdchMacDFlowInfo->binding_id = pEdchMacDFlowInfo->binding_id;
    if(pEdchMacDFlowInfo->bit_mask & edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present){
      pOpEdchMacDFlowInfo->paramPresentFlag |= (1<<2);
      pOpEdchMacDFlowInfo->harq_proc_alloc_2ms_non_sched_tx_grant = pEdchMacDFlowInfo->harqProcAlloc2ms_SchedTxGrant;
    }
}

void hsMacDFlowInfoRspConvHdlr(l1api_macD_flow_info_t * pOpMacDFlowInfoRsp,L1CAPI_MacDFlow_Info_Resp *pHsMacDFlowInfo)
{
    pOpMacDFlowInfoRsp->macD_flow_id = pHsMacDFlowInfo->macDFlowId;
    pOpMacDFlowInfoRsp->binding_id = pHsMacDFlowInfo->bindingId;
}

void hsDschInfoRspConvHdlr(l1api_hsdsch_info_resp_t * pOpHsdschRspInfo,L1CAPI_HSDSCH_Info_Resp * pHsdschInfoRsp)
{
    pOpHsdschRspInfo->harq_mem_choice = pHsdschInfoRsp->harqMemChoice;
    pOpHsdschRspInfo->n_macD_flow = pHsdschInfoRsp->macDFlowCount;
    pOpHsdschRspInfo->n_hsscch_codes = pHsdschInfoRsp->hsscchCodeCount;
}

void radiolinkFailureIndicationConvHdlr(l1api_rl_failure_ind_t *pOpRLFailureInd, L1CAPI_Radiolink_Failure_Ind * pRlFailureInd)
{
    uint8_t rlCount;
    //WARNING: Need to fix reporting of 'nodeB_context'
    pOpRLFailureInd->nodeB_context = 0;
    pOpRLFailureInd->rl_fail_report_obj = L1API_RL_FAIL_RL;

    pOpRLFailureInd->rl_failure_info.n_rl = pRlFailureInd->rlCount;
    for (rlCount=0; rlCount<pRlFailureInd->rlCount; rlCount++)
    {
        pOpRLFailureInd->rl_failure_info.rl_id[rlCount] = pRlFailureInd->pRlFailInf[rlCount].rL_ID;

        if (pRlFailureInd->pRlFailInf[rlCount].cause == L1CAPI_RADIOLINK_FAILURE_SYNC_FAILURE)
        {
            pOpRLFailureInd->rl_failure_info.failure_cause[rlCount] = L1API_RADIOLINK_FAILURE_SYNC_FAILURE;
        }
    }

    pOpRLFailureInd->rls_failure_info.n_rls = pRlFailureInd->rlsCount;
    for (rlCount=0; rlCount<pRlFailureInd->rlsCount; rlCount++)
    {
        pOpRLFailureInd->rls_failure_info.rl_set_id[rlCount] = pRlFailureInd->pRlsFailInf[rlCount].rLS_ID;

        if (pRlFailureInd->pRlsFailInf[rlCount].cause == L1CAPI_RADIOLINK_FAILURE_SYNC_FAILURE)
        {
            pOpRLFailureInd->rls_failure_info.failure_cause[rlCount] = L1API_RADIOLINK_FAILURE_SYNC_FAILURE;
        }
    }
}

void radiolinkRestoreIndicationConvHdlr(l1api_rl_restore_ind_t *pOpRLRestoreInd, L1CAPI_Radiolink_Restore_Ind * pRlRestoreInd)
{
    uint8_t rlCount;
    //WARNING: Need to fix reporting of 'nodeB_context'
    pOpRLRestoreInd->nodeB_context = 0;
    pOpRLRestoreInd->rl_fail_report_obj = L1API_RL_FAIL_RL;
    
    pOpRLRestoreInd->rl_restore_info.n_rl = pRlRestoreInd->rlCount;
    for (rlCount=0; rlCount<pRlRestoreInd->rlCount; rlCount++)
    {
        pOpRLRestoreInd->rl_restore_info.rl_id[rlCount] = pRlRestoreInd->pRl_ID[rlCount];
    }

    pOpRLRestoreInd->rls_restore_info.n_rls = pRlRestoreInd->rlsCount;
    for (rlCount=0; rlCount<pRlRestoreInd->rlsCount; rlCount++)
    {
        pOpRLRestoreInd->rls_restore_info.rl_set_id[rlCount] = pRlRestoreInd->pRls_ID[rlCount];
    }
}
