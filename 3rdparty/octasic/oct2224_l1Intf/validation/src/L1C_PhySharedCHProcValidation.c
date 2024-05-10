/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_PhySharedCHProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Shared Channel Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_PhySharedCHProcValidation.h"

/***********************
Octasic L1C API initial
************************/

static L1CAPI_HS_PDSCH_Code_Info l1c_hsPdschCodeInfo =
{
	5,
	1
};

static L1CAPI_DL_ChannelCodeNumber l1c_hsScchCode[4] = 
{
	4,5,6,7
};

static L1CAPI_HS_SCCH_Code_Info l1c_hsScchCodeInfo =
{
	L1CAPI_CODE_CHOICE_REPLACE,
	4,
	l1c_hsScchCode
};

static L1CAPI_DL_ChannelCodeNumber l1c_agchCode[2] = 
{
	1,2
};
static L1CAPI_E_AGCH_Code_Info l1c_agchCodeInfo = 
{
	L1CAPI_CODE_CHOICE_REPLACE,
	2,
	l1c_agchCode
};

static L1CAPI_DL_ChannelCodeNumber l1c_rgchhichCode[4] = 
{
	1,2,3,4
};
static L1CAPI_E_RGCH_HICH_Code_Info l1c_rgchhichCodeInfo = 
{
	L1CAPI_CODE_CHOICE_REPLACE,
	4,
	l1c_rgchhichCode
};

static L1CAPI_Rl_Cmn_Edch_info l1c_edchCmnInfo =
{
	eAgchPwrOffset_present|eRgchHichPwrOffset_present,
	1,
	2
};

static L1CAPI_Physical_SharedCH_Reconfig_Ext l1c_edchExt = 
{
	hsScchCellPowerOffset_present|eAgchRgchHichScramCode_present|maxTargetRTWP_present|
	refRTWP_present|rlCommonEDchInfo_present|eAgchCodeInfo_present|eRgchHichCodeInfo_present,
	0,
	1,
	30,
	29,
	&l1c_edchCmnInfo,
	&l1c_agchCodeInfo,
	&l1c_rgchhichCodeInfo
};

static L1CAPI_Physical_Share_CH_Reconfig_Request l1c_PhySharedCHReconfigReq = 
{
	sfn_present|hsPdschSschTotalPower_present|hsPdschSschScramCode_present|
	hsPdschCodeInfo_present|hsScchCodeInfo_present|physShChRcfgExtensions_present,
	0,
	23,
	10,
	0,
	&l1c_hsPdschCodeInfo,
	&l1c_hsScchCodeInfo,
	&l1c_edchExt
};


/***********************
Validation API
***********************/


L1CAPI_Physical_Share_CH_Reconfig_Request * getL1CSharedChReconfigRequest()
{
	return &l1c_PhySharedCHReconfigReq;
}

uint8_t validateSharedCHReconfigReqCodecOutput(L1CAPI_Physical_Share_CH_Reconfig_Request * pCodecResult,L1CAPI_Physical_Share_CH_Reconfig_Request *pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->bit_mask&sfn_present && pCodecResult->cId != pExpectedResult->cId)
		return 0;
	if(pCodecResult->bit_mask&sfn_present && pCodecResult->sfn != pExpectedResult->sfn)
		return 0;
	if(pCodecResult->bit_mask&hsPdschSschTotalPower_present && pCodecResult->hsPdschSschAgchRgchHichTotalPower != pExpectedResult->hsPdschSschAgchRgchHichTotalPower)
		return 0;
	if(pCodecResult->bit_mask&hsPdschSschScramCode_present && pCodecResult->hsPdschSschScramCode != pExpectedResult->hsPdschSschScramCode)
		return 0;
	if(pCodecResult->bit_mask& hsPdschCodeInfo_present)
	{
		if(memcmp(pCodecResult->ptrHsPdschCodeInfo,pExpectedResult->ptrHsPdschCodeInfo,sizeof(L1CAPI_HS_PDSCH_Code_Info)))
			return 0;
	}
	if(pCodecResult->bit_mask& hsScchCodeInfo_present)
	{
		if(pCodecResult->ptrHsScchCodeInfo->codeChoice != 
			pExpectedResult->ptrHsScchCodeInfo->codeChoice)
			return 0;
		if(pCodecResult->ptrHsScchCodeInfo->codeCount != 
			pExpectedResult->ptrHsScchCodeInfo->codeCount)
			return 0;
		if(memcmp(pCodecResult->ptrHsScchCodeInfo->ptrHsScchCodeNumberList,pExpectedResult->ptrHsScchCodeInfo->ptrHsScchCodeNumberList
			      ,sizeof(L1CAPI_DL_ChannelCodeNumber) * pCodecResult->ptrHsScchCodeInfo->codeCount))
			return 0;
	}
	if(pCodecResult->bit_mask& physShChRcfgExtensions_present)
	{
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask != 
			pExpectedResult->ptrPhysShChRcfgExtensions->bit_mask)
			return 0;
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & hsScchCellPowerOffset_present &&  
			pCodecResult->ptrPhysShChRcfgExtensions->hsScchCellPowerOffset != pExpectedResult->ptrPhysShChRcfgExtensions->hsScchCellPowerOffset)
			return 0;
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & eAgchRgchHichScramCode_present &&  
			pCodecResult->ptrPhysShChRcfgExtensions->eAgchRgchHichScramCode != pExpectedResult->ptrPhysShChRcfgExtensions->eAgchRgchHichScramCode)
			return 0;
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & maxTargetRTWP_present &&  
			pCodecResult->ptrPhysShChRcfgExtensions->maxTargetRTWP != pExpectedResult->ptrPhysShChRcfgExtensions->maxTargetRTWP)
			return 0;
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & refRTWP_present &&  
			pCodecResult->ptrPhysShChRcfgExtensions->refRTWP != pExpectedResult->ptrPhysShChRcfgExtensions->refRTWP)
			return 0;
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & rlCommonEDchInfo_present){
			if(memcmp(pCodecResult->ptrPhysShChRcfgExtensions->ptrRlCommonEDchInfo,
				      pExpectedResult->ptrPhysShChRcfgExtensions->ptrRlCommonEDchInfo,
					  sizeof(L1CAPI_Rl_Cmn_Edch_info)))
			return 0;
		}
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & eAgchCodeInfo_present){
			if(pCodecResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->codeChoice != 
				pExpectedResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->codeChoice)
				return 0;
			if(pCodecResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->codeCount != 
				pExpectedResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->codeCount)
				return 0;
			if(memcmp(pCodecResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->ptrAgchcodeNumberList,
				       pExpectedResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->ptrAgchcodeNumberList,
					   sizeof(L1CAPI_DL_ChannelCodeNumber) * pCodecResult->ptrPhysShChRcfgExtensions->ptrEagchCodeInfo->codeCount))
					   return 0;
		}
		if(pCodecResult->ptrPhysShChRcfgExtensions->bit_mask & eRgchHichCodeInfo_present){
			if(pCodecResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->codeChoice != 
				pExpectedResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->codeChoice)
				return 0;
			if(pCodecResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->codeCount != 
				pExpectedResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->codeCount)
				return 0;
			if(memcmp(pCodecResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->ptrRgchHichcodeNumberList,
				       pExpectedResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->ptrRgchHichcodeNumberList,
					   sizeof(L1CAPI_DL_ChannelCodeNumber) * pCodecResult->ptrPhysShChRcfgExtensions->ptrErgchHichCodeInfo->codeCount))
					   return 0;
		}
	}
	return 1;
}
