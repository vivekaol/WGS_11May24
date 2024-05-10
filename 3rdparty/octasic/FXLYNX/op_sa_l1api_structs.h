/********************************************************************16**

                         (c) COPYRIGHT 2009 by 
                         Continuous Computing Corporation.
                         All rights reserved.

     This software is confidential and proprietary to Continuous Computing 
     Corporation (CCPU).  No part of this software may be reproduced,
     stored, transmitted, disclosed or used in any form or by any means
     other than as expressly provided by the written Software License 
     Agreement between CCPU and its licensee.

     CCPU warrants that for a period, as provided by the written
     Software License Agreement between CCPU and its licensee, this
     software will perform substantially to CCPU specifications as
     published at the time of shipment, exclusive of any updates or 
     upgrades, and the media used for delivery of this software will be 
     free from defects in materials and workmanship.  CCPU also warrants 
     that has the corporate authority to enter into and perform under the   
     Software License Agreement and it is the copyright owner of the software 
     as originally delivered to its licensee.

     CCPU MAKES NO OTHER WARRANTIES, EXPRESS OR IMPLIED, INCLUDING
     WITHOUT LIMITATION WARRANTIES OF MERCHANTABILITY OR FITNESS FOR
     A PARTICULAR PURPOSE WITH REGARD TO THIS SOFTWARE, SERVICE OR ANY RELATED
     MATERIALS.

     IN NO EVENT SHALL CCPU BE LIABLE FOR ANY INDIRECT, SPECIAL,
     CONSEQUENTIAL DAMAGES, OR PUNITIVE DAMAGES IN CONNECTION WITH OR ARISING
     OUT OF THE USE OF, OR INABILITY TO USE, THIS SOFTWARE, WHETHER BASED
     ON BREACH OF CONTRACT, TORT (INCLUDING NEGLIGENCE), PRODUCT
     LIABILITY, OR OTHERWISE, AND WHETHER OR NOT IT HAS BEEN ADVISED
     OF THE POSSIBILITY OF SUCH DAMAGE.

                       Restricted Rights Legend

     This software and all related materials licensed hereby are
     classified as "restricted computer software" as defined in clause
     52.227-19 of the Federal Acquisition Regulation ("FAR") and were
     developed entirely at private expense for nongovernmental purposes,
     are commercial in nature and have been regularly used for
     nongovernmental purposes, and, to the extent not published and
     copyrighted, are trade secrets and confidential and are provided
     with all rights reserved under the copyright laws of the United
     States.  The government's rights to the software and related
     materials are limited and restricted as provided in clause
     52.227-19 of the FAR.

                    IMPORTANT LIMITATION(S) ON USE

     The use of this software is limited to the use set
     forth in the written Software License Agreement between CCPU and
     its Licensee. Among other things, the use of this software
     may be limited to a particular type of Designated Equipment, as 
     defined in such Software License Agreement.
     Before any installation, use or transfer of this software, please
     consult the written Software License Agreement or contact CCPU at
     the location set forth below in order to confirm that you are
     engaging in a permissible use of the software.

                    Continuous Computing Corporation
                    9450, Carroll Park Drive
                    San Diego, CA-92121, USA

                    Tel: +1 (858) 882 8800
                    Fax: +1 (858) 777 3388

                    Email: support@trillium.com
                    Web: http://www.ccpu.com

*********************************************************************17*/
/********************************************************************20**
  
     Name:     Femto Access Point
  
     Type:     C Source Code.
  
     Desc:     This file contains femto access point l1api structures

     File:     op_sa_l1api_structs.h

     Sid:      op_sa_l1api_structs.h@@/main/3 - Mon Aug 10 21:05:23 2009
  
     Prg:      ns
  
*********************************************************************21*/
/****************************************************************************
 *
 * Module Name: op_sa_l1api.h
 *
 * Description:
 *
 * UMTS L1 API for the picoArray.
 *
 * Author: Liam Wickins
 *
 ***************************************************************************/

/* Dependencies ---------------------------------------------------------- */

#include "op_std_def.h"
#include "l1IntEnums.h"

/* Prevent nested includes */
#ifndef __SA_L1API_STRUCTS_H__
#define __SA_L1API_STRUCTS_H__

#ifdef __cplusplus

EXTERN "C" {

#endif

/*#include "l1IntEnums.h"*/

/* Macros ---------------------------------------------------------------- */
#define dB_TO_PICHPOWER(x)      ((x) + 10)
#define dB_TO_AICHPOWER(x)      ((x) + 22)
#define dB_TO_MAXTXPOWER(x)     ((x)*10)
#define dB_TO_DLTXPOWER(x)      (((x)*10) + 350)
#define dBm_TO_PCPICHPOWER(x)   (((x)*10) + 100)

/* Constants ------------------------------------------------------------- */

#define L1_MODULE_ID    2
#define L1API_MODULE_ID 3
#define  L1_MAX_REF_ETFCI_COUNT  8
#define  L1_MAX_NUM_MACDPDUSIZE  32
#define  L1_MAX_NUM_LOGICAL_CHANS  16
#define  L1_MAX_NUM_EDCH_MACD_FLOWS  8

#ifndef OP_PRC_L1
#define  OP_EDCH_NON_SCHED_GRANT 0
#define  OP_EDCH_SCHED_GRANT 1

#define OP_PUNC_LIMIT_8 8

#define OP_ETTI_2MS  0 
#define OP_ETTI_10MS 1

#define OP_EDCH_HSDSCH_NOT_CONFIGURED 0
#define OP_EDCH_HSDSCH_CONFIGURED 1
#endif

/* Transmission Time Interval */
enum l1api_tti_e {
  L1API_TTI_10MS,
  L1API_TTI_20MS,
  L1API_TTI_40MS,
  L1API_TTI_80MS
};

/* CRC size */
enum l1api_crc_size_e {
  L1API_CRC_SIZE_NONE,
  L1API_CRC_SIZE_8BITS,
  L1API_CRC_SIZE_12BITS,
  L1API_CRC_SIZE_16BITS,
  L1API_CRC_SIZE_24BITS
};

/* Channel coding */
enum l1api_chan_coding_e {
  L1API_CHAN_CODING_NONE,
  L1API_CHAN_CODING_CONV_1_2,
  L1API_CHAN_CODING_CONV_1_3,
  L1API_CHAN_CODING_TURBO_1_3
};

/* Multiplexing position */
enum l1api_mux_pos_e {
  L1API_MUX_POS_FIXED,
  L1API_MUX_POS_FLEXIBLE
};

/* TFCI split (on DPCCH for PDSCH) */
enum l1api_tfci_split_e {
  L1API_TFCI_SPLIT_NORMAL,
  L1API_TFCI_SPLIT_HARD,
  L1API_TFCI_SPLIT_LOGICAL
};

/* Gain factor  */
enum l1api_gain_factor_e {
  L1API_GAIN_FACTOR_SIGNALLED,
  L1API_GAIN_FACTOR_COMPUTED
};

/* Diversity modes */
enum l1api_diversity_mode_e {
  L1API_DIVERSITY_MODE_NONE,
  L1API_DIVERSITY_MODE_STTD,
  L1API_DIVERSITY_MODE_CLOSED_LOOP_1,
  L1API_DIVERSITY_MODE_CLOSED_LOOP_2
};

/* Scrambling code lengths */
enum l1api_scram_code_length_e {
  L1API_SCRAM_CODE_LENGTH_SHORT,
  L1API_SCRAM_CODE_LENGTH_LONG
};

/* SSDT Cell ID lengths */
enum l1api_ssdt_cell_id_length_e {
  L1API_SSDT_CELL_ID_LENGTH_SHORT,
  L1API_SSDT_CELL_ID_LENGTH_MEDIUM,
  L1API_SSDT_CELL_ID_LENGTH_LONG
};

/* TX gap pattern sequence coding */
enum l1api_tx_gap_pattern_sequence_e {
  L1API_TX_GAP_PATTERN_SEQUENCE_NO_CHANGE,
  L1API_TX_GAP_PATTERN_SEQUENCE_CHANGE
};

/* TX gap pattern sequence coding */
enum l1api_sf_e {
  L1API_SF_4,
  L1API_SF_8,
  L1API_SF_16,
  L1API_SF_32,
  L1API_SF_64,
  L1API_SF_128,
  L1API_SF_256
};

/* Closed loop timing mode */
enum l1api_closed_loop_timing_mode_e {
  L1API_CLOSED_LOOP_TIMING_MODE_OFFSET_1,
  L1API_CLOSED_LOOP_TIMING_MODE_OFFSET_2
};

/* Measurement type */
enum l1api_measurement_type_e {
  L1API_MEASUREMENT_TYPE_RX_TOTAL_WIDEBAND_POWER,
  L1API_MEASUREMENT_TYPE_TX_CARRIER_POWER,
  L1API_MEASUREMENT_TYPE_ACKED_PRACH_PREAMBLES,
  L1API_MEASUREMENT_TYPE_UL_TIMESLOT_ISCP,
  L1API_MEASUREMENT_TYPE_ACKED_PCPCH_AP,
  L1API_MEASUREMENT_TYPE_DETECTED_PCPCH_AP,
  L1API_MEASUREMENT_TYPE_SIR,
  L1API_MEASUREMENT_TYPE_SIR_ERROR,
  L1API_MEASUREMENT_TYPE_TX_CODE_POWER,
  L1API_MEASUREMENT_TYPE_RSCP,
  L1API_MEASUREMENT_TYPE_RX_TIMING_DEVIATION,
  L1API_MEASUREMENT_TYPE_ROUND_TRIP_TIME
};

/* Measurement reporting mode */
enum l1api_measurement_report_mode_e {
  L1API_MEASUREMENT_REPORT_ON_DEMAND,
  L1API_MEASUREMENT_REPORT_PERIODIC,
  L1API_MEASUREMENT_REPORT_EVENT_A,
  L1API_MEASUREMENT_REPORT_EVENT_B,
  L1API_MEASUREMENT_REPORT_EVENT_C,
  L1API_MEASUREMENT_REPORT_EVENT_D,
  L1API_MEASUREMENT_REPORT_EVENT_E,
  L1API_MEASUREMENT_REPORT_EVENT_F
};

/* AGC mode */
enum l1api_agc_mode_e {
  L1API_AGC_MODE_CLOSED,
  L1API_AGC_MODE_OPEN
};

/* Clock Mode */
enum l1api_clk_src_e {
  L1API_CLKSRC_NONE,
  L1API_CLKSRC_EXT_10MHZ
};

/* Types ----------------------------------------------------------------- */

/* UARFCN; UTRA Absolute Frequency Channel Number */
typedef U16 l1api_uarfcn_t;

/* Cell timing offset */
typedef U8 l1api_t_cell_t;

/* Maximum cell transmission power */
typedef U16 l1api_max_tx_power_t;

/* Closed loop timing adjustment mode */
typedef U8 l1api_closed_loop_timing_mode_t;

/* DL TPC 01 count */
typedef U8 l1api_dl_tpc_01_count_t;

/* DL TPC mode */
typedef U8 l1api_dl_tpc_mode_t;

/* Primary scrambling code */
typedef U16 l1api_primary_scram_code_t;

/* DL power raise limit */
typedef U8  l1api_dl_power_raise_limit_t;

/* DL power averaging window size */
typedef U8 l1api_dl_power_averaging_window_size_t;

/* CPICH power */
typedef U16 l1api_cpich_power_t;

/* Reference power */
typedef U32 l1api_reference_power_t;

/* Number of transport format combinations */
typedef U16 l1api_n_tfc_t;

/* Number of slot formats */
typedef U8 l1api_n_sf_t;

/* Power offset for TFCI */
typedef U8 l1api_po_tfci_t;

/* Power offset for pilots */
typedef U8 l1api_po_pilot_t;

/* Power offset for TPC */
typedef U8 l1api_po_tpc_t;

/* Downlink scrambling code */
typedef U8 l1api_dl_scram_code_t;

/* Channel Code */
typedef U16 l1api_chan_code_t;

/* Multiplexing position (in DL) */
/* typedef U8 l1api_mux_position_t;*/

/* Calculated transport format combination value */
typedef U32 l1api_ctfc_t;

/* Puncturing limit */
typedef U8 l1api_puncture_limit_t;

/* TTI period */
/* typedef U8 l1api_tti_t; */

/* CRC size */
/* typedef U8 l1api_crc_size_t; */

/* Channel coding type */
/* typedef U8 l1api_chan_coding_t;*/

/* Rate matching attribute */
typedef U8 l1api_rate_match_attrib_t;

/* Number of transport formats */
typedef U8 l1api_n_tf_t;

/* Number of transport blocks (in set) */
typedef U16 l1api_n_tr_block_t;

/* Transport block size */
typedef U16 l1api_tr_block_size_t;

/* Number of transport channels */
typedef U16 l1api_n_trch_t;

/* Gain factor mode */
/* typedef U8 l1api_gain_factor_t;*/

/* Beta C power */
typedef U8 l1api_beta_c_t;

/* Beta D power */
typedef U8 l1api_beta_d_t;

/* Reference number for a transport format combination */
typedef U8 l1api_tfc_ref_num_t;
typedef U8  l1api_harq_proc_alloc_2ms_tti_t;
typedef U16 l1api_dl_chan_code_t;
typedef U16 l1api_ernti_t;
typedef U8  l1api_signature_seq_t;
typedef U8  l1api_serving_grant_val_t;
/* Range [0,5000], PDU count for water mark in priority queue */
typedef U16 l1api_pri_q_water_mark_pdu_count_t;

typedef enum {
    L1API_PRIMARY_E_RNTI,
    L1API_SECONDARY_E_RNTI
} l1api_pri_sec_grant_selector_e;

typedef enum {
    L1API_E_RGCH_RELEASED,
    L1API_E_RGCH_NOT_RELEASED
} l1api_ergch_release_ind_e;
typedef enum {
    L1API_V_N_256,
    L1API_V_N_128,
    L1API_V_N_64,
    L1API_V_N_32,
    L1API_V_N_16,
    L1API_V_N_8,
    L1API_V_N_4,
    L1API_V_2XN_4,
    L1API_V_2XN_2,
    L1API_V_2XN_2_PLUS_2XN_4
} l1api_max_set_edpdch_e;

typedef enum {
	L1API_ETTI_10MS,
	L1API_ETTI_2MS
} l1api_etti_e;

typedef enum {
    L1API_RV_0,
    L1API_RV_INDEX
} l1api_harq_info_for_edch_e;

typedef enum {
    L1API_HS_DSCH_CONFIGURED,
    L1API_HS_DSCH_NOT_CONFIGURED
} l1api_hsdsch_configured_ind_e;

typedef enum {
    L1API_EDCH_NON_SCHEDULED_TX_GRANT,
    L1API_EDCH_SCHEDULED_TX_GRANT
} l1api_edch_grant_type_e;

typedef enum {
    L1API_BUNDLING,
    L1API_NO_BUNDLING
} l1api_bundling_mode_ind_e;

typedef enum {
    L1API_SCHED_INFO_INCLUDED,
    L1API_SCHED_INFO_NOT_INCLUDED
} l1api_sched_info_e;

typedef enum {
    L1API_MACE_RESET,
    L1API_MACE_NO_RESET
} l1api_mace_reset_Ind_e;

typedef enum {
    L1API_CODE_ADJ_REMOVE,
    L1API_CODE_ADJ_REPLACE
} l1api_code_adj_choice_e;
typedef enum {
    L1API_EDCH_RL_IND_EDCH,
    L1API_EDCH_RL_IND_NO_EDCH
} l1api_edch_rl_ind_e;

typedef enum {
    L1API_RL_IN_THIS_NODEB,
    L1API_RL_NOT_IN_THIS_NODEB
} l1api_serving_edch_rl_location_e;

typedef enum {
    L1API_UL_DPDCH_PRESENT,
    L1API_UL_DPDCH_NOT_PRESENT
} l1api_ul_dpch_ind_edch_e;

/* Transport format dynamic information */
typedef struct l1api_tf_s {
  l1api_n_tr_block_t    tr_blocks;
  l1api_tr_block_size_t tr_block_size;
} l1api_tf_t;

/* Downlink transmit power step size */
typedef enum {
    L1API_STEP_SIZE_0_5_DB,
    L1API_STEP_SIZE_1_0_DB,
    L1API_STEP_SIZE_1_5_DB,
    L1API_STEP_SIZE_2_0_DB
} l1api_tpc_dl_step_size_t;

/* Number of power control preamble frames before synchronization */
typedef U8 l1api_n_pcp_t;

/* Allowed diversity modes */
typedef enum {
    L1API_DIV_MODE_NONE,
    L1API_DIV_MODE_STTD,
    L1API_DIV_MODE_CLOSED1
} l1api_diversity_mode_t;

/* Length of UL scrambling codes */
typedef U32 l1api_scram_code_num_t;
typedef enum {
    L1API_SCRAM_CODE_SHORT,
    L1API_SCRAM_CODE_LONG
} l1api_scram_code_length_t;

/* Minimum channelization code length */
typedef enum {
    L1API_MIN_CHAN_CODE_4,
    L1API_MIN_CHAN_CODE_8,
    L1API_MIN_CHAN_CODE_16,
    L1API_MIN_CHAN_CODE_32,
    L1API_MIN_CHAN_CODE_64,
    L1API_MIN_CHAN_CODE_128,
    L1API_MIN_CHAN_CODE_256
} l1api_min_chan_code_length_t;

/* UL scrambling code */
typedef U32 l1api_ul_scram_code_t;

/* Maximum number of uplinkn DPDCHes */
typedef U8 l1api_max_n_ul_dpdch_t;

/* Slot format for an UL DPCCH */
typedef U8 l1api_dpcch_ul_slot_format_t;

/* Uplink SIR target */
typedef U8 l1api_ul_sir_target_t;

/* SSDT Cell identifier length */
typedef U8 l1api_ssdt_cell_id_length_t;

/* S-Field length */
typedef U8 l1api_s_field_length_t;

/* Downlink power */
typedef U16 l1api_dl_power_t;

/* Downlink DPDCH slot format */
typedef U8 l1api_dpdch_dl_slot_format_t;

/* SSDT Cell identifier */
typedef U8 l1api_ssdt_cell_id_t;

/* TFCI Signalling mode */
typedef U8 l1api_tfci_signalling_mode_t;

/* TFCI field 2 size */
typedef U8 l1api_tfci2_size_t;

/* Number of DL channelization codes */
typedef U8 l1api_n_dl_codes_t;

/* Transmission gap pattern sequence */
typedef enum {
    L1API_CODE_CHANGE,
    L1API_NO_CODE_CHANGE,
    L1API_FIELD_NOT_PRESENT
} l1api_tx_gap_pattern_sequence_t;


/* Connection Frame Number (5-bit) */
typedef U8 l1api_cfn_t;
typedef U16 l1api_cfn_pch_t;


/* System Frame Number (12-bit) */
typedef U16 l1api_sfn_t;

/* NodeB Frame Number (12-bit) */
typedef U16 l1api_bfn_t;

/* Transport Format Indicator */
typedef U8 l1api_tfi_t;

/* Propagation Delay */
typedef U8 l1api_propagation_delay_t;

/* CRC indicator */
typedef U8 l1api_crci_t;

/* Paging Indicator Bitmap */
typedef U8 l1api_pi_bitmap_t;

/* FACH Tranmission Power Level */
typedef U8 l1api_tx_power_level_t;

/* DSCH code number */
typedef U8 l1api_code_number_t;

/* DSCH spreading factor */
typedef U8 l1api_sf_t;

/* DSCH power offset */
typedef U8 l1api_power_offset_t;

/* DSCH multi-code information */
typedef U8 l1api_mc_info_t;

/* Quality Estimate */
typedef U8 l1api_qe_t;

/* PRACH slot format */
typedef U8 l1api_prach_slot_format_t;

/* PRACH preamble threshold */
typedef U8 l1api_prach_preamble_threshold_t;

/* PRACH preamble signatures */
typedef U16 l1api_prach_preamble_signatures_t;

/* PRACH sub-channel numbers */
typedef U16 l1api_prach_sub_chan_numbers_t;

/* SCCPCH slot format */
typedef U8 l1api_sccpch_slot_format_t;

/* SCCPCH offset */
typedef U8 l1api_sccpch_offset_t;

/* SCCPCH max FACH power */
typedef U16 l1api_max_fach_power_t;

/* SCCPCH PCH power */
typedef U16 l1api_pch_power_t;

/* SCH power */
typedef U16 l1api_sch_power_t;

/* PCCPCH power */
typedef U16 l1api_pccpch_power_t;

/* PCCPCH power */
typedef U16 l1api_n_phys_chan_t;

/* AICH power */
typedef U8 l1api_aich_power_t;

/* AICH timing */
/* typedef U8 l1api_aich_timing_t; */

/* PICH mode */
/* typedef U8 l1api_pich_mode_t; */

/* PICH power */
typedef U8 l1api_pich_power_t;

/* Number of DCHes */
typedef U8 l1api_n_dch_t;

/* Number of in-sync events before radio link is synchronized */
typedef U8 l1api_n_insync_t;

/* Number of out-sync events before radio link is out-of-sync */
typedef U8 l1api_n_outsync_t;

/* Time (in 100ms steps) to elapse before radio link failure is signalled */
typedef U8 l1api_t_rlfailure_t;

/* Frame offset */
typedef U8 l1api_frame_offset_t;

/* Chip offset */
typedef U16 l1api_chip_offset_t;

/* L1API identifier */
typedef void *l1api_id_t;

/* L1 Entity */
typedef U8 l1api_entity_t;

/* Measurement type */
typedef U8 l1api_measurement_type_t;

/* Measurement reporting mode */
typedef U8 l1api_measurement_report_mode_t;

/* OCNS power */
typedef U16 l1api_ocns_power_t;

/* AGC mode */
typedef U8 l1api_agc_mode_t;

/* AWGN power */
typedef U32 l1api_awgn_power_t;

/* Cell Id */
typedef U16 l1api_cell_id_t;

/* Local Cell Id */
typedef U8 l1api_local_cell_id_t;

/* Common Transport Channel Id */
typedef U8 l1api_common_trch_id_t;

/* Common Physical Channel Id */
typedef U8 l1api_common_phys_id_t;

/* Payload CRC Present */
typedef enum {
    L1API_PAYLOAD_CRC_PRESENT,
    L1API_PAYLOAD_CRC_NOT_PRESENT
} l1api_payload_crc_present_t;

/* FP Mode in the Uplink Direction */
typedef enum {
    L1API_FP_NORMAL,
    L1API_FP_SILENT
} l1api_ul_fp_mode_t;

/* Common transport channel type */
enum l1api_entity_e {
  L1API_ENTITY_CELL = 1,
  L1API_ENTITY_COMMON_TRCH,
  L1API_ENTITY_RADIO_LINK,
  L1API_ENTITY_RADIO_LINK_SET,
  L1API_ENTITY_TRCH,
  L1API_ENTITY_PHYS_CHAN,
  L1API_ENTITY_MEASUREMENT
};

/* TPC modes */
enum l1api_tpc_mode_e {
  L1API_DL_TPC_MODE_DEFAULT,
  L1API_DL_TPC_MODE_ONE_SHOT,
  L1API_DL_TPC_MODE_CONTINUOUS
};

/**************************************************************/
/* API setup structures */
/**************************************************************/

/* DL Power Ctrl Request */
typedef struct l1api_dl_pwr_ctrl_request_s {
   l1api_id_t                      id;
   U8                              inner_loop_pwr_ctrl_flag;
} l1api_dl_pwr_ctrl_request_t;

/* Common Measurement Init Request */
typedef struct l1api_common_measurement_s {
  l1api_entity_t                  object_type;
  U32                             meas_id;
  l1api_measurement_type_t        measurement_type;
  U8                              filter_coefficient;
  l1api_measurement_report_mode_t reporting_mode;
  BOOL                            sfn_required;
  l1api_sfn_t                     sfn;
  union {
    struct {
      U8  scale;
      U16 reporting_frequency;
    } periodic;
    struct {
      U16 threshold_value;
      U16 hysterisis_time;
    } event_a;
    struct {
      U16 threshold_value;
      U16 hysterisis_time;
    } event_b;
    struct {
      U16 delta_threshold;
      U16 delta_time;
    } event_c;
    struct {
      U16 delta_threshold;
      U16 delta_time;
    } event_d;
    struct {
      U16 threshold_value1;
      U16 threshold_value2;
      U16 hysterisis_time;
      U16 reporting_frequency;
    } event_e;
struct {
      U16 threshold_value1;
      U16 threshold_value2;
      U16 hysterisis_time;
      U16 reporting_frequency;
    } event_f;
  } report_char;
} l1api_common_measurement_t;

/* Dedicated Measurement Init Request */
typedef struct l1api_dedicated_measurement_s {
  U32                             nodeBCommCtx;
  U32                             meas_id;
  l1api_measurement_type_t        measurement_type;
  U8                              rlId;
  U8                              rlsId;
  U8                              filter_coefficient;
  l1api_measurement_report_mode_t reporting_mode;
  BOOL                            cfn_required;
  l1api_sfn_t                     cfn;
  union {
    struct {
      U8  scale;
      U16 reporting_frequency;
    } periodic;
    struct {
      U16 threshold_value;
      U16 hysterisis_time;
    } event_a;
    struct {
      U16 threshold_value;
      U16 hysterisis_time;
    } event_b;
    struct {
      U16 delta_threshold;
 U16 delta_time;
    } event_c;
    struct {
      U16 delta_threshold;
      U16 delta_time;
    } event_d;
    struct {
      U16 threshold_value1;
      U16 threshold_value2;
      U16 hysterisis_time;
      U16 reporting_frequency;
    } event_e;
    struct {
      U16 threshold_value1;
      U16 threshold_value2;
      U16 hysterisis_time;
      U16 reporting_frequency;
    } event_f;
  } report_char;
} l1api_dedicated_measurement_t;

/*op003.104- Updating for L1intf */
/* Cell Setup Request */
typedef struct l1api_measurement_s {
  l1api_id_t                      id;
  l1api_entity_t                  object_type;
  l1api_id_t                      obj_id;
  l1api_measurement_type_t        measurement_type;
  U8                              filter_coefficient;
  l1api_measurement_report_mode_t reporting_mode;
  BOOL                            sfn_required;
  l1api_sfn_t                     sfn;
  union {
    struct {
      U16 reporting_frequency;
    } periodic;
    struct {
      U16 threshold_value;
      U16 hysterisis_time;
    } event_a;
    struct {
      U16 threshold_value;
      U16 hysterisis_time;
    } event_b;
    struct {
      U16 delta_threshold;
      U16 delta_time;
    } event_c;
    struct {
      U16 delta_threshold;
      U16 delta_time;
    } event_d;
    struct {
      U16 threshold_value1;
      U16 threshold_value2;
      U16 hysterisis_time;
      U16 reporting_frequency;
    } event_e;
    struct {
      U16 threshold_value1;
      U16 threshold_value2;
      U16 hysterisis_time;
      U16 reporting_frequency;
    } event_f;
  } report_params;
} l1api_measurement_t;

typedef struct l1api_cell_params_s {
  l1api_id_t                             id;
  l1api_cell_id_t                        cell_id;                       
  l1api_local_cell_id_t                  local_cell_id;
  l1api_t_cell_t                         t_cell;
  l1api_uarfcn_t                         ul_uarfcn;
  l1api_uarfcn_t                         dl_uarfcn;
  l1api_max_tx_power_t                   max_tx_power;
  l1api_closed_loop_timing_mode_t        closed_loop_timing_mode;
  l1api_dl_tpc_01_count_t                dl_tpc_01_count;
  l1api_primary_scram_code_t             primary_scram_code;
  l1api_dl_power_raise_limit_t           power_raise_limit;
  l1api_dl_power_averaging_window_size_t dl_power_averaging_window_size;
  l1api_cpich_power_t                    cpich_power;
  l1api_n_insync_t                       n_insync;
  l1api_n_outsync_t                      n_outsync;
  l1api_t_rlfailure_t                    t_rlfailure;
  l1api_reference_power_t                pcpich_reference_0dbm;
} l1api_cell_params_t;

typedef struct l1api_sch_params_s {
  l1api_common_phys_id_t    id;                     
  BOOL                      tstd_indicator;
  BOOL                      sttd_indicator;
  l1api_sch_power_t sch_power;
} l1api_sch_params_t;

typedef struct l1api_cpich_params_s {
  l1api_common_phys_id_t    id;                    
  BOOL                      diversity_indicator;
  l1api_cpich_power_t       cpich_power;          
  l1api_dl_scram_code_t     scram_code;          
  l1api_chan_code_t         chan_code;          
} l1api_cpich_params_t;

typedef struct l1api_pccpch_params_s {
  l1api_common_phys_id_t    id;                
  BOOL                      sttd_indicator;
  l1api_pccpch_power_t      pccpch_power;
} l1api_pccpch_params_t;

typedef struct l1api_common_trch_dlbasic_s
{
    l1api_common_trch_id_t  id;
    l1api_dl_power_t        pwr;
} l1api_common_trch_dlbasic_t;

typedef struct l1api_cell_s {
  l1api_cell_params_t           cell;
  l1api_sch_params_t            psch;
  U16                           n_ssch;
  l1api_sch_params_t            *ssch;
  l1api_cpich_params_t          pcpich;
  U16                           n_scpich;
  l1api_cpich_params_t          *scpich;
  l1api_pccpch_params_t         pccpch;
  l1api_common_trch_dlbasic_t   trch_common_dl_bch;
  BOOL                          ocns_indicator;
  l1api_ocns_power_t            ocns_initial_power;
} l1api_cell_t;

typedef struct l1api_cell_delete_request_s
{
    l1api_cell_id_t             cell_id;
} l1api_cell_delete_request_t;


/* Physical Shared Channel Reconfiguration Request */

typedef struct l1api_hs_pdsch_code_info_s {
    U8                      n_pdsch_codes;
    l1api_chan_code_t       pdsch_start_code;
} l1api_hs_pdsch_code_info_t;

typedef enum {
    L1API_HS_SCCH_REMOVE,
    L1API_HS_SCCH_REPLACE
} l1api_hs_scch_choice_t;

typedef struct l1api_hs_scch_code_info_s {
    l1api_hs_scch_choice_t  hs_scch_choice;
    U8                      n_scch_codes;
    l1api_chan_code_t       scch_code[8];
} l1api_hs_scch_code_info_t;

typedef struct {
    U16 paramPresentFlag;
    U8  eagch_pwr_offset;
    U8  ergch_and_hich_pwr_offset;
} l1api_rl_cmn_edch_info_t;

typedef struct {
    U16 paramPresentFlag;
    l1api_code_adj_choice_e code_adj_choice;
    U8  code_count;
    U16 code_num[8];
} l1api_eagch_code_info_t;

typedef struct {
    U16 paramPresentFlag;
    l1api_code_adj_choice_e code_adj_choice;
    U8  code_count;
    U8 code_num[8];
} l1api_ergch_high_code_info_t;
typedef struct {
    U16  paramPresentFlag;
    U8   hs_scch_cell_power_offset;
    U8   eagch_rgch_hich_scram_code;
    U16  max_target_rtwp;
    U16  ref_rtwp;
    U16  pwr_headroom;
    l1api_rl_cmn_edch_info_t rl_common_edch_info;
    l1api_eagch_code_info_t eAgchCodeInfo;
    l1api_ergch_high_code_info_t eRgchHichCodeInfo;
} l1api_phys_sh_ch_rcfg_extensions_t;
typedef struct l1api_physical_shared_ch_reconfig_request_s {
    l1api_cell_id_t             cell_id; /* Cell identifier */
    l1api_sfn_t                 sfn;
    l1api_max_tx_power_t        hs_pdsch_scch_total_power;
    l1api_dl_scram_code_t       hs_pdsch_scch_scram_code;
    l1api_hs_pdsch_code_info_t  hs_pdsch_code_info;
    l1api_hs_scch_code_info_t   hs_scch_code_info;
    l1api_phys_sh_ch_rcfg_extensions_t phys_sh_ch_rcfg_extentions;
} l1api_physical_shared_ch_reconfig_request_t;


/* System Info Update Request */

typedef U16 l1api_bch_mod_sfn_t;

typedef enum
{
    L1API_IB_TYPE_MIB,
    L1API_IB_TYPE_SB1,
    L1API_IB_TYPE_SB2,
    L1API_IB_TYPE_SIB1,
    L1API_IB_TYPE_SIB2,
    L1API_IB_TYPE_SIB3,
    L1API_IB_TYPE_SIB4,
    L1API_IB_TYPE_SIB5,
    L1API_IB_TYPE_SIB6,
    L1API_IB_TYPE_SIB7,
    L1API_IB_TYPE_SIB8,
    L1API_IB_TYPE_SIB9,
    L1API_IB_TYPE_SIB10,
    L1API_IB_TYPE_SIB11,
    L1API_IB_TYPE_SIB12,
    L1API_IB_TYPE_SIB13,
    L1API_IB_TYPE_SIB13_1,
    L1API_IB_TYPE_SIB13_2,
    L1API_IB_TYPE_SIB13_3,
    L1API_IB_TYPE_SIB13_4,
    L1API_IB_TYPE_SIB14,
    L1API_IB_TYPE_SIB15,
    L1API_IB_TYPE_SIB15_1,
    L1API_IB_TYPE_SIB15_2,
    L1API_IB_TYPE_SIB15_3,
    L1API_IB_TYPE_SIB16,
    L1API_IB_TYPE_SIB17,
    L1API_IB_TYPE_SIB15_4,
    L1API_IB_TYPE_SIB18,
    L1API_IB_TYPE_SIB15_5
} l1api_ib_type_t;

typedef U8 l1api_ib_oc_id_t;

typedef enum
{
    L1API_IB_DELETION_IND_DELETE,
    L1API_IB_DELETION_IND_ADD
} l1api_ib_deletion_ind_t;

typedef enum
{
    L1API_IB_SEG_REP_4,
    L1API_IB_SEG_REP_8,
    L1API_IB_SEG_REP_16,
    L1API_IB_SEG_REP_32,
    L1API_IB_SEG_REP_64,
    L1API_IB_SEG_REP_128,
    L1API_IB_SEG_REP_256,
    L1API_IB_SEG_REP_512,
    L1API_IB_SEG_REP_1024,
    L1API_IB_SEG_REP_2048,
    L1API_IB_SEG_REP_4096
} l1api_ib_seg_rep;

typedef U16 l1api_seg_pos_t;

typedef enum
{
    L1API_SEG_TYPE_FIRST,
    L1API_SEG_TYPE_FIRST_SHORT,
    L1API_SEG_TYPE_SUBSEQUENT,
    L1API_SEG_TYPE_LAST,
    L1API_SEG_TYPE_LAST_SHORT,
    L1API_SEG_TYPE_COMP_SIB,
    L1API_SEG_TYPE_COMP_SIB_SHORT
} l1api_seg_type_t;

typedef struct l1api_seg_info_s
{
    l1api_seg_pos_t         seg_pos;        
    l1api_seg_type_t        seg_type;       
    U8                      data_bit_cnt;
    U8                      seg_data[32];  
                                          
} l1api_seg_info_t;

#define L1API_MAX_IBSEG 16

typedef struct l1api_ib_addition_info_s
{
    l1api_ib_seg_rep        seg_rep;     
    U8                      seg_count;
    l1api_seg_info_t        seg_info[L1API_MAX_IBSEG];
} l1api_ib_addition_info_t;

typedef struct l1api_ib_info_s
{
    l1api_ib_type_t             type;         
    l1api_ib_oc_id_t            oc_id;       
    l1api_ib_deletion_ind_t     deletion_ind;
    l1api_ib_addition_info_t    addition_info;
} l1api_ib_info_t;

#define L1API_MAX_IB 64

typedef struct l1api_bch_sysinfo_s
{
    l1api_cell_id_t     cell_id;        
    l1api_bch_mod_sfn_t bcch_mod_sfn;  
    U8                  count;
    l1api_ib_info_t     info[L1API_MAX_IB];
} l1api_bch_sysinfo_t;

/* Common transport channel setup */

/* NOT NEEDED ANY MORE */
/* Common transport channel type
typedef enum {
  L1API_COMMON_TRCH_FACH_PCH,
  L1API_COMMON_TRCH_FACH,
  L1API_COMMON_TRCH_PCH,
  L1API_COMMON_TRCH_RACH
} l1api_common_trch_type_t;*/

typedef enum {
    L1API_TFCI_PRESENT,
    L1API_TFCI_NOT_PRESENT
} l1api_tfci_presence_t;


typedef enum {
    L1API_FIXED_POSITION,
    L1API_FLEXIBLE_POSITION
} l1api_mux_position_t;

typedef enum {
    L1API_STTD_ACTIVE,
    L1API_STTD_INACTIVE
} l1api_sttd_indicator_t;

typedef enum {
    L1API_TTI_10_MS,
    L1API_TTI_20_MS,
    L1API_TTI_40_MS,
    L1API_TTI_80_MS
} l1api_tti_t;

typedef enum {
    L1API_CRC_0,
    L1API_CRC_8,
    L1API_CRC_12,
    L1API_CRC_16,
    L1API_CRC_24
} l1api_crc_size_t;

typedef enum {
    L1API_CODING_NONE,
    L1API_CODING_CONV_12,
    L1API_CODING_CONV_13,
    L1API_CODING_TURBO_13
} l1api_channel_coding_type_t;

typedef enum {
    L1API_PICH_PI_18,
    L1API_PICH_PI_36,
    L1API_PICH_PI_72,
    L1API_PICH_PI_144
} l1api_pich_mode_t;

typedef enum {
    L1API_AICH_TIMING_0,
    L1API_AICH_TIMING_1
} l1api_aich_timing_t;

typedef enum {
    L1API_SIGNALLED_GF,
    L1API_COMPUTED_GF
} l1api_gain_factor_t;

typedef enum {
    L1API_QE_SELECTED,
    L1API_QE_NOT_SELECTED
} l1api_qe_selector_t;

typedef U16 l1api_toa_t;

typedef struct l1api_common_trch_info_s {
    l1api_cell_id_t     cell_id;
    U16                 tfcs_size;
} l1api_common_trch_info_t;

typedef struct l1api_cctrch_tfc_info_s {
  l1api_ctfc_t         ctfc;                        
  l1api_gain_factor_t  gain_factor_type;            
  l1api_tfc_ref_num_t  tfc_ref_num;                 
  l1api_beta_c_t       beta_c;  /* Uplink only */   
  l1api_beta_d_t       beta_d;  /* Uplink only */   
} l1api_cctrch_tfc_info_t;

typedef struct l1api_trch_tf_s {
  l1api_tti_t                   tti;                
  l1api_crc_size_t              crc_size;           
  l1api_channel_coding_type_t   chan_coding_type;   
  l1api_rate_match_attrib_t     rate_match_attrib;  
  l1api_n_tf_t                  n_tf;               
  l1api_tf_t                    *tfs;
} l1api_trch_tf_t;

typedef struct l1api_trch_dl_params_s {
  l1api_common_trch_id_t        common_trch_dl_id;
  l1api_dl_power_t              channel_pwr;
  l1api_toa_t                   toAWS;                  
  l1api_toa_t                   toAWE;                  
  l1api_trch_tf_t               trch_tf;
} l1api_trch_dl_params_t;

typedef struct l1api_trch_ul_params_s {
  l1api_common_trch_id_t        common_trch_ul_id;
  l1api_trch_tf_t               trch_tf;
} l1api_trch_ul_params_t;

typedef struct l1api_prach_params_s {
  l1api_common_phys_id_t            common_phys_id;             
  l1api_dl_scram_code_t             scram_code;                 
  l1api_prach_preamble_threshold_t  prach_preamble_threshold;   
  l1api_prach_preamble_signatures_t prach_preamble_signatures;  
  l1api_prach_sub_chan_numbers_t    prach_sub_chan_numbers;     
  l1api_puncture_limit_t            puncture_limit;             
  l1api_n_sf_t                      n_sf;                       
  l1api_prach_slot_format_t         *slot_format;               
} l1api_prach_params_t;

typedef struct l1api_aich_params_s {
  l1api_common_phys_id_t    common_phys_id;      
  l1api_sttd_indicator_t    sttd_indicator;
  l1api_aich_power_t        aich_power;          
  l1api_aich_timing_t       aich_timing;         
  l1api_chan_code_t         chan_code;           
} l1api_aich_params_t;

typedef struct l1api_sccpch_params_s {
  l1api_common_phys_id_t     common_phys_id;
  l1api_sccpch_offset_t      sccpch_offset;
  l1api_sttd_indicator_t     sttd_indicator;
  l1api_po_tfci_t            po_tfci;       
  l1api_po_pilot_t           po_pilot;      
  l1api_sccpch_slot_format_t slot_format;   
  l1api_tfci_presence_t      tfci_presence;
  l1api_dl_scram_code_t      scram_code;    
  l1api_chan_code_t          chan_code;     
  l1api_mux_position_t       mux_position;  
  l1api_max_fach_power_t     max_fach_power;
  l1api_pch_power_t          pch_power;     
  l1api_power_offset_t       power_offset1;
  l1api_power_offset_t       power_offset3;
} l1api_sccpch_params_t;

typedef struct l1api_pich_params_s {
  l1api_common_phys_id_t    common_phys_id;
  l1api_pich_mode_t         pich_mode;      
  BOOL                      sttd_indicator;
  l1api_pich_power_t        pich_power;     
  l1api_chan_code_t         chan_code;      
} l1api_pich_params_t;

typedef struct l1api_cctrch_params_s {
  l1api_n_tfc_t                 n_tfc;      
  l1api_cctrch_tfc_info_t       *tfc_info;
} l1api_cctrch_params_t;

typedef struct l1api_fach_pch_s {
  l1api_common_trch_info_t  common_trch_info;
  U8                        n_FACH;
  l1api_trch_dl_params_t    pch;
  l1api_trch_dl_params_t    *fach;
  l1api_sccpch_params_t     sccpch;
  l1api_pich_params_t       pich;
  l1api_cctrch_params_t     cctrch;
} l1api_fach_pch_t;

typedef struct l1api_rach_s {
  l1api_common_trch_info_t  common_trch_info;
  l1api_trch_ul_params_t    rach;
  l1api_prach_params_t      prach;
  l1api_aich_params_t       aich;
  l1api_cctrch_params_t     cctrch;
} l1api_rach_t;

/*
THESE TYPES ARE NOT USED ANYMORE
typedef struct l1api_pch_s {
  l1api_id_t             id;
  l1api_trch_dl_params_t pch;
  l1api_sccpch_params_t  sccpch;
  l1api_pich_params_t    pich;
  l1api_cctrch_params_t  cctrch;
} l1api_pch_t;

typedef struct l1api_fach_s {
  l1api_id_t             id;
  l1api_trch_dl_params_t fach;
  l1api_sccpch_params_t  sccpch;
  l1api_cctrch_params_t  cctrch;
} l1api_fach_t;
typedef struct l1api_common_trch_u {
  l1api_id_t               cell_id;
  l1api_common_trch_type_t type;
  union {
    l1api_fach_pch_t fach_pch;
    l1api_pch_t      pch;
    l1api_fach_t     fach;
    l1api_rach_t     rach;
  } params_u;
} l1api_common_trch_t;*/

typedef struct l1api_common_trch_delete_s {
  l1api_cell_id_t           cell_id;        
  l1api_common_phys_id_t    common_phys_id;
} l1api_common_trch_delete_t;

/* RadioLink management */

/*

typedef U8 l1api_frame_offset_t;

typedef U16 l1api_chip_offset_t;

typedef enum {
    L1API_FIXED_POSITION,
    L1API_FLEXIBLE_POSITION
} l1api_mux_position_t;

typedef U8 l1api_tpc_dl_step_size_t;

typedef U8 l1api_n_pcp_t;

typedef U8 l1api_n_dch_t;

typedef U8 l1api_common_trch_id_t;

typedef struct l1api_cctrch_params_s {
  l1api_n_tfc_t                 n_tfc;      
  l1api_cctrch_tfc_info_t       *tfc_info;
} l1api_cctrch_params_t;

typedef struct l1api_tf_s {
  l1api_n_tr_block_t    tr_blocks;
  l1api_tr_block_size_t tr_block_size;
} l1api_tf_t;

typedef struct l1api_trch_ul_params_s {
  l1api_common_trch_id_t        common_trch_ul_id;
  l1api_tti_t                   tti;                    
  l1api_qe_selector_t           qe_selector;
  l1api_crc_size_t              crc_size;               
  l1api_channel_coding_type_t   chan_coding_type;       
  l1api_rate_match_attrib_t     rate_match_attrib;      
  l1api_n_tf_t                  n_tf;                   
  l1api_tf_t                    *tfs;
} l1api_trch_ul_params_t;

typedef struct l1api_trch_dl_params_s {
  l1api_common_trch_id_t        common_trch_dl_id;
  l1api_tti_t                   tti;                    
  l1api_crc_size_t              crc_size;               
  l1api_channel_coding_type_t   chan_coding_type;       
  l1api_rate_match_attrib_t     rate_match_attrib;      
  l1api_n_tf_t                  n_tf;                   
  l1api_tf_t                    *tfs;
  l1api_toa_t                   toAWS;                  
  l1api_toa_t                   toAWE;                  
} l1api_trch_dl_params_t;

typedef U16 l1api_dl_power_t;

typedef U8 l1api_dpdch_dl_slot_format_t;

typedef U8 l1api_ssdt_cell_id_t;

typedef U8 l1api_tfci_signalling_mode_t;

typedef U8 l1api_po_tpc_t;

typedef U8 l1api_tfci2_size_t;

typedef U8 l1api_tpc_dl_step_size_t;

typedef U8 l1api_n_dl_codes_t;

typedef U8 l1api_tx_gap_pattern_sequence_t;

typedef U16 l1api_chan_code_t;

typedef U8 l1api_cfn_t;
*/

typedef U8 l1api_dch_id_t;

typedef enum {
    L1API_UPLINK_DCH_ONLY,
    L1API_BI_DIRECTIONAL_DCH
} l1api_dch_dir_t;

typedef struct l1api_dch_info_s {
    l1api_dch_id_t          dch_id;
    l1api_qe_selector_t     qe_selector;
    l1api_dch_dir_t         uldl;
    l1api_trch_tf_t         trch_tf_ul;
    l1api_trch_tf_t         trch_tf_dl;
} l1api_dch_info_t;

typedef struct l1api_Nb_com_context_setup_info_s {
    U8  n_rl;
    U8  n_coord;
    U16 dl_tfcs_size;
    U16 ul_tfcs_size;
    U8  n_tgps;
} l1api_Nb_com_context_setup_info_t;

typedef struct l1api_Nb_com_context_reconfig_info_s {
    U8  n_rl;
    U8  n_coord_modify;
    U8  n_coord_add;
    U8  n_trch_del;
    U16 dl_tfcs_size;
    U16 ul_tfcs_size;
    U8  n_tgps;
} l1api_Nb_com_context_reconfig_info_t;

typedef U8  l1api_rl_id_t;

typedef enum {
    L1API_DPC_MODE_0,
    L1API_DPC_MODE_1
} l1api_dpc_mode_t;

typedef struct l1api_dpch_ul_params_s {
  l1api_diversity_mode_t       diversity_mode;
  l1api_scram_code_num_t       scram_code_num;
  l1api_scram_code_length_t    scram_code_length;
  l1api_min_chan_code_length_t min_chan_code_length;
  l1api_ul_scram_code_t        ul_scram_code;
  l1api_max_n_ul_dpdch_t       max_n_ul_dpdch;
  l1api_puncture_limit_t       puncture_limit;              
  l1api_dpcch_ul_slot_format_t slot_format;
  l1api_ul_sir_target_t        ul_sir_target;
  l1api_ssdt_cell_id_length_t  ssdt_cell_id_length;
  l1api_s_field_length_t       s_field_length;
  l1api_dpc_mode_t             dpc_mode;
  l1api_ul_dpch_ind_edch_e     ul_dpch_ind_edch;
} l1api_dpch_ul_params_t;

typedef struct l1api_dpch_dl_code_info_s {
  l1api_dl_scram_code_t           dl_scram_code;            
  l1api_tx_gap_pattern_sequence_t tx_gap_pattern_sequence;
  l1api_chan_code_t               chan_code;
} l1api_dpch_dl_code_info_t;


typedef enum {
    L1API_LIM_POW_INC_USED,
    L1API_LIM_POW_INC_NOT_USED
} l1api_limited_power_inc_t;

typedef enum {
    L1API_INNER_LP_PC_STAT_ACTIVE,
    L1API_INNER_LP_PC_STAT_INACTIVE
} l1api_inner_loop_status_t;

typedef struct l1api_dpch_dl_params_s {
  l1api_dpdch_dl_slot_format_t slot_format;
  l1api_ssdt_cell_id_t         ssdt_cell_id;
  l1api_tfci_signalling_mode_t tfci_signalling_mode;
  l1api_tfci_presence_t        tfci_presence;
  l1api_po_tfci_t              po_tfci;                     
  l1api_po_tpc_t               po_tpc;
  l1api_po_pilot_t             po_pilot;                    
  l1api_tfci2_size_t           tfci2_size;
  l1api_tpc_dl_step_size_t     tpc_dl_step_size;
  l1api_power_offset_t         power_offset1;
  l1api_power_offset_t         power_offset2;
  l1api_power_offset_t         power_offset3;
  l1api_mux_position_t         mux_position;
  l1api_limited_power_inc_t    limited_power_inc;
  l1api_inner_loop_status_t    inner_loop_dlpc_status;
} l1api_dpch_dl_params_t;


typedef U8  l1api_tgps_id_t;
typedef U8  l1api_tg_start_t;
typedef U8  l1api_tg_length_t;
typedef U16 l1api_tg_distance_t;
typedef U8  l1api_tp_patt_length_t;

typedef enum {
    L1API_UL_ONLY,
    L1API_DL_ONLY,
    L1API_UL_DL
} l1api_uldl_mode_t;

typedef enum {
    L1API_SF_2,
    L1API_HIGHER_LAYER_SCHED
} l1api_cm_method_t;

typedef enum {
    L1API_FRAME_TYPE_A,
    L1API_FRAME_TYPE_B
} l1api_cm_frame_type_t;

typedef U8 l1api_delta_sir_t;

typedef struct l1api_trans_gap_patt_seq_info_s {
    l1api_tgps_id_t         tgps_id;
    l1api_tg_start_t        tg_sn;
    l1api_tg_length_t       tg_length1;
    l1api_tg_length_t       tg_length2;
    l1api_tg_distance_t     tg_distance;
    l1api_tp_patt_length_t  tg_patt_len;
    l1api_uldl_mode_t       uldl_mode;
    l1api_cm_method_t       dl_method;
    l1api_cm_method_t       ul_method;
    l1api_cm_frame_type_t   cm_frame_type;
    l1api_delta_sir_t       d_sir1;
    l1api_delta_sir_t       d_sir_after1;
    l1api_delta_sir_t       d_sir2;
    l1api_delta_sir_t       d_sir_after2;
} l1api_trans_gap_patt_seq_info_t;


typedef struct l1api_tgps_status_s {
    l1api_tgps_id_t         tgps_id;
    U16                     tgprc;
    l1api_cfn_t             tg_cfn;
} l1api_tgps_status_t;

typedef struct l1api_active_patt_seq_info_s {
    l1api_cfn_t             cm_config_change_cfn;
    U8                      n_tgpss;
    l1api_tgps_status_t     *tgpss;
} l1api_active_patt_seq_info_t;


typedef enum {
    L1API_POWER_ADJ_NONE,
    L1API_POWER_ADJ_COMMON,
    L1API_POWER_ADJ_INDIVIDUAL
} l1api_power_adj_type_t;

typedef U8   l1api_max_adj_step_t;
typedef U8   l1api_adjust_period_t;
typedef U8   l1api_adjust_ratio_t;

typedef struct l1api_adjust_info_s {
    l1api_max_adj_step_t    max_adj_step;
    l1api_adjust_period_t   adjust_period;
    l1api_adjust_ratio_t    adjust_ratio;
} l1api_adjust_info_t;

typedef struct l1api_power_adj_common_s {
    l1api_dl_power_t    dl_ref_pwr;
    l1api_adjust_info_t adjust_info;
} l1api_power_adj_common_t;


typedef struct l1api_dl_ref_power_info_s {
    l1api_rl_id_t       rl_id;
    l1api_dl_power_t    dl_ref_pwr;
} l1api_dl_ref_power_info_t;

typedef struct l1api_power_adj_indiv_s {
    U8                          n_rl;
    l1api_dl_ref_power_info_t   *dl_ref_pwr;
    l1api_adjust_info_t         adjust_info;
} l1api_power_adj_indiv_t;

typedef struct l1api_dlpower_balancing_info_s {
    l1api_power_adj_type_t      power_adj_type;
    l1api_power_adj_common_t    power_adj_common;
    l1api_power_adj_indiv_t     power_adj_individual;
} l1api_dlpower_balancing_info_t;


typedef U16 l1api_hsdsch_rnti_t;

typedef U8  l1api_hsdsch_phys_cat_t;

typedef U16 l1api_machs_reorder_buff_sz_t;

typedef enum  {
    L1API_CQI_FEEDBACK_0,
    L1API_CQI_FEEDBACK_2,
    L1API_CQI_FEEDBACK_4,
    L1API_CQI_FEEDBACK_8,
    L1API_CQI_FEEDBACK_10,
    L1API_CQI_FEEDBACK_20,
    L1API_CQI_FEEDBACK_40,
    L1API_CQI_FEEDBACK_80,
    L1API_CQI_FEEDBACK_160
} l1api_cqi_fb_cycle_t;

typedef U8  l1api_cqi_rep_factor_t;
typedef U8  l1api_ack_nack_rep_factor_t;
typedef U8  l1api_cqi_power_offset_t;
typedef U8  l1api_ack_power_offset_t;
typedef U8  l1api_nack_power_offset_t;
typedef U8  l1api_hsscch_power_offset_t;
typedef U8  l1api_meas_power_offset_t;

typedef U8  l1api_macd_flow_id_t;

typedef struct l1api_macd_flow_info_setup_s {
    l1api_macd_flow_id_t    macD_flow_id;
} l1api_macd_flow_info_setup_t;

typedef U8 l1api_priority_queue_id_t;

typedef U8 l1api_sched_priority_ind_t;

typedef enum  {
    L1API_T1_10_MS,
    L1API_T1_20_MS,
    L1API_T1_30_MS,
    L1API_T1_40_MS,
    L1API_T1_50_MS,
    L1API_T1_60_MS,
    L1API_T1_70_MS,
    L1API_T1_80_MS,
    L1API_T1_90_MS,
    L1API_T1_100_MS,
    L1API_T1_120_MS,
    L1API_T1_140_MS,
    L1API_T1_160_MS,
    L1API_T1_200_MS,
    L1API_T1_300_MS,
    L1API_T1_400_MS
} l1api_t1_t;

typedef enum {
    L1API_DIS_T1_20_MS,
    L1API_DIS_T1_40_MS,
    L1API_DIS_T1_60_MS,
    L1API_DIS_T1_80_MS,
    L1API_DIS_T1_100_MS,
    L1API_DIS_T1_120_MS,
    L1API_DIS_T1_140_MS,
    L1API_DIS_T1_160_MS,
    L1API_DIS_T1_180_MS,
    L1API_DIS_T1_200_MS,
    L1API_DIS_T1_250_MS,
    L1API_DIS_T1_300_MS,
    L1API_DIS_T1_400_MS,
    L1API_DIS_T1_500_MS,
    L1API_DIS_T1_750_MS,
    L1API_DIS_T1_1000_MS,
    L1API_DIS_T1_1250_MS,
    L1API_DIS_T1_1500_MS,
    L1API_DIS_T1_1750_MS,
    L1API_DIS_T1_2000_MS,
    L1API_DIS_T1_2500_MS,
    L1API_DIS_T1_3000_MS,
    L1API_DIS_T1_3500_MS,
    L1API_DIS_T1_4000_MS,
    L1API_DIS_T1_4500_MS,
    L1API_DIS_T1_5000_MS,
    L1API_DIS_T1_7500_MS
} l1api_discard_timer_t;

typedef enum {
    L1API_MACHS_WIN_SZ_4,
    L1API_MACHS_WIN_SZ_6,
    L1API_MACHS_WIN_SZ_8,
    L1API_MACHS_WIN_SZ_12,
    L1API_MACHS_WIN_SZ_16,
    L1API_MACHS_WIN_SZ_24,
    L1API_MACHS_WIN_SZ_32
} l1api_machs_window_size_t;

typedef U32 l1api_machs_bit_rate_t;

typedef U8  l1api_macd_pdu_index_count_t;

typedef enum {
    L1API_RLC_AM,
    L1API_RLC_UM
} l1api_rlc_mode_t;


typedef U8  l1api_sid_t;
typedef U16 l1api_macd_pdu_size_t;

typedef struct l1api_macd_pdu_size_index_s {
    l1api_sid_t             sid;
    l1api_macd_pdu_size_t   macD_pdu_size;
} l1api_macd_pdu_size_index_t;

typedef struct l1api_pri_water_marks_s {
    l1api_pri_q_water_mark_pdu_count_t low_water_mark_pdu_count;
    l1api_pri_q_water_mark_pdu_count_t high_water_mark_pdu_count;
} l1api_pri_water_marks_t;
typedef struct l1api_priority_queue_info_s {
    struct {
        U8 l1api_discard_timer_present;         
        U8 l1api_machs_bit_rate_present;        
        U8 l1api_pri_water_marks_present;       
    } m;
    l1api_priority_queue_id_t          priority_queue_id;
    l1api_sched_priority_ind_t         sched_prio_ind;
    l1api_t1_t                         t1;
    l1api_discard_timer_t              discard_timer;
    l1api_machs_window_size_t          macHs_window_size;
    l1api_machs_bit_rate_t             macHs_bit_rate;
    l1api_macd_pdu_index_count_t       n_macD_pdu_index;
    l1api_rlc_mode_t                   rlc_mode;
    l1api_macd_flow_info_setup_t       associated_macD_flow_id;
    l1api_macd_pdu_size_index_t        *macD_pdu_size_index;
    l1api_pri_water_marks_t            pri_q_water_marks;
} l1api_priority_queue_info_t;

typedef enum {
    L1API_PRI_QUEUE_ADD,
    L1API_PRI_QUEUE_MOD,
    L1API_PRI_QUEUE_DEL
} l1api_priority_queue_adj_type_t;

typedef struct l1api_priority_queue_reconfig_s {
    l1api_priority_queue_adj_type_t     pri_queue_adj_type;
    l1api_priority_queue_info_t         pri_queue_info;
} l1api_priority_queue_reconfig_t;

typedef struct    l1api_hsdsch_macd_flow_info_s {
    U8                              n_macD_flow;
    U8                              n_priority_queue;
    l1api_macd_flow_info_setup_t    *macD_flow;
    l1api_priority_queue_info_t     *priority_queue;
} l1api_hsdsch_macd_flow_info_t;

typedef struct    l1api_hsdsch_macd_flow_reconfig_s {
    U8                              n_macD_flow;
    U8                              n_priority_queue;
    l1api_macd_flow_info_setup_t    *macD_flow;
    l1api_priority_queue_reconfig_t *priority_queue_reconfig;
} l1api_hsdsch_macd_flow_reconfig_t;

typedef struct l1api_hsdsch_info_s {
    l1api_hsdsch_phys_cat_t         hsdsch_phys_cat;
    l1api_machs_reorder_buff_sz_t   macHs_reorder_buff_sz;
    l1api_cqi_fb_cycle_t            cqi_fb_cycle;
    l1api_cqi_rep_factor_t          cqi_rep_factor;
    l1api_ack_nack_rep_factor_t     ack_nack_rep_factor;
    l1api_cqi_power_offset_t        cqi_power_offset;
    l1api_ack_power_offset_t        ack_power_offset;
    l1api_nack_power_offset_t       nack_power_offset;
    l1api_hsscch_power_offset_t     hsscch_power_offset;
    l1api_meas_power_offset_t       meas_power_offset;
    l1api_hsdsch_macd_flow_info_t   hsdsch_macD_flow_info;
} l1api_hsdsch_info_t;

typedef struct l1api_hsdsch_info_reconfig_s {
    l1api_machs_reorder_buff_sz_t       macHs_reorder_buff_sz;
    l1api_cqi_fb_cycle_t                cqi_fb_cycle;
    l1api_cqi_rep_factor_t              cqi_rep_factor;
    l1api_ack_nack_rep_factor_t         ack_nack_rep_factor;
    l1api_cqi_power_offset_t            cqi_power_offset;
    l1api_ack_power_offset_t            ack_power_offset;
    l1api_nack_power_offset_t           nack_power_offset;
    l1api_hsscch_power_offset_t         hsscch_power_offset;
    l1api_meas_power_offset_t           meas_power_offset;
    l1api_hsdsch_macd_flow_reconfig_t   hsdsch_macD_flow_reconfig;
} l1api_hsdsch_info_reconfig_t;

typedef struct l1api_hsdsch_s {
    l1api_hsdsch_rnti_t     hsdsch_rnti;
    l1api_rl_id_t           rl_id;
    l1api_hsdsch_info_t     hsdsch;
} l1api_hsdsch_t;


typedef struct l1api_coord_trch_dch_s {
  l1api_n_dch_t                 n_dch;
  l1api_payload_crc_present_t   payload_crc_present;
  l1api_ul_fp_mode_t            ul_fp_mode;
  l1api_toa_t                   toAWS;
  l1api_toa_t                   toAWE;
  l1api_dch_info_t              *dch_info;
} l1api_coord_trch_dch_t;

typedef enum {
    L1API_INDICATED_CFN,
    L1API_SEPARATE_MSG
} l1api_activation_type_t;

typedef struct l1api_delayed_activation_s {
    l1api_activation_type_t     activation_type;
    l1api_cfn_t                 activation_cfn;
} l1api_delayed_activation_t;

typedef enum {
    L1API_TXDIV_ACTIVE,
    L1API_TXDIV_INACTIVE
} l1api_tx_div_ind_t;

typedef enum {
    L1API_FIRST_RLS,
    L1API_NOT_FIRST_RLS
} l1api_first_rls_ind_t;

typedef enum {
    L1API_MAY_COMBINE,
    L1API_MUST_COMBINE,
    L1API_MUST_NOT_COMBINE
} l1api_div_ctrl_field_t;

typedef struct {
    short paramPresentFlag;
    U8  eAGCH_power_offset;
    U8  eRGCH_power_offset;
    U8  eHICH_power_offset;
} l1api_rl_specific_edch_info_t;

typedef struct {
    short paramPresentFlag;
    l1api_edch_rl_ind_e edch_rl_ind;
    l1api_rl_specific_edch_info_t rl_specific_edch_info;
} l1api_edch_rl_info_ext_t;
typedef struct l1api_rl_params_s {
  l1api_rl_id_t                 rl_id;
  l1api_cell_id_t               cell_id;
  l1api_tx_div_ind_t            td_indicator;
  BOOL                          split_indicator;
  l1api_first_rls_ind_t         first_rls_indicator;
  l1api_dl_power_t              initial_power;
  l1api_dl_power_t              max_tx_power;
  l1api_dl_power_t              min_tx_power;
  l1api_frame_offset_t          frame_offset;
  l1api_chip_offset_t           chip_offset;
  l1api_mux_position_t          mux_position;
  l1api_div_ctrl_field_t        div_ctrl_field;
  l1api_n_pcp_t                 n_pcp;
  l1api_n_dl_codes_t            n_dl_codes;
  l1api_dpch_dl_code_info_t     *dl_code_info;
  l1api_propagation_delay_t     propagation_delay;
  l1api_delayed_activation_t    delayed_activation;
  l1api_edch_rl_info_ext_t      edch_rl_info_extension;
} l1api_rl_params_t;

typedef enum {
    L1API_DL_TIMING_ADJ_ADVANCE,
    L1API_DL_TIMING_ADJ_DELAY
} l1api_dpch_dl_timing_adj_t;

typedef struct l1api_rl_reconfig_params_s {
  l1api_rl_id_t                 rl_id;
  l1api_tx_div_ind_t            td_indicator;
  l1api_dl_power_t              max_tx_power;
  l1api_dl_power_t              min_tx_power;
  l1api_dpch_dl_timing_adj_t    dpch_dl_timing_adj;
  l1api_n_dl_codes_t            n_dl_codes;
  l1api_dpch_dl_code_info_t     *dl_code_info;
  l1api_edch_rl_info_ext_t      edch_rl_info_ext;
} l1api_rl_reconfig_params_t;
typedef struct {
    U8 ref_etfci;
    U8 ref_etfci_pwr_offset;
} l1api_ref_etfci_t;

typedef struct {
    U16 paramPresentFlag;
    U8  etfci_table_index;
    U8  edch_min_set_etfci;
    U8  ref_etfci_count;
    l1api_ref_etfci_t ref_etfci[L1_MAX_REF_ETFCI_COUNT];
} l1api_etfcs_info_t;

typedef struct {
    U8  paramPresentFlag;
    U16 max_bits_per_mac_epdu;
    U8  harq_proc_alloc_2ms_non_scheduled_tx_grant;
} l1api_edch_non_sched_grant_info_t;
typedef struct {
    U16 paramPresentFlag;
    U8  logical_chan_id;
    U8  sched_pri_ind;
    l1api_sched_info_e sched_info;
    U32  mac_es_guaranteed_bit_rate;
    U8  edch_ddi_val;
    U8  macd_pdu_size_count;
    U16 macd_pdu_size[L1_MAX_NUM_MACDPDUSIZE];
} l1api_edch_logical_chan_info_t;

typedef struct {
    U16 paramPresentFlag;
    U8  edch_macd_flows_id;
    l1api_payload_crc_present_t payload_crc_pres;
    U8  max_num_re_tx_edch;
    U8  edch_harq_power_offset;
    U8  edch_macd_flow_mux_list;
    l1api_edch_grant_type_e   edch_grant_type;
    l1api_bundling_mode_ind_e bundling_mode_ind;
    U8 edch_logical_chan_info_count;
    l1api_edch_non_sched_grant_info_t edch_non_sched_grant_info;
    l1api_edch_logical_chan_info_t    edch_logical_chan_info[L1_MAX_NUM_LOGICAL_CHANS];
} l1api_edch_macd_flows_info_t;
typedef struct {
    U16 paramPresentFlag;
    U8  harq_proc_alloc_2ms_sched_tx_grant;
    U16 edch_max_bit_rate;
    U8  edch_ref_pwr_offset;
    U8  edch_macd_flow_count;
    l1api_edch_macd_flows_info_t edch_macd_flows_info[L1_MAX_NUM_EDCH_MACD_FLOWS];
} l1api_edch_fdd_info_t;

typedef struct {
    U16 paramPresentFlag;
    U8  serving_edch_rl_id;
    l1api_serving_edch_rl_location_e serving_edch_rl_location;
} l1api_serving_edch_rl_t;

typedef struct l1api_edpch_info_s {
    l1api_max_set_edpdch_e max_set_edpdch;
    l1api_puncture_limit_t punct_lim;
    l1api_etti_e etti;
    U8 edpcch_pwr_offset;
    U8 ergch2_index_step_thresh;
    U8 ergch3_index_step_thresh;
    l1api_harq_info_for_edch_e harq_info_for_edch;
    l1api_hsdsch_configured_ind_e hsdsch_configured_ind;
    l1api_etfcs_info_t etfcs_info;
} l1api_edpch_info_t;
typedef struct l1api_edch_rl_setup_extension_s {
    U16 paramPresentFlag;
    l1api_edpch_info_t edpch_info;
    l1api_edch_fdd_info_t edch_fdd_info;
    l1api_serving_edch_rl_t serving_edch_rl;
} l1api_edch_rl_setup_extension_t;

typedef struct l1api_rl_s {
  l1api_Nb_com_context_setup_info_t setup_info;
  l1api_coord_trch_dch_t            *dch;
  l1api_rl_params_t                 *rl;
  l1api_dpch_dl_params_t            dpch_dl;
  l1api_dpch_ul_params_t            dpch_ul;
  l1api_cctrch_params_t             cctrch_dl;
  l1api_cctrch_params_t             cctrch_ul;
  l1api_trans_gap_patt_seq_info_t   *trans_gap_patt;
  l1api_active_patt_seq_info_t      active_patt;
  l1api_dlpower_balancing_info_t    dlpower_bal_info;
  l1api_hsdsch_t                    hsdsch;
  l1api_edch_rl_setup_extension_t   edch_rl_setup_extension;
} l1api_rl_t;


typedef U8 l1api_Nb_com_context_t;

typedef struct l1api_hsdsch_macd_flow_del_s {
    U8                              n_macD_flow;
    l1api_macd_flow_info_setup_t    *macD_flow_info;
} l1api_hsdsch_macd_flow_del_t;

typedef struct l1api_hsdsch_reconfig_s {
    l1api_hsdsch_rnti_t             hsdsch_rnti;
    l1api_rl_id_t                   hs_psch_rl_id;
    l1api_hsdsch_info_t             hsdsch;
    l1api_hsdsch_info_reconfig_t    hsdsch_modify;
    l1api_hsdsch_macd_flow_info_t   hsdsch_macD_add;
    l1api_hsdsch_macd_flow_del_t    hsdsch_macD_delete;
} l1api_hsdsch_reconfig_t;
typedef struct {
    U16 paramPresentFlag;
    U8  logical_chan_id;
    U8  sched_pri_ind;
    l1api_sched_info_e sched_info;
    U32  mac_es_guaranteed_bit_rate;
    U8  edch_ddi_val;
    U8  macd_pdu_size_count;
    U16 macd_pdu_size[L1_MAX_NUM_MACDPDUSIZE];    
} l1api_edch_logical_chan_info_re_t;

typedef struct {
    U8  logical_chan_id;
} l1api_edch_logical_chan_info_del_t;
typedef struct {
    U16 paramPresentFlag;
    U8  edch_macd_flow_id;
    U8  max_num_re_tx_edch;
    U8  edch_harq_pwr_offset;
    U8  edch_macd_flow_mux_list;
    l1api_edch_grant_type_e   edch_grant_Type;
    l1api_bundling_mode_ind_e bundling_mode_ind;
    U8  edch_logical_chan_info_add_count;
    U8  edch_logical_chan_info_mod_count;
    U8  edch_logical_chan_info_del_count;
    l1api_edch_non_sched_grant_info_t  edch_non_sched_grant_info;
    l1api_edch_logical_chan_info_t     edch_logical_chan_info_add[L1_MAX_NUM_LOGICAL_CHANS];
    l1api_edch_logical_chan_info_re_t  edch_logical_chan_info_mod[L1_MAX_NUM_LOGICAL_CHANS];
    l1api_edch_logical_chan_info_del_t edch_logical_chan_info_del[L1_MAX_NUM_LOGICAL_CHANS];
} l1api_edch_macd_flows_info_re_t;

typedef struct {
    U16 paramPresentFlag;
    l1api_max_set_edpdch_e max_set_edpdch;
    U8  punct_lim;
    l1api_etti_e eTti;
    U8  edpcch_pwr_offset;
    U8  ergch2_index_step_thresh;
    U8  ergch3_index_step_thresh;
    l1api_harq_info_for_edch_e    harq_info_for_edch;
    l1api_hsdsch_configured_ind_e hs_dsch_configured_ind;
    l1api_etfcs_info_t eTfcsInfo;
} l1api_edpch_info_re_t;
typedef struct {
    U16 paramPresentFlag;
    U8  harq_pro_calloc_2ms_scheduled_tx_grant;
    U16 edch_max_bit_rate;
    U8  edch_ref_power_offset;
    l1api_mace_reset_Ind_e mace_reset_ind;
    U8  edch_macd_flow_count;
    l1api_edch_macd_flows_info_re_t edch_macd_flows_info[L1_MAX_NUM_EDCH_MACD_FLOWS];
} l1api_edch_fdd_info_re_t;


typedef struct {
    U8 count;
    l1api_edch_macd_flows_info_t edch_macd_flows_info[L1_MAX_NUM_EDCH_MACD_FLOWS];
} l1api_edch_macd_flow_info_t;

typedef struct {
    U8 count;
    U8 edch_macd_flows_id[L1_MAX_NUM_EDCH_MACD_FLOWS];
} l1api_edch_macd_flow_del_t;

typedef struct l1api_edch_ext_reconfig_s {
   U16 paramPresentFlag;
   l1api_edpch_info_re_t edpch_info;
   l1api_edch_fdd_info_t edch_fdd_info;
   l1api_edch_fdd_info_re_t *edch_fdd_info_modify;
   l1api_edch_macd_flow_info_t *edch_macd_flows_add;
   l1api_edch_macd_flow_del_t *edch_macd_flows_delete;
   l1api_serving_edch_rl_t *serving_edch_rl;
} l1api_edch_ext_reconfig_t;

typedef struct l1api_rl_reconfig_s {
  l1api_Nb_com_context_t                com_context;
  l1api_Nb_com_context_reconfig_info_t  reconfig_info;
  l1api_rl_reconfig_params_t            *rl;
  l1api_dch_id_t                        *dch_delete;
  l1api_coord_trch_dch_t                *dch_modify;
  l1api_coord_trch_dch_t                *dch_add;
  l1api_dpch_dl_params_t                dpch_dl;
  l1api_dpch_ul_params_t                dpch_ul;
  l1api_cctrch_params_t                 cctrch_dl;
  l1api_cctrch_params_t                 cctrch_ul;
  l1api_trans_gap_patt_seq_info_t       *trans_gap_patt;
  l1api_hsdsch_reconfig_t               hsdsch_reconfig;
  l1api_edch_ext_reconfig_t             edch_ext_reconfig;
} l1api_rl_reconfig_t;

typedef struct l1api_rl_reconfig_commit_s {
  l1api_Nb_com_context_t        com_context;
  l1api_cfn_t                   cfn;
  l1api_active_patt_seq_info_t  active_patt;
} l1api_rl_reconfig_commit_t;

typedef struct l1api_rl_reconfig_cancel_s {
  l1api_Nb_com_context_t        com_context;
} l1api_rl_reconfig_cancel_t;

typedef struct l1api_rl_delete_s {
  l1api_Nb_com_context_t    com_context;
  U8                        n_rl;
  l1api_rl_id_t             *rl_id;
} l1api_rl_delete_t;

typedef enum {
    L1API_ACTIVATE_SYNCHRONISED,
    L1API_ACTIVATE_UNSYNCHRONISED,
    L1API_DEACTIVATE_SYNCHRONISED,
    L1API_DEACTIVATE_UNSYNCHRONISED
} l1api_act_update_type_t;

typedef struct l1api_activation_info_s {
    l1api_dl_power_t            initial_dltx_pwr;
    l1api_first_rls_ind_t       first_rls_ind;
    l1api_propagation_delay_t   propagation_delay;
} l1api_activation_info_t;

typedef struct l1api_delayed_act_update_s {
    l1api_rl_id_t               rl_id;
    l1api_act_update_type_t     act_update_type;
    l1api_cfn_t                 activation_cfn;
    l1api_activation_info_t     activation_info;
} l1api_delayed_act_update_t;

typedef struct l1api_rl_activate_s {
  l1api_Nb_com_context_t        com_context;
  U8                            n_rl;
  l1api_delayed_act_update_t    *delayed_act;
} l1api_rl_activate_t;

/* Fp frames */

typedef U8  l1api_frame_seq_num_t;      
typedef U8  l1api_CmCH_PI_t;            
typedef U16 l1api_user_buffer_size_t;   
typedef U16 l1api_macD_pdu_len_t;       
typedef U8  l1api_pdu_count_t;
typedef U8  l1api_new_ie_flags_t;
typedef U16 l1api_drt_t;
typedef enum
{
    L1API_DATA_FRAME_TYPE_RACH,
    L1API_DATA_FRAME_TYPE_PCH,
    L1API_DATA_FRAME_TYPE_FACH,
    L1API_DATA_FRAME_TYPE_DSCH,
    L1API_DATA_FRAME_TYPE_HSDSCH,
    L1API_DATA_FRAME_TYPE_DCH_DL,
    L1API_DATA_FRAME_TYPE_DCH_UL
} l1api_data_frame_type_t;



typedef U32 l1api_toa_pch_t;

typedef enum
{
    L1API_CTRL_FRAME_TYPE_OUTER_LOOP_PWR_CTRL = 1,
    L1API_CTRL_FRAME_TYPE_TIMING_ADJ,
    L1API_CTRL_FRAME_TYPE_DL_SYNC,
    L1API_CTRL_FRAME_TYPE_UL_SYNC,
    L1API_CTRL_FRAME_TYPE_DSCH_TFCI_SIGNALLING,
    L1API_CTRL_FRAME_TYPE_DL_NODEB_SYNC,
    L1API_CTRL_FRAME_TYPE_UL_NODEB_SYNC,
    L1API_CTRL_FRAME_TYPE_DYNAMIC_PUSCH_ASSIGN,
    L1API_CTRL_FRAME_TYPE_TIMING_ADV,
    L1API_CTRL_FRAME_TYPE_HSDSCH_CAPACITY_REQUEST,
    L1API_CTRL_FRAME_TYPE_HSDSCH_CAPACITY_ALLOCATION
} l1api_ctrl_frame_type_t;

typedef struct l1api_outer_lp_pwr_ctrl_s
{
    l1api_cfn_t         cfn;
} l1api_outer_lp_pwr_ctrl_t;

typedef struct l1api_timing_adj_s
{
    l1api_cfn_t         cfn;
    l1api_toa_t         toa;
} l1api_timing_adj_t;

typedef struct l1api_timing_adj_pch_s
{
    l1api_cfn_pch_t     cfn;
    l1api_toa_pch_t     toa;
} l1api_timing_adj_pch_t;

typedef struct l1api_dl_sync_s
{
    l1api_cfn_t         cfn;
} l1api_dl_sync_t;

typedef struct l1api_dl_sync_pch_s
{
    l1api_cfn_pch_t     cfn;
} l1api_dl_sync_pch_t;

typedef struct l1api_ul_sync_s
{
    l1api_cfn_t         cfn;
    l1api_toa_t         toa;
} l1api_ul_sync_t;

typedef struct l1api_ul_sync_pch_s
{
    l1api_cfn_pch_t     cfn;
    l1api_toa_pch_t     toa;
} l1api_ul_sync_pch_t;

typedef struct l1api_dsch_tfci_s
{
    l1api_cfn_t         cfn;
} l1api_dsch_tfci_t;

typedef struct l1api_dl_nodeb_sync_s
{
    U8                  T1[3];
} l1api_dl_nodeb_sync_t;

typedef struct l1api_ul_nodeb_sync_s
{
    U8                  T1[3];
    U8                  T2[3];
    U8                  T3[3];
} l1api_ul_nodeb_sync_t;

typedef struct l1api_dyn_pusch_assign_s
{
    l1api_cfn_t         cfn;
} l1api_dyn_pusch_assign_t;

typedef struct l1api_timing_adv_s
{
    l1api_cfn_t         cfn;
} l1api_timing_adv_t;

typedef struct l1api_hsdsch_capacity_req_s
{
    l1api_CmCH_PI_t             CmCH_PI;
    l1api_user_buffer_size_t    user_buffer_size;
}l1api_hsdsch_capacity_req_t;

typedef U8  l1api_hsdsch_credits_t;
typedef U8  l1api_hsdsch_interval_t;
typedef U8  l1api_hsdsch_rep_period_t;

typedef struct l1api_hsdsch_capacity_alloc_s
{
    l1api_CmCH_PI_t             CmCH_PI;
    l1api_macD_pdu_len_t        macD_pdu_max_len;
    l1api_hsdsch_credits_t      credits;
    l1api_hsdsch_interval_t     interval;
    l1api_hsdsch_rep_period_t   rep_period;
}l1api_hsdsch_capacity_alloc_t;

typedef enum {
        PCH_CTRL_FRAME,
        FACH_CTRL_FRAME,
        RACH_CTRL_FRAME,
        DCH_CTRL_FRAME,
        HSDSCH_CTRL_FRAME
} l1api_chn_type_t;

typedef U16 l1api_payload_crc_t;

#define DATA_RACH_HDR_SIZE              4
#define DATA_FACH_HDR_SIZE              4
#define DATA_PCH_HDR_SIZE               4
#define DATA_DCH_HDR_SIZE(n_dch)        2+(n_dch)
#define DATA_HSDSCH_HDR_SIZE            7

#define CTRL_HDR_SIZE                   2
#define CTRL_PAYLOAD_SIZE_DL_SYNC_PCH   2
#define CTRL_PAYLOAD_SIZE_DL_SYNC       1
#define CTRL_PAYLOAD_SIZE_UL_SYNC_PCH   5
#define CTRL_PAYLOAD_SIZE_UL_SYNC       3
#define CTRL_PAYLOAD_SIZE_DL_NODE_SYNC  3
#define CTRL_PAYLOAD_SIZE_UL_NODE_SYNC  9
#define CTRL_PAYLOAD_SIZE_TIM_ADV_PCH   5
#define CTRL_PAYLOAD_SIZE_TIM_ADV       3
#define CTRL_PAYLOAD_SIZE_CAP_REQ       3
#define CTRL_PAYLOAD_SIZE_CAP_ALLOC     5

/* Measurement report information */
typedef struct l1api_measurement_info_s {
  l1api_id_t id;
  U16        value;
} l1api_measurement_info_t;

/* OCNS power control */
typedef struct l1api_ocns_power_control_s {
  l1api_id_t       id;      /* Cell identifier */
  l1api_dl_power_t ocns_power;  /* 0 => -35dB,..., 500 => +15dB (.1dB) */
} l1api_ocns_power_control_t;

/* Downlink power control */
typedef struct l1api_dl_power_control_s {
  l1api_id_t       id;      /* Radio link identifier */
  l1api_dl_power_t dpch_power; /* 0 => -35dB,..., 500 => +15dB (.1dB) */
} l1api_dl_power_control_t;

typedef struct l1api_dl_tpc_control_s {
  l1api_id_t          id;   /* Radio link identifier */
  l1api_dl_tpc_mode_t mode; /* 0 => default mode (as per rl_setup)
                                   1 => send DL TPCs (one-shot)
                                   2 => send DL TPCs (continuous) */
  BOOL                cfn_indicator; /* 0 => apply on cfn 1 => apply now */
  l1api_cfn_t         cfn;  /* cfn start for TPC command */
  U16                 dl_tpc_frame[8]; /* 8 frames must be given, where
                      bit0 => timeslot 0,
                      ...
                      bit14 => timeslot 14 */
} l1api_dl_tpc_control_t;

/* AGC control */
typedef struct l1api_agc_control_s {
  l1api_id_t       id;      /* Cell identifier */
  U32              antenna_id;  /* Antenna identifer (0..1) */
  l1api_agc_mode_t agc_mode;    /* Mode (0=>closed loop, 1=>open loop) */
  U16              gain_value;  /* -78dB<=0..900<=12dB (.1db steps) */
} l1api_agc_control_t;

/* start AWGN */
typedef struct l1api_start_awgn_s {
  l1api_id_t        id; /* Cell identifier */
  l1api_awgn_power_t awgn_power; /* tbd */
} l1api_start_awgn_t;

/* stop AWGN */
typedef struct l1api_stop_awgn_s {
  l1api_id_t       id;      /* Cell identifier */
} l1api_stop_awgn_t;

/* Compressed Mode Command */
typedef struct l1api_compressed_mode_cmd_s {
  l1api_id_t       id;      /* Cell identifier */
} l1api_compressed_mode_cmd_t;

/* Modem Setup Request */
typedef struct l1api_modem_setup_request_s {
	U8  paramPresentFlag;
	/* Set paramPresentFlag to 0x80 if 'radio_tx_analog_attn' is present*/ 
	U8  radio_tx_analog_attn;
	/* Set paramPresentFlag to 0x40 if 'radio_rx_analog_gain' is present*/ 
	U8  radio_rx_analog_gain;
    /* Set paramPresentFlag to 0x20 if 'sdr4000_clksrc_select' is present*/ 
    U8  sdr4000_clksrc_select;
} l1api_modem_setup_request_t;

/* Audit Request */
typedef struct l1api_audit_request_s {
  l1api_id_t       id;      /* Cell identifier */
} l1api_audit_request_t;

/**************************************************************/
/* API data structures */
/**************************************************************/

/* Handler */

typedef void *L1APIHdlr_t;

/* L1API error codes */

typedef enum
{
    /* No error */
    SA_L1API_NO_ERROR,
    L1API_NO_ERROR_PRINT_MESSAGE,

    /* API Errors */
    L1API_ERROR_API_NOT_CONFIGURED,
    L1API_ERROR_API_OUT_OF_MEMORY,
    L1API_ERROR_API_CONNECTING_SERVER,
    L1API_ERROR_API_DISCONNECTING_SERVER,
    L1API_ERROR_API_SOCKET_READ,
    L1API_ERROR_API_SOCKET_WRITE,
    L1API_ERROR_API_ALLOC_TXQUEUE_ELEM,
    L1API_ERROR_API_SEND_TXQUEUE_ELEM,
    L1API_ERROR_API_RESP_NOT_EXPECTED,
    L1API_ERROR_API_INVALID_MSG_ID,
    L1API_ERROR_API_INVALID_TRCH_TYPE,

    /* Error in the message */
    L1API_ERROR_MSG_MODEM_SETUP_REQUEST,
    L1API_ERROR_MSG_CELL_SETUP_REQUEST,
    L1API_ERROR_MSG_CELL_SETUP_REQUEST_PPF,
    L1API_ERROR_MSG_CELL_RECONFIG_REQUEST,
    L1API_ERROR_MSG_CELL_RECONFIG_REQUEST_PPF,
    L1API_ERROR_MSG_CELL_DELETE_REQUEST,
    L1API_ERROR_MSG_CMN_TRCH_SCCPCH_SETUP_REQUEST,
    L1API_ERROR_MSG_CMN_TRCH_SCCPCH_SETUP_REQUEST_PPF,
    L1API_ERROR_MSG_CMN_TRCH_PRACH_SETUP_REQUEST,
    L1API_ERROR_MSG_CMN_TRCH_PRACH_SETUP_REQUEST_PPF,
    L1API_ERROR_MSG_CMN_TRCH_SCCPCH_RECONFIG_REQUEST,
    L1API_ERROR_MSG_CMN_TRCH_SCCPCH_RECONFIG_REQUEST_PPF,
    L1API_ERROR_MSG_CMN_TRCH_PRACH_RECONFIG_REQUEST,
    L1API_ERROR_MSG_CMN_TRCH_PRACH_RECONFIG_REQUEST_PPF,
    L1API_ERROR_MSG_CMN_TRCH_DELETE_REQUEST,
    L1API_ERROR_MSG_CMN_TRCH_SCCPCH_SETUP_RESPONSE,
    L1API_ERROR_MSG_CMN_TRCH_SCCPCH_SETUP_RESPONSE_PPF,
    L1API_ERROR_MSG_CMN_TRCH_PRACH_SETUP_RESPONSE,
    L1API_ERROR_MSG_RADIOLINK_SETUP_REQUEST,
    L1API_ERROR_MSG_RADIOLINK_SETUP_REQUEST_PPF,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_PREP_REQUEST,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_PREP_REQUEST_PPF,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_COMMIT_REQUEST,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_COMMIT_REQUEST_PPF,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_CANCEL_REQUEST,
    L1API_ERROR_MSG_RADIOLINK_ACTIVATION,
    L1API_ERROR_MSG_RADIOLINK_DELETE_REQUEST,
    L1API_ERROR_MSG_RADIOLINK_SETUP_RESPONSE,
    L1API_ERROR_MSG_RADIOLINK_SETUP_RESPONSE_PPF,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_READY,
    L1API_ERROR_MSG_RADIOLINK_RECONFIG_READY_PPF,
    L1API_ERROR_MSG_RADIOLINK_FAILURE_INDICATION,
    L1API_ERROR_MSG_RADIOLINK_FAILURE_INDICATION_PPF,
    L1API_ERROR_MSG_RADIOLINK_RESTORE_INDICATION,
    L1API_ERROR_MSG_RADIOLINK_RESTORE_INDICATION_PPF,
    L1API_ERROR_MSG_PHYSICAL_SHARED_CH_RECONFIG_REQUEST,
    L1API_ERROR_MSG_PHYSICAL_SHARED_CH_RECONFIG_REQUEST_PPF,
    L1API_ERROR_MSG_DL_POWER_CTRL_REQUEST,
    L1API_ERROR_MSG_DL_POWER_CTRL_REQUEST_PPF,
    L1API_ERROR_MSG_COMPRESSED_MODE_CMD,
    L1API_ERROR_MSG_SYSTEM_INFO_UPDATE_REQUEST,
    L1API_ERROR_MSG_SYSTEM_INFO_UPDATE_REQUEST_PPF,
    L1API_ERROR_MSG_COMMON_MEAS_INIT_REQ,
    L1API_ERROR_MSG_COMMON_MEAS_INIT_REQ_PPF,
    L1API_ERROR_MSG_COMMON_MEAS_REPORT,
    L1API_ERROR_MSG_COMMON_MEAS_REPORT_PPF,
    L1API_ERROR_MSG_COMMON_MEAS_TERMINATE_REQ,
    L1API_ERROR_MSG_COMMON_MEAS_FAILURE_IND,
    L1API_ERROR_MSG_COMMON_MEAS_FAILURE_IND_PPF,
    L1API_ERROR_MSG_DEDICATED_MEAS_INIT_REQ,
    L1API_ERROR_MSG_DEDICATED_MEAS_INIT_REQ_PPF,
    L1API_ERROR_MSG_DEDICATED_MEAS_REPORT,
    L1API_ERROR_MSG_DEDICATED_MEAS_REPORT_PPF,
    L1API_ERROR_MSG_DEDICATED_MEAS_TERMINATE_REQ,
    L1API_ERROR_MSG_DEDICATED_MEAS_FAILURE_IND,
    L1API_ERROR_MSG_DEDICATED_MEAS_FAILURE_IND_PPF,
    L1API_ERROR_MSG_GENERIC_RESPONSE,
    L1API_ERROR_MSG_ALARM_INDICATION,
    L1API_ERROR_MSG_AUDIT_REQUEST,
    L1API_ERROR_MSG_AUDIT_RESPONSE,
    L1API_ERROR_MSG_MSGHDR,
    L1API_ERROR_MSG_MSGFTR,
    L1API_ERROR_MSG_CELLINFO,
    L1API_ERROR_MSG_CELLINFO_PPF,
    L1API_ERROR_MSG_CELLINFORE,
    L1API_ERROR_MSG_CELLINFORE_PPF,
    L1API_ERROR_MSG_CMNTRCHINFO,
    L1API_ERROR_MSG_SYNCCONFIG,
    L1API_ERROR_MSG_PHYSDLSCH,
    L1API_ERROR_MSG_PHYSDLPCPICH,
    L1API_ERROR_MSG_PHYSDLSCPICH,
    L1API_ERROR_MSG_PHYSDLPHYSCELLRE,
    L1API_ERROR_MSG_PHYSDLPHYSPCPICHRE,
    L1API_ERROR_MSG_PHYSDLPCCPCH,
    L1API_ERROR_MSG_PHYSDLPICH,
    L1API_ERROR_MSG_PHYSDLPICHRE,
    L1API_ERROR_MSG_PHYSDLPICHRE_PPF,
    L1API_ERROR_MSG_PHYSDLAICH,
    L1API_ERROR_MSG_PHYSDLAICHRE,
    L1API_ERROR_MSG_PHYSDLAICHRE_PPF,
    L1API_ERROR_MSG_PHYSDLPCCPCHRE,
    L1API_ERROR_MSG_PHYSULPRACH,
    L1API_ERROR_MSG_PHYSULPRACHRE,
    L1API_ERROR_MSG_PHYSULPRACHRE_PPF,
    L1API_ERROR_MSG_TRCHCOMMONDLBASIC,
    L1API_ERROR_MSG_PHYSDLSCCPCH,
    L1API_ERROR_MSG_PHYSDLSCCPCH_PPF,
    L1API_ERROR_MSG_TRCHCOMMONPCH,
    L1API_ERROR_MSG_TRCHCOMMONPCHRE,
    L1API_ERROR_MSG_TRCHCOMMONPCHRE_PPF,
    L1API_ERROR_MSG_TRCHCOMMONDL,
    L1API_ERROR_MSG_TRCHCOMMONDLRE,
    L1API_ERROR_MSG_TRCHCOMMONDLRE_PPF,
    L1API_ERROR_MSG_TRCHCOMMONUL,
    L1API_ERROR_MSG_RLINFO,
    L1API_ERROR_MSG_RLINFO_PPF,
    L1API_ERROR_MSG_RLINFORE,
    L1API_ERROR_MSG_RLINFORE_PPF,
    L1API_ERROR_MSG_RLFAILINFO,
    L1API_ERROR_MSG_RLSFAILINFO,
    L1API_ERROR_MSG_RLRESTOREINFO,
    L1API_ERROR_MSG_RLSRESTOREINFO,
    L1API_ERROR_MSG_RLINFOBASIC,
    L1API_ERROR_MSG_DLCODEINFO,
    L1API_ERROR_MSG_DELAYEDACTIVATION,
    L1API_ERROR_MSG_DELAYEDACTUPDATE,
    L1API_ERROR_MSG_DELAYEDACTUPDATE_PPF,
    L1API_ERROR_MSG_ACTIVATIONINFO,
    L1API_ERROR_MSG_ACTIVATIONINFO_PPF,
    L1API_ERROR_MSG_ACTIVEPATTSEQINFO,
    L1API_ERROR_MSG_ACTIVEPATTSEQINFO_PPF,
    L1API_ERROR_MSG_TGPSSTATUS,
    L1API_ERROR_MSG_DLPOWERBALANCINGINFO,
    L1API_ERROR_MSG_DLPOWERBALANCINGINFO_PPF,
    L1API_ERROR_MSG_TRANSGAPPATTSEQINFO,
    L1API_ERROR_MSG_TRANSGAPPATTSEQINFO_PPF,
    L1API_ERROR_MSG_IPDLPARAMS,
    L1API_ERROR_MSG_IPDLPARAMSRE,
    L1API_ERROR_MSG_IPDLPARAMSRE_PPF,
    L1API_ERROR_MSG_IPDLFDDPARAMS,
    L1API_ERROR_MSG_IPDLFDDPARAMS_PPF,
    L1API_ERROR_MSG_BURSTMODEPARAMS,
    L1API_ERROR_MSG_PHYSDLDPCH,
    L1API_ERROR_MSG_PHYSDLDPCH_PPF,
    L1API_ERROR_MSG_PHYSDLDPCHRE,
    L1API_ERROR_MSG_PHYSDLDPCHRE_PPF,
    L1API_ERROR_MSG_PHYSULDPCH,
    L1API_ERROR_MSG_PHYSULDPCH_PPF,
    L1API_ERROR_MSG_PHYSULDPCHRE,
    L1API_ERROR_MSG_PHYSULDPCHRE_PPF,
    L1API_ERROR_MSG_ULSCRAMCODEINFO,
    L1API_ERROR_MSG_CCTRCHDLTFC,
    L1API_ERROR_MSG_CCTRCHULTFC,
    L1API_ERROR_MSG_COORDTRCHDCH,
    L1API_ERROR_MSG_COORDTRCHDCHMOD,
    L1API_ERROR_MSG_COORDTRCHDCHMOD_PPF,
    L1API_ERROR_MSG_RLINFORESP,
    L1API_ERROR_MSG_RLINFORESP_PPF,
    L1API_ERROR_MSG_COORDTRCHRESP,
    L1API_ERROR_MSG_DCHSPECIFICINFO,
    L1API_ERROR_MSG_DCHSPECIFICINFO_PPF,
    L1API_ERROR_MSG_DCHSPECIFICINFOMOD,
    L1API_ERROR_MSG_DCHSPECIFICINFOMOD_PPF,
    L1API_ERROR_MSG_TRCHTF,
    L1API_ERROR_MSG_TRANSFORMAT,
    L1API_ERROR_MSG_POWERADJCOMMON,
    L1API_ERROR_MSG_POWERADJINDIVIDUAL,
    L1API_ERROR_MSG_DLREFPWRINFO,
    L1API_ERROR_MSG_ADJUSTINFO,
    L1API_ERROR_MSG_HSDSCH,
    L1API_ERROR_MSG_HSDSCHINFO,
    L1API_ERROR_MSG_HSDSCHINFO_PPF,
    L1API_ERROR_MSG_HSDSCHINFORE,
    L1API_ERROR_MSG_HSDSCHINFORE_PPF,
    L1API_ERROR_MSG_HSDSCHRE,
    L1API_ERROR_MSG_HSDSCHRE_PPF,
    L1API_ERROR_MSG_HSDSCHINFORESP,
    L1API_ERROR_MSG_HSDSCHINFORESP_PPF,
    L1API_ERROR_MSG_HSSCCHINFORESP,
    L1API_ERROR_MSG_HARQMEMIMPLICIT,
    L1API_ERROR_MSG_HARQMEMEXPLICIT,
    L1API_ERROR_MSG_HSPDSCHCODEINFO,
    L1API_ERROR_MSG_HSPDSCHCODEINFO_PPF,
    L1API_ERROR_MSG_HSSCCHCODEINFO,
    L1API_ERROR_MSG_HSSCCHCODEINFO_PPF,
    L1API_ERROR_MSG_HSDSCHMACDFLOWINFO,
    L1API_ERROR_MSG_HSDSCHMACDFLOWINFORE,
    L1API_ERROR_MSG_HSDSCHMACDFLOWINFORE_PPF,
    L1API_ERROR_MSG_HSDSCHMACDFLOWDEL,
    L1API_ERROR_MSG_MACDFLOWINFOSETUP,
    L1API_ERROR_MSG_MACDFLOWINFO,
    L1API_ERROR_MSG_PRIORITYQUEUEINFORE,
    L1API_ERROR_MSG_PRIORITYQUEUEINFORE_PPF,
    L1API_ERROR_MSG_PRIORITYQUEUEINFO,
    L1API_ERROR_MSG_PRIORITYQUEUEINFO_PPF,
    L1API_ERROR_MSG_PRIORITYQUEUEINFOMOD,
    L1API_ERROR_MSG_PRIORITYQUEUEINFOMOD_PPF,
    L1API_ERROR_MSG_PRIORITYQUEUEINFODEL,
    L1API_ERROR_MSG_MACDPDUSIZEINDEX,
    L1API_ERROR_MSG_IBINFORMATION,
    L1API_ERROR_MSG_IBINFORMATION_PPF,
    L1API_ERROR_MSG_IBADDITIONINFO,
    L1API_ERROR_MSG_IBADDITIONINFO_PPF,
    L1API_ERROR_MSG_SEGINFO,
    L1API_ERROR_MSG_SEGINFO_PPF,
    L1API_ERROR_MSG_CELLMEASUREMENT,
    L1API_ERROR_MSG_RACHMEASUREMENT,
    L1API_ERROR_MSG_RACHMEASUREMENT_PPF,
    L1API_ERROR_MSG_RLMEASUREMENT,
    L1API_ERROR_MSG_RLSMEASUREMENT,
    L1API_ERROR_MSG_MEASCMNINFO,
    L1API_ERROR_MSG_MEASCMNINFO_PPF,
    L1API_ERROR_MSG_MEASDEDINFO,
    L1API_ERROR_MSG_MEASDEDINFO_PPF,
    L1API_ERROR_MSG_REPORTCHARS,
    L1API_ERROR_MSG_REPORTCHARS_PPF,
    L1API_ERROR_MSG_MEASPERIODIC,
    L1API_ERROR_MSG_MEASPERIODIC_PPF,
    L1API_ERROR_MSG_MEASEVENT1,
    L1API_ERROR_MSG_MEASEVENT1_PPF,
    L1API_ERROR_MSG_MEASEVENT2,
    L1API_ERROR_MSG_MEASEVENT2_PPF,
    L1API_ERROR_MSG_MEASEVENT3,
    L1API_ERROR_MSG_MEASEVENT3_PPF,
    L1API_ERROR_MSG_ONMODIFICATION,
    L1API_ERROR_MSG_MEASCHANGETHRESH,
    L1API_ERROR_MSG_MEASCHANGETHRESH_PPF,
    L1API_ERROR_MSG_MEASTHRESH,
    L1API_ERROR_MSG_MEASTHRESH_PPF,
    L1API_ERROR_MSG_COMMONMEASINFO,
    L1API_ERROR_MSG_COMMONMEASINFO_PPF,
    L1API_ERROR_MSG_COMMONMEASVALUE,
    L1API_ERROR_MSG_COMMONMEASVALUE_PPF,
    L1API_ERROR_MSG_DEDICATEDMEASRLINFO,
    L1API_ERROR_MSG_DEDICATEDMEASRLSINFO,
    L1API_ERROR_MSG_DEDICATEDMEASINFO,
    L1API_ERROR_MSG_DEDICATEDMEASINFO_PPF,
    L1API_ERROR_MSG_DEDICATEDMEASVALUE,
    L1API_ERROR_MSG_DEDICATEDMEASVALUE_PPF,
    L1API_ERROR_MSG_NBCOMCONTEXTSETUPINFO,
    L1API_ERROR_MSG_NBCOMCONTEXTSETUPINFORE,
    L1API_ERROR_MSG_NBCOMCONTEXTBASICINFO,
    L1API_ERROR_MSG_L1MSGSTATUS,
    L1API_ERROR_MSG_AUDITINFO,
    L1API_ERROR_MSG_AUDITINFO_PPF,
    L1API_ERROR_MSG_DPCHAUDIT,


    /* Error in the procedure */
    L1API_ERROR_PROC_MODEM_SETUP_REQUEST,
    L1API_ERROR_PROC_CELL_SETUP_REQUEST,
    L1API_ERROR_PROC_CELL_RECONFIG_REQUEST,
    L1API_ERROR_PROC_CELL_DELETE_REQUEST,
    L1API_ERROR_PROC_CMN_TRCH_SCCPCH_SETUP_REQUEST,
    L1API_ERROR_PROC_CMN_TRCH_PRACH_SETUP_REQUEST,
    L1API_ERROR_PROC_CMN_TRCH_SCCPCH_RECONFIG_REQUEST,
    L1API_ERROR_PROC_CMN_TRCH_PRACH_RECONFIG_REQUEST,
    L1API_ERROR_PROC_CMN_TRCH_DELETE_REQUEST,
    L1API_ERROR_PROC_CMN_TRCH_SCCPCH_SETUP_RESPONSE,
    L1API_ERROR_PROC_CMN_TRCH_PRACH_SETUP_RESPONSE,
    L1API_ERROR_PROC_RADIOLINK_SETUP_REQUEST,
    L1API_ERROR_PROC_RADIOLINK_RECONFIG_PREP_REQUEST,
    L1API_ERROR_PROC_RADIOLINK_RECONFIG_COMMIT_REQUEST,
    L1API_ERROR_PROC_RADIOLINK_RECONFIG_CANCEL_REQUEST,
    L1API_ERROR_PROC_RADIOLINK_ACTIVATION,
    L1API_ERROR_PROC_RADIOLINK_DELETE_REQUEST,
    L1API_ERROR_PROC_RADIOLINK_SETUP_RESPONSE,
    L1API_ERROR_PROC_RADIOLINK_RECONFIG_READY,
    L1API_ERROR_PROC_RADIOLINK_FAILURE_INDICATION,
    L1API_ERROR_PROC_RADIOLINK_RESTORE_INDICATION,
    L1API_ERROR_PROC_PHYSICAL_SHARED_CH_RECONFIG_REQUEST,
    L1API_ERROR_PROC_DL_POWER_CTRL_REQUEST,
    L1API_ERROR_PROC_COMPRESSED_MODE_CMD,
    L1API_ERROR_PROC_SYSTEM_INFO_UPDATE_REQUEST,
    L1API_ERROR_PROC_COMMON_MEAS_INIT_REQ,
    L1API_ERROR_PROC_COMMON_MEAS_REPORT,
    L1API_ERROR_PROC_COMMON_MEAS_TERMINATE_REQ,
    L1API_ERROR_PROC_COMMON_MEAS_FAILURE_IND,
    L1API_ERROR_PROC_DEDICATED_MEAS_INIT_REQ,
    L1API_ERROR_PROC_DEDICATED_MEAS_REPORT,
    L1API_ERROR_PROC_DEDICATED_MEAS_TERMINATE_REQ,
    L1API_ERROR_PROC_DEDICATED_MEAS_FAILURE_IND,
    L1API_ERROR_PROC_GENERIC_RESPONSE,
    L1API_ERROR_PROC_ALARM_INDICATION,
    L1API_ERROR_PROC_AUDIT_REQUEST,
    L1API_ERROR_PROC_AUDIT_RESPONSE,
    L1API_ERROR_PROC_MSGHDR,
    L1API_ERROR_PROC_MSGFTR,
    L1API_ERROR_PROC_CELLINFO,
    L1API_ERROR_PROC_CELLINFORE,
    L1API_ERROR_PROC_CMNTRCHINFO,
    L1API_ERROR_PROC_SYNCCONFIG,
    L1API_ERROR_PROC_PHYSDLSCH,
    L1API_ERROR_PROC_PHYSDLPCPICH,
    L1API_ERROR_PROC_PHYSDLSCPICH,
    L1API_ERROR_PROC_PHYSDLPHYSCELLRE,
    L1API_ERROR_PROC_PHYSDLPHYSPCPICHRE,
    L1API_ERROR_PROC_PHYSDLPCCPCH,
    L1API_ERROR_PROC_PHYSDLPICH,
    L1API_ERROR_PROC_PHYSDLPICHRE,
    L1API_ERROR_PROC_PHYSDLAICH,
    L1API_ERROR_PROC_PHYSDLAICHRE,
    L1API_ERROR_PROC_PHYSDLPCCPCHRE,
    L1API_ERROR_PROC_PHYSULPRACH,
    L1API_ERROR_PROC_PHYSULPRACHRE,
    L1API_ERROR_PROC_TRCHCOMMONDLBASIC,
    L1API_ERROR_PROC_PHYSDLSCCPCH,
    L1API_ERROR_PROC_TRCHCOMMONPCH,
    L1API_ERROR_PROC_TRCHCOMMONPCHRE,
    L1API_ERROR_PROC_TRCHCOMMONDL,
    L1API_ERROR_PROC_TRCHCOMMONDLRE,
    L1API_ERROR_PROC_TRCHCOMMONUL,
    L1API_ERROR_PROC_RLINFO,
    L1API_ERROR_PROC_RLINFORE,
    L1API_ERROR_PROC_RLFAILINFO,
    L1API_ERROR_PROC_RLSFAILINFO,
    L1API_ERROR_PROC_RLRESTOREINFO,
    L1API_ERROR_PROC_RLSRESTOREINFO,
    L1API_ERROR_PROC_RLINFOBASIC,
    L1API_ERROR_PROC_DLCODEINFO,
    L1API_ERROR_PROC_DELAYEDACTIVATION,
    L1API_ERROR_PROC_DELAYEDACTUPDATE,
    L1API_ERROR_PROC_ACTIVATIONINFO,
    L1API_ERROR_PROC_ACTIVEPATTSEQINFO,
    L1API_ERROR_PROC_TGPSSTATUS,
    L1API_ERROR_PROC_DLPOWERBALANCINGINFO,
    L1API_ERROR_PROC_TRANSGAPPATTSEQINFO,
    L1API_ERROR_PROC_IPDLPARAMS,
    L1API_ERROR_PROC_IPDLPARAMSRE,
    L1API_ERROR_PROC_IPDLFDDPARAMS,
    L1API_ERROR_PROC_BURSTMODEPARAMS,
    L1API_ERROR_PROC_PHYSDLDPCH,
    L1API_ERROR_PROC_PHYSDLDPCHRE,
    L1API_ERROR_PROC_PHYSULDPCH,
    L1API_ERROR_PROC_PHYSULDPCHRE,
    L1API_ERROR_PROC_ULSCRAMCODEINFO,
    L1API_ERROR_PROC_CCTRCHDLTFC,
    L1API_ERROR_PROC_CCTRCHULTFC,
    L1API_ERROR_PROC_COORDTRCHDCH,
    L1API_ERROR_PROC_COORDTRCHDCHMOD,
    L1API_ERROR_PROC_RLINFORESP,
    L1API_ERROR_PROC_COORDTRCHRESP,
    L1API_ERROR_PROC_DCHSPECIFICINFO,
    L1API_ERROR_PROC_DCHSPECIFICINFOMOD,
    L1API_ERROR_PROC_TRCHTF,
    L1API_ERROR_PROC_TRANSFORMAT,
    L1API_ERROR_PROC_POWERADJCOMMON,
    L1API_ERROR_PROC_POWERADJINDIVIDUAL,
    L1API_ERROR_PROC_DLREFPWRINFO,
    L1API_ERROR_PROC_ADJUSTINFO,
    L1API_ERROR_PROC_HSDSCH,
    L1API_ERROR_PROC_HSDSCHINFO,
    L1API_ERROR_PROC_HSDSCHINFORE,
    L1API_ERROR_PROC_HSDSCHRE,
    L1API_ERROR_PROC_HSDSCHINFORESP,
    L1API_ERROR_PROC_HSSCCHINFORESP,
    L1API_ERROR_PROC_HARQMEMIMPLICIT,
    L1API_ERROR_PROC_HARQMEMEXPLICIT,
    L1API_ERROR_PROC_HSPDSCHCODEINFO,
    L1API_ERROR_PROC_HSSCCHCODEINFO,
    L1API_ERROR_PROC_HSDSCHMACDFLOWINFO,
    L1API_ERROR_PROC_HSDSCHMACDFLOWINFORE,
    L1API_ERROR_PROC_HSDSCHMACDFLOWDEL,
    L1API_ERROR_PROC_MACDFLOWINFOSETUP,
    L1API_ERROR_PROC_MACDFLOWINFO,
    L1API_ERROR_PROC_PRIORITYQUEUEINFORE,
    L1API_ERROR_PROC_PRIORITYQUEUEINFO,
    L1API_ERROR_PROC_PRIORITYQUEUEINFOMOD,
    L1API_ERROR_PROC_PRIORITYQUEUEINFODEL,
    L1API_ERROR_PROC_MACDPDUSIZEINDEX,
    L1API_ERROR_PROC_IBINFORMATION,
    L1API_ERROR_PROC_IBADDITIONINFO,
    L1API_ERROR_PROC_SEGINFO,
    L1API_ERROR_PROC_CELLMEASUREMENT,
    L1API_ERROR_PROC_RACHMEASUREMENT,
    L1API_ERROR_PROC_RLMEASUREMENT,
    L1API_ERROR_PROC_RLSMEASUREMENT,
    L1API_ERROR_PROC_MEASCMNINFO,
    L1API_ERROR_PROC_MEASDEDINFO,
    L1API_ERROR_PROC_REPORTCHARS,
    L1API_ERROR_PROC_MEASPERIODIC,
    L1API_ERROR_PROC_MEASEVENT1,
    L1API_ERROR_PROC_MEASEVENT2,
    L1API_ERROR_PROC_MEASEVENT3,
    L1API_ERROR_PROC_ONMODIFICATION,
    L1API_ERROR_PROC_MEASCHANGETHRESH,
    L1API_ERROR_PROC_MEASTHRESH,
    L1API_ERROR_PROC_COMMONMEASINFO,
    L1API_ERROR_PROC_COMMONMEASVALUE,
    L1API_ERROR_PROC_DEDICATEDMEASRLINFO,
    L1API_ERROR_PROC_DEDICATEDMEASRLSINFO,
    L1API_ERROR_PROC_DEDICATEDMEASINFO,
    L1API_ERROR_PROC_DEDICATEDMEASVALUE,
    L1API_ERROR_PROC_NBCOMCONTEXTSETUPINFO,
    L1API_ERROR_PROC_NBCOMCONTEXTSETUPINFORE,
    L1API_ERROR_PROC_NBCOMCONTEXTBASICINFO,
    L1API_ERROR_PROC_L1MSGSTATUS,
    L1API_ERROR_PROC_AUDITINFO,
    L1API_ERROR_PROC_DPCHAUDIT,
    L1API_ERROR_PROC_RESOURCE_NOT_AVAILABLE,
    L1API_ERROR_PROC_RESOURCE_NOT_SUPPORTED,
    L1API_ERROR_PROC_FEATURE_NOT_SUPPORTED,
    L1API_ERROR_PROC_IB_EXISTS,
    L1API_ERROR_PROC_IB_DOES_NOT_EXIST,
    L1API_ERROR_PROC_RESOURCE_INVALID_STATE,
    L1API_ERROR_PROC_INTERNAL_ERROR,
    L1API_ERROR_PROC_SYSINFO_DATA_SIZE_ERROR,
    L1API_ERROR_PROC_SEG_VALIDATION_ERROR,
    L1API_ERROR_PROC_PRACH_PHYSID_ERROR,
    L1API_ERROR_PROC_AICH_PHYSID_ERROR,
    L1API_ERROR_PROC_FACH_TRCHID_ERROR,
    L1API_ERROR_PROC_PCH_TRCHID_ERROR,
    L1API_ERROR_PROC_PICH_PHYSID_ERROR,
    L1API_ERROR_PROC_RADIOLINK_DOES_NOT_EXIST,
    L1API_ERROR_PROC_CELL_DOES_NOT_EXIST,
    L1API_ERROR_PROC_TRCH_DOES_NOT_EXIST,
    L1API_ERROR_PROC_TRCH_DELETE_VALIDATION_ERROR,
    L1API_ERROR_PROC_HSDSCH_EXISTS,
    L1API_ERROR_PROC_HSDSCH_DOES_NOT_EXIST,
    L1API_ERROR_PROC_PRIORITY_QUEUE_DOES_NOT_EXIST,
    L1API_ERROR_PROC_MACD_FLOW_DOES_NOT_EXIST,
    L1API_ERROR_PROC_MSR_MGR_CLIENT_ERR
} L1APIError_t;


/* Message Status */
typedef struct l1api_msg_status_s {
    L1APIError_t    l1MsgStatusMsgResult;
    U32             l1MsgStatusAdditional0;
    U32             l1MsgStatusAdditional1;
} l1api_msg_status_t;

typedef enum {
    L1API_ADD0_ENCODE_FP_DATA_INVALID_FRAME_TYPE,
    L1API_ADD0_ENCODE_FP_CTRL_INVALID_FRAME_TYPE,
    L1API_ADD0_ENCODE_FP_DATA_INVALID_CHANNEL_TYPE,
    L1API_ADD0_ENCODE_FP_CTRL_INVALID_CHANNEL_TYPE
} l1api_add0_info_t;

/* L1API DownLink Messages */
typedef enum L1APIDlMsg_s {
/*    L1API_FP_DCH_MSG,
    L1API_FP_FACH_MSG,
    L1API_FP_PCH_MSG,
    L1API_FP_HSDSCH_MSG,
    L1API_FP_RACH_MSG,
    L1API_FP_EDCH_UL_MSG  ,*/
    L1API_FP_DL_DATA_MSG,
    L1API_FP_DL_CTRL_MSG,
    L1API_CELL_SETUP_REQUEST,
    L1API_CELL_RECONFIG_REQUEST,
    L1API_CELL_DELETE_REQUEST,
    L1API_SYSTEM_INFO_UPDATE_REQUEST,
    L1API_CMN_TRCH_PRACH_SETUP_REQUEST,
    L1API_CMN_TRCH_SCCPCH_SETUP_REQUEST,
    L1API_CMN_TRCH_PRACH_RECONFIG_REQUEST,
    L1API_CMN_TRCH_SCCPCH_RECONFIG_REQUEST,
    L1API_CMN_TRCH_DELETE_REQUEST,
    L1API_RADIOLINK_SETUP_REQUEST,
    L1API_RADIOLINK_RECONFIG_PREP_REQUEST,
    L1API_RADIOLINK_RECONFIG_COMMIT_REQUEST,
    L1API_RADIOLINK_RECONFIG_CANCEL_REQUEST,
    L1API_RADIOLINK_ACTIVATION,
    L1API_RADIOLINK_DELETE_REQUEST,
    L1API_PHYSICAL_SHARED_CH_RECONFIG_REQUEST,
    L1API_COMPRESSED_MODE_CMD,
    L1API_DL_POWER_CTRL_REQUEST,
    L1API_COMMON_MEAS_INIT_REQ,
    L1API_COMMON_MEAS_TERMINATE_REQ,
    L1API_DEDICATED_MEAS_INIT_REQ,
    L1API_DEDICATED_MEAS_TERMINATE_REQ,
    L1API_MODEM_SETUP_REQUEST,
    L1API_AUDIT_REQUEST,
    L1API_INVALID_REQUEST
} l1api_dlmsg_t;

/* L1API Uplink messages */
typedef enum L1APIUlMsg_t {
    L1API_CMN_TRCH_PRACH_SETUP_RESPONSE = L1API_INVALID_REQUEST + 1,
    L1API_CMN_TRCH_SCCPCH_SETUP_RESPONSE,
    L1API_RADIOLINK_SETUP_RESPONSE,
    L1API_RADIOLINK_RECONFIG_READY,
    L1API_RADIOLINK_FAILURE_INDICATION,
    L1API_RADIOLINK_RESTORE_INDICATION,
    L1API_COMMON_MEAS_REPORT,
    L1API_COMMON_MEAS_FAILURE_IND,
    L1API_DEDICATED_MEAS_REPORT,
    L1API_DEDICATED_MEAS_FAILURE_IND,
    L1API_GENERIC_RESPONSE,
    L1API_ALARM_INDICATION,
    L1API_AUDIT_RESPONSE,
    L1API_FP_UL_DATA_MSG,
    L1API_FP_UL_CTRL_MSG,
    L1API_ERROR_ENCODING_MESSAGE,
    L1API_SOCKET_ERROR,
    L1API_UNKNOWN_EVENT
} l1api_event_t;

typedef union l1api_msgid_u
{
    l1api_dlmsg_t   dlmsg;
    l1api_event_t   event;
} l1api_msgid_t;

/**************************************************************/
/* Event parameters */
/**************************************************************/

/* HSDSCH_CAPACITY_ALLOCATION */

typedef struct l1api_hsdsch_capacity_allocation_s {
    l1api_id_t  id;
    U32         hsdsch_repetition_period;
    U32         hsdsch_credits;
    U8          cmch_pi;
    U32         maximum_mac_d_pdu_length;
    U32         hsdsch_interval;
    L1APIError_t             error;
} l1api_hsdsch_capacity_allocation_t;

/* HSDSCH_CAPACITY_REQUEST */

typedef struct l1api_hsdsch_capacity_request_s {
    l1api_id_t  id;
    U8          cmch_pi;
    U32         user_buffer_size_1;
    U32         user_buffer_size_0;
    L1APIError_t             error;
} l1api_hsdsch_capacity_request_t;

/* GENERIC_EVENT */

typedef struct l1api_generic_event_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_generic_event_t;

/* CELL_SETUP_CNF */

typedef struct l1api_cell_setup_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_cell_setup_cnf_t;

/* CELL_DELETE_CNF */

typedef struct l1api_cell_delete_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_cell_delete_cnf_t;

/* COMMON_TRCH_SETUP_CNF */

#define L1API_MAX_FACH      8

typedef U32     l1api_binding_id_t;

typedef struct l1api_rach_setup_resp_s
{
    l1api_binding_id_t  binding_id;
    l1api_msg_status_t  msgStatus;
} l1api_rach_setup_resp_t;

typedef struct l1api_sccpch_setup_resp_s
{
    U8                  n_FACH;
    l1api_binding_id_t  FACH_binding_id[L1API_MAX_FACH];
    l1api_binding_id_t  PCH_binding_id;
    l1api_msg_status_t  msgStatus;
} l1api_sccpch_setup_resp_t;


typedef struct l1api_ctrch_setup_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_ctrch_setup_cnf_t;

/* COMMON_TRCH_DELETE_CNF */

typedef struct l1api_ctrch_delete_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_ctrch_delete_cnf_t;

/* RADIO_LINK_SETUP_CNF */

typedef struct l1api_rl_setup_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_rl_setup_cnf_t;

/* RADIO_LINK_RECONFIG_PREPARE_CNF */

typedef struct l1api_rl_reconfig_prepare_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_rl_reconfig_prepare_cnf_t;

/* RADIO_LINK_RECONFIG_CANCEL_CNF */

typedef struct l1api_rl_reconfig_cancel_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_rl_reconfig_cancel_cnf_t;

/* RADIO_LINK_RECONFIG_COMMIT_CNF */

typedef struct l1api_rl_reconfig_commit_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_rl_reconfig_commit_cnf_t;

/* RADIO_LINK_DELETE_CNF */

typedef struct l1api_rl_delete_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_rl_delete_cnf_t;

/* MEASUREMENT_SETUP_CNF */

typedef struct l1api_measurement_setup_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_measurement_setup_cnf_t;

/* MEASUREMENT_DELETE_CNF */

typedef struct l1api_measurement_delete_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_measurement_delete_cnf_t;

/* SYSTEM_VERSION_CNF */

typedef struct l1api_system_version_cnf_s {
  l1api_id_t     id;        /* Not used */
  L1APIError_t  error;      /* Error code */
  char           version[256];  /* Version string */
} l1api_system_version_cnf_t;

/* DL_POWER_CONTROL_CNF */

typedef struct l1api_dl_power_control_cnf_s {
  l1api_id_t     id;        /* Radio link */
  L1APIError_t  error;      /* Error code */
} l1api_dl_power_control_cnf_t;

/* OCNS_POWER_CONTROL_CNF */

typedef struct l1api_ocns_power_control_cnf_s {
  l1api_id_t     id;        /* Cell identifier */
  L1APIError_t  error;      /* Error code */
} l1api_ocns_power_control_cnf_t;

/* DL_TPC_CONTROL_CNF */

typedef struct l1api_dl_tpc_control_cnf_s {
  l1api_id_t     id;        /* Radio link */
  L1APIError_t  error;      /* Error code */
} l1api_dl_tpc_control_cnf_t;

/* SYSTEM_AGC_STATUS_CNF */

typedef struct l1api_agc_status_cnf_s {
  l1api_id_t       id;      /* Cell identity */
  L1APIError_t     error;    /* Error code */
  U32              antenna_id;  /* Antenna identifer (0..1) */
  l1api_agc_mode_t agc_mode;    /* Mode (0=>closed loop, 1=>open loop) */
  U16              gain_value;  /* -78dB<=0..900<=12dB (.1db steps) */
  U32              power;   /* Power average (TBD) */
} l1api_agc_status_cnf_t;

/* AWGN START CNF */

typedef struct l1api_start_awgn_cnf_s {
  l1api_id_t       id;      /* Cell identity */
  L1APIError_t    error;    /* Error code */
} l1api_start_awgn_cnf_t;

/* AWGN STOP CNF */

typedef struct l1api_stop_awgn_cnf_s {
  l1api_id_t       id;      /* Cell identity */
  L1APIError_t    error;    /* Error code */
} l1api_stop_awgn_cnf_t;

/* DL_DATA_CNF */

typedef struct l1api_dl_data_cnf_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_dl_data_cnf_t;

/* BFN_IND */

typedef struct l1api_bfn_ind_s {
  l1api_bfn_t bfn;
} l1api_bfn_ind_t;

/* RADIO_LINK_FAILURE_IND */

typedef struct l1api_radio_link_failure_ind_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_radio_link_failure_ind_t;

/* RADIO_LINK_RESTORE_IND */

typedef struct l1api_radio_link_restore_ind_s {
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_radio_link_restore_ind_t;

/* ERROR_IND */

typedef struct l1api_error_ind_s {
  l1api_entity_t            entity;
  l1api_id_t                id;
  L1APIError_t             error;
} l1api_error_ind_t;

/* Generic Response */
typedef struct l1api_generic_response_s {
    l1api_msg_status_t  msgStatus;
    L1MsgId_e       associatedMsg;
} l1api_generic_response_t;

/* DEBUG_IND */

typedef struct l1api_debug_ind_s {
  U32                       msg;
  void                      *params;
} l1api_debug_ind_t;

/* MEASUREMENT_RESPONSE */

typedef struct l1api_measurement_response_s {
  l1api_id_t               measurement_id;
  BOOL                     measurement_available;
  l1api_sfn_t              sfn;
  U16                      n_objects;
  l1api_measurement_info_t *measurements;
} l1api_measurement_response_t;


/* MEASUREMENT_REPORT_IND */

typedef struct l1api_measurement_report_ind_s {
  l1api_id_t               measurement_id;
  BOOL                     measurement_available;
  l1api_sfn_t              sfn;
  U16                      n_objects;
  l1api_measurement_info_t *measurements;
} l1api_measurement_report_ind_t;

/* RadioLink Setup Response */

#define L1API_MAX_COORD_TRCH    15

typedef U16     l1api_rl_set_id_t;

typedef struct l1api_coord_trch_resp_s {
    l1api_dch_id_t      dch_id;
    l1api_binding_id_t  binding_id;
} l1api_coord_trch_resp_t;

typedef struct l1api_edch_mac_d_flow_info_resp_s {
    U16                             paramPresentFlag;
    l1api_macd_flow_id_t            mac_d_flow_id;
    l1api_binding_id_t              binding_id;
    l1api_harq_proc_alloc_2ms_tti_t harq_proc_alloc_2ms_non_sched_tx_grant;
} l1api_edch_mac_d_flow_info_resp_t;

typedef struct l1api_edch_fdd_ctrl_chan_info_s {
    U16 paramPresentFlag;
    l1api_dl_scram_code_t          eagch_rgch_hich_scram_code;
    l1api_dl_chan_code_t           eagch_chan_code;
    l1api_ernti_t                  primary_ernti;
    l1api_ernti_t                  secondary_ernti;
    l1api_dl_chan_code_t           ergch_hich_chan_code;
    l1api_signature_seq_t          ergch_signature_seq;
    l1api_signature_seq_t          ehich_signature_seq;
    l1api_serving_grant_val_t      serving_grant_val;
    l1api_pri_sec_grant_selector_e pri_sec_grant_selector;
    l1api_ergch_release_ind_e      ergch_release_ind;
} l1api_edch_fdd_ctrl_chan_info_t;

typedef struct l1api_rl_edch_fdd_info_resp_s {
    U16                               paramPresentFlag;
    l1api_rl_set_id_t                 edch_rl_set_id;
    U8                                mac_d_flow_count;
    l1api_harq_proc_alloc_2ms_tti_t   harq_proc_alloc_2ms_sched_tx_grant;
    l1api_edch_mac_d_flow_info_resp_t edch_mac_d_flow_info_resp[L1_MAX_NUM_EDCH_MACD_FLOWS];
    l1api_edch_fdd_ctrl_chan_info_t   edch_fdd_ctrl_chan_info;
} l1api_edch_fdd_info_resp_t;
typedef struct l1api_rl_info_resp_s {
    U8                      n_coord_trch;
    l1api_rl_id_t           rl_id;
    l1api_rl_set_id_t       rl_set_id;
    l1api_rl_id_t           reference_rl_id;
    l1api_coord_trch_resp_t coord_trch_resp[L1API_MAX_COORD_TRCH];
    l1api_edch_fdd_info_resp_t edch_fdd_info_resp;   
} l1api_rl_info_resp_t;

typedef enum {
    L1API_HARQ_MEM_IMPLICIT,
    L1API_HARQ_MEM_EXPLICIT
} l1api_harq_mem_choice_t;

typedef struct l1api_macD_flow_info_s {
    l1api_macd_flow_id_t    macD_flow_id;
    l1api_binding_id_t      binding_id;
} l1api_macD_flow_info_t;

typedef struct l1api_hsscch_info_resp_s {
    l1api_chan_code_t       hsscch_code_num;
} l1api_hsscch_info_resp_t;

typedef struct l1api_harq_mem_implicit_s{
    U8          n_process;
} l1api_harq_mem_implicit_t;

typedef enum {
    L1API_PROC_MEM_SZ_800,
    L1API_PROC_MEM_SZ_1600,
    L1API_PROC_MEM_SZ_2400,
    L1API_PROC_MEM_SZ_3200,
    L1API_PROC_MEM_SZ_4000,
    L1API_PROC_MEM_SZ_4800,
    L1API_PROC_MEM_SZ_5600,
    L1API_PROC_MEM_SZ_6400,
    L1API_PROC_MEM_SZ_7200,
    L1API_PROC_MEM_SZ_8000,
    L1API_PROC_MEM_SZ_8800,
    L1API_PROC_MEM_SZ_9600,
    L1API_PROC_MEM_SZ_10400,
    L1API_PROC_MEM_SZ_11200,
    L1API_PROC_MEM_SZ_12000,
    L1API_PROC_MEM_SZ_12800,
    L1API_PROC_MEM_SZ_13600,
    L1API_PROC_MEM_SZ_14400,
    L1API_PROC_MEM_SZ_15200,
    L1API_PROC_MEM_SZ_16000,
    L1API_PROC_MEM_SZ_17600,
    L1API_PROC_MEM_SZ_19200,
    L1API_PROC_MEM_SZ_20800,
    L1API_PROC_MEM_SZ_22400,
    L1API_PROC_MEM_SZ_24000,
    L1API_PROC_MEM_SZ_25600,
    L1API_PROC_MEM_SZ_27200,
    L1API_PROC_MEM_SZ_28800,
    L1API_PROC_MEM_SZ_30400,
    L1API_PROC_MEM_SZ_32000,
    L1API_PROC_MEM_SZ_36000,
    L1API_PROC_MEM_SZ_40000,
    L1API_PROC_MEM_SZ_44000,
    L1API_PROC_MEM_SZ_48000,
    L1API_PROC_MEM_SZ_52000,
    L1API_PROC_MEM_SZ_56000,
    L1API_PROC_MEM_SZ_60000,
    L1API_PROC_MEM_SZ_64000,
    L1API_PROC_MEM_SZ_68000,
    L1API_PROC_MEM_SZ_72000,
    L1API_PROC_MEM_SZ_76000,
    L1API_PROC_MEM_SZ_80000,
    L1API_PROC_MEM_SZ_88000,
    L1API_PROC_MEM_SZ_96000,
    L1API_PROC_MEM_SZ_104000,
    L1API_PROC_MEM_SZ_112000,
    L1API_PROC_MEM_SZ_120000,
    L1API_PROC_MEM_SZ_128000,
    L1API_PROC_MEM_SZ_136000,
    L1API_PROC_MEM_SZ_144000,
    L1API_PROC_MEM_SZ_152000,
    L1API_PROC_MEM_SZ_160000,
    L1API_PROC_MEM_SZ_176000,
    L1API_PROC_MEM_SZ_192000,
    L1API_PROC_MEM_SZ_208000,
    L1API_PROC_MEM_SZ_224000,
    L1API_PROC_MEM_SZ_240000,
    L1API_PROC_MEM_SZ_256000,
    L1API_PROC_MEM_SZ_272000,
    L1API_PROC_MEM_SZ_288000,
    L1API_PROC_MEM_SZ_304000
} l1api_process_mem_size_t;

typedef struct l1api_harq_mem_explicit_s{
    U8                          n_process;
    l1api_process_mem_size_t    process_mem_size[8];
} l1api_harq_mem_explicit_t;

typedef struct l1api_hsdsch_info_resp_s {
    U8                          n_macD_flow;
    U8                          n_hsscch_codes;
    l1api_harq_mem_choice_t     harq_mem_choice;
    l1api_macD_flow_info_t      macD_flow_info[8];
    l1api_hsscch_info_resp_t    hsscch_info_resp[8];
    l1api_harq_mem_implicit_t   harq_mem_implicit;
    l1api_harq_mem_explicit_t   harq_mem_explicit;
} l1api_hsdsch_info_resp_t;

typedef struct l1api_rl_setup_response_s {
    l1api_Nb_com_context_t      nodeB_context;
    U8                          n_rl;
    l1api_msg_status_t          msgStatus;
    l1api_rl_info_resp_t        rl_info_resp[1];    
    l1api_hsdsch_info_resp_t    hsdsch_info_resp;
} l1api_rl_setup_response_t;

typedef struct l1api_rl_reconfig_ready_s {
    U8                          n_rl;
    l1api_msg_status_t          msgStatus;
    l1api_rl_info_resp_t        rl_info_resp[1];
    l1api_hsdsch_info_resp_t    hsdsch_info_resp;
} l1api_rl_reconfig_ready_t;

typedef enum {
    L1API_RL_FAIL_RL,
    L1API_RL_FAIL_RLS
} l1api_rl_fail_report_obj_t;

typedef struct l1api_rl_restore_info_s {
    U8              n_rl;
    l1api_rl_id_t   rl_id[16];
} l1api_rl_restore_info_t;

typedef struct l1api_rls_restore_info_s {
    U8                  n_rls;
    l1api_rl_set_id_t   rl_set_id[16];
} l1api_rls_restore_info_t;

typedef struct l1api_rl_restore_ind_s {
    l1api_Nb_com_context_t      nodeB_context;
    l1api_rl_fail_report_obj_t  rl_fail_report_obj;
    l1api_rl_restore_info_t     rl_restore_info;
    l1api_rls_restore_info_t    rls_restore_info;
} l1api_rl_restore_ind_t;

typedef enum {
    L1API_RADIOLINK_FAILURE_SYNC_FAILURE,
    L1API_RADIOLINK_FAILURE_INVALID_CM_SETTINGS
} l1api_failure_cause_t;

typedef struct l1api_rl_failure_info_s {
    U8                      n_rl;
    l1api_rl_id_t           rl_id[16];
    l1api_failure_cause_t   failure_cause[16];
} l1api_rl_failure_info_t;

typedef struct l1api_rls_failure_info_s {
    U8                      n_rls;
    l1api_rl_set_id_t       rl_set_id[16];
    l1api_failure_cause_t   failure_cause[16];
} l1api_rls_failure_info_t;

typedef struct l1api_rl_failure_ind_s {
    l1api_Nb_com_context_t      nodeB_context;
    l1api_rl_fail_report_obj_t  rl_fail_report_obj;
    l1api_rl_failure_info_t     rl_failure_info;
    l1api_rls_failure_info_t    rls_failure_info;
} l1api_rl_failure_ind_t;



/* L1API device */
typedef void *l1api_dev_t;




/* Functions ------------------------------------------------------------- */

L1APIError_t L1APIInit (char *serverAddr,
                        U16 serverPort,
                        void *callbackContext,
                        void (*callbackFn)(void *, l1api_event_t, void *),
                        void (*traceFn) (char *str, ...),
                        L1APIHdlr_t *hdlr);

L1APIError_t L1APITerm(L1APIHdlr_t hdlr);

L1APIError_t L1APICellSetupRequest (L1APIHdlr_t handle, l1api_cell_t *cell);

L1APIError_t L1APICellReconfigRequest (L1APIHdlr_t handle, l1api_cell_t *cell);

L1APIError_t L1APICellDeleteRequest (L1APIHdlr_t handle, l1api_cell_delete_request_t *cell_del);

L1APIError_t L1APISystemInfoUpdateRequest (L1APIHdlr_t handle, l1api_bch_sysinfo_t *params);

L1APIError_t L1APICmnTrchPrachSetupRequest (L1APIHdlr_t handle, l1api_rach_t *ctrch);

L1APIError_t L1APICmnTrchSccpchSetupRequest (L1APIHdlr_t handle, l1api_fach_pch_t *ctrch);

L1APIError_t L1APICmnTrchPrachReconfigRequest (L1APIHdlr_t handle, l1api_rach_t *ctrch);

L1APIError_t L1APICmnTrchSccpchReconfigRequest (L1APIHdlr_t handle, l1api_fach_pch_t *ctrch);

L1APIError_t L1APICmnTrchDeleteRequest (L1APIHdlr_t handle, l1api_common_trch_delete_t *del);

L1APIError_t L1APIRadiolinkSetupRequest (L1APIHdlr_t handle, l1api_rl_t *rl);

L1APIError_t L1APIRadiolinkDeleteRequest (L1APIHdlr_t handle, l1api_rl_delete_t *rl_del);

L1APIError_t L1APIRadiolinkReconfigPrepRequest(L1APIHdlr_t handle, l1api_rl_reconfig_t *rl);

L1APIError_t L1APIRadiolinkReconfigCancelRequest (L1APIHdlr_t handle, l1api_id_t id);

L1APIError_t L1APIRadiolinkReconfigCommitRequest (L1APIHdlr_t handle, l1api_rl_reconfig_commit_t *params);

L1APIError_t L1APIRadiolinkActivation (L1APIHdlr_t handle, l1api_rl_reconfig_commit_t *params);

L1APIError_t L1APIDLPowerCtrlRequest (L1APIHdlr_t handle, l1api_dl_power_control_t *params);

L1APIError_t L1APIPhysicalSharedChReconfigRequest(L1APIHdlr_t handle,
                                                  l1api_physical_shared_ch_reconfig_request_t *params);

L1APIError_t L1APICompressedModeCmd(L1APIHdlr_t handle, l1api_compressed_mode_cmd_t *params);

L1APIError_t L1APICommonMeasInitRequest(L1APIHdlr_t handle, l1api_measurement_t *measurement);

L1APIError_t L1APICommonMeasTerminateRequest(L1APIHdlr_t handle, l1api_id_t id);

L1APIError_t L1APIDedicatedMeasInitRequest(L1APIHdlr_t handle, l1api_measurement_t *measurement);

L1APIError_t L1APIDedicatedMeasTerminateRequest(L1APIHdlr_t handle, l1api_id_t id);

L1APIError_t L1APIModemSetupRequest(L1APIHdlr_t handle/*, l1api_modem_setup_request_t *params*/);

L1APIError_t L1APIAuditRequest(L1APIHdlr_t handle, l1api_audit_request_t *params);

char *l1api_error_to_string(L1APIError_t e);

U8 CalculateHeaderCRC (U8 const *fpHeader, U16 headerSize);
U16 CalculatePayloadCRC (U8 const *fpPayload, U16 payloadSize);



#ifdef __cplusplus
}
#endif

#endif /* __SA_L1API_STRUCTS_H__ */

/* End of op_sa_l1api.h */


/********************************************************************30**

  End of file:     op_sa_l1api_structs.h@@/main/3 - Mon Aug 10 21:05:23 2009

*********************************************************************31*/

/********************************************************************40**

  Notes:

*********************************************************************41*/

/********************************************************************50**

*********************************************************************51*/

/********************************************************************60**

  Revision history:

*********************************************************************61*/
/********************************************************************70**

  version    initials                   description
  -----------  ---------  ------------------------------------------------

*********************************************************************71*/

/********************************************************************80**

*********************************************************************81*/
/********************************************************************90**

  ver       pat    init                  description
  ----------- -------- ---- -----------------------------------------------
/main/3      ---    sy           1.Created for Release FAP 1.3
*********************************************************************91*/
