/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_GSM_API.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the definition of the RUS_GSM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_GSM_API_H__
#define __OCTVC1_RUS_GSM_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"

#include "octvc1_rus_gsm_id.h"
#include "octvc1_rus_gsm_rc.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	RUS GSM API constant definitions
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_GSM_UPLK_MAX_NUM_OF_MS_MEASUREMENTS		8		 	/* Maximum of number of simultaneous Ms measurments */
#define cOCTVC1_RUS_GSM_UL_MS_BUSRT_LENGTH					16		 	/* Length of the burst */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_GSM_BS_SEARCH_STATE_ENUM : 	Bs searcher process status.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_GSM_BS_SEARCH_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_RUS_GSM_BS_SEARCH_STATE_ENUM_NOTFOUND		0		
#define cOCTVC1_RUS_GSM_BS_SEARCH_STATE_ENUM_SEARCHING		1		
#define cOCTVC1_RUS_GSM_BS_SEARCH_STATE_ENUM_FOUND			2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_GSM_DNLK_BS_STATS

 Members:
	ulFrameNumber
		Range:		[0..2715647]
		Default:	0
 		Find Frame Number
	uSlotNumber
		Range:		[0..7]
		Default:	0
 		Find Slot Number
	State
 		UMNB State
	ulRelativeDelay
 		Relative Bs Delay (in symbol with Qn representation)
	lRTWPdBm
		Range:		[-700..100]
		Default:	-74181
 		Received Total Wideband Power in Q9 format
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32								ulFrameNumber;
	tOCT_UINT32								uSlotNumber;
	tOCTVC1_RUS_GSM_BS_SEARCH_STATE_ENUM	State;
	tOCT_UINT32								ulRelativeDelay;
	tOCT_INT32								lRTWPdBm;

} tOCTVC1_RUS_GSM_DNLK_BS_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_GSM_UPLK_MS_PRM

 Members:
	ulChannelNumber
		Range:		[0..7]
		Default:	0
 		Channel number specifying TS and Sub channel together
	ulMeasurementTimer
		Range:		[0..2715647]
		Default:	0
 		In Number of Radio Frames, Indicates the time difference between two
 		consecutive measurement reports
	HoppingEnableFlag
		Range:		[0..1]
		Default:	cOCT_FALSE
 		todo
	ulMA
		Range:		[0..7]
		Default:	0
 		Mobile allocation
	ulMAIO
		Range:		[0..7]
		Default:	0
 		Mobile Allocation Index Offset
	ulHSN
		Range:		[0..15]
		Default:	0
 		Hopping Sequence Index Offset
	ulTSC
		Range:		[0..7]
		Default:	0
 		Training Sequence Code
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulChannelNumber;
	tOCT_UINT32	ulMeasurementTimer;
	tOCT_BOOL32	HoppingEnableFlag;
	tOCT_UINT32	ulMA;
	tOCT_UINT32	ulMAIO;
	tOCT_UINT32	ulHSN;
	tOCT_UINT32	ulTSC;

} tOCTVC1_RUS_GSM_UPLK_MS_PRM;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_GSM_UPLK_MS_STATS

 Members:
	ulFrameNumber
		Range:		[0..2715647]
		Default:	0
 		Find Frame Number
	uSlotNumber
		Range:		[0..7]
		Default:	0
 		Find Slot Number
	lRTWPdBm
		Range:		[-700..100]
		Default:	-74181
 		Received Total Wideband Power in Q9 format
	lRSSIdBm
		Range:		[-700..100]
		Default:	-74181
 		Received Signal Strength in Q9 format
	lSNRdB
		Range:		[-700..100]
		Default:	-74181
 		Signal to Noise Ratio in Q9 format
	ulBER
		Range:		[0..10000]
		Default:	0
 		Bit Error Rate (x 10000)
	aulRawBurst
 		Raw Burst data after equalization. (symbols or bits ???)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulFrameNumber;
	tOCT_UINT32	uSlotNumber;
	tOCT_INT32	lRTWPdBm;
	tOCT_INT32	lRSSIdBm;
	tOCT_INT32	lSNRdB;
	tOCT_INT32	ulBER;
	tOCT_UINT32	aulRawBurst[cOCTVC1_RUS_GSM_UL_MS_BUSRT_LENGTH];

} tOCTVC1_RUS_GSM_UPLK_MS_STATS;

/*****************************  METHODS  *************************************/

/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_rus_gsm_evt.h"

#endif /* __OCTVC1_RUS_GSM_API_H__ */

