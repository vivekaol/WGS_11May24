/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_phyShareCHProcedureEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Physical Shared Channel Procedure Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_phyShareCHProcedureEncHdlr.h"
#include "L1C_phyShareCHProcedureParamValidate.h"
#include "msgPutPrimitives.h"
#include "l1capi_datastruct.h"


static void hspdschCodeInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                              void * pSrc)
{
    L1CAPI_HS_PDSCH_Code_Info *pL1CPdschCodeInfo = (L1CAPI_HS_PDSCH_Code_Info *)pSrc;


    hspdschCodeInfoProcParamValidate(msgStatus,pL1CPdschCodeInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CPdschCodeInfo->number_of_HS_PDSCH_codes);
    ADD_BYTE_VAL(pL1CPdschCodeInfo->hS_PDSCH_Start_code_number);
END_BLOCK_TRACE
}

static void hsscchCodeInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                             void * pSrc)
{
    L1CAPI_HS_SCCH_Code_Info *pL1CScchCodeInfo = (L1CAPI_HS_SCCH_Code_Info *)pSrc;
    uint8_t i;
    uint16_t code;

    
    hsscchCodeInfoProcParamValidate(msgStatus,pL1CScchCodeInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CScchCodeInfo->codeChoice);
    ADD_BYTE_VAL(pL1CScchCodeInfo->codeCount);
    for(i = 0;i < pL1CScchCodeInfo->codeCount; i++)
    {
      code = pL1CScchCodeInfo->ptrHsScchCodeNumberList[i];
      if ( code > 127 )
      {
        msgStatus->l1MsgResult = L1_EMSG_HSSCCHCODEINFO;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = code;
        return;
      }
START_BLOCK_TRACE
      ADD_WORD_VAL(code);
END_BLOCK_TRACE    
    }    
END_BLOCK_TRACE    
}

static void sharedCHExtRlCmnEdchProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                                       void * pSrc)
{    
    L1CAPI_Rl_Cmn_Edch_info *pL1CRlCmnEdchInfo = (L1CAPI_Rl_Cmn_Edch_info *)pSrc;

START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CRlCmnEdchInfo->bit_mask);
    if(pL1CRlCmnEdchInfo->bit_mask & eAgchPwrOffset_present){
      ADD_BYTE_VAL(pL1CRlCmnEdchInfo->eAgchPwrOffset);
    }
    if(pL1CRlCmnEdchInfo->bit_mask & eRgchHichPwrOffset_present){
      ADD_BYTE_VAL(pL1CRlCmnEdchInfo->eRgchHichPwrOffset);
    }
END_BLOCK_TRACE
}

static void sharedCHExtAgchCodeInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                                         void * pSrc)
{
    uint8_t i;
    uint16_t code;        
    L1CAPI_E_AGCH_Code_Info *pL1CAgchCodeInfo = (L1CAPI_E_AGCH_Code_Info *)pSrc;

START_BLOCK_TRACE
    sharedCHExtAgchCodeInfoProcParamValidate(msgStatus,pL1CAgchCodeInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
    ADD_BYTE_VAL(pL1CAgchCodeInfo->codeChoice);
    ADD_BYTE_VAL(pL1CAgchCodeInfo->codeCount);
    for(i=0;i<pL1CAgchCodeInfo->codeCount;i++)
    {
      code = pL1CAgchCodeInfo->ptrAgchcodeNumberList[i];
      if(code > 255 )
      {
        msgStatus->l1MsgResult = L1_EMSG_EAGCHCODEINFO;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = code;
        return;
       }
START_BLOCK_TRACE
       ADD_WORD_VAL(code);    
END_BLOCK_TRACE
    }
END_BLOCK_TRACE
}

static void sharedCHExtRgchHichCodeInfoProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                                              void * pSrc)
{    
    uint16_t code;
    uint8_t i;
    L1CAPI_E_RGCH_HICH_Code_Info *pL1CRgchHichCodeInfo = (L1CAPI_E_RGCH_HICH_Code_Info *)pSrc;    


    sharedCHExtRgchHichCodeInfoProcParamValidate(msgStatus,pL1CRgchHichCodeInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CRgchHichCodeInfo->codeChoice);
    ADD_BYTE_VAL(pL1CRgchHichCodeInfo->codeCount);
    for(i=0;i<pL1CRgchHichCodeInfo->codeCount;i++)
    {
      code = pL1CRgchHichCodeInfo->ptrRgchHichcodeNumberList[i];
      if(code > 127 )
      {
        msgStatus->l1MsgResult = L1_EMSG_ERGCHHICHCODEINFO;
        msgStatus->additionalInfo0 = PARAM_2;
        msgStatus->additionalInfo1 = code;
        return;
       }
START_BLOCK_TRACE
       ADD_WORD_VAL(code);    
END_BLOCK_TRACE
    }
END_BLOCK_TRACE
}

static void sharedCHExtProcEncHdlr(L1CAPI_Msg_Status *msgStatus,
                                         void * pSrc)
{    
    L1CAPI_Physical_SharedCH_Reconfig_Ext  * pL1CExtInfo = (L1CAPI_Physical_SharedCH_Reconfig_Ext *)pSrc;
    void * pOpRlCmnEdchInfo;
    void * pOpAgchCodeInfo;
    void * pRgchHichCodeInfo;    
    pOpRlCmnEdchInfo = pL1CExtInfo->ptrRlCommonEDchInfo;
    pOpAgchCodeInfo = pL1CExtInfo->ptrEagchCodeInfo;
    pRgchHichCodeInfo = pL1CExtInfo->ptrErgchHichCodeInfo;

    sharedCHExtProcParamValidate(msgStatus,pL1CExtInfo);
    if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
      return;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pL1CExtInfo->bit_mask);
    if(pL1CExtInfo->bit_mask & hsScchCellPowerOffset_present)
    {
      ADD_BYTE_VAL(pL1CExtInfo->hsScchCellPowerOffset);
    }
    if(pL1CExtInfo->bit_mask & eAgchRgchHichScramCode_present)
    {
      ADD_BYTE_VAL(pL1CExtInfo->eAgchRgchHichScramCode);
    }
    if(pL1CExtInfo->bit_mask & maxTargetRTWP_present)
    {
      ADD_WORD_VAL(pL1CExtInfo->maxTargetRTWP);
    }
    if(pL1CExtInfo->bit_mask & refRTWP_present)
    {
      ADD_WORD_VAL(pL1CExtInfo->refRTWP);
    }

    if(pL1CExtInfo->bit_mask & rlCommonEDchInfo_present)
    {
      sharedCHExtRlCmnEdchProcEncHdlr(msgStatus,pOpRlCmnEdchInfo);      
    }
    if(pL1CExtInfo->bit_mask & eAgchCodeInfo_present)
    {
      sharedCHExtAgchCodeInfoProcEncHdlr(msgStatus,pOpAgchCodeInfo);
    }
    if(pL1CExtInfo->bit_mask & eRgchHichCodeInfo_present)
    {
      sharedCHExtRgchHichCodeInfoProcEncHdlr(msgStatus,pRgchHichCodeInfo);
    }
END_BLOCK_TRACE
}


void physicalSharedChReconfigRequestProcEncHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Cell_ID L1CCellId;
    L1CAPI_SFN L1CSfn;
    L1CAPI_MaximumTransmissionPower L1CMaxHsPwr;
    L1CAPI_ScramCodeNumber L1CHsScrmCode;
    uint8_t bit_mask;
    void * pHsDschCodeInfo;
    void * pHsScchCodeInfo;
    void * pShareChReconfigExt;

    L1CAPI_Physical_Share_CH_Reconfig_Request *pL1CPhyShareCHReq = (L1CAPI_Physical_Share_CH_Reconfig_Request *) pHostDLMsg;
    L1CCellId = pL1CPhyShareCHReq->cId;
    L1CSfn = pL1CPhyShareCHReq->sfn;
    L1CMaxHsPwr = pL1CPhyShareCHReq->hsPdschSschAgchRgchHichTotalPower;
    L1CHsScrmCode = pL1CPhyShareCHReq->hsPdschSschScramCode;
    pHsDschCodeInfo = pL1CPhyShareCHReq->ptrHsPdschCodeInfo;
    pHsScchCodeInfo = pL1CPhyShareCHReq->ptrHsScchCodeInfo;
    pShareChReconfigExt = pL1CPhyShareCHReq->ptrPhysShChRcfgExtensions;
    bit_mask = pL1CPhyShareCHReq->bit_mask;
    if(L1CMaxHsPwr > 500 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSICAL_SHARED_CH_RECONFIG_REQUEST;
      msgStatus->additionalInfo0 = PARAM_2;
      msgStatus->additionalInfo1 = L1CMaxHsPwr;
      return;
    }
    if ( L1CHsScrmCode > 15 )
    {
      msgStatus->l1MsgResult = L1_EMSG_PHYSICAL_SHARED_CH_RECONFIG_REQUEST;
      msgStatus->additionalInfo0 = PARAM_3;
      msgStatus->additionalInfo1 = L1CHsScrmCode;
      return;
    }
PRINTF("L23--> Physical Shared Channel Reconfiguration Request \n");
START_BLOCK_TRACE
    ADD_BYTE_VAL(bit_mask);    
    ADD_WORD_VAL(L1CCellId);

    if(bit_mask & sfn_present){
      ADD_WORD_VAL(L1CSfn);
    }

    if(bit_mask & hsPdschSschTotalPower_present){
      ADD_WORD_VAL(L1CMaxHsPwr);
    }
  
    if(bit_mask & hsPdschSschScramCode_present)
    {
      ADD_BYTE_VAL(L1CHsScrmCode);
    }
    /*pdsch code info*/
    if(bit_mask & hsPdschCodeInfo_present)
    {
      hspdschCodeInfoProcEncHdlr(msgStatus,pHsDschCodeInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    /*scch code info*/
    if(bit_mask & hsScchCodeInfo_present)
    {
      hsscchCodeInfoProcEncHdlr(msgStatus,pHsScchCodeInfo);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    } 
    /*ext info*/
    if(bit_mask & physShChRcfgExtensions_present)
    {    
      sharedCHExtProcEncHdlr(msgStatus,pShareChReconfigExt);
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
    }
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
END_BLOCK_TRACE
}

void physicalSharedChReconfigRequestProcEncCommit ( ProcedureStatus_e procStatus  )
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

