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
 * File Name   : taskHndlr.h
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 *############################################################################*/
#ifndef _TASK_HNDLR_H_
#define _TASK_HNDLR_H_
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "cmnDs.h"
#include "cmnPf.h"
#include "msgQue.h"
#include "stddef.h"
#include "stdio.h"
/* -----------------------------------------------------
 *           MACRO Definitions 
 * ----------------------------------------------------- */

/* -----------------------------------------------------
 *           Data Structures for Msg Queue
 * ----------------------------------------------------- */
typedef struct _TaskCntxt{
   U16          inUse;
   TaskId_e     taskId;
   ThrdId_e     thrdId;  // Thread Id where this Task is mapped.
   MsgQueId_e   msgQId;  // msgQueue Id where this Task is mapped. 

}TaskCntxt_t;

// thread context is read from DstTask Used to put msg in correct MsgQueue
typedef struct _ThrdCntxt{
   U16          inUse;
   ThrdId_e     thrdId;
   MsgQCntxt_t *msgQCntxt; //Context of msg queue. Used in scheduler and Msg send/recv
}ThrdCntxt_t;


/* -----------------------------------------------------
 *     Extern Decleration of function and Global Var 
 * ----------------------------------------------------- */
extern ThrdCntxt_t gThrdCntxt[MAX_THREAD_NUM_E];
extern TaskCntxt_t gTaskCntxt[MAX_TASK_NUM_E];

void InitThrdCntxt(void);
void InitTaskCntxt(void);
ErrorCode_e CreateTask(TaskId_e taskId, ThrdId_e thrdId, MsgQueId_e msgQueId);
ErrorCode_e CreateThrdCntxt(ThrdId_e thrdId, MsgQCntxt_t *msgQCntxt);
ErrorCode_e CreateMsgQue(MsgQueId_e msgQueId, MsgQHndlr_f msgQueHndlrFunc);
ErrorCode_e SendMsgToTask(TaskId_e  srcTaskId, TaskId_e dstTaskId, MsgType_e msgType,   void     *msgBuf);
void SchedTaskInThrd(ThrdCntxt_t *thrdCntxt);
#endif
