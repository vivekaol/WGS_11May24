/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_prachProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control PRACH Procedure Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_prachProcedureEncHdlr.h"
#include "L1C_prachProcedureParamValidate.h"
#include "L1C_cctrchEncHdlr.h"
#include "L1C_tfsEncHdlr.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"



static void prachPhyInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                          void * pSrc)
{
    uint8_t i;
    L1CAPI_Prach_Phy_Info *pL1CPrachPhyInfo = (L1CAPI_Prach_Phy_Info *)pSrc;


    prachPhyInfoProcParamValidate(msgStatus,pL1CPrachPhyInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPrachPhyInfo->commonPhysicalChannelID);
    ADD_BYTE_VAL(pL1CPrachPhyInfo->scramblingCodeNumber);
    ADD_WORD_VAL(pL1CPrachPhyInfo->preambleSignatures);
    ADD_BYTE_VAL(pL1CPrachPhyInfo->allowedSFCount);
    for(i=0;i<pL1CPrachPhyInfo->allowedSFCount;i++)
    {
      ADD_BYTE_VAL(pL1CPrachPhyInfo->allowedSlotFormatInfo[i]);
    }
    ADD_WORD_VAL(pL1CPrachPhyInfo->rACH_SubChannelNumbers);
    ADD_BYTE_VAL(pL1CPrachPhyInfo->ul_punctureLimit);
    ADD_BYTE_VAL(pL1CPrachPhyInfo->preambleThreshold);
END_BLOCK_TRACE
}

static void aichInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                    void * pSrc)
{
    L1CAPI_AICH_Phy_Info *pL1CAichInfo = (L1CAPI_AICH_Phy_Info *)pSrc;

    aichInfoProcParamValidate(msgStatus,pL1CAichInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CAichInfo->commonPhysicalChannelID);
    ADD_BYTE_VAL(pL1CAichInfo->aICH_TransmissionTiming);
    ADD_WORD_VAL(pL1CAichInfo->dl_ChannelisationCodeNumber);
    ADD_WORD_VAL(pL1CAichInfo->aICH_Power);
    ADD_BYTE_VAL(pL1CAichInfo->sTTD_Indicator);
END_BLOCK_TRACE
}

static void prachTrchInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                          void * pSrc)
{
    L1CAPI_Prach_Trch_Info *pL1CPrachTrchInfo = (L1CAPI_Prach_Trch_Info *)pSrc;
    void * pTrchTf;
    pTrchTf = &(pL1CPrachTrchInfo->tfsUL);
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPrachTrchInfo->commonTransportChannelID);
    tfsEncHdlr(msgStatus,pTrchTf);    
END_BLOCK_TRACE
}

/****************************Main Interface to OP ***************/

void cmnTrchPrachSetupRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus)
{
    L1CAPI_Cell_ID L1CCellId;
    void * pPrachInfo;
    void * pAichInfo;
    void * pCctrch;
    void * pRachTrchInfo;

    L1CAPI_Prach_Setup_Request *pL1CPrachSetupReq = (L1CAPI_Prach_Setup_Request *) pHostDLMsg;
    L1CCellId = pL1CPrachSetupReq->cmnInfo.cId;
    pPrachInfo = &(pL1CPrachSetupReq->physUlPrach);
    pAichInfo = &(pL1CPrachSetupReq->physDlAich);
    pCctrch = &(pL1CPrachSetupReq->cctrchUlTfc);
    pRachTrchInfo = &(pL1CPrachSetupReq->trchUlPrach);

PRINTF("L23--> Prach Setup Request \n");
START_BLOCK_TRACE
    /*common Info*/
    ADD_WORD_VAL(L1CCellId);

    /*Prach Physical Info*/
    prachPhyInfoProcEncHdlr(msgStatus,pPrachInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
    /*AICH Info*/
    aichInfoProcEncHdlr(msgStatus,pAichInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }

    /*UL TFC*/
    cctrchEncHdlr(msgStatus,pCctrch,0);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }

    /*Trch Rach Param*/
    prachTrchInfoProcEncHdlr(msgStatus,pRachTrchInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
} // cmnTrchPrachSetupRequestProcEncHdlr()

void cmnTrchPrachSetupRequestProcEncCommit ( ProcedureStatus_e procStatus  )
{
  /*Add the procedure handler commit code here.*/
  if (procStatus == PROC_COMMIT)
  {
  }
  else
  {
  }

  return;

} // cmnTrchPrachSetupRequestProcEncCommit()


