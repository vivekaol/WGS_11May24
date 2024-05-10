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
 ############################################################################ */

/**############################################################################
 * File Name	 : macContext.c 
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 09/11/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "macUlDataHndlr.h"
#include "macContext.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = mac;

MacContext_t       gMacContext;
MacPagingContext_t gMacPagingContext;

void InitMacCellContext(void)
{
   gMacContext.cellId        = 0;
}

void InitMacRachContext(void)
{
   DEBUG4(("ENTRY == InitMacRachContext \n"));
   gMacContext.rachCfg.macTfSet.numTf     = 2;
   gMacContext.rachCfg.macTfSet.macTf[0].blockNum  = 0;
   gMacContext.rachCfg.macTfSet.macTf[0].blockSize = 360;
   gMacContext.rachCfg.macTfSet.macTf[1].blockNum  = 1;
   gMacContext.rachCfg.macTfSet.macTf[1].blockSize = 360;
   //gMacContext.rachCfg.macHdrType   = 0; //NOT USED FOR NOW
   gMacContext.rachCfg.macHdrLen                   = 2;
   //gMacContext.rachCfg.macRachHdr.tctfChType       = TCTF_CH_TYPE_INVALID_E;
   gMacContext.rachCfg.macRachHdr.idType           = ID_TYPE_INVLID_E;
   gMacContext.rachCfg.macRachHdr.id.cellId        = 0;
   //gMacContext.rachCfg.macRachHdr.macCt          = //DUMMY FOR NOW
   gMacContext.rachCfg.macRachHdr.macLogChType     = LOG_CH_INVLID_E;
   gMacContext.rachCfg.macPduOffset                = 0;
   //gMacContext.fachCfg                           //DUMMY FOR NOW

   return;
}

void InitMacFachContext(void )
{
   DEBUG4(("ENTRY == InitMacFachContext\n"));
   gMacContext.fachCfg.macTfSet.numTf              = 3;
   gMacContext.fachCfg.macTfSet.macTf[0].blockNum  = 0;
   // TB SIZE 0xa8 = 168 => MAC HDR(1Byte) + RLC HDR(1Byte) + RLC SDU Data with Padding
   gMacContext.fachCfg.macTfSet.macTf[0].blockSize = 0xa8;
   gMacContext.fachCfg.macTfSet.macTf[1].blockNum  = 1;
   gMacContext.fachCfg.macTfSet.macTf[1].blockSize = 0xa8;
   gMacContext.fachCfg.macTfSet.macTf[2].blockNum  = 2;
   // In Case of 2 Blocks, 2 RLC PDU to be sent. Both will have individual RLC Header. 
   gMacContext.fachCfg.macTfSet.macTf[2].blockSize = 0xa8;
   gMacContext.fachCfg.bo                          = 0;
   // 8 bit MAC Header. Only TCTF field = CCCH(0100,0000 = 0x40)
   gMacContext.fachCfg.macHdrLen                   = 8; 
   gMacContext.fachCfg.macFachHdr[0]               = 0x40;

   gMacContext.fachCfg.logChinfo.logChType        = LOG_CH_CCCH_E;
   gMacContext.fachCfg.logChinfo.logChId          = LOG_CH_ID_FACH;
   gMacContext.fachCfg.logChinfo.idType           = ID_TYPE_CELL_ID_E;
   gMacContext.fachCfg.logChinfo.ueCellId.cellId  = 0;

   return;
}

void InitMacUeContext(void )
{
   DEBUG4(("ENTRY == InitMacUeContext\n"));
   gMacContext.numUe             = 0;
   memset( gMacContext.ueCfg, 0, MAC_MAX_UE_NUM * sizeof(MacUeCfg_t ));

   return;
}

void InitMacPagingContext (void)
{
   unsigned int idx = 0;

   gMacPagingContext.numOfPagingMsg = 0;
   for (idx =0; idx < MAX_PCCH_MSG; idx++)
   {
       gMacPagingContext.pPcchMsg[idx] = NULL;
   }
}

void MacClaenupMacPagingContext(void)
{
   unsigned int idx = 0;

   for (idx = 0; idx < gMacPagingContext.numOfPagingMsg; idx++)
   {
      if (NULL != gMacPagingContext.pPcchMsg[idx])
      {
          if(NULL != gMacPagingContext.pPcchMsg[idx]->rrcPdu)
          {
             free(gMacPagingContext.pPcchMsg[idx]->rrcPdu);
			 gMacPagingContext.pPcchMsg[idx]->rrcPdu = NULL;
          }
          free (gMacPagingContext.pPcchMsg[idx]);
          gMacPagingContext.pPcchMsg[idx] = NULL;
      }
   }

   gMacPagingContext.numOfPagingMsg = 0;
}

void MacAddPcchMsgToMacPagingContext (RrcPcchMsg *pPcchMsg)
{
   unsigned int idx = 0;
   unsigned int found = 0;

   DEBUGMSG(("Add paging type1 context for imsi(%s)\n",pPcchMsg->imsi));

   if (0 == gMacPagingContext.numOfPagingMsg)
   {
      gMacPagingContext.numOfPagingMsg++;

      gMacPagingContext.pPcchMsg[0]            = (RrcPcchMsg *)malloc(sizeof(RrcPcchMsg));
      gMacPagingContext.pPcchMsg[0]->sfn       = pPcchMsg->sfn;
      gMacPagingContext.pPcchMsg[0]->rrcPduLen = pPcchMsg->rrcPduLen;
      gMacPagingContext.pPcchMsg[0]->rrcPdu    = (unsigned char *)malloc(sizeof(unsigned char)*pPcchMsg->rrcPduLen);
      memcpy(gMacPagingContext.pPcchMsg[0]->rrcPdu, pPcchMsg->rrcPdu, pPcchMsg->rrcPduLen);
      gMacPagingContext.pPcchMsg[0]->count     = 0;
      strncpy (gMacPagingContext.pPcchMsg[0]->imsi, pPcchMsg->imsi, MAX_IMSI_LENGTH);
      gMacPagingContext.pPcchMsg[0]->imsi[MAX_IMSI_LENGTH] = '\0';
	  gMacPagingContext.pPcchMsg[0]->isInitialIMSIPaging = pPcchMsg->isInitialIMSIPaging;

      free(pPcchMsg->rrcPdu);
      pPcchMsg->rrcPdu = NULL;
      free(pPcchMsg);
      pPcchMsg = NULL;
   }
   else
   {
      /* 
       * Check for empty entry in the List. If found any empty list
       * is found then add the Paging Message into it.
       */
      for (idx = 0; idx < gMacPagingContext.numOfPagingMsg; idx++)
      {
          if (NULL == gMacPagingContext.pPcchMsg[idx])
          {
             gMacPagingContext.pPcchMsg[idx] = (RrcPcchMsg *)malloc(sizeof(RrcPcchMsg));
             gMacPagingContext.pPcchMsg[idx]->sfn       = pPcchMsg->sfn;
             gMacPagingContext.pPcchMsg[idx]->rrcPduLen = pPcchMsg->rrcPduLen;
             gMacPagingContext.pPcchMsg[idx]->rrcPdu    = (unsigned char *)malloc(sizeof(unsigned char)*pPcchMsg->rrcPduLen);
             memcpy(gMacPagingContext.pPcchMsg[idx]->rrcPdu, pPcchMsg->rrcPdu, pPcchMsg->rrcPduLen);
             gMacPagingContext.pPcchMsg[idx]->count     = 0;
             strncpy (gMacPagingContext.pPcchMsg[idx]->imsi, pPcchMsg->imsi, MAX_IMSI_LENGTH);
             gMacPagingContext.pPcchMsg[idx]->imsi[MAX_IMSI_LENGTH] = '\0';
			 gMacPagingContext.pPcchMsg[idx]->isInitialIMSIPaging = pPcchMsg->isInitialIMSIPaging;

             free(pPcchMsg->rrcPdu);
             pPcchMsg->rrcPdu = NULL;
             free(pPcchMsg);
             pPcchMsg = NULL;

             found = 1;
             break;
          }
      }

      /*
       * Add the Paging Message in new entry, if empty entry not found.
       */
      if (0 == found)
      {
          idx = gMacPagingContext.numOfPagingMsg;
          gMacPagingContext.pPcchMsg[idx] = (RrcPcchMsg *)malloc(sizeof(RrcPcchMsg));
          gMacPagingContext.pPcchMsg[idx]->sfn       = pPcchMsg->sfn;
          gMacPagingContext.pPcchMsg[idx]->rrcPduLen = pPcchMsg->rrcPduLen;
          gMacPagingContext.pPcchMsg[idx]->rrcPdu    = (unsigned char *)malloc(sizeof(unsigned char)*pPcchMsg->rrcPduLen);
          memcpy(gMacPagingContext.pPcchMsg[idx]->rrcPdu, pPcchMsg->rrcPdu, pPcchMsg->rrcPduLen);
          gMacPagingContext.pPcchMsg[idx]->count     = 0;
          strncpy (gMacPagingContext.pPcchMsg[idx]->imsi, pPcchMsg->imsi, MAX_IMSI_LENGTH);
          gMacPagingContext.pPcchMsg[idx]->imsi[MAX_IMSI_LENGTH] = '\0';
          gMacPagingContext.pPcchMsg[idx]->isInitialIMSIPaging = pPcchMsg->isInitialIMSIPaging;
		  
          free(pPcchMsg->rrcPdu);
          pPcchMsg->rrcPdu = NULL;
          free(pPcchMsg);
          pPcchMsg = NULL;

          gMacPagingContext.numOfPagingMsg++;
      }
   }
   DEBUGMSG(("NumPaging context after Adding context(%d)\n",gMacPagingContext.numOfPagingMsg));
}

void MacDelPcchMsgFromMacPagingContext(char * imsi, unsigned int freeImsiMemFlag)
{
   unsigned int idx = 0;

   DEBUGMSG(("Delete paging type1 context for imsi(%s)\n",imsi));

   for(idx = 0; idx < gMacPagingContext.numOfPagingMsg; idx++)
   {
      if(strncmp(imsi, gMacPagingContext.pPcchMsg[idx]->imsi , 15/*IMSI_LEN*/) == 0)
      {  // PCCH Message found, delete this entry
         cleanSinglePagingContext(idx);
         return;
      }
   }

   //Not Freeing memory as calling from schedPchData, with array(not to be freed) 
   if(freeImsiMemFlag == 1)
   {
      free(imsi);
   }
}

void cleanSinglePagingContext(unsigned int idx)
{
   if (NULL != gMacPagingContext.pPcchMsg[idx])
   {
       if(NULL != gMacPagingContext.pPcchMsg[idx]->rrcPdu)
       {
          free(gMacPagingContext.pPcchMsg[idx]->rrcPdu);
       }
       free (gMacPagingContext.pPcchMsg[idx]);
       gMacPagingContext.pPcchMsg[idx] = NULL;
   }
   //Moving Last entry to deleted location, this is to avoid shifting.
   gMacPagingContext.pPcchMsg[idx] = gMacPagingContext.pPcchMsg[gMacPagingContext.numOfPagingMsg - 1];
   gMacPagingContext.pPcchMsg[gMacPagingContext.numOfPagingMsg - 1] = NULL;
   gMacPagingContext.numOfPagingMsg--;
   
   DEBUGMSG(("NumPaging context after deleting context(%d)\n",gMacPagingContext.numOfPagingMsg));
}

MacRachCfg_t *getRachCfg()
{
   DEBUG4(("ENTRY == getRachCfg\n"));
   return &(gMacContext.rachCfg);
}

MacDchCfg_t *getDchCfg(U16 ueIdx)
{
   DEBUG4((" ENTRY == getDchCfg \n"));
   if(ueIdx > 0){
      return &(gMacContext.ueCfg[ueIdx].dchCfg[0]);
   }
   else{
      DEBUG1(("ERROR: INVALID UeIdx\n"));
      return NULL;
   }
}

ErrorCode_e UpdateMacBo(LogChId_t logChId, S16 bo, U8 incDec)
{
   ErrorCode_e errorCode = SUCCESS_E;
   DEBUG4(("Update Bo: logChtype(%d), logChId(%d), IdType(%d), Id(%d)\n", 
                               logChId.logChType, logChId.logChId, logChId.idType, logChId.ueCellId.ueIdx));
   switch(logChId.logChType)
   {
   case LOG_CH_CCCH_E:
      {
      switch(logChId.idType)
         {
         case ID_TYPE_CELL_ID_E:
            if(incDec == TRUE_E)
            {
               DEBUG4(("Update(INC) Bo for CCCH (FACH) in MAC: currBo(%d), dataAdded(%d)\n", gMacContext.fachCfg.bo, bo));
               gMacContext.fachCfg.bo                   += bo;
            }
            else
            {
               DEBUG4(("Update(DEC) Bo for CCCH (FACH) in MAC: currBo(%d), dataSent(%d)\n", gMacContext.fachCfg.bo, bo));
               gMacContext.fachCfg.bo     = (gMacContext.fachCfg.bo < bo) ?  0 : (gMacContext.fachCfg.bo - bo);
               DEBUG4(("Bo MAC: currBo(%d), dataSent(%d)\n", gMacContext.fachCfg.bo, bo));
            }
            break;
         default:
            DEBUG4(("Wrong IdType for CCCH(FACH) BO update\n"));
            errorCode = ERROR_GENERIC_FAILURE_E;
            break;
         }
      }
      break;
   case LOG_CH_CTCH_E:
   case LOG_CH_DTCH_E:
   case LOG_CH_DCCH_E:
      {
      switch(logChId.idType)
         {
         case ID_TYPE_UE_IDX_E:
            if(incDec == TRUE_E)
            {
               DEBUG4((" Update(INC) Bo for DCH in MAC: currBo(%d), dataAdded(%d)\n", gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo, bo));
               gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo                     += bo;
               gMacContext.ueCfg[logChId.ueCellId.ueIdx].perLogChBo[logChId.logChId] += bo;
               DEBUG4(("Update(INC) Bo for DCH in MAC: currBo(%d), \n", gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo));
            }
            else
            {
               DEBUG4(("Update(DEC) Bo for DCH in MAC: currBo(%d), dataSent(%d)\n", gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo, bo));
               if(gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo < bo){
                  // Decrease Total only for this perticular LogCh
                  gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo                 -gMacContext.ueCfg[logChId.ueCellId.ueIdx].perLogChBo[logChId.logChId];
                  gMacContext.ueCfg[logChId.ueCellId.ueIdx].perLogChBo[logChId.logChId]  = 0;
                  DEBUG4((" Decrease Bo MAC: currBo(%d), dataSent(%d)(set bo = 0)\n", gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo, bo));
               }
               else{
                  gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo                     -= bo;
                  gMacContext.ueCfg[logChId.ueCellId.ueIdx].perLogChBo[logChId.logChId] -= bo;
                  DEBUG4(("Decrease Bo MAC: currBo(%d), dataSent(%d)\n", gMacContext.ueCfg[logChId.ueCellId.ueIdx].perUeBo, bo));
               }
            }
            break;
         default:
            DEBUG4(("ERROR === Wrong IdType for DCCH(DCH) BO update\n"));
            errorCode = ERROR_GENERIC_FAILURE_E;
            break;
         }
      }
      break;
   default:
      DEBUG4(("ERROR === Wrong/Not supported Logical Channel for Bo Update in MAC\n"));
      errorCode = ERROR_GENERIC_FAILURE_E;
      break;
   }

   return errorCode;
}
