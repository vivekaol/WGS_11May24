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
* File Name   : linkedList.h
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
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//#include "gsmCommon.h"
#include "../../../sls/inc/octvc1/gsm/octvc1_gsm_evt.h"

typedef struct node {
  void *msg;
  struct node *next;
}listNode;

void pushMsgToList(listNode **tail ,void *msg); // if head is NULL then create the first node and update head and tail pointers.
listNode* popMsgFromList(listNode **head ); //Update Head and Tail Pointers after popping up the message from list.
int lenghtOfList(listNode * head); // Return the length of the list.

/***********************************************************************************************************/
#define QUESIZE 100
#define LIST_NODE_BUFFER_SIZE 64

typedef struct {
	void *q[QUESIZE+1];
	int first;
	int last;
	int count;
}queue;

void initQueue(queue *q);
void enQueue(queue *q , void *data);
void* deQueue(queue *q);

tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA* getDataIndBuffer();
void allocateDataIndBuffer();
void deallocateDataIndBuffer();
void allocateTxDataBuffer();
void deallocateTxDataBuffer();
tOCT_UINT8* getTxDataBuffer();
void allocatePageRachBuffer();
void deallocatePageRachBuffer();
tOCT_UINT8* getPageRachBuffer();

#ifdef FEA_GPRS
void allocateGprsDataIndBuffer();
void deallocateGprsDataIndBuffer();
void deallocateGprsTxDataBuffer();
tOCT_UINT8* getGprsDataIndBuffer();
void allocateTxGprsBuffer();
tOCT_UINT8* getGprsTxDataBuffer();
#endif

#endif
