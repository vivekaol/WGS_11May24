/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_API.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the definition of the RUS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_API_H__
#define __OCTVC1_RUS_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_file.h"
#include "../octvc1_radio.h"

#include "octvc1_rus_id.h"
#include "octvc1_rus_rc.h"
#include "octvc1_rus_lic.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	RUS Application Module Id
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_APPLICATION_ID_MODULE_FRAMEWORK			((0x00)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	
#define cOCTVC1_RUS_APPLICATION_ID_SUB_MODULE_BASS			((0x01)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	
#define cOCTVC1_RUS_APPLICATION_ID_SUB_MODULE_WNM			((0x02)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	
#define cOCTVC1_RUS_APPLICATION_ID_SUB_MODULE_PLAYREC		((0x03)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	
#define cOCTVC1_RUS_APPLICATION_ID_SUB_MODULE_TEST			((0x04)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	RUS RFFI and PLAYER constant definitions
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_RFFI_TRANSMITTER_MAX					4		 	/* Max number Transmitter. */
#define cOCTVC1_RUS_RFFI_RECEIVER_MAX						8		 	/* Max number Transmitter. */

/*-------------------------------------------------------------------------------------
 	RUS RFFI and PLAYER type definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_PLAYER_STATE_ENUM : 	Describes the state of a player object.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_PLAYER_STATE_ENUM						tOCT_UINT32

#define cOCTVC1_RUS_PLAYER_STATE_ENUM_IDLE					0		
#define cOCTVC1_RUS_PLAYER_STATE_ENUM_STARTED				1		
#define cOCTVC1_RUS_PLAYER_STATE_ENUM_STOPPED				2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM : 	Antenna mode. Single Antenna, 2 Antenna
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM					tOCT_UINT32

#define cOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM_1ANT				0		 	/* Default: Single Antenna, Antenna selection is done through config file */
#define cOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM_2ANT				1		 	/* 2 Antennas */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM : 	Describes the unit used for capture.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM_NONE			0		
#define cOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM_MS			1		
#define cOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM_SAMPLES		2		
#define cOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM_RADIO_SLOT	3		
#define cOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM_FOREVER		4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_SAMPLING_RATE_ENUM : 	Describes the unit used for capture.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_SAMPLING_RATE_ENUM						tOCT_UINT32

#define cOCTVC1_RUS_SAMPLING_RATE_ENUM_1920_KHZ				0		
#define cOCTVC1_RUS_SAMPLING_RATE_ENUM_3840_KHZ				1		
#define cOCTVC1_RUS_SAMPLING_RATE_ENUM_7680_KHZ				2		
#define cOCTVC1_RUS_SAMPLING_RATE_ENUM_15360_KHZ			3		
#define cOCTVC1_RUS_SAMPLING_RATE_ENUM_30720_KHZ			4		
#define cOCTVC1_RUS_SAMPLING_RATE_ENUM_61440_KHZ			5		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFFI_RX_STATS

 Members:
	eLinkType
 		Radio link the direction
	ulUarfcn
		Default:	0
 		Uarfcn
	ulFrequency
		Default:	0
 		Carier frequency in Hz
	RTWPdBm
		Range:		[-1300..0]
		Default:	-81920
 		Received Total Wideband Power (dBm) (Q9 representation)
	lRxGain
		Range:		[0..35840]
		Default:	0
 		In cOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_MGC mode: The lRxGain is applied to the
 		receiver.
 		The range is between 0 and 70dB with a resoltuion of 1dB (in Q9)
 		In all cOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_AGC mode: the lRxGain is
 		automatically adjusted by the AGC
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulUarfcn;
	tOCT_UINT32						ulFrequency;
	tOCT_INT32						RTWPdBm;
	tOCT_INT32						lRxGain;

} tOCTVC1_RUS_RFFI_RX_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFFI_TX_STATS

 Members:
	eLinkType
 		Radio link the direction
	ulUarfcn
		Default:	0
 		Uarfcn
	ulFrequency
		Default:	0
 		Carier frequency in Hz
	PowerdBm
		Range:		[-81920..5120]
		Default:	-81920
 		Transmitted Power (dBm) (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulUarfcn;
	tOCT_UINT32						ulFrequency;
	tOCT_INT32						PowerdBm;

} tOCTVC1_RUS_RFFI_TX_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_UMTS_TX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	ulUarfcn
		Default:	10700
 		Uarfcn Ul or DL according Band selection
	lGaindB
		Range:		[-45952..0]
		Default:	-15360
 		Controls radio transmitter attenuation.
 		From 0 dB to -89.75 dB with a resolution of 0.25 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulUarfcn;
	tOCT_INT32						lGaindB;

} tOCTVC1_RUS_RFI_UMTS_TX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_UMTS_RX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	ulUarfcn
		Default:	10701
 		Uarfcn Ul or DL according Band selection
	ulGaindB
		Range:		[0..37376]
		Default:	0
 		Controls radio receiver manual gain in analog domain
 		From 0 dB to 73.0 dB with a resolution of 1 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulUarfcn;
	tOCT_UINT32						ulGaindB;

} tOCTVC1_RUS_RFI_UMTS_RX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_UMTS

 Members:
	ulBand
		Default:	cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_1
 		Frequence Band
	Tx
	Rx
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM	ulBand;
	tOCTVC1_RUS_RFI_UMTS_TX						Tx;
	tOCTVC1_RUS_RFI_UMTS_RX						Rx;

} tOCTVC1_RUS_RFI_UMTS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_UMTS_STATS

 Members:
	Rx
	Tx
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RUS_RFFI_RX_STATS	Rx;
	tOCTVC1_RUS_RFFI_TX_STATS	Tx;

} tOCTVC1_RUS_RFI_UMTS_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_LTE_TX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	ulUarfcn
		Default:	300
 		Uarfcn Ul or DL according Band selection
	lGaindB
		Range:		[-45952..0]
		Default:	-15360
 		Controls radio transmitter attenuation.
 		From 0 dB to -89.75 dB with a resolution of 0.25 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulUarfcn;
	tOCT_INT32						lGaindB;

} tOCTVC1_RUS_RFI_LTE_TX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_LTE_RX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_UPLINK
 		Radio link the direction
	ulUarfcn
		Default:	18300
 		Uarfcn Ul or DL according Band selection
	ulGaindB
		Range:		[0..37376]
		Default:	0
 		Controls radio receiver manual gain in analog domain
 		From 0 dB to 73.0 dB with a resolution of 1 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulUarfcn;
	tOCT_UINT32						ulGaindB;

} tOCTVC1_RUS_RFI_LTE_RX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_LTE

 Members:
	ulBwId
		Default:	cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_5MHZ
 		Bandwith Frequence Band
	ulBand
		Default:	cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_1
 		The band identifier
	Tx
	Rx
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM		ulBwId;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM	ulBand;
	tOCTVC1_RUS_RFI_LTE_TX						Tx;
	tOCTVC1_RUS_RFI_LTE_RX						Rx;

} tOCTVC1_RUS_RFI_LTE;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_LTE_STATS

 Members:
	ulBwId
		Default:	cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_5MHZ
 		Bandwith Frequence Band
	Rx
	Tx
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM	ulBwId;
	tOCTVC1_RUS_RFFI_RX_STATS				Rx;
	tOCTVC1_RUS_RFFI_TX_STATS				Tx;

} tOCTVC1_RUS_RFI_LTE_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_GSM_TX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	lGaindB
		Range:		[-45952..0]
		Default:	-15360
 		Controls radio transmitter attenuation.
 		From 0 dB to -89.75 dB with a resolution of 0.25 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_INT32						lGaindB;

} tOCTVC1_RUS_RFI_GSM_TX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_GSM_RX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	ulGaindB
		Range:		[0..37376]
		Default:	0
 		Controls radio receiver manual gain in analog domain
 		From 0 dB to 73.0 dB with a resolution of 1 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulGaindB;

} tOCTVC1_RUS_RFI_GSM_RX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_GSM

 Members:
	ulBand
		Default:	cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_E_900
 		TO DO: Frequence Band
	ulUarfcn
		Default:	124
 		Uarfcn number associated to the selected band
	Tx
	Rx
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM	ulBand;
	tOCT_UINT32									ulUarfcn;
	tOCTVC1_RUS_RFI_GSM_TX						Tx;
	tOCTVC1_RUS_RFI_GSM_RX						Rx;

} tOCTVC1_RUS_RFI_GSM;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_GSM_STATS

 Members:
	Rx
	Tx
	ulReserved
		Default:	0
 		Reserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RUS_RFFI_RX_STATS	Rx;
	tOCTVC1_RUS_RFFI_TX_STATS	Tx;
	tOCT_UINT32					ulReserved;

} tOCTVC1_RUS_RFI_GSM_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_CDMA2000_TX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	lGaindB
		Range:		[-45952..0]
		Default:	-15360
 		Controls radio transmitter attenuation.
 		From 0 dB to -89.75 dB with a resolution of 0.25 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_INT32						lGaindB;

} tOCTVC1_RUS_RFI_CDMA2000_TX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_CDMA2000_RX

 Members:
	eLinkType
		Default:	cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK
 		Radio link the direction
	ulGaindB
		Range:		[0..37376]
		Default:	0
 		Controls radio receiver manual gain in analog domain
 		From 0 dB to 73.0 dB with a resolution of 1 dB (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_ID_DIRECTION_ENUM	eLinkType;
	tOCT_UINT32						ulGaindB;

} tOCTVC1_RUS_RFI_CDMA2000_RX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_CDMA2000

 Members:
	ulBand
		Default:	cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_1
 		The band identifier
	ulRfcn
		Default:	0
 		Rfcn number associated to the selected band
	Tx
	Rx
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM	ulBand;
	tOCT_UINT32										ulRfcn;
	tOCTVC1_RUS_RFI_CDMA2000_TX						Tx;
	tOCTVC1_RUS_RFI_CDMA2000_RX						Rx;

} tOCTVC1_RUS_RFI_CDMA2000;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_CDMA2000_STATS

 Members:
	Rx
	Tx
	ulReserved
		Default:	0
 		Reserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RUS_RFFI_RX_STATS	Rx;
	tOCTVC1_RUS_RFFI_TX_STATS	Tx;
	tOCT_UINT32					ulReserved;

} tOCTVC1_RUS_RFI_CDMA2000_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_CONFIG

 Members:
	szConfigFileName
 		default is empty to use the file supplied with the RUS binary (
 		'octsdr_rus_adi_config.bin' ).
	ulSamplingRate
		Default:	0
 		ulSamplingRate
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT8						szConfigFileName[(cOCTVC1_FILE_NAME_MAX_LENGTH+1)];
	tOCTVC1_RUS_SAMPLING_RATE_ENUM	ulSamplingRate;

} tOCTVC1_RUS_RFI_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_RFI_LOOPBACK

 Members:
	ulLoopbackEnableFlag
		Default:	0
 		Loopback from Rx capture
	ulLoopbackDelayInSamples
		Default:	0
 		Loopback delay in samples
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulLoopbackEnableFlag;
	tOCT_UINT32	ulLoopbackDelayInSamples;

} tOCTVC1_RUS_RFI_LOOPBACK;

/*-------------------------------------------------------------------------------------
 	WNM constant definitions
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_WNM_TEST_SIC							1		 	/* Defines the maximum of search entry of the list */
#define cOCTVC1_RUS_WNM_SEARCH_MAX_ENTRY					32		 	/* Defines the maximum of search entry of the list */
#define cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE		32767	 	/* pecifies the default values of the number of Bch block to decode; This */
 																		/* corresponds to the maximum payload file size */
#define cOCTVC1_RUS_WNM_GSM_BCCH_TB_PAYLOAD_CNT				24		 	/* Defines the payload size of the GSM BCCH */
#define cOCTVC1_RUS_WNM_GSM_BCCH_MAX_NUM_TB_IN_FILE			128		 	/* Defines the maximum number of GSM BCCH transport block in the capture file */
#define cOCTVC1_RUS_WNM_GSM_MAX_BTS_BY_CARRIER				1		 	/* Defines the maximum number of Base station than can be detected in the same */
 																		/* carrier */
#define cOCTVC1_RUS_WNM_CDMA2000_SI_TB_PAYLOAD_CNT			256		 	/* Defines the maximum SI payload size of the CDMA2000 Message */
#define cOCTVC1_RUS_WNM_CDMA2000_SI_MAX_NUM_TB_IN_FILE		128		 	/* Defines the maximum number of SI's TB in the payload file */
#define cOCTVC1_RUS_WNM_CDMA2000_MAX_BTS_BY_CARRIER			8		 	/* Defines the maximum number of Base station than can be detected in the same */
 																		/* carrier */
#define cOCTVC1_RUS_WNM_CDMA2000_MSG_FIELD_NOT_AVAILABLE	-1		 	/* Dynamic field with 0 bit are tag as not available */
#define cOCTVC1_RUS_WNM_UMTS_BCH_TB_PAYLOAD_CNT				32		 	/* Defines the payload size of the UMTS BCH Tch */
#define cOCTVC1_RUS_WNM_UMTS_BCH_MAX_NUM_TB_IN_FILE			2048	 	/* Defines the maximum number of UMTS BCH transport block in the capture file */
#define cOCTVC1_RUS_WNM_UMTS_MAX_NODEB_BY_CARRIER			8		 	/* Defines the maximum number of NodeB than can be detected in the same carrier */
#define cOCTVC1_RUS_WNM_LTE_BCH_TB_PAYLOAD_CNT				280		 	/* Defines the payload size of the LTE BCH Tch */
#define cOCTVC1_RUS_WNM_LTE_BCH_MAX_NUM_TB_IN_FILE			1024	 	/* Defines the maximum number of LTE BCH transport block in the capture file */
#define cOCTVC1_RUS_WNM_LTE_MAX_BTS_BY_CARRIER				6		 	/* Defines the maximum number of Base station than can be detected in the same */
 																		/* carrier */
#define cOCTVC1_RUS_WNM_NR_BCH_TB_PAYLOAD_CNT				512		 	/* Defines the payload size of the NR BCH Tch */
#define cOCTVC1_RUS_WNM_NR_BCH_MAX_NUM_TB_IN_FILE			16		 	/* Defines the maximum number of NR BCH transport block in the capture file */
#define cOCTVC1_RUS_WNM_NR_MAX_BTS_BY_CARRIER				6		 	/* Defines the maximum number of Base station than can be detected in the same */
 																		/* carrier */
#define cOCTVC1_RUS_WNM_RSSI_MAX_NUM_RSSI_CHANNEL_ENTRY		2000	 	/* Defines the maximum number of RSSI channel measurements in a given band */
#define cOCTVC1_RUS_WNM_MAX_NUM_2GBTS_BY_DB					300		 	/* Defines the maximum number of 2G Base Station in the 2G database */
#define cOCTVC1_RUS_WNM_MAX_NUM_CDMA2000BTS_BY_DB			64		 	/* Defines the maximum number of CDMA2000 Base Station in the C2K database */
#define cOCTVC1_RUS_WNM_MAX_NUM_3GBTS_BY_DB					64		 	/* Defines the maximum number of 3G Base Station in the 3G database */
#define cOCTVC1_RUS_WNM_MAX_NUM_4GBTS_BY_DB					48		 	/* Defines the maximum number of 4G Base Station in the 4G database */
#define cOCTVC1_RUS_WNM_MAX_NUM_5GBTS_BY_DB					32		 	/* Defines the maximum number of 5G Base Stations in the 5G database */
#define cOCTVC1_RUS_WNM_MAX_NUM_RSSI_CHX_BY_DB				32		 	/* Defines the maximum number of RSSI channel object in the RSSI database */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_ALL_RFCN				2147483647	 	/* Setting up the 'ulUarfcnStart' with this constant in the search entry performs */
 																		/* the search on all arfcn of the selected 'ulBand' */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED		-81920	 	/* WNM entry threshold default value */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_RSSI_THRESHOLD_MIN		-81920	 	/* Min entry RSSI threshold (-160.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_RSSI_THRESHOLD_MAX		-5120	 	/* Max entry RSSI threshold (-10.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_GSM_SNR_THRESHOLD_MIN	-0		 	/* Min SNR threshold for GSM ( 0.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_GSM_SNR_THRESHOLD_MAX	25600	 	/* Max SNR threshold for GSM ( 50.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_CDMA2000_RSCP_THRESHOLD_MIN	-61440	 	/* Min Rscp threshold for CDMA2000 (-120.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_CDMA2000_RSCP_THRESHOLD_MAX	-10240	 	/* Max Rscp threshold for CDMA2000 (-20.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_CDMA2000_ECI0_THRESHOLD_MIN	-12800	 	/* Min Ec/I0 threshold for CDMA2000 (-25.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_CDMA2000_ECI0_THRESHOLD_MAX	0		 	/* Max Ec/I0 threshold for CDMA2000 ( 0.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_UMTS_RSCP_THRESHOLD_MIN	-61440	 	/* Min Rscp threshold for UMTS (-120.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_UMTS_RSCP_THRESHOLD_MAX	-10240	 	/* Max Rscp threshold for UMTS (-20.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_UMTS_ECI0_THRESHOLD_MIN	-12800	 	/* Min Ec/I0 threshold for UMTS (-25.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_UMTS_ECI0_THRESHOLD_MAX	0		 	/* Max Ec/I0 threshold for UMTS ( 0.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_LTE_RSRP_THRESHOLD_MIN	-71680	 	/* Min RSRP threshold for LTE ( -140.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_LTE_RSRP_THRESHOLD_MAX	-22528	 	/* Max RSRP threshold for LTE ( -44.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_LTE_RSRQ_THRESHOLD_MIN	-12800	 	/* Min RSRQ threshold for LTE (-25.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_LTE_RSRQ_THRESHOLD_MAX	0		 	/* Max RSRQ threshold for LTE ( 0.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_RSRP_THRESHOLD_MIN	-71680	 	/* Min SS-RSRP threshold for NR ( -140.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_RSRP_THRESHOLD_MAX	-22528	 	/* Max SS-RSRP threshold for NR ( -44.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_RSRQ_THRESHOLD_MIN	-12800	 	/* Min SS-RSRQ threshold for NR (-25.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_RSRQ_THRESHOLD_MAX	0		 	/* Max SS-RSRQ threshold for NR ( 0.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_SINR_THRESHOLD_MIN	-12800	 	/* Min SS-SINR threshold for NR (-25.0 * 512) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_SINR_THRESHOLD_MAX	0		 	/* Max SS-SINR threshold for NR ( 0.0 * 512 ) */
#define cOCTVC1_RUS_WNM_SEARCH_ENTRY_NR_SA_ALL_RFCN			2147450879	 	/* Use only with NR entries: Setting up the 'ulUarfcnStart' with this constant in */
 																		/* the search entry performs the search on all GSCN of the selected 'ulBand' */
#define cOCTVC1_RUS_WNM_RXMODE_DEFAULT						1		 	/* By default enable the manual gain control of the receiver. */
#define cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_USE_DEFAULT			2147483647	 	/* use default MGC gain */
#define cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_DEFAULT				19456	 	/* Default MGC gain in Q9 */
#define cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_MAX					35840	 	/* Default MGC gain in Q9 */
#define cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_MIN					0		 	/* Default MGC gain in Q9 */

/*-------------------------------------------------------------------------------------
 	WNM type definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_RXMODE_ENUM : 	Receiver gain control mode
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_RXMODE_ENUM							tOCT_UINT32

#define cOCTVC1_RUS_WNM_RXMODE_ENUM_MGC						0		
#define cOCTVC1_RUS_WNM_RXMODE_ENUM_AGC						1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SEARCH_MODE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SEARCH_MODE_ENUM					tOCT_UINT32

#define cOCTVC1_RUS_WNM_SEARCH_MODE_ENUM_EXHAUSTIVE			0		 	/* Search on the entire scan entry list. Scan stops automatically at the end of */
 																	/* the list */
 																	/* Perform the base station's system information decoding (if BS is found) */
#define cOCTVC1_RUS_WNM_SEARCH_MODE_ENUM_RSSI_ONLY			1		 	/* Perform only the RSSI measure. Scan stops automatically at the end of the list */
#define cOCTVC1_RUS_WNM_SEARCH_MODE_ENUM_DETECTION_ONLY		2		 	/* Perform only the Cell search procedure with RSSI/SNR measurements. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK : 	Mask specifying what SI message user is interested in.
 	Once the selected Sibs are encountered during the cell decoding,
 	scanner is automatically reconfigured for the next entry
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK				tOCT_UINT32

#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_NONE			((tOCT_UINT32)(0<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_1			((tOCT_UINT32)(1<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2			((tOCT_UINT32)(1<<1) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2BIS		((tOCT_UINT32)(1<<2) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2TER		((tOCT_UINT32)(1<<3) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2QUATER	((tOCT_UINT32)(1<<4) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2N			((tOCT_UINT32)(1<<5) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_3			((tOCT_UINT32)(1<<6) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_4			((tOCT_UINT32)(1<<7) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_9			((tOCT_UINT32)(1<<8) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_13			((tOCT_UINT32)(1<<9) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_13ALT		((tOCT_UINT32)(1<<10) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_15			((tOCT_UINT32)(1<<11) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_21			((tOCT_UINT32)(1<<12) )	
#define cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_ALL			0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK : 	Mask specifying what SI message user is interested in.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK			tOCT_UINT32

#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_NONE		((tOCT_UINT32)(0<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_SPM		((tOCT_UINT32)(1<<0) )	 	/* System Parameters Message. */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_APM		((tOCT_UINT32)(1<<1) )	 	/* Access Parameters Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_NLM		((tOCT_UINT32)(1<<2) )	 	/* Neighbor List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_CCLM		((tOCT_UINT32)(1<<3) )	 	/* CDMA Channel List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_ESPM		((tOCT_UINT32)(1<<4) )	 	/* Extended System Parameters Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_GPM		((tOCT_UINT32)(1<<5) )	 	/* Extended System Parameters Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_GSRDM	((tOCT_UINT32)(1<<6) )	 	/* Global Service Redirect */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_ENLM		((tOCT_UINT32)(1<<7) )	 	/* Extended Neighbor List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_GNLM		((tOCT_UINT32)(1<<8) )	 	/* Global Neighbor List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_UZIM		((tOCT_UINT32)(1<<9) )	 	/* User Zone Identification Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_PNLM		((tOCT_UINT32)(1<<10) )	 	/* Private Neighbor List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_EGSRM	((tOCT_UINT32)(1<<11) )	 	/* Extended Global Redirect Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_ECCLM	((tOCT_UINT32)(1<<12) )	 	/* Extended CDMA Channel List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_ATIM		((tOCT_UINT32)(1<<13) )	 	/* Alternative Technologies Information Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_APIDM	((tOCT_UINT32)(1<<14) )	 	/* Access Point Identifier Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_APIDTM	((tOCT_UINT32)(1<<15) )	 	/* Access Point Identifier Text Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_APPIM	((tOCT_UINT32)(1<<16) )	 	/* Access Point Pilot Information Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_GOIM		((tOCT_UINT32)(1<<17) )	 	/* General Overhead InformationMessage */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_FDCCLM	((tOCT_UINT32)(1<<18) )	 	/* Flex Duplex CDMA Channel List Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_FGOIM	((tOCT_UINT32)(1<<19) )	 	/* Frequent General Overhead Information Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_GAPM		((tOCT_UINT32)(1<<20) )	 	/* Generic Access Parameter Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_HDPPM	((tOCT_UINT32)(1<<21) )	 	/* HDP Parameters Message */
#define cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_ALL		0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK : 	Mask specifying what SIBs user is interested in.
 	Once the selected Sibs are encountered during the cell decoding,
 	scanner is automatically reconfigured for the next entry
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK				tOCT_UINT32

#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_NONE			((tOCT_UINT32)(0<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB1			((tOCT_UINT32)(1<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB2			((tOCT_UINT32)(1<<1) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB3			((tOCT_UINT32)(1<<2) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB4			((tOCT_UINT32)(1<<3) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB5			((tOCT_UINT32)(1<<4) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB5_BIS		((tOCT_UINT32)(1<<5) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB6			((tOCT_UINT32)(1<<6) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB7			((tOCT_UINT32)(1<<7) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB11		((tOCT_UINT32)(1<<8) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB12		((tOCT_UINT32)(1<<9) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB13		((tOCT_UINT32)(1<<10) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB13_1		((tOCT_UINT32)(1<<11) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB13_2		((tOCT_UINT32)(1<<12) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB13_3		((tOCT_UINT32)(1<<13) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB13_4		((tOCT_UINT32)(1<<14) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB14		((tOCT_UINT32)(1<<15) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB15		((tOCT_UINT32)(1<<16) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB15_1		((tOCT_UINT32)(1<<17) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB15_2		((tOCT_UINT32)(1<<18) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB15_3		((tOCT_UINT32)(1<<19) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB15_4		((tOCT_UINT32)(1<<20) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB15_5		((tOCT_UINT32)(1<<21) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB16		((tOCT_UINT32)(1<<22) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB17		((tOCT_UINT32)(1<<23) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB18		((tOCT_UINT32)(1<<24) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_SIB19		((tOCT_UINT32)(1<<25) )	
#define cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_ALL			0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK : 	Mask specifying what SIBs user is interested in.
 	Once the selected Sibs are encountered during the cell decoding,
 	scanner is automatically reconfigured for the next entry
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK				tOCT_UINT32

#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_NONE			((tOCT_UINT32)(0<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB2			((tOCT_UINT32)(1<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB3			((tOCT_UINT32)(1<<1) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB4			((tOCT_UINT32)(1<<2) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB5			((tOCT_UINT32)(1<<3) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB6			((tOCT_UINT32)(1<<4) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB7			((tOCT_UINT32)(1<<5) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB8			((tOCT_UINT32)(1<<6) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB9			((tOCT_UINT32)(1<<7) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB10			((tOCT_UINT32)(1<<8) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB11			((tOCT_UINT32)(1<<9) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB12			((tOCT_UINT32)(1<<10) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_SIB13			((tOCT_UINT32)(1<<11) )	
#define cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_ALL			0x0000FFFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK : 	Mask specifying what SIBs user is interested in.
 	Once the selected Sibs are encountered during the cell decoding,
 	Scanner is automatically reconfigured for the next entry
 	Not Supported for now.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK				tOCT_UINT32

#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_NONE			((tOCT_UINT32)(0<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB2			((tOCT_UINT32)(1<<0) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB3			((tOCT_UINT32)(1<<1) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB4			((tOCT_UINT32)(1<<2) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB5			((tOCT_UINT32)(1<<3) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB6			((tOCT_UINT32)(1<<4) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB7			((tOCT_UINT32)(1<<5) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB8			((tOCT_UINT32)(1<<6) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB9			((tOCT_UINT32)(1<<7) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB10			((tOCT_UINT32)(1<<8) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB11			((tOCT_UINT32)(1<<9) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB12			((tOCT_UINT32)(1<<10) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_SIB13			((tOCT_UINT32)(1<<11) )	
#define cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_ALL			0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SELECTIVE_SIB_DECODING

 Members:
	ulEnableFlag
		Default:	cOCT_FALSE
 		Enable the selective sib decoding
	ulGsmSIMask
		Default:	(cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2|cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_3|cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_4)
 		Considered only when ulEnableFlag == cOCT_TRUE.
 		Mask allowing to select the GSM SI messages we are interested in
	ulCdma2000SIMask
		Default:	(cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_SPM|cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_APM|cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_NLM)
 		Considered only when ulEnableFlag == cOCT_TRUE.
 		Mask allowing to select the CDMA2000 SI messages we are interested in
	ulUmtsSibMask
		Default:	cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_ALL
 		Considered only when ulEnableFlag == cOCT_TRUE.
 		Mask allowing to select the UMTS Sibs we are interested in. Mib is always
 		decoded
	ulLteSibMask
		Default:	cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_ALL
 		Considered only when ulEnableFlag == cOCT_TRUE.
 		Mask allowing to select the LTE Sibs we are interested in. MIB and SIB1 are
 		always decoded
	ulNrSibMask
		Default:	cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_NONE
 		Considered only when ulEnableFlag == cOCT_TRUE.
 		Mask allowing to select the NR Sibs we are interested in. MIB is always decoded
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32									ulEnableFlag;
	tOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK		ulGsmSIMask;
	tOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK	ulCdma2000SIMask;
	tOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK		ulUmtsSibMask;
	tOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK		ulLteSibMask;
	tOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK		ulNrSibMask;

} tOCTVC1_RUS_WNM_SELECTIVE_SIB_DECODING;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SEARCH_STATE_ENUM : 	Defines the Cell search status
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SEARCH_STATE_ENUM					tOCT_UINT32

#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_UNINITIALZED		0		 	/* No scan entry list is setuped */
#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_INITIALZED		1		 	/* The scan entry list is setuped */
#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_SEARCHING			2		 	/* The scan is active and proceed the element of the scan list */
#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_DONE				3		 	/* Scanner has completed the list */
#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_PAUSE				4		 	/* Scanner breaks before the next carrier to analyse */
#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_ABORT_ERROR		5		 	/* Abort: internal error. Cause of the failure is in the log file */
#define cOCTVC1_RUS_WNM_SEARCH_STATE_ENUM_QUICK_SEARCH		6		 	/* The scan is active and proceed the element of the scan list */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM : 	Defines the diagnostic code error of the searcher
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM							tOCT_UINT32

#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_SUCCESSFUL						0		
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_CELL_DATABASE_EXCEED_LIMIT		1		 	/* Cell data base exceed the limit */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_DECODER_TIMEOUT				2		 	/* Decoder doesn't response */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_RFFI_TIMEOUT					3		 	/* Radio Farm Interface doesn't response */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_DECODER_ERROR					4		 	/* Decoder register a fatal error. */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_CELL_DATABASE_ACCESS_ERROR		5		 	/* Cell data base access error */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_RSSI_DATABASE_EXCEED_LIMIT		6		 	/* Rssi data base exceed the limit */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_RSSI_DATABASE_ACCESS_ERROR		7		 	/* Rssi data base access error */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_LICENSE_1_ERROR				8		 	/* License error 1 */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_RFFI_SCH_ERROR					9		 	/* Timeout during the Quick search process */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_QUICK_SCH_ERROR				10		 	/* Timeout during the Quick search process */
#define cOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM_QUICK_SEARCH_TIMEOUT			11		 	/* Timeout during the Quick search process */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SEARCH_ENTRY

 Members:
	ulWaveForm
		Default:	cOCTVC1_RADIO_STANDARD_ENUM_UMTS
 		Defines the standard
	ulBand
		Default:	1
 		The band identifier is interpreted accorging the waveform
	ulUarfcnStart
 		It defines, with ulUarfcnStop, the range of carrier frequency
 		to scan according the waveform and the band. This corresponds
 		to the uarfcn of the first element to scan;
 		Note: cOCTVC1_RUS_WNM_SEARCH_ENTRY_ALL_RFCN, the scan performs all carrier of
 		the band specified by ulBand. (ulUarfcnStop is ignored in this case)
	ulUarfcnStop
 		It defines, with ulUarfcnStart, the range of carrier frequency
 		to scan according the waveform and the band. This corresponds
 		to the uarfcn of the last element to scan;
	lRssiThreshold
		Range:		[cOCTVC1_RUS_WNM_SEARCH_ENTRY_RSSI_THRESHOLD_MIN..cOCTVC1_RUS_WNM_SEARCH_ENTRY_RSSI_THRESHOLD_MAX]
		Default:	cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED
 		Rssi threshold define the level above which the cell search is performed.
 		Rssi is in dBm (Q9 representation).
 		Default -81920 (-160.0 dBm).
	lRSPThresholddBm
		Range:		[-71680..-10240]
		Default:	cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED
 		RSP Threshold corresponds to the level of the reference signal power above
 		which the cell decoding will be performed.
 		* Not applicable for GSM
 		* RSCP threshold for CDMA2000 in [-120 -20] * 512 range.
 		* RSCP threshold for UMTS in [-120 -20] * 512 range.
 		* RSRP threshold for LTE in [-140 -44] * 512 range.
 		RSP is in dBm (Q9 representation).
 		Default -81920 (-160.0 dBm).
	lSQThresholddB
		Range:		[-12800..25600]
		Default:	cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED
 		SQ threshold defines the level of the Signal quality above which the cell
 		decoding will be performed.
 		* SNR threshold for GSM in [0 50] * 512 range
 		* Ec/I0 threshold for CDMA2000 in [-25 0] * 512 range.
 		* Ec/I0 threshold for UMTS in [-25 0] * 512 range.
 		* RSRQ threshold for LTE in [-25 0] * 512 range.
 		SQ is in dBm (Q9 representation).
 		Default -81920 (-160.0 dBm).
	usMaxBchPayloadBlockCnt
		Default:	cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE
 		Defines the number of Bch blocs to decode; This control the duration of the
 		decoder
	usReserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM	ulWaveForm;
	tOCT_UINT32					ulBand;
	tOCT_UINT32					ulUarfcnStart;
	tOCT_UINT32					ulUarfcnStop;
	tOCT_INT32					lRssiThreshold;
	tOCT_INT32					lRSPThresholddBm;
	tOCT_INT32					lSQThresholddB;
	tOCT_UINT16					usMaxBchPayloadBlockCnt;
	tOCT_UINT16					usReserved;

} tOCTVC1_RUS_WNM_SEARCH_ENTRY;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SEARCH_PARMS

 Members:
	ulEntryCount
		Default:	1
 		Number of cell entries in the list to search
	ulSearchMode
 		Used to select how exhaustive the search is
	ulRxGainControlMode
		Default:	cOCTVC1_RUS_WNM_RXMODE_ENUM_AGC
 		Receiver gain control mode
	lManualRxGaindB
		Range:		[0..35840]
		Default:	cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_USE_DEFAULT
 		The receiver gain is used only in cOCTVC1_RUS_WNM_RXMODE_MGC
 		From 0 dB to 70.0 dB with a resolution of 1 dB (Q9 representation)
	SelectiveSibDecoding
 		Activate/Configure Selective sib decoding
	ulUserEventId
		Default:	0
 		User defined event identifier. This identifier is returned in the event's
 		header.
	ubyEventCellStatsEnableFlag
		Default:	0
 		Enable cell statistics events (disabled by default)
	ubyEventSearchStatsRate
		Range:		[0..255]
		Default:	0
 		Enable Search statistics events with associated event rate
 		From 0.1 : 0.1 : 25.5 sec; 0 = event disabled
	usReserved0
		Default:	0
 		Reserved
	ulReserved0
		Default:	0
 		Reserved
	ulReserved1
		Default:	0
 		Reserved
	aEntryList
 		List of carrier parameters
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32								ulEntryCount;
	tOCTVC1_RUS_WNM_SEARCH_MODE_ENUM		ulSearchMode;
	tOCTVC1_RUS_WNM_RXMODE_ENUM				ulRxGainControlMode;
	tOCT_INT32								lManualRxGaindB;
	tOCTVC1_RUS_WNM_SELECTIVE_SIB_DECODING	SelectiveSibDecoding;
	tOCT_UINT32								ulUserEventId;
	tOCT_UINT8								ubyEventCellStatsEnableFlag;
	tOCT_UINT8								ubyEventSearchStatsRate;
	tOCT_UINT16								usReserved0;
	tOCT_UINT32								ulReserved0;
	tOCT_UINT32								ulReserved1;
	tOCTVC1_RUS_WNM_SEARCH_ENTRY			aEntryList[cOCTVC1_RUS_WNM_SEARCH_MAX_ENTRY];

} tOCTVC1_RUS_WNM_SEARCH_PARMS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_SEARCH_STATS

 Members:
	ulState
	CurrentEntry
 		Parameters of the current carrier scanned
	ulCurrentEntryIndex
 		Index on the current entry
	ulCurrentUarfcn
 		Current monitored Uarfcn
	ulNumBandToScan
 		Number of bands to scan
	ulNumBandScanned
 		Number of bands than has been scanned
	ul2GBaseStationCnt
 		Summary on the number of GSM base station found
	ulCDMA2000BaseStationCnt
 		Summary on the number of CDMA2000 base station found
	ul3GBaseStationCnt
 		Summary on the number of UMTS base station found
	ul4GBaseStationCnt
 		Summary on the number of LTE base station found
	ul5GBaseStationCnt
 		Summary on the number of NR base station found
	ulRssiBandCnt
 		Summary on the number of band scanned in RSSI only mode
	ulSearcherDiagnosticCode
 		Diagnosic: Provided additionnal information when the searcher state provided an
 		'ABORT_ERROR'
	ulRxGainControlMode
		Default:	cOCTVC1_RUS_WNM_RXMODE_ENUM_AGC
 		Receiver gain control mode
	lManualRxGaindB
		Range:		[0..35840]
		Default:	cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_USE_DEFAULT
 		The receiver gain is used only in cOCTVC1_RUS_WNM_RXMODE_MGC
 		From 0 dB to 70.0 dB with a resolution of 1 dB (Q9 representation)
	ulReserved0
 		reserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RUS_WNM_SEARCH_STATE_ENUM	ulState;
	tOCTVC1_RUS_WNM_SEARCH_ENTRY		CurrentEntry;
	tOCT_UINT32							ulCurrentEntryIndex;
	tOCT_UINT32							ulCurrentUarfcn;
	tOCT_UINT32							ulNumBandToScan;
	tOCT_UINT32							ulNumBandScanned;
	tOCT_UINT32							ul2GBaseStationCnt;
	tOCT_UINT32							ulCDMA2000BaseStationCnt;
	tOCT_UINT32							ul3GBaseStationCnt;
	tOCT_UINT32							ul4GBaseStationCnt;
	tOCT_UINT32							ul5GBaseStationCnt;
	tOCT_UINT32							ulRssiBandCnt;
	tOCTVC1_RUS_WNM_SEARCH_DIAG_ENUM	ulSearcherDiagnosticCode;
	tOCTVC1_RUS_WNM_RXMODE_ENUM			ulRxGainControlMode;
	tOCT_INT32							lManualRxGaindB;
	tOCT_UINT32							ulReserved0;

} tOCTVC1_RUS_WNM_SEARCH_STATS;

/*-------------------------------------------------------------------------------------
 	WNM GSM decoder definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM				tOCT_UINT16

#define cOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM_SUCCESSFUL	0		
#define cOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM_IM_OUTOFSYNC	1		
#define cOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM_OM_TIMEOUT	2		
#define cOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM_OM_OUTOFSYNC	3		
#define cOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM_THR_FILTERED	4		 	/* Cell filtered based on the SNR threshold. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_GSM_CELL_STATS

 Members:
	ulWaveForm
	ulBand
	ulArfcn
 		Arfcn carrier frequency specified according the waveform and the band.
	ulFrequency
 		Carrier frequency specified according the waveform and the band (Hz).
	lRssidBm
 		Receiver Signal Strength Indicator. (Q9 representation)
 		Default -81920 (-160.0 dBm)
	lSNRdB
 		Signal to Noise Ratio (Q9 representation)
 		Default 0 dB
	lTimeAdvance
		Range:		[-64..32]
 		Timing advance (in samples)
	NCC
 		Part of the Base Station Identity Code (BSIC)
 		Network Color Code (range 0-7)
	BCC
 		Part of the Base Station Identity Code (BSIC)
 		Base station Color Code (range 0-7)
	ulDecoderDiagnosticCode
 		Diagnosic: Provided information on the decoder
	usBcchPayloadBlockCnt
 		Number of block in the Bcch payload file
	usBcchPayloadValidBlockCnt
 		Number of valid block in the Bcch payload file (Crc pass)
	ulFoundSIsMask
 		Mask reflecting all System Informations found during the bch decoding
	szBcchPayloadFileName
 		BCCH payload filename
	ulReserved
 		Internal used
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM					ulWaveForm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM	ulBand;
	tOCT_UINT32									ulArfcn;
	tOCT_UINT32									ulFrequency;
	tOCT_INT32									lRssidBm;
	tOCT_INT32									lSNRdB;
	tOCT_INT32									lTimeAdvance;
	tOCT_UINT8									NCC;
	tOCT_UINT8									BCC;
	tOCTVC1_RUS_WNM_GSM_DECODER_DIAG_ENUM		ulDecoderDiagnosticCode;
	tOCT_UINT16									usBcchPayloadBlockCnt;
	tOCT_UINT16									usBcchPayloadValidBlockCnt;
	tOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK		ulFoundSIsMask;
	tOCT_INT8									szBcchPayloadFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32									ulReserved;

} tOCTVC1_RUS_WNM_GSM_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_GSM_BCCH_TB

 Members:
	ulSFN
 		System frame number associated to the payload
	usCrc
 		Crc indicator on the current payload
	usNumBits
 		Number of valid bits in the payload
	abPayload
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulSFN;
	tOCT_UINT16	usCrc;
	tOCT_UINT16	usNumBits;
	tOCT_INT8	abPayload[cOCTVC1_RUS_WNM_GSM_BCCH_TB_PAYLOAD_CNT];

} tOCTVC1_RUS_WNM_GSM_BCCH_TB;

/*-------------------------------------------------------------------------------------
 	WNM CDMA2000 decoder definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM				tOCT_UINT16

#define cOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM_SUCCESSFUL		0		
#define cOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM_IM_TIMEOUT		1		
#define cOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM_IM_OUTOFSYNC		2		
#define cOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM_OM_TIMEOUT		3		
#define cOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM_OM_OUTOFSYNC		4		
#define cOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM_THR_FILTERED		5		 	/* Cell filtered based on the SNR threshold. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_CDMA2000_FSYNC_MSG

 Members:
	byP_REV
 		Protocol revision level currently in use by the base station
 		The base station shall set this field to 00001100
 		Encoding: 8 bits
	byMIN_P_REV
 		Minimum protocol revision level supported by the base station
 		Encoding: 8 bits
	byLP_SEC
		Range:		[0..255]
 		Number of leap 1 seconds that have occurred since the start of System Time
 		Encoding: 8 bits
	byLMT_OFF
		Range:		[0..63]
 		Offset of local time from System Time
	byDAYLT
		Range:		[0..1]
 		Daylight savings time indicator
 		Encoding: 1 bits
	byPRAT
		Range:		[0..3]
 		Paging Channel Data Rate
 		Encoding: 2 bits
 		00 9600 bps
 		01 4800 bps
 		10 Reserved
 		11 Reserved
	bySR1_BCCH_NON_TD_INCL
		Range:		[0..1]
 		Common Channel in non TD mode on Spreading Rate 1 information included indicator
 		Encoding: 1 bits
	bySR1_NON_TD_FREQ_INCL
		Range:		[0..1]
 		SR1: Non Transmit Diversity frequency included indicator
 		Dynamic encoding: 0 or 1 bits
 		See 3.7.2.3.2.26 Sync Channel Message
	bySR1_BRAT_NON_TD
		Range:		[0..3]
 		BCCH data rate in non-TD mode for Spreading Rate 1
 		Dynamic encoding: 0 or 2 bits
 		00 4800bps
 		01 9600 bps
 		10 19200
 		11 Reserved
	bySR1_CRAT_NON_TD
		Range:		[0..1]
 		BCCH code rate in non Transmit Diversity mode for Spreading Rate 1
 		Dynamic encoding: 0 or 1 bits
	bySR1_BCCH_CODE_CHAN_NON_TD
		Range:		[0..63]
 		Walsh code for the Spreading Rate 1 BCCH in Transmit Diversity mode.
 		Dynamic encoding: 0 or 6 bits
	bySR1_TD_INCL
		Range:		[0..1]
 		Spreading Rate 1 Transmit Diversity Mode
	bySR1_BRAT_TD
		Range:		[0..3]
 		BCCH data rate in Transmit Diversity 1 mode for Spreading Rate 1.
 		Dynamic encoding: 0 or 2 bits
	bySR1_CRAT_TD
		Range:		[0..1]
 		BCCH code rate in Transmit Diversity mode for Spreading Rate 1
 		Dynamic encoding: 0 or 1 bits
	bySR1_BCCH_CODE_CHAN_TD
		Range:		[0..63]
 		Walsh code for the Spreading Rate 1 BCCH in Transmit Diversity mode
 		Dynamic encoding: 0 or 6 bits
	bySR1_TD_MODE
		Range:		[0..3]
 		Spreading Rate 1 Transmit Diversity Mode.
 		00 OTD (Orthogonal Transmit Diversity) mode
 		01 STS (Space Time Spreading) mode
 		10-11 Reserved
 		Dynamic encoding: 0 or 2 bits
	bySR1_TD_POWER_LEVEL
		Range:		[0..3]
 		Spreading Rate 1 TD transmit power level
 		Dynamic encoding: 0 or 2 bits
	bySR3_INCL
		Range:		[0..1]
 		Spreading Rate 3 information included indicator
	bySR3_CENTER_FREQ_INCL
		Range:		[0..1]
 		Center SR3 frequency assignment included
 		Dynamic encoding: 0 or 1 bits
	bySR3_BCCH_CODE_CHAN
		Range:		[0..127]
 		Spreading Rate 3 BCCH Walsh code
 		Dynamic encoding: 0 or 7 bits
	bySR3_PRIMARY_PILOT
		Range:		[0..3]
 		Primary SR3 pilot
 		Dynamic encoding: 0 or 2 bits
	bySR3_PILOT_POWER1
		Range:		[0..7]
 		The primary SR3 pilot power level relative to that of the pilot
 		on the lower frequency of the two remaining SR3 frequencies
 		Dynamic encoding: 0 or 3 bits
	bySR3_PILOT_POWER2
		Range:		[0..7]
 		The primary SR3 pilot power level relative to that of the pilot
 		on the higher frequency of the two remaining SR3 frequencies
 		Dynamic encoding: 0 or 3 bits
	byDS_INCL
		Range:		[0..1]
 		Direct Spread (DS) System and Information Available
	usSID
		Range:		[0..32767]
 		System Identifier
 		Encoding: 15 bits
	usNID
		Range:		[0..65535]
 		Network Identifier
 		Encoding: 16 bits
	usPILOT_PN
		Range:		[0..511]
 		Pilot PN sequence offset index
 		Encoding: 9 bits
	usCDMA_FREQ
		Range:		[0..2047]
 		CDMA Frequency assignment
 		Encoding: 11 bits
	usEXT_CDMA_FREQ
		Range:		[0..2047]
 		CDMA Extended frequency assignment
 		Encoding: 11 bits
	usSR1_CDMA_FREQ_NON_TD
		Range:		[0..2047]
 		Frequency assignment for non-transmit diversityoperation
 		Dynamic encoding: 0 or 11 bits
	usSR1_CDMA_FREQ_TD
		Range:		[0..2047]
 		Spreading Rate 1 frequency assignment for Transmit Diversity operation
 		Dynamic encoding: 0 or 11 bits
	usSR3_CENTER_FREQ
		Range:		[0..2047]
 		Center SR3 frequency assignment
 		Dynamic encoding: 0 or 11 bits
	bySR3_BRAT
		Range:		[0..3]
 		Spreading Rate 3 BCCH data rate
 		Dynamic encoding: 0 or 2 bits
	usReserved0
 		future use
	usLC_STATE_HI
		Range:		[0..1024]
 		Long code state.
 		Higher part: 9:0
 		Encoding: 42 bits
	usReserved1
 		future use
	ulLC_STATE_LO
		Range:		[0..4294967295]
 		Long code state
 		Lower part: 31:0
 		Encoding: 42 bits
	usSYS_TIME_HI
		Range:		[0..15]
 		System Time. Unit is 80 ms
 		Higher part: 3:0
 		Encoding: 36 bits
	usReserved2
 		future use
	ulSYS_TIME_LO
		Range:		[0..4294967295]
 		System Time. Unit is 80 ms
 		Lower part: 31:0
 		Encoding: 36 bits
	ulDS_BLOB
		Range:		[0..16777216]
 		Access Information about a Direct Spread (DS) System
 		Dynamic encoding: 0 or 24 bits
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT8	byP_REV;
	tOCT_UINT8	byMIN_P_REV;
	tOCT_UINT8	byLP_SEC;
	tOCT_UINT8	byLMT_OFF;
	tOCT_UINT8	byDAYLT;
	tOCT_UINT8	byPRAT;
	tOCT_UINT8	bySR1_BCCH_NON_TD_INCL;
	tOCT_UINT8	bySR1_NON_TD_FREQ_INCL;
	tOCT_UINT8	bySR1_BRAT_NON_TD;
	tOCT_UINT8	bySR1_CRAT_NON_TD;
	tOCT_UINT8	bySR1_BCCH_CODE_CHAN_NON_TD;
	tOCT_UINT8	bySR1_TD_INCL;
	tOCT_UINT8	bySR1_BRAT_TD;
	tOCT_UINT8	bySR1_CRAT_TD;
	tOCT_UINT8	bySR1_BCCH_CODE_CHAN_TD;
	tOCT_UINT8	bySR1_TD_MODE;
	tOCT_UINT8	bySR1_TD_POWER_LEVEL;
	tOCT_UINT8	bySR3_INCL;
	tOCT_UINT8	bySR3_CENTER_FREQ_INCL;
	tOCT_UINT8	bySR3_BCCH_CODE_CHAN;
	tOCT_UINT8	bySR3_PRIMARY_PILOT;
	tOCT_UINT8	bySR3_PILOT_POWER1;
	tOCT_UINT8	bySR3_PILOT_POWER2;
	tOCT_UINT8	byDS_INCL;
	tOCT_UINT16	usSID;
	tOCT_UINT16	usNID;
	tOCT_UINT16	usPILOT_PN;
	tOCT_UINT16	usCDMA_FREQ;
	tOCT_UINT16	usEXT_CDMA_FREQ;
	tOCT_UINT16	usSR1_CDMA_FREQ_NON_TD;
	tOCT_UINT16	usSR1_CDMA_FREQ_TD;
	tOCT_UINT16	usSR3_CENTER_FREQ;
	tOCT_UINT16	bySR3_BRAT;
	tOCT_UINT16	usReserved0;
	tOCT_UINT16	usLC_STATE_HI;
	tOCT_UINT16	usReserved1;
	tOCT_UINT32	ulLC_STATE_LO;
	tOCT_UINT16	usSYS_TIME_HI;
	tOCT_UINT16	usReserved2;
	tOCT_UINT32	ulSYS_TIME_LO;
	tOCT_UINT32	ulDS_BLOB;

} tOCTVC1_RUS_WNM_CDMA2000_FSYNC_MSG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_CDMA2000_CELL_STATS

 Members:
	ulWaveForm
	ulBand
	ulRfcn
 		Rfcn carrier frequency specified according the waveform and the band.
	ulFrequency
 		Carrier frequency specified according the waveform and the band (Hz).
	lRssidBm
 		Receiver Signal Strength Indicator. (Q9 representation)
 		Default -81920 (-160.0 dBm)
	lRscpdBm
 		The scrambling code power of the F-SYNC. (Q9 representation)
 		Default: -81920 (-160.0 dBm)
	lEcI0dB
		Default:	-81920
 		Ec/Io in dBm (Q9 representation)
	FSyncMessage
 		F-SYNC channel message. C.S0005 - 3.7.2.3.2.26
	lRelativeDelayChip
 		Relative delay, in chips, of the primary path of the F-PICH.
	ulDecoderDiagnosticCode
 		Diagnosic: Provided information on the decoder
	usSIPayloadBlockCnt
 		Number of SI block in the payload file
	usSIPayloadValidBlockCnt
 		Number of valid SI block in the payload file (Crc pass)
	ulFoundSibsMask
 		Return all the sibs found in the channel during the decoding
	szSIPayloadFileName
 		SI payload filename
	ulReserved
 		Internal used
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM						ulWaveForm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM	ulBand;
	tOCT_UINT32										ulRfcn;
	tOCT_UINT32										ulFrequency;
	tOCT_INT32										lRssidBm;
	tOCT_INT32										lRscpdBm;
	tOCT_INT32										lEcI0dB;
	tOCTVC1_RUS_WNM_CDMA2000_FSYNC_MSG				FSyncMessage;
	tOCT_INT32										lRelativeDelayChip;
	tOCTVC1_RUS_WNM_CDMA2000_DECODER_DIAG_ENUM		ulDecoderDiagnosticCode;
	tOCT_UINT16										usSIPayloadBlockCnt;
	tOCT_UINT16										usSIPayloadValidBlockCnt;
	tOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK		ulFoundSibsMask;
	tOCT_INT8										szSIPayloadFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32										ulReserved;

} tOCTVC1_RUS_WNM_CDMA2000_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_CDMA2000_SI_TB

 Members:
	usCrc
 		Crc indicator on the current payload
	usNumBits
 		Number of valid bits in the payload
	usSFN
 		System frame number associated to the payload
	usReserved
	abPayload
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usCrc;
	tOCT_UINT16	usNumBits;
	tOCT_UINT16	usSFN;
	tOCT_UINT16	usReserved;
	tOCT_INT8	abPayload[cOCTVC1_RUS_WNM_CDMA2000_SI_TB_PAYLOAD_CNT];

} tOCTVC1_RUS_WNM_CDMA2000_SI_TB;

/*-------------------------------------------------------------------------------------
 	WNM UMTS decoder definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM				tOCT_UINT16

#define cOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM_SUCCESSFUL		0		
#define cOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM_IM_TIMEOUT		1		
#define cOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM_IM_OUTOFSYNC		2		
#define cOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM_OM_TIMEOUT		3		
#define cOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM_OM_OUTOFSYNC		4		
#define cOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM_THR_FILTERED		5		 	/* Cell filtered based on the lRSPTHreshold or lSQThreshold. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_UMTS_CELL_STATS

 Members:
	ulWaveForm
	ulBand
	ulUarfcn
 		Uarfcn carrier frequency specified according the waveform and the band.
	ulFrequency
 		Carrier frequency specified according the waveform and the band (Hz).
	lRssidBm
 		Receiver Signal Strength Indicator. (Q9 representation)
 		Default -81920 (-160.0 dBm)
	lRscpdBm
 		The scrambling code power of the CPICH. (Q9 representation)
 		Default: -81920 (-160.0 dBm)
	lEcI0dB
		Default:	-81920
 		Ec/Io in dBm (Q9 representation)
	lRelativeDelayChip
 		Relative delay, in chips, of the primary path of the CPICH.
	usPsc
 		0 .. 511
 		Primary scrambling code.
	ulDecoderDiagnosticCode
 		Diagnosic: Provided information on the decoder
	usBchPayloadBlockCnt
 		Number of block in the Bch payload file
	usBchPayloadValidBlockCnt
 		Number of valid block in the Bch payload file (Crc pass)
	ulFoundSibsMask
 		Return all the sibs found in the channel during the decoding
	szBchPayloadFileName
 		BCH payload filename
	ulReserved
 		Internal used
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM					ulWaveForm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM	ulBand;
	tOCT_UINT32									ulUarfcn;
	tOCT_UINT32									ulFrequency;
	tOCT_INT32									lRssidBm;
	tOCT_INT32									lRscpdBm;
	tOCT_INT32									lEcI0dB;
	tOCT_INT32									lRelativeDelayChip;
	tOCT_UINT16									usPsc;
	tOCTVC1_RUS_WNM_UMTS_DECODER_DIAG_ENUM		ulDecoderDiagnosticCode;
	tOCT_UINT16									usBchPayloadBlockCnt;
	tOCT_UINT16									usBchPayloadValidBlockCnt;
	tOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK		ulFoundSibsMask;
	tOCT_INT8									szBchPayloadFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32									ulReserved;

} tOCTVC1_RUS_WNM_UMTS_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_UMTS_BCH_TB

 Members:
	usCrc
 		Crc indicator on the current payload
	usSFN
 		System frame number associated to the payload
	usNumBits
 		Number of valid bits in the payload
	usReserved
	abPayload
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usCrc;
	tOCT_UINT16	usSFN;
	tOCT_UINT16	usNumBits;
	tOCT_UINT16	usReserved;
	tOCT_INT8	abPayload[cOCTVC1_RUS_WNM_UMTS_BCH_TB_PAYLOAD_CNT];

} tOCTVC1_RUS_WNM_UMTS_BCH_TB;

/*-------------------------------------------------------------------------------------
 	WNM LTE decoder definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_MODE_ENUM : 	LTE mode FTT/TDD
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_LTE_MODE_ENUM						tOCT_UINT8

#define cOCTVC1_RUS_WNM_LTE_MODE_ENUM_FDD					0		
#define cOCTVC1_RUS_WNM_LTE_MODE_ENUM_TDD					1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_PHICH_DURATION_ENUM : 	Describes the PHICH duration in the detected cell
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_LTE_PHICH_DURATION_ENUM				tOCT_UINT8

#define cOCTVC1_RUS_WNM_LTE_PHICH_DURATION_ENUM_NORMAL		0		
#define cOCTVC1_RUS_WNM_LTE_PHICH_DURATION_ENUM_EXTENDED	1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM : 	Describes the PHICH Group Configuration in the detected cell
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM				tOCT_UINT8

#define cOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM_ONESIXTH		0		
#define cOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM_HALF			1		
#define cOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM_ONE			2		
#define cOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM_TWO			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_CP_ENUM : 	Detected Cyclic Prefix of the Cell
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_LTE_CP_ENUM							tOCT_UINT8

#define cOCTVC1_RUS_WNM_LTE_CP_ENUM_INVALID					0		
#define cOCTVC1_RUS_WNM_LTE_CP_ENUM_NORMAL					1		
#define cOCTVC1_RUS_WNM_LTE_CP_ENUM_EXTENDED				2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM : 	Detected number of antenna Ports of the cell
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM				tOCT_UINT8

#define cOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM_INVALID		0		
#define cOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM_ONE			1		
#define cOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM_TWO			2		
#define cOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM_FOUR			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM						tOCT_UINT16

#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_SUCCESSFUL				0		
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_IM_TIMEOUT				1		 	/* Inner modem never synchronized */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_IM_OUTOFSYNC				2		 	/* Inner modem become out of sync */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_OM_TIMEOUT				3		 	/* Decoder never decod transport blocks */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_OM_OUTOFSYNC				4		 	/* Decoder provide toomuch of CRC failure */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_FORMAT_NOT_SUPPORTED		5		 	/* Decoder format limitation */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_OMS0_REALTIME_FAILURE		6		 	/* Misc decoder realtime failure */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_OMS1_REALTIME_FAILURE		7		 	/* Misc decoder realtime failure */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_IMS0_REALTIME_FAILURE		8		 	/* Misc decoder realtime failure */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_IMS1_REALTIME_FAILURE		9		 	/* Misc decoder realtime failure */
#define cOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM_THR_FILTERED				10		 	/* Cell filtered based on the lRSPTHreshold or lSQThreshold. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_CELL_STATS

 Members:
	ulWaveForm
	ulBand
 		Waveform.
	ulBandWidth
 		Waveform bandwith.
	ulEarfcn
 		Earfcn carrier frequency specified according the waveform and the band.
	ulFrequency
 		Carrier frequency specified according the waveform and the band (Hz).
	byWaveFormMode
 		Waveform FDD or TDD
	byPhichDuration
 		Describes the PHICH duration in the detected cell
	byPhichGroup
 		Describes the PHICH Group Configuration in the detected cell
	byCyclicPrefix
 		Detected Cyclic Prefix of the Cell
	usCellIdentity
 		Physical Cell Identity of the Detected Cell
 		Range: 0:511
	byNumTxAntennaPorts
 		Detected number of antenna Ports of the cell
	byReserved
 		reserved
	lRssidBm
 		Receiver Signal Strength Indicator. (Q9 representation)
 		Default -81920 (-160.0 dBm)
	lRsrpdBm
 		Describes the RSRP (Reference Signal Reference Power). (Q9 representation)
 		Default: -81920 (-160.0 dBm)
	lRsrqdB
 		Describes the RSRQ (Reference Signal Received Quality). (Q9 representation)
 		Default: -81920 (-160.0 dB)
	lRelativeD
 		Describes the time differential between the beginning of the LTE frame and each
 		second of GPS time
 		Time resolution is 32.552083 ns. This corresponds to a period of the sampling
 		rate 30.720MHz
 		If the PPS source clock is not accurate, value of lRelativeD becomes 0xFFFFFFFF
 		Range: 0 to 307199 (10 msec)
	usRelativeSFN
 		Describes the System Frame Number nearest the PPS's edge (i.e. GPS time)
 		If the PPS source clock is not accurate, value of usRelativeSFN becomes 0xFFFF
 		Range: 0 to 1023
	usReserved
 		Reserved
	usBchPayloadBlockCnt
 		Number of block in the Bch payload file
	usBchPayloadValidBlockCnt
 		Number of valid block in the Bch payload file (Crc pass)
	ulDecoderDiagnosticCode
 		Diagnosic: Provided information on the decoder
	byTddUlDlConfig
 		TDD Uplink-Downlink configuration (0 to 6). Set to 255 if not defined.
 		Note: This field is only decoded when the search mode is
 		cOCTVC1_RUS_WNM_SEARCH_MODE_ENUM_EXHAUSTIVE
	byTddSpecialSF
 		TDD Uplink-Downlink configuration of special subframe (0 to 9). Set to 0 if not
 		defined.
 		Note: This field is only decoded when the search mode is
 		cOCTVC1_RUS_WNM_SEARCH_MODE_ENUM_EXHAUSTIVE
	ulFoundSibsMask
 		Return all the sibs found in the channel during the decoding
	szBchPayloadFileName
 		BCH payload filename
	ulReserved
 		Internal used
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM					ulWaveForm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM	ulBand;
	tOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM		ulBandWidth;
	tOCT_UINT32									ulEarfcn;
	tOCT_UINT32									ulFrequency;
	tOCTVC1_RUS_WNM_LTE_MODE_ENUM				byWaveFormMode;
	tOCTVC1_RUS_WNM_LTE_PHICH_DURATION_ENUM		byPhichDuration;
	tOCTVC1_RUS_WNM_LTE_PHICH_GROUP_ENUM		byPhichGroup;
	tOCTVC1_RUS_WNM_LTE_CP_ENUM					byCyclicPrefix;
	tOCT_UINT16									usCellIdentity;
	tOCTVC1_RUS_WNM_LTE_NUM_ANTENNA_ENUM		byNumTxAntennaPorts;
	tOCT_UINT8									byReserved;
	tOCT_INT32									lRssidBm;
	tOCT_INT32									lRsrpdBm;
	tOCT_INT32									lRsrqdB;
	tOCT_INT32									lRelativeD;
	tOCT_UINT16									usRelativeSFN;
	tOCT_UINT16									usReserved;
	tOCT_UINT16									usBchPayloadBlockCnt;
	tOCT_UINT16									usBchPayloadValidBlockCnt;
	tOCTVC1_RUS_WNM_LTE_DECODER_DIAG_ENUM		ulDecoderDiagnosticCode;
	tOCT_UINT8									byTddUlDlConfig;
	tOCT_UINT8									byTddSpecialSF;
	tOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK		ulFoundSibsMask;
	tOCT_INT8									szBchPayloadFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32									ulReserved;

} tOCTVC1_RUS_WNM_LTE_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_LTE_BCH_TB

 Members:
	usCrc
 		Crc indicator on the current payload
	usSFN
		Range:		[0..1023]
 		System frame number associated to the payload
	usNumBits
 		Number of valid bits in the payload
	ubySubFrameNumber
		Range:		[0..9]
 		Subframe Number associated to the payload
	byReserved
	abPayload
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usCrc;
	tOCT_UINT16	usSFN;
	tOCT_UINT16	usNumBits;
	tOCT_UINT8	ubySubFrameNumber;
	tOCT_UINT8	byReserved;
	tOCT_INT8	abPayload[cOCTVC1_RUS_WNM_LTE_BCH_TB_PAYLOAD_CNT];

} tOCTVC1_RUS_WNM_LTE_BCH_TB;

/*-------------------------------------------------------------------------------------
 	WNM NR decoder definition
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_WNM_NR_MAX_NUM_SSB						8		 	/* Max number of detected Beam. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_CP_ENUM : 	Detected Cyclic Prefix of the Cell
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_NR_CP_ENUM							tOCT_UINT8

#define cOCTVC1_RUS_WNM_NR_CP_ENUM_INVALID					0		
#define cOCTVC1_RUS_WNM_NR_CP_ENUM_NORMAL					1		
#define cOCTVC1_RUS_WNM_NR_CP_ENUM_EXTENDED					2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_DECODER_DIAG_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_WNM_NR_DECODER_DIAG_ENUM				tOCT_UINT16

#define cOCTVC1_RUS_WNM_NR_DECODER_DIAG_ENUM_SUCCESSFUL		0		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_MIB_INFO

 Members:
	ulSFN
 		Synchronization Signal Bloc's system Frame Number (0:1023)
	ulCellBarredFlag
 		Cell barred indicator
	ulIntraFreqReselectionFlag
 		Controls cell selection/reselection to intra-frequency cells
	ulSubcarrierSpacingCommon
 		Indicates the Subcarrier spacing for SIB1 Msg.2/4 for initial access and
 		SI-messages.
 		Values 15 and 30 kHz are applicable for carrier frequencies lower than 6GHz;
 		Values 60 and 120
 		kHz are applicable for carrier frequencies > 6GHz
	usSubcarrierOffsetRB
 		Synchronization Signal Block's ssb-SubcarrierOffset (Kssb) in RB
 		Indicates the frequency domain offset between SSB and the overall
 		resource block grid in number of subcarriers
	byDMRS_typeA_pos
 		PDCCH DMRS position (pos2, pos3). Indicates Position of (first) DL DM-RS
	byPDCCHConfigSIB1
 		Determines a bandwidth for PDCCH/SIB, a common ControlResourceSet (CORESET),
 		a common search space and necessary PDCCH parameters (0:255)
	abyRawPayload
 		Raw MIB payload
	ulReserved
 		Reserved for internal use
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulSFN;
	tOCT_BOOL32							ulCellBarredFlag;
	tOCT_BOOL32							ulIntraFreqReselectionFlag;
	tOCTVC1_RADIO_STANDARD_NR_SCS_ENUM	ulSubcarrierSpacingCommon;
	tOCT_UINT16							usSubcarrierOffsetRB;
	tOCT_UINT8							byDMRS_typeA_pos;
	tOCT_UINT8							byPDCCHConfigSIB1;
	tOCT_UINT8							abyRawPayload[4];
	tOCT_UINT32							ulReserved;

} tOCTVC1_RUS_WNM_NR_MIB_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_SSB_MEAS

 Members:
	lRssidBm
 		Describes the SS-RSSI Power. (Q9 representation)
 		Default: -81920 (-160.0 dBm)
	lRsrpdBm
 		Describes the SS-RSRP Power. (Q9 representation)
 		Default: -81920 (-160.0 dBm)
	sRsrqdB
 		Describes the SS-RSRQ (Received Quality). (Q9 representation)
 		Default: -12800 (-25.0 dB)
	sSinrdB
 		Describes the Synchronization Signal Signal-to-Noise and Interference Ratio.
 		(Q9 representation)
 		Default: -12800 (-25.0 dB)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT32	lRssidBm;
	tOCT_INT32	lRsrpdBm;
	tOCT_INT16	sRsrqdB;
	tOCT_INT16	sSinrdB;

} tOCTVC1_RUS_WNM_NR_SSB_MEAS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_SSB_INFO

 Members:
	eSSBPattern
		Default:	cOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_INVALID
 		SSB Bitmap. Depends on the NR Band and define the SSB burst configuration
 		(A,B,C,D)
	ulSSBPosInBurstMask
 		Mask indicating which SSBs are transmitted and which are not transmitted.
	atBeamMeas
 		Measurements for each of the Beam detected (SS-RSSI, SS-RSRP, SS-RSRQ, SS-SINR).
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM	eSSBPattern;
	tOCT_UINT32									ulSSBPosInBurstMask[2];
	tOCTVC1_RUS_WNM_NR_SSB_MEAS					atBeamMeas[cOCTVC1_RUS_WNM_NR_MAX_NUM_SSB];

} tOCTVC1_RUS_WNM_NR_SSB_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_CELL_STATS

 Members:
	ulWaveForm
	ulBand
 		Waveform.
	ulDuplexingMode
 		Waveform FDD or TDD
	ulNrArfcn
 		NR-ARFCN carrier frequency specified according to the band.
 		Range: 0:2084999
	ulNrArfcnFrequencyKHz
 		GSCN synchronization raster frequency (KHz).
 		Range: 0:6000000 KHz
	usPCI
 		Physical Cell Identity of the Detected Cell
 		Range: 0:1007
	byCyclicPrefix
 		Detected Cyclic Prefix of the Cell
	byReserved0
 		Reserved for future use
	ulNumerology
		Default:	cOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_15KHz
 		Subcarrier Spacing
	lFreqOffsetHz
 		Mesure frequency imperfection in Hz (debug only)
	lRelativeD
 		Describes the time differential between the beginning of the NR frame and each
 		second of GPS time
 		Time resolution is 32.552083 ns. This corresponds to a period of the sampling
 		rate 30.720MHz
 		If the PPS source clock is not accurate, value of lRelativeD becomes 0xFFFFFFFF
 		Range: 0 to 307199 (10 msec)
	tMibInfo
 		Master Block Information
	tSSBInfo
 		SSB informations
	usBchPayloadBlockCnt
 		Number of block in the Bch payload file
	usBchPayloadValidBlockCnt
 		Number of valid block in the Bch payload file (Crc pass)
	ulAvailableSibsMask
 		Indicates all sibs listed in the SIB1
	ulBroadcastedSibsMask
 		Indicates all broadcasted sibs listed in the SIB1
	ulFoundSibsMask
 		Indicates all the decoded sibs in the payload file
	ulDecoderDiagnosticCode
 		Diagnosic: Provided information on the decoder
	szBchPayloadFileName
 		BCH payload filename
	ulReserved1
 		Internal used
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM					ulWaveForm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM	ulBand;
	tOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM		ulDuplexingMode;
	tOCT_UINT32									ulNrArfcn;
	tOCT_UINT32									ulNrArfcnFrequencyKHz;
	tOCT_UINT16									usPCI;
	tOCTVC1_RUS_WNM_NR_CP_ENUM					byCyclicPrefix;
	tOCT_UINT8									byReserved0;
	tOCTVC1_RADIO_STANDARD_NR_SCS_ENUM			ulNumerology;
	tOCT_INT32									lFreqOffsetHz;
	tOCT_INT32									lRelativeD;
	tOCTVC1_RUS_WNM_NR_MIB_INFO					tMibInfo;
	tOCTVC1_RUS_WNM_NR_SSB_INFO					tSSBInfo;
	tOCT_UINT16									usBchPayloadBlockCnt;
	tOCT_UINT16									usBchPayloadValidBlockCnt;
	tOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK		ulAvailableSibsMask;
	tOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK		ulBroadcastedSibsMask;
	tOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK		ulFoundSibsMask;
	tOCTVC1_RUS_WNM_NR_DECODER_DIAG_ENUM		ulDecoderDiagnosticCode;
	tOCT_INT8									szBchPayloadFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32									ulReserved1;

} tOCTVC1_RUS_WNM_NR_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_NR_BCH_TB

 Members:
	usCrc
 		Crc indicator on the current payload
	usSFN
		Range:		[0..1023]
 		System frame number associated to the payload
	usNumBits
 		Number of valid bits in the payload
	bySubFrameNumber
		Range:		[0..9]
 		Subframe Number associated to the payload
	byReserved
	abyPayload
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usCrc;
	tOCT_UINT16	usSFN;
	tOCT_UINT16	usNumBits;
	tOCT_UINT8	bySubFrameNumber;
	tOCT_UINT8	byReserved;
	tOCT_INT8	abyPayload[cOCTVC1_RUS_WNM_NR_BCH_TB_PAYLOAD_CNT];

} tOCTVC1_RUS_WNM_NR_BCH_TB;

/*-------------------------------------------------------------------------------------
 	WNM FAST RSSI definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_RSSI_BAND_STATS

 Members:
	BandId
	ulNumRssiChannel
 		Number of channels for this band for which the RSSI value has been calculated.
	ulReserved
 		Reserved.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID	BandId;
	tOCT_UINT32							ulNumRssiChannel;
	tOCT_UINT32							ulReserved;

} tOCTVC1_RUS_WNM_RSSI_BAND_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_RSSI_BAND_CURSOR

 Members:
	hWnm
 		Unique WNM identifier.
	BandId
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		cOCTVC1_OBJECT_CURSOR_ENUM_FIRST: get the first band of all waveforms.
 		cOCTVC1_OBJECT_CURSOR_ENUM_NEXT: get the next band in all waveforms.
 		cOCTVC1_OBJECT_CURSOR_ENUM_SUB_OBJECT_FIRST: get the first band of specified
 		waveform.
 		cOCTVC1_OBJECT_CURSOR_ENUM_SUB_OBJECT_NEXT: get the next band of specified
 		waveform.
 		cOCTVC1_OBJECT_CURSOR_ENUM_SPECIFIC: get a specific band.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT				hWnm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID	BandId;
	tOCTVC1_OBJECT_CURSOR_ENUM			ulGetMode;

} tOCTVC1_RUS_WNM_RSSI_BAND_CURSOR;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_RSSI_BAND_CHANNEL_CURSOR

 Members:
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		cOCTVC1_OBJECT_CURSOR_ENUM_FIRST: get the first channel list of the band.
 		cOCTVC1_OBJECT_CURSOR_ENUM_NEXT: get the next channel list of the band.
 		cOCTVC1_OBJECT_CURSOR_ENUM_SPECIFIC: get a specific channel list.
	ulRfcn
 		Downlink Rfcn value related to selected band
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;
	tOCT_UINT32					ulRfcn;

} tOCTVC1_RUS_WNM_RSSI_BAND_CHANNEL_CURSOR;

#define cOCTVC1_RUS_WNM_RSSI_BAND_CHANNEL_MAX_ENTRY			128		 	/* Defines the maximum number of RSSI-Channel entries in the list. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_WNM_RSSI_CHANNEL

 Members:
	ulRfcn
 		Downlink Rfcn value related to the band
	lRssidBm
 		Receiver Signal Strength Indicator. (Q9 representation)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulRfcn;
	tOCT_INT32	lRssidBm;

} tOCTVC1_RUS_WNM_RSSI_CHANNEL;

/*-------------------------------------------------------------------------------------
 	BASS constant definitions
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_BASS_RXMODE_DEFAULT						0		 	/* By default enable the manual gain control of the receiver. */
#define cOCTVC1_RUS_BASS_RXMODE_MGC_GAIN_USE_DEFAULT		2147483647	 	/* use default MGC gain */
#define cOCTVC1_RUS_BASS_RXMODE_MGC_GAIN_DEFAULT			19456	 	/* Default MGC gain in Q9 */
#define cOCTVC1_RUS_BASS_RXMODE_MGC_GAIN_MAX				35840	 	/* Default MGC gain in Q9 */
#define cOCTVC1_RUS_BASS_RXMODE_MGC_GAIN_MIN				0		 	/* Default MGC gain in Q9 */

/*-------------------------------------------------------------------------------------
 	BASS type definition
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_RXMODE_ENUM : 	Receiver gain control mode
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_BASS_RXMODE_ENUM						tOCT_UINT32

#define cOCTVC1_RUS_BASS_RXMODE_ENUM_MGC					0		
#define cOCTVC1_RUS_BASS_RXMODE_ENUM_AGC					1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_ATTACH_STATE_ENUM : 	Base station attachement status definitions
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_BASS_ATTACH_STATE_ENUM					tOCT_UINT32

#define cOCTVC1_RUS_BASS_ATTACH_STATE_ENUM_UNINITIALIZED	0		 	/* Initialize BASS */
#define cOCTVC1_RUS_BASS_ATTACH_STATE_ENUM_INITIALZED		1		 	/* Initialization done. */
#define cOCTVC1_RUS_BASS_ATTACH_STATE_ENUM_ATTACHING		2		 	/* Attaching to a base station */
#define cOCTVC1_RUS_BASS_ATTACH_STATE_ENUM_DONE				3		 	/* Base station attachement is complete */
#define cOCTVC1_RUS_BASS_ATTACH_STATE_ENUM_PAUSE			4		
#define cOCTVC1_RUS_BASS_ATTACH_STATE_ENUM_ABORT_ERROR		5		 	/* Abort: internal error. Cause of the failure is in the log file */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_ATTACH_MODE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_BASS_ATTACH_MODE_ENUM					tOCT_UINT32

#define cOCTVC1_RUS_BASS_ATTACH_MODE_ENUM_SINGLE_ONLY		0		 	/* Attach to the base station. Stops automatically */
#define cOCTVC1_RUS_BASS_ATTACH_MODE_ENUM_CONTINUOUS		1		 	/* Attach and keep synchronized to the base station until stop command is executed */

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_SYNC_DIAG_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RUS_BASS_SYNC_DIAG_ENUM						tOCT_UINT32

#define cOCTVC1_RUS_BASS_SYNC_DIAG_ENUM_CELL_NOT_FOUND		0		
#define cOCTVC1_RUS_BASS_SYNC_DIAG_ENUM_CELL_NOT_SYNC		1		
#define cOCTVC1_RUS_BASS_SYNC_DIAG_ENUM_CELL_SYNC			2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_BS_CONFIG

 Members:
	ulWaveForm
		Default:	cOCTVC1_RADIO_STANDARD_ENUM_GSM
 		Defines the standard
	ulBand
		Default:	1
 		The band identifier is interpreted according the waveform
	ulRfcn
		Default:	979
 		It defines, with ulRfcn, the range of carrier frequency
 		to synchronize according the waveform and the band
	usPCI
		Default:	0
 		Defines Physical Cell Identifier of the base station
 		In GSM: Base Station Identity Code (BSIC): NCC 15:8 BCC 7:0
 		. NCC (15:8) Network Color Code (range 0-7)
 		. BCC (7:0) Base station Color Code (range 0-7)
	usReserved
		Default:	0
	ulRxGainControlMode
		Default:	cOCTVC1_RUS_BASS_RXMODE_ENUM_MGC
 		Receiver gain control mode
	lManualRxGaindB
		Default:	cOCTVC1_RUS_BASS_RXMODE_MGC_GAIN_USE_DEFAULT
 		Receiver gain in Q9 (ignored in cOCTVC1_RUS_WNM_RXMODE_AGC)
 		min: 0; max(depend on frequency) 62*512(62 dB) -> 73*512( 73dB) ; step : 512 (1
 		dB)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM		ulWaveForm;
	tOCT_UINT32						ulBand;
	tOCT_UINT32						ulRfcn;
	tOCT_UINT16						usPCI;
	tOCT_UINT16						usReserved;
	tOCTVC1_RUS_BASS_RXMODE_ENUM	ulRxGainControlMode;
	tOCT_INT32						lManualRxGaindB;

} tOCTVC1_RUS_BASS_BS_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_ATTACH_CONFIG

 Members:
	ulSyncMode
 		Used to select how exhaustive the search is
	BaseStationCfg
 		Carrier configuration to synchronize
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RUS_BASS_ATTACH_MODE_ENUM	ulSyncMode;
	tOCTVC1_RUS_BASS_BS_CONFIG			BaseStationCfg;

} tOCTVC1_RUS_BASS_ATTACH_CONFIG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_CELL_STATS

 Members:
	ulWaveForm
		Default:	cOCTVC1_RADIO_STANDARD_ENUM_GSM
 		Defines the standard
	ulBand
		Default:	1
 		The band identifier is interpreted according the waveform
	ulRfcn
		Default:	979
 		It defines, with ulRfcn, the range of carrier frequency
 		to synchronize according the waveform and the band
	ulFrequency
 		Carrier frequency specified according the waveform and the band (Hz).
	usPCI
		Default:	0
 		Defines Physical Cell Identifier of the base station
 		In GSM: Base Station Identity Code (BSIC): NCC 15:8 BCC 7:0
 		NCC (15:8) Network Color Code (range 0-7)
 		BCC (7:0) Base station Color Code (range 0-7)
	usReserved
		Default:	0
	lRssidBmQ9
 		Receiver Signal Strength Indicator. (Q9 representation)
 		Default -81920 (-160.0 dBm)
	lSNRdBQ9
 		Signal to Noise Ratio (Q9 representation)
 		Default 0 dB
	lFreqErrorHzQ2
 		Frequency Error Estimate in Hz (Q2 representation)
	ulCellSyncDiagnosticCode
 		Diagnosic: Provided information on the decoder
	ulReserved
 		For future use
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM		ulWaveForm;
	tOCT_UINT32						ulBand;
	tOCT_UINT32						ulRfcn;
	tOCT_UINT32						ulFrequency;
	tOCT_UINT16						usPCI;
	tOCT_UINT16						usReserved;
	tOCT_INT32						lRssidBmQ9;
	tOCT_INT32						lSNRdBQ9;
	tOCT_INT32						lFreqErrorHzQ2;
	tOCTVC1_RUS_BASS_SYNC_DIAG_ENUM	ulCellSyncDiagnosticCode;
	tOCT_UINT32						ulReserved;

} tOCTVC1_RUS_BASS_CELL_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_BASS_ATTACH_STATS

 Members:
	ulState
	BaseStationStats
 		Cell Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RUS_BASS_ATTACH_STATE_ENUM	ulState;
	tOCTVC1_RUS_BASS_CELL_STATS			BaseStationStats;

} tOCTVC1_RUS_BASS_ATTACH_STATS;

/*-------------------------------------------------------------------------------------
 	RUS Module configuration definitions
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	RUS TAP definitions
-------------------------------------------------------------------------------------*/
#define cOCTVC1_RUS_TAP_RFFI_OUT							((0x0000)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|(cOCTVC1_RUS_APPLICATION_ID_SUB_MODULE_PLAYREC<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	
#define cOCTVC1_RUS_TAP_RFFI_IN								((0x0001)|(cOCTVC1_TAP_DIRECTION_ENUM_RX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|(cOCTVC1_RUS_APPLICATION_ID_SUB_MODULE_PLAYREC<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_OPEN_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
 		Unique RF port identifier
	ulType
		Default:	cOCTVC1_RADIO_STANDARD_ENUM_UMTS
 		Rffi type
	ulRxGainMode
		Range:		[0..2]
		Default:	0
 		Controls radio receiver Rx gain mode
	Umts
 		Rffi Umts Parameter
	Gsm
 		Rffi Gsm Parameter
	Lte
 		Rffi Lte Parameter
	Cdma2000
 		Rffi Cdma2000 Parameter
	RadioConfigFile
		Default:	0
 		Radio Configuration File
	LoopBack
		Default:	0
 		LoopBack
	eAntennaMode
		Default:	cOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM_1ANT
 		Antenna operation mode : 0 - Single Ant; 1 - 2 Ant
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_INDEX							ulPortIndex;
	tOCTVC1_RADIO_STANDARD_ENUM				ulType;
	tOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM	ulRxGainMode;
	tOCTVC1_RUS_RFI_UMTS					Umts;
	tOCTVC1_RUS_RFI_GSM						Gsm;
	tOCTVC1_RUS_RFI_LTE						Lte;
	tOCTVC1_RUS_RFI_CDMA2000				Cdma2000;
	tOCTVC1_RUS_RFI_CONFIG					RadioConfigFile;
	tOCTVC1_RUS_RFI_LOOPBACK				LoopBack;
	tOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM		eAntennaMode;

} tOCTVC1_RUS_MSG_RFFI_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique Rffi identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique Rfi identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique Generator identifier
	ulPortIndex
 		Unique RF port identifier
	ulType
 		Rffi type
	ulRxGainMode
		Range:		[0..2]
		Default:	0
 		Controls radio receiver Rx gain mode
	Umts
 		Rffi Umts Parameter
	Gsm
 		Rffi Gsm Parameter
	Cdma2000
 		Rffi Cdma2000 Parameter
	Lte
 		Rffi LTE Parameter
	RadioConfigFile
		Default:	0
 		Radio Config File
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_HANDLE_OBJECT					hRffi;
	tOCTVC1_INDEX							ulPortIndex;
	tOCTVC1_RADIO_STANDARD_ENUM				ulType;
	tOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM	ulRxGainMode;
	tOCTVC1_RUS_RFI_UMTS					Umts;
	tOCTVC1_RUS_RFI_GSM						Gsm;
	tOCTVC1_RUS_RFI_CDMA2000				Cdma2000;
	tOCTVC1_RUS_RFI_LTE						Lte;
	tOCTVC1_RUS_RFI_CONFIG					RadioConfigFile;

} tOCTVC1_RUS_MSG_RFFI_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique Generator identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique Generator identifier
	ulType
 		Rffi type
	ulTransmitterCnt
 		Rffi transmitter count (see identifier in ahTransmitter[])
	ulReceiverCnt
 		Rffi transmitter count (see identifier in ahTransmitter[])
	ahTransmitter
 		Transmitter identifier array
	ahReceiver
 		Receiver identifier array
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RADIO_STANDARD_ENUM	ulType;
	tOCT_UINT32					ulTransmitterCnt;
	tOCT_UINT32					ulReceiverCnt;
	tOCTVC1_HANDLE_OBJECT		ahTransmitter[cOCTVC1_RUS_RFFI_TRANSMITTER_MAX];
	tOCTVC1_HANDLE_OBJECT		ahReceiver[cOCTVC1_RUS_RFFI_RECEIVER_MAX];

} tOCTVC1_RUS_MSG_RFFI_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_LIST_CMD

 Members:
	Header
	ObjectCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_RUS_MSG_RFFI_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_LIST_RSP

 Members:
	Header
	ObjectCursor
 		Object Cursor.
	ObjectList
 		Generic handle object list structure
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_RUS_MSG_RFFI_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	ulCaptureDoneFlag
		Default:	cOCT_FALSE
 		Indicates than the digital sample capture is done
	ulTxByteWritePnt
 		Indicates where the last captured radio byte is copied in the buffer.
	ulTxCapturedBufferSizeinBytes
 		Indicates the size of captured buffer in bytes.
	ulTxCapturedRadioUnitLength
 		Indicates the size of captured buffer in radio unit length. The radio unit
 		depends on protocol ( For GSM : 1 radio frame, UMTS : 1 radio slot, , LTE : 1
 		radio slot)
	szTxCaptureFileName
 		NULL terminated name of the file.
	ulRxByteWritePnt
 		Indicates where the last captured radio byte is copied in the buffer.
	ulRxCapturedBufferSizeinBytes
 		Indicates the size of captured buffer in bytes.
	ulRxCapturedRadioUnitLength
 		Indicates the size of captured buffer in radio unit length. The radio unit
 		depends on protocol ( For GSM : 1 radio frame, UMTS : 1 radio slot, LTE : 1
 		radio slot)
	szRxCaptureFileName
 		NULL terminated name of the file.
	szRx2CaptureFileName
 		NULL terminated name of Antenna 2 Capture file.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;
	tOCT_BOOL32				ulCaptureDoneFlag;
	tOCT_UINT32				ulTxByteWritePnt;
	tOCT_UINT32				ulTxCapturedBufferSizeinBytes;
	tOCT_UINT32				ulTxCapturedRadioUnitLength;
	tOCT_INT8				szTxCaptureFileName[(cOCTVC1_FILE_NAME_MAX_LENGTH+1)];
	tOCT_UINT32				ulRxByteWritePnt;
	tOCT_UINT32				ulRxCapturedBufferSizeinBytes;
	tOCT_UINT32				ulRxCapturedRadioUnitLength;
	tOCT_INT8				szRxCaptureFileName[(cOCTVC1_FILE_NAME_MAX_LENGTH+1)];
	tOCT_INT8				szRx2CaptureFileName[(cOCTVC1_FILE_NAME_MAX_LENGTH+1)];

} tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	ulCapturedRadioUnitLength
		Default:	30
 		Indicates the number radio unite to be captured. The radio unite capture
 		depends on protocol(For GSM : 1 radio frame, for UMTS: 1 radio slot, for LTE: 1
 		radio slot.)
	ulContinuousCaptureFlag
		Default:	0
 		Capture radio sample forever. Stop only with STOP_CAPTURE ccommand
	ulDurationType
		Default:	0
 		ulDurationType
	ulDuration
		Default:	0
 		Duration
	szFileNamePrefix
 		NULL terminated name of the file.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_HANDLE_OBJECT					hRffi;
	tOCT_UINT32								ulCapturedRadioUnitLength;
	tOCT_BOOL32								ulContinuousCaptureFlag;
	tOCTVC1_RUS_CAPTURE_DURATION_TYPE_ENUM	ulDurationType;
	tOCT_UINT32								ulDuration;
	tOCT_INT8								szFileNamePrefix[(cOCTVC1_FILE_NAME_MAX_LENGTH+1)];

} tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Info
 		Rffi Umts Parameter
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;
	tOCTVC1_RUS_RFI_UMTS	Info;

} tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Stats
 		Rffi Umts Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_UMTS_STATS	Stats;

} tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_GSM_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Info
 		Rffi GSM Parameter
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;
	tOCTVC1_RUS_RFI_GSM		Info;

} tOCTVC1_RUS_MSG_RFFI_INFO_GSM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_GSM_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Stats
 		Rffi Gsm Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_GSM_STATS	Stats;

} tOCTVC1_RUS_MSG_RFFI_STATS_GSM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_LTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Info
 		Rffi LTE Parameter
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;
	tOCTVC1_RUS_RFI_LTE		Info;

} tOCTVC1_RUS_MSG_RFFI_INFO_LTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_LTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Stats
 		Rffi Lte Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_LTE_STATS	Stats;

} tOCTVC1_RUS_MSG_RFFI_STATS_LTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD
 		Select a RFFI to play file selections.

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Rffi identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	hRffi
 		RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_PLAYER_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	State
 		State
	ulActiveFileEntryId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hPlayer;
	tOCTVC1_RUS_PLAYER_STATE_ENUM	State;
	tOCTVC1_SUB_OBJECT_ID			ulActiveFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_LIST_CMD

 Members:
	Header
	ObjectCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_RUS_MSG_PLAYER_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_LIST_RSP

 Members:
	Header
	ObjectCursor
 		Object Cursor.
	ObjectList
 		Generic handle object list structure
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_RUS_MSG_PLAYER_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_START_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	ulActiveFileEntryId
	ulRepeatForeverFlag
		Default:	cOCT_TRUE
 		Play all files forever.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulActiveFileEntryId;
	tOCT_BOOL32				ulRepeatForeverFlag;

} tOCTVC1_RUS_MSG_PLAYER_START_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_START_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_START_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_STOP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_STOP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_STOP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_STOP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	ulActiveFileEntryId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulActiveFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_MODIFY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;

} tOCTVC1_RUS_MSG_PLAYER_MODIFY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	szFileName
 		Player entry Name.
	lFileOffset
		Range:		[-38399..38399]
		Default:	0
 		Select the sample offset of the active playback buffer
 		From -38399 : 1 : +38399
	lGaindB
		Range:		[-200..200]
		Default:	0
 		Apply a gain on sample of the active playback buffer (dB)
 		From -20 : 0.1 : +20
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCT_INT8				szFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];
	tOCT_INT32				lFileOffset;
	tOCT_INT32				lGaindB;

} tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	ulFileEntryId
 		Unique Entry identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	ulFileEntryId
 		Unique Entry identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Unique Player identifier
	ulFileEntryId
 		Unique Entry identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Player identifier
	ulFileEntryId
 		Player entry identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Player identifier
	ulFileEntryId
 		Player entry identifier
	szFileName
 		Player entry Name.
	ulFileSize
		Default:	0
 		File size
	lFileOffset
		Range:		[-38399..38399]
		Default:	0
 		Select the sample offset of the active playback buffer
 		From -38399 : 1 : +38399
	lGaindB
		Range:		[-200..200]
		Default:	0
 		Aplly a gain on sample of the active playback buffer (dB)
 		From -20 : 0.1 : +20
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;
	tOCT_INT8				szFileName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32				ulFileSize;
	tOCT_INT32				lFileOffset;
	tOCT_INT32				lGaindB;

} tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	ObjectNameList
 		Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER									Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID		SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME	ObjectNameList;

} tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Player identifier
	ulFileEntryId
 		Player entry identifier
	lFileOffset
		Range:		[-38399..38399]
		Default:	0
 		Select the sample offset of the active playback buffer
 		From -38399 : 1 : +38399
	lGaindB
		Range:		[-200..200]
		Default:	0
 		Apply a gain on sample of the active playback buffer (dB)
 		From -20 : 0.1 : +20
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;
	tOCT_INT32				lFileOffset;
	tOCT_INT32				lGaindB;

} tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPlayer
 		Player identifier
	ulFileEntryId
 		Player entry identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPlayer;
	tOCTVC1_SUB_OBJECT_ID	ulFileEntryId;

} tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD
 		Setups WNM's list entries with carrier to search.

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	SearchParms
 		Defines the list of carrier to monitor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_RUS_WNM_SEARCH_PARMS	SearchParms;

} tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD
 		Starts the monitoring procedure according carriers parameters specified in the
 		list.
 		Using start commands reset all previous results of the database.

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_START_SEARCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_START_SEARCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD
 		Stop the monitoring procedure. The current scanned carrier is aborted.

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	SearchParms
 		Report current cell search configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_RUS_WNM_SEARCH_PARMS	SearchParms;

} tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD
 		This command reports the status of the cell search. Information summarizes
 		the number of base station found and the current search status.

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	Stats
 		Cell search's statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_RUS_WNM_SEARCH_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_OPEN_CMD
 		The open command reserves the hardware resources required for the
 		WNM processing (.i.e. RF farm association, core and accelerator grant).
 		Response return the handle on the WNM.
 		Select a WNM Port Index to open

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
		Default:	0
 		Unique RF port identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulPortIndex;

} tOCTVC1_RUS_MSG_WNM_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_CLOSE_CMD
 		The close command releases the hardware resources used by the WNM.

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;

} tOCTVC1_RUS_MSG_WNM_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulPortIndex
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCT_UINT32				ulPortIndex;

} tOCTVC1_RUS_MSG_WNM_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_CMD

 Members:
	Header
	ObjectCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_RUS_MSG_WNM_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_RSP

 Members:
	Header
	ObjectCursor
 		Object Cursor.
	ObjectList
 		Generic handle object list structure
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_RUS_MSG_WNM_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_UMTS_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	SubObjectIdList
 		Sub Object Id List.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdList;

} tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_GSM_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	SubObjectIdList
 		Sub Object Id List.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdList;

} tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_LTE_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	SubObjectIdList
 		Sub Object Id List.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdList;

} tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_HANDLE_OBJECT				hWnm;
	tOCTVC1_SUB_OBJECT_ID				ulCellId;
	tOCTVC1_RUS_WNM_CDMA2000_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	SubObjectIdList
 		Sub Object Id List.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdList;

} tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ObjectGet
 		RSSI Band object get structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_RUS_WNM_RSSI_BAND_CURSOR	ObjectGet;

} tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectGet
 		RSSI Band object get structure.
	Stats
 		Band statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_RUS_WNM_RSSI_BAND_CURSOR	ObjectGet;
	tOCTVC1_RUS_WNM_RSSI_BAND_STATS		Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier.
	BandId
	ObjectGet
 		RSSI Channel list get structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_HANDLE_OBJECT						hWnm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID			BandId;
	tOCTVC1_RUS_WNM_RSSI_BAND_CHANNEL_CURSOR	ObjectGet;

} tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier.
	BandId
	ObjectGet
 		RSSI Channel list get structure.
	ulNumEntry
 		Number of valid entries in aChannelEntry.
	aChannelEntry
 		Array of RSSI channel entries.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER							Header;
	tOCTVC1_HANDLE_OBJECT						hWnm;
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID			BandId;
	tOCTVC1_RUS_WNM_RSSI_BAND_CHANNEL_CURSOR	ObjectGet;
	tOCT_UINT32									ulNumEntry;
	tOCTVC1_RUS_WNM_RSSI_CHANNEL				aChannelEntry[cOCTVC1_RUS_WNM_RSSI_BAND_CHANNEL_MAX_ENTRY];

} tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hWnm;
	tOCTVC1_SUB_OBJECT_ID	ulCellId;

} tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hWnm
 		Unique WNM identifier
	ulCellId
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hWnm;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_NR_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	SubObjectIdList
 		Sub Object Id List.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdList;

} tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	LoopBack
		Default:	0
 		LoopBack Configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_LOOPBACK	LoopBack;

} tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	LoopBack
		Default:	0
 		LoopBack Configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_LOOPBACK	LoopBack;

} tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	LoopBack
		Default:	0
 		LoopBack Configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_LOOPBACK	LoopBack;

} tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Info
 		Rffi Cdma2000 Parameter
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hRffi;
	tOCTVC1_RUS_RFI_CDMA2000	Info;

} tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRffi;

} tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRffi
 		Unique RFFI identifier
	Stats
 		Rffi Cdma2000 Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRffi;
	tOCTVC1_RUS_RFI_CDMA2000_STATS	Stats;

} tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD
 		Setup BASS entry with carrier to synchronize.

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
	AttachConfig
 		Defines the entry to monitor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hBass;
	tOCTVC1_RUS_BASS_ATTACH_CONFIG	AttachConfig;

} tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD
 		Starts the monitoring procedure according carrier parameter.
 		Using start commands reset all previous results of the database.

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_START_ATTACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_START_ATTACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD
 		Stop the monitoring procedure. The current synchronized carrier is aborted.

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
	AttachConfig
 		Report current cell synchronized configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hBass;
	tOCTVC1_RUS_BASS_ATTACH_CONFIG	AttachConfig;

} tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD
 		This command reports the status of the cell sync.

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
	Stats
 		Cell sync's statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hBass;
	tOCTVC1_RUS_BASS_ATTACH_STATS	Stats;

} tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_OPEN_CMD
 		The open command reserves the hardware resources required for the
 		BASS processing (.i.e. RF farm association, core and accelerator grant).
 		Response return the handle on the BASS.
 		Select a BASS Port Index to open

 Members:
	Header
 		OCTVC1 Message Header
	ulPortIndex
		Default:	0
 		Unique RF port identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulPortIndex;

} tOCTVC1_RUS_MSG_BASS_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_CLOSE_CMD
 		The close command releases the hardware resources used by the BASS.

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;

} tOCTVC1_RUS_MSG_BASS_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hBass
 		Unique BASS identifier
	ulPortIndex
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hBass;
	tOCT_UINT32				ulPortIndex;

} tOCTVC1_RUS_MSG_BASS_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_LIST_CMD

 Members:
	Header
	ObjectCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_RUS_MSG_BASS_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_BASS_LIST_RSP

 Members:
	Header
	ObjectCursor
 		Object Cursor.
	ObjectList
 		Generic handle object list structure
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_RUS_MSG_BASS_LIST_RSP;


/*****************************  MODULE_DATA  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA

 Members:
	ModuleData
	hRffi
 		Unique RFFI identifier
	ulPktCnt
	ulAntIndex
	ulNbSample
	ulReserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA		ModuleData;
	tOCTVC1_HANDLE_OBJECT	hRffi;
	tOCT_UINT32				ulPktCnt;
	tOCT_UINT32				ulAntIndex;
	tOCT_UINT32				ulNbSample;
	tOCT_UINT32				ulReserved;

} tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_rus_evt.h"

#endif /* __OCTVC1_RUS_API_H__ */

