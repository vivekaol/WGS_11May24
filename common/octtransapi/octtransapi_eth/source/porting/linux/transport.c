#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: TRANSPORT.c

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
#ifdef OCTTRANSAPI_OPT_SELECT
#ifdef OCTTRANSAPI_OPT_POLL
#include <sys/poll.h>
#else
#include <sys/select.h>
#endif	/* OCTTRANSAPI_OPT_POLL */

#endif /* OCTTRANSAPI_OPT_SELECT */

#include <linux/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <linux/filter.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <sys/sysctl.h>
#include <linux/sysctl.h>

/* Porting interface */
#include "eth_util.h"
#include "../../../include/transapi_eth.h"
#include "../../../../octtransapi/include/transapi.h"

/*********************************  MACROS ************************************/
#ifndef mMAX
#define mMAX(x,y) ((x) > (y) ? (x) : (y))
#endif


/*******************************  STRUCTURE ***********************************/

typedef struct
{
	tTRANSAPI_ETH_CTX	TransEthCtx;		/* MUST BE FIRST */

	union
	{
		struct
		{
			int iReadSocket;
			int iWriteSocket;
			unsigned int ulPacketSent;
			unsigned int ulPacketRecv;
		} Loopback;

		struct
		{
			int sock;
			struct sockaddr_ll SocketLink;
			unsigned int ulTimeout;
            unsigned int sockFlags;
			unsigned int ulPacketSent;
			unsigned int ulPacketRecv;
		} Raw;

		int iSelectableSocket;

	} Data;

} tTRANSAPI_ETH_SOCKET, *tPTRANSAPI_ETH_SOCKET;

/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
    OctTransApiEthGetLocalMac
----------------------------------------------------------------------------*/
int OctTransApiEthGetLocalMac(
    void *				f_pTransportContext,
    unsigned			f_uiIndex,
    tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress )
{
    tOCTTRANS_ETH_IF_INFO EthInfo;
	EthInfo.pMacAddress = f_pMacAddress;
    return TransApiEthGetInterfaceInfoByIndex( f_uiIndex, &EthInfo );
}



/*--------------------------------------------------------------------------
    OctTransApiEthGetLocalMacByName
----------------------------------------------------------------------------*/
int OctTransApiEthGetLocalMacByName(
    void *					f_pTransportContext,
    tOCT_INT8				*f_pszInterfaceName,
    tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress )
{
	tOCTTRANS_ETH_IF_INFO EthInfo;

    if( f_pszInterfaceName == NULL )
        return cOCTTRANSAPI_RC_ERROR_PARAM;

	EthInfo.pMacAddress = f_pMacAddress;
    return TransApiEthGetInterfaceInfoByName( f_pszInterfaceName, &EthInfo);
}


/*--------------------------------------------------------------------------
	_TransApiEthOpen
----------------------------------------------------------------------------*/
static tOCT_INT32	_TransApiEthOpen( tOCTTRANSAPI_CONTEXT f_Context,
							   tPOCTTRANSAPI_ETH_OPEN f_pParm,
							   tOCT_INT8	*f_pszInterfaceName,
							   tOCTTRANSAPI_HANDLE *f_phTransport )
{
	tPTRANSAPI_ETH_SOCKET			pSocket;
    static unsigned long	l_ulMinRxBufferSize = 0;
    static unsigned long	l_lRxDefaultBufferSize = 0;
    tOCTTRANSAPI_RC_ERROR   transRc = cOCTTRANSAPI_RC_ERROR_NONE;
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = NULL;
	tOCTTRANS_ETH_IF_INFO	EthInfo;
	
#ifndef OCTTRANSAPI_OPT_SELECT
	/* Test for compiler options */
	if( f_pParm->fUseSelect )
        return cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;
#endif /* OCTTRANSAPI_OPT_SELECT */


    /* Test if transport is initialized */
    if( OctTransApiIsInit() != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT )
        return cOCTTRANSAPI_RC_ERROR_NOT_INIT;


    /* Make sure that the maximum receive buffer size is big enough */
    if( l_ulMinRxBufferSize < f_pParm->ulMinRxBufferSize  )
	{
        int lValue;
        tOCT_BOOL32 fUseSysCtl=cOCT_TRUE;

        FILE *pfileProcSysNet = fopen( "/proc/sys/net/core/rmem_max", "r");
        if( pfileProcSysNet )
        {
            if( fscanf( pfileProcSysNet, "%ld", &lValue ) == 1 )
            {
                if( lValue < (int)f_pParm->ulMinRxBufferSize )
                {
                    fclose( pfileProcSysNet );

                    pfileProcSysNet = fopen( "/proc/sys/net/core/rmem_max", "w");
                    if( pfileProcSysNet && ( fprintf( pfileProcSysNet, "%d", f_pParm->ulMinRxBufferSize ) > 0 ) )
                        fUseSysCtl=cOCT_FALSE;
                }
                else
                    fUseSysCtl=cOCT_FALSE;
            }
        }
        if( pfileProcSysNet )
            fclose( pfileProcSysNet );

        /* Test if have to use old way */
        if( fUseSysCtl )
        {

            int sysctl_args[] = { CTL_NET, NET_CORE,NET_CORE_RMEM_MAX };
            size_t iOptLen=sizeof( int );

            if (sysctl ( sysctl_args,
                          sizeof (sysctl_args) / sizeof (sysctl_args[0]),
                          (void *)&lValue, &iOptLen, (void *)NULL, 0) < 0)
                return cOCTTRANSAPI_RC_ERROR_PORTING;

            if( lValue < (int)f_pParm->ulMinRxBufferSize )
            {
                lValue = (int)f_pParm->ulMinRxBufferSize;
                iOptLen=sizeof( int );

                if (sysctl ( sysctl_args,
                          sizeof (sysctl_args) / sizeof (sysctl_args[0]),
                          (void *)NULL, 0, (void *)&lValue, iOptLen) < 0)
                    return cOCTTRANSAPI_RC_ERROR_PORTING;
            }

        }

        l_ulMinRxBufferSize = f_pParm->ulMinRxBufferSize;

	}


	if( l_lRxDefaultBufferSize == 0 )
	{
        tOCT_BOOL32 fUseSysCtl=cOCT_TRUE;

        FILE *pfileProcSysNet = fopen( "/proc/sys/net/core/rmem_default", "r");
        if( pfileProcSysNet )
        {
            if( fscanf( pfileProcSysNet, "%ld", &l_lRxDefaultBufferSize ) == 1 )
                fUseSysCtl=cOCT_FALSE;

            fclose( pfileProcSysNet );
        }

        /* Test if have to use old way */
        if( fUseSysCtl )
        {

            /* Read default buffer size */
            int sysctl_args[] = { CTL_NET, NET_CORE,NET_CORE_RMEM_DEFAULT };
            size_t iOptLen=sizeof( int );

            if (sysctl ( sysctl_args,
                          sizeof (sysctl_args) / sizeof (sysctl_args[0]),
                          (void *)&l_lRxDefaultBufferSize, &iOptLen, (void *)NULL, 0) < 0)
                return cOCTTRANSAPI_RC_ERROR_PORTING;
        }
	}


	/* Create socket */
    pSocket = (tPTRANSAPI_ETH_SOCKET)malloc( sizeof(*pSocket) +
                    ( f_pParm->ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX) ) +
                    ( f_pParm->ulMaxDestination * sizeof(tOCTDEV_MAC_ADDRESS) ) );
    if( NULL == pSocket )
        return cOCTTRANSAPI_RC_ERROR_MEMORY_ALLOC;

    if(( transRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
    {
        /* At this point, we no longer need the device list. Free it */
        free( pSocket );
        return transRc;
    }

    mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

    pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;
    memset( pSocket, 0, sizeof(*pSocket));

	pSocket->TransEthCtx.ulType = cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW;
	pSocket->TransEthCtx.usEtherType = f_pParm->usEtherType;

    TransApiEthInitCtx( &pSocket->TransEthCtx, sizeof(tTRANSAPI_ETH_SOCKET), f_pParm->ulMaxDestination);


	/* Create socket. */
	pSocket->Data.Raw.sock = socket(PF_PACKET, SOCK_RAW, htons( ETH_P_ALL ));
    if( pSocket->Data.Raw.sock < 0 )
    {
		if( errno == EPERM )
			transRc = cOCTTRANSAPI_RC_ERROR_OPEN_NO_PERMISSION;
		else
			transRc = cOCTTRANSAPI_RC_ERROR_PORTING;

        goto TransApiEthOpen_exitOnError;
	}
	else
	{		
		EthInfo.pMacAddress = &f_pParm->MacAddress;
		
        if( f_pszInterfaceName != NULL )
        {
            transRc = TransApiEthGetInterfaceInfoByName( f_pszInterfaceName, &EthInfo );
        }
        else
        {
            transRc = TransApiEthInterfaceInfoByMAC( &f_pParm->MacAddress, &EthInfo );
        }

		if(  transRc != cOCTTRANSAPI_RC_ERROR_NONE )
		    goto TransApiEthOpen_exitOnError;
	}

	f_pParm->ulInterfaceIndex = EthInfo.ulIF_EthIndex;
    memcpy( &pSocket->TransEthCtx.SrcMacAddr, &f_pParm->MacAddress, sizeof(pSocket->TransEthCtx.SrcMacAddr) );

	/* Get the socket flags. */
    pSocket->Data.Raw.sockFlags = fcntl( pSocket->Data.Raw.sock, F_GETFL, 0 );
    if ( pSocket->Data.Raw.sockFlags < 0 )
	{
        transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
        goto TransApiEthOpen_exitOnError;

	}

#ifdef OCTTRANSAPI_OPT_SELECT
	/* Set socket to non-blocking mode. */
	if( f_pParm->fUseSelect )
	{
        pSocket->Data.Raw.sockFlags |= O_NONBLOCK;
        if( fcntl( pSocket->Data.Raw.sock, F_SETFL, pSocket->Data.Raw.sockFlags ) < 0 )
		{
            transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
            goto TransApiEthOpen_exitOnError;
		}
        /* Select will reset this flag */
        pSocket->TransEthCtx.fSleepOnRecv=cOCT_TRUE;
		pSocket->Data.iSelectableSocket = pSocket->Data.Raw.sock;
        pSocket->TransEthCtx.TransCtx.hSelectable = (tTRANSAPI_SELECTABLE_HANDLE)(intptr_t)pSocket->Data.Raw.sock;
	}
#endif
	if( !f_pParm->fUseSelect )
	{
		/* Set blocking socket */
        pSocket->Data.Raw.sockFlags &= ~O_NONBLOCK;

        if ( fcntl( pSocket->Data.Raw.sock, F_SETFL, pSocket->Data.Raw.sockFlags ) < 0 )
		{
            transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
            goto TransApiEthOpen_exitOnError;
		}
        pSocket->TransEthCtx.fSleepOnRecv=cOCT_TRUE;
	}
	pSocket->TransEthCtx.fUseSelect = (unsigned int)f_pParm->fUseSelect;
    pSocket->Data.Raw.ulTimeout = 0xCAFEDECA;

	/* Prepare the link layer socket address structure */
	pSocket->Data.Raw.SocketLink.sll_family   = PF_PACKET;
	/* BRIDGE_PATCH 
	pSocket->Data.Raw.SocketLink.sll_protocol = htons( f_pParms->usEtherType ); */
	pSocket->Data.Raw.SocketLink.sll_protocol = htons( ETH_P_ALL );
	pSocket->Data.Raw.SocketLink.sll_ifindex  = (int)EthInfo.iIF_GlobalIndex;
	pSocket->Data.Raw.SocketLink.sll_hatype   = ARPHRD_ETHER;
	pSocket->Data.Raw.SocketLink.sll_pkttype  = PACKET_OTHERHOST;
	pSocket->Data.Raw.SocketLink.sll_halen    = ETH_ALEN;

	/* Bind the socket to the interface and the protocol */
	if ( bind(	pSocket->Data.Raw.sock, ( struct sockaddr * )&pSocket->Data.Raw.SocketLink, sizeof( pSocket->Data.Raw.SocketLink ) ) < 0)
	{
        transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
        goto TransApiEthOpen_exitOnError;
	}

	/* Chck if have to filter on Octasic PktHdr proto */
	/* BRIDGE_PATCH 
	if( (f_pParms->ulCtrlProtoType & ~cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK) == 0 ) */
	{

		if( f_pParm->ulCtrlProtoType != cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE )
		{
			static struct sock_filter aFilterProto[]= {
				BPF_STMT(BPF_LD+BPF_H+BPF_ABS,12), /* Ethertype */
				BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K,0x5200,0,4),
				BPF_STMT(BPF_LD+BPF_B+BPF_ABS,16), /* Octasic Proto */
				BPF_STMT(BPF_ALU+BPF_AND+BPF_K,0x78),
				BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K,0x0,0,1),
				BPF_STMT(BPF_RET+BPF_K,-1), /* Keep packet */
				BPF_STMT(BPF_RET+BPF_K,0), /* Drop packet */
			};
			static struct sock_fprog aProgram;
			aProgram.len=sizeof(aFilterProto)/sizeof(aFilterProto[0]);
			aProgram.filter = aFilterProto;

            aFilterProto[1].k = f_pParm->usEtherType;

            //if( f_pParm->usEtherType != cOCTPKT_HDRXL_ETHERTYPE )
			if( ! mIS_TRANSAPI_ETH_OCTPKT_HDRXL_ETHERTYPE( f_pParm->usEtherType ) )
                aFilterProto[4].k = (f_pParm->ulCtrlProtoType&0xF) << 3;
            else
            {
                aFilterProto[3].k = 0xF0;
                aFilterProto[4].k = (f_pParm->ulCtrlProtoType&0xF) << 4;
            }

			/* Apply the packet filter */
			if ( setsockopt(pSocket->Data.Raw.sock, SOL_SOCKET, SO_ATTACH_FILTER, &aProgram, sizeof(aProgram)) < 0)
			{
                transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
                goto TransApiEthOpen_exitOnError;
			}
		}
		else
		{
			static struct sock_filter aFilterNoProto[]= {
				BPF_STMT(BPF_LD+BPF_H+BPF_ABS,12), /* Ethertype */
				BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K,0x5200,0,1),
				BPF_STMT(BPF_RET+BPF_K,-1), /* Keep packet */
				BPF_STMT(BPF_RET+BPF_K,0), /* Drop packet */
			};
			static struct sock_fprog aProgram;
			aProgram.len=sizeof(aFilterNoProto)/sizeof(aFilterNoProto[0]);
			aProgram.filter = aFilterNoProto;

			aFilterNoProto[1].k = f_pParm->usEtherType;

			/* Apply the packet filter */
			if ( setsockopt(pSocket->Data.Raw.sock, SOL_SOCKET, SO_ATTACH_FILTER, &aProgram, sizeof(aProgram)) < 0)
			{
                transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
                goto TransApiEthOpen_exitOnError;
            }

		}
	}

	/* Set buffer size if need more than default */
	if( f_pParm->ulMinRxBufferSize > l_lRxDefaultBufferSize )
	{
		int iLen = f_pParm->ulMinRxBufferSize;

		if ( setsockopt(pSocket->Data.Raw.sock, SOL_SOCKET, SO_RCVBUF, &iLen, sizeof(int)) < 0)
		{
            transRc = cOCTTRANSAPI_RC_ERROR_PORTING;
            goto TransApiEthOpen_exitOnError;
        }
	}
    *f_phTransport = pTransInst;

    mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

    return cOCTTRANSAPI_RC_ERROR_NONE;

TransApiEthOpen_exitOnError:
    if( pSocket )
    {
        if(pSocket->Data.Raw.sock)
            close( pSocket->Data.Raw.sock );

        free( pSocket );
    }
    if( pTransInst )
    {
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
        TransApiInstanceRelease( pTransInst );
    }
    return transRc;

}


/*--------------------------------------------------------------------------
	OctTransApiEthOpen
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiEthOpen( tOCTTRANSAPI_CONTEXT f_Context,
							   tPOCTTRANSAPI_ETH_OPEN f_pParm, 
							   tOCTTRANSAPI_HANDLE *f_phTransport )
{
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( (NULL == f_pParm) || (NULL == f_phTransport) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	return _TransApiEthOpen( f_Context, f_pParm, NULL, f_phTransport );
}

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
									   tOCTTRANSAPI_HANDLE *f_phTransport )
{
	tOCT_INT32 iRc; 

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParm ) ||
		( NULL == f_pParm->pszInterfaceName ) ||
		( NULL == f_phTransport ))
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	iRc = _TransApiEthOpen( f_Context, &f_pParm->EthOpen, f_pParm->pszInterfaceName, f_phTransport );

	return iRc;
}


/*--------------------------------------------------------------------------
	OctTransApiEthGetPrimitiveHandle
----------------------------------------------------------------------------*/
int	OctTransApiEthGetPrimitiveHandle( tOCTTRANSAPI_HANDLE		f_hTransport )
{
    tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;
    tTRANSAPI_CTX *                 pTransCtx;
    tPTRANSAPI_ETH_SOCKET           pSocket;
    int								iRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( ( NULL == f_hTransport ) )
        return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
    iRc = TransApiInstanceUsed( pTransInst );
    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        return iRc;

    pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
        iRc = cOCTTRANSAPI_RC_ERROR_PARAM;

    if( iRc !=  cOCTTRANSAPI_RC_ERROR_NONE )
    {
        TransApiInstanceUnused( pTransInst );
        return iRc;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    pSocket = (tPTRANSAPI_ETH_SOCKET)pTransInst->pTransApiCtx;

	switch( pSocket->TransEthCtx.ulType )
	{
		case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
            iRc = pSocket->Data.Raw.sock;
			break;

		case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
            iRc = pSocket->Data.Loopback.iReadSocket;
            break;

        default:
            iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
            break;
	}

    TransApiInstanceUnused( pTransInst );

    return iRc;
}

/*--------------------------------------------------------------------------
    TransApiEthClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiEthClose( tTRANSAPI_CTX * f_pTransCtx )
{
    tPTRANSAPI_ETH_SOCKET pSocket = (tPTRANSAPI_ETH_SOCKET)f_pTransCtx;
    unsigned int i;

    /* Find if any used destination */
    for( i=0; i<f_pTransCtx->ulMaxDestination; i++ )
    {
        if( f_pTransCtx->apDestinationCtx[i].hTransport )
            return cOCTTRANSAPI_RC_ERROR_BUSY_DESTINATION;
    }

    switch( pSocket->TransEthCtx.ulType )
    {
        case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
            close( pSocket->Data.Raw.sock );
            pSocket->Data.Raw.sock = -1;
            break;
#ifdef OCTTRANSAPI_OPT_SELECT
        case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
            close( pSocket->Data.Loopback.iReadSocket );
            close( pSocket->Data.Loopback.iWriteSocket );
            pSocket->Data.Loopback.iReadSocket = -1;
            pSocket->Data.Loopback.iWriteSocket = -1;
            break;
#endif /* OCTTRANSAPI_OPT_SELECT */
        default :
            return cOCTTRANSAPI_RC_ERROR_PORTING;

    }
    pSocket->TransEthCtx.ulType = cTRANSAPI_ETH_SOCKET_TYPE_ENUM_INVALID;

    free( pSocket );

    return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	OctTransApiEthClose
----------------------------------------------------------------------------*/
int			OctTransApiEthClose( tOCTTRANSAPI_HANDLE f_hTransport )
{
    int                             iRc = 0;
    tTRANSAPI_CTX *                 pTransCtx;
    tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( pTransInst->ulMagicId != cTRANSAPI_MAGIC_ID )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    iRc = TransApiInstanceWaitUnused( pTransInst );
    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        return iRc;

    pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
        iRc = cOCTTRANSAPI_RC_ERROR_PARAM;

    if( iRc !=  cOCTTRANSAPI_RC_ERROR_NONE )
    {
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
        return iRc;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


    iRc = TransApiEthClose( pTransCtx );
    if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
    {
        pTransInst->pTransApiCtx = NULL;
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
        TransApiInstanceRelease( pTransInst );
    }
    else
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

    return iRc;

}



/*--------------------------------------------------------------------------
    TransApiEthSend
----------------------------------------------------------------------------*/
int			TransApiEthSend( tTRANSAPI_CTX *	f_pTransCtx,
                            void *				f_pBuffer,
                            unsigned int		f_ulBufferLength )
{
    tPTRANSAPI_ETH_SOCKET	pSocket = (tPTRANSAPI_ETH_SOCKET)f_pTransCtx;
    int iRc;

    switch( pSocket->TransEthCtx.ulType )
    {
        case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
            iRc = sendto (	pSocket->Data.Raw.sock,
                            f_pBuffer,
                            f_ulBufferLength,
                            0,
                            (struct sockaddr *)&pSocket->Data.Raw.SocketLink,
                            sizeof(pSocket->Data.Raw.SocketLink) );

#ifdef OCTTRANSAPI_OPT_SELECT
            if( iRc < 0 )
            {

                /* Test if socket would block */
                if( pSocket->TransEthCtx.fUseSelect &&
                    (( pSocket->Data.Raw.sockFlags & O_NONBLOCK ) == O_NONBLOCK ) &&
                    (( errno == EAGAIN ) || ( errno == EWOULDBLOCK )) )
                {
                    fd_set			sfds;
                    int 			nfds = 0;
                    int				iRcSel = 0;
                    /* Allow MAX 1ms to send previous packet */
                    struct timeval	tv = { 0, 1000 };
                    FD_ZERO(&sfds);
                    FD_SET(pSocket->Data.Raw.sock, &sfds);

                    nfds = pSocket->Data.Raw.sock;
                    iRcSel = select( nfds+1, NULL, &sfds, NULL, &tv );
                    if( iRcSel < 0)
                    {
                        pSocket->TransEthCtx.TransCtx.ulLastError = errno;
                        return cOCTTRANSAPI_RC_ERROR_PORTING;
                    }

                    if (FD_ISSET(pSocket->Data.Raw.sock, &sfds))
                    {
                        iRc = sendto (	pSocket->Data.Raw.sock,
                                        f_pBuffer,
                                        f_ulBufferLength,
                                        0,
                                        (struct sockaddr *)&pSocket->Data.Raw.SocketLink,
                                        sizeof(pSocket->Data.Raw.SocketLink) );
                        if(iRc<0)
                            pSocket->TransEthCtx.TransCtx.ulLastError = errno;
						else
							pSocket->Data.Raw.ulPacketSent++;
                    }
                }
                else
                    pSocket->TransEthCtx.TransCtx.ulLastError = errno;
            }
			else
				pSocket->Data.Raw.ulPacketSent++;


#endif /* OCTTRANSAPI_OPT_SELECT */
            break;
#ifdef OCTTRANSAPI_OPT_SELECT
        case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
            iRc = send (	pSocket->Data.Loopback.iWriteSocket,
                            f_pBuffer,
                            f_ulBufferLength,
                            0 );
            if( iRc < 0)
                pSocket->TransEthCtx.TransCtx.ulLastError = errno;
			else
				pSocket->Data.Loopback.ulPacketSent++;
            break;
#endif /* OCTTRANSAPI_OPT_SELECT */
        default								:
            iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
            break;
    }

    return iRc;
}

/*--------------------------------------------------------------------------
    OctTransApiEthSend
----------------------------------------------------------------------------*/
int			OctTransApiEthSend(
    tOCTTRANSAPI_HANDLE		f_hTransport,
    tOCTTRANSAPI_CONTEXT	f_RemoteContext,
    void *				f_pBuffer,
    unsigned int		f_ulBufferLength )
{
    int                             iRc = cOCTTRANSAPI_RC_ERROR_NONE;
    tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;
    tTRANSAPI_CTX *					pTransCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( ( NULL == f_hTransport ) )
        return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


    pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
    iRc = TransApiInstanceUsed(pTransInst);

    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        return iRc;

    pTransCtx = pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( ( pTransInst->pTransApiCtx == NULL ) )
        iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
    else if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
        iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
    else if( ( pTransCtx->ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH ) )
        iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
    {
        TransApiInstanceUnused( pTransInst );
        return iRc;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    iRc = TransApiEthSend( pTransInst->pTransApiCtx, f_pBuffer, f_ulBufferLength );

    TransApiInstanceUnused( pTransInst );

    return iRc;
}


/*--------------------------------------------------------------------------
	OctTransApiEthRecv
----------------------------------------------------------------------------*/
int			OctTransApiEthRecv(
	void *				f_hTransport,
	unsigned int		f_ulTimeoutMs,
	void *				f_pBuffer,
	unsigned int		f_ulMaxBufferLength )
{
    int                             iRc = cOCTTRANSAPI_RC_ERROR_NONE;
    tPTRANSAPI_ETH_SOCKET			pSocket;
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

    pSocket = (tPTRANSAPI_ETH_SOCKET)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( ( pTransInst->pTransApiCtx == NULL ) )
        iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
    else if( ( pSocket->TransEthCtx.TransCtx.ulMagicId != cTRANSAPI_MAGIC_ID ) )
        iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
    else if( ( pSocket->TransEthCtx.TransCtx.ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH ) )
        iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

    if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
    {
        TransApiInstanceUnused(pTransInst);
        return iRc;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	switch( pSocket->TransEthCtx.ulType )
	{
		case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
			{

                /* Adjust the timeout if different */
                if ( pSocket->TransEthCtx.fSleepOnRecv &&
                     (pSocket->Data.Raw.ulTimeout != f_ulTimeoutMs ))
                {
                    struct timeval timeout;

                    if( cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs )
                    {
                        timeout.tv_sec = 0xFFFFFFFF;
                        timeout.tv_usec = 0;
                    }
                    else if( 0 == f_ulTimeoutMs ) /* Can't be 0 */
                    {
                        timeout.tv_sec = 0;
                        timeout.tv_usec = 10;
                    }
                    else
                    {
                        timeout.tv_sec = f_ulTimeoutMs/1000;
                        timeout.tv_usec = f_ulTimeoutMs%1000;
                    }

                    setsockopt( pSocket->Data.Raw.sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout) );
                    pSocket->Data.Raw.ulTimeout = f_ulTimeoutMs;

                    /* Set socket blocking mode. if have to*/
                    if( pSocket->TransEthCtx.fUseSelect &&
                       ( ( pSocket->Data.Raw.sockFlags & O_NONBLOCK ) == O_NONBLOCK ) )
                    {
                        pSocket->Data.Raw.sockFlags &= ~O_NONBLOCK;

                        if ( fcntl( pSocket->Data.Raw.sock, F_SETFL, pSocket->Data.Raw.sockFlags ) < 0 )
                        {
                            iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
                            goto OctTransApiEthRecv_exitOnError;
                        }
                    }

                }

                while( iRc == 0 )
                {
					
                    iRc = recvfrom( pSocket->Data.Raw.sock,
								f_pBuffer,
								f_ulMaxBufferLength,
								0,
								NULL,
								NULL );

                    if( ( iRc < 0 ) && pSocket->TransEthCtx.fSleepOnRecv )
                    {
                        if(( errno == EAGAIN ) ||
                           ( errno == EWOULDBLOCK ) )
                            iRc =0;
                        else
                            iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
                    }
					else if( iRc )
						pSocket->Data.Raw.ulPacketRecv++;


                    if( cOCTTRANSAPI_TIMEOUT_FOREVER != f_ulTimeoutMs )
                        break;
                }

			}
			break;
		case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
			{
				iRc = recv ( 	pSocket->Data.Loopback.iReadSocket,
								f_pBuffer,
								f_ulMaxBufferLength,
								0 );
                if( iRc < 0 )
                    iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				else if( iRc )
					pSocket->Data.Loopback.ulPacketRecv++;

			}
			break;
	}

OctTransApiEthRecv_exitOnError:
    if( iRc < 0)
        pSocket->TransEthCtx.TransCtx.ulLastError = errno;

    TransApiInstanceUnused( pTransInst );

    return iRc;
}

/*--------------------------------------------------------------------------
OctTransApiEthStats

Return :		Ethernet stats

----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiEthStats( tOCTTRANSAPI_HANDLE f_hTransport, 
									    tPOCTTRANSAPI_ETH_STATS f_pParm )
{
	int                             iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tPTRANSAPI_ETH_SOCKET			pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pParm  ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	iRc = TransApiInstanceUsed(pTransInst);
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		return iRc;

	pSocket = (tPTRANSAPI_ETH_SOCKET)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransInst->pTransApiCtx == NULL ) )
		iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else if( ( pSocket->TransEthCtx.TransCtx.ulMagicId != cTRANSAPI_MAGIC_ID ) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	else if( ( pSocket->TransEthCtx.TransCtx.ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH ) )
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		TransApiInstanceUnused(pTransInst);
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	switch( pSocket->TransEthCtx.ulType )
	{
	default:
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
		break;

	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
		{
			unsigned int ulPktDrop=0;

#ifdef SO_RXQ_OVFL
			socklen_t iLen = sizeof(ulPktDrop);
			if( getsockopt( pSocket->Data.Raw.sock, SOL_SOCKET, SO_RXQ_OVFL, (char *)&ulPktDrop, &iLen ) > -1 )
#else
			if( !ulPktDrop )
#endif
			{
				f_pParm->ulPacketSent = pSocket->Data.Raw.ulPacketSent;
				f_pParm->ulPacketRecv = pSocket->Data.Raw.ulPacketRecv;
				f_pParm->ulPacketDrop = ulPktDrop;

			}
			else
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			}
			break;

#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
		f_pParm->ulPacketSent = pSocket->Data.Loopback.ulPacketSent;
		f_pParm->ulPacketRecv = pSocket->Data.Loopback.ulPacketRecv;
		f_pParm->ulPacketDrop = 0;
		break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	f_pParm->ulLastError =	pSocket->TransEthCtx.TransCtx.ulLastError;

	TransApiInstanceUnused( pTransInst );
	return iRc;
}




#ifdef OCTTRANSAPI_OPT_SELECT

/*--------------------------------------------------------------------------
	OctTransApiEthLoopbackOpen
----------------------------------------------------------------------------*/
int OctTransApiEthLoopbackOpen(
	void *				f_pTransportContext,
	void **				f_phTransport )
{
	int				sv[2];
    int                             iRc = cOCTTRANSAPI_RC_ERROR_NONE;
    tPTRANSAPI_ETH_SOCKET           pSocket;
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_phTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    /* Test if transport is initialized */
    if( OctTransApiIsInit() != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT )
        return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	pSocket = (tPTRANSAPI_ETH_SOCKET)malloc(sizeof(*pSocket));
	if( NULL == pSocket )
		return cOCTTRANSAPI_RC_ERROR_MEMORY_ALLOC;

    if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
    {
        free( pSocket );
        return iRc;
    }

    mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
	memset( pSocket, 0x0, sizeof(*pSocket) );

    /* Just do minimum init to allow run over ASSERT */
    TransApiEthInitCtx( &pSocket->TransEthCtx, 0, 0);

	pSocket->TransEthCtx.ulType = cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK;
    pSocket->TransEthCtx.fUseSelect = cOCT_TRUE;

    if( socketpair( PF_LOCAL, SOCK_DGRAM, 0, sv ) >= 0 )
	{
        pSocket->Data.Loopback.iReadSocket	= sv[0];
        pSocket->Data.Loopback.iWriteSocket	= sv[1];
        pSocket->Data.iSelectableSocket = pSocket->Data.Loopback.iReadSocket;

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
	OctTransApiEthSelect
----------------------------------------------------------------------------*/
int			OctTransApiEthSelect(
	void *				f_pTransportContext,
	unsigned int		f_ulTimeoutMs,
	unsigned int		f_ulTransportCnt,
	void *				f_ahTransport[],
	unsigned int		f_aulState[] )
{

	unsigned int	ulIndex;
	tPTRANSAPI_ETH_SOCKET	pSocket;
    int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifdef OCTTRANSAPI_OPT_POLL
	struct pollfd fds[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
#else
    int 			iSelectables[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
	int 			nfds = 0;
	fd_set			rfds;
	struct timeval	tv = { f_ulTimeoutMs / 1000, (f_ulTimeoutMs % 1000) * 1000 };
	FD_ZERO(&rfds);
#endif

	for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
	{
        tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;

        pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_ahTransport[ulIndex];
        if( NULL == pTransInst )
            return cOCTTRANSAPI_RC_ERROR_PARAM;

        mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
        pSocket = (tPTRANSAPI_ETH_SOCKET)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
        if( ( pTransInst->pTransApiCtx == NULL ) )
            iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
        else if( pSocket->TransEthCtx.TransCtx.ulMagicId != cTRANSAPI_MAGIC_ID  )
            iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
        else if( pSocket->TransEthCtx.TransCtx.ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH )
            iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

        if( !pSocket->TransEthCtx.fUseSelect )             /* test if should use select */
            iRc = cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;

        if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        {
            mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
            return iRc;
        }

        if( pSocket->TransEthCtx.ulType == cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW )
        {
            /* test if did recv before select */
            if( pSocket->TransEthCtx.fSleepOnRecv &&
               ( ( pSocket->Data.Raw.sockFlags & O_NONBLOCK ) != O_NONBLOCK ) )
            {
                pSocket->Data.Raw.sockFlags |= O_NONBLOCK;

                if ( fcntl( pSocket->Data.Raw.sock, F_SETFL, pSocket->Data.Raw.sockFlags ) < 0 )
                {
                    pSocket->TransEthCtx.TransCtx.ulLastError = errno;
                    mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
                    return cOCTTRANSAPI_RC_ERROR_PORTING;
                }
            }
            pSocket->TransEthCtx.fSleepOnRecv=cOCT_FALSE;
        }
		

#ifdef OCTTRANSAPI_OPT_POLL
		fds[ulIndex].fd		= pSocket->Data.iSelectableSocket;
		fds[ulIndex].events = POLLIN;
#else
		/* Set FD in preparation of select operation */
		FD_SET(pSocket->Data.iSelectableSocket, &rfds);
		nfds = mMAX(nfds, pSocket->Data.iSelectableSocket);
		iSelectables[ulIndex]=pSocket->Data.iSelectableSocket;
#endif
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

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
    if( iRc > 0 )
    {
        for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
        {
            f_aulState[ulIndex] =	FD_ISSET(iSelectables[ulIndex], &rfds) ?
                                        cOCTTRANSAPI_SELECT_STATE_RECV :
                                        cOCTTRANSAPI_SELECT_STATE_NONE ;
        }
    }
#endif

	return iRc;
}

/*--------------------------------------------------------------------------
	TransApiEthPreSelect
----------------------------------------------------------------------------*/
int	TransApiEthPreSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;
    tTRANSAPI_ETH_CTX *		pEthCtx = (tTRANSAPI_ETH_CTX*)pTransInst->pTransApiCtx;
    tPTRANSAPI_ETH_SOCKET	pSocket = (tPTRANSAPI_ETH_SOCKET)pEthCtx;

    /* NO need to lock */

    /* test if should use select */
    if( !pEthCtx->fUseSelect )
        return cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;

    /* test if did recv before select */
    if( pEthCtx->fSleepOnRecv &&
       ( ( pSocket->Data.Raw.sockFlags & O_NONBLOCK ) != O_NONBLOCK ) )
    {
        pSocket->Data.Raw.sockFlags |= O_NONBLOCK;

        if ( fcntl( pSocket->Data.Raw.sock, F_SETFL, pSocket->Data.Raw.sockFlags ) < 0 )
            return cOCTTRANSAPI_RC_ERROR_PORTING;
    }

    pEthCtx->fSleepOnRecv=cOCT_FALSE;

	return cOCTTRANSAPI_RC_ERROR_NONE;
}


#endif /* OCTTRANSAPI_OPT_SELECT */
#endif /* __linux__ */
