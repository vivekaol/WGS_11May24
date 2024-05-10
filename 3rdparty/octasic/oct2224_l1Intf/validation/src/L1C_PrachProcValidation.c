/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_PrachRespProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Random Access Channel Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_PrachProcValidation.h"
#include "L1C_TFCS_CTFC_ProcValidation.h"

/***********************
Octasic L1C API initial
************************/
static L1CAPI_TFC_Beta l1c_BetaCDInfo = 
{
	L1CAPI_SIGNALLED_GF,
	1,
	2,
	1
};

static L1CAPI_TFCS_Info_Item l1c_CtfcInfo[4] = 
{
	{                        
		tFC_Beta_present,
		0,
		&l1c_BetaCDInfo
	},
	{                        
		tFC_Beta_present,
		1,
		&l1c_BetaCDInfo
	},	
	{                        
		tFC_Beta_present,
		2,
		&l1c_BetaCDInfo
	},	
	{                        
		tFC_Beta_present,
		3,
		&l1c_BetaCDInfo
	}
};

static L1CAPI_TFS_DynamicPartListItem l1c_PrachTf[4] =
{
	{1,336},
	{1,224},
	{0,336},
	{2,336}
};

static L1CAPI_Prach_Setup_Request l1c_PrachSetupReq =
{
	{
		0
	},/*cmn info*/
	{
		0,                  /* commonPhysicalChannelID;*/
		2,					/*scramblingCodeNumber;*/
		L1CAPI_Signature0,	/* preambleSignatures;*/
		2,					/* allowedSFCount; */
		{1,2},				/*	 allowedSlotFormatInfo[4];*/
		0xfff,				/*	 rACH_SubChannelNumbers;*/
		15,					/* ul_punctureLimit;*/
		10					/* preambleThreshold;*/
	},/*prach phy info*/
	{
		1,                  /*commonPhysicalChannelID;*/
		L1CAPI_AICH_TRANSTIMING_V0,					/*aICH_TransmissionTiming;*/
		222,					/*dl_ChannelisationCodeNumber;*/
		(2 - 22),					/*aICH_Power;*/
		0					/*sTTD_Indicator;*/
	},/*aich info*/
	{
		4,
		l1c_CtfcInfo
	},/*tfc info*/
	{
		1,
		{
			4,							/*tfCount;*/
			L1CAPI_MSEC_20,				/*tti;*/
			L1CAPI_TFS_CRC_SIZE_V12,	/*crcType;*/
			L1CAPI_CONV_CODING,         /*codingType;*/
			L1CAPI_ONETHIRD_RATE,		/*codingRate; */
			(190 + 1),					/*rmAttrib;*/
			l1c_PrachTf,				/**ptrTransFormat;*/
		}
	}/*trch info*/
};


/***********************
Validation API
***********************/


L1CAPI_Prach_Setup_Request * getL1CPrachSetupRequest()
{
	return &l1c_PrachSetupReq;
}


uint8_t validatePrachSetupReqCodecOutput(L1CAPI_Prach_Setup_Request * pCodecResult,L1CAPI_Prach_Setup_Request *pExpectedResult)
{
	if(pCodecResult->cmnInfo.cId != pExpectedResult->cmnInfo.cId)
	{
		return 0;
	}
	if(memcmp(&pCodecResult->physUlPrach,&pExpectedResult->physUlPrach,sizeof(L1CAPI_Prach_Phy_Info)))
	{
		return 0;
	}

	if(memcmp(&pCodecResult->physDlAich,&pExpectedResult->physDlAich,sizeof(L1CAPI_AICH_Phy_Info)))
	{
		return 0;
	}

	if(!validateCTFCCodecOutput(&pCodecResult->cctrchUlTfc,&pExpectedResult->cctrchUlTfc))
	{
		return 0;
	}
	if(pCodecResult->trchUlPrach.commonTransportChannelID != pExpectedResult->trchUlPrach.commonTransportChannelID)
	{
		return 0;
	}
	if(!validateTFSCodecOutput(&pCodecResult->trchUlPrach.tfsUL,&pExpectedResult->trchUlPrach.tfsUL))
		return 0;
	return 1;
}
