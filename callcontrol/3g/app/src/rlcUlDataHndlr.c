/*############################################################################
 *
 *                   *** FXLynx Technologies Ltd. ***
 *
 *     The information contained in this file is the property of FXLynx
 *     Technologies Ltd. Except as specifically authorized in writing by
 *     FXLynx Technologies Ltd. The user of this file shall keep information
 *     contained herein confidential and shall protect same in whole or in
 *     part from disclosure and dissemination to third parties.
 *
 *     Without prior written consent of FXLynx Technologies Ltd. you may not
 *     reproduce, represent, or download through any means, the information 
 *     contained herein in any way or in any form.
 *
 *       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
 *
 *############################################################################*/
/*############################################################################
 * File Name	: rlcUlDataHndlr.c 
 *
 * Description  : This file handles UL data received in RLC layer
 *
 * History 	:
 *
 * Date		 Author 				 Details
 * ---------------------------------------------------------------------------
 * 29/10/2014	 Kuldeep S. Chauhan 	 File Creation
 *############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 *----------------------------------------------------- */
#include "stdio.h"
#include "cmnDs.h"
#include "macRlcInterface.h"
#include "rrc.h"
#include "taskHndlr.h"
#include "msgQue.h"
#include "cmnPf.h"
#include "rlcContext.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = rlc;

#define BIT_OFFSET_MASK(bitOffset) (((U8 *)0xFF) << (bitOffset))
#define BITS_IN_BYTE 8

void CreateRrcPdu(U8 *rlcPduBuf, U8 *rrcPduBuff, U16 pduSizeBits, U16 bitOffset)
{
    U8  bitMask    = 0x80;
    U16 byteOffset = bitOffset >> 3;
    U8  bitValue   = 0;
    U16 bitCount   = 0;
    U16 leftSrcBit = 0;

    bitOffset  = bitOffset - (byteOffset << 3);
    bitMask    = bitMask >> bitOffset;
    rlcPduBuf  = rlcPduBuf + byteOffset;

    DEBUG4(("RLC: ==== ENTRY ====CreateRrcPdu:  Copy Data to RRC PDU- pduSizeBits (%d), bitOffset(%d), bitMask(%x)\n", pduSizeBits, bitOffset, bitMask));
    for (bitCount = 0; bitCount < pduSizeBits; bitCount++)
    {
       if((*rlcPduBuf) & bitMask)
          bitValue = 1;
       else
          bitValue = 0;

       (*rrcPduBuff) |= bitValue << (7 - (bitCount % 8));

       bitMask = bitMask >> 1;
       if(0 == bitMask)
       {
          bitMask = 0x80; 
          rlcPduBuf++;
       }
       if(7 == (bitCount % 8))
       {
          rrcPduBuff++;
       }
    }
}

void rlcRachDataInd(RlcDataInd_t *rlcDataInd)
{
   U16            i = 0;
   U8            *rrcPdu = NULL;
   RrcDataReq    *pRlcDataInd = NULL;
   U16            dataOffset  = rlcDataInd->rlcDataInfo.dataOffset;
   U8            *dataBuff    = rlcDataInd->rlcDataInfo.pduBuf;
   U16            pduSizeByte = (rlcDataInd->rlcDataInfo.pduSize + 7)>> 3;

   DEBUG4(("RLC: == ENTRY ==  RlcRachDataInd "));
   DEBUG4(("==== RLC PDU\n"));
#if 0
   for(i = 0; i < pduSizeByte + 1; i++){
      printf(" %02x,",rlcDataInd->rlcDataInfo.pduBuf[i]);
      if((i%12 == 0) && (i > 0))
         printf("\n");
   }printf("\n");
#endif

   rrcPdu = (U8 *) malloc((pduSizeByte ) + 1);
   memset(rrcPdu, 0, (pduSizeByte ) + 1);

   CreateRrcPdu(rlcDataInd->rlcDataInfo.pduBuf, rrcPdu, rlcDataInd->rlcDataInfo.pduSize, rlcDataInd->rlcDataInfo.dataOffset); 
   DEBUG4(("RLC: ==== RRC PDU Buffer : pduSizeByte(%d) ======================================\n", pduSizeByte));
#if 0
   for(i = 0; i < pduSizeByte + 1; i++){
      printf(" %02x,",rrcPdu[i]);
      if((i%12 == 0) && (i > 0))
         printf("\n");
   }printf("\n");
#endif

   /* Fill RLC Data Indication */
   pRlcDataInd = (RrcDataReq *)malloc(sizeof(RrcDataReq));
   pRlcDataInd->cellOrUeId.choice      = RRC_CELL_ID;
   pRlcDataInd->cellOrUeId.u.cellId    = 0;
   pRlcDataInd->logicalChType          = LOG_CH_CCCH_E;
   pRlcDataInd->rrcPduLen              = ((rlcDataInd->rlcDataInfo.pduSize + 7) >> 3);
   pRlcDataInd->rrcPdu                 = rrcPdu;
   pRlcDataInd->propDelay              = rlcDataInd->propDelay;
    
   /* Post Message to APP RRC Task */
   SendMsgToTask (L2_UL_DATA_TASK_E, APP_RRC_TASK_E, L2_UL_CCCH_DATA_INDICATION_E, pRlcDataInd);

   free(rlcDataInd->rlcDataInfo.pduBuf); // Free the buffer holding MAC/RLC PDU
} /*End of rlcRachDataInd  */

ErrorCode_e rlcAmDchDataInd(RlcDataInd_t *rlcDataInd, U16 ueIdx)
{
   U16                i = 0;
   U16                bitOffset    = rlcDataInd->rlcDataInfo.dataOffset;
   U8                *dataBuff     = rlcDataInd->rlcDataInfo.pduBuf;
   RlcUlLogChInfo_t  *logChCntxt   = NULL;
   RlcDlLogChInfo_t  *logChDlCntxt = NULL;
   RxAmPduHdrInfo_t  *hdrInfo      = NULL;
   ErrorCode_e        retCode = SUCCESS_E;

   DEBUG4(("RLC: ==== rlcAmDchDataInd \n"));
   logChCntxt      = (RlcUlLogChInfo_t *) GetRlcLogChContext(ueIdx, DIR_UL_E, rlcDataInd->logChInfo.logChType, rlcDataInd->logChInfo.logChId);
   logChDlCntxt    = (RlcDlLogChInfo_t *) GetRlcLogChContext(ueIdx, DIR_DL_E, rlcDataInd->logChInfo.logChType, rlcDataInd->logChInfo.logChId);
   hdrInfo         = &logChCntxt->u.amCntxt.hdrInfo;
   memset(hdrInfo, 0, sizeof(RxAmPduHdrInfo_t));
   hdrInfo->pduLen = (rlcDataInd->rlcDataInfo.pduSize + 7)>> 3;

   retCode         = DecodeRlcAmHdr(ueIdx, hdrInfo, dataBuff, bitOffset);
   if(SUCCESS_E != retCode)
   {
      DEBUG1(("RLC: === ERROR ===Header Decode Failure\n")); 
      free(rlcDataInd->rlcDataInfo.pduBuf);
      return;
   }
   DEBUG4(("RLC: ==== Header Decoded Pdu sn(%d)BitOffset = %d, pduType (%d), pollBit(%d)\n", hdrInfo->sn, bitOffset, hdrInfo->pduType, hdrInfo->pollBit));
   switch(hdrInfo->dcFlag)
   {
      case RLC_AM_CTRL_PDU: 
         retCode = ProcRlcAmCtrlPdu( ueIdx, logChCntxt, &logChDlCntxt->u.amCntxt, rlcDataInd->logChInfo.logChId);
         break;
      case RLC_AM_DATA_PDU: 
         retCode = ProcRlcAmDataPdu( logChCntxt, dataBuff, bitOffset, ueIdx, rlcDataInd->logChInfo.logChId);
         break;
   }

   if(logChCntxt->u.amCntxt.amPollingStatus == TRUE_E) 
   {
      logChCntxt->u.amCntxt.amPollingStatus = FALSE_E;
      PopulateStatusPdu(ueIdx, rlcDataInd->logChInfo.logChId);
      DEBUG4(("Poll PDU Handling at rlcDchDataInd working remove it from RlcReassemblyUnit, remove this log\n"));
   }

   return;
} /*End of rlcAmDchDataInd*/

void rlcUmDchDataInd(RlcDataInd_t *rlcDataInd, U16 ueIdx)
{
   U16                i = 0;
   U16                bitOffset    = rlcDataInd->rlcDataInfo.dataOffset;
   U8                 *dataBuff     = rlcDataInd->rlcDataInfo.pduBuf;
   U16                pduSizeByte  = (rlcDataInd->rlcDataInfo.pduSize + 7)>> 3;
   RlcUlLogChInfo_t   *logChCntxt   = NULL;
   RxUmPduHdrInfo_t   *hdrInfo      = NULL;
   ErrorCode_e        retCode = SUCCESS_E;

   DEBUG4(("RLC: ==== rlcUmDchDataInd \n"));
   logChCntxt      = (RlcUlLogChInfo_t *) GetRlcLogChContext(ueIdx, DIR_UL_E, rlcDataInd->logChInfo.logChType, rlcDataInd->logChInfo.logChId);
   hdrInfo         = &logChCntxt->u.umCntxt.hdrInfo;
   memset(hdrInfo, 0, sizeof(RxUmPduHdrInfo_t));
   hdrInfo->pduLen = pduSizeByte;

   retCode         = DecodeRlcUmHdr(ueIdx, hdrInfo, dataBuff, bitOffset);
   if(SUCCESS_E != retCode)
   {
      DEBUG1(("RLC: === ERROR ===Header Decode Failure\n")); 
      free(rlcDataInd->rlcDataInfo.pduBuf);
      return;
   }
   DEBUG4(("RLC: ==== Header Decoded Pdu sn(%d)BitOffset = %d\n", hdrInfo->sn, bitOffset));
   retCode = ProcRlcUmDataPdu( logChCntxt, dataBuff, bitOffset, ueIdx, rlcDataInd->logChInfo.logChId);

   return;
} /*End of rlcUmDchDataInd*/

void rlcDchDataInd(RlcDataInd_t *rlcDataInd, U16 ueIdx)
{
   U16                i = 0;
   U16                pduSizeByte = (rlcDataInd->rlcDataInfo.pduSize + 7)>> 3;
   RlcUlLogChInfo_t  *rlcUlLogChCntxt = NULL;

   DEBUG4(("RLC: ==== rlcDchDataInd for ueIdx(%d) LogChId(%d), pduSizeByte(%d)\n", ueIdx, rlcDataInd->logChInfo.logChId, pduSizeByte));
   DEBUG4(("RLC: ==== RLC PDU: DCH ============================\n"));
#if 0
   for(i = 0; i < pduSizeByte + 1; i++){
      printf(" %02x,",rlcDataInd->rlcDataInfo.pduBuf[i]);
      if((i%12 == 0) && (i > 0))
         printf("\n");
   } printf("\n");
#endif

   if(rlcDataInd->logChInfo.logChType != LOG_CH_DCCH_E )
   {
      DEBUG4(("RLC: LogCHType(%d) not DCCH_E Received in DCH Data Ind. Drop PDU\n", rlcDataInd->logChInfo.logChType));
      free(rlcDataInd->rlcDataInfo.pduBuf); // Free the buffer holding MAC/RLC PDU
      return;
   }

   rlcUlLogChCntxt = (RlcUlLogChInfo_t *) GetRlcLogChContext(ueIdx, DIR_UL_E, rlcDataInd->logChInfo.logChType, rlcDataInd->logChInfo.logChId);

   // VALIDATIION
   switch(rlcUlLogChCntxt->rlcMode)
   {
      case RLC_MODE_AM_E:
         rlcAmDchDataInd(rlcDataInd, ueIdx);
         break;
      case RLC_MODE_UM_E:
         rlcUmDchDataInd(rlcDataInd, ueIdx);
         break;
      default:
         DEBUG2(("RLC: === ERROR === received RLC PDU for ueIdx(%d) in rlcMode(%d)\n", ueIdx, rlcUlLogChCntxt->rlcMode));
         free(rlcDataInd->rlcDataInfo.pduBuf); 
         break;
   }

   return ;
} /*End of rlcDchDataInd*/
