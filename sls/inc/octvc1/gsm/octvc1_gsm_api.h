/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_GSM_API.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the GSM API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_GSM_API_H__
#define __OCTVC1_GSM_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_fifo.h"
#include "../octvc1_file.h"
#include "../octvc1_radio.h"
#include "../octvc1_module.h"
#include "../octvc1_tap.h"

#include "octvc1_gsm_id.h"
#include "octvc1_gsm_rc.h"
#include "octvc1_gsm_lic.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	APP_TEST Application Module Id
-------------------------------------------------------------------------------------*/

#define cOCTVC1_GSM_APPLICATION_ID_MODULE_PHY				((0x00)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	
#define cOCTVC1_GSM_APPLICATION_ID_MODULE_TEST				((0x01)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	GSM Module Tap Id
-------------------------------------------------------------------------------------*/

#define cOCTVC1_GSM_TAP_ID_RF_UPLINK_INPUT					((0x0000)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|(cOCTVC1_GSM_APPLICATION_ID_MODULE_PHY<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	GSM Module Data Id
-------------------------------------------------------------------------------------*/

#define cOCTVC1_GSM_MODULE_DATA_ID_RF_UPLINK_INPUT_COMPLEX16	((0x0000)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	 	/* Deprecated */
 																		/* Should use cOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MID */


#define cOCTVC1_GSM_HOPPING_LIST_MAX_ENTRY					64		 	/* This is the maximum number of entries in a hopping list */
#define cOCTVC1_GSM_PHYSICAL_MIN_TIMESLOT_NUMBER			0		 	/* Minimum value of the Physical timeslot number. */
#define cOCTVC1_GSM_PHYSICAL_MAX_TIMESLOT_NUMBER			7		 	/* Maximum value of the Physical timeslot number. */
#define cOCTVC1_GSM_TRX_MAX_TIMESLOTS						(cOCTVC1_GSM_PHYSICAL_MAX_TIMESLOT_NUMBER+1)	 	/* This is the number of timeslots associated with a TRX. */
#define cOCTVC1_GSM_TIMESLOT_MIN_SUBCHANNEL_NUMBER			0		 	/* Minimum value of the timeslot sub-channel number. */
#define cOCTVC1_GSM_TIMESLOT_MAX_SUBCHANNEL_NUMBER			7		 	/* Maximum value of the timeslot sub-channel number. */
#define cOCTVC1_GSM_TIMESLOT_ALL_SUBCHANNEL_NUMBER			0xF1	 	/* Value used to specified an unused timeslot sub-channel. */
#define cOCTVC1_GSM_TIMESLOT_ALL_SUBCHANNEL_ENTRY_INDEX		8		 	/* Value used to specified the entry index used for ALL_SUBCHANNEL in subchannel */
 																		/* array. */
#define cOCTVC1_GSM_TIMESLOT_MAX_SUBCHANNEL					(cOCTVC1_GSM_TIMESLOT_MAX_SUBCHANNEL_NUMBER+2)	 	/* This is the number of subchannels associated with a timeslot. */
#define cOCTVC1_GSM_MAX_FRAME_COUNT							2715647	 	/* Max frame tick count. */
#define cOCTVC1_GSM_DATA_CONTENT_SIZE						460		 	/* Data content buffer size in bytes. */
#define cOCTVC1_GSM_DATA_CONTENT_SIZE_RAW_DI				464		 	/* Data content buffer size in bytes for RAW Data Indication. */
#define cOCTVC1_GSM_RATE_LIST_SIZE							4		 	/* Rate list size. */
#define cOCTVC1_GSM_RACH_IND_MSG_SIZE						32		 	/* RACH indication content buffer size. */
#define cOCTVC1_GSM_TRX_ID_LIST_MAX_ENTRY					32		 	/* Maximum number of TRX_ID per list. */
#define cOCTVC1_GSM_PHYSICAL_CHANNEL_ID_LIST_MAX_ENTRY		32		 	/* Maximum number of PHYSICAL_CHANNEL_ID per list. */
#define cOCTVC1_GSM_LOGICAL_CHANNEL_ID_LIST_MAX_ENTRY		128		 	/* Maximum number of LOGICAL_CHANNEL_ID per list. */
#define cOCTVC1_GSM_CIPHER_KEY_LENGTH						8		 	/* Cipher key bytes count. */
#define cOCTVC1_GSM_MAX_PDCH_DATA_BLOCKS					2		 	/* Max PDTCH Data Blocks for All MCS. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CMI_PHASE_ENUM : 	CMI phase.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_CMI_PHASE_ENUM							tOCT_UINT8

#define cOCTVC1_GSM_CMI_PHASE_ENUM_EVEN						0		
#define cOCTVC1_GSM_CMI_PHASE_ENUM_ODD						1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_AMR_CODEC_MODE_ENUM : 	AMR codec mode.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_AMR_CODEC_MODE_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_4_75			0x00	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_5_15			0x01	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_5_90			0x02	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_6_70			0x03	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_7_40			0x04	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_7_95			0x05	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_10_2			0x07	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_RATE_12_2			0x08	
#define cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET				0x0f	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_ID_DIRECTION_ENUM : 	Sub Channel Direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_ID_DIRECTION_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_ID_DIRECTION_ENUM_NONE					0		
#define cOCTVC1_GSM_ID_DIRECTION_ENUM_RX_BTS_MS				1		
#define cOCTVC1_GSM_ID_DIRECTION_ENUM_TX_BTS_MS				3		
#define cOCTVC1_GSM_ID_DIRECTION_ENUM_TX_RX_BTS_MS			4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_DIRECTION_ENUM : 	Sub Channel Direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_DIRECTION_ENUM							tOCT_UINT8

#define cOCTVC1_GSM_DIRECTION_ENUM_NONE						cOCTVC1_GSM_ID_DIRECTION_ENUM_NONE	
#define cOCTVC1_GSM_DIRECTION_ENUM_RX_BTS_MS				cOCTVC1_GSM_ID_DIRECTION_ENUM_RX_BTS_MS	
#define cOCTVC1_GSM_DIRECTION_ENUM_TX_BTS_MS				cOCTVC1_GSM_ID_DIRECTION_ENUM_TX_BTS_MS	
#define cOCTVC1_GSM_DIRECTION_ENUM_TX_RX_BTS_MS				cOCTVC1_GSM_ID_DIRECTION_ENUM_TX_RX_BTS_MS	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_ID_TIMESLOT_NB_ENUM : 	Time slot number.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_ID_TIMESLOT_NB_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0					0		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_1					1		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_2					2		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_3					3		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_4					4		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_5					5		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_6					6		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_7					7		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TIMESLOT_NB_ENUM : 	Time slot number.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TIMESLOT_NB_ENUM						tOCT_UINT32

#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_0						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_1						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_1	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_2						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_2	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_3						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_3	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_4						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_4	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_5						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_5	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_6						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_6	
#define cOCTVC1_GSM_TIMESLOT_NB_ENUM_7						cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_7	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM : 	Time slot number.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM				tOCT_UINT8

#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_0				0		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_1				1		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_2				2		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_3				3		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_4				4		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_5				5		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_6				6		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_7				7		
#define cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_ALL			0xFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM : 	DLOM OR DLIM
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM					tOCT_UINT8

#define cOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM_NONE				0		
#define cOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM_DLOM				1		
#define cOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM_DLIM				2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CAPTURE_TYPE_ENUM : 	WRAP AROUND OR NOT
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_CAPTURE_TYPE_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_CAPTURE_TYPE_ENUM_NONE					0		
#define cOCTVC1_GSM_CAPTURE_TYPE_ENUM_ONE_TIME_CAPTURE		1		
#define cOCTVC1_GSM_CAPTURE_TYPE_ENUM_WRAP_AROUND_CAPTURE	2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CAPTURE_STATUS_ENUM : 	STATUS OF CAPTURE
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_CAPTURE_STATUS_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_CAPTURE_STATUS_ENUM_IDLE				0		
#define cOCTVC1_GSM_CAPTURE_STATUS_ENUM_RUNNING				1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM : 	Time slot number.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM					tOCT_UINT32

#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_0					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_0	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_1					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_1	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_2					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_2	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_3					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_3	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_4					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_4	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_5					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_5	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_6					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_6	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_7					cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_7	
#define cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_ALL				cOCTVC1_GSM_ID_TIMESLOT_NB_STUB_ENUM_ALL	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_ID_STUB_MODE_ENUM : 	Sub Channel Direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_ID_STUB_MODE_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_ID_STUB_MODE_ENUM_NONE					0		
#define cOCTVC1_GSM_ID_STUB_MODE_ENUM_IQ_DATA_CAPTURE		1		
#define cOCTVC1_GSM_ID_STUB_MODE_ENUM_IQ_DATA_STUB			2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_STUB_MODE_ENUM : 	Sub Channel Direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_STUB_MODE_ENUM							tOCT_UINT8

#define cOCTVC1_GSM_STUB_MODE_ENUM_NONE						cOCTVC1_GSM_ID_STUB_MODE_ENUM_NONE	
#define cOCTVC1_GSM_STUB_MODE_ENUM_IQ_DATA_CAPTURE			cOCTVC1_GSM_ID_STUB_MODE_ENUM_IQ_DATA_CAPTURE	
#define cOCTVC1_GSM_STUB_MODE_ENUM_IQ_DATA_STUB				cOCTVC1_GSM_ID_STUB_MODE_ENUM_IQ_DATA_STUB	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_HEADER_CAPTURE_ENUM : 	TRUE OR FALSE
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_HEADER_CAPTURE_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_HEADER_CAPTURE_ENUM_TRUE				0		
#define cOCTVC1_GSM_HEADER_CAPTURE_ENUM_FALSE				1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CAPTURE_MODE_ENUM : 	WETHER TO CAPTURE OR TO STUB
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_CAPTURE_MODE_ENUM						tOCT_UINT8

#define cOCTVC1_GSM_CAPTURE_MODE_ENUM_NONE					cOCTVC1_GSM_ID_STUB_MODE_ENUM_NONE	
#define cOCTVC1_GSM_CAPTURE_MODE_ENUM_IQ_DATA_CAPTURE		cOCTVC1_GSM_ID_STUB_MODE_ENUM_IQ_DATA_CAPTURE	
#define cOCTVC1_GSM_CAPTURE_MODE_ENUM_IQ_DATA_STUB			cOCTVC1_GSM_ID_STUB_MODE_ENUM_IQ_DATA_STUB	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM : 	Sub Channel number.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM					tOCT_UINT8

#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0				0		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_1				1		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_2				2		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_2				2		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_3				3		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_4				4		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_5				5		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_6				6		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_7				7		
#define cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_ALL				0xF1	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_SUB_CHANNEL_NB_ENUM : 	Sub Channel number.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_SUB_CHANNEL_NB_ENUM						tOCT_UINT32

#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_0					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_1					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_1	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_2					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_2	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_3					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_3	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_4					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_4	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_5					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_5	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_6					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_6	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_7					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_7	
#define cOCTVC1_GSM_SUB_CHANNEL_NB_ENUM_ALL					cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_ALL	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CIPHERING_ID_ENUM : 	Sub Channel Direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_CIPHERING_ID_ENUM						tOCT_UINT32

#define cOCTVC1_GSM_CIPHERING_ID_ENUM_UNUSED				0		
#define cOCTVC1_GSM_CIPHERING_ID_ENUM_A5_0					1		
#define cOCTVC1_GSM_CIPHERING_ID_ENUM_A5_1					2		
#define cOCTVC1_GSM_CIPHERING_ID_ENUM_A5_2					3		
#define cOCTVC1_GSM_CIPHERING_ID_ENUM_A5_3					4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_SUBCHANNEL_MASK : 	Sub channel Mask.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_SUBCHANNEL_MASK							tOCT_UINT32

#define cOCTVC1_GSM_SUBCHANNEL_MASK_0						((tOCT_UINT32)(1<<0) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_1						((tOCT_UINT32)(1<<1) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_2						((tOCT_UINT32)(1<<2) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_3						((tOCT_UINT32)(1<<3) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_4						((tOCT_UINT32)(1<<4) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_5						((tOCT_UINT32)(1<<5) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_6						((tOCT_UINT32)(1<<6) )	
#define cOCTVC1_GSM_SUBCHANNEL_MASK_7						((tOCT_UINT32)(1<<7) )	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TEST_MODE_ENUM : 	TEST MODE OPTIONS.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TEST_MODE_ENUM							tOCT_UINT8

#define cOCTVC1_GSM_TEST_MODE_ENUM_TEST_MODE_NONE			0		
#define cOCTVC1_GSM_TEST_MODE_ENUM_TEST_MODE_TX				1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM : 	TX TEST MODE BURST SELECTION.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM				tOCT_UINT8

#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_0		0		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_1		1		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_2		2		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_3		3		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_4		4		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_5		5		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_6		6		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_BURST_7		7		
#define cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND		8		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MODULATION_ENUM : 	modulation types.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_MODULATION_ENUM							tOCT_UINT8

#define cOCTVC1_GSM_MODULATION_ENUM_GMSK					0		
#define cOCTVC1_GSM_MODULATION_ENUM_EPSK					1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_BURST_TYPE_ENUM : 	Burst type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_BURST_TYPE_ENUM							tOCT_UINT32

#define cOCTVC1_GSM_BURST_TYPE_ENUM_SYNC					0		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_NORMAL					1		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_DUMMY					2		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_NORMAL_8PSK				3		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_ACCESS_TRAINING_0		4		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_ACCESS_TRAINING_1		5		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_ACCESS_TRAINING_2		6		
#define cOCTVC1_GSM_BURST_TYPE_ENUM_FREQ_CORRECTION			7		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM : 	Timeslot channel type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM										tOCT_UINT32

#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_EMPTY										0		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_TCHF_FACCHF_SACCHTF						1		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_TCHH_FACCHH_SACCHTH						2		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_FCCH_SCH_BCCH_CCCH							3		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4			4		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_SDCCH8_SACCHC8								5		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_FCCH_SCH_BCCH_CCCH_SDCCH4_CBCH_SACCHC4		6		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_SDCCH8_CBCH_SACCHC8						7		
#define cOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM_PDTCHF_PACCHF_PTCCHF						8		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_PAYLOAD_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_PAYLOAD_TYPE_ENUM						tOCT_UINT32

#define cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE					0		
#define cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_FULL_RATE				1		
#define cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_ENH_FULL_RATE			2		
#define cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_HALF_RATE				3		
#define cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_AMR_FULL_RATE			4		
#define cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_AMR_HALF_RATE			5		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_SAPI_ENUM : 	Timeslot channel type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_SAPI_ENUM								tOCT_UINT8

#define cOCTVC1_GSM_SAPI_ENUM_IDLE							0		
#define cOCTVC1_GSM_SAPI_ENUM_FCCH							1		 	/* Frequency Correction burst pseudo-Channel */
#define cOCTVC1_GSM_SAPI_ENUM_SCH							2		 	/* Synchronization channel */
#define cOCTVC1_GSM_SAPI_ENUM_SACCH							3		 	/* Slow Associated Control Channel */
#define cOCTVC1_GSM_SAPI_ENUM_SDCCH							4		 	/* Stand-Alone Dedicated Control Channel */
#define cOCTVC1_GSM_SAPI_ENUM_BCCH							5		 	/* Broadcast Control Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PCH_AGCH						7		 	/* Paging and Access Grant Channel */
#define cOCTVC1_GSM_SAPI_ENUM_CBCH							8		 	/* Cell Broadcast Channel */
#define cOCTVC1_GSM_SAPI_ENUM_RACH							9		 	/* Random Access Channel */
#define cOCTVC1_GSM_SAPI_ENUM_TCHF							10		 	/* Full rate speech TCH */
#define cOCTVC1_GSM_SAPI_ENUM_FACCHF						11		 	/* Full rate FACCH */
#define cOCTVC1_GSM_SAPI_ENUM_TCHH							12		 	/* Half rate speech TCH */
#define cOCTVC1_GSM_SAPI_ENUM_FACCHH						13		 	/* Half rate FACCH */
#define cOCTVC1_GSM_SAPI_ENUM_NCH							14		 	/* Notification Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PDTCH							15		 	/* EGPRS Packet Data Traffic Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PACCH							16		 	/* EGPRS Packet Associated Control Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PBCCH							17		 	/* EGPRS Packet Broadcast Control Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PAGCH							18		 	/* EGPRS Packet Access Grant Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PPCH							19		 	/* EGPRS Packet Paging Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PNCH							20		 	/* EGPRS Packet Notification Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PTCCH							21		 	/* EGPRS Packet Timing advance Control Channel */
#define cOCTVC1_GSM_SAPI_ENUM_PRACH							22		 	/* EGPRS Packet Random Access Channel */

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_SAPI_MASK : 	SAPI_MASK
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_SAPI_MASK								tOCT_UINT32

#define cOCTVC1_GSM_SAPI_MASK_IDLE							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_IDLE) )	
#define cOCTVC1_GSM_SAPI_MASK_FCCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_FCCH) )	
#define cOCTVC1_GSM_SAPI_MASK_SCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_SCH) )	
#define cOCTVC1_GSM_SAPI_MASK_SACCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_SACCH) )	
#define cOCTVC1_GSM_SAPI_MASK_SDCCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_SDCCH) )	
#define cOCTVC1_GSM_SAPI_MASK_BCCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_BCCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PCH_AGCH						((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PCH_AGCH) )	
#define cOCTVC1_GSM_SAPI_MASK_CBCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_CBCH) )	
#define cOCTVC1_GSM_SAPI_MASK_RACH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_RACH) )	
#define cOCTVC1_GSM_SAPI_MASK_TCHF							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_TCHF) )	
#define cOCTVC1_GSM_SAPI_MASK_FACCHF						((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_FACCHF) )	
#define cOCTVC1_GSM_SAPI_MASK_TCHH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_TCHH) )	
#define cOCTVC1_GSM_SAPI_MASK_FACCHH						((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_FACCHH) )	
#define cOCTVC1_GSM_SAPI_MASK_NCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_NCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PDTCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PDTCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PACCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PACCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PBCCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PBCCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PAGCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PAGCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PPCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PPCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PNCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PNCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PTCCH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PTCCH) )	
#define cOCTVC1_GSM_SAPI_MASK_PRACH							((tOCT_UINT32)(1<<cOCTVC1_GSM_SAPI_ENUM_PRACH) )	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TRX_ID

 Members:
	byTrxId
		Default:	0
	abyPad
 		Reserved to align following member.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT8	byTrxId;
	tOCT_UINT8	abyPad[3];

} tOCTVC1_GSM_TRX_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TRX_ID_CURSOR

 Members:
	TrxId
		Default:	0
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_TRX_ID_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TRX_ID_GET_CURSOR

 Members:
	TrxId
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TRX_ID			TrxId;
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;

} tOCTVC1_GSM_TRX_ID_GET_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK : 	TRX_BAND
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK				tOCT_UINT16

#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TRX_ID_BIT0	((tOCT_UINT16)(1<<15) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TRX_ID_BIT1	((tOCT_UINT16)(1<<14) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TRX_ID_BIT2	((tOCT_UINT16)(1<<13) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TRX_ID_BIT3	((tOCT_UINT16)(1<<12) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TRX_ID_BIT4	((tOCT_UINT16)(1<<11) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TRX_ID_BIT5	((tOCT_UINT16)(1<<10) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_BAND_BIT0		((tOCT_UINT16)(1<<9) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_BAND_BIT1		((tOCT_UINT16)(1<<8) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_BAND_BIT2		((tOCT_UINT16)(1<<7) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_BAND_BIT3		((tOCT_UINT16)(1<<6) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_HOPPING		((tOCT_UINT16)(1<<5) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TSC_BIT0		((tOCT_UINT16)(1<<4) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TSC_BIT1		((tOCT_UINT16)(1<<3) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TSC_BIT2		((tOCT_UINT16)(1<<2) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TSC_BIT3		((tOCT_UINT16)(1<<1) )	
#define cOCTVC1_GSM_TRX_BAND_HOPPING_TSC_MASK_TSC_BIT4		((tOCT_UINT16)(1<<0) )	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_RF_CONFIG
 		RF configuration

 Members:
	ulRxGainDb
		Range:		[0..73]
		Default:	70
 		Rx Gain Db (1 dB step)
	ulTxAttndB
		Range:		[0..359]
 		Tx attenuation Db. (in 1/4 dB)
	ulTxAntennaId
		Range:		[0..1]
		Default:	0
 		TX Antenna Index
	ulRxAntennaId
		Range:		[0..1]
		Default:	0
 		RX Antenna Index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulRxGainDb;
	tOCT_UINT32	ulTxAttndB;
	tOCT_UINT32	ulTxAntennaId;
	tOCT_UINT32	ulRxAntennaId;

} tOCTVC1_GSM_RF_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TRX_CONFIG

 Members:
	ulBand
	usTsc
		Range:		[0..31]
		Default:	0
	usArfcn
	usBcchArfcn
	usCentreArfcn
	usHsn
	usMaio
	ausReserve
	ulHoppingFlag
	ulHoppingListLength
	ausHoppingList
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM	ulBand;
	tOCT_UINT16									usTsc;
	tOCT_UINT16									usArfcn;
	tOCT_UINT16									usBcchArfcn;
	tOCT_UINT16									usCentreArfcn;
	tOCT_UINT16									usHsn;
	tOCT_UINT16									usMaio;
	tOCT_UINT16									ausReserve[2];
	tOCT_BOOL32									ulHoppingFlag;
	tOCT_UINT32									ulHoppingListLength;
	tOCT_UINT16									ausHoppingList[cOCTVC1_GSM_HOPPING_LIST_MAX_ENTRY];

} tOCTVC1_GSM_TRX_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TRX_STATUS_ENUM : 	Timeslot channel type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TRX_STATUS_ENUM							tOCT_UINT32

#define cOCTVC1_GSM_TRX_STATUS_ENUM_INVALID					0		
#define cOCTVC1_GSM_TRX_STATUS_ENUM_RADIO_READY				1		
#define cOCTVC1_GSM_TRX_STATUS_ENUM_RADIO_ERROR				2		
#define cOCTVC1_GSM_TRX_STATUS_ENUM_PROCESSING_STOP			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID

 Members:
	byTimeslotNb
		Default:	cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0
 		Timeslot number.
	abyPad
 		Reserved to align following member.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_ID_TIMESLOT_NB_ENUM	byTimeslotNb;
	tOCT_UINT8						abyPad[3];

} tOCTVC1_GSM_PHYSICAL_CHANNEL_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_CURSOR

 Members:
	PchId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_GET_CURSOR

 Members:
	TrxId
	PchId
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCTVC1_OBJECT_CURSOR_ENUM		ulGetMode;

} tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_GET_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_SUBCHANNEL_STATUS

 Members:
	ulSubchannelNb
 		Sub Channel Number
	ulActiveUplinkSAPIMask
	ulActiveDownlinkSAPIMask
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32				ulSubchannelNb;
	tOCTVC1_GSM_SAPI_MASK	ulActiveUplinkSAPIMask;
	tOCTVC1_GSM_SAPI_MASK	ulActiveDownlinkSAPIMask;

} tOCTVC1_GSM_SUBCHANNEL_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CIPHER_CONFIG

 Members:
	ulCipherId
	abyKey
 		Cipher Key
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_CIPHERING_ID_ENUM	ulCipherId;
	tOCT_UINT8						abyKey[cOCTVC1_GSM_CIPHER_KEY_LENGTH];

} tOCTVC1_GSM_CIPHER_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_STUB_STATUS
 		Buffer address

 Members:
	byTimeslotUsed
		Range:		[0..65536]
		Default:	0
 		Adress of Real Pointer
	byStubMode
 		STUB_MODE_ENUM.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16					byTimeslotUsed;
	tOCTVC1_GSM_STUB_MODE_ENUM	byStubMode;

} tOCTVC1_GSM_STUB_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_STUB_CHANNEL_ID

 Members:
	byTimeslotNb
		Default:	cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_0
 		Timeslot number.
	bySubChannelNb
		Default:	cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0
 		Sub-Channel number.
	bySAPI
		Default:	cOCTVC1_GSM_SAPI_ENUM_TCHF
 		CHANNEL_TYPE.
	byStubMode
		Default:	cOCTVC1_GSM_STUB_MODE_ENUM_NONE
 		STUB_MODE_ENUM.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM	byTimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	bySubChannelNb;
	tOCTVC1_GSM_SAPI_ENUM				bySAPI;
	tOCTVC1_GSM_STUB_MODE_ENUM			byStubMode;

} tOCTVC1_GSM_STUB_CHANNEL_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_CAPTURE_CHANNEL_ID

 Members:
	byTimeslotNb
		Default:	cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_0
 		Timeslot number.
	bySubChannelNb
		Default:	cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0
 		Sub-Channel number.
	byCAPTUREMode
		Default:	cOCTVC1_GSM_CAPTURE_MODE_ENUM_NONE
 		CAPTURE_MODE_ENUM.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM	byTimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	bySubChannelNb;
	tOCTVC1_GSM_CAPTURE_MODE_ENUM		byCAPTUREMode;

} tOCTVC1_GSM_CAPTURE_CHANNEL_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID

 Members:
	byTimeslotNb
		Default:	cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0
 		Timeslot number.
	bySubChannelNb
		Default:	cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0
 		Sub-Channel number.
	bySAPI
 		Access Point Identifier.
	byDirection
 		Channel direction.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_ID_TIMESLOT_NB_ENUM		byTimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	bySubChannelNb;
	tOCTVC1_GSM_SAPI_ENUM				bySAPI;
	tOCTVC1_GSM_ID_DIRECTION_ENUM		byDirection;

} tOCTVC1_GSM_LOGICAL_CHANNEL_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID_CURSOR

 Members:
	LchId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_LOGICAL_CHANNEL_ID_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID_GET_CURSOR

 Members:
	TrxId
	LchId
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCTVC1_OBJECT_CURSOR_ENUM		ulGetMode;

} tOCTVC1_GSM_LOGICAL_CHANNEL_ID_GET_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_CONFIG

 Members:
	byTimingAdvance
	byBSIC
	byCmiPhase
	byInitRate
		Default:	cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET
	abyRate
		Default:	cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT8						byTimingAdvance;
	tOCT_UINT8						byBSIC;
	tOCTVC1_GSM_CMI_PHASE_ENUM		byCmiPhase;
	tOCTVC1_GSM_AMR_CODEC_MODE_ENUM	byInitRate;
	tOCTVC1_GSM_AMR_CODEC_MODE_ENUM	abyRate[cOCTVC1_GSM_RATE_LIST_SIZE];

} tOCTVC1_GSM_LOGICAL_CHANNEL_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_DATA

 Members:
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
	ulPayloadType
		Default:	cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE
	ulDataLength
		Range:		[..cOCTVC1_GSM_DATA_CONTENT_SIZE]
	abyEgprsCrc
 		EGPRS CRC Status for Max PDCH Data Blocks.
	ucInvertedCrcSpeechFlag
	abyPadding
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulFrameNumber;
	tOCTVC1_GSM_PAYLOAD_TYPE_ENUM	ulPayloadType;
	tOCT_UINT32						ulDataLength;
	tOCT_UINT8						abyEgprsCrc[cOCTVC1_GSM_MAX_PDCH_DATA_BLOCKS];
	tOCT_UINT8						ucInvertedCrcSpeechFlag;
	tOCT_UINT8						ucTbfStartIndicationBitMap;
	tOCT_UINT8						abyPadding[4];

} tOCTVC1_GSM_LOGICAL_CHANNEL_DATA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_LOGICAL_CHANNEL_RAW_DATA

 Members:
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
	ulDataLength
		Range:		[..cOCTVC1_GSM_DATA_CONTENT_SIZE_RAW_DI]
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulFrameNumber;
	tOCT_UINT32	ulDataLength;

} tOCTVC1_GSM_LOGICAL_CHANNEL_RAW_DATA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MEASUREMENT_INFO

 Members:
	sSNRDb
	sRSSIDbm
	sBurstTiming
	sBurstTiming4x
	usBERCnt
	usBERTotalBitCnt
	uLMeanBep
	uLCVBep
	uLReserved1
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT16	sSNRDb;
	tOCT_INT16	sRSSIDbm;
	tOCT_INT16	sBurstTiming;
	tOCT_INT16	sBurstTiming4x;
	tOCT_UINT16	usBERCnt;
	tOCT_UINT16	usBERTotalBitCnt;
	tOCT_UINT32	uLMeanBep;
	tOCT_UINT16	uLCVBep;
	tOCT_UINT16	uLReserved1;

} tOCTVC1_GSM_MEASUREMENT_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_RAW_MEASUREMENT_INFO

 Members:
	sSNRDb
	sRSSIDbm
	sBurstTiming
	sBurstTiming4x
	usBERCnt
	usBERTotalBitCnt
	usTrSqErrCnt
	usTrSqTotalBitCnt
	sFreqErrHz
	usReserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT16	sSNRDb;
	tOCT_INT16	sRSSIDbm;
	tOCT_INT16	sBurstTiming;
	tOCT_INT16	sBurstTiming4x;
	tOCT_UINT16	usBERCnt;
	tOCT_UINT16	usBERTotalBitCnt;
	tOCT_UINT16	usTrSqErrCnt;
	tOCT_UINT16	usTrSqTotalBitCnt;
	tOCT_INT16	sFreqErrHz;
	tOCT_UINT16	usReserved;

} tOCTVC1_GSM_RAW_MEASUREMENT_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TIMESLOT_POWER

 Members:
	ulPowerMax
	ulPowerAverage
	ulCount
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulPowerMax;
	tOCT_UINT32	ulPowerAverage;
	tOCT_UINT32	ulCount;

} tOCTVC1_GSM_TIMESLOT_POWER;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_PHYSICAL_STATUS

 Members:
	ulChannelType
	ulSubchannelCount
	ulTchDataCrcPassCount
	ulTchDataCrcFailCount
	ulRachCount
	aulPdtchCrcPassCount
	aulPdtchCrcFailCount
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM	ulChannelType;
	tOCT_UINT32										ulSubchannelCount;
	tOCT_UINT32										ulTchDataCrcPassCount;
	tOCT_UINT32										ulTchDataCrcFailCount;
	tOCT_UINT32										ulRachCount;
	tOCT_UINT32										aulPdtchCrcPassCount[cOCTVC1_GSM_MAX_PDCH_DATA_BLOCKS];
	tOCT_UINT32										aulPdtchCrcFailCount[cOCTVC1_GSM_MAX_PDCH_DATA_BLOCKS];

} tOCTVC1_GSM_PHYSICAL_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TIMESLOT_STATUS

 Members:
	PhysicalStatus
	UplinkPower
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_PHYSICAL_STATUS	PhysicalStatus;
	tOCTVC1_GSM_TIMESLOT_POWER	UplinkPower;

} tOCTVC1_GSM_TIMESLOT_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_DL_STATUS

 Members:
	ulElapseRspCmdMaxUs
 		Max elapse time waiting for DL process Rsp
	ulElapseRspCmdAvgUs
 		Avg Elapse time waiting for DL process Rsp
	ulExpectedDelayExceedCnt
 		Nb of time TX buffer is not filled fast enough.(Should be 0)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulElapseRspCmdMaxUs;
	tOCT_UINT32	ulElapseRspCmdAvgUs;
	tOCT_UINT32	ulExpectedDelayExceedCnt;

} tOCTVC1_GSM_DL_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_UL_STATUS

 Members:
	ulExceedByteMaxCnt
 		Max exceed data count...Expecting 2512.
	ulExpectedDataExceedCnt
 		Nb of time data count present was higher than a slot.(Should be 0)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulExceedByteMaxCnt;
	tOCT_UINT32	ulExpectedDataExceedCnt;

} tOCTVC1_GSM_UL_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_SCHED_STATUS

 Members:
	ulErrorDataInactiveCnt
 		Trying to schedule logical channel without available data.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulErrorDataInactiveCnt;

} tOCTVC1_GSM_SCHED_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_TYPE_ENUM : 	GSM Filer type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TAP_FILTER_TYPE_ENUM					tOCT_UINT32

#define cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_NONE				0		
#define cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_TRX				1		
#define cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_PHYSICAL_CHANNEL	2		
#define cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_LOGICAL_CHANNEL	3		

#define cOCTVC1_GSM_TAP_FILTER_TAP_COUNT_MAX				16		 	/* This is the maximum number of tap that can be associated to a FILTER */
#define cOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL_ENTRY_COUNT_MAX	8		 	/* This is the maximum number of entries in a tap physical channel array */
#define cOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL_ENTRY_COUNT_MAX	8		 	/* This is the maximum number of entries in a tap logical channel array */

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL_ENTRY

 Members:
	TrxId
 		Specify TrxId to tap
	PchId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL_ENTRY;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL_ENTRY

 Members:
	TrxId
 		Specify TrxId to tap
	LchId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL_ENTRY;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_MASK : 	GSM tap filter mask channel Mask.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_GSM_TAP_FILTER_MASK							tOCT_UINT32

#define cOCTVC1_GSM_TAP_FILTER_MASK_NONE					0		
#define cOCTVC1_GSM_TAP_FILTER_MASK_REMOVE_REJECTED_DATA	((tOCT_UINT32)(1<<0) )	

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_TRX

 Members:
	ulAllTrxFlag
		Default:	cOCT_FALSE
 		If cOCT_TRUE, will tap all TRX.Value in TrxId will not be used
 		If cOCT_FALSE, only tap TRX specify in TrxId
	TrxId
 		Specify TrxId to tap
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32			ulAllTrxFlag;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_TAP_FILTER_TRX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL

 Members:
	ulEntryCnt
		Range:		[0..cOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL_ENTRY_COUNT_MAX]
		Default:	0
 		Number of Physical to TAP
 		If 0, no one will be tap
	aEntry
 		Physical Tap filter array .
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32										ulEntryCnt;
	tOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL_ENTRY	aEntry[cOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL_ENTRY_COUNT_MAX];

} tOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL

 Members:
	ulEntryCnt
		Range:		[0..cOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL_ENTRY_COUNT_MAX]
		Default:	0
 		Number of Logical to TAP
 		If 0, no one will be tap
	aEntry
 		Logical Tap filter array .
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32										ulEntryCnt;
	tOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL_ENTRY	aEntry[cOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL_ENTRY_COUNT_MAX];

} tOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER

 Members:
	ulType
		Default:	cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_NONE
 		GSM Tap filter type.
	ulMask
		Default:	cOCTVC1_GSM_TAP_FILTER_MASK_NONE
 		GSM Tap filter mask.
	Trx
 		GSM Tap filter structure when type cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_TRX is used.
	PhysicalChannel
 		GSM Tap filter structure when type
 		cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_PHYSICAL_CHANNEL is used.
	LogicalChannel
 		GSM Tap filter structure when type
 		cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_LOGICAL_CHANNEL is used.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_GSM_TAP_FILTER_TYPE_ENUM		ulType;
	tOCTVC1_GSM_TAP_FILTER_MASK				ulMask;
	tOCTVC1_GSM_TAP_FILTER_TRX				Trx;
	tOCTVC1_GSM_TAP_FILTER_PHYSICAL_CHANNEL	PhysicalChannel;
	tOCTVC1_GSM_TAP_FILTER_LOGICAL_CHANNEL	LogicalChannel;

} tOCTVC1_GSM_TAP_FILTER;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_TAP_FILTER_STATS

 Members:
	ulTapIdCnt
		Range:		[0..cOCTVC1_GSM_TAP_FILTER_TAP_COUNT_MAX]
		Default:	0
 		Number tap using this filter
	ahTapId
 		Array of TapId using this filter
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulTapIdCnt;
	tOCT_UINT32	ahTapId[cOCTVC1_GSM_TAP_FILTER_TAP_COUNT_MAX];

} tOCTVC1_GSM_TAP_FILTER_STATS;

/*-------------------------------------------------------------------------------------
 	Deprecated
 	Should use tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MODULE_DATA_RF_UPLINK_INPUT_HEADER

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Logical Channel identifier
	ulAntennaIndex
 		Antenna index
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
	ulPower
	ulDataSizeInBytes
	byBadFlag
	byBurstId
	byReserved0
	byReserved1
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA				ModuleData;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCTVC1_INDEX					ulAntennaIndex;
	tOCT_UINT32						ulFrameNumber;
	tOCT_UINT32						ulPower;
	tOCT_UINT32						ulDataSizeInBytes;
	tOCT_UINT8						byBadFlag;
	tOCT_UINT8						byBurstId;
	tOCT_UINT8						byReserved0;
	tOCT_UINT8						byReserved1;

} tOCTVC1_GSM_MODULE_DATA_RF_UPLINK_INPUT_HEADER;

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_OPEN_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulRfPortIndex
 		Unique RF port identifier
	TrxId
 		Logical identifier for TRX
	Config
 		TRX configuration
	RfConfig
 		RF configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulRfPortIndex;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_GSM_TRX_CONFIG	Config;
	tOCTVC1_GSM_RF_CONFIG	RfConfig;

} tOCTVC1_GSM_MSG_TRX_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	hGsm
 		Unique GSM identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_HANDLE_OBJECT	hGsm;

} tOCTVC1_GSM_MSG_TRX_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_CLOSE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	ulResetFlag
 		Reset timeslot stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;
	tOCT_BOOL32			ulResetFlag;

} tOCTVC1_GSM_MSG_TRX_STATUS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	DlStatus
	UlStatus
	SchedStatus
	aTSlotStatus
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_GSM_TRX_ID			TrxId;
	tOCTVC1_GSM_DL_STATUS		DlStatus;
	tOCTVC1_GSM_UL_STATUS		UlStatus;
	tOCTVC1_GSM_SCHED_STATUS	SchedStatus;
	tOCTVC1_GSM_TIMESLOT_STATUS	aTSlotStatus[cOCTVC1_GSM_TRX_MAX_TIMESLOTS];

} tOCTVC1_GSM_MSG_TRX_STATUS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	ulRfPortIndex
 		Selected RF port index
	Config
 		TRX configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_INDEX			ulRfPortIndex;
	tOCTVC1_GSM_TRX_CONFIG	Config;

} tOCTVC1_GSM_MSG_TRX_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RESET_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_RESET_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RESET_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_RESET_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	Config
 		TRX configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_GSM_TRX_CONFIG	Config;

} tOCTVC1_GSM_MSG_TRX_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_LIST_CMD

 Members:
	Header
	TrxIdCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID_GET_CURSOR	TrxIdCursor;

} tOCTVC1_GSM_MSG_TRX_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_LIST_RSP

 Members:
	Header
	TrxIdCursor
 		Object Cursor.
	ulNumTrxId
 		Number of valid TrxId in aTrxId
	aTrxId
 		Array containing the listed TrxId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID_GET_CURSOR	TrxIdCursor;
	tOCT_UINT32						ulNumTrxId;
	tOCTVC1_GSM_TRX_ID_CURSOR		aTrxId[cOCTVC1_GSM_TRX_ID_LIST_MAX_ENTRY];

} tOCTVC1_GSM_MSG_TRX_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulCloseCount
 		Number of TRX closed.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulCloseCount;

} tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_RECORD_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_START_RECORD_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_RECORD_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_STOP_RECORD_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Logical Channel identifier
	Config
 		Logical channel config
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID		LchId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_CONFIG	Config;

} tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	usStatus
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCT_UINT16						usStatus;

} tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	Config
 		Logical channel config
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID		LchId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_CONFIG	Config;

} tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD

 Members:
	Header
	LchIdCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID_GET_CURSOR	LchIdCursor;

} tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_RSP

 Members:
	Header
	LchIdCursor
 		Object Cursor.
	ulNumLchId
 		Number of valid LchId in aLchId
	aLchId
 		Array containing the listed PchId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID_GET_CURSOR	LchIdCursor;
	tOCT_UINT32									ulNumLchId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID_CURSOR		aLchId[cOCTVC1_GSM_LOGICAL_CHANNEL_ID_LIST_MAX_ENTRY];

} tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
	ulChannelType
	ulPayloadType
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_GSM_TRX_ID								TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID					PchId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM	ulChannelType;
	tOCTVC1_GSM_PAYLOAD_TYPE_ENUM					ulPayloadType;

} tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	ulResetFlag
 		Reset physical stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCT_BOOL32						ulResetFlag;

} tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	PhysicalStatus
	aSubchannnelStatus
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCTVC1_GSM_PHYSICAL_STATUS		PhysicalStatus;
	tOCTVC1_GSM_SUBCHANNEL_STATUS	aSubchannnelStatus[cOCTVC1_GSM_TIMESLOT_MAX_SUBCHANNEL];

} tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD
 		Reset all associated Physical Channel.

 Members:
	Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_RSP

 Members:
	Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD

 Members:
	Header
	PchIdCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_GET_CURSOR	PchIdCursor;

} tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_RSP

 Members:
	Header
	PchIdCursor
 		Object Cursor.
	ulNumPchId
 		Number of valid PchId in aPchId
	aPchId
 		Array containing the listed PchId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_GET_CURSOR	PchIdCursor;
	tOCT_UINT32									ulNumPchId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID_CURSOR		aPchId[cOCTVC1_GSM_PHYSICAL_CHANNEL_ID_LIST_MAX_ENTRY];

} tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	ulChannelType
	ulPayloadType
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_GSM_TRX_ID								TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID					PchId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_COMBINATION_ENUM	ulChannelType;
	tOCTVC1_GSM_PAYLOAD_TYPE_ENUM					ulPayloadType;

} tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	ulSubchannelNb
 		Sub Channel Number
	Config
 		Cipher configuration
	ulDirection
 		Channel direction.
	abyPad
 		Reserved to align following member.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCTVC1_GSM_SUB_CHANNEL_NB_ENUM	ulSubchannelNb;
	tOCTVC1_GSM_CIPHER_CONFIG		Config;
	tOCTVC1_GSM_DIRECTION_ENUM		ulDirection;
	tOCT_UINT8						abyPad[7];

} tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	ulSubchannelNb
 		Sub Channel Number
	ulDirection
 		Channel direction.
	abyPad
 		Reserved to align following member.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCTVC1_GSM_SUB_CHANNEL_NB_ENUM	ulSubchannelNb;
	tOCTVC1_GSM_DIRECTION_ENUM		ulDirection;
	tOCT_UINT8						abyPad[3];

} tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	ulTxSubChannelMask
	ulRxSubChannelMask
	Config
 		Cipher configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCTVC1_GSM_SUBCHANNEL_MASK		ulTxSubChannelMask;
	tOCTVC1_GSM_SUBCHANNEL_MASK		ulRxSubChannelMask;
	tOCTVC1_GSM_CIPHER_CONFIG		Config[cOCTVC1_GSM_TIMESLOT_MAX_SUBCHANNEL];

} tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;

} tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	PchId
 		Unique Physical channel identifier
	MeasurementInfo
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_PHYSICAL_CHANNEL_ID	PchId;
	tOCTVC1_GSM_MEASUREMENT_INFO	MeasurementInfo;

} tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	RfConfig
 		RF configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_GSM_RF_CONFIG	RfConfig;

} tOCTVC1_GSM_MSG_TRX_INFO_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	RfConfig
 		RF configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_GSM_RF_CONFIG	RfConfig;

} tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_MODIFY_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD

 Members:
	Header
	IndexGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;

} tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	IndexGet
 		Object cursor
	IndexList
 		Object name list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;
	tOCTVC1_LIST_INDEX_GET		IndexList;

} tOCTVC1_GSM_MSG_TAP_FILTER_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulFilterIndex
 		Unique Filter Profile Index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulFilterIndex;

} tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulFilterIndex
 		Unique Filter Profile Index
	Filter
 		Filter configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulFilterIndex;
	tOCTVC1_GSM_TAP_FILTER	Filter;

} tOCTVC1_GSM_MSG_TAP_FILTER_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulFilterIndex
 		Unique Filter Profile Index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulFilterIndex;

} tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulFilterIndex
 		Unique Filter Profile Index
	Stats
 		Filter configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulFilterIndex;
	tOCTVC1_GSM_TAP_FILTER_STATS	Stats;

} tOCTVC1_GSM_MSG_TAP_FILTER_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulFilterIndex
 		Unique Filter Profile Index
	Filter
 		Filter configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulFilterIndex;
	tOCTVC1_GSM_TAP_FILTER	Filter;

} tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulFilterIndex
 		Unique Filter Profile Index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulFilterIndex;

} tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulOversample16xEnableFlag
 		false 4x oversample ,true 16x oversample
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulOversample16xEnableFlag;

} tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulOversample16xEnableFlag
 		false 4x oversample ,true 16x oversample
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulOversample16xEnableFlag;

} tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	ulResetFlag
 		Reset timeslot stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCT_BOOL32						ulResetFlag;

} tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

} tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	StubStatus
 		stub timeslot status bitwise
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_GSM_TRX_ID		TrxId;
	tOCTVC1_GSM_STUB_STATUS	StubStatus;

} tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	STUB_CHANNEL_ID
 		Unique channel_identifier
	HEADER_CAPTURE
		Default:	0
 		CAPTURE_HEADER_OR_NOT
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_STUB_CHANNEL_ID		STUB_CHANNEL_ID;
	tOCTVC1_GSM_HEADER_CAPTURE_ENUM	HEADER_CAPTURE;

} tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	byTimeslotNb
 		Timeslot number.
	bySubChannelNb
 		Sub-Channel number.
	byStubMode
 		STUB_MODE_ENUM.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM	byTimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	bySubChannelNb;
	tOCTVC1_GSM_STUB_MODE_ENUM			byStubMode;

} tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	testModeVal
 		Test Mode None/TX
	modulation
 		modulation type
	abyBurstType
		Default:	cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND
 		Burst Type on Time Slots
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_GSM_TRX_ID						TrxId;
	tOCTVC1_GSM_TEST_MODE_ENUM				testModeVal;
	tOCTVC1_GSM_MODULATION_ENUM				modulation;
	tOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM	abyBurstType[cOCTVC1_GSM_TRX_MAX_TIMESLOTS];

} tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	testModeVal
 		Test Mode None/TX
	modulation
 		modulation type
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_GSM_TEST_MODE_ENUM	testModeVal;
	tOCTVC1_GSM_MODULATION_ENUM	modulation;

} tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	Status
		Default:	0
 		CAPTURE_STATUS.
	tracePoint
		Default:	0
 		OM OR IM
	Type
		Default:	0
 		ONE TIME OR WRAPPING
	TimeslotNb
 		Timeslot number.
	SubChannelNb
 		Sub-Channel number.
	blockCnt
 		blockCnt
	wrapCount
 		WRAP_AROUND_COUNT
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_CAPTURE_STATUS_ENUM		Status;
	tOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM	tracePoint;
	tOCTVC1_GSM_CAPTURE_TYPE_ENUM		Type;
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM	TimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	SubChannelNb;
	tOCT_UINT16							blockCnt;
	tOCT_UINT8							wrapCount;

} tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	Mode
		Default:	0
 		Mode_of_capture
	TimeslotNb
 		Timeslot number.
	SubChannelNb
 		Sub-Channel number.
	tracePoint
		Default:	0
 		MODULE_TO_CAPTURE
	Type
		Default:	0
 		CAPTURE_TYPE
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_CAPTURE_MODE_ENUM		Mode;
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM	TimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	SubChannelNb;
	tOCTVC1_GSM_MODULE_TO_CAPTURE_ENUM	tracePoint;
	tOCTVC1_GSM_CAPTURE_TYPE_ENUM		Type;

} tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	TimeslotNb
 		Timeslot number.
	SubChannelNb
 		Sub-Channel number.
	Mode
		Default:	0
 		CAPTURE_MODE_ENUM.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM	TimeslotNb;
	tOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM	SubChannelNb;
	tOCTVC1_GSM_CAPTURE_MODE_ENUM		Mode;

} tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
	TSDigitalScaling
 		6 dB step scaling(0 means no scaling)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;
	tOCT_UINT8			TSDigitalScaling[cOCTVC1_GSM_TRX_MAX_TIMESLOTS];

} tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TSDigitalScaling
 		Array of TapId using this filter
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT8			TSDigitalScaling[cOCTVC1_GSM_TRX_MAX_TIMESLOTS];

} tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_RSP

 Members:
	Header
 		OCTVC1 Message Header
	TrxId
 		Unique TRX identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_GSM_TRX_ID	TrxId;

} tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_RSP;


/*****************************  MODULE_DATA  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	MeasurementInfo
	Data
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA					ModuleData;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID		LchId;
	tOCTVC1_GSM_MEASUREMENT_INFO		MeasurementInfo;
	tOCTVC1_GSM_LOGICAL_CHANNEL_DATA	Data;

} tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
	ulPrevDRLateFlag
 		Counter for data request late per timeslot
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA				ModuleData;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCT_UINT32						ulFrameNumber;
	tOCT_UINT32						ulPrevDRLateFlag;

} tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	ulBurstType
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
	MeasurementInfo
	ulMsgLength
		Range:		[..cOCTVC1_GSM_RACH_IND_MSG_SIZE]
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA				ModuleData;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCTVC1_GSM_BURST_TYPE_ENUM		ulBurstType;
	tOCT_UINT32						ulFrameNumber;
	tOCTVC1_GSM_MEASUREMENT_INFO	MeasurementInfo;
	tOCT_UINT32						ulMsgLength;

} tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	MeasurementInfo
	Data
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA						ModuleData;
	tOCTVC1_GSM_TRX_ID						TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID			LchId;
	tOCTVC1_GSM_RAW_MEASUREMENT_INFO		MeasurementInfo;
	tOCTVC1_GSM_LOGICAL_CHANNEL_RAW_DATA	Data;

} tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Logical Channel identifier
	ulAntennaIndex
 		Antenna index
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
	ulPower
	ulDataSizeInBytes
	byBadFlag
	byBurstId
	byReserved0
	byReserved1
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA				ModuleData;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCTVC1_INDEX					ulAntennaIndex;
	tOCT_UINT32						ulFrameNumber;
	tOCT_UINT32						ulPower;
	tOCT_UINT32						ulDataSizeInBytes;
	tOCT_UINT8						byBadFlag;
	tOCT_UINT8						byBurstId;
	tOCT_UINT8						byReserved0;
	tOCT_UINT8						byReserved1;

} tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	ulFrameNumber
		Range:		[..cOCTVC1_GSM_MAX_FRAME_COUNT]
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA				ModuleData;
	tOCTVC1_GSM_TRX_ID				TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;
	tOCT_UINT32						ulFrameNumber;

} tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	LchId
 		Unique Logical channel identifier
	Data
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA					ModuleData;
	tOCTVC1_GSM_TRX_ID					TrxId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_ID		LchId;
	tOCTVC1_GSM_LOGICAL_CHANNEL_DATA	Data;

} tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	ulFrameNumber
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA	ModuleData;
	tOCTVC1_GSM_TRX_ID	TrxId;
	tOCT_UINT32			ulFrameNumber;

} tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	ulStatus
 		TRX STATUS event
	ulFrameNumber
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA			ModuleData;
	tOCTVC1_GSM_TRX_ID			TrxId;
	tOCTVC1_GSM_TRX_STATUS_ENUM	ulStatus;
	tOCT_UINT32					ulFrameNumber;

} tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA

 Members:
	ModuleData
 		Module Data structure
	TrxId
 		Unique TRX identifier
	ulMcc
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA	ModuleData;
	tOCTVC1_GSM_TRX_ID	TrxId;
	tOCT_UINT32			ulMcc;

} tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/

#endif /* __OCTVC1_GSM_API_H__ */

