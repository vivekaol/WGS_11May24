/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_HW_ID.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the identifiers for the HW API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_HW_ID_H__
#define __OCTVC1_HW_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_hw_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_HW_MSG_PCB_INFO_CID                         ( 0x001 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CPU_CORE_STATS_CID                   ( 0x002 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CPU_CORE_INFO_CID                    ( 0x003 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CPU_CORE_LIST_CID                    ( 0x004 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_ETH_PORT_INFO_CID                    ( 0x005 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_ETH_PORT_LIST_CID                    ( 0x006 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_ETH_PORT_STATS_CID                   ( 0x007 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_ETH_PORT_MODIFY_CID                  ( 0x009 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_INFO_CID                     ( 0x00a + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_STATS_CID                    ( 0x00b + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_LIST_CID                     ( 0x00c + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_LIST_ANTENNA_CID             ( 0x00d + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_RX_CONFIG_CID   ( 0x00e + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CONFIG_CID   ( 0x00f + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CALIB_CID    ( 0x010 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CALIB_CID  ( 0x011 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_INFO_CID              ( 0x012 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_CID             ( 0x013 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_CID     ( 0x016 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_CID      ( 0x017 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_RX_CONFIG_CID ( 0x018 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CONFIG_CID ( 0x019 + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_FRONT_END_CID   ( 0x01b + cOCTVC1_HW_CID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_FRONT_END_CID ( 0x01c + cOCTVC1_HW_CID_BASE )

#define cOCTVC1_HW_CID_MAX                                  (( 0x01d + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_HW_MSG_CPU_CORE_EXEC_REPORT_EID                    ( 0x0001 + cOCTVC1_HW_EID_BASE )
#define cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATUS_CHANGE_EID            ( 0x0002 + cOCTVC1_HW_EID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_STATUS_CHANGE_EID                   ( 0x0003 + cOCTVC1_HW_EID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_ANTENNA_RX_CONFIG_STATUS_CHANGE_EID ( 0x0004 + cOCTVC1_HW_EID_BASE )
#define cOCTVC1_HW_MSG_RF_PORT_ANTENNA_TX_CONFIG_STATUS_CHANGE_EID ( 0x0005 + cOCTVC1_HW_EID_BASE )
#define cOCTVC1_HW_MSG_CLOCK_SYNC_MGR_DRIFT_CHANGE_EID             ( 0x0006 + cOCTVC1_HW_EID_BASE )

#define cOCTVC1_HW_EID_MAX                                         (( 0x0006 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_HW_ID_H__ */

