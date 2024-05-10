/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_API.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the definition of the OBM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.7.0-B435 (24/10/2018)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_API_H__
#define __OCTVC1_OBM_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include <string.h>
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_fifo.h"
#include "../octvc1_file.h"
#include "../octvc1_ip.h"
#include "../octvc1_mac.h"

#include "octvc1_obm_id.h"
#include "octvc1_obm_rc.h"

/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVC1_OBM_FIELD_VALUE_NOT_AVAILABLE				0xeeeeeeee	 	/* The value for this field is not available. */
#define cOCTVC1_OBM_BOOT_FILE_NAME_LENGTH					256		 	/* Maximum boot file name length. */
#define cOCTVC1_OBM_INFO_STRING_LENGTH						32		 	/* Maximum length for information-type strings. */
#define cOCTVC1_OBM_SUPPLEMENTAL_INFO_STRING_LENGTH			128		 	/* Maximum length for supplemental information strings. */
#define cOCTVC1_OBM_RF_BANK_INFO_STRING_LENGTH				16		 	/* Maximum length for RF bank information-type strings. */
#define cOCTVC1_OBM_FILENAME_STRING_LENGTH					128		 	/* Maximum length for filename-type strings. */
#define cOCTVC1_OBM_ERROR_MSG_STRING_LENGTH					256		 	/* Maximum length for the error message strings. */
#define cOCTVC1_OBM_RF_INFO_STRING_LENGTH					64		 	/* Maximum length for the RF informational strings. */
#define cOCTVC1_OBM_RF_SUPPLEMENTAL_INFO_STRING_LENGTH		192		 	/* Maximum length for the RF supplemental informational strings. */
#define cOCTVC1_OBM_RF_BAND_STRING_LENGTH					8		 	/* Maximum length for the RF band strings. */
#define cOCTVC1_OBM_NOTIFICATION_MSG_STRING_LENGTH			64		 	/* Maximum length for RFE notification supplemental informational strings. */
#define cOCTVC1_OBM_MAX_RF_COMPONENT_BANKS					4		 	/* Maximum number of RF component banks on an RF frontend. */
#define cOCTVC1_OBM_ATTACH_INFO_STRING_LENGTH				256		 	/* Maximum length for the supplementary attach info strings. */
#define cOCTVC1_OBM_MAX_ANTENNA_CONNECTORS					8		 	/* Maximum number of antenna connectors on a board. */
#define cOCTVC1_OBM_SERVER_PORT								0xcaff	 	/* TCP port on which the OBM service listens for incoming connections. */
#define cOCTVC1_OBM_MAX_RF_DIVERSITY_PATH					1		 	/* Maximum number of diversity path present on a RFE. */
#define cOCTVC1_OBM_MAX_RF_COMPONENT_DESC					20		 	/* Maximum number of RF component descriptor present on a board. */
#define cOCTVC1_OBM_RF_DEFAULT_BANDWIDTH_KHZ				10000	 	/* Default value of bandwidth in KHz for frequency requested for filter. */
#define cOCTVC1_OBM_MAX_I2C_BYTES							32		 	/* Maximum number of data bytes per i2c transaction. */
#define cOCTVC1_OBM_POWER_SWITCH_INFINITE_DURATION			-1		 	/* The power switch has been at the given position at least 25.5 seconds */
#define cOCTVC1_OBM_MAX_ACTIVE_SATELLITE					72		 	/* Maximum number of active satellite. */
#define cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT			7		 	/* Maximum number of port in the ethernet switch. */
#define cOCTVC1_OBM_ETHERNET_SWITCH_PORT_MIRROR_DST_NONE	0xffffffff	 	/* Ethernet switch port value to disable the port mirroring destination. */
#define cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS			5		 	/* Maximum number of power measurement points on an Rf Frontend. */
#define cOCTVC1_OBM_MAX_TEMP_SENSORS						5		 	/* Maximum number of temperature sensors on an Rf Frontend. */
#define cOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_LIST_MAX_ENTRY	32		 	/* Maximum number of RF_ANTENNA_CONNECTOR_ID per list. */
#define cOCTVC1_OBM_RF_DBM_Q9_VALUE_POWER_OFF				0xaaaaaaaa	 	/* The value for this field represente power off. */
#define cOCTVC1_OBM_RF_DBM_Q9_VALUE_POWER_ON				0xbbbbbbbb	 	/* The value for this field represente power on. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_DSP_ID_ENUM : 	DSP identifier.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_DSP_ID_ENUM								tOCT_UINT32

#define cOCTVC1_OBM_DSP_ID_ENUM_UNKNOWN						-1		
#define cOCTVC1_OBM_DSP_ID_ENUM_PRIMARY						0		
#define cOCTVC1_OBM_DSP_ID_ENUM_SECONDARY					1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM : 	DSP boot progress.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_UNKNOWN					0		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_RESET					1		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_ADDRESS_ASSIGNED			2		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_TRANSFER_IN_PROGRESS		3		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_WAITING_FOR_RESPONSE		4		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_COMPLETE					5		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_EXT_TFTP_STARTED			6		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_END_WITH_ERROR			7		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_STAGE1_ERROR				8		
#define cOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM_INITIAL_BROADCAST		9		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_GPS_FIX_ENUM : 	GPS fix state as reported by the GPS device.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_GPS_FIX_ENUM							tOCT_UINT32

#define cOCTVC1_OBM_GPS_FIX_ENUM_UNKNOWN					0		 	/* GPS has not yet reported fix information. */
#define cOCTVC1_OBM_GPS_FIX_ENUM_NONE						1		 	/* GPS does not have a fix yet. */
#define cOCTVC1_OBM_GPS_FIX_ENUM_2D							2		 	/* GPS has a latitude and longitude information. */
#define cOCTVC1_OBM_GPS_FIX_ENUM_3D							3		 	/* Gps has latitude, longitued and altitude information. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_GPS_ANTENNA_ENUM : 	GPS antenna selection.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_GPS_ANTENNA_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_GPS_ANTENNA_ENUM_ONBOARD				0		 	/* GPS uses an onboard antenna (located on the PCB). */
#define cOCTVC1_OBM_GPS_ANTENNA_ENUM_BOARD_CONNECTOR		1		 	/* GPS uses a connector-attached antenna. */
#define cOCTVC1_OBM_GPS_ANTENNA_ENUM_INVALID				-1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_SIGNAL_STATE_ENUM : 	State of the hardware signal.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_SIGNAL_STATE_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_SIGNAL_STATE_ENUM_DEASSERT				0		
#define cOCTVC1_OBM_SIGNAL_STATE_ENUM_ASSERT				1		
#define cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE					2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM : 	Input reference clock selection.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_EXTERNAL			0		 	/* External reference clock connector */
#define cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_GPS				1		 	/* Onboard GPS 1PPS tick */
#define cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_SYNCE			2		 	/* Synchronous Ethernet clock from the onboard ethernet switch. */
#define cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_BACKPLANE		3		 	/* Backplane connector */
#define cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_DISCONNECTED		4		 	/* No reference clock is provided to the DSP(s) */
#define cOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM_INVALID			-1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM : 	Output reference clock selection.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_INPUT_REFERENCE		0		 	/* The selected input reference clock gets propagated to the output reference */
 																			/* clock pin. */
#define cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_LOCAL_MAIN_CLOCK	1		 	/* The board's local main clock gets propagated to the output reference clock pin. */
#define cOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM_INVALID				-1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM : 	State of the reference clock.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM_MISSING		0		 	/* The reference clock has not been detected. */
#define cOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM_PRESENT		1		 	/* The reference clock is present. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_CLOCK_MGR_MODE_ENUM : 	Source of the clock manager.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_CLOCK_MGR_MODE_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_UNKNOWN				0		 	/* The mode is unknown for the moment. */
#define cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_1PPS				1		
#define cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_10MHZ				2		
#define cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_25MHZ				3		
#define cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_30_72MHZ			4		
#define cOCTVC1_OBM_CLOCK_MGR_MODE_ENUM_BASS				5		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM : 	Diagnostic of the clock manager.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM								tOCT_UINT32

#define cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_UNKNOWN						0		 	/* The diagnostic is unknown for the moment. */
#define cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_OK							1		 	/* Everything is ok. */
#define cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_INVALID_CONFIG				2		 	/* Configuration is invalid. */
#define cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_VALID_CONFIG_GPS_NO_FIX		3		 	/* Configuration is valid, but with no GPS fix. */
#define cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_VALID_CONFIG_SYNCE_ERROR	4		 	/* Configuration is valid, but with Synce error. */
#define cOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM_DISCONNECTED				5		 	/* Clock is disconnected. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM : 	Power switch bypass modes.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM_NO_BATTERY	0		 	/* Power switch gets bypassed only if no battery is present in the unit. */
#define cOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM_ALWAYS		1		 	/* Power switch gets bypassed whether or not a battery present in the unit. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM : 	Type of updateable component.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_EMIC			1		
#define cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND	2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM : 	Type of attachable component.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND	1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_BOARD_STOP_ACTION_ENUM : 	Board stop action that can be performed.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_BOARD_STOP_ACTION_ENUM					tOCT_UINT32

#define cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_SHUT_DOWN		0		 	/* Shut down. */
#define cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_REBOOT			1		 	/* Shut down and reboot now. */
#define cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_WAKEUP_AT_DATE	2		 	/* Shut down and wakeup at a specific date & time. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM : 	Management mode.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM					tOCT_UINT32

#define cOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM_AUTOMATIC		0		
#define cOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM_MANUAL			1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM : 	RF component entry type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_OFF			0		 	/* Path is disconnected. No Rf can go through. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_DIRECT		1		 	/* Direct Path. No filtering is done. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_DIRECT_NO_PA	2		 	/* Direct Path, without amplification. No filtering nor amplification is done. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FREQ_HIGH		3		 	/* Direct path through a high-frequency capable PA. No filtering is done. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FREQ_MID		4		 	/* Direct path through a mid-frequency capable PA. No filtering is done. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FREQ_LOW		5		 	/* Direct path through a low-frequency capable PA. No filtering is done. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_FILTER		6		 	/* Rf filter element. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_GAIN			7		 	/* Wideband gain element. Attenuation if negative. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_LNA			8		 	/* Low-noise amplifier on. */
#define cOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM_LNA_BYPASS	9		 	/* Low-noise amplifier is bypassed. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_PATH_ENUM : 	Identifier of an RF frontend's RF path.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_RF_PATH_ENUM							tOCT_UINT32

#define cOCTVC1_OBM_RF_PATH_ENUM_MAIN_0						0		
#define cOCTVC1_OBM_RF_PATH_ENUM_DIVERSITY_0				1		
#define cOCTVC1_OBM_RF_PATH_ENUM_MAIN_1						2		
#define cOCTVC1_OBM_RF_PATH_ENUM_DIVERSITY_1				3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID
 		Identifies an antenna connector on a board.

 Members:
	usTransceiverIndex
 		Transceiver Index.
	usAntennaIndex
 		Antenna Index.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usTransceiverIndex;
	tOCT_UINT16	usAntennaIndex;

} tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_DSP_ANTENNA_ID
 		Identifier of an antenna managed by a Dsp application.

 Members:
	usRfPortIndex
 		Transceiver Index.
	usAntennaIndex
 		Antenna Index.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usRfPortIndex;
	tOCT_UINT16	usAntennaIndex;

} tOCTVC1_OBM_DSP_ANTENNA_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_ALARM_INFO
 		Description of RF alarm information.

 Members:
	ulTxPowerOverloadFlag
 		cOCT_TRUE when the RF transmit path has been disabled due to an excessive
 		transmit power.
	ulRxPowerOverloadFlag
 		cOCT_TRUE when the RF receive path has been disabled due to an excessive
 		transmit power.
	ulTxFaultFlag
 		cOCT_TRUE when the RF transmit path has encountered a fault condition.
	ulRxFaultFlag
 		cOCT_TRUE when the RF receive path has encountered a fault condition.
	ulTemperatureFaultFlag
 		cOCT_TRUE when the RF Frontend is in an excessive temperature condition.
	ulOverpowerFlag
 		cOCT_TRUE when the RF Frontend is drawing too much power.
	ulOvercurrentFlag
 		cOCT_TRUE when the RF Frontend is drawing too much current.
	ulPowerFailureFlag
 		cOCT_TRUE when the RF Frontend has experienced a power failure.
	ulFanFlag
 		cOCT_TRUE when the RF Frontend has experienced a fan malfunction.
	ulOtherFlag
 		cOCT_TRUE when the RF Frontend has experienced a malfunction. See the info
 		field for details.
	szNotificationInfo
 		Supplemental information on event cause.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulTxPowerOverloadFlag;
	tOCT_BOOL32	ulRxPowerOverloadFlag;
	tOCT_BOOL32	ulTxFaultFlag;
	tOCT_BOOL32	ulRxFaultFlag;
	tOCT_BOOL32	ulTemperatureFaultFlag;
	tOCT_BOOL32	ulOverpowerFlag;
	tOCT_BOOL32	ulOvercurrentFlag;
	tOCT_BOOL32	ulPowerFailureFlag;
	tOCT_BOOL32	ulFanFlag;
	tOCT_BOOL32	ulOtherFlag;
	tOCT_INT8	szNotificationInfo[cOCTVC1_OBM_NOTIFICATION_MSG_STRING_LENGTH];

} tOCTVC1_OBM_RF_ALARM_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_CURSOR

 Members:
	AntennaConnectorId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;

} tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_GET_CURSOR

 Members:
	ulBoardIndex
	AntennaConnectorId
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCTVC1_OBJECT_CURSOR_ENUM			ulGetMode;

} tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_GET_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_COMPONENT_DESC
 		Description of RF component properties.

 Members:
	ulType
 		Type identifying current RF component descriptor entry.
	ulCenterFrequencyKHz
 		The filter's center frequency, expressed in Kilohertz.
	ulBandwidthKHz
 		The filter's bandwidth, in Kilohertz.
	lGainDbQ9
 		The gain level, in Q9 format (can be negative in case of attenuation).
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_OBM_BOARD_RF_COMPONENT_DESC_TYPE_ENUM	ulType;
	tOCT_UINT32										ulCenterFrequencyKHz;
	tOCT_UINT32										ulBandwidthKHz;
	tOCT_INT32										lGainDbQ9;

} tOCTVC1_OBM_RF_COMPONENT_DESC;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_BOOT_STATUS
 		Boot status structure returned by the DSP at boot.

 Members:
	ulProgressCode
 		Boot progress code.
	usStage1Version
 		Stage1 bootloader version.
	usStage0Version
 		Stage0 bootloader version.
	ulErrorCode
 		Error code as reported by the satge1 bootloader.
	ulErrorInfo
 		Supplemental error infomation.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulProgressCode;
	tOCT_UINT16	usStage1Version;
	tOCT_UINT16	usStage0Version;
	tOCT_UINT32	ulErrorCode;
	tOCT_UINT32	ulErrorInfo;

} tOCTVC1_OBM_BOOT_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_DUPLEX_MODE_ENUM : 	RF Duplex modes.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_RF_DUPLEX_MODE_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_FDD					1		 	/* Frequency division duplex (Full duplex). */
#define cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_TDD					2		 	/* Time division duplex mode (Half duplex). */
#define cOCTVC1_OBM_RF_DUPLEX_MODE_ENUM_INVALID				-1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_PHY_ROLE_ENUM : 	specifies the PHY's role.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_PHY_ROLE_ENUM							tOCT_UINT32

#define cOCTVC1_OBM_PHY_ROLE_ENUM_BASE_STATION				1		 	/* Phy's ole is that of a base station. */
#define cOCTVC1_OBM_PHY_ROLE_ENUM_UE						2		 	/* Phy's role is that of a UE (user entity). */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RADIO_PROFILE_ENUM : 	The radio access technology.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_RADIO_PROFILE_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_RADIO_PROFILE_ENUM_UNKNOWN				0		
#define cOCTVC1_OBM_RADIO_PROFILE_ENUM_CDMA2000				1		
#define cOCTVC1_OBM_RADIO_PROFILE_ENUM_GSM					2		
#define cOCTVC1_OBM_RADIO_PROFILE_ENUM_UMTS					3		
#define cOCTVC1_OBM_RADIO_PROFILE_ENUM_LTE					4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM : 	Ethernet switch port link speed.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_UNKNOWN		0		
#define cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_10_MBS		1		
#define cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_100_MBS		2		
#define cOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM_1000_MBS		3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM : 	Ethernet switch port link duplex.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM				tOCT_UINT32

#define cOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM_UNKNOWN		0		
#define cOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM_HALF		1		
#define cOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM_FULL		2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_STATS
 		Ethernet switch port statistics counters.

 Members:
	ulInGoodOctetsSumLo
 		The lower 32-bits of the 64-bit InGoodOctets counter. The sum of lengths of all
 		good frames received, that is frames that are not bad frames.
	ulInGoodOctetsSumHi
 		The upper 32-bits of the 64-bit InGoodOctets counter.
	ulInBadOctetsSum
 		The sum of lengths of all bad Ethernet frames received.
	ulInUnicastCnt
 		The number of good frames received that have a Unicast destination MAC address.
	ulInBroadcastCnt
 		The number of good frames received that have a Broadcast destination MAC
 		address.
	ulInMulticastCnt
 		The number of good frames received that have a Multicast destination MAC
 		address. NOTE: This does not include frames counted in InPause nor does it
 		include frames counted in InBroadcast.
	ulInPauseCnt
 		The number of good frames received that have a Pause destination MAC address.
	ulInUndersizeCnt
 		The number of frames received with a length of less than 64 octets but with a
 		valid FCS.
	ulInFragmentCnt
 		The number of frames received with a length of less than 64 octets and an
 		invalid FCS.
	ulInOversizeCnt
 		The number of frames received with a length of more than MaxSize octets but
 		with a valid FCS.
	ulInJabberCnt
 		The number of frames received with a length of more than MaxSize octets but
 		with an invalid FCS.
	ulInRxErrorCnt
 		The number of frames received with an RxErr signal from the PHY.
	ulInFCSErrorCnt
 		The number of frames received with a CRC error not counted in InFragment,
 		InJabber or InRxErr.
	ulInFilteredCnt
 		The number of frames received correctly that were filtered out (due to VLAN
 		settings or other).
	ulInDiscardsCntLo
 		The lower 32-bits of the 64-bit InDiscards counter. This counter increments
 		each time a goot, non-filtered frame is received but cannot be forwarded due to
 		lack of memory.
	ulInDiscardsCntHi
 		The upper 32-bits of the 64-bit InDiscards counter.
	ulOutOctetsSumLo
 		The lower 32-bits of the 64-bits OutOctets counter. The sum of lengths of all
 		Ethernet frames sent from this MAC.
	ulOutOctetsSumHi
 		The upper 32-bits of the 64-bits OutOctets counter.
	ulOutUnicastCnt
 		The number of frames sent that have a Unicast destination MAC address.
	ulOutBroadcastCnt
 		The number of good frames sent that have a Broadcast destination MAC address.
	ulOutMulticastCnt
 		The number of good frames sent that have a Multicast destination MAC address.
 		Note: This does not include frames counted in OutPause nor does it include
 		frames counted in OutBroadcast.
	ulOutPauseCnt
 		The number of Flow Control frames sent.
	ulDeferredCnt
 		The number of successfully transmitted frames that experienced no collisions
 		but are delayed because the medium was busy during the first attempt. This
 		counter is applicable in half-duplex only.
	ulCollisionCnt
 		The number of collision events seen by the MAC not including those counted in
 		Single, Multiple Excessive, or Late. This counter is applicable in half-duplex
 		only.
	ulSingleCollisionCnt
 		The number of successfully transmitted frames that experienced exactly one
 		collision. This counter is applicable in half-duplex only.
	ulMultipleCollisionsCnt
 		The number of successfully transmitted frames that experienced more than one
 		collision. This counter is applicable in half-duplex only.
	ulExcessiveCollisionsCnt
 		The of frames dropped in the transmit MAC because the frame experienced 16
 		consecutive collisions. This counter is applicable in half-duplex only.
	ulLateCollisionsCnt
 		The of times a collision is detected later than 512 bits-times into the
 		transmission of a frames. This counter is applicable in half-duplex only.
	ulOutFcsErrorCnt
 		The number of frames transmitted with an invalid FCS.
	ulFrameCnt64Octets
 		The number of frames received and transmitted with a length of exactly 64
 		octets, including those with errors.
	ulFrameCnt65_127Octets
 		The number of frames received and transmitted with a length of between 65 and
 		127 octets inclusive, including those with errors.
	ulFrameCnt128_255Octets
 		The number of frames received and transmitted with a length of between 128 and
 		255 octets inclusive, including those with errors.
	ulFrameCnt256_511Octets
 		The numebr of frames received and transmitted with a length of between 256 and
 		511 octets inclusive, including those with errors.
	ulFrameCnt512_1023Octets
 		The number of frames received and transmitted with a length of between 512 and
 		1023 octets inclusive, including those with errors.
	ulFrameCnt1024_MaxOctets
 		The number of frames received and transmitted with a length of between 1024 and
 		MaxSize octets inclusive, including those with errors.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulInGoodOctetsSumLo;
	tOCT_UINT32	ulInGoodOctetsSumHi;
	tOCT_UINT32	ulInBadOctetsSum;
	tOCT_UINT32	ulInUnicastCnt;
	tOCT_UINT32	ulInBroadcastCnt;
	tOCT_UINT32	ulInMulticastCnt;
	tOCT_UINT32	ulInPauseCnt;
	tOCT_UINT32	ulInUndersizeCnt;
	tOCT_UINT32	ulInFragmentCnt;
	tOCT_UINT32	ulInOversizeCnt;
	tOCT_UINT32	ulInJabberCnt;
	tOCT_UINT32	ulInRxErrorCnt;
	tOCT_UINT32	ulInFCSErrorCnt;
	tOCT_UINT32	ulInFilteredCnt;
	tOCT_UINT32	ulInDiscardsCntLo;
	tOCT_UINT32	ulInDiscardsCntHi;
	tOCT_UINT32	ulOutOctetsSumLo;
	tOCT_UINT32	ulOutOctetsSumHi;
	tOCT_UINT32	ulOutUnicastCnt;
	tOCT_UINT32	ulOutBroadcastCnt;
	tOCT_UINT32	ulOutMulticastCnt;
	tOCT_UINT32	ulOutPauseCnt;
	tOCT_UINT32	ulDeferredCnt;
	tOCT_UINT32	ulCollisionCnt;
	tOCT_UINT32	ulSingleCollisionCnt;
	tOCT_UINT32	ulMultipleCollisionsCnt;
	tOCT_UINT32	ulExcessiveCollisionsCnt;
	tOCT_UINT32	ulLateCollisionsCnt;
	tOCT_UINT32	ulOutFcsErrorCnt;
	tOCT_UINT32	ulFrameCnt64Octets;
	tOCT_UINT32	ulFrameCnt65_127Octets;
	tOCT_UINT32	ulFrameCnt128_255Octets;
	tOCT_UINT32	ulFrameCnt256_511Octets;
	tOCT_UINT32	ulFrameCnt512_1023Octets;
	tOCT_UINT32	ulFrameCnt1024_MaxOctets;

} tOCTVC1_OBM_ETHERNET_SWITCH_PORT_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_MODE
 		Ethernet switch port link mode information.

 Members:
	ulHalfDuplex10BaseTFlag
 		cOCT_TRUE when link is 10BASE-T half-duplex capable.
	ulFullDuplex10BaseTFlag
 		cOCT_TRUE when link is 10BASE-T full-duplex capable.
	ulHalfDuplex100BaseXFlag
 		cOCT_TRUE when link is 100BASE-X half-duplex capable.
	ulFullDuplex100BaseXFlag
 		cOCT_TRUE when link is 100BASE-X full-duplex capable.
	ulHalfDuplex100BaseTXFlag
 		cOCT_TRUE when link is 100BASE-TX half-duplex capable.
	ulFullDuplex100BaseTXFlag
 		cOCT_TRUE when link is 100BASE-TX full-duplex capable.
	ulHalfDuplex1000BaseTFlag
 		cOCT_TRUE when link is 1000BASE-T half-duplex capable.
	ulFullDuplex1000BaseTFlag
 		cOCT_TRUE when link is 1000BASE-T full-duplex capable.
	ulPauseCapableFlag
 		cOCT_TRUE when link is pause capable.
	ulAutoNegotiationAbilityFlag
 		cOCT_TRUE when link supports auto-negotiation.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulHalfDuplex10BaseTFlag;
	tOCT_BOOL32	ulFullDuplex10BaseTFlag;
	tOCT_BOOL32	ulHalfDuplex100BaseXFlag;
	tOCT_BOOL32	ulFullDuplex100BaseXFlag;
	tOCT_BOOL32	ulHalfDuplex100BaseTXFlag;
	tOCT_BOOL32	ulFullDuplex100BaseTXFlag;
	tOCT_BOOL32	ulHalfDuplex1000BaseTFlag;
	tOCT_BOOL32	ulFullDuplex1000BaseTFlag;
	tOCT_BOOL32	ulPauseCapableFlag;
	tOCT_BOOL32	ulAutoNegotiationAbilityFlag;

} tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_MODE;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_STATUS
 		Ethernet switch port link status information.

 Members:
	SupportedLinkMode
 		Supported link mode information..
	AdvertisedLinkMode
 		Advertised link mode information..
	ulLinkSpeed
 		Current link speed.
	ulLinkDuplex
 		Current link duplex.
	ulAutoNegotiationCompleteFlag
 		cOCT_TRUE when link auto-negotiation is completed.
	ulLinkDetectedFlag
 		cOCT_TRUE when link supports auto-negotiation.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_MODE	SupportedLinkMode;
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_MODE	AdvertisedLinkMode;
	tOCTVC1_OBM_ETH_SWITCH_LINK_SPEED_ENUM		ulLinkSpeed;
	tOCTVC1_OBM_ETH_SWITCH_LINK_DUPLEX_ENUM		ulLinkDuplex;
	tOCT_BOOL32									ulAutoNegotiationCompleteFlag;
	tOCT_BOOL32									ulLinkDetectedFlag;

} tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_STATUS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MONTHS_ENUM : 	The 12 months of the year.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_MONTHS_ENUM								tOCT_UINT32

#define cOCTVC1_OBM_MONTHS_ENUM_JANUARY						1		
#define cOCTVC1_OBM_MONTHS_ENUM_FEBRUARY					2		
#define cOCTVC1_OBM_MONTHS_ENUM_MARCH						3		
#define cOCTVC1_OBM_MONTHS_ENUM_APRIL						4		
#define cOCTVC1_OBM_MONTHS_ENUM_MAY							5		
#define cOCTVC1_OBM_MONTHS_ENUM_JUNE						6		
#define cOCTVC1_OBM_MONTHS_ENUM_JULY						7		
#define cOCTVC1_OBM_MONTHS_ENUM_AUGUST						8		
#define cOCTVC1_OBM_MONTHS_ENUM_SEPTEMBER					9		
#define cOCTVC1_OBM_MONTHS_ENUM_OCTOBER						10		
#define cOCTVC1_OBM_MONTHS_ENUM_NOVEMBER					11		
#define cOCTVC1_OBM_MONTHS_ENUM_DECEMBER					12		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_GPS_DATE_TIME
 		Date and tiem information as reported by the GPS.

 Members:
	ulDay
	ulMonth
	ulYear
	ulHour
	ulMinutes
	ulSeconds
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32				ulDay;
	tOCTVC1_OBM_MONTHS_ENUM	ulMonth;
	tOCT_UINT32				ulYear;
	tOCT_UINT32				ulHour;
	tOCT_UINT32				ulMinutes;
	tOCT_UINT32				ulSeconds;

} tOCTVC1_OBM_GPS_DATE_TIME;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_CARDINAL_DIRECTION_ENUM : 	The 4 cardinal directions
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_CARDINAL_DIRECTION_ENUM					tOCT_UINT32

#define cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_NORTH			1		
#define cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_SOUTH			2		
#define cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_EAST			3		
#define cOCTVC1_OBM_CARDINAL_DIRECTION_ENUM_WEST			4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_GPS_COORDINATE
 		GPS Latitude or longitude information structure.

 Members:
	ulDegrees
	ulMinutes
 		Minutes, times 10000.
	ulDirection
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulDegrees;
	tOCT_UINT32							ulMinutes;
	tOCTVC1_OBM_CARDINAL_DIRECTION_ENUM	ulDirection;

} tOCTVC1_OBM_GPS_COORDINATE;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_GPS_LOCATION
 		Location information, as reported by the GPS.

 Members:
	Latitude
	Longitude
	ulAltitude
 		Antenna altitude, in decimeters.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_OBM_GPS_COORDINATE	Latitude;
	tOCTVC1_OBM_GPS_COORDINATE	Longitude;
	tOCT_UINT32					ulAltitude;

} tOCTVC1_OBM_GPS_LOCATION;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_GPS_SAT_VIEW_INFO
 		Satellite in view detailed information, as reported by the GPS.

 Members:
	u8Id
 		Identifier of satellite in view.
	u8Snr
 		Signal to Noise Ratio, in dB (higher is better).
	usReserved
 		Reserved field.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT8	u8Id;
	tOCT_UINT8	u8Snr;
	tOCT_UINT16	usReserved;

} tOCTVC1_OBM_GPS_SAT_VIEW_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_POWER_UP_TYPE_ENUM : 	Reason the board has been powerd up.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_POWER_UP_TYPE_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_POWER_UP_TYPE_ENUM_UNDETERMINED			0		 	/* Unable to identify the reason why the board was powered up. */
#define cOCTVC1_OBM_POWER_UP_TYPE_ENUM_SWITCH				1		 	/* The board has been powered up by the power switch. */
#define cOCTVC1_OBM_POWER_UP_TYPE_ENUM_TIMER_WAKEUP			2		 	/* Board was woken up by the onboard timer. */
#define cOCTVC1_OBM_POWER_UP_TYPE_ENUM_CABLE_CONNECT		3		 	/* Board was woken up by connecting the power supply. */
#define cOCTVC1_OBM_POWER_UP_TYPE_ENUM_SOFT_REBOOT			4		 	/* Board was restarted as requested by software. */
#define cOCTVC1_OBM_POWER_UP_TYPE_ENUM_POST_ALARM_REBOOT	5		 	/* Board was restarted automatically after a shutdown caused by an alarm. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_RF_MUXING_MODE_ENUM : 	Different RF Muxing mode supported by board.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_RF_MUXING_MODE_ENUM							tOCT_UINT32

#define cOCTVC1_OBM_RF_MUXING_MODE_ENUM_STANDARD				0		 	/* Standard mode. */
#define cOCTVC1_OBM_RF_MUXING_MODE_ENUM_CROSS					1		 	/* Cross Radio mode. */
#define cOCTVC1_OBM_RF_MUXING_MODE_ENUM_SINGLE_DSP_DUAL_RADIO	2		 	/* Primary DSP is attached to 2 radios. */
#define cOCTVC1_OBM_RF_MUXING_MODE_ENUM_DUAL_DSP_SINGLE_RADIO	3		 	/* 2 DSPs are attached to a single radio. First DSP handles the tx path, while */
 																		/* second DSP handles the RX path. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_POWER_SOURCE_ENUM : 	Source from which the unit is currently drawing its power.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBM_POWER_SOURCE_ENUM						tOCT_UINT32

#define cOCTVC1_OBM_POWER_SOURCE_ENUM_DC					0		 	/* Unit is drawing its power from the DC jack. */
#define cOCTVC1_OBM_POWER_SOURCE_ENUM_BATTERY0				1		 	/* Unit is being powered by battery 0. */
#define cOCTVC1_OBM_POWER_SOURCE_ENUM_BATTERY1				2		 	/* Unit is being powered by battery 1. */

				

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
/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_SYSTEM_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulDhcpServerEnableFlag
 		cOCT_TRUE when the built-in DHCP server for booting DSPs is enabled.
	ulTftpServerEnableFlag
 		cOCT_TRUE when the built-in TFTP server for booting DSPs is enabled.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulDhcpServerEnableFlag;
	tOCT_BOOL32			ulTftpServerEnableFlag;

} tOCTVC1_OBM_MSG_SYSTEM_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulDhcpServerEnableFlag
		Default:	cOCTVC1_DO_NOT_MODIFY
 		cOCT_TRUE enables the built-in DHCP server for booting DSPs.
	ulTftpServerEnableFlag
		Default:	cOCTVC1_DO_NOT_MODIFY
 		cOCT_TRUE enables the built-in TFTP server for booting DSPs.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulDhcpServerEnableFlag;
	tOCT_BOOL32			ulTftpServerEnableFlag;

} tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_SYSTEM_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_OBM_MSG_SYSTEM_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_RSP

 Members:
	Header
 		OCTVC1 Message Header
	szLastErrorMsg
 		Last error message.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_INT8			szLastErrorMsg[cOCTVC1_OBM_ERROR_MSG_STRING_LENGTH];

} tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulDspId
 		DSP identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulDspId;

} tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_DSP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulDspId
 		DSP identifier
	LastAssignedIpAddress
 		DSP's last assigned IP address.
	MacAddress
 		DSP's base Mac address.
	ulBootProgress
 		DSP's boot progress information. gets updated as DSP booting porgresses.DSP's
 		base Mac address.
	BootStatus
 		Last reported DSP boot status.
	ulResetState
 		Reset signal state
	ulOscillatorOwnershipFlag
 		When true, the dsp has control of the board's main oscillator.
	ulMccInfractionCnt
 		Counter representing the number of MCC infractions for the DSP.
	szBootFileName
 		Name of the file to send to the DSP upon boot request.
	szLastFileName
 		Name of the file last sent to the DSP.
	szRunningApplication
 		Version stirng reported by the runnign DSP application.
	szPlugin
 		Complete path of the plugin hdnling this Dsp application.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID				ulDspId;
	tOCTVC1_IP_ADDRESS					LastAssignedIpAddress;
	tOCTVC1_MAC_ADDRESS					MacAddress;
	tOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM	ulBootProgress;
	tOCTVC1_OBM_BOOT_STATUS				BootStatus;
	tOCTVC1_OBM_SIGNAL_STATE_ENUM		ulResetState;
	tOCT_BOOL32							ulOscillatorOwnershipFlag;
	tOCT_UINT32							ulMccInfractionCnt;
	tOCT_INT8							szBootFileName[cOCTVC1_OBM_BOOT_FILE_NAME_LENGTH];
	tOCT_INT8							szLastFileName[cOCTVC1_OBM_BOOT_FILE_NAME_LENGTH];
	tOCT_INT8							szRunningApplication[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCT_INT8							szPlugin[cOCTVC1_OBM_FILENAME_STRING_LENGTH];

} tOCTVC1_OBM_MSG_BOARD_INFO_DSP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulDspId
 		DSP identifier
	ulState
		Default:	cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE
 		Reset signal state
	szFileName
 		Name of the file to send to the DSP upon reset release. Leave blank to keep
 		previous value.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID			ulDspId;
	tOCTVC1_OBM_SIGNAL_STATE_ENUM	ulState;
	tOCT_INT8						szFileName[cOCTVC1_OBM_BOOT_FILE_NAME_LENGTH];

} tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_RESET_DSP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulDspId
 		DSP identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulDspId;

} tOCTVC1_OBM_MSG_BOARD_RESET_DSP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD
 		List the DSPs present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_DSP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectList
 		Object name list.
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectList;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_DSP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulDspId
 		DSP identifier
	ulNextAssignedIp
 		Next IPv4 address to assign to the DSP by obmd's built-in DHCP server.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulDspId;
	tOCTVC1_IP_ADDRESS		ulNextAssignedIp;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulDspId
 		DSP identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulDspId;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_CMD
 		List the boards handled by this OBM instance.

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectList
 		Object List structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_OBM_MSG_BOARD_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Unique board identifier
	szSerial
 		Board serial number
	szModel
 		Board model
	szProjectId
 		Board-specific project Id.
	szSupplementalInfo
 		Board-specific supplemental information.
	ulEmicVersion
 		EMIC version.
	ulEmicBuildNumber
 		EMIC build number.
	ulCpldVersion
 		CPLD version.
	ulNumDsp
 		Number of DSPs attached to this board.
	ulNumGps
 		Number of GPS devices attached to this board.
	ulNumRfTransceiver
 		Number of RF Transceivers attached to this board.
	ulNumRfFrontEnds
 		Number of RF front-ends attached to this board.
	ulRfMuxingMode
 		Rf Muxing Mode of this Board.
	ulNumBatteries
 		Number of batteries attached to this board.
	ulPowerSource
 		Source from which the unit is currently drawing its power.
	ulEthernetSwitchFlag
 		cOCT_TRUE when an ethernet switch is attached to this board.
	MacAddress
 		Board's DSP-facing base Mac address.
	ulPowerUpType
 		Reason why the board was powered up.
	ulLastSleepDuration
 		Number of seconds the board has been asleep prior to the last powerup. Valid
 		only when PowerUpType == SWITCH and previous powerdown was caused by a
 		BOARD_STOP command.
	ulOscillatorOwner
 		Device currently controlling the board's main oscillator.
	ulClockTrackingConvergedFlag
 		cOCT_TRUE when the clock tracking has converged to a stable value.
	ulClockManagerMode
 		Mode of the clock manager
	ulClockManagerDiag
 		Diagnostic of the clock manager
	ulInputReferenceClock
 		Current input reference clock selection
	ulInputReferenceClockRequested
 		Requested input reference clock selection
	ulInputReferenceClockState
 		Current state of the input reference clock
	ulOutputReferenceClock
 		Current output reference clock selection
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_INDEX							ulBoardIndex;
	tOCT_INT8								szSerial[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCT_INT8								szModel[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCT_INT8								szProjectId[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCT_INT8								szSupplementalInfo[cOCTVC1_OBM_SUPPLEMENTAL_INFO_STRING_LENGTH];
	tOCT_UINT32								ulEmicVersion;
	tOCT_UINT32								ulEmicBuildNumber;
	tOCT_UINT32								ulCpldVersion;
	tOCT_UINT32								ulNumDsp;
	tOCT_UINT32								ulNumGps;
	tOCT_UINT32								ulNumRfTransceiver;
	tOCT_UINT32								ulNumRfFrontEnds;
	tOCTVC1_OBM_RF_MUXING_MODE_ENUM			ulRfMuxingMode;
	tOCT_UINT32								ulNumBatteries;
	tOCTVC1_OBM_POWER_SOURCE_ENUM			ulPowerSource;
	tOCT_BOOL32								ulEthernetSwitchFlag;
	tOCTVC1_MAC_ADDRESS						MacAddress;
	tOCTVC1_OBM_POWER_UP_TYPE_ENUM			ulPowerUpType;
	tOCT_UINT32								ulLastSleepDuration;
	tOCTVC1_OBM_DSP_ID_ENUM					ulOscillatorOwner;
	tOCT_BOOL32								ulClockTrackingConvergedFlag;
	tOCTVC1_OBM_CLOCK_MGR_MODE_ENUM			ulClockManagerMode;
	tOCTVC1_OBM_CLOCK_MGR_DIAG_ENUM			ulClockManagerDiag;
	tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM	ulInputReferenceClock;
	tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM	ulInputReferenceClockRequested;
	tOCTVC1_OBM_REFERENCE_CLOCK_STATE_ENUM	ulInputReferenceClockState;
	tOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM	ulOutputReferenceClock;

} tOCTVC1_OBM_MSG_BOARD_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
	ulInputReferenceClock
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Input reference clock selection
	ulOutputReferenceClock
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Output reference clock selection
	ulRfMuxingMode
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Rf Muxing Mode selection
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_INDEX							ulBoardIndex;
	tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM	ulInputReferenceClock;
	tOCTVC1_OBM_OUTPUT_REFERENCE_CLOCK_ENUM	ulOutputReferenceClock;
	tOCTVC1_OBM_RF_MUXING_MODE_ENUM			ulRfMuxingMode;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Unique board identifier
	ulVoltage
 		Board voltage reading in 100 mV unit.
	lDspSensorTemp
 		DSP current temperature in 1/16 degree Celsius units.
	lRfSensorTemp
 		Analog RF circuit current temperature in 1/16 degree Celsius units.
	ulFanErrorFlag
 		cOCT_TRUE when the fan has an error condition.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;
	tOCT_UINT32			ulVoltage;
	tOCT_INT32			lDspSensorTemp;
	tOCT_INT32			lRfSensorTemp;
	tOCT_BOOL32			ulFanErrorFlag;

} tOCTVC1_OBM_MSG_BOARD_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STOP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
	ulAction
		Default:	cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_SHUT_DOWN
 		Board stop action to be performed.
	WakeupDateTime
 		Date and time at which the board should be woken up.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_BOARD_STOP_ACTION_ENUM	ulAction;
	tOCTVC1_OBM_GPS_DATE_TIME			WakeupDateTime;

} tOCTVC1_OBM_MSG_BOARD_STOP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STOP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_STOP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
	AntennaConnectorId
 		When ulComponentType is RF_FRONTEND, this is one of the antenna connectors
 		identifying the Rf Frontend to be updated.
	ulComponentType
		Default:	cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_EMIC
 		Updateable component type
	szFilename
 		Filename (accessible from obmd's local filesystem) of the updateable
 		component's firmware.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_INDEX								ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID			AntennaConnectorId;
	tOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM	ulComponentType;
	tOCT_INT8									szFilename[cOCTVC1_OBM_FILENAME_STRING_LENGTH];

} tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_UPDATE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_UPDATE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
	ulComponentType
		Default:	cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND
 		Attachable component type
	szManufacturer
 		Manufacturer of the component to attach.
	szModel
 		Model of the component to attach.
	szAttachInfo
 		Supplementary info supplied to the corresponding plugin on attach.
 		Plugin-specific.
	aAntennaConnectors
 		When ulComponentType is RF_FRONTEND, this is the list of antenna connectors to
 		which the new Rf Frontend is connected.
	ulNumAntennaConnectors
		Default:	0
 		Number of valid entries in the aAntennaConnectors array.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_INDEX								ulBoardIndex;
	tOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM	ulComponentType;
	tOCT_INT8									szManufacturer[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCT_INT8									szModel[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCT_INT8									szAttachInfo[cOCTVC1_OBM_ATTACH_INFO_STRING_LENGTH];
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID			aAntennaConnectors[cOCTVC1_OBM_MAX_ANTENNA_CONNECTORS];
	tOCT_UINT32									ulNumAntennaConnectors;

} tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_ATTACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_ATTACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_DETACH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Unique board identifier
	ulComponentType
		Default:	cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND
 		Attachable component type
	aAntennaConnectors
 		When ulComponentType is RF_FRONTEND, this is the list of antenna connectors to
 		which the new Rf Frontend is connected.
	ulNumAntennaConnectors
		Default:	0
 		Number of valid entries in the aAntennaConnectors array.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_INDEX								ulBoardIndex;
	tOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM	ulComponentType;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID			aAntennaConnectors[cOCTVC1_OBM_MAX_ANTENNA_CONNECTORS];
	tOCT_UINT32									ulNumAntennaConnectors;

} tOCTVC1_OBM_MSG_BOARD_DETACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_DETACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Unique board identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulBoardIndex;

} tOCTVC1_OBM_MSG_BOARD_DETACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulGpsId
 		Gps identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulGpsId;

} tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_GPS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulGpsId
 		Gps identifier
	szDescription
 		GPS device's model.
	ulResetState
 		Reset signal state
	ulAntenna
 		Current antenna selection.
	ulSetSystemTimeFlag
 		True if obm updates the system time with the GPS module's reported date & time,
 		when it is valid.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID			ulGpsId;
	tOCT_INT8						szDescription[cOCTVC1_OBM_INFO_STRING_LENGTH];
	tOCTVC1_OBM_SIGNAL_STATE_ENUM	ulResetState;
	tOCTVC1_OBM_GPS_ANTENNA_ENUM	ulAntenna;
	tOCT_BOOL32						ulSetSystemTimeFlag;

} tOCTVC1_OBM_MSG_BOARD_INFO_GPS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulGpsId
 		Gps identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulGpsId;

} tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_GPS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulGpsId
 		Gps identifier
	ulFix
 		GPS fix information
	DateTime
 		Date and Time information last reported by the GPS. Note that this can be
 		valid even when the GPS is not currently fixed.
	Location
 		Location information last reported by the GPS module. Latitude and longitude
 		information are valid if the GPS reports at least a 2d Fix. Altitude is valid
 		if the GPS reports a 3d fix.
	ulSatellitesInView
 		Number of satellites in view.
	ulNumActiveSatellite
 		Number of active satellites used for position fix.
	abyActiveSatelliteId
 		Identifiers of satellites used for position fix.
	SatelliteInViewInfo
 		Satellite in view information last reported by the GPS module.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID			ulGpsId;
	tOCTVC1_OBM_GPS_FIX_ENUM		ulFix;
	tOCTVC1_OBM_GPS_DATE_TIME		DateTime;
	tOCTVC1_OBM_GPS_LOCATION		Location;
	tOCT_UINT32						ulSatellitesInView;
	tOCT_UINT32						ulNumActiveSatellite;
	tOCT_UINT8						abyActiveSatelliteId[cOCTVC1_OBM_MAX_ACTIVE_SATELLITE];
	tOCTVC1_OBM_GPS_SAT_VIEW_INFO	SatelliteInViewInfo[cOCTVC1_OBM_MAX_ACTIVE_SATELLITE];

} tOCTVC1_OBM_MSG_BOARD_STATS_GPS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulGpsId
 		Gps identifier
	ulState
 		Reset signal state
	ulColdStartFlag
 		Perform a GPS cold start. Valid only if State !=
 		cOCTVC1_OBM_SIGNAL_STATE_ENUM_ASSERT.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID			ulGpsId;
	tOCTVC1_OBM_SIGNAL_STATE_ENUM	ulState;
	tOCT_BOOL32						ulColdStartFlag;

} tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_RESET_GPS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulGpsId
 		Gps identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulGpsId;

} tOCTVC1_OBM_MSG_BOARD_RESET_GPS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulGpsId
 		Gps identifier
	ulAntennaSelection
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Antenna that is to be used by the GPS module.
	ulSetSystemTimeFlag
		Default:	cOCTVC1_DO_NOT_MODIFY
 		True if obm is to automatically update the system time with the GPS module's
 		reported date & time, when it is valid.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID			ulGpsId;
	tOCTVC1_OBM_GPS_ANTENNA_ENUM	ulAntennaSelection;
	tOCT_BOOL32						ulSetSystemTimeFlag;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulGpsId
 		Gps identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulGpsId;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD
 		List the GPSes present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_GPS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectList
 		Object name list.
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectList;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_GPS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the targeted RF FrontEnd.
	ulTxRfComponentBankIndex
		Default:	0
 		Tx RF component bank for which the RF component list is to be retrieved.
	ulRxRfComponentBankIndex
		Default:	0
 		Rx RF component bank for which the RF component list is to be retrieved.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCTVC1_INDEX						ulTxRfComponentBankIndex;
	tOCTVC1_INDEX						ulRxRfComponentBankIndex;

} tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the targeted RF FrontEnd.
	ulNumDiversityPath
 		Number of diversity path.
	aDiversityPathAntennaConnectorId
 		Diversity path antenna connector ids, in this RF FrontEnd.
	szTxBankInfo
 		TX Rf bank information string.
	szRxBankInfo
 		RX Rf bank information string.
	ulTxRfComponentBankIndex
 		Tx RF component bank index
	ulRxRfComponentBankIndex
 		Rx RF component bank index
	lTxGainDbQ9
 		Rf transceiver transmit direction gain, in Q9 format. Note that a negative
 		value indicates attenuation.
	lRxGainDbQ9
 		Rf transceiver receive direction gain, in Q9 format.
	ulNumStagesOffered
 		Number of amplification stages available on this RF port. Includes RF port
 		drivers that are in path.
	ulNumStagesActive
 		Number of amplification stages currently active on this RF port. Includes RF
 		port drivers that are
 		in path. A value of 0 indicates that all RF drivers & amplifiers are off. This
 		may not match
 		ulNumStagesRequested, depending on TxFilter settings and board design.
	ulNumStagesRequested
 		Number of amplification stages asked of obm.
	TxRfComponent
 		RF component available in the Tx direction of this RF port.
	RxRfComponent
 		RF component & attenuators available in the Rx direction of this RF port.
	ulNumTxRfComponent
 		Number of Tx RF component offered by this Rf Frontend.
	ulNumRxRfComponent
 		Number of Rx RF component offered by this Rf Frontend.
	ulTxRfComponentIndex
 		Index of the RF component currently in use in the Tx direction.
	ulRxRfComponentIndex
 		Index of the RF component currently in use in the Rx direction.
	ulNumTxRfComponentBanks
 		Number of RF component banks in the tx path.
	ulNumRxRfComponentBanks
 		Number of RF component banks in the rx path.
	ulDuplexMode
 		Current RF duplex mode setting.
	ulManagementMode
 		Management mode defining how the algorithms to adjust rf components, such as
 		the LNA, the attenuator..., are handled.
	szManufacturer
 		Rf frontend manufacturer.
	szModel
 		Rf frontend model.
	lTxPowerDbmQ9
 		Rf Frontend Tx output power, in Q9 format.
	szSupplementalInfo
 		Maunfacturer-specific supplemental information.
	ulRadioProfile
 		Current radio profile. Loosely corresponds to radio protocol.
	lTargetTxPowerDbmQ9
 		Rf Frontend Tx Target output power, in Q9 format.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCT_UINT32							ulNumDiversityPath;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	aDiversityPathAntennaConnectorId[cOCTVC1_OBM_MAX_RF_DIVERSITY_PATH];
	tOCT_INT8							szTxBankInfo[cOCTVC1_OBM_RF_BANK_INFO_STRING_LENGTH];
	tOCT_INT8							szRxBankInfo[cOCTVC1_OBM_RF_BANK_INFO_STRING_LENGTH];
	tOCTVC1_INDEX						ulTxRfComponentBankIndex;
	tOCTVC1_INDEX						ulRxRfComponentBankIndex;
	tOCT_INT32							lTxGainDbQ9;
	tOCT_INT32							lRxGainDbQ9;
	tOCT_UINT32							ulNumStagesOffered;
	tOCT_UINT32							ulNumStagesActive;
	tOCT_UINT32							ulNumStagesRequested;
	tOCTVC1_OBM_RF_COMPONENT_DESC		TxRfComponent[cOCTVC1_OBM_MAX_RF_COMPONENT_DESC];
	tOCTVC1_OBM_RF_COMPONENT_DESC		RxRfComponent[cOCTVC1_OBM_MAX_RF_COMPONENT_DESC];
	tOCT_UINT32							ulNumTxRfComponent;
	tOCT_UINT32							ulNumRxRfComponent;
	tOCT_UINT32							ulTxRfComponentIndex;
	tOCT_UINT32							ulRxRfComponentIndex;
	tOCT_UINT32							ulNumTxRfComponentBanks;
	tOCT_UINT32							ulNumRxRfComponentBanks;
	tOCTVC1_OBM_RF_DUPLEX_MODE_ENUM		ulDuplexMode;
	tOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM	ulManagementMode;
	tOCT_INT8							szManufacturer[cOCTVC1_OBM_RF_INFO_STRING_LENGTH];
	tOCT_INT8							szModel[cOCTVC1_OBM_RF_INFO_STRING_LENGTH];
	tOCT_INT32							lTxPowerDbmQ9;
	tOCT_INT8							szSupplementalInfo[cOCTVC1_OBM_RF_SUPPLEMENTAL_INFO_STRING_LENGTH];
	tOCTVC1_OBM_RADIO_PROFILE_ENUM		ulRadioProfile;
	tOCT_INT32							lTargetTxPowerDbmQ9;

} tOCTVC1_OBM_MSG_BOARD_INFO_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the targeted RF FrontEnd.
	ulTxRfComponentBankIndex
		Default:	0
 		Tx RF component bank index.
	ulRxRfComponentBankIndex
		Default:	0
 		Rx RF component bank index.
	ulNumStagesActive
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Number of amplification stages currently active on this RF port. Includes RF
 		port drivers that are in path. A value of 0 indicates that all RF drivers &
 		amplifiers are off.
	lTargetTxPowerDbmQ9
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Target Tx output power, in Q9 format.
	ulTxRfComponentIndex
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Index of the RF component to use in the Tx direction (or a bypass if selected).
	ulRxRfComponentIndex
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Index of the RF component to use in the Rx direction (or an attenuator if
 		selected).
	ulTxFrequencyKhz
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Frequency the DSP will transmit on.
	ulTxBandwidthKhz
		Default:	cOCTVC1_OBM_RF_DEFAULT_BANDWIDTH_KHZ
 		Bandwidth of the frequency the DSP will transmit on.
	ulRxFrequencyKhz
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Frequency the DSP will receive from.
	ulRxBandwidthKhz
		Default:	cOCTVC1_OBM_RF_DEFAULT_BANDWIDTH_KHZ
 		Bandwidth of the frequency the DSP will receive from.
	szBand
 		Frequency band the DSP uses (applies to both directions).
	ulPhyRole
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Whether the PHY acts as a base station or a UE. Allows to select Tx and Rx
 		frequencies given the selected band
	ulAllowMissingFiltersFlag
		Default:	cOCT_TRUE
 		When ulTxFrequencyKhz and ulRxFrequencyKhz or ulBand and ulPhyRole are set, and
 		the RfFrontend is not equipped with suitable filters, this field specifies
 		whether or not
 		no filtering (bypass) is to be selected if possible. Otherwise, an error is
 		returned in
 		these conditions.
	ulDuplexMode
		Default:	cOCTVC1_DO_NOT_MODIFY
 		RF duplex mode setting.
	ulManagementMode
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Management mode defining how the algorithms to adjust rf components, such as
 		the LNA, the attenuator..., are handled.
	lTxGainDbQ9
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Rf transceiver transmit direction gain, in Q9 format. Note that a negative
 		value indicates attenuation.
	lRxGainDbQ9
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Rf transceiver receive direction gain, in Q9 format.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCTVC1_INDEX						ulTxRfComponentBankIndex;
	tOCTVC1_INDEX						ulRxRfComponentBankIndex;
	tOCT_UINT32							ulNumStagesActive;
	tOCT_INT32							lTargetTxPowerDbmQ9;
	tOCT_UINT32							ulTxRfComponentIndex;
	tOCT_UINT32							ulRxRfComponentIndex;
	tOCT_UINT32							ulTxFrequencyKhz;
	tOCT_UINT32							ulTxBandwidthKhz;
	tOCT_UINT32							ulRxFrequencyKhz;
	tOCT_UINT32							ulRxBandwidthKhz;
	tOCT_INT8							szBand[cOCTVC1_OBM_RF_BAND_STRING_LENGTH];
	tOCTVC1_OBM_PHY_ROLE_ENUM			ulPhyRole;
	tOCT_BOOL32							ulAllowMissingFiltersFlag;
	tOCTVC1_OBM_RF_DUPLEX_MODE_ENUM		ulDuplexMode;
	tOCTVC1_OBM_RF_MANAGEMENT_MODE_ENUM	ulManagementMode;
	tOCT_INT32							lTxGainDbQ9;
	tOCT_INT32							lRxGainDbQ9;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the targeted RF FrontEnd.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD
 		List the Rf interfaces present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	RfAntennaConnectorIdCursor
 		Rf Antenna Connector Id Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_GET_CURSOR	RfAntennaConnectorIdCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	RfAntennaConnectorIdCursor
 		Rf Antenna Connector Id Cursor.
	ulRfAntennaConnectorIdCount
 		Number of valid TrxId in aTrxId
	aRfAntennaConnectorId
 		Array containing the listed RfAntennaConnectorId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_GET_CURSOR	RfAntennaConnectorIdCursor;
	tOCT_UINT32										ulRfAntennaConnectorIdCount;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_CURSOR		aRfAntennaConnectorId[cOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID_LIST_MAX_ENTRY];

} tOCTVC1_OBM_MSG_BOARD_LIST_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD
 		Retrieves the current state of the Rf Frontend.

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the targeted RF FrontEnd.
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		cOCT_TRUE to clear all the flags after read.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCT_BOOL32							ulResetStatsFlag;

} tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the targeted RF FrontEnd.
	AlarmInfo
 		Alarm information.
	alTemperature
 		Temperature readings reported by the Rf Frontend's sensors.
	ulPowerConsumptionMw
 		Current power consumption in milliwatts.
	alMeasuredTxPowerDbmQ9
 		Measured output power readings, in Q9 format. There is one entry per
 		measurement point on the Rf Frontend (refer to the manufacturer's RF Frontend
 		documentation).
	alAdjustedTxPowerDbmQ9
 		Measured output power adjusted with external component gain/attenuation, in Q9
 		format. There is one entry per measurement point on the Rf Frontend (refer to
 		the manufacturer's RF Frontend documentation).
	alMeasuredRxPowerDbmQ9
 		Measured input power readings, in Q9 format. There is one entry per measurement
 		point on the Rf Frontend (refer to the manufacturer's RF Frontend
 		documentation).
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCTVC1_OBM_RF_ALARM_INFO			AlarmInfo;
	tOCT_INT32							alTemperature[cOCTVC1_OBM_MAX_TEMP_SENSORS];
	tOCT_UINT32							ulPowerConsumptionMw;
	tOCT_INT32							alMeasuredTxPowerDbmQ9[cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS];
	tOCT_INT32							alAdjustedTxPowerDbmQ9[cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS];
	tOCT_INT32							alMeasuredRxPowerDbmQ9[cOCTVC1_OBM_MAX_POWER_MEASUREMENT_POINTS];

} tOCTVC1_OBM_MSG_BOARD_STATS_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulBusId
 		I2c bus identifier
	ulNumBytes
		Default:	1
 		Bytes to read on the i2c interface
	bySlave
 		Address of the slave on the I2c bus
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBusId;
	tOCT_UINT32				ulNumBytes;
	tOCT_UINT8				bySlave;

} tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_READ_I2C_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulBusId
 		I2c bus identifier
	abyData
 		Data read from the I2C bus
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBusId;
	tOCT_UINT8				abyData[cOCTVC1_OBM_MAX_I2C_BYTES];

} tOCTVC1_OBM_MSG_BOARD_READ_I2C_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulBusId
 		I2c bus identifier
	ulNumBytes
 		Number of valid bytes in abyData
	bySlave
 		Address of the slave on the I2c bus
	abyData
 		Data that is to be sent on the I2C bus, excluding the slave address.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBusId;
	tOCT_UINT32				ulNumBytes;
	tOCT_UINT8				bySlave;
	tOCT_UINT8				abyData[cOCTVC1_OBM_MAX_I2C_BYTES];

} tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulBusId
 		I2c bus identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBusId;

} tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD
 		List the i2c busses present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_I2C_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectList
 		Object name list.
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectList;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_I2C_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulPowerSwitchId
		Default:	0
 		Power switch identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulPowerSwitchId;

} tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulPowerSwitchId
 		Power switch identifier
	ulDownEventTimeMs
 		Minimum time to wait before declaring that the user requested a powerdown, in
 		milliseconds.
	ulUpEventTimeMs
 		Minimum time to wait before declaring that the user requested a powerup, in
 		milliseconds.
	ulBypassFlag
 		OCT_TRUE when it is desired that the system be switched on whenever the power
 		supply is connected.
	ulBypassMode
 		Condition under which the unit is powered up. Applicable when ulBypassFlag is
 		set to OCT_TRUE.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_INDEX								ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID						ulPowerSwitchId;
	tOCT_UINT32									ulDownEventTimeMs;
	tOCT_UINT32									ulUpEventTimeMs;
	tOCT_BOOL32									ulBypassFlag;
	tOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM	ulBypassMode;

} tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulPowerSwitchId
		Default:	0
 		Power switch identifier
	ulDownEventTimeMs
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Minimum time to wait before declaring that the user requested a powerdown, in
 		milliseconds.
	ulUpEventTimeMs
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Minimum time to wait before declaring that the user requested a powerup, in
 		milliseconds.
	ulBypassFlag
		Default:	cOCTVC1_DO_NOT_MODIFY
 		OCT_TRUE when it is desired that the system be switched on whenever the power
 		supply is connected.
	ulBypassMode
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Bypass mode used when ulBypassFlag is set.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_INDEX								ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID						ulPowerSwitchId;
	tOCT_UINT32									ulDownEventTimeMs;
	tOCT_UINT32									ulUpEventTimeMs;
	tOCT_BOOL32									ulBypassFlag;
	tOCTVC1_OBM_POWER_SWITCH_BYPASS_MODE_ENUM	ulBypassMode;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulPowerSwitchId
 		Power switch identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulPowerSwitchId;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD
 		List the power switches present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectList
 		Object name list.
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectList;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulBatteryId
		Default:	0
 		Battery identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBatteryId;

} tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulBatteryId
 		Battery identifier
	ulBatteryPowerLevel
 		Battery power level in percentage.
	ulBatteryChargingFlag
 		OCT_TRUE when the battery is currently being charged.
	ulBatteryFaultFlag
 		OCT_TRUE for battery fault.
	ulBatteryTempFaultFlag
 		OCT_TRUE when the battery charging is suspended because measured battery
 		temperature is out of allowed range.
	ulBatteryLowFlag
 		OCT_TRUE when battery is low; Emergency shutdown is imminent.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBatteryId;
	tOCT_UINT32				ulBatteryPowerLevel;
	tOCT_BOOL32				ulBatteryChargingFlag;
	tOCT_BOOL32				ulBatteryFaultFlag;
	tOCT_BOOL32				ulBatteryTempFaultFlag;
	tOCT_BOOL32				ulBatteryLowFlag;

} tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD
 		List the batteries present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectList
 		Object name list.
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectList;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD
 		This command reads all the counters for a single physical port on the selected
 		device and than clears them if requested.

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulEthernetSwitchId
		Default:	0
 		Ethernet Switch identifier
	ulPortId
		Default:	0
 		Port identifier to read and/or clear all the statistic counters.
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		cOCT_TRUE to clear all the counters after read.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulEthernetSwitchId;
	tOCT_UINT32				ulPortId;
	tOCT_BOOL32				ulResetStatsFlag;

} tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulEthernetSwitchId
 		Ethernet Switch identifier
	ulPortId
 		Port identifier for which the statistic counters are returned.
	PortStats
 		Ethernet switch port statistics counters.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_INDEX							ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID					ulEthernetSwitchId;
	tOCT_UINT32								ulPortId;
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_STATS	PortStats;

} tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD
 		This command returns information on the ethernet switch configuration.

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulEthernetSwitchId
		Default:	0
 		Ethernet Switch identifier
	ulLinkStatusPortId
		Default:	0
 		Link status port identifier to read link status information.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulEthernetSwitchId;
	tOCT_UINT32				ulLinkStatusPortId;

} tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulEthernetSwitchId
 		Ethernet Switch identifier
	ulPortMirrorSrcList
 		Each bit (only the low 7 bits) represents a port (bit0 = port 0, bit1 = port 1,
 		...). When a bit is set, frames that ingress or egress the port will also be
 		forwared to ulPortMirrorDst.
	ulPortMirrorDst
 		Destination port for sources set in ulPortMirrorSrcList. Note : If NO Port
 		destination is set, the value cOCTVC1_OBM_ETHERNET_SWITCH_PORT_MIRROR_DST_NONE
 		will be returned.
	aPortVlanMapping
 		Each bit (only the low 7 bits) represents a port (bit0 = port 0, bit1 = port 1,
 		...). They specify which ouput ports this input port can send frames to. For
 		example, setting PortVlanMapping[2] to 3 means that port 2 can only send frames
 		to ports 0 and 1.
	ulLinkStatusPortId
 		Link status port identifier of the readed link status.
	LinkStatus
 		Link status information.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_INDEX									ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID							ulEthernetSwitchId;
	tOCT_UINT32										ulPortMirrorSrcList;
	tOCT_UINT32										ulPortMirrorDst;
	tOCT_UINT32										aPortVlanMapping[cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT];
	tOCT_UINT32										ulLinkStatusPortId;
	tOCTVC1_OBM_ETHERNET_SWITCH_PORT_LINK_STATUS	LinkStatus;

} tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD
 		List the ethernet switch present on this board.

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectList
 		Object name list.
	SubObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectList;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectCursor;

} tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD
 		This command modifies ethernet switch configurations.

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
		Default:	0
 		Board index
	ulEthernetSwitchId
		Default:	0
 		Ethernet Switch identifier
	ulPortMirrorSrcList
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Each bit (only the low 7 bits) represents a port (bit0 = port 0, bit1 = port 1,
 		...). When a bit is set, frames that ingress or egress the port will also be
 		forwared to ulPortMirrorDst.
	ulPortMirrorDst
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Destination port for sources set in ulPortMirrorSrcList. Note : To set NO Port
 		destination, the value cOCTVC1_OBM_ETHERNET_SWITCH_PORT_MIRROR_DST_NONE must be
 		used.
	aPortVlanMapping
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Each bit (only the low 7 bits) represents a port (bit0 = port 0, bit1 = port 1,
 		...). They specify which ouput ports this input port can send frames to. For
 		example, setting PortVlanMapping[2] to 3 means that port 2 can only send frames
 		to ports 0 and 1.
	ulRestartAutoNegotiationPortId
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Restart auto-negotiation on port ID specified.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulEthernetSwitchId;
	tOCT_UINT32				ulPortMirrorSrcList;
	tOCT_UINT32				ulPortMirrorDst;
	tOCT_UINT32				aPortVlanMapping[cOCTVC1_OBM_ETHERNET_SWITCH_MAX_NUM_PORT];
	tOCT_UINT32				ulRestartAutoNegotiationPortId;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulBoardIndex
 		Board index
	ulEthernetSwitchId
 		Ethernet Switch identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulEthernetSwitchId;

} tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_RSP;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_obm_evt.h"

#endif /* __OCTVC1_OBM_API_H__ */

