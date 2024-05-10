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
 * File Name	: rlcCfgHndlr.c 
 *
 * Description  : This file has is entry point of all Message received in L2 Task 
 *
 * History 	:
 *
 * Date		 Author 				 Details
 * ---------------------------------------------------------------------------
 * 13/10/2014	 Kuldeep S. Chauhan 	 File Creation
 *############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cmnDs.h"
#include "cmnPf.h"
#include "l2Cmn.h"
#include "rlcContext.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = rlc;

void RlcCfgDelReq( U32 ueIdx)
{
   U16  i = 0;

   if(gRlcContext.rlcUeCntxt[ueIdx].inUse != TRUE_E)
   {
      DEBUG3(("ERROR: === RLC CFG UeIdx(%d) Not in use. Wrong Config \n", ueIdx));
      return;
   }
   memset( &gRlcContext.rlcUeCntxt[ueIdx], 0, sizeof(RlcUeCntxt_t));
   gRlcContext.numUe--;
   DEBUG4(("Config Delete for ueIdx(%d) Success \n", ueIdx));

#if 1
   U16  j = 0;
   SduQCntxt_t    *sduQCntxt = NULL;
   LchUlAmCntxt_t *ulAmCntxt = NULL;

   DEBUG4(("RlcCfgDelReq ueIdx(%d)\n",ueIdx));
   // Release memory in AM/UM/TM Context Reordering Queue and SDU Queue
   for(i = 0; i < MAX_DCH_LOG_CH_PER_UE; i++)
   {
      DEBUG4(("Cleanup LogChIdx(%d), rlcMode(%d)\n", i, gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo[i].rlcMode));
      // FREE DL 
      switch(gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo[i].rlcMode)
      {
      case RLC_MODE_AM_E:
         sduQCntxt = &gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo[i].u.amCntxt.sduQCntxt;
         // TBD: Change loop to only go through valid entries. Complete list loop is temporary.
         for(j = 0; j < MAX_SDU_PER_LOG_CH; j++)
         { 
            if(sduQCntxt->sduInfo[j].inUse == TRUE_E)
            {
               DEBUG4(("Free SDU with sdu index(%d)\n", j));
               free(sduQCntxt->sduInfo[j].buf);
            }
         }
         break;
      case RLC_MODE_UM_E:
         sduQCntxt = &gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo[i].u.umCntxt.sduQCntxt;
         // TBD: Change loop to only go through valid entries. Complete list loop is temporary.
         for(j = 0; j < MAX_SDU_PER_LOG_CH; j++)
         { 
            if(sduQCntxt->sduInfo[j].inUse == TRUE_E)
            {
               DEBUG4((" Free SDU with sdu index(%d)\n", j));
               free(sduQCntxt->sduInfo[j].buf);
            }
         }
         break;
      }

      // FREE UL 
      if(gRlcContext.rlcUeCntxt[ueIdx].ulLogChInfo[i].rlcMode == RLC_MODE_AM_E)
      {
         ulAmCntxt = &gRlcContext.rlcUeCntxt[ueIdx].ulLogChInfo[i].u.amCntxt;
         while(ulAmCntxt->amSv.vr_R < ulAmCntxt->amSv.vr_H)
         {
            if(ulAmCntxt->RxRoQueue[ulAmCntxt->amSv.vr_R].rlcPduBuf != NULL)
            {
               DEBUG4(("Free RxRoPdu with sb(%d)\n", ulAmCntxt->amSv.vr_R));
               free(ulAmCntxt->RxRoQueue[ulAmCntxt->amSv.vr_R].rlcPduBuf);
            }
            ulAmCntxt->amSv.vr_R++;
         }
      }
      memset( &gRlcContext.rlcUeCntxt[ueIdx], 0, sizeof( RlcUeCntxt_t));

   }
#endif

   return;
}

void RlcUeCfgReq(U32 ueIdx)
{
   U16   i = 0;
   RlcDlLogChInfo_t *rlcDlLogChCfg = gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo;
   RlcUlLogChInfo_t *rlcUlLogChCfg = gRlcContext.rlcUeCntxt[ueIdx].ulLogChInfo;

   memset( &gRlcContext.rlcUeCntxt[ueIdx], 0, sizeof(RlcUeCntxt_t));

   if(gRlcContext.rlcUeCntxt[ueIdx].inUse == TRUE_E)
   {
      DEBUG3(("ERROR: === RLC CFG UeIdx(%d) Already in use. Wrong Config \n", ueIdx));
      return;
   }
   gRlcContext.numUe++;
   gRlcContext.rlcUeCntxt[ueIdx].inUse                       = TRUE_E;
   gRlcContext.rlcUeCntxt[ueIdx].numLogCh                    = MAX_DCH_LOG_CH_PER_UE;

   // LogCh Id = 1 UM Mode, Rach/Fach Cfg
   {
      // TBD: No need to memset individual fiels after doing complete UE context memset at start
      memset(&rlcDlLogChCfg[0], 0, sizeof(RlcDlLogChInfo_t));
      memset(&rlcDlLogChCfg[1], 0, sizeof(RlcDlLogChInfo_t));
      rlcDlLogChCfg[1].rlcMode                             = RLC_MODE_UM_E;
      rlcDlLogChCfg[1].u.umCntxt.lchType                   = LOG_CH_DCCH_E;
      rlcDlLogChCfg[1].u.umCntxt.logChId                   = 1;
      rlcDlLogChCfg[1].u.umCntxt.dir                       = DIR_DL_E;
      rlcDlLogChCfg[1].u.umCntxt.rlcMode                   = RLC_MODE_UM_E;
      rlcDlLogChCfg[1].u.umCntxt.nxtSn                     = 0; //Starting with Sn 1
      rlcDlLogChCfg[1].u.umCntxt.snLen                     = 7; // 7 bit
      rlcDlLogChCfg[1].u.umCntxt.boData                    = 0;
      rlcDlLogChCfg[1].u.umCntxt.boCtrl                    = 0;
      rlcDlLogChCfg[1].u.umCntxt.ctrlPduPres               = FALSE_E;

      rlcUlLogChCfg[1].rlcMode                             = RLC_MODE_UM_E;
      rlcUlLogChCfg[1].u.umCntxt.lchType                   = LOG_CH_DCCH_E;
      rlcUlLogChCfg[1].u.umCntxt.logChId                   = 1;
      rlcUlLogChCfg[1].u.umCntxt.dir                       = DIR_UL_E;
      rlcUlLogChCfg[1].u.umCntxt.rlcMode                   = RLC_MODE_UM_E;
      rlcUlLogChCfg[1].u.umCntxt.snLen                     = 7; // Am PDU, Sn = 12 bit
      rlcUlLogChCfg[1].u.umCntxt.umSv.vr_Mr                = RLC_UM_WINDOW_SIZE; // HardCoding Window Size, same in SrbCfg
   }

   // LogChId 2-4, All AM Mode Configuration
   for(i = 2; i < MAX_DCH_LOG_CH_PER_UE; i++)
   {
      // TBD: No need to memset individual fiels after doing complete UE context memset at start
      memset(&rlcDlLogChCfg[i], 0, sizeof(RlcDlLogChInfo_t));
      memset(&rlcUlLogChCfg[i], 0, sizeof(RlcUlLogChInfo_t));
      rlcDlLogChCfg[i].rlcMode                             = RLC_MODE_AM_E;

      rlcDlLogChCfg[i].u.amCntxt.dir                       = DIR_DL_E;
      rlcDlLogChCfg[i].u.amCntxt.logChId                   = i;
      rlcDlLogChCfg[i].u.amCntxt.lchType                   = LOG_CH_DCCH_E;
      rlcDlLogChCfg[i].u.amCntxt.snLen                     = 12; // Am PDU, Sn = 12 bit
      rlcDlLogChCfg[i].u.amCntxt.amSv.vt_Ms                = RLC_AM_WINDOW_SIZE;
      rlcDlLogChCfg[i].u.amCntxt.amSv.vt_Ws                = RLC_AM_WINDOW_SIZE;

      //-----> These are already NULL at Init, or at Delete
      //rlcDlLogChCfg[i].rlcMode.u.amCntxt.rlxTxPdu
      //rlcDlLogChCfg[i].rlcMode.u.amCntxt.reTxQ[RLC_AM_RO_QUEUE_SIZE]
      memset(&rlcDlLogChCfg[i].u.amCntxt.sduQCntxt, 0, sizeof(SduQCntxt_t));
      rlcUlLogChCfg[i].rlcMode                     = RLC_MODE_AM_E;
      rlcUlLogChCfg[i].u.amCntxt.dir               = DIR_UL_E;
      rlcUlLogChCfg[i].u.amCntxt.logChId           = i;
      rlcUlLogChCfg[i].u.amCntxt.lchType           = LOG_CH_DCCH_E;
      rlcUlLogChCfg[i].u.amCntxt.snLen             = 12; // Am PDU, Sn = 12 bit
      rlcUlLogChCfg[i].u.amCntxt.amSv.vr_Mr        = RLC_AM_WINDOW_SIZE; // HardCoding Window Size, same in SrbCfg
   }

   DEBUG3(("Config for ueIdx(%d) Success \n", ueIdx));
   return;
}
