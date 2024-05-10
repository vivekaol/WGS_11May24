/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_ctrl_api_swap.h	

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_CTRL_API_SWAP_H__
#define __OCTVC1_CTRL_API_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_swap_hdrs.h"
#include "octvc1_ctrl_api.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_CTRL_MSG_MODULE_REJECT_SPV_SWAP( _f_pParms ){ 	tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV * pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV = (_f_pParms); SWAP_UNUSED(pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV)\
	{ mOCTVC1_MSG_HEADER_SWAP( &((tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV *)pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV)->Header ); }  \
	((tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV *)pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV)->ulExpectedTransactionId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV *)pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV)->ulExpectedTransactionId); \
	((tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV *)pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV)->ulRejectedCmdId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV *)pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV)->ulRejectedCmdId); \
}
#else
#define mOCTVC1_CTRL_MSG_MODULE_REJECT_SPV_SWAP( pOCTVC1_CTRL_MSG_MODULE_REJECT_SPV )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_CTRL_API_SWAP_H__ */
