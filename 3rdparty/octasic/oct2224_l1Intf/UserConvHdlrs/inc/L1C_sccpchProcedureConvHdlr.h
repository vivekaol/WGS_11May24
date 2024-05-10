/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sccpchProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel Procedure 
   Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"


#ifndef _L1C_SCCPCHPROCEDURECONVHDLR_H_
#define _L1C_SCCPCHPROCEDURECONVHDLR_H_


void sccpchPhyInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_SCCPCH_Phy_Info *pL1CSccpchPhyInfo,
                                    l1api_sccpch_params_t * pOpSccpchPhyInfo);

void sccpchTrchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                     L1CAPI_SCCPCH_Trch_Info * pL1CTrchInfo,
                                     l1api_trch_dl_params_t * pOpTrchInfo);
void pichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_PICH_Params *  pL1CPichInfo,
                              l1api_pich_params_t * pOpPichInfo);




#endif 
