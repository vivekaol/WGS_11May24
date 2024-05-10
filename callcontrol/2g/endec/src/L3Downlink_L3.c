/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "L3Downlink_L3.h"
#include "ed_c_known_ie_L3.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_L3.h"
#include "L3Uplink_L3.h"
#include "CSN1DataTypes_L3.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 17, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_REQUEST_DN (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 18, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->CiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:858> Error encoding subfield CiphKeySequenceNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:859> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthParamRandUmtsChallOrGsmChall */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->AuthParamRandUmtsChallOrGsmChall> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs, (Source->AuthParamRandUmtsChallOrGsmChall), 0, 128);
		Len = 128;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:860> Error encoding subfield AuthParamRandUmtsChallOrGsmChall\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthParamAutn */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthParamAutn_Present) {
			/* Append to buffer IEI tag 0x20 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x20), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthParamAutn> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthParamAutn, 0, 128);
			Len = 128;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:861> Error encoding subfield AuthParamAutn\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REQUEST_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REQUEST_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_REQUEST_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{32, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE CiphKeySequenceNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->CiphKeySequenceNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17260=EDCore::TDMInteger) */Destin->CiphKeySequenceNum___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:862> Error decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 862, (Destin->CiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:863> Message too short decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 862, (Destin->CiphKeySequenceNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17262=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:864> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 864, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:865> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 864, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthParamRandUmtsChallOrGsmChall
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 128;
	/* Read value part LOCATOR_16 */
	EDCopyBits (Destin->AuthParamRandUmtsChallOrGsmChall, 0, Buffer, CurrOfs, 128);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17264=EDCore::TDMBinary) */Destin->AuthParamRandUmtsChallOrGsmChall___LOCATOR), CurrOfs, 128);
	RetLen = 128;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:866> Error decoding subfield AuthParamRandUmtsChallOrGsmChall\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 866, (Destin->AuthParamRandUmtsChallOrGsmChall))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:867> Message too short decoding subfield AuthParamRandUmtsChallOrGsmChall\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 866, (Destin->AuthParamRandUmtsChallOrGsmChall))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthParamAutn
	------------------------------------------------------*/
	/* Detect IEI tag 0x20 */
	ED_EXPECT_OPTIONAL_IE (0x20,  8, 868, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x20) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 128) {
			ED_SIGNAL_ERROR ("<ERRID:869> Size error decoding IE AuthParamAutn\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x20, 869, (Destin->AuthParamAutn))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->AuthParamAutn, 0, Buffer, CurrOfs, 128);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17266=EDCore::TDMBinary) */Destin->AuthParamAutn___LOCATOR), CurrOfs, 128);
		RetLen = 128;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:870> Error decoding subfield AuthParamAutn\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x20, 870, (Destin->AuthParamAutn))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:871> Message too short decoding subfield AuthParamAutn\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x20, 870, (Destin->AuthParamAutn))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CM_SERVICE_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_CM_SERVICE_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 33, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_CM_SERVICE_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_PROMPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CM_SERVICE_PROMPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_CM_SERVICE_PROMPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 37, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for PdAndSapiOfCm */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->PdAndSapiOfCm> DOT=<.> */
		Len = ENCODE_c_PdAndSapiCcbs (Buffer, CurrOfs, (&(Source->PdAndSapiOfCm)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:872> Error encoding subfield PdAndSapiOfCm\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_PROMPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_PROMPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_PROMPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_PROMPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_PROMPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_PROMPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_PROMPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_PROMPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_PROMPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_PROMPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_PROMPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_CM_SERVICE_PROMPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_PROMPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_PROMPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_PROMPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE PdAndSapiOfCm
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PdAndSapiCcbs (Buffer, CurrOfs, (&(Destin->PdAndSapiOfCm)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:873> Error decoding subfield PdAndSapiOfCm\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 873, (Destin->PdAndSapiOfCm))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:874> Message too short decoding subfield PdAndSapiOfCm\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 873, (Destin->PdAndSapiOfCm))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CM_SERVICE_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_CM_SERVICE_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 34, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RejCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RejCause> DOT=<.> */
		Len = ENCODE_c_RejectCause (Buffer, CurrOfs, (&(Source->RejCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:875> Error encoding subfield RejCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3246Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3246Value_Present) {
			/* Append to buffer IEI tag 0x36 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x36), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3246Value> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->T3246Value), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:876> Error encoding subfield T3246Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_CM_SERVICE_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{54, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE RejCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RejectCause (Buffer, CurrOfs, (&(Destin->RejCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:877> Error decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 877, (Destin->RejCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:878> Message too short decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 877, (Destin->RejCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3246Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x36 */
	ED_EXPECT_OPTIONAL_IE (0x36,  8, 879, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x36) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REJECT_DN_T3246Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:880> Size error decoding IE T3246Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REJECT_DN_T3246Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x36, 880, (Destin->T3246Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->T3246Value = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17275=EDCore::TDMOctet) */Destin->T3246Value___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:881> Error decoding subfield T3246Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REJECT_DN_T3246Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x36, 881, (Destin->T3246Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:882> Message too short decoding subfield T3246Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REJECT_DN_T3246Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x36, 881, (Destin->T3246Value))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ABORT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ABORT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ABORT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 41, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RejCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RejCause> DOT=<.> */
		Len = ENCODE_c_RejectCause (Buffer, CurrOfs, (&(Source->RejCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:883> Error encoding subfield RejCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ABORT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ABORT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ABORT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ABORT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ABORT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ABORT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ABORT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ABORT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ABORT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ABORT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ABORT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ABORT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ABORT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ABORT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ABORT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE RejCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RejectCause (Buffer, CurrOfs, (&(Destin->RejCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:884> Error decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 884, (Destin->RejCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:885> Message too short decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 884, (Destin->RejCause))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IDENTITY_REQUEST_DN (char* Buffer, ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 24, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for IdType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->IdType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->IdType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:886> Error encoding subfield IdType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:887> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_REQUEST_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_REQUEST_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_IDENTITY_REQUEST_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE IdType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->IdType = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17281=EDCore::TDMInteger) */Destin->IdType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:888> Error decoding subfield IdType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 888, (Destin->IdType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:889> Message too short decoding subfield IdType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 888, (Destin->IdType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17283=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:890> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 890, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:891> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 890, (Destin->SpareHalfOctet))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_LOCATION_UPDATING_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_LOCATION_UPDATING_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for LocationAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LocationAreaId> DOT=<.> */
		Len = ENCODE_c_LocationAreaId (Buffer, CurrOfs, (&(Source->LocationAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:892> Error encoding subfield LocationAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MobileId */
	{
		int TLV_Base = CurrOfs;
		if (Source->MobileId_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MobileId> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->MobileId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:893> Error encoding subfield MobileId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for FollowOnProceed */
	{
		if (Source->FollowOnProceed_Present) {
			/* Append to buffer IEI tag 0xA1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA1), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for CtsPermission */
	{
		if (Source->CtsPermission_Present) {
			/* Append to buffer IEI tag 0xA2 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA2), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for EquivPlmns */
	{
		int TLV_Base = CurrOfs;
		if (Source->EquivPlmns_Present) {
			/* Append to buffer IEI tag 0x4A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EquivPlmns> DOT=<->> */
			Len = ENCODE_c_PlmnList (Buffer, CurrOfs+8, Source->EquivPlmns);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:894> Error encoding subfield EquivPlmns\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EmergencyNumberList */
	{
		int TLV_Base = CurrOfs;
		if (Source->EmergencyNumberList_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EmergencyNumberList> DOT=<->> */
			Len = ENCODE_c_EmergencyNumberList (Buffer, CurrOfs+8, Source->EmergencyNumberList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:895> Error encoding subfield EmergencyNumberList\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LOCATION_UPDATING_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_LOCATION_UPDATING_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_LOCATION_UPDATING_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_LOCATION_UPDATING_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LOCATION_UPDATING_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_LOCATION_UPDATING_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_LOCATION_UPDATING_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{161, 255, ED_SKIPLIST_OPTIONAL},
		{162, 255, ED_SKIPLIST_OPTIONAL},
		{74, 255, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE LocationAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 40;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LocationAreaId (Buffer, CurrOfs, (&(Destin->LocationAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:896> Error decoding subfield LocationAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 896, (Destin->LocationAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:897> Message too short decoding subfield LocationAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 896, (Destin->LocationAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileId
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 898, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:899> Size error decoding IE MobileId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x17, 899, (Destin->MobileId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->MobileId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:900> Error decoding subfield MobileId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 900, (Destin->MobileId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:901> Message too short decoding subfield MobileId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 900, (Destin->MobileId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE FollowOnProceed
	------------------------------------------------------*/
	/* Detect IEI tag 0xA1 */
	ED_EXPECT_OPTIONAL_IE (0xA1,  8, 902, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA1) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_FollowOnProceed (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CtsPermission
	------------------------------------------------------*/
	/* Detect IEI tag 0xA2 */
	ED_EXPECT_OPTIONAL_IE (0xA2,  8, 905, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA2) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_CtsPermission (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EquivPlmns
	------------------------------------------------------*/
	/* Detect IEI tag 0x4A */
	ED_EXPECT_OPTIONAL_IE (0x4A,  8, 908, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x4A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 120)) {
			ED_SIGNAL_ERROR ("<ERRID:909> Size error decoding IE EquivPlmns\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4A, 909, (Destin->EquivPlmns))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PlmnList (Buffer, CurrOfs, Destin->EquivPlmns, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:910> Error decoding subfield EquivPlmns\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4A, 910, (Destin->EquivPlmns))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:911> Message too short decoding subfield EquivPlmns\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4A, 910, (Destin->EquivPlmns))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EmergencyNumberList
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 912, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 384)) {
			ED_SIGNAL_ERROR ("<ERRID:913> Size error decoding IE EmergencyNumberList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 913, (Destin->EmergencyNumberList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EmergencyNumberList (Buffer, CurrOfs, Destin->EmergencyNumberList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:914> Error decoding subfield EmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 914, (Destin->EmergencyNumberList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:915> Message too short decoding subfield EmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 914, (Destin->EmergencyNumberList))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_LOCATION_UPDATING_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 4, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RejCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RejCause> DOT=<.> */
		Len = ENCODE_c_RejectCause (Buffer, CurrOfs, (&(Source->RejCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:916> Error encoding subfield RejCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LOCATION_UPDATING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_LOCATION_UPDATING_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_LOCATION_UPDATING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_LOCATION_UPDATING_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LOCATION_UPDATING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_LOCATION_UPDATING_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_LOCATION_UPDATING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE RejCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RejectCause (Buffer, CurrOfs, (&(Destin->RejCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:917> Error decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 917, (Destin->RejCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:918> Message too short decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 917, (Destin->RejCause))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_INFORMATION_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MM_INFORMATION_DN (char* Buffer, ED_EXLONG BitOffset, const c_MM_INFORMATION_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 50, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for FullNameForNetwk */
	{
		int TLV_Base = CurrOfs;
		if (Source->FullNameForNetwk_Present) {
			/* Append to buffer IEI tag 0x43 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x43), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->FullNameForNetwk> DOT=<->> */
			Len = ENCODE_c_NetwkName (Buffer, CurrOfs+8, Source->FullNameForNetwk);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:919> Error encoding subfield FullNameForNetwk\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ShortNameForNetwk */
	{
		int TLV_Base = CurrOfs;
		if (Source->ShortNameForNetwk_Present) {
			/* Append to buffer IEI tag 0x45 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x45), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ShortNameForNetwk> DOT=<->> */
			Len = ENCODE_c_NetwkName (Buffer, CurrOfs+8, Source->ShortNameForNetwk);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:920> Error encoding subfield ShortNameForNetwk\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LocalTimeZone */
	{
		if (Source->LocalTimeZone_Present) {
			/* Append to buffer IEI tag 0x46 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x46), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LocalTimeZone> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->LocalTimeZone), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:921> Error encoding subfield LocalTimeZone\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for UniversalTimeAndLocalTimeZone */
	{
		if (Source->UniversalTimeAndLocalTimeZone_Present) {
			/* Append to buffer IEI tag 0x47 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x47), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->UniversalTimeAndLocalTimeZone> DOT=<->> */
			Len = ENCODE_c_TimeZoneAndTime (Buffer, CurrOfs, Source->UniversalTimeAndLocalTimeZone);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:922> Error encoding subfield UniversalTimeAndLocalTimeZone\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for LsaId */
	{
		int TLV_Base = CurrOfs;
		if (Source->LsaId_Present) {
			/* Append to buffer IEI tag 0x48 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x48), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LsaId> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LsaId->value, 0, Source->LsaId->usedBits);
			Len = Source->LsaId->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:923> Error encoding subfield LsaId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NetwkDaylightSavingTime */
	{
		int TLV_Base = CurrOfs;
		if (Source->NetwkDaylightSavingTime_Present) {
			/* Append to buffer IEI tag 0x49 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x49), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NetwkDaylightSavingTime> DOT=<->> */
			Len = ENCODE_c_DaylightSavingTime (Buffer, CurrOfs+8, Source->NetwkDaylightSavingTime);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:924> Error encoding subfield NetwkDaylightSavingTime\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_INFORMATION_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MM_INFORMATION_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_INFORMATION_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MM_INFORMATION_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_MM_INFORMATION_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{67, 255, ED_SKIPLIST_OPTIONAL},
		{69, 255, ED_SKIPLIST_OPTIONAL},
		{70, 255, ED_SKIPLIST_OPTIONAL},
		{71, 255, ED_SKIPLIST_OPTIONAL},
		{72, 255, ED_SKIPLIST_OPTIONAL},
		{73, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE FullNameForNetwk
	------------------------------------------------------*/
	/* Detect IEI tag 0x43 */
	ED_EXPECT_OPTIONAL_IE (0x43,  8, 925, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x43) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:926> Size error decoding IE FullNameForNetwk\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x43, 926, (Destin->FullNameForNetwk))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetwkName (Buffer, CurrOfs, Destin->FullNameForNetwk, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:927> Error decoding subfield FullNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x43, 927, (Destin->FullNameForNetwk))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:928> Message too short decoding subfield FullNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x43, 927, (Destin->FullNameForNetwk))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ShortNameForNetwk
	------------------------------------------------------*/
	/* Detect IEI tag 0x45 */
	ED_EXPECT_OPTIONAL_IE (0x45,  8, 929, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x45) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:930> Size error decoding IE ShortNameForNetwk\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x45, 930, (Destin->ShortNameForNetwk))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetwkName (Buffer, CurrOfs, Destin->ShortNameForNetwk, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:931> Error decoding subfield ShortNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x45, 931, (Destin->ShortNameForNetwk))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:932> Message too short decoding subfield ShortNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x45, 931, (Destin->ShortNameForNetwk))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LocalTimeZone
	------------------------------------------------------*/
	/* Detect IEI tag 0x46 */
	ED_EXPECT_OPTIONAL_IE (0x46,  8, 933, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x46) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LocalTimeZone (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->LocalTimeZone = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17306=EDCore::TDMInteger) */Destin->LocalTimeZone___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:934> Error decoding subfield LocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x46, 934, (Destin->LocalTimeZone))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:935> Message too short decoding subfield LocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x46, 934, (Destin->LocalTimeZone))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UniversalTimeAndLocalTimeZone
	------------------------------------------------------*/
	/* Detect IEI tag 0x47 */
	ED_EXPECT_OPTIONAL_IE (0x47,  8, 936, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x47) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 56;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TimeZoneAndTime (Buffer, CurrOfs, Destin->UniversalTimeAndLocalTimeZone, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:937> Error decoding subfield UniversalTimeAndLocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x47, 937, (Destin->UniversalTimeAndLocalTimeZone))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:938> Message too short decoding subfield UniversalTimeAndLocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x47, 937, (Destin->UniversalTimeAndLocalTimeZone))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LsaId
	------------------------------------------------------*/
	/* Detect IEI tag 0x48 */
	ED_EXPECT_OPTIONAL_IE (0x48,  8, 939, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x48) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LsaId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:940> Size error decoding IE LsaId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LsaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x48, 940, (Destin->LsaId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17310=EDCore::TDMBinary) */Destin->LsaId___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MM_INFORMATION_DN_LsaId (Destin->LsaId, Len);
		
			if (Destin->LsaId->value) {
				EDCopyBits (Destin->LsaId->value, 0, Buffer, CurrOfs, Len);
				Destin->LsaId->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LsaId->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:941> Error decoding subfield LsaId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LsaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x48, 941, (Destin->LsaId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:942> Message too short decoding subfield LsaId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_LsaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x48, 941, (Destin->LsaId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetwkDaylightSavingTime
	------------------------------------------------------*/
	/* Detect IEI tag 0x49 */
	ED_EXPECT_OPTIONAL_IE (0x49,  8, 943, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x49) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:944> Size error decoding IE NetwkDaylightSavingTime\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x49, 944, (Destin->NetwkDaylightSavingTime))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DaylightSavingTime (Buffer, CurrOfs, Destin->NetwkDaylightSavingTime, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:945> Error decoding subfield NetwkDaylightSavingTime\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x49, 945, (Destin->NetwkDaylightSavingTime))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:946> Message too short decoding subfield NetwkDaylightSavingTime\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x49, 945, (Destin->NetwkDaylightSavingTime))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMMAND_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_TMSI_REALLOCATION_COMMAND_DN (char* Buffer, ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMMAND_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 26, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for LocationAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LocationAreaId> DOT=<.> */
		Len = ENCODE_c_LocationAreaId (Buffer, CurrOfs, (&(Source->LocationAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:947> Error encoding subfield LocationAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MobileId */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileId> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->MobileId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:948> Error encoding subfield MobileId\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source))
{
	return L3_ENCODE_c_TMSI_REALLOCATION_COMMAND_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source))
{
	return L3_ENCODE_c_TMSI_REALLOCATION_COMMAND_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_TMSI_REALLOCATION_COMMAND_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE LocationAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 40;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LocationAreaId (Buffer, CurrOfs, (&(Destin->LocationAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:949> Error decoding subfield LocationAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 949, (Destin->LocationAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:950> Message too short decoding subfield LocationAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 949, (Destin->LocationAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileId
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 64)) {
		ED_SIGNAL_ERROR ("<ERRID:951> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 951, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:952> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 952, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:953> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 952, (Destin->MobileId))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ALERTING_DN (char* Buffer, ED_EXLONG BitOffset, const c_ALERTING_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:954> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProgrInd */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProgrInd_Present) {
			/* Append to buffer IEI tag 0x1E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProgrInd> DOT=<->> */
			Len = ENCODE_c_ProgrInd (Buffer, CurrOfs+8, Source->ProgrInd);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:955> Error encoding subfield ProgrInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:956> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ALERTING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ALERTING_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ALERTING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ALERTING_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ALERTING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_ALERTING_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ALERTING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{30, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 957, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:958> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 958, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17324=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ALERTING_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:959> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 959, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:960> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 959, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProgrInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x1E */
	ED_EXPECT_OPTIONAL_IE (0x1E,  8, 961, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_ProgrInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:962> Size error decoding IE ProgrInd\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1E, 962, (Destin->ProgrInd))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProgrInd (Buffer, CurrOfs, Destin->ProgrInd, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:963> Error decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1E, 963, (Destin->ProgrInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:964> Message too short decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1E, 963, (Destin->ProgrInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 965, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:966> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 966, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17328=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ALERTING_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:967> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 967, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:968> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 967, (Destin->UserUser))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CALL_PROCEEDING_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CALL_PROCEEDING_DN (char* Buffer, ED_EXLONG BitOffset, const c_CALL_PROCEEDING_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RepeatInd */
	{
		if (Source->RepeatInd_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RepeatInd> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->RepeatInd), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:969> Error encoding subfield RepeatInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for BearerCpblty1 */
	{
		int TLV_Base = CurrOfs;
		if (Source->BearerCpblty1_Present) {
			/* Append to buffer IEI tag 0x04 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty1> DOT=<->> */
			Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, Source->BearerCpblty1);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:970> Error encoding subfield BearerCpblty1\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BearerCpblty2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->BearerCpblty2_Present) {
			/* Append to buffer IEI tag 0x04 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty2> DOT=<->> */
			Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, Source->BearerCpblty2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:971> Error encoding subfield BearerCpblty2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:972> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProgrInd */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProgrInd_Present) {
			/* Append to buffer IEI tag 0x1E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProgrInd> DOT=<->> */
			Len = ENCODE_c_ProgrInd (Buffer, CurrOfs+8, Source->ProgrInd);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:973> Error encoding subfield ProgrInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PriorityGranted */
	{
		if (Source->PriorityGranted_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->PriorityGranted> DOT=<->> */
			Len = ENCODE_c_PriorityLevel (Buffer, CurrOfs, Source->PriorityGranted);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:974> Error encoding subfield PriorityGranted\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NetwkCallControlCapabil */
	{
		int TLV_Base = CurrOfs;
		if (Source->NetwkCallControlCapabil_Present) {
			/* Append to buffer IEI tag 0x2F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NetwkCallControlCapabil> DOT=<->> */
			Len = ENCODE_c_NetwkCallControlCapabil (Buffer, CurrOfs+8, Source->NetwkCallControlCapabil);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:975> Error encoding subfield NetwkCallControlCapabil\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CALL_PROCEEDING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CALL_PROCEEDING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_PROCEEDING_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CALL_PROCEEDING_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CALL_PROCEEDING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CALL_PROCEEDING_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_PROCEEDING_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CALL_PROCEEDING_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CALL_PROCEEDING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CALL_PROCEEDING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_PROCEEDING_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CALL_PROCEEDING_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CALL_PROCEEDING_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CALL_PROCEEDING_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_PROCEEDING_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{30, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{47, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE RepeatInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 976, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_RepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17335=EDCore::TDMInteger) */Destin->RepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:977> Error decoding subfield RepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_RepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 977, (Destin->RepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:978> Message too short decoding subfield RepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_RepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 977, (Destin->RepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty1
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 979, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:980> Size error decoding IE BearerCpblty1\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 980, (Destin->BearerCpblty1))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty1, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:981> Error decoding subfield BearerCpblty1\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 981, (Destin->BearerCpblty1))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:982> Message too short decoding subfield BearerCpblty1\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 981, (Destin->BearerCpblty1))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty2
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 983, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:984> Size error decoding IE BearerCpblty2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 984, (Destin->BearerCpblty2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:985> Error decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 985, (Destin->BearerCpblty2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:986> Message too short decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 985, (Destin->BearerCpblty2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 987, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:988> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 988, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17341=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CALL_PROCEEDING_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:989> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 989, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:990> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 989, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProgrInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x1E */
	ED_EXPECT_OPTIONAL_IE (0x1E,  8, 991, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:992> Size error decoding IE ProgrInd\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1E, 992, (Destin->ProgrInd))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProgrInd (Buffer, CurrOfs, Destin->ProgrInd, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:993> Error decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1E, 993, (Destin->ProgrInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:994> Message too short decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1E, 993, (Destin->ProgrInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PriorityGranted
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 995, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_PriorityGranted (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PriorityLevel (Buffer, CurrOfs, Destin->PriorityGranted, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:996> Error decoding subfield PriorityGranted\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_PriorityGranted (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 996, (Destin->PriorityGranted))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:997> Message too short decoding subfield PriorityGranted\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_PriorityGranted (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 996, (Destin->PriorityGranted))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetwkCallControlCapabil
	------------------------------------------------------*/
	/* Detect IEI tag 0x2F */
	ED_EXPECT_OPTIONAL_IE (0x2F,  8, 998, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:999> Size error decoding IE NetwkCallControlCapabil\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2F, 999, (Destin->NetwkCallControlCapabil))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetwkCallControlCapabil (Buffer, CurrOfs, Destin->NetwkCallControlCapabil, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1000> Error decoding subfield NetwkCallControlCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2F, 1000, (Destin->NetwkCallControlCapabil))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1001> Message too short decoding subfield NetwkCallControlCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2F, 1000, (Destin->NetwkCallControlCapabil))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONGESTION_CONTROL_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CONGESTION_CONTROL_DN (char* Buffer, ED_EXLONG BitOffset, const c_CONGESTION_CONTROL_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 57, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CongestionLevel */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CongestionLevel> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->CongestionLevel), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1002> Error encoding subfield CongestionLevel\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1003> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		if (Source->Cause_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<->> */
			Len = ENCODE_c_Cause (Buffer, CurrOfs+8, Source->Cause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1004> Error encoding subfield Cause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONGESTION_CONTROL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONGESTION_CONTROL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONGESTION_CONTROL_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CONGESTION_CONTROL_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CONGESTION_CONTROL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONGESTION_CONTROL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONGESTION_CONTROL_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CONGESTION_CONTROL_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONGESTION_CONTROL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONGESTION_CONTROL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONGESTION_CONTROL_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CONGESTION_CONTROL_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONGESTION_CONTROL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONGESTION_CONTROL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONGESTION_CONTROL_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{8, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE CongestionLevel
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->CongestionLevel = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17354=EDCore::TDMInteger) */Destin->CongestionLevel___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1005> Error decoding subfield CongestionLevel\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1005, (Destin->CongestionLevel))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1006> Message too short decoding subfield CongestionLevel\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1005, (Destin->CongestionLevel))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17356=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1007> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1007, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1008> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1007, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 1009, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONGESTION_CONTROL_DN_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:1010> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONGESTION_CONTROL_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 1010, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1011> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONGESTION_CONTROL_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1011, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1012> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONGESTION_CONTROL_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1011, (Destin->Cause))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CONNECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_CONNECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1013> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProgrInd */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProgrInd_Present) {
			/* Append to buffer IEI tag 0x1E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProgrInd> DOT=<->> */
			Len = ENCODE_c_ProgrInd (Buffer, CurrOfs+8, Source->ProgrInd);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1014> Error encoding subfield ProgrInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ConnNum */
	{
		int TLV_Base = CurrOfs;
		if (Source->ConnNum_Present) {
			/* Append to buffer IEI tag 0x4C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ConnNum> DOT=<->> */
			Len = ENCODE_c_ConnNum (Buffer, CurrOfs+8, Source->ConnNum);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1015> Error encoding subfield ConnNum\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ConnSubaddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->ConnSubaddr_Present) {
			/* Append to buffer IEI tag 0x4D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ConnSubaddr> DOT=<->> */
			Len = ENCODE_c_ConnSubaddres (Buffer, CurrOfs+8, Source->ConnSubaddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1016> Error encoding subfield ConnSubaddr\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1017> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CONNECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CONNECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CONNECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{30, 255, ED_SKIPLIST_OPTIONAL},
		{76, 255, ED_SKIPLIST_OPTIONAL},
		{77, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 1018, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:1019> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 1019, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17365=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CONNECT_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1020> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 1020, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1021> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 1020, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProgrInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x1E */
	ED_EXPECT_OPTIONAL_IE (0x1E,  8, 1022, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ProgrInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:1023> Size error decoding IE ProgrInd\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1E, 1023, (Destin->ProgrInd))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProgrInd (Buffer, CurrOfs, Destin->ProgrInd, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1024> Error decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1E, 1024, (Destin->ProgrInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1025> Message too short decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1E, 1024, (Destin->ProgrInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ConnNum
	------------------------------------------------------*/
	/* Detect IEI tag 0x4C */
	ED_EXPECT_OPTIONAL_IE (0x4C,  8, 1026, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x4C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnNum (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 96)) {
			ED_SIGNAL_ERROR ("<ERRID:1027> Size error decoding IE ConnNum\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4C, 1027, (Destin->ConnNum))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ConnNum (Buffer, CurrOfs, Destin->ConnNum, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1028> Error decoding subfield ConnNum\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4C, 1028, (Destin->ConnNum))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1029> Message too short decoding subfield ConnNum\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4C, 1028, (Destin->ConnNum))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ConnSubaddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x4D */
	ED_EXPECT_OPTIONAL_IE (0x4D,  8, 1030, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x4D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnSubaddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:1031> Size error decoding IE ConnSubaddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnSubaddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4D, 1031, (Destin->ConnSubaddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ConnSubaddres (Buffer, CurrOfs, Destin->ConnSubaddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1032> Error decoding subfield ConnSubaddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnSubaddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4D, 1032, (Destin->ConnSubaddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1033> Message too short decoding subfield ConnSubaddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_ConnSubaddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4D, 1032, (Destin->ConnSubaddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 1034, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:1035> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 1035, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17373=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CONNECT_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1036> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 1036, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1037> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 1036, (Destin->UserUser))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DISCONNECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_DISCONNECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 37, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<.> */
		Len = ENCODE_c_Cause (Buffer, CurrOfs+8, (&(Source->Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1038> Error encoding subfield Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1039> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProgrInd */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProgrInd_Present) {
			/* Append to buffer IEI tag 0x1E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProgrInd> DOT=<->> */
			Len = ENCODE_c_ProgrInd (Buffer, CurrOfs+8, Source->ProgrInd);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1040> Error encoding subfield ProgrInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1041> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AllowedActionsCcbs */
	{
		int TLV_Base = CurrOfs;
		if (Source->AllowedActionsCcbs_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AllowedActionsCcbs> DOT=<->> */
			Len = ENCODE_c_AllowedActionsCcbs (Buffer, CurrOfs+8, Source->AllowedActionsCcbs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1042> Error encoding subfield AllowedActionsCcbs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DISCONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_DISCONNECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DISCONNECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_DISCONNECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DISCONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_DISCONNECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DISCONNECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{30, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 240)) {
		ED_SIGNAL_ERROR ("<ERRID:1043> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1043, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1044> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1044, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1045> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1044, (Destin->Cause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 1046, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:1047> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 1047, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17382=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DISCONNECT_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1048> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 1048, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1049> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 1048, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProgrInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x1E */
	ED_EXPECT_OPTIONAL_IE (0x1E,  8, 1050, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_ProgrInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:1051> Size error decoding IE ProgrInd\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1E, 1051, (Destin->ProgrInd))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProgrInd (Buffer, CurrOfs, Destin->ProgrInd, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1052> Error decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1E, 1052, (Destin->ProgrInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1053> Message too short decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1E, 1052, (Destin->ProgrInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 1054, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:1055> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 1055, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17386=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DISCONNECT_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1056> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 1056, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1057> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 1056, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AllowedActionsCcbs
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1058, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1059> Size error decoding IE AllowedActionsCcbs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1059, (Destin->AllowedActionsCcbs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AllowedActionsCcbs (Buffer, CurrOfs, Destin->AllowedActionsCcbs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1060> Error decoding subfield AllowedActionsCcbs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1060, (Destin->AllowedActionsCcbs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1061> Message too short decoding subfield AllowedActionsCcbs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1060, (Destin->AllowedActionsCcbs))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_FACILITY_DN (char* Buffer, ED_EXLONG BitOffset, const c_FACILITY_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 58, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, Source->Facility.value, 0, Source->Facility.usedBits);
		Len = Source->Facility.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1062> Error encoding subfield Facility\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FACILITY_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_DN* ED_CONST Source))
{
	return L3_ENCODE_c_FACILITY_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_FACILITY_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_DN* ED_CONST Source))
{
	return L3_ENCODE_c_FACILITY_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FACILITY_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_FACILITY_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_FACILITY_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 4792) {
		ED_SIGNAL_ERROR ("<ERRID:1063> Size error decoding IE Facility\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1063, (Destin->Facility))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17395=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_FACILITY_DN_Facility (&(Destin->Facility), Len);
	
		if (Destin->Facility.value) {
			EDCopyBits (Destin->Facility.value, 0, Buffer, CurrOfs, Len);
			Destin->Facility.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->Facility.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1064> Error decoding subfield Facility\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1064, (Destin->Facility))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1065> Message too short decoding subfield Facility\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1064, (Destin->Facility))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_ACKNOWLEDGE_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_HOLD_ACKNOWLEDGE_DN (char* Buffer, ED_EXLONG BitOffset, const c_HOLD_ACKNOWLEDGE_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 25, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HOLD_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_HOLD_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_HOLD_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_HOLD_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE HOLD_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HOLD_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_HOLD_ACKNOWLEDGE_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE HOLD_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_HOLD_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_HOLD_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_HOLD_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 26, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<.> */
		Len = ENCODE_c_Cause (Buffer, CurrOfs+8, (&(Source->Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1066> Error encoding subfield Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HOLD_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_HOLD_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_HOLD_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_HOLD_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE HOLD_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HOLD_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_HOLD_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE HOLD_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_HOLD_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 240)) {
		ED_SIGNAL_ERROR ("<ERRID:1067> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1067, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1068> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1068, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1069> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1068, (Destin->Cause))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PROGRESS_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_PROGRESS_DN (char* Buffer, ED_EXLONG BitOffset, const c_PROGRESS_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ProgrInd */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ProgrInd> DOT=<.> */
		Len = ENCODE_c_ProgrInd (Buffer, CurrOfs+8, (&(Source->ProgrInd)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1070> Error encoding subfield ProgrInd\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1071> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PROGRESS_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PROGRESS_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PROGRESS_DN* ED_CONST Source))
{
	return L3_ENCODE_c_PROGRESS_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE PROGRESS_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PROGRESS_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PROGRESS_DN* ED_CONST Source))
{
	return L3_ENCODE_c_PROGRESS_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PROGRESS_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PROGRESS_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PROGRESS_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_PROGRESS_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PROGRESS_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PROGRESS_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PROGRESS_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProgrInd
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 16) {
		ED_SIGNAL_ERROR ("<ERRID:1072> Size error decoding IE ProgrInd\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1072, (Destin->ProgrInd))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_ProgrInd (Buffer, CurrOfs, (&(Destin->ProgrInd)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1073> Error decoding subfield ProgrInd\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1073, (Destin->ProgrInd))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1074> Message too short decoding subfield ProgrInd\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1073, (Destin->ProgrInd))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 1075, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PROGRESS_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:1076> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PROGRESS_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 1076, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17416=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_PROGRESS_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1077> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PROGRESS_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 1077, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1078> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PROGRESS_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 1077, (Destin->UserUser))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CC_ESTABLISHMENT_DN (char* Buffer, ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 4, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SetupContainer */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->SetupContainer> DOT=<.> */
		Len = ENCODE_BODY_c_SETUP_UP (Buffer, CurrOfs+8, (&(Source->SetupContainer)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1079> Error encoding subfield SetupContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CC_ESTABLISHMENT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CC_ESTABLISHMENT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CC_ESTABLISHMENT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_CC_ESTABLISHMENT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CC_ESTABLISHMENT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CC_ESTABLISHMENT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CC_ESTABLISHMENT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE SetupContainer
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1080> Size error decoding IE SetupContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1080, (Destin->SetupContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_BODY_c_SETUP_UP (Buffer, CurrOfs, (&(Destin->SetupContainer)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1081> Error decoding subfield SetupContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1081, (Destin->SetupContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1082> Message too short decoding subfield SetupContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1081, (Destin->SetupContainer))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RELEASE_DN (char* Buffer, ED_EXLONG BitOffset, const c_RELEASE_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 45, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		if (Source->Cause_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<->> */
			Len = ENCODE_c_Cause (Buffer, CurrOfs+8, Source->Cause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1083> Error encoding subfield Cause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SecondCause */
	{
		int TLV_Base = CurrOfs;
		if (Source->SecondCause_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SecondCause> DOT=<->> */
			Len = ENCODE_c_Cause (Buffer, CurrOfs+8, Source->SecondCause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1084> Error encoding subfield SecondCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1085> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1086> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RELEASE_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{8, 255, ED_SKIPLIST_OPTIONAL},
		{8, 255, ED_SKIPLIST_OPTIONAL},
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 1087, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:1088> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 1088, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1089> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1089, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1090> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1089, (Destin->Cause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SecondCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 1091, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_SecondCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:1092> Size error decoding IE SecondCause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_SecondCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 1092, (Destin->SecondCause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->SecondCause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1093> Error decoding subfield SecondCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_SecondCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1093, (Destin->SecondCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1094> Message too short decoding subfield SecondCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_SecondCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1093, (Destin->SecondCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 1095, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:1096> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 1096, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17434=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1097> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 1097, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1098> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 1097, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 1099, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:1100> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 1100, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17436=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1101> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 1101, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1102> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 1101, (Destin->UserUser))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RECALL_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RECALL_DN (char* Buffer, ED_EXLONG BitOffset, const c_RECALL_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 11, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RecallType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RecallType> DOT=<.> */
		Len = ENCODE_c_RecallType (Buffer, CurrOfs, (&(Source->RecallType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1103> Error encoding subfield RecallType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, Source->Facility.value, 0, Source->Facility.usedBits);
		Len = Source->Facility.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1104> Error encoding subfield Facility\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RECALL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RECALL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RECALL_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RECALL_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RECALL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RECALL_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RECALL_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RECALL_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RECALL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RECALL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RECALL_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RECALL_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RECALL_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RECALL_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RECALL_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE RecallType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RecallType (Buffer, CurrOfs, (&(Destin->RecallType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1105> Error decoding subfield RecallType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1105, (Destin->RecallType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1106> Message too short decoding subfield RecallType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1105, (Destin->RecallType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1107> Size error decoding IE Facility\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1107, (Destin->Facility))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17445=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_RECALL_DN_Facility (&(Destin->Facility), Len);
	
		if (Destin->Facility.value) {
			EDCopyBits (Destin->Facility.value, 0, Buffer, CurrOfs, Len);
			Destin->Facility.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->Facility.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1108> Error decoding subfield Facility\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1108, (Destin->Facility))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1109> Message too short decoding subfield Facility\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1108, (Destin->Facility))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RELEASE_COMPLETE_DN (char* Buffer, ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 42, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		if (Source->Cause_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<->> */
			Len = ENCODE_c_Cause (Buffer, CurrOfs+8, Source->Cause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1110> Error encoding subfield Cause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1111> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1112> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_COMPLETE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_COMPLETE_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_COMPLETE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_COMPLETE_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_COMPLETE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RELEASE_COMPLETE_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_COMPLETE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{8, 255, ED_SKIPLIST_OPTIONAL},
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 1113, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:1114> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 1114, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1115> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1115, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1116> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1115, (Destin->Cause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 1117, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:1118> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 1118, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17454=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_COMPLETE_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1119> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 1119, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1120> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 1119, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 1121, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:1122> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 1122, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17456=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_COMPLETE_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1123> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 1123, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1124> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 1123, (Destin->UserUser))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_ACKNOWLEDGE_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RETRIEVE_ACKNOWLEDGE_DN (char* Buffer, ED_EXLONG BitOffset, const c_RETRIEVE_ACKNOWLEDGE_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 29, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RETRIEVE_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RETRIEVE_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RETRIEVE_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RETRIEVE_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RETRIEVE_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RETRIEVE_ACKNOWLEDGE_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RETRIEVE_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RETRIEVE_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_RETRIEVE_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 30, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<.> */
		Len = ENCODE_c_Cause (Buffer, CurrOfs+8, (&(Source->Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1125> Error encoding subfield Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RETRIEVE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RETRIEVE_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RETRIEVE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_RETRIEVE_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RETRIEVE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RETRIEVE_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RETRIEVE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 240)) {
		ED_SIGNAL_ERROR ("<ERRID:1126> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1126, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1127> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1127, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1128> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1127, (Destin->Cause))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SETUP_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SETUP_DN (char* Buffer, ED_EXLONG BitOffset, const c_SETUP_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for BcRepeatInd */
	{
		if (Source->BcRepeatInd_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->BcRepeatInd> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->BcRepeatInd), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1129> Error encoding subfield BcRepeatInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for BearerCpblty1 */
	{
		int TLV_Base = CurrOfs;
		if (Source->BearerCpblty1_Present) {
			/* Append to buffer IEI tag 0x04 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty1> DOT=<->> */
			Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, Source->BearerCpblty1);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1130> Error encoding subfield BearerCpblty1\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BearerCpblty2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->BearerCpblty2_Present) {
			/* Append to buffer IEI tag 0x04 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty2> DOT=<->> */
			Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, Source->BearerCpblty2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1131> Error encoding subfield BearerCpblty2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Facility */
	{
		int TLV_Base = CurrOfs;
		if (Source->Facility_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Facility> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->Facility->value, 0, Source->Facility->usedBits);
			Len = Source->Facility->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1132> Error encoding subfield Facility\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProgrInd */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProgrInd_Present) {
			/* Append to buffer IEI tag 0x1E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProgrInd> DOT=<->> */
			Len = ENCODE_c_ProgrInd (Buffer, CurrOfs+8, Source->ProgrInd);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1133> Error encoding subfield ProgrInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Signal */
	{
		if (Source->Signal_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->Signal> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->Signal), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1134> Error encoding subfield Signal\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for CallingPartyBcdNum */
	{
		int TLV_Base = CurrOfs;
		if (Source->CallingPartyBcdNum_Present) {
			/* Append to buffer IEI tag 0x5C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CallingPartyBcdNum> DOT=<->> */
			Len = ENCODE_c_CallingPartyBcdNum (Buffer, CurrOfs+8, Source->CallingPartyBcdNum);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1135> Error encoding subfield CallingPartyBcdNum\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CallingPartySubAddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->CallingPartySubAddr_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CallingPartySubAddr> DOT=<->> */
			Len = ENCODE_c_CallingPartySubaddr (Buffer, CurrOfs+8, Source->CallingPartySubAddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1136> Error encoding subfield CallingPartySubAddr\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CalledPartyBcdNum */
	{
		int TLV_Base = CurrOfs;
		if (Source->CalledPartyBcdNum_Present) {
			/* Append to buffer IEI tag 0x5E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CalledPartyBcdNum> DOT=<->> */
			Len = ENCODE_c_CalledPartyBcdNum (Buffer, CurrOfs+8, Source->CalledPartyBcdNum);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1137> Error encoding subfield CalledPartyBcdNum\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CalledPartySubAddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->CalledPartySubAddr_Present) {
			/* Append to buffer IEI tag 0x6D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CalledPartySubAddr> DOT=<->> */
			Len = ENCODE_c_CalledPartySubaddr (Buffer, CurrOfs+8, Source->CalledPartySubAddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1138> Error encoding subfield CalledPartySubAddr\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for RedirPartyBcdNum */
	{
		int TLV_Base = CurrOfs;
		if (Source->RedirPartyBcdNum_Present) {
			/* Append to buffer IEI tag 0x74 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x74), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RedirPartyBcdNum> DOT=<->> */
			Len = ENCODE_c_RedirPartyBcdNum (Buffer, CurrOfs+8, Source->RedirPartyBcdNum);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1139> Error encoding subfield RedirPartyBcdNum\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for RedirPartySubAddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->RedirPartySubAddr_Present) {
			/* Append to buffer IEI tag 0x75 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x75), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RedirPartySubAddr> DOT=<->> */
			Len = ENCODE_c_RedirPartySubaddr (Buffer, CurrOfs+8, Source->RedirPartySubAddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1140> Error encoding subfield RedirPartySubAddr\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LlcRepeatInd */
	{
		if (Source->LlcRepeatInd_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->LlcRepeatInd> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->LlcRepeatInd), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1141> Error encoding subfield LlcRepeatInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for LowLayerCpbilityI */
	{
		int TLV_Base = CurrOfs;
		if (Source->LowLayerCpbilityI_Present) {
			/* Append to buffer IEI tag 0x7C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LowLayerCpbilityI> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LowLayerCpbilityI->value, 0, Source->LowLayerCpbilityI->usedBits);
			Len = Source->LowLayerCpbilityI->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1142> Error encoding subfield LowLayerCpbilityI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LowLayerCpbilityIi */
	{
		int TLV_Base = CurrOfs;
		if (Source->LowLayerCpbilityIi_Present) {
			/* Append to buffer IEI tag 0x7C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LowLayerCpbilityIi> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LowLayerCpbilityIi->value, 0, Source->LowLayerCpbilityIi->usedBits);
			Len = Source->LowLayerCpbilityIi->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1143> Error encoding subfield LowLayerCpbilityIi\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HlcRepeatInd */
	{
		if (Source->HlcRepeatInd_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->HlcRepeatInd> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->HlcRepeatInd), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1144> Error encoding subfield HlcRepeatInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for HighLayerCpbilityI */
	{
		int TLV_Base = CurrOfs;
		if (Source->HighLayerCpbilityI_Present) {
			/* Append to buffer IEI tag 0x7D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HighLayerCpbilityI> DOT=<->> */
			Len = ENCODE_c_HighLayerCpbility (Buffer, CurrOfs+8, Source->HighLayerCpbilityI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1145> Error encoding subfield HighLayerCpbilityI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HighLayerCpbilityIi */
	{
		int TLV_Base = CurrOfs;
		if (Source->HighLayerCpbilityIi_Present) {
			/* Append to buffer IEI tag 0x7D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HighLayerCpbilityIi> DOT=<->> */
			Len = ENCODE_c_HighLayerCpbility (Buffer, CurrOfs+8, Source->HighLayerCpbilityIi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1146> Error encoding subfield HighLayerCpbilityIi\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		if (Source->UserUser_Present) {
			/* Append to buffer IEI tag 0x7E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UserUser->value, 0, Source->UserUser->usedBits);
			Len = Source->UserUser->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1147> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Priority */
	{
		if (Source->Priority_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->Priority> DOT=<->> */
			Len = ENCODE_c_PriorityLevel (Buffer, CurrOfs, Source->Priority);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1148> Error encoding subfield Priority\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for Alert */
	{
		int TLV_Base = CurrOfs;
		if (Source->Alert_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Alert> DOT=<->> */
			Len = ENCODE_c_AlertingPattern (Buffer, CurrOfs+8, Source->Alert);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1149> Error encoding subfield Alert\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NetwkCallControlCapabil */
	{
		int TLV_Base = CurrOfs;
		if (Source->NetwkCallControlCapabil_Present) {
			/* Append to buffer IEI tag 0x2F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NetwkCallControlCapabil> DOT=<->> */
			Len = ENCODE_c_NetwkCallControlCapabil (Buffer, CurrOfs+8, Source->NetwkCallControlCapabil);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1150> Error encoding subfield NetwkCallControlCapabil\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CauseOfNoCli */
	{
		int TLV_Base = CurrOfs;
		if (Source->CauseOfNoCli_Present) {
			/* Append to buffer IEI tag 0x3A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x3A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CauseOfNoCli> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->CauseOfNoCli), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1151> Error encoding subfield CauseOfNoCli\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BackupBearerCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->BackupBearerCapability_Present) {
			/* Append to buffer IEI tag 0x41 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x41), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BackupBearerCapability> DOT=<->> */
			Len = ENCODE_c_BackupBearerCapability (Buffer, CurrOfs+8, Source->BackupBearerCapability);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1152> Error encoding subfield BackupBearerCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SETUP_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SETUP_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_DN* ED_CONST Source))
{
	return L3_ENCODE_c_SETUP_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SETUP_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SETUP_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_DN* ED_CONST Source))
{
	return L3_ENCODE_c_SETUP_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SETUP_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SETUP_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_SETUP_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SETUP_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SETUP_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{30, 255, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{92, 255, ED_SKIPLIST_OPTIONAL},
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
		{109, 255, ED_SKIPLIST_OPTIONAL},
		{116, 255, ED_SKIPLIST_OPTIONAL},
		{117, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{47, 255, ED_SKIPLIST_OPTIONAL},
		{58, 255, ED_SKIPLIST_OPTIONAL},
		{65, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE BcRepeatInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 1153, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BcRepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->BcRepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17475=EDCore::TDMInteger) */Destin->BcRepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1154> Error decoding subfield BcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 1154, (Destin->BcRepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1155> Message too short decoding subfield BcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 1154, (Destin->BcRepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty1
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 1156, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty1 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:1157> Size error decoding IE BearerCpblty1\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 1157, (Destin->BearerCpblty1))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty1, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1158> Error decoding subfield BearerCpblty1\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 1158, (Destin->BearerCpblty1))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1159> Message too short decoding subfield BearerCpblty1\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 1158, (Destin->BearerCpblty1))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty2
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 1160, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:1161> Size error decoding IE BearerCpblty2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 1161, (Destin->BearerCpblty2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1162> Error decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 1162, (Destin->BearerCpblty2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1163> Message too short decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 1162, (Destin->BearerCpblty2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 1164, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:1165> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 1165, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17481=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_DN_Facility (Destin->Facility, Len);
		
			if (Destin->Facility->value) {
				EDCopyBits (Destin->Facility->value, 0, Buffer, CurrOfs, Len);
				Destin->Facility->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->Facility->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1166> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 1166, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1167> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 1166, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProgrInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x1E */
	ED_EXPECT_OPTIONAL_IE (0x1E,  8, 1168, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_ProgrInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:1169> Size error decoding IE ProgrInd\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1E, 1169, (Destin->ProgrInd))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProgrInd (Buffer, CurrOfs, Destin->ProgrInd, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1170> Error decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1E, 1170, (Destin->ProgrInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1171> Message too short decoding subfield ProgrInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_ProgrInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1E, 1170, (Destin->ProgrInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Signal
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1172, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Signal (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->Signal = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17485=EDCore::TDMOctet) */Destin->Signal___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1173> Error decoding subfield Signal\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Signal (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1173, (Destin->Signal))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1174> Message too short decoding subfield Signal\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Signal (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1173, (Destin->Signal))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CallingPartyBcdNum
	------------------------------------------------------*/
	/* Detect IEI tag 0x5C */
	ED_EXPECT_OPTIONAL_IE (0x5C,  8, 1175, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x5C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartyBcdNum (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 96)) {
			ED_SIGNAL_ERROR ("<ERRID:1176> Size error decoding IE CallingPartyBcdNum\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5C, 1176, (Destin->CallingPartyBcdNum))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CallingPartyBcdNum (Buffer, CurrOfs, Destin->CallingPartyBcdNum, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1177> Error decoding subfield CallingPartyBcdNum\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5C, 1177, (Destin->CallingPartyBcdNum))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1178> Message too short decoding subfield CallingPartyBcdNum\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5C, 1177, (Destin->CallingPartyBcdNum))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CallingPartySubAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 1179, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartySubAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:1180> Size error decoding IE CallingPartySubAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 1180, (Destin->CallingPartySubAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CallingPartySubaddr (Buffer, CurrOfs, Destin->CallingPartySubAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1181> Error decoding subfield CallingPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 1181, (Destin->CallingPartySubAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1182> Message too short decoding subfield CallingPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CallingPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 1181, (Destin->CallingPartySubAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CalledPartyBcdNum
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 1183, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartyBcdNum (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 136)) {
			ED_SIGNAL_ERROR ("<ERRID:1184> Size error decoding IE CalledPartyBcdNum\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 1184, (Destin->CalledPartyBcdNum))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CalledPartyBcdNum (Buffer, CurrOfs, Destin->CalledPartyBcdNum, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1185> Error decoding subfield CalledPartyBcdNum\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 1185, (Destin->CalledPartyBcdNum))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1186> Message too short decoding subfield CalledPartyBcdNum\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 1185, (Destin->CalledPartyBcdNum))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CalledPartySubAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x6D */
	ED_EXPECT_OPTIONAL_IE (0x6D,  8, 1187, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartySubAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:1188> Size error decoding IE CalledPartySubAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6D, 1188, (Destin->CalledPartySubAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CalledPartySubaddr (Buffer, CurrOfs, Destin->CalledPartySubAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1189> Error decoding subfield CalledPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6D, 1189, (Destin->CalledPartySubAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1190> Message too short decoding subfield CalledPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CalledPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6D, 1189, (Destin->CalledPartySubAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RedirPartyBcdNum
	------------------------------------------------------*/
	/* Detect IEI tag 0x74 */
	ED_EXPECT_OPTIONAL_IE (0x74,  8, 1191, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x74) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartyBcdNum (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 136)) {
			ED_SIGNAL_ERROR ("<ERRID:1192> Size error decoding IE RedirPartyBcdNum\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x74, 1192, (Destin->RedirPartyBcdNum))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RedirPartyBcdNum (Buffer, CurrOfs, Destin->RedirPartyBcdNum, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1193> Error decoding subfield RedirPartyBcdNum\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x74, 1193, (Destin->RedirPartyBcdNum))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1194> Message too short decoding subfield RedirPartyBcdNum\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartyBcdNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x74, 1193, (Destin->RedirPartyBcdNum))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RedirPartySubAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x75 */
	ED_EXPECT_OPTIONAL_IE (0x75,  8, 1195, 11, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x75) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartySubAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:1196> Size error decoding IE RedirPartySubAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x75, 1196, (Destin->RedirPartySubAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RedirPartySubaddr (Buffer, CurrOfs, Destin->RedirPartySubAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1197> Error decoding subfield RedirPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x75, 1197, (Destin->RedirPartySubAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1198> Message too short decoding subfield RedirPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_RedirPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x75, 1197, (Destin->RedirPartySubAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LlcRepeatInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 1199, 12, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LlcRepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->LlcRepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17499=EDCore::TDMInteger) */Destin->LlcRepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1200> Error decoding subfield LlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 1200, (Destin->LlcRepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1201> Message too short decoding subfield LlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 1200, (Destin->LlcRepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerCpbilityI
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 1202, 13, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:1203> Size error decoding IE LowLayerCpbilityI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 1203, (Destin->LowLayerCpbilityI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17501=EDCore::TDMBinary) */Destin->LowLayerCpbilityI___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_DN_LowLayerCpbilityI (Destin->LowLayerCpbilityI, Len);
		
			if (Destin->LowLayerCpbilityI->value) {
				EDCopyBits (Destin->LowLayerCpbilityI->value, 0, Buffer, CurrOfs, Len);
				Destin->LowLayerCpbilityI->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LowLayerCpbilityI->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1204> Error decoding subfield LowLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 1204, (Destin->LowLayerCpbilityI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1205> Message too short decoding subfield LowLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 1204, (Destin->LowLayerCpbilityI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerCpbilityIi
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 1206, 14, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityIi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:1207> Size error decoding IE LowLayerCpbilityIi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 1207, (Destin->LowLayerCpbilityIi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17503=EDCore::TDMBinary) */Destin->LowLayerCpbilityIi___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_DN_LowLayerCpbilityIi (Destin->LowLayerCpbilityIi, Len);
		
			if (Destin->LowLayerCpbilityIi->value) {
				EDCopyBits (Destin->LowLayerCpbilityIi->value, 0, Buffer, CurrOfs, Len);
				Destin->LowLayerCpbilityIi->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LowLayerCpbilityIi->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1208> Error decoding subfield LowLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 1208, (Destin->LowLayerCpbilityIi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1209> Message too short decoding subfield LowLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_LowLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 1208, (Destin->LowLayerCpbilityIi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HlcRepeatInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 1210, 15, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HlcRepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->HlcRepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17505=EDCore::TDMInteger) */Destin->HlcRepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1211> Error decoding subfield HlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 1211, (Destin->HlcRepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1212> Message too short decoding subfield HlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 1211, (Destin->HlcRepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerCpbilityI
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 1213, 16, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:1214> Size error decoding IE HighLayerCpbilityI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 1214, (Destin->HighLayerCpbilityI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerCpbilityI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1215> Error decoding subfield HighLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 1215, (Destin->HighLayerCpbilityI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1216> Message too short decoding subfield HighLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 1215, (Destin->HighLayerCpbilityI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerCpbilityIi
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 1217, 17, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityIi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:1218> Size error decoding IE HighLayerCpbilityIi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 1218, (Destin->HighLayerCpbilityIi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerCpbilityIi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1219> Error decoding subfield HighLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 1219, (Destin->HighLayerCpbilityIi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1220> Message too short decoding subfield HighLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_HighLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 1219, (Destin->HighLayerCpbilityIi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 1221, 18, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 264)) {
			ED_SIGNAL_ERROR ("<ERRID:1222> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 1222, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17511=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_DN_UserUser (Destin->UserUser, Len);
		
			if (Destin->UserUser->value) {
				EDCopyBits (Destin->UserUser->value, 0, Buffer, CurrOfs, Len);
				Destin->UserUser->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UserUser->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1223> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 1223, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1224> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 1223, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Priority
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 1225, 19, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Priority (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PriorityLevel (Buffer, CurrOfs, Destin->Priority, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1226> Error decoding subfield Priority\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Priority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1226, (Destin->Priority))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1227> Message too short decoding subfield Priority\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Priority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1226, (Destin->Priority))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Alert
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 1228, 20, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Alert (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1229> Size error decoding IE Alert\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Alert (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x19, 1229, (Destin->Alert))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AlertingPattern (Buffer, CurrOfs, Destin->Alert, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1230> Error decoding subfield Alert\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Alert (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 1230, (Destin->Alert))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1231> Message too short decoding subfield Alert\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_Alert (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 1230, (Destin->Alert))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetwkCallControlCapabil
	------------------------------------------------------*/
	/* Detect IEI tag 0x2F */
	ED_EXPECT_OPTIONAL_IE (0x2F,  8, 1232, 21, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_NetwkCallControlCapabil (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1233> Size error decoding IE NetwkCallControlCapabil\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_NetwkCallControlCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2F, 1233, (Destin->NetwkCallControlCapabil))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetwkCallControlCapabil (Buffer, CurrOfs, Destin->NetwkCallControlCapabil, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1234> Error decoding subfield NetwkCallControlCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_NetwkCallControlCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2F, 1234, (Destin->NetwkCallControlCapabil))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1235> Message too short decoding subfield NetwkCallControlCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_NetwkCallControlCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2F, 1234, (Destin->NetwkCallControlCapabil))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CauseOfNoCli
	------------------------------------------------------*/
	/* Detect IEI tag 0x3A */
	ED_EXPECT_OPTIONAL_IE (0x3A,  8, 1236, 22, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x3A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CauseOfNoCli (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1237> Size error decoding IE CauseOfNoCli\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CauseOfNoCli (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x3A, 1237, (Destin->CauseOfNoCli))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->CauseOfNoCli = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17519=EDCore::TDMOctet) */Destin->CauseOfNoCli___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1238> Error decoding subfield CauseOfNoCli\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CauseOfNoCli (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x3A, 1238, (Destin->CauseOfNoCli))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1239> Message too short decoding subfield CauseOfNoCli\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_CauseOfNoCli (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x3A, 1238, (Destin->CauseOfNoCli))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BackupBearerCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x41 */
	ED_EXPECT_OPTIONAL_IE (0x41,  8, 1240, 23, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x41) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BackupBearerCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 104)) {
			ED_SIGNAL_ERROR ("<ERRID:1241> Size error decoding IE BackupBearerCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BackupBearerCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x41, 1241, (Destin->BackupBearerCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BackupBearerCapability (Buffer, CurrOfs, Destin->BackupBearerCapability, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1242> Error decoding subfield BackupBearerCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BackupBearerCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x41, 1242, (Destin->BackupBearerCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1243> Message too short decoding subfield BackupBearerCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_DN_BackupBearerCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x41, 1242, (Destin->BackupBearerCapability))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_ACKNOWLEDGE_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_START_DTMF_ACKNOWLEDGE_DN (char* Buffer, ED_EXLONG BitOffset, const c_START_DTMF_ACKNOWLEDGE_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 54, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for KeypadFacility */
	{
		/* Append to buffer IEI tag 0x2C */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2C), 8);
		CurrOfs += 8;
		/* Append to buffer value part DEBUG FIELD=<Source->KeypadFacility> DOT=<.> */
		Len = ENCODE_c_KeypadFacility (Buffer, CurrOfs, (&(Source->KeypadFacility)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1244> Error encoding subfield KeypadFacility\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_START_DTMF_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_START_DTMF_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_START_DTMF_ACKNOWLEDGE_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE KeypadFacility
	------------------------------------------------------*/
	
	/* This is a mandatory field! Signal error if not found. */
	ED_EXPECT_MANDATORY_IE (0x2C,  8, 1245, KnownL3IEs_L3)
	CurrOfs += 8;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_KeypadFacility (Buffer, CurrOfs, (&(Destin->KeypadFacility)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1246> Error decoding subfield KeypadFacility\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR (0x2C, 1246, (Destin->KeypadFacility))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1247> Message too short decoding subfield KeypadFacility\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT (0x2C, 1246, (Destin->KeypadFacility))
	} 
#endif
	
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_START_DTMF_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_START_DTMF_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 55, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<.> */
		Len = ENCODE_c_Cause (Buffer, CurrOfs+8, (&(Source->Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1248> Error encoding subfield Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_DTMF_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_START_DTMF_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_DTMF_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_START_DTMF_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_DTMF_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_START_DTMF_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_DTMF_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 240)) {
		ED_SIGNAL_ERROR ("<ERRID:1249> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1249, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1250> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1250, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1251> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1250, (Destin->Cause))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_ACKNOWLEDGE_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_STOP_DTMF_ACKNOWLEDGE_DN (char* Buffer, ED_EXLONG BitOffset, const c_STOP_DTMF_ACKNOWLEDGE_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode transaction identifier */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 50, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STOP_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_STOP_DTMF_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STOP_DTMF_ACKNOWLEDGE_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Source))
{
	return L3_ENCODE_c_STOP_DTMF_ACKNOWLEDGE_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STOP_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_STOP_DTMF_ACKNOWLEDGE_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_ACKNOWLEDGE_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STOP_DTMF_ACKNOWLEDGE_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_ACKNOWLEDGE_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for AttachResult */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->AttachResult> DOT=<.> */
		Len = ENCODE_c_AttachResult (Buffer, (CurrOfs+4), (&(Source->AttachResult)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1252> Error encoding subfield AttachResult\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1253> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PeriodicRaUpdateTimer */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->PeriodicRaUpdateTimer> DOT=<.> */
		Len = ENCODE_c_GprsTimer (Buffer, CurrOfs, (&(Source->PeriodicRaUpdateTimer)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1254> Error encoding subfield PeriodicRaUpdateTimer\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for RadioPriorityForSms */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RadioPriorityForSms> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->RadioPriorityForSms), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1255> Error encoding subfield RadioPriorityForSms\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1256> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for RoutingAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RoutingAreaId> DOT=<.> */
		Len = ENCODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Source->RoutingAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1257> Error encoding subfield RoutingAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PTmsiSign */
	{
		if (Source->PTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->PTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1258> Error encoding subfield PTmsiSign\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NegotiatedRdyTimerValue */
	{
		if (Source->NegotiatedRdyTimerValue_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedRdyTimerValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer (Buffer, CurrOfs, Source->NegotiatedRdyTimerValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1259> Error encoding subfield NegotiatedRdyTimerValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AllocatedPTmsi */
	{
		int TLV_Base = CurrOfs;
		if (Source->AllocatedPTmsi_Present) {
			/* Append to buffer IEI tag 0x18 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x18), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AllocatedPTmsi> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->AllocatedPTmsi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1260> Error encoding subfield AllocatedPTmsi\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MsId */
	{
		int TLV_Base = CurrOfs;
		if (Source->MsId_Present) {
			/* Append to buffer IEI tag 0x23 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x23), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MsId> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->MsId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1261> Error encoding subfield MsId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for GmmCause */
	{
		if (Source->GmmCause_Present) {
			/* Append to buffer IEI tag 0x25 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x25), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1262> Error encoding subfield GmmCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3302Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3302Value_Present) {
			/* Append to buffer IEI tag 0x2A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3302Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3302Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1263> Error encoding subfield T3302Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CellNotif */
	{
		if (Source->CellNotif_Present) {
			/* Append to buffer IEI tag 0x8C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x8C), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for EquivPlmns */
	{
		int TLV_Base = CurrOfs;
		if (Source->EquivPlmns_Present) {
			/* Append to buffer IEI tag 0x4A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EquivPlmns> DOT=<->> */
			Len = ENCODE_c_PlmnList (Buffer, CurrOfs+8, Source->EquivPlmns);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1264> Error encoding subfield EquivPlmns\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NetworkFeatureSupport */
	{
		if (Source->NetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x0B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0B), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->NetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_NetworkFeatureSupport (Buffer, CurrOfs, Source->NetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1265> Error encoding subfield NetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for EmergencyNumberList */
	{
		int TLV_Base = CurrOfs;
		if (Source->EmergencyNumberList_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EmergencyNumberList> DOT=<->> */
			Len = ENCODE_c_EmergencyNumberList (Buffer, CurrOfs+8, Source->EmergencyNumberList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1266> Error encoding subfield EmergencyNumberList\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for RequestedMSInformation */
	{
		if (Source->RequestedMSInformation_Present) {
			/* Append to buffer IEI tag 0x0A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0A), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RequestedMSInformation> DOT=<->> */
			Len = ENCODE_c_RequestedMSInformation (Buffer, CurrOfs, Source->RequestedMSInformation);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1267> Error encoding subfield RequestedMSInformation\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3319Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3319Value_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3319Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3319Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1268> Error encoding subfield T3319Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3323Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3323Value_Present) {
			/* Append to buffer IEI tag 0x38 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x38), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3323Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3323Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1269> Error encoding subfield T3323Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3312ExtendedValue */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3312ExtendedValue_Present) {
			/* Append to buffer IEI tag 0x39 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x39), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3312ExtendedValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer3 (Buffer, CurrOfs+8, Source->T3312ExtendedValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1270> Error encoding subfield T3312ExtendedValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalNetworkFeatureSupport */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalNetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x66 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x66), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalNetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_AdditionalNetworkFeatureSupport (Buffer, CurrOfs+8, Source->AdditionalNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1271> Error encoding subfield AdditionalNetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3324Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3324Value_Present) {
			/* Append to buffer IEI tag 0x6A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3324Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3324Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1272> Error encoding subfield T3324Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedDRXParameters */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedDRXParameters_Present) {
			/* Append to buffer IEI tag 0x6E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedDRXParameters> DOT=<->> */
			Len = ENCODE_c_ExtendedDRXParameters (Buffer, CurrOfs+8, Source->ExtendedDRXParameters);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1273> Error encoding subfield ExtendedDRXParameters\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ATTACH_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{24, 255, ED_SKIPLIST_OPTIONAL},
		{35, 255, ED_SKIPLIST_OPTIONAL},
		{37, 255, ED_SKIPLIST_OPTIONAL},
		{42, 255, ED_SKIPLIST_OPTIONAL},
		{140, 255, ED_SKIPLIST_OPTIONAL},
		{74, 255, ED_SKIPLIST_OPTIONAL},
		{176, 240, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{160, 240, ED_SKIPLIST_OPTIONAL},
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{56, 255, ED_SKIPLIST_OPTIONAL},
		{57, 255, ED_SKIPLIST_OPTIONAL},
		{102, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE AttachResult
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_AttachResult (Buffer, (CurrOfs+4), (&(Destin->AttachResult)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1274> Error decoding subfield AttachResult\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1274, (Destin->AttachResult))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1275> Message too short decoding subfield AttachResult\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1274, (Destin->AttachResult))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs-4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17545=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1276> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1276, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1277> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1276, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PeriodicRaUpdateTimer
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_GprsTimer (Buffer, CurrOfs, (&(Destin->PeriodicRaUpdateTimer)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1278> Error decoding subfield PeriodicRaUpdateTimer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1278, (Destin->PeriodicRaUpdateTimer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1279> Message too short decoding subfield PeriodicRaUpdateTimer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1278, (Destin->PeriodicRaUpdateTimer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RadioPriorityForSms
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->RadioPriorityForSms = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17549=EDCore::TDMInteger) */Destin->RadioPriorityForSms___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1280> Error decoding subfield RadioPriorityForSms\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1280, (Destin->RadioPriorityForSms))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1281> Message too short decoding subfield RadioPriorityForSms\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1280, (Destin->RadioPriorityForSms))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17551=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1282> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1282, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1283> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1282, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RoutingAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 48;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Destin->RoutingAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1284> Error decoding subfield RoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1284, (Destin->RoutingAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1285> Message too short decoding subfield RoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1284, (Destin->RoutingAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 1286, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_PTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->PTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17555=EDCore::TDMBinary) */Destin->PTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1287> Error decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 1287, (Destin->PTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1288> Message too short decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 1287, (Destin->PTmsiSign))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedRdyTimerValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 1289, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer (Buffer, CurrOfs, Destin->NegotiatedRdyTimerValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1290> Error decoding subfield NegotiatedRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 1290, (Destin->NegotiatedRdyTimerValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1291> Message too short decoding subfield NegotiatedRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 1290, (Destin->NegotiatedRdyTimerValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AllocatedPTmsi
	------------------------------------------------------*/
	/* Detect IEI tag 0x18 */
	ED_EXPECT_OPTIONAL_IE (0x18,  8, 1292, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x18) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:1293> Size error decoding IE AllocatedPTmsi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x18, 1293, (Destin->AllocatedPTmsi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->AllocatedPTmsi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1294> Error decoding subfield AllocatedPTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x18, 1294, (Destin->AllocatedPTmsi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1295> Message too short decoding subfield AllocatedPTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x18, 1294, (Destin->AllocatedPTmsi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MsId
	------------------------------------------------------*/
	/* Detect IEI tag 0x23 */
	ED_EXPECT_OPTIONAL_IE (0x23,  8, 1296, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x23) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_MsId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 40) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:1297> Size error decoding IE MsId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_MsId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x23, 1297, (Destin->MsId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->MsId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1298> Error decoding subfield MsId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_MsId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x23, 1298, (Destin->MsId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1299> Message too short decoding subfield MsId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_MsId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x23, 1298, (Destin->MsId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE GmmCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x25 */
	ED_EXPECT_OPTIONAL_IE (0x25,  8, 1300, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x25) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_GmmCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17563=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1301> Error decoding subfield GmmCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_GmmCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x25, 1301, (Destin->GmmCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1302> Message too short decoding subfield GmmCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_GmmCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x25, 1301, (Destin->GmmCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3302Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x2A */
	ED_EXPECT_OPTIONAL_IE (0x2A,  8, 1303, 11, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1304> Size error decoding IE T3302Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2A, 1304, (Destin->T3302Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3302Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1305> Error decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2A, 1305, (Destin->T3302Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1306> Message too short decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2A, 1305, (Destin->T3302Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CellNotif
	------------------------------------------------------*/
	/* Detect IEI tag 0x8C */
	ED_EXPECT_OPTIONAL_IE (0x8C,  8, 1307, 12, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x8C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_CellNotif (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EquivPlmns
	------------------------------------------------------*/
	/* Detect IEI tag 0x4A */
	ED_EXPECT_OPTIONAL_IE (0x4A,  8, 1310, 13, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x4A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 120)) {
			ED_SIGNAL_ERROR ("<ERRID:1311> Size error decoding IE EquivPlmns\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4A, 1311, (Destin->EquivPlmns))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PlmnList (Buffer, CurrOfs, Destin->EquivPlmns, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1312> Error decoding subfield EquivPlmns\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4A, 1312, (Destin->EquivPlmns))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1313> Message too short decoding subfield EquivPlmns\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4A, 1312, (Destin->EquivPlmns))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x0B */
	ED_EXPECT_OPTIONAL_IE (0x0B,  4, 1314, 14, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetworkFeatureSupport (Buffer, CurrOfs, Destin->NetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1315> Error decoding subfield NetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0B, 1315, (Destin->NetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1316> Message too short decoding subfield NetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0B, 1315, (Destin->NetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EmergencyNumberList
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1317, 15, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 384)) {
			ED_SIGNAL_ERROR ("<ERRID:1318> Size error decoding IE EmergencyNumberList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1318, (Destin->EmergencyNumberList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EmergencyNumberList (Buffer, CurrOfs, Destin->EmergencyNumberList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1319> Error decoding subfield EmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1319, (Destin->EmergencyNumberList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1320> Message too short decoding subfield EmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1319, (Destin->EmergencyNumberList))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RequestedMSInformation
	------------------------------------------------------*/
	/* Detect IEI tag 0x0A */
	ED_EXPECT_OPTIONAL_IE (0x0A,  4, 1321, 16, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_RequestedMSInformation (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RequestedMSInformation (Buffer, CurrOfs, Destin->RequestedMSInformation, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1322> Error decoding subfield RequestedMSInformation\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_RequestedMSInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0A, 1322, (Destin->RequestedMSInformation))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1323> Message too short decoding subfield RequestedMSInformation\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_RequestedMSInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0A, 1322, (Destin->RequestedMSInformation))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3319Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1324, 17, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1325> Size error decoding IE T3319Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1325, (Destin->T3319Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3319Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1326> Error decoding subfield T3319Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1326, (Destin->T3319Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1327> Message too short decoding subfield T3319Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1326, (Destin->T3319Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3323Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x38 */
	ED_EXPECT_OPTIONAL_IE (0x38,  8, 1328, 18, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x38) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1329> Size error decoding IE T3323Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x38, 1329, (Destin->T3323Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3323Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1330> Error decoding subfield T3323Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x38, 1330, (Destin->T3323Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1331> Message too short decoding subfield T3323Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x38, 1330, (Destin->T3323Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3312ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x39 */
	ED_EXPECT_OPTIONAL_IE (0x39,  8, 1332, 19, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x39) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1333> Size error decoding IE T3312ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x39, 1333, (Destin->T3312ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3312ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1334> Error decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x39, 1334, (Destin->T3312ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1335> Message too short decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x39, 1334, (Destin->T3312ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x66 */
	ED_EXPECT_OPTIONAL_IE (0x66,  8, 1336, 20, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x66) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1337> Size error decoding IE AdditionalNetworkFeatureSupport\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x66, 1337, (Destin->AdditionalNetworkFeatureSupport))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalNetworkFeatureSupport (Buffer, CurrOfs, Destin->AdditionalNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1338> Error decoding subfield AdditionalNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x66, 1338, (Destin->AdditionalNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1339> Message too short decoding subfield AdditionalNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x66, 1338, (Destin->AdditionalNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 1340, 21, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1341> Size error decoding IE T3324Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 1341, (Destin->T3324Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3324Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1342> Error decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 1342, (Destin->T3324Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1343> Message too short decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 1342, (Destin->T3324Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 1344, 22, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1345> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 1345, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1346> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 1346, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1347> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 1346, (Destin->ExtendedDRXParameters))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 4, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GmmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1348> Error encoding subfield GmmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3302Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3302Value_Present) {
			/* Append to buffer IEI tag 0x2A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3302Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3302Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1349> Error encoding subfield T3302Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3346Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3346Value_Present) {
			/* Append to buffer IEI tag 0x3A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x3A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3346Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3346Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1350> Error encoding subfield T3346Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ATTACH_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{42, 255, ED_SKIPLIST_OPTIONAL},
		{58, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE GmmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17590=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1351> Error decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1351, (Destin->GmmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1352> Message too short decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1351, (Destin->GmmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3302Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x2A */
	ED_EXPECT_OPTIONAL_IE (0x2A,  8, 1353, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3302Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1354> Size error decoding IE T3302Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2A, 1354, (Destin->T3302Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3302Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1355> Error decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2A, 1355, (Destin->T3302Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1356> Message too short decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2A, 1355, (Destin->T3302Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3346Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x3A */
	ED_EXPECT_OPTIONAL_IE (0x3A,  8, 1357, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x3A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3346Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1358> Size error decoding IE T3346Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x3A, 1358, (Destin->T3346Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3346Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1359> Error decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x3A, 1359, (Destin->T3346Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1360> Message too short decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x3A, 1359, (Destin->T3346Value))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DETACH_REQUEST_DN (char* Buffer, ED_EXLONG BitOffset, const c_DETACH_REQUEST_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 5, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for DetachType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->DetachType> DOT=<.> */
		Len = ENCODE_c_DetachType (Buffer, (CurrOfs+4), (&(Source->DetachType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1361> Error encoding subfield DetachType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1362> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for GmmCause */
	{
		if (Source->GmmCause_Present) {
			/* Append to buffer IEI tag 0x25 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x25), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1363> Error encoding subfield GmmCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_REQUEST_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_REQUEST_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_DETACH_REQUEST_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{37, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE DetachType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_DetachType (Buffer, (CurrOfs+4), (&(Destin->DetachType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1364> Error decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1364, (Destin->DetachType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1365> Message too short decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1364, (Destin->DetachType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs-4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17599=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1366> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1366, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1367> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1366, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE GmmCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x25 */
	ED_EXPECT_OPTIONAL_IE (0x25,  8, 1368, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x25) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_DN_GmmCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17601=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1369> Error decoding subfield GmmCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_DN_GmmCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x25, 1369, (Destin->GmmCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1370> Message too short decoding subfield GmmCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_DN_GmmCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x25, 1369, (Destin->GmmCause))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DETACH_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_DETACH_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 6, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1371> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1372> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_DETACH_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17604=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1373> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1373, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1374> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1373, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17606=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1375> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1375, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1376> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1375, (Destin->SpareHalfOctet))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMMAND_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_P_TMSI_REALLOCATION_COMMAND_DN (char* Buffer, ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMMAND_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 16, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for AllocatedPTmsi */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->AllocatedPTmsi> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->AllocatedPTmsi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1377> Error encoding subfield AllocatedPTmsi\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RoutingAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RoutingAreaId> DOT=<.> */
		Len = ENCODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Source->RoutingAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1378> Error encoding subfield RoutingAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1379> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1380> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PTmsiSign */
	{
		if (Source->PTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->PTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1381> Error encoding subfield PTmsiSign\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source))
{
	return L3_ENCODE_c_P_TMSI_REALLOCATION_COMMAND_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_P_TMSI_REALLOCATION_COMMAND_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Source))
{
	return L3_ENCODE_c_P_TMSI_REALLOCATION_COMMAND_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_P_TMSI_REALLOCATION_COMMAND_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMMAND_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_P_TMSI_REALLOCATION_COMMAND_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMMAND_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE AllocatedPTmsi
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 40) {
		ED_SIGNAL_ERROR ("<ERRID:1382> Size error decoding IE AllocatedPTmsi\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1382, (Destin->AllocatedPTmsi))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->AllocatedPTmsi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1383> Error decoding subfield AllocatedPTmsi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1383, (Destin->AllocatedPTmsi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1384> Message too short decoding subfield AllocatedPTmsi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1383, (Destin->AllocatedPTmsi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RoutingAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 48;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Destin->RoutingAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1385> Error decoding subfield RoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1385, (Destin->RoutingAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1386> Message too short decoding subfield RoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1385, (Destin->RoutingAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17613=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1387> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1387, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1388> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1387, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17615=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1389> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1389, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1390> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1389, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 1391, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->PTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17617=EDCore::TDMBinary) */Destin->PTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1392> Error decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 1392, (Destin->PTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1393> Message too short decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 1392, (Destin->PTmsiSign))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REQUEST_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 18, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CiphAlg */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CiphAlg> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->CiphAlg), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1394> Error encoding subfield CiphAlg\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ImeisvReq */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ImeisvReq> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->ImeisvReq), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1395> Error encoding subfield ImeisvReq\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1396> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ACRefNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ACRefNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->ACRefNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1397> Error encoding subfield ACRefNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthParamRand */
	{
		if (Source->AuthParamRand_Present) {
			/* Append to buffer IEI tag 0x21 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x21), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthParamRand> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->AuthParamRand, 0, 128);
			Len = 128;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1398> Error encoding subfield AuthParamRand\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for GprsCiphKeySequenceNum */
	{
		if (Source->GprsCiphKeySequenceNum_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->GprsCiphKeySequenceNum> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->GprsCiphKeySequenceNum), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1399> Error encoding subfield GprsCiphKeySequenceNum\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AuthParamAutn */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthParamAutn_Present) {
			/* Append to buffer IEI tag 0x28 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x28), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthParamAutn> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthParamAutn, 0, 128);
			Len = 128;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1400> Error encoding subfield AuthParamAutn\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MsNetwkCpblty */
	{
		int TLV_Base = CurrOfs;
		if (Source->MsNetwkCpblty_Present) {
			/* Append to buffer IEI tag 0x31 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x31), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MsNetwkCpblty> DOT=<->> */
			Len = ENCODE_c_MsNetwkCpblty (Buffer, CurrOfs+8, Source->MsNetwkCpblty);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1401> Error encoding subfield MsNetwkCpblty\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for IntegrityProtectionAlgorithm */
	{
		int TLV_Base = CurrOfs;
		if (Source->IntegrityProtectionAlgorithm_Present) {
			/* Append to buffer IEI tag 0x42 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x42), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->IntegrityProtectionAlgorithm> DOT=<->> */
			Len = ENCODE_c_IntegrityProtectionAlgorithm (Buffer, CurrOfs+8, Source->IntegrityProtectionAlgorithm);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1402> Error encoding subfield IntegrityProtectionAlgorithm\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MessageAuthCode */
	{
		int TLV_Base = CurrOfs;
		if (Source->MessageAuthCode_Present) {
			/* Append to buffer IEI tag 0x43 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x43), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MessageAuthCode> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->MessageAuthCode), 32);
			Len = 32;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1403> Error encoding subfield MessageAuthCode\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{33, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{40, 255, ED_SKIPLIST_OPTIONAL},
		{49, 255, ED_SKIPLIST_OPTIONAL},
		{66, 255, ED_SKIPLIST_OPTIONAL},
		{67, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE CiphAlg
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->CiphAlg = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17620=EDCore::TDMOctet) */Destin->CiphAlg___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1404> Error decoding subfield CiphAlg\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1404, (Destin->CiphAlg))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1405> Message too short decoding subfield CiphAlg\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1404, (Destin->CiphAlg))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ImeisvReq
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ImeisvReq = (unsigned char)EDBitsToInt (Buffer, (CurrOfs-4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17622=EDCore::TDMOctet) */Destin->ImeisvReq___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1406> Error decoding subfield ImeisvReq\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1406, (Destin->ImeisvReq))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1407> Message too short decoding subfield ImeisvReq\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1406, (Destin->ImeisvReq))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17624=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1408> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1408, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1409> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1408, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ACRefNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ACRefNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17626=EDCore::TDMInteger) */Destin->ACRefNum___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1410> Error decoding subfield ACRefNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1410, (Destin->ACRefNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1411> Message too short decoding subfield ACRefNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1410, (Destin->ACRefNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthParamRand
	------------------------------------------------------*/
	/* Detect IEI tag 0x21 */
	ED_EXPECT_OPTIONAL_IE (0x21,  8, 1412, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x21) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 128;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->AuthParamRand, 0, Buffer, CurrOfs, 128);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17628=EDCore::TDMBinary) */Destin->AuthParamRand___LOCATOR), CurrOfs, 128);
		RetLen = 128;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1413> Error decoding subfield AuthParamRand\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x21, 1413, (Destin->AuthParamRand))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1414> Message too short decoding subfield AuthParamRand\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x21, 1413, (Destin->AuthParamRand))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE GprsCiphKeySequenceNum
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 1415, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->GprsCiphKeySequenceNum = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17630=EDCore::TDMInteger) */Destin->GprsCiphKeySequenceNum___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1416> Error decoding subfield GprsCiphKeySequenceNum\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1416, (Destin->GprsCiphKeySequenceNum))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1417> Message too short decoding subfield GprsCiphKeySequenceNum\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1416, (Destin->GprsCiphKeySequenceNum))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AuthParamAutn
	------------------------------------------------------*/
	/* Detect IEI tag 0x28 */
	ED_EXPECT_OPTIONAL_IE (0x28,  8, 1418, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x28) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 128) {
			ED_SIGNAL_ERROR ("<ERRID:1419> Size error decoding IE AuthParamAutn\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x28, 1419, (Destin->AuthParamAutn))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->AuthParamAutn, 0, Buffer, CurrOfs, 128);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17632=EDCore::TDMBinary) */Destin->AuthParamAutn___LOCATOR), CurrOfs, 128);
		RetLen = 128;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1420> Error decoding subfield AuthParamAutn\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x28, 1420, (Destin->AuthParamAutn))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1421> Message too short decoding subfield AuthParamAutn\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x28, 1420, (Destin->AuthParamAutn))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MsNetwkCpblty
	------------------------------------------------------*/
	/* Detect IEI tag 0x31 */
	ED_EXPECT_OPTIONAL_IE (0x31,  8, 1422, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x31) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:1423> Size error decoding IE MsNetwkCpblty\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x31, 1423, (Destin->MsNetwkCpblty))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MsNetwkCpblty (Buffer, CurrOfs, Destin->MsNetwkCpblty, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1424> Error decoding subfield MsNetwkCpblty\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x31, 1424, (Destin->MsNetwkCpblty))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1425> Message too short decoding subfield MsNetwkCpblty\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x31, 1424, (Destin->MsNetwkCpblty))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE IntegrityProtectionAlgorithm
	------------------------------------------------------*/
	/* Detect IEI tag 0x42 */
	ED_EXPECT_OPTIONAL_IE (0x42,  8, 1426, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x42) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1427> Size error decoding IE IntegrityProtectionAlgorithm\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x42, 1427, (Destin->IntegrityProtectionAlgorithm))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_IntegrityProtectionAlgorithm (Buffer, CurrOfs, Destin->IntegrityProtectionAlgorithm, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1428> Error decoding subfield IntegrityProtectionAlgorithm\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x42, 1428, (Destin->IntegrityProtectionAlgorithm))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1429> Message too short decoding subfield IntegrityProtectionAlgorithm\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x42, 1428, (Destin->IntegrityProtectionAlgorithm))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MessageAuthCode
	------------------------------------------------------*/
	/* Detect IEI tag 0x43 */
	ED_EXPECT_OPTIONAL_IE (0x43,  8, 1430, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x43) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 32) {
			ED_SIGNAL_ERROR ("<ERRID:1431> Size error decoding IE MessageAuthCode\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x43, 1431, (Destin->MessageAuthCode))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->MessageAuthCode = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17638=EDCore::TDMInteger) */Destin->MessageAuthCode___LOCATOR), CurrOfs, 32);
		RetLen = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1432> Error decoding subfield MessageAuthCode\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x43, 1432, (Destin->MessageAuthCode))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1433> Message too short decoding subfield MessageAuthCode\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x43, 1432, (Destin->MessageAuthCode))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 20, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_B_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IDENTITY_REQUEST_B_DN (char* Buffer, ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_B_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 21, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for IdType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->IdType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->IdType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1434> Error encoding subfield IdType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1435> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_B_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_REQUEST_B_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_B_DN* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_REQUEST_B_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_B_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_REQUEST_B_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST_B_DN* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_REQUEST_B_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_B_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_REQUEST_B_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_B_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_IDENTITY_REQUEST_B_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST_B_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_REQUEST_B_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST_B_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	
	/*----------------------------------------------------- 
		Code for IE IdType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->IdType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17642=EDCore::TDMOctet) */Destin->IdType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1436> Error decoding subfield IdType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1436, (Destin->IdType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1437> Message too short decoding subfield IdType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1436, (Destin->IdType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs-4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17644=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1438> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1438, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1439> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1438, (Destin->ForceToStandby))
	} 
#endif
	
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 9, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1440> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for UpdateResult */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->UpdateResult> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->UpdateResult), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1441> Error encoding subfield UpdateResult\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PeriodicRaUpdateTimer */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->PeriodicRaUpdateTimer> DOT=<.> */
		Len = ENCODE_c_GprsTimer (Buffer, CurrOfs, (&(Source->PeriodicRaUpdateTimer)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1442> Error encoding subfield PeriodicRaUpdateTimer\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for RoutingAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RoutingAreaId> DOT=<.> */
		Len = ENCODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Source->RoutingAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1443> Error encoding subfield RoutingAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PTmsiSign */
	{
		if (Source->PTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->PTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1444> Error encoding subfield PTmsiSign\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AllocatedPTmsi */
	{
		int TLV_Base = CurrOfs;
		if (Source->AllocatedPTmsi_Present) {
			/* Append to buffer IEI tag 0x18 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x18), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AllocatedPTmsi> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->AllocatedPTmsi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1445> Error encoding subfield AllocatedPTmsi\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MsId */
	{
		int TLV_Base = CurrOfs;
		if (Source->MsId_Present) {
			/* Append to buffer IEI tag 0x23 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x23), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MsId> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->MsId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1446> Error encoding subfield MsId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ListOfReceiveNPduNumbers */
	{
		int TLV_Base = CurrOfs;
		if (Source->ListOfReceiveNPduNumbers_Present) {
			/* Append to buffer IEI tag 0x26 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x26), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ListOfReceiveNPduNumbers> DOT=<->> */
			Len = ENCODE_c_ReceiveNPduNumbersList (Buffer, CurrOfs+8, Source->ListOfReceiveNPduNumbers);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1447> Error encoding subfield ListOfReceiveNPduNumbers\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedRdyTimerValue */
	{
		if (Source->NegotiatedRdyTimerValue_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedRdyTimerValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer (Buffer, CurrOfs, Source->NegotiatedRdyTimerValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1448> Error encoding subfield NegotiatedRdyTimerValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for GmmCause */
	{
		if (Source->GmmCause_Present) {
			/* Append to buffer IEI tag 0x25 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x25), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1449> Error encoding subfield GmmCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3302Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3302Value_Present) {
			/* Append to buffer IEI tag 0x2A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3302Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3302Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1450> Error encoding subfield T3302Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CellNotif */
	{
		if (Source->CellNotif_Present) {
			/* Append to buffer IEI tag 0x8C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x8C), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for EquivPlmns */
	{
		int TLV_Base = CurrOfs;
		if (Source->EquivPlmns_Present) {
			/* Append to buffer IEI tag 0x4A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EquivPlmns> DOT=<->> */
			Len = ENCODE_c_PlmnList (Buffer, CurrOfs+8, Source->EquivPlmns);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1451> Error encoding subfield EquivPlmns\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PdpContextStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->PdpContextStatus_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PdpContextStatus> DOT=<->> */
			Len = ENCODE_c_PdpContextStatus (Buffer, CurrOfs+8, Source->PdpContextStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1452> Error encoding subfield PdpContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NetworkFeatureSupport */
	{
		if (Source->NetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x0B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0B), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->NetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_NetworkFeatureSupport (Buffer, CurrOfs, Source->NetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1453> Error encoding subfield NetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for EmergencyNumberList */
	{
		int TLV_Base = CurrOfs;
		if (Source->EmergencyNumberList_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EmergencyNumberList> DOT=<->> */
			Len = ENCODE_c_EmergencyNumberList (Buffer, CurrOfs+8, Source->EmergencyNumberList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1454> Error encoding subfield EmergencyNumberList\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MBMSContextStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->MBMSContextStatus_Present) {
			/* Append to buffer IEI tag 0x35 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x35), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MBMSContextStatus> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->MBMSContextStatus->value, 0, Source->MBMSContextStatus->usedBits);
			Len = Source->MBMSContextStatus->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1455> Error encoding subfield MBMSContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for RequestedMSInformation */
	{
		if (Source->RequestedMSInformation_Present) {
			/* Append to buffer IEI tag 0x0A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0A), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RequestedMSInformation> DOT=<->> */
			Len = ENCODE_c_RequestedMSInformation (Buffer, CurrOfs, Source->RequestedMSInformation);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1456> Error encoding subfield RequestedMSInformation\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3319Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3319Value_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3319Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3319Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1457> Error encoding subfield T3319Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3323Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3323Value_Present) {
			/* Append to buffer IEI tag 0x38 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x38), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3323Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3323Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1458> Error encoding subfield T3323Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3312ExtendedValue */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3312ExtendedValue_Present) {
			/* Append to buffer IEI tag 0x39 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x39), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3312ExtendedValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer3 (Buffer, CurrOfs+8, Source->T3312ExtendedValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1459> Error encoding subfield T3312ExtendedValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalNetworkFeatureSupport */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalNetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x66 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x66), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalNetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_AdditionalNetworkFeatureSupport (Buffer, CurrOfs+8, Source->AdditionalNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1460> Error encoding subfield AdditionalNetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3324Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3324Value_Present) {
			/* Append to buffer IEI tag 0x6A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3324Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3324Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1461> Error encoding subfield T3324Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedDRXParameters */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedDRXParameters_Present) {
			/* Append to buffer IEI tag 0x6E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedDRXParameters> DOT=<->> */
			Len = ENCODE_c_ExtendedDRXParameters (Buffer, CurrOfs+8, Source->ExtendedDRXParameters);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1462> Error encoding subfield ExtendedDRXParameters\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ROUTING_AREA_UPDATE_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{24, 255, ED_SKIPLIST_OPTIONAL},
		{35, 255, ED_SKIPLIST_OPTIONAL},
		{38, 255, ED_SKIPLIST_OPTIONAL},
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{37, 255, ED_SKIPLIST_OPTIONAL},
		{42, 255, ED_SKIPLIST_OPTIONAL},
		{140, 255, ED_SKIPLIST_OPTIONAL},
		{74, 255, ED_SKIPLIST_OPTIONAL},
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{176, 240, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{160, 240, ED_SKIPLIST_OPTIONAL},
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{56, 255, ED_SKIPLIST_OPTIONAL},
		{57, 255, ED_SKIPLIST_OPTIONAL},
		{102, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17647=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1463> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1463, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1464> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1463, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE UpdateResult
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->UpdateResult = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17649=EDCore::TDMInteger) */Destin->UpdateResult___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1465> Error decoding subfield UpdateResult\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1465, (Destin->UpdateResult))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1466> Message too short decoding subfield UpdateResult\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1465, (Destin->UpdateResult))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PeriodicRaUpdateTimer
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_GprsTimer (Buffer, CurrOfs, (&(Destin->PeriodicRaUpdateTimer)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1467> Error decoding subfield PeriodicRaUpdateTimer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1467, (Destin->PeriodicRaUpdateTimer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1468> Message too short decoding subfield PeriodicRaUpdateTimer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1467, (Destin->PeriodicRaUpdateTimer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RoutingAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 48;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Destin->RoutingAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1469> Error decoding subfield RoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1469, (Destin->RoutingAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1470> Message too short decoding subfield RoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1469, (Destin->RoutingAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 1471, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->PTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17655=EDCore::TDMBinary) */Destin->PTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1472> Error decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 1472, (Destin->PTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1473> Message too short decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 1472, (Destin->PTmsiSign))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AllocatedPTmsi
	------------------------------------------------------*/
	/* Detect IEI tag 0x18 */
	ED_EXPECT_OPTIONAL_IE (0x18,  8, 1474, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x18) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:1475> Size error decoding IE AllocatedPTmsi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x18, 1475, (Destin->AllocatedPTmsi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->AllocatedPTmsi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1476> Error decoding subfield AllocatedPTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x18, 1476, (Destin->AllocatedPTmsi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1477> Message too short decoding subfield AllocatedPTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x18, 1476, (Destin->AllocatedPTmsi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MsId
	------------------------------------------------------*/
	/* Detect IEI tag 0x23 */
	ED_EXPECT_OPTIONAL_IE (0x23,  8, 1478, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x23) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 40) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:1479> Size error decoding IE MsId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x23, 1479, (Destin->MsId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->MsId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1480> Error decoding subfield MsId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x23, 1480, (Destin->MsId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1481> Message too short decoding subfield MsId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x23, 1480, (Destin->MsId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ListOfReceiveNPduNumbers
	------------------------------------------------------*/
	/* Detect IEI tag 0x26 */
	ED_EXPECT_OPTIONAL_IE (0x26,  8, 1482, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x26) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 136)) {
			ED_SIGNAL_ERROR ("<ERRID:1483> Size error decoding IE ListOfReceiveNPduNumbers\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x26, 1483, (Destin->ListOfReceiveNPduNumbers))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ReceiveNPduNumbersList (Buffer, CurrOfs, Destin->ListOfReceiveNPduNumbers, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1484> Error decoding subfield ListOfReceiveNPduNumbers\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x26, 1484, (Destin->ListOfReceiveNPduNumbers))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1485> Message too short decoding subfield ListOfReceiveNPduNumbers\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x26, 1484, (Destin->ListOfReceiveNPduNumbers))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedRdyTimerValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 1486, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer (Buffer, CurrOfs, Destin->NegotiatedRdyTimerValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1487> Error decoding subfield NegotiatedRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 1487, (Destin->NegotiatedRdyTimerValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1488> Message too short decoding subfield NegotiatedRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 1487, (Destin->NegotiatedRdyTimerValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE GmmCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x25 */
	ED_EXPECT_OPTIONAL_IE (0x25,  8, 1489, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x25) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17665=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1490> Error decoding subfield GmmCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x25, 1490, (Destin->GmmCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1491> Message too short decoding subfield GmmCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x25, 1490, (Destin->GmmCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3302Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x2A */
	ED_EXPECT_OPTIONAL_IE (0x2A,  8, 1492, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1493> Size error decoding IE T3302Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2A, 1493, (Destin->T3302Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3302Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1494> Error decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2A, 1494, (Destin->T3302Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1495> Message too short decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2A, 1494, (Destin->T3302Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CellNotif
	------------------------------------------------------*/
	/* Detect IEI tag 0x8C */
	ED_EXPECT_OPTIONAL_IE (0x8C,  8, 1496, 11, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x8C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_CellNotif (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EquivPlmns
	------------------------------------------------------*/
	/* Detect IEI tag 0x4A */
	ED_EXPECT_OPTIONAL_IE (0x4A,  8, 1499, 12, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x4A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 120)) {
			ED_SIGNAL_ERROR ("<ERRID:1500> Size error decoding IE EquivPlmns\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4A, 1500, (Destin->EquivPlmns))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PlmnList (Buffer, CurrOfs, Destin->EquivPlmns, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1501> Error decoding subfield EquivPlmns\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4A, 1501, (Destin->EquivPlmns))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1502> Message too short decoding subfield EquivPlmns\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4A, 1501, (Destin->EquivPlmns))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PdpContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 1503, 13, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:1504> Size error decoding IE PdpContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x32, 1504, (Destin->PdpContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PdpContextStatus (Buffer, CurrOfs, Destin->PdpContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1505> Error decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 1505, (Destin->PdpContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1506> Message too short decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 1505, (Destin->PdpContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x0B */
	ED_EXPECT_OPTIONAL_IE (0x0B,  4, 1507, 14, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetworkFeatureSupport (Buffer, CurrOfs, Destin->NetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1508> Error decoding subfield NetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0B, 1508, (Destin->NetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1509> Message too short decoding subfield NetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0B, 1508, (Destin->NetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EmergencyNumberList
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1510, 15, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 384)) {
			ED_SIGNAL_ERROR ("<ERRID:1511> Size error decoding IE EmergencyNumberList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1511, (Destin->EmergencyNumberList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EmergencyNumberList (Buffer, CurrOfs, Destin->EmergencyNumberList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1512> Error decoding subfield EmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1512, (Destin->EmergencyNumberList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1513> Message too short decoding subfield EmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1512, (Destin->EmergencyNumberList))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 1514, 16, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:1515> Size error decoding IE MBMSContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 1515, (Destin->MBMSContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17679=EDCore::TDMBinary) */Destin->MBMSContextStatus___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (Destin->MBMSContextStatus, Len);
		
			if (Destin->MBMSContextStatus->value) {
				EDCopyBits (Destin->MBMSContextStatus->value, 0, Buffer, CurrOfs, Len);
				Destin->MBMSContextStatus->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->MBMSContextStatus->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1516> Error decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 1516, (Destin->MBMSContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1517> Message too short decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 1516, (Destin->MBMSContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RequestedMSInformation
	------------------------------------------------------*/
	/* Detect IEI tag 0x0A */
	ED_EXPECT_OPTIONAL_IE (0x0A,  4, 1518, 17, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RequestedMSInformation (Buffer, CurrOfs, Destin->RequestedMSInformation, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1519> Error decoding subfield RequestedMSInformation\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0A, 1519, (Destin->RequestedMSInformation))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1520> Message too short decoding subfield RequestedMSInformation\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0A, 1519, (Destin->RequestedMSInformation))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3319Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1521, 18, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1522> Size error decoding IE T3319Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1522, (Destin->T3319Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3319Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1523> Error decoding subfield T3319Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1523, (Destin->T3319Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1524> Message too short decoding subfield T3319Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1523, (Destin->T3319Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3323Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x38 */
	ED_EXPECT_OPTIONAL_IE (0x38,  8, 1525, 19, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x38) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1526> Size error decoding IE T3323Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x38, 1526, (Destin->T3323Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3323Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1527> Error decoding subfield T3323Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x38, 1527, (Destin->T3323Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1528> Message too short decoding subfield T3323Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x38, 1527, (Destin->T3323Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3312ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x39 */
	ED_EXPECT_OPTIONAL_IE (0x39,  8, 1529, 20, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x39) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1530> Size error decoding IE T3312ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x39, 1530, (Destin->T3312ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3312ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1531> Error decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x39, 1531, (Destin->T3312ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1532> Message too short decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x39, 1531, (Destin->T3312ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x66 */
	ED_EXPECT_OPTIONAL_IE (0x66,  8, 1533, 21, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x66) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1534> Size error decoding IE AdditionalNetworkFeatureSupport\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x66, 1534, (Destin->AdditionalNetworkFeatureSupport))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalNetworkFeatureSupport (Buffer, CurrOfs, Destin->AdditionalNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1535> Error decoding subfield AdditionalNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x66, 1535, (Destin->AdditionalNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1536> Message too short decoding subfield AdditionalNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x66, 1535, (Destin->AdditionalNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 1537, 22, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1538> Size error decoding IE T3324Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 1538, (Destin->T3324Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3324Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1539> Error decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 1539, (Destin->T3324Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1540> Message too short decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 1539, (Destin->T3324Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 1541, 23, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1542> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 1542, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1543> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 1543, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1544> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 1543, (Destin->ExtendedDRXParameters))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ROUTING_AREA_UPDATE_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 11, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GmmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1545> Error encoding subfield GmmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ForceToStandby */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ForceToStandby> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ForceToStandby), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1546> Error encoding subfield ForceToStandby\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->SpareHalfOctet), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1547> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3302Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3302Value_Present) {
			/* Append to buffer IEI tag 0x2A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3302Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3302Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1548> Error encoding subfield T3302Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3346Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3346Value_Present) {
			/* Append to buffer IEI tag 0x3A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x3A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3346Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3346Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1549> Error encoding subfield T3346Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ROUTING_AREA_UPDATE_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{42, 255, ED_SKIPLIST_OPTIONAL},
		{58, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE GmmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17696=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1550> Error decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1550, (Destin->GmmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1551> Message too short decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1550, (Destin->GmmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ForceToStandby
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ForceToStandby = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17698=EDCore::TDMOctet) */Destin->ForceToStandby___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1552> Error decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1552, (Destin->ForceToStandby))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1553> Message too short decoding subfield ForceToStandby\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1552, (Destin->ForceToStandby))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->SpareHalfOctet = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17700=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1554> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1554, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1555> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1554, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3302Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x2A */
	ED_EXPECT_OPTIONAL_IE (0x2A,  8, 1556, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1557> Size error decoding IE T3302Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2A, 1557, (Destin->T3302Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3302Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1558> Error decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2A, 1558, (Destin->T3302Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1559> Message too short decoding subfield T3302Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2A, 1558, (Destin->T3302Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3346Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x3A */
	ED_EXPECT_OPTIONAL_IE (0x3A,  8, 1560, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x3A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1561> Size error decoding IE T3346Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x3A, 1561, (Destin->T3346Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3346Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1562> Error decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x3A, 1562, (Destin->T3346Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1563> Message too short decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x3A, 1562, (Destin->T3346Value))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GMM_INFORMATION_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_GMM_INFORMATION_DN (char* Buffer, ED_EXLONG BitOffset, const c_GMM_INFORMATION_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 33, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for FullNameForNetwk */
	{
		int TLV_Base = CurrOfs;
		if (Source->FullNameForNetwk_Present) {
			/* Append to buffer IEI tag 0x43 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x43), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->FullNameForNetwk> DOT=<->> */
			Len = ENCODE_c_NetwkName (Buffer, CurrOfs+8, Source->FullNameForNetwk);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1564> Error encoding subfield FullNameForNetwk\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ShortNameForNetwk */
	{
		int TLV_Base = CurrOfs;
		if (Source->ShortNameForNetwk_Present) {
			/* Append to buffer IEI tag 0x45 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x45), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ShortNameForNetwk> DOT=<->> */
			Len = ENCODE_c_NetwkName (Buffer, CurrOfs+8, Source->ShortNameForNetwk);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1565> Error encoding subfield ShortNameForNetwk\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LocalTimeZone */
	{
		if (Source->LocalTimeZone_Present) {
			/* Append to buffer IEI tag 0x46 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x46), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LocalTimeZone> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->LocalTimeZone), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1566> Error encoding subfield LocalTimeZone\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for UniversalTimeAndLocalTimeZone */
	{
		if (Source->UniversalTimeAndLocalTimeZone_Present) {
			/* Append to buffer IEI tag 0x47 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x47), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->UniversalTimeAndLocalTimeZone> DOT=<->> */
			Len = ENCODE_c_TimeZoneAndTime (Buffer, CurrOfs, Source->UniversalTimeAndLocalTimeZone);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1567> Error encoding subfield UniversalTimeAndLocalTimeZone\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for LsaId */
	{
		int TLV_Base = CurrOfs;
		if (Source->LsaId_Present) {
			/* Append to buffer IEI tag 0x48 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x48), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LsaId> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LsaId->value, 0, Source->LsaId->usedBits);
			Len = Source->LsaId->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1568> Error encoding subfield LsaId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NetwkDaylightSavingTime */
	{
		int TLV_Base = CurrOfs;
		if (Source->NetwkDaylightSavingTime_Present) {
			/* Append to buffer IEI tag 0x49 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x49), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NetwkDaylightSavingTime> DOT=<->> */
			Len = ENCODE_c_DaylightSavingTime (Buffer, CurrOfs+8, Source->NetwkDaylightSavingTime);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1569> Error encoding subfield NetwkDaylightSavingTime\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GMM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GMM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_INFORMATION_DN* ED_CONST Source))
{
	return L3_ENCODE_c_GMM_INFORMATION_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE GMM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GMM_INFORMATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_INFORMATION_DN* ED_CONST Source))
{
	return L3_ENCODE_c_GMM_INFORMATION_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GMM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GMM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_GMM_INFORMATION_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GMM_INFORMATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GMM_INFORMATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_INFORMATION_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{67, 255, ED_SKIPLIST_OPTIONAL},
		{69, 255, ED_SKIPLIST_OPTIONAL},
		{70, 255, ED_SKIPLIST_OPTIONAL},
		{71, 255, ED_SKIPLIST_OPTIONAL},
		{72, 255, ED_SKIPLIST_OPTIONAL},
		{73, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE FullNameForNetwk
	------------------------------------------------------*/
	/* Detect IEI tag 0x43 */
	ED_EXPECT_OPTIONAL_IE (0x43,  8, 1570, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x43) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:1571> Size error decoding IE FullNameForNetwk\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x43, 1571, (Destin->FullNameForNetwk))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetwkName (Buffer, CurrOfs, Destin->FullNameForNetwk, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1572> Error decoding subfield FullNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x43, 1572, (Destin->FullNameForNetwk))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1573> Message too short decoding subfield FullNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x43, 1572, (Destin->FullNameForNetwk))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ShortNameForNetwk
	------------------------------------------------------*/
	/* Detect IEI tag 0x45 */
	ED_EXPECT_OPTIONAL_IE (0x45,  8, 1574, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x45) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:1575> Size error decoding IE ShortNameForNetwk\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x45, 1575, (Destin->ShortNameForNetwk))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetwkName (Buffer, CurrOfs, Destin->ShortNameForNetwk, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1576> Error decoding subfield ShortNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x45, 1576, (Destin->ShortNameForNetwk))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1577> Message too short decoding subfield ShortNameForNetwk\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x45, 1576, (Destin->ShortNameForNetwk))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LocalTimeZone
	------------------------------------------------------*/
	/* Detect IEI tag 0x46 */
	ED_EXPECT_OPTIONAL_IE (0x46,  8, 1578, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x46) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LocalTimeZone (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->LocalTimeZone = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17711=EDCore::TDMInteger) */Destin->LocalTimeZone___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1579> Error decoding subfield LocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x46, 1579, (Destin->LocalTimeZone))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1580> Message too short decoding subfield LocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x46, 1579, (Destin->LocalTimeZone))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UniversalTimeAndLocalTimeZone
	------------------------------------------------------*/
	/* Detect IEI tag 0x47 */
	ED_EXPECT_OPTIONAL_IE (0x47,  8, 1581, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x47) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 56;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TimeZoneAndTime (Buffer, CurrOfs, Destin->UniversalTimeAndLocalTimeZone, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1582> Error decoding subfield UniversalTimeAndLocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x47, 1582, (Destin->UniversalTimeAndLocalTimeZone))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1583> Message too short decoding subfield UniversalTimeAndLocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x47, 1582, (Destin->UniversalTimeAndLocalTimeZone))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LsaId
	------------------------------------------------------*/
	/* Detect IEI tag 0x48 */
	ED_EXPECT_OPTIONAL_IE (0x48,  8, 1584, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x48) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LsaId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:1585> Size error decoding IE LsaId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LsaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x48, 1585, (Destin->LsaId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17715=EDCore::TDMBinary) */Destin->LsaId___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_GMM_INFORMATION_DN_LsaId (Destin->LsaId, Len);
		
			if (Destin->LsaId->value) {
				EDCopyBits (Destin->LsaId->value, 0, Buffer, CurrOfs, Len);
				Destin->LsaId->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LsaId->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1586> Error decoding subfield LsaId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LsaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x48, 1586, (Destin->LsaId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1587> Message too short decoding subfield LsaId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_LsaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x48, 1586, (Destin->LsaId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetwkDaylightSavingTime
	------------------------------------------------------*/
	/* Detect IEI tag 0x49 */
	ED_EXPECT_OPTIONAL_IE (0x49,  8, 1588, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x49) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1589> Size error decoding IE NetwkDaylightSavingTime\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x49, 1589, (Destin->NetwkDaylightSavingTime))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DaylightSavingTime (Buffer, CurrOfs, Destin->NetwkDaylightSavingTime, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1590> Error decoding subfield NetwkDaylightSavingTime\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x49, 1590, (Destin->NetwkDaylightSavingTime))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1591> Message too short decoding subfield NetwkDaylightSavingTime\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x49, 1590, (Destin->NetwkDaylightSavingTime))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SERVICE_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_SERVICE_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 13, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for PdpContextStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->PdpContextStatus_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PdpContextStatus> DOT=<->> */
			Len = ENCODE_c_PdpContextStatus (Buffer, CurrOfs+8, Source->PdpContextStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1592> Error encoding subfield PdpContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MBMSContextStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->MBMSContextStatus_Present) {
			/* Append to buffer IEI tag 0x35 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x35), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MBMSContextStatus> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->MBMSContextStatus->value, 0, Source->MBMSContextStatus->usedBits);
			Len = Source->MBMSContextStatus->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1593> Error encoding subfield MBMSContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_SERVICE_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE PdpContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 1594, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:1595> Size error decoding IE PdpContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x32, 1595, (Destin->PdpContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PdpContextStatus (Buffer, CurrOfs, Destin->PdpContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1596> Error decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 1596, (Destin->PdpContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1597> Message too short decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 1596, (Destin->PdpContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 1598, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:1599> Size error decoding IE MBMSContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 1599, (Destin->MBMSContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17722=EDCore::TDMBinary) */Destin->MBMSContextStatus___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SERVICE_ACCEPT_DN_MBMSContextStatus (Destin->MBMSContextStatus, Len);
		
			if (Destin->MBMSContextStatus->value) {
				EDCopyBits (Destin->MBMSContextStatus->value, 0, Buffer, CurrOfs, Len);
				Destin->MBMSContextStatus->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->MBMSContextStatus->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1600> Error decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 1600, (Destin->MBMSContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1601> Message too short decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 1600, (Destin->MBMSContextStatus))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SERVICE_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_SERVICE_REJECT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 14, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GmmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1602> Error encoding subfield GmmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3346Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3346Value_Present) {
			/* Append to buffer IEI tag 0x3A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x3A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3346Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer2 (Buffer, CurrOfs+8, Source->T3346Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1603> Error encoding subfield T3346Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_SERVICE_REJECT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Destin);
	ED_WARNING_REMOVER (Length);
	ED_EXTRAPARAMS_CODE

{
	/* Table containing the expected sequence of IEIs */
	const TEDTLVSkipItem TLVSkipItems [] = {
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{58, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE GmmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17725=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1604> Error decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1604, (Destin->GmmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1605> Message too short decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1604, (Destin->GmmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3346Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x3A */
	ED_EXPECT_OPTIONAL_IE (0x3A,  8, 1606, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x3A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_DN_T3346Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1607> Size error decoding IE T3346Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x3A, 1607, (Destin->T3346Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3346Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1608> Error decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x3A, 1608, (Destin->T3346Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1609> Message too short decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_DN_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x3A, 1608, (Destin->T3346Value))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_AUTHENTICATION_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 17) /* message type */
	);
}

int Match_c_AUTHENTICATION_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 18) /* message type */
	);
}

int Match_c_CM_SERVICE_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 33) /* message type */
	);
}

int Match_c_CM_SERVICE_PROMPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 37) /* message type */
	);
}

int Match_c_CM_SERVICE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 34) /* message type */
	);
}

int Match_c_ABORT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 41) /* message type */
	);
}

int Match_c_IDENTITY_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 24) /* message type */
	);
}

int Match_c_LOCATION_UPDATING_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 2) /* message type */
	);
}

int Match_c_LOCATION_UPDATING_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 4) /* message type */
	);
}

int Match_c_MM_INFORMATION_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 50) /* message type */
	);
}

int Match_c_TMSI_REALLOCATION_COMMAND_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 26) /* message type */
	);
}

int Match_c_ALERTING_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 1) /* message type */
	);
}

int Match_c_CALL_PROCEEDING_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 2) /* message type */
	);
}

int Match_c_CONGESTION_CONTROL_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 57) /* message type */
	);
}

int Match_c_CONNECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 7) /* message type */
	);
}

int Match_c_DISCONNECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 37) /* message type */
	);
}

int Match_c_FACILITY_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 58) /* message type */
	);
}

int Match_c_HOLD_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 25) /* message type */
	);
}

int Match_c_HOLD_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 26) /* message type */
	);
}

int Match_c_PROGRESS_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 3) /* message type */
	);
}

int Match_c_CC_ESTABLISHMENT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 4) /* message type */
	);
}

int Match_c_RELEASE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 45) /* message type */
	);
}

int Match_c_RECALL_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 11) /* message type */
	);
}

int Match_c_RELEASE_COMPLETE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 42) /* message type */
	);
}

int Match_c_RETRIEVE_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 29) /* message type */
	);
}

int Match_c_RETRIEVE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 30) /* message type */
	);
}

int Match_c_SETUP_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 5) /* message type */
	);
}

int Match_c_START_DTMF_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 54) /* message type */
	);
}

int Match_c_START_DTMF_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 55) /* message type */
	);
}

int Match_c_STOP_DTMF_ACKNOWLEDGE_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 50) /* message type */
	);
}

int Match_c_ATTACH_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 2) /* message type */
	);
}

int Match_c_ATTACH_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 4) /* message type */
	);
}

int Match_c_DETACH_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 5) /* message type */
	);
}

int Match_c_DETACH_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 6) /* message type */
	);
}

int Match_c_P_TMSI_REALLOCATION_COMMAND_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 16) /* message type */
	);
}

int Match_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 18) /* message type */
	);
}

int Match_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 20) /* message type */
	);
}

int Match_c_IDENTITY_REQUEST_B_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 21) /* message type */
	);
}

int Match_c_ROUTING_AREA_UPDATE_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 9) /* message type */
	);
}

int Match_c_ROUTING_AREA_UPDATE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 11) /* message type */
	);
}

int Match_c_GMM_INFORMATION_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 33) /* message type */
	);
}

int Match_c_SERVICE_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 13) /* message type */
	);
}

int Match_c_SERVICE_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 14) /* message type */
	);
}

