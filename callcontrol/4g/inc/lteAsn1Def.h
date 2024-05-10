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
* File Name   : lteAsn1Def.h
 *
* Description : Lte Brodcast channels definitions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 22/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef LTE_ASN1_DEF_H_
#define LTE_ASN1_DEF_H_


#include "lteL1Defs.h"

#define LTE_MAX_NO_PLMNS 6
#define MAX_NO_OF_BLACKLISTED_NEIGHBOUR_CELLS_IN_SIB4 16 // Max is 16 curtailing to 8
#define MAX_NO_OF_NEIGHBOUR_CELLS_INTRA_IN_SIB4 16 // Max is 16 curtailing to 8
#define MAX_NO_OF_NEIGHBOUR_CELLS_INTER_IN_SIB5 8 // Max is 8 curtailing to 6
#define MAX_NO_OF_UMTS_NEIGHBOUR_CELLS_IN_SIB6 8
#define MAX_NO_OF_GSM_NEIGHBOUR_CELLS_IN_SIB7 16
#define MAX_NO_OF_CDMA_BAND_CLASS_IN_SIB8 32
#define MAX_NO_OF_CDMA_NEIGHBOUR_CELL_IN_SIB8 16
#define SIB2_MASK 0x00000001
#define SIB3_MASK 0x00000002
#define SIB4_MASK 0x00000004
#define SIB5_MASK 0x00000008
#define SIB6_MASK 0x00000010
#define SIB7_MASK 0x00000020
#define SIB8_MASK 0x00000040
#define SIB1_MASK 0x00000080

#define RELEASE_CAUSE_LOAD_BALANCING_TAU_REQUIRED   0
#define RELEASE_CAUSE_OTHER                         1
#define RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY     2
#define RELEASE_CAUSE_SAPARE                        3


#define ASN_LTE_MAX_INTER_RAT_GSM_CELL_LIST 2 
#define ASN_LTE_MAX_INTER_RAT_UMTS_CELL_LIST 4
#define ASN_LTE_MAX_INTER_RAT_PSC_PER_UARFCN 4
#define ASN_LTE_MAX_INTER_FREQ_CELL_LIST 4
#define ASN_LTE_MAX_INTER_RAT_ARFCN_PER_ARFCN 10

typedef enum			/* PHICH DURATION */
{
  LTE_PHICH_DURATION_NORMAL,
  LTE_PHICH_DURATION_EXTENDED
} ltePhichDuration_;
typedef uint8 eLtePhichDuration;

typedef enum			/* PHICH RESOURCE */
{
  LTE_PHICH_RESOURCE_ONSIXTH,
  LTE_PHICH_RESOURCE_HALF,
  LTE_PHICH_RESOURCE_ONE,
  LTE_PHICH_RESOURCE_TWO
} ltePhichResource_;
typedef uint8 eLtePhichResource;

typedef enum			/* BCCH MODIFICATION PERIOD COEFF */
{
  LTE_BCCH_MODIFICATION_PERIOD_COEFF_N2,
  LTE_BCCH_MODIFICATION_PERIOD_COEFF_N4,
  LTE_BCCH_MODIFICATION_PERIOD_COEFF_N8,
  LTE_BCCH_MODIFICATION_PERIOD_COEFF_N16
} lteBcchModificationPeriodCoeff_;
typedef uint8 eLteBcchModificationPeriodCoeff;

typedef enum			/* DRX CYCLE */
{
  LTE_DRX_CYCLE_RF32,
  LTE_DRX_CYCLE_RF64,
  LTE_DRX_CYCLE_RF128,
  LTE_DRX_CYCLE_RF256
} lteDrxCycle_;
typedef uint8 eLteDrxCycle;

typedef enum			/* nB Paging  */
{
  LTE_PCCH_NB_4T,
  LTE_PCCH_NB_2T,
  LTE_PCCH_NB_1T,
  LTE_PCCH_NB_HALFT,
  LTE_PCCH_NB_QUARTERT,
  LTE_PCCH_NB_ONEEIGHTHT,
  LTE_PCCH_NB_ONESIXTEENTHT,
  LTE_PCCH_NB_ONETHIRTYSECONDT
} ltePcchNB_;
typedef uint8 eLtePcchNB;

typedef enum			/* Delta Pucch Shift */
{
  LTE_PUCCH_DELTA_SHIFT_1,
  LTE_PUCCH_DELTA_SHIFT_2,
  LTE_PUCCH_DELTA_SHIFT_3
} ltedeltaPUCCHShift_;
typedef uint8 eLtedeltaPUCCHShift;

typedef enum			/* PUSCH Hopping Mode */
{
  LTE_HOPPING_MODE_INTERSUBFRAME,
  LTE_HOPPING_MODE_INTRA_INTERSUBFRAME
} ltePuschHoppingMode_;
typedef uint8 eLtePuschHoppingMode;

typedef enum			/* RACH Power Ramping Step */
{
  LTE_RACH_POWER_RAMPING_STEP_DB0,
  LTE_RACH_POWER_RAMPING_STEP_DB2,
  LTE_RACH_POWER_RAMPING_STEP_DB4,
  LTE_RACH_POWER_RAMPING_STEP_DB6
} lteRachPowerRampingStep_;
typedef uint8 eLteRachPowerRampingStep;

typedef enum			/* Preamble Initial Received Target Power */
{
  LTE_INITIAL_PREAMBLE_TARGET_POWER_120DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_118DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_116DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_114DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_112DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_110DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_108DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_106DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_104DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_102DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_100DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_98DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_96DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_94DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_92DBM,
  LTE_INITIAL_PREAMBLE_TARGET_POWER_90DBM
} ltePreambleInitialReceivedTargetPower_;
typedef uint8 eLtePreambleInitialReceivedTargetPower;

typedef enum			/* No. Of RA Preambles */
{
  LTE_NO_RA_PREAMBLES_4,
  LTE_NO_RA_PREAMBLES_8,
  LTE_NO_RA_PREAMBLES_12,
  LTE_NO_RA_PREAMBLES_16,
  LTE_NO_RA_PREAMBLES_20,
  LTE_NO_RA_PREAMBLES_24,
  LTE_NO_RA_PREAMBLES_28,
  LTE_NO_RA_PREAMBLES_32,
  LTE_NO_RA_PREAMBLES_36,
  LTE_NO_RA_PREAMBLES_40,
  LTE_NO_RA_PREAMBLES_44,
  LTE_NO_RA_PREAMBLES_48,
  LTE_NO_RA_PREAMBLES_52,
  LTE_NO_RA_PREAMBLES_56,
  LTE_NO_RA_PREAMBLES_60,
  LTE_NO_RA_PREAMBLES_64
} lteNoOfRAPreambles_;
typedef uint8 eLteNoOfRAPreambles;

typedef enum			/* SRS Bandwidth */
{
  LTE_SRS_BANDWIDTH_0,
  LTE_SRS_BANDWIDTH_1,
  LTE_SRS_BANDWIDTH_2,
  LTE_SRS_BANDWIDTH_3,
  LTE_SRS_BANDWIDTH_4,
  LTE_SRS_BANDWIDTH_5,
  LTE_SRS_BANDWIDTH_6,
  LTE_SRS_BANDWIDTH_7
} lteSrsBandwidth_;
typedef uint8 eLteSrsBandwidth;

typedef enum			/* SRS Subframe configuration */
{
  LTE_SRS_SUBFRAME_0,
  LTE_SRS_SUBFRAME_1,
  LTE_SRS_SUBFRAME_2,
  LTE_SRS_SUBFRAME_3,
  LTE_SRS_SUBFRAME_4,
  LTE_SRS_SUBFRAME_5,
  LTE_SRS_SUBFRAME_6,
  LTE_SRS_SUBFRAME_7,
  LTE_SRS_SUBFRAME_8,
  LTE_SRS_SUBFRAME_9,
  LTE_SRS_SUBFRAME_10,
  LTE_SRS_SUBFRAME_11,
  LTE_SRS_SUBFRAME_12,
  LTE_SRS_SUBFRAME_13,
  LTE_SRS_SUBFRAME_14,
  LTE_SRS_SUBFRAME_15
} lteSrsSubframe_;
typedef uint8 eLteSrsSubframe;

typedef enum			/* Cyclic Prefix Length */
{
  LTE_CYCLIC_PREFIX_LEN_1,
  LTE_CYCLIC_PREFIX_LEN_2
} lteCyclicPrefixLength_;
typedef uint8 eLteCyclicPrefixLength;

typedef enum			/* Uplink Power Control Alpha */
{
  LTE_UL_POWER_CONTROL_ALPHA_0,
  LTE_UL_POWER_CONTROL_ALPHA_4,
  LTE_UL_POWER_CONTROL_ALPHA_5,
  LTE_UL_POWER_CONTROL_ALPHA_6,
  LTE_UL_POWER_CONTROL_ALPHA_7,
  LTE_UL_POWER_CONTROL_ALPHA_8,
  LTE_UL_POWER_CONTROL_ALPHA_9,
  LTE_UL_POWER_CONTROL_ALPHA_1
} lteUplinkPowerControlAlpha_;
typedef uint8 eLteUplinkPowerControlAlpha;

typedef enum			/* DELTA PUCCH FORMAT1 DELTA */
{
  LTE_PUCCH_FORMAT1_DELTA_MINUS2,
  LTE_PUCCH_FORMAT1_DELTA_0,
  LTE_PUCCH_FORMAT1_DELTA_2
} lteDeltaPucchFormat1_;
typedef uint8 eLteDeltaPucchFormat1;

typedef enum			/* DELTA PUCCH FORMAT1B DELTA */
{
  LTE_PUCCH_FORMAT1B_DELTA_1,
  LTE_PUCCH_FORMAT1B_DELTA_3,
  LTE_PUCCH_FORMAT1B_DELTA_5
} lteDeltaPucchFormat1b_;
typedef uint8 eLteDeltaPucchFormat1b;

typedef enum			/* DELTA PUCCH FORMAT2 DELTA */
{
  LTE_PUCCH_FORMAT2_DELTA_MINUS2,
  LTE_PUCCH_FORMAT2_DELTA_0,
  LTE_PUCCH_FORMAT2_DELTA_1,
  LTE_PUCCH_FORMAT2_DELTA_2
} lteDeltaPucchFormat2_;
typedef uint8 eLteDeltaPucchFormat2;

typedef enum			/* DELTA PUCCH FORMAT2A DELTA */
{
  LTE_PUCCH_FORMAT2A_DELTA_MINUS2,
  LTE_PUCCH_FORMAT2A_DELTA_0,
  LTE_PUCCH_FORMAT2A_DELTA_2
} lteDeltaPucchFormat2a_;
typedef uint8 eLteDeltaPucchFormat2a;

typedef enum			/* DELTA PUCCH FORMAT2B DELTA */
{
  LTE_PUCCH_FORMAT2B_DELTA_MINUS2,
  LTE_PUCCH_FORMAT2B_DELTA_0,
  LTE_PUCCH_FORMAT2B_DELTA_2
} lteDeltaPucchFormat2b_;
typedef uint8 eLteDeltaPucchFormat2b;

typedef enum			/* TIME ALIGNMENT TIMER */
{
  LTE_UL_TIME_ALIGNMENT_TIMER_500,
  LTE_UL_TIME_ALIGNMENT_TIMER_750,
  LTE_UL_TIME_ALIGNMENT_TIMER_1280,
  LTE_UL_TIME_ALIGNMENT_TIMER_1920,
  LTE_UL_TIME_ALIGNMENT_TIMER_2560,
  LTE_UL_TIME_ALIGNMENT_TIMER_5120,
  LTE_UL_TIME_ALIGNMENT_TIMER_10240,
  LTE_UL_TIME_ALIGNMENT_TIMER_INFINITY
} lteUlTimeAlignmentTimer_;
typedef uint8 eLteUlTimeAlignmentTimer;


typedef enum			/* UE CONSTANT N-310 */
{
  LTE_UE_CONSTANT_N310_1,
  LTE_UE_CONSTANT_N310_2,
  LTE_UE_CONSTANT_N310_3,
  LTE_UE_CONSTANT_N310_4,
  LTE_UE_CONSTANT_N310_6,
  LTE_UE_CONSTANT_N310_8,
  LTE_UE_CONSTANT_N310_10,
  LTE_UE_CONSTANT_N310_20
} lteUeConstantN310_;
typedef uint8 eLteUeConstantN310;

typedef enum			/* UE CONSTANT N-311 */
{
  LTE_UE_CONSTANT_N311_1,
  LTE_UE_CONSTANT_N311_2,
  LTE_UE_CONSTANT_N311_3,
  LTE_UE_CONSTANT_N311_4,
  LTE_UE_CONSTANT_N311_5,
  LTE_UE_CONSTANT_N311_6,
  LTE_UE_CONSTANT_N311_8,
  LTE_UE_CONSTANT_N311_10
} lteUeConstantN311_;
typedef uint8 eLteUeConstantN311;

typedef enum			/* UE TIMER T301 */
{
  LTE_UE_TIMER_T301_100,
  LTE_UE_TIMER_T301_200,
  LTE_UE_TIMER_T301_300,
  LTE_UE_TIMER_T301_400,
  LTE_UE_TIMER_T301_600,
  LTE_UE_TIMER_T301_1000,
  LTE_UE_TIMER_T301_1500,
  LTE_UE_TIMER_T301_2000
} lteUeTimerT301_;
typedef uint8 eLteUeTimerT301;

typedef enum			/* UE TIMER T300 */
{
  LTE_UE_TIMER_T300_100,
  LTE_UE_TIMER_T300_200,
  LTE_UE_TIMER_T300_300,
  LTE_UE_TIMER_T300_400,
  LTE_UE_TIMER_T300_600,
  LTE_UE_TIMER_T300_1000,
  LTE_UE_TIMER_T300_1500,
  LTE_UE_TIMER_T300_2000
} lteUeTimerT300_;
typedef uint8 eLteUeTimerT300;

typedef enum			/* UE TIMER T310 */
{
  LTE_UE_TIMER_T310_0,
  LTE_UE_TIMER_T310_50,
  LTE_UE_TIMER_T310_100,
  LTE_UE_TIMER_T310_200,
  LTE_UE_TIMER_T310_500,
  LTE_UE_TIMER_T310_1000,
  LTE_UE_TIMER_T310_2000
} lteUeTimerT310_;
typedef uint8 eLteUeTimerT310;

typedef enum			/* UE TIMER T311 */
{
  LTE_UE_TIMER_T311_1000,
  LTE_UE_TIMER_T311_3000,
  LTE_UE_TIMER_T311_5000,
  LTE_UE_TIMER_T311_10000,
  LTE_UE_TIMER_T311_15000,
  LTE_UE_TIMER_T311_20000,
  LTE_UE_TIMER_T311_30000
} lteUeTimerT311_;
typedef uint8 eLteUeTimerT311;

typedef enum			/* qHysterisis in dB */
{
  LTE_RESELECTION_QHYSTERIS_0,
  LTE_RESELECTION_QHYSTERIS_1,
  LTE_RESELECTION_QHYSTERIS_2,
  LTE_RESELECTION_QHYSTERIS_3,
  LTE_RESELECTION_QHYSTERIS_4,
  LTE_RESELECTION_QHYSTERIS_5,
  LTE_RESELECTION_QHYSTERIS_6,
  LTE_RESELECTION_QHYSTERIS_8,
  LTE_RESELECTION_QHYSTERIS_10,
  LTE_RESELECTION_QHYSTERIS_12,
  LTE_RESELECTION_QHYSTERIS_14,
  LTE_RESELECTION_QHYSTERIS_16,
  LTE_RESELECTION_QHYSTERIS_18,
  LTE_RESELECTION_QHYSTERIS_20,
  LTE_RESELECTION_QHYSTERIS_22,
  LTE_RESELECTION_QHYSTERIS_24
} lteReselectionQhysterisis_;
typedef uint8 eLteReselectionQhysterisis;

typedef enum			/* SI Window Length */
{
  LTE_SI_WINDOW_LENGTH_MS1,
  LTE_SI_WINDOW_LENGTH_MS2,
  LTE_SI_WINDOW_LENGTH_MS5,
  LTE_SI_WINDOW_LENGTH_MS10,
  LTE_SI_WINDOW_LENGTH_MS15,
  LTE_SI_WINDOW_LENGTH_MS20,
  LTE_SI_WINDOW_LENGTH_MS40
} lteSiWindowLength_;
typedef uint8 eLteSiWindowLength;

typedef enum			/* SI Periodicity */
{
  LTE_SI_PERIODICITY_RF8,
  LTE_SI_PERIODICITY_RF16,
  LTE_SI_PERIODICITY_RF32,
  LTE_SI_PERIODICITY_RF64,
  LTE_SI_PERIODICITY_RF128,
  LTE_SI_PERIODICITY_RF256,
  LTE_SI_PERIODICITY_RF512
} lteSiPeriodicity_;
typedef uint8 eLteSiPeriodicity;

typedef enum			/* Rach PreambleTransMax */
{
  LTE_PREAMBLE_TRANS_MAX_N3,
  LTE_PREAMBLE_TRANS_MAX_N4,
  LTE_PREAMBLE_TRANS_MAX_N5,
  LTE_PREAMBLE_TRANS_MAX_N6,
  LTE_PREAMBLE_TRANS_MAX_N7,
  LTE_PREAMBLE_TRANS_MAX_N8,
  LTE_PREAMBLE_TRANS_MAX_N10,
  LTE_PREAMBLE_TRANS_MAX_N20,
  LTE_PREAMBLE_TRANS_MAX_N50,
  LTE_PREAMBLE_TRANS_MAX_N100,
  LTE_PREAMBLE_TRANS_MAX_N200
} ltePreambleTransMax_;
typedef uint8 eLtePreambleTransMax;

typedef enum			/*Rach macContentionResolutionTimer */
{
  LTE_CONTENTION_RESOLUTION_TIMER_SF8,
  LTE_CONTENTION_RESOLUTION_TIMER_SF16,
  LTE_CONTENTION_RESOLUTION_TIMER_SF24,
  LTE_CONTENTION_RESOLUTION_TIMER_SF32,
  LTE_CONTENTION_RESOLUTION_TIMER_SF40,
  LTE_CONTENTION_RESOLUTION_TIMER_SF48,
  LTE_CONTENTION_RESOLUTION_TIMER_SF56,
  LTE_CONTENTION_RESOLUTION_TIMER_SF64
} lteContentionResolutionTimer_;
typedef uint8 eLteContentionResolutionTimer;

typedef enum			/* Rach Response Window Size */
{
  LTE_RA_RESPONSE_WINDOW_2,
  LTE_RA_RESPONSE_WINDOW_3,
  LTE_RA_RESPONSE_WINDOW_4,
  LTE_RA_RESPONSE_WINDOW_5,
  LTE_RA_RESPONSE_WINDOW_6,
  LTE_RA_RESPONSE_WINDOW_7,
  LTE_RA_RESPONSE_WINDOW_8,
  LTE_RA_RESPONSE_WINDOW_10
} lteRaResponseWindow_;
typedef uint8 eLteRaResponseWindow;

typedef enum			/* Rlc Am Retransmission Thresholds */
{
  LTE_RLC_RETX_THRESHOLD_1,
  LTE_RLC_RETX_THRESHOLD_2,
  LTE_RLC_RETX_THRESHOLD_3,
  LTE_RLC_RETX_THRESHOLD_4,
  LTE_RLC_RETX_THRESHOLD_6,
  LTE_RLC_RETX_THRESHOLD_8,
  LTE_RLC_RETX_THRESHOLD_16,
  LTE_RLC_RETX_THRESHOLD_32
} lteRlcRetxThreshold_;
typedef uint8 eLteRlcRetxThreshold;

typedef enum			/* Rlc Am Poll Byte */
{
	LTE_RLCAM_POLL_BYTE_25,
	LTE_RLCAM_POLL_BYTE_50,
	LTE_RLCAM_POLL_BYTE_75,
	LTE_RLCAM_POLL_BYTE_100,
	LTE_RLCAM_POLL_BYTE_125,
	LTE_RLCAM_POLL_BYTE_250,
	LTE_RLCAM_POLL_BYTE_375,
	LTE_RLCAM_POLL_BYTE_500,
	LTE_RLCAM_POLL_BYTE_750,
	LTE_RLCAM_POLL_BYTE_1000,
	LTE_RLCAM_POLL_BYTE_1250,
	LTE_RLCAM_POLL_BYTE_1500,
	LTE_RLCAM_POLL_BYTE_2000,
	LTE_RLCAM_POLL_BYTE_3000,
	LTE_RLCAM_POLL_BYTE_infinity
} lteRlcAmPollByte_;
typedef uint8 eLteRlcAmPollByte;

typedef enum			/* Rlc Am Poll Pdu */
{
	LTE_RLCAM_POLL_PDU_4,
	LTE_RLCAM_POLL_PDU_8,
	LTE_RLCAM_POLL_PDU_16,
	LTE_RLCAM_POLL_PDU_32,
	LTE_RLCAM_POLL_PDU_64,
	LTE_RLCAM_POLL_PDU_128,
	LTE_RLCAM_POLL_PDU_256,
	LTE_RLCAM_POLL_PDU_infinity
} lteRlcAmPollPdu_;
typedef uint8 eLteRlcAmPollPdu;

typedef enum			/* Rlc Am Poll Retx Timer */
{
	LTE_RLCAM_POLL_RETX_TIMER_ms5,
	LTE_RLCAM_POLL_RETX_TIMER_ms10,
	LTE_RLCAM_POLL_RETX_TIMER_ms15,
	LTE_RLCAM_POLL_RETX_TIMER_ms20,
	LTE_RLCAM_POLL_RETX_TIMER_ms25,
	LTE_RLCAM_POLL_RETX_TIMER_ms30,
	LTE_RLCAM_POLL_RETX_TIMER_ms35,
	LTE_RLCAM_POLL_RETX_TIMER_ms40,
	LTE_RLCAM_POLL_RETX_TIMER_ms45,
	LTE_RLCAM_POLL_RETX_TIMER_ms50,
	LTE_RLCAM_POLL_RETX_TIMER_ms55,
	LTE_RLCAM_POLL_RETX_TIMER_ms60,
	LTE_RLCAM_POLL_RETX_TIMER_ms65,
	LTE_RLCAM_POLL_RETX_TIMER_ms70,
	LTE_RLCAM_POLL_RETX_TIMER_ms75,
	LTE_RLCAM_POLL_RETX_TIMER_ms80,
	LTE_RLCAM_POLL_RETX_TIMER_ms85,
	LTE_RLCAM_POLL_RETX_TIMER_ms90,
	LTE_RLCAM_POLL_RETX_TIMER_ms95,
	LTE_RLCAM_POLL_RETX_TIMER_ms100,
	LTE_RLCAM_POLL_RETX_TIMER_ms105,
	LTE_RLCAM_POLL_RETX_TIMER_ms110,
	LTE_RLCAM_POLL_RETX_TIMER_ms115,
	LTE_RLCAM_POLL_RETX_TIMER_ms120,
	LTE_RLCAM_POLL_RETX_TIMER_ms125,
	LTE_RLCAM_POLL_RETX_TIMER_ms130,
	LTE_RLCAM_POLL_RETX_TIMER_ms135,
	LTE_RLCAM_POLL_RETX_TIMER_ms140,
	LTE_RLCAM_POLL_RETX_TIMER_ms145,
	LTE_RLCAM_POLL_RETX_TIMER_ms150,
	LTE_RLCAM_POLL_RETX_TIMER_ms155,
	LTE_RLCAM_POLL_RETX_TIMER_ms160,
	LTE_RLCAM_POLL_RETX_TIMER_ms165,
	LTE_RLCAM_POLL_RETX_TIMER_ms170,
	LTE_RLCAM_POLL_RETX_TIMER_ms175,
	LTE_RLCAM_POLL_RETX_TIMER_ms180,
	LTE_RLCAM_POLL_RETX_TIMER_ms185,
	LTE_RLCAM_POLL_RETX_TIMER_ms190,
	LTE_RLCAM_POLL_RETX_TIMER_ms195,
	LTE_RLCAM_POLL_RETX_TIMER_ms200,
	LTE_RLCAM_POLL_RETX_TIMER_ms205,
	LTE_RLCAM_POLL_RETX_TIMER_ms210,
	LTE_RLCAM_POLL_RETX_TIMER_ms215,
	LTE_RLCAM_POLL_RETX_TIMER_ms220,
	LTE_RLCAM_POLL_RETX_TIMER_ms225,
	LTE_RLCAM_POLL_RETX_TIMER_ms230,
	LTE_RLCAM_POLL_RETX_TIMER_ms235,
	LTE_RLCAM_POLL_RETX_TIMER_ms240,
	LTE_RLCAM_POLL_RETX_TIMER_ms245,
	LTE_RLCAM_POLL_RETX_TIMER_ms250,
	LTE_RLCAM_POLL_RETX_TIMER_ms300,
	LTE_RLCAM_POLL_RETX_TIMER_ms350,
	LTE_RLCAM_POLL_RETX_TIMER_ms400,
	LTE_RLCAM_POLL_RETX_TIMER_ms450,
	LTE_RLCAM_POLL_RETX_TIMER_ms500
} lteRlcAmPollRetxTimer_;
typedef uint8 eLteRlcAmPollRetxTimer;

typedef enum			/* UlSch Max Harq Tx */
{
	LTE_ULSCH_MAX_HARQ_TX_n1,
	LTE_ULSCH_MAX_HARQ_TX_n2,
	LTE_ULSCH_MAX_HARQ_TX_n3,
	LTE_ULSCH_MAX_HARQ_TX_n4,
	LTE_ULSCH_MAX_HARQ_TX_n5,
	LTE_ULSCH_MAX_HARQ_TX_n6,
	LTE_ULSCH_MAX_HARQ_TX_n7,
	LTE_ULSCH_MAX_HARQ_TX_n8,
	LTE_ULSCH_MAX_HARQ_TX_n10,
	LTE_ULSCH_MAX_HARQ_TX_n12,
	LTE_ULSCH_MAX_HARQ_TX_n16,
	LTE_ULSCH_MAX_HARQ_TX_n20,
	LTE_ULSCH_MAX_HARQ_TX_n24,
	LTE_ULSCH_MAX_HARQ_TX_n28
} lteUlschMaxHarqTx_;
typedef uint8 eLteUlschMaxHarqTx;

typedef enum			/* UlSch Periodic BSR Timer */
{
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf5,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf10,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf16,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf20,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf32,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf40,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf64,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf80,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf128,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf160,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf320,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf640,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf1280,
	   LTE_ULSCH_PERIODIC_BSR_TIMER_sf2560
} lteUlSchPeriodicBsrTimer_;
typedef uint8 eLteUlSchPeriodicBsrTimer;

typedef enum			/* UlSch Retx BSR Timer */
{
	   LTE_ULSCH_RETX_BSR_TIMER_sf320,
	   LTE_ULSCH_RETX_BSR_TIMER_sf640,
	   LTE_ULSCH_RETX_BSR_TIMER_sf1280,
	   LTE_ULSCH_RETX_BSR_TIMER_sf2560,
	   LTE_ULSCH_RETX_BSR_TIMER_sf5120,
	   LTE_ULSCH_RETX_BSR_TIMER_sf10240
} lteUlSchRetxBsrTimer_;
typedef uint8 eLteUlSchRetxBsrTimer;

typedef enum			/* Timing Alignment timer in Dedicated */
{
	   LTE_TA_DEDICATED_MODE_TIMER_sf500,
	   LTE_TA_DEDICATED_MODE_TIMER_sf750,
	   LTE_TA_DEDICATED_MODE_TIMER_sf1280,
	   LTE_TA_DEDICATED_MODE_TIMER_sf1920,
	   LTE_TA_DEDICATED_MODE_TIMER_sf2560,
	   LTE_TA_DEDICATED_MODE_TIMER_sf5120,
	   LTE_TA_DEDICATED_MODE_TIMER_sf10240,
	   LTE_TA_DEDICATED_MODE_TIMER_infinity
} lteTADedicatedModeTimer_;
typedef uint8 eLteTADedicatedModeTimer;

typedef enum			/* Scheduling Request Setup Trans max */
{
	LTE_SRSETUP_DSR_TRANS_MAX_n4,
	LTE_SRSETUP_DSR_TRANS_MAX_n8,
	LTE_SRSETUP_DSR_TRANS_MAX_n16,
	LTE_SRSETUP_DSR_TRANS_MAX_n32,
	LTE_SRSETUP_DSR_TRANS_MAX_n64
} lteSrSetupDsrTransMax_;
typedef uint8 eLteSrSetupDsrTransMax;

typedef enum			/* Scheduling Request Setup Trans max */
{
	LTE_PDSCH_CONFIG_PA_VALUE_dB_6,
	LTE_PDSCH_CONFIG_PA_VALUE_dB_4dot77,
	LTE_PDSCH_CONFIG_PA_VALUE_dB_3,
	LTE_PDSCH_CONFIG_PA_VALUE_dB_1dot77,
	LTE_PDSCH_CONFIG_PA_VALUE_dB0,
	LTE_PDSCH_CONFIG_PA_VALUE_dB1,
	LTE_PDSCH_CONFIG_PA_VALUE_dB2,
	LTE_PDSCH_CONFIG_PA_VALUE_dB3
} ltePdschConfigPAValue_;
typedef uint8 eLtePdschConfigPAValue;

typedef enum			/* RLC-DL T-Reordering timer */
{
	LTE_RLCAMDL_TREORDERING_TIMER_MS0,
	LTE_RLCAMDL_TREORDERING_TIMER_MS5,
	LTE_RLCAMDL_TREORDERING_TIMER_MS10,
	LTE_RLCAMDL_TREORDERING_TIMER_MS15,
	LTE_RLCAMDL_TREORDERING_TIMER_MS20,
	LTE_RLCAMDL_TREORDERING_TIMER_MS25,
	LTE_RLCAMDL_TREORDERING_TIMER_MS30,
	LTE_RLCAMDL_TREORDERING_TIMER_MS35,
	LTE_RLCAMDL_TREORDERING_TIMER_MS40,
	LTE_RLCAMDL_TREORDERING_TIMER_MS45,
	LTE_RLCAMDL_TREORDERING_TIMER_MS50,
	LTE_RLCAMDL_TREORDERING_TIMER_MS55,
	LTE_RLCAMDL_TREORDERING_TIMER_MS60,
	LTE_RLCAMDL_TREORDERING_TIMER_MS65,
	LTE_RLCAMDL_TREORDERING_TIMER_MS70,
	LTE_RLCAMDL_TREORDERING_TIMER_MS75,
	LTE_RLCAMDL_TREORDERING_TIMER_MS80,
	LTE_RLCAMDL_TREORDERING_TIMER_MS85,
	LTE_RLCAMDL_TREORDERING_TIMER_MS90,
	LTE_RLCAMDL_TREORDERING_TIMER_MS95,
	LTE_RLCAMDL_TREORDERING_TIMER_MS100,
	LTE_RLCAMDL_TREORDERING_TIMER_MS110,
	LTE_RLCAMDL_TREORDERING_TIMER_MS120,
	LTE_RLCAMDL_TREORDERING_TIMER_MS130,
	LTE_RLCAMDL_TREORDERING_TIMER_MS140,
	LTE_RLCAMDL_TREORDERING_TIMER_MS150,
	LTE_RLCAMDL_TREORDERING_TIMER_MS160,
	LTE_RLCAMDL_TREORDERING_TIMER_MS170,
	LTE_RLCAMDL_TREORDERING_TIMER_MS180,
	LTE_RLCAMDL_TREORDERING_TIMER_MS190,
	LTE_RLCAMDL_TREORDERING_TIMER_MS200
} lteRlcAmDlTreorderingTimerValue_;
typedef uint8 eLteRlcAmDlTreorderingTimerValue;

typedef enum			/* RLC-DL T-Status Prohibit timer */
{
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS0,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS5,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS10,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS15,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS20,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS25,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS30,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS35,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS40,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS45,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS50,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS55,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS60,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS65,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS70,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS75,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS80,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS85,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS90,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS95,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS100,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS105,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS110,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS115,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS120,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS125,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS130,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS135,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS140,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS145,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS150,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS155,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS160,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS165,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS170,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS175,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS180,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS185,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS190,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS195,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS200,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS205,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS210,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS215,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS220,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS225,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS230,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS235,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS240,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS245,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS250,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS300,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS350,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS400,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS450,
	LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS500
} lteRlcAmDlTStatusProhibitTimerValue_;
typedef uint8 eLteRlcAmDlTStatusProhibitTimerValue;

typedef enum			/* periodicPHR_Timer */
{
   LTE_PERIODIC_PHR_TIMER_sf10,
   LTE_PERIODIC_PHR_TIMER_sf20,
   LTE_PERIODIC_PHR_TIMER_sf50,
   LTE_PERIODIC_PHR_TIMER_sf100,
   LTE_PERIODIC_PHR_TIMER_sf200,
   LTE_PERIODIC_PHR_TIMER_sf500,
   LTE_PERIODIC_PHR_TIMER_sf1000,
   LTE_PERIODIC_PHR_TIMER_infinity
} ltePeriodicPhrTimerValue_;
typedef uint8 eLtePeriodicPhrTimerValue;

typedef enum			/* prohibitPHR_Timer */
{
   LTE_PROHIBIT_PHR_TIMER_sf0,
   LTE_PROHIBIT_PHR_TIMER_sf10,
   LTE_PROHIBIT_PHR_TIMER_sf20,
   LTE_PROHIBIT_PHR_TIMER_sf50,
   LTE_PROHIBIT_PHR_TIMER_sf100,
   LTE_PROHIBIT_PHR_TIMER_sf200,
   LTE_PROHIBIT_PHR_TIMER_sf500,
   LTE_PROHIBIT_PHR_TIMER_sf1000
} lteProhibitPhrTimerValue_;
typedef uint8 eLteProhibitPhrTimerValue;

typedef enum			/* dl_PathlossChange */
{
   LTE_PHR_DL_PATHLOSS_dB1,
   LTE_PHR_DL_PATHLOSS_dB3,
   LTE_PHR_DL_PATHLOSS_dB6,
   LTE_PHR_DL_PATHLOSS_infinity
} ltePhrDlPathLossValue_;
typedef uint8 eLtePhrDlPathLossValue;

typedef enum			/* Type of Following ARFCN */
{
   LTE_FOLLOWING_ARFCN_EXPLICITLIST,
   LTE_FOLLOWING_ARFCN_EQUALLYSPACED,
   LTE_FOLLOWING_ARFCN_VARIABLEBITMAP
} lteSib7FollowingArfcnType_;
typedef int eLteSib7FollowingArfcnType;
/*************************************************************************************************/

typedef struct
{
   uint8 acBarringFactor;
   uint8 acBarringTime;
   uint8 acBarringForSpecialAC;
}lteBarringParams;

typedef struct  
{
    uint8 mccLength;
	uint8 mcc[3]; //Digit 0...9
	uint8 mncLength;
	uint8 mnc[3]; //Digit 0...9
}ltePlmn;

typedef struct  {
	int dlCarrierFreq;
	int cellReselectionPriority;
	int qRxLevMin;
	int threshXHigh;
	int threshXLow;
	int bandwidth;
	int tReselect;
	int cellConfig;
}lteInterFreqNeighbourCellStruct;

typedef struct  {
	int umtsCarrierFreq;
	int pMaxUTRA;
	int cellReselectionPriority;
	int qQualMin;
	int qRxLevMin;
	int threshXLow;
	int threshXHigh;
}lteUmtsNeighbourCellStruct;

typedef struct {
	int arfcn_Spacing;
	int numberOfFollowingARFCNs;
}equallySpacedARFCNs;

typedef struct {
	int noOfArfcn;
	int ARFCN_ValueGERAN[MAX_NO_OF_GSM_NEIGHBOUR_CELLS_IN_SIB7];
}explicitARFCNs;

typedef struct {
	int bitmap[16];
}variableBitMapArfcns;

typedef union {
	equallySpacedARFCNs eqArfcn;
	explicitARFCNs expArfcn;
	variableBitMapArfcns varBitMapArfcn;
}followingArfcn;

typedef struct  {
	int startingARFCN;
	eLteSib7FollowingArfcnType followingArfcnType;
	followingArfcn neighborList;
	int bandIndicator;
	int cellReselectionPriority;
	int pMaxGeran;
	int qRxLevMin;
	int threshXLow;
	int threshXHigh;
}lteGsmNeighbourCellStruct;

typedef struct  {
        int bandIndicator;
        int cellReselectionPriority;
        int threshXLow;
        int threshXHigh;
}lteCdmaBandClassStruct;

typedef struct {
         int arfcn;
         int noOfPhyCellId;
         int phyCellId[MAX_NO_OF_CDMA_NEIGHBOUR_CELL_IN_SIB8];
}lteCdmaNeighCellStruct;

typedef struct {
        int bandIndicator;
        int numberOfNeighCell;
        lteCdmaNeighCellStruct cdmaNeighCell[MAX_NO_OF_CDMA_NEIGHBOUR_CELL_IN_SIB8];
}lteCdmaNeighCellPerBandStruct;

typedef struct lteMib {
	eLteBw dlBw;
	eLtePhichDuration phichDuration;
	eLtePhichResource phichResource;
	uint8 sfn;
}lteMibStruct;

typedef struct lteServingCell {
	float rssi;
	float rsrp;
	float rsrq;
	uint32 sfNsfcellId;
	lteMibStruct mib;
	uint32 earfcn;
	uint8 noOfTxAntennaPorts;
	uint32 relativeD;
}lteServingCellStruct;

typedef struct lteSib1 {
	uint8 sibMask; // TRUE = BARRED , FALSE = NOT BARRED
	uint8 isCellBarred; // TRUE = BARRED , FALSE = NOT BARRED
	uint32 cellId; // Layer3 Cell Identity
	uint8 isIntraFreqSelectionAllowed; // TRUE-Not- Allowed , FALSE - Allowed
	uint8 noOfPlmns; // MAX = 6
	ltePlmn plmn[LTE_MAX_NO_PLMNS];
	uint16 trackingAreaCode;
	sint8 qRxLevMin; //(-70..-22)
	sint8 qRxLevMinOffset; //(1..8)
	uint8 freqBandIndicator; // (1..64)
	eLteSiPeriodicity siPeriodicity;
	eLteSiWindowLength siWindowLength;
	uint8 systemValueTag;
	sint16 pMax; //(-30..33)
	uint8 ulDLConfig;
	uint8 specialsubfAssg;
}lteSib1Struct;

typedef struct lteSib2 {
	uint8 isBarredForEmergency; // TRUE = Yes , FALSE = No
	uint8 isBarredForMoSignalling; // TRUE = Yes , FALSE = No
	lteBarringParams moSignallingBarringInfo;
	uint8 isBarredForMoData; // TRUE = Yes , FALSE = No
        lteBarringParams moDataBarringInfo;
        uint8 isBarredForMmtelVoice;
        lteBarringParams ssacMmtelVoiceBarringInfo;
        uint8 isBarredForMmtelVideo;
        lteBarringParams ssacMmtelVideoBarringInfo;
        uint8 isBarredForCsfb;
        lteBarringParams csfbBarringInfo;
	eLteBcchModificationPeriodCoeff modficationCoeff;
	eLteDrxCycle drxCycle;
	eLtePcchNB nB;
	sint8 pB;
	sint8 refSignalPower; //(-60..50)
	uint8 isHighSpeedFlagSet; //TRUE = Yes , FALSE = No
	uint8 prachConfigIndex; //(0..63)
	uint8 prachFreqOffset; //(0..94)
	uint8 prachZeroCorrelationZoneConfig; //(0..15)
	uint16 rootSequenceIndex; //(0..837)
	eLtedeltaPUCCHShift pucchDeltaShift;
	uint16 n1PucchAN; //(0..2047)
	uint8 n1CsAn;//(0..7)
	uint8 nRBCqi; //(0..98)
	uint8 enable64QAM; //TRUE = Yes , FALSE = No
	eLtePuschHoppingMode hoppingMode;
	uint8 puschNSB; //(1..4)
	uint8 puschHoppingOffset;//(0..98)
	uint8 puschRefSigCyclicShift; //(0..7)
	uint8 isGroupHoppingEnabled; // TRUE = Yes , FALSE = No
	uint8 puschGroupAssignment;//(0..29),
	uint8 isSequenceHoppingEnabled; // TRUE = Yes , FALSE = No
	uint8 maxHARQMsg3Tx ;
	eLteRachPowerRampingStep  powerRampingStep;
	eLtePreambleInitialReceivedTargetPower preambleTargetPower;
	eLteNoOfRAPreambles noRaPreambles;
	uint8 isSrsAckNackSimultaeneousTransmissionAllowed; // TRUE = Yes , FALSE = No
	eLteSrsBandwidth srsBw;
	eLteSrsSubframe srsSubframe;
	eLteCyclicPrefixLength cyclicPrefixLen;
	eLteUplinkPowerControlAlpha alpha;
	eLteDeltaPucchFormat1 format1Delta;
	eLteDeltaPucchFormat1b format1bDelta;
	eLteDeltaPucchFormat2 format2Delta;
	eLteDeltaPucchFormat2a format2aDelta;
	eLteDeltaPucchFormat2b format2bDelta;
	sint8 deltaPreambleMsg3; //(-1..6)
	sint8 p0NominalPUCCH; //(-127..-96)
	sint8 p0NominalPUSCH; //(-126..24)
	eLteUlTimeAlignmentTimer taTimer;
	eLteUeConstantN310 n310;
	eLteUeConstantN311 n311;
	eLteUeTimerT300 t300;
	eLteUeTimerT301 t301;
	eLteUeTimerT310 t310;
	eLteUeTimerT311 t311;
	eLtePreambleTransMax preambleTransMax;
	eLteContentionResolutionTimer macContentionResolutionTimer;
	eLteRaResponseWindow raResponseWindow;
	uint8 ulBandwidth;
	uint16 ulFrequency;
}lteSib2Struct;

typedef struct lteSib3 {
	eLteReselectionQhysterisis qHyst;
	uint8 cellReselectionPriority;
	sint8 threshServingLow; //(0..31)
	sint8 qRxLevMin; ////(-70..-22)
	uint8 isAntennaPort1Present; // TRUE=Yes , FALSE=No
	uint8 tReselectionEUTRA; //(0..7)
	sint8 sNonIntraSearch;
	sint8 sIntraSearch;
	uint8 neighbourCellConfig;
}lteSib3Struct;

typedef struct lteSib4 {
	int noOfBlackListIntraNeighbourCells;
	int blackListedIntraNeighbourCells[MAX_NO_OF_BLACKLISTED_NEIGHBOUR_CELLS_IN_SIB4];
	int noOfIntraNeighbourCells;
	int neighbourIntraCells[MAX_NO_OF_NEIGHBOUR_CELLS_INTRA_IN_SIB4];
	int neighbourIntraCellQOffset[MAX_NO_OF_NEIGHBOUR_CELLS_INTRA_IN_SIB4];
}lteSib4Struct;

typedef struct lteSib5 {
	int noOfInterFreqNeighbourCells;
	lteInterFreqNeighbourCellStruct interFreqNeighbourCell[MAX_NO_OF_NEIGHBOUR_CELLS_INTER_IN_SIB5];
}lteSib5Struct;

typedef struct lteSib6 {
	int noOfUmtsNeighborCells;
	lteUmtsNeighbourCellStruct umtsNeighbourCell[MAX_NO_OF_UMTS_NEIGHBOUR_CELLS_IN_SIB6];
	int tReselectionUTRA;
}lteSib6Struct;

typedef struct lteSib7 {
	int noOfGsmNeighborCells;
	lteGsmNeighbourCellStruct gsmNeighbourCell[MAX_NO_OF_GSM_NEIGHBOUR_CELLS_IN_SIB7];
	int tReselectionGERAN;
}lteSib7Struct;

typedef struct lteSib8 {
	int tReselectionCDMA2000;
	int numberOfBandClass;
	lteCdmaBandClassStruct cdmaBandClass[MAX_NO_OF_CDMA_BAND_CLASS_IN_SIB8];
        int numberOfNeighCellPerBand;
	lteCdmaNeighCellPerBandStruct cdmaNeighCellPerBand[MAX_NO_OF_CDMA_NEIGHBOUR_CELL_IN_SIB8];
}lteSib8Struct;

typedef struct lteSibs {
	uint8 sibMask;
	uint8 isitTdd;
	lteSib2Struct sib2;
	lteSib3Struct sib3;
	lteSib4Struct sib4;
	lteSib5Struct sib5;
	lteSib6Struct sib6;
	lteSib7Struct sib7;
	lteSib8Struct sib8;
}lteSibsStruct;

typedef struct lteRrcConnSetup {
	uint8 rrcTransactionId;
	uint8 srbIdentity;
	eLteRlcRetxThreshold rlcAmMaxRetxThreshold;
	eLteRlcAmPollByte rlcAmPollByte;
	eLteRlcAmPollPdu rlcAmPollPdu;
	eLteRlcAmPollRetxTimer rlcAmPollRetxTimer;
	eLteUlschMaxHarqTx ulSchMaxHarqTx;
	eLteUlSchPeriodicBsrTimer ulSchPeriodicBsrTimer;
	eLteUlSchRetxBsrTimer ulSchRetxBsrTimer;
	eLteTADedicatedModeTimer taTimerDedicated;
	eLtePdschConfigPAValue pdschPAValue;
	eLteSrSetupDsrTransMax dsrTransMax;
	uint16 srConfigIndex;
	uint16 srPucchResourceIndex;
	eLteRlcAmDlTreorderingTimerValue rlcAmDlTreorderingTimer;
	eLteRlcAmDlTStatusProhibitTimerValue rlcAmDlTStatusReorderingTimer;
	eLtePhrDlPathLossValue phrDlPathLoss;
	eLteProhibitPhrTimerValue phrProhibitTimerValue;
	eLtePeriodicPhrTimerValue phrPeriodicTimerValue;
	uint8 lteDuplexMode;
}lteRrcConnSetupStruct;

// Structure for MSG5
typedef struct lteRrcConnSetupComplete {
	uint8 rrcTransactionId;
	uint32 plmnid; // selected plmn id
	ltePlmn plmn; // plmn identifty
	uint16 mmegi; // MME group identifier
    uint8 mmec;  // MME code
    unsigned char pNasMsg[LTE_MAX_RRC_MSG_SIZE];
}lteRrcConnSetupCompleteStruct;

/*
 * UL CCCH Data
 */
#define LTE_UL_CCCH_RRC_CONN_REQ     1
#define LTE_UL_CCCH_RRC_CONN_REESTAB 0
typedef struct lteUlCCCHMsg {
	uint8 msgType;
        uint8 emergencyCall;
}lteUlCCCHMsgStruct;
/*
* UL DCCH Data
*/
typedef enum
{
	UL_INVALID_MSG_TYPE,
	UL_IDENTITY_RESPONSE_MSG,
	UL_SECURITY_MODE_FAILURE,
	UL_UECAPA_INFO,
	UL_PROXIMITY_IND,
	UL_RECONF_CMPLT,
	UL_MEAS_REPORT,
}lteUlMsgType;

typedef enum
{
  ASN_4G_INTRA_FREQ_CELL_MEASUREMENT = 0,
  ASN_4G_INTER_FREQ_CELL_MEASUREMENT,
  ASN_4G_INTER_RAT_GSM_CELL_MEASUREMENT,
  ASN_4G_INTER_RAT_UMTS_CELL_MEASUREMENT
}asn4GNeighourMeasType;

typedef struct
{
   int   pci;
   int   dlRsrp;
   float dlRsrq;
}asn4gPerCellMeas;

typedef struct
{
   unsigned int          numCell;
   asn4gPerCellMeas      perIntraCellResult[10];
}asn4gIntraFreqMeasResult;

typedef struct
{
   unsigned int          numCell;
   unsigned int          earfcn_DL; 
   asn4gPerCellMeas      perInterCellResult[10];
}asn4gInterFreqMeasResult;

typedef struct
{
    int          rssi;
    unsigned int arfcn;
    unsigned int bandIndicator;
    unsigned int ncc;
    unsigned int bcc;
}asn4gGsmPerCellMeas;

typedef struct
{
   unsigned int          numCell;
   asn4gGsmPerCellMeas   perInterRatGsmCellResult[10];
}asn4gInterRatGsmMeasResult;

typedef struct
{
    unsigned int   psc;
    int            rscp;
}asn4gUmtsPerCellMeas;

typedef struct
{
   unsigned int           numCell;
   unsigned int           uarfcn_DL;
   asn4gUmtsPerCellMeas   perInterRatUmtsCellResult[10];
}asn4gInterRatUmtsMeasResult;

typedef union 
{
   asn4gIntraFreqMeasResult      intraFreqResult;
   asn4gInterFreqMeasResult      interFreqResult;
   asn4gInterRatGsmMeasResult    interRatGsmResult;
   asn4gInterRatUmtsMeasResult   interRatUmtsResult;
}asnMeasResult;

typedef enum
{
   ASN_4G_OWN_CELL_MEASUREMENT = 0,
   ASN_4G_NEIGHBOR_CELL_MEASUREMENT
}asnLteMeasurementType;

typedef struct _lterrcUlDCCHData_t
{
	uint8  nasMsgLen;
	uint8  pNasMsg[LTE_MAX_RRC_MSG_SIZE];
	lteUlMsgType  ulMsgType;
	sint64 rsrp;
	sint64 rsrq;
        asnLteMeasurementType  measurementType;
        int                    measId;
        asn4GNeighourMeasType  neighMeasType;
        asnMeasResult          measResult;
        uint8                  measReportEmpty;
}lteRrcUlDCCHData;

typedef struct lteRrcGsmRedirectInfo_t
{
   uint16      startingarfcn;
  // enum { DCS1800,PCS1900}
   uint8 bandIndicator;
}lteRrcGsmRedirectInfo;

typedef struct lteRrcCdmaRedirectInfo_t
{
   uint16  startingarfcn;
   uint8   bandIndicator;
}lteRrcCdmaRedirectInfo;

typedef uint16 lteRrcUtraFDDRedirectInfo;
typedef uint16 lteRrcRedirectEarfcn;

typedef union rrcGsmRedirectInfo_t
{
	lteRrcGsmRedirectInfo gsmRedirectinfo;
	lteRrcUtraFDDRedirectInfo utraFDDRedirectInfo;
	lteRrcRedirectEarfcn  lteRrcEarfcn;
	lteRrcCdmaRedirectInfo cdmaRedirectinfo;
}lteRrcRedirectInfo;


typedef struct RrcConnRelStruct
{
	uint8	rrcTransactionId;
	uint8	releaseCause;
	// enum { NONE,GERAN, UTRAFDD}redirectInfoPresence ;
	uint8   redirectInfoPresence;
	lteRrcRedirectInfo	 RedirectedCarrierInfo;
}lteRrcConnRelStruct;

typedef struct dlPagingStruct
{
	uint8	cnDomain;
	uint8   imsiLength;
	uint8   uePageCount;
	uint8   mmec[MAX_PAGE_UE_4G];
	uint32  m_Tmsi[MAX_PAGE_UE_4G];
	int     imsi[MAX_PAGE_UE_4G][MAX_IDENTITY_LENGTH_STR_4G];
}lteDlPagingStruct;

typedef struct
{
   int                        dlEarfcn;
   int                        bandWidth;
}asn4gUeMeasInterFreqNeighbr;

typedef struct
{
   int                        band; /* 0 - dsc1800Band, 1  - pcs1900Band*/
   int                        startingArfcn;
   int                        numArfcn;
   int                        arfcn[ASN_LTE_MAX_INTER_RAT_ARFCN_PER_ARFCN];
}asn4gUeMeasInterRatGsmNeighbr;

typedef struct
{
   int                        dlUarfcn;
   int                        numPSC;
   int                        psc[ASN_LTE_MAX_INTER_RAT_PSC_PER_UARFCN];
}asn4gUeMeasInterRatUmtsNeighbr;

typedef struct
{
   int                             enableIntraFreqMeasurement;
   int                             numInterFreqEarfcn;  
   asn4gUeMeasInterFreqNeighbr     interFreqNeighbrList[ASN_LTE_MAX_INTER_FREQ_CELL_LIST];
   int                             numInterRatGsmNeighbr;
   asn4gUeMeasInterRatGsmNeighbr   interRatGsmNeighbrList[ASN_LTE_MAX_INTER_RAT_GSM_CELL_LIST];
   int                             numInterRatUmtsNeighbr;
   asn4gUeMeasInterRatUmtsNeighbr  interRatUmtsNeighbrList[ASN_LTE_MAX_INTER_RAT_UMTS_CELL_LIST];
} asnLteUeMeasConfig;

typedef struct
{
   asnLteUeMeasConfig  ueLteMeasConfig;
   int                 dlEarfcn;
   int                 bandWidth;
   int                 pci;
   int                 measGapConfigured;
}LteRrcMeasurementControlData;

typedef struct
{
    int  arfcn;
    int  bandIndicator;
}asnLteGsmNeighbourCell;

typedef struct
{
    int  dlEarfcn;
    int  bandwidth;
}asnLteNeighbourCell;

typedef struct
{
    unsigned int           numberOfLteNeighbor;
    asnLteNeighbourCell    lteNeighbors[3];
    unsigned int           numberOfUmtsNeighbor;
    unsigned int           dlUarfcn[3];
    unsigned int           numberOfGsmNeighbor;
    asnLteGsmNeighbourCell gsmNeighbors[3];
}asnLteNeighborConfig;

#endif /* LTE_ASN1_DEF_H_ */
