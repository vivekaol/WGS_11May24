/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __MS2MSC_SMS_h
#define __MS2MSC_SMS_h
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
	Encoding/decoding functions for "RP_DATA_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_DATA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_DATA_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_DATA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_DATA_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RP_DATA_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_DATA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_DATA_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_DATA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_DATA_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RP_RP_SMMA_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_RP_SMMA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_SMMA_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_RP_SMMA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_SMMA_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RP_RP_SMMA_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_RP_SMMA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_SMMA_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_RP_SMMA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_SMMA_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RP_RP_ACK_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_RP_ACK_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ACK_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_RP_ACK_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ACK_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RP_RP_ACK_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_RP_ACK_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ACK_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_RP_ACK_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ACK_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "RP_RP_ERROR_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_RP_ERROR_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ERROR_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_RP_ERROR_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ERROR_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "RP_RP_ERROR_MS2MSC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_RP_ERROR_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ERROR_MS2MSC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_RP_ERROR_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ERROR_MS2MSC* ED_CONST Destin, ED_EXLONG Length));

int Match_c_RP_DATA_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RP_RP_SMMA_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RP_RP_ACK_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_RP_RP_ERROR_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

