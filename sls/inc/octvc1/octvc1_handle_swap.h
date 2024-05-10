/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_handle_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_HANDLE_SWAP_H__
#define __OCTVC1_HANDLE_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_handle.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_OBJECT32_NAME_SWAP( _f_pParms ){ 	tOCTVC1_OBJECT32_NAME * pOCTVC1_OBJECT32_NAME = (_f_pParms); SWAP_UNUSED(pOCTVC1_OBJECT32_NAME)\
	((tOCTVC1_OBJECT32_NAME *)pOCTVC1_OBJECT32_NAME)->ulObject32 = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_OBJECT32_NAME *)pOCTVC1_OBJECT32_NAME)->ulObject32); \
}
#else
#define mOCTVC1_OBJECT32_NAME_SWAP( pOCTVC1_OBJECT32_NAME )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_OBJECT32_NAME128_SWAP( _f_pParms ){ 	tOCTVC1_OBJECT32_NAME128 * pOCTVC1_OBJECT32_NAME128 = (_f_pParms); SWAP_UNUSED(pOCTVC1_OBJECT32_NAME128)\
	((tOCTVC1_OBJECT32_NAME128 *)pOCTVC1_OBJECT32_NAME128)->ulObject32 = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_OBJECT32_NAME128 *)pOCTVC1_OBJECT32_NAME128)->ulObject32); \
}
#else
#define mOCTVC1_OBJECT32_NAME128_SWAP( pOCTVC1_OBJECT32_NAME128 )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_HANDLE_SWAP_H__ */
