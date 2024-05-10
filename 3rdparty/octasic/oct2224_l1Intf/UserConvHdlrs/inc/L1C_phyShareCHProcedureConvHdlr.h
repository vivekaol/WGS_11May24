/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_phyShareCHProcedureConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Shared Channel Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"


#ifndef _L1C_PHYSHARECHPROCEDURECONVHDLR_H_
#define _L1C_PHYSHARECHPROCEDURECONVHDLR_H_


void hspdschCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_HS_PDSCH_Code_Info * pL1CPdschCodeInfo,
                                         l1api_hs_pdsch_code_info_t * pOpPdschCodeInfo);

void hsscchCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_HS_SCCH_Code_Info * pL1CScchCodeInfo,
                                       l1api_hs_scch_code_info_t * pOpScchCodeInfo);

void sharedCHExtRlCmnEdchProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                 L1CAPI_Rl_Cmn_Edch_info *  pL1CExtRlCmdEdchInfo,
                                                 l1api_rl_cmn_edch_info_t * pOpExtRlCmnEdchInfo);

void sharedCHExtAgchCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                  L1CAPI_E_AGCH_Code_Info *pL1CAgchCodeInfo,
                                                  l1api_eagch_code_info_t * pOpAgchCodeInfo);

void sharedCHExtRgchHichCodeInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                                       L1CAPI_E_RGCH_HICH_Code_Info *pL1CRgchHichCodeInfo,
                                                       l1api_ergch_high_code_info_t * pOpRgchHichCodeInfo);

void sharedCHExtProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_Physical_SharedCH_Reconfig_Ext *  pL1CExtInfo,
                                    l1api_phys_sh_ch_rcfg_extensions_t * pOpExtInfo);



#endif 
