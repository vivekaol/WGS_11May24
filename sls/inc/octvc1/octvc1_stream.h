/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_STREAM.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_STREAM_H__
#define __OCTVC1_STREAM_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Stream types
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_STREAM_DIRECTION_ENUM : 	Tap direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_STREAM_DIRECTION_ENUM						tOCT_UINT32

#define cOCTVC1_STREAM_DIRECTION_ENUM_TO_HOST				0		
#define cOCTVC1_STREAM_DIRECTION_ENUM_FROM_HOST				1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_STREAM_STATS
 		Stream stats

 Members:
	ulTransferDataSize
	ulDurationUs
	ulSentPacketCnt
	ulRecvPacketCnt
	ulRecvDropCnt
	ulRecvOverflowCnt
	ulRecvRetryCnt
	ulRecvMissCnt
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulTransferDataSize;
	tOCT_UINT32	ulDurationUs;
	tOCT_UINT32	ulSentPacketCnt;
	tOCT_UINT32	ulRecvPacketCnt;
	tOCT_UINT32	ulRecvDropCnt;
	tOCT_UINT32	ulRecvOverflowCnt;
	tOCT_UINT32	ulRecvRetryCnt;
	tOCT_UINT32	ulRecvMissCnt;

} tOCTVC1_STREAM_STATS;


#endif /* __OCTVC1_STREAM_H__ */

