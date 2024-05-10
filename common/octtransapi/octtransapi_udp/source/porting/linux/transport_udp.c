#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transport.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: UDP linux porting transport

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
#include <stdio.h>
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
#include <ifaddrs.h>
#include <unistd.h>

#ifdef OCTTRANSAPI_OPT_SELECT
#ifdef OCTTRANSAPI_OPT_POLL
#include <sys/poll.h>
#else
#include <sys/select.h>
#endif	/* OCTTRANSAPI_OPT_POLL */

#endif /* OCTTRANSAPI_OPT_SELECT */


/* Porting interface */
#include "../../../include/transapi_udp.h"
#include "../../../include/octtransapi_udp.h"
#include "../../../../octtransapi/include/transapi.h"

/*********************************  MACROS ************************************/
#ifndef mMIN
#define mMIN( a, b ) ((a>b)?b:a)
#endif

#define cTRANSAPI_UDP_LOOPBACK_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_UDP_LOOPBACK_MSG_SIZE_MAX		(256)

#define cTRANSAPI_UDP_SEARCHED_INTERFACES		(32)

/*******************************  STRUCTURE ***********************************/

#define tTRANSAPI_UDP_SOCKET_TYPE_ENUM				tOCT_UINT32
#define cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK		(0)
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
			int iReadSocket;
			int iWriteSocket;

		} Loopback;

		struct
		{
			int							iSocket;			/* Socket handle */
			tOCT_UINT32					ulTimeout;			/* Last applied timeout value */
		} Udp;

		int iSelectableSocket;

	} Data;

	/* Room for ulMaxDestination tTRANSAPI_DESTINATION_CTX and tOCTDEV_UDP_ADDRESS structures follow */

} tTRANSAPI_UDP_SOCKET, *tPTRANSAPI_UDP_SOCKET;

/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
	OctTransApiUdpGetInterfaceFromAddress
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiUdpGetInterfaceFromAddress(	tOCTDEV_IP_ADDRESS*	f_pIp,
													char*				f_pszInterfaceName )

{
	int				iSocket;
    tOCT_BOOL32     fFound = cOCT_FALSE;

	/* Create socket. */
	iSocket = socket(AF_INET, SOCK_STREAM, 0);
	if ( iSocket < 0 )
	{
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}

#ifdef SIOCGIFCONF
    {
        struct ifconf conf;
        struct ifreq req[cTRANSAPI_UDP_SEARCHED_INTERFACES];
        struct ifreq	*pIfreq;
        int i;

        conf.ifc_len = sizeof(req);
        conf.ifc_buf = (__caddr_t) req;
        ioctl(iSocket,SIOCGIFCONF,&conf);


        for (i=0; i<conf.ifc_len/sizeof(req[0]); i++)
        {
            struct sockaddr_in *paddr;

            pIfreq = &conf.ifc_req[i];

            /* Filter out non-ethernet interfaces */
            ioctl(iSocket, SIOCGIFHWADDR, pIfreq, sizeof( struct ifreq ));

            if ( ARPHRD_ETHER != pIfreq->ifr_hwaddr.sa_family )
                continue;

            if ( ioctl(iSocket, SIOCGIFFLAGS, (char*)pIfreq) == -1)
                continue;

             /* Chck if UP... */
            if ( !(pIfreq->ifr_flags & IFF_UP) )
                continue;

            /* get interface ip ... if any */
            if (0 < ioctl(iSocket, SIOCGIFADDR, (char *)pIfreq ))
                continue;

            paddr = (struct sockaddr_in *) &pIfreq->ifr_addr;
            if (paddr->sin_family != AF_INET)
                continue;

            /* Looking for this host */
            if( f_pIp->aulIpAddress[0] == ntohl( paddr->sin_addr.s_addr) )
            {
                strcpy(f_pszInterfaceName, pIfreq->ifr_name);
                fFound = cOCT_TRUE;
                break;
            }

        }

    }

#else
    {
        int				iInterfaceIndex;
        unsigned		uiIndex = 0;
        char			abIfreq[sizeof(struct ifreq)*5];
        struct ifreq	*pIfreq = (struct ifreq	*)abIfreq;

        memset( abIfreq, 0, sizeof(abIfreq));

        for (iInterfaceIndex = 0; iInterfaceIndex < cTRANSAPI_UDP_SEARCHED_INTERFACES; iInterfaceIndex++)
        {
            /* Get the interface name as the Os uses it */
            pIfreq->ifr_ifindex = iInterfaceIndex;

            if ( 0 == ioctl(iSocket, SIOCGIFNAME, pIfreq, sizeof( struct ifreq )) )
            {
                /* Filter out non-ethernet interfaces */
                ioctl(iSocket, SIOCGIFHWADDR, pIfreq, sizeof( struct ifreq ));

                if ( ARPHRD_ETHER == pIfreq->ifr_hwaddr.sa_family )
                {
                    struct sockaddr_in *paddr;

                    /* Get interface flag ... */
                    if ( ioctl(iSocket, SIOCGIFFLAGS, (char*)pIfreq) == -1)
                            continue;

                    /* Chck if UP... */
                    if ( !(pIfreq->ifr_flags & IFF_UP) )
                        continue;

                    /* get interface ip ... if any */
                    if (0 < ioctl(iSocket, SIOCGIFADDR, (char *)pIfreq ))
                        continue;

                    /* Test ip .. may be an interface on a bridge .. */
                    paddr = (struct sockaddr_in *) &pIfreq->ifr_addr;
                    if (paddr->sin_family != AF_INET)
                        continue;

                    /* Looking for this host */
                    if( f_pIp->aulIpAddress[0] == ntohl( paddr->sin_addr.s_addr) )
                    {
                        strcpy(f_pszInterfaceName, pIfreq->ifr_name);
                        fFound = cOCT_TRUE;
                        break;
                    }
                    uiIndex++;
                }
            }
        }
    }
#endif

	/* This socket is no longer needed */
	close( iSocket );

	/* Has the interface been found ? */
    if( fFound == cOCT_FALSE )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}
	
    return cOCTTRANSAPI_RC_ERROR_NONE;
}



/*--------------------------------------------------------------------------
	OctTransApiUdpOpen
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiUdpOpen( tOCTTRANSAPI_CONTEXT f_Context,
							   tPOCTTRANSAPI_UDP_OPEN f_pParms,
							   tOCTTRANSAPI_HANDLE *f_phTransport )

{
	int						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	tPTRANSAPI_UDP_SOCKET	pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = NULL;


	if( (NULL == f_pParms) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	/* Test if transport is initialized */
	if( OctTransApiIsInit() != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	if( f_pParms->UdpAddress.IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4 )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	/* Allocate socket structure */
	pSocket = (tPTRANSAPI_UDP_SOCKET)malloc(	sizeof(*pSocket) +
												f_pParms->ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX) +
												f_pParms->ulMaxDestination * sizeof(tOCTDEV_UDP_ADDRESS));
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
	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
	TransApiUdpInitCtx( &pSocket->TransUdpCtx, sizeof(*pSocket), f_pParms->ulMaxDestination);
	pTransInst->pTransApiCtx->hTransport = pTransInst;

	/* Unless told otherwise, the socket will block indefinitely */
	pSocket->Data.Udp.ulTimeout = cOCTTRANSAPI_TIMEOUT_FOREVER;
	pSocket->ulType = cTRANSAPI_UDP_SOCKET_TYPE_ENUM_UDP;

	pSocket->Data.Udp.iSocket = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
	pSocket->TransUdpCtx.ulBroadcastUdpPort = f_pParms->ulBroadcastUdpPort;
	pSocket->Data.iSelectableSocket = pSocket->Data.Udp.iSocket;
	pSocket->TransUdpCtx.TransCtx.hSelectable = (void *)(intptr_t)pSocket->Data.iSelectableSocket;

	if ( pSocket->Data.Udp.iSocket < 0 )
	{
		free(pSocket);
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}
	{
		tOCT_BOOL32 bBroadcastOpt = cOCT_TRUE;
		struct sockaddr_in		InetAddr = {};

		iRc = setsockopt(pSocket->Data.Udp.iSocket, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcastOpt, sizeof(bBroadcastOpt));
		if( iRc < 0 )
			iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
		else
		{
			int loop = 1;
			iRc = setsockopt(pSocket->Data.Udp.iSocket, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
			if( iRc < 0 )
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			else
			{
				if( f_pParms->fAllowRxBroadcast )
				{
					char szInterfaceName[IFNAMSIZ] = {};
                    char *pszToken;
					OctTransApiUdpGetInterfaceFromAddress( &f_pParms->UdpAddress.IpAddress, szInterfaceName );
					/* We rely on setsockopt's result to validate OctTransApiUdpGetInterfaceFromAddress's work */

                    // TEst if it's an alias as eth0:1 .. must bind to main int
                    pszToken = strchr( szInterfaceName, ':');
                    if( pszToken )
                        *pszToken=0;

					iRc = setsockopt(pSocket->Data.Udp.iSocket, SOL_SOCKET, SO_BINDTODEVICE, szInterfaceName, strnlen(szInterfaceName, sizeof(szInterfaceName)));
					f_pParms->UdpAddress.IpAddress.aulIpAddress[0] = 0;
				}
			}

			if( iRc < 0 )
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			else
			{
				/* Bind listening socket */
				InetAddr.sin_family			= AF_INET;
				InetAddr.sin_addr.s_addr	= htonl(f_pParms->UdpAddress.IpAddress.aulIpAddress[0]);
				InetAddr.sin_port			= htons((unsigned short)f_pParms->UdpAddress.ulUdpPort);
				iRc = bind(pSocket->Data.Udp.iSocket, (struct sockaddr *) &InetAddr, sizeof(InetAddr));
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
				}
				else if( f_pParms->UdpAddress.ulUdpPort == 0)
				{
					/* return selected port */
					struct sockaddr_in addrIn;
					socklen_t addrInLen = sizeof( addrIn );

					if( getsockname( pSocket->Data.Udp.iSocket, (struct sockaddr *)&addrIn, &addrInLen ) != -1 )
						f_pParms->ulSelectedPort = ntohs(addrIn.sin_port);
				}
				else
					f_pParms->ulSelectedPort = f_pParms->UdpAddress.ulUdpPort;
			}
		}
	}

	if ( cOCTTRANSAPI_RC_ERROR_NONE != iRc )
	{
		if ( NULL != pSocket )
		{
			OctTransApiUdpClose( pTransInst );
		}
	}
	else
	{
		*f_phTransport = pTransInst;
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
    struct ifaddrs *pInterfaceAddressList;
	struct sockaddr_storage LocalIp;
	socklen_t LocalIpLen = sizeof(LocalIp);
 
	if( (NULL == f_pBroadcastAddress) || (NULL == f_hTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

	iRc = getsockname( pSocket->Data.Udp.iSocket, (struct sockaddr *)&LocalIp, &LocalIpLen );
	if( iRc == 0 )
	{
		if( LocalIp.ss_family != AF_INET )
		{
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
		}
	}

	if( iRc == 0 )
	{
		iRc = getifaddrs(&pInterfaceAddressList);
	}
	
	if( iRc >= 0 )
	{
		struct ifaddrs *pInterfaceAddress;
		
		for( pInterfaceAddress = pInterfaceAddressList; pInterfaceAddress; pInterfaceAddress = pInterfaceAddress->ifa_next )
		{
			if( NULL == pInterfaceAddress->ifa_addr )
			{
				continue;
			}

			if( ((struct sockaddr_in *)pInterfaceAddress->ifa_addr)->sin_addr.s_addr == ((struct sockaddr_in*)&LocalIp)->sin_addr.s_addr &&
				pInterfaceAddress->ifa_netmask != NULL )
			{
				memset( f_pBroadcastAddress, 0, sizeof(tOCTDEV_UDP_ADDRESS) );
				f_pBroadcastAddress->IpAddress.ulIpVersion		= cOCTTRANSAPI_IP_VERSION_ENUM_4;
				f_pBroadcastAddress->IpAddress.aulIpAddress[0]	= ntohl(((struct sockaddr_in *)pInterfaceAddress->ifa_addr)->sin_addr.s_addr | 
																		~((struct sockaddr_in *)pInterfaceAddress->ifa_netmask)->sin_addr.s_addr );
				f_pBroadcastAddress->ulUdpPort					= pSocket->TransUdpCtx.ulBroadcastUdpPort;
				break;
			}
		}

		freeifaddrs( pInterfaceAddressList );
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
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
    tOCT_INT32		iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
    int				iSocket;
    unsigned		uiIndex = 0;

    /* Create socket. */
    iSocket = socket(AF_INET, SOCK_STREAM, 0);
    if ( iSocket < 0 )
    {
        return cOCTTRANSAPI_RC_ERROR_TRANSPORT;
    }

#ifdef SIOCGIFCONF
    struct ifconf conf;
    struct ifreq req[cTRANSAPI_UDP_SEARCHED_INTERFACES];
    struct ifreq	*pIfreq;
    int i;

    conf.ifc_len = sizeof(req);
    conf.ifc_buf = (__caddr_t) req;
    ioctl(iSocket,SIOCGIFCONF,&conf);


    for (i=0; i<conf.ifc_len/sizeof(req[0]); i++)
    {
        struct sockaddr_in *paddr;

        pIfreq = &conf.ifc_req[i];

        /* Filter out non-ethernet interfaces */
        ioctl(iSocket, SIOCGIFHWADDR, pIfreq, sizeof( struct ifreq ));

        if ( ARPHRD_ETHER != pIfreq->ifr_hwaddr.sa_family )
            continue;

        if ( ioctl(iSocket, SIOCGIFFLAGS, (char*)pIfreq) == -1)
            continue;

         /* Chck if UP... */
        if ( !(pIfreq->ifr_flags & IFF_UP) )
            continue;

        /* get interface ip ... if any */
        if (0 < ioctl(iSocket, SIOCGIFADDR, (char *)pIfreq ))
            continue;

        paddr = (struct sockaddr_in *) &pIfreq->ifr_addr;
        if (paddr->sin_family != AF_INET)
            continue;

        /* Looking for this host */
        if( uiIndex == f_ulLocalHostIndex )
        {

            f_pIp->ulIpVersion				= cOCTTRANSAPI_IP_VERSION_ENUM_4;
            f_pIp->aulIpAddress[0]			= ntohl( paddr->sin_addr.s_addr);

            /* Get the NETMASK */
            if (0 < ioctl(iSocket, SIOCGIFNETMASK, pIfreq ))
            {
                  iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
                  break;
            }

            f_pNetmask->ulIpVersion			= cOCTTRANSAPI_IP_VERSION_ENUM_4;
            f_pNetmask->aulIpAddress[0]		= ntohl(((struct sockaddr_in *)&pIfreq->ifr_netmask)->sin_addr.s_addr);
            iRc = cOCTTRANSAPI_RC_ERROR_NONE;
            break;
        }
        uiIndex++;

    }

#else

    int				iInterfaceIndex;


	char			abIfreq[sizeof(struct ifreq)*5];
	struct ifreq	*pIfreq = (struct ifreq	*)abIfreq;

	/* Create socket. */
	iSocket = socket(AF_INET, SOCK_STREAM, 0);
	if ( iSocket < 0 )
	{
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}

	memset( abIfreq, 0, sizeof(abIfreq));

	for (iInterfaceIndex = 0; iInterfaceIndex < cTRANSAPI_UDP_SEARCHED_INTERFACES; iInterfaceIndex++)
	{
		/* Get the interface name as the Os uses it */
		pIfreq->ifr_ifindex = iInterfaceIndex;

		if ( 0 == ioctl(iSocket, SIOCGIFNAME, pIfreq, sizeof( struct ifreq )) )
		{
			/* Filter out non-ethernet interfaces */
			ioctl(iSocket, SIOCGIFHWADDR, pIfreq, sizeof( struct ifreq ));

			if ( ARPHRD_ETHER == pIfreq->ifr_hwaddr.sa_family )
			{
				struct sockaddr_in *paddr;

				/* Get interface flag ... */
				if ( ioctl(iSocket, SIOCGIFFLAGS, (char*)pIfreq) == -1)
						continue;

				/* Chck if UP... */
				if ( !(pIfreq->ifr_flags & IFF_UP) )
					continue;

				/* get interface ip ... if any */
				if (0 < ioctl(iSocket, SIOCGIFADDR, (char *)pIfreq ))
					continue;

				/* Test ip .. may be an interface on a bridge .. */
				paddr = (struct sockaddr_in *) &pIfreq->ifr_addr;
				if (paddr->sin_family != AF_INET)
					continue;

				/* Looking for this host */
				if( uiIndex == f_ulLocalHostIndex )
				{

					f_pIp->ulIpVersion				= cOCTTRANSAPI_IP_VERSION_ENUM_4;
					f_pIp->aulIpAddress[0]			= ntohl( paddr->sin_addr.s_addr);

					/* Get the NETMASK */
					if (0 < ioctl(iSocket, SIOCGIFNETMASK, pIfreq ))
					{
						  ulRet = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
						  break;
					}

					f_pNetmask->ulIpVersion			= cOCTTRANSAPI_IP_VERSION_ENUM_4;
					f_pNetmask->aulIpAddress[0]		= ntohl(((struct sockaddr_in *)&pIfreq->ifr_netmask)->sin_addr.s_addr);
                    iRc = cOCTTRANSAPI_RC_ERROR_NONE;
					break;		
				}
				uiIndex++;
			}
		}
	}

#endif
    /* This socket is no longer needed */
    close( iSocket );

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
			close( pSocket->Data.Udp.iSocket );
			pSocket->Data.Udp.iSocket = -1;
			break;

#ifdef OCTTRANSAPI_OPT_SELECT

		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
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
		pSocket->ulType = cTRANSAPI_UDP_SOCKET_TYPE_ENUM_INVALID;
		free( pSocket );
		iRc = TransApiInstanceRelease( pTransInst );
	}
	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiUdpSendTo
----------------------------------------------------------------------------*/
int	OctTransApiUdpSendTo(
			tOCTTRANSAPI_HANDLE			f_hTransport,
			tPOCTTRANSAPI_UDP_ADDRESS	f_pRemoteUdpAddress,
			void *						f_pBuffer,
			unsigned int				f_ulBufferLength )
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

			struct sockaddr_in InetAddr = {};

			if( f_pRemoteUdpAddress == NULL )
				return cOCTTRANSAPI_RC_ERROR_PARAM;

			if( f_pRemoteUdpAddress->IpAddress.ulIpVersion != cOCTTRANSAPI_IP_VERSION_ENUM_4 )
				return cOCTTRANSAPI_RC_ERROR_PARAM;

			InetAddr.sin_family			= AF_INET;
			InetAddr.sin_addr.s_addr	= htonl(f_pRemoteUdpAddress->IpAddress.aulIpAddress[0]);
			InetAddr.sin_port			= htons((unsigned short)f_pRemoteUdpAddress->ulUdpPort);

			iRc = sendto(
					pSocket->Data.Udp.iSocket,
					f_pBuffer,
					f_ulBufferLength,
					0,
					(struct sockaddr *) &InetAddr,
					sizeof(InetAddr));

		}
		break;

#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
			iRc = send (	pSocket->Data.Loopback.iWriteSocket,
							f_pBuffer,
							f_ulBufferLength,
					  		0 );
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	if( iRc < cOCTTRANSAPI_RC_ERROR_NONE)
	{
		switch( iRc )
		{
			case ENETRESET:
			case ECONNRESET:
			case EADDRNOTAVAIL:
			case EDESTADDRREQ:
			case ETIMEDOUT:
				iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
				break;
			default:
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				break;
		}
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

				/* Adjust the timeout if different */
				if ( pSocket->Data.Udp.ulTimeout != f_ulTimeoutMs )
				{

                    struct timeval timeout;

                    if( cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs )
                    {
                        timeout.tv_sec = 0xFFFFFFFF;
                        timeout.tv_usec = 0;
                    }
                    else
                    {
                        timeout.tv_sec = f_ulTimeoutMs/1000;
                        timeout.tv_usec = f_ulTimeoutMs%1000;
                    }
                    pSocket->Data.Udp.ulTimeout = f_ulTimeoutMs;
                    setsockopt( pSocket->Data.Udp.iSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout) );

				}
                while( iRc == 0 )
                {
                    iRc = recv( pSocket->Data.Udp.iSocket,
								f_pBuffer,
								f_ulMaxBufferLength,
								0 );

                    if( iRc == -1 )
                    {
                        if(( errno == EAGAIN ) ||
                           ( errno == EWOULDBLOCK ) )
                            iRc =0;
                    }
                    if( cOCTTRANSAPI_TIMEOUT_FOREVER != f_ulTimeoutMs )
                        break;
                }

			}
			break;
#ifdef OCTTRANSAPI_OPT_SELECT
		case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
			{
				iRc = recv ( 	pSocket->Data.Loopback.iReadSocket,
								f_pBuffer,
								f_ulMaxBufferLength,
								0 );
			}
			break;
#endif /* OCTTRANSAPI_OPT_SELECT */

	}

	if( iRc < cOCTTRANSAPI_RC_ERROR_NONE)
	{
		switch( errno )
		{
			case ENETRESET:
			case ECONNRESET:
			case EADDRNOTAVAIL:
			case EDESTADDRREQ:
			case ETIMEDOUT:
				iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
				break;
			default:
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				break;
		}
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
			socklen_t			FromLen = sizeof(struct sockaddr_in);
			struct sockaddr_in	RecvFrom;

			/* Adjust the timeout if different */
			if ( pSocket->Data.Udp.ulTimeout != f_ulTimeoutMs )
			{
                struct timeval timeout;

                if( cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs )
                {
                    timeout.tv_sec = 0xFFFFFFFF;
                    timeout.tv_usec = 0;
                }
                else
                {
                    timeout.tv_sec = f_ulTimeoutMs/1000;
                    timeout.tv_usec = f_ulTimeoutMs%1000;
                }

                setsockopt( pSocket->Data.Udp.iSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout) );
				pSocket->Data.Udp.ulTimeout = f_ulTimeoutMs;
			}

            while( iRc == 0 )
            {

                iRc = recvfrom( pSocket->Data.Udp.iSocket,
                                f_pBuffer,
                                f_ulMaxBufferLength,
                                0, &RecvFrom, &FromLen );

                if ( iRc >= 0 )
                {
                    if( RecvFrom.sin_family == AF_INET )
                    {
						memset( f_pRemoteUdpAddress, 0, sizeof(tOCTDEV_UDP_ADDRESS) );
                        f_pRemoteUdpAddress->IpAddress.aulIpAddress[0] = ntohl(RecvFrom.sin_addr.s_addr);
                        f_pRemoteUdpAddress->IpAddress.ulIpVersion = cOCTTRANSAPI_IP_VERSION_ENUM_4;
                        f_pRemoteUdpAddress->ulUdpPort = (tOCT_UINT32)ntohs(RecvFrom.sin_port);
                    }
                }

                if( cOCTTRANSAPI_TIMEOUT_FOREVER != f_ulTimeoutMs )
                    break;
            }
		}
		break;

#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK	:
		{
			iRc = recv ( 	pSocket->Data.Loopback.iReadSocket,
							f_pBuffer,
							f_ulMaxBufferLength,
							0 );
		}
		break;
#endif /* OCTTRANSAPI_OPT_SELECT */

	}

	if( iRc < cOCTTRANSAPI_RC_ERROR_NONE)
	{
		switch( errno )
		{
			case ENETRESET:
			case ECONNRESET:
			case EADDRNOTAVAIL:
			case EDESTADDRREQ:
			case ETIMEDOUT:
				iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
				break;
			default:
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				break;
		}
	}
	return iRc;
}


#ifdef OCTTRANSAPI_OPT_SELECT
/*--------------------------------------------------------------------------
	OctTransApiUdpLoopbackOpen
----------------------------------------------------------------------------*/
int OctTransApiUdpLoopbackOpen(
	tOCTTRANSAPI_CONTEXT	f_Context,
	tOCTTRANSAPI_HANDLE	*f_phTransport )
{
	tPTRANSAPI_UDP_SOCKET	pSocket = (tPTRANSAPI_UDP_SOCKET)malloc(sizeof(tTRANSAPI_UDP_SOCKET));
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;
	int	sv[2];
	int iRc;

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		free( pSocket );
		return iRc;
	}

	memset(pSocket, 0, sizeof(*pSocket));
	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
	TransApiUdpInitCtx( &pSocket->TransUdpCtx, sizeof(pSocket->TransUdpCtx), 0);

	pSocket->ulType = cTRANSAPI_UDP_SOCKET_TYPE_ENUM_LOOPBACK;

	if ( socketpair( PF_LOCAL, SOCK_DGRAM, 0, sv ) < 0 )
	{
		free ( pSocket );
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}
	
	pSocket->Data.Loopback.iReadSocket	= sv[0];
	pSocket->Data.Loopback.iWriteSocket	= sv[1];

	*f_phTransport = pTransInst;

	return cOCTTRANSAPI_RC_ERROR_NONE;
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
#ifdef OCTTRANSAPI_OPT_POLL
	struct pollfd fds[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
#else
	int 			nfds = 0;
	fd_set			rfds;
	struct timeval	tv = { f_ulTimeoutMs / 1000, (f_ulTimeoutMs % 1000) * 1000 };
	FD_ZERO(&rfds);
#endif

	for ( ulIndex=0; ulIndex<f_ulTransportCnt; ulIndex++ )
	{
		tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[ulIndex];
		tPTRANSAPI_UDP_SOCKET	pSocket;

		if( pTransInst == NULL || pTransInst->pTransApiCtx == NULL )
			return cOCTTRANSAPI_RC_ERROR_PARAM;

		pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

#ifdef OCTTRANSAPI_OPT_POLL
		fds[ulIndex].fd		= pSocket->Data.iSelectableSocket;
		fds[ulIndex].events = POLLIN;
#else
		/* Set FD in preparation of select operation */
		FD_SET(pSocket->Data.iSelectableSocket, &rfds);
		nfds = mMAX(nfds, pSocket->Data.iSelectableSocket);
#endif
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

#else
	iRc = select(	nfds+1,
					&rfds, NULL, NULL,
					cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs ? NULL : &tv );

	for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
	{
		tTRANSAPI_TRANSPORT_INSTANCE *pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_ahTransport[ulIndex];
		pSocket = (tPTRANSAPI_UDP_SOCKET)pTransInst->pTransApiCtx;

		/* Set FD in preparation of select operation */
		f_aulState[ulIndex] =	FD_ISSET(pSocket->Data.iSelectableSocket, &rfds) ?
									cOCTTRANSAPI_UDP_SELECT_STATE_RECV :
									cOCTTRANSAPI_UDP_SELECT_STATE_NONE ;
	}
#endif


	return iRc;
}


#endif /* OCTTRANSAPI_OPT_SELECT */
#endif /* __linux__ */
