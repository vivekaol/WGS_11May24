/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_UDP.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_UDP_H__
#define __OCTTRANSAPI_UDP_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../include/octtransapi.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/

#define cOCTTRANSAPI_UDP_LOCAL_HOST_MAX		(16)

#ifdef OCTTRANSAPI_OPT_SELECT

#define cOCTTRANSAPI_UDP_SELECT_MAX			(32)

/*----------------------------------------------------------------------------
	Transport object is not ready for a non-blocking operation
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_UDP_SELECT_STATE_NONE		(0)

/*----------------------------------------------------------------------------
	Transport object is ready for a non-blocking receive operation
----------------------------------------------------------------------------*/
#define cOCTTRANSAPI_UDP_SELECT_STATE_RECV		(1)

#endif /* OCTTRANSAPI_OPT_SELECT */



/*----------------------------------------------------------------------------
	Transport open
----------------------------------------------------------------------------*/
typedef struct _OCTTRANSAPI_UDP_OPEN_
{
	tOCTTRANSAPI_UDP_ADDRESS	UdpAddress;				/* IN Local UDP Address */
	tOCT_UINT32					ulBroadcastUdpPort;		/* IN Udp port to be used for boradcast requests */
	void	*					pLocalContext;			/* IN Transport local porting context */
	tOCT_UINT32					ulMaxDestination;		/* Maximum number of transport destination */
	tOCT_UINT32					fAllowRxBroadcast;		/* IN allow receiving packets from 255.255.255.255 */
	tOCT_UINT32					ulSelectedPort;			/* OUT Selected UDP port when port in is 0 */
}tOCTTRANSAPI_UDP_OPEN, *tPOCTTRANSAPI_UDP_OPEN;

/*****************************  FUNCTIONS ************************************/
/*--------------------------------------------------------------------------
	OctTransApiUdpOpen

		This function opens a transport object.

  f_Context				: IN Pointer to Transport porting layer context.
  f_pParm				: IN Pointer to tOCTTRANSAPI_UDP_OPEN structure.
  f_phTransport			: OUT Pointer to opened transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpOpen( tOCTTRANSAPI_CONTEXT f_Context, 
									   tPOCTTRANSAPI_UDP_OPEN f_pParm, 
									   tOCTTRANSAPI_HANDLE *f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiUdpGetLocalAddress
	
	(Deprecated: Use OctTransApiGetInterfaceIpAddress )

		This function obtains the local addresse for a transport object.

  f_ulLocalHostIndex	: IN The index of the local host to used for performing discovery
  f_pIp			  		: OUT The interface's IP address.
  f_pNetmask	  		: OUT The interface's netmask.

Return :	0 means success
			Negative value means error.
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpGetLocalAddress( 	tOCT_UINT32				f_ulLocalHostIndex,
													tOCTDEV_IP_ADDRESS *	f_pIp,
													tOCTDEV_IP_ADDRESS *	f_pNetmask );

/*--------------------------------------------------------------------------
	OctTransApiUdpClose

		This function closes a transport object.

	f_hTransport			: IN transport object handle.

Return :	0 means success
			Negative value means error.

----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpClose( tOCTTRANSAPI_HANDLE f_hTransport );



/*--------------------------------------------------------------------------
	OctTransApiUdpSendTo

		This function sends a buffer on a transport object.

  f_hTransport			: IN The transport handle.
  f_pRemoteUdpAddress	: IN Remote UDP address.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

Return :	Size of the sent buffer in bytes
			Negative value means error.
			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpSendTo( tOCTTRANSAPI_HANDLE		f_hTransport, 
									   tPOCTTRANSAPI_UDP_ADDRESS	f_pRemoteUdpAddress,
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength  );

/*--------------------------------------------------------------------------
	OctTransApiUdpRecv

		This function receives a buffer from a transport object.

  f_hTransport			: IN The transport handle.
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpRecv( tOCTTRANSAPI_HANDLE f_hTransport, 
									   tOCT_UINT32 f_ulTimeoutMs, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength );

/*--------------------------------------------------------------------------
	OctTransApiUdpRecvFrom

		This function receives a buffer from a transport object.

  f_hTransport			: IN The transport handle.
  f_pRemoteUdpAddress	: OUT Remote UDP address
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpRecvFrom( tOCTTRANSAPI_HANDLE f_hTransport,
							tPOCTTRANSAPI_UDP_ADDRESS	f_pRemoteUdpAddress,
							tOCT_UINT32 f_ulTimeoutMs, 
							void * f_pBuffer, 
							tOCT_UINT32 f_ulBufferLength );


#ifdef OCTTRANSAPI_OPT_SELECT

/*--------------------------------------------------------------------------
	OctTransApiUdpLoopbackOpen
		This function creates a loop-back transport object.
		The loop-back transport object is used to send and receive
		data internally.

  f_Context				: IN Pointer to Transport porting layer context.
  f_phTransport			: OUT Pointer The transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpLoopbackOpen( tOCTTRANSAPI_CONTEXT f_Context,
											   tOCTTRANSAPI_HANDLE	*f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiUdpSelect
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

extern tOCT_INT32	OctTransApiUdpSelect( tOCTTRANSAPI_CONTEXT f_Context, 
										 tOCT_UINT32 f_ulTimeoutMs, 
										 tOCT_UINT32 f_ulTransportCnt,
										 tOCTTRANSAPI_HANDLE f_ahTransport[], 
										 tOCT_UINT32 f_aulState[] );

#endif /* OCTTRANSAPI_OPT_SELECT */

/*--------------------------------------------------------------------------
	OctTransApiUdpGetBroadcastAddress
		This function is used to retrieve the broadcast assdress to use
		for this trnasport instance.

  f_hTransport			: IN The transport handle.
  f_pBroadcastAddress	: OUT Broadcast address.

Return :	0 means success
			Otherwise, Value is the error code.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiUdpGetBroadcastAddress(	tOCTTRANSAPI_HANDLE	f_hTransport,
														tOCTDEV_UDP_ADDRESS*	f_pBroadcastAddress );



/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_UDP_H__*/


