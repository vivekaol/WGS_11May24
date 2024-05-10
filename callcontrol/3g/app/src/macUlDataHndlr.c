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
 * File Name	 : macUlDataHndlr.c
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "macUlDataHndlr.h"
#include "macContext.h"
#include "macRlcInterface.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = mac;

ErrorCode_e DecodeReadRachTctf(MacRachCfg_t *rachCfg, U8 *rachBuf)
{
   ErrorCode_e retVal = SUCCESS_E;

   DEBUG4((" RACH Header Byte(%2x)",*rachBuf));
   // get First 2 bits, which have TCTF Values 
   switch(((*rachBuf) && 0xc0) >> 6)
   //switch(((*rachBuf) >> 6)&& 0x0x03)
   {
       case 0: /*TCTF Value 0b00*/
          DEBUG4(("RACH Decode TCTF: CCCH over RACH\n"));
          rachCfg->macRachHdr.macLogChType = LOG_CH_CCCH_E;
          break;
       case 1:
          DEBUG4(("DTCH or DCCH over RACH. INVALID FOR NOW\n"));
          /* Intentional Fall through*/
       default:
          DEBUG4((" Reserved/Invalid Msg \n"));
          rachCfg->macRachHdr.macLogChType = LOG_CH_INVLID_E;
          retVal = ERROR_L2_RACH_HDR_DECODE_FAIL_E;
          break;
   }
   /*2 initial bit read in TCTF, update offset for data*/
   rachCfg->macPduOffset          = 2;

   return retVal;
}

ErrorCode_e DecodeRachHdr(MacUlDataInd_t *rachDataInd, MacRachCfg_t *rachCfg)
{
   U16 idx = 0;
   ErrorCode_e retCode = SUCCESS_E;
   // TBD: Add functionality, For now Dummy placeholder
   DEBUG4(("====  ENTRY Decode Rach Header ===\n"));

   // Update header field in rachCfg.macRachHdr
   //rachCfg->macRachHdr.tctfChType = TCTF_CH_TYPE_CCCH_E;
   rachCfg->macRachHdr.idType     = ID_TYPE_CELL_ID_E;
   rachCfg->macRachHdr.id.cellId  = CELL_ID_FIRST_CELL;
   for(idx  = 0; idx < rachDataInd->numTb; idx++)
   {
      if(idx > 0)
      {
         DEBUG1((COLOR_TXT_RED "MAC: === ERROR ===Two TB received in RACH. Add Handling\n" COLOR_TXT_RST ));
         retCode = ERROR_GENERIC_FAILURE_E;
         break;
      }
      if(rachDataInd->crci[idx] == TRUE_E)/*CRC Error Drop packet*/
      {
         // KULDEEP : TBD
         DEBUG1((COLOR_TXT_RED "MAC: === ERROR === CRC Error in RACH TB. Dropping RACH TB in MAC\n" COLOR_TXT_RST));
         return ERROR_L2_DATA_CRC_ERROR_E;
         break;
      }
      retCode = DecodeReadRachTctf(rachCfg, rachDataInd->ulDataBuf);
   }

   return retCode;
} /* End of DecodeRachHdr */

ErrorCode_e DecodeDchHdr(MacUlDataInd_t *dchDataInd, MacDchCfg_t *dchCfg)
{
   U16 idx = 0;
   U8  extBits = 0;
   ErrorCode_e retCode = SUCCESS_E;

   DEBUG4((" Decode Dch Header ===\n"));
   for(idx  = 0; idx < dchDataInd->numTb; idx++)
   {
      if(idx > 0)
      {
         DEBUG4((COLOR_TXT_RED "MAC: === ERROR === Two TB received in DCH. Add Handling\n" COLOR_TXT_RST ));
         retCode = ERROR_GENERIC_FAILURE_E;
         break;
      }
      if(dchDataInd->crci[idx] == TRUE_E)/*CRC Error Drop packet*/
      {
         // KULDEEP : TBD
         DEBUG1((COLOR_TXT_RED "MAC: === ERROR === CRC Error in DCH TB. Dropping DCH TB in MAC\n" COLOR_TXT_RST));
         return ERROR_L2_DATA_CRC_ERROR_E;
         break;
      }
   }
   // Update header field in rachCfg.macRachHdr
   // TBD: HARD CODING TO READ 4 Bits of CT Field. Remove in future
   DEBUG3(("Decode CT Filled , byte 0(%3x)\n", dchDataInd->ulDataBuf[0]));
   dchCfg->macDchHdr.macCt.logChId = ((dchDataInd->ulDataBuf[0] & ((U8 )0xf0)) >> 4) + 1;
   dchCfg->macDchHdr.macLogChType  = LOG_CH_DCCH_E;
   dchCfg->macPduOffset            = 4;                                // TBD- 4 bit of CT Field, MAC Header

   return retCode;
} /* End of DecodeDchHdr*/

void ProcMacPdu(MacUlDataInd_t *rachDataInd, MacRachCfg_t *rachCfg)
{
   // TBD: Add functionality, For now Dummy placeholder
   DEBUG3(("== Process Rach Header ===\n"));

   return;

} /* End of ProcMacPdu*/

      
void StripMacHdr( U8 *dataBuf, U16 len, U16 macHdrLen)
{
   U16   i = 0;

   len -= macHdrLen;
   while(len > 0)
   {
      // Decrease By a Byte, Processing One Byte in one iteration
      dataBuf[i] = (dataBuf[i] << macHdrLen) | (dataBuf[i+1] >> macHdrLen) ;
      len -= 8; 
      i++;
   }
}

void RachDataIndHndlr(MacUlDataInd_t *rachDataInd)
{
   U16           blockSize = 0;
   U16           blockNum  = 0, i;
   MacRachCfg_t  *rachCfg;
   //RlcDataInd_t  *rlcDataInd = NULL;
   RlcDataInd_t  rlcDataInd;
   ErrorCode_e   retVal = SUCCESS_E;

   DEBUG4(("ENTRY ==== RachDataIndHndlr \n"));
   rachCfg   = getRachCfg();
   // Decode RACH Header
   if(SUCCESS_E != DecodeRachHdr(rachDataInd, rachCfg))
   {
      DEBUG1(("ERROR === RACH Decode Failure !! Dropping RACH TB\n"));
      free(rachDataInd->ulDataBuf);
      free(rachDataInd);
      return;
   }

   blockNum  = rachCfg->macTfSet.macTf[rachDataInd->tfi].blockNum;
   blockSize = rachCfg->macTfSet.macTf[rachDataInd->tfi].blockSize;
   DEBUG4((" RachDataIndHndlr: DataInd- tfi(%d),\n", rachDataInd->tfi));
   DEBUG4(("MAC:==== RachDataIndHndlr: Config- blockNum(%d), blockSize(%d)\n", blockNum, blockSize));
#if 0
   printf("MAC:==== RACH BUFFER: ===============================================\n");
   for(i = 0; i < ((blockSize >> 3) + 1);i++)
   {
      printf(" %02x,",rachDataInd->ulDataBuf[i]);
      if((i%12 == 0) && (i > 0))
         printf("\n");
   } printf("\n");
#endif
   //rlcDataInd   = (RlcDataInd_t *) malloc(sizeof (RlcDataInd_t));
   // TBD Change the interface, no need to allocate memory as this in function call. Not a msg post
   rlcDataInd.logChInfo.logChType         = rachCfg->macRachHdr.macLogChType;
   rlcDataInd.logChInfo.logChId           = 0; /*In Case of RACH/CCCH no need of logChId*/
   rlcDataInd.logChInfo.idType            = ID_TYPE_CELL_ID_E;
   rlcDataInd.logChInfo.ueCellId.cellId   = 0;//CELL_ID_E;
   rlcDataInd.rlcDataInfo.numPdu          = blockNum;
   rlcDataInd.rlcDataInfo.pduSize         = blockSize - rachCfg->macPduOffset; //RACH Header size
   rlcDataInd.rlcDataInfo.pduBuf          = rachDataInd->ulDataBuf;
   rlcDataInd.rlcDataInfo.dataOffset      = rachCfg->macPduOffset; //RACH Header size
   rlcDataInd.propDelay                   = rachDataInd->propDelay; 

   DEBUG4(("\nSend Data To Rlc Interface ======== \n"));
   rlcRachDataInd(&rlcDataInd);
   free(rachDataInd);

   return;
} /*End of RachDataIndHndlr*/

void DchDataIndHndlr(MacUlDataInd_t *dchDataInd)
{
   U16           blockSize = 0;
   U16           blockNum  = 0, i;
   U16           ueIdx = 0;
   MacDchCfg_t  *dchCfg;
   RlcDataInd_t  rlcDataInd;
   ErrorCode_e   retVal = SUCCESS_E;

   ueIdx    = dchDataInd->ueIdx;
   DEBUG4(("MAC: === Entry: DchData received for ueIdx(%d) === \n", ueIdx));
   dchCfg   = getDchCfg(ueIdx);

   blockNum  = dchCfg->macTfSet.macTf[dchDataInd->tfi].blockNum;
   blockSize = dchCfg->macTfSet.macTf[dchDataInd->tfi].blockSize;
   DEBUG4(("MAC: === DchDataIndHndlr: DataInd- DataLen(%d), tfi(%d),\n", dchDataInd->dataLen, dchDataInd->tfi));
   DEBUG4(("MAC: === DchDataIndHndlr: Config- blockNum(%d), blockSize(%d)\n", blockNum, blockSize));

   DEBUG4(("MAC: === DCH Data Ind BUFFER: \n"));
#if 0
   for(i = 0; i < dchDataInd->dataLen; i++)
   {
      printf(" %02x,",dchDataInd->ulDataBuf[i]);
      if((i%12 == 0) && (i > 0))
         printf("\n");
   } printf("\n");
#endif

   {
      if(blockNum != 1 || (blockSize == 0))
	  {
         DEBUG1(("ERROR === Error 2 TBs in a TTI not configured. 2TB received Drop TB\n"));
         free(dchDataInd->ulDataBuf);
         free(dchDataInd);
         return;
      }
      // Decode MAC Header
      // TBD: Current Decoder assuming only 1 TB MAX of size 148
      if(SUCCESS_E != DecodeDchHdr(dchDataInd, dchCfg))
      {
         DEBUG1((" ERROR === ueIdx (%d) DCH Decode Failure !! Dropping DCH TB\n", ueIdx));
         free(dchDataInd->ulDataBuf);
         free(dchDataInd);
         return;
      }
      StripMacHdr( dchDataInd->ulDataBuf, blockSize, dchCfg->macPduOffset);
      rlcDataInd.logChInfo.logChType         = dchCfg->macDchHdr.macLogChType;
      rlcDataInd.logChInfo.logChId           = dchCfg->macDchHdr.macCt.logChId;
      rlcDataInd.logChInfo.idType            = ID_TYPE_UE_IDX_E;
      rlcDataInd.logChInfo.ueCellId.ueIdx    = ueIdx;
      rlcDataInd.rlcDataInfo.numPdu          = 1;
      rlcDataInd.rlcDataInfo.pduSize         = (blockSize - dchCfg->macPduOffset);
      rlcDataInd.rlcDataInfo.pduBuf          = dchDataInd->ulDataBuf;
      rlcDataInd.rlcDataInfo.dataOffset      = 0;
      DEBUG4(("MAC: === Send Data To Rlc Interface ======== \n"));
      rlcDchDataInd(&rlcDataInd, ueIdx);
   }

   // free(dchDataInd->ulDataBuf);  --> Use same buffer in RLC till it is sent to RRC
   free(dchDataInd);

   return;
} /*End of DchDataIndHndlr*/
