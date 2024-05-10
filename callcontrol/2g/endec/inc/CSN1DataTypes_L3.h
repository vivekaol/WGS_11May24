/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __CSN1DataTypes_L3_h
#define __CSN1DataTypes_L3_h
/* ZZZ */

#include "csn1clib.h"
#include "ed_lib.h"
#include "ed_c_L3.h"
#include "ed_user.h"
#include "endec_configs_L3.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

extern TCSN1CProgram Program_L3_Program;


#ifdef CSN1C_LABEL_NAMES
/* List of label names */
extern const char* const Program_L3_Labels [];
#endif

/* LABELS */

#define CSN1_Content_PS                122
#define CSN1_Content_PS_SIZE             1
#define CSN1_Content_VBS               124
#define CSN1_Content_VBS_SIZE            1
#define CSN1_Content_VGCS              123
#define CSN1_Content_VGCS_SIZE           1
#define CSN1_Content_ES_IND            121
#define CSN1_Content_ES_IND_SIZE         1
#define CSN1_Content_A5_bits           113
#define CSN1_Content_A5_bits_SIZE        7
#define CSN1_GEA1_bits_GEA_1            79
#define CSN1_GEA1_bits_GEA_1_SIZE        1
#define CSN1_A5_CM3_bits_A5_4            3
#define CSN1_A5_CM3_bits_A5_4_SIZE       1
#define CSN1_A5_CM3_bits_A5_5            2
#define CSN1_A5_CM3_bits_A5_5_SIZE       1
#define CSN1_A5_CM3_bits_A5_6            1
#define CSN1_A5_CM3_bits_A5_6_SIZE       1
#define CSN1_A5_CM3_bits_A5_7            0
#define CSN1_A5_CM3_bits_A5_7_SIZE       1
#define CSN1_A5_5_12_bits_A5_1         114
#define CSN1_A5_5_12_bits_A5_1_SIZE      1
#define CSN1_A5_5_12_bits_A5_2         115
#define CSN1_A5_5_12_bits_A5_2_SIZE      1
#define CSN1_A5_5_12_bits_A5_3         116
#define CSN1_A5_5_12_bits_A5_3_SIZE      1
#define CSN1_A5_5_12_bits_A5_4         117
#define CSN1_A5_5_12_bits_A5_4_SIZE      1
#define CSN1_A5_5_12_bits_A5_5         118
#define CSN1_A5_5_12_bits_A5_5_SIZE      1
#define CSN1_A5_5_12_bits_A5_6         119
#define CSN1_A5_5_12_bits_A5_6_SIZE      1
#define CSN1_A5_5_12_bits_A5_7         120
#define CSN1_A5_5_12_bits_A5_7_SIZE      1
#define CSN1_MsNetwkCpblty_GIA_4       103
#define CSN1_MsNetwkCpblty_GIA_4_SIZE    1
#define CSN1_MsNetwkCpblty_GIA_5       104
#define CSN1_MsNetwkCpblty_GIA_5_SIZE    1
#define CSN1_MsNetwkCpblty_GIA_6       105
#define CSN1_MsNetwkCpblty_GIA_6_SIZE    1
#define CSN1_MsNetwkCpblty_GIA_7       106
#define CSN1_MsNetwkCpblty_GIA_7_SIZE    1
#define CSN1_Content_Uplink_EGPRS2     165
#define CSN1_Content_Uplink_EGPRS2_SIZE   2
#define CSN1_ProtocolCfgOpt_Length      11
#define CSN1_ProtocolCfgOpt_Length_SIZE   8
#define CSN1_Content_DTR_Capability    179
#define CSN1_Content_DTR_Capability_SIZE   1
#define CSN1_Content_IPA_Capability    184
#define CSN1_Content_IPA_Capability_SIZE   1
#define CSN1_Content_DLMC_Capability   189
#define CSN1_Content_DLMC_Capability_SIZE   0
#define CSN1_Content_Downlink_EGPRS2   166
#define CSN1_Content_Downlink_EGPRS2_SIZE   2
#define CSN1_Content_EMSR_Capability   180
#define CSN1_Content_EMSR_Capability_SIZE   1
#define CSN1_Content_EMST_Capability   175
#define CSN1_Content_EMST_Capability_SIZE   1
#define CSN1_Content_FANR_Capability   183
#define CSN1_Content_FANR_Capability_SIZE   1
#define CSN1_Content_MTTI_Capability   176
#define CSN1_Content_MTTI_Capability_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_2    87
#define CSN1_Extended_GEA_bits_GEA_2_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_3    88
#define CSN1_Extended_GEA_bits_GEA_3_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_4    89
#define CSN1_Extended_GEA_bits_GEA_4_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_5    90
#define CSN1_Extended_GEA_bits_GEA_5_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_6    91
#define CSN1_Extended_GEA_bits_GEA_6_SIZE   1
#define CSN1_Extended_GEA_bits_GEA_7    92
#define CSN1_Extended_GEA_bits_GEA_7_SIZE   1
#define CSN1_ProtocolCfgOpt_Contents    12
#define CSN1_ProtocolCfgOpt_Contents_SIZE   0
#define CSN1_MsNetwkCpblty_ISR_support  97
#define CSN1_MsNetwkCpblty_ISR_support_SIZE   1
#define CSN1_ProtocolCfgOpt_ProtocolId  10
#define CSN1_ProtocolCfgOpt_ProtocolId_SIZE  16
#define CSN1_Content_E_UTRA_FDD_support 167
#define CSN1_Content_E_UTRA_FDD_support_SIZE   1
#define CSN1_Content_E_UTRA_TDD_support 168
#define CSN1_Content_E_UTRA_TDD_support_SIZE   1
#define CSN1_Content_TIGHTER_Capability 182
#define CSN1_Content_TIGHTER_Capability_SIZE   2
#define CSN1_MsNetwkCpblty_UCS2_support  82
#define CSN1_MsNetwkCpblty_UCS2_support_SIZE   1
#define CSN1_ProtocolCfgOpt_ContainerId  14
#define CSN1_ProtocolCfgOpt_ContainerId_SIZE  16
#define CSN1_Classmark3Value_VAMOS_Level  67
#define CSN1_Classmark3Value_VAMOS_Level_SIZE   2
#define CSN1_Content_RF_Power_Capability 112
#define CSN1_Content_RF_Power_Capability_SIZE   3
#define CSN1_MsNetwkCpblty_NF_capability 100
#define CSN1_MsNetwkCpblty_NF_capability_SIZE   1
#define CSN1_ProtocolCfgOpt_ProtocolCfgs   9
#define CSN1_ProtocolCfgOpt_ProtocolCfgs_SIZE   0
#define CSN1_Content_Multislot_capability 125
#define CSN1_Content_Multislot_capability_SIZE   0
#define CSN1_MsNetwkCpblty_EPC_capability  99
#define CSN1_MsNetwkCpblty_EPC_capability_SIZE   1
#define CSN1_ProtocolCfgOpt_ContainerCfgs  13
#define CSN1_ProtocolCfgOpt_ContainerCfgs_SIZE   0
#define CSN1_Single_Band_Support_GSM_Band  39
#define CSN1_Single_Band_Support_GSM_Band_SIZE   4
#define CSN1_Classmark3Value_UCS2_treatment  20
#define CSN1_Classmark3Value_UCS2_treatment_SIZE   1
#define CSN1_Content_PS_Handover_Capability 157
#define CSN1_Content_PS_Handover_Capability_SIZE   1
#define CSN1_Content__8PSK_Power_Capability 137
#define CSN1_Content__8PSK_Power_Capability_SIZE   2
#define CSN1_MsNetwkCpblty_PFC_feature_mode  86
#define CSN1_MsNetwkCpblty_PFC_feature_mode_SIZE   1
#define CSN1_MsNetwkCpblty_SoLSA_Capability  84
#define CSN1_MsNetwkCpblty_SoLSA_Capability_SIZE   1
#define CSN1_Classmark3Value_ER_Band_Support  74
#define CSN1_Classmark3Value_ER_Band_Support_SIZE   1
#define CSN1_Classmark3Value_Offset_required  55
#define CSN1_Classmark3Value_Offset_required_SIZE   1
#define CSN1_Classmark3Value_Single_Slot_DTM  37
#define CSN1_Classmark3Value_Single_Slot_DTM_SIZE   1
#define CSN1_Content_DTM_Handover_Capability 158
#define CSN1_Content_DTM_Handover_Capability_SIZE   1
#define CSN1_Content_GERAN_Feature_Package_1 144
#define CSN1_Content_GERAN_Feature_Package_1_SIZE   1
#define CSN1_Content_Multiple_TBF_Capability 151
#define CSN1_Content_Multiple_TBF_Capability_SIZE   1
#define CSN1_Content_RLC_Non_persistent_Mode 163
#define CSN1_Content_RLC_Non_persistent_Mode_SIZE   1
#define CSN1_MsNetwkCpblty_LCS_VA_capability  93
#define CSN1_MsNetwkCpblty_LCS_VA_capability_SIZE   1
#define CSN1_Content_Revision_Level_Indicator 139
#define CSN1_Content_Revision_Level_Indicator_SIZE   1
#define CSN1_Content_UTRA_CSG_Cells_Reporting 177
#define CSN1_Content_UTRA_CSG_Cells_Reporting_SIZE   1
#define CSN1_Access_capabilities_struct_Length 110
#define CSN1_Access_capabilities_struct_Length_SIZE   7
#define CSN1_Content_High_Multislot_Capability 148
#define CSN1_Content_High_Multislot_Capability_SIZE   2
#define CSN1_GERAN_Iu_Mode_Capabilities_Length   4
#define CSN1_GERAN_Iu_Mode_Capabilities_Length_SIZE   4
#define CSN1_Classmark3Value_E_UTRA_FDD_support  62
#define CSN1_Classmark3Value_E_UTRA_FDD_support_SIZE   1
#define CSN1_Classmark3Value_E_UTRA_TDD_support  63
#define CSN1_Classmark3Value_E_UTRA_TDD_support_SIZE   1
#define CSN1_Classmark3Value_TIGHTER_Capability  68
#define CSN1_Classmark3Value_TIGHTER_Capability_SIZE   2
#define CSN1_Content_E_UTRA_CSG_Cells_Reporting 178
#define CSN1_Content_E_UTRA_CSG_Cells_Reporting_SIZE   1
#define CSN1_Content_GAN_PS_Handover_Capability 162
#define CSN1_Content_GAN_PS_Handover_Capability_SIZE   1
#define CSN1_Content_Reduced_Latency_Capability 164
#define CSN1_Content_Reduced_Latency_Capability_SIZE   1
#define CSN1_MS_Measurement_capability_SM_VALUE  23
#define CSN1_MS_Measurement_capability_SM_VALUE_SIZE   4
#define CSN1_Classmark3Value_Multiband_supported  15
#define CSN1_Classmark3Value_Multiband_supported_SIZE   3
#define CSN1_Content_DTM_Enhancements_Capability 154
#define CSN1_Content_DTM_Enhancements_Capability_SIZE   1
#define CSN1_Content_Extended_EARFCN_value_range 196
#define CSN1_Content_Extended_EARFCN_value_range_SIZE   1
#define CSN1_MS_Measurement_capability_SMS_VALUE  22
#define CSN1_MS_Measurement_capability_SMS_VALUE_SIZE   4
#define CSN1_Receive_N_Pdu_Numbers_List_val_sapi   6
#define CSN1_Receive_N_Pdu_Numbers_List_val_sapi_SIZE   4
#define CSN1__8_PSK_Struct_Modulation_Capability  26
#define CSN1__8_PSK_Struct_Modulation_Capability_SIZE   1
#define CSN1_Content_Flexible_Timeslot_Assignment 161
#define CSN1_Content_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_Content_GMSK_Multislot_Power_Profile 149
#define CSN1_Content_GMSK_Multislot_Power_Profile_SIZE   2
#define CSN1_MsNetwkCpblty_SS_Screening_Indicator  83
#define CSN1_MsNetwkCpblty_SS_Screening_Indicator_SIZE   2
#define CSN1_Multislot_capability_struct_SM_VALUE 130
#define CSN1_Multislot_capability_struct_SM_VALUE_SIZE   4
#define CSN1_ProtocolCfgOpt_ConfigurationProtocol   8
#define CSN1_ProtocolCfgOpt_ConfigurationProtocol_SIZE   3
#define CSN1_Content_GERAN_Network_Sharing_support 185
#define CSN1_Content_GERAN_Network_Sharing_support_SIZE   1
#define CSN1_Multislot_capability_struct_SMS_VALUE 129
#define CSN1_Multislot_capability_struct_SMS_VALUE_SIZE   4
#define CSN1_Content_DTM_GPRS_High_Multi_Slot_Class 155
#define CSN1_Content_DTM_GPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_Content__8_PSK_Multislot_Power_Profile 150
#define CSN1_Content__8_PSK_Multislot_Power_Profile_SIZE   2
#define CSN1_MsNetwkCpblty_Revision_level_indicator  85
#define CSN1_MsNetwkCpblty_Revision_level_indicator_SIZE   1
#define CSN1_Classmark3Value_GERAN_Feature_Package_1  42
#define CSN1_Classmark3Value_GERAN_Feature_Package_1_SIZE   1
#define CSN1_Classmark3Value_GERAN_Feature_Package_2  46
#define CSN1_Classmark3Value_GERAN_Feature_Package_2_SIZE   1
#define CSN1_Classmark3Value_GSM_400_Bands_Supported  29
#define CSN1_Classmark3Value_GSM_400_Bands_Supported_SIZE   2
#define CSN1_Content_DTM_EGPRS_High_Multi_Slot_Class 156
#define CSN1_Content_DTM_EGPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_Classmark3Value_Repeated_ACCH_Capability  57
#define CSN1_Classmark3Value_Repeated_ACCH_Capability_SIZE   1
#define CSN1_Classmark3Value_UTRA_CSG_Cells_Reporting  66
#define CSN1_Classmark3Value_UTRA_CSG_Cells_Reporting_SIZE   1
#define CSN1_Classmark3Value_DTM_GPRS_Multi_Slot_Class  36
#define CSN1_Classmark3Value_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Classmark3Value_High_Multislot_Capability  45
#define CSN1_Classmark3Value_High_Multislot_Capability_SIZE   2
#define CSN1_Classmark3Value_T_GSM_400_Bands_Supported  49
#define CSN1_Classmark3Value_T_GSM_400_Bands_Supported_SIZE   2
#define CSN1_MS_RA_capability_value_part_struct_Length 197
#define CSN1_MS_RA_capability_value_part_struct_Length_SIZE   7
#define CSN1_Classmark3Value_DTM_EGPRS_Multi_Slot_Class  38
#define CSN1_Classmark3Value_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Content_Extended_DTM_GPRS_Multi_Slot_Class 145
#define CSN1_Content_Extended_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Content_Priority_based_reselection_support 170
#define CSN1_Content_Priority_based_reselection_support_SIZE   1
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1  27
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1_SIZE   2
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2  28
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2_SIZE   2
#define CSN1_Classmark3Value_DTM_Enhancements_Capability  53
#define CSN1_Classmark3Value_DTM_Enhancements_Capability_SIZE   1
#define CSN1_Classmark3Value_Extended_EARFCN_value_range  78
#define CSN1_Classmark3Value_Extended_EARFCN_value_range_SIZE   1
#define CSN1_Content_Extended_DTM_EGPRS_Multi_Slot_Class 146
#define CSN1_Content_Extended_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Content_Extended_TSC_Set_Capability_support 195
#define CSN1_Content_Extended_TSC_Set_Capability_support_SIZE   1
#define CSN1_Multislot_capability_struct_Single_Slot_DTM 135
#define CSN1_Multislot_capability_struct_Single_Slot_DTM_SIZE   1
#define CSN1_Classmark3Value_GMSK_Multislot_Power_Profile  47
#define CSN1_Classmark3Value_GMSK_Multislot_Power_Profile_SIZE   2
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability   5
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability_SIZE   1
#define CSN1_Classmark3Value_Associated_Radio_Capability_1  17
#define CSN1_Classmark3Value_Associated_Radio_Capability_1_SIZE   4
#define CSN1_Classmark3Value_Associated_Radio_Capability_2  16
#define CSN1_Classmark3Value_Associated_Radio_Capability_2_SIZE   4
#define CSN1_Classmark3Value_GERAN_Network_Sharing_support  72
#define CSN1_Classmark3Value_GERAN_Network_Sharing_support_SIZE   1
#define CSN1_Content_Enhanced_Flexible_Timeslot_Assignment 171
#define CSN1_Content_Enhanced_Flexible_Timeslot_Assignment_SIZE   0
#define CSN1_DLMC_Capability_struct_DLMC_Maximum_Bandwidth 192
#define CSN1_DLMC_Capability_struct_DLMC_Maximum_Bandwidth_SIZE   2
#define CSN1_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability  98
#define CSN1_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability_SIZE   1
#define CSN1_Access_capabilities_struct_Access_capabilities 111
#define CSN1_Access_capabilities_struct_Access_capabilities_SIZE   0
#define CSN1_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class  54
#define CSN1_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_Classmark3Value__8_PSK_Multislot_Power_Profile  48
#define CSN1_Classmark3Value__8_PSK_Multislot_Power_Profile_SIZE   2
#define CSN1_Content_Downlink_Advanced_Receiver_Performance 152
#define CSN1_Content_Downlink_Advanced_Receiver_Performance_SIZE   2
#define CSN1_MsNetwkCpblty_GERAN_network_sharing_capability 101
#define CSN1_MsNetwkCpblty_GERAN_network_sharing_capability_SIZE   1
#define CSN1_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class  56
#define CSN1_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_Classmark3Value_Extended_Measurement_Capability  21
#define CSN1_Classmark3Value_Extended_Measurement_Capability_SIZE   1
#define CSN1_MsNetwkCpblty_SM_capabilities_via_GPRS_channels  81
#define CSN1_MsNetwkCpblty_SM_capabilities_via_GPRS_channels_SIZE   1
#define CSN1_MsRadioAccessCpblty_MS_RA_capability_value_part 202
#define CSN1_MsRadioAccessCpblty_MS_RA_capability_value_part_SIZE   0
#define CSN1_Content_Downlink_Dual_Carrier_for_DTM_Capability 160
#define CSN1_Content_Downlink_Dual_Carrier_for_DTM_Capability_SIZE   1
#define CSN1_Content_Modulation_based_multislot_class_support 147
#define CSN1_Content_Modulation_based_multislot_class_support_SIZE   1
#define CSN1_DLMC_Capability_struct_DLMC_Inter_band_reception 191
#define CSN1_DLMC_Capability_struct_DLMC_Inter_band_reception_SIZE   1
#define CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class  25
#define CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class_SIZE   5
#define CSN1_MsNetwkCpblty_EMM_Combined_procedures_Capability  96
#define CSN1_MsNetwkCpblty_EMM_Combined_procedures_Capability_SIZE   1
#define CSN1_Multislot_capability_struct_ECSD_multislot_class 131
#define CSN1_Multislot_capability_struct_ECSD_multislot_class_SIZE   5
#define CSN1_Multislot_capability_struct_GPRS_multislot_class 127
#define CSN1_Multislot_capability_struct_GPRS_multislot_class_SIZE   5
#define CSN1_R_Support_R_GSM_band_Associated_Radio_Capability  18
#define CSN1_R_Support_R_GSM_band_Associated_Radio_Capability_SIZE   3
#define CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA  70
#define CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA_SIZE   2
#define CSN1_Classmark3Value_Ciphering_Mode_Setting_Capability  60
#define CSN1_Classmark3Value_Ciphering_Mode_Setting_Capability_SIZE   1
#define CSN1_Content_E_UTRA_Wideband_RSRQ_measurements_support 186
#define CSN1_Content_E_UTRA_Wideband_RSRQ_measurements_support_SIZE   1
#define CSN1_Multislot_capability_struct_EGPRS_multislot_class 132
#define CSN1_Multislot_capability_struct_EGPRS_multislot_class_SIZE   5
#define CSN1_Multislot_capability_struct_HSCSD_multislot_class 126
#define CSN1_Multislot_capability_struct_HSCSD_multislot_class_SIZE   5
#define CSN1_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class  43
#define CSN1_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Classmark3Value_Priority_based_reselection_support  65
#define CSN1_Classmark3Value_Priority_based_reselection_support_SIZE   1
#define CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class  19
#define CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class_SIZE   5
#define CSN1_Classmark3Value_Additional_Positioning_Capabilities  61
#define CSN1_Classmark3Value_Additional_Positioning_Capabilities_SIZE   1
#define CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA  71
#define CSN1_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_SIZE   2
#define CSN1_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class  44
#define CSN1_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Classmark3Value_Extended_TSC_Set_Capability_support  77
#define CSN1_Classmark3Value_Extended_TSC_Set_Capability_support_SIZE   1
#define CSN1_Classmark3Value_GSM_400_Associated_Radio_Capability  30
#define CSN1_Classmark3Value_GSM_400_Associated_Radio_Capability_SIZE   4
#define CSN1_Classmark3Value_GSM_710_Associated_Radio_Capability  58
#define CSN1_Classmark3Value_GSM_710_Associated_Radio_Capability_SIZE   4
#define CSN1_Classmark3Value_GSM_750_Associated_Radio_Capability  40
#define CSN1_Classmark3Value_GSM_750_Associated_Radio_Capability_SIZE   4
#define CSN1_Classmark3Value_GSM_850_Associated_Radio_Capability  31
#define CSN1_Classmark3Value_GSM_850_Associated_Radio_Capability_SIZE   4
#define CSN1_Content_COMPACT_Interference_Measurement_Capability 138
#define CSN1_Content_COMPACT_Interference_Measurement_Capability_SIZE   1
#define CSN1_Content_UMTS_FDD_Radio_Access_Technology_Capability 140
#define CSN1_Content_UMTS_FDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Classmark3Value_GSM_1900_Associated_Radio_Capability  32
#define CSN1_Classmark3Value_GSM_1900_Associated_Radio_Capability_SIZE   4
#define CSN1_Content_CDMA_2000_Radio_Access_Technology_Capability 142
#define CSN1_Content_CDMA_2000_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Content_Fast_Downlink_Frequency_Switching_Capability 181
#define CSN1_Content_Fast_Downlink_Frequency_Switching_Capability_SIZE   1
#define CSN1_MsNetwkCpblty_SM_capabilities_via_dedicated_channels  80
#define CSN1_MsNetwkCpblty_SM_capabilities_via_dedicated_channels_SIZE   1
#define CSN1_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH  69
#define CSN1_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH_SIZE   1
#define CSN1_Classmark3Value_T_GSM_400_Associated_Radio_Capability  50
#define CSN1_Classmark3Value_T_GSM_400_Associated_Radio_Capability_SIZE   4
#define CSN1_Classmark3Value_T_GSM_810_Associated_Radio_Capability  59
#define CSN1_Classmark3Value_T_GSM_810_Associated_Radio_Capability_SIZE   4
#define CSN1_Classmark3Value_T_GSM_900_Associated_Radio_Capability  51
#define CSN1_Classmark3Value_T_GSM_900_Associated_Radio_Capability_SIZE   4
#define CSN1_MsNetwkCpblty_User_plane_integrity_protection_support 102
#define CSN1_MsNetwkCpblty_User_plane_integrity_protection_support_SIZE   1
#define CSN1_Multislot_capability_struct_DTM_GPRS_Multi_Slot_Class 134
#define CSN1_Multislot_capability_struct_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Additional_access_technologies_struct_GMSK_Power_Class 200
#define CSN1_Additional_access_technologies_struct_GMSK_Power_Class_SIZE   3
#define CSN1_Classmark3Value_Downlink_Advanced_Receiver_Performance  52
#define CSN1_Classmark3Value_Downlink_Advanced_Receiver_Performance_SIZE   2
#define CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method  24
#define CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method_SIZE   5
#define CSN1_MS_RA_capability_value_part_struct_Access_capabilities 109
#define CSN1_MS_RA_capability_value_part_struct_Access_capabilities_SIZE   0
#define CSN1_Multislot_capability_struct_DTM_EGPRS_Multi_Slot_Class 136
#define CSN1_Multislot_capability_struct_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_Additional_access_technologies_struct__8PSK_Power_Class 201
#define CSN1_Additional_access_technologies_struct__8PSK_Power_Class_SIZE   2
#define CSN1_Content_UTRA_Multiple_Frequency_Band_Indicators_support 187
#define CSN1_Content_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_Classmark3Value_E_UTRA_Measurement_and_Reporting_support  64
#define CSN1_Classmark3Value_E_UTRA_Measurement_and_Reporting_support_SIZE   1
#define CSN1_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support  73
#define CSN1_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support_SIZE   1
#define CSN1_Content_E_UTRA_Multiple_Frequency_Band_Indicators_support 188
#define CSN1_Content_E_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_MS_RA_capability_value_part_struct_Access_Technology_Type 108
#define CSN1_MS_RA_capability_value_part_struct_Access_Technology_Type_SIZE   4
#define CSN1_MS_RA_capability_value_part_struct_MS_RA_capability_value 107
#define CSN1_MS_RA_capability_value_part_struct_MS_RA_capability_value_SIZE   0
#define CSN1_Receive_N_Pdu_Numbers_List_val_Receive_N_PDU_Number_value   7
#define CSN1_Receive_N_Pdu_Numbers_List_val_Receive_N_PDU_Number_value_SIZE   8
#define CSN1_Classmark3Value_UMTS_FDD_Radio_Access_Technology_Capability  33
#define CSN1_Classmark3Value_UMTS_FDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Additional_access_technologies_struct_Access_Technology_Type 199
#define CSN1_Additional_access_technologies_struct_Access_Technology_Type_SIZE   4
#define CSN1_Classmark3Value_CDMA_2000_Radio_Access_Technology_Capability  35
#define CSN1_Classmark3Value_CDMA_2000_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Content_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode 169
#define CSN1_Content_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_SIZE   2
#define CSN1_Content_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability 143
#define CSN1_Content_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Content_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability 141
#define CSN1_Content_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support  75
#define CSN1_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Carriers 194
#define CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Carriers_SIZE   3
#define CSN1_DLMC_Capability_struct_DLMC_Non_contiguous_intra_band_reception 190
#define CSN1_DLMC_Capability_struct_DLMC_Non_contiguous_intra_band_reception_SIZE   2
#define CSN1_Content_Extended_RLC_MAC_Control_Message_Segmentation_Capability 153
#define CSN1_Content_Extended_RLC_MAC_Control_Message_Segmentation_Capability_SIZE   1
#define CSN1_Content_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier 159
#define CSN1_Content_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_SIZE   3
#define CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Timeslots 193
#define CSN1_DLMC_Capability_struct_DLMC_Maximum_Number_of_Downlink_Timeslots_SIZE   6
#define CSN1_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support  76
#define CSN1_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_Content_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM 174
#define CSN1_Content_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_SIZE   1
#define CSN1_MS_RA_capability_value_part_struct_Additional_access_technologies 198
#define CSN1_MS_RA_capability_value_part_struct_Additional_access_technologies_SIZE   9
#define CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability  94
#define CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_SIZE   1
#define CSN1_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability  41
#define CSN1_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Classmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability  34
#define CSN1_Classmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability  95
#define CSN1_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_SIZE   1
#define CSN1_Multislot_capability_struct_GPRS_Extended_Dynamic_Allocation_Capability 128
#define CSN1_Multislot_capability_struct_GPRS_Extended_Dynamic_Allocation_Capability_SIZE   1
#define CSN1_Multislot_capability_struct_EGPRS_Extended_Dynamic_Allocation_Capability 133
#define CSN1_Multislot_capability_struct_EGPRS_Extended_Dynamic_Allocation_Capability_SIZE   1
#define CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_Alternative_EFTA_Multislot_Class 172
#define CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_Alternative_EFTA_Multislot_Class_SIZE   4
#define CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier 173
#define CSN1_Enhanced_Flexible_Timeslot_Assignment_struct_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_SIZE   3


/* DEFINITIONS */
#define CSN1C_DEF_bit                    0
#define CSN1C_DEF_spare_bits             2
#define CSN1C_DEF_spare_bit              4
#define CSN1C_DEF_A5_CM3_bits           17
#define CSN1C_DEF_GERAN_Iu_Mode_Capabilities  30
#define CSN1C_DEF_Receive_N_Pdu_Numbers_List_val  52
#define CSN1C_DEF_ProtocolCfgOpt        69
#define CSN1C_DEF_zero_padding         154
#define CSN1C_DEF_spare_padding        170
#define CSN1C_DEF_Classmark3Value      186
#define CSN1C_DEF_ReceiveNPduNumbersList 951
#define CSN1C_DEF_MsNetwkCpblty        964
#define CSN1C_DEF_MS_RA_capability_value_part_struct 1105
#define CSN1C_DEF_MsRadioAccessCpblty  1833
/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Classmark3Value".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Classmark3Value (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Classmark3Value* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Classmark3Value (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Classmark3Value* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ReceiveNPduNumbersList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ReceiveNPduNumbersList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ReceiveNPduNumbersList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ReceiveNPduNumbersList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ReceiveNPduNumbersList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MsNetwkCpblty".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MsNetwkCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MsNetwkCpblty* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MsNetwkCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MsNetwkCpblty* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MsRadioAccessCpblty".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MsRadioAccessCpblty (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MsRadioAccessCpblty* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MsRadioAccessCpblty (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MsRadioAccessCpblty* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ProtocolCfgOpt".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ProtocolCfgOpt (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ProtocolCfgOpt* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ProtocolCfgOpt (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ProtocolCfgOpt* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

