/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_stream_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_STREAM_SWAP_H__
#define __OCTVC1_STREAM_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_swap_hdrs.h"
#include "octvc1_stream.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_STREAM_DIRECTION_ENUM_SWAP( pType ){ \
		*((tOCT_UINT32 *)pType) = mOCT_SWAP32_IF_LE( *((tOCT_UINT32 *)pType) ); }
#else

#define mOCTVC1_STREAM_DIRECTION_ENUM_SWAP( pType )

#endif /* _OCT_ENDIAN_TYPE_LE_ */

#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_STREAM_STATS_SWAP( _f_pParms ){ 	tOCTVC1_STREAM_STATS * pOCTVC1_STREAM_STATS = (_f_pParms); SWAP_UNUSED(pOCTVC1_STREAM_STATS)\
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulTransferDataSize = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulTransferDataSize); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulDurationUs = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulDurationUs); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulSentPacketCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulSentPacketCnt); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvPacketCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvPacketCnt); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvDropCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvDropCnt); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvOverflowCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvOverflowCnt); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvRetryCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvRetryCnt); \
	((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvMissCnt = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_STREAM_STATS *)pOCTVC1_STREAM_STATS)->ulRecvMissCnt); \
}
#else
#define mOCTVC1_STREAM_STATS_SWAP( pOCTVC1_STREAM_STATS )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_STREAM_SWAP_H__ */
