/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_prachProcedureDecHdlr.c

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

#include "L1C_prachProcedureDecHdlr.h"
#include "L1C_cctrchDecHdlr.h"
#include "L1C_tfsDecHdlr.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"

static void prachPhyInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Prach_Phy_Info *pL1CPrachPhyInfo)
{
    uint8_t i;
   
    pL1CPrachPhyInfo->commonPhysicalChannelID = subByteVal();
    pL1CPrachPhyInfo->scramblingCodeNumber = subByteVal();
    pL1CPrachPhyInfo->preambleSignatures = subWordVal();
    pL1CPrachPhyInfo->allowedSFCount = subByteVal();
    for(i=0;i<pL1CPrachPhyInfo->allowedSFCount;i++)
    {
      pL1CPrachPhyInfo->allowedSlotFormatInfo[i] = subByteVal();
    }
    pL1CPrachPhyInfo->rACH_SubChannelNumbers = subWordVal();
    pL1CPrachPhyInfo->ul_punctureLimit = subByteVal();
    pL1CPrachPhyInfo->preambleThreshold = subByteVal();
}

static void aichInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_AICH_Phy_Info *pL1CAichInfo)
{
    pL1CAichInfo->commonPhysicalChannelID = subByteVal();
    pL1CAichInfo->aICH_TransmissionTiming = subByteVal();
    pL1CAichInfo->dl_ChannelisationCodeNumber = subWordVal();
    pL1CAichInfo->aICH_Power = subWordVal();
    pL1CAichInfo->sTTD_Indicator = subByteVal();
}

static void prachTrchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                          L1CAPI_Prach_Trch_Info *pL1CPrachTrchInfo)
{
    pL1CPrachTrchInfo->commonTransportChannelID = subByteVal();
    tfsDecHdlr(msgStatus,&pL1CPrachTrchInfo->tfsUL);    
}

/****************************Main Interface to OP ***************/

void cmnTrchPrachSetupRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus)
{
    L1CAPI_Prach_Setup_Request *pL1CPrachSetupReq = 
      (L1CAPI_Prach_Setup_Request*)allocMem(sizeof(L1CAPI_Prach_Setup_Request),0);

    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    /*common Info*/
    pL1CPrachSetupReq->cmnInfo.cId = subWordVal();

    /*Prach Physical Info*/
    prachPhyInfoProcDecHdlr(msgStatus,&pL1CPrachSetupReq->physUlPrach);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
    /*AICH Info*/
    aichInfoProcDecHdlr(msgStatus,&pL1CPrachSetupReq->physDlAich);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }

    /*UL TFC*/
    cctrchDecHdlr(msgStatus,&pL1CPrachSetupReq->cctrchUlTfc);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }

    /*Trch Rach Param*/
    prachTrchInfoProcDecHdlr(msgStatus,&pL1CPrachSetupReq->trchUlPrach);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
} // cmnTrchPrachSetupRequestProcEncHdlr()
