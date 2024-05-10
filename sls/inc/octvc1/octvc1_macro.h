/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_MACRO.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_MACRO_H__
#define __OCTVC1_MACRO_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "../octdev_macro.h"
#include "octvc1_handle.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Generic swap macros
-------------------------------------------------------------------------------------*/

                
/*--------------------------------------------------------------------------
	32-bit Endian Swapping when target is Little Endian 
----------------------------------------------------------------------------*/
#if !defined( mOCTVC1_SWAP32_IF_LE )
#define mOCTVC1_SWAP32_IF_LE( f_ulValue )  mOCT_SWAP32_IF_LE( f_ulValue )
#endif /* mOCTVC1_SWAP32_IF_LE */

/*--------------------------------------------------------------------------
	16-bit Endian Swapping when target is Little Endian 
----------------------------------------------------------------------------*/
#if !defined( mOCTVC1_SWAP16_IF_LE )
#define mOCTVC1_SWAP16_IF_LE( f_usValue ) mOCT_SWAP16_IF_LE( f_usValue )
#endif /* mOCTVC1_SWAP16_IF_LE */

/*--------------------------------------------------------------------------
	Create a TSST Identifier 
----------------------------------------------------------------------------*/

#define mOCTVC1_MAKE_TSST_ID( f_ulStream, f_ulTimeslot ) \
		( ( ((f_ulStream) & 0x1f) << 10 ) + \
			((f_ulTimeslot) & 0x3ff) )

/*--------------------------------------------------------------------------
	Get Vocoder Mask from a Vocoder Type Value
----------------------------------------------------------------------------*/
/* what 32-bit DWORD index the bit mask corresponds to */
#define mOCTVC1_GET_VOCMASK_INDEX( f_ulEncoderType ) \
	(  (((f_ulEncoderType) >> 5) & 0x3) )

/* The actual bit mask for the 32-bit index */
#define mOCTVC1_GET_VOCMASK_BIT( f_ulEncoderType ) \
	(  (1 << ((f_ulEncoderType) & 0x1F))  )
            
              

#endif /* __OCTVC1_MACRO_H__ */

