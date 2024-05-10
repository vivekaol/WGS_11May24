#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_select.c

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
#include <errno.h>
#include <unistd.h>

#ifdef OCTTRANSAPI_OPT_SELECT
#ifdef OCTTRANSAPI_OPT_POLL
#include <sys/poll.h>
#else
#include <sys/select.h>
#endif	/* OCTTRANSAPI_OPT_POLL */
#endif /* OCTTRANSAPI_OPT_SELECT */

#include "../../../include/transapi.h"

#ifdef OCTTRANSAPI_OPT_SELECT
/*--------------------------------------------------------------------------
	OctTransApiSelect
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiSelect( tOCTTRANSAPI_SELECT_PARMS * f_pParms )
{
	unsigned int	ulIndex;
    int 			iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	
    tTRANSAPI_CTX*                  pTransCtx;
    tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;
    int 							iSelectables[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
	tTRANSAPI_TRANSPORT_INSTANCE*	aTransInst[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];


#ifdef OCTTRANSAPI_OPT_POLL
	struct pollfd fds[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
#else
	int 			nfds = 0;
	fd_set			rfds;
	struct timeval	tv;
#endif	/* OCTTRANSAPI_OPT_POLL */


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if( f_pParms == NULL )
        return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#ifndef OCTTRANSAPI_OPT_POLL
    tv.tv_sec = f_pParms->ulTimeoutMs / 1000;
    tv.tv_usec = (f_pParms->ulTimeoutMs % 1000) * 1000;
	FD_ZERO(&rfds);
#endif	/* OCTTRANSAPI_OPT_POLL */

	for ( ulIndex=0; ulIndex<f_pParms->ulTransportCnt;ulIndex++ )
	{

        pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_pParms->ahTransport[ulIndex];
        if( NULL == pTransInst )
            return cOCTTRANSAPI_RC_ERROR_PARAM;

        mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
        pTransCtx = (tTRANSAPI_CTX*)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
        if( ( pTransInst->pTransApiCtx == NULL ) )
            iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
        else if( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID  )
            iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

        if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
        {
            mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
            return iRc;
        }

        /* May not have pre-select */
        if( pTransCtx->pfnPreSelect )
        {
            iRc = pTransCtx->pfnPreSelect( f_pParms->ahTransport[ulIndex] );
            if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
            {
                mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
                return iRc;
            }
        }

        /* Store selectable */
        iSelectables[ulIndex] = (int)(intptr_t)pTransCtx->hSelectable;
		aTransInst[ulIndex] = pTransInst;

#ifdef OCTTRANSAPI_OPT_POLL
		fds[ulIndex].fd		= iSelectables[ulIndex];
		fds[ulIndex].events = POLLIN;
#else
		/* Set FD in preparation of select operation */
        FD_SET((unsigned int)iSelectables[ulIndex], &rfds);
        nfds = mMAX(nfds, (unsigned int)iSelectables[ulIndex]);
#endif
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

	}

#ifdef OCTTRANSAPI_OPT_POLL
	iRc = poll(fds, f_pParms->ulTransportCnt, (cOCTTRANSAPI_TIMEOUT_FOREVER == f_pParms->ulTimeoutMs) ? -1 : f_pParms->ulTimeoutMs );
#else
	iRc = select(	nfds+1,
					&rfds, NULL, NULL,
					cOCTTRANSAPI_TIMEOUT_FOREVER == f_pParms->ulTimeoutMs ? NULL : &tv );
#endif	/* OCTTRANSAPI_OPT_POLL */

	f_pParms->ulSelectedCnt = 0;

	if( iRc < 0 )
	{
		switch( errno )
		{
			case EBADF:
				return cOCTTRANSAPI_RC_ERROR_SELECT_ABANDON;
				break;

			default:
				/* TODO find how to set generic last error */
				return cOCTTRANSAPI_RC_ERROR_PORTING;
		}
	}
	else if( iRc > 0 )
	{
#ifdef OCTTRANSAPI_OPT_POLL
		for ( ulIndex=0; ulIndex<f_pParms->ulTransportCnt;ulIndex++ )
		{
			if(fds[ulIndex].revents == POLLIN )
			{
				f_pParms->ahTransSelected[f_pParms->ulSelectedCnt++] =	f_pParms->ahTransport[ulIndex];
				if( aTransInst[ulIndex]->pTransApiCtx->pfnPostSelect )
					iRc = aTransInst[ulIndex]->pTransApiCtx->pfnPostSelect( f_pParms->ahTransport[ulIndex] );
			}
			// TODO process unknowned events
		}
#else
		for ( ulIndex=0; ulIndex<f_pParms->ulTransportCnt;ulIndex++ )
		{
			/* Set FD in preparation of select operation */
            if( FD_ISSET((unsigned int)iSelectables[ulIndex], &rfds) )
			{
				f_pParms->ahTransSelected[f_pParms->ulSelectedCnt++] =	f_pParms->ahTransport[ulIndex];

				if( aTransInst[ulIndex]->pTransApiCtx->pfnPostSelect )
					iRc = aTransInst[ulIndex]->pTransApiCtx->pfnPostSelect( f_pParms->ahTransport[ulIndex] );
			}
		}
#endif	/* OCTTRANSAPI_OPT_POLL */

	}
	return cOCTTRANSAPI_RC_ERROR_NONE;

}

#endif /* OCTTRANSAPI_OPT_SELECT */

#endif /* __linux__ */

