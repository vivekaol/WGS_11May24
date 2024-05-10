/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_TFCS_CTFC_ProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Transport Format Combination Sequence, Coded Transport Format 
   Combination Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_TFCS_CTFC_ProcValidation.h"

uint8_t validateCTFCCodecOutput(L1CAPI_TFCS_Info * pCodecResult,L1CAPI_TFCS_Info *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->tfcsSize != pExpectedResult->tfcsSize)
		return 0;
	for(i=0;i<pCodecResult->tfcsSize;i++)
	{
		if(pCodecResult->ptrCctrchTfc[i].bit_mask != pExpectedResult->ptrCctrchTfc[i].bit_mask)
			return 0;
		if(pCodecResult->ptrCctrchTfc[i].cTFC != pExpectedResult->ptrCctrchTfc[i].cTFC)
			return 0;
		if(pCodecResult->ptrCctrchTfc[i].bit_mask & tFC_Beta_present){
			if(memcmp(pCodecResult->ptrCctrchTfc[i].ptrTFCBeta,pExpectedResult->ptrCctrchTfc[i].ptrTFCBeta,sizeof(L1CAPI_TFC_Beta)))
				return 0;
		}
	}
	return 1;
}

uint8_t validateTFSCodecOutput(L1CAPI_TransportFormatSet * pCodecResult,L1CAPI_TransportFormatSet *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->tti != pExpectedResult->tti)
		return 0;
	if(pCodecResult->crcType != pExpectedResult->crcType)
		return 0;
	if(pCodecResult->codingType != pExpectedResult->codingType)
		return 0;
	if(pCodecResult->codingRate != pExpectedResult->codingRate)
		return 0;
	if(pCodecResult->rmAttrib != pExpectedResult->rmAttrib)
		return 0;
	if(pCodecResult->tfCount != pExpectedResult->tfCount)
		return 0;
	for(i=0;i<pCodecResult->tfCount;i++)
	{
		if(memcmp(&(pCodecResult->ptrTransFormat[i]),&(pExpectedResult->ptrTransFormat[i]),sizeof(L1CAPI_TFS_DynamicPartListItem)))
			return 0;
	}
	return 1;
}
