/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_PKT.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __PKTAPI_PKT_H__
#define __PKTAPI_PKT_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../common/octosal/include/octosal.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/
#define cPKTAPI_Q_INVALID	(0xFFFFFFFF)
#define cPKTAPI_Q_FREE		(0)
#define cPKTAPI_Q_BUSY		(1)
#define cPKTAPI_Q_SPECIAL	(2)
#define cPKTAPI_Q_CNT		(cPKTAPI_Q_SPECIAL+1)

#define	tPKTAPI_PKT_INF_FLAG_MASK					tOCT_UINT32
#define cPKTAPI_PKT_INF_FLAG_MASK_DEPENDENCY_CNT	0x0000FFFF
#define cPKTAPI_PKT_INF_FLAG_MASK_RESYNC			0x80000000
#define cPKTAPI_PKT_INF_FLAG_MASK_RETRANSMIT		0x40000000

/*****************************  MACROS **************************************/
#ifndef mMIN
#define mMIN( a, b ) ((a>b)?b:a)
#endif

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD

#define mPKTAPI_PKT_Q_MUTEX_SEIZE( _f_pPktQ )	\
	OctOsalMutexSeize( _f_pPktQ->hMutex, cOCTOSAL_TIMEOUT_FOREVER )

#define mPKTAPI_PKT_Q_MUTEX_RELEASE( _f_pPktQ )	\
	OctOsalMutexRelease( _f_pPktQ->hMutex )

#define mPKTAPI_PKT_Q_SYNC_SIGNAL_SET( _f_pPktQ )	\
	OctOsalSyncSignalSet( _f_pPktQ->hSyncSignal )

#else

#define mPKTAPI_PKT_Q_MUTEX_SEIZE( _f_pPktQ )	
#define mPKTAPI_PKT_Q_MUTEX_RELEASE( _f_pPktQ )	
#define mPKTAPI_PKT_Q_SYNC_SIGNAL_SET( _f_pPktQ )

#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

/***************************  STRUCTURES *************************************/

/*----------------------------------------------------------------------------
	Packet structure
----------------------------------------------------------------------------*/
typedef struct _PKTAPI_PKT_INF_
{
	struct _PKTAPI_PKT_INF_	*		pPrevious;		/* Previous packet */
	struct _PKTAPI_PKT_INF_	*		pNext;			/* Next packet */

	tOCT_UINT32						ulOwnerQ;		/* MAGIC_ID & Index of the packet queue owner. */
	tOCT_UINT32						ulStartTimeMs;	/* Time at which packet has been put in Q */
	tOCT_UINT32						ulTimeoutMs;	/* Single cmd expected timeout in milliseconds */


	tOCTVC1_PKT_API_INST_RECV_PARMS	RecvParms;		/* Packet information. pPayload points just after this structure */
	tPKTAPI_PKT_INF_FLAG_MASK		ulFlag;			/* Pkt flag cPKTAPI_PKT_INF_FLAG_MASK */
	tOCT_UINT32						ulRetry;
													/* Packet dependency count */
	/* Data to match command with response */
	tOCT_UINT32						ulSessionId;	/* API Session Id.  */
	tOCT_UINT32						ulUserInfo;		/* User Information as set by the user in the cmd header */
	tOCT_UINT32						ulTransactionId;/* Transaction ID. */
							
} tPKTAPI_PKT_INF, *tPPKTAPI_PKT_INF;

typedef struct
{
	tOCT_UINT32						ulPktCnt;		/* Count of Packet in Q */
	tPPKTAPI_PKT_INF				pPktHead;		/* First packet in Q */
	tPPKTAPI_PKT_INF				pPktTail;		/* Last packet in Q */

} tPKTAPI_PKT_Q, *tPPKTAPI_PKT_Q;

/*----------------------------------------------------------------------------
	Packet Q structure
----------------------------------------------------------------------------*/
typedef struct _PKTAPI_PKT_Q_INF_
{

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	tOCTOSAL_HANDLE_MUTEX			hMutex;			/* Mutual exclusion object */
	tOCTOSAL_HANDLE_SYNC_SIGNAL		hSyncSignal;	/* Sync Signal */
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

	tPKTAPI_PKT_Q					aQueue[cPKTAPI_Q_CNT];

} tPKTAPI_PKT_Q_INF, *tPPKTAPI_PKT_Q_INF;


/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
	PktApiPktQueueOpen
		This function opens a packet queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueueOpen(
	tPPKTAPI_PKT_Q_INF			f_pPktQ );

/*--------------------------------------------------------------------------
	PktApiPktQueueClose
		This function closes a packet queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueueClose(
	tPPKTAPI_PKT_Q_INF			f_pPktQ );

/*--------------------------------------------------------------------------
	PktApiPktQueueGet
		This function retrieves a packet from a queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueGet(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ );



/*--------------------------------------------------------------------------
	PktApiPktQueueExtract
		This function extract a packet with matching session and transaction 
		ID from a queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueExtract(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	unsigned int				f_ulSessionId,
	tOCT_UINT32					f_ulTransactionId );

/*--------------------------------------------------------------------------
	PktApiPktQueueExtractAny
		This function extract first packet with matching session from a queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueExtractAny(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	unsigned int				f_ulSessionId );



/*--------------------------------------------------------------------------
	PktApiPktQueuePut
		This function puts a packet in a queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
  f_pPkt	: IN Pointer to packet.
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueuePut(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tPPKTAPI_PKT_INF			f_pPkt );


/*--------------------------------------------------------------------------
	PktApiPktQueuePutAndSignal
		This function puts a packet in a queue and set the associated sync signal

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
  f_pPkt	: IN Pointer to packet.
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueuePutAndSignal(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tPPKTAPI_PKT_INF			f_pPkt );

/*--------------------------------------------------------------------------
	PktApiPktQueuePutList
		This function puts a packet list in a queue.

  f_pInst	: IN Pointer to instance.
  f_pPktQ	: IN Pointer to packet Q.
  f_pPkt	: IN Pointer to packet list head.
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueuePutList(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tPPKTAPI_PKT_INF			f_pPktListHead );

/*--------------------------------------------------------------------------
	PktApiPktQueueTimeoutCheck
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueTimeoutCheck(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	unsigned					f_ulCurrentTimeMs );

/*--------------------------------------------------------------------------
	PktApiPktQueueCountGet
----------------------------------------------------------------------------*/
unsigned int PktApiPktQueueCountGet(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ );

/*--------------------------------------------------------------------------
	PktApiPktQueueMinTransactionIdGet
----------------------------------------------------------------------------*/
unsigned int PktApiPktQueueMinTransactionIdGet(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tOCT_UINT32					f_ulSessionId );



/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __PKTAPI_PKT_H__*/
