/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_HW_EVT.h
Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the HW API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_HW_EVT_H__
#define __OCTVC1_HW_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_hw_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_EXEC_REPORT_EVT

 Members:
	Header
	ulCoreIndex
 		Cpu Core identifier
	ulCoreUseMask
 		One-hot vector indicating which cores are used.
	ulCoreHaltMask
 		One-hot vector indicating which cores are halted.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER		Header;
	tOCTVC1_INDEX				ulCoreIndex;
	tOCTVC1_HW_CPU_CORE_MASK	ulCoreUseMask;
	tOCTVC1_HW_CPU_CORE_MASK	ulCoreHaltMask;

} tOCTVC1_HW_MSG_CPU_CORE_EXEC_REPORT_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_ANTENNA_RX_CONFIG_STATUS_CHANGE_EVT

 Members:
	Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	RxConfig
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER					Header;
	tOCTVC1_INDEX							ulPortIndex;
	tOCTVC1_INDEX							ulAntennaIndex;
	tOCTVC1_HW_RF_PORT_ANTENNA_RX_CONFIG	RxConfig;

} tOCTVC1_HW_MSG_RF_PORT_ANTENNA_RX_CONFIG_STATUS_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_ANTENNA_TX_CONFIG_STATUS_CHANGE_EVT

 Members:
	Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	TxConfig
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER					Header;
	tOCTVC1_INDEX							ulPortIndex;
	tOCTVC1_INDEX							ulAntennaIndex;
	tOCTVC1_HW_RF_PORT_ANTENNA_TX_CONFIG	TxConfig;

} tOCTVC1_HW_MSG_RF_PORT_ANTENNA_TX_CONFIG_STATUS_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_STATUS_CHANGE_EVT

 Members:
	Header
	ulPortIndex
 		Unique RF port identifier
	ulInServiceFlag
 		Weather or not the RF_PORT is in service.
	ulRadioStandard
 		Radio standard
	RxFrequency
 		Current Rx frequency
	TxFrequency
 		Current Tx frequency
	ulBandwidth
 		Current Bandwidth (LTE)
	aRxConfig
	aTxConfig
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER					Header;
	tOCTVC1_INDEX							ulPortIndex;
	tOCT_BOOL32								ulInServiceFlag;
	tOCTVC1_RADIO_STANDARD_ENUM				ulRadioStandard;
	tOCTVC1_RADIO_FREQUENCY_VALUE			RxFrequency;
	tOCTVC1_RADIO_FREQUENCY_VALUE			TxFrequency;
	tOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM	ulBandwidth;
	tOCTVC1_HW_RF_PORT_ANTENNA_RX_CONFIG	aRxConfig[cOCTVC1_HW_RF_PORT_MAX_ANTENNA];
	tOCTVC1_HW_RF_PORT_ANTENNA_TX_CONFIG	aTxConfig[cOCTVC1_HW_RF_PORT_MAX_ANTENNA];

} tOCTVC1_HW_MSG_RF_PORT_STATUS_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATUS_CHANGE_EVT

 Members:
	Header
	ulState
	ulPreviousState
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER					Header;
	tOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM	ulState;
	tOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM	ulPreviousState;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATUS_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_DRIFT_CHANGE_EVT

 Members:
	Header
	ulDriftElapseTimeUs
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCT_UINT32				ulDriftElapseTimeUs;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_DRIFT_CHANGE_EVT;


#endif /* __OCTVC1_HW_EVT_H__ */

