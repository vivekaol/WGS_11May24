/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_responseProcDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Response Procedure Decode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include "L1C_responseProcDecHdlr.h"
#include "l1capi_datastruct.h"
#include "msgGetPrimitives.h"


static void msgStatusDecHdlr(void * pDst)
{
    L1CAPI_Msg_Status *pMsgStatus = (L1CAPI_Msg_Status *)pDst;
START_BLOCK_TRACE
	SUB_WORD_VAL(pMsgStatus->l1MsgResult);
    if(pMsgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      SUB_LONG_VAL(pMsgStatus->additionalInfo0);
      SUB_LONG_VAL(pMsgStatus->additionalInfo1);
    }
END_BLOCK_TRACE

}

static void cordTrchInfoRspDecHdlr(void * pDst)
{
    L1CAPI_CoordTrchRespItem *pCordTrchInfo = (L1CAPI_CoordTrchRespItem *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pCordTrchInfo->dchId);
    SUB_LONG_VAL(pCordTrchInfo->binding_id);    
END_BLOCK_TRACE

}

static void edchMacDFlowInfoRspDecHdlr(void * pDst)
{
    L1CAPI_Edch_MacD_Flow_Info_resp * pEdchMacDFlowInfo = (L1CAPI_Edch_MacD_Flow_Info_resp *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pEdchMacDFlowInfo->bit_mask);
    SUB_BYTE_VAL(pEdchMacDFlowInfo->e_DCH_MACdFlow_ID);
    SUB_LONG_VAL(pEdchMacDFlowInfo->binding_id);
	if(pEdchMacDFlowInfo->bit_mask & edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present){
      SUB_BYTE_VAL(pEdchMacDFlowInfo->harqProcAlloc2ms_SchedTxGrant);
    }
END_BLOCK_TRACE

}

static void edchFddCtrlChInfoDecHdlr(void * pDst)
{
    L1CAPI_Edch_Fdd_Ctrl_Channel_Info *pCtrlChInfo = (L1CAPI_Edch_Fdd_Ctrl_Channel_Info *)pDst;
START_BLOCK_TRACE
    SUB_WORD_VAL(pCtrlChInfo->bit_mask);
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eAgchRgchHichScramCode_present)
    {
      SUB_BYTE_VAL(pCtrlChInfo->eAgchRgchHichScramCode);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eAgchChanCode_present)
    {
      SUB_WORD_VAL(pCtrlChInfo->eAgchChanCode);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_primaryErnti_present)
    {
      SUB_WORD_VAL(pCtrlChInfo->primaryErnti);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_secondaryErnti_present)
    {
      SUB_WORD_VAL(pCtrlChInfo->secondaryErnti);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchHichChanCode_present)
    {
      SUB_WORD_VAL(pCtrlChInfo->eRgchHichChanCode);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchSignatureSeq_present)
    {
      SUB_BYTE_VAL(pCtrlChInfo->eRgchSignatureSeq);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eHichSignatureSeq_present)
    {
      SUB_BYTE_VAL(pCtrlChInfo->eHichSignatureSeq);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_servingGrantVal_present)
    {
      SUB_BYTE_VAL(pCtrlChInfo->servingGrantVal);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_priSecGrantSelector_present)
    {
      SUB_BYTE_VAL(pCtrlChInfo->priSecGrantSelector);
    }
    if(pCtrlChInfo->bit_mask & eDch_Ch_Info_eRgchReleaseInd_present)
    {
      SUB_BYTE_VAL(pCtrlChInfo->eRgchReleaseInd);
    }
END_BLOCK_TRACE


}

static void edchFddInfoRspDecHdlr(void * pDst)
{
    uint8_t i;
    void * pEdchMacDFlowInfo;
    void * pEdchFddChInfo;

    L1CAPI_Edch_Fdd_Info_Resp * pEdchFddInfoRsp = (L1CAPI_Edch_Fdd_Info_Resp *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pEdchFddInfoRsp->bit_mask);
    if(pEdchFddInfoRsp->bit_mask & edchRlSetId_present){
      SUB_BYTE_VAL(pEdchFddInfoRsp->edchRlSetId);
    }
    if(pEdchFddInfoRsp->bit_mask & edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present){
      SUB_BYTE_VAL(pEdchFddInfoRsp->harqProcAlloc2ms_SchedTxGrant);
    }
    SUB_BYTE_VAL(pEdchFddInfoRsp->mAcdFlowCount);
    pEdchFddInfoRsp->ptrEdchMacdFlowInfoResp = 
      (L1CAPI_Edch_MacD_Flow_Info_resp *)allocMem(sizeof(L1CAPI_Edch_MacD_Flow_Info_resp) * pEdchFddInfoRsp->mAcdFlowCount,0);

    for(i=0;i<pEdchFddInfoRsp->mAcdFlowCount;i++)
    {
      pEdchMacDFlowInfo = &(pEdchFddInfoRsp->ptrEdchMacdFlowInfoResp[i]);
      edchMacDFlowInfoRspDecHdlr(pEdchMacDFlowInfo);
    }
    if(pEdchFddInfoRsp->bit_mask & edchFddCtrlChanInfo_present){
      pEdchFddInfoRsp->ptrEdchFddCtrlChanInfo = (L1CAPI_Edch_Fdd_Ctrl_Channel_Info *)allocMem(sizeof(L1CAPI_Edch_Fdd_Ctrl_Channel_Info),0);
      pEdchFddChInfo = pEdchFddInfoRsp->ptrEdchFddCtrlChanInfo;
      edchFddCtrlChInfoDecHdlr(pEdchFddChInfo);
	}
END_BLOCK_TRACE
}


static void radiolinkInfoRspDecHdlr(void * pDst)
{
    uint8_t i;
    void * pCordTrchRspInfo;
    void * pEdchRspInfo;
    L1CAPI_Radiolink_Info_Resp * pRlInfoRsp = (L1CAPI_Radiolink_Info_Resp *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pRlInfoRsp->bit_mask);
    SUB_BYTE_VAL(pRlInfoRsp->coordTrchCount);
    SUB_BYTE_VAL(pRlInfoRsp->rL_ID);
    SUB_BYTE_VAL(pRlInfoRsp->rlSetId);
    SUB_BYTE_VAL(pRlInfoRsp->referenceRlId);

    if (0 != pRlInfoRsp->coordTrchCount)
    {
        pRlInfoRsp->ptrCoordTrchRsp = 
             (L1CAPI_CoordTrchRespItem *)malloc(sizeof(L1CAPI_CoordTrchRespItem) * pRlInfoRsp->coordTrchCount);
    }

    if(pRlInfoRsp->bit_mask & edchFddInfoRsp_present){
      pRlInfoRsp->ptrEdchFddInfoRsp = 
        (L1CAPI_Edch_Fdd_Info_Resp *)malloc(sizeof(L1CAPI_Edch_Fdd_Info_Resp));
    }
    pEdchRspInfo = pRlInfoRsp->ptrEdchFddInfoRsp;
    for(i=0;i<pRlInfoRsp->coordTrchCount;i++)
    {
      pCordTrchRspInfo = &(pRlInfoRsp->ptrCoordTrchRsp[i]);
      cordTrchInfoRspDecHdlr(pCordTrchRspInfo);
    }
    if(pRlInfoRsp->bit_mask & edchFddInfoRsp_present)
    {
      edchFddInfoRspDecHdlr(pEdchRspInfo);
    }
END_BLOCK_TRACE
}
static void hsMacDFlowInfoRspDecHdlr(void * pDst)
{
    L1CAPI_MacDFlow_Info_Resp *pHsMacDFlowInfo = (L1CAPI_MacDFlow_Info_Resp *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pHsMacDFlowInfo->macDFlowId);
    SUB_LONG_VAL(pHsMacDFlowInfo->bindingId);
END_BLOCK_TRACE

}

static void harqMemExpInfoDecHdlr(void * pDst)
{
    uint8_t i;
    L1CAPI_Harq_Process_Memory_Size harqMemSize;

    L1CAPI_HarqMem_Partitioning_Explicit * pExpInfo = (L1CAPI_HarqMem_Partitioning_Explicit *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pExpInfo->nrOfProcess);
    pExpInfo->ptrProcessMemSize = 
      (L1CAPI_Harq_Process_Memory_Size *)allocMem(sizeof(L1CAPI_Harq_Process_Memory_Size) * pExpInfo->nrOfProcess,0);
    for(i=0;i<pExpInfo->nrOfProcess;i++)
    {
       SUB_BYTE_VAL(harqMemSize);
       pExpInfo->ptrProcessMemSize[i] = harqMemSize;
	
    }
END_BLOCK_TRACE
}

static void hsDschInfoRspDecHdlr(void * pDst)
{
    uint8_t i;
    void * pMacDFlowInfo;
    void * pHardMemExpInfo;
    L1CAPI_DL_ChannelCodeNumber dlCodeNr;

    L1CAPI_HSDSCH_Info_Resp * pHsdschInfoRsp = (L1CAPI_HSDSCH_Info_Resp *)pDst;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pHsdschInfoRsp->harqMemChoice);
    SUB_BYTE_VAL(pHsdschInfoRsp->macDFlowCount);
    SUB_BYTE_VAL(pHsdschInfoRsp->hsscchCodeCount);

#if 0
	pHsdschInfoRsp->ptrMacDFlowInfo 
      = (L1CAPI_MacDFlow_Info_Resp *)allocMem(sizeof(L1CAPI_MacDFlow_Info_Resp) * pHsdschInfoRsp->macDFlowCount,0);
#else
	pHsdschInfoRsp->ptrMacDFlowInfo 
      = (L1CAPI_MacDFlow_Info_Resp *)malloc(sizeof(L1CAPI_MacDFlow_Info_Resp) * pHsdschInfoRsp->macDFlowCount);
#endif
#if 0
	pHsdschInfoRsp->ptrHsscchInfoResp
      = (L1CAPI_DL_ChannelCodeNumber *)allocMem(sizeof(L1CAPI_DL_ChannelCodeNumber) * pHsdschInfoRsp->hsscchCodeCount,0);
#else
	pHsdschInfoRsp->ptrHsscchInfoResp
      = (L1CAPI_DL_ChannelCodeNumber *)malloc(sizeof(L1CAPI_DL_ChannelCodeNumber) * pHsdschInfoRsp->hsscchCodeCount);
#endif

    for(i=0;i<pHsdschInfoRsp->macDFlowCount;i++)
    {
      pMacDFlowInfo = &(pHsdschInfoRsp->ptrMacDFlowInfo[i]);
      hsMacDFlowInfoRspDecHdlr(pMacDFlowInfo);
    }
    for(i=0;i<pHsdschInfoRsp->hsscchCodeCount;i++)
    {
      dlCodeNr = subWordVal();
	  pHsdschInfoRsp->ptrHsscchInfoResp[i] = dlCodeNr;
    }
	if(pHsdschInfoRsp->harqMemChoice == L1CAPI_HARQ_MEM_IMPLICIT){
      pHsdschInfoRsp->u.harqMemImplicit.nrOfProcess = subByteVal();

    }
	else{
      pHardMemExpInfo = &(pHsdschInfoRsp->u.HarqMemExplicit);
      harqMemExpInfoDecHdlr(pHardMemExpInfo);
    }
END_BLOCK_TRACE
}


/******************************************************
     Generic Response procedure interface
*******************************************************/

void genericResponseProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Generic_Response * pL1CGenRsp = NULL;
    void * pMsgStatus;

#if 0
    pL1CGenRsp = (L1CAPI_Generic_Response *)allocMem(sizeof(L1CAPI_Generic_Response),0);
#else
    pL1CGenRsp = (L1CAPI_Generic_Response *)malloc(sizeof(L1CAPI_Generic_Response));
#endif
    pHostUlMsg = pL1CGenRsp;
    pMsgStatus = &(pL1CGenRsp->msgStatus);
PRINTF("L23<-- Generic Response \n");
START_BLOCK_TRACE
    SUB_BYTE_VAL(pL1CGenRsp->associatedMsg);

    msgStatusDecHdlr(pMsgStatus);
END_BLOCK_TRACE
}

void genericResponseProcDecCommit ( ProcedureStatus_e procStatus  )
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


/******************************************************
     Prach Setup Response procedure interface
*******************************************************/
void cmnTrchPrachSetupResponseProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    void * pMsgStatus;
	
    L1CAPI_Prach_Setup_Response * pL1CPrachSetupRsp = (L1CAPI_Prach_Setup_Response *)allocMem(sizeof(L1CAPI_Prach_Setup_Response),0);
    pHostUlMsg = pL1CPrachSetupRsp;
    pMsgStatus = &(pL1CPrachSetupRsp->msgStatus);
PRINTF("L23<-- Prach Setup Response \n");
START_BLOCK_TRACE
    SUB_LONG_VAL(pL1CPrachSetupRsp->rAch_binding_id);

    msgStatusDecHdlr(pMsgStatus);
END_BLOCK_TRACE
}

void cmnTrchPrachSetupResponseProcDecCommit ( ProcedureStatus_e procStatus  )
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

/******************************************************
     Sccpch Setup Response procedure interface
*******************************************************/
void cmnTrchSccpchSetupResponseProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Sccpch_Setup_Response  * pL1CSccpchSetupRsp = NULL;
    void * pMsgStatus;
    L1CAPI_BINDING_ID bindingId;
    uint8_t i;

#if 0
    pL1CSccpchSetupRsp = (L1CAPI_Sccpch_Setup_Response *)allocMem(sizeof(L1CAPI_Sccpch_Setup_Response),0);
#else
    pL1CSccpchSetupRsp = (L1CAPI_Sccpch_Setup_Response *)malloc(sizeof(L1CAPI_Sccpch_Setup_Response));
#endif
    pHostUlMsg = pL1CSccpchSetupRsp;
    pMsgStatus = &(pL1CSccpchSetupRsp->msgStatus);
PRINTF("L23<-- Sccpch Setup Response \n");    
START_BLOCK_TRACE
    SUB_BYTE_VAL(pL1CSccpchSetupRsp->bit_mask);    
	SUB_BYTE_VAL(pL1CSccpchSetupRsp->n_FACH);
#if 0
    pL1CSccpchSetupRsp->ptrFACH_binding_id = 
      (L1CAPI_BINDING_ID *)allocMem(sizeof(L1CAPI_BINDING_ID) * pL1CSccpchSetupRsp->n_FACH,0);
#else
    pL1CSccpchSetupRsp->ptrFACH_binding_id = 
      (L1CAPI_BINDING_ID *)malloc(sizeof(L1CAPI_BINDING_ID) * pL1CSccpchSetupRsp->n_FACH);
#endif

    for(i=0;i<pL1CSccpchSetupRsp->n_FACH;i++)
    {
      SUB_LONG_VAL(bindingId);
      pL1CSccpchSetupRsp->ptrFACH_binding_id[i] = bindingId;

    }
    if(pL1CSccpchSetupRsp->bit_mask & pchBindingId_present)
    {
      SUB_LONG_VAL(bindingId);
      pL1CSccpchSetupRsp->pCH_binding_id = bindingId;      
    }
    msgStatusDecHdlr(pMsgStatus);
END_BLOCK_TRACE
}

void cmnTrchSccpchSetupResponseProcDecCommit ( ProcedureStatus_e procStatus  )
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

static void measInfDecHdlr(void *pDst)
{
	L1CAPI_MeasInf *pL1CMeasInf = (L1CAPI_MeasInf*)pDst;

START_BLOCK_TRACE	
	SUB_BYTE_VAL(pL1CMeasInf->measType);
	SUB_WORD_VAL(pL1CMeasInf->measValue);
END_BLOCK_TRACE

}

/******************************************************************
     Common Measurement Initiation Response procedure interface
******************************************************************/
void commonMeasInitResponseProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Common_Meas_Init_Response  * pL1CCMeasInitRsp = NULL;

    pL1CCMeasInitRsp = (L1CAPI_Common_Meas_Init_Response *)allocMem(sizeof(L1CAPI_Common_Meas_Init_Response),0);
    pHostUlMsg = pL1CCMeasInitRsp;

PRINTF("L23<-- Common Measurement Initiation Response \n");    
START_BLOCK_TRACE
    SUB_BYTE_VAL(pL1CCMeasInitRsp->bit_mask);    
	SUB_LONG_VAL(pL1CCMeasInitRsp->measureID);
	
	msgStatusDecHdlr(&(pL1CCMeasInitRsp->msgStatus));

	if (pL1CCMeasInitRsp->bit_mask & cMeasInitResp_cellObjMeasInf_present)
	{
		measInfDecHdlr(&pL1CCMeasInitRsp->cellObjMeasInf);
	}
	
	if (pL1CCMeasInitRsp->bit_mask & cMeasInitResp_rachObjMeasInf_present)
	{
		measInfDecHdlr(&pL1CCMeasInitRsp->rachObjMeasInf);
	}

	if (pL1CCMeasInitRsp->bit_mask & cMeasInitResp_sfn_present)
	{
		SUB_WORD_VAL(pL1CCMeasInitRsp->sfn);
	}

END_BLOCK_TRACE
}

/******************************************************************
     Common Measurement Report procedure interface
******************************************************************/
void commonMeasReportProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Common_Meas_Report  * pL1CCMeasReport = NULL;

    pL1CCMeasReport = (L1CAPI_Common_Meas_Report *)allocMem(sizeof(L1CAPI_Common_Meas_Report),0);
    pHostUlMsg = pL1CCMeasReport;

PRINTF("L23<-- Common Measurement Report \n");    
START_BLOCK_TRACE
    SUB_BYTE_VAL(pL1CCMeasReport->bit_mask);    
	SUB_LONG_VAL(pL1CCMeasReport->measureID);
	
	if (pL1CCMeasReport->bit_mask & cMeasRep_cellObjMeasInf_present)
	{
		measInfDecHdlr(&pL1CCMeasReport->cellObjMeasInf);
	}
	
	if (pL1CCMeasReport->bit_mask & cMeasRep_rachObjMeasInf_present)
	{
		measInfDecHdlr(&pL1CCMeasReport->rachObjMeasInf);
	}

	if (pL1CCMeasReport->bit_mask & cMeasRep_sfn_present)
	{
		SUB_WORD_VAL(pL1CCMeasReport->sfn);
	}

END_BLOCK_TRACE
}

/******************************************************************
     Common Measurement Failure Indication procedure interface
******************************************************************/
void commonMeasFailIndicationProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Common_Meas_Fail_Ind  * pL1CCMeasFailInd = NULL;

    pL1CCMeasFailInd = (L1CAPI_Common_Meas_Fail_Ind *)allocMem(sizeof(L1CAPI_Common_Meas_Fail_Ind),0);
    pHostUlMsg = pL1CCMeasFailInd;

PRINTF("L23<-- Common Measurement Failure Indication \n");    
START_BLOCK_TRACE
    SUB_LONG_VAL(pL1CCMeasFailInd->measureID);
	msgStatusDecHdlr(&pL1CCMeasFailInd->msgStatus);
END_BLOCK_TRACE
}

static void dedicatedMeasRlInfDecHdlr(void*pDst)
{
	L1CAPI_DMeasRl_Info *pRLInfo = (L1CAPI_DMeasRl_Info *)pDst;

START_BLOCK_TRACE	

	SUB_BYTE_VAL(pRLInfo->bit_mask);
	SUB_BYTE_VAL(pRLInfo->rL_ID);
	
	if (pRLInfo->bit_mask & dMeasRlInf_measInf_present)
	{
		measInfDecHdlr(&pRLInfo->measInf);
	
		if (pRLInfo->bit_mask & dMeasRlInf_cfn_present)
		{
			SUB_BYTE_VAL(pRLInfo->cfn);
		}
	}

END_BLOCK_TRACE
}

/******************************************************************
     Dedicated Measurement Initiation Response procedure interface
******************************************************************/
void dedicatedMeasInitResponseProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Dedicated_Meas_Init_Response  * pL1CCMeasInitRsp = NULL;
	uint8_t i;

    pL1CCMeasInitRsp = (L1CAPI_Dedicated_Meas_Init_Response *)malloc(sizeof(L1CAPI_Dedicated_Meas_Init_Response));
    pHostUlMsg = pL1CCMeasInitRsp;
PRINTF("L23<-- Dedicated Measurement Initiation Response \n");    
START_BLOCK_TRACE
    SUB_LONG_VAL(pL1CCMeasInitRsp->measureID);	
	msgStatusDecHdlr(&pL1CCMeasInitRsp->msgStatus);
	SUB_BYTE_VAL(pL1CCMeasInitRsp->rlCount);
	SUB_BYTE_VAL(pL1CCMeasInitRsp->rlsCount);

	if (pL1CCMeasInitRsp->rlCount!=0)
	{
		pL1CCMeasInitRsp->pRLInf = (L1CAPI_DMeasRl_Info *)malloc(sizeof(L1CAPI_DMeasRl_Info)*pL1CCMeasInitRsp->rlCount);
	
		for (i=0; i<pL1CCMeasInitRsp->rlCount; i++)
		{
			dedicatedMeasRlInfDecHdlr(&pL1CCMeasInitRsp->pRLInf[i]);		
		}
	}
	
	if (pL1CCMeasInitRsp->rlsCount!=0)
	{
		pL1CCMeasInitRsp->pRLSInf = (L1CAPI_DMeasRl_Info *)malloc(sizeof(L1CAPI_DMeasRl_Info)*pL1CCMeasInitRsp->rlsCount);
	
		for (i=0; i<pL1CCMeasInitRsp->rlsCount; i++)
		{
			dedicatedMeasRlInfDecHdlr(&pL1CCMeasInitRsp->pRLSInf[i]);
		}
	}

END_BLOCK_TRACE
}

/******************************************************************
     Dedicated Measurement Report procedure interface
******************************************************************/
void dedicatedMeasReportProcDecHdlr(L1MsgStatus_t *msgStatus)
{
    L1CAPI_Dedicated_Meas_Report  * pL1CCMeasReport = NULL;
	uint8_t i;

    pL1CCMeasReport = (L1CAPI_Dedicated_Meas_Report *)malloc(sizeof(L1CAPI_Dedicated_Meas_Report));
    pHostUlMsg = pL1CCMeasReport;
PRINTF("L23<-- Dedicated Measurement Report \n");    
START_BLOCK_TRACE
	SUB_LONG_VAL(pL1CCMeasReport->measureID);	
	SUB_BYTE_VAL(pL1CCMeasReport->rlCount);
	SUB_BYTE_VAL(pL1CCMeasReport->rlsCount);

	if (pL1CCMeasReport->rlCount!=0)
	{
		pL1CCMeasReport->pRLInf = (L1CAPI_DMeasRl_Info *)malloc(sizeof(L1CAPI_DMeasRl_Info)*pL1CCMeasReport->rlCount);
	
		for (i=0; i<pL1CCMeasReport->rlCount; i++)
		{
			dedicatedMeasRlInfDecHdlr(&pL1CCMeasReport->pRLInf[i]);
		}
	}
	
	if (pL1CCMeasReport->rlsCount!=0)
	{
		pL1CCMeasReport->pRLSInf = (L1CAPI_DMeasRl_Info *)malloc(sizeof(L1CAPI_DMeasRl_Info)*pL1CCMeasReport->rlsCount);
	
		for (i=0; i<pL1CCMeasReport->rlsCount; i++)
		{
			dedicatedMeasRlInfDecHdlr(&pL1CCMeasReport->pRLSInf[i]);
		}
	}

END_BLOCK_TRACE
}

/******************************************************************
     Dedicated Measurement Fail Indication procedure interface
******************************************************************/
void dedicatedMeasFailIndicationProcDecHdlr(L1MsgStatus_t *msgStatus)
{
    L1CAPI_Dedicated_Meas_Fail_Ind  * pL1CDMeasFailInd = NULL;
	uint8_t i;

    pL1CDMeasFailInd = (L1CAPI_Dedicated_Meas_Fail_Ind *)malloc(sizeof(L1CAPI_Dedicated_Meas_Fail_Ind));
    pHostUlMsg = pL1CDMeasFailInd;
PRINTF("L23<-- Dedicated Measurement Failure Indication \n");    
START_BLOCK_TRACE

	SUB_LONG_VAL(pL1CDMeasFailInd->measureID);
    SUB_BYTE_VAL(pL1CDMeasFailInd->rlCount);
    pL1CDMeasFailInd->pRl_ID = (L1CAPI_Radiolink_ID *)malloc(sizeof(L1CAPI_Radiolink_ID)*pL1CDMeasFailInd->rlCount);
	for(i=0;i<pL1CDMeasFailInd->rlCount;i++)
    {
        SUB_BYTE_VAL(pL1CDMeasFailInd->pRl_ID[i]);
    }
	msgStatusDecHdlr(&pL1CDMeasFailInd->msgStatus);

END_BLOCK_TRACE	
}


/******************************************************
    radio link setup response procedure interface
*******************************************************/
void radiolinkSetupResponseProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Radiolink_Setup_Response * pRlSetupRsp = NULL;
    uint8_t i;
    void * pMsgStatus;
    void * pRlInfo;
    void * pHsInfo;

#if 0
    pRlSetupRsp = (L1CAPI_Radiolink_Setup_Response *)allocMem(sizeof(L1CAPI_Radiolink_Setup_Response),0);
#else
    pRlSetupRsp = (L1CAPI_Radiolink_Setup_Response *)malloc(sizeof(L1CAPI_Radiolink_Setup_Response));
#endif
    pHostUlMsg = pRlSetupRsp;
    pMsgStatus = &(pRlSetupRsp->msgStatus);
PRINTF("L23<-- Radiolink Setup Response \n");
START_BLOCK_TRACE
    SUB_BYTE_VAL(pRlSetupRsp->bit_mask);
    SUB_BYTE_VAL(pRlSetupRsp->NodeBComContext);
    SUB_BYTE_VAL(pRlSetupRsp->rlCount);

#if 0
    pRlSetupRsp->ptrRlInfoResp = (L1CAPI_Radiolink_Info_Resp *)allocMem(sizeof(L1CAPI_Radiolink_Info_Resp) * pRlSetupRsp->rlCount,0);
#else
    pRlSetupRsp->ptrRlInfoResp = (L1CAPI_Radiolink_Info_Resp *)malloc(sizeof(L1CAPI_Radiolink_Info_Resp) * pRlSetupRsp->rlCount);
#endif

    msgStatusDecHdlr(pMsgStatus);

	for(i=0;i<pRlSetupRsp->rlCount;i++){
      pRlInfo = &(pRlSetupRsp->ptrRlInfoResp[i]);
      radiolinkInfoRspDecHdlr(pRlInfo);
    }
    if(pRlSetupRsp->bit_mask & rl_SetupResp_hsdschInfoResp_present)
    {
#if 0
      pRlSetupRsp->ptrHsdschInfoResp = (L1CAPI_HSDSCH_Info_Resp *)allocMem(sizeof(L1CAPI_HSDSCH_Info_Resp),0);
#else
      pRlSetupRsp->ptrHsdschInfoResp = (L1CAPI_HSDSCH_Info_Resp *)malloc(sizeof(L1CAPI_HSDSCH_Info_Resp));
#endif
      pHsInfo = pRlSetupRsp->ptrHsdschInfoResp;
      hsDschInfoRspDecHdlr(pHsInfo);
    }
END_BLOCK_TRACE
}

void radiolinkSetupResponseProcDecCommit ( ProcedureStatus_e procStatus  )
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

/******************************************************
    radio link reconfig ready procedure interface
*******************************************************/
void radiolinkReconfigReadyProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Radiolink_Reconfigure_Ready * pRlReconfigRdy = NULL;
    uint8_t i;
    void * pMsgStatus;
    void * pRlInfo;
    void * pHsInfo;
    /*R6 EDCH support*/
   // #ifdef L1C_SUPPORT_EDCH
     void *pEdchInfo; 
    //#endif

#if 0
    pRlReconfigRdy = (L1CAPI_Radiolink_Reconfigure_Ready *)allocMem(sizeof(L1CAPI_Radiolink_Reconfigure_Ready),0);
#else
    pRlReconfigRdy = (L1CAPI_Radiolink_Reconfigure_Ready *)malloc(sizeof(L1CAPI_Radiolink_Reconfigure_Ready));
#endif

    pHostUlMsg = pRlReconfigRdy;
    pMsgStatus = &(pRlReconfigRdy->msgStatus);
PRINTF("L23<-- Radiolink Reconfiguration Ready \n");
START_BLOCK_TRACE
    SUB_BYTE_VAL(pRlReconfigRdy->bit_mask);
    SUB_BYTE_VAL(pRlReconfigRdy->rlCount);

#if 0
    pRlReconfigRdy->ptrRlInfoResp = (L1CAPI_Radiolink_Info_Resp *)allocMem(sizeof(L1CAPI_Radiolink_Info_Resp) * pRlReconfigRdy->rlCount,0);
#else
    pRlReconfigRdy->ptrRlInfoResp = (L1CAPI_Radiolink_Info_Resp *)malloc(sizeof(L1CAPI_Radiolink_Info_Resp) * pRlReconfigRdy->rlCount);
#endif

    msgStatusDecHdlr(pMsgStatus);

	for(i=0;i<pRlReconfigRdy->rlCount;i++){
      pRlInfo = &(pRlReconfigRdy->ptrRlInfoResp[i]);
      radiolinkInfoRspDecHdlr(pRlInfo);
    }
    if(pRlReconfigRdy->bit_mask & rl_ReconfigResp_hsdschInfoResp_present)
    {
#if 0
      pRlReconfigRdy->ptrHsdschInfoResp = (L1CAPI_HSDSCH_Info_Resp *)allocMem(sizeof(L1CAPI_HSDSCH_Info_Resp),0);
#else
      pRlReconfigRdy->ptrHsdschInfoResp = (L1CAPI_HSDSCH_Info_Resp *)malloc(sizeof(L1CAPI_HSDSCH_Info_Resp));
#endif
      pHsInfo = pRlReconfigRdy->ptrHsdschInfoResp;
      hsDschInfoRspDecHdlr(pHsInfo);
    }
END_BLOCK_TRACE  
}

void radiolinkReconfigReadyProcDecCommit ( ProcedureStatus_e procStatus  )
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

void radiolinkFailureIndicationProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Radiolink_Failure_Ind * pRlFailureInd = NULL;
    uint8_t i;
    
#if 0
    pRlFailureInd = (L1CAPI_Radiolink_Failure_Ind *)allocMem(sizeof(L1CAPI_Radiolink_Failure_Ind),0);
#else
    pRlFailureInd = (L1CAPI_Radiolink_Failure_Ind *)malloc(sizeof(L1CAPI_Radiolink_Failure_Ind));
#endif

    pHostUlMsg = pRlFailureInd;

    
START_BLOCK_TRACE
    SUB_BYTE_VAL(pRlFailureInd->rlCount);
    SUB_BYTE_VAL(pRlFailureInd->rlsCount);
    
    if (pRlFailureInd->rlCount!=0)
    {
#if 0
        pRlFailureInd->pRlFailInf = (L1CAPI_RadioLink_Fail_Info *)allocMem(sizeof(L1CAPI_RadioLink_Fail_Info)*pRlFailureInd->rlCount,0);
        
#else
        pRlFailureInd->pRlFailInf = (L1CAPI_RadioLink_Fail_Info *)malloc(sizeof(L1CAPI_RadioLink_Fail_Info)*pRlFailureInd->rlCount);
#endif
        for (i=0; i<pRlFailureInd->rlCount; i++)
        {
            SUB_BYTE_VAL(pRlFailureInd->pRlFailInf[i].rL_ID);
            SUB_BYTE_VAL(pRlFailureInd->pRlFailInf[i].cause);
        }
    }
        
    if (pRlFailureInd->rlsCount!=0)
    {
#if 0
        pRlFailureInd->pRlsFailInf = (L1CAPI_RadioLinkSet_Fail_Info *)allocMem(sizeof(L1CAPI_RadioLinkSet_Fail_Info)*pRlFailureInd->rlsCount,0);
#else
        pRlFailureInd->pRlsFailInf = (L1CAPI_RadioLinkSet_Fail_Info *)malloc(sizeof(L1CAPI_RadioLinkSet_Fail_Info)*pRlFailureInd->rlsCount);
#endif
        
        for (i=0; i<pRlFailureInd->rlsCount; i++)
        {
            SUB_BYTE_VAL(pRlFailureInd->pRlsFailInf[i].rLS_ID);
            SUB_BYTE_VAL(pRlFailureInd->pRlsFailInf[i].cause);
        }
    }        
END_BLOCK_TRACE  



  return;
}

void radiolinkRestoreIndicationProcDecHdlr( L1MsgStatus_t *msgStatus )
{
    L1CAPI_Radiolink_Restore_Ind * pRlRestoreInd = NULL;
    uint8_t i;
    
    pRlRestoreInd = (L1CAPI_Radiolink_Restore_Ind *)allocMem(sizeof(L1CAPI_Radiolink_Restore_Ind),0);
    pHostUlMsg = pRlRestoreInd;

START_BLOCK_TRACE
    SUB_BYTE_VAL(pRlRestoreInd->rlCount);
    SUB_BYTE_VAL(pRlRestoreInd->rlsCount);
    
    if (pRlRestoreInd->rlCount!=0)
    {
    
        pRlRestoreInd->pRl_ID = (L1CAPI_Radiolink_ID *)allocMem(sizeof(L1CAPI_Radiolink_ID)*pRlRestoreInd->rlCount,0);
        
        for (i=0; i<pRlRestoreInd->rlCount; i++)
        {
            SUB_BYTE_VAL(pRlRestoreInd->pRl_ID[i]);
        }
    }
    
    if (pRlRestoreInd->rlsCount!=0)
    {
    
        pRlRestoreInd->pRls_ID = (L1CAPI_Radiolink_Set_ID *)allocMem(sizeof(L1CAPI_Radiolink_Set_ID)*pRlRestoreInd->rlsCount,0);
        
        for (i=0; i<pRlRestoreInd->rlsCount; i++)
        {
            SUB_BYTE_VAL(pRlRestoreInd->pRls_ID[i]);
        }
    }
        
END_BLOCK_TRACE     


  return;
}
