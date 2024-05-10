#if defined( _LINUX_ ) || defined( __linux__ )
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

#include "../../../include/transapi_local.h"

/*******************************  STRUCTURE ***********************************/
#define cTRANSAPI_LOCAL_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_LOCAL_MSG_SIZE_MAX	(256)
#define cTRANSAPI_SEARCHED_INTERFACES		(32)

typedef struct
{
	tTRANSAPI_LOCAL_CTX	TransLocalCtx;		/* MUST BE FIRST */

    int iReadSocket;
    int iWriteSocket;



} tTRANSAPI_LOCAL_SOCKET, *tPTRANSAPI_LOCAL_SOCKET;

/*--------------------------------------------------------------------------
	OctTransApiLocalOpen
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiLocalOpen( tPOCTTRANSAPI_LOCAL_OPEN_PARMS f_pParm, 
							   tOCTTRANSAPI_HANDLE *f_phTransport )
{
	int								iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tPTRANSAPI_LOCAL_SOCKET			pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;
    int                             sv[2];

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

    memset( pSocket, 0, sizeof( tTRANSAPI_LOCAL_SOCKET ) );

	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	TransApiLocalInitCtx( &pSocket->TransLocalCtx );

    if( socketpair( PF_LOCAL, SOCK_DGRAM, 0, sv ) >= 0 )
    {
        pSocket->iReadSocket	= sv[0];
        pSocket->iWriteSocket	= sv[1];

        pSocket->TransLocalCtx.TransCtx.hSelectable = (tTRANSAPI_SELECTABLE_HANDLE)(intptr_t)pSocket->iReadSocket;
        pTransInst->pTransApiCtx = (tTRANSAPI_CTX*)pSocket;
        *f_phTransport = pTransInst;
    }
    else
    {
        free ( pSocket );
        iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
    }
    mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        TransApiInstanceRelease( pTransInst );

	return iRc;
}
/*--------------------------------------------------------------------------
	TransApiLocalClose

----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiLocalClose( tTRANSAPI_CTX * f_pTransCtx )
{
    tPTRANSAPI_LOCAL_SOCKET		pSocket = (tPTRANSAPI_LOCAL_SOCKET)f_pTransCtx;
    if( f_pTransCtx->ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_LOCAL )
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

    if( pSocket->iWriteSocket )
        close( pSocket->iWriteSocket );
    pSocket->iWriteSocket = -1;
    if( pSocket->iReadSocket )
        close( pSocket->iReadSocket );
    pSocket->iReadSocket = -1;

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
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    iRc = TransApiLocalClose( (tTRANSAPI_CTX *)pTransInst->pTransApiCtx );

	pTransInst->pTransApiCtx = NULL;
    mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
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

    iRc = TransApiInstanceUsed(pTransInst);
    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        return iRc;

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
        TransApiInstanceUnused( pTransInst );
        return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


    iRc = send(	pSocket->iWriteSocket, f_pBuffer, f_ulBufferLength, 0 );
    if( iRc < 0)
        pSocket->TransLocalCtx.TransCtx.ulLastError = errno;

    TransApiInstanceUnused( pTransInst );

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
    int                             iRc = cOCTTRANSAPI_RC_ERROR_NONE;
    tPTRANSAPI_LOCAL_SOCKET			pSocket;
    tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pBuffer  ) ||
		( 0 == f_ulMaxBufferLength ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
    iRc = TransApiInstanceUsed(pTransInst);
    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        return iRc;

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
        TransApiInstanceUnused( pTransInst );
        return iRc;
    }

#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


    iRc = recv ( 	pSocket->iReadSocket,
                    f_pBuffer,
                    f_ulMaxBufferLength,
                    0 );
    if( iRc < 0)
    {
        pSocket->TransLocalCtx.TransCtx.ulLastError = errno;
        iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
    }

    TransApiInstanceUnused( pTransInst );

	return iRc;
}


/*--------------------------------------------------------------------------
	OctTransApiGetInterfaceIpAddress
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiGetInterfaceIpAddress( 	tOCT_UINT32	f_ulLocalInterfaceIndex,
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
    struct ifreq req[cTRANSAPI_SEARCHED_INTERFACES];
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
        if( uiIndex == f_ulLocalInterfaceIndex )
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

	for (iInterfaceIndex = 0; iInterfaceIndex < cTRANSAPI_SEARCHED_INTERFACES; iInterfaceIndex++)
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
				if( uiIndex == f_ulLocalInterfaceIndex )
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
#endif /* __linux__ */
