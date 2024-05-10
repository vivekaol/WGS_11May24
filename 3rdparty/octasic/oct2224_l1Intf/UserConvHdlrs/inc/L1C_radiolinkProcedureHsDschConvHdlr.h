/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureHsDschConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure High Speed Dedicated Shared Channel 
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


#ifndef _L1C_RADIOLINKPROCEDUREHSDSCHCONVHDLR_H_
#define _L1C_RADIOLINKPROCEDUREHSDSCHCONVHDLR_H_

void macDPduSizeIndexProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_MACDPDU_Size_IndexItem *pL1CMacDPduSizeIndex,
                                         l1api_macd_pdu_size_index_t *pOpMacDPduSizeIndex);

void priorityQInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_PriorityQueue_Info *pL1CPriQInfo,
                                   l1api_priority_queue_info_t * pOpPriQInfo);

void macDFlowConfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                            L1CAPI_HSDSCH_MACdFlows_Info * pL1CMacDFlowInfo,
                                            l1api_hsdsch_macd_flow_info_t *pOpMacDFlowInfo);

void macDFlowReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_HSDSCH_MACdFlows_Reconfig_Info * pL1CMacDFlowInfo,
                                               l1api_hsdsch_macd_flow_reconfig_t *pOpMacDFlowInfo);

void hsdschInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_RadioLink_HSDSCH_Info * pL1CHsdschInfo,
                                  l1api_hsdsch_info_t *pOpHsdschInfo);

void hsdschModifyInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_RadioLink_HSDSCH_Reconfig_Info * pL1CHsdschInfo,
                                         l1api_hsdsch_info_reconfig_t *pOpHsdschInfo);

void hsdschConfigProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                     L1CAPI_Radiolink_HSDSCH_Config *pL1CHsdschConfig,
	                                 l1api_hsdsch_t *pOpHsdschConfig);

void hsdschReconfigProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Radiolink_HSDSCH_Reconfig *pL1CHsdschReconfig,
	                                    l1api_hsdsch_reconfig_t *pOpHsdschConfig);

#endif 
