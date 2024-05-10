/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sccpchProcedureDecHdlr.c

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

#include "L1C_sccpchProcedureDecHdlr.h"
#include "L1C_cctrchDecHdlr.h"
#include "L1C_tfsDecHdlr.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"


static void sccpchTrchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                            L1CAPI_SCCPCH_Trch_Info   *pL1CTrchDl)
{
    pL1CTrchDl->commonTransportChannelID = subByteVal();
    pL1CTrchDl->maxFACH_PCH_Power = subWordVal();
    pL1CTrchDl->toAWS = subWordVal();
    pL1CTrchDl->toAWE = subWordVal();
    tfsDecHdlr(msgStatus,&pL1CTrchDl->tfsDL);    
}

static void pichInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_PICH_Params   *pL1CPichInfo)
{
    pL1CPichInfo->commonPhysicalChannelID = subByteVal();
    pL1CPichInfo->dl_ChannelisationCodeNumber = subWordVal();
    pL1CPichInfo->pICH_Power = subByteVal();
    pL1CPichInfo->pICH_Mode = subByteVal();
    pL1CPichInfo->sTTD_Indicator = subByteVal();
}

static void pchTrchInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_PCH_Info * pL1CPchTrchInfo)
{
    sccpchTrchInfoProcDecHdlr(msgStatus,&pL1CPchTrchInfo->commonParameters);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    pichInfoProcDecHdlr(msgStatus,&pL1CPchTrchInfo->pichPhys);
}

static void sccpchPhyInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                           L1CAPI_SCCPCH_Phy_Info *pL1CSccpchPhyInfo)
{
    pL1CSccpchPhyInfo->bit_mask = subByteVal();
    pL1CSccpchPhyInfo->commonPhysicalChannelID = subByteVal();
    pL1CSccpchPhyInfo->sCCPCH_Chip_Offset = subByteVal();
    if(pL1CSccpchPhyInfo->bit_mask & dl_ScramblingCode_present){
      pL1CSccpchPhyInfo->dl_ScramblingCode = subByteVal();
    }
    pL1CSccpchPhyInfo->dL_ChannelisationCodeNumber = subWordVal();
    pL1CSccpchPhyInfo->sCCPCH_SlotFormat = subByteVal();
    if(pL1CSccpchPhyInfo->bit_mask & sccpch_tFCI_present){    
      pL1CSccpchPhyInfo->tFCI_Presence = subByteVal();
    }
    pL1CSccpchPhyInfo->multiplexingPosition = subByteVal();    
    pL1CSccpchPhyInfo->pO1_ForTFCI_Bits = subByteVal();
    pL1CSccpchPhyInfo->pO3_ForPilotBits = subByteVal();    
    pL1CSccpchPhyInfo->sTTD_Indicator = subByteVal();    
}

/****************************main interface***************************************/

void cmnTrchSccpchSetupRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Sccpch_Setup_Request *pL1CSccpchSetupReq = (L1CAPI_Sccpch_Setup_Request*)allocMem(sizeof(L1CAPI_Sccpch_Setup_Request),0);  
    uint8_t i;
    
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;    
    pL1CSccpchSetupReq->bit_mask = subByteVal();
    pL1CSccpchSetupReq->cmnInfo.cId = subWordVal();
    pL1CSccpchSetupReq->nFach = subByteVal();
    pL1CSccpchSetupReq->ptrTrchDlFach = 
      (L1CAPI_SCCPCH_Trch_Info *)allocMem(pL1CSccpchSetupReq->nFach * sizeof(L1CAPI_SCCPCH_Trch_Info),0);
    /*Sccpch Info*/
    sccpchPhyInfoProcDecHdlr(msgStatus,&pL1CSccpchSetupReq->physDlSCcpch); 
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
    /*cctrch DL*/
    cctrchDecHdlr(msgStatus,&pL1CSccpchSetupReq->cctrchDlTfc);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
    {
      return;
    }
    /*FACH*/
    for(i=0;i<pL1CSccpchSetupReq->nFach;i++)
    {
      sccpchTrchInfoProcDecHdlr(msgStatus,&(pL1CSccpchSetupReq->ptrTrchDlFach[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      {
        return;
      }
    }
    /*PCH*/
    if(pL1CSccpchSetupReq->bit_mask & trchCommonDlPch_present)
    {
      pL1CSccpchSetupReq->ptrTrchDlPch = 
        (L1CAPI_PCH_Info *)allocMem(sizeof(L1CAPI_PCH_Info),0);
      pchTrchInfoProcDecHdlr(msgStatus,pL1CSccpchSetupReq->ptrTrchDlPch);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      {
        return;
      }
    }

    return;
}

