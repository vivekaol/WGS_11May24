/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __CSN1DataTypes_EC_PACCH_h
#define __CSN1DataTypes_EC_PACCH_h
/* ZZZ */

#include "csn1clib.h"
#include "ed_lib.h"
#include "ed_c_EC_PACCH.h"
#include "ed_user.h"
#include "endec_configs_EC_PACCH.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

extern TCSN1CProgram Program_EC_PACCH_Program;


#ifdef CSN1C_LABEL_NAMES
/* List of label names */
extern const char* const Program_EC_PACCH_Labels [];
#endif

/* LABELS */

#define CSN1_EC_Reject_struct_Ignore   121
#define CSN1_EC_Reject_struct_Ignore_SIZE   0
#define CSN1_Global_TFI_IE_UPLINK_TFI    8
#define CSN1_Global_TFI_IE_UPLINK_TFI_SIZE   5
#define CSN1_Global_TFI_IE_DOWNLINK_TFI   9
#define CSN1_Global_TFI_IE_DOWNLINK_TFI_SIZE   5
#define CSN1_EC_Reject_struct_Downlink_TFI   0
#define CSN1_EC_Reject_struct_Downlink_TFI_SIZE   5
#define CSN1_Frequency_Parameters_struct_TSC   6
#define CSN1_Frequency_Parameters_struct_TSC_SIZE   3
#define CSN1_EC_Reject_struct_WAIT_INDICATION   1
#define CSN1_EC_Reject_struct_WAIT_INDICATION_SIZE   8
#define CSN1_EC_Channel_Quality_Report_IE_C_VALUE  28
#define CSN1_EC_Channel_Quality_Report_IE_C_VALUE_SIZE   6
#define CSN1_EC_Reject_struct_WAIT__INDICATION_SIZE   2
#define CSN1_EC_Reject_struct_WAIT__INDICATION_SIZE_SIZE   1
#define CSN1_EC_Channel_Quality_Report_IE_GMSK_CV_BEP  25
#define CSN1_EC_Channel_Quality_Report_IE_GMSK_CV_BEP_SIZE   3
#define CSN1_Frequency_Parameters_struct_EC_MA_NUMBER   5
#define CSN1_Frequency_Parameters_struct_EC_MA_NUMBER_SIZE   5
#define CSN1_EC_Channel_Quality_Report_IE__8PSK_CV_BEP  27
#define CSN1_EC_Channel_Quality_Report_IE__8PSK_CV_BEP_SIZE   3
#define CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme  83
#define CSN1_EGPRS_Modulation_and_coding_Scheme_Scheme_SIZE   4
#define CSN1_EC_Channel_Quality_Report_IE_GMSK_MEAN_BEP  24
#define CSN1_EC_Channel_Quality_Report_IE_GMSK_MEAN_BEP_SIZE   5
#define CSN1_EC_Channel_Quality_Report_IE__8PSK_MEAN_BEP  26
#define CSN1_EC_Channel_Quality_Report_IE__8PSK_MEAN_BEP_SIZE   5
#define CSN1_Frequency_Parameters_struct_Primary_TSC_Set   7
#define CSN1_Frequency_Parameters_struct_Primary_TSC_Set_SIZE   1
#define CSN1_EC_Channel_Request_Description_struct_PRIORITY  31
#define CSN1_EC_Channel_Request_Description_struct_PRIORITY_SIZE   1
#define CSN1_EC_Packet_Access_Reject_message_content_Reject  15
#define CSN1_EC_Packet_Access_Reject_message_content_Reject_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_P0 108
#define CSN1_EC_Packet_Uplink_Assignment_message_content_P0_SIZE   4
#define CSN1_PUAN_Fixed_Uplink_Allocation_struct_BSN_OFFSET  78
#define CSN1_PUAN_Fixed_Uplink_Allocation_struct_BSN_OFFSET_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_GAMMA  93
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_GAMMA_SIZE   5
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_T3238  89
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_T3238_SIZE   3
#define CSN1_EC_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP  11
#define CSN1_EC_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP_SIZE  16
#define CSN1_EC_Packet_Downlink_Assignment_message_content_P0  45
#define CSN1_EC_Packet_Downlink_Assignment_message_content_P0_SIZE   4
#define CSN1_EC_Packet_TBF_Release_message_content_GLOBAL_TFI  59
#define CSN1_EC_Packet_TBF_Release_message_content_GLOBAL_TFI_SIZE   6
#define CSN1_EC_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE  44
#define CSN1_EC_Packet_Timing_Advance_IE_TIMING_ADVANCE_VALUE_SIZE   6
#define CSN1_EC_Packet_Uplink_Assignment_message_content_GAMMA 110
#define CSN1_EC_Packet_Uplink_Assignment_message_content_GAMMA_SIZE   5
#define CSN1_EC_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER  10
#define CSN1_EC_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER_SIZE   5
#define CSN1_EC_Packet_Downlink_Assignment_message_content_GAMMA  47
#define CSN1_EC_Packet_Downlink_Assignment_message_content_GAMMA_SIZE   5
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_RESEGMENT  81
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_RESEGMENT_SIZE   1
#define CSN1_EC_Packet_Uplink_Assignment_message_content_PR_MODE 109
#define CSN1_EC_Packet_Uplink_Assignment_message_content_PR_MODE_SIZE   1
#define CSN1_EC_Packet_Polling_Request_message_content_Global_TFI  51
#define CSN1_EC_Packet_Polling_Request_message_content_Global_TFI_SIZE   6
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI  72
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UPLINK_TFI_SIZE   5
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DL_CC_EST  29
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DL_CC_EST_SIZE   4
#define CSN1_EC_Packet_Downlink_Assignment_message_content_PR_MODE  46
#define CSN1_EC_Packet_Downlink_Assignment_message_content_PR_MODE_SIZE   1
#define CSN1_EC_Packet_Polling_Request_message_content_TYPE_OF_ACK  52
#define CSN1_EC_Packet_Polling_Request_message_content_TYPE_OF_ACK_SIZE   1
#define CSN1_EC_Packet_TBF_Release_message_content_WAIT_INDICATION  61
#define CSN1_EC_Packet_TBF_Release_message_content_WAIT_INDICATION_SIZE   8
#define CSN1_EC_Packet_Control_Acknowledgement_message_content_TLLI  17
#define CSN1_EC_Packet_Control_Acknowledgement_message_content_TLLI_SIZE  32
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_ALPHA_Enable  94
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_ALPHA_Enable_SIZE   1
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Global_TFI  96
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_EC_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE  60
#define CSN1_EC_Packet_TBF_Release_message_content_TBF_RELEASE_CAUSE_SIZE   4
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI  20
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_DOWNLINK_TFI_SIZE   5
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Global_TFI  34
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Global_TFI_SIZE   6
#define CSN1_EC_Packet_Polling_Request_message_content_Message_escape 130
#define CSN1_EC_Packet_Polling_Request_message_content_Message_escape_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_ALPHA_Enable 111
#define CSN1_EC_Packet_Uplink_Assignment_message_content_ALPHA_Enable_SIZE   1
#define CSN1_EC_Primary_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP  13
#define CSN1_EC_Primary_Ack_Nack_Description_IE_RECEIVED_BLOCK_BITMAP_SIZE   8
#define CSN1_EC_Packet_Access_Reject_message_content_Additional_Reject  16
#define CSN1_EC_Packet_Access_Reject_message_content_Additional_Reject_SIZE   0
#define CSN1_EC_Packet_Downlink_Assignment_message_content_CONTROL_ACK  35
#define CSN1_EC_Packet_Downlink_Assignment_message_content_CONTROL_ACK_SIZE   1
#define CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_DL_CC_EST   4
#define CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_DL_CC_EST_SIZE   4
#define CSN1_EC_Packet_Control_Acknowledgement_message_content_CTRL_ACK  18
#define CSN1_EC_Packet_Control_Acknowledgement_message_content_CTRL_ACK_SIZE   2
#define CSN1_EC_Packet_Downlink_Assignment_message_content_ALPHA_Enable  48
#define CSN1_EC_Packet_Downlink_Assignment_message_content_ALPHA_Enable_SIZE   1
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Message_escape 146
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_EC_Packet_Control_Acknowledgement_message_content_DL_CC_EST  19
#define CSN1_EC_Packet_Control_Acknowledgement_message_content_DL_CC_EST_SIZE   4
#define CSN1_EC_Packet_TBF_Release_message_content_WAIT__INDICATION_SIZE  62
#define CSN1_EC_Packet_TBF_Release_message_content_WAIT__INDICATION_SIZE_SIZE   1
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_DL_COVERAGE_CLASS  86
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UL_COVERAGE_CLASS  84
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_UL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Primary_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER  12
#define CSN1_EC_Primary_Ack_Nack_Description_IE_STARTING_SEQUENCE_NUMBER_SIZE   5
#define CSN1_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK 107
#define CSN1_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK_SIZE   3
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY  21
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_MS_OUT_OF_MEMORY_SIZE   1
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Message_escape 125
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Message_escape_SIZE   0
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_GAMMA  57
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_GAMMA_SIZE   5
#define CSN1_EC_Packet_TBF_Release_message_content_USED_DL_COVERAGE_CLASS  58
#define CSN1_EC_Packet_TBF_Release_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK 106
#define CSN1_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK_SIZE   4
#define CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_MESSAGE_TYPE   3
#define CSN1_EC_Packet_Control_Acknowledgement_11_bit_message_MESSAGE_TYPE_SIZE   7
#define CSN1_EC_Packet_TBF_Release_message_content_Distribution_part_error 137
#define CSN1_EC_Packet_TBF_Release_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_DL_COVERAGE_CLASS 112
#define CSN1_EC_Packet_Uplink_Assignment_message_content_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Uplink_Assignment_message_content_UL_COVERAGE_CLASS 102
#define CSN1_EC_Packet_Uplink_Assignment_message_content_UL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Channel_Request_Description_struct_NUMBER_OF_UL_DATA_BLOCKS  32
#define CSN1_EC_Channel_Request_Description_struct_NUMBER_OF_UL_DATA_BLOCKS_SIZE   4
#define CSN1_EC_Packet_Access_Reject_message_content_USED_DL_COVERAGE_CLASS  14
#define CSN1_EC_Packet_Access_Reject_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_T_AVG_T  55
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_T_AVG_T_SIZE   5
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Initial_Waiting_Time  90
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Initial_Waiting_Time_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_UL_TIMESLOT  85
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_UL_TIMESLOT_SIZE   3
#define CSN1_EC_Packet_Uplink_Assignment_message_content_OVERLAID_CDMA_CODE  99
#define CSN1_EC_Packet_Uplink_Assignment_message_content_OVERLAID_CDMA_CODE_SIZE   2
#define CSN1_EC_Packet_Access_Reject_message_content_Distribution_part_error 122
#define CSN1_EC_Packet_Access_Reject_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Downlink_Assignment_message_content_DL_COVERAGE_CLASS  37
#define CSN1_EC_Packet_Downlink_Assignment_message_content_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Downlink_Assignment_message_content_UL_COVERAGE_CLASS  41
#define CSN1_EC_Packet_Downlink_Assignment_message_content_UL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Polling_Request_message_content_USED_DL_COVERAGE_CLASS  50
#define CSN1_EC_Packet_Polling_Request_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_TIMESLOT_MULTIPLICATOR  88
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_TIMESLOT_MULTIPLICATOR_SIZE   3
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_USED_DL_COVERAGE_CLASS  71
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters 101
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Frequency_Parameters_SIZE   9
#define CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_UL_TIMESLOT 103
#define CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_UL_TIMESLOT_SIZE   3
#define CSN1_PUAN_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK  80
#define CSN1_PUAN_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK_SIZE   3
#define CSN1_EC_Packet_Polling_Request_message_content_Distribution_part_error 131
#define CSN1_EC_Packet_Polling_Request_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI  54
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Global_TFI_SIZE   6
#define CSN1_EC_Packet_TBF_Release_message_content_Non_distribution_part_error 135
#define CSN1_EC_Packet_TBF_Release_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error 143
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description  76
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Ack_Nack_Description_SIZE  21
#define CSN1_EC_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT  97
#define CSN1_EC_Packet_Uplink_Assignment_message_content_UPLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_PUAN_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK  79
#define CSN1_PUAN_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK_SIZE   4
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters  36
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Frequency_Parameters_SIZE   9
#define CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_DL_TIMESLOT  38
#define CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_DL_TIMESLOT_SIZE   3
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance  92
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Packet_Timing_Advance_SIZE   6
#define CSN1_EC_Packet_Uplink_Assignment_message_content_TIMESLOT_MULTIPLICATOR 104
#define CSN1_EC_Packet_Uplink_Assignment_message_content_TIMESLOT_MULTIPLICATOR_SIZE   3
#define CSN1_EC_Packet_Uplink_Assignment_message_content_USED_DL_COVERAGE_CLASS  95
#define CSN1_EC_Packet_Uplink_Assignment_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_PUANCR_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK  69
#define CSN1_PUANCR_Fixed_Uplink_Allocation_struct_DELAY_NEXT_UL_RLC_DATA_BLOCK_SIZE   3
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description  22
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Ack_Nack_Description_SIZE  21
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error 147
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation 105
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Fixed_Uplink_Allocation_SIZE   0
#define CSN1_PUANCR_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK  68
#define CSN1_PUANCR_Fixed_Uplink_Allocation_struct_START_FIRST_UL_RLC_DATA_BLOCK_SIZE   4
#define CSN1_EC_Packet_Downlink_Assignment_message_content_TIMESLOT_MULTIPLICATOR  39
#define CSN1_EC_Packet_Downlink_Assignment_message_content_TIMESLOT_MULTIPLICATOR_SIZE   3
#define CSN1_EC_Packet_Downlink_Assignment_message_content_USED_DL_COVERAGE_CLASS  33
#define CSN1_EC_Packet_Downlink_Assignment_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_TBF_Release_message_content_Address_information_part_error 136
#define CSN1_EC_Packet_TBF_Release_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI  73
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_TLLI_SIZE  32
#define CSN1_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance 100
#define CSN1_EC_Packet_Uplink_Assignment_message_content_EC_Packet_Timing_Advance_SIZE   6
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report  23
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Quality_Report_SIZE   0
#define CSN1_EC_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT  40
#define CSN1_EC_Packet_Downlink_Assignment_message_content_DOWNLINK_TFI_ASSIGNMENT_SIZE   5
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error 126
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Polling_Request_message_content_Non_distribution_part_error 128
#define CSN1_EC_Packet_Polling_Request_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_rTLLI  75
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_CONTENTION_RESOLUTION_rTLLI_SIZE   4
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_PACCH_Monitoring_Pattern  91
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_PACCH_Monitoring_Pattern_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error 141
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_DL_TIMESLOT_OFFSET  87
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_STARTING_DL_TIMESLOT_OFFSET_SIZE   2
#define CSN1_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance  43
#define CSN1_EC_Packet_Downlink_Assignment_message_content_EC_Packet_Timing_Advance_SIZE   6
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command  82
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation  77
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_PUAN_Fixed_Uplink_Allocation_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error 144
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_DL_TIMESLOT_OFFSET 113
#define CSN1_EC_Packet_Uplink_Assignment_message_content_STARTING_DL_TIMESLOT_OFFSET_SIZE   2
#define CSN1_EC_Packet_Polling_Request_message_content_Address_information_part_error 129
#define CSN1_EC_Packet_Polling_Request_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error 142
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command  98
#define CSN1_EC_Packet_Uplink_Assignment_message_content_EGPRS_Channel_Coding_Command_SIZE   4
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error 123
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_UL_TIMESLOT_OFFSET  42
#define CSN1_EC_Packet_Downlink_Assignment_message_content_STARTING_UL_TIMESLOT_OFFSET_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description  74
#define CSN1_EC_Packet_Uplink_Ack_Nack_message_content_EC_Primary_Ack_Nack_Description_SIZE  13
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description  30
#define CSN1_EC_Packet_Downlink_Ack_Nack_message_content_EC_Channel_Request_Description_SIZE   5
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error 145
#define CSN1_EC_Packet_Uplink_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error 124
#define CSN1_EC_Packet_Downlink_Assignment_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_USED_DL_COVERAGE_CLASS  49
#define CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_USED_DL_COVERAGE_CLASS  53
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_RESEGMENT  70
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_RESEGMENT_SIZE   1
#define CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error 127
#define CSN1_EC_Packet_Downlink_Dummy_Control_Block_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error 134
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_UPLINK_TFI  64
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_UPLINK_TFI_SIZE   5
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance  56
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_EC_Packet_Timing_Advance_SIZE   6
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error 132
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error 133
#define CSN1_EC_Packet_Power_Control_Timing_Advance_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_USED_DL_COVERAGE_CLASS  63
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_USED_DL_COVERAGE_CLASS_SIZE   2
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error 140
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_CONTENTION_RESOLUTION_TLLI  65
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_CONTENTION_RESOLUTION_TLLI_SIZE  32
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error 138
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Non_distribution_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error 139
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_Address_information_part_error_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation  67
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_PUANCR_Fixed_Uplink_Allocation_SIZE   0
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description  66
#define CSN1_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content_EC_Primary_Ack_Nack_Description_SIZE  13


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
#define CSN1C_DEF_EC_Reject_struct      50
#define CSN1C_DEF_EC_Packet_Control_Acknowledgement_11_bit_message  99
#define CSN1C_DEF_Frequency_Parameters_struct 114
#define CSN1C_DEF_Global_TFI_IE        124
#define CSN1C_DEF_EC_Ack_Nack_Description_IE 141
#define CSN1C_DEF_EC_Primary_Ack_Nack_Description_IE 148
#define CSN1C_DEF_EC_Packet_Access_Reject_message_content 155
#define CSN1C_DEF_EC_Packet_Control_Acknowledgement_message_content 224
#define CSN1C_DEF_EC_Packet_Downlink_Ack_Nack_message_content 242
#define CSN1C_DEF_EC_Packet_Downlink_Assignment_message_content 371
#define CSN1C_DEF_EC_Packet_Downlink_Dummy_Control_Block_message_content 629
#define CSN1C_DEF_EC_Packet_Polling_Request_message_content 670
#define CSN1C_DEF_EC_Packet_Power_Control_Timing_Advance_message_content 808
#define CSN1C_DEF_EC_Packet_TBF_Release_message_content 969
#define CSN1C_DEF_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content 1124
#define CSN1C_DEF_EC_Packet_Uplink_Ack_Nack_message_content 1278
#define CSN1C_DEF_EC_Packet_Uplink_Assignment_message_content 1634
/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Access_Reject_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Access_Reject_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Access_Reject_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Access_Reject_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Access_Reject_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Control_Acknowledgement_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Control_Acknowledgement_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Control_Acknowledgement_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Control_Acknowledgement_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Control_Acknowledgement_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Control_Acknowledgement_11_bit_message".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Control_Acknowledgement_11_bit_message (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Control_Acknowledgement_11_bit_message* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Control_Acknowledgement_11_bit_message (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Control_Acknowledgement_11_bit_message* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Downlink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Downlink_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Downlink_Dummy_Control_Block_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Dummy_Control_Block_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Dummy_Control_Block_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Polling_Request_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Polling_Request_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Polling_Request_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Polling_Request_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Polling_Request_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Power_Control_Timing_Advance_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Power_Control_Timing_Advance_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Power_Control_Timing_Advance_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Power_Control_Timing_Advance_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Power_Control_Timing_Advance_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_TBF_Release_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_TBF_Release_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_TBF_Release_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_TBF_Release_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_TBF_Release_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Uplink_Ack_Nack_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Ack_Nack_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Ack_Nack_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Uplink_Assignment_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Assignment_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Assignment_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Assignment_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Assignment_message_content* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

