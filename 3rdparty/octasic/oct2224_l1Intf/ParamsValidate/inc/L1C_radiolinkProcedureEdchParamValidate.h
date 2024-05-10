/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Enhanced Dedicated Channel 
   Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_RADIOLINKPROCEDUREEDCHPARAMVALIDATE_H_
#define _L1C_RADIOLINKPROCEDUREEDCHPARAMVALIDATE_H_


void edchRlInfoExtProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                          L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt);

void edpchConfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_Radiolink_EDpch_Info *pL1CEdpchInfo);

void edpchReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_Radiolink_EDpch_Reconfig_Info *pL1CEdpchInfo);

void edchFddConfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_FDD_Info *pL1CEdchFddInfo);

void edchFddReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_DCH_FDD_Reconfig_Info *pL1CEdchFddInfo);

void edchMacDFlowInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_E_DCH_MACDFlow_Info *pL1CEdchMacDFlowInfo);

void edchMacDFlowReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                          L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pL1CEdchMacDFlowInfo);

void edchNonSchedGrantInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                      L1CAPI_E_DCH_NonScheduled_TxGrantItems *pL1CEDchNonSchedGrantInfo);

void edchLogicChInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo);

void servingEdchRlInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_ServingEdch_Radiolink_Info * pL1CServingEdchRlInfo);

#endif 
