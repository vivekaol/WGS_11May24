/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __Uplink_RLC_MAC_RLCMAC_h
#define __Uplink_RLC_MAC_RLCMAC_h
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
	Encoding/decoding functions for "Packet_Cell_Change_Failure".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Failure (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Failure* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Failure (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Failure* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Cell_Change_Failure".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Cell_Change_Failure (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Failure* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Cell_Change_Failure (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Failure* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Control_Acknowledgement".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Control_Acknowledgement (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Control_Acknowledgement (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_11bit_a".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_11bit_a (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_11bit_a* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_11bit_a (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_11bit_a* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Control_Acknowledgement_11bit_a".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Control_Acknowledgement_11bit_a (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_11bit_a* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Control_Acknowledgement_11bit_a (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_11bit_a* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_11bit_b".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_11bit_b (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_11bit_b* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_11bit_b (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_11bit_b* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Control_Acknowledgement_11bit_b".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Control_Acknowledgement_11bit_b (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_11bit_b* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Control_Acknowledgement_11bit_b (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_11bit_b* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Control_Acknowledgement_8bit".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Control_Acknowledgement_8bit (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_8bit* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Control_Acknowledgement_8bit (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_8bit* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Control_Acknowledgement_8bit".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Control_Acknowledgement_8bit (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Control_Acknowledgement_8bit* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Control_Acknowledgement_8bit (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Control_Acknowledgement_8bit* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Downlink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Downlink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Downlink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Downlink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Downlink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Downlink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Downlink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Downlink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Uplink_Dummy_Control_Block".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Uplink_Dummy_Control_Block (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Dummy_Control_Block* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Uplink_Dummy_Control_Block (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Dummy_Control_Block* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Uplink_Dummy_Control_Block".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Uplink_Dummy_Control_Block (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Uplink_Dummy_Control_Block* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Uplink_Dummy_Control_Block (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Uplink_Dummy_Control_Block* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Measurement_Report".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Measurement_Report (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Measurement_Report* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Measurement_Report (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Measurement_Report* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Measurement_Report".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Measurement_Report (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Measurement_Report* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Measurement_Report (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Measurement_Report* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Resource_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Resource_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Resource_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Resource_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Resource_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Resource_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Resource_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Resource_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Resource_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Resource_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Mobile_TBF_Status".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Mobile_TBF_Status (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Mobile_TBF_Status* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Mobile_TBF_Status (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Mobile_TBF_Status* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Mobile_TBF_Status".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Mobile_TBF_Status (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Mobile_TBF_Status* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Mobile_TBF_Status (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Mobile_TBF_Status* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_PSI_Status".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_PSI_Status (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PSI_Status* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_PSI_Status (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PSI_Status* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_PSI_Status".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_PSI_Status (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_PSI_Status* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_PSI_Status (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_PSI_Status* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EGPRS_Packet_Downlink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EGPRS_Packet_Downlink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EGPRS_Packet_Downlink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Pause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Pause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Pause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Pause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Pause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Pause".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Pause (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Pause* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Pause (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Pause* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Enhanced_Measurement_Report".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Enhanced_Measurement_Report (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Enhanced_Measurement_Report* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Enhanced_Measurement_Report (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Enhanced_Measurement_Report* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Enhanced_Measurement_Report".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Enhanced_Measurement_Report (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Enhanced_Measurement_Report* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Enhanced_Measurement_Report (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Enhanced_Measurement_Report* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Additional_MS_Radio_Access_Capabilities".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Additional_MS_Radio_Access_Capabilities (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Additional_MS_Radio_Access_Capabilities* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Additional_MS_Radio_Access_Capabilities (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Additional_MS_Radio_Access_Capabilities* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Additional_MS_Radio_Access_Capabilities".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Additional_MS_Radio_Access_Capabilities (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Additional_MS_Radio_Access_Capabilities* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Additional_MS_Radio_Access_Capabilities (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Additional_MS_Radio_Access_Capabilities* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_Cell_Change_Notification".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_Cell_Change_Notification (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Notification* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_Cell_Change_Notification (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Notification* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_Cell_Change_Notification".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_Cell_Change_Notification (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_Cell_Change_Notification* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_Cell_Change_Notification (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_Cell_Change_Notification* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_SI_Status".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_SI_Status (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_SI_Status* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_SI_Status (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_SI_Status* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_SI_Status".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_SI_Status (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_SI_Status* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_SI_Status (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_SI_Status* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "Packet_CS_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_Packet_CS_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_Packet_CS_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "Packet_CS_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_Packet_CS_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_Packet_CS_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_Packet_CS_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_Packet_CS_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Service_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Service_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Service_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Service_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Service_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MBMS_Service_Request".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MBMS_Service_Request (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Service_Request* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MBMS_Service_Request (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Service_Request* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "MBMS_Downlink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MBMS_Downlink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Downlink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MBMS_Downlink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Downlink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "MBMS_Downlink_Ack_Nack".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MBMS_Downlink_Ack_Nack (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MBMS_Downlink_Ack_Nack* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MBMS_Downlink_Ack_Nack (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MBMS_Downlink_Ack_Nack* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack_Type_3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_Type_3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_Type_3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EGPRS_Packet_Downlink_Ack_Nack_Type_3".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_Type_3* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_Type_3* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for "EGPRS_Packet_Downlink_Ack_Nack_DLMC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_DLMC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_DLMC* ED_CONST Destin, ED_EXLONG Length));

/*----------------------------------------------------------------------------
	Encoding/decoding functions for body of "EGPRS_Packet_Downlink_Ack_Nack_DLMC".
	It returns number of bits used or <0 in case of error.
----------------------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EGPRS_Packet_Downlink_Ack_Nack_DLMC* ED_CONST Source));

ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EGPRS_Packet_Downlink_Ack_Nack_DLMC* ED_CONST Destin, ED_EXLONG Length));

int Match_c_Packet_Cell_Change_Failure (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Control_Acknowledgement (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Control_Acknowledgement_11bit_a (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Control_Acknowledgement_11bit_b (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Control_Acknowledgement_8bit (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Downlink_Ack_Nack (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Uplink_Dummy_Control_Block (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Measurement_Report (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Resource_Request (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Mobile_TBF_Status (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_PSI_Status (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EGPRS_Packet_Downlink_Ack_Nack (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Pause (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Enhanced_Measurement_Report (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Additional_MS_Radio_Access_Capabilities (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_Cell_Change_Notification (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_SI_Status (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_Packet_CS_Request (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MBMS_Service_Request (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_MBMS_Downlink_Ack_Nack (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EGPRS_Packet_Downlink_Ack_Nack_Type_3 (const char* Buffer, ED_CONST ED_EXLONG BitOffset);
int Match_c_EGPRS_Packet_Downlink_Ack_Nack_DLMC (const char* Buffer, ED_CONST ED_EXLONG BitOffset);

#ifdef __cplusplus
	}
#endif
#endif

