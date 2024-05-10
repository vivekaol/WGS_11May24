/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_dedicatedMeasProcedureDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Dedicated Measurement Procedures Host L1API Message Decoding Routines

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "l1capi_datastruct.h"
#include "msgGetPrimitives.h"
#include "L1C_dedicatedMeasProcedureDecHdlr.h"

static void measPeriodicRepCfgProcDecHdlr(L1CAPI_Msg_Status *msgStatus, 
										  L1CAPI_MeasPeriodicRepCfg *pPeriodicRepCfg)
{
	pPeriodicRepCfg->scale = subByteVal();
	pPeriodicRepCfg->repFreq = subWordVal(); 
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void measReportInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_MeasReportInf *pReportInf)
{	
    pReportInf->reportMode = subByteVal();
	if (pReportInf->reportMode==L1CAPI_MEAS_PERIODIC)
	{
		measPeriodicRepCfgProcDecHdlr(msgStatus, &pReportInf->periodicRepCfg);
		if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		{
			return;
		}
	}
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;

}

/****************************Main Interface to OP ***************/

void dedicatedMeasInitRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t i;
	L1CAPI_Dedicated_Meas_Init_Request *pL1CMeasInitReq = 
      (L1CAPI_Dedicated_Meas_Init_Request *)allocMem(sizeof(L1CAPI_Dedicated_Meas_Init_Request),0);
	
	pL1CMeasInitReq->bit_mask = subByteVal();
	pL1CMeasInitReq->NodeBComContext = subByteVal();
	pL1CMeasInitReq->measureID = subLongVal();
	
	pL1CMeasInitReq->rlCount = subByteVal();
	pL1CMeasInitReq->rlsCount = subByteVal();
	
	if (pL1CMeasInitReq->bit_mask & dMeasInitReq_pRl_ID_present)
	{
		if (pL1CMeasInitReq->rlCount!=0)
		{
			pL1CMeasInitReq->pRl_ID = \
				(L1CAPI_Radiolink_ID*)allocMem(sizeof(L1CAPI_Radiolink_ID)*pL1CMeasInitReq->rlCount,0);
			
			for (i=0; i<pL1CMeasInitReq->rlCount; i++)
			{
				pL1CMeasInitReq->pRl_ID[i] = subByteVal();
			}
		}
	}
	
	if (pL1CMeasInitReq->bit_mask & dMeasInitReq_pRls_ID_present)
	{
		if (pL1CMeasInitReq->rlsCount!=0)
		{
			pL1CMeasInitReq->pRl_ID = \
				(L1CAPI_Radiolink_Set_ID*)allocMem(sizeof(L1CAPI_Radiolink_Set_ID)*pL1CMeasInitReq->rlsCount,0);
			
			for (i=0; i<pL1CMeasInitReq->rlCount; i++)
			{
				pL1CMeasInitReq->pRl_ID[i] = subByteVal();
			}
		}
	}
	
	/* pRls_ID, allRl and allRls are not supported */
	 
	
	pL1CMeasInitReq->measType = subByteVal();
	
	if (pL1CMeasInitReq->bit_mask & dMeasInitReq_filterCoeff_present)
	{
		pL1CMeasInitReq->filterCoeff = subByteVal();
	}
	
	measReportInfoProcDecHdlr(msgStatus, &pL1CMeasInitReq->reportInf);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
	
	pL1CMeasInitReq->cfnReportInd = subByteVal();
	
	if (pL1CMeasInitReq->bit_mask & dMeasInitReq_cfn_present)
	{
		pL1CMeasInitReq->cfn = subByteVal();
	}
	
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
	
    return;
}

void dedicatedMeasTermRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
	L1CAPI_Dedicated_Meas_Term_Request *pL1CMeasTermReq = 
      (L1CAPI_Dedicated_Meas_Term_Request *)allocMem(sizeof(L1CAPI_Dedicated_Meas_Term_Request),0);
	
	pL1CMeasTermReq->NodeBComContext = subByteVal();
	pL1CMeasTermReq->measureID = subLongVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}
