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
 * File Name   : msgQue.c 
 *
 * Description : This file has msgQueue handling of Platform
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
#include "msgQue.h"
#include "stdio.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = cmn;
//Only one thread has Msg Queue context for Now. In Future if muliple thread need queu
//This will need update so will thread context which has mapping with MsgQueue
MsgQCntxt_t gMsgQCntxt;
/* -----------------------------------------------------
 *            Msg Queue Utility Function 
 * ----------------------------------------------------- */


void InitMsgQueCntxt(void)
{
   U16   queIdx  = 0;

   DEBUG3(("===== Initialize Message Queue Context ========\n"));
   // Define wrapper for Mutex and Sem init in cmnDs.h
   pthread_mutex_init( &(gMsgQCntxt.mutexQueLock), NULL);
   sem_init(&(gMsgQCntxt.semThrdMsgSync), 0, 0);  /*Semaphore used across thrd, not Inter Process*/

   //gMsgQCntxt.queStateSM       = ACTIVE_STATE_E;
   gMsgQCntxt.msgQueBitmap     = 0;
   for(queIdx = 0; queIdx < MAX_MSG_QUEUE_NUM_E; queIdx++)
   {
      gMsgQCntxt.msgQLst[queIdx].inUse           = FALSE_E;
      gMsgQCntxt.msgQLst[queIdx].msgQId          = queIdx + 1; //As queId enum starts with INVALID_MSG_QUEUE_ID=0
      gMsgQCntxt.msgQLst[queIdx].numMsgInQ       = 0;
      gMsgQCntxt.msgQLst[queIdx].firstMsgIdx     = 0;
      gMsgQCntxt.msgQLst[queIdx].lastMsgIdx      = 0;
      gMsgQCntxt.msgQLst[queIdx].msgQHndlrFunc   = NULL;
      memset(gMsgQCntxt.msgQLst[queIdx].msgInQue, 0, MAX_MSG_QUEUE_SIZE * sizeof(Msg_t));
   }

}/*End of InitMsgQue*/

ErrorCode_e DeleteMsgQue(void)
{
   U16   queIdx  = 0;
   // Define wrapper for Mutex and Sem init in cmnDs.h
   pthread_mutex_init( &(gMsgQCntxt.mutexQueLock), NULL);
   sem_init(&(gMsgQCntxt.semThrdMsgSync), 0, 0);  /*Semaphore used across thrd, not Inter Process*/

   //gMsgQCntxt.queStateSM       = ACTIVE_STATE_E;
   gMsgQCntxt.msgQueBitmap     = 0;
   for(queIdx = 0; queIdx < MAX_MSG_QUEUE_NUM_E; queIdx++)
   {
      gMsgQCntxt.msgQLst[queIdx].inUse           = FALSE_E;
      gMsgQCntxt.msgQLst[queIdx].msgQId          = queIdx + 1; //As queId enum starts with INVALID_MSG_QUEUE_ID=0
      gMsgQCntxt.msgQLst[queIdx].numMsgInQ       = 0;
      gMsgQCntxt.msgQLst[queIdx].firstMsgIdx     = 0;
      gMsgQCntxt.msgQLst[queIdx].lastMsgIdx      = 0;
      gMsgQCntxt.msgQLst[queIdx].msgQHndlrFunc   = NULL;
      // TBD Free Memory of each message content also
      memset(gMsgQCntxt.msgQLst[queIdx].msgInQue, 0, MAX_MSG_QUEUE_SIZE * sizeof(Msg_t));
   }

   return SUCCESS_E;
}/*End of DeleteMsgQue*/

ErrorCode_e CreateMsgQue(MsgQueId_e msgQueId, MsgQHndlr_f msgQueHndlrFunc)
{
   U16   queIdx  = 0;

   gMsgQCntxt.msgQLst[msgQueId].inUse           = TRUE_E;
   gMsgQCntxt.msgQLst[msgQueId].msgQId          = msgQueId;
   // Memory Allocation for message Queue is already done in Init
   gMsgQCntxt.msgQLst[msgQueId].numMsgInQ       = 0;
   gMsgQCntxt.msgQLst[msgQueId].firstMsgIdx     = 0;
   gMsgQCntxt.msgQLst[msgQueId].lastMsgIdx      = 0;
   gMsgQCntxt.msgQLst[msgQueId].msgQHndlrFunc   = msgQueHndlrFunc;
   DEBUG3(("===== Create Msg Queue for msgId_In(%d), msgId_gCntxt ========\n", msgQueId, gMsgQCntxt.msgQLst[msgQueId].msgQId));

   return SUCCESS_E;
}/*End of CreateMsgQue*/

// This function returns MsgQueueId of highest priority Msg Queue with valid Message.
// return value INVALID_MSG_QUEUE_ID(0) => None of the queue has a valid Msg
inline MsgQueId_e getHighestPrioQWithMsg(MsgQCntxt_t *msgQCntxt)
{
   U16 queId      = 0;
   U16 msgQBitMap = msgQCntxt->msgQueBitmap;

   //printf("===== Queues Status msgQBitMap(%x)",msgQBitMap);
   if(msgQBitMap == 0)  {return 0;}
   if((msgQBitMap & 0x0F) == 0) { queId = queId + 4; msgQBitMap = msgQBitMap >> 4; /*printf("--bitmap +4 \n");*/}
   if((msgQBitMap & 0x03) == 0) { queId = queId + 2; msgQBitMap = msgQBitMap >> 2; /*printf("--bitmap +2 \n");*/}
   if((msgQBitMap & 0x01) == 0) { queId = queId + 1; msgQBitMap = msgQBitMap >> 1; /*printf("--bitmap +1 \n");*/}

   queId++;  // With this LSB will be returned as 1
   return queId;
}


