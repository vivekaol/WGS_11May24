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
* File Name   : sls.h
 *
* Description : System information decoder for GSM messages.
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------
* 11/10/2014          					Anand Kashikar            Initial File Creation
*######################################################################################
*/

#ifndef _SLS_H_
#define _SLS_H_

#include <setjmp.h>
#include "gsmCommon.h"
#include "fxLSocketInterfaceApi.h"
#include "octdev_types.h"
#include "octvc1/octvc1_radio.h"

#define TRUE 1
#define FALSE 0


#define RR_SI2QUATER_REST_OCTS_LEN          20
#define RR_SI2BIS_FREQ_LIST_IE_OFFSET       0
#define RR_SI2TER_FREQ_LIST_IE_OFFSET       0
#define RR_SI2TER_REST_OCTETS_IE_OFFSET     16
#define RR_SI2TER_REST_OCTS_LEN             4
#define RR_SI2TER_REST_OCTS_MAX_AMOUNT      8

#define SI_INVALID_GERAN_PRIORITY       127
#define SI_INVALID_THRESH_PRIO_SRCH     127
#define SI_INVALID_THRESH_GSM_LOW       127
#define SI_INVALID_H_PRIO               127
#define SI_INVALID_T_RESELECTION        127
#define SI_INVALID_FREQ_INDEX           127
#define SI_INVALID_UTRAN_PRIORITY       127
#define SI_INVALID_THRESH_UTRAN         127
#define SI_INVALID_UTRAN_QRXLEVMIN      127
#define SI_THRESH_PRIO_SRCH_ALWAYS_VAL  126
#define SI_THRESH_GSM_LOW_ALWAYS_VAL    126
#define SI_H_PRIO_RULE_DISABLED_VAL     126
#define SI_UTRAN_QRXLEVMIN_DEFAULT_VAL  0
#define SI_EUTRAN_MEAS_BW_DEFAULT_VAL   0
#define SI_EUTRAN_QRXLEVMIN_DEFAULT_VAL 0
#define SI_INVALID_EUTRAN_PRIORITY      255
#define SI_MAX_NUM_EUTRAN_FREQ          8
/* The value 126 should be considered as lowest priority (i.e. lower 
 than the eight network configured values). */
#define SI_GERAN_PRIORITY_BELOW_ZERO    126
#define SI2QUATER_INVALID_INDEX         255 
#define SI_INVALID_LIST_ID              255

/* Possible values for T_SI_REPORTING_TYPE
 */
#define REPORT_TYPE_NORMAL   1
#define REPORT_TYPE_ENHANCED 0

#define SI_REP_TYPE_DEFAULT_VAL         REPORT_TYPE_NORMAL
#define SI_SERVING_BAND_REP_DEFAULT_VAL     3

#define SI_MISSING_3G_NCELL_LIST_INDEX      0xFFFF
#define SYSINFO_INVALID_SCRAMBLING_CODE     65535

#define SI_QOFFSET_DEFAULT_VAL              8
#define SI_FDD_QMIN_DEFAULT_VAL             7


/* maximum values for RTD
 */
#define RMCP_6_BIT_RTD_MAX_VAL  50
#define RMCP_12_BIT_RTD_MAX_VAL 3263

#define RMCP_RANGE_1024_VALUE_PART_LEN        16

/*  Mask for getting scrambling code from FDD_CELL_INFORMATION parameter,
 *  see FDD_CELL_INFO_PARAMS_STR
 */
#define FDD_CELL_INFO_PARAM_PSC_MASK    0x01FF

/*  Mask for getting  diversity from FDD_CELL_INFORMATION parameter,
 *  see FDD_CELL_INFO_PARAMS_STR
 */
#define FDD_CELL_INFO_PARAM_DIV_MASK    0x0200

/* Maximum number of FDD ARFCN indexes in 3G neighbour cell Priority List
 *
 * Note: Assigned value is 32 because according to 44018-8a0 table 10.5.2.33b.1
 * the UTRAN_FREQUENCY_INDEX value range is 0-31.
 */
#define MAX_NR_OF_FDD_ARFCN_INDEX               32

/* Value to indicate Invalid UTRAN frequency in 3G frequency list.
 */
#define SI_INVALID_UTRAN_FREQ               0xFFFD

#define POWER_TXPWR_TABLE_INDEX_COUNT  32

/*
 * Used in C2 calculations, see GSM 05.08 Chapt 6.4
 */
#define SPECIAL_PENALTY_TIME               31


#define B1111_0000 0xF0
#define B0000_1111 0x0F
#define B0000_0001 0x01
#define B1111_1000 0xF1
#define B0001_0000 0x10
#define B1000_0000 0x80

#define GREATEST_PWR_OF_2_LESS_OR_EQ_TO(index,result) \
            { for(result=1;result<=index;result*=2){} result/=2; }

typedef enum 
{
    CELL_ALLOCATION,
    BCCH_ALLOCATION,
    FDD_CELL_INFO_PARAMS
} type_of_freq_allocation;

typedef enum
{
    CELL_CHANNEL_DESCR,
    FREQUENCY_LIST,
    FREQUENCY_SHORT_LIST,
    NEIGHBOUR_CELL_DESCR,
    NEIGHBOUR_CELL_DESCR_2,
    UMTS_NCELL_DESCR
} type_of_frequency_ie;

/* Type for CSN.1 decoding errors.
 */
typedef enum
{
    /* First value in this enum shall not be zero, because these values are
     * used by longjmp to indicate error!
     */
    RMCP_CSN1_ERROR_OUT_OF_BITS = 1,
    RMCP_CSN1_ERROR_SEMANTIC,
    RMCP_CSN1_ERROR_SYNTAX
} T_RMCP_CSN1_ERROR;

typedef struct
    {
    tOCT_UINT8 cell_reselect_offset;
    tOCT_UINT8 temporary_offset;
    tOCT_UINT8 penalty_time;
    tOCT_UINT8 cbq;
    tOCT_UINT8 present;
    } SI_OPT_SELECTION_PARS_STR;
typedef struct
    {
    tOCT_UINT8       gprs_supported;
    tOCT_UINT8       ra_colour;
    tOCT_UINT8       si13_position;
    } SI_GPRS_INDICATOR_STR;
typedef struct
    {
    tOCT_UINT8       present;
    tOCT_UINT8       opt_power_offset;
    } SI_OPT_POWER_OFFSET_STR;
typedef struct
    {
    tOCT_UINT8       present;
    tOCT_UINT8       where;
    } SI_IF_AND_WHERE_STR;
typedef struct
    {
    tOCT_UINT8       present;
    tOCT_UINT8       si2quater_position;
    } SI_SI2QUATER_INDICATOR_STR;

/* Bitmap for neighbour cell lists
 * Bitmap contains 1 bit for each cell in the list.
 *
 * Bit for cell whose index in neighbour list is n is in following position
 * in the bitmap:
 *     Byte (0 denotes first byte in bitmap):             n / 8
 *     Bit within byte (7 denotes MSB and 0 denotes LSB): 7 - (n % 8)
 * Example:
 *     a = bit for cell whose index is 0
 *     b = bit for cell whose index is 1
 *     c = bit for cell whose index is 2
 *     d = bit for cell whose index is 3
 *     e = bit for cell whose index is 4
 *     f = bit for cell whose index is 5
 *     g = bit for cell whose index is 6
 *     h = bit for cell whose index is 7
 *     i = bit for cell whose index is 8
 *     j = bit for cell whose index is 9
 *     k = bit for cell whose index is 10
 *     ->
 *     [0] = abcd_efgh
 *     [1] = ijk0_0000
 *
 * Use macros RMCP_SI_NCELL_LIST_BITMAP_WRITE and RMCP_SI_NCELL_LIST_BITMAP_READ
 * to write/read bits to/from a bitmap.
 */
typedef struct
{
    tOCT_UINT8 bits[SI_NCELL_LIST_BITMAP_SIZE];
} SI_NCELL_LIST_BITMAP_STR;

typedef struct
    {
    SI_OPT_SELECTION_PARS_STR       opt_selection_params;
    SI_GPRS_INDICATOR_STR           gprs_indicator;
    SI_OPT_POWER_OFFSET_STR         opt_power_offset;
    SI_IF_AND_WHERE_STR             if_and_where;
    SI_SI2QUATER_INDICATOR_STR      si2quater_indicator;
    tOCT_UINT8                           si2ter_indicator;
    tOCT_UINT8                           early_clm_sending_ctrl;
    tOCT_UINT8                           early_3g_clm_sending_restrict;
    } SI_SI3_REST_OCTETS_STR;
typedef struct s_t_cell_identity_str
    {
    tOCT_UINT8    ci_value[LENGTH_OF_CELL_IDENTITY];
    } T_CELL_IDENTITY_STR;
typedef struct
    {
    tOCT_UINT8    mcc2_mcc1;
    tOCT_UINT8    mnc3_mcc3;
    tOCT_UINT8    mnc2_mnc1;
    tOCT_UINT8    lac[2];
    } T_LAI_INFO_STR;
typedef struct
	{
	tOCT_UINT16   mcc;
	tOCT_UINT16   mnc;
	tOCT_UINT16   lac;
	} T_LAI_BCD;
typedef struct
    {
    tOCT_UINT8                       att_allowed;
    tOCT_UINT8                       bs_ag_blks_res;
    tOCT_UINT8                       sdcch_ccch_cmb_flag;
    tOCT_UINT8                       bs_cc_chans;
    tOCT_UINT8                       bs_pa_mfrms;
    tOCT_UINT8                       t3212_value;
    } SI_CTRL_CHANNEL_DESCR_STR;

typedef struct
    {
    SI_CTRL_CHANNEL_DESCR_STR   ctrl_ch_descr;
    tOCT_UINT8                       mscr;
    } RR_CTRL_CHANNEL_DESCR_STR;

typedef struct
    {
    tOCT_UINT8                       pwrc_set;
    tOCT_UINT8                       dtx;
    tOCT_UINT8                       radio_link_timeout;
    } SI_CELL_OPTIONS_STR;

typedef struct
    {
    tOCT_UINT8    cell_reselect_hysteresis;
    tOCT_UINT8   ms_txpwr_max_cch;
    tOCT_UINT8   rxlev_access_min;
    tOCT_UINT8    acs;
    tOCT_UINT8    neci;
    } SI_CELL_SELECT_PARAMS_STR;
typedef struct
    {
    tOCT_UINT8                       max_retrans;
    tOCT_UINT8                       tx_integer;
    tOCT_UINT8                       cell_bar_access;
    tOCT_UINT8                       re_disabled;
    tOCT_UINT8                       ec_disabled;
    } SI_RACH_CTRL_PARAMS_STR;

typedef struct
    {
    SI_RACH_CTRL_PARAMS_STR rach_ctrl_params;
    tOCT_UINT16                  access_control_class;
    } RR_RACH_CTRL_PARAMS_STR;

typedef struct
    {
    SI_SI3_REST_OCTETS_STR          si3_rest_octets;
    T_CELL_IDENTITY_STR             cell_id;
    T_LAI_INFO_STR                  lai;
    RR_CTRL_CHANNEL_DESCR_STR       ctrl_channel_desc;
    SI_CELL_OPTIONS_STR             bcch_cell_options;
    SI_CELL_SELECT_PARAMS_STR       cell_select_parameters;
    RR_RACH_CTRL_PARAMS_STR         rach_control_parameters;
    } SI_DECODED_SI3_STR;

typedef struct s_SI_BYTE_BASED_NEIG_CELLS_DES_STR
    {
    tOCT_UINT8        neighbour_descr_parameter;
    tOCT_UINT8        bcch_alloc_ch_120_1[15];
    } SI_BYTE_BASED_NEIG_CELLS_DES_STR;
typedef struct
    {
    tOCT_UINT8           neighbor_cell_description[RR_NEIGHBOUR_CELLS_DESCR_LEN];
    tOCT_UINT8           si2bis_expected;
    tOCT_UINT8           ncc_permitted;
    } RR_DECODED_SI2_STR;

typedef struct s_S_SYSINFO_LINKED_LIST_STR
{
    struct  s_S_SYSINFO_LINKED_LIST_STR *next_ptr;
} S_SYSINFO_LINKED_LIST_STR;

/* Structure for SI2quater's reporting parameters for GSM.
 *
 *
 * Elements
 *
 * REPORT_TYPE
 *
 report_type
 *
 * SERVING_BAND_REPORTING
 *
 serving_band_reporting
 */
typedef struct
{
    tOCT_UINT8 report_type;
    tOCT_UINT8 serving_band_reporting;
} RR_SI2QUATER_GSM_REP_PARS_STR;

/* Structure for SI2quater's 3G measurement and reporting parameters for GSM.
 *
 *
 * Elements
 *
 * FDD parameters: FDD_Qoffset, FDD_REP_QUANT, FDD_MULTIRAT_REPORTING and
 * FDD_Qmin
 *
 fdd_params
 *
 * Qsearch_I
 *
 qsearch_i
 *
 * Qsearch_C_Initial
 *
 qsearch_c_initial
 *
 * Defines whether corresponding field is present, i.e. its value is valid.
 *
 fdd_params_present
 */
typedef struct
{
    struct
    {
      tOCT_UINT8 fdd_qoffset;
      tOCT_UINT8 fdd_rep_quant;
      tOCT_UINT8 fdd_multirat_reporting;
      tOCT_UINT8 fdd_qmin;
    } fdd_params;

    tOCT_UINT8 qsearch_i;
    tOCT_UINT8 qsearch_c_initial;
    tOCT_UINT8 fdd_params_present;     
} RR_SI2QUATER_GSM_3G_PARS_STR;

typedef struct
{
    tOCT_UINT8 identifier;
    tOCT_UINT8 identifier_is_psi3_change_mark;
} SI_NCELL_LIST_IDENTIFIER_STR;

/* Linked list that defines Repeated UTRAN FDD Neighbour Cells struct.
 *
 *
 * Elements
 *
 * Points to next Repeated UTRAN FDD Neighbour Cells struct element.
 * Null-pointer indicates that there are no more elements in the struct.
 *
 next_ptr
 *
 * FDD-ARFCN
 *
 explicit_fdd_arfcn
 *
 * Indicates if FDD_CELL_INFORMATION parameter value '0000000000' is a member
 * of the set.
 *     TRUE  - parameter value '0000000000' is a member of the set
 *     FALSE - parameter value '0000000000' is not a member of the set
 *
 fdd_indic0
 *
 * Number of FDD_CELL_INFORMATION parameters in FDD_CELL_INFORMATION Field.
 *
 no_of_fdd_cells
 *
 * Scrambling codes and diversity parameters compressed to Range 1024 format.
 *
 * Number of bits in this field can be found out from field 'no_of_fdd_cells'
 * with function rmcp_fdd_cell_info_length_calc.
 *
 * The bits in this field are ordered so that each byte holds eight bits
 * starting from MSB of FDD_CELL_INFORMATION Field. If number of bits is not
 * divisible by eight, remaining bits are set at the high part of the last byte.
 * In following example, number of bits is 19 and the bits of the
 * FDD_CELL_INFORMATION Field are presented with lower case letters
 * (MSB is 'a' and LSB is 's'):
 *     FDD_CELL_INFORMATION Field: (MSB) abcdefghijklmnopqrs (LSB)
 *     ->
 *     fdd_cell_information_field[0] = abcd_efgh
 *     fdd_cell_information_field[1] = ijkl_mnop
 *     fdd_cell_information_field[2] = qrs0_0000
 *
 fdd_cell_information_field
 */
typedef struct s_SI_REP_UTRAN_FDD_NCELLS_STR
{
    struct s_SI_REP_UTRAN_FDD_NCELLS_STR* next_ptr;

    tOCT_UINT16 explicit_fdd_arfcn;
    tOCT_UINT8  fdd_indic0;
    tOCT_UINT8  no_of_fdd_cells;
    tOCT_UINT8  fdd_cell_information_field[SI_FDD_CELL_INFO_FIELD_LENGTH];
} SI_REP_UTRAN_FDD_NCELLS_STR;

/* UTRAN FDD Description struct.
 *
 *
 * Elements
 *
 * Points to Repeated UTRAN FDD Neighbour Cells struct.
 * Null-pointer indicates that the struct is not present.
 *
 rep_utran_fdd_ncells
 *
 * BANDWIDTH_FDD
 *
 bandwidth_fdd
 *
 * Defines whether corresponding field is present, i.e. its value is valid.
 *
 bandwidth_fdd_present
 */
typedef struct
{
    SI_REP_UTRAN_FDD_NCELLS_STR* rep_utran_fdd_ncells;
    tOCT_UINT8 bandwidth_fdd;
    tOCT_UINT8 bandwidth_fdd_present; 
} SI_UTRAN_FDD_DESCR_STR;

/* Decoded 3G Neighbour Cell Description from MEASUREMENT INFORMATION,
 * SI2quater, PSI3quater, PACKET MEASUREMENT ORDER and PACKET CELL CHANGE
 * ORDER.
 *
 *
 * Elements
 *
 * Points to UTRAN FDD Description.
 * Null-pointer indicates that UTRAN FDD Description is not present.
 *
 utran_fdd_descr
 *
 * Index_Start_3G.
 * Default value 0 shall be used to indicate that the field is not present.
 *
 index_start_3g
 *
 * Absolute_Index_Start_EMR.
 *
 absolute_index_start_emr
 *
 * Defines number of tdd cells described in the IE. Default value 0
 *
 no_of_tdd_cells
 *
 * Defines number of cdma2000 cells described in the IE. Default value 0
 *
 no_of_cdma2000_cells
 *
 * Defines whether corresponding field is present, i.e. its value is valid.
 *
 absolute_index_start_emr_present
 */
typedef struct
{
    SI_UTRAN_FDD_DESCR_STR* utran_fdd_descr;
    tOCT_UINT8 index_start_3g;
    tOCT_UINT8 absolute_index_start_emr;
    tOCT_UINT8 no_of_tdd_cells;
    tOCT_UINT8 no_of_cdma2000_cells;
    tOCT_UINT8 absolute_index_start_emr_present; 
} SI_3G_NCELL_DESCR_STR;


/* Structure for storing 3G neighbour cell descriptions.
 *
 *
 * Elements
 *
 * Pointer to pointers to 3G Neighbour Cell Descriptions.
 *
 umts_ncells_descr
 *
 * 3G Neighbour Cell Descriptions identifier.
 * Value SI_INVALID_LIST_ID indicates that the 3G Neighbour Cell Descriptions
 * shall not be used to construct 3G Neighbour Cell list.
 *
 umts_id
 *
 * Number of 3G Neighbour Cell Description pointers in 'umts_ncells_descr'.
 *
 nbr_of_3g_ncell_descr
 *
 * Tells if value 31 of NR_OF_FDD_CELLS within the 3G Neighbour Cell
 * Descriptions indicates that the corresponding FDD ARFCN is for 3G Cell
 * Reselection list.
 *     TRUE  -- Value 31 of NR_OF_FDD_CELLS indicates FDD ARFCN for 3G Cell
 * Reselection list
 *     FALSE -- Value 31 of NR_OF_FDD_CELLS has no special meaning.
 *
 val_31_indicates_resel_list_freq
 */
typedef struct
{
    SI_3G_NCELL_DESCR_STR           **umts_ncells_descr;
    SI_NCELL_LIST_IDENTIFIER_STR    umts_id;
    tOCT_UINT8                      nbr_of_3g_ncell_descr;
    tOCT_UINT8                      val_31_indicates_resel_list_freq;
} SI_3G_NCELL_DESCRS_WITH_ID_STR;


typedef struct
{
    tOCT_UINT8 nw_ctrl_order;
    tOCT_UINT8 nc_non_drx_period;
    tOCT_UINT8 nc_reporting_period_i;
    tOCT_UINT8 nc_reporting_period_t;
    tOCT_UINT8 nc_params_present;
} SI_NC_MEAS_PARS_STR;

typedef struct
{
    tOCT_UINT8        geran_priority;
    tOCT_UINT8        thresh_priority_search;
    tOCT_UINT8        thresh_gsm_low;
    tOCT_UINT8        h_prio;
    tOCT_UINT8        t_reselection;
    tOCT_UINT8        scell_prio_params_present;
} SI_SERVCELL_PRIO_PARAMS_STR;

typedef struct
{
    tOCT_UINT8        default_utran_priority;
    tOCT_UINT8        default_thresh_utran;
    tOCT_UINT8        default_utran_qrxlevmin;
    tOCT_UINT8        def_3g_priority_params_present;
} SI_3G_DEFAULT_PRIO_PARAMS_STR;

typedef struct s_SI_REP_UTRAN_FREQ_INDEX_STR
{
    struct s_SI_REP_UTRAN_FREQ_INDEX_STR       *next_ptr;
    tOCT_UINT8                                  utran_freq_index;
} SI_REP_UTRAN_FREQ_INDEX_STR;

typedef struct s_SI_REP_UTRAN_PRIORITY_PARAMS_STR
{
    struct s_SI_REP_UTRAN_PRIORITY_PARAMS_STR  *next_ptr;
    SI_REP_UTRAN_FREQ_INDEX_STR                *rep_utran_freq_index;
    tOCT_UINT8                                  utran_priority;
    tOCT_UINT8                                  thresh_utran_high;
    tOCT_UINT8                                  thresh_utran_low;
    tOCT_UINT8                                  utran_qrxlevmin;
} SI_REP_UTRAN_PRIORITY_PARAMS_STR;

typedef struct
{
    SI_3G_DEFAULT_PRIO_PARAMS_STR           default_3g_prio_params_store;
    SI_REP_UTRAN_PRIORITY_PARAMS_STR        *rep_utran_params_store;
    tOCT_UINT8                              utran_priority_params_present;
} SI_UTRAN_PRIORITY_PARAMS_STR;

typedef struct
{
    tOCT_UINT8   utran_priority;
    tOCT_UINT8   thresh_utran_high_db;
    tOCT_UINT8   thresh_utran_low_db;
    tOCT_INT8    utran_qrxlevmin_dbm;
} FDD_PRIORITY_STR;

typedef struct
{
    tOCT_UINT16  freq;
    tOCT_UINT16  psc;
    tOCT_UINT8   diversity_applied;
} FDD_CELL_STR;


/* 3G Neighbour Cell list
 */
typedef struct
{

    /* Ordered list of FDD cells / frequencies.
       *
       * Note1: Plain frequency is defined with,
       *        frequency       = fdd_arfcn
       *        scrambling code = SYSINFO_INVALID_SCRAMBLING_CODE
       *
       * Note2: If cell not supported,
       *        frequency       = UNSUPPORTED_NEIGHBOUR_ARFCN
       *        scrambling code = SYSINFO_INVALID_SCRAMBLING_CODE
       */
    FDD_CELL_STR* cells;

    /* Ordered list of priorities for FDD cells.
       *
       * Note1: (fdd_priority+i) contains FDD priority of the cell (cells+i)
       *
       * Note2: fdd_priority is NULL when FDD priority information is not
       *        received for all the FDD cells and default priority is not
       *        available.
       *
       * Note3: If FDD priority information is not received for a particular cell
       *        and default UTRAN priority available then default priority values
       *        shall be filled for that cell.
       *
       * Note4: If FDD priority information is received for a particular cell
       *        however optional UTRAN priority parameter not present then
       *        INVALID value for that priority parameter shall be filled.
       *
       * Literature Reference:
       * 
       * 3GPP TS 44.018-880 V8.8.0 (2009-09)
       * Table 10.5.2.33b.1: 3G Priority Parameters Description.
       *
       */
    FDD_PRIORITY_STR* fdd_priority;

    /* Number of cells / frequencies pointed by 'cells'. */
    tOCT_UINT8 no_of_cells;
} SI_3G_NCELL_LIST_STR;


typedef struct s_SI_REP_EARFCN_MEAS_BW_STR
{
    struct s_SI_REP_EARFCN_MEAS_BW_STR	*next_ptr;
    tOCT_UINT16 earfcn;
    tOCT_UINT8  meas_bandwidth;
} SI_REP_EARFCN_MEAS_BW_STR;


typedef struct s_SI_REP_EUTRAN_NCELL_STR
{
    struct s_SI_REP_EUTRAN_NCELL_STR  *next_ptr;
    SI_REP_EARFCN_MEAS_BW_STR *rep_earfcn_meas_bandwidth_ptr;
    tOCT_UINT8 eutran_priority;
    tOCT_UINT8 thresh_eutran_high;
    tOCT_UINT8 thresh_eutran_low;
    tOCT_UINT8 eutran_qrxlevmin;
} SI_REP_EUTRAN_NCELL_STR;

typedef struct
{
    tOCT_UINT8   eutran_priority;
    tOCT_UINT8   thresh_eutran_high_db;
    tOCT_UINT8   thresh_eutran_low_db;
    tOCT_INT16   eutran_qrxlevmin_dbm;
} EUTRAN_PRIORITY_STR;

typedef struct
{
    tOCT_UINT16 eutran_arfcn;
    tOCT_UINT8  eutran_pcid_bitmap[E_MAX_PCID_BITMAP];
    EUTRAN_PRIORITY_STR eutran_priority_info;
    tOCT_UINT8 eutran_meas_bw_nrb;
} EUTRAN_FREQ_STR;

typedef struct
{
    EUTRAN_FREQ_STR *eutran_freq;
    tOCT_UINT8 no_of_eutran_freqs;
} SI_EUTRAN_NA_CELL_LIST_STR;


typedef struct s_SI_REP_PCID_STR
{
    struct s_SI_REP_PCID_STR  *next_ptr;
    tOCT_UINT16 pcid;
} SI_REP_PCID_STR;

typedef struct s_SI_REP_PCID_PATTERN_STR
{
    struct s_SI_REP_PCID_PATTERN_STR  *next_ptr;
    tOCT_UINT8 pcid_pattern_length;
    tOCT_UINT8 pcid_pattern;
    tOCT_UINT8 pcid_pattern_sense;
} SI_REP_PCID_PATTERN_STR;

typedef struct s_SI_PCID_GROUP_STR
{
    SI_REP_PCID_STR *rep_explicit_pcid_ptr;
    SI_REP_PCID_PATTERN_STR *rep_pcid_pattern_ptr;
    tOCT_UINT8 pcid_bitmap_group;
    tOCT_UINT8 pcid_bitmap_group_present;
} SI_PCID_GROUP_STR;

typedef struct s_SI_REP_EUTRAN_FREQ_INDEX_STR
{
    struct s_SI_REP_EUTRAN_FREQ_INDEX_STR *next_ptr;
    tOCT_UINT8 eutran_freq_index;
} SI_REP_EUTRAN_FREQ_INDEX_STR;

typedef struct s_SI_REP_EUTRAN_NA_CELLS_STR
{
    struct s_SI_REP_EUTRAN_NA_CELLS_STR  *next_ptr;
    SI_PCID_GROUP_STR not_allowed_cells;
    SI_REP_EUTRAN_FREQ_INDEX_STR *rep_eutran_freq_index_ptr;
} SI_REP_EUTRAN_NA_CELLS_STR;

typedef struct s_SI_REP_PCIDS_TA_STR
{
    struct s_SI_REP_PCIDS_TA_STR  *next_ptr;
    SI_PCID_GROUP_STR pcid_group;
} SI_REP_PCIDS_TA_STR;

typedef struct s_SI_REP_EUTRAN_FREQ_STR
{
    struct s_SI_REP_EUTRAN_FREQ_STR *next_ptr;
    tOCT_UINT16 eutran_arfcn;
} SI_REP_EUTRAN_FREQ_STR;

typedef struct s_SI_REP_EUTRAN_PCID_TO_TA_STR
{
    struct s_SI_REP_EUTRAN_PCID_TO_TA_STR *next_ptr;
    SI_REP_PCIDS_TA_STR *rep_pcid_ta_group_ptr;
    SI_REP_EUTRAN_FREQ_INDEX_STR *rep_eutran_freq_index_ptr;
} SI_REP_EUTRAN_PCID_TO_TA_STR;

typedef struct s_SI_REP_EUTRAN_TA_STR
{
    struct s_SI_REP_EUTRAN_TA_STR *next_ptr;
    SI_REP_EUTRAN_FREQ_STR *rep_eutran_freq_ptr;
    tOCT_UINT8 eutran_pcid_bm[E_MAX_PCID_BITMAP];
    tOCT_UINT8 all_pcids_same_ta;
} SI_REP_EUTRAN_TA_STR;


typedef struct
{
    RR_SI2QUATER_GSM_REP_PARS_STR gsm_reporting_params;
    RR_SI2QUATER_GSM_3G_PARS_STR* gsm_3g_params;
    SI_3G_NCELL_DESCR_STR* umts_ncell_descr;
    SI_NC_MEAS_PARS_STR* nc_meas_params;
    SI_NCELL_LIST_BITMAP_STR* ccn_supported;

    /* RAT8 priority parameters
         */
    SI_SERVCELL_PRIO_PARAMS_STR* servcell_prio_params;
    SI_UTRAN_PRIORITY_PARAMS_STR* utran_prio_params;
    tOCT_UINT8 utran_start;
    tOCT_UINT8 utran_stop;
    tOCT_UINT8 ba_ind;
    struct
    {   
      tOCT_UINT8 fdd_qmin_offset;
      tOCT_UINT8 fdd_rscpmin;
    } umts_additional_meas_pars;
    tOCT_UINT8 fdd_reporting_threshold_2;
    tOCT_UINT8 umts_ba_ind;
    tOCT_UINT8 mp_change_mark;
    tOCT_UINT8 si2quater_index;
    tOCT_UINT8 si2quater_count;
    tOCT_UINT8 umts_ccn_active;

    SI_REP_EUTRAN_NCELL_STR *rep_eutran_ncells_ptr;
    SI_REP_EUTRAN_NA_CELLS_STR *rep_eutran_na_cells_ptr;
    SI_REP_EUTRAN_PCID_TO_TA_STR *rep_pcid_to_ta_map_ptr;
    tOCT_UINT8 eutran_start;
    tOCT_UINT8 eutran_stop;

    /* present indicators
         */
    tOCT_UINT8 gsm_reporting_params_present;
    tOCT_UINT8 rel6_params_present;
    tOCT_UINT8 rel8_params_present;
    tOCT_UINT8 eutran_params_present;
} RR_DECODED_SI2QUATER_STR;

/* Type for SI2quater Indicator.
 */
typedef enum
{
    RR_SI2QUATER_NOT_SENT,
    RR_SI2QUATER_SENT_ON_BCCH_NORM,
    RR_SI2QUATER_SENT_ON_BCCH_EXT
} T_RR_SI2QUATER_INDICATOR;

/* Enum to indicate different states of fast acquisition
 * 
 * RR_FAST_ACQ_INCOMPLETE = Fast acqusition is not enabled (or)
 *                          fast acq is ongoing
 *
 * RR_FAST_ACQ_COMPLETED = Fast acqusition is complete however not yet stored
 *                         to SYSINFO.
 *
 * RR_FAST_ACQ_STORED = Parameters got by fast acqusition are stored in SYSINFO.
 *
 *
*/
typedef enum
{
    RR_FAST_ACQ_INCOMPLETE,
    RR_FAST_ACQ_COMPLETED,
    RR_FAST_ACQ_STORED
} T_RR_FAST_ACQUISITION_STATUS;


/* Type for structure for SI2quater reception book-keeping.
 *
 * 
 * Elements
 *
 * Dynamic array of pointers to decoded SI2quater instances.
 * Array contains 'si2quater_count' + 1 valid pointers where non-null pointer
 * indicates that corresponding instance has been received (array index
 * equals to SI2quater_INDEX).
 *
 * Null-pointer indicates that we haven't yet received any SI2quater instances.
 *
 instances
 *
 * SI2quater indicator (from SI3).
 *
 si2quater_indicator
 *
 * Latest received SI2quater_COUNT, MP_CHANGE_MARK, BA_IND and 3G_BA_IND.
 * These fields are valid only when 'instances' is non-NULL.
 *
 si2quater_count
 mp_change_mark
 ba_ind
 umts_ba_ind
 */    
typedef struct
    {
    RR_DECODED_SI2QUATER_STR** instances;
    T_RR_SI2QUATER_INDICATOR si2quater_indicator;
    tOCT_UINT8 si2quater_count;
    tOCT_UINT8 mp_change_mark; 
    tOCT_UINT8 ba_ind;
    tOCT_UINT8 umts_ba_ind;
    tOCT_UINT8 fast_acq_utran_start_index;
    tOCT_UINT8 fast_acq_utran_stop_index;
    T_RR_FAST_ACQUISITION_STATUS fast_acq_utran_status;
    tOCT_UINT8 fast_acq_eutran_start_index;
    tOCT_UINT8 fast_acq_eutran_stop_index;
    T_RR_FAST_ACQUISITION_STATUS fast_acq_eutran_status;
} RR_SI2QUATER_RCPTN_STATUS_STR;

typedef struct s_fdd_cell_info_params_str
    {
    tOCT_UINT32 params[MAX_NO_OF_FDD_CELL_INFO_PARAMS];
    tOCT_UINT8 no_of_params;
    } FDD_CELL_INFO_PARAMS_STR;


typedef struct
{
    struct
    {
        tOCT_UINT16 fdd_arfcn;
        tOCT_UINT8 bandwidth_fdd;
        
        /* present indicators
         */
        tOCT_UINT8 bandwidth_fdd_present;
    } utran_fdd_descr; 

    struct
    {
        tOCT_UINT8 qsearch_i;
        struct
        {
            tOCT_UINT8 fdd_qoffset;
            tOCT_UINT8 fdd_qmin;
        } fdd_params;
            
        /* present indicators
         */
        tOCT_UINT8 fdd_params_present;     
    } umts_meas_pars;
    struct
    {   
        tOCT_UINT8 fdd_qmin_offset;
        tOCT_UINT8 fdd_rscpmin;
    } umts_additional_meas_pars;
    tOCT_UINT8 si2ter_mp_change_mark;
    tOCT_UINT8 si2ter_3g_change_mark;
    tOCT_UINT8 si2ter_index;
    tOCT_UINT8 si2ter_count;

    /* present indicators
     */
    tOCT_UINT8 utran_fdd_descr_present;
    tOCT_UINT8 umts_meas_pars_present;
    tOCT_UINT8 umts_addition_meas_pars_present;
} RR_DECODED_SI2TER_REST_OCTS_STR;

struct
{
    RR_DECODED_SI2TER_REST_OCTS_STR** instances;
    tOCT_UINT8 si2ter_count;
    tOCT_UINT8 si2ter_mp_change_mark;
    tOCT_UINT8 si2ter_3g_change_mark;
} rr_si2ter_rest_octs;

typedef struct s_l1_cell_allocation_str
    {
    T_CARRIER_NUMBER hopping_list[SIZE_OF_HOPPING_LIST];
    } L1_CELL_ALLOCATION_STR;

typedef union
    {
    L1_CELL_ALLOCATION_STR ca;
    GERAN_ARFCN_LIST_STR ba;
    FDD_CELL_INFO_PARAMS_STR fdd_cell_info_params;
    } L1_ALLOCATION_UNION_STR;

typedef struct
    {
    L1_ALLOCATION_UNION_STR*        cell_allocation;
    tOCT_UINT8                           band_indicator;
    } RR_DECODED_SI1_STR;

typedef union
    {
    tOCT_UINT8 bcch_data[RR_BCCH_SI_DATA_LEN];
    } RR_BYTE_BASED_SI_UNION_STR;

typedef struct
	{
	tOCT_UINT32 message_type;
	tOCT_UINT8 l3_data_index;
	tOCT_UINT8 l2_pseudo_length;
	} RR_DECODED_SI_HDR_STR;
typedef struct
	{	
    jmp_buf err_buf;
	tOCT_UINT8* decoding_position;
	tOCT_UINT16 bits_left;
	signed char bit_index;
	tOCT_UINT8 length;
	tOCT_UINT8 padding;
	} RMCP_CSN1_FIELD_READ_PARAMS_STR;

typedef struct s_S_BYTE_BASED_CBCH_CH_DES_STR
    {
    tOCT_UINT8    cbch_ch_parameter;
    tOCT_UINT8    hopping_on_parameter_1;
    tOCT_UINT8    hopping_on_parameter_2;
    } S_BYTE_BASED_CBCH_CH_DES_STR;

typedef struct s_S_CBCH_MOBILE_ALLOCATION_STR
    {
    tOCT_UINT8    length;
    tOCT_UINT8    mobile_allocation[CBCH_MOBILE_ALLOCATION_LENGTH];
    } S_CBCH_MOBILE_ALLOCATION_STR;

typedef struct
    {
    struct
        {
        SI_OPT_SELECTION_PARS_STR selection_pars;
        tOCT_UINT8 valid;
        } opt_selection_pars;
    struct
        {
        SI_GPRS_INDICATOR_STR gprs_indicator;
        tOCT_UINT8 valid;
        } gprs_pars;
    } RR_DECODED_SI4_REST_OCTS_STR; 

typedef struct
	{
	T_LAI_INFO_STR lai;
	SI_CELL_SELECT_PARAMS_STR cell_selection_parameters;
	RR_RACH_CTRL_PARAMS_STR rach_control_parameters;
	struct
		{
		S_BYTE_BASED_CBCH_CH_DES_STR ch_descr;
		S_CBCH_MOBILE_ALLOCATION_STR mobile_allocation;
		tOCT_UINT8 valid;
		} cbch_pars;
	RR_DECODED_SI4_REST_OCTS_STR* rest_octets;
	} RR_DECODED_SI4_STR;

typedef struct
{
	int servingCellId;
	tOCT_UINT16 siRcvd;
}combinedSIs;


tOCT_UINT32 convertToOct2gBandFromFxL(fxL2gBandType band);
char * WnmGetBandString( tOCTVC1_RADIO_STANDARD_ENUM f_ulWaveform, tOCT_UINT32 f_Band );

#endif  //#ifndef _SLS_H_
