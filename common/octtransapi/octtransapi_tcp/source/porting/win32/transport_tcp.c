#if defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN32 ) || defined( WIN64 )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: TRANSPORT.c


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

/* Porting interface */
#include "../../../include/transapi_tcp.h"
#include "../../../include/octtransapi_tcp.h"
#include "../../../../octtransapi/include/transapi.h"
#include <winsock2.h>

#pragma comment( lib, "ws2_32.lib" )


/*********************************  MACROS ************************************/
#ifndef mMIN
#define mMIN( a, b ) ((a>b)?b:a)
#endif

#define cTRANSAPI_TCP_LOOPBACK_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_TCP_LOOPBACK_MSG_SIZE_MAX		(256)

/*******************************  STRUCTURE ***********************************/
#define tTRANSAPI_TCP_SOCKET_TYPE_ENUM				tOCT_UINT32
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	(0)
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP			(1)
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_INVALID		(2)

#define cMAX_DESTINATIONS_PER_SOCKET	(1)

typedef struct
{
	tTRANSAPI_TCP_CTX	TransTcpCtx;		/* MUST BE FIRST */
	
	tTRANSAPI_TCP_SOCKET_TYPE_ENUM	ulType;

	union
	{
		struct
		{
			HANDLE						hLock;				/* Protect ourself */
			int							iReadBlock;			/* Read block index */
			int							iWriteBlock;		/* Write block index */
			tTRANSAPI_TCP_SOCKET_LOOPBACK_MSG	aMsgBlock[cTRANSAPI_TCP_LOOPBACK_MSG_BLOCK_MAX+1];	
															/* Array of available message block */
		} Loopback;

		struct
		{
			SOCKET						hSocket;			/* Socket handle */
			tOCT_UINT32					ulTimeout;			/* Last applied timeout value */
			tOCT_BOOL32					fDidSelect;
		} Tcp;

	} Data;

	tTRANSAPI_DESTINATION_CTX	aDestinationCtx[cMAX_DESTINATIONS_PER_SOCKET];
	tOCTDEV_TCP_ADDRESS			aDestinationTcpAddress[cMAX_DESTINATIONS_PER_SOCKET];

} tTRANSAPI_TCP_SOCKET, *tPTRANSAPI_TCP_SOCKET;

/****************************  STATIC FUNCTION ********************************/

/*--------------------------------------------------------------------------
	OctTransApiTcpConnect
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiTcpConnect(	tOCTTRANSAPI_HANDLE			f_hTransport, 
								  	tOCTTRANSAPI_TCP_ADDRESS *	f_pRemoteTcpAddress )
{
	int iRc;
	struct sockaddr_in InetAddr = {0};
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_TCP_SOCKET	pSocket;
    unsigned long iMode = 1;

	if ( (f_hTransport == NULL) || (f_pRemoteTcpAddress == NULL) || 
		 (f_pRemoteTcpAddress->IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4) )
	{
		return cOCTTRANSAPI_RC_ERROR_PARAM;
	}

	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	InetAddr.sin_family			= AF_INET;
	InetAddr.sin_addr.s_addr	= htonl(f_pRemoteTcpAddress->IpAddress.aulIpAddress[0]);
	InetAddr.sin_port			= htons(f_pRemoteTcpAddress->ulTcpPort);

	//set the socket in non-blocking .. at least while we connect
    ioctlsocket(pSocket->Data.Tcp.hSocket, FIONBIO, &iMode);

	iRc = connect(pSocket->Data.Tcp.hSocket, (SOCKADDR *) &InetAddr, sizeof(InetAddr));

	if(iRc < 0)
	{
		int iErr=WSAGetLastError(); 
		if( iErr == WSAEWOULDBLOCK )
			iRc = 0;
	}

	if(iRc == 0)
	{
		HANDLE hConnectEvent = WSACreateEvent();

		/* Our porting may use select */
		if ( 0 == WSAEventSelect( pSocket->Data.Tcp.hSocket, hConnectEvent, FD_CONNECT | FD_WRITE | FD_CLOSE ) )
		{
			DWORD dwTi = (cOCTTRANSAPI_TIMEOUT_FOREVER == pSocket->Data.Tcp.ulTimeout)
							? INFINITE : pSocket->Data.Tcp.ulTimeout;

			iRc = -1;
			/* Wait for the connection to be established */
			if( WSAWaitForMultipleEvents( 1, &hConnectEvent, TRUE, dwTi, FALSE) == WSA_WAIT_EVENT_0 )
			{
				iRc = 0;
			}
		}

		WSACloseEvent( hConnectEvent );
	}


	if(iRc == 0)
	{
#ifdef OCTTRANSAPI_OPT_SELECT
		if( pSocket->TransTcpCtx.fUseSelect )
		{
			unsigned long ulValue = 1;
			
			/* Make sure socket is non-blocking */
			WSAEventSelect(pSocket->Data.Tcp.hSocket, pSocket->TransTcpCtx.TransCtx.hSelectable, FD_READ | FD_CLOSE );
			ioctlsocket( pSocket->Data.Tcp.hSocket, FIONBIO, &ulValue );
		}
		else
#endif /* OCTTRANSAPI_OPT_SELECT */
		{
			unsigned long ulValue = 0;
			
			/* Make sure socket is blocking */
			WSAEventSelect(pSocket->Data.Tcp.hSocket, NULL, 0 );						
			ioctlsocket( pSocket->Data.Tcp.hSocket, FIONBIO, &ulValue );
		}
	}
	else
		pSocket->TransTcpCtx.TransCtx.ulLastError = WSAGetLastError();

	return iRc;
}


/*--------------------------------------------------------------------------
	OctTransApiTcpOpen
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiTcpOpen( tOCTTRANSAPI_CONTEXT f_Context,
							   tPOCTTRANSAPI_TCP_OPEN f_pParms, 
							   tOCTTRANSAPI_HANDLE *f_phTransport )

{
	int						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	tPTRANSAPI_TCP_SOCKET	pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = NULL;

	WORD	wVersionRequested;
	WSADATA wsaData;

	if( (NULL == f_pParms) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if(( f_pParms->LocalTcpAddress.IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4 ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if(f_pParms->fServer && (f_pParms->RemoteTcpAddress.ulTcpPort != 0) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	wVersionRequested = MAKEWORD(2, 2);

	if ( 0 == WSAStartup( wVersionRequested, &wsaData ) )
	{
		if ( 2 == LOBYTE(wsaData.wVersion) 
			&& 
			2 == HIBYTE(wsaData.wVersion) ) 
		{
			struct sockaddr_in InetAddr;

			/* Allocate socket structure */
			pSocket = (tPTRANSAPI_TCP_SOCKET)malloc( sizeof(*pSocket) );
			if ( NULL != pSocket )
			{
				if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
				{
					free( pSocket );
					return iRc;
				}

				memset(pSocket, 0, sizeof(*pSocket));

				pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
				TransApiTcpInitCtx( &pSocket->TransTcpCtx, (tOCT_UINT32)&((tPTRANSAPI_TCP_SOCKET)0)->aDestinationCtx, 1);
				pTransInst->pTransApiCtx->hTransport = pTransInst;
				pSocket->ulType = cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP;

				/* Create socket stuff */
#ifdef OCTTRANSAPI_OPT_SELECT
				pSocket->TransTcpCtx.fUseSelect = f_pParms->fUseSelect;
				pSocket->TransTcpCtx.TransCtx.hSelectable = WSACreateEvent();
				pSocket->TransTcpCtx.TransCtx.pfnPostSelect = TransApiTcpPostSelect;
				pSocket->TransTcpCtx.TransCtx.pfnPreSelect = TransApiTcpPreSelect;
#endif /* OCTTRANSAPI_OPT_SELECT */

				pSocket->Data.Tcp.hSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
				pSocket->Data.Tcp.fDidSelect = cOCT_FALSE;

				/* Unless told otherwise, the socket will block indefinitely */
				pSocket->Data.Tcp.ulTimeout = f_pParms->ulTimeoutMs;	// cOCTTRANSAPI_TIMEOUT_FOREVER;

#ifdef OCTTRANSAPI_OPT_SELECT
				if ( NULL != pSocket->TransTcpCtx.TransCtx.hSelectable && 0 != pSocket->Data.Tcp.hSocket )
#else
				if ( 0 != pSocket->Data.Tcp.hSocket )
#endif /* OCTTRANSAPI_OPT_SELECT */
				{
					InetAddr.sin_family			= AF_INET;
					InetAddr.sin_addr.s_addr	= htonl(f_pParms->LocalTcpAddress.IpAddress.aulIpAddress[0]);
					InetAddr.sin_port			= htons(f_pParms->LocalTcpAddress.ulTcpPort);

					iRc = bind(pSocket->Data.Tcp.hSocket, (SOCKADDR *) &InetAddr, sizeof(InetAddr));

					if( iRc >= 0 )
					{
						if( f_pParms->LocalTcpAddress.ulTcpPort == 0)
						{
							/* return selected port */
							struct sockaddr_in addrIn;
							int addrInLen = sizeof( addrIn );

							if( getsockname( pSocket->Data.Tcp.hSocket, (struct sockaddr *)&addrIn, &addrInLen ) != -1 )
								f_pParms->ulLocalSelectedPort = ntohs(addrIn.sin_port);
						}
						else
							f_pParms->ulLocalSelectedPort = f_pParms->LocalTcpAddress.ulTcpPort;

						if( f_pParms->RemoteTcpAddress.ulTcpPort != 0)
						{
							iRc = OctTransApiTcpConnect( pTransInst, &f_pParms->RemoteTcpAddress );
						}
						else if(f_pParms->fServer)
						{
							iRc = listen( pSocket->Data.Tcp.hSocket, SOMAXCONN );

							if( iRc == 0 )
							{
								iRc = WSAEventSelect( pSocket->Data.Tcp.hSocket, 
												pSocket->TransTcpCtx.TransCtx.hSelectable,
												FD_ACCEPT | FD_CLOSE );
							}
							else
							{
								unsigned ulRc = WSAGetLastError();
								iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;

							}
						}
					}
					if(iRc < 0)
					{
						unsigned ulErr = WSAGetLastError();

						switch( ulErr )
						{
							case WSAEINVAL:
							case WSAEADDRINUSE:
							case WSAEWOULDBLOCK:
							case WSAEADDRNOTAVAIL:
							case WSAEFAULT:
								iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
								break;
							default:					/* PORTING ERROR */
								iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
								break;
						}
						pSocket->TransTcpCtx.TransCtx.ulLastError = ulErr;
					}
				}
			}
			else
			{
				WSACleanup();
			}
		}
		else
		{
			WSACleanup();
		}
	}

	if ( cOCTTRANSAPI_RC_ERROR_NONE == iRc )
	{
		*f_phTransport = pTransInst;
	}
	else
	{
		if ( NULL != pTransInst )
		{
			OctTransApiTcpClose( pTransInst );
		}
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiTcpClose
----------------------------------------------------------------------------*/
int			OctTransApiTcpClose( 
		tOCTTRANSAPI_HANDLE	f_hTransport )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_TCP_SOCKET	pSocket;
	
	if( f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP		:
#ifdef OCTTRANSAPI_OPT_SELECT
			if( pSocket->Data.Tcp.fDidSelect == cOCT_TRUE )
				WSAEventSelect( pSocket->Data.Tcp.hSocket, NULL, 0 );
#endif /* OCTTRANSAPI_OPT_SELECT */
			WSASendDisconnect( pSocket->Data.Tcp.hSocket, NULL );			
			shutdown(pSocket->Data.Tcp.hSocket, SD_BOTH);
			closesocket( pSocket->Data.Tcp.hSocket );
			
			pSocket->Data.Tcp.hSocket = 0;
#ifdef OCTTRANSAPI_OPT_SELECT
			if( pSocket->Data.Tcp.fDidSelect == cOCT_TRUE )
				WSACloseEvent( pSocket->TransTcpCtx.TransCtx.hSelectable );
			pSocket->TransTcpCtx.TransCtx.hSelectable = NULL;
#endif /* OCTTRANSAPI_OPT_SELECT */
			/* Clean up */
			if( !pSocket->TransTcpCtx.fAccepted )
				WSACleanup();
			break;

#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	:
			CloseHandle( pSocket->TransTcpCtx.TransCtx.hSelectable );
			pSocket->TransTcpCtx.TransCtx.hSelectable = NULL;
			CloseHandle( pSocket->Data.Loopback.hLock );
			pSocket->Data.Loopback.hLock = NULL;
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */
		default :
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
			break;
	}
	if ( cOCTTRANSAPI_RC_ERROR_NONE == iRc )
	{
		pSocket->ulType = cTRANSAPI_TCP_SOCKET_TYPE_ENUM_INVALID;
		free( pSocket );
		iRc = TransApiInstanceRelease( pTransInst );
	}
	return iRc;
}


/*--------------------------------------------------------------------------
	OctTransApiTcpGetLocalAddress
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiTcpGetLocalAddress(	tOCTTRANSAPI_HANDLE			f_hTransport, 
								  			tOCTTRANSAPI_TCP_ADDRESS *	f_pLocalTcpAddress )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_TCP_SOCKET	pSocket;
	
	if(( f_hTransport == NULL ) || ( f_pLocalTcpAddress == NULL ))
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	if( pSocket->ulType != cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP)
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	else
	{
		struct sockaddr_in addrIn;
		int addrInLen = sizeof( addrIn );

		if( getsockname( pSocket->Data.Tcp.hSocket, (struct sockaddr *)&addrIn, &addrInLen ) != -1 )
		{
			memset( f_pLocalTcpAddress, 0, sizeof( tOCTTRANSAPI_TCP_ADDRESS ));
			f_pLocalTcpAddress->IpAddress.ulIpVersion		= cOCTDEV_IP_VERSION_ENUM_4;
			f_pLocalTcpAddress->IpAddress.aulIpAddress[0]	= ntohl(addrIn.sin_addr.S_un.S_addr);
			f_pLocalTcpAddress->ulTcpPort = ntohs(addrIn.sin_port);
		}
		else
		{
			iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
			pSocket->TransTcpCtx.TransCtx.ulLastError = WSAGetLastError();
		}

	}
	return iRc;

}
/*--------------------------------------------------------------------------
	OctTransApiTcpRecv
----------------------------------------------------------------------------*/
int			OctTransApiTcpRecv(
	tOCTTRANSAPI_HANDLE		f_hTransport,
	unsigned int			f_ulTimeoutMs,
	void *					f_pBuffer,
	unsigned int			f_ulMaxBufferLength )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_TCP_SOCKET	pSocket;

	if( f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		default:
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
			break;

		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP	:
			{
				WSABUF			RecvBuff;
				DWORD			ulRecvLen;
				DWORD			ulFlags;
				DWORD			ulCumulDataLength;

				RecvBuff.buf	= f_pBuffer;
				RecvBuff.len	= f_ulMaxBufferLength;
				ulFlags = 0;

				/* Adjust the timeout if different */
				if ( pSocket->Data.Tcp.ulTimeout != f_ulTimeoutMs )
				{
					DWORD dwOptVal = (cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs) ? 0 : f_ulTimeoutMs;

					setsockopt( pSocket->Data.Tcp.hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&dwOptVal, sizeof(dwOptVal) );
					pSocket->Data.Tcp.ulTimeout = f_ulTimeoutMs;
				}

				for( ulCumulDataLength = 0; ulCumulDataLength < f_ulMaxBufferLength; ulCumulDataLength += ulRecvLen )
				{
					iRc = WSARecv(
							pSocket->Data.Tcp.hSocket, 
							&RecvBuff,
							1,
							&ulRecvLen,
							&ulFlags,
							NULL,
							NULL );
					if( iRc < 0 )
					{
						unsigned ulErr = WSAGetLastError();
						switch( ulErr )
						{
							case WSAENETUNREACH:			
								iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
								break;

							case WSAETIMEDOUT:	
								/* May have to reset ulCumulDataLength to return 0 as timeout */
								iRc = 0;
								break;

							case WSAECONNABORTED:
							case WSAECONNRESET:
								iRc = cOCTTRANSAPI_RC_ERROR_DISCONNECTED;
								break;
							default:					/* PORTING ERROR */
								iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
								break;
						}
						pSocket->TransTcpCtx.TransCtx.ulLastError = ulErr;
						break;
					}
					else if ( 0 == iRc && 0 == ulRecvLen )
					{
					  /* Remote end disconnected */
					  iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
					  break;
					}
					else
					{
						/* Get ready for following data */
						RecvBuff.buf += ulRecvLen;
						RecvBuff.len -= ulRecvLen;
						/* Should test tOCTTRANSAPI_TCP_OPEN.fRecvByPacket and break */
					}
				}

				if ( 0 == iRc )
				{
					iRc = ulCumulDataLength;
				}
			}
			break;
#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	:
			if ( WAIT_OBJECT_0 == WaitForSingleObject( 
										pSocket->Data.Loopback.hLock, 
										(cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs)
											?INFINITE
											:f_ulTimeoutMs ) )
			{
				if ( pSocket->Data.Loopback.iReadBlock != pSocket->Data.Loopback.iWriteBlock )
				{
					memcpy( f_pBuffer, pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iReadBlock].abyBuffer,
									mMIN( pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iReadBlock].ulSize, f_ulMaxBufferLength) );
					iRc = pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iReadBlock].ulSize;

					pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iReadBlock].ulSize = 0;
					pSocket->Data.Loopback.iReadBlock++;
					if ( pSocket->Data.Loopback.iReadBlock > cTRANSAPI_TCP_LOOPBACK_MSG_BLOCK_MAX )
					{
						pSocket->Data.Loopback.iReadBlock = 0;
					}
				}
				ReleaseSemaphore( pSocket->Data.Loopback.hLock, 1, NULL );

			}
			else
			{
				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
			}
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiTcpSend
----------------------------------------------------------------------------*/
int			OctTransApiTcpSend(
	tOCTTRANSAPI_HANDLE	f_hTransport,
	void *				f_pBuffer,
	unsigned int		f_ulBufferLength )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_TCP_SOCKET	pSocket;

	if(  f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		default:
			return cOCTTRANSAPI_RC_ERROR_PARAM;
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP :
			{
				iRc = send( 
						pSocket->Data.Tcp.hSocket, 
						f_pBuffer,
						f_ulBufferLength,
						0);

				if ( iRc < 0 )
				{
					unsigned ulErr = WSAGetLastError();
					switch( ulErr )
					{
						case WSAECONNRESET:
							iRc = cOCTTRANSAPI_RC_ERROR_DISCONNECTED;
							break;

						case WSAENETRESET:
						case WSAEADDRNOTAVAIL:
						case WSAEDESTADDRREQ:
						case WSAETIMEDOUT:
							iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
							break;
						default:
							iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
							break;
					}
					pSocket->TransTcpCtx.TransCtx.ulLastError = ulErr;
				}
			}
			break;

#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	:
			if ( WAIT_OBJECT_0 == WaitForSingleObject( 
										pSocket->Data.Loopback.hLock, 
										INFINITE ) )
			{
				int	iNextWrite;
				/* Calculate next write index */
				iNextWrite = pSocket->Data.Loopback.iWriteBlock;
				iNextWrite++;
				if ( iNextWrite > cTRANSAPI_TCP_LOOPBACK_MSG_BLOCK_MAX )
				{
					iNextWrite = 0;
				}

				/* Room to store a new one ? */
				if ( pSocket->Data.Loopback.iReadBlock != iNextWrite )
				{
					memcpy( pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].abyBuffer,f_pBuffer,
									mMIN( cTRANSAPI_TCP_LOOPBACK_MSG_SIZE_MAX, f_ulBufferLength ) );
					pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].ulSize 
								= mMIN( cTRANSAPI_TCP_LOOPBACK_MSG_SIZE_MAX, f_ulBufferLength );
					iRc = pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].ulSize;
					pSocket->Data.Loopback.iWriteBlock = iNextWrite;
				}
				else
				{
					iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				}
				ReleaseSemaphore( pSocket->Data.Loopback.hLock, 1, NULL );
				/* Signal a new msg in Q */
				SetEvent( pSocket->TransTcpCtx.TransCtx.hSelectable );
			}
			else
			{
				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
			}
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiTcpLoopbackOpen
----------------------------------------------------------------------------*/
int OctTransApiTcpLoopbackOpen( 
	tOCTTRANSAPI_CONTEXT	f_Context,
	tOCTTRANSAPI_HANDLE	*f_phTransport )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tPTRANSAPI_TCP_SOCKET	pSocket = (tPTRANSAPI_TCP_SOCKET)malloc(sizeof(tTRANSAPI_TCP_SOCKET));
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		free( pSocket );
		return iRc;
	}

	memset(pSocket, 0, sizeof(*pSocket));
	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
	TransApiTcpInitCtx( &pSocket->TransTcpCtx, sizeof(pSocket->TransTcpCtx), 0);

	pSocket->ulType = cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK;
	pSocket->Data.Loopback.iReadBlock	= 0;
	pSocket->Data.Loopback.iWriteBlock	= 0;
	pSocket->Data.Loopback.hLock		= CreateSemaphore( NULL, 1, 1, NULL );

#ifdef OCTTRANSAPI_OPT_SELECT
	pSocket->TransTcpCtx.TransCtx.hSelectable = CreateEvent( NULL, FALSE, FALSE, NULL );
#endif /* OCTTRANSAPI_OPT_SELECT */

	*f_phTransport = pTransInst;
	return iRc;
}

#ifdef OCTTRANSAPI_OPT_SELECT
/*--------------------------------------------------------------------------
	OctTransApiTcpSelect
----------------------------------------------------------------------------*/
int			OctTransApiTcpSelect(
	tOCTTRANSAPI_CONTEXT f_Context,
	unsigned int			f_ulTimeoutMs,
	unsigned int			f_ulTransportCnt,
	tOCTTRANSAPI_HANDLE	f_ahTransport[],
	unsigned int			f_aulState[] )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	unsigned int	ulIndex;
	HANDLE			aHandles[32];
	DWORD			dwRc;

	memset( aHandles, 0x0, sizeof(aHandles) );

	for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
	{
		tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[ulIndex];
		tPTRANSAPI_TCP_SOCKET	pSocket;

		if( pTransInst == NULL )
			return cOCTTRANSAPI_RC_ERROR_PARAM;

		pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

		/* Store event handle */
		aHandles[ulIndex] = pSocket->TransTcpCtx.TransCtx.hSelectable;
		/* State is not ready */
		f_aulState[ulIndex] = cOCTTRANSAPI_TCP_SELECT_STATE_NONE;


		if( pSocket->Data.Tcp.fDidSelect == cOCT_FALSE )
		{
			if ( 0 != WSAEventSelect( pSocket->Data.Tcp.hSocket, pSocket->TransTcpCtx.TransCtx.hSelectable, FD_READ | FD_ACCEPT | FD_CLOSE ) )
				return cOCTTRANSAPI_RC_ERROR_PORTING;
			else
				pSocket->Data.Tcp.fDidSelect = cOCT_TRUE;
		}
	}

	/* Wait for something to happen */
	dwRc = WaitForMultipleObjects(
					f_ulTransportCnt,
					aHandles,
					FALSE,
					(cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs)
						?INFINITE
						:f_ulTimeoutMs);

	if ( WAIT_TIMEOUT == dwRc )
	{
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	else if ( WAIT_OBJECT_0 <= dwRc && WAIT_OBJECT_0 + f_ulTransportCnt > dwRc )
	{
		tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[dwRc-WAIT_OBJECT_0];
		tPTRANSAPI_TCP_SOCKET pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;
		unsigned ulState = cOCTTRANSAPI_TCP_SELECT_STATE_RECV;

		/*  socket activity on udp ... not local */
		if( pSocket->ulType == cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP )
		{
			WSANETWORKEVENTS networkEvents;
			iRc = WSAEnumNetworkEvents( pSocket->Data.Tcp.hSocket, pSocket->TransTcpCtx.TransCtx.hSelectable, &networkEvents );
			if( iRc != 0 )
			{
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			}
			else if( networkEvents.lNetworkEvents & FD_CLOSE )
			{
				ulState = cOCTTRANSAPI_TCP_SELECT_STATE_CLOSE;
			}
			else if( networkEvents.lNetworkEvents & FD_ACCEPT )
			{
				ulState = cOCTTRANSAPI_TCP_SELECT_STATE_ACCEPT;
			}
			else if( networkEvents.lNetworkEvents & FD_READ )
			{
				ulState = cOCTTRANSAPI_TCP_SELECT_STATE_RECV;
			}
			else
			{
				pSocket->TransTcpCtx.TransCtx.ulLastError = WSAGetLastError();
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			}

			WSAResetEvent(aHandles[dwRc - WSA_WAIT_EVENT_0]);
		}

		/* Fill the state array (only retrieve one event at a time) */
		if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
		{
			f_aulState[dwRc - WAIT_OBJECT_0] = ulState;
			/* Tell that there is activity */
			iRc = 1;
		}
	}
	else if ( WAIT_ABANDONED_0 <= dwRc && WAIT_ABANDONED_0 + f_ulTransportCnt > dwRc )
	{
		/* Probably a close handle or socket */
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	return iRc;
}


/*--------------------------------------------------------------------------
	TransApiTcpPostSelect
----------------------------------------------------------------------------*/
int	TransApiTcpPostSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;
    tPTRANSAPI_TCP_SOCKET pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	/*  socket activity on tcp ... not local */
	if( pSocket->ulType == cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP )
	{
		WSANETWORKEVENTS networkEvents;
		int iRc = WSAEnumNetworkEvents( pSocket->Data.Tcp.hSocket, pSocket->TransTcpCtx.TransCtx.hSelectable, &networkEvents );
		if(( iRc != 0 ) || ((networkEvents.lNetworkEvents & (FD_READ | FD_ACCEPT | FD_CLOSE)) == 0) )
			iRc = cOCTTRANSAPI_RC_ERROR_PORTING;

		WSAResetEvent(pSocket->TransTcpCtx.TransCtx.hSelectable);
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	TransApiTcpPreSelect
----------------------------------------------------------------------------*/
int	TransApiTcpPreSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;
    tPTRANSAPI_TCP_SOCKET pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;
	

	/*  socket activity on tcp ... not local */
	if( pSocket->ulType == cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP )
	{
		if( pSocket->Data.Tcp.fDidSelect == cOCT_FALSE )
		{
			if ( 0 != WSAEventSelect( pSocket->Data.Tcp.hSocket, pSocket->TransTcpCtx.TransCtx.hSelectable, FD_READ | FD_ACCEPT | FD_CLOSE) )
				return cOCTTRANSAPI_RC_ERROR_PORTING;
			else
				pSocket->Data.Tcp.fDidSelect = cOCT_TRUE;
		}
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}



#endif /* OCTTRANSAPI_OPT_SELECT */

/*--------------------------------------------------------------------------
  --------------------------------------------------------------------------
  Porting functions needed by server implementations
  --------------------------------------------------------------------------
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	OctTransApiTcpAccept
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiTcpAccept( 	tOCTTRANSAPI_HANDLE	f_hListeningTransport,
									tOCTTRANSAPI_HANDLE *f_phAcceptedTransport, 
								  	tOCTTRANSAPI_TCP_ADDRESS *	f_pRemoteTcpAddress )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	tPTRANSAPI_TCP_SOCKET	pListeningSocket, pAcceptedSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pListeningTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hListeningTransport;
	tTRANSAPI_TRANSPORT_INSTANCE *	pAcceptedTransInst = NULL;
	struct sockaddr_in		AcceptedAddress;
	int						lAcceptedAddressLen = sizeof(AcceptedAddress);

	if( (NULL == pListeningTransInst) || (NULL == f_phAcceptedTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pListeningSocket = (tPTRANSAPI_TCP_SOCKET)pListeningTransInst->pTransApiCtx;

	switch( pListeningSocket->ulType )
	{
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK :
		default:
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
			break;

		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP	:
			{
				pAcceptedSocket = (tPTRANSAPI_TCP_SOCKET)malloc( sizeof(*pAcceptedSocket) );
				if ( NULL == pAcceptedSocket )
				{
					return cOCTTRANSAPI_RC_ERROR_PORTING;
				}

				if(( iRc = TransApiInstanceSeize( &pAcceptedTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
				{
					free( pAcceptedSocket );
					return iRc;
				}

				memset(pAcceptedSocket, 0, sizeof(*pAcceptedSocket));

				pAcceptedTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pAcceptedSocket;
				TransApiTcpInitCtx( &pAcceptedSocket->TransTcpCtx, (tOCT_UINT32)&((tPTRANSAPI_TCP_SOCKET)0)->aDestinationCtx, 1);
				pAcceptedTransInst->pTransApiCtx->hTransport = pAcceptedTransInst;
				pAcceptedSocket->ulType = cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP;

				/* Create socket stuff */
#ifdef OCTTRANSAPI_OPT_SELECT
				pAcceptedSocket->TransTcpCtx.fUseSelect = pListeningSocket->TransTcpCtx.fUseSelect;
				pAcceptedSocket->TransTcpCtx.TransCtx.hSelectable = WSACreateEvent();
				pAcceptedSocket->TransTcpCtx.TransCtx.pfnPostSelect = TransApiTcpPostSelect;
				pAcceptedSocket->TransTcpCtx.TransCtx.pfnPreSelect = TransApiTcpPreSelect;
#endif /* OCTTRANSAPI_OPT_SELECT */
				/* We inherit fron the listening socket */
				pAcceptedSocket->Data.Tcp.ulTimeout = pListeningSocket->Data.Tcp.ulTimeout;
				pAcceptedSocket->TransTcpCtx.fUseSelect = pListeningSocket->TransTcpCtx.fUseSelect;

				pAcceptedSocket->Data.Tcp.hSocket = accept( pListeningSocket->Data.Tcp.hSocket,
															(struct sockaddr *)&AcceptedAddress,
															&lAcceptedAddressLen );

				if ( INVALID_SOCKET == pAcceptedSocket->Data.Tcp.hSocket )
				{
					free( pAcceptedSocket );
					return cOCTTRANSAPI_RC_ERROR_PORTING;
				}

#ifdef OCTTRANSAPI_OPT_SELECT
				if( pAcceptedSocket->TransTcpCtx.fUseSelect )
				{
					unsigned long ulValue = 1;
					
					/* Make sure socket is non-blocking */
					WSAEventSelect(pAcceptedSocket->Data.Tcp.hSocket, pAcceptedSocket->TransTcpCtx.TransCtx.hSelectable, FD_READ | FD_CLOSE );
					ioctlsocket( pAcceptedSocket->Data.Tcp.hSocket, FIONBIO, &ulValue );
				}
				else
#endif /* OCTTRANSAPI_OPT_SELECT */
				{
					unsigned long ulValue = 0;
					
					/* Make sure socket is blocking */
					WSAEventSelect(pAcceptedSocket->Data.Tcp.hSocket, NULL, 0 );						
					ioctlsocket( pAcceptedSocket->Data.Tcp.hSocket, FIONBIO, &ulValue );
				}


				if(f_pRemoteTcpAddress != NULL)
				{
					memset(f_pRemoteTcpAddress, 0, sizeof(*f_pRemoteTcpAddress));
					f_pRemoteTcpAddress->IpAddress.ulIpVersion		= cOCTDEV_IP_VERSION_ENUM_4;
					f_pRemoteTcpAddress->IpAddress.aulIpAddress[0]	= ntohl(AcceptedAddress.sin_addr.S_un.S_addr);
					f_pRemoteTcpAddress->ulTcpPort					= ntohs(AcceptedAddress.sin_port);
				}

				*f_phAcceptedTransport = pAcceptedTransInst;
				pAcceptedSocket->TransTcpCtx.fAccepted = cOCT_TRUE;
			}
	}

	return iRc;
}

#endif /* WIN32 */
