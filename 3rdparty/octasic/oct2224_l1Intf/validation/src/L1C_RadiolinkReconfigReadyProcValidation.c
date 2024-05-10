/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_RadiolinkReconfigReadyProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Reconfiguration Ready Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_RadiolinkReconfigReadyProcValidation.h"

/***********************
Octasic L1C API initial
************************/

static L1CAPI_CoordTrchRespItem l1c_CoordTrchInfoResp[2] = 
{
	{5,0xf0005},
	{5,0xf0006}
};

static L1CAPI_Edch_MacD_Flow_Info_resp l1c_edchMacDInfoResp[2] =
{
	{
		edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present,
		1,
		0xe0001,
		3
	},
	{
		edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present,
		2,
		0xe0002,
		3
	}
};

static L1CAPI_Edch_Fdd_Ctrl_Channel_Info l1c_edchFddCtrlChInfoResp = 
{
	eDch_Ch_Info_eAgchRgchHichScramCode_present |
	eDch_Ch_Info_eAgchChanCode_present|
	eDch_Ch_Info_primaryErnti_present|
	eDch_Ch_Info_secondaryErnti_present|
	eDch_Ch_Info_eRgchHichChanCode_present|
	eDch_Ch_Info_eRgchSignatureSeq_present|
	eDch_Ch_Info_eHichSignatureSeq_present|
	eDch_Ch_Info_servingGrantVal_present|
	eDch_Ch_Info_priSecGrantSelector_present|
	eDch_Ch_Info_eRgchReleaseInd_present,
	1,
	2,
	0xfefe,
	0xefef,
	1,
	0x11,
	0x22,
	0x01,
	L1CAPI_PRIMARY_E_RNTI,
	L1CAPI_E_RGCH_NOT_RELEASED
};

static L1CAPI_Edch_Fdd_Info_Resp l1c_EdchFddInfoResp = 
{
	edchRlSetId_present|edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present|edchFddCtrlChanInfo_present,
	1,
	4,
	2,
	l1c_edchMacDInfoResp,
	&l1c_edchFddCtrlChInfoResp
};

static L1CAPI_Radiolink_Info_Resp l1c_rlInfoResp = 
{
	edchFddInfoRsp_present,
	2,
	1,
	1,
	1,
	l1c_CoordTrchInfoResp,
	&l1c_EdchFddInfoResp
};

static L1CAPI_MacDFlow_Info_Resp l1c_HsMacDInfoResp[2]=
{
	{2,0xc2002},
	{3,0xc2003},
};

static L1CAPI_DL_ChannelCodeNumber l1c_hsScchChCodeResp[3] = 
{
	1,2,3
};

static L1CAPI_HSDSCH_Info_Resp l1c_hsInfoResp = 
{
	L1CAPI_HARQ_MEM_IMPLICIT,
	2,
	3,
	l1c_HsMacDInfoResp,
	l1c_hsScchChCodeResp,
	{
		{8}
	}
};

static L1CAPI_Radiolink_Reconfigure_Ready l1c_RlReconfigReady = 
{
	rl_ReconfigResp_hsdschInfoResp_present,
	1,
	{
		L1_MSG_SUCCESS,
		0,
		0
	},
	&l1c_rlInfoResp,
	&l1c_hsInfoResp
};

/***********************
Validation API
***********************/

L1CAPI_Radiolink_Reconfigure_Ready * getL1CRlReconfigRerady()
{
	return &l1c_RlReconfigReady;
}

uint8_t validateRlReconfigReadyCodecOutput(L1CAPI_Radiolink_Reconfigure_Ready * pCodecResult,L1CAPI_Radiolink_Reconfigure_Ready *pExpectedResult)
{
    uint8_t i;
    if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
      return 0;
    if(pCodecResult->rlCount != pExpectedResult->rlCount)
      return 0;
	if(memcmp(&pCodecResult->msgStatus,&pExpectedResult->msgStatus,sizeof(L1CAPI_Msg_Status)))
		return 0;
	for(i=0;i<pCodecResult->rlCount;i++){
		if(pCodecResult->ptrRlInfoResp[i].bit_mask != pExpectedResult->ptrRlInfoResp[i].bit_mask)
			return 0;
		if(pCodecResult->ptrRlInfoResp[i].coordTrchCount != pExpectedResult->ptrRlInfoResp[i].coordTrchCount)
			return 0;
		if(pCodecResult->ptrRlInfoResp[i].rL_ID != pExpectedResult->ptrRlInfoResp[i].rL_ID)
			return 0;
		if(pCodecResult->ptrRlInfoResp[i].rlSetId != pExpectedResult->ptrRlInfoResp[i].rlSetId)
			return 0;
		if(pCodecResult->ptrRlInfoResp[i].referenceRlId != pExpectedResult->ptrRlInfoResp[i].referenceRlId)
			return 0;		
		if(memcmp(pCodecResult->ptrRlInfoResp[i].ptrCoordTrchRsp,pExpectedResult->ptrRlInfoResp[i].ptrCoordTrchRsp,sizeof(L1CAPI_CoordTrchRespItem) * pExpectedResult->ptrRlInfoResp[i].coordTrchCount))
			return 0;
		if(pCodecResult->ptrRlInfoResp[i].bit_mask & edchFddInfoRsp_present){
			if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask != 
				pExpectedResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask)
				return 0;
			if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask &edchRlSetId_present)
			{
				if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->edchRlSetId != 
					pExpectedResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->edchRlSetId)
					return 0;
			}
			if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask &edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present)
			{
				if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->harqProcAlloc2ms_SchedTxGrant != 
					pExpectedResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->harqProcAlloc2ms_SchedTxGrant)
					return 0;
			}
			if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->mAcdFlowCount != 
				pExpectedResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->mAcdFlowCount)
				return 0;
			if(memcmp(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp,pExpectedResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp,sizeof(L1CAPI_Edch_MacD_Flow_Info_resp) * pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->mAcdFlowCount))
				return 0;			
			if(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask &edchFddCtrlChanInfo_present)
			{
				if(memcmp(pCodecResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo,pExpectedResult->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo,sizeof(L1CAPI_Edch_Fdd_Ctrl_Channel_Info) ))
					return 0;			
			}
		}
    }
	if(pCodecResult->bit_mask & rl_ReconfigResp_hsdschInfoResp_present)
	{
		if(pCodecResult->ptrHsdschInfoResp->harqMemChoice != 
			pExpectedResult->ptrHsdschInfoResp->harqMemChoice)
			return 0;
		if(pCodecResult->ptrHsdschInfoResp->macDFlowCount != 
			pExpectedResult->ptrHsdschInfoResp->macDFlowCount)
			return 0;
		if(pCodecResult->ptrHsdschInfoResp->hsscchCodeCount != 
			pExpectedResult->ptrHsdschInfoResp->hsscchCodeCount)
			return 0;
		if(memcmp(pCodecResult->ptrHsdschInfoResp->ptrMacDFlowInfo,pExpectedResult->ptrHsdschInfoResp->ptrMacDFlowInfo,sizeof(L1CAPI_MacDFlow_Info_Resp) * pCodecResult->ptrHsdschInfoResp->macDFlowCount))
			return 0;			
		if(memcmp(pCodecResult->ptrHsdschInfoResp->ptrHsscchInfoResp,pExpectedResult->ptrHsdschInfoResp->ptrHsscchInfoResp,sizeof(L1CAPI_DL_ChannelCodeNumber) * pCodecResult->ptrHsdschInfoResp->hsscchCodeCount))
			return 0;
		if(pCodecResult->ptrHsdschInfoResp->harqMemChoice == L1CAPI_HARQ_MEM_IMPLICIT){
			if(pCodecResult->ptrHsdschInfoResp->u.harqMemImplicit.nrOfProcess != 
				pExpectedResult->ptrHsdschInfoResp->u.harqMemImplicit.nrOfProcess)\
				return 0;
		}
	}
	return 1;
}
