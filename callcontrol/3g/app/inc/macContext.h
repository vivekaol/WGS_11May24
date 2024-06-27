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
 * File Name	 : macContext.h 
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 15/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef MAC_CONTEXT_H
#define MAC_CONTEXT_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"
#include "macUlDataHndlr.h"
#include "macRlcInterface.h"
#include "rrc.h"

#define CELL_ID_FIRST_CELL     1
#define MAC_FACH_HDR_BYTE_LEN  1
#define MAC_DCH_RLC_DATA_BIT_OFFSET  4
#define MAC_DCH_HDR_BIT_LEN          4
// Sfn range 0 - 4095
#define INCREMENT_SFN(sfn)    ((sfn + 1) % 4096)
#define GET_FACH_BO()         (gMacContext.fachCfg.bo)
#define GET_DCH_BO(udIdx)     (gMacContext.ueCfg[ueIdx].perUeBo)
#define MAX_FACH_RLC_PDU_NUM   2
#define MAC_MAX_UE_NUM         100
#define MAC_MAX_LOG_CH_UE_NUM  5
#define MAC_MAX_DCH_TRCH_NUM   1
#define MAX_PAGING_CNT_UE_OUT_OF_COVERAGE 10

#ifdef FXL_BL_UE_POWER_OFF
#define MAX_PAGING_CNT_UE_POWER_OFF 1
#endif

typedef struct _MacTf_t
{
   U16    blockNum;
   U16    blockSize;

} MacTf_t;

typedef struct _MacTfSet_t
{
   U16      numTf;
#define MAX_MAC_TF_NUM  32
   MacTf_t  macTf[MAX_MAC_TF_NUM];
   
}MacTfSet_t;

typedef struct _MacRachCfg_t 
{
   U16        trchId;
   MacTfSet_t macTfSet;     // RACH TFCS Config
   U16        macHdrType;
   U16        macHdrLen;    // MAC Header Length in bits
   MacHdr_t   macRachHdr;   // Used for temp Rach header storage, for a TTI
   U16        macPduOffset; // Pdu offset in bits

}MacRachCfg_t;

typedef struct _MacFachCfg_t
{
   U16                     trchId;       // For SRB all LogCh mapped to same Trch
   MacTfSet_t              macTfSet;     // FACH TFCS Config
   S16                     bo;           // FACH BO used for MAC scheduling
#define MAX_MAC_HDR_SIZE 1
   U16                     macHdrLen;    // MAC Header Length in bits
   U8                      macFachHdr[MAX_MAC_HDR_SIZE]; //MAX MAC HDR Size is 1Byte
   LogChId_t               logChinfo;
 
}MacFachCfg_t;

typedef struct _MacDchCfg_t 
{
   U16        trchId;
   MacTfSet_t macTfSet;     // RACH TFCS Config
   U16        macHdrType;
   U16        macHdrLen;    // MAC Header Length in bits
   MacHdr_t   macDchHdr;   // Used for temp Rach header storage, for a TTI
   U16        macPduOffset; // Pdu offset in bits

}MacDchCfg_t;

typedef struct _MacUeCfg_t
{
   U16            inUse; 
   Identifier_u   ueId;
   IdType_e       idType;
   U16            crnti;  // NOT USED FOR NOW
   U32            urnti;  // NOT USED FOR NOW
   U16            numTrch; // =1 only one DCH
   MacDchCfg_t    dchCfg[MAC_MAX_DCH_TRCH_NUM];
   S16            perUeBo;
   LogChId_t      logChinfo[MAC_MAX_LOG_CH_UE_NUM];
   U16            perLogChBo[MAC_MAX_LOG_CH_UE_NUM];// Use logChId as Index for getting Bo
}MacUeCfg_t;

typedef struct _MacContext
{
   U16            cellId;
   U32            curSfn;
   U8             macCellCfn; // This will have lower 8 bits of SFN
   MacRachCfg_t   rachCfg;
   MacFachCfg_t   fachCfg;
   U8             numUe;
#if 0 //LET RRC/APP TAKE CARE OF UE ID allocation. 
   U8             firstUeIdx;
   U8             lastUeIdx;
   U8             firstFreeUeIdx;
   U8             lastFreeIdx;
#endif
   MacUeCfg_t     ueCfg[MAC_MAX_UE_NUM + 1];
   // TBD: In future make a list of UEs which have valid bo, in list pointer can point to actual UeCfg

} MacContext_t;

/*
 * MAC Paging Context
 */
#define MAX_PCCH_MSG       100
typedef struct _MacPagingContext
{
   unsigned int numOfPagingMsg;
   RrcPcchMsg  *pPcchMsg[MAX_PCCH_MSG];
}MacPagingContext_t;

extern MacContext_t gMacContext;

void MacTtiIndHndlr(U32 bfn);
void InitMacCellContext(void);
void InitMacRachContext(void);
void InitMacFachContext(void);
void InitMacUeContext(void);
void InitRlcContext(void);
void MacUeCfgReq( U32 ueIdx);
void InitMacPagingContext (void);
void MacClaenupMacPagingContext(void);
void MacAddPcchMsgToMacPagingContext (RrcPcchMsg *pPcchMsg);
void MacDelPcchMsgFromMacPagingContext(char * imsi,unsigned int freeImsiMemFlag);

MacRachCfg_t *getRachCfg(void );
MacDchCfg_t  *getDchCfg(U16 ueIdx);
#endif
