/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_SESS.c

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

/* Module interface */
#include "../include/pktapi_inst.h"
#include "../include/pktapi_cnct.h"
#include "../include/pktapi_sess.h"
#include "../include/pktapi_pkt.h"


/****************************  STATIC FUNCTION ********************************/

/***************************  INTERNAL FUNCTION *******************************/
/*--------------------------------------------------------------------------
	PktApiSessCmdSend
----------------------------------------------------------------------------*/
tOCT_UINT32	PktApiSessCmdSend(
	tPKTAPI_SESS_INF *					f_pSessInf,
	tPOCTVC1_PKT_API_CMD_SEND_PARMS		f_pParms,
	unsigned int						f_ulQIndex,
	unsigned int						f_ulDependencyCnt,
	tPKTAPI_PKT_INF *					f_pPktInf )
{
	tOCT_UINT32					Result = cOCTVC1_PKT_API_RC_OK;
	tOCTVOCNET_PKT_CTL_HEADER *	pCtlHeader;
	tOCTVC1_MSG_HEADER *		pMsgHeader;
	tOCT_UINT32					ulTemp;
	tOCT_UINT32					ulCmdId;
	tOCT_UINT32					ulTimeoutMs	= cPKTAPI_INST_TIMEOUT_CMD_DEF;

	/* Extract required informations */
	pMsgHeader = (tOCTVC1_MSG_HEADER *)f_pParms->pCmd;

	f_pPktInf->RecvParms.ulRcvPayloadLength		= (mOCT_SWAP32_IF_LE( pMsgHeader->ulLength ) 
													>> cOCTVC1_MSG_LENGTH_BIT_OFFSET ) & cOCTVC1_MSG_LENGTH_BIT_MASK;
	f_pPktInf->RecvParms.Info.Rsp.ulCmdId			= (mOCT_SWAP32_IF_LE( pMsgHeader->ul_Type_R_CmdId ) 
													>> cOCTVC1_MSG_ID_BIT_OFFSET )& cOCTVC1_MSG_ID_BIT_MASK;
	f_pPktInf->RecvParms.Info.Rsp.pUserCmdContext = f_pParms->pUserCmdContext;

	/* Be sure we have valid data */
	mOCTOSAL_ASSERT( 0 != f_pPktInf->RecvParms.ulRcvPayloadLength );
	mOCTOSAL_ASSERT( 0 != f_pPktInf->RecvParms.Info.Rsp.ulCmdId );

	/* Lock the session for Resynch and transaction update */
	mPKTAPI_SESS_MUTEX_SEIZE( f_pSessInf );

	/* Remove resynch flag to header */
	ulTemp = mOCT_SWAP32_IF_LE( pMsgHeader->ul_Type_R_CmdId ) 
									& ~(cOCTVC1_MSG_RESYNCH_BIT_MASK << cOCTVC1_MSG_RESYNCH_BIT_OFFSET); 
	pMsgHeader->ul_Type_R_CmdId = mOCT_SWAP32_IF_LE( ulTemp ); 

	/* Copy or set payload */
	memcpy( (unsigned char *)f_pPktInf->RecvParms.pPayload + f_pSessInf->pCnct->ulRoutingHeaderLen + sizeof(*pCtlHeader),
			(unsigned char *)f_pParms->pCmd,
			f_pPktInf->RecvParms.ulRcvPayloadLength );

	/* Add packet control header length */
	f_pPktInf->RecvParms.ulRcvPayloadLength += sizeof(*pCtlHeader);

	/* Now move to control header */
	pCtlHeader = (tOCTVOCNET_PKT_CTL_HEADER *)(
					(unsigned char *)f_pPktInf->RecvParms.pPayload 
					+ f_pSessInf->pCnct->ulRoutingHeaderLen );

	pCtlHeader->ulDestFifoId	= mOCT_SWAP32_IF_LE( f_pSessInf->ulProcessFifoId );
	pCtlHeader->ulSourceFifoId	= mOCT_SWAP32_IF_LE( cPKTAPI_FIFO_ID_MSG );
	pCtlHeader->ulSocketId		= mOCT_SWAP32_IF_LE( 0 );

	/* Fill the originator */
	f_pPktInf->RecvParms.pConnection	= (tPOCTVC1_PKT_API_CNCT)f_pSessInf->pCnct;
	f_pPktInf->RecvParms.pSession		= (tPOCTVC1_PKT_API_SESS)f_pSessInf;
	f_pPktInf->RecvParms.pUserConnectionContext	= f_pSessInf->pCnct->pUserContext;
	f_pPktInf->RecvParms.pUserSessionContext		= f_pSessInf->pUserContext;

	f_pPktInf->ulSessionId		= f_pSessInf->hSession;
	f_pPktInf->ulRetry			= 0;

	/* Time stamp */
	f_pPktInf->ulStartTimeMs	= OctOsalGetTimeMs();
	f_pPktInf->ulFlag			|= (f_ulDependencyCnt & cPKTAPI_PKT_INF_FLAG_MASK_DEPENDENCY_CNT);

	/* Check for smart timeout management */
	ulCmdId = mOCT_SWAP32_IF_LE( pMsgHeader->ul_Type_R_CmdId );
	/* 
		Check for flags according to unofficial hierachy of flags 
		For timeout setting:
			- Long command have precedence over no-response
	*/
	if ( ulCmdId & cOCTVC1_MSG_LONG_PROCESSING_FLAG )
	{
		ulTimeoutMs = cPKTAPI_INST_LONG_TIMEOUT_CMD_DEF;
	}
	else if ( ulCmdId & cOCTVC1_MSG_MID_PROCESSING_FLAG )
	{
		ulTimeoutMs = cPKTAPI_INST_MID_TIMEOUT_CMD_DEF;
	}
	else if ( ulCmdId & cOCTVC1_MSG_NO_RESPONSE_FLAG )
	{
		ulTimeoutMs = cPKTAPI_INST_TIMEOUT_CMD_DEF;
	}


	if(( f_pSessInf->ulPendingRspCount < cPKTAPI_SESS_PENDING_RSP_MAX ) && 
	   ( ( f_pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_FORCE_PENDING ) == 0 )  )
	{
		/* Allocate a transaction ID */
		f_pPktInf->ulTransactionId	= f_pSessInf->ulTransactionId++;

		/* Set transaction Id for debug purpose */
		pMsgHeader->ulTransactionId = mOCT_SWAP32_IF_LE( f_pPktInf->ulTransactionId );
		pMsgHeader->ulSessionId = mOCT_SWAP32_IF_LE( f_pPktInf->ulSessionId );

		/* Update time out */
		f_pSessInf->ulActiveTimeout += ulTimeoutMs;

		/* Set time out elapse time */
		f_pPktInf->ulTimeoutMs = f_pSessInf->ulActiveTimeout;
	
		/* Do we resynch this session */
		if(  f_pSessInf->fFlag & cPKTAPI_SESS_INF_FLAG_MASK_RESYNC )
		{
			f_pPktInf->ulFlag |= cPKTAPI_PKT_INF_FLAG_MASK_RESYNC;
			f_pSessInf->fFlag &= ~cPKTAPI_SESS_INF_FLAG_MASK_RESYNC;
		}

		/* Get ready, send */
		Result = PktApiCnctPktSend(
						f_pSessInf->pCnct,
						f_ulQIndex,
						f_pPktInf->ulOwnerQ,
						cOCTVOCNET_PKT_FORMAT_CTRL,
						f_pPktInf );

		if ( cOCTVC1_PKT_API_RC_OK == Result )
		{
			f_pSessInf->Stats.ulPktSentCnt++;
			f_pSessInf->ulPendingRspCount++;

		}
		else
		{
			f_pSessInf->ulActiveTimeout -= ulTimeoutMs;
		}
	}
	else
	{
		/* Put this pkt in pending q */
		PktApiPktQueuePut(
						cPKTAPI_Q_BUSY,
						&f_pSessInf->PktQPendingCmd,
						f_pPktInf );
	}

	mPKTAPI_SESS_MUTEX_RELEASE( f_pSessInf );

	return Result;
}

/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
	OctVc1PktApiSessOpen
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiSessOpen(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_SESS_OPEN_PARMS				f_pParms )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_CNCT_SESS_NOMORE;
	tPKTAPI_CNCT_INF *		pCnctInf = NULL;
	tPKTAPI_SESS_INF *		pSessInf = NULL;
	unsigned int			ulIndex;
	
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pConnection ) ||
		( NULL == f_pParms )  )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pCnctInf = (tPKTAPI_CNCT_INF *)f_pConnection;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_CNCT != pCnctInf->ulMagic )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mOCTOSAL_ASSERT( NULL != pCnctInf->pInst );

	/* Lock connection */
    mPKTAPI_CNCT_MUTEX_SEIZE( pCnctInf );

    /* Check if session not already opened */
    for ( ulIndex=0; ulIndex<pCnctInf->ulSessCnt; ulIndex++ )
    {
        /* Compare session fifo */
        if ( pCnctInf->paSessInf[ulIndex].hSession == f_pParms->ulControlProcessFifoId )
        {
            /* session already opened */
            f_pParms->pSession = &pCnctInf->paSessInf[ulIndex];
            f_pParms->pUserSessionContext = pCnctInf->paSessInf[ulIndex].pUserContext;

            /* Unlock the session */
            mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );
            return cOCTVC1_PKT_API_RC_SESS_ALREADY_OPEN;
        }
    }

    /* Find a free session */
    for ( ulIndex=0;ulIndex<pCnctInf->ulSessCnt; ulIndex++ )
    {
        if ( cPKTAPI_SESS_SESSION_INVALID == pCnctInf->paSessInf[ulIndex].hSession )
        {
            /* Reserve it */
            pSessInf = &pCnctInf->paSessInf[ulIndex];

            if ( !pSessInf->usInstance )
            {
                pSessInf->usInstance = 1;
            }
            /* Skip the discover unique value */
            if ( cPKTAPI_SESS_HANDLE_DISCOVER_UNIQUE == pSessInf->usInstance )
            {
                pSessInf->usInstance++;
            }

            pSessInf->hSession = mPKTAPI_SESS_HANDLE_BUILD_INDEX( pCnctInf->byIndex, ulIndex, pSessInf->usInstance++ );
            pCnctInf->Stats.ulOpenSessionCnt++;
            pCnctInf->pInst->Stats.ulOpenSessionCnt++;
            Result = cOCTVC1_PKT_API_RC_OK;
#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
            mOCTOSAL_ASSERT( NULL != pSessInf->hMutex );
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

            break;
        }
    }

    /* Unlock connection */
    mPKTAPI_CNCT_MUTEX_RELEASE( pCnctInf );

    /* Do we have a session ? */
    if ( NULL != pSessInf )
    {
        /* Prepare the session */
        pSessInf->pUserContext		= f_pParms->pUserSessionContext;
        pSessInf->ulProcessFifoId	= f_pParms->ulControlProcessFifoId;
        /* Force resynchronization */
        pSessInf->fFlag = cPKTAPI_SESS_INF_FLAG_MASK_RESYNC | cPKTAPI_SESS_INF_FLAG_MASK_ALLOW_RESEND;

        f_pParms->pSession = (tPOCTVC1_PKT_API_SESS)pSessInf;

        /* Close that session on error */
        if ( cOCTVC1_PKT_API_RC_OK != Result )
        {
            if ( NULL != pSessInf )
            {
                tOCTVC1_PKT_API_SESS_CLOSE_PARMS	CloseParms;
                mOCTVC1_PKT_API_SESS_CLOSE_PARMS_DEF( &CloseParms );
                OctVc1PktApiSessClose( (tPOCTVC1_PKT_API_SESS)pSessInf, &CloseParms );
            }
        }
    }

	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiSessClose
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiSessClose(
	tPOCTVC1_PKT_API_SESS 							f_pSession,
	tPOCTVC1_PKT_API_SESS_CLOSE_PARMS				f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_SESS_INF *		pSessInf;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pSession ) ||
		( NULL == f_pParms )  )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pSessInf = (tPKTAPI_SESS_INF *)f_pSession;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_SESS != pSessInf->ulMagic )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct );

	if( pSessInf->hSession == cPKTAPI_SESS_SESSION_INVALID )
		return cOCTVC1_PKT_API_RC_SESS_CLOSE;

	/* Lock connection */
    mPKTAPI_SESS_MUTEX_SEIZE( pSessInf );

    /* Find if any cmd pending */
    if( f_pParms->fForce != cOCT_TRUE )
    {
        mOCTOSAL_ASSERT( NULL != pSessInf->pCnct->pInst );
        if( ( 0!= PktApiPktQueueCountGet( cPKTAPI_Q_BUSY, &pSessInf->PktQPendingCmd ) ) ||
            ( pSessInf->ulPendingRspCount != 0 ) )
            Result = cOCTVC1_PKT_API_RC_DEPENDENCIES;
    }

    if( Result == cOCTVC1_PKT_API_RC_OK )
    {
        /* Put Pending Pkt in Free Q */
        tPKTAPI_PKT_INF *	pCmdPktInf = NULL;

        /* Loop all Q to resend timeout msg */
        unsigned int i;

        /* Find out the transaction in one of the command Q*/
        for ( i=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD; i<pSessInf->pCnct->pInst->ulPktQCnt; )
        {
            pCmdPktInf = PktApiPktQueueExtract(
                                    ( cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD == i ) ? cPKTAPI_Q_BUSY:cPKTAPI_Q_SPECIAL,
                                    &pSessInf->pCnct->pInst->paPktQ[i],
                                    pSessInf->hSession,
                                    0 );

            if ( NULL != pCmdPktInf )
            {
                PktApiPktQueuePut(
                            cPKTAPI_Q_FREE,
                            &pSessInf->pCnct->pInst->paPktQ[pCmdPktInf->ulOwnerQ],
                            pCmdPktInf );
            }
            else
                i++;
        }

        /* Put Pending Pkt in Free Q */
        pCmdPktInf = NULL;
        do{
            pCmdPktInf = PktApiPktQueueGet( cPKTAPI_Q_BUSY, &pSessInf->PktQPendingCmd );
            if( pCmdPktInf )
                PktApiPktQueuePut(
                            cPKTAPI_Q_FREE,
                            &pSessInf->pCnct->pInst->paPktQ[pCmdPktInf->ulOwnerQ],
                            pCmdPktInf );

        }while( pCmdPktInf != NULL );

        /* Clear number of pending response */
        pSessInf->ulPendingRspCount = 0;
        pSessInf->fFlag = cPKTAPI_SESS_INF_FLAG_MASK_NONE;
        pSessInf->ulActiveTimeout	= 0;

        /* Clear it */
        pSessInf->hSession			= cPKTAPI_SESS_SESSION_INVALID;
        pSessInf->ulTransactionId	= 1;
        pSessInf->ulRxTransactionId = pSessInf->ulTransactionId;
        pSessInf->ulRxRejectId		= pSessInf->ulResentId	= 0;


        /* Clean up stats */
        memset( &pSessInf->Stats, 0x0, sizeof(pSessInf->Stats) );
    }

    mPKTAPI_SESS_MUTEX_RELEASE( pSessInf );

	if( Result == cOCTVC1_PKT_API_RC_OK )
	{
		/* Lock connection */
        mPKTAPI_CNCT_MUTEX_SEIZE( pSessInf->pCnct );

        pSessInf->pCnct->Stats.ulOpenSessionCnt--;
        pSessInf->pCnct->pInst->Stats.ulOpenSessionCnt--;

        /* Unlock connection */
        mPKTAPI_CNCT_MUTEX_RELEASE( pSessInf->pCnct );
	}
	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiSessStats
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiSessStats(
	tPOCTVC1_PKT_API_SESS 							f_pSession,
	tPOCTVC1_PKT_API_SESS_STATS_PARMS				f_pParms )
{
	tOCT_UINT32				Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_SESS_INF *		pSessInf;
	tOCT_UINT32				fClear;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pSession ) ||
		( NULL == f_pParms )  )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pSessInf = (tPKTAPI_SESS_INF *)f_pSession;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_SESS != pSessInf->ulMagic )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( pSessInf->hSession == cPKTAPI_SESS_SESSION_INVALID )
		return cOCTVC1_PKT_API_RC_SESS_CLOSE;

	fClear = f_pParms->fClear;
	memcpy( f_pParms, &pSessInf->Stats, sizeof(pSessInf->Stats) );

	if ( cOCT_TRUE == fClear )
	{
		/* Clear the stats */
		memset( &pSessInf->Stats, 0x0, sizeof(pSessInf->Stats) );
	}

	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiCmdSend
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiSessCmdSend(
	tPOCTVC1_PKT_API_SESS							f_pSession,
	tPOCTVC1_PKT_API_CMD_SEND_PARMS					f_pParms )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tPKTAPI_SESS_INF *		pSessInf;
	tPKTAPI_PKT_INF *		pPktInf = NULL;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pSession ) ||
		( NULL == f_pParms ) ||
		( NULL == f_pParms->pCmd ) )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pSessInf = (tPKTAPI_SESS_INF *)f_pSession;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_SESS != pSessInf->ulMagic )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct );
	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct->pInst );

	if( pSessInf->hSession == cPKTAPI_SESS_SESSION_INVALID )
		return cOCTVC1_PKT_API_RC_SESS_CLOSE;

	/* Get a packet */
	pPktInf = PktApiPktQueueGet(
						cPKTAPI_Q_FREE,
						&pSessInf->pCnct->pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD] );

	if ( NULL != pPktInf )
	{
		Result = PktApiSessCmdSend(
						pSessInf,
						f_pParms,
						cPKTAPI_Q_BUSY,
						1,
						pPktInf );

		if ( cOCTVC1_PKT_API_RC_OK != Result )
		{
			/* Return to owner */
			PktApiPktQueuePut(
						cPKTAPI_Q_FREE,
						&pSessInf->pCnct->pInst->paPktQ[cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD],
						pPktInf );
		}
	}
	else
	{
		Result = cOCTVC1_PKT_API_RC_INST_PKT_NOMORE;
	}

	return Result;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiCmdExecute
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiSessCmdExecute(
	tPOCTVC1_PKT_API_SESS							f_pSession,
	tPOCTVC1_PKT_API_CMD_EXECUTE_PARMS				f_pParms )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_INST_SYNC_TOOMANY;
	tPKTAPI_SESS_INF *		pSessInf;
	tPKTAPI_PKT_INF *		pPktInf = NULL;
	unsigned int			ulIndex;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pSession ) ||
		( NULL == f_pParms ) ||
		( NULL == f_pParms->pCmd ) )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pSessInf = (tPKTAPI_SESS_INF *)f_pSession;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( cPKTAPI_MAGIC_SESS != pSessInf->ulMagic )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct );
	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct->pInst );

	if( pSessInf->hSession == cPKTAPI_SESS_SESSION_INVALID )
		return cOCTVC1_PKT_API_RC_SESS_CLOSE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( NULL == f_pParms->pRsp )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Get a packet for one of the synchronous command Q */
	for ( ulIndex=cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD+1; ulIndex<pSessInf->pCnct->pInst->ulPktQCnt; ulIndex++ )
	{
		pPktInf = PktApiPktQueueGet(
							cPKTAPI_Q_FREE,
							&pSessInf->pCnct->pInst->paPktQ[ulIndex] );
		if ( NULL != pPktInf )
		{
			break;
		}
	}

	if ( NULL != pPktInf )
	{
		tOCTVC1_PKT_API_CMD_SEND_PARMS	CmdSendParms;
		mOCTVC1_PKT_API_CMD_SEND_PARMS_DEF( &CmdSendParms );
		CmdSendParms.pCmd			= f_pParms->pCmd;

		/* Send the command */
		Result = PktApiSessCmdSend(
						pSessInf,
						&CmdSendParms,
						cPKTAPI_Q_SPECIAL,
						1,
						pPktInf );

        if ( cOCTVC1_PKT_API_RC_OK == Result )
		{
			tOCTVC1_PKT_API_INST_RECV_PARMS	RecvParms;
			mOCTVC1_PKT_API_INST_RECV_PARMS_DEF( &RecvParms );
			RecvParms.ulTimeoutMs			= cOCTVC1_PKT_API_FOREVER;
			RecvParms.pPayload				= f_pParms->pRsp;
			RecvParms.ulMaxPayloadLength	= f_pParms->ulMaxRspLength;

			/* Wait for the response */
			Result = PktApiInstRecv(
						pSessInf->pCnct->pInst,
						&ulIndex,
						1,
						ulIndex,
						&RecvParms );

			if ( cOCTVC1_PKT_API_RC_OK == Result )
			{
				Result = RecvParms.Info.Rsp.ulReturnCode;
				f_pParms->ulRcvRspLength	= RecvParms.ulRcvPayloadLength;
				f_pParms->ulRoundTripMs		= RecvParms.Info.Rsp.ulRoundTripMs;

				if ( RecvParms.Info.Rsp.ulExtractTimeMs )
				{
					/* Adjust the extract time */
					RecvParms.Info.Rsp.ulExtractTimeMs = PktApiInstCalcElapsedTimeMs( OctOsalGetTimeMs(), RecvParms.Info.Rsp.ulExtractTimeMs ) ;

					f_pParms->ulExtractTimeMs	= RecvParms.Info.Rsp.ulExtractTimeMs;
					if ( !pSessInf->pCnct->pInst->Stats.ulHighestExtractTimeMs 
						|| 
						RecvParms.Info.Rsp.ulExtractTimeMs > pSessInf->pCnct->pInst->Stats.ulHighestExtractTimeMs )
					{
						pSessInf->pCnct->pInst->Stats.ulHighestExtractTimeMs =RecvParms.Info.Rsp.ulExtractTimeMs;
					}
					if ( !pSessInf->pCnct->pInst->Stats.ulLowestExtractTimeMs 
						|| 
						RecvParms.Info.Rsp.ulExtractTimeMs < pSessInf->pCnct->pInst->Stats.ulLowestExtractTimeMs )
					{
						pSessInf->pCnct->pInst->Stats.ulLowestExtractTimeMs =RecvParms.Info.Rsp.ulExtractTimeMs;
					}

					if ( cOCTVC1_PKT_API_RC_OK == Result
						&&
						f_pParms->ulRcvRspLength > f_pParms->ulMaxRspLength )
					{
						/* This response has been truncated */
						Result = cOCTVC1_PKT_API_RC_INST_RSP_TRUNCATE;
					}
				}
			}
			else
			{
				/* No response, packet is stuck in one of the Q (busy or special),
				extract it and return to free */
				tPKTAPI_PKT_INF *	pPktInf = NULL;
				pPktInf = PktApiPktQueueGet(
								cPKTAPI_Q_SPECIAL,
								&pSessInf->pCnct->pInst->paPktQ[ulIndex] );

				if ( NULL == pPktInf )
				{
					pPktInf = PktApiPktQueueGet(
									cPKTAPI_Q_BUSY,
									&pSessInf->pCnct->pInst->paPktQ[ulIndex] );
				}

				if ( NULL != pPktInf )
				{
					PktApiPktQueuePut(
									cPKTAPI_Q_FREE,
									&pSessInf->pCnct->pInst->paPktQ[ulIndex],
									pPktInf );
				}
			}
		}
		else
		{
			/* Return to owner */
			PktApiPktQueuePut(
						cPKTAPI_Q_FREE,
						&pSessInf->pCnct->pInst->paPktQ[ulIndex],
						pPktInf );
		}

	}
	return Result;
}

