/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __XTIDDownlink_L3_h
#define __XTIDDownlink_L3_h
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
	Encoding/decoding functions for "ACTIVATE_PDP_CONTEXT_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_PDP_CONTEXT_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_PDP_CONTEXT_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_PDP_CONTEXT_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "REQUEST_PDP_CONTEXT_ACTIVATION_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "REQUEST_PDP_CONTEXT_ACTIVATION_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_PDP_CONTEXT_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_PDP_CONTEXT_REQUEST_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_PDP_CONTEXT_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_PDP_CONTEXT_ACCEPT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_PDP_CONTEXT_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_PDP_CONTEXT_REJECT_DN".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "NOTIFICATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFICATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "NOTIFICATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFICATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_MBMS_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_MBMS_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_MBMS_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_MBMS_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "REQUEST_MBMS_CONTEXT_ACTIVATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "REQUEST_MBMS_CONTEXT_ACTIVATION".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length));

int Match_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_PDP_CONTEXT_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_PDP_CONTEXT_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_NOTIFICATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_MBMS_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_REQUEST_MBMS_CONTEXT_ACTIVATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif
