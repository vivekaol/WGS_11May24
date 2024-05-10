/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cellProcedureDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Type definition for various data types

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1C_cellProcedureDecHdlr.h"
#include "l1capi_datastruct.h"
#include "msgGetPrimitives.h"

static void cellInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_CellInfo *pL1CCellInfo)
{	
    pL1CCellInfo->bit_mask = subByteVal();
    pL1CCellInfo->cId = subWordVal();
    pL1CCellInfo->localCellId = subByteVal();
    pL1CCellInfo->tCell = subByteVal();
	pL1CCellInfo->uarfcnUl = subWordVal();
	pL1CCellInfo->uarfcnDl = subWordVal();
	pL1CCellInfo->maxTxPower = subWordVal();	
	pL1CCellInfo->priScramCode = subWordVal();
    pL1CCellInfo->syncConfig.nInSyncInd = subByteVal();
    pL1CCellInfo->syncConfig.nOutSyncInd = subByteVal();
    pL1CCellInfo->syncConfig.tRlFailure = subByteVal();
    pL1CCellInfo->dlTpc01Count = subByteVal();
    if(pL1CCellInfo->bit_mask & clLoopTimingAdjMode_present){
      pL1CCellInfo->ptrClLoopTimingAdjMode = 
        (L1CAPI_Closedlooptimingadjustmentmode *)allocMem(sizeof(L1CAPI_Closedlooptimingadjustmentmode),0);
	  *(pL1CCellInfo->ptrClLoopTimingAdjMode) = subByteVal();
    }
    pL1CCellInfo->pwrRaiseLimit = subByteVal();
    pL1CCellInfo->dlPwrAvrgWinSize = subByteVal();
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;

}

static void schInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,                                   
                                   L1CAPI_SCH_Info *pL1CSchInfo)
{
    pL1CSchInfo->commonPhysicalChannelID = subByteVal();	
    pL1CSchInfo->sch_Power = subWordVal();
	pL1CSchInfo->tSTD_Indicator = subByteVal();
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void pCpichInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,                                       
                                       L1CAPI_Primary_CPICH_Info *pL1CPCPichInfo)
{
    pL1CPCPichInfo->commonPhysicalChannelID = subByteVal();
    pL1CPCPichInfo->cpich_Power = subWordVal();
    pL1CPCPichInfo->tSTD_Indicator = subByteVal();
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void sCpichInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_Secondary_CPICH_Info *pL1CPCPichInfo)
{
    pL1CPCPichInfo->commonPhysicalChannelID = subByteVal();
    pL1CPCPichInfo->cpich_Power = subWordVal();
    pL1CPCPichInfo->tSTD_Indicator = subByteVal();
    pL1CPCPichInfo->dL_ChannelisationCodeNumber = subWordVal();
    pL1CPCPichInfo->dl_ScramblingCode = subByteVal();
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void pCcpchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,                                       
                                       L1CAPI_PrimCCPCH_Info *pL1CPccpchInfo)
{
    pL1CPccpchInfo->commonPhysicalChannelID = subByteVal();
	pL1CPccpchInfo->sTTD_Indicator = subByteVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

static void bchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                   L1CAPI_BCH_Info *pL1CBchInfo)
{
	pL1CBchInfo->commonTransportChannelID = subByteVal();
	pL1CBchInfo->bCH_Power = subWordVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

/****************************Main Interface to OP ***************/

void cellSetupRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t i;
	L1CAPI_Cell_Setup_Request *pL1CCellSetupRequest = 
      (L1CAPI_Cell_Setup_Request *)allocMem(sizeof(L1CAPI_Cell_Setup_Request),0);
	
	/*cell info*/
	cellInfoProcDecHdlr(msgStatus,&pL1CCellSetupRequest->cellInfo);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*P-SCH info*/
	schInfoProcDecHdlr(msgStatus,&pL1CCellSetupRequest->physDlPSch);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*S-SCH info*/
	schInfoProcDecHdlr(msgStatus,&pL1CCellSetupRequest->physDlSSch);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*P-CPICH*/
	pCpichInfoProcDecHdlr(msgStatus,&pL1CCellSetupRequest->physDlPCpich);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
	
	pL1CCellSetupRequest->nSCPich = subByteVal();
	pL1CCellSetupRequest->ptrPhysDlSCpich = 
	  (L1CAPI_Secondary_CPICH_Info *)allocMem(sizeof(L1CAPI_Secondary_CPICH_Info) * pL1CCellSetupRequest->nSCPich,0);
    /*S-CPICH*/
	for(i=0;i<pL1CCellSetupRequest->nSCPich;i++)
    {
      sCpichInfoProcDecHdlr(msgStatus,&(pL1CCellSetupRequest->ptrPhysDlSCpich[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      {
        return;
      }
    }
    /*P-CCPCH*/
    pCcpchInfoProcDecHdlr(msgStatus,&pL1CCellSetupRequest->physDlPCcpch);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*BCH*/
    bchInfoProcDecHdlr(msgStatus,&pL1CCellSetupRequest->trchCommonDlBch);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
	
    return;
}

static void cellChReconfInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
									    L1CAPI_CellChReconf_Info *pL1CChInfo)
{
	pL1CChInfo->commonPhysicalChannelID = subByteVal();
	pL1CChInfo->channel_Power = subWordVal();
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}
static void cellChannelsReconfigProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
											L1CAPI_CellChannelsReconf *  pL1CellChReconf)
{
	uint8_t i;
	pL1CellChReconf->bit_mask = subByteVal();
	if (pL1CellChReconf->bit_mask & cellreconf_physDlPSch_present)
	{
		/*P-SCH info*/
		cellChReconfInfoProcDecHdlr(msgStatus,&pL1CellChReconf->physDlPSch);
		if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		{
		   return;
		}
	}
	
	if (pL1CellChReconf->bit_mask & cellreconf_physDlSSch_present)
	{
		/*S-SCH info*/
		cellChReconfInfoProcDecHdlr(msgStatus,&pL1CellChReconf->physDlSSch);
		if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		{
		   return;
		}
	}

	if (pL1CellChReconf->bit_mask & cellreconf_physDlPCpich_present)
	{
		/*P-CPICH*/
		cellChReconfInfoProcDecHdlr(msgStatus,&pL1CellChReconf->physDlPCpich);
		if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		{
		   return;
		}
	}

	pL1CellChReconf->nSCPich = subByteVal();
	if (pL1CellChReconf->nSCPich!=0)
	{
		pL1CellChReconf->ptrPhysDlSCpich = 
		  (L1CAPI_CellChReconf_Info *)allocMem(sizeof(L1CAPI_CellChReconf_Info) * pL1CellChReconf->nSCPich,0);
		/*S-CPICH*/
		for(i=0;i<pL1CellChReconf->nSCPich;i++)
		{
		  cellChReconfInfoProcDecHdlr(msgStatus,&(pL1CellChReconf->ptrPhysDlSCpich[i]));
		  if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		  {
			return;
		  }
		}
	}
}
void cellReconfigRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
   L1CAPI_Cell_Reconfig_Request *pL1CCellReconfigRequest = 
      (L1CAPI_Cell_Reconfig_Request *)allocMem(sizeof(L1CAPI_Cell_Reconfig_Request),0);
	
    pL1CCellReconfigRequest->bit_mask = subByteVal();
    pL1CCellReconfigRequest->cId = subWordVal();
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_maxTxPower_present)
	{
		pL1CCellReconfigRequest->maxTxPower = subWordVal();	
	}
	
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_syncConfig_present)
	{
		pL1CCellReconfigRequest->syncConfig.nInSyncInd = subByteVal();
		pL1CCellReconfigRequest->syncConfig.nOutSyncInd = subByteVal();
		pL1CCellReconfigRequest->syncConfig.tRlFailure = subByteVal();
	}
	 /*Cell Physical Channels infos*/
    if(pL1CCellReconfigRequest->bit_mask & cellreconf_cellPhyCh_present)
    {
      pL1CCellReconfigRequest->ptrCellChReconfig = 
        (L1CAPI_CellChannelsReconf * )allocMem(sizeof(L1CAPI_CellChannelsReconf),0);
      cellChannelsReconfigProcDecHdlr(msgStatus,pL1CCellReconfigRequest->ptrCellChReconfig);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;    
    }
		
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_trchCommonDlBch_present)
	{	
		/*BCH*/
		bchInfoProcDecHdlr(msgStatus,&pL1CCellReconfigRequest->trchCommonDlBch);
		if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
		{
		   return;
		}
	}
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_txattn_present)
	{
		pL1CCellReconfigRequest->txAttn = subByteVal();	
	}
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_activationCfn_present)
	{
		pL1CCellReconfigRequest->cfn = subByteVal();	
	}
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_psc_present)
	{
		pL1CCellReconfigRequest->priScramCode = subWordVal();	
	}
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_newCellId_present)
	{
		pL1CCellReconfigRequest->newCellId = subWordVal();	
	}
    return;
	
}

void cellDeleteRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Cell_Delete_Request *pL1CCellDeleteRequest = 
      (L1CAPI_Cell_Delete_Request *)allocMem(sizeof(L1CAPI_Cell_Delete_Request),0);
	pL1CCellDeleteRequest->cId = subWordVal();	
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

void physicalChannelReconfigRequestProcDecHdlr(L1CAPI_Msg_Status *msgStatus)
{	
	L1CAPI_PhysicalChannel_Reconfig_Request *pL1PhyChReconfigRequest = 
      (L1CAPI_PhysicalChannel_Reconfig_Request *)allocMem(sizeof(L1CAPI_PhysicalChannel_Reconfig_Request),0);
	
	pL1PhyChReconfigRequest->bit_mask = subByteVal();
	pL1PhyChReconfigRequest->cId = subWordVal();
	pL1PhyChReconfigRequest->cfn = subByteVal();
	if(pL1PhyChReconfigRequest->bit_mask&uarfcnInfo_present)
	{
		pL1PhyChReconfigRequest->uarfcnUl = subWordVal();
		pL1PhyChReconfigRequest->uarfcnDl = subWordVal();
	}						   
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}


