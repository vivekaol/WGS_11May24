/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_tfsConvHdlr.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Transport Format Set Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "l1capi_datastruct.h"
#include "op_sa_l1api_structs.h"


#ifndef _L1C_TFSCONVHDLR_H_
#define _L1C_TFSCONVHDLR_H_

void ttiConvHdlr(L1CAPI_Msg_Status *msgStatus,
	              L1CAPI_TFS_TTISemiStatic * pL1CTti,
	              l1api_tti_t opTti);

void crcSizeConvHdlr(L1CAPI_Msg_Status *msgStatus,
                         L1CAPI_TFS_CRC_Size * pL1CCrcSize,
                         l1api_crc_size_t opCrcSize);
	
void codingTypeRateConvHdlr(L1CAPI_Msg_Status *msgStatus,
             	                  L1CAPI_TFS_ChannelCodingType * pL1CCodingType,
             	                  L1CAPI_TFS_CodingRate * pL1CCodingRate,
	                              l1api_channel_coding_type_t opCodingType);

void tfConvHdlr(L1CAPI_Msg_Status *msgStatus,
                L1CAPI_TFS_DynamicPartListItem * pL1CTf,
                l1api_tf_t * pOpTf);

void tfsConvHdlr(L1CAPI_Msg_Status *msgStatus,
                   L1CAPI_TransportFormatSet *pL1CTfsInfo,	
                   l1api_trch_tf_t * pOpTfsInfo);

#endif 
