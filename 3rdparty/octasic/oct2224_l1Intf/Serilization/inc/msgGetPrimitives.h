/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgGetPrimitives.h

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

#ifndef _MSGGETPRIMITIVES_H_
#define _MSGGETPRIMITIVES_H_

#include "l1IntEnums.h"
#include "l1capi_typedef.h"
#include "msgPrimitives.h"

#ifdef L1C_TRACE_CONTENT
#define SUB_BYTE_VAL(value) \
	{PRINT_SPACE;\
	value = subByteVal();\
	PRINTF(#value"=%d\n",value);}

#define SUB_WORD_VAL(value) \
	{PRINT_SPACE;\
	value = subWordVal();\
	PRINTF(#value"=%d\n",value);}

#define SUB_LONG_VAL(value) \
	{PRINT_SPACE;\
	value = subLongVal();\
	PRINTF(#value"=0x%x\n",value);}
#else
#define SUB_BYTE_VAL(value) \
	value = subByteVal();

#define SUB_WORD_VAL(value) \
	value = subWordVal();

#define SUB_LONG_VAL(value) \
	value = subLongVal();
#endif

typedef struct flatMemPool
{
    uint32_t     currentFlatBufWrPos;
    uint32_t     bufferSizeOfFlatBuf;
    uint8_t      *bufAlloc;
}flatMemPool;

static __inline__ void      resetMsgRead(uint8_t *newMsgPtr);
static __inline__ uint32_t  obtainMsgInSize(void);
static __inline__ uint8_t   subByteVal(void);
static __inline__ uint16_t  subWordVal(void);
static __inline__ uint32_t  subLongVal(void);
static __inline__ uint8_t * subByteStream(uint32_t size);
static __inline__ uint8_t   subByteValHdr(void);
static __inline__ uint16_t  subWordValHdr(void);
static __inline__ uint32_t  subLongValHdr(void);
static __inline__ uint8_t * getCurrentBodyRdPtr(void);
static __inline__ void      addBodyRdOffset(uint32_t bodyRdOffset);
static __inline__ uint8_t resetMsgBufferAlloc(uint8_t* memStart,uint32_t bufferSize,uint8_t assignedPoolId);
static __inline__ uint8_t* flatBufferAlloc(uint32_t size,uint8_t assignedPoolId);
static __inline__ void * allocMem(uint32_t size,uint8_t assignedPoolId);

#define MAX_POOL_NR  (2)
uint8_t resetMsgBufferAlloc(uint8_t* memStart,uint32_t bufferSize,uint8_t assignedPoolId);
void * allocMem(uint32_t size,uint8_t assignedPoolId);

extern void *pHostUlMsg;

extern uint8_t *msgStartRdPtr;
extern uint8_t *currentBodyRdPtr;
extern uint8_t *currentHdrRdPtr;

/******************************************************
     Inline Functions Definitions
*******************************************************/

static __inline__ void resetMsgRead(uint8_t *newMsgPtr)
{
	msgStartRdPtr    = newMsgPtr;
	currentBodyRdPtr = newMsgPtr + MSG_HDR_SIZE;
	currentHdrRdPtr  = newMsgPtr;
#ifdef L1C_TRACE_CONTENT
    space_counter = SHIFT_SPACE;
#endif
}

static __inline__ uint32_t obtainMsgInSize(void)
{
    return (currentBodyRdPtr - msgStartRdPtr);
}

static __inline__ uint8_t subByteVal(void)
{
    uint8_t ret;
    ret = *currentBodyRdPtr;
    currentBodyRdPtr++;
    return ret;
}

static __inline__ uint16_t subWordVal(void)
{
    uint16_t ret;
    ret = *((uint16_t *)currentBodyRdPtr);
    currentBodyRdPtr += sizeof(uint16_t);
    return SWAP_ENDIAN_16(ret);
}

static __inline__ uint32_t subLongVal(void)
{
    uint32_t ret;
    ret = *((uint32_t *)currentBodyRdPtr);
    currentBodyRdPtr += sizeof(uint32_t);
    return SWAP_ENDIAN_32(ret);
}

static __inline__ uint8_t *getCurrentBodyRdPtr(void)
{
    return currentBodyRdPtr;
}

static __inline__ void addBodyRdOffset(uint32_t bodyRdOffset)
{
	currentBodyRdPtr += bodyRdOffset;
}

static __inline__ uint8_t subByteValHdr(void)
{
    uint8_t ret;
    ret = *currentHdrRdPtr;
    currentHdrRdPtr++;
    return ret;
}

static __inline__ uint16_t subWordValHdr(void)
{
    uint16_t ret;
    ret = *((uint16_t *)currentHdrRdPtr);
    currentHdrRdPtr += sizeof(uint16_t);
    return SWAP_ENDIAN_16(ret);
}

static __inline__ uint32_t subLongValHdr(void)
{
    uint32_t ret;
    ret = *((uint32_t *)currentHdrRdPtr);
    currentHdrRdPtr += sizeof(uint32_t);
    return SWAP_ENDIAN_32(ret);
}

static __inline__ uint8_t *subByteStream(uint32_t size)
{
	uint8_t * pRet;
	pRet = currentBodyRdPtr;
	currentBodyRdPtr += size;
	return pRet;
}

extern flatMemPool bufPool[MAX_POOL_NR];

static __inline__ uint8_t resetMsgBufferAlloc(uint8_t* memStart,uint32_t bufferSize,uint8_t assignedPoolId)
{
    if(assignedPoolId >= MAX_POOL_NR){
        return 0;
    }
    bufPool[assignedPoolId].currentFlatBufWrPos = 0;
    bufPool[assignedPoolId].bufAlloc = memStart;
    bufPool[assignedPoolId].bufferSizeOfFlatBuf = bufferSize;
    return 1;
}

static __inline__ uint8_t* flatBufferAlloc(uint32_t size,uint8_t assignedPoolId)
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

static __inline__ void * allocMem(uint32_t size,uint8_t assignedPoolId)
{
    //or call user specified mem alloc function
    if(assignedPoolId >= MAX_POOL_NR){
        return 0;
    }
    return (void *)flatBufferAlloc(size,assignedPoolId);
}

#endif
