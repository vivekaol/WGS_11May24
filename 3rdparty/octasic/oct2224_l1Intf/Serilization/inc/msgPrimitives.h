/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: msgPrimitives.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control Message Primitives

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _MSGPRIMITIVES_H_
#define _MSGPRIMITIVES_H_

#if defined( _MSC_VER )
#define __inline__ __inline
#endif

#define MSG_HDR_SIZE 0x08  /*8 bytes for L1CAPI_MsgHdr, enum to use uint16_t*/
#define MSG_FTR_SIZE 0  

#define SHIFT_SPACE (8)

#ifdef PRINT_IO_CONSOLE
#define PRINTF(...) \
	printf(__VA_ARGS__);
#else 
#ifdef PRINT_IO_FILE
#define PRINTF(...) \
	fprintf(ioHandle,__VA_ARGS__);	
#else
#define	PRINTF(...)
#endif
#endif

#ifdef L1C_TRACE_CONTENT

extern char space_counter;
extern char space_counter_iter;

#define START_BLOCK_TRACE \
	space_counter++;

#define END_BLOCK_TRACE \
	space_counter--;

#define PRINT_SPACE \
	for(space_counter_iter = 0;space_counter_iter<space_counter;space_counter_iter++)\
	{\
		PRINTF(" ");\
	}


#else
#define START_BLOCK_TRACE
#define END_BLOCK_TRACE
#define PRINT_SPACE
#endif


#endif
