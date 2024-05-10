/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_tfsConvHdlr.c

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


#include "L1C_tfsConvHdlr.h"

void ttiConvHdlr(L1CAPI_Msg_Status *msgStatus,
                  L1CAPI_TFS_TTISemiStatic * pL1CTti,
                  l1api_tti_t opTti)
{
    switch(opTti)
    {
        case L1API_TTI_10_MS:
            * pL1CTti = L1CAPI_MSEC_10;
            break;                
        case L1API_TTI_20_MS:
            * pL1CTti = L1CAPI_MSEC_20;
            break;
        case L1API_TTI_40_MS:
            * pL1CTti = L1CAPI_MSEC_40;            
            break;
        case L1API_TTI_80_MS:    
            * pL1CTti = L1CAPI_MSEC_80;
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
            msgStatus->additionalInfo0 = PARAM_1;
            msgStatus->additionalInfo1 = opTti;            
            return;
    }
}

void crcSizeConvHdlr(L1CAPI_Msg_Status *msgStatus,
                         L1CAPI_TFS_CRC_Size * pL1CCrcSize,
                         l1api_crc_size_t opCrcSize)
{
    switch(opCrcSize)
    {
        case L1API_CRC_0:
            *pL1CCrcSize = L1CAPI_TFS_CRC_SIZE_V0;
            break;
        case L1API_CRC_8:
            *pL1CCrcSize = L1CAPI_TFS_CRC_SIZE_V8;
            break;
        case L1API_CRC_12:
            *pL1CCrcSize = L1CAPI_TFS_CRC_SIZE_V12;
            break;
        case L1API_CRC_16:
            *pL1CCrcSize = L1CAPI_TFS_CRC_SIZE_V16;
            break;
        case L1API_CRC_24:
            *pL1CCrcSize = L1CAPI_TFS_CRC_SIZE_V24;
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
            msgStatus->additionalInfo0 = PARAM_2;
            msgStatus->additionalInfo1 = opCrcSize;            
            return ;
    }

}

    
void codingTypeRateConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_TFS_ChannelCodingType * pL1CCodingType,
                                   L1CAPI_TFS_CodingRate * pL1CCodingRate,
                                  l1api_channel_coding_type_t opCodingType)
{
    switch(opCodingType)
    {
        case L1API_CODING_NONE:
            *pL1CCodingType = L1CAPI_NO_CODING;
            break;
        case L1API_CODING_CONV_12:
            * pL1CCodingType = L1CAPI_CONV_CODING;            
            * pL1CCodingRate = L1CAPI_HALF_RATE;
            break;
        case L1API_CODING_CONV_13:
            * pL1CCodingType = L1CAPI_CONV_CODING;            
            * pL1CCodingRate = L1CAPI_ONETHIRD_RATE;            
            break;
        case L1API_CODING_TURBO_13:
            * pL1CCodingType = L1CAPI_TURBO_CODING;
            * pL1CCodingRate = L1CAPI_ONETHIRD_RATE;
            break;
        default:
            msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
            msgStatus->additionalInfo0 = PARAM_3;
            msgStatus->additionalInfo1 = opCodingType;            
            break;
    }
}

void tfConvHdlr(L1CAPI_Msg_Status *msgStatus,
                L1CAPI_TFS_DynamicPartListItem * pL1CTf,
                l1api_tf_t * pOpTf)
{
    pL1CTf->nrOfTransportBlocks = (L1CAPI_TFS_NrOfTransportBlocks)pOpTf->tr_blocks;
    pL1CTf->transportBlockSize = pOpTf->tr_block_size;
}

void tfsConvHdlr(L1CAPI_Msg_Status *msgStatus,
                   L1CAPI_TransportFormatSet *pL1CTfsInfo,    
                   l1api_trch_tf_t * pOpTfsInfo)
{
    pL1CTfsInfo->tfCount = pOpTfsInfo->n_tf;
    ttiConvHdlr(msgStatus,&pL1CTfsInfo->tti,pOpTfsInfo->tti);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    crcSizeConvHdlr(msgStatus,&pL1CTfsInfo->crcType,pOpTfsInfo->crc_size);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    codingTypeRateConvHdlr(msgStatus,&pL1CTfsInfo->codingType,&pL1CTfsInfo->codingRate,pOpTfsInfo->chan_coding_type);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    pL1CTfsInfo->rmAttrib = pOpTfsInfo->rate_match_attrib + 1;
}
