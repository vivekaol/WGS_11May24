/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cellProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Cell Procedure Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_cellProcedureEncHdlr.h"
#include "l1capi_datastruct.h"
#include "L1C_cellProcedureParamValidate.h"
#include "msgPutPrimitives.h"



static void cellInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                   void * pSrc)
{
    L1CAPI_CellInfo *pL1CCellInfo = (L1CAPI_CellInfo *)pSrc;
    L1CAPI_Closedlooptimingadjustmentmode clAdjMode;

    cellInfoProcParamValidate(msgStatus,pL1CCellInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CCellInfo->bit_mask);
    ADD_WORD_VAL(pL1CCellInfo->cId);
    ADD_BYTE_VAL(pL1CCellInfo->localCellId);
    ADD_BYTE_VAL(pL1CCellInfo->tCell);
    ADD_WORD_VAL(pL1CCellInfo->uarfcnUl);
    ADD_WORD_VAL(pL1CCellInfo->uarfcnDl);
    ADD_WORD_VAL(pL1CCellInfo->maxTxPower);    
    ADD_WORD_VAL(pL1CCellInfo->priScramCode);
    ADD_BYTE_VAL(pL1CCellInfo->syncConfig.nInSyncInd);
    ADD_BYTE_VAL(pL1CCellInfo->syncConfig.nOutSyncInd);
    ADD_BYTE_VAL(pL1CCellInfo->syncConfig.tRlFailure);
    ADD_BYTE_VAL(pL1CCellInfo->dlTpc01Count);
    if(pL1CCellInfo->bit_mask & clLoopTimingAdjMode_present){
      clAdjMode = *(pL1CCellInfo->ptrClLoopTimingAdjMode);
      ADD_BYTE_VAL(clAdjMode);
    }
    ADD_BYTE_VAL(pL1CCellInfo->pwrRaiseLimit);
    ADD_BYTE_VAL(pL1CCellInfo->dlPwrAvrgWinSize);
END_BLOCK_TRACE
    return;

}

static void schInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,                                   
                                   void * pSrc)
{
    L1CAPI_SCH_Info *pL1CSchInfo = (L1CAPI_SCH_Info * )pSrc;

    schInfoProcParamValidate(msgStatus,pL1CSchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CSchInfo->commonPhysicalChannelID);    
    ADD_WORD_VAL(pL1CSchInfo->sch_Power);
    ADD_BYTE_VAL(pL1CSchInfo->tSTD_Indicator);
END_BLOCK_TRACE
    return;
}

static void pCpichInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,                                       
                                       void * pSrc)
{
    L1CAPI_Primary_CPICH_Info *pL1CPCPichInfo = (L1CAPI_Primary_CPICH_Info *)pSrc;

    pCpichInfoProcParamValidate(msgStatus,pL1CPCPichInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPCPichInfo->commonPhysicalChannelID);
    ADD_WORD_VAL(pL1CPCPichInfo->cpich_Power);
    ADD_BYTE_VAL(pL1CPCPichInfo->tSTD_Indicator);
END_BLOCK_TRACE
    return;
}

static void sCpichInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                       void * pSrc)
{
    L1CAPI_Secondary_CPICH_Info *pL1CPCPichInfo = (L1CAPI_Secondary_CPICH_Info *)pSrc;

    sCpichInfoProcParamValidate(msgStatus,pL1CPCPichInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPCPichInfo->commonPhysicalChannelID);
    ADD_WORD_VAL(pL1CPCPichInfo->cpich_Power);
    ADD_BYTE_VAL(pL1CPCPichInfo->tSTD_Indicator);
    ADD_WORD_VAL(pL1CPCPichInfo->dL_ChannelisationCodeNumber);
    ADD_BYTE_VAL(pL1CPCPichInfo->dl_ScramblingCode);
END_BLOCK_TRACE
    return;
}

static void pCcpchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,                                       
                                       void * pSrc)
{
    L1CAPI_PrimCCPCH_Info *pL1CPccpchInfo = (L1CAPI_PrimCCPCH_Info *)pSrc;    

START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPccpchInfo->commonPhysicalChannelID);
    ADD_BYTE_VAL(pL1CPccpchInfo->sTTD_Indicator);
END_BLOCK_TRACE
}

static void bchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,                                   
                                   void * pSrc)
{
    L1CAPI_BCH_Info *pL1CBchInfo = (L1CAPI_BCH_Info *)pSrc;

    bchInfoProcParamValidate(msgStatus,pL1CBchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CBchInfo->commonTransportChannelID);
    ADD_WORD_VAL(pL1CBchInfo->bCH_Power);
END_BLOCK_TRACE
}

/****************************Main Interface to OP ***************/
void cellSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
    /*Add the procedure handler commit code here.*/
    if (procStatus == PROC_COMMIT)
    {
    }
    else
    {
    }

    return;

} // cellSetupRequestProcEncCommit()


void cellSetupRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t i,nrOfScpich;
    void * pCellInfo;
    void * pPschInfo;
    void * pSschInfo;
    void * pPcpich;
    void * pSCpich;
    void * pPccpch;
    void * pBch;
    L1CAPI_Cell_Setup_Request * pL1CCellSetupRequest = (L1CAPI_Cell_Setup_Request *)pHostDLMsg;
    nrOfScpich = (uint8_t)pL1CCellSetupRequest->nSCPich;
    pCellInfo = &(pL1CCellSetupRequest->cellInfo);
    pPschInfo = &(pL1CCellSetupRequest->physDlPSch);
    pSschInfo = &(pL1CCellSetupRequest->physDlSSch);
    pPcpich = &(pL1CCellSetupRequest->physDlPCpich);
    pPccpch = &(pL1CCellSetupRequest->physDlPCcpch);
    pBch = &(pL1CCellSetupRequest->trchCommonDlBch);
    PRINTF("L23--> Cell Setup Request \n");
START_BLOCK_TRACE
    if(nrOfScpich > L1CAPI_MAX_NR_OF_SCPICH){
        msgStatus->l1MsgResult = L1_EMSG_CELL_SETUP_REQUEST;
        msgStatus->additionalInfo0 = PARAM_5;
        msgStatus->additionalInfo1 = nrOfScpich;
        return;        
    }

    /*cell info*/
    cellInfoProcEncHdlr(msgStatus,pCellInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*P-SCH info*/
    schInfoProcEncHdlr(msgStatus,pPschInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*S-SCH info*/
    schInfoProcEncHdlr(msgStatus,pSschInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*P-CPICH*/
    pCpichInfoProcEncHdlr(msgStatus,pPcpich);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    
    ADD_BYTE_VAL(nrOfScpich);
    /*S-CPICH*/
    for(i=0;i<nrOfScpich;i++)
    {
      pSCpich = &(pL1CCellSetupRequest->ptrPhysDlSCpich[i]);
      sCpichInfoProcEncHdlr(msgStatus,pSCpich);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      {
        return;
      }
    }
    /*P-CCPCH*/
    pCcpchInfoProcEncHdlr(msgStatus,pPccpch);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    /*BCH*/
    bchInfoProcEncHdlr(msgStatus,pBch);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
       return;
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE    
    return;
} // cellSetupRequestProcEncHdlr()

static void cellChReconfInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus, void *pSrc)
{
    L1CAPI_CellChReconf_Info *pChInfo = (L1CAPI_CellChReconf_Info *)pSrc;    

START_BLOCK_TRACE
    ADD_BYTE_VAL(pChInfo->commonPhysicalChannelID);
    ADD_WORD_VAL(pChInfo->channel_Power);
END_BLOCK_TRACE

    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}

void cellReconfigRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Cell_Reconfig_Request * pL1CCellReconfigRequest;
    uint8_t i,nrOfScpich;
    void * pPschInfo;
    void * pSschInfo;
    void * pPcpich;
    void * pSCpich;
    void * pBch;

    pL1CCellReconfigRequest = (L1CAPI_Cell_Reconfig_Request *)pHostDLMsg;

    PRINTF("L23--> Cell Reconfiguration Request \n");
START_BLOCK_TRACE
    
    if (pL1CCellReconfigRequest->bit_mask & cellreconf_cellPhyCh_present)
    {
		nrOfScpich = (uint8_t)pL1CCellReconfigRequest->ptrCellChReconfig->nSCPich;
		if(nrOfScpich > L1CAPI_MAX_NR_OF_SCPICH)
		{
			msgStatus->l1MsgResult = L1_EMSG_CELL_SETUP_REQUEST;
			msgStatus->additionalInfo0 = PARAM_5;
			msgStatus->additionalInfo1 = nrOfScpich;
			return;        
		}
	}

    ADD_BYTE_VAL(pL1CCellReconfigRequest->bit_mask);
    ADD_WORD_VAL(pL1CCellReconfigRequest->cId);
    
    if (pL1CCellReconfigRequest->bit_mask & cellreconf_maxTxPower_present)
    {
        ADD_WORD_VAL(pL1CCellReconfigRequest->maxTxPower);    
    }
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_syncConfig_present)
    {
        ADD_BYTE_VAL(pL1CCellReconfigRequest->syncConfig.nInSyncInd);
        ADD_BYTE_VAL(pL1CCellReconfigRequest->syncConfig.nOutSyncInd);
        ADD_BYTE_VAL(pL1CCellReconfigRequest->syncConfig.tRlFailure);
    }
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_cellPhyCh_present)
	{
		ADD_BYTE_VAL(pL1CCellReconfigRequest->ptrCellChReconfig->bit_mask);
		if (pL1CCellReconfigRequest->ptrCellChReconfig->bit_mask & cellreconf_physDlPSch_present)
		{
			/*P-SCH info*/
			pPschInfo  = &(pL1CCellReconfigRequest->ptrCellChReconfig->physDlPSch);
			cellChReconfInfoProcEncHdlr(msgStatus,pPschInfo);
			if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
			{
			   return;
			}
		}

		if (pL1CCellReconfigRequest->ptrCellChReconfig->bit_mask & cellreconf_physDlSSch_present)
		{
			/*S-SCH info*/
			pSschInfo  = &(pL1CCellReconfigRequest->ptrCellChReconfig->physDlSSch);
			cellChReconfInfoProcEncHdlr(msgStatus,pSschInfo);
			if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
			{
			   return;
			}
		}
	    
		if (pL1CCellReconfigRequest->ptrCellChReconfig->bit_mask & cellreconf_physDlPCpich_present)
		{    
			/*P-CPICH*/
			pPcpich    = &(pL1CCellReconfigRequest->ptrCellChReconfig->physDlPCpich);
			cellChReconfInfoProcEncHdlr(msgStatus,pPcpich);
			if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
			{
			   return;
			}
		}

		ADD_BYTE_VAL(nrOfScpich);
		/*S-CPICH*/
		for(i=0;i<nrOfScpich;i++)
		{
			pSCpich = &(pL1CCellReconfigRequest->ptrCellChReconfig->ptrPhysDlSCpich[i]);
			cellChReconfInfoProcEncHdlr(msgStatus,pSCpich);
			if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
			{
				return;
			}
		}
	}
    if (pL1CCellReconfigRequest->bit_mask & cellreconf_trchCommonDlBch_present)
    {
        /*BCH*/
        pBch = &(pL1CCellReconfigRequest->trchCommonDlBch);
        bchInfoProcEncHdlr(msgStatus,pBch);
        if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        {
           return;
        }
    }
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_txattn_present)
    {
		ADD_BYTE_VAL(pL1CCellReconfigRequest->txAttn);    
    }
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_activationCfn_present)
    {
		ADD_BYTE_VAL(pL1CCellReconfigRequest->cfn);    
    }
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_psc_present)
    {
		ADD_WORD_VAL(pL1CCellReconfigRequest->priScramCode);    
    }
	if (pL1CCellReconfigRequest->bit_mask & cellreconf_newCellId_present)
    {
		ADD_WORD_VAL(pL1CCellReconfigRequest->newCellId);    
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE    
    return;

} // cellSetupRequestProcEncHdlr()

void cellDeleteRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Cell_ID cellId;

    L1CAPI_Cell_Delete_Request * pL1CCellDelRequest = (L1CAPI_Cell_Delete_Request *)pHostDLMsg;
    cellId = pL1CCellDelRequest->cId;
PRINTF("L23--> Cell Deletion Request \n");
START_BLOCK_TRACE
    ADD_WORD_VAL(cellId);
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
  return;
} 

void cellDeleteRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

}

void physicalChannelReconfigRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
	L1CAPI_PhysicalChannel_Reconfig_Request *pL1PhyChReconfigRequest = (L1CAPI_PhysicalChannel_Reconfig_Request *)pHostDLMsg;
	
	ADD_BYTE_VAL(pL1PhyChReconfigRequest->bit_mask);
	ADD_WORD_VAL(pL1PhyChReconfigRequest->cId);
	ADD_BYTE_VAL(pL1PhyChReconfigRequest->cfn);
	
	if(pL1PhyChReconfigRequest->bit_mask&uarfcnInfo_present)
	{
		ADD_WORD_VAL(pL1PhyChReconfigRequest->uarfcnUl);
		ADD_WORD_VAL(pL1PhyChReconfigRequest->uarfcnDl);
	}						   
	
	msgStatus->l1MsgResult = L1_MSG_SUCCESS;
}
