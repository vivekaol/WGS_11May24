/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_commonMeasProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Common Measurement Procedures Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_commonMeasProcedureEncHdlr.h"
#include "l1capi_datastruct.h"
#include "L1C_commonMeasProcedureParamValidate.h"
#include "msgPutPrimitives.h"



static void measPeriodicRepCfgProcEncHdlr(L1CAPI_Msg_Status *msgStatus, void *pSrc)
{
    L1CAPI_MeasPeriodicRepCfg *pPeriodicRepCfg;
    pPeriodicRepCfg = (L1CAPI_MeasPeriodicRepCfg*)pSrc;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pPeriodicRepCfg->scale);
    ADD_WORD_VAL(pPeriodicRepCfg->repFreq); 
END_BLOCK_TRACE	
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void measReportInfProcEncHdlr(L1CAPI_Msg_Status *msgStatus, void *pSrc)
{	
    L1CAPI_MeasReportInf *pReportInf = (L1CAPI_MeasReportInf*)pSrc;
    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pReportInf->reportMode);
    if (pReportInf->reportMode == L1CAPI_MEAS_PERIODIC)
    {
        measPeriodicRepCfgProcEncHdlr(msgStatus, &pReportInf->periodicRepCfg);
        if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        {
            return;
        }
    }
    
END_BLOCK_TRACE	
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

void commonMeasInitRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus)
{
    L1CAPI_Common_Meas_Init_Request * pL1CMeasInitReq;
    pL1CMeasInitReq = (L1CAPI_Common_Meas_Init_Request *)pHostDLMsg;
    PRINTF("L23--> Common Measurement Initiation Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMeasInitReq->bit_mask);
    ADD_LONG_VAL(pL1CMeasInitReq->measureID);
    
    if (pL1CMeasInitReq->bit_mask & cMeasInitReq_cellObjInf_present)
    {
        ADD_WORD_VAL(pL1CMeasInitReq->cellObjInf.cId);
    }
    if (pL1CMeasInitReq->bit_mask & cMeasInitReq_rachObjInf_present)
    {
        ADD_WORD_VAL(pL1CMeasInitReq->rachObjInf.cId);
        ADD_BYTE_VAL(pL1CMeasInitReq->rachObjInf.commonTransportChannelID);
    }
    
    ADD_BYTE_VAL(pL1CMeasInitReq->measType);
    
    if (pL1CMeasInitReq->bit_mask & cMeasInitReq_filterCoeff_present)
    {
        ADD_BYTE_VAL(pL1CMeasInitReq->filterCoeff);
    }
    
    measReportInfProcEncHdlr(msgStatus, &pL1CMeasInitReq->reportInf);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    
    ADD_BYTE_VAL(pL1CMeasInitReq->sfnReportInd);
    
    if (pL1CMeasInitReq->bit_mask & cMeasInitReq_sfn_present)
    {
        ADD_WORD_VAL(pL1CMeasInitReq->sfn);
    }
    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE    
    return;
} 


void commonMeasTermRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus)
{
    L1CAPI_Common_Meas_Term_Request * pL1CMeasTermReq;
    pL1CMeasTermReq = (L1CAPI_Common_Meas_Term_Request *)pHostDLMsg;

PRINTF("L23--> Common Measurement Termination Request \n");

START_BLOCK_TRACE
    ADD_LONG_VAL(pL1CMeasTermReq->measureID);    
END_BLOCK_TRACE
    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
  return;
} 
