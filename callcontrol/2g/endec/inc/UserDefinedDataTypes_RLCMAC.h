/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __UserDefinedDataTypes_RLCMAC_h
#define __UserDefinedDataTypes_RLCMAC_h
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
	Encoding/decoding functions for "GenericTLV_RLCMAC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_RLCMAC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_RLCMAC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_RLCMAC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_RLCMAC* ED_CONST Destin, ED_EXLONG Length));


#ifdef __cplusplus
	}
#endif
#endif

