/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_log_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_LOG_SWAP_H__
#define __OCTVC1_LOG_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_log.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_LOG_TYPE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_LOG_TYPE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_LOG_LEVEL_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_LOG_LEVEL_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_LOG_PAYLOAD_TYPE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_LOG_PAYLOAD_TYPE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_LOG_TRACE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_LOG_TRACE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_LOG_TRACE_MASK_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_LOG_TRACE_MASK_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_LOG_HEADER_SWAP( _f_pParms ){ 	tOCTVC1_LOG_HEADER * pOCTVC1_LOG_HEADER = (_f_pParms); SWAP_UNUSED(pOCTVC1_LOG_HEADER)\
	((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->ulId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->ulId); \
	((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->ulTime = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->ulTime); \
	((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->hProcess = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->hProcess); \
	((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->ul_Type_Info_Length = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_LOG_HEADER *)pOCTVC1_LOG_HEADER)->ul_Type_Info_Length); \
}
#else
#define mOCTVC1_LOG_HEADER_SWAP( pOCTVC1_LOG_HEADER )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_LOG_SWAP_H__ */
