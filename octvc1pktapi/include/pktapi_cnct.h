/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_CNCT.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __PKTAPI_CNCT_H__
#define __PKTAPI_CNCT_H__

/*****************************  INCLUDE FILES  *******************************/
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
#define cPKTAPI_MAGIC_CNCT			(0xBABA0002)

/*****************************  MACROS **************************************/

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
#define mPKTAPI_CNCT_MUTEX_SEIZE( _f_pCnct )	\
	OctOsalMutexSeize( _f_pCnct->hMutex, cOCTOSAL_TIMEOUT_FOREVER )

#define mPKTAPI_CNCT_MUTEX_RELEASE( _f_pCnct )	\
	OctOsalMutexRelease( _f_pCnct->hMutex )

#else
#define mPKTAPI_CNCT_MUTEX_SEIZE( _f_pCnct )
#define mPKTAPI_CNCT_MUTEX_RELEASE( _f_pCnct )

#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */


/***************************  STRUCTURES *************************************/

struct _PKTAPI_INST_INF_;
/*----------------------------------------------------------------------------
	Connection structure
----------------------------------------------------------------------------*/
typedef struct _PKTAPI_CNCT_INF_
{
	tOCT_UINT32						ulMagic;
	tOCT_UINT32						byIndex;			/* Connection index in instance's connection array (8-bits) */
	struct _PKTAPI_INST_INF_ *		pInst;				/* Pointer to instance */

	void *							pUserContext;		/* User connection context */

	tOCT_UINT8						abyRemoteMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];	
														/* Remote MAC address */

	void *							pTransportRemoteContext;
														/* Transport Remote context */

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	tOCTOSAL_HANDLE_MUTEX			hMutex;				/* Mutual exclusion object */
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

	tOCT_UINT32						ulSessCnt;			/* Count of sessions in paSessInf array */
	tPKTAPI_SESS_INF *				paSessInf;			/* Array of session */
	
	tOCTVC1_PKT_API_CNCT_STATS_PARMS	
									Stats;				/* Statistics structure */

	tOCT_UINT32						ulRoutingHeaderLen;	/* Length of the routing header 
															MACs + EtherType + Tunnel (if any) */

	tOCT_UINT8						abyMemory[cPKTAPI_ROUTING_HEADER_SIZE + cPKTAPI_PAYLOAD_ALIGNMENT_PADDING];
														/* Buffer to hold RoutingHeader */
	tOCT_UINT8 *					pabyRoutingHeader;	/* Connection routing header */
														/* Pointer to abyMemory (with care to alignment for processing) */

	tPKTAPI_PKT_INF					StaticPktInf;		/* Static packet information structure, used 
														to transmit connectionless packets (DATA,...)
														RecvParms::pPayload points to abyTxBuffer,
														Usage of this structure is protected by the connection lock */
	tOCT_UINT8						abyMemoryTx[cPKTAPI_PAYLOAD_MAX + cPKTAPI_PAYLOAD_ALIGNMENT_PADDING];
														/* Buffer used to transmit connectionless packets (DATA,...)
															Usage of this buffer is protected by the connection lock */

	tOCT_UINT8 *					pabyTxBuffer;		/* Buffer used to transmit connectionless packets (DATA,...)
															Usage of this buffer is protected by the connection lock */

	tOCTTRANSAPI_DESTINATION_HANDLE	hTransDest;			/* Transport destination */
	tOCTTRANSAPI_HANDLE				hTransport;			/* Associated Transport */
	tOCTPKT_HDR_TYPE_ENUM			ulPktHdrType;		/* Specify if transport is using tOCTPKT_HDR_TYPE */

} tPKTAPI_CNCT_INF, *tPPKTAPI_CNCT_INF;


/***************************  STRUCTURES *************************************/



/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
	PktApiCnctPktSend
		This function sends a packet on the connection.

  f_pCnctInf	: IN pointer to the connection.
  f_ulQIndex	: IN Queue index.
  f_ulPktQType	: IN Queue type index.
  f_ulFormat	: IN Packet format.
  f_pPktInf		: IN Pointer to packet.
  f_fRetransmit	: IN Indicates if this packet is submit for retransmit
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiCnctPktSend(
	tPKTAPI_CNCT_INF *					f_pCnctInf,
	unsigned int						f_ulQIndex,
	unsigned int						f_ulPktQType,
	unsigned int						f_ulFormat,
	tPKTAPI_PKT_INF *					f_pPktInf );

/*--------------------------------------------------------------------------
	PktApiCnctPrepare
		This function prepares a connection

  f_pCnctInf		: IN pointer to the connection to prepare.
  f_pParms			: IN pointer to connection open parameters structure.
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiCnctPrepare(
	tPKTAPI_CNCT_INF *					f_pCnctInf,
	tPOCTVC1_PKT_API_CNCT_OPEN_PARMS	f_pParms );

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __PKTAPI_CNCT_H__*/
