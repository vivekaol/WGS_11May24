/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Coded Composite Transport Channel Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"

#ifndef _L1C_CCTRCHCONVHDLR_H_
#define _L1C_CCTRCHCONVHDLR_H_

void betaCDConvHdlr(L1CAPI_Msg_Status *msgStatus,
                         L1CAPI_TFC_Beta   * pL1BetaCDInfo,
                         l1api_cctrch_tfc_info_t * pOpCtfcInfo);
void tfcsConvHdlr(L1CAPI_Msg_Status *msgStatus,
                    L1CAPI_TFCS_Info_Item   * pL1CCtfcInfo,
                    l1api_cctrch_tfc_info_t * pOpCtfcInfo,
					uint8_t ulOrDl);
void cctrchConvHdlr(L1CAPI_Msg_Status *msgStatus,
                       L1CAPI_TFCS_Info      * pL1CCctrchInfo,
                       l1api_cctrch_params_t * pOpCctrchInfo);
void eTfciConvHdlr(L1CAPI_Msg_Status *msgStatus,
                      L1CAPI_Ref_E_TFCI_InfoItem *pL1CEtfci,
                      l1api_ref_etfci_t *pOpEtfci);
void eTfcsInfoConvHdlr(L1CAPI_Msg_Status *msgStatus,
                          L1CAPI_E_TFCS_Info *pL1CEtfcsInfo,
                          l1api_etfcs_info_t *pOpEtfcsInfo);

#endif 
