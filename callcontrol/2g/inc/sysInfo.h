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
* File Name   : sys_info.h
 *
* Description : GSM system information messages header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/


#ifndef _SYS_INFO_H_
#define _SYS_INFO_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "l1Constants.h"
#include "gsmData.h"

#define GSM_BTS_SI(bts, i)  (tOCT_UINT8 *) (bts->si_buf[i])

// 3GPP TS 44.018 section 10.5.2.11
// CCCH-CONF, NC is not combined
#define CCCH_CONF_1_NC  0x00
#define CCCH_CONF_1_C   0x01
#define CCCH_CONF_2_NC  0x02
#define CCCH_CONF_3_NC  0x04
#define CCCH_CONF_4_NC  0x06

extern tOCT_UINT8 lai[5];

// 3GPP TS 44.018 section 10.2
// 3GPP TS 24.007 section 11.2.3.1.1
typedef enum
{
    PROTO_DISC_GROUP_CC,
    PROTO_DISC_BCAST_CC,
    PROTO_DISC_RES,
    PROTO_DISC_CC_SS,
    PROTO_DISC_GTTP,
    PROTO_DISC_MM,
    PROTO_DISC_RR,
    PROTO_DISC_MM_GPRS = 0x08,
    PROTO_DISC_SMS,
    PROTO_DISC_SM_GPRS,
    PROTO_DISC_NC_SS,
    PROTO_DISC_LOC,
    PROTO_DISC_RES_PD = 0x0e,
    PROTO_DISC_RES_TST
}eRR_PROTO_DESC;

// 3GPP TS 44.018 section 10.4
typedef enum
{
    MT_RR_SYSINFO_TYPE_8 = 0x18,
    MT_RR_SYSINFO_TYPE_1,
    MT_RR_SYSINFO_TYPE_2 = 0x1a,
    MT_RR_SYSINFO_TYPE_3,
    MT_RR_SYSINFO_TYPE_4,
    MT_RR_SYSINFO_TYPE_5,
    MT_RR_SYSINFO_TYPE_6,
    MT_RR_SYSINFO_TYPE_7,
    MT_RR_SYSINFO_TYPE_2bis = 0x02,
    MT_RR_SYSINFO_TYPE_2ter,
    MT_RR_SYSINFO_TYPE_9,
    MT_RR_SYSINFO_TYPE_5bis,
    MT_RR_SYSINFO_TYPE_5ter,
    MT_RR_SYSINFO_TYPE_2quater,
    MT_RR_SYSINFO_TYPE_13 = 0x00,
    MT_RR_SYSINFO_TYPE_16 = 0x3d,
    MT_RR_SYSINFO_TYPE_17,
}eRR_MT_SYSINFO;

// see section 9.1.3x 3GPP TS 44.018
// System information Type header
struct sys_info_header
{
    tOCT_UINT8 l2_p_len;
    tOCT_UINT8 rr_proto_disc:4,
      skip_ind:4;
    tOCT_UINT8 sys_info;
};

// 3GPP TS 24.008
// Section 10.5.1.3
struct loc_area_id
{
    tOCT_UINT8 digits[3];
    tOCT_UINT16 lac;
};

// 3GPP TS 44.018
// section 10.5.2.11
struct ctrl_chan_desc
{
    tOCT_UINT8 ccch_conf :3,
      bs_ag_blks_res :3,
      att :1,
      mscr :1;
    tOCT_UINT8 bs_pa_mfrms :3,
      spare :2,
      cbq3 :2,
      si22ind :1;
    tOCT_UINT8 t3212;
};

// 3GPP TS 44.018
// section 10.5.2.3
struct cell_options
{
    tOCT_UINT8 radio_link_timeout:4,
        dtx:2,
        pwrc:1,
        spare:1;
};

// 3GPP TS 44.018
// Section 9.1.31 System information Type 1
struct sys_info_type_1
{
    struct sys_info_header header;
    tOCT_UINT8 cell_channel_desc[16];
    struct rach_ctrl rach_control;
    tOCT_UINT8 rest_octets[1];
};

// 3GPP TS 44.018
// Section 9.1.32 System information Type 2
struct sys_info_type_2
{
    struct sys_info_header header;
    tOCT_UINT8 bcch_frequency_list[16];
    tOCT_UINT8 ncc_permitted;
    struct rach_ctrl rach_control;
};

// 3GPP TS 44.018
// Section 9.1.35
struct sys_info_type_3
{
    struct sys_info_header header;
    tOCT_UINT16 cell_identity;
    struct loc_area_id lai;
    struct ctrl_chan_desc control_channel_desc;
    struct cell_options cell_options;
    struct cell_select_par cell_sel_par;
    struct rach_ctrl rach_control;
    tOCT_UINT8 rest_octets[4];
};

// 3GPP TS 44.018
// Section 9.1.36
struct sys_info_type_4
{
    struct sys_info_header header;
    struct loc_area_id lai;
    struct cell_select_par cell_sel_par;
    struct rach_ctrl rach_control;
    tOCT_UINT8 rest_octets[10];
};

// 3GPP TS 44.018
// Section 9.1.43a
struct sys_info_type_13
{
    struct sys_info_header header;
    tOCT_UINT8 rest_octets[20];
};

#ifdef FEA_2G_INTER_RAT_MEAS
struct sys_info_type_2q
{
    struct sys_info_header header;
    tOCT_UINT8 rest_octets[20];
};
#endif

int generate_si1(tOCT_UINT8 *output, gsm_trx *trx);
int generate_si2(tOCT_UINT8 *output, gsm_bts *bts);
int generate_si3(tOCT_UINT8 *output, gsm_bts *bts);
int generate_si4(tOCT_UINT8 *output, gsm_bts *bts);
#ifdef FEA_GPRS
int generate_si13(tOCT_UINT8 *output, gsm_bts *bts);
#endif
#ifdef FEA_2G_INTER_RAT_MEAS
int generate_si2q();
#endif

void get_sysinfo(gsm_bts *bts, rts_time *g_time, tOCT_UINT8 *si);
void set_ccch_config(struct ctrl_chan_desc *chan_desc, gsm_trx *trx);
void generate_chan_desc(struct ctrl_chan_desc *chan_desc,  gsm_trx *trx);
int  ms_power_control(int band, unsigned int dbm);
int generate_bcch_frequency_list(tOCT_UINT8* bcch_frequency_list, tOCT_UINT8 nbr_of_arfcns, tOCT_UINT32* arfcns);
tOCT_UINT8* getLaiFromSysInfo();
void generate_lai(struct loc_area_id *lai, gsm_network network, tOCT_UINT16 lac);
#endif  //#ifndef _SYS_INFO_H_

