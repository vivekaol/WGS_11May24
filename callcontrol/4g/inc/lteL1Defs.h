/*
*############################################################################
*
*                   *** FXLynx Technologies Ltd. ***
*
*     The information contained in this file is the property of FXLynx
*     Technologies Ltd. Except as specifically authorized in writing by
*     FXLynx Technologies Ltd. The user of this file shall keep information
*     contained herein confidential and shall protect same in whole or in
*     part from disclosure and dissemination to third parties.
*
*     Without prior written consent of FXLynx Technologies Ltd. you may not
*     reproduce, represent, or download through any means, the information
 *     contained herein in any way or in any form.
*
*       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : lteL1Defs.h
 *
* Description : This file contains all enums,macros,constants
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/01/2015          			Anand Kashikar     File Creation
*############################################################################
*/


#ifndef _LTE_L1_DEFS_H_
#define _LTE_L1_DEFS_H_

#include "lteCmnDef.h"

#define MAX_SIZE_OF_LTE_ETHERNET_FRAME 256
#define LTE_PCFICH_POWER_OFFSET_VALUE 6000 // Range is from -6 to +4 ie 0 to 10000. Setting to -6 for normal cases and 0 for max cell radius cases
#define LTE_PHICH_POWER_OFFSET_VALUE 6000 // Range is from -6 to +4 ie 0 to 10000. Setting to -6 for normal cases and 0 for max cell radius cases
#define LTE_PDCCH_POWER_OFFSET_VALUE 6000
#define LTE_PB_VALUE 0 // 1 //0 //1 0 for single antenna , 1 for double antenna
#define LTE_PB_VALUE_TDD 0 //1//0 //0 //1 0 for single antenna , 1 for double antenna
#define LTE_PERIODIC_CQI_OFFSET 8
#define LTE_PERIODIC_RI_OFFSET 1
#define LTE_REFERENCE_SIGNAL_POWER 18 //20 //18 //-14
#define LTE_REFERENCE_SIGNAL_POWER_TDD 15 //20 //-14
#define LTE_PRIMARY_SYNC_SIGNAL_VALUE 6000 //0 . 9999 represents -6dB to 4dB in step 0.001dB */
#define LTE_SECONDARY_SYNC_SIGNAL_VALUE 6000 //0 . 9999 represents -6dB to 4dB in step 0.001dB */
//#define LTE_PHYSICAL_CELL_ID_VALUE 1 // Can be anything between 0 to 503
#define LTE_PRACH_CONFIGURATION_INDEX 2 //Preamble Format = 0 , SFN = Even , Subframe No. = 7
#define LTE_PRACH_CONFIGURATION_INDEX_TDD 3 //0
#define LTE_PRACH_ROOT_SEQUENCE_INDEX 22 // 0 t0 837
#define LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX 11 // FDD 0 to 15
#define LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX_TDD 11 //7
#define LTE_PUSCH_HOPPING_OFFSET 0  // 4 //0 to 98
#define LTE_PUCCH_DELTA_SHIFT 2 //1 to 3
#define LTE_PUCCH_NUM_CQI_RB_ALLOCATED 0 // 0 to 98
#define LTE_PUCCH_NUM_CYCLIC_SHIFT 0 // 0 to 7
#define LTE_PUCCH_NUM_CQI_RB_ALLOCATED_TDD 2 //4 // 0 to 98
#define LTE_PUCCH_NUM_CYCLIC_SHIFT_TDD 0//6 // 0 to 7
#define LTE_PRACH_FREQUENCY_OFFSET 4 //0 //4
#define LTE_PUSCH_NUM_OF_SUBBANDS 4 //2
#define LTE_PUCCH_AN 20
#define LTE_PUCCH_AN_TDD 20//2 
#define LTE_SRS_BANDWIDTH_CONFIGURATION 3
#define LTE_SRS_SUBFRAME_CONFIG 10
#define LTE_SHORT_ZERO 0x0000
#define LTE_MAX_SYSTEM_FRAME_NUMBER 1024
#define LTE_MAX_SUB_FRAME_NUMBER 10
#define LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH 3
#define LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH_TDD 2
#define LTE_LAYER3_CELL_IDENTITY_VALUE 200
#define LTE_FREQUENCY_BAND_INDICATOR 5
#define LTE_MCC_DIGIT1 0
#define LTE_MCC_DIGIT2 0
#define LTE_MCC_DIGIT3 1
#define LTE_MNC_DIGIT1 0
#define LTE_MNC_DIGIT2 1
#define LTE_MNC_DIGIT3 0
#define LTE_SIB1_Q_RXLEV_MIN -65
#define LTE_SIB1_Q_RXLEV_MIN_OFFSET 1
#define LTE_SIB1_SYSTEM_VALUE_TAG 0
#define LTE_LAYER3_TRACKING_AREA_CODE 100
#define LTE_SIB2_DELTA_PREAMBLE_MSG3 4
#define LTE_SIB2_MAX_HARQ_MSG3_TX 1 //2 // 1 //5  Range : 1-8 [ Octasic recommends to change to 2]
#define LTE_PO_NOMINAL_PUCCH -110 //-96 // -96
#define LTE_PO_NOMINAL_PUCCH_TDD -116 //-105//-96
#define LTE_PO_NOMINAL_PUSCH -80 // -72 //-83
#define LTE_PO_NOMINAL_PUSCH_TDD -85 //-67//-93 // -72 //-83
#define LTE_PUSCH_GROUP_ASSIGNEMENT 0
#define LTE_PUSCH_REF_SIG_CYCLIC_SHIFT 0
#define LTE_SIB3_CELL_RESELECTION_PRIORITY 7
#define LTE_SIB3_Q_RXLEV_MIN -64
#define LTE_SIB3_TRESELECTION_EUTRA 7
#define LTE_SIB3_THRESH_SERVING_LOW  1
#define LTE_MIB_MAX_SIZE 3
#define LTE_RAR_BACKOFF_INDICATOR_VALUE 20
#define LTE_MIB_REPITION_FRAMES 4
#define LTE_SIBS_REPITITION_FRAMES 32
#define LTE_SIB1_REPITION_FRAMES 2 // First SIB1 transmission should be at sfn%8
#define LTE_MIB_SUBFRAME_LOCATION 0
#define LTE_SIB1_SUBFRAME_LOCATION 5
#define LTE_CCE_INDEX_FOR_SIB 0
#define LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS 8
#define LTE_UE_CATEGORY 3 // 150/50
#define LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU 8 //4
#define LTE_NO_OF_PDCCH_CANDIDATES_FOR_AGG_LVL_8 3
#define CONSTAT_A_FOR_CALCULATING_CCE_INDEX  39827
#define CONSTAT_D_FOR_CALCULATING_CCE_INDEX  65537
#define LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY 80
#define LTE_DEDICATED_MODE_SR_SUBFRAME 2
#define LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY -5)
#define LTE_DEDICATED_MODE_SR_CONFIG_INDEX_END (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY + 5 -1)
#define LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY_TDD 40 //80
#define LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START_TDD 37//(LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY_TDD -3)//TDD
#define LTE_DEDICATED_MODE_SR_CONFIG_INDEX_END_TDD (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY_TDD - 5 -1)//TDD
#define LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX 0
#define LTE_NO_OF_RE_IN_CCE 36
#define LTE_INVALID_SR_CONFIG_INDEX 0xFF
#define LTE_PAGING_SUBFRAME_LOCATION 9
#define LTE_PAGING_SUBFRAME_LOCATION_TDD 0
#define MAX_IDENTITY_LENGTH_STR_4G  16
#define MAX_PAGE_UE_4G 5
#define LTE_NUMBER_OF_RE_IN_PCFICH 16
#define LTE_NUMBER_OF_RS_IN_ONE_PRB 4
#define LTE_RACH_TA_DEFAULT 15
#define LTE_TDD_UD_CONFIG 2 // 2
#define LTE_TDD_SPECIALSUBF_ASSG 6 //6
#define LTE_TDD_MAX_UD_CONFIG 7
#define LTE_MAX_CCE_IDX 89
#define LTE_SR_INDEX 77 //52 Every 8 SFN and 2 subframe

#define LTE_TDD_DOWNLINK 0
#define LTE_TDD_UPLINK 1
#define LTE_TDD_SSUBFRAME 2

typedef enum			/* LTE Duplex Mode */
{
  LTE_FDD = 0,
  LTE_TDD
} lteDupMode_;
typedef uint8 elteDupMode;


typedef enum			/* LTE Downlink Bandwidth */
{
  LTE_BW_N6,
  LTE_BW_N15,
  LTE_BW_N25,
  LTE_BW_N50,
  LTE_BW_N75,
  LTE_BW_N100
} lteBw_;
typedef uint8 eLteBw;

#define LTE_MAC_SIB1_CARRYING_DL_MCS 9 //= 296 bits
#define LTE_MAC_SIB1_PDU_SIZE        296/8 //296/8
#define LTE_MAC_SIBS_CARRYING_DL_MCS 9 //13 //= 440 bits
#define LTE_MAC_SIBS_PDU_SIZE        456/8
#define LTE_SIB3_SINTRASEARCH        1
#define LTE_SIB3_SNONINTRASEARCH     1
/*
Table 7.1-1: RNTI values.
Value(hexa-decimal) 		RNTI
0000 						N/A
0001-003C 					RA-RNTI, C-RNTI, Semi-Persistent Scheduling C-RNTI,
							Temporary C-RNTI, TPC-PUCCH-RNTI and TPC-PUSCH-RNTI
							(see note)
003D-FFF3 					C-RNTI, Semi-Persistent Scheduling C-RNTI, Temporary C-RNTI,
							TPC-PUCCH-RNTI and TPC-PUSCH-RNTI
FFF4-FFFC 					Reserved for future use
FFFD 						M-RNTI
FFFE 						P-RNTI
FFFF 						SI-RNTI
*/

#define LTE_MAX_USER_SUPPORTED 32
#define LTE_INVALID_RNTI    0x0000
#define LTE_RA_RNTI_START   0x0001
#define LTE_RA_RNTI_END     0x003C
#define LTE_C_RNTI_START    0x003D
#define LTE_C_RNTI_END      0xFFF3
#define LTE_RESV_RNTI_START 0xFFF4
#define LTE_RESV_RNTI_END   0xFFFC
#define LTE_M_RNTI          0xFFFD
#define LTE_P_RNTI          0xFFFE
#define LTE_SI_RNTI         0xFFFF

#define MAX_BANDWIDTH 6
#define MAX_NO_UPLINK_GRANTS 5
#define MAX_NO_DOWNLINK_GRANTS 14
//Uplink RIV
#define LTE_MAC_UL_GRANT_INSIDE_RAR_RIV 0  //(RB Start = 0, RB Length = 2)
#define LTE_MAC_UL_GRANT_FOR_RRC_CONN_COMPLETE_RIV 1 //RbStart = 0 , NoOfRb = 10
#define LTE_MAC_UL_GRANT_FOR_RRC_NAS_MSG_RIV 2 //RbStart = 0 , NoOfRb = 5
#define LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_RIV 3 //RbStart = 0 , NoOfRb = 2
#define LTE_MAC_UL_GRANT_FOR_SILENT_CALL_NAS_MSG_RIV 4 //RbStart = 0 , NoOfRb = 25 For 10/15/20 Mhz and 10 for 5Mhz

//Downlink RIV
#define LTE_MAC_RAR_CARRYING_DL_RIV 0 // rb_start = 0 , no_prb = 2
#define LTE_MAC_CONTENTION_RESOLUTION_CARRYING_DL_RIV 1 // rb_start = 0 , no_prb = 2
#define LTE_MAC_RRC_CONN_SETUP_CARRYING_DL_RIV 2 //rb_start = 0 , no_prb = 8
#define LTE_MAC_SIB1_CARRYING_DL_RIV 3 //3 //rb_start = 0 , no_prb = 2 //3
#define LTE_MAC_SIBS_CARRYING_DL_RIV 4 //4// //rb_start = 0 , no_prb = 2
//Downlink Paging RIV
#define LTE_MAC_PAGING_REQ_CARRYING_DL_RIV 5 //rb_start = 0 , no_prb = 2
#define LTE_MAC_4_PAGING_REQ_CARRYING_DL_RIV 6 //rb_start = 0 , no_prb = 4
#define LTE_MAC_8_PAGING_REQ_CARRYING_DL_RIV 7 //rb_start = 0 , no_prb = 6
//Downlink Layer3 message RIV
#define LTE_MAC_DL_GRANT_FOR_RLC_ACK 8 //rb_start = 0 , no_prb = 2
#define LTE_MAC_DL_GRANT_FOR_NAS_REQ 9 //rb_start = 0 , no_prb = 4
#define LTE_MAC_DL_GRANT_FOR_RRC_CONN_REL 10 //rb_start = 0 , no_prb = 5
#define LTE_MAC_DL_GRANT_FOR_RRC_MEAS_REQ 11 //rb_start = 0 , no_prb = 6
#define LTE_MAC_DL_GRANT_FOR_RRC_RECONFIG_REQ 12 //rb_start = 0 , no_prb = 8
#define LTE_MAC_DL_GRANT_FOR_RRC_NEIGH_MEAS_REQ 13  //rb_start = 0 , no_prb = 8

#endif  //#ifndef _L1_CONSTANTS_H_
