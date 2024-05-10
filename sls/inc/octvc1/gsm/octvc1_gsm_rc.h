/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_GSM_RC.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the GSM API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_GSM_RC_H__
#define OCTVC1_GSM_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_gsm_base.h"

/****************************************************************************
	GSM return codes
 ****************************************************************************/

/****************************************************************************
	GENERIC return codes
 ****************************************************************************/
#define cOCTVC1_GSM_GENERIC_RC_BASE							 ( 0x0100 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_GENERIC_EVENT_MASK_INVALID			 ( 0x0000 + cOCTVC1_GSM_GENERIC_RC_BASE )

/****************************************************************************
	TRX return codes
 ****************************************************************************/
#define cOCTVC1_GSM_TRX_RC_BASE										 ( 0x0200 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_TRX_RESOURCE_UNAVAILABLE						 ( 0x0000 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_ALREADY_OPENED							 ( 0x0001 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_ID_INVALID								 ( 0x0002 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_NOT_FOUND								 ( 0x0003 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_RADIO_INIT								 ( 0x0004 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_RADIO_CONFIG								 ( 0x0005 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_RADIO_RESET								 ( 0x0006 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_RADIO_TERMINATE							 ( 0x0007 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_CENTRE_FREQ_NOT_SAME_ACROSS_TRX			 ( 0x0008 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_CARRIER_OFFSET_OUTOF_RANGE				 ( 0x0009 + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_NOT_PROPERLY_SEPARATED					 ( 0x000a + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_BCCH_NOT_CONFIGURED						 ( 0x000b + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_CLOSE_NONPRIMARY_FIRST					 ( 0x000c + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_PARAMS_INVALID							 ( 0x000d + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_PRIMARY_ONLY_BCCH_CONFIGURED				 ( 0x000e + cOCTVC1_GSM_TRX_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_PRE_CONFIG_OVERSAMPLE_SELECTION_NOT_DONE	 ( 0x000f + cOCTVC1_GSM_TRX_RC_BASE )

/****************************************************************************
	PHYSICAL_CHANNEL return codes
 ****************************************************************************/
#define cOCTVC1_GSM_PHYSICAL_CHANNEL_RC_BASE					 ( 0x0300 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_PHYSICAL_CHANNEL_RESOURCE_UNAVAILABLE	 ( 0x0000 + cOCTVC1_GSM_PHYSICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_PHYSICAL_CHANNEL_ALREADY_ACTIVATED		 ( 0x0001 + cOCTVC1_GSM_PHYSICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_PHYSICAL_CHANNEL_NOT_ACTIVATED			 ( 0x0002 + cOCTVC1_GSM_PHYSICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_PHYSICAL_CHANNEL_ID_INVALID				 ( 0x0003 + cOCTVC1_GSM_PHYSICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_PHYSICAL_CHANNEL_PARAMS_INVALID			 ( 0x0004 + cOCTVC1_GSM_PHYSICAL_CHANNEL_RC_BASE )

/****************************************************************************
	SUB_CHANNEL return codes
 ****************************************************************************/
#define cOCTVC1_GSM_SUB_CHANNEL_RC_BASE						 ( 0x0350 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_SUB_CHANNEL_ID_INVALID				 ( 0x0000 + cOCTVC1_GSM_SUB_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_SUB_CHANNEL_DIRECTION_INVALID		 ( 0x0001 + cOCTVC1_GSM_SUB_CHANNEL_RC_BASE )

/****************************************************************************
	LOGICAL_CHANNEL return codes
 ****************************************************************************/
#define cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE					 ( 0x0400 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_RESOURCE_UNAVAILABLE	 ( 0x0000 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_ALREADY_ACTIVATED	 ( 0x0001 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_NOT_ACTIVATED		 ( 0x0002 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_ID_INVALID			 ( 0x0003 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_DIRECTION_INVALID	 ( 0x0004 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_SAPI_INVALID			 ( 0x0005 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_BCCH_BSIC_INVALID	 ( 0x0006 + cOCTVC1_GSM_LOGICAL_CHANNEL_RC_BASE )

/****************************************************************************
	TEST_MODULE return codes
 ****************************************************************************/
#define cOCTVC1_GSM_TEST_MODULE_RC_BASE						 ( 0x0420 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_TEST_MODULE_GSM_MODULE_NOT_STARTED	 ( 0x0000 + cOCTVC1_GSM_TEST_MODULE_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE										 ( 0xF000 + cOCTVC1_GSM_RC_BASE )

#define cOCTVC1_GSM_RC_RF_CONFIG_INVALID_RX_GAIN_DB								 ( 0x1 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_RF_CONFIG_INVALID_TX_ATTND_B								 ( 0x2 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_RF_CONFIG_INVALID_TX_ANTENNA_ID							 ( 0x3 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_RF_CONFIG_INVALID_RX_ANTENNA_ID							 ( 0x4 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_TRX_CONFIG_INVALID_US_TSC								 ( 0x5 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_STUB_STATUS_INVALID_BY_TIMESLOT_USED						 ( 0x6 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_DATA_INVALID_FRAME_NUMBER				 ( 0x7 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_DATA_INVALID_DATA_LENGTH					 ( 0x8 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_RAW_DATA_INVALID_FRAME_NUMBER			 ( 0x9 + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_LOGICAL_CHANNEL_RAW_DATA_INVALID_DATA_LENGTH				 ( 0xA + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_TAP_FILTER_PHYSICAL_CHANNEL_INVALID_ENTRY_CNT			 ( 0xB + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_TAP_FILTER_LOGICAL_CHANNEL_INVALID_ENTRY_CNT				 ( 0xC + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_TAP_FILTER_STATS_INVALID_TAP_ID_CNT						 ( 0xD + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_GSM_RC_MODULE_DATA_RF_UPLINK_INPUT_HEADER_INVALID_FRAME_NUMBER	 ( 0xE + cOCTVC1_GSM_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_GSM_RC_H__ */

