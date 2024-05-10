/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __CM_CP_SMS_h
#define __CM_CP_SMS_h
/* ZZZ */

#include "ed_lib.h"
#include "ed_c_SMS.h"
#include "ed_user.h"
#include "endec_configs_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#ifdef __cplusplus
	extern "C" {
#endif

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CP_DATA".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CP_DATA (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CP_DATA* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CP_DATA (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CP_DATA* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CP_DATA".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CP_DATA (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CP_DATA* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CP_DATA (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CP_DATA* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CP_ACK".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CP_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CP_ACK* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CP_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CP_ACK* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CP_ACK".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CP_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CP_ACK* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CP_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CP_ACK* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "CP_ERROR".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CP_ERROR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CP_ERROR* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CP_ERROR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CP_ERROR* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "CP_ERROR".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CP_ERROR (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CP_ERROR* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CP_ERROR (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CP_ERROR* ED_CONST Destin, ED_EXLONG Length));

int Match_c_CP_DATA (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CP_ACK (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_CP_ERROR (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

