/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_api_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_API_SWAP_H__
#define __OCTVC1_API_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_api.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_API_SESSION_INFO_SWAP( _f_pParms ){ 	tOCTVC1_API_SESSION_INFO * pOCTVC1_API_SESSION_INFO = (_f_pParms); SWAP_UNUSED(pOCTVC1_API_SESSION_INFO)\
	((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulActiveFlag = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulActiveFlag); \
	((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulSessionId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulSessionId); \
	((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulTransportSessionIndex = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulTransportSessionIndex); \
	((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulTransportSessionId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_API_SESSION_INFO *)pOCTVC1_API_SESSION_INFO)->ulTransportSessionId); \
}
#else
#define mOCTVC1_API_SESSION_INFO_SWAP( pOCTVC1_API_SESSION_INFO )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_API_SESSION_EVT_INFO_SWAP( _f_pParms ){ 	tOCTVC1_API_SESSION_EVT_INFO * pOCTVC1_API_SESSION_EVT_INFO = (_f_pParms); SWAP_UNUSED(pOCTVC1_API_SESSION_EVT_INFO)\
	((tOCTVC1_API_SESSION_EVT_INFO *)pOCTVC1_API_SESSION_EVT_INFO)->ulEvtActiveFlag = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_API_SESSION_EVT_INFO *)pOCTVC1_API_SESSION_EVT_INFO)->ulEvtActiveFlag); \
	((tOCTVC1_API_SESSION_EVT_INFO *)pOCTVC1_API_SESSION_EVT_INFO)->lEvtEnablerCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_API_SESSION_EVT_INFO *)pOCTVC1_API_SESSION_EVT_INFO)->lEvtEnablerCnt); \
	{ mOCTVC1_API_SESSION_EVT_SYSTEM_MODULE_MASK_SWAP( &((tOCTVC1_API_SESSION_EVT_INFO *)pOCTVC1_API_SESSION_EVT_INFO)->ulSystemEvtMask ); }  \
}
#else
#define mOCTVC1_API_SESSION_EVT_INFO_SWAP( pOCTVC1_API_SESSION_EVT_INFO )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_API_VERSION_MASK_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_API_VERSION_MASK_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_API_SWAP_H__ */
