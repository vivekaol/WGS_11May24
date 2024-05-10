/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_H__
#define __OCTTRANSAPI_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../sls/inc/octdev_types.h"
#include "../../octosal/include/octosal.h"
#include "../../../sls/inc/octpkt/octpkt_hdr.h"
#include "octtransapi_rc.h"
/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/

/*----------------------------------------------------------------------------
	Keep previous compatibility.
----------------------------------------------------------------------------*/
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
#ifndef OCTTRANSAPI_OPT_SELECT	
#define OCTTRANSAPI_OPT_SELECT	
#endif /* OCTTRANSAPI_OPT_SELECT */
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */

/*----------------------------------------------------------------------------
	Make sure we use SELECT option under WIN32
----------------------------------------------------------------------------*/
#ifdef WIN32
#ifndef OCTTRANSAPI_OPT_SELECT
#define OCTTRANSAPI_OPT_SELECT
#endif /* OCTTRANSAPI_OPT_SELECT */
#endif /* WIN32 */



/*----------------------------------------------------------------------------
	Transport object is not ready for a non-blocking operation
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_SELECT_STATE_NONE		(0)

/*----------------------------------------------------------------------------
	Transport object is ready for a non-blocking receive operation
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_SELECT_STATE_RECV		(1)

#define cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX (32)



/*----------------------------------------------------------------------------
	Endless timeout value.
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_TIMEOUT_FOREVER	cOCTDEV_TIMEOUT_FOREVER

/*----------------------------------------------------------------------------
	Transport type 
----------------------------------------------------------------------------*/
#define tOCTTRANSAPI_TRANSPORT_TYPE_ENUM		tOCT_UINT32
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_NONE	0
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH	1
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_UDP	2
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_TCP	3
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_LOCAL	4
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_IPC	5
#define cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_USER	10


/*----------------------------------------------------------------------------
	Transport Instance
----------------------------------------------------------------------------*/
#ifndef cOCTTRANSAPI_TRANSPORT_INSTANCE_MAX
#define cOCTTRANSAPI_TRANSPORT_INSTANCE_MAX		(16)      /* Application transport */
#endif /* cOCTTRANSAPI_TRANSPORT_INSTANCE_MAX */


/*----------------------------------------------------------------------------
	Transport API handle
----------------------------------------------------------------------------*/
#define tOCTTRANSAPI_HANDLE				void *
#define tOCTTRANSAPI_CONTEXT			void *
#define tOCTTRANSAPI_DESTINATION_HANDLE void *
#define tOCTTRANSAPI_DISPATCHER_HANDLE  void *

#define tOCTTRANSAPI_HANDLE_INVALID		(NULL)

/*----------------------------------------------------------------------------
	Transport API handle
----------------------------------------------------------------------------*/
#define tOCTTRANSAPI_DISPATCHER_STATE_ENUM			tOCT_UINT32
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE				0
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_USED				1
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_STOPPED			2
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MUST_WAIT2CLOSE	3
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_STOPPING			4
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_KEEP_RUNNING		5
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_RUNNING			6
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING			7
#define cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MODIFY			8

/*----------------------------------------------------------------------------
	Transport common def
----------------------------------------------------------------------------*/
#define tOCTTRANSAPI_MAC_ADDRESS	tOCTDEV_MAC_ADDRESS
#define tPOCTTRANSAPI_MAC_ADDRESS	tOCTDEV_MAC_ADDRESS*

#define tOCTTRANSAPI_UDP_ADDRESS	tOCTDEV_UDP_ADDRESS
#define tPOCTTRANSAPI_UDP_ADDRESS	tOCTDEV_UDP_ADDRESS*

#define tOCTTRANSAPI_TCP_ADDRESS	tOCTDEV_TCP_ADDRESS
#define tPOCTTRANSAPI_TCP_ADDRESS	tOCTDEV_TCP_ADDRESS*


#define tOCTTRANSAPI_IP_VERSION_ENUM			tOCTDEV_IP_VERSION_ENUM
#define cOCTTRANSAPI_IP_VERSION_ENUM_4			cOCTDEV_IP_VERSION_ENUM_4
#define cOCTTRANSAPI_IP_VERSION_ENUM_6			cOCTDEV_IP_VERSION_ENUM_6
#define cOCTTRANSAPI_IP_VERSION_ENUM_INVALID	cOCTDEV_IP_VERSION_ENUM_INVALID

#define cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE		(128)
#define cOCTRANSAPI_DESTINATION_PAYLOAD_HEADER_SIZE	(64)

#define cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX	(8)

/*----------------------------------------------------------------------------
	Transport init
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCTOSAL_CONTEXT	pOsContext;			/* OS related context */
}tOCTTRANSAPI_INIT_PARMS;

/*----------------------------------------------------------------------------
	Transport terminate
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32		ulReserved;			/* Reserved */
}tOCTTRANSAPI_TERMINATE_PARMS;

/*----------------------------------------------------------------------------
	Transport Recv
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32					ulMaxBufferLength;		/* Maximum buffer length to receive */
	tOCT_UINT32					ulTimeoutMs;			/* Timeout */
	tOCT_UINT8 *				pBuffer;				/* Buffer to receive data */

	tOCT_UINT8 *				pPayload;				/* Start of the received payload in buffer */
	tOCT_UINT32					ulPayloadLength;		/* Recv payload length */
	tOCTTRANSAPI_DESTINATION_HANDLE	hDestination;		/* Transport destination sending this message */

	tOCT_UINT32					ulMaxDestinationAddrLength;	/* Max length of the transport destination address */
	tOCT_INT8 *					pszDestinationAddr;			/* String representation of the transport destination address. NULL when not requested */

}tOCTTRANSAPI_RECV_PARMS;


/*----------------------------------------------------------------------------
	Transport select
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32					ulTimeoutMs;
	tOCT_UINT32					ulTransportCnt;
	/* Transport handle */
	tOCTTRANSAPI_HANDLE			ahTransport[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];	

	/* OUT Selected handle */
	tOCT_UINT32					ulSelectedCnt;	/* Number of selected handel */
	tOCTTRANSAPI_HANDLE			ahTransSelected[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];

}tOCTTRANSAPI_SELECT_PARMS;


typedef tOCTTRANSAPI_RC_ERROR (*tPFNTRANSAPI_DISPATCH_PAYLOAD)( void * f_pAppContext, tOCTTRANSAPI_RECV_PARMS *f_pParms );

/*----------------------------------------------------------------------------
	Transport Set Dispatcher callback
----------------------------------------------------------------------------*/
typedef struct 
{
	tPFNTRANSAPI_DISPATCH_PAYLOAD   pfnDispatchPayload;		/* Function callback to process payload */
	void *							pAppContext;			/* Application context */
}tOCTTRANSAPI_SET_DISPATCHER_CB_PARMS;



/*----------------------------------------------------------------------------
	Transport Get Last error
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32	ulLastError;
	tOCT_BOOL32 fClear;

}tOCTTRANSAPI_GET_LAST_ERROR_PARMS;


/*----------------------------------------------------------------------------
	Transport Destination Add
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32						ulDestinationAddrSize;		/* Size of the transport destination address */
	void *							pDestinationAddr;			/* Destination address. May be null when szDestinationAddr should be used */
	tOCT_INT8						szDestinationAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE]; /* Destination address string representation. Broadcast address should be used when this string is empty and pDestinationAddr is NULL. */
	tOCTTRANSAPI_DESTINATION_HANDLE	hDestination;				/* Newly created transport destination */		

}tOCTTRANSAPI_DESTINATION_ADD_PARMS;

/*----------------------------------------------------------------------------
	Transport Destination Send
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32			ulBufferLength;			/* Message length to send including payload header (if any) */
	tOCT_UINT8 *		pBuffer;				/* Message buffer including payload header (if any) */
	tOCT_UINT32			ulSentLength;			/* Number of byte sent */
}tOCTTRANSAPI_DESTINATION_SEND_PARMS;

/*----------------------------------------------------------------------------
	Transport Destination Info
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCTTRANSAPI_HANDLE				hTransport;					/* Assigned transport handle */
	tOCT_UINT32						ulDestinationAddrSize;		/* size of the transport destination address */
	void *							pDestinationAddr;			/* May be null when szDestinationAddr should be used */
	tOCT_INT8						szDestinationAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE]; /* Destination address string representation. Broadcast address should be used when this string is empty and pDestinationAddr is NULL. */
	tOCT_BOOL32						fIsBroadcast;				/* cOCT_TRUE when destination is broadcast */
	tOCTPKT_HDR_TYPE_ENUM			ulPktHdrType;				/* Specify if transport is using tOCTPKT_HDR_TYPE */
}tOCTTRANSAPI_DESTINATION_INFO_PARMS;


/*----------------------------------------------------------------------------
	Transport Destination Payload Header Info
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32			ulHeaderLength;
	tOCT_UINT8			achHeader[cOCTRANSAPI_DESTINATION_PAYLOAD_HEADER_SIZE];
}tOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS;

/*----------------------------------------------------------------------------
	Transport Dispatcher Open
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32				ulElapseInactivityMs;	/* elapse time without activity before using pfnDispatchInactivity */
	void *					pInactivityAppContext;	/* Application context */
	tOCTTRANSAPI_DISPATCHER_HANDLE	hDispatcher;
	
}tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS;

typedef tOCTTRANSAPI_RC_ERROR (*tPFNTRANSAPI_DISPATCH_INACTIVITY)( tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS * f_pParms );

/*----------------------------------------------------------------------------
	Transport Dispatcher Open
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32				ulRxBufferSize;			/* Size of the default RX buffer. */
	tOCT_UINT32				ulElapseInactivityMs;	/* elapse time without activity before using pfnDispatchInactivity */
	void *					pInactivityAppContext;	/* Application context */

	tPFNTRANSAPI_DISPATCH_INACTIVITY	pfnDispatchInactivity;		/* Function callback to call on inactivity */

	tOCTTRANSAPI_DISPATCHER_HANDLE	hDispatcher;
	
}tOCTTRANSAPI_DISPATCHER_OPEN_PARMS;

/*----------------------------------------------------------------------------
	Transport Dispatcher Set Inactivity callback
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32				ulElapseInactivityMs;				/* elapse time without activity before using pfnDispatchInactivity */
	void *					pInactivityAppContext;				/* Application context */
	tPFNTRANSAPI_DISPATCH_INACTIVITY	pfnDispatchInactivity;	/* Function callback to call on inactivity */
	
}tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS;

/*----------------------------------------------------------------------------
	Transport Dispatcher Add Transport
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCTTRANSAPI_HANDLE				hTransport;				/* transport handle to add to dispatcher */
	tPFNTRANSAPI_DISPATCH_PAYLOAD   pfnDispatchPayload;		/* Function callback to process payload */
	void *							pAppContext;			/* Application context */
}tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS;

/*----------------------------------------------------------------------------
	Transport Dispatcher Run
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32			ulReserved;		
	
}tOCTTRANSAPI_DISPATCHER_RUN_PARMS;

/*----------------------------------------------------------------------------
	Transport Dispatcher Get Status
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCTTRANSAPI_DISPATCHER_STATE_ENUM	ulState;
	tOCT_UINT32							ulTransportCnt;			/* Number of port associated with this dispatcher */
	tOCT_UINT32							ulElapseInactivityMs;	/* Elapse inactivity */
}tOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS;



/*****************************  FUNCTIONS ************************************/
tOCTTRANSAPI_RC_ERROR OctTransApiInit( tOCTTRANSAPI_INIT_PARMS *			f_pParms );
tOCTTRANSAPI_RC_ERROR OctTransApiIsInit( void );
tOCTTRANSAPI_RC_ERROR OctTransApiTerminate( tOCTTRANSAPI_TERMINATE_PARMS * f_pParms );
tOCTTRANSAPI_RC_ERROR OctTransApiClose( tOCTTRANSAPI_HANDLE				f_hTransport );
tOCTTRANSAPI_RC_ERROR OctTransApiGetInterfaceIpAddress( tOCT_UINT32	f_ulLocalInterfaceIndex,
													tOCTDEV_IP_ADDRESS *	f_pIp,
													tOCTDEV_IP_ADDRESS *	f_pNetmask );

#ifdef OCTTRANSAPI_OPT_SELECT
tOCTTRANSAPI_RC_ERROR OctTransApiSelect( tOCTTRANSAPI_SELECT_PARMS *		f_pParms ); 
#endif /* OCTTRANSAPI_OPT_SELECT */

tOCTTRANSAPI_RC_ERROR OctTransApiRecv( tOCTTRANSAPI_HANDLE 				f_hTransport,			
							tOCTTRANSAPI_RECV_PARMS *					f_pParms );

tOCTTRANSAPI_RC_ERROR OctTransApiSetDispatcherCB( tOCTTRANSAPI_HANDLE 		f_hTransport,
							tOCTTRANSAPI_SET_DISPATCHER_CB_PARMS *			f_pParms );

tOCTTRANSAPI_RC_ERROR OctTransApiGetLastError( tOCTTRANSAPI_HANDLE 		f_hTransport,
							tOCTTRANSAPI_GET_LAST_ERROR_PARMS *			f_pParms );

tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationAdd(
								 tOCTTRANSAPI_HANDLE					f_hTransport,
								 tOCTTRANSAPI_DESTINATION_ADD_PARMS *	f_pParms );

tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationRemove(
								 tOCTTRANSAPI_DESTINATION_HANDLE		f_hDestination );

tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationInfo(
								 tOCTTRANSAPI_DESTINATION_HANDLE		f_hDestination,
								 tOCTTRANSAPI_DESTINATION_INFO_PARMS *	f_pParms );

tOCTTRANSAPI_RC_ERROR   OctTransApiDestinationSend( tOCTTRANSAPI_DESTINATION_HANDLE	f_hDestination,
								  tOCTTRANSAPI_DESTINATION_SEND_PARMS *	f_pParms );

tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationPayloadHeaderInfo( tOCTTRANSAPI_DESTINATION_HANDLE 	f_hDestination,
								  tOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS *	f_pParms );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherOpen(
								 tOCTTRANSAPI_DISPATCHER_OPEN_PARMS *	f_pParm );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherClose(
								 tOCTTRANSAPI_DISPATCHER_HANDLE				f_hDispatcher );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherAddTransport(
							tOCTTRANSAPI_DISPATCHER_HANDLE					f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS *	f_pParm );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherRemoveTransport(
							tOCTTRANSAPI_HANDLE						f_hTransport );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherRun(
							tOCTTRANSAPI_DISPATCHER_HANDLE			f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_RUN_PARMS *		f_pParm );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherGetStatus(
							tOCTTRANSAPI_DISPATCHER_HANDLE			f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS *	f_pParm );

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherSetInactivity(
							tOCTTRANSAPI_DISPATCHER_HANDLE			f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS *	f_pParm );



/*****************************  MACROS ************************************/


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_H__*/


