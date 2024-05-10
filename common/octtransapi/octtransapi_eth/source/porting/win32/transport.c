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
#define	HAVE_DESTINATION
#define	WPCAP

#include <stdio.h>

#include <winsock2.h>
#include <iphlpapi.h>
// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")

#include "pcap.h"
#include "packet32.h"
#include "ntddndis.h"

/* Porting interface */
#include "../../../../../../include/octpkt/octpkt_hdrxl.h"
#include "../../../include/transapi_eth.h"
#include "../../../../octtransapi/include/transapi.h"
#include "../../../../../octtransapi/include/octtransapi_default.h"

#pragma comment( lib, "packet.lib" )
#pragma comment( lib, "wpcap.lib" )

#include "transport_ext.h"
#include <winsock2.h>

#pragma comment( lib, "ws2_32.lib" )
#pragma comment( lib, "Winmm.lib" )


#ifdef OCT_ENV_MODE_DEBUG
#pragma comment( lib, "octtransapid.lib" )
#else
#pragma comment( lib, "octtransapi.lib" )
#endif /* OCT_ENV_MODE_DEBUG */

/*********************************  MACROS ************************************/

/*******************************  STRUCTURE ***********************************/
#define cPCAP_SLEEP_TIME						(1)


typedef struct
{
	tTRANSAPI_ETH_CTX	TransEthCtx;		/* MUST BE FIRST */

	HANDLE		hEvent;
	union
	{
		struct
		{
			unsigned int				ulPacketSent;
			unsigned int				ulPacketRecv;
			unsigned int				ulPacketDrop;

			HANDLE						hLock;				/* Protect ourself */
			int							iReadBlock;			/* Read block index */
			int							iWriteBlock;		/* Write block index */
			tTRANSAPI_ETH_SOCKET_LOOPBACK_MSG	aMsgBlock[cTRANSAPI_ETH_LOOPBACK_MSG_BLOCK_MAX+1];	
			/* Array of available message block */
		} Loopback;

		struct
		{
			unsigned int	ulPacketSent;
			unsigned int	ulPacketRecv;
			pcap_t *		pInstance;
		} Pcap;

	} Data;


} tTRANSAPI_ETH_SOCKET, *tPTRANSAPI_ETH_SOCKET;

/****************************  STATIC FUNCTION ********************************/


/*--------------------------------------------------------------------------
_TransApiEthInterfaceGetAddress
----------------------------------------------------------------------------*/
static int	_TransApiEthInterfaceGetAddress(
	char *				f_pszInterfaceName,
	unsigned char		f_abyInterfaceMacAddr[6] )
{
	int					iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	char *				pszTempName;
	LPADAPTER			lpAdapter;
	PPACKET_OID_DATA	OidData;

	/* Retrieve the adapter MAC querying the NIC driver	*/
	pszTempName = strstr(f_pszInterfaceName, "\\Device");

	lpAdapter =   PacketOpenAdapter( pszTempName );

	if (!lpAdapter || (lpAdapter->hFile == INVALID_HANDLE_VALUE))
		return cOCTTRANSAPI_RC_ERROR_PORTING;

	OidData = malloc( 6 + sizeof(PACKET_OID_DATA) );
	if (OidData == NULL) 
	{
		PacketCloseAdapter(lpAdapter);
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	OidData->Oid = OID_802_3_CURRENT_ADDRESS;
	OidData->Length = 6;
	ZeroMemory( OidData->Data, 6 );	
	if( PacketRequest( lpAdapter, FALSE, OidData ) )
	{
		memcpy( f_abyInterfaceMacAddr, OidData->Data, 6 );
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	}						

	PacketCloseAdapter(lpAdapter);
	free(OidData);

	return iRc;
}
/***************************  INTERNAL FUNCTION *******************************/

/****************************  USER INTERFACE *********************************/
/*--------------------------------------------------------------------------
_TransApiEthGetLocalMac
----------------------------------------------------------------------------*/
static tOCTTRANSAPI_RC_ERROR _TransApiEthGetLocalMac( 
	void *				f_Context,
	unsigned			f_uiIndex,
	tOCT_INT8			*f_pszInterfaceName,
	tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress )
{

	PIP_ADAPTER_ADDRESSES	pAlldevs;
	PIP_ADAPTER_ADDRESSES	pDeviceNavigator;
	ULONG					ulListBufferSize;
	unsigned				iIndex = 0;

	/*Get required buffer size for device info list*/
	GetAdaptersAddresses(AF_UNSPEC, 0, NULL, NULL, &ulListBufferSize);

	pAlldevs = (PIP_ADAPTER_ADDRESSES) malloc(ulListBufferSize);

	/* Retrieve the device list on the local machine */
	if (0 != GetAdaptersAddresses(AF_UNSPEC, 0, NULL, pAlldevs, &ulListBufferSize))
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	pDeviceNavigator = pAlldevs;

	while( NULL != pDeviceNavigator )
	{
		/* Found a valid device */
		char szTempName[60];
		wcstombs(szTempName,pDeviceNavigator->FriendlyName,sizeof(szTempName));
		/*  Selection base on interface index or interface name */
		/* In win32 .. we should considere index but for compatibility reason with other platform we test name. 
		The application will select by index when running in Windows */
		if( ( pDeviceNavigator->IfType == IF_TYPE_ETHERNET_CSMACD ) &&
			( ( (f_pszInterfaceName == NULL) && ( iIndex == f_uiIndex ) ) ||
			( f_pszInterfaceName != NULL ) && ( strcmp( f_pszInterfaceName, szTempName ) == 0 ) ) )
		{
			f_pMacAddress->abyReserved[0] = 0;
			f_pMacAddress->abyReserved[1] = 0;
			memcpy( f_pMacAddress->abyMacAddress, pDeviceNavigator->PhysicalAddress, 6 );
			break;		
		}
		/*	This is an Eth function, so 
			consider the provided index as an Eth index*/
		if( pDeviceNavigator->IfType == IF_TYPE_ETHERNET_CSMACD )
			iIndex++;

		pDeviceNavigator = pDeviceNavigator->Next;

	} 

	/* At this point, we no longer need the device list. Free it */
	free( pAlldevs );

	if( pDeviceNavigator == NULL )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
_TransApiEthGetInterfaceIndex
----------------------------------------------------------------------------*/
static tOCTTRANSAPI_RC_ERROR _TransApiEthGetInterfaceIndex( 
	void *				f_Context,
	unsigned			*f_puiIndex,
	tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress )
{

	PIP_ADAPTER_ADDRESSES	pAlldevs;
	PIP_ADAPTER_ADDRESSES	pDeviceNavigator;
	ULONG					ulListBufferSize;
	unsigned				iIndex = 0;

	/*Get required buffer size for device info list*/
	GetAdaptersAddresses(AF_UNSPEC, 0, NULL, NULL, &ulListBufferSize);

	pAlldevs = (PIP_ADAPTER_ADDRESSES) malloc(ulListBufferSize);

	/* Retrieve the device list on the local machine */
	if (0 != GetAdaptersAddresses(AF_UNSPEC, 0, NULL, pAlldevs, &ulListBufferSize))
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	pDeviceNavigator = pAlldevs;

	while( NULL != pDeviceNavigator )
	{
		/* Found a valid device */
		char szTempName[60];
		wcstombs(szTempName,pDeviceNavigator->FriendlyName,sizeof(szTempName));
		/*  Selection base on interface index or interface name */
		/* In win32 .. we should considere index but for compatibility reason with other platform we test name. 
		The application will select by index when running in Windows */
		if( pDeviceNavigator->IfType == IF_TYPE_ETHERNET_CSMACD ) 
		{
			if( memcmp( f_pMacAddress->abyMacAddress, pDeviceNavigator->PhysicalAddress, 6 ) == 0 )
				break;		

			iIndex++;
		}

		pDeviceNavigator = pDeviceNavigator->Next;

	} 

	/* At this point, we no longer need the device list. Free it */
	free( pAlldevs );

	if( pDeviceNavigator == NULL )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	*f_puiIndex = iIndex;
	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
OctTransApiEthGetLocalMac
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiEthGetLocalMac( 
	void *				f_Context,
	unsigned			f_uiIndex,
	tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress )
{
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( NULL == f_pMacAddress )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	return _TransApiEthGetLocalMac( f_Context, f_uiIndex, NULL, f_pMacAddress );
}
/*--------------------------------------------------------------------------
OctTransApiEthGetLocalMacByName
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiEthGetLocalMacByName( tOCTTRANSAPI_CONTEXT f_Context,
														tOCT_INT8		*f_pszInterfaceName, 
														tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress )
{

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pMacAddress ) ||
		( NULL == f_pszInterfaceName ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	return _TransApiEthGetLocalMac( f_Context, 0, f_pszInterfaceName, f_pMacAddress );
}


/*--------------------------------------------------------------------------
_TransApiEthOpen
----------------------------------------------------------------------------*/
static tOCTTRANSAPI_RC_ERROR	_TransApiEthOpen( tOCTTRANSAPI_CONTEXT f_Context,
												 tPOCTTRANSAPI_ETH_OPEN f_pParm,
												 tOCT_INT8	*f_pszInterfaceName,
												 tOCTTRANSAPI_HANDLE *f_phTransport )

{
	int						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
	tPTRANSAPI_ETH_SOCKET	pSocket;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = NULL;

	char				szErrbuf[PCAP_ERRBUF_SIZE];
	pcap_if_t*			pAlldevs;
	pcap_if_t*			pDeviceNavigator;
	char				szFilterExpr[PCAP_ERRBUF_SIZE];
	struct bpf_program	fcode;

	/* Test if transport is initialized */
	if( OctTransApiIsInit() != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	/* Retrieve the device list on the local machine */
	if ( -1 == pcap_findalldevs(	
		&pAlldevs, 
		szErrbuf) )
	{
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

#ifndef OCTTRANSAPI_OPT_SELECT
	/* Test for compiler options */
	if( f_pParm->fUseSelect )
		return cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;
#endif /* OCTTRANSAPI_OPT_SELECT */

	/* If it's an OpenByName, get the required MAC first*/
	if( f_pszInterfaceName != NULL )
	{
		if(0 != _TransApiEthGetLocalMac( f_Context, 0, f_pszInterfaceName, &f_pParm->MacAddress ) )
		{
			return cOCTTRANSAPI_RC_ERROR_PORTING;
		}
	}
	pDeviceNavigator = pAlldevs;

	while( NULL != pDeviceNavigator )
	{
		/* Found a valid device */
		unsigned char		abyInterfaceMacAddr[6];

		if( 0 == _TransApiEthInterfaceGetAddress( pDeviceNavigator->name, abyInterfaceMacAddr ) )
		{
			/* Verify if this is the desired Mac Address */
			if(  0 == memcmp( f_pParm->MacAddress.abyMacAddress, abyInterfaceMacAddr, 6) )
			{
				break;
			}
		}
		pDeviceNavigator = pDeviceNavigator->next;
	} 

	if( pDeviceNavigator == NULL )
	{
		pcap_freealldevs( pAlldevs );
		return cOCTTRANSAPI_RC_ERROR_PORTING;
	}

	_TransApiEthGetInterfaceIndex( f_Context, &f_pParm->ulInterfaceIndex, &f_pParm->MacAddress );

	/* Find local interface, create socket */
	pSocket = (tPTRANSAPI_ETH_SOCKET)malloc( sizeof(*pSocket) + 
		( f_pParm->ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX) ) + 
		( f_pParm->ulMaxDestination * sizeof(tOCTDEV_MAC_ADDRESS) ) );
	if( NULL == pSocket )
	{
		pcap_freealldevs( pAlldevs );
		return cOCTTRANSAPI_RC_ERROR_MEMORY_ALLOC;
	}

	if(( iRc = TransApiInstanceSeize( &pTransInst ) ) != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		/* At this point, we no longer need the device list. Free it */
		pcap_freealldevs( pAlldevs );
		free( pSocket );
		return iRc;
	}
	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	pTransInst->pTransApiCtx = ( tTRANSAPI_CTX *) pSocket;

	memset( pSocket, 0, sizeof( tTRANSAPI_ETH_SOCKET ) );

	pSocket->TransEthCtx.ulType = cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW;
	pSocket->TransEthCtx.usEtherType = f_pParm->usEtherType;

	TransApiEthInitCtx( &pSocket->TransEthCtx, sizeof(tTRANSAPI_ETH_SOCKET), f_pParm->ulMaxDestination);

	memcpy( &pSocket->TransEthCtx.SrcMacAddr, &f_pParm->MacAddress, sizeof(pSocket->TransEthCtx.SrcMacAddr) );

	/* From now on, default is failure */
	iRc = -1;
	/* Open the output adapter */
	pSocket->Data.Pcap.pInstance = pcap_open_live(
		pDeviceNavigator->name,		/* Interface name */
		65536,						/* length of the packet that has to be retained */
		TRUE,						/* promiscuous mode */
		cPCAP_SLEEP_TIME,			/* timeout before reading .. calc timeout outside pcap */
		szErrbuf);
	if ( NULL != pSocket->Data.Pcap.pInstance )
	{
		char *	pszFilter = NULL;

		/* Prepare filter */
		if ( NULL == f_pParm->pLocalContext )
		{
			if ( f_pParm->usEtherType )
			{
				if( ( f_pParm->ulCtrlProtoType == cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE ) ||
					( (f_pParm->ulCtrlProtoType & ~cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK) != 0 ) )
				{
					/* do not receive our broadcast */
					sprintf(szFilterExpr, "(ether dst host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX or ((ether dst host FF:FF:FF:FF:FF:FF) and not(ether src host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX)) ) and ether proto 0x%04x", 
						f_pParm->MacAddress.abyMacAddress[0], 
						f_pParm->MacAddress.abyMacAddress[1], 
						f_pParm->MacAddress.abyMacAddress[2], 
						f_pParm->MacAddress.abyMacAddress[3], 
						f_pParm->MacAddress.abyMacAddress[4], 
						f_pParm->MacAddress.abyMacAddress[5],
						f_pParm->MacAddress.abyMacAddress[0], 
						f_pParm->MacAddress.abyMacAddress[1], 
						f_pParm->MacAddress.abyMacAddress[2], 
						f_pParm->MacAddress.abyMacAddress[3], 
						f_pParm->MacAddress.abyMacAddress[4], 
						f_pParm->MacAddress.abyMacAddress[5],
						f_pParm->usEtherType );
				}
				else
				{
					//if( f_pParm->usEtherType != cOCTPKT_HDRXL_ETHERTYPE )
					if( ! mIS_TRANSAPI_ETH_OCTPKT_HDRXL_ETHERTYPE( f_pParm->usEtherType ) )
					{
						/* Added filter on cOCTPKT_HDRXL_CONTROL_PROTOCOL_TYPE_ENUM_ */
						sprintf(szFilterExpr, "(ether dst host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX or ((ether dst host FF:FF:FF:FF:FF:FF) and not(ether src host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX))) and ether proto 0x%04x and (ether[16] & 0x78 == 0x%x)",
							f_pParm->MacAddress.abyMacAddress[0], 
							f_pParm->MacAddress.abyMacAddress[1], 
							f_pParm->MacAddress.abyMacAddress[2], 
							f_pParm->MacAddress.abyMacAddress[3], 
							f_pParm->MacAddress.abyMacAddress[4], 
							f_pParm->MacAddress.abyMacAddress[5],
							f_pParm->MacAddress.abyMacAddress[0], 
							f_pParm->MacAddress.abyMacAddress[1], 
							f_pParm->MacAddress.abyMacAddress[2], 
							f_pParm->MacAddress.abyMacAddress[3], 
							f_pParm->MacAddress.abyMacAddress[4], 
							f_pParm->MacAddress.abyMacAddress[5],
							f_pParm->usEtherType,
							((f_pParm->ulCtrlProtoType&0xf) << 3) );
					}
					else
					{
						/* Added filter on cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_ */
						sprintf(szFilterExpr, "(ether dst host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX or ((ether dst host FF:FF:FF:FF:FF:FF ) and not(ether src host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX)) ) and ether proto 0x%04x and (ether[16] & 0xf0 == 0x%x)",
							f_pParm->MacAddress.abyMacAddress[0], 
							f_pParm->MacAddress.abyMacAddress[1], 
							f_pParm->MacAddress.abyMacAddress[2], 
							f_pParm->MacAddress.abyMacAddress[3], 
							f_pParm->MacAddress.abyMacAddress[4], 
							f_pParm->MacAddress.abyMacAddress[5],
							f_pParm->MacAddress.abyMacAddress[0], 
							f_pParm->MacAddress.abyMacAddress[1], 
							f_pParm->MacAddress.abyMacAddress[2], 
							f_pParm->MacAddress.abyMacAddress[3], 
							f_pParm->MacAddress.abyMacAddress[4], 
							f_pParm->MacAddress.abyMacAddress[5],
							f_pParm->usEtherType,
							((f_pParm->ulCtrlProtoType&0xf) << 4));
					}
				}
			}
			else
			{
				sprintf(szFilterExpr, "(ether dst host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX or ((ether dst host FF:FF:FF:FF:FF:FF) and not(ether src host %02lX:%02lX:%02lX:%02lX:%02lX:%02lX)) )", 
					f_pParm->MacAddress.abyMacAddress[0], 
					f_pParm->MacAddress.abyMacAddress[1], 
					f_pParm->MacAddress.abyMacAddress[2], 
					f_pParm->MacAddress.abyMacAddress[3], 
					f_pParm->MacAddress.abyMacAddress[4], 
					f_pParm->MacAddress.abyMacAddress[5],
					f_pParm->MacAddress.abyMacAddress[0], 
					f_pParm->MacAddress.abyMacAddress[1], 
					f_pParm->MacAddress.abyMacAddress[2], 
					f_pParm->MacAddress.abyMacAddress[3], 
					f_pParm->MacAddress.abyMacAddress[4], 
					f_pParm->MacAddress.abyMacAddress[5] );
			}

			pszFilter = szFilterExpr;
		}
		else
		{
			tPOCTTRANSAPI_ETH_CONTEXT_PCAP_ENDPOINT	pContextPcap = (tPOCTTRANSAPI_ETH_CONTEXT_PCAP_ENDPOINT)f_pParm->pLocalContext;
			pszFilter = pContextPcap->pszFilter;
		}

		/* Compile capture filter */
		iRc = pcap_compile( pSocket->Data.Pcap.pInstance, &fcode, pszFilter, TRUE, 0 );

		if( 0 == iRc )
		{
			/* set the filter (exception is the loopback adapter, else it doesn't work...) */
			if( strcmp(pDeviceNavigator->description, "MS LoopBack Driver") )
			{
				iRc = pcap_setfilter( pSocket->Data.Pcap.pInstance, &fcode );
			}

			pcap_freecode( &fcode );
			if( 0 == iRc )
			{
				if( f_pParm->ulMinRxBufferSize )
				{
					SYSTEM_INFO sysinfo;
					tOCT_INT32 size;

					GetSystemInfo( &sysinfo );

					/* default kernel buffer is 1M
					Implementation in kernel is strange for 4.1.0.2001
					buffer size is divided by number of cpu... does not allow to handle burst of 500K sec
					We patch it this way; */
					if( sysinfo.dwNumberOfProcessors )
						size = ( f_pParm->ulMinRxBufferSize * sysinfo.dwNumberOfProcessors );
					else
						size = f_pParm->ulMinRxBufferSize;

					if( pcap_setbuff( pSocket->Data.Pcap.pInstance, size ) < 0 )
						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
				}

				if( 0 == iRc )
				{
#ifdef OCTTRANSAPI_OPT_SELECT
					if( f_pParm->fUseSelect )
					{
						pSocket->hEvent = pcap_getevent( pSocket->Data.Pcap.pInstance );
						pcap_setnonblock( pSocket->Data.Pcap.pInstance, 1, szErrbuf );
						pcap_setmintocopy( pSocket->Data.Pcap.pInstance, 1 );
						/* Sleep is done until select is called */
						pSocket->TransEthCtx.fSleepOnRecv = cOCT_TRUE;

						pSocket->TransEthCtx.TransCtx.hSelectable = pSocket->hEvent;
					}
#endif /* OCTTRANSAPI_OPT_SELECT */
					if( !f_pParm->fUseSelect )
					{
						pcap_setnonblock( pSocket->Data.Pcap.pInstance, 0, szErrbuf );
						/* Sleep is done in Pcap */
						pSocket->TransEthCtx.fSleepOnRecv = cOCT_FALSE;
					}
					pSocket->TransEthCtx.fUseSelect = f_pParm->fUseSelect;

				}
			}
		}	
	}

	/* At this point, we no longer need the device list. Free it */
	pcap_freealldevs( pAlldevs );

	if ( cOCTTRANSAPI_RC_ERROR_NONE != iRc )
	{
		iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
		if ( NULL != pSocket )
		{
			TransApiEthClose( &pSocket->TransEthCtx.TransCtx );
		}
	}
	else
	{
		*f_phTransport = pTransInst;
	}

	OctOsalMutexRelease( pTransInst->hMutex );
	return iRc;
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
tOCTTRANSAPI_RC_ERROR	OctTransApiEthOpenByName( tOCTTRANSAPI_CONTEXT f_Context, 
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

	/* Use intermediare struct for backward compatibility reason */
	*f_phTransport = tOCTTRANSAPI_HANDLE_INVALID;
	iRc = _TransApiEthOpen( f_Context, &f_pParm->EthOpen, f_pParm->pszInterfaceName, f_phTransport );

	return iRc;
}

/*--------------------------------------------------------------------------
OctTransApiEthOpen
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiEthOpen( tOCTTRANSAPI_CONTEXT f_Context,
										   tPOCTTRANSAPI_ETH_OPEN f_pParm, 
										   tOCTTRANSAPI_HANDLE *f_phTransport )
{

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParm ) ||
		( NULL == f_phTransport ))
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	*f_phTransport = tOCTTRANSAPI_HANDLE_INVALID;
	return _TransApiEthOpen( f_Context, f_pParm, NULL, f_phTransport );
}

/*--------------------------------------------------------------------------
TransApiEthClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiEthClose( tTRANSAPI_CTX * f_pTransCtx )
{
	tPTRANSAPI_ETH_SOCKET pSocket = (tPTRANSAPI_ETH_SOCKET)f_pTransCtx;
	unsigned int i;

	if( ( f_pTransCtx->ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH ) )
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

	/* Find if any used destination */
	for( i=0; i<f_pTransCtx->ulMaxDestination; i++ )
	{
		if( f_pTransCtx->apDestinationCtx[i].hTransport )
			return cOCTTRANSAPI_RC_ERROR_BUSY_DESTINATION;
	}

	switch(  pSocket->TransEthCtx.ulType )
	{
	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
		if(  pSocket->Data.Pcap.pInstance )
			pcap_close( pSocket->Data.Pcap.pInstance );
		pSocket->Data.Pcap.pInstance = NULL;
		pSocket->hEvent = NULL;
		break;
#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
		if( pSocket->hEvent )
			CloseHandle( pSocket->hEvent );
		pSocket->hEvent = NULL;
		if( pSocket->Data.Loopback.hLock )
			CloseHandle( pSocket->Data.Loopback.hLock );
		pSocket->Data.Loopback.hLock = NULL;
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
tOCTTRANSAPI_RC_ERROR	OctTransApiEthClose( tOCTTRANSAPI_HANDLE	f_hTransport )
{
	int								iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;
	tTRANSAPI_CTX *					pTransCtx;

	/* Always test on close */
	if( ( NULL == f_hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

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
		OctOsalMutexRelease( pTransInst->hMutex );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	iRc = TransApiEthClose( pTransCtx );
	if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		pTransInst->pTransApiCtx = NULL;
		OctOsalMutexRelease( pTransInst->hMutex );
		TransApiInstanceRelease( pTransInst );
	}
	else
		OctOsalMutexRelease( pTransInst->hMutex );

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
	default:
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
		break;

	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
		iRc = pcap_sendpacket(
			pSocket->Data.Pcap.pInstance, 
			f_pBuffer, 
			f_ulBufferLength);
		if ( 0 == iRc )
		{
			pSocket->Data.Pcap.ulPacketSent++;
			iRc = f_ulBufferLength;
		}
		break;
#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
		if ( WAIT_OBJECT_0 == WaitForSingleObject( 
			pSocket->Data.Loopback.hLock, 
			INFINITE ) )
		{
			int	iNextWrite;
			/* Calculate next write index */
			iNextWrite = pSocket->Data.Loopback.iWriteBlock;
			iNextWrite++;
			if ( iNextWrite > cTRANSAPI_ETH_LOOPBACK_MSG_BLOCK_MAX )
			{
				iNextWrite = 0;
				pSocket->Data.Loopback.ulPacketDrop++;
			}

			/* Room to store a new one ? */
			if ( pSocket->Data.Loopback.iReadBlock != iNextWrite )
			{
				memcpy( pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].abyBuffer,f_pBuffer,
					mMIN( cTRANSAPI_ETH_LOOPBACK_MSG_SIZE_MAX, f_ulBufferLength ) );
				pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].ulSize 
					= mMIN( cTRANSAPI_ETH_LOOPBACK_MSG_SIZE_MAX, f_ulBufferLength );
				iRc = pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iWriteBlock].ulSize;
				pSocket->Data.Loopback.iWriteBlock = iNextWrite;

				pSocket->Data.Loopback.ulPacketSent++;
			}
			else
			{
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
			}
			ReleaseSemaphore( pSocket->Data.Loopback.hLock, 1, NULL );
			/* Signal a new msg in Q */
			SetEvent( pSocket->hEvent );
		}
		else
		{
			iRc = cOCTTRANSAPI_RC_ERROR_NONE;
		}
		break;
#endif /* OCTTRANSAPI_OPT_SELECT */

	}

	if( iRc < 0)
		pSocket->TransEthCtx.TransCtx.ulLastError = WSAGetLastError();

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
	int						iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;
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
TransApiEthCalcElapsedTimeMs
Calculate elapsed time between start time and current
----------------------------------------------------------------------------*/
unsigned int TransApiEthCalcElapsedTimeMs(
	DWORD		f_dwCurrentTimeMs,
	DWORD		f_dwStartTimeMs )
{
	unsigned int		ulElapsedMs;

	if ( f_dwCurrentTimeMs >= f_dwStartTimeMs )
	{
		ulElapsedMs = (unsigned int)(f_dwCurrentTimeMs - f_dwStartTimeMs);
	}
	else
	{
		ulElapsedMs = 0xFFFFFFFF - f_dwStartTimeMs;
		ulElapsedMs += (unsigned int)f_dwCurrentTimeMs;
	}
	return ulElapsedMs;
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
			struct pcap_stat	pcapStats;
			if( pcap_stats(pSocket->Data.Pcap.pInstance, &pcapStats) == 0)
			{
				
				f_pParm->ulPacketSent = pSocket->Data.Pcap.ulPacketSent;
				f_pParm->ulPacketRecv = pSocket->Data.Pcap.ulPacketRecv;
				f_pParm->ulPacketDrop = pcapStats.ps_drop;
				// NOT IMPLEMENTED f_pParm->ulPacketDropIf = pcapStats.ps_ifdrop;

			}
			else
				iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
		}
		break;

#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
		f_pParm->ulPacketSent = pSocket->Data.Loopback.ulPacketSent;
		f_pParm->ulPacketRecv = pSocket->Data.Loopback.ulPacketRecv;
		f_pParm->ulPacketDrop = pSocket->Data.Loopback.ulPacketDrop;

		break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	f_pParm->ulLastError =	pSocket->TransEthCtx.TransCtx.ulLastError;

	TransApiInstanceUnused( pTransInst );
	return iRc;
}


/*--------------------------------------------------------------------------
OctTransApiEthRecv

Return :		Size of the received buffer in bytes.
0 means no data,
Negative value means error.

----------------------------------------------------------------------------*/
int		OctTransApiEthRecv(
							   tOCTTRANSAPI_HANDLE		f_hTransport,
							   unsigned int			f_ulTimeoutMs,
							   void *					f_pBuffer,
							   unsigned int			f_ulMaxBufferLength )
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
	default:
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
		break;

	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		:
		{
			struct pcap_pkthdr *	pPktHeader;
			unsigned char*			pRecBuf;
			DWORD					dwTimeStart;
			unsigned int			ulTimeoutMs = f_ulTimeoutMs;
			unsigned int			ulTimeElapsed;
			char					szErrBuf[PCAP_ERRBUF_SIZE];

			dwTimeStart = timeGetTime();

			/* Set pcap to non blocking if requested timeout is zero*/
			iRc =  pcap_setnonblock(
				pSocket->Data.Pcap.pInstance,
				f_ulTimeoutMs == 0,
				szErrBuf );

			do
			{
				iRc = pcap_next_ex( 
					pSocket->Data.Pcap.pInstance, 
					&pPktHeader, 
					&pRecBuf );

				if ( 1 == iRc )
				{
					memcpy( f_pBuffer, pRecBuf, mMIN( pPktHeader->len, f_ulMaxBufferLength) );
					iRc = pPktHeader->len;

					pSocket->Data.Pcap.ulPacketRecv++;

					/* Patch for PCAP not signaling on a packet basis:
					Signal again the sync event */
					if( pSocket->TransEthCtx.fUseSelect )
						SetEvent( pSocket->hEvent );

				}
				else
				{
					if ( 0 == iRc )
					{

						/* Timeout ...
						When used with select .. the socket is set none blocking. 
						When use without select .. socket is set for blocking
						timeout is wait before reading to allow min number of packet to be received
						and we calc wait timeout base on l_ulTimerResolution */
						if( ulTimeoutMs )
						{
							ulTimeElapsed = TransApiEthCalcElapsedTimeMs( timeGetTime(),dwTimeStart );
							ulTimeoutMs = (f_ulTimeoutMs > ulTimeElapsed) ? (f_ulTimeoutMs - ulTimeElapsed) : 0;

							if ( ulTimeoutMs && pSocket->TransEthCtx.fSleepOnRecv )
								Sleep( cPCAP_SLEEP_TIME );
						}
					}
					else
					{
						/* Error */
						pSocket->TransEthCtx.TransCtx.ulLastError = iRc;
						iRc = cOCTTRANSAPI_RC_ERROR_PORTING;
					}
				}

			} while ( iRc <= 0 && ulTimeoutMs );
		}
		break;
#ifdef OCTTRANSAPI_OPT_SELECT
	case cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	:
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

				pSocket->Data.Loopback.ulPacketRecv++;

				pSocket->Data.Loopback.aMsgBlock[pSocket->Data.Loopback.iReadBlock].ulSize = 0;
				pSocket->Data.Loopback.iReadBlock++;
				if ( pSocket->Data.Loopback.iReadBlock > cTRANSAPI_ETH_LOOPBACK_MSG_BLOCK_MAX )
				{
					pSocket->Data.Loopback.iReadBlock = 0;
				}
			}
			ReleaseSemaphore( pSocket->Data.Loopback.hLock, 1, NULL );

		}
		else
		{
			iRc = 0;
		}
		break;
#endif /* OCTTRANSAPI_OPT_SELECT */
	}

	if( iRc < 0)
		pSocket->TransEthCtx.TransCtx.ulLastError = WSAGetLastError();

	TransApiInstanceUnused( pTransInst );
	return iRc;
}

#ifdef OCTTRANSAPI_OPT_SELECT

/*--------------------------------------------------------------------------
TransApiEthPreSelect
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiEthPreSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;

	/* NO need to lock */
	tTRANSAPI_ETH_CTX *		pEthCtx = (tTRANSAPI_ETH_CTX*)pTransInst->pTransApiCtx;

	/* test if should use select */
	if( !pEthCtx->fUseSelect )
		return cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;

	if( pEthCtx->ulType == cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW )
		pEthCtx->fSleepOnRecv=cOCT_FALSE;

	return cOCTTRANSAPI_RC_ERROR_NONE;
}


/*--------------------------------------------------------------------------
OctTransApiEthLoopbackOpen
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiEthLoopbackOpen( 
	tOCTTRANSAPI_CONTEXT	f_Context,
	tOCTTRANSAPI_HANDLE	*f_phTransport )
{
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

		memset( pSocket, 0, sizeof( tTRANSAPI_ETH_SOCKET ) );

	/* Just do minimum init to allow run over ASSERT */
	TransApiEthInitCtx( &pSocket->TransEthCtx, 0, 0);

	pSocket->TransEthCtx.ulType = cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK;
	pSocket->TransEthCtx.fUseSelect = cOCT_TRUE;
	pSocket->Data.Loopback.iReadBlock	= 0;
	pSocket->Data.Loopback.iWriteBlock	= 0;
	pSocket->Data.Loopback.hLock		= CreateSemaphore( NULL, 1, 1, NULL );
	pSocket->hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );
	pTransInst->pTransApiCtx = (tTRANSAPI_CTX*)pSocket;
	*f_phTransport = pTransInst;

	OctOsalMutexRelease( pTransInst->hMutex );

	return iRc;
}

/*--------------------------------------------------------------------------
OctTransApiEthSelect
----------------------------------------------------------------------------*/
int			OctTransApiEthSelect(
								 tOCTTRANSAPI_CONTEXT	f_Context,
								 unsigned int			f_ulTimeoutMs,
								 unsigned int			f_ulTransportCnt,
								 tOCTTRANSAPI_HANDLE		f_ahTransport[],
								 unsigned int			f_aulState[] )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	unsigned int	ulIndex;
	HANDLE			aHandles[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
	DWORD			dwRc;

	memset( aHandles, 0x0, sizeof(aHandles) );

	for ( ulIndex=0; ulIndex<f_ulTransportCnt;ulIndex++ )
	{
		tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;
		tPTRANSAPI_ETH_SOCKET	pSocket;

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
		else if( !pSocket->TransEthCtx.fUseSelect )
			iRc = cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;

#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

		if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		{
			OctOsalMutexRelease( pTransInst->hMutex );
			return iRc;
		}

		if( pSocket->TransEthCtx.ulType == cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW )
			pSocket->TransEthCtx.fSleepOnRecv=cOCT_FALSE;

		/* Store event handle */
		aHandles[ulIndex] = pSocket->hEvent;

		OctOsalMutexRelease( pTransInst->hMutex );

		/* State is not ready */
		f_aulState[ulIndex] = cOCTTRANSAPI_SELECT_STATE_NONE;
	}

	/* Wait for something to happen */
	dwRc = WaitForMultipleObjects(
		f_ulTransportCnt,
		aHandles,
		FALSE,
		(cOCTTRANSAPI_TIMEOUT_FOREVER == f_ulTimeoutMs)
		?INFINITE
		:f_ulTimeoutMs );

	if ( WAIT_TIMEOUT == dwRc )
	{
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	else if ( WAIT_OBJECT_0 <= dwRc && WAIT_OBJECT_0 + f_ulTransportCnt > dwRc )
	{
		/* Fill the state array (only retrieve one event at a time) */
		f_aulState[dwRc - WAIT_OBJECT_0] = cOCTTRANSAPI_SELECT_STATE_RECV;
		iRc = 1;
	}
	else if ( WAIT_ABANDONED_0 <= dwRc && WAIT_ABANDONED_0 + f_ulTransportCnt > dwRc )
	{
		/* Probably a close handle or socket */
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}

	return iRc;
}

#endif /* OCTTRANSAPI_OPT_SELECT */

#endif /* WIN32 */
