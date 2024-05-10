/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octadf_util_config.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-04.10.01-B3387 (2018/01/29)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef __OCTADF_UTIL_CONFIG_H__
#define __OCTADF_UTIL_CONFIG_H__

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

#include "octdev_types.h"

typedef tOCT_INT8		tOCT_CHAR;
typedef tOCT_INT8 * 	tOCT_PSZ;

/*****************************  DEFINES  *************************************/
/*----------------------------------------------------------------------------
	Config file
----------------------------------------------------------------------------*/
#define cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH		(128)
#define cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH			(128)
#define cOCTADF_UTIL_CONFIG_MAX_ITEM_CONTENT_LENGTH		(512)

#define cOCTADF_UTIL_CONFIG_ALL_SECTION_NAME			( (tOCT_PSZ)NULL )
#define cOCTADF_UTIL_CONFIG_ALL_SECTION_ITEM_NAME		( (tOCT_PSZ)-1 ) 
#define cOCTADF_UTIL_CONFIG_ALL_SECTION_ITEM_CONTENT	( (tOCT_PSZ)NULL )
#define OADF_APIENTRY				

#define UTIL_RC_BASE 0xBBBB
#define cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG					( 0x100 | UTIL_RC_BASE )
#define cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED				( 0x101 | UTIL_RC_BASE )
#define cOCTADF_UTIL_CONFIG_RC_MANDATORY_ENTRY_MISSING		( 0x102 | UTIL_RC_BASE )
#define cOCTADF_UTIL_CONFIG_RC_INVALID_ENTRY_VALUE			( 0x103 | UTIL_RC_BASE )
#define cOCTADF_UTIL_CONFIG_RC_TRUNC_VALUE					( 0x104 | UTIL_RC_BASE )
#define cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG				( 0x105 | UTIL_RC_BASE )
#define cOCTADF_UTIL_CONFIG_RC_TOO_MANY_OBJECT				( 0x106 | UTIL_RC_BASE )
#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL					( 0x003 | UTIL_RC_BASE )

/*--------------------------------------------------------------------------
	Characters textual definitions
----------------------------------------------------------------------------*/

#define cOCTADF_UTIL_CHAR_SPACE ' '

#define cOCTADF_UTIL_CHAR_BS	0x8

#define cOCTADF_UTIL_CHAR_DEL	0x7f

#define cOCTADF_UTIL_CHAR_CR	'\r'

#define cOCTADF_UTIL_CHAR_LF	'\n'

#define cOCTADF_UTIL_CHAR_FF	'\f'

#define cOCTADF_UTIL_CHAR_TAB	0x9

#define cOCTADF_UTIL_CHAR_ESC	0x1b

#define cOCTADF_UTIL_CHAR_WORDTOKEN		"\t\n "				/* Word separator */

#define cOCTADF_UTIL_CHAR_VALUETOKEN	"\t;[]{}:\n "		/* Value separator */

#define cOCTADF_UTIL_CHAR_STRTOKEN		"\r\n"				/* String separator */

#define cOCTADF_UTIL_CHAR_WORDFILETOKEN "\t,;.+[]{}*:\n "	/* Word separator */

#define cOCTADF_UTIL_CHAR_KBYTE			1024

#ifndef mMIN
	#define mMIN(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef mMAX
	#define mMAX(a,b) (((a) > (b)) ? (a) : (b))
#endif

/*----------------------------------------------------------------------------
	String ID
----------------------------------------------------------------------------*/

typedef struct _OCTADF_UTIL_STR_ID_
{
	tOCT_PSZ	pszString;
	tOCT_UINT32 ulId;

}tOCTADF_UTIL_STR_ID;


/************************** FUNCTION PROTOTYPES  *****************************/



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilStrUpr

Description:   Convert all character of the string to upper character

		tOCT_PSZ f_pszStr		=> String to convert
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OADF_APIENTRY OctAdfUtilStrUpr(  tOCT_PSZ f_pszStr );
	
	

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilStrLwr

Description:   Convert all character of the string to lower character

		tOCT_PSZ f_pszStr		=> String to convert
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrLwr( tOCT_PSZ f_pszStr );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilStrCenter

Description:   Center a string using padding character

		tOCT_PSZ f_pszCenter		=> Centered string
		tOCT_CHAR f_chPadChar	=> character to use for padding	
		tOCT_PSZ f_pszString		=> String to center
		tOCT_INT16 f_sMaxLen		=> Maximum output string
		
		RETURN
				TRUE;
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_BOOL32 OADF_APIENTRY OctAdfUtilStrCenter( 
				tOCT_PSZ f_pszCenter, 
				tOCT_CHAR f_chPadChar, 
				tOCT_PSZ f_pszString, 
				tOCT_INT16 f_sMaxLen );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilStrRemoveSubString

Description:   Get and remove from a string all character up to f_chEofToken or f_ulLength

		tOCT_PSZ f_pszSubString		=> SubString destination
		tOCT_PSZ f_pszString			=> String
		tOCT_CHAR f_chEofToken		=> End of substring
		tOCT_UINT32 f_ulLength			=> Max substring length
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrRemoveSubString( 
				tOCT_PSZ f_pszSubString, 
				tOCT_PSZ f_pszString, 
				tOCT_CHAR f_chEofToken, 
				tOCT_UINT32 f_ulLength );

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilStrTrimRight

Description:   Remove all space character ( ' ' ) at the right of a string

		tOCT_PSZ f_pszStr		=> String to process
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrTrimRight( tOCT_PSZ f_pszStr );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrTrim

Description: Remove all space character ( ' ' ) at the right and left of a string

		tOCT_PSZ f_pszStr		=> String to process

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrTrim( tOCT_PSZ f_pszStr );



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrTrimLeft

Description: Remove all space character ( ' ' ) at the left of a string

		tOCT_PSZ f_pszStr		=> String to process

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrTrimLeft( tOCT_PSZ f_pszStr );



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrExtractSubString

Description: Extract all characters between chStartOfSub and chEndOfSub

		tOCT_PSZ f_pszString			=> String to process
		tOCT_CHAR chStartOfSub		=> Character that start the sub string
		tOCT_CHAR chEndOfSub			=> Character that end the sub string
		tOCT_PSZ f_pszSubString		=> Output substring
		tOCT_INT16 f_sMaxLen			=> Max output len

		RETURN:
				Start of substring in f_pszString
				NULL if can't find chStartOfSub

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_CHAR * OADF_APIENTRY OctAdfUtilStrExtractSubString( 
				tOCT_PSZ f_pszString, 
				tOCT_CHAR chStartOfSub, 
				tOCT_CHAR chEndOfSub, 
				tOCT_PSZ f_pszSubString, 
				tOCT_INT16 f_sMaxLen );



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrGetLen

Description: Get string length where string end with \n or \r or null 

		tOCT_PSZ f_pszStr		=> String to process

		RETURN:
				string length

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilStrGetLen( tOCT_PSZ f_pszStr );

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrGetStrCount

Description:  Get number of string include in string where a string end with \n or \r or null 

		tOCT_PSZ f_pszStr		=> String to process

		RETURN:
				string count
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OADF_APIENTRY OctAdfUtilStrGetWordCount( 
					tOCT_PSZ f_pszStr, 
					tOCT_PSZ f_pszWordSet );

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrGetWordLen

Description:  Get first word length include in str

		tOCT_PSZ f_pszStr			=> String to process
		tOCT_PSZ f_pszWordSet		=> Word splitter
		tOCT_UINT16 f_usWordOfs			=> Word offset

		RETURN:
				word length
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrGetWordLen( 
					tOCT_PSZ f_pszStr, 
					tOCT_PSZ f_pszWordSet, 
					tOCT_UINT16 f_usWordOfs );
	


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrGetWord

Description:  Get number of word length

		tOCT_PSZ f_pszStr				=> String to process
		tOCT_PSZ f_pszWordSet			=> Word splitter
		tOCT_UINT16 f_usWordOfs		=> Word offset
		tOCT_PSZ f_pszSubString		=> Output substring
		tOCT_INT16 f_sMaxLen			=> Max output len


		RETURN:
				word length, 0 if no word match, -1 if f_pszSubString is too small
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrGetWord( 
					tOCT_PSZ f_pszStr, 
					tOCT_PSZ f_pszWordSet, 
					tOCT_UINT16 f_usWordOfs, 
					tOCT_PSZ f_pszSubString, 
					tOCT_INT16 f_sMaxLen );
								
								
								

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrGetStrId

Description:  Compare table string and return identificator 

		tOCTADF_UTIL_STR_ID * f_pStrId 

		RETURN:
				String identificator
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrGetStrId( 
				tOCTADF_UTIL_STR_ID * f_pStrId, 
				tOCT_PSZ f_pszWord );
	

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrGetIdStr

Description:  Compare table string and return identificator 

		tOCTADF_UTIL_STR_ID * f_pStrId 

		RETURN:
				Identificator string
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_CHAR * OADF_APIENTRY OctAdfUtilStrGetIdStr( 
				tOCTADF_UTIL_STR_ID * f_pStrId, 
				tOCT_UINT32 f_ulId );

		

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrISBlank

Description:  Verify if a string is empty.

		NOTE: String with all space characters will be considere empty

		tOCT_PSZ f_pszStr		=> String to process

		RETURN:
				TRUE		=> String contain nothing or only space
				FALSE		=> String is not empty
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_BOOL32 OADF_APIENTRY OctAdfUtilStrISBlank( tOCT_PSZ f_pszString );

	

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrRMPendingCrLf

Description:  Remove all \n or \r from the end of the string

		tOCT_PSZ f_pszStr		=> String to process
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrRMPendingCrLf( tOCT_PSZ f_pszString );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrtok

Description:  Find the next token in a string

		tOCT_PSZ f_pszStr			=> String to process
		tOCT_PSZ f_pszToken		=> Token to look for
		tOCT_PSZ *f_ppszNextStr	=> Next to string to process
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_CHAR * OADF_APIENTRY OctAdfUtilStrtok( 
				tOCT_PSZ f_pszStr, 
				tOCT_PSZ f_pszToken, 
				tOCT_PSZ *f_ppszNextStr );




/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrFindNextChar

Description:  Find the next specific character of the string

		tOCT_PSZ f_pszString	=> String to process
		tOCT_CHAR f_ch		=> Character to find

		RETURN:
				position where character was found
				-1 if not found
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrFindNextChar( 
					tOCT_PSZ f_pszString, 
					tOCT_CHAR f_ch );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrReplChar

Description:  Replace all specific f_ch from a string by f_chRep

		tOCT_PSZ f_pszString	=> String to process
		tOCT_CHAR f_ch		=> Character to find
		tOCT_CHAR f_pszRep	=> Character to find

		RETURN:
				result str len
				-1 on error
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void OADF_APIENTRY OctAdfUtilStrReplChar(  
				tOCT_PSZ f_pszString, 
				tOCT_CHAR f_ch, 
				tOCT_CHAR f_chRep  );




/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrCharRepl

Description:  Replace all specific f_ch from a string f_pszRep

		tOCT_PSZ f_pszString	=> String to process
		tOCT_CHAR f_ch		=> Character to find
		tOCT_CHAR f_pszRep	=> Character to find
		tOCT_UINT32 f_ulMax	=> Max to process
		tOCT_PSZ f_pszStrOut	=> String destination

		RETURN:
				result str len
				-1 on error
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrCharRepl( 
				tOCT_PSZ f_pszString, 
				tOCT_CHAR f_ch, 
				tOCT_PSZ f_pszRep, 
				tOCT_UINT32 f_ulMax, 
				tOCT_PSZ f_pszStrOut );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function: OctAdfUtilStrMatchBrace

Description:  Find a string inside brace token

		tOCT_PSZ f_pszString		=> String to process
		tOCT_CHAR f_chStart		=> Character that start substring
		tOCT_CHAR f_chStop		=> Character that stop substring
		tOCT_BOOL32 f_UseCRLF_EoL	=> Use CRLF as eof line
		tOCT_INT32 * f_plEndPos	=> End of match pos -1 on error

		RETURN:
				Start of match pos
				-1 on error
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilStrMatchBrace( 
					tOCT_PSZ f_pszString, 
					tOCT_CHAR f_chStart, 
					tOCT_CHAR f_chEnd, 
					tOCT_BOOL32 f_UseCRLF_EoL, 
					tOCT_INT32 * f_plEndPos );

	 
/*----------------------------------------------------------------------------
	Config context
----------------------------------------------------------------------------*/

typedef struct _OCTADF_UTIL_CONFIG_CTX_
{
	tOCT_CHAR		szCurrSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];	/*  Current section name */
	tOCT_INT32		lCurrSectionLength;								/*  Current section length */

	tOCT_CHAR		szCurrItemName[cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH+1];	/*  Current item name */
	tOCT_INT32		lCurrItemLength;								/*  Current item length */

	tOCT_PSZ		pszCurrentPos;			/*  Current buffer position */

	tOCT_PSZ		pszStartOfSection;		/*  Start of config section  */

	tOCT_PSZ		pszConfigBuffer;		/*  Start of config buffer */
	tOCT_INT32		lConfigLength;		/*  Config length */

	tOCT_CHAR		szTargetSection[cOCTADF_UTIL_CONFIG_SECTION_NAME_LENGTH+1];	/*  Target section name */
	tOCT_CHAR		szTargetItem[cOCTADF_UTIL_CONFIG_MAX_ITEM_NAME_LENGTH+1];		/*  Target item name */

	tOCT_BOOL32		fCaseInsensitive;		/* Search item without case sensitivity */

}tOCTADF_UTIL_CONFIG_CTX;


/*----------------------------------------------------------------------------
	Config item list
----------------------------------------------------------------------------*/
/*
	Item list function is a helper function for lazy programmers.
	This function read all the entry declared in the supplied item array
	and take care of common coding tests and processing :
	- Mandatory fields checking,
	- Convertion of string param value to common type or through decode call back
	functions for advanced user params,
	- Entry repetition.

  Example :
  [SECTION]
  entryname=MyEntryName
  ipaddr=1.2.3.4
  valid=cOCT_TRUE
  ref=0x33
  ref=0x44
  ref=0x55

  Assuming 'entryname' is mandatory and ref can be repeated.
  _fmo_DecodeIp() is a local function that convert a string ip addr
  to a IP_ADDR struct (like  inet_addr ).
  Use the following item list and code to read this section :

  tOCT_CHAR						szEntryName[cMAX_ENTRY];
  tOCT_UINT32					aRef[cMAX_REF];
  tOCT_UINT32					ulRefCount = cMAX_REF;
  IP_ADDR					IpAddr;
  tOCT_BOOL32						fValid;
  tOCTADF_UTIL_CONFIG_ITEM_DECL	pFailureItem;

  tOCTADF_UTIL_CONFIG_ITEM_DECL	aMyItemList[]=
  {
	cOCTADF_UTIL_CONFIG_ITEM_DECL_MANDATORY("entryname",cOCTADF_UTIL_CONFIG_ITEM_TYPE_STRING,szEntryName,sizeof(szEntryName))
	cOCTADF_UTIL_CONFIG_ITEM_DECL_USER("ipaddr", _fmo_DecodeIp, &IpAddr, sizeof(IpAddr) )
	cOCTADF_UTIL_CONFIG_ITEM_DECL("valid", cOCTADF_UTIL_CONFIG_ITEM_TYPE_BOOL, &fValid, sizeof(fValid) )
	cOCTADF_UTIL_CONFIG_ITEM_DECL_REPEAT("ref", cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINT32_HEX, aRef, sizeof(aRef[0]), &ulRefCount )
	cOCTADF_UTIL_CONFIG_ITEM_DECL_LAST
  };

  ulRc = OctAdfUtilConfigGetItemList(
						pMyConfigContext,
						aMyItemList,
						&pFailureItem );



*/
/* item type supported */
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_INVALID		(0)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINT32		(1)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINT32_HEX	(2)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_STRING		(3)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_BOOL			(4)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_USER			(5)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_UINTX			(6)
#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_INTX			(7)

#define cOCTADF_UTIL_CONFIG_ITEM_FLAVOR_INCLUDE_COMMENT		(0x80000000)	/* Do not stop item when encounter " #" */

#define cOCTADF_UTIL_CONFIG_ITEM_TYPE_MASK					(0x00FFFFFF)	/* */
#define cOCTADF_UTIL_CONFIG_ITEM_FLAVOR_MASK				(0xFF000000)	/* */

/* user decode function for item */
typedef tOCT_UINT32 (OADF_APIENTRY *tPFN_OCTADF_UTIL_CONFIG_ITEM_DECODE)(
			tOCT_PSZ			f_szItem,
			tOCT_UINT32			f_ulItemDataSize,
			void *				f_pItemData );

/* Item declaration struct */
typedef struct _OCTADF_UTIL_CONFIG_ITEM_DECL_
{
	tOCT_PSZ							pszItemName;
	tOCT_BOOL32							fMandatory;
	tOCT_UINT32							ulItemType;
	tPFN_OCTADF_UTIL_CONFIG_ITEM_DECODE	pfnItemDecode;
	void *								pItemData;
	tOCT_UINT32							ulItemDataSize;
	tOCT_BOOL32							fRepeat;
	tOCT_UINT32 *						pulRepeatArrayElementCount;

} tOCTADF_UTIL_CONFIG_ITEM_DECL;

/* Item list array must be terminated by this define */
#define cOCTADF_UTIL_CONFIG_ITEM_DECL_LAST	{NULL}
/* helpfull macro declaration */
#define cOCTADF_UTIL_CONFIG_ITEM_DECL( f_szItemName, f_szItemType, f_pItemData, f_ulItemDataSize )	\
			{ f_szItemName, cOCT_FALSE, f_szItemType, NULL, f_pItemData, f_ulItemDataSize, cOCT_FALSE, NULL },

#define cOCTADF_UTIL_CONFIG_ITEM_DECL_MANDATORY( f_szItemName, f_szItemType, f_pItemData, f_ulItemDataSize )	\
			{ f_szItemName, cOCT_TRUE, f_szItemType, NULL, f_pItemData, f_ulItemDataSize, cOCT_FALSE, NULL },

#define cOCTADF_UTIL_CONFIG_ITEM_DECL_USER( f_szItemName, f_pItemDecode, f_pItemData, f_ulItemDataSize )	\
			{ f_szItemName, cOCT_FALSE, cOCTADF_UTIL_CONFIG_ITEM_TYPE_USER, f_pItemDecode, f_pItemData, f_ulItemDataSize, cOCT_FALSE, NULL },

#define cOCTADF_UTIL_CONFIG_ITEM_DECL_USER_MANDATORY( f_szItemName, f_pItemDecode, f_pItemData, f_ulItemDataSize )	\
			{ f_szItemName, cOCT_TRUE, cOCTADF_UTIL_CONFIG_ITEM_TYPE_USER, f_pItemDecode, f_pItemData, f_ulItemDataSize, cOCT_FALSE, NULL },

#define cOCTADF_UTIL_CONFIG_ITEM_DECL_REPEAT( f_szItemName, f_szItemType, f_pItemData, f_ulItemDataSize, f_pulRepeatMaxCount )	\
			{ f_szItemName, cOCT_FALSE, f_szItemType, NULL, f_pItemData, f_ulItemDataSize, cOCT_TRUE, f_pulRepeatMaxCount },

#define cOCTADF_UTIL_CONFIG_ITEM_DECL_USER_REPEAT( f_szItemName, f_pItemDecode, f_pItemData, f_ulItemDataSize, f_pulRepeatMaxCount )	\
			{ f_szItemName, cOCT_FALSE, cOCTADF_UTIL_CONFIG_ITEM_TYPE_USER, f_pItemDecode, f_pItemData, f_ulItemDataSize, cOCT_TRUE, f_pulRepeatMaxCount },



/* parsing function for section */
typedef tOCT_UINT32 (OADF_APIENTRY *tPFN_OCTADF_UTIL_CONFIG_GET_SECTION)( 
	tOCTADF_UTIL_CONFIG_CTX *				f_pConfCtx,
	void *									f_UserInfo);

/* Section declaration struct */
typedef struct _OCTADF_UTIL_CONFIG_SEC_DECL_
{
	tOCT_PSZ							pszSecName;
	tOCT_BOOL32							fMandatory;
	tPFN_OCTADF_UTIL_CONFIG_GET_SECTION	pCallback;
	void *								pUserInfo;
	tOCT_UINT32							ulRepeatMaxCount;

} tOCTADF_UTIL_CONFIG_SEC_DECL;
		
/* Item section array must be terminated by this define */
#define cOCTADF_UTIL_CONFIG_SEC_DECL_LAST	{NULL}

/* helpfull macro declaration */
#define cOCTADF_UTIL_CONFIG_SEC_DECL( f_szSecName, f_pCallback, f_pUserInfo, f_pulRepeatMaxCount )	\
			{ f_szSecName, cOCT_FALSE, f_pCallback, f_pUserInfo, f_pulRepeatMaxCount },

#define cOCTADF_UTIL_CONFIG_SEC_DECL_MANDATORY( f_szSecName, f_pCallback, f_pUserInfo, f_pulRepeatMaxCount )	\
			{ f_szSecName, cOCT_TRUE, f_pCallback, f_pUserInfo, f_pulRepeatMaxCount },
			
/* Master Section declaration struct */
typedef struct _OCTADF_UTIL_CONFIG_MASTER_SEC_DECL_
{
	tOCT_PSZ							szMasterSecName;
	tOCTADF_UTIL_CONFIG_SEC_DECL *		pSections;

} tOCTADF_UTIL_CONFIG_MASTER_SEC_DECL;
		
/* Item section array must be terminated by this define */
#define cOCTADF_UTIL_CONFIG_MASTER_SEC_DECL_LAST	{NULL}

/* helpfull macro declaration */
#define cOCTADF_UTIL_CONFIG_MASTER_SEC_DECL_START( f_szMasterSecName, f_pSections )	\
			{ f_szMasterSecName, f_pSections},


/************************** FUNCTION PROTOTYPES  *****************************/

/*----------------------------------------------------------------------------
	Config file
----------------------------------------------------------------------------*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetItem

Description:   Get configuration item from a null ascii terminated configuration buffer.

		tOCT_PSZ	f_pszSection		=>	Configuration section name. Word with not space. 
										This word will be contain between brace in f_pszConfigBuffer ex: [Section_Name]
										Section name must have there own line.
		tOCT_PSZ	f_pszItemName		=>	Item name. First word of a line with no space 
										ex: LOGFILE=d:\temp\log 
												"LOGFILE" is the item name and "d:\temp\log" the item data
		tOCT_PSZ	f_pszDefault		=>	String to return if the item is not found
		tOCT_PSZ	f_pszData			=>	Requested data
		tOCT_INT32	f_lValueMax			=>	Maximum space allow for the requested data
		tOCT_PSZ	f_pszConfigBuffer	=>	Configuration buffer.

		RETURN:
				Requested data size.
				-1 if can not process the request

		PS:		
			1: If f_pszSection is NULL, f_pszData will contain all section name... space delimited.
			2: If f_pszSection is NULL and f_pszData is NULL, return error (-1).
			3: If f_pszItemName is NULL return all section content.
			4: If f_pszItemName is NULL and f_pszData is NULL, RETURN will be the size of all section content.
			5: If f_pszItemName is -1 return all key name ... space delimited
			6: If f_pszData is NULL, RETURN the length of the section or the item value (with separator).
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilConfigGetItem( 
				tOCT_PSZ f_pszSection, 
				tOCT_PSZ f_pszItemName, 
				tOCT_PSZ f_pszDefault, 
				tOCT_PSZ f_pszData, 
				tOCT_INT32 f_lValueMax, 
				tOCT_PSZ f_pszConfigBuffer );

	

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetAllSectionName

Description:   Get all section name from a null ascii terminated configuration buffer.

		tOCT_PSZ f_pszDelemiter		=> section name delimiter
		tOCT_PSZ f_pszData			=> All function name
		tOCT_INT32 f_lValueMax			=> Maximum space allow for the requested data
		tOCT_PSZ f_pszConfigBuffer	=> Configuration buffer. 

		RETURN:
				Requested data size.
				-1 if can not process the request

			1: If f_pszData is NULL, RETURN the length of the section names space.
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_INT32 OADF_APIENTRY OctAdfUtilConfigGetAllSectionName( 
				tOCT_PSZ pszDelemiter,
				tOCT_PSZ f_pszData, 
				tOCT_INT32 f_lValueMax, 
				tOCT_PSZ f_pszConfigBuffer );



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetFirstSection

Description:   Get First section name from a null ascii terminated configuration buffer.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	New section context
		tOCT_PSZ	f_pszSection				=>	Configuration section name. Word with not space. 
												This word will be contain between brace in f_pszConfigBuffer ex: [Section_Name]
												Section name must have there own line.

		tOCT_PSZ	f_pszData					=>	Requested data
		tOCT_INT32	f_lValueMax					=>	Maximum space allow for the requested data
		tOCT_PSZ	f_pszConfigBuffer			=>	Configuration buffer.

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no section found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
				cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG		=> section name is too long
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL	=> data buffer is too small

		PS:		
			1: If f_pszSection is NULL, f_pszData will contain the first section of f_pszConfigBuffer
			2: If f_pszData is NULL, POCTADF_UTIL_CONFIG_CTX will reflect first section param
			3: If f_pszData is NOT NULL, f_pszData will contain the full section data. if big enough
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetFirstSection( 
			tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
			tOCT_PSZ f_pszSection, 
			tOCT_PSZ f_pszData, 
			tOCT_INT32 f_lValueMax, 
			tOCT_PSZ f_pszConfigBuffer );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetNextSection

Description:   Get next section from a null ascii terminated configuration buffer.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	Current Section context

		tOCT_PSZ	f_pszData					=>	Requested data
		tOCT_INT32	f_lValueMax					=>	Maximum space allow for the requested data

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no section found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL	=> data buffer is too small
				cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG		=> End of config
				cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED	=> Context is corrupted

		PS:		
			1: If f_pszData is NULL, POCTADF_UTIL_CONFIG_CTX will reflect next section param
			2: If f_pszData is NOT NULL, f_pszData will contain the full section data. if big enough
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetNextSection( tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
											tOCT_PSZ f_pszData, tOCT_INT32 f_lValueMax );

	

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetFirstItem

Description:   Get First section item from a null ascii terminated configuration buffer.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	Current section context
		tOCT_PSZ	f_pszItemName				=>	Item name to look for. First word of a line with no space 

		tOCT_PSZ	f_pszData					=>	Requested data
		tOCT_INT32	f_lValueMax					=>	Maximum space allow for the requested data

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no item found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL	=> data buffer is too small
				cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG		=> End of config
				cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED	=> Context is corrupted

		PS:		
			1: If f_pszItemName is NULL, f_pszData will contain the first section item 
			2: If f_pszData is NULL, POCTADF_UTIL_CONFIG_CTX will reflect first item param
			3: If f_pszData is NOT NULL, f_pszData will contain the full item data. if big enough
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetFirstItem( tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
										  tOCT_PSZ f_pszItemName, tOCT_PSZ f_pszData, tOCT_INT32 f_lValueMax );

	


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetNextItem

Description:   Get next section item from a null ascii terminated configuration buffer.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	Current section context

		tOCT_PSZ	f_pszData					=>	Requested data
		tOCT_INT32	f_lValueMax					=>	Maximum space allow for the requested data

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no item found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL	=> data buffer is too small
				cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG		=> End of config
				cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED	=> Context is corrupted

		PS:		
			1: If f_pszData is NULL, POCTADF_UTIL_CONFIG_CTX will reflect first item param
			2: If f_pszData is NOT NULL, f_pszData will contain the full item data. if big enough

		tOCT_PSZ f_pszStr		=> String to convert
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetNextItem( tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
												tOCT_PSZ f_pszData, tOCT_INT32 f_lValueMax );

	


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetItemCount

Description:   Get First section item from a null ascii terminated configuration buffer.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	Current section context
		tOCT_PSZ	f_pszItemName				=>	Item name to look for. If NULL count all item

		tOCT_UINT32 * f_pulItemCount			=>	Item count

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no item found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
				cOCTADF_UTIL_CONFIG_RC_EOF_CONFIG		=> End of config
				cOCTADF_UTIL_CONFIG_RC_CTX_CORRUPTED	=> Context is corrupted

		PS:		
			1: If f_pszItemName is NULL, Count all items
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetItemCount( tOCTADF_UTIL_CONFIG_CTX * f_pConfCtx, 
											tOCT_PSZ f_pszItemName, tOCT_UINT32 * f_pulItemCount );


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetItemList

Description:  Get configuration items list from config context.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	Current Section context
		tOCTADF_UTIL_CONFIG_ITEM_DECL *	f_aConfItemDecl		=>	Item declaration list.
		tOCTADF_UTIL_CONFIG_ITEM_DECL * *	f_ppErrorItem	=> Item declaration that fail

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no section found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
				cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG		=> section name is too long
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL	=> data buffer is too small
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetItemList( 
	tOCTADF_UTIL_CONFIG_CTX *				f_pConfCtx,
	tOCTADF_UTIL_CONFIG_ITEM_DECL *		f_aConfItemDecl,
	tOCTADF_UTIL_CONFIG_ITEM_DECL * *	f_ppErrorItem );

	
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigGetSectionList

Description:  Get configuration items list from config context.

		tOCTADF_UTIL_CONFIG_CTX *				f_ConfCtx					=>	Current Section context
		tOCT_PSZ *								f_pszBuffer					=>	Config content
		tOCT_PSZ *								f_pszMasterSection			=>	Work buffer for current master section
		tOCT_UINT32								f_ulMasterSectionMaxSize	=>	Work buffer Size
		tOCTADF_UTIL_CONFIG_MASTER_SEC_DECL *	f_aConfSecDecl				=>	Section declaration list.

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND				=> no section found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM				=> bad param
				cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG	=> section name is too long
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL		=> data buffer is too small
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigGetSectionList( 
	tOCTADF_UTIL_CONFIG_CTX *				f_pConfCtx,
	tOCT_PSZ								f_pszBuffer,
	tOCT_PSZ								f_pszMasterSection,
	tOCT_UINT32								f_ulMasterSectionMaxSize,
	tOCTADF_UTIL_CONFIG_MASTER_SEC_DECL *	f_aConfSecDecl );

	

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:		OctAdfUtilConfigExtractMasterSection

Description:   Extract master section from buffer. 
		Master section is delimited by begin and end keyword, is Master section name is OCTUTIL, 
		everithing between [OCTUTIL_BEGIN] and [OCTUTIL_END] will be copied into dest buffer
		excluding master section delimiters.

		tOCTADF_UTIL_CONFIG_CTX * f_ConfCtx	=>	Current Section context
		tOCTADF_UTIL_CONFIG_ITEM_DECL *	f_aConfItemDecl		=>	Item declaration list.
		tOCTADF_UTIL_CONFIG_ITEM_DECL * *	f_ppErrorItem	=> Item declaration that fail

		RETURN:
			#define cOCTVC1_RC_OK
			#define cOCTVC1_GENERIC_RC_NOT_FOUND		=> no section found
			#define cOCTVC1_GENERIC_RC_BAD_PARAM		=> bad param
				cOCTADF_UTIL_CONFIG_RC_NAME_TOO_LONG		=> section name is too long
			#define cOCTADF_UTIL_RC_BUFFER_TOO_SMALL	=> data buffer is too small
		
		RETURN
				TRUE;
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OADF_APIENTRY OctAdfUtilConfigExtractMasterSection( 
	tOCT_PSZ				f_pszMasterSection, 
	tOCT_INT32				f_lValueMax,
	tOCT_PSZ				f_pszMasterSectionName, 
	tOCT_PSZ				f_pszBuffer );


#ifdef __cplusplus
}
#endif

#endif /* __OCTADF_UTIL_CONFIG_H__ */


