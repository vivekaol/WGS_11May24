/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_radiolinkProcedureDecHdlr.h

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

#ifndef _L1C_RADIOLINKPROCEDUREDECHDLR_H_
#define _L1C_RADIOLINKPROCEDUREDECHDLR_H_
#include "l1MsgStatus.h"
#include "msgGetPrimitives.h"
#include "l1capi_datastruct.h"

void radiolinkSetupRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
void radiolinkReconfigPrepRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
//void radiolinkReconfigCommitRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
//void radiolinkDeleteRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );

static __inline__ void radiolinkReconfigCancelRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
static __inline__ void activePatternInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_Active_Pattern_Seq4 *pL1CActvPatternInfo);
static __inline__ void activeTgpsPatternProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_Active_Pattern_Sequence_Info *pL1CActvPattern);                                            
static __inline__ void radiolinkReconfigCancelRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
static __inline__ void radiolinkReconfigCommitRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
static __inline__ void radiolinkDeleteRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus );
                                            
static __inline__ void radiolinkReconfigCancelRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Radiolink_ReconfigCancel *pl1CRlReconfigCancel = (L1CAPI_Radiolink_ReconfigCancel *)allocMem(sizeof(L1CAPI_Radiolink_ReconfigCancel),0);
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    pl1CRlReconfigCancel->NodeBComContext = subByteVal();
} 

static __inline__ void activePatternInfoProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                             L1CAPI_Active_Pattern_Seq4 *pL1CActvPatternInfo)
{
    pL1CActvPatternInfo->tGPSID = subByteVal();
    pL1CActvPatternInfo->tGPRC = subWordVal();
    pL1CActvPatternInfo->tGCFN = subByteVal();
}

static __inline__ void activeTgpsPatternProcDecHdlr(L1CAPI_Msg_Status *msgStatus,
                                               L1CAPI_Active_Pattern_Sequence_Info *pL1CActvPattern)
{
    uint8_t i;
    pL1CActvPattern->cMConfigurationChangeCFN = subByteVal();
    pL1CActvPattern->tgpssCount = subByteVal();    
    pL1CActvPattern->ptrTgpss = 
    (L1CAPI_Active_Pattern_Seq4 * )allocMem(sizeof(L1CAPI_Active_Pattern_Seq4) * pL1CActvPattern->tgpssCount,0);
    for(i=0;i<pL1CActvPattern->tgpssCount;i++)
    {
      activePatternInfoProcDecHdlr(msgStatus,&(pL1CActvPattern->ptrTgpss[i]));
      if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;       
    }
}

static __inline__ void radiolinkReconfigCommitRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    L1CAPI_Radiolink_ReconfigCommit *pl1CRlReconfigReq = (L1CAPI_Radiolink_ReconfigCommit *)allocMem(sizeof(L1CAPI_Radiolink_ReconfigCommit),0);

    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    pl1CRlReconfigReq->bit_mask = subByteVal();
    pl1CRlReconfigReq->NodeBComContext = subByteVal();
    pl1CRlReconfigReq->cfn = subByteVal();    
    
    if(pl1CRlReconfigReq->bit_mask & activePattSeqInfo_present)
    {
      pl1CRlReconfigReq->ptrActivePattSeqInfo = 
        (L1CAPI_Active_Pattern_Sequence_Info *)allocMem(sizeof(L1CAPI_Active_Pattern_Sequence_Info),0);          
      activeTgpsPatternProcDecHdlr(msgStatus,pl1CRlReconfigReq->ptrActivePattSeqInfo);
    }
} 

static __inline__ void radiolinkDeleteRequestProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
    uint8_t i;
    L1CAPI_Radiolink_DeletionRequest *pl1CRlDelReq = (L1CAPI_Radiolink_DeletionRequest *)allocMem(sizeof(L1CAPI_Radiolink_DeletionRequest),0);

    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    pl1CRlDelReq->NodeBComContext = subByteVal();
    pl1CRlDelReq->rlCount = subByteVal();    
    pl1CRlDelReq->pRl_ID = (L1CAPI_Radiolink_ID *)allocMem(sizeof(L1CAPI_Radiolink_ID) * pl1CRlDelReq->rlCount,0);
    for(i=0;i<pl1CRlDelReq->rlCount;i++)
    {
      pl1CRlDelReq->pRl_ID[i] = subByteVal();
    }
}
static __inline__ void compressedModeCommandProcDecHdlr( L1CAPI_Msg_Status *msgStatus )
{
     L1CAPI_Compressed_Mode_Command *pL1CCMCommand = (L1CAPI_Compressed_Mode_Command *)allocMem(sizeof(L1CAPI_Compressed_Mode_Command),0);
    msgStatus->l1MsgResult = L1_MSG_SUCCESS;
    pL1CCMCommand->bit_mask = subByteVal(); // for future use
	pL1CCMCommand->NodeBComContext = subByteVal();
    /*active pattern info*/
    activeTgpsPatternProcDecHdlr(msgStatus,&pL1CCMCommand->ActivePattSeqInfo);
	if(msgStatus->l1MsgResult != L1_MSG_SUCCESS)
        return;
}
#endif 
