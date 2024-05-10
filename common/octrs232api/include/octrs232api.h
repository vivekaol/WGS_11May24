/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octrs232api.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description:	RS232 Abstraction Layer

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTRS232API_H__
#define __OCTRS232API_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../include/octdev_types.h"
#include "../../include/octcommon_base.h"


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif



/*----------------------------------------------------------------------------
	Return code
----------------------------------------------------------------------------*/
typedef tOCT_UINT32						tOCTRS232API_RC;

#define cOCTRS232API_RC_OK				0
#define cOCTRS232API_RC_BAD_PARAM		( 0x0001 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_ALREADY_OPEN	( 0x0002 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_INTERNAL		( 0x0003 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_BAD_PORT_INDEX	( 0x0004 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_CANT_OPEN_PORT	( 0x0005 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_BAD_PORT_HANDLE	( 0x0006 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_PORT_CLOSED		( 0x0007 + cOCTRS232API_RC_BASE )
#define cOCTRS232API_RC_RECV_NONE		( 0x0008 + cOCTRS232API_RC_BASE )


/*----------------------------------------------------------------------------
	Limits
----------------------------------------------------------------------------*/
#define cOCTRS232API_MAX_PORT_INST	8		/* Max port instance */
#define cOCTRS232API_PORT_NAME_LEN	32

#ifdef WIN32
#define cOCTRS232API_PORT_NAME_DEF "COM1"
#else
#define cOCTRS232API_PORT_NAME_DEF "/dev/ttyS0"
#endif


/***************************  STRUCTURES *************************************/
/*--------------------------------------------------------------------------
	Open Port Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT8	szPortName[cOCTRS232API_PORT_NAME_LEN+1];

	tOCT_UINT32	ulBaudRate;			/* Default 38400 */

	/* OUT */
	tOCT_UINT32	hPort;				/* RS232 port Handle */

} tOCTRS232API_OPEN_PORT, *tPOCTRS232API_OPEN_PORT;

/*--------------------------------------------------------------------------
	Close Port Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	hPort;			/* RS232 port Handle */

} tOCTRS232API_CLOSE_PORT, *tPOCTRS232API_CLOSE_PORT;

/*--------------------------------------------------------------------------
	Receive functions
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	hPort;				/* RS232 port Handle */
	tOCT_UINT8	byData;				/* data */

} tOCTRS232API_GET_CHAR, *tPOCTRS232API_GET_CHAR;

typedef struct
{
	tOCT_UINT32	hPort;				/* RS232 port Handle */

	tOCT_UINT32	ulLen;				/* Buffer len */
	tOCT_UINT8*	pbyBuffer;			/* Buffer */

	/* OUT */
	tOCT_UINT32	ulRecvLen;			/* Received len */

} tOCTRS232API_GET_BUFFER, *tPOCTRS232API_GET_BUFFER;

/*--------------------------------------------------------------------------
	Transmit functions
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	hPort;			/* RS232 port Handle */
	tOCT_UINT8	byData;			/* data */

} tOCTRS232API_PUT_CHAR, *tPOCTRS232API_PUT_CHAR;

typedef struct
{
	tOCT_UINT32	hPort;			/* RS232 port Handle */
	tOCT_UINT32	ulLen;			/* Buffer len */
	tOCT_UINT8*	pbyBuffer;		/* data */

} tOCTRS232API_PUT_BUFFER, *tPOCTRS232API_PUT_BUFFER;


/*--------------------------------------------------------------------------
	DTR functions
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	hPort;			/* RS232 port Handle */
	tOCT_UINT32	fState;			/* 0 or 1 */

} tOCTRS232API_SET_DTR, *tPOCTRS232API_SET_DTR;

/*--------------------------------------------------------------------------
	RTS functions
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	hPort;			/* RS232 port Handle */
	tOCT_UINT32	fState;			/* 0 or 1 */

} tOCTRS232API_SET_RTS, *tPOCTRS232API_SET_RTS;



/*--------------------------------------------------------------------------
	Flush functions
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	hPort;			/* RS232 port Handle */
	tOCT_UINT32	fFlushRx;		/* Default 1 */
	tOCT_UINT32	fFlushTx;		/* Default 1 */

} tOCTRS232API_FLUSH, *tPOCTRS232API_FLUSH;



/*****************************  FUNCTIONS ************************************/
extern tOCTRS232API_RC OctRS232ApiOpenPortDef( tPOCTRS232API_OPEN_PORT f_pParm );
extern tOCTRS232API_RC OctRS232ApiOpenPort( tPOCTRS232API_OPEN_PORT f_pParm );

extern tOCTRS232API_RC OctRS232ApiClosePortDef( tPOCTRS232API_CLOSE_PORT f_pParm );
extern tOCTRS232API_RC OctRS232ApiClosePort( tPOCTRS232API_CLOSE_PORT f_pParm );

extern tOCTRS232API_RC  OctRS232ApiGetCharDef( tPOCTRS232API_GET_CHAR f_pParm );
extern tOCTRS232API_RC  OctRS232ApiGetChar( tPOCTRS232API_GET_CHAR f_pParm );

extern tOCTRS232API_RC  OctRS232ApiGetBufferDef( tPOCTRS232API_GET_BUFFER f_pParm );
extern tOCTRS232API_RC  OctRS232ApiGetBuffer( tPOCTRS232API_GET_BUFFER f_pParm );

extern tOCTRS232API_RC  OctRS232ApiPutCharDef( tPOCTRS232API_PUT_CHAR f_pParm );
extern tOCTRS232API_RC  OctRS232ApiPutChar( tPOCTRS232API_PUT_CHAR f_pParm );

extern tOCTRS232API_RC  OctRS232ApiPutBufferDef( tPOCTRS232API_PUT_BUFFER f_pParm );
extern tOCTRS232API_RC  OctRS232ApiPutBuffer( tPOCTRS232API_PUT_BUFFER f_pParm );

extern tOCTRS232API_RC  OctRS232ApiFlushDef( tPOCTRS232API_FLUSH f_pParm );
extern tOCTRS232API_RC  OctRS232ApiFlush( tPOCTRS232API_FLUSH f_pParm );

extern tOCTRS232API_RC OctRS232ApiSetDtrDef( tPOCTRS232API_SET_DTR f_pParm );
extern tOCTRS232API_RC OctRS232ApiSetDtr( tPOCTRS232API_SET_DTR f_pParm );

extern tOCTRS232API_RC OctRS232ApiSetRtsDef( tPOCTRS232API_SET_RTS f_pParm );
extern tOCTRS232API_RC OctRS232ApiSetRts( tPOCTRS232API_SET_RTS f_pParm );


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif


#endif /* __OCTRS232API_H__*/
