/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __EPS_MM_Uplink_EPS_h
#define __EPS_MM_Uplink_EPS_h
/* ZZZ */

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

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_FAILURE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_FAILURE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_FAILURE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_FAILURE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_FAILURE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_FAILURE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_RESPONSE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_RESPONSE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPS_DETACH_ACCEPT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EPS_DETACH_ACCEPT_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPS_DETACH_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EPS_DETACH_REQUEST_UP".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_UP* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EMM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EMM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EXTENDED_SERVICE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EXTENDED_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EXTENDED_SERVICE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EXTENDED_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EXTENDED_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EXTENDED_SERVICE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EXTENDED_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EXTENDED_SERVICE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EXTENDED_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EXTENDED_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GUTI_REALLOCATION_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GUTI_REALLOCATION_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GUTI_REALLOCATION_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "GUTI_REALLOCATION_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GUTI_REALLOCATION_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GUTI_REALLOCATION_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IDENTITY_RESPONSE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IDENTITY_RESPONSE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SECURITY_MODE_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_MODE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_MODE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SECURITY_MODE_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_MODE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_MODE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SECURITY_MODE_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_MODE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_MODE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SECURITY_MODE_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_MODE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_MODE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SECURITY_PROTECTED_NAS_MESSAGE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_PROTECTED_NAS_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_PROTECTED_NAS_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SECURITY_PROTECTED_NAS_MESSAGE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_PROTECTED_NAS_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_PROTECTED_NAS_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SERVICE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SERVICE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TRACKING_AREA_UPDATE_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "TRACKING_AREA_UPDATE_COMPLETE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TRACKING_AREA_UPDATE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "TRACKING_AREA_UPDATE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UPLINK_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UPLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UPLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "UPLINK_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_UPLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_UPLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "UPLINK_GENERIC_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UPLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UPLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "UPLINK_GENERIC_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_UPLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_UPLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CONTROL_PLANE_SERVICE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONTROL_PLANE_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONTROL_PLANE_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CONTROL_PLANE_SERVICE_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONTROL_PLANE_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONTROL_PLANE_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length));

int Match_c_ATTACH_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ATTACH_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_FAILURE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EPS_DETACH_ACCEPT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EPS_DETACH_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EMM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EXTENDED_SERVICE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_GUTI_REALLOCATION_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IDENTITY_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SECURITY_MODE_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SECURITY_MODE_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SECURITY_PROTECTED_NAS_MESSAGE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SERVICE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_TRACKING_AREA_UPDATE_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_TRACKING_AREA_UPDATE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_UPLINK_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_UPLINK_GENERIC_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CONTROL_PLANE_SERVICE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

