/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octpkt_hdrxl_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTPKT_HDRXL_SWAP_H__
#define __OCTPKT_HDRXL_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1/octvc1_swap_hdrs.h"
#include "octpkt_hdrxl.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTPKT_HDRXL_SWAP( _f_pParms ){ 	tOCTPKT_HDRXL * pOCTPKT_HDRXL = (_f_pParms); SWAP_UNUSED(pOCTPKT_HDRXL)\
	{ mOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_SWAP( &((tOCTPKT_HDRXL *)pOCTPKT_HDRXL)->ul_Proto_Format_Length ); }  \
}
#else
#define mOCTPKT_HDRXL_SWAP( pOCTPKT_HDRXL )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTPKT_HDRXL_ETH_SWAP( _f_pParms ){ 	tOCTPKT_HDRXL_ETH * pOCTPKT_HDRXL_ETH = (_f_pParms); SWAP_UNUSED(pOCTPKT_HDRXL_ETH)\
	((tOCTPKT_HDRXL_ETH *)pOCTPKT_HDRXL_ETH)->usReserved = \
		mOCT_SWAP16_IF_LE(((tOCTPKT_HDRXL_ETH *)pOCTPKT_HDRXL_ETH)->usReserved);  \
}
#else
#define mOCTPKT_HDRXL_ETH_SWAP( pOCTPKT_HDRXL_ETH )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTPKT_HDRXL_SWAP_H__ */
