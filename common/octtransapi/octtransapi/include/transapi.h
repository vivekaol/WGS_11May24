/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: TRANSAPI.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __TRANSAPI_H__
#define __TRANSAPI_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../include/octtransapi.h"
#include "../../../../common/octosal/include/octosal.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/
#define cTRANSAPI_MAGIC_ID				0x29081990
#define cTRANSAPI_MAGIC_DESTINATION_ID	0x26041967
#define cTRANSAPI_MAGIC_DISPATCHOR_ID	0x19081958

#define	cTRANSAPI_DESTINATION_ADDRESS_SIZE	64
#define tTRANSAPI_SELECTABLE_HANDLE		void *

#ifdef OCTOSAL_OPT_MULTI_THREAD
#ifndef cOCTTRANSAPI_DISPATCHER_COUNT
#define cOCTTRANSAPI_DISPATCHER_COUNT		2
#endif /* cOCTTRANSAPI_DISPATCHER_COUNT */
#else	
#define cOCTTRANSAPI_DISPATCHER_COUNT		0
#endif
/* MAX 32 to be set in MAGIC_ID */
#define cTRANSAPI_TRANSPORT_INSTANCE_MAX		(cOCTTRANSAPI_TRANSPORT_INSTANCE_MAX+cOCTTRANSAPI_DISPATCHER_COUNT)      /* Dispatcher + user */

#if ( cTRANSAPI_TRANSPORT_INSTANCE_MAX > 32 )
#error "cTRANSAPI_TRANSPORT_INSTANCE_MAX too big for MAGIC_ID"
#endif

#define cTRANSAPI_MSG_PAYLOAD_GUARD		0xCAFEDECA
#define cTRANSAPI_MSG_MAGIC_ID			0x28012A00
#define cTRANSAPI_MSG_MAGIC_ID_MASK		0xFFFFFE00

#define mIS_TRANSAPI_MSG_MAGIC_ID( id )	( ( id & cTRANSAPI_MSG_MAGIC_ID_MASK ) == cTRANSAPI_MSG_MAGIC_ID )
#define mTRANSAPI_MSG_MAGIC_ID_2_TRANSNDX( id )	( ( id & 0x000000FF ) >> 2 )
#define mTRANSAPI_MSG_MAGIC_ID_2_POOLNDX( id )	( ( id & 0x00000003 ) )
#define mIS_TRANSAPI_MSG_MAGIC_ID_USED( id )	( ( id & 0x00000100 ) )
#define mTRANSAPI_MSG_MAGIC_ID_UNUSED( id )		( ( id & 0xFFFFFEFF ) )
#define mTRANSAPI_MSG_MAGIC_ID_USED( id )		( ( id | 0x00000100 ) )

/*----------------------------------------------------------------------------
	Transport Destination Context
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCTTRANSAPI_RECV_PARMS *pRecvParms;
	tOCT_UINT32				ulRecvLength;
	tOCT_UINT32				ulDestinationAddrLength;
	tOCT_UINT8				achDestinationAddr[cTRANSAPI_DESTINATION_ADDRESS_SIZE];
	tOCT_INT8				szDestinationAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE];

}tTRANSAPI_DESTINATION_RECV;

/*----------------------------------------------------------------------------
	Transport Callback
----------------------------------------------------------------------------*/

typedef tOCT_INT32 (*tPFNTRANSAPI_SELECT)( tOCTTRANSAPI_HANDLE	f_hTransport );
typedef tOCT_INT32 (*tPFNTRANSAPI_DESTINATION_RECV)	( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV *f_pDestinationRecv);

/*----------------------------------------------------------------------------
	Transport Destination Callback
----------------------------------------------------------------------------*/
typedef tOCT_INT32 (*tPFNTRANSAPI_DESTINATION_SEND)( tOCTTRANSAPI_DESTINATION_HANDLE	f_hDestination, tOCTTRANSAPI_DESTINATION_SEND_PARMS  *f_pParms);


/*----------------------------------------------------------------------------
	Transport MsgAllocator Context
----------------------------------------------------------------------------*/
typedef struct 
{
	tOCT_UINT32							ulMagicId;		
	tOCTTRANSAPI_HANDLE					hTransport;
	tOCT_INT8							achPayloadHeader[cOCTRANSAPI_DESTINATION_PAYLOAD_HEADER_SIZE];
	void *								pDestinationAddr;
	tOCT_UINT32							ulDestinationAddrSize;
	tOCT_INT8							szDestinationAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE];
	tPFNTRANSAPI_DESTINATION_SEND		pfnDestinationSend;
	tOCT_BOOL32							fIsBroadcast;
	tOCT_UINT32							ulHeaderBufferPadding;		// Space use in Recv buffer as padding to allign payload 
}tTRANSAPI_DESTINATION_CTX;


/*----------------------------------------------------------------------------
	Transport Context
----------------------------------------------------------------------------*/
typedef struct _TRANSAPI_CTX_
{
	tOCT_UINT32							ulMagicId;		
	tOCTTRANSAPI_TRANSPORT_TYPE_ENUM	ulTransportType;
	tOCT_UINT32							ulLastError;
	tPFNTRANSAPI_DISPATCH_PAYLOAD		pfnDispatchPayload;
	void *								pAppDispatchCtx;
    tOCT_INT32      					(*pfnClose)( struct _TRANSAPI_CTX_ * f_pTransCtx);
#ifdef OCTTRANSAPI_OPT_SELECT 
	tPFNTRANSAPI_SELECT					pfnPreSelect;
	tPFNTRANSAPI_SELECT					pfnPostSelect;
#endif /* OCTTRANSAPI_OPT_SELECT */
	tOCTTRANSAPI_DISPATCHER_HANDLE		hDispatcher;
    tOCT_INT32                          (*pfnDestinationAdd)( struct _TRANSAPI_CTX_ * f_pTransCtx, tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_ADD_PARMS *f_pParms );
	tPFNTRANSAPI_DESTINATION_RECV		pfnDestinationRecv;
	tOCT_UINT32							ulMaxDestination;
	tTRANSAPI_DESTINATION_CTX *			apDestinationCtx;
	tTRANSAPI_SELECTABLE_HANDLE			hSelectable;
	tOCT_UINT32							ulPayloadHeaderLength;
	tOCT_UINT32							ulHeaderBufferPadding;		/* Space use in Recv buffer as padding to allign payload */
	tOCTTRANSAPI_HANDLE					hTransport;					/* Handle to the containing instance */
	tOCTPKT_HDR_TYPE_ENUM				ulPktHdrType;				/* Specify if transport is using tOCTPKT_HDR_TYPE */
}tTRANSAPI_CTX;

typedef tOCT_INT32 (*tPFNTRANSAPI_CLOSE)( tTRANSAPI_CTX * f_pTransCtx );
typedef tOCT_INT32 (*tPFNTRANSAPI_DESTINATION_ADD)	(  tTRANSAPI_CTX * f_pTransCtx, tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_ADD_PARMS *f_pParms );

/*----------------------------------------------------------------------------
	Transport Slot
----------------------------------------------------------------------------*/

typedef struct 
{
	tOCT_UINT32									ulMagicId;
#ifdef OCTOSAL_OPT_MULTI_THREAD
	tOCTOSAL_HANDLE_MUTEX						hMutex;
#endif /*OCTOSAL_OPT_MULTI_THREAD*/
	tOCT_BOOL32									fUsed;
	tOCT_UINT32									ulUseCnt;
	tOCT_UINT32									ulIndex;
	tTRANSAPI_CTX *								pTransApiCtx;
}tTRANSAPI_TRANSPORT_INSTANCE;

extern tTRANSAPI_TRANSPORT_INSTANCE	g_aTransApiTransportInstance[];

/*----------------------------------------------------------------------------
	Transport Instance
----------------------------------------------------------------------------*/
typedef struct 
{
#ifdef OCTOSAL_OPT_MULTI_THREAD
    tOCTOSAL_HANDLE_MUTEX						hMutex;
#endif /*OCTOSAL_OPT_MULTI_THREAD*/

}tTRANSAPI_INST;
/*****************************  Internal Proto ************************************/
extern tOCT_INT32	TransApiDispatcherInit( void );
extern tOCT_INT32	TransApiDispatcherTerminate(void);
extern tOCT_UINT32  TransApiCalcElapsedTimeMs( tOCT_UINT32	f_ulCurrentTimeMs, tOCT_UINT32	f_ulStartTimeMs );

/*****************************  Inter Transport Proto ************************************/
extern tOCTTRANSAPI_RC_ERROR	TransApiInstanceSeize( tTRANSAPI_TRANSPORT_INSTANCE ** f_ppTransInst  );
extern tOCTTRANSAPI_RC_ERROR	TransApiInstanceRelease( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst );
extern tOCTTRANSAPI_RC_ERROR	TransApiInstanceUsed( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst );
extern tOCTTRANSAPI_RC_ERROR	TransApiInstanceUnused( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst );
extern tOCTTRANSAPI_RC_ERROR	TransApiInstanceWaitUnused( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst );

/*****************************  MACROS ************************************/
/*----------------------------------------------------------------------------
	MACRO
----------------------------------------------------------------------------*/
#ifndef OCTOSAL_OPT_MULTI_THREAD
#define mTRANSAPI_MUTEX_SEIZE( seize_mutex, seize_t, seize_ret )
#define mTRANSAPI_MUTEX_RELEASE( f_hMutex )
#define mTRANSAPI_MUTEX_CLOSE( f_hMutex )
#define mTRANSAPI_MUTEX_OPEN( f_hMutex )

#else   /*OCTOSAL_OPT_MULTI_THREAD*/

#define mTRANSAPI_MUTEX_RELEASE( f_hMutex ) OctOsalMutexRelease( f_hMutex )
#define mTRANSAPI_MUTEX_CLOSE( f_hMutex ) OctOsalMutexClose( f_hMutex )
#define mTRANSAPI_MUTEX_OPEN( f_hMutex ) OctOsalMutexOpen( f_hMutex )

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
#define mTRANSAPI_MUTEX_SEIZE( seize_mutex, seize_t, seize_ret ) if( OctOsalMutexSeize( seize_mutex, seize_t ) != cOCTOSAL_RC_OK ) seize_ret;
#else
#define mTRANSAPI_MUTEX_SEIZE( seize_mutex, seize_t, seize_ret ) OctOsalMutexSeize( seize_mutex, seize_t );
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#endif /*OCTOSAL_OPT_MULTI_THREAD*/


#ifndef mMIN
#define mMIN( a, b ) ((a>b)?b:a)
#endif
#ifndef mMAX
#define mMAX( a, b ) ((a<b)?b:a)
#endif


/*****************************  GLOBAL ************************************/
extern	tTRANSAPI_INST *		g_pTransApiInst;


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __TRANSAPI_H__*/


