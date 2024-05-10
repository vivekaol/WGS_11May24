/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_INST.c

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/

#include <stdio.h>
#include "../../sls/inc/octdev_macro.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment( lib, "octosald.lib" )
#pragma comment( lib, "octtransapid.lib" )
#pragma comment( lib, "octtransapi_ethd.lib" )
#else
#pragma comment( lib, "octosal.lib" )
#pragma comment( lib, "octtransapi.lib" )
#pragma comment( lib, "octtransapi_eth.lib" )
#endif /* _DEBUG */
#endif /* WIN32 */

#include <memory.h>
#include <stdlib.h>
#include <string.h>


/* Transport default interface */
#include "../../common/octtransapi/include/octtransapi.h"
#include "../../common/octtransapi/include/octtransapi_default.h"
#include "../../common/octtransapi/octtransapi_eth/include/octtransapi_eth.h"
#include "../../common/octtransapi/octtransapi_eth/include/octtransapi_eth_default.h"
/* Module interface */
#include "../include/pktapi_inst.h"
#include "../include/pktapi_pkt.h"

/* Vocallo Main interface required for discover until Vocallo exposes a discovery method */
#include "../../sls/inc/octvc1/main/octvc1_main_api.h"
#include "../../sls/inc/octvc1/main/octvc1_main_api_swap.h"
#include "../../sls/inc/octvc1/main/octvc1_main_id.h"
#include "../../sls/inc/octvc1/main/octvc1_main_version.h"
#include "../../sls/inc/octvc1/ctrl/octvc1_ctrl_api.h"
#include "../../sls/inc/octvc1/octvocnet_pkt_swap.h"

unsigned char g_abyPktApiMacAddrNull[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
unsigned char g_abyPktApiMacAddrBroadcast[]  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

static tOCT_BOOL32	l_fDidInitTransport = cOCT_FALSE;
static tOCT_UINT32	l_ulInstanceCnt = 0;

#define cOCTVC1_PKT_API_TRANSPORT_SELECT_MAX	(32)


extern tOCTTRANSAPI_RC_ERROR PktApiInstDispatchBufferFnc( void * f_pAppContext, tOCTTRANSAPI_RECV_PARMS *f_pParms );

/*******************************  STRUCTURES ***********************************/
/*
	Patched Get info response structure, used for discover.
	Need to add the source MAC address
*/
#define cOCTVC1_PKT_API_MAC_ADDR_SIZE_DWORD_ALIGN	(8)

typedef struct
{
	union
	{
		tOCT_UINT8	abyRemoteMacAddr[cOCTVC1_PKT_API_MAC_ADDR_SIZE_DWORD_ALIGN];
		tOCT_UINT8	szDestAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE];
	}DestAddr;

	tOCT_UINT8	abyGetInfoResp[2048];

} tPKTAPI_OCT1010_GET_INFO_RSP_PARMS, *tPPKTAPI_OCT1010_GET_INFO_RSP_PARMS;


extern tOCTTRANSAPI_RC_ERROR PktApiInstDispatchInactivityFnc( tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS *f_pParms );

/****************************  STATIC FUNCTION ********************************/
/*--------------------------------------------------------------------------
	_PktApiInstCalculateSize
		Calculates the size of the instance
----------------------------------------------------------------------------*/
static tOCT_UINT32 _PktApiInstCalculateSize(
	tPOCTVC1_PKT_API_INST_INIT_PARMS	f_pInitParms )
{
	tOCT_UINT32		ulInstSize = 0;
	tOCT_UINT32		ulMsgCnt = ( f_pInitParms->ulMaxPendingData
				+ f_pInitParms->ulMaxPendingEvt
				+ f_pInitParms->ulMaxPendingRsp
				+ f_pInitParms->ulMaxSyncCmd
				+ (cOCTVC1_PKT_API_DEV_MAX * cOCTVC1_PKT_API_DEV_PORT_MAX) ) /* Provision for discover */;

	/* Calculate the required size */
	ulInstSize = sizeof(tPKTAPI_INST_INF);
	/* Packet Q size */
	ulInstSize += (cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT + f_pInitParms->ulMaxSyncCmd) * sizeof(tPKTAPI_PKT_Q_INF);
	
	/* Packet  size */
	ulInstSize += ulMsgCnt * (sizeof(tPKTAPI_PKT_INF) + cPKTAPI_PAYLOAD_MAX + cPKTAPI_PAYLOAD_ALIGNMENT_PADDING );

	/* Connection and session size */
	ulInstSize += ( f_pInitParms->ulMaxConnection * sizeof(tPKTAPI_CNCT_INF) )
				+ ( f_pInitParms->ulMaxConnection * sizeof(tPKTAPI_SESS_INF) );


	return ulInstSize;
}


/***************************  INTERNAL FUNCTION *******************************/
/*--------------------------------------------------------------------------
	PktApiInstUnlock
----------------------------------------------------------------------------*/
int PktApiInstUnlock(
	tPKTAPI_INST_INF *				f_pInst,
	unsigned int					f_ulReason )
{
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
	if ( NULL != f_pInst->hTransportLoopback )
	{
		unsigned int ulUnlock;
		ulUnlock = f_ulReason;
		/* send a loopback packet to unlock the select */
		f_pInst->TransportFunc.pfnTransportApiSend(
					f_pInst->hTransportLoopback,
					NULL,
					&ulUnlock,
					sizeof(ulUnlock) );
	}
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
	return 0;
}

/*--------------------------------------------------------------------------
	PktApiInstCalcElapsedTimeMs
		Calculate elapsed time between start time and current
----------------------------------------------------------------------------*/
unsigned int PktApiInstCalcElapsedTimeMs(
	unsigned int		f_ulCurrentTimeMs,
	unsigned int		f_ulStartTimeMs )
{
	unsigned int		ulElapsedMs = f_ulCurrentTimeMs - f_ulStartTimeMs;
	return (( (int)ulElapsedMs < 0 ) ? 0 : ulElapsedMs );
}


/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
	OctVc1PktApiInstanceGetSize
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstGetSize(
	tPOCTVC1_PKT_API_INST_GET_SIZE_PARMS			f_pParms )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;

	/* Validate parameters */
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParms ) ||
		( NULL == f_pParms->pInitParms ) ||
		( ( 0 == f_pParms->pInitParms->ulMaxConnection ) || (0xFF == (f_pParms->pInitParms->ulMaxConnection & 0xFF)) ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Calculte size */
	f_pParms->ulRequiredSize = _PktApiInstCalculateSize( f_pParms->pInitParms );

	return Result;
}



/*--------------------------------------------------------------------------
	OctVc1PktApiInstInit
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstInit(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_INIT_PARMS				f_pParms )
{
	tOCTTRANSAPI_RC_ERROR		transRc;
	tOCT_UINT32					ulInstSize;
	tOCT_UINT32					ulPktCnt;
	tOCT_UINT32					ulIndex;
	tPKTAPI_INST_INF *			pInst;
	tOCT_UINT8*					pNextPointer;
	tOCT_UINT32		Result = cOCTVC1_PKT_API_RC_OK;
	tOCT_UINT32		ulPayloadHeaderAlignmentPadding = f_pParms->fUseExternalTransport ? 0 : cPKTAPI_PAYLOAD_ALIGNMENT_PADDING;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) ||
		( f_pParms->ulMaxConnection > cOCTVC1_PKT_API_CNCT_MAX ) ||
		( f_pParms->ulMaxSyncCmd > cOCTVC1_PKT_API_CMD_MAX ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;

	if (!f_pParms->fUseExternalTransport)
	{
		if( f_pParms->AdaptorSelection == cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_NAME )
		{
			if( NULL == f_pParms->pszInterfaceName )
				return cOCTVC1_PKT_API_RC_BAD_PARAM;
		}
		else
		{
			if( ( 0 == memcmp( f_pParms->abyLocalMac, g_abyPktApiMacAddrBroadcast, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ||
				( 0 == memcmp( f_pParms->abyLocalMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) )
			return cOCTVC1_PKT_API_RC_BAD_PARAM;
		}
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Keep compatibility with previous release. From now we must initialized the transport context */
	/* Old application never have to. We will init the transport and expecte already init */
	if( OctTransApiIsInit() != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT )
	{
		tOCTTRANSAPI_INIT_PARMS TransInit;
		mOCTTRANSAPI_INIT_PARMS_DEF( &TransInit );

		transRc = OctTransApiInit( &TransInit );
		if( ( transRc != cOCTTRANSAPI_RC_ERROR_ALREADY_INIT ) && 
			( transRc != cOCTTRANSAPI_RC_ERROR_NONE ) )
			return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

		l_fDidInitTransport = cOCT_TRUE;
	}

	if( f_pParms->hTransDispatcher != NULL )
	{
		tOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS DispStatus;
		mOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS_DEF( &DispStatus );

#ifndef OCTOSAL_OPT_MULTI_THREAD
		return cOCTVC1_PKT_API_RC_REQUIRES_MULTI_THREAD;
#endif /*OCTOSAL_OPT_MULTI_THREAD*/
		
		transRc = OctTransApiDispatcherGetStatus( f_pParms->hTransDispatcher, &DispStatus );
		if( transRc != cOCTTRANSAPI_RC_ERROR_NONE )
			return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

		/* Test if at least running */
		if( DispStatus.ulState < cOCTTRANSAPI_DISPATCHER_STATE_ENUM_KEEP_RUNNING )
			return cOCTVC1_PKT_API_RC_DISPATCHER_NOT_READY;
	}


	/* Calculte size */
	ulInstSize = _PktApiInstCalculateSize( f_pParms );

	/* Clear memory */
	memset( f_pInstance, 0x0, ulInstSize );

	/* Prepare instance */
	pInst = (tPKTAPI_INST_INF *)f_pInstance;


	pNextPointer = (tOCT_UINT8*)pInst;
	pNextPointer += sizeof(tPKTAPI_INST_INF);

	/* Store config */
	pInst->ulMagic				= cPKTAPI_MAGIC_INST;

	pInst->pTransportContext	= f_pParms->pTransportContext;
	pInst->ulCmdTimeoutMs		= f_pParms->ulCmdTimeoutMs;
	pInst->ulMaxRetry			= f_pParms->ulMaxRetry;

	pInst->ulMaxConnection		= f_pParms->ulMaxConnection;
	pInst->ulMaxSession			= 1;
	pInst->ulMaxSyncCmd			= f_pParms->ulMaxSyncCmd;
	pInst->ulMaxPendingRsp		= f_pParms->ulMaxPendingRsp;
	pInst->ulMaxPendingEvt		= f_pParms->ulMaxPendingEvt;
	pInst->ulMaxPendingData		= f_pParms->ulMaxPendingData;
	pInst->ulOptionMask			= f_pParms->ulOptionMask;
	pInst->usSessionInstanceStart	= f_pParms->usSessionInstanceStart;
	pInst->pTransportLocalContext = f_pParms->pTransportLocalContext;
	memcpy( pInst->abyLocalMac, f_pParms->abyLocalMac, sizeof(f_pParms->abyLocalMac) );

	pInst->fUseExternalTransport	= f_pParms->fUseExternalTransport;
	pInst->hTransDispatcher			= f_pParms->hTransDispatcher;

	/* Set pointer to routing header misaligned at the begining (ethernet header) in order
	to have aligned payload pointer */
	mOCTOSAL_ASSERT( 0 == ((tOCTOSAL_UINT_PTR)pInst->abyMemory) % 4 );
	pInst->pabyRxBuffer = &pInst->abyMemory[ulPayloadHeaderAlignmentPadding];

	/* Prepare packet Q */
	pInst->ulPktQCnt	= (cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT + f_pParms->ulMaxSyncCmd);
	pInst->paPktQ		= (tPKTAPI_PKT_Q_INF *)pNextPointer;
	pNextPointer		+= (pInst->ulPktQCnt * sizeof(tPKTAPI_PKT_Q_INF));

	/* Open Qs */
	for ( ulIndex=0; ulIndex<pInst->ulPktQCnt && cOCTVC1_PKT_API_RC_OK == Result; ulIndex++ )
	{
		Result = PktApiPktQueueOpen( &pInst->paPktQ[ulIndex] );
	}

	/* Calculate the total packet count */
	ulPktCnt = ( f_pParms->ulMaxPendingData
			+ f_pParms->ulMaxPendingEvt
			+ f_pParms->ulMaxPendingRsp
			+ f_pParms->ulMaxSyncCmd
			+(cOCTVC1_PKT_API_DEV_MAX * cOCTVC1_PKT_API_DEV_PORT_MAX) );

	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		/* Prepare free packets and dispatch them to their respective Q */
		tPPKTAPI_PKT_INF	pPktInf;
		unsigned			ulCurrentType;
		unsigned 			aPktCnt[cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT];

		memset( aPktCnt, 0, sizeof(aPktCnt));
		aPktCnt[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP]		= 0;
		aPktCnt[cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT]	= f_pParms->ulMaxPendingEvt;
		aPktCnt[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA]		= f_pParms->ulMaxPendingData;
		aPktCnt[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER]	= cOCTVC1_PKT_API_DEV_MAX * cOCTVC1_PKT_API_DEV_PORT_MAX;
		aPktCnt[cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD]		= f_pParms->ulMaxPendingRsp;

		pPktInf = (tPPKTAPI_PKT_INF)pNextPointer;

		pPktInf->pNext		= NULL;
		pPktInf->pPrevious	= NULL;

		ulCurrentType = cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;

		for ( ulIndex=0; ulIndex<ulPktCnt; ulIndex++ )
		{
			tPPKTAPI_PKT_INF	pNextPktInf;

			/* Set pointer to payload */
			pPktInf->RecvParms.pPayload = ((tOCT_UINT8*)pPktInf) + sizeof(*pPktInf) + cPKTAPI_PAYLOAD_ALIGNMENT_PADDING;
			pPktInf->RecvParms.ulMaxPayloadLength = cPKTAPI_PAYLOAD_MAX;

			/* Store next pointer */
			pNextPktInf = (tPPKTAPI_PKT_INF)((tOCT_UINT8*)pPktInf->RecvParms.pPayload + cPKTAPI_PAYLOAD_MAX);

			/* Find Q where to put that packet */
			while( (ulCurrentType <= cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD ) && (0 == aPktCnt[ulCurrentType]) )
			{
				/* Look in next Q */
				ulCurrentType++;
			};

			mOCTOSAL_ASSERT( ulCurrentType <= pInst->ulPktQCnt );
			/* Set packet owner */
			pPktInf->ulOwnerQ = ulCurrentType;

			PktApiPktQueuePut(
						cPKTAPI_Q_FREE,
						&pInst->paPktQ[ulCurrentType],
						pPktInf );

			if ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD < ulCurrentType )
			{
				ulCurrentType++;
			}
			else
			{
				aPktCnt[ulCurrentType]--;
			}

			pPktInf = pNextPktInf;
		}

		/* Update next pointer */
		pNextPointer = (tOCT_UINT8*)pPktInf;
	}

	/* Prepare connections and sessions  */
	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		/* Resolve Connection array pointer */
		pInst->paCnctInf	= (tPKTAPI_CNCT_INF *)pNextPointer;
		pInst->ulCnctCnt	= f_pParms->ulMaxConnection;
		/* Move next available pointer */
		pNextPointer += sizeof(pInst->paCnctInf[0]) * pInst->ulCnctCnt;

		for ( ulIndex=0; ulIndex<f_pParms->ulMaxConnection; ulIndex++ )
		{
			unsigned			ulSessIndex;
			tPPKTAPI_CNCT_INF	pCnctInf;

			pCnctInf = &pInst->paCnctInf[ulIndex];
			pCnctInf->ulMagic	= cPKTAPI_MAGIC_CNCT;
			pCnctInf->byIndex	= (tOCT_UINT8)ulIndex;
			pCnctInf->pInst		= pInst;

            if( 0 != mPKTAPI_MUTEX_OPEN( &pCnctInf->hMutex ) )
            {
                Result = cOCTVC1_PKT_API_RC_OS_ERROR;
                break;
            }

			/* Prepare the static packet information */
			pCnctInf->StaticPktInf.pNext		= NULL;
			pCnctInf->StaticPktInf.pPrevious	= NULL;
			pCnctInf->StaticPktInf.ulOwnerQ		= cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID;
			mOCTOSAL_ASSERT( 0 == ((tOCTOSAL_UINT_PTR)pCnctInf->abyMemoryTx) % 4 );
			pCnctInf->StaticPktInf.RecvParms.pPayload	= &pCnctInf->abyMemoryTx[ulPayloadHeaderAlignmentPadding];
			pCnctInf->StaticPktInf.RecvParms.ulMaxPayloadLength	= sizeof( pCnctInf->abyMemoryTx ) - ulPayloadHeaderAlignmentPadding;

			/* Prepare sessions */
			pCnctInf->paSessInf	= (tPKTAPI_SESS_INF *)pNextPointer;
			pCnctInf->ulSessCnt	= 1;

			/* Move next available pointer */
			pNextPointer += sizeof(pCnctInf->paSessInf[0]) * pCnctInf->ulSessCnt;

			for ( ulSessIndex=0; ulSessIndex<pCnctInf->ulSessCnt; ulSessIndex++ )
			{
				tPPKTAPI_SESS_INF	pSessInf;
				pSessInf = &pCnctInf->paSessInf[ulSessIndex];

				pSessInf->ulMagic		= cPKTAPI_MAGIC_SESS;
				pSessInf->byIndex		= (tOCT_UINT8)ulSessIndex;
				pSessInf->pCnct			= pCnctInf;
				pSessInf->hSession		= cPKTAPI_SESS_SESSION_INVALID;
				pSessInf->usInstance	= f_pParms->usSessionInstanceStart;
				pSessInf->ulPendingRspCount = 0;
				pSessInf->ulActiveTimeout	= 0;
				pSessInf->fFlag				= cPKTAPI_SESS_INF_FLAG_MASK_NONE;
				pSessInf->ulRxTransactionId = pSessInf->ulTransactionId = 1;
				pSessInf->ulRxRejectId		= pSessInf->ulResentId		= 0;

                if( 0!= mPKTAPI_MUTEX_OPEN( &pSessInf->hMutex ) )
                {
                    Result = cOCTVC1_PKT_API_RC_OS_ERROR;
                    break;
                }

				/* Open PktQ */
				PktApiPktQueueOpen( &pSessInf->PktQPendingCmd );

			}
		}
	}

	mOCTOSAL_ASSERT( pNextPointer == ((tOCT_UINT8*)f_pInstance + ulInstSize) );

	if ( ( cOCTVC1_PKT_API_RC_OK == Result ) &&
		 ( ( 0 != mPKTAPI_MUTEX_OPEN( &pInst->hMutex ) ) ||
		   ( 0 != mPKTAPI_MUTEX_OPEN( &pInst->hRecvMutex ) ) || 
		   ( 0 != mPKTAPI_MUTEX_OPEN( &pInst->hQueueMutex ) ) ) )
	{
		Result = cOCTVC1_PKT_API_RC_OS_ERROR;
	}

	/* Open porting layer objects */
	if( !pInst->fUseExternalTransport && ( cOCTVC1_PKT_API_RC_OK == Result ) )
	{
		tOCTTRANSAPI_ETH_OPEN EthOpen;
		tOCTTRANSAPI_ETH_OPEN_BY_NAME EthOpenByName;
		tOCT_BOOL32 fUsingEthOpenByName = cOCT_FALSE;
		tOCTTRANSAPI_CONTEXT	pLocalContext;

		if( ( f_pParms->TransportFunc.pfnTransportApiOpen != NULL ) &&
			( f_pParms->TransportFunc.pfnTransportApiClose != NULL ) &&
			( f_pParms->TransportFunc.pfnTransportApiSend != NULL ) &&
			( f_pParms->TransportFunc.pfnTransportApiRecv != NULL )
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
			&& ( f_pParms->TransportFunc.pfnTransportApiSelect != NULL )
			&& ( f_pParms->TransportFunc.pfnTransportApiOpenLoopBack != NULL )
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
			)
		{
			memcpy( &pInst->TransportFunc, &f_pParms->TransportFunc, sizeof(pInst->TransportFunc) );
			pLocalContext = pInst->pTransportLocalContext;
		}
		else	/* Using default ethernet transport */
		{

			/* Calculate minimum rx buffer size = max connection * ((nb pending * 3) + (rsp.event.data) ) */
			tOCT_UINT32 ulMinRxBufferSize = ( pInst->ulMaxConnection * (( f_pParms->ulMaxPendingData + ( cPKTAPI_SESS_PENDING_RSP_MAX * 3 ) ) * 1500 ) );

			if( f_pParms->AdaptorSelection != cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_NAME )
			{
				mOCTTRANSAPI_ETH_OPEN_DEF( &EthOpen );
				EthOpen.usEtherType = cOCTVOCNET_PKT_ETHERTYPE;
				EthOpen.ulCtrlProtoType = cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTVOCNET;
				EthOpen.pLocalContext = pInst->pTransportLocalContext;
				EthOpen.ulMinRxBufferSize = ulMinRxBufferSize;
				memcpy( EthOpen.MacAddress.abyMacAddress, pInst->abyLocalMac, sizeof( EthOpen.MacAddress.abyMacAddress) );

				if( f_pParms->hTransDispatcher != NULL )
					EthOpen.ulMaxDestination = f_pParms->ulMaxConnection;

				pLocalContext = &EthOpen;
				pInst->TransportFunc.pfnTransportApiOpen = (tPFNTRANSPORTAPI_OPEN)OctTransApiEthOpen;
			}
			else
			{
				mOCTTRANSAPI_ETH_OPEN_BY_NAME_DEF( &EthOpenByName );
				EthOpenByName.EthOpen.usEtherType = cOCTVOCNET_PKT_ETHERTYPE;
				EthOpenByName.EthOpen.ulCtrlProtoType = cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTVOCNET;
				EthOpenByName.EthOpen.pLocalContext = pInst->pTransportLocalContext;
				EthOpenByName.EthOpen.ulMinRxBufferSize = ulMinRxBufferSize;
				EthOpenByName.pszInterfaceName = f_pParms->pszInterfaceName;
				pLocalContext = &EthOpenByName;
				fUsingEthOpenByName=cOCT_TRUE;

				if( f_pParms->hTransDispatcher != NULL )
					EthOpenByName.EthOpen.ulMaxDestination = f_pParms->ulMaxConnection;

				pInst->TransportFunc.pfnTransportApiOpen = (tPFNTRANSPORTAPI_OPEN)OctTransApiEthOpenByName;
			}

			pInst->TransportFunc.pfnTransportApiClose = OctTransApiEthClose;
			pInst->TransportFunc.pfnTransportApiSend = OctTransApiEthSend;
			pInst->TransportFunc.pfnTransportApiRecv = OctTransApiEthRecv;
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
			pInst->TransportFunc.pfnTransportApiSelect = OctTransApiEthSelect;
			pInst->TransportFunc.pfnTransportApiOpenLoopBack = OctTransApiEthLoopbackOpen;
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */

		}


		if ( 0 != pInst->TransportFunc.pfnTransportApiOpen(
							pInst->pTransportContext,
							pLocalContext,
							&pInst->hTransport ) )
		{
			Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
		}
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
		/* Create loopback transport */
		else if ( 0 != pInst->TransportFunc.pfnTransportApiOpenLoopBack(
						pInst->pTransportContext,
						&pInst->hTransportLoopback ) )
		{
			Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
		}
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */

		if( ( cOCTTRANSAPI_RC_ERROR_NONE == Result ) && fUsingEthOpenByName )
		{
			/* Retrieve the MAC */
			memcpy( pInst->abyLocalMac, EthOpenByName.EthOpen.MacAddress.abyMacAddress, sizeof(pInst->abyLocalMac) );
		}
	}

	/* Prepare discover objects */
	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		tPPKTAPI_CNCT_INF	pCnctInf;
		tPPKTAPI_SESS_INF	pSessInf;
		unsigned			ulSessIndex;
		tOCTVC1_PKT_API_CNCT_OPEN_PARMS	CnctOpenParms;

		pCnctInf			= &pInst->DiscoverCnct;
		pCnctInf->ulMagic	= cPKTAPI_MAGIC_CNCT;
		pCnctInf->pInst		= pInst;

        if( 0 == mPKTAPI_MUTEX_OPEN( &pCnctInf->hMutex ) )
        {

            /* Prepare the static packet information */
            pCnctInf->StaticPktInf.pNext		= NULL;
            pCnctInf->StaticPktInf.pPrevious	= NULL;
            pCnctInf->StaticPktInf.ulOwnerQ		= cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID;
            mOCTOSAL_ASSERT( 0 == ((tOCTOSAL_UINT_PTR)pCnctInf->abyMemoryTx) % 4 );

			pCnctInf->StaticPktInf.RecvParms.pPayload	= &pCnctInf->abyMemoryTx[ulPayloadHeaderAlignmentPadding];
			pCnctInf->StaticPktInf.RecvParms.ulMaxPayloadLength	= sizeof( pCnctInf->abyMemoryTx ) - ulPayloadHeaderAlignmentPadding;

            /* Prepare sessions */
            pCnctInf->paSessInf	= (tPKTAPI_SESS_INF *)&pInst->DiscoverSess;
            pCnctInf->ulSessCnt	= 1;


            for ( ulSessIndex=0; ulSessIndex<pCnctInf->ulSessCnt; ulSessIndex++ )
            {
                pSessInf = &pCnctInf->paSessInf[ulSessIndex];
                pSessInf->ulMagic	= cPKTAPI_MAGIC_SESS;
                pSessInf->pCnct		= pCnctInf;
                pSessInf->hSession	= cPKTAPI_SESS_SESSION_INVALID;

                if( 0 != mPKTAPI_MUTEX_OPEN( &pSessInf->hMutex ) )
                {
                    Result = cOCTVC1_PKT_API_RC_OS_ERROR;
                    break;
                }

                /* Open PktQ */
                PktApiPktQueueOpen( &pSessInf->PktQPendingCmd );

            }

            if ( cOCTVC1_PKT_API_RC_OK == Result )
            {
                /* Open the discover connection */
				if( !pInst->fUseExternalTransport )
				{
					memcpy( CnctOpenParms.abyRemoteMac, g_abyPktApiMacAddrBroadcast, sizeof(g_abyPktApiMacAddrBroadcast) );
	                CnctOpenParms.pTransportRemoteContext	= NULL;
		            CnctOpenParms.pUserConnectionContext	= NULL;
			        /* Prepare the connection */
				    Result = PktApiCnctPrepare( pCnctInf, &CnctOpenParms );
				}
            }
        }
        else
            Result = cOCTVC1_PKT_API_RC_OS_ERROR;
	}
	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		if( f_pParms->hTransDispatcher != NULL )
		{
			tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS DispInact;
			mOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS_DEF( &DispInact );

			DispInact.pfnDispatchInactivity = PktApiInstDispatchInactivityFnc;
			DispInact.ulElapseInactivityMs	= ( cPKTAPI_INST_TIMEOUT_CMD_DEF >> 2);
			DispInact.pInactivityAppContext = pInst;

			transRc = OctTransApiDispatcherSetInactivity( f_pParms->hTransDispatcher, &DispInact );
			if( transRc != cOCTTRANSAPI_RC_ERROR_NONE )
				Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

			/* Test if have to add transport to dispatcher */
			if( !pInst->fUseExternalTransport )
			{
				tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS DispAdd;
				mOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS_DEF( &DispAdd );

				DispAdd.hTransport			= pInst->hTransport;
				DispAdd.pfnDispatchPayload	= PktApiInstDispatchBufferFnc;
				DispAdd.pAppContext			= pInst;

				if( OctTransApiDispatcherAddTransport( pInst->hTransDispatcher, &DispAdd ) != cOCTTRANSAPI_RC_ERROR_NONE )
					Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
			}
		}
	}

	l_ulInstanceCnt++;

	if ( cOCTVC1_PKT_API_RC_OK != Result )
	{
		/* Terminate instance on error */
		tOCTVC1_PKT_API_INST_TERM_PARMS	TerminateParms;
		TerminateParms.fForce = cOCT_TRUE;

		OctVc1PktApiInstTerm( f_pInstance, &TerminateParms );
	}
	else
	{
		pInst->fReady = cOCT_TRUE;
		
	}
	return Result;
}





/*--------------------------------------------------------------------------
	OctVc1PktApiInstTerminate
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstTerm(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_TERM_PARMS				f_pParms )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_INST_INF *		pInst;
	unsigned int			ulIndex;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pInst = (tPKTAPI_INST_INF *)f_pInstance;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Some connection opened ? */
	if ( 0 != pInst->Stats.ulOpenConnectionCnt )
	{
		if ( cOCT_TRUE == f_pParms->fForce )
		{
			/* Close every connections */
			for ( ulIndex=0; ulIndex<pInst->ulCnctCnt; ulIndex++ )
			{
				if ( 0 != memcmp( pInst->paCnctInf[ulIndex].abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) )
				{
					tOCTVC1_PKT_API_CNCT_CLOSE_PARMS	CloseParms;
					mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF( &CloseParms );
					CloseParms.fForce = cOCT_TRUE;
					Result = OctVc1PktApiCnctClose( (tPOCTVC1_PKT_API_CNCT)&pInst->paCnctInf[ulIndex], &CloseParms );

					if ( Result != cOCTVC1_PKT_API_RC_OK )
					{
						break;
					}
				}
			}
		}
		else
		{
			Result = cOCTVC1_PKT_API_RC_INST_CNCT_DEP;
		}
	}
	/* Close discover connection ... if init */
	if ( ( cOCTVC1_PKT_API_RC_OK == Result ) && 
		( pInst->DiscoverCnct.ulMagic == cPKTAPI_MAGIC_CNCT ) )
	{
		tOCTVC1_PKT_API_CNCT_CLOSE_PARMS	CloseParms;
		mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF( &CloseParms );
		CloseParms.fForce = cOCT_TRUE;
		OctVc1PktApiCnctClose( (tPOCTVC1_PKT_API_CNCT)&pInst->DiscoverCnct, &CloseParms );
	}

	/* Release or destroy mutex ? */
	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		pInst->fReady = cOCT_FALSE;
#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
		if( pInst->fUseExternalTransport == cOCT_FALSE )
		{
	        if(pInst->hTransDispatcher == NULL)
			{
				PktApiInstUnlock( pInst, cPKTAPI_INST_UNLOCK_REASON_TERMINATE );
				while ( 0 != mPKTAPI_INST_RECVMUTEX_TIMED_SEIZE( pInst, 50 ) )
				{
					PktApiInstUnlock( pInst, cPKTAPI_INST_UNLOCK_REASON_TERMINATE );
				};

				OctOsalSleepMs(2000);
			}
		}

       /*Stop dispatcher from using inactivity function*/
        if(pInst->hTransDispatcher != NULL)
        {
            tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS DispInact;
            mOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS_DEF( &DispInact );
            OctTransApiDispatcherSetInactivity(pInst->hTransDispatcher,&DispInact);
        }

        if(pInst->hTransDispatcher != NULL)
		{
			// Signal all recv thread to terminate
			for ( ulIndex=0; ulIndex<pInst->ulPktQCnt;ulIndex++ )
			{
				mPKTAPI_PKT_Q_SYNC_SIGNAL_SET( (&pInst->paPktQ[ulIndex]) );
			}
			OctOsalSleepMs(200);
		}

#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

 

		if(( pInst->hTransDispatcher != NULL ) &&
			( pInst->fUseExternalTransport == cOCT_FALSE ) &&
			( NULL != pInst->hTransport ) )
		{
			OctTransApiDispatcherRemoveTransport( pInst->hTransport );
		}

        mPKTAPI_INST_MUTEX_SEIZE(pInst);

		/* Close the transport object */
		if ( NULL != pInst->hTransport )
		{
			pInst->TransportFunc.pfnTransportApiClose(
						pInst->hTransport );
			pInst->hTransport = NULL;
		}

#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
		if ( NULL != pInst->hTransportLoopback )
		{
			pInst->TransportFunc.pfnTransportApiClose(
						pInst->hTransportLoopback );
			pInst->hTransportLoopback = NULL;
		}
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
		/* Close evey Q */
		for ( ulIndex=0; ulIndex<pInst->ulPktQCnt; ulIndex++ )
		{
			PktApiPktQueueClose( &pInst->paPktQ[ulIndex] );
		}

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
		/* Close mutex of every session of every connection */
		for ( ulIndex=0; ulIndex<pInst->ulCnctCnt; ulIndex++ )
		{
			unsigned int	ulSessIndex;
			for ( ulSessIndex=0; ulSessIndex<pInst->paCnctInf[ulIndex].ulSessCnt; ulSessIndex++ )
			{
				/* Close Session PktQ */
				PktApiPktQueueClose( &pInst->paCnctInf[ulIndex].paSessInf[ulSessIndex].PktQPendingCmd );

				if ( NULL != pInst->paCnctInf[ulIndex].paSessInf[ulSessIndex].hMutex )
				{
					mPKTAPI_MUTEX_CLOSE( &pInst->paCnctInf[ulIndex].paSessInf[ulSessIndex].hMutex );
					pInst->paCnctInf[ulIndex].paSessInf[ulSessIndex].hMutex = NULL;
				}
			}

			if ( NULL != pInst->paCnctInf[ulIndex].hMutex )
			{
				mPKTAPI_MUTEX_CLOSE( &pInst->paCnctInf[ulIndex].hMutex );
				pInst->paCnctInf[ulIndex].hMutex = NULL;
			}
		}

		/* Close Discover Session PktQ */
		if( pInst->DiscoverSess.ulMagic == cPKTAPI_MAGIC_SESS )
		{
			PktApiPktQueueClose( &pInst->DiscoverSess.PktQPendingCmd );

			if ( NULL != pInst->DiscoverSess.hMutex )
			{
				mPKTAPI_MUTEX_CLOSE( &pInst->DiscoverSess.hMutex );
				pInst->DiscoverSess.hMutex = NULL;
			}
		}

		/* Close mutex of discover session and connection */
		if ( NULL != pInst->DiscoverCnct.hMutex )
		{
			mPKTAPI_MUTEX_CLOSE( &pInst->DiscoverCnct.hMutex );
			pInst->DiscoverCnct.hMutex = NULL;
		}

		/* 
		mPKTAPI_INST_MUTEX_RELEASE(pInst);
		mPKTAPI_INST_RECVMUTEX_RELEASE(pInst); 
		force to quit on error 
		*/
		mPKTAPI_INST_MUTEX_RELEASE( pInst );

		mPKTAPI_MUTEX_CLOSE( &pInst->hMutex );
		mPKTAPI_MUTEX_CLOSE( &pInst->hRecvMutex );
		mPKTAPI_MUTEX_CLOSE( &pInst->hQueueMutex );

		pInst->hMutex = NULL;
		pInst->hRecvMutex = NULL;
		pInst->hQueueMutex = NULL;
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

		/* wipe memory */
		memset( pInst, 0x0, sizeof(*pInst) );
	}

	if(( cOCTVC1_PKT_API_RC_OK == Result ) &&  l_ulInstanceCnt )
	{
		l_ulInstanceCnt--;
		if(( l_ulInstanceCnt == 0 ) && l_fDidInitTransport )
		{
			tOCTTRANSAPI_TERMINATE_PARMS TransTerm;
			mOCTTRANSAPI_TERMINATE_PARMS_DEF( &TransTerm );
			OctTransApiTerminate( &TransTerm );
		}
	}

	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiInstStats
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstStats(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_STATS_PARMS				f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_INST_INF *		pInst;
	tOCT_UINT32				fClear;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	/* Validate parameters */
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pInst = (tPKTAPI_INST_INF *)f_pInstance;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	fClear = f_pParms->fClear;
	memcpy( f_pParms, &pInst->Stats, sizeof(pInst->Stats) );

	if ( cOCT_TRUE == fClear )
	{
		tOCT_UINT32		ulOpenConnectionCnt;
		tOCT_UINT32		ulOpenSessionCnt;

		mPKTAPI_INST_MUTEX_SEIZE( pInst );

		/* Latch open counters */
		ulOpenConnectionCnt	= pInst->Stats.ulOpenConnectionCnt;
		ulOpenSessionCnt	= pInst->Stats.ulOpenSessionCnt;

		/* Clear the stats */
		memset( &pInst->Stats, 0x0, sizeof(pInst->Stats) );
		/* Copy back the open counters */
		pInst->Stats.ulOpenConnectionCnt	= ulOpenConnectionCnt;
		pInst->Stats.ulOpenSessionCnt		= ulOpenSessionCnt;
		mPKTAPI_INST_MUTEX_RELEASE( pInst );
	}

	return Result;
}
/*--------------------------------------------------------------------------
	_PktApiActiveTimeoutSet
----------------------------------------------------------------------------*/
static void _PktApiActiveTimeoutSet(
	tPPKTAPI_PKT_INF		f_pPktInf,
	tOCT_BOOL32	f_increase )
{
	tOCT_UINT32	ulTimeoutMs = cPKTAPI_INST_TIMEOUT_CMD_DEF;

	if( f_pPktInf->RecvParms.Info.Rsp.ulCmdId & cOCTVC1_MSG_LONG_PROCESSING_FLAG )
		ulTimeoutMs = cPKTAPI_INST_LONG_TIMEOUT_CMD_DEF;
	else if( f_pPktInf->RecvParms.Info.Rsp.ulCmdId & cOCTVC1_MSG_MID_PROCESSING_FLAG )
		ulTimeoutMs = cPKTAPI_INST_MID_TIMEOUT_CMD_DEF;

	if( f_increase )
		((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulActiveTimeout += ulTimeoutMs;
	else
	{
		if( ((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulActiveTimeout > ulTimeoutMs )
			((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulActiveTimeout -= ulTimeoutMs;
		else
			((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulActiveTimeout = 0;
	}

}
/*--------------------------------------------------------------------------
	_PktApiMsgTimeoutSet
----------------------------------------------------------------------------*/
static void _PktApiMsgTimeoutSet(
	tPKTAPI_INST_INF *		f_pInst,
	tPPKTAPI_PKT_INF		f_pPktInf )
{

	/* Prepare timeout response */
	f_pPktInf->RecvParms.RcvPktType				= cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
	f_pPktInf->RecvParms.ulRcvPayloadLength		= 0;
	f_pPktInf->RecvParms.Info.Rsp.ulReturnCode	= cOCTVC1_PKT_API_RC_TIMEOUT;

	
	/* update pending rsp */
	if( ((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulPendingRspCount > 0 )
	{
		((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulPendingRspCount--;

		/* update the active timeout with the recv response */
		_PktApiActiveTimeoutSet( f_pPktInf, cOCT_FALSE );
	}
	else
		((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulActiveTimeout = 0;


	/* Check for one-way command (ulCmdId already swapped) */
	if ( f_pPktInf->RecvParms.Info.Rsp.ulCmdId & cOCTVC1_MSG_NO_RESPONSE_FLAG )
	{
		/* Change return code and skip timeout stats increment. */
		f_pPktInf->RecvParms.Info.Rsp.ulReturnCode	= cOCTVC1_PKT_API_RC_OK;
	}
	else
	{
		/* Increment the stats */
		f_pInst->Stats.ulTotalPktTimeoutCnt++;
		if ( NULL != f_pPktInf->RecvParms.pConnection )
		{
			((tPKTAPI_CNCT_INF *)f_pPktInf->RecvParms.pConnection)->Stats.ulTotalPktTimeoutCnt++;
		}
		if ( NULL != f_pPktInf->RecvParms.pSession )
		{
			((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->Stats.ulPktTimeoutCnt++;
		}
	}

	if( ((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->ulPendingRspCount == 0 )
	{
		((tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession)->fFlag &= ~( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | 
						cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT |
						cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION |
						cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION );
	}

	/* Post in Q */
	PktApiPktQueuePutAndSignal(
				cPKTAPI_Q_BUSY,
				( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == f_pPktInf->ulOwnerQ )
					?&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP]
					:&f_pInst->paPktQ[f_pPktInf->ulOwnerQ],
				f_pPktInf );

}

/*--------------------------------------------------------------------------
	_PktApiMsgTimeoutSessionSet
----------------------------------------------------------------------------*/
static int _PktApiMsgTimeoutSessionSet(
	tPKTAPI_INST_INF *		f_pInst,
	tPPKTAPI_PKT_INF		f_pPktInf )
{
	int	iCnt = 0;
	tPPKTAPI_PKT_INF		pPktInf = f_pPktInf;
	unsigned int			ulIndex=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD;
	tPKTAPI_SESS_INF		*pSessInf = (tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession;

	/* May happend on close session */
	if( pSessInf == NULL )
		return 0;

	mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );

	/* Loop all Q to send timeout response */
	do
	{
		if( pPktInf==NULL )
		{
			ulIndex++;
			if( ulIndex == f_pInst->ulPktQCnt )
				break;
		}
		else
		{
			_PktApiMsgTimeoutSet( f_pInst, pPktInf );
			iCnt++;
		}

		pPktInf = PktApiPktQueueExtractAny( ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == ulIndex ) ? cPKTAPI_Q_BUSY:cPKTAPI_Q_SPECIAL,
								&f_pInst->paPktQ[ulIndex], pSessInf->hSession );

	}while( ulIndex<f_pInst->ulPktQCnt );

	/* Now do session pending cmd */
	do
	{
		pPktInf = PktApiPktQueueGet( cPKTAPI_Q_BUSY, &pSessInf->PktQPendingCmd );
		if( pPktInf )
		{
			_PktApiMsgTimeoutSet( f_pInst, pPktInf );
			iCnt++;
		}
	}while( pPktInf != NULL );

	/* Cleanup session param */
	pSessInf->fFlag &= ~( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | 
						cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT |
						cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION |
						cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION );

	pSessInf->fFlag |= cPKTAPI_SESS_INF_FLAG_MASK_RESYNC;	/* Make sure to resync next command */
	pSessInf->ulActiveTimeout = 0;
	pSessInf->ulPendingRspCount = 0;
	pSessInf->ulResentId = 0;
	pSessInf->ulRxRejectId = 0;
	pSessInf->ulRxTransactionId = pSessInf->ulTransactionId;
	

	mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );
	return iCnt;
}

/*--------------------------------------------------------------------------
	_PktApiCmpTransactId
----------------------------------------------------------------------------*/
static int _PktApiCmpTransactId(const void *aa, const void *bb)
{
    tPPKTAPI_PKT_INF pPktInf_A = *(tPPKTAPI_PKT_INF *)aa;
	tPPKTAPI_PKT_INF pPktInf_B = *(tPPKTAPI_PKT_INF *)bb;

	/* Test if loop */
	if( pPktInf_A->ulTransactionId < pPktInf_B->ulTransactionId )
	{
		/* diff should never be > NB PENDING */
		if( (pPktInf_B->ulTransactionId - pPktInf_A->ulTransactionId ) > 1000 )
			return 1;

		return ( -1 );
	}

	return ( pPktInf_A->ulTransactionId - pPktInf_B->ulTransactionId );
}

/*--------------------------------------------------------------------------
	_PktApiMsgSessionRetry
----------------------------------------------------------------------------*/
static int _PktApiMsgSessionRetry(
	tPKTAPI_INST_INF *		f_pInst,
	tPPKTAPI_PKT_INF		f_pPktInf )
{
	int						iCnt = 0;
	tPPKTAPI_PKT_INF		pPktInf;
	tPPKTAPI_PKT_INF		apPktInf[cPKTAPI_SESS_PENDING_RSP_MAX];
	tOCT_UINT32				ulIndex;
	tPKTAPI_SESS_INF		*pSessInf = (tPKTAPI_SESS_INF *)f_pPktInf->RecvParms.pSession;
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tOCT_UINT32				iCmd=0;


	/* May happend on close session */
	if( pSessInf == NULL )
		return 0;

	apPktInf[iCmd++]=f_pPktInf;

	mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );

	/* Extract all session sent cmd. Since we have one msg timeout ... all sent cmd must be resent */
	for( ulIndex=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD; ulIndex<f_pInst->ulPktQCnt;)
	{
		pPktInf = PktApiPktQueueExtractAny( ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == ulIndex ) ? cPKTAPI_Q_BUSY:cPKTAPI_Q_SPECIAL,
							&f_pInst->paPktQ[ulIndex], pSessInf->hSession );

		if( pPktInf )
		{
			mOCTOSAL_ASSERT( iCmd < cPKTAPI_SESS_PENDING_RSP_MAX );
			apPktInf[iCmd++]=pPktInf;	
		}
		else
			ulIndex++;
	}

    qsort(apPktInf, iCmd, sizeof(tPPKTAPI_PKT_INF), _PktApiCmpTransactId);

	for( ulIndex=0; ulIndex<iCmd; ulIndex++ )
	{
		/* set retransmit */
		apPktInf[ulIndex]->ulFlag |= cPKTAPI_PKT_INF_FLAG_MASK_RETRANSMIT;

		/* Re-submit the packet */
		Result = PktApiCnctPktSend(
						pSessInf->pCnct,
						( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == apPktInf[ulIndex]->ulOwnerQ )
							?cPKTAPI_Q_BUSY
							:cPKTAPI_Q_SPECIAL,
						apPktInf[ulIndex]->ulOwnerQ,
						cOCTVOCNET_PKT_FORMAT_CTRL,
						apPktInf[ulIndex] ); 

		if ( cOCTVC1_PKT_API_RC_OK != Result )
		{
			/* Have to return packet to user with response indicating error */
			apPktInf[ulIndex]->RecvParms.RcvPktType			= cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
			apPktInf[ulIndex]->RecvParms.ulRcvPayloadLength	= 0;
			apPktInf[ulIndex]->RecvParms.Info.Rsp.ulReturnCode	= cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

			/* Update active timeout && RspCount */
			if( pSessInf->ulPendingRspCount > 0 )
			{
				pSessInf->ulPendingRspCount--;

				/* Update active timeout .. test just in case*/
				_PktApiActiveTimeoutSet( apPktInf[ulIndex], cOCT_FALSE );

			}
			else
				pSessInf->ulActiveTimeout = 0;

			/* Post in Q */
			PktApiPktQueuePutAndSignal(
						cPKTAPI_Q_BUSY,
						( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == apPktInf[ulIndex]->ulOwnerQ )
							?&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP]
							:&f_pInst->paPktQ[apPktInf[ulIndex]->ulOwnerQ],
						apPktInf[ulIndex] );
		}
		else
		{
			apPktInf[ulIndex]->ulRetry++;
			pSessInf->Stats.ulPktRetryCnt++;
			pSessInf->Stats.ulPktSentCnt++;

			pSessInf->pCnct->Stats.ulTotalPktRetryCnt++;
			f_pInst->Stats.ulTotalPktRetryCnt++;

			pSessInf->fFlag |= ( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT );

			/* This transaction may already be in resend procedure */
			if( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION )
			{
				if( pSessInf->ulResentId == apPktInf[ulIndex]->ulTransactionId )
					pSessInf->fFlag &= ~cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION;
			}
		}
		iCnt++;
	}

	mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );
	return iCnt;


}

/*--------------------------------------------------------------------------
	_PktApiSendingPending
----------------------------------------------------------------------------*/
static int _PktApiSendingPending( tPKTAPI_SESS_INF * f_pSessInf )
{
	tOCT_UINT32 Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_PKT_INF *	pCmdPktInf;

	/* Can't send pending cmd when we are in fault processing (resend,timeout or reject)*/
	if( ( f_pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING ) == 0 )
	{
		/* Send all pending up to max */
		while( f_pSessInf->ulPendingRspCount < cPKTAPI_SESS_PENDING_RSP_MAX )
		{
			pCmdPktInf = PktApiPktQueueGet( cPKTAPI_Q_BUSY, &f_pSessInf->PktQPendingCmd );
			if( pCmdPktInf )
			{
				/* Set transaction ID */
				pCmdPktInf->ulTransactionId	= f_pSessInf->ulTransactionId++;

				/* Send the packet */
				Result = PktApiCnctPktSend(
								f_pSessInf->pCnct,
								( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == pCmdPktInf->ulOwnerQ )
									?cPKTAPI_Q_BUSY
									:cPKTAPI_Q_SPECIAL,
								pCmdPktInf->ulOwnerQ,
								cOCTVOCNET_PKT_FORMAT_CTRL,
								pCmdPktInf ); 

				if ( cOCTVC1_PKT_API_RC_OK != Result )
				{
					/* Have to return packet to user with response indicating error */
					pCmdPktInf->RecvParms.RcvPktType			= cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
					pCmdPktInf->RecvParms.ulRcvPayloadLength	= 0;
					pCmdPktInf->RecvParms.Info.Rsp.ulReturnCode	= cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

					/* Post in Q */
					PktApiPktQueuePutAndSignal(
								cPKTAPI_Q_BUSY,
								( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == pCmdPktInf->ulOwnerQ )
									?&f_pSessInf->pCnct->pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP]
									:&f_pSessInf->pCnct->pInst->paPktQ[pCmdPktInf->ulOwnerQ],
								pCmdPktInf );
				}
				else
				{
					f_pSessInf->Stats.ulPktSentCnt++;
					f_pSessInf->ulPendingRspCount++;

					_PktApiActiveTimeoutSet( pCmdPktInf, cOCT_TRUE );

					// Set timeout for this cmd
					pCmdPktInf->ulStartTimeMs = OctOsalGetTimeMs();
					pCmdPktInf->ulTimeoutMs = f_pSessInf->ulActiveTimeout;
				}
			}
			else
				break;
		}
	}

	return Result;

}

/*--------------------------------------------------------------------------
	_PktApiInstQueueTimeoutCheck
----------------------------------------------------------------------------*/
static int _PktApiInstQueueTimeoutCheck(
	tPKTAPI_INST_INF *				f_pInst )
{
	int						iCnt = 0;
	tPPKTAPI_PKT_INF		pPktInf = NULL;
	unsigned int			ulIndex;
	unsigned int			ulCurrentTimeMs;

	/* Get the time */
	ulCurrentTimeMs = OctOsalGetTimeMs();

	/* Get ready to check timeout in few (50) ms */
	f_pInst->ulTimeoutCheckMs = ulCurrentTimeMs;

	/* Loop all Q to resend timeout msg */
	for( ulIndex=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD; ulIndex<f_pInst->ulPktQCnt; ulIndex++ )
	{
		/* Chck for timeout msg */
		pPktInf = PktApiPktQueueTimeoutCheck(
							( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == ulIndex ) ? cPKTAPI_Q_BUSY:cPKTAPI_Q_SPECIAL,
							&f_pInst->paPktQ[ulIndex],
							ulCurrentTimeMs );
		if( pPktInf != NULL )
		{
			tPKTAPI_SESS_INF *	pSessInf;

			mPKTAPI_INST_MUTEX_SEIZE( f_pInst );
			
			pSessInf = (tPKTAPI_SESS_INF *)pPktInf->RecvParms.pSession;

			/* Check for one-way command (ulCmdId already swapped) */
			if ( pPktInf->RecvParms.Info.Rsp.ulCmdId & cOCTVC1_MSG_NO_RESPONSE_FLAG )
			{
				_PktApiMsgTimeoutSet( f_pInst, pPktInf ); 				/* Reply OK to app */

				/* Lock the session */
				mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );

				/* May have to send pending cmd */
				_PktApiSendingPending( pSessInf );

				/* Unlock the session */
				mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );

			}
			else
			{
				if( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_ALLOW_RESEND )
				{
					/* Resent all session msg */
					if(  pPktInf->ulRetry < f_pInst->ulMaxRetry  )
						_PktApiMsgSessionRetry( f_pInst, pPktInf );
					else	/* If reach max retry ... set timeout */
							/* Apply timeout on all session msg */
						iCnt += _PktApiMsgTimeoutSessionSet( f_pInst, pPktInf );
				}
				else	/* Apply timeout on all session msg */
					iCnt += _PktApiMsgTimeoutSessionSet( f_pInst, pPktInf );
			}
			mPKTAPI_INST_MUTEX_RELEASE( f_pInst );
		}
	}

	return iCnt;
}


/*--------------------------------------------------------------------------
	_PktApiInstQueueToRecvParm
----------------------------------------------------------------------------*/
static tOCT_BOOL32 _PktApiInstQueueToRecvParm(
	tPKTAPI_INST_INF *					f_pInst,
	tPPKTAPI_PKT_INF					f_pPktInf,
	tPOCTVC1_PKT_API_INST_RECV_PARMS		f_pParms )
{
	tOCTVC1_PKT_API_RCV_MASK		PktRcvMask;
	tOCT_UINT32						ulTimeoutMs;
	void *							pPayload;
	tOCT_UINT32						ulMaxPayloadLength;

	/* Latch user values */
	PktRcvMask			= f_pParms->PktRcvMask;
	ulTimeoutMs			= f_pParms->ulTimeoutMs;
	pPayload			= f_pParms->pPayload;
	ulMaxPayloadLength	= f_pParms->ulMaxPayloadLength;

	/* Copy the complete structure */
	memcpy( f_pParms, &f_pPktInf->RecvParms, sizeof(f_pPktInf->RecvParms) );

	/* Set back user values */
	f_pParms->PktRcvMask			= PktRcvMask;
	f_pParms->ulTimeoutMs			= ulTimeoutMs;
	f_pParms->ulMaxPayloadLength	= ulMaxPayloadLength;

	/* Copy payload */
	f_pParms->pPayload	= pPayload;
	memcpy( f_pParms->pPayload, f_pPktInf->RecvParms.pPayload, mMIN( f_pParms->ulMaxPayloadLength, f_pPktInf->RecvParms.ulRcvPayloadLength ) );

	/* Return packet to its Q (owner) */
	PktApiPktQueuePut(
					cPKTAPI_Q_FREE,
					&f_pInst->paPktQ[f_pPktInf->ulOwnerQ],
					f_pPktInf );

	return cOCT_TRUE;
}
/*--------------------------------------------------------------------------
	_PktApiInstQueueRecv
----------------------------------------------------------------------------*/
static tOCT_BOOL32 _PktApiInstQueueRecv(
	tPKTAPI_INST_INF *				f_pInst,
	unsigned int					f_aulPktType[],
	unsigned int					f_ulPktTypeCnt,
	tPOCTVC1_PKT_API_INST_RECV_PARMS		f_pParms )
{
	unsigned				ulIndex;
	tPPKTAPI_PKT_INF		pPktInf = NULL;

	/* Check in Queues */
	for ( ulIndex=0;ulIndex<f_ulPktTypeCnt; ulIndex++ )
	{
		/* Get a busy block from that Q */
		pPktInf = PktApiPktQueueGet(
						cPKTAPI_Q_BUSY,
						&f_pInst->paPktQ[f_aulPktType[ulIndex]] );

		if ( NULL != pPktInf )
		{
			break;
		}
	}

	/* Got one ? return it an leave */
	if ( NULL != pPktInf )
		return _PktApiInstQueueToRecvParm( f_pInst, pPktInf, f_pParms );

	return cOCT_FALSE;
}

/*--------------------------------------------------------------------------
	_PktApiHandleDataPkt
----------------------------------------------------------------------------*/
static int _PktApiHandleDataPkt(
	tPKTAPI_INST_INF *				f_pInst,
	tPKTAPI_CNCT_INF *				f_pCnctInf,
	unsigned int					f_ulBufferLen,
	unsigned char *					f_pbyBuffer,
	unsigned int					f_ulOffset,
	unsigned char					f_byPktFormat,
	tOCTVOCNET_PKT_DATA_F_HEADER *	f_pDataFHeader )
{
	int					iRc = 0;
	tPKTAPI_PKT_INF *	pDataPktInf = NULL;

	f_pCnctInf->Stats.ulTotalPktRecvCnt++;

	/* Get an data packet */
	pDataPktInf = PktApiPktQueueGet(
						cPKTAPI_Q_FREE,
						&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA] );

	if ( NULL != pDataPktInf )
	{
		/* Prepare event packet */
		pDataPktInf->RecvParms.RcvPktType				= cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA;
		pDataPktInf->RecvParms.Info.Data.ulPktFormat	= (tOCT_UINT32)f_byPktFormat;
		pDataPktInf->RecvParms.Info.Data.ulPktSubType	= (f_pDataFHeader->ulSubType & 0xF);

		f_pInst->Stats.ulTotalPktRecvDataCnt++;
		f_pCnctInf->Stats.ulTotalPktRecvDataCnt++;

		/* Copy payload */
		pDataPktInf->RecvParms.ulRcvPayloadLength = f_ulBufferLen - f_ulOffset;

		/* Copy payload (adjust copy length to avoid corruption) */
		memcpy( pDataPktInf->RecvParms.pPayload,
			f_pbyBuffer+f_ulOffset,
			mMIN( pDataPktInf->RecvParms.ulRcvPayloadLength, pDataPktInf->RecvParms.ulMaxPayloadLength ) );

		/* Set owners */
		pDataPktInf->RecvParms.pConnection	= (tPOCTVC1_PKT_API_CNCT)f_pCnctInf;
		pDataPktInf->RecvParms.pSession		= NULL;
		pDataPktInf->RecvParms.pUserConnectionContext	= f_pCnctInf->pUserContext;
		pDataPktInf->RecvParms.pUserSessionContext		= NULL;

		/* Ready post in busy Q */
		PktApiPktQueuePutAndSignal(
						cPKTAPI_Q_BUSY,
						&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA],
						pDataPktInf );
		iRc = 1;
	}
	else
	{
		f_pInst->Stats.ulTotalPktDropCnt++;
		f_pInst->Stats.ulTotalPktDropDataCnt++;		
		f_pCnctInf->Stats.ulTotalPktDropCnt++;
		f_pCnctInf->Stats.ulTotalPktDropDataCnt++;
	}

	return iRc;
}

/*--------------------------------------------------------------------------
	_PktApiHandleEventPkt
----------------------------------------------------------------------------*/
static int _PktApiHandleEventPkt(
	tPKTAPI_INST_INF *				f_pInst,
	tPKTAPI_CNCT_INF *				f_pCnctInf,
	unsigned int					f_ulBufferLen,
	unsigned char *					f_pbyBuffer,
	unsigned int					f_ulOffset,
	tOCTVOCNET_PKT_DATA_F_HEADER *	f_pDataFHeader,
	tOCTVC1_EVENT_HEADER *			f_pEventHeader )
{
	tPKTAPI_PKT_INF *	pEvtPktInf = NULL;

	f_pCnctInf->Stats.ulTotalPktRecvCnt++;

	/* Test if this is an event tag for our session */
	if( f_pDataFHeader->VocNetHeader.ulLogicalObjPktPort == cOCTVOCNET_PKT_DATA_LOGICAL_OBJ_PKT_PORT_EVENT_SESSION )
	{
		unsigned int		ulSessionIndex;
		tPKTAPI_SESS_INF *	pSessInf = NULL;

		/* Test for broadcast session */
		if( f_pDataFHeader->VocNetHeader.ulDestFifoId == 0 )
		{
			if( f_pCnctInf->Stats.ulOpenSessionCnt )
				ulSessionIndex = 0;
			else	/* make it to drop */
				ulSessionIndex = f_pCnctInf->ulSessCnt+1;
		}
		else 
			ulSessionIndex = mPKTAPI_SESS_HANDLE_GET_INDEX( f_pDataFHeader->VocNetHeader.ulDestFifoId );

		if ( f_pCnctInf->ulSessCnt > ulSessionIndex )
		{
			/* Find the session */
			pSessInf = &f_pCnctInf->paSessInf[ulSessionIndex];

			/* Be sure it's the same .. or broadcast session */
			if ( ( pSessInf->hSession != f_pDataFHeader->VocNetHeader.ulDestFifoId ) &&
				 ( 0 != f_pDataFHeader->VocNetHeader.ulDestFifoId ) )
				pSessInf = NULL;
		}

		if( pSessInf == NULL )
			goto dropEvent;	
		else if( f_pEventHeader->ulLength > (f_ulBufferLen - f_ulOffset) )	// Test if the recv evt size is ok
				pSessInf->Stats.ulPktInvalidCnt++;

	}

	// Test if the recv evt size is ok
	if( f_pEventHeader->ulLength > (f_ulBufferLen - f_ulOffset) )
	{
		f_pInst->Stats.ulTotalPktInvalidCnt++;
		f_pCnctInf->Stats.ulTotalPktInvalidCnt++;
		goto dropEvent;
	}


	/* Get an event packet */
	pEvtPktInf = PktApiPktQueueGet(
						cPKTAPI_Q_FREE,
						&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT] );

	if ( NULL != pEvtPktInf )
	{
		/* Prepare event packet */
		pEvtPktInf->RecvParms.RcvPktType				= cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT;
		pEvtPktInf->RecvParms.Info.Evt.ulEvtId			= f_pEventHeader->ulEventId;
		pEvtPktInf->RecvParms.Info.Evt.ulUserEvtId		= f_pEventHeader->ulUserEventId;

		memcpy( &pEvtPktInf->RecvParms.Info.Evt.hLogicalObj,
			&f_pDataFHeader->VocNetHeader.hLogicalObj,
			sizeof(f_pDataFHeader->VocNetHeader.hLogicalObj) );

		f_pInst->Stats.ulTotalPktRecvEventCnt++;
		f_pCnctInf->Stats.ulTotalPktRecvEventCnt++;

		pEvtPktInf->RecvParms.Info.Evt.ulLogicalObjPktPort	= f_pDataFHeader->VocNetHeader.ulLogicalObjPktPort;
		pEvtPktInf->RecvParms.Info.Evt.ulDestFifoId			= f_pDataFHeader->VocNetHeader.ulDestFifoId;
		pEvtPktInf->RecvParms.Info.Evt.ulTimestamp			= f_pDataFHeader->ulTimestamp;

		/* Copy payload */
		/* Consider lenght as defined in the event header */
		pEvtPktInf->RecvParms.ulRcvPayloadLength = mMIN( f_pEventHeader->ulLength, f_ulBufferLen - f_ulOffset );

		/* Copy payload (adjust copy length to avoid corruption) */
		memcpy( pEvtPktInf->RecvParms.pPayload,
				f_pbyBuffer + f_ulOffset,
				mMIN( pEvtPktInf->RecvParms.ulRcvPayloadLength, pEvtPktInf->RecvParms.ulMaxPayloadLength ) );

		/* Set owners */
		pEvtPktInf->RecvParms.pConnection	= (tPOCTVC1_PKT_API_CNCT)f_pCnctInf;
		pEvtPktInf->RecvParms.pSession		= NULL;
		pEvtPktInf->RecvParms.pUserConnectionContext	= f_pCnctInf->pUserContext;
		pEvtPktInf->RecvParms.pUserSessionContext		= NULL;

		/* Ready post in busy Q */
		PktApiPktQueuePutAndSignal(
						cPKTAPI_Q_BUSY,
						&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT],
						pEvtPktInf );

		return 1;
	}

dropEvent:

	f_pInst->Stats.ulTotalPktDropCnt++;
	f_pInst->Stats.ulTotalPktDropEventCnt++;
	f_pCnctInf->Stats.ulTotalPktDropCnt++;
	f_pCnctInf->Stats.ulTotalPktDropEventCnt++;

	return 0;
}


/*--------------------------------------------------------------------------
	_PktApiFindPktInAllQ
----------------------------------------------------------------------------*/
tPKTAPI_PKT_INF *_PktApiFindPktInAllQ(tPKTAPI_INST_INF * f_pInst, tOCT_UINT32 f_ulSessionId, tOCT_UINT32 f_ulTransactionId )
{
	tPKTAPI_PKT_INF *	pCmdPktInf = NULL;
	unsigned int i;

	/* Find out the transaction in one of the command Q*/
	for ( i=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD; i<f_pInst->ulPktQCnt;i++ )
	{
		pCmdPktInf = PktApiPktQueueExtract(
								( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == i ) ? cPKTAPI_Q_BUSY:cPKTAPI_Q_SPECIAL,
								&f_pInst->paPktQ[i],
								f_ulSessionId,
								f_ulTransactionId );

		if ( NULL != pCmdPktInf )
			break;
	}
	return pCmdPktInf;
}


/*--------------------------------------------------------------------------
	PktApiFindMinPendingTransactionId
----------------------------------------------------------------------------*/
tOCT_BOOL32 PktApiFindMinPendingTransactionId( tPKTAPI_INST_INF * f_pInst, tPKTAPI_SESS_INF *	f_pSessInf )
{
	unsigned int	ulQMinTransactionId;
	unsigned int	ulMinTransactionId;
	unsigned int	ulIndex;

	ulMinTransactionId = 0xFFFFFFFF;

	for( ulIndex=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD; ulIndex<f_pInst->ulPktQCnt; ulIndex++ )
	{
		ulQMinTransactionId = PktApiPktQueueMinTransactionIdGet(
								( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == ulIndex )? cPKTAPI_Q_BUSY:cPKTAPI_Q_SPECIAL,
								&f_pInst->paPktQ[ulIndex],
								f_pSessInf->hSession );

		if ( ulQMinTransactionId && ulQMinTransactionId < ulMinTransactionId )
		{
			ulMinTransactionId = ulQMinTransactionId;
		}
	}
	if( ulMinTransactionId != 0xFFFFFFFF )
	{
		f_pSessInf->ulRxTransactionId = ulMinTransactionId;
		return cOCT_TRUE;
	}
	else
	{
		/* Nothing pending, set next expected transaction */
		f_pSessInf->ulRxTransactionId = f_pSessInf->ulTransactionId;

		f_pSessInf->fFlag &= ~( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | 
				cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT |
				cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION |
				cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION );

	}
	return cOCT_FALSE;
}

/*--------------------------------------------------------------------------
	_PktApiHandleRejectPkt
----------------------------------------------------------------------------*/
static int _PktApiHandleRejectPkt(
	tPKTAPI_INST_INF *				f_pInst,
	tPKTAPI_CNCT_INF *				f_pCnctInf,
	unsigned int					f_ulBufferLen,
	unsigned char *					f_pbyBuffer,
	unsigned int					f_ulOffset,
	tOCTVOCNET_PKT_CTL_HEADER *		f_pCtlHeader,
	tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV *			f_pRejectHeader )
{
	unsigned int		ulSessionIndex;

	f_pInst->Stats.ulTotalPktRejectCnt++;

	/* Be sure we have a connection for a response */
	ulSessionIndex = mPKTAPI_SESS_HANDLE_GET_INDEX( f_pRejectHeader->Header.ulSessionId );


	if ( NULL != f_pCnctInf && f_pCnctInf->ulSessCnt > ulSessionIndex )
	{
		tPKTAPI_SESS_INF *	pSessInf;

		f_pCnctInf->Stats.ulTotalPktRejectCnt++;
		f_pCnctInf->Stats.ulTotalPktRecvCnt++;

		/* Find the session */
		pSessInf = &f_pCnctInf->paSessInf[ulSessionIndex];

		/* Be sure it's the same */
		if ( pSessInf->hSession == f_pRejectHeader->Header.ulSessionId )
		{
			tOCT_UINT32	ulRetransmitCnt;
			tOCT_UINT32	ulRetransmitIndex;
			tOCT_UINT32	ulRetransmitStart;
			tOCT_UINT32	ulRetransmitEnd;
			tOCT_BOOL32 fResync = cOCT_FALSE;			
			tOCT_BOOL32 fForceResyncOnError = cOCT_FALSE;

			/* Lock the session */
			mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );

			/* Increment stat */
			pSessInf->Stats.ulPktRejectCnt++;
			pSessInf->Stats.ulPktRecvCnt++;

			/* One (or more) command has been lost, prepare the range of command to retransmit */
			ulRetransmitStart = f_pRejectHeader->ulExpectedTransactionId;
			ulRetransmitEnd	 = f_pRejectHeader->Header.ulTransactionId;

			if( ulRetransmitStart > ulRetransmitEnd )
				fForceResyncOnError = cOCT_TRUE;

			/* If rejecting the resent ... No need to retransmit ... let timeout occurs */
			if( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION ) &&
				/* Test if never received resend */
				( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_DID_RESEND ) == 0 ) &&
				( f_pRejectHeader->Header.ulTransactionId == pSessInf->ulResentId ) )
			{

				tPKTAPI_PKT_INF *pCmdPktInf = _PktApiFindPktInAllQ( f_pInst, f_pRejectHeader->Header.ulSessionId, 
							pSessInf->ulResentId );

				/* Simulate Timeout to user */
				if( pCmdPktInf )
					_PktApiMsgTimeoutSet( f_pInst, pCmdPktInf );

				/* did reject pSessInf->ulResentId .. MGW does not support resend .. < 1.5 */
				pSessInf->fFlag &= ~(cPKTAPI_SESS_INF_FLAG_MASK_ALLOW_RESEND);

				/* Find next transaction id .. min of all session pending response */
				PktApiFindMinPendingTransactionId(f_pInst, pSessInf );
			}
			else
			{

				/* Test if bigger than window */
				if( ( ulRetransmitEnd - ulRetransmitStart ) > cPKTAPI_SESS_PENDING_RSP_MAX )
				{
					/* Set to resend up to rejected transaction */
					if( ulRetransmitEnd < cPKTAPI_SESS_PENDING_RSP_MAX )
						ulRetransmitStart = 1;
					else
						ulRetransmitStart = ulRetransmitEnd - cPKTAPI_SESS_PENDING_RSP_MAX;

					/* Force to resync */
					fResync = cOCT_TRUE;
				}

				/* Are we in a reject procedure */
				if( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION ) &&
					( ulRetransmitStart < pSessInf->ulRxRejectId ) &&
					( ulRetransmitEnd > pSessInf->ulRxRejectId ) )
				{
					ulRetransmitStart = pSessInf->ulRxRejectId+1;
					fResync = cOCT_FALSE;
				}
				ulRetransmitCnt = (ulRetransmitEnd-ulRetransmitStart)+1;

				/* Loop from start */
				ulRetransmitIndex=ulRetransmitStart;
				while( ulRetransmitCnt )
				{
					tPKTAPI_PKT_INF *	pCmdPktInf = NULL;

					pCmdPktInf = _PktApiFindPktInAllQ( f_pInst, f_pRejectHeader->Header.ulSessionId, 
												ulRetransmitIndex );

					if ( NULL != pCmdPktInf )
					{
						tOCT_UINT32	Result;

						if( fResync )
							pCmdPktInf->ulFlag |= cPKTAPI_PKT_INF_FLAG_MASK_RESYNC;
						fResync = cOCT_FALSE;
						fForceResyncOnError = cOCT_FALSE;

						/* set retransmit */
						pCmdPktInf->ulFlag |= cPKTAPI_PKT_INF_FLAG_MASK_RETRANSMIT;

						/* Re-submit the packet */
						Result = PktApiCnctPktSend(
										pSessInf->pCnct,
										( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == pCmdPktInf->ulOwnerQ )
											? cPKTAPI_Q_BUSY : cPKTAPI_Q_SPECIAL,
										pCmdPktInf->ulOwnerQ,
										cOCTVOCNET_PKT_FORMAT_CTRL,
										pCmdPktInf ); 

						if ( cOCTVC1_PKT_API_RC_OK != Result )
						{
							/* Have to return packet to user with response indicating error */
							pCmdPktInf->RecvParms.RcvPktType			= cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
							pCmdPktInf->RecvParms.ulRcvPayloadLength	= 0;
							pCmdPktInf->RecvParms.Info.Rsp.ulReturnCode	= cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

							/* This cmd is no more in Mgw */
							if( pSessInf->ulPendingRspCount > 0 )
							{
								pSessInf->ulPendingRspCount--;
								_PktApiActiveTimeoutSet( pCmdPktInf, cOCT_FALSE );
							}
							else
								pSessInf->ulActiveTimeout = 0;

							/* Post in Q */
							PktApiPktQueuePut(
										cPKTAPI_Q_BUSY,
										( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == pCmdPktInf->ulOwnerQ )
											?&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP]
											:&f_pInst->paPktQ[pCmdPktInf->ulOwnerQ], pCmdPktInf );
						}
						else
						{
							pSessInf->Stats.ulPktRetryCnt++;
							pSessInf->Stats.ulPktSentCnt++;
							pSessInf->pCnct->Stats.ulTotalPktRetryCnt++;
							f_pInst->Stats.ulTotalPktRetryCnt++;

							/* Do not modif if does not expect response */
							if( ( pCmdPktInf->RecvParms.Info.Rsp.ulCmdId & cOCTVC1_MSG_NO_RESPONSE_FLAG ) == 0 )
							{
								/* Set a rejecting procedure */
								pSessInf->ulRxRejectId = pCmdPktInf->ulTransactionId;
								pSessInf->fFlag |= ( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | 
											cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION );

							}
						}
					}
					else
					{
						/* Test if the expected one is not in the list */
						/* It is possible thas:
							We sent trans_1(with resync), trans_2 
							MGW miss trans_1, rsp to trans_2, 
							We resend trans_1(with resync)... MGW rsp to trans_1
							We send trans_3 ... MGW reject trans_3 expected trans_2
							We can't find trans trans_2 and resync to trans_3 */							
						if( fForceResyncOnError || (ulRetransmitIndex==ulRetransmitStart ) )
							fResync = cOCT_TRUE;

					}
					ulRetransmitIndex++;
					ulRetransmitCnt--;
				}
			}

			/* We did not sent anything and there is nothing expected */
			if( pSessInf->ulPendingRspCount == 0 )
			{
				pSessInf->fFlag &= ~( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | 
								cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION );

				pSessInf->ulActiveTimeout = 0;
				_PktApiSendingPending( pSessInf );
			}

			/* Release the session */
			mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );
		}
	}

	/* Did not recv a response */
	return 0;
}


/*--------------------------------------------------------------------------
	_PktApiHandleResponsePkt
----------------------------------------------------------------------------*/
static int _PktApiHandleResponsePkt(
	tPKTAPI_INST_INF *				f_pInst,
	tPKTAPI_CNCT_INF *				f_pCnctInf,
	unsigned char *					f_pbySrcAddr,
	unsigned int					f_ulBufferLen,
	unsigned char *					f_pbyBuffer,
	unsigned int					f_ulOffset,
	tOCTVOCNET_PKT_CTL_HEADER *		f_pCtlHeader,
	tOCTVC1_MSG_HEADER *			f_pMsgHeader )
{
	int					iRc = 0;
	unsigned int		ulSessionIndex;

	/* Be sure we have a connection for a response */
	ulSessionIndex = mPKTAPI_SESS_HANDLE_GET_INDEX( f_pMsgHeader->ulSessionId );

	if ( NULL != f_pCnctInf && f_pCnctInf->ulSessCnt > ulSessionIndex )
	{
		tPKTAPI_SESS_INF *	pSessInf;

		f_pCnctInf->Stats.ulTotalPktRecvCnt++;
		/* Find the session */
		pSessInf = &f_pCnctInf->paSessInf[ulSessionIndex];

		/* Be sure it's the same */
		if ( pSessInf->hSession == f_pMsgHeader->ulSessionId )
		{
			/* User info is set with the Q identifier and make sure that recv response size is ok */
			if ( ( f_pMsgHeader->ulUserInfo < f_pInst->ulPktQCnt ) &&
				 ( f_pMsgHeader->ulLength <= (f_ulBufferLen - f_ulOffset) ) )
			{
				unsigned int		ulRspQ;
				tPKTAPI_PKT_INF *	pCmdPktInf = NULL;
				tPKTAPI_PKT_INF *	pRspPktInf = NULL;

				pSessInf->Stats.ulPktRecvCnt++;

				/* Retrieve the cmd packet. From busy Q if standard cmd, or from the special Q if
				synchronous command */
				pCmdPktInf = PktApiPktQueueExtract(
										( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == f_pMsgHeader->ulUserInfo )
											?cPKTAPI_Q_BUSY
											:cPKTAPI_Q_SPECIAL,
										&f_pInst->paPktQ[f_pMsgHeader->ulUserInfo],
										f_pMsgHeader->ulSessionId,
										f_pMsgHeader->ulTransactionId );

				if ( NULL != pCmdPktInf )
				{
					tOCTVC1_MSG_HEADER *		pMsgHeader;


					/* Decrement packet dependency count */
					mOCTOSAL_ASSERT( (pCmdPktInf->ulFlag & cPKTAPI_PKT_INF_FLAG_MASK_DEPENDENCY_CNT) > 0 );
					pCmdPktInf->ulFlag--;
					/* Do we have to keep the packet in Q for further responses (discover) ? */
					if ( pCmdPktInf->ulFlag & cPKTAPI_PKT_INF_FLAG_MASK_DEPENDENCY_CNT )
					{
						tPKTAPI_PKT_INF *	pDuplicatePktInf = NULL;
						/* Get a free packet from the same Q and use it */
						pDuplicatePktInf = PktApiPktQueueGet(
												cPKTAPI_Q_FREE,
												&f_pInst->paPktQ[f_pMsgHeader->ulUserInfo] );

						if ( NULL != pDuplicatePktInf )
						{
							void *	pDuplicatePayload;

							/* Keep payload pointer of the duplicated packet */
							pDuplicatePayload = pDuplicatePktInf->RecvParms.pPayload;

							/* Copy required info in the duplicated packet */
							memcpy( &pDuplicatePktInf->RecvParms, &pCmdPktInf->RecvParms, sizeof(pCmdPktInf->RecvParms) );
							pDuplicatePktInf->ulStartTimeMs = pCmdPktInf->ulStartTimeMs;

							/* copy back payload pointer */
							pDuplicatePayload = pDuplicatePktInf->RecvParms.pPayload = pDuplicatePayload;

							/* Re-post the original command in its waiting Q */
							PktApiPktQueuePut(
										( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == f_pMsgHeader->ulUserInfo )
											?cPKTAPI_Q_BUSY
											:cPKTAPI_Q_SPECIAL,
										&f_pInst->paPktQ[f_pMsgHeader->ulUserInfo],
										pCmdPktInf );

							/* Use duplicate packet as cmd packet */
							pCmdPktInf = pDuplicatePktInf;
						}
						else
						{
							/* Too many response for that dependency, clear dependency */
							pCmdPktInf->ulFlag &= ~cPKTAPI_PKT_INF_FLAG_MASK_DEPENDENCY_CNT;
						}
					}

					/* the command should be in that Q */
					if ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == f_pMsgHeader->ulUserInfo )
					{
						/*
							Little twist with packet in Q.
							Use the packet from the cmd Q and place it in the rsp Q.
							Release packet will take care of returning the packet to the initial
							owner Q
						*/

						/* Prepare mail address */
						pRspPktInf	= pCmdPktInf;
						pCmdPktInf	= NULL;
						ulRspQ		= cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
					}
					else
					{
						/* Sync cmd Q or discover */
						/* Prepare mail address */
						pRspPktInf	= pCmdPktInf;
						pCmdPktInf	= NULL;
						ulRspQ		= f_pMsgHeader->ulUserInfo;
					}

					/* Prepare the response */
					/* Be sure packet type is set correctly */
					pRspPktInf->RecvParms.RcvPktType = cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
					pRspPktInf->RecvParms.ulRcvPayloadLength = mMIN( f_pMsgHeader->ulLength, f_ulBufferLen - f_ulOffset );
					if ( pRspPktInf->RecvParms.ulRcvPayloadLength )
					{
						/* Copy payload (adjust copy length to avoid corruption) */
						memcpy( pRspPktInf->RecvParms.pPayload,
								f_pbyBuffer + f_ulOffset,
								mMIN( pRspPktInf->RecvParms.ulRcvPayloadLength, pRspPktInf->RecvParms.ulMaxPayloadLength ) );
					}

					pRspPktInf->RecvParms.Info.Rsp.ulReturnCode = f_pMsgHeader->ulReturnCode;
					/* Set back the userinfo (in msg header) */
					pMsgHeader = (tOCTVC1_MSG_HEADER *)pRspPktInf->RecvParms.pPayload;
					/* WARNING: pPayload not aligned */
					memcpy( &pMsgHeader->ulUserInfo, &pRspPktInf->ulUserInfo, sizeof(pMsgHeader->ulUserInfo) );

					/* Following fields already present */
					/*
					pRspPktInf->RecvParms.Info.Rsp.ulCmdId;
					pRspPktInf->RecvParms.Info.Rsp.pUserCmdContext;
					*/

					/* Round trip */
					pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(), pRspPktInf->ulStartTimeMs );
					pRspPktInf->RecvParms.Info.Rsp.ulExtractTimeMs = OctOsalGetTimeMs();

					if ( pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs )
					{
						/* Update instance round trip stats */
						if ( 0 == f_pInst->Stats.ulLowestRoundTripMs || pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs < f_pInst->Stats.ulLowestRoundTripMs )
						{
							f_pInst->Stats.ulLowestRoundTripMs = pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs;
						}
						if ( 0 == f_pInst->Stats.ulHighestRoundTripMs || pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs > f_pInst->Stats.ulHighestRoundTripMs )
						{
							f_pInst->Stats.ulHighestRoundTripMs = pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs;
						}

						/* Update connection round trip stats */
						if ( 0 == f_pCnctInf->Stats.ulLowestRoundTripMs || pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs < f_pCnctInf->Stats.ulLowestRoundTripMs )
						{
							f_pCnctInf->Stats.ulLowestRoundTripMs = pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs;
						}
						if ( 0 == f_pCnctInf->Stats.ulHighestRoundTripMs || pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs > f_pCnctInf->Stats.ulHighestRoundTripMs )
						{
							f_pCnctInf->Stats.ulHighestRoundTripMs = pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs;
						}
						/* Update session round trip stats */
						if ( 0 == pSessInf->Stats.ulLowestRoundTripMs || pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs < pSessInf->Stats.ulLowestRoundTripMs )
						{
							pSessInf->Stats.ulLowestRoundTripMs = pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs;
						}
						if ( 0 == pSessInf->Stats.ulHighestRoundTripMs || pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs > pSessInf->Stats.ulHighestRoundTripMs )
						{
							pSessInf->Stats.ulHighestRoundTripMs = pRspPktInf->RecvParms.Info.Rsp.ulRoundTripMs;
						}
					}

					/* If discover packet, add the source MAC address after the payload */
					if( cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER == f_pMsgHeader->ulUserInfo
						&&
						pRspPktInf->RecvParms.ulMaxPayloadLength - pRspPktInf->RecvParms.ulRcvPayloadLength >= cOCTVC1_PKT_API_MAC_ADDR_SIZE_DWORD_ALIGN )
					{
						int iOffset = (cOCT_FALSE == f_pInst->fUseExternalTransport) ? cOCTVC1_PKT_API_MAC_ADDR_SIZE_DWORD_ALIGN : cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE;
						

						memmove(
								(unsigned char*)pRspPktInf->RecvParms.pPayload + iOffset,
								(unsigned char*)pRspPktInf->RecvParms.pPayload,
								pRspPktInf->RecvParms.ulRcvPayloadLength );
						/* Copy source MAC to begining of structure */
						memcpy(
								(unsigned char*)pRspPktInf->RecvParms.pPayload,
								f_pbySrcAddr,
								iOffset );
						pRspPktInf->RecvParms.ulRcvPayloadLength += iOffset;

					}

					/* Ready, put it in the response Q */
					PktApiPktQueuePutAndSignal(
								cPKTAPI_Q_BUSY,
								&f_pInst->paPktQ[ulRspQ],
								pRspPktInf );

					iRc = 1;


					/* Decrement number of pending response when not discover special pkt ..*/
					if ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER != f_pMsgHeader->ulUserInfo )
					{
						/* Lock the session */
						mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );


						/* This session juste recv a response ... is there pending Cmd */
						_PktApiActiveTimeoutSet( pRspPktInf, cOCT_FALSE );

						/* Rcv Rsp ... allow tx new cmd */
						if( pSessInf->ulPendingRspCount > 0 )
							pSessInf->ulPendingRspCount--;

						if( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_ALLOW_RESEND ) &&
							/* Test if not in timeout procedure */
							(( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT) == 0 ) &&
							/* Is this the expected response */
							( f_pMsgHeader->ulTransactionId != pSessInf->ulRxTransactionId ) )
						{
							tPKTAPI_PKT_INF *	pCmdPktInf = NULL;

							/* Did we recv the expected response */
							if( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION ) &&
								( pSessInf->ulResentId == f_pMsgHeader->ulTransactionId ) )
							{
								/* Enable resend ... reject will not disable it */
								pSessInf->fFlag |= cPKTAPI_SESS_INF_FLAG_MASK_DID_RESEND;

								/* Find next transaction id .. min of all session pending response */
								if( PktApiFindMinPendingTransactionId(f_pInst, pSessInf ) )
								{
									/* There is pending .. keep session flag */
									pSessInf->ulResentId = pSessInf->ulRxTransactionId;
								}
							}
							else
							{
								/* Resend the expected one */
								pCmdPktInf = _PktApiFindPktInAllQ( f_pInst, pSessInf->hSession, 
											pSessInf->ulRxTransactionId );

								/* Do not modif if does not expect response */
								if( NULL != pCmdPktInf )
								{
									while( pCmdPktInf->RecvParms.Info.Rsp.ulCmdId & cOCTVC1_MSG_NO_RESPONSE_FLAG )
									{
										/* Timeout this one ... it will return ok */
										_PktApiMsgTimeoutSet( f_pInst, pCmdPktInf );

										PktApiFindMinPendingTransactionId(f_pInst, pSessInf );

										/* Test if next expected is expected */
										if( pSessInf->ulRxTransactionId < f_pMsgHeader->ulTransactionId )
											pCmdPktInf = _PktApiFindPktInAllQ( f_pInst, pSessInf->hSession, 
															pSessInf->ulRxTransactionId );
										else
										{
											pCmdPktInf = NULL;
											break;
										}
									}
								}


								if ( NULL != pCmdPktInf )
								{
									tOCT_UINT32	Result;

									/* Get ready for next Rsp */
									PktApiFindMinPendingTransactionId(f_pInst, pSessInf );

									/* Make sure not tx until recv this one */
									pSessInf->fFlag |= cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING;

									/* Specify we resend for this transaction .. if not already resending*/ 
									if( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION ) == 0 )
									{
										pSessInf->fFlag |= cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION;
										pSessInf->ulResentId = pCmdPktInf->ulTransactionId;
									}

									/* Set for retransmit */
									pCmdPktInf->ulFlag |= cPKTAPI_PKT_INF_FLAG_MASK_RETRANSMIT;

									/* Re-submit the missing command */
									Result = PktApiCnctPktSend(
													pSessInf->pCnct,
													( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == pCmdPktInf->ulOwnerQ )
														?cPKTAPI_Q_BUSY
														:cPKTAPI_Q_SPECIAL,
													pCmdPktInf->ulOwnerQ,
													cOCTVOCNET_PKT_FORMAT_CTRL,
													pCmdPktInf ); 

									if ( cOCTVC1_PKT_API_RC_OK != Result )
									{
										/* Have to return packet to user with response indicating error */
										pCmdPktInf->RecvParms.RcvPktType			= cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP;
										pCmdPktInf->RecvParms.ulRcvPayloadLength	= 0;
										pCmdPktInf->RecvParms.Info.Rsp.ulReturnCode	= cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

										/* This cmd is no more in Mgw */
										if( pSessInf->ulPendingRspCount > 0 )
										{
											pSessInf->ulPendingRspCount--;
											_PktApiActiveTimeoutSet( pCmdPktInf, cOCT_FALSE );
										}
										else
											pSessInf->ulActiveTimeout = 0;

										pSessInf->fFlag &= ~( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING | 
															cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION );

										/* Post in Q */
										PktApiPktQueuePutAndSignal(
													cPKTAPI_Q_BUSY,
													( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == pCmdPktInf->ulOwnerQ )
														?&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP]
														:&f_pInst->paPktQ[pCmdPktInf->ulOwnerQ],
													pCmdPktInf );

									}
									else
									{
										pSessInf->Stats.ulPktRetryCnt++;
										pSessInf->Stats.ulPktSentCnt++;
										pSessInf->pCnct->Stats.ulTotalPktRetryCnt++;
										f_pInst->Stats.ulTotalPktRetryCnt++;

										/* Set new timeout for this cmd */
										pCmdPktInf->ulStartTimeMs = OctOsalGetTimeMs();
										pCmdPktInf->ulTimeoutMs = pSessInf->ulActiveTimeout;

									}
								}
								else
								{
									/* Can't find the expected .. may be rsp during rety procedure .. see if 
										special procedure still on. Get ready for next Rsp */
									PktApiFindMinPendingTransactionId(f_pInst, pSessInf );
								}
							}
						}
						else
						{
							/* Did we recv the expected response */
							if( ( pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION ) &&
								( pSessInf->ulResentId == f_pMsgHeader->ulTransactionId ) )
							{
								/* Enable resend ... reject will not disable it */
								pSessInf->fFlag |= cPKTAPI_SESS_INF_FLAG_MASK_DID_RESEND;

								/* Find next transaction id .. min of all session pending response */
								if( PktApiFindMinPendingTransactionId(f_pInst, pSessInf ) )
								{
									/* There is pending .. keep session flag */
									pSessInf->ulResentId = pSessInf->ulRxTransactionId;
								}
							}
							else	/* Get ready for next Rsp */							
								pSessInf->ulRxTransactionId = f_pMsgHeader->ulTransactionId+1;

							/* Chck if we are in special state (Timeout or retry or reject) and we do not expect anything */
							if( pSessInf->ulPendingRspCount == 0 )
							{
								pSessInf->fFlag &= ~( cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING |
												cPKTAPI_SESS_INF_FLAG_MASK_RESENDING_TRANSACTION |
												cPKTAPI_SESS_INF_FLAG_MASK_REJECTING_TRANSACTION |
												cPKTAPI_SESS_INF_FLAG_MASK_RETRANSMIT_ON_TIOUT );
								pSessInf->ulActiveTimeout = 0;
								pSessInf->ulRxTransactionId = pSessInf->ulTransactionId;
							}
						}

						/* unlock the session */
						mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );
					}
				}
				else
				{
					pSessInf->Stats.ulPktLateRspCnt++;
					f_pCnctInf->Stats.ulTotalPktLateRspCnt++;
					f_pInst->Stats.ulTotalPktLateRspCnt++;
				}


				/* Lock the session */
				mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );

				/* May have to send pending cmd */
				_PktApiSendingPending( pSessInf );

				/* Unlock the session */
				mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );


			}
			else
			{
				pSessInf->Stats.ulPktInvalidCnt++;
				f_pCnctInf->Stats.ulTotalPktInvalidCnt++;
				f_pInst->Stats.ulTotalPktInvalidCnt++;
			}
		}
		else
		{
			f_pCnctInf->Stats.ulTotalPktInvalidCnt++;
			f_pInst->Stats.ulTotalPktInvalidCnt++;
		}
	}
	return iRc;
}


/*--------------------------------------------------------------------------
	_PktApiInstHandleRecvPkt
----------------------------------------------------------------------------*/
static int _PktApiInstHandleRecvPkt(
	tPKTAPI_INST_INF *				f_pInst,
	unsigned int					f_ulBufferLen,
	unsigned char *					f_pbyBuffer,
	tOCTTRANSAPI_DESTINATION_HANDLE	f_hTransDest,
	unsigned char *					f_pszDestinationAddr )
{
	int						iRc = 0;
	unsigned int			ulVocNetPktHdrOffset;
	unsigned int			ulIndex;
	unsigned int			ulAdjustedBufferLen;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;
	unsigned char *			pbyDestAddr = NULL;

	tOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_ENUM	ulOctVocNetPktCtrlType;
	unsigned int			ulOctVocNetPktLen;
	unsigned int			ulOctVocNetPktFormat;
	unsigned int			ulOctVocNetPktHdrSize;


	/* One more packet received */
	f_pInst->Stats.ulTotalPktRecvCnt++;

	/* Check for Vocallo EtherType */
	if( !f_pInst->fUseExternalTransport )
	{
		if ( f_pbyBuffer[12] != ((cOCTVOCNET_PKT_ETHERTYPE>>8) & 0xff)
			||
			f_pbyBuffer[13] != ((cOCTVOCNET_PKT_ETHERTYPE) & 0xff) )
		{
			f_pInst->Stats.ulTotalPktInvalidCnt++;
			return 0;
		}
		/* Set the initial offset (skip src+dst MAC and EtherType) */
		ulVocNetPktHdrOffset = cPKTAPI_ETH_II_HEADER_SIZE;

		/* VocalloNet Packet */
		/* It is the Vocallo EtherType; this is a VocalloNet Packet */
		pbyDestAddr = &f_pbyBuffer[cOCTVC1_PKT_API_MAC_ADDR_SIZE];

		/* find out the connection */
		for ( ulIndex=0; ulIndex<f_pInst->ulCnctCnt; ulIndex++ )
		{
			if ( 0 == memcmp( f_pInst->paCnctInf[ulIndex].abyRemoteMac,
								pbyDestAddr,
								cOCTVC1_PKT_API_MAC_ADDR_SIZE ) )
			{
				pCnctInf = &f_pInst->paCnctInf[ulIndex];
				break;
			}
		}
		/* Try with the discover connection */
		if(( pCnctInf == NULL ) && ( 0 != f_pInst->DiscoverCnct.Stats.ulOpenSessionCnt ) )
		{
			pCnctInf = &f_pInst->DiscoverCnct;
		}
	}
	else
	{
		if( f_hTransDest )
		{
			/* find out the connection */
			for ( ulIndex=0; ulIndex<f_pInst->ulCnctCnt; ulIndex++ )
			{
				if ( f_hTransDest == f_pInst->paCnctInf[ulIndex].hTransDest )
				{
					pCnctInf = &f_pInst->paCnctInf[ulIndex];
					break;
				}
			}
			if( pCnctInf == NULL )
			{
				/* Try with the discover connection */
				if ( f_hTransDest == f_pInst->DiscoverCnct.hTransDest )
					pCnctInf = &f_pInst->DiscoverCnct;
			}
			//if( pCnctInf  )
			ulVocNetPktHdrOffset = 0;

			pbyDestAddr = f_pszDestinationAddr;
		}
	}


	if ( NULL == pCnctInf )
	{
		f_pInst->Stats.ulTotalPktInvalidCnt++;
		return 0;
	}

	if( pCnctInf->ulPktHdrType ==  cOCTPKT_HDR_TYPE_ENUM_NORMAL )
	{
		tOCTVOCNET_PKT_HEADER PktHeader;
		/* Get vocnet packet header */
		memcpy( &PktHeader, (tOCTVOCNET_PKT_HEADER *)&f_pbyBuffer[ulVocNetPktHdrOffset], sizeof(PktHeader) );

		/* swap content */
		PktHeader.ul_Format_Trace_Length = mOCT_SWAP32_IF_LE(PktHeader.ul_Format_Trace_Length);
		/* Extract content */
		ulOctVocNetPktCtrlType = (( PktHeader.ul_Format_Trace_Length >> cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET ) & cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK );
		ulOctVocNetPktLen = (( PktHeader.ul_Format_Trace_Length >> cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET ) & cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK );
		ulOctVocNetPktFormat = (( PktHeader.ul_Format_Trace_Length >> cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET ) & cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK );
		ulOctVocNetPktHdrSize = sizeof(tOCTVOCNET_PKT_HEADER);

	}
	else
	{
		tOCTVOCNET_PKT_HEADER_XL PktHeaderXl;
		/* Get vocnet packet header .. make sure to be aligned */
		memcpy( &PktHeaderXl, (tOCTVOCNET_PKT_HEADER_XL *)&f_pbyBuffer[ulVocNetPktHdrOffset], sizeof(PktHeaderXl) );

		/* swap content */
		PktHeaderXl.ul_Proto_Format_Length = mOCT_SWAP32_IF_LE(PktHeaderXl.ul_Proto_Format_Length);
		/* Extract content */
		ulOctVocNetPktCtrlType = (( PktHeaderXl.ul_Proto_Format_Length >> cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET ) & cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK );
		ulOctVocNetPktLen = (( PktHeaderXl.ul_Proto_Format_Length >> cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET ) & cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK );
		ulOctVocNetPktFormat = (( PktHeaderXl.ul_Proto_Format_Length >> cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET ) & cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK );
		ulOctVocNetPktHdrSize = sizeof(tOCTVOCNET_PKT_HEADER_XL);
	}

	/* Is this the OCTVOCNET protocol type */
	if( ulOctVocNetPktCtrlType != cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTVOCNET )
	{
		f_pInst->Stats.ulTotalPktInvalidCnt++;
		pCnctInf->Stats.ulTotalPktInvalidCnt++;
		return 0;
	}

	/* Remove padding from size */
	ulAdjustedBufferLen = mMIN( f_ulBufferLen, ulOctVocNetPktLen + ulVocNetPktHdrOffset );

	/* Check the format */
	if ( cOCTVOCNET_PKT_FORMAT_CTRL == ulOctVocNetPktFormat )
	{
		/* Make sure it is an PKTAPI message - validate the destination SVP RX port */
		tOCTVOCNET_PKT_CTL_HEADER	CtlHdr;

		ulVocNetPktHdrOffset += ulOctVocNetPktHdrSize;

		memcpy( &CtlHdr,
				&f_pbyBuffer[ulVocNetPktHdrOffset],
				sizeof(CtlHdr));

		/* Swap control */
		CtlHdr.ulDestFifoId		= mOCT_SWAP32_IF_LE( CtlHdr.ulDestFifoId );
		CtlHdr.ulSourceFifoId	= mOCT_SWAP32_IF_LE( CtlHdr.ulSourceFifoId );
		CtlHdr.ulSocketId		= mOCT_SWAP32_IF_LE( CtlHdr.ulSourceFifoId );

		if ( cPKTAPI_FIFO_ID_MSG == CtlHdr.ulDestFifoId )
		{
			tOCTVC1_MSG_HEADER			MsgHeader;
			unsigned int				ulMsgType;
			unsigned int				ulCmdId;

			ulVocNetPktHdrOffset += sizeof(tOCTVOCNET_PKT_CTL_HEADER);

			memcpy( &MsgHeader,
					&f_pbyBuffer[ulVocNetPktHdrOffset],
					sizeof(MsgHeader) );
			/* Swap msg header */
			MsgHeader.ulLength			= mOCT_SWAP32_IF_LE( MsgHeader.ulLength			  );
			MsgHeader.ulTransactionId	= mOCT_SWAP32_IF_LE( MsgHeader.ulTransactionId	  );
			MsgHeader.ul_Type_R_CmdId	= mOCT_SWAP32_IF_LE( MsgHeader.ul_Type_R_CmdId	  );
			MsgHeader.ulSessionId		= mOCT_SWAP32_IF_LE( MsgHeader.ulSessionId		  );
			MsgHeader.ulReturnCode		= mOCT_SWAP32_IF_LE( MsgHeader.ulReturnCode		  );
			/* User info is from us, no need to swap */
			MsgHeader.ulUserInfo		= MsgHeader.ulUserInfo;

			ulMsgType = ( MsgHeader.ul_Type_R_CmdId >> cOCTVC1_MSG_TYPE_BIT_OFFSET ) & cOCTVC1_MSG_TYPE_BIT_MASK;
			ulCmdId = ( MsgHeader.ul_Type_R_CmdId >> cOCTVC1_MSG_ID_BIT_OFFSET ) & cOCTVC1_MSG_ID_BIT_MASK;

			/* Check if the packet is destinated to a DISCOVERY session */
			if ( cPKTAPI_SESS_HANDLE_DISCOVER_UNIQUE == mPKTAPI_SESS_HANDLE_GET_UNIQUE(MsgHeader.ulSessionId) )
			{
				/* Try with the discover connection */
				if ( 0 != f_pInst->DiscoverCnct.Stats.ulOpenSessionCnt )
				{
					if( !f_pInst->fUseExternalTransport ||
                        (f_pInst->fUseExternalTransport && f_pInst->DiscoverCnct.hTransDest) )
					pCnctInf = &f_pInst->DiscoverCnct;
				}
			}

			switch( ulMsgType )
			{
				case cOCTVC1_MSG_TYPE_RESPONSE:
					iRc = _PktApiHandleResponsePkt( f_pInst, pCnctInf, pbyDestAddr, ulAdjustedBufferLen, f_pbyBuffer, ulVocNetPktHdrOffset, &CtlHdr, &MsgHeader );
					break;

				case cOCTVC1_MSG_TYPE_SUPERVISORY:
					if( ( cOCTVC1_CTRL_MSG_MODULE_REJECT_SID == ulCmdId ) ||
						( cOCTVC1_SUPERVISORY_MSG_MODULE_REJECT_CID == ulCmdId ) )
					{
						tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV	RejectHeader;
						/* Copy reject header */
						memcpy( &RejectHeader,
								&f_pbyBuffer[ulVocNetPktHdrOffset],
								sizeof(RejectHeader) );

						/* Copy already swapped msg header */
						memcpy( &RejectHeader.Header, &MsgHeader, sizeof(MsgHeader) );
						/* Swap reject header */
						RejectHeader.ulExpectedTransactionId	= mOCT_SWAP32_IF_LE( RejectHeader.ulExpectedTransactionId );
						RejectHeader.ulRejectedCmdId			= mOCT_SWAP32_IF_LE( RejectHeader.ulRejectedCmdId );

						/* Handle Reject */
						iRc = _PktApiHandleRejectPkt( f_pInst, pCnctInf, ulAdjustedBufferLen, f_pbyBuffer, ulVocNetPktHdrOffset, &CtlHdr, &RejectHeader );
						break;
					}
					/* No break left intentionnaly */
				default :
					f_pInst->Stats.ulTotalPktInvalidCnt++;
					break;
			}
		}
	}
	else
	{
		/* VocalloNet Data Packet */
		tOCTVOCNET_PKT_DATA_F_HEADER	PktHdr;
		unsigned int					ulMsgOffset;
		unsigned int					ulSubType;

		ulMsgOffset = ulVocNetPktHdrOffset + ulOctVocNetPktHdrSize;

		memcpy( &PktHdr, &f_pbyBuffer[ulMsgOffset], sizeof(PktHdr));

		mOCTVOCNET_PKT_DATA_F_HEADER_SWAP( &PktHdr );
		/* 
		PktHdr.VocNetHeader.hLogicalObj			= mOCT_SWAP32_IF_LE( PktHdr.VocNetHeader.hLogicalObj );
		PktHdr.VocNetHeader.ulLogicalObjPktPort	= mOCT_SWAP32_IF_LE( PktHdr.VocNetHeader.ulLogicalObjPktPort );
		PktHdr.VocNetHeader.ulDestFifoId		= mOCT_SWAP32_IF_LE( PktHdr.VocNetHeader.ulDestFifoId );
		PktHdr.ulSubType						= mOCT_SWAP32_IF_LE( PktHdr.ulSubType );
		PktHdr.ulTimestamp						= mOCT_SWAP32_IF_LE( PktHdr.ulTimestamp );
		*/
		/* Get subtype */
		ulSubType = PktHdr.ulSubType & 0x0F;

		if ( ( cOCTVOCNET_PKT_FORMAT_F == ulOctVocNetPktFormat )
			&&
			 (cOCTVOCNET_PKT_SUBTYPE_API_EVENT == ulSubType ) )
		{
			/* API Event */
			tOCTVC1_EVENT_HEADER	EventHeader;

			ulMsgOffset += sizeof(tOCTVOCNET_PKT_DATA_F_HEADER);

			memcpy( &EventHeader, &f_pbyBuffer[ulMsgOffset], sizeof(EventHeader));

			/* Swap header */
			EventHeader.ulLength	= mOCT_SWAP32_IF_LE( EventHeader.ulLength );
			EventHeader.ulEventId	= mOCT_SWAP32_IF_LE( EventHeader.ulEventId );
			EventHeader.ulUserEventId = mOCT_SWAP32_IF_LE( EventHeader.ulUserEventId );
			

			iRc = _PktApiHandleEventPkt( f_pInst, pCnctInf, ulAdjustedBufferLen , f_pbyBuffer, ulMsgOffset, &PktHdr, &EventHeader );
		}
		else
		{
			/* Data packet */
			iRc = _PktApiHandleDataPkt( f_pInst, pCnctInf, ulAdjustedBufferLen, f_pbyBuffer, ulMsgOffset, (tOCT_UINT8)ulOctVocNetPktFormat, &PktHdr );
		}
	}

	/* iRc indicates whether or not a packet has been put in a Q */
	return iRc;
}



/*--------------------------------------------------------------------------
	PktApiInstDispatchBufferFnc
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR PktApiInstDispatchBufferFnc( void * f_pAppContext, tOCTTRANSAPI_RECV_PARMS *f_pParms )
{
	tPKTAPI_INST_INF *		pInst = (tPKTAPI_INST_INF *)f_pAppContext;
	tOCTTRANSAPI_RC_ERROR	transRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pAppContext ) || ( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	
	mPKTAPI_INST_MUTEX_SEIZE(pInst);
	/* Packet from instance or connection */
	_PktApiInstHandleRecvPkt(
						pInst,
						f_pParms->ulPayloadLength+(cPKTAPI_PAYLOAD_ALIGNMENT_PADDING+cPKTAPI_ETH_II_HEADER_SIZE),
						f_pParms->pBuffer+cPKTAPI_PAYLOAD_ALIGNMENT_PADDING,
						f_pParms->hDestination,
                        (unsigned char*)f_pParms->pszDestinationAddr );

	mPKTAPI_INST_MUTEX_RELEASE(pInst);

	if(( pInst->ulOptionMask &  cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) != cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) 
	{
		// CHck every x (50ms)
		if( 50 < PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),pInst->ulTimeoutCheckMs ) ) 
			_PktApiInstQueueTimeoutCheck( pInst );
	}


	return transRc;
}

/*--------------------------------------------------------------------------
	PktApiInstDispatchPayloadFnc
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR PktApiInstDispatchPayloadFnc( void * f_pAppContext, tOCTTRANSAPI_RECV_PARMS *f_pParms )
{
	tPKTAPI_INST_INF *		pInst = (tPKTAPI_INST_INF *)f_pAppContext;
	tOCTTRANSAPI_RC_ERROR	transRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pAppContext ) || ( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	
	mPKTAPI_INST_MUTEX_SEIZE(pInst);
	/* Packet from instance or connection */
	_PktApiInstHandleRecvPkt(
						pInst,
						f_pParms->ulPayloadLength,
						f_pParms->pPayload,
						f_pParms->hDestination,
                        (unsigned char*)f_pParms->pszDestinationAddr );

	mPKTAPI_INST_MUTEX_RELEASE(pInst);

	if(( pInst->ulOptionMask &  cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) != cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) 
	{
		// CHck every x (50ms)
		if( 50 < PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),pInst->ulTimeoutCheckMs ))
			_PktApiInstQueueTimeoutCheck( pInst );
	}


	return transRc;
}

/*--------------------------------------------------------------------------
	PktApiInstDispatchRemoveTransport
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiInstDispatchRemoveTransport( tPKTAPI_INST_INF *	f_pInst, 
														tOCTTRANSAPI_HANDLE f_hTrans )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tOCT_UINT32 ulTransCnt = 0;

	/* Count how many connections is using this transport */
	if ( 0 != f_pInst->Stats.ulOpenConnectionCnt )
	{
		tOCT_UINT32 i;
		for ( i=0; i<f_pInst->ulCnctCnt; i++ )
		{
			if( f_pInst->paCnctInf[i].hTransport == f_hTrans )
				ulTransCnt++;
		}
	}	
	if ( ( cOCTVC1_PKT_API_RC_OK == Result ) && ( f_pInst->DiscoverCnct.ulMagic == cPKTAPI_MAGIC_CNCT ) )
	{
		if( f_pInst->DiscoverCnct.hTransport == f_hTrans )
			ulTransCnt++;
	}
	if( ulTransCnt == 1 )
	{
		if( OctTransApiDispatcherRemoveTransport( f_hTrans ) != cOCTTRANSAPI_RC_ERROR_NONE )
			Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
	}
	return Result;
}
/*--------------------------------------------------------------------------
	PktApiInstDispatchAddTransport
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiInstDispatchAddTransport( tPKTAPI_INST_INF *	f_pInst, 
														tOCTTRANSAPI_HANDLE f_hTrans )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tOCT_UINT32 ulTransCnt = 0;

	/* Count how many connections is using this transport */
	if ( 0 != f_pInst->Stats.ulOpenConnectionCnt )
	{
		tOCT_UINT32 i;
		for ( i=0; i<f_pInst->ulCnctCnt; i++ )
		{
			if( f_pInst->paCnctInf[i].hTransport == f_hTrans )
				ulTransCnt++;
		}
	}	
	if ( ( cOCTVC1_PKT_API_RC_OK == Result ) && ( f_pInst->DiscoverCnct.ulMagic == cPKTAPI_MAGIC_CNCT ) )
	{
		if( f_pInst->DiscoverCnct.hTransport == f_hTrans )
			ulTransCnt++;
	}
	/* We should be there and alone */
	if( ulTransCnt == 1 )
	{
		tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS DispAdd;
		mOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS_DEF( &DispAdd );

		DispAdd.hTransport			= f_hTrans;
		DispAdd.pfnDispatchPayload	= PktApiInstDispatchPayloadFnc;
		DispAdd.pAppContext			= f_pInst;

		if( OctTransApiDispatcherAddTransport( f_pInst->hTransDispatcher, &DispAdd ) != cOCTTRANSAPI_RC_ERROR_NONE )
			Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
	}
	return Result;
}

/*--------------------------------------------------------------------------
	PktApiInstWaitForDispatch
----------------------------------------------------------------------------*/
tOCT_UINT32	PktApiInstWaitForDispatch(
	tPKTAPI_INST_INF *					f_pInst,
	unsigned int						f_aulPktType[],
	unsigned int						f_ulPktTypeCnt,
	tPOCTVC1_PKT_API_INST_RECV_PARMS	f_pParms )
{
#ifndef OCTOSAL_OPT_MULTI_THREAD
    return cOCTVC1_PKT_API_RC_REQUIRES_MULTI_THREAD;
#else /*OCTOSAL_OPT_MULTI_THREAD*/
	tOCT_UINT32					Result = cOCTVC1_PKT_API_RC_TIMEOUT;
	tOCT_UINT32					osRc;
	tPPKTAPI_PKT_Q_INF			pPktQ = NULL;
	tOCT_BOOL32					fComplete = cOCT_FALSE;
	tOCTOSAL_HANDLE_SYNC_SIGNAL ahSyncSignal[cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT];
	unsigned int				ulTimeStart;
	unsigned int				ulTimeElapsed;


	/* Extract a packet from one of the receive Q ... if any */
	if( !f_pInst->fReady )
		return cOCTVC1_PKT_API_RC_INST_TERMINATED;

	if ( cOCT_TRUE == _PktApiInstQueueRecv( f_pInst, f_aulPktType, f_ulPktTypeCnt, f_pParms ) )
	{
		return cOCTVC1_PKT_API_RC_OK;
	}

	/* Get ready to wait for signal */
	if( f_ulPktTypeCnt > 1 )
	{
		tOCT_UINT32 i;
		for( i=0; i<f_ulPktTypeCnt; i++ )
			ahSyncSignal[i] = f_pInst->paPktQ[f_aulPktType[i]].hSyncSignal;
	}

	ulTimeStart = OctOsalGetTimeMs();
	ulTimeElapsed = 0;

	while( 
			1 == f_pInst->fReady &&
			fComplete == cOCT_FALSE &&
			(
				cOCTVC1_PKT_API_FOREVER == f_pParms->ulTimeoutMs
				||
				( 0 == f_pParms->ulTimeoutMs )
				||
				f_pParms->ulTimeoutMs > ulTimeElapsed 
			)	)
	{
		unsigned int	ulWaitTimeoutMs;

		if (cOCTVC1_PKT_API_FOREVER == f_pParms->ulTimeoutMs)
		{
			ulWaitTimeoutMs = cOCTVC1_PKT_API_FOREVER;
		}
		else
		{
			/* On f_pParms->ulTimeoutMs == 0 ... use 1ms max to seize time out ... */
			ulWaitTimeoutMs = (f_pParms->ulTimeoutMs > ulTimeElapsed) ? (f_pParms->ulTimeoutMs - ulTimeElapsed) : 1;
		}

		if( f_ulPktTypeCnt > 1 )
		{
			tOCT_UINT32 ulSignalIndex;

			osRc = OctOsalSyncSignalWaitMultiple( f_ulPktTypeCnt, ahSyncSignal, ulWaitTimeoutMs, &ulSignalIndex );
			if( osRc == cOCTOSAL_RC_OK )
				pPktQ = &f_pInst->paPktQ[f_aulPktType[ulSignalIndex]];
		}
		else
		{
			osRc = OctOsalSyncSignalWait( f_pInst->paPktQ[f_aulPktType[0]].hSyncSignal, ulWaitTimeoutMs );
			if( osRc == cOCTOSAL_RC_OK )
				pPktQ = &f_pInst->paPktQ[f_aulPktType[0]];
		}

		if( !f_pInst->fReady )
			break;

		if( osRc == cOCTOSAL_RC_OK )
		{
			/* Get a busy block from that Q */
			tPPKTAPI_PKT_INF pPktInf = PktApiPktQueueGet( cPKTAPI_Q_BUSY, pPktQ );

			/* It is possible to get signal without pkt */
			if ( NULL != pPktInf )
				fComplete = _PktApiInstQueueToRecvParm( f_pInst, pPktInf, f_pParms );
		}
		else if ( osRc == cOCTOSAL_RC_TIMEOUT )
			Result = cOCTVC1_PKT_API_RC_TIMEOUT;
		else
		{
			Result = cOCTVC1_PKT_API_RC_OS_ERROR;
			break;
		}

		/* Test if tried all Q and nothing present */
		if( !fComplete  )
		{
			/* The user did not want to wait and there is nothing in the Q */
			if( 0 == f_pParms->ulTimeoutMs )
				break;
			else
				ulTimeElapsed = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),ulTimeStart );
		}
	}

	if ( fComplete == cOCT_TRUE )
	{
		Result = cOCTVC1_PKT_API_RC_OK;
	}
	else
	{
		if ( cOCT_TRUE != f_pInst->fReady )
			Result = cOCTVC1_PKT_API_RC_INST_TERMINATED;
	}

	return Result;
#endif /*OCTOSAL_OPT_MULTI_THREAD*/
}

/*--------------------------------------------------------------------------
	PktApiInstRecv
----------------------------------------------------------------------------*/
tOCT_UINT32	PktApiInstRecv(
	tPKTAPI_INST_INF *				f_pInst,
	unsigned int					f_aulPktType[],
	unsigned int					f_ulPktTypeCnt,
	unsigned int					f_ulTimeoutQType,
	tPOCTVC1_PKT_API_INST_RECV_PARMS		f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_TIMEOUT;
	unsigned int			ulIndex;
	unsigned int			ulTimeStart;
	unsigned int			ulTimeElapsed;
	unsigned int			fComplete = cOCT_FALSE;
	unsigned int			ulPktCnt = 0;

	if( f_pInst->hTransDispatcher != NULL )
		return PktApiInstWaitForDispatch( f_pInst, f_aulPktType, f_ulPktTypeCnt, f_pParms );

	/* Latch start time */
	ulTimeStart = OctOsalGetTimeMs();
	ulTimeElapsed = 0;

	/* Enter the loop */
	while (
			1 == f_pInst->fReady
			&&
			cOCT_FALSE == fComplete
			&&
			(
			cOCTVC1_PKT_API_FOREVER == f_pParms->ulTimeoutMs
			||
			( 0 == f_pParms->ulTimeoutMs )
			||
			f_pParms->ulTimeoutMs > ulTimeElapsed ) )
	{
		unsigned int	ulWaitTimeoutMs;

		/* First time in the loop ? ... no wait if expected timeout is 0 */
		if( ( 0 != ulTimeElapsed ) && f_pParms->ulTimeoutMs )
		{
			/* No give a chance to other threads */
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
			OctOsalSleepMs( 0 );
#else
			OctOsalSleepMs( 10 );
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
		}

		/* Extract a packet from one of the receive Q */
		if ( cOCT_FALSE == (fComplete = _PktApiInstQueueRecv( f_pInst, f_aulPktType, f_ulPktTypeCnt, f_pParms )) )
		{

			/* Test if tried all Q and nothing present */
			if( ( 0 != ulTimeElapsed ) && ( 0 == f_pParms->ulTimeoutMs ) )
			{
				/* The user did not want to wait and there is nothing in the Q */
				break;
			}

			/* Try to receive from the transport */
			if (cOCTVC1_PKT_API_FOREVER == f_pParms->ulTimeoutMs)
			{
				ulWaitTimeoutMs = cOCTVC1_PKT_API_FOREVER;
			}
			else
			{
				/* On f_pParms->ulTimeoutMs == 0 ... use 1ms max to seize time out ... */
				ulWaitTimeoutMs = (f_pParms->ulTimeoutMs > ulTimeElapsed) ? (f_pParms->ulTimeoutMs - ulTimeElapsed) : 1;
			}

			/* Lock the recv process it */
			if( 0 == mPKTAPI_INST_RECVMUTEX_TIMED_SEIZE( f_pInst, ulWaitTimeoutMs ) )
			{
				unsigned int	fOtherPendingPacket;
				
				fOtherPendingPacket = 0;

				/* Be sure packet is not arrived while seizing the lock */
				fComplete = _PktApiInstQueueRecv( f_pInst, f_aulPktType, f_ulPktTypeCnt, f_pParms );

#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
				if ( fComplete == cOCT_FALSE )
				{
					/* no packet for the current call, check if some other responses
						are present for any other synchronous call */
					for( ulIndex=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD+1; ulIndex<f_pInst->ulPktQCnt; ulIndex++ )
					{
						if ( PktApiPktQueueCountGet(
													cPKTAPI_Q_BUSY,
													&f_pInst->paPktQ[ulIndex] ) )
						{
							fOtherPendingPacket = 1;
							break;
						}
					}

					if( !fOtherPendingPacket )
					{
						/* Look if there is async response waiting */
						if( f_ulTimeoutQType != cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD )
						{
							if ( PktApiPktQueueCountGet(
														cPKTAPI_Q_BUSY,
														&f_pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP] ) )
							{
								fOtherPendingPacket = 1;
							}
						}					
					}
				}
				/* Calc number of time we skip looking for recv data because there is a response waiting */
				if( fOtherPendingPacket )
				{
					if( f_pInst->ulPendingRspElapseMs )
					{
						/* We can't skip pooling received for more than 10 ms */
						if( PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),
								f_pInst->ulPendingRspElapseMs ) > 10 )
						{
							/* There is an rsp waiting but no owner of the Q is not schedule */
							/* Keep going ... possible that the application user SendCmd but never send InstRecv ? */
							fOtherPendingPacket = cOCT_FALSE;
						}
					}
					else
						f_pInst->ulPendingRspElapseMs = OctOsalGetTimeMs();
				}
				else
					f_pInst->ulPendingRspElapseMs = 0;
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */

				/* If no packet for the current call and no pending synchronous response,
				then go to transport to fetch some packets. otherwise, yield to give a chance
				to the waiting synchronous call to complete */
				if ( !fComplete && !fOtherPendingPacket )
				{
					unsigned int		ulTransportCnt = 0;
					tOCT_UINT32			ulTransportStartTimeMs = 0;
					tPPKTAPI_CNCT_INF	apCnctInf[cOCTVC1_PKT_API_TRANSPORT_SELECT_MAX];

					/* Get the new elapsed time */
					ulTimeElapsed = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),ulTimeStart );
					if (cOCTVC1_PKT_API_FOREVER == f_pParms->ulTimeoutMs)
					{
						ulWaitTimeoutMs = cPKTAPI_INST_TIMEOUT_CMD_DEF;
					}
					else if( 0 == f_pParms->ulTimeoutMs )
					{
						ulWaitTimeoutMs = 0; /* No wait .. expect data to be there */
					}
					else
					{
						ulWaitTimeoutMs = (f_pParms->ulTimeoutMs > ulTimeElapsed) ? (f_pParms->ulTimeoutMs - ulTimeElapsed) : 1;
					}

                    {
                        unsigned int    ulIndex;
                        void *			ahTransport[cOCTVC1_PKT_API_TRANSPORT_SELECT_MAX];
                        unsigned int	aulTransportState[cOCTVC1_PKT_API_TRANSPORT_SELECT_MAX];
						void **         pahTransport;
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                        tOCT_UINT32     fSelectSuccess;
                        tOCTTRANSAPI_SELECT_PARMS TransSelect;
                        mOCTTRANSAPI_SELECT_PARMS_DEF( &TransSelect );
						pahTransport = TransSelect.ahTransport;
#else
                        pahTransport = ahTransport;
#endif

                        /* We have to wait from transport */
                        /* Build the select array */
                        memset( aulTransportState, 0x0, sizeof(aulTransportState) );
                        memset( apCnctInf, 0x0, sizeof(apCnctInf) );

                        if( f_pInst->fUseExternalTransport )
                        {
                            for( ulIndex=0; ulIndex<f_pInst->ulCnctCnt; ulIndex++ )
                            {
                                if( f_pInst->paCnctInf[ulIndex].hTransport != NULL )
								{
                                    unsigned ulTransportIndex;
                                    /*  Two connections may share the same transport, scan that we don't already have this transport
                                        in the list */
                                    for(ulTransportIndex = 0; ulTransportIndex < ulTransportCnt &&
                                        f_pInst->paCnctInf[ulIndex].hTransport != pahTransport[ulTransportIndex]; )
									{
										ulTransportIndex++;
									}

                                    if(ulTransportIndex < ulTransportCnt)
                                        continue;

                                    pahTransport[ulTransportCnt++] = f_pInst->paCnctInf[ulIndex].hTransport;
                                }
                            }
                            /* Test for discovercnt */
                            if( f_pInst->DiscoverCnct.hTransport != NULL )
                            {
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                                    TransSelect.ahTransport[ulTransportCnt++] = f_pInst->DiscoverCnct.hTransport;
#else
                                    ahTransport[ulTransportCnt++] = f_pInst->DiscoverCnct.hTransport;
#endif
                            }
                        }
                        else    /*Local transport*/
                        {
                            /* Instance transport */
                            ahTransport[ulTransportCnt++] = f_pInst->hTransport;
                        }

#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                        /*Do select*/
                        if (cOCT_TRUE == f_pInst->fUseExternalTransport)
                        {
                            TransSelect.ulTimeoutMs = ulWaitTimeoutMs;
                            TransSelect.ulTransportCnt = ulTransportCnt;
                            fSelectSuccess = (OctTransApiSelect( &TransSelect ) == cOCTTRANSAPI_RC_ERROR_NONE);
                        }
                        else
                        {
                            /* Add loopback transport */
                            ahTransport[ulTransportCnt++] = f_pInst->hTransportLoopback;

                            ulWaitTimeoutMs = (ulWaitTimeoutMs > ( cPKTAPI_INST_TIMEOUT_CMD_DEF >> 1) ) ? ( cPKTAPI_INST_TIMEOUT_CMD_DEF >> 1) : ulWaitTimeoutMs;

                            /* Latch time before invoking transport */
                            ulTransportStartTimeMs =  OctOsalGetTimeMs();
                            fSelectSuccess = (0 < f_pInst->TransportFunc.pfnTransportApiSelect(
                                                    f_pInst->pTransportContext,
                                                    ulWaitTimeoutMs,
                                                    ulTransportCnt,
                                                    ahTransport,
                                                    aulTransportState ) );
                        }
                        if(fSelectSuccess)
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
                        {
                            /* Loop around all ready transport */
                            for ( ulIndex=0;ulIndex<ulTransportCnt; ulIndex++ )
                            {
                                tOCTTRANSAPI_RECV_PARMS Recv;
                                unsigned char	szDestinationAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE];

#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                                if ( (cOCT_TRUE == f_pInst->fUseExternalTransport &&
                                      ulIndex<TransSelect.ulSelectedCnt) ||
                                     (cOCT_FALSE == f_pInst->fUseExternalTransport &&
                                        cOCTTRANSAPI_SELECT_STATE_RECV & aulTransportState[ulIndex] )
                                     )
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
                                {
                                    int	ulRecvLen = 0;
                                    int transRc = cOCTTRANSAPI_RC_ERROR_NONE;

                                    /* Receive from that transport */
                                    if(cOCT_TRUE == f_pInst->fUseExternalTransport)
                                    {
                                        mOCTTRANSAPI_RECV_PARMS_DEF( &Recv );
                                        Recv.pBuffer = f_pInst->pabyRxBuffer;
                                        Recv.ulMaxBufferLength = cPKTAPI_PAYLOAD_MAX;
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                                        Recv.ulTimeoutMs = 0;
#else
                                        Recv.ulTimeoutMs = ulWaitTimeoutMs ? 10 : 0;
#endif
                                        /* Need to get remote addr when expecting discover response */
                                        if( f_ulTimeoutQType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER )
                                        {
                                            Recv.pszDestinationAddr = (char *)szDestinationAddr;
                                            Recv.ulMaxDestinationAddrLength = cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE;
                                        }

                                        transRc = OctTransApiRecv(
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                                            TransSelect.ahTransSelected[ulIndex],
#else
                                             ahTransport[ulIndex],
#endif
                                             &Recv );

                                        if(transRc == cOCTTRANSAPI_RC_ERROR_NONE )
                                        {
                                            ulRecvLen = Recv.ulPayloadLength;
                                        }

                                    }
                                    else /*Local Transport*/
                                    {
                                        ulRecvLen = f_pInst->TransportFunc.pfnTransportApiRecv(
                                                    ahTransport[ulIndex],
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                                                    0,
#else
                                                    ulWaitTimeoutMs ? 10 : 0,
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
                                                    f_pInst->pabyRxBuffer,
                                                    cPKTAPI_PAYLOAD_MAX );
                                    }

                                    if( 0 < ulRecvLen )
                                    {
#ifdef OCTVC1_PKT_API_TRANSPORT_OPT_SELECT
                                        if ( 1 == ulIndex &&
                                             cOCT_FALSE == f_pInst->fUseExternalTransport)
                                        {
                                            unsigned int	ulReason;
                                            /* Internal loop back packet */
                                            memcpy( &ulReason,((unsigned int*)f_pInst->pabyRxBuffer), sizeof(ulReason) );
                                            if ( cPKTAPI_INST_UNLOCK_REASON_TERMINATE == ulReason )
                                            {
                                                /* Have to exit */
                                                Result = cOCTVC1_PKT_API_RC_INST_TERMINATED;
                                                break;
                                            }
                                            ulTransportStartTimeMs = 0;
                                        }
                                        else
#endif /* OCTVC1_PKT_API_TRANSPORT_OPT_SELECT */
                                        {

                                            mPKTAPI_INST_MUTEX_SEIZE(f_pInst);
                                            /* Packet from instance or connection */
                                            ulPktCnt += _PktApiInstHandleRecvPkt(
                                                        f_pInst,
                                                        ulRecvLen,
                                                        (f_pInst->fUseExternalTransport)?
                                                            Recv.pPayload :
                                                            f_pInst->pabyRxBuffer,
                                                        (f_pInst->fUseExternalTransport)?
                                                            Recv.hDestination :
                                                                NULL,
                                                        (f_pInst->fUseExternalTransport)?
                                                            (unsigned char*)Recv.pszDestinationAddr :
                                                                NULL );
                                            mPKTAPI_INST_MUTEX_RELEASE(f_pInst);
                                        }
                                    }
                                }
                            }
                        }
                    }
					if ( ulTransportStartTimeMs )
					{
						mPKTAPI_INST_MUTEX_SEIZE(f_pInst);

						ulTransportStartTimeMs = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),ulTransportStartTimeMs );
						if ( ulPktCnt )
						{
							if ( !f_pInst->Stats.ulHighestTransportRxTimeMs
								||
								ulTransportStartTimeMs > f_pInst->Stats.ulHighestTransportRxTimeMs )
							{
								f_pInst->Stats.ulHighestTransportRxTimeMs = ulTransportStartTimeMs;
							}
						}
						else
						{
							if ( !f_pInst->Stats.ulHighestTransportNoRxTimeMs
								||
								ulTransportStartTimeMs > f_pInst->Stats.ulHighestTransportNoRxTimeMs )
							{
								f_pInst->Stats.ulHighestTransportNoRxTimeMs = ulTransportStartTimeMs;
							}
						}
						mPKTAPI_INST_MUTEX_RELEASE(f_pInst);
					}
				}


				/* Unlock the recv instance */
				mPKTAPI_INST_RECVMUTEX_RELEASE( f_pInst );

				/* Calculate elapsed time to avoid been stuck here */
				ulTimeElapsed = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),ulTimeStart ) ;
				/* Be sure that elapsed is at least 1 */
				if ( ! ulTimeElapsed )
				{
					ulTimeElapsed = 1;
				}
			}
			else
			{
				/* Force to exit */
				break;
			}
		}

		// SHould check from timeout every 50ms
		if((( f_pInst->ulOptionMask &  cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) != cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) &&
		   (((ulTimeStart + ulTimeElapsed) - f_pInst->ulTimeoutCheckMs ) > 50 ) )
		{

			tOCT_BOOL32 fChckTimeout;

			/* Make sure only one thread is testing timeout */
			mPKTAPI_INST_QUEUEMUTEX_SEIZE( f_pInst );
			if( f_pInst->fChckTimeout == cOCT_FALSE )
			{
				fChckTimeout = f_pInst->fChckTimeout = cOCT_TRUE;
			}
			else
				fChckTimeout = cOCT_FALSE;
			mPKTAPI_INST_QUEUEMUTEX_RELEASE( f_pInst );
			
			/* Test if have to check timeout */
			if( fChckTimeout )
			{

				_PktApiInstQueueTimeoutCheck( f_pInst );

				mPKTAPI_INST_QUEUEMUTEX_SEIZE( f_pInst );
				f_pInst->fChckTimeout = cOCT_FALSE;
				mPKTAPI_INST_QUEUEMUTEX_RELEASE( f_pInst );

			}
		}
	};

	if ( fComplete == cOCT_TRUE )
	{
		Result = cOCTVC1_PKT_API_RC_OK;
	}
	else
	{
		if ( cOCT_TRUE != f_pInst->fReady )
			Result = cOCTVC1_PKT_API_RC_INST_TERMINATED;
	}
	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiInstRecv
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstRecv(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_RECV_PARMS						f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_TIMEOUT;
	tPKTAPI_INST_INF *		pInst;
	unsigned int			aulPktType[cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT];
	unsigned int			ulPktTypeCnt=0;
	unsigned int			ulIndex;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	/* Validate parameters */
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) ||
		( 0 == f_pParms->ulMaxPayloadLength ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pInst = (tPKTAPI_INST_INF *)f_pInstance;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */




	/* Build packet type array to retrieve packet from */
	for ( ulIndex=0; ulIndex<cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT; ulIndex++ )
	{
		if ( f_pParms->PktRcvMask & (1<<ulIndex) )
		{
			aulPktType[ulPktTypeCnt++] = ulIndex;
		}
	}

	if ( ulPktTypeCnt )
	{
		/* Enter the loop */
		Result = PktApiInstRecv(
						pInst,
						aulPktType,
						ulPktTypeCnt,
						cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD,
						f_pParms );
		if ( cOCTVC1_PKT_API_RC_OK == Result
			&&
			f_pParms->ulRcvPayloadLength > f_pParms->ulMaxPayloadLength )
		{
			/* This response has been truncated */
			Result = cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE;
		}
		/* just check if the packet is a response (even non OK response) */
		if (
			cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP == f_pParms->RcvPktType
			&&
			f_pParms->Info.Rsp.ulExtractTimeMs )
		{
			/*  Adjust the extract time */
			f_pParms->Info.Rsp.ulExtractTimeMs = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(),f_pParms->Info.Rsp.ulExtractTimeMs ) ;

			mPKTAPI_INST_MUTEX_SEIZE(pInst);

			if ( !pInst->Stats.ulHighestExtractTimeMs 
				|| 
				f_pParms->Info.Rsp.ulExtractTimeMs > pInst->Stats.ulHighestExtractTimeMs )
			{
				pInst->Stats.ulHighestExtractTimeMs =f_pParms->Info.Rsp.ulExtractTimeMs;

			}
			if ( !pInst->Stats.ulLowestExtractTimeMs 
				|| 
				f_pParms->Info.Rsp.ulExtractTimeMs < pInst->Stats.ulLowestExtractTimeMs )
			{
				pInst->Stats.ulLowestExtractTimeMs =f_pParms->Info.Rsp.ulExtractTimeMs;
			}
			mPKTAPI_INST_MUTEX_RELEASE(pInst);
		}
	}
	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiInstInfo
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstInfo(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_INFO_PARMS				f_pParms)
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_INST_INF *		pInst;


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	/* Validate parameters */
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pInst = (tPKTAPI_INST_INF *)f_pInstance;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	mPKTAPI_INST_MUTEX_SEIZE( pInst );

	/* Transfer the inst info */
	memcpy( &f_pParms->abyLocalMac, &pInst->abyLocalMac, sizeof( f_pParms->abyLocalMac ));
	f_pParms->pTransportLocalContext	= pInst->pTransportLocalContext;
	f_pParms->pTransportContext			= pInst->pTransportContext;
	f_pParms->ulMaxConnection			= pInst->ulMaxConnection; 
	f_pParms->ulMaxSession				= 1;
	f_pParms->ulMaxSyncCmd				= pInst->ulMaxSyncCmd;

	f_pParms->ulMaxPendingRsp			= pInst->ulMaxPendingRsp;
	f_pParms->ulMaxPendingEvt			= pInst->ulMaxPendingEvt;
	f_pParms->ulMaxPendingData			= pInst->ulMaxPendingData;
	f_pParms->ulMaxRetry				= pInst->ulMaxRetry;
	f_pParms->usSessionInstanceStart	= pInst->usSessionInstanceStart;
	f_pParms->ulOptionMask				= pInst->ulOptionMask;
	f_pParms->fUseExternalTransport		= pInst->fUseExternalTransport;
	f_pParms->hTransDispatcher			= pInst->hTransDispatcher;

	mPKTAPI_INST_MUTEX_RELEASE( pInst );

	return Result;
}

/*--------------------------------------------------------------------------
	SendTargetInfoCmd
----------------------------------------------------------------------------*/
static tOCT_UINT32	SendTargetInfoCmd(	
	tPKTAPI_SESS_INF *					f_pSessInf )
{
	/* Send new DEVICE INFO CMD */
	tOCT_UINT32							Result = cOCTVC1_PKT_API_RC_OK;
	tOCTVC1_MAIN_MSG_TARGET_INFO_CMD	DeviceInfoCmd;
	tOCTVC1_PKT_API_CMD_SEND_PARMS		SendParms;
	tPKTAPI_PKT_INF *					pPktInf;

	/* Get a packet from the discover Q */
	pPktInf = PktApiPktQueueGet(
							cPKTAPI_Q_FREE,
							&f_pSessInf->pCnct->pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER] );

	/* Prepare the command we wish to send */
	memset( &DeviceInfoCmd, 0x0, sizeof(DeviceInfoCmd) );
	DeviceInfoCmd.Header.ulLength			=
			((sizeof(tOCTVC1_MAIN_MSG_TARGET_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK);
	DeviceInfoCmd.Header.ul_Type_R_CmdId	=
			( cOCTVC1_MAIN_MSG_TARGET_INFO_CID <<cOCTVC1_MSG_ID_BIT_OFFSET&cOCTVC1_MSG_ID_BIT_MASK);
	/* swap the command */
	mOCTVC1_MAIN_MSG_TARGET_INFO_CMD_SWAP( &DeviceInfoCmd );
	SendParms.pCmd		= &DeviceInfoCmd;
	SendParms.pUserCmdContext	= NULL;

	/* Send the command */
	Result =  PktApiSessCmdSend(
					f_pSessInf,
					&SendParms,
					cPKTAPI_Q_SPECIAL,
					cOCTVC1_PKT_API_DEV_MAX * cOCTVC1_PKT_API_DEV_PORT_MAX,
					pPktInf );
	if( Result != cOCTVC1_PKT_API_RC_OK )
	{
		PktApiPktQueuePut(
							cPKTAPI_Q_FREE,
							&f_pSessInf->pCnct->pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER],
							pPktInf );
	}

	return Result;
}

/*--------------------------------------------------------------------------
	InstDiscoverDevbyInfo
----------------------------------------------------------------------------*/
static tOCT_UINT32	InstDiscoverDevbyInfo(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPKTAPI_SESS_INF *								f_pSessInf,
	tPOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS		f_pParms,
	tOCT_BOOL32										f_fUse1010Info,
	tOCT_BOOL32									*	f_pfInvalidDevice )
{
	tOCTVC1_PKT_API_INST_RECV_PARMS		RecvParms;
	tPKTAPI_OCT1010_GET_INFO_RSP_PARMS	PktApiGetInfoResp;
	unsigned int						ulStartTimeMs;
	unsigned int						ulElapsedTimeMs;
	unsigned int						aulPktType[] = {cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER,
														cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT};
	tPKTAPI_INST_INF *					pInst;
	tOCT_UINT32							Result = cOCTVC1_PKT_API_RC_OK;
	unsigned int						ulExpectedDeviceCnt = (f_pParms->ulExpectedDeviceCnt==0) ? cOCTVC1_PKT_API_DEV_MAX : f_pParms->ulExpectedDeviceCnt;

	pInst = (tPKTAPI_INST_INF *)f_pInstance;
	ulStartTimeMs	= OctOsalGetTimeMs();
	ulElapsedTimeMs	= 0;

	if (ulExpectedDeviceCnt > cOCTVC1_PKT_API_DEV_MAX)
		ulExpectedDeviceCnt = cOCTVC1_PKT_API_DEV_MAX;

	/* Wait for the responses (till timeout elapsed or enougth device detected) */
	while ( ulElapsedTimeMs <= f_pParms->ulTimeoutMs
			&&
			f_pParms->ulDeviceCnt < ulExpectedDeviceCnt )
	{
		RecvParms.ulTimeoutMs = f_pParms->ulTimeoutMs - ulElapsedTimeMs;
		RecvParms.ulMaxPayloadLength = sizeof(PktApiGetInfoResp);
		RecvParms.pPayload = &PktApiGetInfoResp;

		Result = PktApiInstRecv(
						pInst,
						aulPktType,
						2,
						cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER,
						&RecvParms );

		if ( cOCTVC1_RC_OK == Result
			&&
			cOCTVC1_PKT_API_RC_TIMEOUT != RecvParms.Info.Rsp.ulReturnCode)
		{
			unsigned int	ulDevIndex;
			unsigned int	fValidResponse = 0;
			tOCT_UINT8 *	pabyMacAddr = NULL;
			tOCT_UINT8 *	pszDestAddr = NULL;
			tPOCTVC1_PKT_API_DEV_INFO	pDevInfo;
			tOCTVC1_MAIN_MSG_TARGET_INFO_RSP *pOctDeviceInfo=NULL;
#ifdef cOCTVC1_MAIN_MSG_OCT1010_INFO_CID
			tOCTVC1_MAIN_MSG_OCT1010_INFO_RSP *pOct1010Info=NULL;
#else
			void *pOct1010Info=NULL;
#endif /* cOCTVC1_MAIN_MSG_OCT1010_INFO_CID */

			if( !pInst->fUseExternalTransport )
				pabyMacAddr = PktApiGetInfoResp.DestAddr.abyRemoteMacAddr;
			else
				pszDestAddr = PktApiGetInfoResp.DestAddr.szDestAddr;

			if ( cOCTVC1_PKT_API_RC_OK == RecvParms.Info.Rsp.ulReturnCode )
			{
#ifdef cOCTVC1_MAIN_MSG_OCT1010_INFO_CID
				if(f_fUse1010Info && ( RecvParms.Info.Rsp.ulCmdId == cOCTVC1_MAIN_MSG_OCT1010_INFO_CID) )
				{
					pOct1010Info = (tOCTVC1_MAIN_MSG_OCT1010_INFO_RSP *)PktApiGetInfoResp.abyGetInfoResp;
					pOctDeviceInfo = NULL;
					mOCTVC1_MAIN_MSG_OCT1010_INFO_RSP_SWAP( pOct1010Info );
					fValidResponse = 1;

				}
#endif /* cOCTVC1_MAIN_MSG_OCT1010_INFO_CID */
				if( RecvParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP &&
					RecvParms.Info.Rsp.ulCmdId == cOCTVC1_MAIN_MSG_TARGET_INFO_CID)
				{
					pOctDeviceInfo = (tOCTVC1_MAIN_MSG_TARGET_INFO_RSP *)PktApiGetInfoResp.abyGetInfoResp;
					mOCTVC1_MAIN_MSG_TARGET_INFO_RSP_SWAP( pOctDeviceInfo );
					pOct1010Info = NULL;
					fValidResponse = 1;
				}
				else if(RecvParms.RcvPktType == cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT)
				{
					/*Received an event, try sending another Target Info Cmd*/
					Result = SendTargetInfoCmd(f_pSessInf);
				}
			}
			else
			{
				/* Invalid response .. will try old OCT1010_INFO later */
				fValidResponse = 0;
				*f_pfInvalidDevice = cOCT_TRUE;

				// Stop trying to match device that does not reply a valid response
				continue;

			}

			/* loop all discovered devices port */
			pDevInfo = NULL;
			for ( ulDevIndex=0; ulDevIndex<f_pParms->ulDeviceCnt; ulDevIndex++ )
			{
				unsigned int	ulDevPortIndex;

				for ( ulDevPortIndex=0; ulDevPortIndex<f_pParms->aDeviceInfo[ulDevIndex].ulPortCnt; ulDevPortIndex++ )
				{
					switch( f_pParms->aDeviceInfo[ulDevIndex].aPortInfo[ulDevPortIndex].ulPortType )
					{
						case cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH:
							if( pabyMacAddr &&
								( 0 == memcmp( f_pParms->aDeviceInfo[ulDevIndex].aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr,
								pabyMacAddr, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) )
							{
								f_pParms->aDeviceInfo[ulDevIndex].aPortInfo[ulDevPortIndex].fReachable = cOCT_TRUE;
								pDevInfo = &f_pParms->aDeviceInfo[ulDevIndex];
							}
							break;
						case cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_TRANSPORT:
							if( pszDestAddr &&
                                ( 0 == strcmp( (char *)f_pParms->aDeviceInfo[ulDevIndex].aPortInfo[ulDevPortIndex].Type.Transport.szDestinationAddr,
                                (char *)pszDestAddr ) ) )
							{
								f_pParms->aDeviceInfo[ulDevIndex].aPortInfo[ulDevPortIndex].fReachable = cOCT_TRUE;
								pDevInfo = &f_pParms->aDeviceInfo[ulDevIndex];
							}
							break;

						default:
							break;
					}
					if( pDevInfo )
						break;
				}
				if( pDevInfo )
					break;
			}

			/* New one ? */
			if ( !pDevInfo || f_fUse1010Info )
			{
				unsigned int				ulDevPortIndex;

				/* Add it to the list if new one */
				if( pDevInfo == NULL )
				{
					if( !f_fUse1010Info && !fValidResponse )
					{
						/* specify that this device is not valid */
						*f_pfInvalidDevice = cOCT_TRUE;
						continue;
					}
					pDevInfo = &f_pParms->aDeviceInfo[f_pParms->ulDeviceCnt];
					f_pParms->ulDeviceCnt++;
				}

				/* Create both ports */
				if( fValidResponse )
				{
					pDevInfo->ulPortCnt = 2;

					if( pInst->fUseExternalTransport )
					{
						tOCTTRANSAPI_DESTINATION_INFO_PARMS DestInfo;

						mOCTTRANSAPI_DESTINATION_INFO_PARMS_DEF( &DestInfo );
						if( OctTransApiDestinationInfo( pInst->DiscoverCnct.hTransDest, &DestInfo ) == cOCTVC1_PKT_API_RC_OK )
							pDevInfo->hTransport = DestInfo.hTransport;

						pDevInfo->ulPortCnt = 1;
					}
				}

				/* Use old way */
				if( !pInst->fUseExternalTransport )
				{
					for ( ulDevPortIndex=0; ulDevPortIndex<pDevInfo->ulPortCnt; ulDevPortIndex++ )
					{
						if ( fValidResponse )
						{
							if( pOct1010Info )
							{
#ifdef cOCTVC1_MAIN_MSG_OCT1010_INFO_CID
								pDevInfo->aPortInfo[ulDevPortIndex].ulPortType = cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH;
								memcpy( pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr,
									(pOct1010Info->aMacAddress[ulDevPortIndex].abyMacAddress),
									sizeof(pOct1010Info->aMacAddress[ulDevPortIndex].abyMacAddress) );
#endif

							}
							else
							{
								/* Locate Mac Token on device */
								tOCT_INT8 *pszMac;
								tOCT_INT8 szToken[50];


								sprintf( szToken, "DEVICE_IO_ETH_MAC_ADDRESS_PORT_%d=",ulDevPortIndex );
								pszMac = strstr( (char*)pOctDeviceInfo->abyTargetInfo, szToken );
								if( pszMac )
								{
									tOCT_INT32 ulMac[6];
									pszMac += strlen( szToken );
									if( sscanf( pszMac, "%02X%02X%02X%02X%02X%02X", &ulMac[0],&ulMac[1],&ulMac[2],&ulMac[3],&ulMac[4],&ulMac[5] ) == 6 )
									{
										pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr[0] = (tOCT_INT8)ulMac[0];
										pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr[1] = (tOCT_INT8)ulMac[1];
										pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr[2] = (tOCT_INT8)ulMac[2];
										pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr[3] = (tOCT_INT8)ulMac[3];
										pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr[4] = (tOCT_INT8)ulMac[4];
										pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr[5] = (tOCT_INT8)ulMac[5];
									}
									else
										fValidResponse =  0;
								}
								else
									fValidResponse =  0;
							}
						}

						if( fValidResponse )
						{
							/* Tag the port */
							pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.ulPortId = ulDevPortIndex;
							pDevInfo->aPortInfo[ulDevPortIndex].ulPortType = cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH;

							/* Response from this port ? */
							if ( 0 == memcmp( pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr,
											pabyMacAddr, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) )
							{
								pDevInfo->aPortInfo[ulDevPortIndex].fReachable = cOCT_TRUE;
							}
							else
							{
								pDevInfo->aPortInfo[ulDevPortIndex].fReachable = cOCT_FALSE;
							}
						}
						else if ( 0 == ulDevPortIndex )
						{
							/* There is a device but the response format is not knowned */
							pDevInfo->aPortInfo[ulDevPortIndex].ulPortType = cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH;
							memcpy( pDevInfo->aPortInfo[ulDevPortIndex].Type.Eth.abyMacAddr,
									pabyMacAddr, cOCTVC1_PKT_API_MAC_ADDR_SIZE );
							pDevInfo->aPortInfo[ulDevPortIndex].fReachable = cOCT_TRUE;
							pDevInfo->ulPortCnt = 1;
							break;
						}
					}
				}
				else
				{
					pDevInfo->aPortInfo[0].ulPortType = cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_TRANSPORT;
					pDevInfo->aPortInfo[0].fReachable = cOCT_TRUE;
					pDevInfo->ulPortCnt = 1;
                    strcpy( (char *)pDevInfo->aPortInfo[0].Type.Transport.szDestinationAddr, (char *)pszDestAddr );

				}

				/* Update user info .. even if not valid */
				if( pOct1010Info )
				{
#ifdef cOCTVC1_MAIN_MSG_OCT1010_INFO_CID
					pDevInfo->ulUserInfoLength = mMIN( sizeof( pOct1010Info->aulUserInfo ), sizeof(pDevInfo->abyUserInfo) );
					memcpy( pDevInfo->abyUserInfo, &pOct1010Info->aulUserInfo, pDevInfo->ulUserInfoLength );
					pDevInfo->abyDeviceInfo[0]=0;
#endif /* cOCTVC1_MAIN_MSG_OCT1010_INFO_CID */
				}
				else
				{
					pDevInfo->ulUserInfoLength = mMIN( sizeof( pOctDeviceInfo->abyUserInfo), sizeof(pDevInfo->abyUserInfo) );
					memcpy( pDevInfo->abyUserInfo, &pOctDeviceInfo->abyUserInfo, pDevInfo->ulUserInfoLength );
					memcpy( pDevInfo->abyDeviceInfo, &pOctDeviceInfo->abyTargetInfo, cOCTVC1_PKT_API_DEV_INFO_LEN_MAX );
				}
			}
		}
		/* Calculate new elapsed time */
		ulElapsedTimeMs = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(), ulStartTimeMs );
	};
	return Result;
}


/*--------------------------------------------------------------------------
	OctVc1PktApiInstDiscoverDev
----------------------------------------------------------------------------*/
tOCT_UINT32	PktApiInstDiscoverDev(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_CNCT							f_pCnct,
	tPOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS		f_pParms )
{
	tOCTVC1_PKT_API_SESS_OPEN_PARMS	SessOpenParms;
	tOCT_UINT32 Result;
	tPKTAPI_INST_INF *pInst = (tPKTAPI_INST_INF *)f_pInstance;
	
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) ||
		( cOCTVC1_PKT_API_FOREVER == f_pParms->ulTimeoutMs ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	f_pParms->ulDeviceCnt = 0;
	memset( f_pParms->aDeviceInfo, 0x0, sizeof(f_pParms->aDeviceInfo) );

	/* Create the discover session */
	SessOpenParms.pSession					= NULL;
	SessOpenParms.pUserSessionContext		= NULL;
	SessOpenParms.ulControlProcessFifoId	= cOCTVC1_FIFO_ID_CONTROL;

	/* Create it on the discover connection */
	Result = OctVc1PktApiSessOpen( f_pCnct, &SessOpenParms );

	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		tOCTVC1_PKT_API_SESS_CLOSE_PARMS	SessCloseParms;
		tPKTAPI_SESS_INF *					pSessInf;
		tOCT_UINT16							usSessionIndex;

		pSessInf = (tPKTAPI_SESS_INF *)SessOpenParms.pSession;

		mOCTOSAL_ASSERT( NULL != pSessInf );

		/* Modify the session handle to a known value */
		usSessionIndex = (tOCT_UINT16)mPKTAPI_SESS_HANDLE_GET_INDEX( pSessInf->hSession );
		pSessInf->hSession = mPKTAPI_SESS_HANDLE_BUILD_INDEX( 0, usSessionIndex, cPKTAPI_SESS_HANDLE_DISCOVER_UNIQUE );

		{
			/* Send new DEVICE INFO CMD */
			Result = SendTargetInfoCmd(pSessInf);

			if ( cOCTVC1_PKT_API_RC_OK == Result )
			{
				tOCT_BOOL32 fInvalidDevice = cOCT_FALSE;

				/* Use new device info */
				Result = InstDiscoverDevbyInfo( pInst, pSessInf, f_pParms, cOCT_FALSE, &fInvalidDevice );

#ifdef cOCTVC1_MAIN_MSG_OCT1010_INFO_CID
				/* At least one response with TIMEOUT return code */
				if( cOCTVC1_PKT_API_RC_TIMEOUT == Result && fInvalidDevice )
				{
					tPKTAPI_PKT_INF *	pPktInf = NULL;

					/* This device is not knowned try old OCT1010_INFO*/
					tOCTVC1_MAIN_MSG_OCT1010_INFO_CMD	Oct1010InfoCmd;

					/* Get a packet from the discover Q */
					pPktInf = PktApiPktQueueGet(
							cPKTAPI_Q_FREE,
							&pSessInf->pCnct->pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER] );

					/* Prepare the command we wish to send */
					memset( &Oct1010InfoCmd, 0x0, sizeof(Oct1010InfoCmd) );
					Oct1010InfoCmd.Header.ulLength			=
							((sizeof(tOCTVC1_MAIN_MSG_OCT1010_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK);
					Oct1010InfoCmd.Header.ul_Type_R_CmdId	=
							( cOCTVC1_MAIN_MSG_OCT1010_INFO_CID <<cOCTVC1_MSG_ID_BIT_OFFSET&cOCTVC1_MSG_ID_BIT_MASK);
					/* swap the command */
					mOCTVC1_MAIN_MSG_OCT1010_INFO_CMD_SWAP( &Oct1010InfoCmd );
					SendParms.pCmd		= &Oct1010InfoCmd;
					SendParms.pUserCmdContext	= NULL;

					/* Send the command */
					Result = PktApiSessCmdSend(
									pSessInf,
									&SendParms,
									cPKTAPI_Q_SPECIAL,
									cOCTVC1_PKT_API_DEV_MAX * cOCTVC1_PKT_API_DEV_PORT_MAX,
									pPktInf );

					InstDiscoverDevbyInfo( pInst, pSessInf, f_pParms, cOCT_TRUE, &fInvalidDevice );
					
				}
#endif /* cOCTVC1_MAIN_MSG_OCT1010_INFO_CID */
				if( cOCTVC1_PKT_API_RC_TIMEOUT == Result )
					Result = cOCTVC1_PKT_API_RC_OK;
			}
		}

		/* Done, close the session */
		mOCTVC1_PKT_API_SESS_CLOSE_PARMS_DEF( &SessCloseParms );
		SessCloseParms.fForce = cOCT_TRUE;
		OctVc1PktApiSessClose( (tPOCTVC1_PKT_API_SESS)pSessInf, &SessCloseParms );
		/* Clean Q */
		{
			tPKTAPI_PKT_INF *	pPktInf;

			while ( NULL
					!=
					(pPktInf = PktApiPktQueueGet(
										cPKTAPI_Q_BUSY,
										&pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER]) ) )
			{
				PktApiPktQueuePut(
							cPKTAPI_Q_FREE,
							&pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER],
							pPktInf );
			};
			while ( NULL
					!=
					(pPktInf = PktApiPktQueueGet(
										cPKTAPI_Q_SPECIAL,
										&pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER]) ) )
			{
				PktApiPktQueuePut(
							cPKTAPI_Q_FREE,
							&pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER],
							pPktInf );
			};
		}

		if( pInst->hTransDispatcher != NULL )
			PktApiInstDispatchRemoveTransport( pInst, ((tPKTAPI_CNCT_INF *)f_pCnct)->hTransport );
	}
	else
	{
		/* Discover probably ongoing */
		Result = cOCTVC1_PKT_API_RC_INST_DISCOVER_INPROGRESS;
	}	
	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiInstDiscoverDev
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiInstDiscoverDev(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS		f_pParms )
{
	tOCT_UINT32						Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_INST_INF *				pInst;

	/* Validate parameters */
	mOCTOSAL_ASSERT( NULL != f_pInstance );
	mOCTOSAL_ASSERT( NULL != f_pParms );
	mOCTOSAL_ASSERT( cOCTVC1_PKT_API_FOREVER != f_pParms->ulTimeoutMs );

	pInst = (tPKTAPI_INST_INF *)f_pInstance;
	mOCTOSAL_ASSERT( cPKTAPI_MAGIC_INST == pInst->ulMagic );

	f_pParms->ulDeviceCnt = 0;
	memset( f_pParms->aDeviceInfo, 0x0, sizeof(f_pParms->aDeviceInfo) );

	if( pInst->fUseExternalTransport )
	{
		unsigned int ulIndex;
		for( ulIndex=0; ulIndex< f_pParms->ulTransportCnt; ulIndex++ )
		{
			tOCTVC1_PKT_API_CNCT_OPEN_PARMS		CnctOpenParms;
			tOCTTRANSAPI_DESTINATION_ADD_PARMS		DestAdd;
			mOCTTRANSAPI_DESTINATION_ADD_PARMS_DEF( &DestAdd );

			/* Add a broadcast remote */
			if( OctTransApiDestinationAdd( f_pParms->ahTransport[ulIndex], &DestAdd  ) != 0)
				return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

	        /* Prepare the connection */
			CnctOpenParms.hTransDest = DestAdd.hDestination;
		    Result = PktApiCnctPrepare( &pInst->DiscoverCnct, &CnctOpenParms );

			Result = PktApiInstDiscoverDev( f_pInstance, (tPOCTVC1_PKT_API_CNCT)&pInst->DiscoverCnct, f_pParms );

			/* No more discover on this port */
			if( OctTransApiDestinationRemove( DestAdd.hDestination ) != 0)
				return cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;

			pInst->DiscoverCnct.hTransport = NULL;
			pInst->DiscoverCnct.hTransDest = NULL;

			if( Result != cOCTVC1_PKT_API_RC_OK )
				break;
		}
	}
	else
		PktApiInstDiscoverDev( pInst, (tPOCTVC1_PKT_API_CNCT)&pInst->DiscoverCnct, f_pParms );



	return Result;
}


/*--------------------------------------------------------------------------
	PktApiInstDispatchInactivityFnc

	Called by TransportDispatcher when there is inactivity for at least ( cPKTAPI_INST_TIMEOUT_CMD_DEF >> 2)
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR PktApiInstDispatchInactivityFnc( tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS *f_pParms )
{
	tPKTAPI_INST_INF *		pInst;
	tOCTTRANSAPI_RC_ERROR	transRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParms ) || (f_pParms->pInactivityAppContext==NULL) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pInst = (tPKTAPI_INST_INF *)f_pParms->pInactivityAppContext;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	f_pParms->ulElapseInactivityMs = 0; /* do not change it */

	/* Test if have to check timeout */
	if( ( pInst->ulOptionMask &  cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT ) != cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT )
		_PktApiInstQueueTimeoutCheck( pInst );


	return transRc;
}

