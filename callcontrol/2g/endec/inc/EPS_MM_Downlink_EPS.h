/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __EPS_MM_Downlink_EPS_h
#define __EPS_MM_Downlink_EPS_h
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
	Encoding/decoding functions for "ATTACH_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ATTACH_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ATTACH_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "AUTHENTICATION_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "AUTHENTICATION_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CS_SERVICE_NOTIFICATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CS_SERVICE_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CS_SERVICE_NOTIFICATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CS_SERVICE_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CS_SERVICE_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CS_SERVICE_NOTIFICATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CS_SERVICE_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CS_SERVICE_NOTIFICATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CS_SERVICE_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CS_SERVICE_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPS_DETACH_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EPS_DETACH_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EPS_DETACH_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EPS_DETACH_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DOWNLINK_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DOWNLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DOWNLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DOWNLINK_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DOWNLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DOWNLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EMM_INFORMATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EMM_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_INFORMATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EMM_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_INFORMATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EMM_INFORMATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EMM_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_INFORMATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EMM_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_INFORMATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "GUTI_REALLOCATION_COMMAND".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GUTI_REALLOCATION_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMMAND* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GUTI_REALLOCATION_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMMAND* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "GUTI_REALLOCATION_COMMAND".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GUTI_REALLOCATION_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMMAND* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GUTI_REALLOCATION_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMMAND* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "IDENTITY_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "IDENTITY_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SECURITY_MODE_COMMAND".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_MODE_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMMAND* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_MODE_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMMAND* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SECURITY_MODE_COMMAND".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_MODE_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMMAND* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_MODE_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMMAND* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SERVICE_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SERVICE_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TRACKING_AREA_UPDATE_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "TRACKING_AREA_UPDATE_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "TRACKING_AREA_UPDATE_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "TRACKING_AREA_UPDATE_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DOWNLINK_GENERIC_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DOWNLINK_GENERIC_NAS_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DOWNLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DOWNLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SERVICE_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "SERVICE_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

int Match_c_ATTACH_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ATTACH_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_AUTHENTICATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CS_SERVICE_NOTIFICATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EPS_DETACH_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EPS_DETACH_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DOWNLINK_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EMM_INFORMATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_GUTI_REALLOCATION_COMMAND (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_IDENTITY_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SECURITY_MODE_COMMAND (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SERVICE_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_TRACKING_AREA_UPDATE_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_TRACKING_AREA_UPDATE_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DOWNLINK_GENERIC_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_SERVICE_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

