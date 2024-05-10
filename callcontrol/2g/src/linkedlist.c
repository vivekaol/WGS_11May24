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
* File Name   : linkedList.c
 *
* Description : Function to support Linked-List data structure
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#include "linkedlist.h"
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include "logManager.h"
#define TX_DATA_BUFFER_MAX 96
#define DATA_IND_BUFFER_MAX 48
#define PAGE_RACH_BUFFER_MAX 96
#define GPRS_DATA_IND_BUF_SIZE (16*16+4)
#define GPRS_DATA_IND_BUF_MAX_NUM 32

void pushMsgToList(listNode **tail , void* msg)
{
	listNode *currNode = *tail;
    //logPrint(LOG_DEBUG , "pushMsgToList Tail Pointer = %p \n" , currNode );
	listNode* tailNode = (listNode *) malloc(LIST_NODE_BUFFER_SIZE /*sizeof(listNode)*/);
#ifndef NDEBUG
	assert(tailNode != NULL);
#else
	if(tailNode == NULL)
	{
		logPrint(LOG_ERR, "pushMsgToList: tailNode == NULL\n");
		exit(1);
	}
#endif
	tailNode->next = NULL;
    tailNode->msg = msg;

	if(currNode == NULL) // This is first node to add to the list so head and tail are same
	{
		*tail = tailNode;
	}
	else
	{
		currNode->next = tailNode;
		*tail = tailNode;
	}
	return;
}
listNode* popMsgFromList(listNode** head) // free outside this function
{
	listNode *currNode = *head;
    //logPrint(LOG_DEBUG , "popMsgFromList Head Pointer = %p \n" , currNode );
#ifndef NDEBUG
	assert(currNode != NULL);
#else
	if(currNode == NULL)
	{
		logPrint(LOG_ERR, "popMsgFromList: currNode == NULL\n");
		exit(1);
	}
#endif
	*head = currNode->next;

	return currNode;
}
int lenghtOfList(listNode* head)
{
	int len = 0;
	if(head != NULL)
	{
		while(head != NULL)
		{
			head = head->next;
			len++;
		}

	}
	return len;
}

void initQueue(queue *q)
{
	q->first = 0;
	q->last = QUESIZE - 1;
	q->count = 0;
}
void enQueue(queue *q , void *data)
{
#ifndef NDEBUG
	assert(q->count < QUESIZE);
#else
	if(q->count >= QUESIZE)
	{
		logPrint(LOG_ERR, "enQueue: q->count >= QUESIZE\n");
		exit(1);
	}
#endif

	q->last = (q->last + 1) % QUESIZE;
	q->q[q->last] = data;
	q->count = q->count + 1;
	//logPrint(LOG_DEBUG ,"EnQue Pointer = %p \n", data);
}
void* deQueue(queue *q)
{
	void* ptr = NULL;
	if(q->count > 0)
	{
		ptr = q->q[q->first];
		q->first = (q->first + 1) % QUESIZE;
		q->count = q->count - 1;
		//logPrint(LOG_DEBUG ,"DeQue Pointer = %p , Remaining Number of Items in Q = %d \n", data , q->count);
	}
	return ptr;
}

tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA *dataInd[DATA_IND_BUFFER_MAX];
void allocateDataIndBuffer()
{
	int i = 0;
	for(i = 0 ; i <(DATA_IND_BUFFER_MAX) ; i++ )
	{
		dataInd[i] = (tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA *) malloc(sizeof(tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA));
#ifndef NDEBUG
		assert(dataInd[i] != NULL);
#else
		if(dataInd[i] == NULL)
		{
			logPrint(LOG_ERR, "allocateDataIndBuffer: dataInd[i] == NULL\n");
			exit(1);
		}
#endif
	}

	return;
}

void deallocateDataIndBuffer()
{
	int i = 0;
	for(i = 0 ; i < DATA_IND_BUFFER_MAX ; i++ )
	{
		if(dataInd[i] != NULL)
		  free(dataInd[i]);
		dataInd[i] = NULL;
	}

	return;
}
tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA* getDataIndBuffer()
{
	static int dataIndBufIndex = 0;

	if(dataIndBufIndex == DATA_IND_BUFFER_MAX)
	{
		dataIndBufIndex = 0;
	}
	return dataInd[dataIndBufIndex++];

}

tOCT_UINT8 *TxDataBuffers[TX_DATA_BUFFER_MAX]; // Every DataInd generates 2 messages
void allocateTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(TX_DATA_BUFFER_MAX) ; i++ )
	{
		TxDataBuffers[i] = (tOCT_UINT8 *) malloc(GSM_MACBLOCK_LEN);
#ifndef NDEBUG
		assert(TxDataBuffers[i] != NULL);
#else
		if(TxDataBuffers[i] == NULL)
		{
			logPrint(LOG_ERR, "allocateTxDataBuffer: TxDataBuffers[i] == NULL\n");
			exit(1);
		}
#endif
	}

	return;
}

void deallocateTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <TX_DATA_BUFFER_MAX; i++ )
	{
		if(TxDataBuffers[i] != NULL)
		{
			free(TxDataBuffers[i]);
		}
		TxDataBuffers[i] = NULL;
	}

	return;
}
tOCT_UINT8* getTxDataBuffer()
{
	static int TxDataBufIndex = 0;

	if(TxDataBufIndex == TX_DATA_BUFFER_MAX)
	{
		TxDataBufIndex = 0;
	}
	return TxDataBuffers[TxDataBufIndex++];

}

tOCT_UINT8 *pageRachBuffers[PAGE_RACH_BUFFER_MAX];
void allocatePageRachBuffer()
{
	int i = 0;
	for(i = 0 ; i <PAGE_RACH_BUFFER_MAX; i++ )
	{
		pageRachBuffers[i] = (tOCT_UINT8 *) malloc(GSM_MACBLOCK_LEN);
#ifndef NDEBUG
		assert(pageRachBuffers[i] != NULL);
#else
		if(pageRachBuffers[i] == NULL)
		{
			logPrint(LOG_ERR, "allocatePageRachBuffer: pageRachBuffers[i] == NULL\n");
			exit(1);
		}
#endif
	}
	return;
}
void deallocatePageRachBuffer()
{
	int i = 0;
	for(i = 0 ; i < PAGE_RACH_BUFFER_MAX ; i++ )
	{
		if(pageRachBuffers[i] != NULL)
		{
			free(pageRachBuffers[i]);
		}
		pageRachBuffers[i] = NULL;
	}
	return;

}
tOCT_UINT8* getPageRachBuffer()
{
	static int pageRachBufIndex = 0;

	if(pageRachBufIndex == PAGE_RACH_BUFFER_MAX)
	{
		pageRachBufIndex = 0;
	}
	return pageRachBuffers[pageRachBufIndex++];
}

#ifdef FEA_GPRS
tOCT_UINT8 *gprsDataIndBuffers[GPRS_DATA_IND_BUF_MAX_NUM];
void allocateGprsDataIndBuffer()
{
	int i = 0;
	for(i = 0 ; i <GPRS_DATA_IND_BUF_MAX_NUM; i++ )
	{
		gprsDataIndBuffers[i] = (tOCT_UINT8 *) malloc(GPRS_DATA_IND_BUF_SIZE);
#ifndef NDEBUG
		assert(gprsDataIndBuffers[i] != NULL);
#else
		if(gprsDataIndBuffers[i] == NULL)
		{
			logPrint(LOG_ERR, "allocateGprsDataBuffer: gprsDataIndBuffers[i] == NULL");
			exit(1);
		}
#endif
	}
	return;
}
void deallocateGprsDataIndBuffer()
{
	int i = 0;
	for(i = 0 ; i < GPRS_DATA_IND_BUF_MAX_NUM ; i++ )
	{
		if(gprsDataIndBuffers[i] != NULL)
		{
			logPrint(LOG_DEBUG,"Freeing %u with index %d", &gprsDataIndBuffers[i],i);
			free(gprsDataIndBuffers[i]);
		}
		gprsDataIndBuffers[i] = NULL;
	}
	return;

}
tOCT_UINT8* getGprsDataIndBuffer()
{
	static int gprsDataIndBufIndex = 0;

	if(gprsDataIndBufIndex == GPRS_DATA_IND_BUF_MAX_NUM)
	{
		gprsDataIndBufIndex = 0;
	}
	logPrint(LOG_ERR, "getGprsDataIndBuff GprsBuffers[%d] ",gprsDataIndBufIndex);
	return gprsDataIndBuffers[gprsDataIndBufIndex++];
}

tOCT_UINT8 *TxGprsBuffers[TX_DATA_BUFFER_MAX]; // Every DataInd generates 2 messages
void allocateTxGprsBuffer()
{
	int i = 0;
	for(i = 0 ; i <(TX_DATA_BUFFER_MAX) ; i++ )
	{
		TxGprsBuffers[i] = (tOCT_UINT8 *) malloc(GPRS_MACBLOCK_LEN);
#ifndef NDEBUG
		assert(TxGprsBuffers[i] != NULL);
#else
		if(TxGprsBuffers[i] == NULL)
		{
			logPrint(LOG_ERR, "allocateTxGprsBuffer: TxGprsBuffers[i] == NULL\n");
			exit(1);
		}
#endif
	}

	return;
}
tOCT_UINT8* getGprsTxDataBuffer()
{
	static int TxGprsBufIndex = 0;

	if(TxGprsBufIndex == TX_DATA_BUFFER_MAX)
	{
		TxGprsBufIndex = 0;
	}
	return TxGprsBuffers[TxGprsBufIndex++];

}

void deallocateGprsTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <TX_DATA_BUFFER_MAX; i++ )
	{
		if(TxGprsBuffers[i] != NULL)
		{
			free(TxGprsBuffers[i]);
		}
		TxGprsBuffers[i] = NULL;
	}

	return;
}
#endif
