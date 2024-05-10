/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_MAIN_ID.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the identifiers for the MAIN API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_MAIN_ID_H__
#define __OCTVC1_MAIN_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_main_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_MAIN_MSG_TARGET_RESET_CID                        ( ( 0x004 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_NO_RESPONSE_FLAG  ) 
#define cOCTVC1_MAIN_MSG_TARGET_INFO_CID                         ( 0x005 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_ERASE_CID                           ( ( 0x006 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_LOG_INFO_CID                            ( 0x007 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_STATS_CID                           ( 0x008 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_INFO_TRACE_CID                      ( 0x009 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_START_TRACE_CID                     ( 0x00a + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_STOP_TRACE_CID                      ( 0x00b + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_ERASE_TRACE_CID                     ( 0x00c + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_STATS_TRACE_CID                     ( 0x00d + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_INFO_CPU_USAGE_CID              ( 0x00e + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_OPEN_CID                           ( ( 0x00f + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_FILE_CLOSE_CID                          ( ( 0x010 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_REMOVE_FILE_CID             ( ( 0x011 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_DELETE_FILE_CID             cOCTVC1_MAIN_MSG_FILE_SYSTEM_REMOVE_FILE_CID /* OCTVC1_RENAMED_API */
#define cOCTVC1_MAIN_MSG_FILE_WRITE_CID                          ( ( 0x012 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_FILE_READ_CID                           ( 0x013 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_INFO_CID                           ( 0x014 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_LIST_CID                           ( 0x015 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_CID                    ( 0x016 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_INFO_FILE_CID               ( 0x017 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_INFO_CID                        ( 0x018 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_LIST_CID                        ( 0x019 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_MONITOR_CPU_USAGE_CID           ( 0x01a + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_STATS_CPU_USAGE_CID             ( 0x01c + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_LIST_SESSION_CID             ( 0x01d + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_INFO_SESSION_CID             ( 0x01e + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_INFO_SESSION_EVT_CID         ( 0x01f + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_MODIFY_SESSION_EVT_CID       ( 0x020 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_INFO_SESSION_HEARTBEAT_CID   ( 0x021 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_STATS_SESSION_HEARTBEAT_CID  ( 0x022 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_START_SESSION_HEARTBEAT_CID  ( 0x023 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_STOP_SESSION_HEARTBEAT_CID   ( 0x024 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_MODIFY_SESSION_HEARTBEAT_CID ( 0x025 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_STOP_CID                    ( ( 0x027 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_APPLICATION_INFO_CID                    ( 0x028 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_INFO_SYSTEM_CID             ( 0x029 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_LIST_MODULE_CID             ( 0x02a + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_INFO_MODULE_CID             ( 0x02b + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_STATS_MODULE_CID            ( 0x02c + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_ADD_FILE_CID                ( 0x02d + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_INFO_STREAM_CID                     ( 0x02e + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_START_STREAM_CID                    ( 0x02f + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LOG_STOP_STREAM_CID                     ( 0x030 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_START_MODULE_CID            ( ( 0x031 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_APPLICATION_STOP_MODULE_CID             ( ( 0x032 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_CID                    ( 0x033 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_OPEN_CID                    ( 0x034 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LICENSING_STATS_CID                     ( 0x035 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LICENSING_INFO_FEATURES_CID             ( 0x036 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LICENSING_LIST_FEATURES_CID             ( 0x037 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_STOP_FILE_TRANSFER_CID      ( 0x038 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_WRITE_FILE_TRANSFER_CID     ( ( 0x039 + cOCTVC1_MAIN_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_READ_FILE_TRANSFER_CID      ( 0x03a + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_FIND_FILE_CID               ( 0x03b + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_CLOSE_CID                   ( 0x03c + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_FIND_CID                    ( 0x03d + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_STATS_FILE_TRANSFER_CID     ( 0x03e + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_LIST_FILE_CID               ( 0x03f + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_START_FILE_TRANSFER_CID     ( 0x040 + cOCTVC1_MAIN_CID_BASE )
#define cOCTVC1_MAIN_MSG_LICENSING_INFO_MCC_CONFIG_CID           ( 0x047 + cOCTVC1_MAIN_CID_BASE )

#define cOCTVC1_MAIN_CID_MAX                                     (( 0x048 + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_MAIN_MSG_PROCESS_DUMP_EID                      ( 0x0001 + cOCTVC1_MAIN_EID_BASE )
#define cOCTVC1_MAIN_MSG_API_SYSTEM_SESSION_HEARTBEAT_EID      ( 0x0002 + cOCTVC1_MAIN_EID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_CPU_USAGE_REPORT_EID          ( 0x0003 + cOCTVC1_MAIN_EID_BASE )
#define cOCTVC1_MAIN_MSG_APPLICATION_STATE_CHANGE_EID          ( 0x0004 + cOCTVC1_MAIN_EID_BASE )
#define cOCTVC1_MAIN_MSG_PROCESS_STATE_CHANGE_EID              ( 0x0005 + cOCTVC1_MAIN_EID_BASE )
#define cOCTVC1_MAIN_MSG_LICENSING_STATE_CHANGE_EID            ( 0x0006 + cOCTVC1_MAIN_EID_BASE )

#define cOCTVC1_MAIN_EID_MAX                                   (( 0x0007 + 1 ) & 0xFFFF)

/****************************************************************************
	Module Data IDs
 ****************************************************************************/
#define cOCTVC1_MAIN_MSG_LOG_DATA_MID                              ( 0x0000 + cOCTVC1_MAIN_MID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_REQUEST_FILE_TRANSFER_MID     ( 0x0001 + cOCTVC1_MAIN_MID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_REQUEST_ACK_FILE_TRANSFER_MID ( 0x0002 + cOCTVC1_MAIN_MID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_ABORT_FILE_TRANSFER_MID       ( 0x0003 + cOCTVC1_MAIN_MID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_DATA_FILE_TRANSFER_MID        ( 0x0004 + cOCTVC1_MAIN_MID_BASE )
#define cOCTVC1_MAIN_MSG_FILE_SYSTEM_DATA_ACK_FILE_TRANSFER_MID    ( 0x0005 + cOCTVC1_MAIN_MID_BASE )

#define cOCTVC1_MAIN_MID_MAX                                       (( 0x0005 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_MAIN_ID_H__ */

