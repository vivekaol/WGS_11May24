/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTDEV_MACRO.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTDEV_MACRO_H__
#define __OCTDEV_MACRO_H__


/*****************************  INCLUDE FILES  *******************************/
#include "octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Generic swap macros
-------------------------------------------------------------------------------------*/

                
#if !defined( mOCT_SWAP32 )

#if defined( __linux__ )
/* Linux (and probably other unices') htonl implementation is far more
 * efficient than our own; Win32 implementation, howerever is similar to
 * our own BUT with the added cost of a function call */
		
#include <arpa/inet.h>
#include <endian.h>

#if defined( _OCT_ENDIAN_TYPE_LE_ )

#define mOCT_SWAP64( f_ullValue )	(((uint64_t)ntohl(f_ullValue)) << 32 | ntohl(f_ullValue>>32))
#define mOCT_SWAP32			htonl
#define mOCT_SWAP16			htons

#else	/* _OCT_ENDIAN_TYPE_BE_ */

#define mOCT_SWAP64			letoh64
#define mOCT_SWAP32			letoh32
#define mOCT_SWAP16			letoh16

#endif	/* _OCT_ENDIAN_TYPE_LE_ */

#else /* windows and others ...  */
		
#define mOCT_SWAP64( f_ullValue ) \
		(((tOCT_UINT64)(f_ullValue) << 56) | \
      (((tOCT_UINT64)(f_ullValue) << 40) & 0xff000000000000ULL) | \
      (((tOCT_UINT64)(f_ullValue) << 24) & 0xff0000000000ULL) | \
      (((tOCT_UINT64)(f_ullValue) << 8)  & 0xff00000000ULL) | \
      (((tOCT_UINT64)(f_ullValue) >> 8)  & 0xff000000ULL) | \
      (((tOCT_UINT64)(f_ullValue) >> 24) & 0xff0000ULL) | \
      (((tOCT_UINT64)(f_ullValue) >> 40) & 0xff00ULL) | \
      ((tOCT_UINT64)(f_ullValue)  >> 56))

#define mOCT_SWAP32( f_ulValue ) \
		    ( (((f_ulValue) & 0xff000000 ) >> 24) | \
		      (((f_ulValue) & 0x00ff0000 ) >> 8) | \
		      (((f_ulValue) & 0x0000ff00 ) << 8) | \
		      (((f_ulValue) & 0x000000ff ) << 24)  )

#define mOCT_SWAP16( f_usValue ) \
		    ( (((f_usValue) & 0x00ff ) << 8) | \
		      (((f_usValue) & 0xff00 ) >> 8) ) 

#endif /* __linux__ */

#endif	/* mOCT_SWAP32 */

/*-------------------------------------------------------------------------------------
 	Generic swap LE macros
-------------------------------------------------------------------------------------*/
#if !defined( mOCT_SWAP32_IF_LE )

#if defined( _OCT_ENDIAN_TYPE_LE_ )

#define mOCT_SWAP64_IF_LE	mOCT_SWAP64
#define mOCT_SWAP32_IF_LE	mOCT_SWAP32
#define mOCT_SWAP16_IF_LE	mOCT_SWAP16


#else	/* _OCT_ENDIAN_TYPE_LE_ */
		
#define mOCT_SWAP64_IF_LE( f_ulValue )	(f_ulValue)
#define mOCT_SWAP32_IF_LE( f_ulValue )	(f_ulValue)
#define mOCT_SWAP16_IF_LE( f_usValue )	(f_usValue)

#endif /* _OCT_ENDIAN_TYPE_LE_ */
#endif /* mOCT_SWAP32_IF_LE  */

/*-------------------------------------------------------------------------------------
 	Generic swap BE macros
-------------------------------------------------------------------------------------*/
#if !defined( mOCT_SWAP32_IF_BE )

#if defined( _OCT_ENDIAN_TYPE_BE_ )

#define mOCT_SWAP64_IF_BE	mOCT_SWAP64
#define mOCT_SWAP32_IF_BE	mOCT_SWAP32
#define mOCT_SWAP16_IF_BE	mOCT_SWAP16

#else	/* _OCT_ENDIAN_TYPE_BE_ */
		
#define mOCT_SWAP64_IF_BE( f_ulValue )	(f_ulValue)
#define mOCT_SWAP32_IF_BE( f_ulValue )	(f_ulValue)
#define mOCT_SWAP16_IF_BE( f_usValue )	(f_usValue)

#endif /* _OCT_ENDIAN_TYPE_BE_ */
#endif /* mOCT_SWAP32_IF_BE  */
           
            
              

#endif /* __OCTDEV_MACRO_H__ */

