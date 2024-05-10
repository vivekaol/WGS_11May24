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
* File Name   : l1_constants.h
 *
* Description : This file contains all enums,macros,constants
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/


#ifndef _L1_CONSTANTS_H_
#define _L1_CONSTANTS_H_

#include "gsmCommon.h"

// Globals
//struct parameters parms_g;

ConfigList configUeIdList;

#define EMPTY 0
#define FULL 1

#define MAX_TS  8
#define MAX_SUBCHAN_TIMESLOT    8

#ifdef FEA_GPRS
#define GPRS_MAX_TS  8
#endif

#define GSM_MAX_MCC_LENGTH  3
#define GSM_MAX_MNC_LENGTH  3

//Number of slots in frame
#define NSLOTS_IN_FRAME     8

#define L1_MSG_BASE_MSG_TYPE_SIZE (1)
#define L1_MSG_BASE_MSG_SIZE (1)
#define L1_MSG_BASE_SEQ_NUM_SIZE (2)
#define L1_MSG_BASE_HEADER_SIZE (L1_MSG_BASE_MSG_TYPE_SIZE + L1_MSG_BASE_MSG_SIZE + L1_MSG_BASE_SEQ_NUM_SIZE)

#define ETH_PACKET_SRC_MAC_ADDR_SIZE_BYTES  (6)
#define ETH_PACKET_DST_MAC_ADDR_SIZE_BYTES  (6)
#define ETH_PACKET_MAC_ADDR_SIZE_BYTES  (12)
#define ETH_PACKET_PAYLOAD_TYPE     (2)
#define ETH_PACKET_RESERVED         (2)
#define ETH_PACKET_HEADER_SIZE_BYTES_2G    (ETH_PACKET_MAC_ADDR_SIZE_BYTES + ETH_PACKET_PAYLOAD_TYPE + ETH_PACKET_RESERVED)

// Received message size from L1
#define ETH_RX_MSG_SIZE (504)

#define GSM_MACBLOCK_LEN   23
#define GSM_TCHH_FRAME_LEN 14
#define GSM_TCHF_FRAME_LEN 33

#define GSM_MACBLOCK_PADDING 0x2b

#ifdef FEA_2G_INTER_RAT_MEAS
#define MAX_SI2Q_INSTANCES 8
#define MAX_MI_INSTANCES   7
#endif
#define GSM_L3_MSG_MAX_SIZE 251

#define RRLP_TOTAL_SEGMENTS       4
#define RRLP_GPS_ASSIST_OCTET_LEN 13

#define GPRS_MACBLOCK_LEN GSM_MACBLOCK_LEN+2

#define MAX_PAGING_BLOCKS_IN_51_FRAME   9
#define MAX_COMBINED_PAGE_BLOCKS_IN_51  3

#define MAX_PAGING_PERIODICITY          9

typedef enum{
    GSM_450 = 0,
    GSM_850,
    GSM_900,
    DCS_1800,
    PCS_1900,
    E_GSM,
    R_GSM
}eBands;

typedef enum{
    EMPTY_CHANNEL=0,
    TCHF_FACCHF_SACCHTF,
    TCHH_FACCHH_SACCHTH,
    FCCH_SCH_BCCH_CCCH,
    FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4,
    SDCCH8_SACCHC8,
    PDTCHF_PACCHF_PTCCHF,
    eMAX_LOGICAL_CHANNEL_TYPE
}eLOGICAL_CHANNEL_TYPE; //eLogical_Channel_Type;

typedef enum{
    NO_PATH=0,
    RX_MS_BTS,
    RX_BTS_MS,
    TX_BTS_MS,
    TX_MS_BTS
}eDirection;

typedef enum{
    NONE_RATE = 0,
    FULL_RATE=0x1,
    ENH_FULL_RATE=0x2,
    HALF_RATE=0x3,
    AMR_FULL_RATE=0x4,
    AMR_HALF_RATE=0x5
}ePayloadType;

typedef enum{
    RATE_4_75=0,
    RATE_5_15=1,
    RATE_5_90=2,
    RATE_6_70=3,
    RATE_7_40=4,
    RATE_7_95=5,
    RATE_10_2=6,
    RATE_12_2=7,
    UNSET=0xF
}tAmrCodecMode;

typedef enum{
    SAPI_IDLE     = 0x00,
    SAPI_FCCH     = 0x01,
    SAPI_SCH      = 0x02,
    SAPI_SACCH    = 0x03,
    SAPI_SDCCH    = 0x04,
    SAPI_BCCH     = 0x05,
    SAPI_PCH_AGCH = 0x07,
    SAPI_CBCH     = 0x08,
    SAPI_RACH     = 0x09,
    SAPI_TCHF     = 0x0A,
    SAPI_FACCHF   = 0x0B,
    SAPI_TCHH     = 0x0C,
    SAPI_FACCHH   = 0x0D,
    SAPI_NCH      = 0x0E,
    SAPI_PDTCH    = 0x0F,
    SAPI_PACCH    = 0x10,
    SAPI_PBCCH    = 0x11,
    SAPI_PAGCH    = 0x12,
    SAPI_PPCH     = 0x13,
    SAPI_PNCH     = 0x14,
    SAPI_PTCCH    = 0x15,
    SAPI_PRACH    = 0x16
}eSAPI_CHANNEL_TYPE; //eSapi_Channel_Type

typedef enum{
    SYNC_BURST=0x0,
    NORMAL_BURST=0x1,
    DUMMY_BURST=0x2,
    NORMAL_BURST_8PSK=0x3,
    ACCESS_BURST_TS0=0x4,
    ACCESS_BURST_TS1=0x5,
    ACCESS_BURST_TS2=0x6,
    FREQ_CORRECTN_BURST=0x7,
}eBurstType; // eBurstType

typedef enum{
    STATUS_NOERR=0x00,
    STATUS_GENERR=0x01,
    STATUS_NOMEMERR=0x02,
    STATUS_TIMEOUTERR=0x03,
    STATUS_INVPARMERR=0x04,
    STATUS_BUSYRESERR=0x05,
    STATUS_NORESAVAILERR=0x06,
    STATUS_UNINITRESERR=0x07,
    STATUS_INVALTRXERR=0x08,
    STATUS_ARFCNRANGEERR=0x09,
    STATUS_BADCRCERR=0x0a,
    STATUS_BADUSFERR=0x0b,
    STATUS_INVALCPSERR=0x0c,
    STATUS_UNEXPBURSTERR=0x0d,
    STATUS_AMRCODECUNAVAILERR=0x0e,
    STATUS_CRITICALRR=0x0f,
    STATUS_OVERHEATERR=0x10,
    STATUS_DEVICEERR=0x11,
    STATUS_FACCHB4TCHERR=0x12,
    STATUS_DEACTIVATECHRR=0x13,
    STATUS_FIFOVERRUNERR=0x14,
    STATUS_FIFOUNDERRUNERR=0x15,
    STATUS_NOSYNCERR=0x16,
    STATUS_UNSUPPFEATERR=0x17,
    STATUS_NOGPSLOCKERR=0x18,
    STATUS_GPSSYNCTIMEOUTERR=0x19,
}eStatusErrorFlg;

typedef enum{

    SUBCH0=0x0,
    SUBCH1=0x1,
    SUBCH2=0x2,
    SUBCH3=0x3,
    SUBCH4=0x4,
    SUBCH5=0x5,
    SUBCH6=0x6,
    SUBCH7=0x7,
    SUBCHF=0xF1

}eSubChanNum;

typedef enum{
    A5_0 = 0,
    A5_1,
    A5_2,
    A5_3
}eCipherId;

typedef enum
{
    SYSINFO_TYPE_NONE,
    SYSINFO_TYPE_1,
    SYSINFO_TYPE_2,
    SYSINFO_TYPE_3,
    SYSINFO_TYPE_4,
    SYSINFO_TYPE_5,
    SYSINFO_TYPE_6,
    SYSINFO_TYPE_7,
    SYSINFO_TYPE_8,
    SYSINFO_TYPE_9,
    SYSINFO_TYPE_10,
    SYSINFO_TYPE_13,
    SYSINFO_TYPE_16,
    SYSINFO_TYPE_17,
    SYSINFO_TYPE_18,
    SYSINFO_TYPE_19,
    SYSINFO_TYPE_20,
    SYSINFO_TYPE_2bis,
    SYSINFO_TYPE_2ter,
    SYSINFO_TYPE_2quater,
    SYSINFO_TYPE_5bis,
    SYSINFO_TYPE_5ter,
    SYSINFO_TYPE_EMO,
    SYSINFO_TYPE_MEAS_INFO,
    MAX_SYSINFO_TYPE
}eSYS_INFO_TYPE;

#endif  //#ifndef _L1_CONSTANTS_H_
