/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_CNCT.c

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
#include <memory.h> 
#include <stdlib.h> 

/* User interface */
#include "../../common/octtransapi/include/octtransapi.h"
#include "../../common/octtransapi/include/octtransapi_default.h"

#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api.h"
#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api_default.h"

/* Module interface */
#include "../include/pktapi_inst.h"
#include "../include/pktapi_cnct.h"

/****************************  STATIC FUNCTION ********************************/

/*--------------------------------------------------------------------------
	_PktApiCnctOpen
----------------------------------------------------------------------------*/
static tOCT_UINT32	_PktApiCnctOpen(
	tPKTAPI_INST_INF *								f_pInst,
	tPOCTVC1_PKT_API_CNCT_OPEN_PARMS				f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_INST_CNCT_NOMORE;
	unsigned				ulIndex;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;

	f_pParms->pConnection = NULL;

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	/* Unlock the instance */
	while ( 0 != mPKTAPI_INST_RECVMUTEX_TIMED_SEIZE( f_pInst, 50 ) )
	{
		PktApiInstUnlock( f_pInst, cPKTAPI_INST_UNLOCK_REASON_CNCT_OPEN );
	};
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

    mPKTAPI_INST_MUTEX_SEIZE(f_pInst);

    /* Check if connection not already opened */
    for ( ulIndex=0; ulIndex<f_pInst->ulCnctCnt; ulIndex++ )
    {
        /* Compare connection remote MAC */
		if( ( f_pInst->fUseExternalTransport && ( f_pParms->hTransDest == f_pInst->paCnctInf[ulIndex].hTransDest ) ) ||
			( !f_pInst->fUseExternalTransport && ( 0 == memcmp( f_pInst->paCnctInf[ulIndex].abyRemoteMac, f_pParms->abyRemoteMac, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
        {
            /* Connection already opened */
            f_pParms->pConnection = &f_pInst->paCnctInf[ulIndex];
            f_pParms->pTransportRemoteContext = f_pInst->paCnctInf[ulIndex].pTransportRemoteContext;
            f_pParms->pUserConnectionContext = f_pInst->paCnctInf[ulIndex].pUserContext;

            /* Unlock the instance */
            mPKTAPI_INST_MUTEX_RELEASE(f_pInst);
            mPKTAPI_INST_RECVMUTEX_RELEASE( f_pInst );
            return cOCTVC1_PKT_API_RC_CNCT_ALREADY_OPEN;
        }
    }
    /* Find a free connection */
    for ( ulIndex=0; ulIndex<f_pInst->ulCnctCnt; ulIndex++ )
    {
        /* Find a connection with a NULL remote MAC */
        if( ( f_pInst->fUseExternalTransport && (f_pInst->paCnctInf[ulIndex].hTransDest == NULL )) ||
			( !f_pInst->fUseExternalTransport && ( 0 == memcmp( f_pInst->paCnctInf[ulIndex].abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
        {
            pCnctInf = &f_pInst->paCnctInf[ulIndex];
            break;
        }
    }

    if ( NULL != pCnctInf )
    {
        /* reserve it at instance level */
        f_pInst->Stats.ulOpenConnectionCnt++;

        /* Prepare the connection */
        Result = PktApiCnctPrepare( pCnctInf, f_pParms );
    }

    /* Unlock the instance */
    mPKTAPI_INST_MUTEX_RELEASE(f_pInst);
    mPKTAPI_INST_RECVMUTEX_RELEASE( f_pInst );

	if ( cOCTVC1_PKT_API_RC_OK != Result && cOCTVC1_PKT_API_RC_INST_CNCT_NOMORE != Result )
	{
		/* Close connection */
		tOCTVC1_PKT_API_CNCT_CLOSE_PARMS	CloseParms;
		mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF( &CloseParms );
		CloseParms.fForce = cOCT_TRUE;
		OctVc1PktApiCnctClose( (tPOCTVC1_PKT_API_CNCT)pCnctInf, &CloseParms );
	}


	return Result;
}


/***************************  INTERNAL FUNCTION *******************************/

/*--------------------------------------------------------------------------
	PktApiCnctSetExternalTransport
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiCnctSetExternalTransport( tPKTAPI_CNCT_INF * f_pCnctInf )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tOCTTRANSAPI_DESTINATION_INFO_PARMS DestInfo;
	tOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS PayloadHeader;

	mOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS_DEF( &PayloadHeader );
	if( OctTransApiDestinationPayloadHeaderInfo( f_pCnctInf->hTransDest, &PayloadHeader ) != cOCTTRANSAPI_RC_ERROR_NONE )
		Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
	else
	{
		memcpy( f_pCnctInf->pabyRoutingHeader, PayloadHeader.achHeader, PayloadHeader.ulHeaderLength );

		mOCTTRANSAPI_DESTINATION_INFO_PARMS_DEF( &DestInfo );
		if( OctTransApiDestinationInfo( f_pCnctInf->hTransDest, &DestInfo ) == cOCTVC1_PKT_API_RC_OK )
		{
			f_pCnctInf->hTransport = DestInfo.hTransport;
			f_pCnctInf->ulPktHdrType = DestInfo.ulPktHdrType;

			/* Set routingheaderLen including sizeof(tOCTVOCNET_PKT_HEADER) */
			if( f_pCnctInf->ulPktHdrType == cOCTPKT_HDR_TYPE_ENUM_NORMAL )
				f_pCnctInf->ulRoutingHeaderLen = PayloadHeader.ulHeaderLength + sizeof(tOCTVOCNET_PKT_HEADER);
			else
				f_pCnctInf->ulRoutingHeaderLen = PayloadHeader.ulHeaderLength + sizeof(tOCTVOCNET_PKT_HEADER_XL);
		}
		else
			Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
	}
	return Result;
}


/*--------------------------------------------------------------------------
	PktApiCnctPrepare
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiCnctPrepare(
	tPKTAPI_CNCT_INF *					f_pCnctInf,
	tPOCTVC1_PKT_API_CNCT_OPEN_PARMS	f_pParms )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tOCT_UINT32	ulPayloadAlignmentPadding = cPKTAPI_PAYLOAD_ALIGNMENT_PADDING;

	/* Some assertions */
#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	mOCTOSAL_ASSERT( NULL != f_pCnctInf->hMutex );
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

	/* Prepare the connection */
	if( f_pCnctInf->pInst->fUseExternalTransport )
	{
		f_pCnctInf->hTransDest = f_pParms->hTransDest;
		ulPayloadAlignmentPadding = 0;
	}
	else
		memcpy( f_pCnctInf->abyRemoteMac, f_pParms->abyRemoteMac, cOCTVC1_PKT_API_MAC_ADDR_SIZE );
	
	f_pCnctInf->pTransportRemoteContext	= f_pParms->pTransportRemoteContext;
	f_pCnctInf->pUserContext				= f_pParms->pUserConnectionContext;
	/* Set pointer to routing header misaligned at the begining (ethernet header) in order
	to have aligned payload pointer */
	mOCTOSAL_ASSERT( 0 == ((tOCTOSAL_UINT_PTR)f_pCnctInf->abyMemory) % 4 );

	f_pCnctInf->pabyRoutingHeader = &f_pCnctInf->abyMemory[ulPayloadAlignmentPadding];
	f_pCnctInf->ulPktHdrType = cOCTPKT_HDR_TYPE_ENUM_NORMAL;

	/* Assume everything is going well */
	Result = cOCTVC1_PKT_API_RC_OK;

	if( f_pCnctInf->pInst->fUseExternalTransport )
		Result = PktApiCnctSetExternalTransport( f_pCnctInf );
	else
	{
		/* Prepare the routing headers */
		f_pCnctInf->ulRoutingHeaderLen = cPKTAPI_ETH_II_HEADER_SIZE + sizeof(tOCTVOCNET_PKT_HEADER);
		/* Destination MAC */
		memcpy( 
				&f_pCnctInf->pabyRoutingHeader[0],
					f_pCnctInf->abyRemoteMac, cOCTVC1_PKT_API_MAC_ADDR_SIZE );
		/* Source MAC */
		memcpy( 
				&f_pCnctInf->pabyRoutingHeader[6],
				f_pCnctInf->pInst->abyLocalMac,
				cOCTVC1_PKT_API_MAC_ADDR_SIZE );

		/* EtherType */
		f_pCnctInf->pabyRoutingHeader[12] = (cOCTVOCNET_PKT_ETHERTYPE>>8)& 0xFF;
		f_pCnctInf->pabyRoutingHeader[13] = (cOCTVOCNET_PKT_ETHERTYPE)& 0xFF;
	}

	if( ( f_pCnctInf->pInst->hTransDispatcher != NULL ) && f_pCnctInf->hTransport )
	{
		/* Tell dispatcher to dispatch here */
		Result = PktApiInstDispatchAddTransport( f_pCnctInf->pInst, f_pCnctInf->hTransport );
	}

		/* Set connection pointer */
	if( Result == cOCTVC1_PKT_API_RC_OK )
		f_pParms->pConnection = f_pCnctInf;

	return Result;
}

/*--------------------------------------------------------------------------
	PktApiCnctPktSend
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiCnctPktSend(
	tPKTAPI_CNCT_INF *					f_pCnctInf,
	unsigned int						f_ulQIndex,
	unsigned int						f_ulPktQType,
	unsigned int						f_ulFormat,
	tPKTAPI_PKT_INF *					f_pPktInf )
{
	int						iRc;
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	int						iPacketLen;

	/* Is this a control packet ? */
	if ( f_ulFormat == cOCTVOCNET_PKT_FORMAT_CTRL )
	{
		/* Update transaction ID, session and user info */
		tOCTVC1_MSG_HEADER *		pMsgHeader;
		tOCT_UINT32					ulTypeRCmd;

		/* Now move to message header */
		pMsgHeader = (tOCTVC1_MSG_HEADER *)(
						(unsigned char *)f_pPktInf->RecvParms.pPayload 
						+ f_pCnctInf->ulRoutingHeaderLen
						+ sizeof(tOCTVOCNET_PKT_CTL_HEADER));

		

		pMsgHeader->ulTransactionId	= mOCT_SWAP32_IF_LE( f_pPktInf->ulTransactionId );
		pMsgHeader->ulSessionId		= mOCT_SWAP32_IF_LE( f_pPktInf->ulSessionId );

		/* Remove resynch flag to header */
		ulTypeRCmd = mOCT_SWAP32_IF_LE( pMsgHeader->ul_Type_R_CmdId ) 
										& ~(cOCTVC1_MSG_RESYNCH_BIT_MASK << cOCTVC1_MSG_RESYNCH_BIT_OFFSET)
										& ~(cOCTVC1_MSG_RETRANSMIT_FLAG); 

		/* Test if retransmit */
		if (( f_pPktInf->ulFlag & cPKTAPI_PKT_INF_FLAG_MASK_RETRANSMIT ) == 0 )
		{
			/* Store the user information */
			f_pPktInf->ulUserInfo		= pMsgHeader->ulUserInfo;
			/* Set our user information */
			pMsgHeader->ulUserInfo		= f_ulPktQType;
		}
		else
		{
			ulTypeRCmd |= (cOCTVC1_MSG_RETRANSMIT_FLAG);
		}

		/* Test Re-synch */
		if(( f_pPktInf->ulFlag & cPKTAPI_PKT_INF_FLAG_MASK_RESYNC ) == cPKTAPI_PKT_INF_FLAG_MASK_RESYNC )
			ulTypeRCmd |= (cOCTVC1_MSG_RESYNCH_BIT_MASK << cOCTVC1_MSG_RESYNCH_BIT_OFFSET);

		pMsgHeader->ul_Type_R_CmdId = mOCT_SWAP32_IF_LE( ulTypeRCmd );

	}

	/* CHck if pkt is already set */
	if (( f_pPktInf->ulFlag & cPKTAPI_PKT_INF_FLAG_MASK_RETRANSMIT ) ==  0 )
	{
		memcpy( f_pPktInf->RecvParms.pPayload, f_pCnctInf->pabyRoutingHeader, f_pCnctInf->ulRoutingHeaderLen );

		if( f_pCnctInf->ulPktHdrType == cOCTPKT_HDR_TYPE_ENUM_NORMAL )
		{
			tOCT_UINT32				ul_Format_Trace_Length;
			tOCTVOCNET_PKT_HEADER *	pVocnetPktHeader = (tOCTVOCNET_PKT_HEADER *)(
							(unsigned char *)f_pPktInf->RecvParms.pPayload 
							+ f_pCnctInf->ulRoutingHeaderLen - sizeof(tOCTVOCNET_PKT_HEADER) );

			/* Create the vocnet packet header */
			ul_Format_Trace_Length = (f_ulFormat & cOCTVOCNET_PKT_FORMAT_BIT_MASK)<<cOCTVOCNET_PKT_FORMAT_BIT_OFFSET;

			/* Create length and trace dword (add the packet header in length) */
			ul_Format_Trace_Length = ul_Format_Trace_Length 
				| ( 
					((f_pPktInf->RecvParms.ulRcvPayloadLength + sizeof(tOCTVOCNET_PKT_HEADER)) & cOCTVOCNET_PKT_LENGTH_BIT_MASK )
					<< cOCTVOCNET_PKT_LENGTH_BIT_OFFSET );


			pVocnetPktHeader->ul_Format_Trace_Length = mOCT_SWAP32_IF_LE( ul_Format_Trace_Length );
		}
		else
		{
			tOCT_UINT32				ul_Proto_Format_Length;
			tOCTVOCNET_PKT_HEADER_XL *	pVocnetPktHeaderXl = (tOCTVOCNET_PKT_HEADER_XL *)(
							(unsigned char *)f_pPktInf->RecvParms.pPayload 
							+ f_pCnctInf->ulRoutingHeaderLen - sizeof(tOCTVOCNET_PKT_HEADER_XL) );

			/* Create the vocnet packet header */
			ul_Proto_Format_Length = (f_ulFormat & cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK)<<cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET;

			/* Create length and trace dword (add the packet header in length) */
			ul_Proto_Format_Length = ul_Proto_Format_Length 
				| ( 
					((f_pPktInf->RecvParms.ulRcvPayloadLength + sizeof(tOCTVOCNET_PKT_HEADER_XL)) & cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK )
					<< cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET );


			pVocnetPktHeaderXl->ul_Proto_Format_Length = mOCT_SWAP32_IF_LE( ul_Proto_Format_Length );
		}

		/* Adjust the payload size */
		f_pPktInf->RecvParms.ulRcvPayloadLength += f_pCnctInf->ulRoutingHeaderLen;
	}

	/* Local copy of packet len value */
	iPacketLen = f_pPktInf->RecvParms.ulRcvPayloadLength;

	/* Only valid packet type are queued */
	if ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID != f_ulPktQType )
    {
		/* Put in Q */
		PktApiPktQueuePut(
					f_ulQIndex,
					&f_pCnctInf->pInst->paPktQ[f_ulPktQType],
					f_pPktInf );

	}

	/* Send on transport */
	if( f_pCnctInf->pInst->fUseExternalTransport )
	{
		tOCTTRANSAPI_DESTINATION_SEND_PARMS	DestSend;
		mOCTTRANSAPI_DESTINATION_SEND_PARMS_DEF( &DestSend );
		DestSend.pBuffer = (tOCT_UINT8 *)f_pPktInf->RecvParms.pPayload;
		DestSend.ulBufferLength = iPacketLen;
		iRc = OctTransApiDestinationSend( f_pCnctInf->hTransDest, &DestSend );
		if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
			iRc = DestSend.ulBufferLength;

    }
	else
	{
		iRc = f_pCnctInf->pInst->TransportFunc.pfnTransportApiSend(
						f_pCnctInf->pInst->hTransport,
						f_pCnctInf->pTransportRemoteContext,
						f_pPktInf->RecvParms.pPayload,
						iPacketLen );
	}


	if ( iRc > 0
		&&
		iPacketLen == iRc )
	{
		f_pCnctInf->Stats.ulTotalPktSentCnt++;
		f_pCnctInf->pInst->Stats.ulTotalPktSentCnt++;
	}
	else
	{
		if ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID != f_ulPktQType )
		{
			/* Extract from the Q */
			/* Returning error will take care of the packet */
			PktApiPktQueueExtract(
									f_ulQIndex,
									&f_pCnctInf->pInst->paPktQ[f_ulPktQType],
									f_pPktInf->ulSessionId,
									f_pPktInf->ulTransactionId );

		}

		Result = cOCTVC1_PKT_API_RC_TRANSPORT_ERROR;
	}

	return Result;
}

/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctOpen
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiCnctOpen(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_CNCT_OPEN_PARMS				f_pParms )
{
	tPKTAPI_INST_INF *		pInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pInstance ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pInst = (tPKTAPI_INST_INF *)f_pInstance;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_INST != pInst->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
			
	if( pInst->fUseExternalTransport &&( NULL == f_pParms->hTransDest ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;	
	else if( !pInst->fUseExternalTransport &&
		( ( 0 == memcmp( f_pParms->abyRemoteMac, g_abyPktApiMacAddrBroadcast, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ||
		  ( 0 == memcmp( f_pParms->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
	{
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	return _PktApiCnctOpen( pInst, f_pParms );

}

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctClose
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiCnctClose(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_CLOSE_PARMS				f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pConnection ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pCnctInf = (tPKTAPI_CNCT_INF *)f_pConnection;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_CNCT != pCnctInf->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */
	
	mOCTOSAL_ASSERT( NULL != pCnctInf->pInst );

	/* Lock the connection */
	mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

	/* test if cnct is close */
	if( ( pCnctInf->pInst->fUseExternalTransport && ( pCnctInf->hTransDest == NULL ) ) ||
		( !pCnctInf->pInst->fUseExternalTransport && ( 0 == memcmp( pCnctInf->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
		Result = cOCTVC1_PKT_API_RC_CNCT_CLOSE;

	/* Release lock */
	mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );

	if( Result != cOCTVC1_PKT_API_RC_OK )
		return Result;

	/* Unlock select (if needed) */
#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	/* Unlock the instance */
	while ( 0 != mPKTAPI_INST_RECVMUTEX_TIMED_SEIZE( pCnctInf->pInst, 50 ) )
	{
		PktApiInstUnlock( pCnctInf->pInst, cPKTAPI_INST_UNLOCK_REASON_CNCT_CLOSE );
	};
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */


	/* Do we have sessions opened ? */
	if ( 0 != pCnctInf->Stats.ulOpenSessionCnt )
	{
		if ( f_pParms->fForce )
		{
			unsigned int	ulIndex;

			for ( ulIndex=0; ulIndex<pCnctInf->ulSessCnt; ulIndex++ )
			{
				if ( cPKTAPI_SESS_SESSION_INVALID != pCnctInf->paSessInf[ulIndex].hSession )
				{
					tOCTVC1_PKT_API_SESS_CLOSE_PARMS	CloseParms;
					mOCTVC1_PKT_API_SESS_CLOSE_PARMS_DEF( &CloseParms );
					CloseParms.fForce = cOCT_TRUE;

					Result = OctVc1PktApiSessClose( (tPOCTVC1_PKT_API_SESS)&pCnctInf->paSessInf[ulIndex], &CloseParms );

					if ( cOCTVC1_PKT_API_RC_OK != Result )
						break;
				}
			}
		}
		else
		{
			Result = cOCTVC1_PKT_API_RC_CNCT_SESS_DEP;
		}
	}

	if ( cOCTVC1_PKT_API_RC_OK == Result )
	{
		/* Lock the connection */
		mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

		/* Clean up MAC */
		memset( pCnctInf->abyRemoteMac, 0x0, sizeof(pCnctInf->abyRemoteMac) );
		/* Clean up stats */
		memset( &pCnctInf->Stats, 0x0, sizeof(pCnctInf->Stats) );


		if(( pCnctInf->pInst->hTransDispatcher != NULL ) &&
			( pCnctInf->hTransport != NULL ) )
		{
			PktApiInstDispatchRemoveTransport( pCnctInf->pInst, pCnctInf->hTransport );
		}

		pCnctInf->hTransDest = NULL;
		pCnctInf->hTransport = NULL;

		/* Release lock */
		mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );

		mPKTAPI_INST_MUTEX_SEIZE( pCnctInf->pInst );

		/* Update instance stats */
		pCnctInf->pInst->Stats.ulOpenConnectionCnt--;

		/* Unlock the instance */
		mPKTAPI_INST_MUTEX_RELEASE( pCnctInf->pInst );
	}

	mPKTAPI_INST_RECVMUTEX_RELEASE( pCnctInf->pInst );

	return Result;
}


/*--------------------------------------------------------------------------
	OctVc1PktApiCnctInfo
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiCnctInfo(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_INFO_PARMS				f_pParms)
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pConnection ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pCnctInf = (tPKTAPI_CNCT_INF *)f_pConnection;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_CNCT != pCnctInf->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mOCTOSAL_ASSERT( NULL != pCnctInf->pInst );

	mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

	/* test if cnct is close */
	if( ( pCnctInf->pInst->fUseExternalTransport && ( pCnctInf->hTransDest == NULL ) ) ||
		( !pCnctInf->pInst->fUseExternalTransport && ( 0 == memcmp( pCnctInf->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
		Result = cOCTVC1_PKT_API_RC_CNCT_CLOSE;

	if( Result == cOCTVC1_PKT_API_RC_OK )
	{
		/* Transfer the connection info */
		f_pParms->hTransDest = pCnctInf->hTransDest;
		memcpy( &f_pParms->abyRemoteMac, &pCnctInf->abyRemoteMac, sizeof( f_pParms->abyRemoteMac ));
		f_pParms->pTransportRemoteContext	= pCnctInf->pTransportRemoteContext;
		f_pParms->pUserConnectionContext	= pCnctInf->pUserContext;
	}

	mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );

	return Result;
}
/*--------------------------------------------------------------------------
	OctVc1PktApiCnctModify
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiCnctModify(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_MODIFY_PARMS			f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pConnection ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pCnctInf = (tPKTAPI_CNCT_INF *)f_pConnection;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_CNCT != pCnctInf->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;

	if( ( pCnctInf->pInst->fUseExternalTransport && ( f_pParms->hTransDest == NULL ) ) ||
		( !pCnctInf->pInst->fUseExternalTransport && 
		( ( 0 == memcmp( f_pParms->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ||
		  ( 0 == memcmp( f_pParms->abyRemoteMac, g_abyPktApiMacAddrBroadcast, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) )	) ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
		
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

	/* test if cnct is close */
	if( ( pCnctInf->pInst->fUseExternalTransport && ( pCnctInf->hTransDest == NULL ) ) ||
		( !pCnctInf->pInst->fUseExternalTransport && 
		( ( 0 == memcmp( pCnctInf->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) ) )
		Result = cOCTVC1_PKT_API_RC_CNCT_CLOSE;

	if( Result == cOCTVC1_PKT_API_RC_OK )
	{
		/* Prepare the connection */
		memcpy( &pCnctInf->abyRemoteMac, &f_pParms->abyRemoteMac, sizeof( f_pParms->abyRemoteMac ));
		pCnctInf->pTransportRemoteContext	= f_pParms->pTransportRemoteContext;
		pCnctInf->pUserContext				= f_pParms->pUserConnectionContext;
		pCnctInf->hTransDest				= f_pParms->hTransDest;
		pCnctInf->ulPktHdrType				= cOCTPKT_HDR_TYPE_ENUM_NORMAL;

		if( pCnctInf->pInst->fUseExternalTransport )
		{
			Result = PktApiCnctSetExternalTransport( pCnctInf );
		}
		else	/* Destination MAC */
			memcpy( &pCnctInf->pabyRoutingHeader[0], pCnctInf->abyRemoteMac, cOCTVC1_PKT_API_MAC_ADDR_SIZE );
	}
	mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );

	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctStats
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiCnctStats(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_STATS_PARMS				f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;
	tOCT_UINT32				fClear;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pConnection ) ||
		( NULL == f_pParms ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pCnctInf = (tPKTAPI_CNCT_INF *)f_pConnection;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_CNCT != pCnctInf->ulMagic )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

	/* test if cnct is close */
	if( ( pCnctInf->pInst->fUseExternalTransport && ( pCnctInf->hTransDest == NULL ) ) ||
		( !pCnctInf->pInst->fUseExternalTransport && ( 0 == memcmp( pCnctInf->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
		Result = cOCTVC1_PKT_API_RC_CNCT_CLOSE;

	if( Result == cOCTVC1_PKT_API_RC_OK )
	{
		fClear = f_pParms->fClear;

		memcpy( f_pParms, &pCnctInf->Stats, sizeof(pCnctInf->Stats) );

		if ( cOCT_TRUE == fClear )
		{
			tOCT_UINT32		ulOpenSessionCnt;

			/* Latch open counters */
			ulOpenSessionCnt	= pCnctInf->Stats.ulOpenSessionCnt; 

			/* Clear the stats */
			memset( &pCnctInf->Stats, 0x0, sizeof(pCnctInf->Stats) );
			/* Copy back the open counters */
			pCnctInf->Stats.ulOpenSessionCnt		= ulOpenSessionCnt;

		}
	}
	mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );
	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctDataSend
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiCnctDataSend(
	tPOCTVC1_PKT_API_CNCT						f_pConnection,
	tPOCTVC1_PKT_API_DATA_SEND_PARMS			f_pParms )
{
	tOCT_UINT32		Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_CNCT_INF *	pCnctInf = NULL;
	
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	/* Validate parameters */
	if( ( NULL == f_pConnection ) ||
		( NULL == f_pParms ) ||
		( NULL == f_pParms->pData ) ||
		( 0 == f_pParms->ulLength ) ||
		( cOCTVOCNET_PKT_FORMAT_CTRL == f_pParms->ulFormat ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pCnctInf = (tPKTAPI_CNCT_INF *)f_pConnection;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if(
		( cPKTAPI_MAGIC_CNCT != pCnctInf->ulMagic ) ||
		( (cPKTAPI_PAYLOAD_MAX - pCnctInf->ulRoutingHeaderLen) < f_pParms->ulLength ) )
		return cOCTVC1_PKT_API_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Lock the connection to exclusively use the static packet */
    mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

    /* test if cnct is close */
	if( ( pCnctInf->pInst->fUseExternalTransport && ( pCnctInf->hTransDest == NULL ) ) ||
		( !pCnctInf->pInst->fUseExternalTransport && ( 0 == memcmp( pCnctInf->abyRemoteMac, g_abyPktApiMacAddrNull, cOCTVC1_PKT_API_MAC_ADDR_SIZE ) ) ) )
        Result = cOCTVC1_PKT_API_RC_CNCT_CLOSE;

    if( Result == cOCTVC1_PKT_API_RC_OK )
    {
        /* Copy data payload */
		memcpy( (unsigned char *)pCnctInf->StaticPktInf.RecvParms.pPayload + pCnctInf->ulRoutingHeaderLen,
            (unsigned char *)f_pParms->pData,
            f_pParms->ulLength );


        /* Set payload size */
        pCnctInf->StaticPktInf.RecvParms.ulRcvPayloadLength = f_pParms->ulLength;

        /* Send the packet without Queuing info */
        Result = PktApiCnctPktSend(
                    pCnctInf,
                    cPKTAPI_Q_INVALID,
                    cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID,
                    f_pParms->ulFormat,
                    &pCnctInf->StaticPktInf );

    }
    /* unlock the connection */
    mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );

	return Result;
}


