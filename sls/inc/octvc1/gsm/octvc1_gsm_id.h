/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_GSM_ID.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the identifiers for the GSM API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_GSM_ID_H__
#define __OCTVC1_GSM_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_gsm_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_GSM_MSG_TRX_OPEN_CID                                       ( ( 0x001 + cOCTVC1_GSM_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_GSM_MSG_TRX_CLOSE_CID                                      ( 0x002 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STATUS_CID                                     ( 0x003 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_CID                                       ( 0x004 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_RESET_CID                                      ( 0x005 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_MODIFY_CID                                     ( 0x006 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_LIST_CID                                       ( 0x007 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CID                                  ( 0x008 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_START_RECORD_CID                               ( 0x009 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STOP_RECORD_CID                                ( 0x00a + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CID                   ( 0x00b + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CID                 ( 0x00c + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CID                     ( 0x00d + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CID                       ( 0x00e + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CID                       ( 0x00f + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CID                  ( 0x012 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CID                ( 0x013 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CID                    ( 0x014 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CID                     ( 0x015 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CID                      ( 0x016 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CID                      ( 0x017 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CID          ( 0x018 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CID            ( 0x019 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CID          ( 0x01a + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_RF_CID                                    ( 0x01b + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_MODIFY_RF_CID                                  ( 0x01c + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TAP_FILTER_LIST_CID                                ( 0x01d + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TAP_FILTER_INFO_CID                                ( 0x01e + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TAP_FILTER_STATS_CID                               ( 0x01f + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CID                              ( 0x020 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CID                   ( 0x021 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CID                     ( 0x022 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CID ( 0x035 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CID  ( 0x036 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CID  ( 0x037 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CID                   ( 0x038 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CID                  ( 0x039 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CID                   ( 0x03a + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CID                           ( 0x03b + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CID                             ( 0x03c + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CID                         ( 0x03d + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CID                        ( 0x03e + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CID                         ( 0x03f + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CID                  ( 0x040 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CID                    ( 0x041 + cOCTVC1_GSM_CID_BASE )
#define cOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CID                   ( 0x042 + cOCTVC1_GSM_CID_BASE )

#define cOCTVC1_GSM_CID_MAX                                                (( 0x042 + 1 ) & 0xFFF)

/****************************************************************************
	Module Data IDs
 ****************************************************************************/
#define cOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MID     ( 0x0000 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MID              ( 0x0001 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MID             ( 0x0002 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MID                          ( 0x0020 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MID                            ( 0x0021 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MID                   ( 0x0022 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MID          ( 0x0031 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MID ( 0x0032 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MID          ( 0x0033 + cOCTVC1_GSM_MID_BASE )
#define cOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MID      ( 0x0034 + cOCTVC1_GSM_MID_BASE )

#define cOCTVC1_GSM_MID_MAX                                              (( 0x0034 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_GSM_ID_H__ */

