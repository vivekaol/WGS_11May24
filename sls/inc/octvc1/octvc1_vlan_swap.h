/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_vlan_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_VLAN_SWAP_H__
#define __OCTVC1_VLAN_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_vlan.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_VLAN_PROTOCOL_ID_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_VLAN_PROTOCOL_ID_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_VLAN_TAG_SWAP( _f_pParms ){ 	tOCTVC1_VLAN_TAG * pOCTVC1_VLAN_TAG = (_f_pParms); SWAP_UNUSED(pOCTVC1_VLAN_TAG)\
	((tOCTVC1_VLAN_TAG *)pOCTVC1_VLAN_TAG)->ulPriority = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_VLAN_TAG *)pOCTVC1_VLAN_TAG)->ulPriority); \
	((tOCTVC1_VLAN_TAG *)pOCTVC1_VLAN_TAG)->ulVlanId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_VLAN_TAG *)pOCTVC1_VLAN_TAG)->ulVlanId); \
	{ mOCTVC1_VLAN_PROTOCOL_ID_ENUM_SWAP( &((tOCTVC1_VLAN_TAG *)pOCTVC1_VLAN_TAG)->ulProtocolId ); }  \
}
#else
#define mOCTVC1_VLAN_TAG_SWAP( pOCTVC1_VLAN_TAG )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_VLAN_HEADER_INFO_SWAP( _f_pParms ){ 	tOCTVC1_VLAN_HEADER_INFO * pOCTVC1_VLAN_HEADER_INFO = (_f_pParms); SWAP_UNUSED(pOCTVC1_VLAN_HEADER_INFO)\
	((tOCTVC1_VLAN_HEADER_INFO *)pOCTVC1_VLAN_HEADER_INFO)->ulNumVlanTag = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_VLAN_HEADER_INFO *)pOCTVC1_VLAN_HEADER_INFO)->ulNumVlanTag); \
	{ tOCT_UINT32 jOCTVC1_VLAN_HEADER_INFO; \
	for( jOCTVC1_VLAN_HEADER_INFO=0; \
		jOCTVC1_VLAN_HEADER_INFO<(cOCTVC1_VLAN_MAX_TAG);jOCTVC1_VLAN_HEADER_INFO++ ) \
	{ mOCTVC1_VLAN_TAG_SWAP( &((tOCTVC1_VLAN_HEADER_INFO *)pOCTVC1_VLAN_HEADER_INFO)->aVlanTag[jOCTVC1_VLAN_HEADER_INFO] ); }} \
}
#else
#define mOCTVC1_VLAN_HEADER_INFO_SWAP( pOCTVC1_VLAN_HEADER_INFO )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_VLAN_SWAP_H__ */
