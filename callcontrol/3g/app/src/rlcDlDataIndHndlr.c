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
 * File Name	: rlcDlDataHndlr.c 
 *
 * Description  : This file has Rlc DL Data handling. 
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
#include "rlcUmData.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = rlc;

extern RlcCntxt_t gRlcContext;

ErrorCode_e DlCcchDataHndlr(LogChId_t logChinfo, U8 *rlcPduBuf,U16 pduLen)
{
   U16             pduByteIdx = 0;
   ErrorCode_e     errorCode   = SUCCESS_E;
   LchDlUmCntxt_t  *logChCntxt = &gRlcContext.rlcDlCcchCntxt.logChInfo[DL_CCCH_LCH_IDX_FOR_FACH];
   TxUmPduInfo_t   *txPduInfo  = &logChCntxt->rlxTxPdu;
   SduInfo_t       *sduCntxt   = &logChCntxt->sduQCntxt;

   // TBD: Need to Make TxPduInfo a pointer, as for AM it will move to ReTxInfo[sn]
   memset(txPduInfo, 0, sizeof(TxUmPduInfo_t ));
   txPduInfo->inUse  = TRUE_E;
   // TBD: Currently ASSUMING THIS IS FACH CHANNEL
   // In Future need to make generic to handle Paging channel as well

   // "-1" in PduLen as 1 Byte needed for SN
   GetUmDlRlcHdrInfo( &logChinfo, pduLen - 1, logChCntxt, sduCntxt);

   CreateDlUmRlcHdr( rlcPduBuf, &pduByteIdx, txPduInfo);
   CreateUmRlcPdu( rlcPduBuf, &pduByteIdx, logChCntxt, pduLen);

   DEBUG4(("Rlc PDU: - \n"));
#if 0
   for(pduByteIdx = 0; pduByteIdx < pduLen; pduByteIdx++)
   {
      printf("%3x",rlcPduBuf[pduByteIdx]);
   }
   printf("\n");
#endif

   UpdateMacBo(logChinfo, txPduInfo->rlcPduHdrInfo.totalSduData, FALSE_E);
   return errorCode;
}

ErrorCode_e RlcDataInd(LogChId_t logChinfo, U8 *rlcPduBuf, U16 pduLen)
{
   ErrorCode_e errorCode = SUCCESS_E;

   switch(logChinfo.logChType)
   {
   case LOG_CH_CCCH_E:
      if(logChinfo.idType != ID_TYPE_CELL_ID_E)
      {
         errorCode = ERROR_GENERIC_FAILURE_E;
         break;
      }
      errorCode = DlCcchDataHndlr( logChinfo, rlcPduBuf, pduLen); 
      break;
   case LOG_CH_CTCH_E:
   case LOG_CH_DTCH_E:
   case LOG_CH_DCCH_E:
   case LOG_CH_INVLID_E:
   default:
      DEBUG4(("Data Request for Fach Trch With Wrong LogChType(%d)\n", logChinfo.logChType));
      errorCode = ERROR_INVALID_LOGCH_TYPE_E;
      break;
   }

   return errorCode;
} /*End of RlcFachDataReq */

ErrorCode_e DlDcchDataHndlr(LogChId_t logChinfo, U8 *rlcPduBuf,U16 pduLen, U16 bitOffset)
{
   U16             i = 0;
   U16             pduByteIdx = 0;
   ErrorCode_e     errorCode   = SUCCESS_E;
   LchDlAmCntxt_t  *logChCntxt = &gRlcContext.rlcUeCntxt[logChinfo.ueCellId.ueIdx].dlLogChInfo[logChinfo.logChId].u.amCntxt;
   TxAmPduInfo_t   *txPduInfo  = NULL; // Select based on amSv, parameter values
   SduInfo_t       *sduCntxt   = &logChCntxt->sduQCntxt;
   S16             ctrlPduSize = 0;
   S16             dataPduSize = 0;

   DEBUG4(("DlDcchDataHndlr  , ueIdx(%d), logChId(%d), pduLen(%d)\n", logChinfo.ueCellId.ueIdx, logChinfo.logChId, pduLen));
   DEBUG4(("==: boData(%d), reTxBo(%d), crtlBo(%d)\n",logChCntxt->boData, logChCntxt->boReTxData, logChCntxt->boCtrl));
   if(logChCntxt->boData > 0 || logChCntxt->boReTxData > 0)
   {
      dataPduSize = CreateAmRlcDataPdu(logChinfo, rlcPduBuf, pduLen, bitOffset);
      if(dataPduSize <= 0){
         DEBUG4(("RLC AM DATA PDU Creat Failure, ueIdx(%d), logChId(%d)\n", logChinfo.ueCellId.ueIdx, logChinfo.logChId));
         return ERROR_RLC_AMD_DATA_PDU_FAIL_E;
      }

   }else if(logChCntxt->boReTxData > 0)
   {
      dataPduSize = CreateAmRlcReTxDataPdu(logChinfo, rlcPduBuf, pduLen, bitOffset);
      if(dataPduSize <= 0){
         DEBUG4(("==== RLC: RLC AM ReTx DATA PDU Creat Failure, ueIdx(%d), logChId(%d)\n", logChinfo.ueCellId.ueIdx, logChinfo.logChId));
         return ERROR_RLC_AMD_DATA_PDU_FAIL_E;
      }

   }else if(logChCntxt->boCtrl > 0)
   {
      ctrlPduSize  = CreateAmRlcCtrlPdu(logChinfo, rlcPduBuf, pduLen, bitOffset);
      if(ctrlPduSize <= 0) {
         DEBUG4(("==== RLC: RLC AM CTRL PDU Creat Failure, ueIdx(%d), logChId(%d)\n", logChinfo.ueCellId.ueIdx, logChinfo.logChId));
         return ERROR_RLC_AMD_CTRL_PDU_FAIL_E;
      }
   } else 
   {
      DEBUG4(("==== RLC: RLC AM CTRL PDU Creat Failure, ueIdx(%d), logChId(%d)\n", logChinfo.ueCellId.ueIdx, logChinfo.logChId));
      return ERROR_RLC_AMD_DATA_PDU_FAIL_E;
   }

   DEBUG4(("RLC AM: Final MAC PDU - len(%d)\n", pduLen));
#if 0
   for(i = 0; i < pduLen; i++)
   {  
      printf(" %02x,",rlcPduBuf[i]);
   }printf("\n");
#endif

   return SUCCESS_E;
}

ErrorCode_e RlcDchDataInd(LogChId_t logChinfo, U8 *rlcPduBuf, U16 pduLen/*In Bytes*/, U16 bitOffset)
{
   ErrorCode_e errorCode = SUCCESS_E;

   switch(logChinfo.logChType)
   {
   case LOG_CH_DCCH_E:
      if(logChinfo.idType != ID_TYPE_UE_IDX_E){
         DEBUG4(("ERROR: RlcDchDataInd - ERROR_GENERIC_FAILURE_E\n"));
         errorCode = ERROR_GENERIC_FAILURE_E;
      }else {
         DEBUG4((" RlcDchDataInd - pduLen(%d), bitOffset(%d)\n", pduLen, bitOffset));
         errorCode = DlDcchDataHndlr( logChinfo, rlcPduBuf, pduLen, bitOffset);
      }
      break;
   default:
      DEBUG4((" Data Request for Fach Trch With Wrong LogChType(%d)\n", logChinfo.logChType));
      errorCode = ERROR_INVALID_LOGCH_TYPE_E;
      break;
   }

   return errorCode;
} /*End of RlcDchDataReq */
