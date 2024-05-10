/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __L3Downlink_L3_h
#define __L3Downlink_L3_h
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
	Encoding/decoding functions for "AUTHENTICATION_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CM_SERVICE_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CM_SERVICE_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CM_SERVICE_PROMPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_PROMPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_PROMPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_PROMPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_PROMPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CM_SERVICE_PROMPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_PROMPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_PROMPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_PROMPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_PROMPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CM_SERVICE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CM_SERVICE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ABORT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ABORT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ABORT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ABORT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ABORT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ABORT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ABORT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ABORT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ABORT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ABORT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IDENTITY_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IDENTITY_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LOCATION_UPDATING_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LOCATION_UPDATING_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LOCATION_UPDATING_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "LOCATION_UPDATING_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_LOCATION_UPDATING_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_LOCATION_UPDATING_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "LOCATION_UPDATING_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LOCATION_UPDATING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LOCATION_UPDATING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "LOCATION_UPDATING_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_LOCATION_UPDATING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_LOCATION_UPDATING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MM_INFORMATION_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_INFORMATION_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MM_INFORMATION_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_INFORMATION_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TMSI_REALLOCATION_COMMAND_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "TMSI_REALLOCATION_COMMAND_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ALERTING_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ALERTING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ALERTING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ALERTING_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ALERTING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ALERTING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CALL_PROCEEDING_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CALL_PROCEEDING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_PROCEEDING_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CALL_PROCEEDING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_PROCEEDING_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CALL_PROCEEDING_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CALL_PROCEEDING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_PROCEEDING_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CALL_PROCEEDING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_PROCEEDING_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CONGESTION_CONTROL_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONGESTION_CONTROL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONGESTION_CONTROL_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONGESTION_CONTROL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONGESTION_CONTROL_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CONGESTION_CONTROL_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONGESTION_CONTROL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONGESTION_CONTROL_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONGESTION_CONTROL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONGESTION_CONTROL_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CONNECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CONNECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DISCONNECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DISCONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DISCONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DISCONNECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DISCONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DISCONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "FACILITY_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FACILITY_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FACILITY_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "FACILITY_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_FACILITY_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_FACILITY_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "HOLD_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HOLD_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HOLD_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "HOLD_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_HOLD_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_HOLD_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "HOLD_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HOLD_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HOLD_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "HOLD_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_HOLD_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_HOLD_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PROGRESS_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PROGRESS_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PROGRESS_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PROGRESS_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PROGRESS_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PROGRESS_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PROGRESS_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PROGRESS_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PROGRESS_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PROGRESS_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CC_ESTABLISHMENT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CC_ESTABLISHMENT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CC_ESTABLISHMENT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CC_ESTABLISHMENT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CC_ESTABLISHMENT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CC_ESTABLISHMENT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RELEASE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RELEASE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RECALL_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RECALL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RECALL_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RECALL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RECALL_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RECALL_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RECALL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RECALL_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RECALL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RECALL_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RELEASE_COMPLETE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_COMPLETE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_COMPLETE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RELEASE_COMPLETE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_COMPLETE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_COMPLETE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RETRIEVE_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RETRIEVE_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RETRIEVE_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RETRIEVE_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RETRIEVE_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RETRIEVE_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RETRIEVE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RETRIEVE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RETRIEVE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RETRIEVE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RETRIEVE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RETRIEVE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SETUP_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SETUP_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SETUP_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SETUP_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SETUP_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SETUP_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "START_DTMF_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "START_DTMF_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "START_DTMF_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_DTMF_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_DTMF_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "START_DTMF_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_DTMF_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_DTMF_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "STOP_DTMF_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STOP_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STOP_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "STOP_DTMF_ACKNOWLEDGE_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STOP_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STOP_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DETACH_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DETACH_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DETACH_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DETACH_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "P_TMSI_REALLOCATION_COMMAND_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "P_TMSI_REALLOCATION_COMMAND_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_P_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_P_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_AND_CIPHERING_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_AND_CIPHERING_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_AND_CIPHERING_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_AND_CIPHERING_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IDENTITY_REQUEST_B_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_REQUEST_B_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_B_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_REQUEST_B_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_B_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IDENTITY_REQUEST_B_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_REQUEST_B_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_B_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_REQUEST_B_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_B_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ROUTING_AREA_UPDATE_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ROUTING_AREA_UPDATE_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ROUTING_AREA_UPDATE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ROUTING_AREA_UPDATE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GMM_INFORMATION_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GMM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_INFORMATION_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GMM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "GMM_INFORMATION_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GMM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_INFORMATION_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GMM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SERVICE_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SERVICE_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SERVICE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SERVICE_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

int Match_c_AUTHENTICATION_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CM_SERVICE_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CM_SERVICE_PROMPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CM_SERVICE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ABORT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IDENTITY_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_LOCATION_UPDATING_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_LOCATION_UPDATING_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MM_INFORMATION_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_TMSI_REALLOCATION_COMMAND_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ALERTING_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CALL_PROCEEDING_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CONGESTION_CONTROL_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CONNECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DISCONNECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_FACILITY_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_HOLD_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_HOLD_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PROGRESS_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CC_ESTABLISHMENT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RELEASE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RECALL_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RELEASE_COMPLETE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RETRIEVE_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RETRIEVE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SETUP_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_START_DTMF_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_START_DTMF_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_STOP_DTMF_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ATTACH_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ATTACH_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DETACH_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DETACH_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_P_TMSI_REALLOCATION_COMMAND_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IDENTITY_REQUEST_B_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ROUTING_AREA_UPDATE_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ROUTING_AREA_UPDATE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_GMM_INFORMATION_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SERVICE_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SERVICE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

