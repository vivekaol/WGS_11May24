/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_HELPER.c

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
#include <stdio.h>

/* Transport default interface */
#include "../../common/octtransapi/octtransapi_eth/include/octtransapi_eth.h"

/* Module interface */
#include "../include/pktapi_inst.h"
#include "../include/pktapi_cnct.h"
#include "../include/pktapi_sess.h"
#include "../include/pktapi_helper.h"


/****************************  STATIC FUNCTION ********************************/

/***************************  INTERNAL FUNCTION *******************************/

/****************************  USER INTERFACE *********************************/


/*--------------------------------------------------------------------------
	OctVc1PktApiHelperSessGetInst
----------------------------------------------------------------------------*/
tPOCTVC1_PKT_API_INST	OctVc1PktApiHelperSessGetInst(
	tPOCTVC1_PKT_API_SESS							f_pSession )
{
	tPKTAPI_SESS_INF *		pSessInf;

	/* Validate parameters */
	mOCTOSAL_ASSERT( NULL != f_pSession );
	pSessInf = (tPKTAPI_SESS_INF *)f_pSession;

	mOCTOSAL_ASSERT( cPKTAPI_MAGIC_SESS == pSessInf->ulMagic );
	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct );
	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct->pInst );

	return (tPOCTVC1_PKT_API_INST)pSessInf->pCnct->pInst;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiHelperSessGetCnct
----------------------------------------------------------------------------*/
tPOCTVC1_PKT_API_CNCT	OctVc1PktApiHelperSessGetCnct(
	tPOCTVC1_PKT_API_SESS							f_pSession )
{
	tPKTAPI_SESS_INF *		pSessInf;

	/* Validate parameters */
	mOCTOSAL_ASSERT( NULL != f_pSession );
	pSessInf = (tPKTAPI_SESS_INF *)f_pSession;

	mOCTOSAL_ASSERT( cPKTAPI_MAGIC_SESS == pSessInf->ulMagic );
	mOCTOSAL_ASSERT( NULL != pSessInf->pCnct );

	return (tPOCTVC1_PKT_API_CNCT)pSessInf->pCnct;
}

/*--------------------------------------------------------------------------
	OctVc1PktApiGetLocalMacAddr
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiGetLocalMacAddr(
	tPOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS		f_pParms )
{
	tOCTTRANSAPI_MAC_ADDRESS MacAddress;
	/* Validate parameters */
	mOCTOSAL_ASSERT( NULL != f_pParms );

	if( f_pParms->AdaptorSelection == cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_NAME )
	{
		mOCTOSAL_ASSERT( f_pParms->pszInterfaceName != NULL );
		if ( 0 == OctTransApiEthGetLocalMacByName(
							f_pParms->pTransportContext,
							f_pParms->pszInterfaceName,
							&MacAddress	 ) )
		{
			memcpy( f_pParms->abyLocalMac, MacAddress.abyMacAddress, sizeof(f_pParms->abyLocalMac) );
			return cOCTVC1_PKT_API_RC_OK;
		}
		else
		{
			return cOCTVC1_PKT_API_RC_INTERFACE_NAME_NOT_FOUND;
		}

	}
	else
	{
		if ( 0 == OctTransApiEthGetLocalMac(
							f_pParms->pTransportContext,
							f_pParms->ulAdaptorIndex,
							&MacAddress	 ) )
		{
			memcpy( f_pParms->abyLocalMac, MacAddress.abyMacAddress, sizeof(f_pParms->abyLocalMac) );
			return cOCTVC1_PKT_API_RC_OK;
		}
		else
		{
			return cOCTVC1_PKT_API_RC_LOCAL_MAC_INDEX_NOT_FOUND;
		}
	}
}


/*--------------------------------------------------------------------------
	OctVc1PktApiGetVersion
----------------------------------------------------------------------------*/
tOCT_UINT32	OctVc1PktApiGetVersion(
	tPOCTVC1_PKT_API_GET_VERSION_PARMS		f_pParms )
{
	/* Validate parameters */
	mOCTOSAL_ASSERT( NULL != f_pParms );


	f_pParms->ulApiVersionId = cOCTVC1_PKT_API_VERSION_ID;
	sprintf( (char *)f_pParms->szApiVersion, "%02d.%02d.%02d.%02d",
		cOCTVC1_PKT_API_VERSION_MAJOR,
		cOCTVC1_PKT_API_VERSION_MINOR,
		cOCTVC1_PKT_API_VERSION_MAINTENANCE,
		cOCTVC1_PKT_API_VERSION_BUILD );

	return cOCTVC1_PKT_API_RC_OK;
}

