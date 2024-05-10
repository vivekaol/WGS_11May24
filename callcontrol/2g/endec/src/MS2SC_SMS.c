/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "MS2SC_SMS.h"
#include "ed_c_known_ie_SMS.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* 3GPP 23.040 ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_SUBMIT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_SUBMIT* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG Len = 0;
	/* Encode TP-MTI=1 */
	EDIntToBits (Buffer, CurrOfs+6, 1, 2);
	CurrOfs += 8;
	

	Len = ENCODE_c_TP_MTI (Buffer, CurrOfs, (&(Source->header)));
	CurrOfs += Len;
	/* Implementation of TP_RD - 1 bit(s) at bit n. 2 */
	EDIntToBits (Buffer, (BitOffset+5), (int)(Source->TP_RD != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_VPF - 2 bit(s) at bit n. 3 */
	EDIntToBits (Buffer, (BitOffset+3), (int)(Source->TP_VPF), 2);
	Len = 2;
	/* Implementation of TP_RP - 1 bit(s) at bit n. 7 */
	EDIntToBits (Buffer, (BitOffset+0), (int)(Source->TP_RP != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	EDIntToBits (Buffer, (BitOffset+1), (int)(Source->TP_UDHI != 0 ? 1 : 0), 1);Len = 1;
	/* Implementation of TP_SRR - 1 bit(s) at bit n. 5 */
	EDIntToBits (Buffer, (BitOffset+2), (int)(Source->TP_SRR != 0 ? 1 : 0), 1);Len = 1;
	EDIntToBits (Buffer, (CurrOfs), (int)(Source->TP_MR), 8);
	Len = 8;
	
	CurrOfs += Len;
	Len = ENCODE_c_TAddress (Buffer, CurrOfs, (&(Source->TP_DA)));
	CurrOfs += Len;
	Len = ENCODE_c_TP_PID (Buffer, CurrOfs, (&(Source->TP_PID)));
	CurrOfs += Len;
	Len = ENCODE_c_TP_DCS (Buffer, CurrOfs, (&(Source->TP_DCS)));
	CurrOfs += Len;
	if (Source->TP_VP_Present) {
		Len = ENCODE_c_TP_VP (Buffer, CurrOfs, Source->TP_VP);
	} else {
		Len=0;
	}
	CurrOfs += Len;
	Len = ENCODE_c_TP_UD (Buffer, CurrOfs, (&(Source->TP_UD)), THIS->TP_UDHI, PTR_c_SMS_SUBMIT_TP_DCS(THIS->TP_DCS));
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_SUBMIT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_SUBMIT* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset+8; /* Skip TP-MTI together with the first octet */
	ED_EXLONG Len = 0;

	Len = DECODE_c_TP_MTI (Buffer, CurrOfs, (&(Destin->header)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:148> Message too short decoding subfield header\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 147, (Destin->header))
	} 
#endif
	/* Implementation of TP_RD - 1 bit(s) at bit n. 2 */
	Destin->TP_RD = (EDBitsToInt (Buffer, BitOffset+5, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_RD___LOCATOR), BitOffset+5, 1);
	Len = 1;
	/* Implementation of TP_VPF - 2 bit(s) at bit n. 3 */
	Destin->TP_VPF = (ED_OCTET)EDBitsToInt (Buffer, (BitOffset+3), 2);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(Destin->TP_VPF___LOCATOR), BitOffset+3, 2);
	Len = 2;
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
	/* Implementation of TP_SRR - 1 bit(s) at bit n. 5 */
	Destin->TP_SRR = (EDBitsToInt (Buffer, BitOffset+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_SRR___LOCATOR), BitOffset+2, 1);
	Len = 1;
	Destin->TP_MR = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(Destin->TP_MR___LOCATOR), CurrOfs, 8);
	Len = 8;
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:150> Message too short decoding subfield TP_MR\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 149, (Destin->TP_MR))
	} 
#endif
	Len = DECODE_c_TAddress (Buffer, CurrOfs, (&(Destin->TP_DA)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:152> Message too short decoding subfield TP_DA\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 151, (Destin->TP_DA))
	} 
#endif
	Len = DECODE_c_TP_PID (Buffer, CurrOfs, (&(Destin->TP_PID)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:154> Message too short decoding subfield TP_PID\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 153, (Destin->TP_PID))
	} 
#endif
	Len = DECODE_c_TP_DCS (Buffer, CurrOfs, (&(Destin->TP_DCS)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:156> Message too short decoding subfield TP_DCS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 155, (Destin->TP_DCS))
	} 
#endif
	if (THIS->TP_VPF) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_SUBMIT_TP_VP (Destin, ED_TRUE), != ED_NO_ERRORS)
		Len = DECODE_c_TP_VP (Buffer, CurrOfs, Destin->TP_VP, (Length-(CurrOfs-BitOffset)), THIS->TP_VPF);
	} else {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK16*/(/*SETP2*/SETPRESENT_c_SMS_SUBMIT_TP_VP (Destin, ED_FALSE), != ED_NO_ERRORS)
		Len=0;
	}CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:158> Message too short decoding subfield TP_VP\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 157, (Destin->TP_VP))
	} 
#endif
	Len = DECODE_c_TP_UD (Buffer, CurrOfs, (&(Destin->TP_UD)), (Length-(CurrOfs-BitOffset)), THIS->TP_UDHI, PTR_c_SMS_SUBMIT_TP_DCS(THIS->TP_DCS));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:160> Message too short decoding subfield TP_UD\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 159, (Destin->TP_UD))
	} 
#endif
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(Destin->spare___LOCATOR), CurrOfs, (Length-(CurrOfs-BitOffset)));
	if ((Length-(CurrOfs-BitOffset)) > 0) {
		/* BINDEC02 */
		ALLOC_c_SMS_SUBMIT_spare (&(Destin->spare), (Length-(CurrOfs-BitOffset)));
	
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
		ED_SIGNAL_ERROR ("<ERRID:162> Message too short decoding subfield spare\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 161, (Destin->spare))
	} 
#endif

	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* 3GPP 23.040 ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SMS_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SMS_COMMAND* ED_CONST Source))
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
	/* Implementation of TP_SRR - 1 bit(s) at bit n. 5 */
	EDIntToBits (Buffer, (BitOffset+2), (int)(Source->TP_SRR != 0 ? 1 : 0), 1);Len = 1;
	EDIntToBits (Buffer, (CurrOfs), (int)(Source->TP_MR), 8);
	Len = 8;
	
	CurrOfs += Len;
	Len = ENCODE_c_TP_PID (Buffer, CurrOfs, (&(Source->TP_PID)));
	CurrOfs += Len;
	EDIntToBits (Buffer, (CurrOfs), (int)(Source->TP_CT), 8);
	Len = 8;
	
	CurrOfs += Len;
	EDIntToBits (Buffer, (CurrOfs), (int)(Source->TP_MN), 8);
	Len = 8;
	
	CurrOfs += Len;
	Len = ENCODE_c_TAddress (Buffer, CurrOfs, (&(Source->TP_DA)));
	CurrOfs += Len;
	Len = ENCODE_c_TP_CD (Buffer, CurrOfs, (&(Source->TP_CD)));
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
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SMS_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SMS_COMMAND* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset+8; /* Skip TP-MTI together with the first octet */
	ED_EXLONG Len = 0;

	Len = DECODE_c_TP_MTI (Buffer, CurrOfs, (&(Destin->header)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:164> Message too short decoding subfield header\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 163, (Destin->header))
	} 
#endif
	/* Implementation of TP_UDHI - 1 bit(s) at bit n. 6 */
	Destin->TP_UDHI = (EDBitsToInt (Buffer, BitOffset+1, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_UDHI___LOCATOR), BitOffset+1, 1);
	Len = 1;
	/* Implementation of TP_SRR - 1 bit(s) at bit n. 5 */
	Destin->TP_SRR = (EDBitsToInt (Buffer, BitOffset+2, 1) != 0 ? ED_TRUE : ED_FALSE);
	/* LOCATOR SETTINGS LOCBOOL */;
	ED_LOCATOR_SET (&(Destin->TP_SRR___LOCATOR), BitOffset+2, 1);
	Len = 1;
	Destin->TP_MR = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(Destin->TP_MR___LOCATOR), CurrOfs, 8);
	Len = 8;
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:166> Message too short decoding subfield TP_MR\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 165, (Destin->TP_MR))
	} 
#endif
	Len = DECODE_c_TP_PID (Buffer, CurrOfs, (&(Destin->TP_PID)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:168> Message too short decoding subfield TP_PID\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 167, (Destin->TP_PID))
	} 
#endif
	Destin->TP_CT = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(Destin->TP_CT___LOCATOR), CurrOfs, 8);
	Len = 8;
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:170> Message too short decoding subfield TP_CT\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 169, (Destin->TP_CT))
	} 
#endif
	Destin->TP_MN = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(Destin->TP_MN___LOCATOR), CurrOfs, 8);
	Len = 8;
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:172> Message too short decoding subfield TP_MN\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 171, (Destin->TP_MN))
	} 
#endif
	Len = DECODE_c_TAddress (Buffer, CurrOfs, (&(Destin->TP_DA)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:174> Message too short decoding subfield TP_DA\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 173, (Destin->TP_DA))
	} 
#endif
	Len = DECODE_c_TP_CD (Buffer, CurrOfs, (&(Destin->TP_CD)), (Length-(CurrOfs-BitOffset)));CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:176> Message too short decoding subfield TP_CD\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 175, (Destin->TP_CD))
	} 
#endif
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(Destin->spare___LOCATOR), CurrOfs, (Length-(CurrOfs-BitOffset)));
	if ((Length-(CurrOfs-BitOffset)) > 0) {
		/* BINDEC02 */
		ALLOC_c_SMS_COMMAND_spare (&(Destin->spare), (Length-(CurrOfs-BitOffset)));
	
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
		ED_SIGNAL_ERROR ("<ERRID:178> Message too short decoding subfield spare\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 177, (Destin->spare))
	} 
#endif

	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
