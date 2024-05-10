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
 * File Name	: rlcContext.c 
 *
 * Description  : This file handles RLC Context
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
#include "cmnPf.h"
#include "cmnDs.h"
#include "l2Cmn.h"
#include "rlcContext.h"
#include "errorCode.h"
#include "rrc.h"
#include "macRlcInterface.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = rlc;

RlcCntxt_t gRlcContext;

void InitRlcContext(void)
{
   U16 i = 0;

   DEBUG4(("ENTRY == InitRlcContext\n"));
   memset(&gRlcContext,  0, sizeof(RlcCntxt_t));

   gRlcContext.cellId                                   = 0;
   // Rach : Used for Rach (RRC Conn Req Msg)       
   gRlcContext.rlcUlCcchCntxt.logChInfo[0].lchType     = LOG_CH_CCCH_E;
   gRlcContext.rlcUlCcchCntxt.logChInfo[0].logChId     = 0;
   gRlcContext.rlcUlCcchCntxt.logChInfo[0].dir         = DIR_UL_E;
   gRlcContext.rlcUlCcchCntxt.logChInfo[0].rlcMode     = RLC_MODE_TM_E;
   // Fach 0: Used for Fach (RRC Conn Setup Msg)       
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].lchType     = LOG_CH_CCCH_E;
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].logChId     = 0;
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].dir         = DIR_DL_E;
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].rlcMode     = RLC_MODE_UM_E;
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].nxtSn       = 0; //Starting with Sn 1
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].snLen       = 7; // 7 bit
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].boData      = 0;
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].boCtrl      = 0;
   gRlcContext.rlcDlCcchCntxt.logChInfo[0].ctrlPduPres = FALSE_E;

   // Initialize SRB Default Configuration for RLC
   gRlcContext.srbRlcDftCfg.numLogCh                 = 4;
   for(i=0; i< gRlcContext.srbRlcDftCfg.numLogCh;  i++)
   {
      // SRB-DL LogCh Config
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].logChId.logChType        = LOG_CH_DCCH_E;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].logChId.logChId          = i + 1;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].pduSize                  = 144;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].logChPrio                = i + 1;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].transmissionWindowSize   = 32;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].timerRST                 = 300;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].maxRST                   = 4;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].pollTimer                = 150;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].pollPdu                  = 4;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].pollSdu                  = 1;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].lastTransmissionPduPoll  = TRUE_E;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].lastRetransmissionPduPoll= TRUE_E;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].pollWindow               = 70;
      // SRB-UL LogCh Config
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].logChId.logChType        = LOG_CH_DCCH_E;
      gRlcContext.srbRlcDftCfg.dlLogChCfg[i].logChId.logChId          = i + 1;
      gRlcContext.srbRlcDftCfg.ulLogChCfg[i].pduSize                  = 144;
      gRlcContext.srbRlcDftCfg.ulLogChCfg[i].logChPrio                = i + 1;
      gRlcContext.srbRlcDftCfg.ulLogChCfg[i].inSequenceDelivery       = TRUE_E;
      gRlcContext.srbRlcDftCfg.ulLogChCfg[i].receivingWindowSize      = 32;
      gRlcContext.srbRlcDftCfg.ulLogChCfg[i].missingPduIndicator      = TRUE_E;
   }

   // No NEED TO MEMSET INDIVIDUAL FIELDS, memset &gRlcContext at start. And fill other values on Top

   return;
} /*End of InitRlcContext*/

void *GetRlcLogChContext(U16 ueIdx, Direction_e dir, LogChType_e logChType, U16 logChId)
{
   switch(logChType)
   {
   case LOG_CH_CCCH_E:
      {
         switch(dir)
         {
         case DIR_DL_E:
            //logChInfo []: index 0 used for FACH
            return ( (void *)& (gRlcContext.rlcDlCcchCntxt.logChInfo[0]));
         case DIR_UL_E:
         default:
            DEBUG4(("ERROR === SDU CONTEXT FOR UL_CCCH NOT HANDLED For NOW\n"));
         
         }
      }
   case LOG_CH_DCCH_E:
      {
         switch(dir)
         {
         case DIR_DL_E:
            // TBD: DL_RLC
            return( (void *)& (gRlcContext.rlcUeCntxt[ueIdx].dlLogChInfo[logChId]));
         case DIR_UL_E:
            return( (void *)& (gRlcContext.rlcUeCntxt[ueIdx].ulLogChInfo[logChId]));
         default:
            DEBUG4(("ERROR === SDU CONTEXT FOR UL_CCCH NOT HANDLED For NOW\n"));
         
         }
      }
   }

   return NULL;
} /*End of InitRlcContext*/

GetSrbCfg(U16 ueIdx, U16 logChId)
{
   // Dummy 
}
