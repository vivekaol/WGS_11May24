/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_recog_L3_h
#define __ed_c_recog_L3_h

#include "ed_c_L3.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#include "ed_user.h"
#define ED_MAXSIZE 600
#include "endec_configs_L3.h"

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group L3Uplink
--------------------------------------------------------------------*/
typedef enum {
	ID_L3Uplink_Unrecognized = 0,
	ID_L3Uplink_AUTHENTICATION_RESPONSE_UP,
	ID_L3Uplink_AUTHENTICATION_FAILURE_UP,
	ID_L3Uplink_CM_RE_ESTABLISHMENT_REQUEST_UP,
	ID_L3Uplink_CM_SERVICE_ABORT_UP,
	ID_L3Uplink_CM_SERVICE_REQUEST_UP,
	ID_L3Uplink_IDENTITY_RESPONSE_UP,
	ID_L3Uplink_IMSI_DETACH_INDICATION_UP,
	ID_L3Uplink_LOCATION_UPDATING_REQUEST_UP,
	ID_L3Uplink_MM_STATUS,
	ID_L3Uplink_TMSI_REALLOCATION_COMPLETE_UP,
	ID_L3Uplink_MM_NULL_UP,
	ID_L3Uplink_ALERTING_UP,
	ID_L3Uplink_CALL_CONFIRMED_UP,
	ID_L3Uplink_CONNECT_UP,
	ID_L3Uplink_CONNECT_ACKNOWLEDGE,
	ID_L3Uplink_DISCONNECT_UP,
	ID_L3Uplink_EMERGENCY_SETUP_UP,
	ID_L3Uplink_FACILITY_UP,
	ID_L3Uplink_HOLD_UP,
	ID_L3Uplink_MODIFY,
	ID_L3Uplink_MODIFY_COMPLETE,
	ID_L3Uplink_MODIFY_REJECT,
	ID_L3Uplink_NOTIFY,
	ID_L3Uplink_CC_ESTABLISHMENT_CONFIRMED_UP,
	ID_L3Uplink_RELEASE_UP,
	ID_L3Uplink_RELEASE_COMPLETE_UP,
	ID_L3Uplink_RETRIEVE_UP,
	ID_L3Uplink_SETUP_UP,
	ID_L3Uplink_START_CC_UP,
	ID_L3Uplink_START_DTMF_UP,
	ID_L3Uplink_STATUS,
	ID_L3Uplink_STATUS_ENQUIRY,
	ID_L3Uplink_STOP_DTMF_UP,
	ID_L3Uplink_USER_INFORMATION,
	ID_L3Uplink_ATTACH_REQUEST_UP,
	ID_L3Uplink_ATTACH_COMPLETE_UP,
	ID_L3Uplink_DETACH_REQUEST_UP,
	ID_L3Uplink_DETACH_ACCEPT_UP,
	ID_L3Uplink_P_TMSI_REALLOCATION_COMPLETE_UP,
	ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP,
	ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_FAILURE_UP,
	ID_L3Uplink_IDENTITY_RESPONSE_B_UP,
	ID_L3Uplink_ROUTING_AREA_UPDATE_REQUEST_UP,
	ID_L3Uplink_ROUTING_AREA_UPDATE_COMPLETE_UP,
	ID_L3Uplink_GMM_STATUS,
	ID_L3Uplink_SERVICE_REQUEST_UP
} TL3Uplink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group L3Uplink
--------------------------------------------------------------------*/
typedef struct {
	TL3Uplink_Type Type;
	int SkipIndicator;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_AUTHENTICATION_RESPONSE_UP* fld_c_AUTHENTICATION_RESPONSE_UP;
		c_AUTHENTICATION_FAILURE_UP* fld_c_AUTHENTICATION_FAILURE_UP;
		c_CM_RE_ESTABLISHMENT_REQUEST_UP* fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP;
		c_CM_SERVICE_ABORT_UP* fld_c_CM_SERVICE_ABORT_UP;
		c_CM_SERVICE_REQUEST_UP* fld_c_CM_SERVICE_REQUEST_UP;
		c_IDENTITY_RESPONSE_UP* fld_c_IDENTITY_RESPONSE_UP;
		c_IMSI_DETACH_INDICATION_UP* fld_c_IMSI_DETACH_INDICATION_UP;
		c_LOCATION_UPDATING_REQUEST_UP* fld_c_LOCATION_UPDATING_REQUEST_UP;
		c_MM_STATUS* fld_c_MM_STATUS;
		c_TMSI_REALLOCATION_COMPLETE_UP* fld_c_TMSI_REALLOCATION_COMPLETE_UP;
		c_MM_NULL_UP* fld_c_MM_NULL_UP;
		c_ALERTING_UP* fld_c_ALERTING_UP;
		c_CALL_CONFIRMED_UP* fld_c_CALL_CONFIRMED_UP;
		c_CONNECT_UP* fld_c_CONNECT_UP;
		c_CONNECT_ACKNOWLEDGE* fld_c_CONNECT_ACKNOWLEDGE;
		c_DISCONNECT_UP* fld_c_DISCONNECT_UP;
		c_EMERGENCY_SETUP_UP* fld_c_EMERGENCY_SETUP_UP;
		c_FACILITY_UP* fld_c_FACILITY_UP;
		c_HOLD_UP* fld_c_HOLD_UP;
		c_MODIFY* fld_c_MODIFY;
		c_MODIFY_COMPLETE* fld_c_MODIFY_COMPLETE;
		c_MODIFY_REJECT* fld_c_MODIFY_REJECT;
		c_NOTIFY* fld_c_NOTIFY;
		c_CC_ESTABLISHMENT_CONFIRMED_UP* fld_c_CC_ESTABLISHMENT_CONFIRMED_UP;
		c_RELEASE_UP* fld_c_RELEASE_UP;
		c_RELEASE_COMPLETE_UP* fld_c_RELEASE_COMPLETE_UP;
		c_RETRIEVE_UP* fld_c_RETRIEVE_UP;
		c_SETUP_UP* fld_c_SETUP_UP;
		c_START_CC_UP* fld_c_START_CC_UP;
		c_START_DTMF_UP* fld_c_START_DTMF_UP;
		c_STATUS* fld_c_STATUS;
		c_STATUS_ENQUIRY* fld_c_STATUS_ENQUIRY;
		c_STOP_DTMF_UP* fld_c_STOP_DTMF_UP;
		c_USER_INFORMATION* fld_c_USER_INFORMATION;
		c_ATTACH_REQUEST_UP* fld_c_ATTACH_REQUEST_UP;
		c_ATTACH_COMPLETE_UP* fld_c_ATTACH_COMPLETE_UP;
		c_DETACH_REQUEST_UP* fld_c_DETACH_REQUEST_UP;
		c_DETACH_ACCEPT_UP* fld_c_DETACH_ACCEPT_UP;
		c_P_TMSI_REALLOCATION_COMPLETE_UP* fld_c_P_TMSI_REALLOCATION_COMPLETE_UP;
		c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP;
		c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP;
		c_IDENTITY_RESPONSE_B_UP* fld_c_IDENTITY_RESPONSE_B_UP;
		c_ROUTING_AREA_UPDATE_REQUEST_UP* fld_c_ROUTING_AREA_UPDATE_REQUEST_UP;
		c_ROUTING_AREA_UPDATE_COMPLETE_UP* fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP;
		c_GMM_STATUS* fld_c_GMM_STATUS;
		c_SERVICE_REQUEST_UP* fld_c_SERVICE_REQUEST_UP;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TL3Uplink_Data;
#define INIT_TL3Uplink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TL3Uplink_Data)), (sp)->Type=ID_L3Uplink_Unrecognized)
void FREE_TL3Uplink_Data (TL3Uplink_Data* sp);

int SETPRESENT_TL3Uplink_Data(TL3Uplink_Data* sp, TL3Uplink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group DummyDownlink
--------------------------------------------------------------------*/
typedef enum {
	ID_DummyDownlink_Unrecognized = 0,
	ID_DummyDownlink_SETUP_UP
} TDummyDownlink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group DummyDownlink
--------------------------------------------------------------------*/
typedef struct {
	TDummyDownlink_Type Type;
	int SkipIndicator;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_SETUP_UP* fld_c_SETUP_UP;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TDummyDownlink_Data;
#define INIT_TDummyDownlink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TDummyDownlink_Data)), (sp)->Type=ID_DummyDownlink_Unrecognized)
void FREE_TDummyDownlink_Data (TDummyDownlink_Data* sp);

int SETPRESENT_TDummyDownlink_Data(TDummyDownlink_Data* sp, TDummyDownlink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group L3Downlink
--------------------------------------------------------------------*/
typedef enum {
	ID_L3Downlink_Unrecognized = 0,
	ID_L3Downlink_AUTHENTICATION_REJECT_DN,
	ID_L3Downlink_AUTHENTICATION_REQUEST_DN,
	ID_L3Downlink_CM_SERVICE_ACCEPT_DN,
	ID_L3Downlink_CM_SERVICE_PROMPT_DN,
	ID_L3Downlink_CM_SERVICE_REJECT_DN,
	ID_L3Downlink_ABORT_DN,
	ID_L3Downlink_IDENTITY_REQUEST_DN,
	ID_L3Downlink_LOCATION_UPDATING_ACCEPT_DN,
	ID_L3Downlink_LOCATION_UPDATING_REJECT_DN,
	ID_L3Downlink_MM_INFORMATION_DN,
	ID_L3Downlink_MM_STATUS,
	ID_L3Downlink_TMSI_REALLOCATION_COMMAND_DN,
	ID_L3Downlink_ALERTING_DN,
	ID_L3Downlink_CALL_PROCEEDING_DN,
	ID_L3Downlink_CONGESTION_CONTROL_DN,
	ID_L3Downlink_CONNECT_DN,
	ID_L3Downlink_CONNECT_ACKNOWLEDGE,
	ID_L3Downlink_DISCONNECT_DN,
	ID_L3Downlink_FACILITY_DN,
	ID_L3Downlink_HOLD_ACKNOWLEDGE_DN,
	ID_L3Downlink_HOLD_REJECT_DN,
	ID_L3Downlink_MODIFY,
	ID_L3Downlink_MODIFY_COMPLETE,
	ID_L3Downlink_MODIFY_REJECT,
	ID_L3Downlink_NOTIFY,
	ID_L3Downlink_PROGRESS_DN,
	ID_L3Downlink_CC_ESTABLISHMENT_DN,
	ID_L3Downlink_RELEASE_DN,
	ID_L3Downlink_RECALL_DN,
	ID_L3Downlink_RELEASE_COMPLETE_DN,
	ID_L3Downlink_RETRIEVE_ACKNOWLEDGE_DN,
	ID_L3Downlink_RETRIEVE_REJECT_DN,
	ID_L3Downlink_SETUP_DN,
	ID_L3Downlink_START_DTMF_ACKNOWLEDGE_DN,
	ID_L3Downlink_START_DTMF_REJECT_DN,
	ID_L3Downlink_STATUS,
	ID_L3Downlink_STATUS_ENQUIRY,
	ID_L3Downlink_STOP_DTMF_ACKNOWLEDGE_DN,
	ID_L3Downlink_USER_INFORMATION,
	ID_L3Downlink_ATTACH_REQUEST_UP,
	ID_L3Downlink_ATTACH_ACCEPT_DN,
	ID_L3Downlink_ATTACH_REJECT_DN,
	ID_L3Downlink_DETACH_REQUEST_DN,
	ID_L3Downlink_DETACH_ACCEPT_DN,
	ID_L3Downlink_P_TMSI_REALLOCATION_COMMAND_DN,
	ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REQUEST_DN,
	ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REJECT_DN,
	ID_L3Downlink_IDENTITY_REQUEST_B_DN,
	ID_L3Downlink_ROUTING_AREA_UPDATE_ACCEPT_DN,
	ID_L3Downlink_ROUTING_AREA_UPDATE_REJECT_DN,
	ID_L3Downlink_GMM_STATUS,
	ID_L3Downlink_GMM_INFORMATION_DN,
	ID_L3Downlink_SERVICE_ACCEPT_DN,
	ID_L3Downlink_SERVICE_REJECT_DN
} TL3Downlink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group L3Downlink
--------------------------------------------------------------------*/
typedef struct {
	TL3Downlink_Type Type;
	int SkipIndicator;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_AUTHENTICATION_REJECT_DN* fld_c_AUTHENTICATION_REJECT_DN;
		c_AUTHENTICATION_REQUEST_DN* fld_c_AUTHENTICATION_REQUEST_DN;
		c_CM_SERVICE_ACCEPT_DN* fld_c_CM_SERVICE_ACCEPT_DN;
		c_CM_SERVICE_PROMPT_DN* fld_c_CM_SERVICE_PROMPT_DN;
		c_CM_SERVICE_REJECT_DN* fld_c_CM_SERVICE_REJECT_DN;
		c_ABORT_DN* fld_c_ABORT_DN;
		c_IDENTITY_REQUEST_DN* fld_c_IDENTITY_REQUEST_DN;
		c_LOCATION_UPDATING_ACCEPT_DN* fld_c_LOCATION_UPDATING_ACCEPT_DN;
		c_LOCATION_UPDATING_REJECT_DN* fld_c_LOCATION_UPDATING_REJECT_DN;
		c_MM_INFORMATION_DN* fld_c_MM_INFORMATION_DN;
		c_MM_STATUS* fld_c_MM_STATUS;
		c_TMSI_REALLOCATION_COMMAND_DN* fld_c_TMSI_REALLOCATION_COMMAND_DN;
		c_ALERTING_DN* fld_c_ALERTING_DN;
		c_CALL_PROCEEDING_DN* fld_c_CALL_PROCEEDING_DN;
		c_CONGESTION_CONTROL_DN* fld_c_CONGESTION_CONTROL_DN;
		c_CONNECT_DN* fld_c_CONNECT_DN;
		c_CONNECT_ACKNOWLEDGE* fld_c_CONNECT_ACKNOWLEDGE;
		c_DISCONNECT_DN* fld_c_DISCONNECT_DN;
		c_FACILITY_DN* fld_c_FACILITY_DN;
		c_HOLD_ACKNOWLEDGE_DN* fld_c_HOLD_ACKNOWLEDGE_DN;
		c_HOLD_REJECT_DN* fld_c_HOLD_REJECT_DN;
		c_MODIFY* fld_c_MODIFY;
		c_MODIFY_COMPLETE* fld_c_MODIFY_COMPLETE;
		c_MODIFY_REJECT* fld_c_MODIFY_REJECT;
		c_NOTIFY* fld_c_NOTIFY;
		c_PROGRESS_DN* fld_c_PROGRESS_DN;
		c_CC_ESTABLISHMENT_DN* fld_c_CC_ESTABLISHMENT_DN;
		c_RELEASE_DN* fld_c_RELEASE_DN;
		c_RECALL_DN* fld_c_RECALL_DN;
		c_RELEASE_COMPLETE_DN* fld_c_RELEASE_COMPLETE_DN;
		c_RETRIEVE_ACKNOWLEDGE_DN* fld_c_RETRIEVE_ACKNOWLEDGE_DN;
		c_RETRIEVE_REJECT_DN* fld_c_RETRIEVE_REJECT_DN;
		c_SETUP_DN* fld_c_SETUP_DN;
		c_START_DTMF_ACKNOWLEDGE_DN* fld_c_START_DTMF_ACKNOWLEDGE_DN;
		c_START_DTMF_REJECT_DN* fld_c_START_DTMF_REJECT_DN;
		c_STATUS* fld_c_STATUS;
		c_STATUS_ENQUIRY* fld_c_STATUS_ENQUIRY;
		c_STOP_DTMF_ACKNOWLEDGE_DN* fld_c_STOP_DTMF_ACKNOWLEDGE_DN;
		c_USER_INFORMATION* fld_c_USER_INFORMATION;
		c_ATTACH_REQUEST_UP* fld_c_ATTACH_REQUEST_UP;
		c_ATTACH_ACCEPT_DN* fld_c_ATTACH_ACCEPT_DN;
		c_ATTACH_REJECT_DN* fld_c_ATTACH_REJECT_DN;
		c_DETACH_REQUEST_DN* fld_c_DETACH_REQUEST_DN;
		c_DETACH_ACCEPT_DN* fld_c_DETACH_ACCEPT_DN;
		c_P_TMSI_REALLOCATION_COMMAND_DN* fld_c_P_TMSI_REALLOCATION_COMMAND_DN;
		c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN;
		c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN;
		c_IDENTITY_REQUEST_B_DN* fld_c_IDENTITY_REQUEST_B_DN;
		c_ROUTING_AREA_UPDATE_ACCEPT_DN* fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN;
		c_ROUTING_AREA_UPDATE_REJECT_DN* fld_c_ROUTING_AREA_UPDATE_REJECT_DN;
		c_GMM_STATUS* fld_c_GMM_STATUS;
		c_GMM_INFORMATION_DN* fld_c_GMM_INFORMATION_DN;
		c_SERVICE_ACCEPT_DN* fld_c_SERVICE_ACCEPT_DN;
		c_SERVICE_REJECT_DN* fld_c_SERVICE_REJECT_DN;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TL3Downlink_Data;
#define INIT_TL3Downlink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TL3Downlink_Data)), (sp)->Type=ID_L3Downlink_Unrecognized)
void FREE_TL3Downlink_Data (TL3Downlink_Data* sp);

int SETPRESENT_TL3Downlink_Data(TL3Downlink_Data* sp, TL3Downlink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group XTIDUplink
--------------------------------------------------------------------*/
typedef enum {
	ID_XTIDUplink_Unrecognized = 0,
	ID_XTIDUplink_ACTIVATE_PDP_CONTEXT_REQUEST_UP,
	ID_XTIDUplink_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP,
	ID_XTIDUplink_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP,
	ID_XTIDUplink_MODIFY_PDP_CONTEXT_REQUEST_UP,
	ID_XTIDUplink_MODIFY_PDP_CONTEXT_ACCEPT_UP,
	ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_REQUEST,
	ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_ACCEPT,
	ID_XTIDUplink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT,
	ID_XTIDUplink_SM_STATUS,
	ID_XTIDUplink_ACTIVATE_MBMS_CONTEXT_REQUEST,
	ID_XTIDUplink_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT
} TXTIDUplink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group XTIDUplink
--------------------------------------------------------------------*/
typedef struct {
	TXTIDUplink_Type Type;
	int SkipIndicator;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP;
		c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP;
		c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP;
		c_MODIFY_PDP_CONTEXT_REQUEST_UP* fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP;
		c_MODIFY_PDP_CONTEXT_ACCEPT_UP* fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP;
		c_DEACTIVATE_PDP_CONTEXT_REQUEST* fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST;
		c_DEACTIVATE_PDP_CONTEXT_ACCEPT* fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT;
		c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT;
		c_SM_STATUS* fld_c_SM_STATUS;
		c_ACTIVATE_MBMS_CONTEXT_REQUEST* fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST;
		c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TXTIDUplink_Data;
#define INIT_TXTIDUplink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TXTIDUplink_Data)), (sp)->Type=ID_XTIDUplink_Unrecognized)
void FREE_TXTIDUplink_Data (TXTIDUplink_Data* sp);

int SETPRESENT_TXTIDUplink_Data(TXTIDUplink_Data* sp, TXTIDUplink_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group XTIDDownlink
--------------------------------------------------------------------*/
typedef enum {
	ID_XTIDDownlink_Unrecognized = 0,
	ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_ACCEPT_DN,
	ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_REJECT_DN,
	ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN,
	ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN,
	ID_XTIDDownlink_REQUEST_PDP_CONTEXT_ACTIVATION_DN,
	ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REQUEST_DN,
	ID_XTIDDownlink_MODIFY_PDP_CONTEXT_ACCEPT_DN,
	ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REJECT_DN,
	ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_REQUEST,
	ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_ACCEPT,
	ID_XTIDDownlink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION,
	ID_XTIDDownlink_NOTIFICATION,
	ID_XTIDDownlink_SM_STATUS,
	ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_ACCEPT,
	ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_REJECT,
	ID_XTIDDownlink_REQUEST_MBMS_CONTEXT_ACTIVATION
} TXTIDDownlink_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group XTIDDownlink
--------------------------------------------------------------------*/
typedef struct {
	TXTIDDownlink_Type Type;
	int SkipIndicator;
	int ProtocolDiscriminator;
	int MessageType;
	union {
		c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN;
		c_ACTIVATE_PDP_CONTEXT_REJECT_DN* fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN;
		c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN;
		c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN;
		c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN;
		c_MODIFY_PDP_CONTEXT_REQUEST_DN* fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN;
		c_MODIFY_PDP_CONTEXT_ACCEPT_DN* fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN;
		c_MODIFY_PDP_CONTEXT_REJECT_DN* fld_c_MODIFY_PDP_CONTEXT_REJECT_DN;
		c_DEACTIVATE_PDP_CONTEXT_REQUEST* fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST;
		c_DEACTIVATE_PDP_CONTEXT_ACCEPT* fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT;
		c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION;
		c_NOTIFICATION* fld_c_NOTIFICATION;
		c_SM_STATUS* fld_c_SM_STATUS;
		c_ACTIVATE_MBMS_CONTEXT_ACCEPT* fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT;
		c_ACTIVATE_MBMS_CONTEXT_REJECT* fld_c_ACTIVATE_MBMS_CONTEXT_REJECT;
		c_REQUEST_MBMS_CONTEXT_ACTIVATION* fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TXTIDDownlink_Data;
#define INIT_TXTIDDownlink_Data(sp) (ED_RESET_MEM ((sp), sizeof (TXTIDDownlink_Data)), (sp)->Type=ID_XTIDDownlink_Unrecognized)
void FREE_TXTIDDownlink_Data (TXTIDDownlink_Data* sp);

int SETPRESENT_TXTIDDownlink_Data(TXTIDDownlink_Data* sp, TXTIDDownlink_Type toBeSetPresent);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_L3Uplink (const char* buffer, TL3Uplink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_L3Uplink (const char* buffer, int len, TL3Uplink_Data* data);
#endif

/* Set encode function */
int SetEncode_L3Uplink (char* buffer, ED_EXLONG bitOffset, TL3Uplink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_DummyDownlink (const char* buffer, TDummyDownlink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_DummyDownlink (const char* buffer, int len, TDummyDownlink_Data* data);
#endif

/* Set encode function */
int SetEncode_DummyDownlink (char* buffer, ED_EXLONG bitOffset, TDummyDownlink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_L3Downlink (const char* buffer, TL3Downlink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_L3Downlink (const char* buffer, int len, TL3Downlink_Data* data);
#endif

/* Set encode function */
int SetEncode_L3Downlink (char* buffer, ED_EXLONG bitOffset, TL3Downlink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_XTIDUplink (const char* buffer, TXTIDUplink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_XTIDUplink (const char* buffer, int len, TXTIDUplink_Data* data);
#endif

/* Set encode function */
int SetEncode_XTIDUplink (char* buffer, ED_EXLONG bitOffset, TXTIDUplink_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_XTIDDownlink (const char* buffer, TXTIDDownlink_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_XTIDDownlink (const char* buffer, int len, TXTIDDownlink_Data* data);
#endif

/* Set encode function */
int SetEncode_XTIDDownlink (char* buffer, ED_EXLONG bitOffset, TXTIDDownlink_Data* data);

#ifdef __cplusplus
	}
#endif
#endif

