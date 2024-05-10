
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: util_config.c

Copyright (c) 2018 Octasic Inc. All rights reserved.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-04.10.01-B3387 (2018/01/29)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "oct_util_config.h"
#include "octvc1_generic_rc.h"


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrTrimLeft
|
|	Description:    Remove all space character ( ' ' ) at the left of a string
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString			=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrTrimLeft(tOCT_PSZ f_pszString )
{
	tOCT_PSZ pszDest;

	pszDest = f_pszString;
	if( f_pszString != NULL )
	{
		while( *f_pszString != '\0' && 
				( isspace( (tOCT_INT32)*f_pszString ) || iscntrl( (tOCT_INT32)*f_pszString ) ) )
			f_pszString++;
		 
		while (*f_pszString != '\0')
			*pszDest++ = *f_pszString++;
			
		*pszDest = '\0';
	}
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrTrim
|
|	Description:    Remove all space character ( ' ' ) at the right and left of a string
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString			=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrTrim(tOCT_PSZ f_pszString )
{
	tOCT_PSZ pszDest;
	tOCT_PSZ pszTemp = f_pszString;

	pszDest = f_pszString;
	if( pszTemp != NULL )
	{
		while( *pszTemp != '\0' && 
				( isspace( (tOCT_INT32)*pszTemp ) || iscntrl( (tOCT_INT32)*pszTemp ) ) )
			pszTemp++;
		 
		while (*pszTemp != '\0')
			*pszDest++ = *pszTemp++;
			
		*pszDest = '\0';
	}

	pszDest = f_pszString;

	if(pszDest != NULL && pszDest[0] != '\0')
	{
		pszDest = f_pszString + strlen( f_pszString ) - 1;
		
		while ( isspace( (tOCT_INT32)*pszDest ) || iscntrl( (tOCT_INT32)*pszDest ) ) 
		{
			*pszDest-- = '\0';
			
			/* Don't go to far */
            if( pszDest == f_pszString - 1 )
				break;
		}
	}
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrTrimRight
|
|	Description:    Remove all space character ( ' ' ) at the right of a string
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString		=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrTrimRight(tOCT_PSZ f_pszString )
{
	tOCT_PSZ pszTemp;

	if(f_pszString != NULL && f_pszString[0] != '\0')
	{
		pszTemp = f_pszString + strlen( f_pszString ) - 1;
		
		while ( isspace( (tOCT_INT32)*pszTemp ) || iscntrl( (tOCT_INT32)*pszTemp ) )
		{
			*pszTemp-- = '\0';
			
			/* Don't go to far */
            if( pszTemp == f_pszString - 1 )
				break;
		}
	}
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrUpr
|
|	Description:    Convert all character of the string to upper character
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrUpr(tOCT_PSZ f_pszString )
{
	if(f_pszString != NULL && f_pszString[0] != '\0')
	{
		while( *f_pszString )
		{
			*f_pszString = (tOCT_CHAR)toupper( *f_pszString );
			f_pszString++;
		}
	}
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrLwr
|
|	Description:    Convert all character of the string to lower character
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrLwr(tOCT_PSZ f_pszString )
{
	if(f_pszString != NULL && f_pszString[0] != '\0')
	{
		while( *f_pszString )
		{
			*f_pszString = (tOCT_CHAR)tolower( *f_pszString );
			f_pszString++;
		}
	}
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrRemoveSubString
|
|	Description:    Get and remove from a string all character up to f_chEofToken or f_ulLength
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ pszSubString			=> SubString destination
|  tOCT_PSZ f_pszString				=> String
|   tOCT_CHAR f_chEofToken		=> End of substring
|	tOCT_UINT32 f_ulLength			=> Max substring length
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrRemoveSubString(tOCT_PSZ pszSubString,tOCT_PSZ f_pszString, tOCT_CHAR f_chEofToken, tOCT_UINT32 f_ulLength )
{
    tOCT_UINT32 x = 0,y;

	/*  Get char up to stop char */
    for(x=0;( (f_pszString[x]) && ( f_pszString[x] != f_chEofToken ) && (x<f_ulLength) );x++)
        pszSubString[x] = f_pszString[x];

	/*  Max substring */
	if( x == f_ulLength )
		pszSubString[x-1] = '\0';
	else
		pszSubString[x] = '\0';

	/*  Chck if end of string */
    if(f_pszString[x]) 
		++x;

    y=0;

	/*  Remove this substring */
    while((f_pszString[y++] = f_pszString[x++]) != 0);
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrCenter
|
|	Description:    Center a string using padding character
|
|   Return type:    tOCT_BOOL32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ pszCenter			=> Centered string
|   tOCT_CHAR f_chPadChar		=> character to use for padding	
|  tOCT_PSZ f_pszString			=> String to center
|   tOCT_INT16 f_sMaxLen			=> Maximum output string
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_BOOL32 OADF_APIENTRY OctAdfUtilStrCenter(tOCT_PSZ pszCenter, tOCT_CHAR f_chPadChar,tOCT_PSZ f_pszString, tOCT_INT16 f_sMaxLen )
{
	tOCT_INT32 cLen;		
	tOCT_INT32 cPad;
	tOCT_PSZ	pszPad;

	/*  End string */
	memset( pszCenter, 0, f_sMaxLen );

	strncpy( pszCenter, f_pszString, f_sMaxLen );
	*( pszCenter + f_sMaxLen - 1 ) = 0;

	OctAdfUtilStrTrim( pszCenter );
	cLen = strlen( pszCenter );

	/*  Calc nb to pad width */
	cPad = ( ( f_sMaxLen - cLen ) / 2 );

	/*  Move string to center */
	memmove(pszCenter+cPad, pszCenter, cLen );
	
	/*  Pad up to pszCenter */
	memset( pszCenter, f_chPadChar, cPad );

	/*  Pad from pszCenter */
	cLen = strlen( pszCenter );
	pszPad = pszCenter + cLen;
	cPad = f_sMaxLen - cLen - 1;

	/*  Pad up to pszCenter */
	memset( pszPad, f_chPadChar, cPad );

	return( cOCT_TRUE );
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		*OctAdfUtilStrExtractSubString
|
|	Description:    
|
|   Return type:    tOCT_CHAR 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString
|   tOCT_CHAR chStartOfSub
|	tOCT_CHAR chEndOfSub
|  tOCT_PSZ pszSubString
|   tOCT_INT16 sMaxLen
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_CHAR * OADF_APIENTRY OctAdfUtilStrExtractSubString(
					tOCT_PSZ f_pszString, 
					tOCT_CHAR chStartOfSub, 
					tOCT_CHAR chEndOfSub, 
					tOCT_PSZ pszSubString, 
					tOCT_INT16 sMaxLen )
{
	tOCT_PSZ pszSub2 = NULL;
	tOCT_PSZ pszTemp = f_pszString;
	tOCT_PSZ  pszSub1 = NULL;
	tOCT_CHAR achMarker[2];
	tOCT_CHAR * pchMarker;

	/*  Valid this string */
	if( !pszTemp )
		return( NULL );

	/*  Set markers */
	achMarker[0] = chStartOfSub;
	achMarker[1] = chEndOfSub;
	pchMarker = achMarker;

	if( pszSubString )
		*pszSubString = 0;

	while( *pszTemp )
	{
		/*  Is marker value */
		if( *pszTemp == *pchMarker )
		{
			/* Chck is doing endofstr */
			if( pszSub1 )
			{
				pszSub2 = pszTemp;
				break;
			}

			/* Keep start of string */
			pszSub1 = pszTemp+1;

			/*  Set for next marker */
			pchMarker++;
		}
		pszTemp++;
	}

	/*  Chck if found first marker */
	if( pszSubString && pszSub2 )
	{
		/*  Calc sub len */
		tOCT_INT32 sLen = (pszSub2-pszSub1);

		/*  Chck mMAX len string */
		if( sMaxLen )
		{
			/*  Ajust sub len */
			if( sLen > sMaxLen )
				sLen = sMaxLen;
		}

		strncpy( pszSubString, pszSub1, sLen );

		/*  Chck mMAX len ... end the string */
		if( sMaxLen )
		{
			if( sLen > sMaxLen )
				sLen = sMaxLen-1;
		}
		/*  End sub */
		*(pszSubString+sLen )= 0;
	}
	/*   */
	return( pszSub1 );
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrMatchBrace
|
|	Description:    Find a string inside brace token
|
|   Return type:    tOCT_INT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszStr		=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrMatchBrace(tOCT_PSZ f_pszString, tOCT_CHAR f_chStart, tOCT_CHAR f_chEnd, 
							   tOCT_BOOL32 f_UseCRLF_EoL, tOCT_INT32 * f_plEndPos )
{
	tOCT_PSZ	pszTemp = (tOCT_PSZ)f_pszString;
	tOCT_UINT32 cCount=0;
	tOCT_INT32 lStartPos = -1;

	if( !f_pszString || !f_plEndPos )
		return -1;

	*f_plEndPos = -1;

	/* Find Start Brace */
	while( *pszTemp && 
			( !f_UseCRLF_EoL || 
			( f_UseCRLF_EoL && ( *pszTemp != '\r' ) && ( *pszTemp != '\n' ) ) ) )
	{
		/*  Is marker value */
		if( *pszTemp == f_chStart )
		{
			lStartPos = pszTemp - f_pszString;
			cCount++;
			pszTemp++;
			break;
		}
		pszTemp++;
	}

	if( lStartPos >= 0 )
	{
		while( *pszTemp && 
				( !f_UseCRLF_EoL || 
				( f_UseCRLF_EoL && ( *pszTemp != '\r' ) && ( *pszTemp != '\n' ) ) ) )
		{
			/*  Is marker value */
			if( *pszTemp == f_chStart )
				cCount++;
			else
			{
				if( *pszTemp == f_chEnd )
				{
					cCount--;
					if( !cCount )
					{
						*f_plEndPos = pszTemp - f_pszString;
						break;
					}
				}
			}
			pszTemp++;
		}
	}

	return lStartPos;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetLen
|
|	Description:    Get string length where string end with \n or \r or null 
|
|   Return type:    tOCT_INT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszStr		=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilStrGetLen(tOCT_PSZ f_pszStr )
{
	tOCT_CHAR * pchEnd = f_pszStr;

	/*  Process up to end of string */
	while ( *pchEnd && ( *pchEnd != '\r' ) && ( *pchEnd != '\n' ) )
		pchEnd++; 

	return( (tOCT_UINT32)( pchEnd - f_pszStr) ); 
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrRMPendingCrLf
|
|	Description:    Remove all \n or \r from the end of the string
|
|   Return type:    void 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_f_pszString			=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrRMPendingCrLf(tOCT_PSZ f_pszString )
{

	tOCT_PSZ pszTemp;

	if( !f_pszString )
		return;

	pszTemp = f_pszString+strlen( f_pszString )-1;
	while(f_pszString <= pszTemp )
	{
		if( ( *pszTemp == '\r' ) || ( *pszTemp == '\n' ) )
			*pszTemp = 0;
		else
			break;

		pszTemp--;
	}
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrISBlank
|
|	Description:    Verify if a string is empty ... 
|
|					NOTE: String with all space characters will be considere empty
|
|   Return type:    tOCT_BOOL32 
|
|						cOCT_TRUE	=> String contain nothing or only space
|						cOCT_FALSE	=> String is not empty
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ pszString		=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_BOOL32 OADF_APIENTRY OctAdfUtilStrISBlank(tOCT_PSZ f_pszString )
{
	tOCT_PSZ pszTemp = f_pszString;

	if( !pszTemp )
		return( cOCT_TRUE );

	while( *pszTemp )
		if( *pszTemp++ != ' ' )
			return( cOCT_FALSE );

	return( cOCT_TRUE );
}




/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrFindNextChar
|
|	Description:    Find the next specific character of the string
|
|   Return type:    tOCT_INT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszString
|   tOCT_CHAR f_ch				=> Character to find
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrFindNextChar(tOCT_PSZ f_pszString, tOCT_CHAR f_ch )
{
	tOCT_INT32 i;
	tOCT_PSZ pszTemp = f_pszString;

	/*  Get get the character */
	for( i=0; *pszTemp; i++, pszTemp++)
		if( *pszTemp == f_ch )
			return( i );

	return(-1);
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\


Function:		OctAdfUtilStrCharRepl

Description:    Replace all char of string by 


---------------------------------------------------------------------------
|	Argument		|				Description
---------------------------------------------------------------------------
tOCT_PSZ	f_pszString
tOCT_CHAR f_ch
tOCT_PSZ f_pszRep
tOCT_UINT32 f_ulMax
tOCT_PSZ f_pszStrOut

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrCharRepl( tOCT_PSZ f_pszString, tOCT_CHAR f_ch,tOCT_PSZ f_pszRep, 
								  tOCT_UINT32 f_ulMax,tOCT_PSZ f_pszStrOut )
{
	tOCT_PSZ pszIn;
	tOCT_PSZ pszOut;
	tOCT_UINT32 ul2Rep;
	tOCT_UINT_PTR pStrMax;

	if( !f_pszString || !f_pszRep || !f_ulMax || !f_pszStrOut )
		return -1;

	/* End str */
	*f_pszStrOut = 0;

	/* Be ready to process */
	pszIn = f_pszString;
	pszOut = f_pszStrOut;
	pStrMax = (tOCT_UINT_PTR)f_pszStrOut + f_ulMax;
	ul2Rep = strlen( f_pszRep );

	while( *pszIn )
	{
		/* Chck if can process */
		if( ( (tOCT_UINT_PTR)pszOut + ul2Rep ) > pStrMax )
			break;

		if( *pszIn == f_ch )
		{
			strcpy( pszOut, f_pszRep );
			pszOut += ul2Rep;
		}
		else
		{
			*pszOut = *pszIn;
			pszOut++;
		}

		pszIn++;
	}
	/* End the str */
	*pszOut=0;
	return strlen( f_pszStrOut );
}

/*******************************************************************************

	OctAdfUtilStrReplChar	 : Replace all char of string by f_chRep
	
	tOCT_PSZ	f_pszString
	tOCT_CHAR f_ch
	tOCT_PSZ f_pszRep
	
	return			 :	

*******************************************************************************/

void OADF_APIENTRY OctAdfUtilStrReplChar(tOCT_PSZ f_pszString, tOCT_CHAR f_ch, tOCT_CHAR f_chRep  )
{
	tOCT_PSZ pszIn = f_pszString;

	if( !f_pszString  )
		return ;

	while( *pszIn )
	{
		if( *pszIn == f_ch )
			*pszIn = f_chRep;

		pszIn++;
	}

}


/*******************************************************************************

	OctAdfUtilStrtok	 : Find first occurence of token
	
	tOCT_PSZ pszStr		 : Str to chck
	tOCT_PSZ pszToken     :
	tOCT_PSZ pszNextStr	 : 
	
	return			 :	Start of occurence

*******************************************************************************/
tOCT_CHAR * OADF_APIENTRY OctAdfUtilStrtok(tOCT_PSZ f_pszStr,tOCT_PSZ f_pszToken, 
						  tOCT_PSZ *f_ppszNextStr )
{
	tOCT_PSZ pszNextStr;
	tOCT_PSZ pszStr;

	if( !f_pszStr )
		return( NULL );

	pszNextStr = strpbrk( f_pszStr, f_pszToken );
	if( pszNextStr )
	{
		*pszNextStr = 0;
		pszNextStr++;
		if( *pszNextStr == '\n' )
			pszNextStr++;

		if( !*pszNextStr  )
			pszNextStr = NULL;
		
		pszStr = f_pszStr;
	}
	else
	{
		pszStr = f_pszStr;
		pszNextStr = NULL;
	}

	if( f_ppszNextStr )
		*f_ppszNextStr = pszNextStr;

	return( pszStr );
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetStrCount
|
|	Description:    Get string count where string end with \n or \r or null 
|
|   Return type:    tOCT_INT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszStr		=> String to process
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctAdfUtilStrGetStrCount(tOCT_PSZ f_pszStr )
{
	tOCT_UINT32 cCount = 0;
	tOCT_CHAR * pchEnd = f_pszStr;

	if( !f_pszStr )
		return 0;

	/*  Process up to end of string */
	while( *pchEnd )
	{
		if( ( *pchEnd == '\r' ) || ( *pchEnd == '\n' ) )
		{
			if((( *pchEnd == '\r' ) && ( *(pchEnd+1) == '\n' )) ||
				(( *pchEnd == '\n' ) && ( *(pchEnd+1) == '\r' )) )
				pchEnd++;

			cCount++;
		}
		pchEnd++; 
	}
	if( ( pchEnd-1 > f_pszStr ) && (*(pchEnd-1) != '\n') && (*(pchEnd-1) != '\r'))
		cCount++;

	return( cCount ); 
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetWordCount
|
|	Description:    Get word count where string end with \n or \r or null 
|
|   Return type:    tOCT_INT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszStr		=> String to process
|	tOCT_PSZ pszWordSet	=> Word splitter
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilStrGetWordCount(tOCT_PSZ f_pszStr,tOCT_PSZ f_pszWordSet )
{
	tOCT_UINT32 cCount = 0;
	tOCT_PSZ pchEnd;
	tOCT_PSZ pszStr;
	tOCT_INT32 lPos;

	if( !f_pszWordSet || !f_pszStr )
		return 0;

	pchEnd = f_pszStr+OctAdfUtilStrGetLen( f_pszStr );
	pszStr = f_pszStr;

	/*  Process up to end of string */
	while( pszStr < pchEnd )
	{
		lPos = strcspn( pszStr, f_pszWordSet );
		if( lPos >= 0 )
		{
			cCount++;
			pszStr += lPos+1;
		}
		else
			break;
	}

	return( cCount ); 
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetWordLen
|
|	Description:    Get word len
|
|   Return type:    tOCT_INT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszStr		=> String to process
|	tOCT_PSZ pszWordSet	=> Word splitter
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrGetWordLen(tOCT_PSZ f_pszStr,tOCT_PSZ f_pszWordSet, tOCT_UINT16 f_usWordOfs )
{
	tOCT_UINT16	cWord = 0;
	tOCT_INT32 lPos=-1;
	tOCT_PSZ pszStr = f_pszStr;

	if( !f_pszWordSet || !f_pszStr )
		return -1;

	/* Should be while(cOCT_TRUE) .. avoid compiler warning */
	while( f_pszWordSet )
	{
		lPos = strcspn( pszStr, f_pszWordSet );
		if( lPos < 0 )
			return 0;

		if( f_usWordOfs == cWord )
			return lPos;

		cWord++;
		pszStr += (lPos+1);
	}
	return -1;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetWord
|
|	Description:    Get word
|
|   Return type:    tOCT_INT32

|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|  tOCT_PSZ f_pszStr				=> String to process
|	tOCT_PSZ pszWordSet			=> Word splitter
|	tOCT_INT16 f_sWordOfs			=>
|	tOCT_PSZ f_pszSubString		=>
|	tOCT_INT16 f_sMaxLen			=>
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrGetWord(tOCT_PSZ f_pszStr,tOCT_PSZ f_pszWordSet, 
								 tOCT_UINT16 f_usWordOfs,tOCT_PSZ f_pszSubString, tOCT_INT16 f_sMaxLen )
{
	tOCT_PSZ pszStr = f_pszStr;
	tOCT_UINT16	cWord = 0;
	tOCT_INT32 lPos=-1;

	if( !f_pszWordSet || !f_pszStr || !f_pszSubString || !f_sMaxLen)
		return 0;

	*f_pszSubString = 0;

	/* Should be while(cOCT_TRUE) .. avoid compiler warning */
	while( f_pszWordSet )
	{
		lPos = strcspn( pszStr, f_pszWordSet );
		if( lPos < 0 )
			return 0;

		if( f_usWordOfs == cWord )
		{
			if( (lPos+1) <= f_sMaxLen )
			{
				strncpy( f_pszSubString, pszStr, lPos );
				f_pszSubString[lPos] = 0;
				return( lPos );
			}
			return -1;
		}

		cWord++;
		pszStr += (lPos+1);
	}
	return lPos;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetStrId
|
|	Description:    
|
|   Return type:    tOCT_INT32

|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_STR_ID * f_pStrId	=> Table string to check
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrGetStrId( tOCTADF_UTIL_STR_ID * f_pStrId,tOCT_PSZ f_pszWord )
{
	tOCTADF_UTIL_STR_ID * pStrId;

	if( !f_pszWord || !f_pStrId )
		return -1;

	pStrId = f_pStrId;

	while( pStrId->pszString )
	{
		if( ( *f_pszWord == *pStrId->pszString ) &&
			( strcmp( f_pszWord, pStrId->pszString ) == 0 ) )
			return pStrId->ulId;

		pStrId++;
	}
	return pStrId->ulId;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilStrGetIdStr
|
|	Description:    
|
|   Return type:    tOCT_CHAR *

|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_STR_ID * f_pStrId	=> Table string to check
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_CHAR * OADF_APIENTRY OctAdfUtilStrGetIdStr( tOCTADF_UTIL_STR_ID * f_pStrId, tOCT_UINT32 f_ulId )
{
	tOCTADF_UTIL_STR_ID * pStrId;

	if( !f_pStrId )
		return NULL;

	pStrId = f_pStrId;

	while( pStrId->pszString )
	{
		if( pStrId->ulId == f_ulId )
			return pStrId->pszString;

		pStrId++;
	}
	return NULL;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		FindStartNextKey
|
|	Description:    
|
|   Return type:    tOCT_PSZ 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCT_PSZ f_pszBuffer
|   tOCT_PSZ *ppszEndOfKey
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_PSZ FindStartNextKey( tOCT_PSZ f_pszSectionStart, tOCT_PSZ f_pszBuffer, tOCT_PSZ *ppszEndOfKey )
{
	tOCT_PSZ pszTemp = f_pszBuffer;
	tOCT_PSZ pszStartOfKey = NULL;
	tOCT_PSZ pszTempStartOfKey = NULL;
	tOCT_UINT32 ulLen;
	tOCT_CHAR szKeyLine[cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH+1];
	tOCT_BOOL32 fNeedEndOfCurrent = cOCT_FALSE; /* End of current is start of comment or start of section */

	/*  Assign End to start */
	if( ppszEndOfKey )
	{
		*ppszEndOfKey = f_pszBuffer;
		fNeedEndOfCurrent = cOCT_TRUE;
	}

	if( !*pszTemp )
		return( NULL );

	ulLen = 0;

	/*  Find if start of a line */
	if( f_pszSectionStart  )
	{
		if( ( f_pszSectionStart != pszTemp ) &&
			(*(pszTemp-1) != '\n' ) && ( *(pszTemp+1) != '\r' ) )
			ulLen = OctAdfUtilStrGetLen( pszTemp );
	}
	else if( (*(pszTemp-1) != '\n' ) && ( *(pszTemp+1) != '\r' ) )
		ulLen = OctAdfUtilStrGetLen( pszTemp );

	while( *pszTemp )
	{
		tOCT_PSZ pszEqual;

		pszTemp += ulLen;

		/*  Move to start of next line */
		ulLen = OctAdfUtilStrGetLen( pszTemp );
		if( !ulLen )
		{
			if( *pszTemp == cOCTADF_UTIL_CHAR_CR )
				ulLen++;

			if( ( *pszTemp == cOCTADF_UTIL_CHAR_LF ) || ( *(pszTemp+1) == cOCTADF_UTIL_CHAR_LF ) )
				ulLen++;

			continue;
		}

		pszTempStartOfKey = pszTemp;

		/*  Chck for comment or section */
		if(	( fNeedEndOfCurrent && ( *pszTemp == '#' ) ) || ( *pszTemp == '[' ) )
			break;

		ulLen = mMIN(ulLen, cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH);
		strncpy( szKeyLine, pszTemp, ulLen );
		szKeyLine[ulLen]=0;

		/*  Find end or key ... = */
		if( ( pszEqual = strchr( szKeyLine, '=' ) ) == NULL )
			continue;
		*pszEqual = 0;

		/*  One word key name */
		strtok( szKeyLine, cOCTADF_UTIL_CHAR_WORDTOKEN );

		/* Should be null ... need only one word */
		if( strtok( NULL, cOCTADF_UTIL_CHAR_WORDTOKEN ) )
			continue;

		/*  That a key definition; */
		pszStartOfKey = pszTempStartOfKey;
		break;
	}

	/*  Need end of key */
	if( ppszEndOfKey )
	{
		/*  When stop by start of next section */
		if( !pszStartOfKey )
			*ppszEndOfKey = pszTemp;
		else
			*ppszEndOfKey = pszStartOfKey;	/* End of previous key = start of this key */
	}

	return( pszStartOfKey );
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		FindStartNextSection
|
|	Description:    
|
|   Return type:    tOCT_PSZ 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCT_PSZ f_pszBuffer
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_PSZ FindStartNextSection( tOCT_PSZ f_pszBuffer )
{
	tOCT_PSZ pszTemp = f_pszBuffer;

	if( !f_pszBuffer )
		return( NULL );

	do
	{
		pszTemp = strchr( pszTemp, '[' );

		if( pszTemp )
		{
			/*  Be sure it's a section */
			if((pszTemp==f_pszBuffer)||(*(pszTemp-1)==cOCTADF_UTIL_CHAR_CR) || (*(pszTemp-1)== cOCTADF_UTIL_CHAR_LF))
				return( pszTemp );

			/*  Next */
			pszTemp++;
		}

	}
	while( pszTemp );

	return( NULL );
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		FindPrivateSection
|
|	Description:    
|
|   Return type:    tOCT_PSZ 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCT_PSZ f_pszSection
|   tOCT_PSZ f_pszSectionName
|   tOCT_PSZ f_pszBuffer
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_PSZ FindPrivateSection( tOCT_PSZ f_pszSection, tOCT_PSZ f_pszSectionName, tOCT_PSZ f_pszBuffer )
{
	tOCT_CHAR szSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];
	tOCT_PSZ	pszBuf = f_pszBuffer;
	tOCT_PSZ	pszTemp;

	szSection[0] = 0;

	if( !f_pszBuffer || ( f_pszSection && strlen( f_pszSection ) > cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH ) )
		return( NULL );

	if( f_pszSection )
	{
		sprintf( szSection, "[%s]", f_pszSection );

		pszTemp = strstr( pszBuf, szSection );
		while( pszTemp )
		{
			/*  Be sure it's a section */
			if((pszTemp==pszBuf)||(*(pszTemp-1)==cOCTADF_UTIL_CHAR_CR) || (*(pszTemp-1)== cOCTADF_UTIL_CHAR_LF))
			{
				pszTemp += strlen( szSection );
				strcpy( szSection, f_pszSection );
				break;
			}
			else
			{
				pszBuf = pszTemp + strlen( szSection );
				pszTemp = strstr( pszBuf, szSection );
			}
		}
	}
	else	/*  Find next section */
	{
		pszTemp = FindStartNextSection( pszBuf );

		/*  Be sure we found */
		if(pszTemp)
		{
			tOCT_INT32 i;

			pszTemp++;

			/* find end of section name */
			for(i=0; *pszTemp && i < (int)sizeof(szSection); i++ )
			{
				if(*pszTemp == ']')
				{
					pszTemp++; /*  skip this */
					break;
				}
				szSection[i] = *pszTemp++;
			}
			szSection[i]=0;
		}
	}

	if( f_pszSectionName )
		strcpy( f_pszSectionName, szSection );

	return( pszTemp );
}


static tOCT_INT32 UtilStricmp_( const tOCT_CHAR *f_pStr1, const tOCT_CHAR *f_pStr2 )
{
	tOCT_CHAR szStr1[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];
	tOCT_CHAR szStr2[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];

	strcpy( szStr1, f_pStr1 );
	OctAdfUtilStrLwr( szStr1 );

	strcpy( szStr2, f_pStr2 );
	OctAdfUtilStrLwr( szStr2 );

	return strcmp( szStr1, szStr2 );

}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		FindPrivateKey
|
|	Description:    
|
|   Return type:    tOCT_PSZ 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCT_PSZ f_pszItemName
|   tOCT_PSZ f_pszItemNameValue
|   tOCT_INT32 f_lMaxKeyValue
|   tOCT_PSZ f_pszSectionBuff
|	tOCT_BOOL32 * f_pfComplete
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_PSZ FindPrivateKey( tOCT_PSZ f_pszItemName, tOCT_PSZ f_pszItemNameValue, tOCT_INT32 f_lMaxKeyValue, 
				   tOCT_PSZ f_pszSectionBuff, tOCT_BOOL32 * f_pfComplete, tOCT_BOOL32 f_CaseSensitive )
{
	tOCT_PSZ pszTemp = f_pszSectionBuff;
	tOCT_PSZ	pszItemNameFound = NULL;
	tOCT_PSZ	pszStartOfKeyValue = NULL;
	tOCT_UINT32 ulLen;
	tOCT_CHAR szKeyName[cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH+1];

	/*  May search for next key name in section */
	if( f_pszItemName )
	{
		tOCT_BOOL32 fNoKey=cOCT_FALSE;
		ulLen = 0;

		/*  Set none complete */
		if( f_pfComplete )
			*f_pfComplete = cOCT_FALSE;

		/* Should be while(cOCT_TRUE) but avoid compiler warning */
		while( f_pszItemName )
		{
			tOCT_UINT32 ulCurLen;
			tOCT_INT32 iCmp;

			/*  End of buffer */
			if( !*pszTemp )
				return( NULL );

			pszTemp += ulLen;

			/*  Move to start of next line */
			ulLen = OctAdfUtilStrGetLen( pszTemp );
			if( !ulLen )
			{
				if( *pszTemp == cOCTADF_UTIL_CHAR_CR )
					ulLen++;

				if( ( *pszTemp == cOCTADF_UTIL_CHAR_LF ) || ( *(pszTemp+1) == cOCTADF_UTIL_CHAR_LF ) )
					ulLen++;

				continue;
			}
			ulCurLen = mMIN( ulLen, cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH );

			strncpy( szKeyName, pszTemp, ulCurLen  );
			szKeyName[ulCurLen]=0;

			OctAdfUtilStrTrimLeft( szKeyName );
			if( szKeyName[0] == '#' )
				continue;

			/*  End the key */
			strtok( szKeyName, " =" );

			/*  Find if same key name */
			if( f_CaseSensitive )
				iCmp = strcmp( szKeyName, f_pszItemName );
			else
				iCmp = UtilStricmp_( szKeyName, f_pszItemName );

			if( !iCmp )
			{
				tOCT_INT32 lLen;
				tOCT_PSZ pszSect = pszItemNameFound;

				/*  Find the keyname */
				pszItemNameFound = strstr( pszTemp, szKeyName );
				pszSect = pszItemNameFound;

				/*  Move to start of value */
				pszItemNameFound += strlen( szKeyName );
				fNoKey=cOCT_FALSE;

				while( *pszItemNameFound != '=' )
				{
					/*  Not the key value */
					if( ( *pszItemNameFound != ' ' ) && ( *pszItemNameFound != '=' ) )
					{
						pszTemp = pszItemNameFound;
						fNoKey=cOCT_TRUE;
						break;
					}

					pszItemNameFound++;
				}
				if( fNoKey )
					continue;

				/*  Move over = */
				pszItemNameFound++;
				pszStartOfKeyValue = pszItemNameFound;

				/*  Find if same section ... may find this key name as part of next section */
				while( pszSect > f_pszSectionBuff )
				{
					if( (*pszSect == '[' ) && ((*(pszSect-1)== cOCTADF_UTIL_CHAR_CR) || (*(pszSect-1)== cOCTADF_UTIL_CHAR_LF)) )
					{
						/*  Found section name soo Out of section */
						return( NULL );
					}
					pszSect--;
				}

				/*  Chck if need key content */
				if( f_pszItemNameValue )
				{
					tOCT_PSZ pszEndOfKey;

					pszTemp = FindStartNextKey( NULL, pszItemNameFound, &pszEndOfKey );

					lLen = mMIN( (pszEndOfKey - pszItemNameFound), f_lMaxKeyValue );

					strncpy( f_pszItemNameValue, pszItemNameFound, lLen );
					*(f_pszItemNameValue+lLen)=0;

					/* RM /r/n at end of key */
					OctAdfUtilStrRMPendingCrLf( f_pszItemNameValue );

					/*  Set complete flag */
					if( f_pfComplete && ( (pszEndOfKey - pszItemNameFound) == lLen ) )
						*f_pfComplete = cOCT_TRUE;
				}
				break;
			}
		}
	}
	else
	{
		if( f_pszItemNameValue )
			*f_pszItemNameValue=0;

		/*  Grabe up to end of key == start of new key of start of section */
		pszTemp = FindStartNextKey( NULL, pszTemp, NULL );
		if( pszTemp )
		{
			/*  Copy up to = */
			tOCT_INT32 lEndOfKey = OctAdfUtilStrFindNextChar( pszTemp, '=' );
			tOCT_INT32 lLen = mMIN( lEndOfKey, f_lMaxKeyValue-1 );

			if( f_pszItemNameValue )
			{
				strncpy( f_pszItemNameValue, pszTemp, lLen );
				*(f_pszItemNameValue+lLen) = 0;

				OctAdfUtilStrRMPendingCrLf(f_pszItemNameValue );
				OctAdfUtilStrTrim( f_pszItemNameValue );
			}

			pszStartOfKeyValue = pszTemp+lEndOfKey+1;

			/*  Set complete flag */
			if( f_pfComplete && ( lEndOfKey == lLen ) )
				*f_pfComplete = cOCT_TRUE;

		}
	}
	return( pszStartOfKeyValue );
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetItem
|
|	Description:	Get configuration item from a null ascii terminated configuration buffer.
|
|					: If Section is NULL return all section name... space delimited
|					: If key is NULL return all section content or size if f_pszData is null
|					: If key is -1 return all key name
|					: If f_pszData is NULL return len of or section or key
|
|   Return type:    tOCT_INT32 Len of Value read or -1 on error ...
|					f_pszData may be set on error saying buffer not complete
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|
|		tOCT_PSZ	f_pszSection		=>	Configuration section name. Word with not space contain in brace ex: [Section_Name]
|										Section name must have there own line.
|		tOCT_PSZ	f_pszItemName		=>	Item name. First word of a line with no space 
|										ex: LOGFILE=d:\temp\log 
|												"LOGFILE" is the item name and "d:\temp\log" the item data
|		tOCT_PSZ	f_pszDefault		=>	String to return if the item is not found
|		tOCT_PSZ	f_pszData			=>	Requested data
|		tOCT_INT32	f_lValueMax			=>	Maximum space allow for the requested data
|		tOCT_PSZ	f_pszConfigBuffer	=>	Configuration buffer.
|
|		RETURN:
|				Requested data size.
|				-1 if can not process the request
|
|		PS:		
|			1: If f_pszSection is NULL, f_pszData will contain all section name... space delimited.
|			2: If f_pszSection is NULL and f_pszData is NULL, RETURN error -1.
|			3: If f_pszItemName is NULL return all section content.
|			4: If f_pszItemName is NULL and f_pszData is NULL, RETURN will be the size of all section content.
|			5: If f_pszItemName is -1 return all key name ... space delimited
|			6: If f_pszData is NULL, RETURN the length of the section or the item value.
|	
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilConfigGetItem( 
					tOCT_PSZ f_pszSection, 
					tOCT_PSZ f_pszItemName, 
					tOCT_PSZ f_pszDefault, 
					tOCT_PSZ f_pszData, 
					tOCT_INT32 f_lValueMax, 
					tOCT_PSZ f_pszConfigBuffer )
{
	tOCT_INT32 lValue=0;
	tOCT_PSZ pszTemp = f_pszConfigBuffer;
	tOCT_PSZ f_pszSectionFound;
	tOCT_CHAR szSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];
	tOCT_PSZ pszStartOfKeyValue;


	/*  Valid section name len */
	if( f_pszSection && strlen( f_pszSection ) > cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH )
	{
		if( f_pszData && f_pszDefault && ( f_lValueMax > 0 ) )
		{
			strncpy( f_pszData, f_pszDefault, f_lValueMax );
			f_pszData[f_lValueMax-1] = 0;
		}
		return( 0 );
	}

	/*  Look if want all section name */
	if( f_pszSection == NULL  )
	{
		if( !f_pszData || ( f_lValueMax <= 0 ) )
			return( -1 );

		*f_pszData = 0;

		/* Should be while( cOCT_TRUE) but avoid compiler warning */
		while( f_pszData )
		{
			f_pszSectionFound = FindPrivateSection( NULL, szSection, pszTemp );
			if( !f_pszSectionFound )
				return( lValue );

			/*  Find mMAX */
			if( (lValue + (tOCT_INT32)strlen( szSection ) + 2 ) > f_lValueMax )
			{
				return( -1 );
			}

			OctAdfUtilStrTrim(szSection );
			strcat( szSection, " " );
			strcat( f_pszData, szSection );
			lValue = strlen( f_pszData );

			pszTemp = f_pszSectionFound;
		}
	}

	/*  Move to start of section */
	f_pszSectionFound = FindPrivateSection( f_pszSection, szSection, pszTemp );
	if( !f_pszSectionFound )	/*  Can't find it */
	{
		if( f_pszData && f_pszDefault && ( f_lValueMax > 0 ) )
			strncpy( f_pszData, f_pszDefault, f_lValueMax );
		return( -1 );
	}


	/*  Ask of all section content lenght */
	if( !f_pszItemName  && !f_pszData )
	{
		tOCT_INT32 lSectionLen;

		/* Found start of next section definition */
		tOCT_PSZ pszEndOfSection = FindStartNextSection( f_pszSectionFound );

		if( !pszEndOfSection )
			lSectionLen = strlen( f_pszSectionFound );
		else
			lSectionLen = mMAX( 0, ( pszEndOfSection - f_pszSectionFound ) );

		/*  Section len if section complete */
		return( lSectionLen );

	}

	/*  Ask for key len */
	if( f_pszItemName && !f_pszData )
	{
		tOCT_PSZ pszEndOfKey;

		pszStartOfKeyValue = FindPrivateKey( f_pszItemName, NULL, 0, f_pszSectionFound, NULL, cOCT_FALSE);
		if( pszStartOfKeyValue == NULL )
			return( 0 );

		/*  Get start of next key name */
		FindStartNextKey( NULL, pszStartOfKeyValue, &pszEndOfKey  );

		if( *pszEndOfKey )
			return( mMAX( 0, (pszEndOfKey - pszStartOfKeyValue) - 1 ) );
		else
			return( mMAX( 0, (pszEndOfKey - pszStartOfKeyValue) ) );

	}

	/*  Need this param */
	if( !f_pszData || ( f_lValueMax <= 0 ) )
		return( -1 );


	/*  Ask of all key name */
    if( f_pszItemName == cOCTADF_UTIL_CONFIG_ALL_SECTION_ITEM_NAME )
	{
		tOCT_CHAR szKeyValue[cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH+1];

		*f_pszData = 0;

		/*  Set to start of section */
		pszTemp = f_pszSectionFound;

		/* Should be while(cOCT_TRUE) but avoid compiler warning */
		while( f_pszItemName )
		{
			tOCT_PSZ pszItemNameFound;

			/*  Get next key name */
			pszItemNameFound = FindPrivateKey( NULL, szKeyValue, cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH, pszTemp, NULL, cOCT_FALSE );

			if( !pszItemNameFound )
				return( lValue );

			/*  Find mMAX */
			if( (lValue + (tOCT_INT32)strlen( szKeyValue ) + 2 ) > f_lValueMax )
			{
				return( -1 );
			}

			OctAdfUtilStrTrim(szKeyValue );
			strcat( szKeyValue, " " );
			strcat( f_pszData, szKeyValue );
			lValue = strlen( f_pszData );

			/*  Set to start of key content; */
			pszTemp = pszItemNameFound;

		}
	}

	/*  Ask of all section content */
	if( f_pszItemName == NULL )
	{
		tOCT_INT32 lSectionLen;
		tOCT_INT32 lLen;

		/* Found start of next section definition */
		tOCT_PSZ pszEndOfSection = FindStartNextSection( f_pszSectionFound );

		if( !pszEndOfSection )
			lSectionLen = strlen( f_pszSectionFound );
		else
			lSectionLen = pszEndOfSection - f_pszSectionFound;

		lLen = mMIN( lSectionLen, f_lValueMax-1 );

		strncpy( f_pszData, f_pszSectionFound, lLen );
		
		*(f_pszData+lLen)=0;

		OctAdfUtilStrRMPendingCrLf(f_pszData);

		/*  Section len if section complete */
		return( ( lLen == lSectionLen ) ? lLen : -1 );

	}

	{
		tOCT_BOOL32 fComplete;

		/*  Ask for key content */
		pszStartOfKeyValue = FindPrivateKey( f_pszItemName, f_pszData, f_lValueMax, f_pszSectionFound, &fComplete, cOCT_FALSE );
		if( pszStartOfKeyValue )
			OctAdfUtilStrRMPendingCrLf( f_pszData );
		else
		{
			/*  Put default */
			if( !f_pszDefault )
				strcpy( f_pszData, "" );
			else
			{
				strncpy( f_pszData, f_pszDefault, f_lValueMax );
				fComplete = cOCT_TRUE;
			}
		}
		/*  Value len if complete */
		return( fComplete ?  strlen( f_pszData ) : -1 );
	}

}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetAllSectionName
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCT_PSZ pszDelemiter
|   tOCT_INT32 f_lValueMax
|   tOCT_PSZ f_pszData
|   tOCT_PSZ f_pszConfigBuffer
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilConfigGetAllSectionName( tOCT_PSZ f_pszDelemiter, tOCT_PSZ f_pszData, 
										   tOCT_INT32 f_lValueMax, tOCT_PSZ f_pszConfigBuffer )
{
	tOCT_CHAR szSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];
	tOCT_PSZ pszDelaultDel = " ";
	tOCT_PSZ pszDelimiter;
	tOCT_PSZ pszTemp = f_pszConfigBuffer;
	tOCT_INT32 lValue = 0;
	tOCT_INT32 lDelimiter;
	tOCT_PSZ f_pszSectionFound;

	if( !f_pszConfigBuffer )
		return( -1 );

	/*  Assign delemiter */
	if( !f_pszDelemiter )
		pszDelimiter = pszDelaultDel;
	else
		pszDelimiter = f_pszDelemiter;

	lDelimiter = strlen( pszDelimiter );

	if( f_pszData )
		*f_pszData = 0;

	/* Should be while(cOCT_TRUE) but avoid compiler warning */
	while( f_pszConfigBuffer )
	{
		f_pszSectionFound = FindPrivateSection( NULL, szSection, pszTemp );
		if( !f_pszSectionFound )
			return( lValue );

		/*   */
		OctAdfUtilStrTrim(szSection );

		/*  Calc size */
		lValue += ( lDelimiter + strlen( szSection ) + 1 );

		/*  May only need length */
		if( f_pszData )
		{
			/*  Chck if big enough */
			if( lValue  > f_lValueMax )
			{
				return( -1 );
			}

			/*  Add new section */
			strcat( f_pszData, szSection );

			/*  Add delimiter */
			strcat( f_pszData, pszDelimiter );
		}

		/*  Get for next */
		pszTemp = f_pszSectionFound;

	}
	return cOCTVC1_RC_OK;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetFirstSection
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx
|   tOCT_PSZ f_pszSection
|   tOCT_PSZ f_pszData
|   tOCT_INT32 f_lValueMax
|   tOCT_PSZ f_pszConfigBuffer
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetFirstSection( tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, tOCT_PSZ f_pszSection, 
													tOCT_PSZ f_pszData, tOCT_INT32 f_lValueMax, tOCT_PSZ f_pszConfigBuffer )
{
	tOCT_PSZ pszTemp = f_pszConfigBuffer;
	tOCT_PSZ pszEndOfSection;

	/*  valid param */
	if( !f_pConfCtx || !f_pszConfigBuffer || (f_pszData!=NULL && f_lValueMax==0) )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	/*  Clear context */
	memset( f_pConfCtx, 0, sizeof( tOCTADF_UTIL_CONFIG_CTX ) );

	/*  Set contex init */
	f_pConfCtx->pszConfigBuffer = f_pszConfigBuffer;
	f_pConfCtx->pszCurrentPos = f_pszConfigBuffer;

	/*  Set config len */
	f_pConfCtx->lConfigLength = strlen( f_pConfCtx->pszConfigBuffer );
	
	/*  Valid section name len */
	if( f_pszSection && strlen( f_pszSection ) > cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH )
	{
		return( cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG );
	}

	/*  Keep the target section */
	if( f_pszSection )
		strcpy( f_pConfCtx->szTargetSection, f_pszSection );

	/*  Position to first section */
	f_pConfCtx->pszStartOfSection = FindPrivateSection( f_pszSection, f_pConfCtx->szCurrSection, pszTemp );

	/*  Can't find it */
	if( !f_pConfCtx->pszStartOfSection )	
	{
		return cOCTVC1_GENERIC_RC_NOT_FOUND;
	}

	/*  Trim section name */
	OctAdfUtilStrTrim( f_pConfCtx->szCurrSection );

	/*  Find section length */
	pszEndOfSection = FindStartNextSection( f_pConfCtx->pszStartOfSection );

	if( !pszEndOfSection )
		f_pConfCtx->lCurrSectionLength = strlen( f_pConfCtx->pszStartOfSection );
	else
		f_pConfCtx->lCurrSectionLength = mMAX( 0, ( pszEndOfSection - f_pConfCtx->pszStartOfSection ) -1 );

	/*  Set current position */
	f_pConfCtx->pszCurrentPos = f_pConfCtx->pszStartOfSection;

	/*  Chck if ask for section content */
	if( f_pszData )
	{
		if( f_lValueMax < f_pConfCtx->lCurrSectionLength )
			return cOCTADF_UTIL_RC_BUFFER_TOO_SMALL;

		strncpy( f_pszData, f_pConfCtx->pszStartOfSection, f_pConfCtx->lCurrSectionLength );
		*(f_pszData+f_pConfCtx->lCurrSectionLength-1)=0;

		/*  Remove pending CrLf */
		OctAdfUtilStrRMPendingCrLf(f_pszData);
		
	}
	return cOCTVC1_RC_OK;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetNextSection
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx
|   tOCT_PSZ f_pszData
|   tOCT_INT32 f_lValueMax
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetNextSection( 
				tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
				tOCT_PSZ f_pszData, 
				tOCT_INT32 f_lValueMax )
{

	tOCT_PSZ pszStartOfSect;
	tOCT_PSZ pszEndOfSection;
	tOCT_PSZ pszSection;
	tOCT_CHAR szCurrSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];

	/*  valid param */
	if( !f_pConfCtx )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	/*  Valid context */
	if( ( f_pConfCtx->pszStartOfSection < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszCurrentPos < f_pConfCtx->pszConfigBuffer )  ||
		( f_pConfCtx->pszStartOfSection > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) ||
		( f_pConfCtx->pszCurrentPos > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) )
		return cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED;

	/*  valid target section */
	if( f_pConfCtx->szTargetSection[0] == 0 )
		pszSection = NULL;
	else
		pszSection = f_pConfCtx->szTargetSection;

	/*  Position to next section */
	pszStartOfSect = FindPrivateSection( pszSection, szCurrSection, f_pConfCtx->pszStartOfSection );

	/*  Can't find it */
	if( !pszStartOfSect )	
	{
		return cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG;
	}

	/*  Trim section name */
	OctAdfUtilStrTrim( szCurrSection );
	strcpy( f_pConfCtx->szCurrSection, szCurrSection );
	f_pConfCtx->pszStartOfSection = pszStartOfSect;

	/*  Find section length */
	pszEndOfSection = FindStartNextSection( f_pConfCtx->pszStartOfSection );

	if( !pszEndOfSection )
		f_pConfCtx->lCurrSectionLength = strlen( f_pConfCtx->pszStartOfSection );
	else
		f_pConfCtx->lCurrSectionLength = mMAX( 0, ( pszEndOfSection - f_pConfCtx->pszStartOfSection ) -1 );

	/*  Set current position */
	f_pConfCtx->pszCurrentPos = f_pConfCtx->pszStartOfSection;

	/*  Chck if ask for section content */
	if( f_pszData )
	{
		if( f_lValueMax < f_pConfCtx->lCurrSectionLength )
			return cOCTADF_UTIL_RC_BUFFER_TOO_SMALL;

		strncpy( f_pszData, f_pConfCtx->pszStartOfSection, f_pConfCtx->lCurrSectionLength );
		*(f_pszData+f_pConfCtx->lCurrSectionLength-1)=0;

		/*  Remove pending CrLf */
		OctAdfUtilStrRMPendingCrLf(f_pszData);
		
	}
	return cOCTVC1_RC_OK;

}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetFirstItem
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx
|   tOCT_PSZ f_pszItemName
|   tOCT_PSZ f_pszData
|   tOCT_INT32 f_lValueMax
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetFirstItem( tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, tOCT_PSZ f_pszItemName, 
												 tOCT_PSZ f_pszData, tOCT_INT32 f_lValueMax )
{
	tOCT_PSZ pszEndOfKey;
	tOCT_PSZ pszCurrentPos;

	/*  valid param */
	if( !f_pConfCtx )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	/*  Valid context */
	if( ( f_pConfCtx->pszStartOfSection < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszCurrentPos < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszStartOfSection > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) ||
		( f_pConfCtx->pszCurrentPos > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) )
		return cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED;

	
	/*  Find key len */
	if( f_pszItemName )
	{
		/*  Keep the target item */
		strcpy( f_pConfCtx->szTargetItem, f_pszItemName );

		/*  Get start of key value */
		pszCurrentPos = FindPrivateKey( f_pszItemName, NULL, 0, f_pConfCtx->pszStartOfSection, NULL, 
									!f_pConfCtx->fCaseInsensitive );

		/*  Set current item */
		if( pszCurrentPos )
			strcpy( f_pConfCtx->szCurrItemName, f_pszItemName );
	}
	else
	{
		f_pConfCtx->szTargetItem[0] = 0;

		/*  Get start of next key name */
		pszCurrentPos = FindStartNextKey( f_pConfCtx->pszStartOfSection, f_pConfCtx->pszStartOfSection, NULL );

		if( pszCurrentPos )
		{
			/*  Copy up to = */
			tOCT_INT32 lEndOfKey = OctAdfUtilStrFindNextChar( pszCurrentPos, '=' );
			tOCT_INT32 lLen = mMIN( lEndOfKey, cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH );

			strncpy( f_pConfCtx->szCurrItemName, pszCurrentPos, lLen );
			*(f_pConfCtx->szCurrItemName+lLen) = 0;

			OctAdfUtilStrTrim( f_pConfCtx->szCurrItemName );

			/*  Set to start of key value */
			pszCurrentPos = pszCurrentPos+lEndOfKey+1;
		}
	}

	/*  Get start of item value */
	if( pszCurrentPos == NULL )
		return( cOCTVC1_GENERIC_RC_NOT_FOUND );

	/*  Set current pos */
	f_pConfCtx->pszCurrentPos = pszCurrentPos;

	/*  Find item len */
	FindStartNextKey( NULL, f_pConfCtx->pszCurrentPos, &pszEndOfKey );

	/*  Calc item length */
	/* pszEndOfKey may contain /n/t/n/r...*/
	// f_pConfCtx->lCurrItemLength = mMAX( 0, (pszEndOfKey - f_pConfCtx->pszCurrentPos) );
	f_pConfCtx->lCurrItemLength = OctAdfUtilStrGetLen(f_pConfCtx->pszCurrentPos);

	/*  Chck if ask for item length */
	if( f_pszData )
	{
		if( f_lValueMax < f_pConfCtx->lCurrItemLength )
			return cOCTADF_UTIL_RC_BUFFER_TOO_SMALL;
		
		strncpy( f_pszData, f_pConfCtx->pszCurrentPos, f_pConfCtx->lCurrItemLength );
		*(f_pszData+f_pConfCtx->lCurrItemLength)=0;

#if 0
		/*  Remove pending CrLf */
		OctAdfUtilStrRMPendingCrLf(f_pszData);

		/*  Set real length */
		f_pConfCtx->lCurrItemLength = strlen( f_pszData )+1;
#endif

	}

	return cOCTVC1_RC_OK;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetNextItem
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx
|   tOCT_PSZ f_pszData
|   tOCT_INT32 f_lValueMax
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetNextItem( 
				tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
				tOCT_PSZ f_pszData, 
				tOCT_INT32 f_lValueMax )
{
	tOCT_PSZ pszEndOfKey;
	tOCT_PSZ pszCurrentPos;
	tOCT_PSZ pszItem;

	/*  valid param */
	if( !f_pConfCtx )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	/*  Valid context */
	if( ( f_pConfCtx->pszStartOfSection < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszCurrentPos < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszStartOfSection > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) ||
		( f_pConfCtx->pszCurrentPos > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) )
		return cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED;

	
	/*  valid target item */
	if( f_pConfCtx->szTargetItem[0] == 0 )
		pszItem = NULL;
	else
		pszItem = f_pConfCtx->szTargetItem;

	/*  Find key len */
	if( pszItem )
	{
		/*  Get start of key value */
		pszCurrentPos = FindPrivateKey( pszItem, NULL, 0, f_pConfCtx->pszCurrentPos, NULL, !f_pConfCtx->fCaseInsensitive );
	}
	else
	{
		/*  Get start of next key name */
		pszCurrentPos = FindStartNextKey( f_pConfCtx->pszStartOfSection, f_pConfCtx->pszCurrentPos, NULL );

		if( pszCurrentPos )
		{
			/*  Copy up to = */
			tOCT_INT32 lEndOfKey = OctAdfUtilStrFindNextChar( pszCurrentPos, '=' );
			tOCT_INT32 lLen = mMIN( lEndOfKey, cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH );

			strncpy( f_pConfCtx->szCurrItemName, pszCurrentPos, lLen );
			*(f_pConfCtx->szCurrItemName+lLen) = 0;

			OctAdfUtilStrTrim( f_pConfCtx->szCurrItemName );

			/*  Set to start of key value */
			pszCurrentPos = pszCurrentPos+lEndOfKey+1;
		}
	}

	/*  Get start of item value */
	if( pszCurrentPos == NULL )
		return( cOCTVC1_GENERIC_RC_NOT_FOUND );

	/*  Set current pos */
	f_pConfCtx->pszCurrentPos = pszCurrentPos;

	/*  Find item len */
	FindStartNextKey( NULL, f_pConfCtx->pszCurrentPos, &pszEndOfKey );

	/*  Calc item length */
	f_pConfCtx->lCurrItemLength = mMAX( 0, (pszEndOfKey - f_pConfCtx->pszCurrentPos) );

	/*  Chck if ask for item length */
	if( f_pszData )
	{
		if( f_lValueMax < f_pConfCtx->lCurrItemLength )
			return cOCTADF_UTIL_RC_BUFFER_TOO_SMALL;
		
		strncpy( f_pszData, f_pConfCtx->pszCurrentPos, f_pConfCtx->lCurrItemLength );
		*(f_pszData+f_pConfCtx->lCurrItemLength)=0;

		/*  Remove pending CrLf */
		OctAdfUtilStrRMPendingCrLf(f_pszData);

		/*  Set real length */
		f_pConfCtx->lCurrItemLength = strlen( f_pszData )+1;
	}

	return cOCTVC1_RC_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetItemCount
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|   tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx
|	tOCT_PSZ f_pszItemName
|	tOCT_UINT32 * f_pulItemCount
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetItemCount( 
				tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
				tOCT_PSZ f_pszItemName, 
				tOCT_UINT32 * f_pulItemCount )
{

	tOCT_PSZ pszEndOfKey;
	tOCT_PSZ pszCurrentPos;
	tOCT_UINT32 ulCount = 0;

	/*  valid param */
	if( !f_pConfCtx || !f_pulItemCount )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	/*  Valid context */
	if( ( f_pConfCtx->pszStartOfSection < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszCurrentPos < f_pConfCtx->pszConfigBuffer ) ||
		( f_pConfCtx->pszStartOfSection > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) ||
		( f_pConfCtx->pszCurrentPos > ( f_pConfCtx->pszConfigBuffer + f_pConfCtx->lConfigLength ) ) )
		return cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED;

	/*  Find key len */
	if( f_pszItemName )
	{
		/*  Get start of key value */
		pszCurrentPos = FindPrivateKey( f_pszItemName, NULL, 0, f_pConfCtx->pszStartOfSection, NULL, !f_pConfCtx->fCaseInsensitive );
		while( pszCurrentPos )
		{
			ulCount++;

			/* Move to end of item name */
			pszCurrentPos = FindPrivateKey( f_pszItemName, NULL, 0, pszCurrentPos, NULL, !f_pConfCtx->fCaseInsensitive );
		}

	}
	else
	{
		/*  Get start of next key name */
		pszCurrentPos = FindStartNextKey( f_pConfCtx->pszStartOfSection, 
							f_pConfCtx->pszStartOfSection, &pszEndOfKey );

		while( pszCurrentPos )
		{
			ulCount++;

			/* Move to end of item name */
			pszCurrentPos = pszEndOfKey + 1;

			pszCurrentPos = FindStartNextKey( NULL, pszCurrentPos, &pszEndOfKey );

			/* chck if got a comment */
			if( !pszCurrentPos && pszEndOfKey && ( *pszEndOfKey == '#' ))
			{
				ulCount--;
				pszCurrentPos = pszEndOfKey + 1;

			}
		}
	}

	*f_pulItemCount = ulCount;

	return ulCount ? cOCTVC1_RC_OK : cOCTVC1_GENERIC_RC_NOT_FOUND;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetItemList
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|	tOCTADF_UTIL_CONFIG_CTX *				f_pConfCtx
|	tOCTADF_UTIL_CONFIG_ITEM_DECL *		f_aConfItemDecl
|	tOCTADF_UTIL_CONFIG_ITEM_DECL * *	f_ppErrorItem 
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetItemList( 
	tOCTADF_UTIL_CONFIG_CTX *				f_pConfCtx,
	tOCTADF_UTIL_CONFIG_ITEM_DECL *		f_aConfItemDecl,
	tOCTADF_UTIL_CONFIG_ITEM_DECL * *	f_ppErrorItem )
{
	tOCT_UINT32						ulRc = cOCTVC1_RC_OK;
	tOCTADF_UTIL_CONFIG_ITEM_DECL *	pItemDecl;
	tOCT_CHAR						szBuffer[cOCTADF_UTIL_CONFIG_MAX_ITEM_CONTENT_LENGTH];

	/*  valid param */
	if( !f_pConfCtx || !f_aConfItemDecl )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	if ( f_ppErrorItem )
		*f_ppErrorItem = NULL;

	pItemDecl = f_aConfItemDecl;

	while( pItemDecl && pItemDecl->pszItemName && cOCTVC1_RC_OK == ulRc )
	{
		/* provision errored item in case of failure */
		if ( f_ppErrorItem )
			*f_ppErrorItem = pItemDecl;

		if ( !pItemDecl->pItemData )
		{
			return cOCTVC1_GENERIC_RC_BAD_PARAM;
		}

		szBuffer[0] = 0x0;
		/* get item */
		ulRc = OctAdfUtilConfigGetFirstItem(
							f_pConfCtx,
							pItemDecl->pszItemName,
							szBuffer,
							sizeof(szBuffer) );

		/* did we find something ? */
		if ( cOCTVC1_GENERIC_RC_NOT_FOUND == ulRc 
			|| 
			(cOCTVC1_RC_OK == ulRc 
			&&
			0 == strlen( szBuffer )) )
		{
			/* Is this item mandatory ? */
			if ( !pItemDecl->fMandatory )
			{
				/* no, so convert to OK */
				ulRc = cOCTVC1_RC_OK;
			}
			else
			{
				ulRc = cOCTADF_UTIL_CONFIG_RC_MANDATORY_ENTRY_MISSING;
			}
			if ( pItemDecl->fRepeat )
			{
				if ( pItemDecl->pulRepeatArrayElementCount )
					*pItemDecl->pulRepeatArrayElementCount = 0;
			}
		}
		else if ( cOCTVC1_RC_OK == ulRc )
		{
			tOCT_BOOL32	fRepeat;
			void *	pItemData;
			tOCT_UINT32	ulItemCount = 0;

			/* Remove space padding */
			OctAdfUtilStrTrim(szBuffer);

			pItemData	= pItemDecl->pItemData;
			if ( pItemDecl->fRepeat 
				&& 
				(!pItemDecl->pulRepeatArrayElementCount
				||
				!(*pItemDecl->pulRepeatArrayElementCount)) )
			{
				return cOCTVC1_GENERIC_RC_BAD_PARAM;
			}
			fRepeat		= pItemDecl->fRepeat;
			
			do
			{
				tOCT_PSZ pszFault;

				/* Chck if include # in middle of item */
				if( !( pItemDecl->ulItemType & cOCTADF_UTIL_CONFIG_ITEM_FLAVOR_INCLUDE_COMMENT ) )
				{
					tOCT_PSZ pszTemp = strchr( szBuffer, '#' );
					if( pszTemp )
					{
						/* Chck if previous char is ' ' */
						do
						{
							if( isspace(*(pszTemp-1)) )
							{
								*(pszTemp-1) = 0;
								OctAdfUtilStrTrimRight( szBuffer );
								break;
							}

						}while( ( pszTemp = strchr( pszTemp+1, '#' ) ) != NULL );
					}
				}

				/* switch type and convert to destination */
				switch( pItemDecl->ulItemType & cOCTADF_UTIL_CONFIG_ITEM_TYPE_MASK )
				{
					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_INTX:
						{
							tOCT_INT32 lData;
							
							lData = (tOCT_INT32) strtol( szBuffer, &pszFault, 10 );
							if( ( *pszFault != '\n' ) && ( *pszFault != '\r' ) && ( *pszFault != '\t' ) && ( *pszFault != '\0' ) )
								return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;

							switch( pItemDecl->ulItemDataSize )
							{
								case sizeof( tOCT_INT32 ):
									*((tOCT_INT32 *)pItemData) = lData;
									break;

								case sizeof( tOCT_INT16 ):
									if( ( lData > 0xFFFF ) ||
										( (int)lData < (int)(-32767) ) )
										return cOCTADF_UTIL_CONFIG_RC_TRUNC_VALUE;
									*((tOCT_INT16 *)pItemData) = (tOCT_INT16)lData;
									break;

								case sizeof( tOCT_INT8 ):

									if( ( lData > 0xFF ) ||
										( (int)lData < (int)(-127) ) )
										return cOCTADF_UTIL_CONFIG_RC_TRUNC_VALUE;

									*((tOCT_INT8 *)pItemData) = (tOCT_INT8)lData;
									break;

								default:
									return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;
							}
						}
						break;
						
					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINTX:
						{
							tOCT_UINT32 ulData;
							
							ulData = (tOCT_UINT32)strtoul( szBuffer, &pszFault, 10 );
							if( ( *pszFault != '\n' ) && ( *pszFault != '\r' ) && ( *pszFault != '\t' ) && ( *pszFault != '\0' ) )
								return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;

							switch( pItemDecl->ulItemDataSize )
							{
								case sizeof( tOCT_UINT32 ):
									*((tOCT_UINT32 *)pItemData) = ulData;
									break;

								case sizeof( tOCT_UINT16 ):
									if( ulData > 0xFFFF )
										return cOCTADF_UTIL_CONFIG_RC_TRUNC_VALUE;
									*((tOCT_UINT16 *)pItemData) = (tOCT_UINT16)ulData;
									break;

								case sizeof( tOCT_UINT8 ):

									if( ulData > 0xFF )
										return cOCTADF_UTIL_CONFIG_RC_TRUNC_VALUE;

									*((tOCT_UINT8 *)pItemData) = (tOCT_UINT8)ulData;
									break;

								default:
									return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;
							}
						}
						break;
						
					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINT32		:
						{
							*((tOCT_UINT32 *)pItemData) = (tOCT_UINT32)strtoul( szBuffer, &pszFault, 10 );
							if( ( *pszFault != '\n' ) && ( *pszFault != '\r' ) && ( *pszFault != '\0' ) )
								return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;

						}
						break;

					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINT32_HEX	:
						if ( 0 > sscanf( szBuffer,"0x%x", (tOCT_UINT32 *)pItemData ) )
							return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;
						break;
					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_STRING		:
						if ( strlen(szBuffer) > pItemDecl->ulItemDataSize )
							return cOCTADF_UTIL_RC_BUFFER_TOO_SMALL;
						strcpy(pItemData, szBuffer );
						break;
					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_BOOL			:
						{
							tOCT_BOOL32 fValue;

							OctAdfUtilStrUpr(szBuffer);
							if ( 0 == strcmp(szBuffer, "TRUE") )
							{
								fValue = cOCT_TRUE;
							}
							else
							{
								if ( 0 == strcmp( szBuffer, "FALSE") )
								{
									fValue = cOCT_FALSE;
								}
								else
								{
									return cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE;
								}
							}

							switch( pItemDecl->ulItemDataSize )
							{
								case sizeof( tOCT_UINT32 ):
									*((tOCT_UINT32 *)pItemData) = fValue;
									break;

								case sizeof( tOCT_UINT16 ):
									*((tOCT_UINT16 *)pItemData) = (tOCT_UINT16)fValue;
									break;

								case sizeof( tOCT_UINT8 ):
									*((tOCT_UINT8 *)pItemData) = (tOCT_UINT8)fValue;
									break;

								default:
									*((tOCT_BOOL32 *)pItemData) = fValue;
							}
							break;
						}
					case cOCTADF_UTIL_CONFIG_ITEM_TYPE_USER			:
						if ( !pItemDecl->pfnItemDecode )
							return cOCTVC1_GENERIC_RC_BAD_PARAM;
						ulRc = pItemDecl->pfnItemDecode(
												szBuffer,
												pItemDecl->ulItemDataSize,
												pItemData );
						break;
				}

				if ( cOCTVC1_RC_OK == ulRc && fRepeat )
				{
					ulItemCount++;

					pItemData = (tOCT_UINT8 *)pItemData + pItemDecl->ulItemDataSize;
					/* get next item */
					ulRc = OctAdfUtilConfigGetNextItem(
										f_pConfCtx,
										szBuffer,
										sizeof(szBuffer) );

					if ( cOCTVC1_RC_OK != ulRc )
					{
						*pItemDecl->pulRepeatArrayElementCount = ulItemCount;
						fRepeat = cOCT_FALSE;
						if ( cOCTVC1_GENERIC_RC_NOT_FOUND == ulRc )
							ulRc = cOCTVC1_RC_OK;
					}
					else
					{
						if ( ulItemCount >= *pItemDecl->pulRepeatArrayElementCount )
						{
							/* not enougth space */
							return cOCTADF_UTIL_CONFIG_RC_TOO_MANY_OBJECT;
						}
					}

				}

			} while( cOCTVC1_RC_OK == ulRc && fRepeat );
		}
		/* move to next item decl */
		pItemDecl++;
	};

	if ( cOCTVC1_RC_OK == ulRc && f_ppErrorItem )
		*f_ppErrorItem = NULL;

	return ulRc;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigExtractMasterSection
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|	tOCT_PSZ				f_pszMasterSection
|	tOCT_INT32			f_lValueMax
|	tOCT_PSZ				f_pszMasterSectionName
|	tOCT_PSZ				f_pszBuffer 
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigExtractMasterSection( 
	tOCT_PSZ				f_pszMasterSection, 
	tOCT_INT32			f_lValueMax,
	tOCT_PSZ				f_pszMasterSectionName, 
	tOCT_PSZ				f_pszBuffer )
{
	tOCT_CHAR		szMasterSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH];
	tOCT_UINT32		ulRc;
	tOCT_PSZ			pszMasterSectionStart = NULL;
	tOCT_PSZ			pszMasterSectionEnd = NULL;
	/*  valid param */
	if( !f_pszMasterSection || !f_pszMasterSectionName || !f_pszBuffer || !f_lValueMax )
		return cOCTVC1_GENERIC_RC_BAD_PARAM;

	if ( strlen(f_pszMasterSectionName) + 7  > cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH )
		return cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG;

	ulRc = cOCTVC1_GENERIC_RC_NOT_FOUND;

	/* Build master section begin */
	sprintf( szMasterSection, "%s_BEGIN", f_pszMasterSectionName );

	/* try to locate begin of master section */
	pszMasterSectionStart = FindPrivateSection( 
								szMasterSection,
								NULL,
								f_pszBuffer );

	/* Find it ? */
	if ( pszMasterSectionStart )
	{
		/* Yes, so build master section end */
		sprintf( szMasterSection, "%s_END", f_pszMasterSectionName );

		/* try to locate end of master section */
		pszMasterSectionEnd = FindPrivateSection( 
									szMasterSection,
									NULL,
									f_pszBuffer );
		if ( pszMasterSectionEnd )
		{
			tOCT_INT32		lMasterSectionSize;
			ulRc = cOCTADF_UTIL_RC_BUFFER_TOO_SMALL;
			/* remove section and calculate buffer size */
			lMasterSectionSize = (pszMasterSectionEnd - pszMasterSectionStart) - 2 - strlen( szMasterSection );

			if ( lMasterSectionSize <= f_lValueMax)
			{
				/* copy master section to dest buffer */
				memcpy( f_pszMasterSection, 
								pszMasterSectionStart,
								lMasterSectionSize );

				f_pszMasterSection[lMasterSectionSize] = 0x0;
				ulRc = cOCTVC1_RC_OK;
			}
		}
	}

	return ulRc;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
|
|
|	Function:		OctAdfUtilConfigGetSectionList
|
|	Description:    
|
|   Return type:    tOCT_UINT32 
|
|  ----------------------------------------------------------------------------------------
|  |	Argument		|				Description
|  ----------------------------------------------------------------------------------------
|	f_pConfCtx				Current Section context
|	f_pszBuffer				Config content
|	f_pszMasterSection		Work buffer for current master section
|	f_aConfSecDecl			Section declaration list.
|
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetSectionList( 
	tOCTADF_UTIL_CONFIG_CTX *				f_pConfCtx,
	tOCT_PSZ								f_pszBuffer,
	tOCT_PSZ								f_pszMasterSection,
	tOCT_UINT32								f_ulMasterSectionMaxSize,
	tOCTADF_UTIL_CONFIG_MASTER_SEC_DECL *	f_aConfSecDecl )
{	
	tOCT_UINT32 ulRc                 = cOCTVC1_RC_OK;
	tOCT_UINT32 ulMasterSectionIdx   = 0;
	tOCT_UINT32 ulSectionRepeatCount = 0;
	
	tOCTADF_UTIL_CONFIG_SEC_DECL * pSection = NULL;
	
	while( NULL != f_aConfSecDecl[ulMasterSectionIdx].szMasterSecName )
	{
		ulRc = OctAdfUtilConfigExtractMasterSection( 
			f_pszMasterSection, 
			f_ulMasterSectionMaxSize, 
			f_aConfSecDecl[ulMasterSectionIdx].szMasterSecName,
			f_pszBuffer );
		
		if( cOCTVC1_RC_OK != ulRc )
		{
			// All master sections are mandatory
			break;
		}
		
		pSection = &f_aConfSecDecl[ulMasterSectionIdx].pSections[0];
		while( NULL != pSection->pszSecName )	
		{
			ulSectionRepeatCount = 0;
			ulRc = OctAdfUtilConfigGetFirstSection( 
				f_pConfCtx, pSection->pszSecName, NULL, 0, f_pszMasterSection );

			if( cOCTVC1_RC_OK != ulRc )
			{
				if( cOCTVC1_GENERIC_RC_NOT_FOUND == ulRc )
				{
					if( cOCT_FALSE == pSection->fMandatory )
					{
						ulRc = cOCTVC1_RC_OK;
						pSection++;
						continue;
					}
				}
				break;
			}
				
			do
			{	
				
				ulRc = pSection->pCallback(f_pConfCtx, pSection->pUserInfo);
				if( cOCTVC1_RC_OK != ulRc )
				{
					break;
				}
			
				if( ulSectionRepeatCount < pSection->ulRepeatMaxCount )
				{
					ulRc = OctAdfUtilConfigGetNextSection( f_pConfCtx, NULL, 0 );
					if( cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG == ulRc )
					{
						ulRc = cOCTVC1_RC_OK;
						break;
					}
					
					ulSectionRepeatCount++;
				}
				else
				{
					break;
				}
				
			} while( 1 );
			
			if( cOCTVC1_RC_OK != ulRc )
			{
				break;
			}
			
			pSection++;
		}
		
		if( cOCTVC1_RC_OK != ulRc )
		{
			break;
		}
		
		ulMasterSectionIdx++;
	}
	
	return ulRc;
}

