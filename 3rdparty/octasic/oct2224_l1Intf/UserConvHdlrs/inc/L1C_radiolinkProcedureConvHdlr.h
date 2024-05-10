/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"


#ifndef _L1C_RADIOLINKPROCEDURECONVHDLR_H_
#define _L1C_RADIOLINKPROCEDURECONVHDLR_H_

void rlCmnContextInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                         L1CAPI_RadioLink_CmnContextInfo *pL1NodeBCmnContextInfo,
                                         l1api_Nb_com_context_setup_info_t *pOpNBCmnContextInfo);
void dlCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                 L1CAPI_DL_CodeInfo *pL1CDlCodeInfo,	
                                 l1api_dpch_dl_code_info_t *pOpDlCodeInfo);

void rlInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                           L1CAPI_RadioLink_Info *pL1CRlInfo,
                           l1api_rl_params_t *pOpRlInfo);

void rlReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus ,
                                     L1CAPI_Radiolink_Reconfig_params *pL1CRlInfo,
                                     l1api_rl_reconfig_params_t *pOpRlInfo);

void dchTrchProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                               L1CAPI_DCH_Info *pL1CDchInfo,	
                               l1api_dch_info_t* pOpDchInfo);

void coordTrchProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                 L1CAPI_DCH_CoordTrchInfoListItem *pL1CCordInfo, 
                                 l1api_coord_trch_dch_t* pOpCordInfo);

void phyDlDpchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_DL_DPCH_PhyInfo *pL1CPhyDlDpchInfo,
                                      l1api_dpch_dl_params_t* pOpPhyDlDpchInfo);

void phyDlDpchReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_DL_DPCH_PhyInfo_Reconfig *pL1CPhyDlDpchInfo,
                                                l1api_dpch_dl_params_t* pOpPhyDlDpchInfo);

void phyUlDpchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_UL_DPCH_PhyInfo *pL1CPhyUlDpchInfo,
                                      l1api_dpch_ul_params_t* pOpPhyUlDpchInfo);

void phyUlDpchReconfigInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                L1CAPI_UL_DPCH_PhyInfo_Reconfig *pL1CPhyUlDpchInfo,
                                                l1api_dpch_ul_params_t* pOpPhyUlDpchInfo);

void pwrBalanceInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_DL_PowerBalancing_Info *pL1CPwrBalanceInfo,
                                       l1api_dlpower_balancing_info_t* pOpPwrBalanceInfo);

void rlReconfigCmnInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo,
                                          l1api_Nb_com_context_reconfig_info_t * pOpRlReconfigCmnInfo);

void activePatternInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Active_Pattern_Seq4 *pL1CActvPatternInfo,
                                        l1api_tgps_status_t *pOpActvPatternInfo);

void tgpsGapInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_TxGap_SeqInfo *pL1CtgpsGapInfo,
                                  l1api_trans_gap_patt_seq_info_t *pOpTgpsGapInfo);


#endif 
