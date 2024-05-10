/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "MS2SC_ACK_SMS.h"
#include "ed_c_known_ie_SMS.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* 3GPP 23.040 ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_DELIVERY_REPORT_RP_ACK (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_DELIVERY_REPORT_RP_ACK* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG Len = 0;
	/* Encode TP-MTI=0 */
	EDIntToBits (Buffer, CurrOfs+6, 0, 2);
	CurrOfs += 8;
	

	Len = ENCODE_c_TP_MTI (Buffer, CurrOfs, (&(Source->header)));
	CurrOfs += Len;
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	EDIntToBits (Buffer, (BitOffset+1), (int)(Source->TP_UDHI != 0 ? 1 : 0), 1);Len = 1;
	Len = ENCODE_c_TP_PI (Buffer, CurrOfs, (&(Source->TP_PI)));
	CurrOfs += Len;
	if (Source->TP_PID_Present) {
		Len = ENCODE_c_TP_PID (Buffer, CurrOfs, Source->TP_PID);
	} else {
		Len=0;
	}
	CurrOfs += Len;
	if (Source->TP_DCS_Present) {
		Len = ENCODE_c_TP_DCS (Buffer, CurrOfs, Source->TP_DCS);
	} else {
		Len=0;
	}
	CurrOfs += Len;
	if (Source->TP_UD_Present) {
		Len = ENCODE_c_TP_UD (Buffer, CurrOfs, Source->TP_UD, THIS->TP_UDHI, PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS(THIS->TP_DCS));
	} else {
		Len=0;
	}
	CurrOfs += Len;
	EDCopyBits (Buffer, CurrOfs, Source->spare.value, 0, Source->spare.usedBits);
	Len = Source->spare.usedBits;
	
	CurrOfs += Len;

	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* 3GPP 23.040 DECODER */
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_DELIVERY_REPORT_RP_ACK (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_DELIVERY_REPORT_RP_ACK* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset+8; /* Skip TP-MTI together with the first octet */
	ED_EXLONG Len = 0;

	Len = DECODE_c_TP_MTI (Buffer, CurrOfs, (&(Destin->header)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:194> Message too short decoding subfield header\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 193, (Destin->header))
	} 
#endif
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	Destin->TP_UDHI = (EDBitsToInt (Buffer, BitOffset+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_UDHI___LOCATOR), BitOffset+1, 1);
	Len = 1;
	Len = DECODE_c_TP_PI (Buffer, CurrOfs, (&(Destin->TP_PI)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:196> Message too short decoding subfield TP_PI\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 195, (Destin->TP_PI))
	} 
#endif
	if (THIS->TP_PI.TP_PID) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_PID (Buffer, CurrOfs, Destin->TP_PID, (Length-(CurrOfs-BitOffset)));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_PID (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:198> Message too short decoding subfield TP_PID\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 197, (Destin->TP_PID))
	} 
#endif
	if (THIS->TP_PI.TP_DCS) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_DCS (Buffer, CurrOfs, Destin->TP_DCS, (Length-(CurrOfs-BitOffset)));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:200> Message too short decoding subfield TP_DCS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 199, (Destin->TP_DCS))
	} 
#endif
	if (THIS->TP_PI.TP_UDL) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_UD (Buffer, CurrOfs, Destin->TP_UD, (Length-(CurrOfs-BitOffset)), THIS->TP_UDHI, PTR_c_SMS_DELIVERY_REPORT_RP_ACK_TP_DCS(THIS->TP_DCS));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_DELIVERY_REPORT_RP_ACK_TP_UD (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:202> Message too short decoding subfield TP_UD\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 201, (Destin->TP_UD))
	} 
#endif
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(Destin->spare___LOCATOR), CurrOfs, (Length-(CurrOfs-BitOffset)));
	if ((Length-(CurrOfs-BitOffset)) > 0) {
		/* BINDEC02 */
		ALLOC_c_SMS_DELIVERY_REPORT_RP_ACK_spare (&(Destin->spare), (Length-(CurrOfs-BitOffset)));
	
		if (Destin->spare.value) {
			EDCopyBits (Destin->spare.value, 0, Buffer, CurrOfs, (Length-(CurrOfs-BitOffset)));
			Destin->spare.usedBits = (Length-(CurrOfs-BitOffset));
			Len = (Length-(CurrOfs-BitOffset));
	
		}
		else {
			Destin->spare.usedBits = 0;
			Len = ED_OUT_OF_MEMORY;
		}
	}
	else {
		Len = (Length-(CurrOfs-BitOffset));
	
	}
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:204> Message too short decoding subfield spare\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 203, (Destin->spare))
	} 
#endif

	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
