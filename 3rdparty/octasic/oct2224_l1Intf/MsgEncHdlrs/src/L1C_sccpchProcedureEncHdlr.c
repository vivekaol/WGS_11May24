/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sccpchProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel Procedure Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_sccpchProcedureEncHdlr.h"
#include "L1C_sccpchProcedureParamValidate.h"
#include "L1C_cctrchEncHdlr.h"
#include "L1C_tfsEncHdlr.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"


static void sccpchTrchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                            void * pSrc)
{
    L1CAPI_SCCPCH_Trch_Info   *pL1CTrchDl = (L1CAPI_SCCPCH_Trch_Info*)pSrc;
    void * pTrchTf;
	pTrchTf = &(pL1CTrchDl->tfsDL);
    sccpchTrchInfoProcParamValidate(msgStatus,pL1CTrchDl);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;

START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CTrchDl->commonTransportChannelID);
    ADD_WORD_VAL(pL1CTrchDl->maxFACH_PCH_Power);
    ADD_WORD_VAL(pL1CTrchDl->toAWS);
    ADD_WORD_VAL(pL1CTrchDl->toAWE);
    tfsEncHdlr(msgStatus,pTrchTf);    
END_BLOCK_TRACE
}

static void pichInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                    void * pSrc)
{
    L1CAPI_PICH_Params   *pL1CPichInfo = (L1CAPI_PICH_Params *)pSrc;

    pichInfoProcParamValidate(msgStatus,pL1CPichInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPichInfo->commonPhysicalChannelID);
    ADD_WORD_VAL(pL1CPichInfo->dl_ChannelisationCodeNumber);
    ADD_BYTE_VAL(pL1CPichInfo->pICH_Power);
    ADD_BYTE_VAL(pL1CPichInfo->pICH_Mode);
    ADD_BYTE_VAL(pL1CPichInfo->sTTD_Indicator);
END_BLOCK_TRACE    
}

static void pchTrchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                        void * pOpTrchInfo,
                                        void * pOpPichInfo)
{
START_BLOCK_TRACE
    sccpchTrchInfoProcEncHdlr(msgStatus,pOpTrchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    pichInfoProcEncHdlr(msgStatus,pOpPichInfo);
END_BLOCK_TRACE
}

static void sccpchPhyInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                           void * pSrc)
{
    L1CAPI_SCCPCH_Phy_Info *pL1CSccpchPhyInfo = (L1CAPI_SCCPCH_Phy_Info *)pSrc;


    sccpchPhyInfoProcParamValidate(msgStatus,pL1CSccpchPhyInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;    
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->bit_mask);
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->commonPhysicalChannelID);
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->sCCPCH_Chip_Offset);
    if(pL1CSccpchPhyInfo->bit_mask & dl_ScramblingCode_present){
      ADD_BYTE_VAL(pL1CSccpchPhyInfo->dl_ScramblingCode);
    }
    ADD_WORD_VAL(pL1CSccpchPhyInfo->dL_ChannelisationCodeNumber);
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->sCCPCH_SlotFormat);
    if(pL1CSccpchPhyInfo->bit_mask & sccpch_tFCI_present){
      ADD_BYTE_VAL(pL1CSccpchPhyInfo->tFCI_Presence);
    }
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->multiplexingPosition);    
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->pO1_ForTFCI_Bits);
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->pO3_ForPilotBits);    
    ADD_BYTE_VAL(pL1CSccpchPhyInfo->sTTD_Indicator);    
END_BLOCK_TRACE
}

void cmnTrchSccpchSetupRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t bit_mask;
    uint8_t i,nFach;
    L1CAPI_Cell_ID L1CCellId;
    void * pSccpchInfo;
    void * pCctrch;
    void * pFachInfo;
    void * pPchInfo;
    void * pPichInfo;

    L1CAPI_Sccpch_Setup_Request *pL1CSccpchSetupReq = (L1CAPI_Sccpch_Setup_Request *) pHostDLMsg;  
    nFach = pL1CSccpchSetupReq->nFach;
	L1CCellId = pL1CSccpchSetupReq->cmnInfo.cId;
    pSccpchInfo = &(pL1CSccpchSetupReq->physDlSCcpch);
    pCctrch = &(pL1CSccpchSetupReq->cctrchDlTfc);
    pPchInfo = &(pL1CSccpchSetupReq->ptrTrchDlPch->commonParameters);
    pPichInfo = &(pL1CSccpchSetupReq->ptrTrchDlPch->pichPhys);    
    bit_mask = pL1CSccpchSetupReq->bit_mask;
    if(nFach > L1CAPI_MAX_NR_OF_FACH)
    {
      msgStatus->l1MsgResult = L1_EMSG_CMN_TRCH_SCCPCH_SETUP_REQUEST;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = nFach;
      return;      
    }
PRINTF("L23--> Sccpch Setup Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);
    ADD_WORD_VAL(L1CCellId);
    ADD_BYTE_VAL(nFach);
    /*Sccpch Info*/
    sccpchPhyInfoProcEncHdlr(msgStatus,pSccpchInfo); 
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
    /*cctrch DL*/
    cctrchEncHdlr(msgStatus,pCctrch,1);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
    /*FACH*/
    for(i=0;i<nFach;i++)
    {
      pFachInfo = &(pL1CSccpchSetupReq->ptrTrchDlFach[i]);
      sccpchTrchInfoProcEncHdlr(msgStatus,pFachInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      {
        return;
      }
    }
    /*PCH*/
    if(bit_mask & trchCommonDlPch_present)
    {
      pchTrchInfoProcEncHdlr(msgStatus,pPchInfo,pPichInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      {
        return;
      }
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
    return;
}


void cmnTrchSccpchSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

} // cmnTrchSccpchSetupRequestProcEncCommit()



