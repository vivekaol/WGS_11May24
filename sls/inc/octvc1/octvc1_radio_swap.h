/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_radio_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_RADIO_SWAP_H__
#define __OCTVC1_RADIO_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_radio.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_FREQ_UNIT_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_FREQ_UNIT_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_ID_SWAP( _f_pParms ){ 	tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID * pOCTVC1_RADIO_STANDARD_FREQ_BAND_ID = (_f_pParms); SWAP_UNUSED(pOCTVC1_RADIO_STANDARD_FREQ_BAND_ID)\
	{ mOCTVC1_RADIO_STANDARD_ENUM_SWAP( &((tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID *)pOCTVC1_RADIO_STANDARD_FREQ_BAND_ID)->ulStandard ); }  \
	((tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID *)pOCTVC1_RADIO_STANDARD_FREQ_BAND_ID)->ulBandNumber = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID *)pOCTVC1_RADIO_STANDARD_FREQ_BAND_ID)->ulBandNumber); \
}
#else
#define mOCTVC1_RADIO_STANDARD_FREQ_BAND_ID_SWAP( pOCTVC1_RADIO_STANDARD_FREQ_BAND_ID )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_FREQUENCY_VALUE_SWAP( _f_pParms ){ 	tOCTVC1_RADIO_FREQUENCY_VALUE * pOCTVC1_RADIO_FREQUENCY_VALUE = (_f_pParms); SWAP_UNUSED(pOCTVC1_RADIO_FREQUENCY_VALUE)\
	{ mOCTVC1_RADIO_FREQ_UNIT_ENUM_SWAP( &((tOCTVC1_RADIO_FREQUENCY_VALUE *)pOCTVC1_RADIO_FREQUENCY_VALUE)->ulUnit ); }  \
	((tOCTVC1_RADIO_FREQUENCY_VALUE *)pOCTVC1_RADIO_FREQUENCY_VALUE)->ulValue = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_RADIO_FREQUENCY_VALUE *)pOCTVC1_RADIO_FREQUENCY_VALUE)->ulValue); \
}
#else
#define mOCTVC1_RADIO_FREQUENCY_VALUE_SWAP( pOCTVC1_RADIO_FREQUENCY_VALUE )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_ID_DIRECTION_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_ID_DIRECTION_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_RADIO_SWAP_H__ */
