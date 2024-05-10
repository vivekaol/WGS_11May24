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
 * File Name	 : rlcContext.h
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/11/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef RLC_CONTEXT_H
#define RLC_CONTEXT_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"
#include "l2Cmn.h"
#include "rlc.h"
#include "rlcUmData.h"
#include "rlcAmData.h"

typedef struct _LchUlCntxt
{
   LogChType_e   lchType;
   U16           logChId;
   Direction_e   dir;  //direction DIR_DL_E/DIR_UL_E
   RlcMode_e     rlcMode;

} LchUlTmCntxt_t;

// RLC RACH CONTEXT. As There is no RACH in RLC only UL_CCCH which maps to RACH
typedef struct _RlcUlCcchCntxt
{
  #define MAX_UL_CCCH_LCH_NUM 1
  LchUlTmCntxt_t logChInfo[MAX_UL_CCCH_LCH_NUM];
}RlcUlCcchCntxt_t;

typedef struct _RlcDlCcchCntxt
{
  // Paging and FACH, using Idx 0 for Fach
  #define MAX_DL_CCCH_LCH_NUM 2
  LchDlUmCntxt_t logChInfo[MAX_DL_CCCH_LCH_NUM];

}RlcDlCcchCntxt_t ;

typedef struct _UlLogChCfg
{
   LogChId_t    logChId;
   U16          pduSize;
   U16          logChPrio;
   // UL/Rx
   U16          transmissionWindowSize;
   U16          timerRST;
   U16          maxRST;
   U16          pollTimer;  /*ms */
   U16          pollPdu;
   U16          pollSdu;
   U16          lastTransmissionPduPoll;
   U16          lastRetransmissionPduPoll;
   U16          pollWindow;
   // DL/Tx
   U16          inSequenceDelivery;
   U16          receivingWindowSize;
   U16          missingPduIndicator;

}LogChCfg_t;

typedef struct _SrbRlcDftCfg
{
   U16           numLogCh;
   LogChCfg_t    dlLogChCfg[MAX_DCH_LOG_CH_PER_UE];
   LogChCfg_t    ulLogChCfg[MAX_DCH_LOG_CH_PER_UE];

}SrbRlcDftCfg_t; 

typedef struct _RlcDlLogChInfo
{
   RlcMode_e    rlcMode;
   union _RlcDlContxt
   {
      LchDlUmCntxt_t umCntxt;
      LchDlAmCntxt_t amCntxt;
      //LchDlTmCntxt_t tmCntxt;
   }u;
}RlcDlLogChInfo_t; 

typedef struct _RlcUlLogChInfo
{
   RlcMode_e    rlcMode;
   union _RlcUlContxt
   {
      LchUlUmCntxt_t umCntxt;
      LchUlAmCntxt_t amCntxt;
      LchUlTmCntxt_t tmCntxt;
   }u;
   // State Variables based on RLC Mode
}RlcUlLogChInfo_t; 

typedef struct _RlcUeCntxt
{
  U16                inUse;
  U16                numLogCh;
  // We are supporting only SRB => Max log Ch num = 4
  // Logical Channed Id used as index
  RlcDlLogChInfo_t   dlLogChInfo[MAX_DCH_LOG_CH_PER_UE];
  RlcUlLogChInfo_t   ulLogChInfo[MAX_DCH_LOG_CH_PER_UE];
}RlcUeCntxt_t;

// ----------- RLC Context 
typedef struct _RlcCntxt
{
   U16              cellId;
   RlcUlCcchCntxt_t rlcUlCcchCntxt;
   RlcDlCcchCntxt_t rlcDlCcchCntxt;
   SrbRlcDftCfg_t   srbRlcDftCfg;
   U16              numUe;
   RlcUeCntxt_t     rlcUeCntxt[RLC_MAX_UE_NUM + 1]; /*As treating UeIdx 0 as invalid*/

}RlcCntxt_t;

extern RlcCntxt_t gRlcContext;
void InitRlcContext(void);
void *GetRlcLogChContext(U16 ueIdx, Direction_e dir, LogChType_e logChType, U16 logChId);
#endif
