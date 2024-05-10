/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_responseProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Response Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"


#ifndef _L1C_RESPONSEPROCEDURECONVHDLR_H_
#define _L1C_RESPONSEPROCEDURECONVHDLR_H_

void msgStatusConvHdlr(l1api_msg_status_t *pOpMsgStatus,L1CAPI_Msg_Status *pL1CMsgStatus);
void cordTrchInfoRspConvHdlr(l1api_coord_trch_resp_t *pOpcordTrchInfoRsp,L1CAPI_CoordTrchRespItem *pL1CCordTrchInfo);
void radiolinkInfoRspConvHdlr(l1api_rl_info_resp_t *pOpRlInfoRsp,L1CAPI_Radiolink_Info_Resp * pL1CRlInfoRsp);
void edchFddCtrlChInfoConvHdlr(l1api_edch_fdd_ctrl_chan_info_t *pOpedchFddCtrlChInfo,L1CAPI_Edch_Fdd_Ctrl_Channel_Info *pCtrlChInfo);
void edchFddInfoRspConvHdlr(l1api_edch_fdd_info_resp_t *pOpEdchFddInfoRsp,L1CAPI_Edch_Fdd_Info_Resp * pEdchFddInfoRsp);
void edchMacDFlowInfoRspConvHdlr(l1api_edch_mac_d_flow_info_resp_t * pOpEdchMacDFlowInfo,L1CAPI_Edch_MacD_Flow_Info_resp * pEdchMacDFlowInfo);
void hsMacDFlowInfoRspConvHdlr(l1api_macD_flow_info_t * pOpMacDFlowInfoRsp,L1CAPI_MacDFlow_Info_Resp *pHsMacDFlowInfo);
void hsDschInfoRspConvHdlr(l1api_hsdsch_info_resp_t * pOpHsdschRspInfo,L1CAPI_HSDSCH_Info_Resp * pHsdschInfoRsp);
void radiolinkFailureIndicationConvHdlr(l1api_rl_failure_ind_t *pOpRLFailureInd, L1CAPI_Radiolink_Failure_Ind * pRlFailureInd);
void radiolinkRestoreIndicationConvHdlr(l1api_rl_restore_ind_t *pOpRLRestoreInd, L1CAPI_Radiolink_Restore_Ind * pRlRestoreInd);
#endif 
