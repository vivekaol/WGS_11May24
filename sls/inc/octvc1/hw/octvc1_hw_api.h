/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_HW_API.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the HW API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_HW_API_H__
#define __OCTVC1_HW_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_fifo.h"
#include "../octvc1_buffer.h"
#include "../octvc1_eth.h"
#include "../octvc1_mac.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_log.h"
#include "../octvc1_process.h"
#include "../octvc1_user_id.h"
#include "../octvc1_radio.h"

#include "octvc1_hw_id.h"
#include "octvc1_hw_rc.h"

/************************  COMMON DEFINITIONS  *******************************/


/*-------------------------------------------------------------------------------------
 	PCB related definitions.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	PCB source information state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_PCB_INFO_SOURCE_ENUM						tOCT_UINT32

#define cOCTVC1_HW_PCB_INFO_SOURCE_ENUM_USER_HW_CONFIG		0		
#define cOCTVC1_HW_PCB_INFO_SOURCE_ENUM_DATA_SECTION		1		
#define cOCTVC1_HW_PCB_INFO_SOURCE_ENUM_EEPROM				2		
#define cOCTVC1_HW_PCB_INFO_SOURCE_ENUM_INI_FILE			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM_SIGNED_OK		0x40000000	
#define cOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM_SIGNED_ERROR	0x80000000	

/*-------------------------------------------------------------------------------------
 	PCB information state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_PCB_INFO_STATE_ENUM								tOCT_UINT32

#define cOCTVC1_HW_PCB_INFO_STATE_ENUM_PARSED_ERROR					0		
#define cOCTVC1_HW_PCB_INFO_STATE_ENUM_PARSED_OK					1		
#define cOCTVC1_HW_PCB_INFO_STATE_ENUM_PARSED_OK_SIGNED				((tOCT_UINT32)(1|cOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM_SIGNED_OK) )	
#define cOCTVC1_HW_PCB_INFO_STATE_ENUM_PARSED_OK_SIGNED_ERROR		((tOCT_UINT32)(1|cOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM_SIGNED_ERROR) )	
#define cOCTVC1_HW_PCB_INFO_STATE_ENUM_PARSED_ERROR_SIGNED			((tOCT_UINT32)(0|cOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM_SIGNED_OK) )	
#define cOCTVC1_HW_PCB_INFO_STATE_ENUM_PARSED_ERROR_SIGNED_ERROR	((tOCT_UINT32)(0|cOCTVC1_HW_PCB_INFO_SIGNED_STATE_ENUM_SIGNED_ERROR) )	

/*-------------------------------------------------------------------------------------
 	PCB max field definitions.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_HW_PCB_NAME_MAX_LENGTH						23		 	/* Device PCB name. */
#define cOCTVC1_HW_PCB_SERIAL_MAX_LENGTH					23		 	/* Device PCB serial number. */
#define cOCTVC1_HW_PCB_FILENAME_MAX_LENGTH					23		 	/* Device PCB name. */
#define cOCTVC1_HW_PCB_GPS_NAME_MAX_LENGTH					23		 	/* GPS name. */
#define cOCTVC1_HW_PCB_WIFI_NAME_MAX_LENGTH					23		 	/* WIFI name. */

/*-------------------------------------------------------------------------------------
 	CPU CORE related definitions.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	Cpu Core Mask.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_CPU_CORE_MASK							tOCT_UINT32

#define cOCTVC1_HW_CPU_CORE_MASK_1							((tOCT_UINT32)(1<<1) )	
#define cOCTVC1_HW_CPU_CORE_MASK_2							((tOCT_UINT32)(1<<2) )	
#define cOCTVC1_HW_CPU_CORE_MASK_3							((tOCT_UINT32)(1<<3) )	
#define cOCTVC1_HW_CPU_CORE_MASK_4							((tOCT_UINT32)(1<<4) )	
#define cOCTVC1_HW_CPU_CORE_MASK_5							((tOCT_UINT32)(1<<5) )	
#define cOCTVC1_HW_CPU_CORE_MASK_6							((tOCT_UINT32)(1<<6) )	
#define cOCTVC1_HW_CPU_CORE_MASK_7							((tOCT_UINT32)(1<<7) )	
#define cOCTVC1_HW_CPU_CORE_MASK_8							((tOCT_UINT32)(1<<8) )	
#define cOCTVC1_HW_CPU_CORE_MASK_9							((tOCT_UINT32)(1<<9) )	
#define cOCTVC1_HW_CPU_CORE_MASK_10							((tOCT_UINT32)(1<<10) )	
#define cOCTVC1_HW_CPU_CORE_MASK_11							((tOCT_UINT32)(1<<11) )	
#define cOCTVC1_HW_CPU_CORE_MASK_12							((tOCT_UINT32)(1<<12) )	
#define cOCTVC1_HW_CPU_CORE_MASK_13							((tOCT_UINT32)(1<<13) )	
#define cOCTVC1_HW_CPU_CORE_MASK_14							((tOCT_UINT32)(1<<14) )	
#define cOCTVC1_HW_CPU_CORE_MASK_15							((tOCT_UINT32)(1<<15) )	
#define cOCTVC1_HW_CPU_CORE_MASK_16							((tOCT_UINT32)(1<<16) )	
#define cOCTVC1_HW_CPU_CORE_MASK_17							((tOCT_UINT32)(1<<17) )	
#define cOCTVC1_HW_CPU_CORE_MASK_18							((tOCT_UINT32)(1<<18) )	
#define cOCTVC1_HW_CPU_CORE_MASK_19							((tOCT_UINT32)(1<<19) )	
#define cOCTVC1_HW_CPU_CORE_MASK_20							((tOCT_UINT32)(1<<20) )	
#define cOCTVC1_HW_CPU_CORE_MASK_21							((tOCT_UINT32)(1<<21) )	
#define cOCTVC1_HW_CPU_CORE_MASK_22							((tOCT_UINT32)(1<<22) )	
#define cOCTVC1_HW_CPU_CORE_MASK_23							((tOCT_UINT32)(1<<23) )	
#define cOCTVC1_HW_CPU_CORE_MASK_24							((tOCT_UINT32)(1<<24) )	

/*-------------------------------------------------------------------------------------
 	Core Status.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_CPU_CORE_STATUS_ENUM						tOCT_UINT32

#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_RESET				0		 	/* The core is in reset mode. */
 																	/* This is the state of cores that have not been started. */
#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_RUNNING				1		 	/* The core is executing code. */
 																	/* This is the typical state of cores that have been started in target. */
#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_HALT				2		 	/* The core has reached an instruction that caused the core to stop executing code. */
 																	/* This is an error condition. */
#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_TRAP				3		 	/* The core has reached an instruction that caused the core to stop executing code. */
 																	/* This is an error condition. */
#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_ACCESS_VIOLATION	4		 	/* The core has stopped execution because the code it is hosting caused an access */
 																	/* violation. */
 																	/* This is an error condition. */
#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_NOT_PRESENT			5		 	/* The core is not present on the device. */
#define cOCTVC1_HW_CPU_CORE_STATUS_ENUM_FAILURE_DETECTED	6		 	/* A failure has been detected and this core cannot be used anymore. */
 																	/* Contact Octasic Support. */

/*-------------------------------------------------------------------------------------
 	Cpu Core Failure Mask.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_CPU_CORE_FAILURE_MASK					tOCT_UINT32

#define cOCTVC1_HW_CPU_CORE_FAILURE_MASK_NONE				0		 	/* No failures have been detected. */
#define cOCTVC1_HW_CPU_CORE_FAILURE_MASK_MEMORY				((tOCT_UINT32)(1<<1) )	 	/* A memory failure has been detected on the core */

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_CPU_CORE_STATS

 Members:
	ulCoreStatus
	ulProgramCounter
	ulFailureMask
 		Valid when ulCoreStatus = FAILURE_DETECTED.
 		Contact Octasic Support.
	ulAccessViolationAddress
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HW_CPU_CORE_STATUS_ENUM		ulCoreStatus;
	tOCT_UINT32							ulProgramCounter;
	tOCTVC1_HW_CPU_CORE_FAILURE_MASK	ulFailureMask;
	tOCT_UINT32							ulAccessViolationAddress;

} tOCTVC1_HW_CPU_CORE_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_CPU_CORE_INFO

 Members:
	hProcess
		Default:	cOCTVC1_HANDLE_INVALID
 		Process handle identifier. Value INVALID means no process running on this core.
	ulPhysicalCoreId
		Default:	0
 		Physical core index. Value 0 means no core is running for this logical
 		identifier.
	ulProcessUserId
		Default:	cOCTVC1_USER_ID_PROCESS_ENUM_INVALID
 		Process Type identifier. Value INVALID means no process running on this core.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						hProcess;
	tOCT_UINT32						ulPhysicalCoreId;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulProcessUserId;

} tOCTVC1_HW_CPU_CORE_INFO;

/*-------------------------------------------------------------------------------------
 	ETH port related definitions.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	Ethernet port mode of operation.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_ETH_MODE_ENUM							tOCT_UINT32

#define cOCTVC1_HW_ETH_MODE_ENUM_INVALID					0xFFFFFFFF	
#define cOCTVC1_HW_ETH_MODE_ENUM_MII						0		
#define cOCTVC1_HW_ETH_MODE_ENUM_RMII						1		
#define cOCTVC1_HW_ETH_MODE_ENUM_GMII						2		
#define cOCTVC1_HW_ETH_MODE_ENUM_RGMII						3		
#define cOCTVC1_HW_ETH_MODE_ENUM_SGMII						4		

/*-------------------------------------------------------------------------------------
 	Ethernet link speed (MBits).
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_ETH_LINK_SPEED_ENUM						tOCT_UINT32

#define cOCTVC1_HW_ETH_LINK_SPEED_ENUM_INVALID				0xFFFFFFFF	
#define cOCTVC1_HW_ETH_LINK_SPEED_ENUM_10					10		
#define cOCTVC1_HW_ETH_LINK_SPEED_ENUM_100					100		
#define cOCTVC1_HW_ETH_LINK_SPEED_ENUM_1000					1000	

/*-------------------------------------------------------------------------------------
 	Ethernet duplex mode.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_ETH_DUPLEX_MODE_ENUM						tOCT_UINT32

#define cOCTVC1_HW_ETH_DUPLEX_MODE_ENUM_INVALID				0		
#define cOCTVC1_HW_ETH_DUPLEX_MODE_ENUM_FULL				1		
#define cOCTVC1_HW_ETH_DUPLEX_MODE_ENUM_HALF				2		

/*-------------------------------------------------------------------------------------
 	ETH port.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_HW_ETH_PORT_PHY_ADDRESS_INVALID				63		 	/* Invalid Phy Address */
 																		/* This definition indicates that either no PHY is present or */
 																		/* that communication with the phy is not allowed. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_ETH_PORT_CONFIG

 Members:
	MacAddress
	ulPromiscuousModeFlag
 		When set, all frames are accepted
	ulAcceptMulticastFlag
 		When set, multicast and broadcast frames are accepted
	ulAcceptJumboFrameFlag
 		When set, Jumbo frames are accepted.
 		See hardware documentation for interface maximum payload size.
	ulSgmiiAutoNegotationFlag
 		When set, sGMII auto-negotiation is enable
	ulLinkSpeed
	ulDuplexMode
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MAC_ADDRESS				MacAddress;
	tOCT_BOOL32						ulPromiscuousModeFlag;
	tOCT_BOOL32						ulAcceptMulticastFlag;
	tOCT_BOOL32						ulAcceptJumboFrameFlag;
	tOCT_BOOL32						ulSgmiiAutoNegotationFlag;
	tOCTVC1_HW_ETH_LINK_SPEED_ENUM	ulLinkSpeed;
	tOCTVC1_HW_ETH_DUPLEX_MODE_ENUM	ulDuplexMode;

} tOCTVC1_HW_ETH_PORT_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_ETH_PORT_TX_ERROR_STATS

 Members:
	ulTxUnderflowCnt
 		Number of frames aborted due to frame underflow error.
	ulTxLateCollisionCnt
 		Number of frames aborted due to late collision error.
	ulTxExcessCollisionCnt
 		Number of frames aborted due to excessive collision errors.
	ulTxExcessDeferralCnt
 		Number of frames aborted due to excessive deferral error.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulTxUnderflowCnt;
	tOCT_UINT32	ulTxLateCollisionCnt;
	tOCT_UINT32	ulTxExcessCollisionCnt;
	tOCT_UINT32	ulTxExcessDeferralCnt;

} tOCTVC1_HW_ETH_PORT_TX_ERROR_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_ETH_PORT_TX_STATS

 Members:
	ulTxFrameCnt
 		Number of frames transmitted.
 		This number includes good and bad frames but excludes retried frames.
	ulTxByteCnt
 		Number of bytes transmitted in good and bad frames.
 		This number excludes preamble and retried bytes.
	ulTxPauseFrameCnt
 		Number of times Ethernet port sent a PAUSE frame.
	ulTxVlanFrameCnt
 		Number of times Ethernet port sent a VLAN frame.
	ulTxJumboFrameCnt
 		Number of frames transmitted with byte length over 1,024.
	TxErrorStat
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulTxFrameCnt;
	tOCT_UINT32							ulTxByteCnt;
	tOCT_UINT32							ulTxPauseFrameCnt;
	tOCT_UINT32							ulTxVlanFrameCnt;
	tOCT_UINT32							ulTxJumboFrameCnt;
	tOCTVC1_HW_ETH_PORT_TX_ERROR_STATS	TxErrorStat;

} tOCTVC1_HW_ETH_PORT_TX_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_ETH_PORT_RX_ERROR_STATS

 Members:
	ulRxCrcErrorCnt
 		Number of times the Ethernet port detected packets with an invalid Cyclic
 		Redundancy Check (CRC).
	ulRxAlignmentErrorCnt
 		Number of frames received with alignment (dribble) error. Valid only in 10/100
 		mode.
	ulRxJabberErrorCnt
 		Number of giant frames received with length (including CRC) greater than 1,518
 		bytes (1,522 bytes for VLAN tagged) and with CRC error.
	ulRxUndersizeCnt
 		Number of frames received with a byte length of less than 64. This number
 		includes good frames only.
	ulRxOversizeCnt
 		Number of frames received with byte length greater than the maximum size.
	ulRxLengthCnt
 		Number of frames received with a valid Length Type field, but the size of the
 		received frame does not match the value in the Length Type field.
	ulRxOutOfRangeCnt
 		Number of frames received with length field not equal to the valid frame size
 		(between 1,500 and 1,536 bytes, inclusive).
	ulRxFifoOverflowCnt
 		Number of received frames missed due to FIFO overflow.
	ulRxWatchdogCnt
 		Number of frames received with an error due to watchdog timeout (frames with a
 		data load larger than 2,048 bytes.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulRxCrcErrorCnt;
	tOCT_UINT32	ulRxAlignmentErrorCnt;
	tOCT_UINT32	ulRxJabberErrorCnt;
	tOCT_UINT32	ulRxUndersizeCnt;
	tOCT_UINT32	ulRxOversizeCnt;
	tOCT_UINT32	ulRxLengthCnt;
	tOCT_UINT32	ulRxOutOfRangeCnt;
	tOCT_UINT32	ulRxFifoOverflowCnt;
	tOCT_UINT32	ulRxWatchdogCnt;

} tOCTVC1_HW_ETH_PORT_RX_ERROR_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_ETH_PORT_RX_STATS

 Members:
	ulRxFrameCnt
 		Number of frames received. This number includes good and bad frames.
	ulRxByteCnt
 		Number of bytes received in good and bad frames. This number excludes preamble.
	ulRxJumboFrameCnt
 		Number of frames received with byte length over 1,024.
	ulRxPauseFrameCnt
 		Number of times Ethernet port detected a PAUSE frame.
	ulRxVlanFrameCnt
 		Number of good and bad VLAN frames received.
	RxErrorStat
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulRxFrameCnt;
	tOCT_UINT32							ulRxByteCnt;
	tOCT_UINT32							ulRxJumboFrameCnt;
	tOCT_UINT32							ulRxPauseFrameCnt;
	tOCT_UINT32							ulRxVlanFrameCnt;
	tOCTVC1_HW_ETH_PORT_RX_ERROR_STATS	RxErrorStat;

} tOCTVC1_HW_ETH_PORT_RX_STATS;

/*-------------------------------------------------------------------------------------
 	RF_PORT related definitions.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_HW_RF_PORT_MAX_ANTENNA						2		 	/* Maximum number of antenna per RF_PORT. */
#define cOCTVC1_HW_RF_PORT_ANTENNA_MAX_TX_CALIB				20		 	/* Maximum number of TX calibration per RF_PORT antenna. */
#define cOCTVC1_HW_RF_PORT_ANTENNA_UNUSED_ID				0xFFFFFFFF	 	/* Specify that this antenna is not used. */

/*-------------------------------------------------------------------------------------
 	RF port antenna calibration state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_RF_PORT_ANTENNA_CALIB_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_HW_RF_PORT_ANTENNA_CALIB_STATE_ENUM_UNAVAILABLE		0		
#define cOCTVC1_HW_RF_PORT_ANTENNA_CALIB_STATE_ENUM_INACTIVE		1		
#define cOCTVC1_HW_RF_PORT_ANTENNA_CALIB_STATE_ENUM_ACTIVE			2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_RF_PORT_ANTENNA_RX_CONFIG

 Members:
	ulEnableFlag
	lRxGaindB
 		Q9 value, (1 dB step) Minimum value is:0 Maximum value is:73 (* 512)
	ulRxGainMode
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32								ulEnableFlag;
	tOCT_INT32								lRxGaindB;
	tOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM	ulRxGainMode;

} tOCTVC1_HW_RF_PORT_ANTENNA_RX_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_RF_PORT_ANTENNA_TX_CONFIG

 Members:
	ulEnableFlag
	lTxGaindB
 		Q9 value, Minimum value is:-89.75 Maximum value is:0
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulEnableFlag;
	tOCT_INT32	lTxGaindB;

} tOCTVC1_HW_RF_PORT_ANTENNA_TX_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_RF_PORT_RX_STATS

 Members:
	ulRxByteCnt
 		Number of bytes received. Attentions 32-bits counter
	ulRxOverflowCnt
 		Count the number overflow
 		Counter increase by 1 each time an overflow is detected between two receive
	ulRxAverageBytePerSecond
 		Average byte receive per seconds
	ulRxAveragePeriodUs
 		Average Time in microseconds between two receive
	Frequency
 		Current frequency
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulRxByteCnt;
	tOCT_UINT32						ulRxOverflowCnt;
	tOCT_UINT32						ulRxAverageBytePerSecond;
	tOCT_UINT32						ulRxAveragePeriodUs;
	tOCTVC1_RADIO_FREQUENCY_VALUE	Frequency;

} tOCTVC1_HW_RF_PORT_RX_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_RF_PORT_TX_STATS

 Members:
	ulTxByteCnt
 		Number of bytes received. Attentions 32-bits counter
	ulTxUnderflowCnt
 		Count the number underflow
 		Counter increase by 1 each time an overflow is detected between two send
	ulTxAverageBytePerSecond
 		Average byte receive per seconds
	ulTxAveragePeriodUs
 		Average Time in microseconds between two send
	Frequency
 		Current frequency
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulTxByteCnt;
	tOCT_UINT32						ulTxUnderflowCnt;
	tOCT_UINT32						ulTxAverageBytePerSecond;
	tOCT_UINT32						ulTxAveragePeriodUs;
	tOCTVC1_RADIO_FREQUENCY_VALUE	Frequency;

} tOCTVC1_HW_RF_PORT_TX_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_RF_PORT_ANTENNA_TX_CALIB

 Members:
	ulFrequencyMhz
 		Frequency in Mhz
	ulAttenuationdB
 		Attenuation in dB.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulFrequencyMhz;
	tOCT_UINT32	ulAttenuationdB;

} tOCTVC1_HW_RF_PORT_ANTENNA_TX_CALIB;

/*-------------------------------------------------------------------------------------
 	Clock Sync Manager related definitions.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	Clock Sync Manager Source
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM				tOCT_UINT32

#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_FREQ_1HZ			0		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_FREQ_10MHZ		1		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_FREQ_30_72MHZ		2		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_FREQ_1HZ_EXT		3		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_SOFT_APP			4		 	/* Clock Sync Manager is driven by the software application. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_FREQ_25MHZ		6		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM_NONE				5		 	/* Clock Sync Manager is not initialized. */
 																		/* Base on config file informations. */

/*-------------------------------------------------------------------------------------
 	Clock Sync Manager DAC State.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_CLOCK_SYNC_MGR_DAC_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_HW_CLOCK_SYNC_MGR_DAC_STATE_ENUM_UNUSED			0		 	/* Clock Sync Manager DAC mechanism is not used. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_DAC_STATE_ENUM_MASTER			1		 	/* Clock Sync Manager DAC mechanism is controled by the process. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_DAC_STATE_ENUM_SLAVE			2		 	/* Clock Sync Manager DAC mechanism is controled by another DSP. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_DAC_STATE_ENUM_FREE_RUNNING	3		 	/* Clock Sync Manager is disable. Clock asservissement is done externally. */

/*-------------------------------------------------------------------------------------
 	Clock Sync manager state
-------------------------------------------------------------------------------------*/
#define tOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_UNINITIALIZE		0		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_UNUSED				1		 	/* Not opened. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_NO_EXT_CLOCK		2		 	/* Never detect any clock. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_LOCKED				3		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_UNLOCKED			4		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_ERROR				5		
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_DISABLE			6		 	/* The actual PCB does not support this service. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_LOSS_EXT_CLOCK		7		 	/* No more clock detected. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_UNRESERVED			8		 	/* Opened, but no process has reserved. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_RESERVED			9		 	/* Reserved, not yet active. */
#define cOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM_ACTIVE				10		

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_PCB_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_HW_MSG_PCB_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_PCB_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	szName
 		PCB name/model
	ulDeviceId
 		PCB device order (Primary=0/Secondary=1...)
	szSerial
 		PCB serial number
	szFilename
 		File containing raw PCB info
	ulInfoSource
 		PCB information source.
	ulInfoState
 		PCB information state.
	szGpsName
 		GPS name
	szWifiName
 		WIFI name
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCT_INT8						szName[(cOCTVC1_HW_PCB_NAME_MAX_LENGTH+1)];
	tOCT_UINT32						ulDeviceId;
	tOCT_INT8						szSerial[(cOCTVC1_HW_PCB_SERIAL_MAX_LENGTH+1)];
	tOCT_INT8						szFilename[(cOCTVC1_HW_PCB_FILENAME_MAX_LENGTH+1)];
	tOCTVC1_HW_PCB_INFO_SOURCE_ENUM	ulInfoSource;
	tOCTVC1_HW_PCB_INFO_STATE_ENUM	ulInfoState;
	tOCT_INT8						szGpsName[(cOCTVC1_HW_PCB_GPS_NAME_MAX_LENGTH+1)];
	tOCT_INT8						szWifiName[(cOCTVC1_HW_PCB_WIFI_NAME_MAX_LENGTH+1)];

} tOCTVC1_HW_MSG_PCB_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulCoreIndex
 		Cpu Core identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulCoreIndex;

} tOCTVC1_HW_MSG_CPU_CORE_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	CoreStats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HW_CPU_CORE_STATS	CoreStats;

} tOCTVC1_HW_MSG_CPU_CORE_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulCoreIndex
 		Cpu Core identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulCoreIndex;

} tOCTVC1_HW_MSG_CPU_CORE_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	CoreInfo
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HW_CPU_CORE_INFO	CoreInfo;

} tOCTVC1_HW_MSG_CPU_CORE_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_LIST_CMD

 Members:
	Header
	IndexGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;

} tOCTVC1_HW_MSG_CPU_CORE_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CPU_CORE_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	IndexGet
 		Object cursor
	IndexList
 		Object name list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;
	tOCTVC1_LIST_INDEX_GET		IndexList;

} tOCTVC1_HW_MSG_CPU_CORE_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique ETH port identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;

} tOCTVC1_HW_MSG_ETH_PORT_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique ETH port identifier
	ulInterfaceId
 		Interface ID
	ulMode
	ulTxPktQueuesByteSize
	ulRxPktQueuesByteSize
	ulRestrictedApiFlag
 		Set to TRUE when this port can be configure by control port.
	ulEnableFlag
 		Set to TRUE when this port is used by the target application.
	Config
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_INDEX				ulPortIndex;
	tOCT_UINT32					ulInterfaceId;
	tOCTVC1_HW_ETH_MODE_ENUM	ulMode;
	tOCT_UINT32					ulTxPktQueuesByteSize;
	tOCT_UINT32					ulRxPktQueuesByteSize;
	tOCT_BOOL32					ulRestrictedApiFlag;
	tOCT_BOOL32					ulEnableFlag;
	tOCTVC1_HW_ETH_PORT_CONFIG	Config;

} tOCTVC1_HW_MSG_ETH_PORT_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_LIST_CMD

 Members:
	Header
	IndexGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;

} tOCTVC1_HW_MSG_ETH_PORT_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	IndexGet
 		Object cursor
	IndexList
 		Object name list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;
	tOCTVC1_LIST_INDEX_GET		IndexList;

} tOCTVC1_HW_MSG_ETH_PORT_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique ETH port identifier
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCT_BOOL32			ulResetStatsFlag;

} tOCTVC1_HW_MSG_ETH_PORT_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique ETH port identifier
	RxStats
	TxStats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulPortIndex;
	tOCTVC1_HW_ETH_PORT_RX_STATS	RxStats;
	tOCTVC1_HW_ETH_PORT_TX_STATS	TxStats;

} tOCTVC1_HW_MSG_ETH_PORT_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique ETH port identifier
	Config
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_INDEX				ulPortIndex;
	tOCTVC1_HW_ETH_PORT_CONFIG	Config;

} tOCTVC1_HW_MSG_ETH_PORT_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_ETH_PORT_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique ETH port identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;

} tOCTVC1_HW_MSG_ETH_PORT_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;

} tOCTVC1_HW_MSG_RF_PORT_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulInService
 		Main Rf port is in service.
	hOwner
 		Main Rf port owner identifier.
	ulPortInterfaceId
 		PCB Port Interface Id
	ulFrequencyMinKhz
 		RF minimum frequency (Khz)
	ulFrequencyMaxKhz
 		RF maximum frequency (Khz)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulPortIndex;
	tOCT_BOOL32				ulInService;
	tOCTVC1_HANDLE_OBJECT	hOwner;
	tOCT_UINT32				ulPortInterfaceId;
	tOCT_UINT32				ulFrequencyMinKhz;
	tOCT_UINT32				ulFrequencyMaxKhz;

} tOCTVC1_HW_MSG_RF_PORT_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulResetStatsFlag
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCT_BOOL32			ulResetStatsFlag;

} tOCTVC1_HW_MSG_RF_PORT_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulRadioStandard
 		Radio standard
	RxStats
 		Main Rf Rx stats
	TxStats
 		Main Rf Tx stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_INDEX				ulPortIndex;
	tOCTVC1_RADIO_STANDARD_ENUM	ulRadioStandard;
	tOCTVC1_HW_RF_PORT_RX_STATS	RxStats;
	tOCTVC1_HW_RF_PORT_TX_STATS	TxStats;

} tOCTVC1_HW_MSG_RF_PORT_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_LIST_CMD

 Members:
	Header
	IndexGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;

} tOCTVC1_HW_MSG_RF_PORT_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	IndexGet
 		Object cursor
	IndexList
 		Object name list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;
	tOCTVC1_LIST_INDEX_GET		IndexList;

} tOCTVC1_HW_MSG_RF_PORT_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_LIST_ANTENNA_CMD

 Members:
	Header
	SubIndexGet
 		Index cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_INDEX_GET_SUB_INDEX	SubIndexGet;

} tOCTVC1_HW_MSG_RF_PORT_LIST_ANTENNA_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_LIST_ANTENNA_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubIndexGet
 		Index cursor
	SubIndexList
 		Object name list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_INDEX_GET_SUB_INDEX	SubIndexGet;
	tOCTVC1_LIST_INDEX_GET_SUB_INDEX	SubIndexList;

} tOCTVC1_HW_MSG_RF_PORT_LIST_ANTENNA_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_RX_CONFIG_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_RX_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_RX_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	RxConfig
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_INDEX							ulPortIndex;
	tOCTVC1_INDEX							ulAntennaIndex;
	tOCTVC1_HW_RF_PORT_ANTENNA_RX_CONFIG	RxConfig;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_RX_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CONFIG_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	TxConfig
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_INDEX							ulPortIndex;
	tOCTVC1_INDEX							ulAntennaIndex;
	tOCTVC1_HW_RF_PORT_ANTENNA_TX_CONFIG	TxConfig;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CALIB_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CALIB_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CALIB_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	ulCalibState
 		Set to UNAVAILABLE when the calibrations are not present.
 		Set to ACTIVE when the calibration is enable by the configuration file.
	ulCalibCnt
 		Number of valid calibration in 'aCalib' array
	aCalib
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_INDEX								ulPortIndex;
	tOCTVC1_INDEX								ulAntennaIndex;
	tOCTVC1_HW_RF_PORT_ANTENNA_CALIB_STATE_ENUM	ulCalibState;
	tOCT_UINT32									ulCalibCnt;
	tOCTVC1_HW_RF_PORT_ANTENNA_TX_CALIB			aCalib[cOCTVC1_HW_RF_PORT_ANTENNA_MAX_TX_CALIB];

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_TX_CALIB_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CALIB_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	ulActivateFlag
 		Weather or not to activate the calibration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_BOOL32			ulActivateFlag;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CALIB_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CALIB_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CALIB_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulClkSourceRef
 		Selected source for reference clock
	ulMaxDriftDurationUs
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM	ulClkSourceRef;
	tOCT_INT32								ulMaxDriftDurationUs;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulResetStatsFlag
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulResetStatsFlag;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulState
 		Clock sync manager state
	ulDacState
 		DAC state
	ulDacValue
 		Current DAC value
	ulOwnerProcessUid
	ulDriftElapseTimeUs
 		Last calculated drift elapse time in microseconds.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_HW_CLOCK_SYNC_MGR_STATE_ENUM		ulState;
	tOCTVC1_HW_CLOCK_SYNC_MGR_DAC_STATE_ENUM	ulDacState;
	tOCT_UINT32									ulDacValue;
	tOCTVC1_USER_ID_PROCESS_ENUM				ulOwnerProcessUid;
	tOCT_UINT32									ulDriftElapseTimeUs;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulClkSourceRef
 		Selected source for reference clock
	ulDacInitValue
		Default:	0x00007600
 		DAC initial value.
	ulSyncWindowSize
		Default:	7
 		Number of consecutive values within iSyncThreshold to consider that the clock
 		manager is synchronized to its reference.
	lSyncThreshold
		Default:	10
 		Maximum allowed delta to consider that the clock manager is synchronized to its
 		reference.
	ulFrequencyCorrectionFlag
 		Set to cOCT_TRUE when frequency correction should be applied.
	ulMaxDriftDurationUs
		Default:	40
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_HW_CLOCK_SYNC_MGR_SOURCE_ENUM	ulClkSourceRef;
	tOCT_UINT32								ulDacInitValue;
	tOCT_UINT32								ulSyncWindowSize;
	tOCT_INT32								lSyncThreshold;
	tOCT_BOOL32								ulFrequencyCorrectionFlag;
	tOCT_INT32								ulMaxDriftDurationUs;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_START_SYNCHRO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_CMD

 Members:
	Header
 		OCTVC1 Message Header
 		Attention all application module must be stopped (except system) to be able to
 		stop the clock sync manager
 		Can use command cOCTVC1_MAIN_MSG_APPLICATION_STOP_MODULE_CID
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_HW_MSG_CLOCK_SYNC_MGR_STOP_SYNCHRO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_RX_CONFIG_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	ulRelativeGainFlag
 		Weather or not the following 'lRxGaindB' is relative of absolute value.
 		TRUE: mean that the 'lRxGaindB' will be added to the current configured value.
	lRxGaindB
		Range:		[..]
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Q9 value, (1 dB step) Minimum value is:0 Maximum value is:73 dB (37376 in Q9)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_BOOL32			ulRelativeGainFlag;
	tOCT_INT32			lRxGaindB;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_RX_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_RX_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	lRxGaindB
 		Q9 value, (1 dB step) Minimum value is:0 Maximum value is:73 (* 512)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_INT32			lRxGaindB;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_RX_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CONFIG_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	ulRelativeGainFlag
 		Weather or not the following 'lTxGaindB' is relative of absolute value.
 		TRUE: mean that the 'lRxGaindB' will be added to the current configured value.
	lTxGaindB
		Range:		[..]
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Q9 value, Minimum value is:-89.75 (-45952 in Q9) Maximum value is:0 allow step
 		is 0.25 (128 in Q9)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_BOOL32			ulRelativeGainFlag;
	tOCT_INT32			lTxGaindB;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		RF PORT index
	ulAntennaIndex
 		Antenna index
	lTxGaindB
 		Q9 value, Minimum value is:-89.75 Maximum value is:0
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_INT32			lTxGaindB;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_TX_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_FRONT_END_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulAntennaIndex
 		Antenna index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_FRONT_END_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_FRONT_END_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulAntennaIndex
 		Antenna index
	ulInitializedFlag
 		Whether or not the values was initialized by the host application.
	lTxGaindB
 		Q9 value.
	lRxGaindB
 		Q9 value.
	ulTxPathDelayNs
 		TX path delay in nanosecond.
	ulRxPathDelayNs
 		RX path delay in nanosecond.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_BOOL32			ulInitializedFlag;
	tOCT_INT32			lTxGaindB;
	tOCT_INT32			lRxGaindB;
	tOCT_UINT32			ulTxPathDelayNs;
	tOCT_UINT32			ulRxPathDelayNs;

} tOCTVC1_HW_MSG_RF_PORT_INFO_ANTENNA_FRONT_END_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_FRONT_END_CMD
 		Allow the host application to inform the target about
 		few characteristics of the associated front-end.

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulAntennaIndex
 		Antenna index
	lTxGaindB
 		Q9 value.
	lRxGaindB
 		Q9 value.
	ulTxPathDelayNs
 		TX path delay in nanosecond.
	ulRxPathDelayNs
 		RX path delay in nanosecond.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;
	tOCT_INT32			lTxGaindB;
	tOCT_INT32			lRxGaindB;
	tOCT_UINT32			ulTxPathDelayNs;
	tOCT_UINT32			ulRxPathDelayNs;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_FRONT_END_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_FRONT_END_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulAntennaIndex
 		Antenna index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulPortIndex;
	tOCTVC1_INDEX		ulAntennaIndex;

} tOCTVC1_HW_MSG_RF_PORT_MODIFY_ANTENNA_FRONT_END_RSP;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_hw_evt.h"

#endif /* __OCTVC1_HW_API_H__ */

