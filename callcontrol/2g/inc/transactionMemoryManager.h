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
*#########################################################################################
* File Name   : transactionMemoryManager.h
 *
* Description : Functions for managing data structures per transaction.
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 29/11/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#ifndef TRANSACTIONMEMORYMANAGER_H_
#define TRANSACTIONMEMORYMANAGER_H_
#include "l2Scheduler.h"

typedef struct
{
    tOCT_UINT8 pushToTail;
    tOCT_UINT8 sapi;
}transactMemoryParams;

void transactionMemoryManagerInit();
void pushMsgToTransactionMemoryManager(void* msg , logicalChannelIdentity * ch_id , transactMemoryParams params);
void* popMsgFromTransactionMemoryManager(logicalChannelIdentity * ch_id, tOCT_UINT8 sapi);
void* popGprsMsgFromTransactionMemoryManager(logicalChannelIdentity * ch_id, tOCT_UINT8 tfi);
void transactionMemoryManagerClose();
void clearUserTransactionMemory(logicalChannelIdentity * ch_id);

#endif
