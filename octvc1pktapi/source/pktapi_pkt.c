/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_PKT.c

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
#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api.h"
#include "../../sls/inc/octvc1/pkt_api/octvc1_pkt_api_default.h"

/* Module interface */
#include "../include/pktapi_inst.h"
#include "../include/pktapi_pkt.h"

/****************************  STATIC FUNCTION ********************************/
/*--------------------------------------------------------------------------
	_PktApiInstCalculateSize
		Calculates the size of the instance
----------------------------------------------------------------------------*/

/***************************  INTERNAL FUNCTION *******************************/

/****************************  USER INTERFACE *********************************/

/*--------------------------------------------------------------------------
	PktApiPktQueueOpen
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueueOpen(
	tPPKTAPI_PKT_Q_INF			f_pPktQ )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	unsigned				ulIndex;

	if ( ( 0 != mPKTAPI_MUTEX_OPEN( &f_pPktQ->hMutex ) ) )
	{
		Result = cOCTVC1_PKT_API_RC_OS_ERROR;
	}
	else if ( ( 0 != mPKTAPI_SYNC_SIGNAL_OPEN( &f_pPktQ->hSyncSignal ) ) )
	{
		Result = cOCTVC1_PKT_API_RC_OS_ERROR;
	}
	else
	{
		for ( ulIndex=0; ulIndex<cPKTAPI_Q_CNT; ulIndex++ )
		{
			f_pPktQ->aQueue[ulIndex].ulPktCnt	= 0;
			f_pPktQ->aQueue[ulIndex].pPktHead	= NULL;
			f_pPktQ->aQueue[ulIndex].pPktTail	= NULL;
		}
	}

	return Result;
}

/*--------------------------------------------------------------------------
	PktApiPktQueueClose
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueueClose(
	tPPKTAPI_PKT_Q_INF			f_pPktQ )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	unsigned				ulIndex;
	tPPKTAPI_PKT_INF		pPktInf;

	for ( ulIndex=0; ulIndex<cPKTAPI_Q_CNT; ulIndex++ )
	{
		pPktInf = PktApiPktQueueGet( ulIndex, f_pPktQ );

		while ( NULL != pPktInf )
		{
			pPktInf = PktApiPktQueueGet( ulIndex, f_pPktQ );
		};
	}

#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
	/* Close the mutex */
	mPKTAPI_MUTEX_CLOSE( &f_pPktQ->hMutex );
	f_pPktQ->hMutex = NULL;

	mPKTAPI_SYNC_SIGNAL_CLOSE( f_pPktQ->hSyncSignal );
	f_pPktQ->hMutex = NULL;

#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

	return Result;
}

/*--------------------------------------------------------------------------
	PktApiPktQueueGet
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueGet(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ )
{
	tPPKTAPI_PKT_INF		pPktInf;
	tPPKTAPI_PKT_Q			pQ;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];
	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	pPktInf = pQ->pPktHead;

	if ( NULL != pPktInf )
	{
		/* Validate Q consistency */
		mOCTOSAL_ASSERT( NULL == pPktInf->pPrevious );

		/* Update pointers */
		if ( NULL != pPktInf->pNext )
		{
			pPktInf->pNext->pPrevious = NULL;
		}
		/* Update head / tail */
		pQ->pPktHead = pPktInf->pNext;
		if ( NULL == pQ->pPktHead )
		{
			/* No more tail */
			mOCTOSAL_ASSERT( pQ->pPktTail == pPktInf );
			pQ->pPktTail = NULL;
		}

		/* Clean up packet pointers */
		pPktInf->pNext		= NULL;
		pPktInf->pPrevious	= NULL;

		mOCTOSAL_ASSERT( pQ->ulPktCnt >= 1 );
		pQ->ulPktCnt--;

		/* Check consistency */
		mOCTOSAL_ASSERT( (0 == pQ->ulPktCnt) || (NULL != pQ->pPktHead && NULL != pQ->pPktTail) );
	}

	/* setup new pkt */
	if( pPktInf && (f_ulQIndex == cPKTAPI_Q_FREE) )
	{
		/* Clear flag */
		pPktInf->ulFlag = 0;
	}
	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	return pPktInf;
}

/*--------------------------------------------------------------------------
	PktApiPktQueueExtract
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueExtract(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	unsigned int				f_ulSessionId,
	tOCT_UINT32					f_ulTransactionId )
{
	tPPKTAPI_PKT_INF		pPktInf;
	tPPKTAPI_PKT_Q			pQ;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];
	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	pPktInf = pQ->pPktHead;

	while ( NULL != pPktInf )
	{
		if ( (pPktInf->ulSessionId == f_ulSessionId ) && 
			 (pPktInf->ulTransactionId == f_ulTransactionId) )
		{
			/* Got it */
			if ( NULL == pPktInf->pPrevious )
			{
				mOCTOSAL_ASSERT( pPktInf == pQ->pPktHead );

				/* First packet. New head is next */
				pQ->pPktHead = pPktInf->pNext;
				/* Unlink next from previous */
				if ( NULL != pPktInf->pNext )
				{
					pPktInf->pNext->pPrevious = NULL;
				}
			}
			else
			{
				mOCTOSAL_ASSERT( pPktInf != pQ->pPktHead );
				/* Link previous to next */
				pPktInf->pPrevious->pNext = pPktInf->pNext;

				if ( NULL != pPktInf->pNext )
				{
					pPktInf->pNext->pPrevious = pPktInf->pPrevious;
				}
			}

			/* Are we the tail ? */
			if ( pQ->pPktTail == pPktInf )
			{
				if ( NULL != pPktInf->pPrevious )
				{
					pQ->pPktTail = pPktInf->pPrevious;
					pQ->pPktTail->pNext = NULL;
				}
				else
				{
					pQ->pPktTail = NULL;
				}
			}

			/* Clean up packet pointers */
			pPktInf->pNext		= NULL;
			pPktInf->pPrevious	= NULL;

			/* Remove one packet from Q */
			mOCTOSAL_ASSERT( pQ->ulPktCnt >= 1 );
			pQ->ulPktCnt--;
			/* Check consistency */
			mOCTOSAL_ASSERT( (0 == pQ->ulPktCnt) || (NULL != pQ->pPktHead && NULL != pQ->pPktTail) );

			break;
		}

		/* Move next */
		pPktInf = pPktInf->pNext;
	}

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	return pPktInf;
}

/*--------------------------------------------------------------------------
	PktApiPktQueueExtractAny
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueExtractAny(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	unsigned int				f_ulSessionId )
{
	tPPKTAPI_PKT_INF		pPktInf;
	tPPKTAPI_PKT_Q			pQ;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];
	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	pPktInf = pQ->pPktHead;

	while ( NULL != pPktInf )
	{
		if ( pPktInf->ulSessionId == f_ulSessionId )
		{
			/* Got it */
			if ( NULL == pPktInf->pPrevious )
			{
				mOCTOSAL_ASSERT( pPktInf == pQ->pPktHead );

				/* First packet. New head is next */
				pQ->pPktHead = pPktInf->pNext;
				/* Unlink next from previous */
				if ( NULL != pPktInf->pNext )
				{
					pPktInf->pNext->pPrevious = NULL;
				}
			}
			else
			{
				mOCTOSAL_ASSERT( pPktInf != pQ->pPktHead );
				/* Link previous to next */
				pPktInf->pPrevious->pNext = pPktInf->pNext;

				if ( NULL != pPktInf->pNext )
				{
					pPktInf->pNext->pPrevious = pPktInf->pPrevious;
				}
			}

			/* Are we the tail ? */
			if ( pQ->pPktTail == pPktInf )
			{
				if ( NULL != pPktInf->pPrevious )
				{
					pQ->pPktTail = pPktInf->pPrevious;
					pQ->pPktTail->pNext = NULL;
				}
				else
				{
					pQ->pPktTail = NULL;
				}
			}

			/* Clean up packet pointers */
			pPktInf->pNext		= NULL;
			pPktInf->pPrevious	= NULL;

			/* Remove one packet from Q */
			mOCTOSAL_ASSERT( pQ->ulPktCnt >= 1 );
			pQ->ulPktCnt--;
			/* Check consistency */
			mOCTOSAL_ASSERT( (0 == pQ->ulPktCnt) || (NULL != pQ->pPktHead && NULL != pQ->pPktTail) );

			break;
		}

		/* Move next */
		pPktInf = pPktInf->pNext;
	}

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	return pPktInf;
}

/*--------------------------------------------------------------------------
	PktApiPktQueuePut
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueuePut(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tPPKTAPI_PKT_INF			f_pPkt )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tPPKTAPI_PKT_Q			pQ;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];

	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	/* Timestamp the packet */
	f_pPkt->ulStartTimeMs = OctOsalGetTimeMs();

	if ( NULL != pQ->pPktTail )
	{
		pQ->pPktTail->pNext	= f_pPkt;
		f_pPkt->pPrevious	= pQ->pPktTail;
		f_pPkt->pNext		= NULL;
		pQ->pPktTail		= f_pPkt;
	}
	else
	{
		mOCTOSAL_ASSERT( NULL == pQ->pPktHead );
		pQ->pPktHead		= pQ->pPktTail = f_pPkt;
		f_pPkt->pPrevious	= NULL;
		f_pPkt->pNext		= NULL;
	}
	/* Increment packet count */
	pQ->ulPktCnt++;

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );
	return Result;	
}


/*--------------------------------------------------------------------------
	PktApiPktQueuePutAndSignal
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueuePutAndSignal(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tPPKTAPI_PKT_INF			f_pPkt)
{
	tOCT_UINT32	Result;

	if( ( Result = PktApiPktQueuePut( f_ulQIndex, f_pPktQ, f_pPkt ) ) == cOCTVC1_PKT_API_RC_OK )
	{
		mPKTAPI_PKT_Q_SYNC_SIGNAL_SET( f_pPktQ );
	}
	return Result;
}



/*--------------------------------------------------------------------------
	PktApiPktQueuePutList
----------------------------------------------------------------------------*/
tOCT_UINT32 PktApiPktQueuePutList(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tPPKTAPI_PKT_INF			f_pPktListHead )
{
	tOCT_UINT32	Result = cOCTVC1_PKT_API_RC_OK;
	tPPKTAPI_PKT_INF		pPktInf;
	tPPKTAPI_PKT_INF		pPktInfLast;
	tPPKTAPI_PKT_Q			pQ;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];

	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	if ( NULL != pQ->pPktTail )
	{
		pQ->pPktTail->pNext	= f_pPktListHead;
		f_pPktListHead->pPrevious	= pQ->pPktTail;
	}
	else
	{
		mOCTOSAL_ASSERT( NULL == pQ->pPktHead );
		pQ->pPktHead	= f_pPktListHead;
	}

	/* Update list and count */
	pPktInf		= f_pPktListHead;
	pPktInfLast = pPktInf;

	while ( NULL != pPktInf )
	{
		/* Increment packet count */
		pQ->ulPktCnt++;

		pPktInfLast = pPktInf;
		pPktInf = pPktInf->pNext;
	};

	pQ->pPktTail = pPktInfLast;

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	/* No need to signal .. nobody is waiting here 
		mPKTAPI_PKT_Q_SYNC_SIGNAL_SET( f_pPktQ ); */

	return Result;
}

/*--------------------------------------------------------------------------
	PktApiPktQueueTimeoutCheck
----------------------------------------------------------------------------*/
tPPKTAPI_PKT_INF PktApiPktQueueTimeoutCheck(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	unsigned					f_ulCurrentTimeMs )
{
	tPPKTAPI_PKT_INF		pPktInf;
	tPPKTAPI_PKT_Q			pQ;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];
	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );


	pPktInf = pQ->pPktHead;

	while ( NULL != pPktInf )
	{
		tPKTAPI_SESS_INF *pSessInf = (tPKTAPI_SESS_INF *)pPktInf->RecvParms.pSession;

		if( ( pSessInf 
			&&
			PktApiInstCalcElapsedTimeMs( f_ulCurrentTimeMs, pPktInf->ulStartTimeMs ) > pPktInf->ulTimeoutMs )
			)
		{

			/* Got it */
			if ( NULL == pPktInf->pPrevious )
			{
				mOCTOSAL_ASSERT( pPktInf == pQ->pPktHead );
				/* First packet. New head is next */
				pQ->pPktHead = pPktInf->pNext;
				/* Unlink next from previous */
				if ( NULL != pPktInf->pNext )
				{
					pPktInf->pNext->pPrevious = NULL;
				}
			}
			else
			{
				mOCTOSAL_ASSERT( pPktInf != pQ->pPktHead );
				/* Link previous to next */
				pPktInf->pPrevious->pNext = pPktInf->pNext;

				if ( NULL != pPktInf->pNext )
				{
					pPktInf->pNext->pPrevious = pPktInf->pPrevious;
				}
			}
			/* Are we the tail ? */
			if ( pQ->pPktTail == pPktInf )
			{
				if ( NULL != pPktInf->pPrevious )
				{
					pQ->pPktTail = pPktInf->pPrevious;
					pQ->pPktTail->pNext = NULL;
				}
				else
				{
					pQ->pPktTail = NULL;
				}
			}

			/* Clean up packet pointers */
			pPktInf->pNext		= NULL;
			pPktInf->pPrevious	= NULL;

			/* Remove one packet from Q */
			mOCTOSAL_ASSERT( pQ->ulPktCnt >= 1 );
			pQ->ulPktCnt--;
			/* Check consistency */
			mOCTOSAL_ASSERT( (0 == pQ->ulPktCnt) || (NULL != pQ->pPktHead && NULL != pQ->pPktTail) );

			break;
		}
		else
		{
			/* Test if this is a normal cmd ... not cOCTVC1_MSG_NO_RESPONSE_FLAG or cOCTVC1_MSG_LONG_PROCESSING_FLAG */
			/* Next msg are not in timeout if this normale msg is not */
			if( pSessInf && 
				(( pPktInf->RecvParms.Info.Rsp.ulCmdId & ( cOCTVC1_MSG_NO_RESPONSE_FLAG | cOCTVC1_MSG_MID_PROCESSING_FLAG | cOCTVC1_MSG_LONG_PROCESSING_FLAG ) ) == 0 ) )
				pPktInf = NULL;	
			else	/* Move next */
				pPktInf = pPktInf->pNext;
		}
	}

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	return pPktInf;
}



/*--------------------------------------------------------------------------
	PktApiPktQueueCountGet
----------------------------------------------------------------------------*/
unsigned int PktApiPktQueueCountGet(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ )
{
	tPPKTAPI_PKT_Q			pQ;
	unsigned int			ulPacketCnt;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];
	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	ulPacketCnt = pQ->ulPktCnt;

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	return ulPacketCnt;
}


/*--------------------------------------------------------------------------
	PktApiPktQueueMinTransactionIdGet
----------------------------------------------------------------------------*/
unsigned int PktApiPktQueueMinTransactionIdGet(
	unsigned					f_ulQIndex,
	tPPKTAPI_PKT_Q_INF			f_pPktQ,
	tOCT_UINT32					f_ulSessionId )
{
	tPPKTAPI_PKT_Q			pQ;
	tPPKTAPI_PKT_INF		pPktInf;
	unsigned int			ulTransactionId = 0;

	mOCTOSAL_ASSERT( f_ulQIndex < cPKTAPI_Q_CNT );

	pQ = &f_pPktQ->aQueue[f_ulQIndex];
	/* Lock */
	mPKTAPI_PKT_Q_MUTEX_SEIZE( f_pPktQ );

	pPktInf = pQ->pPktHead;

	while ( NULL != pPktInf )
	{
		/* First session packet should be min id */
		if( pPktInf->ulSessionId == f_ulSessionId )
		{
			ulTransactionId = pPktInf->ulTransactionId;
			break;
		}

		/* Move next */
		pPktInf = pPktInf->pNext;
	}

	/* Unlock */
	mPKTAPI_PKT_Q_MUTEX_RELEASE( f_pPktQ );

	return ulTransactionId;

}


