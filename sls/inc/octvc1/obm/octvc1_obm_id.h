/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_ID.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the identifiers for the OBM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.7.0-B435 (24/10/2018)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_ID_H__
#define __OCTVC1_OBM_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_obm_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_OBM_MSG_SYSTEM_INFO_CID                  ( 0x001 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_SYSTEM_MODIFY_CID                ( 0x002 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CID         ( 0x010 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CID          ( 0x011 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_INFO_DSP_CID               ( ( 0x020 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_RESET_DSP_CID              ( ( 0x021 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_LIST_DSP_CID               ( 0x022 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CID             ( 0x023 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_LIST_CID                   ( 0x030 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_INFO_CID                   ( ( 0x031 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_MODIFY_CID                 ( 0x032 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_STATS_CID                  ( ( 0x033 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_STOP_CID                   ( 0x034 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_UPDATE_CID                 ( ( 0x035 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_ATTACH_CID                 ( ( 0x036 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_DETACH_CID                 ( 0x037 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_INFO_GPS_CID               ( 0x040 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_STATS_GPS_CID              ( 0x041 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_RESET_GPS_CID              ( ( 0x042 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CID             ( 0x043 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_LIST_GPS_CID               ( 0x044 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_INFO_RF_CID                ( ( 0x050 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CID              ( ( 0x051 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_LIST_RF_CID                ( 0x052 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_STATS_RF_CID               ( 0x053 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_READ_I2C_CID               ( 0x070 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CID              ( 0x071 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_LIST_I2C_CID               ( 0x072 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CID      ( 0x080 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CID    ( 0x081 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CID      ( 0x082 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CID          ( 0x090 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CID           ( 0x092 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CID  ( ( 0x0a0 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CID   ( ( 0x0a1 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 
#define cOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CID   ( 0x0a2 + cOCTVC1_OBM_CID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CID ( ( 0x0a3 + cOCTVC1_OBM_CID_BASE )| cOCTVC1_MSG_MID_PROCESSING_FLAG  ) 

#define cOCTVC1_OBM_CID_MAX                              (( 0x0a3 + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_OBM_MSG_BOARD_GPS_STATE_CHANGE_EID     ( 0x0001 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_POWER_SWITCH_CHANGE_EID  ( 0x0002 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_BATTERY_CHANGE_EID       ( 0x0004 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_TEMPERATURE_ALARM_EID    ( 0x0008 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_RF_ALARM_EID             ( 0x0010 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_FAN_ALARM_EID            ( 0x0020 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_DSP_BOOT_PROGRESS_EID    ( 0x0040 + cOCTVC1_OBM_EID_BASE )
#define cOCTVC1_OBM_MSG_BOARD_REF_CLOCK_OVERRIDDEN_EID ( 0x0080 + cOCTVC1_OBM_EID_BASE )

#define cOCTVC1_OBM_EID_MAX                            (( 0x0080 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_OBM_ID_H__ */

