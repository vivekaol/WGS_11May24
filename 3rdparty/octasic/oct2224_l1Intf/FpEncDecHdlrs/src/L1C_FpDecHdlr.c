/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_FpDecHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Frame Protocol Decode Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "msgGetPrimitives.h"
#include "L1C_FpDecHdlr.h"

static __inline__ uint8_t fpR4DataHeaderDecHdlr(L1CAPI_FP_R4_DATA_MSG_Hdr *pSrc,L1MsgId_e msgId)
{
    uint8_t i;
START_BLOCK_TRACE
    if (msgId==FP_PCH_MSG)
    {
        SUB_BYTE_VAL(pSrc->pchCfnHi);
    }
    
    SUB_BYTE_VAL(pSrc->cfn);
    
    SUB_BYTE_VAL(pSrc->tfi);

    if (msgId==FP_FACH_MSG)
    {
        SUB_BYTE_VAL(pSrc->fachTxPwr);
    }
    
    if (msgId==FP_RACH_MSG)
    {
        SUB_BYTE_VAL(pSrc->propagationDelay);
    }
    
    SUB_BYTE_VAL(pSrc->numTb);
	
	if (msgId == FP_RACH_MSG)
	{
		SUB_WORD_VAL(pSrc->propagationDelayQchips);
	}
    
	SUB_WORD_VAL(pSrc->payloadLen);
    SUB_BYTE_VAL(pSrc->direction);
    
    switch(msgId)
    {
      case FP_RACH_MSG:
      case FP_DCH_MSG:
           if(pSrc->direction == L1CAPI_UL_DATA_FRAME)
           {
               SUB_BYTE_VAL(pSrc->u.ulTrchCommon.qEstimate);
               for(i=0;i<pSrc->numTb;i++)
               {
                   SUB_BYTE_VAL(pSrc->u.ulTrchCommon.crci[i]);
               }
           }
           break;
      case FP_PCH_MSG:
           pSrc->u.pichInfo.len = subByteVal();
           for(i=0;i<pSrc->u.pichInfo.len;i++)
           {
               SUB_BYTE_VAL(pSrc->u.pichInfo.piBmp[i]);
           }
       break;
      default:
       break;
    }
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpHsDschDataHeaderDecHdlr(L1CAPI_FP_HSDSCH_DATA_Hdr *pSrc)
{
START_BLOCK_TRACE
    SUB_BYTE_VAL(pSrc->flags);
    SUB_BYTE_VAL(pSrc->cmChPi);
    SUB_WORD_VAL(pSrc->macDPduLen);
    SUB_BYTE_VAL(pSrc->numPdu);
    SUB_WORD_VAL(pSrc->usrBufSize);
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpEdchDataHeaderDecHdlr(L1CAPI_FP_EDCH_DATA_MSG_Hdr *pSrc)
{

   uint8_t i=0,j=0;
   START_BLOCK_TRACE
   	SUB_BYTE_VAL(pSrc->macDflowId);
       //SUB_BYTE_VAL(pSrc->payloadLen);
       SUB_BYTE_VAL(pSrc->numOfSubframes);
       for (i=0;i<pSrc->numOfSubframes;i++)
       {
        SUB_BYTE_VAL(pSrc->subFrameHeader[i].cfn);
	 
	 SUB_BYTE_VAL(pSrc->subFrameHeader[i].SubFrameNumber);
	 SUB_BYTE_VAL(pSrc->subFrameHeader[i].numOfHarqRetransmits);
	 SUB_BYTE_VAL(pSrc->subFrameHeader[i].numOfEsPDUs);
	 for(j=0;j<pSrc->subFrameHeader[i].numOfEsPDUs;j++)
	  {
	      SUB_BYTE_VAL(pSrc->subFrameHeader[i].DDI[j]);
	      SUB_BYTE_VAL(pSrc->subFrameHeader[i].N[j]);
	  }
       }
   END_BLOCK_TRACE	
    return 1;
 
}

static __inline__ uint8_t fpDataHeaderDecHdlr(L1CAPI_FP_DATA_MSG * pSrc,L1CAPI_MsgId_e msgId)
{
    uint8_t ret = 0;
START_BLOCK_TRACE    
    switch(msgId)
    {
      case FP_RACH_MSG:
      case FP_DCH_MSG:
      case FP_FACH_MSG:
      case FP_PCH_MSG:
           ret = fpR4DataHeaderDecHdlr(&pSrc->fpDatahdr.r4DataHdr,msgId);
           break;
      case FP_HSDSCH_MSG:
           ret = fpHsDschDataHeaderDecHdlr(&pSrc->fpDatahdr.hsDschDataHdr);
           break;
      case FP_EDCH_MSG:
           ret = fpEdchDataHeaderDecHdlr(&pSrc->fpDatahdr.edchDataHdr);
           break;
      default:
           break;
    }
END_BLOCK_TRACE
    return ret;
}

static __inline__ uint8_t fpErrorDecHdlr(L1CAPI_FP_ERROR_MSG * pSrc)
{
START_BLOCK_TRACE
	SUB_BYTE_VAL(pSrc->errorId); /*padding byte*/	
	SUB_WORD_VAL(pSrc->errorId);
END_BLOCK_TRACE
	return 1;
}

static __inline__ uint8_t fpR4OLPCReqDecHdlr(L1CAPI_OUTER_LOOP_PC_REQ * pSrc)
{
START_BLOCK_TRACE
    pSrc->ul_SIR_Target = subByteVal();
END_BLOCK_TRACE
    return 1;    
}

static __inline__ uint8_t fpHsCapReqDecHdlr(L1CAPI_HS_CAP_REQUEST * pSrc)
{
START_BLOCK_TRACE
    pSrc->cmChPi = subByteVal();
    pSrc->userBufSize = subWordVal();
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpHsCapAllocDecHdlr(L1CAPI_HS_CAP_ALLOCATION * pSrc)
{
START_BLOCK_TRACE
    SUB_BYTE_VAL(pSrc->allocType);
    SUB_BYTE_VAL(pSrc->macdFlowId);
    SUB_BYTE_VAL(pSrc->cmChPi);
    SUB_WORD_VAL(pSrc->macDPduLen);
    SUB_BYTE_VAL(pSrc->hsDschCredits);
    SUB_BYTE_VAL(pSrc->hsDschInterval);
    SUB_BYTE_VAL(pSrc->hsDschRepPeriod);

    SUB_BYTE_VAL(pSrc->resedualPduNumber);
    SUB_WORD_VAL(pSrc->genSfn);
    SUB_BYTE_VAL(pSrc->optimizedCredit);
END_BLOCK_TRACE
    return 1;
}

static __inline__ uint8_t fpCtrlDecHdlr(L1CAPI_FP_CTRL_MSG * pSrc)
{
    uint8_t ret = 0;
START_BLOCK_TRACE
    SUB_BYTE_VAL(pSrc->ctrlMsgType);
    switch(pSrc->ctrlMsgType)
    {
      case L1CAPI_MSGTYPE_R4_OLPC_REQ:
          ret = fpR4OLPCReqDecHdlr(&pSrc->u.r4OLPCReq);
          break;
      case L1CAPI_MSGTYPE_HS_CAP_REQ:
          ret = fpHsCapReqDecHdlr(&pSrc->u.hsCapReq);
          break;
      case L1CAPI_MSGTYPE_HS_CAP_ALLOC:
          PRINT_SPACE;
#ifdef L1C_TRACE_CONTENT
          PRINTF("FP: HSDSCH CAPABILITY ALLOCATION \n");
#endif
          ret = fpHsCapAllocDecHdlr(&pSrc->u.hsCapAlloc);
          break;
      break;
    }
END_BLOCK_TRACE
    return ret;
}

uint8_t fpDecHdlr(L1CAPI_FP_MSG * pSrc,L1CAPI_MsgId_e msgId)
{
    uint8_t ret = 0;
#ifdef L1C_TRACE_CONTENT
    switch(msgId)
    {
      case FP_RACH_MSG:
          PRINTF("L23<-- Frame Protocl Rach Message \n");
          break;
      case FP_DCH_MSG:
          PRINTF("L23<-- Frame Protocl Dch Message \n");
          break;
      case FP_HSDSCH_MSG:
          PRINTF("L23<-- Frame Protocl HSDSCH Message \n");
          break;
      case FP_EDCH_MSG:
          PRINTF("L23<-- Frame Protocl Edch Message \n");
          break;
      case FP_OLPC_MSG:
          PRINTF("L23<-- Frame Protocol Outer Loop Power Control Message \n");
          break;  
      default:
          PRINTF("L23<-- Unknown FP Message %d Receive \n",msgId);
          break;
    }
#endif
START_BLOCK_TRACE
    SUB_LONG_VAL(pSrc->bindingId);
    SUB_BYTE_VAL(pSrc->fp_msg_type);
    if(pSrc->fp_msg_type == L1CAPI_MSG_TYPE_FP_CTRL)
    {
      ret = fpCtrlDecHdlr(&pSrc->u.ctrl);
    }
    else if(pSrc->fp_msg_type == L1CAPI_MSG_TYPE_FP_DATA)
    {
      ret = fpDataHeaderDecHdlr(&pSrc->u.data, msgId);
    }
    else
    {
      ret = fpErrorDecHdlr(&pSrc->u.error);
    }		
END_BLOCK_TRACE
    return ret;
}
