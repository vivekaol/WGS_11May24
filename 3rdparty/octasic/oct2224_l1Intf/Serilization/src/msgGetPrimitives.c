/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgGetPrimitives.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Message Get Primitives

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "msgGetPrimitives.h"
#include "l1capi_typedef.h"

uint8_t *msgStartRdPtr;
uint8_t *currentBodyRdPtr;
uint8_t *currentHdrRdPtr;

flatMemPool bufPool[MAX_POOL_NR];

/*
uint8_t resetMsgBufferAlloc(uint8_t* memStart,uint32_t bufferSize,uint8_t assignedPoolId)
{
    if(assignedPoolId >= MAX_POOL_NR){
        return 0;
    }
    bufPool[assignedPoolId].currentFlatBufWrPos = 0;
    bufPool[assignedPoolId].bufAlloc = memStart;
    bufPool[assignedPoolId].bufferSizeOfFlatBuf = bufferSize;
    return 1;
}

static uint8_t* flatBufferAlloc(uint32_t size,uint8_t assignedPoolId)
{
    uint8_t* pRet = 0;
    if(size == 0)
      return 0;

    pRet = bufPool[assignedPoolId].bufAlloc + bufPool[assignedPoolId].currentFlatBufWrPos;
    bufPool[assignedPoolId].currentFlatBufWrPos += size;
    if(bufPool[assignedPoolId].currentFlatBufWrPos > bufPool[assignedPoolId].bufferSizeOfFlatBuf)
        return 0;
    return (pRet);
}

void * allocMem(uint32_t size,uint8_t assignedPoolId)
{
    //or call user specified mem alloc function
    if(assignedPoolId >= MAX_POOL_NR){
        return 0;
    }
    return (void *)flatBufferAlloc(size,assignedPoolId);
}
*/
