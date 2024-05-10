/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_ipc_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_IPC_SWAP_H__
#define __OCTVC1_IPC_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_ipc.h"

/*********************************  MACROS  **********************************/



#define mOCTVC1_IPC_MSG_FLAG_MASK_SWAP( pType )	/* tOCT_UINT8 */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_IPC_MSG_HEADER_SWAP( _f_pParms ){ 	tOCTVC1_IPC_MSG_HEADER * pOCTVC1_IPC_MSG_HEADER = (_f_pParms); SWAP_UNUSED(pOCTVC1_IPC_MSG_HEADER)\
	((tOCTVC1_IPC_MSG_HEADER *)pOCTVC1_IPC_MSG_HEADER)->ulFlag_Seq_Id = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_IPC_MSG_HEADER *)pOCTVC1_IPC_MSG_HEADER)->ulFlag_Seq_Id); \
}
#else
#define mOCTVC1_IPC_MSG_HEADER_SWAP( pOCTVC1_IPC_MSG_HEADER )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_IPC_SWAP_H__ */
