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
 * File Name	: rlcDlSduHndlr.c
 *
 * Description  : This file has handles the SDU received in RLC Layer from RRC Layer
 *
 * History 	:
 *
 * Date		 Author 		 Details
 * ---------------------------------------------------------------------------
 * 19/11/2014	 Kuldeep S. Chauhan 	 File Creation
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
#include "rrc.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = rlc;

extern RlcCntxt_t gRlcContext;

ErrorCode_e AddSduInSduQ( U8 *rlcSduBuf, U16 rlcSduLen,SduQCntxt_t *sduQCntxt)
{
   U16 i = 0;
   U16 lastSduIdx = sduQCntxt->lastSduIdx; 

   DEBUG4(("RLC:== Add Sdu in SduQ, before adding numSdu (%d), lastSduIdx(%d) \n", sduQCntxt->numSdu, sduQCntxt->lastSduIdx));
   DEBUG4(("RLC:== lastSduIdx(%d), nxtSduIdx(%d), numSdu(%d)\n",sduQCntxt->lastSduIdx,sduQCntxt->nxtSduIdx, sduQCntxt->numSdu));
   if((sduQCntxt->numSdu >= MAX_SDU_PER_LOG_CH) 
      || (INC_RLC_SDU_NUM(sduQCntxt->lastSduIdx) == sduQCntxt->nxtSduIdx))
   {
      DEBUG4(("Max Number of Sdu in SduQ Reached: numSduInQ(%d)\n", sduQCntxt->numSdu));
      return ERROR_GENERIC_FAILURE_E;
   }
   
   sduQCntxt->numSdu++;
   sduQCntxt->sduInfo[lastSduIdx].inUse         = TRUE_E;
   sduQCntxt->sduInfo[lastSduIdx].numUsr        = 0; // Added One context
   //sduQCntxt->sduInfo[lastSduIdx].mui         =  //NOT USED FOR NOW
   sduQCntxt->sduInfo[lastSduIdx].byteLeft      = rlcSduLen;
   sduQCntxt->sduInfo[lastSduIdx].len           = rlcSduLen;
   sduQCntxt->sduInfo[lastSduIdx].nxtPduOffset  = 0;
   sduQCntxt->sduInfo[lastSduIdx].buf           = rlcSduBuf;
   sduQCntxt->sduInfo[lastSduIdx].nxtSduIdx     = INC_RLC_SDU_NUM(sduQCntxt->lastSduIdx);
   sduQCntxt->sduInfo[lastSduIdx].prevSduIdx    = DEC_RLC_SDU_NUM(sduQCntxt->lastSduIdx);
   sduQCntxt->lastSduIdx                        = INC_RLC_SDU_NUM(sduQCntxt->lastSduIdx);

   DEBUG4((" RRC SDU STORED in RLC : sduIDx(%d), len(%d)\n", lastSduIdx, sduQCntxt->sduInfo[lastSduIdx].len));
   #if 0
   for(i = 0; i < sduQCntxt->sduInfo[lastSduIdx].len; i++)
   {
      printf(" %02x", sduQCntxt->sduInfo[lastSduIdx].buf[i]);
   }printf("\n");
#endif

   return SUCCESS_E;

}/*End of AddSduInSduQ*/

ErrorCode_e RlcDlCcchDataHndlr(RrcDataReq * dlDataReq)
{
   U16           i = 0;
   ErrorCode_e   retCode = SUCCESS_E;
   LchDlUmCntxt_t *logChCntxt;
   SduQCntxt_t    *sduQCntxt;
   LogChId_t      logChId;

   DEBUG4(("RlcDlCcchDataHndlr: idType(%d), LogChType(%d)\n", dlDataReq->cellOrUeId.choice, dlDataReq->logicalChType));
   // Re-Validation
   if((dlDataReq->cellOrUeId.choice != RRC_CELL_ID) || (dlDataReq->logicalChType != LOG_CH_CCCH_E))
   {
      DEBUG4(("ERROR: Wrong IdType/Channel Type \n"));
      free(dlDataReq->rrcPdu);
      free(dlDataReq);
      return ERROR_GENERIC_FAILURE_E;
   }

   // Print RRC SDU BUFFER
   DEBUG4((" RLC SDU Received on DL_CCCH of Len(%d):\n", dlDataReq->rrcPduLen));
#if 0
   for(i = 0; i < dlDataReq->rrcPduLen; i++)
   {
      printf(" %02x", dlDataReq->rrcPdu[i]);
   }printf("\n");
#endif

   // Logical Channed Id is not used for DL_CCCH for now. CellId Not used
   logChCntxt = GetRlcLogChContext(/*dlDataReq->cellOrUeId.u.cellId */0, DIR_DL_E, dlDataReq->logicalChType, 0);
   if(logChCntxt == NULL){
      DEBUG4(("ERROR: Invalid Logical Channel Context Drop Sdu \n"));
      free(dlDataReq->rrcPdu);
      free(dlDataReq);
      return ERROR_GENERIC_FAILURE_E;
   }

   /********* HERE IS Actual Handling to Add new Sdu to SduQ of Dl_CCCH(FACH)*****/
   retCode = AddSduInSduQ( dlDataReq->rrcPdu, dlDataReq->rrcPduLen, &(logChCntxt->sduQCntxt));
   // Update BO for Logical channel which got this data
   logChCntxt->boData  = dlDataReq->rrcPduLen; 
   // Update Bo in MAC - Start
   logChId.logChType   = dlDataReq->logicalChType;
   logChId.logChId     = 0;// Only Dl_CCCH=> FACH will come to this method
   logChId.idType      = ID_TYPE_CELL_ID_E;
   UpdateMacBo(logChId, logChCntxt->boData, TRUE_E);

   if(retCode != SUCCESS_E){ // In Success it is added in SDU Q
      DEBUG1(("++++++++++++++++++++++++++ ERROR: RRC SDU ADD IN RLC FAIL: Drop SDU ++++++++\n"));
      free(dlDataReq->rrcPdu);
   }
   free(dlDataReq);
   return retCode;

} /*End of RlcDlCcchDataHndlr*/

ErrorCode_e RlcDlDcchDataHndlr(RrcDataReq * dlDataReq)
{
   U16            i = 0;
   U16            ueIdx = dlDataReq->cellOrUeId.u.ueId + 1;
   ErrorCode_e    retCode = SUCCESS_E;
   LchDlAmCntxt_t *logChCntxt;
   SduQCntxt_t    *sduQCntxt;
   LogChId_t      logChId;

   // ueIdx Alignment for L3->L2
   DEBUG4(("=== RLC RlcDlDcchDataHndlr: ueIdx(%d), idType(%d), LogChType(%d) logChId(%d)\n", 
                      ueIdx, dlDataReq->cellOrUeId.choice, dlDataReq->logicalChType, dlDataReq->logicalChId));
   // Re-Validation
   if((dlDataReq->cellOrUeId.choice != RRC_UE_ID ) || (dlDataReq->logicalChType != LOG_CH_DCCH_E))
   {
      DEBUG4(("ERROR: Wrong IdType/Channel Type \n"));
      free(dlDataReq->rrcPdu);
      free(dlDataReq);
      return ERROR_GENERIC_FAILURE_E;
   }

   // Print RRC SDU BUFFER
   DEBUG4(("RLC: SDU Received on DL_DCCH of Len(%d):\n", dlDataReq->rrcPduLen));
#if 0
   for(i = 0; i < dlDataReq->rrcPduLen; i++)
   {
      printf("%3x", dlDataReq->rrcPdu[i]);
   }printf("\n");
#endif

   // Logical Channed Id is not used for DL_CCCH for now. CellId Not used
   logChCntxt = &gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo[dlDataReq->logicalChId].u.amCntxt;
   if(logChCntxt == NULL){
      DEBUG4(("ERROR: Invalid Logical Channel Context Drop Sdu \n"));
      free(dlDataReq->rrcPdu);
      free(dlDataReq);
      return ERROR_GENERIC_FAILURE_E;
   }

   /********* HERE IS Actual Handling to Add new Sdu to SduQ of Dl_CCCH(FACH)*****/
   retCode = AddSduInSduQ( dlDataReq->rrcPdu, dlDataReq->rrcPduLen, &(logChCntxt->sduQCntxt));
   // Update BO for Logical channel which got this data
   //logChCntxt->boData     = dlDataReq->rrcPduLen; 
      DEBUG3(("Before RLC SDU added bo (%d)\n",logChCntxt->boData));
   logChCntxt->boData     += dlDataReq->rrcPduLen; 
      DEBUG3(("After RLC SDU added bo (%d)\n",logChCntxt->boData));
   // Update Bo in MAC - Start
   logChId.logChType      = dlDataReq->logicalChType;
   logChId.logChId        = dlDataReq->logicalChId;// Only Dl_CCCH=> FACH will come to this method
   logChId.idType         = ID_TYPE_UE_IDX_E;
   logChId.ueCellId.ueIdx = ueIdx;
   //UpdateMacBo(logChId, logChCntxt->boData, TRUE_E);
   UpdateMacBo(logChId, dlDataReq->rrcPduLen, TRUE_E);

   if(retCode != SUCCESS_E){ // In Success it is added in SDU Q
      DEBUG1(("++++++++++++++++++++++++++ ERROR: RRC SDU ADD IN RLC FAIL: Drop SDU ++++++++\n"));
      free(dlDataReq->rrcPdu);
   }
   free(dlDataReq);
   return retCode;

} /*End of RlcDlCcchDataHndlr*/
