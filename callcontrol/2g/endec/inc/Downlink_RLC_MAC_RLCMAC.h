/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __Downlink_RLC_MAC_RLCMAC_h
#define __Downlink_RLC_MAC_RLCMAC_h
/* ZZZ */

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

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Order".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Order (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Order* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Order (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Order* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Cell_Change_Order".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Cell_Change_Order (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Order* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Cell_Change_Order (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Order* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Downlink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Downlink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Downlink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Downlink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Downlink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Downlink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Measurement_Order".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Measurement_Order (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Measurement_Order* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Measurement_Order (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Measurement_Order* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Measurement_Order".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Measurement_Order (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Measurement_Order* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Measurement_Order (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Measurement_Order* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Polling_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Polling_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Polling_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Polling_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Polling_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Polling_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Polling_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Polling_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Polling_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Polling_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Power_Control_Timing_Advance".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Power_Control_Timing_Advance (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Power_Control_Timing_Advance* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Power_Control_Timing_Advance (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Power_Control_Timing_Advance* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Power_Control_Timing_Advance".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Power_Control_Timing_Advance (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Power_Control_Timing_Advance* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Power_Control_Timing_Advance (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Power_Control_Timing_Advance* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Queueing_Notification".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Queueing_Notification (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Queueing_Notification* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Queueing_Notification (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Queueing_Notification* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Queueing_Notification".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Queueing_Notification (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Queueing_Notification* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Queueing_Notification (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Queueing_Notification* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Timeslot_Reconfigure".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Timeslot_Reconfigure (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Timeslot_Reconfigure* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Timeslot_Reconfigure (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Timeslot_Reconfigure* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Timeslot_Reconfigure".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Timeslot_Reconfigure (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Timeslot_Reconfigure* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Timeslot_Reconfigure (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Timeslot_Reconfigure* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_TBF_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_TBF_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_TBF_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_TBF_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_TBF_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_TBF_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_TBF_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_TBF_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_TBF_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_TBF_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Uplink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Uplink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Uplink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Uplink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Uplink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Uplink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Uplink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Uplink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Uplink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Uplink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Uplink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Uplink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Continue".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Continue (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Continue* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Continue (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Continue* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Cell_Change_Continue".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Cell_Change_Continue (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Continue* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Cell_Change_Continue (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Continue* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Neighbour_Cell_Data".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Neighbour_Cell_Data (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Neighbour_Cell_Data* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Neighbour_Cell_Data (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Neighbour_Cell_Data* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Neighbour_Cell_Data".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Neighbour_Cell_Data (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Neighbour_Cell_Data* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Neighbour_Cell_Data (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Neighbour_Cell_Data* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Serving_Cell_Data".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Serving_Cell_Data (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Serving_Cell_Data* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Serving_Cell_Data (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Serving_Cell_Data* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Serving_Cell_Data".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Serving_Cell_Data (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Serving_Cell_Data* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Serving_Cell_Data (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Serving_Cell_Data* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_DBPSCH_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_DBPSCH_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_DBPSCH_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_DBPSCH_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_DBPSCH_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_DBPSCH_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_DBPSCH_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_DBPSCH_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_DBPSCH_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_DBPSCH_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Multiple_TBF_Downlink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Multiple_TBF_Downlink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Downlink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Multiple_TBF_Downlink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Downlink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Multiple_TBF_Downlink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Multiple_TBF_Downlink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Downlink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Multiple_TBF_Downlink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Downlink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Access_Reject".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Access_Reject (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Access_Reject* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Access_Reject (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Access_Reject* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Access_Reject".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Access_Reject (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Access_Reject* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Access_Reject (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Access_Reject* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Paging_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Paging_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Paging_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Paging_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Paging_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Paging_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Paging_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Paging_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Paging_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Paging_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_PDCH_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_PDCH_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PDCH_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_PDCH_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PDCH_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_PDCH_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_PDCH_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PDCH_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_PDCH_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PDCH_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_PRACH_Parameters".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_PRACH_Parameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PRACH_Parameters* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_PRACH_Parameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PRACH_Parameters* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_PRACH_Parameters".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_PRACH_Parameters (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PRACH_Parameters* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_PRACH_Parameters (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PRACH_Parameters* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Downlink_Dummy_Control_Block".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Downlink_Dummy_Control_Block (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Dummy_Control_Block* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Downlink_Dummy_Control_Block (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Dummy_Control_Block* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Downlink_Dummy_Control_Block".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Downlink_Dummy_Control_Block (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Dummy_Control_Block* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Downlink_Dummy_Control_Block (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Dummy_Control_Block* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI16".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI16 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI16* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI16 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI16* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI16".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI16 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI16* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI16 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI16* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI6".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI6 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI6* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI6 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI6* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI6".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI6 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI6* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI6 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI6* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI1".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI1* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI1* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI1".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI1 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI1* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI1 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI1* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI2".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI2 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI2* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI2 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI2* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_bis".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_bis (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_bis* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_bis (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_bis* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI3_bis".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI3_bis (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_bis* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI3_bis (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_bis* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI4".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI4 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI4* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI4 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI4* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI4".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI4 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI4* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI4 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI4* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI5".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI5 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI5* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI5 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI5* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI5".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI5 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI5* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI5 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI5* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI13".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI13 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI13* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI13 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI13* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI13".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI13 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI13* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI13 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI13* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI7".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI7 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI7* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI7 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI7* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI7".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI7 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI7* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI7 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI7* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI8".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI8 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI8* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI8 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI8* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI8".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI8 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI8* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI8 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI8* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI14".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI14 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI14* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI14 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI14* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI14".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI14 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI14* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI14 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI14* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_ter".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_ter (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_ter* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_ter (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_ter* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI3_ter".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI3_ter (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_ter* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI3_ter (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_ter* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI3_quater".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI3_quater (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_quater* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI3_quater (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_quater* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI3_quater".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI3_quater (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI3_quater* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI3_quater (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI3_quater* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PSI15".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PSI15 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI15* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PSI15 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI15* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PSI15".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PSI15 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PSI15* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PSI15 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PSI15* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Multiple_TBF_Uplink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Multiple_TBF_Uplink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Uplink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Multiple_TBF_Uplink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Uplink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Multiple_TBF_Uplink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Multiple_TBF_Uplink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Uplink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Multiple_TBF_Uplink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Uplink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Multiple_TBF_Timeslot_Reconfigure".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Multiple_TBF_Timeslot_Reconfigure (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Timeslot_Reconfigure* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Multiple_TBF_Timeslot_Reconfigure (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Timeslot_Reconfigure* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Multiple_TBF_Timeslot_Reconfigure".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Multiple_TBF_Timeslot_Reconfigure (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Multiple_TBF_Timeslot_Reconfigure* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Multiple_TBF_Timeslot_Reconfigure (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Multiple_TBF_Timeslot_Reconfigure* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_MS_ID_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_MS_ID_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_MS_ID_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_MS_ID_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_MS_ID_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MBMS_MS_ID_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MBMS_MS_ID_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_MS_ID_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MBMS_MS_ID_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_MS_ID_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Assignment_Non_distribution".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Assignment_Non_distribution (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Assignment_Non_distribution* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Assignment_Non_distribution (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Assignment_Non_distribution* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MBMS_Assignment_Non_distribution".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MBMS_Assignment_Non_distribution (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Assignment_Non_distribution* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MBMS_Assignment_Non_distribution (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Assignment_Non_distribution* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PS_Handover_Command".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PS_Handover_Command (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PS_Handover_Command* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PS_Handover_Command (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PS_Handover_Command* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PS_Handover_Command".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PS_Handover_Command (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PS_Handover_Command* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PS_Handover_Command (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PS_Handover_Command* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Physical_Information".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Physical_Information (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Physical_Information* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Physical_Information (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Physical_Information* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Physical_Information".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Physical_Information (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Physical_Information* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Physical_Information (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Physical_Information* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Serving_Cell_SI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Serving_Cell_SI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Serving_Cell_SI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Serving_Cell_SI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Serving_Cell_SI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Serving_Cell_SI".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Serving_Cell_SI (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Serving_Cell_SI* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Serving_Cell_SI (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Serving_Cell_SI* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_CS_Command".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_CS_Command (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Command* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_CS_Command (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Command* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_CS_Command".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_CS_Command (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Command* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_CS_Command (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Command* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_CS_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_CS_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_CS_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_CS_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_CS_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_CS_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Assignment_Distribution".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Assignment_Distribution (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Assignment_Distribution* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Assignment_Distribution (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Assignment_Distribution* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MBMS_Assignment_Distribution".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MBMS_Assignment_Distribution (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Assignment_Distribution* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MBMS_Assignment_Distribution (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Assignment_Distribution* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Neighbouring_Cell_Information".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Neighbouring_Cell_Information (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Neighbouring_Cell_Information* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Neighbouring_Cell_Information (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Neighbouring_Cell_Information* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MBMS_Neighbouring_Cell_Information".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MBMS_Neighbouring_Cell_Information (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Neighbouring_Cell_Information* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MBMS_Neighbouring_Cell_Information (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Neighbouring_Cell_Information* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_MBMS_Announcement".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_MBMS_Announcement (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_MBMS_Announcement* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_MBMS_Announcement (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_MBMS_Announcement* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_MBMS_Announcement".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_MBMS_Announcement (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_MBMS_Announcement* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_MBMS_Announcement (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_MBMS_Announcement* ED_CONST Destin, ED_EXLONG Length));

int Match_c_Packet_Cell_Change_Order (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Downlink_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Measurement_Order (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Polling_Request (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Power_Control_Timing_Advance (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Queueing_Notification (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Timeslot_Reconfigure (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_TBF_Release (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Uplink_Ack_Nack (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Uplink_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Cell_Change_Continue (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Neighbour_Cell_Data (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Serving_Cell_Data (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_DBPSCH_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Multiple_TBF_Downlink_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Access_Reject (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Paging_Request (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_PDCH_Release (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_PRACH_Parameters (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Downlink_Dummy_Control_Block (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI16 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI6 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI1 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI2 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI3 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI3_bis (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI4 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI5 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI13 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI7 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI8 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI14 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI3_ter (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI3_quater (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PSI15 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Multiple_TBF_Uplink_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Multiple_TBF_Timeslot_Reconfigure (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MBMS_MS_ID_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MBMS_Assignment_Non_distribution (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PS_Handover_Command (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Physical_Information (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Serving_Cell_SI (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_CS_Command (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_CS_Release (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MBMS_Assignment_Distribution (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MBMS_Neighbouring_Cell_Information (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_MBMS_Announcement (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

