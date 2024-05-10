/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "SC2MS_SMS.h"
#include "ed_c_known_ie_SMS.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* 3GPP 23.040 ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_DELIVER (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_DELIVER* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG Len = 0;
	/* Encode TP-MTI=0 */
	EDIntToBits (Buffer, CurrOfs+6, 0, 2);
	CurrOfs += 8;
	

	Len = ENCODE_c_TP_MTI (Buffer, CurrOfs, (&(Source->header)));
	CurrOfs += Len;
	/* Implementation of TP_MMS - 1 bit(s) at bit n. 2 */
	EDIntToBits (Buffer, (BitOffset+5), (int)(Source->TP_MMS != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_LO - 1 bit(s) at bit n. 3 */
	EDIntToBits (Buffer, (BitOffset+4), (int)(Source->TP_LO != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_RP - 1 bit(s) at bit n. 7 */
	EDIntToBits (Buffer, (BitOffset+0), (int)(Source->TP_RP != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	EDIntToBits (Buffer, (BitOffset+1), (int)(Source->TP_UDHI != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_SRI - 1 bit(s) at bit n. 5 */
	EDIntToBits (Buffer, (BitOffset+2), (int)(Source->TP_SRI != 0 ? 1 : 0), 1);Len = 1;
	Len = ENCODE_c_TAddress (Buffer, CurrOfs, (&(Source->TP_OA)));
	CurrOfs += Len;
	Len = ENCODE_c_TP_PID (Buffer, CurrOfs, (&(Source->TP_PID)));
	CurrOfs += Len;
	Len = ENCODE_c_TP_DCS (Buffer, CurrOfs, (&(Source->TP_DCS)));
	CurrOfs += Len;
	Len = ENCODE_c_TTimeStamp (Buffer, CurrOfs, (&(Source->TP_SCTS)));
	CurrOfs += Len;
	Len = ENCODE_c_TP_UD (Buffer, CurrOfs, (&(Source->TP_UD)), THIS->TP_UDHI, &(THIS->TP_DCS));
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_DELIVER (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_DELIVER* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset+8; /* Skip TP-MTI together with the first octet */
	ED_EXLONG Len = 0;

	Len = DECODE_c_TP_MTI (Buffer, CurrOfs, (&(Destin->header)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:82> Message too short decoding subfield header\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 81, (Destin->header))
	} 
#endif
	/* Implementation of TP_MMS - 1 bit(s) at bit n. 2 */
	Destin->TP_MMS = (EDBitsToInt (Buffer, BitOffset+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_MMS___LOCATOR), BitOffset+5, 1);
	Len = 1;
	/* Implementation of TP_LO - 1 bit(s) at bit n. 3 */
	Destin->TP_LO = (EDBitsToInt (Buffer, BitOffset+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_LO___LOCATOR), BitOffset+4, 1);
	Len = 1;
	/* Implementation of TP_RP - 1 bit(s) at bit n. 7 */
	Destin->TP_RP = (EDBitsToInt (Buffer, BitOffset+0, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_RP___LOCATOR), BitOffset+0, 1);
	Len = 1;
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	Destin->TP_UDHI = (EDBitsToInt (Buffer, BitOffset+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_UDHI___LOCATOR), BitOffset+1, 1);
	Len = 1;
	/* Implementation of TP_SRI - 1 bit(s) at bit n. 5 */
	Destin->TP_SRI = (EDBitsToInt (Buffer, BitOffset+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_SRI___LOCATOR), BitOffset+2, 1);
	Len = 1;
	Len = DECODE_c_TAddress (Buffer, CurrOfs, (&(Destin->TP_OA)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:84> Message too short decoding subfield TP_OA\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 83, (Destin->TP_OA))
	} 
#endif
	Len = DECODE_c_TP_PID (Buffer, CurrOfs, (&(Destin->TP_PID)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:86> Message too short decoding subfield TP_PID\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 85, (Destin->TP_PID))
	} 
#endif
	Len = DECODE_c_TP_DCS (Buffer, CurrOfs, (&(Destin->TP_DCS)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:88> Message too short decoding subfield TP_DCS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 87, (Destin->TP_DCS))
	} 
#endif
	Len = DECODE_c_TTimeStamp (Buffer, CurrOfs, (&(Destin->TP_SCTS)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:90> Message too short decoding subfield TP_SCTS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 89, (Destin->TP_SCTS))
	} 
#endif
	Len = DECODE_c_TP_UD (Buffer, CurrOfs, (&(Destin->TP_UD)), (Length-(CurrOfs-BitOffset)), THIS->TP_UDHI, &(THIS->TP_DCS));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:92> Message too short decoding subfield TP_UD\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 91, (Destin->TP_UD))
	} 
#endif
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(Destin->spare___LOCATOR), CurrOfs, (Length-(CurrOfs-BitOffset)));
	if ((Length-(CurrOfs-BitOffset)) > 0) {
		/* BINDEC02 */
		ALLOC_c_SMS_DELIVER_spare (&(Destin->spare), (Length-(CurrOfs-BitOffset)));
	
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
		ED_SIGNAL_ERROR ("<ERRID:94> Message too short decoding subfield spare\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 93, (Destin->spare))
	} 
#endif

	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* 3GPP 23.040 ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_STATUS_REPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_STATUS_REPORT* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG Len = 0;
	/* Encode TP-MTI=2 */
	EDIntToBits (Buffer, CurrOfs+6, 2, 2);
	CurrOfs += 8;
	

	Len = ENCODE_c_TP_MTI (Buffer, CurrOfs, (&(Source->header)));
	CurrOfs += Len;
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	EDIntToBits (Buffer, (BitOffset+1), (int)(Source->TP_UDHI != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_LO - 1 bit(s) at bit n. 3 */
	EDIntToBits (Buffer, (BitOffset+4), (int)(Source->TP_LO != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_MMS - 1 bit(s) at bit n. 2 */
	EDIntToBits (Buffer, (BitOffset+5), (int)(Source->TP_MMS != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_SRQ - 1 bit(s) at bit n. 5 */
	EDIntToBits (Buffer, (BitOffset+2), (int)(Source->TP_SRQ != 0 ? 1 : 0), 1);Len = 1;
	EDIntToBits (Buffer, (CurrOfs), (int)(Source->TP_MR), 8);
	Len = 8;
	
	CurrOfs += Len;
	Len = ENCODE_c_TAddress (Buffer, CurrOfs, (&(Source->TP_RA)));
	CurrOfs += Len;
	Len = ENCODE_c_TTimeStamp (Buffer, CurrOfs, (&(Source->TP_SCTS)));
	CurrOfs += Len;
	Len = ENCODE_c_TTimeStamp (Buffer, CurrOfs, (&(Source->TP_DT)));
	CurrOfs += Len;
	EDIntToBits (Buffer, (CurrOfs), (int)(Source->TP_ST), 8);
	Len = 8;
	
	CurrOfs += Len;
	if (Source->TP_PI_Present) {
		Len = ENCODE_c_TP_PI (Buffer, CurrOfs, Source->TP_PI);
	} else {
		Len=0;
	}
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
		Len = ENCODE_c_TP_UD (Buffer, CurrOfs, Source->TP_UD, THIS->TP_UDHI, PTR_c_SMS_STATUS_REPORT_TP_DCS(THIS->TP_DCS));
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_STATUS_REPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_STATUS_REPORT* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset+8; /* Skip TP-MTI together with the first octet */
	ED_EXLONG Len = 0;

	Len = DECODE_c_TP_MTI (Buffer, CurrOfs, (&(Destin->header)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:96> Message too short decoding subfield header\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 95, (Destin->header))
	} 
#endif
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	Destin->TP_UDHI = (EDBitsToInt (Buffer, BitOffset+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_UDHI___LOCATOR), BitOffset+1, 1);
	Len = 1;
	/* Implementation of TP_LO - 1 bit(s) at bit n. 3 */
	Destin->TP_LO = (EDBitsToInt (Buffer, BitOffset+4, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_LO___LOCATOR), BitOffset+4, 1);
	Len = 1;
	/* Implementation of TP_MMS - 1 bit(s) at bit n. 2 */
	Destin->TP_MMS = (EDBitsToInt (Buffer, BitOffset+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_MMS___LOCATOR), BitOffset+5, 1);
	Len = 1;
	/* Implementation of TP_SRQ - 1 bit(s) at bit n. 5 */
	Destin->TP_SRQ = (EDBitsToInt (Buffer, BitOffset+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_SRQ___LOCATOR), BitOffset+2, 1);
	Len = 1;
	Destin->TP_MR = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(Destin->TP_MR___LOCATOR), CurrOfs, 8);
	Len = 8;
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:98> Message too short decoding subfield TP_MR\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 97, (Destin->TP_MR))
	} 
#endif
	Len = DECODE_c_TAddress (Buffer, CurrOfs, (&(Destin->TP_RA)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:100> Message too short decoding subfield TP_RA\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 99, (Destin->TP_RA))
	} 
#endif
	Len = DECODE_c_TTimeStamp (Buffer, CurrOfs, (&(Destin->TP_SCTS)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:102> Message too short decoding subfield TP_SCTS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 101, (Destin->TP_SCTS))
	} 
#endif
	Len = DECODE_c_TTimeStamp (Buffer, CurrOfs, (&(Destin->TP_DT)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:104> Message too short decoding subfield TP_DT\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 103, (Destin->TP_DT))
	} 
#endif
	Destin->TP_ST = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(Destin->TP_ST___LOCATOR), CurrOfs, 8);
	Len = 8;
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:106> Message too short decoding subfield TP_ST\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 105, (Destin->TP_ST))
	} 
#endif
	if (Length-(CurrOfs-BitOffset) >= 8) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_PI (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_PI (Buffer, CurrOfs, Destin->TP_PI, (Length-(CurrOfs-BitOffset)));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_PI (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:108> Message too short decoding subfield TP_PI\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 107, (Destin->TP_PI))
	} 
#endif
	if (THIS->TP_PI_Present && PTR_c_SMS_STATUS_REPORT_TP_PI (THIS->TP_PI)->TP_PID) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_PID (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_PID (Buffer, CurrOfs, Destin->TP_PID, (Length-(CurrOfs-BitOffset)));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_PID (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:110> Message too short decoding subfield TP_PID\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 109, (Destin->TP_PID))
	} 
#endif
	if (THIS->TP_PI_Present && PTR_c_SMS_STATUS_REPORT_TP_PI (THIS->TP_PI)->TP_DCS) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_DCS (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_DCS (Buffer, CurrOfs, Destin->TP_DCS, (Length-(CurrOfs-BitOffset)));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_DCS (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:112> Message too short decoding subfield TP_DCS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 111, (Destin->TP_DCS))
	} 
#endif
	if (THIS->TP_PI_Present && PTR_c_SMS_STATUS_REPORT_TP_PI (THIS->TP_PI)->TP_UDL) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_UD (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_UD (Buffer, CurrOfs, Destin->TP_UD, (Length-(CurrOfs-BitOffset)), THIS->TP_UDHI, PTR_c_SMS_STATUS_REPORT_TP_DCS(THIS->TP_DCS));
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_STATUS_REPORT_TP_UD (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:114> Message too short decoding subfield TP_UD\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 113, (Destin->TP_UD))
	} 
#endif
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(Destin->spare___LOCATOR), CurrOfs, (Length-(CurrOfs-BitOffset)));
	if ((Length-(CurrOfs-BitOffset)) > 0) {
		/* BINDEC02 */
		ALLOC_c_SMS_STATUS_REPORT_spare (&(Destin->spare), (Length-(CurrOfs-BitOffset)));
	
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
		ED_SIGNAL_ERROR ("<ERRID:116> Message too short decoding subfield spare\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 115, (Destin->spare))
	} 
#endif

	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
