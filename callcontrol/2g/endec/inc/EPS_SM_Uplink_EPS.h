/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __EPS_SM_Uplink_EPS_h
#define __EPS_SM_Uplink_EPS_h
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
	Encoding/decoding functions for "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "BEARER_RESOURCE_ALLOCATION_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "BEARER_RESOURCE_ALLOCATION_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "BEARER_RESOURCE_MODIFICATION_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "BEARER_RESOURCE_MODIFICATION_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ESM_DUMMY_MESSAGE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_DUMMY_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DUMMY_MESSAGE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_DUMMY_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DUMMY_MESSAGE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ESM_DUMMY_MESSAGE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_DUMMY_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DUMMY_MESSAGE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_DUMMY_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DUMMY_MESSAGE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ESM_INFORMATION_RESPONSE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_INFORMATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_INFORMATION_RESPONSE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_INFORMATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_INFORMATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ESM_INFORMATION_RESPONSE".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_INFORMATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_INFORMATION_RESPONSE* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_INFORMATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_INFORMATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ESM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ESM_STATUS".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_STATUS* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_STATUS* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_EPS_BEARER_CONTEXT_ACCEPT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MODIFY_EPS_BEARER_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MODIFY_EPS_BEARER_CONTEXT_REJECT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PDN_CONNECTIVITY_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDN_CONNECTIVITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDN_CONNECTIVITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_CONNECTIVITY_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PDN_CONNECTIVITY_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PDN_CONNECTIVITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PDN_CONNECTIVITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_CONNECTIVITY_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "PDN_DISCONNECT_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDN_DISCONNECT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDN_DISCONNECT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_DISCONNECT_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "PDN_DISCONNECT_REQUEST".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PDN_DISCONNECT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REQUEST* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PDN_DISCONNECT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_DISCONNECT_REQUEST* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "REMOTE_UE_REPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REMOTE_UE_REPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REMOTE_UE_REPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REMOTE_UE_REPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "REMOTE_UE_REPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REMOTE_UE_REPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REMOTE_UE_REPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REMOTE_UE_REPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "ESM_DATA_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_DATA_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DATA_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_DATA_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DATA_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "ESM_DATA_TRANSPORT".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_DATA_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DATA_TRANSPORT* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_DATA_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DATA_TRANSPORT* ED_CONST Destin, ED_EXLONG Length));

int Match_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_BEARER_RESOURCE_ALLOCATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_BEARER_RESOURCE_MODIFICATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ESM_DUMMY_MESSAGE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ESM_INFORMATION_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ESM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PDN_CONNECTIVITY_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_PDN_DISCONNECT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_REMOTE_UE_REPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_ESM_DATA_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

