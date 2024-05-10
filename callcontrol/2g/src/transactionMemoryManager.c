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
* File Name   : transactionMemoryManager.c
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
#include <stdlib.h>
#include "transactionMemoryManager.h"
#include "linkedlist.h"
#include <assert.h>
#include "logManager.h"
#include "userManager.h"

#ifdef FEA_GPRS
#include "gprs.h"

extern gprsInfo*  gprsUserDb[GPRS_MAX_TS][MAX_SUBCHAN_TIMESLOT] ;
#endif

static listNode*  transactionMemoryDb[MAX_TS][MAX_SUBCHAN_TIMESLOT][SAPI_PRACH];
pthread_mutex_t   mutexTransactionQ = PTHREAD_MUTEX_INITIALIZER;

void transactionMemoryManagerInit()
{
	tOCT_UINT8 i=0 , j = 0, k = 0;
	for ( i = 0; i < MAX_TS; i++ )
	{
	  for ( j = 0; j < MAX_SUBCHAN_TIMESLOT; j++ )
	  {
	      for( k = 0; k < SAPI_PRACH; k++)
          {   
		      transactionMemoryDb[i][j][k] = NULL;
          }
	  }
	}
}

listNode * getListNodeFromTransactionMemoryDb(logicalChannelIdentity * ch_id, tOCT_UINT8 sapi)
{
	listNode *qNode = NULL;
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum >= 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum < 0))
	{
		logPrint(LOG_ERR, "getListNodeFromTransactionMemoryDb: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "getListNodeFromTransactionMemoryDb: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
    if(isTimeSlotTypeSupportsPDTCH(ch_id->txSLotNum) == FALSE)
	qNode = transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][sapi];
	else
		qNode = transactionMemoryDb[ch_id->txSLotNum][0][SAPI_PDTCH];
	return qNode;
}

void pushMsgToTransactionMemoryManager(void* msg , logicalChannelIdentity * ch_id , transactMemoryParams params)
{
	pthread_mutex_lock(&mutexTransactionQ);
	listNode *currNode = getListNodeFromTransactionMemoryDb(ch_id, params.sapi); // This is head node
	listNode* qNode = malloc(/*LIST_NODE_BUFFER_SIZE*/sizeof(listNode));
#ifndef NDEBUG
	assert(qNode != NULL);
#else
	if(qNode == NULL)
	{
		logPrint(LOG_ERR, "pushMsgToTransactionMemoryManager: qNode == NULL\n");
		exit(1);
	}
#endif
	qNode->next = NULL;
	qNode->msg = msg;

	if(currNode == NULL) // This is first node to add to the list so head and tail are same
	{
		//This is head node in this linked list
		if(isTimeSlotTypeSupportsPDTCH(ch_id->txSLotNum) == FALSE)
		transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][params.sapi] = qNode;
		else
		transactionMemoryDb[ch_id->txSLotNum][0][SAPI_PDTCH] = qNode;
		//logPrint(LOG_DEBUG, "This is first node for Ts = %d , Sc = %d NodePtr = %p \n",ch_id->txSLotNum , ch_id->subChNum , qNode );
	}
	else
	{
		if(params.pushToTail == TRUE) // Add to the end of list
		{
			//First go to end of queue
			while(currNode->next != NULL)
			{
				currNode = currNode->next;
				//logPrint(LOG_DEBUG, "Looping through Nodes Ts = %d , Sc = %d \n",ch_id->txSLotNum , ch_id->subChNum  );
			}
			currNode->next = qNode;
			//logPrint(LOG_DEBUG, "Adding node to tail Ts = %d , Sc = %d \n",ch_id->txSLotNum , ch_id->subChNum  );

		}
		else // Add in front of head
		{
			qNode->next = currNode;
			//This is head node in this linked list
		if(isTimeSlotTypeSupportsPDTCH(ch_id->txSLotNum) == FALSE)
			transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][params.sapi] = qNode;
		else
			transactionMemoryDb[ch_id->txSLotNum][0][SAPI_PDTCH] = qNode;
			//logPrint(LOG_DEBUG, "Adding in front of Node Ts = %d , Sc = %d \n",ch_id->txSLotNum , ch_id->subChNum  );

		}
	}
	pthread_mutex_unlock(&mutexTransactionQ);
	return;

}

void* popMsgFromTransactionMemoryManager(logicalChannelIdentity * ch_id, tOCT_UINT8 sapi)
{
    pthread_mutex_lock(&mutexTransactionQ);
    tOCT_UINT8 * msg = NULL;
    listNode *qNode = getListNodeFromTransactionMemoryDb(ch_id, sapi );
    if(qNode != NULL)
    {
	    msg = qNode->msg;
	    transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][sapi] = qNode->next;
	    //logPrint(LOG_DEBUG, "popMsgFromTransactionMemoryManager Ts = %d , Sc = %d NodePtr = %p \n",ch_id->txSLotNum , ch_id->subChNum , qNode );
	    free(qNode);
	    qNode = NULL;
    }
    pthread_mutex_unlock(&mutexTransactionQ);
    return (void*)msg;
}

void clearUserTransactionMemory(logicalChannelIdentity * ch_id)
{
	pthread_mutex_lock(&mutexTransactionQ);
    
#ifndef NDEBUG
    assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum >= 0));
    assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
    if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum < 0))
    {
        logPrint(LOG_ERR, "clearUserTransactionMemory: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
        exit(1);
    }
    if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
    {
        logPrint(LOG_ERR, "clearUserTransactionMemory: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
        exit(1);
    }
#endif
    listNode *current = NULL , *tmp = NULL;
    int i = 0;
    for(i = 0; i < SAPI_PRACH; i++)
    {
        current =  transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][i];
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
        transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][i] = NULL;
    }
    pthread_mutex_unlock(&mutexTransactionQ);
	return;
}

void transactionMemoryManagerClose()
{
	tOCT_UINT8 i=0 , j = 0, k = 0;
	listNode *current = NULL , *tmp = NULL;
	for ( i = 0; i < MAX_TS; i++ )
	{
	  for ( j = 0; j < MAX_SUBCHAN_TIMESLOT; j++ )
	  {
        for ( k = 0; k < SAPI_PRACH; k++ )
        {
       		current =  transactionMemoryDb[i][j][k];
		while(current != NULL)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
       		transactionMemoryDb[i][j][k] = NULL;
        }
	  }
	}
}

#ifdef FEA_GPRS
listNode * getGprsListNodeFromTransactionMemoryDb(logicalChannelIdentity * ch_id, tOCT_UINT8 tfi )
{
	listNode *qNode = NULL;
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum > 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0))
	{
		logPrint(LOG_ERR, "getGprsListNodeFromTransactionMemoryDb: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "getGprsListNodeFromTransactionMemoryDb: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
	//for(; subChNum<MAX_SUBCHAN_TIMESLOT ; subChNum++)
	//{
			//info = gprsUserDb[ch_id->txSLotNum][subChNum];
			//if((info != NULL) && (info->tfi == tfi))
			//{
					//ch_id->subChNum = subChNum;
					qNode = transactionMemoryDb[ch_id->txSLotNum][0][SAPI_PDTCH];
					//break;
			//}
	//}
	return qNode;
}

void* popGprsMsgFromTransactionMemoryManager(logicalChannelIdentity * ch_id, tOCT_UINT8 tfi)
{
    pthread_mutex_lock(&mutexTransactionQ);
    tOCT_UINT8 * msg = NULL;
    listNode *qNode = getGprsListNodeFromTransactionMemoryDb(ch_id, tfi );
    if(qNode != NULL)
    {
	    msg = qNode->msg;
	    transactionMemoryDb[ch_id->txSLotNum][ch_id->subChNum][SAPI_PDTCH] = qNode->next;
	    free(qNode);
	    qNode = NULL;
    }
    pthread_mutex_unlock(&mutexTransactionQ);
    return (void*)msg;
}

#endif // FEA_GPRS
