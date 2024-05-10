/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: rs232.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description:

    This file contains routines related to rs232 IO:

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include <stdlib.h>
#include <string.h>

#include "../include/octrs232api.h"

/*****************************  DEFINES  *************************************/

/********************************  MACROS  ***********************************/

/*--------------------------------------------------------------------------
	Open Port Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiOpenPortDef( tPOCTRS232API_OPEN_PORT f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	strcpy( (tOCT_INT8*)f_pParm->szPortName, cOCTRS232API_PORT_NAME_DEF );
	f_pParm->hPort = 0;
	f_pParm->ulBaudRate = 38400;

	return cOCTRS232API_RC_OK;
}

/*--------------------------------------------------------------------------
	Close Port Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiClosePortDef( tPOCTRS232API_CLOSE_PORT f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );

	return cOCTRS232API_RC_OK;
}

/*--------------------------------------------------------------------------
	Get Char Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiGetCharDef( tPOCTRS232API_GET_CHAR f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );

	return cOCTRS232API_RC_OK;
}

/*--------------------------------------------------------------------------
	Get Buffer Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiGetBufferDef( tPOCTRS232API_GET_BUFFER f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );
	return cOCTRS232API_RC_OK;
}

/*--------------------------------------------------------------------------
	Put char Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiPutCharDef( tPOCTRS232API_PUT_CHAR f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );
	return cOCTRS232API_RC_OK;
}
/*--------------------------------------------------------------------------
	Put buffer Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiPutBufferDef( tPOCTRS232API_PUT_BUFFER f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );
	return cOCTRS232API_RC_OK;
}

/*--------------------------------------------------------------------------
	Flush Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiFlushDef( tPOCTRS232API_FLUSH f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );
	return cOCTRS232API_RC_OK;
}

/*--------------------------------------------------------------------------
	Set Dtr Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiSetDtrDef( tPOCTRS232API_SET_DTR f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );

	return cOCTRS232API_RC_OK;
}


/*--------------------------------------------------------------------------
	Set Rts Parameters
----------------------------------------------------------------------------*/
tOCTRS232API_RC OctRS232ApiSetRtsDef( tPOCTRS232API_SET_RTS f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	memset( f_pParm, 0, sizeof( *f_pParm ) );

	return cOCTRS232API_RC_OK;
}
