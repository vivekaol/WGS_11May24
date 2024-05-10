/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_RADIOLINKPROCEDUREPARAMVALIDATE_H_
#define _L1C_RADIOLINKPROCEDUREPARAMVALIDATE_H_


void rlCmnContextInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                              L1CAPI_RadioLink_CmnContextInfo *pL1NodeBCmnContextInfo);

void dlCodeInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                       L1CAPI_DL_CodeInfo *pL1CDlCodeInfo);

void rlInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                L1CAPI_RadioLink_Info *pL1CRlInfo);

void rlReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus ,
                                          L1CAPI_Radiolink_Reconfig_params *pL1CRlInfo);

void dchTrchProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                  L1CAPI_DCH_Info *pL1CDchInfo);

void coordTrchProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                      L1CAPI_DCH_CoordTrchInfoListItem *pL1CCordInfo);

void phyDlDpchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_DL_DPCH_PhyInfo *pL1CPhyDlDpchInfo);

void phyDlDpchReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_DL_DPCH_PhyInfo_Reconfig *pL1CPhyDlDpchInfo);

void phyUlDpchInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_UL_DPCH_PhyInfo *pL1CPhyUlDpchInfo);

void phyUlDpchReconfigInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                                     L1CAPI_UL_DPCH_PhyInfo_Reconfig *pL1CPhyUlDpchInfo);

void rlReconfigCmnInfoProcParamValidate(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_Radiolink_Reconfig_CmnContextInfo *pL1CRlReconfigCmnInfo);

#endif 
