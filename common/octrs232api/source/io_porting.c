/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: io_porting.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description:

    This file contains routines related to rs232 IO for linux operating system

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
#include <string.h>

#include "../include/octrs232api.h"
#include "../../octosal/include/octosal.h"

/*****************************  DEFINES  *************************************/

/********************************  MACROS  ***********************************/
#ifdef OCT_ENV_TYPE_LINUX

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <signal.h>

#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>



/********************************  GLOBAL  ***********************************/

typedef struct
{
	tOCT_INT32	fIsOpen;
	tOCT_INT8	szPortName[cOCTRS232API_PORT_NAME_LEN+1];
	tOCT_INT32 	fdTty;
	tOCT_INT32	iOldModemControl;
	tOCT_UINT32	ulBaudRate;
	tOCT_UINT32	hPort;
	struct termios	OldTermAttributes;

}tRS232_PORT, *tPRS232_PORT;

tRS232_PORT	l_aRS232Port[cOCTRS232API_MAX_PORT_INST] = { {0} };

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: RS232IsPortOpen

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCTRS232API_RC RS232IsPortOpen( tPOCTRS232API_OPEN_PORT f_pParm, 
									   tOCT_UINT32 *f_pulPortIndex )
{
	int i=0;

	*f_pulPortIndex = cOCTRS232API_MAX_PORT_INST;

	for( i=0; i<cOCTRS232API_MAX_PORT_INST; i++ )
	{
		if( (*f_pulPortIndex == cOCTRS232API_MAX_PORT_INST) && 
			l_aRS232Port[i].fdTty == 0 )
		{
			*f_pulPortIndex = i;
		}
		else
		{
			if( strcmp( l_aRS232Port[i].szPortName, f_pParm->szPortName ) == 0 )
				return cOCTRS232API_RC_ALREADY_OPEN;
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
	struct termios	NewTermAttributes;
	speed_t			Baud;
	tOCT_INT32		iModemControl;
	tOCT_UINT32		ulPortIndex;
	tOCT_UINT32		Rc;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( ( Rc = RS232IsPortOpen( f_pParm, &ulPortIndex ) ) != cOCTRS232API_RC_OK )
		return Rc;

	switch( f_pParm->ulBaudRate )
	{
		case 9600:
			Baud = B9600;
			break;
		case 19200:
			Baud = B19200;
			break;
		case 38400:
			Baud = B38400;
			break;
		case 57600:
			Baud = B57600;
			break;
		case 115200:
			Baud = B115200;
			break;

		default:
			return cOCTRS232API_RC_BAD_PARAM;
	}



	/* open the device(com port) to be non-blocking (read will return immediately) */
	l_aRS232Port[ulPortIndex].fdTty = open(f_pParm->szPortName, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
	if( l_aRS232Port[ulPortIndex].fdTty < 0 )
	{
		l_aRS232Port[ulPortIndex].fdTty = 0;
		perror( "tty open" );
		return(cOCTRS232API_RC_CANT_OPEN_PORT);
	}

	

	/* Set the requested port settings */
	tcgetattr(l_aRS232Port[ulPortIndex].fdTty, &l_aRS232Port[ulPortIndex].OldTermAttributes);

	NewTermAttributes.c_cflag = Baud | CLOCAL | CREAD | CS8;
	NewTermAttributes.c_cflag &= ~PARENB;
	NewTermAttributes.c_cflag &= ~CSTOPB;
	NewTermAttributes.c_cflag &= ~HUPCL; /* clear the HUPCL bit, close doesn't change DTR */

	NewTermAttributes.c_iflag = IGNPAR;	//  | ICRNL;

	NewTermAttributes.c_oflag &= ~OPOST;
	NewTermAttributes.c_lflag = 0;	// ICANON;	/* Disable all echo fnc */

	NewTermAttributes.c_cc[VTIME]=0;	/* No time delay */
	NewTermAttributes.c_cc[VMIN]= 0;		/* No char delay */

	tcflush(l_aRS232Port[ulPortIndex].fdTty, TCIFLUSH);
	tcsetattr(l_aRS232Port[ulPortIndex].fdTty,TCSANOW,&NewTermAttributes);

	/* Indicate to the far end that we're ready to exchange data */
	ioctl( l_aRS232Port[ulPortIndex].fdTty, TIOCMGET, &l_aRS232Port[ulPortIndex].iOldModemControl );
	iModemControl = l_aRS232Port[ulPortIndex].iOldModemControl;
	iModemControl &= ~TIOCM_DTR;			/* DTR negative ... release reset */
	ioctl(l_aRS232Port[ulPortIndex].fdTty, TIOCMSET, &iModemControl);

	strcpy( l_aRS232Port[ulPortIndex].szPortName, f_pParm->szPortName );
	l_aRS232Port[ulPortIndex].fIsOpen = 1;
	l_aRS232Port[ulPortIndex].ulBaudRate = f_pParm->ulBaudRate;
	f_pParm->hPort = ulPortIndex;


	/* Since Open just reset device through DTR default setting ... wait to bring up */

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
	if( l_aRS232Port[f_pParm->hPort].fIsOpen )
	{
		tPRS232_PORT pPort = &l_aRS232Port[f_pParm->hPort];

		/* Restore previous com port settings */
		tcsetattr(pPort->fdTty, TCSANOW, &pPort->OldTermAttributes);

		/* Keep active one */
		/* ioctl( pPort->fdTty, TIOCMSET, &pPort->iOldModemControl ); */

		close( pPort->fdTty );

		pPort->fIsOpen = 0;

	}

	return cOCTRS232API_RC_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: RS232IoGetCharCnt

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCTRS232API_RC  RS232IoGetCharCnt( tPRS232_PORT f_pPort, tOCT_UINT8 *f_pbyByte, tOCT_UINT32 f_ulBufLen, tOCT_UINT32 *f_pulRecvLen )
{

	tOCT_INT32 lBytesRead;
	tOCT_UINT32 ulTotalBytesRead = 0;
	tOCT_UINT32 ulCurrentLen = f_ulBufLen ;
	fd_set readfs;    /* file descriptor set */
	struct timeval Timeout;
	tOCT_INT32 iRc;

    tOCT_INT32 iNumRetries ;

    if( f_pPort->ulBaudRate <= 9600 )
        iNumRetries = 10;
    else
        iNumRetries = 8;

    FD_ZERO( &readfs );

    while( ulTotalBytesRead < f_ulBufLen )
    {
	FD_SET(f_pPort->fdTty, &readfs);  /* set testing for source 1 */

	/* set timeout value within input loop */
	Timeout.tv_usec = 200000;
	Timeout.tv_sec  = 0;  /* seconds */

	/* block until input becomes available */
	iRc = select( f_pPort->fdTty+1, &readfs, NULL, NULL, &Timeout);
	if( iRc )
	{
		if ( FD_ISSET(f_pPort->fdTty, &readfs ) )         /* input from source 1 available */
		{
			lBytesRead = read(f_pPort->fdTty, &f_pbyByte[ulTotalBytesRead], ulCurrentLen);

			if( lBytesRead < 0)
				return cOCTRS232API_RC_INTERNAL;

			ulTotalBytesRead += lBytesRead;
			ulCurrentLen     -= lBytesRead;
		}
	}
	if( iNumRetries-- <= 0 )
		break;

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
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
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
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
		return cOCTRS232API_RC_PORT_CLOSED;


	return RS232IoGetCharCnt( &l_aRS232Port[f_pParm->hPort],
								f_pParm->pbyBuffer,
								f_pParm->ulLen,
								&f_pParm->ulRecvLen );
	return 0;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

    Function: RS232IoPutCharCnt

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCTRS232API_RC  RS232IoPutCharCnt( tPRS232_PORT f_pPort, tOCT_UINT8 *f_pCh, tOCT_UINT32 f_ulLen )
{
	tOCT_INT32 ulBytesWritten;
	tOCT_INT32 ulTry = 50;
	

	do
	{
	    ulBytesWritten = write( f_pPort->fdTty, f_pCh, f_ulLen );

    	if(  ulBytesWritten != f_ulLen )
    	{
			if( errno == EAGAIN )
			{
				OctOsalSleepMs(20);
				ulTry--;
				continue;
			}

			perror( "RS232 write:");
			return cOCTRS232API_RC_INTERNAL;
		}
		else
		    return cOCTRS232API_RC_OK;

	}while( ulTry > 0 ); 

	
	perror( "RS232 write:");
	return cOCTRS232API_RC_INTERNAL;
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
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
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
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
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
    tOCT_INT32	iOldModemControl;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
		return cOCTRS232API_RC_PORT_CLOSED;


    /* Get the current state prior to changing it */
	if( ioctl(l_aRS232Port[f_pParm->hPort].fdTty, TIOCMGET, &iOldModemControl) )
        return cOCTRS232API_RC_INTERNAL;

    if(f_pParm->fState)
		iOldModemControl |= TIOCM_DTR;
	else
		iOldModemControl &= ~TIOCM_DTR;

	if( ioctl(l_aRS232Port[f_pParm->hPort].fdTty, TIOCMSET, &iOldModemControl) )
		return cOCTRS232API_RC_INTERNAL;

    return cOCTRS232API_RC_OK;

}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:     OctRS232ApiFlush

Description:

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC OctRS232ApiFlush( tPOCTRS232API_FLUSH f_pParm )
{
	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
		return cOCTRS232API_RC_PORT_CLOSED;

	if( f_pParm->fFlushRx )
		tcflush(l_aRS232Port[f_pParm->hPort].fdTty, TCIFLUSH);

	if( f_pParm->fFlushTx )
		tcflush(l_aRS232Port[f_pParm->hPort].fdTty, TCOFLUSH);

	return cOCTRS232API_RC_OK;

}
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:     OctRS232ApiSetRts

Description:  Change terminal RTS Setting

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCTRS232API_RC OctRS232ApiSetRts( tPOCTRS232API_SET_RTS f_pParm )
{
    tOCT_INT32	iOldModemControl;

	if( f_pParm == NULL )
		return cOCTRS232API_RC_BAD_PARAM;

	if( f_pParm->hPort > cOCTRS232API_MAX_PORT_INST )
		return cOCTRS232API_RC_BAD_PORT_HANDLE;

	/* Nothing to do */
	if( l_aRS232Port[f_pParm->hPort].fIsOpen == 0 )
		return cOCTRS232API_RC_PORT_CLOSED;

    /* Get the current state prior to changing it */
	if( ioctl(l_aRS232Port[f_pParm->hPort].fdTty, TIOCMGET, &iOldModemControl) )
        return cOCTRS232API_RC_INTERNAL;

    if(f_pParm->fState)
		iOldModemControl |= TIOCM_RTS;
	else
		iOldModemControl &= ~TIOCM_RTS;

	if( ioctl(l_aRS232Port[f_pParm->hPort].fdTty, TIOCMSET, &iOldModemControl) )
		return cOCTRS232API_RC_INTERNAL;

    return cOCTRS232API_RC_OK;

}

#endif /* OCT_ENV_TYPE_LINUX */
