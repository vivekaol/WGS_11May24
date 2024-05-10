/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_recog_EPS_h
#define __ed_c_recog_EPS_h

#include "ed_c_EPS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#include "ed_user.h"
#define ED_MAXSIZE 600
#include "endec_configs_EPS.h"

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group EPS_MM_Uplink
--------------------------------------------------------------------*/
typedef enum {
	ID_EPS_MM_Uplink_Unrecognized = 0,
	ID_EPS_MM_Uplink_ATTACH_COMPLETE,
	ID_EPS_MM_Uplink_ATTACH_REQUEST,
	ID_EPS_MM_Uplink_AUTHENTICATION_FAILURE,
	ID_EPS_MM_Uplink_AUTHENTICATION_RESPONSE,
	ID_EPS_MM_Uplink_EPS_DETACH_ACCEPT_UP,
	ID_EPS_MM_Uplink_EPS_DETACH_REQUEST_UP,
	ID_EPS_MM_Uplink_EMM_STATUS,
	ID_EPS_MM_Uplink_EXTENDED_SERVICE_REQUEST,
	ID_EPS_MM_Uplink_GUTI_REALLOCATION_COMPLETE,
	ID_EPS_MM_Uplink_IDENTITY_RESPONSE,
	ID_EPS_MM_Uplink_SECURITY_MODE_COMPLETE,
	ID_EPS_MM_Uplink_SECURITY_MODE_REJECT,
	ID_EPS_MM_Uplink_SECURITY_PROTECTED_NAS_MESSAGE,
	ID_EPS_MM_Uplink_SERVICE_REQUEST,
	ID_EPS_MM_Uplink_TRACKING_AREA_UPDATE_COMPLETE,
	ID_EPS_MM_Uplink_TRACKING_AREA_UPDATE_REQUEST,
	ID_EPS_MM_Uplink_UPLINK_NAS_TRANSPORT,
	ID_EPS_MM_Uplink_UPLINK_GENERIC_NAS_TRANSPORT,
	ID_EPS_MM_Uplink_CONTROL_PLANE_SERVICE_REQUEST
} TEPS_MM_Uplink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group EPS_MM_Uplink
--------------------------------------------------------------------*/
typedef struct {
	TEPS_MM_Uplink_Type Type;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_ATTACH_COMPLETE* fld_c_ATTACH_COMPLETE;
		c_ATTACH_REQUEST* fld_c_ATTACH_REQUEST;
		c_AUTHENTICATION_FAILURE* fld_c_AUTHENTICATION_FAILURE;
		c_AUTHENTICATION_RESPONSE* fld_c_AUTHENTICATION_RESPONSE;
		c_EPS_DETACH_ACCEPT_UP* fld_c_EPS_DETACH_ACCEPT_UP;
		c_EPS_DETACH_REQUEST_UP* fld_c_EPS_DETACH_REQUEST_UP;
		c_EMM_STATUS* fld_c_EMM_STATUS;
		c_EXTENDED_SERVICE_REQUEST* fld_c_EXTENDED_SERVICE_REQUEST;
		c_GUTI_REALLOCATION_COMPLETE* fld_c_GUTI_REALLOCATION_COMPLETE;
		c_IDENTITY_RESPONSE* fld_c_IDENTITY_RESPONSE;
		c_SECURITY_MODE_COMPLETE* fld_c_SECURITY_MODE_COMPLETE;
		c_SECURITY_MODE_REJECT* fld_c_SECURITY_MODE_REJECT;
		c_SECURITY_PROTECTED_NAS_MESSAGE* fld_c_SECURITY_PROTECTED_NAS_MESSAGE;
		c_SERVICE_REQUEST* fld_c_SERVICE_REQUEST;
		c_TRACKING_AREA_UPDATE_COMPLETE* fld_c_TRACKING_AREA_UPDATE_COMPLETE;
		c_TRACKING_AREA_UPDATE_REQUEST* fld_c_TRACKING_AREA_UPDATE_REQUEST;
		c_UPLINK_NAS_TRANSPORT* fld_c_UPLINK_NAS_TRANSPORT;
		c_UPLINK_GENERIC_NAS_TRANSPORT* fld_c_UPLINK_GENERIC_NAS_TRANSPORT;
		c_CONTROL_PLANE_SERVICE_REQUEST* fld_c_CONTROL_PLANE_SERVICE_REQUEST;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TEPS_MM_Uplink_Data;
#define INIT_TEPS_MM_Uplink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TEPS_MM_Uplink_Data)), (sp)->Type=ID_EPS_MM_Uplink_Unrecognized)
void FREE_TEPS_MM_Uplink_Data (TEPS_MM_Uplink_Data* sp);

int SETPRESENT_TEPS_MM_Uplink_Data(TEPS_MM_Uplink_Data* sp, TEPS_MM_Uplink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group EPS_MM_Downlink
--------------------------------------------------------------------*/
typedef enum {
	ID_EPS_MM_Downlink_Unrecognized = 0,
	ID_EPS_MM_Downlink_ATTACH_ACCEPT,
	ID_EPS_MM_Downlink_ATTACH_REJECT,
	ID_EPS_MM_Downlink_AUTHENTICATION_REJECT,
	ID_EPS_MM_Downlink_AUTHENTICATION_REQUEST,
	ID_EPS_MM_Downlink_CS_SERVICE_NOTIFICATION,
	ID_EPS_MM_Downlink_EPS_DETACH_ACCEPT_DN,
	ID_EPS_MM_Downlink_EPS_DETACH_REQUEST_DN,
	ID_EPS_MM_Downlink_DOWNLINK_NAS_TRANSPORT,
	ID_EPS_MM_Downlink_EMM_INFORMATION,
	ID_EPS_MM_Downlink_EMM_STATUS,
	ID_EPS_MM_Downlink_GUTI_REALLOCATION_COMMAND,
	ID_EPS_MM_Downlink_IDENTITY_REQUEST,
	ID_EPS_MM_Downlink_SECURITY_MODE_COMMAND,
	ID_EPS_MM_Downlink_SECURITY_PROTECTED_NAS_MESSAGE,
	ID_EPS_MM_Downlink_SERVICE_REJECT,
	ID_EPS_MM_Downlink_TRACKING_AREA_UPDATE_ACCEPT,
	ID_EPS_MM_Downlink_TRACKING_AREA_UPDATE_REJECT,
	ID_EPS_MM_Downlink_DOWNLINK_GENERIC_NAS_TRANSPORT,
	ID_EPS_MM_Downlink_SERVICE_ACCEPT
} TEPS_MM_Downlink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group EPS_MM_Downlink
--------------------------------------------------------------------*/
typedef struct {
	TEPS_MM_Downlink_Type Type;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_ATTACH_ACCEPT* fld_c_ATTACH_ACCEPT;
		c_ATTACH_REJECT* fld_c_ATTACH_REJECT;
		c_AUTHENTICATION_REJECT* fld_c_AUTHENTICATION_REJECT;
		c_AUTHENTICATION_REQUEST* fld_c_AUTHENTICATION_REQUEST;
		c_CS_SERVICE_NOTIFICATION* fld_c_CS_SERVICE_NOTIFICATION;
		c_EPS_DETACH_ACCEPT_DN* fld_c_EPS_DETACH_ACCEPT_DN;
		c_EPS_DETACH_REQUEST_DN* fld_c_EPS_DETACH_REQUEST_DN;
		c_DOWNLINK_NAS_TRANSPORT* fld_c_DOWNLINK_NAS_TRANSPORT;
		c_EMM_INFORMATION* fld_c_EMM_INFORMATION;
		c_EMM_STATUS* fld_c_EMM_STATUS;
		c_GUTI_REALLOCATION_COMMAND* fld_c_GUTI_REALLOCATION_COMMAND;
		c_IDENTITY_REQUEST* fld_c_IDENTITY_REQUEST;
		c_SECURITY_MODE_COMMAND* fld_c_SECURITY_MODE_COMMAND;
		c_SECURITY_PROTECTED_NAS_MESSAGE* fld_c_SECURITY_PROTECTED_NAS_MESSAGE;
		c_SERVICE_REJECT* fld_c_SERVICE_REJECT;
		c_TRACKING_AREA_UPDATE_ACCEPT* fld_c_TRACKING_AREA_UPDATE_ACCEPT;
		c_TRACKING_AREA_UPDATE_REJECT* fld_c_TRACKING_AREA_UPDATE_REJECT;
		c_DOWNLINK_GENERIC_NAS_TRANSPORT* fld_c_DOWNLINK_GENERIC_NAS_TRANSPORT;
		c_SERVICE_ACCEPT* fld_c_SERVICE_ACCEPT;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TEPS_MM_Downlink_Data;
#define INIT_TEPS_MM_Downlink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TEPS_MM_Downlink_Data)), (sp)->Type=ID_EPS_MM_Downlink_Unrecognized)
void FREE_TEPS_MM_Downlink_Data (TEPS_MM_Downlink_Data* sp);

int SETPRESENT_TEPS_MM_Downlink_Data(TEPS_MM_Downlink_Data* sp, TEPS_MM_Downlink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group EPS_SM_Uplink
--------------------------------------------------------------------*/
typedef enum {
	ID_EPS_SM_Uplink_Unrecognized = 0,
	ID_EPS_SM_Uplink_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT,
	ID_EPS_SM_Uplink_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT,
	ID_EPS_SM_Uplink_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT,
	ID_EPS_SM_Uplink_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT,
	ID_EPS_SM_Uplink_BEARER_RESOURCE_ALLOCATION_REQUEST,
	ID_EPS_SM_Uplink_BEARER_RESOURCE_MODIFICATION_REQUEST,
	ID_EPS_SM_Uplink_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT,
	ID_EPS_SM_Uplink_ESM_DUMMY_MESSAGE,
	ID_EPS_SM_Uplink_ESM_INFORMATION_RESPONSE,
	ID_EPS_SM_Uplink_ESM_STATUS,
	ID_EPS_SM_Uplink_MODIFY_EPS_BEARER_CONTEXT_ACCEPT,
	ID_EPS_SM_Uplink_MODIFY_EPS_BEARER_CONTEXT_REJECT,
	ID_EPS_SM_Uplink_PDN_CONNECTIVITY_REQUEST,
	ID_EPS_SM_Uplink_PDN_DISCONNECT_REQUEST,
	ID_EPS_SM_Uplink_REMOTE_UE_REPORT,
	ID_EPS_SM_Uplink_ESM_DATA_TRANSPORT
} TEPS_SM_Uplink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group EPS_SM_Uplink
--------------------------------------------------------------------*/
typedef struct {
	TEPS_SM_Uplink_Type Type;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* fld_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT;
		c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* fld_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT;
		c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* fld_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT;
		c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* fld_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT;
		c_BEARER_RESOURCE_ALLOCATION_REQUEST* fld_c_BEARER_RESOURCE_ALLOCATION_REQUEST;
		c_BEARER_RESOURCE_MODIFICATION_REQUEST* fld_c_BEARER_RESOURCE_MODIFICATION_REQUEST;
		c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* fld_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT;
		c_ESM_DUMMY_MESSAGE* fld_c_ESM_DUMMY_MESSAGE;
		c_ESM_INFORMATION_RESPONSE* fld_c_ESM_INFORMATION_RESPONSE;
		c_ESM_STATUS* fld_c_ESM_STATUS;
		c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* fld_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT;
		c_MODIFY_EPS_BEARER_CONTEXT_REJECT* fld_c_MODIFY_EPS_BEARER_CONTEXT_REJECT;
		c_PDN_CONNECTIVITY_REQUEST* fld_c_PDN_CONNECTIVITY_REQUEST;
		c_PDN_DISCONNECT_REQUEST* fld_c_PDN_DISCONNECT_REQUEST;
		c_REMOTE_UE_REPORT* fld_c_REMOTE_UE_REPORT;
		c_ESM_DATA_TRANSPORT* fld_c_ESM_DATA_TRANSPORT;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TEPS_SM_Uplink_Data;
#define INIT_TEPS_SM_Uplink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TEPS_SM_Uplink_Data)), (sp)->Type=ID_EPS_SM_Uplink_Unrecognized)
void FREE_TEPS_SM_Uplink_Data (TEPS_SM_Uplink_Data* sp);

int SETPRESENT_TEPS_SM_Uplink_Data(TEPS_SM_Uplink_Data* sp, TEPS_SM_Uplink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group EPS_SM_Downlink
--------------------------------------------------------------------*/
typedef enum {
	ID_EPS_SM_Downlink_Unrecognized = 0,
	ID_EPS_SM_Downlink_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST,
	ID_EPS_SM_Downlink_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST,
	ID_EPS_SM_Downlink_BEARER_RESOURCE_ALLOCATION_REJECT,
	ID_EPS_SM_Downlink_BEARER_RESOURCE_MODIFICATION_REJECT,
	ID_EPS_SM_Downlink_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST,
	ID_EPS_SM_Downlink_ESM_DUMMY_MESSAGE,
	ID_EPS_SM_Downlink_ESM_INFORMATION_REQUEST,
	ID_EPS_SM_Downlink_ESM_STATUS,
	ID_EPS_SM_Downlink_MODIFY_EPS_BEARER_CONTEXT_REQUEST,
	ID_EPS_SM_Downlink_EPS_NOTIFICATION,
	ID_EPS_SM_Downlink_PDN_CONNECTIVITY_REJECT,
	ID_EPS_SM_Downlink_PDN_DISCONNECT_REJECT,
	ID_EPS_SM_Downlink_REMOTE_UE_REPORT_RESPONSE,
	ID_EPS_SM_Downlink_ESM_DATA_TRANSPORT
} TEPS_SM_Downlink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group EPS_SM_Downlink
--------------------------------------------------------------------*/
typedef struct {
	TEPS_SM_Downlink_Type Type;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* fld_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST;
		c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* fld_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST;
		c_BEARER_RESOURCE_ALLOCATION_REJECT* fld_c_BEARER_RESOURCE_ALLOCATION_REJECT;
		c_BEARER_RESOURCE_MODIFICATION_REJECT* fld_c_BEARER_RESOURCE_MODIFICATION_REJECT;
		c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* fld_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST;
		c_ESM_DUMMY_MESSAGE* fld_c_ESM_DUMMY_MESSAGE;
		c_ESM_INFORMATION_REQUEST* fld_c_ESM_INFORMATION_REQUEST;
		c_ESM_STATUS* fld_c_ESM_STATUS;
		c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* fld_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST;
		c_EPS_NOTIFICATION* fld_c_EPS_NOTIFICATION;
		c_PDN_CONNECTIVITY_REJECT* fld_c_PDN_CONNECTIVITY_REJECT;
		c_PDN_DISCONNECT_REJECT* fld_c_PDN_DISCONNECT_REJECT;
		c_REMOTE_UE_REPORT_RESPONSE* fld_c_REMOTE_UE_REPORT_RESPONSE;
		c_ESM_DATA_TRANSPORT* fld_c_ESM_DATA_TRANSPORT;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TEPS_SM_Downlink_Data;
#define INIT_TEPS_SM_Downlink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TEPS_SM_Downlink_Data)), (sp)->Type=ID_EPS_SM_Downlink_Unrecognized)
void FREE_TEPS_SM_Downlink_Data (TEPS_SM_Downlink_Data* sp);

int SETPRESENT_TEPS_SM_Downlink_Data(TEPS_SM_Downlink_Data* sp, TEPS_SM_Downlink_Type toBeSetPresent);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_EPS_MM_Uplink (const char* buffer, TEPS_MM_Uplink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_EPS_MM_Uplink (const char* buffer, int len, TEPS_MM_Uplink_Data* data);
#endif

/* Set encode function */
int SetEncode_EPS_MM_Uplink (char* buffer, ED_EXLONG bitOffset, TEPS_MM_Uplink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_EPS_MM_Downlink (const char* buffer, TEPS_MM_Downlink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_EPS_MM_Downlink (const char* buffer, int len, TEPS_MM_Downlink_Data* data);
#endif

/* Set encode function */
int SetEncode_EPS_MM_Downlink (char* buffer, ED_EXLONG bitOffset, TEPS_MM_Downlink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_EPS_SM_Uplink (const char* buffer, TEPS_SM_Uplink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_EPS_SM_Uplink (const char* buffer, int len, TEPS_SM_Uplink_Data* data);
#endif

/* Set encode function */
int SetEncode_EPS_SM_Uplink (char* buffer, ED_EXLONG bitOffset, TEPS_SM_Uplink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_EPS_SM_Downlink (const char* buffer, TEPS_SM_Downlink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_EPS_SM_Downlink (const char* buffer, int len, TEPS_SM_Downlink_Data* data);
#endif

/* Set encode function */
int SetEncode_EPS_SM_Downlink (char* buffer, ED_EXLONG bitOffset, TEPS_SM_Downlink_Data* data);

#ifdef __cplusplus
	}
#endif
#endif

