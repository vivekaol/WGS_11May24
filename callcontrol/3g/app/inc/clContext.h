/*
 *############################################################################
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
 *############################################################################
 */
/*
 *############################################################################
 * File Name   : clContext.h 
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 *############################################################################
 */
#ifndef _CL_CONTEXT_H_
#define _CL_CONTEXT_H_
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "cmnDs.h"
#include "clL1RcvMsg.h"
#include "timer.h"

#define L1_CPLANE_RSP_MAX_BUF_SIZE 1000
#define L1_UPLANE_MAX_BUF_SIZE     2000
#define MAX_BIND_ID_MAPPING_ENTRY  100
#define INVALID_MAPPING_IDX        (0) 
#define INVALID_RL_TRANSACTION_ID  -1
#define INVALID_MEAS_TRANSACTION_ID  -1
#define INVALID_BIND_ID            -1
#define MAX_FACH_NUM               2
#define CL_MAX_UE_SUPPORTED        100
#define CL_MAX_DCH_SUPPORT         1
#define CL_CELL_RECONFIG_TIMEOUT   500
#define CL_SYS_INFO_UPDATE_TIMEOUT 500

typedef struct _DchIdBindIdMap
{
   U16   dchId;
   U32   bindId;
}DchIdBindIdMap_t;

typedef struct _ClUeCntxt_t
{
   // Index of UeContext is UeIdx/RlIdx
   S16               nodebCmnCntxt;
   S16               rlDelTransId;
   S16               DedRttMeasTermTransId;
   S16               DedRscpMeasTermTransId; 
   U16               numDch;
   DchIdBindIdMap_t  bindIdToDchMap[CL_MAX_DCH_SUPPORT];
}ClUeCntxt_t;

/*
 * CL States
 */
typedef enum
{
    CL_CELL_IDLE,
    CL_WAIT_FOR_MODEM_SETUP_RESP,
    CL_WAIT_FOR_CELL_DELETE_RESP,
    CL_WAIT_FOR_CELL_SETUP_RESP,
    CL_WAIT_FOR_CELL_RECONFIG_RESP,
    CL_WAIT_FOR_BRING_UP_SYSTEM_INFO_UPDATE_RESP,
    CL_WAIT_FOR_ONLINE_CPICH_SYSTEM_INFO_UPDATE_RESP,
    CL_WAIT_FOR_ONLINE_SYSTEM_INFO_UPDATE_RESP,
    CL_WAIT_FOR_SCCPCH_SETUP_RESP,
    CL_WAIT_FOR_PRACH_SETUP_RESP,
    CL_CELL_ACTIVE 
}NbapCellState;

typedef struct _ClCntxt_t
{
   U32           bfn;
   U32           cPlaneTrnsId;
   U32           uPlaneTrnsId;
   U8            uPlaneL1DataBuf[L1_UPLANE_MAX_BUF_SIZE];
   U8            cPlaneL1RspBuf[L1_CPLANE_RSP_MAX_BUF_SIZE];
   U16           numFachCh;
   U32           fachL1BindId[MAX_FACH_NUM]; //Bind Id for Fach Channel
   U32           pchL1BindId;
   U16           rachBindId;                 //Binding Id for Rach Channel
   ClUeCntxt_t   clUeCntxt[CL_MAX_UE_SUPPORTED];
   NbapCellState cellState;
   tcbTimer_t    cellTimer;
} ClCntxt_t;

extern ClCntxt_t                  gClCntxt;
#endif


