/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_responseProcedureEncHdlr.c

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
#include "L1C_responseProcedureEncHdlr.h"
#include "l1capi_datastruct.h"
#include "msgPutPrimitives.h"

void sccpchSetupResponseEncHdlr(L1CAPI_Sccpch_Setup_Response * pL1CSccpchSetupRsp)
{
    uint8_t i;
	addByteVal(pL1CSccpchSetupRsp->bit_mask);
	addByteVal(pL1CSccpchSetupRsp->n_FACH);
    for(i=0;i<pL1CSccpchSetupRsp->n_FACH;i++)
    {
      addLongVal(pL1CSccpchSetupRsp->ptrFACH_binding_id[i]);
    }
    if(pL1CSccpchSetupRsp->bit_mask & pchBindingId_present)
    {
      addLongVal(pL1CSccpchSetupRsp->pCH_binding_id);
    }
    msgStatusEncHdlr(&(pL1CSccpchSetupRsp->msgStatus));
}

void prachSetupResponseEncHdlr(L1CAPI_Prach_Setup_Response * pL1CPrachSetupRsp)
{
	addLongVal(pL1CPrachSetupRsp->rAch_binding_id);
    msgStatusEncHdlr(&(pL1CPrachSetupRsp->msgStatus));
}

static __inline__ void measInfEncHdlr(L1CAPI_MeasInf *pMeasInf)
{
	addByteVal(pMeasInf->measType);
	addWordVal(pMeasInf->measValue);
}

void commonMeasInitResponseEncHdlr(L1CAPI_Common_Meas_Init_Response *pL1CCMeasInitRsp)
{
	addByteVal(pL1CCMeasInitRsp->bit_mask);
	addLongVal(pL1CCMeasInitRsp->measureID);
	msgStatusEncHdlr(&pL1CCMeasInitRsp->msgStatus);
	if (pL1CCMeasInitRsp->bit_mask & cMeasInitResp_cellObjMeasInf_present)
	{
		measInfEncHdlr(&pL1CCMeasInitRsp->cellObjMeasInf);
	}

	if (pL1CCMeasInitRsp->bit_mask & cMeasInitResp_rachObjMeasInf_present)
	{
		measInfEncHdlr(&pL1CCMeasInitRsp->rachObjMeasInf);
	}

	if (pL1CCMeasInitRsp->bit_mask & cMeasInitResp_sfn_present)
	{
		addWordVal(pL1CCMeasInitRsp->sfn);
	}
}

void commonMeasReportEncHdlr(L1CAPI_Common_Meas_Report *pL1CCMeasReport)
{
	addByteVal(pL1CCMeasReport->bit_mask);
	addLongVal(pL1CCMeasReport->measureID);
	if (pL1CCMeasReport->bit_mask & cMeasRep_cellObjMeasInf_present)
	{
		measInfEncHdlr(&pL1CCMeasReport->cellObjMeasInf);
	}

	if (pL1CCMeasReport->bit_mask & cMeasRep_rachObjMeasInf_present)
	{
		measInfEncHdlr(&pL1CCMeasReport->rachObjMeasInf);
	}

	if (pL1CCMeasReport->bit_mask & cMeasRep_sfn_present)
	{
		addWordVal(pL1CCMeasReport->sfn);
	}	
}

void commonMeasFailIndicationEncHdlr(L1CAPI_Common_Meas_Fail_Ind *pL1CCMeasFailInd)
{
	addLongVal(pL1CCMeasFailInd->measureID);
	msgStatusEncHdlr(&pL1CCMeasFailInd->msgStatus);
}

static __inline__ void edchMacDFlowInfoRspEncHdlr(L1CAPI_Edch_MacD_Flow_Info_resp * pEdchMacDFlowInfo)
{
    addByteVal(pEdchMacDFlowInfo->bit_mask);
    addByteVal(pEdchMacDFlowInfo->e_DCH_MACdFlow_ID);
    addLongVal(pEdchMacDFlowInfo->binding_id);
	if(pEdchMacDFlowInfo->bit_mask & edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present){
      addByteVal(pEdchMacDFlowInfo->harqProcAlloc2ms_SchedTxGrant);
    }
}

static __inline__ void cordTrchInfoRspEncHdlr(L1CAPI_CoordTrchRespItem *pCordTrchInfo)
{
    addByteVal(pCordTrchInfo->dchId);
    addLongVal(pCordTrchInfo->binding_id);
}

static void edchFddCtrlChInfoEncHdlr(L1CAPI_Edch_Fdd_Ctrl_Channel_Info *pCtrlChInfo)
{
    addWordVal(pCtrlChInfo->bit_mask);
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eAgchRgchHichScramCode_present)
    {
      addByteVal(pCtrlChInfo->eAgchRgchHichScramCode);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eAgchChanCode_present)
    {
      addWordVal(pCtrlChInfo->eAgchChanCode);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_primaryErnti_present)
    {
      addWordVal(pCtrlChInfo->primaryErnti);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_secondaryErnti_present)
    {
      addWordVal(pCtrlChInfo->secondaryErnti);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchHichChanCode_present)
    {
      addWordVal(pCtrlChInfo->eRgchHichChanCode);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchSignatureSeq_present)
    {
      addByteVal(pCtrlChInfo->eRgchSignatureSeq);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eHichSignatureSeq_present)
    {
      addByteVal(pCtrlChInfo->eHichSignatureSeq);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_servingGrantVal_present)
    {
      addByteVal(pCtrlChInfo->servingGrantVal);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_priSecGrantSelector_present)
    {
      addByteVal(pCtrlChInfo->priSecGrantSelector);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchReleaseInd_present)
    {
      addByteVal(pCtrlChInfo->eRgchReleaseInd);
    }
}

static void edchFddInfoRspEncHdlr(L1CAPI_Edch_Fdd_Info_Resp * pEdchFddInfoRsp)
{
    uint8_t i;
    addByteVal(pEdchFddInfoRsp->bit_mask);
    if(pEdchFddInfoRsp->bit_mask & edchRlSetId_present){
      addByteVal(pEdchFddInfoRsp->edchRlSetId);
    }
    if(pEdchFddInfoRsp->bit_mask & edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present){
      addByteVal(pEdchFddInfoRsp->harqProcAlloc2ms_SchedTxGrant);
    }
    addByteVal(pEdchFddInfoRsp->mAcdFlowCount);
    for(i=0;i<pEdchFddInfoRsp->mAcdFlowCount;i++)
    {
      edchMacDFlowInfoRspEncHdlr(&(pEdchFddInfoRsp->ptrEdchMacdFlowInfoResp[i]));
    }
    if(pEdchFddInfoRsp->bit_mask & edchFddCtrlChanInfo_present){
      edchFddCtrlChInfoEncHdlr(pEdchFddInfoRsp->ptrEdchFddCtrlChanInfo);
	}
}

static void radiolinkInfoRspEncHdlr(L1CAPI_Radiolink_Info_Resp * pRlInfoRsp)
{
    uint8_t i;
    addByteVal(pRlInfoRsp->bit_mask);
    addByteVal(pRlInfoRsp->coordTrchCount);
    addByteVal(pRlInfoRsp->rL_ID);
    addByteVal(pRlInfoRsp->rlSetId);
    addByteVal(pRlInfoRsp->referenceRlId);
    for(i=0;i<pRlInfoRsp->coordTrchCount;i++)
    {
      cordTrchInfoRspEncHdlr(&(pRlInfoRsp->ptrCoordTrchRsp[i]));
    }
    if(pRlInfoRsp->bit_mask & edchFddInfoRsp_present)
    {
      edchFddInfoRspEncHdlr(pRlInfoRsp->ptrEdchFddInfoRsp);
    }
}

static __inline__ void harqMemExpInfoEncHdlr(L1CAPI_HarqMem_Partitioning_Explicit * pExpInfo)
{
    uint8_t i;
    addByteVal(pExpInfo->nrOfProcess);
    for(i=0;i<pExpInfo->nrOfProcess;i++)
    {
       addByteVal(pExpInfo->ptrProcessMemSize[i]);
    }
}

static __inline__ void hsMacDFlowInfoRspEncHdlr(L1CAPI_MacDFlow_Info_Resp *pHsMacDFlowInfo)
{
    addByteVal(pHsMacDFlowInfo->macDFlowId);
    addLongVal(pHsMacDFlowInfo->bindingId);
}

static void hsDschInfoRspEncHdlr(L1CAPI_HSDSCH_Info_Resp * pHsdschInfoRsp)
{
    uint8_t i;
    addByteVal(pHsdschInfoRsp->harqMemChoice);
    addByteVal(pHsdschInfoRsp->macDFlowCount);
    addByteVal(pHsdschInfoRsp->hsscchCodeCount);
    for(i=0;i<pHsdschInfoRsp->macDFlowCount;i++)
    {
      hsMacDFlowInfoRspEncHdlr(&(pHsdschInfoRsp->ptrMacDFlowInfo[i]));
    }
    for(i=0;i<pHsdschInfoRsp->hsscchCodeCount;i++)
    {
      addWordVal(pHsdschInfoRsp->ptrHsscchInfoResp[i]);
    }
	if(pHsdschInfoRsp->harqMemChoice == L1CAPI_HARQ_MEM_IMPLICIT){
      addByteVal(pHsdschInfoRsp->u.harqMemImplicit.nrOfProcess);
    }
	else{
      harqMemExpInfoEncHdlr(&(pHsdschInfoRsp->u.HarqMemExplicit));
    }
}

void radiolinkSetupResponseEncHdlr(L1CAPI_Radiolink_Setup_Response * pRlSetupRsp)
{
    uint8_t i;

    addByteVal(pRlSetupRsp->bit_mask);
    addByteVal(pRlSetupRsp->NodeBComContext);
    addByteVal(pRlSetupRsp->rlCount);
    msgStatusEncHdlr(&(pRlSetupRsp->msgStatus));    
	for(i=0;i<pRlSetupRsp->rlCount;i++){
      radiolinkInfoRspEncHdlr(&(pRlSetupRsp->ptrRlInfoResp[i]));
    }
    if(pRlSetupRsp->bit_mask & rl_SetupResp_hsdschInfoResp_present)
    {
      hsDschInfoRspEncHdlr(pRlSetupRsp->ptrHsdschInfoResp);
    }
}

void radiolinkReconfigReadyEncHdlr(L1CAPI_Radiolink_Reconfigure_Ready * pRlReconfigRdy)
{
    uint8_t i;

    addByteVal(pRlReconfigRdy->bit_mask);
    addByteVal(pRlReconfigRdy->rlCount);
    msgStatusEncHdlr(&(pRlReconfigRdy->msgStatus));    
	for(i=0;i<pRlReconfigRdy->rlCount;i++){
      radiolinkInfoRspEncHdlr(&(pRlReconfigRdy->ptrRlInfoResp[i]));
    }
    if(pRlReconfigRdy->bit_mask & rl_ReconfigResp_hsdschInfoResp_present)
    {
      hsDschInfoRspEncHdlr(pRlReconfigRdy->ptrHsdschInfoResp);
    }
}

void radiolinkFailureIndicationProcEncHdlr(L1CAPI_Radiolink_Failure_Ind *pL1CRlFailInd)
{
    uint8_t i;
    addByteVal(pL1CRlFailInd->rlCount);
    addByteVal(pL1CRlFailInd->rlsCount);
    
    if (pL1CRlFailInd->rlCount!=0)
    {
        for(i=0;i<pL1CRlFailInd->rlCount;i++)
        {
            addByteVal(pL1CRlFailInd->pRlFailInf[i].rL_ID);
            addByteVal(pL1CRlFailInd->pRlFailInf[i].cause);
        }
    }
    
    if (pL1CRlFailInd->rlsCount!=0)
    {
        for(i=0;i<pL1CRlFailInd->rlsCount;i++)
        {
            addByteVal(pL1CRlFailInd->pRlsFailInf[i].rLS_ID);
            addByteVal(pL1CRlFailInd->pRlsFailInf[i].cause);
        }
    }    
}

void radiolinkRestoreIndicationProcEncHdlr(L1CAPI_Radiolink_Restore_Ind *pL1CRlRestoreInd)
{
    uint8_t i;
    addByteVal(pL1CRlRestoreInd->rlCount);
    addByteVal(pL1CRlRestoreInd->rlsCount);
    if (pL1CRlRestoreInd->rlCount!=0)
    {
        for(i=0;i<pL1CRlRestoreInd->rlCount;i++)
        {
            addByteVal(pL1CRlRestoreInd->pRl_ID[i]);
        }
    }
    if (pL1CRlRestoreInd->rlsCount!=0)
    {
        for(i=0;i<pL1CRlRestoreInd->rlsCount;i++)
        {
            addByteVal(pL1CRlRestoreInd->pRls_ID[i]);
        }
    }
}

static void dMeasRlInfEncHdlr(L1CAPI_DMeasRl_Info *pRlInfo)
{
	addByteVal(pRlInfo->bit_mask);
	addByteVal(pRlInfo->rL_ID);

	if (pRlInfo->bit_mask & dMeasRlInf_measInf_present)
	{
		measInfEncHdlr(&pRlInfo->measInf);

		if (pRlInfo->bit_mask & dMeasRlInf_cfn_present)
		{
			addByteVal(pRlInfo->cfn);
		}
	}
}

void dedicatedMeasInitResponseProcEncHdlr(L1CAPI_Dedicated_Meas_Init_Response *pL1CDMeasInitRsp)
{
	uint8_t i;
	addLongVal(pL1CDMeasInitRsp->measureID);
	msgStatusEncHdlr(&pL1CDMeasInitRsp->msgStatus);
	addByteVal(pL1CDMeasInitRsp->rlCount);
	addByteVal(pL1CDMeasInitRsp->rlsCount);

	for(i=0;i<pL1CDMeasInitRsp->rlCount;i++)
	{
		/* Set measInf_present in bit_mask */
		dMeasRlInfEncHdlr(&pL1CDMeasInitRsp->pRLInf[i]);
	}
	
	for(i=0;i<pL1CDMeasInitRsp->rlsCount;i++)
	{
		dMeasRlInfEncHdlr(&pL1CDMeasInitRsp->pRLSInf[i]);
	}
}

void dedicatedMeasReportProcEncHdlr(L1CAPI_Dedicated_Meas_Report *pL1CDMeasReport)
{
	uint8_t i;
	addLongVal(pL1CDMeasReport->measureID);
	addByteVal(pL1CDMeasReport->rlCount);
	addByteVal(pL1CDMeasReport->rlsCount);

	for(i=0;i<pL1CDMeasReport->rlCount;i++)
	{
		dMeasRlInfEncHdlr(&pL1CDMeasReport->pRLInf[i]);
	}
	
	for(i=0;i<pL1CDMeasReport->rlsCount;i++)
	{
		dMeasRlInfEncHdlr(&pL1CDMeasReport->pRLSInf[i]);
	}
}

void dedicatedMeasFailIndicationProcEncHdlr(L1CAPI_Dedicated_Meas_Fail_Ind *pL1CDMeasFailInd)
{	
	uint8_t i;
	addLongVal(pL1CDMeasFailInd->measureID);
	addByteVal(pL1CDMeasFailInd->rlCount);
	for(i=0;i<pL1CDMeasFailInd->rlCount;i++)
	{
		addByteVal(pL1CDMeasFailInd->pRl_ID[i]);
	}	
	msgStatusEncHdlr(&pL1CDMeasFailInd->msgStatus);
}
