/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1CAPI_Validation.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control API Validation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include "op_sa_l1api_structs.h"
#include "l1capi_datastruct.h"

#include "msgGetPrimitives.h"
#include "msgPutPrimitives.h"
#include "msgHeaderDef.h"
#include "msgHeaderCodec.h"
#include "msgHdrMsgEncHdlr.h"
#include "msgHdrMsgDecHdlr.h"

#include "L1C_cellProcedureEncHdlr.h"
#include "L1C_cellProcedureDecHdlr.h"
#include "L1C_CellProcValidation.h"

#include "L1C_prachProcedureEncHdlr.h"
#include "L1C_prachProcedureDecHdlr.h"
#include "L1C_PrachProcValidation.h"

#include "L1C_sccpchProcedureEncHdlr.h"
#include "L1C_sccpchProcedureDecHdlr.h"
#include "L1C_SccpchProcValidation.h"

#include "L1C_phyShareCHProcedureEncHdlr.h"
#include "L1C_phyShareCHProcedureDecHdlr.h"
#include "L1C_PhySharedCHProcValidation.h"

#include "L1C_radiolinkProcedureEncHdlr.h"
#include "L1C_radiolinkProcedureDecHdlr.h"
#include "L1C_RadiolinkProcValidation.h"

#include "L1C_responseProcedureEncHdlr.h"
#include "L1C_responseProcDecHdlr.h"

#include "L1C_GenericRespProcValidation.h"
#include "L1C_PrachRespProcValidation.h"
#include "L1C_RadiolinkReconfigReadyProcValidation.h"
#include "L1C_RadiolinkSetupRespProcValidation.h"
#include "L1C_SccpchRespProcValidation.h"

#include "L1C_FpEncHdlr.h"
#include "L1C_FpDecHdlr.h"

void * pHostDLMsg;
void * pHostUlMsg;

static uint8_t SASendL1Buf[4096];
static uint8_t SARecvL1Buf[4096];
static uint8_t SaL1DecBuf[4096];

static uint16_t transactionID = 0;
static uint16_t totalMsgSize = 0;
static MsgHdr_t msgHdr;

uint8_t cellSetupReqValidate()
{

	L1CAPI_Cell_Setup_Request * pL1CCodecResult = NULL;
	L1CAPI_Cell_Setup_Request * pL1CExpectResult = getL1CCellSetupRequest();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;
	
	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);
    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    cellSetupRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Cell Setup Request encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = CELL_SETUP_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
    pL1CCodecResult = (L1CAPI_Cell_Setup_Request *)SARecvL1Buf;

	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	cellSetupRequestProcDecHdlr(&msgStatus);	
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Cell Setup Request decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateCellSetupReqCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Cell Setup Request codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t prachSetupReqValidate()
{

	L1CAPI_Prach_Setup_Request * pL1CCodecResult = NULL;
	L1CAPI_Prach_Setup_Request * pL1CExpectResult = getL1CPrachSetupRequest();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    cmnTrchPrachSetupRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Prach Setup Request encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = CMN_TRCH_PRACH_SETUP_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
	pL1CCodecResult = (L1CAPI_Prach_Setup_Request *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	cmnTrchPrachSetupRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Prach Setup Request decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	pL1CExpectResult = getL1CPrachSetupRequest();
	if(!validatePrachSetupReqCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Prach Setup Request codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t sccpchSetupReqValidate()
{

	L1CAPI_Sccpch_Setup_Request * pL1CCodecResult = NULL;
	L1CAPI_Sccpch_Setup_Request * pL1CExpectResult = getL1CSccpchSetupRequest();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    cmnTrchSccpchSetupRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Sccpch Setup Request encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = CMN_TRCH_SCCPCH_SETUP_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
	pL1CCodecResult = (L1CAPI_Sccpch_Setup_Request *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	cmnTrchSccpchSetupRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Sccpch Setup Request decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}

	if(!validateSccpchSetupReqCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Sccpch Setup Request codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t phySharedCHReconfigReqValidate()
{

	L1CAPI_Physical_Share_CH_Reconfig_Request * pL1CCodecResult = NULL;
	L1CAPI_Physical_Share_CH_Reconfig_Request * pL1CExpectResult = getL1CSharedChReconfigRequest();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    physicalSharedChReconfigRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Sccpch Setup Request encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = PHYSICAL_SHARED_CH_RECONFIG_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
	pL1CCodecResult = (L1CAPI_Physical_Share_CH_Reconfig_Request *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	physicalSharedChReconfigRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("PhyShared Channel Reconfig Request decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}

	if(!validateSharedCHReconfigReqCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("PhyShared Channel Reconfig Request codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t radiolinkSetupReqValidate()
{

	L1CAPI_Radiolink_Setup_Request * pL1CCodecResult = NULL;
	L1CAPI_Radiolink_Setup_Request * pL1CExpectResult = getL1CRadiolinkSetupRequest();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    radiolinkSetupRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Setup Request encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = RADIOLINK_SETUP_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
    pL1CCodecResult = (L1CAPI_Radiolink_Setup_Request *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	radiolinkSetupRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Prach Setup Request decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}

	if(!validateRadiolinkSetupReqCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Radiolink Setup Request codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t radiolinkReconfigPrepareValidate()
{

	L1CAPI_Radiolink_Reconfig_Prepare * pL1CCodecResult = NULL;
	L1CAPI_Radiolink_Reconfig_Prepare * pL1CExpectResult = getL1CRadiolinkReconfigPrepare();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    radiolinkReconfigPrepRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Reconfig Prepare encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = RADIOLINK_RECONFIG_PREP_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
	pL1CCodecResult = (L1CAPI_Radiolink_Reconfig_Prepare *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	radiolinkReconfigPrepRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Reconfig Prepare decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}

	if(!validateRadiolinkReconfigPrepareCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Radiolink Reconfig Prepare codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t radiolinkReconfigCommitValidate()
{

	L1CAPI_Radiolink_ReconfigCommit * pL1CCodecResult = NULL;
	L1CAPI_Radiolink_ReconfigCommit * pL1CExpectResult = getL1CRadiolinkReconfigCommit();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
	radiolinkReconfigCommitRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Reconfig Commit encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = RADIOLINK_RECONFIG_COMMIT_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
    pL1CCodecResult = (L1CAPI_Radiolink_ReconfigCommit *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	radiolinkReconfigCommitRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Reconfig Commit decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateRadiolinkReconfigCommitCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Radiolink Reconfig Commit codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t rlDeleteValidate()
{

	L1CAPI_Radiolink_DeletionRequest * pL1CCodecResult = NULL;
	L1CAPI_Radiolink_DeletionRequest * pL1CExpectResult = getL1CRadiolinkDeletion();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SARecvL1Buf,0,4096);

    resetMsgWrite(SASendL1Buf);
	pHostDLMsg = pL1CExpectResult;
    radiolinkDeleteRequestProcEncHdlr( &msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Delete encode failed!\n");
      return 0;
	}
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = RADIOLINK_DELETE_REQUEST;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	resetMsgRead(SASendL1Buf);
	if(!resetMsgBufferAlloc(SARecvL1Buf,4096,0))
		return 0;
	pL1CCodecResult = (L1CAPI_Radiolink_DeletionRequest *)SARecvL1Buf;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}
	radiolinkDeleteRequestProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Delete decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateRadiolinkDeletionCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Radiolink Delete codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t genericRespValidate()
{
	L1CAPI_Generic_Response * l1cGenericResp = getL1CGenericResp();
	L1CAPI_Generic_Response * pL1CCodecResult  = NULL;
	L1CAPI_Generic_Response * pL1CExpectResult  = getL1CGenericResp();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);
    genericResponseEncHdlr(l1cGenericResp);
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = GENERIC_RESPONSE;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	pHostUlMsg = SaL1DecBuf;
	pL1CCodecResult = (L1CAPI_Generic_Response *)SaL1DecBuf;
	if(!resetMsgBufferAlloc(SaL1DecBuf,4096,0))
		return 0;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}

	genericResponseProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Generic Response decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateGenericRespCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Generic Response codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t prachSetupRespValidate()
{
    L1CAPI_Prach_Setup_Response * l1cpRachSetupResp = getL1CPrachSetupResp();
	L1CAPI_Prach_Setup_Response * pL1CCodecResult = NULL;
	L1CAPI_Prach_Setup_Response * pL1CExpectResult = getL1CPrachSetupResp();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);
    prachSetupResponseEncHdlr(l1cpRachSetupResp);

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = CMN_TRCH_PRACH_SETUP_RESPONSE;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	pHostUlMsg = SaL1DecBuf;
	pL1CCodecResult = (L1CAPI_Prach_Setup_Response *)SaL1DecBuf;
	if(!resetMsgBufferAlloc(SaL1DecBuf,4096,0))
		return 0;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}

	cmnTrchPrachSetupResponseProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Prach Setup Response decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validatePrachSetupRespCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Prach Setup Response codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t sccpchSetupRespValidate()
{
    L1CAPI_Sccpch_Setup_Response * l1cSccpchSetupResp = getL1CSccpchSetupResp();
	L1CAPI_Sccpch_Setup_Response * pL1CCodecResult = NULL;
	L1CAPI_Sccpch_Setup_Response * pL1CExpectResult = getL1CSccpchSetupResp();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);
    sccpchSetupResponseEncHdlr(l1cSccpchSetupResp);

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = CMN_TRCH_SCCPCH_SETUP_RESPONSE;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	pHostUlMsg = SaL1DecBuf;
	pL1CCodecResult = (L1CAPI_Sccpch_Setup_Response *)SaL1DecBuf;
	if(!resetMsgBufferAlloc(SaL1DecBuf,4096,0))
		return 0;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}

	cmnTrchSccpchSetupResponseProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Sccpch Setup Response decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateSccpchSetupRespCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Sccpch Setup codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t rlSetupRespValidate()
{
    L1CAPI_Radiolink_Setup_Response * l1cRlSetupResp = getL1CRlSetupResp();
	L1CAPI_Radiolink_Setup_Response * pL1CCodecResult = NULL;
	L1CAPI_Radiolink_Setup_Response * pL1CExpectResult = getL1CRlSetupResp();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);
    radiolinkSetupResponseEncHdlr(l1cRlSetupResp);

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = RADIOLINK_SETUP_RESPONSE;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	pHostUlMsg = SaL1DecBuf;
	pL1CCodecResult = (L1CAPI_Radiolink_Setup_Response *)SaL1DecBuf;
	if(!resetMsgBufferAlloc(SaL1DecBuf,4096,0))
		return 0;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}

	radiolinkSetupResponseProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Setup Response decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateRlSetupRespCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Radiolink Setup Response codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t rlReconfigReadyValidate()
{
    L1CAPI_Radiolink_Reconfigure_Ready * l1cRlReconfigReady = getL1CRlReconfigRerady();
	L1CAPI_Radiolink_Reconfigure_Ready * pL1CCodecResult = NULL;
	L1CAPI_Radiolink_Reconfigure_Ready * pL1CExpectResult = getL1CRlReconfigRerady();
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);
    radiolinkReconfigReadyEncHdlr(l1cRlReconfigReady);
	
	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = RADIOLINK_RECONFIG_READY;
	msgHdr.msgType = CTRL_NBAP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}

	resetMsgRead(SASendL1Buf);
	pHostUlMsg = SaL1DecBuf;
	pL1CCodecResult = (L1CAPI_Radiolink_Reconfigure_Ready  *)SaL1DecBuf;
	if(!resetMsgBufferAlloc(SaL1DecBuf,4096,0))
		return 0;
	msgHdrMsgDecHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header decode failure!\n");
		return 0;
	}

	radiolinkReconfigReadyProcDecHdlr(&msgStatus);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
      printf("Radiolink Reconfig Ready decode failed!\n");
      return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(!validateRlReconfigReadyCodecOutput(pL1CCodecResult,pL1CExpectResult)){
		printf("Radiolink Reconfig Ready codec failure!\n");
		return 0;
	}
	return 1;
}

uint8_t fpR4UlDchDataValidate()
{
	L1CAPI_FP_MSG fpR4UlDchData;
	uint8_t * wrPtr = NULL;
	L1CAPI_FP_MSG * fpR4DecodedUlDchData;
	L1CAPI_Msg_Status msgStatus;
	int ret =0;
	 uint8_t paylaod[40] = {0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d
							};

	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(&fpR4UlDchData,0,sizeof(L1CAPI_FP_MSG));
	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);

	fpR4UlDchData.bindingId = 0x8801;
	fpR4UlDchData.fp_msg_type = L1CAPI_MSG_TYPE_FP_DATA;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.direction = L1CAPI_UL_DATA_FRAME;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.cfn = 2;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.tfi = 1;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.numTb = 4;	
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.u.ulTrchCommon.crci[0] = 1;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.u.ulTrchCommon.crci[1] = 1;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.u.ulTrchCommon.crci[2] = 1;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.u.ulTrchCommon.crci[3] = 1;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.u.ulTrchCommon.qEstimate = 2;
	fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.payloadLen = 40;
	
	if(!fpEncHdlr(&fpR4UlDchData,FP_DCH_MSG)){
		printf("ul Dch Fp data header encode error\n");
		return 0;
	}
	wrPtr = getCurrentBodyWrPtr();
	memcpy(wrPtr,paylaod,40);
	addBodyWrOffset(40);

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = FP_DCH_MSG;
	msgHdr.msgType = FP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	
	memcpy(SARecvL1Buf,SASendL1Buf,4096);

	resetMsgRead(SARecvL1Buf);
	fpR4DecodedUlDchData = (L1CAPI_FP_MSG *)SaL1DecBuf;
	if(!fpDecHdlr(fpR4DecodedUlDchData,FP_DCH_MSG)){
		printf("ul Dch Fp data header decode error\n");
		return 0;
	}
	if(obtainMsgInSize() + fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.payloadLen != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(memcmp(fpR4DecodedUlDchData,&fpR4UlDchData,sizeof(L1CAPI_FP_MSG))){
		printf("ul Dch Fp data header compare error\n");
		return 0;
	}
	fpR4UlDchData.u.data.payload = getCurrentBodyRdPtr();

	if(ret = memcmp(fpR4UlDchData.u.data.payload,paylaod,fpR4UlDchData.u.data.fpDatahdr.r4DataHdr.payloadLen)){
		printf("ul Dch Fp data payload compare error\n");
		return 0;
	}
	return 1;
}


uint8_t fpR4DlPchDataValidate()
{
	L1CAPI_FP_MSG fpR4DlPchData;
	uint8_t * wrPtr = NULL;
	L1CAPI_FP_MSG * fpR4DecodedDlPchData;
	L1CAPI_Msg_Status msgStatus;
	int ret =0;
	uint8_t i;
	uint8_t paylaod[40] = {0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d
							};

	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(&fpR4DlPchData,0,sizeof(L1CAPI_FP_MSG));
	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);

	fpR4DlPchData.bindingId = 0x8801;
	fpR4DlPchData.fp_msg_type = L1CAPI_MSG_TYPE_FP_DATA;
	fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.direction = L1CAPI_DL_DATA_FRAME;
	fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.cfn = 2;
	fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.tfi = 1;
	fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.numTb = 4;	
	fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.u.pichInfo.len = 18;
	for(i=0;i<fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.u.pichInfo.len;i++)
	{
		fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.u.pichInfo.piBmp[i] = 0xff;
	}
	fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.payloadLen = 40;
	
	if(!fpEncHdlr(&fpR4DlPchData,FP_PCH_MSG)){
		printf("dl Pch Fp data header encode error\n");
		return 0;
	}
	wrPtr = getCurrentBodyWrPtr();
	memcpy(wrPtr,paylaod,40);
	addBodyWrOffset(40);

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = FP_PCH_MSG;
	msgHdr.msgType = FP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	
	memcpy(SARecvL1Buf,SASendL1Buf,4096);

	resetMsgRead(SARecvL1Buf);
	fpR4DecodedDlPchData = (L1CAPI_FP_MSG *)SaL1DecBuf;
	if(!fpDecHdlr(fpR4DecodedDlPchData,FP_PCH_MSG)){
		printf("dl Pch Fp data header decode error\n");
		return 0;
	}
	if(obtainMsgInSize() + fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.payloadLen != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(memcmp(fpR4DecodedDlPchData,&fpR4DlPchData,sizeof(L1CAPI_FP_MSG))){
		printf("dl Pch Fp data header compare error\n");
		return 0;
	}
	fpR4DlPchData.u.data.payload = getCurrentBodyRdPtr();

	if(ret = memcmp(fpR4DlPchData.u.data.payload,paylaod,fpR4DlPchData.u.data.fpDatahdr.r4DataHdr.payloadLen)){
		printf("dl Pch Fp data payload compare error\n");
		return 0;
	}
	return 1;
}

uint8_t fpR5HsdschDataValidate()
{
	L1CAPI_FP_MSG fpR5HsdschData;
	uint8_t * wrPtr = NULL;
	L1CAPI_FP_MSG * fpR5DecodedHsDschData;
	L1CAPI_Msg_Status msgStatus;
	int ret =0;
	uint8_t paylaod[82] = {
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b,0x3c,0x4d,
						   0x1a,0x2b
							};

	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(&fpR5HsdschData,0,sizeof(L1CAPI_FP_MSG));
	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);

	fpR5HsdschData.bindingId = 0x8801;
	fpR5HsdschData.fp_msg_type = L1CAPI_MSG_TYPE_FP_DATA;
	fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.cmChPi = 2;
	fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.macdFlowId = 0;
	fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.macDPduLen = 656;
	fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.numPdu = 1;
	fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.usrBufSize = 256;
	
	if(!fpEncHdlr(&fpR5HsdschData,FP_HSDSCH_MSG)){
		printf("HSDsch Fp data header encode error\n");
		return 0;
	}
	wrPtr = getCurrentBodyWrPtr();
	memcpy(wrPtr,paylaod,82);
	addBodyWrOffset(82);

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = FP_HSDSCH_MSG;
	msgHdr.msgType = FP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	
	memcpy(SARecvL1Buf,SASendL1Buf,4096);

	resetMsgRead(SARecvL1Buf);
	fpR5DecodedHsDschData = (L1CAPI_FP_MSG *)SaL1DecBuf;
	if(!fpDecHdlr(fpR5DecodedHsDschData,FP_HSDSCH_MSG)){
		printf("HSDsch Fp data header decode error\n");
		return 0;
	}
	if(obtainMsgInSize() + ((fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.macDPduLen * fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.numPdu) >> 3)
		!= msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(memcmp(fpR5DecodedHsDschData,&fpR5HsdschData,sizeof(L1CAPI_FP_MSG))){
		printf("HSDsch Fp data header compare error\n");
		return 0;
	}
	fpR5HsdschData.u.data.payload = getCurrentBodyRdPtr();

	if(ret = memcmp(fpR5HsdschData.u.data.payload,paylaod,
		            ((fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.macDPduLen * fpR5HsdschData.u.data.fpDatahdr.hsDschDataHdr.numPdu) >> 3))){
		printf("HSDsch Fp data payload compare error\n");
		return 0;
	}
	return 1;
}

uint8_t fpR5HsCapReqValidate()
{
	L1CAPI_FP_MSG fpR5HsCapReq;
	uint8_t * wrPtr = NULL;
	L1CAPI_FP_MSG * fpR5DecodedHsCapReq;
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(&fpR5HsCapReq,0,sizeof(L1CAPI_FP_MSG));
	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);

	fpR5HsCapReq.bindingId = 0x8801;
	fpR5HsCapReq.fp_msg_type = L1CAPI_MSG_TYPE_FP_CTRL;
	fpR5HsCapReq.u.ctrl.ctrlMsgType = L1CAPI_MSGTYPE_HS_CAP_REQ;
	fpR5HsCapReq.u.ctrl.u.hsCapReq.cmChPi = 5;
	fpR5HsCapReq.u.ctrl.u.hsCapReq.userBufSize = 256;
	
	if(!fpEncHdlr(&fpR5HsCapReq,FP_HSDSCH_MSG)){
		printf("Fp ctrl header encode error\n");
		return 0;
	}

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = FP_HSDSCH_MSG;
	msgHdr.msgType = FP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	
	memcpy(SARecvL1Buf,SASendL1Buf,4096);

	resetMsgRead(SARecvL1Buf);
	fpR5DecodedHsCapReq = (L1CAPI_FP_MSG *)SaL1DecBuf;
	if(!fpDecHdlr(fpR5DecodedHsCapReq,FP_HSDSCH_MSG)){
		printf("Fp cap req header decode error\n");
		return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(memcmp(fpR5DecodedHsCapReq,&fpR5HsCapReq,sizeof(L1CAPI_FP_MSG))){
		printf("Fp cap req compare error\n");
		return 0;
	}
	return 1;
}


uint8_t fpR5HsCapAllocValidate()
{
	L1CAPI_FP_MSG fpR5HsCapAlloc;
	uint8_t * wrPtr = NULL;
	L1CAPI_FP_MSG * fpR5DecodedHsCapAlloc;
	L1CAPI_Msg_Status msgStatus;
	msgStatus.l1MsgResult = L1_MSG_SUCCESS;

	memset(&fpR5HsCapAlloc,0,sizeof(L1CAPI_FP_MSG));
	memset(SASendL1Buf,0,4096);
	memset(SaL1DecBuf,0,4096);
	memset(SARecvL1Buf,0,4096);

	resetMsgWrite(SASendL1Buf);

	fpR5HsCapAlloc.bindingId = 0x8801;
	fpR5HsCapAlloc.fp_msg_type = L1CAPI_MSG_TYPE_FP_CTRL;
	fpR5HsCapAlloc.u.ctrl.ctrlMsgType = L1CAPI_MSGTYPE_HS_CAP_ALLOC;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.allocType = L1C_HSDSCH_ALLOC_TYPE_ONE;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.cmChPi = 1;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.genSfn = 1024;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.hsDschCredits = 100;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.hsDschInterval = 1;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.hsDschRepPeriod = 2;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.macdFlowId = 1;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.macDPduLen = 656;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.optimizedCredit = 50;
	fpR5HsCapAlloc.u.ctrl.u.hsCapAlloc.resedualPduNumber = 50;
	
	if(!fpEncHdlr(&fpR5HsCapAlloc,FP_HSDSCH_MSG)){
		printf("Fp ctrl header encode error\n");
		return 0;
	}

	totalMsgSize = findMsgBodySize();
	msgHdr.msgSize = totalMsgSize;
	msgHdr.transactionId = transactionID++;
	msgHdr.msgId = FP_HSDSCH_MSG;
	msgHdr.msgType = FP_MSG;
	msgHdrMsgEncHdlr(&msgStatus,&msgHdr);
	if(msgStatus.l1MsgResult != L1_MSG_SUCCESS){
		printf("Header encode failure!\n");
		return 0;
	}
	
	memcpy(SARecvL1Buf,SASendL1Buf,4096);

	resetMsgRead(SARecvL1Buf);
	fpR5DecodedHsCapAlloc = (L1CAPI_FP_MSG *)SaL1DecBuf;
	if(!fpDecHdlr(fpR5DecodedHsCapAlloc,FP_HSDSCH_MSG)){
		printf("Fp cap alloc header decode error\n");
		return 0;
	}
	if(obtainMsgInSize() != msgHdr.msgSize + MSG_HDR_SIZE){
		printf("msg size is not matching!\n");
		return 0;
	}
	if(memcmp(fpR5DecodedHsCapAlloc,&fpR5HsCapAlloc,sizeof(L1CAPI_FP_MSG))){
		printf("Fp cap alloc compare error\n");
		return 0;
	}
	return 1;
}
