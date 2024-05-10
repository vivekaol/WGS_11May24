/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_TCP.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_TCP_H__
#define __OCTTRANSAPI_TCP_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../include/octtransapi.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/


#ifdef OCTTRANSAPI_OPT_SELECT

#define cOCTTRANSAPI_TCP_SELECT_MAX			(32)

/*----------------------------------------------------------------------------
	Transport object is not ready for a non-blocking operation
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_TCP_SELECT_STATE_NONE		(0)

/*----------------------------------------------------------------------------
	Transport object is ready for a non-blocking receive operation
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_TCP_SELECT_STATE_RECV		(1)

/*----------------------------------------------------------------------------
	Transport object is ready to accept a new connection
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_TCP_SELECT_STATE_ACCEPT	(2)

/*----------------------------------------------------------------------------
	Transport object is to be closed
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_TCP_SELECT_STATE_CLOSE		(3)

/*----------------------------------------------------------------------------
	Transport object is in error
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_TCP_SELECT_STATE_ERROR		(4)

#endif /* OCTTRANSAPI_OPT_SELECT */



/*----------------------------------------------------------------------------
	Transport open
----------------------------------------------------------------------------*/
typedef struct _OCTTRANSAPI_TCP_OPEN_
{
	tOCTTRANSAPI_TCP_ADDRESS	LocalTcpAddress;		/* IN Local TCP Address. */
	tOCTTRANSAPI_TCP_ADDRESS	RemoteTcpAddress;		/* IN Remote TCP Address (optional; leave 0 if no connection is to be done) */
	void	*					pLocalContext;			/* IN Transport local porting context */
	tOCT_UINT32					ulTimeoutMs;			/* IN Maximum time in milliseconds to wait */
	tOCT_BOOL32					fUseSelect;				/* IN Specify that the application will use select with this transport */
	tOCT_BOOL32					fServer;				/* IN Specify that this is to be a server socket (enter the listen state). */
	tOCT_UINT32					ulLocalSelectedPort;	/* OUT Selected TCP port when Local port in is 0 */

}tOCTTRANSAPI_TCP_OPEN, *tPOCTTRANSAPI_TCP_OPEN;

/*****************************  FUNCTIONS ************************************/
/*--------------------------------------------------------------------------
	OctTransApiTcpOpen

		This function opens a transport object.

  f_Context				: IN Pointer to Transport porting layer context.
  f_pParm				: IN Pointer to tOCTTRANSAPI_TCP_OPEN structure.
  f_phTransport			: OUT Pointer to opened transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpOpen( tOCTTRANSAPI_CONTEXT f_Context, 
									   tPOCTTRANSAPI_TCP_OPEN f_pParm, 
									   tOCTTRANSAPI_HANDLE *f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiTcpConnect

		This function connects a transport object to a remote peer.

  f_hTransport			: IN transport object handle.
  f_pRemoteTcpAddress	: IN Pointer to tOCTTRANSAPI_TCP_ADDRESS structure.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpConnect(	tOCTTRANSAPI_HANDLE			f_hTransport, 
								  			tOCTTRANSAPI_TCP_ADDRESS *	f_pRemoteTcpAddress );

/*--------------------------------------------------------------------------
	OctTransApiTcpGetLocalAddress

		This function retreive the local TCP address.

  f_hTransport			: IN transport object handle.
  f_pLocalTcpAddress	: IN Pointer to tOCTTRANSAPI_TCP_ADDRESS structure.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpGetLocalAddress(	tOCTTRANSAPI_HANDLE		f_hTransport, 
								  			tOCTTRANSAPI_TCP_ADDRESS *	f_pLocalTcpAddress );

											
/*--------------------------------------------------------------------------
	OctTransApiTcpClose

		This function closes a transport object.

	f_hTransport		: IN transport object handle.

Return :	0 means success
			Negative value means error.

----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpClose( 	tOCTTRANSAPI_HANDLE		f_hTransport );



/*--------------------------------------------------------------------------
	OctTransApiTcpRecv

		This function receives a buffer from a transport object.

  f_hTransport			: IN The transport handle.
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpRecv( tOCTTRANSAPI_HANDLE f_hTransport, 
									   tOCT_UINT32 f_ulTimeoutMs, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength );


/*--------------------------------------------------------------------------
	OctTransApiTcpSend

		This function sends a buffer to a transport object.

  f_Context					: IN Pointer to Transport porting layer context.
  f_pBuffer				    : IN Pointer to buffer.
  f_ulBufferLength		    : IN Buffer length in bytes.

  Return :		Numnber of bytes sent.
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpSend(	tOCTTRANSAPI_HANDLE	f_hTransport,
										void *				f_pBuffer,
										tOCT_UINT32			f_ulBufferLength );


#ifdef OCTTRANSAPI_OPT_SELECT

/*--------------------------------------------------------------------------
	OctTransApiTcpLoopbackOpen
		This function creates a loop-back transport object.
		The loop-back transport object is used to send and receive
		data internally.

  f_Context				: IN Pointer to Transport porting layer context.
  f_phTransport			: OUT Pointer The transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiTcpLoopbackOpen( tOCTTRANSAPI_CONTEXT f_Context,
											   tOCTTRANSAPI_HANDLE	*f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiTcpSelect
		This function monitors multiple transport objects, waiting until 
		one or more object become ready for a non-blocking operation. 

  f_Context				: IN Pointer to Transport porting layer context.
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_ulTransportCnt		: IN Count of transport object in f_ahTransport,
							and count of state in f_aulState.
  f_ahTransport			: IN Array of pointer to the transport object.
  f_aulState			: OUT Array of transport object state.

Return :		Number of transport object in a ready state.
				0 means no transport object ready,
				Negative value means error.
				
----------------------------------------------------------------------------*/

extern tOCT_INT32	OctTransApiTcpSelect( tOCTTRANSAPI_CONTEXT f_Context, 
										 tOCT_UINT32 f_ulTimeoutMs, 
										 tOCT_UINT32 f_ulTransportCnt,
										 tOCTTRANSAPI_HANDLE f_ahTransport[], 
										 tOCT_UINT32 f_aulState[] );
#endif /* OCTTRANSAPI_OPT_SELECT */

/*--------------------------------------------------------------------------
	OctTransApiTcpAccept
		This function ensures that the underlying socket is in listening
		mode and then accepts an incoming connection.

	f_hListeningTransport:	Opened, but unconnected transport to be used for
							incoming conneciton requests.
	f_phAcceptedTransport:	Pointer to an new opened transport handle whenever
							a connection request is accepted.
	f_pRemoteTcpAddress:	If not NULL, this structure will have been
							populated with the IP address of the remote
							peer's accepted connection.

Return :	0 means success
			Negative value means error.			
				
----------------------------------------------------------------------------*/

extern tOCT_INT32	OctTransApiTcpAccept( 	tOCTTRANSAPI_HANDLE	f_hListeningTransport,
											tOCTTRANSAPI_HANDLE *f_phAcceptedTransport, 
							  				tOCTTRANSAPI_TCP_ADDRESS *	f_pRemoteTcpAddress );


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_TCP_H__*/


