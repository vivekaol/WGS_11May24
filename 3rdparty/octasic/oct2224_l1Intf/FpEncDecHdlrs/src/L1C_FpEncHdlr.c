/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_FpEncHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Frame Protocol Encode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "msgPutPrimitives.h"
#include "L1C_FpEncHdlr.h"
#include "l1IntEnums.h"

static __inline__ uint8_t fpR4DataHeaderEncHdlr(L1CAPI_FP_R4_DATA_MSG_Hdr *pSrc,L1MsgId_e msgId)
{
    uint8_t i;
START_BLOCK_TRACE

    if (msgId==FP_PCH_MSG)
    {
        ADD_BYTE_VAL(pSrc->pchCfnHi);
    }

    ADD_BYTE_VAL(pSrc->cfn);
    
    ADD_BYTE_VAL(pSrc->tfi);
    
    if (msgId==FP_FACH_MSG)
    {
        ADD_BYTE_VAL(pSrc->fachTxPwr);
    }
    
    //Not supported by 16UE Stack
	if (msgId==FP_RACH_MSG)
    {
        ADD_BYTE_VAL(pSrc->propagationDelay);
    }
    
    ADD_BYTE_VAL(pSrc->numTb);
	
	if (msgId == FP_RACH_MSG)
	{
		ADD_WORD_VAL(pSrc->propagationDelayQchips);
	} 
	
	//Remove the check
    //if(pSrc->payloadLen > MAX_DCH_BUFSIZE)
    //return 0;
		
    ADD_WORD_VAL(pSrc->payloadLen);
    ADD_BYTE_VAL(pSrc->direction);
    switch(msgId)
    {
      case FP_RACH_MSG:
      case FP_DCH_MSG:
          if(pSrc->direction == L1CAPI_UL_DATA_FRAME){
              ADD_BYTE_VAL(pSrc->u.ulTrchCommon.qEstimate);
              for(i=0;i<pSrc->numTb;i++)
              {
                  ADD_BYTE_VAL(pSrc->u.ulTrchCommon.crci[i]);
              }
          }
          break;
      case FP_PCH_MSG:
          ADD_BYTE_VAL(pSrc->u.pichInfo.len);
          for(i=0;i<pSrc->u.pichInfo.len;i++)
          {
              ADD_BYTE_VAL(pSrc->u.pichInfo.piBmp[i]);
          }
          break;
      default:
          break;
    }    
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpHsDschDataHeaderEncHdlr(L1CAPI_FP_HSDSCH_DATA_Hdr *pSrc)
{
START_BLOCK_TRACE
    ADD_BYTE_VAL(pSrc->flags);
    ADD_BYTE_VAL(pSrc->cmChPi);
    ADD_WORD_VAL(pSrc->macDPduLen);
    ADD_BYTE_VAL(pSrc->numPdu);
    ADD_WORD_VAL(pSrc->usrBufSize);
END_BLOCK_TRACE

    return 1;
}

static __inline__ uint8_t fpEdchDataHeaderEncHdlr(L1CAPI_FP_EDCH_DATA_MSG_Hdr *pSrc)
{
  /*_RK_*/
	

	uint8_t i,j;  
     if(pSrc->macDflowId > 8) /*Max num of Mac d flow is 8*/
    return 0;
    if(pSrc->numOfSubframes> MAX_NUM_SUB_FRAMES)
        return 0;
    for (i=0;i<pSrc->numOfSubframes;i++)
    {
       if(pSrc->subFrameHeader[i].cfn > L1CAPI_MAX_CFN_NUM)
        return 0;
    }
	START_BLOCK_TRACE
   	   ADD_BYTE_VAL(pSrc->macDflowId);
       //ADD_WORD_VAL(pSrc->payloadLen);
       ADD_BYTE_VAL(pSrc->numOfSubframes);
       for (i=0;i<pSrc->numOfSubframes;i++)
       {
        	ADD_BYTE_VAL(pSrc->subFrameHeader[i].cfn);
			ADD_BYTE_VAL(pSrc->subFrameHeader[i].SubFrameNumber);
			ADD_BYTE_VAL(pSrc->subFrameHeader[i].numOfHarqRetransmits);
			ADD_BYTE_VAL(pSrc->subFrameHeader[i].numOfEsPDUs);
	
			//mASSERT_CTRAP(pSrc->subFrameHeader[i].numOfEsPDUs==0);
	
			
	 		for(j=0;j<pSrc->subFrameHeader[i].numOfEsPDUs;j++)
	 		 {
	 		     ADD_BYTE_VAL(pSrc->subFrameHeader[i].DDI[j]);
	 		     ADD_BYTE_VAL(pSrc->subFrameHeader[i].N[j]);
				
				 //N_Log[DDIEncCnt]=pSrc->subFrameHeader[i].N[j];
				 //D_Log[DDIEncCnt++]=pSrc->subFrameHeader[i].DDI[j];
	 		 }
       }
	END_BLOCK_TRACE	
    return 1;
	
}

static __inline__ uint8_t fpDataHeaderEncHdlr(L1CAPI_FP_DATA_MSG * pSrc,L1CAPI_MsgId_e msgId)
{
    uint8_t ret = 0;
    uint32_t payloadLen = 0;
START_BLOCK_TRACE
    switch(msgId)
    {
      case FP_RACH_MSG:
      case FP_FACH_MSG:
      case FP_PCH_MSG:
      case FP_DCH_MSG:
          ret = fpR4DataHeaderEncHdlr(&pSrc->fpDatahdr.r4DataHdr,msgId);
		  payloadLen = pSrc->fpDatahdr.r4DataHdr.payloadLen;
          break;
      case FP_HSDSCH_MSG:
          ret = fpHsDschDataHeaderEncHdlr(&pSrc->fpDatahdr.hsDschDataHdr);
		  payloadLen = (pSrc->fpDatahdr.hsDschDataHdr.macDPduLen << 3) * pSrc->fpDatahdr.hsDschDataHdr.numPdu;
          break;
      case FP_EDCH_MSG:
          ret = fpEdchDataHeaderEncHdlr(&pSrc->fpDatahdr.edchDataHdr);
          break;
      default:
          break;
    }
END_BLOCK_TRACE

    return ret;
}

static __inline__ uint8_t fpR4OLPCReqEncHdlr(L1CAPI_OUTER_LOOP_PC_REQ * pSrc)
{
START_BLOCK_TRACE
    ADD_BYTE_VAL(pSrc->ul_SIR_Target);
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpHsCapReqEncHdlr(L1CAPI_HS_CAP_REQUEST * pSrc)
{
PRINT_SPACE;
#ifdef L1C_TRACE_CONTENT
    PRINTF("FP: HSDSCH CAPABILITY REQUEST \n");
#endif
START_BLOCK_TRACE
    ADD_BYTE_VAL(pSrc->cmChPi);
    ADD_WORD_VAL(pSrc->userBufSize);
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpHsCapAllocEncHdlr(L1CAPI_HS_CAP_ALLOCATION * pSrc)
{
    if(pSrc->macdFlowId > L1CAPI_MAX_NR_OF_HS_MACD_FLOWS)
        return 0;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pSrc->allocType);
    ADD_BYTE_VAL(pSrc->macdFlowId);
    ADD_BYTE_VAL(pSrc->cmChPi);
    ADD_WORD_VAL(pSrc->macDPduLen);
    ADD_BYTE_VAL(pSrc->hsDschCredits);
    ADD_BYTE_VAL(pSrc->hsDschInterval);
    ADD_BYTE_VAL(pSrc->hsDschRepPeriod);

    ADD_BYTE_VAL(pSrc->resedualPduNumber);
    ADD_WORD_VAL(pSrc->genSfn);
    ADD_BYTE_VAL(pSrc->optimizedCredit);
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpCtrlEncHdlr(L1CAPI_FP_CTRL_MSG * pSrc)
{
    uint8_t ret = 0;
START_BLOCK_TRACE
    ADD_BYTE_VAL(pSrc->ctrlMsgType);
    switch(pSrc->ctrlMsgType)
    {
      case L1CAPI_MSGTYPE_R4_OLPC_REQ:
          ret = fpR4OLPCReqEncHdlr(&pSrc->u.r4OLPCReq);
          break;
      case L1CAPI_MSGTYPE_HS_CAP_REQ:
          ret = fpHsCapReqEncHdlr(&pSrc->u.hsCapReq);
          break;
      case L1CAPI_MSGTYPE_HS_CAP_ALLOC:
          ret = fpHsCapAllocEncHdlr(&pSrc->u.hsCapAlloc);
          break;
      break;
    }
END_BLOCK_TRACE
    return ret;
}

/****************************Main Interface to OP ***************/
uint8_t fpEncHdlr(L1CAPI_FP_MSG * pSrc,L1CAPI_MsgId_e msgId)
{
    uint8_t ret = 0;
#ifdef L1C_TRACE_CONTENT
    switch(msgId)
    {
      case FP_FACH_MSG:
          PRINTF("L23--> Frame Protocl Fach Message \n");
          break;
      case FP_PCH_MSG:
          PRINTF("L23--> Frame Protocl Pch Message \n");
          break;
      case FP_DCH_MSG:
          if(pSrc->u.data.fpDatahdr.r4DataHdr.direction == L1CAPI_DL_DATA_FRAME){
            PRINTF("L23--> Frame Protocl Dch Message \n");;
          }
          break;
      case FP_HSDSCH_MSG:
          PRINTF("L23--> Frame Protocl HsDsch Message \n");
          break;     
      case FP_OLPC_MSG:
          PRINTF("L23--> Frame Protocol Outer Loop Power Control Message \n");
          break;
     default:
          PRINTF("L23--> Unknown FP Message %d\n",msgId);
          break;
    }
#endif

START_BLOCK_TRACE
    ADD_LONG_VAL(pSrc->bindingId);
    ADD_BYTE_VAL(pSrc->fp_msg_type);
    if(pSrc->fp_msg_type == L1CAPI_MSG_TYPE_FP_CTRL)
    {
      ret = fpCtrlEncHdlr(&pSrc->u.ctrl);
    }
    else{
      ret = fpDataHeaderEncHdlr(&pSrc->u.data,msgId);
    }
END_BLOCK_TRACE
    return ret;
}
