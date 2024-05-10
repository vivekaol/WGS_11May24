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


#include <string.h>
#include <malloc.h>
#include <assert.h>
#include "linkedlist.h"
#include "logManager.h"
#include "lteL1IfApi.h"
#include "lteUserManager.h"

#define LTE_MAX_NUMBER_OF_RX_BUFFERS 150
#define LTE_MAX_NUMBER_OF_UL_BUFFERS 200
#define LTE_MAX_NUMBER_OF_BUFFERS 200
#define LTE_MAX_NUMBER_OF_RRC_BUFFERS 200
#define SIZE_OF_UL_CONFIG_BUFFER 128

uint8 *RxDataBuffers[LTE_MAX_NUMBER_OF_RX_BUFFERS];
uint8 *UlTxDataBuffers[LTE_MAX_NUMBER_OF_BUFFERS];
uint8 *rrcDataBuffers[LTE_MAX_NUMBER_OF_RRC_BUFFERS];
uint8 *ulConfigReqBuf[10];
uint8 *DlTxDataBuffer[LTE_MAX_NUMBER_OF_BUFFERS];
uint8 *DlConfigBuffers[LTE_MAX_NUMBER_OF_BUFFERS];
uint8 *UlConfigBuffers[LTE_MAX_NUMBER_OF_UL_BUFFERS];

void allocateUlConfigBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_UL_BUFFERS) ; i++ )
	{
		UlConfigBuffers[i] = (uint8 *) malloc(SIZE_OF_UL_CONFIG_BUFFER);
		assert(UlConfigBuffers[i] != NULL);
	}
	return;
}

void deallocateUlConfigBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_UL_BUFFERS) ; i++ )
	{
		if(UlConfigBuffers[i] != NULL)
		free(UlConfigBuffers[i]);
		UlConfigBuffers[i] = NULL;
	}
	return;
}

uint8* getUlConfigBuffer()
{
	static int UlConfigBufIndex = 0;
	uint8 *buf = NULL;
	if(UlConfigBufIndex == LTE_MAX_NUMBER_OF_UL_BUFFERS)
	{
		UlConfigBufIndex = 0;
	}
	buf = UlConfigBuffers[UlConfigBufIndex++];
	memset(buf , 0 , SIZE_OF_UL_CONFIG_BUFFER);
	return buf;
}

void allocateDlConfigBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_BUFFERS) ; i++ )
	{
		DlConfigBuffers[i] = (uint8 *) malloc(LTE_MAX_SIZE_BUFFER);
		assert(DlConfigBuffers[i] != NULL);
	}
	return;
}

void deallocateDlConfigBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_BUFFERS) ; i++ )
	{
		if(DlConfigBuffers[i] != NULL)
		free(DlConfigBuffers[i]);
		DlConfigBuffers[i] = NULL;
	}
	return;
}

uint8* getDlConfigBuffer()
{
	static int DlConfigBufIndex = 0;
	uint8 *buf = NULL;
	if(DlConfigBufIndex == LTE_MAX_NUMBER_OF_BUFFERS)
	{
		DlConfigBufIndex = 0;
	}
	buf = DlConfigBuffers[DlConfigBufIndex++];
	memset(buf , 0 , LTE_MAX_SIZE_BUFFER);
	return buf;
}

void allocateDlTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_BUFFERS) ; i++ )
	{
		DlTxDataBuffer[i] = (uint8 *) malloc(LTE_MAX_SIZE_BUFFER);
		assert(DlTxDataBuffer[i] != NULL);
	}

	return;
}

void deallocateDlTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_BUFFERS) ; i++ )
	{
		if(DlTxDataBuffer[i] != NULL)
		free(DlTxDataBuffer[i]);
		DlTxDataBuffer[i] = NULL;
	}

	return;
}

uint8* getDlTxDataBuffer()
{
	static int TxDataBufIndexLte = 0;
	uint8 *buf = NULL;
	if(TxDataBufIndexLte == LTE_MAX_NUMBER_OF_BUFFERS)
	{
		TxDataBufIndexLte = 0;
	}
	buf = DlTxDataBuffer[TxDataBufIndexLte++];
	memset(buf , 0 , LTE_MAX_SIZE_BUFFER);

	return buf;

}

void allocateRxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_RX_BUFFERS) ; i++ )
	{
		RxDataBuffers[i] = (uint8 *) malloc(LTE_MAX_SIZE_ULSCH_BUFFER);
		assert(RxDataBuffers[i] != NULL);
	}

	return;
}

void deallocateRxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_RX_BUFFERS) ; i++ )
	{
		if(RxDataBuffers[i] != NULL)
		free(RxDataBuffers[i]);
		RxDataBuffers[i] = NULL;
	}

	return;
}

uint8* getRxDataBuffer()
{
	static int RxDataBufIndex = 0;
	uint8 *buf = NULL;
	if(RxDataBufIndex == LTE_MAX_NUMBER_OF_RX_BUFFERS)
	{
		RxDataBufIndex = 0;
	}
	buf = RxDataBuffers[RxDataBufIndex++];
	memset(buf , 0 , (LTE_MAX_SIZE_ULSCH_BUFFER));

	return buf;

}

void allocateUlTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_BUFFERS) ; i++ )
	{
		UlTxDataBuffers[i] = (uint8 *) malloc(LTE_MAX_SIZE_BUFFER);
		assert(UlTxDataBuffers[i] != NULL);
	}
	for(i = 0 ; i < 10 ; i++ )
	{
		ulConfigReqBuf[i] = (uint8 *) malloc(64);
		assert(ulConfigReqBuf[i] != NULL);
	}

	return;
}

void deallocateUlTxDataBuffer()
{
	int i = 0;
	for(i = 0 ; i <(LTE_MAX_NUMBER_OF_BUFFERS) ; i++ )
	{
		if(UlTxDataBuffers[i] != NULL)
		free(UlTxDataBuffers[i]);
		UlTxDataBuffers[i] = NULL;
	}

	for(i = 0 ; i < 10 ; i++ )
	{
		if(ulConfigReqBuf[i] != NULL)
			free(ulConfigReqBuf[i]);
		ulConfigReqBuf[i] = NULL;
	}

	return;
}

uint8* getUlTxDataBuffer()
{
	static int UlTxDataBufIndex = 0;
	uint8 *buf = NULL;
	if(UlTxDataBufIndex == LTE_MAX_NUMBER_OF_BUFFERS)
	{
		UlTxDataBufIndex = 0;
	}
	buf = UlTxDataBuffers[UlTxDataBufIndex++];
	memset(buf , 0 , LTE_MAX_SIZE_BUFFER);

	return buf;

}

uint8* getBufferFordummyUlconfigReq()
{
	static int UlConfigBufIndex = 0;
	uint8 *buf = NULL;
	if(UlConfigBufIndex == 10)
	{
		UlConfigBufIndex = 0;
	}
	buf = ulConfigReqBuf[UlConfigBufIndex++];
	return buf;
}

void allocateRrcDataBuffer()
{
	int i = 0;
	for(i = 0 ; i < LTE_MAX_NUMBER_OF_RRC_BUFFERS ; i++ )
	{
		rrcDataBuffers[i] = (uint8 *) malloc(LTE_MAX_MSG_SIZE);
		assert(rrcDataBuffers[i] != NULL);
	}
	return;
}

void deallocateRrcDataBuffer()
{
	int i = 0;
	for(i = 0 ; i < LTE_MAX_NUMBER_OF_RRC_BUFFERS ; i++ )
	{
		if(rrcDataBuffers[i] != NULL)
		free(rrcDataBuffers[i]);
		rrcDataBuffers[i] = NULL;
	}
	return;
}

uint8* getRrcDataBuffer()
{
	static int RrcDataBufIndex = 32; // Buffer from 0-31 are used for storing paging messages
	uint8 *buf = NULL;
	if(RrcDataBufIndex == LTE_MAX_NUMBER_OF_RRC_BUFFERS)
	{
		RrcDataBufIndex = 32;
	}
	buf = rrcDataBuffers[RrcDataBufIndex++];
	memset(buf , 0 , LTE_MAX_MSG_SIZE);
	return buf;
}

uint8* getRrcPageBuffer(uint8 pageIndex)
{
	if(pageIndex >= 32)
	{
		assert(0);
	}
	return rrcDataBuffers[pageIndex];
}
