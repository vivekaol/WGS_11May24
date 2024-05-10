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
#include "../../../include/transapi_udp.h"
#include "../../../include/octtransapi_udp.h"
#include "../../../../octtransapi/include/transapi.h"

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment( lib, "ws2_32.lib" )


/*********************************  MACROS ************************************/
#ifndef mMIN
#define mMIN( a, b ) ((a>b)?b:a)
#endif

#define cTRANSAPI_UDP_LOOPBACK_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_UDP_LOOPBACK_MSG_SIZE_MAX		(256)

/*******************************  STRUCTURE ***********************************/
#define tTRANSAPI_UDP_SOCKET_TYPE_ENUM				tOCT_UINT32
#define cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	(0)
#define cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP			(1)
#define cTRANSAPI_UDP_SOCKET_TYPE_ENUM_INVALID		(2)

typedef struct
{
	tTRANSAPI_UDP_CTX	TransUdpCtx;		/* MUST BE FIRST */

	tTRANSAPI_UDP_SOCKET_TYPE_ENUM	ulType;

	union
	{
		struct
		{
			HANDLE						hLock;				/* Protect ourself */
			int							iReadBlock;			/* Read block index */
			int							iWriteBlock;		/* Write block index */
			tTRANSAPI_UDP_SOCKET_LOOPBACK_MSG	aMsgBlock[cTRANSAPI_UDP_LOOPBACK_MSG_BLOCK_MAX+1];	
															/* Array of available message block */
		} Loopback;

		struct
		{
			SOCKET						hSocket;			/* Socket handle */
			tOCT_UINT32					ulTimeout;			/* Last applied timeout value */
			tOCT_BOOL32					fDidSelect;
		} Udp;

	} Data;
	

	/* Room for ulMaxDestination tTRANSAPI_DESTINATION_CTX and tOCTDEV_UDP_ADDRESS structures follow */

} tTRANSAPI_UDP_SOCKET, *tPTRANSAPI_UDP_SOCKET;

/****************************  STATIC FUNCTION ********************************/

/*--------------------------------------------------------------------------
	OctTransApiUdpOpen
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiUdpOpen( tOCTTRANSAPI_CONTEXT f_Context,
							   tPOCTTRANSAPI_UDP_OPEN f_pParms, 
							   tOCTTRANSAPI_HANDLE *f_phTransport )

{
	int								iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	tPTRANSAPI_UDP_SOCKET			pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = NULL;

	WORD	wVersionRequested;
	WSADATA wsaData;


	if( (NULL == f_pParms) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	/* Test if transport is initialized */
	if( OctTransApiIsInit() != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	if( f_pParms->UdpAddress.IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4 )
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
			pSocket = (tPTRANSAPI_UDP_SOCKET)malloc( sizeof(*pSocket) +
													 f_pParms->ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX) +
													 f_pParms->ulMaxDestination * sizeof(tOCTDEV_UDP_ADDRESS));
			if ( NULL != pSocket )
			{
				if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
				{
					free( pSocket );
					return iRc;
				}
				memset(pSocket, 0, sizeof(*pSocket));
				pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
				TransApiUdpInitCtx( &pSocket->TransUdpCtx, sizeof(*pSocket), f_pParms->ulMaxDestination);
				pTransInst->pTransApiCtx->hTransport = pTransInst;
				pSocket->ulType = cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP;
#ifdef OCTTRANSAPI_OPT_SELECT
				/* Create socket stuff */
				pSocket->TransUdpCtx.TransCtx.hSelectable = WSACreateEvent();
				pSocket->TransUdpCtx.TransCtx.pfnPostSelect = TransApiUdpPostSelect;
				pSocket->TransUdpCtx.TransCtx.pfnPreSelect = TransApiUdpPreSelect;
#endif /* OCTTRANSAPI_OPT_SELECT */

				pSocket->Data.Udp.hSocket = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
				pSocket->Data.Udp.fDidSelect = cOCT_FALSE;

				/* Unless told otherwise, the socket will block indefinitely */
				pSocket->Data.Udp.ulTimeout = cOCTTRANSAPI_TIMEOUT_FOREVER;

#ifndef OCTTRANSAPI_OPT_SELECT
				if( INVALID_SOCKET != pSocket->Data.Udp.hSocket )
				{
#endif /* OCTTRANSAPI_OPT_SELECT */

#ifdef OCTTRANSAPI_OPT_SELECT
				if (( NULL != pSocket->TransUdpCtx.TransCtx.hSelectable) && (INVALID_SOCKET != pSocket->Data.Udp.hSocket ))
				{
					/* Allow broadcast */
					BOOL bBroadcastOpt = TRUE;					  
					setsockopt(pSocket->Data.Udp.hSocket, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcastOpt, sizeof(bBroadcastOpt));

					pSocket->TransUdpCtx.ulBroadcastUdpPort = f_pParms->ulBroadcastUdpPort;

					/* Associate socket with evt on first select */
//					if ( 0 != WSAEventSelect( pSocket->Data.Udp.hSocket, pSocket->TransUdpCtx.TransCtx.hSelectable, FD_READ ) )
//						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;

//					else
#endif /* OCTTRANSAPI_OPT_SELECT */
					{
						/* Bind listening socket */
						InetAddr.sin_family			= AF_INET;
						InetAddr.sin_addr.s_addr	= htonl(f_pParms->UdpAddress.IpAddress.aulIpAddress[0]);
						InetAddr.sin_port			= htons((unsigned short)f_pParms->UdpAddress.ulUdpPort);
						iRc = bind(pSocket->Data.Udp.hSocket, (SOCKADDR *) &InetAddr, sizeof(InetAddr));
						if( iRc < 0 )
						{
							switch( WSAGetLastError() )
							{
								case WSAEINVAL:
								case WSAEADDRINUSE:
								case WSAEADDRNOTAVAIL:
								case WSAEFAULT:
									iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
									break;
								default:					/* PORTING ERROR */
									iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
									break;
							}
						}
						else if( f_pParms->UdpAddress.ulUdpPort == 0)
						{
							/* return selected port */
							struct sockaddr_in addrIn;
							int addrInLen = sizeof( addrIn );

							if( getsockname( pSocket->Data.Udp.hSocket, (struct sockaddr *)&addrIn, &addrInLen ) != -1 )
								f_pParms->ulSelectedPort = ntohs(addrIn.sin_port);
						}
						else
							f_pParms->ulSelectedPort = f_pParms->UdpAddress.ulUdpPort;

					}
				}
				else
				{
					/* Nothing else than a PORTING error */
					iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
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

	if ( cOCTTRANSAPI_RC_ERROR_NONE != iRc )
	{
		if ( NULL != pSocket )
		{
			OctTransApiUdpClose( pSocket );
		}
	}
	else
	{
		*f_phTransport = pTransInst;
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiUdpGetLocalAddress
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiUdpGetLocalAddress( 	tOCT_UINT32			f_ulLocalHostIndex,
											tOCTDEV_IP_ADDRESS*	f_pIp,
											tOCTDEV_IP_ADDRESS*	f_pNetmask )
{
	tOCT_INT32				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
    INTERFACE_INFO			InterfaceList[cOCTTRANSAPI_UDP_LOCAL_HOST_MAX];
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

				if(f_ulLocalHostIndex < ulListSize)
				{
					f_pIp->ulIpVersion				= cOCTTRANSAPI_IP_VERSION_ENUM_4;
					f_pIp->aulIpAddress[0]			= ntohl(((struct sockaddr_in *)&InterfaceList[f_ulLocalHostIndex].iiAddress)->sin_addr.S_un.S_addr);

					f_pNetmask->ulIpVersion			= cOCTTRANSAPI_IP_VERSION_ENUM_4;
					f_pNetmask->aulIpAddress[0]		= ntohl(((struct sockaddr_in *)&InterfaceList[f_ulLocalHostIndex].iiNetmask)->sin_addr.S_un.S_addr);
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

/*--------------------------------------------------------------------------
	OctTransApiUdpGetBroadcastAddress
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiUdpGetBroadcastAddress( 
	tOCTTRANSAPI_HANDLE	f_hTransport,
	tOCTDEV_UDP_ADDRESS*	f_pBroadcastAddress )
{
	tOCT_INT32				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_UDP_SOCKET	pSocket;
    INTERFACE_INFO			InterfaceList[cOCTTRANSAPI_UDP_LOCAL_HOST_MAX];
    tOCT_UINT32				ulListSize;
    tOCT_UINT32				ulIndex;
	struct sockaddr_storage LocalIp;
	socklen_t LocalIpLen = sizeof(LocalIp);

	if( (NULL == f_pBroadcastAddress) || (NULL == f_hTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	iRc = getsockname( pSocket->Data.Udp.hSocket, (struct sockaddr *)&LocalIp, &LocalIpLen );
	if( iRc == 0 )
	{
		if( LocalIp.ss_family != AF_INET )
		{
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
		}
	}

	if( iRc == 0 )
	{
		iRc = WSAIoctl(	pSocket->Data.Udp.hSocket,
						SIO_GET_INTERFACE_LIST, 0, 0,
						&InterfaceList,
						sizeof(InterfaceList),
						&ulListSize, 0, 0);
	}

	if( iRc >= 0 )
	{
		ulListSize /= sizeof(INTERFACE_INFO);

		for(ulIndex = 0; ulIndex < ulListSize; ++ulIndex)
		{
			if ( ((struct sockaddr_in*)&LocalIp)->sin_addr.S_un.S_addr ==
				 ((struct sockaddr_in*)&InterfaceList[ulIndex].iiAddress)->sin_addr.S_un.S_addr )
			{
				memset( f_pBroadcastAddress, 0, sizeof(tOCTDEV_UDP_ADDRESS) );
				f_pBroadcastAddress->IpAddress.ulIpVersion		= cOCTTRANSAPI_IP_VERSION_ENUM_4;
				f_pBroadcastAddress->IpAddress.aulIpAddress[0]	= ntohl(((struct sockaddr_in *)&InterfaceList[ulIndex].iiAddress)->sin_addr.S_un.S_addr | 
																		~((struct sockaddr_in *)&InterfaceList[ulIndex].iiNetmask)->sin_addr.S_un.S_addr );
				f_pBroadcastAddress->ulUdpPort					= pSocket->TransUdpCtx.ulBroadcastUdpPort;
				break;
			}
		}
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiUdpClose
----------------------------------------------------------------------------*/
int			OctTransApiUdpClose(
	tOCTTRANSAPI_HANDLE	f_hTransport )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_UDP_SOCKET	pSocket;

	if( f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP		:

#ifdef OCTTRANSAPI_OPT_SELECT
			if( pSocket->Data.Udp.fDidSelect == cOCT_TRUE )
				WSAEventSelect( pSocket->Data.Udp.hSocket, NULL, 0 );
			WSACloseEvent( pSocket->TransUdpCtx.TransCtx.hSelectable );
#endif /* OCTTRANSAPI_OPT_SELECT */

			closesocket( pSocket->Data.Udp.hSocket );
			pSocket->Data.Udp.hSocket = 0;

			/* Clean up */
			WSACleanup();
			break;

#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
			CloseHandle( pSocket->TransUdpCtx.TransCtx.hSelectable );
			pSocket->TransUdpCtx.TransCtx.hSelectable = NULL;
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
		pSocket->ulType = cTRANSAPI_UDP_SOCKET_TYPE_ENUM_INVALID;
		free( pSocket );
		iRc = TransApiInstanceRelease( pTransInst );

	}
	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiUdpSendTo
----------------------------------------------------------------------------*/
int			OctTransApiUdpSendTo(
	tOCTTRANSAPI_HANDLE	f_hTransport,
	tPOCTTRANSAPI_UDP_ADDRESS	f_pRemoteUdpAddress,
	void *				f_pBuffer,
	unsigned int		f_ulBufferLength )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_UDP_SOCKET	pSocket;

	if(  f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		default:
			return cOCTTRANSAPI_RC_ERROR_PARAM;

		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP :
			{

				struct sockaddr_in InetAddr;

				if( f_pRemoteUdpAddress == NULL )
					return cOCTTRANSAPI_RC_ERROR_PARAM;

				if( f_pRemoteUdpAddress->IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4 )
					return cOCTTRANSAPI_RC_ERROR_PARAM;

				InetAddr.sin_family			= AF_INET;
				InetAddr.sin_addr.s_addr	= htonl(f_pRemoteUdpAddress->IpAddress.aulIpAddress[0]);
				InetAddr.sin_port			= htons((unsigned short)f_pRemoteUdpAddress->ulUdpPort);

				iRc = sendto( 
						pSocket->Data.Udp.hSocket, 
						f_pBuffer,
						f_ulBufferLength,
						0, 
						(SOCKADDR *) &InetAddr, 
						sizeof(InetAddr));

				if( iRc < 0 )
				{
					switch( WSAGetLastError() )
					{
						case WSAENETRESET:
						case WSAECONNRESET:
						case WSAEADDRNOTAVAIL:
						case WSAEDESTADDRREQ:
						case WSAETIMEDOUT:
							iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
							break;
						default:
							iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
							break;
					}
				}
			}
			break;

#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
			if ( WAIT_OBJECT_0 == WaitForSingleObject( 
										pSocket->Data.Loopback.hLock, 
										INFINITE ) )
			{
				int	iNextWrite;
				/* Calculate next write index */
				iNextWrite = pSocket->Data.Loopback.iWriteBlock;
				iNextWrite++;
				if ( iNextWrite > cTRANSAPI_UDP_LOOPBACK_MSG_BLOCK_MAX )
				{
					iNextWrite = 0;
				}

				/* Room to store a new one ? */
				if ( pSocket->Data.Loopback.iReadBlock != iNextWrite )
				{
					memcpy( pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].abyBuffer,f_pBuffer,
									mMIN( cTRANSAPI_UDP_LOOPBACK_MSG_SIZE_MAX, f_ulBufferLength ) );
					pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].ulSize 
								= mMIN( cTRANSAPI_UDP_LOOPBACK_MSG_SIZE_MAX, f_ulBufferLength );
					iRc = pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].ulSize;
					pSocket->Data.Loopback.iWriteBlock = iNextWrite;
				}
				else
				{
					iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				}
				ReleaseSemaphore( pSocket->Data.Loopback.hLock, 1, NULL );
				/* Signal a new msg in Q */
				SetEvent( pSocket->TransUdpCtx.TransCtx.hSelectable );
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
	OctTransApiUdpRecv
----------------------------------------------------------------------------*/
int			OctTransApiUdpRecv(
	tOCTTRANSAPI_HANDLE	f_hTransport,
	unsigned int			f_ulTimeoutMs,
	void *					f_pBuffer,
	unsigned int			f_ulMaxBufferLength )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_UDP_SOCKET	pSocket;

	if( f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		default:
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
			break;

		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP	:
			{
				WSABUF			RecvBuff;
				DWORD			ulRecvLen;
				DWORD			ulFlags;

				RecvBuff.buf	= f_pBuffer;
				RecvBuff.len	= f_ulMaxBufferLength;
				ulFlags = 0;

				/* Adjust the timeout if different */
				if ( pSocket->Data.Udp.ulTimeout != f_ulTimeoutMs )
				{
					DWORD dwOptVal = (cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs) ? 0 : f_ulTimeoutMs;

					setsockopt( pSocket->Data.Udp.hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&dwOptVal, sizeof(dwOptVal) );
					pSocket->Data.Udp.ulTimeout = f_ulTimeoutMs;
				}

				iRc = WSARecv(
						pSocket->Data.Udp.hSocket, 
						&RecvBuff,
						1,
						&ulRecvLen,
						&ulFlags,
						NULL,
						NULL );
				if ( 0 == iRc )
				{
					iRc = ulRecvLen;
				}
				else
				{

					switch( WSAGetLastError() )
					{
						case WSAECONNABORTED:
						case WSAENETUNREACH:			
						case WSAECONNRESET:			
							iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
							break;

						case WSAETIMEDOUT:
							iRc = 0;
							break;

						default:					/* PORTING ERROR */
							iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
							break;

					}
				}

			}
			break;
#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
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
					if ( pSocket->Data.Loopback.iReadBlock > cTRANSAPI_UDP_LOOPBACK_MSG_BLOCK_MAX )
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
	OctTransApiUdpRecvFrom
----------------------------------------------------------------------------*/
int			OctTransApiUdpRecvFrom(
	tOCTTRANSAPI_HANDLE		f_hTransport,
	tPOCTTRANSAPI_UDP_ADDRESS	f_pRemoteUdpAddress,
	unsigned int			f_ulTimeoutMs,
	void *					f_pBuffer,
	unsigned int			f_ulMaxBufferLength )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_UDP_SOCKET	pSocket;

	if( ( f_hTransport == NULL ) ||
		( f_pRemoteUdpAddress == NULL ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		default:
			return cOCTTRANSAPI_RC_ERROR_PARAM;
			break;

		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP	:
			{
				WSABUF			RecvBuff;
				DWORD			ulRecvLen;
				DWORD			ulFlags;
				struct sockaddr_in	RecvFrom;
				int				lRecvFromLen;

				RecvBuff.buf	= f_pBuffer;
				RecvBuff.len	= f_ulMaxBufferLength;
				ulFlags = 0;

				/* Adjust the timeout if different */
				if ( pSocket->Data.Udp.ulTimeout != f_ulTimeoutMs )
				{
					DWORD dwOptVal = (cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs) ? 0 : f_ulTimeoutMs;

					setsockopt( pSocket->Data.Udp.hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&dwOptVal, sizeof(dwOptVal) );
					pSocket->Data.Udp.ulTimeout = f_ulTimeoutMs;
				}

				lRecvFromLen = sizeof(RecvFrom);

				iRc = WSARecvFrom(
						pSocket->Data.Udp.hSocket, 
						&RecvBuff,
						1,
						&ulRecvLen,
						&ulFlags,
						(SOCKADDR *)&RecvFrom,
						&lRecvFromLen,
						NULL,
						NULL );
				if ( 0 == iRc )
				{
		            if( RecvFrom.sin_family == AF_INET )
					{
						memset( f_pRemoteUdpAddress, 0, sizeof(tOCTDEV_UDP_ADDRESS) );
						f_pRemoteUdpAddress->IpAddress.aulIpAddress[0] = ntohl(RecvFrom.sin_addr.S_un.S_addr);
						f_pRemoteUdpAddress->IpAddress.ulIpVersion = cOCTTRANSAPI_IP_VERSION_ENUM_4;
						f_pRemoteUdpAddress->ulUdpPort = (tOCT_UINT32)ntohs(RecvFrom.sin_port);
					}

					iRc = ulRecvLen;
				}
				else
				{
					int iWrc = WSAGetLastError();
					switch( iWrc )
					{
						case WSAECONNABORTED:
						case WSAENETUNREACH:			
						case WSAECONNRESET:		
							iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
							break;

						case WSAEWOULDBLOCK:
						case WSAETIMEDOUT:
							iRc = 0;
							break;

						default:	
							iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
							break;
					}
				}
			}
			break;
#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
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
					if ( pSocket->Data.Loopback.iReadBlock > cTRANSAPI_UDP_LOOPBACK_MSG_BLOCK_MAX )
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

#ifdef OCTTRANSAPI_OPT_SELECT
/*--------------------------------------------------------------------------
	TransApiUdpPostSelect
----------------------------------------------------------------------------*/
int	TransApiUdpPostSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;
    tPTRANSAPI_UDP_SOCKET pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	/*  socket activity on udp ... not local */
	if( pSocket->ulType == cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP )
	{
		WSANETWORKEVENTS networkEvents;
		int iRc = WSAEnumNetworkEvents( pSocket->Data.Udp.hSocket, pSocket->TransUdpCtx.TransCtx.hSelectable, &networkEvents );
		if(( iRc != 0 ) || ((networkEvents.lNetworkEvents & FD_READ) != FD_READ) )
			iRc = cOCTTRANSAPI_RC_ERROR_PORTING;

		WSAResetEvent(pSocket->TransUdpCtx.TransCtx.hSelectable);
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	TransApiUdpPreSelect
----------------------------------------------------------------------------*/
int	TransApiUdpPreSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;
    tPTRANSAPI_UDP_SOCKET pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;
	

	/*  socket activity on udp ... not local */
	if( pSocket->ulType == cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP )
	{
		if( pSocket->Data.Udp.fDidSelect == cOCT_FALSE )
		{
			if ( 0 != WSAEventSelect( pSocket->Data.Udp.hSocket, pSocket->TransUdpCtx.TransCtx.hSelectable, FD_READ ) )
				return cOCTTRANSAPI_RC_ERROR_PORTING;
			else
				pSocket->Data.Udp.fDidSelect = cOCT_TRUE;
		}
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	OctTransApiUdpLoopbackOpen
----------------------------------------------------------------------------*/
int OctTransApiUdpLoopbackOpen( 
	tOCTTRANSAPI_CONTEXT	f_Context,
	tOCTTRANSAPI_HANDLE	*f_phTransport )
{
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tPTRANSAPI_UDP_SOCKET	pSocket = (tPTRANSAPI_UDP_SOCKET)malloc(sizeof(tTRANSAPI_UDP_SOCKET));
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		free( pSocket );
		return iRc;
	}

	memset(pSocket, 0, sizeof(*pSocket));
	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
	TransApiUdpInitCtx( &pSocket->TransUdpCtx, sizeof(pSocket->TransUdpCtx), 0);

	pSocket->ulType = cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK;
	pSocket->Data.Loopback.iReadBlock	= 0;
	pSocket->Data.Loopback.iWriteBlock	= 0;
	pSocket->Data.Loopback.hLock		= CreateSemaphore( NULL, 1, 1, NULL );
	pSocket->TransUdpCtx.TransCtx.hSelectable = CreateEvent( NULL, FALSE, FALSE, NULL );

	*f_phTransport = pTransInst;
	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiUdpSelect
----------------------------------------------------------------------------*/
int			OctTransApiUdpSelect(
	tOCTTRANSAPI_CONTEXT	f_Context, 
	unsigned int			f_ulTimeoutMs,
	unsigned int			f_ulTransportCnt,
	tOCTTRANSAPI_HANDLE	f_ahTransport[],
	unsigned int			f_aulState[] )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	unsigned int	ulIndex;
	tPTRANSAPI_UDP_SOCKET	pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *pTransInst;
	HANDLE			aHandles[32];
	DWORD			dwRc;

	memset( aHandles, 0x0, sizeof(aHandles) );

	for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
	{
		pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[ulIndex];
		if( pTransInst == NULL || pTransInst->pTransApiCtx == NULL )
			return cOCTTRANSAPI_RC_ERROR_PARAM;

		pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;
		aHandles[ulIndex] = pSocket->TransUdpCtx.TransCtx.hSelectable;

		/* State is not ready */
		f_aulState[ulIndex] = cOCTTRANSAPI_UDP_SELECT_STATE_NONE;

		if( pSocket->Data.Udp.fDidSelect == cOCT_FALSE )
		{
			if ( 0 != WSAEventSelect( pSocket->Data.Udp.hSocket, pSocket->TransUdpCtx.TransCtx.hSelectable, FD_READ ) )
				return cOCTTRANSAPI_RC_ERROR_PORTING;
			else
				pSocket->Data.Udp.fDidSelect = cOCT_TRUE;
		}

	}

	/* Wait for something to happen */
	dwRc =  WaitForMultipleObjects(
					f_ulTransportCnt,
					aHandles,
					FALSE,
					(cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs)	? INFINITE :f_ulTimeoutMs);

	if ( WAIT_TIMEOUT == dwRc )
	{
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	else if ( WAIT_OBJECT_0 <= dwRc && WAIT_OBJECT_0 + f_ulTransportCnt > dwRc )
	{
		pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[dwRc-WAIT_OBJECT_0];
		pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

		/*  socket activity on udp ... not local */
		if( pSocket->ulType == cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP )
		{
			WSANETWORKEVENTS networkEvents;
			iRc = WSAEnumNetworkEvents( pSocket->Data.Udp.hSocket, pSocket->TransUdpCtx.TransCtx.hSelectable, &networkEvents );
			if(( iRc != 0 ) || ((networkEvents.lNetworkEvents & FD_READ) != FD_READ) )
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			
			WSAResetEvent(pSocket->TransUdpCtx.TransCtx.hSelectable);
		}

		/* Fill the state array (only retrieve one event at a time) */
		if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
		{
			f_aulState[dwRc - WAIT_OBJECT_0] = cOCTTRANSAPI_UDP_SELECT_STATE_RECV;

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

#endif /* OCTTRANSAPI_OPT_SELECT */
#endif /* WIN32 */
