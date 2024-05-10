/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_CellProcValidation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control: Cell Procedure Validation.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <memory.h>

#include "L1C_CellProcValidation.h"

/***********************
CCPU L1 API initial
************************/

/***********************
Octasic L1C API initial
************************/
static L1CAPI_Closedlooptimingadjustmentmode l1cCLAdjMode = L1CAPI_ADJ_1_SLOT;

static L1CAPI_Secondary_CPICH_Info l1cSCpichParams[2] = 
{
	{
		1,          /*commonPhysicalChannelID;*/
		(2-350),		/*cpich_Power;*/
		0,			/*tSTD_Indicator;*/
		111,		/*dL_ChannelisationCodeNumber;*/
		11			/*dl_ScramblingCode;*/
	},
	{
		2,         /*commonPhysicalChannelID;*/
		(3-350),	   /*cpich_Power;*/
		0,		   /*tSTD_Indicator;*/
		112,	   /*dL_ChannelisationCodeNumber;*/
		12		   /*dl_ScramblingCode;*/
	}
};

static L1CAPI_Cell_Setup_Request l1c_CellSetupReq = 
{
	{
		clLoopTimingAdjMode_present,                          
		0,                             /*cell id*/               
		1,							   /**/
		L1CAPI_T_CELL_V2,
		854,
		1073,
		7,
		10,
		{
			1,
			2,
			100
		},
		2,
		&l1cCLAdjMode,
		NULL,
		9,
		2
	},/*Cell Info*/
	{
		1,(0-350),0
	},/*P-SCH*/
	{
		1,(0-350),0
	},/*S-SCH*/
	{
		0,(1-100),0
	},/*P-CPICH*/
	2,
	l1cSCpichParams,
	{
		0,0
	},/*P-CCPCH*/
	{
		2,(3-350)
	}/*BCH*/
};


/***********************
Validation API
***********************/


L1CAPI_Cell_Setup_Request * getL1CCellSetupRequest()
{
	return &l1c_CellSetupReq;
}

static uint8_t validateCellInfoOutput(L1CAPI_CellInfo * pOutput,L1CAPI_CellInfo *pExpect)
{
	if(pOutput->bit_mask != pExpect->bit_mask)
		return 0;
	if(pOutput->localCellId != pExpect->localCellId)
		return 0;
	if(pOutput->tCell != pExpect->tCell)
		return 0;
	if(pOutput->uarfcnUl != pExpect->uarfcnUl)
		return 0;
	if(pOutput->uarfcnDl != pExpect->uarfcnDl)
		return 0;
	if(pOutput->maxTxPower != pExpect->maxTxPower)
		return 0;
	if(pOutput->priScramCode != pExpect->priScramCode)
		return 0;
	if(memcmp(&pOutput->syncConfig, &pExpect->syncConfig,sizeof(L1CAPI_Sync_Config)))
		return 0;
	if(pOutput->dlTpc01Count != pExpect->dlTpc01Count)
		return 0;
	if(clLoopTimingAdjMode_present & pOutput->bit_mask){
		if(*pOutput->ptrClLoopTimingAdjMode != *pExpect->ptrClLoopTimingAdjMode)
			return 0;
	}
	if(ipdlParams_present & pOutput->bit_mask){
		if(memcmp(&pOutput->ptrIpdlParams, &pExpect->ptrIpdlParams,sizeof(L1CAPI_IPDLParameter_Info)))
			return 0;
	}
	if(pOutput->pwrRaiseLimit != pExpect->pwrRaiseLimit)
		return 0;
	if(pOutput->dlPwrAvrgWinSize != pExpect->dlPwrAvrgWinSize)
		return 0;
	return 1;
}

uint8_t validateCellSetupReqCodecOutput(L1CAPI_Cell_Setup_Request * pCodecResult,L1CAPI_Cell_Setup_Request *pExpectedResult)
{
	uint8_t i;

	if(!validateCellInfoOutput(&pCodecResult->cellInfo,&pExpectedResult->cellInfo))
	{
		return 0;
	}
	if(memcmp(&pCodecResult->physDlPSch,&pExpectedResult->physDlPSch,sizeof(L1CAPI_SCH_Info)))
	{
		return 0;
	}
	if(memcmp(&pCodecResult->physDlSSch,&pExpectedResult->physDlSSch,sizeof(L1CAPI_SCH_Info)))
	{
		return 0;
	}
	if(memcmp(&pCodecResult->physDlPCpich,&pExpectedResult->physDlPCpich,sizeof(L1CAPI_Primary_CPICH_Info)))
	{
		return 0;
	}
	if(pCodecResult->nSCPich != pExpectedResult->nSCPich)
	{
		return 0;
	}
	for(i=0;i<pCodecResult->nSCPich;i++)
	{
		if(memcmp(&pCodecResult->ptrPhysDlSCpich[i],&pExpectedResult->ptrPhysDlSCpich[i],sizeof(L1CAPI_Secondary_CPICH_Info)))
		{
			return 0;
		}
	}
	if(memcmp(&pCodecResult->physDlPCcpch,&pExpectedResult->physDlPCcpch,sizeof(L1CAPI_PrimCCPCH_Info)))
	{
		return 0;
	}
	if(memcmp(&pCodecResult->trchCommonDlBch,&pExpectedResult->trchCommonDlBch,sizeof(L1CAPI_BCH_Info)))
	{
		return 0;
	}
	return 1;
}
