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

/*############################################################################
 * File Name   : taskHndlr.c 
 *
 * Description : This file has Task related handling of Platform
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 19/09/2014	   Kuldeep S. Chauhan            File Creation
 *############################################################################ */
 
/* -----------------------------------------------------
 *           Include Files
 * ----------------------------------------------------- */
#include "taskHndlr.h"
#include "errorCode.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = cmn;

/*---------- Global Data Structures --------------------*/
ThrdCntxt_t gThrdCntxt[MAX_THREAD_NUM_E];
TaskCntxt_t gTaskCntxt[MAX_TASK_NUM_E];

/* -----------------------------------------------------
 *            Msg Queue Utility Function 
 * ----------------------------------------------------- */
void InitThrdCntxt(void)
{
   U16 idx = 0;

   DEBUG4(("===== Init Thrd Cntxt(%d) ========\n"));
   // Initialize ThreadContext to dummy  values(0,NULL,INVALID etc)
   for(idx =  0; idx < MAX_THREAD_NUM_E; idx++)
   {
      gThrdCntxt[idx].inUse          = FALSE_E;
      gThrdCntxt[idx].thrdId         = INVALID_THRD_ID_E;
      gThrdCntxt[idx].msgQCntxt      = NULL;
   }
   
} /* End of InitThrdContxt*/

void InitTaskCntxt(void)
{
   DEBUG4(("===== Init Task Cntxt(%d) ========\n"));
   U16  idx = 0;
   for(idx =  0; idx < MAX_TASK_NUM_E; idx++)
   {
      gTaskCntxt[idx].inUse            = FALSE_E;
      gTaskCntxt[idx].taskId           = INVALID_TASK_E;
      gTaskCntxt[idx].thrdId           = INVALID_THRD_ID_E;
      gTaskCntxt[idx].msgQId           = INVALID_MSG_QUEUE_ID;
   }
} /* End of InitTaskContxt*/

ErrorCode_e CreateTask(TaskId_e taskId, ThrdId_e thrdId, MsgQueId_e msgQueId) 
{
   // TASK Context create
   DEBUG4(("===== Create Task with Task Id(%d), msgQueId(%d)========\n",taskId, msgQueId));
   gTaskCntxt[taskId].inUse             = TRUE_E;
   gTaskCntxt[taskId].taskId            = taskId;
   gTaskCntxt[taskId].thrdId            = thrdId;
   gTaskCntxt[taskId].msgQId            = msgQueId;

   return SUCCESS_E;
}

ErrorCode_e CreateThrdCntxt(ThrdId_e thrdId, MsgQCntxt_t *msgQCntxt)
{
   DEBUG4(("===== Create Thrd thrdId(%d)========\n",thrdId));
   // THREAD Context create
   gThrdCntxt[thrdId].inUse             = TRUE_E;
   gThrdCntxt[thrdId].thrdId            = thrdId;
   //When multiple thread are Introduced define gMsgQCntxt as array
   gThrdCntxt[thrdId].msgQCntxt         = msgQCntxt; 

   return SUCCESS_E;
}

ErrorCode_e SendMsgToTask(TaskId_e  srcTaskId, TaskId_e dstTaskId, 
                          MsgType_e msgType,   void     *msgBuf)
{
   MsgQCntxt_t  *msgQCntxt;
   MsgQueue_t   *msgQue;
   MsgQueId_e   msgQId = gTaskCntxt[dstTaskId].msgQId; 

   msgQCntxt   = gThrdCntxt[(gTaskCntxt[dstTaskId].thrdId)].msgQCntxt;
#if 0
   printf("===== SEND MSG : srcTaskId(%d), dstTaskId(%d), msgQId(%d), inUse(%d) msgType(%d)---- \n", 
                            srcTaskId, dstTaskId, msgQId, msgQCntxt->msgQLst[(msgQId)].inUse, msgType);
#endif
   if((msgQCntxt->msgQLst[(msgQId)].inUse != TRUE_E) || (msgQId >= MAX_MSG_QUEUE_NUM_E))
   {
      DEBUG4((COLOR_TXT_RED));
      DEBUG1(("===== ERROR SEND MSG: INVALID MESSAGE QUEUE: srcTaskId(%d), dstTaskId(%d), msgQId(%d), inUse(%d) msgType(%d)---- \n",
                            srcTaskId, dstTaskId, msgQId, msgQCntxt->msgQLst[(msgQId)].inUse, msgType));
      DEBUG4((COLOR_TXT_RST));
      return ERROR_MSG_QUEUE_INVALID_E;
   }
   //Get Message Queue
   msgQue      = & ( msgQCntxt->msgQLst[(msgQId)] );
#if 0
   printf("===== MESSAGE QUEUE Params. msgQId(%d), numMsgInQ(%d), fixstiMsgIdx(%d), lastMsgIdx(%d)\n", 
                                       msgQId, msgQue->numMsgInQ, msgQue->firstMsgIdx, msgQue->lastMsgIdx);
#endif

   if((msgQue->numMsgInQ >= MAX_MSG_QUEUE_SIZE ) || (msgQue->firstMsgIdx == QUEUE_ADD_MSG_IDX(msgQue->lastMsgIdx, 1)))
   {
      DEBUG1((COLOR_TXT_RED));
      DEBUG1(("===== ERROR: MESSAGE QUEUE FULL. msgQId(%d), numMsgInQ(%d), fixstiMsgIdx(%d), lastMsgIdx(%d)\n", 
                             msgQId, msgQue->numMsgInQ, msgQue->firstMsgIdx, msgQue->lastMsgIdx));
      DEBUG1((COLOR_TXT_RST));
      return ERROR_MSG_QUEUE_FULL_E;
   }
   pthread_mutex_lock(&(msgQCntxt->mutexQueLock));

   // Add Message to Msg Queue
   msgQue->msgInQue[msgQue->lastMsgIdx].srcTaskId  = srcTaskId;
   msgQue->msgInQue[msgQue->lastMsgIdx].dstTaskId  = dstTaskId;
   msgQue->msgInQue[msgQue->lastMsgIdx].msgType    = msgType;
   msgQue->msgInQue[msgQue->lastMsgIdx].msgBuf     = msgBuf;
   // Increase number of msg in queue
   msgQue->numMsgInQ++;
   // MsgQId: 1 => bitpos: 0 in bitMap
   msgQCntxt->msgQueBitmap      |=   1 << (gTaskCntxt[dstTaskId].msgQId -1);

   QUEUE_INC_MSG_IDX(msgQue->lastMsgIdx);

   pthread_mutex_unlock(&(msgQCntxt->mutexQueLock));
   // SEND SIGNAL TO Receiving Thread
   sem_post(&(msgQCntxt->semThrdMsgSync));	

#if 0
   printf("===== MSG SEND : SUCCESS ========\n");
#endif

   return SUCCESS_E;
} /*End of SendMsgToTask*/


/*
 *  This function schedules All task/queues mapped to one thread.
 *  It also takes care of priority of task
 *  PASS THIS FUNCTION AS HANDLER FUNCTION in pthread_create.
 *  pthread_create SHOULD BE CALLED ONLY AFTER QUEUE,TASK,THREAD contexts are created.
*/
void TaskSchedulerPerThrd(ThrdId_e thrdId)
{
   int          i = 0;
   MsgQCntxt_t *msgQCntxt;
   Msg_t        msg;
   MsgQueId_e   schedQId; // Id of scheduled Queue
   U16          msgIdx;
   ErrorCode_e  errorCode = SUCCESS_E;

   msgQCntxt = gThrdCntxt[thrdId].msgQCntxt;
   DEBUG4(("\n===== Starting TaskSchedulerPerThrd for Thread Id (%d) =======\n\n", thrdId));

   while(1)/*TASK Scheduler will be continuously running*/
   {
#if 0
      printf("\n===== WAIT FOR NEXT MSG THREAD_ID(%d) =======\n\n", thrdId);
#endif
      // TBD: Check if this is busy looping,, convert it to signal wait
      while(sem_wait(&(msgQCntxt->semThrdMsgSync)) != 0) {}

#if 0
      printf("===== RCV MSG: Handle Queue Msg ========\n");
#endif
      // Mutex Lock before reading data from queue
      pthread_mutex_lock(&(msgQCntxt->mutexQueLock));

      // READ MSG From Highest Priority Queue which has valid msg
      schedQId = getHighestPrioQWithMsg(msgQCntxt);
#if 0
      printf("===== RCV MSG: QueeuId((%d), fistMsgIdx(%d), lastMsgIdx(%d)\n", schedQId, 
                                                                         msgQCntxt->msgQLst[schedQId].firstMsgIdx,
                                                                         msgQCntxt->msgQLst[schedQId].lastMsgIdx);
#endif
      // Error in reading Msg from queue
      if(  (schedQId == INVALID_MSG_QUEUE_ID) ||(schedQId >= MAX_MSG_QUEUE_NUM_E))
      {
         pthread_mutex_unlock(&(msgQCntxt->mutexQueLock));
         DEBUG1(("ERROR: INVALID MSG QUEUE, QueuId(%d) \n", schedQId));
         return;
      }
      else if( msgQCntxt->msgQLst[schedQId].firstMsgIdx == msgQCntxt->msgQLst[schedQId].lastMsgIdx){
         pthread_mutex_unlock(&(msgQCntxt->mutexQueLock));
         DEBUG1((" ERROR: NO VALID MSG IN QUEUE -QueeuId((%d), fistMsgIdx(%d), lastMsgIdx(%d)\n", 
                                schedQId, msgQCntxt->msgQLst[schedQId].firstMsgIdx, msgQCntxt->msgQLst[schedQId].lastMsgIdx));
         return;
      }

#if 0
      printf("===== RCV MSG: MSG Found in Queue\n");
#endif
      msgIdx         = msgQCntxt->msgQLst[schedQId].firstMsgIdx;
      msg.srcTaskId  = msgQCntxt->msgQLst[schedQId].msgInQue[msgIdx].srcTaskId;
      msg.dstTaskId  = msgQCntxt->msgQLst[schedQId].msgInQue[msgIdx].dstTaskId;
      msg.msgType    = msgQCntxt->msgQLst[schedQId].msgInQue[msgIdx].msgType;
      msg.msgBuf     = msgQCntxt->msgQLst[schedQId].msgInQue[msgIdx].msgBuf;
      QUEUE_INC_MSG_IDX(msgQCntxt->msgQLst[schedQId].firstMsgIdx); 
      msgQCntxt->msgQLst[schedQId].numMsgInQ--;
      if(msgQCntxt->msgQLst[schedQId].numMsgInQ == 0)
      {
#if 0
         printf("===== All Msg processed in Queue(%d): Reset the bitmap for this queue========\n", schedQId);
#endif
         RESET_BIMAP_FOR_QUEUE(msgQCntxt, schedQId);
      }

      pthread_mutex_unlock(&(msgQCntxt->mutexQueLock));

#if 0
      printf("===== INFO: Message received srcTask(%d), dstTask(%d), msgQId(%d), msgType(%d), msgIdx(%d)\n", 
                                   msg.srcTaskId, msg.dstTaskId, schedQId, msg.msgType, msgIdx );
#endif
      //CALL MESSAGE QUEUE HANDLER FUNCTION
      // Should make Array of Handler function, msgQId should be able to get correct handler
      // e.g QueHndlrFuncArr[msgQId] (PARAMS)
      msgQCntxt->msgQLst[schedQId].msgQHndlrFunc(msg);
   } 

   return;
}
