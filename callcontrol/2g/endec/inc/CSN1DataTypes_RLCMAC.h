/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __CSN1DataTypes_RLCMAC_h
#define __CSN1DataTypes_RLCMAC_h
/* ZZZ */

#include "csn1clib.h"
#include "ed_lib.h"
#include "ed_c_RLCMAC.h"
#include "ed_user.h"
#include "endec_configs_RLCMAC.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

extern TCSN1CProgram Program_RLCMAC_Program;


#ifdef CSN1C_LABEL_NAMES
/* List of label names */
extern const char* const Program_RLCMAC_Labels [];
#endif

/* LABELS */

#define CSN1_Content_PS                1300
#define CSN1_Content_PS_SIZE             1
#define CSN1_Content_VBS               1302
#define CSN1_Content_VBS_SIZE            1
#define CSN1_TMGI_IE_MCC               255
#define CSN1_TMGI_IE_MCC_SIZE           12
#define CSN1_TMGI_IE_MNC               256
#define CSN1_TMGI_IE_MNC_SIZE           12
#define CSN1_Content_VGCS              1301
#define CSN1_Content_VGCS_SIZE           1
#define CSN1_Content_ES_IND            1299
#define CSN1_Content_ES_IND_SIZE         1
#define CSN1_Content_A5_bits           1291
#define CSN1_Content_A5_bits_SIZE        7
#define CSN1_RTD6_Struct_RTD           100
#define CSN1_RTD6_Struct_RTD_SIZE        6
#define CSN1_PSC_Group_IE_PSC          2031
#define CSN1_PSC_Group_IE_PSC_SIZE       9
#define CSN1_RTD12_Struct_RTD          101
#define CSN1_RTD12_Struct_RTD_SIZE      12
#define CSN1_A5_5_12_bits_A5_1         1292
#define CSN1_A5_5_12_bits_A5_1_SIZE      1
#define CSN1_A5_5_12_bits_A5_2         1293
#define CSN1_A5_5_12_bits_A5_2_SIZE      1
#define CSN1_A5_5_12_bits_A5_3         1294
#define CSN1_A5_5_12_bits_A5_3_SIZE      1
#define CSN1_A5_5_12_bits_A5_4         1295
#define CSN1_A5_5_12_bits_A5_4_SIZE      1
#define CSN1_A5_5_12_bits_A5_5         1296
#define CSN1_A5_5_12_bits_A5_5_SIZE      1
#define CSN1_A5_5_12_bits_A5_6         1297
#define CSN1_A5_5_12_bits_A5_6_SIZE      1
#define CSN1_A5_5_12_bits_A5_7         1298
#define CSN1_A5_5_12_bits_A5_7_SIZE      1
#define CSN1_HCS_struct_HCS_THR         14
#define CSN1_HCS_struct_HCS_THR_SIZE     5
#define CSN1_PCID_Group_IE_PCID        272
#define CSN1_PCID_Group_IE_PCID_SIZE     9
#define CSN1_PLMN_ID_struct_MCC        277
#define CSN1_PLMN_ID_struct_MCC_SIZE    12
#define CSN1_PLMN_ID_struct_MNC        278
#define CSN1_PLMN_ID_struct_MNC_SIZE    12
#define CSN1_GRA_ID_struct_GRA_ID      487
#define CSN1_GRA_ID_struct_GRA_ID_SIZE  16
#define CSN1_Reject_struct_Ignore      3109
#define CSN1_Reject_struct_Ignore_SIZE   0
#define CSN1_RLC_Entity_Struct_PFI     605
#define CSN1_RLC_Entity_Struct_PFI_SIZE   7
#define CSN1_RLC_Entity_Struct_TFI     602
#define CSN1_RLC_Entity_Struct_TFI_SIZE   5
#define CSN1_RESEGMENT_IE_Resegment    1616
#define CSN1_RESEGMENT_IE_Resegment_SIZE   1
#define CSN1_MBMS_Information_Ignore   3242
#define CSN1_MBMS_Information_Ignore_SIZE   0
#define CSN1_TMGI_IE_MBMS_SERVICE_ID   254
#define CSN1_TMGI_IE_MBMS_SERVICE_ID_SIZE  24
#define CSN1_EM1_struct_INT_FREQUENCY  1126
#define CSN1_EM1_struct_INT_FREQUENCY_SIZE   5
#define CSN1_EM1_struct_NCC_PERMITTED  1125
#define CSN1_EM1_struct_NCC_PERMITTED_SIZE   8
#define CSN1_GPRS_Cell_Options_IE_NMO  1028
#define CSN1_GPRS_Cell_Options_IE_NMO_SIZE   2
#define CSN1_GPRS_Cell_Options_IE_ext  1038
#define CSN1_GPRS_Cell_Options_IE_ext_SIZE   0
#define CSN1_Global_TFI_IE_UPLINK_TFI  221
#define CSN1_Global_TFI_IE_UPLINK_TFI_SIZE   5
#define CSN1_NCP2_Property_struct_BCC   95
#define CSN1_NCP2_Property_struct_BCC_SIZE   3
#define CSN1_PSC_Group_IE_PSC_Pattern  2033
#define CSN1_PSC_Group_IE_PSC_Pattern_SIZE   0
#define CSN1_Reject_struct_Global_TFI  283
#define CSN1_Reject_struct_Global_TFI_SIZE   6
#define CSN1_Channel_Group_struct_MAIO 103
#define CSN1_Channel_Group_struct_MAIO_SIZE   6
#define CSN1_HCS_struct_PRIORITY_CLASS  13
#define CSN1_HCS_struct_PRIORITY_CLASS_SIZE   3
#define CSN1_MPRACH_description_IE_USF 2448
#define CSN1_MPRACH_description_IE_USF_SIZE   3
#define CSN1_PSI13_message_content_RAC 1217
#define CSN1_PSI13_message_content_RAC_SIZE   8
#define CSN1_PSI1_message_content_MSCR 1145
#define CSN1_PSI1_message_content_MSCR_SIZE   1
#define CSN1_Reject_struct_TLLI_G_RNTI 284
#define CSN1_Reject_struct_TLLI_G_RNTI_SIZE  32
#define CSN1_Additional_PFCs_struct_PFI 264
#define CSN1_Additional_PFCs_struct_PFI_SIZE   7
#define CSN1_Additional_PFCs_struct_TFI 262
#define CSN1_Additional_PFCs_struct_TFI_SIZE   5
#define CSN1_Cell_Identification_IE_RAC 595
#define CSN1_Cell_Identification_IE_RAC_SIZE   8
#define CSN1_Channel_Group_struct_ARFCN 104
#define CSN1_Channel_Group_struct_ARFCN_SIZE  10
#define CSN1_EGPRS_Level_IE_EGPRS_Level 1430
#define CSN1_EGPRS_Level_IE_EGPRS_Level_SIZE   2
#define CSN1_GPRS_Cell_Options_IE_T3168 1029
#define CSN1_GPRS_Cell_Options_IE_T3168_SIZE   3
#define CSN1_GPRS_Cell_Options_IE_T3192 1030
#define CSN1_GPRS_Cell_Options_IE_T3192_SIZE   3
#define CSN1_Global_TFI_IE_DOWNLINK_TFI 222
#define CSN1_Global_TFI_IE_DOWNLINK_TFI_SIZE   5
#define CSN1_MBMS_Sessions_List_IE_TMGI 600
#define CSN1_MBMS_Sessions_List_IE_TMGI_SIZE   0
#define CSN1_PCID_Group_IE_PCID_Pattern 275
#define CSN1_PCID_Group_IE_PCID_Pattern_SIZE   0
#define CSN1_PSI1_message_content_SGSNR 1146
#define CSN1_PSI1_message_content_SGSNR_SIZE   1
#define CSN1_RLC_Entity_Struct_RLC_MODE 603
#define CSN1_RLC_Entity_Struct_RLC_MODE_SIZE   1
#define CSN1_Response_Time_struct_TRMIN  71
#define CSN1_Response_Time_struct_TRMIN_SIZE   6
#define CSN1_TLLI_G_RNTI_IE_TLLI_G_RNTI 1381
#define CSN1_TLLI_G_RNTI_IE_TLLI_G_RNTI_SIZE  32
#define CSN1_A_Gb_mode_Reject_struct_PFI 670
#define CSN1_A_Gb_mode_Reject_struct_PFI_SIZE   7
#define CSN1_Content_RF_Power_Capability 1290
#define CSN1_Content_RF_Power_Capability_SIZE   3
#define CSN1_Dynamic_Allocation_2_IE_USF 1873
#define CSN1_Dynamic_Allocation_2_IE_USF_SIZE   3
#define CSN1_Dynamic_Allocation_3_IE_TSC 1066
#define CSN1_Dynamic_Allocation_3_IE_TSC_SIZE   3
#define CSN1_Dynamic_Allocation_3_IE_USF 1067
#define CSN1_Dynamic_Allocation_3_IE_USF_SIZE   3
#define CSN1_EGPRS_mode_2_IE_BEP_PERIOD2 1760
#define CSN1_EGPRS_mode_2_IE_BEP_PERIOD2_SIZE   4
#define CSN1_Frequency_Parameters_IE_TSC 1252
#define CSN1_Frequency_Parameters_IE_TSC_SIZE   3
#define CSN1_GSM_target_cell_struct_BSIC 2297
#define CSN1_GSM_target_cell_struct_BSIC_SIZE   6
#define CSN1_Gen_Cell_Sel_struct_T_RESEL 1499
#define CSN1_Gen_Cell_Sel_struct_T_RESEL_SIZE   3
#define CSN1_Iu_mode_Reject_struct_RB_Id 668
#define CSN1_Iu_mode_Reject_struct_RB_Id_SIZE   5
#define CSN1_Non_GPRS_Cell_Options_IE_EC 1449
#define CSN1_Non_GPRS_Cell_Options_IE_EC_SIZE   1
#define CSN1_PBCCH_Description_struct_Pb 1225
#define CSN1_PBCCH_Description_struct_Pb_SIZE   4
#define CSN1_PBCCH_Description_struct_TN 1227
#define CSN1_PBCCH_Description_struct_TN_SIZE   3
#define CSN1_PBCCH_information_struct_Pb 1014
#define CSN1_PBCCH_information_struct_Pb_SIZE   4
#define CSN1_PBCCH_information_struct_TN 1016
#define CSN1_PBCCH_information_struct_TN_SIZE   3
#define CSN1_PSI13_message_content_SGSNR 1230
#define CSN1_PSI13_message_content_SGSNR_SIZE   1
#define CSN1_Uplink_Assignment_struct_P0 1237
#define CSN1_Uplink_Assignment_struct_P0_SIZE   4
#define CSN1_COMPACT_reduced_MA_IE_MAIO_2 253
#define CSN1_COMPACT_reduced_MA_IE_MAIO_2_SIZE   6
#define CSN1_Content_Multislot_capability 1303
#define CSN1_Content_Multislot_capability_SIZE   0
#define CSN1_Direct_encoding_2_struct_HSN 1263
#define CSN1_Direct_encoding_2_struct_HSN_SIZE   6
#define CSN1_Dynamic_Allocation_2_IE_N_TS 1876
#define CSN1_Dynamic_Allocation_2_IE_N_TS_SIZE   4
#define CSN1_EPD_A_N_Extension_Info_RB_Id 1889
#define CSN1_EPD_A_N_Extension_Info_RB_Id_SIZE   5
#define CSN1_GPRS_Cell_Options_IE_PAN_DEC 1035
#define CSN1_GPRS_Cell_Options_IE_PAN_DEC_SIZE   3
#define CSN1_GPRS_Cell_Options_IE_PAN_INC 1036
#define CSN1_GPRS_Cell_Options_IE_PAN_INC_SIZE   3
#define CSN1_GPRS_Cell_Options_IE_PAN_MAX 1037
#define CSN1_GPRS_Cell_Options_IE_PAN_MAX_SIZE   3
#define CSN1_GPRS_Mobile_Allocation_IE_MA 587
#define CSN1_GPRS_Mobile_Allocation_IE_MA_SIZE   0
#define CSN1_GSM_target_cell_struct_ARFCN 2296
#define CSN1_GSM_target_cell_struct_ARFCN_SIZE  10
#define CSN1_Gen_Cell_Sel_struct_C31_HYST 1497
#define CSN1_Gen_Cell_Sel_struct_C31_HYST_SIZE   1
#define CSN1_Gen_Cell_Sel_struct_C32_QUAL 1498
#define CSN1_Gen_Cell_Sel_struct_C32_QUAL_SIZE   1
#define CSN1_Non_GPRS_Cell_Options_IE_ATT 1438
#define CSN1_Non_GPRS_Cell_Options_IE_ATT_SIZE   1
#define CSN1_Non_GPRS_Cell_Options_IE_DTX 1442
#define CSN1_Non_GPRS_Cell_Options_IE_DTX_SIZE   2
#define CSN1_Non_GPRS_Cell_Options_IE_ext 1451
#define CSN1_Non_GPRS_Cell_Options_IE_ext_SIZE   0
#define CSN1_PBCCH_Description_struct_TSC 1226
#define CSN1_PBCCH_Description_struct_TSC_SIZE   3
#define CSN1_PBCCH_information_struct_TSC 1015
#define CSN1_PBCCH_information_struct_TSC_SIZE   3
#define CSN1_PCCCH_Description_struct_TSC 1464
#define CSN1_PCCCH_Description_struct_TSC_SIZE   3
#define CSN1_Power_Command_struct_FPC_EPC 742
#define CSN1_Power_Command_struct_FPC_EPC_SIZE   1
#define CSN1_Additional_PFCs_struct_DN_PFI  78
#define CSN1_Additional_PFCs_struct_DN_PFI_SIZE   7
#define CSN1_Additional_PFCs_struct_UP_PFI 124
#define CSN1_Additional_PFCs_struct_UP_PFI_SIZE   7
#define CSN1_Cell_Selection_struct_EXC_ACC 302
#define CSN1_Cell_Selection_struct_EXC_ACC_SIZE   1
#define CSN1_Direct_encoding_1_struct_MAIO 1254
#define CSN1_Direct_encoding_1_struct_MAIO_SIZE   6
#define CSN1_Direct_encoding_2_struct_MAIO 1262
#define CSN1_Direct_encoding_2_struct_MAIO_SIZE   6
#define CSN1_Dynamic_Allocation_2_IE_GAMMA 1874
#define CSN1_Dynamic_Allocation_2_IE_GAMMA_SIZE   5
#define CSN1_Dynamic_Allocation_2_IE_N_USF 1877
#define CSN1_Dynamic_Allocation_2_IE_N_USF_SIZE   4
#define CSN1_Dynamic_Allocation_2_IE_P0_C1 1864
#define CSN1_Dynamic_Allocation_2_IE_P0_C1_SIZE   4
#define CSN1_Dynamic_Allocation_2_IE_P0_C2 1866
#define CSN1_Dynamic_Allocation_2_IE_P0_C2_SIZE   4
#define CSN1_Dynamic_Allocation_2_IE_USF_2 1875
#define CSN1_Dynamic_Allocation_2_IE_USF_2_SIZE   3
#define CSN1_Dynamic_Allocation_3_IE_ALPHA 1065
#define CSN1_Dynamic_Allocation_3_IE_ALPHA_SIZE   4
#define CSN1_Dynamic_Allocation_3_IE_GAMMA 1068
#define CSN1_Dynamic_Allocation_3_IE_GAMMA_SIZE   5
#define CSN1_Dynamic_Allocation_3_IE_USF_2 1069
#define CSN1_Dynamic_Allocation_3_IE_USF_2_SIZE   3
#define CSN1_EGPRS_mode_struct_BEP_PERIOD2 1349
#define CSN1_EGPRS_mode_struct_BEP_PERIOD2_SIZE   4
#define CSN1_EM1_struct_EXT_FREQUENCY_LIST 1128
#define CSN1_EM1_struct_EXT_FREQUENCY_LIST_SIZE   0
#define CSN1_EM1_struct_EXT_REPORTING_TYPE 1124
#define CSN1_EM1_struct_EXT_REPORTING_TYPE_SIZE   2
#define CSN1_E_UTRAN_Target_cell_IE_EARFCN 265
#define CSN1_E_UTRAN_Target_cell_IE_EARFCN_SIZE  16
#define CSN1_Frequency_Parameters_IE_ARFCN 1266
#define CSN1_Frequency_Parameters_IE_ARFCN_SIZE  10
#define CSN1_GPRS_Mobile_Allocation_IE_HSN 583
#define CSN1_GPRS_Mobile_Allocation_IE_HSN_SIZE   6
#define CSN1_Indirect_encoding_struct_MAIO 1257
#define CSN1_Indirect_encoding_struct_MAIO_SIZE   6
#define CSN1_MPRACH_description_struct_USF 2288
#define CSN1_MPRACH_description_struct_USF_SIZE   3
#define CSN1_Non_GPRS_Cell_Options_IE_NECI 1440
#define CSN1_Non_GPRS_Cell_Options_IE_NECI_SIZE   1
#define CSN1_Non_GPRS_Cell_Options_IE_PWRC 1441
#define CSN1_Non_GPRS_Cell_Options_IE_PWRC_SIZE   1
#define CSN1_PBCCH_Description_struct_2_Pb 2129
#define CSN1_PBCCH_Description_struct_2_Pb_SIZE   4
#define CSN1_PBCCH_Description_struct_2_TN 2130
#define CSN1_PBCCH_Description_struct_2_TN_SIZE   3
#define CSN1_PBCCH_Description_struct_MAIO 1229
#define CSN1_PBCCH_Description_struct_MAIO_SIZE   6
#define CSN1_PRACH_Control_Parameters_IE_S 246
#define CSN1_PRACH_Control_Parameters_IE_S_SIZE   4
#define CSN1_PSI16_message_content__3G_LAC 494
#define CSN1_PSI16_message_content__3G_LAC_SIZE  16
#define CSN1_PSI16_message_content__3G_RAC 495
#define CSN1_PSI16_message_content__3G_RAC_SIZE   8
#define CSN1_Page_info_struct_PAGING_CAUSE  87
#define CSN1_Page_info_struct_PAGING_CAUSE_SIZE   3
#define CSN1_Reject_struct_WAIT_INDICATION 285
#define CSN1_Reject_struct_WAIT_INDICATION_SIZE   8
#define CSN1_Add_Frequency_list_struct_BSIC 1363
#define CSN1_Add_Frequency_list_struct_BSIC_SIZE   6
#define CSN1_Cell_Selection_struct_bis_BSIC 428
#define CSN1_Cell_Selection_struct_bis_BSIC_SIZE   6
#define CSN1_Channel_Description_struct_HSN 747
#define CSN1_Channel_Description_struct_HSN_SIZE   6
#define CSN1_Channel_Description_struct_TSC 745
#define CSN1_Channel_Description_struct_TSC_SIZE   3
#define CSN1_Channel_Description_struct_USF 739
#define CSN1_Channel_Description_struct_USF_SIZE   3
#define CSN1_Channel_Group_struct_MA_NUMBER 102
#define CSN1_Channel_Group_struct_MA_NUMBER_SIZE   4
#define CSN1_Container_repetition_struct_PD 375
#define CSN1_Container_repetition_struct_PD_SIZE   3
#define CSN1_Content_PS_Handover_Capability 1337
#define CSN1_Content_PS_Handover_Capability_SIZE   1
#define CSN1_Content__8PSK_Power_Capability 1315
#define CSN1_Content__8PSK_Power_Capability_SIZE   2
#define CSN1_DYNAMIC_ARFCN_MAPPING_GSM_Band 2108
#define CSN1_DYNAMIC_ARFCN_MAPPING_GSM_Band_SIZE   4
#define CSN1_GPRS_Cell_Options_IE_BS_CV_MAX 1034
#define CSN1_GPRS_Cell_Options_IE_BS_CV_MAX_SIZE   4
#define CSN1_MPRACH_Control_Parameters_IE_S 259
#define CSN1_MPRACH_Control_Parameters_IE_S_SIZE   4
#define CSN1_Non_GPRS_Cell_Options_IE_T3212 1439
#define CSN1_Non_GPRS_Cell_Options_IE_T3212_SIZE   8
#define CSN1_PBCCH_Description_struct_ARFCN 1228
#define CSN1_PBCCH_Description_struct_ARFCN_SIZE  10
#define CSN1_PBCCH_information_struct_ARFCN 1019
#define CSN1_PBCCH_information_struct_ARFCN_SIZE  10
#define CSN1_PSC_Group_IE_PSC_pattern_sense 2034
#define CSN1_PSC_Group_IE_PSC_pattern_sense_SIZE   1
#define CSN1_PSI1_message_content_PAGE_MODE 1129
#define CSN1_PSI1_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI2_message_content_PAGE_MODE 1432
#define CSN1_PSI2_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI3_message_content_PAGE_MODE 1485
#define CSN1_PSI3_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI4_message_content_PAGE_MODE 870
#define CSN1_PSI4_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI5_message_content_PAGE_MODE 1517
#define CSN1_PSI5_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI6_message_content_PAGE_MODE 469
#define CSN1_PSI6_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI8_message_content_PAGE_MODE 2098
#define CSN1_PSI8_message_content_PAGE_MODE_SIZE   2
#define CSN1_Repeated_Page_info_struct_TMSI 2421
#define CSN1_Repeated_Page_info_struct_TMSI_SIZE  32
#define CSN1_Uplink_Assignment_2_struct_TSH 1634
#define CSN1_Uplink_Assignment_2_struct_TSH_SIZE   2
#define CSN1_Carrier_Specific_Info_struct_P0 1747
#define CSN1_Carrier_Specific_Info_struct_P0_SIZE   4
#define CSN1_Channel_Description_struct_MAIO 746
#define CSN1_Channel_Description_struct_MAIO_SIZE   6
#define CSN1_Content_GERAN_Feature_Package_1 1322
#define CSN1_Content_GERAN_Feature_Package_1_SIZE   1
#define CSN1_Content_Multiple_TBF_Capability 1331
#define CSN1_Content_Multiple_TBF_Capability_SIZE   1
#define CSN1_Dynamic_Allocation_2_IE_N_PAIRS 1872
#define CSN1_Dynamic_Allocation_2_IE_N_PAIRS_SIZE   3
#define CSN1_Dynamic_Allocation_2_struct_USF 117
#define CSN1_Dynamic_Allocation_2_struct_USF_SIZE   3
#define CSN1_EM1_struct_EXT_REPORTING_PERIOD 1127
#define CSN1_EM1_struct_EXT_REPORTING_PERIOD_SIZE   3
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN 585
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN_SIZE   0
#define CSN1_GRA_ID_struct_NUMBER_OF_GRA_IDs 486
#define CSN1_GRA_ID_struct_NUMBER_OF_GRA_IDs_SIZE   3
#define CSN1_NonGSM_Message_struct_CONTAINER 476
#define CSN1_NonGSM_Message_struct_CONTAINER_SIZE   8
#define CSN1_PCID_Group_IE_PCID_BITMAP_GROUP 273
#define CSN1_PCID_Group_IE_PCID_BITMAP_GROUP_SIZE   6
#define CSN1_PSC_Group_IE_PSC_Pattern_length 2032
#define CSN1_PSC_Group_IE_PSC_Pattern_length_SIZE   3
#define CSN1_PSI13_message_content_PAGE_MODE 1212
#define CSN1_PSI13_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI14_message_content_PAGE_MODE 2112
#define CSN1_PSI14_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI15_message_content_PAGE_MODE 477
#define CSN1_PSI15_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI16_message_content_PAGE_MODE 481
#define CSN1_PSI16_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI2_message_content_PSI2_COUNT 1435
#define CSN1_PSI2_message_content_PSI2_COUNT_SIZE   3
#define CSN1_PSI2_message_content_PSI2_INDEX 1434
#define CSN1_PSI2_message_content_PSI2_INDEX_SIZE   3
#define CSN1_PSI4_message_content_PSI4_COUNT 873
#define CSN1_PSI4_message_content_PSI4_COUNT_SIZE   3
#define CSN1_PSI4_message_content_PSI4_INDEX 872
#define CSN1_PSI4_message_content_PSI4_INDEX_SIZE   3
#define CSN1_PSI5_message_content_PSI5_COUNT 1520
#define CSN1_PSI5_message_content_PSI5_COUNT_SIZE   3
#define CSN1_PSI5_message_content_PSI5_INDEX 1519
#define CSN1_PSI5_message_content_PSI5_INDEX_SIZE   3
#define CSN1_PSI6_message_content_PSI6_COUNT 472
#define CSN1_PSI6_message_content_PSI6_COUNT_SIZE   3
#define CSN1_PSI6_message_content_PSI6_INDEX 471
#define CSN1_PSI6_message_content_PSI6_INDEX_SIZE   3
#define CSN1_PSI8_message_content_PSI8_COUNT 2101
#define CSN1_PSI8_message_content_PSI8_COUNT_SIZE   3
#define CSN1_PSI8_message_content_PSI8_INDEX 2100
#define CSN1_PSI8_message_content_PSI8_INDEX_SIZE   3
#define CSN1_Repeated_Page_info_struct_PTMSI 2424
#define CSN1_Repeated_Page_info_struct_PTMSI_SIZE  32
#define CSN1_SI_Message_List_struct_MESS_REC 416
#define CSN1_SI_Message_List_struct_MESS_REC_SIZE   2
#define CSN1_COMPACT_NCP2_Property_struct_BCC  98
#define CSN1_COMPACT_NCP2_Property_struct_BCC_SIZE   3
#define CSN1_Cell_Selection_struct_HCS_params 309
#define CSN1_Cell_Selection_struct_HCS_params_SIZE   8
#define CSN1_Channel_Description_struct_ARFCN 748
#define CSN1_Channel_Description_struct_ARFCN_SIZE  10
#define CSN1_Content_Revision_Level_Indicator 1317
#define CSN1_Content_Revision_Level_Indicator_SIZE   1
#define CSN1_DLMC_Frequency_Parameters_IE_TSC 1730
#define CSN1_DLMC_Frequency_Parameters_IE_TSC_SIZE   3
#define CSN1_Dynamic_Allocation_2_IE_ALPHA_C1 1870
#define CSN1_Dynamic_Allocation_2_IE_ALPHA_C1_SIZE   4
#define CSN1_Dynamic_Allocation_2_IE_ALPHA_C2 1871
#define CSN1_Dynamic_Allocation_2_IE_ALPHA_C2_SIZE   4
#define CSN1_Dynamic_Allocation_2_struct_N_TS 120
#define CSN1_Dynamic_Allocation_2_struct_N_TS_SIZE   4
#define CSN1_EGPRS_Window_Size_IE_Window_Size 366
#define CSN1_EGPRS_Window_Size_IE_Window_Size_SIZE   5
#define CSN1_Extension_Information_BEP_PERIOD 1040
#define CSN1_Extension_Information_BEP_PERIOD_SIZE   4
#define CSN1_Extension_Information_CCN_ACTIVE 1044
#define CSN1_Extension_Information_CCN_ACTIVE_SIZE   1
#define CSN1_LSA_ID_information_struct_LSA_ID 249
#define CSN1_LSA_ID_information_struct_LSA_ID_SIZE  24
#define CSN1_Multi_Block_Allocation_struct_P0 926
#define CSN1_Multi_Block_Allocation_struct_P0_SIZE   4
#define CSN1_PCID_Group_IE_PCID_pattern_sense 276
#define CSN1_PCID_Group_IE_PCID_pattern_sense_SIZE   1
#define CSN1_Packet_Pause_message_content_RAI 509
#define CSN1_Packet_Pause_message_content_RAI_SIZE  48
#define CSN1_Power_Command_struct_POWER_LEVEL 743
#define CSN1_Power_Command_struct_POWER_LEVEL_SIZE   8
#define CSN1_Relative_Frame_Number_Encoding_k 593
#define CSN1_Relative_Frame_Number_Encoding_k_SIZE  13
#define CSN1_Repeated_Page_info_struct_Ignore 3240
#define CSN1_Repeated_Page_info_struct_Ignore_SIZE   0
#define CSN1_SI_Message_List_struct_SIX_COUNT 418
#define CSN1_SI_Message_List_struct_SIX_COUNT_SIZE   4
#define CSN1_UTRAN_CSG_Target_cell_IE_PLMN_ID 687
#define CSN1_UTRAN_CSG_Target_cell_IE_PLMN_ID_SIZE  24
#define CSN1_Uplink_Assignment_2_struct_GAMMA 1645
#define CSN1_Uplink_Assignment_2_struct_GAMMA_SIZE   5
#define CSN1_Uplink_Assignment_2_struct_P0_C1 1630
#define CSN1_Uplink_Assignment_2_struct_P0_C1_SIZE   4
#define CSN1_Uplink_Assignment_2_struct_P0_C2 1632
#define CSN1_Uplink_Assignment_2_struct_P0_C2_SIZE   4
#define CSN1_Uplink_Assignment_struct_PR_MODE 1238
#define CSN1_Uplink_Assignment_struct_PR_MODE_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_PFI 931
#define CSN1_Uplink_TBF_Assignment_struct_PFI_SIZE   7
#define CSN1__3G_Target_Cell_Struct_FDD_ARFCN   0
#define CSN1__3G_Target_Cell_Struct_FDD_ARFCN_SIZE  14
#define CSN1__3G_Target_Cell_Struct_Sync_Case   6
#define CSN1__3G_Target_Cell_Struct_Sync_Case_SIZE   1
#define CSN1__3G_Target_Cell_Struct_TDD_ARFCN   3
#define CSN1__3G_Target_Cell_Struct_TDD_ARFCN_SIZE  14
#define CSN1_Absolute_Frame_Number_Encoding_T1 590
#define CSN1_Absolute_Frame_Number_Encoding_T1_SIZE   5
#define CSN1_Absolute_Frame_Number_Encoding_T2 592
#define CSN1_Absolute_Frame_Number_Encoding_T2_SIZE   5
#define CSN1_Absolute_Frame_Number_Encoding_T3 591
#define CSN1_Absolute_Frame_Number_Encoding_T3_SIZE   6
#define CSN1_Access_capabilities_struct_Length 1288
#define CSN1_Access_capabilities_struct_Length_SIZE   7
#define CSN1_Assignment_Info_struct_Carrier_ID  75
#define CSN1_Assignment_Info_struct_Carrier_ID_SIZE   1
#define CSN1_Carrier_Specific_Info_struct_MAIO 1746
#define CSN1_Carrier_Specific_Info_struct_MAIO_SIZE   6
#define CSN1_Cell_Allocation_struct_RFL_NUMBER 1459
#define CSN1_Cell_Allocation_struct_RFL_NUMBER_SIZE   4
#define CSN1_Cell_Selection_struct_bis_EXC_ACC 430
#define CSN1_Cell_Selection_struct_bis_EXC_ACC_SIZE   1
#define CSN1_Content_High_Multislot_Capability 1326
#define CSN1_Content_High_Multislot_Capability_SIZE   2
#define CSN1_DLMC_Direct_encoding_2_struct_HSN 1738
#define CSN1_DLMC_Direct_encoding_2_struct_HSN_SIZE   6
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_FIRST 2109
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_FIRST_SIZE  10
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_RANGE 2111
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_RANGE_SIZE   7
#define CSN1_DYNAMIC_ARFCN_MAPPING_BAND_OFFSET 2110
#define CSN1_DYNAMIC_ARFCN_MAPPING_BAND_OFFSET_SIZE  10
#define CSN1_Dynamic_Allocation_2_struct_GAMMA 118
#define CSN1_Dynamic_Allocation_2_struct_GAMMA_SIZE   5
#define CSN1_Dynamic_Allocation_2_struct_N_USF 121
#define CSN1_Dynamic_Allocation_2_struct_N_USF_SIZE   4
#define CSN1_Dynamic_Allocation_2_struct_P0_C1 108
#define CSN1_Dynamic_Allocation_2_struct_P0_C1_SIZE   4
#define CSN1_Dynamic_Allocation_2_struct_P0_C2 110
#define CSN1_Dynamic_Allocation_2_struct_P0_C2_SIZE   4
#define CSN1_Dynamic_Allocation_2_struct_USF_2 119
#define CSN1_Dynamic_Allocation_2_struct_USF_2_SIZE   3
#define CSN1_EGPRS_mode_2_IE_Uplink_Assignment 1852
#define CSN1_EGPRS_mode_2_IE_Uplink_Assignment_SIZE   0
#define CSN1_E_UTRAN_Target_Cell_struct_EARFCN 698
#define CSN1_E_UTRAN_Target_Cell_struct_EARFCN_SIZE  16
#define CSN1_Extension_Information_DTM_SUPPORT 1042
#define CSN1_Extension_Information_DTM_SUPPORT_SIZE   1
#define CSN1_Extension_Information_NW_EXT_UTBF 1045
#define CSN1_Extension_Information_NW_EXT_UTBF_SIZE   1
#define CSN1_GERAN_Iu_Mode_Capabilities_Length 1327
#define CSN1_GERAN_Iu_Mode_Capabilities_Length_SIZE   4
#define CSN1_GSM_Priority_Parameters_IE_H_PRIO 1991
#define CSN1_GSM_Priority_Parameters_IE_H_PRIO_SIZE   2
#define CSN1_GSM_target_cell_struct_CCN_ACTIVE 2301
#define CSN1_GSM_target_cell_struct_CCN_ACTIVE_SIZE   1
#define CSN1_NCP2_Repeat_struct_FREQUENCY_DIFF 464
#define CSN1_NCP2_Repeat_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_PCID_Group_IE_PCID_Pattern_length 274
#define CSN1_PCID_Group_IE_PCID_Pattern_length_SIZE   3
#define CSN1_PSI16_message_content_GRA_ID_LIST 485
#define CSN1_PSI16_message_content_GRA_ID_LIST_SIZE   0
#define CSN1_PSI16_message_content_PSI16_COUNT 484
#define CSN1_PSI16_message_content_PSI16_COUNT_SIZE   3
#define CSN1_PSI16_message_content_PSI16_INDEX 483
#define CSN1_PSI16_message_content_PSI16_INDEX_SIZE   3
#define CSN1_PSI1_message_content_PSI_COUNT_HR 1134
#define CSN1_PSI1_message_content_PSI_COUNT_HR_SIZE   4
#define CSN1_PSI1_message_content_PSI_COUNT_LR 1133
#define CSN1_PSI1_message_content_PSI_COUNT_LR_SIZE   6
#define CSN1_PS_Handover_Radio_Resources_IE_P0 1724
#define CSN1_PS_Handover_Radio_Resources_IE_P0_SIZE   4
#define CSN1_PS_Handover_Radio_Resources_IE_SI 1712
#define CSN1_PS_Handover_Radio_Resources_IE_SI_SIZE   2
#define CSN1_Packet_Pause_message_content_TLLI 508
#define CSN1_Packet_Pause_message_content_TLLI_SIZE  32
#define CSN1_Power_Control_Parameters_IE_ALPHA 235
#define CSN1_Power_Control_Parameters_IE_ALPHA_SIZE   4
#define CSN1_RFL_number_list_struct_RFL_NUMBER 223
#define CSN1_RFL_number_list_struct_RFL_NUMBER_SIZE   4
#define CSN1_Repeated_Iu_Page_info_struct_TMSI 2429
#define CSN1_Repeated_Iu_Page_info_struct_TMSI_SIZE  32
#define CSN1_Single_Block_Allocation_struct_P0 1555
#define CSN1_Single_Block_Allocation_struct_P0_SIZE   4
#define CSN1_Single_Uplink_Assignment_2_IE_PFI 1878
#define CSN1_Single_Uplink_Assignment_2_IE_PFI_SIZE   7
#define CSN1_Single_Uplink_Assignment_2_IE_TSH 1859
#define CSN1_Single_Uplink_Assignment_2_IE_TSH_SIZE   2
#define CSN1_Timeslot_description_struct_ALPHA 125
#define CSN1_Timeslot_description_struct_ALPHA_SIZE   4
#define CSN1_UFPS_struct_CARRIER_SPECIFIC_INFO 1742
#define CSN1_UFPS_struct_CARRIER_SPECIFIC_INFO_SIZE   0
#define CSN1_UTRAN_CSG_Target_cell_IE_UTRAN_CI 686
#define CSN1_UTRAN_CSG_Target_cell_IE_UTRAN_CI_SIZE  28
#define CSN1_CBCH_Channel_Description_struct_TN 2104
#define CSN1_CBCH_Channel_Description_struct_TN_SIZE   3
#define CSN1_CCCH_Access_Information_struct_RAC 2123
#define CSN1_CCCH_Access_Information_struct_RAC_SIZE   8
#define CSN1_COMPACT_Cell_Selection_struct_BSIC 439
#define CSN1_COMPACT_Cell_Selection_struct_BSIC_SIZE   6
#define CSN1_DLMC_Frequency_Parameters_IE_ARFCN 1741
#define CSN1_DLMC_Frequency_Parameters_IE_ARFCN_SIZE  10
#define CSN1_Downlink_TBF_assignment_struct_PFI 1398
#define CSN1_Downlink_TBF_assignment_struct_PFI_SIZE   7
#define CSN1_Dynamic_Allocation_2_IE_PR_MODE_C1 1865
#define CSN1_Dynamic_Allocation_2_IE_PR_MODE_C1_SIZE   1
#define CSN1_Dynamic_Allocation_2_IE_PR_MODE_C2 1867
#define CSN1_Dynamic_Allocation_2_IE_PR_MODE_C2_SIZE   1
#define CSN1_E_UTRAN_CSG_Target_cell_IE_PLMN_ID 691
#define CSN1_E_UTRAN_CSG_Target_cell_IE_PLMN_ID_SIZE  24
#define CSN1_Extension_Bits_IE_extension_length 597
#define CSN1_Extension_Bits_IE_extension_length_SIZE   6
#define CSN1_Extension_Information_MNCI_SUPPORT 1050
#define CSN1_Extension_Information_MNCI_SUPPORT_SIZE   1
#define CSN1_GPRS_Cell_Options_IE_DRX_TIMER_MAX 1031
#define CSN1_GPRS_Cell_Options_IE_DRX_TIMER_MAX_SIZE   3
#define CSN1_GPRS_mode_struct_Uplink_Assignment 1345
#define CSN1_GPRS_mode_struct_Uplink_Assignment_SIZE   0
#define CSN1_Hopping_PCCCH_Carriers_struct_MAIO 1467
#define CSN1_Hopping_PCCCH_Carriers_struct_MAIO_SIZE   6
#define CSN1_Indirect_encoding_struct_MA_NUMBER 1258
#define CSN1_Indirect_encoding_struct_MA_NUMBER_SIZE   4
#define CSN1_NCP2_Repeat_struct_START_FREQUENCY 461
#define CSN1_NCP2_Repeat_struct_START_FREQUENCY_SIZE  10
#define CSN1_Neighbour_parameter_set_struct_NCC 1156
#define CSN1_Neighbour_parameter_set_struct_NCC_SIZE   3
#define CSN1_Non_GPRS_Cell_Options_IE_CCCH_CONF 1445
#define CSN1_Non_GPRS_Cell_Options_IE_CCCH_CONF_SIZE   3
#define CSN1_PCCCH_Description_struct_MA_NUMBER 1465
#define CSN1_PCCCH_Description_struct_MA_NUMBER_SIZE   4
#define CSN1_PRACH_Control_Parameters_IE_TX_INT 247
#define CSN1_PRACH_Control_Parameters_IE_TX_INT_SIZE   4
#define CSN1_PSI13_message_content_SI2n_SUPPORT 1233
#define CSN1_PSI13_message_content_SI2n_SUPPORT_SIZE   2
#define CSN1_PSI3_bis_message_content_PAGE_MODE 1148
#define CSN1_PSI3_bis_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI3_ter_message_content_PAGE_MODE 862
#define CSN1_PSI3_ter_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI_Message_List_struct_PSIX_COUNT 405
#define CSN1_PSI_Message_List_struct_PSIX_COUNT_SIZE   4
#define CSN1_PS_Handover_Radio_Resources_IE_NCI 1713
#define CSN1_PS_Handover_Radio_Resources_IE_NCI_SIZE   1
#define CSN1_Repeated_Iu_Page_info_struct_PTMSI 2430
#define CSN1_Repeated_Iu_Page_info_struct_PTMSI_SIZE  32
#define CSN1_Response_Time_struct_TRESP_MAC_DTM  72
#define CSN1_Response_Time_struct_TRESP_MAC_DTM_SIZE   7
#define CSN1_Serving_Cell_params_struct_EXC_ACC 1490
#define CSN1_Serving_Cell_params_struct_EXC_ACC_SIZE   1
#define CSN1_UTRAN_FDD_Target_cell_IE_Diversity 2317
#define CSN1_UTRAN_FDD_Target_cell_IE_Diversity_SIZE   1
#define CSN1_UTRAN_FDD_Target_cell_IE_FDD_ARFCN 2316
#define CSN1_UTRAN_FDD_Target_cell_IE_FDD_ARFCN_SIZE  14
#define CSN1_UTRAN_TDD_Target_cell_IE_TDD_ARFCN 2321
#define CSN1_UTRAN_TDD_Target_cell_IE_TDD_ARFCN_SIZE  14
#define CSN1_Uplink_Assignment_2_struct_N_PAIRS 1644
#define CSN1_Uplink_Assignment_2_struct_N_PAIRS_SIZE   3
#define CSN1_Uplink_TBF_Assignment_2_struct_PFI 940
#define CSN1_Uplink_TBF_Assignment_2_struct_PFI_SIZE   7
#define CSN1_Uplink_TBF_Assignment_struct_RB_Id 930
#define CSN1_Uplink_TBF_Assignment_struct_RB_Id_SIZE   5
#define CSN1__3G_Measurement_Report_struct_N_3G 806
#define CSN1__3G_Measurement_Report_struct_N_3G_SIZE   3
#define CSN1_ARFCN_index_list_struct_ARFCN_INDEX 224
#define CSN1_ARFCN_index_list_struct_ARFCN_INDEX_SIZE   6
#define CSN1_Content_DTM_Enhancements_Capability 1334
#define CSN1_Content_DTM_Enhancements_Capability_SIZE   1
#define CSN1_DLMC_Channel_Quality_Report_C_VALUE 630
#define CSN1_DLMC_Channel_Quality_Report_C_VALUE_SIZE   6
#define CSN1_Dynamic_Allocation_2_struct_N_PAIRS 116
#define CSN1_Dynamic_Allocation_2_struct_N_PAIRS_SIZE   3
#define CSN1_EGPRS_mode_2_IE_Downlink_Assignment 1834
#define CSN1_EGPRS_mode_2_IE_Downlink_Assignment_SIZE   0
#define CSN1_EGPRS_mode_struct_EGPRS_Window_Size 1347
#define CSN1_EGPRS_mode_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_EGPRS_mode_struct_Uplink_Assignment 1351
#define CSN1_EGPRS_mode_struct_Uplink_Assignment_SIZE   0
#define CSN1_GPRS_Mobile_Allocation_IE_MA_BITMAP 589
#define CSN1_GPRS_Mobile_Allocation_IE_MA_BITMAP_SIZE   0
#define CSN1_GPRS_Mobile_Allocation_IE_MA_LENGTH 588
#define CSN1_GPRS_Mobile_Allocation_IE_MA_LENGTH_SIZE   6
#define CSN1_GSM_target_cell_struct_CONTAINER_ID 2302
#define CSN1_GSM_target_cell_struct_CONTAINER_ID_SIZE   2
#define CSN1_MBMS_Information_MBMS_Sessions_List 2433
#define CSN1_MBMS_Information_MBMS_Sessions_List_SIZE   0
#define CSN1_MPRACH_Control_Parameters_IE_TX_INT 260
#define CSN1_MPRACH_Control_Parameters_IE_TX_INT_SIZE   4
#define CSN1_Multi_Block_Allocation_struct_ALPHA 924
#define CSN1_Multi_Block_Allocation_struct_ALPHA_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_2_IE_TSH 1794
#define CSN1_Multiple_Uplink_Assignment_2_IE_TSH_SIZE   2
#define CSN1_NCP2_Repeat_struct_FREQ_DIFF_LENGTH 463
#define CSN1_NCP2_Repeat_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_NC_Measurement_Report_struct_BSIC_N 799
#define CSN1_NC_Measurement_Report_struct_BSIC_N_SIZE   6
#define CSN1_Non_GPRS_Cell_Options_IE_TX_INTEGER 1448
#define CSN1_Non_GPRS_Cell_Options_IE_TX_INTEGER_SIZE   4
#define CSN1_Non_GPRS_Extension_Information_ECSC 1452
#define CSN1_Non_GPRS_Extension_Information_ECSC_SIZE   1
#define CSN1_PSI13_message_content_SI_CHANGE_ALT 1234
#define CSN1_PSI13_message_content_SI_CHANGE_ALT_SIZE   1
#define CSN1_PSI13_message_content_SI_STATUS_IND 1231
#define CSN1_PSI13_message_content_SI_STATUS_IND_SIZE   1
#define CSN1_PSI13_message_content_SPGC_CCCH_SUP 1218
#define CSN1_PSI13_message_content_SPGC_CCCH_SUP_SIZE   1
#define CSN1_PSI1_message_content_BAND_INDICATOR 1147
#define CSN1_PSI1_message_content_BAND_INDICATOR_SIZE   1
#define CSN1_PSI1_message_content_PSI_STATUS_IND 1144
#define CSN1_PSI1_message_content_PSI_STATUS_IND_SIZE   1
#define CSN1_PSI3_message_content_LSA_Parameters 1503
#define CSN1_PSI3_message_content_LSA_Parameters_SIZE   0
#define CSN1_PSI3_message_content_PSI3_BIS_COUNT 1487
#define CSN1_PSI3_message_content_PSI3_BIS_COUNT_SIZE   4
#define CSN1_PSI6_message_content_NonGSM_Message 473
#define CSN1_PSI6_message_content_NonGSM_Message_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_SI 2339
#define CSN1_PS_Handover_Radio_Resources_2_IE_SI_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_SI 2360
#define CSN1_PS_Handover_Radio_Resources_3_IE_SI_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_IE_BSIC 1714
#define CSN1_PS_Handover_Radio_Resources_IE_BSIC_SIZE   6
#define CSN1_Page_info_struct_CN_DOMAIN_IDENTITY  88
#define CSN1_Page_info_struct_CN_DOMAIN_IDENTITY_SIZE   2
#define CSN1_RLC_Entity_Struct_EGPRS_Window_Size 604
#define CSN1_RLC_Entity_Struct_EGPRS_Window_Size_SIZE   5
#define CSN1_RRC_Container_IE_RRC_CONTAINER_DATA 609
#define CSN1_RRC_Container_IE_RRC_CONTAINER_DATA_SIZE   0
#define CSN1_Repeated_Iu_Page_info_struct_G_RNTI 2432
#define CSN1_Repeated_Iu_Page_info_struct_G_RNTI_SIZE  32
#define CSN1_Repeated_Iu_Page_info_struct_Ignore 3241
#define CSN1_Repeated_Iu_Page_info_struct_Ignore_SIZE   0
#define CSN1_Single_Downlink_Assignment_2_IE_PFI 1847
#define CSN1_Single_Downlink_Assignment_2_IE_PFI_SIZE   7
#define CSN1_Uplink_Assignment_2_struct_ALPHA_C1 1642
#define CSN1_Uplink_Assignment_2_struct_ALPHA_C1_SIZE   4
#define CSN1_Uplink_Assignment_2_struct_ALPHA_C2 1643
#define CSN1_Uplink_Assignment_2_struct_ALPHA_C2_SIZE   4
#define CSN1_CCCH_Access_Information_struct_SGSNR 2122
#define CSN1_CCCH_Access_Information_struct_SGSNR_SIZE   1
#define CSN1_CCN_Measurement_Report_struct_BSIC_N 714
#define CSN1_CCN_Measurement_Report_struct_BSIC_N_SIZE   6
#define CSN1_Carrier_Specific_Info_struct_PR_MODE 1748
#define CSN1_Carrier_Specific_Info_struct_PR_MODE_SIZE   1
#define CSN1_Cell_Selection_struct_bis_HCS_params 437
#define CSN1_Cell_Selection_struct_bis_HCS_params_SIZE   8
#define CSN1_Channel_Quality_Report_struct_RXQUAL 339
#define CSN1_Channel_Quality_Report_struct_RXQUAL_SIZE   3
#define CSN1_Content_GMSK_Multislot_Power_Profile 1329
#define CSN1_Content_GMSK_Multislot_Power_Profile_SIZE   2
#define CSN1_Downlink_TBF_assignment_2_struct_PFI 359
#define CSN1_Downlink_TBF_assignment_2_struct_PFI_SIZE   7
#define CSN1_Downlink_TBF_assignment_struct_RB_Id 1400
#define CSN1_Downlink_TBF_assignment_struct_RB_Id_SIZE   5
#define CSN1_Dynamic_Allocation_2_struct_ALPHA_C1 114
#define CSN1_Dynamic_Allocation_2_struct_ALPHA_C1_SIZE   4
#define CSN1_Dynamic_Allocation_2_struct_ALPHA_C2 115
#define CSN1_Dynamic_Allocation_2_struct_ALPHA_C2_SIZE   4
#define CSN1_EGPRS_Channel_Quality_Report_C_VALUE 1023
#define CSN1_EGPRS_Channel_Quality_Report_C_VALUE_SIZE   6
#define CSN1_ETWS_Primary_Notification_struct_PNI 2454
#define CSN1_ETWS_Primary_Notification_struct_PNI_SIZE   1
#define CSN1_EXT_Measurement_Report_struct_BSIC_N 791
#define CSN1_EXT_Measurement_Report_struct_BSIC_N_SIZE   6
#define CSN1_GPRS_mode_struct_Downlink_Assignment 1346
#define CSN1_GPRS_mode_struct_Downlink_Assignment_SIZE   0
#define CSN1_LSA_Parameters_IE_LSA_ID_information 599
#define CSN1_LSA_Parameters_IE_LSA_ID_information_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_struct_P0 1243
#define CSN1_Multiple_Uplink_Assignment_struct_P0_SIZE   4
#define CSN1_Multislot_capability_struct_SM_VALUE 1308
#define CSN1_Multislot_capability_struct_SM_VALUE_SIZE   4
#define CSN1_NC_Measurement_Report_struct_NC_MODE 794
#define CSN1_NC_Measurement_Report_struct_NC_MODE_SIZE   1
#define CSN1_NC_Measurement_Report_struct_RXLEV_N 800
#define CSN1_NC_Measurement_Report_struct_RXLEV_N_SIZE   6
#define CSN1_Non_GPRS_Cell_Options_IE_BS_PA_MFRMS 1446
#define CSN1_Non_GPRS_Cell_Options_IE_BS_PA_MFRMS_SIZE   3
#define CSN1_Non_GPRS_Cell_Options_IE_MAX_RETRANS 1447
#define CSN1_Non_GPRS_Cell_Options_IE_MAX_RETRANS_SIZE   2
#define CSN1_PSI16_message_content_CN_DOMAIN_LIST 489
#define CSN1_PSI16_message_content_CN_DOMAIN_LIST_SIZE   2
#define CSN1_PSI2_message_content_Cell_Allocation 1458
#define CSN1_PSI2_message_content_Cell_Allocation_SIZE   0
#define CSN1_PSI_Message_List_struct_MESSAGE_TYPE 403
#define CSN1_PSI_Message_List_struct_MESSAGE_TYPE_SIZE   6
#define CSN1_PS_Handover_Radio_Resources_2_IE_NCI 2340
#define CSN1_PS_Handover_Radio_Resources_2_IE_NCI_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_NCI 2361
#define CSN1_PS_Handover_Radio_Resources_3_IE_NCI_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_TSH 2393
#define CSN1_PS_Handover_Radio_Resources_3_IE_TSH_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_IE_ARFCN 1711
#define CSN1_PS_Handover_Radio_Resources_IE_ARFCN_SIZE  10
#define CSN1_REMOVED_3GCELL_Description_struct_N1 1102
#define CSN1_REMOVED_3GCELL_Description_struct_N1_SIZE   2
#define CSN1_REMOVED_3GCELL_Description_struct_N2 1103
#define CSN1_REMOVED_3GCELL_Description_struct_N2_SIZE   5
#define CSN1_Reject_struct_WAIT_INDICATION_LENGTH 286
#define CSN1_Reject_struct_WAIT_INDICATION_LENGTH_SIZE   1
#define CSN1_Single_Block_Allocation_struct_ALPHA 1553
#define CSN1_Single_Block_Allocation_struct_ALPHA_SIZE   4
#define CSN1__3G_Target_Cell_Struct_Bandwidth_FDD   1
#define CSN1__3G_Target_Cell_Struct_Bandwidth_FDD_SIZE   3
#define CSN1__3G_Target_Cell_Struct_Bandwidth_TDD   4
#define CSN1__3G_Target_Cell_Struct_Bandwidth_TDD_SIZE   3
#define CSN1_p3G_CSG_Description_IE_CSG_PSC_SPLIT 2030
#define CSN1_p3G_CSG_Description_IE_CSG_PSC_SPLIT_SIZE   0
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_PFI 1797
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_PFI_SIZE   7
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF 1810
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_SIZE   3
#define CSN1_CCN_Measurement_Report_struct_RXLEV_N 715
#define CSN1_CCN_Measurement_Report_struct_RXLEV_N_SIZE   6
#define CSN1_COMPACT_Cell_Selection_struct_EXC_ACC 441
#define CSN1_COMPACT_Cell_Selection_struct_EXC_ACC_SIZE   1
#define CSN1_COMPACT_Control_Info_struct_N_CCCH_NH 1479
#define CSN1_COMPACT_Control_Info_struct_N_CCCH_NH_SIZE   4
#define CSN1_Channel_Quality_Report_struct_C_VALUE 338
#define CSN1_Channel_Quality_Report_struct_C_VALUE_SIZE   6
#define CSN1_Container_repetition_struct_CD_LENGTH 376
#define CSN1_Container_repetition_struct_CD_LENGTH_SIZE   5
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_P0 2510
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_P0_SIZE   4
#define CSN1_EGPRS_Modulation_and_Coding_IE_Scheme 1568
#define CSN1_EGPRS_Modulation_and_Coding_IE_Scheme_SIZE   4
#define CSN1_EGPRS_mode_struct_Downlink_Assignment 1353
#define CSN1_EGPRS_mode_struct_Downlink_Assignment_SIZE   0
#define CSN1_EXT_Measurement_Report_struct_RXLEV_N 792
#define CSN1_EXT_Measurement_Report_struct_RXLEV_N_SIZE   6
#define CSN1_E_UTRAN_CSG_Target_cell_IE_E_UTRAN_CI 689
#define CSN1_E_UTRAN_CSG_Target_cell_IE_E_UTRAN_CI_SIZE  28
#define CSN1_Extension_Information_EXT_UTBF_NODATA 1047
#define CSN1_Extension_Information_EXT_UTBF_NODATA_SIZE   1
#define CSN1_Extension_Information_NMO_I_ALTERNATE 1052
#define CSN1_Extension_Information_NMO_I_ALTERNATE_SIZE   1
#define CSN1_GPRS_Cell_Options_IE_CONTROL_ACK_TYPE 1033
#define CSN1_GPRS_Cell_Options_IE_CONTROL_ACK_TYPE_SIZE   1
#define CSN1_GSM_target_cell_struct_LSA_Parameters 2299
#define CSN1_GSM_target_cell_struct_LSA_Parameters_SIZE   0
#define CSN1_GSM_target_cell_struct__3G_CCN_ACTIVE 2308
#define CSN1_GSM_target_cell_struct__3G_CCN_ACTIVE_SIZE   1
#define CSN1_Global_Power_Control_Parameters_IE_Pb 212
#define CSN1_Global_Power_Control_Parameters_IE_Pb_SIZE   4
#define CSN1_LSA_ID_information_struct_ShortLSA_ID 250
#define CSN1_LSA_ID_information_struct_ShortLSA_ID_SIZE  10
#define CSN1_LSA_Parameters_IE_NR_OF_FREQ_OR_CELLS 598
#define CSN1_LSA_Parameters_IE_NR_OF_FREQ_OR_CELLS_SIZE   5
#define CSN1_Multi_Block_Allocation_struct_PR_MODE 927
#define CSN1_Multi_Block_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_IE_GAMMA 1815
#define CSN1_Multiple_Uplink_Assignment_2_IE_GAMMA_SIZE   5
#define CSN1_Multiple_Uplink_Assignment_2_IE_P0_C1 1790
#define CSN1_Multiple_Uplink_Assignment_2_IE_P0_C1_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_2_IE_P0_C2 1792
#define CSN1_Multiple_Uplink_Assignment_2_IE_P0_C2_SIZE   4
#define CSN1_Multislot_capability_struct_SMS_VALUE 1307
#define CSN1_Multislot_capability_struct_SMS_VALUE_SIZE   4
#define CSN1_PSI13_message_content_SI_CHANGE_FIELD 1214
#define CSN1_PSI13_message_content_SI_CHANGE_FIELD_SIZE   4
#define CSN1_PSI1_message_content_PSI_CHANGE_FIELD 1131
#define CSN1_PSI1_message_content_PSI_CHANGE_FIELD_SIZE   4
#define CSN1_PSI2_message_content_PSI2_CHANGE_MARK 1433
#define CSN1_PSI2_message_content_PSI2_CHANGE_MARK_SIZE   2
#define CSN1_PSI3_message_content_PSI3_CHANGE_MARK 1486
#define CSN1_PSI3_message_content_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_PSI3_quater_message_content_PAGE_MODE 1183
#define CSN1_PSI3_quater_message_content_PAGE_MODE_SIZE   2
#define CSN1_PSI4_message_content_PSI4_CHANGE_MARK 871
#define CSN1_PSI4_message_content_PSI4_CHANGE_MARK_SIZE   2
#define CSN1_PSI5_message_content_PSI5_CHANGE_MARK 1518
#define CSN1_PSI5_message_content_PSI5_CHANGE_MARK_SIZE   2
#define CSN1_PSI6_message_content_PSI6_CHANGE_MARK 470
#define CSN1_PSI6_message_content_PSI6_CHANGE_MARK_SIZE   2
#define CSN1_PSI8_message_content_PSI8_CHANGE_MARK 2099
#define CSN1_PSI8_message_content_PSI8_CHANGE_MARK_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_2_IE_BSIC 2341
#define CSN1_PS_Handover_Radio_Resources_2_IE_BSIC_SIZE   6
#define CSN1_PS_Handover_Radio_Resources_3_IE_BSIC 2362
#define CSN1_PS_Handover_Radio_Resources_3_IE_BSIC_SIZE   6
#define CSN1_PS_Handover_Radio_Resources_3_IE_UFPS 2368
#define CSN1_PS_Handover_Radio_Resources_3_IE_UFPS_SIZE   0
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN0 236
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN0_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN1 237
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN1_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN2 238
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN2_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN3 239
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN3_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN4 240
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN4_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN5 241
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN5_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN6 242
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN6_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN7 243
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN7_SIZE   5
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_1 582
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_1_SIZE   3
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_2 578
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_2_SIZE   0
#define CSN1_RRC_Container_IE_RRC_CONTAINER_LENGTH 608
#define CSN1_RRC_Container_IE_RRC_CONTAINER_LENGTH_SIZE   8
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_PFI 1818
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_PFI_SIZE   7
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF 1828
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_SIZE   3
#define CSN1_Reference_Frequency_struct_RFL_NUMBER 1455
#define CSN1_Reference_Frequency_struct_RFL_NUMBER_SIZE   4
#define CSN1_Timeslot_description_struct_GAMMA_TN0 126
#define CSN1_Timeslot_description_struct_GAMMA_TN0_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN1 127
#define CSN1_Timeslot_description_struct_GAMMA_TN1_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN2 128
#define CSN1_Timeslot_description_struct_GAMMA_TN2_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN3 129
#define CSN1_Timeslot_description_struct_GAMMA_TN3_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN4 130
#define CSN1_Timeslot_description_struct_GAMMA_TN4_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN5 131
#define CSN1_Timeslot_description_struct_GAMMA_TN5_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN6 132
#define CSN1_Timeslot_description_struct_GAMMA_TN6_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN7 133
#define CSN1_Timeslot_description_struct_GAMMA_TN7_SIZE   5
#define CSN1_UFPS_struct_DLMC_Frequency_Parameters 1729
#define CSN1_UFPS_struct_DLMC_Frequency_Parameters_SIZE   0
#define CSN1_Uplink_Assignment_2_struct_PR_MODE_C1 1631
#define CSN1_Uplink_Assignment_2_struct_PR_MODE_C1_SIZE   1
#define CSN1_Uplink_Assignment_2_struct_PR_MODE_C2 1633
#define CSN1_Uplink_Assignment_2_struct_PR_MODE_C2_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_RLC_MODE 932
#define CSN1_Uplink_TBF_Assignment_struct_RLC_MODE_SIZE   1
#define CSN1__3G_Target_Cell_Struct_Cell_Parameter   5
#define CSN1__3G_Target_Cell_Struct_Cell_Parameter_SIZE   7
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_BSIC 1112
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_BSIC_SIZE   6
#define CSN1_Assignment_Info_struct_Assignment_Type  74
#define CSN1_Assignment_Info_struct_Assignment_Type_SIZE   2
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_N_TS 1806
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_N_TS_SIZE   4
#define CSN1_Channel_Quality_Report_struct_SIGN_VAR 340
#define CSN1_Channel_Quality_Report_struct_SIGN_VAR_SIZE   6
#define CSN1_Content_DTM_GPRS_High_Multi_Slot_Class 1335
#define CSN1_Content_DTM_GPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_Content__8_PSK_Multislot_Power_Profile 1330
#define CSN1_Content__8_PSK_Multislot_Power_Profile_SIZE   2
#define CSN1_Downlink_TBF_assignment_struct_HFN_LSB 1404
#define CSN1_Downlink_TBF_assignment_struct_HFN_LSB_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_bis_PFI 978
#define CSN1_Downlink_TBF_assignment_struct_bis_PFI_SIZE   7
#define CSN1_Downlink_TBF_assignment_struct_ter_PFI 1055
#define CSN1_Downlink_TBF_assignment_struct_ter_PFI_SIZE   7
#define CSN1_Dynamic_Allocation_2_struct_PR_MODE_C1 109
#define CSN1_Dynamic_Allocation_2_struct_PR_MODE_C1_SIZE   1
#define CSN1_Dynamic_Allocation_2_struct_PR_MODE_C2 111
#define CSN1_Dynamic_Allocation_2_struct_PR_MODE_C2_SIZE   1
#define CSN1_EPD_A_N_Extension_Info_Timeslot_Number 1890
#define CSN1_EPD_A_N_Extension_Info_Timeslot_Number_SIZE   3
#define CSN1_Extension_Information_PFC_FEATURE_MODE 1041
#define CSN1_Extension_Information_PFC_FEATURE_MODE_SIZE   1
#define CSN1_GPRS_Cell_Options_IE_ACCESS_BURST_TYPE 1032
#define CSN1_GPRS_Cell_Options_IE_ACCESS_BURST_TYPE_SIZE   1
#define CSN1_GPRS_Power_Control_Parameters_IE_ALPHA 216
#define CSN1_GPRS_Power_Control_Parameters_IE_ALPHA_SIZE   4
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_1 1259
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_1_SIZE   2
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_2 1260
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_2_SIZE   2
#define CSN1_Iu_mode_Reject_struct_G_RNTI_extension 667
#define CSN1_Iu_mode_Reject_struct_G_RNTI_extension_SIZE   4
#define CSN1_Multi_Block_Allocation_struct_GAMMA_TN 925
#define CSN1_Multi_Block_Allocation_struct_GAMMA_TN_SIZE   5
#define CSN1_Multiple_Downlink_Assignment_2_IE_FANR 1765
#define CSN1_Multiple_Downlink_Assignment_2_IE_FANR_SIZE   1
#define CSN1_NCP2_Property_struct_CELL_BAR_ACCESS_2  94
#define CSN1_NCP2_Property_struct_CELL_BAR_ACCESS_2_SIZE   1
#define CSN1_NC_Measurement_Report_struct_bis_SCALE 822
#define CSN1_NC_Measurement_Report_struct_bis_SCALE_SIZE   1
#define CSN1_Neighbour_parameter_set_struct_EXC_ACC 1157
#define CSN1_Neighbour_parameter_set_struct_EXC_ACC_SIZE   1
#define CSN1_Neighbour_parameter_set_struct_HCS_THR 1161
#define CSN1_Neighbour_parameter_set_struct_HCS_THR_SIZE   5
#define CSN1_Neighbouring_Cell_Report_struct_BSIC_N 768
#define CSN1_Neighbouring_Cell_Report_struct_BSIC_N_SIZE   6
#define CSN1_PSI13_message_content_BCCH_CHANGE_MARK 1213
#define CSN1_PSI13_message_content_BCCH_CHANGE_MARK_SIZE   3
#define CSN1_PSI13_message_content_SI13_CHANGE_MARK 1215
#define CSN1_PSI13_message_content_SI13_CHANGE_MARK_SIZE   2
#define CSN1_PSI1_message_content_GPRS_Cell_Options 1136
#define CSN1_PSI1_message_content_GPRS_Cell_Options_SIZE   0
#define CSN1_PSI1_message_content_MEASUREMENT_ORDER 1135
#define CSN1_PSI1_message_content_MEASUREMENT_ORDER_SIZE   1
#define CSN1_PSI1_message_content_PBCCH_CHANGE_MARK 1130
#define CSN1_PSI1_message_content_PBCCH_CHANGE_MARK_SIZE   3
#define CSN1_PSI2_message_content_PCCCH_Description 1463
#define CSN1_PSI2_message_content_PCCCH_Description_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_ARFCN 2338
#define CSN1_PS_Handover_Radio_Resources_2_IE_ARFCN_SIZE  10
#define CSN1_PS_Handover_Radio_Resources_IE_PR_MODE 1725
#define CSN1_PS_Handover_Radio_Resources_IE_PR_MODE_SIZE   1
#define CSN1_Reject_struct_Packet_Request_Reference 282
#define CSN1_Reject_struct_Packet_Request_Reference_SIZE  27
#define CSN1_Response_Time_SACCH_struct_TRESP_SACCH 753
#define CSN1_Response_Time_SACCH_struct_TRESP_SACCH_SIZE   1
#define CSN1_Response_Time_SACCH_struct_TRMIN_SACCH 752
#define CSN1_Response_Time_SACCH_struct_TRMIN_SACCH_SIZE   1
#define CSN1_Response_Time_SDCCH_struct_TRESP_SDCCH 758
#define CSN1_Response_Time_SDCCH_struct_TRESP_SDCCH_SIZE   1
#define CSN1_Response_Time_SDCCH_struct_TRMIN_SDCCH 757
#define CSN1_Response_Time_SDCCH_struct_TRMIN_SDCCH_SIZE   1
#define CSN1_SI_Message_List_struct_Instance_bitmap 419
#define CSN1_SI_Message_List_struct_Instance_bitmap_SIZE   0
#define CSN1_SI_Message_List_struct_SIX_CHANGE_MARK 417
#define CSN1_SI_Message_List_struct_SIX_CHANGE_MARK_SIZE   3
#define CSN1_SI_Message_List_struct_SI_MESSAGE_TYPE 415
#define CSN1_SI_Message_List_struct_SI_MESSAGE_TYPE_SIZE   8
#define CSN1_Single_Block_Allocation_struct_PR_MODE 1556
#define CSN1_Single_Block_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_Single_Uplink_Assignment_2_IE_RLC_MODE 1879
#define CSN1_Single_Uplink_Assignment_2_IE_RLC_MODE_SIZE   1
#define CSN1_Timeslot_description_2_struct_ALPHA_C1 135
#define CSN1_Timeslot_description_2_struct_ALPHA_C1_SIZE   4
#define CSN1_Timeslot_description_2_struct_ALPHA_C2 144
#define CSN1_Timeslot_description_2_struct_ALPHA_C2_SIZE   4
#define CSN1_UTRAN_CSG_Measurement_Report_IE_CSG_ID 627
#define CSN1_UTRAN_CSG_Measurement_Report_IE_CSG_ID_SIZE  27
#define CSN1_UTRAN_FDD_Target_cell_IE_Bandwidth_FDD 2318
#define CSN1_UTRAN_FDD_Target_cell_IE_Bandwidth_FDD_SIZE   3
#define CSN1_UTRAN_TDD_Target_cell_IE_Bandwidth_TDD 2323
#define CSN1_UTRAN_TDD_Target_cell_IE_Bandwidth_TDD_SIZE   3
#define CSN1_UTRAN_TDD_Target_cell_IE_Diversity_TDD 2322
#define CSN1_UTRAN_TDD_Target_cell_IE_Diversity_TDD_SIZE   1
#define CSN1__3G_CCN_Measurement_Report_Struct_N_3G 718
#define CSN1__3G_CCN_Measurement_Report_Struct_N_3G_SIZE   3
#define CSN1__3G_Target_Cell_Struct_SCRAMBLING_CODE   2
#define CSN1__3G_Target_Cell_Struct_SCRAMBLING_CODE_SIZE   9
#define CSN1_COMPACT_NCP2_Property_struct_TIME_GROUP  99
#define CSN1_COMPACT_NCP2_Property_struct_TIME_GROUP_SIZE   2
#define CSN1_COMPACT_reduced_MA_IE_Reduced_MA_bitmap 252
#define CSN1_COMPACT_reduced_MA_IE_Reduced_MA_bitmap_SIZE   0
#define CSN1_Cell_Identification_IE_Cell_Identity_IE 596
#define CSN1_Cell_Identification_IE_Cell_Identity_IE_SIZE  16
#define CSN1_Cell_Selection_struct_CELL_BAR_ACCESS_2 301
#define CSN1_Cell_Selection_struct_CELL_BAR_ACCESS_2_SIZE   1
#define CSN1_Cell_Selection_struct_GPRS_PENALTY_TIME 307
#define CSN1_Cell_Selection_struct_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_Channel_Description_struct_CHANNEL_MODE 744
#define CSN1_Channel_Description_struct_CHANNEL_MODE_SIZE   8
#define CSN1_Channel_Description_struct_CHANNEL_TYPE 736
#define CSN1_Channel_Description_struct_CHANNEL_TYPE_SIZE   6
#define CSN1_Channel_Request_Description_IE_RLC_MODE 199
#define CSN1_Channel_Request_Description_IE_RLC_MODE_SIZE   1
#define CSN1_Content_DTM_EGPRS_High_Multi_Slot_Class 1336
#define CSN1_Content_DTM_EGPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_DLMC_Indirect_encoding_struct_MA_NUMBER 1734
#define CSN1_DLMC_Indirect_encoding_struct_MA_NUMBER_SIZE   4
#define CSN1_Downlink_TBF_assignment_struct_RLC_MODE 1399
#define CSN1_Downlink_TBF_assignment_struct_RLC_MODE_SIZE   1
#define CSN1_Dynamic_Allocation_2_IE_USF_GRANULARITY 1868
#define CSN1_Dynamic_Allocation_2_IE_USF_GRANULARITY_SIZE   1
#define CSN1_Dynamic_Allocation_3_IE_USF_GRANULARITY 1064
#define CSN1_Dynamic_Allocation_3_IE_USF_GRANULARITY_SIZE   1
#define CSN1_GPRS_mode_struct_CHANNEL_CODING_COMMAND 1343
#define CSN1_GPRS_mode_struct_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_GSM_target_cell_struct_G_RNTI_extension 2304
#define CSN1_GSM_target_cell_struct_G_RNTI_extension_SIZE   4
#define CSN1_Individual_priorities_IE_GERAN_PRIORITY 1076
#define CSN1_Individual_priorities_IE_GERAN_PRIORITY_SIZE   3
#define CSN1_Multiple_Uplink_Assignment_2_IE_N_PAIRS 1812
#define CSN1_Multiple_Uplink_Assignment_2_IE_N_PAIRS_SIZE   3
#define CSN1_Multiple_Uplink_Assignment_2_struct_TSH 1690
#define CSN1_Multiple_Uplink_Assignment_2_struct_TSH_SIZE   2
#define CSN1_Neighbouring_Cell_Report_struct_RXLEV_N 769
#define CSN1_Neighbouring_Cell_Report_struct_RXLEV_N_SIZE   6
#define CSN1_Non_GPRS_Cell_Options_IE_BS_AG_BLKS_RES 1444
#define CSN1_Non_GPRS_Cell_Options_IE_BS_AG_BLKS_RES_SIZE   3
#define CSN1_Non_GPRS_Extension_Information_p3G_ECSR 1453
#define CSN1_Non_GPRS_Extension_Information_p3G_ECSR_SIZE   1
#define CSN1_Non_Hopping_PCCCH_Carriers_struct_ARFCN 1470
#define CSN1_Non_Hopping_PCCCH_Carriers_struct_ARFCN_SIZE  10
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_0 1475
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_0_SIZE   4
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_1 1476
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_1_SIZE   4
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_2 1477
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_2_SIZE   4
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_3 1478
#define CSN1_Number_of_Idle_Blocks_struct_NIB_CCCH_3_SIZE   4
#define CSN1_PRACH_Control_Parameters_IE_MAX_RETRANS 245
#define CSN1_PRACH_Control_Parameters_IE_MAX_RETRANS_SIZE   8
#define CSN1_PSI13_message_content_GPRS_Cell_Options 1221
#define CSN1_PSI13_message_content_GPRS_Cell_Options_SIZE   0
#define CSN1_PSI13_message_content_PBCCH_Description 1224
#define CSN1_PSI13_message_content_PBCCH_Description_SIZE   0
#define CSN1_PSI14_message_content_PBCCH_Description 2127
#define CSN1_PSI14_message_content_PBCCH_Description_SIZE   0
#define CSN1_PSI16_message_content_PSI16_CHANGE_MARK 482
#define CSN1_PSI16_message_content_PSI16_CHANGE_MARK_SIZE   2
#define CSN1_PSI1_message_content_PSI1_REPEAT_PERIOD 1132
#define CSN1_PSI1_message_content_PSI1_REPEAT_PERIOD_SIZE   4
#define CSN1_PSI3_bis_message_content_LSA_Parameters 1166
#define CSN1_PSI3_bis_message_content_LSA_Parameters_SIZE   0
#define CSN1_PSI3_bis_message_content_PSI3_BIS_COUNT 1151
#define CSN1_PSI3_bis_message_content_PSI3_BIS_COUNT_SIZE   4
#define CSN1_PSI3_bis_message_content_PSI3_BIS_INDEX 1150
#define CSN1_PSI3_bis_message_content_PSI3_BIS_INDEX_SIZE   4
#define CSN1_PSI3_message_content_CELL_BAR_QUALIFY_3 1512
#define CSN1_PSI3_message_content_CELL_BAR_QUALIFY_3_SIZE   2
#define CSN1_PSI3_ter_message_content_PSI3_TER_COUNT 865
#define CSN1_PSI3_ter_message_content_PSI3_TER_COUNT_SIZE   4
#define CSN1_PSI3_ter_message_content_PSI3_TER_INDEX 864
#define CSN1_PSI3_ter_message_content_PSI3_TER_INDEX_SIZE   4
#define CSN1_PSI_Message_List_struct_Instance_bitmap 406
#define CSN1_PSI_Message_List_struct_Instance_bitmap_SIZE   0
#define CSN1_Packet_CS_Command_message_content_spare 525
#define CSN1_Packet_CS_Command_message_content_spare_SIZE   2
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_2 1829
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_2_SIZE   3
#define CSN1_Reference_Frequency_struct_RFL_contents 1457
#define CSN1_Reference_Frequency_struct_RFL_contents_SIZE   0
#define CSN1_Single_Block_Allocation_struct_GAMMA_TN 1554
#define CSN1_Single_Block_Allocation_struct_GAMMA_TN_SIZE   5
#define CSN1_Single_Uplink_Assignment_2_IE_RESEGMENT 1854
#define CSN1_Single_Uplink_Assignment_2_IE_RESEGMENT_SIZE   1
#define CSN1_UTRAN_CSG_Measurement_Report_IE_PLMN_ID 626
#define CSN1_UTRAN_CSG_Measurement_Report_IE_PLMN_ID_SIZE  24
#define CSN1_UTRAN_TDD_Target_cell_IE_Cell_Parameter 2324
#define CSN1_UTRAN_TDD_Target_cell_IE_Cell_Parameter_SIZE   7
#define CSN1_UTRAN_TDD_Target_cell_IE_Sync_Case_TSTD 2325
#define CSN1_UTRAN_TDD_Target_cell_IE_Sync_Case_TSTD_SIZE   1
#define CSN1_Uplink_TBF_Assignment_2_struct_RLC_MODE 941
#define CSN1_Uplink_TBF_Assignment_2_struct_RLC_MODE_SIZE   1
#define CSN1_Add_Frequency_list_struct_FREQUENCY_DIFF 1367
#define CSN1_Add_Frequency_list_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_Additional_PFCs_struct_NPM_Transfer_Time 263
#define CSN1_Additional_PFCs_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_C1 1808
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_C1_SIZE   3
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_C2 1809
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_C2_SIZE   3
#define CSN1_CN_Domain_Identity_IE_CN_Domain_Identity 491
#define CSN1_CN_Domain_Identity_IE_CN_Domain_Identity_SIZE   2
#define CSN1_COMPACT_Cell_Selection_struct_HCS_params 448
#define CSN1_COMPACT_Cell_Selection_struct_HCS_params_SIZE   8
#define CSN1_COMPACT_Cell_Selection_struct_TIME_GROUP 449
#define CSN1_COMPACT_Cell_Selection_struct_TIME_GROUP_SIZE   2
#define CSN1_Channel_Description_struct_POWER_COMMAND 741
#define CSN1_Channel_Description_struct_POWER_COMMAND_SIZE   0
#define CSN1_Channel_Group_struct_TIMESLOT_ALLOCATION 105
#define CSN1_Channel_Group_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Downlink_TBF_assignment_2_struct_bis_PFI 510
#define CSN1_Downlink_TBF_assignment_2_struct_bis_PFI_SIZE   7
#define CSN1_Downlink_TBF_assignment_struct_bis_RB_Id 980
#define CSN1_Downlink_TBF_assignment_struct_bis_RB_Id_SIZE   5
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_TSC 1267
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_TSC_SIZE   3
#define CSN1_ENH_Measurement_parameters_struct_BA_IND 1089
#define CSN1_ENH_Measurement_parameters_struct_BA_IND_SIZE   1
#define CSN1_EXT_Frequency_list_struct_FREQUENCY_DIFF  86
#define CSN1_EXT_Frequency_list_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_E_UTRAN_CSG_Description_IE_CSG_PCI_SPLIT 2037
#define CSN1_E_UTRAN_CSG_Description_IE_CSG_PCI_SPLIT_SIZE   0
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_CSG_ID 622
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_CSG_ID_SIZE  27
#define CSN1_E_UTRAN_Parameters_IE_E_UTRAN_CCN_ACTIVE 2004
#define CSN1_E_UTRAN_Parameters_IE_E_UTRAN_CCN_ACTIVE_SIZE   1
#define CSN1_GPRS_Mobile_Allocations_struct_MA_NUMBER 1461
#define CSN1_GPRS_Mobile_Allocations_struct_MA_NUMBER_SIZE   4
#define CSN1_GPRS_Power_Control_Parameters_IE_N_AVG_I 220
#define CSN1_GPRS_Power_Control_Parameters_IE_N_AVG_I_SIZE   4
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_T 218
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_T_SIZE   5
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_W 217
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_W_SIZE   5
#define CSN1_GSM_Priority_Parameters_IE_T_Reselection 1992
#define CSN1_GSM_Priority_Parameters_IE_T_Reselection_SIZE   2
#define CSN1_Global_Power_Control_Parameters_IE_ALPHA 209
#define CSN1_Global_Power_Control_Parameters_IE_ALPHA_SIZE   4
#define CSN1_MBMS_Information_MBMS_Channel_Parameters 2434
#define CSN1_MBMS_Information_MBMS_Channel_Parameters_SIZE   0
#define CSN1_MPRACH_Control_Parameters_IE_MAX_RETRANS 258
#define CSN1_MPRACH_Control_Parameters_IE_MAX_RETRANS_SIZE   2
#define CSN1_Multiple_Uplink_Assignment_2_IE_ALPHA_C1 1813
#define CSN1_Multiple_Uplink_Assignment_2_IE_ALPHA_C1_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_2_IE_ALPHA_C2 1814
#define CSN1_Multiple_Uplink_Assignment_2_IE_ALPHA_C2_SIZE   4
#define CSN1_NCP2_Repeat_struct_NR_OF_REMAINING_CELLS 462
#define CSN1_NCP2_Repeat_struct_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_NC_Measurement_Report_struct_FREQUENCY_N 798
#define CSN1_NC_Measurement_Report_struct_FREQUENCY_N_SIZE   6
#define CSN1_NC_Measurement_Report_struct_bis_BA_USED 817
#define CSN1_NC_Measurement_Report_struct_bis_BA_USED_SIZE   1
#define CSN1_NC_Measurement_Report_struct_bis_NC_MODE 816
#define CSN1_NC_Measurement_Report_struct_bis_NC_MODE_SIZE   1
#define CSN1_PSI13_message_content_PSI1_REPEAT_PERIOD 1223
#define CSN1_PSI13_message_content_PSI1_REPEAT_PERIOD_SIZE   4
#define CSN1_PSI16_message_content_CN_DOMAIN_IDENTITY 490
#define CSN1_PSI16_message_content_CN_DOMAIN_IDENTITY_SIZE   2
#define CSN1_PSI2_message_content_Cell_Identification 1436
#define CSN1_PSI2_message_content_Cell_Identification_SIZE  64
#define CSN1_PSI3_message_content_COMPACT_Information 1504
#define CSN1_PSI3_message_content_COMPACT_Information_SIZE   0
#define CSN1_PSI_Message_List_struct_PSIX_CHANGE_MARK 404
#define CSN1_PSI_Message_List_struct_PSIX_CHANGE_MARK_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_IE_GPRS_mode 1728
#define CSN1_PS_Handover_Radio_Resources_IE_GPRS_mode_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_IE_RLC_RESET 1723
#define CSN1_PS_Handover_Radio_Resources_IE_RLC_RESET_SIZE   1
#define CSN1_Packet_Request_Reference_IE_FRAME_NUMBER 226
#define CSN1_Packet_Request_Reference_IE_FRAME_NUMBER_SIZE  16
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_C1 1830
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_C1_SIZE   3
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_C2 1831
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_C2_SIZE   3
#define CSN1_Repeated_Page_info_struct_CHANNEL_NEEDED 2422
#define CSN1_Repeated_Page_info_struct_CHANNEL_NEEDED_SIZE   2
#define CSN1_Repeated_Page_info_struct_eMLPP_PRIORITY 2423
#define CSN1_Repeated_Page_info_struct_eMLPP_PRIORITY_SIZE   3
#define CSN1_Response_Time_struct_TRESP_MAC_Dedicated  73
#define CSN1_Response_Time_struct_TRESP_MAC_Dedicated_SIZE   7
#define CSN1_SI13_PBCCH_Location_struct_SI13_LOCATION  92
#define CSN1_SI13_PBCCH_Location_struct_SI13_LOCATION_SIZE   1
#define CSN1_Single_Downlink_Assignment_2_IE_RLC_MODE 1848
#define CSN1_Single_Downlink_Assignment_2_IE_RLC_MODE_SIZE   1
#define CSN1_UTRAN_FDD_Target_cell_IE_SCRAMBLING_CODE 2319
#define CSN1_UTRAN_FDD_Target_cell_IE_SCRAMBLING_CODE_SIZE   9
#define CSN1_Uplink_Assignment_2_struct_RTTI_USF_MODE 1646
#define CSN1_Uplink_Assignment_2_struct_RTTI_USF_MODE_SIZE   1
#define CSN1_Add_Frequency_list_struct_START_FREQUENCY 1362
#define CSN1_Add_Frequency_list_struct_START_FREQUENCY_SIZE  10
#define CSN1_CCN_Measurement_Report_struct_FREQUENCY_N 713
#define CSN1_CCN_Measurement_Report_struct_FREQUENCY_N_SIZE   6
#define CSN1_COMPACT_NCP2_Repeat_struct_FREQUENCY_DIFF 468
#define CSN1_COMPACT_NCP2_Repeat_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_RLC_Entity_2 1752
#define CSN1_Carrier_Specific_Info_struct_RLC_Entity_2_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_RLC_Entity_3 1753
#define CSN1_Carrier_Specific_Info_struct_RLC_Entity_3_SIZE   0
#define CSN1_Cell_Selection_struct_SI13_PBCCH_LOCATION 310
#define CSN1_Cell_Selection_struct_SI13_PBCCH_LOCATION_SIZE   0
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN0 341
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN0_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN1 342
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN1_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN2 343
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN2_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN3 344
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN3_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN4 345
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN4_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN5 346
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN5_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN6 347
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN6_SIZE   4
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN7 348
#define CSN1_Channel_Quality_Report_struct_I_LEVEL_TN7_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN0 651
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN0_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN1 652
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN1_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN2 653
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN2_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN3 654
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN3_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN4 655
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN4_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN5 656
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN5_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN6 657
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN6_SIZE   4
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN7 658
#define CSN1_DLMC_BEP_Measurements_Struct_MEAN_BEP_TN7_SIZE   4
#define CSN1_Downlink_TBF_assignment_2_struct_RLC_MODE 360
#define CSN1_Downlink_TBF_assignment_2_struct_RLC_MODE_SIZE   1
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_HSN 1281
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_HSN_SIZE   6
#define CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme 878
#define CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme_SIZE   4
#define CSN1_ENH_Measurement_parameters_struct_PMO_IND 1092
#define CSN1_ENH_Measurement_parameters_struct_PMO_IND_SIZE   1
#define CSN1_EXT_Frequency_list_struct_START_FREQUENCY  83
#define CSN1_EXT_Frequency_list_struct_START_FREQUENCY_SIZE  10
#define CSN1_EXT_Measurement_Report_struct_FREQUENCY_N 790
#define CSN1_EXT_Measurement_Report_struct_FREQUENCY_N_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN0 781
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN0_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN1 782
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN1_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN2 783
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN2_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN3 784
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN3_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN4 785
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN4_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN5 786
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN5_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN6 787
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN6_SIZE   6
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN7 788
#define CSN1_EXT_Measurement_Report_struct_I_LEVEL_TN7_SIZE   6
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_PLMN_ID 621
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_PLMN_ID_SIZE  24
#define CSN1_Frequency_Parameters_IE_Direct_encoding_1 1253
#define CSN1_Frequency_Parameters_IE_Direct_encoding_1_SIZE   0
#define CSN1_Frequency_Parameters_IE_Direct_encoding_2 1261
#define CSN1_Frequency_Parameters_IE_Direct_encoding_2_SIZE   0
#define CSN1_Frequency_Parameters_IE_Indirect_encoding 1256
#define CSN1_Frequency_Parameters_IE_Indirect_encoding_SIZE   0
#define CSN1_GPRS_Mobile_Allocation_IE_RFL_number_list 584
#define CSN1_GPRS_Mobile_Allocation_IE_RFL_number_list_SIZE   0
#define CSN1_GSM_Priority_Parameters_IE_GERAN_PRIORITY 1988
#define CSN1_GSM_Priority_Parameters_IE_GERAN_PRIORITY_SIZE   3
#define CSN1_GSM_Priority_Parameters_IE_THRESH_GSM_low 1990
#define CSN1_GSM_Priority_Parameters_IE_THRESH_GSM_low_SIZE   4
#define CSN1_GSM_target_cell_struct_E_UTRAN_CCN_ACTIVE 2313
#define CSN1_GSM_target_cell_struct_E_UTRAN_CCN_ACTIVE_SIZE   1
#define CSN1_MBMS_Service_Request_message_content_TLLI 528
#define CSN1_MBMS_Service_Request_message_content_TLLI_SIZE  32
#define CSN1_MBMS_Service_Request_message_content_TMGI 529
#define CSN1_MBMS_Service_Request_message_content_TMGI_SIZE   0
#define CSN1_MPRACH_description_struct_MPRACH_TIMESLOT 2287
#define CSN1_MPRACH_description_struct_MPRACH_TIMESLOT_SIZE   3
#define CSN1_MS_RA_capability_value_part_struct_Length 1338
#define CSN1_MS_RA_capability_value_part_struct_Length_SIZE   7
#define CSN1_Multiple_Uplink_Assignment_2_IE_RESEGMENT 1787
#define CSN1_Multiple_Uplink_Assignment_2_IE_RESEGMENT_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_struct_GAMMA 1697
#define CSN1_Multiple_Uplink_Assignment_2_struct_GAMMA_SIZE   5
#define CSN1_Multiple_Uplink_Assignment_2_struct_P0_C1 1686
#define CSN1_Multiple_Uplink_Assignment_2_struct_P0_C1_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_2_struct_P0_C2 1688
#define CSN1_Multiple_Uplink_Assignment_2_struct_P0_C2_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_struct_PR_MODE 1244
#define CSN1_Multiple_Uplink_Assignment_struct_PR_MODE_SIZE   1
#define CSN1_NC_Measurement_Report_struct_bis_PMO_USED 820
#define CSN1_NC_Measurement_Report_struct_bis_PMO_USED_SIZE   1
#define CSN1_PSI13_message_content_LB_MS_TXPWR_MAX_CCH 1232
#define CSN1_PSI13_message_content_LB_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_PSI13_message_content_PRIORITY_ACCESS_THR 1219
#define CSN1_PSI13_message_content_PRIORITY_ACCESS_THR_SIZE   3
#define CSN1_PSI16_message_content_Iu_MODE_NMO_SUPPORT 488
#define CSN1_PSI16_message_content_Iu_MODE_NMO_SUPPORT_SIZE   1
#define CSN1_PSI3_bis_message_content_PSI3_CHANGE_MARK 1149
#define CSN1_PSI3_bis_message_content_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_PSI3_ter_message_content_PSI3_CHANGE_MARK 863
#define CSN1_PSI3_ter_message_content_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_IE_CCN_ACTIVE 1715
#define CSN1_PS_Handover_Radio_Resources_IE_CCN_ACTIVE_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_IE_EGPRS_mode 1727
#define CSN1_PS_Handover_Radio_Resources_IE_EGPRS_mode_SIZE   0
#define CSN1_Packet_Paging_Request_message_content_NLN 2417
#define CSN1_Packet_Paging_Request_message_content_NLN_SIZE   2
#define CSN1_Repeated_Page_info_struct_Mobile_Identity 2420
#define CSN1_Repeated_Page_info_struct_Mobile_Identity_SIZE   0
#define CSN1_SI13_PBCCH_Location_struct_PBCCH_LOCATION  90
#define CSN1_SI13_PBCCH_Location_struct_PBCCH_LOCATION_SIZE   2
#define CSN1_UTRAN_CSG_Measurement_Report_IE_UTRAN_CGI 625
#define CSN1_UTRAN_CSG_Measurement_Report_IE_UTRAN_CGI_SIZE  28
#define CSN1__3G_Target_Cell_Struct_REPORTING_QUANTITY   7
#define CSN1__3G_Target_Cell_Struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_Add_Frequency_list_struct_FREQ_DIFF_LENGTH 1366
#define CSN1_Add_Frequency_list_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_RLC_MODE 1798
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_RLC_MODE_SIZE   1
#define CSN1_COMPACT_NCP2_Repeat_struct_START_FREQUENCY 465
#define CSN1_COMPACT_NCP2_Repeat_struct_START_FREQUENCY_SIZE  10
#define CSN1_COMPACT_Neighbour_parameter_set_struct_NCC 1170
#define CSN1_COMPACT_Neighbour_parameter_set_struct_NCC_SIZE   3
#define CSN1_Cell_Selection_struct_GPRS_RESELECT_OFFSET 308
#define CSN1_Cell_Selection_struct_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_Channel_Description_struct_USF_GRANULARITY 740
#define CSN1_Channel_Description_struct_USF_GRANULARITY_SIZE   1
#define CSN1_Container_repetition_struct_CONTAINER_DATA 377
#define CSN1_Container_repetition_struct_CONTAINER_DATA_SIZE   0
#define CSN1_Content_Extended_DTM_GPRS_Multi_Slot_Class 1323
#define CSN1_Content_Extended_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_PR_MODE 2511
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_PR_MODE_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_CONTROL_ACK 1402
#define CSN1_Downlink_TBF_assignment_struct_CONTROL_ACK_SIZE   1
#define CSN1_EGPRS_mode_2_IE_Multiple_Uplink_Assignment 1785
#define CSN1_EGPRS_mode_2_IE_Multiple_Uplink_Assignment_SIZE   0
#define CSN1_EXT_Frequency_list_struct_FREQ_DIFF_LENGTH  85
#define CSN1_EXT_Frequency_list_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN_index_list 586
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN_index_list_SIZE   0
#define CSN1_Gen_Cell_Sel_struct_RA_RESELECT_HYSTERESIS 1500
#define CSN1_Gen_Cell_Sel_struct_RA_RESELECT_HYSTERESIS_SIZE   3
#define CSN1_Global_Power_Control_Parameters_IE_N_AVG_I 215
#define CSN1_Global_Power_Control_Parameters_IE_N_AVG_I_SIZE   4
#define CSN1_Global_Power_Control_Parameters_IE_T_AVG_T 211
#define CSN1_Global_Power_Control_Parameters_IE_T_AVG_T_SIZE   5
#define CSN1_Global_Power_Control_Parameters_IE_T_AVG_W 210
#define CSN1_Global_Power_Control_Parameters_IE_T_AVG_W_SIZE   5
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_HSN 999
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_HSN_SIZE   6
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_TSC 997
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_TSC_SIZE   3
#define CSN1_MPRACH_description_IE_Frequency_Parameters 2446
#define CSN1_MPRACH_description_IE_Frequency_Parameters_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_IE_PR_MODE_C1 1791
#define CSN1_Multiple_Uplink_Assignment_2_IE_PR_MODE_C1_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_IE_PR_MODE_C2 1793
#define CSN1_Multiple_Uplink_Assignment_2_IE_PR_MODE_C2_SIZE   1
#define CSN1_NC_Measurement_Report_struct_bis_BSIC_Seen 821
#define CSN1_NC_Measurement_Report_struct_bis_BSIC_Seen_SIZE   1
#define CSN1_Non_GPRS_Cell_Options_IE_MS_TXPWR_MAX_CCCH 1450
#define CSN1_Non_GPRS_Cell_Options_IE_MS_TXPWR_MAX_CCCH_SIZE   5
#define CSN1_PBCCH_Description_struct_2_PSI_CHANGED_IND 2132
#define CSN1_PBCCH_Description_struct_2_PSI_CHANGED_IND_SIZE   1
#define CSN1_PSI15_message_content_UTRAN_Frequency_List 478
#define CSN1_PSI15_message_content_UTRAN_Frequency_List_SIZE   0
#define CSN1_PSI2_message_content_Non_GPRS_Cell_Options 1437
#define CSN1_PSI2_message_content_Non_GPRS_Cell_Options_SIZE   0
#define CSN1_PSI3_quater_message_content__3G_CCN_ACTIVE 1211
#define CSN1_PSI3_quater_message_content__3G_CCN_ACTIVE_SIZE   1
#define CSN1_PSI4_message_content_INT_MEAS_CHANNEL_LIST 874
#define CSN1_PSI4_message_content_INT_MEAS_CHANNEL_LIST_SIZE   0
#define CSN1_PSI5_message_content__700_REPORTING_OFFSET 1535
#define CSN1_PSI5_message_content__700_REPORTING_OFFSET_SIZE   3
#define CSN1_PSI5_message_content__810_REPORTING_OFFSET 1537
#define CSN1_PSI5_message_content__810_REPORTING_OFFSET_SIZE   3
#define CSN1_PS_Handover_Radio_Resources_2_IE_RLC_RESET 2351
#define CSN1_PS_Handover_Radio_Resources_2_IE_RLC_RESET_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_RESEGMENT 2385
#define CSN1_PS_Handover_Radio_Resources_3_IE_RESEGMENT_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_RLC_RESET 2398
#define CSN1_PS_Handover_Radio_Resources_3_IE_RLC_RESET_SIZE   1
#define CSN1_Packet_Polling_Request_message_content_TQI 383
#define CSN1_Packet_Polling_Request_message_content_TQI_SIZE  16
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_RLC_MODE 1819
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_RLC_MODE_SIZE   1
#define CSN1_SI_Message_List_struct_ADDITIONAL_MSG_TYPE 420
#define CSN1_SI_Message_List_struct_ADDITIONAL_MSG_TYPE_SIZE   1
#define CSN1_Single_Uplink_Assignment_2_IE_Pulse_Format 1881
#define CSN1_Single_Uplink_Assignment_2_IE_Pulse_Format_SIZE   0
#define CSN1_Timeslot_description_2_struct_GAMMA_TN0_C1 136
#define CSN1_Timeslot_description_2_struct_GAMMA_TN0_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN0_C2 145
#define CSN1_Timeslot_description_2_struct_GAMMA_TN0_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN1_C1 137
#define CSN1_Timeslot_description_2_struct_GAMMA_TN1_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN1_C2 146
#define CSN1_Timeslot_description_2_struct_GAMMA_TN1_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN2_C1 138
#define CSN1_Timeslot_description_2_struct_GAMMA_TN2_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN2_C2 147
#define CSN1_Timeslot_description_2_struct_GAMMA_TN2_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN3_C1 139
#define CSN1_Timeslot_description_2_struct_GAMMA_TN3_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN3_C2 148
#define CSN1_Timeslot_description_2_struct_GAMMA_TN3_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN4_C1 140
#define CSN1_Timeslot_description_2_struct_GAMMA_TN4_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN4_C2 149
#define CSN1_Timeslot_description_2_struct_GAMMA_TN4_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN5_C1 141
#define CSN1_Timeslot_description_2_struct_GAMMA_TN5_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN5_C2 150
#define CSN1_Timeslot_description_2_struct_GAMMA_TN5_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN6_C1 142
#define CSN1_Timeslot_description_2_struct_GAMMA_TN6_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN6_C2 151
#define CSN1_Timeslot_description_2_struct_GAMMA_TN6_C2_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN7_C1 143
#define CSN1_Timeslot_description_2_struct_GAMMA_TN7_C1_SIZE   5
#define CSN1_Timeslot_description_2_struct_GAMMA_TN7_C2 152
#define CSN1_Timeslot_description_2_struct_GAMMA_TN7_C2_SIZE   5
#define CSN1_UTRAN_FDD_Description_struct_Bandwidth_FDD 311
#define CSN1_UTRAN_FDD_Description_struct_Bandwidth_FDD_SIZE   3
#define CSN1_UTRAN_TDD_Description_struct_Bandwidth_TDD 317
#define CSN1_UTRAN_TDD_Description_struct_Bandwidth_TDD_SIZE   3
#define CSN1_Uplink_Assignment_struct_TBF_Starting_Time 1239
#define CSN1_Uplink_Assignment_struct_TBF_Starting_Time_SIZE   0
#define CSN1_Add_Frequency_list_struct_NR_OF_FREQUENCIES 1365
#define CSN1_Add_Frequency_list_struct_NR_OF_FREQUENCIES_SIZE   5
#define CSN1_Additional_PFCs_struct_DN_NPM_Transfer_Time  77
#define CSN1_Additional_PFCs_struct_DN_NPM_Transfer_Time_SIZE   5
#define CSN1_Additional_PFCs_struct_UP_NPM_Transfer_Time 123
#define CSN1_Additional_PFCs_struct_UP_NPM_Transfer_Time_SIZE   5
#define CSN1_CCCH_Access_Information_struct_SI2n_SUPPORT 2126
#define CSN1_CCCH_Access_Information_struct_SI2n_SUPPORT_SIZE   2
#define CSN1_CCN_Support_Description_struct_Number_Cells  38
#define CSN1_CCN_Support_Description_struct_Number_Cells_SIZE   7
#define CSN1_COMPACT_NCP2_Repeat_struct_FREQ_DIFF_LENGTH 467
#define CSN1_COMPACT_NCP2_Repeat_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_Cell_Selection_struct_GPRS_MS_TXPWR_MAX_CCH 305
#define CSN1_Cell_Selection_struct_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Cell_Selection_struct_GPRS_RXLEV_ACCESS_MIN 304
#define CSN1_Cell_Selection_struct_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_Cell_Selection_struct_GPRS_TEMPORARY_OFFSET 306
#define CSN1_Cell_Selection_struct_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_Cell_Selection_struct_bis_CELL_BAR_ACCESS_2 429
#define CSN1_Cell_Selection_struct_bis_CELL_BAR_ACCESS_2_SIZE   1
#define CSN1_Cell_Selection_struct_bis_GPRS_PENALTY_TIME 435
#define CSN1_Cell_Selection_struct_bis_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_Content_Extended_DTM_EGPRS_Multi_Slot_Class 1324
#define CSN1_Content_Extended_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_DLMC_Indirect_encoding_struct_CHANGE_MARK_1 1735
#define CSN1_DLMC_Indirect_encoding_struct_CHANGE_MARK_1_SIZE   2
#define CSN1_DLMC_Indirect_encoding_struct_CHANGE_MARK_2 1736
#define CSN1_DLMC_Indirect_encoding_struct_CHANGE_MARK_2_SIZE   2
#define CSN1_DLMC_UL_Carrier_Info_struct_Primary_TSC_Set 1075
#define CSN1_DLMC_UL_Carrier_Info_struct_Primary_TSC_Set_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_bis_RLC_MODE 979
#define CSN1_Downlink_TBF_assignment_struct_bis_RLC_MODE_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_ter_RLC_MODE 1056
#define CSN1_Downlink_TBF_assignment_struct_ter_RLC_MODE_SIZE   1
#define CSN1_Dual_Carrier_Direct_encoding_1_struct_MAIO1 1269
#define CSN1_Dual_Carrier_Direct_encoding_1_struct_MAIO1_SIZE   6
#define CSN1_Dual_Carrier_Direct_encoding_1_struct_MAIO2 1270
#define CSN1_Dual_Carrier_Direct_encoding_1_struct_MAIO2_SIZE   6
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_MAIO1 1279
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_MAIO1_SIZE   6
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_MAIO2 1280
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_MAIO2_SIZE   6
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_ARFCN1 1284
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_ARFCN1_SIZE  10
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_ARFCN2 1285
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_ARFCN2_SIZE  10
#define CSN1_Dual_Carrier_Indirect_encoding_struct_MAIO1 1273
#define CSN1_Dual_Carrier_Indirect_encoding_struct_MAIO1_SIZE   6
#define CSN1_Dual_Carrier_Indirect_encoding_struct_MAIO2 1274
#define CSN1_Dual_Carrier_Indirect_encoding_struct_MAIO2_SIZE   6
#define CSN1_Dynamic_Allocation_2_struct_USF_GRANULARITY 112
#define CSN1_Dynamic_Allocation_2_struct_USF_GRANULARITY_SIZE   1
#define CSN1_ENH_Reporting_parameters_struct_Report_Type 1528
#define CSN1_ENH_Reporting_parameters_struct_Report_Type_SIZE   1
#define CSN1_EXT_Frequency_list_struct_NR_OF_FREQUENCIES  84
#define CSN1_EXT_Frequency_list_struct_NR_OF_FREQUENCIES_SIZE   5
#define CSN1_E_UTRAN_Measurement_Report_struct_N_E_UTRAN  79
#define CSN1_E_UTRAN_Measurement_Report_struct_N_E_UTRAN_SIZE   2
#define CSN1_Extended_Channel_Request_Description_IE_PFI 205
#define CSN1_Extended_Channel_Request_Description_IE_PFI_SIZE   7
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_BSIC 451
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_BSIC_SIZE   6
#define CSN1_MBMS_Frequency_List_struct_FREQ_LIST_NUMBER 993
#define CSN1_MBMS_Frequency_List_struct_FREQ_LIST_NUMBER_SIZE   2
#define CSN1_MBMS_MS_ID_Assignment_message_content_ALPHA 539
#define CSN1_MBMS_MS_ID_Assignment_message_content_ALPHA_SIZE   4
#define CSN1_MBMS_MS_ID_Assignment_message_content_GAMMA 540
#define CSN1_MBMS_MS_ID_Assignment_message_content_GAMMA_SIZE   5
#define CSN1_MBMS_MS_ID_Assignment_message_content_MS_ID 537
#define CSN1_MBMS_MS_ID_Assignment_message_content_MS_ID_SIZE   0
#define CSN1_MBMS_Sessions_List_IE_MBMS_Session_Identity 601
#define CSN1_MBMS_Sessions_List_IE_MBMS_Session_Identity_SIZE   8
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_MAIO 998
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_MAIO_SIZE   6
#define CSN1_Multiple_Uplink_Assignment_2_struct_N_PAIRS 1696
#define CSN1_Multiple_Uplink_Assignment_2_struct_N_PAIRS_SIZE   3
#define CSN1_Multislot_capability_struct_Single_Slot_DTM 1313
#define CSN1_Multislot_capability_struct_Single_Slot_DTM_SIZE   1
#define CSN1_NC_Frequency_list_struct_NR_OF_REMOVED_FREQ 1359
#define CSN1_NC_Frequency_list_struct_NR_OF_REMOVED_FREQ_SIZE   5
#define CSN1_NC_Frequency_list_struct_REMOVED_FREQ_INDEX 1360
#define CSN1_NC_Frequency_list_struct_REMOVED_FREQ_INDEX_SIZE   6
#define CSN1_Neighbour_Cell_params_struct_FREQUENCY_DIFF 855
#define CSN1_Neighbour_Cell_params_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_Non_GPRS_Cell_Options_IE_RADIO_LINK_TIMEOUT 1443
#define CSN1_Non_GPRS_Cell_Options_IE_RADIO_LINK_TIMEOUT_SIZE   4
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PCC_REL 1139
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PCC_REL_SIZE   1
#define CSN1_PRACH_Control_Parameters_IE_ACC_CONTR_CLASS 244
#define CSN1_PRACH_Control_Parameters_IE_ACC_CONTR_CLASS_SIZE  16
#define CSN1_PSI13_message_content_NETWORK_CONTROL_ORDER 1220
#define CSN1_PSI13_message_content_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_PSI_Message_List_struct_ADDITIONAL_MSG_TYPE 407
#define CSN1_PSI_Message_List_struct_ADDITIONAL_MSG_TYPE_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_2_IE_CCN_ACTIVE 2342
#define CSN1_PS_Handover_Radio_Resources_2_IE_CCN_ACTIVE_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_2_IE_EGPRS_mode 2352
#define CSN1_PS_Handover_Radio_Resources_2_IE_EGPRS_mode_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_CCN_ACTIVE 2363
#define CSN1_PS_Handover_Radio_Resources_3_IE_CCN_ACTIVE_SIZE   1
#define CSN1_Packet_Access_Reject_message_content_Reject 664
#define CSN1_Packet_Access_Reject_message_content_Reject_SIZE   0
#define CSN1_Packet_CS_Command_message_content_PAGE_MODE 523
#define CSN1_Packet_CS_Command_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_CS_Release_message_content_PAGE_MODE 2216
#define CSN1_Packet_CS_Release_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_CS_Release_message_content_RESEGMENT 2232
#define CSN1_Packet_CS_Release_message_content_RESEGMENT_SIZE   1
#define CSN1_Packet_Resource_Request_message_content_PFI 2086
#define CSN1_Packet_Resource_Request_message_content_PFI_SIZE   7
#define CSN1_Packet_SI_Status_message_content_GLOBAL_TFI 412
#define CSN1_Packet_SI_Status_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_SI_Status_message_content_PS_REL_REQ 425
#define CSN1_Packet_SI_Status_message_content_PS_REL_REQ_SIZE   1
#define CSN1_Repeated_Iu_Page_info_struct_eMLPP_PRIORITY 2431
#define CSN1_Repeated_Iu_Page_info_struct_eMLPP_PRIORITY_SIZE   3
#define CSN1_Serving_cell_data_struct_RXLEV_SERVING_CELL 824
#define CSN1_Serving_cell_data_struct_RXLEV_SERVING_CELL_SIZE   6
#define CSN1_Single_Downlink_Assignment_2_IE_CONTROL_ACK 1850
#define CSN1_Single_Downlink_Assignment_2_IE_CONTROL_ACK_SIZE   1
#define CSN1_Single_Uplink_Assignment_2_IE_RTTI_USF_MODE 1860
#define CSN1_Single_Uplink_Assignment_2_IE_RTTI_USF_MODE_SIZE   1
#define CSN1_UTRAN_CSG_Measurement_Report_IE_Access_Mode 628
#define CSN1_UTRAN_CSG_Measurement_Report_IE_Access_Mode_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_TFI_Assignment 933
#define CSN1_Uplink_TBF_Assignment_struct_TFI_Assignment_SIZE   5
#define CSN1_Uplink_TBF_Assignment_struct_USF_ALLOCATION 939
#define CSN1_Uplink_TBF_Assignment_struct_USF_ALLOCATION_SIZE   3
#define CSN1_Ack_Nack_Description_IE_FINAL_ACK_INDICATION 156
#define CSN1_Ack_Nack_Description_IE_FINAL_ACK_INDICATION_SIZE   1
#define CSN1_CCCH_Access_Information_struct_SI_STATUS_IND 2124
#define CSN1_CCCH_Access_Information_struct_SI_STATUS_IND_SIZE   1
#define CSN1_CCCH_Access_Information_struct_SPGC_CCCH_SUP 2117
#define CSN1_CCCH_Access_Information_struct_SPGC_CCCH_SUP_SIZE   1
#define CSN1_CCN_Support_Description_struct_CCN_SUPPORTED  39
#define CSN1_CCN_Support_Description_struct_CCN_SUPPORTED_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_Primary_TSC_Set 1757
#define CSN1_Carrier_Specific_Info_struct_Primary_TSC_Set_SIZE   1
#define CSN1_Channel_Request_Description_IE_LLC__PDU_TYPE 200
#define CSN1_Channel_Request_Description_IE_LLC__PDU_TYPE_SIZE   1
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_mode 2514
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_mode_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_MAX_LAPDm 2504
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_MAX_LAPDm_SIZE   3
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_RLC_RESET 2509
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_RLC_RESET_SIZE   1
#define CSN1_Downlink_TBF_assignment_2_struct_CONTROL_ACK 362
#define CSN1_Downlink_TBF_assignment_2_struct_CONTROL_ACK_SIZE   1
#define CSN1_EGPRS_mode_2_IE_Multiple_Downlink_Assignment 1761
#define CSN1_EGPRS_mode_2_IE_Multiple_Downlink_Assignment_SIZE   0
#define CSN1_ENH_Measurement_parameters_struct__3G_BA_IND 1090
#define CSN1_ENH_Measurement_parameters_struct__3G_BA_IND_SIZE   1
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_E_UTRAN_CI 619
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_E_UTRAN_CI_SIZE  28
#define CSN1_E_UTRAN_Target_cell_IE_Measurement_Bandwidth 266
#define CSN1_E_UTRAN_Target_cell_IE_Measurement_Bandwidth_SIZE   3
#define CSN1_Extension_Information_REDUCED_LATENCY_ACCESS 1051
#define CSN1_Extension_Information_REDUCED_LATENCY_ACCESS_SIZE   1
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability 1328
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability_SIZE   1
#define CSN1_GPRS_mode_struct_Global_Timeslot_description 1344
#define CSN1_GPRS_mode_struct_Global_Timeslot_description_SIZE   0
#define CSN1_GSM_target_cell_struct_Individual_Priorities 2314
#define CSN1_GSM_target_cell_struct_Individual_Priorities_SIZE   0
#define CSN1_GSM_target_cell_struct__700_REPORTING_OFFSET 2309
#define CSN1_GSM_target_cell_struct__700_REPORTING_OFFSET_SIZE   3
#define CSN1_GSM_target_cell_struct__810_REPORTING_OFFSET 2311
#define CSN1_GSM_target_cell_struct__810_REPORTING_OFFSET_SIZE   3
#define CSN1_Individual_priorities_IE_T3230_timeout_value 1088
#define CSN1_Individual_priorities_IE_T3230_timeout_value_SIZE   3
#define CSN1_Iu_mode_Channel_Request_Description_IE_RB_Id 202
#define CSN1_Iu_mode_Channel_Request_Description_IE_RB_Id_SIZE   5
#define CSN1_MBMS_Neighbouring_Cell_Report_struct_BA_USED 761
#define CSN1_MBMS_Neighbouring_Cell_Report_struct_BA_USED_SIZE   1
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_ARFCN 1001
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_ARFCN_SIZE  10
#define CSN1_MPRACH_Control_Parameters_IE_ACC_CONTR_CLASS 257
#define CSN1_MPRACH_Control_Parameters_IE_ACC_CONTR_CLASS_SIZE  16
#define CSN1_MPRACH_description_IE_MPRACH_TIMESLOT_NUMBER 2447
#define CSN1_MPRACH_description_IE_MPRACH_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Multiple_Uplink_Assignment_2_IE_Pulse_Format 1833
#define CSN1_Multiple_Uplink_Assignment_2_IE_Pulse_Format_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_struct_ALPHA_C1 1694
#define CSN1_Multiple_Uplink_Assignment_2_struct_ALPHA_C1_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_2_struct_ALPHA_C2 1695
#define CSN1_Multiple_Uplink_Assignment_2_struct_ALPHA_C2_SIZE   4
#define CSN1_NCP2_Property_struct_SAME_RA_AS_SERVING_CELL  93
#define CSN1_NCP2_Property_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_NC_Measurement_Report_struct_bis__3G_BA_USED 818
#define CSN1_NC_Measurement_Report_struct_bis__3G_BA_USED_SIZE   1
#define CSN1_Neighbour_Cell_params_struct_START_FREQUENCY 851
#define CSN1_Neighbour_Cell_params_struct_START_FREQUENCY_SIZE  10
#define CSN1_NonGSM_Message_struct_NR_OF_CONTAINER_OCTETS 475
#define CSN1_NonGSM_Message_struct_NR_OF_CONTAINER_OCTETS_SIZE   5
#define CSN1_PSI13_message_content_GPRS_Mobile_Allocation 1216
#define CSN1_PSI13_message_content_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_PSI1_message_content_Distribution_part_error 3160
#define CSN1_PSI1_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI2_message_content_Additional_PSI_Messages 1480
#define CSN1_PSI2_message_content_Additional_PSI_Messages_SIZE   5
#define CSN1_PSI2_message_content_Distribution_part_error 3177
#define CSN1_PSI2_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI2_message_content_GPRS_Mobile_Allocations 1460
#define CSN1_PSI2_message_content_GPRS_Mobile_Allocations_SIZE   0
#define CSN1_PSI3_message_content_CCN_Support_Description 1511
#define CSN1_PSI3_message_content_CCN_Support_Description_SIZE   0
#define CSN1_PSI3_message_content_Distribution_part_error 3178
#define CSN1_PSI3_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI3_message_content_Serving_Cell_parameters 1488
#define CSN1_PSI3_message_content_Serving_Cell_parameters_SIZE   0
#define CSN1_PSI3_quater_message_content_PSI3_CHANGE_MARK 1184
#define CSN1_PSI3_quater_message_content_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_PSI4_message_content_Distribution_part_error 3154
#define CSN1_PSI4_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI5_message_content_Distribution_part_error 3179
#define CSN1_PSI5_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI6_message_content_Distribution_part_error 3127
#define CSN1_PSI6_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI8_message_content_Distribution_part_error 3211
#define CSN1_PSI8_message_content_Distribution_part_error_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_BEP_PERIOD2 2377
#define CSN1_PS_Handover_Radio_Resources_3_IE_BEP_PERIOD2_SIZE   4
#define CSN1_PS_Handover_Radio_Resources_3_IE_CONTROL_ACK 2367
#define CSN1_PS_Handover_Radio_Resources_3_IE_CONTROL_ACK_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_PDAN_Coding 2375
#define CSN1_PS_Handover_Radio_Resources_3_IE_PDAN_Coding_SIZE   1
#define CSN1_Packet_CS_Command_message_content_GLOBAL_TFI 524
#define CSN1_Packet_CS_Command_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_CS_Release_message_content_EGPRS_mode 2247
#define CSN1_Packet_CS_Release_message_content_EGPRS_mode_SIZE   0
#define CSN1_Packet_CS_Release_message_content_GLOBAL_TFI 2217
#define CSN1_Packet_CS_Release_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_CS_Request_message_content_GLOBAL_TFI 521
#define CSN1_Packet_CS_Request_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_Downlink_Ack_Nack_message_content_PFI 349
#define CSN1_Packet_Downlink_Ack_Nack_message_content_PFI_SIZE   7
#define CSN1_Packet_PSI_Status_message_content_GLOBAL_TFI 400
#define CSN1_Packet_PSI_Status_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_PSI_Status_message_content_PS_REL_REQ 411
#define CSN1_Packet_PSI_Status_message_content_PS_REL_REQ_SIZE   1
#define CSN1_Packet_TBF_Release_message_content_PAGE_MODE 497
#define CSN1_Packet_TBF_Release_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Uplink_Ack_Nack_message_content_RB_Id 891
#define CSN1_Packet_Uplink_Ack_Nack_message_content_RB_Id_SIZE   5
#define CSN1_Packet_Uplink_Assignment_message_content_PFI 1561
#define CSN1_Packet_Uplink_Assignment_message_content_PFI_SIZE   7
#define CSN1_Packet_Uplink_Assignment_message_content_TQI 1544
#define CSN1_Packet_Uplink_Assignment_message_content_TQI_SIZE  16
#define CSN1_Packet_Uplink_Assignment_message_content_TSH 1594
#define CSN1_Packet_Uplink_Assignment_message_content_TSH_SIZE   2
#define CSN1_Repeated_Iu_Page_info_struct_Mobile_Identity 2427
#define CSN1_Repeated_Iu_Page_info_struct_Mobile_Identity_SIZE   0
#define CSN1_Serving_Cell_params_struct_CELL_BAR_ACCESS_2 1489
#define CSN1_Serving_Cell_params_struct_CELL_BAR_ACCESS_2_SIZE   1
#define CSN1_Unknown_PSI_Message_List_struct_MESSAGE_TYPE 409
#define CSN1_Unknown_PSI_Message_List_struct_MESSAGE_TYPE_SIZE   6
#define CSN1_Uplink_TBF_Assignment_struct_USF_GRANULARITY 937
#define CSN1_Uplink_TBF_Assignment_struct_USF_GRANULARITY_SIZE   1
#define CSN1_p3G_CSG_Description_IE_UTRAN_FREQUENCY_INDEX 2035
#define CSN1_p3G_CSG_Description_IE_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP 158
#define CSN1_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP_SIZE  64
#define CSN1_Additional_PSI_Messages_struct_PSI8_BROADCAST 1482
#define CSN1_Additional_PSI_Messages_struct_PSI8_BROADCAST_SIZE   1
#define CSN1_Cell_Selection_struct_SAME_RA_AS_SERVING_CELL 303
#define CSN1_Cell_Selection_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_Cell_Selection_struct_bis_SI13_PBCCH_Location 438
#define CSN1_Cell_Selection_struct_bis_SI13_PBCCH_Location_SIZE   0
#define CSN1_Channel_Request_Description_IE_RADIO_PRIORITY 198
#define CSN1_Channel_Request_Description_IE_RADIO_PRIORITY_SIZE   2
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_EGPRS_mode 2513
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_EGPRS_mode_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_PFI 610
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_PFI_SIZE   7
#define CSN1_Downlink_TBF_assignment_2_struct_bis_RLC_MODE 511
#define CSN1_Downlink_TBF_assignment_2_struct_bis_RLC_MODE_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_TFI_Assignment 1401
#define CSN1_Downlink_TBF_assignment_struct_TFI_Assignment_SIZE   5
#define CSN1_Dynamic_Allocation_2_IE_UPLINK_TFI_ASSIGNMENT 1869
#define CSN1_Dynamic_Allocation_2_IE_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_EGPRS_mode_struct_Global_Timeslot_description 1350
#define CSN1_EGPRS_mode_struct_Global_Timeslot_description_SIZE   0
#define CSN1_ENH_Measurement_parameters_struct_REPORT_TYPE 1093
#define CSN1_ENH_Measurement_parameters_struct_REPORT_TYPE_SIZE   1
#define CSN1_ENH_Reporting_parameters_struct_NCC_PERMITTED 1531
#define CSN1_ENH_Reporting_parameters_struct_NCC_PERMITTED_SIZE   8
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_Access_Mode 623
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_Access_Mode_SIZE   1
#define CSN1_E_UTRAN_CSG_Target_cell_IE_Tracking_Area_Code 690
#define CSN1_E_UTRAN_CSG_Target_cell_IE_Tracking_Area_Code_SIZE  16
#define CSN1_E_UTRAN_Target_Cell_struct_REPORTING_QUANTITY 701
#define CSN1_E_UTRAN_Target_Cell_struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_Extension_Information_BSS_PAGING_COORDINATION 1043
#define CSN1_Extension_Information_BSS_PAGING_COORDINATION_SIZE   1
#define CSN1_Extension_Information_MULTIPLE_TBF_CAPABILITY 1046
#define CSN1_Extension_Information_MULTIPLE_TBF_CAPABILITY_SIZE   1
#define CSN1_GPRS_Power_Control_Parameters_IE_PC_MEAS_CHAN 219
#define CSN1_GPRS_Power_Control_Parameters_IE_PC_MEAS_CHAN_SIZE   1
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_HCS_params 332
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_HCS_params_SIZE   8
#define CSN1_MBMS_Channel_Parameters_IE_MPRACH_description 2445
#define CSN1_MBMS_Channel_Parameters_IE_MPRACH_description_SIZE   0
#define CSN1_Multi_Block_Allocation_struct_TIMESLOT_NUMBER 923
#define CSN1_Multi_Block_Allocation_struct_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Multiple_Uplink_Assignment_2_IE_RTTI_USF_MODE 1816
#define CSN1_Multiple_Uplink_Assignment_2_IE_RTTI_USF_MODE_SIZE   1
#define CSN1_Neighbour_Cell_params_2_struct_Message_escape 3161
#define CSN1_Neighbour_Cell_params_2_struct_Message_escape_SIZE   0
#define CSN1_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH 854
#define CSN1_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_Neighbour_parameter_set_struct_PRIORITY_CLASS 1160
#define CSN1_Neighbour_parameter_set_struct_PRIORITY_CLASS_SIZE   3
#define CSN1_PBCCH_Description_struct_2_PSI1_REPEAT_PERIOD 2128
#define CSN1_PBCCH_Description_struct_2_PSI1_REPEAT_PERIOD_SIZE   4
#define CSN1_PRACH_Control_Parameters_IE_PERSISTENCE_LEVEL 248
#define CSN1_PRACH_Control_Parameters_IE_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_PSI13_message_content_Distribution_part_error 3166
#define CSN1_PSI13_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI14_message_content_CCCH_Access_Information 2113
#define CSN1_PSI14_message_content_CCCH_Access_Information_SIZE   0
#define CSN1_PSI14_message_content_Distribution_part_error 3212
#define CSN1_PSI14_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI15_message_content_Distribution_part_error 3128
#define CSN1_PSI15_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI16_message_content_Distribution_part_error 3129
#define CSN1_PSI16_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI1_message_content_PRACH_Control_Parameters 1137
#define CSN1_PSI1_message_content_PRACH_Control_Parameters_SIZE   0
#define CSN1_PSI3_quater_message_content_PSI3_QUATER_COUNT 1186
#define CSN1_PSI3_quater_message_content_PSI3_QUATER_COUNT_SIZE   4
#define CSN1_PSI3_quater_message_content_PSI3_QUATER_INDEX 1185
#define CSN1_PSI3_quater_message_content_PSI3_QUATER_INDEX_SIZE   4
#define CSN1_PSI5_message_content_ENH_Reporting_Parameters 1527
#define CSN1_PSI5_message_content_ENH_Reporting_Parameters_SIZE   0
#define CSN1_PSI5_message_content__700_REPORTING_THRESHOLD 1536
#define CSN1_PSI5_message_content__700_REPORTING_THRESHOLD_SIZE   3
#define CSN1_PSI5_message_content__810_REPORTING_THRESHOLD 1538
#define CSN1_PSI5_message_content__810_REPORTING_THRESHOLD_SIZE   3
#define CSN1_PSI8_message_content_CBCH_Channel_Description 2102
#define CSN1_PSI8_message_content_CBCH_Channel_Description_SIZE   0
#define CSN1_PS_Handover_Command_message_content_PAGE_MODE 2331
#define CSN1_PS_Handover_Command_message_content_PAGE_MODE_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_Extended_SNS 2376
#define CSN1_PS_Handover_Radio_Resources_3_IE_Extended_SNS_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_Pulse_Format 2395
#define CSN1_PS_Handover_Radio_Resources_3_IE_Pulse_Format_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_IE__3G_CCN_ACTIVE 1716
#define CSN1_PS_Handover_Radio_Resources_IE__3G_CCN_ACTIVE_SIZE   1
#define CSN1_Packet_CS_Release_message_content_BEP_PERIOD2 2228
#define CSN1_Packet_CS_Release_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_P0 1905
#define CSN1_Packet_Downlink_Assignment_message_content_P0_SIZE   4
#define CSN1_Packet_MBMS_Announcement_message_content_TMGI 2274
#define CSN1_Packet_MBMS_Announcement_message_content_TMGI_SIZE   0
#define CSN1_Packet_PDCH_Release_message_content_PAGE_MODE 378
#define CSN1_Packet_PDCH_Release_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_TBF_Release_message_content_GLOBAL_TFI 498
#define CSN1_Packet_TBF_Release_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_INDEX 228
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE 227
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CI_DTR 897
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CI_DTR_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_FANR 1591
#define CSN1_Packet_Uplink_Assignment_message_content_FANR_SIZE   0
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BSIC 828
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BSIC_SIZE   6
#define CSN1_Repeated_Iu_Page_info_struct_Page_info_struct 2428
#define CSN1_Repeated_Iu_Page_info_struct_Page_info_struct_SIZE   0
#define CSN1_SI13_PBCCH_Location_struct_PSI1_REPEAT_PERIOD  91
#define CSN1_SI13_PBCCH_Location_struct_PSI1_REPEAT_PERIOD_SIZE   4
#define CSN1_Uplink_TBF_Assignment_2_struct_TFI_Assignment 942
#define CSN1_Uplink_TBF_Assignment_2_struct_TFI_Assignment_SIZE   5
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_ALLOCATION 952
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_ALLOCATION_SIZE   3
#define CSN1_Access_capabilities_struct_Access_capabilities 1289
#define CSN1_Access_capabilities_struct_Access_capabilities_SIZE   0
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN0 569
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN0_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN1 570
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN1_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN2 571
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN2_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN3 572
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN3_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN4 573
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN4_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN5 574
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN5_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN6 575
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN6_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN7 576
#define CSN1_BEP_Measurement_Report_Struct_bis_MEAN_BEP_TN7_SIZE   4
#define CSN1_COMPACT_Information_struct_Cell_Identification 1505
#define CSN1_COMPACT_Information_struct_Cell_Identification_SIZE  64
#define CSN1_COMPACT_NCP2_Property_struct_CELL_BAR_ACCESS_2  97
#define CSN1_COMPACT_NCP2_Property_struct_CELL_BAR_ACCESS_2_SIZE   1
#define CSN1_COMPACT_Neighbour_parameter_set_struct_EXC_ACC 1171
#define CSN1_COMPACT_Neighbour_parameter_set_struct_EXC_ACC_SIZE   1
#define CSN1_Cell_Selection_struct_bis_GPRS_RESELECT_OFFSET 436
#define CSN1_Cell_Selection_struct_bis_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_Channel_Request_Description_IE_RLC_OCTET_COUNT 201
#define CSN1_Channel_Request_Description_IE_RLC_OCTET_COUNT_SIZE  16
#define CSN1_Content_Downlink_Advanced_Receiver_Performance 1332
#define CSN1_Content_Downlink_Advanced_Receiver_Performance_SIZE   2
#define CSN1_DTM_Handover_Command_message_content_PAGE_MODE 2457
#define CSN1_DTM_Handover_Command_message_content_PAGE_MODE_SIZE   2
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_MAX_LAPDm 2486
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_MAX_LAPDm_SIZE   3
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_RLC_RESET 2490
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_RLC_RESET_SIZE   1
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_MAX_LAPDm 2465
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_MAX_LAPDm_SIZE   3
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_RLC_RESET 2469
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_RLC_RESET_SIZE   1
#define CSN1_Downlink_Assignment_struct_TIMESLOT_ALLOCATION 1053
#define CSN1_Downlink_Assignment_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Downlink_TBF_assignment_struct_bis_CONTROL_ACK 983
#define CSN1_Downlink_TBF_assignment_struct_bis_CONTROL_ACK_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_ter_CONTROL_ACK 1058
#define CSN1_Downlink_TBF_assignment_struct_ter_CONTROL_ACK_SIZE   1
#define CSN1_EGPRS_Channel_Quality_Report_Type_2_IE_C_VALUE 1026
#define CSN1_EGPRS_Channel_Quality_Report_Type_2_IE_C_VALUE_SIZE   6
#define CSN1_EGPRS_mode_struct_EGPRS_Channel_Coding_Command 1348
#define CSN1_EGPRS_mode_struct_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_ENH_Reporting_parameters_struct_REPORTING_RATE 1529
#define CSN1_ENH_Reporting_parameters_struct_REPORTING_RATE_SIZE   1
#define CSN1_EPD_A_N_Extension_Info_EARLY_TBF_ESTABLISHMENT 1892
#define CSN1_EPD_A_N_Extension_Info_EARLY_TBF_ESTABLISHMENT_SIZE   1
#define CSN1_Extension_Information_12_48_EMST_NW_Capability 2497
#define CSN1_Extension_Information_12_48_EMST_NW_Capability_SIZE   1
#define CSN1_Extension_Information_12_64_EMST_NW_Capability 2476
#define CSN1_Extension_Information_12_64_EMST_NW_Capability_SIZE   1
#define CSN1_GSM_target_cell_struct_CCN_Support_Description 2303
#define CSN1_GSM_target_cell_struct_CCN_Support_Description_SIZE   0
#define CSN1_MPRACH_Control_Parameters_IE_PERSISTENCE_LEVEL 261
#define CSN1_MPRACH_Control_Parameters_IE_PERSISTENCE_LEVEL_SIZE   4
#define CSN1_MPRACH_description_struct_Frequency_Parameters 2286
#define CSN1_MPRACH_description_struct_Frequency_Parameters_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_struct_PR_MODE_C1 1687
#define CSN1_Multiple_Uplink_Assignment_2_struct_PR_MODE_C1_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_struct_PR_MODE_C2 1689
#define CSN1_Multiple_Uplink_Assignment_2_struct_PR_MODE_C2_SIZE   1
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PBCCH_BLKS 1140
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PBCCH_BLKS_SIZE   2
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PRACH_BLKS 1142
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PRACH_BLKS_SIZE   4
#define CSN1_PDCH_Pairs_Description_IE_UPLINK_PDCH_PAIRS_C1 181
#define CSN1_PDCH_Pairs_Description_IE_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_PDCH_Pairs_Description_IE_UPLINK_PDCH_PAIRS_C2 182
#define CSN1_PDCH_Pairs_Description_IE_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_PSI2_message_content_Reference_Frequency_Lists 1454
#define CSN1_PSI2_message_content_Reference_Frequency_Lists_SIZE   0
#define CSN1_PSI3_message_content_Neighbour_Cell_parameters 1501
#define CSN1_PSI3_message_content_Neighbour_Cell_parameters_SIZE   0
#define CSN1_PSI5_message_content_NC_Measurement_Parameters 1521
#define CSN1_PSI5_message_content_NC_Measurement_Parameters_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Global_TFI 2332
#define CSN1_PS_Handover_Command_message_content_Global_TFI_SIZE   6
#define CSN1_PS_Handover_Radio_Resources_3_IE_PTCCH_CARRIER 2374
#define CSN1_PS_Handover_Radio_Resources_3_IE_PTCCH_CARRIER_SIZE   4
#define CSN1_Packet_Access_Reject_message_content_PAGE_MODE 663
#define CSN1_Packet_Access_Reject_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Downlink_Ack_Nack_message_content_RB_Id 351
#define CSN1_Packet_Downlink_Ack_Nack_message_content_RB_Id_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_PFI 1920
#define CSN1_Packet_Downlink_Assignment_message_content_PFI_SIZE   7
#define CSN1_Packet_SI_Status_message_content_PSCSI_SUPPORT 424
#define CSN1_Packet_SI_Status_message_content_PSCSI_SUPPORT_SIZE   1
#define CSN1_Packet_Serving_Cell_Data_message_content_spare 848
#define CSN1_Packet_Serving_Cell_Data_message_content_spare_SIZE   4
#define CSN1_Packet_Uplink_Ack_Nack_message_content_TBF_EST 884
#define CSN1_Packet_Uplink_Ack_Nack_message_content_TBF_EST_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_RB_Id 1560
#define CSN1_Packet_Uplink_Assignment_message_content_RB_Id_SIZE   5
#define CSN1_Page_info_struct_Paging_Record_Type_Identifier  89
#define CSN1_Page_info_struct_Paging_Record_Type_Identifier_SIZE   2
#define CSN1_REMOVED_3GCELL_Description_struct__3GCELL_DIFF 1106
#define CSN1_REMOVED_3GCELL_Description_struct__3GCELL_DIFF_SIZE   0
#define CSN1_Serving_Cell_params_struct_MULTIBAND_REPORTING 1494
#define CSN1_Serving_Cell_params_struct_MULTIBAND_REPORTING_SIZE   2
#define CSN1_Single_Block_Allocation_struct_TIMESLOT_NUMBER 1552
#define CSN1_Single_Block_Allocation_struct_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Unknown_SI_Message_List_struct_SI_MESSAGE_TYPE 422
#define CSN1_Unknown_SI_Message_List_struct_SI_MESSAGE_TYPE_SIZE   8
#define CSN1_Uplink_Assignment_struct_Uplink_TBF_Assignment 1241
#define CSN1_Uplink_Assignment_struct_Uplink_TBF_Assignment_SIZE   0
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_GRANULARITY 945
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_GRANULARITY_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Window_Size 936
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_Add_Frequency_list_struct_Cell_selection_params 1364
#define CSN1_Add_Frequency_list_struct_Cell_selection_params_SIZE   0
#define CSN1_Additional_PFCs_struct_UP_UPLINK_TFI_ASSIGNMENT 122
#define CSN1_Additional_PFCs_struct_UP_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_CCCH_Access_Information_struct_BCCH_CHANGE_MARK 2114
#define CSN1_CCCH_Access_Information_struct_BCCH_CHANGE_MARK_SIZE   3
#define CSN1_CCCH_Access_Information_struct_SI13_CHANGE_MARK 2115
#define CSN1_CCCH_Access_Information_struct_SI13_CHANGE_MARK_SIZE   2
#define CSN1_COMPACT_Cell_Selection_struct_CELL_BAR_ACCESS_2 440
#define CSN1_COMPACT_Cell_Selection_struct_CELL_BAR_ACCESS_2_SIZE   1
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_PENALTY_TIME 446
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_Cell_Selection_struct_bis_GPRS_MS_TXPWR_MAX_CCH 433
#define CSN1_Cell_Selection_struct_bis_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Cell_Selection_struct_bis_GPRS_RXLEV_ACCESS_MIN 432
#define CSN1_Cell_Selection_struct_bis_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_Cell_Selection_struct_bis_GPRS_TEMPORARY_OFFSET 434
#define CSN1_Cell_Selection_struct_bis_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_DLMC_UL_Carrier_Info_struct_Uplink_RLC_Entity_2 1070
#define CSN1_DLMC_UL_Carrier_Info_struct_Uplink_RLC_Entity_2_SIZE   0
#define CSN1_DLMC_UL_Carrier_Info_struct_Uplink_RLC_Entity_3 1071
#define CSN1_DLMC_UL_Carrier_Info_struct_Uplink_RLC_Entity_3_SIZE   0
#define CSN1_DTM_Handover_Command_message_content_Global_TFI 2458
#define CSN1_DTM_Handover_Command_message_content_Global_TFI_SIZE   6
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_EGPRS_mode 2491
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_EGPRS_mode_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_EGPRS_mode 2470
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_EGPRS_mode_SIZE   0
#define CSN1_Direct_encoding_1_struct_GPRS_Mobile_Allocation 1255
#define CSN1_Direct_encoding_1_struct_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_TFI_Assignment 361
#define CSN1_Downlink_TBF_assignment_2_struct_TFI_Assignment_SIZE   5
#define CSN1_Dual_Carrier_Indirect_encoding_struct_MA_NUMBER 1275
#define CSN1_Dual_Carrier_Indirect_encoding_struct_MA_NUMBER_SIZE   4
#define CSN1_EGPRS_Ack_Nack_Description_struct_END_OF_WINDOW 161
#define CSN1_EGPRS_Ack_Nack_Description_struct_END_OF_WINDOW_SIZE   1
#define CSN1_EGPRS_mode_struct_LINK_QUALITY_MEASUREMENT_MODE 1352
#define CSN1_EGPRS_mode_struct_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_ETWS_Primary_Notification_struct_Segment_Number 2453
#define CSN1_ETWS_Primary_Notification_struct_Segment_Number_SIZE   4
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_N_E_UTRAN   9
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_N_E_UTRAN_SIZE   2
#define CSN1_E_UTRAN_Measurement_Report_struct_CELL_IDENTITY  81
#define CSN1_E_UTRAN_Measurement_Report_struct_CELL_IDENTITY_SIZE   9
#define CSN1_Extension_Information_12_48_Uplink_RLC_Entity_2 2495
#define CSN1_Extension_Information_12_48_Uplink_RLC_Entity_2_SIZE   0
#define CSN1_Extension_Information_12_48_Uplink_RLC_Entity_3 2496
#define CSN1_Extension_Information_12_48_Uplink_RLC_Entity_3_SIZE   0
#define CSN1_Extension_Information_12_64_Uplink_RLC_Entity_2 2474
#define CSN1_Extension_Information_12_64_Uplink_RLC_Entity_2_SIZE   0
#define CSN1_Extension_Information_12_64_Uplink_RLC_Entity_3 2475
#define CSN1_Extension_Information_12_64_Uplink_RLC_Entity_3_SIZE   0
#define CSN1_GSM_target_cell_struct__700_REPORTING_THRESHOLD 2310
#define CSN1_GSM_target_cell_struct__700_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GSM_target_cell_struct__810_REPORTING_THRESHOLD 2312
#define CSN1_GSM_target_cell_struct__810_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Global_Power_Control_Parameters_IE_PC_MEAS_CHAN 213
#define CSN1_Global_Power_Control_Parameters_IE_PC_MEAS_CHAN_SIZE   1
#define CSN1_MBMS_MS_ID_Assignment_message_content_PAGE_MODE 532
#define CSN1_MBMS_MS_ID_Assignment_message_content_PAGE_MODE_SIZE   2
#define CSN1_MPRACH_description_IE_MPRACH_Control_Parameters 2449
#define CSN1_MPRACH_description_IE_MPRACH_Control_Parameters_SIZE   0
#define CSN1_Multi_Block_Allocation_struct_TBF_Starting_Time 928
#define CSN1_Multi_Block_Allocation_struct_TBF_Starting_Time_SIZE   0
#define CSN1_NC_Measurement_Report_struct_RXLEV_SERVING_CELL 795
#define CSN1_NC_Measurement_Report_struct_RXLEV_SERVING_CELL_SIZE   6
#define CSN1_PCCCH_Description_struct_Hopping_PCCCH_carriers 1466
#define CSN1_PCCCH_Description_struct_Hopping_PCCCH_carriers_SIZE   0
#define CSN1_PSI16_message_content_GRA_AND_CELL_UPDATE_TIMER 496
#define CSN1_PSI16_message_content_GRA_AND_CELL_UPDATE_TIMER_SIZE   3
#define CSN1_PSI5_message_content_EXT_Measurement_Parameters 1526
#define CSN1_PSI5_message_content_EXT_Measurement_Parameters_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE__3G_CCN_ACTIVE 2343
#define CSN1_PS_Handover_Radio_Resources_2_IE__3G_CCN_ACTIVE_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE__3G_CCN_ACTIVE 2364
#define CSN1_PS_Handover_Radio_Resources_3_IE__3G_CCN_ACTIVE_SIZE   1
#define CSN1_Packet_Cell_Change_Failure_message_content_BSIC 673
#define CSN1_Packet_Cell_Change_Failure_message_content_BSIC_SIZE   6
#define CSN1_Packet_DBPSCH_Assignment_message_content_G_RNTI 734
#define CSN1_Packet_DBPSCH_Assignment_message_content_G_RNTI_SIZE  32
#define CSN1_Packet_Downlink_Assignment_message_content_UFPS 1958
#define CSN1_Packet_Downlink_Assignment_message_content_UFPS_SIZE   0
#define CSN1_Packet_Neighbour_Cell_Data_message_content_BSIC 844
#define CSN1_Packet_Neighbour_Cell_Data_message_content_BSIC_SIZE   6
#define CSN1_Packet_Paging_Request_message_content_PAGE_MODE 2415
#define CSN1_Packet_Paging_Request_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Resource_Request_message_content_C_VALUE 2074
#define CSN1_Packet_Resource_Request_message_content_C_VALUE_SIZE   6
#define CSN1_Packet_Resource_Request_message_content_HFN_LSB 2091
#define CSN1_Packet_Resource_Request_message_content_HFN_LSB_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_TSH 2195
#define CSN1_Packet_Timeslot_Reconfigure_message_content_TSH_SIZE   2
#define CSN1_Packet_Uplink_Ack_Nack_message_content_DTR_Blks 894
#define CSN1_Packet_Uplink_Ack_Nack_message_content_DTR_Blks_SIZE   2
#define CSN1_Single_Uplink_Assignment_2_IE_NPM_Transfer_Time 1880
#define CSN1_Single_Uplink_Assignment_2_IE_NPM_Transfer_Time_SIZE   5
#define CSN1_p3G_Priority_Parameters_IE_DEFAULT_THRESH_UTRAN 1995
#define CSN1_p3G_Priority_Parameters_IE_DEFAULT_THRESH_UTRAN_SIZE   5
#define CSN1_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER 157
#define CSN1_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER_SIZE   7
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_FREQUENCY_DIFF 1116
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_Additional_PSI_Messages_struct_PSI3ter_BROADCAST 1483
#define CSN1_Additional_PSI_Messages_struct_PSI3ter_BROADCAST_SIZE   1
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN0 550
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN0_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN1 552
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN1_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN2 554
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN2_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN3 556
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN3_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN4 558
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN4_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN5 560
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN5_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN6 562
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN6_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN7 564
#define CSN1_BEP_Measurement_Report_Struct_GMSK_MEAN_BEP__TN7_SIZE   4
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_TFI_Assignment 1799
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_TFI_Assignment_SIZE   5
#define CSN1_CCCH_Access_Information_struct_GPRS_Cell_Options 2120
#define CSN1_CCCH_Access_Information_struct_GPRS_Cell_Options_SIZE   0
#define CSN1_CCN_Measurement_Report_struct_RXLEV_SERVING_CELL 710
#define CSN1_CCN_Measurement_Report_struct_RXLEV_SERVING_CELL_SIZE   6
#define CSN1_COMPACT_Control_Info_struct_Large_Cell_Operation 1473
#define CSN1_COMPACT_Control_Info_struct_Large_Cell_Operation_SIZE   1
#define CSN1_COMPACT_NCP2_Repeat_struct_NR_OF_REMAINING_CELLS 466
#define CSN1_COMPACT_NCP2_Repeat_struct_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_Carrier_Specific_Info_struct_TIMESLOT_ALLOCATION 1745
#define CSN1_Carrier_Specific_Info_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Content_Modulation_based_multislot_class_support 1325
#define CSN1_Content_Modulation_based_multislot_class_support_SIZE   1
#define CSN1_DLMC_BEP_Measurements_Struct_REPORTED_MODULATION 650
#define CSN1_DLMC_BEP_Measurements_Struct_REPORTED_MODULATION_SIZE   2
#define CSN1_DLMC_UL_Carrier_Info_struct_Dynamic_Allocation_3 1062
#define CSN1_DLMC_UL_Carrier_Info_struct_Dynamic_Allocation_3_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_bis_CONTROL_ACK 515
#define CSN1_Downlink_TBF_assignment_2_struct_bis_CONTROL_ACK_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_EGPRS_Window_Size 1403
#define CSN1_Downlink_TBF_assignment_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_ENH_Measurement_parameters_struct_REPORTING_RATE 1094
#define CSN1_ENH_Measurement_parameters_struct_REPORTING_RATE_SIZE   1
#define CSN1_EXT_Measurement_Report_struct_EXT_REPORTING_TYPE 780
#define CSN1_EXT_Measurement_Report_struct_EXT_REPORTING_TYPE_SIZE   2
#define CSN1_E_UTRAN_Target_Cell_struct_Measurement_Bandwidth 699
#define CSN1_E_UTRAN_Target_Cell_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_Extended_Channel_Request_Description_IE_RLC_MODE 207
#define CSN1_Extended_Channel_Request_Description_IE_RLC_MODE_SIZE   1
#define CSN1_GSM_target_cell_struct_NC_Measurement_Parameters 2298
#define CSN1_GSM_target_cell_struct_NC_Measurement_Parameters_SIZE   0
#define CSN1_Iu_Mode_Cell_Selection_struct_CELL_BAR_QUALIFY_3 323
#define CSN1_Iu_Mode_Cell_Selection_struct_CELL_BAR_QUALIFY_3_SIZE   2
#define CSN1_MBMS_MS_ID_Assignment_message_content_Global_TFI 533
#define CSN1_MBMS_MS_ID_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_MBMS_bearer_description_struct_EGPRS_Window_Size 1707
#define CSN1_MBMS_bearer_description_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_MBMS_bearer_description_struct_NPM_Transfer_Time 1709
#define CSN1_MBMS_bearer_description_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_MS_Radio_Access_Capability_2_IE_MS_RA_capability 2071
#define CSN1_MS_Radio_Access_Capability_2_IE_MS_RA_capability_SIZE   0
#define CSN1_Multislot_capability_struct_ECSD_multislot_class 1309
#define CSN1_Multislot_capability_struct_ECSD_multislot_class_SIZE   5
#define CSN1_Multislot_capability_struct_GPRS_multislot_class 1305
#define CSN1_Multislot_capability_struct_GPRS_multislot_class_SIZE   5
#define CSN1_NC_Frequency_list_struct_List_of_added_Frequency 1361
#define CSN1_NC_Frequency_list_struct_List_of_added_Frequency_SIZE   0
#define CSN1_Neighbour_parameter_set_struct_GPRS_PENALTY_TIME 1164
#define CSN1_Neighbour_parameter_set_struct_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PAG_BLKS_RES 1141
#define CSN1_PCCCH_Organization_Parameters_IE_BS_PAG_BLKS_RES_SIZE   4
#define CSN1_PDCH_Pairs_Description_IE_DOWNLINK_PDCH_PAIRS_C1 179
#define CSN1_PDCH_Pairs_Description_IE_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_PDCH_Pairs_Description_IE_DOWNLINK_PDCH_PAIRS_C2 180
#define CSN1_PDCH_Pairs_Description_IE_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_PSI2_message_content_COMPACT_Control_Information 1472
#define CSN1_PSI2_message_content_COMPACT_Control_Information_SIZE   0
#define CSN1_PSI3_bis_message_content_CCN_Support_Description 1180
#define CSN1_PSI3_bis_message_content_CCN_Support_Description_SIZE   0
#define CSN1_PSI3_bis_message_content_Distribution_part_error 3163
#define CSN1_PSI3_bis_message_content_Distribution_part_error_SIZE   0
#define CSN1_PSI3_ter_message_content_Distribution_part_error 3153
#define CSN1_PSI3_ter_message_content_Distribution_part_error_SIZE   0
#define CSN1_PS_Handover_Command_message_content_CONTAINER_ID 2333
#define CSN1_PS_Handover_Command_message_content_CONTAINER_ID_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_UPLINK_RLC_MODE 2390
#define CSN1_PS_Handover_Radio_Resources_3_IE_UPLINK_RLC_MODE_SIZE   1
#define CSN1_Packet_CS_Command_message_content_CONTAINER_DATA 527
#define CSN1_Packet_CS_Command_message_content_CONTAINER_DATA_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Message_escape 3221
#define CSN1_Packet_CS_Release_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Cell_Change_Continue_message_content_BSIC 299
#define CSN1_Packet_Cell_Change_Continue_message_content_BSIC_SIZE   6
#define CSN1_Packet_Cell_Change_Failure_message_content_ARFCN 672
#define CSN1_Packet_Cell_Change_Failure_message_content_ARFCN_SIZE  10
#define CSN1_Packet_Cell_Change_Failure_message_content_CAUSE 674
#define CSN1_Packet_Cell_Change_Failure_message_content_CAUSE_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_P0_C1 1946
#define CSN1_Packet_Downlink_Assignment_message_content_P0_C1_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_P0_C2 1948
#define CSN1_Packet_Downlink_Assignment_message_content_P0_C2_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_RB_Id 1916
#define CSN1_Packet_Downlink_Assignment_message_content_RB_Id_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_type0 1899
#define CSN1_Packet_Downlink_Assignment_message_content_type0_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_type1 1931
#define CSN1_Packet_Downlink_Assignment_message_content_type1_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_PMO_IND 1985
#define CSN1_Packet_Measurement_Order_message_content_PMO_IND_SIZE   1
#define CSN1_Packet_Neighbour_Cell_Data_message_content_ARFCN 843
#define CSN1_Packet_Neighbour_Cell_Data_message_content_ARFCN_SIZE  10
#define CSN1_Packet_Neighbour_Cell_Data_message_content_spare 841
#define CSN1_Packet_Neighbour_Cell_Data_message_content_spare_SIZE   1
#define CSN1_Packet_Polling_Request_message_content_PAGE_MODE 380
#define CSN1_Packet_Polling_Request_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Queueing_Notification_message_content_TQI 399
#define CSN1_Packet_Queueing_Notification_message_content_TQI_SIZE  16
#define CSN1_Packet_Resource_Request_message_content_SIGN_VAR 2075
#define CSN1_Packet_Resource_Request_message_content_SIGN_VAR_SIZE   6
#define CSN1_Packet_Serving_Cell_SI_message_content_PAGE_MODE 426
#define CSN1_Packet_Serving_Cell_SI_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UFPS 2204
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UFPS_SIZE   0
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PAGE_MODE 875
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Uplink_Ack_Nack_message_content_RESEGMENT 879
#define CSN1_Packet_Uplink_Ack_Nack_message_content_RESEGMENT_SIZE   1
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap 580
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap_SIZE   0
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_TFI_Assignment 1820
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_TFI_Assignment_SIZE   5
#define CSN1_Serving_Cell_params_struct_GPRS_MS_TXPWR_MAX_CCH 1492
#define CSN1_Serving_Cell_params_struct_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Serving_Cell_params_struct_GPRS_RXLEV_ACCESS_MIN 1491
#define CSN1_Serving_Cell_params_struct_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_Single_Block_Allocation_struct_TBF_Starting_Time 1557
#define CSN1_Single_Block_Allocation_struct_TBF_Starting_Time_SIZE   0
#define CSN1_Single_Downlink_Assignment_2_IE_EVENT_BASED_FANR 1838
#define CSN1_Single_Downlink_Assignment_2_IE_EVENT_BASED_FANR_SIZE   1
#define CSN1_Single_Uplink_Assignment_2_IE_Uplink_EGPRS_Level 1856
#define CSN1_Single_Uplink_Assignment_2_IE_Uplink_EGPRS_Level_SIZE   2
#define CSN1_Uplink_Assignment_struct_Uplink_Control_Timeslot 1236
#define CSN1_Uplink_Assignment_struct_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Uplink_TBF_Assignment_2_struct_EGPRS_Window_Size 944
#define CSN1_Uplink_TBF_Assignment_2_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_Uplink_TBF_Assignment_2_struct_NPM_Transfer_Time 946
#define CSN1_Uplink_TBF_Assignment_2_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_ALLOCATION_C1 950
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_ALLOCATION_C1_SIZE   3
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_ALLOCATION_C2 951
#define CSN1_Uplink_TBF_Assignment_2_struct_USF_ALLOCATION_C2_SIZE   3
#define CSN1__3G_Measurement_Report_struct_REPORTING_QUANTITY 808
#define CSN1__3G_Measurement_Report_struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_START_FREQUENCY 1111
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_START_FREQUENCY_SIZE  10
#define CSN1_Additional_PFCs_struct_DN_DOWNLINK_TFI_ASSIGNMENT  76
#define CSN1_Additional_PFCs_struct_DN_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN0 551
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN0_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN1 553
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN1_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN2 555
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN2_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN3 557
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN3_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN4 559
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN4_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN5 561
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN5_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN6 563
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN6_SIZE   4
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN7 565
#define CSN1_BEP_Measurement_Report_Struct__8PSK_MEAN_BEP__TN7_SIZE   4
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_GRANULARITY 1805
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_USF_GRANULARITY_SIZE   1
#define CSN1_COMPACT_Control_Info_struct_Number_of_Idle_Blocks 1474
#define CSN1_COMPACT_Control_Info_struct_Number_of_Idle_Blocks_SIZE   0
#define CSN1_COMPACT_reduced_MA_IE_Length_of_Reduced_MA_bitmap 251
#define CSN1_COMPACT_reduced_MA_IE_Length_of_Reduced_MA_bitmap_SIZE   7
#define CSN1_Carrier_Specific_Info_struct_Secondary_DL_TSC_Set 1758
#define CSN1_Carrier_Specific_Info_struct_Secondary_DL_TSC_Set_SIZE   1
#define CSN1_Cell_Selection_struct_bis_SAME_RA_AS_SERVING_CELL 431
#define CSN1_Cell_Selection_struct_bis_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_DLMC_Channel_Quality_Report_DLMC_BEP_MEASUREMENTS 649
#define CSN1_DLMC_Channel_Quality_Report_DLMC_BEP_MEASUREMENTS_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_EVENT_BASED_FANR 364
#define CSN1_Downlink_TBF_assignment_2_struct_EVENT_BASED_FANR_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_bis_TFI_Assignment 982
#define CSN1_Downlink_TBF_assignment_struct_bis_TFI_Assignment_SIZE   5
#define CSN1_Downlink_TBF_assignment_struct_ter_TFI_Assignment 1057
#define CSN1_Downlink_TBF_assignment_struct_ter_TFI_Assignment_SIZE   5
#define CSN1_Dynamic_Allocation_2_struct_UPLINK_TFI_ASSIGNMENT 113
#define CSN1_Dynamic_Allocation_2_struct_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_p3G_BA_USED   8
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_p3G_BA_USED_SIZE   1
#define CSN1_Extension_Information_12_48_Downlink_RLC_Entity_2 2493
#define CSN1_Extension_Information_12_48_Downlink_RLC_Entity_2_SIZE   0
#define CSN1_Extension_Information_12_48_Downlink_RLC_Entity_3 2494
#define CSN1_Extension_Information_12_48_Downlink_RLC_Entity_3_SIZE   0
#define CSN1_Extension_Information_12_64_Downlink_RLC_Entity_2 2472
#define CSN1_Extension_Information_12_64_Downlink_RLC_Entity_2_SIZE   0
#define CSN1_Extension_Information_12_64_Downlink_RLC_Entity_3 2473
#define CSN1_Extension_Information_12_64_Downlink_RLC_Entity_3_SIZE   0
#define CSN1_Extension_Information_DTM_ENHANCEMENTS_CAPABILITY 1048
#define CSN1_Extension_Information_DTM_ENHANCEMENTS_CAPABILITY_SIZE   1
#define CSN1_GPRS_REP_PRIORITY_Description_struct_Number_Cells  15
#define CSN1_GPRS_REP_PRIORITY_Description_struct_Number_Cells_SIZE   7
#define CSN1_GPRS_REP_PRIORITY_Description_struct_REP_PRIORITY  16
#define CSN1_GPRS_REP_PRIORITY_Description_struct_REP_PRIORITY_SIZE   1
#define CSN1_GSM_Priority_Parameters_IE_THRESH_Priority_Search 1989
#define CSN1_GSM_Priority_Parameters_IE_THRESH_Priority_Search_SIZE   4
#define CSN1_GSM_target_cell_struct_ENH_Measurement_parameters 2300
#define CSN1_GSM_target_cell_struct_ENH_Measurement_parameters_SIZE   0
#define CSN1_Gen_Cell_Sel_struct_GPRS_CELL_RESELECT_HYSTERESIS 1496
#define CSN1_Gen_Cell_Sel_struct_GPRS_CELL_RESELECT_HYSTERESIS_SIZE   3
#define CSN1_Hopping_PCCCH_Carriers_struct_TIMESLOT_ALLOCATION 1468
#define CSN1_Hopping_PCCCH_Carriers_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_HCS_params 459
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_HCS_params_SIZE   8
#define CSN1_MBMS_Assignment_Distribution_message_content_TMGI 2267
#define CSN1_MBMS_Assignment_Distribution_message_content_TMGI_SIZE   0
#define CSN1_MBMS_MS_ID_Assignment_message_content_TLLI_G_RNTI 534
#define CSN1_MBMS_MS_ID_Assignment_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_MBMS_Session_Parameters_List_IE_EGPRS_Window_Size 2443
#define CSN1_MBMS_Session_Parameters_List_IE_EGPRS_Window_Size_SIZE   5
#define CSN1_MBMS_Session_Parameters_List_IE_NPM_Transfer_Time 2444
#define CSN1_MBMS_Session_Parameters_List_IE_NPM_Transfer_Time_SIZE   5
#define CSN1_Multiple_Uplink_Assignment_2_struct_RTTI_USF_MODE 1698
#define CSN1_Multiple_Uplink_Assignment_2_struct_RTTI_USF_MODE_SIZE   1
#define CSN1_Multislot_capability_struct_EGPRS_multislot_class 1310
#define CSN1_Multislot_capability_struct_EGPRS_multislot_class_SIZE   5
#define CSN1_Multislot_capability_struct_HSCSD_multislot_class 1304
#define CSN1_Multislot_capability_struct_HSCSD_multislot_class_SIZE   5
#define CSN1_NC_Measurement_Report_struct_bis_PSI3_CHANGE_MARK 819
#define CSN1_NC_Measurement_Report_struct_bis_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_SACCH 751
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_SACCH_SIZE   2
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_SDCCH 756
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_SDCCH_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_2_IE_Extension_Length 2353
#define CSN1_PS_Handover_Radio_Resources_2_IE_Extension_Length_SIZE   6
#define CSN1_PS_Handover_Radio_Resources_3_IE_EVENT_BASED_FANR 2380
#define CSN1_PS_Handover_Radio_Resources_3_IE_EVENT_BASED_FANR_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_IE_Handover_Reference 1710
#define CSN1_PS_Handover_Radio_Resources_IE_Handover_Reference_SIZE   8
#define CSN1_Packet_CS_Release_message_content_Assignment_Info 2243
#define CSN1_Packet_CS_Release_message_content_Assignment_Info_SIZE   3
#define CSN1_Packet_CS_Release_message_content_Primary_TSC_Set 2225
#define CSN1_Packet_CS_Release_message_content_Primary_TSC_Set_SIZE   1
#define CSN1_Packet_Cell_Change_Continue_message_content_ARFCN 298
#define CSN1_Packet_Cell_Change_Continue_message_content_ARFCN_SIZE  10
#define CSN1_Packet_Measurement_Report_message_content_BA_USED 801
#define CSN1_Packet_Measurement_Report_message_content_BA_USED_SIZE   1
#define CSN1_Packet_PRACH_Parameters_message_content_PAGE_MODE 395
#define CSN1_Packet_PRACH_Parameters_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Polling_Request_message_content_Global_TFI 381
#define CSN1_Packet_Polling_Request_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_SI_Status_message_content_BCCH_CHANGE_MARK 413
#define CSN1_Packet_SI_Status_message_content_BCCH_CHANGE_MARK_SIZE   3
#define CSN1_Packet_TBF_Release_message_content_UPLINK_RELEASE 499
#define CSN1_Packet_TBF_Release_message_content_UPLINK_RELEASE_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI 876
#define CSN1_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI_SIZE   5
#define CSN1_Packet_Uplink_Assignment_message_content_RLC_MODE 1562
#define CSN1_Packet_Uplink_Assignment_message_content_RLC_MODE_SIZE   1
#define CSN1_Physical_information_message_content_MESSAGE_TYPE 519
#define CSN1_Physical_information_message_content_MESSAGE_TYPE_SIZE   6
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_GRANULARITY 1826
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_USF_GRANULARITY_SIZE   1
#define CSN1_Reference_Frequency_struct_Length_of_RFL_contents 1456
#define CSN1_Reference_Frequency_struct_Length_of_RFL_contents_SIZE   4
#define CSN1_Single_Downlink_Assignment_2_IE_NPM_Transfer_Time 1851
#define CSN1_Single_Downlink_Assignment_2_IE_NPM_Transfer_Time_SIZE   5
#define CSN1_UTRAN_Frequency_List_Description_struct_FDD_ARFCN 479
#define CSN1_UTRAN_Frequency_List_Description_struct_FDD_ARFCN_SIZE  14
#define CSN1_UTRAN_Frequency_List_Description_struct_TDD_ARFCN 480
#define CSN1_UTRAN_Frequency_List_Description_struct_TDD_ARFCN_SIZE  14
#define CSN1_Uplink_Assignment_2_struct_PDCH_Pairs_Description 1637
#define CSN1_Uplink_Assignment_2_struct_PDCH_Pairs_Description_SIZE   0
#define CSN1__3G_Measurement_Report_struct__3G_CELL_LIST_INDEX 807
#define CSN1__3G_Measurement_Report_struct__3G_CELL_LIST_INDEX_SIZE   7
#define CSN1_p3G_Priority_Parameters_IE_DEFAULT_UTRAN_PRIORITY 1994
#define CSN1_p3G_Priority_Parameters_IE_DEFAULT_UTRAN_PRIORITY_SIZE   3
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_FREQ_DIFF_LENGTH 1115
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_Additional_PSI_Messages_struct_NON_GSM_INFORMATION 1481
#define CSN1_Additional_PSI_Messages_struct_NON_GSM_INFORMATION_SIZE   2
#define CSN1_CCCH_Access_Information_struct_LB_MS_TXPWR_MAX_CCH 2125
#define CSN1_CCCH_Access_Information_struct_LB_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_CCCH_Access_Information_struct_PRIORITY_ACCESS_THR 2118
#define CSN1_CCCH_Access_Information_struct_PRIORITY_ACCESS_THR_SIZE   3
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_RESELECT_OFFSET 447
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_DLMC_UL_Carrier_Info_struct_EMSR_Additional_PFCs_1 1072
#define CSN1_DLMC_UL_Carrier_Info_struct_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_DLMC_UL_Carrier_Info_struct_EMSR_Additional_PFCs_2 1073
#define CSN1_DLMC_UL_Carrier_Info_struct_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_DLMC_UL_Carrier_Info_struct_EMSR_Additional_PFCs_3 1074
#define CSN1_DLMC_UL_Carrier_Info_struct_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_DLMC_UL_Carrier_Info_struct_UPLINK_PDCH_PAIRS_DLMC 1061
#define CSN1_DLMC_UL_Carrier_Info_struct_UPLINK_PDCH_PAIRS_DLMC_SIZE   8
#define CSN1_Downlink_Assignment_struct_Downlink_TBF_assignment 1054
#define CSN1_Downlink_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_RLC_MODE 611
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_RLC_MODE_SIZE   1
#define CSN1_Downlink_TBF_assignment_2_struct_NPM_Transfer_Time 363
#define CSN1_Downlink_TBF_assignment_2_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE_GMSK_CV_BEP 168
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE_GMSK_CV_BEP_SIZE   3
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_PFI 1886
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_PFI_SIZE   7
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_ext 1887
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_ext_SIZE   0
#define CSN1_ENH_Measurement_parameters_struct_PSI3_CHANGE_MARK 1091
#define CSN1_ENH_Measurement_parameters_struct_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_ETWS_Primary_Notification_struct_Length_Of_Segment 2455
#define CSN1_ETWS_Primary_Notification_struct_Length_Of_Segment_SIZE   7
#define CSN1_E_UTRAN_CSG_Description_IE_E_UTRAN_FREQUENCY_INDEX 2038
#define CSN1_E_UTRAN_CSG_Description_IE_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_Extension_Information_12_64_EMSR_Additional_PFCs_1 2481
#define CSN1_Extension_Information_12_64_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_Extension_Information_12_64_EMSR_Additional_PFCs_2 2482
#define CSN1_Extension_Information_12_64_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_Extension_Information_12_64_EMSR_Additional_PFCs_3 2483
#define CSN1_Extension_Information_12_64_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN0 171
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN0_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN1 172
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN1_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN2 173
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN2_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN3 174
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN3_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN4 175
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN4_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN5 176
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN5_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN6 177
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN6_SIZE   4
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN7 178
#define CSN1_Interference_Measurement_Report_Struct_I_LEVEL_TN7_SIZE   4
#define CSN1_MBMS_Frequency_List_struct_Frequency_List_contents 995
#define CSN1_MBMS_Frequency_List_struct_Frequency_List_contents_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_IE_Uplink_EGPRS_Level 1832
#define CSN1_Multiple_Uplink_Assignment_2_IE_Uplink_EGPRS_Level_SIZE   2
#define CSN1_NC_Measurement_Parameters_struct_NC_FREQUENCY_LIST 1358
#define CSN1_NC_Measurement_Parameters_struct_NC_FREQUENCY_LIST_SIZE   0
#define CSN1_NC_Measurement_Parameters_struct_NC_NON_DRX_PERIOD 1355
#define CSN1_NC_Measurement_Parameters_struct_NC_NON_DRX_PERIOD_SIZE   3
#define CSN1_NC_Measurement_Report_struct_bis_Serving_cell_data 823
#define CSN1_NC_Measurement_Report_struct_bis_Serving_cell_data_SIZE   0
#define CSN1_Neighbour_Cell_params_2_struct_CELL_PARAMS_POINTER 1154
#define CSN1_Neighbour_Cell_params_2_struct_CELL_PARAMS_POINTER_SIZE   2
#define CSN1_Neighbour_Cell_params_struct_Cell_Selection_Params 856
#define CSN1_Neighbour_Cell_params_struct_Cell_Selection_Params_SIZE   0
#define CSN1_Neighbour_Cell_params_struct_Cell_selection_params 852
#define CSN1_Neighbour_Cell_params_struct_Cell_selection_params_SIZE   0
#define CSN1_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS 853
#define CSN1_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_Neighbour_parameter_set_struct_SI13_PBCCH_LOCATION 1162
#define CSN1_Neighbour_parameter_set_struct_SI13_PBCCH_LOCATION_SIZE   0
#define CSN1_Neighbouring_Cell_Report_struct_NCELL_LIST_INDEX_N 767
#define CSN1_Neighbouring_Cell_Report_struct_NCELL_LIST_INDEX_N_SIZE   7
#define CSN1_Neighbouring_Cell_Report_struct_RXLEV_SERVING_CELL 764
#define CSN1_Neighbouring_Cell_Report_struct_RXLEV_SERVING_CELL_SIZE   6
#define CSN1_PDCH_Pairs_Description_struct_UPLINK_PDCH_PAIRS_C1 1640
#define CSN1_PDCH_Pairs_Description_struct_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_PDCH_Pairs_Description_struct_UPLINK_PDCH_PAIRS_C2 1641
#define CSN1_PDCH_Pairs_Description_struct_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_PSI1_message_content_PCCCH_Organization_Parameters 1138
#define CSN1_PSI1_message_content_PCCCH_Organization_Parameters_SIZE  11
#define CSN1_PSI3_bis_message_content_Neighbour_cell_parameters 1152
#define CSN1_PSI3_bis_message_content_Neighbour_cell_parameters_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Message_escape 3236
#define CSN1_PS_Handover_Command_message_content_Message_escape_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_DOWNLINK_RLC_MODE 2366
#define CSN1_PS_Handover_Radio_Resources_3_IE_DOWNLINK_RLC_MODE_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_PFI_of_uplink_TBF 2389
#define CSN1_PS_Handover_Radio_Resources_3_IE_PFI_of_uplink_TBF_SIZE   7
#define CSN1_Packet_CS_Command_message_content_CONTAINER_LENGTH 526
#define CSN1_Packet_CS_Command_message_content_CONTAINER_LENGTH_SIZE   8
#define CSN1_Packet_Cell_Change_Order_message_content_PAGE_MODE 2291
#define CSN1_Packet_Cell_Change_Order_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_DBPSCH_Assignment_message_content_PAGE_MODE 730
#define CSN1_Packet_DBPSCH_Assignment_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Downlink_Assignment_message_content_HFN_LSB 1919
#define CSN1_Packet_Downlink_Assignment_message_content_HFN_LSB_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_PR_MODE 1906
#define CSN1_Packet_Downlink_Assignment_message_content_PR_MODE_SIZE   1
#define CSN1_Packet_MBMS_Announcement_message_content_PAGE_MODE 2273
#define CSN1_Packet_MBMS_Announcement_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Measurement_Order_message_content_PAGE_MODE 1964
#define CSN1_Packet_Measurement_Order_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Measurement_Order_message_content_PMO_COUNT 1968
#define CSN1_Packet_Measurement_Order_message_content_PMO_COUNT_SIZE   3
#define CSN1_Packet_Measurement_Order_message_content_PMO_INDEX 1967
#define CSN1_Packet_Measurement_Order_message_content_PMO_INDEX_SIZE   3
#define CSN1_Packet_Measurement_Report_message_content_PMO_USED 804
#define CSN1_Packet_Measurement_Report_message_content_PMO_USED_SIZE   1
#define CSN1_Packet_Mobile_TBF_Status_message_content_TBF_CAUSE 372
#define CSN1_Packet_Mobile_TBF_Status_message_content_TBF_CAUSE_SIZE   3
#define CSN1_Packet_Polling_Request_message_content_TLLI_G_RNTI 382
#define CSN1_Packet_Polling_Request_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Polling_Request_message_content_TYPE_OF_ACK 384
#define CSN1_Packet_Polling_Request_message_content_TYPE_OF_ACK_SIZE   1
#define CSN1_Packet_Resource_Request_message_content_Global_TFI 2068
#define CSN1_Packet_Resource_Request_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Serving_Cell_Data_message_content_CONTAINER 850
#define CSN1_Packet_Serving_Cell_Data_message_content_CONTAINER_SIZE   0
#define CSN1_Packet_Serving_Cell_Data_message_content_PAGE_MODE 846
#define CSN1_Packet_Serving_Cell_Data_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PDAN_Coding 892
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PDAN_Coding_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_PAGE_MODE 1539
#define CSN1_Packet_Uplink_Assignment_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Uplink_Assignment_message_content_RESEGMENT 1569
#define CSN1_Packet_Uplink_Assignment_message_content_RESEGMENT_SIZE   1
#define CSN1_Real_Time_Difference_Description_struct_RTD_Struct 868
#define CSN1_Real_Time_Difference_Description_struct_RTD_Struct_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_EARFCN 2016
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_EARFCN_SIZE  16
#define CSN1_Serving_cell_data_struct_INTERFERENCE_SERVING_CELL 825
#define CSN1_Serving_cell_data_struct_INTERFERENCE_SERVING_CELL_SIZE   6
#define CSN1_Single_Uplink_Assignment_2_IE_Dynamic_Allocation_2 1862
#define CSN1_Single_Uplink_Assignment_2_IE_Dynamic_Allocation_2_SIZE   0
#define CSN1_Timeslot_description_struct_MS_TIMESLOT_ALLOCATION 134
#define CSN1_Timeslot_description_struct_MS_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_UTRAN_CSG_Measurement_Report_IE_REPORTING_QUANTITY 629
#define CSN1_UTRAN_CSG_Measurement_Report_IE_REPORTING_QUANTITY_SIZE   6
#define CSN1_Unknown_SI_Message_List_struct_ADDITIONAL_MSG_TYPE 423
#define CSN1_Unknown_SI_Message_List_struct_ADDITIONAL_MSG_TYPE_SIZE   1
#define CSN1_Uplink_Assignment_2_struct_Uplink_TBF_Assignment_2 1636
#define CSN1_Uplink_Assignment_2_struct_Uplink_TBF_Assignment_2_SIZE   0
#define CSN1_p3G_Priority_Parameters_IE_DEFAULT_UTRAN_QRXLEVMIN 1996
#define CSN1_p3G_Priority_Parameters_IE_DEFAULT_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_NR_OF_FREQUENCIES 1114
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_NR_OF_FREQUENCIES_SIZE   5
#define CSN1_Additional_PSI_Messages_struct_PSI3quater_BROADCAST 1484
#define CSN1_Additional_PSI_Messages_struct_PSI3quater_BROADCAST_SIZE   1
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_NPM_Transfer_Time 1802
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_MS_TXPWR_MAX_CCH 444
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_RXLEV_ACCESS_MIN 443
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_TEMPORARY_OFFSET 445
#define CSN1_COMPACT_Cell_Selection_struct_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQUENCY_DIFF 1510
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_HCS_THR 1175
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_HCS_THR_SIZE   5
#define CSN1_Carrier_Specific_Info_struct_EMSR_Additional_PFCs_1 1754
#define CSN1_Carrier_Specific_Info_struct_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_EMSR_Additional_PFCs_2 1755
#define CSN1_Carrier_Specific_Info_struct_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_EMSR_Additional_PFCs_3 1756
#define CSN1_Carrier_Specific_Info_struct_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_Secondary_DL_TSC_Value 1759
#define CSN1_Carrier_Specific_Info_struct_Secondary_DL_TSC_Value_SIZE   3
#define CSN1_Content_COMPACT_Interference_Measurement_Capability 1316
#define CSN1_Content_COMPACT_Interference_Measurement_Capability_SIZE   1
#define CSN1_Content_UMTS_FDD_Radio_Access_Technology_Capability 1318
#define CSN1_Content_UMTS_FDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_DLMC_Frequency_Parameters_IE_DLMC_Direct_encoding_1 1731
#define CSN1_DLMC_Frequency_Parameters_IE_DLMC_Direct_encoding_1_SIZE   0
#define CSN1_DLMC_Frequency_Parameters_IE_DLMC_Direct_encoding_2 1737
#define CSN1_DLMC_Frequency_Parameters_IE_DLMC_Direct_encoding_2_SIZE   0
#define CSN1_DLMC_Frequency_Parameters_IE_DLMC_Indirect_encoding 1733
#define CSN1_DLMC_Frequency_Parameters_IE_DLMC_Indirect_encoding_SIZE   0
#define CSN1_DTM_Handover_Command_message_content_Message_escape 3247
#define CSN1_DTM_Handover_Command_message_content_Message_escape_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_TBF_mode_error 3245
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_TBF_mode_error_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_TBF_mode_error 3244
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_TBF_mode_error_SIZE   0
#define CSN1_Direct_encoding_2_struct_MA_Frequency_List_contents 1265
#define CSN1_Direct_encoding_2_struct_MA_Frequency_List_contents_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_bis_TFI_Assignment 514
#define CSN1_Downlink_TBF_assignment_2_struct_bis_TFI_Assignment_SIZE   5
#define CSN1_Dual_Carrier_Indirect_encoding_struct_CHANGE_MARK_1 1276
#define CSN1_Dual_Carrier_Indirect_encoding_struct_CHANGE_MARK_1_SIZE   2
#define CSN1_Dual_Carrier_Indirect_encoding_struct_CHANGE_MARK_2 1277
#define CSN1_Dual_Carrier_Indirect_encoding_struct_CHANGE_MARK_2_SIZE   2
#define CSN1_Dynamic_Allocation_2_IE_EXTENDED_DYNAMIC_ALLOCATION 1863
#define CSN1_Dynamic_Allocation_2_IE_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Dynamic_Allocation_3_IE_EXTENDED_DYNAMIC_ALLOCATION 1063
#define CSN1_Dynamic_Allocation_3_IE_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE__8PSK_CV_BEP 170
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE__8PSK_CV_BEP_SIZE   3
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_CELL_IDENTITY  11
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_CELL_IDENTITY_SIZE   9
#define CSN1_E_UTRAN_Target_cell_IE_Physical_Layer_Cell_Identity 267
#define CSN1_E_UTRAN_Target_cell_IE_Physical_Layer_Cell_Identity_SIZE   9
#define CSN1_Extension_Information_42a_MTTI_UPLINK_ASSIGNMENT_C1 2356
#define CSN1_Extension_Information_42a_MTTI_UPLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Extension_Information_42a_MTTI_UPLINK_ASSIGNMENT_C2 2357
#define CSN1_Extension_Information_42a_MTTI_UPLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Extension_Information_EGPRS_PACKET__CHANNEL_REQUEST 1039
#define CSN1_Extension_Information_EGPRS_PACKET__CHANNEL_REQUEST_SIZE   1
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_DOWNLINK_TFI 759
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_MBMS_bearer_description_struct_Frequency_Parameters 1703
#define CSN1_MBMS_bearer_description_struct_Frequency_Parameters_SIZE   0
#define CSN1_MBMS_bearer_description_struct_MBMS_Bearer_Identity 1706
#define CSN1_MBMS_bearer_description_struct_MBMS_Bearer_Identity_SIZE   0
#define CSN1_MPRACH_description_struct_MPRACH_Control_Parameters 2289
#define CSN1_MPRACH_description_struct_MPRACH_Control_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_P0 1385
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_P0_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_struct_TBF_Starting_Time 1245
#define CSN1_Multiple_Uplink_Assignment_struct_TBF_Starting_Time_SIZE   0
#define CSN1_NAS_Container_for_PS_Handover_IE_NAS_CONTAINER_DATA 607
#define CSN1_NAS_Container_for_PS_Handover_IE_NAS_CONTAINER_DATA_SIZE   0
#define CSN1_NC_Measurement_Report_struct_bis_REPORTING_QUANTITY 830
#define CSN1_NC_Measurement_Report_struct_bis_REPORTING_QUANTITY_SIZE   6
#define CSN1_Neighbour_parameter_set_struct_GPRS_RESELECT_OFFSET 1165
#define CSN1_Neighbour_parameter_set_struct_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_FACCH_F 754
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_FACCH_F_SIZE  20
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_FACCH_H 755
#define CSN1_Network_Response_Times_struct_RESPONSE_TIME_FACCH_H_SIZE  20
#define CSN1_NonGSM_Message_struct_NonGSM_Protocol_Discriminator 474
#define CSN1_NonGSM_Message_struct_NonGSM_Protocol_Discriminator_SIZE   3
#define CSN1_PCCCH_Description_struct_Non_hopping_PCCCH_carriers 1469
#define CSN1_PCCCH_Description_struct_Non_hopping_PCCCH_carriers_SIZE   0
#define CSN1_PSI13_message_content_GPRS_Power_Control_Parameters 1222
#define CSN1_PSI13_message_content_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_PSI3_quater_message_content_Distribution_part_error 3165
#define CSN1_PSI3_quater_message_content_Distribution_part_error_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Primary_TSC_Set 2412
#define CSN1_PS_Handover_Command_message_content_Primary_TSC_Set_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_2_IE_Handover_Reference 2337
#define CSN1_PS_Handover_Radio_Resources_2_IE_Handover_Reference_SIZE   8
#define CSN1_PS_Handover_Radio_Resources_3_IE_Handover_Reference 2359
#define CSN1_PS_Handover_Radio_Resources_3_IE_Handover_Reference_SIZE   8
#define CSN1_PS_Handover_Radio_Resources_3_IE_REPORTED_TIMESLOTS 2392
#define CSN1_PS_Handover_Radio_Resources_3_IE_REPORTED_TIMESLOTS_SIZE   8
#define CSN1_PS_Handover_Radio_Resources_3_IE_Uplink_EGPRS_Level 2394
#define CSN1_PS_Handover_Radio_Resources_3_IE_Uplink_EGPRS_Level_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_IE_Frequency_Parameters 1718
#define CSN1_PS_Handover_Radio_Resources_IE_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Access_Reject_message_content_Iu_mode_Reject 666
#define CSN1_Packet_Access_Reject_message_content_Iu_mode_Reject_SIZE   0
#define CSN1_Packet_CS_Release_message_content_NPM_Transfer_Time 2234
#define CSN1_Packet_CS_Release_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_Cell_Change_Order_message_content_Global_TFI 2292
#define CSN1_Packet_Cell_Change_Order_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_DBPSCH_Assignment_message_content_Global_TFI 733
#define CSN1_Packet_DBPSCH_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_RB_Id 503
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_RB_Id_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_LegacyIE 1941
#define CSN1_Packet_Downlink_Assignment_message_content_LegacyIE_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_MAC_MODE 1900
#define CSN1_Packet_Downlink_Assignment_message_content_MAC_MODE_SIZE   2
#define CSN1_Packet_Downlink_Assignment_message_content_RLC_MODE 1901
#define CSN1_Packet_Downlink_Assignment_message_content_RLC_MODE_SIZE   1
#define CSN1_Packet_Measurement_Order_message_content_CCN_ACTIVE 1973
#define CSN1_Packet_Measurement_Order_message_content_CCN_ACTIVE_SIZE   1
#define CSN1_Packet_Measurement_Order_message_content_Global_TFI 1965
#define CSN1_Packet_Measurement_Order_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Measurement_Order_message_content__3G_BA_IND 1984
#define CSN1_Packet_Measurement_Order_message_content__3G_BA_IND_SIZE   1
#define CSN1_Packet_Mobile_TBF_Status_message_content_GLOBAL_TFI 371
#define CSN1_Packet_Mobile_TBF_Status_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_PSI_Status_message_content_PBCCH_CHANGE_MARK 401
#define CSN1_Packet_PSI_Status_message_content_PBCCH_CHANGE_MARK_SIZE   3
#define CSN1_Packet_Resource_Request_message_content_ACCESS_TYPE 2067
#define CSN1_Packet_Resource_Request_message_content_ACCESS_TYPE_SIZE   2
#define CSN1_Packet_Resource_Request_message_content_CHANGE_MARK 2073
#define CSN1_Packet_Resource_Request_message_content_CHANGE_MARK_SIZE   2
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN0 2076
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN0_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN1 2077
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN1_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN2 2078
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN2_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN3 2079
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN3_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN4 2080
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN4_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN5 2081
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN5_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN6 2082
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN6_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN7 2083
#define CSN1_Packet_Resource_Request_message_content_I_LEVEL_TN7_SIZE   4
#define CSN1_Packet_Resource_Request_message_content_TLLI_G_RNTI 2069
#define CSN1_Packet_Resource_Request_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Serving_Cell_Data_message_content_Global_TFI 847
#define CSN1_Packet_Serving_Cell_Data_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_TBF_Release_message_content_DOWNLINK_RELEASE 500
#define CSN1_Packet_TBF_Release_message_content_DOWNLINK_RELEASE_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_Global_TFI 1542
#define CSN1_Packet_Uplink_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_NPM_Transfer_Time 1823
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_ARFCN 313
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_ARFCN_SIZE  14
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_ARFCN 319
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_ARFCN_SIZE  14
#define CSN1_Single_Uplink_Assignment_2_IE_REPORTED_TIMESLOTS_C1 1857
#define CSN1_Single_Uplink_Assignment_2_IE_REPORTED_TIMESLOTS_C1_SIZE   8
#define CSN1_Single_Uplink_Assignment_2_IE_REPORTED_TIMESLOTS_C2 1858
#define CSN1_Single_Uplink_Assignment_2_IE_REPORTED_TIMESLOTS_C2_SIZE   8
#define CSN1_Unknown_PSI_Message_List_struct_ADDITIONAL_MSG_TYPE 410
#define CSN1_Unknown_PSI_Message_List_struct_ADDITIONAL_MSG_TYPE_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_CHANNEL_CODING_COMMAND 934
#define CSN1_Uplink_TBF_Assignment_struct_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_CBCH_Channel_Description_struct_Frequency_Parameters 2105
#define CSN1_CBCH_Channel_Description_struct_Frequency_Parameters_SIZE   0
#define CSN1_CCCH_Access_Information_struct_NETWORK_CONTROL_ORDER 2119
#define CSN1_CCCH_Access_Information_struct_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_COMPACT_Cell_Selection_struct_GUAR_CONSTANT_PWR_BLKS 450
#define CSN1_COMPACT_Cell_Selection_struct_GUAR_CONSTANT_PWR_BLKS_SIZE   2
#define CSN1_COMPACT_NCP2_Property_struct_SAME_RA_AS_SERVING_CELL  96
#define CSN1_COMPACT_NCP2_Property_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_COMPACT_Neighbour_Cell_params_struct_START_FREQUENCY 1506
#define CSN1_COMPACT_Neighbour_Cell_params_struct_START_FREQUENCY_SIZE  10
#define CSN1_Carrier_Specific_Info_struct_DOWNLINK_TFI_ASSIGNMENT 1749
#define CSN1_Carrier_Specific_Info_struct_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Channel_Request_Description_IE_PEAK_THROUGHPUT_CLASS 197
#define CSN1_Channel_Request_Description_IE_PEAK_THROUGHPUT_CLASS_SIZE   4
#define CSN1_Content_CDMA_2000_Radio_Access_Technology_Capability 1320
#define CSN1_Content_CDMA_2000_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_DLMC_Direct_encoding_1_struct_GPRS_Mobile_Allocation 1732
#define CSN1_DLMC_Direct_encoding_1_struct_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_Cell_Options 2506
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_Cell_Options_SIZE   0
#define CSN1_Downlink_TBF_assignment_struct_ter_EGPRS_Window_Size 1059
#define CSN1_Downlink_TBF_assignment_struct_ter_EGPRS_Window_Size_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE_GMSK_MEAN_BEP 167
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE_GMSK_MEAN_BEP_SIZE   5
#define CSN1_EXT_Measurement_Report_struct_NUMBER_OF_MEASUREMENTS 789
#define CSN1_EXT_Measurement_Report_struct_NUMBER_OF_MEASUREMENTS_SIZE   5
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_REPORTING_QUANTITY 624
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_REPORTING_QUANTITY_SIZE   6
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_Tracking_Area_Code 620
#define CSN1_E_UTRAN_CSG_Measurement_Report_IE_Tracking_Area_Code_SIZE  16
#define CSN1_E_UTRAN_Measurement_Report_struct_REPORTING_QUANTITY  82
#define CSN1_E_UTRAN_Measurement_Report_struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_Global_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE 230
#define CSN1_Global_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_Iu_Mode_Cell_Selection_struct_SI13Alt_PBCCH_Location 324
#define CSN1_Iu_Mode_Cell_Selection_struct_SI13Alt_PBCCH_Location_SIZE   0
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_PENALTY_TIME 330
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Bearer_Identity 2440
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Bearer_Identity_SIZE   0
#define CSN1_NC_Iu_Mode_Only_Cell_List_struct_List_of_added_cells 1110
#define CSN1_NC_Iu_Mode_Only_Cell_List_struct_List_of_added_cells_SIZE   0
#define CSN1_Neighbour_parameter_set_struct_GPRS_MS_TXPWR_MAX_CCH 1159
#define CSN1_Neighbour_parameter_set_struct_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Neighbour_parameter_set_struct_GPRS_RXLEV_ACCESS_MIN 1158
#define CSN1_Neighbour_parameter_set_struct_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_Neighbour_parameter_set_struct_GPRS_TEMPORARY_OFFSET 1163
#define CSN1_Neighbour_parameter_set_struct_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_Neighbouring_Cell_Report_struct_MBMS_PTM_CHANGE_MARK 771
#define CSN1_Neighbouring_Cell_Report_struct_MBMS_PTM_CHANGE_MARK_SIZE   2
#define CSN1_PDCH_Pairs_Description_struct_DOWNLINK_PDCH_PAIRS_C1 1638
#define CSN1_PDCH_Pairs_Description_struct_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_PDCH_Pairs_Description_struct_DOWNLINK_PDCH_PAIRS_C2 1639
#define CSN1_PDCH_Pairs_Description_struct_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_PSI1_message_content_Global_Power_Control_Parameters 1143
#define CSN1_PSI1_message_content_Global_Power_Control_Parameters_SIZE  24
#define CSN1_PSI3_bis_message_content_Neighbour_Cell_parameters_2 1153
#define CSN1_PSI3_bis_message_content_Neighbour_Cell_parameters_2_SIZE   0
#define CSN1_PSI3_message_content_Serving_Cell_LSA_ID_information 1502
#define CSN1_PSI3_message_content_Serving_Cell_LSA_ID_information_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_PFI_of_downlink_TBF 2378
#define CSN1_PS_Handover_Radio_Resources_3_IE_PFI_of_downlink_TBF_SIZE   7
#define CSN1_PS_Handover_Radio_Resources_IE_NETWORK_CONTROL_ORDER 1719
#define CSN1_PS_Handover_Radio_Resources_IE_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_Packet_Cell_Change_Failure_message_content_Diversity 676
#define CSN1_Packet_Cell_Change_Failure_message_content_Diversity_SIZE   1
#define CSN1_Packet_Cell_Change_Failure_message_content_FDD_ARFCN 675
#define CSN1_Packet_Cell_Change_Failure_message_content_FDD_ARFCN_SIZE  14
#define CSN1_Packet_Cell_Change_Failure_message_content_Sync_Case 682
#define CSN1_Packet_Cell_Change_Failure_message_content_Sync_Case_SIZE   1
#define CSN1_Packet_Cell_Change_Failure_message_content_TDD_ARFCN 679
#define CSN1_Packet_Cell_Change_Failure_message_content_TDD_ARFCN_SIZE  14
#define CSN1_Packet_Cell_Change_Notification_message_content_BSIC 695
#define CSN1_Packet_Cell_Change_Notification_message_content_BSIC_SIZE   6
#define CSN1_Packet_Cell_Change_Order_message_content_TLLI_G_RNTI 2293
#define CSN1_Packet_Cell_Change_Order_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Control_Acknowledgement_8bit_content_CTRL_ACK 295
#define CSN1_Packet_Control_Acknowledgement_8bit_content_CTRL_ACK_SIZE   2
#define CSN1_Packet_Downlink_Assignment_message_content_PAGE_MODE 1895
#define CSN1_Packet_Downlink_Assignment_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Measurement_Order_message_content_TLLI_G_RNTI 1966
#define CSN1_Packet_Measurement_Order_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Neighbour_Cell_Data_message_content_CONTAINER 845
#define CSN1_Packet_Neighbour_Cell_Data_message_content_CONTAINER_SIZE   0
#define CSN1_Packet_Neighbour_Cell_Data_message_content_PAGE_MODE 838
#define CSN1_Packet_Neighbour_Cell_Data_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE 501
#define CSN1_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE_SIZE   4
#define CSN1_Packet_Uplink_Assignment_message_content_BEP_PERIOD2 1573
#define CSN1_Packet_Uplink_Assignment_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Packet_Uplink_Assignment_message_content_TLLI_G_RNTI 1543
#define CSN1_Packet_Uplink_Assignment_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Repeated_Invalid_BSIC_Information_struct_RXLEV_NCELL 829
#define CSN1_Repeated_Invalid_BSIC_Information_struct_RXLEV_NCELL_SIZE   6
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_Indic0 314
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_Indic0_SIZE   1
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_Indic0 320
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_Indic0_SIZE   1
#define CSN1_Single_Downlink_Assignment_2_IE_Downlink_EGPRS_Level 1837
#define CSN1_Single_Downlink_Assignment_2_IE_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Single_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C1 1841
#define CSN1_Single_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C2 1842
#define CSN1_Single_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Uplink_Assignment_struct_EXTENDED_DYNAMIC_ALLOCATION 1235
#define CSN1_Uplink_Assignment_struct_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Uplink_Assignment_struct_Global_Timeslot_description 1240
#define CSN1_Uplink_Assignment_struct_Global_Timeslot_description_SIZE   0
#define CSN1_Uplink_TBF_Assignment_2_struct_REPORTED_TIMESLOTS_C1 947
#define CSN1_Uplink_TBF_Assignment_2_struct_REPORTED_TIMESLOTS_C1_SIZE   8
#define CSN1_Uplink_TBF_Assignment_2_struct_REPORTED_TIMESLOTS_C2 948
#define CSN1_Uplink_TBF_Assignment_2_struct_REPORTED_TIMESLOTS_C2_SIZE   8
#define CSN1_Uplink_TBF_Assignment_struct_TBF_TIMESLOT_ALLOCATION 938
#define CSN1_Uplink_TBF_Assignment_struct_TBF_TIMESLOT_ALLOCATION_SIZE   0
#define CSN1__3G_CCN_Measurement_Report_Struct_REPORTING_QUANTITY 720
#define CSN1__3G_CCN_Measurement_Report_Struct_REPORTING_QUANTITY_SIZE   6
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Ignore 3164
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Ignore_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_Index_Start_3G 1097
#define CSN1__3G_Neighbour_Cell_Description_struct_Index_Start_3G_SIZE   7
#define CSN1_BEP_Measurement_Report_Struct_bis_REPORTED_MODULATION 568
#define CSN1_BEP_Measurement_Report_Struct_bis_REPORTED_MODULATION_SIZE   2
#define CSN1_CCCH_Access_Information_struct_SI13_Mobile_Allocation 2116
#define CSN1_CCCH_Access_Information_struct_SI13_Mobile_Allocation_SIZE   0
#define CSN1_COMPACT_Cell_Selection_struct_SAME_RA_AS_SERVING_CELL 442
#define CSN1_COMPACT_Cell_Selection_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_COMPACT_Neighbour_Cell_params_2_struct_Message_escape 3162
#define CSN1_COMPACT_Neighbour_Cell_params_2_struct_Message_escape_SIZE   0
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH 1509
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_Carrier_Specific_Info_struct_DOWNLINK_PDCH_PAIRS_DLMC 1743
#define CSN1_Carrier_Specific_Info_struct_DOWNLINK_PDCH_PAIRS_DLMC_SIZE   8
#define CSN1_Carrier_Specific_Info_struct_DOWNLINK_eTFI_ASSIGNMENT 1750
#define CSN1_Carrier_Specific_Info_struct_DOWNLINK_eTFI_ASSIGNMENT_SIZE   3
#define CSN1_Carrier_Specific_Info_struct_Power_Control_Parameters 1751
#define CSN1_Carrier_Specific_Info_struct_Power_Control_Parameters_SIZE   0
#define CSN1_Channel_Description_struct_UPLINK_TIMESLOT_ALLOCATION 738
#define CSN1_Channel_Description_struct_UPLINK_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct_GMSK_CV_BEP 642
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct_GMSK_CV_BEP_SIZE   3
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_Extension_Length 2492
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_Extension_Length_SIZE   6
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_Extension_Length 2471
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_Extension_Length_SIZE   8
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_CONTROL_ACK 615
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_CONTROL_ACK_SIZE   1
#define CSN1_Downlink_TBF_assignment_2_struct_bis_EVENT_BASED_FANR 517
#define CSN1_Downlink_TBF_assignment_2_struct_bis_EVENT_BASED_FANR_SIZE   1
#define CSN1_EGPRS_Ack_Nack_Description_struct_BEGINNING_OF_WINDOW 160
#define CSN1_EGPRS_Ack_Nack_Description_struct_BEGINNING_OF_WINDOW_SIZE   1
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE__8PSK_MEAN_BEP 169
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_IE__8PSK_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_Packet_channel_request_message_content_Priority  58
#define CSN1_EGPRS_Packet_channel_request_message_content_Priority_SIZE   2
#define CSN1_EPD_A_N_Extension_Info_Type_2_EARLY_TBF_ESTABLISHMENT 1375
#define CSN1_EPD_A_N_Extension_Info_Type_2_EARLY_TBF_ESTABLISHMENT_SIZE   1
#define CSN1_Extended_Channel_Request_Description_IE_LLC__PDU_TYPE 208
#define CSN1_Extended_Channel_Request_Description_IE_LLC__PDU_TYPE_SIZE   1
#define CSN1_Extension_Information_12_48_MTTI_UPLINK_ASSIGNMENT_C1 2500
#define CSN1_Extension_Information_12_48_MTTI_UPLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Extension_Information_12_48_MTTI_UPLINK_ASSIGNMENT_C2 2501
#define CSN1_Extension_Information_12_48_MTTI_UPLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Extension_Information_12_64_MTTI_UPLINK_ASSIGNMENT_C1 2479
#define CSN1_Extension_Information_12_64_MTTI_UPLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Extension_Information_12_64_MTTI_UPLINK_ASSIGNMENT_C2 2480
#define CSN1_Extension_Information_12_64_MTTI_UPLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Extension_Information_42a_MTTI_DOWNLINK_ASSIGNMENT_C1 2354
#define CSN1_Extension_Information_42a_MTTI_DOWNLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Extension_Information_42a_MTTI_DOWNLINK_ASSIGNMENT_C2 2355
#define CSN1_Extension_Information_42a_MTTI_DOWNLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_GPRS_Mobile_Allocations_struct_GPRS_Mobile_Allocation 1462
#define CSN1_GPRS_Mobile_Allocations_struct_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_CELL_BAR_QUALIFY_3 325
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_CELL_BAR_QUALIFY_3_SIZE   2
#define CSN1_Iu_mode_Channel_Request_Description_IE_RADIO_PRIORITY 203
#define CSN1_Iu_mode_Channel_Request_Description_IE_RADIO_PRIORITY_SIZE   2
#define CSN1_MBMS_Assignment_Non_distribution_message_content_TMGI 2257
#define CSN1_MBMS_Assignment_Non_distribution_message_content_TMGI_SIZE   0
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_Extension_Bits 773
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_Extension_Bits_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Report_struct_PSI3_CHANGE_MARK 762
#define CSN1_MBMS_Neighbouring_Cell_Report_struct_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_FANR 1418
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_FANR_SIZE   1
#define CSN1_Multislot_capability_struct_DTM_GPRS_Multi_Slot_Class 1312
#define CSN1_Multislot_capability_struct_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_NAS_Container_for_PS_Handover_IE_NAS_CONTAINER_LENGTH 606
#define CSN1_NAS_Container_for_PS_Handover_IE_NAS_CONTAINER_LENGTH_SIZE   7
#define CSN1_Neighbouring_Cell_Report_struct_RESEL_PARAMS_ACQUIRED 770
#define CSN1_Neighbouring_Cell_Report_struct_RESEL_PARAMS_ACQUIRED_SIZE   1
#define CSN1_Non_Hopping_PCCCH_Carriers_struct_TIMESLOT_ALLOCATION 1471
#define CSN1_Non_Hopping_PCCCH_Carriers_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_PSI3_message_content_General_Cell_Selection_parameter 1495
#define CSN1_PSI3_message_content_General_Cell_Selection_parameter_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_DLMC_UL_Carrier_Info 2386
#define CSN1_PS_Handover_Radio_Resources_3_IE_DLMC_UL_Carrier_Info_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_Downlink_EGPRS_Level 2381
#define CSN1_PS_Handover_Radio_Resources_3_IE_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Packet_Access_Reject_message_content_A_Gb_mode_Reject 669
#define CSN1_Packet_Access_Reject_message_content_A_Gb_mode_Reject_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Uplink_RLC_Entity_2 2238
#define CSN1_Packet_CS_Release_message_content_Uplink_RLC_Entity_2_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Uplink_RLC_Entity_3 2239
#define CSN1_Packet_CS_Release_message_content_Uplink_RLC_Entity_3_SIZE   0
#define CSN1_Packet_CS_Request_message_content_ESTABLISHMENT_CAUSE 522
#define CSN1_Packet_CS_Request_message_content_ESTABLISHMENT_CAUSE_SIZE   8
#define CSN1_Packet_Cell_Change_Continue_message_content_PAGE_MODE 296
#define CSN1_Packet_Cell_Change_Continue_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Cell_Change_Notification_message_content_ARFCN 694
#define CSN1_Packet_Cell_Change_Notification_message_content_ARFCN_SIZE  10
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_RB_Id 356
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_RB_Id_SIZE   5
#define CSN1_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI 334
#define CSN1_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_Global_TFI 1897
#define CSN1_Packet_Downlink_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Downlink_Assignment_message_content_PR_MODE_C1 1947
#define CSN1_Packet_Downlink_Assignment_message_content_PR_MODE_C1_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_PR_MODE_C2 1949
#define CSN1_Packet_Downlink_Assignment_message_content_PR_MODE_C2_SIZE   1
#define CSN1_Packet_Measurement_Report_message_content_TLLI_G_RNTI 777
#define CSN1_Packet_Measurement_Report_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Measurement_Report_message_content__3G_BA_USED 802
#define CSN1_Packet_Measurement_Report_message_content__3G_BA_USED_SIZE   1
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Global_TFI 839
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Paging_Request_message_content_NLN_status_PPCH 2450
#define CSN1_Packet_Paging_Request_message_content_NLN_status_PPCH_SIZE   1
#define CSN1_Packet_Physical_Information_message_content_PAGE_MODE 543
#define CSN1_Packet_Physical_Information_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Resource_Request_message_content_Downlink_eTFI 2097
#define CSN1_Packet_Resource_Request_message_content_Downlink_eTFI_SIZE   3
#define CSN1_Packet_Serving_Cell_SI_message_content_CONTAINER_DATA 427
#define CSN1_Packet_Serving_Cell_SI_message_content_CONTAINER_DATA_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PAGE_MODE 2133
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RESEGMENT 2166
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RESEGMENT_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Extension_Bits 888
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Extension_Bits_SIZE   0
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Message_escape 3156
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Pulse_Format 1596
#define CSN1_Packet_Uplink_Assignment_message_content_Pulse_Format_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_RLC_Entity_2 1578
#define CSN1_Packet_Uplink_Assignment_message_content_RLC_Entity_2_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_RLC_Entity_3 1579
#define CSN1_Packet_Uplink_Assignment_message_content_RLC_Entity_3_SIZE   0
#define CSN1_Uplink_Assignment_2_struct_Uplink_Control_Timeslot_C1 1628
#define CSN1_Uplink_Assignment_2_struct_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_Uplink_Assignment_2_struct_Uplink_Control_Timeslot_C2 1629
#define CSN1_Uplink_Assignment_2_struct_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1__3G_CCN_Measurement_Report_Struct__3G_CELL_LIST_INDEX 719
#define CSN1__3G_CCN_Measurement_Report_Struct__3G_CELL_LIST_INDEX_SIZE   7
#define CSN1__3G_Neighbour_Cells_Description_struct_Index_Start_3G 1189
#define CSN1__3G_Neighbour_Cells_Description_struct_Index_Start_3G_SIZE   7
#define CSN1_Additional_access_technologies_struct_GMSK_Power_Class 1341
#define CSN1_Additional_access_technologies_struct_GMSK_Power_Class_SIZE   3
#define CSN1_Cell_Identification_IE_Location_Area_Identification_IE 594
#define CSN1_Cell_Identification_IE_Location_Area_Identification_IE_SIZE  40
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__8PSK_CV_BEP 644
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__8PSK_CV_BEP_SIZE   3
#define CSN1_DLMC_UL_Carrier_Info_struct_UPLINK_TIMESLOT_ALLOCATION 1060
#define CSN1_DLMC_UL_Carrier_Info_struct_UPLINK_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_GPRS_Cell_Options 2488
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_GPRS_Cell_Options_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_GPRS_Cell_Options 2467
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_GPRS_Cell_Options_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_Cell_Identification 2503
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_Cell_Identification_SIZE  64
#define CSN1_Downlink_TBF_assignment_2_struct_bis_NPM_Transfer_Time 516
#define CSN1_Downlink_TBF_assignment_2_struct_bis_NPM_Transfer_Time_SIZE   5
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_Direct_encoding_1 1268
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_Direct_encoding_1_SIZE   0
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_Direct_encoding_2 1278
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_Direct_encoding_2_SIZE   0
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_Indirect_encoding 1272
#define CSN1_Dual_Carrier_Frequency_Parameters_IE_Indirect_encoding_SIZE   0
#define CSN1_EGPRS_Ack_Nack_Description_struct_FINAL_ACK_INDICATION 159
#define CSN1_EGPRS_Ack_Nack_Description_struct_FINAL_ACK_INDICATION_SIZE   1
#define CSN1_ENH_Reporting_parameters_struct_INVALID_BSIC_REPORTING 1530
#define CSN1_ENH_Reporting_parameters_struct_INVALID_BSIC_REPORTING_SIZE   1
#define CSN1_E_UTRAN_Parameters_IE_Repeated_E_UTRAN_Neighbour_Cells 2015
#define CSN1_E_UTRAN_Parameters_IE_Repeated_E_UTRAN_Neighbour_Cells_SIZE   0
#define CSN1_Extended_Channel_Request_Description_IE_RADIO_PRIORITY 206
#define CSN1_Extended_Channel_Request_Description_IE_RADIO_PRIORITY_SIZE   2
#define CSN1_Handover_Access_8_bit_message_HANDOVER_REFERENCE_VALUE 155
#define CSN1_Handover_Access_8_bit_message_HANDOVER_REFERENCE_VALUE_SIZE   8
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_NR_OF_FREQUENCIES 729
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_NR_OF_FREQUENCIES_SIZE   5
#define CSN1_Iu_mode_Channel_Request_Description_IE_RLC_BLOCK_COUNT 204
#define CSN1_Iu_mode_Channel_Request_Description_IE_RLC_BLOCK_COUNT_SIZE   8
#define CSN1_MBMS_Assignment_Distribution_message_content_PAGE_MODE 2266
#define CSN1_MBMS_Assignment_Distribution_message_content_PAGE_MODE_SIZE   2
#define CSN1_MBMS_Assignment_Non_distribution_message_content_ALPHA 2255
#define CSN1_MBMS_Assignment_Non_distribution_message_content_ALPHA_SIZE   4
#define CSN1_MBMS_Assignment_Non_distribution_message_content_GAMMA 2256
#define CSN1_MBMS_Assignment_Non_distribution_message_content_GAMMA_SIZE   5
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MS_ID 2253
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MS_ID_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_USF 1020
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_USF_SIZE   3
#define CSN1_MBMS_p_t_m_channel_description_IE_Frequency_Parameters 2436
#define CSN1_MBMS_p_t_m_channel_description_IE_Frequency_Parameters_SIZE   0
#define CSN1_MS_RA_capability_value_part_struct_Access_capabilities 1287
#define CSN1_MS_RA_capability_value_part_struct_Access_capabilities_SIZE   0
#define CSN1_Multiple_Downlink_Assignment_2_IE_Downlink_EGPRS_Level 1764
#define CSN1_Multiple_Downlink_Assignment_2_IE_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Multiple_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C1 1774
#define CSN1_Multiple_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Multiple_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C2 1775
#define CSN1_Multiple_Downlink_Assignment_2_IE_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_P0_C1 1407
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_P0_C1_SIZE   4
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_P0_C2 1409
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_P0_C2_SIZE   4
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_FANR 1669
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_FANR_SIZE   1
#define CSN1_Multislot_capability_struct_DTM_EGPRS_Multi_Slot_Class 1314
#define CSN1_Multislot_capability_struct_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_I 1356
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_I_SIZE   3
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_T 1357
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_T_SIZE   3
#define CSN1_NC_Measurement_Parameters_struct_NETWORK_CONTROL_ORDER 1354
#define CSN1_NC_Measurement_Parameters_struct_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_NC_Measurement_Report_struct_INTERFERENCE_SERVING_CELL 796
#define CSN1_NC_Measurement_Report_struct_INTERFERENCE_SERVING_CELL_SIZE   6
#define CSN1_NC_Measurement_Report_struct_NUMBER_OF_NC_MEASUREMENTS 797
#define CSN1_NC_Measurement_Report_struct_NUMBER_OF_NC_MEASUREMENTS_SIZE   3
#define CSN1_Neighbour_Cell_params_2_struct_Neighbour_parameter_set 1155
#define CSN1_Neighbour_Cell_params_2_struct_Neighbour_parameter_set_SIZE   0
#define CSN1_PBCCH_Description_struct_2_PBCCH_Frequency_Description 2131
#define CSN1_PBCCH_Description_struct_2_PBCCH_Frequency_Description_SIZE   0
#define CSN1_PSI3_message_content_Iu_Mode_Neighbour_Cell_Parameters 1513
#define CSN1_PSI3_message_content_Iu_Mode_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_PSI3_ter_message_content_GPRS_REP_PRIORITY_Description 869
#define CSN1_PSI3_ter_message_content_GPRS_REP_PRIORITY_Description_SIZE   0
#define CSN1_PSI8_message_content_Dynamic_ARFCN_Mapping_Description 2106
#define CSN1_PSI8_message_content_Dynamic_ARFCN_Mapping_Description_SIZE   0
#define CSN1_PS_Handover_Command_message_content_EMST_NW_Capability 2407
#define CSN1_PS_Handover_Command_message_content_EMST_NW_Capability_SIZE   1
#define CSN1_PS_Handover_Command_message_content_E_UTRAN_CCN_ACTIVE 2400
#define CSN1_PS_Handover_Command_message_content_E_UTRAN_CCN_ACTIVE_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_2_IE_NETWORK_CONTROL_ORDER 2348
#define CSN1_PS_Handover_Radio_Resources_2_IE_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_DLMC_Measurement_Type 2369
#define CSN1_PS_Handover_Radio_Resources_3_IE_DLMC_Measurement_Type_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_3_IE_NETWORK_CONTROL_ORDER 2397
#define CSN1_PS_Handover_Radio_Resources_3_IE_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_UPLINK_TFI_ASSIGNMENT 2388
#define CSN1_PS_Handover_Radio_Resources_3_IE_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_PS_Handover_Radio_Resources_IE_CCN_Support_Description 1717
#define CSN1_PS_Handover_Radio_Resources_IE_CCN_Support_Description_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_IE_Uplink_Control_Timeslot 1726
#define CSN1_PS_Handover_Radio_Resources_IE_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Packet_Access_Reject_message_content_Additional_Reject 665
#define CSN1_Packet_Access_Reject_message_content_Additional_Reject_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Frequency_Parameters 2220
#define CSN1_Packet_CS_Release_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Secondary_DL_TSC_Set 2226
#define CSN1_Packet_CS_Release_message_content_Secondary_DL_TSC_Set_SIZE   1
#define CSN1_Packet_Cell_Change_Continue_message_content_GLOBAL_TFI 297
#define CSN1_Packet_Cell_Change_Continue_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_Cell_Change_Failure_message_content_TLLI_G_RNTI 671
#define CSN1_Packet_Cell_Change_Failure_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Cell_Change_Order_message_content_IMMEDIATE_REL 2294
#define CSN1_Packet_Cell_Change_Order_message_content_IMMEDIATE_REL_SIZE   1
#define CSN1_Packet_Control_Acknowledgement_11bit_b_content_TN_RRBP 293
#define CSN1_Packet_Control_Acknowledgement_11bit_b_content_TN_RRBP_SIZE   3
#define CSN1_Packet_Control_Acknowledgement_message_content_TN_RRBP 289
#define CSN1_Packet_Control_Acknowledgement_message_content_TN_RRBP_SIZE   3
#define CSN1_Packet_Downlink_Assignment_message_content_BEP_PERIOD2 1913
#define CSN1_Packet_Downlink_Assignment_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_CONTROL_ACK 1902
#define CSN1_Packet_Downlink_Assignment_message_content_CONTROL_ACK_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_PDAN_Coding 1962
#define CSN1_Packet_Downlink_Assignment_message_content_PDAN_Coding_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_TLLI_G_RNTI 1898
#define CSN1_Packet_Downlink_Assignment_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_Measurement_Report_message_content_SI23_BA_USED 813
#define CSN1_Packet_Measurement_Report_message_content_SI23_BA_USED_SIZE   1
#define CSN1_Packet_Mobile_TBF_Status_message_content_Downlink_eTFI 374
#define CSN1_Packet_Mobile_TBF_Status_message_content_Downlink_eTFI_SIZE   3
#define CSN1_Packet_Physical_Information_message_content_Global_TFI 544
#define CSN1_Packet_Physical_Information_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Queueing_Notification_message_content_PAGE_MODE 397
#define CSN1_Packet_Queueing_Notification_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Timeslot_Reconfigure_message_content_GLOBAL_TFI 2134
#define CSN1_Packet_Timeslot_Reconfigure_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Packet_Uplink_Assignment_message_content_RTTI_USF_MODE 1585
#define CSN1_Packet_Uplink_Assignment_message_content_RTTI_USF_MODE_SIZE   1
#define CSN1_Packet_channel_request_11_bit_message_content_Priority  43
#define CSN1_Packet_channel_request_11_bit_message_content_Priority_SIZE   2
#define CSN1_REMOVED_3GCELL_Description_struct_REMOVED_3GCELL_INDEX 1104
#define CSN1_REMOVED_3GCELL_Description_struct_REMOVED_3GCELL_INDEX_SIZE   7
#define CSN1_REMOVED_3GCELL_Description_struct__3G_CELL_DIFF_LENGTH 1105
#define CSN1_REMOVED_3GCELL_Description_struct__3G_CELL_DIFF_LENGTH_SIZE   3
#define CSN1_Serving_Cell_params_struct_HCS_Serving_Cell_parameters 1493
#define CSN1_Serving_Cell_params_struct_HCS_Serving_Cell_parameters_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C1 1839
#define CSN1_Single_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C2 1840
#define CSN1_Single_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_TIMESLOT_ALLOCATION_C1 1845
#define CSN1_Single_Downlink_Assignment_2_IE_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_TIMESLOT_ALLOCATION_C2 1846
#define CSN1_Single_Downlink_Assignment_2_IE_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_Single_Uplink_Assignment_2_IE_Uplink_EGPRS_Window_Size 1855
#define CSN1_Single_Uplink_Assignment_2_IE_Uplink_EGPRS_Window_Size_SIZE   5
#define CSN1_Uplink_Assignment_2_struct_EXTENDED_DYNAMIC_ALLOCATION 1627
#define CSN1_Uplink_Assignment_2_struct_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Uplink_Assignment_2_struct_Global_Timeslot_description 1635
#define CSN1_Uplink_Assignment_2_struct_Global_Timeslot_description_SIZE   0
#define CSN1_Uplink_TBF_Assignment_2_struct_TBF_TIMESLOT_ALLOCATION 949
#define CSN1_Uplink_TBF_Assignment_2_struct_TBF_TIMESLOT_ALLOCATION_SIZE   0
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_Qmin 1196
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_Qmin_SIZE   3
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_Cell_selection_params 1113
#define CSN1_Add_Iu_Mode_Only_Cell_List_struct_Cell_selection_params_SIZE   0
#define CSN1_Additional_access_technologies_struct__8PSK_Power_Class 1342
#define CSN1_Additional_access_technologies_struct__8PSK_Power_Class_SIZE   2
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C1 1803
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C1_SIZE   8
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C2 1804
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C2_SIZE   8
#define CSN1_CCN_Measurement_Report_struct_INTERFERENCE_SERVING_CELL 711
#define CSN1_CCN_Measurement_Report_struct_INTERFERENCE_SERVING_CELL_SIZE   6
#define CSN1_CCN_Measurement_Report_struct_NUMBER_OF_NC_MEASUREMENTS 712
#define CSN1_CCN_Measurement_Report_struct_NUMBER_OF_NC_MEASUREMENTS_SIZE   3
#define CSN1_Channel_Description_struct_DOWNLINK_TIMESLOT_ALLOCATION 737
#define CSN1_Channel_Description_struct_DOWNLINK_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct_GMSK_MEAN_BEP 641
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct_GMSK_MEAN_BEP_SIZE   5
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN0 632
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN0_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN1 633
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN1_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN2 634
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN2_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN3 635
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN3_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN4 636
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN4_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN5 637
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN5_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN6 638
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN6_SIZE   4
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN7 639
#define CSN1_DLMC_Interference_Measurement_Report_Struct_I_LEVEL_TN7_SIZE   4
#define CSN1_Dynamic_ARFCN_Mapping_Description_struct_DM_CHANGE_MARK 2107
#define CSN1_Dynamic_ARFCN_Mapping_Description_struct_DM_CHANGE_MARK_SIZE   4
#define CSN1_Dynamic_Allocation_2_struct_EXTENDED_DYNAMIC_ALLOCATION 107
#define CSN1_Dynamic_Allocation_2_struct_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_PFI 1251
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_PFI_SIZE   7
#define CSN1_EGPRS_Packet_channel_request_message_content_RandomBits  59
#define CSN1_EGPRS_Packet_channel_request_message_content_RandomBits_SIZE   3
#define CSN1_EGPRS_Packet_channel_request_message_content_Signalling  66
#define CSN1_EGPRS_Packet_channel_request_message_content_Signalling_SIZE  11
#define CSN1_EXT_Measurement_Parameters_struct_EXT_MEASUREMENT_ORDER 1123
#define CSN1_EXT_Measurement_Parameters_struct_EXT_MEASUREMENT_ORDER_SIZE   2
#define CSN1_E_UTRAN_Target_Cell_struct_Physical_Layer_Cell_Identity 700
#define CSN1_E_UTRAN_Target_Cell_struct_Physical_Layer_Cell_Identity_SIZE   9
#define CSN1_Extension_Information_12_48_MTTI_DOWNLINK_ASSIGNMENT_C1 2498
#define CSN1_Extension_Information_12_48_MTTI_DOWNLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Extension_Information_12_48_MTTI_DOWNLINK_ASSIGNMENT_C2 2499
#define CSN1_Extension_Information_12_48_MTTI_DOWNLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Extension_Information_12_64_MTTI_DOWNLINK_ASSIGNMENT_C1 2477
#define CSN1_Extension_Information_12_64_MTTI_DOWNLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Extension_Information_12_64_MTTI_DOWNLINK_ASSIGNMENT_C2 2478
#define CSN1_Extension_Information_12_64_MTTI_DOWNLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_RESELECT_OFFSET 331
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_Session_Parameters_List 2438
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_Session_Parameters_List_SIZE   0
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY 774
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY_SIZE   1
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_BSIC 987
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_BSIC_SIZE   6
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_FREQ_LIST_NUMBER 1000
#define CSN1_MBMS_p_t_m_Frequency_Parameters_struct_FREQ_LIST_NUMBER_SIZE   2
#define CSN1_MBMS_p_t_m_channel_description_struct_EGPRS_Window_Size 2283
#define CSN1_MBMS_p_t_m_channel_description_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_MBMS_p_t_m_channel_description_struct_NPM_Transfer_Time 2284
#define CSN1_MBMS_p_t_m_channel_description_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_Multiple_Downlink_Assignment_struct_TIMESLOT_ALLOCATION 975
#define CSN1_Multiple_Downlink_Assignment_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Multiple_Uplink_Assignment_struct_Uplink_TBF_Assignment 1247
#define CSN1_Multiple_Uplink_Assignment_struct_Uplink_TBF_Assignment_SIZE   0
#define CSN1_NC_Measurement_Parameters_struct_bis_NC__NON_DRX_PERIOD 1523
#define CSN1_NC_Measurement_Parameters_struct_bis_NC__NON_DRX_PERIOD_SIZE   3
#define CSN1_PBCCH_information_struct_Neighbour_MBMS_Bearer_Identity 1018
#define CSN1_PBCCH_information_struct_Neighbour_MBMS_Bearer_Identity_SIZE   0
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_Info 2335
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_Info_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Selected_PLMN_Index 2411
#define CSN1_PS_Handover_Command_message_content_Selected_PLMN_Index_SIZE   3
#define CSN1_PS_Handover_Command_message_content_Uplink_RLC_Entity_2 2405
#define CSN1_PS_Handover_Command_message_content_Uplink_RLC_Entity_2_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Uplink_RLC_Entity_3 2406
#define CSN1_PS_Handover_Command_message_content_Uplink_RLC_Entity_3_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Downlink_RLC_Entity_2 2236
#define CSN1_Packet_CS_Release_message_content_Downlink_RLC_Entity_2_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Downlink_RLC_Entity_3 2237
#define CSN1_Packet_CS_Release_message_content_Downlink_RLC_Entity_3_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_BA_USED 705
#define CSN1_Packet_Cell_Change_Notification_message_content_BA_USED_SIZE   1
#define CSN1_Packet_Cell_Change_Order_message_content_Message_escape 3231
#define CSN1_Packet_Cell_Change_Order_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Control_Acknowledgement_11bit_a_content_CTRL_ACK 292
#define CSN1_Packet_Control_Acknowledgement_11bit_a_content_CTRL_ACK_SIZE   2
#define CSN1_Packet_Control_Acknowledgement_11bit_b_content_CTRL_ACK 294
#define CSN1_Packet_Control_Acknowledgement_11bit_b_content_CTRL_ACK_SIZE   2
#define CSN1_Packet_Control_Acknowledgement_message_content_CTRL_ACK 288
#define CSN1_Packet_Control_Acknowledgement_message_content_CTRL_ACK_SIZE   2
#define CSN1_Packet_DBPSCH_Assignment_message_content_Message_escape 3144
#define CSN1_Packet_DBPSCH_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Extended_SNS 1963
#define CSN1_Packet_Downlink_Assignment_message_content_Extended_SNS_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_RLC_Entity_2 1923
#define CSN1_Packet_Downlink_Assignment_message_content_RLC_Entity_2_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_RLC_Entity_3 1924
#define CSN1_Packet_Downlink_Assignment_message_content_RLC_Entity_3_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_LSA_Parameters 1971
#define CSN1_Packet_Measurement_Order_message_content_LSA_Parameters_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content__3G_CCN_ACTIVE 1979
#define CSN1_Packet_Measurement_Order_message_content__3G_CCN_ACTIVE_SIZE   1
#define CSN1_Packet_Neighbour_Cell_Data_message_content_CONTAINER_ID 840
#define CSN1_Packet_Neighbour_Cell_Data_message_content_CONTAINER_ID_SIZE   2
#define CSN1_Packet_PDCH_Release_message_content_TIMESLOTS_AVAILABLE 379
#define CSN1_Packet_PDCH_Release_message_content_TIMESLOTS_AVAILABLE_SIZE   8
#define CSN1_Packet_Paging_Request_message_content_PERSISTENCE_LEVEL 2416
#define CSN1_Packet_Paging_Request_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_Packet_Polling_Request_message_content_G_RNTI_extension 385
#define CSN1_Packet_Polling_Request_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Timeslot_Reconfigure_message_content_BEP_PERIOD2 2175
#define CSN1_Packet_Timeslot_Reconfigure_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Packet_Timeslot_Reconfigure_message_content_CONTROL_ACK 2138
#define CSN1_Packet_Timeslot_Reconfigure_message_content_CONTROL_ACK_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PDAN_Coding 2208
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PDAN_Coding_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_EMSR 2160
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_EMSR_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_FANR 2192
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_FANR_SIZE   0
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_TIMESLOT_NUMBER 229
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Packet_Uplink_Ack_Nack_message_content_TN_PDCH_pair_DTR 893
#define CSN1_Packet_Uplink_Ack_Nack_message_content_TN_PDCH_pair_DTR_SIZE   3
#define CSN1_Packet_Uplink_Assignment_message_content_Message_escape 3182
#define CSN1_Packet_Uplink_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap_Length 579
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap_Length_SIZE   7
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C1 1824
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C1_SIZE   8
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C2 1825
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_REPORTED_TIMESLOTS_C2_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_DOWNLINK_TFI_ASSIGNMENT 1849
#define CSN1_Single_Downlink_Assignment_2_IE_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Timeslot_description_2_struct_MS_TIMESLOT_ALLOCATION_C1 153
#define CSN1_Timeslot_description_2_struct_MS_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_Timeslot_description_2_struct_MS_TIMESLOT_ALLOCATION_C2 154
#define CSN1_Timeslot_description_2_struct_MS_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_P 1194
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_P_SIZE   4
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_PENALTY_TIME 1177
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__8PSK_MEAN_BEP 643
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__8PSK_MEAN_BEP_SIZE   5
#define CSN1_DLMC_Direct_encoding_2_struct_MA_Frequency_List_contents 1740
#define CSN1_DLMC_Direct_encoding_2_struct_MA_Frequency_List_contents_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_Cell_Identification 2485
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_Cell_Identification_SIZE  64
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_Cell_Identification 2464
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_Cell_Identification_SIZE  64
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_MS_TXPWR_MAX_CCH 2505
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_TFI_Assignment 614
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_TFI_Assignment_SIZE   5
#define CSN1_ENH_Measurement_parameters_struct_INVALID_BSIC_REPORTING 1095
#define CSN1_ENH_Measurement_parameters_struct_INVALID_BSIC_REPORTING_SIZE   1
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_REPORTING_QUANTITY  12
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_E_UTRAN_Parameters_IE_Repeated_E_UTRAN_Not_Allowed_Cells 2022
#define CSN1_E_UTRAN_Parameters_IE_Repeated_E_UTRAN_Not_Allowed_Cells_SIZE   0
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_Ignore 3107
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_Ignore_SIZE   0
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SCALE_ORD  19
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SCALE_ORD_SIZE   2
#define CSN1_GSM_target_cell_struct_Iu_Mode_Neighbour_Cell_Parameters 2305
#define CSN1_GSM_target_cell_struct_Iu_Mode_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_GSM_target_cell_struct_NC_Iu_MODE_ONLY_CAPABLE_CELL_LIST 2306
#define CSN1_GSM_target_cell_struct_NC_Iu_MODE_ONLY_CAPABLE_CELL_LIST_SIZE   0
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_MS_TXPWR_MAX_CCH 328
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_RXLEV_ACCESS_MIN 327
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_TEMPORARY_OFFSET 329
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_PENALTY_TIME 457
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_PENALTY_TIME_SIZE   5
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_FREQUENCY_DIFF 861
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_MBMS_p_t_m_channel_description_IE_DL_TIMESLOT_ALLOCATION 2437
#define CSN1_MBMS_p_t_m_channel_description_IE_DL_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Multiple_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C1 1772
#define CSN1_Multiple_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Multiple_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C2 1773
#define CSN1_Multiple_Downlink_Assignment_2_IE_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PR_MODE 1386
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PR_MODE_SIZE   1
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_PAGE_MODE 1602
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_PAGE_MODE_SIZE   2
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_RESEGMENT 1622
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_RESEGMENT_SIZE   1
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Resegment 1615
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Resegment_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_IE_Uplink_EGPRS_Window_Size 1788
#define CSN1_Multiple_Uplink_Assignment_2_IE_Uplink_EGPRS_Window_Size_SIZE   5
#define CSN1_Neighbouring_Cell_Report_struct_RESEL_CRITERIA_FULFILLED 765
#define CSN1_Neighbouring_Cell_Report_struct_RESEL_CRITERIA_FULFILLED_SIZE   1
#define CSN1_PDCH_Pairs_Description_IE_PDCH_pairs_configuration_error 3108
#define CSN1_PDCH_Pairs_Description_IE_PDCH_pairs_configuration_error_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Secondary_DL_TSC_Set 2413
#define CSN1_PS_Handover_Command_message_content_Secondary_DL_TSC_Set_SIZE   1
#define CSN1_PS_Handover_Radio_Resources_2_IE_CCN_Support_Description 2344
#define CSN1_PS_Handover_Radio_Resources_2_IE_CCN_Support_Description_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_Frequency_Parameters_C1 2345
#define CSN1_PS_Handover_Radio_Resources_2_IE_Frequency_Parameters_C1_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_Frequency_Parameters_C2 2346
#define CSN1_PS_Handover_Radio_Resources_2_IE_Frequency_Parameters_C2_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_CCN_Support_Description 2365
#define CSN1_PS_Handover_Radio_Resources_3_IE_CCN_Support_Description_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_Uplink_Control_Timeslot 2396
#define CSN1_PS_Handover_Radio_Resources_3_IE_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Packet_Application_Information_message_content_PAGE_MODE 546
#define CSN1_Packet_Application_Information_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_CS_Release_message_content_CHANNEL_CODING_COMMAND 2223
#define CSN1_Packet_CS_Release_message_content_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_Packet_CS_Release_message_content_EMSR_Additional_PFCs_1 2240
#define CSN1_Packet_CS_Release_message_content_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_Packet_CS_Release_message_content_EMSR_Additional_PFCs_2 2241
#define CSN1_Packet_CS_Release_message_content_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_Packet_CS_Release_message_content_EMSR_Additional_PFCs_3 2242
#define CSN1_Packet_CS_Release_message_content_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Secondary_DL_TSC_Value 2227
#define CSN1_Packet_CS_Release_message_content_Secondary_DL_TSC_Value_SIZE   3
#define CSN1_Packet_Cell_Change_Continue_message_content_CONTAINER_ID 300
#define CSN1_Packet_Cell_Change_Continue_message_content_CONTAINER_ID_SIZE   2
#define CSN1_Packet_Cell_Change_Failure_message_content_Bandwidth_FDD 677
#define CSN1_Packet_Cell_Change_Failure_message_content_Bandwidth_FDD_SIZE   3
#define CSN1_Packet_Cell_Change_Failure_message_content_Bandwidth_TDD 680
#define CSN1_Packet_Cell_Change_Failure_message_content_Bandwidth_TDD_SIZE   3
#define CSN1_Packet_Cell_Change_Notification_message_content_PMO_USED 707
#define CSN1_Packet_Cell_Change_Notification_message_content_PMO_USED_SIZE   1
#define CSN1_Packet_Cell_Change_Order_message_content_GSM_target_cell 2295
#define CSN1_Packet_Cell_Change_Order_message_content_GSM_target_cell_SIZE   0
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Timeslot_Number 352
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Timeslot_Number_SIZE   3
#define CSN1_Packet_Downlink_Assignment_message_content_PTCCH_CARRIER 1961
#define CSN1_Packet_Downlink_Assignment_message_content_PTCCH_CARRIER_SIZE   4
#define CSN1_Packet_Paging_Request_message_content_Repeated_Page_info 2418
#define CSN1_Packet_Paging_Request_message_content_Repeated_Page_info_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_G_RNTI_extension 2089
#define CSN1_Packet_Resource_Request_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Serving_Cell_Data_message_content_CONTAINER_INDEX 849
#define CSN1_Packet_Serving_Cell_Data_message_content_CONTAINER_INDEX_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Extended_SNS 2209
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Extended_SNS_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Pulse_Format 2198
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Pulse_Format_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Assignment_Info 1584
#define CSN1_Packet_Uplink_Assignment_message_content_Assignment_Info_SIZE   3
#define CSN1_Packet_Uplink_Assignment_message_content_Primary_TSC_Set 1563
#define CSN1_Packet_Uplink_Assignment_message_content_Primary_TSC_Set_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_message_content 1545
#define CSN1_Packet_Uplink_Assignment_message_content_message_content_SIZE   0
#define CSN1_Packet_channel_request_11_bit_message_content_RandomBits  44
#define CSN1_Packet_channel_request_11_bit_message_content_RandomBits_SIZE   3
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BCCH_FREQ_NCELL 827
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BCCH_FREQ_NCELL_SIZE   5
#define CSN1_Access_Technologies_Request_struct_Access_Technology_Type 106
#define CSN1_Access_Technologies_Request_struct_Access_Technology_Type_SIZE   4
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_TBF_TIMESLOT_ALLOCATION 1807
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_TBF_TIMESLOT_ALLOCATION_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_P0 899
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_P0_SIZE   4
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_GMSK_CV_BEP 184
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_GMSK_CV_BEP_SIZE   3
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_QPSK_CV_BEP 188
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_QPSK_CV_BEP_SIZE   3
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_PFI 1372
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_PFI_SIZE   7
#define CSN1_E_UTRAN_Measurement_Report_struct_E_UTRAN_FREQUENCY_INDEX  80
#define CSN1_E_UTRAN_Measurement_Report_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_E_UTRAN_Parameters_IE_GPRS_E_UTRAN_Measurement_Parameters 2005
#define CSN1_E_UTRAN_Parameters_IE_GPRS_E_UTRAN_Measurement_Parameters_SIZE   0
#define CSN1_E_UTRAN_Parameters_IE_Repeated_E_UTRAN_PCID_to_TA_mapping 2025
#define CSN1_E_UTRAN_Parameters_IE_Repeated_E_UTRAN_PCID_to_TA_mapping_SIZE   0
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_SI13Alt_PBCCH_LOCATION 333
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_SI13Alt_PBCCH_LOCATION_SIZE   0
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_CELL_BAR_QUALIFY_3 452
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_CELL_BAR_QUALIFY_3_SIZE   2
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_START_FREQUENCY 857
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_START_FREQUENCY_SIZE  10
#define CSN1_MBMS_Assignment_Distribution_message_content_Reject_cause 2272
#define CSN1_MBMS_Assignment_Distribution_message_content_Reject_cause_SIZE   2
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_p_t_m_channel_description 2435
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_p_t_m_channel_description_SIZE   0
#define CSN1_MS_RA_capability_value_part_struct_Access_Technology_Type 1286
#define CSN1_MS_RA_capability_value_part_struct_Access_Technology_Type_SIZE   4
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Global_TFI 1606
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_Multiple_Uplink_Assignment_2_struct_Uplink_TBF_Assignment 1692
#define CSN1_Multiple_Uplink_Assignment_2_struct_Uplink_TBF_Assignment_SIZE   0
#define CSN1_PSI3_quater_message_content_GPRS_REP_PRIORITY_Description 1187
#define CSN1_PSI3_quater_message_content_GPRS_REP_PRIORITY_Description_SIZE   0
#define CSN1_PSI3_ter_message_content_Real_Time_Difference_Description 866
#define CSN1_PSI3_ter_message_content_Real_Time_Difference_Description_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Downlink_RLC_Entity_2 2403
#define CSN1_PS_Handover_Command_message_content_Downlink_RLC_Entity_2_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Downlink_RLC_Entity_3 2404
#define CSN1_PS_Handover_Command_message_content_Downlink_RLC_Entity_3_SIZE   0
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_2_Info 2336
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_2_Info_SIZE   0
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_3_Info 2358
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_3_Info_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_UPLINK_EGPRS_Window_Size 2387
#define CSN1_PS_Handover_Radio_Resources_3_IE_UPLINK_EGPRS_Window_Size_SIZE   5
#define CSN1_PS_Handover_Radio_Resources_3_IE_Uplink_NPM_Transfer_Time 2391
#define CSN1_PS_Handover_Radio_Resources_3_IE_Uplink_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_CS_Command_message_content_Distribution_part_error 3136
#define CSN1_Packet_CS_Command_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Distribution_part_error 3223
#define CSN1_Packet_CS_Release_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Frequency_Parameters_C1 2244
#define CSN1_Packet_CS_Release_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Frequency_Parameters_C2 2245
#define CSN1_Packet_CS_Release_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Packet_Cell_Change_Failure_message_content_Cell_Parameter 681
#define CSN1_Packet_Cell_Change_Failure_message_content_Cell_Parameter_SIZE   7
#define CSN1_Packet_Cell_Change_Order_message_content_G_RNTI_extension 2326
#define CSN1_Packet_Cell_Change_Order_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_Message_escape 3205
#define CSN1_Packet_Downlink_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_G_RNTI_extension 1975
#define CSN1_Packet_Measurement_Order_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_SI_Status_message_content_Received_SI_Message_List 414
#define CSN1_Packet_SI_Status_message_content_Received_SI_Message_List_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_EMSR 2156
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_EMSR_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PTCCH_CARRIER 2207
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PTCCH_CARRIER_SIZE   4
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RTTI_USF_MODE 2176
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RTTI_USF_MODE_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_G_RNTI_extension 1559
#define CSN1_Packet_Uplink_Assignment_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_channel_request_11_bit_message_content_Cell_Update  49
#define CSN1_Packet_channel_request_11_bit_message_content_Cell_Update_SIZE  11
#define CSN1_Physical_information_message_content_TIMING_ADVANCE_VALUE 520
#define CSN1_Physical_information_message_content_TIMING_ADVANCE_VALUE_SIZE   8
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_NR_OF_FDD_CELLS 315
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_NR_OF_FDD_CELLS_SIZE   5
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_NR_OF_TDD_CELLS 321
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_NR_OF_TDD_CELLS_SIZE   5
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command 935
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_Uplink_EGPRS_Window_Size 1801
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_Uplink_EGPRS_Window_Size_SIZE   5
#define CSN1_COMPACT_Neighbour_Cell_params_2_struct_CELL_PARAMS_POINTER 1168
#define CSN1_COMPACT_Neighbour_Cell_params_2_struct_CELL_PARAMS_POINTER_SIZE   2
#define CSN1_COMPACT_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS 1508
#define CSN1_COMPACT_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_PRIORITY_CLASS 1174
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_PRIORITY_CLASS_SIZE   3
#define CSN1_DLMC_Channel_Quality_Report_DLMC_Interference_Measurements 631
#define CSN1_DLMC_Channel_Quality_Report_DLMC_Interference_Measurements_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_GPRS_MS_TXPWR_MAX_CCH 2487
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_GPRS_MS_TXPWR_MAX_CCH 2466
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_Uplink_Control_Timeslot 2512
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_EVENT_BASED_FANR 617
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_EVENT_BASED_FANR_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_bis_Uplink_Control_Timeslot 981
#define CSN1_Downlink_TBF_assignment_struct_bis_Uplink_Control_Timeslot_SIZE   3
#define CSN1_EGPRS_Ack_Nack_Description_struct_COMPRESSED_BITMAP_LENGTH 163
#define CSN1_EGPRS_Ack_Nack_Description_struct_COMPRESSED_BITMAP_LENGTH_SIZE   7
#define CSN1_EGPRS_Ack_Nack_Description_struct_STARTING_SEQUENCE_NUMBER 162
#define CSN1_EGPRS_Ack_Nack_Description_struct_STARTING_SEQUENCE_NUMBER_SIZE  11
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__8PSK_CV_BEP 186
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__8PSK_CV_BEP_SIZE   3
#define CSN1_EPD_A_N_Extension_Info_Iu_mode_Channel_Request_Description 1888
#define CSN1_EPD_A_N_Extension_Info_Iu_mode_Channel_Request_Description_SIZE   0
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_SAME_RA_AS_SERVING_CELL 326
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH 860
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_MBMS_Assignment_Non_distribution_message_content_PAGE_MODE 2249
#define CSN1_MBMS_Assignment_Non_distribution_message_content_PAGE_MODE_SIZE   2
#define CSN1_MBMS_MS_ID_Assignment_message_content_MBMS_Bearer_Identity 536
#define CSN1_MBMS_MS_ID_Assignment_message_content_MBMS_Bearer_Identity_SIZE   0
#define CSN1_MBMS_Service_Request_message_content_MBMS_Session_Identity 530
#define CSN1_MBMS_Service_Request_message_content_MBMS_Session_Identity_SIZE   8
#define CSN1_MBMS_Session_Parameters_List_IE_Estimated_Session_Duration 2441
#define CSN1_MBMS_Session_Parameters_List_IE_Estimated_Session_Duration_SIZE   8
#define CSN1_MBMS_p_t_m_channel_description_struct_Frequency_Parameters 2279
#define CSN1_MBMS_p_t_m_channel_description_struct_Frequency_Parameters_SIZE   0
#define CSN1_MBMS_p_t_m_channel_description_struct_MBMS_Bearer_Identity 2282
#define CSN1_MBMS_p_t_m_channel_description_struct_MBMS_Bearer_Identity_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PAGE_MODE 1378
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PAGE_MODE_SIZE   2
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_BEP_PERIOD2 1617
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_TLLI_G_RNTI 1604
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Multiple_Uplink_Assignment_2_IE_BTTI_Uplink_TBF_Assignment 1796
#define CSN1_Multiple_Uplink_Assignment_2_IE_BTTI_Uplink_TBF_Assignment_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_IE_RTTI_Uplink_TBF_Assignment 1817
#define CSN1_Multiple_Uplink_Assignment_2_IE_RTTI_Uplink_TBF_Assignment_SIZE   0
#define CSN1_NC_Measurement_Parameters_struct_bis_NC_REPORTING_PERIOD_I 1524
#define CSN1_NC_Measurement_Parameters_struct_bis_NC_REPORTING_PERIOD_I_SIZE   3
#define CSN1_NC_Measurement_Parameters_struct_bis_NC_REPORTING_PERIOD_T 1525
#define CSN1_NC_Measurement_Parameters_struct_bis_NC_REPORTING_PERIOD_T_SIZE   3
#define CSN1_NC_Measurement_Parameters_struct_bis_NETWORK_CONTROL_ORDER 1522
#define CSN1_NC_Measurement_Parameters_struct_bis_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_PSI3_bis_message_content_COMPACT_Neighbour_Cell_Parameters 1167
#define CSN1_PSI3_bis_message_content_COMPACT_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_PSI3_bis_message_content_Iu_Mode_Neighbour_Cell_Parameters 1181
#define CSN1_PSI3_bis_message_content_Iu_Mode_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_PS_Handover_Command_message_content_EMSR_Additional_PFCs_1 2408
#define CSN1_PS_Handover_Command_message_content_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_PS_Handover_Command_message_content_EMSR_Additional_PFCs_2 2409
#define CSN1_PS_Handover_Command_message_content_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_PS_Handover_Command_message_content_EMSR_Additional_PFCs_3 2410
#define CSN1_PS_Handover_Command_message_content_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Secondary_DL_TSC_Value 2414
#define CSN1_PS_Handover_Command_message_content_Secondary_DL_TSC_Value_SIZE   3
#define CSN1_PS_Handover_Radio_Resources_IE_EXTENDED_DYNAMIC_ALLOCATION 1722
#define CSN1_PS_Handover_Radio_Resources_IE_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Packet_CS_Release_message_content_Uplink_EGPRS_Window_Size 2233
#define CSN1_Packet_CS_Release_message_content_Uplink_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_Cell_Change_Failure_message_content_SCRAMBLING_CODE 678
#define CSN1_Packet_Cell_Change_Failure_message_content_SCRAMBLING_CODE_SIZE   9
#define CSN1_Packet_Cell_Change_Notification_message_content_Global_TFI 693
#define CSN1_Packet_Cell_Change_Notification_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Control_Acknowledgement_message_content_TLLI_G_RNTI 287
#define CSN1_Packet_Control_Acknowledgement_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_DBPSCH_Assignment_message_content_PERSISTENCE_LEVEL 731
#define CSN1_Packet_DBPSCH_Assignment_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_MESSAGE_TYPE 502
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_MESSAGE_TYPE_SIZE   6
#define CSN1_Packet_Downlink_Assignment_message_content_Assignment_Info 1932
#define CSN1_Packet_Downlink_Assignment_message_content_Assignment_Info_SIZE   3
#define CSN1_Packet_Downlink_Assignment_message_content_Primary_TSC_Set 1928
#define CSN1_Packet_Downlink_Assignment_message_content_Primary_TSC_Set_SIZE   1
#define CSN1_Packet_MBMS_Announcement_message_content_RESTRICTION_TIMER 2290
#define CSN1_Packet_MBMS_Announcement_message_content_RESTRICTION_TIMER_SIZE   4
#define CSN1_Packet_Measurement_Report_message_content_G_RNTI_extension 809
#define CSN1_Packet_Measurement_Report_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Measurement_Report_message_content_PSI3_CHANGE_MARK 803
#define CSN1_Packet_Measurement_Report_message_content_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_Packet_Measurement_Report_message_content_PSI5_CHANGE_MARK 778
#define CSN1_Packet_Measurement_Report_message_content_PSI5_CHANGE_MARK_SIZE   2
#define CSN1_Packet_Neighbour_Cell_Data_message_content_CONTAINER_INDEX 842
#define CSN1_Packet_Neighbour_Cell_Data_message_content_CONTAINER_INDEX_SIZE   5
#define CSN1_Packet_TBF_Release_message_content_Distribution_part_error 3132
#define CSN1_Packet_TBF_Release_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Message_escape 3216
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_EGPRS_Window_Size 1570
#define CSN1_Packet_Uplink_Assignment_message_content_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_Uplink_Assignment_message_content_NPM_Transfer_Time 1575
#define CSN1_Packet_Uplink_Assignment_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_Uplink_Assignment_message_content_PERSISTENCE_LEVEL 1540
#define CSN1_Packet_Uplink_Assignment_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_Packet_channel_request_11_bit_message_content_MM_Procedure  50
#define CSN1_Packet_channel_request_11_bit_message_content_MM_Procedure_SIZE  11
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_Uplink_EGPRS_Window_Size 1822
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_Uplink_EGPRS_Window_Size_SIZE   5
#define CSN1_Single_Downlink_Assignment_2_IE_Downlink_EGPRS_Window_Size 1835
#define CSN1_Single_Downlink_Assignment_2_IE_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_Single_Uplink_Assignment_2_IE_EGPRS_Channel_Coding_Command 1853
#define CSN1_Single_Uplink_Assignment_2_IE_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_RESELECT_OFFSET 1178
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_NPM_Transfer_Time 616
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_NPM_Transfer_Time_SIZE   5
#define CSN1_Downlink_TBF_assignment_2_struct_Downlink_EGPRS_Window_Size 365
#define CSN1_Downlink_TBF_assignment_2_struct_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_GMSK_MEAN_BEP 183
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_GMSK_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_QPSK_MEAN_BEP 187
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE_QPSK_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI 1882
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_EGPRS_Packet_channel_request_message_content_Emergency_call  69
#define CSN1_EGPRS_Packet_channel_request_message_content_Emergency_call_SIZE  11
#define CSN1_EGPRS_Packet_channel_request_message_content_MultislotClass  57
#define CSN1_EGPRS_Packet_channel_request_message_content_MultislotClass_SIZE   5
#define CSN1_EGPRS_Packet_channel_request_message_content_NumberOfBlocks  61
#define CSN1_EGPRS_Packet_channel_request_message_content_NumberOfBlocks_SIZE   3
#define CSN1_EPD_A_N_Extension_Info_Extended_Channel_Request_Description 1891
#define CSN1_EPD_A_N_Extension_Info_Extended_Channel_Request_Description_SIZE   0
#define CSN1_E_UTRAN_Target_cell_with_extended_EARFCN_IE_EARFCN_extended 279
#define CSN1_E_UTRAN_Target_cell_with_extended_EARFCN_IE_EARFCN_extended_SIZE  18
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_P  30
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_P_SIZE   4
#define CSN1_Global_Packet_Timing_Advance_IE_UPLINK_TIMING_ADVANCE_INDEX 231
#define CSN1_Global_Packet_Timing_Advance_IE_UPLINK_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_RESELECT_OFFSET 458
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_RESELECT_OFFSET_SIZE   5
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Global_TFI 2250
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Global_TFI_SIZE   6
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_Ack_Nack_Description 776
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_Ack_Nack_Description_SIZE  72
#define CSN1_MBMS_MS_ID_Assignment_message_content_Packet_Timing_Advance 538
#define CSN1_MBMS_MS_ID_Assignment_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_MBMS_bearer_description_struct_DOWNLINK_TIMESLOT_ALLOCATION 1704
#define CSN1_MBMS_bearer_description_struct_DOWNLINK_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Multiple_Downlink_Assignment_struct_Downlink_TBF_assignment 977
#define CSN1_Multiple_Downlink_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Multiple_Downlink_Assignment_struct_Uplink_Control_Timeslot 976
#define CSN1_Multiple_Downlink_Assignment_struct_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION 1396
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Global_TFI 1383
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PR_MODE_C1 1408
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PR_MODE_C1_SIZE   1
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PR_MODE_C2 1410
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PR_MODE_C2_SIZE   1
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_PAGE_MODE 1649
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_PAGE_MODE_SIZE   2
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_RESEGMENT 1658
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_RESEGMENT_SIZE   1
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Pulse_Format 1648
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Pulse_Format_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_IE_EXTENDED_DYNAMIC_ALLOCATION 1789
#define CSN1_Multiple_Uplink_Assignment_2_IE_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_IE_Global_Timeslot_description 1795
#define CSN1_Multiple_Uplink_Assignment_2_IE_Global_Timeslot_description_SIZE   0
#define CSN1_PSI3_message_content_Iu_mode_Only_Neighbour_Cell_Parameters 1516
#define CSN1_PSI3_message_content_Iu_mode_Only_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_PSI3_quater_message_content__3G_Neighbour_Cells_Description 1188
#define CSN1_PSI3_quater_message_content__3G_Neighbour_Cells_Description_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Distribution_part_error 3239
#define CSN1_PS_Handover_Command_message_content_Distribution_part_error_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_Frequency_Parameters_error 3234
#define CSN1_PS_Handover_Radio_Resources_2_IE_Frequency_Parameters_error_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_Downlink_NPM_Transfer_Time 2379
#define CSN1_PS_Handover_Radio_Resources_3_IE_Downlink_NPM_Transfer_Time_SIZE   5
#define CSN1_PS_Handover_Radio_Resources_IE_Global_Packet_Timing_Advance 1720
#define CSN1_PS_Handover_Radio_Resources_IE_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_Packet_Cell_Change_Failure_message_content_G_RNTI_extension 683
#define CSN1_Packet_Cell_Change_Failure_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Cell_Change_Notification_message_content__3G_BA_USED 716
#define CSN1_Packet_Cell_Change_Notification_message_content__3G_BA_USED_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_EVENT_BASED_FANR 1952
#define CSN1_Packet_Downlink_Assignment_message_content_EVENT_BASED_FANR_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_G_RNTI_extension 1917
#define CSN1_Packet_Downlink_Assignment_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_MBMS_Announcement_message_content_MPRACH_description 2285
#define CSN1_Packet_MBMS_Announcement_message_content_MPRACH_description_SIZE   0
#define CSN1_Packet_PDCH_Release_message_content_Distribution_part_error 3114
#define CSN1_Packet_PDCH_Release_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_PSI_Status_message_content_Received_PSI_Message_List 402
#define CSN1_Packet_PSI_Status_message_content_Received_PSI_Message_List_SIZE   0
#define CSN1_Packet_Paging_Request_message_content_Repeated_Iu_Page_info 2425
#define CSN1_Packet_Paging_Request_message_content_Repeated_Iu_Page_info_SIZE   0
#define CSN1_Packet_Request_Reference_IE_RANDOM_ACCESS_INFORMATION_value 225
#define CSN1_Packet_Request_Reference_IE_RANDOM_ACCESS_INFORMATION_value_SIZE  11
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Assignment_Info 2174
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Assignment_Info_SIZE   3
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Primary_TSC_Set 2161
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Primary_TSC_Set_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_RLC_MODE 2150
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_RLC_MODE_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Ack_Nack_Description 896
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Ack_Nack_Description_SIZE  72
#define CSN1_Packet_Uplink_Assignment_message_content_COMPACT_reduced_MA 1566
#define CSN1_Packet_Uplink_Assignment_message_content_COMPACT_reduced_MA_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Dynamic_Allocation 1550
#define CSN1_Packet_Uplink_Assignment_message_content_Dynamic_Allocation_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_EMST_NW_Capability 1580
#define CSN1_Packet_Uplink_Assignment_message_content_EMST_NW_Capability_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_REPORTED_TIMESLOTS 1601
#define CSN1_Packet_Uplink_Assignment_message_content_REPORTED_TIMESLOTS_SIZE   8
#define CSN1_Packet_Uplink_Assignment_message_content_Uplink_EGPRS_Level 1595
#define CSN1_Packet_Uplink_Assignment_message_content_Uplink_EGPRS_Level_SIZE   2
#define CSN1_Packet_channel_request_11_bit_message_content_Page_Response  48
#define CSN1_Packet_channel_request_11_bit_message_content_Page_Response_SIZE  11
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_Not_Allowed_Cells 2023
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_Not_Allowed_Cells_SIZE   0
#define CSN1_Uplink_TBF_Assignment_2_struct_EGPRS_Channel_Coding_Command 943
#define CSN1_Uplink_TBF_Assignment_2_struct_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_FDD_Description 1099
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_FDD_Description_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_TDD_Description 1100
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_TDD_Description_SIZE   0
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_TLLI 2213
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_TLLI_SIZE  32
#define CSN1_Additional_access_technologies_struct_Access_Technology_Type 1340
#define CSN1_Additional_access_technologies_struct_Access_Technology_Type_SIZE   4
#define CSN1_CBCH_Channel_Description_struct_Channel_type_and_TDMA_offset 2103
#define CSN1_CBCH_Channel_Description_struct_Channel_type_and_TDMA_offset_SIZE   5
#define CSN1_CCCH_Access_Information_struct_GPRS_Power_Control_Parameters 2121
#define CSN1_CCCH_Access_Information_struct_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_MS_TXPWR_MAX_CCH 1173
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_RXLEV_ACCESS_MIN 1172
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_TEMPORARY_OFFSET 1176
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__16QAM__NSR_CV_BEP 646
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__16QAM__NSR_CV_BEP_SIZE   3
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__32QAM__NSR_CV_BEP 648
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__32QAM__NSR_CV_BEP_SIZE   3
#define CSN1_Dual_Carrier_Direct_encoding_1_struct_GPRS_Mobile_Allocation 1271
#define CSN1_Dual_Carrier_Direct_encoding_1_struct_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_P0 954
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_P0_SIZE   4
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_ALPHA 905
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_ALPHA_SIZE   4
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__8PSK_MEAN_BEP 185
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__8PSK_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_IE_BEP_MEASUREMENTS 549
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_IE_BEP_MEASUREMENTS_SIZE   0
#define CSN1_EPD_A_N_Extension_Info_Secondary_Dual_Carrier_Channel_Report 1893
#define CSN1_EPD_A_N_Extension_Info_Secondary_Dual_Carrier_Channel_Report_SIZE   0
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_REP_QUANT 2007
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_REP_QUANT_SIZE   1
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_Qsearch_P_E_UTRAN 2006
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_Qsearch_P_E_UTRAN_SIZE   4
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_MS_TXPWR_MAX_CCH 455
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_RXLEV_ACCESS_MIN 454
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_TEMPORARY_OFFSET 456
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_GPRS_TEMPORARY_OFFSET_SIZE   3
#define CSN1_MBMS_Assignment_Non_distribution_message_content_TLLI_G_RNTI 2251
#define CSN1_MBMS_Assignment_Non_distribution_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_MBMS_Frequency_List_struct_Length_of_Frequency_List_contents 994
#define CSN1_MBMS_Frequency_List_struct_Length_of_Frequency_List_contents_SIZE   4
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_PAGE_MODE 985
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_PAGE_MODE_SIZE   2
#define CSN1_MBMS_p_t_m_channel_description_struct_DL_TIMESLOT_ALLOCATION 2280
#define CSN1_MBMS_p_t_m_channel_description_struct_DL_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Multiple_Downlink_Assignment_2_IE_Downlink_EGPRS_Window_Size 1762
#define CSN1_Multiple_Downlink_Assignment_2_IE_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_BEP_PERIOD2 1392
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_TLLI_G_RNTI 1380
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_GLOBAL_TFI 1650
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_Multiple_Uplink_Assignment_2_IE_EGPRS_Channel_Coding_Command 1786
#define CSN1_Multiple_Uplink_Assignment_2_IE_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Packet_Access_Reject_message_content_Distribution_part_error 3141
#define CSN1_Packet_Access_Reject_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Downlink_EGPRS_Window_Size 2229
#define CSN1_Packet_CS_Release_message_content_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_CS_Release_message_content_Frequency_parameters_error 3220
#define CSN1_Packet_CS_Release_message_content_Frequency_parameters_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Multiple_Uplink_Assignment 2224
#define CSN1_Packet_CS_Release_message_content_Multiple_Uplink_Assignment_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_PCCN_SENDING 708
#define CSN1_Packet_Cell_Change_Notification_message_content_PCCN_SENDING_SIZE   1
#define CSN1_Packet_Cell_Change_Order_message_content_E_UTRAN_Target_cell 2327
#define CSN1_Packet_Cell_Change_Order_message_content_E_UTRAN_Target_cell_SIZE   0
#define CSN1_Packet_DBPSCH_Assignment_message_content_CHANNEL_DESCRIPTION 735
#define CSN1_Packet_DBPSCH_Assignment_message_content_CHANNEL_DESCRIPTION_SIZE   0
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_MESSAGE_TYPE 355
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_MESSAGE_TYPE_SIZE   6
#define CSN1_Packet_Downlink_Assignment_message_content_EGPRS_Window_Size 1911
#define CSN1_Packet_Downlink_Assignment_message_content_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_NPM_Transfer_Time 1921
#define CSN1_Packet_Downlink_Assignment_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_PERSISTENCE_LEVEL 1896
#define CSN1_Packet_Downlink_Assignment_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_Packet_Downlink_Assignment_message_content_TBF_Starting_Time 1910
#define CSN1_Packet_Downlink_Assignment_message_content_TBF_Starting_Time_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content__3G_CSG_Description 2029
#define CSN1_Packet_Measurement_Order_message_content__3G_CSG_Description_SIZE   0
#define CSN1_Packet_Mobile_TBF_Status_message_content_STATUS_MESSAGE_TYPE 373
#define CSN1_Packet_Mobile_TBF_Status_message_content_STATUS_MESSAGE_TYPE_SIZE   6
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EVENT_BASED_FANR 2191
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EVENT_BASED_FANR_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Packet_Timing_Advance 885
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_Packet_channel_request_11_bit_message_content_Emergency_call  54
#define CSN1_Packet_channel_request_11_bit_message_content_Emergency_call_SIZE  11
#define CSN1_Packet_channel_request_11_bit_message_content_MultislotClass  42
#define CSN1_Packet_channel_request_11_bit_message_content_MultislotClass_SIZE   5
#define CSN1_Packet_channel_request_11_bit_message_content_NumberOfBlocks  46
#define CSN1_Packet_channel_request_11_bit_message_content_NumberOfBlocks_SIZE   3
#define CSN1_Real_Time_Difference_Description_struct_Cell_Index_Start_RTD 867
#define CSN1_Real_Time_Difference_Description_struct_Cell_Index_Start_RTD_SIZE   7
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_E_UTRAN_PRIORITY 2018
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_Repeated_Page_info_struct_Length_of_Mobile_Identity_contents 2419
#define CSN1_Repeated_Page_info_struct_Length_of_Mobile_Identity_contents_SIZE   4
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_UTRAN_PRIORITY 1999
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_UTRAN_PRIORITY_SIZE   3
#define CSN1__3G_Neighbour_Cells_Description_struct_UTRAN_FDD_Description 1191
#define CSN1__3G_Neighbour_Cells_Description_struct_UTRAN_FDD_Description_SIZE   0
#define CSN1__3G_Neighbour_Cells_Description_struct_UTRAN_TDD_Description 1192
#define CSN1__3G_Neighbour_Cells_Description_struct_UTRAN_TDD_Description_SIZE   0
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GUAR_CONSTANT_PWR_BLKS 1179
#define CSN1_COMPACT_Neighbour_parameter_set_struct_GUAR_CONSTANT_PWR_BLKS_SIZE   2
#define CSN1_Content_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability 1321
#define CSN1_Content_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Content_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability 1319
#define CSN1_Content_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents 1264
#define CSN1_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents_SIZE   4
#define CSN1_Downlink_TBF_assignment_struct_bis_Downlink_EGPRS_Window_Size 984
#define CSN1_Downlink_TBF_assignment_struct_bis_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_E_UTRAN_FREQUENCY_INDEX  10
#define CSN1_E_UTRAN_CCN_Measurement_Report_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_IE_DEFAULT_E_UTRAN_PRIORITY 659
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_IE_DEFAULT_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_Global_Packet_Timing_Advance_IE_DOWNLINK_TIMING_ADVANCE_INDEX 233
#define CSN1_Global_Packet_Timing_Advance_IE_DOWNLINK_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_SI13Alt_PBCCH_Location 460
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_SI13Alt_PBCCH_Location_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Reject_cause 2265
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Reject_cause_SIZE   2
#define CSN1_MBMS_MS_ID_Assignment_message_content_Distribution_part_error 3139
#define CSN1_MBMS_MS_ID_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Report_struct_Neighbouring_Cell_Report 763
#define CSN1_MBMS_Neighbouring_Cell_Report_struct_Neighbouring_Cell_Report_SIZE   0
#define CSN1_MBMS_Service_Request_message_content_MS_ID_Request_Indication 531
#define CSN1_MBMS_Service_Request_message_content_MS_ID_Request_Indication_SIZE   1
#define CSN1_MBMS_bearer_description_struct_Length_of_MBMS_Bearer_Identity 1705
#define CSN1_MBMS_bearer_description_struct_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_BEP_PERIOD2 1662
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_BEP_PERIOD2_SIZE   4
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Message_escape 3187
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_struct_EXTENDED_DYNAMIC_ALLOCATION 1242
#define CSN1_Multiple_Uplink_Assignment_struct_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_struct_Global_Timeslot_description 1246
#define CSN1_Multiple_Uplink_Assignment_struct_Global_Timeslot_description_SIZE   0
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_Info_Error 3235
#define CSN1_PS_Handover_Command_message_content_PS_Handover_RR_Info_Error_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_Global_Packet_Timing_Advance 2349
#define CSN1_PS_Handover_Radio_Resources_2_IE_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_EGPRS_Channel_Coding_Command 2384
#define CSN1_PS_Handover_Radio_Resources_3_IE_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_PS_Handover_Radio_Resources_3_IE_Global_Packet_Timing_Advance 2372
#define CSN1_PS_Handover_Radio_Resources_3_IE_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_IE_Packet_Extended_Timing_Advance 1721
#define CSN1_PS_Handover_Radio_Resources_IE_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_CS_Command_message_content_Non_distribution_part_error 3134
#define CSN1_Packet_CS_Command_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Non_distribution_part_error 3219
#define CSN1_Packet_CS_Release_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_Downlink_eTFI 727
#define CSN1_Packet_Cell_Change_Notification_message_content_Downlink_eTFI_SIZE   3
#define CSN1_Packet_DBPSCH_Assignment_message_content_TIMING_ADVANCE_VALUE 749
#define CSN1_Packet_DBPSCH_Assignment_message_content_TIMING_ADVANCE_VALUE_SIZE   8
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Ack_Nack_Description 335
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Ack_Nack_Description_SIZE  72
#define CSN1_Packet_Downlink_Assignment_message_content_COMPACT_reduced_MA 1915
#define CSN1_Packet_Downlink_Assignment_message_content_COMPACT_reduced_MA_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_downlink_mc_EGPRS2 1957
#define CSN1_Packet_Downlink_Assignment_message_content_downlink_mc_EGPRS2_SIZE   0
#define CSN1_Packet_Downlink_Dummy_Control_Block_message_content_PAGE_MODE 367
#define CSN1_Packet_Downlink_Dummy_Control_Block_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Paging_Request_message_content_Distribution_part_error 3243
#define CSN1_Packet_Paging_Request_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_PAGE_MODE 386
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_PAGE_MODE_SIZE   2
#define CSN1_Packet_Resource_Request_message_content_RETRANSMISSION_OF_PRR 2088
#define CSN1_Packet_Resource_Request_message_content_RETRANSMISSION_OF_PRR_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_RLC_MODE 2137
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_RLC_MODE_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PFI_of_uplink_TBF 2149
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PFI_of_uplink_TBF_SIZE   7
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CHANNEL_CODING_COMMAND 895
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_Packet_Uplink_Assignment_message_content_DLMC_UL_Carrier_Info 1599
#define CSN1_Packet_Uplink_Assignment_message_content_DLMC_UL_Carrier_Info_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Dynamic_Allocation_2 1587
#define CSN1_Packet_Uplink_Assignment_message_content_Dynamic_Allocation_2_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters 1549
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Uplink_Dummy_Control_Block_message_content_TLLI_G_RNTI 369
#define CSN1_Packet_Uplink_Dummy_Control_Block_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Pulse_Format_Coding_2_struct_Non_Hopping_Carrier_Pulse_Format 581
#define CSN1_Pulse_Format_Coding_2_struct_Non_Hopping_Carrier_Pulse_Format_SIZE   0
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_TBF_UPLINK_PAIRS_ALLOCATION 1827
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_TBF_UPLINK_PAIRS_ALLOCATION_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_E_UTRAN_QRXLEVMIN 2021
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_E_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_PCID_to_TA_mapping 2026
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_PCID_to_TA_mapping_SIZE   0
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_struct_EARFCN 1086
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_struct_EARFCN_SIZE  16
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_UTRAN_QRXLEVMIN 2002
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Single_Downlink_Assignment_2_IE_LINK_QUALITY_MEASUREMENT_MODE 1836
#define CSN1_Single_Downlink_Assignment_2_IE_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_p3G_Priority_Parameters_IE_Repeated_UTRAN_Priority_Parameters 1997
#define CSN1_p3G_Priority_Parameters_IE_Repeated_UTRAN_Priority_Parameters_SIZE   0
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command 1800
#define CSN1_BTTI_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__16QAM__NSR_MEAN_BEP 645
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__16QAM__NSR_MEAN_BEP_SIZE   5
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__32QAM__NSR_MEAN_BEP 647
#define CSN1_DLMC_BEP_Link_Quality_Measurements_struct__32QAM__NSR_MEAN_BEP_SIZE   5
#define CSN1_DLMC_Channel_Quality_Report_DLMC_BEP_Link_Quality_Measurements 640
#define CSN1_DLMC_Channel_Quality_Report_DLMC_BEP_Link_Quality_Measurements_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_EXTENDED_DYNAMIC_ALLOCATION 2508
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_PR_MODE 900
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_PR_MODE_SIZE   1
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN0 906
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN0_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN1 908
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN1_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN2 910
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN2_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN3 912
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN3_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN4 914
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN4_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN5 916
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN5_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN6 918
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN6_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN7 920
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_TN7_SIZE   3
#define CSN1_Extension_Information_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT 1049
#define CSN1_Extension_Information_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT_SIZE   1
#define CSN1_Global_Power_Control_Parameters_IE_INT_MEAS_CHANNEL_LIST_AVAIL 214
#define CSN1_Global_Power_Control_Parameters_IE_INT_MEAS_CHANNEL_LIST_AVAIL_SIZE   1
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_bis_NR_OF_REMAINING_CELLS 1514
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_bis_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_SAME_RA_AS_SERVING_CELL 453
#define CSN1_Iu_Mode_Only_Cell_Selection_struct_bis_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_MBMS_Session_Parameters_List_IE_Length_of_MBMS_Bearer_Identity 2439
#define CSN1_MBMS_Session_Parameters_List_IE_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_MBMS_bearer_description_struct_MBMS_Radio_Bearer_Starting_Time 1702
#define CSN1_MBMS_bearer_description_struct_MBMS_Radio_Bearer_Starting_Time_SIZE  16
#define CSN1_Multi_Block_Allocation_struct_NUMBER_OF_RADIO_BLOCKS_ALLOCATED 929
#define CSN1_Multi_Block_Allocation_struct_NUMBER_OF_RADIO_BLOCKS_ALLOCATED_SIZE   2
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Pulse_Format 1701
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Pulse_Format_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Assignment_Info 1621
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Assignment_Info_SIZE   3
#define CSN1_PS_Handover_Radio_Resources_3_IE_LINK_QUALITY_MEASUREMENT_MODE 2370
#define CSN1_PS_Handover_Radio_Resources_3_IE_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Packet_CS_Release_message_content_EGPRS_Channel_Coding_Command 2231
#define CSN1_Packet_CS_Release_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Packet_CS_Release_message_content_Global_Packet_Timing_Advance 2219
#define CSN1_Packet_CS_Release_message_content_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Multiple_Downlink_Assignment 2222
#define CSN1_Packet_CS_Release_message_content_Multiple_Downlink_Assignment_SIZE   0
#define CSN1_Packet_Cell_Change_Failure_message_content_E_UTRAN_Target_cell 684
#define CSN1_Packet_Cell_Change_Failure_message_content_E_UTRAN_Target_cell_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_Message_escape 3142
#define CSN1_Packet_Cell_Change_Notification_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Cell_Change_Order_message_content_Individual_Priorities 2328
#define CSN1_Packet_Cell_Change_Order_message_content_Individual_Priorities_SIZE   0
#define CSN1_Packet_Cell_Change_Order_message_content_UTRAN_FDD_Target_cell 2315
#define CSN1_Packet_Cell_Change_Order_message_content_UTRAN_FDD_Target_cell_SIZE   0
#define CSN1_Packet_Cell_Change_Order_message_content_UTRAN_TDD_Target_cell 2320
#define CSN1_Packet_Cell_Change_Order_message_content_UTRAN_TDD_Target_cell_SIZE   0
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_G_RNTI_extension 505
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_TIMESLOT_ALLOCATION 1903
#define CSN1_Packet_Downlink_Assignment_message_content_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_TLLI_G_RNTI 814
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_TLLI_G_RNTI_SIZE  32
#define CSN1_Packet_MBMS_Announcement_message_content_MBMS_Session_Identity 2275
#define CSN1_Packet_MBMS_Announcement_message_content_MBMS_Session_Identity_SIZE   8
#define CSN1_Packet_Measurement_Order_message_content_Individual_Priorities 2028
#define CSN1_Packet_Measurement_Order_message_content_Individual_Priorities_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content__700_REPORTING_OFFSET 1980
#define CSN1_Packet_Measurement_Order_message_content__700_REPORTING_OFFSET_SIZE   3
#define CSN1_Packet_Measurement_Order_message_content__810_REPORTING_OFFSET 1982
#define CSN1_Packet_Measurement_Order_message_content__810_REPORTING_OFFSET_SIZE   3
#define CSN1_Packet_Polling_Request_message_content_Distribution_part_error 3117
#define CSN1_Packet_Polling_Request_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Global_TFI 387
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Global_TFI_SIZE   6
#define CSN1_Packet_Serving_Cell_SI_message_content_Distribution_part_error 3126
#define CSN1_Packet_Serving_Cell_SI_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_TBF_Release_message_content_Non_distribution_part_error 3130
#define CSN1_Packet_TBF_Release_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_COMPACT_reduced_MA 2164
#define CSN1_Packet_Timeslot_Reconfigure_message_content_COMPACT_reduced_MA_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Dynamic_Allocation 2143
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Dynamic_Allocation_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMST_NW_Capability 2155
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMST_NW_Capability_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_REPORTED_TIMESLOTS 2211
#define CSN1_Packet_Timeslot_Reconfigure_message_content_REPORTED_TIMESLOTS_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_EGPRS_Level 2196
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_EGPRS_Level_SIZE   2
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error 3158
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_EGPRS_message_content 1564
#define CSN1_Packet_Uplink_Assignment_message_content_EGPRS_message_content_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Packet_Timing_Advance 1548
#define CSN1_Packet_Uplink_Assignment_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_REPORTED_TIMESLOTS_C1 1592
#define CSN1_Packet_Uplink_Assignment_message_content_REPORTED_TIMESLOTS_C1_SIZE   8
#define CSN1_Packet_Uplink_Assignment_message_content_REPORTED_TIMESLOTS_C2 1593
#define CSN1_Packet_Uplink_Assignment_message_content_REPORTED_TIMESLOTS_C2_SIZE   8
#define CSN1_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT 1600
#define CSN1_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command 1821
#define CSN1_RTTI_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_THRESH_E_UTRAN_low 2020
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_THRESH_E_UTRAN_low_SIZE   5
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_FDD_ARFCN 1080
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_FDD_ARFCN_SIZE  14
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_TDD_ARFCN 1081
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_TDD_ARFCN_SIZE  14
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_THRESH_UTRAN_low 2001
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_THRESH_UTRAN_low_SIZE   5
#define CSN1_Single_Downlink_Assignment_2_IE_PDCH_pairs_configuration_error 3201
#define CSN1_Single_Downlink_Assignment_2_IE_PDCH_pairs_configuration_error_SIZE   0
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_GPRS_Qoffset 1195
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_GPRS_Qoffset_SIZE   4
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_GPRS_Qoffset 1197
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_GPRS_Qoffset_SIZE   4
#define CSN1__3G_Neighbour_Cell_Description_struct_Absolute_Index_Start_EMR 1098
#define CSN1__3G_Neighbour_Cell_Description_struct_Absolute_Index_Start_EMR_SIZE   7
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_TIMESLOT_ALLOCATION_C1 1671
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_TIMESLOT_ALLOCATION_C2 1672
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_Downlink_TBF_assignment_2_struct_bis_Downlink_EGPRS_Window_Size 518
#define CSN1_Downlink_TBF_assignment_2_struct_bis_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_Downlink_TBF_assignment_2_struct_bis_Uplink_Control_Timeslot_C1 512
#define CSN1_Downlink_TBF_assignment_2_struct_bis_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_Downlink_TBF_assignment_2_struct_bis_Uplink_Control_Timeslot_C2 513
#define CSN1_Downlink_TBF_assignment_2_struct_bis_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_ALPHA 958
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_ALPHA_SIZE   4
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM_HSR_CV_BEP 194
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM_HSR_CV_BEP_SIZE   3
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM_HSR_CV_BEP 196
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM_HSR_CV_BEP_SIZE   3
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY 1883
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY_SIZE   1
#define CSN1_ENH_Measurement_parameters_struct_GPRS_REP_PRIORITY_Description 1107
#define CSN1_ENH_Measurement_parameters_struct_GPRS_REP_PRIORITY_Description_SIZE   0
#define CSN1_ETWS_Primary_Notification_struct_ETWS_Primary_Notification_Data 2456
#define CSN1_ETWS_Primary_Notification_struct_ETWS_Primary_Notification_Data_SIZE   0
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_EARFCN_extended 723
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_EARFCN_extended_SIZE  18
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT  31
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT_SIZE   1
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS 859
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Message_escape 3224
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Message_escape_SIZE   0
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_MS_ID_Release_Indication 772
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_MS_ID_Release_Indication_SIZE   1
#define CSN1_MBMS_MS_ID_Assignment_message_content_Current_MS_ID_Expiry_Time 541
#define CSN1_MBMS_MS_ID_Assignment_message_content_Current_MS_ID_Expiry_Time_SIZE  16
#define CSN1_MBMS_MS_ID_Assignment_message_content_Length_Indicator_of_MS_ID 542
#define CSN1_MBMS_MS_ID_Assignment_message_content_Length_Indicator_of_MS_ID_SIZE   2
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Radio_Bearer_Starting_Time 2442
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Radio_Bearer_Starting_Time_SIZE  16
#define CSN1_Multiple_Downlink_Assignment_2_IE_LINK_QUALITY_MEASUREMENT_MODE 1763
#define CSN1_Multiple_Downlink_Assignment_2_IE_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment 1397
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Message_escape 3174
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_G_RNTI_extension 1605
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Multiple_Uplink_Assignment_2_struct_EXTENDED_DYNAMIC_ALLOCATION 1685
#define CSN1_Multiple_Uplink_Assignment_2_struct_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_struct_Global_Timeslot_description 1691
#define CSN1_Multiple_Uplink_Assignment_2_struct_Global_Timeslot_description_SIZE   0
#define CSN1_PSI3_bis_message_content_Iu_mode_Only_Neighbour_Cell_Parameters 1182
#define CSN1_PSI3_bis_message_content_Iu_mode_Only_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Non_distribution_part_error 3237
#define CSN1_PS_Handover_Command_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_Packet_Extended_Timing_Advance 2350
#define CSN1_PS_Handover_Radio_Resources_2_IE_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_Packet_Extended_Timing_Advance 2373
#define CSN1_PS_Handover_Radio_Resources_3_IE_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_Application_Information_message_content_Application_Data 548
#define CSN1_Packet_Application_Information_message_content_Application_Data_SIZE   0
#define CSN1_Packet_Application_Information_message_content_Application_Type 547
#define CSN1_Packet_Application_Information_message_content_Application_Type_SIZE   4
#define CSN1_Packet_CS_Release_message_content_LINK_QUALITY_MEASUREMENT_MODE 2230
#define CSN1_Packet_CS_Release_message_content_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Packet_Cell_Change_Notification_message_content__3G_Target_Cell 696
#define CSN1_Packet_Cell_Change_Notification_message_content__3G_Target_Cell_SIZE   0
#define CSN1_Packet_Control_Acknowledgement_message_content_G_RNTI_extension 290
#define CSN1_Packet_Control_Acknowledgement_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_DBPSCH_Assignment_message_content_NETWORK_RESPONSE_TIMES 750
#define CSN1_Packet_DBPSCH_Assignment_message_content_NETWORK_RESPONSE_TIMES_SIZE   0
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Channel_Quality_Report 337
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Channel_Quality_Report_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Downlink_EGPRS_Level 1953
#define CSN1_Packet_Downlink_Assignment_message_content_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters 1907
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Secondary_DL_TSC_Set 1929
#define CSN1_Packet_Downlink_Assignment_message_content_Secondary_DL_TSC_Set_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C1 1935
#define CSN1_Packet_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Packet_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C2 1936
#define CSN1_Packet_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_SI23_BA_USED 837
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_SI23_BA_USED_SIZE   1
#define CSN1_Packet_Measurement_Report_message_content_NC_Measurement_Report 793
#define CSN1_Packet_Measurement_Report_message_content_NC_Measurement_Report_SIZE   0
#define CSN1_Packet_PRACH_Parameters_message_content_Distribution_part_error 3122
#define CSN1_Packet_PRACH_Parameters_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Paging_Request_message_content_ETWS_Primary_Notification 2451
#define CSN1_Packet_Paging_Request_message_content_ETWS_Primary_Notification_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_EARLY_TBF_ESTABLISHMENT 2093
#define CSN1_Packet_Resource_Request_message_content_EARLY_TBF_ESTABLISHMENT_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PFI_of_downlink_TBF 2148
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PFI_of_downlink_TBF_SIZE   7
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RB_Id_of_uplink_TBF 2146
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RB_Id_of_uplink_TBF_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_RLC_Entity_2 2153
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_RLC_Entity_2_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_RLC_Entity_3 2154
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_RLC_Entity_3_SIZE   0
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PRE_EMPTIVE_TRANSMISSION 880
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PRE_EMPTIVE_TRANSMISSION_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Power_Control_Parameters 887
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Power_Control_Parameters_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_CHANNEL_CODING_COMMAND 1546
#define CSN1_Packet_Uplink_Assignment_message_content_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_Packet_Uplink_Assignment_message_content_EMSR_Additional_PFCs_1 1581
#define CSN1_Packet_Uplink_Assignment_message_content_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_EMSR_Additional_PFCs_2 1582
#define CSN1_Packet_Uplink_Assignment_message_content_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_EMSR_Additional_PFCs_3 1583
#define CSN1_Packet_Uplink_Assignment_message_content_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Multi_Block_Allocation 1574
#define CSN1_Packet_Uplink_Assignment_message_content_Multi_Block_Allocation_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_PDCH_Pairs_Description 1586
#define CSN1_Packet_Uplink_Assignment_message_content_PDCH_Pairs_Description_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_THRESH_E_UTRAN_high 2019
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_THRESH_E_UTRAN_high_SIZE   5
#define CSN1_Repeated_Iu_Page_info_struct_Length_of_Mobile_Identity_contents 2426
#define CSN1_Repeated_Iu_Page_info_struct_Length_of_Mobile_Identity_contents_SIZE   4
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_THRESH_UTRAN_high 2000
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_THRESH_UTRAN_high_SIZE   5
#define CSN1_UTRAN_FDD_Description_struct_Repeated_UTRAN_FDD_Neighbour_Cells 312
#define CSN1_UTRAN_FDD_Description_struct_Repeated_UTRAN_FDD_Neighbour_Cells_SIZE   0
#define CSN1_UTRAN_TDD_Description_struct_Repeated_UTRAN_TDD_Neighbour_Cells 318
#define CSN1_UTRAN_TDD_Description_struct_Repeated_UTRAN_TDD_Neighbour_Cells_SIZE   0
#define CSN1__3G_Neighbour_Cells_Description_struct_Absolute_Index_Start_EMR 1190
#define CSN1__3G_Neighbour_Cells_Description_struct_Absolute_Index_Start_EMR_SIZE   7
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_Downlink_TBF_assignment 1675
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Content_Extended_RLC_MAC_Control_Message_Segmentation_Capability 1333
#define CSN1_Content_Extended_RLC_MAC_Control_Message_Segmentation_Capability_SIZE   1
#define CSN1_DTM_Handover_Command_message_content_Non_distribution_part_error 3248
#define CSN1_DTM_Handover_Command_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_Power_Control_Parameters 2507
#define CSN1_DTM_Handover_PS_Radio_Resources_IE_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_MA_Frequency_List_contents 1283
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_MA_Frequency_List_contents_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN0 907
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN0_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN1 909
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN1_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN2 911
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN2_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN3 913
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN3_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN4 915
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN4_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN5 917
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN5_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN6 919
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN6_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN7 921
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_GAMMA_TN7_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM__NSR_CV_BEP 190
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM__NSR_CV_BEP_SIZE   3
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM__NSR_CV_BEP 192
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM__NSR_CV_BEP_SIZE   3
#define CSN1_EGPRS_Channel_Quality_Report_EGPRS_BEP_Link_Quality_Measurements 1022
#define CSN1_EGPRS_Channel_Quality_Report_EGPRS_BEP_Link_Quality_Measurements_SIZE   0
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_DOWNLINK_TFI 1248
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_EGPRS_Packet_channel_request_message_content_MultislotClassGroup  63
#define CSN1_EGPRS_Packet_channel_request_message_content_MultislotClassGroup_SIZE   3
#define CSN1_ENH_Measurement_parameters_struct__3G_Neighbour_Cell_Description 1096
#define CSN1_ENH_Measurement_parameters_struct__3G_Neighbour_Cell_Description_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Absence_cause 991
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Absence_cause_SIZE   2
#define CSN1_MBMS_p_t_m_channel_description_struct_Estimated_Session_Duration 2277
#define CSN1_MBMS_p_t_m_channel_description_struct_Estimated_Session_Duration_SIZE   8
#define CSN1_Multiple_Downlink_Assignment_2_IE_PDCH_pairs_configuration_error 3200
#define CSN1_Multiple_Downlink_Assignment_2_IE_PDCH_pairs_configuration_error_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Assignment_Info 1406
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Assignment_Info_SIZE   3
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Message_escape 3197
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Message_escape_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_EGPRS_Window_Size 1613
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_EGPRS_Window_Size_SIZE   5
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_NPM_Transfer_Time 1618
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_PERSISTENCE_LEVEL 1603
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_PS_Handover_Command_message_content_PS_Handover_to_UTRAN_Payload 2399
#define CSN1_PS_Handover_Command_message_content_PS_Handover_to_UTRAN_Payload_SIZE   0
#define CSN1_Packet_CS_Command_message_content_Address_information_part_error 3135
#define CSN1_Packet_CS_Command_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Address_information_part_error 3222
#define CSN1_Packet_CS_Release_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_CS_Release_message_content_PACKET_EXTENDED_TIMING_ADVANCE 2221
#define CSN1_Packet_CS_Release_message_content_PACKET_EXTENDED_TIMING_ADVANCE_SIZE   2
#define CSN1_Packet_Cell_Change_Failure_message_content_UTRAN_CSG_Target_cell 685
#define CSN1_Packet_Cell_Change_Failure_message_content_UTRAN_CSG_Target_cell_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_PSI3_CHANGE_MARK 706
#define CSN1_Packet_Cell_Change_Notification_message_content_PSI3_CHANGE_MARK_SIZE   2
#define CSN1_Packet_Cell_Change_Order_message_content_Distribution_part_error 3233
#define CSN1_Packet_Cell_Change_Order_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_DBPSCH_Assignment_message_content_Distribution_part_error 3146
#define CSN1_Packet_DBPSCH_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Downlink_Ack_Nack_message_content_EARLY_TBF_ESTABLISHMENT 354
#define CSN1_Packet_Downlink_Ack_Nack_message_content_EARLY_TBF_ESTABLISHMENT_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_DLMC_Measurement_Type 1959
#define CSN1_Packet_Downlink_Assignment_message_content_DLMC_Measurement_Type_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_Packet_Timing_Advance 1904
#define CSN1_Packet_Downlink_Assignment_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_BITMAP_LENGTH 832
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_BITMAP_LENGTH_SIZE   7
#define CSN1_Packet_MBMS_Announcement_message_content_Distribution_part_error 3229
#define CSN1_Packet_MBMS_Announcement_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_CCN_Support_Description 1974
#define CSN1_Packet_Measurement_Order_message_content_CCN_Support_Description_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_Distribution_part_error 3210
#define CSN1_Packet_Measurement_Order_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_E_UTRAN_CSG_Description 2036
#define CSN1_Packet_Measurement_Order_message_content_E_UTRAN_CSG_Description_SIZE   0
#define CSN1_Packet_Measurement_Report_message_content_EXT_Measurement_Report 779
#define CSN1_Packet_Measurement_Report_message_content_EXT_Measurement_Report_SIZE   0
#define CSN1_Packet_Measurement_Report_message_content__3G_Measurement_Report 805
#define CSN1_Packet_Measurement_Report_message_content__3G_Measurement_Report_SIZE   0
#define CSN1_Packet_PRACH_Parameters_message_content_PRACH_Control_Parameters 396
#define CSN1_Packet_PRACH_Parameters_message_content_PRACH_Control_Parameters_SIZE   0
#define CSN1_Packet_Physical_Information_message_content_TIMING_ADVANCE_VALUE 545
#define CSN1_Packet_Physical_Information_message_content_TIMING_ADVANCE_VALUE_SIZE   8
#define CSN1_Packet_Serving_Cell_Data_message_content_Distribution_part_error 3152
#define CSN1_Packet_Serving_Cell_Data_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DLMC_UL_Carrier_Info 2210
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DLMC_UL_Carrier_Info_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_EGPRS_Level 2197
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Dynamic_Allocation_2 2188
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Dynamic_Allocation_2_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters 2142
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Secondary_DL_TSC_Set 2162
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Secondary_DL_TSC_Set_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C1 2179
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C2 2180
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Packet_Uplink_Assignment_message_content_Distribution_part_error 3184
#define CSN1_Packet_Uplink_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_C1 1588
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_C2 1589
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Single_Block_Allocation 1551
#define CSN1_Packet_Uplink_Assignment_message_content_Single_Block_Allocation_SIZE   0
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_EARFCN_extended 2061
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_EARFCN_extended_SIZE  18
#define CSN1__3G_Neighbour_Cell_Description_struct_REMOVED_3GCELL_Description 1101
#define CSN1__3G_Neighbour_Cell_Description_struct_REMOVED_3GCELL_Description_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_PR_MODE 955
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_PR_MODE_SIZE   1
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN0 959
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN0_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN1 961
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN1_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN2 963
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN2_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN3 965
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN3_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN4 967
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN4_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN5 969
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN5_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN6 971
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN6_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN7 973
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_TN7_SIZE   3
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM_HSR_MEAN_BEP 193
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM_HSR_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM_HSR_MEAN_BEP 195
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM_HSR_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_DOWNLINK_eTFI 1249
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_DOWNLINK_eTFI_SIZE   3
#define CSN1_EGPRS_Packet_channel_request_message_content_Short_Access_Request  60
#define CSN1_EGPRS_Packet_channel_request_message_content_Short_Access_Request_SIZE  11
#define CSN1_E_UTRAN_Target_cell_with_extended_EARFCN_IE_Measurement_Bandwidth 280
#define CSN1_E_UTRAN_Target_cell_with_extended_EARFCN_IE_Measurement_Bandwidth_SIZE   3
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_EGPRS_Ack_Nack_Description 775
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_EGPRS_Ack_Nack_Description_SIZE   0
#define CSN1_MBMS_MS_ID_Assignment_message_content_Non_distribution_part_error 3137
#define CSN1_MBMS_MS_ID_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_MS_RA_capability_value_part_struct_Additional_access_technologies 1339
#define CSN1_MS_RA_capability_value_part_struct_Additional_access_technologies_SIZE   9
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_G_RNTI_extension 1382
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Uplink_EGPRS_Level 1647
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Uplink_EGPRS_Level_SIZE   2
#define CSN1_PBCCH_information_struct_Length_of_Neighbour_MBMS_Bearer_Identity 1017
#define CSN1_PBCCH_information_struct_Length_of_Neighbour_MBMS_Bearer_Identity_SIZE   3
#define CSN1_Packet_Cell_Change_Notification_message_content_CSG_Discriminator 721
#define CSN1_Packet_Cell_Change_Notification_message_content_CSG_Discriminator_SIZE   1
#define CSN1_Packet_Control_Acknowledgement_message_content_CTRL_ACK_EXTENSION 291
#define CSN1_Packet_Control_Acknowledgement_message_content_CTRL_ACK_EXTENSION_SIZE   9
#define CSN1_Packet_DBPSCH_Assignment_message_content_Packet_Request_Reference 732
#define CSN1_Packet_DBPSCH_Assignment_message_content_Packet_Request_Reference_SIZE  27
#define CSN1_Packet_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C1 1933
#define CSN1_Packet_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Packet_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C2 1934
#define CSN1_Packet_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Packet_Downlink_Assignment_message_content_EMSR_Additional_PFCs_1 1925
#define CSN1_Packet_Downlink_Assignment_message_content_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_EMSR_Additional_PFCs_2 1926
#define CSN1_Packet_Downlink_Assignment_message_content_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_EMSR_Additional_PFCs_3 1927
#define CSN1_Packet_Downlink_Assignment_message_content_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Optimized_dual_carrier 1944
#define CSN1_Packet_Downlink_Assignment_message_content_Optimized_dual_carrier_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Secondary_DL_TSC_Value 1930
#define CSN1_Packet_Downlink_Assignment_message_content_Secondary_DL_TSC_Value_SIZE   3
#define CSN1_Packet_Downlink_Assignment_message_content_TIMESLOT_ALLOCATION_C1 1939
#define CSN1_Packet_Downlink_Assignment_message_content_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_Packet_Downlink_Assignment_message_content_TIMESLOT_ALLOCATION_C2 1940
#define CSN1_Packet_Downlink_Assignment_message_content_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_Packet_Measurement_Order_message_content__700_REPORTING_THRESHOLD 1981
#define CSN1_Packet_Measurement_Order_message_content__700_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Packet_Measurement_Order_message_content__810_REPORTING_THRESHOLD 1983
#define CSN1_Packet_Measurement_Order_message_content__810_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Carrier_Count 393
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Carrier_Count_SIZE   4
#define CSN1_Packet_SI_Status_message_content_Received_Unknown_SI_Message_List 421
#define CSN1_Packet_SI_Status_message_content_Received_Unknown_SI_Message_List_SIZE   0
#define CSN1_Packet_TBF_Release_message_content_Address_information_part_error 3131
#define CSN1_Packet_TBF_Release_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DLMC_Measurement_Type 2205
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DLMC_Measurement_Type_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_RLC_Entity_2 2151
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_RLC_Entity_2_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_RLC_Entity_3 2152
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_RLC_Entity_3_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RB_Id_of_downlink_TBF 2145
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RB_Id_of_downlink_TBF_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_REPORTED_TIMESLOTS_C1 2193
#define CSN1_Packet_Timeslot_Reconfigure_message_content_REPORTED_TIMESLOTS_C1_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_REPORTED_TIMESLOTS_C2 2194
#define CSN1_Packet_Timeslot_Reconfigure_message_content_REPORTED_TIMESLOTS_C2_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_TFI_ASSIGNMENT 2140
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI 883
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI_SIZE  32
#define CSN1_Packet_Uplink_Ack_Nack_message_content_EGPRS_Ack_Nack_Description 889
#define CSN1_Packet_Uplink_Ack_Nack_message_content_EGPRS_Ack_Nack_Description_SIZE   0
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PRR_RETRANSMISSION_REQUEST 881
#define CSN1_Packet_Uplink_Ack_Nack_message_content_PRR_RETRANSMISSION_REQUEST_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_Packet_Request_Reference 1541
#define CSN1_Packet_Uplink_Assignment_message_content_Packet_Request_Reference_SIZE  27
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_E_UTRAN_PRIORITY 2063
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_Measurement_Bandwidth 2017
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_bis_Measurement_Bandwidth_SIZE   3
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_E_UTRAN_FREQUENCY_INDEX 2024
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_Qsearch_I 1200
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_Qsearch_I_SIZE   4
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_Global_TFI 2212
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_Global_TFI_SIZE   6
#define CSN1_COMPACT_Neighbour_Cell_params_struct_COMPACT_Cell_selection_params 1507
#define CSN1_COMPACT_Neighbour_Cell_params_struct_COMPACT_Cell_selection_params_SIZE   0
#define CSN1_DLMC_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents 1739
#define CSN1_DLMC_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents_SIZE   4
#define CSN1_DTM_Handover_Command_message_content_DTM_Handover_to_UTRAN_Payload 2515
#define CSN1_DTM_Handover_Command_message_content_DTM_Handover_to_UTRAN_Payload_SIZE   0
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_GPRS_Power_Control_Parameters 2489
#define CSN1_DTM_Handover_PS_Radio_Resources_2_IE_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_GPRS_Power_Control_Parameters 2468
#define CSN1_DTM_Handover_PS_Radio_Resources_3_IE_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_EGPRS_Ack_Nack_Description_struct_COMPRESSED_RECEIVED_BLOCK_BITMAP 165
#define CSN1_EGPRS_Ack_Nack_Description_struct_COMPRESSED_RECEIVED_BLOCK_BITMAP_SIZE   0
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM__NSR_MEAN_BEP 189
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__16QAM__NSR_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM__NSR_MEAN_BEP 191
#define CSN1_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE__32QAM__NSR_MEAN_BEP_SIZE   5
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_DOWNLINK_TFI 1368
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_DOWNLINK_TFI 1117
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_EPD_A_N_Extension_Info_Type_2_Extended_Channel_Request_Description 1374
#define CSN1_EPD_A_N_Extension_Info_Type_2_Extended_Channel_Request_Description_SIZE   0
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_REPORTING_QUANTITY 726
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_MULTIBAND_REPORTING  17
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_MULTIBAND_REPORTING_SIZE   2
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_Iu_Mode_Cell_Selection_Params 728
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_Iu_Mode_Cell_Selection_Params_SIZE   0
#define CSN1_MBMS_Assignment_Distribution_message_content_MBMS_Session_Identity 2268
#define CSN1_MBMS_Assignment_Distribution_message_content_MBMS_Session_Identity_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_EGPRS_Window_Size 1390
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_EGPRS_Window_Size_SIZE   5
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_NPM_Transfer_Time 1405
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PERSISTENCE_LEVEL 1379
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_TBF_Starting_Time 1389
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_TBF_Starting_Time_SIZE   0
#define CSN1_NC_Measurement_Report_struct_bis_Repeated_Invalid_BSIC_Information 826
#define CSN1_NC_Measurement_Report_struct_bis_Repeated_Invalid_BSIC_Information_SIZE  17
#define CSN1_PSI3_quater_message_content__3G_MEASUREMENT_Parameters_Description 1193
#define CSN1_PSI3_quater_message_content__3G_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Address_information_part_error 3238
#define CSN1_PS_Handover_Command_message_content_Address_information_part_error_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_2_IE_Dual_Carrier_Frequency_Parameters 2347
#define CSN1_PS_Handover_Radio_Resources_2_IE_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Cell_Change_Failure_message_content_E_UTRAN_CSG_Target_cell 688
#define CSN1_Packet_Cell_Change_Failure_message_content_E_UTRAN_CSG_Target_cell_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT 1908
#define CSN1_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Packet_Downlink_Assignment_message_content_Distribution_part_error 3207
#define CSN1_Packet_Downlink_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_C1 1942
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_C2 1943
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Uplink_Control_Timeslot 1918
#define CSN1_Packet_Downlink_Assignment_message_content_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Packet_Measurement_Order_message_content_NC_Measurement_Parameters 1969
#define CSN1_Packet_Measurement_Order_message_content_NC_Measurement_Parameters_SIZE   0
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Distribution_part_error 3149
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Polling_Request_message_content_Non_distribution_part_error 3115
#define CSN1_Packet_Polling_Request_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Message_escape 3119
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Message_escape_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_CHANNEL_CODING_COMMAND 2135
#define CSN1_Packet_Timeslot_Reconfigure_message_content_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C1 2177
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C2 2178
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMSR_Additional_PFCs_1 2157
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMSR_Additional_PFCs_2 2158
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMSR_Additional_PFCs_3 2159
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Secondary_DL_TSC_Value 2163
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Secondary_DL_TSC_Value_SIZE   3
#define CSN1_Packet_Timeslot_Reconfigure_message_content_TIMESLOT_ALLOCATION_C1 2183
#define CSN1_Packet_Timeslot_Reconfigure_message_content_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_TIMESLOT_ALLOCATION_C2 2184
#define CSN1_Packet_Timeslot_Reconfigure_message_content_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_Packet_Uplink_Ack_Nack_message_content_ARAC_RETRANSMISSION_REQUEST 882
#define CSN1_Packet_Uplink_Ack_Nack_message_content_ARAC_RETRANSMISSION_REQUEST_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error 3155
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_MTTI_UPLINK_ASSIGNMENT_C1 1597
#define CSN1_Packet_Uplink_Assignment_message_content_MTTI_UPLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_MTTI_UPLINK_ASSIGNMENT_C2 1598
#define CSN1_Packet_Uplink_Assignment_message_content_MTTI_UPLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_TLLI_BLOCK_CHANNEL_CODING 1547
#define CSN1_Packet_Uplink_Assignment_message_content_TLLI_BLOCK_CHANNEL_CODING_SIZE   1
#define CSN1_Packet_Uplink_Dummy_Control_Block_message_content_G_RNTI_extension 370
#define CSN1_Packet_Uplink_Dummy_Control_Block_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_channel_request_11_bit_message_content_Short_Access_Request  45
#define CSN1_Packet_channel_request_11_bit_message_content_Short_Access_Request_SIZE  11
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_E_UTRAN_QRXLEVMIN 2066
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_E_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_E_UTRAN_FREQUENCY_INDEX 2027
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct__3G_BA_IND 1199
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct__3G_BA_IND_SIZE   1
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_Uplink_Control_Timeslot_C1 1673
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_Uplink_Control_Timeslot_C2 1674
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C1 1420
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C2 1421
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_DTM_Handover_CS_Radio_Resources_IE_CS_HANDOVER_RADIO_RESOURCES_DATA 2462
#define CSN1_DTM_Handover_CS_Radio_Resources_IE_CS_HANDOVER_RADIO_RESOURCES_DATA_SIZE   0
#define CSN1_DTM_Handover_Command_message_content_Address_information_part_error 3249
#define CSN1_DTM_Handover_Command_message_content_Address_information_part_error_SIZE   0
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_Message_escape 3246
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_Message_escape_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN0 960
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN0_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN1 962
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN1_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN2 964
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN2_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN3 966
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN3_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN4 968
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN4_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN5 970
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN5_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN6 972
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN6_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN7 974
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_GAMMA_TN7_SIZE   5
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_IE_BEP_MEASUREMENTS 567
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_IE_BEP_MEASUREMENTS_SIZE   0
#define CSN1_EPD_A_N_Extension_Info_Type_2_Secondary_Dual_Carrier_Channel_Report 1376
#define CSN1_EPD_A_N_Extension_Info_Type_2_Secondary_Dual_Carrier_Channel_Report_SIZE   0
#define CSN1_Measurement_Control_Parameters_Description_IE_UTRAN_FREQUENCY_INDEX 271
#define CSN1_Measurement_Control_Parameters_Description_IE_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_Multiple_Downlink_Assignment_2_IE_BTTI_Multiple_Downlink_Assignment 1766
#define CSN1_Multiple_Downlink_Assignment_2_IE_BTTI_Multiple_Downlink_Assignment_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_NPM_Transfer_Time 1663
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters 1611
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Packet_CS_Release_message_content_Dual_Carrier_Frequency_Parameters 2246
#define CSN1_Packet_CS_Release_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Cell_Change_Continue_message_content_Distribution_part_error 3112
#define CSN1_Packet_Cell_Change_Continue_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_Target_Cell 697
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_Target_Cell_SIZE   0
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_RECEIVED_BLOCK_BITMAP 507
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_RECEIVED_BLOCK_BITMAP_SIZE 128
#define CSN1_Packet_Downlink_Assignment_message_content_Power_Control_Parameters 1909
#define CSN1_Packet_Downlink_Assignment_message_content_Power_Control_Parameters_SIZE   0
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_G_RNTI_extension 831
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_G_RNTI_extension_SIZE   4
#define CSN1_Packet_Measurement_Order_message_content_ENH_Measurement_Parameters 1972
#define CSN1_Packet_Measurement_Order_message_content_ENH_Measurement_Parameters_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_EXT_Measurement_Parameters 1970
#define CSN1_Packet_Measurement_Order_message_content_EXT_Measurement_Parameters_SIZE   0
#define CSN1_Packet_PSI_Status_message_content_Received_Unknown_PSI_Message_List 408
#define CSN1_Packet_PSI_Status_message_content_Received_Unknown_PSI_Message_List_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_Channel_Request_Description 2072
#define CSN1_Packet_Resource_Request_message_content_Channel_Request_Description_SIZE  24
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_TFI_ASSIGNMENT 2139
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Distribution_part_error 3218
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_C1 2185
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_C2 2186
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_Control_Timeslot 2147
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command 877
#define CSN1_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Packet_Uplink_Assignment_message_content_CONTENTION_RESOLUTION_TLLI 1565
#define CSN1_Packet_Uplink_Assignment_message_content_CONTENTION_RESOLUTION_TLLI_SIZE  32
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_error 3181
#define CSN1_Packet_Uplink_Assignment_message_content_Frequency_Parameters_error_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Downlink_TBF_assignment 1684
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_Downlink_TBF_assignment 1680
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_THRESH_E_UTRAN_low 2065
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_THRESH_E_UTRAN_low_SIZE   5
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_UTRAN_PRIORITY 1082
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_UTRAN_PRIORITY_SIZE   3
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_UTRAN_FREQUENCY_INDEX 1998
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_bis_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_FDD_Qoffset 1202
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_FDD_Qoffset_SIZE   4
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_TDD_Qoffset 1205
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_TDD_Qoffset_SIZE   4
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment 1422
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Carrier_Specific_Info_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DLMC 1744
#define CSN1_Carrier_Specific_Info_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DLMC_SIZE   4
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_Downlink_EGPRS_Window_Size 618
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_Uplink_Control_Timeslot_C1 612
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_Uplink_Control_Timeslot_C2 613
#define CSN1_Downlink_TBF_assignment_2_struct_12_48a_5_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_EGPRS_Ack_Nack_Description_struct_UNCOMPRESSED_RECEIVED_BLOCK_BITMAP 166
#define CSN1_EGPRS_Ack_Nack_Description_struct_UNCOMPRESSED_RECEIVED_BLOCK_BITMAP_SIZE   0
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_MS_OUT_OF_MEMORY 1250
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content_MS_OUT_OF_MEMORY_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_Extension_Bits 1121
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_Extension_Bits_SIZE   0
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__400_REPORTING_OFFSET  24
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__400_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__850_REPORTING_OFFSET  28
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__850_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__900_REPORTING_OFFSET  20
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__900_REPORTING_OFFSET_SIZE   3
#define CSN1_MBMS_Assignment_Distribution_message_content_Distribution_part_error 3228
#define CSN1_MBMS_Assignment_Distribution_message_content_Distribution_part_error_SIZE   0
#define CSN1_MBMS_Assignment_Distribution_message_content_MBMS_bearer_description 2269
#define CSN1_MBMS_Assignment_Distribution_message_content_MBMS_bearer_description_SIZE   0
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_MBMS_Neighbouring_Cell_Report 760
#define CSN1_MBMS_Downlink_Ack_Nack_message_content_MBMS_Neighbouring_Cell_Report_SIZE   0
#define CSN1_MBMS_MS_ID_Assignment_message_content_Address_information_part_error 3138
#define CSN1_MBMS_MS_ID_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_MBMS_MS_ID_Assignment_message_content_Length_of_MBMS_Bearer_Identity 535
#define CSN1_MBMS_MS_ID_Assignment_message_content_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_EGPRS_Window_Size 1007
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_EGPRS_Window_Size_SIZE   5
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_NPM_Transfer_Time 1012
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_NPM_Transfer_Time_SIZE   5
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_PBCCH_information 1013
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_PBCCH_information_SIZE   0
#define CSN1_MBMS_p_t_m_channel_description_struct_Length_of_MBMS_Bearer_Identity 2281
#define CSN1_MBMS_p_t_m_channel_description_struct_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Uplink_EGPRS_Level 1699
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Uplink_EGPRS_Level_SIZE   2
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Packet_Timing_Advance 1609
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Uplink_TBF_Assignment 1612
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Uplink_TBF_Assignment_SIZE   0
#define CSN1_PS_Handover_Command_message_content_PS_Handover_to_A_Gb_Mode_Payload 2334
#define CSN1_PS_Handover_Command_message_content_PS_Handover_to_A_Gb_Mode_Payload_SIZE   0
#define CSN1_Packet_CS_Release_message_content_ENHANCED_DTM_CS_RELEASE_INDICATION 2218
#define CSN1_Packet_CS_Release_message_content_ENHANCED_DTM_CS_RELEASE_INDICATION_SIZE   1
#define CSN1_Packet_Cell_Change_Order_message_content_Non_distribution_part_error 3230
#define CSN1_Packet_Cell_Change_Order_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_DBPSCH_Assignment_message_content_Non_distribution_part_error 3143
#define CSN1_Packet_DBPSCH_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Channel_Request_Description 336
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Channel_Request_Description_SIZE  24
#define CSN1_Packet_Measurement_Order_message_content_Non_distribution_part_error 3208
#define CSN1_Packet_Measurement_Order_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Measurement_Report_message_content_E_UTRAN_Measurement_Report 810
#define CSN1_Packet_Measurement_Report_message_content_E_UTRAN_Measurement_Report_SIZE   0
#define CSN1_Packet_Queueing_Notification_message_content_Distribution_part_error 3125
#define CSN1_Packet_Queueing_Notification_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_MS_Radio_Access_Capability_2 2070
#define CSN1_Packet_Resource_Request_message_content_MS_Radio_Access_Capability_2_SIZE   0
#define CSN1_Packet_Serving_Cell_Data_message_content_Non_distribution_part_error 3150
#define CSN1_Packet_Serving_Cell_Data_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_EGPRS_Window_Size 2168
#define CSN1_Packet_Timeslot_Reconfigure_message_content_UPLINK_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_NPM_Transfer_Time 2171
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_Uplink_Assignment_message_content_ARAC_RETRANSMISSION_REQUEST 1572
#define CSN1_Packet_Uplink_Assignment_message_content_ARAC_RETRANSMISSION_REQUEST_SIZE   1
#define CSN1_Packet_Uplink_Assignment_message_content_Access_Technologies_Request 1571
#define CSN1_Packet_Uplink_Assignment_message_content_Access_Technologies_Request_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Non_distribution_part_error 3180
#define CSN1_Packet_Uplink_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_THRESH_E_UTRAN_high 2064
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_THRESH_E_UTRAN_high_SIZE   5
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_CELL_INFORMATION_Field 316
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_CELL_INFORMATION_Field_SIZE   0
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_CELL_INFORMATION_Field 322
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_CELL_INFORMATION_Field_SIZE   0
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_Downlink_eTFI 2215
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_Downlink_eTFI_SIZE   3
#define CSN1_DTM_Handover_CS_Radio_Resources_IE_CS_HANDOVER_RADIO_RESOURCES_LENGTH 2461
#define CSN1_DTM_Handover_CS_Radio_Resources_IE_CS_HANDOVER_RADIO_RESOURCES_LENGTH_SIZE   7
#define CSN1_EGPRS_Channel_Quality_Report_EGPRS_Timeslot_Link_Quality_Measurements 1024
#define CSN1_EGPRS_Channel_Quality_Report_EGPRS_Timeslot_Link_Quality_Measurements_SIZE   0
#define CSN1_EGPRS_Packet_channel_request_message_content_One_Phase_Access_Request  56
#define CSN1_EGPRS_Packet_channel_request_message_content_One_Phase_Access_Request_SIZE  11
#define CSN1_EGPRS_Packet_channel_request_message_content_Two_Phase_Access_Request  64
#define CSN1_EGPRS_Packet_channel_request_message_content_Two_Phase_Access_Request_SIZE  11
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_IE_INTERFERENCE_MEASUREMENTS 566
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_IE_INTERFERENCE_MEASUREMENTS_SIZE   0
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_Measurement_Bandwidth 724
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_MULTIRAT_REPORTING 2008
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_MULTIRAT_REPORTING_SIZE   2
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SERVING_BAND_REPORTING  18
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SERVING_BAND_REPORTING_SIZE   2
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1800_REPORTING_OFFSET  22
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1800_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1900_REPORTING_OFFSET  26
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1900_REPORTING_OFFSET_SIZE   3
#define CSN1_Global_Packet_Timing_Advance_IE_UPLINK_TIMING_ADVANCE_TIMESLOT_NUMBER 232
#define CSN1_Global_Packet_Timing_Advance_IE_UPLINK_TIMING_ADVANCE_TIMESLOT_NUMBER_SIZE   3
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_Bearer_Identity 2264
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_Bearer_Identity_SIZE   0
#define CSN1_MBMS_p_t_m_channel_description_struct_MBMS_Radio_Bearer_Starting_Time 2278
#define CSN1_MBMS_p_t_m_channel_description_struct_MBMS_Radio_Bearer_Starting_Time_SIZE   0
#define CSN1_Measurement_Control_Parameters_Description_IE_E_UTRAN_FREQUENCY_INDEX 269
#define CSN1_Measurement_Control_Parameters_Description_IE_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Downlink_EGPRS_Level 1429
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters 1387
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C1 1424
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C2 3172
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_CHANNEL_CODING_COMMAND 1607
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_PSI16_message_content_CN_DOMAIN_SPECIFIC_DRX_CYCLE_LENGTH_COEFFICIENT 492
#define CSN1_PSI16_message_content_CN_DOMAIN_SPECIFIC_DRX_CYCLE_LENGTH_COEFFICIENT_SIZE   2
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_RECEIVED_BLOCK_BITMAP 358
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_RECEIVED_BLOCK_BITMAP_SIZE 128
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_error 3204
#define CSN1_Packet_Downlink_Assignment_message_content_Frequency_Parameters_error_SIZE   0
#define CSN1_Packet_Downlink_Dummy_Control_Block_message_content_PERSISTENCE_LEVEL 368
#define CSN1_Packet_Downlink_Dummy_Control_Block_message_content_PERSISTENCE_LEVEL_SIZE  16
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_REPORTING_QUANTITY 833
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_REPORTING_QUANTITY_SIZE   6
#define CSN1_Packet_Polling_Request_message_content_Address_information_part_error 3116
#define CSN1_Packet_Polling_Request_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Queueing_Notification_message_content_Packet_Request_Reference 398
#define CSN1_Packet_Queueing_Notification_message_content_Packet_Request_Reference_SIZE  27
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_UPLINK_ASSIGNMENT_C1 2201
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_UPLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_UPLINK_ASSIGNMENT_C2 2202
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_UPLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error 3157
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Packet_Extended_Timing_Advance 886
#define CSN1_Packet_Uplink_Ack_Nack_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command 1567
#define CSN1_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Single_Downlink_Assignment_2_IE_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 1843
#define CSN1_Single_Downlink_Assignment_2_IE_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_Single_Downlink_Assignment_2_IE_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 1844
#define CSN1_Single_Downlink_Assignment_2_IE_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_FDD_REP_QUANT 1203
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_FDD_REP_QUANT_SIZE   1
#define CSN1_COMPACT_Neighbour_Cell_params_2_struct_COMPACT_Neighbour_parameter_set 1169
#define CSN1_COMPACT_Neighbour_Cell_params_2_struct_COMPACT_Neighbour_parameter_set_SIZE   0
#define CSN1_DTM_Handover_Command_message_content_DTM_Handover_to_A_Gb_Mode_Payload 2459
#define CSN1_DTM_Handover_Command_message_content_DTM_Handover_to_A_Gb_Mode_Payload_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_GRANULARITY 901
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_USF_GRANULARITY_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_MS_OUT_OF_MEMORY 1369
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_MS_OUT_OF_MEMORY_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_MS_OUT_OF_MEMORY 1118
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_MS_OUT_OF_MEMORY_SIZE   1
#define CSN1_EGPRS_Packet_channel_request_message_content_Dedicated_Channel_Request  68
#define CSN1_EGPRS_Packet_channel_request_message_content_Dedicated_Channel_Request_SIZE  11
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_OFFSET  33
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_OFFSET  36
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_OFFSET_SIZE   3
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_bis_Iu_Mode_Cell_Selection_Params 1515
#define CSN1_Iu_Mode_Neighbour_Cell_Params_struct_bis_Iu_Mode_Cell_Selection_Params_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_Session_Identity 2258
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_Session_Identity_SIZE   8
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Packet_Timing_Advance 2254
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_MBMS_In_band_Signalling_Indicator_IE_MBMS_In_band_Signalling_Indicator 1011
#define CSN1_MBMS_In_band_Signalling_Indicator_IE_MBMS_In_band_Signalling_Indicator_SIZE   1
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_Frequency_List 992
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_Frequency_List_SIZE   0
#define CSN1_Multiple_Downlink_Assignment_2_IE_RTTI_Multiple_Downlink_Assignment_DC 1776
#define CSN1_Multiple_Downlink_Assignment_2_IE_RTTI_Multiple_Downlink_Assignment_DC_SIZE   0
#define CSN1_Multiple_Downlink_Assignment_2_IE_RTTI_Multiple_Downlink_Assignment_SC 1781
#define CSN1_Multiple_Downlink_Assignment_2_IE_RTTI_Multiple_Downlink_Assignment_SC_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Packet_Timing_Advance 1384
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Packet_Timing_Advance_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Downlink_EGPRS_Level 1700
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters 1653
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C1 1677
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C2 3195
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Distribution_part_error 3189
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_C1 1623
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_C2 1624
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Uplink_TBF_Assignment_2 1626
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Uplink_TBF_Assignment_2_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_Carrier_for_Interference_Measurements 2371
#define CSN1_PS_Handover_Radio_Resources_3_IE_Carrier_for_Interference_Measurements_SIZE   4
#define CSN1_Packet_Application_Information_message_content_Distribution_part_error 3140
#define CSN1_Packet_Application_Information_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_CCN_Measurement_Report 709
#define CSN1_Packet_Cell_Change_Notification_message_content_CCN_Measurement_Report_SIZE   0
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_STARTING_SEQUENCE_NUMBER 506
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_STARTING_SEQUENCE_NUMBER_SIZE   8
#define CSN1_Packet_Downlink_Assignment_message_content_MTTI_DOWNLINK_ASSIGNMENT_C1 1954
#define CSN1_Packet_Downlink_Assignment_message_content_MTTI_DOWNLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_MTTI_DOWNLINK_ASSIGNMENT_C2 1955
#define CSN1_Packet_Downlink_Assignment_message_content_MTTI_DOWNLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_Non_distribution_part_error 3202
#define CSN1_Packet_Downlink_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Power_Control_Parameters_C1 1950
#define CSN1_Packet_Downlink_Assignment_message_content_Power_Control_Parameters_C1_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Power_Control_Parameters_C2 1951
#define CSN1_Packet_Downlink_Assignment_message_content_Power_Control_Parameters_C2_SIZE   0
#define CSN1_Packet_Measurement_Report_message_content_UTRAN_CSG_Measurement_Report 811
#define CSN1_Packet_Measurement_Report_message_content_UTRAN_CSG_Measurement_Report_SIZE   0
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Non_distribution_part_error 3147
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_Low_Access_Priority_Signalling 2096
#define CSN1_Packet_Resource_Request_message_content_Low_Access_Priority_Signalling_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_EGPRS_Window_Size 2167
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_NPM_Transfer_Time 2170
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Downlink_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_error 3215
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Frequency_Parameters_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_Control_Timeslot_C1 2189
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_Control_Timeslot_C2 2190
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_Packet_channel_request_11_bit_message_content_One_Phase_Access_Request  41
#define CSN1_Packet_channel_request_11_bit_message_content_One_Phase_Access_Request_SIZE  11
#define CSN1_Packet_channel_request_11_bit_message_content_Single_block_MBMS_access  55
#define CSN1_Packet_channel_request_11_bit_message_content_Single_block_MBMS_access_SIZE  11
#define CSN1_Packet_channel_request_11_bit_message_content_Two_Phase_Access_Request  47
#define CSN1_Packet_channel_request_11_bit_message_content_Two_Phase_Access_Request_SIZE  11
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Uplink_Control_Timeslot_C1 1682
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Uplink_Control_Timeslot_C2 1683
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_Uplink_Control_Timeslot_C1 1679
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_Measurement_Bandwidth 2062
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_Single_Uplink_Assignment_2_IE_Uplink_Assignment_PDCH_Pairs_Description 1861
#define CSN1_Single_Uplink_Assignment_2_IE_Uplink_Assignment_PDCH_Pairs_Description_SIZE   0
#define CSN1_EGPRS_Ack_Nack_Description_struct_COMPRESSED_BITMAP_STARTING_COLOR_CODE 164
#define CSN1_EGPRS_Ack_Nack_Description_struct_COMPRESSED_BITMAP_STARTING_COLOR_CODE_SIZE   1
#define CSN1_ENH_Reporting_parameters_struct_GPRS_MEASUREMENT_Parameters_Description 1532
#define CSN1_ENH_Reporting_parameters_struct_GPRS_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_FDD_REPORTING_OFFSET 2011
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_FDD_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_TDD_REPORTING_OFFSET 2014
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_TDD_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__400_REPORTING_THRESHOLD  25
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__400_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__850_REPORTING_THRESHOLD  29
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__850_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__900_REPORTING_THRESHOLD  21
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__900_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Global_Packet_Timing_Advance_IE_DOWNLINK_TIMING_ADVANCE_TIMESLOT_NUMBER 234
#define CSN1_Global_Packet_Timing_Advance_IE_DOWNLINK_TIMING_ADVANCE_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Individual_priorities_IE__3G_Individual_Priority_Parameters_Description 1077
#define CSN1_Individual_priorities_IE__3G_Individual_Priority_Parameters_Description_SIZE   0
#define CSN1_MBMS_Assignment_Distribution_message_content_Estimated_Session_Duration 2270
#define CSN1_MBMS_Assignment_Distribution_message_content_Estimated_Session_Duration_SIZE   8
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_Bearer_Identity 990
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_Bearer_Identity_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_PTM_CHANGE_MARK 988
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_PTM_CHANGE_MARK_SIZE   2
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_NEIGHBOUR_CELL_INDEX 986
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_NEIGHBOUR_CELL_INDEX_SIZE   7
#define CSN1_Measurement_Control_Parameters_Description_IE_Measurement_Control_UTRAN 270
#define CSN1_Measurement_Control_Parameters_Description_IE_Measurement_Control_UTRAN_SIZE   1
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C1 1423
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C2 3171
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Multislot_capability_struct_GPRS_Extended_Dynamic_Allocation_Capability 1306
#define CSN1_Multislot_capability_struct_GPRS_Extended_Dynamic_Allocation_Capability_SIZE   1
#define CSN1_Packet_CS_Release_message_content_Enhanced_Flexible_Timeslot_Assignment 2235
#define CSN1_Packet_CS_Release_message_content_Enhanced_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_Packet_Cell_Change_Continue_message_content_Non_distribution_part_error 3110
#define CSN1_Packet_Cell_Change_Continue_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Cell_Change_Order_message_content_Address_information_part_error 3232
#define CSN1_Packet_Cell_Change_Order_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_DBPSCH_Assignment_message_content_Address_information_part_error 3145
#define CSN1_Packet_DBPSCH_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_DBPSCH_message_part_error 3133
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_DBPSCH_message_part_error_SIZE   0
#define CSN1_Packet_MBMS_Announcement_message_content_MBMS_p_t_m_channel_description 2276
#define CSN1_Packet_MBMS_Announcement_message_content_MBMS_p_t_m_channel_description_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_Address_information_part_error 3209
#define CSN1_Packet_Measurement_Order_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_DLMC_Carrier_Bitmap 394
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_DLMC_Carrier_Bitmap_SIZE   0
#define CSN1_Packet_Serving_Cell_Data_message_content_Address_information_part_error 3151
#define CSN1_Packet_Serving_Cell_Data_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_DOWNLINK_ASSIGNMENT_C1 2199
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_DOWNLINK_ASSIGNMENT_C1_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_DOWNLINK_ASSIGNMENT_C2 2200
#define CSN1_Packet_Timeslot_Reconfigure_message_content_MTTI_DOWNLINK_ASSIGNMENT_C2_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Non_distribution_part_error 3213
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Address_information_part_error 3183
#define CSN1_Packet_Uplink_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Packet_Extended_Timing_Advance 1558
#define CSN1_Packet_Uplink_Assignment_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_channel_request_11_bit_message_content_Dedicated_channel_request  53
#define CSN1_Packet_channel_request_11_bit_message_content_Dedicated_channel_request_SIZE  11
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_DC_struct_Downlink_TBF_assignment 1428
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_DC_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_SC_struct_Downlink_TBF_assignment 1426
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_SC_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_struct_E_UTRAN_PRIORITY 1087
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_TIMESLOT_ALLOCATION_C1 1767
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_TIMESLOT_ALLOCATION_C2 1768
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_TBF_Starting_Time 903
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_TBF_Starting_Time_SIZE   0
#define CSN1_E_UTRAN_Target_cell_with_extended_EARFCN_IE_Physical_Layer_Cell_Identity 281
#define CSN1_E_UTRAN_Target_cell_with_extended_EARFCN_IE_Physical_Layer_Cell_Identity_SIZE   9
#define CSN1_GPRS_3G_Additional_Measurement_Parameters_Description_struct_FDD_RSCPmin 1209
#define CSN1_GPRS_3G_Additional_Measurement_Parameters_Description_struct_FDD_RSCPmin_SIZE   4
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING  32
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING  35
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1800_REPORTING_THRESHOLD  23
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1800_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1900_REPORTING_THRESHOLD  27
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct__1900_REPORTING_THRESHOLD_SIZE   3
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Distribution_part_error 3227
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Distribution_part_error_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_bearer_description 2259
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_bearer_description_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Distribution_part_error 3176
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_C1 1411
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_C2 1412
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Uplink_Control_Timeslot 1394
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_CHANNEL_CODING_COMMAND 1651
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C1 1676
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C2 3194
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_TLLI_BLOCK_CHANNEL_CODING 1608
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_TLLI_BLOCK_CHANNEL_CODING_SIZE   1
#define CSN1_Multiple_Uplink_Assignment_2_IE_Uplink_Assignment_PDCH_Pairs_Description 1811
#define CSN1_Multiple_Uplink_Assignment_2_IE_Uplink_Assignment_PDCH_Pairs_Description_SIZE   0
#define CSN1_Multislot_capability_struct_EGPRS_Extended_Dynamic_Allocation_Capability 1311
#define CSN1_Multislot_capability_struct_EGPRS_Extended_Dynamic_Allocation_Capability_SIZE   1
#define CSN1_Neighbouring_Cell_Report_struct_NUMBER_OF_NEIGHBOURING_CELL_MEASUREMENTS 766
#define CSN1_Neighbouring_Cell_Report_struct_NUMBER_OF_NEIGHBOURING_CELL_MEASUREMENTS_SIZE   3
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_STARTING_SEQUENCE_NUMBER 357
#define CSN1_Packet_DBPSCH_Downlink_Ack_Nack_message_content_STARTING_SEQUENCE_NUMBER_SIZE   8
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI 504
#define CSN1_Packet_DBPSCH_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI_SIZE  32
#define CSN1_Packet_Downlink_Assignment_message_content_LINK_QUALITY_MEASUREMENT_MODE 1912
#define CSN1_Packet_Downlink_Assignment_message_content_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_NC_Measurement_Report 815
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_NC_Measurement_Report_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_CSG_Cells_Reporting_Description 2048
#define CSN1_Packet_Measurement_Order_message_content_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_Packet_Measurement_Report_message_content_E_UTRAN_CSG_Measurement_Report 812
#define CSN1_Packet_Measurement_Report_message_content_E_UTRAN_CSG_Measurement_Report_SIZE   0
#define CSN1_Packet_Queueing_Notification_message_content_Non_distribution_part_error 3123
#define CSN1_Packet_Queueing_Notification_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_TIMESLOT_ALLOCATION 2141
#define CSN1_Packet_Timeslot_Reconfigure_message_content_DOWNLINK_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EGPRS_Channel_Coding_Command 2165
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Global_Packet_Timing_Advance 2136
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_Downlink_TBF_assignment 1771
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_Downlink_TBF_assignment_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_GRANULARITY 956
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_USF_GRANULARITY_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_EGPRS_Ack_Nack_Description 1894
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_EGPRS_Ack_Nack_Description_SIZE   0
#define CSN1_EGPRS_Packet_channel_request_message_content_Signalling_by_IPA_capable_MS  70
#define CSN1_EGPRS_Packet_channel_request_message_content_Signalling_by_IPA_capable_MS_SIZE  11
#define CSN1_ENH_Measurement_parameters_struct_GPRS_MEASUREMENT_Parameters_Description 1108
#define CSN1_ENH_Measurement_parameters_struct_GPRS_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_THRESHOLD  34
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_THRESHOLD  37
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Measurement_Control_Parameters_Description_IE_Measurement_Control_E_UTRAN 268
#define CSN1_Measurement_Control_Parameters_Description_IE_Measurement_Control_E_UTRAN_SIZE   1
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Power_Control_Parameters 1388
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Power_Control_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Distribution_part_error 3199
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Distribution_part_error_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_C1 1666
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_C1_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_C2 1667
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_C2_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_error 3186
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Frequency_Parameters_error_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Enhanced_Flexible_Timeslot_Assignment 2402
#define CSN1_PS_Handover_Command_message_content_Enhanced_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_Packet_Downlink_Assignment_message_content_Address_information_part_error 3206
#define CSN1_Packet_Downlink_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_PDCH_pairs_configuration_error 3203
#define CSN1_Packet_Downlink_Assignment_message_content_PDCH_pairs_configuration_error_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Packet_Extended_Timing_Advance 1914
#define CSN1_Packet_Downlink_Assignment_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_Measurement_Order_message_content_E_UTRAN_NC_with_extended_EARFCNs 2059
#define CSN1_Packet_Measurement_Order_message_content_E_UTRAN_NC_with_extended_EARFCNs_SIZE   0
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Address_information_part_error 3148
#define CSN1_Packet_Neighbour_Cell_Data_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_LINK_QUALITY_MEASUREMENT_MODE 2169
#define CSN1_Packet_Timeslot_Reconfigure_message_content_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_Qmin 2047
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_Qmin_SIZE   4
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_Qsearch_C_Initial 1201
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_Qsearch_C_Initial_SIZE   1
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents 1282
#define CSN1_Dual_Carrier_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents_SIZE   4
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_Timeslot_Allocation 922
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_Timeslot_Allocation_SIZE   0
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_Channel_Request_Description 1885
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_Channel_Request_Description_SIZE  24
#define CSN1_ENH_Reporting_parameters_struct_GPRS_3G_MEASUREMENT_Parameters_Description 1533
#define CSN1_ENH_Reporting_parameters_struct_GPRS_3G_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_FDD_REPORTING_THRESHOLD 2009
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_TDD_REPORTING_THRESHOLD 2012
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Length_Indicator_of_MS_ID 2252
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Length_Indicator_of_MS_ID_SIZE   2
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Distribution_part_error 3159
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Distribution_part_error_SIZE   0
#define CSN1_MBMS_bearer_description_struct_TIMESLOT_ALLOCATION_UPLINK_FEEDBACK_CHANNEL 1708
#define CSN1_MBMS_bearer_description_struct_TIMESLOT_ALLOCATION_UPLINK_FEEDBACK_CHANNEL_SIZE   3
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Uplink_EGPRS_Window_Size 1660
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Uplink_EGPRS_Window_Size_SIZE   5
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Non_distribution_part_error 3185
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Cell_Change_Continue_message_content_Address_information_part_error 3111
#define CSN1_Packet_Cell_Change_Continue_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content__3G_CCN_Measurement_Report 717
#define CSN1_Packet_Cell_Change_Notification_message_content__3G_CCN_Measurement_Report_SIZE   0
#define CSN1_Packet_Cell_Change_Order_message_content_E_UTRAN_IPP_with_extended_EARFCNs 2330
#define CSN1_Packet_Cell_Change_Order_message_content_E_UTRAN_IPP_with_extended_EARFCNs_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_E_UTRAN_IPP_with_extended_EARFCNs 2058
#define CSN1_Packet_Measurement_Order_message_content_E_UTRAN_IPP_with_extended_EARFCNs_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_Iu_Mode_Neighbour_Cell_Parameters 1976
#define CSN1_Packet_Measurement_Order_message_content_Iu_Mode_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_NC_Iu_MODE_ONLY_CAPABLE_CELL_LIST 1977
#define CSN1_Packet_Measurement_Order_message_content_NC_Iu_MODE_ONLY_CAPABLE_CELL_LIST_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Carrier_Identification 392
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Carrier_Identification_SIZE   2
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Address_information_part_error 3217
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PDCH_pairs_configuration_error 3214
#define CSN1_Packet_Timeslot_Reconfigure_message_content_PDCH_pairs_configuration_error_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Packet_Extended_Timing_Advance 2144
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_Uplink_Assignment_message_content_Dual_Carrier_Frequency_Parameters 1590
#define CSN1_Packet_Uplink_Assignment_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_TBF_Starting_Time 957
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_TBF_Starting_Time_SIZE   0
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_EGPRS_Channel_Quality_Report 1884
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_message_content_EGPRS_Channel_Quality_Report_SIZE   0
#define CSN1_Individual_priorities_IE_E_UTRAN_Individual_Priority_Parameters_Description 1083
#define CSN1_Individual_priorities_IE_E_UTRAN_Individual_Priority_Parameters_Description_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Estimated_Session_Duration 2260
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Estimated_Session_Duration_SIZE   8
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_error 3168
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Frequency_Parameters_error_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Uplink_Control_Timeslot_C1 1416
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Uplink_Control_Timeslot_C2 1417
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command 1614
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error 3113
#define CSN1_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error 3121
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error_SIZE   0
#define CSN1_Packet_Queueing_Notification_message_content_Address_information_part_error 3124
#define CSN1_Packet_Queueing_Notification_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_EGPRS_BEP_Link_Quality_Measurements 2084
#define CSN1_Packet_Resource_Request_message_content_EGPRS_BEP_Link_Quality_Measurements_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_Iu_mode_Channel_Request_Description 2090
#define CSN1_Packet_Resource_Request_message_content_Iu_mode_Channel_Request_Description_SIZE   0
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_struct_EARFCN_extended 661
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_struct_EARFCN_extended_SIZE  18
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_Uplink_Control_Timeslot_C1 1769
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_Uplink_Control_Timeslot_C2 1770
#define CSN1_BTTI_Multiple_Downlink_Assignment_struct_12_48a_5_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_Cells_Reporting_Description 2049
#define CSN1_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_CS_RR_Info 2460
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_CS_RR_Info_SIZE   0
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_PS_RR_Info 2502
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_PS_RR_Info_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_UPLINK_TFI_ASSIGNMENT 902
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_IE_INTERFERENCE_MEASUREMENTS 577
#define CSN1_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_IE_INTERFERENCE_MEASUREMENTS_SIZE   0
#define CSN1_ENH_Measurement_parameters_struct_GPRS_3G_MEASUREMENT_Parameters_Description 1109
#define CSN1_ENH_Measurement_parameters_struct_GPRS_3G_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_Physical_Layer_Cell_Identity 725
#define CSN1_E_UTRAN_Target_Cell_with_extended_EARFCN_struct_Physical_Layer_Cell_Identity_SIZE   9
#define CSN1_GPRS_3G_Additional_Measurement_Parameters_Description_struct_FDD_Qmin_Offset 1208
#define CSN1_GPRS_3G_Additional_Measurement_Parameters_Description_struct_FDD_Qmin_Offset_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_2 2010
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_2 2013
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_Iu_mode_Only_Cell_selection_params 858
#define CSN1_Iu_mode_Only_Neighbour_Cell_params_struct_Iu_mode_Only_Cell_selection_params_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Non_distribution_part_error 3225
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MPRACH_Control_Parameters 1021
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MPRACH_Control_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Non_distribution_part_error 3167
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Power_Control_Parameters_C1 1414
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Power_Control_Parameters_C1_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Power_Control_Parameters_C2 1415
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Power_Control_Parameters_C2_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Downlink_EGPRS_Window_Size 1659
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_error 3191
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Frequency_Parameters_error_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Multiple_Uplink_Assignment 1656
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Multiple_Uplink_Assignment_SIZE   0
#define CSN1_Multiple_Uplink_Assignment_2_struct_Uplink_Assignment_PDCH_Pairs_Description 1693
#define CSN1_Multiple_Uplink_Assignment_2_struct_Uplink_Assignment_PDCH_Pairs_Description_SIZE   0
#define CSN1_PSI3_quater_message_content__3G_Initial_Dedicated_Mode_Reporting_Description 1198
#define CSN1_PSI3_quater_message_content__3G_Initial_Dedicated_Mode_Reporting_Description_SIZE   0
#define CSN1_PSI5_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_2 1534
#define CSN1_PSI5_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_2_SIZE   0
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Iu_mode_Channel_Request_Description 350
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Iu_mode_Channel_Request_Description_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Dual_Carrier_Frequency_Parameters 1945
#define CSN1_Packet_Downlink_Assignment_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Power_Control_Parameters 390
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Power_Control_Parameters_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_Extended_Channel_Request_Description 2092
#define CSN1_Packet_Resource_Request_message_content_Extended_Channel_Request_Description_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_Downlink_TBF_assignment 1780
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_Downlink_TBF_assignment_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_12_48a_5_Downlink_TBF_assignment 1784
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_12_48a_5_Downlink_TBF_assignment_SIZE   0
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_RSRPmin 2046
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_RSRPmin_SIZE   5
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_struct_E_UTRAN_PRIORITY 662
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY 1078
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY_SIZE   3
#define CSN1_E_UTRAN_NC_with_extended_EARFCNs_IE_Repeated_E_UTRAN_NC_with_extended_EARFCNs 2060
#define CSN1_E_UTRAN_NC_with_extended_EARFCNs_IE_Repeated_E_UTRAN_NC_with_extended_EARFCNs_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Non_distribution_part_error 3190
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Address_information_part_error 3188
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Packet_Extended_Timing_Advance 1610
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Extended_Channel_Request_Description 353
#define CSN1_Packet_Downlink_Ack_Nack_message_content_Extended_Channel_Request_Description_SIZE   0
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_E_UTRAN_Measurement_Report 834
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_E_UTRAN_Measurement_Report_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Dual_Carrier_Frequency_Parameters 2187
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_QQUALMIN 2045
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_QQUALMIN_SIZE   4
#define CSN1_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_Cells_Reporting_Description 2053
#define CSN1_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_PS_RR_2_Info 2484
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_PS_RR_2_Info_SIZE   0
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_PS_RR_3_Info 2463
#define CSN1_DTM_Handover_to_A_Gb_mode_Payload_description_struct_DTM_Handover_PS_RR_3_Info_SIZE   0
#define CSN1_GSM_target_cell_struct_GPRS_3G_Additional_Measurement_Parameters_Description_2 2307
#define CSN1_GSM_target_cell_struct_GPRS_3G_Additional_Measurement_Parameters_Description_2_SIZE   0
#define CSN1_MBMS_Assignment_Distribution_message_content_MBMS_In_band_Signalling_Indicator 2271
#define CSN1_MBMS_Assignment_Distribution_message_content_MBMS_In_band_Signalling_Indicator_SIZE   1
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_LINK_QUALITY_MEASUREMENT_MODE 1391
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_EGPRS_Channel_Coding_Command 1657
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Global_Packet_Timing_Advance 1652
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Multiple_Downlink_Assignment 1655
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Multiple_Downlink_Assignment_SIZE   0
#define CSN1_PS_Handover_Command_message_content_Measurement_Control_Parameters_Description 2401
#define CSN1_PS_Handover_Command_message_content_Measurement_Control_Parameters_Description_SIZE   0
#define CSN1_PS_Handover_Radio_Resources_3_IE_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support 2383
#define CSN1_PS_Handover_Radio_Resources_3_IE_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support_SIZE   1
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_CCN_Measurement_Report 702
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_CCN_Measurement_Report_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Enhanced_Flexible_Timeslot_Assignment 1577
#define CSN1_Packet_Uplink_Assignment_message_content_Enhanced_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD 2050
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_TDD_REPORTING_THRESHOLD 2052
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_FDD_MULTIRAT_REPORTING 1204
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_FDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_TDD_MULTIRAT_REPORTING 1206
#define CSN1__3G_Initial_Dedicated_Mode_Reporting_Description_struct_TDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Address_information_part_error 3226
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Address_information_part_error_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Length_of_MBMS_Bearer_Identity 2263
#define CSN1_MBMS_Assignment_Non_distribution_message_content_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_DOWNLINK_TIMESLOT_ALLOCATION 1002
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_DOWNLINK_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Serving_MBMS_Bearer_Identity 1004
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Serving_MBMS_Bearer_Identity_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Address_information_part_error 3175
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PDCH_pairs_configuration_error 3169
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_PDCH_pairs_configuration_error_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Packet_Extended_Timing_Advance 1393
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_LINK_QUALITY_MEASUREMENT_MODE 1661
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_PS_Handover_Radio_Resources_3_IE_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 2382
#define CSN1_PS_Handover_Radio_Resources_3_IE_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_Packet_CS_Release_message_content_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support 2248
#define CSN1_Packet_CS_Release_message_content_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support_SIZE   1
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_UTRAN_CSG_Measurement_Report 835
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_UTRAN_CSG_Measurement_Report_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error 3118
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_ADDITIONAL_MS_RAC_INFORMATION_AVAILABLE 2087
#define CSN1_Packet_Resource_Request_message_content_ADDITIONAL_MS_RAC_INFORMATION_AVAILABLE_SIZE   1
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_Uplink_Control_Timeslot_C1 1778
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_Uplink_Control_Timeslot_C2 1779
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_Uplink_Control_Timeslot_C2_SIZE   3
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_12_48a_5_Uplink_Control_Timeslot_C1 1783
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_12_48a_5_Uplink_Control_Timeslot_C1_SIZE   3
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_EGPRS_Ack_Nack_Description 1377
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_EGPRS_Ack_Nack_Description_SIZE   0
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_EGPRS_Ack_Nack_Description 1122
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_EGPRS_Ack_Nack_Description_SIZE   0
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_Radio_Bearer_Starting_Time 2262
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_Radio_Bearer_Starting_Time_SIZE  16
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Address_information_part_error 3198
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Address_information_part_error_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_PDCH_pairs_configuration_error 3192
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_PDCH_pairs_configuration_error_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Packet_Extended_Timing_Advance 1654
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Dual_Carrier_Frequency_Parameters 1625
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Carrier_for_Interference_Measurements 1960
#define CSN1_Packet_Downlink_Assignment_message_content_Carrier_for_Interference_Measurements_SIZE   4
#define CSN1_Packet_Downlink_Assignment_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 1937
#define CSN1_Packet_Downlink_Assignment_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_Packet_Downlink_Assignment_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 1938
#define CSN1_Packet_Downlink_Assignment_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Global_Packet_Timing_Advance 389
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Global_Packet_Timing_Advance_SIZE   0
#define CSN1_Packet_Resource_Request_message_content_EGPRS_Timeslot_Link_Quality_Measurements 2085
#define CSN1_Packet_Resource_Request_message_content_EGPRS_Timeslot_Link_Quality_Measurements_SIZE   0
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2 2051
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_EGPRS_Channel_Quality_Report_Type_2_IE_EGPRS_BEP_Link_Quality_Measurements_Type_2 1025
#define CSN1_EGPRS_Channel_Quality_Report_Type_2_IE_EGPRS_BEP_Link_Quality_Measurements_Type_2_SIZE   0
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_Channel_Request_Description 1371
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_Channel_Request_Description_SIZE  24
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Length_of_MBMS_Bearer_Identity 989
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Neighbour_MBMS_Bearer_Identity 1006
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Neighbour_MBMS_Bearer_Identity_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Multiple_Downlink_TBF_Assignment 1395
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Multiple_Downlink_TBF_Assignment_SIZE   0
#define CSN1_PSI3_quater_message_content_GPRS_3G_Additional_Measurement_Parameters_Description 1207
#define CSN1_PSI3_quater_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_SIZE   7
#define CSN1_Packet_Cell_Change_Order_message_content_E_UTRAN_Target_cell_with_extended_EARFCN 2329
#define CSN1_Packet_Cell_Change_Order_message_content_E_UTRAN_Target_cell_with_extended_EARFCN_SIZE   0
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_E_UTRAN_CSG_Measurement_Report 836
#define CSN1_Packet_Enhanced_Measurement_Report_message_content_E_UTRAN_CSG_Measurement_Report_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Carrier_for_Interference_Measurements 2206
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Carrier_for_Interference_Measurements_SIZE   4
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Enhanced_Flexible_Timeslot_Assignment 2173
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Enhanced_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 2181
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 2182
#define CSN1_Packet_Timeslot_Reconfigure_message_content_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_Identifier_extension 890
#define CSN1_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_Identifier_extension_SIZE   4
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_E_UTRAN_Parameters_Description 2003
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_E_UTRAN_Parameters_Description_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 1681
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 1678
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_low_Q 2044
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_low_Q_SIZE   5
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_EXTENDED_DYNAMIC_ALLOCATION 898
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_EGPRS_Channel_Quality_Report 1119
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_EGPRS_Channel_Quality_Report_SIZE   0
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD 2054
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_TDD_REPORTING_THRESHOLD 2056
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_DEFAULT_E_UTRAN_PRIORITY 1084
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_DEFAULT_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_In_band_Signalling_Indicator 2261
#define CSN1_MBMS_Assignment_Non_distribution_message_content_MBMS_In_band_Signalling_Indicator_SIZE   1
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_Radio_Bearer_Starting_Time 1009
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_Radio_Bearer_Starting_Time_SIZE  16
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_p_t_m_Frequency_Parameters 996
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_p_t_m_Frequency_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Dual_Carrier_Frequency_Parameters 1413
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error 3120
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Packet_Extended_Timing_Advance 391
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_Packet_Resource_Request_message_content_EGPRS_BEP_Link_Quality_Measurements_Type_2 2094
#define CSN1_Packet_Resource_Request_message_content_EGPRS_BEP_Link_Quality_Measurements_Type_2_SIZE   0
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_high_Q 2043
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_high_Q_SIZE   5
#define CSN1_ETWS_Primary_Notification_struct_Total_No_Of_Segments_For_ETWS_Primary_Notification 2452
#define CSN1_ETWS_Primary_Notification_struct_Total_No_Of_Segments_For_ETWS_Primary_Notification_SIZE   4
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_BTTI_Multiple_Downlink_Assignment 1670
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_BTTI_Multiple_Downlink_Assignment_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Dual_Carrier_Frequency_Parameters 1668
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Dual_Carrier_Frequency_Parameters_SIZE   0
#define CSN1_PSI3_quater_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_2 1210
#define CSN1_PSI3_quater_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_2_SIZE   0
#define CSN1_Packet_Cell_Change_Failure_message_content_E_UTRAN_Target_cell_with_extended_EARFCN 692
#define CSN1_Packet_Cell_Change_Failure_message_content_E_UTRAN_Target_cell_with_extended_EARFCN_SIZE   0
#define CSN1_Packet_Measurement_Order_message_content_Measurement_Control_Parameters_Description 2039
#define CSN1_Packet_Measurement_Order_message_content_Measurement_Control_Parameters_Description_SIZE   0
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Global_Power_Control_Parameters 388
#define CSN1_Packet_Power_Control_Timing_Advance_message_content_Global_Power_Control_Parameters_SIZE  24
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_MS_Radio_Access_Capability_2 2214
#define CSN1_Additional_MS_Radio_Access_Capabilities_message_content_MS_Radio_Access_Capability_2_SIZE   0
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2 2055
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_TDD_REPORTING_THRESHOLD_2 2057
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_TDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_In_band_Signalling_Indicator 1010
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_MBMS_In_band_Signalling_Indicator_SIZE   1
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Enhanced_Flexible_Timeslot_Assignment 1620
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Enhanced_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_Packet_Measurement_Order_message_content_Priority_and_E_UTRAN_Parameters_Description 1986
#define CSN1_Packet_Measurement_Order_message_content_Priority_and_E_UTRAN_Parameters_Description_SIZE   0
#define CSN1_Packet_channel_request_11_bit_message_content_Single_Block_Without_TBF_Establishment  51
#define CSN1_Packet_channel_request_11_bit_message_content_Single_Block_Without_TBF_Establishment_SIZE  11
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_FREQUENCY_INDEX 2042
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_EXTENDED_DYNAMIC_ALLOCATION 953
#define CSN1_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_EPD_A_N_Extension_Type_2_length 1373
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_EPD_A_N_Extension_Type_2_length_SIZE   8
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_DC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 1427
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_DC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_SC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 1425
#define CSN1_RTTI_Multiple_Downlink_TBF_Assignment_SC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1_EGPRS_Channel_Quality_Report_Type_2_IE_EGPRS_Timeslot_Link_Quality_Measurements_Type_2 1027
#define CSN1_EGPRS_Channel_Quality_Report_Type_2_IE_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_BTTI_Multiple_Downlink_TBF_Assignment 1419
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_BTTI_Multiple_Downlink_TBF_Assignment_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_RTTI_Multiple_Downlink_Assignment_DC 3196
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_RTTI_Multiple_Downlink_Assignment_DC_SIZE   0
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_RTTI_Multiple_Downlink_Assignment_SC 3193
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_RTTI_Multiple_Downlink_Assignment_SC_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct__3G_Priority_Parameters_Description 1993
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct__3G_Priority_Parameters_Description_SIZE   0
#define CSN1_EGPRS_Packet_channel_request_message_content_One_phase_Access_Request_in_RLC_unack_mode  67
#define CSN1_EGPRS_Packet_channel_request_message_content_One_phase_Access_Request_in_RLC_unack_mode_SIZE  11
#define CSN1_EGPRS_Packet_channel_request_message_content_Two_Phase_Access_Request_by_IPA_capable_MS  65
#define CSN1_EGPRS_Packet_channel_request_message_content_Two_Phase_Access_Request_by_IPA_capable_MS_SIZE  11
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Enhanced_Flexible_Timeslot_Assignment 1665
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Enhanced_Flexible_Timeslot_Assignment_SIZE   1
#define CSN1_Packet_Resource_Request_message_content_EGPRS_Timeslot_Link_Quality_Measurements_Type_2 2095
#define CSN1_Packet_Resource_Request_message_content_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_SIZE   0
#define CSN1_Packet_Uplink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 1576
#define CSN1_Packet_Uplink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_GPRS_3G_Additional_Measurement_Parameters_Description_2_struct_FDD_REPORTING_THRESHOLD_2  40
#define CSN1_GPRS_3G_Additional_Measurement_Parameters_Description_2_struct_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_Target_Cell_with_extended_EARFCN 722
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_Target_Cell_with_extended_EARFCN_SIZE   0
#define CSN1_Packet_Cell_Change_Notification_message_content_UTRAN_CSG_Target_Cell_Measurement_Report 704
#define CSN1_Packet_Cell_Change_Notification_message_content_UTRAN_CSG_Target_Cell_Measurement_Report_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support 1956
#define CSN1_Packet_Downlink_Assignment_message_content_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support_SIZE   1
#define CSN1_Packet_channel_request_11_bit_message_content_One_Phase_Access_Request_in_RLC_unack_mode  52
#define CSN1_Packet_channel_request_11_bit_message_content_One_Phase_Access_Request_in_RLC_unack_mode_SIZE  11
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_EGPRS_Channel_Quality_Report_Type_2 1370
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content_EGPRS_Channel_Quality_Report_Type_2_SIZE   0
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_IE_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs 660
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_IE_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_SIZE   0
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Length_of_Serving_MBMS_Bearer_Identity 1003
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Length_of_Serving_MBMS_Bearer_Identity_SIZE   3
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_RTTI_Multiple_Downlink_TBF_Assignment_DC 3173
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_RTTI_Multiple_Downlink_TBF_Assignment_DC_SIZE   0
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_RTTI_Multiple_Downlink_TBF_Assignment_SC 3170
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_RTTI_Multiple_Downlink_TBF_Assignment_SC_SIZE   0
#define CSN1_Packet_Downlink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 1922
#define CSN1_Packet_Downlink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_Packet_Measurement_Order_message_content_Enhanced_Cell_Reselection_Parameters_Description 2040
#define CSN1_Packet_Measurement_Order_message_content_Enhanced_Cell_Reselection_Parameters_Description_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support 2203
#define CSN1_Packet_Timeslot_Reconfigure_message_content_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support_SIZE   1
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_CSG_Target_Cell_Measurement_Report 703
#define CSN1_Packet_Cell_Change_Notification_message_content_E_UTRAN_CSG_Target_Cell_Measurement_Report_SIZE   0
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 2172
#define CSN1_Packet_Timeslot_Reconfigure_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 1777
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_12_48a_5_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_12_48a_5_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 1782
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_12_48a_5_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_Secondary_Dual_Carrier_Channel_Report 1120
#define CSN1_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content_Secondary_Dual_Carrier_Channel_Report_SIZE   0
#define CSN1_EGPRS_Packet_channel_request_message_content_One_Phase_Access_Request_by_Reduced_Latency_MS  62
#define CSN1_EGPRS_Packet_channel_request_message_content_One_Phase_Access_Request_by_Reduced_Latency_MS_SIZE  11
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Length_of_Neighbour_MBMS_Bearer_Identity 1005
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_Length_of_Neighbour_MBMS_Bearer_Identity_SIZE   3
#define CSN1_Enhanced_Cell_Reselection_Parameters_IE_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters 2041
#define CSN1_Enhanced_Cell_Reselection_Parameters_IE_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_SIZE   0
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 1619
#define CSN1_Multiple_TBF_Uplink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_TIMESLOT_ALLOCATION_UPLINK_FEEDBACK_CHANNEL 1008
#define CSN1_MBMS_Neighbouring_Cell_Information_message_content_TIMESLOT_ALLOCATION_UPLINK_FEEDBACK_CHANNEL_SIZE   3
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 1431
#define CSN1_Multiple_TBF_Downlink_Assignment_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_Serving_Cell_Priority_Parameters_Description 1987
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_Serving_Cell_Priority_Parameters_Description_SIZE  15
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM 1664
#define CSN1_Multiple_TBF_Timeslot_Reconfigure_message_content_Indication_of_Upper_Layer_PDU_Start_for_RLC_UM_SIZE   1
#define CSN1_Packet_Measurement_Order_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_2 1978
#define CSN1_Packet_Measurement_Order_message_content_GPRS_3G_Additional_Measurement_Parameters_Description_2_SIZE   0
#define CSN1_CN_Domain_Specific_DRX_Cycle_Length_Coefficient_IE_CN_Domain_Specific_DRX_Cycle_Length_Coefficient 493
#define CSN1_CN_Domain_Specific_DRX_Cycle_Length_Coefficient_IE_CN_Domain_Specific_DRX_Cycle_Length_Coefficient_SIZE   2
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_Repeated_Individual_UTRAN_Priority_Parameters 1079
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_Repeated_Individual_UTRAN_Priority_Parameters_SIZE   0
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_Timeslot_Allocation_with_Power_Control_Parameters 904
#define CSN1_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment_Timeslot_Allocation_with_Power_Control_Parameters_SIZE   0
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_Repeated_Individual_E_UTRAN_Priority_Parameters 1085
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_Repeated_Individual_E_UTRAN_Priority_Parameters_SIZE   0


/* DEFINITIONS */
#define CSN1C_DEF_bit                    0
#define CSN1C_DEF_bit_string             2
#define CSN1C_DEF_spare_L                4
#define CSN1C_DEF_spare_bits             6
#define CSN1C_DEF_no_string             19
#define CSN1C_DEF_spare_bit             22
#define CSN1C_DEF_octet                 24
#define CSN1C_DEF_spare_padding         26
#define CSN1C_DEF_padding_bits          42
#define CSN1C_DEF__3G_Target_Cell_Struct  50
#define CSN1C_DEF_E_UTRAN_CCN_Measurement_Report_struct 123
#define CSN1C_DEF_HCS_struct           149
#define CSN1C_DEF_GPRS_REP_PRIORITY_Description_struct 156
#define CSN1C_DEF_GPRS_MEASUREMENT_PARAMETERS_Description_struct 176
#define CSN1C_DEF_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct 313
#define CSN1C_DEF_CCN_Support_Description_struct 418
#define CSN1C_DEF_GPRS_3G_Additional_Measurement_Parameters_Description_2_struct 438
#define CSN1C_DEF_Packet_channel_request_11_bit_message_content 455
#define CSN1C_DEF_EGPRS_Packet_channel_request_message_content 660
#define CSN1C_DEF_Response_Time_struct 859
#define CSN1C_DEF_Assignment_Info_struct 872
#define CSN1C_DEF_Additional_PFCs_struct_DN 881
#define CSN1C_DEF_E_UTRAN_Measurement_Report_struct 906
#define CSN1C_DEF_EXT_Frequency_list_struct 934
#define CSN1C_DEF_Page_info_struct     976
#define CSN1C_DEF_SI13_PBCCH_Location_struct 1001
#define CSN1C_DEF_NCP2_Property_struct 1024
#define CSN1C_DEF_COMPACT_NCP2_Property_struct 1037
#define CSN1C_DEF_RTD6_Struct          1066
#define CSN1C_DEF_RTD12_Struct         1083
#define CSN1C_DEF_Channel_Group_struct 1100
#define CSN1C_DEF_Access_Technologies_Request_struct 1127
#define CSN1C_DEF_Dynamic_Allocation_2_struct 1147
#define CSN1C_DEF_Additional_PFCs_struct_UP 1407
#define CSN1C_DEF_Timeslot_description_struct 1432
#define CSN1C_DEF_Timeslot_description_2_struct 1599
#define CSN1C_DEF_Handover_Access_8_bit_message 1938
#define CSN1C_DEF_Ack_Nack_Description_IE 1943
#define CSN1C_DEF_EGPRS_Ack_Nack_Description_struct 1956
#define CSN1C_DEF_EGPRS_BEP_Link_Quality_Measurements_IE 2026
#define CSN1C_DEF_Interference_Measurement_Report_Struct 2067
#define CSN1C_DEF_PDCH_Pairs_Description_IE 2196
#define CSN1C_DEF_EGPRS_BEP_Link_Quality_Measurements_Type_2_IE 2321
#define CSN1C_DEF_Channel_Request_Description_IE 2462
#define CSN1C_DEF_Iu_mode_Channel_Request_Description_IE 2483
#define CSN1C_DEF_Extended_Channel_Request_Description_IE 2523
#define CSN1C_DEF_Global_Power_Control_Parameters_IE 2567
#define CSN1C_DEF_GPRS_Power_Control_Parameters_IE 2596
#define CSN1C_DEF_Global_TFI_IE        2617
#define CSN1C_DEF_RFL_number_list_struct 2636
#define CSN1C_DEF_ARFCN_index_list_struct 2656
#define CSN1C_DEF_Packet_Request_Reference_IE 2676
#define CSN1C_DEF_Packet_Timing_Advance_IE 2685
#define CSN1C_DEF_Global_Packet_Timing_Advance_IE 2722
#define CSN1C_DEF_Power_Control_Parameters_IE 2779
#define CSN1C_DEF_PRACH_Control_Parameters_IE 2912
#define CSN1C_DEF_LSA_ID_information_struct 2959
#define CSN1C_DEF_COMPACT_reduced_MA_IE 2986
#define CSN1C_DEF_TMGI_IE              3027
#define CSN1C_DEF_MPRACH_Control_Parameters_IE 3054
#define CSN1C_DEF_Additional_PFCs_struct 3123
#define CSN1C_DEF_E_UTRAN_Target_cell_IE 3148
#define CSN1C_DEF_Measurement_Control_Parameters_Description_IE 3173
#define CSN1C_DEF_PCID_Group_IE        3238
#define CSN1C_DEF_PLMN_ID_struct       3302
#define CSN1C_DEF_E_UTRAN_Target_cell_with_extended_EARFCN_IE 3311
#define CSN1C_DEF_Reject_struct        3336
#define CSN1C_DEF_Packet_Control_Acknowledgement_message_content 3428
#define CSN1C_DEF_Packet_Control_Acknowledgement_11bit_a_content 3550
#define CSN1C_DEF_Packet_Control_Acknowledgement_11bit_b_content 3559
#define CSN1C_DEF_Packet_Control_Acknowledgement_8bit_content 3570
#define CSN1C_DEF_Packet_Cell_Change_Continue_message_content 3577
#define CSN1C_DEF_Cell_Selection_struct 3710
#define CSN1C_DEF_UTRAN_FDD_Description_struct 3821
#define CSN1C_DEF_UTRAN_TDD_Description_struct 3881
#define CSN1C_DEF_Iu_Mode_Cell_Selection_struct 3941
#define CSN1C_DEF_Iu_Mode_Only_Cell_Selection_struct 3967
#define CSN1C_DEF_Packet_Downlink_Ack_Nack_message_content 4074
#define CSN1C_DEF_Packet_DBPSCH_Downlink_Ack_Nack_message_content 4478
#define CSN1C_DEF_Downlink_TBF_assignment_2_struct 4555
#define CSN1C_DEF_Packet_Downlink_Dummy_Control_Block_message_content 4614
#define CSN1C_DEF_Packet_Uplink_Dummy_Control_Block_message_content 4678
#define CSN1C_DEF_Packet_Mobile_TBF_Status_message_content 4735
#define CSN1C_DEF_Container_repetition_struct 4823
#define CSN1C_DEF_Packet_PDCH_Release_message_content 4903
#define CSN1C_DEF_Packet_Polling_Request_message_content 4949
#define CSN1C_DEF_Packet_Power_Control_Timing_Advance_message_content 5131
#define CSN1C_DEF_Packet_PRACH_Parameters_message_content 5514
#define CSN1C_DEF_Packet_Queueing_Notification_message_content 5564
#define CSN1C_DEF_Packet_PSI_Status_message_content 5678
#define CSN1C_DEF_Packet_SI_Status_message_content 5815
#define CSN1C_DEF_Packet_Serving_Cell_SI_message_content 5980
#define CSN1C_DEF_Cell_Selection_struct_bis 6034
#define CSN1C_DEF_COMPACT_Cell_Selection_struct 6149
#define CSN1C_DEF_Iu_Mode_Only_Cell_Selection_struct_bis 6275
#define CSN1C_DEF_NCP2_Repeat_struct   6386
#define CSN1C_DEF_COMPACT_NCP2_Repeat_struct 6466
#define CSN1C_DEF_PSI6_message_content 6546
#define CSN1C_DEF_PSI15_message_content 6646
#define CSN1C_DEF_PSI16_message_content 6729
#define CSN1C_DEF_Packet_TBF_Release_message_content 6896
#define CSN1C_DEF_Packet_DBPSCH_Uplink_Ack_Nack_message_content 7040
#define CSN1C_DEF_Packet_Pause_message_content 7183
#define CSN1C_DEF_Downlink_TBF_assignment_2_struct_bis 7199
#define CSN1C_DEF_Physical_information_message_content 7290
#define CSN1C_DEF_Packet_CS_Request_message_content 7311
#define CSN1C_DEF_Packet_CS_Command_message_content 7332
#define CSN1C_DEF_MBMS_Service_Request_message_content 7461
#define CSN1C_DEF_MBMS_MS_ID_Assignment_message_content 7502
#define CSN1C_DEF_Packet_Physical_Information_message_content 7806
#define CSN1C_DEF_Packet_Application_Information_message_content 7831
#define CSN1C_DEF_EGPRS_Ack_Nack_Description_IE 7889
#define CSN1C_DEF_EGPRS_Timeslot_Link_Quality_Measurements_IE 7915
#define CSN1C_DEF_EGPRS_Timeslot_Link_Quality_Measurements_Type_2_IE 8195
#define CSN1C_DEF_Pulse_Format_IE      8395
#define CSN1C_DEF_GPRS_Mobile_Allocation_IE 8527
#define CSN1C_DEF_Starting_Frame_Number_Description_IE 8619
#define CSN1C_DEF_Cell_Identification_IE 8646
#define CSN1C_DEF_Extension_Bits_IE    8659
#define CSN1C_DEF_LSA_Parameters_IE    8677
#define CSN1C_DEF_MBMS_Sessions_List_IE 8704
#define CSN1C_DEF_RLC_Entity_Struct    8738
#define CSN1C_DEF_NAS_Container_for_PS_Handover_IE 8773
#define CSN1C_DEF_RRC_Container_IE     8798
#define CSN1C_DEF_Downlink_TBF_assignment_2_struct_12_48a_5 8830
#define CSN1C_DEF_E_UTRAN_CSG_Measurement_Report_IE 8933
#define CSN1C_DEF_UTRAN_CSG_Measurement_Report_IE 8977
#define CSN1C_DEF_DLMC_Channel_Quality_Report 9017
#define CSN1C_DEF_E_UTRAN_IPP_with_extended_EARFCNs_IE 9447
#define CSN1C_DEF_Packet_Access_Reject_message_content 9496
#define CSN1C_DEF_Packet_Cell_Change_Failure_message_content 9714
#define CSN1C_DEF_Packet_Cell_Change_Notification_message_content 10133
#define CSN1C_DEF_Iu_Mode_Neighbour_Cell_Params_struct 10730
#define CSN1C_DEF_Packet_DBPSCH_Assignment_message_content 10794
#define CSN1C_DEF_MBMS_Downlink_Ack_Nack_message_content 11218
#define CSN1C_DEF_Packet_Measurement_Report_message_content 11396
#define CSN1C_DEF_Packet_Enhanced_Measurement_Report_message_content 12053
#define CSN1C_DEF_Packet_Neighbour_Cell_Data_message_content 12470
#define CSN1C_DEF_Packet_Serving_Cell_Data_message_content 12630
#define CSN1C_DEF_Neighbour_Cell_params_struct 12766
#define CSN1C_DEF_Iu_mode_Only_Neighbour_Cell_params_struct 12839
#define CSN1C_DEF_PSI3_ter_message_content 12912
#define CSN1C_DEF_PSI4_message_content 13131
#define CSN1C_DEF_Packet_Uplink_Ack_Nack_message_content 13208
#define CSN1C_DEF_Dynamic_Allocation_struct_for_Packet_Uplink_Assignment 13953
#define CSN1C_DEF_Multi_Block_Allocation_struct 14340
#define CSN1C_DEF_Uplink_TBF_Assignment_struct 14401
#define CSN1C_DEF_Uplink_TBF_Assignment_2_struct 14569
#define CSN1C_DEF_Dynamic_Allocation_struct_for_Packet_Timeslot_Reconfigure 14771
#define CSN1C_DEF_Multiple_Downlink_Assignment_struct 15126
#define CSN1C_DEF_MBMS_Neighbouring_Cell_Information_message_content 15233
#define CSN1C_DEF_EGPRS_Channel_Quality_Report 15777
#define CSN1C_DEF_EGPRS_Channel_Quality_Report_Type_2_IE 15804
#define CSN1C_DEF_GPRS_Cell_Options_IE 15831
#define CSN1C_DEF_Downlink_Assignment_struct 16008
#define CSN1C_DEF_DLMC_UL_Carrier_Info_struct 16073
#define CSN1C_DEF_Individual_priorities_IE 16418
#define CSN1C_DEF_ENH_Measurement_parameters_struct 16609
#define CSN1C_DEF_NC_Iu_Mode_Only_Cell_List_struct 16899
#define CSN1C_DEF_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content 17017
#define CSN1C_DEF_EXT_Measurement_Parameters_struct 17117
#define CSN1C_DEF_PSI1_message_content 17252
#define CSN1C_DEF_PSI3_bis_message_content 17418
#define CSN1C_DEF_PSI3_quater_message_content 18137
#define CSN1C_DEF_PSI13_message_content 18595
#define CSN1C_DEF_Uplink_Assignment_struct 18926
#define CSN1C_DEF_Multiple_Uplink_Assignment_struct 19032
#define CSN1C_DEF_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content 19122
#define CSN1C_DEF_Frequency_Parameters_IE 19218
#define CSN1C_DEF_Dual_Carrier_Frequency_Parameters_IE 19365
#define CSN1C_DEF_MS_RA_capability_value_part_struct 19612
#define CSN1C_DEF_GPRS_mode_struct     20190
#define CSN1C_DEF_EGPRS_mode_struct    20268
#define CSN1C_DEF_NC_Measurement_Parameters_struct 20464
#define CSN1C_DEF_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content 20671
#define CSN1C_DEF_Multiple_TBF_Downlink_Assignment_message_content 20885
#define CSN1C_DEF_PSI2_message_content 22219
#define CSN1C_DEF_PSI3_message_content 22837
#define CSN1C_DEF_PSI5_message_content 23393
#define CSN1C_DEF_Packet_Uplink_Assignment_message_content 23780
#define CSN1C_DEF_Multiple_TBF_Uplink_Assignment_message_content 27463
#define CSN1C_DEF_Multiple_TBF_Timeslot_Reconfigure_message_content 28842
#define CSN1C_DEF_MBMS_bearer_description_struct 30546
#define CSN1C_DEF_PS_Handover_Radio_Resources_IE 30680
#define CSN1C_DEF_UFPS_struct          30915
#define CSN1C_DEF_EGPRS_mode_2_IE      31547
#define CSN1C_DEF_EGPRS_Packet_Downlink_Ack_Nack_message_content 33735
#define CSN1C_DEF_Packet_Downlink_Assignment_message_content 33977
#define CSN1C_DEF_Packet_Measurement_Order_message_content 36085
#define CSN1C_DEF_Packet_Resource_Request_message_content 37954
#define CSN1C_DEF_PSI8_message_content 38643
#define CSN1C_DEF_PSI14_message_content 38838
#define CSN1C_DEF_Packet_Timeslot_Reconfigure_message_content 39136
#define CSN1C_DEF_Additional_MS_Radio_Access_Capabilities_message_content 42166
#define CSN1C_DEF_Packet_CS_Release_message_content 42272
#define CSN1C_DEF_MBMS_Assignment_Non_distribution_message_content 43908
#define CSN1C_DEF_MBMS_Assignment_Distribution_message_content 44309
#define CSN1C_DEF_Packet_MBMS_Announcement_message_content 44443
#define CSN1C_DEF_Packet_Cell_Change_Order_message_content 44774
#define CSN1C_DEF_PS_Handover_Command_message_content 45822
#define CSN1C_DEF_Packet_Paging_Request_message_content 47727
#define CSN1C_DEF_DTM_Handover_Command_message_content 48662
/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Access_Reject_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Access_Reject_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Access_Reject_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Access_Reject_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Access_Reject_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_11bit_a_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_11bit_a_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_11bit_a_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_11bit_a_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_11bit_a_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_11bit_b_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_11bit_b_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_11bit_b_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_11bit_b_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_11bit_b_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_8bit_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_8bit_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_8bit_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_8bit_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_8bit_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Continue_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Continue_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Continue_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Continue_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Continue_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Failure_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Failure_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Failure_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Failure_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Failure_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Notification_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Notification_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Notification_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Notification_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Notification_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Order_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Order_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Order_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Order_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Order_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_channel_request_11_bit_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_channel_request_11_bit_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_channel_request_11_bit_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_channel_request_11_bit_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_channel_request_11_bit_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_channel_request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_channel_request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_channel_request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_channel_request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_channel_request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_DBPSCH_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_DBPSCH_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_DBPSCH_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_DBPSCH_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_DBPSCH_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Downlink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Downlink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Downlink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_DBPSCH_Downlink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_DBPSCH_Downlink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_DBPSCH_Downlink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_DBPSCH_Downlink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_DBPSCH_Downlink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Downlink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Downlink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Downlink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Downlink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Downlink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_Type_2_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_Type_3_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Downlink_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Downlink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Downlink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Multiple_TBF_Downlink_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Multiple_TBF_Downlink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Downlink_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Multiple_TBF_Downlink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Downlink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Downlink_Dummy_Control_Block_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Downlink_Dummy_Control_Block_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Dummy_Control_Block_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Downlink_Dummy_Control_Block_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Dummy_Control_Block_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Uplink_Dummy_Control_Block_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Uplink_Dummy_Control_Block_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Dummy_Control_Block_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Uplink_Dummy_Control_Block_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Dummy_Control_Block_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Measurement_Report_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Measurement_Report_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Measurement_Report_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Measurement_Report_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Measurement_Report_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Measurement_Order_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Measurement_Order_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Measurement_Order_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Measurement_Order_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Measurement_Order_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Mobile_TBF_Status_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Mobile_TBF_Status_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Mobile_TBF_Status_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Mobile_TBF_Status_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Mobile_TBF_Status_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Enhanced_Measurement_Report_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Enhanced_Measurement_Report_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Enhanced_Measurement_Report_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Enhanced_Measurement_Report_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Enhanced_Measurement_Report_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Neighbour_Cell_Data_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Neighbour_Cell_Data_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Neighbour_Cell_Data_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Neighbour_Cell_Data_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Neighbour_Cell_Data_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Paging_Request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Paging_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Paging_Request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Paging_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Paging_Request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_PDCH_Release_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_PDCH_Release_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PDCH_Release_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_PDCH_Release_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PDCH_Release_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Polling_Request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Polling_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Polling_Request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Polling_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Polling_Request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Power_Control_Timing_Advance_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Power_Control_Timing_Advance_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Power_Control_Timing_Advance_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Power_Control_Timing_Advance_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Power_Control_Timing_Advance_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_PRACH_Parameters_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_PRACH_Parameters_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PRACH_Parameters_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_PRACH_Parameters_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PRACH_Parameters_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Queueing_Notification_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Queueing_Notification_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Queueing_Notification_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Queueing_Notification_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Queueing_Notification_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Resource_Request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Resource_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Resource_Request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Resource_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Resource_Request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_PSI_Status_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_PSI_Status_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PSI_Status_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_PSI_Status_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PSI_Status_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Serving_Cell_Data_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Serving_Cell_Data_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Serving_Cell_Data_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Serving_Cell_Data_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Serving_Cell_Data_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_SI_Status_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_SI_Status_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_SI_Status_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_SI_Status_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_SI_Status_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Serving_Cell_SI_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Serving_Cell_SI_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Serving_Cell_SI_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Serving_Cell_SI_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Serving_Cell_SI_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI1_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI1_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI1_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI1_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI1_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI2_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI2_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI2_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI2_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI2_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_bis_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_bis_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_bis_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_bis_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_bis_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_ter_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_ter_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_ter_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_ter_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_ter_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_quater_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_quater_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_quater_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_quater_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_quater_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI4_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI4_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI4_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI4_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI4_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI5_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI5_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI5_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI5_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI5_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI6_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI6_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI6_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI6_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI6_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI8_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI8_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI8_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI8_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI8_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI13_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI13_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI13_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI13_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI13_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI14_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI14_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI14_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI14_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI14_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI15_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI15_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI15_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI15_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI15_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI16_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI16_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI16_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI16_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI16_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_TBF_Release_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_TBF_Release_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_TBF_Release_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_TBF_Release_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_TBF_Release_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Uplink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Uplink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Uplink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_DBPSCH_Uplink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_DBPSCH_Uplink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_DBPSCH_Uplink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_DBPSCH_Uplink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_DBPSCH_Uplink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Uplink_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Uplink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Uplink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Multiple_TBF_Uplink_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Multiple_TBF_Uplink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Uplink_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Multiple_TBF_Uplink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Uplink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Pause_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Pause_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Pause_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Pause_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Pause_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Timeslot_Reconfigure_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Timeslot_Reconfigure_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Timeslot_Reconfigure_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Timeslot_Reconfigure_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Timeslot_Reconfigure_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Multiple_TBF_Timeslot_Reconfigure_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Multiple_TBF_Timeslot_Reconfigure_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Timeslot_Reconfigure_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Multiple_TBF_Timeslot_Reconfigure_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Timeslot_Reconfigure_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Additional_MS_Radio_Access_Capabilities_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Additional_MS_Radio_Access_Capabilities_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Additional_MS_Radio_Access_Capabilities_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Additional_MS_Radio_Access_Capabilities_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Additional_MS_Radio_Access_Capabilities_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Handover_Access_8_bit_message".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Handover_Access_8_bit_message (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Handover_Access_8_bit_message* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Handover_Access_8_bit_message (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Handover_Access_8_bit_message* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Physical_information_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Physical_information_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Physical_information_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Physical_information_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Physical_information_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_CS_Request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_CS_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_CS_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_CS_Command_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_CS_Command_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Command_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_CS_Command_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Command_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_CS_Release_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_CS_Release_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Release_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_CS_Release_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Release_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Service_Request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Service_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Service_Request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Service_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Service_Request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Assignment_Non_distribution_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Assignment_Non_distribution_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Assignment_Non_distribution_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Assignment_Non_distribution_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Assignment_Non_distribution_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Assignment_Distribution_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Assignment_Distribution_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Assignment_Distribution_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Assignment_Distribution_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Assignment_Distribution_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Neighbouring_Cell_Information_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Neighbouring_Cell_Information_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Neighbouring_Cell_Information_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Neighbouring_Cell_Information_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Neighbouring_Cell_Information_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_MS_ID_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_MS_ID_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_MS_ID_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_MS_ID_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_MS_ID_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_MBMS_Announcement_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_MBMS_Announcement_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_MBMS_Announcement_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_MBMS_Announcement_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_MBMS_Announcement_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PS_Handover_Command_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PS_Handover_Command_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PS_Handover_Command_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PS_Handover_Command_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PS_Handover_Command_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Physical_Information_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Physical_Information_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Physical_Information_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Physical_Information_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Physical_Information_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DTM_Handover_Command_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DTM_Handover_Command_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DTM_Handover_Command_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DTM_Handover_Command_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DTM_Handover_Command_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Application_Information_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Application_Information_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Application_Information_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Application_Information_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Application_Information_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_DLMC_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Frequency_Parameters_IE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Frequency_Parameters_IE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Frequency_Parameters_IE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Frequency_Parameters_IE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Frequency_Parameters_IE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PS_Handover_Radio_Resources_IE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PS_Handover_Radio_Resources_IE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PS_Handover_Radio_Resources_IE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PS_Handover_Radio_Resources_IE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PS_Handover_Radio_Resources_IE* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

