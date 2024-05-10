/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_recog_RLCMAC_h
#define __ed_c_recog_RLCMAC_h

#include "ed_c_RLCMAC.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#include "ed_user.h"
#define ED_MAXSIZE 600
#include "endec_configs_RLCMAC.h"

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group Downlink_RLC_MAC
--------------------------------------------------------------------*/
typedef enum {
	ID_Downlink_RLC_MAC_Unrecognized = 0,
	ID_Downlink_RLC_MAC_Packet_Cell_Change_Order,
	ID_Downlink_RLC_MAC_Packet_Downlink_Assignment,
	ID_Downlink_RLC_MAC_Packet_Measurement_Order,
	ID_Downlink_RLC_MAC_Packet_Polling_Request,
	ID_Downlink_RLC_MAC_Packet_Power_Control_Timing_Advance,
	ID_Downlink_RLC_MAC_Packet_Queueing_Notification,
	ID_Downlink_RLC_MAC_Packet_Timeslot_Reconfigure,
	ID_Downlink_RLC_MAC_Packet_TBF_Release,
	ID_Downlink_RLC_MAC_Packet_Uplink_Ack_Nack,
	ID_Downlink_RLC_MAC_Packet_Uplink_Assignment,
	ID_Downlink_RLC_MAC_Packet_Cell_Change_Continue,
	ID_Downlink_RLC_MAC_Packet_Neighbour_Cell_Data,
	ID_Downlink_RLC_MAC_Packet_Serving_Cell_Data,
	ID_Downlink_RLC_MAC_Packet_DBPSCH_Assignment,
	ID_Downlink_RLC_MAC_Multiple_TBF_Downlink_Assignment,
	ID_Downlink_RLC_MAC_Packet_Access_Reject,
	ID_Downlink_RLC_MAC_Packet_Paging_Request,
	ID_Downlink_RLC_MAC_Packet_PDCH_Release,
	ID_Downlink_RLC_MAC_Packet_PRACH_Parameters,
	ID_Downlink_RLC_MAC_Packet_Downlink_Dummy_Control_Block,
	ID_Downlink_RLC_MAC_PSI16,
	ID_Downlink_RLC_MAC_PSI6,
	ID_Downlink_RLC_MAC_PSI1,
	ID_Downlink_RLC_MAC_PSI2,
	ID_Downlink_RLC_MAC_PSI3,
	ID_Downlink_RLC_MAC_PSI3_bis,
	ID_Downlink_RLC_MAC_PSI4,
	ID_Downlink_RLC_MAC_PSI5,
	ID_Downlink_RLC_MAC_PSI13,
	ID_Downlink_RLC_MAC_PSI7,
	ID_Downlink_RLC_MAC_PSI8,
	ID_Downlink_RLC_MAC_PSI14,
	ID_Downlink_RLC_MAC_PSI3_ter,
	ID_Downlink_RLC_MAC_PSI3_quater,
	ID_Downlink_RLC_MAC_PSI15,
	ID_Downlink_RLC_MAC_Multiple_TBF_Uplink_Assignment,
	ID_Downlink_RLC_MAC_Multiple_TBF_Timeslot_Reconfigure,
	ID_Downlink_RLC_MAC_MBMS_MS_ID_Assignment,
	ID_Downlink_RLC_MAC_MBMS_Assignment_Non_distribution,
	ID_Downlink_RLC_MAC_PS_Handover_Command,
	ID_Downlink_RLC_MAC_Packet_Physical_Information,
	ID_Downlink_RLC_MAC_Packet_Serving_Cell_SI,
	ID_Downlink_RLC_MAC_Packet_CS_Command,
	ID_Downlink_RLC_MAC_Packet_CS_Release,
	ID_Downlink_RLC_MAC_MBMS_Assignment_Distribution,
	ID_Downlink_RLC_MAC_MBMS_Neighbouring_Cell_Information,
	ID_Downlink_RLC_MAC_Packet_MBMS_Announcement
} TDownlink_RLC_MAC_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group Downlink_RLC_MAC
--------------------------------------------------------------------*/
typedef struct {
	TDownlink_RLC_MAC_Type Type;
	int MessageType;
	union {
		c_Packet_Cell_Change_Order* fld_c_Packet_Cell_Change_Order;
		c_Packet_Downlink_Assignment* fld_c_Packet_Downlink_Assignment;
		c_Packet_Measurement_Order* fld_c_Packet_Measurement_Order;
		c_Packet_Polling_Request* fld_c_Packet_Polling_Request;
		c_Packet_Power_Control_Timing_Advance* fld_c_Packet_Power_Control_Timing_Advance;
		c_Packet_Queueing_Notification* fld_c_Packet_Queueing_Notification;
		c_Packet_Timeslot_Reconfigure* fld_c_Packet_Timeslot_Reconfigure;
		c_Packet_TBF_Release* fld_c_Packet_TBF_Release;
		c_Packet_Uplink_Ack_Nack* fld_c_Packet_Uplink_Ack_Nack;
		c_Packet_Uplink_Assignment* fld_c_Packet_Uplink_Assignment;
		c_Packet_Cell_Change_Continue* fld_c_Packet_Cell_Change_Continue;
		c_Packet_Neighbour_Cell_Data* fld_c_Packet_Neighbour_Cell_Data;
		c_Packet_Serving_Cell_Data* fld_c_Packet_Serving_Cell_Data;
		c_Packet_DBPSCH_Assignment* fld_c_Packet_DBPSCH_Assignment;
		c_Multiple_TBF_Downlink_Assignment* fld_c_Multiple_TBF_Downlink_Assignment;
		c_Packet_Access_Reject* fld_c_Packet_Access_Reject;
		c_Packet_Paging_Request* fld_c_Packet_Paging_Request;
		c_Packet_PDCH_Release* fld_c_Packet_PDCH_Release;
		c_Packet_PRACH_Parameters* fld_c_Packet_PRACH_Parameters;
		c_Packet_Downlink_Dummy_Control_Block* fld_c_Packet_Downlink_Dummy_Control_Block;
		c_PSI16* fld_c_PSI16;
		c_PSI6* fld_c_PSI6;
		c_PSI1* fld_c_PSI1;
		c_PSI2* fld_c_PSI2;
		c_PSI3* fld_c_PSI3;
		c_PSI3_bis* fld_c_PSI3_bis;
		c_PSI4* fld_c_PSI4;
		c_PSI5* fld_c_PSI5;
		c_PSI13* fld_c_PSI13;
		c_PSI7* fld_c_PSI7;
		c_PSI8* fld_c_PSI8;
		c_PSI14* fld_c_PSI14;
		c_PSI3_ter* fld_c_PSI3_ter;
		c_PSI3_quater* fld_c_PSI3_quater;
		c_PSI15* fld_c_PSI15;
		c_Multiple_TBF_Uplink_Assignment* fld_c_Multiple_TBF_Uplink_Assignment;
		c_Multiple_TBF_Timeslot_Reconfigure* fld_c_Multiple_TBF_Timeslot_Reconfigure;
		c_MBMS_MS_ID_Assignment* fld_c_MBMS_MS_ID_Assignment;
		c_MBMS_Assignment_Non_distribution* fld_c_MBMS_Assignment_Non_distribution;
		c_PS_Handover_Command* fld_c_PS_Handover_Command;
		c_Packet_Physical_Information* fld_c_Packet_Physical_Information;
		c_Packet_Serving_Cell_SI* fld_c_Packet_Serving_Cell_SI;
		c_Packet_CS_Command* fld_c_Packet_CS_Command;
		c_Packet_CS_Release* fld_c_Packet_CS_Release;
		c_MBMS_Assignment_Distribution* fld_c_MBMS_Assignment_Distribution;
		c_MBMS_Neighbouring_Cell_Information* fld_c_MBMS_Neighbouring_Cell_Information;
		c_Packet_MBMS_Announcement* fld_c_Packet_MBMS_Announcement;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TDownlink_RLC_MAC_Data;
#define INIT_TDownlink_RLC_MAC_Data(sp) (ED_RESET_MEM ((sp), sizeof (TDownlink_RLC_MAC_Data)), (sp)->Type=ID_Downlink_RLC_MAC_Unrecognized)
void FREE_TDownlink_RLC_MAC_Data (TDownlink_RLC_MAC_Data* sp);

int SETPRESENT_TDownlink_RLC_MAC_Data(TDownlink_RLC_MAC_Data* sp, TDownlink_RLC_MAC_Type toBeSetPresent);

/*--------------------------------------------------------------------
	Enum representing a tag for every message in group Uplink_RLC_MAC
--------------------------------------------------------------------*/
typedef enum {
	ID_Uplink_RLC_MAC_Unrecognized = 0,
	ID_Uplink_RLC_MAC_Packet_Cell_Change_Failure,
	ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement,
	ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_a,
	ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_11bit_b,
	ID_Uplink_RLC_MAC_Packet_Control_Acknowledgement_8bit,
	ID_Uplink_RLC_MAC_Packet_Downlink_Ack_Nack,
	ID_Uplink_RLC_MAC_Packet_Uplink_Dummy_Control_Block,
	ID_Uplink_RLC_MAC_Packet_Measurement_Report,
	ID_Uplink_RLC_MAC_Packet_Resource_Request,
	ID_Uplink_RLC_MAC_Packet_Mobile_TBF_Status,
	ID_Uplink_RLC_MAC_Packet_PSI_Status,
	ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack,
	ID_Uplink_RLC_MAC_Packet_Pause,
	ID_Uplink_RLC_MAC_Packet_Enhanced_Measurement_Report,
	ID_Uplink_RLC_MAC_Additional_MS_Radio_Access_Capabilities,
	ID_Uplink_RLC_MAC_Packet_Cell_Change_Notification,
	ID_Uplink_RLC_MAC_Packet_SI_Status,
	ID_Uplink_RLC_MAC_Packet_CS_Request,
	ID_Uplink_RLC_MAC_MBMS_Service_Request,
	ID_Uplink_RLC_MAC_MBMS_Downlink_Ack_Nack,
	ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_Type_3,
	ID_Uplink_RLC_MAC_EGPRS_Packet_Downlink_Ack_Nack_DLMC
} TUplink_RLC_MAC_Type;

/*--------------------------------------------------------------------
	Union containing data for every message in group Uplink_RLC_MAC
--------------------------------------------------------------------*/
typedef struct {
	TUplink_RLC_MAC_Type Type;
	int MessageType;
	union {
		c_Packet_Cell_Change_Failure* fld_c_Packet_Cell_Change_Failure;
		c_Packet_Control_Acknowledgement* fld_c_Packet_Control_Acknowledgement;
		c_Packet_Control_Acknowledgement_11bit_a* fld_c_Packet_Control_Acknowledgement_11bit_a;
		c_Packet_Control_Acknowledgement_11bit_b* fld_c_Packet_Control_Acknowledgement_11bit_b;
		c_Packet_Control_Acknowledgement_8bit* fld_c_Packet_Control_Acknowledgement_8bit;
		c_Packet_Downlink_Ack_Nack* fld_c_Packet_Downlink_Ack_Nack;
		c_Packet_Uplink_Dummy_Control_Block* fld_c_Packet_Uplink_Dummy_Control_Block;
		c_Packet_Measurement_Report* fld_c_Packet_Measurement_Report;
		c_Packet_Resource_Request* fld_c_Packet_Resource_Request;
		c_Packet_Mobile_TBF_Status* fld_c_Packet_Mobile_TBF_Status;
		c_Packet_PSI_Status* fld_c_Packet_PSI_Status;
		c_EGPRS_Packet_Downlink_Ack_Nack* fld_c_EGPRS_Packet_Downlink_Ack_Nack;
		c_Packet_Pause* fld_c_Packet_Pause;
		c_Packet_Enhanced_Measurement_Report* fld_c_Packet_Enhanced_Measurement_Report;
		c_Additional_MS_Radio_Access_Capabilities* fld_c_Additional_MS_Radio_Access_Capabilities;
		c_Packet_Cell_Change_Notification* fld_c_Packet_Cell_Change_Notification;
		c_Packet_SI_Status* fld_c_Packet_SI_Status;
		c_Packet_CS_Request* fld_c_Packet_CS_Request;
		c_MBMS_Service_Request* fld_c_MBMS_Service_Request;
		c_MBMS_Downlink_Ack_Nack* fld_c_MBMS_Downlink_Ack_Nack;
		c_EGPRS_Packet_Downlink_Ack_Nack_Type_3* fld_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3;
		c_EGPRS_Packet_Downlink_Ack_Nack_DLMC* fld_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC;
		char Dummy; /* Avoids empty unions! */
	} Data;
} TUplink_RLC_MAC_Data;
#define INIT_TUplink_RLC_MAC_Data(sp) (ED_RESET_MEM ((sp), sizeof (TUplink_RLC_MAC_Data)), (sp)->Type=ID_Uplink_RLC_MAC_Unrecognized)
void FREE_TUplink_RLC_MAC_Data (TUplink_RLC_MAC_Data* sp);

int SETPRESENT_TUplink_RLC_MAC_Data(TUplink_RLC_MAC_Data* sp, TUplink_RLC_MAC_Type toBeSetPresent);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_Downlink_RLC_MAC (const char* buffer, TDownlink_RLC_MAC_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Downlink_RLC_MAC (const char* buffer, int len, TDownlink_RLC_MAC_Data* data);
#endif

/* Set encode function */
int SetEncode_Downlink_RLC_MAC (char* buffer, ED_EXLONG bitOffset, TDownlink_RLC_MAC_Data* data);


/*-------------------------------------------------------------------------------
	Returns number of consumed bits (>=0) if recognized. <0 otherwise.
	Parameter 'len' is expressed in octets, while 'bitLen' is in bits.

-------------------------------------------------------------------------------*/
int SetDecode_Uplink_RLC_MAC (const char* buffer, TUplink_RLC_MAC_Data* data, int bitLen);

/* Maintains compatibility with Encodix 1.0.33 and before */
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Uplink_RLC_MAC (const char* buffer, int len, TUplink_RLC_MAC_Data* data);
#endif

/* Set encode function */
int SetEncode_Uplink_RLC_MAC (char* buffer, ED_EXLONG bitOffset, TUplink_RLC_MAC_Data* data);

#ifdef __cplusplus
	}
#endif
#endif

