/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_eth_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_ETH_SWAP_H__
#define __OCTVC1_ETH_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_eth.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_ETH_PORT_ID_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_ETH_PORT_ID_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_ETH_ADDRESS_SWAP( _f_pParms ){ 	tOCTVC1_ETH_ADDRESS * pOCTVC1_ETH_ADDRESS = (_f_pParms); SWAP_UNUSED(pOCTVC1_ETH_ADDRESS)\
	((tOCTVC1_ETH_ADDRESS *)pOCTVC1_ETH_ADDRESS)->usEtherType = \
		mOCT_SWAP16_IF_LE(((tOCTVC1_ETH_ADDRESS *)pOCTVC1_ETH_ADDRESS)->usEtherType);  \
	((tOCTVC1_ETH_ADDRESS *)pOCTVC1_ETH_ADDRESS)->usReserved = \
		mOCT_SWAP16_IF_LE(((tOCTVC1_ETH_ADDRESS *)pOCTVC1_ETH_ADDRESS)->usReserved);  \
}
#else
#define mOCTVC1_ETH_ADDRESS_SWAP( pOCTVC1_ETH_ADDRESS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_ETH_SWAP_H__ */
