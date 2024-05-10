/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_INST.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __PKTAPI_INST_H__
#define __PKTAPI_INST_H__

/*****************************  INCLUDE FILES  *******************************/
/* Porting interface */
#include "../../common/octosal/include/octosal.h"
#include "../../common/octtransapi/include/octtransapi.h"

/* Keep previous notations */
#ifdef OCTOSAL_OPT_MULTI_THREAD
#ifndef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
#define OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */
#endif /* OCTOSAL_OPT_MULTI_THREAD */

/* Keep previous notations */
#ifdef OCTTRANSAPI_OPT_SELECT
#ifndef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
#define OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
#endif /* OCTTRANSAPI_OPT_SELECT */

/* User interface */
#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api.h"
#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api_default.h"
#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api_version.h"

#include "pktapi_cnct.h"
#include "pktapi_sess.h"
#include "pktapi_pkt.h"
#include "pktapi_common.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/
/*----------------------------------------------------------------------------
	MAGIC
----------------------------------------------------------------------------*/
#define cPKTAPI_MAGIC_INST			(0xBABA0001)

/*****************************  MACROS **************************************/

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD

#define mPKTAPI_INST_MUTEX_TIMED_SEIZE( _f_pInst, _f_ulTimeoutMs )	\
	OctOsalMutexSeize( _f_pInst->hMutex, _f_ulTimeoutMs )

#define mPKTAPI_INST_MUTEX_SEIZE( _f_pInst )	\
	OctOsalMutexSeize( _f_pInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER )

#define mPKTAPI_INST_MUTEX_RELEASE( _f_pInst )	\
	OctOsalMutexRelease( _f_pInst->hMutex )


#define mPKTAPI_INST_RECVMUTEX_TIMED_SEIZE( _f_pInst, _f_ulTimeoutMs )	\
	OctOsalMutexSeize( _f_pInst->hRecvMutex, _f_ulTimeoutMs )

#define mPKTAPI_INST_RECVMUTEX_RELEASE( _f_pInst )	\
	OctOsalMutexRelease( _f_pInst->hRecvMutex )

#define mPKTAPI_MUTEX_OPEN( _f_phMutex	)	\
	OctOsalMutexOpen(  _f_phMutex )

#define mPKTAPI_MUTEX_CLOSE( _f_phMutex	)	\
	OctOsalMutexClose( *(_f_phMutex) )


#define mPKTAPI_INST_QUEUEMUTEX_SEIZE( _f_pInst )	\
	OctOsalMutexSeize( _f_pInst->hQueueMutex, cOCTOSAL_TIMEOUT_FOREVER )

#define mPKTAPI_INST_QUEUEMUTEX_RELEASE( _f_pInst )	\
	OctOsalMutexRelease( _f_pInst->hQueueMutex )


#define mPKTAPI_SYNC_SIGNAL_OPEN( _f_phSyncSignal	)	\
	OctOsalSyncSignalOpen(  _f_phSyncSignal )

#define mPKTAPI_SYNC_SIGNAL_CLOSE( _f_phSyncSignal	)	\
	OctOsalSyncSignalClose( _f_phSyncSignal )

#else

#define mPKTAPI_INST_MUTEX_TIMED_SEIZE( _f_pInst, _f_ulTimeoutMs )	(0)
#define mPKTAPI_INST_MUTEX_SEIZE( _f_pInst )
#define mPKTAPI_INST_MUTEX_RELEASE( _f_pInst )

#define mPKTAPI_INST_RECVMUTEX_TIMED_SEIZE( _f_pInst, _f_ulTimeoutMs )	(0)
#define mPKTAPI_INST_RECVMUTEX_RELEASE( _f_pInst )

#define mPKTAPI_INST_QUEUEMUTEX_SEIZE( _f_pInst )
#define mPKTAPI_INST_QUEUEMUTEX_RELEASE( _f_pInst )

#define mPKTAPI_MUTEX_OPEN( _f_phMutex )  (0)
#define mPKTAPI_MUTEX_CLOSE( _f_phMutex	)

#define mPKTAPI_SYNC_SIGNAL_OPEN( _f_phSyncSignal	)	(0)
#define mPKTAPI_SYNC_SIGNAL_CLOSE( _f_phSyncSignal	)

#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

/***************************  STRUCTURES *************************************/

/*----------------------------------------------------------------------------
	Instance structure

	Memory is structured as follow:

	+----------------------------------
	| tPKTAPI_INST_INF
	|
	|
	|
	 \
	| tPKTAPI_INST_INF::aCnctIn	         |-----
	|                                           \
	| tPKTAPI_INST_INF::paPktQ  ---------\      |
	+---------------------------------+   |     |
	| tPKTAPI_PKT_Q_INF[]             <--/      |
	|   Packet Qs                               |
	|		= MAX packetType + ulMaxSyncCmd     |
	+----------------------------------         |
	| tPKTAPI_PKT_INF[]                         |
	|   All packets linked in one of the        |
	|		tPKTAPI_INST_INF::paPktQ            |
	+----------------------------------         |
	| tPKTAPI_CNCT_INF[]               <-------/
	|   Connections
	| tPKTAPI_CNCT_INF::paSessInf      |-----
	|                                         \
	| +--------------------------------        |
	| | tPKTAPI_SESS_INF[]             <------/
	| +--------------------------------
	+----------------------------------

----------------------------------------------------------------------------*/

typedef struct _PKTAPI_INST_INF_
{
	tOCT_UINT32						ulMagic;

	tOCTTRANSAPI_CONTEXT			pTransportContext;	/* Porting transport layer context, submitted to Porting transport layer functions */
	tOCT_UINT32						ulCmdTimeoutMs;		/* Command execution timeout in milliseconds */
	tOCT_UINT32						ulMaxRetry;			/* Maximum number of retry before a command get timeout */

	/* Keep for InstInfo */
	tOCT_UINT32						ulMaxConnection;	/* Maximum connection on this instance */
	tOCT_UINT32						ulMaxSession;		/* Maximum session per connection on this instance */
	tOCT_UINT32						ulMaxSyncCmd;		/* Maximum simultaneous synchronous command */

	tOCT_UINT32						ulMaxPendingRsp;	/* Maximum pending response packet in queue */
	tOCT_UINT32						ulMaxPendingEvt;	/* Maximum pending event packet in queue */
	tOCT_UINT32						ulMaxPendingData;	/* Maximum pending data packet in queue  */
	tOCT_UINT16						usSessionInstanceStart;
														/* 16 MSB of session identifier start instance */

	tOCT_UINT8						abyLocalMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Local MAC address */
	tOCTTRANSAPI_CONTEXT			pTransportLocalContext;
														/* Transport local context */

	tOCTTRANSAPI_HANDLE				hTransport;			/* Local transport object */
	tOCT_BOOL32						fReady;				/* Boolean indicating if instance is ready */
	tOCT_UINT32						ulPendingRspElapseMs; /* Keep elapse time when rsp is waiting for somebody else*/

	tOCT_BOOL32						fChckTimeout;

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	tOCTOSAL_HANDLE_MUTEX			hMutex;				/* Mutual exclusion object */
	tOCTOSAL_HANDLE_MUTEX			hRecvMutex;			/* Mutual exclusion object */
	tOCTOSAL_HANDLE_MUTEX			hQueueMutex;			/* Mutual exclusion object */
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
	tOCTTRANSAPI_HANDLE				hTransportLoopback;	/* Loop-back transport object */
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */

	tOCT_UINT8						abyMemory[cPKTAPI_PAYLOAD_MAX + cPKTAPI_PAYLOAD_ALIGNMENT_PADDING];
														/* Buffer to hold RxBuffer */
	tOCT_UINT8 *					pabyRxBuffer;
														/* Transport reception buffer */
														/* Pointer to abyMemory (with care to alignment for processing) */

	tOCT_UINT32						ulCnctCnt;			/* Count of connections in paCnctInf array */
	tPKTAPI_CNCT_INF *				paCnctInf;			/* Array of connections */

	tOCT_UINT32						ulPktQCnt;			/* Count of packet Q in paPktQ array */
	tPKTAPI_PKT_Q_INF *				paPktQ;				/* Point to array of packet Q */

	tOCTVC1_PKT_API_INST_STATS_PARMS
									Stats;				/* Statistics structure */

	tPKTAPI_CNCT_INF				DiscoverCnct;		/* Connection used for discovery */
	tPKTAPI_SESS_INF				DiscoverSess;		/* Session used for discovery */

	tOCTVC1_PKT_API_TRANSPORT_FUNC	TransportFunc;		/* Transport Fnc */
	tOCTVC1_PKT_API_INSTANCE_OPTION_MASK	ulOptionMask;	/* Option mask */

	tOCT_BOOL32						fUseExternalTransport;		/* Application is taking care of the transport */
	tOCTTRANSAPI_DISPATCHER_HANDLE	hTransDispatcher;		/* Application did start a dispatch thread */

	tOCT_UINT32						ulTimeoutCheckMs;	/* Time to check timeout */
} tPKTAPI_INST_INF, *tPPKTAPI_INST_INF;

/*****************************  FUNCTIONS ************************************/
/*--------------------------------------------------------------------------
	PktApiInstDispatchFnc
		Dispatch a received packet
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR PktApiInstDispatchFnc( void * f_pAppContext, tOCTTRANSAPI_RECV_PARMS *f_pParms );
tOCT_UINT32 PktApiInstDispatchAddTransport( tPKTAPI_INST_INF *	f_pInst, tOCTTRANSAPI_HANDLE f_hTrans );
tOCT_UINT32 PktApiInstDispatchRemoveTransport( tPKTAPI_INST_INF *	f_pInst, tOCTTRANSAPI_HANDLE f_hTrans );

/*--------------------------------------------------------------------------
	PktApiInstCalcElapsedTimeMs
		Calculate elapsed time between start time and current
----------------------------------------------------------------------------*/
unsigned int PktApiInstCalcElapsedTimeMs(
	unsigned int		f_ulCurrentTimeMs,
	unsigned int		f_ulStartTimeMs );

/*--------------------------------------------------------------------------
	PktApiInstRecv
----------------------------------------------------------------------------*/
tOCT_UINT32	PktApiInstRecv(
	tPKTAPI_INST_INF *				f_pInst,
	unsigned int					f_aulPktType[],
	unsigned int					f_ulPktTypeCnt,
	unsigned int					f_ulTimeoutQType,
	tPOCTVC1_PKT_API_INST_RECV_PARMS		f_pParms );


#define cPKTAPI_INST_UNLOCK_REASON_CNCT_OPEN	(1)
#define cPKTAPI_INST_UNLOCK_REASON_CNCT_CLOSE	(2)
#define cPKTAPI_INST_UNLOCK_REASON_CMD_TIMEOUT	(3)
#define cPKTAPI_INST_UNLOCK_REASON_TERMINATE	(4)


#define cPKTAPI_INST_TIMEOUT_CMD_DEF		(200)		/* Default command timeout (ms) */
#define cPKTAPI_INST_MID_TIMEOUT_CMD_DEF	(1510)		/* Default command timeout (ms) */
#define cPKTAPI_INST_LONG_TIMEOUT_CMD_DEF	(30010)		/* Default command timeout (ms) */

/*--------------------------------------------------------------------------
	PktApiInstUnlock
		This function unlocks the instance by sending a loopback packet.
		Used when select is supported
----------------------------------------------------------------------------*/
int PktApiInstUnlock(
	tPKTAPI_INST_INF *				f_pInst,
	unsigned int					f_ulReason );

/*--------------------------------------------------------------------------
	PktApiFindMinPendingTransactionId

----------------------------------------------------------------------------*/
tOCT_BOOL32 PktApiFindMinPendingTransactionId( tPKTAPI_INST_INF * f_pInst, tPKTAPI_SESS_INF *f_pSessInf );


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __PKTAPI_INST_H__*/
