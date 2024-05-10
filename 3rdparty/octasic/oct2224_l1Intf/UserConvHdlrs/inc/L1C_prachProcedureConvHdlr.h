/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_prachProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control PRACH Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"


#ifndef _L1C_PRACHPROCEDURECONVHDLR_H_
#define _L1C_PRACHPROCEDURECONVHDLR_H_

void prachPhyInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_Prach_Phy_Info * pL1CPrachPhyInfo,
                                    l1api_prach_params_t * pOpPrachPhyInfo);
void aichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_AICH_Phy_Info * pL1CAichInfo,
                              l1api_aich_params_t * pOpAichInfo);
void prachTrchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                     L1CAPI_Prach_Trch_Info * pL1CPrachTrchInfo,
                                     l1api_trch_ul_params_t * pOpPrachTrchInfo);



#endif 
