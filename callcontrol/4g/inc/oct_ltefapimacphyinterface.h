/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_ltefapimacphyinterface.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.
    
Description: 

This is the file used as interface between PHY and MAC for LTE.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_LTE_APP-03.12.00-B589 (2018/03/19)

$Revision: 41583 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCT_LTE_FAPI_MAC_PHY_INTERFACE_H
#define OCT_LTE_FAPI_MAC_PHY_INTERFACE_H
#include "octdev_types.h"

/* Below are flags to manage different versions of header file */

/* Set alignment to 32 bit boundary for this file */
#pragma pack(4)

/**
 * tFAPI_MSG_ID definition
 */
typedef tOCT_UINT8 tFAPI_MSG_ID;
/**
 * Possible FAPI messages for the PHY interface of type tFAPI_MSG_ID
 */
#define PHY_PARAM_REQUEST				0x00
#define PHY_PARAM_RESPONSE				0x01
#define PHY_CELL_CONFIG_REQUEST			0x02
#define PHY_CELL_CONFIG_RESPONSE		0x03
#define PHY_START_REQUEST				0x04
#define PHY_STOP_REQUEST				0x05
#define PHY_STOP_INDICATION				0x06
#define PHY_UE_CONFIG_REQUEST			0x07
#define PHY_UE_CONFIG_RESPONSE			0x08
#define PHY_ERROR_INDICATION			0x09

#define PHY_DL_CONFIG_REQUEST			0x80
#define PHY_UL_CONFIG_REQUEST			0x81
#define PHY_UL_SUBFRAME_INDICATION		0x82
#define PHY_DL_HI_DCI0_REQUEST			0x83
#define PHY_DL_TX_REQUEST				0x84
#define PHY_UL_HARQ_INDICATION			0x85
#define PHY_UL_CRC_INDICATION			0x86
#define PHY_UL_RX_ULSCH_INDICATION		0x87
#define PHY_UL_RACH_INDICATION			0x88
#define PHY_UL_SRS_INDICATION			0x89
#define PHY_UL_RX_SR_INDICATION			0x8a
#define PHY_UL_RX_CQI_INDICATION		0x8b


/* This macro is used for declaring array of variable length */
#define mFAPI_VAR_SIZE(x) 1


/**
* Data : constant
* Name : cRECONFIG_TLV_NUM
* Description : This constant describes the number of TLV changes request during
*               PHY Reconfig currently value is 2, later may be increased as
*               number of runtime reconfig parameters supported increases
**/
#define cRECONFIG_TLV_NUM 2

/* Maximum number of antennas in DL or UL currently supported */
#define cMAX_NUM_ANTENNA 4


/* L1 Error Indication */

typedef enum
{
    eFAPI_MSG_OK,
    eFAPI_MSG_INVALID_STATE,
    eFAPI_MSG_INVALID_CONFIG,
    eFAPI_SFN_OUT_OF_SYNC,
    eFAPI_MSG_SUBFRAME_ERR,
    eFAPI_MSG_BCH_MISSING,
    eFAPI_MSG_INVALID_SFN,
    eFAPI_MSG_HI_ERR,
    eFAPI_MSG_TX_ERR,
	eFAPI_OCTASIC_CUSTOM_ERR
}eFAPI_L1ERRORCODES;

// Below are the bit positions for different modules, which can raise an error.
// For modules like PDCCH,PDSCH,UL and RFI the error codes are defined subsequently.
// For L1C cache handler, the cache miss count is indicated in the 16 bit value.
typedef enum
{
     eOCTASIC_CUSTOM_ERROR_DL_PDCCH_HANDLER=0x1,
	 eOCTASIC_CUSTOM_ERROR_L1C_CACHE_HANDLER=0x2,
     eOCTASIC_CUSTOM_ERROR_DL_PDSCH_HANDLER=0x4,
     eOCTASIC_CUSTOM_ERROR_UL_HANDLER=0x8,
     eOCTASIC_CUSTOM_ERROR_DL_RFI_HANDLER=0x10,
     eOCTASIC_CUSTOM_ERROR_UL_RFI_HANDLER=0x20,
} eOCTASIC_CUSTOM_ERROR_HANDLERS;


typedef enum
{
	eDL_PDCCH_HANDLER_ERROR_NONE=0x00,
	eDL_PDCCH_HANDLER_ERROR_DCI_PDU_MISSING=0x0001,
	eDL_PDCCH_HANDLER_ERROR_WRONG_CFI_LENGTH=0x0002,
	eDL_PDCCH_HANDLER_ERROR_DL_CONFIG_MISSING=0x0004,
	eDL_PDCCH_HANDLER_ERROR_PBCH_PDU_MISSING=0x0008,
	eDL_PDCCH_HANDLER_ERROR_UNEXPECTED_SUBFN_DL_CONFIG=0x0010,
	eDL_PDCCH_HANDLER_ERROR_UNEXPECTED_SUBFN_HI_DCI0=0x0020,
	eDL_PDCCH_HANDLER_ERROR_UNEXPECTED_SUBFN_HI_DCI0_IGNORED=0x0040,
	eDL_PDCCH_HANDLER_ERROR_TDD_HI_PDU_IN_INVALID_SUBFN=0x0080,
}eDL_PDCCH_HANDLER_ERROR_CODES;


typedef enum
{
    eDL_PDSCH_HANDLER_ERROR_NONE=0x00,
	eDL_PDSCH_HANDLER_ERROR_TX_REQUEST_MISSING=0x0001,
	eDL_PDSCH_HANDLER_ERROR_DLSCH_PDU_MISSING=0x0002,
	eDL_PDSCH_HANDLER_ERROR_DL_CONFIG_MISSING=0x0004,
	eDL_PDSCH_HANDLER_ERROR_TXREQUEST_DLSCH_PDU_MISSING=0x0008,
	eDL_PDSCH_HANDLER_ERROR_UNEXPECTED_SUBFN_DL_CONFIG=0x0010,
	eDL_PDSCH_HANDLER_ERROR_UNEXPECTED_SUBFN_TX_REQUEST=0x0020,
	eDL_PDSCH_HANDLER_ERROR_UNEXPECTED_SUBFN_TX_REQUEST_IGNORED=0x0040,
	eDL_PDSCH_HANDLER_ERROR_TX_REQUEST_WITHOUT_DLSCH_PDU=0x0080,
	eDL_PDSCH_HANDLER_ERROR_PBCH_PDU_MISSING=0x0100,
	eDL_PDSCH_HANDLER_ERROR_PBCH_INVALID_SUBFN=0x0200,
}eDL_PDSCH_HANDLER_ERROR_CODES;


typedef enum
{
    eUL_HANDLER_ERROR_NONE=0x00,
	eUL_HANDLER_ERROR_UL_CONFIG_MISSING=0x0001,
	eUL_HANDLER_ERROR_UNEXPECTED_SUBFN_UL_CONFIG=0x0002,
	eUL_HANDLER_ERROR_SEVERAL_PUCCH=0x0004,
	eUL_HANDLER_ERROR_SEVERAL_PUSCH=0x0008,
	eUL_HANDLER_ERROR_PUSCH_OM_SYNC_ERROR=0x0010,
	eUL_HANDLER_ERROR_PUSCH_OM_DELAYED_ULSCH_RESPONSE=0x0020,
	eUL_HANDLER_ERROR_SEVERAL_SRS=0x0040,
	eUL_HANDLER_ERROR_UL_GRANT_NOT_SUPPORTED=0x0080
}eUL_HANDLER_ERROR_CODES;

typedef enum
{
  eDL_RFI_HANDLER_ERROR_NONE=0x00,
  eDL_RFI_HANDLER_ERROR_UNDERFLOW =0x1,
}eDL_RFI_HANDLER_ERROR_CODES;


typedef enum
{
  eUL_RFI_HANDLER_ERROR_NONE=0x00,
  eUL_RFI_HANDLER_ERROR_OVERFLOW =0x1,
}eUL_RFI_HANDLER_ERROR_CODES;


/* PHY CELL CONFIG Possible Tags */
typedef enum
{
    eFAPI_DUPLEXING_MODE = 1,
    eFAPI_PCFICH_POWER_OFFSET,
    eFAPI_P_B,
    eFAPI_DL_CYCLIC_PREFIX_TYPE,
    eFAPI_UL_CYCLIC_PREFIX_TYPE,
/* RF Config */
    eFAPI_DL_CHANNEL_BANDWIDTH,
    eFAPI_UL_CHANNEL_BANDWIDTH,
    eFAPI_REFERENCE_SIGNAL_POWER,
    eFAPI_TX_ANTENNA_PORTS,
    eFAPI_RX_ANTENNA_PORTS,
/* RF CONFIG TAGS ENDS */
/* PHICH CONFIG */
    eFAPI_PHICH_RESOURCE,
    eFAPI_PHICH_DURATION,
    eFAPI_PHICH_POWER_OFFSET,
/* PHICH CONFIG ENDS */
/* SCH COnfig */
    eFAPI_PRIMARY_SYNC_SIGNAL,
    eFAPI_SECONDARY_SYNC_SIGNAL,
    eFAPI_PHYSICAL_CELL_ID,
/* SCH COnfig  Ends */
/* PRACH Config */
    eFAPI_CONFIGURATION_INDEX,
    eFAPI_ROOT_SEQUENCE_INDEX,
    eFAPI_ZERO_CORRELATION_ZONE_CONFIGURATION,
    eFAPI_HIGH_SPEED_FLAG,
    eFAPI_FREQUENCY_OFFSET,
/* PRACH Config  Ends */
/* PUSCH Config */
    eFAPI_HOPPING_MODE,
    eFAPI_HOPPIG_OFFSET,
    eFAPI_NUM_OF_SUB_BANDS,
/* PUSCH Config  Ends */
/* PUCCH Config */
    eFAPI_DELTA_PUCCH_SHIFT,
    eFAPI_N_CQI_RB,
    eFAPI_N_AN_CS,
    eFAPI_N_1_PUCCH_AN,
/* PUCCH Config Ends */
/* SRS Config */
    eFAPI_BANDWIDTH_CONFIGURATION,
    eFAPI_MAX_UP_PTS,
    eFAPI_SRS_SUB_FRAME_CONFIGURATION,
    eFAPI_SRS_ACK_NACK_SRS_SIMULTANEOUS_TRANSMISSION,
/* SRS Config Ends */
/* Uplink reference signal Config */
    eFAPI_UPLINK_RS_HOPPING,
    eFAPI_GROUP_ASSIGNMENT,
    eFAPI_CYCLIC_SHIFT_1_FOR_DMRS,
/* Uplink reference signal Config Ends */
/* TDD Frame Structure Config */
    eFAPI_SUB_FRAME_ASSIGNMENT,
    eFAPI_SPECIAL_SUB_FRAME_PATTERNS,
/* TDD Frame Structure Config Ends */

/* below tags are used by L1 to reports its physical capabilities to L2/L3 software */
    eFAPI_DL_BANDWIDTH_SUPPORT = 40,
    eFAPI_UL_BANDWIDTH_SUPPORT,
    eFAPI_DL_MODULATION_SUPPORT,
    eFAPI_UL_MODULATION_SUPPORT,
    eFAPI_PHY_ANTENNA_CAPABILITY,
/* below tags are used by L2/L3 software to configure the interaction between L2/L3 and L1 */

    eFAPI_DATA_REPORT_MODE = 50,
    eFAPI_SFN_SF,

/* the below tag is used by L1 to report its current status */
    eFAPI_PHY_STATE = 60

}eFAPI_CELL_CONFIG;

/* --------------------------------------------- */

/* PHY states */
typedef enum
{
    eFAPI_IDLE,
    eFAPI_CONFIGURED,
    eFAPI_RUNNING,
    eFAPI_INTERNAL_STOPPING
}eFAPI_PHY_STATES;

/* Types of Duplexing Mode */
typedef enum
{
    eFAPI_TDD,
    eFAPI_FDD,
    eFAPI_HD_FDD
}eFAPI_DUPLEXING_MODES;

/* Types of Cylic Prefix */
typedef enum
{
    eFAPI_CP_NORMAL,
    eFAPI_CP_EXTENDED
}eFAPI_CYCLIC_PREFIX;

/* UL/DL Channel Bandwidth */
typedef enum
{
    eFAPI_CHANNEL_BW_6RB = 6,
    eFAPI_CHANNEL_BW_15RB = 15,
    eFAPI_CHANNEL_BW_25RB = 25,
    eFAPI_CHANNEL_BW_50RB = 50,
    eFAPI_CHANNEL_BW_75RB = 75,
    eFAPI_CHANNEL_BW_100RB = 100 
}eFAPI_CHANNEL_BW;

/* Num. of Tx Antenna Ports (downlink) */
typedef enum
{
    eFAPI_TX_ANTENNA_PORT_1 = 1,
    eFAPI_TX_ANTENNA_PORT_2 = 2,
    eFAPI_TX_ANTENNA_PORT_4 = 4
}eFAPI_TX_ANTENNA_PORT;

/* Num. of Rx Antenna Ports (uplink) */
typedef enum
{
    eFAPI_RX_ANTENNA_PORT_1 = 1,
    eFAPI_RX_ANTENNA_PORT_2 = 2,
    eFAPI_RX_ANTENNA_PORT_4 = 4
}eFAPI_RX_ANTENNA_PORT;

/* POSSIBLE PHICH RESOURCE VALUES */
typedef enum
{
    eFAPI_PHICH_R_ONE_SIXTH,
    eFAPI_PHICH_R_HALF,
    eFAPI_PHICH_R_ONE,
    eFAPI_PHICH_R_TWO
}eFAPI_PHICH_RESOURCE_VALUES;

/* PHICH Duration */
typedef enum
{
    eFAPI_PHICH_D_NORMAL,
    eFAPI_PHICH_D_EXTENDED
}eFAPI_PHICH_DURATIONS;

/* High Speed Flag */
typedef enum
{
    eFAPI_HS_UNRESTRICTED_SET,
    eFAPI_HS_RESTRICTED_SET
}eFAPI_HIGH_SPEED_FLAG_TYPE;

/* Hopping Mode */
typedef enum
{
    eFAPI_HM_INTER_SF,
    eFAPI_HM_INTRA_INTER_SF
}eFAPI_HOPPING_MODE_TYPE;

/* Types of hopping */
typedef enum
{
    eFAPI_RS_NO_HOPPING,
    eFAPI_RS_GROUP_HOPPING,
    eFAPI_RS_SEQUENCE_HOPPING
}eFAPI_HOPPING_TYPE;

/* Physical Antenna Capabililty */
typedef enum
{
    eFAPI_PHY_ANTENNA_CAP_1 = 1,
    eFAPI_PHY_ANTENNA_CAP_2 = 2,
    eFAPI_PHY_ANTENNA_CAP_4 = 4
}eFAPI_PHY_ANTENNA_CAPABILITY_LIST;

/* Ack Nack Repetition Factor */
typedef enum
{
    eFAPI_AN_REPETITION_FACTOR_2 = 2,
    eFAPI_AN_REPETITION_FACTOR_4 = 4,
    eFAPI_AN_REPETITION_FACTOR_6 = 6
}eFAPI_AN_REPETITION_FACTOR_LIST;

/* SPS DL Config Scheduling Interval */
typedef enum
{
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_10 = 10,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_20 = 20,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_32 = 32,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_40 = 40,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_64 = 64,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_80 = 80,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_128 = 128,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_160 = 160,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_320 = 320,
    eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL_640 = 640 
}eFAPI_SPS_DL_CONFIG_SCHED_INTERVAL;

/* Types of Resource Allocation */
typedef enum
{
    eFAPI_RES_ALLOC_TYPE_0,
    eFAPI_RES_ALLOC_TYPE_1,
    eFAPI_RES_ALLOC_TYPE_2
}eFAPI_RES_ALLOC_TYPE;
   
/* vRB Assignment Flag */
typedef enum
{
    eFAPI_LOCALISED,
    eFAPI_DISTRIBUTED
}eFAPI_VRB_ASSIGNMENT_TYPE;

/* Transport Block (TB) To Code Word (CW) Swap Flag */
typedef enum
{
    eFAPI_NOSWAPPING,
    eFAPI_SWAPPED
}eFAPI_TB_TO_CW_SWAP_TYPE;



/* types of TPC 0/1A/1B/1D/1/2A/2B/2/3*/
typedef enum
{
    eFAPI_TX_POWER_CONTROL_MINUS_1 = 0,
    eFAPI_TX_POWER_CONTROL_0 = 1,
    eFAPI_TX_POWER_CONTROL_1 = 2,
    eFAPI_TX_POWER_CONTROL_3 = 3
}eFAPI_TPC_VALUE;

/* types of TPC 3A*/
typedef enum
{
    eFAPI_DCI_3A_TX_POWER_CONTROL_MINUS_1 = 0,
    eFAPI_DCI_3A_TX_POWER_CONTROL_1 =1
}eFAPI_DCI_3A_TPC_VALUE;



/* Types of Transmission Scheme */
typedef enum
{
    eFAPI_DL_SINGLE_ANTENNA_PORT_0, 
    eFAPI_DL_TX_DIVERSITY, 
    eFAPI_DL_LARGE_DELAY_CDD, 
    eFAPI_DL_CLOSED_LOOP_SPATIAL_MULTIPLEXING, 
    eFAPI_DL_MULTI_USER_MIMO, 
    eFAPI_DL_CLOSED_LOOP_RANK_1_PRECODING, 
    eFAPI_DL_SINGLE_ANTENNA_PORT_5
}eFAPI_DL_TRANSMISSION_SCHEME;

/* Types of RNTI */
typedef enum
{
    eFAPI_C_RNTI = 1,
    eFAPI_RA_RNTI_P_RNTI_SI_RNTI,
    eFAPI_SPS_CRNTI,
    eFAPI_OTHER_CRNTI
}eFAPI_RNTI_TYPE;

/* types of AggegationLevel */
typedef enum
{
    eFAPI_AGGEGATION_LEVEL_1 = 1,
    eFAPI_AGGEGATION_LEVEL_2 = 2,
    eFAPI_AGGEGATION_LEVEL_4 = 4,
    eFAPI_AGGEGATION_LEVEL_8 = 8
}eFAPI_AGGREGATION_LEVEL;

/* P-A values */
typedef enum
{
    eFAPI_DB_MINUS6,
    eFAPI_DB_MINUS_4DOT77,
    eFAPI_DB_MINUS_3,
    eFAPI_DB_MINUS_1DOT77,
    eFAPI_DB0,
    eFAPI_DB1,
    eFAPI_DB2,
    eFAPI_DB3
}eFAPI_PA_VALUE;
 
/* Types of modulation*/
typedef enum
{
    eFAPI_QPSK = 2,
    eFAPI_16QAM = 4,
    eFAPI_64QAM = 6
}eFAPI_MODULATION_TYPE;

/* uplink Transmission Mode types */
typedef enum
{
    eFAPI_UL_TX_SISO_SIMO,
    eFAPI_UL_TX_MIMO
}eFAPI_UL_TRANSMISSION_SCHEME;

/* Types of Harq Indicator Values */
typedef enum
{
    eFAPI_HI_NACK,
    eFAPI_HI_ACK  
}eFAPI_HI_VALUE;

/* Types of CQI Request */
typedef enum
{
    eFAPI_APERIODIC_CQI_NOT_REQUESTED,
    eFAPI_APERIODIC_CQI_REQUESTED
}eFAPI_APERIODIC_CQI_REQUEST;

/* ue Tx Antenna Selection (uplink)*/
typedef enum
{   
    eFAPI_ANT_PORT_NOT_CONFIGURED = 0,
    eFAPI_CONF_UE_PORT_0 = 1,
    eFAPI_CONF_UE_PORT_1 = 2
}eFAPI_UE_TX_ANTENNA_SELECTION;

/* types of DL Assignment Index */
typedef enum
{
    eFAPI_DL_ASSIGN_INDEX_1 = 1,
    eFAPI_DL_ASSIGN_INDEX_2,
    eFAPI_DL_ASSIGN_INDEX_3,
    eFAPI_DL_ASSIGN_INDEX_4
}eFAPI_DL_ASSIGN_INDEX;

/* types of DL HARQ feedback TB1/TB2 recieved in PUCCH/PUSCH */
typedef enum
{
    eFAPI_DL_ACK = 1,
    eFAPI_DL_NACK,
    eFAPI_DL_ACK_OR_NACK,
    eFAPI_DL_DTX,
    eFAPI_DL_ACK_OR_DTX,
    eFAPI_DL_NACK_OR_DTX,
    eFAPI_DL_ACK_OR_NACK_OR_DTX 
}eFAPI_DL_HARQ_FEEDBACK;

/* CRC FLAGS */
typedef enum
{
    eFAPI_CRC_CORRECT,
    eFAPI_CRC_ERROR
}eFAPI_CRC_FLAGS;

/* TDD ACK NACK FEEDBACK MODE */
typedef enum
{
    eFAPI_TDD_BUNDLING=0,
    eFAPI_TDD_MULTIPLEXING=1,
    eFAPI_TDD_SPECIAL_BUNDLING=2,// Valid only in the direction PHY->STACK 
}eFAPI_TDD_ACK_NACK_FEEDBACK_MODE;

/* enum definition for UL/DL config/tx request */

typedef enum
{
    eFAPI_DCI_DL_PDU,
    eFAPI_BCH_PDU,
    eFAPI_MCH_PDU,
    eFAPI_DLSCH_PDU,
    eFAPI_PCH_PDU
}eFAPI_DL_PDU_TYPE;

typedef enum
{
    eFAPI_DL_DCI_FORMAT_1,
    eFAPI_DL_DCI_FORMAT_1A,
    eFAPI_DL_DCI_FORMAT_1B,
    eFAPI_DL_DCI_FORMAT_1C,
    eFAPI_DL_DCI_FORMAT_1D,
    eFAPI_DL_DCI_FORMAT_2,
    eFAPI_DL_DCI_FORMAT_2A,
    eFAPI_DL_DCI_FORMAT_2B,
}eFAPI_DL_DCI_FORMAT_INFO;

typedef enum
{
    eFAPI_UL_DCI_FORMAT_0,
    eFAPI_UL_DCI_FORMAT_3,
    eFAPI_UL_DCI_FORMAT_3A
}eFAPI_UL_DCI_FORMAT_INFO;

typedef enum
{
    eFAPI_HI_PDU,
    eFAPI_DCI_UL_PDU
}eFAPI_HI_DCI0_PDU_INFO;

typedef enum
{
    eFAPI_ULSCH,
    eFAPI_ULSCH_CQI_RI,
    eFAPI_ULSCH_HARQ,
    eFAPI_ULSCH_CQI_HARQ_RI,
    eFAPI_UCI_CQI,
    eFAPI_UCI_SR,
    eFAPI_UCI_HARQ,
    eFAPI_UCI_SR_HARQ,
    eFAPI_UCI_CQI_HARQ,
    eFAPI_UCI_CQI_SR,
    eFAPI_UCI_CQI_SR_HARQ,
    eFAPI_SRS,
    eFAPI_HARQ_BUFFER,
    eFAPI_INVALID_PDU_TYPE = 255
}eFAPI_UL_CONFIG_PDU_INFO;

/* UE CONFIG Possible Tags */
typedef enum
{
    eFAPI_HANDLE = 100,
    eFAPI_RNTI,
/* CQI CONFIG */
    eFAPI_CQI_PUCCH_RESOURCE_INDEX,
    eFAPI_CQI_PMI_CONFIG_INDEX,
    eFAPI_CQI_RI_CONFIG_INDEX,
    eFAPI_CQI_SIMULTANEOUS_ACK_NACK_CQI,
/* CQI CONFIG ENDS */
/* ACK/NACK CONFIG */
    eFAPI_AN_REPETITION_FACTOR,
    eFAPI_AN_N1_PUCCH_AN_REP,
    eFAPI_TDD_ACK_NACK_FEEDBACK,
/* ACK/NACK CONFIG  Ends*/
/* SRS CONFIG */
    eFAPI_SRS_BANDWIDTH,
    eFAPI_SRS_HOPPING_BANDWIDTH,
    eFAPI_FREQUENCY_DOMAIN_POSITION,
    eFAPI_SRS_DURATION,
    eFAPI_ISRS_SRS_CONFIG_INDEX,
    eFAPI_TRANSMISSION_COMB,
    eFAPI_SOUNDING_REFERENCE_SYCLIC_SHIFT,
/* SRS CONFIG  Ends */
/* SR CONFIG */
    eFAPI_SR_PUCCH_RESOURCE_INDEX,
    eFAPI_SR_CONFIG_INDEX,
/* SR CONFIG Ends */
/* SPS CONFIG */
    eFAPI_SPS_DL_CONFIG_SCHD_INTERVAL,
    eFAPI_SPS_DL_N1_PUCCH_AN_PERSISTENT
/* SPS CONFIG  Ends*/
}eFAPI_UE_CONFIG_INFO;

/********************* STRUCTURE TYPES  **************************************/

/* --------------------------------------------- */

/* parameters which can be present in Config.Request */
typedef union
{
    /* Type of duplexing mode 0: TDD,1: FDD,2: HD_FDD */
    tOCT_UINT16  usDuplexingMode;

    /*The power per antenna of the PCFICH with respect to the reference signal.
    Value: 0->10000 represents -6dB to 4dB in steps 0.001dB */
    tOCT_UINT16  usPcfichPowerOffset;
          
    /*Refers to downlink power allocation. Value is an index into the 
    referenced table.Value: 0 -> 3*/
    tOCT_UINT16  usPb;

    /*Cyclic prefix type, used for DL 0: CP_NORMAL, 1: CP_EXTENDED. */
    tOCT_UINT16  usDlCyclicPrefixType;
   
    /*Cyclic prefix type, used for UL 0: CP_NORMAL, 1: CP_EXTENDED. */
    tOCT_UINT16  usUlCyclicPrefixType;

    /* RF Config */
    
    /*Downlink channel bandwidth in resource blocks.
    Value: 6,15, 25, 50, 75, 100 */
    tOCT_UINT16  usDlChannelBW;
   
    /*Uplink channel bandwidth in resource blocks.
    Value: 6,15, 25, 50, 75,100 */
    tOCT_UINT16  usUlChannelBW;

    /* Normalized value levels (relative) to accommodate different 
    absolute Tx Power used by eNb.
    Value: 0 . 255 Representing 0dB to -63.75dB in -0.25dB step */
    tOCT_UINT16  usRefSignalPower;

    /*No. of cell specific transmit antenna ports.
    Value:1,2,4 */
    tOCT_UINT16  usTxAntennaPort;

    /* No. of cell specific receive antenna ports.
    Value: 1, 2, 4 */
    tOCT_UINT16  usRxAntennaPort;
   
    /* RF Config Ends */

    /* PHICH Config */

    /* No.of resource element groups used for PHICH
    0: PHICH_R_ONE_SIXTH
    1: PHICH_R_HALF
    2: PHICH_R_ONE
    3: PHICH_R_TWO */
    tOCT_UINT16  usPhichResource;

    /* No. resource element groups used for PHICH
    0: PHICH_D_NORMAL
    1: PHICH_D_EXTENDED  */
    tOCT_UINT16  usPhichDuration;

    /* The power per antenna of the PHICH with respect to the reference signal:
    Value: 0-> 10000, represents -6dB to 4dB in steps 0.001dB */
    tOCT_UINT16  usPhichPowOffset;

    /* PHICH Config  Ends */
    
    /* SCH Config */

    /* The power of synchronization signal with respect to the reference signal
    Value: 0 . 9999 represents -6dB to 4dB in step 0.001dB */
    tOCT_UINT16  usPrimarySyncSignal;

    /* The power of synchronization signal with respect to the reference signal
    Value: 0 . 9999 represents -6dB to 4dB in step 0.001dB */
    tOCT_UINT16  usSecondarySyncSignal;

    /* The Cell ID sent with the synchronization signal
    Value: 0 . 503 */
    tOCT_UINT16  usPhysicalCellId;

    /* SCH Config Ends */

    /* PRACH Config start*/
    /* Provides information about the location and format of the PRACH. 
    See TS36.211, section 5.7. Table 5.7.1-2 for FDD, Table 5.7.1-3 for TDD.        
    The value is an index into the referenced tables. Value: 0 . 63 */ 
    tOCT_UINT16  usConfigurationIndex;

    /* PRACH Root sequence index
    Value: 0 . 837 */
    tOCT_UINT16  usRootSeqIndex;
   
    /* Equivalent to Ncs, 
    TDD: 0 . 6
    FDD: 0 . 15 */
    tOCT_UINT16  usZeroCorelationZoneConfig;

    /* Indicates if unrestricted, or restricted, set of preambles is used
    0: HS_UNRESTRICTED_SET
    1: HS_RESTRICTED_SET */
    tOCT_UINT16  usHighSpeedFlag;

    /* The first physical resource block available for PRACH
    Value: 0 . UL_channel_bandwidth . 6 */
    tOCT_UINT16  usFreqOffset;
    /* PRACH Config Ends */

    /* PUSCH Config */

    /* If hopping is enabled indicates the type of hopping used
    0: HM_INTER_SF
    1: HM_INTRA_INTER_SF */
    tOCT_UINT16  usHoppingMode;

    /* The offset used if hopping is enabled
    Value: 0 . 98 */
    tOCT_UINT16  usHoppingOffset;

    /* The number of sub-bands used for hopping
    Value: 1 . 4 */
    tOCT_UINT16  usNumOfSubBand;

    /* PUSCH Config Ends */
    
    /* PUCCH Config */

    /* The cyclic shift difference
    Value: 1 . 3 */
    tOCT_UINT16  usDeltaPUCCHShift;

    /* The bandwidth, in units of resource blocks, that is available for use 
    by PUCCH formats 2/2a/2b transmission in each slot.
    Value: 0 . 98 */
    tOCT_UINT16  usNCQIRB;

    /* The number of cyclic shifts used for PUCCH formats 1/1a/1b in a 
    resource block with a mix of formats 1/a/1/ab and 2/2a/2b
    Value: 0 . 7 */
    tOCT_UINT16  usNAnCs;
   
    tOCT_UINT16  usN1PucchAn;

    /* PUCCH Config Ends */

    /* SRS Config */
 
    /* The available SRS bandwidth of the cell
    The value is an index into the referenced table.
    Value: 0 . 7 */
    tOCT_UINT16  usBandWidthConfiguration;

    /*  - Used for TDD only
    - Indicates how SRS operates in UpPTS subframes
    0: Disabled
    1: Enabled */
    tOCT_UINT16  usMaxUpPTS;

    /* The SRS subframe configuration. 
    Value: 0 . 15 */
    tOCT_UINT16  usSRSSubframeConfiguration;

    /* Indicates if SRS and ACK/NACK can be received in the same subframe. 
    0: no simultaneous transmission
    1: simultaneous transmission */
    tOCT_UINT8  bySrsAckNackSimulTx;

    /* SRS Config Ends */

    /* Uplink Reference Signal Config */
    /* Indicates the type of hopping to use.
    0: RS_NO_HOPPING
    1: RS_GROUP_HOPPING
    2: RS_SEQUENCE_HOPPING */
    tOCT_UINT16  usUplinkRSHopping;

    /* The sequence shift pattern used if group hopping is enabled.
    Values: 0 . 29 */
    tOCT_UINT16  usGroupAssignment;

    /* Specifies the cyclic shift for the reference signal used in the cell.
    The value is an index into the referenced table.
    Value: 0 . 7 */
    tOCT_UINT16  usCyclicShift1forDMRS;
    /* Uplink Reference Signal Config Ends */

    /* TDD FRAME STRUCTURE CONFIG */

    /* indicates the DL/UL subframe structure.
    Value: 0 . 6 */
    tOCT_UINT16  usSubFrameAssignment;

    /* Length of fields DwPTS, GP and UpPTS.
    Value: 0 . 8 */
    tOCT_UINT16  usSpecialSubFramePatterns;

    /* TDD FRAME STRUCTURE CONFIG Ends */

    /* The data report mode for the uplink data.
    0: A CRC.indication message is sent in every subframe.  
    - If ULSCH data has been processed, the CRC.indication contains 
    CRC results for the subframe. 
    - The CRC results are, also, given in the RX.indication message.
    1: The CRC.indication message is not sent. 
    - The CRC results are given in the RX.indication message. */
    tOCT_UINT16  usDataReportingMode;

    /* The future SFN/SF subframe where the TLVs included in the message 
    should be applied.A 16-bit value where,[15:4] SFN, range 0 . 1023
    [3:0] SF, range 0 . 9 */
    tOCT_UINT16  usSfnsf;

    /* Below parametrs are used by L1 to report its physical capabilities to 
    the L2/L3 software */

    /* Indicates the current operational state of the PHY.

    0 = IDLE
    1 = CONFIGURED
    2 = RUNNING   */
    tOCT_UINT16    usPhyState; /* define in enum eFAPI_PHY_STATE */
   
    /* The PHY downlink channel bandwidth capability (in resource blocks). 
    Value: bitX :0 = no support, 1= support. 
    Bit0: 6
    Bit1: 15
    Bit2: 25
    Bit3: 50
    Bit4: 75
    Bit5: 100     */

    tOCT_UINT16    usDlBandWidthSupport;
    
    /* The PHY uplink channel bandwidth capability (in resource blocks). 

    Value: bitX :0 = no support, 1= support.
    Bit0: 6
    Bit1: 15
    Bit2: 25
    Bit3: 50
    Bit4: 75
    Bit5: 100     */
    tOCT_UINT16    usUlBandWidthSupport;
    
    /* The PHY downlink modulation capability.
    Value: bitX :0 = no support, 1= support.
    Bit0: QPSK
    Bit1: 16QAM
    Bit2: 64QAM */
    tOCT_UINT16    usDlModulationSupport;

    /* The PHY uplink modulation capability.
    Value: bitX :0 = no support, 1= support.
    Bit0: QPSK
    Bit1: 16QAM
    Bit2: 64QAM    */
    tOCT_UINT16    usUlModulationSupport;
    
    /* Number of antennas supported.
    Value: 1, 2, 4  */
    tOCT_UINT16    usPhyAntennaCapability;

}tOCT_FAPI_CELL_CONFIG_PARAM;

/* parameters which can be present in Config.Request during PHY Reconfig */
typedef union
{
    /* The power per antenna of the PCFICH with respect to the reference signal.
       Value: 0 -> 10000, represents -6dB to 4dB in steps 0.001dB */
    tOCT_UINT16  usPcfichPowerOffset;

    /* Refers to downlink power allocation.
       See TS36.213 section 5.2
       Value is an index into the referenced table.
       Value: 0 -> 3 */
    tOCT_UINT16  usPB;

    /* Normalized value levels (relative) to accommodate different absolute 
	   Tx Power used by eNb.
       Value: 0 -> 255, representing 0dB to -63.75dB in -0.25dB steps. */
    tOCT_UINT16  usRefSignalPower;

    /* The power per antenna of the PHICH with respect to the reference signal.
       Value: 0-> 10000, represents -6dB to 4dB in steps 0.001dB */
    tOCT_UINT16  usPhichPowOffset;

    /* The power of synchronization signal with respect to the reference signal,
       Value: 0 -> 9999 represents -6dB to 4dB in step 0.001dB */
    tOCT_UINT16  usPrimarySyncSignal;

    /* The power of synchronization signal with respect to the reference signal,
       Value: 0 -> 9999 represents -6dB to 4dB in step 0.001dB */
    tOCT_UINT16  usSecondarySyncSignal;
	
    /* The Cell ID sent with the synchronization signal
       Value: 0 -> 503 */
    tOCT_UINT16  usPhysicalCellId;

    /* The future SFN/SF subframe where the TLVs included in the message should be applied.
       A 16-bit value where,
           [15:4] SFN, range 0 -> 1023
           [3:0] SF, range 0 -> 9 */
    tOCT_UINT16  usSfnsf;

} tOCT_FAPI_CELL_RECONFIG_PARAM;
/* ------------------------- */

/* cell Config structure */
typedef struct
{
    /* tag values are defined in enum eFAPI_CELL_CONFIG */
    tOCT_UINT8                   byTag; 

    /* tag length parameter ensures the complete TLV is a multiple
    * of 4-bytes (32-bits).  */
    tOCT_UINT8                   byTagLen;

    tOCT_FAPI_CELL_CONFIG_PARAM  configParam;     
     
}tOCT_FAPI_CELL_CONFIG_TLV;

#define SIZE_TOCT_FAPI_CELL_CONFIG_TLV ( 2*sizeof(tOCT_UINT8) + sizeof(tOCT_FAPI_CELL_CONFIG_PARAM) )

/*cell ReConfig structure */
typedef struct
{
    /*tag values are defined in enum eFAPI_CELL_CONFIG */
    tOCT_UINT8                    byTag;
    /* tag length parameter ensures the complete TLV is a multiple
    * of 4-bytes (32-bits).  */
    tOCT_UINT8                    byTagLen;
    
    tOCT_FAPI_CELL_RECONFIG_PARAM configParam;

}tOCT_FAPI_CELL_RECONFIG_TLV;

#define SIZE_TOCT_FAPI_CELL_RECONFIG_TLV ( 2*sizeof(tOCT_UINT8) + sizeof(tOCT_FAPI_CELL_RECONFIG_PARAM) )

/* --------------------------------------------- */

/* UE Config parametrs which wiil be filled in tOCT_FAPI_UE_CONFIG_TLV */

    /* An opaque handling to associate the received information in 
    RX.indication */
  
    /* tOCT_UINT32  ulHandle; */

    /* The RNTI used for identifying the UE when receiving the PDU.
    Value: 1 . 65535. */

    /* tOCT_UINT16  usRnti; */

    /* CQI Config */

    /* PUCCH resource for periodc CQI reporting
    Value: 0 . 1185 */

    /* tOCT_UINT16  usCqiPucchResourceIndex; */

    /* The periodic PMI reporting configuration.
    Value: 0 . 1023. */

    /* tOCT_UINT16  usCqiPmiConfigIndex; */

    /* The periodic RI reporting configuration.
    Value: 0 . 1023. */

    /* tOCT_UINT16  usCqiRiConfigIndex; */

    /* Indicates if simultaneous transmission of CQI and ACK/NACK is allowed.
    Value:
    0: no PUCCH Format 2a/2b
    1: PUCCH Format 2a/2b can be used */

    /* tOCT_UINT16  usSimultaneousAckNackAndCqi; */

    /* CQI Config ENDS */
 
    /* ACK/NACK Config */

    /* The ACK/NACK repetition  factor.
    Value: 2,4,6 */
    
    /* tOCT_UINT8   byAckNacknRepetitionFactor; */

    /* The ACK/NACK repetition PUCCH resource index.
    Value: 0. 2047 */

    /* tOCT_UINT16  usAnN1PUCCHANRep; */

    /* The TDD ACK/NACK Feedback Mode
    Value:
    0: bundling
    1: multiplexing */

    /* tOCT_UINT8   byTddAckNackFeedbackMode; */

    /* ACK/NACK Config Ends */

    /* SRS Config */

    /*  SRS Bandwidth. This value is fixed for a UE and allocated in 
    RRC connection setup.
    Value: 0 . 3. */

    /* tOCT_UINT8   bySrSBandWidth; */

    /* Configures the frequency hopping on the SRS. 
    This value is fixed for a UE and allocated in RRC connection setup.
    Value 0 . 3. */

    /* tOCT_UINT8   bySrsHoppingBandwidth; */

    /* Frequency-domain position, NRRC This value is fixed for a UE and 
    allocated in RRC connection setup.
    Value: 0 . 23. */

    /* tOCT_UINT8   byFreqDomainPosition; */

    /* The duration of the SRS configuration
    Value:
    0: once
    1: indefinite */

    /* tOCT_UINT8   bySrsDuration; */

    /* Defines the periodicity and subframe location of the SRS.
    SRS Configuration Index. This value is fixed for a UE and 
    allocated in RRC connection setup
    Value: 0 . 1023. */

    /* tOCT_UINT16   usSrsConfigIndex; */

    /* Configures the frequency location of the SRS. 
    This value is fixed for a UE and allocated in RRC connection setup.
    Value: 0 .  1 */

    /* tOCT_UINT8   byTxComb; */

    /* Configures the SRS sequence generation. 
    This value is fixed for a UE and allocated in RRC connection setup.
    Value: 0 . 7 */

    /* tOCT_UINT8   bySoundingRefCyclicShift; */
    /* SRS Config Ends */

    /* SR Config */

    /* Scheduling request PUCCH resource index
    Value: 0 . 2047. */
 
    /* tOCT_UINT16  usSrPucchResourceIndex; */

    /* The scheduling request configuration index.
    Value: 0 . 155. */

    /* tOCT_UINT8   bySrConfigIndex; */

    /* SR Config Ends */

    /* SPS Config */

    /* SPS Configuration Interval
    Value: 10,20,32,40,64,80,128,160,320,640 */

    /* tOCT_UINT16  usSpsDlConfigSchedInterval; */

    /* The SPS PUCCH AN Resource configuration.
    The TLV can be repeated four times.
    Value: 0 . 2047. */

    /* tOCT_UINT16  usSpsDln1PUCCHANPersistent; */

    /* SPS Config Ends */

/* -------------------------------   */

/* UE Config structure */
typedef struct
{
    /* tag define in  FAPI_ueConig_en */
    tOCT_UINT8   byTag;

    /* tag length parameter ensures the complete TLV is a multiple of 4-bytes 
    (32-bits).  */
    tOCT_UINT8   byTagLen;

    /* The Possible values can be of size tOCT_UINT16 or tOCT_UINT32 or tOCT_UINT8 */
    /* For more details please see above parametrs wise in comment */ 
    tOCT_UINT8   abyValue[mFAPI_VAR_SIZE(tagLen)];    

}tOCT_FAPI_UE_CONFIG_TLV;

/* --------------------------------- */

typedef struct
{
    /* tag values are defined in enum eFAPI_CELL_CONFIG */
    tOCT_UINT8                   byTag; 

    /* tag length parameter ensures the complete TLV is a multiple of 4-bytes (32-bits).  */
    tOCT_UINT8                   byTagLen;
    
    tOCT_FAPI_CELL_CONFIG_PARAM  configParam;     
    
}tOCT_FAPI_PARAM_RESPONSE_TLV;

#define SIZE_TOCT_FAPI_PARAM_RESPONSE_TLV ( 2*sizeof(tOCT_UINT8) + \
		sizeof(tOCT_FAPI_CELL_CONFIG_PARAM) )

/* structure for DCI FORMAT 1 */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Resource allocation type
    Valid for DCI formats: 1,2,2A
    0=type 0
    1=type 1  */
    tOCT_UINT8         byResAllocationType;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* HARQ process number
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;


    /* Tx power control command for PUCCH.
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI 
    the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3 
    respectively. */
    tOCT_UINT8         byTpc;

    /* The downlink assignment index. Only used in TDD mode, value ignored 
    for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;
    
    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* RNTI type Valid for DCI format 1, 1A,2,2A
    1  =  C-RNTI
    2 =  RA-RNTI, P-RNTI, or SI-RNTI.
    3 = SPS-CRNTI   */
    tOCT_UINT8         byRntiType;

    /* Padding required for 2 bytes */
    tOCT_UINT8         abyPadding[1];

}tOCT_FAPI_DCIFORMAT_1;

#define SIZE_TOCT_FAPI_DCIFORMAT_1 ( sizeof(tOCT_FAPI_DCIFORMAT_1) )

/* ---------------------------------- */

/* structure for DCI FORMAT 1A */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Type of virtual resource block used
    Valid for DCI formats: 1A,1B,1D

    0 = localized
    1 = distributed  */
    tOCT_UINT8         byVRBAssignmentFlag;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* HARQ process number
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;

    /* Tx power control command for PUCCH.
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI 
    the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3 
    respectively. */
    tOCT_UINT8         byTpc;

    /* The downlink assignment index. Only used in TDD mode, value ignored 
    for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;
    
    /* Indicates that PRACH procedure is initiated Valid for DCI formats: 1A
    0 = false
    1=true   */
    tOCT_UINT8         byAllocatePRACHFlag;

    /* The preamble index to be used on the PRACH Valid for DCI formats: 1A
    Value: 0 . 63   */
    tOCT_UINT8         byPreambleIndex;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* The mask index to be used on the PRACH Valid for DCI formats: 1A
    Value: 0 . 15  */
    tOCT_UINT8         byPRACHMaskIndex;

    /* RNTI type Valid for DCI format 1, 1A,2,2A
    1  =  C-RNTI
    2 =  RA-RNTI, P-RNTI, or SI-RNTI.
    3 = SPS-CRNTI   */
    tOCT_UINT8         byRntiType;

    tOCT_UINT8         abyPadding[2];

}tOCT_FAPI_DCIFORMAT_1A;

#define SIZE_TOCT_FAPI_DCIFORMAT_1A ( sizeof(tOCT_FAPI_DCIFORMAT_1A) )

/* ---------------------------------- */

/* structure for DCI FORMAT 1B */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Type of virtual resource block used
    Valid for DCI formats: 1A,1B,1D

    0 = localized
    1 = distributed  */
    tOCT_UINT8         byVRBAssignmentFlag;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* HARQ process number
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;

    /* The codebook index to be used for precoding
    Valid for DCI formats: 1B,1D 
    2 antenna_ports: 0 . 3
    4 antenna_ports: 0 . 15  */
    tOCT_UINT8         byTPMI;

    /* Confirmation for precoding
    Valid for DCI formats: 1B
    0 = use precoding indicated in TPMI field
    1 = use precoding indicated in last PMI report on PUSCH  */
    tOCT_UINT8         byPmi;

    /* Tx power control command for PUCCH.
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI 
    the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3 
    respectively. */
    tOCT_UINT8         byTpc;

    /* The downlink assignment index. Only used in TDD mode, value ignored 
    for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;
    
    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* Used in virtual resource block distribution
    Valid for DCI formats: 1B,1C,1D
    0= NGAP1
    1=  NGAP2   */
    tOCT_UINT8         byNGAP;

    tOCT_UINT8         abyPadding[3];
}tOCT_FAPI_DCIFORMAT_1B;

#define SIZE_TOCT_FAPI_DCIFORMAT_1B ( sizeof(tOCT_FAPI_DCIFORMAT_1B) )

/* ---------------------------------- */

/* structure for DCI FORMAT 1C */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* Used in virtual resource block distribution
    Valid for DCI formats: 1B,1C,1D
    0= NGAP1
    1=  NGAP2   */
    tOCT_UINT8         byNGAP;

    /* The transport block size
    Valid for DCI formats: 1C
    Value: 0 . 31   */
    tOCT_UINT8         byTbSizeIndex;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

}tOCT_FAPI_DCIFORMAT_1C;

#define SIZE_TOCT_FAPI_DCIFORMAT_1C ( sizeof(tOCT_FAPI_DCIFORMAT_1C) )

/* ---------------------------------- */

/* structure for DCI FORMAT 1D */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Type of virtual resource block used
    Valid for DCI formats: 1A,1B,1D

    0 = localized
    1 = distributed  */
    tOCT_UINT8         byVRBAssignmentFlag;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* HARQ process number
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;

    /* The codebook index to be used for precoding
    Valid for DCI formats: 1B,1D 
    2 antenna_ports: 0 . 3
    4 antenna_ports: 0 . 15  */
    tOCT_UINT8         byTPMI;

    /* Tx power control command for PUCCH.
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI 
    the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3 
    respectively. */
    tOCT_UINT8         byTpc;

    /* The downlink assignment index. Only used in TDD mode, value ignored 
    for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;
    
    /* Used in virtual resource block distribution
    Valid for DCI formats: 1B,1C,1D
    0= NGAP1
    1=  NGAP2   */
    tOCT_UINT8         byNGAP;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* Indicates the DL power offset type for multi-user MIMO transmission
    Valid for DCI formats: 1D
    Value: 0 . 1   */
    tOCT_UINT8         byDlPowerOffset;

    tOCT_UINT8         abyPadding[3];
}tOCT_FAPI_DCIFORMAT_1D;

#define SIZE_TOCT_FAPI_DCIFORMAT_1D ( sizeof(tOCT_FAPI_DCIFORMAT_1D) )

/* ---------------------------------- */

/* structure for DCI FORMAT 2 */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Resource allocation type
    Valid for DCI formats: 1,2,2A
    0=type 0
    1=type 1  */
    tOCT_UINT8         byResAllocationType;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* Indicates the mapping of transport block to codewords
    Valid for DCI formats: 2,2A
    0 = no swapping
    1 = swapped    */
    tOCT_UINT8         byTbToCodeWordSwapFlag;

    /* The modulation and coding scheme for 2nd transport block. 
    Valid for DCI formats: 2,2A
    Value: 0 . 31    */
    tOCT_UINT8         byMcs_2;

    /* The redundancy version for 2nd transport block. 
    Valid for DCI formats: 2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_2;

    /* The new data indicator for 2nd transport block.
    Valid for DCI formats: 2,2A */
    tOCT_UINT8         byNewDataIndicator_2;

    /* HARQ process number
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;

    /* Precoding information
    2 antenna_ports: 0 . 7
    4 antenna_ports: 0 . 63   */
    tOCT_UINT8         byPreCodingInfo;

    /* Tx power control command for PUCCH.
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI 
    the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3 
    respectively. */
    tOCT_UINT8         byTpc;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* The downlink assignment index. Only used in TDD mode, value ignored 
    for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;
    
    /* RNTI type Valid for DCI format 1, 1A,2,2A
    1  =  C-RNTI
    2 =  RA-RNTI, P-RNTI, or SI-RNTI.
    3 = SPS-CRNTI   */
    tOCT_UINT8         byRntiType;

}tOCT_FAPI_DCIFORMAT_2;

#define SIZE_TOCT_FAPI_DCIFORMAT_2 ( sizeof(tOCT_FAPI_DCIFORMAT_2) )

/* ---------------------------------- */

/* structure for DCI FORMAT 2A */
typedef struct
{
    /* The aggregation level used
    Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Resource allocation type
    Valid for DCI formats: 1,2,2A
    0=type 0
    1=type 1  */
    tOCT_UINT8         byResAllocationType;

    /* The modulation and coding scheme for 1st transport block
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use.
    Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A
    Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* Indicates the mapping of transport block to codewords
    Valid for DCI formats: 2,2A
    0 = no swapping
    1 = swapped    */
    tOCT_UINT8         byTbToCodeWordSwapFlag;

    /* The modulation and coding scheme for 2nd transport block. 
    Valid for DCI formats: 2,2A
    Value: 0 . 31    */
    tOCT_UINT8         byMcs_2;

    /* The redundancy version for 2nd transport block. 
    Valid for DCI formats: 2,2A
    Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_2;

    /* The new data indicator for 2nd transport block.
    Valid for DCI formats: 2,2A */
    tOCT_UINT8         byNewDataIndicator_2;

    /* HARQ process number
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;

    /* Precoding information
    4 antenna_ports: 0 . 3*/
    tOCT_UINT8         byPreCodingInfo;

    /* Tx power control command for PUCCH.
    Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI 
    the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3 
    respectively. */
    tOCT_UINT8         byTpc;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* The downlink assignment index. Only used in TDD mode, value ignored 
    for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A
    Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;
    
    /* RNTI type Valid for DCI format 1, 1A,2,2A
    1  =  C-RNTI
    2 =  RA-RNTI, P-RNTI, or SI-RNTI.
    3 = SPS-CRNTI   */
    tOCT_UINT8         byRntiType;

}tOCT_FAPI_DCIFORMAT_2A;

#define SIZE_TOCT_FAPI_DCIFORMAT_2A ( sizeof(tOCT_FAPI_DCIFORMAT_2A) )

/* ---------------------------------- */

typedef struct
{
    /* The aggregation level used
    * Value: 1,2,4,8  */
    tOCT_UINT8         byAggregationLevel;

    /* Resource allocation type
    * Valid for DCI formats: 1,2,2A, 2B
    * 0=type 0
    * 1=type 1  */
    tOCT_UINT8         byResAllocationType;

    /* The modulation and coding scheme for 1st transport block
    * Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A, 2B
    * Value: 0 . 31   */
    tOCT_UINT8         byMcs_1;

    /* The redundancy version for 1st transport block.
    * Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A, 2B
    * Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_1;

    /* The encoding for the resource blocks. It's coding is dependent on
    * whether resource allocation type 0, 1, 2 is in use.
    * Resource allocation type 0 is explicitly signalled for DCI formats 1, 2, 2A, 2B
    * Resource allocation type 1 is explicitly signalled for DCI formats 1, 2, 2A, 2B
    * Resource allocation type 2 is implicit for DCI formats 1A, 1B, 1C, 1D
    * Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A, 2B   */
    tOCT_UINT32        ulRbCoding;

    /* The new data indicator for 1st transport block.
    * Valid for DCI formats: 1,1A,1B,1C,1D ,2,2A, 2B  */
    tOCT_UINT8         byNewDataIndicator_1;

    /* The modulation and coding scheme for 2nd transport block.
    * Valid for DCI formats: 2,2A, 2B
    * Value: 0 . 31    */
    tOCT_UINT8         byMcs_2;

    /* The redundancy version for 2nd transport block.
    * Valid for DCI formats: 2,2A, 2B
    * Value: 0 . 3   */
    tOCT_UINT8         byRedundancyVersion_2;

    /* The new data indicator for 2nd transport block.
    * Valid for DCI formats: 2,2A, 2B */
    tOCT_UINT8         byNewDataIndicator_2;

    /* HARQ process number
    * Valid for DCI formats: 1,1A,1B,1D,2,2A, 2B
    * Value: 0 . 7  */
    tOCT_UINT8         byHarqProcessNum;
    /* Scrambling identity */
    tOCT_UINT8         byScramblingId;

    /* Tx power control command for PUCCH.
    * Valid for DCI formats: 1,1A,1B,1D,2,2A, 2B
    * Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    * In case of DCI format 1A and RNTI=SI-RNTI,RA-RNTI or P-RNTI
    * the TPC values are either 0,1 representing N_PRB=2 and N_PRB =3
    * respectively. */
    tOCT_UINT8         byTpc;
    
    /* The downlink assignment index. Only used in TDD mode, value ignored
    * for FDD.Valid for DCI formats: 1,1A,1B,1D,2,2A, 2B
    * Value: 1,2,3,4  */
    tOCT_UINT8         byDlAssignmentIndex;

    /* Offset to the reference signal power.
    * Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16        usTxPower;

    /* RNTI type Valid for DCI format 1, 1A,2,2A, 2B
    * 1  =  C-RNTI
    * 2 =  RA-RNTI, P-RNTI, or SI-RNTI.
    * 3 = SPS-CRNTI   */
    tOCT_UINT8         byRntiType;

    tOCT_UINT8         abyPadding[1];
}tOCT_FAPI_DCIFORMAT_2B;

#define SIZE_TOCT_FAPI_DCIFORMAT_2B ( sizeof(tOCT_FAPI_DCIFORMAT_2B) )

/* ---------------------------------- */

/* DCI PDU Structure */
typedef struct
{
    /* Format of the DCI
    0 = 1
    1 = 1A
    2 = 1B
    3 = 1C
    4 = 1D
    5 = 2
    6 = 2A
    7 = 2B */
    tOCT_UINT8         byDciFormat; /* defined in  eFAPI_DL_DCI_FORMAT_INFO */

    /* CCE index used to send the DCI. 
    Value: 0 . 88 */
    tOCT_UINT8         byCceIndex;

    /* The RNTI used for identifying the UE when receiving the PDU
    Valid for all DCI formats
    Value: 1 . 65535. */
    tOCT_UINT16        usRnti;

    /* this dci PDU can be of any structre mentioned above based 
    upon dciFormat type. Parsing entity is required to typecast this 
    with apropriate DCI Format structure */
    tOCT_UINT8         abyDciPdu[mFAPI_VAR_SIZE(x)];

}tOCT_FAPI_DL_DCI_PDU_INFO;

#define SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE ( sizeof(tOCT_UINT8)*2 + sizeof(tOCT_UINT16) )

/* ---------------------------------- */

/* BCH PDU structure */
typedef struct
{
    /* The length (in byTes) of the associated MAC PDU, delivered in 
    TX.request. This should be the actual length of the MAC PDU, 
    which may not be a multiple of 32-bits. */
    tOCT_UINT16         usBchPduLen;
    
    /* This is a count value which is incremented every time a BCH, MCH, PCH or
    DLSCH PDU is included in the DL_CONFIG.request message.
    This value is repeated in TX.request and associates the control information
    to the data.It is reset to 0 for every subframe.
    Range 0 . 65535 */
    tOCT_UINT16         usPduIndex;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps.  */
    tOCT_UINT16         usTxPower;

    tOCT_UINT8          abyPadding[2];
}tOCT_FAPI_DL_BCH_PDU_INFO;

#define SIZE_TOCT_FAPI_DL_BCH_PDU_INFO ( sizeof(tOCT_FAPI_DL_BCH_PDU_INFO) )

/* ---------------------------------- */

/* MCH CONFIG PDU structure */
typedef struct
{
    /* The length (in bytes) of the associated MAC PDU, delivered in 
    TX.request.  This should be the actual length of the MAC PDU, 
    which may not be a multiple of 32-bits  */
    tOCT_UINT16         usMchPduLen;

    /* This is a count value which is incremented every time a BCH, MCH, PCH or
    DLSCH PDU is included in the DL_CONFIG.request message.
    This value is repeated in TX.request and associates the control information
    to the data.It is reset to 0 for every subframe.
    Range 0 . 65535    */
    tOCT_UINT16         usPduIndex;

    /* The RNTI associated with the MCH
    Value: 1 . 65535.  */
    tOCT_UINT16         usRnti;

    /* Resource allocation type
    0 = type 0
    1 = type 1
    2 = type 2   */
    tOCT_UINT8          byResAllocationType;

    /* The modulation type used in the transport channels
    2: QPSK
    4: 16QAM
    6: 64QAM  */
    tOCT_UINT8          byModulationType;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use. */
    tOCT_UINT32         ulRbCoding;
 
    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16         usTxPower;

    tOCT_UINT8          abyPadding[2];
}tOCT_FAPI_DL_MCH_PDU_INFO;

#define SIZE_TOCT_FAPI_DL_MCH_PDU_INFO ( sizeof(tOCT_FAPI_DL_MCH_PDU_INFO) )

/* ---------------------------------- */

/* BEAM Froming Vector Structure */
typedef struct
{
    /* Index of subband for which the following beam forming vector is
    applied.         */
    tOCT_UINT8         bySubBandIndex;

    /* Number of physical antennas */
    tOCT_UINT8         byNumOfAntenna;

    /* For each physical antenna */
    /* Beam forming vector element for physical antenna 
    #i real 8 bits followed by imaginery 8 bits  */
    tOCT_UINT16        ausBfValuePerAntenna[mFAPI_VAR_SIZE(numOfAntenna)];

}tOCT_FAPI_DL_BEAMFORM_INFO;

/* ---------------------------------- */

/* DLSCH CONFIG structure */
typedef struct
{
    /* The length (in bytes) of the associated MAC PDU, delivered in 
    TX.request. This should be the actual length of the MAC PDU, 
    which may not be a multiple of 32-bits. */
    tOCT_UINT16                 usDlschPduLen;

    /* This is a count value which is incremented every time a BCH, MCH, PCH 
    or DLSCH PDU is included in the DL_CONFIG.request message.
    This value is repeated in TX.request and associates the control information
    to the data.It is reset to 0 for every subframe. 
    Range 0 . 65535   */
    tOCT_UINT16                 usPduIndex;

    /* The RNTI associated with the UE
    Value: 1 . 65535. */
    tOCT_UINT16                 usRnti;

    /* Resource allocation type
    0 = type 0
    1 = type 1
    2 = type 2  */
    tOCT_UINT8                  byResAllocationType;

    /* Type of virtual resource block used. This should match the value sent in
    the DCI Format 1A, 1B, 1D PDU which allocated this grant.
    0 = localized
    1 = distributed     */
    tOCT_UINT8                  byVRBAssignmentFlag;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use. This should match 
    the value sent in the DCI Format PDU which allocated this grant. */
    tOCT_UINT32                 ulRbCoding;

    /* 2: QPSK
    4: 16QAM
    6: 64QAM   */
    tOCT_UINT8                  byMcs;

    /* HARQ redundancy version. This should match the value sent in the 
    DCI Format PDU which allocated this grant.
    Value: 0 . 3.   */
    tOCT_UINT8                  byRedundancyVersion;

    /* The transport block transmitted to this RNTI. A value of 2 indicates 
    this is the second transport block for either DCI format 2 or 2A. 
    For other DCI values this field will always be 1.
    Value: 1 . 2  */
    tOCT_UINT8                  byTransportBlocks;

    /* Indicates the mapping of transport block to codewords. 
    This should match the value sent in the DCI Format 2, 2A PDU which 
    allocated this grant.
    0 = no swapping
    1 = swapped      */
    tOCT_UINT8                  byTbToCodeWordSwapFlag;

    /* The MIMO mode used in the PDU
 
    0: SINGLE_ANTENNA_PORT_0, 
    1: TX_DIVERSITY, 
    2: LARGE_DELAY_CDD, 
    3: CLOSED_LOOP_SPATIAL_MULTIPLEXING, 
    4: MULTI_USER_MIMO, 
    5: CLOSED_LOOP_RANK_1_PRECODING, 
    6: SINGLE_ANTENNA_PORT_5.  */
    tOCT_UINT8                  byTransmissionScheme;

    /* The number of layers used in transmission.
    Value: 1 . 4    */    
    tOCT_UINT8                  byNumOfLayers;

    /* Only valid when transmission scheme = 3, 4, 5.
    Defines the number of subbands and codebooks used for PMI. 
    If value=1 then a single PMI value is supplied which should be 
    used over all RB.
    Value 0 -> 13  */
    tOCT_UINT8                  byNumOfSubBand;
    
    /*} */

    /* The UE capabilities category
    Value:1 . 5   */
    tOCT_UINT8                  byUeCatagoryCapacity;

    /* The ratio of PDSCH EPRE to cell-specific RS EPRE among PDSCH REs 
    in all the OFDM symbols not containing cell-specific RS in dB.
    0: -6dB
    1: -4.77dB
    2: -3dB
    3: -1.77dB
    4: 0dB
    5: 1dB
    6: 2dB
    7: 3dB          */
    tOCT_UINT8                  byPA;

    /* Delta power offset, value: 0..1, 
    Refer to: Table 7.1.5-1 in [6] for Multi-user MIMO mode. 
    Takes value zero for all other modes. */
    tOCT_UINT8                  byDeltaPowerOffsetAIndex;

    /* Used in virtual resource block distribution
    0= NGAP1
    1=  NGAP2   */
    tOCT_UINT8                  byNGap;

    /* Used with DCI format 1A and RNTI=SI-RNTI or RA-RNTI. 
    This should match the value sent in the TPC field of the 
    DCI 1A PDU which allocated this grant.
    0: NPRB = 2 
    1: NPRB = 3   */
    tOCT_UINT8                  byNPRB;

    /* Number of PRBs that are treated as one subband */
    tOCT_UINT16                 usNumRbPerSubBand;
    
    /* Number of beam forming vectors
    One beam forming vector is specified for each subband */
    tOCT_UINT16                 usNumbfVector;
 
    /* subBandInfo contains codebook indices per numOfSubBand{ */
    /* Only valid when transmission scheme = 3, 4, 5.
    Defines the codebook used.
    When antenna port = 1: NA
    When antenna port = 2: 0..3
    When antenna port = 4: 0..15   */
    tOCT_UINT8                  abySubBandInfo[mFAPI_VAR_SIZE(byNumOfSubBand)];
   
    /* Beam forming vectors */
    tOCT_FAPI_DL_BEAMFORM_INFO  aBfVector[mFAPI_VAR_SIZE(numbfVector)];

}tOCT_FAPI_DL_SCH_PDU_INFO;

#define SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE ( sizeof(tOCT_UINT16)*5 + \
	   	sizeof(tOCT_UINT8)*14 + sizeof(tOCT_UINT32)*1 )

/* ---------------------------------- */

/* Paging config structure */
typedef struct
{
    /* The length (in bytes) of the associated MAC PDU, delivered in 
    TX.request. This should be the actual length of the MAC PDU, 
    which may not be a multiple of 32-bits. */
    tOCT_UINT16           usPchPduLen;

    /* This is a count value which is incremented every time a BCH, MCH, PCH 
    or DLSCH PDU is included in the DL_CONFIG.request message. This value is 
    repeated in TX.request and associates the control information to the data.
    It is reset to 0 for every subframe.
    Range 0 . 65535   */
    tOCT_UINT16           usPduIndex;

    /* The P-RNTI associated with the paging
    Value: 0xFFFE  */
    tOCT_UINT16           usPRNTI;

    /* Resource allocation type
    2 = type 2  */
    tOCT_UINT8            byResAllocationType;

    /* Type of virtual resource block used. This should match the value sent 
    in the DCI Format 1A, 1B, 1D PDU which allocated this grant.
    0 = localized
    1 = distributed    */
    tOCT_UINT8            byVRBAssignmentFlag;

    /* The encoding for the resource blocks. It's coding is dependent on 
    whether resource allocation type 0, 1, 2 is in use. This should match
    the value sent in the DCI Format PDU which allocated this grant. */
    tOCT_UINT32           ulRbCoding;
   
    /* For PCH PDU only QPSK modulation is allowed.
           This field shall be set to 0x0   */
    tOCT_UINT8            byMcs;

    /* For PCH PDU only redundancy version 0 is allowed
    Value: 0    */
    tOCT_UINT8            byRedundancyVersion;

    /* The number of transport blocks transmitted to this RNTI. 
    Only 1 transport block is sent on the PCH per subframe.
    Value: 1    */
    tOCT_UINT8            byNumOftransportBlocks;

    /* Reserved.  This parameter is not used on the PCH transport channel */
    tOCT_UINT8            byTbToCodeWordSwapFlag;
 
    /* The MIMO mode used in the PDU
    0: SINGLE_ANTENNA_PORT_0, 
    1: TX_DIVERSITY, 
    6: SINGLE_ANTENNA_PORT_5.    */
    tOCT_UINT8            byTransmissionScheme;

    /* The number of layers used in transmission
    Value: 1 . 4    */
    tOCT_UINT8            byNumOfLayers;

    /* Reserved.  This parameter is not used on the PCH transport channel. */
    tOCT_UINT8            byCodeBookIndex;

    /* Reserved.  This parameter is not used on the PCH transport channel. */
    tOCT_UINT8            byUeCatagoryCapacity;

    /* The ratio of PDSCH EPRE to cell-specific RS EPRE among PDSCH REs in 
    all the OFDM symbols not containing cell-specific RS in dB.
    0: -6dB
    1: -4.77dB
    2: -3dB
    3: -1.77dB
    4: 0dB
    5: 1dB
    6: 2dB
    7: 3dB    */
    tOCT_UINT8            byPA;

    /* Used with DCI 1A format. This should match the value sent in the 
    TPC field of the DCI 1A PDU which allocated this grant.
    0: NPRB = 2 
    1: NPRB = 3    */
    tOCT_UINT8            byNPRB;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps.  */
    tOCT_UINT16           usTxPower;
 
}tOCT_FAPI_DL_PCH_PDU_INFO;

#define SIZE_TOCT_FAPI_DL_PCH_PDU_INFO ( sizeof(tOCT_FAPI_DL_PCH_PDU_INFO) )

/* ---------------------------------- */



/* DL CONFIG union */
typedef union 
{

    tOCT_FAPI_DL_DCI_PDU_INFO  DCIPdu;
    tOCT_FAPI_DL_BCH_PDU_INFO  BCHPdu;
    tOCT_FAPI_DL_MCH_PDU_INFO  MCHPdu;
    tOCT_FAPI_DL_SCH_PDU_INFO  DlSCHPdu;
    tOCT_FAPI_DL_PCH_PDU_INFO  PCHPdu;
} tOCT_FAPI_DL_CONFIG_PDU_INFO;

/* ---------------------------------- */

/* DL Config PDU Structure */
typedef struct
{
    /* 0: DCI DL PDU,
    1: BCH PDU, 
    2: MCH PDU,
    3: DLSCH PDU,
    4: PCH PDU */
    tOCT_UINT8     byPduType; /* defined in eFAPI_DL_PDU_TYPE */
    
    /*Size of the PDU control information (in bytes).
    This length value includes the 2 bytes required for the PDU type 
    and PDU size parameters. The size will always be a multiple of 4 bytes. */
    tOCT_UINT8     byPduSize;

    tOCT_UINT8     abyPadding[2];

    tOCT_FAPI_DL_CONFIG_PDU_INFO  dlConfigpduInfo;
}tOCT_FAPI_DL_CONFIG_PDU_LIST;

#define SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE ( sizeof(tOCT_UINT8)*4 )

/* ---------------------------------- */

/* DL TLV Structure */
typedef struct 
{
    /* Range 0 -> 1
    0: Payload is carried directly in the value field
    1: Pointer to payload is in the value field  */
    tOCT_UINT16      usTag;

    /* Length of the payload in bytes */
    tOCT_UINT16      usTagLen;
      
    /* Always a multiple of 32-bits.
    Tag=0: Only the most significant bytes of the size indicated by .length.
    field are valid. Remaining  bytes are zero padded to the nearest 32-bit 
    boundary.
    Tag=1: Pointer to the payload. Occupies 32-bits  */
    tOCT_UINT32      aulValue[mFAPI_VAR_SIZE(tagLen)];

}tOCT_FAPI_DL_PDU_DATA_TLV;

#define SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE ( sizeof(tOCT_UINT16)*2 )

/* ---------------------------------- */

/* DL PDU Info Structure */
typedef struct
{
    /* The total length (in bytes) of the PDU description and PDU data. */
    tOCT_UINT16           usPduLen;
      
    /* This is a count value which starts from 0. It is incremented for each 
    BCH, MCH, PCH or DLSCH PDU. This value was included in TX.request and 
    associates the data to the control information.It is reset to 0 for 
    every subframe.
    Range 0 . 65535 */
    tOCT_UINT16           usPduIndex;

    /* The number of TLVs describing the data of the transport block. */
    tOCT_UINT32           ulNumOfTLV;
      
    /* Always a multiple of 32-bits */
    tOCT_FAPI_DL_PDU_DATA_TLV  aDlTLVInfo[mFAPI_VAR_SIZE(numOfTLV)];

}tOCT_FAPI_DL_PDU_DATA_INFO;

#define SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE ( sizeof(tOCT_UINT16)*2 + sizeof(tOCT_UINT32)*1 )

/* ---------------------------------- */

/* UL HI PDU structure */
typedef struct
{
    /* 0: HI PDU */
    tOCT_UINT8     byPduType;
     
    /* Size of the PDU control information (in bytes).
    This length value includes the 2 bytes required for the PDU type 
    and PDU size parameters.The size will always be a multiple of 4 bytes. */
    tOCT_UINT8     byHipduSize;

    /* This value is the starting resource block assigned to the ULSCH grant 
    associated with this HI response. It should match the value sent in the 
    DCI format 0 which allocated the ULSCH grant
    Value: 0 . 99   */
    tOCT_UINT8     byRbStart;   

    /* This value is the 2nd cyclic shift for DMRS assigned to the ULSCH grant
    associated with this HI response. It should match the value sent in the 
    DCI format 0 which allocated the ULSCH grant
    Value: 0 . 7  */
    tOCT_UINT8     byCyclicShift2forDMRS;

    /* The PHICH value which is sent on the resource.
    0: HI_NACK
    1: HI_ACK     */
    tOCT_UINT8     byHiValue;

    /* Is used in the calculation of the PHICH location. For TDD only.
    1 = TDD subframe configuration 0 is used and the ULSCH grant associated 
    with this HI was received in subframe 4 or 9
    0 = in all other cases   */
    tOCT_UINT8     byIPHICH;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16    usTxPower;

}tOCT_FAPI_UL_HI_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_HI_PDU_INFO ( sizeof(tOCT_FAPI_UL_HI_PDU_INFO) )

/* ---------------------------------- */

/* UL DCI PDU Structure */ 
typedef struct
{
    /* 1: DCI PDU */
    tOCT_UINT8     byPduType;
     
    /* Size of the PDU control information (in bytes).
    This length value includes the 2 bytes required for the PDU type 
    and PDU size parameters.The size will always be a multiple of 4 bytes. */
    tOCT_UINT8      byUlDCIPDUSize; 

    /* Format of the DCI
    0 = 0
    1 = 3
    2 = 3A  */
    tOCT_UINT8     byUlDCIFormat;

    /* CCE index used to send the DCI. 
    Value: 0 . 88   */
    tOCT_UINT8     byCceIndex;

    /* The RNTI used for identifying the UE when receiving the PDU
    Valid for all DCI formats
    Value: 1 . 65535.    */
    tOCT_UINT16    usRnti;

    /* The aggregation level used
    Value: 1,2,4,8   */
    tOCT_UINT8     byAggLevel;

    /* The starting resource block for this ULSCH allocation.
    Valid for DCI format 0
    Value: 0 . 99     */
    tOCT_UINT8     byRbStart;

    /* The number of resource blocks allocated to this ULSCH grant.
    Valid for DCI format 0
    Value: 0 . 100      */
    tOCT_UINT8     byNumOfRB;

    /* The modulation and redundancy version.
    Valid for DCI format 0
    Value: 0 . 31    */
    tOCT_UINT8     byMcs;

    /* The 2nd cyclic shift for DMRS assigned to the UE in the ULSCH grant. 
    Valid for DCI format 0
    Value: 0 . 7    */
    tOCT_UINT8     byCyclicShift2forDMRS;

    /* Indicates if hopping is being used.
    Valid for DCI format 0
    0 = no hopping, 1= hopping enabled    */
    tOCT_UINT8     byFreqHoppingenabledFlag;

    /* The frequency hopping bits
    Valid for DCI format 0
    Value: 0 . 3  */
    tOCT_UINT8     byFreqHoppingBits;

    /* The new data indicator for the transport block.
    Valid for DCI format 0    */
    tOCT_UINT8     byNewDataIndication;

    /* Indicates how the CRC is calculated on the PDCCH.
    Valid for DCI format 0
    0 = Not configured;
    1 = Configured and usIng UE port 0;
    2 = Configured and using UE port 1.   */
    tOCT_UINT8     byUeTxAntennaSelection;

    /* Tx power control command for PUSCH.
    Valid for DCI format 0
    Value:  0,1,2,3 as represented in 36.213 Sec 5.1 for TPC Command Field.
    */
    tOCT_UINT8     byTpc;

    /* Aperiodic CQI request flag
    Valid for DCI format 0
    0 = Aperiodic CQI not requested
    1 = Aperiodic CQI requested    */
    tOCT_UINT8     byCqiRequest;

    /* UL index. Valid for TDD mode only.
    Valid for DCI format 0
    Value: 0,1,2,3    */
    tOCT_UINT8     byUlIndex;

    /* DL assignment index. Valid for TDD mode only.
    Valid for DCI format 0
    Value: 1,2,3,4     */
    tOCT_UINT8     byDlAssignmentIndex;

	/* Aricent reports SNR of received signal here */
	tOCT_UINT8     bySnr;

    tOCT_UINT8     abyPadding[2];
     
	 /* Transmission Power for DCI 0/3/3A PDU */
    tOCT_UINT16    usTxPower;

    /* TPC commands for PUCCH and PUSCH
    Valid for DCI formats: 3,3A   */
    tOCT_UINT32    ulTpcBitMap;

}tOCT_FAPI_UL_DCI_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_DCI_PDU_INFO ( sizeof(tOCT_FAPI_UL_DCI_PDU_INFO) )

/* ---------------------------------- */

/* CQI Information */
typedef struct
{
    /* The PUCCH Index value  
    Value: 0 . 1185    */
    tOCT_UINT16   usPucchIndex; 

    /* The size of the DL CQI/PMI in bits.
    Value: 0 . 255   */
    tOCT_UINT8    byDlCqiPmiSize;

    tOCT_UINT8    abyPadding[1];
}tOCT_FAPI_UL_CQI_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_CQI_PDU_INFO ( sizeof(tOCT_FAPI_UL_CQI_PDU_INFO) )

/* ---------------------------------- */

/* SR Information */
typedef struct
{
    /* The PUCCH Index value  
    Value: 0 . 2047    */
    tOCT_UINT16   usPucchIndex;

}tOCT_FAPI_UL_SR_PDU_INFO;

/* SR Information Ends */
/* ---------------------------------- */

/* TDD Harq Information */
typedef struct
{
    /* For ACK_NACK Mode 0 (Bundling) and 1 (Multiplexing), 
    this is the size of the ACK/NACK in bits.
    Value: 1 . 4
    For Special Bundling this is the expected number of ACK/NACK 
    responses (UDAI + NSPS).
    Value: 0 . 9     */
    tOCT_UINT8   byHarqSize;

    /* The format of the ACK/NACK response expected. For TDD only.
    0 = BUNDLING
    1 = MULTIPLEXING        */
    tOCT_UINT8   byAcknackMode;

    /* The number of ACK/NACK responses received in this subframe. 
    For TDD only. 
    Value: 0 . 4
    (Value 0 is only valid for Special Bundling.)   */
    tOCT_UINT8   byNumOfPUCCHResource;

    tOCT_UINT8   abyPadding[1];

    /* SPR 1680 changes start*/
    /* HARQ resource 0, value: 0 . 2047 */
    tOCT_UINT16   usN_PUCCH_1_0;

    /* HARQ resource 1, value: 0 . 2047 */
    tOCT_UINT16   usN_PUCCH_1_1;

    /* HARQ resource 2, value: 0 . 2047 */
    tOCT_UINT16   usN_PUCCH_1_2;

    /* HARQ resource 3, value: 0 . 2047 */
    tOCT_UINT16   usN_PUCCH_1_3;
    /* SPR 1680 changes end*/

}tOCT_FAPI_UL_HARQ_PDU_INFO_TDD;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_INFO_TDD ( sizeof(tOCT_FAPI_UL_HARQ_PDU_INFO_TDD) )

/* TDD Harq Information Ends */
/* ---------------------------------- */

/* FDD Harq Information */
typedef struct
{
    /* The PUCCH Index value for ACK/NACK
    Value: 0 . 2047    */
    tOCT_UINT16  usPucchIndex;

    /*  The size of the ACK/NACK in bits.
    Value: 1 . 2   */
    tOCT_UINT8   byHarqSize;

    tOCT_UINT8   abyPadding[1];
}tOCT_FAPI_UL_HARQ_PDU_INFO_FDD;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_INFO_FDD ( sizeof(tOCT_FAPI_UL_HARQ_PDU_INFO_FDD) )

/* FDD Harq Information Ends */
/* ---------------------------------- */

/* SRS PDU */
typedef struct
{
    /* An opaque handling returned in the SRS.indication */
    tOCT_UINT32      ulHandle;
    
    /* The size of the PDU in bytes. */
    tOCT_UINT16      usSize;
    
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16      usRnti;

    /* SRS Bandwidth. This value is fixed for a UE and allocated in 
    RRC connection setup.
    Value: 0 . 3   */
    tOCT_UINT8       bySrsBandWidth;

    /* Frequency-domain position, NRRC This value is fixed for a UE and 
    allocated in RRC connection setup.
    Value: 0 . 23    */
    tOCT_UINT8       byFreqDomainPosition;

    /* Configures the frequency hopping on the SRS. This value is fixed 
    for a UE and allocated in RRC connection setup.
    Value 0 . 3    */
    tOCT_UINT8       bySrsHoppingBandWidth;

    /* Configures the frequency location of the SRS. 
    This value is fixed for a UE and allocated in RRC connection setup.
    Value: 0 .  1    */
    tOCT_UINT8       byTransmissionComb;

    /* Defines the periodicity and subframe location of the SRS.
    SRS Configuration Index. This value is fixed for a UE and 
    allocated in RRC connection setup.
    Value: 0 . 1023.   */
    tOCT_UINT16       usIsrsSRSConfigIndex;

    /* Configures the SRS sequence generation. This value is fixed for a UE 
    and allocated in RRC connection setup.
    Value: 0 . 7    */
    tOCT_UINT8       bySoundingRefCyclicShift;

    tOCT_UINT8       abyPadding[1];
}tOCT_FAPI_UL_SRS_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_SRS_PDU_INFO ( sizeof(tOCT_FAPI_UL_SRS_PDU_INFO) )

/* SRS PDU Ends */
/* ---------------------------------- */

/* CQI_RI information */
typedef struct
{
    /* The size of the DL CQI/PMI in bits in case of rank 1 report.
    Value: 0 . 255   */
    tOCT_UINT8     byDlCqiPmiSizeRank_1;

    /* The size of the DL CQI/PMI in bits in case of rank>1 report.
    Value: 0 . 255   */
    tOCT_UINT8     byDlCqiPmiSizeRankGT_1;

    /* The size of RI in bits
    Value:0, 1 and 2    */
    tOCT_UINT8     byRiSize;

    /* Delta offset for CQI. This value is fixed for a UE and allocated in 
    RRC connection setup.
    Value: 0 . 15    */
    tOCT_UINT8     byDeltaOffsetCQI;

    /* Delta offset for RI. This value is fixed for a UE and allocated in 
    RRC connection setup.
    Value: 0 . 15     */
    tOCT_UINT8     byDeltaOffsetRI;

    tOCT_UINT8     abyPadding[3];
}tOCT_FAPI_UL_CQI_RI_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_CQI_RI_PDU_INFO ( sizeof(tOCT_FAPI_UL_CQI_RI_PDU_INFO) )

/* CQI_RI information Ends */
/* ---------------------------------- */

/* UCI_SR PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32            ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16            usRnti;

    tOCT_FAPI_UL_SR_PDU_INFO  srInfo;

}tOCT_FAPI_UCI_SR_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_SR_PDU_INFO ( sizeof(tOCT_FAPI_UCI_SR_PDU_INFO) )

/* UCI_SR PDU Ends */
/* ---------------------------------- */

/* UCI_CQI PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32            ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16            usRnti;

    tOCT_UINT8             abyPadding[2];

    tOCT_FAPI_UL_CQI_PDU_INFO cqiInfo;

}tOCT_FAPI_UCI_CQI_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_CQI_PDU_INFO ( sizeof(tOCT_FAPI_UCI_CQI_PDU_INFO)  )

/* UCI_CQI PDU Ends */
/* ---------------------------------- */

/* UCI_HARQ PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_UINT8                  abyPadding[2];
    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_FDD     harqInfo;

}tOCT_FAPI_UCI_HARQ_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_HARQ_PDU_INFO ( sizeof(tOCT_FAPI_UCI_HARQ_PDU_INFO) )

/* UCI_HARQ PDU Ends */
/* ---------------------------------- */

/* UCI_HARQ PDU TDD */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_UINT8                  abyPadding[2];
    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_TDD     harqInfo;

}tOCT_FAPI_UCI_HARQ_PDU_INFO_TDD;

#define SIZE_TOCT_FAPI_UCI_HARQ_PDU_INFO_TDD ( sizeof(tOCT_FAPI_UCI_HARQ_PDU_INFO_TDD) )

/* UCI_HARQ PDU TDD Ends */
/* ---------------------------------- */


/* UCI_SR_HARQ PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_FAPI_UL_SR_PDU_INFO       srInfo;

    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_FDD     harqInfo;

}tOCT_FAPI_UCI_SRHARQ_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_SRHARQ_PDU_INFO ( sizeof(tOCT_FAPI_UCI_SRHARQ_PDU_INFO) )

/* UCI_SR_HARQ PDU Ends */
/* ---------------------------------- */

/* UCI_SR_HARQ TDD PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_FAPI_UL_SR_PDU_INFO       srInfo;

    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_TDD     harqInfo;

}tOCT_FAPI_UCI_SRHARQ_PDU_INFO_TDD;

#define SIZE_TOCT_FAPI_UCI_SRHARQ_PDU_INFO_TDD ( sizeof(tOCT_FAPI_UCI_SRHARQ_PDU_INFO_TDD)  )

/* UCI_SR_HARQ TDD PDU Ends */
/* ---------------------------------- */


/* UCI_CQI_HARQ PDU */

typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    tOCT_FAPI_UL_CQI_PDU_INFO       cqiInfo;

    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_UINT8                  abyPadding[2];

    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_FDD     harqInfo;

}tOCT_FAPI_UCI_CQIHARQ_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_CQIHARQ_PDU_INFO ( sizeof(tOCT_FAPI_UCI_CQIHARQ_PDU_INFO)  )

/* UCI_CQI_HARQ PDU Ends */
/* ---------------------------------- */

/* UCI_CQI_HARQ TDD PDU */

typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    tOCT_FAPI_UL_CQI_PDU_INFO   cqiInfo;

    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_UINT8                  abyPadding[2];

    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_TDD     harqInfo;

}tOCT_FAPI_UCI_CQIHARQ_PDU_INFO_TDD;

#define SIZE_TOCT_FAPI_UCI_CQIHARQ_PDU_INFO_TDD ( sizeof(tOCT_FAPI_UCI_CQIHARQ_PDU_INFO_TDD)  )

/* UCI_CQI_HARQ TDD PDU Ends */
/* ---------------------------------- */


/* UCI_CQI_SR PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_FAPI_UL_CQI_PDU_INFO      cqiInfo;

    tOCT_FAPI_UL_SR_PDU_INFO       srInfo;

}tOCT_FAPI_UCI_CQISR_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_CQISR_PDU_INFO ( sizeof(tOCT_FAPI_UCI_CQISR_PDU_INFO)  )

/* UCI_CQI_SR PDU Ends */
/* ---------------------------------- */

/* UCI_CQI_SR HARQ_PDU */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_FAPI_UL_SR_PDU_INFO       srInfo;

    tOCT_FAPI_UL_CQI_PDU_INFO      cqiInfo;
       
    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_FDD     harqInfo;

}tOCT_FAPI_UCI_CQISRHARQ_PDU_INFO;

#define SIZE_TOCT_FAPI_UCI_CQISRHARQ_PDU_INFO ( sizeof(tOCT_FAPI_UCI_CQISRHARQ_PDU_INFO)  )

/* UCI_CQI_SR HARQ_PDU  Ends */
/* ---------------------------------- */

/* UCI_CQI_SR HARQ_PDU TDD */
typedef struct
{
    /* An opaque handling returned in the RX_CQI.indication */
    tOCT_UINT32                 ulHandle;
       
    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535.   */
    tOCT_UINT16                 usRnti;

    tOCT_FAPI_UL_SR_PDU_INFO       srInfo;

    tOCT_FAPI_UL_CQI_PDU_INFO      cqiInfo;
       
    /* depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_INFO_TDD     harqInfo;

}tOCT_FAPI_UCI_CQISRHARQ_PDU_INFO_TDD;

#define SIZE_TOCT_FAPI_UCI_CQISRHARQ_PDU_INFO_TDD ( sizeof(tOCT_FAPI_UCI_CQISRHARQ_PDU_INFO_TDD)  )

/* UCI_CQI_SR HARQ_PDU TDD  Ends */
/* ---------------------------------- */


/* ULSCH PDU */
typedef struct 
{
    /* An opaque handling returned in the RX.indication */ 
    tOCT_UINT32      ulHandle;
     
    /* The size of the ULSCH PDU in bytes as defined by the relevant UL grant.
    The size can be 0 if UCI over ULSCH without data is configured. 
    The size of CQI/RI/HARQ are not added to this element. */
    tOCT_UINT16       usSize;

    /* The RNTI used for identifying the UE when receiving the PDU
    Value: 1 . 65535. */
    tOCT_UINT16       usRnti;

    /* The starting resource block for this ULSCH allocation. 
    This should match the value sent in the DCI Format 0 PDU 
    which allocated this grant.
    Value: 0 . 99    */
    tOCT_UINT8       byRbStart;

    /* The number of resource blocks allocated to this ULSCH grant. 
    This should match the value sent in the DCI Format 0 PDU 
    which allocated this grant.
    Value: 1 . 100    */
    tOCT_UINT8       byNumOfRB;

    /* 2: QPSK
    4: 16QAM
    6: 64QAM   */
    tOCT_UINT8       byModulationType;

    /* The 2nd cyclic shift for DMRS assigned to the UE in the ULSCH grant. 
    This should match the value sent in the DCI Format 0 PDU 
    which allocated this grant.
    Value: 0 . 7 */
    tOCT_UINT8       byCyclicShift2forDMRS;

    /* Indicates if hopping is being used. This should match the value 
    sent in the DCI Format 0 PDU which allocated this grant.
    0 = no hopping, 1= hopping enabled   */
    tOCT_UINT8       byFreqHoppingenabledFlag;

    /* The frequency hopping bits. This should match the value sent in 
    the DCI Format 0 PDU which allocated this grant.
    Value: 0 . 3      */
    tOCT_UINT8       byFreqHoppingBits;

    /* Specify whether this received PUSCH is a new transmission from UE. 
    This should match the value sent in the DCI Format 0 PDU which 
    allocated this grant. */
    tOCT_UINT8       byNewDataIndication;

    /* Redundancy version
    Value: 0 . 3  */
    tOCT_UINT8       byRedundancyVersion;

    /* HARQ Process number.
    TDD 0 . 15
    FDD 0 . 7   */
    tOCT_UINT8       byHarqProcessNumber;

    /* 0 = SISO/SIMO
    1 = MIMO     */
    tOCT_UINT8       byUlTxMode;

    /* The current HARQ transmission count of this transport block. 
    Valid if frequency hopping enabled. */
    tOCT_UINT8       byCurrentTxNB;

    /* Indicates if the resource blocks allocated for this grant 
    overlap with the SRS configuration.
    0 = no overlap
    1 = overlap     */
    tOCT_UINT8       byNSRS;

}tOCT_FAPI_UL_SCH_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_SCH_PDU_INFO ( sizeof(tOCT_FAPI_UL_SCH_PDU_INFO) )

/* ULSCH PDU Ends */
/* ---------------------------------- */

/* Initial transmission parameters */
typedef struct
{
    /* 0 = last OFDM symbol is not punctured
    1 = last OFDM symbol is punctured. */
    tOCT_UINT8  byNSRSInitial;

    /* The number of resource blocks used in the initial transmission 
    of this transport block.
    Value: 1 . 100    */
    tOCT_UINT8  byInitialNumOfRB;

    tOCT_UINT8  abyPadding[2];
}tOCT_FAPI_UL_INITIAL_TX_PARAM;

#define SIZE_TOCT_FAPI_UL_INITIAL_TX_PARAM ( sizeof(tOCT_FAPI_UL_INITIAL_TX_PARAM) )

/* Initial transmission parameters Ends */
/* ---------------------------------- */

typedef struct
{
    /*The size of the ACK/NACK in bits Value 1-2*/
    tOCT_UINT8         byHarqSize;
    /*Delta offset for HARQ. This value is fixed for a UE and allocated in
    *RRC connection setup. Value: 0-15*/
    tOCT_UINT8         byDeltaOffsetHarq;
    /*The format of the ACK/NACK response expected. For TDD only.
    * 0 = BUNDLING
    * 1 = MULTIPLEXING
    * */
    tOCT_UINT8         byAckNackMode;
    tOCT_UINT8         abyPadding[1];
} tOCT_FAPI_UL_SCH_HARQ_INFO;

#define SIZE_TOCT_FAPI_UL_SCH_HARQ_INFO ( sizeof(tOCT_TOCT_FAPI_UL_SCH_HARQ_INFO) )

/* ---------------------------------- */
/* ULSCH_CQI_HARQ_RI PDU */
typedef struct
{
    tOCT_FAPI_UL_SCH_PDU_INFO      ulSCHPduInfo;

    tOCT_FAPI_UL_CQI_RI_PDU_INFO      cqiRiInfo;

    tOCT_FAPI_UL_SCH_HARQ_INFO      harqInfo;

    tOCT_FAPI_UL_INITIAL_TX_PARAM    initialTxParamInfo;

}tOCT_FAPI_UL_SCH_CQIRIHARQ_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_SCH_CQIRIHARQ_PDU_INFO ( tOCT_FAPI_UL_SCH_CQIRIHARQ_PDU_INFO  )

/* ULSCH_CQI_HARQ_RI PDU Ends */
/* ---------------------------------- */
    
/* ---------------------------------- */
/* ULSCH_HARQ PDU */
typedef struct
{
    tOCT_FAPI_UL_SCH_PDU_INFO       ulSCHPduInfo;
       
    tOCT_FAPI_UL_SCH_HARQ_INFO      harqInfo;

    tOCT_FAPI_UL_INITIAL_TX_PARAM     initialTxParamInfo;

}tOCT_FAPI_UL_SCH_HARQ_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_SCH_HARQ_PDU_INFO ( tOCT_FAPI_UL_SCH_HARQ_PDU_INFO )

/* ULSCH_HARQ PDU  Ends */
/* ---------------------------------- */

/* ULSCH_CQI_RI PDU */
typedef struct
{
    tOCT_FAPI_UL_SCH_PDU_INFO           ulSCHPduInfo;

    tOCT_FAPI_UL_CQI_RI_PDU_INFO           cqiRiInfo;

    tOCT_FAPI_UL_INITIAL_TX_PARAM         initialTxParamInfo;

}tOCT_FAPI_UL_SCH_CQIRI_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_SCH_CQIRI_PDU_INFO ( sizeof(tOCT_FAPI_UL_SCH_CQIRI_PDU_INFO) )

/* ULSCH_CQI_RI PDU Ends */
/* ---------------------------------- */

/* HARQ BUFFER PDU */
typedef struct
{
    tOCT_UINT32     ulHandle;
    
    tOCT_UINT16     usRnti;
    
    tOCT_UINT8      abyPadding[2]; 

}tOCT_FAPI_UL_SCH_HARQ_BUFFER_RELEASE_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_SCH_HARQ_BUFFER_RELEASE_PDU_INFO ( sizeof(tOCT_FAPI_UL_SCH_HARQ_BUFFER_RELEASE_PDU_INFO) )

/* HARQ BUFFER PDU Ends*/

/* ---------------------------------- */

/* UL CONFIG PDU Structure */
typedef struct 
{
    /* 0: ULSCH,
    1 : ULSCH_CQI_RI,
    2 : ULSCH_HARQ,
    3 : ULSCH_CQI_HARQ_RI,
    4 : UCI_CQI,
    5 : UCI_SR, 
    6 : UCI_HARQ,
    7 : UCI_SR_HARQ,
    8 : UCI_CQI_HARQ,
    9 : UCI_CQI_SR,
    10: UCI_CQI_SR_HARQ,
    11: SRS 
    12: HARQ BUFFER RELEASE */
    tOCT_UINT8  byUlConfigPduType; /*Tags are defined in
    FAPI_ulConfigPduInfo_en */

    /* Size of the PDU control information (in bytes).
    This length value includes the 2 bytes required for the PDU type 
    and PDU size parameters.The length will always be a multiple of 4 bytes. */
    tOCT_UINT8  byUlConfigPduSize;

    tOCT_UINT8  abyPadding[2];

    /* need to typecase it with appropriate 
    UL CONFIG PDU TYPE (ulConfigPduType)*/
    tOCT_UINT8  abyUlPduConfigInfo[mFAPI_VAR_SIZE(x)];

}tOCT_FAPI_UL_CONFIG_PDU_INFO;

#define SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE ( sizeof(tOCT_UINT8)*4 )

/* ---------------------------------- */

/* UL DATA PDU Structure */
typedef struct
{
    /* The handle received in the ULSCH PDU. */
    tOCT_UINT32     ulHandle;
	
    /* The RNTI passed to the PHY in a DL_CONFIG.request ULSCH PDU 
    Value: 1 . 65535. */
    tOCT_UINT16     usRnti;
	
    /* Length of PDU in byTes. */
    tOCT_UINT16     usLength;
    
    /* Gives the PDU#i data address offset from the beginning of the 
    'Number of PDUs' field.An offset of 0 indicates a CRC or decoding error. */
    tOCT_UINT16     usDataOffset;
	
    /* The timing advance measured for this PDU and UE.
    Value: 0 .. 1282   */
    tOCT_UINT16     usTimingAdvance;
	
    /* SNR 
    Value: 0-255, representing -64dB to 63.5dB, with 0.5dB step size. */
    tOCT_UINT8      byUlCqi;
	
	/* Indicates the possibility of saturation
	Value: 0x1 -> Possibility of saturation high 0x0 -> Possibility of saturation low 
	Note: Octasic specific field using FAPI padding. */
    tOCT_UINT8    	byUlSaturationFlag;
	
	/* PUSCH RSSI expressed in dBm in Q7 format
	Value: -6400 to -15360, representing -50 .. -120 dBm
	Example:  Value -10240 represents -80 dBm
	Note: Octasic specific field using FAPI padding. */
	tOCT_INT16		sUlRssi;
	
}tOCT_FAPI_UL_DATA_PDU_IND;

#define SIZE_TOCT_FAPI_UL_DATA_PDU_IND (sizeof(tOCT_FAPI_UL_DATA_PDU_IND))

/* ---------------------------------- */

/* FDD HARQ PDU Info Structure */
typedef struct 
{
    tOCT_UINT32 ulHandle;
    
	/* The RNTI passed to the PHY in an uplink subframe configuration PDU. 
    Value: 1 . 65535.  */
    tOCT_UINT16   usRnti;

    /* HARQ feedback of 1st TB.
    Range 1 . 7
    1 = ACK
    2 = NACK
    3 = ACK or NACK
    4 = DTX
    5 = ACK or DTX
    6 = NACK or DTX
    7 = ACK or NACK or DTX   */
    tOCT_UINT8    byHarqTB1;
    
    /* HARQ feedback of 2nd TB. 
    Range 1 . 7
    1 = ACK
    2 = NACK
    3 = ACK or NACK
    4 = DTX
    5 = ACK or DTX
    6 = NACK or DTX
    7 = ACK or NACK or DTX   */
    tOCT_UINT8    byHarqTB2;

}tOCT_FAPI_UL_HARQ_PDU_IND_FDD;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_FDD (sizeof(tOCT_FAPI_UL_HARQ_PDU_IND_FDD))

/* ---------------------------------- */

/* TDD Bundling type harq info structure */ 
typedef struct
{
    /* Indicates HARQ results. 
    Range 1 . 7
    1 = ACK
    2 = NACK
    3 = ACK or NACK
    4 = DTX
    5 = ACK or DTX
    6 = NACK or DTX
    7 = ACK or NACK or DTX    */
    tOCT_UINT8  byValue0;

    /* Indicates HARQ results. Range 1 . 7 same as above */
    tOCT_UINT8  byValue1;

    tOCT_UINT8  abyPadding[2];

}tOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING (sizeof(tOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING))


/* ---------------------------------- */

/* TDD multiplexing type harq info structure */ 
typedef struct
{
    /* Indicates HARQ results. 
    Range 1 . 7
    1 = ACK
    2 = NACK
    3 = ACK or NACK
    4 = DTX
    5 = ACK or DTX
    6 = NACK or DTX
    7 = ACK or NACK or DTX    */
    tOCT_UINT8  byValue0;

    /* Indicates HARQ results. Range 1 . 7 same as above */
    tOCT_UINT8  byValue1;

    /* Indicates HARQ results. Range 1 . 7 same as above */
    tOCT_UINT8  byValue2;

    /* Indicates HARQ results. Range 1 . 7 same as above */
    tOCT_UINT8  byValue3;

}tOCT_FAPI_UL_HARQ_PDU_IND_TDD_MULTIPLEXING;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_TDD_MULTIPLEXING (sizeof(tOCT_FAPI_UL_HARQ_PDU_IND_TDD_MULTIPLEXING))

/* ---------------------------------- */

/* TDD Special type harq info structure */ 
typedef struct
{
    /* Number of ACK among multiple ACK/NACK responses 
    0 = 0 or None (UE detect at least one DL assignment is missed)
    1 = 1 or 4 or 7 ACKs reported
    2 = 2 or 5 or 8 ACKs reported
    3 = 3 or 6 or 9 ACKs reported
    4 = DTX (UE did not transmit anything)  */
    tOCT_UINT8  byValue0;

    tOCT_UINT8  abyPadding[3];
	
}tOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING_SPECIAL;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING_SPECIAL (sizeof(tOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING_SPECIAL))

typedef union
{
	tOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING			tddBundling;
	tOCT_FAPI_UL_HARQ_PDU_IND_TDD_MULTIPLEXING		tddMultiplexing;
	tOCT_FAPI_UL_HARQ_PDU_IND_TDD_BUNDLING_SPECIAL	tddBundlingSpecial;
	
}tOCT_FAPI_UL_HARQ_PDU_IND_TDD_HARQ_TYPES;

// ?? GM
#define SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_TDD_HARQ_TYPES (sizeof(tOCT_UINT32)*3)

/* ---------------------------------- */

/* TDD HARQ PDU Info Structure */
typedef struct
{
    /* The handle received in the ULSCH PDU or UCI PDU. */
    tOCT_UINT32    ulHandle;

    /* The RNTI passed to the PHY in an uplink subframe configuration PDU. 
    Value: 1 . 65535.  */
    tOCT_UINT16    usRnti;

    /* The format of the ACK/NACK response expected. The bundling and 
    multiplexing options are passed to the PHY in an uplink subframe 
    configuration PDU. If the ACK/NACK is combined with either CQI or SR 
    information then a special ACK/NACK encoding is used which reports 
    the number of ACKs, rather than providing specific ACK/NACK values. 
    This is identified separately and called SPECIAL_BUNDLING in this API. 
    0 = BUNDLING
    1 = MULTIPLEXING   
    2 = SPECIAL BUNDLING */
    tOCT_UINT8     byMode;

    /* The number of ACK/NACK results reported for this UE.
    Value: 1 . 4 
    For Special Bundling this is the expected number of ACK/NACK 
    responses (UDAI + NSPS).
    Value: 0 . 9  */
    tOCT_UINT8     byNumOfAckNack;

    /* The format of the data is dependent on the HARQ mode; 
    BUNDLING, MULTIPLEXING, or SPECIAL BUNDLING.  
    need to typecast it with appropriate TTD Harq structures
    defined above */
    tOCT_FAPI_UL_HARQ_PDU_IND_TDD_HARQ_TYPES     tddHarqResult;
	
}tOCT_FAPI_UL_HARQ_PDU_IND_TDD;

#define SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_TDD ( sizeof(tOCT_UINT32)*1 + \
		sizeof(tOCT_UINT16)*1 + sizeof(tOCT_UINT8)*2 +\
		SIZE_TOCT_FAPI_UL_HARQ_PDU_IND_TDD_HARQ_TYPES )

/* ---------------------------------- */

/* CRC PDU Structure */
typedef struct
{
    /* The handle received in the ULSCH PDU */
    tOCT_UINT32    ulHandle;

    /* The RNTI passed to the PHY in an uplink subframe configuration PDU. 
    Value: 1 . 65535.  */
    tOCT_UINT16    usRnti;

    /* A flag indicating if a CRC error was detected.
    0: CRC_CORRECT
    1:CRC_ERROR   */
    tOCT_UINT8     byCrcFlag;

    tOCT_UINT8     abyPadding[1];
	
}tOCT_FAPI_UL_CRC_PDU_IND;

#define SIZE_TOCT_FAPI_UL_CRC_PDU_IND (sizeof(tOCT_FAPI_UL_CRC_PDU_IND))

/* ---------------------------------- */

/* SR PDU Structure */
typedef struct
{
    /* The handle received in the ULSCH PDU */
    tOCT_UINT32    ulHandle;

    /* The RNTI passed to the PHY in an uplink subframe configuration PDU. 
    Value: 1 . 65535.  */
    tOCT_UINT16    usRnti;

    tOCT_UINT8     abyPadding[2];
}tOCT_FAPI_UL_SR_PDU_IND;

#define SIZE_TOCT_FAPI_UL_SR_PDU_IND (sizeof(tOCT_FAPI_UL_SR_PDU_IND))

/* ---------------------------------- */

/* CQI Indication structure */
typedef struct 
{
    /* The handle received in the ULSCH PDU or UCI PDU.*/
    tOCT_UINT32    ulHandle;
	
    /* The RNTI identifying the UE. For semi-static information held in the MAC
    this will be the value passed to the PHY in a UL_CONFIG.request CQI PDU.  
    Value: 1 . 65535.  */
    tOCT_UINT16    usRnti;
	
    /* Length of PDU in byTes. */
    tOCT_UINT16    usLength;
	
    /* Gives the PDU#i data address offset from the beginning of the 
    'Number of PDUs' field. An offset of 0 indicates a CRC or decoding error, 
    or only RI received on PUSCH. */
    tOCT_UINT16    usDataOffset;
	
    /* The timing advance measured for this PDU and UE.
    Value: 0 .. 1282   */
    tOCT_UINT16  usTimingAdvance;
	
    /* SNR 
    Value: 0-255, representing -64dB to 63.5dB, 
    with 0.5dB step size.   */
    tOCT_UINT8    byUlCqi;
	
    /* The rank indication reported by the UE on PUSCH
    Value: 0..4
    0 = RI not received
    1..4 = RI value    */
    tOCT_UINT8   byRi;
	
	/* Indicates the possibility of saturation
	Value: 0x1 -> Possibility of saturation high 0x0 -> Possibility of saturation low.
	Note: Octasic specific field using FAPI padding. */
    tOCT_UINT8    	byUlSaturationFlag;
	
	tOCT_UINT8      abyPadding[1];
	
}tOCT_FAPI_UL_CQI_PDU_IND;

#define SIZE_TOCT_FAPI_UL_CQI_PDU_IND (sizeof(tOCT_FAPI_UL_CQI_PDU_IND))

/* ---------------------------------- */

/* RACH PDU Structure */
typedef struct
{
    /* The RA-RNTI value. 
    Value: 1 .. 65535.  */
    tOCT_UINT16    usRnti;
	
    /* The measured timing advance for the preamble. 
    Value: 0 . 1282   */
    tOCT_UINT16    usTimingAdvance;
	
    /* The detected preamble
    Value: 0 .. 63  */
    tOCT_UINT8     byPreamble;
	
	/* SNR 
	Value: 0 .. 255, representing -64dB to 63.5dB, 
	with 0.5dB step size.
	Note: Octasic specific field using FAPI padding. */
    tOCT_UINT8      bySnr;
	
	/* PUSCH RSSI expressed in dBm in Q7 format
	Value: -6400 to -15360, representing -50 .. -120 dBm
	Example: Value -10240 represents -80 dBm
	Note: Octasic specific field using FAPI padding. */
    tOCT_INT16     usRssi;
	
}tOCT_FAPI_UL_PRACH_PDU_IND;

#define SIZE_TOCT_FAPI_UL_PRACH_PDU_IND ( sizeof(tOCT_FAPI_UL_PRACH_PDU_IND)  )

/* ---------------------------------- */

/* SRS PDU Structure */
typedef struct
{
    /* The handle received in the SRS PDU. */
    tOCT_UINT32    ulHandle;
	
    /* The RNTI passed to the PHY in an uplink subframe configuration PDU */
    tOCT_UINT16    usRnti;
	
    /* FFS.  Values: 0 . 255, */
    tOCT_UINT16    usDopplerEstimation; 
	
    /* The timing advance measured for the UE.
    Value: T_A from 0 to 1282 */
    tOCT_UINT16    usTimingAdvance;
	
    /* Number of resource blocks to be reported for this UE */
    tOCT_UINT8     byNumOfRB;
	
    /* The starting point of the RBs to be reported.  */
    tOCT_UINT8     byRbStart;
	
    /* Field size dependent on configured bandwidth
    SNR for RBs, each RBs report one SNR. 
    Value: 0-255, representing -64dB to 63.5dB, with 0.5dB step size..*/
    tOCT_UINT8     abySnr[mFAPI_VAR_SIZE(byNumOfRB)];
	
}tOCT_FAPI_UL_SRS_PDU_IND;

#define SIZE_TOCT_FAPI_UL_SRS_PDU_IND_BASE ( sizeof(tOCT_UINT32)*1 + \
		sizeof(tOCT_UINT16)*3 + sizeof(tOCT_UINT8)*2 )

/* ---------------------------------- */

/* For error codes FAPI_SFN_OUT_OF_SYNC and FAPI_MSG_INVALID_SFN */
typedef struct
{
    /* The SFN/SF value received in the message */
    tOCT_UINT16  usRecvdSfnSf;
	
    /* The SFN/SF value the PHY was expecting to receive in the message */
    tOCT_UINT16  usExpectedSfnSf;
	
}tOCT_FAPI_ERR_MSG_TYPE_1;
#define SIZE_TOCT_FAPI_ERR_MSG_TYPE_1 ( sizeof(tOCT_FAPI_ERR_MSG_TYPE_1) )


/* if error codes is FAPI_MSG_PDU_ERR */
typedef struct
{
    tOCT_UINT8    bySubErrCode;
	
    /* Indicates if this error was in a DL subframe configuration or an 
    UL subframe configuration.
    0 = DL, 1 = UL */
    tOCT_UINT8    byDirection;  
	
    /* The RNTI in the received PDU. If the error occurred in a MCH, or BCH, 
    PDU this value is set to 0  */
    tOCT_UINT16   usRnti;
	
    /* The PDU Type  parameter specified in both DL_CONFIG.request and 
    UL_CONFIG.request   */
    tOCT_UINT8   byPduType;
	
    tOCT_UINT8   abyPadding[1];
	
}tOCT_FAPI_ERR_MSG_TYPE_2;
#define SIZE_TOCT_FAPI_ERR_MSG_TYPE_2 ( sizeof(tOCT_FAPI_ERR_MSG_TYPE_2) )

/* if error codes is FAPI_MSG_HI_ERR */
typedef struct
{
    tOCT_UINT8   bySubErrCode;
	
    /* The PHICH RB Index parameters specified in each HI PDU */
    tOCT_UINT8   byPhichLowestulRbIndex;
	
}tOCT_FAPI_ERR_MSG_TYPE_3;
#define SIZE_TOCT_FAPI_ERR_MSG_TYPE_3 ( sizeof(tOCT_FAPI_ERR_MSG_TYPE_3))

/* if error codes is FAPI_MSG_TX_ERR */
typedef struct
{
    tOCT_UINT8   bySubErrCode;
	
    /* The PDU index parameter specified for each PDU */
    tOCT_UINT8   byPduIndex;
	
}tOCT_FAPI_ERR_MSG_TYPE_4;
#define SIZE_TOCT_FAPI_ERR_MSG_TYPE_4 ( sizeof(tOCT_FAPI_ERR_MSG_TYPE_4))

typedef struct
{
	// Takes values from e{DL_PDCCH/DL_PDSCH/UL/UL_RFI/DL_RFI}_HANDLER_ERROR_CODES
    tOCT_UINT16	 usErrCode[5];
	
}tOCT_FAPI_ERR_MSG_TYPE_5;
#define SIZE_TOCT_FAPI_ERR_MSG_TYPE_5 (sizeof(tOCT_FAPI_ERR_MSG_TYPE_5))

/* Union of all message body types */
typedef union
{
    tOCT_FAPI_ERR_MSG_TYPE_1 msgBody1;
    
    tOCT_FAPI_ERR_MSG_TYPE_2 msgBody2;
    
    tOCT_FAPI_ERR_MSG_TYPE_3 msgBody3;
    
    tOCT_FAPI_ERR_MSG_TYPE_4 msgBody4;
	
	tOCT_FAPI_ERR_MSG_TYPE_5 msgBody5;
	
} tOCT_FAPI_ERR_MSG;

/* Message definition starts from here */

/*  ------------------------------- */
/* 
 * Every message changed betweem MAC/L3 and PHY shall follow this format
 */
typedef struct
{
    /* Message type ID */
    tFAPI_MSG_ID  msgId;
    
    /* Length of vendor-specific message body (bytes) */
    tOCT_UINT8    byLenVendorSpecific; 
	
    /* Length of message body (bytes) */
    tOCT_UINT16   usMsgLen;
	
    /* Message body.
    * This shall contain one of the below mentioned structure.
    * Each of the below mentioned structure are specific to
    * different message type */
    tOCT_UINT8    abyMsgBody[mFAPI_VAR_SIZE(msgLen)];
	
    /* Vendor-specific message body */
    tOCT_UINT8    abyVendorMsgBody[mFAPI_VAR_SIZE(lenVendorSpecific)];
	
}tOCT_FAPI_L1_API_MSG;

#define SIZE_TOCT_FAPI_L1_API_MSG ( sizeof(tFAPI_MSG_ID) + sizeof(tOCT_UINT8) + \
			sizeof(tOCT_UINT16) )

/* in Param request we need to fill only msgId of struct tOCT_FAPI_L1_API_MSG */
/* The message length in the generic header = 0. */ 

/* PHY_PARAM_REQUEST: PARAM Request*/

/*  ------------------------------- */
/* PHY PARAM RESPONSE: This defines the message body for PHY_PARAM_RESPONSE
 * API */
typedef struct
{
	/* possible error codes are defined in eFAPI_L1ERRORCODES */
	tOCT_UINT8                     byErrorCode;     
	tOCT_UINT8                     byNumOfTlv;
	tOCT_UINT8                     abyPadding[2];
	
	tOCT_FAPI_PARAM_RESPONSE_TLV   aTlvs[mFAPI_VAR_SIZE(numOfTlv)];
	
}tOCT_FAPI_PARAM_RESPONSE_V1PT1;

#define SIZE_TOCT_FAPI_PARAM_RESPONSE_V1PT1_BASE ( 4 * sizeof(tOCT_UINT8) )

/*  ------------------------------- */


/* PHY CELL CONFIG REQUEST:This defines the message body for
 * PHY_CELL_CONFIG_REQUEST */

typedef struct
{
    tOCT_UINT8               byNumOfTlv;
	
    tOCT_UINT8               abyPadding[3];
    /* Please refer FAPI document to know mandatory TLVs for IDLE,
    * CONFIGURED, RUNNING state for FDD/TDD */
    tOCT_FAPI_CELL_CONFIG_TLV        aConfigTlvs[mFAPI_VAR_SIZE(numOfTlv)];
	
}tOCT_FAPI_CELL_CONFIG_REQUEST;

#define SIZE_TOCT_FAPI_CELL_CONFIG_REQUEST_BASE ( 4* sizeof(tOCT_UINT8) )

/* PHY_RECONFIG_CELL_REQ : This defines the message body for 
*  PHY_RECONFIG_CELL_REQUEST 
*/
typedef struct
{
    tOCT_UINT8                 byNumOfTlv;
    tOCT_UINT8                 abyPadding[3];
    /* Please refer FAPI document to know reconfig TLVs for 
    * RECONFIG during running state of PHY 
    */
    tOCT_FAPI_CELL_RECONFIG_TLV    aConfigTlvs[mFAPI_VAR_SIZE(numOfTlv)];
	
}tOCT_FAPI_CELL_RECONFIG_REQUEST;

#define SIZE_TOCT_FAPI_CELL_RECONFIG_REQUEST_BASE ( 4* sizeof(tOCT_UINT8) )

/*  ------------------------------- */
/* PHY CELL CONFIG RESPONSE:This defines the message body for
 * PHY_CELL_CONFIG_RESPONSE */

typedef struct
{
   /* Possible values are defined in eFAPI_L1ERRORCODES. */
    tOCT_UINT8          		byErrorCode; 
	
    /* Number of invalid or unsupported TLVs contained in the message body. */
    tOCT_UINT8                 	byNumOfInvalidOrUnsupportedTLV;
	
    /* Number of missing TLVs contained in the message body. 
    If the PHY is in the CONFIGURED state this will always be 0. */
    tOCT_UINT8                 	byNumOfMissingTLV;
	
	tOCT_UINT8                 	abyPadding[1];
	
	/* A list of invalid or unsupported TLVs . 
    each TLV is presented in its entirety. */
    tOCT_FAPI_CELL_CONFIG_TLV	aListOfTLV[mFAPI_VAR_SIZE(numOfInvalidOrUnsupportedTLV)];
    
    /* A list of missing TLVs . each TLV is presented in its entirety */
    tOCT_FAPI_CELL_CONFIG_TLV	aListOfMissingTlv[mFAPI_VAR_SIZE(numOfTlv)];
	
}tOCT_FAPI_CELL_CONFIG_RESPONSE_V1PT1;

#define SIZE_TOCT_FAPI_CELL_CONFIG_RESPONSE_V1PT1_BASE ( sizeof(tOCT_UINT8)*4 )

/*  ------------------------------- */
/* START REQUEST:This defines the message body for
 * PHY_START_REQUEST */

/* No message body is defined for START.request.
 * The message length in the generic header = 0 */

/*  ------------------------------- */

/* STOP REQUEST:This defines the message body for
 * PHY_STOP_REQUEST */

/* No message body is defined for STOP.request.
 * The message length in the generic header = 0 */

/*  ------------------------------- */

/* STOP INDICATION:This defines the message body for
 * PHY_STOP_INDICATION */

/* No message body is defined for STOP.indication.
 * The message length in the generic header = 0 */

/*  ------------------------------- */

/* PHY UE CONFIG REQUEST: This defines the message body for
 * PHY_UE_CONFIG_REQUEST.
 * The message is only valid if semi-static configuration is kept in PHY.
 */

typedef struct
{
    tOCT_UINT8                byNumOfTlv;
    tOCT_FAPI_UE_CONFIG_TLV   aTlvs[mFAPI_VAR_SIZE(numOfTlv)];

}tOCT_FAPI_UE_CONFIG_REQUEST;

/*  ------------------------------- */

/* PHY UE CONFIG RESPONSE: This defines the message body for
 * PHY_UE_CONFIG_RESPONSE
 * The message is only valid if semi-static configuration is kept in PHY.
 */

typedef struct
{
   /* Possible values are defined in eFAPI_L1ERRORCODES. */
    tOCT_UINT8          		byErrorCode; 

    /* Number of invalid or unsupported TLVs contained in the message body. */
    tOCT_UINT8                 byNumOfInvalidOrUnsupportedTLV;

    /* Number of missing TLVs contained in the message body. 
    If the PHY is in the CONFIGURED state this will always be 0. */
    tOCT_UINT8                 byNumOfMissingTLV;

	tOCT_UINT8                 	abyPadding[1];

    /* A list of invalid or unsupported TLVs . 
    each TLV is presented in its entirety. */
    tOCT_FAPI_UE_CONFIG_TLV    aListOfTLV[mFAPI_VAR_SIZE(numOfInvalidOrUnsupportedTLV)];
    
    /* A list of missing TLVs . each TLV is presented in its entirety */
    tOCT_FAPI_UE_CONFIG_TLV    aListOfMissingTlv[mFAPI_VAR_SIZE(numOfTlv)];

}tOCT_FAPI_UE_CONFIG_RESPONSE_V1PT1;

#define SIZE_TOCT_FAPI_UE_CONFIG_RESPONSE_V1PT1_BASE ( sizeof(tOCT_UINT8)*4 )

/*  ------------------------------- */

/* PHY Notification : This defines the message body for
 * PHY_ERROR_INDICATION */

typedef struct
{
    /* Indicate which message received by the PHY has an error */
	
    /* When byErrorCode is set to "eFAPI_OCTASIC_CUSTOM_ERR" then 
	   msgId = PhyErrorIndication
       errMsgBody will contain the internal errors detected 
	   these are: Takes values from e{DL_PDCCH/DL_PDSCH/UL/RFI}_HANDLER_ERROR_CODES. 
	   the type for errMsgBody is FAPI_ERR_MSG_TYPE_5
    */
    tFAPI_MSG_ID		msgId;

	// 
   /* Possible values are defined in eFAPI_L1ERRORCODES. 
      and correspond to TSN standard. */
    tOCT_UINT8			byErrorCode; 

    tOCT_FAPI_ERR_MSG   errMsgBody;

}tOCT_FAPI_ERROR_INDICATION_V1PT1;

#define SIZE_TOCT_FAPI_ERROR_INDICATION_V1PT1_BASE ( sizeof(tFAPI_MSG_ID) + sizeof(tOCT_UINT8) )
//	sizeof(tOCT_UINT8) + sizeof(tOCT_FAPI_ERR_MSG) )

/* if error codes is FAPI_MSG_INVALID_STATE or FAPI_MSG_BCH_MISSING */
/* then errValues are not supported in notification */
/*  ------------------------------- */

/* SUBFRAME indication : This defines the message body for
 * PHY_UL_SUBFRAME_INDICATION */
typedef struct
{
    /* A 16-bit value where,[15:4] SFN, range 0 . 1023[3:0] SF, range 0 . 9 */
    tOCT_UINT16   usSfnsf;

}tOCT_FAPI_SUBFRAME_INDICATION;

#define SIZE_TOCT_FAPI_SUBFRAME_INDICATION (sizeof(tOCT_FAPI_SUBFRAME_INDICATION))

/*  ------------------------------- */

/*****************************************************************************
    Downlink Subframe for following information
    - DL_CONFIG_Request
    - HI_DCI0_CONFIG
    - DL Data : TX_Request
 *****************************************************************************/

/* DL_CONFIG_Request MSG : This defines the message body for
 * PHY_DL_CONFIG_REQUEST */

typedef struct
{
    /* A 16-bit value where,[15:4] SFN, range 0 . 1023[3:0] SF, range 0 . 9 */ 
    tOCT_UINT16                    usSfnsf;

    /* The length of the downlink subframe configuration. 
    Range 0 . 65535. */
    tOCT_UINT16                    usLength;

    /* The number of OFDM symbols for the PDCCH.
    Value:0 . 4 */
    tOCT_UINT8                     byCfi;

    /*The number of DCI PDUs included in this message.
    Range: 0 . 255 */
    tOCT_UINT8                     byNumDCI;

    /* Number of PDUs that are included in this message.
    Range 0 . 514 */
    tOCT_UINT16                    usNumOfPDU;

    /* Offset to the reference signal power.
    Value: 0 . 10000, representing -6 dB to 4 dB in 0.001 dB steps. */
    tOCT_UINT16                    usTxPowerForPCFICH;

    /* Number of unique RNTIs sent on the PDSCH. 
    - a PCH PDU will have an unique RNTI and should be included in this value
    - a DLSCH PDU can be one transport block sent to a UE with an unique RNTI.
    This RNTI should be included in this value
    - a DLSCH PDU can be one of two transport blocks sent to a UE. In this case
    the two DLSCH PDUs will share the same RNTI. Only one RNTI should be 
    included in this value. */
    tOCT_UINT8                     byNumOfPDSCHRNTI;

    tOCT_UINT8                     abyPadding[1];
    /* possible values of PDU Type supported are defined in 
    * enum eFAPI_DL_PDU_TYPE */

    tOCT_FAPI_DL_CONFIG_PDU_LIST   aDlConfigpduList[mFAPI_VAR_SIZE(numOfPDU)];

}tOCT_FAPI_DL_CONFIG_REQUEST;

#define SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE ( 4* sizeof(tOCT_UINT16) + \
		4* sizeof(tOCT_UINT8) )

/*  ------------------------------- */

/* HI DCI0 REQUEST : This defines the message body for
 * PHY_DL_HI_DCI0_REQUEST . */

typedef struct
{
    /* The SFN/SF in this message should be the same as the corresponding 
    DL_CONFIG.request message. A 2-byte value where,
    [15:4] SFN, range 0 . 1023
    [3:0] SF, range 0 . 9    */
    tOCT_UINT16                    usSfnsf;

    /* Number of DCI PDUs included in this message */
    tOCT_UINT8                     byNumOfDCI;

    /* Number of HI PDUs included in this message */
    tOCT_UINT8                     byNumOfHI;

    tOCT_UINT8                     abyHidciPduInfo[mFAPI_VAR_SIZE(byNumOfDCI + byNumOfHI)];

}tOCT_FAPI_HI_DCI0_REQUEST;

#define SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE ( 1* sizeof(tOCT_UINT16) + \
		2* sizeof(tOCT_UINT8) )

/*  ------------------------------- */

/* DL DATA TX REQUEST : This defines the message body for 
 * PHY_DL_TX_REQUEST .  */

typedef struct
{
    /* The SFN/SF in this message should be the same as the corresponding 
    DL_CONFIG.request message.A 2-byte value where,[15:4] SFN, range 0 . 1023
    [3:0] SF, range 0 . 9   */
    tOCT_UINT16        usSfnsf;

    /* Number of PDUs included in this message. */
    tOCT_UINT16        usNumOfPDU;

    /* For each PDU */
    tOCT_FAPI_DL_PDU_DATA_INFO  aDlPduDataInfo[mFAPI_VAR_SIZE(numOfPDU)];

}tOCT_FAPI_DL_DATA_TX_REQUEST;

#define SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE ( 2* sizeof(tOCT_UINT16) )

/*  ------------------------------- */

/*****************************************************************************
    Uplink Subframe Information
    - UL_CONFIG_Request
    - UL Data
 *****************************************************************************/
/* UL CONFIG REQUEST : This defines the message body for
 * PHY_UL_CONFIG_REQUEST.
 * 
 * The supported PDUs are dependent on whether the semi-static information
 * and uplink HARQ signalling calculation is held in the MAC or PHY.
 * 
 */

typedef struct
{
    /* A 16-bit value where,[15:4] SFN, range 0 . 1023[3:0] SF, range 0 . 9 */
    tOCT_UINT16                        usSfnsf;

    /* The length of the uplink subframe configuration. 
    Range 0 . 65535. */
    tOCT_UINT16                        usUlConfigLen;

    /* The number of UL SCHs PDUs included in this message. */
    tOCT_UINT8                         byNumOfPdu;

    /* If semi-static information is held in the MAC
    For FDD:
    0: No RACH in this subframe
    1: RACH present in this subframe
    For TDD:
    Bits 0:5 indicate which RACH frequency resources are used in this 
    subframe,
    0: This RACH frequency index is not used
    1: This RACH frequency index is used  */
    tOCT_UINT8                         byRachFreqResources;

    /* If semi-static information is held in the MAC
    0: No SRS in this subframe
    1: SRS present in this subframe */
    tOCT_UINT8                         bySrsPresent;

    tOCT_UINT8                         abyPadding[1];
    /* For Number of PDUs */
    tOCT_FAPI_UL_CONFIG_PDU_INFO       aUlPduConfigInfo[mFAPI_VAR_SIZE(numOfPdu)];

}tOCT_FAPI_UL_CONFIG_REQUEST;

#define SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE ( 2* sizeof(tOCT_UINT16) + \
		4* sizeof(tOCT_UINT8) )

/*  ------------------------------- */

/* RX ULSCH DATA INDICATION  : This defines the message body for 
 * PHY_UL_RX_ULSCH_INDICATION . */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit value where,[15:4] SFN, range 0 . 1023[3:0] SF, range 0 . 9 */
    tOCT_UINT16               usSfnsf;

    /* Number of PDUs included in this message. */
    tOCT_UINT16               usNumOfPdu;

    /* For (Number of PDUs) { */
    tOCT_FAPI_UL_DATA_PDU_IND  aUlDataPduInfo[mFAPI_VAR_SIZE(numOfPdu)];
    /* } */

    /* Contents of PDU#1...PDU#n These will be MAC PDUs. */
    tOCT_UINT8                abyPduBuffer[mFAPI_VAR_SIZE(x)];

}tOCT_FAPI_UL_SCH_INDICATION;

//size of the common part only
#define SIZE_TOCT_FAPI_UL_SCH_INDICATION_BASE (sizeof(tOCT_UINT16)*2)

typedef struct
{
	/* PUSCH saturation
	Value: 0 - Possibility of Saturation is low, 1 - Possibility of Saturation is high */
	tOCT_UINT8				bySatFlag;	
	
	/* Pre-processing SNR 
	Value: 0 .. 255, representing -64 to 63.5 (dB) in 0.5 dB steps. */
	tOCT_UINT8              abyPreprocessedSnr[4];
	
	/* Fading indicator
	Value: 0 - no fading conditions, 1 - fading conditions detected */
	tOCT_UINT8              abyFadingIndicator[4];
	
	/* RF saturation
	Value: 0 - Possibility of Saturation is low, 1 - Possibility of Saturation is high */
	tOCT_UINT8 				byOverallSaturation;
	
	/* padding */
	tOCT_UINT8              abyPadding[2];
	
	/* PUSCH RSSI in time domain in baseband (expressed in dBm, in Q7 units) 
	Value: -6400 to -15360 (Q7 format), representing -50 .. -120 dBm
	Example: -10240 represents -80 dB. */
	tOCT_INT32				puschRssi;
	
}tOCT_FAPI_UL_SCH_INDICATION_VENDOR;

#define SIZE_TOCT_FAPI_UL_SCH_INDICATION_VENDOR (sizeof(tOCT_FAPI_UL_SCH_INDICATION_VENDOR))

/*  ------------------------------- */

/* UL HARQ INDICATION  : This defines the message body for   
 * PHY_UL_HARQ_INDICATION . */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16             usSfnsf;

    /* Number of HARQs included in this message. */
    tOCT_UINT16             usNumOfHarq;

    /* For (Number of HARQs) depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_IND_FDD aHarqPduInfo[mFAPI_VAR_SIZE(numOfHarq)];

}tOCT_FAPI_UL_HARQ_INDICATION;

#define SIZE_TOCT_FAPI_UL_HARQ_INDICATION_BASE (sizeof(tOCT_UINT16)*2)

/*  ------------------------------- */

/* UL HARQ INDICATION  TDD : This defines the message body for   
 * PHY_UL_HARQ_INDICATION when sent in TDD mode. */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16             usSfnsf;

    /* Number of HARQs included in this message. */
    tOCT_UINT16             usNumOfHarq;

    /* For (Number of HARQs) depending upon Mode ( TDD or FDD ) */
    tOCT_FAPI_UL_HARQ_PDU_IND_TDD aHarqPduInfo[mFAPI_VAR_SIZE(numOfHarq)];

}tOCT_FAPI_UL_HARQ_INDICATION_TDD;

#define SIZE_TOCT_FAPI_UL_HARQ_INDICATION_TDD_BASE (sizeof(tOCT_UINT16)*2)


/*  ------------------------------- */

/* UL CRC INDICATION  : This defines the message body for  
 * PHY_UL_CRC_INDICATION . */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16            usSfnsf;

    /* Number of CRCs included in this message. */
    tOCT_UINT16            usNumOfCrc;

    /* For (Number of CRCs) */
    tOCT_FAPI_UL_CRC_PDU_IND  aCrcPduInfo[mFAPI_VAR_SIZE(numOfCrc)];

}tOCT_FAPI_UL_CRC_INDICATION;

#define SIZE_TOCT_FAPI_UL_CRC_INDICATION_BASE (sizeof(tOCT_UINT16)*2)

/*  ------------------------------- */

/* UL RX SR INDICATION  : This defines the message body for  
 * PHY_UL_RX_SR_INDICATION . */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16          usSfnsf;

    /* Number of SRs included in this message.  */
    tOCT_UINT16          usNumOfSr;

    /* For (Number of SRs) */
    tOCT_FAPI_UL_SR_PDU_IND aSrPduInfo[mFAPI_VAR_SIZE(numOfSr)];

}tOCT_FAPI_UL_RX_SR_INDICATION;

#define SIZE_TOCT_FAPI_UL_SR_INDICATION_BASE (sizeof(tOCT_UINT16)*2)

/*  ------------------------------- */

/* UL RX CQI INDICATION  : This defines the message body for  
 * PHY_UL_RX_CQI_INDICATION . */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16          usSfnsf;

    /* Number of Cqi included in this message.  */
    tOCT_UINT16          usNumOfCqi;

    /* For (Number of Cqis) */
    tOCT_FAPI_UL_CQI_PDU_IND aCqiPduInfo[mFAPI_VAR_SIZE(numOfCqi)];

    /* Contents of PDU#1....PDU#n These will be CQI PDUs. */
    tOCT_UINT8                abyPduBuffer[mFAPI_VAR_SIZE(x)];

}tOCT_FAPI_UL_RX_CQI_INDICATION;

#define SIZE_TOCT_FAPI_UL_CQI_INDICATION_BASE (sizeof(tOCT_UINT16)*2)

typedef struct
{
    /* SNR 
	Value: 0-255, representing -64dB to 63.5dB, 
	with 0.5dB step size.
	Example: 30 represents 15 dB. */
	tOCT_UINT8      abySnr[8];
	
 	/* Indicates the possibility of saturation, 0x1 -> Possibility of saturation high 0x0 -> Possibility of saturation low */
	tOCT_UINT8   	byUlSaturationFlag[8];
	
  	/* PUCCH RSSI expressed in dBm in Q7 format
	Value: -6400 to -15360, representing -50 .. -120 dBm
	Example:  Value -10240 represents -80 dBm */
	tOCT_INT16		sUlRssi[8];
	
}tOCT_FAPI_UL_HARQ_PUCCH_IND_VENDOR;

#define SIZE_TOCT_FAPI_UL_HARQ_PUCCH_IND_VENDOR (sizeof(tOCT_FAPI_UL_HARQ_PUCCH_IND_VENDOR))

typedef struct
{
  	/* PUCCH RSSI expressed in dBm in Q7 format
	Value: -6400 to -15360, representing -50 .. -120 dBm
	Example:  Value -10240 represents -80 dBm */
	tOCT_INT16		sUlRssi[8];
	
}tOCT_FAPI_UL_CQI_PUCCH_IND_VENDOR;

#define SIZE_TOCT_FAPI_UL_CQI_PUCCH_IND_VENDOR (sizeof(tOCT_FAPI_UL_CQI_PUCCH_IND_VENDOR))


/*  ------------------------------- */

/* UL RACH INDICATION  : This defines the message body for  
 * PHY_UL_RACH_INDICATION . */

typedef struct
{
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16              usSfnsf;

    /* Number of RACH preambles */
    tOCT_UINT16              usNumOfPreamble;

    /* For (Number of Preambles) */
    tOCT_FAPI_UL_PRACH_PDU_IND   aRachPduInfo[mFAPI_VAR_SIZE(numOfPreamble)];

}tOCT_FAPI_UL_RACH_INDICATION;

#define SIZE_TOCT_FAPI_UL_RACH_INDICATION_BASE ( sizeof(tOCT_UINT16)*2 )

/*  ------------------------------- */

/* UL SRS INDICATION  : This defines the message body for  
 * PHY_UL_SRS_INDICATION . */
typedef struct
{
	
    /* The SFN/SF of the SUBFRAME this information was received in.
    A 16-bit  value where,[15:4] SFN, range 0 . 1023 [3:0] SF, range 0 . 9 */ 
    tOCT_UINT16              usSfnsf;

    /* Number of UEs contributing to the uplink SRS*/
    tOCT_UINT8              usNumOfUes;
	tOCT_UINT8              abyPadding[1];
	/* For (Number of UEs) */
    tOCT_FAPI_UL_SRS_PDU_IND   aSrsPduInfo[mFAPI_VAR_SIZE(usNumOfUes)];
		
}tOCT_FAPI_UL_SRS_INDICATION;
#define SIZE_TOCT_FAPI_UL_SRS_INDICATION_BASE ( sizeof(tOCT_UINT16) + sizeof(tOCT_UINT8)*2  )


/*  ------------------------------- */
/* Set the alignment back to default. Only structures in this file are aligned
 * to 32 bit boundary. */
#pragma pack() 

#endif /* LTE_FAPI_MAC_PHY_INTERFACE_H */
