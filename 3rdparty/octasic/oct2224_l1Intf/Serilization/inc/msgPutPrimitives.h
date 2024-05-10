/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgPutPrimitives.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Message Put Primitives

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _MSGPUTPRIMITIVES_H_
#define _MSGPUTPRIMITIVES_H_

#include "l1IntEnums.h"
#include "l1capi_typedef.h"
#include "msgPrimitives.h"

#ifdef L1C_TRACE_CONTENT
#define ADD_BYTE_VAL(value) \
	{PRINT_SPACE;\
	PRINTF(#value"=%d\n",value); \
	addByteVal(value);}

#define ADD_WORD_VAL(value) \
	{PRINT_SPACE;\
	PRINTF(#value"=%d\n",value); \
	addWordVal(value);}

#define ADD_LONG_VAL(value) \
	{PRINT_SPACE;\
	PRINTF(#value"=0x%x\n",value); \
	addLongVal(value);}
#else
#define ADD_BYTE_VAL(value) \
	addByteVal(value);

#define ADD_WORD_VAL(value) \
	addWordVal(value);

#define ADD_LONG_VAL(value) \
	addLongVal(value);
#endif

static __inline__ void      resetMsgWrite(uint8_t *memStart);
static __inline__ uint16_t  findMsgBodySize(void);
static __inline__ void      addByteVal(uint8_t byteVal);
static __inline__ void      addWordVal(uint16_t wordVal);
static __inline__ void      addLongVal(uint32_t longVal);
static __inline__ void      addByteValHdr(uint8_t byteVal);
static __inline__ void      addWordValHdr(uint16_t wordVal);
static __inline__ void      addLongValHdr(uint32_t longVal);
static __inline__ uint8_t * getCurrentBodyWrPtr(void);
static __inline__ void      addBodyWrOffset(uint32_t bodyWrOffset);
static __inline__ void      resetMsgRead(uint8_t *newMsgPtr);

extern void *pHostDLMsg;

extern uint8_t *msgStartWrPtr;
extern uint8_t *currentBodyWrPtr; 
extern uint8_t *currentHdrWrPtr;

/******************************************************
     Inline Functions Definitions
*******************************************************/

static __inline__ void resetMsgWrite(uint8_t *memStart)
{
	msgStartWrPtr    = memStart;
    currentHdrWrPtr  = memStart;
    currentBodyWrPtr = memStart + MSG_HDR_SIZE;
#ifdef L1C_TRACE_CONTENT
	space_counter = SHIFT_SPACE;
#endif
}

static __inline__ uint16_t findMsgBodySize(void)
{
    return (uint16_t)(currentBodyWrPtr - msgStartWrPtr - MSG_HDR_SIZE);
}

static __inline__ void addByteVal(uint8_t byteVal)
{
    *currentBodyWrPtr = byteVal;
    currentBodyWrPtr++;
}

static __inline__ void addWordVal(uint16_t wordVal)
{
    *((uint16_t *)currentBodyWrPtr) = SWAP_ENDIAN_16(wordVal);
    currentBodyWrPtr += sizeof(uint16_t);
}

static __inline__ void addLongVal(uint32_t longVal)
{
    *((uint32_t *)currentBodyWrPtr) = SWAP_ENDIAN_32(longVal);
    currentBodyWrPtr += sizeof(uint32_t);
}

static __inline__ uint8_t *getCurrentBodyWrPtr(void)
{
    return currentBodyWrPtr;
}

static __inline__ void addBodyWrOffset(uint32_t bodyWrOffset)
{
    currentBodyWrPtr += bodyWrOffset;
}

static __inline__ void addByteValHdr(uint8_t byteVal)
{
    *currentHdrWrPtr = byteVal;
    currentHdrWrPtr++;
}

static __inline__ void addWordValHdr(uint16_t wordVal)
{
    *((uint16_t *)currentHdrWrPtr) = SWAP_ENDIAN_16(wordVal);
    currentHdrWrPtr += sizeof(uint16_t);
}

static __inline__ void addLongValHdr(uint32_t longVal)
{
    *((uint32_t *)currentHdrWrPtr) = SWAP_ENDIAN_32(longVal);
    currentHdrWrPtr += sizeof(uint32_t);
}

#endif
