/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_recog_SMS_h
#define __ed_c_recog_SMS_h

#include "ed_c_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#include "ed_user.h"
#define ED_MAXSIZE 600
#include "endec_configs_SMS.h"

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group CM_CP
--------------------------------------------------------------------*/
typedef enum {
	ID_CM_CP_Unrecognized = 0,
	ID_CM_CP_CP_DATA,
	ID_CM_CP_CP_ACK,
	ID_CM_CP_CP_ERROR
} TCM_CP_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group CM_CP
--------------------------------------------------------------------*/
typedef struct {
	TCM_CP_Type Type;
	int SkipIndicator;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_CP_DATA* fld_c_CP_DATA;
		c_CP_ACK* fld_c_CP_ACK;
		c_CP_ERROR* fld_c_CP_ERROR;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TCM_CP_Data;
#define INIT_TCM_CP_Data(sp) (ED_RESET_MEM ((sp), sizeof (TCM_CP_Data)), (sp)->Type=ID_CM_CP_Unrecognized)
void FREE_TCM_CP_Data (TCM_CP_Data* sp);

int SETPRESENT_TCM_CP_Data(TCM_CP_Data* sp, TCM_CP_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group MSC2MS
--------------------------------------------------------------------*/
typedef enum {
	ID_MSC2MS_Unrecognized = 0,
	ID_MSC2MS_RP_DATA_MSC2MS,
	ID_MSC2MS_RP_RP_ACK_MSC2MS,
	ID_MSC2MS_RP_RP_ERROR_MSC2MS
} TMSC2MS_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group MSC2MS
--------------------------------------------------------------------*/
typedef struct {
	TMSC2MS_Type Type;
	int MessageType;
	union {
		c_RP_DATA_MSC2MS* fld_c_RP_DATA_MSC2MS;
		c_RP_RP_ACK_MSC2MS* fld_c_RP_RP_ACK_MSC2MS;
		c_RP_RP_ERROR_MSC2MS* fld_c_RP_RP_ERROR_MSC2MS;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TMSC2MS_Data;
#define INIT_TMSC2MS_Data(sp) (ED_RESET_MEM ((sp), sizeof (TMSC2MS_Data)), (sp)->Type=ID_MSC2MS_Unrecognized)
void FREE_TMSC2MS_Data (TMSC2MS_Data* sp);

int SETPRESENT_TMSC2MS_Data(TMSC2MS_Data* sp, TMSC2MS_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group MS2MSC
--------------------------------------------------------------------*/
typedef enum {
	ID_MS2MSC_Unrecognized = 0,
	ID_MS2MSC_RP_DATA_MS2MSC,
	ID_MS2MSC_RP_RP_SMMA_MS2MSC,
	ID_MS2MSC_RP_RP_ACK_MS2MSC,
	ID_MS2MSC_RP_RP_ERROR_MS2MSC
} TMS2MSC_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group MS2MSC
--------------------------------------------------------------------*/
typedef struct {
	TMS2MSC_Type Type;
	int MessageType;
	union {
		c_RP_DATA_MS2MSC* fld_c_RP_DATA_MS2MSC;
		c_RP_RP_SMMA_MS2MSC* fld_c_RP_RP_SMMA_MS2MSC;
		c_RP_RP_ACK_MS2MSC* fld_c_RP_RP_ACK_MS2MSC;
		c_RP_RP_ERROR_MS2MSC* fld_c_RP_RP_ERROR_MS2MSC;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TMS2MSC_Data;
#define INIT_TMS2MSC_Data(sp) (ED_RESET_MEM ((sp), sizeof (TMS2MSC_Data)), (sp)->Type=ID_MS2MSC_Unrecognized)
void FREE_TMS2MSC_Data (TMS2MSC_Data* sp);

int SETPRESENT_TMS2MSC_Data(TMS2MSC_Data* sp, TMS2MSC_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group SC2MS
--------------------------------------------------------------------*/
typedef enum {
	ID_SC2MS_Unrecognized = 0,
	ID_SC2MS_SMS_DELIVER,
	ID_SC2MS_SMS_STATUS_REPORT
} TSC2MS_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group SC2MS
--------------------------------------------------------------------*/
typedef struct {
	TSC2MS_Type Type;
	int MessageType;
	union {
		c_SMS_DELIVER* fld_c_SMS_DELIVER;
		c_SMS_STATUS_REPORT* fld_c_SMS_STATUS_REPORT;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TSC2MS_Data;
#define INIT_TSC2MS_Data(sp) (ED_RESET_MEM ((sp), sizeof (TSC2MS_Data)), (sp)->Type=ID_SC2MS_Unrecognized)
void FREE_TSC2MS_Data (TSC2MS_Data* sp);

int SETPRESENT_TSC2MS_Data(TSC2MS_Data* sp, TSC2MS_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group SC2MS_ERR
--------------------------------------------------------------------*/
typedef enum {
	ID_SC2MS_ERR_Unrecognized = 0,
	ID_SC2MS_ERR_SMS_SUBMIT_REPORT_RP_ERROR
} TSC2MS_ERR_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group SC2MS_ERR
--------------------------------------------------------------------*/
typedef struct {
	TSC2MS_ERR_Type Type;
	int MessageType;
	union {
		c_SMS_SUBMIT_REPORT_RP_ERROR* fld_c_SMS_SUBMIT_REPORT_RP_ERROR;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TSC2MS_ERR_Data;
#define INIT_TSC2MS_ERR_Data(sp) (ED_RESET_MEM ((sp), sizeof (TSC2MS_ERR_Data)), (sp)->Type=ID_SC2MS_ERR_Unrecognized)
void FREE_TSC2MS_ERR_Data (TSC2MS_ERR_Data* sp);

int SETPRESENT_TSC2MS_ERR_Data(TSC2MS_ERR_Data* sp, TSC2MS_ERR_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group SC2MS_ACK
--------------------------------------------------------------------*/
typedef enum {
	ID_SC2MS_ACK_Unrecognized = 0,
	ID_SC2MS_ACK_SMS_SUBMIT_REPORT_RP_ACK
} TSC2MS_ACK_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group SC2MS_ACK
--------------------------------------------------------------------*/
typedef struct {
	TSC2MS_ACK_Type Type;
	int MessageType;
	union {
		c_SMS_SUBMIT_REPORT_RP_ACK* fld_c_SMS_SUBMIT_REPORT_RP_ACK;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TSC2MS_ACK_Data;
#define INIT_TSC2MS_ACK_Data(sp) (ED_RESET_MEM ((sp), sizeof (TSC2MS_ACK_Data)), (sp)->Type=ID_SC2MS_ACK_Unrecognized)
void FREE_TSC2MS_ACK_Data (TSC2MS_ACK_Data* sp);

int SETPRESENT_TSC2MS_ACK_Data(TSC2MS_ACK_Data* sp, TSC2MS_ACK_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group MS2SC
--------------------------------------------------------------------*/
typedef enum {
	ID_MS2SC_Unrecognized = 0,
	ID_MS2SC_SMS_SUBMIT,
	ID_MS2SC_SMS_COMMAND
} TMS2SC_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group MS2SC
--------------------------------------------------------------------*/
typedef struct {
	TMS2SC_Type Type;
	int MessageType;
	union {
		c_SMS_SUBMIT* fld_c_SMS_SUBMIT;
		c_SMS_COMMAND* fld_c_SMS_COMMAND;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TMS2SC_Data;
#define INIT_TMS2SC_Data(sp) (ED_RESET_MEM ((sp), sizeof (TMS2SC_Data)), (sp)->Type=ID_MS2SC_Unrecognized)
void FREE_TMS2SC_Data (TMS2SC_Data* sp);

int SETPRESENT_TMS2SC_Data(TMS2SC_Data* sp, TMS2SC_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group MS2SC_ERR
--------------------------------------------------------------------*/
typedef enum {
	ID_MS2SC_ERR_Unrecognized = 0,
	ID_MS2SC_ERR_SMS_DELIVERY_REPORT_RP_ERROR
} TMS2SC_ERR_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group MS2SC_ERR
--------------------------------------------------------------------*/
typedef struct {
	TMS2SC_ERR_Type Type;
	int MessageType;
	union {
		c_SMS_DELIVERY_REPORT_RP_ERROR* fld_c_SMS_DELIVERY_REPORT_RP_ERROR;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TMS2SC_ERR_Data;
#define INIT_TMS2SC_ERR_Data(sp) (ED_RESET_MEM ((sp), sizeof (TMS2SC_ERR_Data)), (sp)->Type=ID_MS2SC_ERR_Unrecognized)
void FREE_TMS2SC_ERR_Data (TMS2SC_ERR_Data* sp);

int SETPRESENT_TMS2SC_ERR_Data(TMS2SC_ERR_Data* sp, TMS2SC_ERR_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group MS2SC_ACK
--------------------------------------------------------------------*/
typedef enum {
	ID_MS2SC_ACK_Unrecognized = 0,
	ID_MS2SC_ACK_SMS_DELIVERY_REPORT_RP_ACK
} TMS2SC_ACK_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group MS2SC_ACK
--------------------------------------------------------------------*/
typedef struct {
	TMS2SC_ACK_Type Type;
	int MessageType;
	union {
		c_SMS_DELIVERY_REPORT_RP_ACK* fld_c_SMS_DELIVERY_REPORT_RP_ACK;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TMS2SC_ACK_Data;
#define INIT_TMS2SC_ACK_Data(sp) (ED_RESET_MEM ((sp), sizeof (TMS2SC_ACK_Data)), (sp)->Type=ID_MS2SC_ACK_Unrecognized)
void FREE_TMS2SC_ACK_Data (TMS2SC_ACK_Data* sp);

int SETPRESENT_TMS2SC_ACK_Data(TMS2SC_ACK_Data* sp, TMS2SC_ACK_Type toBeSetPresent);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_CM_CP (const char* buffer, TCM_CP_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_CM_CP (const char* buffer, int len, TCM_CP_Data* data);
#endif

/* Set encode function */
int SetEncode_CM_CP (char* buffer, ED_EXLONG bitOffset, TCM_CP_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_MSC2MS (const char* buffer, TMSC2MS_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MSC2MS (const char* buffer, int len, TMSC2MS_Data* data);
#endif

/* Set encode function */
int SetEncode_MSC2MS (char* buffer, ED_EXLONG bitOffset, TMSC2MS_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_MS2MSC (const char* buffer, TMS2MSC_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2MSC (const char* buffer, int len, TMS2MSC_Data* data);
#endif

/* Set encode function */
int SetEncode_MS2MSC (char* buffer, ED_EXLONG bitOffset, TMS2MSC_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_SC2MS (const char* buffer, TSC2MS_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_SC2MS (const char* buffer, int len, TSC2MS_Data* data);
#endif

/* Set encode function */
int SetEncode_SC2MS (char* buffer, ED_EXLONG bitOffset, TSC2MS_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_SC2MS_ERR (const char* buffer, TSC2MS_ERR_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_SC2MS_ERR (const char* buffer, int len, TSC2MS_ERR_Data* data);
#endif

/* Set encode function */
int SetEncode_SC2MS_ERR (char* buffer, ED_EXLONG bitOffset, TSC2MS_ERR_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_SC2MS_ACK (const char* buffer, TSC2MS_ACK_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_SC2MS_ACK (const char* buffer, int len, TSC2MS_ACK_Data* data);
#endif

/* Set encode function */
int SetEncode_SC2MS_ACK (char* buffer, ED_EXLONG bitOffset, TSC2MS_ACK_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_MS2SC (const char* buffer, TMS2SC_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2SC (const char* buffer, int len, TMS2SC_Data* data);
#endif

/* Set encode function */
int SetEncode_MS2SC (char* buffer, ED_EXLONG bitOffset, TMS2SC_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_MS2SC_ERR (const char* buffer, TMS2SC_ERR_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2SC_ERR (const char* buffer, int len, TMS2SC_ERR_Data* data);
#endif

/* Set encode function */
int SetEncode_MS2SC_ERR (char* buffer, ED_EXLONG bitOffset, TMS2SC_ERR_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_MS2SC_ACK (const char* buffer, TMS2SC_ACK_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_MS2SC_ACK (const char* buffer, int len, TMS2SC_ACK_Data* data);
#endif

/* Set encode function */
int SetEncode_MS2SC_ACK (char* buffer, ED_EXLONG bitOffset, TMS2SC_ACK_Data* data);

#ifdef __cplusplus
	}
#endif
#endif

