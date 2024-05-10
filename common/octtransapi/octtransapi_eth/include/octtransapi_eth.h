/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_ETH.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_ETH_H__
#define __OCTTRANSAPI_ETH_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../../sls/inc/octpkt/octpkt_hdrxl.h"
#include "../../include/octtransapi.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/

#define mIS_TRANSAPI_ETH_OCTPKT_HDR_ETHERTYPE( ethertype ) ( ((ethertype&0xFF00) == cOCTPKT_HDR_ETHERTYPE) && ((ethertype&0x1)==0) )

#define mIS_TRANSAPI_ETH_OCTPKT_HDRXL_ETHERTYPE( ethertype ) ( ((ethertype&0xFF00) == cOCTPKT_HDR_ETHERTYPE) && ((ethertype&0x1)!=0) )


/*----------------------------------------------------------------------------
	Transport open
----------------------------------------------------------------------------*/
typedef struct _OCTTRANSAPI_ETH_OPEN_
{
	tOCTTRANSAPI_MAC_ADDRESS	MacAddress;				/* IN/OUT Local Mac Address */
	tOCT_UINT16					usEtherType;			/* IN Ethernet type */
	void	*					pLocalContext;			/* IN Transport local porting context */

	tOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM	ulCtrlProtoType;	/* Octasic control protocol */
	tOCT_UINT32					ulMinRxBufferSize;		/* Minimum rx buffer size */
	tOCT_BOOL32					fUseSelect;				/* Specify that the application will use select with this transport */
	tOCT_UINT32					ulMaxDestination;		/* Maximum number of transport destination */
	tOCT_UINT32					ulInterfaceIndex;		/* OUT associated interface index */
}tOCTTRANSAPI_ETH_OPEN, *tPOCTTRANSAPI_ETH_OPEN;

/*****************************  FUNCTIONS ************************************/
/*--------------------------------------------------------------------------
	OctTransApiEthOpen

		This function opens a transport object.

  f_Context				: IN Pointer to Transport porting layer context.
  f_pParm				: IN Pointer to tOCTTRANSAPI_ETH_OPEN structure.
  f_phTransport			: OUT Pointer to opened transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthOpen( tOCTTRANSAPI_CONTEXT f_Context, 
									   tPOCTTRANSAPI_ETH_OPEN f_pParm, 
									   tOCTTRANSAPI_HANDLE *f_phTransport );


/*----------------------------------------------------------------------------
	Transport open by name
----------------------------------------------------------------------------*/
typedef struct _OCTTRANSAPI_ETH_OPEN_BY_NAME_
{
	tOCTTRANSAPI_ETH_OPEN		EthOpen;
	tOCT_INT8*					pszInterfaceName;		/* IN Interface name */

}tOCTTRANSAPI_ETH_OPEN_BY_NAME, *tPOCTTRANSAPI_ETH_OPEN_BY_NAME;

/*--------------------------------------------------------------------------
	OctTransApiEthOpenByName

		This function opens a transport object.

  f_Context				: IN Pointer to Transport porting layer context.
  f_pParm				: IN Pointer to tOCTTRANSAPI_ETH_OPEN_BY_NAME structure.
  f_phTransport			: OUT Pointer to opened transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthOpenByName( tOCTTRANSAPI_CONTEXT f_Context, 
									   tPOCTTRANSAPI_ETH_OPEN_BY_NAME f_pParm, 
									   tOCTTRANSAPI_HANDLE *f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiEthClose

		This function closes a transport object.

	f_hTransport			: IN transport object handle.

Return :	0 means success
			Negative value means error.

----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthClose( tOCTTRANSAPI_HANDLE f_hTransport );

/*--------------------------------------------------------------------------
	OctTransApiEthSend

		This function sends a buffer on a transport object.

  f_hTransport			: IN The transport handle.
  f_pTransportDestinationContext
						: IN Destination transport peer context.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

Return :	Size of the sent buffer in bytes
			Negative value means error.
			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthSend( tOCTTRANSAPI_HANDLE f_hTransport, 
									   tOCTTRANSAPI_CONTEXT f_DestinationContext,
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength  );

/*--------------------------------------------------------------------------
	OctTransApiEthRecv

		This function receives a buffer from a transport object.

  f_hTransport			: IN The transport handle.
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthRecv( tOCTTRANSAPI_HANDLE f_hTransport, 
									   tOCT_UINT32 f_ulTimeoutMs, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength );


/*--------------------------------------------------------------------------
	OctTransApiEthGetPrimitiveHandle

		This function retrieve the primitive socket handle.

  f_hTransport			: IN The transport handle.

  Return : Primitive transport handle ( ie: isocket handle ).
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthGetPrimitiveHandle( tOCTTRANSAPI_HANDLE f_hTransport );


/*--------------------------------------------------------------------------
	OctTransApiEthGetLocalMac

		This function retreives the local mac address of the supplied 
		index adaptor.

  f_Context				: IN Pointer to Transport porting layer context.
  f_ulAdaptorIndex		: IN Local adaptor index.
  f_pMacAddress			: OUT Pointer to tOCTTRANSAPI_MAC_ADDRESS structure.


Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthGetLocalMac( tOCTTRANSAPI_CONTEXT f_Context,
											  tOCT_UINT32 f_ulAdaptorIndex, 
											  tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress );

/*--------------------------------------------------------------------------
	OctTransApiEthGetLocalMacByName

		This function retreives the local mac address of the supplied 
		interface name.

  f_Context				: IN Pointer to Transport porting layer context.
  f_pszInterfaceName	: IN Local interface name.
  f_pMacAddress			: OUT Pointer to tOCTTRANSAPI_MAC_ADDRESS structure.


Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthGetLocalMacByName( tOCTTRANSAPI_CONTEXT f_Context,
											  tOCT_INT8		*f_pszInterfaceName, 
											  tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress );


/*--------------------------------------------------------------------------
	OctTransApiEthStats

		This function receives a statistics.

  f_hTransport			: IN The transport handle.
  f_ulTimeoutMs			: IN Maximum time in milliseconds to wait.
  f_pBuffer				: IN Pointer to buffer.
  f_ulBufferLength		: IN Buffer length in bytes.

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/

typedef struct _OCTTRANSAPI_ETH_STATS_
{
	tOCT_UINT32					ulPacketSent;		/* Nb packet sent */
	tOCT_UINT32					ulPacketRecv;		/* Nb packet recv */
	tOCT_UINT32					ulPacketDrop;		/* Nb packet drop */
	tOCT_UINT32					ulLastError;		/* Interface last error */

}tOCTTRANSAPI_ETH_STATS, *tPOCTTRANSAPI_ETH_STATS;


extern tOCT_INT32	OctTransApiEthStats( tOCTTRANSAPI_HANDLE f_hTransport, 
									    tPOCTTRANSAPI_ETH_STATS f_pParm );



#ifdef OCTTRANSAPI_OPT_SELECT

/*--------------------------------------------------------------------------
	OctTransApiEthLoopbackOpen
		This function creates a loop-back transport object.
		The loop-back transport object is used to send and receive
		data internally.

  f_Context				: IN Pointer to Transport porting layer context.
  f_phTransport			: OUT Pointer The transport handle.

Return :	0 means success
			Negative value means error.			
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiEthLoopbackOpen( tOCTTRANSAPI_CONTEXT f_Context,
											   tOCTTRANSAPI_HANDLE	*f_phTransport );

/*--------------------------------------------------------------------------
	OctTransApiEthSelect
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

extern tOCT_INT32	OctTransApiEthSelect( tOCTTRANSAPI_CONTEXT f_Context, 
										 tOCT_UINT32 f_ulTimeoutMs, 
										 tOCT_UINT32 f_ulTransportCnt,
										 tOCTTRANSAPI_HANDLE f_ahTransport[], 
										 tOCT_UINT32 f_aulState[] );

#endif /* OCTTRANSAPI_OPT_SELECT */


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_ETH_H__*/


