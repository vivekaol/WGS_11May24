/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_ID.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the identifiers for the RUS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_ID_H__
#define __OCTVC1_RUS_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_rus_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_RUS_MSG_RFFI_OPEN_CID                    ( ( 0x040 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_RFFI_CLOSE_CID                   ( ( 0x041 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_RFFI_INFO_CID                    ( 0x042 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STATS_CID                   ( 0x043 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_LIST_CID                    ( 0x044 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CID           ( 0x045 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CID           ( 0x046 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CID               ( 0x047 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CID              ( 0x048 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_INFO_GSM_CID                ( 0x049 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STATS_GSM_CID               ( 0x04a + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CID            ( 0x04b + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_INFO_LTE_CID                ( 0x04c + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STATS_LTE_CID               ( 0x04d + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_OPEN_CID                  ( 0x050 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_CLOSE_CID                 ( 0x051 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_INFO_CID                  ( 0x052 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_STATS_CID                 ( 0x053 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_LIST_CID                  ( 0x054 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_START_CID                 ( ( 0x055 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_PLAYER_STOP_CID                  ( 0x056 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_MODIFY_CID                ( 0x057 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CID        ( 0x05a + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CID     ( 0x05b + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CID       ( 0x05c + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CID       ( 0x05d + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CID     ( 0x05e + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CID            ( ( 0x060 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_WNM_START_SEARCH_CID             ( 0x061 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CID              ( ( 0x062 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CID            ( 0x064 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CID              ( 0x065 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CID             ( 0x066 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_OPEN_CID                     ( ( 0x070 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_WNM_CLOSE_CID                    ( ( 0x071 + cOCTVC1_RUS_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_RUS_MSG_WNM_INFO_CID                     ( 0x072 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LIST_CID                     ( 0x074 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CID           ( 0x080 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CID          ( 0x081 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CID           ( 0x082 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CID            ( 0x083 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CID           ( 0x084 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CID            ( 0x085 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CID            ( 0x086 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CID           ( 0x087 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CID            ( 0x088 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CID       ( 0x090 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CID      ( 0x091 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CID       ( 0x092 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CID          ( 0x093 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CID ( 0x094 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CID             ( 0x095 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CID            ( 0x096 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CID             ( 0x097 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CID           ( 0x145 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CID         ( 0x146 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CID           ( 0x147 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CID          ( 0x148 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CID           ( 0x190 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_START_ATTACH_CID            ( 0x191 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CID             ( 0x192 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CID             ( 0x195 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CID            ( 0x196 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_OPEN_CID                    ( 0x197 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_CLOSE_CID                   ( 0x198 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_INFO_CID                    ( 0x199 + cOCTVC1_RUS_CID_BASE )
#define cOCTVC1_RUS_MSG_BASS_LIST_CID                    ( 0x19b + cOCTVC1_RUS_CID_BASE )

#define cOCTVC1_RUS_CID_MAX                              (( 0x19b + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_RUS_MSG_WNM_SEARCH_STATS_EID        ( 0x0001 + cOCTVC1_RUS_EID_BASE )
#define cOCTVC1_RUS_MSG_WNM_GSM_CELL_STATS_EID      ( 0x0002 + cOCTVC1_RUS_EID_BASE )
#define cOCTVC1_RUS_MSG_WNM_CDMA2000_CELL_STATS_EID ( 0x0003 + cOCTVC1_RUS_EID_BASE )
#define cOCTVC1_RUS_MSG_WNM_UMTS_CELL_STATS_EID     ( 0x0004 + cOCTVC1_RUS_EID_BASE )
#define cOCTVC1_RUS_MSG_WNM_LTE_CELL_STATS_EID      ( 0x0005 + cOCTVC1_RUS_EID_BASE )
#define cOCTVC1_RUS_MSG_WNM_MCC_LIC_ERR_EID         ( 0x0006 + cOCTVC1_RUS_EID_BASE )
#define cOCTVC1_RUS_MSG_WNM_NR_CELL_STATS_EID       ( 0x0007 + cOCTVC1_RUS_EID_BASE )

#define cOCTVC1_RUS_EID_MAX                         (( 0x0007 + 1 ) & 0xFFFF)

/****************************************************************************
	Module Data IDs
 ****************************************************************************/
#define cOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MID (  + cOCTVC1_RUS_MID_BASE )

#define cOCTVC1_RUS_MID_MAX                 ((  + 1 ) & 0xFFFF)


#endif /* __OCTVC1_RUS_ID_H__ */

