/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure HighSpeed Dedicated Shared Channel 
   Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_RADIOLINKPROCEDUREHSDSCHPARAMVALIDATE_H_
#define _L1C_RADIOLINKPROCEDUREHSDSCHPARAMVALIDATE_H_

void macDPduSizeIndexProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_MACDPDU_Size_IndexItem *pL1CMacDPduSizeIndex);

void Discard_Tmr_ParamValidate(L1CAPI_Msg_Status *msgStatus,L1CAPI_DiscardTimer tmr);

void T1_Tmr_ParamValidate(L1CAPI_Msg_Status *msgStatus,L1CAPI_T1 t1);

void mACHS_WindowSize_ParamValidate(L1CAPI_Msg_Status *msgStatus,L1CAPI_MAC_hsWindowSize type);

void priorityQInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_PriorityQueue_Info *pL1CPriQInfo);

void macDFlowConfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_HSDSCH_MACdFlows_Info * pL1CMacDFlowInfo);

void macDFlowReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                    L1CAPI_HSDSCH_MACdFlows_Reconfig_Info * pL1CMacDFlowInfo);

void hsdschInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_RadioLink_HSDSCH_Info * pL1CHsdschInfo);

void hsdschModifyInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_RadioLink_HSDSCH_Reconfig_Info * pL1CHsdschInfo);

void hsdschConfigProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig);

void hsdschReconfigProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig);

#endif 
