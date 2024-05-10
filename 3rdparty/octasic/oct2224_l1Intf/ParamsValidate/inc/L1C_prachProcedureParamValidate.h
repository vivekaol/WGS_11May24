/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_prachProcedureParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Prach Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_PRACHPROCEDUREPARAMVALIDATE_H_
#define _L1C_PRACHPROCEDUREPARAMVALIDATE_H_

void prachPhyInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Prach_Phy_Info * pL1CPrachPhyInfo);
void aichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_AICH_Phy_Info * pL1CAichInfo);

#endif 
