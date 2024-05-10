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
 ############################################################################*/

/*############################################################################
 * File Name   : msgQue.h
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date	        Author                  Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 ############################################################################*/
#ifndef _MSG_QUEUE_H_
#define _MSG_QUEUE_H_

/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "cmnDs.h"
#include "cmnPf.h"
#include "stddef.h"
#include "string.h"
#include "pthread.h"
#include "semaphore.h"
#include "errorCode.h"
/* -----------------------------------------------------
 *           MACRO Definitions 
 * ----------------------------------------------------- */
#define MAX_MSG_QUEUE_SIZE  128 // MAX Number of Msg in one Queue

// Increment index to access message Queue, i.e. increment with Modulo 128(queue size)
#define QUEUE_INC_MSG_IDX(x)         ((x) = ((x) + 1) & 0x7F)
#define QUEUE_ADD_MSG_IDX(idx, num)  (((idx) + (num)) & 0x7F)
#define RESET_BIMAP_FOR_QUEUE(queCntxt, queId) ((queCntxt)->msgQueBitmap  &=  ~(1 << (queId -1)))

/* -----------------------------------------------------
 *           Data Structures for Msg Queue
 * ----------------------------------------------------- */
typedef struct _Message_t
{
   TaskId_e    srcTaskId;  // Identifies source Task
   TaskId_e    dstTaskId;  // Identifies source Task
   // TBD: Check we Need to rename as MsgId OR event 
   MsgType_e   msgType;    // Identifies the message 
   void        *msgBuf;     // pointer to actual message

} Msg_t;

//Message Queue Handler function prototype(decleration)
typedef void (*MsgQHndlr_f)(Msg_t msg);

typedef struct _MsgQueue
{
   U8          inUse;
   MsgQueId_e  msgQId;
   U16         numMsgInQ;     // Number of Msg in Queue 
   U16         firstMsgIdx;   // Queue Head: Index of First Msg In Queue
   U16         lastMsgIdx;    // Queue Tail: Index of Last  Msg in Queue
   MsgQHndlr_f msgQHndlrFunc; // Handler function for this message queue
   Msg_t       msgInQue[MAX_MSG_QUEUE_SIZE];
} MsgQueue_t;

typedef struct _MsgQCntxt
{
   pthread_mutex_t mutexQueLock; // Used for locking MsgQue
   sem_t       semThrdMsgSync;   // Used for Signaling of new message
   //InitSM_e    queStateSM;       // State machine telling queue is in which state of initialization
   // U16         numMsgQue;
   U8          msgQueBitmap;     // Bitmap indicating which Queue has valid Msgs
   MsgQueue_t  msgQLst[MAX_MSG_QUEUE_NUM_E + 1];

} MsgQCntxt_t;


/* -----------------------------------------------------
 *     Extern Decleration of function and Global Var 
 * ----------------------------------------------------- */
extern MsgQCntxt_t gMsgQCntxt;

MsgQueId_e getHighestPrioQWithMsg(MsgQCntxt_t *msgQCntxt);
void InitMsgQueCntxt(void);
U16  createMessageQueue(MsgQueId_e msgQId);
U16  deleteMessageQueue(MsgQueId_e msgQId);

//U16  sendMessageToQueue(int queueID, const Msg_t * message);
//U16  recvMessageFromQueue(int queueID, Msg_t * message);
#endif
