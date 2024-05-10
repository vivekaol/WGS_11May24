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
 * File Name	 : macDlDataHndlr.c
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 11/11/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
//#include "macDlDataHndlr.h"
#include "macContext.h"
#include "macRlcInterface.h"
#include "string.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = mac;

extern MacContext_t       gMacContext;
extern MacPagingContext_t gMacPagingContext;
extern int clientFd;

U16 MacGetFachTfci(MacTfSet_t *macTfSet, U32 bo)
{
   U16 tfIdx = 0;

   for (tfIdx = 0; tfIdx < macTfSet->numTf; tfIdx++)
   {
      if(((macTfSet->macTf[tfIdx].blockNum) * ((macTfSet->macTf[tfIdx].blockSize + 7)  >>3)) > bo)
      {
         return (tfIdx);
      }
   }

   return (tfIdx -1); // -1 to remove extra increment at end of loop
}

U16 MacGetDchTfci(MacTfSet_t *macTfSet, U32 bo)
{
   U16 tfIdx = 0;

   for (tfIdx = 0; tfIdx < macTfSet->numTf; tfIdx++)
   {
      if(((macTfSet->macTf[tfIdx].blockNum) * ((macTfSet->macTf[tfIdx].blockSize + 7)  >>3)) > bo)
      {
         return (tfIdx);
      }
   }

   return (tfIdx -1); // -1 to remove extra increment at end of loop
}

void UpdateMacCellSfn(U32 bfn)
{
   if(bfn != ((gMacContext.curSfn + 1) %4096))
   {
      DEBUG1(("SFN Drift L1bfn(%d), MacSfn(%d)\n", bfn, gMacContext.curSfn));
   }

   gMacContext.curSfn = bfn;
   return;
}

void schedFachData(U32 bfn)
{
   U16     tfi          = 0;
   U16     tbIdx         = 0;
   U16     numTbSched    = 0;
   U16     tbSizeSched   = 0;     // TB Size in Bytes
   U8      *macFpDataBuf = NULL;  // Buffer to store DL FP Data
   U16     tbByteOffset  = 0;
   U8      cfn = (U16) (bfn &0xFF); // 8 Bit Cfn

   DEBUG4(("========== Schedule Data on FACH =========\n"));
   // TFCI Selection
   tfi = MacGetFachTfci(&gMacContext.fachCfg.macTfSet, GET_FACH_BO());
   if(tfi > gMacContext.fachCfg.macTfSet.numTf){
      DEBUG1(("ERROR: Wrong TFI\n"));
   }
   numTbSched  = gMacContext.fachCfg.macTfSet.macTf[tfi].blockNum;
   tbSizeSched = (gMacContext.fachCfg.macTfSet.macTf[tfi].blockSize + 7) >> 3;

   DEBUG4(("FACH Data Scheduled with blockNum(%d), blockSize in Bits(%d)", numTbSched, tbSizeSched));

   // Allocate memory to transfer complete data via FP to L1
   // TBD :Assumption Block Size is Multiple of 8 (i.e. complete Byte )
   macFpDataBuf = (U8 *) malloc(numTbSched * tbSizeSched);
   memset(macFpDataBuf, 0, numTbSched * tbSizeSched);
   if(macFpDataBuf == NULL){
      DEBUG1(("++++++++++++++++++++ ERROR MALLOC FAILED ++++++++++++\n"));
   }
   for(tbIdx = 0; tbIdx < numTbSched; tbIdx++)
   {
      tbByteOffset  = tbIdx*tbSizeSched;
      // Add 1 Byte MAC Header.
      macFpDataBuf[tbByteOffset] = gMacContext.fachCfg.macFachHdr[0];

      // TBD: Make it generic to get UmData
      // RlcDataInd( <BUFFER STRT PTR TO STORE RLC PDU>, <RLC PDU LEN>)
      DEBUG4(("Get RLC PDU for FACH, Rlc Byte Offset(%d), tbIdx(%d)\n", tbByteOffset, tbIdx));
      /********************************************************
            Update BO in RLC code
      *********************************************************/
      RlcDataInd(  gMacContext.fachCfg.logChinfo, 
                   &macFpDataBuf[tbByteOffset + MAC_FACH_HDR_BYTE_LEN], 
                   (tbSizeSched - MAC_FACH_HDR_BYTE_LEN) );
   }

   SendFachDataToL1(macFpDataBuf, cfn, tfi, gMacContext.fachCfg.macTfSet.macTf[tfi]);
   return;
}

void SchedPerUeDch(U32 bfn, U16 ueIdx)
{
   U16        tfi           = 0;
   U16        tbIdx         = 0;
   MacTfSet_t *macTfSet     = NULL;
   U16        numTbSched    = 0;
   U16        tbSizeSched   = 0;
   U8         *macFpDataBuf = NULL;  // Buffer to store DL FP Data
   U8         tstBuf[18] = {0x28, 0x00, 0x50, 0xff, 0xe1, 0x50, 0x00, 0x40, 0xa3, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   U16        tbByteOffset  = 0;
   U8         cfn = (U16) (bfn &0xFF); // 8 Bit Cfn
   U16        i = 0, j = 0;

   DEBUG4(("MAC: Schedule DCH data for Ue(%d) \n",ueIdx));

   macTfSet = &gMacContext.ueCfg[ueIdx].dchCfg[0].macTfSet;
   // TFCI Selection
   // TBD: MacGetDchTfci is same as MacGetFachTfci, replace them by one. once working
   tfi = MacGetDchTfci(macTfSet, GET_DCH_BO(ueIdx));

   if(tfi > macTfSet->numTf){
      DEBUG1(("ERROR: Wrong TFI\n"));
   }

   numTbSched  = macTfSet->macTf[tfi].blockNum;
   tbSizeSched = (macTfSet->macTf[tfi].blockSize + 7) >> 3;

   DEBUG4(("DCH Data Scheduled with blockNum(%d), blockSize in Bits(%d)\n", numTbSched, tbSizeSched));

   // Allocate memory to transfer complete data via FP to L1
   // TBD :Assumption Block Size is Multiple of 8 (i.e. complete Byte )
   macFpDataBuf = (U8 *) malloc(numTbSched * tbSizeSched);
   memset(macFpDataBuf, 0, numTbSched * tbSizeSched);
   if(macFpDataBuf == NULL){
      DEBUG1(("++++++++++++++++++++ ERROR MALLOC FAILED ++++++++++++\n"));
      return;
   }
#if 0
   memcpy(macFpDataBuf, tstBuf, tbSizeSched);
#endif
   for(tbIdx = 0; tbIdx < numTbSched; tbIdx++)
   {
      tbByteOffset  = tbIdx*tbSizeSched;

     for(i = 0; i < MAC_MAX_LOG_CH_UE_NUM; i++)
     {
        if(gMacContext.ueCfg[ueIdx].perLogChBo[i] > 0 )
        {
           DEBUG4(("Data Ind to get data from Rlc,ueId(%d), LogCh(%d) ByteOffset(%d), tbIdx(%d)\n", ueIdx, 
                                                          gMacContext.ueCfg[ueIdx].logChinfo[i].logChId, tbByteOffset, tbIdx));
           // Add 1 Byte MAC Header.==> For LogChId 1 fill 0. as per spec
           macFpDataBuf[tbByteOffset] = ((U8 )gMacContext.ueCfg[ueIdx].logChinfo[i].logChId -1) << 4;
           gMacContext.ueCfg[ueIdx].logChinfo[i].logChType             = LOG_CH_DCCH_E;
           gMacContext.ueCfg[ueIdx].logChinfo[i].logChId               = i;
           gMacContext.ueCfg[ueIdx].logChinfo[i].idType                = ID_TYPE_UE_IDX_E;
           gMacContext.ueCfg[ueIdx].logChinfo[i].ueCellId.ueIdx        = ueIdx;

           RlcDchDataInd( gMacContext.ueCfg[ueIdx].logChinfo[i], 
                          &macFpDataBuf[tbByteOffset], 
                          ((macTfSet->macTf[tfi].blockSize - MAC_DCH_HDR_BIT_LEN +7) >>3), /*Len in Bytes*/
                          MAC_DCH_HDR_BIT_LEN );
           break;
        }
     }
   }

   DEBUG4(("=========   SEND DL DCH DATA FROM MAC TO CL :  ueIdx(%d)====================\n", ueIdx));
   // L2 and Cl are using different indexing for ueId
   SendDchDataToL1(ueIdx -1, macFpDataBuf, cfn, tfi, macTfSet->macTf[tfi]);
   return;
}

unsigned int schedPchData (U32 bfn)
{
   unsigned int retCode      = 0;
   unsigned int idx          = 0;
   unsigned int idx1         = 0;
   unsigned int pagingCycle  = 1;
   unsigned int pagingValue  = 0;
   unsigned int valuePresent = 0;
   char *outOfCovrgeImsi = (char *) malloc((sizeof(char)) * (MAX_IMSI_LENGTH + 1));

   for(idx = 0; idx < gMacPagingContext.numOfPagingMsg; idx++)
   {
       /*
        * Paging Message is sent for (Paging SFN + 1) & (Paging SFN + 2).
        * Paging message is sent much before to L1 to schedule properly.
        */ 
       if ((NULL != gMacPagingContext.pPcchMsg[idx]) && 
           ((bfn == (gMacPagingContext.pPcchMsg[idx]->sfn - 7)) ||
            (bfn == (gMacPagingContext.pPcchMsg[idx]->sfn - 6))))
       {
           //DEBUG3(("Mac : Calculated Paging SFN(%ld), Current SFN(%ld)\n", gMacPagingContext.pPcchMsg[idx]->sfn, bfn));

           /* Send Paging Message to L1 */
           SendPchDataToL1 (idx, bfn);
           gMacPagingContext.pPcchMsg[idx]->count++;
           /* 
            * Adjust the Paging SFN as per DRX Cycle(64).
            */
           if (bfn == (gMacPagingContext.pPcchMsg[idx]->sfn - 6))
           {
ContinuousLoop:
               pagingValue  = 0;
               valuePresent = 0;

               pagingValue = (gMacPagingContext.pPcchMsg[idx]->sfn + (pagingCycle * 64)) % 4096;

               /* Make the Paging SFN in proper boundary */
               if (pagingValue <= 8)
               {
                   pagingCycle++;
                   goto ContinuousLoop;
               }

               for (idx1 = 0; idx1 < gMacPagingContext.numOfPagingMsg; idx1++)
               {
                  if ((idx != idx1) && (pagingValue == gMacPagingContext.pPcchMsg[idx1]->sfn))
                  {
                      valuePresent = 1;
                      break;
                  }
               }

               if (1 == valuePresent)
               {
                   pagingCycle++;
                   goto ContinuousLoop;
               }
               else
               {
                   gMacPagingContext.pPcchMsg[idx]->sfn = pagingValue % 4096;
               }
           }

#if 0  /* Avoiding sending of FXL_BL_UE_POWER_OFF_IND with FXL_RL_FAILURE */
           if((FALSE == gMacPagingContext.pPcchMsg[idx]->isInitialIMSIPaging) &&
		   	  (gMacPagingContext.pPcchMsg[idx]->count ==  MAX_PAGING_CNT_UE_POWER_OFF))
           {  //MAX paging count without response. Assuming UE RL Failure or swutch off. Send Power off indiaction

              fxLBlUePowerOffInd powerOffInd;
              memset (&powerOffInd, 0 , sizeof (fxLBlUePowerOffInd));
              powerOffInd.hdr.msgLength = sizeof(fxLBlUePowerOffInd);
              powerOffInd.hdr.rat = FXL_RAT_3G;
              powerOffInd.hdr.msgType = FXL_BL_UE_POWER_OFF_IND;
              powerOffInd.detachCause = FXL_RL_FAILURE;
              strncpy (powerOffInd.imsiStr, gMacPagingContext.pPcchMsg[idx]->imsi, MAX_IMSI_LENGTH);
			  powerOffInd.imsiStr[MAX_IMSI_LENGTH] = '\0';

              if (-1 != clientFd)
              {
                  if (send(clientFd, &powerOffInd, sizeof(powerOffInd), 0) < 0)
                  {
                       DEBUG1(("Unable to send Message to External Client\n"));
                  }
                  else
                  {
                       DEBUGMSG(("UE Power Off Indication is sent to External Client\n"));
                  }
              }
              else
              {
                   DEBUG1(("Unable to send message to External Client, clientFd = -1\n"));
              }
           }
           else if((FALSE == gMacPagingContext.pPcchMsg[idx]->isInitialIMSIPaging) &&
		   	       (gMacPagingContext.pPcchMsg[idx]->count > MAX_PAGING_CNT_UE_OUT_OF_COVERAGE))
#endif
           if((FALSE == gMacPagingContext.pPcchMsg[idx]->isInitialIMSIPaging) &&
		   	  (gMacPagingContext.pPcchMsg[idx]->count > MAX_PAGING_CNT_UE_OUT_OF_COVERAGE))          

           {  //MAX Paging count without response reached. Assuming UE went out of coverage. Stop Paging
              strncpy ( outOfCovrgeImsi, gMacPagingContext.pPcchMsg[idx]->imsi, MAX_IMSI_LENGTH);
              outOfCovrgeImsi[MAX_IMSI_LENGTH] = '\0';
              cleanSinglePagingContext(idx);

              /* Post Message to APP RRC Task */
              SendMsgToTask (L2_DL_DATA_TASK_E, APP_RRC_TASK_E, L2_DL_PCCH_UE_OUT_OF_COVERAGE_E, outOfCovrgeImsi);
           }
           retCode = 1;
           break;
       }
   }

   return (retCode);
}

void MacTtiIndHndlr(U32 bfn)
{
   U16         ueIdx;

   UpdateMacCellSfn(bfn); 

   //Schedule Paging
   if ((gMacPagingContext.numOfPagingMsg > 0) &&
       (0 != schedPchData (bfn)))
   {
       /* 
        * Paging message is sent to L1.
        */
   }
   else
   {
       // Fach is 20 ms TTI. So Schedule Fach only for even SFN, when data is available.
       if((GET_FACH_BO() > 0) && ((bfn % 2) == 0))
       {
           DEBUG4(("MAC TTI Ind: Fach bo(%d) \n",GET_FACH_BO()));
           // Schedule Data on common Channels
           schedFachData(bfn);
       }
   }

   // Schedule per UE Data on Dedicated channels
#if 1
   //TBD: In future need to have saperate list of valid UEs
   // UeIdx = 0 not used in L2
   if((bfn % 4) == 0)
   {
      for(ueIdx = 1; ueIdx < MAC_MAX_UE_NUM; ueIdx++)
      {
         if( gMacContext.ueCfg[ueIdx].perUeBo > 0)
            SchedPerUeDch( bfn, ueIdx);
      }
   }
#endif

   return;
}
