/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __CSN1DataTypes_EPS_h
#define __CSN1DataTypes_EPS_h
/* ZZZ */

#include "csn1clib.h"
#include "ed_lib.h"
#include "ed_c_EPS.h"
#include "ed_user.h"
#include "endec_configs_EPS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

extern TCSN1CProgram Program_EPS_Program;


#ifdef CSN1C_LABEL_NAMES
/* List of label names */
extern const char* const Program_EPS_Labels [];
#endif

/* LABELS */

#define CSN1_EPS_QOS_QCI                48
#define CSN1_EPS_QOS_QCI_SIZE            8
#define CSN1_EPS_QOS_basic              49
#define CSN1_EPS_QOS_basic_SIZE         32
#define CSN1_GEA1_bits_GEA_1           157
#define CSN1_GEA1_bits_GEA_1_SIZE        1
#define CSN1_A5_CM3_bits_A5_4           63
#define CSN1_A5_CM3_bits_A5_4_SIZE       1
#define CSN1_A5_CM3_bits_A5_5           62
#define CSN1_A5_CM3_bits_A5_5_SIZE       1
#define CSN1_A5_CM3_bits_A5_6           61
#define CSN1_A5_CM3_bits_A5_6_SIZE       1
#define CSN1_A5_CM3_bits_A5_7           60
#define CSN1_A5_CM3_bits_A5_7_SIZE       1
#define CSN1_EPS_QOS_extended           54
#define CSN1_EPS_QOS_extended_SIZE      32
#define CSN1_EPS_QOS_extended2          59
#define CSN1_EPS_QOS_extended2_SIZE     32
#define CSN1_epsMsNetwkCpblty_GIA_4    181
#define CSN1_epsMsNetwkCpblty_GIA_4_SIZE   1
#define CSN1_epsMsNetwkCpblty_GIA_5    182
#define CSN1_epsMsNetwkCpblty_GIA_5_SIZE   1
#define CSN1_epsMsNetwkCpblty_GIA_6    183
#define CSN1_epsMsNetwkCpblty_GIA_6_SIZE   1
#define CSN1_epsMsNetwkCpblty_GIA_7    184
#define CSN1_epsMsNetwkCpblty_GIA_7_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_2   165
#define CSN1_Extended_GEA_bits_GEA_2_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_3   166
#define CSN1_Extended_GEA_bits_GEA_3_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_4   167
#define CSN1_Extended_GEA_bits_GEA_4_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_5   168
#define CSN1_Extended_GEA_bits_GEA_5_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_6   169
#define CSN1_Extended_GEA_bits_GEA_6_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_7   170
#define CSN1_Extended_GEA_bits_GEA_7_SIZE   1
#define CSN1_UENetworkCapability_ISR   225
#define CSN1_UENetworkCapability_ISR_SIZE   1
#define CSN1_UENetworkCapability_LCS   223
#define CSN1_UENetworkCapability_LCS_SIZE   1
#define CSN1_UENetworkCapability_LPP   222
#define CSN1_UENetworkCapability_LPP_SIZE   1
#define CSN1_epsQualityOfServ_uplink    86
#define CSN1_epsQualityOfServ_uplink_SIZE  16
#define CSN1_UENetworkCapability_EEA4  189
#define CSN1_UENetworkCapability_EEA4_SIZE   1
#define CSN1_UENetworkCapability_EEA5  190
#define CSN1_UENetworkCapability_EEA5_SIZE   1
#define CSN1_UENetworkCapability_EEA6  191
#define CSN1_UENetworkCapability_EEA6_SIZE   1
#define CSN1_UENetworkCapability_EEA7  192
#define CSN1_UENetworkCapability_EEA7_SIZE   1
#define CSN1_UENetworkCapability_EIA0  193
#define CSN1_UENetworkCapability_EIA0_SIZE   1
#define CSN1_UENetworkCapability_EIA4  197
#define CSN1_UENetworkCapability_EIA4_SIZE   1
#define CSN1_UENetworkCapability_EIA5  198
#define CSN1_UENetworkCapability_EIA5_SIZE   1
#define CSN1_UENetworkCapability_EIA6  199
#define CSN1_UENetworkCapability_EIA6_SIZE   1
#define CSN1_UENetworkCapability_EIA7  200
#define CSN1_UENetworkCapability_EIA7_SIZE   1
#define CSN1_UENetworkCapability_UCS2  211
#define CSN1_UENetworkCapability_UCS2_SIZE   1
#define CSN1_UENetworkCapability_UEA0  202
#define CSN1_UENetworkCapability_UEA0_SIZE   1
#define CSN1_UENetworkCapability_UEA1  203
#define CSN1_UENetworkCapability_UEA1_SIZE   1
#define CSN1_UENetworkCapability_UEA2  204
#define CSN1_UENetworkCapability_UEA2_SIZE   1
#define CSN1_UENetworkCapability_UEA3  205
#define CSN1_UENetworkCapability_UEA3_SIZE   1
#define CSN1_UENetworkCapability_UEA4  206
#define CSN1_UENetworkCapability_UEA4_SIZE   1
#define CSN1_UENetworkCapability_UEA5  207
#define CSN1_UENetworkCapability_UEA5_SIZE   1
#define CSN1_UENetworkCapability_UEA6  208
#define CSN1_UENetworkCapability_UEA6_SIZE   1
#define CSN1_UENetworkCapability_UEA7  209
#define CSN1_UENetworkCapability_UEA7_SIZE   1
#define CSN1_UENetworkCapability_UIA1  212
#define CSN1_UENetworkCapability_UIA1_SIZE   1
#define CSN1_UENetworkCapability_UIA2  213
#define CSN1_UENetworkCapability_UIA2_SIZE   1
#define CSN1_UENetworkCapability_UIA3  214
#define CSN1_UENetworkCapability_UIA3_SIZE   1
#define CSN1_UENetworkCapability_UIA4  215
#define CSN1_UENetworkCapability_UIA4_SIZE   1
#define CSN1_UENetworkCapability_UIA5  216
#define CSN1_UENetworkCapability_UIA5_SIZE   1
#define CSN1_UENetworkCapability_UIA6  217
#define CSN1_UENetworkCapability_UIA6_SIZE   1
#define CSN1_UENetworkCapability_UIA7  218
#define CSN1_UENetworkCapability_UIA7_SIZE   1
#define CSN1_UENetworkCapability_ePCO  227
#define CSN1_UENetworkCapability_ePCO_SIZE   1
#define CSN1_UESecurityCapability_GEA   32
#define CSN1_UESecurityCapability_GEA_SIZE   8
#define CSN1_UESecurityCapability_EEA4   4
#define CSN1_UESecurityCapability_EEA4_SIZE   1
#define CSN1_UESecurityCapability_EEA5   5
#define CSN1_UESecurityCapability_EEA5_SIZE   1
#define CSN1_UESecurityCapability_EEA6   6
#define CSN1_UESecurityCapability_EEA6_SIZE   1
#define CSN1_UESecurityCapability_EEA7   7
#define CSN1_UESecurityCapability_EEA7_SIZE   1
#define CSN1_UESecurityCapability_EIA4  12
#define CSN1_UESecurityCapability_EIA4_SIZE   1
#define CSN1_UESecurityCapability_EIA5  13
#define CSN1_UESecurityCapability_EIA5_SIZE   1
#define CSN1_UESecurityCapability_EIA6  14
#define CSN1_UESecurityCapability_EIA6_SIZE   1
#define CSN1_UESecurityCapability_EIA7  15
#define CSN1_UESecurityCapability_EIA7_SIZE   1
#define CSN1_UESecurityCapability_GEA1  33
#define CSN1_UESecurityCapability_GEA1_SIZE   1
#define CSN1_UESecurityCapability_GEA2  34
#define CSN1_UESecurityCapability_GEA2_SIZE   1
#define CSN1_UESecurityCapability_GEA3  35
#define CSN1_UESecurityCapability_GEA3_SIZE   1
#define CSN1_UESecurityCapability_GEA4  36
#define CSN1_UESecurityCapability_GEA4_SIZE   1
#define CSN1_UESecurityCapability_GEA5  37
#define CSN1_UESecurityCapability_GEA5_SIZE   1
#define CSN1_UESecurityCapability_GEA6  38
#define CSN1_UESecurityCapability_GEA6_SIZE   1
#define CSN1_UESecurityCapability_GEA7  39
#define CSN1_UESecurityCapability_GEA7_SIZE   1
#define CSN1_UESecurityCapability_UEA0  17
#define CSN1_UESecurityCapability_UEA0_SIZE   1
#define CSN1_UESecurityCapability_UEA1  18
#define CSN1_UESecurityCapability_UEA1_SIZE   1
#define CSN1_UESecurityCapability_UEA2  19
#define CSN1_UESecurityCapability_UEA2_SIZE   1
#define CSN1_UESecurityCapability_UEA3  20
#define CSN1_UESecurityCapability_UEA3_SIZE   1
#define CSN1_UESecurityCapability_UEA4  21
#define CSN1_UESecurityCapability_UEA4_SIZE   1
#define CSN1_UESecurityCapability_UEA5  22
#define CSN1_UESecurityCapability_UEA5_SIZE   1
#define CSN1_UESecurityCapability_UEA6  23
#define CSN1_UESecurityCapability_UEA6_SIZE   1
#define CSN1_UESecurityCapability_UEA7  24
#define CSN1_UESecurityCapability_UEA7_SIZE   1
#define CSN1_UESecurityCapability_UIA1  25
#define CSN1_UESecurityCapability_UIA1_SIZE   1
#define CSN1_UESecurityCapability_UIA2  26
#define CSN1_UESecurityCapability_UIA2_SIZE   1
#define CSN1_UESecurityCapability_UIA3  27
#define CSN1_UESecurityCapability_UIA3_SIZE   1
#define CSN1_UESecurityCapability_UIA4  28
#define CSN1_UESecurityCapability_UIA4_SIZE   1
#define CSN1_UESecurityCapability_UIA5  29
#define CSN1_UESecurityCapability_UIA5_SIZE   1
#define CSN1_UESecurityCapability_UIA6  30
#define CSN1_UESecurityCapability_UIA6_SIZE   1
#define CSN1_UESecurityCapability_UIA7  31
#define CSN1_UESecurityCapability_UIA7_SIZE   1
#define CSN1_epsQualityOfServ_downlink  83
#define CSN1_epsQualityOfServ_downlink_SIZE  16
#define CSN1_APNAggregateMaxBitRate_ext  42
#define CSN1_APNAggregateMaxBitRate_ext_SIZE  16
#define CSN1_APNAggregateMaxBitRate_ext2  45
#define CSN1_APNAggregateMaxBitRate_ext2_SIZE  16
#define CSN1_UENetworkCapability_CP_CIoT 232
#define CSN1_UENetworkCapability_CP_CIoT_SIZE   1
#define CSN1_UENetworkCapability_UP_CIoT 231
#define CSN1_UENetworkCapability_UP_CIoT_SIZE   1
#define CSN1_UENetworkCapability_octet_5 201
#define CSN1_UENetworkCapability_octet_5_SIZE   8
#define CSN1_UENetworkCapability_octet_6 210
#define CSN1_UENetworkCapability_octet_6_SIZE   8
#define CSN1_UENetworkCapability_octet_7 219
#define CSN1_UENetworkCapability_octet_7_SIZE   8
#define CSN1_UENetworkCapability_octet_8 226
#define CSN1_UENetworkCapability_octet_8_SIZE   8
#define CSN1_epsQualityOfServ_DelayClass  64
#define CSN1_epsQualityOfServ_DelayClass_SIZE   3
#define CSN1_epsQualityOfServ_ext2uplink  90
#define CSN1_epsQualityOfServ_ext2uplink_SIZE  16
#define CSN1_Single_Band_Support_GSM_Band 115
#define CSN1_Single_Band_Support_GSM_Band_SIZE   4
#define CSN1_UENetworkCapability_ACC_CSFB 221
#define CSN1_UENetworkCapability_ACC_CSFB_SIZE   1
#define CSN1_UENetworkCapability_ERw_oPDN 229
#define CSN1_UENetworkCapability_ERw_oPDN_SIZE   1
#define CSN1_UENetworkCapability_H245_ASH 220
#define CSN1_UENetworkCapability_H245_ASH_SIZE   1
#define CSN1_UENetworkCapability_ProSe_dc 234
#define CSN1_UENetworkCapability_ProSe_dc_SIZE   1
#define CSN1_UESecurityCapability_UEA_UIA  16
#define CSN1_UESecurityCapability_UEA_UIA_SIZE  16
#define CSN1_epsMsNetwkCpblty_ISR_support 175
#define CSN1_epsMsNetwkCpblty_ISR_support_SIZE   1
#define CSN1_epsQualityOfServ_ResidualBER  75
#define CSN1_epsQualityOfServ_ResidualBER_SIZE   4
#define CSN1_UENetworkCapability_S1_U_data 230
#define CSN1_UENetworkCapability_S1_U_data_SIZE   1
#define CSN1_UENetworkCapability_p128_EEA0 185
#define CSN1_UENetworkCapability_p128_EEA0_SIZE   1
#define CSN1_UENetworkCapability_p128_EEA1 186
#define CSN1_UENetworkCapability_p128_EEA1_SIZE   1
#define CSN1_UENetworkCapability_p128_EEA2 187
#define CSN1_UENetworkCapability_p128_EEA2_SIZE   1
#define CSN1_UENetworkCapability_p128_EEA3 188
#define CSN1_UENetworkCapability_p128_EEA3_SIZE   1
#define CSN1_UENetworkCapability_p128_EIA1 194
#define CSN1_UENetworkCapability_p128_EIA1_SIZE   1
#define CSN1_UENetworkCapability_p128_EIA2 195
#define CSN1_UENetworkCapability_p128_EIA2_SIZE   1
#define CSN1_UENetworkCapability_p128_EIA3 196
#define CSN1_UENetworkCapability_p128_EIA3_SIZE   1
#define CSN1_UENetworkCapability_p1xSR_VCC 224
#define CSN1_UENetworkCapability_p1xSR_VCC_SIZE   1
#define CSN1_epsMsNetwkCpblty_UCS2_support 160
#define CSN1_epsMsNetwkCpblty_UCS2_support_SIZE   1
#define CSN1_epsQualityOfServ_TrafficClass  69
#define CSN1_epsQualityOfServ_TrafficClass_SIZE   3
#define CSN1_epsQualityOfServ_ext2downlink  89
#define CSN1_epsQualityOfServ_ext2downlink_SIZE  16
#define CSN1_UENetworkCapability_HC_CP_CIoT 228
#define CSN1_UENetworkCapability_HC_CP_CIoT_SIZE   1
#define CSN1_UESecurityCapability_p128_EEA0   0
#define CSN1_UESecurityCapability_p128_EEA0_SIZE   1
#define CSN1_UESecurityCapability_p128_EEA1   1
#define CSN1_UESecurityCapability_p128_EEA1_SIZE   1
#define CSN1_UESecurityCapability_p128_EEA2   2
#define CSN1_UESecurityCapability_p128_EEA2_SIZE   1
#define CSN1_UESecurityCapability_p128_EEA3   3
#define CSN1_UESecurityCapability_p128_EEA3_SIZE   1
#define CSN1_UESecurityCapability_p128_EIA0   8
#define CSN1_UESecurityCapability_p128_EIA0_SIZE   1
#define CSN1_UESecurityCapability_p128_EIA1   9
#define CSN1_UESecurityCapability_p128_EIA1_SIZE   1
#define CSN1_UESecurityCapability_p128_EIA2  10
#define CSN1_UESecurityCapability_p128_EIA2_SIZE   1
#define CSN1_UESecurityCapability_p128_EIA3  11
#define CSN1_UESecurityCapability_p128_EIA3_SIZE   1
#define CSN1_epsClassmark3Value_VAMOS_Level 145
#define CSN1_epsClassmark3Value_VAMOS_Level_SIZE   2
#define CSN1_epsMsNetwkCpblty_NF_capability 178
#define CSN1_epsMsNetwkCpblty_NF_capability_SIZE   1
#define CSN1_epsQualityOfServ_DeliveryOrder  70
#define CSN1_epsQualityOfServ_DeliveryOrder_SIZE   2
#define CSN1_epsQualityOfServ_SDUErrorRatio  76
#define CSN1_epsQualityOfServ_SDUErrorRatio_SIZE   4
#define CSN1_epsQualityOfServ_TransderDelay  77
#define CSN1_epsQualityOfServ_TransderDelay_SIZE   6
#define CSN1_EPS_QOS_MaximumBitRateForUplink  50
#define CSN1_EPS_QOS_MaximumBitRateForUplink_SIZE   8
#define CSN1_UENetworkCapability_Prose_relay 233
#define CSN1_UENetworkCapability_Prose_relay_SIZE   1
#define CSN1_epsMsNetwkCpblty_EPC_capability 177
#define CSN1_epsMsNetwkCpblty_EPC_capability_SIZE   1
#define CSN1_epsQualityOfServ_MaximumSDUSize  72
#define CSN1_epsQualityOfServ_MaximumSDUSize_SIZE   8
#define CSN1_epsQualityOfServ_MeanThroughput  68
#define CSN1_epsQualityOfServ_MeanThroughput_SIZE   5
#define CSN1_epsQualityOfServ_PeakThroughput  66
#define CSN1_epsQualityOfServ_PeakThroughput_SIZE   4
#define CSN1_epsQualityOfServ_PrecedenceClass  67
#define CSN1_epsQualityOfServ_PrecedenceClass_SIZE   3
#define CSN1_EPS_QOS_MaximumBitRateForDownlink  51
#define CSN1_EPS_QOS_MaximumBitRateForDownlink_SIZE   8
#define CSN1_GERAN_Iu_Mode_Capabilities_Length 122
#define CSN1_GERAN_Iu_Mode_Capabilities_Length_SIZE   4
#define CSN1_epsClassmark3Value_UCS2_treatment  96
#define CSN1_epsClassmark3Value_UCS2_treatment_SIZE   1
#define CSN1_epsMsNetwkCpblty_PFC_feature_mode 164
#define CSN1_epsMsNetwkCpblty_PFC_feature_mode_SIZE   1
#define CSN1_epsMsNetwkCpblty_SoLSA_Capability 162
#define CSN1_epsMsNetwkCpblty_SoLSA_Capability_SIZE   1
#define CSN1_epsQualityOfServ_ReliabilityClass  65
#define CSN1_epsQualityOfServ_ReliabilityClass_SIZE   3
#define CSN1_EPS_QOS_GuaranteedBitRateForUplink  52
#define CSN1_EPS_QOS_GuaranteedBitRateForUplink_SIZE   8
#define CSN1_EPS_QOS_MaximumBitRateForUplinkExt  55
#define CSN1_EPS_QOS_MaximumBitRateForUplinkExt_SIZE   8
#define CSN1_MS_Measurement_capability_SM_VALUE  99
#define CSN1_MS_Measurement_capability_SM_VALUE_SIZE   4
#define CSN1_epsClassmark3Value_ER_Band_Support 152
#define CSN1_epsClassmark3Value_ER_Band_Support_SIZE   1
#define CSN1_epsClassmark3Value_Offset_required 133
#define CSN1_epsClassmark3Value_Offset_required_SIZE   1
#define CSN1_epsClassmark3Value_Single_Slot_DTM 113
#define CSN1_epsClassmark3Value_Single_Slot_DTM_SIZE   1
#define CSN1_epsMsNetwkCpblty_LCS_VA_capability 171
#define CSN1_epsMsNetwkCpblty_LCS_VA_capability_SIZE   1
#define CSN1_MS_Measurement_capability_SMS_VALUE  98
#define CSN1_MS_Measurement_capability_SMS_VALUE_SIZE   4
#define CSN1__8_PSK_Struct_Modulation_Capability 102
#define CSN1__8_PSK_Struct_Modulation_Capability_SIZE   1
#define CSN1_EPS_QOS_GuaranteedBitRateForDownlink  53
#define CSN1_EPS_QOS_GuaranteedBitRateForDownlink_SIZE   8
#define CSN1_EPS_QOS_MaximumBitRateForDownlinkExt  56
#define CSN1_EPS_QOS_MaximumBitRateForDownlinkExt_SIZE   8
#define CSN1_epsQualityOfServ_SignalingIndication  81
#define CSN1_epsQualityOfServ_SignalingIndication_SIZE   1
#define CSN1_APNAggregateMaxBitRate_APN_AMBRUplink  41
#define CSN1_APNAggregateMaxBitRate_APN_AMBRUplink_SIZE   8
#define CSN1_EPS_QOS_GuaranteedBitRateForUplinkExt  57
#define CSN1_EPS_QOS_GuaranteedBitRateForUplinkExt_SIZE   8
#define CSN1_epsClassmark3Value_E_UTRA_FDD_support 140
#define CSN1_epsClassmark3Value_E_UTRA_FDD_support_SIZE   1
#define CSN1_epsClassmark3Value_E_UTRA_TDD_support 141
#define CSN1_epsClassmark3Value_E_UTRA_TDD_support_SIZE   1
#define CSN1_epsClassmark3Value_TIGHTER_Capability 146
#define CSN1_epsClassmark3Value_TIGHTER_Capability_SIZE   2
#define CSN1_epsClassmark3Value_Multiband_supported  91
#define CSN1_epsClassmark3Value_Multiband_supported_SIZE   3
#define CSN1_epsQualityOfServ_DeliveryOfErroneusSDU  71
#define CSN1_epsQualityOfServ_DeliveryOfErroneusSDU_SIZE   3
#define CSN1_APNAggregateMaxBitRate_APN_AMBRDownlink  40
#define CSN1_APNAggregateMaxBitRate_APN_AMBRDownlink_SIZE   8
#define CSN1_EPS_QOS_GuaranteedBitRateForDownlinkExt  58
#define CSN1_EPS_QOS_GuaranteedBitRateForDownlinkExt_SIZE   8
#define CSN1_epsMsNetwkCpblty_SS_Screening_Indicator 161
#define CSN1_epsMsNetwkCpblty_SS_Screening_Indicator_SIZE   2
#define CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt  44
#define CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt_SIZE   8
#define CSN1_epsQualityOfServ_MaximumBitRateForUplink  73
#define CSN1_epsQualityOfServ_MaximumBitRateForUplink_SIZE   8
#define CSN1_epsQualityOfServ_TrafficHandlingPriority  78
#define CSN1_epsQualityOfServ_TrafficHandlingPriority_SIZE   2
#define CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt2  47
#define CSN1_APNAggregateMaxBitRate_APN_AMBRUplinkExt2_SIZE   8
#define CSN1_epsMsNetwkCpblty_Revision_level_indicator 163
#define CSN1_epsMsNetwkCpblty_Revision_level_indicator_SIZE   1
#define CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt  43
#define CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt_SIZE   8
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1 103
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1_SIZE   2
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2 104
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2_SIZE   2
#define CSN1_epsClassmark3Value_GERAN_Feature_Package_1 118
#define CSN1_epsClassmark3Value_GERAN_Feature_Package_1_SIZE   1
#define CSN1_epsClassmark3Value_GERAN_Feature_Package_2 124
#define CSN1_epsClassmark3Value_GERAN_Feature_Package_2_SIZE   1
#define CSN1_epsClassmark3Value_GSM_400_Bands_Supported 105
#define CSN1_epsClassmark3Value_GSM_400_Bands_Supported_SIZE   2
#define CSN1_epsQualityOfServ_MaximumBitRateForDownlink  74
#define CSN1_epsQualityOfServ_MaximumBitRateForDownlink_SIZE   8
#define CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt2  46
#define CSN1_APNAggregateMaxBitRate_APN_AMBRDownlinkExt2_SIZE   8
#define CSN1_epsClassmark3Value_Repeated_ACCH_Capability 135
#define CSN1_epsClassmark3Value_Repeated_ACCH_Capability_SIZE   1
#define CSN1_epsClassmark3Value_UTRA_CSG_Cells_Reporting 144
#define CSN1_epsClassmark3Value_UTRA_CSG_Cells_Reporting_SIZE   1
#define CSN1_epsQualityOfServ_GuaranteedBitRateForUplink  79
#define CSN1_epsQualityOfServ_GuaranteedBitRateForUplink_SIZE   8
#define CSN1_epsQualityOfServ_MaximumBitRateForUplinkExt  87
#define CSN1_epsQualityOfServ_MaximumBitRateForUplinkExt_SIZE   8
#define CSN1_epsQualityOfServ_SourceStatisticsDescriptor  82
#define CSN1_epsQualityOfServ_SourceStatisticsDescriptor_SIZE   4
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability 123
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability_SIZE   1
#define CSN1_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class 112
#define CSN1_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_epsClassmark3Value_High_Multislot_Capability 121
#define CSN1_epsClassmark3Value_High_Multislot_Capability_SIZE   2
#define CSN1_epsClassmark3Value_T_GSM_400_Bands_Supported 127
#define CSN1_epsClassmark3Value_T_GSM_400_Bands_Supported_SIZE   2
#define CSN1_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class 114
#define CSN1_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_epsQualityOfServ_GuaranteedBitRateForDownlink  80
#define CSN1_epsQualityOfServ_GuaranteedBitRateForDownlink_SIZE   8
#define CSN1_epsQualityOfServ_MaximumBitRateForDownlinkExt  84
#define CSN1_epsQualityOfServ_MaximumBitRateForDownlinkExt_SIZE   8
#define CSN1_epsClassmark3Value_DTM_Enhancements_Capability 131
#define CSN1_epsClassmark3Value_DTM_Enhancements_Capability_SIZE   1
#define CSN1_epsClassmark3Value_Extended_EARFCN_value_range 156
#define CSN1_epsClassmark3Value_Extended_EARFCN_value_range_SIZE   1
#define CSN1_epsQualityOfServ_GuaranteedBitRateForUplinkExt  88
#define CSN1_epsQualityOfServ_GuaranteedBitRateForUplinkExt_SIZE   8
#define CSN1_epsClassmark3Value_GMSK_Multislot_Power_Profile 125
#define CSN1_epsClassmark3Value_GMSK_Multislot_Power_Profile_SIZE   2
#define CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class 101
#define CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class_SIZE   5
#define CSN1_R_Support_R_GSM_band_Associated_Radio_Capability  94
#define CSN1_R_Support_R_GSM_band_Associated_Radio_Capability_SIZE   3
#define CSN1_epsClassmark3Value_Associated_Radio_Capability_1  93
#define CSN1_epsClassmark3Value_Associated_Radio_Capability_1_SIZE   4
#define CSN1_epsClassmark3Value_Associated_Radio_Capability_2  92
#define CSN1_epsClassmark3Value_Associated_Radio_Capability_2_SIZE   4
#define CSN1_epsClassmark3Value_GERAN_Network_Sharing_support 150
#define CSN1_epsClassmark3Value_GERAN_Network_Sharing_support_SIZE   1
#define CSN1_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability 176
#define CSN1_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability_SIZE   1
#define CSN1_epsQualityOfServ_GuaranteedBitRateForDownlinkExt  85
#define CSN1_epsQualityOfServ_GuaranteedBitRateForDownlinkExt_SIZE   8
#define CSN1_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class 132
#define CSN1_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_epsClassmark3Value__8_PSK_Multislot_Power_Profile 126
#define CSN1_epsClassmark3Value__8_PSK_Multislot_Power_Profile_SIZE   2
#define CSN1_epsMsNetwkCpblty_GERAN_network_sharing_capability 179
#define CSN1_epsMsNetwkCpblty_GERAN_network_sharing_capability_SIZE   1
#define CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class  95
#define CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class_SIZE   5
#define CSN1_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class 134
#define CSN1_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_epsClassmark3Value_Extended_Measurement_Capability  97
#define CSN1_epsClassmark3Value_Extended_Measurement_Capability_SIZE   1
#define CSN1_epsMsNetwkCpblty_SM_capabilities_via_GPRS_channels 159
#define CSN1_epsMsNetwkCpblty_SM_capabilities_via_GPRS_channels_SIZE   1
#define CSN1_epsMsNetwkCpblty_EMM_Combined_procedures_Capability 174
#define CSN1_epsMsNetwkCpblty_EMM_Combined_procedures_Capability_SIZE   1
#define CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA 148
#define CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA_SIZE   2
#define CSN1_epsClassmark3Value_Ciphering_Mode_Setting_Capability 138
#define CSN1_epsClassmark3Value_Ciphering_Mode_Setting_Capability_SIZE   1
#define CSN1_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class 119
#define CSN1_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_epsClassmark3Value_Priority_based_reselection_support 143
#define CSN1_epsClassmark3Value_Priority_based_reselection_support_SIZE   1
#define CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method 100
#define CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method_SIZE   5
#define CSN1_epsClassmark3Value_Additional_Positioning_Capabilities 139
#define CSN1_epsClassmark3Value_Additional_Positioning_Capabilities_SIZE   1
#define CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA 149
#define CSN1_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_SIZE   2
#define CSN1_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class 120
#define CSN1_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_epsClassmark3Value_Extended_TSC_Set_Capability_support 155
#define CSN1_epsClassmark3Value_Extended_TSC_Set_Capability_support_SIZE   1
#define CSN1_epsClassmark3Value_GSM_400_Associated_Radio_Capability 106
#define CSN1_epsClassmark3Value_GSM_400_Associated_Radio_Capability_SIZE   4
#define CSN1_epsClassmark3Value_GSM_710_Associated_Radio_Capability 136
#define CSN1_epsClassmark3Value_GSM_710_Associated_Radio_Capability_SIZE   4
#define CSN1_epsClassmark3Value_GSM_750_Associated_Radio_Capability 116
#define CSN1_epsClassmark3Value_GSM_750_Associated_Radio_Capability_SIZE   4
#define CSN1_epsClassmark3Value_GSM_850_Associated_Radio_Capability 107
#define CSN1_epsClassmark3Value_GSM_850_Associated_Radio_Capability_SIZE   4
#define CSN1_epsClassmark3Value_GSM_1900_Associated_Radio_Capability 108
#define CSN1_epsClassmark3Value_GSM_1900_Associated_Radio_Capability_SIZE   4
#define CSN1_epsMsNetwkCpblty_SM_capabilities_via_dedicated_channels 158
#define CSN1_epsMsNetwkCpblty_SM_capabilities_via_dedicated_channels_SIZE   1
#define CSN1_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH 147
#define CSN1_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH_SIZE   1
#define CSN1_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability 128
#define CSN1_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability_SIZE   4
#define CSN1_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability 137
#define CSN1_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability_SIZE   4
#define CSN1_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability 129
#define CSN1_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability_SIZE   4
#define CSN1_epsMsNetwkCpblty_User_plane_integrity_protection_support 180
#define CSN1_epsMsNetwkCpblty_User_plane_integrity_protection_support_SIZE   1
#define CSN1_epsClassmark3Value_Downlink_Advanced_Receiver_Performance 130
#define CSN1_epsClassmark3Value_Downlink_Advanced_Receiver_Performance_SIZE   2
#define CSN1_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support 142
#define CSN1_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support_SIZE   1
#define CSN1_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support 151
#define CSN1_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support_SIZE   1
#define CSN1_epsClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability 109
#define CSN1_epsClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_epsClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability 111
#define CSN1_epsClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support 153
#define CSN1_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support 154
#define CSN1_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability 172
#define CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_SIZE   1
#define CSN1_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability 117
#define CSN1_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_epsClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability 110
#define CSN1_epsClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability 173
#define CSN1_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_SIZE   1


/* DEFINITIONS */
#define CSN1C_DEF_bit                    0
#define CSN1C_DEF_spare_bits             2
#define CSN1C_DEF_spare_bit              4
#define CSN1C_DEF_spare_zero            17
#define CSN1C_DEF_UESecurityCapability  19
#define CSN1C_DEF_APNAggregateMaxBitRate 150
#define CSN1C_DEF_EPS_QOS              189
#define CSN1C_DEF_A5_CM3_bits          265
#define CSN1C_DEF_epsQualityOfServ     282
#define CSN1C_DEF_spare_padding        425
#define CSN1C_DEF_zero_padding         441
#define CSN1C_DEF_epsClassmark3Value   457
#define CSN1C_DEF_epsMsNetwkCpblty     1250
#define CSN1C_DEF_UENetworkCapability  1381
/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UENetworkCapability".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UENetworkCapability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UENetworkCapability* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UENetworkCapability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UENetworkCapability* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UESecurityCapability".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UESecurityCapability (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UESecurityCapability* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UESecurityCapability (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UESecurityCapability* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "APNAggregateMaxBitRate".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_APNAggregateMaxBitRate (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_APNAggregateMaxBitRate* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_APNAggregateMaxBitRate (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_APNAggregateMaxBitRate* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPS_QOS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_QOS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_QOS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_QOS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_QOS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsClassmark3Value".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsClassmark3Value (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsClassmark3Value* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsClassmark3Value (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsClassmark3Value* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsMsNetwkCpblty".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsMsNetwkCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsMsNetwkCpblty* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsMsNetwkCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsMsNetwkCpblty* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "epsQualityOfServ".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_epsQualityOfServ (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_epsQualityOfServ* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_epsQualityOfServ (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_epsQualityOfServ* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

