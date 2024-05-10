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
 * File Name	: rlcUmTx.c
 *
 * Description  : This file has handling of Rlc UmMode handling. 
 *
 * History 	:
 *
 * Date		 Author 		 Details
 * ---------------------------------------------------------------------------
 * 15/11/2014	 Kuldeep S. Chauhan 	 File Creation
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
#include "macContext.h"
#include "cmnDebug.h"
#include "rrc.h"

static DbgModule_e  DBG_MODULE = rlc;


extern RlcCntxt_t gRlcContext;

ErrorCode_e GetUmDlRlcHdrInfo(LogChId_t *logChinfo, U16 pduLen, LchDlUmCntxt_t *logChCntxt, SduInfo_t *sduCntxt)
{
   ErrorCode_e     retCode   = SUCCESS_E;
   RlcPduHdrInfo_t *hdrInfo  = &logChCntxt->rlxTxPdu.rlcPduHdrInfo;
   U16             curSduIdx = logChCntxt->sduQCntxt.nxtSduIdx;
   SduInfo_t       *curSdu   = &logChCntxt->sduQCntxt.sduInfo[curSduIdx];

   hdrInfo->sn               = logChCntxt->nxtSn; 
   INCREMENT_RLC_SN(logChCntxt->nxtSn, logChCntxt->snLen);

   if(logChCntxt->prevPduFullLiPendFlag  == TRUE_E)
   {
      hdrInfo->numLi++;
      pduLen--; //One Byte used for Li Filed
      hdrInfo->Li[hdrInfo->numLi - 1]           = LI_PREV_SDU_END_WITH_PDU;
      logChCntxt->prevPduFullLiPendFlag = FALSE_E;
   }

   // New Sdu Starting With this PDU
   if((curSdu->byteLeft == curSdu->len) && (curSdu->nxtPduOffset == 0))
   {
      DEBUG4(("RLC: PDU STARTS WITH SDU sduIdx(%d): pduLen(%d), sduLen(%d)\n", curSduIdx, pduLen, curSdu->len));
      if(curSdu->len > pduLen){                     // Special LI: First SDU filled PDU and Overflowing
         hdrInfo->numLi++;
         hdrInfo->numSduSeg++;
         pduLen--; //One Byte used for Li Filed
         hdrInfo->Li[hdrInfo->numLi - 1]                          = SDU_STRT_WITH_PDU_NON_ENDING;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = pduLen;
         hdrInfo->sduDataSeg[0].sduIdx                   = curSduIdx; 
         pduLen = 0;
      } else if(curSdu->len == pduLen){              // No Li: First SDU exactly Fills PDU.
         // TBD: Cross Check, could be wrong
         DEBUG4(("RLC HDR FILLING: SPECIAL CASE- TBD-RECONFORM. SDU EXACTLY FILLS PDU\n"));
         logChCntxt->prevPduFullLiPendFlag                = TRUE_E; //SDU END WILL BE INDICATED IN NEXT PDU.
         hdrInfo->numSduSeg++;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = pduLen;
         hdrInfo->sduDataSeg[0].sduIdx                   = curSduIdx; 
         pduLen = 0;
      } else if(curSdu->len == pduLen - 1){          // Special Li: SDU EXACTLY FILLING THE SDU WITH SPACE FOR LI
         hdrInfo->numLi++;
         hdrInfo->numSduSeg++;
         pduLen--; //One Byte used for Li Filed
         hdrInfo->Li[hdrInfo->numLi - 1]                          = SDU_EXACT_FIT_PDU_WITH_LI;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = pduLen;
         hdrInfo->sduDataSeg[0].sduIdx                   = curSduIdx; 
         pduLen = 0;
      } else if(curSdu->len < pduLen - 1){          // Normal LI: SDU ending within Pdu, Normal Li
         hdrInfo->numLi++;
         hdrInfo->numSduSeg++;
         pduLen--; //One Byte used for Li Filed
         hdrInfo->Li[hdrInfo->numLi - 1]                          = curSdu->len;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = curSdu->len;
         hdrInfo->sduDataSeg[0].sduIdx                   = curSduIdx; 
         pduLen                                         -= (curSdu->len);
      }
      // First SDU Detials filled, Move CurSdu to next
      curSduIdx  = curSdu->nxtSduIdx;
      curSdu     = (curSduIdx !=0 ) ? (&logChCntxt->sduQCntxt.sduInfo[curSduIdx]) : NULL;
   }

   while((pduLen > 0) && (curSdu != NULL))
   {
      if((curSdu->inUse != TRUE_E) ||(curSdu->len == 0))
      {
         DEBUG4(("RLC: getHdrLoop Break\n"));
         break;
      }
      if(curSdu->byteLeft > pduLen) {                     // No LI: SDU Overflowing the Pdu
         hdrInfo->numSduSeg++;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = pduLen;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].sduIdx = curSduIdx; 
         pduLen = 0;
      } else if(curSdu->byteLeft  == pduLen) {              // No LI: This SDU Ending With PDU,
         hdrInfo->numSduSeg++;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = curSdu->byteLeft;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].sduIdx  = curSduIdx; 
         logChCntxt->prevPduFullLiPendFlag               = TRUE_E;  //SDU END WILL BE INDICATED IN NEXT PDU.
         pduLen = 0;
      } 
      else if(curSdu->byteLeft  <= pduLen - 1){            // Normal LI: SDU Ending within Pdu
         hdrInfo->numLi++;
         hdrInfo->numSduSeg++;
         pduLen--; //One Byte used for Li Filed
         hdrInfo->Li[hdrInfo->numLi - 1]                 = curSdu->byteLeft;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].len = curSdu->byteLeft ;
         hdrInfo->sduDataSeg[hdrInfo->numSduSeg - 1].sduIdx = curSduIdx; 
         pduLen                                         -= curSdu->byteLeft;
      }
 
      DEBUG4(("RLC: Get next sdu context\n"));
      curSduIdx  = curSdu->nxtSduIdx;
      curSdu     = (curSduIdx !=0 ) ? (&logChCntxt->sduQCntxt.sduInfo[curSduIdx]) : NULL;
   }

   if(pduLen > 0)  // SPECIAL LI: All bytes left are padding
   {
      // No SDU Content. No need to add sduSeg Info for Padding
      hdrInfo->numLi++;
      hdrInfo->Li[hdrInfo->numLi - 1]                = LI_PADDING_TO_FILL_PDU;
      pduLen = 0; // All remaining Bytes Filled by Padding
   }

   return retCode;
}

ErrorCode_e CreateDlUmRlcHdr( U8 *rlcPduBuf, U16 *pduByteIdx, TxUmPduInfo_t *txPduInfo)
{
   ErrorCode_e     retCode  = SUCCESS_E;
   RlcPduHdrInfo_t *hdrInfo = &txPduInfo->rlcPduHdrInfo;

   //Fill SN
   rlcPduBuf[*pduByteIdx]       = hdrInfo->sn << 1;
   DEBUG4(("DL RLC UM PDU sn(%d)  \n",hdrInfo->sn));
   (*pduByteIdx)++;

   // numLi is Unsigned int, => i<numLi will be always true so this weired indexing
   for( ; *pduByteIdx < hdrInfo->numLi+1; (*pduByteIdx)++) // One Byte for SN
   {
      // Fill Extn 'E' Bit in Previous SN/LI Field
      SET_EXTN_BIT_IN_LI_SN(rlcPduBuf[*pduByteIdx - 1]);
      rlcPduBuf[*pduByteIdx]    = (hdrInfo->Li[*pduByteIdx -1]) << 1;
      // INCREMENTED AT FOR LOOP
      //(*pduByteIdx)            += 1;
   }

   return SUCCESS_E;
} /* End of CreateDlUmRlcHdr*/

ErrorCode_e CreateUmRlcPdu( U8 *rlcPduBuf, U16 *pduByteIdx, LchDlUmCntxt_t *logChCntxt, U16 pduLen)
{
   ErrorCode_e     retCode      = SUCCESS_E;
   DlSduDataSeg_t  *curSduSeg   = NULL;
   U16             segLen       = 0;
   U16             sduSegIdx    = 0;
   U16             curSduIdx    = 0;
   SduInfo_t       *curSdu      = NULL;;
   RlcPduHdrInfo_t *hdrInfo     = &logChCntxt->rlxTxPdu.rlcPduHdrInfo;

   for (sduSegIdx = 0; sduSegIdx < hdrInfo->numSduSeg; sduSegIdx++)
   {
      segLen = hdrInfo->sduDataSeg[sduSegIdx].len;
      // Get Info about Sdu and SDU Segment which need to be added
      curSduIdx  = hdrInfo->sduDataSeg[sduSegIdx].sduIdx;
      curSdu     = &logChCntxt->sduQCntxt.sduInfo[curSduIdx];

      DEBUG4(("RLC:=== Add SDU in UmPdu. sduIdx(%d), pduByteIdx(%d),segLen(%d), byteLeft(%d)\n", curSduIdx, *pduByteIdx, segLen, curSdu->byteLeft));
      if(   (curSdu->byteLeft < segLen) 
         || (curSdu->nxtPduOffset + segLen > curSdu->len)
         || (segLen > (pduLen - *pduByteIdx)))
      {
         DEBUG4(("ERROR: In PduLen(%d), SegLen(%d) or ByteLeft(%d),pduOffset(%d) Calculation \n",
                           pduLen, segLen, curSdu->byteLeft, curSdu->nxtPduOffset));
      }

      // Copy First SduSegment to RLC Pdu
      memcpy( &rlcPduBuf[*pduByteIdx], &curSdu->buf[curSdu->nxtPduOffset], segLen); 
      
      // Update Sdu Segment Info , And Sdu Info
      hdrInfo->sduDataSeg[sduSegIdx].segOffset = curSdu->nxtPduOffset;
      curSdu->byteLeft                        -= segLen;
      curSdu->nxtPduOffset                    += segLen;
      curSdu->numUsr                          += 1;
      hdrInfo->totalSduData                   += segLen;
      // Update Rlc Pdu Offset for next Segment
      *pduByteIdx                              += segLen;

      if(curSdu->byteLeft > 0){
         DEBUG4(("RLC:==== Sdu with sduIdx(%d) partialy added in RLC UMPDU, SduNum \n", curSduIdx, logChCntxt->sduQCntxt.numSdu));
         logChCntxt->sduQCntxt.nxtSduIdx = curSduIdx;
         break; // This SDU is partiall added. i.e no more room for next SDU segment. 
      } 
      // CurSduSeg is sent, Free Sdu context if this was last segment
      if(curSdu->byteLeft == 0){
         DEBUG4(("RLC:==== RLC UM MODE sdu sent, cleanup sduIdx(%d)\n", curSduIdx));
         logChCntxt->sduQCntxt.nxtSduIdx = curSdu->nxtSduIdx;
         logChCntxt->sduQCntxt.numSdu--;
         free(curSdu->buf);
         memset(curSdu, 0, sizeof(SduInfo_t));
         DEBUG4(("RLC:==== sduIdx(%d) added in RLC UmPdu Release Sdu. SduNum(%d) after release\n", curSduIdx, logChCntxt->sduQCntxt.numSdu));
      }
   }

   DEBUG4(("RLC PDU CREATED: next SduIdx(%d)\n", logChCntxt->sduQCntxt.nxtSduIdx));
   return SUCCESS_E;
} /* End of CreateUmRlcPdu*/

ErrorCode_e DecodeRlcUmHdr(U16 ueIdx, RxUmPduHdrInfo_t *hdrInfo, U8 *dataBuff, U16 bitOffset)
{
   ErrorCode_e      retCode = SUCCESS_E;

   DEBUG4(("DecodeRlcUmHdr: \n"));
   // SN Field => 7 Bit
   hdrInfo->sn                = GetNBits(dataBuff, 7, bitOffset + hdrInfo->hdrLen);
   hdrInfo->hdrLen +=7;
   DEBUG4((" Decoding Rlc Um Pdu with sn (%d)\n", hdrInfo->sn));
   // E Field => 1 Bit
   hdrInfo->e                = GetNBits(dataBuff, 1, bitOffset + hdrInfo->hdrLen);;
   hdrInfo->hdrLen +=1;

   // HE is used for E field following Li in RLC PDU
   while(hdrInfo->e == 1)
   {
      hdrInfo->numLi++;
      hdrInfo->Li[hdrInfo->numLi -1] = GetNBits(dataBuff, 7, bitOffset + hdrInfo->hdrLen);
      hdrInfo->hdrLen +=7;
      hdrInfo->e                    = GetNBits(dataBuff, 1, bitOffset + hdrInfo->hdrLen);
      hdrInfo->hdrLen +=1;
      DEBUG4(("Li number(%d) , LiValue(%d) hdrLen(%d)\n", hdrInfo->numLi, hdrInfo->Li[hdrInfo->numLi -1], hdrInfo->hdrLen));
   }

   return retCode;
} /*End of DecodeRlcUmHdr*/

ErrorCode_e ReassabmleSndUmSdu(LchUlUmCntxt_t *umCntxt, U16 ueIdx, U16 sn)
{
   U16               i = 0, j = 0;
   U16               sduIdx        = 0;
   UmRlcRxSv_t      *umSv          = &umCntxt->umSv;
   RxUmPduInfo_t    *roQPduCntxt   = NULL;
   RrcDataReq       *pRrcDataInd   = NULL;
   RxUmSduDataSeg_t *pSduSeg       = NULL;
   U16               startReAsemblyFlag = FALSE_E;

   DEBUG4(("ReassabmleSndUmSdu ueIdx(%d), sn(%d)\n", ueIdx, sn));
   for(i = umSv->vr_R; i <= sn; i++)
   {
      roQPduCntxt  = &umCntxt->RxRoQueue[i];
      DEBUG4(("Reassabmle sn(%d), numSeg(%d)\n", i, roQPduCntxt->numSeg));
      if(roQPduCntxt->inUse != TRUE){
         DEBUG4(("ERROR_RLC_UMD_SDU_ASSMBLY_FAIL_E\n"));
         return ERROR_RLC_UMD_SDU_ASSMBLY_FAIL_E;
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
         if(pSduSeg->isFirstSeg == TRUE_E) {
            roQPduCntxt->numFirstSduSeg--;
            startReAsemblyFlag = TRUE_E;
         }

         if( (roQPduCntxt->pduBitOffset == 0) && (startReAsemblyFlag == TRUE_E)) // Byte Aligned RLC Data, can use memcpy 
         {
            memcpy( &pRrcDataInd->rrcPdu[pRrcDataInd->rrcPduLen], &roQPduCntxt->rlcPduBuf[pSduSeg->bitOffset >>  3], pSduSeg->len);
            pRrcDataInd->rrcPduLen += pSduSeg->len; // As Len was filled by Li value it is in Bytes
            DEBUG4(("Sdu Seg segIdx(%d) Added New pduLen(%d), sduSegLen(%d), bitOffset(%d)\n",
                                       sduIdx, pRrcDataInd->rrcPduLen, pSduSeg->len, pSduSeg->bitOffset));
            if((pSduSeg->isLastSeg == TRUE_E) && (startReAsemblyFlag == TRUE_E))
            {
               DEBUG4(("Send SDU to RRC at pdu sn(%d) . RRC DCCH PDU of pduLen(%d)\n", sn, pRrcDataInd->rrcPduLen));
               /* Post Message to APP RRC Task */
               SendMsgToTask (L2_UL_DATA_TASK_E, APP_RRC_TASK_E, L2_UL_DCCH_DATA_INDICATION_E, pRrcDataInd);
               // RRC Data Indication info already sent to RRC. 
               // Make pointer ready for next SDU(=NULL) without releasing memory
               pRrcDataInd = NULL;
               roQPduCntxt->nxtValidSegIdx = sduIdx + 1;
               roQPduCntxt->numLastSduSeg--;
               startReAsemblyFlag = FALSE_E;

               if(sduIdx == roQPduCntxt->numSeg -1)
               { //This is last SDU segment, set Vr_R to next PDU
                  umSv->vr_R  = sn + 1;
                  umSv->vr_Mr = umSv->vr_R + RLC_UM_WINDOW_SIZE;
                  DEBUG4(("UM StateVar update vr_R(%d), vr_Mr(%d) sduIdx(%d), numSeg(%d)\n",
                                                      umSv->vr_R, umSv->vr_Mr, sduIdx, roQPduCntxt->numSeg));
               }
               else{ // one or more SDU segments still pending in PDU for Processing
                  umSv->vr_R  = sn; // a Segment of this PDU need to be assembled next time
                  umSv->vr_Mr = umSv->vr_R + RLC_UM_WINDOW_SIZE;
                  DEBUG4(("Sdu Seg Pending in PDU. UM StateVar update vr_R(%d), vr_Mr(%d) sduIdx(%d), numSeg(%d)\n",
                                                      umSv->vr_R, umSv->vr_Mr, sduIdx, roQPduCntxt->numSeg));
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
            memset(roQPduCntxt, 0, sizeof(RxUmPduInfo_t) );
            return ERROR_RLC_UMD_SDU_ASSMBLY_FAIL_E;
         }
      }

      // RO_Pdu processing Done free PDU
      free(roQPduCntxt->rlcPduBuf);
      memset(roQPduCntxt, 0, sizeof(RxUmPduInfo_t) );
   }
   return SUCCESS_E;
}

ErrorCode_e RlcUmReassemblyUnit(LchUlUmCntxt_t *umCntxt, U16 ueIdx,  U16 logChId)
{
   U16              sn = 0;
   UmRlcRxSv_t      *umSv          = &umCntxt->umSv;
   RxUmPduInfo_t    *roQPduCntxt   = NULL;
   ErrorCode_e      retCode        = SUCCESS_E;
   U16              startReAsemblyFlag = FALSE_E;

   DEBUG4(("RLC: === Um RLC ReassemblyUnit ueIdx(%d) \n", ueIdx));
   for( sn = umSv->vr_R; sn < umSv->vr_H; sn++)
   {
      DEBUG4((" Pdu Sn(%d). First Seg Pres Flag(%d), Last Seg pres Flag(%d)\n", sn, umCntxt->RxRoQueue[sn].numFirstSduSeg, umCntxt->RxRoQueue[sn].numLastSduSeg));
      if(umCntxt->RxRoQueue[sn].inUse == TRUE_E)
      {
         if(umCntxt->RxRoQueue[sn].numFirstSduSeg >= 1) {
            umSv->vr_R = sn;
            startReAsemblyFlag = TRUE_E;
         }
         if((umCntxt->RxRoQueue[sn].numLastSduSeg >= 1) && (startReAsemblyFlag == TRUE_E)) {
            ReassabmleSndUmSdu(umCntxt, ueIdx, sn);
         }
      }
      else{
         // Missing PDU restart from next PDU
         umSv->vr_R = sn+1;
         startReAsemblyFlag = FALSE_E;
      }
   }

   return retCode;
}

ErrorCode_e ProcRlcUmDataPdu( RlcUlLogChInfo_t  *logChCntxt, U8 *dataBuff, U16 bitOffset, U16 ueIdx, U16 logChId)
{
   U16               sduIdx      = 0;
   UmRlcRxSv_t      *umSV        = &logChCntxt->u.umCntxt.umSv;
   RxUmPduHdrInfo_t *hdrInfo     = &logChCntxt->u.umCntxt.hdrInfo;
   RxUmPduInfo_t    *roQPduCntxt = &logChCntxt->u.umCntxt.RxRoQueue[hdrInfo->sn];
   ErrorCode_e       retCode     = SUCCESS_E;
   U16               padStatusFlag = FALSE_E;

   DEBUG4(("ProcRlcUmDataPdu: sn(%d),numLi(%d), vr_R(%d) , vr_H(%d) vr_Mr(%d)\n", 
                              hdrInfo->sn, hdrInfo->numLi, umSV->vr_R, umSV->vr_H ,umSV->vr_Mr));

   if( (RLC_RX_UM_SN_IN_WINDOW(hdrInfo->sn, umSV->vr_R, umSV->vr_Mr) != TRUE_E) 
     ||(roQPduCntxt->inUse == TRUE_E))
   {
      DEBUG4(("PDU OUTSIDE WINDOW or Duplicate PDU.sn(%d),vr_R(%d), vr_Mr(%d)\n", hdrInfo->sn, umSV->vr_R, umSV->vr_Mr));
      free(dataBuff);
      return ERROR_RLC_UMD_RX_PDU_PROC_FAIL_E;
   }
   if(roQPduCntxt->inUse != TRUE_E)
   {
      DEBUG4(("Add PDU in reordering Queue\n"));
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
      DEBUG4(("Process LiValue(%d), sduIdx(%d), bitOffset(%d) \n", hdrInfo->Li[sduIdx], sduIdx, bitOffset));
      switch(hdrInfo->Li[sduIdx])
      {
         case LI_PREV_SDU_END_WITH_PDU:        // Last PDU Ended With SDU
             DEBUG4(("RLC_PREV_PDU_END_WITH_SDU i.e liValue(0)\n"));
             // accessing with value numSeg -1, for 1st SduSeg numSeg =1 but index is 0
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len           = 0;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset     = 0;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg     = TRUE_E;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isFirstSeg    = FALSE_E;
             roQPduCntxt->numLastSduSeg++;
             roQPduCntxt->numSeg++;
             break;         

	 case SDU_EXACT_FIT_PDU_WITH_LI:    // 7D, SDU starts and ends with PDU
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len        = roQPduCntxt->pduLen - (bitOffset >> 3);
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset  = bitOffset;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isFirstSeg = TRUE_E;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg  = TRUE_E;
             roQPduCntxt->numFirstSduSeg++;
             roQPduCntxt->numLastSduSeg++;
             roQPduCntxt->numSeg++;
             DEBUG4(("First SDU Segment. SDU not ending in PDU. BitOffset(%d)\n", roQPduCntxt->numSeg, hdrInfo->Li[sduIdx], bitOffset));
             bitOffset  += (hdrInfo->Li[sduIdx]*8); //Converting Li to Byte and updating bitOffset
             break;         

         case SDU_ONLY_ONE_SEG_IN_PDU:
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len        = roQPduCntxt->pduLen - (bitOffset >> 3);
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset  = bitOffset;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isFirstSeg = FALSE_E;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg  = FALSE_E;
             roQPduCntxt->numSeg++;
             DEBUG4(("First SDU Segment. SDU not ending in PDU. BitOffset(%d)\n", roQPduCntxt->numSeg, hdrInfo->Li[sduIdx], bitOffset));
             bitOffset  += (hdrInfo->Li[sduIdx]*8); //Converting Li to Byte and updating bitOffset
             break;         

         case LI_PADDING_TO_FILL_PDU:
             DEBUG4(("Padding\n"));
             padStatusFlag = TRUE_E;
             break;

	 case SDU_STRT_WITH_UM_PDU:    // PDU Starts with SDU
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len        = (hdrInfo->numLi == 1) ? (roQPduCntxt->pduLen - (bitOffset >> 3)) : 0;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].bitOffset  = bitOffset;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isFirstSeg = TRUE_E;
             roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].isLastSeg  = FALSE_E;
             roQPduCntxt->numFirstSduSeg++;
             roQPduCntxt->numSeg++;
             DEBUG4(("First SDU Segment. SDU not ending in PDU. BitOffset(%d)\n", roQPduCntxt->numSeg, hdrInfo->Li[sduIdx], bitOffset));
             bitOffset  += ((roQPduCntxt->segDataInfo[roQPduCntxt->numSeg].len)*8); //Converting Li to Byte and updating bitOffset
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
   }

   if(RLC_RX_UM_SN_IN_WINDOW(hdrInfo->sn, umSV->vr_H, umSV->vr_Mr) == TRUE_E) 
   {
      // For now not possible to have 4096 pdu. so harcoding, when needed use next statement which is commented
      umSV->vr_H = hdrInfo->sn + 1;
      DEBUG4(("vr_H Update new Value(%d)\n",umSV->vr_H));
   }

   RlcUmReassemblyUnit(&logChCntxt->u.umCntxt, ueIdx, logChId);

   return SUCCESS_E;
}
