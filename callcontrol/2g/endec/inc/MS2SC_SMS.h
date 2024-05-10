/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __MS2SC_SMS_h
#define __MS2SC_SMS_h
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
	Encoding/decoding functions for "SMS_SUBMIT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SUBMIT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SUBMIT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SUBMIT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SUBMIT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "SMS_COMMAND".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_COMMAND* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_COMMAND* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

