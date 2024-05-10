/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octdev_types_swap.h	

Copyright (c) 2019 Octasic Inc. All rights reserved.	

Description:	

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTDEV_TYPES_SWAP_H__
#define __OCTDEV_TYPES_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1/octvc1_swap_hdrs.h"
#include "octdev_types.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTDEV_IP_VERSION_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTDEV_IP_VERSION_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTDEV_IP_ADDRESS_SWAP( _f_pParms ){ 	tOCTDEV_IP_ADDRESS * pOCTDEV_IP_ADDRESS = (_f_pParms); SWAP_UNUSED(pOCTDEV_IP_ADDRESS)\
	{ mOCTDEV_IP_VERSION_ENUM_SWAP( &((tOCTDEV_IP_ADDRESS *)pOCTDEV_IP_ADDRESS)->ulIpVersion ); }  \
	{ tOCT_UINT32 iOCTDEV_IP_ADDRESS; \
	for( iOCTDEV_IP_ADDRESS=0; \
		iOCTDEV_IP_ADDRESS<(4);iOCTDEV_IP_ADDRESS++ ) \
	((tOCTDEV_IP_ADDRESS *)pOCTDEV_IP_ADDRESS)->aulIpAddress[iOCTDEV_IP_ADDRESS] = \
		mOCT_SWAP32_IF_LE(((tOCTDEV_IP_ADDRESS *)pOCTDEV_IP_ADDRESS)->aulIpAddress[iOCTDEV_IP_ADDRESS]);}\
}
#else
#define mOCTDEV_IP_ADDRESS_SWAP( pOCTDEV_IP_ADDRESS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTDEV_UDP_ADDRESS_SWAP( _f_pParms ){ 	tOCTDEV_UDP_ADDRESS * pOCTDEV_UDP_ADDRESS = (_f_pParms); SWAP_UNUSED(pOCTDEV_UDP_ADDRESS)\
	{ mOCTDEV_IP_ADDRESS_SWAP( &((tOCTDEV_UDP_ADDRESS *)pOCTDEV_UDP_ADDRESS)->IpAddress ); }  \
	((tOCTDEV_UDP_ADDRESS *)pOCTDEV_UDP_ADDRESS)->ulUdpPort = \
		mOCT_SWAP32_IF_LE(((tOCTDEV_UDP_ADDRESS *)pOCTDEV_UDP_ADDRESS)->ulUdpPort); \
}
#else
#define mOCTDEV_UDP_ADDRESS_SWAP( pOCTDEV_UDP_ADDRESS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTDEV_TCP_ADDRESS_SWAP( _f_pParms ){ 	tOCTDEV_TCP_ADDRESS * pOCTDEV_TCP_ADDRESS = (_f_pParms); SWAP_UNUSED(pOCTDEV_TCP_ADDRESS)\
	{ mOCTDEV_IP_ADDRESS_SWAP( &((tOCTDEV_TCP_ADDRESS *)pOCTDEV_TCP_ADDRESS)->IpAddress ); }  \
	((tOCTDEV_TCP_ADDRESS *)pOCTDEV_TCP_ADDRESS)->ulTcpPort = \
		mOCT_SWAP32_IF_LE(((tOCTDEV_TCP_ADDRESS *)pOCTDEV_TCP_ADDRESS)->ulTcpPort); \
}
#else
#define mOCTDEV_TCP_ADDRESS_SWAP( pOCTDEV_TCP_ADDRESS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTDEV_TYPES_SWAP_H__ */
