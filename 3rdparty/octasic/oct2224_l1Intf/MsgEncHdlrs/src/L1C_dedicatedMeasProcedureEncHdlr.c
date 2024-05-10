/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_dedicatedMeasProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Dedicated Measurement Procedures Encode Handler

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

static void measReportInfProcEncHdlr(L1CAPI_Msg_Status *msgStatus, void * pSrc)
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

void dedicatedMeasInitRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Dedicated_Meas_Init_Request * pL1CMeasInitReq;
    uint8_t i;
	
    pL1CMeasInitReq = (L1CAPI_Dedicated_Meas_Init_Request *)pHostDLMsg;
    PRINTF("L23--> Dedicated Measurement Initiation Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMeasInitReq->bit_mask);
    ADD_BYTE_VAL(pL1CMeasInitReq->NodeBComContext);
    ADD_LONG_VAL(pL1CMeasInitReq->measureID);
    ADD_BYTE_VAL(pL1CMeasInitReq->rlCount);
    ADD_BYTE_VAL(pL1CMeasInitReq->rlsCount);
	
    if (pL1CMeasInitReq->bit_mask & dMeasInitReq_pRl_ID_present)
    {
        for (i=0; i<pL1CMeasInitReq->rlCount; i++)
        {
            ADD_BYTE_VAL(pL1CMeasInitReq->pRl_ID[i]);
        }
    }
    if (pL1CMeasInitReq->bit_mask & dMeasInitReq_pRls_ID_present)
    {
        for (i=0; i<pL1CMeasInitReq->rlsCount; i++)
        {
            ADD_BYTE_VAL(pL1CMeasInitReq->pRls_ID[i]);
        }
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
	
    ADD_BYTE_VAL(pL1CMeasInitReq->cfnReportInd);
    if (pL1CMeasInitReq->bit_mask & dMeasInitReq_cfn_present)
    {
        ADD_BYTE_VAL(pL1CMeasInitReq->cfn);
    }
	
END_BLOCK_TRACE    

    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    return;
}


void dedicatedMeasTermRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Dedicated_Meas_Term_Request * pL1CMeasTermReq;
    pL1CMeasTermReq = (L1CAPI_Dedicated_Meas_Term_Request *)pHostDLMsg;

PRINTF("L23--> Dedicated Measurement Termination Request \n");

START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CMeasTermReq->NodeBComContext);
    ADD_LONG_VAL(pL1CMeasTermReq->measureID);    
END_BLOCK_TRACE
	
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
  return;
} 
