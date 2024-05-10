/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_test_api_swap.h	

Copyright (c) 2016 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.00.00-B212 (2016/12/02)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_TEST_API_SWAP_H__
#define __OCTVC1_TEST_API_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_swap_hdrs.h"
#include "octvc1_test_api.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_TEST_EXEC_PARMS_SWAP( _f_pParms ){ 	tOCTVC1_TEST_EXEC_PARMS * pOCTVC1_TEST_EXEC_PARMS = (_f_pParms); SWAP_UNUSED(pOCTVC1_TEST_EXEC_PARMS)\
	{ tOCT_UINT32 iOCTVC1_TEST_EXEC_PARMS; \
	for( iOCTVC1_TEST_EXEC_PARMS=0; \
		iOCTVC1_TEST_EXEC_PARMS<(cOCTVC1_TEST_RUNNER_TEST_MAX_OBJ);iOCTVC1_TEST_EXEC_PARMS++ ) \
	((tOCTVC1_TEST_EXEC_PARMS *)pOCTVC1_TEST_EXEC_PARMS)->ahObj[iOCTVC1_TEST_EXEC_PARMS] = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_TEST_EXEC_PARMS *)pOCTVC1_TEST_EXEC_PARMS)->ahObj[iOCTVC1_TEST_EXEC_PARMS]);}\
}
#else
#define mOCTVC1_TEST_EXEC_PARMS_SWAP( pOCTVC1_TEST_EXEC_PARMS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_TEST_API_SWAP_H__ */
