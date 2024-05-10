/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_file_swap.h	

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_FILE_SWAP_H__
#define __OCTVC1_FILE_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_file.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_FILE_TYPE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_FILE_TYPE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_FILE_FORMAT_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_FILE_FORMAT_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_FILE_HEADER_SWAP( _f_pParms ){ 	tOCTVC1_FILE_HEADER * pOCTVC1_FILE_HEADER = (_f_pParms); SWAP_UNUSED(pOCTVC1_FILE_HEADER)\
	((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ulMagic = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ulMagic); \
	((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ul_Type_Ver = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ul_Type_Ver); \
	((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ulTimeStamp = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ulTimeStamp); \
	((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ul_Align_HdrSize = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_FILE_HEADER *)pOCTVC1_FILE_HEADER)->ul_Align_HdrSize); \
}
#else
#define mOCTVC1_FILE_HEADER_SWAP( pOCTVC1_FILE_HEADER )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_FILE_SWAP_H__ */
