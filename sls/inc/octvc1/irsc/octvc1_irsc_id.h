/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_IRSC_ID.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the identifiers for the IRSC API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_IRSC_ID_H__
#define __OCTVC1_IRSC_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_irsc_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_IRSC_MSG_PROCESS_INFO_CID                  ( 0x001 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_STATS_CID                 ( 0x002 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_LIST_CID                  ( 0x003 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_INFO_IPC_PORT_CID         ( 0x004 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_STATS_IPC_PORT_CID        ( 0x005 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_LIST_IPC_PORT_CID         ( 0x006 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_INFO_TASK_CID             ( 0x007 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_STATS_TASK_CID            ( 0x008 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_LIST_TASK_CID             ( 0x009 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_OBJMGR_INFO_CID                   ( 0x00a + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_OBJMGR_STATS_CID                  ( 0x00b + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_OBJMGR_LIST_CID                   ( 0x00c + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_START_MONITORING_CID   ( 0x00d + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_STOP_MONITORING_CID    ( 0x00e + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_LIST_COMMAND_CID       ( 0x00f + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_STATS_COMMAND_CID      ( 0x010 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_LIST_SESSION_CID       ( 0x011 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_CID       ( 0x012 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_CID      ( 0x013 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_EVT_CID   ( 0x014 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_EVT_CID  ( 0x015 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_LIST_TAP_CID          ( 0x016 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_INFO_TAP_CID          ( 0x017 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_STATS_TAP_CID         ( 0x018 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_START_TAP_CID         ( 0x019 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_STOP_TAP_CID          ( 0x01a + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_ROUTER_INFO_CID                   ( 0x01b + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_ROUTER_STATS_CID                  ( 0x01c + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_ROUTER_INFO_STREAMER_CID          ( 0x01d + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_STATS_SYSTEM_CID      ( 0x01e + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_ROUTER_MODIFY_STREAMER_CID        ( 0x01f + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_STATS_MEMORY_CID          ( 0x020 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_SYSTEM_CID  ( 0x021 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_SYSTEM_CID ( 0x022 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_USER_CID    ( 0x023 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_USER_CID   ( 0x024 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_PAUSE_TAP_CID         ( 0x026 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_APPLICATION_RESUME_TAP_CID        ( 0x027 + cOCTVC1_IRSC_CID_BASE )
#define cOCTVC1_IRSC_MSG_LICENSING_EXECUTE_EXTERNAL_CID    ( ( 0x028 + cOCTVC1_IRSC_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 

#define cOCTVC1_IRSC_CID_MAX                               (( 0x028 + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_IRSC_MSG_PROCESS_DUMP_EID ( 0x0001 + cOCTVC1_IRSC_EID_BASE )

#define cOCTVC1_IRSC_EID_MAX              (( 0x0001 + 1 ) & 0xFFFF)

/****************************************************************************
	Module Data IDs
 ****************************************************************************/
#define cOCTVC1_IRSC_MSG_ROUTER_DATA_REQUEST_STREAMER_MID ( 0x0000 + cOCTVC1_IRSC_MID_BASE )

#define cOCTVC1_IRSC_MID_MAX                              (( 0x0000 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_IRSC_ID_H__ */

