/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-dump
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_dump_EC_PACCH_h_H
#define __ed_c_dump_EC_PACCH_h_H

#include "ed_c_EC_PACCH.h"
#include "ed_c_recog_EC_PACCH.h"
#include "ed_dump.h"
#ifdef __cplusplus
	extern "C" {
#endif

void Dump_c_EC_Packet_Access_Reject_message_content (TEDOStream* OStream, const c_EC_Packet_Access_Reject_message_content* Data);

void Dump_c_EC_Packet_Control_Acknowledgement_message_content (TEDOStream* OStream, const c_EC_Packet_Control_Acknowledgement_message_content* Data);

void Dump_c_EC_Packet_Downlink_Ack_Nack_message_content (TEDOStream* OStream, const c_EC_Packet_Downlink_Ack_Nack_message_content* Data);

void Dump_c_EC_Packet_Downlink_Assignment_message_content (TEDOStream* OStream, const c_EC_Packet_Downlink_Assignment_message_content* Data);

void Dump_c_EC_Packet_Downlink_Dummy_Control_Block_message_content (TEDOStream* OStream, const c_EC_Packet_Downlink_Dummy_Control_Block_message_content* Data);

void Dump_c_EC_Packet_Polling_Request_message_content (TEDOStream* OStream, const c_EC_Packet_Polling_Request_message_content* Data);

void Dump_c_EC_Packet_Power_Control_Timing_Advance_message_content (TEDOStream* OStream, const c_EC_Packet_Power_Control_Timing_Advance_message_content* Data);

void Dump_c_EC_Packet_TBF_Release_message_content (TEDOStream* OStream, const c_EC_Packet_TBF_Release_message_content* Data);

void Dump_c_EC_Packet_Uplink_Ack_Nack_message_content (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack_message_content* Data);

void Dump_c_EC_Packet_Uplink_Assignment_message_content (TEDOStream* OStream, const c_EC_Packet_Uplink_Assignment_message_content* Data);

void Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution_message_content* Data);

void Dump_c_EC_Packet_Access_Reject (TEDOStream* OStream, const c_EC_Packet_Access_Reject* Data);

void Dump_c_EC_Packet_Downlink_Assignment (TEDOStream* OStream, const c_EC_Packet_Downlink_Assignment* Data);

void Dump_c_EC_Packet_Polling_Request (TEDOStream* OStream, const c_EC_Packet_Polling_Request* Data);

void Dump_c_EC_Packet_Power_Control_Timing_Advance (TEDOStream* OStream, const c_EC_Packet_Power_Control_Timing_Advance* Data);

void Dump_c_EC_Packet_TBF_Release (TEDOStream* OStream, const c_EC_Packet_TBF_Release* Data);

void Dump_c_EC_Packet_Uplink_Ack_Nack (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack* Data);

void Dump_c_EC_Packet_Uplink_Assignment (TEDOStream* OStream, const c_EC_Packet_Uplink_Assignment* Data);

void Dump_c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution (TEDOStream* OStream, const c_EC_Packet_Uplink_Ack_Nack_and_Contention_Resolution* Data);

void Dump_c_EC_Packet_Downlink_Dummy_Control_Block (TEDOStream* OStream, const c_EC_Packet_Downlink_Dummy_Control_Block* Data);

void Dump_c_EC_Packet_Control_Acknowledgement (TEDOStream* OStream, const c_EC_Packet_Control_Acknowledgement* Data);

void Dump_c_EC_Packet_Downlink_Ack_Nack (TEDOStream* OStream, const c_EC_Packet_Downlink_Ack_Nack* Data);

void Dump_c_EC_Packet_Control_Acknowledgement_11_bit_message (TEDOStream* OStream, const c_EC_Packet_Control_Acknowledgement_11_bit_message* Data);

void Dump_c_GenericTLV_EC_PACCH (TEDOStream* OStream, const c_GenericTLV_EC_PACCH* Data);

void Dump_Downlink_RLC_MAC_EC_PACCH (TEDOStream* OStream, const TDownlink_RLC_MAC_EC_PACCH_Data* Data);
void Dump_Uplink_RLC_MAC_EC_PACCH (TEDOStream* OStream, const TUplink_RLC_MAC_EC_PACCH_Data* Data);

#ifdef __cplusplus
	}
#endif

#endif

