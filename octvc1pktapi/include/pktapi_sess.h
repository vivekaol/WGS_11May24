/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_SESS.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __PKTAPI_SESS_H__
#define __PKTAPI_SESS_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../common/octosal/include/octosal.h"

#include "pktapi_cnct.h"
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
#define cPKTAPI_MAGIC_SESS					(0xBABA0003)
#define cPKTAPI_SESS_HANDLE_DISCOVER_UNIQUE	(0x5200)

#define cPKTAPI_SESS_SESSION_INVALID		(0xFFFFFFFF)

#define mPKTAPI_SESS_HANDLE_GET_INDEX( _f_hSession )	\
										(_f_hSession&0x000000FF)

#define mPKTAPI_SESS_HANDLE_GET_UNIQUE( _f_hSession )	\
										((_f_hSession&0xFFFF0000)>>16)

#define mPKTAPI_SESS_HANDLE_GET_CNCT_INDEX( _f_hSession )	\
										((_f_hSession&0x0000FF00)>>8)

#define mPKTAPI_SESS_HANDLE_BUILD_INDEX( _f_ulConnectionIndex, _f_ulSessionIndex, _f_ulUnique )	\
										((_f_ulSessionIndex&0x000000FF)|((_f_ulConnectionIndex&0x000000FF)<<8 )|((_f_ulUnique&0x0000FFFF)<<16 ))
		

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
#define mPKTAPI_SESS_MUTEX_SEIZE( _f_pSess )	\
	OctOsalMutexSeize( _f_pSess->hMutex, cOCTOSAL_TIMEOUT_FOREVER )

#define mPKTAPI_SESS_MUTEX_RELEASE( _f_pSess )	\
	OctOsalMutexRelease( _f_pSess->hMutex )

#else
#define mPKTAPI_SESS_MUTEX_SEIZE( _f_pSess )
#define mPKTAPI_SESS_MUTEX_RELEASE( _f_pSess )

#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

#define cPKTAPI_SESS_PENDING_RSP_MAX		8		/* Max number of waiting response per session ... MUST be in sync with MGW */

/***************************  STRUCTURES *************************************/

struct _PKTAPI_CNCT_INF_;

#define	tPKTAPI_SESS_INF_FLAG_MASK							tOCT_UINT32
#define cPKTAPI_SESS_INF_FLAG_MASK_NONE						0x00000000
#define cPKTAPI_SESS_INF_FLAG_MASK_ALLOW_RESEND				0x00000001
#define cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING			0x00000002
#define cPKTAPI_SESS_INF_FLAG_MASK_RESYNC					0x00000004
#define cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT		0x00000008
#define cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION	0x00000010
#define cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION	0x00000020
#define cPKTAPI_SESS_INF_FLAG_MASK_DID_RESEND				0x00000040



/*----------------------------------------------------------------------------
	Connection structure
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32						ulMagic;
	tOCT_UINT32						byIndex;			/* Session index in connection session array (8-bits) */
	tOCT_UINT32						hSession;			/* Session handle 
															[31:16] usInstance
															[15:0]	Session index in session array of connection structure
														*/
//	tOCT_UINT32						fResynch;			/* Indicates if the resynch flag has to be set for the command */
	tOCT_UINT16						usInstance;			/* Session instance (16-bits) */

	struct _PKTAPI_CNCT_INF_ *		pCnct;				/* Pointer to connection */
	void *							pUserContext;		/* User session context */

	tOCT_UINT32						ulProcessFifoId;	/* Vocallo process control Fifo ID */

	tOCT_UINT32						ulTransactionId;	/* Next transaction Id */
	tOCT_UINT32						ulRxTransactionId;	/* Expected Rx transaction Id */
	tOCT_UINT32						ulRxRejectId;		/* Expected Reject transaction Id */
	tOCT_UINT32						ulResentId;			/* Resent transaction Id */

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	tOCTOSAL_HANDLE_MUTEX			hMutex;
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

	tOCTVC1_PKT_API_SESS_STATS_PARMS	
									Stats;				/* Statistics structure */

	tPKTAPI_SESS_INF_FLAG_MASK		fFlag;				/* Allow Resend Missing response .. disable when detect MGW<1.5.x */
#if 0
	tOCT_BOOL32						fAllowResend;		
	tOCT_BOOL32						fForcePending;		/* Can't send until specific reason */
	tOCT_BOOL32						fRetransmittingOnTimeout;		/* Can't resend cause on bad response sequence */
#endif
	tOCT_UINT32						ulPendingRspCount;	/* Number of cmd sent to Mgw waiting for response */
	tPKTAPI_PKT_Q_INF 				PktQPendingCmd;		/* packet Q for PendingCmd */
	
	tOCT_UINT32						ulActiveTimeout;	/* Sum of all pending response timeout */

} tPKTAPI_SESS_INF, *tPPKTAPI_SESS_INF;


/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
	PktApiSessCmdSend
----------------------------------------------------------------------------*/
tOCT_UINT32	PktApiSessCmdSend(
	tPKTAPI_SESS_INF *					f_pSessInf,
	tPOCTVC1_PKT_API_CMD_SEND_PARMS		f_pParms,
	unsigned int						f_ulQIndex,
	unsigned int						f_ulDependencyCnt,
	tPKTAPI_PKT_INF *					f_pPktInf );


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __PKTAPI_SESS_H__*/
