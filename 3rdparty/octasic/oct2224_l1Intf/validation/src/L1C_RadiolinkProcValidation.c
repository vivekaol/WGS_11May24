/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_RadiolinkProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control RadioLink Procedure Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_RadiolinkProcValidation.h"
#include "L1C_TFCS_CTFC_ProcValidation.h"
/***********************
CCPU L1 API initial
************************/

/***********************
Octasic L1C API initial
************************/
static L1CAPI_DL_CodeInfo l1c_dlCodeInfo = 
{
	12,
	8,
	L1CAPI_TX_GAP_NO_CODE_CHANGE
};

static L1CAPI_RadioLink_Info l1c_rlInfo =
{
	propagationDelay_present|diversityControlField_present|rl_info_transmitDiverIndicator_present|delayedActivation_present,
	1,
	1,
	0,
	1,
	0,
	0,
	0,
	L1CAPI_DIV_MUST_NOT_COMBINE,
	(290-350),
	(350-350),
	(250-350),
	L1CAPI_TSTD_INDICATOR_INACTIVE,
	&l1c_dlCodeInfo,
	{
		cfn_indication,
		10
	},
	NULL
};


static L1CAPI_TFS_DynamicPartListItem l1c_DchTf[4] =
{
	{0,656},
	{1,656},
	{2,656},
	{3,656}
};

static L1CAPI_TransportFormatSet l1c_ULTFS =
{
	4,
	L1CAPI_MSEC_20,
	L1CAPI_TFS_CRC_SIZE_V12,
	L1CAPI_TURBO_CODING,
	L1CAPI_ONETHIRD_RATE,
	(189+1),
	l1c_DchTf
};

static L1CAPI_TransportFormatSet l1c_DLTFS =
{
	4,
	L1CAPI_MSEC_10,
	L1CAPI_TFS_CRC_SIZE_V16,
	L1CAPI_TURBO_CODING,
	L1CAPI_ONETHIRD_RATE,
	(185+1),
	l1c_DchTf
};

static L1CAPI_DCH_Info l1c_DchInfo[2] =
{
	{
		tfsDL_present|tfsUL_present,
		1,
		L1CAPI_QE_NON_SELECTED,
		&l1c_DLTFS,
		&l1c_ULTFS
	},
	{
		tfsDL_present|tfsUL_present,
		2,
		L1CAPI_QE_NON_SELECTED,
		&l1c_DLTFS,
		&l1c_ULTFS
	}
};

static L1CAPI_DCH_CoordTrchInfoListItem l1_CordTrchInfo[2] =
{
	{
		toAws_present|toAwe_present|payloadCRC_presenceIndicator_present|ulFpMode_present,
		2,                                     /*dchCount;*/
		0,									   /*toAWS;*/
		0,									   /*toAWE;*/
		L1CAPI_CRC_NOTINCLUDED,		           /*payloadCRC_PresenceIndicator;*/
		L1CAPI_FPMODE_NORMAL,				   /*ul_FP_Mode;*/
		l1c_DchInfo							   /**ptrDCHSpecificInfo;*/
	},
	{
		toAws_present|toAwe_present|payloadCRC_presenceIndicator_present|ulFpMode_present,
		2,                                     /*dchCount;*/
		0,									   /*toAWS;*/
		0,									   /*toAWE;*/
		L1CAPI_CRC_NOTINCLUDED,		           /*payloadCRC_PresenceIndicator;*/
		L1CAPI_FPMODE_NORMAL,				   /*ul_FP_Mode;*/
		l1c_DchInfo							   /**ptrDCHSpecificInfo;*/
	},
};

static L1CAPI_TFCS_Info_Item l1c_DlCtfcInfo[8] = 
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
		2,
		NULL
	},	
	{                        
		0,
		3,
		NULL
	},
	{                        
		0,
		5,
		NULL
	},
	{                        
		0,
		6,
		NULL
	},	
	{                        
		0,
		7,
		NULL
	},	
	{                        
		0,
		9,
		NULL
	}
};
static L1CAPI_TFC_Beta l1c_BetaCDInfo = 
{
	L1CAPI_SIGNALLED_GF,
	1,
	2,
	1
};
static L1CAPI_TFC_Beta l1c_BetaCDInfo2 = 
{
	L1CAPI_COMPUTED_GF,
	1,
	2,
	1
};

static L1CAPI_TFCS_Info_Item l1c_UlCtfcInfo[8] = 
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
	},
	{                        
		tFC_Beta_present,
		5,
		&l1c_BetaCDInfo2
	},
	{                        
		tFC_Beta_present,
		6,
		&l1c_BetaCDInfo2
	},	
	{                        
		tFC_Beta_present,
		7,
		&l1c_BetaCDInfo2
	},	
	{                        
		tFC_Beta_present,
		9,
		&l1c_BetaCDInfo2
	}
};

static L1CAPI_Radiolink_Setup_Request l1c_RlSetupReq = 
{
	0,
	{
		1,
		2,
		0
	},
	&l1c_rlInfo,
	l1_CordTrchInfo,
	{
		DL_DPCH_RL_Setup_tFCI_present,
		14,
		1,
		L1CAPI_FIXED,
		{0,0,0},
		L1CAPI_TPC_STEP_SIZE1_5,
		L1CAPI_LIMITED_PWR_INC_NOT_USED,
		L1CAPI_INNERLOOPDLPC_INACTIVE
	},
	{
		8,
		l1c_DlCtfcInfo
	},
	{
		UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present|UL_DPCH_Setup_DpcMode_present|UL_DPCH_Setup_IndEDch_present,
		{0,L1CAPI_UL_SCRAMCODELENGTH_LONG},
		L1CAPI_MINUL_CHANNELCODE_LEN_v8,
		1,
		10,
		0,
		-81,
		L1CAPI_DIV_NONE,
		L1CAPI_DPC_MODE0,
		L1CAPI_UL_DPDCH_PRESENT
	},
	{
		8,
		l1c_UlCtfcInfo
	},
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

static L1CAPI_EDCH_RL_InfoExtension l1c_RlEdchInfoExt = 
{
	eDchRlInd_present|rlSpecificEDchInfo_present,L1CAPI_RL_EDCH,
	{
		e_AGCH_PowerOffset_present|e_RGCH_PowerOffset_present|e_HICH_PowerOffset_present
		,1
		,2,
		3
	}
};

static L1CAPI_Radiolink_Reconfig_params l1c_rlReconfigInfo =
{
	maxDlPower_present|minDlPower_present|rl_reconfig_transmitDiverIndicator_present|dlDpchTimingAdj_present|eDchRlReconfigInfoExtension_present,
	1,
	1,
	(350-350),
	(250-350),
	(250-350),
	L1CAPI_TSTD_INDICATOR_INACTIVE,
	L1CAPI_DL_DPCH_TIMING_ADJ_ADVANCE,
	&l1c_dlCodeInfo,
    &l1c_RlEdchInfoExt
};

static L1CAPI_DL_DPCH_PhyInfo_Reconfig l1c_DlDpchReconfig =
{
	DL_DPCH_RL_Reconfig_SlotFormat_present|DL_DPCH_RL_Reconfig_tFCI_present|DL_DPCH_RL_Reconfig_MuxPos_present|DL_DPCH_RL_Reconfig_LimitedPwrInc_present,
	14,
	1,
	L1CAPI_FIXED,
	L1CAPI_LIMITED_PWR_INC_NOT_USED
};

static L1CAPI_UL_DPCH_PhyInfo_Reconfig l1cUlDpchReconfig =
{
	UL_DPCH_Reconfig_UlScramCodeInfo_present|UL_DPCH_Reconfig_MinChanCodeLen_present|
	UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present|UL_DPCH_Reconfig_UlPuncLimit_present|
	UL_DPCH_Reconfig_UlSlotFormat_present|UL_DPCH_Reconfig_UlSIR_present|
	UL_DPCH_Reconfig_DiversityMode_present|UL_DPCH_Reconfig_IndEDch_present,
	{0,L1CAPI_UL_SCRAMCODELENGTH_LONG},
	L1CAPI_MINUL_CHANNELCODE_LEN_v8,
	1,
	10,
	0,
	1-82,
	L1CAPI_DPC_MODE0,
	L1CAPI_UL_DPDCH_PRESENT
};

static L1CAPI_HSDSCH_MACdFlow_ID l1c_hsMacDFlowInfo[2] = 
{
	0,1
};
static L1CAPI_MACDPDU_Size_IndexItem l1c_macDPduSizeIndex[2] = 
{
	{0,656},{1,336}
};

static L1CAPI_PriorityQueue_Info l1c_priQInfo[2] =
{
	{
		discardTimer_present|mac_hsWindowSz_present|t1_present|mAChsGuaranteedBitRate_present|
		rlMode_present|associatedHSDSCH_MACdFlow_present,
		0,
		15,
		L1CAPI_T1_V100,
		L1CAPI_DISCARDTIMER_V500,
		L1CAPI_MAC_HSWINDOWSIZE_V24,
		100000,
		0,
		L1CAPI_RLC_AM,
		2,
		l1c_macDPduSizeIndex,
	},
	{
		discardTimer_present|mac_hsWindowSz_present|
		rlMode_present|associatedHSDSCH_MACdFlow_present,
		1,
		15,
		L1CAPI_T1_V160,
		L1CAPI_DISCARDTIMER_V500,
		L1CAPI_MAC_HSWINDOWSIZE_V24,
		200000,
		1,
		L1CAPI_RLC_AM,
		2,
		l1c_macDPduSizeIndex,
	}
};
static L1CAPI_RadioLink_HSDSCH_Info l1c_hsInfo  =
{
	hsscch_PowerOffset_present|measurement_Power_Offset_present,
	7,
	200,
	L1CAPI_CQI_FEEDBACK_CYCLE_V10,
	4,
	2,
	0,
	0,
	0,
	-4,
	0-12,
	{
		2,
		2,
		l1c_hsMacDFlowInfo,
		l1c_priQInfo
	}
};

static L1CAPI_PriorityQueue_Reconfig_Info l1c_hsPriqReconfig[2] =
{
	{
		L1CAPI_PRI_QUEUE_ADD,
		&l1c_priQInfo[0]
	},
	{
		L1CAPI_PRI_QUEUE_ADD,
		&l1c_priQInfo[1]
	}
};

static L1CAPI_HSDSCH_MACdFlows_Reconfig_Info l1c_hsMacdReconfig =
{
	2,
	2,
	l1c_hsMacDFlowInfo,
	l1c_hsPriqReconfig
};

static L1CAPI_RadioLink_HSDSCH_Reconfig_Info l1c_hsModifyInfo =
{
	macHsReorderBufSz_present|cqiFeedbackCycle_present|
	cqiRepetitionFactor_present|ackNackRepetitionFactor_present|
	cqiPO_present|ackPO_present|nackPO_present|hsscchPO_present|
	measmentPO_present|hsdschMacDFlowReconfigInfo_present,
	200,
	L1CAPI_CQI_FEEDBACK_CYCLE_V10,
	3,
	2,
	0,
	0,
	0,
	0-4,
	0-12,
	&l1c_hsMacdReconfig
};

static L1CAPI_Radiolink_HSDSCH_Reconfig l1c_HsReconfig =
{
	HSDSCH_RECONFIG_Rnti_present|HSDSCH_RECONFIG_Rlid_present|
	HSDSCH_RECONFIG_HsdschInfo_present/*|HSDSCH_RECONFIG_HsdschModify_present*/,
	0x00fe,
	1,
	&l1c_hsInfo,
	NULL,
	NULL,
	NULL
};

static L1CAPI_Ref_E_TFCI_InfoItem l1c_etfcsInfoItem[2] = 
{
	{1,2},
	{3,4}
};

static L1CAPI_E_TFCS_Info l1c_etfcsInfo =
{
	e_DCH_Min_Set_E_TFCI_present,
	0,
	0,
	2,
	l1c_etfcsInfoItem
};

static L1CAPI_Radiolink_EDpch_Reconfig_Info l1c_edpchReconfigInfo =
{
	Edpch_Reconfig_MaxSetEdpchs_present|Edpch_Reconfig_PuncLimit_present|
	Edpch_Reconfig_ETTI_present|Edpch_Reconfig_PwrOffset_present|
	Edpch_Reconfig_Rgch2Threshold_present|Edpch_Reconfig_Rgch3Threshold_present|
	Edpch_Reconfig_HarqInfo_present|Edpch_Reconfig_HsdschConfigInd_present|Edpch_Reconfig_ETfcsInfo_present,
	L1CAPI_MAX_SET_EDPDCH_VN16,
	2,
	L1CAPI_E_TTI_2MS,
	0,
	1,
	1,
	L1CAPI_HARQ_EDCH_RVTABLE,
	L1CAPI_CONFIGURED_HS_DSCH,
	&l1c_etfcsInfo
};

static L1CAPI_E_DCH_NonScheduled_TxGrantItems l1c_edchNonSchedGrantItem = 
{
	hARQ_Ps_An_NnSchd_2ms_present,
	1024,
	2
};

static L1CAPI_MACdPDU_Size l1c_edchMacDPduSize1 = 656;
static L1CAPI_E_DCH_LogicalChannelInfo l1c_edchLogicCHInfo[2] = 
{
	{
		schedulingPriorityIndicator_present|schedulingInformation_present|mACesGuaranteedBitRate_present|eDCH_DDI_Value_present,
		1,
		1,
		L1CAPI_EDCH_SCHEDULING_INCLUDED,
		65536,
		2,
		1,
		&l1c_edchMacDPduSize1
	},
	{
		schedulingPriorityIndicator_present|schedulingInformation_present|mACesGuaranteedBitRate_present|eDCH_DDI_Value_present,
		2,
		2,
		L1CAPI_EDCH_SCHEDULING_INCLUDED,
		65536,
		2,
		1,
		&l1c_edchMacDPduSize1	
	}
};

static L1CAPI_E_DCH_MACDFlow_Info l1c_edchMacDFlowInfo[2] = 
{
	{
		eDCH_MACdFlow_Multiplexing_present|eDCH_MACdFlow_bundlingModeIndicator_present|eDCH_MACdFlow_eDchNonSchedGrantInfo_present,
		0,
		L1CAPI_CRC_NOTINCLUDED,
		11,
		0,
		0,
		L1CAPI_EDCH_GRANTTYPE_SCHEDULED,
		L1CAPI_EDCH_BUNDINGMODE,
		&l1c_edchNonSchedGrantItem,
		2,
		l1c_edchLogicCHInfo
	},
	{
		eDCH_MACdFlow_Multiplexing_present|eDCH_MACdFlow_bundlingModeIndicator_present|eDCH_MACdFlow_eDchNonSchedGrantInfo_present,
		1,
		L1CAPI_CRC_NOTINCLUDED,
		11,
		0,
		0,
		L1CAPI_EDCH_GRANTTYPE_SCHEDULED,
		L1CAPI_EDCH_BUNDINGMODE,
		&l1c_edchNonSchedGrantItem,
		2,
		l1c_edchLogicCHInfo
		}
};

static L1CAPI_E_DCH_FDD_Info l1c_edchFddInfo =
{
	hARQ_Pc_Ac_Sd_2ms_EDCH_present|e_DCH_Maximum_Bitrate_present|e_DCH_Reference_Pwr_Offset_present,
	2,
	5698,
	0,
	0,
	2,
	l1c_edchMacDFlowInfo
};

static L1CAPI_Radiolink_EDCH_Reconfig_Ext l1c_EdchReconfig =
{
	rl_Reconfig_EdpchInfo_present|rl_Reconfig_EdchFddInfo_present,
	&l1c_edpchReconfigInfo,
	&l1c_edchFddInfo,
	NULL,
	NULL,
	NULL,
	NULL
};

static L1CAPI_DCH_ID l1c_delTrch[2] =
{1,2};
static L1CAPI_Radiolink_Reconfig_Prepare l1c_RlReconfigPre = 
{
	/*rl_Reconfig_physDlDpch_present|*/rl_Reconfig_physUlDpch_present|rl_Reconfig_hsdsch_present|rl_Reconfig_eDchRlSetupExtension_present,
	0,
	{1,2,2,2,0},
	&l1c_rlReconfigInfo,
	l1c_delTrch,
	l1_CordTrchInfo,
	l1_CordTrchInfo,
	&l1c_DlDpchReconfig,
	&l1cUlDpchReconfig,
	{
		8,
		l1c_DlCtfcInfo
	},
	{
		8,
		l1c_UlCtfcInfo
	},
	NULL,
	&l1c_HsReconfig,
	&l1c_EdchReconfig
};

static L1CAPI_Active_Pattern_Seq4 l1c_actvPatternSeq[2] =
{
	{
		1,
		20,
		3
	},
	{
		1,
		20,
		3
	}
};

static L1CAPI_Active_Pattern_Sequence_Info l1c_activePatternInfo = 
{
	222,
	2,
	l1c_actvPatternSeq
};

static L1CAPI_Radiolink_ReconfigCommit l1c_RlReconfigCommit =
{
	0/*activePattSeqInfo_present*/,
	1,
	234,
	&l1c_activePatternInfo
};

static L1CAPI_Radiolink_ID l1c_rlIds[3] = 
{
	1,2,3
};

static L1CAPI_Radiolink_DeletionRequest l1c_RlDel = 
{
	2,
	3,
	l1c_rlIds
};
/***********************
Validation API
***********************/


L1CAPI_Radiolink_Setup_Request * getL1CRadiolinkSetupRequest()
{
	return &l1c_RlSetupReq;
}

L1CAPI_Radiolink_Reconfig_Prepare * getL1CRadiolinkReconfigPrepare()
{
	return &l1c_RlReconfigPre;
}

L1CAPI_Radiolink_ReconfigCommit * getL1CRadiolinkReconfigCommit()
{
	return &l1c_RlReconfigCommit;
}

L1CAPI_Radiolink_DeletionRequest * getL1CRadiolinkDeletion()
{
	return &l1c_RlDel;
}

static uint8_t validateRlInfo(L1CAPI_RadioLink_Info *pCodecResult,L1CAPI_RadioLink_Info * pExpectedResult)
{

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->dlCodeCount != pExpectedResult->dlCodeCount)
		return 0;
	if(pCodecResult->rL_ID != pExpectedResult->rL_ID)
		return 0;
	if(pCodecResult->c_ID != pExpectedResult->c_ID)
		return 0;
	if(pCodecResult->firstRLS_indicator != pExpectedResult->firstRLS_indicator)
		return 0;
	if(pCodecResult->frameOffset != pExpectedResult->frameOffset)
		return 0;
	if(pCodecResult->chipOffset != pExpectedResult->chipOffset)
		return 0;
	if(pCodecResult->bit_mask  & propagationDelay_present && pCodecResult->propagationDelay != pExpectedResult->propagationDelay)
		return 0;
	if(pCodecResult->bit_mask  & diversityControlField_present && pCodecResult->diversityControlField != pExpectedResult->diversityControlField)
		return 0;
	if(pCodecResult->initialDL_transmissionPower != pExpectedResult->initialDL_transmissionPower)
		return 0;
	if(pCodecResult->maximumDL_power != pExpectedResult->maximumDL_power)
		return 0;
	if(pCodecResult->minimumDL_power != pExpectedResult->minimumDL_power)
		return 0;
	if(pCodecResult->bit_mask  & rl_info_transmitDiverIndicator_present && pCodecResult->transmitDiversityIndicator != pExpectedResult->transmitDiversityIndicator)
		return 0;
	if(memcmp(pCodecResult->ptrDlCodeInfo,pExpectedResult->ptrDlCodeInfo,sizeof(L1CAPI_DL_CodeInfo) * pCodecResult->dlCodeCount))
		return 0;
	if(pCodecResult->bit_mask  & delayedActivation_present)
	{
		if(memcmp(&pCodecResult->delayedActivation,&pExpectedResult->delayedActivation,sizeof(L1CAPI_DelayedActivation)))
			return 0;
	}
	if(pCodecResult->bit_mask  & eDchRlInfoExtension_present)
	{
		if(memcmp(pCodecResult->ptrEDchRlInfoExtension,pExpectedResult->ptrEDchRlInfoExtension,sizeof(L1CAPI_EDCH_RL_InfoExtension)))
			return 0;
	}
	return 1;
}

static uint8_t validateRlReconfigInfo(L1CAPI_Radiolink_Reconfig_params *pCodecResult,L1CAPI_Radiolink_Reconfig_params * pExpectedResult)
{

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->dlCodeCount != pExpectedResult->dlCodeCount)
		return 0;
	if(pCodecResult->rL_ID != pExpectedResult->rL_ID)
		return 0;
	if(pCodecResult->bit_mask  & maxDlPower_present && pCodecResult->maximumDL_power != pExpectedResult->maximumDL_power)
		return 0;
	if(pCodecResult->bit_mask  & minDlPower_present && pCodecResult->minimumDL_power != pExpectedResult->minimumDL_power)
		return 0;
	if(pCodecResult->bit_mask  & dlRefPower_present && pCodecResult->dL_reference_power != pExpectedResult->dL_reference_power)
		return 0;
	if(pCodecResult->bit_mask  & rl_reconfig_transmitDiverIndicator_present && pCodecResult->transmitDiversityIndicator != pExpectedResult->transmitDiversityIndicator)
		return 0;
	if(pCodecResult->bit_mask  & dlDpchTimingAdj_present && pCodecResult->dl_dpch_timing_adj != pExpectedResult->dl_dpch_timing_adj)
		return 0;
	if(memcmp(pCodecResult->ptrDlCodeInfo,pExpectedResult->ptrDlCodeInfo,sizeof(L1CAPI_DL_CodeInfo) * pCodecResult->dlCodeCount))
		return 0;
	if(pCodecResult->bit_mask  & eDchRlInfoExtension_present)
	{
		if(memcmp(pCodecResult->ptrEDchRlInfoExtension,pExpectedResult->ptrEDchRlInfoExtension,sizeof(L1CAPI_EDCH_RL_InfoExtension)))
			return 0;
	}
	return 1;
}

static uint8_t validateDchTrchInfo(L1CAPI_DCH_Info *pCodecResult,L1CAPI_DCH_Info * pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->dCH_ID != pExpectedResult->dCH_ID)
		return 0;
	if(pCodecResult->qE_Selector != pExpectedResult->qE_Selector)
		return 0;
	if(pCodecResult->bit_mask & tfsDL_present && (!validateTFSCodecOutput(pCodecResult->ptrTfsDL,pExpectedResult->ptrTfsDL)))
		return 0;
	if(pCodecResult->bit_mask & tfsUL_present && (!validateTFSCodecOutput(pCodecResult->ptrTfsUL,pExpectedResult->ptrTfsUL)))
		return 0;
	return 1;
}

static uint8_t validateCordTrchInfo(L1CAPI_DCH_CoordTrchInfoListItem * pCodecResult,L1CAPI_DCH_CoordTrchInfoListItem * pExpectedResult)
{
	uint8_t i;
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->dchCount != pExpectedResult->dchCount)
		return 0;
	if(pCodecResult->toAWS != pExpectedResult->toAWS)
		return 0;
	if(pCodecResult->toAWE != pExpectedResult->toAWE)
		return 0;
	if(pCodecResult->payloadCRC_PresenceIndicator != pExpectedResult->payloadCRC_PresenceIndicator)
		return 0;
	if(pCodecResult->ul_FP_Mode != pExpectedResult->ul_FP_Mode)
		return 0;
	for(i=0;i<pCodecResult->dchCount;i++)
	{
		if(!validateDchTrchInfo(&pCodecResult->ptrDCHSpecificInfo[i],&pExpectedResult->ptrDCHSpecificInfo[i]))
			return 0;
	}
	return 1;
}

static uint8_t validateActvPattern(L1CAPI_Active_Pattern_Sequence_Info * pCodecResult,L1CAPI_Active_Pattern_Sequence_Info * pExpectedResult)
{
	if(pCodecResult->cMConfigurationChangeCFN != pExpectedResult->cMConfigurationChangeCFN)
		return 0;
	if(pCodecResult->tgpssCount != pExpectedResult->tgpssCount)
		return 0;
	if(memcmp(pCodecResult->ptrTgpss,pExpectedResult->ptrTgpss,sizeof(L1CAPI_Active_Pattern_Seq4) * pCodecResult->tgpssCount))
		return 0;
	return 1;
}

static uint8_t validateMacHsPriQInfo(L1CAPI_PriorityQueue_Info *pCodecResult, L1CAPI_PriorityQueue_Info* pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->priorityQueueId != pExpectedResult->priorityQueueId)
		return 0;
	if(pCodecResult->schedulingPriorityIndicator != pExpectedResult->schedulingPriorityIndicator)
		return 0;
	if((pCodecResult->bit_mask & t1_present)
		&&(pCodecResult->t1 != pExpectedResult->t1))
		return 0;
	if((pCodecResult->bit_mask & discardTimer_present)
		&&(pCodecResult->discardTimer != pExpectedResult->discardTimer))
		return 0;
	if((pCodecResult->bit_mask & mac_hsWindowSz_present)
		&&(pCodecResult->mAC_hsWindowSize != pExpectedResult->mAC_hsWindowSize))
		return 0;
	if((pCodecResult->bit_mask & mAChsGuaranteedBitRate_present)
		&&(pCodecResult->mAChsGuaranteedBitRate != pExpectedResult->mAChsGuaranteedBitRate))
		return 0;
	if((pCodecResult->bit_mask & rlMode_present)
		&&(pCodecResult->rLC_Mode != pExpectedResult->rLC_Mode))
		return 0;
	if((pCodecResult->bit_mask & associatedHSDSCH_MACdFlow_present)
		&&(pCodecResult->associatedHSDSCH_MACdFlow != pExpectedResult->associatedHSDSCH_MACdFlow))
		return 0;
	if(pCodecResult->macDPduIndexCount != pExpectedResult->macDPduIndexCount)
		return 0;	
	if(memcmp(pCodecResult->ptrMacdPDU_Size_Index,pExpectedResult->ptrMacdPDU_Size_Index,sizeof(L1CAPI_MACDPDU_Size_IndexItem) * pCodecResult->macDPduIndexCount))
		return 0;
	return 1;
}

static uint8_t validateMacHsPriQReconfigInfo(L1CAPI_PriorityQueue_Reconfig_Info *pCodecResult, L1CAPI_PriorityQueue_Reconfig_Info* pExpectedResult)
{
	if(pCodecResult->priQueueAdjType != pExpectedResult->priQueueAdjType)
		return 0;
	if(pCodecResult->priQueueAdjType == L1CAPI_PRI_QUEUE_ADD)
	{
		if(!validateMacHsPriQInfo(pCodecResult->u.ptrPriorityQueueAdd_Info,pExpectedResult->u.ptrPriorityQueueAdd_Info))
			return 0;
	}
	else if(pCodecResult->priQueueAdjType == L1CAPI_PRI_QUEUE_MOD)
	{
		if(!validateMacHsPriQInfo(pCodecResult->u.ptrPriorityQueueMod_Info,pExpectedResult->u.ptrPriorityQueueMod_Info))
			return 0;
	}
	else{
		if(pCodecResult->u.priorityQueueDel_Info != pExpectedResult->u.priorityQueueDel_Info)
			return 0;
	}
	return 1;
}

static uint8_t validateMacHsMacDFlowInfo(L1CAPI_HSDSCH_MACdFlows_Info *pCodecResult ,L1CAPI_HSDSCH_MACdFlows_Info * pExpectedResult)
{
	if((pCodecResult->macDFlowCount != pExpectedResult->macDFlowCount) ||
		(pCodecResult->priorityQueueCount != pExpectedResult->priorityQueueCount)
		)
		return 0;
	if(memcmp(pCodecResult->ptrHDSCH_MACdFlow_Info,pExpectedResult->ptrHDSCH_MACdFlow_Info,sizeof(L1CAPI_HSDSCH_MACdFlow_ID)*pCodecResult->macDFlowCount ))
		return 0;
	if(!validateMacHsPriQInfo(pCodecResult->ptrPriorityQueue_Info,pExpectedResult->ptrPriorityQueue_Info))
		return 0;
	return 1;
}

static uint8_t validateMacHsMacDFlowDelInfo(L1CAPI_HSDSCH_MACdFlows_Delete_Info *pCodecResult ,L1CAPI_HSDSCH_MACdFlows_Delete_Info * pExpectedResult)
{
	if(pCodecResult->macDFlowCount != pExpectedResult->macDFlowCount)
		return 0;
	if(memcmp(pCodecResult->ptrHDSCH_MACdFlow_Info,pExpectedResult->ptrHDSCH_MACdFlow_Info,sizeof(L1CAPI_HSDSCH_MACdFlow_ID) * pCodecResult->macDFlowCount))
		return 0;
	return 1;
}

static uint8_t validateMacHsMacDFlowReconfigInfo(L1CAPI_HSDSCH_MACdFlows_Reconfig_Info *pCodecResult ,L1CAPI_HSDSCH_MACdFlows_Reconfig_Info * pExpectedResult)
{
	if((pCodecResult->macDFlowCount != pExpectedResult->macDFlowCount) ||
		(pCodecResult->priorityQueueCount != pExpectedResult->priorityQueueCount)
		)
		return 0;
	if(memcmp(pCodecResult->ptrHDSCH_MACdFlow_Info,pExpectedResult->ptrHDSCH_MACdFlow_Info,sizeof(L1CAPI_HSDSCH_MACdFlow_ID)*pCodecResult->macDFlowCount ))
		return 0;
	if(!validateMacHsPriQReconfigInfo(pCodecResult->ptrPriorityQueue_Info,pExpectedResult->ptrPriorityQueue_Info))
		return 0;
	return 1;
}

static uint8_t validateHsdschInfo(L1CAPI_RadioLink_HSDSCH_Info * pCodecResult,L1CAPI_RadioLink_HSDSCH_Info *pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->hsdcschPhysCat != pExpectedResult->hsdcschPhysCat)
		return 0;
	if(pCodecResult->macHsReorderBuffSz != pExpectedResult->macHsReorderBuffSz)
		return 0;
	if(pCodecResult->cqiFeedback_CycleK != pExpectedResult->cqiFeedback_CycleK)
		return 0;
	if(pCodecResult->cqiRepetitionFactor != pExpectedResult->cqiRepetitionFactor)
		return 0;
	if(pCodecResult->ackNackRepetitionFactor != pExpectedResult->ackNackRepetitionFactor)
		return 0;
	if(pCodecResult->cqiPowerOffset != pExpectedResult->cqiPowerOffset)
		return 0;
	if(pCodecResult->ackPowerOffset != pExpectedResult->ackPowerOffset)
		return 0;
	if(pCodecResult->nackPowerOffset != pExpectedResult->nackPowerOffset)
		return 0;
	if(pCodecResult->bit_mask & hsscch_PowerOffset_present && pCodecResult->hsscch_PowerOffset != pExpectedResult->hsscch_PowerOffset )
		return 0;
	if(pCodecResult->bit_mask & measurement_Power_Offset_present && pCodecResult->measurement_Power_Offset != pExpectedResult->measurement_Power_Offset)
		return 0;
	if(!validateMacHsMacDFlowInfo(&pCodecResult->hsdschMacDFlowInfo,&pExpectedResult->hsdschMacDFlowInfo))
		return 0;
	return 1;
}

static uint8_t validateHsdschReconfigInfo(L1CAPI_RadioLink_HSDSCH_Reconfig_Info * pCodecResult,L1CAPI_RadioLink_HSDSCH_Reconfig_Info *pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->bit_mask & macHsReorderBufSz_present && pCodecResult->macHsReorderBuffSz != pExpectedResult->macHsReorderBuffSz)
		return 0;
	if(pCodecResult->bit_mask & cqiFeedbackCycle_present && pCodecResult->cqiFeedback_CycleK != pExpectedResult->cqiFeedback_CycleK)
		return 0;
	if(pCodecResult->bit_mask & cqiRepetitionFactor_present && pCodecResult->cqiRepetitionFactor != pExpectedResult->cqiRepetitionFactor)
		return 0;
	if(pCodecResult->bit_mask & ackNackRepetitionFactor_present && pCodecResult->ackNackRepetitionFactor != pExpectedResult->ackNackRepetitionFactor)
		return 0;
	if(pCodecResult->bit_mask & cqiPO_present && pCodecResult->cqiPowerOffset != pExpectedResult->cqiPowerOffset)
		return 0;
	if(pCodecResult->bit_mask & ackPO_present && pCodecResult->ackPowerOffset != pExpectedResult->ackPowerOffset)
		return 0;
	if(pCodecResult->bit_mask & nackPO_present && pCodecResult->nackPowerOffset != pExpectedResult->nackPowerOffset)
		return 0;
	if(pCodecResult->bit_mask & hsscchPO_present && pCodecResult->hsscch_PowerOffset != pExpectedResult->hsscch_PowerOffset )
		return 0;
	if(pCodecResult->bit_mask & measmentPO_present && pCodecResult->measurement_Power_Offset != pExpectedResult->measurement_Power_Offset)
		return 0;
	if(!validateMacHsMacDFlowReconfigInfo(pCodecResult->ptrHsdschMacDFlowReconfigInfo,pExpectedResult->ptrHsdschMacDFlowReconfigInfo))
		return 0;
	return 1;
}

static uint8_t validateETFCSInfo(L1CAPI_E_TFCS_Info *pCodecResult, L1CAPI_E_TFCS_Info * pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->e_DCH_TFCI_Table_Index != pExpectedResult->e_DCH_TFCI_Table_Index)
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Min_Set_E_TFCI_present) &&
		pCodecResult->e_DCH_Min_Set_E_TFCI != pExpectedResult->e_DCH_Min_Set_E_TFCI)
		return 0;
	if(pCodecResult->refETfciCount != pExpectedResult->refETfciCount)
		return 0;
	if(memcmp(pCodecResult->ptrReference_E_TFCI_Information,pExpectedResult->ptrReference_E_TFCI_Information,sizeof(L1CAPI_Ref_E_TFCI_InfoItem) * pExpectedResult->refETfciCount))
		return 0;
	return 1;
}

static uint8_t validateEDpchInfo(L1CAPI_Radiolink_EDpch_Info * pCodecResult, L1CAPI_Radiolink_EDpch_Info * pExpectedResult)
{
	if((pCodecResult->maxSet_E_DPDCHs != pExpectedResult->maxSet_E_DPDCHs) ||
		(pCodecResult->ul_PunctureLimit != pExpectedResult->ul_PunctureLimit) ||
		(pCodecResult->e_TTI != pExpectedResult->e_TTI) ||
		(pCodecResult->e_DPCCH_PowerOFfset != pExpectedResult->e_DPCCH_PowerOFfset) ||
		(pCodecResult->e_RGCH_2_IndexStepThreshold != pExpectedResult->e_RGCH_2_IndexStepThreshold) ||
		(pCodecResult->e_RGCH_3_IndexStepThreshold != pExpectedResult->e_RGCH_3_IndexStepThreshold) ||
		(pCodecResult->hARQ_Info_for_E_DCH != pExpectedResult->hARQ_Info_for_E_DCH) ||
		(pCodecResult->hSDSCH_Configured_Indicator != pExpectedResult->hSDSCH_Configured_Indicator)
		)
		return 0;
	if(!validateETFCSInfo(&pCodecResult->e_TFCS_Information,&pExpectedResult->e_TFCS_Information))
		return 0;
	return 1;
}

static uint8_t validateEDpchReconfigInfo(L1CAPI_Radiolink_EDpch_Reconfig_Info * pCodecResult, L1CAPI_Radiolink_EDpch_Reconfig_Info * pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_MaxSetEdpchs_present) &&
		(pCodecResult->maxSet_E_DPDCHs != pExpectedResult->maxSet_E_DPDCHs))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_PuncLimit_present) &&
		(pCodecResult->ul_PunctureLimit != pExpectedResult->ul_PunctureLimit))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_ETTI_present) &&
		(pCodecResult->e_TTI != pExpectedResult->e_TTI))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_PwrOffset_present) &&
		(pCodecResult->e_DPCCH_PowerOFfset != pExpectedResult->e_DPCCH_PowerOFfset))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_Rgch2Threshold_present) &&
		(pCodecResult->e_RGCH_2_IndexStepThreshold != pExpectedResult->e_RGCH_2_IndexStepThreshold))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_Rgch3Threshold_present) &&
		(pCodecResult->e_RGCH_3_IndexStepThreshold != pExpectedResult->e_RGCH_3_IndexStepThreshold))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_HarqInfo_present) &&
		(pCodecResult->hARQ_Info_for_E_DCH != pExpectedResult->hARQ_Info_for_E_DCH))
		return 0;
	if((pCodecResult->bit_mask & Edpch_Reconfig_HsdschConfigInd_present) &&
		(pCodecResult->hSDSCH_Configured_Indicator != pExpectedResult->hSDSCH_Configured_Indicator))
		return 0;
	if(pCodecResult->bit_mask & Edpch_Reconfig_ETfcsInfo_present){
		if(!validateETFCSInfo(pCodecResult->ptr_ETFCS_Information,pExpectedResult->ptr_ETFCS_Information))
			return 0;
	}
	return 1;
}

static uint8_t validateEdchLogicCh(L1CAPI_E_DCH_LogicalChannelInfo *pCodecResult, L1CAPI_E_DCH_LogicalChannelInfo *pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->logicalChannelId != pExpectedResult->logicalChannelId)
		return 0;
	if((pCodecResult->bit_mask & schedulingPriorityIndicator_present) &&
		(pCodecResult->schedulingPriorityIndicator != pExpectedResult->schedulingPriorityIndicator))
		return 0;
	if((pCodecResult->bit_mask & schedulingInformation_present) &&
		(pCodecResult->schedulingInformation != pExpectedResult->schedulingInformation))
		return 0;
	if((pCodecResult->bit_mask & mACesGuaranteedBitRate_present) &&
		(pCodecResult->mACesGuaranteedBitRate != pExpectedResult->mACesGuaranteedBitRate))
		return 0;
	if((pCodecResult->bit_mask & eDCH_DDI_Value_present) &&
		(pCodecResult->e_DCH_DDI_Value != pExpectedResult->e_DCH_DDI_Value))
		return 0;
	if(pCodecResult->macD_PDU_Size_Count != pExpectedResult->macD_PDU_Size_Count)
		return 0;
	if(memcmp(pCodecResult->ptrMacDPduSize,pExpectedResult->ptrMacDPduSize,sizeof(L1CAPI_MACdPDU_Size) * pExpectedResult->macD_PDU_Size_Count))
		return 0;
	return 1;
}

static uint8_t validateEdchMacDFlowInfo(L1CAPI_E_DCH_MACDFlow_Info *pCodecResult, L1CAPI_E_DCH_MACDFlow_Info *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if((pCodecResult->e_DCH_MACdFlow_ID != pExpectedResult->e_DCH_MACdFlow_ID) ||
		(pCodecResult->payloadCRC_PresenceIndicator != pExpectedResult->payloadCRC_PresenceIndicator) ||
		(pCodecResult->maxNrOfRetransmission_E_DCH != pExpectedResult->maxNrOfRetransmission_E_DCH) ||
		(pCodecResult->eDCH_HarqPowerOffset != pExpectedResult->eDCH_HarqPowerOffset) ||
		(pCodecResult->eDCH_Grant_Type != pExpectedResult->eDCH_Grant_Type)
		)
		return 0;
	if((pCodecResult->bit_mask & eDCH_MACdFlow_Multiplexing_present) &&
		(pCodecResult->eDCH_MACdFlow_Multiplexing_List != pExpectedResult->eDCH_MACdFlow_Multiplexing_List))
		return 0;
	if((pCodecResult->bit_mask & eDCH_MACdFlow_bundlingModeIndicator_present) &&
		(pCodecResult->bundlingModeIndicator != pExpectedResult->bundlingModeIndicator))
		return 0;
	if(pCodecResult->bit_mask & eDCH_MACdFlow_eDchNonSchedGrantInfo_present)
	{
		if(memcmp(pCodecResult->ptrEDchNonSchedGrantInfo,pExpectedResult->ptrEDchNonSchedGrantInfo,sizeof(L1CAPI_E_DCH_NonScheduled_TxGrantItems)))
			return 0;
	}
	if(pCodecResult->eDchNrOfLogicalChannels != pExpectedResult->eDchNrOfLogicalChannels)
		return 0;
	for(i=0;i<pCodecResult->eDchNrOfLogicalChannels;i++)
	{
		if(!validateEdchLogicCh(&pCodecResult->ptrEDCHLogicalChannelInformation[i],&pExpectedResult->ptrEDCHLogicalChannelInformation[i]))
			return 0;
	}
	return 1;
}

static uint8_t validateEdchMacDFlowReconfigInfo(L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pCodecResult, L1CAPI_E_DCH_MACDFlow_Reconfig_Info *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->e_DCH_MACdFlow_ID != pExpectedResult->e_DCH_MACdFlow_ID)
		return 0;
	if((pCodecResult->bit_mask & maxNrOfRetransmission_E_DCH_present) &&
		(pCodecResult->maxNrOfRetransmission_E_DCH != pExpectedResult->maxNrOfRetransmission_E_DCH))
		return 0;
	if((pCodecResult->bit_mask & eDCH_HarqPowerOffset_present) &&
		(pCodecResult->eDCH_HarqPowerOffset != pExpectedResult->eDCH_HarqPowerOffset))
		return 0;
	if((pCodecResult->bit_mask & eDCH_MACdFlow_Reconfig_Multiplexing_present) &&
		(pCodecResult->eDCH_MACdFlow_Multiplexing_List != pExpectedResult->eDCH_MACdFlow_Multiplexing_List))
		return 0;
	if((pCodecResult->bit_mask & eDCH_GrantType_present) &&
		(pCodecResult->eDCH_Grant_Type != pExpectedResult->eDCH_Grant_Type))
		return 0;
	if((pCodecResult->bit_mask & eDCH_MACdFlow_Reconfig_bundlingModeIndicator_present) &&
		(pCodecResult->bundlingModeIndicator != pExpectedResult->bundlingModeIndicator))
		return 0;
	if(pCodecResult->bit_mask & eDCH_MACdFlow_Reconfig_eDchNonSchedGrantInfo_present)
	{
		if(memcmp(pCodecResult->ptrEDchNonSchedGrantInfo,pExpectedResult->ptrEDchNonSchedGrantInfo,sizeof(L1CAPI_E_DCH_NonScheduled_TxGrantItems)))
			return 0;
	}
	if(pCodecResult->eDchNrOfLogicalChannelsAdd != pExpectedResult->eDchNrOfLogicalChannelsAdd)
		return 0;
	if(pCodecResult->eDchNrOfLogicalChannelsMod != pExpectedResult->eDchNrOfLogicalChannelsMod)
		return 0;
	if(pCodecResult->eDchNrOfLogicalChannelsDel != pExpectedResult->eDchNrOfLogicalChannelsDel)
		return 0;
	for(i=0;i<pCodecResult->eDchNrOfLogicalChannelsAdd;i++)
	{
		if(!validateEdchLogicCh(&pCodecResult->ptrEDCHLogicalChannelAdd[i],&pExpectedResult->ptrEDCHLogicalChannelAdd[i]))
			return 0;
	}
	for(i=0;i<pCodecResult->eDchNrOfLogicalChannelsMod;i++)
	{
		if(!validateEdchLogicCh(&pCodecResult->ptrEDCHLogicalChannelMod[i],&pExpectedResult->ptrEDCHLogicalChannelMod[i]))
			return 0;
	}
	if(memcmp(pCodecResult->ptrEDCHLogicalChannelDel,pExpectedResult->ptrEDCHLogicalChannelDel,sizeof(L1CAPI_LogicalChannelID)*pCodecResult->eDchNrOfLogicalChannelsDel ))
		return 0;
	return 1;
}

static uint8_t validateEDchFddInfo(L1CAPI_E_DCH_FDD_Info * pCodecResult, L1CAPI_E_DCH_FDD_Info * pExpectedResult)
{
	uint8_t i;
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if((pCodecResult->bit_mask & hARQ_Pc_Ac_Sd_2ms_EDCH_present) &&
		(pCodecResult->hARQ_Proc_Alloc_Sched_2ms_EDCH != pExpectedResult->hARQ_Proc_Alloc_Sched_2ms_EDCH))
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Maximum_Bitrate_present) &&
		(pCodecResult->e_DCH_Maximum_Bitrate != pExpectedResult->e_DCH_Maximum_Bitrate))
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Processing_Overload_Level_present) &&
		(pCodecResult->e_DCH_Processing_Overload_Level != pExpectedResult->e_DCH_Processing_Overload_Level))
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Reference_Pwr_Offset_present) &&
		(pCodecResult->e_DCH_Reference_Power_Offset != pExpectedResult->e_DCH_Reference_Power_Offset))
		return 0;
	if(pCodecResult->e_DCH_MacDFlow_Count != pExpectedResult->e_DCH_MacDFlow_Count)
		return 0;
	for(i=0;i<pCodecResult->e_DCH_MacDFlow_Count;i++){
		if(!validateEdchMacDFlowInfo(&pCodecResult->ptrE_DCH_MACdFlows_Information[i],&pExpectedResult->ptrE_DCH_MACdFlows_Information[i]))
			return 0;
	}
	return 1;
}

static uint8_t validateEDchFddReconfigInfo(L1CAPI_E_DCH_FDD_Reconfig_Info * pCodecResult, L1CAPI_E_DCH_FDD_Reconfig_Info * pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Reconfig_hARQ_Pc_Ac_Sd_2ms_EDCH_present) &&
		(pCodecResult->hARQ_Proc_Alloc_Sched_2ms_EDCH != pExpectedResult->hARQ_Proc_Alloc_Sched_2ms_EDCH))
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Reconfig_Maximum_Bitrate_present) &&
		(pCodecResult->e_DCH_Maximum_Bitrate != pExpectedResult->e_DCH_Maximum_Bitrate))
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Reconfig_Processing_Overload_Level_present) &&
		(pCodecResult->e_DCH_Processing_Overload_Level != pExpectedResult->e_DCH_Processing_Overload_Level))
		return 0;
	if((pCodecResult->bit_mask & e_DCH_Reconfig_Reference_Pwr_Offset_present) &&
		(pCodecResult->e_DCH_Reference_Power_Offset != pExpectedResult->e_DCH_Reference_Power_Offset))
		return 0;
	if((pCodecResult->bit_mask & macERestIndication_present) &&
		(pCodecResult->macERestIndication != pExpectedResult->macERestIndication))
		return 0;
	if(pCodecResult->e_DCH_MacDFlow_Count != pExpectedResult->e_DCH_MacDFlow_Count)
		return 0;
	for(i=0;i<pCodecResult->e_DCH_MacDFlow_Count;i++){
		if(!validateEdchMacDFlowReconfigInfo(&pCodecResult->ptrE_DCH_MACdFlows_Reconfig_Information[i],&pExpectedResult->ptrE_DCH_MACdFlows_Reconfig_Information[i]))
			return 0;
	}

	return 1;
}

uint8_t validateRadiolinkSetupReqCodecOutput(L1CAPI_Radiolink_Setup_Request * pCodecResult,L1CAPI_Radiolink_Setup_Request *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(memcmp(&pCodecResult->comContextInfo,&pExpectedResult->comContextInfo,sizeof(L1CAPI_RadioLink_CmnContextInfo)))
		return 0;
	for(i=0;i<pCodecResult->comContextInfo.rlCount;i++){
		if(!validateRlInfo(&pCodecResult->pRlInfo[i],&pExpectedResult->pRlInfo[i]) )
			return 0;
	}
	for(i=0;i<pCodecResult->comContextInfo.coordTrchCount;i++){
		if(!validateCordTrchInfo(&pCodecResult->ptrCoordTrchDchInfo[i],&pExpectedResult->ptrCoordTrchDchInfo[i]) )
			return 0;
	}
	if(memcmp(&pCodecResult->physDlDpch,&pExpectedResult->physDlDpch,sizeof(L1CAPI_DL_DPCH_PhyInfo)))
		return 0;
	if(memcmp(&pCodecResult->physUlDpch,&pExpectedResult->physUlDpch,sizeof(L1CAPI_UL_DPCH_PhyInfo)))
		return 0;
	if(!validateCTFCCodecOutput(&pCodecResult->cctrchDlTfc,&pExpectedResult->cctrchDlTfc))
		return 0;
	if(!validateCTFCCodecOutput(&pCodecResult->cctrchUlTfc,&pExpectedResult->cctrchUlTfc))
		return 0;
	for(i=0;i<pCodecResult->comContextInfo.tgpsCount;i++)
	{
		if(memcmp(&pCodecResult->ptrTransGapPattSeqInfo[i],&pExpectedResult->ptrTransGapPattSeqInfo[i],sizeof(L1CAPI_TxGap_SeqInfo)))
			return 0;
	}
	if(pCodecResult->bit_mask & rl_Setup_activePatternSeqInfo_present)
	{
		if(!validateActvPattern(pCodecResult->ptrActivePatternSeqInfo,pExpectedResult->ptrActivePatternSeqInfo))
			return 0;
	}
	if(pCodecResult->bit_mask & rl_Setup_dlPowerBalancingInfo_present)
	{
		printf("Power Balancing info not implemented!\n");
	}
	if(pCodecResult->bit_mask & rl_Setup_hsdsch_present)
	{
		if((pCodecResult->ptrHsdsch->bit_mask != pExpectedResult->ptrHsdsch->bit_mask) ||
			(pCodecResult->ptrHsdsch->hsDschRnti != pExpectedResult->ptrHsdsch->hsDschRnti) ||
			(pCodecResult->ptrHsdsch->hsPschRlId != pExpectedResult->ptrHsdsch->hsPschRlId))
			return 0;
		if(!validateHsdschInfo(pCodecResult->ptrHsdsch->ptrHdschInfo,pExpectedResult->ptrHsdsch->ptrHdschInfo))
			return 0;

	}
	if(pCodecResult->bit_mask & rl_Setup_eDchRlSetupExtension_present)
	{
		if(pCodecResult->ptrEDchRlSetupExtension->bit_mask != pExpectedResult->ptrEDchRlSetupExtension->bit_mask)
			return 0;
		if(!validateEDpchInfo(&pCodecResult->ptrEDchRlSetupExtension->eDpchInfo,&pExpectedResult->ptrEDchRlSetupExtension->eDpchInfo))
			return 0;
		if(!validateEDchFddInfo(&pCodecResult->ptrEDchRlSetupExtension->eDchFddInfo,&pExpectedResult->ptrEDchRlSetupExtension->eDchFddInfo))
			return 0;
		if(pCodecResult->ptrEDchRlSetupExtension->bit_mask & rl_Setup_servingEdchRlInfo_present)
		{
			if(memcmp(pCodecResult->ptrEDchRlSetupExtension->ptrServingEdchRlInfo,pExpectedResult->ptrEDchRlSetupExtension->ptrServingEdchRlInfo,sizeof(L1CAPI_ServingEdch_Radiolink_Info)))
				return 0;
		}
	}
	
	
	return 1;
}

uint8_t validateRadiolinkReconfigPrepareCodecOutput(L1CAPI_Radiolink_Reconfig_Prepare * pCodecResult,L1CAPI_Radiolink_Reconfig_Prepare *pExpectedResult)
{
	uint8_t i;

	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->NodeBComContext != pExpectedResult->NodeBComContext)
		return 0;
	if(memcmp(&pCodecResult->rl_reconfig_comContextInfo,&pExpectedResult->rl_reconfig_comContextInfo,sizeof(L1CAPI_Radiolink_Reconfig_CmnContextInfo)))
		return 0;
	for(i=0;i<pCodecResult->rl_reconfig_comContextInfo.rlCount;i++){
		if(!validateRlReconfigInfo(&pCodecResult->ptrRlInfo[i],&pExpectedResult->ptrRlInfo[i]) )
			return 0;
	}
	if(memcmp(pCodecResult->ptrTrchDchDelete,pExpectedResult->ptrTrchDchDelete,sizeof(L1CAPI_DCH_ID)*pCodecResult->rl_reconfig_comContextInfo.trchCountDelete))
		return 0;
	for(i=0;i<pCodecResult->rl_reconfig_comContextInfo.coorTrchCountAdd;i++)
	{
		if(!validateCordTrchInfo(&pCodecResult->ptrTrchDchAdd[i],&pExpectedResult->ptrTrchDchAdd[i]) )
			return 0;
	}
	for(i=0;i<pCodecResult->rl_reconfig_comContextInfo.coorTrchCountModify;i++)
	{
		if(!validateCordTrchInfo(&pCodecResult->PtrTrchDchModify[i],&pExpectedResult->PtrTrchDchModify[i]) )
			return 0;
	}
	if((pCodecResult->bit_mask & rl_Reconfig_physDlDpch_present) &&
		(memcmp(pCodecResult->ptrPhysDldpch,pExpectedResult->ptrPhysDldpch,sizeof(L1CAPI_DL_DPCH_PhyInfo_Reconfig))))
	{
		return 0;
	}
	if((pCodecResult->bit_mask & rl_Reconfig_physUlDpch_present) &&
		(memcmp(pCodecResult->ptrPhysUldpch,pExpectedResult->ptrPhysUldpch,sizeof(L1CAPI_UL_DPCH_PhyInfo_Reconfig))))
	{
		return 0;
	}
	if(!validateCTFCCodecOutput(&pCodecResult->cctrchDlTfc,&pExpectedResult->cctrchDlTfc))
		return 0;
	if(!validateCTFCCodecOutput(&pCodecResult->cctrchUlTfc,&pExpectedResult->cctrchUlTfc))
		return 0;
	for(i=0;i<pCodecResult->rl_reconfig_comContextInfo.tgpsCount;i++)
	{
		if(memcmp(&pCodecResult->ptrTransGapPattSeqInfo[i],&pExpectedResult->ptrTransGapPattSeqInfo[i],sizeof(L1CAPI_TxGap_SeqInfo)))
			return 0;
	}
	if(pCodecResult->bit_mask & rl_Reconfig_hsdsch_present)
	{
		if(pCodecResult->ptrHsdsch->bit_mask != pExpectedResult->ptrHsdsch->bit_mask)
			return 0;
		if((pCodecResult->ptrHsdsch->bit_mask & HSDSCH_RECONFIG_Rnti_present) &&
			(pCodecResult->ptrHsdsch->hsDschRnti != pExpectedResult->ptrHsdsch->hsDschRnti))
			return 0;
		if((pCodecResult->ptrHsdsch->bit_mask & HSDSCH_RECONFIG_Rlid_present) &&
			(pCodecResult->ptrHsdsch->hsPschRlId != pExpectedResult->ptrHsdsch->hsPschRlId))
			return 0;
		if(pCodecResult->ptrHsdsch->bit_mask & HSDSCH_RECONFIG_HsdschInfo_present){
			if(!validateHsdschInfo(pCodecResult->ptrHsdsch->ptrHdschInfo,pExpectedResult->ptrHsdsch->ptrHdschInfo))
				return 0;
		}
		if(pCodecResult->ptrHsdsch->bit_mask & HSDSCH_RECONFIG_HsdschModify_present){
			if(!validateHsdschReconfigInfo(pCodecResult->ptrHsdsch->ptrHsdschModify,pExpectedResult->ptrHsdsch->ptrHsdschModify))
				return 0;
		}
		if(pCodecResult->ptrHsdsch->bit_mask & HSDSCH_RECONFIG_HsdschMacDFlowAdd_present){
			if(!validateMacHsMacDFlowInfo(pCodecResult->ptrHsdsch->ptrHsdschMacDFlowAdd,pExpectedResult->ptrHsdsch->ptrHsdschMacDFlowAdd))
				return 0;
		}
		if(pCodecResult->ptrHsdsch->bit_mask & HSDSCH_RECONFIG_HsdschMacDFlowDel_present){
			if(!validateMacHsMacDFlowDelInfo(pCodecResult->ptrHsdsch->ptrHsdschMacDFlowDel,pExpectedResult->ptrHsdsch->ptrHsdschMacDFlowDel))
				return 0;
		}		
	}

	if(pCodecResult->bit_mask & rl_Reconfig_eDchRlSetupExtension_present)
	{
		if(pCodecResult->ptrEDchRlExtension->bit_mask != pExpectedResult->ptrEDchRlExtension->bit_mask)
			return 0;
		if(pCodecResult->ptrEDchRlExtension->bit_mask & rl_Reconfig_EdpchInfo_present){
			if(!validateEDpchReconfigInfo(pCodecResult->ptrEDchRlExtension->ptrEDpchInfo,pExpectedResult->ptrEDchRlExtension->ptrEDpchInfo))
				return 0;
		}
		if(pCodecResult->ptrEDchRlExtension->bit_mask & rl_Reconfig_EdchFddInfo_present){
			if(!validateEDchFddInfo(pCodecResult->ptrEDchRlExtension->ptrEDchFddInfo,pExpectedResult->ptrEDchRlExtension->ptrEDchFddInfo))
				return 0;
		}
		if(pCodecResult->ptrEDchRlExtension->bit_mask & rl_Reconfig_EdchFddModifyInfo_present)
		{
			if(!validateEDchFddReconfigInfo(pCodecResult->ptrEDchRlExtension->ptrEDchFddInfoModify,pExpectedResult->ptrEDchRlExtension->ptrEDchFddInfoModify))
				return 0;
		}
		if(pCodecResult->ptrEDchRlExtension->bit_mask & rl_Reconfig_EdchMacDFlowAdd_present)
		{
			if(pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsAdd->e_DCH_MacDFlow_Count != 
				pExpectedResult->ptrEDchRlExtension->ptrEdchMadDFlowsAdd->e_DCH_MacDFlow_Count)
				return 0;
			for(i=0;i<pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsAdd->e_DCH_MacDFlow_Count;i++)
			{
				if(!validateEdchMacDFlowInfo(&pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsAdd->ptrE_DCH_MACdFlows_Information[i],
					                         &pExpectedResult->ptrEDchRlExtension->ptrEdchMadDFlowsAdd->ptrE_DCH_MACdFlows_Information[i]))
					return 0;
			}
		}
		if(pCodecResult->ptrEDchRlExtension->bit_mask & rl_Reconfig_EdchMacDFlowDel_present)
		{
			if(pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsDel->e_DCH_MacDFlow_Count != 
				pExpectedResult->ptrEDchRlExtension->ptrEdchMadDFlowsDel->e_DCH_MacDFlow_Count)
				return 0;
			for(i=0;i<pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsDel->e_DCH_MacDFlow_Count;i++)
			{
				if(memcmp(pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsDel->ptrE_DCH_MACdFlow_ID,
					      pExpectedResult->ptrEDchRlExtension->ptrEdchMadDFlowsDel->ptrE_DCH_MACdFlow_ID,
						  sizeof(L1CAPI_E_DCH_MACdFlow_ID) * pCodecResult->ptrEDchRlExtension->ptrEdchMadDFlowsDel->e_DCH_MacDFlow_Count))
					return 0;
			}
		}
		if(pCodecResult->ptrEDchRlExtension->bit_mask & rl_Reconfig_servingEdchRlInfo_present)
		{
			if(memcmp(pCodecResult->ptrEDchRlExtension->ptrServingEdchRlInfo,
				      pExpectedResult->ptrEDchRlExtension->ptrServingEdchRlInfo,
					  sizeof(L1CAPI_ServingEdch_Radiolink_Info)))
				return 0;
		}

	}

	return 1;
}


uint8_t validateRadiolinkReconfigCommitCodecOutput(L1CAPI_Radiolink_ReconfigCommit * pCodecResult,L1CAPI_Radiolink_ReconfigCommit *pExpectedResult)
{
	if(pCodecResult->bit_mask != pExpectedResult->bit_mask)
		return 0;
	if(pCodecResult->NodeBComContext != pExpectedResult->NodeBComContext)
		return 0;
	if(pCodecResult->cfn != pExpectedResult->cfn)
		return 0;
	if(pCodecResult->bit_mask & activePattSeqInfo_present)
	{
		if(pCodecResult->ptrActivePattSeqInfo->cMConfigurationChangeCFN != 
			pExpectedResult->ptrActivePattSeqInfo->cMConfigurationChangeCFN)
			return 0;
		if(pCodecResult->ptrActivePattSeqInfo->tgpssCount != 
			pExpectedResult->ptrActivePattSeqInfo->tgpssCount)
			return 0;
		if(memcmp(pCodecResult->ptrActivePattSeqInfo->ptrTgpss,
			       pExpectedResult->ptrActivePattSeqInfo->ptrTgpss,
				   sizeof(L1CAPI_Active_Pattern_Seq4) * pCodecResult->ptrActivePattSeqInfo->tgpssCount))
			return 0;
	}
	return 1;
}

uint8_t validateRadiolinkDeletionCodecOutput(L1CAPI_Radiolink_DeletionRequest * pCodecResult,L1CAPI_Radiolink_DeletionRequest *pExpectedResult)
{
	if(pCodecResult->NodeBComContext != pExpectedResult->NodeBComContext)
		return 0;
	if(pCodecResult->rlCount != pExpectedResult->rlCount)
		return 0;
	if(memcmp(pCodecResult->pRl_ID,pExpectedResult->pRl_ID,sizeof(L1CAPI_Radiolink_ID) * pCodecResult->rlCount))
		return 0;
	return 1;

}
