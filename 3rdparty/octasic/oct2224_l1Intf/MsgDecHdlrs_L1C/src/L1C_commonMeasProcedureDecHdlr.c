/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_commonMeasProcedureDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Common Measurement Procedures Host L1API Message Decoding Routines

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "l1capi_datastruct.h"
#include "msgGetPrimitives.h"
#include "L1C_commonMeasProcedureDecHdlr.h"

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

void commonMeasInitRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
	L1CAPI_Common_Meas_Init_Request *pL1CMeasInitReq = 
      (L1CAPI_Common_Meas_Init_Request *)allocMem(sizeof(L1CAPI_Common_Meas_Init_Request),0);
	
	pL1CMeasInitReq->bit_mask = subByteVal();
	pL1CMeasInitReq->measureID = subLongVal();
	
	if (pL1CMeasInitReq->bit_mask & cMeasInitReq_cellObjInf_present)
	{
		pL1CMeasInitReq->cellObjInf.cId = subWordVal();
	}
	
	if (pL1CMeasInitReq->bit_mask & cMeasInitReq_rachObjInf_present)
	{
		pL1CMeasInitReq->rachObjInf.cId = subWordVal();
		pL1CMeasInitReq->rachObjInf.commonTransportChannelID = subByteVal();
	}
	
	pL1CMeasInitReq->measType = subByteVal();
	
	if (pL1CMeasInitReq->bit_mask & cMeasInitReq_filterCoeff_present)
	{
		pL1CMeasInitReq->filterCoeff = subByteVal();
	}
	
	measReportInfoProcDecHdlr(msgStatus, &pL1CMeasInitReq->reportInf);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
	
	pL1CMeasInitReq->sfnReportInd = subByteVal();
	
	if (pL1CMeasInitReq->bit_mask & cMeasInitReq_sfn_present)
	{
		pL1CMeasInitReq->sfn = subWordVal();
	}
	
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
	
    return;
}

void commonMeasTermRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
	L1CAPI_Common_Meas_Term_Request *pL1CMeasTermReq = 
      (L1CAPI_Common_Meas_Term_Request *)allocMem(sizeof(L1CAPI_Common_Meas_Term_Request),0);
	
	pL1CMeasTermReq->measureID = subLongVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}
