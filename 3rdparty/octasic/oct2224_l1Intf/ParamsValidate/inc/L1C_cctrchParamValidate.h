/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cctrchParamValidate.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Coded Composite Transport Channel Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"


#ifndef _L1C_CCTRCHPARAMVALIDATE_H_
#define _L1C_CCTRCHPARAMVALIDATE_H_


void betaCDParamValidate(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_TFC_Beta   * pL1BetaCDInfo);
void cctrchParamValidate(L1CAPI_Msg_Status *msgStatus,
                             L1CAPI_TFCS_Info  * pL1CCctrchInfo);
void eTfciParamValidate(L1CAPI_Msg_Status *msgStatus,
                           L1CAPI_Ref_E_TFCI_InfoItem *pL1CEtfci);
void eTfcsInfoParamValidate(L1CAPI_Msg_Status *msgStatus,
                                L1CAPI_E_TFCS_Info *pL1CEtfcsInfo);

#endif 
