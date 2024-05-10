/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_phyShareCHProcedureDecHdlr.c

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

#include "L1C_phyShareCHProcedureDecHdlr.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"


static void hspdschCodeInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                              L1CAPI_HS_PDSCH_Code_Info *pL1CPdschCodeInfo)
{
    pL1CPdschCodeInfo->number_of_HS_PDSCH_codes = subByteVal();
    pL1CPdschCodeInfo->hS_PDSCH_Start_code_number = subByteVal();
}

static void hsscchCodeInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_HS_SCCH_Code_Info *pL1CScchCodeInfo)
{
    uint8_t i;
    pL1CScchCodeInfo->codeChoice = subByteVal();
    pL1CScchCodeInfo->codeCount = subByteVal();
    pL1CScchCodeInfo->ptrHsScchCodeNumberList = 
      (L1CAPI_DL_ChannelCodeNumber *)allocMem(sizeof(L1CAPI_DL_ChannelCodeNumber) * pL1CScchCodeInfo->codeCount,0);
    
    for(i = 0;i < pL1CScchCodeInfo->codeCount; i++)
    {
      pL1CScchCodeInfo->ptrHsScchCodeNumberList[i] = subWordVal();
    }    
}

static void sharedCHExtRlCmnEdchProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                       L1CAPI_Rl_Cmn_Edch_info *pL1CRlCmnEdchInfo)
{
    pL1CRlCmnEdchInfo->bit_mask = subByteVal();
    if(pL1CRlCmnEdchInfo->bit_mask & eAgchPwrOffset_present){
      pL1CRlCmnEdchInfo->eAgchPwrOffset = subByteVal();
    }
    if(pL1CRlCmnEdchInfo->bit_mask & eRgchHichPwrOffset_present){
      pL1CRlCmnEdchInfo->eRgchHichPwrOffset = subByteVal();
    }
}

static void sharedCHExtAgchCodeInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                         L1CAPI_E_AGCH_Code_Info *pL1CAgchCodeInfo)
{
    uint8_t i;
    
    pL1CAgchCodeInfo->codeChoice = subByteVal();
    pL1CAgchCodeInfo->codeCount = subByteVal();
    pL1CAgchCodeInfo->ptrAgchcodeNumberList = 
      (L1CAPI_DL_ChannelCodeNumber*)allocMem(sizeof(L1CAPI_DL_ChannelCodeNumber) * pL1CAgchCodeInfo->codeCount,0);
    for(i=0;i<pL1CAgchCodeInfo->codeCount;i++)
    {
       pL1CAgchCodeInfo->ptrAgchcodeNumberList[i] = subWordVal();    
    }
}

static void sharedCHExtRgchHichCodeInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                                              L1CAPI_E_RGCH_HICH_Code_Info *pL1CRgchHichCodeInfo)
{
    uint8_t i;
    pL1CRgchHichCodeInfo->codeChoice = subByteVal();
    pL1CRgchHichCodeInfo->codeCount = subByteVal();
    pL1CRgchHichCodeInfo->ptrRgchHichcodeNumberList = 
      (L1CAPI_DL_ChannelCodeNumber *)allocMem(sizeof(L1CAPI_DL_ChannelCodeNumber) * pL1CRgchHichCodeInfo->codeCount,0);
    for(i=0;i<pL1CRgchHichCodeInfo->codeCount;i++)
    {
       pL1CRgchHichCodeInfo->ptrRgchHichcodeNumberList[i] = subWordVal();    
    }
}

static void sharedCHExtProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                         L1CAPI_Physical_SharedCH_Reconfig_Ext  * pL1CExtInfo)
{
    pL1CExtInfo->bit_mask = subByteVal();
    if(pL1CExtInfo->bit_mask & hsScchCellPowerOffset_present)
    {
      pL1CExtInfo->hsScchCellPowerOffset = subByteVal();
    }
    if(pL1CExtInfo->bit_mask & eAgchRgchHichScramCode_present)
    {
      pL1CExtInfo->eAgchRgchHichScramCode = subByteVal();
    }
    if(pL1CExtInfo->bit_mask & maxTargetRTWP_present)
    {
      pL1CExtInfo->maxTargetRTWP = subWordVal();
    }
    if(pL1CExtInfo->bit_mask & refRTWP_present)
    {
      pL1CExtInfo->refRTWP = subWordVal();
    }
    if(pL1CExtInfo->bit_mask & rlCommonEDchInfo_present)
    {
      pL1CExtInfo->ptrRlCommonEDchInfo = 
        (L1CAPI_Rl_Cmn_Edch_info *)allocMem(sizeof(L1CAPI_Rl_Cmn_Edch_info),0);
      sharedCHExtRlCmnEdchProcDecHdlr(msgStatus,pL1CExtInfo->ptrRlCommonEDchInfo);      
    }
    if(pL1CExtInfo->bit_mask & eAgchCodeInfo_present)
    {
      pL1CExtInfo->ptrEagchCodeInfo = 
        (L1CAPI_E_AGCH_Code_Info *)allocMem(sizeof(L1CAPI_E_AGCH_Code_Info),0);
      sharedCHExtAgchCodeInfoProcDecHdlr(msgStatus,pL1CExtInfo->ptrEagchCodeInfo);
    }
    if(pL1CExtInfo->bit_mask & eRgchHichCodeInfo_present)
    {
      pL1CExtInfo->ptrErgchHichCodeInfo = 
        (L1CAPI_E_RGCH_HICH_Code_Info *)allocMem(sizeof(L1CAPI_E_RGCH_HICH_Code_Info),0);
      sharedCHExtRgchHichCodeInfoProcDecHdlr(msgStatus,pL1CExtInfo->ptrErgchHichCodeInfo);
    }

}

/************************************Main interface ***************************************************/

void physicalSharedChReconfigRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Physical_Share_CH_Reconfig_Request *pL1CPhySharedChReconfigReq = 
      (L1CAPI_Physical_Share_CH_Reconfig_Request *)allocMem(sizeof(L1CAPI_Physical_Share_CH_Reconfig_Request),0);
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    pL1CPhySharedChReconfigReq->bit_mask = subByteVal();
    pL1CPhySharedChReconfigReq->cId = subWordVal();

    if(pL1CPhySharedChReconfigReq->bit_mask & sfn_present){
      pL1CPhySharedChReconfigReq->sfn = subWordVal();
    }

    if(pL1CPhySharedChReconfigReq->bit_mask & hsPdschSschTotalPower_present){
      pL1CPhySharedChReconfigReq->hsPdschSschAgchRgchHichTotalPower = subWordVal();
    }
  
    if(pL1CPhySharedChReconfigReq->bit_mask & hsPdschSschScramCode_present)
    {
      pL1CPhySharedChReconfigReq->hsPdschSschScramCode = subByteVal();
    }
 
    /*pdsch code info*/
    if(pL1CPhySharedChReconfigReq->bit_mask & hsPdschCodeInfo_present)
    {
      pL1CPhySharedChReconfigReq->ptrHsPdschCodeInfo = 
        (L1CAPI_HS_PDSCH_Code_Info *)allocMem(sizeof(L1CAPI_HS_PDSCH_Code_Info),0);
      hspdschCodeInfoProcDecHdlr(msgStatus,pL1CPhySharedChReconfigReq->ptrHsPdschCodeInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*scch code info*/
    if(pL1CPhySharedChReconfigReq->bit_mask & hsScchCodeInfo_present)
    {
      pL1CPhySharedChReconfigReq->ptrHsScchCodeInfo = 
        (L1CAPI_HS_SCCH_Code_Info *)allocMem(sizeof(L1CAPI_HS_SCCH_Code_Info),0);
      hsscchCodeInfoProcDecHdlr(msgStatus,pL1CPhySharedChReconfigReq->ptrHsScchCodeInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    } 
    /*ext info*/
    if(pL1CPhySharedChReconfigReq->bit_mask & physShChRcfgExtensions_present)
    {
      pL1CPhySharedChReconfigReq->ptrPhysShChRcfgExtensions = 
        (L1CAPI_Physical_SharedCH_Reconfig_Ext *)allocMem(sizeof(L1CAPI_Physical_SharedCH_Reconfig_Ext),0);
      sharedCHExtProcDecHdlr(msgStatus,pL1CPhySharedChReconfigReq->ptrPhysShChRcfgExtensions);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
 }
