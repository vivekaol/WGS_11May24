#if defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN32 ) || defined( WIN64 )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_local.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)
	
$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include <stdio.h>
#include "../../../include/transapi_local.h"
#include <winsock2.h>
#include <ws2tcpip.h>


/*******************************  STRUCTURE ***********************************/
#define cTRANSAPI_LOCAL_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_LOCAL_MSG_SIZE_MAX	(256)

typedef struct
{
	unsigned			ulSize;
	unsigned char		abyBuffer[cTRANSAPI_LOCAL_MSG_SIZE_MAX+1];

} tTRANSAPI_LOCAL_SOCKET_MSG;

typedef struct
{
	tTRANSAPI_LOCAL_CTX	TransLocalCtx;		/* MUST BE FIRST */

	HANDLE		hEvent;
	HANDLE		hLock;				
	int			iReadBlock;			/* Read block index */
	int			iWriteBlock;		/* Write block index */
	tTRANSAPI_LOCAL_SOCKET_MSG	aMsgBlock[cTRANSAPI_LOCAL_MSG_BLOCK_MAX+1];	
															/* Array of available message block */
} tTRANSAPI_LOCAL_SOCKET, *tPTRANSAPI_LOCAL_SOCKET;

/*--------------------------------------------------------------------------
	OctTransApiLocalOpen
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiLocalOpen( tPOCTTRANSAPI_LOCAL_OPEN_PARMS f_pParm, 
							   tOCTTRANSAPI_HANDLE *f_phTransport )
{
	int								iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tPTRANSAPI_LOCAL_SOCKET			pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( (NULL == f_pParm) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pSocket = (tPTRANSAPI_LOCAL_SOCKET)malloc(sizeof(tTRANSAPI_LOCAL_SOCKET));
	if( NULL == pSocket )
		return cOCTTRANSAPI_RC_ERROR_MEMORY_ALLOC;

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		/* At this point, we no longer need the device list. Free it */
		free( pSocket );
		return iRc;
	}

	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	memset( pSocket, 0, sizeof( tTRANSAPI_LOCAL_SOCKET ) );

	TransApiLocalInitCtx( &pSocket->TransLocalCtx );

	pSocket->iReadBlock		= 0;
	pSocket->iWriteBlock	= 0;
	pSocket->hLock			= CreateSemaphore( NULL, 1, 1, NULL );
	pSocket->hEvent			= CreateEvent( NULL, FALSE, FALSE, NULL );
	pSocket->TransLocalCtx.TransCtx.hSelectable = pSocket->hEvent;

	pTransInst->pTransApiCtx = (tTRANSAPI_CTX *)pSocket;
	*f_phTransport = pTransInst;

	OctOsalMutexRelease( pTransInst->hMutex );

	return iRc;
}
/*--------------------------------------------------------------------------
	TransApiLocalClose

----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiLocalClose( tTRANSAPI_CTX * f_pTransCtx  )
{
    tPTRANSAPI_LOCAL_SOCKET		pSocket = (tPTRANSAPI_LOCAL_SOCKET)f_pTransCtx;
    if( f_pTransCtx->ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_LOCAL )
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

	if( pSocket->hEvent )
		CloseHandle( pSocket->hEvent );
	pSocket->hEvent = NULL;
	if( pSocket->hLock )
		CloseHandle( pSocket->hLock );

	free( pSocket );
	return cOCTTRANSAPI_RC_ERROR_NONE;
}
/*--------------------------------------------------------------------------
	OctTransApiLocalClose

----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiLocalClose( tOCTTRANSAPI_HANDLE f_hTransport )
{

	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;
	tTRANSAPI_CTX *			pTransCtx;


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransInst->pTransApiCtx == NULL ) )
		iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	
	if( iRc !=  cOCTTRANSAPI_RC_ERROR_NONE )
	{
		OctOsalMutexRelease( pTransInst->hMutex );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    iRc = TransApiLocalClose( (tTRANSAPI_CTX *)pTransInst->pTransApiCtx );

	pTransInst->pTransApiCtx = NULL;
	OctOsalMutexRelease( pTransInst->hMutex );
	TransApiInstanceRelease( pTransInst );

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiLocalSend

		This function sends a buffer on a transport object.

----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiLocalSend( tOCTTRANSAPI_HANDLE f_hTransport, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulBufferLength  )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;
	tPTRANSAPI_LOCAL_SOCKET				pSocket;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
	pSocket = (tPTRANSAPI_LOCAL_SOCKET)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransInst->pTransApiCtx == NULL ) )
		iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else if( ( pSocket->TransLocalCtx.TransCtx.ulMagicId != cTRANSAPI_MAGIC_ID ) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	else if( ( pSocket->TransLocalCtx.TransCtx.ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_LOCAL ) )
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;
	
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		OctOsalMutexRelease( pTransInst->hMutex );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	if ( WAIT_OBJECT_0 == WaitForSingleObject( 
								pSocket->hLock, 
								INFINITE ) )
	{
		int	iNextWrite;
		/* Calculate next write index */
		iNextWrite = pSocket->iWriteBlock;
		iNextWrite++;
		if ( iNextWrite > cTRANSAPI_LOCAL_MSG_BLOCK_MAX )
		{
			iNextWrite = 0;
		}

		/* Room to store a new one ? */
		if ( pSocket->iReadBlock != iNextWrite )
		{
			pSocket->aMsgBlock[pSocket->iWriteBlock].ulSize 
						= mMIN( cTRANSAPI_LOCAL_MSG_SIZE_MAX, f_ulBufferLength );
			memcpy( pSocket->aMsgBlock[pSocket->iWriteBlock].abyBuffer,f_pBuffer,
							pSocket->aMsgBlock[pSocket->iWriteBlock].ulSize );
			iRc = pSocket->aMsgBlock[pSocket->iWriteBlock].ulSize;
			pSocket->iWriteBlock = iNextWrite;
		}
		else
		{
			iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
		}
		ReleaseSemaphore( pSocket->hLock, 1, NULL );
		
		/* Signal a new msg in Q */
		if( iRc > 0 )
			SetEvent( pSocket->hEvent );
	}
	OctOsalMutexRelease( pTransInst->hMutex );
	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiLocalRecv

  Return :		Size of the received buffer in bytes.
				0 means no data,
				Negative value means error.
				
----------------------------------------------------------------------------*/
extern tOCT_INT32	OctTransApiLocalRecv( tOCTTRANSAPI_HANDLE f_hTransport, 
									   tOCT_UINT32 f_ulTimeoutMs, 
									   void * f_pBuffer, 
									   tOCT_UINT32 f_ulMaxBufferLength )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tPTRANSAPI_LOCAL_SOCKET				pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE*		pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pBuffer  ) ||
		( 0 == f_ulMaxBufferLength ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
	pSocket = (tPTRANSAPI_LOCAL_SOCKET)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransInst->pTransApiCtx == NULL ) )
		iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else if( (pSocket->TransLocalCtx.TransCtx.ulMagicId != cTRANSAPI_MAGIC_ID ) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	else if( pSocket->TransLocalCtx.TransCtx.ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_LOCAL )
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		OctOsalMutexRelease( pTransInst->hMutex );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	if ( WAIT_OBJECT_0 == WaitForSingleObject( 
								pSocket->hLock, 
								(cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs)
									?INFINITE
									:f_ulTimeoutMs ) )
	{
		if ( pSocket->iReadBlock != pSocket->iWriteBlock )
		{
			iRc = mMIN( pSocket->aMsgBlock[pSocket->iReadBlock].ulSize, f_ulMaxBufferLength);
			memcpy( f_pBuffer, pSocket->aMsgBlock[pSocket->iReadBlock].abyBuffer, iRc );

			pSocket->aMsgBlock[pSocket->iReadBlock].ulSize = 0;
			pSocket->iReadBlock++;
			if ( pSocket->iReadBlock > cTRANSAPI_LOCAL_MSG_BLOCK_MAX )
			{
				pSocket->iReadBlock = 0;
			}
		}
		ReleaseSemaphore( pSocket->hLock, 1, NULL );

	}
	else
	{
		iRc = 0;
	}

	OctOsalMutexRelease( pTransInst->hMutex );

	return iRc;
}


/*--------------------------------------------------------------------------
	OctTransApiGetInterfaceIpAddress
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiGetInterfaceIpAddress( 	tOCT_UINT32	f_ulLocalInterfaceIndex,
											tOCTDEV_IP_ADDRESS*	f_pIp,
											tOCTDEV_IP_ADDRESS*	f_pNetmask )
{
	tOCT_INT32				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
    INTERFACE_INFO			InterfaceList[16];
    tOCT_UINT32				ulListSize;
	WSADATA					wsaData;

	if ( 0 == WSAStartup( MAKEWORD(2, 2), &wsaData ) )
	{
		SOCKET	hSocket = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );

		if( INVALID_SOCKET != hSocket )
		{
			iRc = WSAIoctl(	hSocket,
							SIO_GET_INTERFACE_LIST, 0, 0,
							&InterfaceList,
							sizeof(InterfaceList),
							&ulListSize, 0, 0);

			if( iRc >= 0 )
			{
				ulListSize /= sizeof(INTERFACE_INFO);

				if(f_ulLocalInterfaceIndex < ulListSize)
				{
					f_pIp->ulIpVersion				= cOCTTRANSAPI_IP_VERSION_ENUM_4;
					f_pIp->aulIpAddress[0]			= ntohl(((struct sockaddr_in *)&InterfaceList[f_ulLocalInterfaceIndex].iiAddress)->sin_addr.S_un.S_addr);

					f_pNetmask->ulIpVersion			= cOCTTRANSAPI_IP_VERSION_ENUM_4;
					f_pNetmask->aulIpAddress[0]		= ntohl(((struct sockaddr_in *)&InterfaceList[f_ulLocalInterfaceIndex].iiNetmask)->sin_addr.S_un.S_addr);
				}
				else
				{
					iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
				}
			}

			/* This soket is used for calling WSAIoctl and nothing else... */
			closesocket( hSocket );
		}
		else
		{
			iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
		}

		WSACleanup();
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	return iRc;
	
}


#endif /* WIN32 */
