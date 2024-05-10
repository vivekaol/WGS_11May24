/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-recog
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_recog_EC_PACCH.h"
#include "ed_lib.h"
#include "Downlink_RLC_MAC_EC_PACCH_EC_PACCH.h"
#include "Uplink_RLC_MAC_EC_PACCH_EC_PACCH.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


int SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (TDownlink_RLC_MAC_EC_PACCH_Data* sp, TDownlink_RLC_MAC_EC_PACCH_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TDownlink_RLC_MAC_EC_PACCH_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Access_Reject: {
			sp->Data.fld_c_EC_Packet_Access_Reject = (c_EC_Packet_Access_Reject*)EDAlloc (sizeof (c_EC_Packet_Access_Reject)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Access_Reject == NULL)
			INIT_c_EC_Packet_Access_Reject (sp->Data.fld_c_EC_Packet_Access_Reject);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Assignment: {
			sp->Data.fld_c_EC_Packet_Downlink_Assignment = (c_EC_Packet_Downlink_Assignment*)EDAlloc (sizeof (c_EC_Packet_Downlink_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Downlink_Assignment == NULL)
			INIT_c_EC_Packet_Downlink_Assignment (sp->Data.fld_c_EC_Packet_Downlink_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Polling_Request: {
			sp->Data.fld_c_EC_Packet_Polling_Request = (c_EC_Packet_Polling_Request*)EDAlloc (sizeof (c_EC_Packet_Polling_Request)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Polling_Request == NULL)
			INIT_c_EC_Packet_Polling_Request (sp->Data.fld_c_EC_Packet_Polling_Request);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Power_Control_Timing_Advance: {
			sp->Data.fld_c_EC_Packet_Power_Control_Timing_Advance = (c_EC_Packet_Power_Control_Timing_Advance*)EDAlloc (sizeof (c_EC_Packet_Power_Control_Timing_Advance)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Power_Control_Timing_Advance == NULL)
			INIT_c_EC_Packet_Power_Control_Timing_Advance (sp->Data.fld_c_EC_Packet_Power_Control_Timing_Advance);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_TBF_Release: {
			sp->Data.fld_c_EC_Packet_TBF_Release = (c_EC_Packet_TBF_Release*)EDAlloc (sizeof (c_EC_Packet_TBF_Release)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_TBF_Release == NULL)
			INIT_c_EC_Packet_TBF_Release (sp->Data.fld_c_EC_Packet_TBF_Release);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack: {
			sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack = (c_EC_Packet_Uplink_Ack_Nack*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack == NULL)
			INIT_c_EC_Packet_Uplink_Ack_Nack (sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Assignment: {
			sp->Data.fld_c_EC_Packet_Uplink_Assignment = (c_EC_Packet_Uplink_Assignment*)EDAlloc (sizeof (c_EC_Packet_Uplink_Assignment)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Uplink_Assignment == NULL)
			INIT_c_EC_Packet_Uplink_Assignment (sp->Data.fld_c_EC_Packet_Uplink_Assignment);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution: {
			sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution = (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution*)EDAlloc (sizeof (c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution == NULL)
			INIT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution);
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Dummy_Control_Block: {
			sp->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block = (c_EC_Packet_Downlink_Dummy_Control_Block*)EDAlloc (sizeof (c_EC_Packet_Downlink_Dummy_Control_Block)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block == NULL)
			INIT_c_EC_Packet_Downlink_Dummy_Control_Block (sp->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TDownlink_RLC_MAC_EC_PACCH_Data (TDownlink_RLC_MAC_EC_PACCH_Data* sp)
{
	switch (sp->Type) {
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Access_Reject: {
			FREE_c_EC_Packet_Access_Reject (sp->Data.fld_c_EC_Packet_Access_Reject);
	EDFree (sp->Data.fld_c_EC_Packet_Access_Reject );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Assignment: {
			FREE_c_EC_Packet_Downlink_Assignment (sp->Data.fld_c_EC_Packet_Downlink_Assignment);
	EDFree (sp->Data.fld_c_EC_Packet_Downlink_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Polling_Request: {
			FREE_c_EC_Packet_Polling_Request (sp->Data.fld_c_EC_Packet_Polling_Request);
	EDFree (sp->Data.fld_c_EC_Packet_Polling_Request );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Power_Control_Timing_Advance: {
			FREE_c_EC_Packet_Power_Control_Timing_Advance (sp->Data.fld_c_EC_Packet_Power_Control_Timing_Advance);
	EDFree (sp->Data.fld_c_EC_Packet_Power_Control_Timing_Advance );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_TBF_Release: {
			FREE_c_EC_Packet_TBF_Release (sp->Data.fld_c_EC_Packet_TBF_Release);
	EDFree (sp->Data.fld_c_EC_Packet_TBF_Release );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack: {
			FREE_c_EC_Packet_Uplink_Ack_Nack (sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack);
	EDFree (sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Assignment: {
			FREE_c_EC_Packet_Uplink_Assignment (sp->Data.fld_c_EC_Packet_Uplink_Assignment);
	EDFree (sp->Data.fld_c_EC_Packet_Uplink_Assignment );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution: {
			FREE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution);
	EDFree (sp->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution );
			break;
		}
		
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Dummy_Control_Block: {
			FREE_c_EC_Packet_Downlink_Dummy_Control_Block (sp->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block);
	EDFree (sp->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block );
			break;
		}
		
		default:;
	}

	sp->Type = ID_Downlink_RLC_MAC_EC_PACCH_Unrecognized;
}

int SETPRESENT_TUplink_RLC_MAC_EC_PACCH_Data (TUplink_RLC_MAC_EC_PACCH_Data* sp, TUplink_RLC_MAC_EC_PACCH_Type toBeSetPresent)
{
	if (sp->Type == toBeSetPresent) return ED_NO_ERRORS;
	FREE_TUplink_RLC_MAC_EC_PACCH_Data (sp);
	sp->Type = toBeSetPresent;

	switch (sp->Type) {
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Control_Acknowledgement: {
			sp->Data.fld_c_EC_Packet_Control_Acknowledgement = (c_EC_Packet_Control_Acknowledgement*)EDAlloc (sizeof (c_EC_Packet_Control_Acknowledgement)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Control_Acknowledgement == NULL)
			INIT_c_EC_Packet_Control_Acknowledgement (sp->Data.fld_c_EC_Packet_Control_Acknowledgement);
			break;
		}
		
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Ack_Nack: {
			sp->Data.fld_c_EC_Packet_Downlink_Ack_Nack = (c_EC_Packet_Downlink_Ack_Nack*)EDAlloc (sizeof (c_EC_Packet_Downlink_Ack_Nack)); ED_CHECK_OUT_OF_MEMORY_DISCARD(sp->Data.fld_c_EC_Packet_Downlink_Ack_Nack == NULL)
			INIT_c_EC_Packet_Downlink_Ack_Nack (sp->Data.fld_c_EC_Packet_Downlink_Ack_Nack);
			break;
		}
		
		default:;
	}
return ED_NO_ERRORS;
}

void FREE_TUplink_RLC_MAC_EC_PACCH_Data (TUplink_RLC_MAC_EC_PACCH_Data* sp)
{
	switch (sp->Type) {
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Control_Acknowledgement: {
			FREE_c_EC_Packet_Control_Acknowledgement (sp->Data.fld_c_EC_Packet_Control_Acknowledgement);
	EDFree (sp->Data.fld_c_EC_Packet_Control_Acknowledgement );
			break;
		}
		
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Ack_Nack: {
			FREE_c_EC_Packet_Downlink_Ack_Nack (sp->Data.fld_c_EC_Packet_Downlink_Ack_Nack);
	EDFree (sp->Data.fld_c_EC_Packet_Downlink_Ack_Nack );
			break;
		}
		
		default:;
	}

	sp->Type = ID_Uplink_RLC_MAC_EC_PACCH_Unrecognized;
}

#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_Downlink_RLC_MAC_EC_PACCH (const char* buffer, TDownlink_RLC_MAC_EC_PACCH_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*/ = ((unsigned char)buffer [0])>> 3/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0]);
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF1F) {
			/* Detect signal EC_Packet_Access_Reject */
		case 0x0011: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Access_Reject), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Access_Reject (data->Data.fld_c_EC_Packet_Access_Reject);
			retLen = DECODE_c_EC_Packet_Access_Reject (buffer, 0, data->Data.fld_c_EC_Packet_Access_Reject, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Downlink_Assignment */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Assignment), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Downlink_Assignment (data->Data.fld_c_EC_Packet_Downlink_Assignment);
			retLen = DECODE_c_EC_Packet_Downlink_Assignment (buffer, 0, data->Data.fld_c_EC_Packet_Downlink_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Polling_Request */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Polling_Request), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Polling_Request (data->Data.fld_c_EC_Packet_Polling_Request);
			retLen = DECODE_c_EC_Packet_Polling_Request (buffer, 0, data->Data.fld_c_EC_Packet_Polling_Request, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Power_Control_Timing_Advance */
		case 0x0003: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Power_Control_Timing_Advance), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Power_Control_Timing_Advance (data->Data.fld_c_EC_Packet_Power_Control_Timing_Advance);
			retLen = DECODE_c_EC_Packet_Power_Control_Timing_Advance (buffer, 0, data->Data.fld_c_EC_Packet_Power_Control_Timing_Advance, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_TBF_Release */
		case 0x0004: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_TBF_Release), != ED_NO_ERRORS)
			INIT_c_EC_Packet_TBF_Release (data->Data.fld_c_EC_Packet_TBF_Release);
			retLen = DECODE_c_EC_Packet_TBF_Release (buffer, 0, data->Data.fld_c_EC_Packet_TBF_Release, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Uplink_Ack_Nack */
		case 0x0005: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Uplink_Ack_Nack (data->Data.fld_c_EC_Packet_Uplink_Ack_Nack);
			retLen = DECODE_c_EC_Packet_Uplink_Ack_Nack (buffer, 0, data->Data.fld_c_EC_Packet_Uplink_Ack_Nack, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Uplink_Assignment */
		case 0x0006: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Assignment), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Uplink_Assignment (data->Data.fld_c_EC_Packet_Uplink_Assignment);
			retLen = DECODE_c_EC_Packet_Uplink_Assignment (buffer, 0, data->Data.fld_c_EC_Packet_Uplink_Assignment, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution */
		case 0x0007: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (data->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution);
			retLen = DECODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (buffer, 0, data->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Downlink_Dummy_Control_Block */
		case 0x0012: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TDownlink_RLC_MAC_EC_PACCH_Data (data, ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Dummy_Control_Block), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Downlink_Dummy_Control_Block (data->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block);
			retLen = DECODE_c_EC_Packet_Downlink_Dummy_Control_Block (buffer, 0, data->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_Downlink_RLC_MAC_EC_PACCH_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Downlink_RLC_MAC_EC_PACCH (const char* buffer, int len, TDownlink_RLC_MAC_EC_PACCH_Data* data)
	{
		if (SetDecode_Downlink_RLC_MAC_EC_PACCH (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_Downlink_RLC_MAC_EC_PACCH (char* buffer, ED_EXLONG bitOffset, TDownlink_RLC_MAC_EC_PACCH_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Access_Reject: {
			retLen = ENCODE_c_EC_Packet_Access_Reject (buffer, 0, data->Data.fld_c_EC_Packet_Access_Reject);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Assignment: {
			retLen = ENCODE_c_EC_Packet_Downlink_Assignment (buffer, 0, data->Data.fld_c_EC_Packet_Downlink_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Polling_Request: {
			retLen = ENCODE_c_EC_Packet_Polling_Request (buffer, 0, data->Data.fld_c_EC_Packet_Polling_Request);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Power_Control_Timing_Advance: {
			retLen = ENCODE_c_EC_Packet_Power_Control_Timing_Advance (buffer, 0, data->Data.fld_c_EC_Packet_Power_Control_Timing_Advance);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_TBF_Release: {
			retLen = ENCODE_c_EC_Packet_TBF_Release (buffer, 0, data->Data.fld_c_EC_Packet_TBF_Release);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack: {
			retLen = ENCODE_c_EC_Packet_Uplink_Ack_Nack (buffer, 0, data->Data.fld_c_EC_Packet_Uplink_Ack_Nack);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Assignment: {
			retLen = ENCODE_c_EC_Packet_Uplink_Assignment (buffer, 0, data->Data.fld_c_EC_Packet_Uplink_Assignment);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution: {
			retLen = ENCODE_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (buffer, 0, data->Data.fld_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution);
			break;
		}
		case ID_Downlink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Dummy_Control_Block: {
			retLen = ENCODE_c_EC_Packet_Downlink_Dummy_Control_Block (buffer, 0, data->Data.fld_c_EC_Packet_Downlink_Dummy_Control_Block);
			break;
		}

		default:;
	}
	return retLen;
}
#ifdef ED_REVERSED_INTEGER
#error ED_REVERSED_INTEGER is defined!
#endif


int SetDecode_Uplink_RLC_MAC_EC_PACCH (const char* buffer, TUplink_RLC_MAC_EC_PACCH_Data* data, int bitLen)
{
	int retLen = 0;
	
	/*-----------------------------------------------------------------
		Key is set to a single value containing protocol discriminator,
		skip indicator and message type.
		For example, message ASSIGNMENT_COMMAND has:
			skip indicator         = 0000 (0x0)
			protocol discriminator = 0110 (0x6)
			message type           = 00101110 (0x2E)
		In this case, key will be set to 0x602E.
		Skip indicator could be in some cases a transaction identifier.
		In such cases, it will be set to 0 for matching purposes.
	------------------------------------------------------------------*/
	unsigned /****/ int key /*1*/ = ((unsigned char)buffer [0])>> 3/*2*/;/*3*/
	data->MessageType = (int)((unsigned char)buffer [0]);
	
	ED_WARNING_REMOVER(key);
	switch (key & 0xFF1F) {
			/* Detect signal EC_Packet_Control_Acknowledgement */
		case 0x0001: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_EC_PACCH_Data (data, ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Control_Acknowledgement), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Control_Acknowledgement (data->Data.fld_c_EC_Packet_Control_Acknowledgement);
			retLen = DECODE_c_EC_Packet_Control_Acknowledgement (buffer, 0, data->Data.fld_c_EC_Packet_Control_Acknowledgement, bitLen);
		
			return retLen;
		}
		/* Detect signal EC_Packet_Downlink_Ack_Nack */
		case 0x0002: {
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK08*/(/*SETP5*/SETPRESENT_TUplink_RLC_MAC_EC_PACCH_Data (data, ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Ack_Nack), != ED_NO_ERRORS)
			INIT_c_EC_Packet_Downlink_Ack_Nack (data->Data.fld_c_EC_Packet_Downlink_Ack_Nack);
			retLen = DECODE_c_EC_Packet_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_EC_Packet_Downlink_Ack_Nack, bitLen);
		
			return retLen;
		}

		default:;
	}
	data->Type = ID_Uplink_RLC_MAC_EC_PACCH_Unrecognized;

	return ED_UNKNOWN_MESSAGE;
}
			
#ifndef ED_EXCLUDE_1_0_33_COMPATIBILITY
	int Decode_Uplink_RLC_MAC_EC_PACCH (const char* buffer, int len, TUplink_RLC_MAC_EC_PACCH_Data* data)
	{
		if (SetDecode_Uplink_RLC_MAC_EC_PACCH (buffer, data, len*8) < 0) {
			return ED_FALSE;
		}
		else {
			return ED_TRUE;
		}
	}
#endif

/* Set encoder */
int SetEncode_Uplink_RLC_MAC_EC_PACCH (char* buffer, ED_EXLONG bitOffset, TUplink_RLC_MAC_EC_PACCH_Data* data)
{
	int retLen = ED_UNKNOWN_MESSAGE;
	ED_WARNING_REMOVER(bitOffset);
	
	switch (data->Type) {
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Control_Acknowledgement: {
			retLen = ENCODE_c_EC_Packet_Control_Acknowledgement (buffer, 0, data->Data.fld_c_EC_Packet_Control_Acknowledgement);
			break;
		}
		case ID_Uplink_RLC_MAC_EC_PACCH_EC_Packet_Downlink_Ack_Nack: {
			retLen = ENCODE_c_EC_Packet_Downlink_Ack_Nack (buffer, 0, data->Data.fld_c_EC_Packet_Downlink_Ack_Nack);
			break;
		}

		default:;
	}
	return retLen;
}

