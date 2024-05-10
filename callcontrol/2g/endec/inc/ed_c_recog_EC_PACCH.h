/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_recog_EC_PACCH_h
#define __ed_c_recog_EC_PACCH_h

#include "ed_c_EC_PACCH.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#include "ed_user.h"
#define ED_MAXSIZE 600
#include "endec_configs_EC_PACCH.h"

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group Downlink_RLC_MAC_EC_PACCH
--------------------------------------------------------------------*/
typedef enum {
	ID_Downlink_RLC_MAC_EC_PACCH_Unrecognized = 0,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Access_Reject,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Assignment,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Polling_Request,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Power_Control_Timing_Advance,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_TBF_Release,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Assignment,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution,
	ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Dummy_Control_Block
} TDownlink_RLC_MAC_EC_PACCH_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group Downlink_RLC_MAC_EC_PACCH
--------------------------------------------------------------------*/
typedef struct {
	TDownlink_RLC_MAC_EC_PACCH_Type Type;
	int MessageType;
	union {
		c_EC_Packet_Access_Reject* fld_c_EC_Packet_Access_Reject;
		c_EC_Packet_Downlink_Assignment* fld_c_EC_Packet_Downlink_Assignment;
		c_EC_Packet_Polling_Request* fld_c_EC_Packet_Polling_Request;
		c_EC_Packet_Power_Control_Timing_Advance* fld_c_EC_Packet_Power_Control_Timing_Advance;
		c_EC_Packet_TBF_Release* fld_c_EC_Packet_TBF_Release;
		c_EC_Packet_Uplink_Ack_Nack* fld_c_EC_Packet_Uplink_Ack_Nack;
		c_EC_Packet_Uplink_Assignment* fld_c_EC_Packet_Uplink_Assignment;
		c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution;
		c_EC_Packet_Downlink_Dummy_Control_Block* fld_c_EC_Packet_Downlink_Dummy_Control_Block;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TDownlink_RLC_MAC_EC_PACCH_Data;
#define INIT_TDownlink_RLC_MAC_EC_PACCH_Data(sp) (ED_RESET_MEM ((sp), sizeof (TDownlink_RLC_MAC_EC_PACCH_Data)), (sp)->Type=ID_Downlink_RLC_MAC_EC_PACCH_Unrecognized)
void FREE_TDownlink_RLC_MAC_EC_PACCH_Data (TDownlink_RLC_MAC_EC_PACCH_Data* sp);

int SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data(TDownlink_RLC_MAC_EC_PACCH_Data* sp, TDownlink_RLC_MAC_EC_PACCH_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group Uplink_RLC_MAC_EC_PACCH
--------------------------------------------------------------------*/
typedef enum {
	ID_Uplink_RLC_MAC_EC_PACCH_Unrecognized = 0,
	ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Control_Acknowledgement,
	ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Ack_Nack
} TUplink_RLC_MAC_EC_PACCH_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group Uplink_RLC_MAC_EC_PACCH
--------------------------------------------------------------------*/
typedef struct {
	TUplink_RLC_MAC_EC_PACCH_Type Type;
	int MessageType;
	union {
		c_EC_Packet_Control_Acknowledgement* fld_c_EC_Packet_Control_Acknowledgement;
		c_EC_Packet_Downlink_Ack_Nack* fld_c_EC_Packet_Downlink_Ack_Nack;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TUplink_RLC_MAC_EC_PACCH_Data;
#define INIT_TUplink_RLC_MAC_EC_PACCH_Data(sp) (ED_RESET_MEM ((sp), sizeof (TUplink_RLC_MAC_EC_PACCH_Data)), (sp)->Type=ID_Uplink_RLC_MAC_EC_PACCH_Unrecognized)
void FREE_TUplink_RLC_MAC_EC_PACCH_Data (TUplink_RLC_MAC_EC_PACCH_Data* sp);

int SETPRESENT_TUplink_RLC_MAC_EC_PACCH_Data(TUplink_RLC_MAC_EC_PACCH_Data* sp, TUplink_RLC_MAC_EC_PACCH_Type toBeSetPresent);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_Downlink_RLC_MAC_EC_PACCH (const char* buffer, TDownlink_RLC_MAC_EC_PACCH_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Downlink_RLC_MAC_EC_PACCH (const char* buffer, int len, TDownlink_RLC_MAC_EC_PACCH_Data* data);
#endif

/* Set encode function */
int SetEncode_Downlink_RLC_MAC_EC_PACCH (char* buffer, ED_EXLONG bitOffset, TDownlink_RLC_MAC_EC_PACCH_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_Uplink_RLC_MAC_EC_PACCH (const char* buffer, TUplink_RLC_MAC_EC_PACCH_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Uplink_RLC_MAC_EC_PACCH (const char* buffer, int len, TUplink_RLC_MAC_EC_PACCH_Data* data);
#endif

/* Set encode function */
int SetEncode_Uplink_RLC_MAC_EC_PACCH (char* buffer, ED_EXLONG bitOffset, TUplink_RLC_MAC_EC_PACCH_Data* data);

#ifdef __cplusplus
	}
#endif
#endif

