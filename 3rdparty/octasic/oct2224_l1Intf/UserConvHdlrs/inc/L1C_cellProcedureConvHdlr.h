/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cellProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Cell Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"

#ifndef _L1C_CELLPROCEDURECONVHDLR_H_
#define _L1C_CELLPROCEDURECONVHDLR_H_


void cellInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                             L1CAPI_CellInfo *pL1CCellInfo,
                             l1api_cell_params_t * pOpCellInfo);

void schInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_SCH_Info *pL1CSchInfo,
                              l1api_sch_params_t * pOpSchInfo);
void pCpichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_Primary_CPICH_Info *pL1CPCPichInfo,
                                  l1api_cpich_params_t * pOpPCpichInfo);

void sCpichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                 L1CAPI_Secondary_CPICH_Info *pL1CPCPichInfo,
                                 l1api_cpich_params_t * pOpPCpichInfo);

void pCcpchInfoConvHdlr(L1CAPI_Msg_Status *msgStatus,
                             L1CAPI_PrimCCPCH_Info *pL1CPccpchInfo,
                             l1api_pccpch_params_t * pOpPccpchInfo);

void bchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_BCH_Info *pL1CBchInfo,
                              l1api_common_trch_dlbasic_t * pOpBchInfo);


#endif 
