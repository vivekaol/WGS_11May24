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
 * File Name   : asnApi.h 
 *
 * Description : This file provides the filling & encoding of RRC ASN1 interface 
 *               to IMSI Catcher application.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 12/09/2014	        Ashutosh Samal              File Creation
 *############################################################################
*/

#ifndef __ASN_API_H__
#define __ASN_API_H__

/*
 * Defines
 */
#define   CELL_IDENTITY_SIZE               28

#define   SIB_TYPEANDTAG_SYSINFOTYPE1      0
#define   SIB_TYPEANDTAG_SYSINFOTYPE2      1
#define   SIB_TYPEANDTAG_SYSINFOTYPE3      2
#define   SIB_TYPEANDTAG_SYSINFOTYPE4      3
#define   SIB_TYPEANDTAG_SYSINFOTYPE5      4
#define   SIB_TYPEANDTAG_SYSINFOTYPE6      5
#define   SIB_TYPEANDTAG_SYSINFOTYPE7      6
#define   SIB_TYPEANDTAG_SYSINFOTYPE8      7
#define   SIB_TYPEANDTAG_SYSINFOTYPE9      8
#define   SIB_TYPEANDTAG_SYSINFOTYPE10     9
#define   SIB_TYPEANDTAG_SYSINFOTYPE11     10
#define   SIB_TYPEANDTAG_SYSINFOTYPE12     11
#define   SIB_TYPEANDTAG_SYSINFOTYPE13     12
#define   SIB_TYPEANDTAG_SYSINFOTYPE13_1   13
#define   SIB_TYPEANDTAG_SYSINFOTYPE13_2   14
#define   SIB_TYPEANDTAG_SYSINFOTYPE13_3   15
#define   SIB_TYPEANDTAG_SYSINFOTYPE13_4   16
#define   SIB_TYPEANDTAG_SYSINFOTYPE14     17
#define   SIB_TYPEANDTAG_SYSINFOTYPE15     18
#define   SIB_TYPEANDTAG_SYSINFOTYPE16     19
#define   SIB_TYPEANDTAG_SYSINFOTYPE17     20
#define   SIB_TYPEANDTAG_SYSINFOTYPESB1    21
#define   SIB_TYPEANDTAG_SYSINFOTYPESB2    22

#define   SIB_SCHEDULING_POS_REP4            0
#define   SIB_SCHEDULING_POS_REP8            1
#define   SIB_SCHEDULING_POS_REP16           2
#define   SIB_SCHEDULING_POS_REP32           3
#define   SIB_SCHEDULING_POS_REP64           4
#define   SIB_SCHEDULING_POS_REP128          5
#define   SIB_SCHEDULING_POS_REP256          6
#define   SIB_SCHEDULING_POS_REP512          7
#define   SIB_SCHEDULING_POS_REP1024         8
#define   SIB_SCHEDULING_POS_REP2048         9
#define   SIB_SCHEDULING_POS_REP4096         10

#define   CN_DOMAIN_IDENTITY_CS              0
#define   CN_DOMAIN_IDENTITY_PS              1

#define   SIB_TYPE1_CN_TYPE_GSM_MAP          0
#define   SIB_TYPE1_CN_TYPE_ANSI_41          1

#define   SIB_TYPE1_UE_IDLE_TIMER_T300_100_MS     0
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_200_MS     1
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_400_MS     2
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_600_MS     3
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_800_MS     4
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_1000_MS    5
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_1200_MS    6
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_1400_MS    7
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_1600_MS    8
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_1800_MS    9
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_2000_MS    10
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_3000_MS    11
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_4000_MS    12
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_6000_MS    13
#define   SIB_TYPE1_UE_IDLE_TIMER_T300_8000_MS    14

#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S1         0
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S50        1
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S100       2
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S200       3
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S400       4
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S600       5
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S800       6
#define   SIB_TYPE1_UE_IDLE_TIMER_N312_S1000      7

#define   SIB_TYPE1_UE_CONN_TIMER_T301_100_MS     0
#define   SIB_TYPE1_UE_CONN_TIMER_T301_200_MS     1
#define   SIB_TYPE1_UE_CONN_TIMER_T301_400_MS     2
#define   SIB_TYPE1_UE_CONN_TIMER_T301_600_MS     3
#define   SIB_TYPE1_UE_CONN_TIMER_T301_800_MS     4
#define   SIB_TYPE1_UE_CONN_TIMER_T301_1000_MS    5
#define   SIB_TYPE1_UE_CONN_TIMER_T301_1200_MS    6
#define   SIB_TYPE1_UE_CONN_TIMER_T301_1400_MS    7
#define   SIB_TYPE1_UE_CONN_TIMER_T301_1600_MS    8
#define   SIB_TYPE1_UE_CONN_TIMER_T301_1800_MS    9
#define   SIB_TYPE1_UE_CONN_TIMER_T301_2000_MS    10
#define   SIB_TYPE1_UE_CONN_TIMER_T301_3000_MS    11
#define   SIB_TYPE1_UE_CONN_TIMER_T301_4000_MS    12
#define   SIB_TYPE1_UE_CONN_TIMER_T301_6000_MS    13
#define   SIB_TYPE1_UE_CONN_TIMER_T301_8000_MS    14
#define   SIB_TYPE1_UE_CONN_TIMER_T301_SPARE      15

#define   SIB_TYPE1_UE_CONN_TIMER_T302_100_MS     0
#define   SIB_TYPE1_UE_CONN_TIMER_T302_200_MS     1
#define   SIB_TYPE1_UE_CONN_TIMER_T302_400_MS     2
#define   SIB_TYPE1_UE_CONN_TIMER_T302_600_MS     3
#define   SIB_TYPE1_UE_CONN_TIMER_T302_800_MS     4
#define   SIB_TYPE1_UE_CONN_TIMER_T302_1000_MS    5
#define   SIB_TYPE1_UE_CONN_TIMER_T302_1200_MS    6
#define   SIB_TYPE1_UE_CONN_TIMER_T302_1400_MS    7
#define   SIB_TYPE1_UE_CONN_TIMER_T302_1600_MS    8
#define   SIB_TYPE1_UE_CONN_TIMER_T302_1800_MS    9
#define   SIB_TYPE1_UE_CONN_TIMER_T302_2000_MS    10
#define   SIB_TYPE1_UE_CONN_TIMER_T302_3000_MS    11
#define   SIB_TYPE1_UE_CONN_TIMER_T302_4000_MS    12
#define   SIB_TYPE1_UE_CONN_TIMER_T302_6000_MS    13
#define   SIB_TYPE1_UE_CONN_TIMER_T302_8000_MS    14
#define   SIB_TYPE1_UE_CONN_TIMER_T302_SPARE      15

#define   SIB_TYPE1_UE_CONN_TIMER_T304_100_MS     0
#define   SIB_TYPE1_UE_CONN_TIMER_T304_200_MS     1
#define   SIB_TYPE1_UE_CONN_TIMER_T304_400_MS     2
#define   SIB_TYPE1_UE_CONN_TIMER_T304_1000_MS    3
#define   SIB_TYPE1_UE_CONN_TIMER_T304_2000_MS    4
#define   SIB_TYPE1_UE_CONN_TIMER_T304_SPARE3     5
#define   SIB_TYPE1_UE_CONN_TIMER_T304_SPARE2     6
#define   SIB_TYPE1_UE_CONN_TIMER_T304_SPARE1     7

#define   SIB_TYPE1_UE_CONN_TIMER_T305_NO_UPDATE  0
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M5         1
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M10        2
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M30        3
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M60        4
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M120       5
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M360       6
#define   SIB_TYPE1_UE_CONN_TIMER_T305_M720       7

#define   SIB_TYPE1_UE_CONN_TIMER_T307_S5         0
#define   SIB_TYPE1_UE_CONN_TIMER_T307_S10        1
#define   SIB_TYPE1_UE_CONN_TIMER_T307_S15        2
#define   SIB_TYPE1_UE_CONN_TIMER_T307_S20        3
#define   SIB_TYPE1_UE_CONN_TIMER_T307_S30        4
#define   SIB_TYPE1_UE_CONN_TIMER_T307_S40        5
#define   SIB_TYPE1_UE_CONN_TIMER_T307_S50        6
#define   SIB_TYPE1_UE_CONN_TIMER_T307_SPARE      7

#define   SIB_TYPE1_UE_CONN_TIMER_T308_40_MS      0
#define   SIB_TYPE1_UE_CONN_TIMER_T308_80_MS      1
#define   SIB_TYPE1_UE_CONN_TIMER_T308_160_MS     2
#define   SIB_TYPE1_UE_CONN_TIMER_T308_320_MS     3

#define   SIB_TYPE1_UE_CONN_TIMER_T310_40_MS      0
#define   SIB_TYPE1_UE_CONN_TIMER_T310_80_MS      1
#define   SIB_TYPE1_UE_CONN_TIMER_T310_120_MS     2
#define   SIB_TYPE1_UE_CONN_TIMER_T310_160_MS     3
#define   SIB_TYPE1_UE_CONN_TIMER_T310_200_MS     4
#define   SIB_TYPE1_UE_CONN_TIMER_T310_240_MS     5
#define   SIB_TYPE1_UE_CONN_TIMER_T310_280_MS     6
#define   SIB_TYPE1_UE_CONN_TIMER_T310_320_MS     7

#define   SIB_TYPE1_UE_CONN_TIMER_T311_250_MS     0
#define   SIB_TYPE1_UE_CONN_TIMER_T311_500_MS     1
#define   SIB_TYPE1_UE_CONN_TIMER_T311_750_MS     2
#define   SIB_TYPE1_UE_CONN_TIMER_T311_1000_MS    3
#define   SIB_TYPE1_UE_CONN_TIMER_T311_1250_MS    4
#define   SIB_TYPE1_UE_CONN_TIMER_T311_1500_MS    5
#define   SIB_TYPE1_UE_CONN_TIMER_T311_1750_MS    6
#define   SIB_TYPE1_UE_CONN_TIMER_T311_2000_MS    7

#define   SIB_TYPE1_UE_CONN_TIMER_T314_S0         0
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S2         1
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S4         2
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S6         3
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S8         4
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S12        5
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S16        6
#define   SIB_TYPE1_UE_CONN_TIMER_T314_S20        7

#define   SIB_TYPE1_UE_CONN_TIMER_T315_S0         0
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S10        1
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S30        2
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S60        3
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S180       4
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S600       5
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S1200      6
#define   SIB_TYPE1_UE_CONN_TIMER_T315_S1800      7

#define   SIB_TYPE1_UE_CONN_TIMER_T316_S0         0
#define   SIB_TYPE1_UE_CONN_TIMER_T316_S10        1
#define   SIB_TYPE1_UE_CONN_TIMER_T316_S20        2
#define   SIB_TYPE1_UE_CONN_TIMER_T316_S30        3
#define   SIB_TYPE1_UE_CONN_TIMER_T316_S40        4
#define   SIB_TYPE1_UE_CONN_TIMER_T316_S50        5
#define   SIB_TYPE1_UE_CONN_TIMER_T316_INF        6
#define   SIB_TYPE1_UE_CONN_TIMER_T316_SPARE      7

#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY0  0
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY1  1
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY2  2
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY3  3
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY4  4
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY5  5
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY6  6
#define   SIB_TYPE1_UE_CONN_TIMER_T317_INFINITY7  7

#define   SIB_TYPE1_UE_CONN_TIMER_N312_S1         0
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S50        1
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S100       2
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S200       3
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S400       4
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S600       5
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S800       6
#define   SIB_TYPE1_UE_CONN_TIMER_N312_S1000      7

#define   SIB_TYPE1_UE_CONN_TIMER_N313_S1         0
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S2         1
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S4         2
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S10        3
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S20        4
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S50        5
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S100       6
#define   SIB_TYPE1_UE_CONN_TIMER_N313_S200       7

#define   SIB_TYPE1_UE_CONN_TIMER_N315_S1         0
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S50        1
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S100       2
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S200       3
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S400       4
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S600       5
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S800       6
#define   SIB_TYPE1_UE_CONN_TIMER_N315_S1000      7

#define   SIB_TYPE3_CELL_SELECT_QUALITY_MEASURE_CPICH_ECNO 0
#define   SIB_TYPE3_CELL_SELECT_QUALITY_MEASURE_CPICH_RSCP 1

#define   ACCESS_CLASS_BARRED                     0
#define   ACCESS_CLASS_NOT_BARRED                 1

#define   SIB_TYPE5_PRACH_RACH_AVAILABLE_SF_PR32    0
#define   SIB_TYPE5_PRACH_RACH_AVAILABLE_SF_PR64    1
#define   SIB_TYPE5_PRACH_RACH_AVAILABLE_SF_PR128   2
#define   SIB_TYPE5_PRACH_RACH_AVAILABLE_SF_PR256   3

#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_40    0
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_44    1
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_48    2
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_52    3
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_56    4
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_60    5
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_64    6
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_68    7
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_72    8
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_76    9
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_80    10
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_84    11
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_88    12
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_92    13
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL0_96    14
#define   SIB_TYPE5_PRACH_RACH_PUNCTURING_LIMIT_PL1       15

#define   SIB_TYPE5_RACH_SUB_CHANNEL_SIZE                 12

#define   SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_10_MS    0
#define   SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_20_MS    1
#define   SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_30_MS    2
#define   SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_40_MS    3
#define   SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_80_MS    4
#define   SIB_TYPE5_COMMON_TRANSPORT_CHANNEL_TTI_DYNAMIC  5

#define   SIB_TYPE5_OCTET_MODE_RLC_SIZE_INFO_TYPE2_TYPE1  0
#define   SIB_TYPE5_OCTET_MODE_RLC_SIZE_INFO_TYPE2_TYPE2  1
#define   SIB_TYPE5_OCTET_MODE_RLC_SIZE_INFO_TYPE2_TYPE3  2

#define   SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ZERO       0
#define   SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_ONE        1
#define   SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_SMALL      2
#define   SIB_TYPE5_NUMBER_OF_TRANSPORT_BLOCKS_LARGE      3

#define   SIB_TYPE5_LOGICAL_CHANNEL_LIST_ALL_SIZES        0
#define   SIB_TYPE5_LOGICAL_CHANNEL_LIST_CONFIGURED       1

#define   SIB_TYPE5_LOGICAL_CHANNEL_CODING_TYPE_NOCODING       0
#define   SIB_TYPE5_LOGICAL_CHANNEL_CODING_TYPE_CONVOLUTIONAL  1
#define   SIB_TYPE5_LOGICAL_CHANNEL_CODING_TYPE_TURBO          2

#define   SIB_TYPE5_CHANNEL_CODING_RATE_HALF              0
#define   SIB_TYPE5_CHANNEL_CODING_RATE_THIRD             1

#define   SIB_TYPE5_CRC_SIZE_CRC0                         0
#define   SIB_TYPE5_CRC_SIZE_CRC8                         1
#define   SIB_TYPE5_CRC_SIZE_CRC12                        2
#define   SIB_TYPE5_CRC_SIZE_CRC16                        3
#define   SIB_TYPE5_CRC_SIZE_CRC24                        4

#define   SIB_TYPE5_TFCS_CONFIGURATION_TYPE_COMPLETE      0

#define   SIB_TYPE5_CTFC_SIZE_2BIT                        0

#define   SIB_TYPE5_GAIN_FACTOR_SIGNALLED                 0

#define   MAX_SUBCHANNEL_NUMBER                           4

#define   MAX_ACtoASC_MAPPING                             7

#define   SIB_TYPE5_SF_256_CODE_NUMBER_SF64               4

#define   SIB_TYPE5_SCCPCH_POSITION_FLEXIBLE              1

#define   SIB_TYPE5_CTFC_SIZE_4BIT                        1

#define   SIB_TYPE5_RLC_SIZE_TYPE1                        0
#define   SIB_TYPE5_RLC_SIZE_TYPE2                        1
#define   SIB_TYPE5_RLC_SIZE_TYPE3                        2

#define   BCH_PAYLOAD_NO_SEGMENT                          0
#define   BCH_PAYLOAD_FIRST_SEGMENT                       1
#define   BCH_PAYLOAD_SUBSEQUENT_SEGMENT                  2
#define   BCH_PAYLOAD_LAST_SEGMENT_SHORT                  3
#define   BCH_PAYLOAD_LAST_AND_FIRST                      4
#define   BCH_PAYLOAD_LAST_AND_COMPLETE                   5
#define   BCH_PAYLOAD_LAST_AND_COMPLETE_AND_FIRST         6
#define   BCH_PAYLOAD_COMPLETE_SIB_LIST                   7
#define   BCH_PAYLOAD_COMPLETE_AND_FIRST                  8
#define   BCH_PAYLOAD_COMPLETE_SIB                        9
#define   BCH_PAYLOAD_LAST_SEGMENT                        10

#define   SIB_TYPE_NONE                                  -1
#define   MASTER_INFORMATION_BLOCK                        0
#define   SYSTEM_INFORMATION_TYPE1                        1
#define   SYSTEM_INFORMATION_TYPE2                        2
#define   SYSTEM_INFORMATION_TYPE3                        3
#define   SYSTEM_INFORMATION_TYPE4                        4
#define   SYSTEM_INFORMATION_TYPE5                        5
#define   SYSTEM_INFORMATION_TYPE6                        6
#define   SYSTEM_INFORMATION_TYPE7                        7
#define   SYSTEM_INFORMATION_TYPE_DUMMY1                  8
#define   SYSTEM_INFORMATION_TYPE_DUMMY2                  9
#define   SYSTEM_INFORMATION_TYPE_DUMMY3                  10
#define   SYSTEM_INFORMATION_TYPE11                       11
#define   SYSTEM_INFORMATION_TYPE12                       12
#define   SYSTEM_INFORMATION_TYPE13                       13
#define   SYSTEM_INFORMATION_TYPE13_1                     14
#define   SYSTEM_INFORMATION_TYPE13_2                     15
#define   SYSTEM_INFORMATION_TYPE13_3                     16
#define   SYSTEM_INFORMATION_TYPE13_4                     17
#define   SYSTEM_INFORMATION_TYPE14                       18
#define   SYSTEM_INFORMATION_TYPE15                       19

#define   MAX_SFN                                         64
#define   NONE                                            0xFF

/*
 * UL CCCH Message
 */
#define UL_CCCH_MSG_TYPE_NONE                            -1
#define UL_CCCH_MSG_TYPE_CELL_UPDATE                      0
#define UL_CCCH_MSG_TYPE_RRC_CONNECTION_REQ               1
#define UL_CCCH_MSG_TYPE_URA_UPDATE                       2
#define UL_CCCH_MSG_TYPE_R11                              3

/*
 * UL DCCH Message
 */
#define UL_DCCH_MSG_TYPE_NONE                            -1
#define UL_DCCH_MSG_TYPE_IDT                              5
#define UL_DCCH_MSG_TYPE_MEASUREMENT_REPORT               8
#define UL_DCCH_MSG_TYPE_RRC_CONN_REL_COMP                17
#define UL_DCCH_MSG_TYPE_RRC_CONN_SETUP_COMP              18
#define UL_DCCH_MSG_TYPE_UL_DIRECT_TRANSFER               27

#define UE_IDENTITY_IMSI                                  0
#define UE_IDENTITY_TMSI_AND_LAI                          1
#define UE_IDENTITY_PTMSI_AND_RAI                         2
#define UE_IDENTITY_IMEI                                  3
#define UE_IDENTITY_ESN_DS_41                             4
#define UE_IDENTITY_IMSI_DS_41                            5
#define UE_IDENTITY_IMSI_AND_ESN_DS_41                    6
#define UE_IDENTITY_TMSI_DS_41                            7

#define MAX_IMSI_LENGTH                                   15
#define MAX_IMEI_LENGTH                                   15
#define MAX_TMSI_LENGTH                                   4
#define MAX_PTMSI_LENGTH                                  4
#define MAX_LAC_LENGTH                                    2
#define MAX_MCC_LENGTH                                    3
#define MAX_MNC_LENGTH                                    3


/*
 * Return code for ASN API
 */
typedef enum
{
   ASN_SUCCESS,
   ASN_FAILURE
}ASNRetCode_t;

/*
 * BCCH BCH Data
 */
typedef struct bcchBchData
{
   int    sfn; 
   int    sibType;
   int    payloadType;
   int    segCount;
   int    segIdx;
   int    payloadLen;
   char   *payload; 
}BcchBchData_t;

/*
 * SIB Payload
 */
typedef struct sibPayload
{
   int           sibType;
   int           sibSegCount;
   int           sibSegIndex;
   unsigned char sibData[32];
}SibPayload_t;

/*
 * BCCH BCH Decode Data
 */
typedef struct bcchBchDecodeData
{
   int          sfn;
   int          decodedDataLen;
   int          sibSegmentType;
   int          numOfSib;
   SibPayload_t sibPayload[30];
}BcchBchDecodeData_t;

/*
 * Initial UE Identity
 */
typedef struct rrcInitialUEIdentity
{
   int  initialUEIdentityType;
   int  imsiLength;
   int  imeiLength;
   int  mccLength;
   int  mncLength;
   char imsi[MAX_IMSI_LENGTH];
   char imei[MAX_IMEI_LENGTH];
   char lac[MAX_LAC_LENGTH];
   char tmsi[MAX_TMSI_LENGTH];
   char ptmsi[MAX_PTMSI_LENGTH];
   char mcc[MAX_MCC_LENGTH];
   char mnc[MAX_MNC_LENGTH];
   char rac;
   char used;
}RrcInitialUEIdentity;

#define MAX_SRB_PER_UE                                    4
#define VALUE_NOT_PRESENT                                 0
#define VALUE_PRESENT                                     1
#define RLC_INFO_CHOICE_RLC_INFO                          0
#define RLC_INFO_CHOICE_SAME_AS_RB                        1
#define UL_AM_RLC_MODE                                    0
#define UL_UM_RLC_MODE                                    1
#define UL_TM_RLC_MODE                                    2
#define UL_RLC_MODE_SPARE                                 3
#define TRANSMISSION_RLC_DISCARD_TIMER_BASED_EXPLICIT     0
#define TRANSMISSION_RLC_DISCARD_TIMER_BASED_NO_EXPLICIT  1
#define TRANSMISSION_RLC_DISCARD_MAX_DAT_RETRANSMISSIONS  2
#define TRANSMISSION_RLC_DISCARD_NO_DISCARD               3
#define MAX_DAT_DAT1                                      0
#define MAX_DAT_DAT2                                      1
#define MAX_DAT_DAT3                                      2
#define MAX_DAT_DAT4                                      3
#define MAX_DAT_DAT5                                      4
#define MAX_DAT_DAT6                                      5
#define MAX_DAT_DAT7                                      6
#define MAX_DAT_DAT8                                      7
#define MAX_DAT_DAT9                                      8
#define MAX_DAT_DAT10                                     9
#define MAX_DAT_DAT15                                     10
#define MAX_DAT_DAT20                                     11
#define MAX_DAT_DAT25                                     12
#define MAX_DAT_DAT30                                     13
#define MAX_DAT_DAT35                                     14
#define MAX_DAT_DAT40                                     15
#define TRANSMISSION_WINDOW_SIZE_TW1                      0
#define TRANSMISSION_WINDOW_SIZE_TW8                      1
#define TRANSMISSION_WINDOW_SIZE_TW16                     2
#define TRANSMISSION_WINDOW_SIZE_TW32                     3
#define TRANSMISSION_WINDOW_SIZE_TW64                     4
#define TRANSMISSION_WINDOW_SIZE_TW128                    5
#define TRANSMISSION_WINDOW_SIZE_TW256                    6
#define TRANSMISSION_WINDOW_SIZE_TW512                    7
#define TRANSMISSION_WINDOW_SIZE_TW768                    8
#define TRANSMISSION_WINDOW_SIZE_TW1024                   9
#define TRANSMISSION_WINDOW_SIZE_TW1536                   10
#define TRANSMISSION_WINDOW_SIZE_TW2047                   11
#define TRANSMISSION_WINDOW_SIZE_TW2560                   12
#define TRANSMISSION_WINDOW_SIZE_TW3072                   13
#define TRANSMISSION_WINDOW_SIZE_TW3584                   14
#define TRANSMISSION_WINDOW_SIZE_TW4095                   15
#define TIMER_RESET_TR300                                 5
#define TIMER_POLL_TP150                                  14
#define POLL_PDU_PDU4                                     2
#define POLL_SDU_SDU1                                     0
#define POLL_WINDOW_PW70                                  2
#define DL_AM_RLC_MODE                                    0
#define DL_UM_RLC_MODE                                    1
#define DL_TM_RLC_MODE                                    2
#define RECIEVING_WINDOW_SIZE_RW32                        3
#define TFCS_NORMAL_TFCI_SIGNALLING                       0

#define TFCS_CONFIGURATION_COMPLETE                       0
#define TFCS_CONFIGURATION_ADDITION                       1
#define TFCS_CONFIGURATION_REMOVAL                        2
#define TFCS_CONFIGURATION_REPLACEMENT                    3
#define CTFC_SIZE_2BIT                                    0
#define CTFC_SIZE_4BIT                                    1
#define CTFC_SIZE_6BIT                                    2
#define CTFC_SIZE_8BIT                                    3
#define CTFC_SIZE_12BIT                                   4
#define CTFC_SIZE_16BIT                                   5
#define CTFC_SIZE_24BIT                                   6
#define MAX_CTFC2                                         2
#define MAX_RB_MAPPING_INFO                               2
#define UL_LOGICAL_CHANNEL_MAPPING_ONE                    0
#define UL_LOGICAL_CHANNEL_MAPPING_TWO                    1
#define UL_TRANSPORT_CHANNEL_TYPE_DCH                     0
#define UL_TRANSPORT_CHANNEL_TYPE_RACH                    1
#define UL_TRANSPORT_CHANNEL_TYPE_DUMMY                   2
#define UL_TRANSPORT_CHANNEL_TYPE_USCH                    3
#define RLC_SIZE_LIST_ALL_SIZES                           0
#define RLC_SIZE_LIST_CONFIGURED                          1
#define RLC_SIZE_LIST_EXPLICIT_LIST                       2
#define MAX_TB_SIZE_LIST                                  2
#define DL_TRANSPORT_CHANNEL_TYPE_DCH                     0
#define DL_TRANSPORT_CHANNEL_TYPE_FACH                    1
#define SIGNALED_GAIN_FACTOR                              0
#define RRC_STATE_INDICATOR_CELL_DCH                      0
#define RRC_STATE_INDICATOR_CELL_FACH                     1
#define RRC_STATE_INDICATOR_CELL_PCH                      2
#define RRC_STATE_INDICATOR_URA_PCH                       3
#define DEDICATED_TRANSPORT_CHANNEL_TFS                   0
#define DEDICATED_TRANSPORT_CHANNEL_TFS_TTI40             2
#define RLC_SIZE_OCTET_MODE_TYPE1                         1
#define OCTET_MODE_RLC_SIZE_TYPE1                         0
#define NUMBER_OF_TRANSPORT_BLOCKS_ZERO                   0
#define NUMBER_OF_TRANSPORT_BLOCKS_ONE                    1
#define LOGICAL_CHANNEL_LIST_ALL_SIZES                    0
#define CRC_SIZE_CRC16                                    3
#define CODING_RATE_THIRD                                 1
#define CHANNEL_CODING_TYPE_CONVOLUTIONAL                 1
#define DL_PARAMETERS_SAME_AS_UL                          1
#define TFS_SIGNALLING_EXPLICIT_CONFIG                    0
#define TRANSPORT_FORMAT_SET_DEDICATED                    0
#define UL_CHANNEL_REQUIREMENT_DPCH_INFO                  0
#define POWER_CONTROL_ALGORITHM1                          0
#define SCRAMBLING_CODE_LONG_SC                           1
#define SPREADING_FACTOR_SF256                            6
#define CFN_HANDLING_MAINTAIN                             0
#define PILOT_BITS256_PB4                                 1
#define POSITION_FIXED                                    0
#define SPREADING_FACTOR_AND_PILOT_SFD256                 6
#define PCPICH_USAGE_MAY_BE_USED                          0
#define MAX_RESET_4                                       1

/*
 * SRB RB Mapping Info
 */
typedef struct rrcSrbRbMappingInfo
{
   unsigned int        ulLogicalChannelMappingsPresence;
   unsigned int        ulLogicalChannelMappingType;
   unsigned int        ulTransportChannelType; 
   unsigned int        ulTransportChannelDch;
   unsigned int        logicalChannelIdentityPresence;
   unsigned int        logicalChannelIdentity;
   unsigned int        rlcSizeListType; 
   unsigned int        numOfRlcSizeExplicitList;
   unsigned int        rlcSizeIndex;
   unsigned int        macLogicalChannelPriority;
   unsigned int        dlLogicalChannelMappingsPresence;
   unsigned int        numOfDlLogicalCahnnelMappings;
   unsigned int        dlTransportChannelType;
   unsigned int        dlTransportChannelDch;
   unsigned int        dlLogicalChannelIdPresence;
   unsigned int        dlLogicalChannelId;
}RrcSrbRbMappingInfo;

/*
 * SRB Info
 */
typedef struct rrcSrbInfo
{
   unsigned int         rbIdPresence;
   unsigned int         rbId;
   unsigned int         rlcInfoType;
   unsigned int         ulRlcModePresence;
   unsigned int         ulRlcModeType;
   unsigned int         ulAmRlcModeTransmitDiscardType;
   unsigned int         ulAmRlcModeTransmitDiscardValue;
   unsigned int         ulAmRlcModeTransmitWindowSize;
   unsigned int         ulAmRlcModeTimerReset;
   unsigned int         ulAmRlcModeMaxReset;
   unsigned int         ulAmRlcModePollingInfoPresence;
   unsigned int         ulAmRlcModeTimerPollProhibitPresence;
   unsigned int         ulAmRlcModeTimerPollProhibit;
   unsigned int         ulAmRlcModeTimerPollPresence;
   unsigned int         ulAmRlcModeTimerPoll;
   unsigned int         ulAmRlcModePollPDUPresence;
   unsigned int         ulAmRlcModePollPDU;
   unsigned int         ulAmRlcModePollSDUPresence;
   unsigned int         ulAmRlcModePollSDU;
   unsigned int         ulAmRlcModeLastTransmissionPDUPoll;
   unsigned int         ulAmRlcModeLastRetransmissionPDUPoll;
   unsigned int         ulAmRlcPollWindowPresence;
   unsigned int         ulAmRlcPollWindow;
   unsigned int         ulAmRlcTimerPollPeriodicPresence;
   unsigned int         ulAmRlcTimerPollPeriodic;
   unsigned int         dlRlcModePresence;
   unsigned int         dlRlcModeType;
   unsigned int         dlAmRlcModeInSequenceDelivery;
   unsigned int         dlAmRlcModeReceivingWindowSize;
   unsigned int         dlAmRlcModeTimerStatusProhibitPresence;
   unsigned int         dlAmRlcModeTimerStatusProhibit;
   unsigned int         dlAmRlcModeDummyPresence;
   unsigned int         dlAmRlcModeDummy;
   unsigned int         dlAmRlcModeMissingPDUIndicator;
   unsigned int         dlAmRlcModeTimerStatusPeriodicPresence;
   unsigned int         dlAmRlcModeTimerStatusPeriodic;
   unsigned int         numOfRBMappingInfo;
   RrcSrbRbMappingInfo  rbMappingInfo[MAX_RB_MAPPING_INFO];
}RrcSrbInfo;

/*
 * URNTI
 */
typedef struct rrcURNTI
{
   unsigned int    sRNCIdentityLength;
   unsigned int    sRNCIdentityValue;
   unsigned int    sRNTILength;
   unsigned int    sRNTIValue;
}RrcURNTI;

/*
 * Capability Update Requirement
 */
typedef struct rrcCapabilityUpdateRequirement
{
   unsigned int    ueRadioCapabilityFDDUpdateRequirement;
   unsigned int    ueRadioCapabilityTDDUpdateRequirement; 
   unsigned int    systemSpecificCapUpdateReqListPresence;
   unsigned int    numOfSystemSpecificCapUpdateReqList;
}RrcCapabilityUpdateRequirement;

/*
 * CTFC 2 BIT
 */
typedef struct rrcCtfc2Bit
{
   unsigned int     ctfc2;
   unsigned int     powerOffsetInformationPresence;   
   unsigned int     gainFactorInformationType;
   unsigned int     gainFactorBetaC;
   unsigned int     gainFactorBetaD; 
   unsigned int     powerOffsetPpmPresence;
   unsigned int     powerOffsetPpm;
}RrcCtfc2Bit;

/*
 * UL Common Transport Channel Information
 */
typedef struct rrcUlCommonTransChInfo
{
   unsigned int     modeSpecificInfoPresence;
   unsigned int     tfcsType;
   unsigned int     tfcsConfigurationType;
   unsigned int     ctfcSizeType;
   unsigned int     numOfCtfc2Bit;
   RrcCtfc2Bit      ctfc2Bit[MAX_CTFC2];   
}RrcUlCommonTransChInfo;

/*
 * TB Size List
 */
typedef struct rrcTbSizeList
{
    unsigned int     numberOfTransportBlocksType;
    unsigned int     transportBlockvalue;
}RrcTbSizeList;

/*
 * TTI 40
 */
typedef struct rrcTti40
{
   unsigned int         rlcSizeType;
   unsigned int         octectModeType;
   unsigned int         sizeType1;
   unsigned int         numOfTbSizeList;
   RrcTbSizeList        tbSizeList[MAX_TB_SIZE_LIST];
   unsigned int         logicalChannelListType;
}RrcTti40;

/*
 * Semistatic TF Information
 */
typedef struct rrcSemistaticTFInfo
{
   unsigned int        channelCodingType;
   unsigned int        codingRateType;
   unsigned int        rateMatchingAttribute;
   unsigned int        crcSize;
}RrcSemistaticTFInfo;

/*
 * Dedicated Transport Channel Information
 */
typedef struct rrcDedicatedTransChTfs
{
   unsigned int          ttiType;
   unsigned int          numOfTti40;
   RrcTti40              tti40;
   RrcSemistaticTFInfo   semistaticTFInfo;         
}RrcDedicatedTransChTfs;

/*
 * UL ADD Reconfig Transport Channel Info List
 */
typedef struct rrcUlAddReconfTransChInfoList
{
   unsigned int           numOfUlAddReconfTransChInfo;
   unsigned int           ulTransportChannelType;
   unsigned int           transportChannelIdentity;
   unsigned int           transportFormatSetType;
   RrcDedicatedTransChTfs dedicatedTransChInfo; 
}RrcUlAddReconfTransChInfoList;

/*
 * RRC DL Common Transport Channel Info
 */
typedef struct rrcDlCommonTransChInfo
{
    unsigned int         dlParametersType;
}RrcDlCommonTransChInfo;

/*
 * RRC DL COMMON Transport Channel Info
 */
typedef struct rrcDlAddReconfTransChInfoList
{
   unsigned int           numOfDlAddReconfTransChInfoList;
   unsigned int           dlTransportChannelType;
   unsigned int           dlTransportChannelId;
   unsigned int           tfsSignallingModeType;
   unsigned int           transportFormatSetType; 
   RrcDedicatedTransChTfs dedicatedTransChInfo;
   unsigned int           dchQualityTargetPresence;
   unsigned int           blerQualityValue;
}RrcDlAddReconfTransChInfoList;

/*
 * RRC UL Channel Requirement
 */
typedef struct rrcUlChannelRequirement
{
   unsigned int            ulChannelRequirementType;
   unsigned int            ulDPCHPowerControlPresence;
   unsigned int            dpcchPowerOffset;
   unsigned int            pcPreamble;
   unsigned int            srbDelay;
   unsigned int            powerControlAlgorithmType;
   unsigned int            powerControlAlgorithmValue;
   unsigned int            scramblingCodeType;
   unsigned int            scramblingCode;
   unsigned int            spreadingFactor;
   unsigned int            tfciExistence;
   unsigned int            puncturingLimit;
}RrcUlChannelRequirement;
      
/*
 * RRC DL Common Information
 */
typedef struct rrcDlCommonInformation
{
   unsigned int          dlDPCHInfoCommonPresence;
   unsigned int          cfnHandlingType;
   unsigned int          powerOffsetPilotPDPDCH;
   unsigned int          spreadingFactorAndPilotType;
   unsigned int          pilotBits256Type;
   unsigned int          positionFixedOrFlexible;
   unsigned int          tfciExistence;
   unsigned int          defaultDPCHOffsetValuePresence;
   unsigned int          defaultDPCHOffsetValue; 
}RrcDlCommonInformation;

/*
 * RRC DL Information per RL List
 */
typedef struct rrcDlInformationPerRLList
{
    unsigned int         numOfDlInfoPerRLList;
    unsigned int         primaryScramblingCode;
    unsigned int         dlDPCHInfoPerRLPresence;
    unsigned int         pCPICHUsageForChannelEst;
    unsigned int         numOfDlChannelisationCode;
    unsigned int         dpchFrameOffset;
    unsigned int         sfAndCodeNumber;
    unsigned int         sfValue;
    unsigned int         tpcCombinationIndex;
}RrcDlInformationPerRLList;

/*
 * RRC Connection Setup Data
 */
typedef struct rrcConnectionSetupData
{
   unsigned int                   rrcTransactionId;
   unsigned int                   numOfSrb;
   RrcSrbInfo                     srbInfo[MAX_SRB_PER_UE];
   unsigned int                   activationTimePrsence;
   unsigned int                   activationTime;
   RrcURNTI                       newURNTI;
   unsigned int                   rrcStateIndicator;
   unsigned int                   utranDRXCycleLengthCoeff;
   unsigned int                   capabilityUpdateRequirementPresence;
   RrcCapabilityUpdateRequirement capabilityUpdateRequirement;
   unsigned int                   ulCommonTransportChannelInfoPresence;
   RrcUlCommonTransChInfo         ulCommonTransportChannelInfo;
   RrcUlAddReconfTransChInfoList  ulAddReconfTransChInfoList;
   unsigned int                   dlCommonTransportChannelInfoPresence;
   RrcDlCommonTransChInfo         dlCommonTransportChannelInfo;
   RrcDlAddReconfTransChInfoList  dlAddReconfTransChInfoList;
   unsigned int                   maxAllowedULTXPowerPresence;
   unsigned int                   maxAllowedULTXPower;
   unsigned int                   ulChannelRequirementPresence;
   RrcUlChannelRequirement        ulChannelRequirement;
   unsigned int                   dlCommonInformationPresence;
   RrcDlCommonInformation         dlCommonInformation;
   unsigned int                   dlInformationPerRLListPrsence;
   RrcDlInformationPerRLList      dlInformationPerRLList;
}RrcConnectionSetupData;

/*
 * UL DCCH Data
 */
typedef struct rrcUlDCCHData
{
   int            msgType;
   unsigned int   nasMsgLen;
   unsigned char *pNasMsg;
   unsigned int   cnDomainType;
}RrcUlDCCHData;

/*
 * RRC Connetion Release Data
 */
#define RELEASE_CAUSE_NORMAL_EVENT                      0
#define RELEASE_CAUSE_UNSPECIFIED                       1
#define RELEASE_CAUSE_PREMPTIVE                         2
#define RELEASE_CAUSE_CONGESTION                        3
#define RELEASE_CAUSE_REESTABLISHMENT_REJECT            4
#define RELEASE_CAUSE_DIRECTED_SIGNALLING_REESTAB       5
#define RELEASE_CAUSE_USER_INACTIVE                     6
#define REDIRECTION_INFO_INTER_FREQUENCY                0
#define REDIRECTION_INFO_INTER_RAT                      1
#define MAX_GSM_REDIRECT_INFO                           10
#define GSM_FREQ_BAND_1800                              0
#define GSM_FREQ_BAND_1900                              1

typedef struct rrcGsmRedirectInfo
{
   unsigned int       arfcn;
   unsigned int       frequencyBand;
   unsigned int       bsicPresence;
   unsigned char      bsicNcc;
   unsigned char      bsicBcc;
   unsigned char      dummy[2];
}RrcGsmRedirectInfo;

typedef struct rrcConnectionReleaseData
{
   unsigned char      laterThanR3;
   unsigned int       rrcTransactionId;
   unsigned int       n308Presence;
   unsigned int       n308;
   unsigned int       releaseCause;
   unsigned int       redirectionType;
   unsigned int       numOfGsmCell;
   RrcGsmRedirectInfo gsmInfo[MAX_GSM_REDIRECT_INFO];
}RrcConnectionReleaseData;

/*
 * PLMN structure
 */
typedef struct plmnData
{
   unsigned int mccLength;
   unsigned int mcc[MAX_MCC_LENGTH];
   unsigned int mncLength;
   unsigned int mnc[MAX_MNC_LENGTH];
}PlmnData;

/*
 * Cell Selection Reselection Data
 */
typedef struct cellSelReselData
{
    int qQualMin;
    int qRxLevMin;
    int qHystLS;
    int qHyst2S;
    int tReselS;
    int maxAllowedULTxPower;
}CellSelReselData;

/*
 * Intra Frequency Cell List
 */
typedef struct intraFreqCellInfo
{
   int cellId;
   int psc;
}IntraFreqCellInfo;

/*
 * Inter Frequency Cell List
 */
typedef struct interFreqCellInfo
{
   int cellId;
   int dlUarfcn;
   int ulUarfcn;
   int psc;
}InterFreqCellInfo;

/*
 * Inter RAT Cell List
 */
typedef struct interRATCellInfo
{
   int cellId;
   int qRxLevMin;
   int ncc;
   int bcc;
   int arfcn;
   int band;
}InterRATCellInfo;

#define MAX_CELL_LIST       32
/*
 * Sysinfo Type 11 Frequency Cell List
 */
typedef struct sysInfoType11FreqCellList
{
    IntraFreqCellInfo intraFreqCellInfo[MAX_CELL_LIST];
    InterFreqCellInfo interFreqCellInfo[MAX_CELL_LIST];
    InterRATCellInfo  interRATCellInfo[MAX_CELL_LIST];
}SysInfoType11FreqCellList;

/*
 * Method Declaration
 */
#if 0
extern ASNRetCode_t initializeASNContext (char *fileName);
#else
extern ASNRetCode_t initializeASNContext (void);
#endif

extern void cleanASNContext (void);

extern ASNRetCode_t buildASNMIBValue (void);

extern void fillASNMIBValueTag (unsigned int mibValueTag);

extern void fillASNMIBPLMNType (unsigned int mibPLMNType);

extern void fillASNMIBPLMNIdentityMCC (unsigned int maxIndex, 
                                       unsigned int *mccBuffer);

extern void fillASNMIBPLMNIdentityMNC (unsigned int maxIndex, 
                                       unsigned int *mncBuffer);

extern void fillASNMIBSIBReferenceList (unsigned int maxIndex, 
                                        unsigned int *sibRefList,
                                        unsigned int *sibRepPos,
                                        unsigned int *sibRepPosValue);

extern ASNRetCode_t fillASNSysInfoType1LAC (unsigned int *pLac);

extern ASNRetCode_t fillASNSysInfoType1CNDomainSystemInfo
                      (unsigned int maxIndex,
                       unsigned int *pCnDomainList,
                       unsigned int *pCnType,
                       unsigned char *pGsmMapValue1,
                       unsigned char *pGsmMapValue2,
                       unsigned int *pDrxCycLngCoef);

extern void fillASNSysInfoType1UeIdleTimers (int n300, int t300,
                                             int t312, int n312);

extern void fillASNSysInfoType1ConnTimer (void);

extern void fillASNSysInfoType1ConnTimerT301 (int t301);

extern void fillASNSysInfoType1ConnTimerT302 (int t302);

extern void fillASNSysInfoType1ConnTimerT304 (int t304);

extern void fillASNSysInfoType1ConnTimerT305 (int t305);

extern void fillASNSysInfoType1ConnTimerT307 (int t307);

extern void fillASNSysInfoType1ConnTimerT308 (int t308);

extern void fillASNSysInfoType1ConnTimerT310 (int t310);

extern void fillASNSysInfoType1ConnTimerT311 (int t311);

extern void fillASNSysInfoType1ConnTimerT312 (int t312);

extern void fillASNSysInfoType1ConnTimerT314 (int t314);

extern void fillASNSysInfoType1ConnTimerT315 (int t315);

extern void fillASNSysInfoType1ConnTimerT316 (int t316);

extern void fillASNSysInfoType1ConnTimerT317 (int t317);

extern void fillASNSysInfoType1ConnTimerN312 (int n312);

extern void fillASNSysInfoType1ConnTimerN313 (int n313);

extern void fillASNSysInfoType1ConnTimerN315 (int n315);

extern ASNRetCode_t fillASNSysInfoType2URAIdentity (
                      unsigned int maxIndex,
                      unsigned int *URAIdentityList);

extern void fillASNSysInfoType3SIB4Indicator (int sib4Indicator);

extern ASNRetCode_t fillASNSysInfoType3CellIdentity (
                                       unsigned int cellIdentity);

extern void fillASNSysInfoType3CellSelectReselectQualMeas 
                                                  (int qualMeas,
                                                   int qHyst2S);
extern void fillASNSysInfoType3CellSelectReselectModeSpecificInfo 
                                                 (int intraSearch,
                                                  int interSearch,
                                                  int hcsSearch,
                                                  int qQualMin,
                                                  int qRxlevMin);

extern void fillASNSysInfoType3CellSelectReselectQHystLS (int qHystLS);

extern void fillASNSysInfoType3CellSelectReselectTReselectionS 
                                                   (int tReselectionS);

extern void fillASNSysInfoType3CellSelectReselectULTxPower 
                                             (int maxAllowedULTxPower);

extern void fillASNSysInfoType3CellAccessRestrictionCellNotBarred (void);

extern void fillASNSysInfoType3CellReservedForOperatorUse 
                                        (int cellReservedForOperatorUse);

extern void fillASNSysInfoType3CellReservationExtension 
                                          (int cellReservationExtension);

extern void fillASNSysInfoType3AccessClassBarredList (int maxIndex,
                                             int *accessClassBarredList);

extern void fillASNSysInfoType5SIB6Indicator (int sib6Indicator);

extern void fillASNSysInfoType5PICHPowerOffset (int pichPowerOffset);

extern void fillASNSysInfoType5ModeSpecificInfo (int aichPowerOffset);

extern ASNRetCode_t fillASNSysInfoType5PRACHSystemInformationList 
                       (int maxIndex,
                        int AvailableSignature,
                        int availableSF,
                        int scramblingCodeNumber,
                        int puncturingLimit,
                        int subChannelNumber,
                        int transportChannelIdentity,
                        int ttiType,
                        int numberOfTFInfo,
                        int rlcSizeOctetModeType,
                        int rlcSizeOctetModeValue,
                        int maxTBSize,
                        int *tbSizeList,
                        int logicalChannelType,
                        int channelCodingType,
                        int codingRate,
                        int rateMatchingAttribute,
                        int crcSize,
                        int tfcsConfigurationType,
                        int ctfcSize,
                        int maxCtfcSize,
                        int *ctfc2,
                        int *gainFactor,
                        int *gainFactorBetaC,
                        int *gainFactorBetaD,
                        int *powerOffsetPpm,
                        int maxPRACHPartition,
                        int *availableSignatureStartIndex,
                        int *availableSignatureEndIndex,
                        char assignedSubChanNumber,
                        int primaryCPICHTxPower,
                        int constantValue,
                        int powerRampStep,
                        int preambleRetransMax,
                        int mMax,
                        int nb01Min,
                        int nb01Max,
                        int channelisationCode256,
                        int sttd_Indicator,
                        int aich_TransmissionTiming);

extern void fillASNSysInfoType7 (int ulInterference,
                                 int maxSib5Info,
                                 int *sib5Info);

extern void fillASNSysInfoType11SIB12Indicator (int sib12Indicator);

extern void fillASNSysInfoType11MeasurementControlSystemInfo
                       (int interFreqCells,
                        int *dlUarfcn,
                        int *primaryScramblingCode,
                        int intraFreqCells,
                        int *intraPrimaryScramblingCode);

extern void cleanASNMIBValue (void);

extern ASNRetCode_t encodeASNMib (int  *pMibEncodedLength,
                                  char *pMibOutputBuffer); 

extern ASNRetCode_t buildASNSIB1Value (void);

extern void cleanASNSIB1Value (void);

extern ASNRetCode_t encodeASNSib1 (int  *pSib1EncodedLength,
                                   char *pSib1OutputBuffer);

extern ASNRetCode_t buildASNSIB2Value (void);

extern void cleanASNSIB2Value (void);

extern ASNRetCode_t encodeASNSib2 (int  *pSib2EncodedLength,
                                   char *pSib2OutputBuffer);

extern ASNRetCode_t encodeASNSib3 (int  *pSib3EncodedLength,
                                   char *pSib3OutputBuffer);

extern ASNRetCode_t buildASNSIB3Value (void);

extern void cleanASNSIB3Value (void);

extern ASNRetCode_t encodeASNSib5 (int  *pSib5EncodedLength,
                                   char *pSib5OutputBuffer);

extern ASNRetCode_t buildASNSIB5Value (void);

extern void cleanASNSIB5Value (void);

extern ASNRetCode_t encodeASNSib7 (int  *pSib7EncodedLength,
                                   char *pSib7OutputBuffer);

extern ASNRetCode_t buildASNSIB7Value (void);

extern void cleanASNSIB7Value (void);

extern ASNRetCode_t encodeASNSib11 (int  *pSib11EncodedLength,
                                    char *pSib11OutputBuffer);

extern ASNRetCode_t buildASNSIB11Value (void);

extern void cleanASNSIB11Value (void);

extern ASNRetCode_t encodeASNBcchBchMessage 
                       (BcchBchData_t *pBcchBchInputData,
                        int           *pBcchEncodedLen,
                        char          *pBcchEncodedBuf);

extern void fillASNSysInfoType5PrimaryCCPCHInfo 
                       (int txDiversityIndicator);

extern void fillASNSysInfoType5SCCPCHSysInfo 
              (int maxSysInfo,
               int sttdIndicator,
               int sfCodeType,
               int sfCodeValue,
               int pilotSymbolExistence,
               int tfciExistence,
               int positionFixedOrFlexible,
               int ctfcSizeType,
               int timingOffset,
               int maxTfc4Bit,
               int *ctfc4,
               int maxFachPchInfo,
               int maxTfCount,
               int *rlcSizeType,
               int *rlcSizeTypeValue,
               int *tbSizeList,
               int tbSize[][3],
               int *rateMatchingAttribute,
               int *transportChannelIdentity,
               int channelisationCode256,
               int *sccpchChannelCodingType);

extern ASNRetCode_t decodeASNBcchBchMessage (unsigned char        *pBcchBchInputBuffer,
                                             int                   bufferLength,
                                             BcchBchDecodeData_t  *pBcchBchDecodeData);

extern ASNRetCode_t decodeASNMib (unsigned char *pMibBuffer,
                                  int mibBufferLength,
                                  PlmnData *pPlmnData);

extern ASNRetCode_t decodeASNSib1 (unsigned char *pSib1Buffer, 
                                   int sib1BufferLength,
                                   unsigned char *pLac);

extern ASNRetCode_t decodeASNSib3 (unsigned char *pSib3Buffer, 
                                   int sib3BufferLength,
                                   CellSelReselData *pCellSelReselData);

extern ASNRetCode_t decodeASNSib11 (unsigned char *pSib11Buffer,
                                    int sib11BufferLength,
                                    SysInfoType11FreqCellList *pSysInfoType11FreqCellList);

extern ASNRetCode_t decodeASNULCCCHMessage (unsigned char        *pULCCCHBuffer, 
                                            int                   ulCCCHLength,
                                            int                  *pMsgType,
                                            RrcInitialUEIdentity *pInitUEIdentity);

extern ASNRetCode_t fillAndEncodeRrcConnectionSetup (RrcInitialUEIdentity   *pInitialUEIdentity,
                                                     RrcConnectionSetupData *pRrcConnectionSetup,
                                                     unsigned char          **pEncodedData,
                                                     unsigned int           *pEncodedDataLen);

extern ASNRetCode_t decodeASNULDCCHMessage (unsigned char *pULDCCHBuffer,
                                            int            ulDCCHLength,
                                            RrcUlDCCHData *pUlDCCHData);

extern ASNRetCode_t fillAndEncodeDLDirectTransfer (unsigned int    cnDomainType,
                                                   unsigned int    rrcTransactionId,
                                                   unsigned int    nasMsgLen,
                                                   unsigned char  *pNasMsg,
                                                   unsigned char **pEncodedData,
                                                   unsigned int   *pEncodedDataLen);

extern ASNRetCode_t fillAndEncodeRrcConnectionRelease (RrcConnectionReleaseData *pRrcConnRel,
                                                       unsigned char           **pEncodedData,
                                                       unsigned int             *pEncodedDataLen);
#endif
