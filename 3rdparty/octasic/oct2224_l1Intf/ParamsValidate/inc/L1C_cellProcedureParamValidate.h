/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cellProcedureParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Cell Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"

#ifndef _L1C_CELLPROCEDUREPARAMVALIDATE_H_
#define _L1C_CELLPROCEDUREPARAMVALIDATE_H_

void cellInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_CellInfo *pL1CCellInfo);

void schInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_SCH_Info *pL1CSchInfo);

void pCpichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_Primary_CPICH_Info *pL1CPCPichInfo);

void sCpichInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_Secondary_CPICH_Info *pL1CPCPichInfo);
 
void bchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_BCH_Info *pL1CBchInfo );



#endif 
