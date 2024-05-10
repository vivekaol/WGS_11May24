#ifndef OCT_OPT_REMOVE_OPTIONS_FILE
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octoption.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Compiler conditionnal directives. 'octoptions_licensing'

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-04.10.01-B3387 (2018/01/29)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTOPTIONS_H__
#define __OCTOPTIONS_H__

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------
	SPECIFIC OPTIONS
----------------------------------------------------------------------------*/

#ifndef OCT_OPT_REMOVE_OPTIONS_SECTIONS

/*****************************  DEFINES  *************************************/
#define mOCTOPTION_UNDEF( opt )
#define mOCTOPTION_IGNORE( opt )
#define mOCTOPTION_PARSER_SECT_START( section )
#define mOCTOPTION_PARSER_SECT_STOP( section )



/*--------------------------------------------------------------------------
	GENERIC DEFINED SECTION
----------------------------------------------------------------------------*/


/* Keep directive */
mOCTOPTION_IGNORE( OCT_OPT_REMOVE_FNC_PARAM_VALIDATION )
mOCTOPTION_IGNORE( OCTTRANSAPI_OPT_SELECT )
mOCTOPTION_IGNORE( OCT_OPT_REMOVE_OCTTRANSAPI_OPT_POLL )
mOCTOPTION_IGNORE( OCTTRANSAPI_OPT_POLL )
mOCTOPTION_IGNORE( OCTOSAL_OPT_ASSERT )
mOCTOPTION_IGNORE( OCTOSAL_OPT_MULTI_THREAD )

mOCTOPTION_IGNORE( OCTVC1_PKT_API_OS_OPT_MULTI_THREAD )
mOCTOPTION_IGNORE( OCTVC1_PKT_API_TRANSPORT_OPT_SELECT )

mOCTOPTION_IGNORE( OCT_OPTION_OCTVC1_REMOVE_PRIVATE )

/*--------------------------------------------------------------------------
	REMOVE LICENSING
----------------------------------------------------------------------------*/
#define OCT_OPT_REMOVE_LICENSING
#define OCT_OPTION_OCTVC1_REMOVE_LICENSING_EXTERNAL

/*--------------------------------------------------------------------------
	SPECIFIC HOST DEFINED SECTION
----------------------------------------------------------------------------*/
mOCTOPTION_PARSER_SECT_START( OCT_OPT_CLIENT_OPTIONS )
#if defined( OCT_OPT_CLIENT_OPTIONS )

/* Remove comments */
mOCTOPTION_UNDEF( OCT_OPT_REMOVE_INTERNAL_COMMENTS )
mOCTOPTION_UNDEF( OCT_OPT_OCTVC1_REMOVE_SDR_FEATURE )


#endif /* OCT_OPT_CLIENT_OPTIONS */
mOCTOPTION_PARSER_SECT_STOP( OCT_OPT_CLIENT_OPTIONS )

/*--------------------------------------------------------------------------
	SPECIFIC TARGET DEFINED SECTION
----------------------------------------------------------------------------*/
mOCTOPTION_PARSER_SECT_START( OCT_OPT_SERVER_OPTIONS )
#if defined( OCT_OPT_SERVER_OPTIONS )


#endif /* OCT_OPT_SERVER_OPTIONS */
mOCTOPTION_PARSER_SECT_STOP( OCT_OPT_SERVER_OPTIONS )

/* Specific parser section */
mOCTOPTION_PARSER_SECT_START( OCT_OPT_PARSER_OPTIONS )

#if defined( OCT_OPT_PARSER_OPTIONS )
mOCTOPTION_UNDEF( OCT_OPT_REMOVE_OPTIONS_FILE )
#define OCT_OPT_REMOVE_OPTIONS_SECTIONS
#endif /* OCT_OPT_PARSER_SECTION */

mOCTOPTION_PARSER_SECT_STOP( OCT_OPT_PARSER_OPTIONS )


#endif /* OCT_OPT_REMOVE_OPTIONS_SECTIONS */

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* __OCTOPTIONS_H__ */

#endif /* OCT_OPT_REMOVE_OPTIONS_FILE */

