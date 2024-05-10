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
 * File Name	: rlcAmData.c
 *
 * Description  : This file has handling of Rlc UmMode handling. 
 *
 * History 	:
 *
 * Date		 Author 		 Details
 * ---------------------------------------------------------------------------
 * 01/12/2014	 Kuldeep S. Chauhan 	 File Creation
 *############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 *----------------------------------------------------- */
#include "stdio.h"
#include "cmnPf.h"
#include "cmnDs.h"
#include "l2Cmn.h"
#include "rlcContext.h"
#include "errorCode.h"
#include "string.h"
#include "rrc.h"
#include "cmnDebug.h"


static DbgModule_e  DBG_MODULE = rlc;

#define MASK_N_BIT_MSB_SIDE(n)                 (~(((U8)0xff) >> n))
#define MASK_N_BIT_LSB_SIDE(n)                 (((U8)0xff) << n) 
// offset 0 => start with MSB, offset = 7 Start with last bit 
#define MASK_LSB_N_BIT_SET(n)                  (~(~0 << n))
#define MASK_MSB_N_BIT_SET(n)                  (~((U8)(~0) >> n))
#define GET_N_BIT_FROM_OFFSET(Byte, n, pos)             ((Byte >> (8 - n - pos)) & MASK_LSB_N_BIT_SET(n))
#define SET_VALUE_AT_N_BIT_FROM_OFFSET(Byte, n, pos)    ((Byte & (U8)MASK_MSB_N_BIT_SET(n)) >> (pos))

// Get N Bits from Data, starting from BitPos = bitOffset
U16 GetNBits(U8 *data, U16 numBits, U16 bitOffset)
{
   U16   byteOffset = bitOffset >> 3;
   U16   getBitNum     = 0;
   U16   result = 0;

   bitOffset  = bitOffset - (byteOffset << 3);
   while(numBits > 0)
   {
      //In One iteration get bits present in one Nth Byte of Data
      getBitNum   = (numBits <= (8-bitOffset)) ? numBits : (8-bitOffset); 
      result      = (result  << getBitNum) | (GET_N_BIT_FROM_OFFSET(data[byteOffset], getBitNum, bitOffset));
      numBits    -= getBitNum;
      bitOffset   = 0;
      byteOffset++;
   }while(numBits > 0)

   DEBUG4(("Hdr Decode GetNBit result(%x)\n", result));
   return result;
}

// Put N Bits In data, starting from BitPos = bitOffset
// This is only for numBits <= 8
U16 PutNBits(U8 *data, U16 numBits, U16 bitOffset, U16 value)
{
   U16   byteOffset  = bitOffset >> 3;
   U16   fillBitNum  = 0;
   U8    srcByte = 0;
   U16   result      = 0;

   bitOffset  = bitOffset - (byteOffset << 3); // Byte offset removed
   //DEBUG4(("In value(%x),numBits(%d), ByteOffset(%d), bitOffset(%d)\n", value, numBits, byteOffset, bitOffset));
   value  = value << (16 - numBits ); // Assuming value is 16 bit.
   //DEBUG4(("value1(%x)\n", value));

   while(numBits > 0)
   {
         fillBitNum           = (numBits <= (8-bitOffset)) ? numBits : (8-bitOffset);
         srcByte              = (unsigned char) ((value >> 8) & 0xff);
         data[byteOffset]    |= SET_VALUE_AT_N_BIT_FROM_OFFSET(srcByte, fillBitNum, bitOffset);
         numBits             -= fillBitNum;
         value                = value << fillBitNum;
         //DEBUG4(("PutNBits value(%x),  data[byteOffset](%x)\n", value, data[byteOffset]));
         bitOffset   = 0;
         byteOffset++;
   }

   //DEBUG4(("PDU Encode GetNBit IN- numBit(%d), value(%d), offset(%d), result(%x)\n", numBits, value, bitOffset, result));
   return result;
}

ErrorCode_e DecodeRlcAmDHdr(RxAmPduHdrInfo_t *hdrInfo, U8 *dataBuff, U16 bitOffset)
{
   // SN Field => 12 Bit
   hdrInfo->sn                = GetNBits(dataBuff, 12, bitOffset + hdrInfo->hdrLen);
   hdrInfo->hdrLen +=12;
   DEBUG4((" Decoding Rlc Am Pdu with sn (%d)\n", hdrInfo->sn));
   // P(Poll Bit) Field => 1 Bit
   hdrInfo->pollBit           = GetNBits(dataBuff, 1, bitOffset + hdrInfo->hdrLen);;
   hdrInfo->hdrLen +=1;
   // HE Field => 2 Bit
   hdrInfo->he                = GetNBits(dataBuff, 2, bitOffset + hdrInfo->hdrLen);;
   hdrInfo->hdrLen +=2;
   if((hdrInfo->he != 0) && (hdrInfo->he != 1)){
      DEBUG1(("Header extention Invalid\n"));
      return ERROR_RLC_HDR_DECODE_FAIL_E;
   }
   // HE is used for HE as well as E field following Li in RLC PDU
   while(hdrInfo->he == 1)
   {
      hdrInfo->numLi++;
      hdrInfo->Li[hdrInfo->numLi -1] = GetNBits(dataBuff, 7, bitOffset + hdrInfo->hdrLen);
      hdrInfo->hdrLen +=7;
      hdrInfo->he                    = GetNBits(dataBuff, 1, bitOffset + hdrInfo->hdrLen);
      hdrInfo->hdrLen +=1;
      DEBUG4(("Li number(%d) , LiValue(%d) hdrLen(%d)\n", hdrInfo->numLi, hdrInfo->Li[hdrInfo->numLi -1], hdrInfo->hdrLen));
   }

   return SUCCESS_E;
}

ErrorCode_e DecodeRlcAmCtrlPduHdr(U16 ueIdx, RxAmPduHdrInfo_t *hdrInfo, U8 *dataBuff, U16 bitOffset)
{
   ErrorCode_e retCode = SUCCESS_E;
   U16         sufiIdx = 0, i = 0;
   S16         lastSufiDone = FALSE_E;
   U32         *rrcUeIdx = NULL;


   DEBUG3(("Decode RLC AM CTRL PDU \n"));
   hdrInfo->pduType           = GetNBits(dataBuff, 3, bitOffset + hdrInfo->hdrLen);
   hdrInfo->hdrLen +=3;
   hdrInfo->statusPdu.numSufi = 0;
   DEBUG3(("pduType(%d)\n", hdrInfo->pduType));

   switch(hdrInfo->pduType)
   {
      case PDU_TYPE_STATUS_E:
         while(lastSufiDone != TRUE_E && (hdrInfo->statusPdu.numSufi < MAX_SUFI_NUM_IN_STATUS_PDU/*5*/))
         {
            hdrInfo->statusPdu.sufiInfo[sufiIdx].sufiType = GetNBits(dataBuff, 4, bitOffset + hdrInfo->hdrLen);
            hdrInfo->hdrLen +=4;
            hdrInfo->statusPdu.numSufi++;
            DEBUG4(("numSufi(%d)\t", hdrInfo->statusPdu.numSufi));
            switch(hdrInfo->statusPdu.sufiInfo[sufiIdx].sufiType)
            {
               case SUFI_NO_MORE_E:
                  lastSufiDone = TRUE_E;
                  DEBUG4(("SUFI_NO_MORE_E,\n"));
                  break;
               case SUFI_ACK_E:
                  hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.ackSufi.lsn = GetNBits(dataBuff, 12, bitOffset + hdrInfo->hdrLen);
                  hdrInfo->hdrLen +=12;
                  lastSufiDone = TRUE_E;
                  DEBUG4(("SUFI_ACK_E, lsn(%d)\n", hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.ackSufi.lsn));
                  break;
               case  SUFI_WINDOW_E:
                  hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.windowSufi.wsn = GetNBits(dataBuff, 12, bitOffset + hdrInfo->hdrLen);
                  hdrInfo->hdrLen +=12;
                  DEBUG4(("SUFI_WINDOW_E, wsn (%d)\n", hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.windowSufi.wsn));
                  break;
               case  SUFI_LIST_E:
                  DEBUG4(("SUFI_LIST_E,\n"));
                  hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.lstSufi.length = GetNBits(dataBuff, 4, bitOffset + hdrInfo->hdrLen);
                  hdrInfo->hdrLen +=4;
                  for(i = 0; i < hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.lstSufi.length; i++) {
                     hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.lstSufi.SN[i] = GetNBits(dataBuff, 12, bitOffset + hdrInfo->hdrLen);
                     hdrInfo->hdrLen +=12;
                     hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.lstSufi.LI[i] = GetNBits(dataBuff, 4, bitOffset + hdrInfo->hdrLen);
                     hdrInfo->hdrLen +=4;
                  }
                  break;
               case  SUFI_BITMAP_E:
                  DEBUG4(("SUFI_BITMAP_E,\n"));
                  hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.bitMapSufi.length = GetNBits(dataBuff, 4, bitOffset + hdrInfo->hdrLen);
                  hdrInfo->hdrLen +=4;
                  hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.bitMapSufi.FSN    = GetNBits(dataBuff, 12, bitOffset + hdrInfo->hdrLen);
                  hdrInfo->hdrLen +=12;
                  for(i = 0; i < hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.bitMapSufi.length; i++){
                     hdrInfo->statusPdu.sufiInfo[sufiIdx].sufi.bitMapSufi.Bitmap[i] = GetNBits(dataBuff, 8, bitOffset + hdrInfo->hdrLen);
                     hdrInfo->hdrLen +=8;
                  }
                  break;
               case  SUFI_RLIST_E:
                  DEBUG4(("== ERROR: SUFI_RLIST_E Not handled ===============\n"));
                  lastSufiDone = TRUE_E; // Stop Decoding Status msg. As we are not decoding this these bits will spill to next sufi
                  break;
               case  SUFI_MRW_E:
                  DEBUG4(("== ERROR:SUFI_MRW_E Not handled ===============\n"));
                  lastSufiDone = TRUE_E; // Stop Decoding Status msg. As we are not decoding this these bits will spill to next sufi
                  break;
               case  SUFI_MRW_ACK_E:
                  DEBUG4(("== ERROR:SUFI_MRW_ACK_E Not handled ===============\n"));
                  lastSufiDone = TRUE_E; // Stop Decoding Status msg. As we are not decoding this these bits will spill to next sufi
                  break;
               default:
                  DEBUG2(("== ERROR: Invalid Sufi (default) Not handled ===============\n"));
                  lastSufiDone = TRUE_E; // Stop Decoding Status msg. As we are not decoding this these bits will spill to next sufi
                  break;
            }
         }
         break;
      case PDU_TYPE_RESET_E:
         DEBUG3(("CTRL PDU RESET Received, Trigger Call Release\n"));
         retCode = ERROR_RLC_HDR_DECODE_FAIL_E;
         break;
      case PDU_TYPE_RESET_ACK_E:
         DEBUG3(("CTRL PDU RESET ACK Received, Trigger Call Release\n"));
         retCode = ERROR_RLC_HDR_DECODE_FAIL_E;
         break;
      default:
         DEBUG2(("Error: Invalid Ctrl PDU, Trigger Call Release \n"));
         retCode = ERROR_RLC_HDR_DECODE_FAIL_E;
         break;
   }

   if(retCode == ERROR_RLC_HDR_DECODE_FAIL_E)
   {
      rrcUeIdx   = (unsigned int *)malloc (sizeof(unsigned int));
      *rrcUeIdx  = ueIdx - 1; //ueIdx in L2 = ueIdx in RRC + 1

      SendMsgToTask (L2_UL_DATA_TASK_E, APP_RRC_TASK_E, L2_RLC_ERROR_CALL_RLS_E, rrcUeIdx);
      //SendMsgToTask (L2_UL_DATA_TASK_E, APP_RRC_TASK_E, L2_RLC_ERROR_CALL_RLS_E, NULL);
   }

   return retCode;
}

ErrorCode_e DecodeRlcAmHdr(U16 ueIdx, RxAmPduHdrInfo_t *hdrInfo, U8 *dataBuff, U16 bitOffset)
{
   ErrorCode_e      retCode = SUCCESS_E;
   //memset(hdrInfo, 0, sizeof(RxAmPduHdrInfo_t));  --> Some of the vales filled before function call

   DEBUG4(("DecodeRlcAmHdr: databuff[0] = (%02x), bitOffset(%d) hdrLen(%d)\n", dataBuff[0], bitOffset, hdrInfo->hdrLen));
   // D/C Field => 1 Bit
   hdrInfo->dcFlag            = GetNBits(dataBuff, 1, bitOffset + hdrInfo->hdrLen) == 1 ? RLC_AM_DATA_PDU : RLC_AM_CTRL_PDU;
   hdrInfo->hdrLen +=1;
   switch(hdrInfo->dcFlag)
   {
      case RLC_AM_CTRL_PDU:
         retCode = DecodeRlcAmCtrlPduHdr(ueIdx, hdrInfo, dataBuff, bitOffset);
         break;
      case RLC_AM_DATA_PDU:
         retCode = DecodeRlcAmDHdr(hdrInfo, dataBuff, bitOffset);
         break;
   }
   return retCode;
} /*End of DecodeRlcAmHdr*/

ErrorCode_e ProcRlcAmCtrlPdu(U32 ueIdx, RlcUlLogChInfo_t  *logChCntxt, LchDlAmCntxt_t *logChDlCntxt, U16 logChIdx)
{
   U16       i  = 0, j = 0, k = 0;
   U32       sn = 0;
   U32       li = 0;
   LogChId_t logChId;
   SduInfo_t *curSdu = NULL;
   U32       sduIdx = 0;
   RxAmPduHdrInfo_t *hdrInfo = &logChCntxt->u.amCntxt.hdrInfo;
   ErrorCode_e      retCode = SUCCESS_E;

   DEBUG4(("======= RLC: Process UL RLC_AM Pdu ==========\n"));
   for(i = 0; i < hdrInfo->statusPdu.numSufi; i++)
   {
      switch(hdrInfo->statusPdu.sufiInfo[i].sufiType)
      {
      case SUFI_ACK_E:
         DEBUG4(("Process Ack Sufi, vt_A(%d),lsn(%d)\n", logChDlCntxt->amSv.vt_A, hdrInfo->statusPdu.sufiInfo[i].sufi.ackSufi.lsn));
         // It is possible that Ack sufi came with list sufi. In that case Vt_A cant be moved to lsn
         while(logChDlCntxt->amSv.vt_A < hdrInfo->statusPdu.sufiInfo[i].sufi.ackSufi.lsn
                && logChDlCntxt->reTxQ[logChDlCntxt->amSv.vt_A].inUse == TRUE_E)
         {
            if(logChDlCntxt->reTxQ[logChDlCntxt->amSv.vt_A].reTxStatus != TRUE_E) // set to true on NACK
            {
               // Free SDU memory if PDU has last SDU.
               for(i=0; i < logChDlCntxt->reTxQ[logChDlCntxt->amSv.vt_A].amPduHdrInfo.numSduSeg ; i++)
               {
                  sduIdx = logChDlCntxt->reTxQ[logChDlCntxt->amSv.vt_A].amPduHdrInfo.sduDataSeg[i].sduIdx;
                  curSdu = &logChDlCntxt->sduQCntxt.sduInfo[sduIdx];
                  DEBUG4((" Release SDU segment sduIdx(%d), numUsr(%d)\n",sduIdx, logChDlCntxt->sduQCntxt.sduInfo[sduIdx].numUsr));
                  logChDlCntxt->sduQCntxt.sduInfo[sduIdx].numUsr--;
                  if(logChDlCntxt->sduQCntxt.sduInfo[sduIdx].numUsr == 0)
                  {
                     // Free SDU
                     free(curSdu->buf);
                     logChDlCntxt->sduQCntxt.numSdu--;
                     logChDlCntxt->sduQCntxt.sduInfo[curSdu->prevSduIdx].nxtSduIdx = curSdu->nxtSduIdx;
                     logChDlCntxt->sduQCntxt.sduInfo[curSdu->nxtSduIdx].prevSduIdx = curSdu->prevSduIdx;
                     memset(curSdu, 0, sizeof(SduInfo_t));
                     DEBUG4(("All segemnt of sduIdx (%d) acked Release Sdu. numSdu After Release\n",sduIdx, logChDlCntxt->sduQCntxt.numSdu));
                  }
               }
               // Free ReTxPdu and update Vt_A
               memset(&logChDlCntxt->reTxQ[logChDlCntxt->amSv.vt_A], 0, sizeof(TxAmPduInfo_t));
               logChDlCntxt->amSv.vt_A++;
               DEBUG4(("Update Vt_A newVal(%d),\n", logChDlCntxt->amSv.vt_A));
            }
            else{
               //Retx = TRUE => Nack received, stop no need move VtA 
               break;
            }
         }
         break;
      case SUFI_NO_MORE_E: 
         break;
      case SUFI_WINDOW_E:
         DEBUG4(("RLC_AM SufiType, Not changing Window size for Window SUFI\n"));
         break;
      case SUFI_LIST_E:
         DEBUG4(("RLC_AM SufiList\n"));
         for(j = 0; j < hdrInfo->statusPdu.sufiInfo[i].sufi.lstSufi.length; j++) {
            sn = hdrInfo->statusPdu.sufiInfo[i].sufi.lstSufi.SN[j];
            li = hdrInfo->statusPdu.sufiInfo[i].sufi.lstSufi.LI[j];
            for(k = 0; k < li; k++){
               logChDlCntxt->reTxQ[sn + k].reTxStatus  = TRUE_E;
               logChDlCntxt->reTxQ[sn + k].vt_Dat++;
               if(logChDlCntxt->reTxQ[sn + k].vt_Dat  >= RLC_AM_MAX_NUM_RETX)
               {
                  DEBUG3((" MAX RLC RETRANSMISSION Trigger release\n"));
                  // TBD: need to trigger call release by indicating Release of maxReset to RRC
               }
               logChId.logChType                       = LOG_CH_DCCH_E;
               logChId.logChId                         = logChIdx;
               logChId.idType                          = ID_TYPE_UE_IDX_E;
               logChId.ueCellId.ueIdx                  = ueIdx;
               logChDlCntxt->boReTxData               += logChDlCntxt->reTxQ[sn].pduLen;
               UpdateMacBo(logChId, logChDlCntxt->boReTxData, TRUE_E/*INC*/);      
            }
         }
         break;
      case SUFI_BITMAP_E:
      case SUFI_RLIST_E:
      case SUFI_MRW_E:
      case SUFI_MRW_ACK_E:
      default:
         retCode = ERROR_RLC_AMD_RX_PDU_PROC_FAIL_E;
         DEBUG4((" RLC_AM SufiType(%d) not handled\n", hdrInfo->statusPdu.sufiInfo[i].sufiType));
         break;
      }
      if(hdrInfo->statusPdu.sufiInfo[i].sufiType == SUFI_NO_MORE_E
         || hdrInfo->statusPdu.sufiInfo[i].sufiType == SUFI_ACK_E)
      {
         break;
      }
   }
   
   return retCode;
} /*End of ProcRlcAmCtrlPdu*/


/************************************************************************
 *
 *  THIS FUNCTION REASSAMBLES SINGLE SDU AND SENDS IT TO RRC
 *
 * **********************************************************************/
ErrorCode_e ReassabmleSndSdu(LchUlAmCntxt_t *amCntxt, U16 ueIdx, U16 sn)
{
   U16               i = 0, j = 0;
   U16               sduIdx        = 0;
   AmRlcRxSv_t      *amSv          = &amCntxt->amSv;
   RxAmPduInfo_t    *roQPduCntxt   = NULL;
   RrcDataReq       *pRrcDataInd   = NULL;
   RxAmSduDataSeg_t *pSduSeg       = NULL;

   DEBUG4(("ReassabmleSndSdu ueIdx(%d), sn(%d)\n", ueIdx, sn));

   for(i = amSv->vr_R; i <= sn; i++)
   {
      roQPduCntxt  = &amCntxt->RxRoQueue[i];
      DEBUG4(("Reassabmle sn(%d), numSeg(%d)\n", i, roQPduCntxt->numSeg));
      if(roQPduCntxt->inUse != TRUE){
         DEBUG4(("ERROR_RLC_AMD_SDU_ASSMBLY_FAIL_E\n"));
         return ERROR_RLC_AMD_SDU_ASSMBLY_FAIL_E;
      }
      if(pRrcDataInd == NULL)
      {
         DEBUG4(("pRrcDataInd = NULL\n"));
         /* Fill RLC Data Indication */
         pRrcDataInd = (RrcDataReq *)malloc(sizeof(RrcDataReq));
         pRrcDataInd->cellOrUeId.choice     = RRC_UE_ID;
         pRrcDataInd->cellOrUeId.u.ueId     = ueIdx - 1;  // As RRC ueIdx starting from 0, and L2 from 1
         pRrcDataInd->logicalChType         = LOG_CH_DCCH_E;
         pRrcDataInd->rrcPduLen             = 0;
         // TBD: Currently allocating RRC PDU to Fixed MAX size of 200.
         // Later on need to allocate exact memory needed for RRC PDU buffer
         pRrcDataInd->rrcPdu = (U8 *) malloc( MAX_UL_RRC_MSG_BYTE_SIZE*sizeof(U8));
      }
      // Start with Seg Index which is not processed previously
      for(sduIdx = roQPduCntxt->nxtValidSegIdx; sduIdx < roQPduCntxt->numSeg; sduIdx++)
      {
         pSduSeg = &roQPduCntxt->segDataInfo[sduIdx];
         if(roQPduCntxt->pduBitOffset == 0) // Byte Aligned RLC Data, can use memcpy 
         {
            memcpy( &pRrcDataInd->rrcPdu[pRrcDataInd->rrcPduLen], &roQPduCntxt->rlcPduBuf[pSduSeg->bitOffset >>  3], pSduSeg->len);
            pRrcDataInd->rrcPduLen += pSduSeg->len; // As Len was filled by Li value it is in Bytes
            DEBUG4(("Sdu Seg segIdx(%d) Added New pduLen(%d), sduSegLen(%d), bitOffset(%d)\n", 
                                       sduIdx, pRrcDataInd->rrcPduLen, pSduSeg->len, pSduSeg->bitOffset));
            if(pSduSeg->isLastSeg == TRUE_E)
            {
               DEBUG4(("Send SDU to RRC at pdu sn(%d) . RRC DCCH PDU of pduLen(%d)\n", sn, pRrcDataInd->rrcPduLen));
#if 0
               for(j = 0; j < pRrcDataInd->rrcPduLen; j++){
                  printf(" %02x,", pRrcDataInd->rrcPdu[j]);
                  if((j%12 == 0) && (j > 0))
                    printf("\n");
               } printf("\n");
#endif

               // SEND SDU To RRC, And Cleanup Mem, Reset pRrcDataInd to NULL 
               /* Post Message to APP RRC Task */
               SendMsgToTask (L2_UL_DATA_TASK_E, APP_RRC_TASK_E, L2_UL_DCCH_DATA_INDICATION_E, pRrcDataInd);
               // RRC Data Indication info already sent to RRC. 
               // Make pointer ready for next SDU(=NULL) without releasing memory
               pRrcDataInd = NULL;
               roQPduCntxt->nxtValidSegIdx = sduIdx + 1;
               roQPduCntxt->numLastSduSeg--;

               if(sduIdx == roQPduCntxt->numSeg -1)
               { //This is last SDU segment, set Vr_R to next PDU
                  amSv->vr_R  = sn + 1;
                  amSv->vr_Mr = amSv->vr_R + RLC_AM_WINDOW_SIZE;
                  DEBUG4(("AM StateVar update vr_R(%d), vr_Mr(%d) sduIdx(%d), numSeg(%d)\n", 
                                                      amSv->vr_R, amSv->vr_Mr, sduIdx, roQPduCntxt->numSeg));
               }
               else{ // one or more SDU segments still pending in PDU for Processing
                  amSv->vr_R  = sn; // a Segment of this PDU need to be assembled next time
                  amSv->vr_Mr = amSv->vr_R + RLC_AM_WINDOW_SIZE;
                  DEBUG4(("Sdu Seg Pending in PDU. AM StateVar update vr_R(%d), vr_Mr(%d) sduIdx(%d), numSeg(%d)\n", 
                                                      amSv->vr_R, amSv->vr_Mr, sduIdx, roQPduCntxt->numSeg));
                  // Sdu Segment Pending Dont Free PDU
                  return SUCCESS_E;
               }
            }
         }
         else
         {
            // TBD: Copy Data Bit by Bit
            DEBUG4(("ERROR ===BitOffset of RLC PDU !=0, but from MAC it was sent with bitOffset = 0\n"));
            free(pRrcDataInd->rrcPdu);
            free(pRrcDataInd);
            free(roQPduCntxt->rlcPduBuf);
            memset(roQPduCntxt, 0, sizeof(RxAmPduInfo_t) );
            return ERROR_RLC_AMD_SDU_ASSMBLY_FAIL_E;
         }
      }

      // RO_Pdu processing Done free PDU
      free(roQPduCntxt->rlcPduBuf);
      memset(roQPduCntxt, 0, sizeof(RxAmPduInfo_t) );
   }

   return SUCCESS_E;
}

ErrorCode_e PopulateStatusPdu(U16 ueIdx, U16 logChIdx)
{
   U32 sn = 0; // for ack sufi finding. As Vr_R is not updated on receiving PDU but only when re-assembled
   RlcUlLogChInfo_t  *pUlLogChCntxt;
   RlcDlLogChInfo_t  *pDlLogChCntxt;
   AmRlcRxSv_t       *amSV;
   DlStatusPduInfo_t *statusPduInfo;
   LogChId_t         logChId;
   U16               nackSnUpdatedFlag = FALSE_E;

   DEBUG4(("ENTRY == PopulateStatusPdu for ueIdx(%d), logChIdx(%d)\n", ueIdx, logChIdx));
   pUlLogChCntxt  = (RlcUlLogChInfo_t *) GetRlcLogChContext(ueIdx, DIR_UL_E, LOG_CH_DCCH_E, logChIdx);
   pDlLogChCntxt  = (RlcDlLogChInfo_t *) GetRlcLogChContext(ueIdx, DIR_DL_E, LOG_CH_DCCH_E, logChIdx);
   amSV           = &pUlLogChCntxt->u.amCntxt.amSv;
   statusPduInfo  = &pDlLogChCntxt->u.amCntxt.statusPduInfo;
   statusPduInfo->dcField            = RLC_AM_CTRL_PDU;   // 1 Bit
   statusPduInfo->pduType            = PDU_TYPE_STATUS_E; // 3 Bit 
   statusPduInfo->listSufiLength     = 0;

   for(sn = amSV->vr_R; sn <= amSV->vr_H; sn++)
   {
      DEBUG4(("Get correct lsn for ack sufi, sn(%d), inUse(%d)\n", sn, pDlLogChCntxt->u.amCntxt.reTxQ[sn].inUse));
      if(pUlLogChCntxt->u.amCntxt.RxRoQueue[sn].inUse != TRUE_E)
      {
         break;
      }
   }
   
   // In all cases AckLsn = vrH, if any Pdu is missing add that info in List Sufi
   // Pdu len should be good enough for all PDUs ack/nack, In all practical scenarios Vr_H - Vr_R should be <=5
   statusPduInfo->ackSufiInfo.lsn   = amSV->vr_H;        // 12 Bit
   DEBUG4(("Populate Ack Sufi with lsn (%d)\n, sn, vr_H(%d)", statusPduInfo->ackSufiInfo.lsn,
                                                                        sn, amSV->vr_H));
   if(sn != amSV->vr_H)
   {
      DEBUG4(("Populate List Sufi for NACK reporting\n"));
      while(sn < amSV->vr_H)
      {
         DEBUG4(("listSufiLength(%d), nackSnUpdatedFlag(%d)\n", statusPduInfo->listSufiLength, nackSnUpdatedFlag));
         if(pUlLogChCntxt->u.amCntxt.RxRoQueue[sn].inUse != TRUE_E){
            if(nackSnUpdatedFlag == FALSE_E){
               nackSnUpdatedFlag  = TRUE_E;
               statusPduInfo->listSufiLength++;
               statusPduInfo->listSufiInfo.SN[statusPduInfo->listSufiLength-1] = sn;
            }
            statusPduInfo->listSufiInfo.LI[statusPduInfo->listSufiLength-1]++;
         }else{
            nackSnUpdatedFlag  = FALSE_E;
         }
         sn++;
      }
   }

   pDlLogChCntxt->u.amCntxt.boCtrl   = RLC_AM_ACK_SUFI_SIZE_BYTE; //3Byte
   logChId.logChType                 = LOG_CH_DCCH_E;
   logChId.logChId                   = logChIdx;
   logChId.idType                    = ID_TYPE_UE_IDX_E;
   logChId.ueCellId.ueIdx            = ueIdx;

   // If Already Ctrl Pdu Bo Updated. Only update status msg to latest status or ReOrderingQ. Bo already updated 
   if(pDlLogChCntxt->u.amCntxt.statusPduFlag != TRUE_E)
   {
      // Multiply by 2 in Bo size, just to send Status PDU twice
      UpdateMacBo(logChId, RLC_AM_ACK_SUFI_SIZE_BYTE, TRUE_E/*INC*/);
      pDlLogChCntxt->u.amCntxt.statusPduFlag = TRUE_E;
   }

   return SUCCESS_E;
}

ErrorCode_e RlcReassemblyUnit(LchUlAmCntxt_t *amCntxt, U16 ueIdx,  U16 logChId)
{
   U16              sn = 0;
   AmRlcRxSv_t      *amSv          = &amCntxt->amSv;
   RxAmPduInfo_t    *roQPduCntxt   = NULL;
   ErrorCode_e      retCode       = SUCCESS_E;

   DEBUG4(("RlcReassemblyUnit ueIdx(%d) \n", ueIdx)); 
   for( sn = amSv->vr_R; (sn <= amSv->vr_H); sn++)
   {
      DEBUG4((" Pdu Sn(%d).Last SDU seg in PDU pres Flag(%d)\n", sn, amCntxt->RxRoQueue[sn].numLastSduSeg));
      if(amCntxt->RxRoQueue[sn].inUse == TRUE_E)
      {
         if(amCntxt->RxRoQueue[sn].numLastSduSeg >= 1)
         {
            // This Assembles only one SDU at a Time
            // TBD: Test And Varify the scenario when more than one SDU end in same PDU
            ReassabmleSndSdu(amCntxt, ueIdx, sn);
         }
      }
      else{
         DEBUG4(("Nothing more to assamble\n"));
         break; // Missing PDU break from loop
      }
   }
#if 1
   // TBD: Remove it once ack status in rlcDchDataInd after pduProc working
   // Reassembly is only called if sn falls in reassembly window, but poll bit responce(status msg) need to be send in other case also.
   if(amCntxt->amPollingStatus == TRUE_E) {
      amCntxt->amPollingStatus = FALSE_E;
      PopulateStatusPdu(ueIdx, logChId);
   }
#endif
   return retCode;
}

ErrorCode_e ProcRlcAmDataPdu( RlcUlLogChInfo_t  *logChCntxt, U8 *dataBuff, U16 bitOffset, U16 ueIdx, U16 logChId)
{
   U16               sduIdx      = 0;
   AmRlcRxSv_t      *amSV        = &logChCntxt->u.amCntxt.amSv;
   RxAmPduHdrInfo_t *hdrInfo     = &logChCntxt->u.amCntxt.hdrInfo;
   RxAmPduInfo_t    *roQPduCntxt = &logChCntxt->u.amCntxt.RxRoQueue[hdrInfo->sn];
   ErrorCode_e       retCode     = SUCCESS_E;
   U16               padStatusFlag = FALSE_E;

   DEBUG4(("ProcRlcAmDataPdu: Pollong bit(%d) . Send Ctrl PDU sn(%d),  vr_R(%d)==\n", hdrInfo->pollBit, hdrInfo->sn, amSV->vr_R));
   if(hdrInfo->pollBit == TRUE_E)
   {
      logChCntxt->u.amCntxt.amPollingStatus = TRUE_E;
   }
   if( (RLC_RX_AM_SN_IN_WINDOW(hdrInfo->sn, amSV->vr_R, amSV->vr_Mr) != TRUE_E) 
     ||(roQPduCntxt->inUse == TRUE_E))
   {
      DEBUG4(("PDU OUTSIDE WINDOW or Duplicate PDU.sn(%d),vr_R(%d), vr_Mr(%d)\n", hdrInfo->sn, amSV->vr_R, amSV->vr_Mr));
      free(dataBuff);
      return ERROR_RLC_AMD_RX_PDU_PROC_FAIL_E;
   }
   if(roQPduCntxt->inUse != TRUE_E)
   {
      DEBUG4(("Initialize PDU Context\n"));
      roQPduCntxt->inUse        = TRUE_E;
      roQPduCntxt->rlcPduBuf    = dataBuff;
      roQPduCntxt->pduBitOffset = bitOffset;
      roQPduCntxt->pduLen       = hdrInfo->pduLen;
      roQPduCntxt->sn           = hdrInfo->sn;
   }

   bitOffset = hdrInfo->hdrLen;
   // Go through all SDU segments and add all sdu segments in RxPdu 
   while((sduIdx < hdrInfo->numLi) && (hdrInfo->numLi!= 0/*TBD: Workaround as both are U16(invalid condn for 0), add proper logic*/ ))
   {
      DEBUG4(("Process LiValue(%d) \n",hdrInfo->Li[sduIdx]));
      switch(hdrInfo->Li[sduIdx])
      {
         // TBD: Used MACRO for case values with Hex format, not binary
         case RLC_PREV_PDU_END_WITH_SDU:
             DEBUG4(("RLC_PREV_PDU_END_WITH_SDU i.e liValue(0)\n"));
             // accessing with value numSeg -1, for 1st SduSeg numSeg =1 but index is 0
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len           = 0;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset     = 0;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg     = TRUE_E;
             roQPduCntxt->numLastSduSeg++;
             // Last PDU Ended With SDU
             roQPduCntxt->numSeg++;
             break;
         case RLC_INVALID_AM_PDU_1:
         case RLC_INVALID_AM_PDU_2:
             // DISCARD PDU : Invalid LI
             DEBUG4(("AMPDU Unhandled LI\n" ));
             break;
         case RLC_AM_STATUS_PDU:
             // Piggiback Status PDU
             DEBUG4(("RLC: ==== PiggyBack Status PDU, Currently no handling Drop Pdu \n"));
             padStatusFlag = TRUE_E;
             break;
         case RLC_PDU_PADDING:
             DEBUG4(("Padding\n"));
             padStatusFlag = TRUE_E;
             break;
         default:
             // - AddSduSegInRoPdu
             // accessing with value numSeg -1, for 1st SduSeg numSeg =1 but index is 0
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len        = hdrInfo->Li[sduIdx];
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset  = bitOffset;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg  = TRUE_E;
             roQPduCntxt->numLastSduSeg++;
             roQPduCntxt->numSeg++;
             DEBUG4(("Last SDU Segment. numSeg(%d)n len(%d), bitOffset(%d)\n", roQPduCntxt->numSeg, hdrInfo->Li[sduIdx], bitOffset));
             bitOffset  += (hdrInfo->Li[sduIdx]*8); //Converting Li to Byte and updating bitOffset
             break;         
      } 
      sduIdx++;
   }
   DEBUG4(("bitOffset(%d), roQPduCntxt->pduLen(%d), padStatusFlag(%d)\n", bitOffset, roQPduCntxt->pduLen, padStatusFlag));
   if((padStatusFlag == FALSE_E) && ((bitOffset>>3) < roQPduCntxt->pduLen))
   {  // Last Non Ending PDU
      DEBUG4(("Non Ending Pdu added pduLen(%d), bitOffset(%d) \n", roQPduCntxt->pduLen, bitOffset));
      roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len        = roQPduCntxt->pduLen - (bitOffset >> 3);
      roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset  = bitOffset;
      roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg  = FALSE_E;
      roQPduCntxt->numSeg++;
      DEBUG4(("numSeg(%d) len(%d), bitOffset(%d)\n", roQPduCntxt->numSeg, 
                                   roQPduCntxt->segDataInfo[roQPduCntxt->numSeg -1].len, bitOffset));
#if 0
 //  TBD: Currently Vr_R not updated on each pdu received
 //  but only when PDUs are assambled and forwarded to L3, then only we are updating Vr_R
 //  ====> take care in ack sufi of this consideration
 //  send lsn of first non existing PDU by checking reTxQ[sn] != TRUE
      if(hdrInfo->sn == amSV->vr_R){ //PDU with sn = Vr_R received, with non ending SDU. Update Vr_R
         amSV->vr_R  = hdrInfo->sn + 1;
         printf("RLC: ==== vrR Update new Value(%d)\n",amSV->vr_R);
      }
#endif
   }

   if(RLC_RX_AM_SN_IN_WINDOW(hdrInfo->sn, amSV->vr_H, amSV->vr_Mr) == TRUE_E) 
   {
      // For now not possible to have 4096 pdu. so harcoding, when needed use next statement which is commented
      amSV->vr_H = hdrInfo->sn + 1;
      DEBUG4(("vr_H Update new Value(%d)\n",amSV->vr_H));
   }
   RlcReassemblyUnit(&logChCntxt->u.amCntxt, ueIdx, logChId);

   return SUCCESS_E;
}

/************************************************************************************************
*
*  Handling of DL Data in RLC AM_Mode
*
************************************************************************************************/
/****************************************************
 *  		RLC CTRL PDU Create 
 * **************************************************/
S16 CreateAmRlcCtrlPdu(LogChId_t logChinfo, U8 *dataBuff,U16 pduLen, U16 bitOffset)
{
   RlcDlLogChInfo_t  *pDlLogChCntxt  = NULL;
   DlStatusPduInfo_t *statusPduInfo  = NULL;
   U16 nackSufiIdx = 0;

   pDlLogChCntxt  = (RlcDlLogChInfo_t *) GetRlcLogChContext(logChinfo.ueCellId.ueIdx, DIR_DL_E, LOG_CH_DCCH_E, logChinfo.logChId);

   DEBUG4(("CreateAmRlcCtrlPdu: bitOffset(%d)\n",  bitOffset));
   if(  (logChinfo.logChType != LOG_CH_DCCH_E) || (pDlLogChCntxt== NULL) 
      ||(pDlLogChCntxt->u.amCntxt.boCtrl == 0) || (pDlLogChCntxt->u.amCntxt.statusPduFlag != TRUE_E))
   {
      DEBUG4(("ERROR === Ctrl PDU Create Fail. logChType(%d), boCtrl(%d), statusPduFlag(%d)\n", 
                                    logChinfo.logChType, pDlLogChCntxt->u.amCntxt.boCtrl, pDlLogChCntxt->u.amCntxt.statusPduFlag));
      return -1; //Error
   }
   // Validation Success. Create Ctrl Pdu
   statusPduInfo = &pDlLogChCntxt->u.amCntxt.statusPduInfo;
   DEBUG4(("dc(%d),pduType(%d), listSufiLength(%d), iack sufi lsn(%d)\n", statusPduInfo->dcField,
                  statusPduInfo->pduType, statusPduInfo->listSufiLength, statusPduInfo->ackSufiInfo.lsn));
   PutNBits(dataBuff, 1,  bitOffset , statusPduInfo->dcField);          // RLC_AM_CTRL_PDU;   // 1 Bit
   bitOffset += 1;
   PutNBits(dataBuff, 3,  bitOffset , statusPduInfo->pduType);          // PDU_TYPE_STATUS_E; // 3 Bit 
   bitOffset += 3;
   // Fill List Sufi - Start
   if(statusPduInfo->listSufiLength != 0) // U16 so value never less than 0
   {
      DEBUG4(("Populate List Sufi SN0(%d), LI0(%d)\n", statusPduInfo->listSufiInfo.SN[0], statusPduInfo->listSufiInfo.LI[0]));
      PutNBits(dataBuff, 4,  bitOffset , SUFI_LIST_E); // SUFI_LIST_E
      bitOffset += 4;
      PutNBits(dataBuff, 4,  bitOffset , statusPduInfo->listSufiLength);
      bitOffset += 4;
      for(nackSufiIdx = 0; nackSufiIdx < statusPduInfo->listSufiLength; nackSufiIdx++)
      {
         PutNBits(dataBuff, 12, bitOffset , statusPduInfo->listSufiInfo.SN[nackSufiIdx] ); // amSV->vr_R ;sn < vr_R success // 12 Bit
         bitOffset += 12;
         PutNBits(dataBuff, 4, bitOffset , (statusPduInfo->listSufiInfo.LI[nackSufiIdx] - 1) ); //Li: no of consicutive not received PDU After nacked.
         bitOffset += 4;
      }
   }
   // Fill List Sufi - End
   // Fill ACk Sufi - Start
   {
      PutNBits(dataBuff, 4,  bitOffset , SUFI_ACK_E);         // SUFI_ACK_E;        // 4 Bit
      bitOffset += 4;
      PutNBits(dataBuff, 12, bitOffset , statusPduInfo->ackSufiInfo.lsn ); // amSV->vr_R ;sn < vr_R success // 12 Bit
      bitOffset += 12;
   }
   // Fill ACk Sufi - End

   // WE can directly set boCtrl = 0
   UpdateMacBo(logChinfo, pDlLogChCntxt->u.amCntxt.boCtrl, FALSE_E); // Get Ctrl Pdu Size as return Value
   pDlLogChCntxt->u.amCntxt.boCtrl       = 0;
#if 0
   // For sending one Ctrl Pdu decrease Bo only once
   UpdateMacBo(logChinfo, RLC_AM_ACK_SUFI_SIZE_BYTE, FALSE_E); // Get Ctrl Pdu Size as return Value
#endif
   pDlLogChCntxt->u.amCntxt.statusPduFlag = FALSE_E;           // Status PDU sent Reset Flag
   DEBUG4(("UL: CreateAmRlcCtrlPdu:boCtrl(%d), dc(%d), pduType(%d), listSufiLen(%d), lsn(%d)\n",
                                      pDlLogChCntxt->u.amCntxt.boCtrl,
                                      statusPduInfo->dcField,  statusPduInfo->pduType,
                                      statusPduInfo->listSufiLength, statusPduInfo->ackSufiInfo.lsn));
   memset(statusPduInfo, 0, sizeof(DlStatusPduInfo_t));
   DEBUG4(("CreateAmRlcCtrlPdu: bitOffset(%d)\n",  bitOffset));
   return RLC_AM_ACK_SUFI_SIZE_BYTE; 

} /*End of CreateAmRlcCtrlPdu*/

/****************************************************
 *  		RLC DATA PDU Create 
 * **************************************************/
ErrorCode_e GetAmDlRlcHdrInfo( U16 pduLen, LchDlAmCntxt_t *logChAmCntxt) 
{
   U16                   curSduIdx   = logChAmCntxt->sduQCntxt.nxtSduIdx;
   SduInfo_t             *curSdu     = &logChAmCntxt->sduQCntxt.sduInfo[curSduIdx];
   TxAmPduInfo_t         *txPduCntxt = &logChAmCntxt->reTxQ[logChAmCntxt->amSv.vt_S];
   RlcAmdTxPduHdrInfo_t  *hdrInfo    = &txPduCntxt->amPduHdrInfo;

   // Data Pdu, so set DC = TRUE_E
   hdrInfo->dcFlag       = TRUE_E;
   hdrInfo->sn           = logChAmCntxt->amSv.vt_S;
   // INCREMENT When Creating Data Pdu
   pduLen -= 2;  // 2 Byte USed for D/C, SN  .. field. Fixed Hdr

   if(logChAmCntxt->prevPduFullLiPendFlag  == TRUE_E)
   { // Last PDU Ended with SDU without Li information, add AM_MODE Li for it in this PDU.
      // TBD: Currently poll bit hardcoded at SDU end. make it generic in future.
      hdrInfo->pollBit                          = TRUE_E; // SDU Ending, Set poll Bit
      hdrInfo->Li[hdrInfo->numLi - 1]           = LI_PREV_SDU_END_WITH_PDU;
      logChAmCntxt->prevPduFullLiPendFlag       = FALSE_E;
      pduLen--; // One Byte used
   }
   /****************************************************
   * In AM No indication that SDU is starting with PDU.
   ******************************************************/
   //while((pduLen > 0) && (curSdu != NULL))
   if((pduLen > 0) && (curSdu != NULL))
   {
      if((curSdu->inUse != TRUE_E) ||(curSdu->len == 0)) {
         DEBUG4(("getAmDlRlcHdr Loop Break\n"));
         //break;
      }

			else
			{
			if(curSdu->byteLeft > pduLen) {                     // No LI: SDU Overflowing the Pdu
         hdrInfo->numSduSeg++;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len    = pduLen;  // Fill Complete PDU with Sdu
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].sduIdx = curSduIdx;
         pduLen = 0;
      }else if(curSdu->byteLeft  == pduLen) {             // No LI: This SDU Ending With PDU,
         hdrInfo->numSduSeg++;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len     = curSdu->byteLeft;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].sduIdx  = curSduIdx;
         logChAmCntxt->prevPduFullLiPendFlag                 = TRUE_E;  //SDU END WILL BE INDICATED IN NEXT PDU.
         pduLen = 0;
         // TBD:  In this scenario BO will be zero and it will not be scheduled. So Need to take care of this.
      }else if(curSdu->byteLeft  < pduLen ){           // Normal LI: SDU Ending within Pdu
         hdrInfo->numLi++;
         hdrInfo->numSduSeg++;
         pduLen--; //One Byte used for Li Filed
         hdrInfo->Li[hdrInfo->numLi - 1]                     = curSdu->byteLeft;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len     = curSdu->byteLeft ;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].sduIdx  = curSduIdx;
         pduLen                                             -= curSdu->byteLeft;
      }

      DEBUG4(("AM: Get next sdu context\n"));
      curSduIdx  = curSdu->nxtSduIdx;
      curSdu     = (curSduIdx !=0 ) ? (&logChAmCntxt->sduQCntxt.sduInfo[curSduIdx]) : NULL;
			}
   }
   
   if(pduLen > 0)  // SPECIAL LI: All bytes left are padding
   {
      // No SDU Content. No need to add sduSeg Info for Padding
      hdrInfo->numLi++;
      hdrInfo->Li[hdrInfo->numLi - 1]                        = LI_PADDING_TO_FILL_PDU;
      hdrInfo->paddingPresFlag                               = TRUE_E;
      pduLen = 0; // All remaining Bytes Filled by Padding
   }

   return SUCCESS_E;
} /* End of GetAmDlRlcHdrInfo*/

ErrorCode_e CreateDlAmRlcHdr( U8* rlcDataBuf,TxAmPduInfo_t *txPduInfo, U16 *bitOffset)
{
   S16                    liIdx   = 0;
   RlcAmdTxPduHdrInfo_t  *hdrInfo = &txPduInfo->amPduHdrInfo;

   // Filling AMD Header Fields.
   PutNBits( rlcDataBuf, 1, *bitOffset, hdrInfo->dcFlag);          // dcField : 1 Bit
   *bitOffset += 1; 
   PutNBits( rlcDataBuf, 12, *bitOffset, hdrInfo->sn);             // SN: 12 Bit
   *bitOffset += 12; 
   //PutNBits( rlcDataBuf, 1, *bitOffset, hdrInfo->pollBit);         // P- Poll Bit: 1 Bit
   PutNBits( rlcDataBuf, 1, *bitOffset, 1);         // always 1, for testing. Correct it later
   *bitOffset += 1; 
   if(hdrInfo->numLi > 0){
      PutNBits( rlcDataBuf, 2, *bitOffset, 1);
   }else {
      PutNBits( rlcDataBuf, 2, *bitOffset, 0);
   }
   *bitOffset += 2;

   for(liIdx = 0; liIdx < hdrInfo->numLi; liIdx++)
   {
      // Fill Li Field
      PutNBits( rlcDataBuf, 7, *bitOffset, hdrInfo->Li[liIdx]);
      *bitOffset += 7;
      if(liIdx != hdrInfo->numLi -1)
      {
         // Fill E - Extention Bit.
         PutNBits( rlcDataBuf, 1, *bitOffset, 1);
      }
      *bitOffset += 1;
   }

   return SUCCESS_E;
}

ErrorCode_e CreateAmRlcPdu( U8* rlcPduBuf, LchDlAmCntxt_t *logChAmCntxt, U16 *bitOffset) 
{
   U16             idx         = 0;  // Used in copying data Byte by Byte
   U16             segLen      = 0;
   U16             sduSegIdx   = 0;
   U16             curSduIdx   = 0;
   SduInfo_t       *curSdu     = NULL;;
   DlSduDataSeg_t  *curSduSeg  = NULL;
   RlcAmdTxPduHdrInfo_t *hdrInfo  = &logChAmCntxt->reTxQ[logChAmCntxt->amSv.vt_S].amPduHdrInfo;

   if(hdrInfo->numSduSeg == 0)
   {
      DEBUG4((" ERROR === numSduSeg = 0 in AMData PDu\n"));
   }
   for (sduSegIdx = 0; sduSegIdx < hdrInfo->numSduSeg; sduSegIdx++)
   {
      segLen = hdrInfo->sduDataSeg[sduSegIdx].len;
      // Get Info about Sdu and SDU Segment which need to be added
      curSduIdx  = hdrInfo->sduDataSeg[sduSegIdx].sduIdx;
      curSdu     = &logChAmCntxt->sduQCntxt.sduInfo[curSduIdx];

      if( (curSdu->byteLeft < segLen) || (curSdu->nxtPduOffset + segLen > curSdu->len) )
      {
         DEBUG4((" ERROR === In CreateAmRlcPdu: SegLen(%d) or ByteLeft(%d),pduOffset(%d) Calculation \n",
                                                 segLen, curSdu->byteLeft, curSdu->nxtPduOffset));
      }

      DEBUG4(("Add SDU in PDU. bitOffset(%d), segLen(%d), byteLeft(%d)\n", *bitOffset, segLen, curSdu->byteLeft));
      // Copy First SduSegment to RLC Pdu
      for( idx = 0; idx < segLen; idx++ ){
         // TBD: Write a MACRO for next two lines. RLC_AM_CPY_1_BYTE(dst, bitOffset, src)
         if(curSdu->byteLeft == curSdu->len)
            PutNBits( rlcPduBuf, 8, *bitOffset, curSdu->buf[idx]);
         else if(curSdu->byteLeft < curSdu->len)
            PutNBits( rlcPduBuf, 8, *bitOffset, curSdu->buf[idx + curSdu->nxtPduOffset]);

         *bitOffset += 8;
      } // Copy 1 Byte from source in one iteration. This logic is needed as Dst is not byte Aligned

      // Update Sdu Segment Info , And Sdu Info
      hdrInfo->sduDataSeg[sduSegIdx].segOffset = curSdu->nxtPduOffset;
      curSdu->byteLeft                        -= segLen;
      curSdu->nxtPduOffset                    += segLen;
      curSdu->numUsr                          += 1;
      hdrInfo->totalSduData                   += segLen;
      // Update Rlc Pdu Offset for next Segment
   }

   if(curSdu != NULL)
   {
      if(curSdu->byteLeft > 0){
         DEBUG4(("Sdu with sduIdx(%d) partialy added in RLC UMPDU, \n", curSduIdx));
         logChAmCntxt->sduQCntxt.nxtSduIdx = curSduIdx;
      }else{
         DEBUG4(("Sdu with sduIdx(%d) added in RLC UMPDU\n", curSduIdx));
         logChAmCntxt->sduQCntxt.nxtSduIdx = curSdu->nxtSduIdx;
         // TBD: in UM numSdu decremented here as SDU is no longer in use can release memory also
         // In AM mode decrement numSdu on receiving ack and release buffer also
         //logChCntxt->sduQCntxt.numSdu--;
      }
   }else{
      DEBUG4(("ERROR === CreateAmRlcPdu wrong CurrSdu val\n"));
   }
   DEBUG4(("PDU CREATED: next SduIdx(%d)\n", logChAmCntxt->sduQCntxt.nxtSduIdx));
   return SUCCESS_E;
}/*End of CreateAmRlcPdu*/

ErrorCode_e CreateAmRlcReTxPdu( U8* rlcPduBuf, LchDlAmCntxt_t *logChAmCntxt, U16 *bitOffset) 
{
   U16             idx         = 0;  // Used in copying data Byte by Byte
   U16             segLen      = 0;
   U16             sduSegIdx   = 0;
   U16             curSduIdx   = 0;
   SduInfo_t       *curSdu     = NULL;;
   DlSduDataSeg_t  *curSduSeg  = NULL;
   RlcAmdTxPduHdrInfo_t *hdrInfo  = &logChAmCntxt->reTxQ[logChAmCntxt->amSv.vt_S].amPduHdrInfo;

   DEBUG4(("Create RLC AM ReTx AMData PDu\n"));
   if(hdrInfo->numSduSeg == 0) {
      DEBUG4(("ERROR === numSduSeg = 0 in AMData PDu\n"));
   }

   for (sduSegIdx = 0; sduSegIdx < hdrInfo->numSduSeg; sduSegIdx++)
   {
      segLen = hdrInfo->sduDataSeg[sduSegIdx].len;
      // Get Info about Sdu and SDU Segment which need to be added
      curSduIdx  = hdrInfo->sduDataSeg[sduSegIdx].sduIdx;
      curSdu     = &logChAmCntxt->sduQCntxt.sduInfo[curSduIdx];

      if( (curSdu->byteLeft < segLen) || (curSdu->nxtPduOffset + segLen > curSdu->len) )
      {
         DEBUG4(("In CreateAmRlcReTxPdu: SegLen(%d) or ByteLeft(%d),pduOffset(%d) Calculation \n",
                                                 segLen, curSdu->byteLeft, curSdu->nxtPduOffset));
      }

      DEBUG4(("Add SDU in PDU. bitOffset(%d), segLen(%d), byteLeft(%d)\n", *bitOffset, segLen, curSdu->byteLeft));
      // Copy First SduSegment to RLC Pdu
      for( idx = 0; idx < segLen; idx++ ){
         // TBD: Write a MACRO for next two lines. RLC_AM_CPY_1_BYTE(dst, bitOffset, src)
         PutNBits( rlcPduBuf, 8, *bitOffset, curSdu->buf[idx]);
         *bitOffset += 8;
      } // Copy 1 Byte from source in one iteration. This logic is needed as Dst is not byte Aligned

      // Update Sdu Segment Info , And Sdu Info
      hdrInfo->sduDataSeg[sduSegIdx].segOffset = curSdu->nxtPduOffset;
   }

   DEBUG4(("ReTx PDU CREATED: next SduIdx(%d)\n", logChAmCntxt->sduQCntxt.nxtSduIdx));
   return SUCCESS_E;
}/*End of CreateAmRlcReTxPdu*/

S16 CreateAmRlcDataPdu(LogChId_t logChinfo, U8 *rlcPduBuf,U16 pduLen, U16 bitOffset)
{
   U16              i = 0;
   RlcDlLogChInfo_t *dlLogChCntxt = NULL;
   AmRlcTxSv_t      *amSV         = NULL;
   TxAmPduInfo_t    *txPduInfo    = NULL;

   DEBUG4(("CreateAmRlcDataPdu : bitOffset(%d)\n",  bitOffset));
   dlLogChCntxt = (RlcDlLogChInfo_t *) GetRlcLogChContext(logChinfo.ueCellId.ueIdx, DIR_DL_E, LOG_CH_DCCH_E, logChinfo.logChId);
   amSV         = &dlLogChCntxt->u.amCntxt.amSv;

   if(dlLogChCntxt->u.amCntxt.boData > 0)
   { // Send New Rlc PDU
      txPduInfo  = &dlLogChCntxt->u.amCntxt.reTxQ[amSV->vt_S]; // Next Sn to send is vt_S
      if(txPduInfo->inUse  == TRUE_E){
         DEBUG4(("ERROR === New Sn(%d) this PDU data is already in use\n", amSV->vt_S));
         return -1;
      }else{
         memset(txPduInfo, 0, sizeof(TxUmPduInfo_t ));
         txPduInfo->inUse  = TRUE_E;
         txPduInfo->sn     = amSV->vt_S;
      }
      // Collect AM RLC Header Info
      GetAmDlRlcHdrInfo( pduLen, &dlLogChCntxt->u.amCntxt);
      DEBUG4(("RLC: AMD- bitoffset before Am Hdr create (%d)\n", bitOffset)); 
      CreateDlAmRlcHdr( rlcPduBuf, txPduInfo, &bitOffset);
      CreateAmRlcPdu( rlcPduBuf, &dlLogChCntxt->u.amCntxt, &bitOffset);
   }
   else if(dlLogChCntxt->u.amCntxt.boReTxData > 0 )
   { // RLC PDU ReTx
      DEBUG4(("RLC: === ERROR === Trying to create Retx Pdu in New PDU create handling\n"));
      return ERROR_RLC_AMD_DATA_PDU_FAIL_E;
#if 0
      for(i = amSV->vt_A; i < amSV->vt_S; i++)
      {
         if(dlLogChCntxt->u.amCntxt.reTxQ[i].reTxStatus ==  TRUE_E){
            txPduInfo  = &dlLogChCntxt->u.amCntxt.reTxQ[i]; // Next Sn to send is vt_S
            printf("=== RLC: AM  Retx PDU with sn(%d), vt_A(%d), vt_S(%d)\n", i, amSV->vt_A, amSV->vt_S);
            CreateDlAmRlcHdr( rlcPduBuf, txPduInfo, &bitOffset);
            CreateAmRlcPdu( rlcPduBuf, &dlLogChCntxt->u.amCntxt, &bitOffset);
            break;
         }
      }
#endif
   } 


   dlLogChCntxt->u.amCntxt.boData  -= txPduInfo->amPduHdrInfo.totalSduData;
   INCREMENT_RLC_SN(dlLogChCntxt->u.amCntxt.amSv.vt_S, dlLogChCntxt->u.amCntxt.snLen);
   UpdateMacBo(logChinfo, txPduInfo->amPduHdrInfo.totalSduData, FALSE_E);

   return pduLen;
} /* End of CreateAmRlcDataPdu */

S16 CreateAmRlcReTxDataPdu(LogChId_t logChinfo, U8 *rlcPduBuf,U16 pduLen, U16 bitOffset)
{
   U16              i = 0;
   U16              reTxPduSn     = 0;
   RlcDlLogChInfo_t *dlLogChCntxt = NULL;
   AmRlcTxSv_t      *amSV         = NULL;
   TxAmPduInfo_t    *txPduInfo    = NULL;


   DEBUG4(("CreateAmRlcReTxDataPdu : bitOffset(%d)\n",  bitOffset));
   dlLogChCntxt = (RlcDlLogChInfo_t *) GetRlcLogChContext(logChinfo.ueCellId.ueIdx, DIR_DL_E, LOG_CH_DCCH_E, logChinfo.logChId);
   amSV         = &dlLogChCntxt->u.amCntxt.amSv;

   // RLC PDU ReTx
   for(i = amSV->vt_A; i < amSV->vt_S; i++)
   {
      if(dlLogChCntxt->u.amCntxt.reTxQ[i].reTxStatus ==  TRUE_E){
         txPduInfo  = &dlLogChCntxt->u.amCntxt.reTxQ[i]; // Next Sn to send is vt_S
         reTxPduSn  = i;
         break;
      }
   }
   if(txPduInfo == NULL) {
      DEBUG4(("RLC: === ERROR === No ReTx PDU Found in Reordering queue\n"));
      return ERROR_RLC_AMD_DATA_PDU_FAIL_E;
   }

   DEBUG4(("AM  Retx PDU with sn(%d), vt_A(%d), vt_S(%d)\n", i, amSV->vt_A, amSV->vt_S));
   CreateDlAmRlcHdr( rlcPduBuf, txPduInfo, &bitOffset);
   CreateAmRlcReTxPdu( rlcPduBuf, &dlLogChCntxt->u.amCntxt, &bitOffset);

   //  For ReTransMission
   DEBUG4(("=======================================================================\n"));
   DEBUG4(("------ RLC PDU ReTransmission on AM Data PDU of SN(%d)  --------\n",reTxPduSn));
   DEBUG4(("=======================================================================\n"));
   dlLogChCntxt->u.amCntxt.boReTxData -= txPduInfo->amPduHdrInfo.totalSduData;
   dlLogChCntxt->u.amCntxt.reTxQ[i].reTxStatus = FALSE_E;
   UpdateMacBo(logChinfo, txPduInfo->amPduHdrInfo.totalSduData, FALSE_E);

   return pduLen;
} /* End of CreateAmRlcReTxDataPdu*/
