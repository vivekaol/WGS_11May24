/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __CSN1DataTypes_RR_h
#define __CSN1DataTypes_RR_h
/* ZZZ */

#include "csn1clib.h"
#include "ed_lib.h"
#include "ed_c_RR.h"
#include "ed_user.h"
#include "endec_configs_RR.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

extern TCSN1CProgram Program_RR_Program;


#ifdef CSN1C_LABEL_NAMES
/* List of label names */
extern const char* const Program_RR_Labels [];
#endif

/* LABELS */

#define CSN1_TMGI_IE_MCC               141
#define CSN1_TMGI_IE_MCC_SIZE           12
#define CSN1_TMGI_IE_MNC               142
#define CSN1_TMGI_IE_MNC_SIZE           12
#define CSN1_ChReqDesc2_PFI            279
#define CSN1_ChReqDesc2_PFI_SIZE         7
#define CSN1_cell_info_bsic            1427
#define CSN1_cell_info_bsic_SIZE         6
#define CSN1_RTD6_Struct_RTD            87
#define CSN1_RTD6_Struct_RTD_SIZE        6
#define CSN1_A5_CM3_bits_A5_4          125
#define CSN1_A5_CM3_bits_A5_4_SIZE       1
#define CSN1_A5_CM3_bits_A5_5          124
#define CSN1_A5_CM3_bits_A5_5_SIZE       1
#define CSN1_A5_CM3_bits_A5_6          123
#define CSN1_A5_CM3_bits_A5_6_SIZE       1
#define CSN1_A5_CM3_bits_A5_7          122
#define CSN1_A5_CM3_bits_A5_7_SIZE       1
#define CSN1_IARestOctets_RCC          709
#define CSN1_IARestOctets_RCC_SIZE       3
#define CSN1_P1RestOctets_RCC          1467
#define CSN1_P1RestOctets_RCC_SIZE       3
#define CSN1_P2RestOctets_CN3          1468
#define CSN1_P2RestOctets_CN3_SIZE       2
#define CSN1_P2RestOctets_NLN          1469
#define CSN1_P2RestOctets_NLN_SIZE       2
#define CSN1_P2RestOctets_RCC          1482
#define CSN1_P2RestOctets_RCC_SIZE       3
#define CSN1_P3RestOctets_CN3          302
#define CSN1_P3RestOctets_CN3_SIZE       2
#define CSN1_P3RestOctets_CN4          303
#define CSN1_P3RestOctets_CN4_SIZE       2
#define CSN1_P3RestOctets_NLN          304
#define CSN1_P3RestOctets_NLN_SIZE       2
#define CSN1_P3RestOctets_RCC          314
#define CSN1_P3RestOctets_RCC_SIZE       3
#define CSN1_PSC_Group_IE_PSC          398
#define CSN1_PSC_Group_IE_PSC_SIZE       9
#define CSN1_Position_modulus          109
#define CSN1_Position_modulus_SIZE       4
#define CSN1_RTD12_Struct_RTD           88
#define CSN1_RTD12_Struct_RTD_SIZE      12
#define CSN1_SI6RestOctet_RAC          816
#define CSN1_SI6RestOctet_RAC_SIZE       8
#define CSN1_IARRestOctets_RCC          51
#define CSN1_IARRestOctets_RCC_SIZE      3
#define CSN1_IARestOctets_MAIO         752
#define CSN1_IARestOctets_MAIO_SIZE      6
#define CSN1_IAXRestOctets_RCC         295
#define CSN1_IAXRestOctets_RCC_SIZE      3
#define CSN1_IPARestOctets_RCC         1403
#define CSN1_IPARestOctets_RCC_SIZE      3
#define CSN1_BA_List_Pref_Range        262
#define CSN1_BA_List_Pref_Range_SIZE    20
#define CSN1_LSA_Parameters_MCC        805
#define CSN1_LSA_Parameters_MCC_SIZE    12
#define CSN1_LSA_Parameters_MNC        806
#define CSN1_LSA_Parameters_MNC_SIZE    12
#define CSN1_PCID_Group_IE_PCID        143
#define CSN1_PCID_Group_IE_PCID_SIZE     9
#define CSN1_PLMN_ID_struct_MCC        148
#define CSN1_PLMN_ID_struct_MCC_SIZE    12
#define CSN1_PLMN_ID_struct_MNC        149
#define CSN1_PLMN_ID_struct_MNC_SIZE    12
#define CSN1_Position_bcch_type        111
#define CSN1_Position_bcch_type_SIZE     1
#define CSN1_SI13RestOctets_RAC        1103
#define CSN1_SI13RestOctets_RAC_SIZE     8
#define CSN1_SI13RestOctets_RCC        1121
#define CSN1_SI13RestOctets_RCC_SIZE     3
#define CSN1_LSA_identity_LSA_ID       405
#define CSN1_LSA_identity_LSA_ID_SIZE   24
#define CSN1_BA_List_Pref_BA_FREQ      265
#define CSN1_BA_List_Pref_BA_FREQ_SIZE  10
#define CSN1_P1RestOctets_NLN_PCH      1442
#define CSN1_P1RestOctets_NLN_PCH_SIZE   2
#define CSN1_RRPktDownlinkAssi_P0      1026
#define CSN1_RRPktDownlinkAssi_P0_SIZE   4
#define CSN1_SI13RestOctets_SGSNR      1116
#define CSN1_SI13RestOctets_SGSNR_SIZE   1
#define CSN1_Scheduling_info_info      1097
#define CSN1_Scheduling_info_info_SIZE   0
#define CSN1_Info_type_Info_type_4     106
#define CSN1_Info_type_Info_type_4_SIZE   4
#define CSN1_Info_type_Info_type_5     107
#define CSN1_Info_type_Info_type_5_SIZE   5
#define CSN1_Info_type_Info_type_6     108
#define CSN1_Info_type_Info_type_6_SIZE   6
#define CSN1_NTNRestOctets_NLN_PCH     1012
#define CSN1_NTNRestOctets_NLN_PCH_SIZE   2
#define CSN1_SI2nRestOctets_BA_IND     768
#define CSN1_SI2nRestOctets_BA_IND_SIZE   1
#define CSN1_P1RestOctets_Priority1    1444
#define CSN1_P1RestOctets_Priority1_SIZE   3
#define CSN1_P1RestOctets_Priority2    1445
#define CSN1_P1RestOctets_Priority2_SIZE   3
#define CSN1_P1RestOctets_VSTK_RAND    1450
#define CSN1_P1RestOctets_VSTK_RAND_SIZE  36
#define CSN1_P2RestOctets_Priority1    1471
#define CSN1_P2RestOctets_Priority1_SIZE   3
#define CSN1_P2RestOctets_Priority2    1472
#define CSN1_P2RestOctets_Priority2_SIZE   3
#define CSN1_P2RestOctets_Priority3    1473
#define CSN1_P2RestOctets_Priority3_SIZE   3
#define CSN1_P3RestOctets_Priority1    306
#define CSN1_P3RestOctets_Priority1_SIZE   3
#define CSN1_P3RestOctets_Priority2    307
#define CSN1_P3RestOctets_Priority2_SIZE   3
#define CSN1_P3RestOctets_Priority3    308
#define CSN1_P3RestOctets_Priority3_SIZE   3
#define CSN1_P3RestOctets_Priority4    309
#define CSN1_P3RestOctets_Priority4_SIZE   3
#define CSN1_RRPktDownlinkAssi_FANR    1046
#define CSN1_RRPktDownlinkAssi_FANR_SIZE   1
#define CSN1_SI13RestOctets_NoPBCCH    1102
#define CSN1_SI13RestOctets_NoPBCCH_SIZE   0
#define CSN1_SI13RestOctets_PEO_DSC    1120
#define CSN1_SI13RestOctets_PEO_DSC_SIZE   2
#define CSN1_SI2bisRestOctets_dummy    353
#define CSN1_SI2bisRestOctets_dummy_SIZE   0
#define CSN1_SI4_Rest_Octets_S_CBQ3    808
#define CSN1_SI4_Rest_Octets_S_CBQ3_SIZE   2
#define CSN1_SI6RestOctet_MAX_LAPDm    817
#define CSN1_SI6RestOctet_MAX_LAPDm_SIZE   3
#define CSN1_LSA_Parameters_PRIO_THR   803
#define CSN1_LSA_Parameters_PRIO_THR_SIZE   3
#define CSN1_P1RestOctets_AMR_Config   1455
#define CSN1_P1RestOctets_AMR_Config_SIZE   4
#define CSN1_P1RestOctets_NLN_status   1443
#define CSN1_P1RestOctets_NLN_status_SIZE   1
#define CSN1_P2RestOctets_NLN_status   1470
#define CSN1_P2RestOctets_NLN_status_SIZE   1
#define CSN1_P3RestOctets_NLN_status   305
#define CSN1_P3RestOctets_NLN_status_SIZE   1
#define CSN1_SI10_rest_octets_BA_ind   1425
#define CSN1_SI10_rest_octets_BA_ind_SIZE   1
#define CSN1_SI13RestOctets_C1_DELTA   1122
#define CSN1_SI13RestOctets_C1_DELTA_SIZE   3
#define CSN1_SI16_LSA_Parameters_MCC   1125
#define CSN1_SI16_LSA_Parameters_MCC_SIZE  12
#define CSN1_SI16_LSA_Parameters_MNC   1126
#define CSN1_SI16_LSA_Parameters_MNC_SIZE  12
#define CSN1_SI18RestOctet_SI18_LAST   422
#define CSN1_SI18RestOctet_SI18_LAST_SIZE   1
#define CSN1_SI6RestOctet_AMR_Config   821
#define CSN1_SI6RestOctet_AMR_Config_SIZE   4
#define CSN1_TMGI_IE_MBMS_SERVICE_ID   140
#define CSN1_TMGI_IE_MBMS_SERVICE_ID_SIZE  24
#define CSN1_UTRANFreqList_FDD_ARFCN   266
#define CSN1_UTRANFreqList_FDD_ARFCN_SIZE  14
#define CSN1_UTRANFreqList_TDD_ARFCN   267
#define CSN1_UTRANFreqList_TDD_ARFCN_SIZE  14
#define CSN1__3GTargetCell_Diversity   454
#define CSN1__3GTargetCell_Diversity_SIZE   1
#define CSN1__3GTargetCell_FDD_ARFCN   453
#define CSN1__3GTargetCell_FDD_ARFCN_SIZE  14
#define CSN1__3GTargetCell_Sync_Case   460
#define CSN1__3GTargetCell_Sync_Case_SIZE   1
#define CSN1__3GTargetCell_TDD_ARFCN   457
#define CSN1__3GTargetCell_TDD_ARFCN_SIZE  14
#define CSN1_cell_barred_cell_barred     0
#define CSN1_cell_barred_cell_barred_SIZE   0
#define CSN1_ChReqDesc2_Uplink_EGPRS2  283
#define CSN1_ChReqDesc2_Uplink_EGPRS2_SIZE   2
#define CSN1_GPRS_Cell_Options_IE_NMO  870
#define CSN1_GPRS_Cell_Options_IE_NMO_SIZE   2
#define CSN1_GPRS_Cell_Options_IE_ext  880
#define CSN1_GPRS_Cell_Options_IE_ext_SIZE   0
#define CSN1_GPRS_Indicator_RA_COLOUR  801
#define CSN1_GPRS_Indicator_RA_COLOUR_SIZE   3
#define CSN1_IARestOctets_HH_detected  710
#define CSN1_IARestOctets_HH_detected_SIZE   0
#define CSN1_IARestOctets_LH_detected  665
#define CSN1_IARestOctets_LH_detected_SIZE   0
#define CSN1_IARestOctets_LL_detected  754
#define CSN1_IARestOctets_LL_detected_SIZE   0
#define CSN1_LSA_identity_ShortLSA_ID  406
#define CSN1_LSA_identity_ShortLSA_ID_SIZE  10
#define CSN1_P1RestOctets_IPA_Support  1465
#define CSN1_P1RestOctets_IPA_Support_SIZE   1
#define CSN1_P1RestOctets_Reduced_GCR  1449
#define CSN1_P1RestOctets_Reduced_GCR_SIZE  28
#define CSN1_P2RestOctets_IPA_Support  1480
#define CSN1_P2RestOctets_IPA_Support_SIZE   1
#define CSN1_P3RestOctets_IPA_Support  312
#define CSN1_P3RestOctets_IPA_Support_SIZE   1
#define CSN1_PSC_Group_IE_PSC_Pattern  400
#define CSN1_PSC_Group_IE_PSC_Pattern_SIZE   0
#define CSN1_RANGE_LIMITS_RANGE_LOWER  263
#define CSN1_RANGE_LIMITS_RANGE_LOWER_SIZE  10
#define CSN1_RANGE_LIMITS_RANGE_UPPER  264
#define CSN1_RANGE_LIMITS_RANGE_UPPER_SIZE  10
#define CSN1_RLC_Entity_Struct_DN_PFI  344
#define CSN1_RLC_Entity_Struct_DN_PFI_SIZE   7
#define CSN1_RLC_Entity_Struct_UP_PFI  340
#define CSN1_RLC_Entity_Struct_UP_PFI_SIZE   7
#define CSN1_SI10bis_Rest_Octets_BSIC  851
#define CSN1_SI10bis_Rest_Octets_BSIC_SIZE   6
#define CSN1_SI18RestOctet_SI18_INDEX  421
#define CSN1_SI18RestOctet_SI18_INDEX_SIZE   3
#define CSN1_SI19RestOctets_SI19_LAST  1129
#define CSN1_SI19RestOctets_SI19_LAST_SIZE   1
#define CSN1_SI6RestOctet_DTM_support  815
#define CSN1_SI6RestOctet_DTM_support_SIZE   0
#define CSN1_Selection_Parameters_CBQ  787
#define CSN1_Selection_Parameters_CBQ_SIZE   1
#define CSN1_LSA_Parameters_LSA_OFFSET 804
#define CSN1_LSA_Parameters_LSA_OFFSET_SIZE   3
#define CSN1_MPRACH_description_IE_USF 1417
#define CSN1_MPRACH_description_IE_USF_SIZE   3
#define CSN1_MultirateSpeechCfgIE_ICMI 298
#define CSN1_MultirateSpeechCfgIE_ICMI_SIZE   1
#define CSN1_MultirateSpeechCfgIE_NSCB 297
#define CSN1_MultirateSpeechCfgIE_NSCB_SIZE   1
#define CSN1_RRPktDownlinkAssi_PR_MODE 1028
#define CSN1_RRPktDownlinkAssi_PR_MODE_SIZE   1
#define CSN1_SI14RestOctets_SI14_COUNT 428
#define CSN1_SI14RestOctets_SI14_COUNT_SIZE   2
#define CSN1_SI14RestOctets_SI14_INDEX 427
#define CSN1_SI14RestOctets_SI14_INDEX_SIZE   2
#define CSN1_SI15RestOctets_SI15_COUNT 432
#define CSN1_SI15RestOctets_SI15_COUNT_SIZE   2
#define CSN1_SI15RestOctets_SI15_INDEX 431
#define CSN1_SI15RestOctets_SI15_INDEX_SIZE   2
#define CSN1_SI19RestOctets_SI19_INDEX 1128
#define CSN1_SI19RestOctets_SI19_INDEX_SIZE   3
#define CSN1_SI2nRestOctets_SI2n_COUNT 771
#define CSN1_SI2nRestOctets_SI2n_COUNT_SIZE   4
#define CSN1_SI2nRestOctets_SI2n_INDEX 770
#define CSN1_SI2nRestOctets_SI2n_INDEX_SIZE   4
#define CSN1_SI6RestOctet_MNCI_SUPPORT 820
#define CSN1_SI6RestOctet_MNCI_SUPPORT_SIZE   1
#define CSN1_ChReqDesc2_Downlink_EGPRS2 284
#define CSN1_ChReqDesc2_Downlink_EGPRS2_SIZE   2
#define CSN1_ChReqDesc2_FANR_Capability 287
#define CSN1_ChReqDesc2_FANR_Capability_SIZE   1
#define CSN1_EGPRS_Level_IE_EGPRS_Level 732
#define CSN1_EGPRS_Level_IE_EGPRS_Level_SIZE   2
#define CSN1_Fixed_Allocation_struct_P0 327
#define CSN1_Fixed_Allocation_struct_P0_SIZE   4
#define CSN1_GPRS_Cell_Options_IE_T3168 871
#define CSN1_GPRS_Cell_Options_IE_T3168_SIZE   3
#define CSN1_GPRS_Cell_Options_IE_T3192 872
#define CSN1_GPRS_Cell_Options_IE_T3192_SIZE   3
#define CSN1_MBMS_Sessions_List_IE_TMGI 558
#define CSN1_MBMS_Sessions_List_IE_TMGI_SIZE   0
#define CSN1_MeasurementResults_BA_USED 756
#define CSN1_MeasurementResults_BA_USED_SIZE   1
#define CSN1_MultirateSpeechCfgIE_codec 301
#define CSN1_MultirateSpeechCfgIE_codec_SIZE  10
#define CSN1_PCH_and_NCH_info_NLN_SACCH 811
#define CSN1_PCH_and_NCH_info_NLN_SACCH_SIZE   2
#define CSN1_PCID_Group_IE_PCID_Pattern 146
#define CSN1_PCID_Group_IE_PCID_Pattern_SIZE   0
#define CSN1_Position_relative_position 110
#define CSN1_Position_relative_position_SIZE   0
#define CSN1_RRPktDownlinkAssi_MAC_MODE 1022
#define CSN1_RRPktDownlinkAssi_MAC_MODE_SIZE   2
#define CSN1_RRPktDownlinkAssi_RLC_MODE 1023
#define CSN1_RRPktDownlinkAssi_RLC_MODE_SIZE   1
#define CSN1_SI1RestOctets_NCH_Position 352
#define CSN1_SI1RestOctets_NCH_Position_SIZE   5
#define CSN1_SI21RestOctets_SI_21_COUNT 437
#define CSN1_SI21RestOctets_SI_21_COUNT_SIZE   3
#define CSN1_SI21RestOctets_SI_21_INDEX 436
#define CSN1_SI21RestOctets_SI_21_INDEX_SIZE   3
#define CSN1_SI22RestOctets_SI_22_COUNT 442
#define CSN1_SI22RestOctets_SI_22_COUNT_SIZE   3
#define CSN1_SI22RestOctets_SI_22_INDEX 441
#define CSN1_SI22RestOctets_SI_22_INDEX_SIZE   3
#define CSN1_SI23RestOctets_SI_23_COUNT 1365
#define CSN1_SI23RestOctets_SI_23_COUNT_SIZE   3
#define CSN1_SI23RestOctets_SI_23_INDEX 1364
#define CSN1_SI23RestOctets_SI_23_INDEX_SIZE   3
#define CSN1_SI2quaterRestOctets_BA_IND 1220
#define CSN1_SI2quaterRestOctets_BA_IND_SIZE   1
#define CSN1_differential_cell_info_BCC 1435
#define CSN1_differential_cell_info_BCC_SIZE   3
#define CSN1_DTMInfoRestOctets_MAX_LAPDm 288
#define CSN1_DTMInfoRestOctets_MAX_LAPDm_SIZE   3
#define CSN1_Emergency_Ind_Emergency_Ind  57
#define CSN1_Emergency_Ind_Emergency_Ind_SIZE   0
#define CSN1_Frequency_Parameters_IE_TSC 1138
#define CSN1_Frequency_Parameters_IE_TSC_SIZE   3
#define CSN1_GSM_Description_struct_BSIC  31
#define CSN1_GSM_Description_struct_BSIC_SIZE   6
#define CSN1_IARRestOctets_Extended_RA_1  47
#define CSN1_IARRestOctets_Extended_RA_1_SIZE   5
#define CSN1_IARRestOctets_Extended_RA_2  48
#define CSN1_IARRestOctets_Extended_RA_2_SIZE   5
#define CSN1_IARRestOctets_Extended_RA_3  49
#define CSN1_IARRestOctets_Extended_RA_3_SIZE   5
#define CSN1_IARRestOctets_Extended_RA_4  50
#define CSN1_IARRestOctets_Extended_RA_4_SIZE   5
#define CSN1_MeasurementResults_DTX_USED 757
#define CSN1_MeasurementResults_DTX_USED_SIZE   1
#define CSN1_NTNRestOctets_FR_AMR_Config 1018
#define CSN1_NTNRestOctets_FR_AMR_Config_SIZE   4
#define CSN1_NTNRestOctets_HR_AMR_Config 1019
#define CSN1_NTNRestOctets_HR_AMR_Config_SIZE   4
#define CSN1_PBCCH_Description_struct_Pb 1111
#define CSN1_PBCCH_Description_struct_Pb_SIZE   4
#define CSN1_PBCCH_Description_struct_TN 1113
#define CSN1_PBCCH_Description_struct_TN_SIZE   3
#define CSN1_PCH_and_NCH_info_NLN_status 813
#define CSN1_PCH_and_NCH_info_NLN_status_SIZE   1
#define CSN1_PacketChannelDescription_TN 316
#define CSN1_PacketChannelDescription_TN_SIZE   3
#define CSN1_Packet_Uplink_Assignment_P0 737
#define CSN1_Packet_Uplink_Assignment_P0_SIZE   4
#define CSN1_SI13RestOctets_SI2n_SUPPORT 1119
#define CSN1_SI13RestOctets_SI2n_SUPPORT_SIZE   2
#define CSN1_SI23RestOctets_SI_23_BA_IND 1362
#define CSN1_SI23RestOctets_SI_23_BA_IND_SIZE   1
#define CSN1__3GTargetCell_Bandwidth_FDD 455
#define CSN1__3GTargetCell_Bandwidth_FDD_SIZE   3
#define CSN1__3GTargetCell_Bandwidth_TDD 458
#define CSN1__3GTargetCell_Bandwidth_TDD_SIZE   3
#define CSN1_differential_cell_info_bsic 1436
#define CSN1_differential_cell_info_bsic_SIZE   6
#define CSN1_BSIC_Description_struct_BSIC 912
#define CSN1_BSIC_Description_struct_BSIC_SIZE   6
#define CSN1_Direct_encoding_2_struct_HSN 1149
#define CSN1_Direct_encoding_2_struct_HSN_SIZE   6
#define CSN1_Dynamic_Allocation_struct_P0  59
#define CSN1_Dynamic_Allocation_struct_P0_SIZE   4
#define CSN1_EC_Cell_Options_struct_ALPHA 225
#define CSN1_EC_Cell_Options_struct_ALPHA_SIZE   4
#define CSN1_EC_Cell_Options_struct_T3168 226
#define CSN1_EC_Cell_Options_struct_T3168_SIZE   3
#define CSN1_EC_Cell_Options_struct_T3192 227
#define CSN1_EC_Cell_Options_struct_T3192_SIZE   3
#define CSN1_EC_Cell_Options_struct_T3226 228
#define CSN1_EC_Cell_Options_struct_T3226_SIZE   3
#define CSN1_EC_Cell_Options_struct_T3248 229
#define CSN1_EC_Cell_Options_struct_T3248_SIZE   2
#define CSN1_GPRS_Cell_Options_IE_PAN_DEC 877
#define CSN1_GPRS_Cell_Options_IE_PAN_DEC_SIZE   3
#define CSN1_GPRS_Cell_Options_IE_PAN_INC 878
#define CSN1_GPRS_Cell_Options_IE_PAN_INC_SIZE   3
#define CSN1_GPRS_Cell_Options_IE_PAN_MAX 879
#define CSN1_GPRS_Cell_Options_IE_PAN_MAX_SIZE   3
#define CSN1_GPRS_Indicator_SI13_POSITION 802
#define CSN1_GPRS_Indicator_SI13_POSITION_SIZE   1
#define CSN1_GPRS_Mobile_Allocation_IE_MA 555
#define CSN1_GPRS_Mobile_Allocation_IE_MA_SIZE   0
#define CSN1_GSM_Description_struct_ARFCN  30
#define CSN1_GSM_Description_struct_ARFCN_SIZE  10
#define CSN1_Measurement_information_PWRC 903
#define CSN1_Measurement_information_PWRC_SIZE   1
#define CSN1_PBCCH_Description_struct_TSC 1112
#define CSN1_PBCCH_Description_struct_TSC_SIZE   3
#define CSN1_PacketChannelDescription_HSN 323
#define CSN1_PacketChannelDescription_HSN_SIZE   6
#define CSN1_PacketChannelDescription_TSC 317
#define CSN1_PacketChannelDescription_TSC_SIZE   3
#define CSN1_Packet_Uplink_Assignment_PFI 749
#define CSN1_Packet_Uplink_Assignment_PFI_SIZE   7
#define CSN1_Packet_Uplink_Assignment_USF 740
#define CSN1_Packet_Uplink_Assignment_USF_SIZE   3
#define CSN1_RRPacketUplinkAssignment_TSH 1196
#define CSN1_RRPacketUplinkAssignment_TSH_SIZE   2
#define CSN1_SI13RestOctets_SI_STATUS_IND 1117
#define CSN1_SI13RestOctets_SI_STATUS_IND_SIZE   1
#define CSN1_SI13RestOctets_SPGC_CCCH_SUP 1104
#define CSN1_SI13RestOctets_SPGC_CCCH_SUP_SIZE   1
#define CSN1_SI16_LSA_Parameters_PRIO_THR 1123
#define CSN1_SI16_LSA_Parameters_PRIO_THR_SIZE   3
#define CSN1_Single_Band_Support_GSM_Band 509
#define CSN1_Single_Band_Support_GSM_Band_SIZE   4
#define CSN1__3GTargetCell_Cell_Parameter 459
#define CSN1__3GTargetCell_Cell_Parameter_SIZE   7
#define CSN1_Additional_PFCs_struct_DN_PFI  86
#define CSN1_Additional_PFCs_struct_DN_PFI_SIZE   7
#define CSN1_Additional_PFCs_struct_UP_PFI  83
#define CSN1_Additional_PFCs_struct_UP_PFI_SIZE   7
#define CSN1_Band_indicator_BAND_INDICATOR   2
#define CSN1_Band_indicator_BAND_INDICATOR_SIZE   1
#define CSN1_ChReqDesc2_EMSR_MS_Capability 286
#define CSN1_ChReqDesc2_EMSR_MS_Capability_SIZE   1
#define CSN1_ChReqDesc2_EMST_MS_Capability 285
#define CSN1_ChReqDesc2_EMST_MS_Capability_SIZE   1
#define CSN1_Direct_encoding_1_struct_MAIO 1140
#define CSN1_Direct_encoding_1_struct_MAIO_SIZE   6
#define CSN1_Direct_encoding_2_struct_MAIO 1148
#define CSN1_Direct_encoding_2_struct_MAIO_SIZE   6
#define CSN1_Frequency_Parameters_IE_ARFCN 1152
#define CSN1_Frequency_Parameters_IE_ARFCN_SIZE  10
#define CSN1_GPRS_Mobile_Allocation_IE_HSN 551
#define CSN1_GPRS_Mobile_Allocation_IE_HSN_SIZE   6
#define CSN1_Indirect_encoding_struct_MAIO 1143
#define CSN1_Indirect_encoding_struct_MAIO_SIZE   6
#define CSN1_Iu_Indicator_SI13alt_POSITION 799
#define CSN1_Iu_Indicator_SI13alt_POSITION_SIZE   1
#define CSN1_MeasurementResults_MEAS_VALID 760
#define CSN1_MeasurementResults_MEAS_VALID_SIZE   1
#define CSN1_MeasurementResults_NO_NCELL_M 765
#define CSN1_MeasurementResults_NO_NCELL_M_SIZE   3
#define CSN1_Mobile_Identity_struct_P_TMSI  28
#define CSN1_Mobile_Identity_struct_P_TMSI_SIZE  32
#define CSN1_PBCCH_Description_2_struct_Pb 1375
#define CSN1_PBCCH_Description_2_struct_Pb_SIZE   4
#define CSN1_PBCCH_Description_2_struct_TN 1376
#define CSN1_PBCCH_Description_2_struct_TN_SIZE   3
#define CSN1_PBCCH_Description_struct_MAIO 1115
#define CSN1_PBCCH_Description_struct_MAIO_SIZE   6
#define CSN1_PacketChannelDescription_MAIO 318
#define CSN1_PacketChannelDescription_MAIO_SIZE   6
#define CSN1_Packet_Downlink_Assignment_P0 720
#define CSN1_Packet_Downlink_Assignment_P0_SIZE   4
#define CSN1_RLC_Entity_Struct_DN_RLC_MODE 342
#define CSN1_RLC_Entity_Struct_DN_RLC_MODE_SIZE   1
#define CSN1_RLC_Entity_Struct_UP_RLC_MODE 337
#define CSN1_RLC_Entity_Struct_UP_RLC_MODE_SIZE   1
#define CSN1_RRClassmark3Value_VAMOS_Level 539
#define CSN1_RRClassmark3Value_VAMOS_Level_SIZE   2
#define CSN1_SI13_GPRS_Indicator_RA_COLOUR 794
#define CSN1_SI13_GPRS_Indicator_RA_COLOUR_SIZE   3
#define CSN1_SI14RestOctets_DM_CHANGE_MARK 429
#define CSN1_SI14RestOctets_DM_CHANGE_MARK_SIZE   4
#define CSN1_SI15RestOctets_DM_CHANGE_MARK 433
#define CSN1_SI15RestOctets_DM_CHANGE_MARK_SIZE   4
#define CSN1_SI18RestOctet_Non_GSM_Message 423
#define CSN1_SI18RestOctet_Non_GSM_Message_SIZE   0
#define CSN1_SI2terRestOctets_SI2ter_COUNT 357
#define CSN1_SI2terRestOctets_SI2ter_COUNT_SIZE   3
#define CSN1_SI2terRestOctets_SI2ter_INDEX 356
#define CSN1_SI2terRestOctets_SI2ter_INDEX_SIZE   3
#define CSN1_SI6RestOctet_VBS_VGCS_options 814
#define CSN1_SI6RestOctet_VBS_VGCS_options_SIZE   2
#define CSN1_SI_CHANGE_ALT_SI_CHANGE_ALT_H   3
#define CSN1_SI_CHANGE_ALT_SI_CHANGE_ALT_H_SIZE   0
#define CSN1_Scheduling_if_and_where_WHERE 793
#define CSN1_Scheduling_if_and_where_WHERE_SIZE   3
#define CSN1__3GTargetCell_SCRAMBLING_CODE 456
#define CSN1__3GTargetCell_SCRAMBLING_CODE_SIZE   9
#define CSN1_next_frequency_next_frequency 1434
#define CSN1_next_frequency_next_frequency_SIZE   1
#define CSN1_DTMInfoRestOctets_MNCI_SUPPORT 292
#define CSN1_DTMInfoRestOctets_MNCI_SUPPORT_SIZE   1
#define CSN1_DYNAMIC_ARFCN_MAPPING_GSM_Band  42
#define CSN1_DYNAMIC_ARFCN_MAPPING_GSM_Band_SIZE   4
#define CSN1_GPRS_Cell_Options_IE_BS_CV_MAX 876
#define CSN1_GPRS_Cell_Options_IE_BS_CV_MAX_SIZE   4
#define CSN1_IARestOctets_Mobile_Allocation 753
#define CSN1_IARestOctets_Mobile_Allocation_SIZE   0
#define CSN1_MPRACH_Control_Parameters_IE_S 1421
#define CSN1_MPRACH_Control_Parameters_IE_S_SIZE   4
#define CSN1_MeasurementResults__3G_BA_USED 759
#define CSN1_MeasurementResults__3G_BA_USED_SIZE   1
#define CSN1_Measurement_information_BA_IND 898
#define CSN1_Measurement_information_BA_IND_SIZE   1
#define CSN1_NCELL_Report_struct_BSIC_NCELL  54
#define CSN1_NCELL_Report_struct_BSIC_NCELL_SIZE   6
#define CSN1_P1RestOctets_CELL_GLOBAL_COUNT 1448
#define CSN1_P1RestOctets_CELL_GLOBAL_COUNT_SIZE   2
#define CSN1_PBCCH_Description_struct_ARFCN 1114
#define CSN1_PBCCH_Description_struct_ARFCN_SIZE  10
#define CSN1_PCH_and_NCH_info_Call_priority 812
#define CSN1_PCH_and_NCH_info_Call_priority_SIZE   3
#define CSN1_PSC_Group_IE_PSC_pattern_sense 401
#define CSN1_PSC_Group_IE_PSC_pattern_sense_SIZE   1
#define CSN1_PacketChannelDescription_ARFCN 322
#define CSN1_PacketChannelDescription_ARFCN_SIZE  10
#define CSN1_Packet_Downlink_Assignment_PFI 726
#define CSN1_Packet_Downlink_Assignment_PFI_SIZE   7
#define CSN1_Packet_Uplink_Assignment_ALPHA 744
#define CSN1_Packet_Uplink_Assignment_ALPHA_SIZE   4
#define CSN1_Packet_Uplink_Assignment_GAMMA 745
#define CSN1_Packet_Uplink_Assignment_GAMMA_SIZE   5
#define CSN1_RRPktDownlinkAssi_RLC_Entity_2 1054
#define CSN1_RRPktDownlinkAssi_RLC_Entity_2_SIZE   0
#define CSN1_RRPktDownlinkAssi_RLC_Entity_3 1055
#define CSN1_RRPktDownlinkAssi_RLC_Entity_3_SIZE   0
#define CSN1_SI10bis_Rest_Octets_BCCH_ARFCN 850
#define CSN1_SI10bis_Rest_Octets_BCCH_ARFCN_SIZE  10
#define CSN1_SI13RestOctets_SI_CHANGE_FIELD 1099
#define CSN1_SI13RestOctets_SI_CHANGE_FIELD_SIZE   4
#define CSN1_SI16_LSA_Parameters_LSA_OFFSET 1124
#define CSN1_SI16_LSA_Parameters_LSA_OFFSET_SIZE   3
#define CSN1_SI18RestOctet_SI18_CHANGE_MARK 420
#define CSN1_SI18RestOctet_SI18_CHANGE_MARK_SIZE   2
#define CSN1_SI21RestOctets_EAB_Subcategory 439
#define CSN1_SI21RestOctets_EAB_Subcategory_SIZE   2
#define CSN1_SI2quaterRestOctets_p3G_BA_IND 1221
#define CSN1_SI2quaterRestOctets_p3G_BA_IND_SIZE   1
#define CSN1_SI6RestOctet_Random_bit_stream 822
#define CSN1_SI6RestOctet_Random_bit_stream_SIZE   0
#define CSN1_UPLINK_FREE_BODY_Emergency_Ind 164
#define CSN1_UPLINK_FREE_BODY_Emergency_Ind_SIZE   1
#define CSN1_further_cell_info_penalty_time 1432
#define CSN1_further_cell_info_penalty_time_SIZE   5
#define CSN1_Break_Indicator_Break_Indicator 1096
#define CSN1_Break_Indicator_Break_Indicator_SIZE   0
#define CSN1_CDMA2000_Description_struct_QOF 948
#define CSN1_CDMA2000_Description_struct_QOF_SIZE   2
#define CSN1_DTMInfoRestOctets_Cell_identity 290
#define CSN1_DTMInfoRestOctets_Cell_identity_SIZE  16
#define CSN1_Dynamic_Allocation_struct_ALPHA  64
#define CSN1_Dynamic_Allocation_struct_ALPHA_SIZE   4
#define CSN1_EC_Mobile_Allocation_struct_HSN 623
#define CSN1_EC_Mobile_Allocation_struct_HSN_SIZE   6
#define CSN1_Fixed_Allocation_struct_PR_MODE 329
#define CSN1_Fixed_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_GPRSBCastInfo_GPRS_Cell_Options 1010
#define CSN1_GPRSBCastInfo_GPRS_Cell_Options_SIZE   0
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN 553
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN_SIZE   0
#define CSN1_IARestOctets_Implicit_Reject_CS 755
#define CSN1_IARestOctets_Implicit_Reject_CS_SIZE   1
#define CSN1_IARestOctets_Implicit_Reject_PS 707
#define CSN1_IARestOctets_Implicit_Reject_PS_SIZE   1
#define CSN1_IPA_Uplink_Assignment_struct_TN 1386
#define CSN1_IPA_Uplink_Assignment_struct_TN_SIZE   3
#define CSN1_List_of_Reduced_GCR_Reduced_GCR 1014
#define CSN1_List_of_Reduced_GCR_Reduced_GCR_SIZE  28
#define CSN1_MeasurementResults_NCELL_Report 766
#define CSN1_MeasurementResults_NCELL_Report_SIZE  17
#define CSN1_MeasurementResults_SI23_BA_USED 762
#define CSN1_MeasurementResults_SI23_BA_USED_SIZE   1
#define CSN1_MultirateSpeechCfgIE_MR_version 296
#define CSN1_MultirateSpeechCfgIE_MR_version_SIZE   3
#define CSN1_MultirateSpeechCfgIE_Start_mode 299
#define CSN1_MultirateSpeechCfgIE_Start_mode_SIZE   2
#define CSN1_NCELL_Report_struct_RXLEV_NCELL  52
#define CSN1_NCELL_Report_struct_RXLEV_NCELL_SIZE   6
#define CSN1_NTNRestOctets_CELL_GLOBAL_COUNT 1013
#define CSN1_NTNRestOctets_CELL_GLOBAL_COUNT_SIZE   2
#define CSN1_P1RestOctets_Implicit_Reject_CS 1463
#define CSN1_P1RestOctets_Implicit_Reject_CS_SIZE   1
#define CSN1_P1RestOctets_Implicit_Reject_PS 1464
#define CSN1_P1RestOctets_Implicit_Reject_PS_SIZE   1
#define CSN1_P2RestOctets_Implicit_Reject_CS 1478
#define CSN1_P2RestOctets_Implicit_Reject_CS_SIZE   1
#define CSN1_P2RestOctets_Implicit_Reject_PS 1479
#define CSN1_P2RestOctets_Implicit_Reject_PS_SIZE   1
#define CSN1_P3RestOctets_Implicit_Reject_CS 310
#define CSN1_P3RestOctets_Implicit_Reject_CS_SIZE   1
#define CSN1_P3RestOctets_Implicit_Reject_PS 311
#define CSN1_P3RestOctets_Implicit_Reject_PS_SIZE   1
#define CSN1_PCID_Group_IE_PCID_BITMAP_GROUP 144
#define CSN1_PCID_Group_IE_PCID_BITMAP_GROUP_SIZE   6
#define CSN1_PSC_Group_IE_PSC_Pattern_length 399
#define CSN1_PSC_Group_IE_PSC_Pattern_length_SIZE   3
#define CSN1_Packet_Downlink_Assignment_TLLI 711
#define CSN1_Packet_Downlink_Assignment_TLLI_SIZE  32
#define CSN1_SI13RestOctets_BCCH_CHANGE_MARK 1098
#define CSN1_SI13RestOctets_BCCH_CHANGE_MARK_SIZE   3
#define CSN1_SI13RestOctets_SI13_CHANGE_MARK 1100
#define CSN1_SI13RestOctets_SI13_CHANGE_MARK_SIZE   2
#define CSN1_SI19RestOctets_SI19_CHANGE_MARK 1127
#define CSN1_SI19RestOctets_SI19_CHANGE_MARK_SIZE   2
#define CSN1_SI2nRestOctets_SI2n_CHANGE_MARK 769
#define CSN1_SI2nRestOctets_SI2n_CHANGE_MARK_SIZE   2
#define CSN1_SI4_Rest_Octets_S_Cell_Identity 807
#define CSN1_SI4_Rest_Octets_S_Cell_Identity_SIZE  16
#define CSN1_Serving_cell_data_struct_CV_BEP 595
#define CSN1_Serving_cell_data_struct_CV_BEP_SIZE   3
#define CSN1_VGCSCipheringParameters_LAC_IND 113
#define CSN1_VGCSCipheringParameters_LAC_IND_SIZE   1
#define CSN1_neighbour_information_InfoField 1433
#define CSN1_neighbour_information_InfoField_SIZE   0
#define CSN1_CDMA2000_Description_struct_QOF1 951
#define CSN1_CDMA2000_Description_struct_QOF1_SIZE   2
#define CSN1_CDMA2000_Description_struct_QOF2 954
#define CSN1_CDMA2000_Description_struct_QOF2_SIZE   2
#define CSN1_EC_Downlink_Allocation_struct_P0 659
#define CSN1_EC_Downlink_Allocation_struct_P0_SIZE   4
#define CSN1_EC_Mobile_Allocation_struct_MAIO 622
#define CSN1_EC_Mobile_Allocation_struct_MAIO_SIZE   6
#define CSN1_EGPRS_Window_Size_IE_Window_Size 339
#define CSN1_EGPRS_Window_Size_IE_Window_Size_SIZE   5
#define CSN1_Extension_Information_BEP_PERIOD 883
#define CSN1_Extension_Information_BEP_PERIOD_SIZE   4
#define CSN1_Extension_Information_CCN_ACTIVE 887
#define CSN1_Extension_Information_CCN_ACTIVE_SIZE   1
#define CSN1_IPA_Uplink_Assignment_struct_USF 1383
#define CSN1_IPA_Uplink_Assignment_struct_USF_SIZE   3
#define CSN1_Measurement_information_MI_COUNT 902
#define CSN1_Measurement_information_MI_COUNT_SIZE   4
#define CSN1_Measurement_information_MI_INDEX 901
#define CSN1_Measurement_information_MI_INDEX_SIZE   4
#define CSN1_Non_GSM_Message_struct_CONTAINER 426
#define CSN1_Non_GSM_Message_struct_CONTAINER_SIZE   8
#define CSN1_P1RestOctets_MBMS_Notification_1 1451
#define CSN1_P1RestOctets_MBMS_Notification_1_SIZE   0
#define CSN1_P1RestOctets_MBMS_Notification_2 1452
#define CSN1_P1RestOctets_MBMS_Notification_2_SIZE   0
#define CSN1_P2RestOctets_MBMS_Notification_3 1475
#define CSN1_P2RestOctets_MBMS_Notification_3_SIZE   0
#define CSN1_PCID_Group_IE_PCID_pattern_sense 147
#define CSN1_PCID_Group_IE_PCID_pattern_sense_SIZE   1
#define CSN1_Packet_Downlink_Assignment_ALPHA 714
#define CSN1_Packet_Downlink_Assignment_ALPHA_SIZE   4
#define CSN1_Packet_Downlink_Assignment_GAMMA 715
#define CSN1_Packet_Downlink_Assignment_GAMMA_SIZE   5
#define CSN1_Packet_Uplink_Assignment_POLLING 734
#define CSN1_Packet_Uplink_Assignment_POLLING_SIZE   1
#define CSN1_Packet_Uplink_Assignment_PR_MODE 739
#define CSN1_Packet_Uplink_Assignment_PR_MODE_SIZE   1
#define CSN1_Paging_Information_channel_first 574
#define CSN1_Paging_Information_channel_first_SIZE   2
#define CSN1_RRClassmark3Value_UCS2_treatment 490
#define CSN1_RRClassmark3Value_UCS2_treatment_SIZE   1
#define CSN1_Relative_Frame_Number_Encoding_k 1219
#define CSN1_Relative_Frame_Number_Encoding_k_SIZE  13
#define CSN1_SI13RestOctets_GPRS_Cell_Options 1107
#define CSN1_SI13RestOctets_GPRS_Cell_Options_SIZE   0
#define CSN1_SI13RestOctets_PBCCH_Description 1110
#define CSN1_SI13RestOctets_PBCCH_Description_SIZE   0
#define CSN1_SI21RestOctets_SI_21_CHANGE_MARK 435
#define CSN1_SI21RestOctets_SI_21_CHANGE_MARK_SIZE   2
#define CSN1_SI22RestOctets_SI_22_CHANGE_MARK 440
#define CSN1_SI22RestOctets_SI_22_CHANGE_MARK_SIZE   2
#define CSN1_SI23RestOctets_SI_23_CHANGE_MARK 1363
#define CSN1_SI23RestOctets_SI_23_CHANGE_MARK_SIZE   2
#define CSN1_SI2quaterRestOctets_INIT_PWR_RED 1356
#define CSN1_SI2quaterRestOctets_INIT_PWR_RED_SIZE   1
#define CSN1_SI3RestOctet_SI2quater_Indicator 797
#define CSN1_SI3RestOctet_SI2quater_Indicator_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_PFI 1172
#define CSN1_Uplink_TBF_Assignment_struct_PFI_SIZE   7
#define CSN1_VGCSCipheringParameters_CELL_IND 114
#define CSN1_VGCSCipheringParameters_CELL_IND_SIZE   1
#define CSN1_VGCSCipheringParameters_RAND_IND 112
#define CSN1_VGCSCipheringParameters_RAND_IND_SIZE   1
#define CSN1_Absolute_Frame_Number_Encoding_T1 1216
#define CSN1_Absolute_Frame_Number_Encoding_T1_SIZE   5
#define CSN1_Absolute_Frame_Number_Encoding_T2 1218
#define CSN1_Absolute_Frame_Number_Encoding_T2_SIZE   5
#define CSN1_Absolute_Frame_Number_Encoding_T3 1217
#define CSN1_Absolute_Frame_Number_Encoding_T3_SIZE   6
#define CSN1_COMPACT_Cell_Selection_struct_BCC 407
#define CSN1_COMPACT_Cell_Selection_struct_BCC_SIZE   3
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_FIRST  43
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_FIRST_SIZE  10
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_RANGE  45
#define CSN1_DYNAMIC_ARFCN_MAPPING_ARFCN_RANGE_SIZE   7
#define CSN1_DYNAMIC_ARFCN_MAPPING_BAND_OFFSET  44
#define CSN1_DYNAMIC_ARFCN_MAPPING_BAND_OFFSET_SIZE  10
#define CSN1_Dynamic_Allocation_struct_PR_MODE  60
#define CSN1_Dynamic_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_Dynamic_Allocation_struct_USF_TN0  65
#define CSN1_Dynamic_Allocation_struct_USF_TN0_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN1  67
#define CSN1_Dynamic_Allocation_struct_USF_TN1_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN2  69
#define CSN1_Dynamic_Allocation_struct_USF_TN2_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN3  71
#define CSN1_Dynamic_Allocation_struct_USF_TN3_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN4  73
#define CSN1_Dynamic_Allocation_struct_USF_TN4_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN5  75
#define CSN1_Dynamic_Allocation_struct_USF_TN5_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN6  77
#define CSN1_Dynamic_Allocation_struct_USF_TN6_SIZE   3
#define CSN1_Dynamic_Allocation_struct_USF_TN7  79
#define CSN1_Dynamic_Allocation_struct_USF_TN7_SIZE   3
#define CSN1_EC_Mobile_Allocation_struct_ARFCN 626
#define CSN1_EC_Mobile_Allocation_struct_ARFCN_SIZE  10
#define CSN1_EGPRS_Packet_Uplink_Assignment_P0 672
#define CSN1_EGPRS_Packet_Uplink_Assignment_P0_SIZE   4
#define CSN1_E_UTRAN_Description_struct_EARFCN 268
#define CSN1_E_UTRAN_Description_struct_EARFCN_SIZE  16
#define CSN1_Enhanced_Measurement_report_SCALE 589
#define CSN1_Enhanced_Measurement_report_SCALE_SIZE   1
#define CSN1_Extension_Information_DTM_SUPPORT 885
#define CSN1_Extension_Information_DTM_SUPPORT_SIZE   1
#define CSN1_Extension_Information_NW_EXT_UTBF 888
#define CSN1_Extension_Information_NW_EXT_UTBF_SIZE   1
#define CSN1_GERAN_Iu_Mode_Capabilities_Length 516
#define CSN1_GERAN_Iu_Mode_Capabilities_Length_SIZE   4
#define CSN1_GPRS_BSIC_Description_struct_BSIC 1233
#define CSN1_GPRS_BSIC_Description_struct_BSIC_SIZE   6
#define CSN1_IARestOctets_PEO_BCCH_CHANGE_MARK 708
#define CSN1_IARestOctets_PEO_BCCH_CHANGE_MARK_SIZE   2
#define CSN1_IPA_Downlink_Assignment_struct_TN 1394
#define CSN1_IPA_Downlink_Assignment_struct_TN_SIZE   3
#define CSN1_Multiple_TBF_Allocation_struct_P0 1158
#define CSN1_Multiple_TBF_Allocation_struct_P0_SIZE   4
#define CSN1_MultirateSpeechCfgCodec_Threshold  55
#define CSN1_MultirateSpeechCfgCodec_Threshold_SIZE   6
#define CSN1_NOTIFICATION_FACCH_BODY_B22_COUNT 577
#define CSN1_NOTIFICATION_FACCH_BODY_B22_COUNT_SIZE   1
#define CSN1_NOTIFICATION_FACCH_BODY_VSTK_RAND 578
#define CSN1_NOTIFICATION_FACCH_BODY_VSTK_RAND_SIZE  36
#define CSN1_P1RestOctets_PEO_BCCH_CHANGE_MARK 1466
#define CSN1_P1RestOctets_PEO_BCCH_CHANGE_MARK_SIZE   2
#define CSN1_P2RestOctets_PEO_BCCH_CHANGE_MARK 1481
#define CSN1_P2RestOctets_PEO_BCCH_CHANGE_MARK_SIZE   2
#define CSN1_P3RestOctets_PEO_BCCH_CHANGE_MARK 313
#define CSN1_P3RestOctets_PEO_BCCH_CHANGE_MARK_SIZE   2
#define CSN1_PCID_Group_IE_PCID_Pattern_length 145
#define CSN1_PCID_Group_IE_PCID_Pattern_length_SIZE   3
#define CSN1_Paging_Information_eMLPP_priority 575
#define CSN1_Paging_Information_eMLPP_priority_SIZE   3
#define CSN1_Power_Control_Parameters_IE_ALPHA 131
#define CSN1_Power_Control_Parameters_IE_ALPHA_SIZE   4
#define CSN1_RFL_number_list_struct_RFL_NUMBER 126
#define CSN1_RFL_number_list_struct_RFL_NUMBER_SIZE   4
#define CSN1_RRClassmark3Value_ER_Band_Support 546
#define CSN1_RRClassmark3Value_ER_Band_Support_SIZE   1
#define CSN1_RRClassmark3Value_Offset_required 527
#define CSN1_RRClassmark3Value_Offset_required_SIZE   1
#define CSN1_RRClassmark3Value_Single_Slot_DTM 507
#define CSN1_RRClassmark3Value_Single_Slot_DTM_SIZE   1
#define CSN1_RRPacketUplinkAssignment_RLC_MODE 1186
#define CSN1_RRPacketUplinkAssignment_RLC_MODE_SIZE   1
#define CSN1_SI13RestOctets_PSI1_REPEAT_PERIOD 1109
#define CSN1_SI13RestOctets_PSI1_REPEAT_PERIOD_SIZE   4
#define CSN1_SI13_GPRS_Indicator_SI13_POSITION 795
#define CSN1_SI13_GPRS_Indicator_SI13_POSITION_SIZE   1
#define CSN1_Selection_Parameters_PENALTY_TIME 790
#define CSN1_Selection_Parameters_PENALTY_TIME_SIZE   5
#define CSN1_Serving_cell_data_struct_DTX_USED 591
#define CSN1_Serving_cell_data_struct_DTX_USED_SIZE   1
#define CSN1_Serving_cell_data_struct_MEAN_BEP 594
#define CSN1_Serving_cell_data_struct_MEAN_BEP_SIZE   5
#define CSN1_Single_Block_Allocation_struct_P0 1213
#define CSN1_Single_Block_Allocation_struct_P0_SIZE   4
#define CSN1_Timeslot_description_struct_ALPHA 1161
#define CSN1_Timeslot_description_struct_ALPHA_SIZE   4
#define CSN1_VGCSCipheringParameters_B22_COUNT 115
#define CSN1_VGCSCipheringParameters_B22_COUNT_SIZE   1
#define CSN1_VGCSCipheringParameters_VSTK_RAND 119
#define CSN1_VGCSCipheringParameters_VSTK_RAND_SIZE  40
#define CSN1_COMPACT_Cell_Selection_struct_BSIC 408
#define CSN1_COMPACT_Cell_Selection_struct_BSIC_SIZE   6
#define CSN1_COMPACT_Cell_Selection_struct_CBQ2 410
#define CSN1_COMPACT_Cell_Selection_struct_CBQ2_SIZE   2
#define CSN1_ChReqDesc2_Multiple_TBF_Capability 280
#define CSN1_ChReqDesc2_Multiple_TBF_Capability_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_PFI 1041
#define CSN1_Downlink_TBF_assignment_struct_PFI_SIZE   7
#define CSN1_EGPRS_Packet_Uplink_Assignment_PFI 696
#define CSN1_EGPRS_Packet_Uplink_Assignment_PFI_SIZE   7
#define CSN1_EGPRS_Packet_Uplink_Assignment_TSH 694
#define CSN1_EGPRS_Packet_Uplink_Assignment_TSH_SIZE   2
#define CSN1_EGPRS_Packet_Uplink_Assignment_USF 675
#define CSN1_EGPRS_Packet_Uplink_Assignment_USF_SIZE   3
#define CSN1_Extension_Information_MNCI_SUPPORT 893
#define CSN1_Extension_Information_MNCI_SUPPORT_SIZE   1
#define CSN1_GPRS_Cell_Options_IE_DRX_TIMER_MAX 873
#define CSN1_GPRS_Cell_Options_IE_DRX_TIMER_MAX_SIZE   3
#define CSN1_IPA_Uplink_Assignment_struct_GAMMA 1380
#define CSN1_IPA_Uplink_Assignment_struct_GAMMA_SIZE   5
#define CSN1_Indirect_encoding_struct_MA_NUMBER 1144
#define CSN1_Indirect_encoding_struct_MA_NUMBER_SIZE   4
#define CSN1_MS_Measurement_capability_SM_VALUE 493
#define CSN1_MS_Measurement_capability_SM_VALUE_SIZE   4
#define CSN1_Measurement_information__3G_BA_IND 899
#define CSN1_Measurement_information__3G_BA_IND_SIZE   1
#define CSN1_Mobile_Identity_struct_IMSI_Digits  27
#define CSN1_Mobile_Identity_struct_IMSI_Digits_SIZE   0
#define CSN1_MultirateSpeechCfgCodec_Hysteresis  56
#define CSN1_MultirateSpeechCfgCodec_Hysteresis_SIZE   4
#define CSN1_NOTIFICATION_FACCH_BODY_AMR_Config 581
#define CSN1_NOTIFICATION_FACCH_BODY_AMR_Config_SIZE   4
#define CSN1_Optional_Power_Offset_Power_Offset 105
#define CSN1_Optional_Power_Offset_Power_Offset_SIZE   2
#define CSN1_Packet_Downlink_Assignment_POLLING 716
#define CSN1_Packet_Downlink_Assignment_POLLING_SIZE   1
#define CSN1_Packet_Downlink_Assignment_PR_MODE 722
#define CSN1_Packet_Downlink_Assignment_PR_MODE_SIZE   1
#define CSN1_Paging_Information_mobile_identity 573
#define CSN1_Paging_Information_mobile_identity_SIZE   1
#define CSN1_RRPacketUplinkAssignment_RESEGMENT 1183
#define CSN1_RRPacketUplinkAssignment_RESEGMENT_SIZE   1
#define CSN1_RRPktDownlinkAssi_EVENT_BASED_FANR 1048
#define CSN1_RRPktDownlinkAssi_EVENT_BASED_FANR_SIZE   1
#define CSN1_SI13RestOctets_LB_MS_TXPWR_MAX_CCH 1118
#define CSN1_SI13RestOctets_LB_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_SI13RestOctets_PRIORITY_ACCESS_THR 1105
#define CSN1_SI13RestOctets_PRIORITY_ACCESS_THR_SIZE   3
#define CSN1_SI2quaterRestOctets_MP_CHANGE_MARK 1222
#define CSN1_SI2quaterRestOctets_MP_CHANGE_MARK_SIZE   1
#define CSN1_SI2quaterRestOctets__3G_CCN_ACTIVE 1294
#define CSN1_SI2quaterRestOctets__3G_CCN_ACTIVE_SIZE   1
#define CSN1_SI4_Rest_Octets_S_SI13alt_Position 809
#define CSN1_SI4_Rest_Octets_S_SI13alt_Position_SIZE   1
#define CSN1_SI6RestOctet_GPRS_MS_TXPWR_MAX_CCH 818
#define CSN1_SI6RestOctet_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Serving_cell_data_struct_RXLEV_VAL 592
#define CSN1_Serving_cell_data_struct_RXLEV_VAL_SIZE   6
#define CSN1_further_cell_info_ms_txpwr_max_cch 1428
#define CSN1_further_cell_info_ms_txpwr_max_cch_SIZE   5
#define CSN1_further_cell_info_rxlev_access_min 1429
#define CSN1_further_cell_info_rxlev_access_min_SIZE   6
#define CSN1_further_cell_info_temporary_offset 1431
#define CSN1_further_cell_info_temporary_offset_SIZE   3
#define CSN1_ARFCN_index_list_struct_ARFCN_INDEX 127
#define CSN1_ARFCN_index_list_struct_ARFCN_INDEX_SIZE   6
#define CSN1_CDMA2000_Description_struct_TD_MODE 960
#define CSN1_CDMA2000_Description_struct_TD_MODE_SIZE   2
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN0  66
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN0_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN1  68
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN1_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN2  70
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN2_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN3  72
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN3_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN4  74
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN4_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN5  76
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN5_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN6  78
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN6_SIZE   5
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN7  80
#define CSN1_Dynamic_Allocation_struct_GAMMA_TN7_SIZE   5
#define CSN1_EC_Downlink_Allocation_struct_GAMMA 657
#define CSN1_EC_Downlink_Allocation_struct_GAMMA_SIZE   5
#define CSN1_EGPRS_Packet_Uplink_Assignment_USF2 690
#define CSN1_EGPRS_Packet_Uplink_Assignment_USF2_SIZE   3
#define CSN1_Enhanced_Measurement_report_BA_USED 586
#define CSN1_Enhanced_Measurement_report_BA_USED_SIZE   1
#define CSN1_GPRS_Mobile_Allocation_IE_MA_BITMAP 557
#define CSN1_GPRS_Mobile_Allocation_IE_MA_BITMAP_SIZE   0
#define CSN1_GPRS_Mobile_Allocation_IE_MA_LENGTH 556
#define CSN1_GPRS_Mobile_Allocation_IE_MA_LENGTH_SIZE   6
#define CSN1_IPA_Downlink_Assignment_struct_TLLI 1388
#define CSN1_IPA_Downlink_Assignment_struct_TLLI_SIZE  32
#define CSN1_IndividualPriorities_GERAN_PRIORITY 852
#define CSN1_IndividualPriorities_GERAN_PRIORITY_SIZE   3
#define CSN1_MBMS_Information_MBMS_Sessions_List 1453
#define CSN1_MBMS_Information_MBMS_Sessions_List_SIZE   0
#define CSN1_MPRACH_Control_Parameters_IE_TX_INT 1422
#define CSN1_MPRACH_Control_Parameters_IE_TX_INT_SIZE   4
#define CSN1_MS_Measurement_capability_SMS_VALUE 492
#define CSN1_MS_Measurement_capability_SMS_VALUE_SIZE   4
#define CSN1_Measurement_information_REPORT_TYPE 904
#define CSN1_Measurement_information_REPORT_TYPE_SIZE   1
#define CSN1_NCELL_Report_struct_BCCH_FREQ_NCELL  53
#define CSN1_NCELL_Report_struct_BCCH_FREQ_NCELL_SIZE   5
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_MSISDN 184
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_MSISDN_SIZE   0
#define CSN1_P1RestOctets_Priority_Uplink_Access 1456
#define CSN1_P1RestOctets_Priority_Uplink_Access_SIZE   1
#define CSN1_PacketChannelDescription_spare_bits 320
#define CSN1_PacketChannelDescription_spare_bits_SIZE   2
#define CSN1_Packet_Downlink_Assignment_RLC_MODE 713
#define CSN1_Packet_Downlink_Assignment_RLC_MODE_SIZE   1
#define CSN1_Packet_Downlink_Assignment_TA_VALID 717
#define CSN1_Packet_Downlink_Assignment_TA_VALID_SIZE   1
#define CSN1_RRPktDownlinkAssi_BTS_PWR_CTRL_MODE 1027
#define CSN1_RRPktDownlinkAssi_BTS_PWR_CTRL_MODE_SIZE   1
#define CSN1_RRPktDownlinkAssi_EGPRS_Window_Size 1034
#define CSN1_RRPktDownlinkAssi_EGPRS_Window_Size_SIZE   5
#define CSN1_RRPktDownlinkAssi_NPM_Transfer_Time 1047
#define CSN1_RRPktDownlinkAssi_NPM_Transfer_Time_SIZE   5
#define CSN1_SI13altRestOctets_PBCCH_Description 1373
#define CSN1_SI13altRestOctets_PBCCH_Description_SIZE   0
#define CSN1_SI2quaterRestOctets_SI2quater_COUNT 1224
#define CSN1_SI2quaterRestOctets_SI2quater_COUNT_SIZE   4
#define CSN1_SI2quaterRestOctets_SI2quater_INDEX 1223
#define CSN1_SI2quaterRestOctets_SI2quater_INDEX_SIZE   4
#define CSN1__8_PSK_Struct_Modulation_Capability 496
#define CSN1__8_PSK_Struct_Modulation_Capability_SIZE   1
#define CSN1_further_diff_cell_info_penalty_time 1441
#define CSN1_further_diff_cell_info_penalty_time_SIZE   5
#define CSN1_Downlink_TBF_assignment_2_struct_PFI 345
#define CSN1_Downlink_TBF_assignment_2_struct_PFI_SIZE   7
#define CSN1_EC_Fixed_Uplink_Allocation_struct_P0  20
#define CSN1_EC_Fixed_Uplink_Allocation_struct_P0_SIZE   4
#define CSN1_EC_RACH_Control_Parameters_struct_Sm 210
#define CSN1_EC_RACH_Control_Parameters_struct_Sm_SIZE   2
#define CSN1_EC_RACH_Control_Parameters_struct_Tm 211
#define CSN1_EC_RACH_Control_Parameters_struct_Tm_SIZE   2
#define CSN1_EGPRS_Packet_Uplink_Assignment_ALPHA 683
#define CSN1_EGPRS_Packet_Uplink_Assignment_ALPHA_SIZE   4
#define CSN1_EGPRS_Packet_Uplink_Assignment_GAMMA 684
#define CSN1_EGPRS_Packet_Uplink_Assignment_GAMMA_SIZE   5
#define CSN1_ETWS_Primary_Notification_struct_PNI 1460
#define CSN1_ETWS_Primary_Notification_struct_PNI_SIZE   1
#define CSN1_IPA_Downlink_Assignment_struct_GAMMA 1390
#define CSN1_IPA_Downlink_Assignment_struct_GAMMA_SIZE   5
#define CSN1_NOTIFICATION_FACCH_BODY_Paging_Cause 582
#define CSN1_NOTIFICATION_FACCH_BODY_Paging_Cause_SIZE   2
#define CSN1_NTNRestOctets_Priority_Uplink_access 1017
#define CSN1_NTNRestOctets_Priority_Uplink_access_SIZE   1
#define CSN1_Packet_Downlink_Assignment_BTTI_FANR 728
#define CSN1_Packet_Downlink_Assignment_BTTI_FANR_SIZE   0
#define CSN1_Packet_Uplink_Assignment_Extended_RA 748
#define CSN1_Packet_Uplink_Assignment_Extended_RA_SIZE   5
#define CSN1_RRClassmark3Value_E_UTRA_FDD_support 534
#define CSN1_RRClassmark3Value_E_UTRA_FDD_support_SIZE   1
#define CSN1_RRClassmark3Value_E_UTRA_TDD_support 535
#define CSN1_RRClassmark3Value_E_UTRA_TDD_support_SIZE   1
#define CSN1_RRClassmark3Value_TIGHTER_Capability 540
#define CSN1_RRClassmark3Value_TIGHTER_Capability_SIZE   2
#define CSN1_RRPacketDownlinkAssignmentType2_FANR 1079
#define CSN1_RRPacketDownlinkAssignmentType2_FANR_SIZE   1
#define CSN1_RRPktDownlinkAssi_MEASUREMENT_BITMAP 1033
#define CSN1_RRPktDownlinkAssi_MEASUREMENT_BITMAP_SIZE   8
#define CSN1_SI10bis_Rest_Octets_SI10bis_Sequence 848
#define CSN1_SI10bis_Rest_Octets_SI10bis_Sequence_SIZE   2
#define CSN1_SI13RestOctets_NETWORK_CONTROL_ORDER 1106
#define CSN1_SI13RestOctets_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_SI2quaterRestOctets_extension_length 1262
#define CSN1_SI2quaterRestOctets_extension_length_SIZE   8
#define CSN1_Single_Block_Allocation_struct_ALPHA 1211
#define CSN1_Single_Block_Allocation_struct_ALPHA_SIZE   4
#define CSN1_USF_Assignment_struct_USF_ALLOCATION 1180
#define CSN1_USF_Assignment_struct_USF_ALLOCATION_SIZE   3
#define CSN1_Validity_Information_Validity_bitmap 613
#define CSN1_Validity_Information_Validity_bitmap_SIZE   3
#define CSN1_ChReqDesc2_PACKET_ESTABLISHMENT_CAUSE 272
#define CSN1_ChReqDesc2_PACKET_ESTABLISHMENT_CAUSE_SIZE   2
#define CSN1_ChReqDesc2_Reduced_Latency_Capability 282
#define CSN1_ChReqDesc2_Reduced_Latency_Capability_SIZE   1
#define CSN1_EC_Downlink_Allocation_struct_PR_MODE 660
#define CSN1_EC_Downlink_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_EC_Mobile_Allocation_struct_MA_BITMAP 625
#define CSN1_EC_Mobile_Allocation_struct_MA_BITMAP_SIZE   0
#define CSN1_EC_Mobile_Allocation_struct_MA_LENGTH 624
#define CSN1_EC_Mobile_Allocation_struct_MA_LENGTH_SIZE   6
#define CSN1_EGPRS_Modulation_and_Coding_IE_Scheme 678
#define CSN1_EGPRS_Modulation_and_Coding_IE_Scheme_SIZE   4
#define CSN1_Enhanced_Measurement_report_BSIC_Seen 588
#define CSN1_Enhanced_Measurement_report_BSIC_Seen_SIZE   1
#define CSN1_Extension_Information_EXT_UTBF_NODATA 890
#define CSN1_Extension_Information_EXT_UTBF_NODATA_SIZE   1
#define CSN1_Extension_Information_NMO_I_ALTERNATE 895
#define CSN1_Extension_Information_NMO_I_ALTERNATE_SIZE   1
#define CSN1_GPRS_Cell_Options_IE_CONTROL_ACK_TYPE 875
#define CSN1_GPRS_Cell_Options_IE_CONTROL_ACK_TYPE_SIZE   1
#define CSN1_GPRS_Cell_Options_IE_Extension_Length 881
#define CSN1_GPRS_Cell_Options_IE_Extension_Length_SIZE   6
#define CSN1_GSM_Description_struct_Band_Indicator  29
#define CSN1_GSM_Description_struct_Band_Indicator_SIZE   1
#define CSN1_NOTIFICATION_FACCH_BODY_Emergency_Ind 580
#define CSN1_NOTIFICATION_FACCH_BODY_Emergency_Ind_SIZE   1
#define CSN1_P1RestOctets_Packet_Page_Indication_1 1446
#define CSN1_P1RestOctets_Packet_Page_Indication_1_SIZE   1
#define CSN1_P1RestOctets_Packet_Page_Indication_2 1447
#define CSN1_P1RestOctets_Packet_Page_Indication_2_SIZE   1
#define CSN1_P2RestOctets_Packet_Page_Indication_3 1474
#define CSN1_P2RestOctets_Packet_Page_Indication_3_SIZE   1
#define CSN1_PacketChannelDescription_Channel_type 315
#define CSN1_PacketChannelDescription_Channel_type_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN0 132
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN0_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN1 133
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN1_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN2 134
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN2_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN3 135
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN3_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN4 136
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN4_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN5 137
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN5_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN6 138
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN6_SIZE   5
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN7 139
#define CSN1_Power_Control_Parameters_IE_GAMMA_TN7_SIZE   5
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_1 1194
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_1_SIZE   3
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_2 1190
#define CSN1_Pulse_Format_IE_Pulse_Format_Coding_2_SIZE   0
#define CSN1_RRClassmark3Value_Multiband_supported 485
#define CSN1_RRClassmark3Value_Multiband_supported_SIZE   3
#define CSN1_RRPacketDownlinkAssignmentType2_P0_C1 1060
#define CSN1_RRPacketDownlinkAssignmentType2_P0_C1_SIZE   4
#define CSN1_RRPacketDownlinkAssignmentType2_P0_C2 1062
#define CSN1_RRPacketDownlinkAssignmentType2_P0_C2_SIZE   4
#define CSN1_RRPacketUplinkAssignment_Pulse_Format 1189
#define CSN1_RRPacketUplinkAssignment_Pulse_Format_SIZE   0
#define CSN1_RRPacketUplinkAssignment_RLC_Entity_2 1201
#define CSN1_RRPacketUplinkAssignment_RLC_Entity_2_SIZE   0
#define CSN1_RRPacketUplinkAssignment_RLC_Entity_3 1202
#define CSN1_RRPacketUplinkAssignment_RLC_Entity_3_SIZE   0
#define CSN1_RRPktDownlinkAssi_TIMESLOT_ALLOCATION 1024
#define CSN1_RRPktDownlinkAssi_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_SI10bis_Neighbour_Cell_Info_B22_COUNT 464
#define CSN1_SI10bis_Neighbour_Cell_Info_B22_COUNT_SIZE   1
#define CSN1_SI13RestOctets_GPRS_Mobile_Allocation 1101
#define CSN1_SI13RestOctets_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_SI21RestOctets_EAB_Authorization_Mask 438
#define CSN1_SI21RestOctets_EAB_Authorization_Mask_SIZE  10
#define CSN1_Selection_Parameters_TEMPORARY_OFFSET 789
#define CSN1_Selection_Parameters_TEMPORARY_OFFSET_SIZE   3
#define CSN1_Serving_cell_data_struct_RX_QUAL_FULL 593
#define CSN1_Serving_cell_data_struct_RX_QUAL_FULL_SIZE   3
#define CSN1_Timeslot_description_struct_GAMMA_TN0 1163
#define CSN1_Timeslot_description_struct_GAMMA_TN0_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN1 1164
#define CSN1_Timeslot_description_struct_GAMMA_TN1_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN2 1165
#define CSN1_Timeslot_description_struct_GAMMA_TN2_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN3 1166
#define CSN1_Timeslot_description_struct_GAMMA_TN3_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN4 1167
#define CSN1_Timeslot_description_struct_GAMMA_TN4_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN5 1168
#define CSN1_Timeslot_description_struct_GAMMA_TN5_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN6 1169
#define CSN1_Timeslot_description_struct_GAMMA_TN6_SIZE   5
#define CSN1_Timeslot_description_struct_GAMMA_TN7 1170
#define CSN1_Timeslot_description_struct_GAMMA_TN7_SIZE   5
#define CSN1_UPLINK_FREE_BODY_Uplink_Identity_Code 163
#define CSN1_UPLINK_FREE_BODY_Uplink_Identity_Code_SIZE   6
#define CSN1_UPLINK_FREE_BODY_short_layer_2_header 161
#define CSN1_UPLINK_FREE_BODY_short_layer_2_header_SIZE   2
#define CSN1_Uplink_TBF_Assignment_struct_RLC_MODE 1173
#define CSN1_Uplink_TBF_Assignment_struct_RLC_MODE_SIZE   1
#define CSN1_VGCSCipheringParameters_Cell_Identity 117
#define CSN1_VGCSCipheringParameters_Cell_Identity_SIZE  16
#define CSN1_la_different_cell_reselect_hysteresis   7
#define CSN1_la_different_cell_reselect_hysteresis_SIZE   3
#define CSN1_neighbour_information_first_frequency 1426
#define CSN1_neighbour_information_first_frequency_SIZE   5
#define CSN1_BSIC_Description_struct_Remaining_BSIC 914
#define CSN1_BSIC_Description_struct_Remaining_BSIC_SIZE   7
#define CSN1_ChReqDesc2_Channel_Request_Description 273
#define CSN1_ChReqDesc2_Channel_Request_Description_SIZE  24
#define CSN1_EGPRS_Packet_Uplink_Assignment_POLLING 669
#define CSN1_EGPRS_Packet_Uplink_Assignment_POLLING_SIZE   1
#define CSN1_EGPRS_Packet_Uplink_Assignment_PR_MODE 674
#define CSN1_EGPRS_Packet_Uplink_Assignment_PR_MODE_SIZE   1
#define CSN1_E_UTRAN_CSG_Description_struct_CSG_PCI 1345
#define CSN1_E_UTRAN_CSG_Description_struct_CSG_PCI_SIZE   0
#define CSN1_E_UTRAN_Description_struct_TARGET_PCID 271
#define CSN1_E_UTRAN_Description_struct_TARGET_PCID_SIZE   9
#define CSN1_Extension_Information_PFC_FEATURE_MODE 884
#define CSN1_Extension_Information_PFC_FEATURE_MODE_SIZE   1
#define CSN1_Fixed_Allocation_struct_Message_escape 1653
#define CSN1_Fixed_Allocation_struct_Message_escape_SIZE   0
#define CSN1_GPRS_Cell_Options_IE_ACCESS_BURST_TYPE 874
#define CSN1_GPRS_Cell_Options_IE_ACCESS_BURST_TYPE_SIZE   1
#define CSN1_GPRS_Power_Control_Parameters_IE_ALPHA 150
#define CSN1_GPRS_Power_Control_Parameters_IE_ALPHA_SIZE   4
#define CSN1_IPA_Uplink_Assignment_struct_FN_OFFSET 1379
#define CSN1_IPA_Uplink_Assignment_struct_FN_OFFSET_SIZE   8
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_1 1145
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_1_SIZE   2
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_2 1146
#define CSN1_Indirect_encoding_struct_CHANGE_MARK_2_SIZE   2
#define CSN1_MBMS_Information_P2_MBMS_Sessions_List 1476
#define CSN1_MBMS_Information_P2_MBMS_Sessions_List_SIZE   0
#define CSN1_Measurement_information_MP_CHANGE_MARK 900
#define CSN1_Measurement_information_MP_CHANGE_MARK_SIZE   1
#define CSN1_Measurement_information_REPORTING_RATE 905
#define CSN1_Measurement_information_REPORTING_RATE_SIZE   1
#define CSN1_Multiple_TBF_Allocation_struct_PR_MODE 1159
#define CSN1_Multiple_TBF_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_P1RestOctets_ETWS_Primary_Notification 1457
#define CSN1_P1RestOctets_ETWS_Primary_Notification_SIZE   0
#define CSN1_PacketChannelDescription_CHANGE_MARK_1 321
#define CSN1_PacketChannelDescription_CHANGE_MARK_1_SIZE   2
#define CSN1_PacketChannelDescription_MA_NUMBER_IND 319
#define CSN1_PacketChannelDescription_MA_NUMBER_IND_SIZE   1
#define CSN1_Packet_Downlink_Assignment_BEP_PERIOD2 725
#define CSN1_Packet_Downlink_Assignment_BEP_PERIOD2_SIZE   4
#define CSN1_RLC_Entity_Struct_DN_EGPRS_Window_Size 343
#define CSN1_RLC_Entity_Struct_DN_EGPRS_Window_Size_SIZE   5
#define CSN1_RLC_Entity_Struct_UP_EGPRS_Window_Size 338
#define CSN1_RLC_Entity_Struct_UP_EGPRS_Window_Size_SIZE   5
#define CSN1_RRPktDownlinkAssi_Downlink_EGPRS_Level 1049
#define CSN1_RRPktDownlinkAssi_Downlink_EGPRS_Level_SIZE   2
#define CSN1_RRPktDownlinkAssi_MEASUREMENT_INTERVAL 1032
#define CSN1_RRPktDownlinkAssi_MEASUREMENT_INTERVAL_SIZE   5
#define CSN1_SI10bis_Neighbour_Cell_Info_Tx_Integer 471
#define CSN1_SI10bis_Neighbour_Cell_Info_Tx_Integer_SIZE   4
#define CSN1_SI2terRestOctets_SI2ter_3G_CHANGE_MARK 355
#define CSN1_SI2terRestOctets_SI2ter_3G_CHANGE_MARK_SIZE   1
#define CSN1_SI2terRestOctets_SI2ter_MP_CHANGE_MARK 354
#define CSN1_SI2terRestOctets_SI2ter_MP_CHANGE_MARK_SIZE   1
#define CSN1_SI2terRestOctets_UTRAN_FDD_Description 358
#define CSN1_SI2terRestOctets_UTRAN_FDD_Description_SIZE   0
#define CSN1_SI2terRestOctets_UTRAN_TDD_Description 365
#define CSN1_SI2terRestOctets_UTRAN_TDD_Description_SIZE   0
#define CSN1_Single_Block_Allocation_struct_PR_MODE 1214
#define CSN1_Single_Block_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_UPLINK_FREE_BODY_Uplink_Access_Request 162
#define CSN1_UPLINK_FREE_BODY_Uplink_Access_Request_SIZE   1
#define CSN1_UTRAN_CSG_Measurement_Report_IE_CSG_ID 569
#define CSN1_UTRAN_CSG_Measurement_Report_IE_CSG_ID_SIZE  27
#define CSN1_further_cell_info_cell_reselect_offset 1430
#define CSN1_further_cell_info_cell_reselect_offset_SIZE   6
#define CSN1_CDMA2000_Description_struct_WALSH_LEN_A 961
#define CSN1_CDMA2000_Description_struct_WALSH_LEN_A_SIZE   3
#define CSN1_CDMA2000_Description_struct_WALSH_LEN_B 957
#define CSN1_CDMA2000_Description_struct_WALSH_LEN_B_SIZE   3
#define CSN1_CDMA2000_Description_struct_WALSH_LEN_C 949
#define CSN1_CDMA2000_Description_struct_WALSH_LEN_C_SIZE   3
#define CSN1_Channel_Request_Description_IE_RLC_MODE 276
#define CSN1_Channel_Request_Description_IE_RLC_MODE_SIZE   1
#define CSN1_DTMInfoRestOctets_GPRS_MS_TXPWR_MAX_CCH 289
#define CSN1_DTMInfoRestOctets_GPRS_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_Downlink_TBF_assignment_struct_RLC_MODE 1042
#define CSN1_Downlink_TBF_assignment_struct_RLC_MODE_SIZE   1
#define CSN1_EC_Fixed_Uplink_Allocation_struct_GAMMA  18
#define CSN1_EC_Fixed_Uplink_Allocation_struct_GAMMA_SIZE   5
#define CSN1_Enhanced_Measurement_report__3G_BA_USED 587
#define CSN1_Enhanced_Measurement_report__3G_BA_USED_SIZE   1
#define CSN1_IPA_Downlink_Assignment_struct_RLC_MODE 1393
#define CSN1_IPA_Downlink_Assignment_struct_RLC_MODE_SIZE   1
#define CSN1_List_of_VSTK_RAND_information_VSTK_RAND 1016
#define CSN1_List_of_VSTK_RAND_information_VSTK_RAND_SIZE  36
#define CSN1_Packet_Uplink_Assignment_TFI_ASSIGNMENT 733
#define CSN1_Packet_Uplink_Assignment_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RRPacketUplinkAssignment_EGPRS_MCS_MODE 1182
#define CSN1_RRPacketUplinkAssignment_EGPRS_MCS_MODE_SIZE   4
#define CSN1_RRPktDownlinkAssi_Packet_Timing_Advance 1025
#define CSN1_RRPktDownlinkAssi_Packet_Timing_Advance_SIZE   0
#define CSN1_RRPktDownlinkAssi_UTRAN_FREQUENCY_INDEX 1053
#define CSN1_RRPktDownlinkAssi_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_SI10bis_Neighbour_Cell_Info_Max_retrans 470
#define CSN1_SI10bis_Neighbour_Cell_Info_Max_retrans_SIZE   2
#define CSN1_SI2quaterRestOctets__3G_CSG_Description 1343
#define CSN1_SI2quaterRestOctets__3G_CSG_Description_SIZE   0
#define CSN1_Segmented_SMS_Description_struct_Length 173
#define CSN1_Segmented_SMS_Description_struct_Length_SIZE   8
#define CSN1_Single_Block_Allocation_struct_GAMMA_TN 1212
#define CSN1_Single_Block_Allocation_struct_GAMMA_TN_SIZE   5
#define CSN1_UTRAN_CSG_Measurement_Report_IE_PLMN_ID 568
#define CSN1_UTRAN_CSG_Measurement_Report_IE_PLMN_ID_SIZE  24
#define CSN1_VBS_VGCS_RECONFIGURE_BODY_Starting_Time 159
#define CSN1_VBS_VGCS_RECONFIGURE_BODY_Starting_Time_SIZE  16
#define CSN1_further_diff_cell_info_ms_txpwr_max_cch 1437
#define CSN1_further_diff_cell_info_ms_txpwr_max_cch_SIZE   5
#define CSN1_further_diff_cell_info_rxlev_access_min 1438
#define CSN1_further_diff_cell_info_rxlev_access_min_SIZE   6
#define CSN1_further_diff_cell_info_temporary_offset 1440
#define CSN1_further_diff_cell_info_temporary_offset_SIZE   3
#define CSN1_CDMA2000_Description_struct_AUX_TD_WALSH 958
#define CSN1_CDMA2000_Description_struct_AUX_TD_WALSH_SIZE   0
#define CSN1_COMPACT_Cell_Selection_struct_TIME_GROUP 418
#define CSN1_COMPACT_Cell_Selection_struct_TIME_GROUP_SIZE   2
#define CSN1_EC_Fixed_Uplink_Allocation_struct_No_gap  25
#define CSN1_EC_Fixed_Uplink_Allocation_struct_No_gap_SIZE   1
#define CSN1_EC_Mobile_Allocation_struct_EC_MA_NUMBER 621
#define CSN1_EC_Mobile_Allocation_struct_EC_MA_NUMBER_SIZE   5
#define CSN1_EC_Packet_Channel_Description_Type_1_TSC 476
#define CSN1_EC_Packet_Channel_Description_Type_1_TSC_SIZE   3
#define CSN1_EC_Packet_Channel_Description_Type_2_TSC 483
#define CSN1_EC_Packet_Channel_Description_Type_2_TSC_SIZE   3
#define CSN1_EGPRS_Packet_Uplink_Assignment_BTTI_FANR 693
#define CSN1_EGPRS_Packet_Uplink_Assignment_BTTI_FANR_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_RESEGMENT 681
#define CSN1_EGPRS_Packet_Uplink_Assignment_RESEGMENT_SIZE   1
#define CSN1_Enhanced_Measurement_report_SI23_BA_USED 609
#define CSN1_Enhanced_Measurement_report_SI23_BA_USED_SIZE   1
#define CSN1_Fixed_Allocation_struct_FINAL_ALLOCATION 325
#define CSN1_Fixed_Allocation_struct_FINAL_ALLOCATION_SIZE   1
#define CSN1_Fixed_Allocation_struct_HALF_DUPLEX_MODE 332
#define CSN1_Fixed_Allocation_struct_HALF_DUPLEX_MODE_SIZE   1
#define CSN1_GPRS_Power_Control_Parameters_IE_N_AVG_I 154
#define CSN1_GPRS_Power_Control_Parameters_IE_N_AVG_I_SIZE   4
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_T 152
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_T_SIZE   5
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_W 151
#define CSN1_GPRS_Power_Control_Parameters_IE_T_AVG_W_SIZE   5
#define CSN1_IndividualPriorities_T3230_timeout_value 864
#define CSN1_IndividualPriorities_T3230_timeout_value_SIZE   3
#define CSN1_List_of_VSTK_RAND_information_Segment_Id 1015
#define CSN1_List_of_VSTK_RAND_information_Segment_Id_SIZE   1
#define CSN1_MBMS_Information_MBMS_Channel_Parameters 1454
#define CSN1_MBMS_Information_MBMS_Channel_Parameters_SIZE   0
#define CSN1_MPRACH_Control_Parameters_IE_MAX_RETRANS 1420
#define CSN1_MPRACH_Control_Parameters_IE_MAX_RETRANS_SIZE   2
#define CSN1_Measurement_information_BSIC_Description 910
#define CSN1_Measurement_information_BSIC_Description_SIZE   0
#define CSN1_Measurement_information_extension_length 933
#define CSN1_Measurement_information_extension_length_SIZE   8
#define CSN1_NTNRestOctets_SMS_Guaranteed_Privacy_Ind 1021
#define CSN1_NTNRestOctets_SMS_Guaranteed_Privacy_Ind_SIZE   1
#define CSN1_Packet_Uplink_Assignment_USF_GRANULARITY 741
#define CSN1_Packet_Uplink_Assignment_USF_GRANULARITY_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_RLC_MODE 1059
#define CSN1_RRPacketDownlinkAssignmentType2_RLC_MODE_SIZE   1
#define CSN1_RRPktDownlinkAssi_EMSR_Additional_PFCs_1 1056
#define CSN1_RRPktDownlinkAssi_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_RRPktDownlinkAssi_EMSR_Additional_PFCs_2 1057
#define CSN1_RRPktDownlinkAssi_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_RRPktDownlinkAssi_EMSR_Additional_PFCs_3 1058
#define CSN1_RRPktDownlinkAssi_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_SI10bis_Rest_Octets_Position_in_SI5_list 849
#define CSN1_SI10bis_Rest_Octets_Position_in_SI5_list_SIZE   5
#define CSN1_Serving_cell_data_struct_NBR_RCVD_BLOCKS 596
#define CSN1_Serving_cell_data_struct_NBR_RCVD_BLOCKS_SIZE   5
#define CSN1__3G_CSG_Description_struct_CSG_PSC_SPLIT 397
#define CSN1__3G_CSG_Description_struct_CSG_PSC_SPLIT_SIZE   0
#define CSN1_CDMA2000_Description_struct_AUX_WALSH_LEN 950
#define CSN1_CDMA2000_Description_struct_AUX_WALSH_LEN_SIZE   0
#define CSN1_CDMA2000_Description_struct_WALSH_LENGTH1 952
#define CSN1_CDMA2000_Description_struct_WALSH_LENGTH1_SIZE   3
#define CSN1_CDMA2000_Description_struct_WALSH_LENGTH2 955
#define CSN1_CDMA2000_Description_struct_WALSH_LENGTH2_SIZE   3
#define CSN1_COMPACT_Cell_Selection_struct_CELL_BARRED 409
#define CSN1_COMPACT_Cell_Selection_struct_CELL_BARRED_SIZE   1
#define CSN1_COMPACT_Neighbour_Cell_params_struct_Cell 1136
#define CSN1_COMPACT_Neighbour_Cell_params_struct_Cell_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_RLC_MODE 346
#define CSN1_Downlink_TBF_assignment_2_struct_RLC_MODE_SIZE   1
#define CSN1_Dynamic_Allocation_struct_USF_GRANULARITY  61
#define CSN1_Dynamic_Allocation_struct_USF_GRANULARITY_SIZE   1
#define CSN1_EC_Fixed_Uplink_Allocation_struct_PR_MODE  21
#define CSN1_EC_Fixed_Uplink_Allocation_struct_PR_MODE_SIZE   1
#define CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme 1177
#define CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme_SIZE   4
#define CSN1_E_UTRAN_CSG_Description_struct_CSG_EARFCN 1348
#define CSN1_E_UTRAN_CSG_Description_struct_CSG_EARFCN_SIZE  16
#define CSN1_Enhanced_Measurement_report_BITMAP_LENGTH 602
#define CSN1_Enhanced_Measurement_report_BITMAP_LENGTH_SIZE   7
#define CSN1_Fixed_Allocation_struct_ALLOCATION_BITMAP 335
#define CSN1_Fixed_Allocation_struct_ALLOCATION_BITMAP_SIZE   0
#define CSN1_Fixed_Allocation_struct_BTS_PWR_CTRL_MODE 328
#define CSN1_Fixed_Allocation_struct_BTS_PWR_CTRL_MODE_SIZE   1
#define CSN1_Frequency_Parameters_IE_Direct_encoding_1 1139
#define CSN1_Frequency_Parameters_IE_Direct_encoding_1_SIZE   0
#define CSN1_Frequency_Parameters_IE_Direct_encoding_2 1147
#define CSN1_Frequency_Parameters_IE_Direct_encoding_2_SIZE   0
#define CSN1_Frequency_Parameters_IE_Indirect_encoding 1142
#define CSN1_Frequency_Parameters_IE_Indirect_encoding_SIZE   0
#define CSN1_GPRS_Mobile_Allocation_IE_RFL_number_list 552
#define CSN1_GPRS_Mobile_Allocation_IE_RFL_number_list_SIZE   0
#define CSN1_MeasurementResults_RXLEV_SUB_SERVING_CELL 761
#define CSN1_MeasurementResults_RXLEV_SUB_SERVING_CELL_SIZE   6
#define CSN1_NOTIFICATION_FACCH_BODY_CELL_GLOBAL_COUNT 576
#define CSN1_NOTIFICATION_FACCH_BODY_CELL_GLOBAL_COUNT_SIZE   2
#define CSN1_Packet_Downlink_Assignment_TFI_ASSIGNMENT 712
#define CSN1_Packet_Downlink_Assignment_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RRClassmark3Value_GERAN_Feature_Package_1 512
#define CSN1_RRClassmark3Value_GERAN_Feature_Package_1_SIZE   1
#define CSN1_RRClassmark3Value_GERAN_Feature_Package_2 518
#define CSN1_RRClassmark3Value_GERAN_Feature_Package_2_SIZE   1
#define CSN1_RRClassmark3Value_GSM_400_Bands_Supported 499
#define CSN1_RRClassmark3Value_GSM_400_Bands_Supported_SIZE   2
#define CSN1_RRPacketUplinkAssignment_Fixed_Allocation 1208
#define CSN1_RRPacketUplinkAssignment_Fixed_Allocation_SIZE   0
#define CSN1_RRPktDownlinkAssi_DOWNLINK_TFI_ASSIGNMENT 1030
#define CSN1_RRPktDownlinkAssi_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RRPktDownlinkAssi_E_UTRAN_FREQUENCY_INDEX 1051
#define CSN1_RRPktDownlinkAssi_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_SI10bis_Neighbour_Cell_Info_FR_AMR_Config 466
#define CSN1_SI10bis_Neighbour_Cell_Info_FR_AMR_Config_SIZE   4
#define CSN1_SI10bis_Neighbour_Cell_Info_HR_AMR_Config 467
#define CSN1_SI10bis_Neighbour_Cell_Info_HR_AMR_Config_SIZE   4
#define CSN1_SI2_UTRAN_FDD_Description_struct_SC_P_SCG 362
#define CSN1_SI2_UTRAN_FDD_Description_struct_SC_P_SCG_SIZE   8
#define CSN1_SI2quaterRestOctets_GPRS_BSIC_Description 1231
#define CSN1_SI2quaterRestOctets_GPRS_BSIC_Description_SIZE   0
#define CSN1_SI2quaterRestOctets__700_REPORTING_OFFSET 1295
#define CSN1_SI2quaterRestOctets__700_REPORTING_OFFSET_SIZE   3
#define CSN1_SI2quaterRestOctets__810_REPORTING_OFFSET 1297
#define CSN1_SI2quaterRestOctets__810_REPORTING_OFFSET_SIZE   3
#define CSN1_Second_Part_Packet_Assignment_Extended_RA 750
#define CSN1_Second_Part_Packet_Assignment_Extended_RA_SIZE   5
#define CSN1_Selection_Parameters_CELL_RESELECT_OFFSET 788
#define CSN1_Selection_Parameters_CELL_RESELECT_OFFSET_SIZE   6
#define CSN1_UTRAN_CSG_Measurement_Report_IE_UTRAN_CGI 567
#define CSN1_UTRAN_CSG_Measurement_Report_IE_UTRAN_CGI_SIZE  28
#define CSN1_UTRAN_FDD_Description_struct_CS_FDD_ARFCN  33
#define CSN1_UTRAN_FDD_Description_struct_CS_FDD_ARFCN_SIZE  14
#define CSN1_UTRAN_TDD_Description_struct_CS_TDD_ARFCN  38
#define CSN1_UTRAN_TDD_Description_struct_CS_TDD_ARFCN_SIZE  14
#define CSN1_VGCSCipheringParameters_CELL_GLOBAL_COUNT 116
#define CSN1_VGCSCipheringParameters_CELL_GLOBAL_COUNT_SIZE   2
#define CSN1_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY_BSIC 612
#define CSN1_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY_BSIC_SIZE   6
#define CSN1__3G_CSG_Description_struct_CSG_FDD_UARFCN 403
#define CSN1__3G_CSG_Description_struct_CSG_FDD_UARFCN_SIZE  14
#define CSN1__3G_CSG_Description_struct_CSG_TDD_UARFCN 404
#define CSN1__3G_CSG_Description_struct_CSG_TDD_UARFCN_SIZE  14
#define CSN1_CDMA2000_Description_struct_SR3_PRIM_PILOT 945
#define CSN1_CDMA2000_Description_struct_SR3_PRIM_PILOT_SIZE   2
#define CSN1_CDMA2000_Description_struct_TD_POWER_LEVEL 963
#define CSN1_CDMA2000_Description_struct_TD_POWER_LEVEL_SIZE   3
#define CSN1_COMPACT_Cell_Selection_struct_PENALTY_TIME 417
#define CSN1_COMPACT_Cell_Selection_struct_PENALTY_TIME_SIZE   5
#define CSN1_Downlink_TBF_assignment_struct_CONTROL_ACK 1044
#define CSN1_Downlink_TBF_assignment_struct_CONTROL_ACK_SIZE   1
#define CSN1_EC_Downlink_Allocation_struct_ALPHA_Enable 658
#define CSN1_EC_Downlink_Allocation_struct_ALPHA_Enable_SIZE   1
#define CSN1_EC_System_Information_Type_1_EC_SI_1_COUNT 615
#define CSN1_EC_System_Information_Type_1_EC_SI_1_COUNT_SIZE   2
#define CSN1_EC_System_Information_Type_1_EC_SI_1_INDEX 614
#define CSN1_EC_System_Information_Type_1_EC_SI_1_INDEX_SIZE   2
#define CSN1_EC_System_Information_Type_2_EC_SI_2_COUNT 187
#define CSN1_EC_System_Information_Type_2_EC_SI_2_COUNT_SIZE   2
#define CSN1_EC_System_Information_Type_2_EC_SI_2_INDEX 186
#define CSN1_EC_System_Information_Type_2_EC_SI_2_INDEX_SIZE   2
#define CSN1_EC_System_Information_Type_3_EC_SI_3_COUNT 231
#define CSN1_EC_System_Information_Type_3_EC_SI_3_COUNT_SIZE   2
#define CSN1_EC_System_Information_Type_3_EC_SI_3_INDEX 230
#define CSN1_EC_System_Information_Type_3_EC_SI_3_INDEX_SIZE   2
#define CSN1_EC_System_Information_Type_4_EC_SI_4_COUNT 252
#define CSN1_EC_System_Information_Type_4_EC_SI_4_COUNT_SIZE   2
#define CSN1_EC_System_Information_Type_4_EC_SI_4_INDEX 251
#define CSN1_EC_System_Information_Type_4_EC_SI_4_INDEX_SIZE   2
#define CSN1_EGPRS_Packet_Uplink_Assignment_BEP_PERIOD2 680
#define CSN1_EGPRS_Packet_Uplink_Assignment_BEP_PERIOD2_SIZE   4
#define CSN1_EGPRS_Packet_Uplink_Assignment_Extended_RA 666
#define CSN1_EGPRS_Packet_Uplink_Assignment_Extended_RA_SIZE   5
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN_index_list 554
#define CSN1_GPRS_Mobile_Allocation_IE_ARFCN_index_list_SIZE   0
#define CSN1_MPRACH_description_IE_Frequency_Parameters 1415
#define CSN1_MPRACH_description_IE_Frequency_Parameters_SIZE   0
#define CSN1_MeasurementResults_RXLEV_FULL_SERVING_CELL 758
#define CSN1_MeasurementResults_RXLEV_FULL_SERVING_CELL_SIZE   6
#define CSN1_MeasurementResults_RXQUAL_SUB_SERVING_CELL 764
#define CSN1_MeasurementResults_RXQUAL_SUB_SERVING_CELL_SIZE   3
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_MSISDN_length 183
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_MSISDN_length_SIZE   4
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_data_identity 182
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_data_identity_SIZE   8
#define CSN1_NTNRestOctets_SMS_Data_Confidentiality_Ind 1020
#define CSN1_NTNRestOctets_SMS_Data_Confidentiality_Ind_SIZE   1
#define CSN1_Packet_Uplink_Assignment_ALLOCATION_BITMAP 736
#define CSN1_Packet_Uplink_Assignment_ALLOCATION_BITMAP_SIZE   0
#define CSN1_Packet_Uplink_Assignment_BTS_PWR_CTRL_MODE 738
#define CSN1_Packet_Uplink_Assignment_BTS_PWR_CTRL_MODE_SIZE   1
#define CSN1_Packet_Uplink_Assignment_TBF_STARTING_TIME 747
#define CSN1_Packet_Uplink_Assignment_TBF_STARTING_TIME_SIZE  16
#define CSN1_RLC_Entity_Struct_UP_UPLINK_TFI_ASSIGNMENT 336
#define CSN1_RLC_Entity_Struct_UP_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RRClassmark3Value_Repeated_ACCH_Capability 529
#define CSN1_RRClassmark3Value_Repeated_ACCH_Capability_SIZE   1
#define CSN1_RRClassmark3Value_UTRA_CSG_Cells_Reporting 538
#define CSN1_RRClassmark3Value_UTRA_CSG_Cells_Reporting_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_PR_MODE_C1 1061
#define CSN1_RRPacketDownlinkAssignmentType2_PR_MODE_C1_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_PR_MODE_C2 1063
#define CSN1_RRPacketDownlinkAssignmentType2_PR_MODE_C2_SIZE   1
#define CSN1_RRPacketUplinkAssignment_EGPRS_Window_Size 1184
#define CSN1_RRPacketUplinkAssignment_EGPRS_Window_Size_SIZE   5
#define CSN1_RRPacketUplinkAssignment_NPM_Transfer_Time 1187
#define CSN1_RRPacketUplinkAssignment_NPM_Transfer_Time_SIZE   5
#define CSN1_RRPktDownlinkAssi_Power_Control_Parameters 1029
#define CSN1_RRPktDownlinkAssi_Power_Control_Parameters_SIZE   0
#define CSN1_SI10bis_Neighbour_Cell_Info_Frequency_List 462
#define CSN1_SI10bis_Neighbour_Cell_Info_Frequency_List_SIZE   0
#define CSN1_SI22RestOctets_Network_Sharing_Information 443
#define CSN1_SI22RestOctets_Network_Sharing_Information_SIZE   0
#define CSN1_SI2_UTRAN_FDD_Description_struct_Diversity 361
#define CSN1_SI2_UTRAN_FDD_Description_struct_Diversity_SIZE   1
#define CSN1_SI2_UTRAN_FDD_Description_struct_FDD_ARFCN 363
#define CSN1_SI2_UTRAN_FDD_Description_struct_FDD_ARFCN_SIZE  14
#define CSN1_SI2_UTRAN_TDD_Description_struct_Diversity 369
#define CSN1_SI2_UTRAN_TDD_Description_struct_Diversity_SIZE   1
#define CSN1_SI2_UTRAN_TDD_Description_struct_Sync_Case 368
#define CSN1_SI2_UTRAN_TDD_Description_struct_Sync_Case_SIZE   1
#define CSN1_SI2_UTRAN_TDD_Description_struct_TDD_ARFCN 370
#define CSN1_SI2_UTRAN_TDD_Description_struct_TDD_ARFCN_SIZE  14
#define CSN1_SI2quaterRestOctets_NC2_CSG_PCCN_permitted 1357
#define CSN1_SI2quaterRestOctets_NC2_CSG_PCCN_permitted_SIZE   1
#define CSN1_UTRAN_FDD_Description_struct_Bandwidth_FDD 380
#define CSN1_UTRAN_FDD_Description_struct_Bandwidth_FDD_SIZE   3
#define CSN1_UTRAN_FDD_Description_struct_CS_FDD_Indic0  34
#define CSN1_UTRAN_FDD_Description_struct_CS_FDD_Indic0_SIZE   1
#define CSN1_UTRAN_TDD_Description_struct_Bandwidth_TDD 386
#define CSN1_UTRAN_TDD_Description_struct_Bandwidth_TDD_SIZE   3
#define CSN1_UTRAN_TDD_Description_struct_CS_TDD_Indic0  39
#define CSN1_UTRAN_TDD_Description_struct_CS_TDD_Indic0_SIZE   1
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1 497
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_1_SIZE   2
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2 498
#define CSN1__8_PSK_Struct__8_PSK_RF_Power_Capability_2_SIZE   2
#define CSN1_Additional_PFCs_struct_DN_NPM_Transfer_Time  85
#define CSN1_Additional_PFCs_struct_DN_NPM_Transfer_Time_SIZE   5
#define CSN1_Additional_PFCs_struct_UP_NPM_Transfer_Time  82
#define CSN1_Additional_PFCs_struct_UP_NPM_Transfer_Time_SIZE   5
#define CSN1_BSIC_Description_struct_BA_Index_Start_BSIC 911
#define CSN1_BSIC_Description_struct_BA_Index_Start_BSIC_SIZE   5
#define CSN1_BSIC_Description_struct_Frequency_Scrolling 915
#define CSN1_BSIC_Description_struct_Frequency_Scrolling_SIZE   1
#define CSN1_CCN_Support_Description_struct_Number_Cells 1264
#define CSN1_CCN_Support_Description_struct_Number_Cells_SIZE   7
#define CSN1_CDMA2000_Description_struct_AUX_PILOT_WALSH 962
#define CSN1_CDMA2000_Description_struct_AUX_PILOT_WALSH_SIZE   0
#define CSN1_CDMA2000_Description_struct_Pilot_PN_offset 944
#define CSN1_CDMA2000_Description_struct_Pilot_PN_offset_SIZE   9
#define CSN1_EC_Downlink_Assignment_message_content_TLLI 649
#define CSN1_EC_Downlink_Assignment_message_content_TLLI_SIZE  32
#define CSN1_EC_System_Information_Type_1_Band_Indicator 627
#define CSN1_EC_System_Information_Type_1_Band_Indicator_SIZE   1
#define CSN1_E_UTRAN_Measurement_Report_struct_N_E_UTRAN 604
#define CSN1_E_UTRAN_Measurement_Report_struct_N_E_UTRAN_SIZE   2
#define CSN1_Fixed_Allocation_struct_TIMESLOT_ALLOCATION 331
#define CSN1_Fixed_Allocation_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_GPRSBCastInfo_GPRS_Power_Control_Parameters 1011
#define CSN1_GPRSBCastInfo_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_GPRS_Support_Indicator_struct_SI13_POSITION 786
#define CSN1_GPRS_Support_Indicator_struct_SI13_POSITION_SIZE   1
#define CSN1_Group_Call_information_Group_Call_Reference 185
#define CSN1_Group_Call_information_Group_Call_Reference_SIZE  36
#define CSN1_Group_Channel_Description_Mobile_Allocation   9
#define CSN1_Group_Channel_Description_Mobile_Allocation_SIZE   0
#define CSN1_IARestOctets_Length_of_frequency_parameters 751
#define CSN1_IARestOctets_Length_of_frequency_parameters_SIZE   6
#define CSN1_IPA_Uplink_Assignment_struct_TFI_ASSIGNMENT 1382
#define CSN1_IPA_Uplink_Assignment_struct_TFI_ASSIGNMENT_SIZE   5
#define CSN1_MBMS_Information_P2_MBMS_Channel_Parameters 1477
#define CSN1_MBMS_Information_P2_MBMS_Channel_Parameters_SIZE   0
#define CSN1_MBMS_Sessions_List_IE_MBMS_Session_Identity 559
#define CSN1_MBMS_Sessions_List_IE_MBMS_Session_Identity_SIZE   8
#define CSN1_MeasurementResults_RXQUAL_FULL_SERVING_CELL 763
#define CSN1_MeasurementResults_RXQUAL_FULL_SERVING_CELL_SIZE   3
#define CSN1_Measurement_information__3G_CSG_Description 1005
#define CSN1_Measurement_information__3G_CSG_Description_SIZE   0
#define CSN1_MultirateSpeechCfgIE_Set_of_AMR_codec_modes 300
#define CSN1_MultirateSpeechCfgIE_Set_of_AMR_codec_modes_SIZE   8
#define CSN1_Network_Sharing_Information_struct_SI22_MCC 448
#define CSN1_Network_Sharing_Information_struct_SI22_MCC_SIZE  12
#define CSN1_Network_Sharing_Information_struct_SI22_MNC 449
#define CSN1_Network_Sharing_Information_struct_SI22_MNC_SIZE  12
#define CSN1_Non_Segmented_SMS_Description_struct_Length 177
#define CSN1_Non_Segmented_SMS_Description_struct_Length_SIZE   8
#define CSN1_Packet_Downlink_Assignment_EVENT_BASED_FANR 729
#define CSN1_Packet_Downlink_Assignment_EVENT_BASED_FANR_SIZE   1
#define CSN1_RRClassmark3Value_DTM_GPRS_Multi_Slot_Class 506
#define CSN1_RRClassmark3Value_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_RRClassmark3Value_High_Multislot_Capability 515
#define CSN1_RRClassmark3Value_High_Multislot_Capability_SIZE   2
#define CSN1_RRClassmark3Value_T_GSM_400_Bands_Supported 521
#define CSN1_RRClassmark3Value_T_GSM_400_Bands_Supported_SIZE   2
#define CSN1_RRPacketUplinkAssignment_Dynamic_Allocation 1207
#define CSN1_RRPacketUplinkAssignment_Dynamic_Allocation_SIZE   0
#define CSN1_RRPacketUplinkAssignment_EMST_NW_Capability 1203
#define CSN1_RRPacketUplinkAssignment_EMST_NW_Capability_SIZE   1
#define CSN1_RRPacketUplinkAssignment_REPORTED_TIMESLOTS 1195
#define CSN1_RRPacketUplinkAssignment_REPORTED_TIMESLOTS_SIZE   8
#define CSN1_RRPacketUplinkAssignment_Uplink_EGPRS_Level 1188
#define CSN1_RRPacketUplinkAssignment_Uplink_EGPRS_Level_SIZE   2
#define CSN1_RRPktDownlinkAssi_MEASUREMENT_STARTING_TIME 1031
#define CSN1_RRPktDownlinkAssi_MEASUREMENT_STARTING_TIME_SIZE  16
#define CSN1_RRPktDownlinkAssi_Measurement_Control_UTRAN 1052
#define CSN1_RRPktDownlinkAssi_Measurement_Control_UTRAN_SIZE   1
#define CSN1_SI2quaterRestOctets_E_UTRAN_CSG_Description 1344
#define CSN1_SI2quaterRestOctets_E_UTRAN_CSG_Description_SIZE   0
#define CSN1_Timeslot_description_struct_USF_GRANULARITY 1162
#define CSN1_Timeslot_description_struct_USF_GRANULARITY_SIZE   1
#define CSN1_UTRAN_CSG_Measurement_Report_IE_Access_Mode 570
#define CSN1_UTRAN_CSG_Measurement_Report_IE_Access_Mode_SIZE   1
#define CSN1_Uplink_TBF_Assignment_struct_USF_ALLOCATION 1181
#define CSN1_Uplink_TBF_Assignment_struct_USF_ALLOCATION_SIZE   3
#define CSN1_Uplink_TBF_Assignment_struct_USF_Assignment 1179
#define CSN1_Uplink_TBF_Assignment_struct_USF_Assignment_SIZE   0
#define CSN1_further_diff_cell_info_cell_reselect_offset 1439
#define CSN1_further_diff_cell_info_cell_reselect_offset_SIZE   6
#define CSN1_CCN_Support_Description_struct_CCN_SUPPORTED 1265
#define CSN1_CCN_Support_Description_struct_CCN_SUPPORTED_SIZE   0
#define CSN1_CDMA2000_Description_struct_AUX_PILOT_WALSH1 953
#define CSN1_CDMA2000_Description_struct_AUX_PILOT_WALSH1_SIZE   0
#define CSN1_CDMA2000_Description_struct_AUX_PILOT_WALSH2 956
#define CSN1_CDMA2000_Description_struct_AUX_PILOT_WALSH2_SIZE   0
#define CSN1_CDMA2000_Description_struct_SR3_PILOT_POWER1 946
#define CSN1_CDMA2000_Description_struct_SR3_PILOT_POWER1_SIZE   3
#define CSN1_CDMA2000_Description_struct_SR3_PILOT_POWER2 947
#define CSN1_CDMA2000_Description_struct_SR3_PILOT_POWER2_SIZE   3
#define CSN1_Channel_Request_Description_IE_LLC__PDU_TYPE 277
#define CSN1_Channel_Request_Description_IE_LLC__PDU_TYPE_SIZE   1
#define CSN1_Downlink_TBF_assignment_2_struct_CONTROL_ACK 348
#define CSN1_Downlink_TBF_assignment_2_struct_CONTROL_ACK_SIZE   1
#define CSN1_EC_Downlink_Allocation_struct_Timing_Advance 652
#define CSN1_EC_Downlink_Allocation_struct_Timing_Advance_SIZE   6
#define CSN1_EC_Fixed_Uplink_Allocation_struct_data_block  23
#define CSN1_EC_Fixed_Uplink_Allocation_struct_data_block_SIZE   0
#define CSN1_EC_Packet_Channel_Description_Type_1_TSC_Set 475
#define CSN1_EC_Packet_Channel_Description_Type_1_TSC_Set_SIZE   1
#define CSN1_EC_Packet_Channel_Description_Type_2_TSC_Set 482
#define CSN1_EC_Packet_Channel_Description_Type_2_TSC_Set_SIZE   1
#define CSN1_EC_System_Information_Type_2_EC_Cell_Options 224
#define CSN1_EC_System_Information_Type_2_EC_Cell_Options_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_RTTI_USF_MODE 687
#define CSN1_EGPRS_Packet_Uplink_Assignment_RTTI_USF_MODE_SIZE   1
#define CSN1_E_UTRAN_CSG_Description_struct_CSG_PCI_SPLIT 1346
#define CSN1_E_UTRAN_CSG_Description_struct_CSG_PCI_SPLIT_SIZE   0
#define CSN1_E_UTRAN_Description_struct_Not_Allowed_Cells 270
#define CSN1_E_UTRAN_Description_struct_Not_Allowed_Cells_SIZE   0
#define CSN1_Extension_Information_REDUCED_LATENCY_ACCESS 894
#define CSN1_Extension_Information_REDUCED_LATENCY_ACCESS_SIZE   1
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability 517
#define CSN1_GERAN_Iu_Mode_Capabilities_FLO_Iu_Capability_SIZE   1
#define CSN1_GPRS_BSIC_Description_struct_Remaining_BSICs 1235
#define CSN1_GPRS_BSIC_Description_struct_Remaining_BSICs_SIZE   0
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_TN 1401
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_TN_SIZE   3
#define CSN1_LA_Different_struct_CELL_RESELECT_HYSTERISIS 412
#define CSN1_LA_Different_struct_CELL_RESELECT_HYSTERISIS_SIZE   3
#define CSN1_MPRACH_Control_Parameters_IE_ACC_CONTR_CLASS 1419
#define CSN1_MPRACH_Control_Parameters_IE_ACC_CONTR_CLASS_SIZE  16
#define CSN1_MPRACH_description_IE_MPRACH_TIMESLOT_NUMBER 1416
#define CSN1_MPRACH_description_IE_MPRACH_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Measurement_information_Short_layer_2_header 897
#define CSN1_Measurement_information_Short_layer_2_header_SIZE   2
#define CSN1_Mobile_Identity_struct_Number_of_IMSI_Digits  26
#define CSN1_Mobile_Identity_struct_Number_of_IMSI_Digits_SIZE   4
#define CSN1_NOTIFICATION_FACCH_BODY_short_layer_2_header 572
#define CSN1_NOTIFICATION_FACCH_BODY_short_layer_2_header_SIZE   2
#define CSN1_Packet_Downlink_Assignment_BTS_PWR_CTRL_MODE 721
#define CSN1_Packet_Downlink_Assignment_BTS_PWR_CTRL_MODE_SIZE   1
#define CSN1_Packet_Downlink_Assignment_EGPRS_Window_Size 723
#define CSN1_Packet_Downlink_Assignment_EGPRS_Window_Size_SIZE   5
#define CSN1_Packet_Downlink_Assignment_NPM_Transfer_Time 727
#define CSN1_Packet_Downlink_Assignment_NPM_Transfer_Time_SIZE   5
#define CSN1_Packet_Downlink_Assignment_TBF_STARTING_TIME 719
#define CSN1_Packet_Downlink_Assignment_TBF_STARTING_TIME_SIZE  16
#define CSN1_RLC_Entity_Struct_DN_DOWNLINK_TFI_ASSIGNMENT 341
#define CSN1_RLC_Entity_Struct_DN_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RRClassmark3Value_DTM_EGPRS_Multi_Slot_Class 508
#define CSN1_RRClassmark3Value_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_RRPacketDownlinkAssignmentType2_RLC_Entity_2 1090
#define CSN1_RRPacketDownlinkAssignmentType2_RLC_Entity_2_SIZE   0
#define CSN1_RRPacketDownlinkAssignmentType2_RLC_Entity_3 1091
#define CSN1_RRPacketDownlinkAssignmentType2_RLC_Entity_3_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_cell 1334
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_cell_SIZE   0
#define CSN1_SI13RestOctets_GPRS_Power_Control_Parameters 1108
#define CSN1_SI13RestOctets_GPRS_Power_Control_Parameters_SIZE  19
#define CSN1_SI2quaterRestOctets__700_REPORTING_THRESHOLD 1296
#define CSN1_SI2quaterRestOctets__700_REPORTING_THRESHOLD_SIZE   3
#define CSN1_SI2quaterRestOctets__810_REPORTING_THRESHOLD 1298
#define CSN1_SI2quaterRestOctets__810_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Segmented_SMS_Description_struct_SMS_Content 175
#define CSN1_Segmented_SMS_Description_struct_SMS_Content_SIZE   0
#define CSN1_VBS_VGCS_RECONFIGURE_BODY_Additional_Segment 160
#define CSN1_VBS_VGCS_RECONFIGURE_BODY_Additional_Segment_SIZE   1
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_filler_bits 167
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_filler_bits_SIZE   3
#define CSN1_BSIC_Description_struct_Number_Remaining_BSIC 913
#define CSN1_BSIC_Description_struct_Number_Remaining_BSIC_SIZE   7
#define CSN1_ChReqDesc2_RLC_Non_persistent_Mode_Capability 281
#define CSN1_ChReqDesc2_RLC_Non_persistent_Mode_Capability_SIZE   1
#define CSN1_Channel_Request_Description_IE_RADIO_PRIORITY 275
#define CSN1_Channel_Request_Description_IE_RADIO_PRIORITY_SIZE   2
#define CSN1_EGPRS_Packet_Uplink_Assignment_Additional_USF 689
#define CSN1_EGPRS_Packet_Uplink_Assignment_Additional_USF_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_TFI_ASSIGNMENT 668
#define CSN1_EGPRS_Packet_Uplink_Assignment_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Enhanced_Measurement_report_Serving_cell_data 590
#define CSN1_Enhanced_Measurement_report_Serving_cell_data_SIZE  23
#define CSN1_Extension_Information_BSS_PAGING_COORDINATION 886
#define CSN1_Extension_Information_BSS_PAGING_COORDINATION_SIZE   1
#define CSN1_Extension_Information_MULTIPLE_TBF_CAPABILITY 889
#define CSN1_Extension_Information_MULTIPLE_TBF_CAPABILITY_SIZE   1
#define CSN1_Fixed_Allocation_struct_UPLINK_TFI_ASSIGNMENT 324
#define CSN1_Fixed_Allocation_struct_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_GPRS_Power_Control_Parameters_IE_PC_MEAS_CHAN 153
#define CSN1_GPRS_Power_Control_Parameters_IE_PC_MEAS_CHAN_SIZE   1
#define CSN1_Group_Channel_Description_Channel_Description   8
#define CSN1_Group_Channel_Description_Channel_Description_SIZE  24
#define CSN1_IPA_Downlink_Assignment_struct_TFI_ASSIGNMENT 1389
#define CSN1_IPA_Downlink_Assignment_struct_TFI_ASSIGNMENT_SIZE   5
#define CSN1_IPA_Uplink_Assignment_struct_Random_Reference 1378
#define CSN1_IPA_Uplink_Assignment_struct_Random_Reference_SIZE  11
#define CSN1_MBMS_Channel_Parameters_IE_MPRACH_description 1414
#define CSN1_MBMS_Channel_Parameters_IE_MPRACH_description_SIZE   0
#define CSN1_Measurement_information__700_REPORTING_OFFSET 977
#define CSN1_Measurement_information__700_REPORTING_OFFSET_SIZE   3
#define CSN1_Measurement_information__810_REPORTING_OFFSET 979
#define CSN1_Measurement_information__810_REPORTING_OFFSET_SIZE   3
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_application_data 181
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_application_data_SIZE  72
#define CSN1_Non_GSM_Message_struct_NR_OF_CONTAINER_OCTETS 425
#define CSN1_Non_GSM_Message_struct_NR_OF_CONTAINER_OCTETS_SIZE   5
#define CSN1_PBCCH_Description_2_struct_PSI1_REPEAT_PERIOD 1374
#define CSN1_PBCCH_Description_2_struct_PSI1_REPEAT_PERIOD_SIZE   4
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_INDEX 129
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE 128
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_Packet_Uplink_Assignment_TIMING_ADVANCE_INDEX 746
#define CSN1_Packet_Uplink_Assignment_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_RRClassmark3Value_DTM_Enhancements_Capability 525
#define CSN1_RRClassmark3Value_DTM_Enhancements_Capability_SIZE   1
#define CSN1_RRClassmark3Value_Extended_EARFCN_value_range 550
#define CSN1_RRClassmark3Value_Extended_EARFCN_value_range_SIZE   1
#define CSN1_RRPktDownlinkAssi_Measurement_Control_E_UTRAN 1050
#define CSN1_RRPktDownlinkAssi_Measurement_Control_E_UTRAN_SIZE   1
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BSIC 599
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BSIC_SIZE   6
#define CSN1_SI10bis_Neighbour_Cell_Info_CELL_GLOBAL_COUNT 463
#define CSN1_SI10bis_Neighbour_Cell_Info_CELL_GLOBAL_COUNT_SIZE   2
#define CSN1_SI2quaterRestOctets_NC_Measurement_Parameters 1257
#define CSN1_SI2quaterRestOctets_NC_Measurement_Parameters_SIZE   0
#define CSN1_SI2quater_Indicator_struct_SI2quater_POSITION 798
#define CSN1_SI2quater_Indicator_struct_SI2quater_POSITION_SIZE   1
#define CSN1_System_Information_21_Indicator_SI21_POSITION 800
#define CSN1_System_Information_21_Indicator_SI21_POSITION_SIZE   1
#define CSN1_UTRAN_FDD_Description_struct_CS_Bandwidth_FDD  32
#define CSN1_UTRAN_FDD_Description_struct_CS_Bandwidth_FDD_SIZE   3
#define CSN1_UTRAN_TDD_Description_struct_CS_Bandwidth_TDD  37
#define CSN1_UTRAN_TDD_Description_struct_CS_Bandwidth_TDD_SIZE   3
#define CSN1_CDMA2000_Description_struct_AUX_TD_POWER_LEVEL 959
#define CSN1_CDMA2000_Description_struct_AUX_TD_POWER_LEVEL_SIZE   2
#define CSN1_CDMA2000_Description_struct_cdma2000_frequency 942
#define CSN1_CDMA2000_Description_struct_cdma2000_frequency_SIZE  11
#define CSN1_COMPACT_Cell_Selection_struct_MS_TXPWR_MAX_CCH 413
#define CSN1_COMPACT_Cell_Selection_struct_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_COMPACT_Cell_Selection_struct_RXLEV_ACCESS_MIN 414
#define CSN1_COMPACT_Cell_Selection_struct_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_COMPACT_Cell_Selection_struct_TEMPORARY_OFFSET 416
#define CSN1_COMPACT_Cell_Selection_struct_TEMPORARY_OFFSET_SIZE   3
#define CSN1_COMPACT_Neighbour_Cell_params_struct_parameter 1131
#define CSN1_COMPACT_Neighbour_Cell_params_struct_parameter_SIZE   0
#define CSN1_Channel_Request_Description_IE_RLC_OCTET_COUNT 278
#define CSN1_Channel_Request_Description_IE_RLC_OCTET_COUNT_SIZE  16
#define CSN1_EC_Fixed_Uplink_Allocation_struct_ALPHA_Enable  19
#define CSN1_EC_Fixed_Uplink_Allocation_struct_ALPHA_Enable_SIZE   1
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Assigned_MCS  17
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Assigned_MCS_SIZE   4
#define CSN1_EC_Packet_Channel_Description_Type_1_spare_bit 478
#define CSN1_EC_Packet_Channel_Description_Type_1_spare_bit_SIZE   1
#define CSN1_EC_System_Information_Type_1_EC_SI_CHANGE_MARK 616
#define CSN1_EC_System_Information_Type_1_EC_SI_CHANGE_MARK_SIZE   5
#define CSN1_EC_System_Information_Type_2_EC_SI_CHANGE_MARK 188
#define CSN1_EC_System_Information_Type_2_EC_SI_CHANGE_MARK_SIZE   5
#define CSN1_EC_System_Information_Type_3_EC_SI_4_Indicator 233
#define CSN1_EC_System_Information_Type_3_EC_SI_4_Indicator_SIZE   1
#define CSN1_EC_System_Information_Type_3_EC_SI_CHANGE_MARK 232
#define CSN1_EC_System_Information_Type_3_EC_SI_CHANGE_MARK_SIZE   5
#define CSN1_EC_System_Information_Type_4_EC_SI_CHANGE_MARK 253
#define CSN1_EC_System_Information_Type_4_EC_SI_CHANGE_MARK_SIZE   5
#define CSN1_EGPRS_Packet_Uplink_Assignment_Additional_USF2 691
#define CSN1_EGPRS_Packet_Uplink_Assignment_Additional_USF2_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_USF_GRANULARITY 676
#define CSN1_EGPRS_Packet_Uplink_Assignment_USF_GRANULARITY_SIZE   1
#define CSN1_Enhanced_Measurement_report_REPORTING_QUANTITY 601
#define CSN1_Enhanced_Measurement_report_REPORTING_QUANTITY_SIZE   6
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_CBQ 779
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_CBQ_SIZE   1
#define CSN1_Group_Channel_Description_Frequency_Short_List  10
#define CSN1_Group_Channel_Description_Frequency_Short_List_SIZE  64
#define CSN1_IAXRestOctets_Compressed_Inter_RAT_HO_INFO_IND 294
#define CSN1_IAXRestOctets_Compressed_Inter_RAT_HO_INFO_IND_SIZE   1
#define CSN1_MPRACH_Control_Parameters_IE_PERSISTENCE_LEVEL 1423
#define CSN1_MPRACH_Control_Parameters_IE_PERSISTENCE_LEVEL_SIZE   4
#define CSN1_Measurement_information_INVALID_BSIC_REPORTING 906
#define CSN1_Measurement_information_INVALID_BSIC_REPORTING_SIZE   1
#define CSN1_NOTIFICATION_FACCH_BODY_Priority_Uplink_Access 579
#define CSN1_NOTIFICATION_FACCH_BODY_Priority_Uplink_Access_SIZE   1
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_MCC 257
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_MCC_SIZE  12
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_MNC 258
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_MNC_SIZE  12
#define CSN1_Network_Sharing_Information_struct_SI22_PS_ACC 452
#define CSN1_Network_Sharing_Information_struct_SI22_PS_ACC_SIZE  16
#define CSN1_RRClassmark3Value_GMSK_Multislot_Power_Profile 519
#define CSN1_RRClassmark3Value_GMSK_Multislot_Power_Profile_SIZE   2
#define CSN1_RRPacketUplinkAssignment_Packet_Timing_Advance 1155
#define CSN1_RRPacketUplinkAssignment_Packet_Timing_Advance_SIZE   0
#define CSN1_RRPacketUplinkAssignment_UTRAN_FREQUENCY_INDEX 1200
#define CSN1_RRPacketUplinkAssignment_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_EARFCN 1335
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_EARFCN_SIZE  16
#define CSN1_SI2_UTRAN_FDD_Description_struct_Bandwidth_FDD 364
#define CSN1_SI2_UTRAN_FDD_Description_struct_Bandwidth_FDD_SIZE   3
#define CSN1_SI2_UTRAN_TDD_Description_struct_Bandwidth_TDD 371
#define CSN1_SI2_UTRAN_TDD_Description_struct_Bandwidth_TDD_SIZE   3
#define CSN1_Single_Block_Allocation_struct_TIMESLOT_NUMBER 1210
#define CSN1_Single_Block_Allocation_struct_TIMESLOT_NUMBER_SIZE   3
#define CSN1_UTRAN_FDD_TDD_Description_struct_Bandwidth_FDD 827
#define CSN1_UTRAN_FDD_TDD_Description_struct_Bandwidth_FDD_SIZE   3
#define CSN1_UTRAN_FDD_TDD_Description_struct_Bandwidth_TDD 828
#define CSN1_UTRAN_FDD_TDD_Description_struct_Bandwidth_TDD_SIZE   3
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Window_Size 1178
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_VBS_VGCS_RECONFIGURE_BODY_short_layer_2_header 155
#define CSN1_VBS_VGCS_RECONFIGURE_BODY_short_layer_2_header_SIZE   2
#define CSN1_VGCS_SMS_INFORMATION_BODY_short_layer_2_header 169
#define CSN1_VGCS_SMS_INFORMATION_BODY_short_layer_2_header_SIZE   2
#define CSN1_Additional_PFCs_struct_UP_UPLINK_TFI_ASSIGNMENT  81
#define CSN1_Additional_PFCs_struct_UP_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_Direct_encoding_1_struct_GPRS_Mobile_Allocation 1141
#define CSN1_Direct_encoding_1_struct_GPRS_Mobile_Allocation_SIZE   0
#define CSN1_Downlink_TBF_assignment_2_struct_TFI_Assignment 347
#define CSN1_Downlink_TBF_assignment_2_struct_TFI_Assignment_SIZE   5
#define CSN1_Dynamic_Allocation_struct_UPLINK_TFI_ASSIGNMENT  62
#define CSN1_Dynamic_Allocation_struct_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_EC_Dummy_message_content_Used_DL_Coverage_Class 641
#define CSN1_EC_Dummy_message_content_Used_DL_Coverage_Class_SIZE   2
#define CSN1_ETWS_Primary_Notification_struct_Segment_Number 1459
#define CSN1_ETWS_Primary_Notification_struct_Segment_Number_SIZE   4
#define CSN1_E_UTRAN_CSG_Description_struct_RR_CSG_PCI_SPLIT 1003
#define CSN1_E_UTRAN_CSG_Description_struct_RR_CSG_PCI_SPLIT_SIZE   0
#define CSN1_E_UTRAN_Measurement_Report_struct_CELL_IDENTITY 606
#define CSN1_E_UTRAN_Measurement_Report_struct_CELL_IDENTITY_SIZE   9
#define CSN1_Fixed_Allocation_struct_BLOCKS_OR_BLOCK_PERIODS 333
#define CSN1_Fixed_Allocation_struct_BLOCKS_OR_BLOCK_PERIODS_SIZE   1
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_BSIC 774
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_BSIC_SIZE   6
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_GAMMA 1398
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_GAMMA_SIZE   5
#define CSN1_MPRACH_description_IE_MPRACH_Control_Parameters 1418
#define CSN1_MPRACH_description_IE_MPRACH_Control_Parameters_SIZE   0
#define CSN1_MeasurementResults_UTRAN_CSG_Measurement_Report 767
#define CSN1_MeasurementResults_UTRAN_CSG_Measurement_Report_SIZE   0
#define CSN1_Measurement_information_E_UTRAN_CSG_Description 1002
#define CSN1_Measurement_information_E_UTRAN_CSG_Description_SIZE   0
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_TMGI 705
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_TMGI_SIZE   0
#define CSN1_Packet_Downlink_Assignment_Downlink_EGPRS_Level 731
#define CSN1_Packet_Downlink_Assignment_Downlink_EGPRS_Level_SIZE   2
#define CSN1_Packet_Downlink_Assignment_PDCH_PAIR_INDICATION 730
#define CSN1_Packet_Downlink_Assignment_PDCH_PAIR_INDICATION_SIZE   3
#define CSN1_Packet_Downlink_Assignment_TIMING_ADVANCE_INDEX 718
#define CSN1_Packet_Downlink_Assignment_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_Packet_Uplink_Assignment_CHANNEL_CODING_COMMAND 742
#define CSN1_Packet_Uplink_Assignment_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_REPORT_PRIORITY_Description_struct_Number_Cells 917
#define CSN1_REPORT_PRIORITY_Description_struct_Number_Cells_SIZE   7
#define CSN1_REPORT_PRIORITY_Description_struct_REP_PRIORITY 918
#define CSN1_REPORT_PRIORITY_Description_struct_REP_PRIORITY_SIZE   0
#define CSN1_RRClassmark3Value_Associated_Radio_Capability_1 487
#define CSN1_RRClassmark3Value_Associated_Radio_Capability_1_SIZE   4
#define CSN1_RRClassmark3Value_Associated_Radio_Capability_2 486
#define CSN1_RRClassmark3Value_Associated_Radio_Capability_2_SIZE   4
#define CSN1_RRClassmark3Value_GERAN_Network_Sharing_support 544
#define CSN1_RRClassmark3Value_GERAN_Network_Sharing_support_SIZE   1
#define CSN1_RRPacketUplinkAssignment_CHANNEL_CODING_COMMAND 1153
#define CSN1_RRPacketUplinkAssignment_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_RRPacketUplinkAssignment_EMSR_Additional_PFCs_1 1204
#define CSN1_RRPacketUplinkAssignment_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_RRPacketUplinkAssignment_EMSR_Additional_PFCs_2 1205
#define CSN1_RRPacketUplinkAssignment_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_RRPacketUplinkAssignment_EMSR_Additional_PFCs_3 1206
#define CSN1_RRPacketUplinkAssignment_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_RRPktDownlinkAssi_LINK_QUALITY_MEASUREMENT_MODE 1035
#define CSN1_RRPktDownlinkAssi_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_SI2_UTRAN_TDD_Description_struct_Cell_Parameter 367
#define CSN1_SI2_UTRAN_TDD_Description_struct_Cell_Parameter_SIZE   7
#define CSN1_Segmented_SMS_Description_struct_Segment_Number 172
#define CSN1_Segmented_SMS_Description_struct_Segment_Number_SIZE   4
#define CSN1_Short_RACH_Control_Parameters_struct_Tx_integer 220
#define CSN1_Short_RACH_Control_Parameters_struct_Tx_integer_SIZE   4
#define CSN1_UTRAN_FDD_Description_struct_CS_NR_OF_FDD_CELLS  35
#define CSN1_UTRAN_FDD_Description_struct_CS_NR_OF_FDD_CELLS_SIZE   5
#define CSN1_UTRAN_TDD_Description_struct_CS_NR_OF_TDD_CELLS  40
#define CSN1_UTRAN_TDD_Description_struct_CS_NR_OF_TDD_CELLS_SIZE   5
#define CSN1_new_Group_Channel_Description_Mobile_Allocation 157
#define CSN1_new_Group_Channel_Description_Mobile_Allocation_SIZE   1
#define CSN1_Coverage_Class_Selection_Parameters_struct_BSPWR 206
#define CSN1_Coverage_Class_Selection_Parameters_struct_BSPWR_SIZE   6
#define CSN1_Downlink_TBF_assignment_struct_EGPRS_Window_Size 1045
#define CSN1_Downlink_TBF_assignment_struct_EGPRS_Window_Size_SIZE   5
#define CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class 495
#define CSN1_ECSD_Multi_Slot_Capability_ECSD_Multi_Slot_Class_SIZE   5
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Timing_Advance  12
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Timing_Advance_SIZE   6
#define CSN1_EC_RACH_Control_Parameters_struct_EC_Max_Retrans 209
#define CSN1_EC_RACH_Control_Parameters_struct_EC_Max_Retrans_SIZE   2
#define CSN1_EC_Request_Reference_Description_Last_TDMA_Frame 120
#define CSN1_EC_Request_Reference_Description_Last_TDMA_Frame_SIZE  10
#define CSN1_EGPRS_Packet_Uplink_Assignment_ALLOCATION_BITMAP 671
#define CSN1_EGPRS_Packet_Uplink_Assignment_ALLOCATION_BITMAP_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_BTS_PWR_CTRL_MODE 673
#define CSN1_EGPRS_Packet_Uplink_Assignment_BTS_PWR_CTRL_MODE_SIZE   1
#define CSN1_EGPRS_Packet_Uplink_Assignment_EGPRS_Window_Size 682
#define CSN1_EGPRS_Packet_Uplink_Assignment_EGPRS_Window_Size_SIZE   5
#define CSN1_EGPRS_Packet_Uplink_Assignment_TBF_STARTING_TIME 686
#define CSN1_EGPRS_Packet_Uplink_Assignment_TBF_STARTING_TIME_SIZE  16
#define CSN1_E_UTRAN_Description_struct_Measurement_Bandwidth 269
#define CSN1_E_UTRAN_Description_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_Enhanced_Measurement_report_Short_layer_2_header 585
#define CSN1_Enhanced_Measurement_report_Short_layer_2_header_SIZE   2
#define CSN1_Fixed_Allocation_struct_ALLOCATION_BITMAP_LENGTH 334
#define CSN1_Fixed_Allocation_struct_ALLOCATION_BITMAP_LENGTH_SIZE   7
#define CSN1_Fixed_Allocation_struct_Power_Control_Parameters 330
#define CSN1_Fixed_Allocation_struct_Power_Control_Parameters_SIZE   0
#define CSN1_GPRS_BSIC_Description_struct_BA_Index_Start_BSIC 1232
#define CSN1_GPRS_BSIC_Description_struct_BA_Index_Start_BSIC_SIZE   5
#define CSN1_GPRS_BSIC_Description_struct_Frequency_Scrolling 1236
#define CSN1_GPRS_BSIC_Description_struct_Frequency_Scrolling_SIZE   1
#define CSN1_GPRS_Real_Time_Difference_Description_struct_RTD 1230
#define CSN1_GPRS_Real_Time_Difference_Description_struct_RTD_SIZE   0
#define CSN1_Measurement_information__700_REPORTING_THRESHOLD 978
#define CSN1_Measurement_information__700_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Measurement_information__810_REPORTING_THRESHOLD 980
#define CSN1_Measurement_information__810_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_ALPHA 703
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_ALPHA_SIZE   4
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_GAMMA 704
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_GAMMA_SIZE   5
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_MS_ID 701
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_MS_ID_SIZE   0
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap 1192
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap_SIZE   0
#define CSN1_RRClassmark3Value_DTM_GPRS_High_Multi_Slot_Class 526
#define CSN1_RRClassmark3Value_DTM_GPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_RRClassmark3Value__8_PSK_Multislot_Power_Profile 520
#define CSN1_RRClassmark3Value__8_PSK_Multislot_Power_Profile_SIZE   2
#define CSN1_RRPacketUplinkAssignment_E_UTRAN_FREQUENCY_INDEX 1198
#define CSN1_RRPacketUplinkAssignment_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_RRPacketUplinkAssignment_Multiple_TBF_Allocation 1156
#define CSN1_RRPacketUplinkAssignment_Multiple_TBF_Allocation_SIZE   0
#define CSN1_RRPacketUplinkAssignment_Single_Block_Allocation 1209
#define CSN1_RRPacketUplinkAssignment_Single_Block_Allocation_SIZE   0
#define CSN1_R_Support_R_GSM_band_Associated_Radio_Capability 488
#define CSN1_R_Support_R_GSM_band_Associated_Radio_Capability_SIZE   3
#define CSN1_SI10bis_Neighbour_Cell_Info_Frequency_Short_List 461
#define CSN1_SI10bis_Neighbour_Cell_Info_Frequency_Short_List_SIZE  64
#define CSN1_SI14RestOctets_DYNAMIC_ARFCN_MAPPING_Description 430
#define CSN1_SI14RestOctets_DYNAMIC_ARFCN_MAPPING_Description_SIZE   0
#define CSN1_SI15RestOctets_DYNAMIC_ARFCN_MAPPING_Description 434
#define CSN1_SI15RestOctets_DYNAMIC_ARFCN_MAPPING_Description_SIZE   0
#define CSN1_SI19RestOctets_COMPACT_Neighbour_Cell_Parameters 1130
#define CSN1_SI19RestOctets_COMPACT_Neighbour_Cell_Parameters_SIZE   0
#define CSN1_SI23RestOctets_IRAT_Cell_Reselection_Information 1366
#define CSN1_SI23RestOctets_IRAT_Cell_Reselection_Information_SIZE   0
#define CSN1_SI2_UTRAN_FDD_Description_struct_FDD_ARFCN_INDEX 359
#define CSN1_SI2_UTRAN_FDD_Description_struct_FDD_ARFCN_INDEX_SIZE   3
#define CSN1_SI2_UTRAN_FDD_Description_struct_Scrambling_Code 360
#define CSN1_SI2_UTRAN_FDD_Description_struct_Scrambling_Code_SIZE   9
#define CSN1_SI2_UTRAN_TDD_Description_struct_TDD_ARFCN_INDEX 366
#define CSN1_SI2_UTRAN_TDD_Description_struct_TDD_ARFCN_INDEX_SIZE   3
#define CSN1_SI2quaterRestOctets_Extended_EARFCNs_Description 1358
#define CSN1_SI2quaterRestOctets_Extended_EARFCNs_Description_SIZE   0
#define CSN1_Short_RACH_Control_Parameters_struct_Max_Retrans 219
#define CSN1_Short_RACH_Control_Parameters_struct_Max_Retrans_SIZE   2
#define CSN1_Single_Block_Allocation_struct_TBF_Starting_Time 1215
#define CSN1_Single_Block_Allocation_struct_TBF_Starting_Time_SIZE   0
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_talker_identity 168
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_talker_identity_SIZE   0
#define CSN1__3G_CSG_Description_struct_UTRAN_FREQUENCY_INDEX 402
#define CSN1__3G_CSG_Description_struct_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_Additional_PFCs_struct_DN_DOWNLINK_TFI_ASSIGNMENT  84
#define CSN1_Additional_PFCs_struct_DN_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_CDMA2000_Description_struct_number_cdma2000_cells 943
#define CSN1_CDMA2000_Description_struct_number_cdma2000_cells_SIZE   5
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_GSM_Description 664
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_GSM_Description_SIZE  17
#define CSN1_Downlink_TBF_assignment_2_struct_EVENT_BASED_FANR 350
#define CSN1_Downlink_TBF_assignment_2_struct_EVENT_BASED_FANR_SIZE   1
#define CSN1_Dynamic_Allocation_struct_RLC_DATA_BLOCKS_GRANTED  63
#define CSN1_Dynamic_Allocation_struct_RLC_DATA_BLOCKS_GRANTED_SIZE   8
#define CSN1_EC_Cell_Channel_Description_struct_NumberOfOctets 618
#define CSN1_EC_Cell_Channel_Description_struct_NumberOfOctets_SIZE   5
#define CSN1_EC_Cell_Selection_Parameters_struct_Cell_Identity 192
#define CSN1_EC_Cell_Selection_Parameters_struct_Cell_Identity_SIZE  16
#define CSN1_EC_Packet_Channel_Description_Type_1_EC_MA_NUMBER 477
#define CSN1_EC_Packet_Channel_Description_Type_1_EC_MA_NUMBER_SIZE   5
#define CSN1_EC_Packet_Channel_Description_Type_2_EC_MA_NUMBER 484
#define CSN1_EC_Packet_Channel_Description_Type_2_EC_MA_NUMBER_SIZE   5
#define CSN1_EC_RACH_Control_Parameters_struct_Cell_Bar_Access 214
#define CSN1_EC_RACH_Control_Parameters_struct_Cell_Bar_Access_SIZE   1
#define CSN1_EGPRS_Packet_Uplink_Assignment_REPORTED_TIMESLOTS 692
#define CSN1_EGPRS_Packet_Uplink_Assignment_REPORTED_TIMESLOTS_SIZE   8
#define CSN1_Extension_Information_DTM_ENHANCEMENTS_CAPABILITY 891
#define CSN1_Extension_Information_DTM_ENHANCEMENTS_CAPABILITY_SIZE   1
#define CSN1_Fixed_Allocation_struct_DOWNLINK_CONTROL_TIMESLOT 326
#define CSN1_Fixed_Allocation_struct_DOWNLINK_CONTROL_TIMESLOT_SIZE   3
#define CSN1_IPA_Uplink_Assignment_struct_Frequency_Parameters 1387
#define CSN1_IPA_Uplink_Assignment_struct_Frequency_Parameters_SIZE   0
#define CSN1_IPA_Uplink_Assignment_struct_TIMING_ADVANCE_VALUE 1381
#define CSN1_IPA_Uplink_Assignment_struct_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_MBMS_Session_Parameters_List_IE_EGPRS_Window_Size 1412
#define CSN1_MBMS_Session_Parameters_List_IE_EGPRS_Window_Size_SIZE   5
#define CSN1_MBMS_Session_Parameters_List_IE_NPM_Transfer_Time 1413
#define CSN1_MBMS_Session_Parameters_List_IE_NPM_Transfer_Time_SIZE   5
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_short_layer_2_header 180
#define CSN1_NOTIFY_APPLICATION_DATA_BODY_short_layer_2_header_SIZE   2
#define CSN1_Packet_Uplink_Assignment_ALLOCATION_BITMAP_LENGTH 735
#define CSN1_Packet_Uplink_Assignment_ALLOCATION_BITMAP_LENGTH_SIZE   5
#define CSN1_RRClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class 528
#define CSN1_RRClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class_SIZE   3
#define CSN1_RRClassmark3Value_Extended_Measurement_Capability 491
#define CSN1_RRClassmark3Value_Extended_Measurement_Capability_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_EGPRS_Window_Size 1067
#define CSN1_RRPacketDownlinkAssignmentType2_EGPRS_Window_Size_SIZE   5
#define CSN1_RRPktDownlinkAssi_Packet_Extended_Ttiming_Advance 1036
#define CSN1_RRPktDownlinkAssi_Packet_Extended_Ttiming_Advance_SIZE   2
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_RR_EARFCN 994
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_RR_EARFCN_SIZE  16
#define CSN1_SYSTEM_INFORMATION_TYPE_10ter_SI10ter_Rest_Octets   6
#define CSN1_SYSTEM_INFORMATION_TYPE_10ter_SI10ter_Rest_Octets_SIZE  32
#define CSN1__3G_Neighbour_Cell_Description_struct_RR__3G_Wait 935
#define CSN1__3G_Neighbour_Cell_Description_struct_RR__3G_Wait_SIZE   3
#define CSN1_new_Group_Channel_Description_Channel_Description 156
#define CSN1_new_Group_Channel_Description_Channel_Description_SIZE  24
#define CSN1_COMPACT_Cell_Selection_struct_CELL_RESELECT_OFFSET 415
#define CSN1_COMPACT_Cell_Selection_struct_CELL_RESELECT_OFFSET_SIZE   6
#define CSN1_Downlink_TBF_assignment_2_struct_NPM_Transfer_Time 349
#define CSN1_Downlink_TBF_assignment_2_struct_NPM_Transfer_Time_SIZE   5
#define CSN1_EC_Cell_Reselection_Parameters_struct_C1_DELTA_MAX 238
#define CSN1_EC_Cell_Reselection_Parameters_struct_C1_DELTA_MAX_SIZE   3
#define CSN1_EC_Cell_Reselection_Parameters_struct_C1_DELTA_MIN 237
#define CSN1_EC_Cell_Reselection_Parameters_struct_C1_DELTA_MIN_SIZE   2
#define CSN1_EC_Cell_Selection_Parameters_struct_EC_BS_CC_CHANS 193
#define CSN1_EC_Cell_Selection_Parameters_struct_EC_BS_CC_CHANS_SIZE   2
#define CSN1_EC_Downlink_Allocation_struct_STARTING_DL_TIMESLOT 653
#define CSN1_EC_Downlink_Allocation_struct_STARTING_DL_TIMESLOT_SIZE   3
#define CSN1_EC_RACH_Control_Parameters_struct_Access_Timeslots 212
#define CSN1_EC_RACH_Control_Parameters_struct_Access_Timeslots_SIZE   1
#define CSN1_ETWS_Primary_Notification_struct_Length_Of_Segment 1461
#define CSN1_ETWS_Primary_Notification_struct_Length_Of_Segment_SIZE   7
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_Stop 1321
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_Stop_SIZE   1
#define CSN1_GPRS_BSIC_Description_struct_Number_Remaining_BSIC 1234
#define CSN1_GPRS_BSIC_Description_struct_Number_Remaining_BSIC_SIZE   7
#define CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class 489
#define CSN1_HSCSD_Multi_Slot_Capability_HSCSD_Multi_Slot_Class_SIZE   5
#define CSN1_NC_Measurement_Parameters_struct_NC_NON_DRX_PERIOD 1259
#define CSN1_NC_Measurement_Parameters_struct_NC_NON_DRX_PERIOD_SIZE   3
#define CSN1_NOTIFICATION_FACCH_BODY_SMS_Guaranteed_Privacy_Ind 584
#define CSN1_NOTIFICATION_FACCH_BODY_SMS_Guaranteed_Privacy_Ind_SIZE   1
#define CSN1_Packet_Uplink_Assignment_TLLI_BLOCK_CHANNEL_CODING 743
#define CSN1_Packet_Uplink_Assignment_TLLI_BLOCK_CHANNEL_CODING_SIZE   1
#define CSN1_RRPacketUplinkAssignment_Measurement_Control_UTRAN 1199
#define CSN1_RRPacketUplinkAssignment_Measurement_Control_UTRAN_SIZE   1
#define CSN1_RRPacketUplinkAssignment_TLLI_BLOCK_CHANNEL_CODING 1154
#define CSN1_RRPacketUplinkAssignment_TLLI_BLOCK_CHANNEL_CODING_SIZE   1
#define CSN1_RRPktDownlinkAssi_Multiple_Downlink_TBF_Assignment 1037
#define CSN1_RRPktDownlinkAssi_Multiple_Downlink_TBF_Assignment_SIZE   0
#define CSN1_Real_Time_Difference_Description_struct_RTD_Struct 909
#define CSN1_Real_Time_Difference_Description_struct_RTD_Struct_SIZE   0
#define CSN1_SI10bis_Neighbour_Cell_Info_Priority_Uplink_access 465
#define CSN1_SI10bis_Neighbour_Cell_Info_Priority_Uplink_access_SIZE   1
#define CSN1_SI2q_Extension_Information_CCN_Support_Description 1263
#define CSN1_SI2q_Extension_Information_CCN_Support_Description_SIZE   0
#define CSN1_SI2quaterRestOctets_p3G_Neighbour_Cell_Description 1266
#define CSN1_SI2quaterRestOctets_p3G_Neighbour_Cell_Description_SIZE   0
#define CSN1_SYSTEM_INFORMATION_TYPE_10ter_short_layer_2_header   4
#define CSN1_SYSTEM_INFORMATION_TYPE_10ter_short_layer_2_header_SIZE   2
#define CSN1_Segmented_SMS_Description_struct_SMS_Final_Content 174
#define CSN1_Segmented_SMS_Description_struct_SMS_Final_Content_SIZE   0
#define CSN1_UTRAN_CSG_Measurement_Report_IE_REPORTING_QUANTITY 571
#define CSN1_UTRAN_CSG_Measurement_Report_IE_REPORTING_QUANTITY_SIZE   6
#define CSN1_Uplink_TBF_Assignment_struct_UPLINK_TFI_ASSIGNMENT 1174
#define CSN1_Uplink_TBF_Assignment_struct_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_new_Group_Channel_Description_Frequency_Short_List 158
#define CSN1_new_Group_Channel_Description_Frequency_Short_List_SIZE  64
#define CSN1_CDMA2000_Description_struct_cdma2000_frequency_band 941
#define CSN1_CDMA2000_Description_struct_cdma2000_frequency_band_SIZE   5
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQUENCY_DIFF 1137
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQUENCY_DIFF_SIZE   0
#define CSN1_Direct_encoding_2_struct_MA_Frequency_List_contents 1151
#define CSN1_Direct_encoding_2_struct_MA_Frequency_List_contents_SIZE   0
#define CSN1_EC_Downlink_Allocation_struct_TIMESLOT_MULIPLICATOR 655
#define CSN1_EC_Downlink_Allocation_struct_TIMESLOT_MULIPLICATOR_SIZE   2
#define CSN1_EC_Downlink_Assignment_message_content_Message_Type 646
#define CSN1_EC_Downlink_Assignment_message_content_Message_Type_SIZE   4
#define CSN1_EC_Neighbour_Cell_Description_struct_NumberOfOctets 240
#define CSN1_EC_Neighbour_Cell_Description_struct_NumberOfOctets_SIZE   5
#define CSN1_EC_Paging_Request_message_content_EC_Page_Extension 643
#define CSN1_EC_Paging_Request_message_content_EC_Page_Extension_SIZE   4
#define CSN1_EC_Paging_Request_message_content_Mobile_Identity_1 644
#define CSN1_EC_Paging_Request_message_content_Mobile_Identity_1_SIZE   0
#define CSN1_EC_Paging_Request_message_content_Mobile_Identity_2 645
#define CSN1_EC_Paging_Request_message_content_Mobile_Identity_2_SIZE   0
#define CSN1_EC_Request_Reference_Description_Echoed_Random_Bits 121
#define CSN1_EC_Request_Reference_Description_Echoed_Random_Bits_SIZE   3
#define CSN1_EGPRS_Packet_Uplink_Assignment_PDCH_PAIR_INDICATION 688
#define CSN1_EGPRS_Packet_Uplink_Assignment_PDCH_PAIR_INDICATION_SIZE   3
#define CSN1_EGPRS_Packet_Uplink_Assignment_TIMING_ADVANCE_INDEX 685
#define CSN1_EGPRS_Packet_Uplink_Assignment_TIMING_ADVANCE_INDEX_SIZE   4
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_Start 1320
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_Start_SIZE   1
#define CSN1_Extended_EARFCNs_Description_struct_EARFCN_extended 1359
#define CSN1_Extended_EARFCNs_Description_struct_EARFCN_extended_SIZE  18
#define CSN1_Extension_Information_EGPRS_PACKET__CHANNEL_REQUEST 882
#define CSN1_Extension_Information_EGPRS_PACKET__CHANNEL_REQUEST_SIZE   1
#define CSN1_IPA_Downlink_Assignment_struct_Frequency_Parameters 1395
#define CSN1_IPA_Downlink_Assignment_struct_Frequency_Parameters_SIZE   0
#define CSN1_IPA_Downlink_Assignment_struct_TIMING_ADVANCE_VALUE 1391
#define CSN1_IPA_Downlink_Assignment_struct_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_FN_OFFSET 1397
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_FN_OFFSET_SIZE   8
#define CSN1_IRAT_Cell_Reselection_Information_struct_PLMN_index 1370
#define CSN1_IRAT_Cell_Reselection_Information_struct_PLMN_index_SIZE   2
#define CSN1_Measurement_information_REPORT_PRIORITY_Description 916
#define CSN1_Measurement_information_REPORT_PRIORITY_Description_SIZE   0
#define CSN1_Multiple_TBF_Allocation_struct_Timeslot_description 1160
#define CSN1_Multiple_TBF_Allocation_struct_Timeslot_description_SIZE   0
#define CSN1_RRClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA 542
#define CSN1_RRClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA_SIZE   2
#define CSN1_RRClassmark3Value_Ciphering_Mode_Setting_Capability 532
#define CSN1_RRClassmark3Value_Ciphering_Mode_Setting_Capability_SIZE   1
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_ARFCN 382
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_ARFCN_SIZE  14
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_ARFCN 388
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_ARFCN_SIZE  14
#define CSN1_SI2quaterRestOctets_CSG_Cells_Reporting_Description 1350
#define CSN1_SI2quaterRestOctets_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_Uplink_TBF_Assignment_struct_CHANNEL_CODING_COMMAND 1175
#define CSN1_Uplink_TBF_Assignment_struct_CHANNEL_CODING_COMMAND_SIZE   2
#define CSN1_VGCS_SMS_INFORMATION_BODY_Segmented_SMS_Description 170
#define CSN1_VGCS_SMS_INFORMATION_BODY_Segmented_SMS_Description_SIZE   0
#define CSN1_COMPACT_Cell_Selection_struct_GUAR_CONSTANT_PWR_BLKS 419
#define CSN1_COMPACT_Cell_Selection_struct_GUAR_CONSTANT_PWR_BLKS_SIZE   2
#define CSN1_COMPACT_Neighbour_Cell_params_struct_START_FREQUENCY 1132
#define CSN1_COMPACT_Neighbour_Cell_params_struct_START_FREQUENCY_SIZE  10
#define CSN1_Channel_Request_Description_IE_PEAK_THROUGHPUT_CLASS 274
#define CSN1_Channel_Request_Description_IE_PEAK_THROUGHPUT_CLASS_SIZE   4
#define CSN1_EC_Cell_Selection_Parameters_struct_MS_TXPWR_MAX_CCH 195
#define CSN1_EC_Cell_Selection_Parameters_struct_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_EC_Fixed_Uplink_Allocation_struct_OVERLAID_CDMA_CODE  16
#define CSN1_EC_Fixed_Uplink_Allocation_struct_OVERLAID_CDMA_CODE_SIZE   2
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_BSIC 244
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_BSIC_SIZE   6
#define CSN1_E_UTRAN_Measurement_Report_struct_REPORTING_QUANTITY 607
#define CSN1_E_UTRAN_Measurement_Report_struct_REPORTING_QUANTITY_SIZE   6
#define CSN1_GPRS_REPORT_PRIORITY_Description_struct_Number_Cells 1238
#define CSN1_GPRS_REPORT_PRIORITY_Description_struct_Number_Cells_SIZE   7
#define CSN1_GPRS_REPORT_PRIORITY_Description_struct_REP_PRIORITY 1239
#define CSN1_GPRS_REPORT_PRIORITY_Description_struct_REP_PRIORITY_SIZE   0
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Bearer_Identity 1409
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Bearer_Identity_SIZE   0
#define CSN1_Multiple_TBF_Allocation_struct_Uplink_TBF_Assignment 1171
#define CSN1_Multiple_TBF_Allocation_struct_Uplink_TBF_Assignment_SIZE   0
#define CSN1_NOTIFICATION_FACCH_BODY_SMS_Data_Confidentiality_Ind 583
#define CSN1_NOTIFICATION_FACCH_BODY_SMS_Data_Confidentiality_Ind_SIZE   1
#define CSN1_RRClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class 513
#define CSN1_RRClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class_SIZE   2
#define CSN1_RRClassmark3Value_Priority_based_reselection_support 537
#define CSN1_RRClassmark3Value_Priority_based_reselection_support_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_Downlink_EGPRS_Level 1085
#define CSN1_RRPacketDownlinkAssignmentType2_Downlink_EGPRS_Level_SIZE   2
#define CSN1_RRPacketDownlinkAssignmentType2_UPLINK_PDCH_PAIRS_C1 1071
#define CSN1_RRPacketDownlinkAssignmentType2_UPLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_RRPacketDownlinkAssignmentType2_UPLINK_PDCH_PAIRS_C2 1072
#define CSN1_RRPacketDownlinkAssignmentType2_UPLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_RRPacketUplinkAssignment_Measurement_Control_E_UTRAN 1197
#define CSN1_RRPacketUplinkAssignment_Measurement_Control_E_UTRAN_SIZE   1
#define CSN1_Repeated_Invalid_BSIC_Information_struct_RXLEV_NCELL 600
#define CSN1_Repeated_Invalid_BSIC_Information_struct_RXLEV_NCELL_SIZE   6
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_Indic0 383
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_Indic0_SIZE   1
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_Indic0 390
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_Indic0_SIZE   1
#define CSN1_SI2quaterRestOctets_GPRS_REPORT_PRIORITY_Description 1237
#define CSN1_SI2quaterRestOctets_GPRS_REPORT_PRIORITY_Description_SIZE   0
#define CSN1_SYSTEM_INFORMATION_TYPE_10_BODY_short_layer_2_header 1424
#define CSN1_SYSTEM_INFORMATION_TYPE_10_BODY_short_layer_2_header_SIZE   2
#define CSN1_Short_RACH_Control_Parameters_struct_Cell_Bar_Access 221
#define CSN1_Short_RACH_Control_Parameters_struct_Cell_Bar_Access_SIZE   1
#define CSN1_VGCSCipheringParameters_Location_Area_Identification 118
#define CSN1_VGCSCipheringParameters_Location_Area_Identification_SIZE  32
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Ignore 1654
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Ignore_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_Index_Start_3G 1267
#define CSN1__3G_Neighbour_Cell_Description_struct_Index_Start_3G_SIZE   7
#define CSN1_COMPACT_Cell_Selection_struct_LA_Different_parameters 411
#define CSN1_COMPACT_Cell_Selection_struct_LA_Different_parameters_SIZE   0
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH 1135
#define CSN1_COMPACT_Neighbour_Cell_params_struct_FREQ_DIFF_LENGTH_SIZE   3
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_E_UTRAN_Description 661
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_E_UTRAN_Description_SIZE   0
#define CSN1_DynamicARFCNMapping_DYNAMIC_ARFCN_MAPPING_Description 293
#define CSN1_DynamicARFCNMapping_DYNAMIC_ARFCN_MAPPING_Description_SIZE   0
#define CSN1_Dynamic_Allocation_struct_Extended_Dynamic_Allocation  58
#define CSN1_Dynamic_Allocation_struct_Extended_Dynamic_Allocation_SIZE   1
#define CSN1_EC_Cell_Selection_Parameters_struct_Routing_Area_Code 191
#define CSN1_EC_Cell_Selection_Parameters_struct_Routing_Area_Code_SIZE   8
#define CSN1_EC_Downlink_Allocation_struct_Downlink_TFI_Assignment 654
#define CSN1_EC_Downlink_Allocation_struct_Downlink_TFI_Assignment_SIZE   5
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Stop 991
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Stop_SIZE   1
#define CSN1_GPRS_Support_Indicator_struct_SAME_RA_AS_SERVING_CELL 785
#define CSN1_GPRS_Support_Indicator_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_MEASUREMENT_PARAMETERS_Description_Struct_REPORT_TYPE 1226
#define CSN1_MEASUREMENT_PARAMETERS_Description_Struct_REPORT_TYPE_SIZE   1
#define CSN1_Network_Sharing_Information_struct_SI22_NCC_Permitted 450
#define CSN1_Network_Sharing_Information_struct_SI22_NCC_Permitted_SIZE   8
#define CSN1_Non_GSM_Message_struct_Non_GSM_Protocol_Discriminator 424
#define CSN1_Non_GSM_Message_struct_Non_GSM_Protocol_Discriminator_SIZE   3
#define CSN1_RRClassmark3Value_Additional_Positioning_Capabilities 533
#define CSN1_RRClassmark3Value_Additional_Positioning_Capabilities_SIZE   1
#define CSN1_RRClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA 543
#define CSN1_RRClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_SIZE   2
#define CSN1_RRClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class 514
#define CSN1_RRClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class_SIZE   2
#define CSN1_RRClassmark3Value_Extended_TSC_Set_Capability_support 549
#define CSN1_RRClassmark3Value_Extended_TSC_Set_Capability_support_SIZE   1
#define CSN1_RRClassmark3Value_GSM_400_Associated_Radio_Capability 500
#define CSN1_RRClassmark3Value_GSM_400_Associated_Radio_Capability_SIZE   4
#define CSN1_RRClassmark3Value_GSM_710_Associated_Radio_Capability 530
#define CSN1_RRClassmark3Value_GSM_710_Associated_Radio_Capability_SIZE   4
#define CSN1_RRClassmark3Value_GSM_750_Associated_Radio_Capability 510
#define CSN1_RRClassmark3Value_GSM_750_Associated_Radio_Capability_SIZE   4
#define CSN1_RRClassmark3Value_GSM_850_Associated_Radio_Capability 501
#define CSN1_RRClassmark3Value_GSM_850_Associated_Radio_Capability_SIZE   4
#define CSN1_RRPacketDownlinkAssignmentType2_UTRAN_FREQUENCY_INDEX 1089
#define CSN1_RRPacketDownlinkAssignmentType2_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_SI6RestOctet_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT 819
#define CSN1_SI6RestOctet_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT_SIZE   1
#define CSN1_Segmented_SMS_Description_struct_SMS_Reference_Number 171
#define CSN1_Segmented_SMS_Description_struct_SMS_Reference_Number_SIZE   4
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_short_layer_2_header 165
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_short_layer_2_header_SIZE   2
#define CSN1_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY_SI10bis_Sequence 611
#define CSN1_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY_SI10bis_Sequence_SIZE   2
#define CSN1__3G_Priority_Parameters_Description_struct_UTRAN_Stop 1308
#define CSN1__3G_Priority_Parameters_Description_struct_UTRAN_Stop_SIZE   1
#define CSN1_Downlink_TBF_assignment_struct_DOWNLINK_TFI_ASSIGNMENT 1043
#define CSN1_Downlink_TBF_assignment_struct_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_EC_Fixed_Uplink_Allocation_struct_STARTING_UL_TIMESLOT  13
#define CSN1_EC_Fixed_Uplink_Allocation_struct_STARTING_UL_TIMESLOT_SIZE   3
#define CSN1_EC_Packet_Channel_Description_Type_1_DL_COVERAGE_CLASS 473
#define CSN1_EC_Packet_Channel_Description_Type_1_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Channel_Description_Type_1_UL_COVERAGE_CLASS 474
#define CSN1_EC_Packet_Channel_Description_Type_1_UL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Channel_Description_Type_2_DL_COVERAGE_CLASS 480
#define CSN1_EC_Packet_Channel_Description_Type_2_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Channel_Description_Type_2_UL_COVERAGE_CLASS 481
#define CSN1_EC_Packet_Channel_Description_Type_2_UL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_RACH_Control_Parameters_struct_CC_Access_Adaptation 213
#define CSN1_EC_RACH_Control_Parameters_struct_CC_Access_Adaptation_SIZE   2
#define CSN1_EC_System_Information_Type_1_EC_Mobile_Allocation_List 620
#define CSN1_EC_System_Information_Type_1_EC_Mobile_Allocation_List_SIZE   0
#define CSN1_E_UTRAN_CSG_Description_struct_E_UTRAN_FREQUENCY_INDEX 1347
#define CSN1_E_UTRAN_CSG_Description_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Start 990
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Start_SIZE   1
#define CSN1_Enhanced_Measurement_report_E_UTRAN_Measurement_Report 603
#define CSN1_Enhanced_Measurement_report_E_UTRAN_Measurement_Report_SIZE   0
#define CSN1_MBMS_p_t_m_channel_description_IE_Frequency_Parameters 1405
#define CSN1_MBMS_p_t_m_channel_description_IE_Frequency_Parameters_SIZE   0
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR_SCALE_ORD 922
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR_SCALE_ORD_SIZE   2
#define CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method 494
#define CSN1_MS_Positioning_Method_Capability_MS_Positioning_Method_SIZE   5
#define CSN1_Measurement_information_E_UTRAN_Parameters_Description 989
#define CSN1_Measurement_information_E_UTRAN_Parameters_Description_SIZE   0
#define CSN1_Measurement_information__3G_Neighbour_Cell_Description 934
#define CSN1_Measurement_information__3G_Neighbour_Cell_Description_SIZE   0
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_TLLI_G_RNTI 699
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_TLLI_G_RNTI_SIZE  32
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_I 1260
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_I_SIZE   3
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_T 1261
#define CSN1_NC_Measurement_Parameters_struct_NC_REPORTING_PERIOD_T_SIZE   3
#define CSN1_NC_Measurement_Parameters_struct_NETWORK_CONTROL_ORDER 1258
#define CSN1_NC_Measurement_Parameters_struct_NETWORK_CONTROL_ORDER_SIZE   2
#define CSN1_Network_Sharing_Information_struct_SI22_Additional_ACC 451
#define CSN1_Network_Sharing_Information_struct_SI22_Additional_ACC_SIZE  16
#define CSN1_Network_Sharing_Information_struct_SI22_SI23_Indicator 444
#define CSN1_Network_Sharing_Information_struct_SI22_SI23_Indicator_SIZE   1
#define CSN1_Non_Segmented_SMS_Description_struct_SMS_Final_Content 179
#define CSN1_Non_Segmented_SMS_Description_struct_SMS_Final_Content_SIZE   0
#define CSN1_PBCCH_Description_2_struct_PBCCH_Frequency_Description 1377
#define CSN1_PBCCH_Description_2_struct_PBCCH_Frequency_Description_SIZE   0
#define CSN1_RRClassmark3Value_GSM_1900_Associated_Radio_Capability 502
#define CSN1_RRClassmark3Value_GSM_1900_Associated_Radio_Capability_SIZE   4
#define CSN1_RRPacketDownlinkAssignmentType2_DOWNLINK_PDCH_PAIRS_C1 1069
#define CSN1_RRPacketDownlinkAssignmentType2_DOWNLINK_PDCH_PAIRS_C1_SIZE   8
#define CSN1_RRPacketDownlinkAssignmentType2_DOWNLINK_PDCH_PAIRS_C2 1070
#define CSN1_RRPacketDownlinkAssignmentType2_DOWNLINK_PDCH_PAIRS_C2_SIZE   8
#define CSN1_RRPacketDownlinkAssignmentType2_EMSR_Additional_PFCs_1 1092
#define CSN1_RRPacketDownlinkAssignmentType2_EMSR_Additional_PFCs_1_SIZE   0
#define CSN1_RRPacketDownlinkAssignmentType2_EMSR_Additional_PFCs_2 1093
#define CSN1_RRPacketDownlinkAssignmentType2_EMSR_Additional_PFCs_2_SIZE   0
#define CSN1_RRPacketDownlinkAssignmentType2_EMSR_Additional_PFCs_3 1094
#define CSN1_RRPacketDownlinkAssignmentType2_EMSR_Additional_PFCs_3_SIZE   0
#define CSN1_SI10bis_Neighbour_Cell_Info_SMS_Guaranteed_Privacy_Ind 469
#define CSN1_SI10bis_Neighbour_Cell_Info_SMS_Guaranteed_Privacy_Ind_SIZE   1
#define CSN1_SI2nRestOctets_GSM_Neighbour_Cell_Selection_parameters 772
#define CSN1_SI2nRestOctets_GSM_Neighbour_Cell_Selection_parameters_SIZE   0
#define CSN1_SI2quaterRestOctets_Measurement_Parameters_Description 1225
#define CSN1_SI2quaterRestOctets_Measurement_Parameters_Description_SIZE   3
#define CSN1_SYSTEM_INFORMATION_TYPE_10ter_Cell_Channel_Description   5
#define CSN1_SYSTEM_INFORMATION_TYPE_10ter_Cell_Channel_Description_SIZE 128
#define CSN1__3G_Priority_Parameters_Description_struct_UTRAN_Start 1307
#define CSN1__3G_Priority_Parameters_Description_struct_UTRAN_Start_SIZE   1
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_UTRAN_FDD_Description 662
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_UTRAN_FDD_Description_SIZE   0
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_UTRAN_TDD_Description 663
#define CSN1_CellSelIndAfterReleaseTCHandSDCCH_UTRAN_TDD_Description_SIZE   0
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC2_Range_DL 201
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC2_Range_DL_SIZE   5
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC2_Range_UL 204
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC2_Range_UL_SIZE   5
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC3_Range_DL 202
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC3_Range_DL_SIZE   5
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC3_Range_UL 205
#define CSN1_Coverage_Class_Selection_Parameters_struct_CC3_Range_UL_SIZE   5
#define CSN1_EC_Cell_Selection_Parameters_struct_EC_RXLEV_ACCESS_MIN 194
#define CSN1_EC_Cell_Selection_Parameters_struct_EC_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_EC_Cell_Selection_Parameters_struct_LB_MS_TXPWR_MAX_CCH 196
#define CSN1_EC_Cell_Selection_Parameters_struct_LB_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Enhanced_Access_Burst  11
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Enhanced_Access_Burst_SIZE   1
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Uplink_TFI_Assignment  14
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Uplink_TFI_Assignment_SIZE   5
#define CSN1_EC_System_Information_Type_2_EC_RACH_Control_Parameters 208
#define CSN1_EC_System_Information_Type_2_EC_RACH_Control_Parameters_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_ALLOCATION_BITMAP_LENGTH 670
#define CSN1_EGPRS_Packet_Uplink_Assignment_ALLOCATION_BITMAP_LENGTH_SIZE   5
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_PENALTY_TIME 782
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_PENALTY_TIME_SIZE   5
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_POWER_OFFSET 783
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_POWER_OFFSET_SIZE   2
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_Session_Parameters_List 1407
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_Session_Parameters_List_SIZE   0
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_TIMESLOT_NUMBER 130
#define CSN1_Packet_Timing_Advance_IE_TIMING_ADVANCE_TIMESLOT_NUMBER_SIZE   3
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap_Length 1191
#define CSN1_Pulse_Format_Coding_2_struct_Pulse_Format_Bitmap_Length_SIZE   7
#define CSN1_RRClassmark3Value_Selective_Ciphering_of_Downlink_SACCH 541
#define CSN1_RRClassmark3Value_Selective_Ciphering_of_Downlink_SACCH_SIZE   1
#define CSN1_RRClassmark3Value_T_GSM_400_Associated_Radio_Capability 522
#define CSN1_RRClassmark3Value_T_GSM_400_Associated_Radio_Capability_SIZE   4
#define CSN1_RRClassmark3Value_T_GSM_810_Associated_Radio_Capability 531
#define CSN1_RRClassmark3Value_T_GSM_810_Associated_Radio_Capability_SIZE   4
#define CSN1_RRClassmark3Value_T_GSM_900_Associated_Radio_Capability 523
#define CSN1_RRClassmark3Value_T_GSM_900_Associated_Radio_Capability_SIZE   4
#define CSN1_RRPacketDownlinkAssignmentType2_DOWNLINK_TFI_ASSIGNMENT 1066
#define CSN1_RRPacketDownlinkAssignmentType2_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_RRPacketDownlinkAssignmentType2_E_UTRAN_FREQUENCY_INDEX 1087
#define CSN1_RRPacketDownlinkAssignmentType2_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_RRPacketUplinkAssignment_Packet_Extended_Timing_Advance 1185
#define CSN1_RRPacketUplinkAssignment_Packet_Extended_Timing_Advance_SIZE   2
#define CSN1_SI2terRestOctets__3G_MEASUREMENT_Parameters_Description 372
#define CSN1_SI2terRestOctets__3G_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_SYSTEM_INFORMATION_TYPE_10bis_BODY_short_layer_2_header 896
#define CSN1_SYSTEM_INFORMATION_TYPE_10bis_BODY_short_layer_2_header_SIZE   2
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_talker_identity_length 166
#define CSN1_VGCS_ADDITIONAL_INFORMATION_BODY_talker_identity_length_SIZE   5
#define CSN1_VGCS_SMS_INFORMATION_BODY_Non_Segmented_SMS_Description 176
#define CSN1_VGCS_SMS_INFORMATION_BODY_Non_Segmented_SMS_Description_SIZE   0
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_C 965
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_C_SIZE   4
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_Index_Start_3G 936
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_Index_Start_3G_SIZE   7
#define CSN1_EC_Downlink_Assignment_message_content_EC_Page_Extension 648
#define CSN1_EC_Downlink_Assignment_message_content_EC_Page_Extension_SIZE   4
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_Nb_NCELL 243
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_Nb_NCELL_SIZE   5
#define CSN1_EC_Paging_Request_message_content_Used_DL_Coverage_Class 642
#define CSN1_EC_Paging_Request_message_content_Used_DL_Coverage_Class_SIZE   2
#define CSN1_EC_RACH_Control_Parameters_struct_BT_Threshold_UL_Margin 217
#define CSN1_EC_RACH_Control_Parameters_struct_BT_Threshold_UL_Margin_SIZE   3
#define CSN1_EC_System_Information_Type_1_EC_Cell_Channel_Description 617
#define CSN1_EC_System_Information_Type_1_EC_Cell_Channel_Description_SIZE   0
#define CSN1_EC_System_Information_Type_4_Network_Sharing_Information 254
#define CSN1_EC_System_Information_Type_4_Network_Sharing_Information_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_TLLI_BLOCK_CHANNEL_CODING 679
#define CSN1_EGPRS_Packet_Uplink_Assignment_TLLI_BLOCK_CHANNEL_CODING_SIZE   1
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_CCN_ACTIVE 1319
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_CCN_ACTIVE_SIZE   1
#define CSN1_Enhanced_Measurement_report_UTRAN_CSG_Measurement_Report 608
#define CSN1_Enhanced_Measurement_report_UTRAN_CSG_Measurement_Report_SIZE   0
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SCALE_ORD 1246
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SCALE_ORD_SIZE   2
#define CSN1_MBMS_p_t_m_channel_description_IE_DL_TIMESLOT_ALLOCATION 1406
#define CSN1_MBMS_p_t_m_channel_description_IE_DL_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Measurement_information_Real_Time_Difference_Description 907
#define CSN1_Measurement_information_Real_Time_Difference_Description_SIZE   0
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_NCC_Permitted 259
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_NCC_Permitted_SIZE   8
#define CSN1_Packet_Downlink_Assignment_LINK_QUALITY_MEASUREMENT_MODE 724
#define CSN1_Packet_Downlink_Assignment_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_RRClassmark3Value_Downlink_Advanced_Receiver_Performance 524
#define CSN1_RRClassmark3Value_Downlink_Advanced_Receiver_Performance_SIZE   2
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_E_UTRAN_PRIORITY 1337
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BCCH_FREQ_NCELL 598
#define CSN1_Repeated_Invalid_BSIC_Information_struct_BCCH_FREQ_NCELL_SIZE   5
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_UTRAN_PRIORITY 1314
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_UTRAN_PRIORITY_SIZE   3
#define CSN1_SI10bis_Neighbour_Cell_Info_SMS_Data_Confidentiality_Ind 468
#define CSN1_SI10bis_Neighbour_Cell_Info_SMS_Data_Confidentiality_Ind_SIZE   1
#define CSN1_Access_Technologies_Request_struct_Access_Technology_Type  46
#define CSN1_Access_Technologies_Request_struct_Access_Technology_Type_SIZE   4
#define CSN1_EC_Downlink_Allocation_struct_STARTING_UL_TIMESLOT_OFFSET 656
#define CSN1_EC_Downlink_Allocation_struct_STARTING_UL_TIMESLOT_OFFSET_SIZE   2
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_CELL_TYPE 245
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_CELL_TYPE_SIZE   1
#define CSN1_EC_RACH_Control_Parameters_struct_EC_Access_Control_Class 215
#define CSN1_EC_RACH_Control_Parameters_struct_EC_Access_Control_Class_SIZE   7
#define CSN1_EC_RACH_Control_Parameters_struct_Exception_Report_Status 216
#define CSN1_EC_RACH_Control_Parameters_struct_Exception_Report_Status_SIZE   1
#define CSN1_EC_System_Information_Type_2_EC_Cell_Selection_Parameters 189
#define CSN1_EC_System_Information_Type_2_EC_Cell_Selection_Parameters_SIZE   0
#define CSN1_E_UTRAN_CSG_Description_struct_RR_E_UTRAN_FREQUENCY_INDEX 1004
#define CSN1_E_UTRAN_CSG_Description_struct_RR_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_E_UTRAN_Measurement_Report_struct_E_UTRAN_FREQUENCY_INDEX 605
#define CSN1_E_UTRAN_Measurement_Report_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_IPA_Uplink_Assignment_struct_EGPRS_CHANNEL_CODING_COMMAND 1384
#define CSN1_IPA_Uplink_Assignment_struct_EGPRS_CHANNEL_CODING_COMMAND_SIZE   4
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_p_t_m_channel_description 1404
#define CSN1_MBMS_Channel_Parameters_IE_MBMS_p_t_m_channel_description_SIZE   0
#define CSN1_Non_Segmented_SMS_Description_struct_SMS_Reference_Number 178
#define CSN1_Non_Segmented_SMS_Description_struct_SMS_Reference_Number_SIZE   4
#define CSN1_RRPacketDownlinkAssignmentType2_Measurement_Control_UTRAN 1088
#define CSN1_RRPacketDownlinkAssignmentType2_Measurement_Control_UTRAN_SIZE   1
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_E_UTRAN_QRXLEVMIN 1340
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_E_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_NR_OF_FDD_CELLS 384
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_NR_OF_FDD_CELLS_SIZE   5
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_UTRAN_QRXLEVMIN 1317
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_NR_OF_TDD_CELLS 391
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_NR_OF_TDD_CELLS_SIZE   5
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_ARFCN_INDEX 389
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_ARFCN_INDEX_SIZE   3
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_FDD_Qmin 375
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_FDD_Qmin_SIZE   3
#define CSN1_SI2quaterRestOctets_GPRS_Real_Time_Difference_Description 1228
#define CSN1_SI2quaterRestOctets_GPRS_Real_Time_Difference_Description_SIZE   0
#define CSN1_Short_RACH_Control_Parameters_struct_Access_Control_Class 222
#define CSN1_Short_RACH_Control_Parameters_struct_Access_Control_Class_SIZE  16
#define CSN1_System_Information_2ter_Indicator_System_Information_2ter 791
#define CSN1_System_Information_2ter_Indicator_System_Information_2ter_SIZE   0
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command 1176
#define CSN1_Uplink_TBF_Assignment_struct_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY_short_layer_2_header 610
#define CSN1_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY_short_layer_2_header_SIZE   2
#define CSN1_paging_channel_restructuring_paging_channel_restructuring 810
#define CSN1_paging_channel_restructuring_paging_channel_restructuring_SIZE   1
#define CSN1_COMPACT_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS 1134
#define CSN1_COMPACT_Neighbour_Cell_params_struct_NR_OF_REMAINING_CELLS_SIZE   4
#define CSN1_Coverage_Class_Selection_Parameters_struct_BT_Threshold_DL 200
#define CSN1_Coverage_Class_Selection_Parameters_struct_BT_Threshold_DL_SIZE   5
#define CSN1_Coverage_Class_Selection_Parameters_struct_BT_Threshold_UL 203
#define CSN1_Coverage_Class_Selection_Parameters_struct_BT_Threshold_UL_SIZE   5
#define CSN1_Coverage_Class_Selection_Parameters_struct_DL_CC_Selection 199
#define CSN1_Coverage_Class_Selection_Parameters_struct_DL_CC_Selection_SIZE   1
#define CSN1_DTMInfoRestOctets_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT 291
#define CSN1_DTMInfoRestOctets_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT_SIZE   1
#define CSN1_EC_Cell_Reselection_Parameters_struct_CELL_RESELECT_OFFSET 236
#define CSN1_EC_Cell_Reselection_Parameters_struct_CELL_RESELECT_OFFSET_SIZE   6
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Start_FN_Next_Data_Block  24
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Start_FN_Next_Data_Block_SIZE   3
#define CSN1_EC_System_Information_Type_2_Short_RACH_Control_Parameters 218
#define CSN1_EC_System_Information_Type_2_Short_RACH_Control_Parameters_SIZE   0
#define CSN1_EC_System_Information_Type_3_EC_Neighbour_Cell_Description 239
#define CSN1_EC_System_Information_Type_3_EC_Neighbour_Cell_Description_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_Access_Technologies_Request 667
#define CSN1_EGPRS_Packet_Uplink_Assignment_Access_Technologies_Request_SIZE   0
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_REPORT_TYPE 1241
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_REPORT_TYPE_SIZE   1
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_CELL_BAR_ACCESS 775
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_CELL_BAR_ACCESS_SIZE   1
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_Random_Reference 1396
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_Random_Reference_SIZE  11
#define CSN1_MBMS_Session_Parameters_List_IE_Estimated_Session_Duration 1410
#define CSN1_MBMS_Session_Parameters_List_IE_Estimated_Session_Duration_SIZE   8
#define CSN1_Measurement_information_MEASUREMENT_Parameters_Description 919
#define CSN1_Measurement_information_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_Multiple_TBF_Allocation_struct_EXTENDED_DYNAMIC_ALLOCATION 1157
#define CSN1_Multiple_TBF_Allocation_struct_EXTENDED_DYNAMIC_ALLOCATION_SIZE   1
#define CSN1_Network_Sharing_Information_struct_SI22_Common_PLMN_PS_ACC 446
#define CSN1_Network_Sharing_Information_struct_SI22_Common_PLMN_PS_ACC_SIZE  16
#define CSN1_RRClassmark3Value_E_UTRA_Measurement_and_Reporting_support 536
#define CSN1_RRClassmark3Value_E_UTRA_Measurement_and_Reporting_support_SIZE   1
#define CSN1_Real_Time_Difference_Description_struct_BA_Index_Start_RTD 908
#define CSN1_Real_Time_Difference_Description_struct_BA_Index_Start_RTD_SIZE   5
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_THRESH_E_UTRAN_low 1339
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_THRESH_E_UTRAN_low_SIZE   5
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_THRESH_UTRAN_low 1316
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_THRESH_UTRAN_low_SIZE   5
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_Qsearch_I 373
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_Qsearch_I_SIZE   4
#define CSN1_SI2quaterRestOctets_p3G_Measurement_Parameters_Description 1271
#define CSN1_SI2quaterRestOctets_p3G_Measurement_Parameters_Description_SIZE   0
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_H_PRIO 1304
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_H_PRIO_SIZE   2
#define CSN1_UTRAN_FDD_Description_struct_CS_FDD_CELL_INFORMATION_Field  36
#define CSN1_UTRAN_FDD_Description_struct_CS_FDD_CELL_INFORMATION_Field_SIZE   0
#define CSN1_UTRAN_TDD_Description_struct_CS_TDD_CELL_INFORMATION_Field  41
#define CSN1_UTRAN_TDD_Description_struct_CS_TDD_CELL_INFORMATION_Field_SIZE   0
#define CSN1__3G_Supplementary_Parameters_Description_struct_UTRAN_Stop 983
#define CSN1__3G_Supplementary_Parameters_Description_struct_UTRAN_Stop_SIZE   1
#define CSN1_Downlink_TBF_assignment_2_struct_Downlink_EGPRS_Window_Size 351
#define CSN1_Downlink_TBF_assignment_2_struct_Downlink_EGPRS_Window_Size_SIZE   5
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Start_First_UL_Data_Block  22
#define CSN1_EC_Fixed_Uplink_Allocation_struct_Start_First_UL_Data_Block_SIZE   4
#define CSN1_EC_System_Information_Type_3_EC_Cell_Reselection_Parameters 234
#define CSN1_EC_System_Information_Type_3_EC_Cell_Reselection_Parameters_SIZE   0
#define CSN1_EGPRS_Packet_Uplink_Assignment_EGPRS_CHANNEL_CODING_COMMAND 677
#define CSN1_EGPRS_Packet_Uplink_Assignment_EGPRS_CHANNEL_CODING_COMMAND_SIZE   4
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_P 1281
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_P_SIZE   4
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_MS_TXPWR_MAX_CCH 778
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_NCELL_LIST_INDEX 773
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_NCELL_LIST_INDEX_SIZE   6
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_RXLEV_ACCESS_MIN 777
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_TEMPORARY_OFFSET 781
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_TEMPORARY_OFFSET_SIZE   3
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION 1039
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_SIZE   8
#define CSN1_Network_Sharing_Information_struct_SI22_Common_PLMN_Allowed 445
#define CSN1_Network_Sharing_Information_struct_SI22_Common_PLMN_Allowed_SIZE   1
#define CSN1_Network_Sharing_Information_struct_SI22_Nb_Additional_PLMNs 447
#define CSN1_Network_Sharing_Information_struct_SI22_Nb_Additional_PLMNs_SIZE   2
#define CSN1_RRClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support 545
#define CSN1_RRClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_Measurement_Control_E_UTRAN 1086
#define CSN1_RRPacketDownlinkAssignmentType2_Measurement_Control_E_UTRAN_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_Power_Control_Parameters_C1 1064
#define CSN1_RRPacketDownlinkAssignmentType2_Power_Control_Parameters_C1_SIZE   0
#define CSN1_RRPacketDownlinkAssignmentType2_Power_Control_Parameters_C2 1065
#define CSN1_RRPacketDownlinkAssignmentType2_Power_Control_Parameters_C2_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_THRESH_E_UTRAN_high 1338
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_THRESH_E_UTRAN_high_SIZE   5
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_Not_Allowed_Cells 393
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_Not_Allowed_Cells_SIZE   0
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_THRESH_UTRAN_high 1315
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_THRESH_UTRAN_high_SIZE   5
#define CSN1_SI2quaterRestOctets_GPRS_MEASUREMENT_Parameters_Description 1240
#define CSN1_SI2quaterRestOctets_GPRS_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT 966
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT_SIZE   1
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_FDD_Description 1269
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_FDD_Description_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_TDD_Description 1270
#define CSN1__3G_Neighbour_Cell_Description_struct_UTRAN_TDD_Description_SIZE   0
#define CSN1__3G_Supplementary_Parameters_Description_struct_UTRAN_Start 982
#define CSN1__3G_Supplementary_Parameters_Description_struct_UTRAN_Start_SIZE   1
#define CSN1_IPA_Downlink_Assignment_struct_LINK_QUALITY_MEASUREMENT_MODE 1392
#define CSN1_IPA_Downlink_Assignment_struct_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_IRAT_Cell_Reselection_Information_struct_Nb_Additional_PLMNs 1369
#define CSN1_IRAT_Cell_Reselection_Information_struct_Nb_Additional_PLMNs_SIZE   2
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_TBF_STARTING_TIME 697
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_TBF_STARTING_TIME_SIZE  16
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_FDD_Qoffset 374
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_FDD_Qoffset_SIZE   4
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_TDD_Qoffset 376
#define CSN1_SI2_3G_MEASUREMENT_Parameters_Description_struct_TDD_Qoffset_SIZE   4
#define CSN1_Short_RACH_Control_Parameters_struct_Exception_Report_Status 223
#define CSN1_Short_RACH_Control_Parameters_struct_Exception_Report_Status_SIZE   1
#define CSN1_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents 1150
#define CSN1_Direct_encoding_2_struct_Length_of_MA_Frequency_List_contents_SIZE   4
#define CSN1_EC_Cell_Channel_Description_struct_Frequency_List_Information 619
#define CSN1_EC_Cell_Channel_Description_struct_Frequency_List_Information_SIZE   0
#define CSN1_EC_Cell_Selection_Parameters_struct_CELL_SELECTION_RLA_MARGIN 197
#define CSN1_EC_Cell_Selection_Parameters_struct_CELL_SELECTION_RLA_MARGIN_SIZE   3
#define CSN1_EC_Downlink_Assignment_message_content_EC_Downlink_Allocation 651
#define CSN1_EC_Downlink_Assignment_message_content_EC_Downlink_Allocation_SIZE   0
#define CSN1_EC_Downlink_Assignment_message_content_Used_DL_Coverage_Class 647
#define CSN1_EC_Downlink_Assignment_message_content_Used_DL_Coverage_Class_SIZE   2
#define CSN1_EC_Fixed_Uplink_Allocation_struct_STARTING_DL_TIMESLOT_OFFSET  15
#define CSN1_EC_Fixed_Uplink_Allocation_struct_STARTING_DL_TIMESLOT_OFFSET_SIZE   2
#define CSN1_Enhanced_Measurement_report_Repeated_Invalid_BSIC_Information 597
#define CSN1_Enhanced_Measurement_report_Repeated_Invalid_BSIC_Information_SIZE  17
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_REPORTING_RATE 1242
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_REPORTING_RATE_SIZE   1
#define CSN1_Measurement_information_UTRAN_CSG_Cells_Reporting_Description 1006
#define CSN1_Measurement_information_UTRAN_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_Pulse_Format_Coding_2_struct_Non_Hopping_Carrier_Pulse_Format 1193
#define CSN1_Pulse_Format_Coding_2_struct_Non_Hopping_Carrier_Pulse_Format_SIZE   0
#define CSN1_RRClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability 503
#define CSN1_RRClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_LINK_QUALITY_MEASUREMENT_MODE 1068
#define CSN1_RRPacketDownlinkAssignmentType2_LINK_QUALITY_MEASUREMENT_MODE_SIZE   2
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_Measurement_Bandwidth 1336
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_PCID_to_TA_mapping 395
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_PCID_to_TA_mapping_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_CDMA2000_Description 940
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_CDMA2000_Description_SIZE   0
#define CSN1_EC_Cell_Reselection_Parameters_struct_CELL_RESELECT_HYSTERESIS 235
#define CSN1_EC_Cell_Reselection_Parameters_struct_CELL_RESELECT_HYSTERESIS_SIZE   3
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Wait_Timer_1 636
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Wait_Timer_1_SIZE   8
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Wait_Timer_2 638
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Wait_Timer_2_SIZE   8
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Wait_Timer_3 640
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Wait_Timer_3_SIZE   8
#define CSN1_Extension_Information_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT 892
#define CSN1_Extension_Information_DEDICATED_MODE_MBMS_NOTIFICATION_SUPPORT_SIZE   1
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_Frequency_Parameters 1402
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_Frequency_Parameters_SIZE   0
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_STARTING_TIME_OFFSET 1400
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_STARTING_TIME_OFFSET_SIZE   6
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_TIMING_ADVANCE_VALUE 1399
#define CSN1_IPA_Single_Block_Uplink_Assignment_struct_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_IPA_Uplink_Assignment_struct_Radio_Access_Capabilities_Request 1385
#define CSN1_IPA_Uplink_Assignment_struct_Radio_Access_Capabilities_Request_SIZE   1
#define CSN1_MBMS_Session_Parameters_List_IE_Length_of_MBMS_Bearer_Identity 1408
#define CSN1_MBMS_Session_Parameters_List_IE_Length_of_MBMS_Bearer_Identity_SIZE   3
#define CSN1_Measurement_information__3G_MEASUREMENT_Parameters_Description 964
#define CSN1_Measurement_information__3G_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_Common_PLMN_Allowed 255
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_Common_PLMN_Allowed_SIZE   1
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_Nb_Additional_PLMNs 256
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_Nb_Additional_PLMNs_SIZE   2
#define CSN1_RRClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability 505
#define CSN1_RRClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_RRPacketDownlinkAssignmentType2_PDCH_pairs_configuration_error 1655
#define CSN1_RRPacketDownlinkAssignmentType2_PDCH_pairs_configuration_error_SIZE   2
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_FDD_ARFCN 856
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_FDD_ARFCN_SIZE  14
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_TDD_ARFCN 857
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_TDD_ARFCN_SIZE  14
#define CSN1_SI2quaterRestOctets_Extended_EARFCNs_Description_for_CSG_Cells 1360
#define CSN1_SI2quaterRestOctets_Extended_EARFCNs_Description_for_CSG_Cells_SIZE   0
#define CSN1_SI2quaterRestOctets_GPRS_3G_MEASUREMENT_Parameters_Description 1280
#define CSN1_SI2quaterRestOctets_GPRS_3G_MEASUREMENT_Parameters_Description_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_Absolute_Index_Start_EMR 1268
#define CSN1__3G_Neighbour_Cell_Description_struct_Absolute_Index_Start_EMR_SIZE   7
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_UTRAN_FDD_Description 938
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_UTRAN_FDD_Description_SIZE   0
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_UTRAN_TDD_Description 939
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_UTRAN_TDD_Description_SIZE   0
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_CELL_BAR_ACCESS 246
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_CELL_BAR_ACCESS_SIZE   1
#define CSN1_EGPRS_Packet_Uplink_Assignment_NUMBER_OF_RADIO_BLOCKS_ALLOCATED 695
#define CSN1_EGPRS_Packet_Uplink_Assignment_NUMBER_OF_RADIO_BLOCKS_ALLOCATED_SIZE   2
#define CSN1_ETWS_Primary_Notification_struct_ETWS_Primary_Notification_Data 1462
#define CSN1_ETWS_Primary_Notification_struct_ETWS_Primary_Notification_Data_SIZE   0
#define CSN1_Early_Classmark_Sending_Control_Early_Classmark_Sending_Control 792
#define CSN1_Early_Classmark_Sending_Control_Early_Classmark_Sending_Control_SIZE   0
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT 1283
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT_SIZE   1
#define CSN1_GPRS_Real_Time_Difference_Description_struct_BA_Index_Start_RTD 1229
#define CSN1_GPRS_Real_Time_Difference_Description_struct_BA_Index_Start_RTD_SIZE   5
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_CELL_RESELECT_OFFSET 780
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_CELL_RESELECT_OFFSET_SIZE   6
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Radio_Bearer_Starting_Time 1411
#define CSN1_MBMS_Session_Parameters_List_IE_MBMS_Radio_Bearer_Starting_Time_SIZE  16
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment 1040
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_Uplink_Control_Timeslot 1038
#define CSN1_Multiple_Downlink_TBF_Assignment_struct_Uplink_Control_Timeslot_SIZE   3
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_UTRAN_FREQUENCY_INDEX 1313
#define CSN1_Repeated_UTRAN_Priority_Parameters_struct_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description 1299
#define CSN1_SI2quaterRestOctets_Priority_and_E_UTRAN_Parameters_Description_SIZE   0
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_Qmin 1277
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_Qmin_SIZE   3
#define CSN1_UTRAN_FDD_Description_struct_Repeated_UTRAN_FDD_Neighbour_Cells 381
#define CSN1_UTRAN_FDD_Description_struct_Repeated_UTRAN_FDD_Neighbour_Cells_SIZE   0
#define CSN1_UTRAN_TDD_Description_struct_Repeated_UTRAN_TDD_Neighbour_Cells 387
#define CSN1_UTRAN_TDD_Description_struct_Repeated_UTRAN_TDD_Neighbour_Cells_SIZE   0
#define CSN1__3G_Priority_Parameters_Description_struct_DEFAULT_THRESH_UTRAN 1310
#define CSN1__3G_Priority_Parameters_Description_struct_DEFAULT_THRESH_UTRAN_SIZE   5
#define CSN1_EC_Cell_Selection_Parameters_struct_Location_Area_Identification 190
#define CSN1_EC_Cell_Selection_Parameters_struct_Location_Area_Identification_SIZE  40
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Page_Extension 634
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Page_Extension_SIZE   4
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Page_Extension 629
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Page_Extension_SIZE   4
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_MS_TXPWR_MAX_CCH 249
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_MS_TXPWR_MAX_CCH_SIZE   5
#define CSN1_EC_System_Information_Type_2_Coverage_Class_Selection_Parameters 198
#define CSN1_EC_System_Information_Type_2_Coverage_Class_Selection_Parameters_SIZE   0
#define CSN1_MEASUREMENT_PARAMETERS_Description_Struct_SERVING_BAND_REPORTING 1227
#define CSN1_MEASUREMENT_PARAMETERS_Description_Struct_SERVING_BAND_REPORTING_SIZE   2
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR_MULTIBAND_REPORTING 920
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR_MULTIBAND_REPORTING_SIZE   2
#define CSN1_Measurement_information__3G_Supplementary_Parameters_Description 981
#define CSN1_Measurement_information__3G_Supplementary_Parameters_Description_SIZE   0
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_MBMS_Session_Identity 706
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_MBMS_Session_Identity_SIZE   8
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_PACKET_TIMING_ADVANCE 702
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_PACKET_TIMING_ADVANCE_SIZE   0
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_EARFCN_extended 1008
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_EARFCN_extended_SIZE  18
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_RR_Measurement_Bandwidth 995
#define CSN1_Repeated_E_UTRAN_Neighbour_Cells_struct_RR_Measurement_Bandwidth_SIZE   3
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_I 1272
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_I_SIZE   4
#define CSN1_Compressed_Inter_RAT_HO_INFO_IND_Compressed_Inter_RAT_HO_INFO_IND   1
#define CSN1_Compressed_Inter_RAT_HO_INFO_IND_Compressed_Inter_RAT_HO_INFO_IND_SIZE   0
#define CSN1_EC_Packet_Channel_Description_Type_1_QUARTER_HYPERFRAME_INDICATOR 472
#define CSN1_EC_Packet_Channel_Description_Type_1_QUARTER_HYPERFRAME_INDICATOR_SIZE   2
#define CSN1_EC_Packet_Channel_Description_Type_2_QUARTER_HYPERFRAME_INDICATOR 479
#define CSN1_EC_Packet_Channel_Description_Type_2_QUARTER_HYPERFRAME_INDICATOR_SIZE   2
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_p3G_SEARCH_PRIO 1282
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_p3G_SEARCH_PRIO_SIZE   1
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_GPRS_Support_Indicator 784
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_GPRS_Support_Indicator_SIZE   0
#define CSN1_RRClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support 547
#define CSN1_RRClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_E_UTRAN_FREQUENCY_INDEX 394
#define CSN1_Repeated_E_UTRAN_Not_Allowed_Cells_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_T_Reselection 1305
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_T_Reselection_SIZE   2
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_Absolute_Index_Start_EMR 937
#define CSN1__3G_Neighbour_Cell_Description_struct_RR_Absolute_Index_Start_EMR_SIZE   7
#define CSN1__3G_Priority_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY 1309
#define CSN1__3G_Priority_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY_SIZE   3
#define CSN1_COMPACT_Neighbour_Cell_params_struct_COMPACT_Cell_selection_params 1133
#define CSN1_COMPACT_Neighbour_Cell_params_struct_COMPACT_Cell_selection_params_SIZE   0
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_MULTIBAND_REPORTING 1244
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_MULTIBAND_REPORTING_SIZE   2
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_SAME_LA_AS_SERVING_CELL 776
#define CSN1_GSM_Neighbour_Cell_Selection_params_struct_SAME_LA_AS_SERVING_CELL_SIZE   1
#define CSN1_IndividualPriorities_E_UTRAN_IPP_with_extended_EARFCNs_Description 865
#define CSN1_IndividualPriorities_E_UTRAN_IPP_with_extended_EARFCNs_Description_SIZE   0
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__400_REPORTING_OFFSET 927
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__400_REPORTING_OFFSET_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__850_REPORTING_OFFSET 931
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__850_REPORTING_OFFSET_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__900_REPORTING_OFFSET 923
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__900_REPORTING_OFFSET_SIZE   3
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_EC_Access_Control_Class 260
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_EC_Access_Control_Class_SIZE   7
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_Exception_Report_Status 261
#define CSN1_Network_Sharing_Information_struct_EC_SI_4_Exception_Report_Status_SIZE   1
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_E_UTRAN_FREQUENCY_INDEX 396
#define CSN1_Repeated_E_UTRAN_PCID_to_TA_mapping_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_Qoffset 1274
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_Qoffset_SIZE   4
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_Qoffset 1278
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_Qoffset_SIZE   4
#define CSN1_SI2terRestOctets__3G_Additional_Measurement_Parameters_Description 377
#define CSN1_SI2terRestOctets__3G_Additional_Measurement_Parameters_Description_SIZE   7
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_GERAN_PRIORITY 1301
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_GERAN_PRIORITY_SIZE   3
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_THRESH_GSM_low 1303
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_THRESH_GSM_low_SIZE   4
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_OFFSET 968
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_OFFSET_SIZE   3
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_OFFSET 971
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_OFFSET_SIZE   3
#define CSN1__3G_Priority_Parameters_Description_struct_DEFAULT_UTRAN_QRXLEVMIN 1311
#define CSN1__3G_Priority_Parameters_Description_struct_DEFAULT_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C1 1082
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C1_SIZE   8
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C2 1083
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_TIMESLOT_ALLOCATION_C2_SIZE   8
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Request_Reference 630
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Request_Reference_SIZE  13
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_EC_RXLEV_ACCESS_MIN 248
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_EC_RXLEV_ACCESS_MIN_SIZE   6
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_REP_QUANT  91
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_REP_QUANT_SIZE   1
#define CSN1_IndividualPriorities__3G_Individual_Priority_Parameters_Description 853
#define CSN1_IndividualPriorities__3G_Individual_Priority_Parameters_Description_SIZE   0
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR_SERVING_BAND_REPORTING 921
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR_SERVING_BAND_REPORTING_SIZE   2
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1800_REPORTING_OFFSET 925
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1800_REPORTING_OFFSET_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1900_REPORTING_OFFSET 929
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1900_REPORTING_OFFSET_SIZE   3
#define CSN1_RRClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support 548
#define CSN1_RRClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support_SIZE   1
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Downlink_TBF_assignment 1075
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_Downlink_TBF_assignment 1078
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_UTRAN_PRIORITY 858
#define CSN1_Repeated_Individual_UTRAN_Priority_Parameters_struct_UTRAN_PRIORITY_SIZE   3
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment 1084
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_Downlink_TBF_assignment_SIZE   0
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_Uplink_Control_Timeslot 1081
#define CSN1_BTTI_Multiple_Downlink_TBF_Assignment_struct_Uplink_Control_Timeslot_SIZE   3
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_CELL_RESELECT_OFFSET 250
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_CELL_RESELECT_OFFSET_SIZE   6
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p400_REPORTING_OFFSET 1251
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p400_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p850_REPORTING_OFFSET 1255
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p850_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p900_REPORTING_OFFSET 1247
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p900_REPORTING_OFFSET_SIZE   3
#define CSN1_Measurement_information_E_UTRAN_NC_with_extended_EARFCNs_Description 1007
#define CSN1_Measurement_information_E_UTRAN_NC_with_extended_EARFCNs_Description_SIZE   0
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_Length_Indicator_of_MS_ID 700
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_Length_Indicator_of_MS_ID_SIZE   2
#define CSN1_RRPacketDownlinkAssignmentType2_RTTI_Multiple_Downlink_Assignment_DC 1073
#define CSN1_RRPacketDownlinkAssignmentType2_RTTI_Multiple_Downlink_Assignment_DC_SIZE   0
#define CSN1_RRPacketDownlinkAssignmentType2_RTTI_Multiple_Downlink_Assignment_SC 1076
#define CSN1_RRPacketDownlinkAssignmentType2_RTTI_Multiple_Downlink_Assignment_SC_SIZE   0
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_CELL_INFORMATION_Field 385
#define CSN1_Repeated_UTRAN_FDD_Neighbour_Cells_struct_FDD_CELL_INFORMATION_Field_SIZE   0
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_CELL_INFORMATION_Field 392
#define CSN1_Repeated_UTRAN_TDD_Neighbour_Cells_struct_TDD_CELL_INFORMATION_Field_SIZE   0
#define CSN1_SI2quaterRestOctets_Enhanced_Cell_Reselection_Parameters_Description 1349
#define CSN1_SI2quaterRestOctets_Enhanced_Cell_Reselection_Parameters_Description_SIZE   0
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT 1275
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REP_QUANT_SIZE   1
#define CSN1__3G_Additional_Measurement_Parameters_Description_struct_FDD_RSCPmin 1292
#define CSN1__3G_Additional_Measurement_Parameters_Description_struct_FDD_RSCPmin_SIZE   4
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING 967
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING 970
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Request_Reference_1 635
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Request_Reference_1_SIZE  13
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Request_Reference_2 637
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Request_Reference_2_SIZE  13
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Request_Reference_3 639
#define CSN1_EC_Immediate_Assignment_Reject_message_content_EC_Request_Reference_3_SIZE  13
#define CSN1_EC_Immediate_Assignment_Reject_message_content_Used_DL_Coverage_Class 633
#define CSN1_EC_Immediate_Assignment_Reject_message_content_Used_DL_Coverage_Class_SIZE   2
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_Used_DL_Coverage_Class 628
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_Used_DL_Coverage_Class_SIZE   2
#define CSN1_EC_System_Information_Type_3_EC_Neighbour_Cell_Reselection_Parameters 242
#define CSN1_EC_System_Information_Type_3_EC_Neighbour_Cell_Reselection_Parameters_SIZE   0
#define CSN1_Extended_EARFCNs_Description_for_CSG_Cells_struct_CSG_EARFCN_extended 1361
#define CSN1_Extended_EARFCNs_Description_for_CSG_Cells_struct_CSG_EARFCN_extended_SIZE  18
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_INVALID_BSIC_REPORTING 1243
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_INVALID_BSIC_REPORTING_SIZE   1
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SERVING_BAND_REPORTING 1245
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_SERVING_BAND_REPORTING_SIZE   2
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1800_REPORTING_OFFSET 1249
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1800_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1900_REPORTING_OFFSET 1253
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1900_REPORTING_OFFSET_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__400_REPORTING_THRESHOLD 928
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__400_REPORTING_THRESHOLD_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__850_REPORTING_THRESHOLD 932
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__850_REPORTING_THRESHOLD_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__900_REPORTING_THRESHOLD 924
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__900_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_NUMBER_OF_ALLOCATED_BLOCKS 698
#define CSN1_Multiple_Blocks_Packet_Downlink_Assignment_NUMBER_OF_ALLOCATED_BLOCKS_SIZE   4
#define CSN1_RRPacketDownlinkAssignmentType2_BTTI_Multiple_Downlink_TBF_Assignment 1080
#define CSN1_RRPacketDownlinkAssignmentType2_BTTI_Multiple_Downlink_TBF_Assignment_SIZE   0
#define CSN1_SI2quaterRestOctets__3G_Additional_Measurement_Parameters_Description 1290
#define CSN1_SI2quaterRestOctets__3G_Additional_Measurement_Parameters_Description_SIZE   7
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_THRESHOLD 969
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_THRESHOLD 972
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_E_UTRAN_Parameters_Description_struct_Repeated_E_UTRAN_Neighbour_Cells 1333
#define CSN1_E_UTRAN_Parameters_Description_struct_Repeated_E_UTRAN_Neighbour_Cells_SIZE   0
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_OFFSET 1285
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_OFFSET 1288
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_OFFSET_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1800_REPORTING_THRESHOLD 926
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1800_REPORTING_THRESHOLD_SIZE   3
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1900_REPORTING_THRESHOLD 930
#define CSN1_MEASUREMENT_PARAMETERS_Description_struct_RR__1900_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_Measurement_Bandwidth 1009
#define CSN1_Repeated_E_UTRAN_NC_with_extended_EARFCNs_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_Coverage_Class_Selection_Parameters_struct_DL_Signal_Strength_Step_Size 207
#define CSN1_Coverage_Class_Selection_Parameters_struct_DL_Signal_Strength_Step_Size_SIZE   2
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_SAME_RA_AS_SERVING_CELL 247
#define CSN1_EC_Neighbour_Cell_Reselection_Parameters_struct_SAME_RA_AS_SERVING_CELL_SIZE   1
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_REPORTING_GRANULARITY  99
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_REPORTING_GRANULARITY_SIZE   1
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p400_REPORTING_THRESHOLD 1252
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p400_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p850_REPORTING_THRESHOLD 1256
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p850_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p900_REPORTING_THRESHOLD 1248
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p900_REPORTING_THRESHOLD_SIZE   3
#define CSN1_IndividualPriorities_E_UTRAN_Individual_Priority_Parameters_Description 859
#define CSN1_IndividualPriorities_E_UTRAN_Individual_Priority_Parameters_Description_SIZE   0
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY 823
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY_SIZE   3
#define CSN1_RRClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability 511
#define CSN1_RRClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_RRClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability 504
#define CSN1_RRClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_SIZE   1
#define CSN1_SI2_3G_Additional_Measurement_Parameters_Description_struct_FDD_RSCPmin 379
#define CSN1_SI2_3G_Additional_Measurement_Parameters_Description_struct_FDD_RSCPmin_SIZE   4
#define CSN1_SI2quaterRestOctets__3G_ADDITIONAL_MEASUREMENT_Parameters_Description_2 1293
#define CSN1_SI2quaterRestOctets__3G_ADDITIONAL_MEASUREMENT_Parameters_Description_2_SIZE   0
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_CDMA2000_REPORTING_OFFSET 974
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_CDMA2000_REPORTING_OFFSET_SIZE   3
#define CSN1_E_UTRAN_Parameters_Description_struct_Repeated_E_UTRAN_Not_Allowed_Cells 1341
#define CSN1_E_UTRAN_Parameters_Description_struct_Repeated_E_UTRAN_Not_Allowed_Cells_SIZE   0
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING 1284
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING 1287
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_REP_QUANT 1325
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_REP_QUANT_SIZE   1
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_Qsearch_P_E_UTRAN 1324
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_Qsearch_P_E_UTRAN_SIZE   4
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1800_REPORTING_THRESHOLD 1250
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1800_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1900_REPORTING_THRESHOLD 1254
#define CSN1_GPRS_MEASUREMENT_PARAMETERS_Description_struct_p1900_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_DEFAULT_UTRAN_QRXLEVMIN 825
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_DEFAULT_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_EARFCN_extended 839
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_EARFCN_extended_SIZE  18
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_C_Initial 1273
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_Qsearch_C_Initial_SIZE   1
#define CSN1__3G_Additional_Measurement_Parameters_Description_struct_FDD_Qmin_Offset 1291
#define CSN1__3G_Additional_Measurement_Parameters_Description_struct_FDD_Qmin_Offset_SIZE   3
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Fixed_Uplink_Allocation 632
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Fixed_Uplink_Allocation_SIZE   0
#define CSN1_EC_Neighbour_Cell_Description_struct_Neighbour_Frequency_List_Information 241
#define CSN1_EC_Neighbour_Cell_Description_struct_Neighbour_Frequency_List_Information_SIZE   0
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_Repeated_E_UTRAN_Neighbour_Cells 993
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_Repeated_E_UTRAN_Neighbour_Cells_SIZE   0
#define CSN1_E_UTRAN_Parameters_Description_struct_Repeated_E_UTRAN_PCID_to_TA_mapping 1342
#define CSN1_E_UTRAN_Parameters_Description_struct_Repeated_E_UTRAN_PCID_to_TA_mapping_SIZE   0
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_THRESHOLD 1286
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_THRESHOLD 1289
#define CSN1_GPRS_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_DEFAULT_THRESH_UTRAN_low 824
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_DEFAULT_THRESH_UTRAN_low_SIZE   5
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_Qmin 566
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_Qmin_SIZE   4
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_E_UTRAN_PRIORITY 841
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_Description_struct_EARFCN 862
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_Description_struct_EARFCN_SIZE  16
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_CDMA2000_MULTIRAT_REPORTING 973
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_CDMA2000_MULTIRAT_REPORTING_SIZE   2
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_UTRAN_FDD_TDD_Description 826
#define CSN1_Priority_and_UTRAN_Parameters_Description_struct_UTRAN_FDD_TDD_Description_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_E_UTRAN_QRXLEVMIN 844
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_E_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_UTRAN_ARFCN 830
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_UTRAN_ARFCN_SIZE  14
#define CSN1_Repeated_UTRAN_Measurement_Control_Parameters_struct_UTRAN_FREQUENCY_INDEX 987
#define CSN1_Repeated_UTRAN_Measurement_Control_Parameters_struct_UTRAN_FREQUENCY_INDEX_SIZE   5
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_THRESH_Priority_Search 1302
#define CSN1_Serving_Cell_Priority_Parameters_Description_struct_THRESH_Priority_Search_SIZE   4
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_CDMA2000_REPORTING_THRESHOLD 975
#define CSN1__3G_MEASUREMENT_PARAMETERS_Description_struct_CDMA2000_REPORTING_THRESHOLD_SIZE   3
#define CSN1_EC_Downlink_Assignment_message_content_EC_Packet_Channel_Description_Type_2 650
#define CSN1_EC_Downlink_Assignment_message_content_EC_Packet_Channel_Description_Type_2_SIZE  15
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_Qsearch_C_E_UTRAN_Initial  90
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_Qsearch_C_E_UTRAN_Initial_SIZE   4
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_Repeated_E_UTRAN_Not_Allowed_Cells 996
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_Repeated_E_UTRAN_Not_Allowed_Cells_SIZE   0
#define CSN1_Measurement_information__3G_ADDITIONAL_MEASUREMENT_Parameters_Description_2 976
#define CSN1_Measurement_information__3G_ADDITIONAL_MEASUREMENT_Parameters_Description_2_SIZE   0
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_THRESH_E_UTRAN_low 843
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_THRESH_E_UTRAN_low_SIZE   5
#define CSN1_SI2_3G_Additional_Measurement_Parameters_Description_struct_FDD_Qmin_Offset 378
#define CSN1_SI2_3G_Additional_Measurement_Parameters_Description_struct_FDD_Qmin_Offset_SIZE   3
#define CSN1_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_Cells_Reporting_Description 1351
#define CSN1_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_MULTIRAT_REPORTING  92
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_MULTIRAT_REPORTING_SIZE   2
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_RSRPmin 565
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_RSRPmin_SIZE   5
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_THRESH_E_UTRAN_high 842
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_THRESH_E_UTRAN_high_SIZE   5
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY 854
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_DEFAULT_UTRAN_PRIORITY_SIZE   3
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_Description_struct_DEFAULT_E_UTRAN_PRIORITY 866
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_Description_struct_DEFAULT_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_RRPacketDownlinkAssignmentType2_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support 1095
#define CSN1_RRPacketDownlinkAssignmentType2_EGPRS_Packet_Downlink_Ack_Nack_Type_3_Support_SIZE   1
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_QQUALMIN 564
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_QQUALMIN_SIZE   4
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_UTRAN_PRIORITY 831
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_UTRAN_PRIORITY_SIZE   3
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING 1276
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_FDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING 1279
#define CSN1_SI2quater_3G_MEASUREMENT_PARAMETERS_Description_struct_TDD_MULTIRAT_REPORTING_SIZE   2
#define CSN1__3G_Priority_Parameters_Description_struct_Repeated_UTRAN_Priority_Parameters 1312
#define CSN1__3G_Priority_Parameters_Description_struct_Repeated_UTRAN_Priority_Parameters_SIZE   0
#define CSN1_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_Cells_Reporting_Description 1352
#define CSN1_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_Cells_Reporting_Description_SIZE   0
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_OFFSET  95
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_OFFSET_SIZE   3
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_OFFSET  98
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_OFFSET_SIZE   3
#define CSN1_Repeated_E_UTRAN_Measurement_Control_Parameters_struct_E_UTRAN_FREQUENCY_INDEX 1000
#define CSN1_Repeated_E_UTRAN_Measurement_Control_Parameters_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_Measurement_Bandwidth 840
#define CSN1_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_struct_Measurement_Bandwidth_SIZE   3
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_UTRAN_QRXLEVMIN 834
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_UTRAN_Measurement_Control_Parameters_struct_Measurement_Control_UTRAN 988
#define CSN1_Repeated_UTRAN_Measurement_Control_Parameters_struct_Measurement_Control_UTRAN_SIZE   1
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD 102
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_TDD_REPORTING_THRESHOLD 104
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_DEFAULT_E_UTRAN_PRIORITY 835
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_DEFAULT_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_THRESH_UTRAN_low 833
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_THRESH_UTRAN_low_SIZE   5
#define CSN1__3G_Early_Classmark_Sending_Restriction__3G_Early_Classmark_Sending_Restriction 796
#define CSN1__3G_Early_Classmark_Sending_Restriction__3G_Early_Classmark_Sending_Restriction_SIZE   0
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_Measurement_Parameters_Description 1322
#define CSN1_E_UTRAN_Parameters_Description_struct_E_UTRAN_Measurement_Parameters_Description_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_DEFAULT_E_UTRAN_QRXLEVMIN 837
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_DEFAULT_E_UTRAN_QRXLEVMIN_SIZE   5
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_THRESH_UTRAN_high 832
#define CSN1_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_struct_THRESH_UTRAN_high_SIZE   5
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2 103
#define CSN1_UTRAN_CSG_Cells_Reporting_Description_struct_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD 100
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD 101
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_MULTIRAT_REPORTING 1326
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_MULTIRAT_REPORTING_SIZE   2
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_DEFAULT_THRESH_E_UTRAN_low 836
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_DEFAULT_THRESH_E_UTRAN_low_SIZE   5
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_E_UTRAN_Parameters_Description 1318
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_E_UTRAN_Parameters_Description_SIZE   0
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC 1074
#define CSN1_RTTI_Multiple_Downlink_Assignment_DC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_DC_SIZE   8
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC 1077
#define CSN1_RTTI_Multiple_Downlink_Assignment_SC_struct_RTTI_DOWNLINK_PDCH_PAIR_ASSIGNMENT_SC_SIZE   4
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_low_Q 563
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_low_Q_SIZE   5
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD 1353
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_TDD_REPORTING_THRESHOLD 1355
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_DEFAULT_E_UTRAN_PRIORITY 860
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_DEFAULT_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_UTRAN_Parameters_Description 1371
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_UTRAN_Parameters_Description_SIZE   0
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_high_Q 562
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_THRESH_E_UTRAN_high_Q_SIZE   5
#define CSN1_Repeated_E_UTRAN_Measurement_Control_Parameters_struct_Measurement_Control_E_UTRAN 1001
#define CSN1_Repeated_E_UTRAN_Measurement_Control_Parameters_struct_Measurement_Control_E_UTRAN_SIZE   1
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Packet_Channel_Description_Type_2 631
#define CSN1_EC_Immediate_Assignment_Type_2_message_content_EC_Packet_Channel_Description_Type_2_SIZE  15
#define CSN1_ETWS_Primary_Notification_struct_Total_No_Of_Segments_For_ETWS_Primary_Notification 1458
#define CSN1_ETWS_Primary_Notification_struct_Total_No_Of_Segments_For_ETWS_Primary_Notification_SIZE   4
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_2  94
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_2  97
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Measurement_Parameters_Description 992
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Measurement_Parameters_Description_SIZE   0
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_OFFSET 1329
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_OFFSET_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_OFFSET 1332
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_OFFSET_SIZE   3
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_Description_struct_E_UTRAN_PRIORITY 863
#define CSN1_Repeated_Individual_E_UTRAN_Priority_Parameters_Description_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2 1354
#define CSN1_E_UTRAN_CSG_Cells_Reporting_Description_struct_E_UTRAN_CSG_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_E_UTRAN_Parameters_Description 1372
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_E_UTRAN_Parameters_Description_SIZE   0
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_FREQUENCY_INDEX 561
#define CSN1_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_struct_E_UTRAN_FREQUENCY_INDEX_SIZE   3
#define CSN1__3G_Additional_Measurement_Parameters_Description_2_struct_FDD_REPORTING_THRESHOLD_2  89
#define CSN1__3G_Additional_Measurement_Parameters_Description_2_struct_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_E_UTRAN_Parameters_Description_struct_GPRS_E_UTRAN_Measurement_Parameters_Description 1323
#define CSN1_E_UTRAN_Parameters_Description_struct_GPRS_E_UTRAN_Measurement_Parameters_Description_SIZE   0
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD 1327
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD 1330
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_SIZE   3
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct__3G_Priority_Parameters_Description 1306
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct__3G_Priority_Parameters_Description_SIZE   0
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_MEASUREMENT_REPORT_OFFSET  93
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_MEASUREMENT_REPORT_OFFSET_SIZE   6
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_MEASUREMENT_REPORT_OFFSET  96
#define CSN1_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_MEASUREMENT_REPORT_OFFSET_SIZE   6
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_Description_struct_EARFCN_extended 868
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_Description_struct_EARFCN_extended_SIZE  18
#define CSN1__3G_Measurement_Control_Parameters_Description_struct_DEFAULT_Measurement_Control_UTRAN 985
#define CSN1__3G_Measurement_Control_Parameters_Description_struct_DEFAULT_Measurement_Control_UTRAN_SIZE   1
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_2 1328
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_FDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_2 1331
#define CSN1_GPRS_E_UTRAN_Measurement_Parameters_Description_struct_E_UTRAN_TDD_REPORTING_THRESHOLD_2_SIZE   6
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_Description_struct_E_UTRAN_PRIORITY 869
#define CSN1_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_Description_struct_E_UTRAN_PRIORITY_SIZE   3
#define CSN1_UTRAN_FDD_TDD_Description_struct_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority 829
#define CSN1_UTRAN_FDD_TDD_Description_struct_Repeated_UTRAN_FDD_TDD_Neighbour_Frequency_and_Priority_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Repeated_E_UTRAN_Not_Allowed_Cells 845
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Repeated_E_UTRAN_Not_Allowed_Cells_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Repeated_E_UTRAN_PCID_to_TA_mapping 846
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Repeated_E_UTRAN_PCID_to_TA_mapping_SIZE   0
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Measurement_Control_Parameters_Description 997
#define CSN1_E_UTRAN_Parameters_Description_struct_RR_E_UTRAN_Measurement_Control_Parameters_Description_SIZE   0
#define CSN1_E_UTRAN_Measurement_Control_Parameters_Description_struct_DEFAULT_Measurement_Control_E_UTRAN 998
#define CSN1_E_UTRAN_Measurement_Control_Parameters_Description_struct_DEFAULT_Measurement_Control_E_UTRAN_SIZE   1
#define CSN1_Enhanced_Cell_Reselection_Parameters_IE_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters 560
#define CSN1_Enhanced_Cell_Reselection_Parameters_IE_Repeated_E_UTRAN_Enhanced_Cell_Reselection_Parameters_SIZE   0
#define CSN1__3G_Supplementary_Parameters_Description_struct__3G_Measurement_Control_Parameters_Description 984
#define CSN1__3G_Supplementary_Parameters_Description_struct__3G_Measurement_Control_Parameters_Description_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_Serving_Cell_Priority_Parameters_Description 1300
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_Serving_Cell_Priority_Parameters_Description_SIZE  15
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_Repeated_Individual_UTRAN_Priority_Parameters 855
#define CSN1__3G_Individual_Priority_Parameters_Description_struct_Repeated_Individual_UTRAN_Priority_Parameters_SIZE   0
#define CSN1__3G_Measurement_Control_Parameters_Description_struct_Repeated_UTRAN_Measurement_Control_Parameters 986
#define CSN1__3G_Measurement_Control_Parameters_Description_struct_Repeated_UTRAN_Measurement_Control_Parameters_SIZE   0
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_UTRAN_Parameters_Description_for_the_Common_PLMN 1367
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_UTRAN_Parameters_Description_for_the_Common_PLMN_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Enhanced_Cell_Reselection_Parameters_Description 847
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Enhanced_Cell_Reselection_Parameters_Description_SIZE   0
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_E_UTRAN_Parameters_Description_for_the_Common_PLMN 1368
#define CSN1_IRAT_Cell_Reselection_Information_struct_Priority_and_E_UTRAN_Parameters_Description_for_the_Common_PLMN_SIZE   0
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority 838
#define CSN1_Priority_and_E_UTRAN_Parameters_Description_struct_37o_Repeated_E_UTRAN_Neighbour_Frequency_and_Priority_SIZE   0
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_Description_struct_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs 867
#define CSN1_E_UTRAN_IPP_with_extended_EARFCNs_Description_struct_Repeated_Individual_E_UTRAN_PP_with_extended_EARFCNs_SIZE   0
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_Repeated_Individual_E_UTRAN_Priority_Parameters 861
#define CSN1_E_UTRAN_Individual_Priority_Parameters_Description_struct_Repeated_Individual_E_UTRAN_Priority_Parameters_SIZE   0
#define CSN1_E_UTRAN_Measurement_Control_Parameters_Description_struct_Repeated_E_UTRAN_Measurement_Control_Parameters 999
#define CSN1_E_UTRAN_Measurement_Control_Parameters_Description_struct_Repeated_E_UTRAN_Measurement_Control_Parameters_SIZE   0


/* DEFINITIONS */
#define CSN1C_DEF_cell_barred            0
#define CSN1C_DEF_bit                    6
#define CSN1C_DEF_bit_string             8
#define CSN1C_DEF_spare_L               10
#define CSN1C_DEF_spare_bits            12
#define CSN1C_DEF_no_string             31
#define CSN1C_DEF_Compressed_Inter_RAT_HO_INFO_IND  32
#define CSN1C_DEF_Extension2            49
#define CSN1C_DEF_Band_indicator        50
#define CSN1C_DEF_SI_CHANGE_ALT         67
#define CSN1C_DEF_SYSTEM_INFORMATION_TYPE_10ter  84
#define CSN1C_DEF_la_different         104
#define CSN1C_DEF_spare_bit            120
#define CSN1C_DEF_octet                122
#define CSN1C_DEF_spare_padding        124
#define CSN1C_DEF_padding_bits         140
#define CSN1C_DEF_zero_padding         148
#define CSN1C_DEF_Group_Channel_Description 164
#define CSN1C_DEF_EC_Fixed_Uplink_Allocation_struct 206
#define CSN1C_DEF_Mobile_Identity_struct 325
#define CSN1C_DEF_GSM_Description_struct 362
#define CSN1C_DEF_UTRAN_FDD_Description_struct_CS 375
#define CSN1C_DEF_UTRAN_TDD_Description_struct_CS 434
#define CSN1C_DEF_DYNAMIC_ARFCN_MAPPING 493
#define CSN1C_DEF_Access_Technologies_Request_struct 510
#define CSN1C_DEF_IARRestOctets        530
#define CSN1C_DEF_NCELL_Report_struct  630
#define CSN1C_DEF_MultirateSpeechCfgCodec 643
#define CSN1C_DEF_List_of_Emergency_information 652
#define CSN1C_DEF_Dynamic_Allocation_struct 686
#define CSN1C_DEF_Additional_PFCs_struct_UP 1049
#define CSN1C_DEF_Additional_PFCs_struct_DN 1074
#define CSN1C_DEF_RTD6_Struct          1099
#define CSN1C_DEF_RTD12_Struct         1112
#define CSN1C_DEF__3G_Additional_Measurement_Parameters_Description_2_struct 1125
#define CSN1C_DEF_E_UTRAN_Measurement_Parameters_Description_struct 1142
#define CSN1C_DEF_UTRAN_CSG_Cells_Reporting_Description_struct 1361
#define CSN1C_DEF_Optional_Power_Offset 1398
#define CSN1C_DEF_Info_type            1415
#define CSN1C_DEF_Position             1445
#define CSN1C_DEF_VGCSCipheringParameters 1474
#define CSN1C_DEF_EC_Request_Reference_Description 1514
#define CSN1C_DEF_A5_CM3_bits          1523
#define CSN1C_DEF_RFL_number_list_struct 1540
#define CSN1C_DEF_ARFCN_index_list_struct 1560
#define CSN1C_DEF_Packet_Timing_Advance_IE 1580
#define CSN1C_DEF_Power_Control_Parameters_IE 1617
#define CSN1C_DEF_TMGI_IE              1750
#define CSN1C_DEF_PCID_Group_IE        1777
#define CSN1C_DEF_PLMN_ID_struct       1841
#define CSN1C_DEF_GPRS_Power_Control_Parameters_IE 1850
#define CSN1C_DEF_VBS_VGCS_RECONFIGURE_BODY 1871
#define CSN1C_DEF_UPLINK_FREE_BODY     1920
#define CSN1C_DEF_VGCS_ADDITIONAL_INFORMATION_BODY 1977
#define CSN1C_DEF_VGCS_SMS_INFORMATION_BODY 2010
#define CSN1C_DEF_NOTIFY_APPLICATION_DATA_BODY 2118
#define CSN1C_DEF_Group_Call_information 2177
#define CSN1C_DEF_EC_System_Information_Type_2 2197
#define CSN1C_DEF_EC_System_Information_Type_3 2602
#define CSN1C_DEF_EC_System_Information_Type_4 2842
#define CSN1C_DEF_BA_List_Pref         2950
#define CSN1C_DEF_UTRANFreqList        2987
#define CSN1C_DEF_E_UTRAN_Description_struct 3014
#define CSN1C_DEF_ChReqDesc2           3072
#define CSN1C_DEF_DTMInfoRestOctets    3209
#define CSN1C_DEF_DynamicARFCNMapping  3258
#define CSN1C_DEF_IAXRestOctets        3301
#define CSN1C_DEF_MultirateSpeechCfgIE 3326
#define CSN1C_DEF_P3RestOctets         3384
#define CSN1C_DEF_PacketChannelDescription 3563
#define CSN1C_DEF_Fixed_Allocation_struct 3636
#define CSN1C_DEF_RLC_Entity_Struct_UP 3792
#define CSN1C_DEF_RLC_Entity_Struct_DN 3827
#define CSN1C_DEF_Downlink_TBF_assignment_2_struct 3862
#define CSN1C_DEF_SI1RestOctets        3921
#define CSN1C_DEF_SI2bisRestOctets     3942
#define CSN1C_DEF_SI2terRestOctets     3951
#define CSN1C_DEF_UTRAN_FDD_Description_struct 4276
#define CSN1C_DEF_UTRAN_TDD_Description_struct 4336
#define CSN1C_DEF_Repeated_E_UTRAN_Not_Allowed_Cells_struct 4409
#define CSN1C_DEF_Repeated_E_UTRAN_PCID_to_TA_mapping_struct 4431
#define CSN1C_DEF__3G_CSG_Description_struct 4461
#define CSN1C_DEF_LSA_ID_information   4561
#define CSN1C_DEF_Positions            4595
#define CSN1C_DEF_COMPACT_Cell_Selection_struct 4614
#define CSN1C_DEF_SI18RestOctet        4763
#define CSN1C_DEF_SI14RestOctets       4816
#define CSN1C_DEF_SI15RestOctets       4848
#define CSN1C_DEF_SI21RestOctets       4880
#define CSN1C_DEF_SI22RestOctets       4915
#define CSN1C_DEF__3GTargetCell        5071
#define CSN1C_DEF_SI10bis_Neighbour_Cell_Info 5164
#define CSN1C_DEF_ECPacketChDescType1  5327
#define CSN1C_DEF_ECPacketChDescType2  5356
#define CSN1C_DEF_ECFixedUplinkAlloc   5381
#define CSN1C_DEF_RRClassmark3Value    5385
#define CSN1C_DEF_GPRS_Mobile_Allocation_IE 6116
#define CSN1C_DEF_MBMS_Sessions_List_IE 6208
#define CSN1C_DEF_Enhanced_Cell_Reselection_Parameters_IE 6242
#define CSN1C_DEF_UTRAN_CSG_Measurement_Report_IE 6335
#define CSN1C_DEF_NOTIFICATION_FACCH_BODY 6385
#define CSN1C_DEF_Enhanced_Measurement_report 6553
#define CSN1C_DEF_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY 6868
#define CSN1C_DEF_EC_System_Information_Type_1 6930
#define CSN1C_DEF_EC_IMMEDIATE_ASSIGNMENT_TYPE_2 7087
#define CSN1C_DEF_EC_IMMEDIATE_ASSIGNMENT_REJECT 7127
#define CSN1C_DEF_EC_DUMMY             7198
#define CSN1C_DEF_EC_PAGING_REQUEST    7205
#define CSN1C_DEF_EC_DOWNLINK_ASSIGNMENT 7258
#define CSN1C_DEF_CellSelIndAfterReleaseTCHandSDCCH 7347
#define CSN1C_DEF_IARestOctets         7482
#define CSN1C_DEF_MeasurementResults   8864
#define CSN1C_DEF_List_of_Group_Call_NCH_information 9021
#define CSN1C_DEF_SI2nRestOctets       9040
#define CSN1C_DEF_SI3RestOctet         9216
#define CSN1C_DEF_SI4_Rest_Octets_O    9413
#define CSN1C_DEF_SI4_Rest_Octets_S    9470
#define CSN1C_DEF_SI6RestOctet         9574
#define CSN1C_DEF_Priority_and_UTRAN_Parameters_Description_struct 9750
#define CSN1C_DEF_Priority_and_E_UTRAN_Parameters_Description_struct_37o 9959
#define CSN1C_DEF_SI10bis_Rest_Octets  10181
#define CSN1C_DEF_IndividualPriorities 10235
#define CSN1C_DEF_GPRS_Cell_Options_IE 10496
#define CSN1C_DEF_SYSTEM_INFORMATION_TYPE_10bis_BODY 10674
#define CSN1C_DEF_Measurement_information 10732
#define CSN1C_DEF_GPRSBCastInfo        12275
#define CSN1C_DEF_NTNRestOctets        12296
#define CSN1C_DEF_RRPktDownlinkAssi    12485
#define CSN1C_DEF_RRPacketDownlinkAssignmentType2 13087
#define CSN1C_DEF_SI4_Rest_Octets      13797
#define CSN1C_DEF_SI7_Rest_Octets      13838
#define CSN1C_DEF_SI8_Rest_Octets      13856
#define CSN1C_DEF_SI9RestOctets        13874
#define CSN1C_DEF_SI13RestOctets       13921
#define CSN1C_DEF_SI16RestOctet        14211
#define CSN1C_DEF_SI19RestOctets       14257
#define CSN1C_DEF_Frequency_Parameters_IE 14354
#define CSN1C_DEF_RRPacketUplinkAssignment 14489
#define CSN1C_DEF_SI2quaterRestOctets  16216
#define CSN1C_DEF_SI23RestOctets       18078
#define CSN1C_DEF_SI13altRestOctets    18198
#define CSN1C_DEF_IPARestOctets        18232
#define CSN1C_DEF_MBMS_Channel_Parameters_IE 18494
#define CSN1C_DEF_SYSTEM_INFORMATION_TYPE_10_BODY 18795
#define CSN1C_DEF_P1RestOctets         19029
#define CSN1C_DEF_P2RestOctets         19565
/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NOTIFICATION_FACCH_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NOTIFICATION_FACCH_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFICATION_FACCH_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NOTIFICATION_FACCH_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFICATION_FACCH_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "VBS_VGCS_RECONFIGURE_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VBS_VGCS_RECONFIGURE_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VBS_VGCS_RECONFIGURE_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VBS_VGCS_RECONFIGURE_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VBS_VGCS_RECONFIGURE_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UPLINK_FREE_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UPLINK_FREE_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_FREE_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UPLINK_FREE_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_FREE_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "VGCS_ADDITIONAL_INFORMATION_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VGCS_ADDITIONAL_INFORMATION_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VGCS_ADDITIONAL_INFORMATION_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VGCS_ADDITIONAL_INFORMATION_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VGCS_ADDITIONAL_INFORMATION_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "VGCS_SMS_INFORMATION_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VGCS_SMS_INFORMATION_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VGCS_SMS_INFORMATION_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VGCS_SMS_INFORMATION_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VGCS_SMS_INFORMATION_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SYSTEM_INFORMATION_TYPE_10_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SYSTEM_INFORMATION_TYPE_10_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SYSTEM_INFORMATION_TYPE_10_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SYSTEM_INFORMATION_TYPE_10_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SYSTEM_INFORMATION_TYPE_10_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SYSTEM_INFORMATION_TYPE_10bis_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SYSTEM_INFORMATION_TYPE_10bis_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SYSTEM_INFORMATION_TYPE_10bis_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SYSTEM_INFORMATION_TYPE_10bis_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SYSTEM_INFORMATION_TYPE_10bis_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SYSTEM_INFORMATION_TYPE_10ter".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SYSTEM_INFORMATION_TYPE_10ter (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SYSTEM_INFORMATION_TYPE_10ter* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SYSTEM_INFORMATION_TYPE_10ter (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SYSTEM_INFORMATION_TYPE_10ter* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Measurement_information".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Measurement_information (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Measurement_information* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Measurement_information (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Measurement_information* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Enhanced_Measurement_report".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Enhanced_Measurement_report (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Enhanced_Measurement_report* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Enhanced_Measurement_report (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Enhanced_Measurement_report* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "VGCS_NEIGHBOUR_CELL_INFORMATION_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VGCS_NEIGHBOUR_CELL_INFORMATION_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NOTIFY_APPLICATION_DATA_BODY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NOTIFY_APPLICATION_DATA_BODY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFY_APPLICATION_DATA_BODY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NOTIFY_APPLICATION_DATA_BODY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFY_APPLICATION_DATA_BODY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Group_Call_information".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Group_Call_information (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Group_Call_information* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Group_Call_information (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Group_Call_information* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_System_Information_Type_1".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_System_Information_Type_1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_System_Information_Type_1* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_System_Information_Type_1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_System_Information_Type_1* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_System_Information_Type_2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_System_Information_Type_2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_System_Information_Type_2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_System_Information_Type_2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_System_Information_Type_2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_System_Information_Type_3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_System_Information_Type_3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_System_Information_Type_3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_System_Information_Type_3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_System_Information_Type_3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_System_Information_Type_4".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_System_Information_Type_4 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_System_Information_Type_4* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_System_Information_Type_4 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_System_Information_Type_4* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_IMMEDIATE_ASSIGNMENT_TYPE_2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_IMMEDIATE_ASSIGNMENT_TYPE_2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_IMMEDIATE_ASSIGNMENT_TYPE_2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_IMMEDIATE_ASSIGNMENT_TYPE_2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_IMMEDIATE_ASSIGNMENT_TYPE_2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_IMMEDIATE_ASSIGNMENT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_IMMEDIATE_ASSIGNMENT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_IMMEDIATE_ASSIGNMENT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_IMMEDIATE_ASSIGNMENT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_IMMEDIATE_ASSIGNMENT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_DUMMY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_DUMMY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_DUMMY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_DUMMY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_DUMMY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_PAGING_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_PAGING_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_PAGING_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_PAGING_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_PAGING_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_DOWNLINK_ASSIGNMENT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_DOWNLINK_ASSIGNMENT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_DOWNLINK_ASSIGNMENT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_DOWNLINK_ASSIGNMENT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_DOWNLINK_ASSIGNMENT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "BA_List_Pref".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BA_List_Pref (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BA_List_Pref* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BA_List_Pref (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BA_List_Pref* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UTRANFreqList".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UTRANFreqList (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UTRANFreqList* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UTRANFreqList (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UTRANFreqList* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CellSelIndAfterReleaseTCHandSDCCH".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CellSelIndAfterReleaseTCHandSDCCH (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CellSelIndAfterReleaseTCHandSDCCH* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CellSelIndAfterReleaseTCHandSDCCH (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CellSelIndAfterReleaseTCHandSDCCH* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ChReqDesc2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ChReqDesc2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ChReqDesc2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ChReqDesc2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ChReqDesc2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DTMInfoRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DTMInfoRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DTMInfoRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DTMInfoRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DTMInfoRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DynamicARFCNMapping".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DynamicARFCNMapping (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DynamicARFCNMapping* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DynamicARFCNMapping (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DynamicARFCNMapping* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GPRSBCastInfo".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GPRSBCastInfo (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GPRSBCastInfo* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GPRSBCastInfo (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GPRSBCastInfo* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IARestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IARestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IARestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IARestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IARestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IARRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IARRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IARRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IARRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IARRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IAXRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IAXRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IAXRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IAXRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IAXRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MeasurementResults".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MeasurementResults (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MeasurementResults* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MeasurementResults (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MeasurementResults* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NCELL_Report_struct".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NCELL_Report_struct (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NCELL_Report_struct* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NCELL_Report_struct (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NCELL_Report_struct* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MultirateSpeechCfgIE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MultirateSpeechCfgIE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MultirateSpeechCfgIE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MultirateSpeechCfgIE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MultirateSpeechCfgIE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NTNRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NTNRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NTNRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NTNRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NTNRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "P1RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P1RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P1RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P1RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P1RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "P2RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P2RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P2RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P2RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P2RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "P3RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P3RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P3RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P3RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P3RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PacketChannelDescription".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PacketChannelDescription (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PacketChannelDescription* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PacketChannelDescription (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PacketChannelDescription* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RRPacketUplinkAssignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRPacketUplinkAssignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRPacketUplinkAssignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRPacketUplinkAssignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRPacketUplinkAssignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Dynamic_Allocation_struct".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Dynamic_Allocation_struct (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Dynamic_Allocation_struct* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Dynamic_Allocation_struct (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Dynamic_Allocation_struct* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Fixed_Allocation_struct".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Fixed_Allocation_struct (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Fixed_Allocation_struct* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Fixed_Allocation_struct (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Fixed_Allocation_struct* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RRPktDownlinkAssi".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRPktDownlinkAssi (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRPktDownlinkAssi* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRPktDownlinkAssi (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRPktDownlinkAssi* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RRPacketDownlinkAssignmentType2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRPacketDownlinkAssignmentType2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRPacketDownlinkAssignmentType2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRPacketDownlinkAssignmentType2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRPacketDownlinkAssignmentType2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI1RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI1RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI1RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI1RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI1RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI2bisRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI2bisRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI2bisRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI2bisRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI2bisRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI2terRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI2terRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI2terRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI2terRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI2terRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI2quaterRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI2quaterRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI2quaterRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI2quaterRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI2quaterRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI2nRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI2nRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI2nRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI2nRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI2nRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI3RestOctet".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI3RestOctet (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI3RestOctet* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI3RestOctet (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI3RestOctet* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI4_Rest_Octets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI4_Rest_Octets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI4_Rest_Octets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI4_Rest_Octets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI4_Rest_Octets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI7_Rest_Octets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI7_Rest_Octets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI7_Rest_Octets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI7_Rest_Octets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI7_Rest_Octets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI8_Rest_Octets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI8_Rest_Octets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI8_Rest_Octets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI8_Rest_Octets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI8_Rest_Octets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI6RestOctet".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI6RestOctet (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI6RestOctet* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI6RestOctet (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI6RestOctet* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI9RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI9RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI9RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI9RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI9RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI13RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI13RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI13RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI13RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI13RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI_CHANGE_ALT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI_CHANGE_ALT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI_CHANGE_ALT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI_CHANGE_ALT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI_CHANGE_ALT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI16RestOctet".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI16RestOctet (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI16RestOctet* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI16RestOctet (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI16RestOctet* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI19RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI19RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI19RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI19RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI19RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI18RestOctet".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI18RestOctet (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI18RestOctet* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI18RestOctet (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI18RestOctet* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI14RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI14RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI14RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI14RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI14RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI15RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI15RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI15RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI15RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI15RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI13altRestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI13altRestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI13altRestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI13altRestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI13altRestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI21RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI21RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI21RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI21RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI21RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI22RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI22RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI22RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI22RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI22RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI23RestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI23RestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI23RestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI23RestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI23RestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "VGCSCipheringParameters".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_VGCSCipheringParameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_VGCSCipheringParameters* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_VGCSCipheringParameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_VGCSCipheringParameters* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "_3GTargetCell".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c__3GTargetCell (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c__3GTargetCell* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c__3GTargetCell (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c__3GTargetCell* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SI10bis_Rest_Octets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SI10bis_Rest_Octets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SI10bis_Rest_Octets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SI10bis_Rest_Octets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SI10bis_Rest_Octets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IndividualPriorities".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IndividualPriorities (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IndividualPriorities* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IndividualPriorities (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IndividualPriorities* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IPARestOctets".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IPARestOctets (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IPARestOctets* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IPARestOctets (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IPARestOctets* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Request_Reference_Description".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Request_Reference_Description (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Request_Reference_Description* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Request_Reference_Description (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Request_Reference_Description* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ECPacketChDescType1".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ECPacketChDescType1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ECPacketChDescType1* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ECPacketChDescType1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ECPacketChDescType1* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ECPacketChDescType2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ECPacketChDescType2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ECPacketChDescType2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ECPacketChDescType2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ECPacketChDescType2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ECFixedUplinkAlloc".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ECFixedUplinkAlloc (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ECFixedUplinkAlloc* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ECFixedUplinkAlloc (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ECFixedUplinkAlloc* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RRClassmark3Value".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RRClassmark3Value (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RRClassmark3Value* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RRClassmark3Value (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RRClassmark3Value* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

