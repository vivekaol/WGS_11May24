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

#ifndef FXLYNXSOCKETINTERFACEAPI_H_
#define FXLYNXSOCKETINTERFACEAPI_H_

#define FXL_SOCKETINTERFACEAPI_VERSION								 4.0960000
#define FXL_MINOR_VERSION 0
#define SIZE_OF_GPSINFO 48
#define SIZE_OF_IDENTITY_STR 16
#define SIZE_OF_TMSI_IDENTITY 4
#define SIZE_OF_CLASSMARK_2   4
#define SIZE_OF_CLASSMARK_3   34
#define MAX_DSP         2
#define MAX_NO_OF_IDS_PER_TRANSACTION 10

#define MAX_NO_TIMESLOTS 8
#define LTE_MAX_BANDS_TO_SCAN 32
#define GSM_MAX_BANDS_TO_SCAN 7

//#define LTE_MAX_NO_PLMNS 6
#define MAX_NO_OF_NEIGHBOUR_CELLS_INTER_IN_SIB5 8 // Max is 8 curtailing to 6
#define MAX_NO_OF_UMTS_NEIGHBOUR_CELLS_IN_SIB6 8

#define MAX_SIZE_OF_SMS 160
#define MAX_NO_OF_NEIGHBOR_ARFCNS 32
#define MAX_NO_OF_HOPPING_ARFCNS  64
#define FXL_2G_MAX_3G_NEIGHBOR_UARFCNS       8
#define FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN  3
#define FXL_2G_MAX_4G_NEIGHBOR_EARFCNS       6
#define FXL_SI_NCELL_LIST_SIZE 96
#define SERVER_PORT_FOR_PRI 4571
#define SERVER_PORT_FOR_SEC 4671
#define FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST    32
#define FXL_UMTS_MAX_INTER_FREQ_CELL_LIST    32
#define FXL_UMTS_MAX_INTER_RAT_CELL_LIST     32
//#define FXL_UMTS_MAX_INTER_RAT_LTE_CELL_LIST 8
#define FXL_MAX_PRIORITY_CELL_LIST           8
#define FXL_UMTS_VALUE_NOT_APPLICABLE        -1
#define FXL_UMTS_MAX_MCC_LEN     3
#define FXL_UMTS_MAX_MNC_LEN     3
#define FXL_UMTS_MAX_USER                 100
#define MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS 16 //8
#define MAX_NO_OF_INTER_FREQ_NEIGHBOR_EARFCNS 8
#define MAX_NO_OF_INTER_RAT_NEIGHBOR_UARFCNS 8
#define MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS 16
#define MAX_NO_ARFCN_FOR_SELECTIVE_SCAN 32
#define MAX_NO_EARFCN_FOR_SELECTIVE_SCAN 32
#define MAX_NO_OF_UARFCN 32
#define MAX_NO_CHANNEL_FOR_SELECTIVE_SCAN 32
#define SI_INVALID_EUTRAN_FREQ 0Xffff
#define E_MAX_PCID_BITMAP 0x3F
#define E_MAX_ALLOWED_PCID_NUM 503
#define SI_MAX_NUM_EUTRAN_FREQ 8
#define FXL_LTE_MAX_NO_PLMNS       6
#define FXL_UMTS_MAX_NO_PLMNS      6
#define MAX_URA_IDENTITY_NUM       1
#define FXL_LTE_MAX_INTER_RAT_GSM_CELL_LIST 2 
#define FXL_LTE_MAX_INTER_RAT_UMTS_CELL_LIST 4
#define FXL_LTE_MAX_INTER_FREQ_CELL_LIST 4
#define FXL_LTE_MAX_INTER_RAT_PSC_PER_UARFCN 4
#define FXL_LTE_MAX_INTER_RAT_GSM_PER_ARFCN 10

#define    FXL_REJ_CAUSE_IMSI_UNKNOWN_IN_HLR                         0x02
#define    FXL_REJ_CAUSE_ILLEGAL_MS                                  0x03
#define    FXL_REJ_CAUSE_IMSI_UNKNOWN_IN_VLR                         0x04
#define    FXL_REJ_CAUSE_IMEI_NOT_ACCEPTED                           0x05
#define    FXL_REJ_CAUSE_ILLEGAL_ME                                  0x06
#define    FXL_REJ_CAUSE_GPRS_SERVICES_NOT_ALLOWED                   0x07
#define    FXL_REJ_CAUSE_GPRS_AND_NONGPRS_SERVICES_NOT_ALLOWED       0x08
#define    FXL_REJ_CAUSE_MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK    0x09
#define    FXL_REJ_CAUSE_IMPLICITLY_DETACHED                         0x0A
#define    FXL_REJ_CAUSE_PLMN_NOT_ALLOWED                            0x0B
#define    FXL_REJ_CAUSE_LA_NOT_ALLOWED                              0x0C
#define    FXL_REJ_CAUSE_ROAMING_NOT_ALLOWED_IN_THIS_LA              0x0D
#define    FXL_REJ_CAUSE_GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN      0x0E
#define    FXL_REJ_CAUSE_NO_SUITABLE_CELLS_IN_LA                     0x0F
#define    FXL_REJ_CAUSE_MSC_TEMPORARILY_NOT_REACHABLE               0x10
#define    FXL_REJ_CAUSE_NETWORK_FAILURE                             0x11
#define    FXL_REJ_CAUSE_MAC_FAILURE                                 0x14
#define    FXL_REJ_CAUSE_SYNCH_FAILURE                               0x15
#define    FXL_REJ_CAUSE_CONGESTION                                  0x16
#define    FXL_REJ_CAUSE_GSM_AUTH_UNACCEPTABLE                       0x17
#define    FXL_REJ_CAUSE_NOT_AUTH_FOR_THIS_CSG                       0x19
#define    FXL_REJ_CAUSE_SERV_OPT_NOT_SUPPORTED                      0x20
#define    FXL_REJ_CAUSE_REQ_SERV_OPT_NOT_SUBSCRIBED                 0x21
#define    FXL_REJ_CAUSE_SERV_OPT_TEMP_OUT_OF_ORDER                  0x22
#define    FXL_REJ_CAUSE_CALL_CANNOT_BE_IDENTIFIED                   0x26
#define    FXL_REJ_CAUSE_NO_PDP_CONTEXT_ACTIVATED                    0x28
#define    FXL_REJ_CAUSE_RETRY_UPON_ENTRY_INTO_NEW_CELL              0x30
#define    FXL_REJ_SEMANTICALLY_INCORRECT_MESSAGE                    0x5F
#define    FXL_REJ_CAUSE_INVALID_MANDATORY_INFO                      0x60
#define    FXL_REJ_CAUSE_MSGTYPE_NONEXISTENT_OR_NOT_IMPLEMENTED      0x61
#define    FXL_REJ_CAUSE_MSGTYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE  0x62
#define    FXL_REJ_CAUSE_INFO_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED 0x63
#define    FXL_REJ_CAUSE_CONDITIONAL_IE_ERROR                        0x64
#define    FXL_REJ_CAUSE_MSG_NOT_COMPATIBLE_WITH_PROTOCOL_STATE      0x65
#define    FXL_REJ_CAUSE_PROTOCOL_ERROR_UNSPECIFIED                  0x6F


typedef enum
{
    // Common Messages starting with 1XX
    FXL_HANDSHAKE_CMD                                       = 101,
    FXL_HANDSHAKE_RSP                                       = 102,
    FXL_CONFIGURE_IDENTITY_LIST_CMD                         = 103,
    FXL_CONFIGURE_IDENTITY_LIST_RSP                         = 104,
    FXL_BOOT_L1_CMD                                         = 105,
    FXL_BOOT_L1_RSP                                         = 106,
    FXL_GET_UE_WITHIN_RANGE_CMD                             = 107,
    FXL_GET_UE_WITHIN_RANGE_RSP                             = 108,
    FXL_LISTEN_MODE_STATUS_IND                              = 109,
    FXL_ENABLE_GPS_CMD                                      = 110,
    FXL_ENABLE_GPS_RSP                                      = 111,
    FXL_GPS_STATUS_IND                                      = 112,
    FXL_STOP_GPS_CMD                                        = 113,
    FXL_STOP_GPS_RSP                                        = 114,
    FXL_RESET_IDENTITY_LIST_CMD                             = 115,
    FXL_RESET_IDENTITY_LIST_RSP                             = 116,
    FXL_DELETE_ENTRY_IN_IDENTITY_LIST_CMD                   = 117,
    FXL_DELETE_ENTRY_IN_IDENTITY_LIST_RSP                   = 118,

    FXL_BL_UE_POWER_OFF_IND                                 = 119,
    FXL_CHANGE_TX_RX_ANTENNA_ID_CMD                         = 120,
    FXL_CHANGE_TX_RX_ANTENNA_ID_RSP                         = 121,
    
    FXL_LISTEN_MODE_RSSI_SCAN_RESULT_IND                    = 122,
    FXL_SYSTEM_STATUS_IND                                   = 123,
	
    FXL_ENABLE_TX_CALIBRATION_CMD                           = 124,
    FXL_ENABLE_TX_CALIBRATION_RSP                           = 125,
        
		
    // 2G Messages starting with 2XX
    FXL_2G_CONFIGURE_IDCATCHER_PARAMS_CMD                   = 201,
    FXL_2G_CONFIGURE_IDCATCHER_PARAMS_RSP                   = 202,
    FXL_2G_START_IDCATCHER_CMD                              = 203,
    FXL_2G_START_IDCATCHER_RSP                              = 204,
    FXL_2G_GET_RSSI_GPS_COORDINATES_CMD                     = 205,
    FXL_2G_GET_RSSI_GPS_COORDINATES_RSP                     = 206,
    FXL_2G_GET_RSSI_GPS_COORDINATES_IND                     = 207,
    FXL_2G_GET_BLOCKED_CALL_COUNTER_CMD                     = 208,
    FXL_2G_GET_BLOCKED_CALL_COUNTER_RSP                     = 209,

    FXL_2G_START_SILENT_CALL_CMD                            = 210,
    FXL_2G_START_SILENT_CALL_RSP                            = 211,
    FXL_2G_MODIFY_UE_TX_POWER_CMD                           = 212,
    FXL_2G_MODIFY_UE_TX_POWER_RSP                           = 213,
    FXL_2G_END_SILENT_CALL_CMD                              = 214,
    FXL_2G_END_SILENT_CALL_RSP                              = 215,

    FXL_2G_SEND_INDIVIDUAL_SMS_CMD                          = 216,
    FXL_2G_SEND_INDIVIDUAL_SMS_RSP                          = 217,
    FXL_2G_SEND_BROADCAST_SMS_CMD                           = 218,
    FXL_2G_SEND_BROADCAST_SMS_RSP                           = 219,

    FXL_2G_REGISTRATION_ATTEMPTED_IND                       = 220,
    FXL_2G_MO_CALL_ATTEMPTED_IND                            = 221,
    FXL_2G_STOP_IDCATCHER_CMD                               = 222,
    FXL_2G_STOP_IDCATCHER_RSP                               = 223,
    FXL_2G_ALERT_BLACKLIST_CMD                              = 224,
    FXL_2G_ALERT_BLACKLIST_RSP                              = 225,
    FXL_2G_AUTO_CONFIG_ARFCN_IND                            = 226,
    FXL_2G_SILENT_CALL_MEAS_IND                             = 227,
    FXL_2G_SILENT_CALL_RESOURCES_IND                        = 228,
    FXL_2G_MO_SMS_ATTEMPTED_IND                             = 229,

    FXL_2G_IDCATCHER_RF_MODIFY_CMD                          = 230,
    FXL_2G_IDCATCHER_RF_MODIFY_RSP                          = 231,
    FXL_2G_BL_USER_DETACHED_IND                             = 232,

    FXL_2G_REDIRECT_TO_2G_CELL_CMD                          = 233,    
    FXL_2G_REDIRECT_TO_2G_CELL_RSP                          = 234,

    FXL_2G_SYS_INFO_MODIFY_CMD                              = 235,
    FXL_2G_SYS_INFO_MODIFY_RSP                              = 236,
    FXL_2G_SET_MO_MSISDN_FOR_TARGET_VOICE_CALL_CMD          = 241,
    FXL_2G_SET_MO_MSISDN_FOR_TARGET_VOICE_CALL_RSP          = 242,
    FXL_2G_REDIRECTION_COMPLETE_IND                         = 243,

    FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_CMD                  = 250,
    FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_RSP                  = 251,
    FXL_2G_LISTEN_MODE_START_SCAN_CMD                       = 252,
    FXL_2G_LISTEN_MODE_START_SCAN_RSP                       = 253,
    FXL_2G_LISTEN_MODE_STOP_SCAN_CMD                        = 254,
    FXL_2G_LISTEN_MODE_STOP_SCAN_RSP                        = 255,
    FXL_2G_LISTEN_MODE_SYSTEM_INFO_IND                      = 256,
    FXL_2G_LISTEN_MODE_SCAN_COMPLETE_IND                    = 257,
    FXL_2G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD  = 258,
    FXL_2G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP  = 259,
    
    FXL_2G_SILENT_CALL_DED_SYS_INFO_MODIFY_CMD              = 260,
    FXL_2G_SILENT_CALL_DED_SYS_INFO_MODIFY_RSP              = 261,

    FXL_2G_EMERGENCY_CALL_ATTEMPTED_IND                     = 265,

    // 3G Messages starting with 3XX
    // 3G ID CATCHER
    FXL_3G_CONFIGURE_IDCATCHER_PARAMS_CMD                   = 301,
    FXL_3G_CONFIGURE_IDCATCHER_PARAMS_RSP                   = 302,
    FXL_3G_START_IDCATCHER_CMD                              = 303,
    FXL_3G_START_IDCATCHER_RSP                              = 304,
    FXL_3G_STOP_IDCATCHER_CMD                               = 305,
    FXL_3G_STOP_IDCATCHER_RSP                               = 306,
    FXL_3G_REGISTRATION_ATTEMPTED_IND                       = 307,
    FXL_3G_AUTO_CONFIG_CMD                                  = 308,
    FXL_3G_AUTO_CONFIG_RSP                                  = 309,
    FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_CMD                  = 310,
    FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_RSP                  = 311,
    FXL_3G_AUTO_CONFIG_STOP_CMD                             = 312,
    FXL_3G_AUTO_CONFIG_STOP_RSP                             = 313,
    FXL_3G_AUTO_CONFIG_UARFCN_IND                           = 314,
    FXL_3G_SYSINFO_CONFIG_CMD                               = 315,
    FXL_3G_SYSINFO_CONFIG_RSP                               = 316,
    FXL_3G_BL_UE_REDIRECT_CMD                               = 317,
    FXL_3G_BL_UE_REDIRECT_RSP                               = 318,
    FXL_3G_START_SILENT_CALL_CMD                            = 321,
    FXL_3G_START_SILENT_CALL_RSP                            = 322,
    FXL_3G_END_SILENT_CALL_CMD                              = 323,
    FXL_3G_END_SILENT_CALL_RSP                              = 324,
    FXL_3G_DED_MEAS_VALUE_IND                               = 325,

    FXL_3G_CHANGE_UE_UL_TX_PWR_CMD                          = 326,
    FXL_3G_CHANGE_UE_UL_TX_PWR_RSP                          = 327,
    FXL_3G_BL_UE_OUT_OF_COVERAGE_IND                        = 328,

    FXL_3G_UE_BASED_GPS_MEAS_IND                            = 329,

    FXL_3G_TX_JAMMER_START_CMD                              = 330,
    FXL_3G_TX_JAMMER_START_RSP                              = 331,
    FXL_3G_TX_JAMMER_STOP_CMD                               = 332,
    FXL_3G_TX_JAMMER_STOP_RSP                               = 333,
    FXL_3G_TX_JAMMER_STATUS_IND                             = 334,

    // 3G Scanner/listen mode
    FXL_3G_LISTEN_MODE_CONFIGURE_BANDS_CMD                  = 350,
    FXL_3G_LISTEN_MODE_CONFIGURE_BANDS_RSP                  = 351,
    FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_CMD                   = 352,
    FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_RSP                   = 353,
    FXL_3G_LISTEN_MODE_SYSTEM_INFO_IND                      = 354,
    FXL_3G_LISTEN_MODE_SCAN_COMP_IND                        = 355,
    FXL_3G_LISTEN_MODE_PRIORITY_SCAN_CMD                    = 356,
    FXL_3G_LISTEN_MODE_PRIORITY_SCAN_RSP                    = 357,

    FXL_3G_EMERGENCY_CALL_ATTEMPTED_IND                     = 380,

    // 4G Messages starting with 4XX
    FXL_4G_CONFIGURE_IDCATCHER_PARAMS_CMD                   = 401,
    FXL_4G_CONFIGURE_IDCATCHER_PARAMS_RSP                   = 402,
    FXL_4G_START_IDCATCHER_CMD                              = 403,
    FXL_4G_START_IDCATCHER_RSP                              = 404,
    FXL_4G_STOP_IDCATCHER_CMD                               = 405,
    FXL_4G_STOP_IDCATCHER_RSP                               = 406,
    FXL_4G_REGISTRATION_ATTEMPTED_IND                       = 407,
    FXL_4G_AUTO_CONFIG_EARFCN_IND                           = 408,
    FXL_4G_START_SILENT_CALL_CMD                            = 409,
    FXL_4G_START_SILENT_CALL_RSP                            = 410,
    FXL_4G_END_SILENT_CALL_CMD                              = 411,
    FXL_4G_END_SILENT_CALL_RSP                              = 412,
    FXL_4G_MEASUREMENT_REPORT_IND                           = 413,
    FXL_4G_IDCATCHER_RF_MODIFY_CMD                          = 414,
    FXL_4G_IDCATCHER_RF_MODIFY_RSP                          = 415,

    FXL_4G_UE_MEASUREMENT_CONFIG_CMD                        = 416,
    FXL_4G_UE_MEASUREMENT_CONFIG_RSP                        = 417,
    FXL_4G_UE_MEASUREMENT_REPORT_IND                        = 418,

    FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_CMD                  = 450,
    FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_RSP                  = 451,
    FXL_4G_LISTEN_MODE_START_SCAN_CMD                       = 452,
    FXL_4G_LISTEN_MODE_START_SCAN_RSP                       = 453,
    FXL_4G_LISTEN_MODE_STOP_SCAN_CMD                        = 454,
    FXL_4G_LISTEN_MODE_STOP_SCAN_RSP                        = 455,
    FXL_4G_LISTEN_MODE_SYSTEM_INFO_IND                      = 456,
    FXL_4G_LISTEN_MODE_SCAN_COMPLETE_IND                    = 457,
    FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD  = 458,
    FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP  = 459,

    FXL_4G_TX_JAMMER_START_CMD                              = 460,
    FXL_4G_TX_JAMMER_START_RSP                              = 461,
    FXL_4G_TX_JAMMER_STOP_CMD                               = 462,
    FXL_4G_TX_JAMMER_STOP_RSP                               = 463,
    FXL_4G_TX_JAMMER_STATUS_IND                             = 464,

    FXL_4G_BL_UE_REDIRECT_CMD                               = 465,
    FXL_4G_BL_UE_REDIRECT_RSP                               = 466,
    FXL_4G_BL_UE_OUT_OF_COVERAGE_IND                        = 470,

    FXL_4G_SYS_INFO_MODIFY_CMD                              = 472,
    FXL_4G_SYS_INFO_MODIFY_RSP                              = 473,



     FXL_4G_BL_USER_RELEASE_CMD                            = 474,
     FXL_4G_BL_USER_RELEASE_RSP                            = 475,

     FXL_4G_NEW_CONFIGURED_TAC_IND                         = 476,
     FXL_4G_MODIFY_EARFCN_CMD                              = 477,
     FXL_4G_MODIFY_EARFCN_RSP                              = 478,

     FXL_4G_CONFIGURE_NEIGHBOR_CMD                         = 479,
     FXL_4G_CONFIGURE_NEIGHBOR_RSP                         = 480,

    FXL_2G_BASS_MODE_CONFIGURE_BANDS_CMD                   = 700,
    FXL_2G_BASS_MODE_CONFIGURE_BANDS_RSP                   = 701,
    FXL_2G_BASS_MODE_START_CMD                             = 702,
    FXL_2G_BASS_MODE_START_RSP                             = 703,
    FXL_2G_BASS_MODE_STOP_CMD                              = 704,
    FXL_2G_BASS_MODE_STOP_RSP                              = 705,
    FXL_2G_BASS_MODE_SYNC_CELL_INFO_IND                    = 706,
    FXL_2G_BASS_MODE_COMPLETE_IND                          = 707,


    /*OBM */
    FXL_OBM_RA_RF_CTRL_CMD                                  = 801,
    FXL_OBM_RA_RF_CTRL_RSP                                  = 802,
    FXL_OBM_BATTERY_STATUS_CMD                              = 803,
    FXL_OBM_BATTERY_STATUS_RSP                              = 804,
    FXL_OBM_SWITCH_OFF_BOARD_CMD                            = 805,
    FXL_OBM_TEMPERATURE_STATUS_CMD                          = 806,
    FXL_OBM_TEMPERATURE_STATUS_RSP                          = 807,
}fxLMsgType_;
typedef int fxLMsgType;

typedef enum{
    FXL_RAT_2G   = 0,
    FXL_RAT_3G   = 1,
    FXL_RAT_4G   = 2,
    FXL_RAT_NONE = 4
}fxLRat_;
typedef int fxLRat;

typedef enum{
    FXL_SUCCESS = 0,
    FXL_FAILURE = 1
}fxLResult_;
typedef int fxLResult;

typedef enum{
    FXL_WHITEUSERSLIST = 0,
    FXL_BLACKUSERSLIST = 1
}fxLListType_;
typedef int fxLListType;

typedef enum{
    FXL_IDENTITY_IMSI = 0,
    FXL_IDENTITY_IMEI = 1
}fxLIdentityType_;
typedef int fxLIdentityType;

/***********************************************************************************/

typedef enum
{
    FXL_CDMA_BAND_0 = 0,
    FXL_CDMA_BAND_1,
    FXL_CDMA_BAND_2,
    FXL_CDMA_BAND_3,
    FXL_CDMA_BAND_4,
    FXL_CDMA_BAND_5,
    FXL_CDMA_BAND_6,
    FXL_CDMA_BAND_7,
    FXL_CDMA_BAND_8,
    FXL_CDMA_BAND_9,
    FXL_CDMA_BAND_10,
    FXL_CDMA_BAND_11,
    FXL_CDMA_BAND_12,
    FXL_CDMA_BAND_13,
    FXL_CDMA_BAND_14,
    FXL_CDMA_BAND_15,
    FXL_CDMA_BAND_16,
    FXL_CDMA_BAND_18,
    FXL_CDMA_BAND_19,
    FXL_CDMA_BAND_20,
    FXL_CDMA_BAND_21,
    FXL_CDMA_MAX_BAND_SUPPORTED
}fxLCdmaBandType_;
typedef int fxLCdmaBandType;

typedef struct
{
    char             identity[SIZE_OF_IDENTITY_STR];
    fxLIdentityType  idType;
    fxLListType      listType;
    int              rejectCauseIfWhitelist;
}fxLIdentityConfig;

typedef enum
{
    FXL_SCAN_TYPE_EXHAUSTIVE,
    FXL_SCAN_TYPE_RSSI
}fxLScanType_;
typedef int fxLScanType;

typedef enum{
    FXL_BAND_GSM_450 = 0,
    FXL_BAND_GSM_850,
    FXL_BAND_GSM_900,
    FXL_BAND_DCS_1800,
    FXL_BAND_PCS_1900,
    FXL_BAND_E_GSM,
    FXL_BAND_R_GSM
}fxL2gBandType_;
typedef int fxL2gBandType;

typedef struct
{
    int           arfcn;
    fxL2gBandType band;
}fxLgsmArfcnBand;

typedef enum{
    FXL_GSM_NO_REDIR = 0,
    FXL_GSM_TEMP_REDIR,
    FXL_GSM_PERM_REDIR
}fxL2gRedirType_;
typedef int fxL2gRedirType;

typedef enum                    /* RF Power Capability  */
{
    CLASS_1 = 0,
    CLASS_2 = 1,
    CLASS_3 = 2,
    CLASS_4 = 3,
    CLASS_5 = 4,
} fxL2gRfPowerCapability_;
typedef int fxL2gRfPowerCapability;

typedef struct
{
    unsigned char          encodedCM2[SIZE_OF_CLASSMARK_2];
    fxL2gRfPowerCapability rfPowerCapability;
    unsigned char          revisionLevel;
    unsigned char          earlyClassmarkSending;
    unsigned char          A5_1AlgorithmSupport;
    unsigned char          A5_2AlgorithmSupport;
    unsigned char          A5_3AlgorithmSupport;
    unsigned char          pseudoSyncCapability;
    unsigned char          ssScreeningIndicator;
    unsigned char          smCapability;
    unsigned char          vbsCapability;
    unsigned char          vgcsCapability;
    unsigned char          freqCapability;
    unsigned char          lcsValCapability;
    unsigned char          ucs2Treatment;
    unsigned char          soLsaSupport;
    unsigned char          cmServicePrompt;
	unsigned char		   dummy1;
}fxL2gMsClassmark;

typedef enum{
    FXL_MEAS_TRIGGER_ONE_SHOT = 0,
    FXL_MEAS_TRIGGER_CONTINUOUS = 1
}fxLMeasTriggerType_;
typedef int fxLMeasTriggerType;

typedef enum{
    FXL_START_CONTINUOUS_TRIGGER = 0,
    FXL_STOP_CONTINUOUS_TRIGGER = 1
}fxLStartStopTrigger_;
typedef int fxLStartStopTrigger;

typedef enum{
    FXL_TCH_SILENT_CALL = 0,
    FXL_SDCCH_SILENT_CALL = 1
}fxLSilentCallPurpose_;
typedef int fxLSilentCallPurpose;

typedef enum{
    FXL_TCH_SILENT_CALL_CELL_BARRED_OFF  = 0,
    FXL_TCH_SILENT_CALL_CELL_BARRED_ON   = 0xEA
}fxLSilentCellBarOption_;
typedef int fxLSilentCellBarOption;


typedef enum{
    FXL_PRIMARY_DSP = 0,
    FXL_SECONDARY_DSP = 1
}fxLDspType_;
typedef int fxLDspType;

typedef enum{
    FXL_L1_GSM_SLS_IMAGE = 0,
    FXL_L1_GSM_NATIVE_IMAGE = 1,
    FXL_L1_UMTS_SLS_IMAGE = 2,
    FXL_L1_UMTS_NATIVE_IMAGE = 3,
    FXL_L1_LTE_SLS_IMAGE = 4,
    FXL_L1_LTE_NATIVE_IMAGE = 5,
    FXL_L1_BASS_IMAGE = 6
}fxLL1ImageType_;
typedef int fxLL1ImageType;

typedef enum
{
    FXL_UMTS_BAND_1 = 0,
    FXL_UMTS_BAND_2,
    FXL_UMTS_BAND_3,
    FXL_UMTS_BAND_4,
    FXL_UMTS_BAND_5,
    FXL_UMTS_BAND_6,
    FXL_UMTS_BAND_7,
    FXL_UMTS_BAND_8,
    FXL_UMTS_BAND_9,
    FXL_UMTS_BAND_10,
    FXL_UMTS_BAND_11,
    FXL_UMTS_BAND_12,
    FXL_UMTS_BAND_13,
    FXL_UMTS_BAND_14,
    FXL_UMTS_BAND_19,
    FXL_UMTS_BAND_20,
    FXL_UMTS_BAND_21,
    FXL_UMTS_BAND_22,
    FXL_UMTS_BAND_25,
    FXL_UMTS_BAND_26,
    FXL_UMTS_ADDITIONAL_BAND_2,
    FXL_UMTS_ADDITIONAL_BAND_4,
    FXL_UMTS_ADDITIONAL_BAND_5,
    FXL_UMTS_ADDITIONAL_BAND_6,
    FXL_UMTS_ADDITIONAL_BAND_7,
    FXL_UMTS_ADDITIONAL_BAND_10,
    FXL_UMTS_ADDITIONAL_BAND_12,
    FXL_UMTS_ADDITIONAL_BAND_13,
    FXL_UMTS_ADDITIONAL_BAND_14,
    FXL_UMTS_ADDITIONAL_BAND_19,
    FXL_UMTS_ADDITIONAL_BAND_25,
    FXL_UMTS_ADDITIONAL_BAND_26,
    FXL_UMTS_MAX_BAND_SUPPORTED
}fxL3gBandType_;
typedef int fxL3gBandType;

typedef enum
{
   FXL_NO_MEAS = 0,
   FXL_RTT_MEAS,
   FXL_RSCP_MEAS,
   FXL_RTT_AND_RSCP_MEAS,
   FXL_GPS_MEAS,
   FXL_RTT_AND_RSCP_AND_GPS_MEAS
}fxL3gMeasType_;
typedef int fxL3gMeasType;

typedef enum{
    FXL_BAND_LTE_1 = 0,
    FXL_BAND_LTE_2 = 1,
    FXL_BAND_LTE_3 = 2,
    FXL_BAND_LTE_4 = 3,
    FXL_BAND_LTE_5 = 4,
    FXL_BAND_LTE_6 = 5,
    FXL_BAND_LTE_7 = 6,
    FXL_BAND_LTE_8 = 7,
    FXL_BAND_LTE_9 = 8,
    FXL_BAND_LTE_10 = 9,
    FXL_BAND_LTE_11 = 10,
    FXL_BAND_LTE_12 = 11,
    FXL_BAND_LTE_13 = 12,
    FXL_BAND_LTE_14 = 13,
    FXL_BAND_LTE_15 = 14,
    FXL_BAND_LTE_16 = 15,
    FXL_BAND_LTE_17 = 16,
    FXL_BAND_LTE_18 = 17,
    FXL_BAND_LTE_19 = 18,
    FXL_BAND_LTE_20 = 19,
    FXL_BAND_LTE_21 = 20,
    FXL_BAND_LTE_22 = 21,
    FXL_BAND_LTE_23 = 22,
    FXL_BAND_LTE_24 = 23,
    FXL_BAND_LTE_25 = 24,
    FXL_BAND_LTE_26 = 25,
    FXL_BAND_LTE_27 = 26,
    FXL_BAND_LTE_28 = 27,
    FXL_BAND_LTE_29 = 28,
    FXL_BAND_LTE_30 = 29,
    FXL_BAND_LTE_31 = 30,
    FXL_BAND_LTE_32 = 31,
    FXL_BAND_LTE_33 = 32,
    FXL_BAND_LTE_34 = 33,
    FXL_BAND_LTE_35 = 34,
    FXL_BAND_LTE_36 = 35,
    FXL_BAND_LTE_37 = 36,
    FXL_BAND_LTE_38 = 37,
    FXL_BAND_LTE_39 = 38,
    FXL_BAND_LTE_40 = 39,
    FXL_BAND_LTE_41 = 40,
    FXL_BAND_LTE_42 = 41,
    FXL_BAND_LTE_43 = 42,
    FXL_BAND_LTE_44 = 43,
    FXL_BAND_LTE_45 = 44,
    FXL_BAND_LTE_46 = 45,
    FXL_BAND_LTE_47 = 46,
    FXL_BAND_LTE_48 = 47,
    FXL_BAND_LTE_50 = 48,
    FXL_BAND_LTE_51 = 49,
    FXL_BAND_LTE_65 = 50,
    FXL_BAND_LTE_66 = 51,
    FXL_BAND_LTE_67 = 52,
    FXL_BAND_LTE_68 = 53,
    FXL_BAND_LTE_69 = 54,
    FXL_BAND_LTE_70 = 55,
    FXL_BAND_LTE_71 = 56,
    FXL_BAND_LTE_72 = 57,
    FXL_BAND_LTE_74 = 58,
    FXL_BAND_LTE_75 = 59,
    FXL_BAND_LTE_76 = 60,
    FXL_BAND_LTE_85 = 61,
    FXL_BAND_LTE_52  = 62
}fxL4gBandType_;
typedef int fxL4gBandType;

typedef enum            /* LTE Downlink Bandwidth */
{
    FXL_LTE_DL_BW_N6,
    FXL_LTE_DL_BW_N15,
    FXL_LTE_DL_BW_N25,
    FXL_LTE_DL_BW_N50,
    FXL_LTE_DL_BW_N75,
    FXL_LTE_DL_BW_N100
} fxL4gDlBw_;
typedef int fxL4gDlBw;

typedef enum            /* PHICH DURATION */
{
    FXL_LTE_PHICH_DURATION_NORMAL,
    FXL_LTE_PHICH_DURATION_EXTENDED
} fxL4gPhichDuration_;
typedef int fxL4gPhichDuration;

typedef enum            /* PHICH RESOURCE */
{
    FXL_LTE_PHICH_RESOURCE_ONSIXTH,
    FXL_LTE_PHICH_RESOURCE_HALF,
    FXL_LTE_PHICH_RESOURCE_ONE,
    FXL_LTE_PHICH_RESOURCE_TWO
} fxL4gPhichResource_;
typedef int fxL4gPhichResource;

typedef enum            /*Redirection From 4G */
{
    NO_REDIRECTION = 0,
    REDIRECTION_TO_2G = 1,
    REDIRECTION_TO_3G = 2,
    REDIRECTION_TO_4G = 3,
    REDIRECTION_TO_CDMA = 4
} fxLRedirectionFrom4g_;
typedef int fxLRedirectionFrom4gType;

typedef enum            /*BandIndicator DCS/PCS  */
{
    DCS1800 = 0,
    PCS1900 = 1
} fxLGsmBandIndicator_;
typedef int fxLGsmBandIndicator;

typedef struct
{
   unsigned int   startingarfcn;
   fxLGsmBandIndicator bandIndicator;
}fxLGsmRedirectInfo;

typedef struct
{       
   unsigned int    startingarfcn;
   fxLCdmaBandType bandIndicator;
   unsigned int    phyCellId;
}fxLCdmaRedirectInfo;

typedef union
{
    fxLGsmRedirectInfo gsmRedirectinfo;
    unsigned int utraFDDUARFCN;
    unsigned int eutraEARFCN;
    fxLCdmaRedirectInfo cdmaRedirectinfo;
}fxLRedirectionFrom4gInfo;

typedef enum            /* Emergency call Serving Cell Type  */
{
    NO_SERVING_CELL = 0,
    SERVING_CELL_2G = 1,
    SERVING_CELL_3G = 2,
    SERVING_CELL_CDMA = 3
} fxLEmegerncyCallServingCell_;
typedef int fxLEmegerncyCallServingCellType;

typedef union
{
    fxLGsmRedirectInfo gsmCellInfo;
    unsigned int utraFDDUARFCN;
    fxLCdmaRedirectInfo cdmaCellInfo;
}fxLEmergencyCallServingCellInfo;

typedef enum
{
    FXL_LTE_IMSI_UNKNOWN_IN_HSS = 2,
    FXL_LTE_ILLEGAL_UE = 3,
    FXL_LTE_IMEI_NOT_ACCEPTED = 5,
    FXL_LTE_ILLEGAL_ME = 6,
    FXL_LTE_EPS_SERVICES_NOT_ALLOWED = 7,
    FXL_LTE_EPS_AND_NONEPS_SERVICES_NOT_ALLOWED =8,
    FXL_LTE_UE_ID_CANNOT_BE_DERVICED_BY_NW =9,
    FXL_LTE_IMPLICIT_DETTACH = 10,
    FXL_LTE_PLMN_NOT_ALLOWED = 11,                        
    FXL_LTE_TRACKING_AREA_NOT_ALLOWED = 12,
    FXL_LTE_ROAMING_NOT_ALLOWED_IN_THIS_TRACKING_AREA = 13,
    FXL_LTE_EPS_SERVICES_NOTALLOWED_INTHIS_PLMN =14,
    FXL_LTE_NO_SUITABLE_CELLS_IN_TRACKING_AREA = 15,
    FXL_LTE_MSC_TEMPORARILY_NOT_REACHABLE = 16 ,   
    FXL_LTE_NETWORK_FAILURE = 17,
    FXL_LTE_CS_DOMAIN_NOT_AVAILABLE = 18,
    FXL_LTE_ESM_FAILURE = 19,
    FXL_LTE_MAC_FAILURE = 20,
    FXL_LTE_SYNCH_FAILURE = 21,
    FXL_LTE_CONGESTION = 22,
    FXL_LTE_UE_CAPABAILITIES_MISMATCH = 23,
    FXL_LTE_SECURITYMODE_REJECT_UNSPECIFIED = 24,
    FXL_LTE_NOT_AUTHORIZED_FOR_CSG = 25,
    FXL_LTE_NONEPS_AUTHENTICATION_UNACCEPTABLE = 26,
    FXL_LTE_CS_DOMAIN_TEMP_NOT_AVAILABLE = 39,
    FXL_LTE_NO_EPS_BEARER_ACTIVATED = 40,
    FXL_LTE_SEMANTICALLY_INCORRECT_MESSAGE = 95,
    FXL_LTE_INVALID_MANDATORY_INFORMATION = 96,
    FXL_LTE_MSGTYPE_NONEXISTENT_OR_NOT_IMPLEMENETED = 97,
    FXL_LTE_MSGTYPE_NOTCOMPATIABLE_WITH_PROTOCOL_STATE = 98,
    FXL_LTE_INFO_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED = 99,
    FXL_LTE_CODNITIONAL_IE_ERROR = 100,
    FXL_LTE_MSG_NOTCOMPATIABLE_WITH_PROTOCOL_STATE = 101,
    FXL_LTE_PROTOCOL_ERROR_UNSPECIFIED = 111,
}fxl4gWlRejectCause;    

typedef enum            /* OBM PA on/off */
{
    FXL_OBM_RA_OFF = 0,
    FXL_OBM_RA_STAGE3_ON = 3,
} fxLObmRaVal_;
typedef int fxLObmRaVal;

typedef struct
{
    unsigned int mccLength;
    unsigned int mcc[FXL_UMTS_MAX_MCC_LEN];
    unsigned int mncLength;
    unsigned int mnc[FXL_UMTS_MAX_MNC_LEN];
}fxL3gPlmn;

typedef struct
{
    float latitude;
    float longitude;
    int   altitude;
}fxLGpsLocation;

typedef enum
{
    FXL_GPS_FIX_NONE,
    FXL_GPS_FIX_2D,
    FXL_GPS_FIX_3D
}fxLGpsFixType;

typedef enum
{
   FXL_UE_POS_ERR_NOT_ENOUGH_OTDOA_CELLS,
   FXL_UE_POS_ERR_NOT_ENOUGH_GPS_SATELLITE,
   FXL_UE_POS_ERR_ASSISTANCE_DATA_MISSING,
   FXL_UE_POS_ERR_NOT_ACCOMPLISHED_GPS,
   FXL_UE_POS_ERR_UNDEFINED,
   FXL_UE_POS_ERR_REQ_DENIED_BY_USER,
   FXL_UE_POS_ERR_NOT_PROCESSED_TIMEOUT,
   FXL_UE_POS_ERR_REF_CELL_NOT_SERVING_CELL,
   FXL_UE_POS_ERR_METHOD_NOT_SUPPORTED,
   FXL_UE_POS_ERR_NONE,
}fxlUePositioningError;

typedef struct
{
    fxLGpsFixType  gpsFixType;
    fxLGpsLocation gpsLocation;
}fxlUePositioningInfo;

typedef struct
{
    int        msgLength;
    fxLMsgType msgType;
    fxLRat     rat;
}fxLHeader;

/***********************************************************************************/
//Command from External Client for Initial Handshake.
#define FEATURE_SCANNER 0x01
#define FEATURE_2G_IDCATCHER ((0x01) <<1)
#define FEATURE_3G_IDCATCHER ((0x01) <<2)
#define FEATURE_4G_FDD_IDCATCHER ((0x01) <<3)
#define FEATURE_4G_TDD_IDCATCHER ((0x01) <<4)

typedef struct
{
    fxLHeader hdr;
    float     clientSocketApiVersion;
}fxLHandShakeCmd; //FXL_HANDSHAKE_CMD

typedef struct
{
	fxLHeader hdr;
	float ServerSocketApiVersion;
	fxLResult result;
	int   FeatureEnabled;
	int   minorVersion;
}fxLHandShakeRsp ;//FXL_HANDSHAKE_RSP
/***********************************************************************************/

/***********************************************************************************/
//Command from External Client to load the L1 image on primary and secondary dsp
// This can be 2G and 3G Listen mode and 2G and 3G S/W.
typedef struct
{
    fxLHeader      hdr;
    fxLDspType     dspType;
    fxLL1ImageType l1ImageType;
}fxLBootL1Cmd; //FXL_BOOT_L1_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxLBootL1Rsp ;//FXL_BOOT_L1_RSP

/***********************************************************************************/
//Command from External Client to change Tx Rx Antenna Id in 2G/3G/4G
typedef enum
{
   FXL_TX_RX_ANTENNA_ID_0,
   FXL_TX_RX_ANTENNA_ID_1
}fxLTxRxAntennaId;

typedef struct
{
    fxLHeader        hdr;
    fxLDspType       dspType;
	fxLTxRxAntennaId txAntennaId;
	fxLTxRxAntennaId rxAntennaId; 
}fxLChangeTxRxAntennaIdCmd; //FXL_CHANGE_TX_RX_ANTENNA_ID_CMD

typedef struct
{
    fxLHeader    hdr;
    fxLResult    result;
}fxLChangeTxRxAntennaIdRsp; //FXL_CHANGE_TX_RX_ANTENNA_ID_RSP

/***********************************************************************************/
//Command from External Client to get number of UEs within range for 2G/3G/4G
typedef struct
{
    fxLHeader hdr;
}fxLGetUeWithinRangeCmd ; //FXL_GET_UE_WITHIN_RANGE_CMD

typedef struct
{
    fxLHeader    hdr;
    fxLResult    result;
    unsigned int numOfUe;
}fxLGetUeWithinRangeRsp; //FXL_GET_UE_WITHIN_RANGE_RSP

typedef struct
{
    fxLHeader hdr;
    unsigned int numFreqScanned;
    unsigned int totalFreqtoScan;
    char         bandString[20];
}fxLlistenModeStatusInd; //FXL_LISTEN_MODE_STATUS_IND

typedef enum
{
   FXL_ERROR,
   FXL_STARTED,
   FXL_RUNNING
}fxLSystemCurrentState;

typedef enum
{
   FXL_2G_IDC,
   FXL_3G_IDC,
   FXL_4G_IDC
}fxLCurrentTask;

typedef struct
{
    fxLHeader hdr;
    fxLCurrentTask        runningTask;
    fxLSystemCurrentState status;
}fxLSystemStatusInd; // FXL_SYSTEM_STATUS_IND

#define MAX_NUMBER_OF_CHANNELS_PER_BAND   2000
/***********************************************************************************/
//Indication from WGS to provide RSSI of each channel  for 2G/3G/4G
typedef struct
{
   int    channelNum;
   float  rssi;
}fxLChannelInfo;

typedef struct
{
    fxLHeader       hdr;
    fxL2gBandType   band2g;
    fxL3gBandType   band3g;
    fxL4gBandType   band4g;
    int             numOfChannels;
    fxLChannelInfo  channelInfo[MAX_NUMBER_OF_CHANNELS_PER_BAND];
}fxLListenModeRssiScanResultInd; //FXL_LISTEN_MODE_RSSI_SCAN_RESULT_IND

typedef struct
{
    fxLHeader         hdr;
}fxLEnableTxCalibrationCmd ;//FXL_ENABLE_TX_CALIBRATION_CMD

typedef enum
{
    FXL_CELL_NOT_BRING_UP         = 0,
    FXL_FAILURE_FROM_L1           = 1,
    FXL_HW_NOT_SUPPORTED          = 2
}fxlTxCalibrationFailureCause;

typedef struct
{
    fxLHeader    hdr;
    fxLResult    result;
    fxlTxCalibrationFailureCause failureCause;
} fxLEnableTxCalibrationRsp; //FXL_ENABLE_TX_CALIBRATION_RSP


/***********************************************************************************/


/***********************************************************************************/
//Command from External Client to configure identity lists. 10 Ids per transaction allowed.
typedef struct
{
    fxLHeader         hdr;
    fxLListType       defaultListConfig;
    int               noOfEntries;
    fxLIdentityConfig configList[MAX_NO_OF_IDS_PER_TRANSACTION];    
    //fxLListAction   actionOnList;
}fxLConfigureIdentityListCmd ;//FXL_CONFIGURE_IDENTITY_LIST_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxLConfigureIdentityListRsp ;//FXL_CONFIGURE_IDENTITY_LIST_RSP
typedef struct
{
    fxLHeader        hdr;
    fxLIdentityType  idType;    
    char             identity[SIZE_OF_IDENTITY_STR];
}fxLDeleteEntryInIdentityListCmd ;//FXL_DELETE_ENTRY_IN_IDENTITY_LIST_CMD
typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxLDeleteEntryInIdentityListRsp ;//FXL_DELETE_ENTRY_IN_IDENTITY_LIST_RSP
typedef struct
{
    fxLHeader hdr;
}fxLResetIdentityListCmd ; //FXL_RESET_IDENTITY_LIST_CMD
typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxLResetIdentityListRsp ;//FXL_RESET_IDENTITY_LIST_RSP

/***********************************************************************************/
//Command to External Client to Indicate a BL UE Power off indication 

typedef enum
{
    FXL_POWER_OFF                = 0,
    FXL_RL_FAILURE               = 1, /* Redundant Cause, not used anymore */
    FXL_UE_OUT_OF_RANGE          = 2,
    FXL_ID_CONFIG_CHANGED        = 3,
    FXL_REDIRECTED_TO_OTHER_CELL = 4
}fxlBlUeDeatchCause;

typedef struct
{
    fxLHeader           hdr;
    char                imsiStr[SIZE_OF_IDENTITY_STR];
    fxlBlUeDeatchCause  detachCause;
}fxLBlUePowerOffInd; //FXL_BL_UE_POWER_OFF_IND


/***********************************************************************************/
//Command from External Client to configure base-station parameters
typedef fxL3gPlmn fxL2gPlmn;
typedef struct
{
    fxLHeader          hdr;
    fxL2gPlmn          plmn;
    int                Lac;
    int                Ci;
    fxL2gBandType      Band;
    int                Arfcn;
    int                ncc; // BSIC(6 bits) = NCC(3 bits) + BCC(3 bits)
    int                bcc;
    int                AutoConfigureEnabled; // TRUE-yes , FALSE-no, When set to TRUE , BS will choose ARFCN and LAC based on Listen Mode data.
    int                RxGainInDb;  // Range is 0 to 73 . Default Gain is 70dB.
    int                TxAttenuationInDb; // Range is 0 to 89 (increment in 1 dB) . Default Attenuation is 0.
    unsigned int       changeWLDefaultRejectCause;
    unsigned int       defaultWLRejectCause;
    unsigned int       timingAdvanceFilter; 
	int                emergencyredirNcc; // BSIC(6 bits) = NCC(3 bits) + BCC(3 bits)
	int                emergencyredirBcc;
	int                emergengyredirectenable;
	fxLGsmRedirectInfo emergencyRedirectinfo;  
}fxL2gConfigureIdCatcherParamsCmd ;//FXL_2G_CONFIGURE_IDCATCHER_PARAMS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gConfigureIdCatcherParamsRsp ;//FXL_2G_CONFIGURE_IDCATCHER_PARAMS_RSP



typedef struct
{
    fxLHeader      hdr;
    unsigned int   arfcn;
    fxL2gBandType  band;
    unsigned int   ncc;
    unsigned int   bcc;
    unsigned int   lac;
    unsigned int   cellId;
}fxL2gAutoConfigArfcnInd ;//FXL_2G_AUTO_CONFIG_ARFCN_IND

/***********************************************************************************/
//Command from External Client to start Base-Station.
typedef struct
{
    fxLHeader hdr;
}fxL2gStartIdCatcherCmd ;//FXL_2G_START_IDCATCHER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gStartIdCatcherRsp ;//FXL_2G_START_IDCATCHER_RSP

/***********************************************************************************/
//Command from External Client to change RF Parameters of Base-Station.
typedef struct
{
    fxLHeader hdr;    
    int       TxAttenuationInDb; // Range is 0 to 359 (increment in 1/4dB) . Default Attenuation is 0.
}fxL2gIdCatcherRfModifyCmd ;//FXL_2G_IDCATCHER_RF_MODIFY_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gIdCatcherRfModifyRsp ;//FXL_2G_IDCATCHER_RF_MODIFY_RSP

/***********************************************************************************/
//Command from External Client to get Rssi and Gps Co-ordinates from UE.
typedef struct
{
    fxLHeader           hdr;
    int                 ueIndex;
    char                imsiStr[SIZE_OF_IDENTITY_STR];
    fxLMeasTriggerType  measTriggerType;
    fxLStartStopTrigger startStopTrigger;
}fxL2gGetRssiGpsCoordinatesCmd ;//FXL_2G_GET_RSSI_GPS_COORDINATES_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char  imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gGetRssiGpsCoordinatesRsp ;//FXL_2G_GET_RSSI_GPS_COORDINATES_RSP

typedef struct
{
    fxLHeader              hdr;
    char                   imsiStr[SIZE_OF_IDENTITY_STR];
    float                  rssi;
    fxlUePositioningError  errorCode;
    fxlUePositioningInfo   uePosInfo;
}fxL2gGetRssiGpsCoordinatesInd ;//FXL_2G_GET_RSSI_GPS_COORDINATES_IND

/***********************************************************************************/
//Command from External Client to get Mo call blocked call counter/numbers
typedef struct
{
    fxLHeader hdr;
    int       ueIndex;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gGetBlockedCallCounterCmd ;//FXL_2G_GET_BLOCKED_CALL_COUNTER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    int       blockedCallCounter;
}fxL2gGetBlockedCallCounterRsp ;//FXL_2G_GET_BLOCKED_CALL_COUNTER_RSP
/***********************************************************************************/
typedef struct
{
    fxLHeader hdr;
    int       dspResetNeeded;
}fxL2gStopIdCatcherCmd ;//FXL_2G_STOP_IDCATCHER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gStopIdCatcherRsp ;//FXL_2G_STOP_IDCATCHER_RSP

/***********************************************************************************/
//Command from External Client to start Silent call to increase or decrease Tx Power of Ue
typedef struct
{
    fxLHeader            hdr;
    int                  ueIndex;
    fxLSilentCallPurpose purpose;
    char                 imsiStr[SIZE_OF_IDENTITY_STR];    
    fxLSilentCellBarOption cellBarOption;
}fxL2gStartSilentCallCmd ;//FXL_2G_START_SILENT_CALL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gStartSilentCallRsp ;//FXL_2G_START_SILENT_CALL_RSP

typedef struct
{
    /*
     * RXLEV   0   =   less than -110 dBm.
     * RXLEV   1   =   -110 dBm to -109 dBm
     * RXLEV   2   =   -109 dBm to -108 dBm
                        :
                        :
     * RXLEV   62  =   -49 dBm  to -48 dBm
     * RXLEV   63  =   greater than -48 dBm.
     */
        int           arfcn;
        unsigned char bsic;
        unsigned char rxlev_Rssi;
		unsigned char dummy1;
		unsigned char dummy2;
}fxLGsmMeasRes2gNeigh;

typedef struct
{
    /* 3GPP TS 45008:8.1.5 - UTRAN Measurement quantity *
     * 
     * RSCP:
     *
     *     rxlev_Rscp_ecNo = 0;  --> " -116 dBm <= RSCP < -115 dBm"
     *     rxlev_Rscp_ecNo = 1;  --> " -115 dBm <= RSCP < -114 dBm"
     *     .
     *     .
     *     rxlev_Rscp_ecNo = 63; --> " -53 dBm  <= RSCP < -52 dBm"
     *
     * Ec/No:
     *
     *     rxlev_Rscp_ecNo = 0;  -->  " -24   dB >  CPICH Ec/Io"
     *     rxlev_Rscp_ecNo = 1;  -->  " -24   dB <= CPICH Ec/Io < -23.5 dB"
     *     rxlev_Rscp_ecNo = 2;  -->  " -23.5 dB <= CPICH Ec/Io < -23   dB"
     *     .
     *     .
     *     rxlev_Rscp_ecNo = 48; --> " -0.5 dB   <= CPICH Ec/Io < 0 dB"
     *     rxlev_Rscp_ecNo = 49; --> "  0   dB   <  CPICH Ec/Io"
     */
        int            uarfcn;
        int            psc;
        unsigned char  rxlev_Rscp_ecNo;		
		unsigned char dummy1;
		unsigned char dummy2;
		unsigned char dummy3;
}fxLGsmMeasRes3gNeigh;

typedef struct
{
    /* 3GPP TS 45008:8.1.5 - EUTRAN Measurement quantity : 3 Bit Reporting *
     *
     *    Offset = E UTRAN_FDD_MEASUREMENT_REPORT_OFFSET/E UTRAN_TDD_MEASUREMENT_REPORT_OFFSET
     *             0 = -140 dBm, 1 = -139 dBm, 2 = -138 dBm, <85>, 62 = -78 dBm, 63 = -77 dBm.
     *
     *    Step   = REPORTING_GRANULARITY
     *             0 = 2 dB step size, 1 = 3 dB step size
     *
     *    
     *      rxlev_Rsrp_Rsrq  = 0   -->   Offset                  to  Offset + Step
     *      rxlev_Rsrp_Rsrq  = 1   -->   Offset  + Step          to  Offset + 2 * Step
     *      rxlev_Rsrp_Rsrq  = 2   -->   Offset  + 2 * Step      to  Offset + 3 * Step
     *      rxlev_Rsrp_Rsrq  = 3   -->   Offset  + 3 * Step      to  Offset + 4 * Step
     *      rxlev_Rsrp_Rsrq  = 4   -->   Offset  + 4 * Step      to  Offset + 5 * Step
     *      rxlev_Rsrp_Rsrq  = 5   -->   Offset  + 5 * Step      to  Offset + 6 * Step
     *      rxlev_Rsrp_Rsrq  = 6   -->   Offset  + 6 * Step      to  Offset + 7 * Step
     *      rxlev_Rsrp_Rsrq  = 7   -->   greater than or equal   to  Offset + 7 * Step
     *
     *    Default Values: Offset = 40(-100 dBm), Step = 0(2 dB step size)
     */
        int            earfcn;
        int            pcid;
        unsigned char  rxlev_Rsrp_Rsrq;		
		unsigned char dummy1;
		unsigned char dummy2;
		unsigned char dummy3;
}fxLGsmMeasRes4gNeigh;


typedef struct
{
    fxLRat measRatType;
    union
    {
        fxLGsmMeasRes2gNeigh gsmNeighCell;
        fxLGsmMeasRes3gNeigh umtsNeighCell;
        fxLGsmMeasRes4gNeigh lteNeighCell;
    }u;
}fxLGsmMeasRes;

typedef struct
{
    int            msPowerUsed;
    unsigned char  timingAdvance;
    unsigned char  timingAdvanceQbits;
    unsigned char  baUsed;
    unsigned char  ulDtxUsed;
    unsigned char  dlRxLevFull;
    unsigned char  dlRxLevSub;
    unsigned char  dlRxQualFull;
    unsigned char  dlRxQualSub;
    unsigned char  ulRxQualFull;
    unsigned char  ulRxLevFull;
    unsigned char  measValid;
    unsigned char  numOfCellsMeasured;
    fxLGsmMeasRes  neigh[6];
}fxLGsmMeasReport;

typedef struct
{
    fxLHeader        hdr;
    char             imsiStr[SIZE_OF_IDENTITY_STR];
    float            rssidBm;
    float            snrdB;   
    fxLGsmMeasReport measReport; 	
}fxL2gSilentCallMeasInd ;//FXL_2G_SILENT_CALL_MEAS_IND

typedef struct
{
    fxLHeader            hdr;
    char                 imsiStr[SIZE_OF_IDENTITY_STR];
    fxLSilentCallPurpose purpose;
    unsigned char        tsc;
    unsigned char        timeSlot;
    unsigned char        subChannel;	
	unsigned char 		 dummy1;
}fxL2gSilentCallResourcesInd ;//FXL_2G_SILENT_CALL_RESOURCES_IND

typedef struct
{
    int           arfcnNeighbors[MAX_NO_OF_NEIGHBOR_ARFCNS];
    int			  noOfNeighbors;
}fxLSi5Info;

typedef struct
{
    int cellId;
    int lac;
}fxLSi6Info;


/***********************************************************************************/
//Command from External Client to change Tx Power
typedef struct
{
    fxLHeader hdr;
    int       ueIndex;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    int       newPowerLeveldBm;
}fxL2gModifyUeTxPowerCmd ;//FXL_2G_MODIFY_UE_TX_POWER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gModifyUeTxPowerRsp ;//FXL_2G_MODIFY_UE_TX_POWER_RSP
/***********************************************************************************/
//Command from External Client to end silent call
typedef struct
{
    fxLHeader hdr;
    int       ueIndex;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gEndSilentCallCmd ;//FXL_2G_END_SILENT_CALL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gEndSilentCallRsp ;//FXL_2G_END_SILENT_CALL_RSP

/***********************************************************************************/
//Command from External Client to send Sms to individual UE.
typedef struct
{
    fxLHeader hdr;
    int       ueIndex;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    char      moMsisdnNoStr[SIZE_OF_IDENTITY_STR];
    char      smsMessage[MAX_SIZE_OF_SMS];
}fxL2gSendIndividualSmsCmd ;//FXL_2G_SEND_INDIVIDUAL_SMS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gSendIndividualSmsRsp ;//FXL_2G_SEND_INDIVIDUAL_SMS_RSP
/***********************************************************************************/
//Command from External Client to send Sms to all blacklisted registered UEs.
typedef struct
{
    fxLHeader hdr;
    char      smsMessage[MAX_SIZE_OF_SMS];  
    char      moMsisdnNoStr[SIZE_OF_IDENTITY_STR];
}fxL2gSendBroadcastSmsCmd ;//FXL_2G_SEND_BROADCAST_SMS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gSendBroadcastSmsRsp ;//FXL_2G_SEND_BROADCAST_SMS_RSP

typedef struct
{    
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    int       ncc; // BSIC(6 bits) = NCC(3 bits) + BCC(3 bits)
    int       bcc;
    fxLGsmRedirectInfo gsmRedirectinfo;
}fxL2gRedirectTo2gCellCmd ; //FXL_2G_REDIRECT_TO_2G_CELL_CMD

typedef struct
{    
    fxLHeader hdr;    
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gRedirectTo2gCellRsp ; //FXL_2G_REDIRECT_TO_2G_CELL_RSP

/***********************************************************************************
 ** Unsolicited / Asynchronous Indication to External Client to indicate the 
 ** Redirection command is sent to the UE */
typedef struct
{
    fxLHeader hdr;    
    char      imsiStr[SIZE_OF_IDENTITY_STR]; // To Identify UE.
}fxL2gRedirectionCompleteInd ;/* FXL_2G_REDIRECTION_COMPLETE_IND */
/***********************************************************************************/

/***********************************************************************************/
//Unsolicited / Asynchronous Indication to External Client to update the registration attempt of UE.

typedef struct
{
    unsigned char     timingAdvance;
    unsigned char     timingAdvanceQbits;
    unsigned char     dlRxLevFull;
    unsigned char     dlRxLevSub;
    unsigned char     dlRxQualFull;
    unsigned char     dlRxQualSub;	
    unsigned char     dummy1;
    unsigned char     dummy2;
}fxLGsmiInitialDlMeasReport;

typedef struct
{
    fxLHeader        hdr;
    char             imsiStr[SIZE_OF_IDENTITY_STR];
    char             imeiStr[SIZE_OF_IDENTITY_STR];
    char             tmsi[SIZE_OF_TMSI_IDENTITY];
    fxLListType      listType;
    float            rssidBm;
    float            snrdB;
    unsigned int     timingAdvance;
    fxL2gMsClassmark msClassmark;
	unsigned int     imeiSv;
    unsigned int     last_lac;
    
}fxL2gRegistrationAttemptedInd ;//FXL_2G_REGISTRATION_ATTEMPTED_IND

typedef struct
{
    fxLHeader        hdr;
    char             imsiStr[SIZE_OF_IDENTITY_STR];
    char             imeiStr[SIZE_OF_IDENTITY_STR];
}fxLGsmEmergencyCallAttmpInd;
/***********************************************************************************/
//Unsolicited / Asynchronous Indication to External Client to update detach Ind of the registered UE.
typedef struct
{
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gBlUserDetachedInd ;//FXL_2G_BL_USER_DETACHED_IND

/***********************************************************************************
 * Unsolicited / Asynchronous Indication to External Client to update MSISDN of the
 * dialed no. by registered UE.
 */
typedef struct
{
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    char      msisdnOfDialedNoStr[SIZE_OF_IDENTITY_STR];
    int       blockedCallCounter;
}fxL2gCallAttemptedInd ;//FXL_2G_MO_CALL_ATTEMPTED_IND
/***********************************************************************************/
typedef struct
{
   unsigned char isConcatenatedMsg;
   unsigned char messageRefNo;
   unsigned char messageTotalNoOfParts;
   unsigned char messagePartNumber;
   char          smsMessage[MAX_SIZE_OF_SMS];
}fxL2gMoSms;

/* Unsolicited/Asynchronous Indication to External Client to update MSISDN of the
 * recipient no. by registered UE.
 */
typedef struct
{
    fxLHeader  hdr;
    char       imsiStr[SIZE_OF_IDENTITY_STR];
    char       msMsisdnOfRecipientNoStr[SIZE_OF_IDENTITY_STR];
    fxL2gMoSms moSms;
}fxL2gMoSmsAttemptedInd ;//FXL_2G_MO_SMS_ATTEMPTED_IND

typedef struct
{   
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gStartAlertBlacklistRsp ;//FXL_2G_ALERT_BLACKLIST_RSP

typedef struct
{
    fxLHeader hdr;
    int       ueIndex;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    char      callingPartyIsdnStr[SIZE_OF_IDENTITY_STR];
}fxL2gStartAlertBlacklistCmd;//FXL_2G_ALERT_BLACKLIST_CMD

/***********************************************************************************/
/* Command from External Client to set MO-MSISDN for Target Voice Call */
typedef struct
{
    fxLHeader hdr;
    int       ueIndex;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    char      moMsIsdnStr[SIZE_OF_IDENTITY_STR];
}fxL2gSetMoMsisdnForTargetVoiceCallCmd;//FXL_2G_SET_MO_MSISDN_FOR_TARGET_VOICE_CALL_CMD

typedef struct
{   
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gSetMoMsisdnForTargetVoiceCallRsp ;//FXL_2G_SET_MO_MSISDN_FOR_TARGET_VOICE_CALL_RSP

/***********************************************************************************/


/***********************************************************************************
 * Command from External Client to configure Bands for scanning in Listen Mode */
typedef struct
{
    fxLHeader     hdr;
    int           noOfScanIterations;
    int           noOfBandsToScan;
    fxL2gBandType band[GSM_MAX_BANDS_TO_SCAN]; // Maximum bands can be scan as 7
}fxL2gListenModeConfigureBandsCmd ;//FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gListenModeConfigureBandsRsp ;//FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_RSP
/***********************************************************************************
 * Command from External Client to start scanning in Listen Mode. */
typedef struct
{
    fxLHeader   hdr;
    fxLScanType scanType;
}fxL2gListenModeStartScanCmd ;//FXL_2G_LISTEN_MODE_START_SCAN_CMD

//Command from External Client to stop scanning in Listen Mode.
typedef struct
{
    fxLHeader hdr;
    int       dspResetNeeded;
}fxL2gListenModeStopScanCmd ;//FXL_2G_LISTEN_MODE_STOP_SCAN_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gListenModeStartScanRsp ;//FXL_2G_LISTEN_MODE_START_SCAN_RSP

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gListenModeStopScanRsp ;//FXL_2G_LISTEN_MODE_STOP_SCAN_RSP
typedef struct
{
    int uarfcn;
    int psc;
    int utranQrxlevminDbm;
    int utranPriority;
    int threshUtranHighDb;
    int threshUtranLowDb;
    int diversityApplied;
}fxLUmtsFddCell ;

typedef struct
{
    int noNeighUmtsCells;
    int priorityParamsPresent;
    fxLUmtsFddCell neighFddCell[FXL_SI_NCELL_LIST_SIZE];
    //fxLUmtsTddCell neighTddCell[FXL_SI_NCELL_LIST_SIZE];
}fxLUmtsNeighborInfo ;

typedef struct
{
    int fddQoffset;
    int fddRepQuant;
    int fddMultiratReporting;
    int fddQmin;
} fddParamsStruct;

typedef struct
{
    int qSearchI;
    int qSearchCInit;
    int fddParamsPresent;
    fddParamsStruct fddParams;   
}fxLUmtsMeasParams ;

typedef struct
{
    int geranPriority;
    int threshPrioSearch;
    int threshGsmLow;
    int hPrio;
    int tReselection;
    int scellPrioParamsPresent;
} fxLServCellPrioParams;


typedef struct
{
    int   eutranPriority;
    int   threshEutranHighDb;
    int   threshEutranLowDb;
    int   eutranQrxlevminDbm;
}fxLLtePriorityInfo ;

typedef struct
{
    int earfcn;
    int eutranPcidBitmap[E_MAX_PCID_BITMAP];
    int eutranMeasBwNrb;
    fxLLtePriorityInfo eutranPriorityInfo;
}fxLLteFreq ;

typedef struct
{
    int noEutranFreqs;
    fxLLteFreq eutranFreq[SI_MAX_NUM_EUTRAN_FREQ];
}fxLLteNeighborInfo ;

typedef struct
{
    fxLServCellPrioParams   servCellPrioParams;
    fxLUmtsMeasParams       umtsMeasParams;
    fxLUmtsNeighborInfo     umtsNeighbors;
    fxLLteNeighborInfo      lteNeighbors;
}fxLSi2qInfo ;


typedef struct
{
    int priorityParamsPresent;
    int utranQrxlevminDbm;
    int utranPriority;
    int threshUtranDb;
}fxLUmtsPrioParams;

typedef struct
{
    int psc;
    int diversityApplied;
}fxL3gFddCellInfo;

typedef struct
{
    int              uarfcn;
    int              noOfCells;
    fxL3gFddCellInfo neighFddCell[FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN];
}fxLFddUarfcnInfo;

typedef struct
{
    int               noOfFddUarfcns;
    fxLFddUarfcnInfo  neighFddUarfcn[FXL_2G_MAX_3G_NEIGHBOR_UARFCNS];
}fxL3gNeighborInfo;

typedef struct
{
    int                earfcn;
    int                eutranMeasBwNrb;
    fxLLtePriorityInfo eutranPriorityInfo;
}fxL4gNeighFreq;

typedef struct
{
    int            noEutranFreqs;
    fxL4gNeighFreq eutranFreq[FXL_2G_MAX_4G_NEIGHBOR_EARFCNS];
}fxL4gNeighborInfo;

typedef struct
{
    fxLServCellPrioParams servCellPrioParams;
    fxLUmtsMeasParams     umtsMeasParams;
    fxLUmtsPrioParams     umtsDefaultPrioParams;
    fxL3gNeighborInfo     umtsNeighbors;
    fxL4gNeighborInfo     lteNeighbors;
}fxL2gInterRatInfo;

typedef struct
{
    fxLHeader hdr;
    // -1 value for any of these parameters indicates it is unchanged.
    int cellIdentity;
    int lac;
    int rxlevAccMin;    
    int cellReselHyst;
    int msTxpwrMaxCcch;
    int cbq;
    int cro;
    int tempOffset;
    int penaltyTime;
    int noOfNeighbors;
    int arfcnNeighbors[MAX_NO_OF_NEIGHBOR_ARFCNS];
    int t3212;
    int noOfHoppingNeighbors;
    int hoppingArfcnNeighbors[MAX_NO_OF_HOPPING_ARFCNS];
    int accessClassList;
    int interRatInfoPresent;
    fxL2gInterRatInfo interRatInfo;
    int nmo;
    int rac;
    int cellBarred;
}fxL2gSysInfoModifyCmd; //FXL_2G_SYS_INFO_MODIFY_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gSysInfoModifyRsp ;//FXL_2G_SYS_INFO_MODIFY_RSP

typedef struct
{
   /*
    * qSearchC: ( Range : 0 - 15)
    *   Search for 3G cells if signal level below threshold (0-7): 
    *   - 98, - 94, <85> , - 74 dBm,(always) 
    *   or above threshold (8-15):
    *   - 78, - 74, <85> , - 54 dBm,(never)
    *
    * fddRepQuant: (Range : 0 - 1)
    *   Indicates the reporting quantity for UTRAN FDD cells,
    *   0 = RSCP, 1 = Ec/No
    *
    * fddMultiratReporting:(Range : 0 -3)
    *   The number of 3G FDD cells (one or more) that shall be included 
    *   in the measurement report.
    * 
    */
    int  qSearchC;
    int  fddRepQuant;
    int  fddMultiratReporting;
}fxL2gMIUmtsMeasParams;

typedef struct
{
   /*
    * qSearchC_Eutran: ( Range : 0 - 15)
    *   Search for E-UTRAN cells if signal level below threshold (0-7): 
    *   - 98, - 94, <85> , - 74 dBm,(always) 
    *   or above threshold (8-15):
    *   - 78, - 74, <85> , - 54 dBm,(never)
    *
    * eutranRepQuant: (Range : 0 - 1)
    *   Indicates the reporting quantity for E-UTRAN cells,
    *   0 = RSRP, 1 = RSRQ
    *
    * eutranMultiratReporting:(Range : 0 -3)
    *   The number of EUTRAN cells (one or more) that shall be included 
    *   in the measurement report.
    * 
    */
    int  qSearchC_Eutran;
    int  eutranRepQuant;
    int  eutranMultiratReporting;
}fxL2gMIlteMeasParams;

typedef struct
{
    int  earfcn;          /* EARFCN */
    int  eutranMeasBwNrb; /* Measurement Bandwidth */
}fxL2gMILteFreq;

typedef struct
{
    int            noEutranFreqs;
    fxL2gMILteFreq eutranFreq[FXL_2G_MAX_4G_NEIGHBOR_EARFCNS];
}fxL2gMIlteNeighborInfo;

typedef struct
{
    fxL2gMIUmtsMeasParams   umtsMeasParams;
    fxL3gNeighborInfo       umtsNeighbors;
    fxL2gMIlteMeasParams    lteMeasParams;
    fxL2gMIlteNeighborInfo  lteNeighbors;
}fxL2gInterRatMeasInfo;

typedef struct
{
    fxLHeader             hdr;
    char                  imsiStr[SIZE_OF_IDENTITY_STR];
    fxLSi5Info            si5Info;
    fxLSi6Info            si6Info;
    int                   interRatMeasInfoPresent;
    fxL2gInterRatMeasInfo measInfo;
}fxL2gSilentCallDedSysInfoModifyCmd; //FXL_2G_SILENT_CALL_DED_SYS_INFO_MODIFY_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL2gSilentCallDedSysInfoModifyRsp ; //FXL_2G_SILENT_CALL_DED_SYS_INFO_MODIFY_RSP

/***********************************************************************************/
//Unsolicited / Asynchronous Indication to External Client to update SI of serving cell
// parameters
typedef struct
{
    fxLHeader       hdr;
    int             arfcn;
    fxL2gBandType   band;
    float           rssi;
    float           snr;
    fxL2gPlmn       plmn;
    int             lac;
    int             cellId;
    int             ncc; // BSIC(6 bits) = NCC(3 bits) + BCC(3 bits)
    int             bcc;
    int             noOfNeighbors;
    int             arfcnNeighbors[MAX_NO_OF_NEIGHBOR_ARFCNS];
    fxLSi2qInfo     si2qInfo;
    int             c1;
    int             c2;
    int             rxlevAccMin;    
    int             msTxpwrMaxCcch;
    int             cro;
    int             tempOffset;
    int             penaltyTime;
    int             noOfHoppingArfcns;
    int             hoppingList[MAX_NO_OF_HOPPING_ARFCNS];
    int             t3212;
}fxL2gListenModeSystemInfoInd ;//FXL_2G_LISTEN_MODE_SYSTEM_INFO_IND

typedef struct
{
    fxLHeader hdr;
}fxL2gListenModeScanCompleteInd ; //FXL_2G_LISTEN_MODE_SCAN_COMPLETE_IND

/***********************************************************************************/
//Command from External Client to trigger selective frequency scan in Listen Mode.
typedef struct
{
    fxLHeader       hdr;
    int             noOfScanIterations;
    int             noOfArfcnConfigured;
    fxLgsmArfcnBand bandArfcn[MAX_NO_ARFCN_FOR_SELECTIVE_SCAN];
}fxL2gListenModeConfigureSelectiveFreqCmd ;//FXL_2G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gListenModeConfigureSelectiveFreqRsp ;//FXL_2G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP
/***********************************************************************************/


/***********************************************************************************/
//3G Commands
/***********************************************************************************/

typedef enum
{
    FXL_UMTS_NO_REDIRECTION    = 0,
    FXL_UMTS_REDIRECTION_TO_2G = 1,
    FXL_UMTS_REDIRECTION_TO_3G = 2
}fxL3gRedirectionType;

typedef union
{
    fxLGsmRedirectInfo gsmRedirectinfo;
    unsigned int       dlUarfcn;
}fxL3gRedirectionInfo;

typedef enum
{
    FXL_UMTS_IMSI   = 0,
    FXL_UMTS_TMSI   = 1,
    FXL_UMTS_PTMSI  = 2,
    FXL_UMTS_IMEI   = 3,
    FXL_UMTS_NO_ID  = 4
}fxl3gInitialUEIdentityType;

typedef struct
{
    fxLHeader                  hdr;
    fxl3gInitialUEIdentityType initialIdentityType;
    union{
       char   imsiStr[SIZE_OF_IDENTITY_STR];
       char   imeiStr[SIZE_OF_IDENTITY_STR];
       char   tmsi[SIZE_OF_TMSI_IDENTITY];
       char   ptmsi[SIZE_OF_TMSI_IDENTITY]; 
    }u; 
}fxL3gEmergencyCallAttemptedInd ;//FXL_3G_EMERGENCY_CALL_ATTEMPTED_IND

typedef enum
{
    FXL_NETWORK_BASED_GPS_SUPPORT        = 0,
    FXL_UE_BASED_GPS_SUPPORT             = 1,
    FXL_NETWORK_AND_UE_BASED_GPS_SUPPORT = 2,
    FXL_NO_GPS_SUPPORT = 3
}fxL3gGpsSupportType_;
typedef int fxL3gGpsSupportType;


typedef struct
{
    fxLHeader      hdr;
    char           imsiStr[SIZE_OF_IDENTITY_STR];
    char           imeiStr[SIZE_OF_IDENTITY_STR];
    char           tmsi[SIZE_OF_TMSI_IDENTITY];
    unsigned int   imeiSv;
    fxLListType    listType;
    unsigned int   ulScramblingCode;
    unsigned int   dlChannelizationCode;
    float          initialRttVal;
    int            initialRscpVal;
    unsigned int   propagationDelay;
    fxL3gGpsSupportType  gpsSupportType;
    unsigned int         ueAccessSpectrumReleaseSupport;
    unsigned int         numberOfFddBandSupported;
    unsigned int         supportedFddBand[22];
	int          		 lastLac;
}fxL3gRegistrationAttemptedInd ;//FXL_3G_REGISTRATION_ATTEMPTED_IND

typedef struct
{
    int qQualMin;
    int qRxLevMin;
    int qHystLS;
    int qHyst2S;
    int tReselS;
    int maxAllowedULTxPower;
    int sIntraSearch;
    int sInterSearch;
    int sSearchHCS;
    int ratSearch;
    int sLimitSearchRAT;
}fxL3gCellSelReselInfo;

typedef struct
{
    int cellId;
    int psc;
}fxL3gIntraFreqCellList;

typedef struct
{
    int cellId;
    int dlUarfcn;
    int ulUarfcn;
    int psc;
}fxL3gInterFreqCellList;

typedef struct
{
    int           cellId;
    int           qRxLevMin;
    int           ncc;
    int           bcc;
    int           arfcn;
    fxLGsmBandIndicator band;
}fxL3gInterRATCellList;

typedef struct
{
    float                  rssi;
    float                  rscp;
    float                  ecio;
    int                    psc;
    int                    networkCellId;
    fxL3gCellSelReselInfo  cellSelReselInfo;
    fxL3gIntraFreqCellList intraFreqCellList[FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST];
    fxL3gInterFreqCellList interFreqCellList[FXL_UMTS_MAX_INTER_FREQ_CELL_LIST];
    fxL3gInterRATCellList  interRATCellList[FXL_UMTS_MAX_INTER_RAT_CELL_LIST];
}fxL3gCellInfo;

typedef struct
{
   int uarfcn;
   int priority;
   int threshXhigh;
   int threshXlow;
   int qQualMinFdd;
   int qRxLevMinFdd;
}fxL3gFddPriorityCellInfo;

typedef struct
{
   int earfcn;
   int priority;
   int qRxLevMinEUTRA;
   int threshXhigh;
   int threshXlow;
}fxL3gLtePriorityCellInfo;

typedef struct
{
   int arfcn;
   int bandIndicator; /* 0 = dcs1800, 1 = pcs1900 */
   int priority;
   int qRxLevMinGSM;
   int threshXhigh;
   int threshXlow;
}fxL3gGsmPriorityCellInfo;

typedef struct
{
    int                       servingCellPriority;
    int                       s_PrioritySearch1;
    int                       s_PrioritySearch2;
    int                       threshServingLow;
    fxL3gFddPriorityCellInfo  fddPriorityCellInfo[FXL_MAX_PRIORITY_CELL_LIST];
    fxL3gGsmPriorityCellInfo  gsmPriorityCellInfo[FXL_MAX_PRIORITY_CELL_LIST];
    fxL3gLtePriorityCellInfo  ltePriorityCellInfo[FXL_MAX_PRIORITY_CELL_LIST];
}fxl3gPriorityCellInfo;

/***********************************************************************************/
//Command from External Client to configure Bands for scanning in 3G Listen Mode.
typedef struct
{
    fxLHeader     hdr;
    int           noOfScanIterations;
    int           noOfBandsToScan;
    fxL3gBandType band[FXL_UMTS_MAX_BAND_SUPPORTED]; // Maximum bands can be scan as 8
                                                     // ie. BAND1, BAND2, BAND3, BAND4,
                                                     // BAND5, BAND8, Additional Band2 &
                                                     // Additional Band5
}fxL3gListenModeConfigureBandsCmd ;//FXL_3G_LISTEN_MODE_CONFIGURE_BANDS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gListenModeConfigureBandsRsp ;//FXL_3G_LISTEN_MODE_CONFIGURE_BANDS_RSP

/***********************************************************************************/
//Command from External Client to start or stop scanning in 3G Listen Mode.
typedef struct
{
    fxLHeader           hdr;
    fxLStartStopTrigger startStopScan;
    int                 dspResetNeeded;
    fxLScanType         scanType;
}fxL3gListenModeStartStopScanCmd ;//FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gListenModeStartStopScanRsp ;//FXL_3G_LISTEN_MODE_STARTSTOP_SCAN_RSP

/***********************************************************************************/
//Command from External Client to start or stop priority scanning in 3G Listen Mode.

typedef struct
{
    int           uarfcn;
    fxL3gBandType band;
}fxL3gUarfcnBand;

typedef struct
{
    fxLHeader       hdr;
    int             noOfIteration;
    int             noOfUarfcn;
    fxL3gUarfcnBand bandUarfcn[MAX_NO_OF_UARFCN];
}fxL3gListenModeConfigureUarfcnCmd ;//FXL_3G_LISTEN_MODE_PRIORITY_SCAN_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gListenModeConfigureUarfcnRsp ;//FXL_3G_LISTEN_MODE_PRIORITY_SCAN_RSP

/***********************************************************************************/
//Unsolicited / Asynchronous Indication to External Client to update Operator
//Configuration Details.
#define FXL_UMTS_MAX_CELL_INFO         1
typedef struct
{
    fxLHeader     hdr;
    fxL3gBandType band;
    int           uarfcn;
    unsigned int  mibPlmnIdentity;
    unsigned int  numOfPlmn;
    fxL3gPlmn     plmn[FXL_UMTS_MAX_NO_PLMNS];
    int           lac;
    int           rac;
    int           t3212;
    int           nmo;
    int           pci;
    int           numOfCell;
    fxL3gCellInfo cellInfo[FXL_UMTS_MAX_CELL_INFO];
    fxl3gPriorityCellInfo  priorityCellInfo;
}fxL3gListenModeSystemInfoInd ;//FXL_3G_LISTEN_MODE_SYSTEM_INFO_IND
/***********************************************************************************/
//Command from External Client to configure 3G IdCatcher parameters

typedef enum
{
    FXL_IMSI_UNKNOWN_IN_HLR                       = 2,
    FXL_ILLEGAL_MS                                = 3,
    //FXL_IMSI_UNKNOWN_IN_VLR                     = 4,
    FXL_IMEI_NOT_ACCEPTED                         = 5,
    FXL_ILLEGAL_ME                                = 6,
    FXL_PLMN_NOT_ALLOWED                          = 11,
    FXL_LOCATION_AREA_NOT_ALLOWED                 = 12,
    FXL_ROAMING_NOT_ALLOWED_IN_THIS_LOCATION_AREA = 13,
    FXL_N0_SUITABLE_CELLS_IN_LOCATION_AREA        = 15,
    FXL_NETWORK_FAILURE                           = 17,
    FXL_MAC_FAILURE                               = 20,
    FXL_SYNCH_FAILURE                             = 21,
    FXL_CONGESTION                                = 22,
    FXL_GSM_AUTHENTICATION_UNACCEPTABLE           = 23,
    //FXL_SERVICE_OPTION_NOT_SUPPORTED            = 32,
    //FXL_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED = 33,
    //FXL_SERVICE_OPTION_TEMPORIALY_OUT_OF_ORDER  = 34,
    //FXL_CALL_CANNOT_BE_IDENTIFIED               = 38,
    FXL_RETRY_UPON_ENTRY_INTO_A_NEW_CELL          = 48
}fxl3gWlRejectCause; 

typedef struct
{
    fxLHeader            hdr;
    unsigned int         dlUarfcn;
    unsigned int         rncId;
    unsigned int         cellId;
    unsigned int         psc;
    unsigned int         numOfPlmn;
    fxL3gPlmn            plmn[FXL_UMTS_MAX_NO_PLMNS];
    unsigned int         lac[2];
    unsigned int         rac;
    unsigned int         txAttn;
    unsigned int         cpichTxPwr;
    fxL3gRedirectionType redirectionType;
    fxL3gRedirectionInfo redirectionInfo;
    unsigned int         rejectCauseEnable; 
    fxl3gWlRejectCause   rejectCause;
    unsigned int         t3212;
    unsigned int         enableEmergencyRejection;
    fxL3gRedirectionType emergencyCallRedirectionType;
    fxL3gRedirectionInfo emergencyCallRedirectionInfo; 
    unsigned int         pilot_boost_enable;
    unsigned int         ulRxGainDb; // range : [0..73] in dB
}fxL3gConfigureIdCatcherParamsCmd ;//FXL_3G_CONFIGURE_IDCATCHER_PARAMS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gConfigureIdCatcherParamsRsp ;//FXL_3G_CONFIGURE_IDCATCHER_PARAMS_RSP
/***********************************************************************************/
//Command from External Client to start 3G Id Catcher.
typedef struct
{
    fxLHeader hdr;
}fxL3gStartIdCatcherCmd ;//FXL_3G_START_IDCATCHER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gStartIdCatcherRsp ;//FXL_3G_START_IDCATCHER_RSP

/***********************************************************************************/
//Command from External Client for silent call.
typedef struct
{
    fxLHeader     hdr;
    fxL3gMeasType measType;        
    char          imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gStartSilentCallCmd ;//FXL_3G_START_SILENT_CALL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gStartSilentCallRsp ;//FXL_3G_START_SILENT_CALL_RSP

typedef struct
{
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gEndSilentCallCmd ;//FXL_3G_END_SILENT_CALL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gEndSilentCallRsp ;//FXL_3G_END_SILENT_CALL_RSP
/***********************************************************************************/
//Command from External Client to start 3G dedicated measurement.
typedef struct
{
    fxLHeader     hdr;
    fxL3gMeasType measType;        
    char          imsiStr[SIZE_OF_IDENTITY_STR];
    int           rscpValue;
    float         rttValue;
}fxL3gDedMeasValueInd; //FXL_3G_DED_MEAS_VALUE_IND

/***********************************************************************************/
//Command to External Client to Indicate a BL UE went out of Coverage 
typedef struct
{
    fxLHeader     hdr;
    char          imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gBlUeOutOfCoverage; //FXL_3G_BL_UE_OUT_OF_COVERAGE_IND

/***********************************************************************************/
//Command from External Client to Modify UE Uplink Tx Power
typedef struct
{
    fxLHeader     hdr;
    int           maxUlTxPwr;
    char          imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gChangeUeUlTxPwrCmd; //FXL_3G_CHANGE_UE_UL_TX_PWR_CMD

typedef struct
{
    fxLHeader     hdr;
    fxLResult     result;
    char          imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gChangeUeUlTxPwrRsp; //FXL_3G_CHANGE_UE_UL_TX_PWR_RSP
/***********************************************************************************/
//Command from External Client to Modify UE Uplink Tx Power
typedef struct
{
    fxLHeader            hdr;
    fxL3gRedirectionType redirectionType;
    fxL3gRedirectionInfo redirectionInfo;
    char                 imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gBLUeRedirectCmd; //FXL_3G_BL_UE_REDIRECT_CMD

typedef struct
{
    fxLHeader     hdr;
    fxLResult     result;
    char          imsiStr[SIZE_OF_IDENTITY_STR];
}fxL3gBLUeRedirectRsp; //FXL_3G_BL_UE_REDIRECT_RSP
/***********************************************************************************/
//Indication to External Client for GPS Measurement



typedef struct
{
    fxLHeader              hdr;
    fxLResult              result;
    char                   imsiStr[SIZE_OF_IDENTITY_STR];
    fxlUePositioningError  errorCode;
    fxlUePositioningInfo   uePosInfo;
}fxl3gUeBasedGpsMeasInd; //FXL_3G_UE_BASED_GPS_MEAS_IND

/***********************************************************************************/
//Command from External Client to start 3G Tx Jammer.
typedef struct
{
    fxLHeader     hdr;
    unsigned int  uarfcn;
    fxL3gBandType band; 
}fxL3gTxJammerStartCmd; //FXL_3G_TX_JAMMER_START_CMD
/***********************************************************************************/
//Response from WGS Application to External Client.
typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gTxJammerStartRsp; //FXL_3G_TX_JAMMER_START_RSP
/***********************************************************************************/
//Command from External Client to stop 3G Tx Jammer.
typedef struct
{
    fxLHeader hdr;
}fxL3gTxJammerStopCmd; //FXL_3G_TX_JAMMER_STOP_CMD
/***********************************************************************************/
//Response from WGS Application to External Client.
typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gTxJammerStopRsp; //FXL_3G_TX_JAMMER_STOP_RSP
/***********************************************************************************/
//3G Tx Jammer Status
typedef enum
{
   FXL_3G_TX_JAMMER_INITIALIZATION_FAILED,
   FXL_3G_TX_JAMMER_SCANNING_CELL,
   FXL_3G_TX_JAMMER_SCANNING_CELL_FAILED,
   FXL_3G_TX_JAMMER_CELL_FOUND,
   FXL_3G_TX_JAMMER_NO_CELL_FOUND,
   FXL_3G_TX_JAMMER_RUNNING
}fxL3gTxJammerStatus;
#define MAX_NUM_OF_PSC_PER_UARFCN 10
/***********************************************************************************/
//3G Tx Jammer Status Indication from WGS Application to External Client.
typedef struct
{
    fxLHeader            hdr;
    fxL3gTxJammerStatus  status;
    unsigned int         numOfCell;
    unsigned int         cellPsc[MAX_NUM_OF_PSC_PER_UARFCN];
}fxL3gTxJammerStatusInd; //FXL_3G_TX_JAMMER_STATUS_IND
/***********************************************************************************/
//Command from External Client to stop 3G Id Catcher.
typedef struct
{
    fxLHeader hdr;
    int dspResetNeeded;
}fxL3gStopIdCatcherCmd ;//FXL_3G_STOP_IDCATCHER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gStopIdCatcherRsp ;//FXL_3G_STOP_IDCATCHER_RSP

/***********************************************************************************/
//Command from External Client to configure System information(SIB info) for 3G S/W 
typedef struct 
{
   unsigned int psc;
   int          readSfnIndicator;
   int          txDiversityIndicator;
}fxl3gIntraFreqNeigbrInfo;

typedef struct 
{
   unsigned int psc;
   unsigned int dlUarfcn;
   int          readSfnIndicator;
   int          txDiversityIndicator;
}fxl3gInterFreqNeigbrInfo;

typedef struct
{
   //CN domain list
   int       cnDomainList[2]; // HardCoded as idx 0 = CS, 1 = PS
   int       T300;
   int       N300;
   int       T301;
   int       T302;
   int       T304;
   int       T305;
   int       T307;
   int       T308;
   int       T310;
   int       T311;
   int       T312;
   int       N312;
   int       N313;
   int       T314;
   int       T315;
   int       N315;
   int       T316;
   int       T317;

}fxL3gSib1Info;

typedef struct
{
   // If Sib2 is filled this value shall be filled.
   int numUraIdentity;                          // 1, for 0 set sib2Pres to 0.
   int uraIdentityLst[MAX_URA_IDENTITY_NUM];  
}fxL3gSib2Info;

typedef struct
{
   int status;  //Barred = 0, Not Barred = 1)
   //Following info is required if status = 0
   int intraFreqCellReselectionInd; // 0 = allowed, 1 = not allowed.
   int T_Barred; // 0 = s10, 1 = s20, 2 = s40, 3 = s80, 4= s160, 5 = s320, 6 = s640, 7 = s1280.
}CellBarredInfo;

typedef struct
{
   int sib4Indicator;
   int cellId;
   int cellSelQualMeas;
   int qHyst2S;
   //-- Mode Specific Info (FDD only)
   int sIntraSearch;
   int sInterSearch;
   int sSearchHCS;
   int ratSearch;
   int cellReselectionCfgStatus; // Cell Reselection parameter controlled by flag if filled or not.
   //CellReselectParam - Start
   //{
      int sLimitSearchRAT;
      int qQualMin;
      int qRxLevMin;
      int qHystLS;
      int tReselect;
      int maxULTxPower;
   //}
   //CellReselectParam - End

   CellBarredInfo cellBarredInfo; //Barred = 0, Not Barred = 1
   int cellReservedForOperatiorUse;    // 0- No, 1-Yes
   int cellReservationExtention;    // 0- No, 1-Yes
   int accessClassBarredLstPres;    //
   unsigned int accessClassBarredLst[16];  //Fill All values if accessClassBarredLstPres != 0

}fxL3gSib3Info;

/*
 * If Sib5 is filled all parameters are mendatory to Fill.
 */
typedef struct
{
    //These parameter require change in L1 cell setup. so if filled it will require Id catcher restart.
   int sib6indicator; 
   //PICH Power-- Unit dB, Range -10dB .. +5dB, Step +1dB
   int pichPwr;                           //Default = -5 
   int aichPwr;                           //Default = -5 
   int prachPowerRampStep;                //Default = 1
   int prachpreambleRetransMax;           //Default = 30

}fxL3gSib5Info;

typedef struct
{  //This value mendatory if sib7CfgPres != 0
   int ulInterference; 

}fxL3gSib7Info;

typedef struct
{  // IF Sib11 is updated All Neighbour list will be updated no default Neighbour list will be used
   int                       sib12indicator; 
   int                       hscUsed; // Currently not Supported. Hardcoded to not used.
   int                       numInterFreqNeighbr;
   fxl3gInterFreqNeigbrInfo  interFreqNeighbrList[FXL_UMTS_MAX_INTER_FREQ_CELL_LIST];
   unsigned int              numIntraFreqNeighbr;
   fxl3gIntraFreqNeigbrInfo  intraFreqNeighbrList[FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST];

}fxL3gSib11Info; 

typedef struct
{
    fxLHeader hdr;
    int                  numOfPlmn;
    fxL3gPlmn            plmn[FXL_UMTS_MAX_NO_PLMNS];    
    int                  lac[2];
    int                  rac;
    int                  t3212;
    int                  att;
    int                  nmo;       
    int                  mibValueTag;
    int                  sib1CfgPres;  // 0 = Not Present/Updated.
    int                  sib2CfgPres;
    int                  sib3CfgPres;
    int                  sib5CfgPres;
    int                  sib7CfgPres;
    int                  sib11CfgPres;
    fxL3gSib1Info        sib1Info;
    fxL3gSib2Info        sib2Info;
    fxL3gSib3Info        sib3Info;
    fxL3gSib5Info        sib5Info;  //If Sib5 is changed it must be followed by Cell/Id catcher restart.
    fxL3gSib7Info        sib7Info;
    fxL3gSib11Info       sib11Info;

}fxL3gSysInfoConfigCmd;//FXL_3G_SYSINFO_CONFIG_CMD

typedef struct
{
    fxLHeader hdr; 
    fxLResult result;
}fxL3gSysInfoConfigRsp;//FXL_3G_SYSINFO_CONFIG_RSP

/***********************************************************************************/
/***********************************************************************************/
//Command from External Client to auto start 3G Id Catcher
typedef struct
{
    fxLHeader            hdr;
    fxLDspType           dspType;
    int                  noOfBandsToScan;
    fxL3gBandType        band[FXL_UMTS_MAX_BAND_SUPPORTED];
    fxL3gPlmn            plmn;
    unsigned int         txAttn;
    unsigned int         cpichTxPwr;
    int                  dspResetNeeded;
    fxLListType          defaultListConfig;
    int                  noOfEntries;
    fxLIdentityConfig    configList[MAX_NO_OF_IDS_PER_TRANSACTION];
    fxL3gRedirectionType redirectionType;
    fxL3gRedirectionInfo redirectionInfo;
    unsigned int         rejectCauseEnable; 
    fxl3gWlRejectCause   rejectCause;
    unsigned int         enableEmergencyRejection;
    fxL3gRedirectionType emergencyCallRedirectionType;
    fxL3gRedirectionInfo emergencyCallRedirectionInfo;
    unsigned int         pilot_boost_enable;
    unsigned int         ulRxGainDb; // range : [0..73] in dB
}fxL3gAutoConfigCmd; //FXL_3G_AUTO_CONFIG_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gAutoConfigRsp; //FXL_3G_AUTO_CONFIG_RSP

typedef struct
{
    fxLHeader    hdr;
    unsigned int txAttn;
    unsigned int cpichTxPwr;
}fxL3gChgTxAttnCpichTxPwrCmd;   //FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gChgTxAttnCpichTxPwrRsp;   //FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_RSP

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gListenModeScanCompInd ;//FXL_3G_LISTEN_MODE_SCAN_COMP_IND


typedef struct
{
    fxLHeader hdr;
    int dspResetNeeded;
}fxL3gAutoConfigStopCmd ; //FXL_3G_AUTO_CONFIG_STOP_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL3gAutoConfigStopRsp; //FXL_3G_AUTO_CONFIG_STOP_RSP

typedef struct
{
    fxLHeader     hdr;
    unsigned int  uarfcn;
    fxL3gBandType band;
    unsigned int  psc;
    unsigned int  cellId;
    unsigned int  lac[2];
    unsigned int  rac;
}fxL3gAutoConfigUarfcnInd; //FXL_3G_AUTO_CONFIG_UARFCN_IND

typedef struct
{
    fxLHeader hdr;
}fxLEnableGpsCmd ; //FXL_ENABLE_GPS_CMD

typedef struct
{
    fxLHeader      hdr;
    fxLResult      result;
}fxLEnableGpsRsp ; //FXL_ENABLE_GPS_RSP

typedef struct
{
    fxLHeader      hdr;
    fxLGpsFixType  gpsFixType;
    fxLGpsLocation gpsLocation;
}fxLGpsStatusInd; //FXL_GPS_STATUS_IND

typedef struct
{
    fxLHeader hdr;
}fxLStopGpsCmd; //FXL_STOP_GPS_CMD

typedef struct
{
    fxLHeader      hdr;
    fxLResult      result;
}fxLStopGpsRsp; //FXL_STOP_GPS_RSP

/***********************************************************************************/
typedef fxL3gPlmn fxL4gPlmn;
typedef struct
{
    fxL4gPlmn    plmn;
    unsigned int mmegrpID;
    unsigned int mmecode;
    unsigned int mtmsi;
}fxl4gGuti;

//Command from External Client to configure Bands for scanning in Listen Mode.
typedef struct
{
    fxLHeader     hdr;
    int           noOfScanIterations;
    int           noOfBandsToScan;
    fxL4gBandType band[LTE_MAX_BANDS_TO_SCAN];
}fxL4gListenModeConfigureBandsCmd ;//FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gListenModeConfigureBandsRsp ;//FXL_4G_LISTEN_MODE_CONFIGURE_BANDS_RSP
/***********************************************************************************/
//Command from External Client to start scanning in Listen Mode.
typedef struct
{
    fxLHeader   hdr;
    fxLScanType scanType;
}fxL4gListenModeStartScanCmd ;//FXL_4G_LISTEN_MODE_START_SCAN_CMD

//Command from External Client to stop scanning in Listen Mode.
typedef struct
{
    fxLHeader hdr;
    int       dspResetNeeded;
}fxL4gListenModeStopScanCmd ;//FXL_4G_LISTEN_MODE_STOP_SCAN_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gListenModeStartScanRsp ;//FXL_4G_LISTEN_MODE_START_SCAN_RSP

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gListenModeStopScanRsp ;//FXL_4G_LISTEN_MODE_STOP_SCAN_RSP

typedef struct
{
    fxLHeader hdr;
    int       noOfScanIterations;
    int       noOfEarfcnConfigured;
    int       earfcn[MAX_NO_EARFCN_FOR_SELECTIVE_SCAN];
}fxL4gListenModeConfigureSelectiveFreqCmd ;//FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gListenModeConfigureSelectiveFreqRsp ;//FXL_4G_LISTEN_MODE_CONFIGURE_SELECTIVE_FREQUENCIES_RSP

/***********************************************************************************/
//Unsolicited / Asynchronous Indication to External Client to update SI-3 serving cell
// parameters

typedef enum{
	 casn_dB_24 = 0 ,
	 casn_dB_22,
	 casn_dB_20,
	 casn_dB_18,
	 casn_dB_16,
	 casn_dB_14,
	 casn_dB_12,
	 casn_dB_10,
	 casn_dB_8,
	 casn_Q_OffsetRange__dB_6,
	 casn_dB_5,
	 casn_Q_OffsetRange__dB_4,
	 casn_Q_OffsetRange__dB_3,
	 casn_Q_OffsetRange__dB_2,
	 casn_dB_1,
	 casn_Q_OffsetRange__dB0,
	 casn_Q_OffsetRange__dB1,
	 casn_Q_OffsetRange__dB2,
	 casn_Q_OffsetRange__dB3,
	 casn_Q_OffsetRange__dB4,
	 casn_Q_OffsetRange__dB5,
	 casn_Q_OffsetRange__dB6,
	 casn_Q_OffsetRange__dB8,
	 casn_Q_OffsetRange__dB10,
	 casn_Q_OffsetRange__dB12,
	 casn_Q_OffsetRange__dB14,
	 casn_Q_OffsetRange__dB16,
	 casn_Q_OffsetRange__dB18,
	 casn_Q_OffsetRange__dB20,
	 casn_Q_OffsetRange__dB22,
	 casn_Q_OffsetRange__dB24
}fxLSib4QoffsetRange_;
typedef int fxLSib4QoffsetRange;


typedef struct
{
    int intraFreqNeighborCellPci; //0-511
    fxLSib4QoffsetRange intraFreqNeighborCellQoffset; // -24 to +24
}lteIntraFreqNeighbourCell ;

typedef struct  
{
    unsigned int dlCarrierFreq;
    unsigned int cellReselectionPriority;
    int          qRxLevMin;
    int          threshXLow;
    int          threshXHigh;   
}lteInterFreqNeighbourCell;

typedef struct  
{
    unsigned int umtsCarrierFreq;
    int          pMaxUTRA;
    unsigned int cellReselectionPriority;
    int          qQualMin;
    int          qRxLevMin;
    int          threshXLow;
    int          threshXHigh;
}lteUmtsNeighbourCell; 

typedef struct
{
    int          tac; // 16 bit
    unsigned int l3cellId; //28bit
    unsigned int noOfPlmns; // MAX = 6
	fxL4gPlmn plmn[FXL_LTE_MAX_NO_PLMNS];
    unsigned int isCellBarred; // TRUE = BARRED , FALSE = NOT BARRED
    int          qRxLevMin; //(-70..-22)
    int          qRxLevMinOffset; //(1..8)
    fxL4gBandType freqBandIndicator; 
    unsigned int siPeriodicity;
    unsigned int siWindowLength;
    unsigned int isIntraFreqSelectionAllowed; // TRUE = ALLOWEd , FALSE = NOT ALLOWED
    unsigned int pMax; // -30 to 33
}fxL4gSib1 ;

typedef struct
{
    unsigned int drxCycle;
    unsigned int prachConfigIdx;
    unsigned int highSpeedFlag;
    unsigned int prachZeroCorrelationZoneConfig;
    unsigned int prachFreqOffset;
    int          p0NominalPUCCH;
}fxL4gSib2 ;

typedef struct
{
    unsigned int qHyst;
    unsigned int cellReselectionPriority;
    int          threshServingLow; //(0..31)
    int          qRxLevMin; ////(-70..-22)
    unsigned int isAntennaPort1Present; // TRUE=Yes , FALSE=No
    unsigned int tReselectionEUTRA; //(0..7)
    int          sNonIntraSearch;
    int          sIntraSearch;
    unsigned int neighbourCell;
}fxL4gSib3 ;

typedef struct
{
    int  noOfIntraFreqNeighbors;
    lteIntraFreqNeighbourCell  intraFreqCells[MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS];
	int  noOfBlacklistedIntraFreqNeighbors;
	int  intraFreqBlacklistedCellPci[MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS];
}fxL4gSib4 ;

typedef struct
{
    unsigned int              noOfInterFreqNeighbourCells;
    lteInterFreqNeighbourCell earfcnInterFreqNeighbors[MAX_NO_OF_NEIGHBOUR_CELLS_INTER_IN_SIB5];
}fxL4gSib5 ;

typedef struct
{
    unsigned int         noOfInterRatUmtsNeighbors;
    lteUmtsNeighbourCell uarfcnInterRatNeighbors[MAX_NO_OF_UMTS_NEIGHBOUR_CELLS_IN_SIB6];
    unsigned int         tReselectionUTRA;
}fxL4gSib6 ;

typedef struct
{
    int  noOfInterRatGsmNeighbors;
    int  startingArfcnInterRatNeighbors[MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS];
    int  bandIndicator[MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS];
}fxL4gSib7 ;

typedef struct
{
    fxLHeader          hdr;
    int                earfcn;
    int                phyCellId;
    float              rssi;
    float              rsrp;
    float              rsrq;
    fxL4gDlBw          dlBw;
    int                noOfTxAntPorts;
    fxL4gPhichDuration phichDuration;
    fxL4gPhichResource phichResource;
    fxL4gSib1          sib1;
    fxL4gSib2          sib2;
    fxL4gSib3          sib3;
    fxL4gSib4          sib4;
    fxL4gSib5          sib5;
    fxL4gSib6          sib6;
    fxL4gSib7          sib7;    
    int                sibMask;
	unsigned int       relativeD;
}fxL4gListenModeSystemInfoInd ;//FXL_4G_LISTEN_MODE_SYSTEM_INFO_IND

typedef struct
{
    fxLHeader hdr;
}fxL4gListenModeScanCompleteInd ; //FXL_4G_LISTEN_MODE_SCAN_COMPLETE_IND
/***********************************************************************************/
//Command from External Client to configure 4G IdCatcher parameters

typedef struct
{
    fxLHeader                hdr;
    unsigned int             earfcn;
    fxL4gBandType            bandIndicator;
    unsigned int             phyCellId; // 0-503
    unsigned int             layer3CellId;
    unsigned int             numOfPlmn;
    fxL4gPlmn                plmn[FXL_LTE_MAX_NO_PLMNS];
    unsigned int             tac;
    unsigned int             AutoConfigureEnabled; // TRUE-yes , FALSE-no, When set to TRUE , LTE-EnodeB will choose EARFCN and TAC based on Listen Mode data.
    fxLRedirectionFrom4gType redirectionType;
    fxLRedirectionFrom4gInfo redirectionInfo;
    unsigned int             txAttndB;
    unsigned int             enableAttRejCause;
    fxl4gWlRejectCause       attRejCause;
    unsigned int             ulRxGainDb; // range : [0..73] in dB 
    unsigned int             lteBandwidth; // range [0-5]
    unsigned int             minTaValue; // o to 63
    unsigned int             maxTaValue; // o to 63
    unsigned int             reserved; // 0 to 65535
    unsigned int 	     enablePrmredirectCfg;// TRUE or FALSE
    unsigned int             pilot_boost_enable;
    unsigned int             wlRedirectEarfcn;
    fxLEmegerncyCallServingCellType emeCallSrvCellType;
    fxLEmergencyCallServingCellInfo emeCallSrvCellInfo;
}fxL4gConfigureIdCatcherParamsCmd ;//FXL_4G_CONFIGURE_IDCATCHER_PARAMS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gConfigureIdCatcherParamsRsp ;//FXL_4G_CONFIGURE_IDCATCHER_PARAMS_RSP

typedef struct
{
        unsigned int tac; // 16 bit
        unsigned int isCellBarred; // TRUE = BARRED , FALSE = NOT BARRED
        int          qRxLevMin; //(-70..-22) ==> need to check IE*2dbm
        int          qRxLevMinOffset; //(1..8) 
        unsigned int isIntraFreqSelectionAllowed; // TRUE = ALLOWEd , FALSE = NOT ALLOWED
        int          pMax; // -30 to 33
        unsigned int systemValueTag; 
}fxL4gSib1_lte ;

typedef enum
{
 FXL_AC_BARRING_FACTOR_P00 = 0,
 FXL_AC_BARRING_FACTOR_P05,
 FXL_AC_BARRING_FACTOR_P10,
 FXL_AC_BARRING_FACTOR_P15,
 FXL_AC_BARRING_FACTOR_P20,
 FXL_AC_BARRING_FACTOR_P25,
 FXL_AC_BARRING_FACTOR_P30,
 FXL_AC_BARRING_FACTOR_P40,
 FXL_AC_BARRING_FACTOR_P50,
 FXL_AC_BARRING_FACTOR_P60,
 FXL_AC_BARRING_FACTOR_P70,
 FXL_AC_BARRING_FACTOR_P75,
 FXL_AC_BARRING_FACTOR_P80,
 FXL_AC_BARRING_FACTOR_P85,
 FXL_AC_BARRING_FACTOR_P90,
 FXL_AC_BARRING_FACTOR_P95
}fxLAcBarringFactor; 

typedef enum
{
  FXL_AC_BARRING_TIME_S4 = 0,
  FXL_AC_BARRING_TIME_S8,
  FXL_AC_BARRING_TIME_S16,
  FXL_AC_BARRING_TIME_S32,
  FXL_AC_BARRING_TIME_S64,
  FXL_AC_BARRING_TIME_S128,
  FXL_AC_BARRING_TIME_S256,
  FXL_AC_BARRING_TIME_S512
}fxLAcBarringTime;

typedef struct
{
   fxLAcBarringFactor acBarringFactor;
   fxLAcBarringTime acBarringTime;
   unsigned int acBarringForSpecialAC; // For set AC11, set MSB(index 7) bit as 1 (10000000),For set AC12, set index 6 bit as 1 (01000000),
}fxL4gBarringParams;                   // For set AC13, set index 5 bit as 1 (00100000),For set AC14, set index 4 bit as 1 (00010000),
                                       // For set AC15, set index 3 bit as 1 (00001000),For set all AC, set bit as 1 (11111000)

typedef struct
{
        unsigned int isBarredForEmergency;
        unsigned int isBarredForMoSignalling;
        fxL4gBarringParams moSignallingBarringInfo;
        unsigned int isBarredForMoData;
        fxL4gBarringParams moDataBarringInfo;
        unsigned int isBarredForMmtelVoice;
        fxL4gBarringParams ssacMmtelVoiceBarringInfo;
        unsigned int isBarredForMmtelVideo;
        fxL4gBarringParams ssacMmtelVideoBarringInfo;
        unsigned int isBarredForCsfb;
        fxL4gBarringParams csfbBarringInfo;
        unsigned int modficationCoeff;
        unsigned int nB;
        unsigned int pB; // (0..3)
        int          refSignalPower; // (-60..50)
        unsigned int isHighSpeedFlagSet; // boolean
        unsigned int prachConfigIndex; // 0 -63
        unsigned int prachFreqOffset; // 0 -94
        unsigned int prachZeroCorrelationZoneConfig; // 0-15
        unsigned int rootSequenceIndex; // 0 -837 
        unsigned int pucchDeltaShift; // {ds1, ds2, ds3},
        unsigned int n1PucchAN; //  (0..2047)
        unsigned int n1CsAn; // (0..97)
        unsigned int nRBCqi; // (0..98)
        unsigned int enable64QAM; // boolean
        unsigned int hoppingMode; //{interSubFrame, intraAndInterSubFrame},
        unsigned int puschNSB; // (1..4),
        unsigned int puschHoppingOffset; // (0..98)
        unsigned int puschRefSigCyclicShift; // (0..7)
        unsigned int isGroupHoppingEnabled; // BOOLEAN
        unsigned int puschGroupAssignment; // (0..29)
        unsigned int isSequenceHoppingEnabled; // BOOLEAN
        unsigned int maxHARQMsg3Tx; // (1..8)
        unsigned int powerRampingStep; // {dB0, dB2,dB4, dB6}
        unsigned int preambleTargetPower; // { dBm-120, dBm-118, dBm-116, dBm-114, dBm-112,dBm-110, dBm-108, dBm-106, dBm-104, dBm-102,dBm-100, dBm-98, dBm-96, dBm-94,dBm-92, dBm-90}
        unsigned int noRaPreambles; // n4, n8, n12, n16 ,n20, n24, n28,n32, n36, n40, n44, n48, n52, n56,n60, n64
        unsigned int isSrsAckNackSimultaeneousTransmissionAllowed; // BOOLEAN
        unsigned int srsBw; // {bw0, bw1, bw2, bw3, bw4, bw5, bw6, bw7},
        unsigned int srsSubframe; // sc0, sc1, sc2, sc3, sc4, sc5, sc6, sc7,sc8, sc9, sc10, sc11, sc12, sc13, sc14, sc15}
        unsigned int cyclicPrefixLen; // {len1, len2}
        unsigned int alpha; //{al0, al04, al05, al06, al07, al08, al09, al1}
        unsigned int format1Delta; // {deltaF-2, deltaF0, deltaF2}
        unsigned int format1bDelta; // {deltaF1, deltaF3, deltaF5}
        unsigned int format2Delta; // {deltaF-2, deltaF0, deltaF1, deltaF2}
        unsigned int format2aDelta; // {deltaF-2, deltaF0, deltaF2},
        unsigned int format2bDelta; // {deltaF-2, deltaF0, deltaF2}
        int          deltaPreambleMsg3; // (-1..6)
        int          p0NominalPUCCH; // (-127..-96)
        int          p0NominalPUSCH; // (-126..24)
        unsigned int taTimer; // sf500, sf750, sf1280, sf1920, sf2560, sf5120,sf10240, infinity
        unsigned int n310; // enum values , please check 3gpp spec 36.331 UE-TimersAndConstants topic
        unsigned int n311;
        unsigned int t300;
        unsigned int t301;
        unsigned int t310;
        unsigned int t311;
        unsigned int preambleTransMax; // enum n3, n4, n5, n6, n7,  n8, n10, n20, n50,n100, n200
        unsigned int macContentionResolutionTimer; // sf8, sf16, sf24, sf32, sf40, sf48,sf56, sf64}
        unsigned int raResponseWindow; // sf2, sf3, sf4, sf5, sf6, sf7,sf8, sf10
        unsigned int ulBandwidth; // {n6, n15, n25, n50, n75, n100}
        unsigned int ulFrequency;// 
}fxL4gSib2_lte ;

typedef struct
{
    unsigned int qHyst;
    unsigned int cellReselectionPriority;
    int          threshServingLow; //(0..31)
    int          qRxLevMin; ////(-70..-22)
    unsigned int isAntennaPort1Present; // TRUE=Yes , FALSE=No
    unsigned int tReselectionEUTRA; //(0..7)
    int          sNonIntraSearch; // (0-31)
    int          sIntraSearch;  // (0-31)
    unsigned int neighbourCell; // only for mbms and UL/DL TDD cases , default 0 
}fxL4gSib3_lte ;

typedef struct
{
    int  noOfIntraFreqNeighbors;
    lteIntraFreqNeighbourCell  intraFreqCells[MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS];
	int  noOfBlacklistedIntraFreqNeighbors;
	int  intraFreqBlacklistedCellPci[MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS];
}fxL4gSib4_lte ;

typedef struct
{
    unsigned int              noOfInterFreqNeighbourCells;
    lteInterFreqNeighbourCell earfcnInterFreqNeighbors[MAX_NO_OF_NEIGHBOUR_CELLS_INTER_IN_SIB5];
}fxL4gSib5_lte ;

typedef struct
{
    unsigned int         noOfInterRatUmtsNeighbors;
    lteUmtsNeighbourCell uarfcnInterRatNeighbors[MAX_NO_OF_UMTS_NEIGHBOUR_CELLS_IN_SIB6];
    unsigned int tReselectionUTRA;
}fxL4gSib6_lte ;

typedef struct
{
    int  noOfInterRatGsmNeighbors;
    int  startingArfcnInterRatNeighbors[MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS];
    int  bandIndicator[MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS];
}fxL4gSib7_lte ;

typedef struct
{
    fxLHeader           hdr;
    unsigned int        sibMask; // indicates sib presence
    fxL4gSib1_lte       sib1;   
    fxL4gSib2_lte       sib2;
    fxL4gSib3_lte       sib3;
    //fxL4gSib4_lte sib4;
    //fxL4gSib5_lte sib5;
    //fxL4gSib6_lte sib6;
    //fxL4gSib7_lte sib7;   
    //int sibMask;
}fxL4gSysInfoModifyCmd ;//FXL_4G_SYS_INFO_MODIFY_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gSysInfoModifyRsp ;//FXL_4G_SYS_INFO_MODIFY_RSP


typedef struct
{
    fxLHeader            hdr;
    int                  noOfEntries;
    // Only  IMSI IdType is supported
    // Configure ListType as FXL_WHITEUSERSLIST
    fxLIdentityConfig    blRlsUserList[MAX_NO_OF_IDS_PER_TRANSACTION];
}fxL4gRlsBlUsersCmd; // FLX_4G_RLS_BL_USERS_CMD


typedef struct
{
    fxLHeader      hdr;
    fxLResult      result;
}fxL4gRlsBlUsersRsp; // FLX_4G_RLS_BL_USERS_RSP

typedef struct
{
    fxLHeader      hdr;
    unsigned int   earfcn;
    unsigned int   phyCellId;
    unsigned int   layer3CellId;
    unsigned int   tac;
    fxL4gBandType  bandIndicator;
    unsigned int   bandwidth;
}fxL4gAutoConfigEarfcnInd ;//FXL_4G_AUTO_CONFIG_EARFCN_IND

typedef struct
{
    fxLHeader      hdr;
    unsigned int   tac;
}fxL4gNewConfiguredTacInd;//FXL_4G_NEW_CONFIGURED_TAC_IND

typedef struct
{
    fxLHeader    hdr;
    unsigned int dlEarfcn;
}fxL4gModifyEarfcnCmd ;//FXL_4G_MODIFY_EARFCN_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gModifyEarfcnRsp ;//FXL_4G_MODIFY_EARFCN_RSP

/***********************************************************************************/
//Command from External Client to start 4G Id Catcher.
typedef struct
{
    fxLHeader hdr;
}fxL4gStartIdCatcherCmd ;//FXL_4G_START_IDCATCHER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gStartIdCatcherRsp ;//FXL_4G_START_IDCATCHER_RSP
/***********************************************************************************/
//Command from External Client to stop 4G Id Catcher.
typedef struct
{
    fxLHeader hdr;
    int       dspResetNeeded;
}fxL4gStopIdCatcherCmd ;//FXL_4G_STOP_IDCATCHER_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gStopIdCatcherRsp ;//FXL_4G_STOP_IDCATCHER_RSP
/***********************************************************************************/
//Unsolicited / Asynchronous Indication to External Client to update the registration attempt of UE.
typedef struct
{
    fxLHeader   hdr;
    char        imsiStr[SIZE_OF_IDENTITY_STR];
    char        imeiStr[SIZE_OF_IDENTITY_STR];
    fxl4gGuti   guti;
    fxLListType listType;
    int         timingAdvance;
    int    lastTac;
    unsigned char   encodedCM2[SIZE_OF_CLASSMARK_2];
    unsigned int    lengthOfCM3;
    unsigned char   encodedCM3[SIZE_OF_CLASSMARK_3];
	unsigned char   dummy1;
	unsigned char   dummy2;
    int          lastLac;
    unsigned int emergencyCallIndication;
    float        rssi;
    float        rsrp;
    float        rsrq;
}fxL4gRegistrationAttemptedInd ;//FXL_4G_REGISTRATION_ATTEMPTED_IND
/***********************************************************************************/

/***********************************************************************************/
//Command from External Client to start Silent call in LTE

typedef enum
{
   FXL_4G_OWN_CELL_MEASUREMENT = 0,
   FXL_4G_NEIGHBOR_CELL_MEASUREMENT
}fxLLteMeasurementType;

typedef struct
{
    fxLHeader hdr;
    fxLLteMeasurementType measType;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gStartSilentCallCmd ;//FXL_4G_START_SILENT_CALL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gStartSilentCallRsp ;//FXL_4G_START_SILENT_CALL_RSP
/***********************************************************************************/
//Command from External Client to end silent call
typedef struct
{
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gEndSilentCallCmd ;//FXL_4G_END_SILENT_CALL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gEndSilentCallRsp ;//FXL_4G_END_SILENT_CALL_RSP
/***********************************************************************************/
typedef struct
{
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
    int       rsrp;
    float     rsrq;
}fxL4gMeasurementReportInd; //FXL_4G_MEASUREMENT_REPORT_IND

/***********************************************************************************/
//Command from External Client to change RF Parameters of Base-Station.
typedef struct
{
    fxLHeader hdr;
    int       TxAttenuationInDb; // Range is 0 to 359 (increment in 1/4dB) . Default Attenuation is 0.
}fxL4gIdCatcherRfModifyCmd ;//FXL_4G_IDCATCHER_RF_MODIFY_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gIdCatcherRfModifyRsp ;//FXL_4G_IDCATCHER_RF_MODIFY_RSP
/***********************************************************************************/

/***********************************************************************************/
//Command to External Client to Indicate a 4G BL UE went out of Coverage
typedef struct
{
    fxLHeader hdr;
    char      imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gBlUeOutOfCoverageInd; //FXL_4G_BL_UE_OUT_OF_COVERAGE_IND

typedef struct
{
    int  arfcn;
    fxLGsmBandIndicator  bandIndicator;
}lteGsmNeighbourCell;

typedef struct
{
    int  dlEarfcn;
    int  bandwidth;
}lteNeighbourCell;

typedef struct
{
    fxLHeader hdr;
    unsigned int        numberOfLteNeighbor;
    lteNeighbourCell    lteNeighbors[3];
    unsigned int        numberOfUmtsNeighbor;
    unsigned int        dlUarfcn[3];
    unsigned int        numberOfGsmNeighbor;
    lteGsmNeighbourCell gsmNeighbors[3];
}fxL4gConfigureNeighborCmd ;//FXL_4G_CONFIGURE_NEIGHBOR_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gConfigureNeighborRsp ;//FXL_4G_CONFIGURE_NEIGHBOR_RSP

/***********************************************************************************/
//Command from External Client to start 4G Tx Jammer.
typedef struct
{
    fxLHeader    hdr;
    unsigned int earfcn;
}fxL4gTxJammerStartCmd; //FXL_4G_TX_JAMMER_START_CMD
/***********************************************************************************/
//Response from WGS Application to External Client.
typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gTxJammerStartRsp; //FXL_4G_TX_JAMMER_START_RSP
/***********************************************************************************/
//Command from External Client to stop 4G Tx Jammer.
typedef struct
{
    fxLHeader hdr;
}fxL4gTxJammerStopCmd; //FXL_4G_TX_JAMMER_STOP_CMD
/***********************************************************************************/
//Response from WGS Application to External Client.
typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gTxJammerStopRsp; //FXL_4G_TX_JAMMER_STOP_RSP
/***********************************************************************************/
//4G Tx Jammer Status
typedef enum
{
   FXL_4G_TX_JAMMER_INITIALIZATION_FAILED,
   FXL_4G_TX_JAMMER_SCANNING_CELL,
   FXL_4G_TX_JAMMER_SCANNING_CELL_FAILED,
   FXL_4G_TX_JAMMER_CELL_FOUND,
   FXL_4G_TX_JAMMER_NO_CELL_FOUND,
   FXL_4G_TX_JAMMER_RUNNING
}fxL4gTxJammerStatus;

/***********************************************************************************/
//4G Tx Jammer Status Indication from WGS Application to External Client.
typedef struct
{
    fxLHeader            hdr;
    fxL4gTxJammerStatus  status;
    // unsigned int         numOfCells;
    unsigned int         pci;
}fxL4gTxJammerStatusInd; //FXL_4G_TX_JAMMER_STATUS_IND

/***********************************************************************************/
//Command from External Client to redirect 4G BL user
typedef struct
{
    fxLHeader                hdr;
    fxLRedirectionFrom4gType redirectionType;
    fxLRedirectionFrom4gInfo redirectionInfo;
    char                     imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gBLUeRedirectCmd; //FXL_4G_BL_UE_REDIRECT_CMD

typedef struct
{
    fxLHeader     hdr;
    fxLResult     result;
    char          imsiStr[SIZE_OF_IDENTITY_STR];
}fxL4gBLUeRedirectRsp; //FXL_4G_BL_UE_REDIRECT_RSP

/***********************************************************************************/
//Command from External Client to Configure neighbours for UE measurements(INTRA/INTER FREQ, Inter Rat)

typedef struct
{
   int                        dlEarfcn;
   int                        bandWidth;
}fxL4gUeMeasInterFreqNeighbr;

typedef struct
{
   int                        band; /* 0 - dsc1800Band, 1  - pcs1900Band*/
   int                        startingArfcn;
   int                        numArfcn;
   int                        arfcn[FXL_LTE_MAX_INTER_RAT_GSM_PER_ARFCN];
}fxL4gUeMeasInterRatGsmNeighbr;

typedef struct
{
   int                        dlUarfcn;
   int                        numPSC;
   int                        psc[FXL_LTE_MAX_INTER_RAT_PSC_PER_UARFCN];
}fxL4gUeMeasInterRatUmtsNeighbr;

typedef struct
{
   int                             enableIntraFreqMeasurement;
   int                             numInterFreqEarfcn;   
   fxL4gUeMeasInterFreqNeighbr     interFreqNeighbrList[FXL_LTE_MAX_INTER_FREQ_CELL_LIST];
   int                             numInterRatGsmNeighbr;
   fxL4gUeMeasInterRatGsmNeighbr   interRatGsmNeighbrList[FXL_LTE_MAX_INTER_RAT_GSM_CELL_LIST]; //Arry size =2
   int                             numInterRatUmtsNeighbr;
   fxL4gUeMeasInterRatUmtsNeighbr  interRatUmtsNeighbrList[FXL_LTE_MAX_INTER_RAT_UMTS_CELL_LIST];
} fxL4gUeMeasConfig;

typedef struct
{
    fxLHeader hdr;
    fxL4gUeMeasConfig  ueMeasCfg;
}fxL4gMeasurementCfgCmd;//FXL_4G_UE_MEASUREMENT_CONFIG_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL4gMeasurementCfgRsp;//FXL_4G_UE_MEASUREMENT_CONFIG_RSP

typedef enum
{
   FXL_4G_INTRA_FREQ_CELL_MEASUREMENT = 0,
   FXL_4G_INTER_FREQ_CELL_MEASUREMENT,
   FXL_4G_INTER_RAT_GSM_CELL_MEASUREMENT,
   FXL_4G_INTER_RAT_UMTS_CELL_MEASUREMENT
}fxL4GNeighourMeasType;

typedef struct
{
   int   pci;
   int   dlRsrp;
   float dlRsrq;
} fxL4gPerCellMeas;

typedef struct
{
   unsigned int          numCell;
   fxL4gPerCellMeas      perIntraCellResult[10];
}fxl4gIntraFreqMeasResult;

typedef struct
{
   unsigned int          numCell;
   unsigned int          earfcn_DL; 
   fxL4gPerCellMeas        perInterCellResult[10];
}fxl4gInterFreqMeasResult;

typedef struct
{
    int          rssi;
    unsigned int arfcn;
    unsigned int bandIndicator;
    unsigned int ncc;
    unsigned int bcc;
}fxl4gGsmPerCellMeas;

typedef struct
{
   unsigned int          numCell;
   fxl4gGsmPerCellMeas   perInterRatGsmCellResult[10];
}fxl4gInterRatGsmMeasResult;

typedef struct
{
    unsigned int   psc;
    int            rscp;
} fxl4gUmtsPerCellMeas;

typedef struct
{
   unsigned int          numCell;
   unsigned int   uarfcn_DL;
   fxl4gUmtsPerCellMeas   perInterRatUmtsCellResult[10];
}fxl4gInterRatUmtsMeasResult;

typedef struct
{
    fxLHeader     hdr;
    fxL4GNeighourMeasType measType;
    char          imsiStr[SIZE_OF_IDENTITY_STR];
    union
    {
      fxl4gIntraFreqMeasResult          intraFreqResult;
      fxl4gInterFreqMeasResult          interFreqResult;
      fxl4gInterRatGsmMeasResult    interRatGsmResult;
      fxl4gInterRatUmtsMeasResult    interRatUmtsResult;
    }u;
}fxL4gUeMeasurementReportInd; //FXL_4G_UE_MEASUREMENT_REPORT_IND

/***********************************************************************************/
//Command from External Client to control the PA on/off on 8000 board.
typedef struct
{
    fxLHeader   hdr;
    fxLObmRaVal raVal; // 0 is off, 1,2,3 different stage of amplification
}fxLObmRaRfCtrlCmd ;//FXL_OBM_RA_RF_CTRL_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxLObmRaRfCtrlRsp ;//FXL_OBM_RA_RF_CTRL_RSP
/***********************************************************************************/
//Command from External Client to get Battery Status of the Board
typedef struct
{
    fxLHeader     hdr;
}fxLObmBatteryStatusCmd;                    // FXL_OBM_BATTERY_STATUS_CMD 
typedef struct
{
    fxLHeader     hdr;
    fxLResult     result;
    unsigned int  boardId;
    unsigned int  batteryId;
    unsigned int  batteryPowerLevel;
    unsigned int  batteryChargingFlag;   // 0 is No Charging for Battery, else Charging is On
    unsigned int  batteryFaultFlag;      // 0 is No fault in Battery, else Battery fault is present
    unsigned int  batteryTempFaultFlag;  // 0 No fault for Temparature, else fault is there due to Temprature 
    unsigned int  batteryLowWaringFlag;  // 0 No Battery Low Warning, else Battery Low Warning is present
}fxLObmBatteryStatusRsp;                     // FXL_OBM_BATTERY_STATUS_RSP
/***********************************************************************************/
//Command from External Client to Switch Off the Board
typedef struct
{
    fxLHeader     hdr;
}fxLObmSwitchOffBoardCmd; //FXL_OBM_SWITCH_OFF_BOARD_CMD
/***********************************************************************************/
//Command from External Client to get tempreture Status of the Board

typedef struct
{
        fxLHeader     hdr;
}fxLObmTemperatureStatusCmd;                    // FXL_OBM_TEMPERATURE_STATUS_CMD 

typedef struct
{
        fxLHeader     hdr;
        fxLResult     result;
        float         dspTemperature;
        float         rfTemperature;
}fxLObmTemperatureStatusRsp;                    // FXL_OBM_TEMPERATURE_STATUS_RSP

/***********************************************************************************
 * Command from External Client to configure Bands for scanning in Bass Mode */
typedef struct
{
    fxLHeader     hdr;
    int           noOfBandsToScan;
    fxL2gBandType band[GSM_MAX_BANDS_TO_SCAN]; // Maximum bands can be scan as 7
}fxL2gBassModeConfigureBandsCmd ;//FXL_2G_BASS_MODE_CONFIGURE_BANDS_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gBassModeConfigureBandsRsp ;//FXL_2G_BASS_MODE_CONFIGURE_BANDS_RSP

/***********************************************************************************
 * Command from External Client to start scanning in Bass Mode. */
typedef struct
{
    fxLHeader   hdr;
}fxL2gBassModeStartCmd ;//FXL_2G_BASS_MODE_START_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gBassModeStartRsp ;//FXL_2G_BASS_MODE_START_RSP

/***********************************************************************************
* Command from External Client to stop scanning in Listen Mode */
typedef struct
{
   fxLHeader hdr;
}fxL2gBassModeStopCmd ;//FXL_2G_BASS_MODE_STOP_CMD

typedef struct
{
    fxLHeader hdr;
    fxLResult result;
}fxL2gBassModeStopRsp ;//FXL_2G_BASS_MODE_STOP_RSP

typedef struct
{
    fxLHeader       hdr;
    int             arfcn;
    fxL2gBandType   band;
    float           snr;
}fxL2gBassModeSyncCellInfoInd ;//FXL_2G_BASS_MODE_SYNC_CELL_INFO_IND

typedef struct
{
    fxLHeader hdr;
}fxL2gBassModeCompleteInd ; //FXL_2G_BASS_MODE_COMPLETE_IND

#endif //FXLYNXSOCKETINTERFACEAPI_H_
