/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __Downlink_RLC_MAC_EC_PACCH_EC_PACCH_h
#define __Downlink_RLC_MAC_EC_PACCH_EC_PACCH_h
/* ZZZ */

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

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Access_Reject".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Access_Reject (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Access_Reject* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Access_Reject (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Access_Reject* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Access_Reject".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Access_Reject (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Access_Reject* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Access_Reject (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Access_Reject* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Downlink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Downlink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Downlink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Downlink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Polling_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Polling_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Polling_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Polling_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Polling_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Polling_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Polling_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Polling_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Polling_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Polling_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Power_Control_Timing_Advance".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Power_Control_Timing_Advance (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Power_Control_Timing_Advance* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Power_Control_Timing_Advance (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Power_Control_Timing_Advance* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Power_Control_Timing_Advance".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Power_Control_Timing_Advance (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Power_Control_Timing_Advance* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Power_Control_Timing_Advance (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Power_Control_Timing_Advance* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_TBF_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_TBF_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_TBF_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_TBF_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_TBF_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_TBF_Release".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_TBF_Release (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_TBF_Release* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_TBF_Release (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_TBF_Release* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Uplink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Uplink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Uplink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Uplink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Uplink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Uplink_Assignment".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Uplink_Assignment (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Assignment* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Uplink_Assignment (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Assignment* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EC_Packet_Downlink_Dummy_Control_Block".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EC_Packet_Downlink_Dummy_Control_Block (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Dummy_Control_Block* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EC_Packet_Downlink_Dummy_Control_Block (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Dummy_Control_Block* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EC_Packet_Downlink_Dummy_Control_Block".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EC_Packet_Downlink_Dummy_Control_Block (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EC_Packet_Downlink_Dummy_Control_Block* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EC_Packet_Downlink_Dummy_Control_Block (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EC_Packet_Downlink_Dummy_Control_Block* ED_CONST Destin, ED_EXLONG Length));

int Match_c_EC_Packet_Access_Reject (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Downlink_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Polling_Request (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Power_Control_Timing_Advance (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_TBF_Release (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Uplink_Ack_Nack (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Uplink_Assignment (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EC_Packet_Downlink_Dummy_Control_Block (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

