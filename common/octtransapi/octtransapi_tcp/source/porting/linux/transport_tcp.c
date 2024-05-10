#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transport.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: TCP linux porting transport

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
// #define OCT_OPT_REMOVE_OCTTRANSAPI_OPT_POLL // allow to remove this option

#ifndef OCT_OPT_REMOVE_OCTTRANSAPI_OPT_POLL
#define OCTTRANSAPI_OPT_POLL		/* Specify to use POLL instead of select */
#endif	/* OCT_OPT_REMOVE_OCTTRANSAPI_POLL */


#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>

#ifdef OCTTRANSAPI_OPT_SELECT
#ifdef OCTTRANSAPI_OPT_POLL
#include <sys/poll.h>
#else
#include <sys/select.h>
#endif	/* OCTTRANSAPI_OPT_POLL */

#endif /* OCTTRANSAPI_OPT_SELECT */


/* Porting interface */
#include "../../../include/transapi_tcp.h"
#include "../../../include/octtransapi_tcp.h"
#include "../../../../octtransapi/include/transapi.h"

/*********************************  MACROS ************************************/
#ifndef mMIN
#define mMIN( a, b ) ((a>b)?b:a)
#endif

#define cTRANSAPI_TCP_LOOPBACK_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_TCP_LOOPBACK_MSG_SIZE_MAX		(256)

#define cTRANSAPI_TCP_SEARCHED_INTERFACES		(32)

/*******************************  STRUCTURE ***********************************/

#define tTRANSAPI_TCP_SOCKET_TYPE_ENUM				tOCT_UINT32
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK		(0)
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
			int iReadSocket;
			int iWriteSocket;

		} Loopback;

		struct
		{
			int							iSocket;			/* Socket handle */
			tOCT_UINT32					ulTimeout;			/* Last applied timeout value */
		} Tcp;

	} Data;

	tTRANSAPI_DESTINATION_CTX	aDestinationCtx[cMAX_DESTINATIONS_PER_SOCKET];
	tOCTDEV_TCP_ADDRESS			aDestinationTcpAddress[cMAX_DESTINATIONS_PER_SOCKET];

} tTRANSAPI_TCP_SOCKET, *tPTRANSAPI_TCP_SOCKET;

/****************************  USER INTERFACE *********************************/

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
	int flags;
	
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
	flags = fcntl(pSocket->Data.Tcp.iSocket, F_GETFL, 0);
    flags |= O_NONBLOCK;
	fcntl(pSocket->Data.Tcp.iSocket, F_SETFL, flags);

	iRc = connect(pSocket->Data.Tcp.iSocket, (struct sockaddr *) &InetAddr, sizeof(InetAddr));

	if(iRc < 0)
	{
		if( errno == EINPROGRESS )
		{
			struct timeval Timeout, *pTimeout = NULL;
			fd_set WriteFds;

			FD_ZERO(&WriteFds);
			FD_SET(pSocket->Data.Tcp.iSocket, &WriteFds);
			
			if( pSocket->Data.Tcp.ulTimeout != cOCTTRANSAPI_TIMEOUT_FOREVER )
			{
				Timeout.tv_sec = pSocket->Data.Tcp.ulTimeout / 1000;
				Timeout.tv_usec = (pSocket->Data.Tcp.ulTimeout % 1000) * 1000;
				pTimeout = &Timeout;
			}

			if( select(pSocket->Data.Tcp.iSocket+1, NULL, &WriteFds, NULL, pTimeout) == 1 )
			{
				iRc = 0;
			}
		}
	}

	if(iRc == 0)
	{
		flags = fcntl(pSocket->Data.Tcp.iSocket, F_GETFL, 0);

#ifdef OCTTRANSAPI_OPT_SELECT
		if( pSocket->TransTcpCtx.fUseSelect )
		{
			/* Make sure socket is non-blocking */
			flags |= O_NONBLOCK;
			fcntl( pSocket->Data.Tcp.iSocket, F_SETFL, &flags );
		}
		else
#endif /* OCTTRANSAPI_OPT_SELECT */
		{
			flags = (flags&~O_NONBLOCK);
			
			/* Make sure socket is blocking */
			fcntl( pSocket->Data.Tcp.iSocket, F_SETFL, &flags );
		}
	}
	else
		pSocket->TransTcpCtx.TransCtx.ulLastError = errno;

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
	struct sockaddr_in		InetAddr;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = NULL;

	if( (NULL == f_pParms) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if( (NULL == f_pParms) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if( f_pParms->LocalTcpAddress.IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4 )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if(f_pParms->fServer && (f_pParms->RemoteTcpAddress.ulTcpPort != 0) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	/* Allocate socket structure */
	pSocket = (tPTRANSAPI_TCP_SOCKET)malloc( sizeof(*pSocket) );
	if( pSocket == NULL )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		free( pSocket );
		return iRc;
	}

	memset(pSocket, 0, sizeof(*pSocket));
				
	/* Unless told otherwise, the socket will block indefinitely */
	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
	TransApiTcpInitCtx( &pSocket->TransTcpCtx, (tOCT_UINT32)&((tPTRANSAPI_TCP_SOCKET)0)->aDestinationCtx, cMAX_DESTINATIONS_PER_SOCKET);
	pTransInst->pTransApiCtx->hTransport = pTransInst;
	pSocket->Data.Tcp.ulTimeout = f_pParms->ulTimeoutMs;	// cOCTTRANSAPI_TIMEOUT_FOREVER;
	pSocket->ulType = cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP;

	pSocket->Data.Tcp.iSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

#ifdef OCTTRANSAPI_OPT_SELECT
	pSocket->TransTcpCtx.fUseSelect = f_pParms->fUseSelect;
	pSocket->TransTcpCtx.TransCtx.hSelectable = (tOCTTRANSAPI_HANDLE)pSocket->Data.Tcp.iSocket;
#endif /* OCTTRANSAPI_OPT_SELECT */

	if ( pSocket->Data.Tcp.iSocket < 0 )
	{
		free(pSocket);
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}
	{
#ifdef OCTTRANSAPI_OPT_SELECT
		fd_set			rfds;
		struct timeval	tv = { 5, 0 };

		FD_ZERO(&rfds);
		FD_SET(pSocket->Data.Tcp.iSocket, &rfds);

		iRc = select(	FD_SETSIZE, &rfds, NULL, NULL, &tv );

		if ( iRc > 0 )
		{
#endif /* OCTTRANSAPI_OPT_SELECT */

			/* Bind listening socket */
			InetAddr.sin_family			= AF_INET;
			InetAddr.sin_addr.s_addr	= htonl(f_pParms->LocalTcpAddress.IpAddress.aulIpAddress[0]);
			InetAddr.sin_port			= htons((unsigned short)f_pParms->LocalTcpAddress.ulTcpPort);
			iRc = bind(pSocket->Data.Tcp.iSocket, (struct sockaddr *) &InetAddr, sizeof(InetAddr));
			if( iRc >= 0 )
			{
				if( f_pParms->RemoteTcpAddress.ulTcpPort != 0)
				{
					iRc = OctTransApiTcpConnect( pTransInst, &f_pParms->RemoteTcpAddress );
				}
				else if(f_pParms->fServer)
				{
					iRc = listen( pSocket->Data.Tcp.iSocket, SOMAXCONN );
				}
			}

			if( iRc < 0 )
			{
				switch( errno )
				{
					case EINVAL:
					case EADDRINUSE:
					case EADDRNOTAVAIL:
					case EFAULT:
						iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
						break;
					default:					/* PORTING ERROR */
						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
						break;
				}
				pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
			}
#ifdef OCTTRANSAPI_OPT_SELECT
		}
		else
		{
			/* Nothing else than a PORTING error */
			iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
		}
#endif /* OCTTRANSAPI_OPT_SELECT */
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
		socklen_t addrInLen = sizeof( addrIn );

		if( getsockname( pSocket->Data.Tcp.iSocket, (struct sockaddr *)&addrIn, &addrInLen ) != -1 )
		{
			memset( f_pLocalTcpAddress, 0, sizeof( tOCTTRANSAPI_TCP_ADDRESS ));
			f_pLocalTcpAddress->IpAddress.ulIpVersion		= cOCTDEV_IP_VERSION_ENUM_4;
			f_pLocalTcpAddress->IpAddress.aulIpAddress[0]	= ntohl(addrIn.sin_addr.s_addr);
			f_pLocalTcpAddress->ulTcpPort = ntohs(addrIn.sin_port);

		}
		else
		{
			iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
			pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
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
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	tPTRANSAPI_TCP_SOCKET	pSocket;

	if( f_hTransport == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->ulType )
	{
		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_TCP		:
			close( pSocket->Data.Tcp.iSocket );
			pSocket->Data.Tcp.iSocket = -1;
			break;

#ifdef OCTTRANSAPI_OPT_SELECT

		case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	:
			close( pSocket->Data.Loopback.iReadSocket );
			close( pSocket->Data.Loopback.iWriteSocket );
			pSocket->Data.Loopback.iReadSocket = -1;
			pSocket->Data.Loopback.iWriteSocket = -1;
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
	OctTransApiTcpSend
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiTcpSend(
			tOCTTRANSAPI_HANDLE			f_hTransport,
			void *						f_pBuffer,
			unsigned int				f_ulBufferLength )
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
					pSocket->Data.Tcp.iSocket,
					f_pBuffer,
					f_ulBufferLength,
					0 );

		}
		break;

#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	:
			iRc = send (	pSocket->Data.Loopback.iWriteSocket,
							f_pBuffer,
							f_ulBufferLength,
					  		0 );
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	if( iRc < 0)
	{
		switch( iRc )
		{
			case EADDRNOTAVAIL:
			case EDESTADDRREQ:
				iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
				break;

			case EPIPE:
			case ENETRESET:
			case ECONNRESET:
				iRc = cOCTTRANSAPI_RC_ERROR_DISCONNECTED;
				break;

			default:
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				break;
		}

		pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiTcpRecv
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiTcpRecv(
	tOCTTRANSAPI_HANDLE	f_hTransport,
	unsigned int			f_ulTimeoutMs,
	void *					f_pBuffer,
	unsigned int			f_ulMaxBufferLength )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
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

				unsigned int ulCumulDataLength;
				void * pBuffer = f_pBuffer;
				size_t len = (size_t)f_ulMaxBufferLength;

				/* Adjust the timeout if different */
				if ( pSocket->Data.Tcp.ulTimeout != f_ulTimeoutMs )
				{
					int iOptVal = (cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs) ? 0 : f_ulTimeoutMs;

					setsockopt( pSocket->Data.Tcp.iSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&iOptVal, sizeof(iOptVal) );
					pSocket->Data.Tcp.ulTimeout = f_ulTimeoutMs;
				}

				for( ulCumulDataLength = 0; ulCumulDataLength < f_ulMaxBufferLength;  )
				{
					iRc = recv( pSocket->Data.Tcp.iSocket,
								pBuffer,
								len,
								0 );

					if( 0 < iRc )
					{
						/* Get ready for following data */
						ulCumulDataLength += iRc;
						pBuffer += iRc;
						len		-= iRc;

						/* Should test tOCTTRANSAPI_TCP_OPEN.fRecvByPacket and break */

					}
					else if ( iRc == 0 )
					{
						/* Connection close by peer */
						iRc = cOCTTRANSAPI_RC_ERROR_DISCONNECTED;
						break;
					}
					else
					{
						switch( errno )
						{
							case EADDRNOTAVAIL:
							case EDESTADDRREQ:
								iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
								break;

							case ETIMEDOUT:
							case EWOULDBLOCK:	/* Timeout */
								iRc =0;
								break;

							case EPIPE:
							case ENETRESET:
							case ECONNRESET:
								iRc = cOCTTRANSAPI_RC_ERROR_DISCONNECTED;
								break;

							default:
								iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
								break;
						}
						pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
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
			{
				iRc = recv ( 	pSocket->Data.Loopback.iReadSocket,
								f_pBuffer,
								f_ulMaxBufferLength,
								0 );
				if( iRc < 0 )
				{
					switch( errno )
					{
						case ENETRESET:
						case ECONNRESET:
						case EADDRNOTAVAIL:
						case EDESTADDRREQ:
							iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
							break;

						case ETIMEDOUT:
						case EWOULDBLOCK:	/* Timeout */
							iRc =0;
							break;

						default:
							iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
							break;
					}
					pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
				}
			}
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */

	}


	return iRc;
}


#ifdef OCTTRANSAPI_OPT_SELECT
/*--------------------------------------------------------------------------
	OctTransApiTcpLoopbackOpen
----------------------------------------------------------------------------*/
int OctTransApiTcpLoopbackOpen(
	tOCTTRANSAPI_CONTEXT	f_Context,
	tOCTTRANSAPI_HANDLE	*f_phTransport )
{
	tPTRANSAPI_TCP_SOCKET	pSocket = (tPTRANSAPI_TCP_SOCKET)malloc(sizeof(tTRANSAPI_TCP_SOCKET));
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;
	int				sv[2];
	int 			iRc;

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		free( pSocket );
		return iRc;
	}

	memset(pSocket, 0, sizeof(*pSocket));
	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
	TransApiTcpInitCtx( &pSocket->TransTcpCtx, sizeof(pSocket->TransTcpCtx), 0);

	pSocket->ulType = cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK;

	if ( socketpair( PF_LOCAL, SOCK_DGRAM, 0, sv ) < 0 )
	{
		free ( pSocket );
		TransApiInstanceRelease( pTransInst );
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}
	
#ifdef OCTTRANSAPI_OPT_SELECT
	pSocket->TransTcpCtx.TransCtx.hSelectable = (tOCTTRANSAPI_HANDLE)sv[0];
#endif /* OCTTRANSAPI_OPT_SELECT */

	pSocket->Data.Loopback.iReadSocket	= sv[0];
	pSocket->Data.Loopback.iWriteSocket	= sv[1];

	*f_phTransport = pTransInst;

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	OctTransApiTcpSelect
----------------------------------------------------------------------------*/
int			OctTransApiTcpSelect(
	tOCTTRANSAPI_CONTEXT	f_Context,
	unsigned int			f_ulTimeoutMs,
	unsigned int			f_ulTransportCnt,
	tOCTTRANSAPI_HANDLE		f_ahTransport[],
	unsigned int			f_aulState[] )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	unsigned int	ulIndex;

#ifdef OCTTRANSAPI_OPT_POLL
	struct pollfd fds[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
#else
	fd_set			rfds;
	struct timeval	tv = { f_ulTimeoutMs / 1000, (f_ulTimeoutMs % 1000) * 1000 };
	FD_ZERO(&rfds);
#endif /* OCTTRANSAPI_OPT_POLL */

	for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
	{
		tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[ulIndex];
		tPTRANSAPI_TCP_SOCKET	pSocket;

		if( pTransInst == NULL )
			return cOCTTRANSAPI_RC_ERROR_PARAM;

		pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;
		
#ifdef OCTTRANSAPI_OPT_POLL
		fds[ulIndex].fd		= (int)pSocket->TransTcpCtx.TransCtx.hSelectable;
		fds[ulIndex].events = POLLIN;
#else
		/* Set FD in preparation of select operation */
		FD_SET((int)pSocket->TransTcpCtx.TransCtx.hSelectable, &rfds);
#endif /* OCTTRANSAPI_OPT_POLL */
	}

#ifdef OCTTRANSAPI_OPT_POLL
	iRc = poll(fds, f_ulTransportCnt, (cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs) ? -1 : f_ulTimeoutMs );

	if( iRc > 0 )
    {
        for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
        {
			if(fds[ulIndex].revents == 0)
				f_aulState[ulIndex] = cOCTTRANSAPI_SELECT_STATE_NONE;
			else if(fds[ulIndex].revents == POLLIN )
				f_aulState[ulIndex] = cOCTTRANSAPI_SELECT_STATE_RECV;
			else	// Unexpected event
				return cOCTTRANSAPI_RC_ERROR_PORTING;
        }
    }
	else if( iRc < 0 )
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;

#else
	iRc = select(	FD_SETSIZE,
					&rfds, NULL, NULL,
					cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs ? NULL : &tv );

	if( iRc < 0 )
	{
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
		pSocket->TransTcpCtx.TransCtx.ulLastError = errno;
	}
	else
	{
		for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
		{
			tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[ulIndex];
			tPTRANSAPI_TCP_SOCKET	pSocket = (tPTRANSAPI_TCP_SOCKET)pTransInst->pTransApiCtx;

			/* Set FD in preparation of select operation */
			f_aulState[ulIndex] =	FD_ISSET((int)pSocket->TransTcpCtx.TransCtx.hSelectable, &rfds) ?
										cOCTTRANSAPI_TCP_SELECT_STATE_RECV :
										cOCTTRANSAPI_TCP_SELECT_STATE_NONE ;
		}
	}
#endif /* OCTTRANSAPI_OPT_POLL */

	return iRc;
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
	socklen_t				AcceptedAddressLen = sizeof(AcceptedAddress);

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
				/* We inherit fron the listening socket */
				pAcceptedSocket->Data.Tcp.ulTimeout = pListeningSocket->Data.Tcp.ulTimeout;
				pAcceptedSocket->TransTcpCtx.fUseSelect = pListeningSocket->TransTcpCtx.fUseSelect;

				pAcceptedSocket->Data.Tcp.iSocket = accept( pListeningSocket->Data.Tcp.iSocket,
															(struct sockaddr *)&AcceptedAddress,
															&AcceptedAddressLen );

				if ( pAcceptedSocket->Data.Tcp.iSocket < 0 )
				{
					free( pAcceptedSocket );
					pListeningSocket->TransTcpCtx.TransCtx.ulLastError = errno;
					return cOCTTRANSAPI_RC_ERROR_PORTING;
				}

#ifdef OCTTRANSAPI_OPT_SELECT
				pAcceptedSocket->TransTcpCtx.fUseSelect = pListeningSocket->TransTcpCtx.fUseSelect;
				pAcceptedSocket->TransTcpCtx.TransCtx.hSelectable = (tOCTTRANSAPI_HANDLE)pAcceptedSocket->Data.Tcp.iSocket;

				if( pAcceptedSocket->TransTcpCtx.fUseSelect )
				{
					int lValue = O_NONBLOCK;
			
					/* Make sure socket is non-blocking */
					fcntl( pAcceptedSocket->Data.Tcp.iSocket, F_SETFL, &lValue );
				}
				else
#endif /* OCTTRANSAPI_OPT_SELECT */
				{
					int lValue = 0;
			
					/* Make sure socket is blocking */
					fcntl( pAcceptedSocket->Data.Tcp.iSocket, F_SETFL, &lValue );
				}

				if(f_pRemoteTcpAddress != NULL)
				{
					memset(f_pRemoteTcpAddress, 0, sizeof(*f_pRemoteTcpAddress));
					f_pRemoteTcpAddress->IpAddress.ulIpVersion		= cOCTDEV_IP_VERSION_ENUM_4;
					f_pRemoteTcpAddress->IpAddress.aulIpAddress[0]	= ntohl(AcceptedAddress.sin_addr.s_addr);
					f_pRemoteTcpAddress->ulTcpPort					= ntohs(AcceptedAddress.sin_port);
				}

				*f_phAcceptedTransport = pAcceptedTransInst;
			}
	}

	return iRc;
}


#endif /* __linux__ */
