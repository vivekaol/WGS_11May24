/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_msg_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_MSG_SWAP_H__
#define __OCTVC1_MSG_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_msg.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_MSG_FLAGS_MASK_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_MSG_FLAGS_MASK_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_MSG_HEADER_SWAP( _f_pParms ){ 	tOCTVC1_MSG_HEADER * pOCTVC1_MSG_HEADER = (_f_pParms); SWAP_UNUSED(pOCTVC1_MSG_HEADER)\
	((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulLength = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulLength); \
	((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulTransactionId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulTransactionId); \
	((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ul_Type_R_CmdId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ul_Type_R_CmdId); \
	((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulSessionId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulSessionId); \
	((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulReturnCode = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_MSG_HEADER *)pOCTVC1_MSG_HEADER)->ulReturnCode); \
}
#else
#define mOCTVC1_MSG_HEADER_SWAP( pOCTVC1_MSG_HEADER )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_EVENT_HEADER_SWAP( _f_pParms ){ 	tOCTVC1_EVENT_HEADER * pOCTVC1_EVENT_HEADER = (_f_pParms); SWAP_UNUSED(pOCTVC1_EVENT_HEADER)\
	((tOCTVC1_EVENT_HEADER *)pOCTVC1_EVENT_HEADER)->ulLength = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_EVENT_HEADER *)pOCTVC1_EVENT_HEADER)->ulLength); \
	((tOCTVC1_EVENT_HEADER *)pOCTVC1_EVENT_HEADER)->ulEventId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_EVENT_HEADER *)pOCTVC1_EVENT_HEADER)->ulEventId); \
	((tOCTVC1_EVENT_HEADER *)pOCTVC1_EVENT_HEADER)->ulUserEventId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_EVENT_HEADER *)pOCTVC1_EVENT_HEADER)->ulUserEventId); \
}
#else
#define mOCTVC1_EVENT_HEADER_SWAP( pOCTVC1_EVENT_HEADER )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_MSG_SWAP_H__ */
