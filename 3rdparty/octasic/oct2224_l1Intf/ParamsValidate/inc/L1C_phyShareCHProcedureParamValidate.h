/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_phyShareCHProcedureParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Shared Channel Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_PHYSHARECHPROCEDUREPARAMVALIDATE_H_
#define _L1C_PHYSHARECHPROCEDUREPARAMVALIDATE_H_

void hspdschCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_HS_PDSCH_Code_Info * pL1CPdschCodeInfo);
void hsscchCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_HS_SCCH_Code_Info * pL1CScchCodeInfo);
void sharedCHExtAgchCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                         L1CAPI_E_AGCH_Code_Info *pL1CAgchCodeInfo);
void sharedCHExtRgchHichCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                              L1CAPI_E_RGCH_HICH_Code_Info *pL1CRgchHichCodeInfo);
void sharedCHExtProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_Physical_SharedCH_Reconfig_Ext *  pL1CExtInfo);

#endif 
