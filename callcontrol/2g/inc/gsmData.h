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
* File Name   : gsm_data.h
 *
* Description : common gsm header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/

#ifndef _GSM_DATA_H_
#define _GSM_DATA_H_

#include "l1Constants.h"

#ifdef MM_INFO
#define GSM_NETWORK_NAME_MAX_SIZE 32
#endif

typedef tOCT_UINT8 sysinfo_t[GSM_MACBLOCK_LEN];

typedef struct gsm_network_
{
    tOCT_UINT8 mcc[GSM_MAX_MCC_LENGTH];
    tOCT_UINT8 mcc_length;
    tOCT_UINT8 mnc[GSM_MAX_MNC_LENGTH];
    tOCT_UINT8 mnc_length;
}gsm_network;

// 3GPP TS 44.018
// Section 10.5.2.4
struct cell_select_par
{
    tOCT_UINT8 ms_txpwr_max_ccch:5,
               cell_resel_hyst:3;
    tOCT_UINT8 rxlev_acc_min:6,
               neci:1,
               acs:1;
};

struct opt_cell_select_par
{
    tOCT_UINT8 parameter_present:1,
               cell_bar_qualify:1,
               cell_reselect_offset:6;
    tOCT_UINT8 temp_offset:3,
               penalty_time:5;
};

// 3GPP TS 44.018
// section 10.5.2.29
struct rach_ctrl {
    tOCT_UINT8 re :1,
      cell_bar :1,
      tx_int :4,
      max_trans :2;
    tOCT_UINT8 t2;
    tOCT_UINT8 t3;
};

#ifdef FEA_2G_INTER_RAT_MEAS
typedef struct 
{
	int            uarfcn;
    int            psc;
}gsm3gNeighCell;
#endif

#ifdef FEA_EMER
typedef struct 
{
    tOCT_UINT8  bandIndicator;
    tOCT_UINT8  bsic;
    tOCT_UINT16 arfcn;
}EmergencyRedirectInfo;
#endif
// One BTS
typedef struct gsm_bts_
{
    gsm_network  network;

    // Cell Identity
    tOCT_UINT16 cell_identity;

    // location area code of this BTS
    tOCT_UINT16 location_area_code;

    // Training Sequence Code
    tOCT_UINT8 tsc;

    // Base Station Identification Code (BSIC)
    tOCT_UINT8 bsic;

    tOCT_UINT8 band;

    // maximum Tx power that the MS is permitted to use in this cell
    int ms_max_power;

    // Cell Selection Parameters
    struct cell_select_par cell_sel_par;

    // Optional Cell Selection Parameters
    struct opt_cell_select_par opt_cell_sel_par;

    // RACH Control Parameters
    struct rach_ctrl rach_ctrl_par;

    // Neighbour List
    GERAN_ARFCN_LIST_STR neigh_list;

    // Neighbour List ( CA List)
    GERAN_HOPPING_LIST_STR neigh_ca_list;

    // Radio Link Timeout
    tOCT_UINT8 radio_link_timeout;
    
    // bitmask of SI that are present in si_buf
    tOCT_UINT32 si_valid;

    // buffers where we put the pre-computed SI */
    tOCT_UINT8 si1_buf[GSM_MACBLOCK_LEN];
    tOCT_UINT8 si2_buf[GSM_MACBLOCK_LEN];
#ifdef FEA_2G_INTER_RAT_MEAS
    tOCT_UINT8         si2q_buf[MAX_SI2Q_INSTANCES][GSM_MACBLOCK_LEN];
    tOCT_UINT8         noOfValidSi2qInstances;
    fxL2gInterRatInfo  interRatInfo;
    gsm3gNeighCell     gsm3gNeighCellList[FXL_2G_MAX_3G_NEIGHBOR_UARFCNS * FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN];;
#endif
    tOCT_UINT8 si3_buf[GSM_MACBLOCK_LEN];
    tOCT_UINT8 si4_buf[GSM_MACBLOCK_LEN];
    
	tOCT_UINT8 si13_buf[GSM_MACBLOCK_LEN];
	
    //Access class List
    tOCT_UINT16 access_class_list;

    // Base Station Identification Code (BSIC) for Redirection
    tOCT_UINT8 redirBsic;

    // Redirection Type
    tOCT_UINT8 redirType;

    // Redirection Band
    tOCT_UINT8 redirBand;

    // Redirection ARFCN
    tOCT_UINT16 redirArfcn;
    
    // TA Filter
    tOCT_UINT8 ta_filter_start;
    tOCT_UINT8 ta_filter_stop;
    
    // T3212 timer
    tOCT_UINT8 t3212;

    // Number of Agch block
    tOCT_UINT8 blockReservedForAgch;

    // Paging periodicty
    tOCT_UINT8 pagingPeriodicity;
#ifdef MM_INFO
    // Network Name
    tOCT_UINT8 nwName[GSM_NETWORK_NAME_MAX_SIZE];
    tOCT_UINT8 nwNameLen;
#endif
#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
    tOCT_UINT8 sendSmsDuringRegistration;
#endif
#ifdef FEA_EMER
    char                   Emergencyredirectenable;
    EmergencyRedirectInfo  Redirectemergencyinfo;  
#endif
}gsm_bts;

// One Timeslot in a TRX
typedef struct gsm_ts_
{
    // ts number
    tOCT_UINT8 ts_num;

    // subchannel
    tOCT_UINT8 sc_num;

    // configured logical channel for this ts
    eLOGICAL_CHANNEL_TYPE lchan;

    int tsc; // usually -1 == use BTS TSC
    // add support to hopping in future here
}gsm_ts;

// One TRX in BTS
typedef struct gsm_trx_
{
     gsm_bts  bts;

    // TRX id
    tOCT_UINT8 trx_id;

    // TS num
    tOCT_UINT8 tsNum;

    tOCT_UINT16 arfcn;

    int nominal_power;      // in dBm
    unsigned int max_power_red; // in actual dB

    gsm_ts ts[MAX_TS];

}gsm_trx;

typedef struct gsm_time_
{
    tOCT_UINT32 fn;  // FN count
    tOCT_UINT16 t1;  // FN div (26*51)
    tOCT_UINT8  t2;  // FN modulo 26
    tOCT_UINT8  t3;  // FN modulo 51
    tOCT_UINT8  tc;
}gsm_time;

typedef struct rts_time_
{
    tOCT_UINT32 fn;  // FN count
    tOCT_UINT16 t1;  // FN div (26*51)
    tOCT_UINT8  t2;  // FN modulo 26
    tOCT_UINT8  t3;  // FN modulo 51
    tOCT_UINT8  tc;
}rts_time;

#endif  //#ifndef _GSM_DATA_H_

