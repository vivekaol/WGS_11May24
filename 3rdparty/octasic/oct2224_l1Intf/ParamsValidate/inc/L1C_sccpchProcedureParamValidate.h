/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sccpchProcedureParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_SCCPCHPROCEDUREPARAMVALIDATE_H_
#define _L1C_SCCPCHPROCEDUREPARAMVALIDATE_H_

void sccpchPhyInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_SCCPCH_Phy_Info *pL1CSccpchPhyInfo);
void sccpchTrchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                            L1CAPI_SCCPCH_Trch_Info * pL1CTrchInfo);
void pichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_PICH_Params *  pL1CPichInfo);

#endif 
