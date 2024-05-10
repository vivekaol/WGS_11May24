/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: io_porting.c

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
#include <stdio.h>

#include "../include/octrs232api.h"

/*****************************  DEFINES  *************************************/
#ifdef OCT_ENV_TYPE_WINDOWS

/********************************  MACROS  ***********************************/
#include <windows.h>
/********************************  GLOBAL  ***********************************/

typedef struct
{
	HANDLE		hPort;
	tOCT_UINT32	ulBaudRate;
	tOCT_UINT8	szPortName[cOCTRS232API_PORT_NAME_LEN+1];

}tRS232_PORT, *tPRS232_PORT;

tRS232_PORT	l_aRS232Port[cOCTRS232API_MAX_PORT_INST] = { NULL };


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: RS232IsPortOpen

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCTRS232API_RC RS232IsPortOpen( tPOCTRS232API_OPEN_PORT f_pParm, tOCT_UINT32 *f_pulPortIndex )
{
	UINT32 i=0;

	*f_pulPortIndex = cOCTRS232API_MAX_PORT_INST;

	for( i=0; i<cOCTRS232API_MAX_PORT_INST; i++ )
	{
		if( (*f_pulPortIndex == cOCTRS232API_MAX_PORT_INST) && 
			l_aRS232Port[i].hPort == NULL )
		{
			*f_pulPortIndex = i;
		}
		else
		{
			if( strcmp( l_aRS232Port[i].szPortName, f_pParm->szPortName ) == 0 )
			{
				*f_pulPortIndex = i;
				return cOCTRS232API_RC_ALREADY_OPEN;
			}
		}
	}

	if(*f_pulPortIndex != cOCTRS232API_MAX_PORT_INST)
		return cOCTRS232API_RC_OK;

	return cOCTRS232API_RC_CANT_OPEN_PORT;

}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: OctRS232ApiOpenPort

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC OctRS232ApiOpenPort( tPOCTRS232API_OPEN_PORT f_pParm )
{
	COMMTIMEOUTS    Timeouts;
    DCB             DcbStruct;
	HANDLE			hPort;
	tOCTRS232API_RC Rc;
	tOCT_UINT32		ulPortIndex;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( ( Rc = RS232IsPortOpen( f_pParm, &ulPortIndex ) ) != cOCTRS232API_RC_OK )
	{
		if( Rc == cOCTRS232API_RC_ALREADY_OPEN )
			f_pParm->hPort = ulPortIndex;

		return Rc;
	}

    hPort = CreateFile( f_pParm->szPortName,
                            GENERIC_READ | GENERIC_WRITE,
                            0,
                            NULL,
                            OPEN_EXISTING,
                            0,
                            NULL );

    if( hPort == INVALID_HANDLE_VALUE )
		return(cOCTRS232API_RC_CANT_OPEN_PORT);

    ZeroMemory( &Timeouts, sizeof(COMMTIMEOUTS) );

    Timeouts.ReadIntervalTimeout         = MAXDWORD;
    Timeouts.ReadTotalTimeoutConstant    = 300;		/* 500 */;
    Timeouts.ReadTotalTimeoutMultiplier  = MAXDWORD;
    Timeouts.WriteTotalTimeoutMultiplier = MAXDWORD;	/* 0 */;
    Timeouts.WriteTotalTimeoutConstant   = MAXDWORD;	/* 0 */


    if ( !SetCommTimeouts( hPort, &Timeouts ) )
    {
        CloseHandle( hPort );
		return cOCTRS232API_RC_INTERNAL;
    }

    /* Get the current state prior to changing it */
    if( !GetCommState( hPort, &DcbStruct ) )
    {
        CloseHandle( hPort );
		return cOCTRS232API_RC_INTERNAL;
    }

    /* Setup default DCB Structure: 8,n,1, no h/w flow control for Vocallo */
	DcbStruct.BaudRate			= f_pParm->ulBaudRate;
    DcbStruct.ByteSize			= 8;
	DcbStruct.fBinary			= TRUE;
	DcbStruct.fParity			= FALSE;
	DcbStruct.fOutxCtsFlow		= FALSE;
	DcbStruct.fOutxDsrFlow		= FALSE;
	DcbStruct.fDsrSensitivity	= FALSE;
	DcbStruct.fTXContinueOnXoff	= FALSE;
	DcbStruct.fOutX				= FALSE;
	DcbStruct.fInX				= FALSE;
	DcbStruct.fErrorChar		= FALSE;
	DcbStruct.fNull				= FALSE;
	DcbStruct.fAbortOnError		= FALSE;
	DcbStruct.Parity			= NOPARITY;
    DcbStruct.StopBits			= ONESTOPBIT;

	DcbStruct.fDtrControl = DTR_CONTROL_DISABLE;
    DcbStruct.fRtsControl = RTS_CONTROL_ENABLE;

    if( !SetCommState( hPort, &DcbStruct ) )
    {
        CloseHandle( hPort );
		return cOCTRS232API_RC_INTERNAL;
    }

	strcpy( l_aRS232Port[ulPortIndex].szPortName, f_pParm->szPortName );

	l_aRS232Port[ulPortIndex].hPort = hPort;
	l_aRS232Port[ulPortIndex].ulBaudRate = f_pParm->ulBaudRate;
	f_pParm->hPort = ulPortIndex;

	return cOCTRS232API_RC_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: OctRS232ApiClosePort

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC  OctRS232ApiClosePort( tPOCTRS232API_CLOSE_PORT f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort != NULL )
	{
		CloseHandle( l_aRS232Port[f_pParm->hPort].hPort );
	}
	l_aRS232Port[f_pParm->hPort].hPort = NULL;

	return cOCTRS232API_RC_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: RS232IoGetCharCnt

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCTRS232API_RC  RS232IoGetCharCnt( tPRS232_PORT f_pPort, tOCT_UINT8 *f_pbyByte, tOCT_UINT32 f_ulBufLen, tOCT_UINT32 *f_pulRecvLen )
{
	tOCT_UINT32 ulBytesRead;
    tOCT_UINT32 ulTotalBytesRead = 0;
    tOCT_UINT32 ulCurrentLen = f_ulBufLen ;

    tOCT_INT32 fSuccess;
    tOCT_INT32 iNumRetries ;
    tOCT_INT32 iDelay ;

    if( f_pPort->ulBaudRate <= 9600 )
    {
        iNumRetries = 10;
        iDelay      = 5;
    }
    else
    {
        iNumRetries = 8;
        iDelay      = 2;
    }


    while( ulTotalBytesRead < f_ulBufLen )
    {
        fSuccess = ReadFile( f_pPort->hPort, &f_pbyByte[ulTotalBytesRead],
                             ulCurrentLen, &ulBytesRead, NULL );

        if( !fSuccess )
        {
            DWORD ulResult = GetLastError( );
			return cOCTRS232API_RC_INTERNAL;
        }

        ulTotalBytesRead += ulBytesRead ;
        ulCurrentLen     -= ulBytesRead ;

        if( iNumRetries-- <= 0 ) break;

        /* If didn't get all the bytes first time, relax a bit. */
        /* This is required for slow device like EEPROM. */
        if( ulTotalBytesRead < f_ulBufLen )
            Sleep(iDelay);
    }

	if( f_pulRecvLen )
		*f_pulRecvLen =  ulTotalBytesRead;

    return ulTotalBytesRead ? cOCTRS232API_RC_OK : cOCTRS232API_RC_RECV_NONE;

}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: OctRS232ApiGetChar

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC  OctRS232ApiGetChar( tPOCTRS232API_GET_CHAR f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;


	return RS232IoGetCharCnt( &l_aRS232Port[f_pParm->hPort], &f_pParm->byData, 1, NULL );
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: OctRS232ApiGetBuffer

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC  OctRS232ApiGetBuffer( tPOCTRS232API_GET_BUFFER f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;


	return RS232IoGetCharCnt( &l_aRS232Port[f_pParm->hPort],
								f_pParm->pbyBuffer,
								f_pParm->ulLen,
								&f_pParm->ulRecvLen );
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: RS232IoPutCharCnt

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCTRS232API_RC  RS232IoPutCharCnt( tPRS232_PORT f_pPort, tOCT_UINT8 *f_pCh, tOCT_UINT32 f_ulLen )
{
	tOCT_UINT32 ulBytesWritten = 0;
	tOCT_INT32 fSuccess;

    fSuccess = WriteFile( f_pPort->hPort, f_pCh,
                              f_ulLen, (unsigned long*)&ulBytesWritten, NULL );

    if ( !fSuccess || ( ulBytesWritten != f_ulLen ) )
    {
		return cOCTRS232API_RC_INTERNAL;
    }

    FlushFileBuffers( f_pPort->hPort );

    return cOCTRS232API_RC_OK;

}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: OctRS232ApiPutChar

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC  OctRS232ApiPutChar( tPOCTRS232API_PUT_CHAR f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;


	return RS232IoPutCharCnt( &l_aRS232Port[f_pParm->hPort], &f_pParm->byData, 1 );
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: OctRS232ApiPutBuffer

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC  OctRS232ApiPutBuffer( tPOCTRS232API_PUT_BUFFER f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;

	return RS232IoPutCharCnt( &l_aRS232Port[f_pParm->hPort],
								f_pParm->pbyBuffer,
								f_pParm->ulLen );
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:     Dtr

Description:  Change terminal DTR setting

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC OctRS232ApiSetDtr( tPOCTRS232API_SET_DTR f_pParm )
{
    DCB             DcbStruct;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;

    /* Get the current state prior to changing it */
    if( !GetCommState( l_aRS232Port[f_pParm->hPort].hPort, &DcbStruct ) )
        return cOCTRS232API_RC_INTERNAL;

    if(f_pParm->fState)
		DcbStruct.fDtrControl = DTR_CONTROL_ENABLE;
	else
		DcbStruct.fDtrControl = DTR_CONTROL_DISABLE;

    if( !SetCommState( l_aRS232Port[f_pParm->hPort].hPort, &DcbStruct ) )
		return cOCTRS232API_RC_INTERNAL;

    return cOCTRS232API_RC_OK;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:     OctRS232ApiFlush

Description:

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC OctRS232ApiFlush( tPOCTRS232API_FLUSH f_pParm )
{
	DWORD         ulTimeout = 1;
	unsigned long ulBytesRead;
	BYTE  abyBuffer[256];
	tOCT_INT32 fSuccess;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;

	if( f_pParm->fFlushRx )
	{
		while( ulTimeout )
		{
			fSuccess = ReadFile(l_aRS232Port[f_pParm->hPort].hPort , abyBuffer, 256, &ulBytesRead, NULL );

			if( !fSuccess )
			{
				GetLastError( );
			}

			if( !ulBytesRead )
			{
				ulTimeout--;
			}
		}
	}

	if( f_pParm->fFlushTx )
		FlushFileBuffers( l_aRS232Port[f_pParm->hPort].hPort );

	return cOCTRS232API_RC_OK;
}
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:     OctRS232ApiSetRts

Description:  Change terminal RTS Setting

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC OctRS232ApiSetRts( tPOCTRS232API_SET_RTS f_pParm )
{
    DCB             DcbStruct;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].hPort == NULL )
		return cOCTRS232API_RC_PORT_CLOSED;

    /* Get the current state prior to changing it */
    if( !GetCommState( l_aRS232Port[f_pParm->hPort].hPort, &DcbStruct ) )
        return cOCTRS232API_RC_INTERNAL;

    if(f_pParm->fState)
		DcbStruct.fRtsControl = RTS_CONTROL_ENABLE;
	else
		DcbStruct.fRtsControl = RTS_CONTROL_DISABLE;

    if( !SetCommState( l_aRS232Port[f_pParm->hPort].hPort, &DcbStruct ) )
        return cOCTRS232API_RC_INTERNAL;

    return cOCTRS232API_RC_OK;
}

#endif /* OCT_ENV_TYPE_WINDOWS */
