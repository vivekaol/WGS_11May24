/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_responseProcedureEncHdlr.h

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

#ifndef _L1C_RESPONSEPROCEDUREENCHDLR_H_
#define _L1C_RESPONSEPROCEDUREENCHDLR_H_
#include "l1capi_datastruct.h"
#include "msgPutPrimitives.h"

static __inline__ void msgStatusEncHdlr(L1CAPI_Msg_Status *pMsgStatus);
static __inline__ void genericResponseEncHdlr(L1CAPI_Generic_Response * pL1CGenRsp);

static __inline__ void msgStatusEncHdlr(L1CAPI_Msg_Status *pMsgStatus)
{
    addWordVal(pMsgStatus->l1MsgResult);
    if(pMsgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      addLongVal(pMsgStatus->additionalInfo0);
      addLongVal(pMsgStatus->additionalInfo1);
    }
}

static __inline__ void genericResponseEncHdlr(L1CAPI_Generic_Response * pL1CGenRsp)
{
    addByteVal(pL1CGenRsp->associatedMsg);
    msgStatusEncHdlr(&(pL1CGenRsp->msgStatus));
}

void genericResponseEncHdlr(L1CAPI_Generic_Response * pL1CGenRsp);
void sccpchSetupResponseEncHdlr(L1CAPI_Sccpch_Setup_Response * pL1CSccpchSetupRsp);
void prachSetupResponseEncHdlr(L1CAPI_Prach_Setup_Response * pL1CPrachSetupRsp);
void radiolinkSetupResponseEncHdlr(L1CAPI_Radiolink_Setup_Response * pRlSetupRsp);
void radiolinkReconfigReadyEncHdlr(L1CAPI_Radiolink_Reconfigure_Ready * pRlReconfigRdy);
void radiolinkFailureIndicationProcEncHdlr(L1CAPI_Radiolink_Failure_Ind *pL1CRlFailInd);
void radiolinkRestoreIndicationProcEncHdlr(L1CAPI_Radiolink_Restore_Ind *pL1CRlRestoreInd);
void commonMeasInitResponseEncHdlr(L1CAPI_Common_Meas_Init_Response *pL1CCMeasInitRsp);
void commonMeasReportEncHdlr(L1CAPI_Common_Meas_Report *pL1CCMeasReport);
void commonMeasFailIndicationEncHdlr(L1CAPI_Common_Meas_Fail_Ind *pL1CCMeasFailInd);
void dedicatedMeasInitResponseProcEncHdlr(L1CAPI_Dedicated_Meas_Init_Response *pL1CDMeasInitRsp);
void dedicatedMeasReportProcEncHdlr(L1CAPI_Dedicated_Meas_Report *pL1CDMeasReport);
void dedicatedMeasFailIndicationProcEncHdlr(L1CAPI_Dedicated_Meas_Fail_Ind *pL1CDMeasFailInd);

#endif 
