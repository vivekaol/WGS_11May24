/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureDecHdlr.c

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

#include "L1C_radiolinkProcedureDecHdlr.h"
#include "L1C_radiolinkProcedureHsdschDecHdlr.h"
#include "L1C_radiolinkProcedureEdchDecHdlr.h"
#include "L1C_cctrchDecHdlr.h"
#include "L1C_tfsDecHdlr.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"

static __inline__ void rlCmnContextInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus ,
                                              L1CAPI_RadioLink_CmnContextInfo *pL1CNodeBCmnContextInfo)
{
    pL1CNodeBCmnContextInfo->rlCount = subByteVal();
    pL1CNodeBCmnContextInfo->coordTrchCount = subByteVal();
    pL1CNodeBCmnContextInfo->tgpsCount = subByteVal();
}

static __inline__ void dlCodeInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus ,
                                       L1CAPI_DL_CodeInfo *pL1CDlCodeInfo)
{
    pL1CDlCodeInfo->dl_ScramblingCode = subByteVal();
    pL1CDlCodeInfo->dL_ChannelisationCodeNumber = subWordVal();
    pL1CDlCodeInfo->TransGapPatternSequenceCodeInfo = subByteVal();
}

static __inline__ void rlInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus ,
                                         L1CAPI_RadioLink_Info *pL1CRlInfo)
{
    uint8_t i;
    pL1CRlInfo->bit_mask = subByteVal();
    pL1CRlInfo->dlCodeCount = subByteVal();
    pL1CRlInfo->rL_ID = subByteVal();
    pL1CRlInfo->c_ID = subWordVal();
    pL1CRlInfo->firstRLS_indicator = subByteVal();
    pL1CRlInfo->frameOffset = subByteVal();
    pL1CRlInfo->chipOffset = subWordVal();
    if(pL1CRlInfo->bit_mask & propagationDelay_present){
      pL1CRlInfo->propagationDelay = subWordVal();
    }
    if(pL1CRlInfo->bit_mask & diversityControlField_present){
      pL1CRlInfo->diversityControlField = subByteVal();
    }
    pL1CRlInfo->initialDL_transmissionPower = subWordVal();
    pL1CRlInfo->maximumDL_power = subWordVal();
    pL1CRlInfo->minimumDL_power = subWordVal();
    if(pL1CRlInfo->bit_mask & rl_info_transmitDiverIndicator_present){
      pL1CRlInfo->transmitDiversityIndicator = subByteVal();
    }
    pL1CRlInfo->ptrDlCodeInfo = 
      (L1CAPI_DL_CodeInfo *)allocMem(sizeof(L1CAPI_DL_CodeInfo) * pL1CRlInfo->dlCodeCount,0);
    for(i=0;i<pL1CRlInfo->dlCodeCount;i++)
    {
      dlCodeInfoProcDecHdlr(msgStatus,&(pL1CRlInfo->ptrDlCodeInfo[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CRlInfo->bit_mask & delayedActivation_present){
      pL1CRlInfo->delayedActivation.delayedActivationType = subByteVal();
      if(pL1CRlInfo->delayedActivation.delayedActivationType == cfn_indication)
        pL1CRlInfo->delayedActivation.cfn = subByteVal();
    }
    if(pL1CRlInfo->bit_mask & eDchRlInfoExtension_present){
      pL1CRlInfo->ptrEDchRlInfoExtension = 
        (L1CAPI_EDCH_RL_InfoExtension *)allocMem(sizeof(L1CAPI_EDCH_RL_InfoExtension),0);
      edchRlInfoExtProcDecHdlr(msgStatus,pL1CRlInfo->ptrEDchRlInfoExtension);
    }
    
}


static __inline__ void rlReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus ,
                                          L1CAPI_Radiolink_Reconfig_params *pL1CRlInfo)
{
    uint8_t i;
    pL1CRlInfo->bit_mask = subByteVal();
    pL1CRlInfo->dlCodeCount = subByteVal();
    pL1CRlInfo->rL_ID = subByteVal();
    if(pL1CRlInfo->bit_mask & maxDlPower_present)
    {
      pL1CRlInfo->maximumDL_power = subWordVal();
    }
    if(pL1CRlInfo->bit_mask & minDlPower_present)
    {
      pL1CRlInfo->minimumDL_power = subWordVal();
    }
    if(pL1CRlInfo->bit_mask & dlRefPower_present){
      pL1CRlInfo->dL_reference_power = subWordVal();
    }
    if(pL1CRlInfo->bit_mask & rl_reconfig_transmitDiverIndicator_present){
      pL1CRlInfo->transmitDiversityIndicator = subByteVal();
    }
    if(pL1CRlInfo->bit_mask & dlDpchTimingAdj_present){
      pL1CRlInfo->transmitDiversityIndicator = subByteVal();
    }
    pL1CRlInfo->ptrDlCodeInfo = 
      (L1CAPI_DL_CodeInfo *)allocMem(sizeof(L1CAPI_DL_CodeInfo) * pL1CRlInfo->dlCodeCount,0);
    for(i=0;i<pL1CRlInfo->dlCodeCount;i++)
    {
      dlCodeInfoProcDecHdlr(msgStatus,&(pL1CRlInfo->ptrDlCodeInfo[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CRlInfo->bit_mask & eDchRlReconfigInfoExtension_present){
      pL1CRlInfo->ptrEDchRlInfoExtension = 
        (L1CAPI_EDCH_RL_InfoExtension *)allocMem(sizeof(L1CAPI_EDCH_RL_InfoExtension),0);
      edchRlInfoExtProcDecHdlr(msgStatus,pL1CRlInfo->ptrEDchRlInfoExtension);
    }
    
}

static __inline__ void dchTrchProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_DCH_Info *pL1CDchInfo)
{    
    pL1CDchInfo->bit_mask = subByteVal();
    pL1CDchInfo->dCH_ID = subByteVal();
    pL1CDchInfo->qE_Selector = subByteVal();
    if(pL1CDchInfo->bit_mask & tfsDL_present)
    {
      pL1CDchInfo->ptrTfsDL = 
        (L1CAPI_TransportFormatSet *)allocMem(sizeof(L1CAPI_TransportFormatSet),0);
      tfsDecHdlr(msgStatus,pL1CDchInfo->ptrTfsDL);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CDchInfo->bit_mask & tfsUL_present)
    {
      pL1CDchInfo->ptrTfsUL = 
        (L1CAPI_TransportFormatSet *)allocMem(sizeof(L1CAPI_TransportFormatSet),0);
      tfsDecHdlr(msgStatus,pL1CDchInfo->ptrTfsUL);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }

}

static void coordTrchProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_DCH_CoordTrchInfoListItem *pL1CCordInfo)
{
    uint8_t i;
    pL1CCordInfo->bit_mask = subByteVal();
    pL1CCordInfo->dchCount = subByteVal();
    if(pL1CCordInfo->bit_mask & toAws_present){
      pL1CCordInfo->toAWS = subWordVal();
    }
    if(pL1CCordInfo->bit_mask & toAwe_present){
      pL1CCordInfo->toAWE = subWordVal();
    }
    if(pL1CCordInfo->bit_mask & payloadCRC_presenceIndicator_present){
      pL1CCordInfo->payloadCRC_PresenceIndicator = subByteVal();
    }
    if(pL1CCordInfo->bit_mask & ulFpMode_present){
      pL1CCordInfo->ul_FP_Mode = subByteVal();
    }
    pL1CCordInfo->ptrDCHSpecificInfo = 
      (L1CAPI_DCH_Info *)allocMem(sizeof(L1CAPI_DCH_Info) * pL1CCordInfo->dchCount,0);
    for(i=0;i<pL1CCordInfo->dchCount;i++)
    {
      dchTrchProcDecHdlr(msgStatus,&(pL1CCordInfo->ptrDCHSpecificInfo[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }

}

static __inline__ void phyDlDpchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_DL_DPCH_PhyInfo *pL1CPhyDlDpchInfo)
{
    pL1CPhyDlDpchInfo->bit_mask = subByteVal();
    pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat = subByteVal();
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Setup_tFCI_present)
      pL1CPhyDlDpchInfo->tFCI_Presence = subByteVal();
    pL1CPhyDlDpchInfo->multiplexingPosition = subByteVal();
    pL1CPhyDlDpchInfo->powerOffsetInformation.pO1_ForTFCI_Bits = subByteVal();
    pL1CPhyDlDpchInfo->powerOffsetInformation.pO2_ForTPC_Bits = subByteVal();
    pL1CPhyDlDpchInfo->powerOffsetInformation.pO3_ForPilotBits = subByteVal();
    pL1CPhyDlDpchInfo->tPC_DownlinkStepSize = subByteVal();
    pL1CPhyDlDpchInfo->limitedPowerIncrease = subByteVal();
    pL1CPhyDlDpchInfo->innerLoopDLPCStatus = subByteVal();    
}

static __inline__ void phyDlDpchReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_DL_DPCH_PhyInfo_Reconfig *pL1CPhyDlDpchInfoReconfig)
{
    pL1CPhyDlDpchInfoReconfig->bit_mask = subByteVal();
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_SlotFormat_present)
      pL1CPhyDlDpchInfoReconfig->dl_DPCH_SlotFormat = subByteVal();
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_tFCI_present)
      pL1CPhyDlDpchInfoReconfig->tFCI_Presence = subByteVal();
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_MuxPos_present)
      pL1CPhyDlDpchInfoReconfig->multiplexingPosition = subByteVal();
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_LimitedPwrInc_present)
      pL1CPhyDlDpchInfoReconfig->limitedPowerIncrease = subByteVal();
}

static __inline__ void phyUlDpchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_UL_DPCH_PhyInfo *pL1CPhyUlDpchInfo)
{    
    pL1CPhyUlDpchInfo->bit_mask = subByteVal();
    pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber = subLongVal();
    pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength = subByteVal();
    pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present)
      pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs = subByteVal();
    pL1CPhyUlDpchInfo->ul_PunctureLimit = subByteVal();
    pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat = subByteVal();
    pL1CPhyUlDpchInfo->ul_SIR_Target = subWordVal();
    pL1CPhyUlDpchInfo->diversityMode = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_DpcMode_present)
      pL1CPhyUlDpchInfo->dpcMode = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_IndEDch_present)
      pL1CPhyUlDpchInfo->ulDpdchIndEDch = subByteVal();
}

static __inline__ void phyUlDpchReconfigInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_UL_DPCH_PhyInfo_Reconfig *pL1CPhyUlDpchInfo)
{    
    pL1CPhyUlDpchInfo->bit_mask = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlScramCodeInfo_present){
      pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber = subLongVal();
      pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength = subByteVal();
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MinChanCodeLen_present)
      pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present)
      pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlPuncLimit_present)   
      pL1CPhyUlDpchInfo->ul_PunctureLimit = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSlotFormat_present)   
      pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSIR_present)   
      pL1CPhyUlDpchInfo->ul_SIR_Target = subWordVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_DiversityMode_present)       
      pL1CPhyUlDpchInfo->diversityMode = subByteVal();
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_IndEDch_present)
      pL1CPhyUlDpchInfo->ulDpdchIndEDch = subByteVal();
}

static __inline__ void pwrBalanceInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                            L1CAPI_DL_PowerBalancing_Info *pL1CPwrBalanceInfo)
{
    pL1CPwrBalanceInfo->bit_mask = 0;
}

static __inline__ void rlReconfigCmnInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo)
{
    pL1CRlReconfigCmnInfo->rlCount = subByteVal();
    pL1CRlReconfigCmnInfo->coorTrchCountAdd = subByteVal();
    pL1CRlReconfigCmnInfo->coorTrchCountModify = subByteVal();
    pL1CRlReconfigCmnInfo->trchCountDelete = subByteVal();
    pL1CRlReconfigCmnInfo->tgpsCount = subByteVal();
}

static void tgpsGapInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_TxGap_SeqInfo *pL1CtgpsGapInfo)
{
    pL1CtgpsGapInfo->bit_mask = subByteVal();
    pL1CtgpsGapInfo->tGPSID = subByteVal();
    pL1CtgpsGapInfo->tGSN = subByteVal();
    pL1CtgpsGapInfo->tGL1 = subByteVal();
    if(pL1CtgpsGapInfo->bit_mask & tGL2_present){    
      pL1CtgpsGapInfo->tGL2 = subByteVal();
    }
    pL1CtgpsGapInfo->tGD = subWordVal();
    pL1CtgpsGapInfo->tGPL1 = subByteVal();
    pL1CtgpsGapInfo->uL_DL_mode = subByteVal();
    if(pL1CtgpsGapInfo->bit_mask & downlink_Compressed_Mode_Method_present){
      pL1CtgpsGapInfo->downlink_Compressed_Mode_Method = subByteVal();
    }
    if(pL1CtgpsGapInfo->bit_mask & uplink_Compressed_Mode_Method_present){
      pL1CtgpsGapInfo->uplink_Compressed_Mode_Method = subByteVal();
    }
    pL1CtgpsGapInfo->dL_FrameType = subByteVal();
    pL1CtgpsGapInfo->delta_SIR1 = subByteVal();
    pL1CtgpsGapInfo->delta_SIR_after1 = subByteVal();
    if(pL1CtgpsGapInfo->bit_mask & delta_SIR2_present){
      pL1CtgpsGapInfo->delta_SIR2 = subByteVal();
    }
    if(pL1CtgpsGapInfo->bit_mask & delta_SIR_after2_present){
      pL1CtgpsGapInfo->delta_SIR_after2 = subByteVal();
    }
}

/*********************main interface of radio link procedure ***************************/
void radiolinkSetupRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t i;
    L1CAPI_Radiolink_Setup_Request *pL1CRLSetupReq = 
      (L1CAPI_Radiolink_Setup_Request *)allocMem(sizeof(L1CAPI_Radiolink_Setup_Request),0);
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    /*bit_mask*/
    pL1CRLSetupReq->bit_mask = subByteVal();
    /*rl common context*/
    rlCmnContextInfoProcDecHdlr(msgStatus,&pL1CRLSetupReq->comContextInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*rl info*/
    pL1CRLSetupReq->pRlInfo = 
      (L1CAPI_RadioLink_Info *)allocMem(sizeof(L1CAPI_RadioLink_Info) * pL1CRLSetupReq->comContextInfo.rlCount,0);
    for(i=0;i<pL1CRLSetupReq->comContextInfo.rlCount;i++){
      rlInfoProcDecHdlr(msgStatus,&(pL1CRLSetupReq->pRlInfo[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*coordinate trch info*/
    pL1CRLSetupReq->ptrCoordTrchDchInfo = 
      (L1CAPI_DCH_CoordTrchInfoListItem *)allocMem(sizeof(L1CAPI_DCH_CoordTrchInfoListItem) * pL1CRLSetupReq->comContextInfo.coordTrchCount,0);
    for(i=0;i<pL1CRLSetupReq->comContextInfo.coordTrchCount;i++){
      coordTrchProcDecHdlr(msgStatus,&(pL1CRLSetupReq->ptrCoordTrchDchInfo[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*physical dl dpch info*/
    phyDlDpchInfoProcDecHdlr(msgStatus,&(pL1CRLSetupReq->physDlDpch));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*cctrch dl*/
    cctrchDecHdlr(msgStatus,&(pL1CRLSetupReq->cctrchDlTfc));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*physical ul dpch info*/
    phyUlDpchInfoProcDecHdlr(msgStatus,&(pL1CRLSetupReq->physUlDpch));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*cctrch ul*/
    cctrchDecHdlr(msgStatus,&(pL1CRLSetupReq->cctrchUlTfc));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;   
    /*Gap Info*/
    pL1CRLSetupReq->ptrTransGapPattSeqInfo = 
      (L1CAPI_TxGap_SeqInfo *)allocMem(sizeof(L1CAPI_TxGap_SeqInfo) * pL1CRLSetupReq->comContextInfo.tgpsCount,0);
    for(i=0;i<pL1CRLSetupReq->comContextInfo.tgpsCount;i++)
    {
       tgpsGapInfoProcDecHdlr(msgStatus,&(pL1CRLSetupReq->ptrTransGapPattSeqInfo[i]));
       if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
         return;      
    }
    /*active pattern info*/
    if(pL1CRLSetupReq->bit_mask & rl_Setup_activePatternSeqInfo_present)
    {
      pL1CRLSetupReq->ptrActivePatternSeqInfo = 
       (L1CAPI_Active_Pattern_Sequence_Info *)allocMem(sizeof(L1CAPI_Active_Pattern_Sequence_Info),0);
      activeTgpsPatternProcDecHdlr(msgStatus,pL1CRLSetupReq->ptrActivePatternSeqInfo);
    }
    
    /*balance info*/
    if(pL1CRLSetupReq->bit_mask & rl_Setup_dlPowerBalancingInfo_present)
    {
      pL1CRLSetupReq->ptrDlPowerBalancingInfo = 
        (L1CAPI_DL_PowerBalancing_Info *)allocMem(sizeof(L1CAPI_DL_PowerBalancing_Info),0);
      pwrBalanceInfoProcDecHdlr(msgStatus,pL1CRLSetupReq->ptrDlPowerBalancingInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;   
    }

    /*hsdsch info*/
    if(pL1CRLSetupReq->bit_mask & rl_Setup_hsdsch_present)
    {
      pL1CRLSetupReq->ptrHsdsch = 
        (L1CAPI_Radiolink_HSDSCH_Config * )allocMem(sizeof(L1CAPI_Radiolink_HSDSCH_Config),0);
      hsdschConfigProcDecHdlr(msgStatus,pL1CRLSetupReq->ptrHsdsch);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }

    /*edch config info*/
    if(pL1CRLSetupReq->bit_mask & rl_Setup_eDchRlSetupExtension_present)
    {
      pL1CRLSetupReq->ptrEDchRlSetupExtension = 
        (L1CAPI_Radiolink_EDCH_Config_Ext *)allocMem(sizeof(L1CAPI_Radiolink_EDCH_Config_Ext),0);
      edchExtConfigInfoProcDecHdlr(msgStatus,pL1CRLSetupReq->ptrEDchRlSetupExtension);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }
}

void radiolinkReconfigPrepRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t  i;
    L1CAPI_Radiolink_Reconfig_Prepare *pL1CRlReconfigReq = (L1CAPI_Radiolink_Reconfig_Prepare *)allocMem(sizeof(L1CAPI_Radiolink_Reconfig_Prepare),0);
    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;

    pL1CRlReconfigReq->bit_mask = subByteVal();

    /*NodB Context*/    
    pL1CRlReconfigReq->NodeBComContext = subByteVal();
    /*rl reconfig common context*/    
    rlReconfigCmnInfoProcDecHdlr(msgStatus,&(pL1CRlReconfigReq->rl_reconfig_comContextInfo));
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
    /*rl info*/
    pL1CRlReconfigReq->ptrRlInfo = 
      (L1CAPI_Radiolink_Reconfig_params * )allocMem(sizeof(L1CAPI_Radiolink_Reconfig_params) * pL1CRlReconfigReq->rl_reconfig_comContextInfo.rlCount,0);
    for(i=0;i<pL1CRlReconfigReq->rl_reconfig_comContextInfo.rlCount;i++)
    {
      rlReconfigInfoProcDecHdlr(msgStatus,&(pL1CRlReconfigReq->ptrRlInfo[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return; 
    }
    /*trch delete*/
    pL1CRlReconfigReq->ptrTrchDchDelete = 
      allocMem(sizeof(L1CAPI_DCH_ID) * pL1CRlReconfigReq->rl_reconfig_comContextInfo.trchCountDelete,0);
    for(i=0;i<pL1CRlReconfigReq->rl_reconfig_comContextInfo.trchCountDelete;i++)
    {
      pL1CRlReconfigReq->ptrTrchDchDelete[i] = subByteVal();
    }
    /*coordinate trch add*/    
    pL1CRlReconfigReq->ptrTrchDchAdd = 
      (L1CAPI_DCH_CoordTrchInfoListItem *)allocMem(sizeof(L1CAPI_DCH_CoordTrchInfoListItem) * pL1CRlReconfigReq->rl_reconfig_comContextInfo.coorTrchCountAdd,0);
    for(i=0;i<pL1CRlReconfigReq->rl_reconfig_comContextInfo.coorTrchCountAdd;i++){
      coordTrchProcDecHdlr(msgStatus,&(pL1CRlReconfigReq->ptrTrchDchAdd[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*coordinate trch modify*/    
    pL1CRlReconfigReq->PtrTrchDchModify = 
      (L1CAPI_DCH_CoordTrchInfoListItem *)allocMem(sizeof(L1CAPI_DCH_CoordTrchInfoListItem) * pL1CRlReconfigReq->rl_reconfig_comContextInfo.coorTrchCountModify,0);
    for(i=0;i<pL1CRlReconfigReq->rl_reconfig_comContextInfo.coorTrchCountModify;i++){
      coordTrchProcDecHdlr(msgStatus,&(pL1CRlReconfigReq->PtrTrchDchModify[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*Phy DL Dpch*/    
    if(pL1CRlReconfigReq->bit_mask & rl_Reconfig_physDlDpch_present)
    {
      pL1CRlReconfigReq->ptrPhysDldpch = 
        (L1CAPI_DL_DPCH_PhyInfo_Reconfig *)allocMem(sizeof(L1CAPI_DL_DPCH_PhyInfo_Reconfig),0);
      phyDlDpchReconfigInfoProcDecHdlr(msgStatus,pL1CRlReconfigReq->ptrPhysDldpch);
    }
    /*Phy UL Dpch*/    
    if(pL1CRlReconfigReq->bit_mask & rl_Reconfig_physUlDpch_present)
    {
      pL1CRlReconfigReq->ptrPhysUldpch = 
        (L1CAPI_UL_DPCH_PhyInfo_Reconfig *)allocMem(sizeof(L1CAPI_UL_DPCH_PhyInfo_Reconfig),0);
      phyUlDpchReconfigInfoProcDecHdlr(msgStatus,pL1CRlReconfigReq->ptrPhysUldpch);
    }
    /*cctrch DL*/    
    cctrchDecHdlr(msgStatus,&pL1CRlReconfigReq->cctrchDlTfc);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*cctrch UL*/    
    cctrchDecHdlr(msgStatus,&pL1CRlReconfigReq->cctrchUlTfc);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*gap info*/
    pL1CRlReconfigReq->ptrTransGapPattSeqInfo = 
      (L1CAPI_TxGap_SeqInfo *)allocMem(sizeof(L1CAPI_TxGap_SeqInfo) * pL1CRlReconfigReq->rl_reconfig_comContextInfo.tgpsCount,0);
    for(i=0;i<pL1CRlReconfigReq->rl_reconfig_comContextInfo.tgpsCount;i++)
    {
       tgpsGapInfoProcDecHdlr(msgStatus,&(pL1CRlReconfigReq->ptrTransGapPattSeqInfo[i]));
       if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
         return;      
    }

    /*hsdsch*/
    if(pL1CRlReconfigReq->bit_mask & rl_Reconfig_hsdsch_present)
    {    
      pL1CRlReconfigReq->ptrHsdsch = 
        (L1CAPI_Radiolink_HSDSCH_Reconfig *)allocMem(sizeof(L1CAPI_Radiolink_HSDSCH_Reconfig),0);
      hsdschReconfigProcDecHdlr(msgStatus,pL1CRlReconfigReq->ptrHsdsch);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return; 
    }
    /*edch*/        
    if(pL1CRlReconfigReq->bit_mask & rl_Reconfig_eDchRlSetupExtension_present)
    {    
      pL1CRlReconfigReq->ptrEDchRlExtension = 
        (L1CAPI_Radiolink_EDCH_Reconfig_Ext *)allocMem(sizeof(L1CAPI_Radiolink_EDCH_Reconfig_Ext),0);
      edchExtReconfigInfoProcDecHdlr(msgStatus,pL1CRlReconfigReq->ptrEDchRlExtension);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
}
