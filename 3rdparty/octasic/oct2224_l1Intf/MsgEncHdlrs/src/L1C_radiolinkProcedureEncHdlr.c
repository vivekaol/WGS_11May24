/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_radiolinkProcedureEncHdlr.h"
#include "L1C_radiolinkProcedureHsDschEncHdlr.h"
#include "L1C_radiolinkProcedureEdchEncHdlr.h"
#include "L1C_radiolinkProcedureParamValidate.h"
#include "L1C_cctrchEncHdlr.h"
#include "L1C_tfsEncHdlr.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"


static void rlCmnContextInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus ,void *pSrc,L1CAPI_RadioLink_CmnContextInfo *pL1CNodeBCmnContextInfo)
{


    rlCmnContextInfoProcParamValidate(msgStatus ,pL1CNodeBCmnContextInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CNodeBCmnContextInfo->rlCount);
    ADD_BYTE_VAL(pL1CNodeBCmnContextInfo->coordTrchCount);
    ADD_BYTE_VAL(pL1CNodeBCmnContextInfo->tgpsCount);
END_BLOCK_TRACE
}

static void dlCodeInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus ,void *pSrc)
{
    L1CAPI_DL_CodeInfo *pL1CDlCodeInfo = (L1CAPI_DL_CodeInfo *)pSrc;


    dlCodeInfoProcParamValidate(msgStatus ,pL1CDlCodeInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CDlCodeInfo->dl_ScramblingCode);
    ADD_WORD_VAL(pL1CDlCodeInfo->dL_ChannelisationCodeNumber);
    ADD_BYTE_VAL(pL1CDlCodeInfo->TransGapPatternSequenceCodeInfo);
END_BLOCK_TRACE
}

static void rlInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus ,void *pSrc)
{
    uint8_t i;
    L1CAPI_RadioLink_Info *pL1CRlInfo = (L1CAPI_RadioLink_Info *)pSrc;
    void *pDlCodeInfo;
    void * pEdchRlInfoExt;
    pEdchRlInfoExt = pL1CRlInfo->ptrEDchRlInfoExtension;

    rlInfoProcParamValidate(msgStatus,pL1CRlInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CRlInfo->bit_mask);
    ADD_BYTE_VAL(pL1CRlInfo->dlCodeCount);
    ADD_BYTE_VAL(pL1CRlInfo->rL_ID);
    ADD_WORD_VAL(pL1CRlInfo->c_ID);
    ADD_BYTE_VAL(pL1CRlInfo->firstRLS_indicator);
    ADD_BYTE_VAL(pL1CRlInfo->frameOffset);
    ADD_WORD_VAL(pL1CRlInfo->chipOffset);
    if(pL1CRlInfo->bit_mask & propagationDelay_present){
      ADD_WORD_VAL(pL1CRlInfo->propagationDelay);
    }
    if(pL1CRlInfo->bit_mask & diversityControlField_present){
      ADD_BYTE_VAL(pL1CRlInfo->diversityControlField);
    }
    ADD_WORD_VAL(pL1CRlInfo->initialDL_transmissionPower);
    ADD_WORD_VAL(pL1CRlInfo->maximumDL_power);
    ADD_WORD_VAL(pL1CRlInfo->minimumDL_power);
    if(pL1CRlInfo->bit_mask & rl_info_transmitDiverIndicator_present){
      ADD_BYTE_VAL(pL1CRlInfo->transmitDiversityIndicator);
    }
    for(i=0;i<pL1CRlInfo->dlCodeCount;i++)
    {
      pDlCodeInfo = &(pL1CRlInfo->ptrDlCodeInfo[i]);
      dlCodeInfoProcEncHdlr(msgStatus,pDlCodeInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CRlInfo->bit_mask & delayedActivation_present){
      ADD_BYTE_VAL(pL1CRlInfo->delayedActivation.delayedActivationType);
      if(pL1CRlInfo->delayedActivation.delayedActivationType == cfn_indication)
        ADD_BYTE_VAL(pL1CRlInfo->delayedActivation.cfn);
    }
    if(pL1CRlInfo->bit_mask & eDchRlInfoExtension_present){
      edchRlInfoExtProcEncHdlr(msgStatus,pEdchRlInfoExt);
    }
END_BLOCK_TRACE    
}


static void rlReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus ,void *pSrc)
{
    uint8_t i;
    L1CAPI_Radiolink_Reconfig_params *pL1CRlInfo = (L1CAPI_Radiolink_Reconfig_params *)pSrc;
    void *pDlCodeInfo;
    void * pEdchRlInfoExt;

    pEdchRlInfoExt = pL1CRlInfo->ptrEDchRlInfoExtension;
    rlReconfigInfoProcParamValidate(msgStatus,pL1CRlInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CRlInfo->bit_mask);
    ADD_BYTE_VAL(pL1CRlInfo->dlCodeCount);
    ADD_BYTE_VAL(pL1CRlInfo->rL_ID);
    if(pL1CRlInfo->bit_mask & maxDlPower_present)
    {
      ADD_WORD_VAL(pL1CRlInfo->maximumDL_power);
    }
    if(pL1CRlInfo->bit_mask & minDlPower_present)
    {
      ADD_WORD_VAL(pL1CRlInfo->minimumDL_power);
    }
    if(pL1CRlInfo->bit_mask & dlRefPower_present){
      ADD_WORD_VAL(pL1CRlInfo->dL_reference_power);
    }
    if(pL1CRlInfo->bit_mask & rl_reconfig_transmitDiverIndicator_present){
      ADD_BYTE_VAL(pL1CRlInfo->transmitDiversityIndicator);
    }
    if(pL1CRlInfo->bit_mask & dlDpchTimingAdj_present){
      ADD_BYTE_VAL(pL1CRlInfo->transmitDiversityIndicator);
    }
    for(i=0;i<pL1CRlInfo->dlCodeCount;i++)
    {
      pDlCodeInfo = &(pL1CRlInfo->ptrDlCodeInfo[i]);
      dlCodeInfoProcEncHdlr(msgStatus,pDlCodeInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CRlInfo->bit_mask & eDchRlReconfigInfoExtension_present){
      edchRlInfoExtProcEncHdlr(msgStatus,pEdchRlInfoExt);
    }
END_BLOCK_TRACE    
}

static void dchTrchProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_DCH_Info *pL1CDchInfo = (L1CAPI_DCH_Info *)pSrc;
    void * pTrchTfInfoDl;
    void * pTrchTfInfoUl;

    pTrchTfInfoDl = pL1CDchInfo->ptrTfsDL;
    pTrchTfInfoUl = pL1CDchInfo->ptrTfsUL;
    dchTrchProcParamValidate(msgStatus,pL1CDchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CDchInfo->bit_mask);
    ADD_BYTE_VAL(pL1CDchInfo->dCH_ID);
    ADD_BYTE_VAL(pL1CDchInfo->qE_Selector);
    if(pL1CDchInfo->bit_mask & tfsDL_present)
    {
      tfsEncHdlr(msgStatus,pTrchTfInfoDl);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    if(pL1CDchInfo->bit_mask & tfsUL_present)
    {
      tfsEncHdlr(msgStatus,pTrchTfInfoUl);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

static void coordTrchProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void* pSrc)
{
    uint8_t i;
    L1CAPI_DCH_CoordTrchInfoListItem *pL1CCordInfo = (L1CAPI_DCH_CoordTrchInfoListItem *)pSrc;
    void * pDchInfo;

    coordTrchProcParamValidate(msgStatus,pL1CCordInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CCordInfo->bit_mask);
    ADD_BYTE_VAL(pL1CCordInfo->dchCount);
    if(pL1CCordInfo->bit_mask & toAws_present){
      ADD_WORD_VAL(pL1CCordInfo->toAWS);
    }
    if(pL1CCordInfo->bit_mask & toAwe_present){
      ADD_WORD_VAL(pL1CCordInfo->toAWE);
    }
    if(pL1CCordInfo->bit_mask & payloadCRC_presenceIndicator_present){
      ADD_BYTE_VAL(pL1CCordInfo->payloadCRC_PresenceIndicator);
    }
    if(pL1CCordInfo->bit_mask & ulFpMode_present){
      ADD_BYTE_VAL(pL1CCordInfo->ul_FP_Mode);
    }
    for(i=0;i<pL1CCordInfo->dchCount;i++)
    {
      pDchInfo = &(pL1CCordInfo->ptrDCHSpecificInfo[i]);
      dchTrchProcEncHdlr(msgStatus,pDchInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
END_BLOCK_TRACE
}

static void phyDlDpchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc)
{
    L1CAPI_DL_DPCH_PhyInfo *pL1CPhyDlDpchInfo = (L1CAPI_DL_DPCH_PhyInfo *)pSrc;


    phyDlDpchInfoProcParamValidate(msgStatus,pL1CPhyDlDpchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->bit_mask);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->dl_DPCH_SlotFormat);
    if(pL1CPhyDlDpchInfo->bit_mask & DL_DPCH_RL_Setup_tFCI_present)
      ADD_BYTE_VAL(pL1CPhyDlDpchInfo->tFCI_Presence);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->multiplexingPosition);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->powerOffsetInformation.pO1_ForTFCI_Bits);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->powerOffsetInformation.pO2_ForTPC_Bits);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->powerOffsetInformation.pO3_ForPilotBits);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->tPC_DownlinkStepSize);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->limitedPowerIncrease);
    ADD_BYTE_VAL(pL1CPhyDlDpchInfo->innerLoopDLPCStatus);    
END_BLOCK_TRACE
}

static void phyDlDpchReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void* pSrc)
{
    L1CAPI_DL_DPCH_PhyInfo_Reconfig *pL1CPhyDlDpchInfoReconfig = (L1CAPI_DL_DPCH_PhyInfo_Reconfig *)pSrc;    


    phyDlDpchReconfigInfoProcParamValidate(msgStatus,pL1CPhyDlDpchInfoReconfig);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPhyDlDpchInfoReconfig->bit_mask);
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_SlotFormat_present)
      ADD_BYTE_VAL(pL1CPhyDlDpchInfoReconfig->dl_DPCH_SlotFormat);
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_tFCI_present)
      ADD_BYTE_VAL(pL1CPhyDlDpchInfoReconfig->tFCI_Presence);
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_MuxPos_present)
      ADD_BYTE_VAL(pL1CPhyDlDpchInfoReconfig->multiplexingPosition);
    if(pL1CPhyDlDpchInfoReconfig->bit_mask & DL_DPCH_RL_Reconfig_LimitedPwrInc_present)
      ADD_BYTE_VAL(pL1CPhyDlDpchInfoReconfig->limitedPowerIncrease);
END_BLOCK_TRACE
}

static void phyUlDpchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void* pSrc)
{    
    L1CAPI_UL_DPCH_PhyInfo *pL1CPhyUlDpchInfo = (L1CAPI_UL_DPCH_PhyInfo *)pSrc;


    phyUlDpchInfoProcParamValidate(msgStatus,pL1CPhyUlDpchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->bit_mask);
    ADD_LONG_VAL(pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber);
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength);
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present)
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs);
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ul_PunctureLimit);
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat);
    ADD_WORD_VAL(pL1CPhyUlDpchInfo->ul_SIR_Target);
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->diversityMode);
    if(pL1CPhyUlDpchInfo->bit_mask &    UL_DPCH_Setup_DpcMode_present)
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->dpcMode);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Setup_IndEDch_present)
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ulDpdchIndEDch);    
END_BLOCK_TRACE
}

static void phyUlDpchReconfigInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void* pSrc)
{    
    L1CAPI_UL_DPCH_PhyInfo_Reconfig *pL1CPhyUlDpchInfo = (L1CAPI_UL_DPCH_PhyInfo_Reconfig *)pSrc;


    phyUlDpchReconfigInfoProcParamValidate(msgStatus,pL1CPhyUlDpchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPhyUlDpchInfo->bit_mask);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlScramCodeInfo_present){
      ADD_LONG_VAL(pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeNumber);
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ul_ScramblingCodeInfo.uL_ScramblingCodeLength);
    }
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MinChanCodeLen_present)
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->minUL_ChannelisationCodeLength);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present)
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->maxNrOfUL_DPDCHs);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlPuncLimit_present)   
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ul_PunctureLimit);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSlotFormat_present)   
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ul_DPCCH_SlotFormat);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_UlSIR_present)   
      ADD_WORD_VAL(pL1CPhyUlDpchInfo->ul_SIR_Target);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_DiversityMode_present)       
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->diversityMode);
    if(pL1CPhyUlDpchInfo->bit_mask & UL_DPCH_Reconfig_IndEDch_present)
      ADD_BYTE_VAL(pL1CPhyUlDpchInfo->ulDpdchIndEDch);    
END_BLOCK_TRACE
}

static void pwrBalanceInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void* pSrc)
{
    L1CAPI_DL_PowerBalancing_Info *pL1CPwrBalanceInfo = (L1CAPI_DL_PowerBalancing_Info *)pSrc;

}

static void rlReconfigCmnInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void * pSrc,L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo)
{

    rlReconfigCmnInfoProcParamValidate(msgStatus,pL1CRlReconfigCmnInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return; 
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CRlReconfigCmnInfo->rlCount);
    ADD_BYTE_VAL(pL1CRlReconfigCmnInfo->coorTrchCountAdd);    
    ADD_BYTE_VAL(pL1CRlReconfigCmnInfo->coorTrchCountModify);    
    ADD_BYTE_VAL(pL1CRlReconfigCmnInfo->trchCountDelete);    
    ADD_BYTE_VAL(pL1CRlReconfigCmnInfo->tgpsCount);    
END_BLOCK_TRACE
}

static void activePatternInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    L1CAPI_Active_Pattern_Seq4 *pL1CActvPatternInfo = (L1CAPI_Active_Pattern_Seq4 *)pSrc;


START_BLOCK_TRACE    
    ADD_BYTE_VAL(pL1CActvPatternInfo->tGPSID);
    ADD_WORD_VAL(pL1CActvPatternInfo->tGPRC);
    ADD_BYTE_VAL(pL1CActvPatternInfo->tGCFN);    
END_BLOCK_TRACE
}

static void activeTgpsPatternProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    uint8_t i;
    L1CAPI_Active_Pattern_Sequence_Info *pL1CActvPattern = (L1CAPI_Active_Pattern_Sequence_Info *)pSrc;
    void * pTgpss;

START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CActvPattern->cMConfigurationChangeCFN);
    ADD_BYTE_VAL(pL1CActvPattern->tgpssCount);    
    for(i=0;i<pL1CActvPattern->tgpssCount;i++)
    {
      pTgpss = &(pL1CActvPattern->ptrTgpss[i]);
      activePatternInfoProcEncHdlr(msgStatus,pTgpss);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;       
    }
END_BLOCK_TRACE
}

static void tgpsGapInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,void *pSrc)
{
    uint8_t bit_mask;
    L1CAPI_TxGap_SeqInfo *pL1CtgpsGapInfo = (L1CAPI_TxGap_SeqInfo *)pSrc;
    bit_mask = pL1CtgpsGapInfo->bit_mask;
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->tGPSID);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->tGSN);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->tGL1);
    if(bit_mask & tGL2_present){    
      ADD_BYTE_VAL(pL1CtgpsGapInfo->tGL2);
    }
    ADD_WORD_VAL(pL1CtgpsGapInfo->tGD);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->tGPL1);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->uL_DL_mode);
    if(bit_mask & downlink_Compressed_Mode_Method_present){
      ADD_BYTE_VAL(pL1CtgpsGapInfo->downlink_Compressed_Mode_Method);
    }
    if(bit_mask & uplink_Compressed_Mode_Method_present){
      ADD_BYTE_VAL(pL1CtgpsGapInfo->uplink_Compressed_Mode_Method);
    }
    ADD_BYTE_VAL(pL1CtgpsGapInfo->dL_FrameType);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->delta_SIR1);
    ADD_BYTE_VAL(pL1CtgpsGapInfo->delta_SIR_after1);
    if(bit_mask & delta_SIR2_present){
      ADD_BYTE_VAL(pL1CtgpsGapInfo->delta_SIR2);
    }
    if(bit_mask & delta_SIR_after2_present){
      ADD_BYTE_VAL(pL1CtgpsGapInfo->delta_SIR_after2);
    }
END_BLOCK_TRACE
}

/*********************main interface of radio link procedure ***************************/
void radiolinkSetupRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t bit_mask,i;    
    L1CAPI_RadioLink_CmnContextInfo *pL1CNodeBCmnContextInfo;
    void * pRlCmnInfo;
    void * pRlInfo;
    void * pCoordTrchInfo;
    void * pDpchPhyDl;
    void * pDpchPhyUl;
    void * pCctrchDl;
    void * pCctrchUl;
    void * pGapInfo;
    void * pBalanceInfo;
    void * pHsInfo;
    void * pEdchInfo;
    void * pActvPattInfo;
    uint8_t  n_coord = 0;
    L1CAPI_Radiolink_Setup_Request *pL1CRl = (L1CAPI_Radiolink_Setup_Request *) pHostDLMsg;
    pL1CNodeBCmnContextInfo = &(pL1CRl->comContextInfo);
    pRlCmnInfo = &pL1CRl->comContextInfo;
    pDpchPhyDl = &(pL1CRl->physDlDpch);
    pDpchPhyUl = &(pL1CRl->physUlDpch);
    pCctrchDl = &(pL1CRl->cctrchDlTfc);
    pCctrchUl = &(pL1CRl->cctrchUlTfc);
    pBalanceInfo = pL1CRl->ptrDlPowerBalancingInfo;
    pHsInfo = pL1CRl->ptrHsdsch;
    pEdchInfo = pL1CRl->ptrEDchRlSetupExtension;
    pActvPattInfo = pL1CRl->ptrActivePatternSeqInfo;
    bit_mask = pL1CRl->bit_mask;  
    n_coord = pL1CRl->comContextInfo.coordTrchCount;
PRINTF("L23--> Radiolink Setup Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);
    /*rl common context*/
    rlCmnContextInfoProcEncHdlr(msgStatus,pRlCmnInfo,pL1CNodeBCmnContextInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*rl info*/
    for(i=0;i<pL1CNodeBCmnContextInfo->rlCount;i++){      
      pRlInfo = &(pL1CRl->pRlInfo[i]);
      rlInfoProcEncHdlr(msgStatus,pRlInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*coordinate trch info*/
    for(i=0;i<n_coord;i++){
      pCoordTrchInfo = &(pL1CRl->ptrCoordTrchDchInfo[i]);
      coordTrchProcEncHdlr(msgStatus,pCoordTrchInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*physical dl dpch info*/
    phyDlDpchInfoProcEncHdlr(msgStatus,pDpchPhyDl);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*cctrch dl*/
    cctrchEncHdlr(msgStatus,pCctrchDl,1);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*physical ul dpch info*/
    phyUlDpchInfoProcEncHdlr(msgStatus,pDpchPhyUl);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*cctrch ul*/
    cctrchEncHdlr(msgStatus,pCctrchUl,0);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;   
    /*Gap Info*/
    for(i=0;i<pL1CNodeBCmnContextInfo->tgpsCount;i++){
      pGapInfo = &(pL1CRl->ptrTransGapPattSeqInfo[i]);
      tgpsGapInfoProcEncHdlr(msgStatus,pGapInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;       
    }
    /*active pattern info*/
    if(bit_mask & rl_Setup_activePatternSeqInfo_present)
    {
      pActvPattInfo = (pL1CRl->ptrActivePatternSeqInfo);
      activeTgpsPatternProcEncHdlr(msgStatus,pActvPattInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return; 
    }
    /*balance info*/
    if(bit_mask & rl_Setup_dlPowerBalancingInfo_present)
    {
      pwrBalanceInfoProcEncHdlr(msgStatus,pBalanceInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;   
    }
    /*hsdsch info*/
    if(bit_mask & rl_Setup_hsdsch_present)
    {
      hsdschConfigProcEncHdlr(msgStatus,pHsInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }

    /*edch config info*/
    if(bit_mask & rl_Setup_eDchRlSetupExtension_present)
    {
      edchExtConfigInfoProcEncHdlr(msgStatus,pEdchInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
  return;
}

void radiolinkSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

}

void radiolinkReconfigPrepRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t  bit_mask =0;
    uint8_t  i;
    L1CAPI_NodeB_Com_Context nodeBContext;
    L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo;

    void * pRlReconfigInfo;
    void * pRlInfo;
    void * pCordDchAdd;
    void * pCordDchMod;
    void * pDpchPhyDl;
    void * pDpchPhyUl;
    void * pCctrchDl;
    void * pCctrchUl;
    void * pGapInfo;
    void * pHsdschInfo;
    void * pRlExtInfo;
    L1CAPI_DCH_ID dchDelId;    

    L1CAPI_Radiolink_Reconfig_Prepare * pL1CRlReconfigPrepare = (L1CAPI_Radiolink_Reconfig_Prepare * )pHostDLMsg;
    nodeBContext = pL1CRlReconfigPrepare->NodeBComContext;
    bit_mask = pL1CRlReconfigPrepare->bit_mask;
    pL1CRlReconfigCmnInfo = &(pL1CRlReconfigPrepare->rl_reconfig_comContextInfo);
    pRlReconfigInfo = &(pL1CRlReconfigPrepare->rl_reconfig_comContextInfo);
    pDpchPhyDl = pL1CRlReconfigPrepare->ptrPhysDldpch;
    pDpchPhyUl = pL1CRlReconfigPrepare->ptrPhysUldpch;
    pCctrchDl = &(pL1CRlReconfigPrepare->cctrchDlTfc);
    pCctrchUl = &(pL1CRlReconfigPrepare->cctrchUlTfc);
    pHsdschInfo = pL1CRlReconfigPrepare->ptrHsdsch;
    pRlExtInfo = pL1CRlReconfigPrepare->ptrEDchRlExtension;
    bit_mask = pL1CRlReconfigPrepare->bit_mask;
PRINTF("L23--> Radiolink Reconfiguration Prepare \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);
    /*NodB Context*/    
    ADD_BYTE_VAL(nodeBContext);    
    /*rl reconfig common context*/    
    rlReconfigCmnInfoProcEncHdlr(msgStatus,pRlReconfigInfo,pL1CRlReconfigCmnInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
    /*rl info*/    
    for(i=0;i<pL1CRlReconfigCmnInfo->rlCount;i++)
    {
      pRlInfo = &(pL1CRlReconfigPrepare->ptrRlInfo[i]);
      rlReconfigInfoProcEncHdlr(msgStatus,pRlInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return; 
    }
    /*trch delete*/    
    for(i=0;i<pL1CRlReconfigCmnInfo->trchCountDelete;i++)
    {
      dchDelId = pL1CRlReconfigPrepare->ptrTrchDchDelete[i];
      ADD_BYTE_VAL(dchDelId);
    }
    /*coordinate trch add*/    
    for(i=0;i<pL1CRlReconfigCmnInfo->coorTrchCountAdd;i++){
      pCordDchAdd = &(pL1CRlReconfigPrepare->ptrTrchDchAdd[i]);
      coordTrchProcEncHdlr(msgStatus,pCordDchAdd);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*coordinate trch modify*/    
    for(i=0;i<pL1CRlReconfigCmnInfo->coorTrchCountModify;i++){
      pCordDchMod = &(pL1CRlReconfigPrepare->PtrTrchDchModify[i]);
      coordTrchProcEncHdlr(msgStatus,pCordDchMod);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*Phy DL Dpch*/    
    if(bit_mask & rl_Reconfig_physDlDpch_present)
    {
      phyDlDpchReconfigInfoProcEncHdlr(msgStatus, pDpchPhyDl);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*Phy UL Dpch*/    
    if(bit_mask & rl_Reconfig_physUlDpch_present)
    {
      phyUlDpchReconfigInfoProcEncHdlr(msgStatus,pDpchPhyUl);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*cctrch DL*/    
    cctrchEncHdlr(msgStatus,pCctrchDl,1);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*cctrch UL*/    
    cctrchEncHdlr(msgStatus,pCctrchUl,0);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    /*gap info*/
    for(i=0;i<pL1CRlReconfigCmnInfo->tgpsCount;i++){
      pGapInfo = &(pL1CRlReconfigPrepare->ptrTransGapPattSeqInfo[i]);
      tgpsGapInfoProcEncHdlr(msgStatus,pGapInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;       
    }
    /*hsdsch*/
    if(bit_mask & rl_Reconfig_hsdsch_present)
    {    
      hsdschReconfigProcEncHdlr(msgStatus,pHsdschInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return; 
    }
    /*edch*/        
    if(bit_mask & rl_Reconfig_eDchRlSetupExtension_present)
    {    
      edchExtReconfigInfoProcEncHdlr(msgStatus,pRlExtInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
  return;
}

void radiolinkReconfigPrepRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

}

void radiolinkReconfigCommitRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t bit_mask = 0;
    uint8_t nrOfTgpss;
    L1CAPI_NodeB_Com_Context nodeBCmnCtx;
    uint8_t cfn;
    void * pActvPattern;

    L1CAPI_Radiolink_ReconfigCommit * pL1CRlReconfigCommit = (L1CAPI_Radiolink_ReconfigCommit *)pHostDLMsg;
    bit_mask = pL1CRlReconfigCommit->bit_mask;
    pActvPattern = pL1CRlReconfigCommit->ptrActivePattSeqInfo;
    if(bit_mask & activePattSeqInfo_present){
      nrOfTgpss = pL1CRlReconfigCommit->ptrActivePattSeqInfo->tgpssCount;
    }
    nodeBCmnCtx = pL1CRlReconfigCommit->NodeBComContext;
    cfn = pL1CRlReconfigCommit->cfn;    
    bit_mask = pL1CRlReconfigCommit->bit_mask;
PRINTF("L23--> Radiolink Reconfiguration Commit Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);
    ADD_BYTE_VAL(nodeBCmnCtx);
    ADD_BYTE_VAL(cfn);    
    
    if(bit_mask & activePattSeqInfo_present)
    {
      activeTgpsPatternProcEncHdlr(msgStatus,pActvPattern);
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
  return;
} 

void radiolinkReconfigCommitRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

} 

void radiolinkDeleteRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_NodeB_Com_Context nodeBCmnCtx;
    uint8_t nrOfRl,i;
    L1CAPI_Radiolink_ID rlId;

    L1CAPI_Radiolink_DeletionRequest * pL1CRlDel = (L1CAPI_Radiolink_DeletionRequest *)pHostDLMsg;
    nodeBCmnCtx = pL1CRlDel->NodeBComContext;
    nrOfRl = pL1CRlDel->rlCount;
PRINTF("L23--> Radiolink Deletion Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(nodeBCmnCtx);
    ADD_BYTE_VAL(nrOfRl);
    for(i=0;i<nrOfRl;i++)
    {
      rlId = pL1CRlDel->pRl_ID[i];        
      ADD_BYTE_VAL(rlId);
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
    return;
}

void radiolinkDeleteRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

}


void radiolinkReconfigCancelRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_NodeB_Com_Context nodeBCmnCtx;

    L1CAPI_Radiolink_ReconfigCancel * pL1CRlCancel = (L1CAPI_Radiolink_ReconfigCancel *)pHostDLMsg;
    nodeBCmnCtx = pL1CRlCancel->NodeBComContext;
PRINTF("L23--> Radiolink Reconfiguration Cancel Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(nodeBCmnCtx);
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
    return;
}

void radiolinkReconfigCancelRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

}
void compressedModeCommandProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t bit_mask = 0;
    L1CAPI_NodeB_Com_Context nodeBCmnCtx;
    void * pActvPattern;

    L1CAPI_Compressed_Mode_Command * pCMCommand = (L1CAPI_Compressed_Mode_Command *)pHostDLMsg;
    nodeBCmnCtx = pCMCommand->NodeBComContext;
	pActvPattern = &pCMCommand->ActivePattSeqInfo;
	
	PRINTF("L23--> Compress Mode Command Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);
    ADD_BYTE_VAL(nodeBCmnCtx);
    
	activeTgpsPatternProcEncHdlr(msgStatus,pActvPattern);
    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
  return;


}
