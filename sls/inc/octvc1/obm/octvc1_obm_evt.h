/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_EVT.h
Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the event definition of the OBM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.5.0-B393 (07/02/2018)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_EVT_H__
#define __OCTVC1_OBM_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_obm_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_TEMPERATURE_ALARM_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulHighTempWarningFlag
 		cOCT_TRUE when the measured temperature has exceeded the high temperature
 		warning threshold.
	ulLowTempWarningFlag
 		cOCT_TRUE when the measured temperature was below the low temperature warning
 		threshold.
	lDspSensorTemp
 		DSP current temperature in 1/16 degree Celsius units.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCT_BOOL32				ulHighTempWarningFlag;
	tOCT_BOOL32				ulLowTempWarningFlag;
	tOCT_INT32				lDspSensorTemp;

} tOCTVC1_OBM_MSG_BOARD_TEMPERATURE_ALARM_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_REF_CLOCK_OVERRIDDEN_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulInputReferenceClock
 		Current input reference clock selection
	ulInputReferenceClockRequested
 		Requested input reference clock selection
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER					Header;
	tOCTVC1_INDEX							ulBoardIndex;
	tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM	ulInputReferenceClock;
	tOCTVC1_OBM_INPUT_REFERENCE_CLOCK_ENUM	ulInputReferenceClockRequested;

} tOCTVC1_OBM_MSG_BOARD_REF_CLOCK_OVERRIDDEN_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_RF_ALARM_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	AntennaConnectorId
 		Antenna connector identifying the Rf Frontend which caused the event.
	AlarmInfo
 		Alarm information.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_OBM_RF_ANTENNA_CONNECTOR_ID	AntennaConnectorId;
	tOCTVC1_OBM_RF_ALARM_INFO			AlarmInfo;

} tOCTVC1_OBM_MSG_BOARD_RF_ALARM_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_DSP_BOOT_PROGRESS_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulDspId
 		DSP identifier
	ulBootProgress
 		DSP's boot progress information. gets updated as DSP booting porgresses.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_INDEX						ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID				ulDspId;
	tOCTVC1_OBM_DSP_BOOT_PROGRESS_ENUM	ulBootProgress;

} tOCTVC1_OBM_MSG_BOARD_DSP_BOOT_PROGRESS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_GPS_STATE_CHANGE_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulGpsId
 		Gps identifier
	ulPreviousFix
 		Previous GPS fix status.
	ulNewFix
 		New GPS fix status.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER		Header;
	tOCTVC1_INDEX				ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID		ulGpsId;
	tOCTVC1_OBM_GPS_FIX_ENUM	ulPreviousFix;
	tOCTVC1_OBM_GPS_FIX_ENUM	ulNewFix;

} tOCTVC1_OBM_MSG_BOARD_GPS_STATE_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_POWER_SWITCH_CHANGE_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulPowerSwitchId
 		Power switch identifier
	ulOffMs
 		Number of milliseconds the power switch had been in the off position before
 		having been changed to the on position.
	ulOnMs
 		Number of milliseconds the power switch has been in the on position when the
 		event got triggered.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulPowerSwitchId;
	tOCT_UINT32				ulOffMs;
	tOCT_UINT32				ulOnMs;

} tOCTVC1_OBM_MSG_BOARD_POWER_SWITCH_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_BATTERY_CHANGE_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulBatteryId
 		Battery identifier
	ulBatteryChargingFlag
 		OCT_TRUE when the battery is currently being charged.
	ulBatteryFaultFlag
 		OCT_TRUE for battery fault.
	ulBatteryTempFaultFlag
 		OCT_TRUE when the battery charging is suspended because measured battery
 		temperature is out of allowed range.
	ulBatteryLowLevelWarnFlag
 		OCT_TRUE when battery is low; Emergency shutdown is imminent.
	ulBatteryPowerLevel
 		Battery power level in percentage.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulBatteryId;
	tOCT_BOOL32				ulBatteryChargingFlag;
	tOCT_BOOL32				ulBatteryFaultFlag;
	tOCT_BOOL32				ulBatteryTempFaultFlag;
	tOCT_BOOL32				ulBatteryLowLevelWarnFlag;
	tOCT_UINT32				ulBatteryPowerLevel;

} tOCTVC1_OBM_MSG_BOARD_BATTERY_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_OBM_MSG_BOARD_FAN_ALARM_EVT

 Members:
	Header
	ulBoardIndex
 		Board index
	ulFanIndex
 		Fan index
	ulFanErrorFlag
 		cOCT_TRUE when the fan has an error condition.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_INDEX			ulBoardIndex;
	tOCTVC1_SUB_OBJECT_ID	ulFanIndex;
	tOCT_BOOL32				ulFanErrorFlag;

} tOCTVC1_OBM_MSG_BOARD_FAN_ALARM_EVT;


#endif /* __OCTVC1_OBM_EVT_H__ */

