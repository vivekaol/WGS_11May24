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
 * File Name	: macCfgHndlr.c 
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
#include "cmnDs.h"
#include "macContext.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = mac;

void MacCfgDelReq( U32 ueIdx)
{
   U16  i = 0;
   if(gMacContext.ueCfg[ueIdx].inUse  != TRUE_E)
   {
      DEBUG1(("MAC: ==== ERROR ==: COFIGURATION FAILURE - UE Index not in Use Cant delete \n"));
      return;
   }
   memset( &gMacContext.ueCfg[ueIdx], 0, sizeof(MacUeCfg_t ));
   gMacContext.numUe--;
   DEBUG4(("RLC:====== Config Delete for ueIdx(%d) Success \n", ueIdx));

   return;
}

void MacUeCfgReq( U32 ueIdx)
{
   U16  i = 0;
   // Use the UeIdx sent by RRC to allocate the resources.
   // Ue Index allocation logig will be taken care by RRC.

   // Validation - Check if this user is free at this point
   if(gMacContext.ueCfg[ueIdx].inUse  == TRUE_E)
   {
      DEBUG1(("ERROR: MAC COFIGURATION FAILURE - UE Index already in Use \n"));
      return;
   }
   memset( &gMacContext.ueCfg[ueIdx], 0, sizeof(MacUeCfg_t ));

   gMacContext.numUe++;
   gMacContext.ueCfg[ueIdx].inUse               = TRUE_E;
   gMacContext.ueCfg[ueIdx].ueId.ueIdx          = ueIdx; 
   gMacContext.ueCfg[ueIdx].idType              = ID_TYPE_UE_IDX_E;
   gMacContext.ueCfg[ueIdx].crnti               = ueIdx;
   gMacContext.ueCfg[ueIdx].urnti               = 0; // NOT USED FOR NOW
   gMacContext.ueCfg[ueIdx].numTrch             = 1; // For Signaling only one DCH Trch
   gMacContext.ueCfg[ueIdx].dchCfg[0].trchId         = 1;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macTfSet.numTf = 2;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macTfSet.macTf[0].blockNum  = 0;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macTfSet.macTf[0].blockSize = 148;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macTfSet.macTf[1].blockNum  = 1;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macTfSet.macTf[1].blockSize = 148;
   //gMacContext.ueCfg[ueIdx].dchCfg[0].macHdrType                = //NOT USED FOR NOW 
   gMacContext.ueCfg[ueIdx].dchCfg[0].macHdrLen                   = 4; // Header length in Bits
   // ---- MAC HDR INFO USED TO STORE TB DECODE INFO, All info invalid at this point
   //gMacContext.ueCfg[ueIdx].dchCfg[0].macDchHdr.tctfChType        = TCTF_CH_TYPE_DCCH_E;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macDchHdr.idType            = ID_TYPE_INVLID_E;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macDchHdr.id.cellId         = 0;
   //gMacContext.ueCfg[ueIdx].dchCfg[0].macRachHdr.r.macCt        = //NOT USED FOR NOW
   gMacContext.ueCfg[ueIdx].dchCfg[0].macDchHdr.macLogChType      = LOG_CH_INVLID_E;
   gMacContext.ueCfg[ueIdx].dchCfg[0].macPduOffset                = 0;

   for(i = 1; i < MAC_MAX_LOG_CH_UE_NUM; i++)
   {
      gMacContext.ueCfg[ueIdx].logChinfo[i].logChType             = LOG_CH_DCCH_E;
      gMacContext.ueCfg[ueIdx].logChinfo[i].logChId               = i;
      gMacContext.ueCfg[ueIdx].logChinfo[i].idType                = ID_TYPE_UE_IDX_E;
      gMacContext.ueCfg[ueIdx].logChinfo[i].ueCellId.ueIdx        = ueIdx;
   }

   DEBUGMSG(("RLC:====== Config for ueIdx(%d) Success \n", ueIdx));
   return;
}
