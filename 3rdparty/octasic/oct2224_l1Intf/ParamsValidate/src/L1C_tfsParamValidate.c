/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_tfsParamValidate.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Transport Format Set Parameter Validate

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_tfsParamValidate.h"
	

void tfParamValidate(L1CAPI_Msg_Status *msgStatus,
                       L1CAPI_TFS_DynamicPartListItem * pL1CTf)
{
    if ( pL1CTf->nrOfTransportBlocks > 255 )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRANSFORMAT;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CTf->nrOfTransportBlocks;
      return;
    }
    if (pL1CTf->transportBlockSize > 5000 )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRANSFORMAT;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CTf->transportBlockSize;
      return;
    }
}

void tfsParamValidate(L1CAPI_Msg_Status *msgStatus,
                        L1CAPI_TransportFormatSet *pL1CTfsInfo)
{
    if(pL1CTfsInfo->tfCount > L1CAPI_MAX_NR_OF_TFS)
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
      msgStatus->additionalInfo0 = PARAM_0;
      msgStatus->additionalInfo1 = pL1CTfsInfo->tfCount;
      return;
    }
    if((pL1CTfsInfo->tti != L1CAPI_MSEC_10) &&
       (pL1CTfsInfo->tti != L1CAPI_MSEC_20) &&
	   (pL1CTfsInfo->tti != L1CAPI_MSEC_40) &&
		(pL1CTfsInfo->tti != L1CAPI_MSEC_80) 
	   )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
      msgStatus->additionalInfo0 = PARAM_1;
      msgStatus->additionalInfo1 = pL1CTfsInfo->tti;
    }
    if((pL1CTfsInfo->crcType != L1CAPI_TFS_CRC_SIZE_V0)&&
      (pL1CTfsInfo->crcType != L1CAPI_TFS_CRC_SIZE_V8)&&
      (pL1CTfsInfo->crcType != L1CAPI_TFS_CRC_SIZE_V12)&&
      (pL1CTfsInfo->crcType != L1CAPI_TFS_CRC_SIZE_V16)&&
      (pL1CTfsInfo->crcType != L1CAPI_TFS_CRC_SIZE_V24)
      )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = pL1CTfsInfo->crcType;
    }
    if((pL1CTfsInfo->codingType != L1CAPI_NO_CODING)&&
      (pL1CTfsInfo->codingType != L1CAPI_CONV_CODING)&&
      (pL1CTfsInfo->codingType != L1CAPI_TURBO_CODING)
      )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = pL1CTfsInfo->codingType;
    }
    if((pL1CTfsInfo->codingRate!= L1CAPI_HALF_RATE)&&
      (pL1CTfsInfo->codingRate != L1CAPI_ONETHIRD_RATE)
      )
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
      msgStatus->additionalInfo0 = PARAM_4;
      msgStatus->additionalInfo1 = pL1CTfsInfo->codingRate;
    }

    if(pL1CTfsInfo->rmAttrib > 256)
    {
      msgStatus->l1MsgResult = L1_EMSG_TRCHTF;
      msgStatus->additionalInfo0 = PARAM_5;
      msgStatus->additionalInfo1 = pL1CTfsInfo->rmAttrib;
      return;    
    }
}
