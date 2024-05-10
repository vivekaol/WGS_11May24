/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __L3Uplink_L3_h
#define __L3Uplink_L3_h
/* ZZZ */

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

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_RESPONSE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_RESPONSE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_FAILURE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_FAILURE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CM_RE_ESTABLISHMENT_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CM_RE_ESTABLISHMENT_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_RE_ESTABLISHMENT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_RE_ESTABLISHMENT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CM_SERVICE_ABORT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_ABORT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ABORT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_ABORT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ABORT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CM_SERVICE_ABORT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_ABORT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ABORT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_ABORT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ABORT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CM_SERVICE_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CM_SERVICE_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IDENTITY_RESPONSE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IDENTITY_RESPONSE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IMSI_DETACH_INDICATION_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IMSI_DETACH_INDICATION_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IMSI_DETACH_INDICATION_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IMSI_DETACH_INDICATION_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IMSI_DETACH_INDICATION_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IMSI_DETACH_INDICATION_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IMSI_DETACH_INDICATION_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IMSI_DETACH_INDICATION_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IMSI_DETACH_INDICATION_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IMSI_DETACH_INDICATION_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LOCATION_UPDATING_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LOCATION_UPDATING_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LOCATION_UPDATING_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "LOCATION_UPDATING_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_LOCATION_UPDATING_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_LOCATION_UPDATING_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TMSI_REALLOCATION_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "TMSI_REALLOCATION_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MM_NULL_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MM_NULL_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_NULL_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MM_NULL_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_NULL_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MM_NULL_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MM_NULL_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_NULL_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MM_NULL_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_NULL_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ALERTING_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ALERTING_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ALERTING_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ALERTING_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ALERTING_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ALERTING_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CALL_CONFIRMED_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CALL_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_CONFIRMED_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CALL_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CALL_CONFIRMED_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CALL_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_CONFIRMED_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CALL_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CONNECT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CONNECT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CONNECT_ACKNOWLEDGE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONNECT_ACKNOWLEDGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_ACKNOWLEDGE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONNECT_ACKNOWLEDGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_ACKNOWLEDGE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CONNECT_ACKNOWLEDGE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONNECT_ACKNOWLEDGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_ACKNOWLEDGE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONNECT_ACKNOWLEDGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_ACKNOWLEDGE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DISCONNECT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DISCONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DISCONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DISCONNECT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DISCONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DISCONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EMERGENCY_SETUP_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EMERGENCY_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMERGENCY_SETUP_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EMERGENCY_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMERGENCY_SETUP_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EMERGENCY_SETUP_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EMERGENCY_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMERGENCY_SETUP_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EMERGENCY_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMERGENCY_SETUP_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "FACILITY_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FACILITY_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FACILITY_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "FACILITY_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_FACILITY_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_FACILITY_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "HOLD_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HOLD_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HOLD_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "HOLD_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_HOLD_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_HOLD_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NOTIFY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NOTIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NOTIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "NOTIFY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_NOTIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_NOTIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CC_ESTABLISHMENT_CONFIRMED_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CC_ESTABLISHMENT_CONFIRMED_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CC_ESTABLISHMENT_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CC_ESTABLISHMENT_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RELEASE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RELEASE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RELEASE_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RELEASE_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RETRIEVE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RETRIEVE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RETRIEVE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RETRIEVE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RETRIEVE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RETRIEVE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SETUP_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SETUP_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "START_CC_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_CC_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_CC_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_CC_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_CC_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "START_CC_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_CC_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_CC_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_CC_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_CC_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "START_DTMF_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "START_DTMF_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "STATUS_ENQUIRY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STATUS_ENQUIRY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS_ENQUIRY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STATUS_ENQUIRY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS_ENQUIRY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "STATUS_ENQUIRY".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STATUS_ENQUIRY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS_ENQUIRY* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STATUS_ENQUIRY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS_ENQUIRY* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "STOP_DTMF_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STOP_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STOP_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "STOP_DTMF_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STOP_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STOP_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "USER_INFORMATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_USER_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_USER_INFORMATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_USER_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_USER_INFORMATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "USER_INFORMATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_USER_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_USER_INFORMATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_USER_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_USER_INFORMATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DETACH_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DETACH_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DETACH_ACCEPT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DETACH_ACCEPT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "P_TMSI_REALLOCATION_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "P_TMSI_REALLOCATION_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_P_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_P_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_AND_CIPHERING_FAILURE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_AND_CIPHERING_FAILURE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IDENTITY_RESPONSE_B_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_RESPONSE_B_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_B_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_RESPONSE_B_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_B_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IDENTITY_RESPONSE_B_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_RESPONSE_B_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_B_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_RESPONSE_B_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_B_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ROUTING_AREA_UPDATE_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ROUTING_AREA_UPDATE_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ROUTING_AREA_UPDATE_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ROUTING_AREA_UPDATE_COMPLETE_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GMM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "GMM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SERVICE_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SERVICE_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

int Match_c_AUTHENTICATION_RESPONSE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_FAILURE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CM_RE_ESTABLISHMENT_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CM_SERVICE_ABORT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CM_SERVICE_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IDENTITY_RESPONSE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IMSI_DETACH_INDICATION_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_LOCATION_UPDATING_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_TMSI_REALLOCATION_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MM_NULL_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ALERTING_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CALL_CONFIRMED_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CONNECT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CONNECT_ACKNOWLEDGE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DISCONNECT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EMERGENCY_SETUP_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_FACILITY_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_HOLD_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_NOTIFY (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CC_ESTABLISHMENT_CONFIRMED_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RELEASE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RELEASE_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RETRIEVE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SETUP_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_START_CC_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_START_DTMF_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_STATUS_ENQUIRY (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_STOP_DTMF_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_USER_INFORMATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ATTACH_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ATTACH_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DETACH_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DETACH_ACCEPT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_P_TMSI_REALLOCATION_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IDENTITY_RESPONSE_B_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ROUTING_AREA_UPDATE_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ROUTING_AREA_UPDATE_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_GMM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SERVICE_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

