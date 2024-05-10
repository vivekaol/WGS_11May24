/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureEdchConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Enhanced Dedicated Channel 
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


#ifndef _L1C_RADIOLINKPROCEDUREEDCHCONVHDLR_H_
#define _L1C_RADIOLINKPROCEDUREEDCHCONVHDLR_H_


void edchRlInfoExtProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                     L1CAPI_EDCH_RL_InfoExtension *pL1CEdchRlInfoExt,
                                     l1api_edch_rl_info_ext_t *pOpEdchRlInfoExt);

void edpchConfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Radiolink_EDpch_Info *pL1CEdpchInfo,
                                        l1api_edpch_info_t *pOpEdchInfo);

void edpchReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Radiolink_EDpch_Reconfig_Info *pL1CEdpchInfo,
                                          l1api_edpch_info_re_t *pOpEdchInfo);

void edchFddConfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_E_DCH_FDD_Info *pL1CEdchFddInfo,
                                           l1api_edch_fdd_info_t *pOpEdchFddInfo);

void edchFddReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_E_DCH_FDD_Reconfig_Info *pL1CEdchFddInfo,
                                             l1api_edch_fdd_info_re_t *pOpEdchFddInfo);

void edchMacDFlowInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_E_DCH_MACDFlow_Info *pL1CEdchMacDFlowInfo,
                                          l1api_edch_macd_flows_info_t * pOpEdchMadFlowInfo);

void edchMacDFlowReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pL1CEdchMacDFlowInfo,
                                                     l1api_edch_macd_flows_info_re_t * pOpEdchMadFlowInfo);

void edchNonSchedGrantInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                 L1CAPI_E_DCH_NonScheduled_TxGrantItems *pL1CEDchNonSchedGrantInfo,
                                                 l1api_edch_non_sched_grant_info_t *pOpEdchNonSchedGrantInfo);

void edchLogicChInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo,
                                        l1api_edch_logical_chan_info_t *pOpEdchLogicChInfo);

void edchLogicChReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_DCH_LogicalChannelInfo * pL1CEdchLogicChInfo,
                                                  l1api_edch_logical_chan_info_re_t *pOpEdchLogicChInfo);

void servingEdchRlInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_ServingEdch_Radiolink_Info * pL1CServingEdchRlInfo,
                                          l1api_serving_edch_rl_t * pOpServingEdchRlInfo);


#endif 
