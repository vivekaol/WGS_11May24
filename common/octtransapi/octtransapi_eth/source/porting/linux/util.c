#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: UTIL.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: ETH linux porting transport

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
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>

#ifndef USE_SIOCGIFNAME
/* Avoid dependency on cTRANSAPI_ETH_SEARCHED_INTERFACES */
#include <net/if.h>
#include <net/if_arp.h>
#else
#include <linux/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <linux/filter.h>
#include <arpa/inet.h>
#include <sys/sysctl.h>
#include <linux/sysctl.h>

#ifndef cTRANSAPI_ETH_SEARCHED_INTERFACES
#define cTRANSAPI_ETH_SEARCHED_INTERFACES		(32)
#endif /* cTRANSAPI_ETH_SEARCHED_INTERFACES */

#endif

/* Porting interface */
#include "../../../include/transapi_eth.h"
#include "../../../../octtransapi/include/transapi.h"
#include "eth_util.h"
/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
    TransApiEthGetLocalMac
----------------------------------------------------------------------------*/
int TransApiEthGetInterfaceInfoByIndex( unsigned f_uiIndex, tOCTTRANS_ETH_IF_INFO *f_pEthIfInfo )
{
#ifndef USE_SIOCGIFNAME
    int				iRet=cOCTTRANSAPI_RC_ERROR_PORTING;
    int				sock;
    int             uiIndex=0;

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if ( sock < 0 )
    {
        if( errno == EPERM )
            return cOCTTRANSAPI_RC_ERROR_OPEN_NO_PERMISSION;

        return cOCTTRANSAPI_RC_ERROR_PORTING;
    }

    struct if_nameindex *pNameIndex = if_nameindex();
    if( pNameIndex )
    {
        struct if_nameindex *ifptr = pNameIndex;
        while(ifptr)
        {
            if( ifptr->if_name )
            {
                /* BRIDGE_PATCH
                Filter out ethernet bridges for compatibility reason ...
                New API OctTransApiEthGetLocalMacByName should be use */
                if( 0 != memcmp( ifptr->if_name, "br", 2 ) )
                {
                    struct ifreq ifr_adr;

                    strcpy(ifr_adr.ifr_name, ifptr->if_name);

                    /* Filter out non-ethernet interfaces */
                    ioctl(sock, SIOCGIFHWADDR, &ifr_adr);

                    if ( ARPHRD_ETHER == ifr_adr.ifr_hwaddr.sa_family )
                    {
                        if( uiIndex == f_uiIndex )
                        {
                            f_pEthIfInfo->pMacAddress->abyReserved[0] = 0;
                            f_pEthIfInfo->pMacAddress->abyReserved[1] = 0;
                            memcpy( f_pEthIfInfo->pMacAddress->abyMacAddress, ifr_adr.ifr_hwaddr.sa_data, 6 );
                            strcpy( (char *)f_pEthIfInfo->szName, ifptr->if_name );
							f_pEthIfInfo->iIF_GlobalIndex	= ifptr->if_index;
							f_pEthIfInfo->ulIF_EthIndex	= f_uiIndex;
							
                            iRet=cOCTTRANSAPI_RC_ERROR_NONE;
                            break;
                        }
                        uiIndex++;
                    }
                }
            }
            else
                break;

            ifptr++;
        }
        if_freenameindex( pNameIndex );
    }

	/* This socket is no longer needed */
	close( sock );

    return iRet;
#else
	struct ifreq	InterfaceRequest;
	int				iInterfaceIndex;
	int				iSocket;
	unsigned		uiIndex = 0;

	/* Create socket. */
	iSocket = socket(PF_PACKET, SOCK_RAW, htons( ETH_P_ALL ));
	if ( iSocket < 0 )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	for (iInterfaceIndex = 0; iInterfaceIndex < cTRANSAPI_ETH_SEARCHED_INTERFACES; iInterfaceIndex++)
	{
		/* Get the interface name as the Os uses it */
		InterfaceRequest.ifr_ifindex = iInterfaceIndex;

		if ( 0 == ioctl(iSocket, SIOCGIFNAME, &InterfaceRequest) )
		{
			/* BRIDGE_PATCH 
			Filter out ethernet bridges for compatibility reason ...
			New API OctTransApiEthGetLocalMacByName should be use */
			if( 0 != memcmp( InterfaceRequest.ifr_name, "br", 2 ) )
			{
				/* Filter out non-ethernet interfaces */
				ioctl(iSocket, SIOCGIFHWADDR, &InterfaceRequest);

				if ( ARPHRD_ETHER == InterfaceRequest.ifr_hwaddr.sa_family )
				{
					if( uiIndex == f_uiIndex )
					{
						
						f_pEthIfInfo->pMacAddress->abyReserved[0] = 0;
						f_pEthIfInfo->pMacAddress->abyReserved[1] = 0;
						memcpy( f_pEthIfInfo->pMacAddress->abyMacAddress, InterfaceRequest.ifr_hwaddr.sa_data, 6 );
						strcpy( (char *)f_pEthIfInfo->szName, InterfaceRequest.ifr_name );
						f_pEthIfInfo->iIF_GlobalIndex	= InterfaceRequest.if_index;
						f_pEthIfInfo->ulIF_EthIndex	= f_uiIndex;
						break;
					}
					uiIndex++;
				}
			}
		}
	}

	/* This socket is no longer needed */
	close( iSocket );

	/* Has the interface been found ? */
	if( cTRANSAPI_ETH_SEARCHED_INTERFACES == iInterfaceIndex )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}
	return cOCTTRANSAPI_RC_ERROR_NONE;
#endif
}

/*--------------------------------------------------------------------------
    TransApiEthGetInterfaceInfoByName
----------------------------------------------------------------------------*/
int TransApiEthGetInterfaceInfoByName(
	tOCT_INT8				*f_pszInterfaceName,
    tOCTTRANS_ETH_IF_INFO *f_pEthIfInfo )
{
#ifndef USE_SIOCGIFNAME
    int				iRet=cOCTTRANSAPI_RC_ERROR_PORTING;
    int				sock;
	unsigned		uiIndex = 0;

    if( f_pszInterfaceName == NULL )
        return cOCTTRANSAPI_RC_ERROR_PARAM;

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if ( sock < 0 )
    {
        if( errno == EPERM )
            return cOCTTRANSAPI_RC_ERROR_OPEN_NO_PERMISSION;

        return cOCTTRANSAPI_RC_ERROR_PORTING;
    }

    struct if_nameindex *pNameIndex = if_nameindex();
    if( pNameIndex )
    {
        struct if_nameindex *ifptr = pNameIndex;
        while(ifptr)
        {
            if( ifptr->if_name )
            {
				struct ifreq ifr_adr;

				strcpy(ifr_adr.ifr_name, ifptr->if_name);

				/* Filter out non-ethernet interfaces */
				ioctl(sock, SIOCGIFHWADDR, &ifr_adr);

				if ( ARPHRD_ETHER == ifr_adr.ifr_hwaddr.sa_family )
				{
					if( 0 == strcmp( ifptr->if_name, f_pszInterfaceName ) )
					{
						f_pEthIfInfo->pMacAddress->abyReserved[0] = 0;
						f_pEthIfInfo->pMacAddress->abyReserved[1] = 0;
						memcpy( f_pEthIfInfo->pMacAddress->abyMacAddress, ifr_adr.ifr_hwaddr.sa_data, 6 );
						strcpy( (char *)f_pEthIfInfo->szName, ifptr->if_name );
						f_pEthIfInfo->iIF_GlobalIndex	= ifptr->if_index;
						f_pEthIfInfo->ulIF_EthIndex	= uiIndex;
						iRet=cOCTTRANSAPI_RC_ERROR_NONE;

						break;
					}
				}
				uiIndex++;
            }
            else
                break;

            ifptr++;
        }
        if_freenameindex( pNameIndex );
    }

	/* This socket is no longer needed */
	close( sock );

	return iRet;
#else
	struct ifreq	InterfaceRequest;
	int				iInterfaceIndex;
	int				iSocket;
	unsigned		uiIndex = 0;
	
	if( f_pszInterfaceName == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	/* Create socket. */
	iSocket = socket(PF_PACKET, SOCK_RAW, htons( ETH_P_ALL ));
	if ( iSocket < 0 )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	for (iInterfaceIndex = 0; iInterfaceIndex < cTRANSAPI_ETH_SEARCHED_INTERFACES; iInterfaceIndex++)
	{
		/* Get the interface name as the Os uses it */
		InterfaceRequest.ifr_ifindex = iInterfaceIndex;

		if ( 0 == ioctl(iSocket, SIOCGIFNAME, &InterfaceRequest) )
		{
			/* Filter out non-ethernet interfaces */
			ioctl(iSocket, SIOCGIFHWADDR, &InterfaceRequest);

			if ( ARPHRD_ETHER == InterfaceRequest.ifr_hwaddr.sa_family )
			{
				if( 0 == strcmp( InterfaceRequest.ifr_name, f_pszInterfaceName ) )
				{
					f_pEthIfInfo->pMacAddress->abyReserved[0] = 0;
					f_pEthIfInfo->pMacAddress->abyReserved[1] = 0;
					memcpy( f_pEthIfInfo->pMacAddress->abyMacAddress, InterfaceRequest.ifr_hwaddr.sa_data, 6 );
					strcpy( (char *)f_pEthIfInfo->szName, InterfaceRequest.ifr_name );
					f_pEthIfInfo->iIF_GlobalIndex	= InterfaceRequest.if_index;
					f_pEthIfInfo->ulIF_EthIndex	= uiIndex;
					
					break;
				}
				uiIndex++;
			}
		}
	}

	/* This socket is no longer needed */
	close( iSocket );

	/* Has the interface been found ? */
	if( cTRANSAPI_ETH_SEARCHED_INTERFACES == iInterfaceIndex )
	{
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
#endif
}

/*--------------------------------------------------------------------------
    TransApiEthGetLocalMacIndex
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR TransApiEthInterfaceInfoByMAC(tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress, 
												tOCTTRANS_ETH_IF_INFO *f_pEthIfInfo )
{
#ifndef USE_SIOCGIFNAME
    int				iRet=cOCTTRANSAPI_RC_ERROR_PORTING;
    int				sock;
	unsigned		uiIndex = 0;
	
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if ( sock < 0 )
    {
        if( errno == EPERM )
            return cOCTTRANSAPI_RC_ERROR_OPEN_NO_PERMISSION;

        return cOCTTRANSAPI_RC_ERROR_PORTING;
    }

    struct if_nameindex *pNameIndex = if_nameindex();
    if( pNameIndex )
    {
        struct if_nameindex *ifptr = pNameIndex;
        while(ifptr)
        {
            if( ifptr->if_name )
            {
                /* BRIDGE_PATCH
                Filter out ethernet bridges for compatibility reason ...
                New API OctTransApiEthGetLocalMacByName should be use */
                if( 0 != memcmp( ifptr->if_name, "br", 2 ) )
                {
                    struct ifreq ifr_adr;

                    strcpy(ifr_adr.ifr_name, ifptr->if_name);

                    /* Filter out non-ethernet interfaces */
                    ioctl(sock, SIOCGIFHWADDR, &ifr_adr);

                    if ( ARPHRD_ETHER == ifr_adr.ifr_hwaddr.sa_family )
                    {
                        if( 0 == memcmp(f_pMacAddress->abyMacAddress, ifr_adr.ifr_hwaddr.sa_data, 6) )
                        {
							f_pEthIfInfo->pMacAddress->abyReserved[0] = 0;
							f_pEthIfInfo->pMacAddress->abyReserved[1] = 0;
							memcpy( f_pEthIfInfo->pMacAddress->abyMacAddress, ifr_adr.ifr_hwaddr.sa_data, 6 );
							strcpy( (char *)f_pEthIfInfo->szName, ifptr->if_name );
							f_pEthIfInfo->iIF_GlobalIndex	= ifptr->if_index;
							f_pEthIfInfo->ulIF_EthIndex	= uiIndex;
                            iRet=cOCTTRANSAPI_RC_ERROR_NONE;
                            break;
                        }
                    }
					uiIndex++;
                }
            }
            else
                break;


            ifptr++;
        }
        if_freenameindex( pNameIndex );
    }

	/* This socket is no longer needed */
	close( sock );

    return iRet;
#else
	struct ifreq	InterfaceRequest;
	int				iInterfaceIndex;
	int				iSocket;
	unsigned		uiIndex = 0;

	/* Create socket. */
	iSocket = socket(PF_PACKET, SOCK_RAW, htons( ETH_P_ALL ));
	if ( iSocket < 0 )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	for (iInterfaceIndex = 0; iInterfaceIndex < cTRANSAPI_ETH_SEARCHED_INTERFACES; iInterfaceIndex++)
	{
		/* Get the interface name as the Os uses it */
		InterfaceRequest.ifr_ifindex = iInterfaceIndex;

		if ( 0 == ioctl(iSocket, SIOCGIFNAME, &InterfaceRequest) )
		{
			/* BRIDGE_PATCH 
			Filter out ethernet bridges for compatibility reason ...
			New API OctTransApiEthGetLocalMacByName should be use */
			if( 0 != memcmp( InterfaceRequest.ifr_name, "br", 2 ) )
			{
				/* Filter out non-ethernet interfaces */
				ioctl(iSocket, SIOCGIFHWADDR, &InterfaceRequest);

				if ( ARPHRD_ETHER == InterfaceRequest.ifr_hwaddr.sa_family )
				{
                    if( 0 == memcmp(f_pMacAddress->abyMacAddress, InterfaceRequest.ifr_hwaddr.sa_data, 6) )
                    {
						f_pEthIfInfo->pMacAddress->abyReserved[0] = 0;
						f_pEthIfInfo->pMacAddress->abyReserved[1] = 0;
						memcpy( f_pEthIfInfo->pMacAddress->abyMacAddress, ifr_adr.ifr_hwaddr.sa_data, 6 );
						strcpy( (char *)f_pEthIfInfo->szName, InterfaceRequest.ifr_name );
						f_pEthIfInfo->iIF_GlobalIndex	= InterfaceRequest.if_index;
						f_pEthIfInfo->ulIF_EthIndex	= uiIndex;

                        iRet=cOCTTRANSAPI_RC_ERROR_NONE;
                        break;
                    }
					uiIndex++;
				}
			}
		}
	}
	/* This socket is no longer needed */
	close( iSocket );

	/* Has the interface been found ? */
	if( cTRANSAPI_ETH_SEARCHED_INTERFACES == iInterfaceIndex )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}
	return cOCTTRANSAPI_RC_ERROR_NONE;
#endif
}

#endif /* __linux__ */
