/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_API_PRIV.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the definition of the OBM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.7.0-B435 (24/10/2018)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_API_PRIV_H__
#define __OCTVC1_OBM_API_PRIV_H__


/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_obm_api.h"
#include "octvc1_obm_id_priv.h"
#include "octvc1_obm_rc_priv.h"

/************************  COMMON DEFINITIONS  *******************************/

				

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_TO_STRING :	Convert a  tOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM
									to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_TO_STRING(_x)						\
	((_x) == cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_10_MBS	  ? "10 Mb/s" :	\
	((_x) == cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_100_MBS	  ? "100 Mb/s" :	\
	((_x) == cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_1000_MBS	? "1000 Mb/s" :	\
												  "UNKNOWN" )))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_TO_STRING :	Convert a  tOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM
									to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_TO_STRING(_x)						\
	((_x) == cOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM_HALF	  ? "Half" :	\
	((_x) == cOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM_FULL	  ? "Full" :	\
												  "UNKNOWN" ))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_GPS_ANTENNA_TO_STRING :	Convert a  tOCTVC1_OBM_GPS_ANTENNA_ENUM
									to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_GPS_ANTENNA_TO_STRING(_x)						\
	((_x) == cOCTVC1_OBM_GPS_ANTENNA_ENUM_ONBOARD			? "ONBOARD" :	\
	((_x) == cOCTVC1_OBM_GPS_ANTENNA_ENUM_BOARD_CONNECTOR	? "BOARD_CONNECTOR" :	\
												  "UNKNOWN" ))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_GPS_ANTENNA_TO_ENUM : Convert a string representation to a
									tOCTVC1_OBM_GPS_ANTENNA_ENUM.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_GPS_ANTENNA_TO_ENUM(_s)					\
			(strncmp(_s, "ONBOARD", sizeof("ONBOARD") ) == 0				? cOCTVC1_OBM_GPS_ANTENNA_ENUM_ONBOARD :			\
			(strncmp(_s, "BOARD_CONNECTOR", sizeof("BOARD_CONNECTOR")) == 0	? cOCTVC1_OBM_GPS_ANTENNA_ENUM_BOARD_CONNECTOR :	\
									cOCTVC1_OBM_GPS_ANTENNA_ENUM_INVALID ))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_SIGNAL_STATE_TO_STRING :	Convert a  tOCTVC1_OBM_SIGNAL_STATE_ENUM
										to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_SIGNAL_STATE_TO_STRING(_x)						\
	((_x) == cOCTVC1_OBM_SIGNAL_STATE_ENUM_DEASSERT	? "DEASSERT" :	\
	((_x) == cOCTVC1_OBM_SIGNAL_STATE_ENUM_ASSERT	? "ASSERT" :	\
	((_x) == cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE	? "CYCLE" :		\
												  "UNKNOWN" )))

/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_DSP_BOOT_PROGRESS_TO_STRING : 	Convert a tOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_DSP_BOOT_PROGRESS_TO_STRING(_x)											\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_RESET					? "RESET" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_ADDRESS_ASSIGNED		? "ADDRESS_ASSIGNED" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_TRANSFER_IN_PROGRESS	? "TRANSFER_IN_PROGRESS" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_WAITING_FOR_RESPONSE	? "WAITING_FOR_RESPONSE" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_COMPLETE				? "COMPLETE" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_EXT_TFTP_STARTED		? "EXT_TFTP_STARTED" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_END_WITH_ERROR			? "END_WITH_ERROR" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_STAGE1_ERROR			? "STAGE1_ERROR" :	\
	((_x) == cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_INITIAL_BROADCAST		? "INITIAL_BROADCAST" :	\
																		  "UNKNOWN" )))))))))
				
/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_RADIO_PROFILE_TO_STRING : 	Convert a tOCTVC1_OBM_RADIO_PROFILE_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_RADIO_PROFILE_TO_STRING(_x)											\
	((_x) == cOCTVC1_OBM_RADIO_PROFILE_ENUM_CDMA2000 ? "CDMA2000" : \
	((_x) == cOCTVC1_OBM_RADIO_PROFILE_ENUM_GSM	     ? "GSM"      : \
	((_x) == cOCTVC1_OBM_RADIO_PROFILE_ENUM_UMTS	 ? "UMTS"     : \
	((_x) == cOCTVC1_OBM_RADIO_PROFILE_ENUM_LTE	     ? "LTE"      : \
													 "UNKNOWN" ))))
				
/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_RF_DUPLEX_MODE_TO_STRING : 	Convert a tOCTVC1_OBM_RF_DUPLEX_MODE_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_RF_DUPLEX_MODE_TO_STRING(_x)											\
	((_x) == cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_FDD    ? "FDD" :	\
	((_x) == cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_TDD    ? "TDD" :	\
													  "UNKNOWN" ))

/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_RF_MANAGEMENT_MODE_TO_STRING : 	Convert a tOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_RF_MANAGEMENT_MODE_TO_STRING(_x)											\
	((_x) == cOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM_AUTOMATIC  ? "AUTOMATIC" :	\
	((_x) == cOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM_MANUAL     ? "MANUAL" :	\
													  "UNKNOWN" ))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_STRING :	Convert a  tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_EXTERNAL	? "EXTERNAL" :	\
	((_x) == cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_GPS			? "GPS" :	\
	((_x) == cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_SYNCE		? "SYNCE" :	\
	((_x) == cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_BACKPLANE	? "BACKPLANE" :	\
	((_x) == cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_DISCONNECTED	? "DISCONNECTED" :	\
												  "UNKNOWN" )))))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_ENUM :	Convert a string representation to a
                                            tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_INPUT_REFERENCE_CLOCK_TO_ENUM(_s)											\
			(strncmp(_s, "EXTERNAL", sizeof("EXTERNAL") ) == 0			? cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_EXTERNAL :		\
			(strncmp(_s, "GPS", sizeof("GPS")) == 0						? cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_GPS :			\
			(strncmp(_s, "SYNCE", sizeof("SYNCE")) == 0					? cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_SYNCE :		\
			(strncmp(_s, "BACKPLANE", sizeof("BACKPLANE")) == 0			? cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_BACKPLANE :	\
			(strncmp(_s, "DISCONNECTED", sizeof("DISCONNECTED")) == 0	? cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_DISCONNECTED :	\
									cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_INVALID )))))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_REFERENCE_CLOCK_STATE_TO_STRING :	Convert a  tOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_REFERENCE_CLOCK_STATE_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM_MISSING	? "CLOCK_MISSING" :	\
	((_x) == cOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM_PRESENT	? "CLOCK_PRESENT" :	\
												  "UNKNOWN" ))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_CLOCK_MGR_MODE_TO_STRING :	Convert a  tOCTVC1_OBM_CLOCK_MGR_MODE_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_CLOCK_MGR_MODE_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_1PPS	? "1 PPS" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_10MHZ	? "10 MHz" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_25MHZ	? "25 MHz" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_30_72MHZ	? "30.72 MHz" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_BASS	? "BASS" :	\
												  "UNKNOWN" )))))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_CLOCK_MGR_DIAG_TO_STRING :	Convert a  tOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_CLOCK_MGR_DIAG_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_UNKNOWN	? "UNKNOWN" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_OK	? "OK" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_INVALID_CONFIG	? "INVALID_CONFIG" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_VALID_CONFIG_GPS_NO_FIX	? "VALID_CONFIG_GPS_NO_FIX" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_VALID_CONFIG_SYNCE_ERROR	? "VALID_CONFIG_SYNCE_ERROR" :	\
	((_x) == cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_DISCONNECTED	? "CLOCK_DISCONNECTED" :	\
												  "UNKNOWN" ))))))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_TO_STRING :	Convert a  tOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM
												to its string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_INPUT_REFERENCE	? "INPUT_REFERENCE" :	\
	((_x) == cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_LOCAL_MAIN_CLOCK	? "LOCAL_MAIN_CLOCK" :	\
												  "UNKNOWN" ))

/*-------------------------------------------------------------------------------------
mOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_TO_ENUM : Convert a string representation to a
											 tOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_TO_ENUM(_s)					\
			(strncmp(_s, "INPUT_REFERENCE", sizeof("INPUT_REFERENCE") ) == 0	? cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_INPUT_REFERENCE :		\
			(strncmp(_s, "LOCAL_MAIN_CLOCK", sizeof("LOCAL_MAIN_CLOCK")) == 0	? cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_LOCAL_MAIN_CLOCK :	\
									cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_INVALID ))

/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_GPS_FIX_TO_STRING :	Convert a  tOCTVC1_OBM_GPS_FIX_ENUM to its
								string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_GPS_FIX_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_GPS_FIX_ENUM_NONE		? "NONE" :	\
	((_x) == cOCTVC1_OBM_GPS_FIX_ENUM_2D		? "2D" :	\
	((_x) == cOCTVC1_OBM_GPS_FIX_ENUM_3D		? "3D" :	\
												  "UNKNOWN" )))

/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_MONTHS_TO_STRING :	Convert a  tOCTVC1_OBM_MONTHS_ENUM to its
									string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_MONTHS_TO_STRING(_x)				\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_JANUARY		? "JANUARY" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_FEBRUARY		? "FEBRUARY" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_MARCH			? "MARCH" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_APRIL			? "APRIL" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_MAY			? "MAY" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_JUNE			? "JUNE" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_JULY			? "JULY" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_AUGUST			? "AUGUST" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_SEPTEMBER		? "SEPTEMBER" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_OCTOBER		? "OCTOBER" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_NOVEMBER		? "NOVEMBER" :	\
((_x) == cOCTVC1_OBM_MONTHS_ENUM_DECEMBER		? "DECEMBER" :	\
												  "UNKNOWN" ))))))))))))


/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_CARDINAL_DIRECTION_TO_STRING :	Convert a  tOCTVC1_OBM_CARDINAL_DIRECTION_TO_STRING to its
												string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_CARDINAL_DIRECTION_TO_STRING(_x)		\
((_x) == cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_NORTH	? "NORTH" :	\
((_x) == cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_SOUTH	? "SOUTH" :	\
((_x) == cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_EAST	? "EAST" :	\
((_x) == cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_WEST	? "WEST" :	\
												  "UNKNOWN" ))))

/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_POWER_UP_TYPE_TO_STRING :	Convert a  tOCTVC1_OBM_POWER_UP_TYPE_ENUM to its
								string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_POWER_UP_TYPE_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_POWER_UP_TYPE_ENUM_SWITCH        ? "SWITCH" :	\
	((_x) == cOCTVC1_OBM_POWER_UP_TYPE_ENUM_TIMER_WAKEUP  ? "TIMER_WAKEUP" :	\
	((_x) == cOCTVC1_OBM_POWER_UP_TYPE_ENUM_CABLE_CONNECT ? "CABLE_CONNECT" :	\
	((_x) == cOCTVC1_OBM_POWER_UP_TYPE_ENUM_SOFT_REBOOT ? "SOFT_REBOOT" :	\
	((_x) == cOCTVC1_OBM_POWER_UP_TYPE_ENUM_POST_ALARM_REBOOT ? "POST_ALARM_REBOOT" :	\
										                    "UNDETERMINED" )))))
															
/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_RF_MUXING_MODE_TO_STRING :	Convert a  tOCTVC1_OBM_RF_MUXING_MODE_ENUM to its
								string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_RF_MUXING_MODE_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_RF_MUXING_MODE_ENUM_STANDARD        ? "STANDARD" :	\
	((_x) == cOCTVC1_OBM_RF_MUXING_MODE_ENUM_CROSS  ? "CROSS" :	\
	((_x) == cOCTVC1_OBM_RF_MUXING_MODE_ENUM_SINGLE_DSP_DUAL_RADIO ? "SINGLE_DSP_DUAL_RADIO" :	\
	((_x) == cOCTVC1_OBM_RF_MUXING_MODE_ENUM_DUAL_DSP_SINGLE_RADIO ? "DUAL_DSP_SINGLE_RADIO" :	\
										                    "UNDETERMINED" ))))
															
/*-------------------------------------------------------------------------------------
	mOCTVC1_OBM_POWER_SOURCE_TO_STRING :	Convert a  tOCTVC1_OBM_POWER_SOURCE_ENUM to its
								string representation.
-------------------------------------------------------------------------------------*/
#define mOCTVC1_OBM_POWER_SOURCE_TO_STRING(_x)				\
	((_x) == cOCTVC1_OBM_POWER_SOURCE_ENUM_DC        ? "DC" :	\
	((_x) == cOCTVC1_OBM_POWER_SOURCE_ENUM_BATTERY0  ? "BATTERY0" :	\
	((_x) == cOCTVC1_OBM_POWER_SOURCE_ENUM_BATTERY1 ? "BATTERY1" :	\
										                    "UNDETERMINED" )))

				
			  
/*****************************  METHODS  *************************************/

/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_obm_evt_priv.h"

#endif /* __OCTVC1_OBM_API_PRIV_H__ */

