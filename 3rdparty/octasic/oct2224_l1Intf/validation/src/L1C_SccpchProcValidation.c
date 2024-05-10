/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_SccpchProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel
   Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include <stdio.h>
#include <memory.h>

#include "L1C_SccpchProcValidation.h"
#include "L1C_TFCS_CTFC_ProcValidation.h"

/***********************
Octasic L1C API initial
************************/

static L1CAPI_TFCS_Info_Item l1c_CtfcInfo[4] = 
{
	{                        
		0,
		0,
		NULL
	},
	{                        
		0,
		1,
		NULL
	},	
	{                        
		0,
		3,
		NULL
	},	
	{                        
		0,
		4,
		NULL
	}
};

static L1CAPI_TFS_DynamicPartListItem l1c_FachTf[3] =
{
	{0,656},
	{1,656},
	{2,656}
};

static L1CAPI_TFS_DynamicPartListItem l1c_PchTf[3] =
{
	{1,336},
	{1,224},
	{0,336}
};

static L1CAPI_SCCPCH_Trch_Info l1c_FachInfo[2] = 
{
	{
		2,
		(2-350),
		0,
		0,
		{
			3,							/*tfCount;*/
			L1CAPI_MSEC_40,				/*tti;*/
			L1CAPI_TFS_CRC_SIZE_V16,	/*crcType;*/
			L1CAPI_CONV_CODING,         /*codingType;*/
			L1CAPI_HALF_RATE,		/*codingRate; */
			(195 + 1),					/*rmAttrib;*/
			l1c_FachTf,				/**ptrTransFormat;*/
		}
	},
	{
		3,
		(2-350),
		0,
		0,
		{
			3,							/*tfCount;*/
			L1CAPI_MSEC_80,				/*tti;*/
			L1CAPI_TFS_CRC_SIZE_V16,	/*crcType;*/
			L1CAPI_CONV_CODING,         /*codingType;*/
			L1CAPI_HALF_RATE,		/*codingRate; */
			(195 + 1),					/*rmAttrib;*/
			l1c_FachTf,				/**ptrTransFormat;*/
		}
	}
};
static L1CAPI_PCH_Info l1cPchInfo =
{
	{
		1,
		(2-350),
		0,
		0,
		{
			3,							/*tfCount;*/
			L1CAPI_MSEC_10,				/*tti;*/
			L1CAPI_TFS_CRC_SIZE_V16,	/*crcType;*/
			L1CAPI_CONV_CODING,         /*codingType;*/
			L1CAPI_HALF_RATE,		/*codingRate; */
			(192 + 1),					/*rmAttrib;*/
			l1c_PchTf,				/**ptrTransFormat;*/
		}
	},
	{
		1,                       /*commonPhysicalChannelID;*/
		4,						 /*dl_ChannelisationCodeNumber;*/
		(1-10),                       /*pICH_Power;*/
		L1CAPI_PichMode_v144,	 /*pICH_Mode;*/
		0						 /*sTTD_Indicator;*/
	}
};

static L1CAPI_Sccpch_Setup_Request l1c_SccpchSetupReq = 
{
	trchCommonDlPch_present,
	{
		0
	},
	2,
	{
		dl_ScramblingCode_present|sccpch_tFCI_present,  /*bit_mask*/
		3,                                              /*commonPhysicalChannelID*/
		0,												/*sCCPCH_Chip_Offset*/
		3,												/*dl_ScramblingCode*/
		6,												/*dL_ChannelisationCodeNumber*/
		8,												/*sCCPCH_SlotFormat*/
		1,												/*tFCI_Presence*/
		L1CAPI_FLEXIBLE,								/*multiplexingPosition*/
		1,												/*pO1_ForTFCI_Bits*/
		2,												/*pO3_ForPilotBits*/
		0												/*sTTD_Indicator*/
	},
	{
		4,
		l1c_CtfcInfo
	},
	l1c_FachInfo,
	&l1cPchInfo
};


/***********************
Validation API
***********************/


L1CAPI_Sccpch_Setup_Request * getL1CSccpchSetupRequest()
{
	return &l1c_SccpchSetupReq;
}

static validateFachTrchInfo(L1CAPI_SCCPCH_Trch_Info * pCodecResult,L1CAPI_SCCPCH_Trch_Info * pExpectedResult)
{
	if(pCodecResult->commonTransportChannelID != pExpectedResult->commonTransportChannelID)
		return 0;
	if(pCodecResult->maxFACH_PCH_Power != pExpectedResult->maxFACH_PCH_Power)
		return 0;
	if(pCodecResult->toAWS != pExpectedResult->toAWS)
		return 0;
	if(pCodecResult->toAWE != pExpectedResult->toAWE)
		return 0;
	if(!validateTFSCodecOutput(&pCodecResult->tfsDL,&pExpectedResult->tfsDL))
		return 0;
	return 1;
}

static validatePchTrchInfo(L1CAPI_PCH_Info * pCodecResult,L1CAPI_PCH_Info * pExpectedResult)
{
	if(!(validateFachTrchInfo(&pCodecResult->commonParameters,&pExpectedResult->commonParameters)))
		return 0;
	if(memcmp(&pCodecResult->pichPhys,&pExpectedResult->pichPhys,sizeof(L1CAPI_PICH_Params)))
	{
		return 0;
	}
	return 1;
}

uint8_t validateSccpchSetupReqCodecOutput(L1CAPI_Sccpch_Setup_Request * pCodecResult,L1CAPI_Sccpch_Setup_Request *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->cmnInfo.cId != pExpectedResult->cmnInfo.cId)
		return 0;
	if(pCodecResult->nFach != pExpectedResult->nFach)
		return 0;
	if(memcmp(&pCodecResult->physDlSCcpch,&pExpectedResult->physDlSCcpch,sizeof(L1CAPI_SCCPCH_Phy_Info)))
	{
		return 0;
	}
	if(!validateCTFCCodecOutput(&pCodecResult->cctrchDlTfc,&pExpectedResult->cctrchDlTfc))
	{
		return 0;
	}
	for(i=0;i<pCodecResult->nFach;i++){
		if(!validateFachTrchInfo(&(pCodecResult->ptrTrchDlFach[i]),&(pExpectedResult->ptrTrchDlFach[i])))
			return 0;
	}
	if(pCodecResult->bit_mask & trchCommonDlPch_present)
	{
		if(!validatePchTrchInfo(pCodecResult->ptrTrchDlPch,pExpectedResult->ptrTrchDlPch))
			return 0;
	}

	return 1;
}
