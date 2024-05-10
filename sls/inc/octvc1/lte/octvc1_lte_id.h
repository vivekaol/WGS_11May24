/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LTE_ID.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the identifiers for the LTE API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_LTE_APP-04.03.00-B3607 (2019/04/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LTE_ID_H__
#define __OCTVC1_LTE_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_lte_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CID   ( 0x010 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CID ( 0x011 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_OPEN_CID          ( ( 0x020 + cOCTVC1_LTE_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_LTE_MSG_ENODEB_CLOSE_CID         ( 0x021 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_INFO_CID          ( 0x022 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_LIST_CID          ( 0x023 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CID     ( 0x030 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CID    ( 0x031 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CID   ( 0x032 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_START_CELL_CID    ( ( 0x033 + cOCTVC1_LTE_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CID     ( ( 0x034 + cOCTVC1_LTE_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_LTE_MSG_ENODEB_INFO_RF_CID       ( 0x040 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CID     ( 0x041 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CID      ( 0x050 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CID    ( 0x051 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CID     ( 0x052 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CID      ( 0x070 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CID    ( 0x071 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CID     ( 0x080 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CID   ( 0x081 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CID     ( 0x090 + cOCTVC1_LTE_CID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_START_BASS_CID    ( ( 0x092 + cOCTVC1_LTE_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CID    ( 0x093 + cOCTVC1_LTE_CID_BASE )

#define cOCTVC1_LTE_CID_MAX                      (( 0x093 + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_LTE_MSG_ENODEB_CELL_STATE_UPDATE_EID            ( 0x0001 + cOCTVC1_LTE_EID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_BASS_NEW_CELL_FOUND_EID          ( 0x0002 + cOCTVC1_LTE_EID_BASE )
#define cOCTVC1_LTE_MSG_ENODEB_BASS_CELL_SYNC_CHANGE_SOURCE_EID ( 0x0003 + cOCTVC1_LTE_EID_BASE )

#define cOCTVC1_LTE_EID_MAX                                     (( 0x0003 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_LTE_ID_H__ */

