/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_transport_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_TRANSPORT_SWAP_H__
#define __OCTVC1_TRANSPORT_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_transport.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_TRANSPORT_TYPE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_TRANSPORT_TYPE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_TRANSPORT_ADDRESS_SWAP( _f_pParms ){ 	tOCTVC1_TRANSPORT_ADDRESS * pOCTVC1_TRANSPORT_ADDRESS = (_f_pParms); SWAP_UNUSED(pOCTVC1_TRANSPORT_ADDRESS)\
	{ mOCTVC1_TRANSPORT_TYPE_ENUM_SWAP( &((tOCTVC1_TRANSPORT_ADDRESS *)pOCTVC1_TRANSPORT_ADDRESS)->ulTransportType ); }  \
	{ mOCTVC1_ETH_ADDRESS_SWAP( &((tOCTVC1_TRANSPORT_ADDRESS *)pOCTVC1_TRANSPORT_ADDRESS)->Eth ); }  \
}
#else
#define mOCTVC1_TRANSPORT_ADDRESS_SWAP( pOCTVC1_TRANSPORT_ADDRESS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_TRANSPORT_SWAP_H__ */
