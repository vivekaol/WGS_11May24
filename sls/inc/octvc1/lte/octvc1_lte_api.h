/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LTE_API.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the definition of the LTE API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_LTE_APP-04.03.00-B3607 (2019/04/16)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LTE_API_H__
#define __OCTVC1_LTE_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_radio.h"
#include "../octvc1_tap.h"

#include "octvc1_lte_id.h"
#include "octvc1_lte_rc.h"
#include "octvc1_lte_lic.h"

/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVC1_LTE_AUTO									0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
 	LTE module application
-------------------------------------------------------------------------------------*/

#define cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB		((0x00)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	LTE test module ID.
-------------------------------------------------------------------------------------*/

#define cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB_TEST	((0x01)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	LTE TAP ID.
-------------------------------------------------------------------------------------*/

#define cOCTVC1_LTE_TAP_ID_UL_RFI_0_TIME_SYMBOLS			((0x0000)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_RFI_1_TIME_SYMBOLS			((0x0001)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_RFI_0_FREQ_SYMBOLS			((0x0002)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_RFI_1_FREQ_SYMBOLS			((0x0003)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_DL_RFI_0_TIME_SYMBOLS			((0x0004)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_DL_RFI_1_TIME_SYMBOLS			((0x0005)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_DL_CTRL_FREQ_SYMBOLS				((0x0006)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_DL_CTRL_1_FREQ_SYMBOLS			((0x0007)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_0_SOFTBITS			((0x0008)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_1_SOFTBITS			((0x0009)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_2_SOFTBITS			((0x000A)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_3_SOFTBITS			((0x000B)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_0_HARDBITS			((0x000C)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_1_HARDBITS			((0x000D)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_2_HARDBITS			((0x000E)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_LTE_TAP_ID_UL_PUSCH_OM_3_HARDBITS			((0x000F)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|((cOCTVC1_LTE_APPLICATION_ID_MODULE_PHY_ENODEB&cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT)<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM : 	LTE module profile type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM_INVALID		0		
#define cOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM_DEFAULT		1		
#define cOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM_TX_DIVERSITY	2		
#define cOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM_RX_DIVERSITY	3		
#define cOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM_TDD_BASS		4		

#define cOCTVC1_LTE_TDD_BASS_PHRASE_2						100		 	/* Define TDD BAS PHRASE 2 developpement. */

/*-------------------------------------------------------------------------------------
 	LTE 3GPP standard definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_DUPLEX_MODE_ENUM : 	LTE duplexing mode.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_DUPLEX_MODE_ENUM						tOCT_UINT32

#define cOCTVC1_LTE_DUPLEX_MODE_ENUM_FDD					0		
#define cOCTVC1_LTE_DUPLEX_MODE_ENUM_TDD					1		
#define cOCTVC1_LTE_DUPLEX_MODE_ENUM_INVALID				2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_CP_TYPE_ENUM : 	LTE Cyclic Prefix type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_CP_TYPE_ENUM							tOCT_UINT32

#define cOCTVC1_LTE_CP_TYPE_ENUM_NORMAL						0		
#define cOCTVC1_LTE_CP_TYPE_ENUM_EXTENDED					1		
#define cOCTVC1_LTE_CP_TYPE_ENUM_INVALID					2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BANDWIDTH_ENUM : 	LTE system bandwidth.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_BANDWIDTH_ENUM							tOCT_UINT32

#define cOCTVC1_LTE_BANDWIDTH_ENUM_1p4MHZ					0		
#define cOCTVC1_LTE_BANDWIDTH_ENUM_3MHZ						1		
#define cOCTVC1_LTE_BANDWIDTH_ENUM_5MHZ						2		
#define cOCTVC1_LTE_BANDWIDTH_ENUM_10MHZ					3		
#define cOCTVC1_LTE_BANDWIDTH_ENUM_15MHZ					4		
#define cOCTVC1_LTE_BANDWIDTH_ENUM_20MHZ					5		
#define cOCTVC1_LTE_BANDWIDTH_ENUM_INVALID					6		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM : 	LTE TDD Uplink Downlink configuration index.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM					tOCT_UINT32

#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_0					0		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_1					1		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_2					2		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_3					3		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_4					4		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_5					5		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_6					6		
#define cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_INVALID			7		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM : 	LTE TDD Special Subframe configuration index.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM				tOCT_UINT32

#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_0			0		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_1			1		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_2			2		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_3			3		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_4			4		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_5			5		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_6			6		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_7			7		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_8			8		
#define cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_INVALID		9		

/*-------------------------------------------------------------------------------------
 	LTE eNodeB definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_COMPLIANCE_TYPE_ENUM : 	LTE cell standard compliance.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_COMPLIANCE_TYPE_ENUM					tOCT_UINT32

#define cOCTVC1_LTE_COMPLIANCE_TYPE_ENUM_INVALID			0		
#define cOCTVC1_LTE_COMPLIANCE_TYPE_ENUM_3GPP				1		 	/* Indicates the configuration follows 3GPP specification. */
#define cOCTVC1_LTE_COMPLIANCE_TYPE_ENUM_CUSTOM				2		 	/* Indicates the configuration is user-defined (some checks are disactivated). */

/*-------------------------------------------------------------------------------------
 	eNodeB Cell definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_CELL_STATE_ENUM : 	LTE cell state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_CELL_STATE_ENUM							tOCT_UINT32

#define cOCTVC1_LTE_CELL_STATE_ENUM_INVALID					0		
#define cOCTVC1_LTE_CELL_STATE_ENUM_IDLE					1		
#define cOCTVC1_LTE_CELL_STATE_ENUM_READY					2		
#define cOCTVC1_LTE_CELL_STATE_ENUM_RUNNING					3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_CELL_CONFIG
 		Cell configuration.

 Members:
	ulDuplexMode
		Default:	cOCTVC1_LTE_DUPLEX_MODE_ENUM_FDD
 		Duplexing mode.
	ulCpType
		Default:	cOCTVC1_LTE_CP_TYPE_ENUM_NORMAL
 		Cyclic Prefix.
	ulBwId
		Default:	cOCTVC1_LTE_BANDWIDTH_ENUM_10MHZ
 		System Bandwidth.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_LTE_DUPLEX_MODE_ENUM	ulDuplexMode;
	tOCTVC1_LTE_CP_TYPE_ENUM		ulCpType;
	tOCTVC1_LTE_BANDWIDTH_ENUM		ulBwId;

} tOCTVC1_LTE_CELL_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_CELL_TDD_CONFIG
 		TDD configuration.

 Members:
	ulUplinkDownlinkConfigIdx
		Default:	cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_INVALID
 		Uplink-Downlink configuration index.
	ulSpecialSubframeConfigIdx
		Default:	cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_INVALID
 		Special subframe configuration index.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM		ulUplinkDownlinkConfigIdx;
	tOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM	ulSpecialSubframeConfigIdx;

} tOCTVC1_LTE_CELL_TDD_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_CELL_STATS_DOWNLINK
 		Cell downlink statistics.

 Members:
	ulTtiCnt
 		Cumulated number of DL TTI.
	ulCrntiTtiCnt
 		Cumulated number of DL C-RNTI TTI.
	ulTbCnt
 		Cumulated number of DL Transport Blocks.
	ulAckCnt
 		Cumulated number of DL ACKs.
	ulNackCnt
 		Cumulated number of DL NACKs.
	ulDtxCnt
 		Cumulated number of DL DTX.
	ulUeCnt
 		Cumulated number of DL UEs.
	ulKbitsCnt
 		Cumulated number of DL kbits.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulTtiCnt;
	tOCT_UINT32	ulCrntiTtiCnt;
	tOCT_UINT32	ulTbCnt;
	tOCT_UINT32	ulAckCnt;
	tOCT_UINT32	ulNackCnt;
	tOCT_UINT32	ulDtxCnt;
	tOCT_UINT32	ulUeCnt;
	tOCT_UINT32	ulKbitsCnt;

} tOCTVC1_LTE_CELL_STATS_DOWNLINK;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_CELL_STATS_UPLINK
 		Cell uplink statistics.

 Members:
	ulTtiCnt
 		Cumulated number of UL TTI.
	ulCrntiTtiCnt
 		Cumulated number of UL C-RNTI TTI.
	ulTbCnt
 		Cumulated number of UL Transport Blocks.
	ulCrcPassCnt
 		Cumulated number of UL CRC PASS.
	ulCrcFailCnt
 		Cumulated number of UL CRC FAIL.
	ulUeCnt
 		Cumulated number of UL UEs.
	ulPrbCnt
 		Cumulated number of UL PRBs.
	ulKbitsCnt
 		Cumulated number of UL kbits.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulTtiCnt;
	tOCT_UINT32	ulCrntiTtiCnt;
	tOCT_UINT32	ulTbCnt;
	tOCT_UINT32	ulCrcPassCnt;
	tOCT_UINT32	ulCrcFailCnt;
	tOCT_UINT32	ulUeCnt;
	tOCT_UINT32	ulPrbCnt;
	tOCT_UINT32	ulKbitsCnt;

} tOCTVC1_LTE_CELL_STATS_UPLINK;

/*-------------------------------------------------------------------------------------
 	eNodeB RF definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM : 	RF configuration source.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM					tOCT_UINT32

#define cOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM_INVALID			0		
#define cOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM_EARFCN			1		 	/* Frequency configuration will be derived from EARFCN values. */
#define cOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM_FREQUENCY			2		 	/* Frequency configuration will be taken directly. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_RF_ANTENNA_CONFIG
 		RF antenna configuration.

 Members:
	ulPhysicalAntennaId
		Range:		[0..1]
		Default:	0
 		RF port physical antenna ID.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulPhysicalAntennaId;

} tOCTVC1_LTE_RF_ANTENNA_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_RF_CONFIG
 		RF configuration.

 Members:
	ulConfigSource
		Default:	cOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM_EARFCN
 		LTE RF configuration source.
	ulDownlinkEarfcn
		Range:		[0..262143],cOCTVC1_LTE_AUTO
		Default:	6300
 		LTE Downlink EARFCN.
	ulUplinkEarfcn
		Range:		[0..262143],cOCTVC1_LTE_AUTO
		Default:	cOCTVC1_LTE_AUTO
 		LTE Uplink EARFCN.
	ulDownlinkFrequencyKhz
		Range:		[0..6000000],cOCTVC1_LTE_AUTO
		Default:	cOCTVC1_LTE_AUTO
 		Downlink (Tx) frequency in kHz.
	ulUplinkFrequencyKhz
		Range:		[0..6000000],cOCTVC1_LTE_AUTO
		Default:	cOCTVC1_LTE_AUTO
 		Uplink (Rx) frequency in kHz.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM	ulConfigSource;
	tOCT_UINT32							ulDownlinkEarfcn;
	tOCT_UINT32							ulUplinkEarfcn;
	tOCT_UINT32							ulDownlinkFrequencyKhz;
	tOCT_UINT32							ulUplinkFrequencyKhz;

} tOCTVC1_LTE_RF_CONFIG;

/*-------------------------------------------------------------------------------------
 	eNodeB PHY definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_PHY_SFN_SWITCH_CONFIG
 		PHY SFN Switch configuration.

 Members:
	ulSfnSwitchOnGpioEnableFlag
		Default:	cOCT_FALSE
 		If enabled, the system will switch to specified SFN value when a specific GPIO
 		signal is received.
	ulSfnSwitchValue
		Range:		[0..1023]
		Default:	0
 		Specifies which SFN value to switch to.
 		Refers to SFN as defined in 3GPP specification.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulSfnSwitchOnGpioEnableFlag;
	tOCT_UINT32	ulSfnSwitchValue;

} tOCTVC1_LTE_PHY_SFN_SWITCH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_PHY_CONFIG
 		PHY configuration.

 Members:
	ulDownlinkCfrEnableFlag
		Default:	cOCT_TRUE
 		Downlink CFR.
	ulUplinkHarqEnableFlag
		Default:	cOCT_TRUE
 		Uplink HARQ.
	ulFrameTriggerGpioEnableFlag
		Default:	cOCT_FALSE
 		GPIO Frame trigger.
	ulTxDiversityEnableFlag
		Default:	cOCT_FALSE
 		Tx Diversity.
	ulRxDiversityEnableFlag
		Default:	cOCT_FALSE
 		Rx Diversity.
	SfnSwitchConfig
 		SFN Switch configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32							ulDownlinkCfrEnableFlag;
	tOCT_BOOL32							ulUplinkHarqEnableFlag;
	tOCT_BOOL32							ulFrameTriggerGpioEnableFlag;
	tOCT_BOOL32							ulTxDiversityEnableFlag;
	tOCT_BOOL32							ulRxDiversityEnableFlag;
	tOCTVC1_LTE_PHY_SFN_SWITCH_CONFIG	SfnSwitchConfig;

} tOCTVC1_LTE_PHY_CONFIG;

/*-------------------------------------------------------------------------------------
 	BASS type definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_STATE_ENUM : 	Component's BASS status.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_BASS_STATE_ENUM							tOCT_UINT32

#define cOCTVC1_LTE_BASS_STATE_ENUM_NOT_INITIALIZED			0		 	/* Not initialized */
#define cOCTVC1_LTE_BASS_STATE_ENUM_INITIALIZED				1		 	/* Initialized */
#define cOCTVC1_LTE_BASS_STATE_ENUM_OPENNED					2		 	/* OPENNED */
#define cOCTVC1_LTE_BASS_STATE_ENUM_CONFIGURED				3		 	/* Configured */
#define cOCTVC1_LTE_BASS_STATE_ENUM_CELLSEARCH				4		 	/* Performs cell search */
#define cOCTVC1_LTE_BASS_STATE_ENUM_CONVERGING				5		 	/* Performs convergence on active source cell */
#define cOCTVC1_LTE_BASS_STATE_ENUM_TRACKING				6		 	/* Performs tracking on active source cell after convergence */
#define cOCTVC1_LTE_BASS_STATE_ENUM_ERROR					7		 	/* Internal Error */
#define cOCTVC1_LTE_BASS_STATE_ENUM_INVALID					8		 	/* Invalid state */

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_STATE_SYNC_ENUM : 	Source Synchronization status.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_BASS_STATE_SYNC_ENUM					tOCT_UINT32

#define cOCTVC1_LTE_BASS_STATE_SYNC_ENUM_NOTSYNC			0		 	/* Component is not synchronized to the source */
#define cOCTVC1_LTE_BASS_STATE_SYNC_ENUM_ISSYNC				1		 	/* Component is synchronized to the source */
#define cOCTVC1_LTE_BASS_STATE_SYNC_ENUM_UNSYNC				2		 	/* Component is de-synchronized from the source */
#define cOCTVC1_LTE_BASS_STATE_SYNC_ENUM_INVALID			3		 	/* -- */

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_RX_LEVEL_ENUM : 	Status on received radio sample's level.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_BASS_RX_LEVEL_ENUM						tOCT_UINT32

#define cOCTVC1_LTE_BASS_RX_LEVEL_ENUM_OPTIMAL				0		 	/* Optimal received level */
#define cOCTVC1_LTE_BASS_RX_LEVEL_ENUM_HI					1		 	/* High level (not optimal) */
#define cOCTVC1_LTE_BASS_RX_LEVEL_ENUM_LO					2		 	/* Low level (not optimal) */
#define cOCTVC1_LTE_BASS_RX_LEVEL_ENUM_INVALID				3		 	/* -- */

#define cOCTVC1_LTE_BASS_MAX_NUM_CELL						6		 	/* Max number cell in the Bass list. */
#define cOCTVC1_LTE_BASS_MAX_BLACKLIST_CELL					6		 	/* Max number cell in the Bass blacklist. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_BLACKLIST_CONFIG
 		BASS black list.

 Members:
	ulNumPhysicalCellId
		Range:		[0..6]
		Default:	0
 		Number Pci in BlackList.
 		Value: 0.. BASS_MAX_BLACKLIST_CELL
	aPhysicalCellIdList
 		List of Physical Cell ID for blacklist
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulNumPhysicalCellId;
	tOCT_UINT32	aPhysicalCellIdList[cOCTVC1_LTE_BASS_MAX_BLACKLIST_CELL];

} tOCTVC1_LTE_BASS_BLACKLIST_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_CONFIG
 		BASS configuration.

 Members:
	ulSpecificPciFlag
		Default:	cOCT_TRUE
 		Use PhysicalCellID.
	ulPhysicalCellId
		Range:		[0..503]
		Default:	0
 		Physical Cell ID.
 		Value: 0..503
	ulFrameOffset
		Default:	0
 		Frame Offset in Samples
 		Value: 0..19200 for Bandwith 1.4Mhz
 		Value: 0..38400 for Bandwith 3 Mhz
 		Value: 0..76800 for Bandwith 5 Mhz
 		Value: 0..153600 for Bandwith 10 Mhz
 		Value: 0..307200 for Bandwith 20 Mhz
	ulRxGainFixedFlag
		Default:	cOCT_TRUE
 		Use RxGain specified in the Cell config. Otherwise, DSP will modify the RX Gain
 		to get the optimal RX level
	lSnrThreshold
		Range:		[-32767..32768]
		Default:	-32767
 		SNR threshold define the level above which the cell sync is performed (Q10)
	ulTrackingPeriod
		Range:		[8..128]
		Default:	32
 		Tracking period in 10 ms (Must be 2^n)
	tBlackListConfig
 		Black List Config.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32							ulSpecificPciFlag;
	tOCT_UINT32							ulPhysicalCellId;
	tOCT_UINT32							ulFrameOffset;
	tOCT_BOOL32							ulRxGainFixedFlag;
	tOCT_INT32							lSnrThreshold;
	tOCT_UINT32							ulTrackingPeriod;
	tOCTVC1_LTE_BASS_BLACKLIST_CONFIG	tBlackListConfig;

} tOCTVC1_LTE_BASS_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_CELL_STATS
 		BASS's cell statistics.

 Members:
	ulPhysicalCellId
		Range:		[0..503]
		Default:	0
 		Physical Cell ID.
 		Value: 0..503
	ulDuplexMode
		Default:	cOCTVC1_LTE_DUPLEX_MODE_ENUM_TDD
 		Duplexing mode.
	ulCpType
		Default:	cOCTVC1_LTE_CP_TYPE_ENUM_NORMAL
 		Cyclic Prefix.
	ulLinearPdpPower
		Range:		[0..65535]
		Default:	0
 		Pdp Power.
	sSnr
		Default:	0
 		in dB, SNR on Pdp Power (Q10)
	usReserved
		Default:	0
 		reserved
	lAverageFrequencyError
		Range:		[-7000..7000]
		Default:	0
 		Averaged frequency error in Hz
	ulRelFrameDelay
		Range:		[0..307200]
		Default:	0
 		Relative Frame delay from the Radio Sample capture (in samples)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulPhysicalCellId;
	tOCTVC1_LTE_DUPLEX_MODE_ENUM	ulDuplexMode;
	tOCTVC1_LTE_CP_TYPE_ENUM		ulCpType;
	tOCT_UINT32						ulLinearPdpPower;
	tOCT_INT16						sSnr;
	tOCT_UINT16						usReserved;
	tOCT_INT32						lAverageFrequencyError;
	tOCT_UINT32						ulRelFrameDelay;

} tOCTVC1_LTE_BASS_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_EVENT_CELL_INFO
 		BASS's event cell statistics.

 Members:
	ulPhysicalCellId
		Range:		[0..503]
		Default:	0
 		Physical Cell ID.
 		Value: 0..503
	sSnr
		Default:	0
 		in dB, SNR on Pdp Power (Q10)
	usReserved
		Default:	0
 		reserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulPhysicalCellId;
	tOCT_INT16	sSnr;
	tOCT_UINT16	usReserved;

} tOCTVC1_LTE_BASS_EVENT_CELL_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_CHANNEL_STATS
 		BASS's channel statistics.

 Members:
	ulRxLevelIndicator
		Default:	cOCTVC1_LTE_BASS_RX_LEVEL_ENUM_LO
 		Status on received radio sample's level
	ulNumCell
		Range:		[0..6]
		Default:	0
 		Number of Cell in the current earfcn.
	aCellList
 		List of Cell in the current earfcn
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_LTE_BASS_RX_LEVEL_ENUM	ulRxLevelIndicator;
	tOCT_UINT32						ulNumCell;
	tOCTVC1_LTE_BASS_CELL_STATS		aCellList[cOCTVC1_LTE_BASS_MAX_NUM_CELL];

} tOCTVC1_LTE_BASS_CHANNEL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_CONTROL_STATS
 		BASS's control statistics.

 Members:
	ulActiveSourceCellFlag
		Default:	cOCT_FALSE
 		Cell Source info: Indicate if the Source is active.
	ChannelInfo
 		Cell Source info: Detail of the active source
	ulCellSourceLostCnt
		Range:		[0..4294967295]
		Default:	0
 		Cell Source info: Source lost counter.
	lFrequencyCorrectionError
		Default:	0
 		Control: Last Frequency error (Hz) in Q0.
	ulFrequencyCorrectionCnt
		Range:		[0..4294967295]
		Default:	0
 		Control: cumulative count of the frequency correction.
	ulTrackingErrorCnt
		Range:		[0..4294967295]
		Default:	0
 		Control: cumulative Frequency error divergence count.
	ulTrackingTotalCnt
		Range:		[0..4294967295]
		Default:	0
 		Control: cumulative tracking count.
	lRxGaindB
		Range:		[0..4294967295]
		Default:	0
 		Control: Rx gain value in dB Q9.
	ulReserved
		Default:	0
 		Reserved.
	ulReserved1
		Default:	0
 		Reserved1.
	ulReserved2
		Default:	0
 		Reserved2.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32					ulActiveSourceCellFlag;
	tOCTVC1_LTE_BASS_CELL_STATS	ChannelInfo;
	tOCT_UINT32					ulCellSourceLostCnt;
	tOCT_INT32					lFrequencyCorrectionError;
	tOCT_UINT32					ulFrequencyCorrectionCnt;
	tOCT_UINT32					ulTrackingErrorCnt;
	tOCT_UINT32					ulTrackingTotalCnt;
	tOCT_INT32					lRxGaindB;
	tOCT_UINT32					ulReserved;
	tOCT_UINT32					ulReserved1;
	tOCT_UINT32					ulReserved2;

} tOCTVC1_LTE_BASS_CONTROL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_BASS_STATS

 Members:
	ulState
		Default:	cOCTVC1_LTE_BASS_STATE_ENUM_NOT_INITIALIZED
 		BASS status.
	ulStateSync
		Default:	cOCTVC1_LTE_BASS_STATE_SYNC_ENUM_NOTSYNC
 		BASS status.
	ChannelInfo
 		Channel information
	ControlInfo
 		Channel information
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_LTE_BASS_STATE_ENUM			ulState;
	tOCTVC1_LTE_BASS_STATE_SYNC_ENUM	ulStateSync;
	tOCTVC1_LTE_BASS_CHANNEL_STATS		ChannelInfo;
	tOCTVC1_LTE_BASS_CONTROL_STATS		ControlInfo;

} tOCTVC1_LTE_BASS_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_PHY_FRAME_SYNC_STATS
 		PHY frame synchronization statistics.

 Members:
	ulSfnSwitchOnGpioCheckCnt
 		Number of checks of the status bit of the GPIO interrupt register (once per
 		frame).
	ulSfnSwitchOnGpioRequestCnt
 		Number of SFN switch requests.
	ulSfnSwitchOnGpioErrorCnt
 		Number of errors.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulSfnSwitchOnGpioCheckCnt;
	tOCT_UINT32	ulSfnSwitchOnGpioRequestCnt;
	tOCT_UINT32	ulSfnSwitchOnGpioErrorCnt;

} tOCTVC1_LTE_PHY_FRAME_SYNC_STATS;

/*-------------------------------------------------------------------------------------
 	eNodeB Test definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_TEST_MODULE_STATE_ENUM : 	LTE test module state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_TEST_MODULE_STATE_ENUM					tOCT_UINT32

#define cOCTVC1_LTE_TEST_MODULE_STATE_ENUM_INVALID			0		
#define cOCTVC1_LTE_TEST_MODULE_STATE_ENUM_STOPPED			1		
#define cOCTVC1_LTE_TEST_MODULE_STATE_ENUM_STARTED			2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PHY_CONFIG
 		FAPI PHY configuration.

 Members:
	ulFapiConfigHoldFlag
		Default:	cOCT_FALSE
 		FAPI configuration hold flag.
 		TRUE: the same FAPI config is hold for every TTI.
 		FALSE: FAPI config is expected to be provided every TTI by L2 stack.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulFapiConfigHoldFlag;

} tOCTVC1_LTE_FAPI_PHY_CONFIG;

/*-------------------------------------------------------------------------------------
 	eNodeB ETM definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_ETM_CONFIG
 		ETM configuration.

 Members:
	ulEpreIndex
		Range:		[0..255]
		Default:	40
 		EPRE index.
 		It corresponds to Reference Signal Power parameter in FAPI specification.
 		It affects digital gain.
 		From 0 dB to -63.5 dB in steps of -0.25 dB
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulEpreIndex;

} tOCTVC1_LTE_ETM_CONFIG;

/*-------------------------------------------------------------------------------------
 	eNodeB FAPI definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PHY_STATE_ENUM : 	FAPI PHY State.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LTE_FAPI_PHY_STATE_ENUM						tOCT_UINT32

#define cOCTVC1_LTE_FAPI_PHY_STATE_ENUM_IDLE				0		
#define cOCTVC1_LTE_FAPI_PHY_STATE_ENUM_CONFIGURED			1		
#define cOCTVC1_LTE_FAPI_PHY_STATE_ENUM_RUNNING				2		
#define cOCTVC1_LTE_FAPI_PHY_STATE_ENUM_STOPPING			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_CELL_CONFIG
 		FAPI cell configuration.

 Members:
	ulDuplexingMode
 		Duplexing mode.
 		0: TDD
 		1: FDD
	ulDownlinkCyclicPrefixType
 		Downlink Cyclic Prefix.
 		0: NORMAL
 		1: EXTENDED
	ulUplinkCyclicPrefixType
 		Uplink Cyclic Prefix.
 		0: NORMAL
 		1: EXTENDED
	ulDownlinkChannelBandwidth
 		Number of Downlink Resource Blocks.
 		Value: 6, 15, 25, 50, 75, 100
	ulUplinkChannelBandwidth
 		Number of Uplink Resource Blocks.
 		Value: 6, 15, 25, 50, 75, 100
	ulTxAntennaPort
 		Tx antenna ports.
 		Number of cell specific transmit antenna ports.
 		Value:1,2,4
	ulRxAntennaPort
 		Rx antenna ports.
 		Number of cell specific receive antenna ports.
 		Value:1,2,4
	ulRefSignalPower
 		Reference Signal Power.
 		Normalized value levels (relative) to accommodate different absolute Tx Power.
 		Value: 0..255 representing 0dB to -63.75dB in steps of -0.25dB.
	ulPhysicalCellId
 		Physical Cell ID.
 		Value: 0..503
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulDuplexingMode;
	tOCT_UINT32	ulDownlinkCyclicPrefixType;
	tOCT_UINT32	ulUplinkCyclicPrefixType;
	tOCT_UINT32	ulDownlinkChannelBandwidth;
	tOCT_UINT32	ulUplinkChannelBandwidth;
	tOCT_UINT32	ulTxAntennaPort;
	tOCT_UINT32	ulRxAntennaPort;
	tOCT_UINT32	ulRefSignalPower;
	tOCT_UINT32	ulPhysicalCellId;

} tOCTVC1_LTE_FAPI_CELL_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PHICH_CONFIG
 		FAPI PHICH configuration.

 Members:
	ulResource
 		PHICH resource.
 		Determines the number of resource element groups used for PHICH.
 		0: 1/6
 		1: 1/2
 		2: 1
 		3: 2
	ulDuration
 		PHICH duration.
 		0: NORMAL
 		1: EXTENDED
	ulPowerOffset
 		PHICH power offset.
 		The power of PHICH with respect to the Reference Signal Power.
 		Value: 0..10000 representing -6dB to 4dB in steps of 0.001dB.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulResource;
	tOCT_UINT32	ulDuration;
	tOCT_UINT32	ulPowerOffset;

} tOCTVC1_LTE_FAPI_PHICH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PCFICH_CONFIG
 		FAPI PCFICH configuration.

 Members:
	ulPowerOffset
 		PCFICH power offset.
 		The power of PCFICH with respect to the Reference Signal Power.
 		Value: 0..10000 representing -6dB to 4dB in steps of 0.001dB.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulPowerOffset;

} tOCTVC1_LTE_FAPI_PCFICH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_DL_PHY_SIGNAL_CONFIG
 		FAPI Downlink PHY signal configuration.

 Members:
	ulPssPowerOffset
 		Primary Synchronization Signal (P-SS) power offset.
 		The power of P-SS with respect to the Reference Signal Power.
 		Value: 0..9999 representing -6dB to 4dB in steps of 0.001dB.
	ulSssPowerOffset
 		Secondary Synchronization Signal (P-SS) power offset.
 		The power of S-SS with respect to the Reference Signal Power.
 		Value: 0..9999 representing -6dB to 4dB in steps of 0.001dB.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulPssPowerOffset;
	tOCT_UINT32	ulSssPowerOffset;

} tOCTVC1_LTE_FAPI_DL_PHY_SIGNAL_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PRACH_CONFIG
 		FAPI PRACH configuration.

 Members:
	ulConfigIndex
 		PRACH configuration index.
 		Indicates the location and format of the PRACH. See TS36.211.
 		Value: 0..63
	ulRootSequenceIndex
 		PRACH root sequence index.
 		Value: 0..837
	ulZeroCorrelationZoneConfig
 		PRACH zero correlation zone configuration.
 		Equivalent to Ncs.
 		TDD: 0..6
 		FDD: 0..15
	ulHighSpeedFlag
 		PRACH high speed flag.
 		Indicates if unrestricted, or restricted, set of PRACH preambles is used.
 		0: UNRESTRICTED SET
 		1: RESTRICTED SET
	ulFrequencyOffset
 		PRACH frequency offset.
 		Index of the first Physical Resource Block (RB) available for PRACH.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulConfigIndex;
	tOCT_UINT32	ulRootSequenceIndex;
	tOCT_UINT32	ulZeroCorrelationZoneConfig;
	tOCT_UINT32	ulHighSpeedFlag;
	tOCT_UINT32	ulFrequencyOffset;

} tOCTVC1_LTE_FAPI_PRACH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PUSCH_CONFIG
 		FAPI PUSCH configuration.

 Members:
	ulHoppingMode
 		PUSCH hopping mode.
 		Valid only if hopping is enabled.
 		Indicates the type of hopping used.
 		0: INTER SUBFRAME
 		1: INTRA-INTER SUBFRAME
	ulHoppingOffset
 		PUSCH hopping offset.
 		Valid only if hopping is enabled.
 		Value: 0..98
	ulHoppingNumSubBand
 		PUSCH number of subbands used.
 		Valid only if hopping is enabled.
 		Value: 1..4
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulHoppingMode;
	tOCT_UINT32	ulHoppingOffset;
	tOCT_UINT32	ulHoppingNumSubBand;

} tOCTVC1_LTE_FAPI_PUSCH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_PUCCH_CONFIG
 		FAPI PUCCH configuration.

 Members:
	ulDeltaShift
 		PUCCH Delta Shift.
 		Cyclic shift difference.
 		Value: 1..3
	ulNumCqiRb
 		Number of Resource Blocks (RB) available for PUCCH formats 2/2a/2b (CQI).
 		Value: 0..98
	ulNumAnCs
 		Number of cyclic shifts used for PUCCH formats 1/1a/1b in a Resource Block with
 		a mix of formats 1/a/1/ab and 2/2a/2b.
 		Value: 0..7
	ulN1An
 		PUCCH resource index used for HARQ message transmission.
 		Value: 0..2047
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulDeltaShift;
	tOCT_UINT32	ulNumCqiRb;
	tOCT_UINT32	ulNumAnCs;
	tOCT_UINT32	ulN1An;

} tOCTVC1_LTE_FAPI_PUCCH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_SRS_CONFIG
 		FAPI Sounding Reference Signal (SRS) configuration.

 Members:
	ulBandwidthConfiguration
 		The available SRS bandwidth of the cell. The value is an index into the
 		referenced table.
 		Value: 0..7
	ulMaxUpPts
 		Indicates how SRS operates in UpPTS subframes.
 		Valid for TDD only.
 		0: Disabled.
 		1: Enabled.
	ulSubframeConfiguration
 		SRS subframe configuration.
 		Needed if semi-static configuration is held in PHY.
 		Value: 0..15
	ulAckNackSimulaneousTx
 		Indicates if SRS and ACK/NACK can be received in the same subframe.
 		Needed if semi-static configuration is held in PHY.
 		0: simultaneous not allowed.
 		1: simultaneous allowed.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulBandwidthConfiguration;
	tOCT_UINT32	ulMaxUpPts;
	tOCT_UINT32	ulSubframeConfiguration;
	tOCT_UINT32	ulAckNackSimulaneousTx;

} tOCTVC1_LTE_FAPI_SRS_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_UL_PHY_SIGNAL_CONFIG
 		FAPI Uplink PHY signal configuration.

 Members:
	ulRsHopping
 		Indicates the type of hopping to use.
 		0: NO HOPPING
 		1: GROUP HOPPING
 		2: SEQUENCE HOPPING
	ulRsGroupAssignment
 		Sequence shift pattern.
 		Valid if group hopping is enabled.
 		Value: 0..29
	ulRsCyclicShift1Dmrs
 		Specifies the cyclic shift for the reference signal used in the cell.
 		The value is an index into the referenced table.
 		Value: 0..7
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulRsHopping;
	tOCT_UINT32	ulRsGroupAssignment;
	tOCT_UINT32	ulRsCyclicShift1Dmrs;

} tOCTVC1_LTE_FAPI_UL_PHY_SIGNAL_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_TDD_CONFIG
 		FAPI TDD configuration.

 Members:
	ulSubframeAssignment
 		Indicates the DL/UL subframe structure.
 		Value: 0..6
	ulSpecialSubframePattern
 		Special Subframe configuration.
 		Determines the length of DwPTS, GP and UpPTS
 		Value: 0..8
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulSubframeAssignment;
	tOCT_UINT32	ulSpecialSubframePattern;

} tOCTVC1_LTE_FAPI_TDD_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_FAPI_CELL_PARAM_CONFIG
 		FAPI Cell Parameters configuration.

 Members:
	ulState
 		FAPI PHY state.
 		When IDLE, the content of Cell Config is not relevant.
	Cell
 		Cell configuration.
	Tdd
 		TDD cell configuration.
	Phich
 		PHICH cell configuration.
	Pcfich
 		PCFICH cell configuration.
	DownlinkPhySignal
 		Downlink Physical Signal cell configuration.
	Prach
 		PRACH cell configuration.
	Pusch
 		PUSCH cell configuration.
	Pucch
 		PUCCH cell configuration.
	Srs
 		SRS cell configuration.
	UplinkPhySignal
 		Uplink Physical signal cell configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_LTE_FAPI_PHY_STATE_ENUM			ulState;
	tOCTVC1_LTE_FAPI_CELL_CONFIG			Cell;
	tOCTVC1_LTE_FAPI_TDD_CONFIG				Tdd;
	tOCTVC1_LTE_FAPI_PHICH_CONFIG			Phich;
	tOCTVC1_LTE_FAPI_PCFICH_CONFIG			Pcfich;
	tOCTVC1_LTE_FAPI_DL_PHY_SIGNAL_CONFIG	DownlinkPhySignal;
	tOCTVC1_LTE_FAPI_PRACH_CONFIG			Prach;
	tOCTVC1_LTE_FAPI_PUSCH_CONFIG			Pusch;
	tOCTVC1_LTE_FAPI_PUCCH_CONFIG			Pucch;
	tOCTVC1_LTE_FAPI_SRS_CONFIG				Srs;
	tOCTVC1_LTE_FAPI_UL_PHY_SIGNAL_CONFIG	UplinkPhySignal;

} tOCTVC1_LTE_FAPI_CELL_PARAM_CONFIG;

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD
 		This command retrieves the LTE eNodeB module configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	ulBootProcConfigType
 		Profile type.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM	ulBootProcConfigType;

} tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD
 		This command modifies the LTE module configuration parameters.
 		This command will fail if LTE module is running.

 Members:
	Header
 		OCTVC1 Message Header.
	ulBootProcConfigType
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Profile type.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_LTE_MODULE_PROC_CONFIG_TYPE_ENUM	ulBootProcConfigType;

} tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	ulUserId
 		Host application object identifier.
	ulRfPortIndex
 		RF port index.
	CellConfig
 		LTE cell general configuration.
	CellTddConfig
 		LTE TDD configuration.
	RfConfig
 		RF configuration.
	bTxOuputScPwrEqual
		Default:	cOCT_FALSE
 		Allows Equal Pwr/SC across Bw.
	bUseExtFirCoeff
		Default:	cOCT_FALSE
 		Allows selecting External FIR coeff file.
	ulFrameBorderAlignEnableFlag
		Default:	cOCT_FALSE
 		Align frame border on external tick.
 		The PHY needs to be locked onto an external PPS clock.
	ulFrameBorderDelaySamples
		Default:	0
 		Configure delay between frame border and external tick.
 		In number of RF samples.
 		The Frame Border Alignment needs to be enabled, otherwise this is ignored.
	PhyConfig
 		PHY configuration.
	BassConfig
 		Bass configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCT_UINT32					ulUserId;
	tOCTVC1_INDEX				ulRfPortIndex;
	tOCTVC1_LTE_CELL_CONFIG		CellConfig;
	tOCTVC1_LTE_CELL_TDD_CONFIG	CellTddConfig;
	tOCTVC1_LTE_RF_CONFIG		RfConfig;
	tOCT_BOOL32					bTxOuputScPwrEqual;
	tOCT_BOOL32					bUseExtFirCoeff;
	tOCT_BOOL32					ulFrameBorderAlignEnableFlag;
	tOCT_UINT32					ulFrameBorderDelaySamples;
	tOCTVC1_LTE_PHY_CONFIG		PhyConfig;
	tOCTVC1_LTE_BASS_CONFIG		BassConfig;

} tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	ulUserId
 		Host application object identifier.
	ulStandardComplianceType
 		Whether the eNodeB configuration follows 3GPP specification or not.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_HANDLE_OBJECT				hEnodeb;
	tOCT_UINT32							ulUserId;
	tOCTVC1_LTE_COMPLIANCE_TYPE_ENUM	ulStandardComplianceType;

} tOCTVC1_LTE_MSG_ENODEB_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_LIST_CMD

 Members:
	Header
	ObjectCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_LTE_MSG_ENODEB_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_LIST_RSP

 Members:
	Header
	ObjectCursor
 		Object Cursor.
	ObjectList
 		Generic handle object list structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_LTE_MSG_ENODEB_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD
 		This command retrieves the eNodeB Cell configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	CellConfig
 		LTE cell general configuration.
	CellTddConfig
 		LTE cell TDD configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hEnodeb;
	tOCTVC1_LTE_CELL_CONFIG		CellConfig;
	tOCTVC1_LTE_CELL_TDD_CONFIG	CellTddConfig;

} tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	ulResetStatsFlag
 		Reset flag.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCT_UINT32				ulResetStatsFlag;

} tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	ulState
 		Cell state.
	Downlink
 		LTE cell general configuration.
	Uplink
 		LTE cell general configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hEnodeb;
	tOCTVC1_LTE_CELL_STATE_ENUM		ulState;
	tOCTVC1_LTE_CELL_STATS_DOWNLINK	Downlink;
	tOCTVC1_LTE_CELL_STATS_UPLINK	Uplink;

} tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	CellConfig
 		LTE cell general configuration.
	CellTddConfig
 		LTE TDD configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hEnodeb;
	tOCTVC1_LTE_CELL_CONFIG		CellConfig;
	tOCTVC1_LTE_CELL_TDD_CONFIG	CellTddConfig;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_START_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_START_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD
 		This command retrieves the eNodeB RF configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	ulRfPortIndex
 		RF port index.
	ulRfBandId
 		LTE RF Band ID.
	bUseExtFirCoeff
 		Allows selecting External FIR coeff file.
	RfConfig
 		RF configuration.
	aTxLogicalAntennaConfig
 		Tx logical antennas configuration.
	aRxLogicalAntennaConfig
 		Rx logical antennas configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hEnodeb;
	tOCTVC1_INDEX					ulRfPortIndex;
	tOCT_UINT32						ulRfBandId;
	tOCT_BOOL32						bUseExtFirCoeff;
	tOCTVC1_LTE_RF_CONFIG			RfConfig;
	tOCTVC1_LTE_RF_ANTENNA_CONFIG	aTxLogicalAntennaConfig[(2)];
	tOCTVC1_LTE_RF_ANTENNA_CONFIG	aRxLogicalAntennaConfig[(2)];

} tOCTVC1_LTE_MSG_ENODEB_INFO_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD
 		This command allows to modify eNodeB RF configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	RfConfig
 		RF configuration.
	aTxLogicalAntennaConfig
 		Tx logical antennas configuration.
	aRxLogicalAntennaConfig
 		Rx logical antennas configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hEnodeb;
	tOCTVC1_LTE_RF_CONFIG			RfConfig;
	tOCTVC1_LTE_RF_ANTENNA_CONFIG	aTxLogicalAntennaConfig[(2)];
	tOCTVC1_LTE_RF_ANTENNA_CONFIG	aRxLogicalAntennaConfig[(2)];

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD
 		This command retrieves the eNodeB PHY configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	bTxOuputScPwrEqual
 		Allows Equal Pwr/SC across Bw.
	ulFrameBorderAlignEnableFlag
 		Align frame border on external tick.
 		The PHY needs to be locked onto an external PPS clock.
	ulFrameBorderDelaySamples
 		Configure delay between frame border and external tick.
 		In number of RF samples.
 		The Frame Border Alignment needs to be enabled, otherwise this is ignored.
	PhyConfig
 		PHY configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCT_BOOL32				bTxOuputScPwrEqual;
	tOCT_BOOL32				ulFrameBorderAlignEnableFlag;
	tOCT_UINT32				ulFrameBorderDelaySamples;
	tOCTVC1_LTE_PHY_CONFIG	PhyConfig;

} tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD
 		This command modifies the eNodeB PHY configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	PhyConfig
 		PHY configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCTVC1_LTE_PHY_CONFIG	PhyConfig;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	FrameSync
 		Frame synchronizaiton statistics.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_HANDLE_OBJECT				hEnodeb;
	tOCTVC1_LTE_PHY_FRAME_SYNC_STATS	FrameSync;

} tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD
 		This command retrieves the eNodeB ETM configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	EtmConfig
 		ETM configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCTVC1_LTE_ETM_CONFIG	EtmConfig;

} tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD
 		This command modifies the eNodeB ETM configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	EtmConfig
 		ETM configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCTVC1_LTE_ETM_CONFIG	EtmConfig;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD
 		This command retrieves the eNodeB FAPI configuration parameters.
 		This will be only populated after L2 configures the PHY.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	FapiPhyConfig
 		FAPI PHY configuration.
	FapiCellConfig
 		FAPI cell configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_HANDLE_OBJECT				hEnodeb;
	tOCTVC1_LTE_FAPI_PHY_CONFIG			FapiPhyConfig;
	tOCTVC1_LTE_FAPI_CELL_PARAM_CONFIG	FapiCellConfig;

} tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD
 		This command modifies the eNodeB FAPI configuration parameters.
 		Note that FAPI parameters are configured by L2 stack. Parameters listed here
 		are not FAPI per se, but FAPI related.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	FapiPhyConfig
 		FAPI PHY configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hEnodeb;
	tOCTVC1_LTE_FAPI_PHY_CONFIG	FapiPhyConfig;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD
 		This command retrieves the eNodeB Bass parameters.

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	BassConfig
 		LTE cell Bass specific configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCTVC1_LTE_BASS_CONFIG	BassConfig;

} tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_START_BASS_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;

} tOCTVC1_LTE_MSG_ENODEB_START_BASS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		Reset Component's BASS statistics.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCT_BOOL32				ulResetStatsFlag;

} tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_RSP

 Members:
	Header
 		OCTVC1 Message Header.
	hEnodeb
 		Unique eNodeB identifier.
	BassStats
 		Bass statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hEnodeb;
	tOCTVC1_LTE_BASS_STATS	BassStats;

} tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_RSP;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_lte_evt.h"

#endif /* __OCTVC1_LTE_API_H__ */

