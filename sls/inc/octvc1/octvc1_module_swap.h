/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_module_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_MODULE_SWAP_H__
#define __OCTVC1_MODULE_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_module.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RESOURCE_SWAP( _f_pParms ){ 	tOCTVC1_RESOURCE * pOCTVC1_RESOURCE = (_f_pParms); SWAP_UNUSED(pOCTVC1_RESOURCE)\
	((tOCTVC1_RESOURCE *)pOCTVC1_RESOURCE)->ulModuleId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_RESOURCE *)pOCTVC1_RESOURCE)->ulModuleId); \
	((tOCTVC1_RESOURCE *)pOCTVC1_RESOURCE)->ulLocalMemorySize = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_RESOURCE *)pOCTVC1_RESOURCE)->ulLocalMemorySize); \
}
#else
#define mOCTVC1_RESOURCE_SWAP( pOCTVC1_RESOURCE )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_MODULE_ID_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_MODULE_ID_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_MODULE_APPLICATION_ID_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_MODULE_APPLICATION_ID_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_MODULE_DATA_SWAP( _f_pParms ){ 	tOCTVC1_MODULE_DATA * pOCTVC1_MODULE_DATA = (_f_pParms); SWAP_UNUSED(pOCTVC1_MODULE_DATA)\
	((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->ulModuleDataId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->ulModuleDataId); \
	((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->ulModuleDataSize = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->ulModuleDataSize); \
	((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->hLogicalObj = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->hLogicalObj); \
	((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->ulTimestamp = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MODULE_DATA *)pOCTVC1_MODULE_DATA)->ulTimestamp); \
}
#else
#define mOCTVC1_MODULE_DATA_SWAP( pOCTVC1_MODULE_DATA )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_MODULE_SWAP_H__ */
