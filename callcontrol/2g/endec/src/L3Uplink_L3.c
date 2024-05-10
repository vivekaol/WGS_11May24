/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "L3Uplink_L3.h"
#include "ed_c_known_ie_L3.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_L3.h"
#include "CSN1DataTypes_L3.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_RESPONSE_UP (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 20, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for AuthRespParam */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->AuthRespParam> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->AuthRespParam), 32);
		Len = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1> Error encoding subfield AuthRespParam\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthRespParamExt */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthRespParamExt_Present) {
			/* Append to buffer IEI tag 0x21 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x21), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthRespParamExt> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthRespParamExt->value, 0, Source->AuthRespParamExt->usedBits);
			Len = Source->AuthRespParamExt->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2> Error encoding subfield AuthRespParamExt\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_RESPONSE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_RESPONSE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_RESPONSE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{33, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE AuthRespParam
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 32;
	/* Read value part LOCATOR_16 */
	Destin->AuthRespParam = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16727=EDCore::TDMInteger) */Destin->AuthRespParam___LOCATOR), CurrOfs, 32);
	RetLen = 32;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:3> Error decoding subfield AuthRespParam\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 3, (Destin->AuthRespParam))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:4> Message too short decoding subfield AuthRespParam\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 3, (Destin->AuthRespParam))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthRespParamExt
	------------------------------------------------------*/
	/* Detect IEI tag 0x21 */
	ED_EXPECT_OPTIONAL_IE (0x21,  8, 5, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x21) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 96)) {
			ED_SIGNAL_ERROR ("<ERRID:6> Size error decoding IE AuthRespParamExt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x21, 6, (Destin->AuthRespParamExt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16729=EDCore::TDMBinary) */Destin->AuthRespParamExt___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (Destin->AuthRespParamExt, Len);
		
			if (Destin->AuthRespParamExt->value) {
				EDCopyBits (Destin->AuthRespParamExt->value, 0, Buffer, CurrOfs, Len);
				Destin->AuthRespParamExt->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->AuthRespParamExt->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:7> Error decoding subfield AuthRespParamExt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x21, 7, (Destin->AuthRespParamExt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:8> Message too short decoding subfield AuthRespParamExt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x21, 7, (Destin->AuthRespParamExt))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_FAILURE_UP (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 28, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RejCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RejCause> DOT=<.> */
		Len = ENCODE_c_RejectCause (Buffer, CurrOfs, (&(Source->RejCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:9> Error encoding subfield RejCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthFailureParam */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthFailureParam_Present) {
			/* Append to buffer IEI tag 0x22 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x22), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthFailureParam> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthFailureParam, 0, 112);
			Len = 112;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:10> Error encoding subfield AuthFailureParam\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_FAILURE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_FAILURE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_FAILURE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{34, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:11> Error decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 11, (Destin->RejCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:12> Message too short decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 11, (Destin->RejCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthFailureParam
	------------------------------------------------------*/
	/* Detect IEI tag 0x22 */
	ED_EXPECT_OPTIONAL_IE (0x22,  8, 13, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x22) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 112) {
			ED_SIGNAL_ERROR ("<ERRID:14> Size error decoding IE AuthFailureParam\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x22, 14, (Destin->AuthFailureParam))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->AuthFailureParam, 0, Buffer, CurrOfs, 112);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16734=EDCore::TDMBinary) */Destin->AuthFailureParam___LOCATOR), CurrOfs, 112);
		RetLen = 112;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:15> Error decoding subfield AuthFailureParam\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x22, 15, (Destin->AuthFailureParam))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:16> Message too short decoding subfield AuthFailureParam\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x22, 15, (Destin->AuthFailureParam))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_RE_ESTABLISHMENT_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_CM_RE_ESTABLISHMENT_REQUEST_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 40, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->CiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:17> Error encoding subfield CiphKeySequenceNum\n");
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
			ED_SIGNAL_ERROR ("<ERRID:18> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MobileStationClassmark */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark> DOT=<.> */
		Len = ENCODE_c_MobileStationClassmark2 (Buffer, CurrOfs+8, (&(Source->MobileStationClassmark)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:19> Error encoding subfield MobileStationClassmark\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for MobileId */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileId> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->MobileId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:20> Error encoding subfield MobileId\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for LocationAreaId */
	{
		if (Source->LocationAreaId_Present) {
			/* Append to buffer IEI tag 0x13 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x13), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LocationAreaId> DOT=<->> */
			Len = ENCODE_c_LocationAreaId (Buffer, CurrOfs, Source->LocationAreaId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:21> Error encoding subfield LocationAreaId\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DeviceProperties */
	{
		if (Source->DeviceProperties_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:22> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_RE_ESTABLISHMENT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_RE_ESTABLISHMENT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_RE_ESTABLISHMENT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_RE_ESTABLISHMENT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_RE_ESTABLISHMENT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_CM_RE_ESTABLISHMENT_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_RE_ESTABLISHMENT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_RE_ESTABLISHMENT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_RE_ESTABLISHMENT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{19, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16737=EDCore::TDMInteger) */Destin->CiphKeySequenceNum___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:23> Error decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 23, (Destin->CiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:24> Message too short decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 23, (Destin->CiphKeySequenceNum))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16739=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:25> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 25, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:26> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 25, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 24) {
		ED_SIGNAL_ERROR ("<ERRID:27> Size error decoding IE MobileStationClassmark\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 27, (Destin->MobileStationClassmark))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileStationClassmark2 (Buffer, CurrOfs, (&(Destin->MobileStationClassmark)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:28> Error decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 28, (Destin->MobileStationClassmark))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:29> Message too short decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 28, (Destin->MobileStationClassmark))
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
		ED_SIGNAL_ERROR ("<ERRID:30> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 30, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:31> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 31, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:32> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 31, (Destin->MobileId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE LocationAreaId
	------------------------------------------------------*/
	/* Detect IEI tag 0x13 */
	ED_EXPECT_OPTIONAL_IE (0x13,  8, 33, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x13) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_LocationAreaId (Buffer, CurrOfs, Destin->LocationAreaId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:34> Error decoding subfield LocationAreaId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x13, 34, (Destin->LocationAreaId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:35> Message too short decoding subfield LocationAreaId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x13, 34, (Destin->LocationAreaId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 36, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:37> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 37, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:38> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 37, (Destin->DeviceProperties))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ABORT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CM_SERVICE_ABORT_UP (char* Buffer, ED_EXLONG BitOffset, const c_CM_SERVICE_ABORT_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 35, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ABORT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_ABORT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ABORT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_ABORT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ABORT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_ABORT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_ABORT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_ABORT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ABORT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_ABORT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ABORT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_CM_SERVICE_ABORT_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_ABORT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_ABORT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_ABORT_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CM_SERVICE_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_CM_SERVICE_REQUEST_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 36, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CmServType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CmServType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->CmServType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:39> Error encoding subfield CmServType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for CiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->CiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:40> Error encoding subfield CiphKeySequenceNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MobileStationClassmark */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark> DOT=<.> */
		Len = ENCODE_c_MobileStationClassmark2 (Buffer, CurrOfs+8, (&(Source->MobileStationClassmark)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:41> Error encoding subfield MobileStationClassmark\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for MobileId */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileId> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->MobileId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:42> Error encoding subfield MobileId\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:43> Error encoding subfield Priority\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AdditionalUpdateParameters */
	{
		if (Source->AdditionalUpdateParameters_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalUpdateParameters> DOT=<->> */
			Len = ENCODE_c_AdditionalUpdateParameters (Buffer, CurrOfs, Source->AdditionalUpdateParameters);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:44> Error encoding subfield AdditionalUpdateParameters\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DeviceProperties */
	{
		if (Source->DeviceProperties_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:45> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CM_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CM_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CM_SERVICE_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CM_SERVICE_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CM_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_CM_SERVICE_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CM_SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CM_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CM_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE CmServType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->CmServType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-16751=EDCore::TDMOctet) */Destin->CmServType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:46> Error decoding subfield CmServType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 46, (Destin->CmServType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:47> Message too short decoding subfield CmServType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 46, (Destin->CmServType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE CiphKeySequenceNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->CiphKeySequenceNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16753=EDCore::TDMInteger) */Destin->CiphKeySequenceNum___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:48> Error decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 48, (Destin->CiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:49> Message too short decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 48, (Destin->CiphKeySequenceNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 24) {
		ED_SIGNAL_ERROR ("<ERRID:50> Size error decoding IE MobileStationClassmark\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 50, (Destin->MobileStationClassmark))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileStationClassmark2 (Buffer, CurrOfs, (&(Destin->MobileStationClassmark)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:51> Error decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 51, (Destin->MobileStationClassmark))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:52> Message too short decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 51, (Destin->MobileStationClassmark))
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
		ED_SIGNAL_ERROR ("<ERRID:53> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 53, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:54> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 54, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:55> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 54, (Destin->MobileId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Priority
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 56, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_Priority (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PriorityLevel (Buffer, CurrOfs, Destin->Priority, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:57> Error decoding subfield Priority\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_Priority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 57, (Destin->Priority))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:58> Message too short decoding subfield Priority\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_Priority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 57, (Destin->Priority))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 59, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalUpdateParameters (Buffer, CurrOfs, Destin->AdditionalUpdateParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:60> Error decoding subfield AdditionalUpdateParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 60, (Destin->AdditionalUpdateParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:61> Message too short decoding subfield AdditionalUpdateParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 60, (Destin->AdditionalUpdateParameters))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 62, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:63> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 63, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:64> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CM_SERVICE_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 63, (Destin->DeviceProperties))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IDENTITY_RESPONSE_UP (char* Buffer, ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 25, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for MobileId */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileId> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->MobileId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:65> Error encoding subfield MobileId\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for PTMSI */
	{
		if (Source->PTMSI_Present) {
			/* Append to buffer IEI tag 0x0E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0E), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->PTMSI> DOT=<->> */
			Len = ENCODE_c_PTMSI_Type (Buffer, CurrOfs, Source->PTMSI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:66> Error encoding subfield PTMSI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AdditionalOldRoutingAreaIdent */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalOldRoutingAreaIdent_Present) {
			/* Append to buffer IEI tag 0x1B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalOldRoutingAreaIdent> DOT=<->> */
			Len = ENCODE_c_RoutingAreaIdenti2 (Buffer, CurrOfs+8, Source->AdditionalOldRoutingAreaIdent);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:67> Error encoding subfield AdditionalOldRoutingAreaIdent\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PTmsiSign */
	{
		int TLV_Base = CurrOfs;
		if (Source->PTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->PTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:68> Error encoding subfield PTmsiSign\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_RESPONSE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_RESPONSE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_IDENTITY_RESPONSE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{224, 240, ED_SKIPLIST_OPTIONAL},
		{27, 255, ED_SKIPLIST_OPTIONAL},
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE MobileId
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 72)) {
		ED_SIGNAL_ERROR ("<ERRID:69> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 69, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:70> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 70, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:71> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 70, (Destin->MobileId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PTMSI
	------------------------------------------------------*/
	/* Detect IEI tag 0x0E */
	ED_EXPECT_OPTIONAL_IE (0x0E,  4, 72, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTMSI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PTMSI_Type (Buffer, CurrOfs, Destin->PTMSI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:73> Error decoding subfield PTMSI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTMSI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0E, 73, (Destin->PTMSI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:74> Message too short decoding subfield PTMSI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTMSI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0E, 73, (Destin->PTMSI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalOldRoutingAreaIdent
	------------------------------------------------------*/
	/* Detect IEI tag 0x1B */
	ED_EXPECT_OPTIONAL_IE (0x1B,  8, 75, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 48) {
			ED_SIGNAL_ERROR ("<ERRID:76> Size error decoding IE AdditionalOldRoutingAreaIdent\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1B, 76, (Destin->AdditionalOldRoutingAreaIdent))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RoutingAreaIdenti2 (Buffer, CurrOfs, Destin->AdditionalOldRoutingAreaIdent, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:77> Error decoding subfield AdditionalOldRoutingAreaIdent\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1B, 77, (Destin->AdditionalOldRoutingAreaIdent))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:78> Message too short decoding subfield AdditionalOldRoutingAreaIdent\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1B, 77, (Destin->AdditionalOldRoutingAreaIdent))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 79, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:80> Size error decoding IE PTmsiSign\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x19, 80, (Destin->PTmsiSign))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->PTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16772=EDCore::TDMBinary) */Destin->PTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:81> Error decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 81, (Destin->PTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:82> Message too short decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 81, (Destin->PTmsiSign))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IMSI_DETACH_INDICATION_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IMSI_DETACH_INDICATION_UP (char* Buffer, ED_EXLONG BitOffset, const c_IMSI_DETACH_INDICATION_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for MobileStationClassmark */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark> DOT=<.> */
		Len = ENCODE_c_MobileStationClassmark1 (Buffer, CurrOfs, (&(Source->MobileStationClassmark)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:83> Error encoding subfield MobileStationClassmark\n");
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
			ED_SIGNAL_ERROR ("<ERRID:84> Error encoding subfield MobileId\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IMSI_DETACH_INDICATION_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IMSI_DETACH_INDICATION_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IMSI_DETACH_INDICATION_UP* ED_CONST Source))
{
	return L3_ENCODE_c_IMSI_DETACH_INDICATION_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IMSI_DETACH_INDICATION_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IMSI_DETACH_INDICATION_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IMSI_DETACH_INDICATION_UP* ED_CONST Source))
{
	return L3_ENCODE_c_IMSI_DETACH_INDICATION_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IMSI_DETACH_INDICATION_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IMSI_DETACH_INDICATION_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IMSI_DETACH_INDICATION_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_IMSI_DETACH_INDICATION_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IMSI_DETACH_INDICATION_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IMSI_DETACH_INDICATION_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IMSI_DETACH_INDICATION_UP* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE MobileStationClassmark
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileStationClassmark1 (Buffer, CurrOfs, (&(Destin->MobileStationClassmark)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:85> Error decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 85, (Destin->MobileStationClassmark))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:86> Message too short decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 85, (Destin->MobileStationClassmark))
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
		ED_SIGNAL_ERROR ("<ERRID:87> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 87, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:88> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 88, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:89> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 88, (Destin->MobileId))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_LOCATION_UPDATING_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REQUEST_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for LocationUpdatingType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LocationUpdatingType> DOT=<.> */
		Len = ENCODE_c_LocationUpdatingType (Buffer, (CurrOfs+4), (&(Source->LocationUpdatingType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:90> Error encoding subfield LocationUpdatingType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for CiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->CiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:91> Error encoding subfield CiphKeySequenceNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for LocationAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LocationAreaId> DOT=<.> */
		Len = ENCODE_c_LocationAreaId (Buffer, CurrOfs, (&(Source->LocationAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:92> Error encoding subfield LocationAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MobileStationClassmark */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark> DOT=<.> */
		Len = ENCODE_c_MobileStationClassmark1 (Buffer, CurrOfs, (&(Source->MobileStationClassmark)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:93> Error encoding subfield MobileStationClassmark\n");
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
			ED_SIGNAL_ERROR ("<ERRID:94> Error encoding subfield MobileId\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for MobileStationClassmarkForUmts */
	{
		int TLV_Base = CurrOfs;
		if (Source->MobileStationClassmarkForUmts_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmarkForUmts> DOT=<->> */
			Len = ENCODE_c_MobileStationClassmark2 (Buffer, CurrOfs+8, Source->MobileStationClassmarkForUmts);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:95> Error encoding subfield MobileStationClassmarkForUmts\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalUpdateParameters */
	{
		if (Source->AdditionalUpdateParameters_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalUpdateParameters> DOT=<->> */
			Len = ENCODE_c_AdditionalUpdateParameters (Buffer, CurrOfs, Source->AdditionalUpdateParameters);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:96> Error encoding subfield AdditionalUpdateParameters\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_LOCATION_UPDATING_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_LOCATION_UPDATING_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_LOCATION_UPDATING_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_LOCATION_UPDATING_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_LOCATION_UPDATING_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_LOCATION_UPDATING_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE LOCATION_UPDATING_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_LOCATION_UPDATING_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_LOCATION_UPDATING_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE LocationUpdatingType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LocationUpdatingType (Buffer, (CurrOfs+4), (&(Destin->LocationUpdatingType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:97> Error decoding subfield LocationUpdatingType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 97, (Destin->LocationUpdatingType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:98> Message too short decoding subfield LocationUpdatingType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 97, (Destin->LocationUpdatingType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE CiphKeySequenceNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->CiphKeySequenceNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16782=EDCore::TDMInteger) */Destin->CiphKeySequenceNum___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:99> Error decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 99, (Destin->CiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:100> Message too short decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 99, (Destin->CiphKeySequenceNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE LocationAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 40;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LocationAreaId (Buffer, CurrOfs, (&(Destin->LocationAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:101> Error decoding subfield LocationAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 101, (Destin->LocationAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:102> Message too short decoding subfield LocationAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 101, (Destin->LocationAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileStationClassmark1 (Buffer, CurrOfs, (&(Destin->MobileStationClassmark)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:103> Error decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 103, (Destin->MobileStationClassmark))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:104> Message too short decoding subfield MobileStationClassmark\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 103, (Destin->MobileStationClassmark))
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
		ED_SIGNAL_ERROR ("<ERRID:105> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 105, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:106> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 106, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:107> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 106, (Destin->MobileId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmarkForUmts
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 108, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:109> Size error decoding IE MobileStationClassmarkForUmts\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 109, (Destin->MobileStationClassmarkForUmts))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileStationClassmark2 (Buffer, CurrOfs, Destin->MobileStationClassmarkForUmts, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:110> Error decoding subfield MobileStationClassmarkForUmts\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 110, (Destin->MobileStationClassmarkForUmts))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:111> Message too short decoding subfield MobileStationClassmarkForUmts\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 110, (Destin->MobileStationClassmarkForUmts))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 112, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalUpdateParameters (Buffer, CurrOfs, Destin->AdditionalUpdateParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:113> Error decoding subfield AdditionalUpdateParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 113, (Destin->AdditionalUpdateParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:114> Message too short decoding subfield AdditionalUpdateParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 113, (Destin->AdditionalUpdateParameters))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_STATUS
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MM_STATUS (char* Buffer, ED_EXLONG BitOffset, const c_MM_STATUS* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 49, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RejCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RejCause> DOT=<.> */
		Len = ENCODE_c_RejectCause (Buffer, CurrOfs, (&(Source->RejCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:115> Error encoding subfield RejCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_MM_STATUS (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_MM_STATUS (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_STATUS* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_MM_STATUS (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_STATUS* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:116> Error decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 116, (Destin->RejCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:117> Message too short decoding subfield RejCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 116, (Destin->RejCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMPLETE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_TMSI_REALLOCATION_COMPLETE_UP (char* Buffer, ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMPLETE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 27, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_TMSI_REALLOCATION_COMPLETE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_TMSI_REALLOCATION_COMPLETE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_TMSI_REALLOCATION_COMPLETE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_NULL_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MM_NULL_UP (char* Buffer, ED_EXLONG BitOffset, const c_MM_NULL_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 48, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_NULL_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MM_NULL_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_NULL_UP* ED_CONST Source))
{
	return L3_ENCODE_c_MM_NULL_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MM_NULL_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MM_NULL_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MM_NULL_UP* ED_CONST Source))
{
	return L3_ENCODE_c_MM_NULL_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MM_NULL_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MM_NULL_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_NULL_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_MM_NULL_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MM_NULL_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MM_NULL_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MM_NULL_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ALERTING_UP (char* Buffer, ED_EXLONG BitOffset, const c_ALERTING_UP* Source, int Mode)
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
				ED_SIGNAL_ERROR ("<ERRID:118> Error encoding subfield Facility\n");
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
				ED_SIGNAL_ERROR ("<ERRID:119> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:120> Error encoding subfield SsVer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ALERTING_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ALERTING_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ALERTING_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ALERTING_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ALERTING_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ALERTING_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_ALERTING_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ALERTING_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ALERTING_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ALERTING_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{127, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 121, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:122> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 122, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16804=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ALERTING_UP_Facility (Destin->Facility, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:123> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 123, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:124> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 123, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 125, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:126> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 126, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16806=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ALERTING_UP_UserUser (Destin->UserUser, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:127> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 127, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:128> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 127, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 129, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:130> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 130, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16808=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ALERTING_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:131> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 131, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:132> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ALERTING_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 131, (Destin->SsVer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CALL_CONFIRMED_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CALL_CONFIRMED_UP (char* Buffer, ED_EXLONG BitOffset, const c_CALL_CONFIRMED_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
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
				ED_SIGNAL_ERROR ("<ERRID:133> Error encoding subfield RepeatInd\n");
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
				ED_SIGNAL_ERROR ("<ERRID:134> Error encoding subfield BearerCpblty1\n");
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
				ED_SIGNAL_ERROR ("<ERRID:135> Error encoding subfield BearerCpblty2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
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
				ED_SIGNAL_ERROR ("<ERRID:136> Error encoding subfield Cause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for CcCapabil */
	{
		int TLV_Base = CurrOfs;
		if (Source->CcCapabil_Present) {
			/* Append to buffer IEI tag 0x15 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x15), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CcCapabil> DOT=<->> */
			Len = ENCODE_c_CallControlCapabil (Buffer, CurrOfs+8, Source->CcCapabil);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:137> Error encoding subfield CcCapabil\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for StreamId */
	{
		int TLV_Base = CurrOfs;
		if (Source->StreamId_Present) {
			/* Append to buffer IEI tag 0x2D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->StreamId> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->StreamId), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:138> Error encoding subfield StreamId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SupportedCodecs */
	{
		int TLV_Base = CurrOfs;
		if (Source->SupportedCodecs_Present) {
			/* Append to buffer IEI tag 0x40 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x40), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SupportedCodecs> DOT=<->> */
			Len = ENCODE_c_SupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:139> Error encoding subfield SupportedCodecs\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CALL_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CALL_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_CONFIRMED_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CALL_CONFIRMED_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CALL_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CALL_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CALL_CONFIRMED_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CALL_CONFIRMED_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CALL_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CALL_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CALL_CONFIRMED_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CALL_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CALL_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CALL_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{8, 255, ED_SKIPLIST_OPTIONAL},
		{21, 255, ED_SKIPLIST_OPTIONAL},
		{45, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 140, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_RepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16815=EDCore::TDMInteger) */Destin->RepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:141> Error decoding subfield RepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_RepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 141, (Destin->RepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:142> Message too short decoding subfield RepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_RepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 141, (Destin->RepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty1
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 143, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:144> Size error decoding IE BearerCpblty1\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 144, (Destin->BearerCpblty1))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty1, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:145> Error decoding subfield BearerCpblty1\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 145, (Destin->BearerCpblty1))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:146> Message too short decoding subfield BearerCpblty1\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 145, (Destin->BearerCpblty1))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty2
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 147, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:148> Size error decoding IE BearerCpblty2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 148, (Destin->BearerCpblty2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:149> Error decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 149, (Destin->BearerCpblty2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:150> Message too short decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 149, (Destin->BearerCpblty2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 151, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:152> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 152, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:153> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 153, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:154> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 153, (Destin->Cause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CcCapabil
	------------------------------------------------------*/
	/* Detect IEI tag 0x15 */
	ED_EXPECT_OPTIONAL_IE (0x15,  8, 155, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x15) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:156> Size error decoding IE CcCapabil\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x15, 156, (Destin->CcCapabil))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CallControlCapabil (Buffer, CurrOfs, Destin->CcCapabil, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:157> Error decoding subfield CcCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x15, 157, (Destin->CcCapabil))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:158> Message too short decoding subfield CcCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x15, 157, (Destin->CcCapabil))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE StreamId
	------------------------------------------------------*/
	/* Detect IEI tag 0x2D */
	ED_EXPECT_OPTIONAL_IE (0x2D,  8, 159, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_StreamId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:160> Size error decoding IE StreamId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2D, 160, (Destin->StreamId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->StreamId = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16825=EDCore::TDMInteger) */Destin->StreamId___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:161> Error decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2D, 161, (Destin->StreamId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:162> Message too short decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2D, 161, (Destin->StreamId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 163, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:164> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 164, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:165> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 165, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:166> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 165, (Destin->SupportedCodecs))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CONNECT_UP (char* Buffer, ED_EXLONG BitOffset, const c_CONNECT_UP* Source, int Mode)
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
				ED_SIGNAL_ERROR ("<ERRID:167> Error encoding subfield Facility\n");
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
				ED_SIGNAL_ERROR ("<ERRID:168> Error encoding subfield ConnSubaddr\n");
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
				ED_SIGNAL_ERROR ("<ERRID:169> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:170> Error encoding subfield SsVer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for StreamId */
	{
		int TLV_Base = CurrOfs;
		if (Source->StreamId_Present) {
			/* Append to buffer IEI tag 0x2D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->StreamId> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->StreamId), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:171> Error encoding subfield StreamId\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CONNECT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CONNECT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CONNECT_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{77, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{127, 255, ED_SKIPLIST_OPTIONAL},
		{45, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 172, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:173> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 173, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16834=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CONNECT_UP_Facility (Destin->Facility, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:174> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 174, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:175> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 174, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ConnSubaddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x4D */
	ED_EXPECT_OPTIONAL_IE (0x4D,  8, 176, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x4D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_ConnSubaddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:177> Size error decoding IE ConnSubaddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_ConnSubaddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4D, 177, (Destin->ConnSubaddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ConnSubaddres (Buffer, CurrOfs, Destin->ConnSubaddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:178> Error decoding subfield ConnSubaddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_ConnSubaddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4D, 178, (Destin->ConnSubaddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:179> Message too short decoding subfield ConnSubaddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_ConnSubaddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4D, 178, (Destin->ConnSubaddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 180, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:181> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 181, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16838=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CONNECT_UP_UserUser (Destin->UserUser, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:182> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 182, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:183> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 182, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 184, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:185> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 185, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16840=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CONNECT_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:186> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 186, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:187> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 186, (Destin->SsVer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE StreamId
	------------------------------------------------------*/
	/* Detect IEI tag 0x2D */
	ED_EXPECT_OPTIONAL_IE (0x2D,  8, 188, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_StreamId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:189> Size error decoding IE StreamId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2D, 189, (Destin->StreamId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->StreamId = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16842=EDCore::TDMInteger) */Destin->StreamId___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:190> Error decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2D, 190, (Destin->StreamId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:191> Message too short decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONNECT_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2D, 190, (Destin->StreamId))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_ACKNOWLEDGE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CONNECT_ACKNOWLEDGE (char* Buffer, ED_EXLONG BitOffset, const c_CONNECT_ACKNOWLEDGE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 15, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_ACKNOWLEDGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONNECT_ACKNOWLEDGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_ACKNOWLEDGE* ED_CONST Source))
{
	return L3_ENCODE_c_CONNECT_ACKNOWLEDGE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_ACKNOWLEDGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONNECT_ACKNOWLEDGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONNECT_ACKNOWLEDGE* ED_CONST Source))
{
	return L3_ENCODE_c_CONNECT_ACKNOWLEDGE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_ACKNOWLEDGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONNECT_ACKNOWLEDGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_ACKNOWLEDGE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CONNECT_ACKNOWLEDGE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONNECT_ACKNOWLEDGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONNECT_ACKNOWLEDGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONNECT_ACKNOWLEDGE* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DISCONNECT_UP (char* Buffer, ED_EXLONG BitOffset, const c_DISCONNECT_UP* Source, int Mode)
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
			ED_SIGNAL_ERROR ("<ERRID:192> Error encoding subfield Cause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:193> Error encoding subfield Facility\n");
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
				ED_SIGNAL_ERROR ("<ERRID:194> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:195> Error encoding subfield SsVer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DISCONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_DISCONNECT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DISCONNECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DISCONNECT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_DISCONNECT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DISCONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_DISCONNECT_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DISCONNECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DISCONNECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DISCONNECT_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{127, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:196> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 196, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:197> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 197, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:198> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 197, (Destin->Cause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 199, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:200> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 200, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16856=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DISCONNECT_UP_Facility (Destin->Facility, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:201> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 201, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:202> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 201, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 203, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:204> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 204, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16858=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DISCONNECT_UP_UserUser (Destin->UserUser, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:205> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 205, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:206> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 205, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 207, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:208> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 208, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16860=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DISCONNECT_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:209> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 209, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:210> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DISCONNECT_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 209, (Destin->SsVer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EMERGENCY_SETUP_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EMERGENCY_SETUP_UP (char* Buffer, ED_EXLONG BitOffset, const c_EMERGENCY_SETUP_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 14, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for BearerCpblty */
	{
		int TLV_Base = CurrOfs;
		if (Source->BearerCpblty_Present) {
			/* Append to buffer IEI tag 0x04 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty> DOT=<->> */
			Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, Source->BearerCpblty);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:211> Error encoding subfield BearerCpblty\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for StreamId */
	{
		int TLV_Base = CurrOfs;
		if (Source->StreamId_Present) {
			/* Append to buffer IEI tag 0x2D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->StreamId> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->StreamId), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:212> Error encoding subfield StreamId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SupportedCodecs */
	{
		int TLV_Base = CurrOfs;
		if (Source->SupportedCodecs_Present) {
			/* Append to buffer IEI tag 0x40 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x40), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SupportedCodecs> DOT=<->> */
			Len = ENCODE_c_SupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:213> Error encoding subfield SupportedCodecs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EmergencyCategory */
	{
		int TLV_Base = CurrOfs;
		if (Source->EmergencyCategory_Present) {
			/* Append to buffer IEI tag 0x2E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EmergencyCategory> DOT=<->> */
			Len = ENCODE_c_ServCategory (Buffer, CurrOfs+8, Source->EmergencyCategory);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:214> Error encoding subfield EmergencyCategory\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EMERGENCY_SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EMERGENCY_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMERGENCY_SETUP_UP* ED_CONST Source))
{
	return L3_ENCODE_c_EMERGENCY_SETUP_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EMERGENCY_SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EMERGENCY_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMERGENCY_SETUP_UP* ED_CONST Source))
{
	return L3_ENCODE_c_EMERGENCY_SETUP_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EMERGENCY_SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EMERGENCY_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMERGENCY_SETUP_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_EMERGENCY_SETUP_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EMERGENCY_SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EMERGENCY_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMERGENCY_SETUP_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{45, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
		{46, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 215, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 56)) {
			ED_SIGNAL_ERROR ("<ERRID:216> Size error decoding IE BearerCpblty\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 216, (Destin->BearerCpblty))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:217> Error decoding subfield BearerCpblty\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 217, (Destin->BearerCpblty))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:218> Message too short decoding subfield BearerCpblty\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 217, (Destin->BearerCpblty))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE StreamId
	------------------------------------------------------*/
	/* Detect IEI tag 0x2D */
	ED_EXPECT_OPTIONAL_IE (0x2D,  8, 219, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_StreamId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:220> Size error decoding IE StreamId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2D, 220, (Destin->StreamId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->StreamId = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16869=EDCore::TDMInteger) */Destin->StreamId___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:221> Error decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2D, 221, (Destin->StreamId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:222> Message too short decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2D, 221, (Destin->StreamId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 223, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:224> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 224, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:225> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 225, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:226> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 225, (Destin->SupportedCodecs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EmergencyCategory
	------------------------------------------------------*/
	/* Detect IEI tag 0x2E */
	ED_EXPECT_OPTIONAL_IE (0x2E,  8, 227, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:228> Size error decoding IE EmergencyCategory\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2E, 228, (Destin->EmergencyCategory))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ServCategory (Buffer, CurrOfs, Destin->EmergencyCategory, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:229> Error decoding subfield EmergencyCategory\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2E, 229, (Destin->EmergencyCategory))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:230> Message too short decoding subfield EmergencyCategory\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2E, 229, (Destin->EmergencyCategory))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_FACILITY_UP (char* Buffer, ED_EXLONG BitOffset, const c_FACILITY_UP* Source, int Mode)
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
			ED_SIGNAL_ERROR ("<ERRID:231> Error encoding subfield Facility\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:232> Error encoding subfield SsVer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_FACILITY_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_UP* ED_CONST Source))
{
	return L3_ENCODE_c_FACILITY_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_FACILITY_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_FACILITY_UP* ED_CONST Source))
{
	return L3_ENCODE_c_FACILITY_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_FACILITY_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_FACILITY_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE FACILITY_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_FACILITY_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_FACILITY_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{127, 255, ED_SKIPLIST_OPTIONAL},
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
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 4792) {
		ED_SIGNAL_ERROR ("<ERRID:233> Size error decoding IE Facility\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 233, (Destin->Facility))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16880=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_FACILITY_UP_Facility (&(Destin->Facility), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:234> Error decoding subfield Facility\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 234, (Destin->Facility))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:235> Message too short decoding subfield Facility\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 234, (Destin->Facility))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 236, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_FACILITY_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:237> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_FACILITY_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 237, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16882=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_FACILITY_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:238> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_FACILITY_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 238, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:239> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_FACILITY_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 238, (Destin->SsVer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_HOLD_UP (char* Buffer, ED_EXLONG BitOffset, const c_HOLD_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 24, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_HOLD_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_UP* ED_CONST Source))
{
	return L3_ENCODE_c_HOLD_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE HOLD_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_HOLD_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_HOLD_UP* ED_CONST Source))
{
	return L3_ENCODE_c_HOLD_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE HOLD_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_HOLD_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_HOLD_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE HOLD_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_HOLD_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_HOLD_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 23, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for BearerCpblty */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty> DOT=<.> */
		Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, (&(Source->BearerCpblty)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:240> Error encoding subfield BearerCpblty\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for LowLayerComp */
	{
		int TLV_Base = CurrOfs;
		if (Source->LowLayerComp_Present) {
			/* Append to buffer IEI tag 0x7C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LowLayerComp> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LowLayerComp->value, 0, Source->LowLayerComp->usedBits);
			Len = Source->LowLayerComp->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:241> Error encoding subfield LowLayerComp\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HighLayerComp */
	{
		int TLV_Base = CurrOfs;
		if (Source->HighLayerComp_Present) {
			/* Append to buffer IEI tag 0x7D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HighLayerComp> DOT=<->> */
			Len = ENCODE_c_HighLayerCpbility (Buffer, CurrOfs+8, Source->HighLayerComp);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:242> Error encoding subfield HighLayerComp\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ReverseCallSetupDir */
	{
		if (Source->ReverseCallSetupDir_Present) {
			/* Append to buffer IEI tag 0xA3 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA3), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for ImmediateModifInd */
	{
		if (Source->ImmediateModifInd_Present) {
			/* Append to buffer IEI tag 0xA4 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA4), 8);
			CurrOfs += 8;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_MODIFY (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY* ED_CONST Destin, ED_EXLONG Length))
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
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{163, 255, ED_SKIPLIST_OPTIONAL},
		{164, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 112)) {
		ED_SIGNAL_ERROR ("<ERRID:243> Size error decoding IE BearerCpblty\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 243, (Destin->BearerCpblty))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, (&(Destin->BearerCpblty)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:244> Error decoding subfield BearerCpblty\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 244, (Destin->BearerCpblty))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:245> Message too short decoding subfield BearerCpblty\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 244, (Destin->BearerCpblty))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerComp
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 246, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_LowLayerComp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:247> Size error decoding IE LowLayerComp\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 247, (Destin->LowLayerComp))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16896=EDCore::TDMBinary) */Destin->LowLayerComp___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_LowLayerComp (Destin->LowLayerComp, Len);
		
			if (Destin->LowLayerComp->value) {
				EDCopyBits (Destin->LowLayerComp->value, 0, Buffer, CurrOfs, Len);
				Destin->LowLayerComp->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LowLayerComp->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:248> Error decoding subfield LowLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 248, (Destin->LowLayerComp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:249> Message too short decoding subfield LowLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 248, (Destin->LowLayerComp))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerComp
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 250, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_HighLayerComp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:251> Size error decoding IE HighLayerComp\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 251, (Destin->HighLayerComp))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerComp, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:252> Error decoding subfield HighLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 252, (Destin->HighLayerComp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:253> Message too short decoding subfield HighLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 252, (Destin->HighLayerComp))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReverseCallSetupDir
	------------------------------------------------------*/
	/* Detect IEI tag 0xA3 */
	ED_EXPECT_OPTIONAL_IE (0xA3,  8, 254, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA3) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_ReverseCallSetupDir (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ImmediateModifInd
	------------------------------------------------------*/
	/* Detect IEI tag 0xA4 */
	ED_EXPECT_OPTIONAL_IE (0xA4,  8, 257, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA4) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_ImmediateModifInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_COMPLETE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_COMPLETE (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_COMPLETE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 31, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for BearerCpblty */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty> DOT=<.> */
		Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, (&(Source->BearerCpblty)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:260> Error encoding subfield BearerCpblty\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for LowLayerComp */
	{
		int TLV_Base = CurrOfs;
		if (Source->LowLayerComp_Present) {
			/* Append to buffer IEI tag 0x7C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LowLayerComp> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LowLayerComp->value, 0, Source->LowLayerComp->usedBits);
			Len = Source->LowLayerComp->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:261> Error encoding subfield LowLayerComp\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HighLayerComp */
	{
		int TLV_Base = CurrOfs;
		if (Source->HighLayerComp_Present) {
			/* Append to buffer IEI tag 0x7D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HighLayerComp> DOT=<->> */
			Len = ENCODE_c_HighLayerCpbility (Buffer, CurrOfs+8, Source->HighLayerComp);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:262> Error encoding subfield HighLayerComp\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ReverseCallSetupDir */
	{
		if (Source->ReverseCallSetupDir_Present) {
			/* Append to buffer IEI tag 0xA3 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA3), 8);
			CurrOfs += 8;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_COMPLETE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_COMPLETE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_MODIFY_COMPLETE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
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
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{163, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 112)) {
		ED_SIGNAL_ERROR ("<ERRID:263> Size error decoding IE BearerCpblty\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 263, (Destin->BearerCpblty))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, (&(Destin->BearerCpblty)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:264> Error decoding subfield BearerCpblty\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 264, (Destin->BearerCpblty))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:265> Message too short decoding subfield BearerCpblty\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 264, (Destin->BearerCpblty))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerComp
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 266, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_LowLayerComp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:267> Size error decoding IE LowLayerComp\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 267, (Destin->LowLayerComp))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16911=EDCore::TDMBinary) */Destin->LowLayerComp___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_COMPLETE_LowLayerComp (Destin->LowLayerComp, Len);
		
			if (Destin->LowLayerComp->value) {
				EDCopyBits (Destin->LowLayerComp->value, 0, Buffer, CurrOfs, Len);
				Destin->LowLayerComp->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LowLayerComp->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:268> Error decoding subfield LowLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 268, (Destin->LowLayerComp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:269> Message too short decoding subfield LowLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 268, (Destin->LowLayerComp))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerComp
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 270, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_HighLayerComp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:271> Size error decoding IE HighLayerComp\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 271, (Destin->HighLayerComp))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerComp, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:272> Error decoding subfield HighLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 272, (Destin->HighLayerComp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:273> Message too short decoding subfield HighLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 272, (Destin->HighLayerComp))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReverseCallSetupDir
	------------------------------------------------------*/
	/* Detect IEI tag 0xA3 */
	ED_EXPECT_OPTIONAL_IE (0xA3,  8, 274, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA3) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_COMPLETE_ReverseCallSetupDir (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_REJECT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 19, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for BearerCpblty */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty> DOT=<.> */
		Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, (&(Source->BearerCpblty)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:277> Error encoding subfield BearerCpblty\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<.> */
		Len = ENCODE_c_Cause (Buffer, CurrOfs+8, (&(Source->Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:278> Error encoding subfield Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for LowLayerComp */
	{
		int TLV_Base = CurrOfs;
		if (Source->LowLayerComp_Present) {
			/* Append to buffer IEI tag 0x7C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LowLayerComp> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LowLayerComp->value, 0, Source->LowLayerComp->usedBits);
			Len = Source->LowLayerComp->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:279> Error encoding subfield LowLayerComp\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HighLayerComp */
	{
		int TLV_Base = CurrOfs;
		if (Source->HighLayerComp_Present) {
			/* Append to buffer IEI tag 0x7D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HighLayerComp> DOT=<->> */
			Len = ENCODE_c_HighLayerCpbility (Buffer, CurrOfs+8, Source->HighLayerComp);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:280> Error encoding subfield HighLayerComp\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_MODIFY_REJECT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 112)) {
		ED_SIGNAL_ERROR ("<ERRID:281> Size error decoding IE BearerCpblty\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 281, (Destin->BearerCpblty))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, (&(Destin->BearerCpblty)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:282> Error decoding subfield BearerCpblty\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 282, (Destin->BearerCpblty))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:283> Message too short decoding subfield BearerCpblty\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 282, (Destin->BearerCpblty))
	} 
#endif
	
	
	
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
		ED_SIGNAL_ERROR ("<ERRID:284> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 284, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:285> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 285, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:286> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 285, (Destin->Cause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerComp
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 287, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_LowLayerComp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:288> Size error decoding IE LowLayerComp\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 288, (Destin->LowLayerComp))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16926=EDCore::TDMBinary) */Destin->LowLayerComp___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_REJECT_LowLayerComp (Destin->LowLayerComp, Len);
		
			if (Destin->LowLayerComp->value) {
				EDCopyBits (Destin->LowLayerComp->value, 0, Buffer, CurrOfs, Len);
				Destin->LowLayerComp->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LowLayerComp->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:289> Error decoding subfield LowLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 289, (Destin->LowLayerComp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:290> Message too short decoding subfield LowLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_LowLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 289, (Destin->LowLayerComp))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerComp
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 291, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_HighLayerComp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:292> Size error decoding IE HighLayerComp\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 292, (Destin->HighLayerComp))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerComp, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:293> Error decoding subfield HighLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 293, (Destin->HighLayerComp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:294> Message too short decoding subfield HighLayerComp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_REJECT_HighLayerComp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 293, (Destin->HighLayerComp))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE NOTIFY
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_NOTIFY (char* Buffer, ED_EXLONG BitOffset, const c_NOTIFY* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 62, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NotifInd */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NotifInd> DOT=<.> */
		Len = ENCODE_c_NotifInd (Buffer, CurrOfs, (&(Source->NotifInd)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:295> Error encoding subfield NotifInd\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE NOTIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NOTIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFY* ED_CONST Source))
{
	return L3_ENCODE_c_NOTIFY (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE NOTIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_NOTIFY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFY* ED_CONST Source))
{
	return L3_ENCODE_c_NOTIFY (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE NOTIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NOTIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFY* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_NOTIFY (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE NOTIFY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_NOTIFY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFY* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE NotifInd
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NotifInd (Buffer, CurrOfs, (&(Destin->NotifInd)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:296> Error decoding subfield NotifInd\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 296, (Destin->NotifInd))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:297> Message too short decoding subfield NotifInd\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 296, (Destin->NotifInd))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_CONFIRMED_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (char* Buffer, ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_CONFIRMED_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 6, 8);
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
				ED_SIGNAL_ERROR ("<ERRID:298> Error encoding subfield RepeatInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for BearerCpblty1 */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer IEI tag 0x04 */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
		CurrOfs += 8;TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty1> DOT=<.> */
		Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, (&(Source->BearerCpblty1)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:299> Error encoding subfield BearerCpblty1\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:300> Error encoding subfield BearerCpblty2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
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
				ED_SIGNAL_ERROR ("<ERRID:301> Error encoding subfield Cause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SupportedCodecs */
	{
		int TLV_Base = CurrOfs;
		if (Source->SupportedCodecs_Present) {
			/* Append to buffer IEI tag 0x40 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x40), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SupportedCodecs> DOT=<->> */
			Len = ENCODE_c_SupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:302> Error encoding subfield SupportedCodecs\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CC_ESTABLISHMENT_CONFIRMED_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Source))
{
	return L3_ENCODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CC_ESTABLISHMENT_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_CC_ESTABLISHMENT_CONFIRMED_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CC_ESTABLISHMENT_CONFIRMED_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CC_ESTABLISHMENT_CONFIRMED_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CC_ESTABLISHMENT_CONFIRMED_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{4, 255, ED_SKIPLIST_MANDATORY},
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{8, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 303, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16942=EDCore::TDMInteger) */Destin->RepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:304> Error decoding subfield RepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 304, (Destin->RepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:305> Message too short decoding subfield RepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 304, (Destin->RepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty1
	------------------------------------------------------*/
	
	/* This is a mandatory field! Signal error if not found. */
	ED_EXPECT_MANDATORY_IE (0x04,  8, 306, KnownL3IEs_L3)
	CurrOfs += 8;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 112)) {
		ED_SIGNAL_ERROR ("<ERRID:307> Size error decoding IE BearerCpblty1\n");
		ED_HANDLE_IE_SIZE_ERROR (0x04, 307, (Destin->BearerCpblty1))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, (&(Destin->BearerCpblty1)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:308> Error decoding subfield BearerCpblty1\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR (0x04, 308, (Destin->BearerCpblty1))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:309> Message too short decoding subfield BearerCpblty1\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT (0x04, 308, (Destin->BearerCpblty1))
	} 
#endif
	
	
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty2
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 310, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:311> Size error decoding IE BearerCpblty2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 311, (Destin->BearerCpblty2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:312> Error decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 312, (Destin->BearerCpblty2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:313> Message too short decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 312, (Destin->BearerCpblty2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Cause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 314, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:315> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 315, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:316> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 316, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:317> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 316, (Destin->Cause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 318, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:319> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 319, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:320> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 320, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:321> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 320, (Destin->SupportedCodecs))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RELEASE_UP (char* Buffer, ED_EXLONG BitOffset, const c_RELEASE_UP* Source, int Mode)
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
				ED_SIGNAL_ERROR ("<ERRID:322> Error encoding subfield Cause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:323> Error encoding subfield SecondCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:324> Error encoding subfield Facility\n");
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
				ED_SIGNAL_ERROR ("<ERRID:325> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:326> Error encoding subfield SsVer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RELEASE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{127, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 327, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:328> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 328, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:329> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 329, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:330> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 329, (Destin->Cause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SecondCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 331, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SecondCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:332> Size error decoding IE SecondCause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SecondCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 332, (Destin->SecondCause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->SecondCause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:333> Error decoding subfield SecondCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SecondCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 333, (Destin->SecondCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:334> Message too short decoding subfield SecondCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SecondCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 333, (Destin->SecondCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 335, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:336> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 336, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16961=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_UP_Facility (Destin->Facility, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:337> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 337, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:338> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 337, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 339, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:340> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 340, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16963=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_UP_UserUser (Destin->UserUser, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:341> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 341, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:342> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 341, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 343, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:344> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 344, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16965=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:345> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 345, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:346> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 345, (Destin->SsVer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RELEASE_COMPLETE_UP (char* Buffer, ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_UP* Source, int Mode)
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
				ED_SIGNAL_ERROR ("<ERRID:347> Error encoding subfield Cause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:348> Error encoding subfield Facility\n");
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
				ED_SIGNAL_ERROR ("<ERRID:349> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:350> Error encoding subfield SsVer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RELEASE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_COMPLETE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RELEASE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RELEASE_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_RELEASE_COMPLETE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RELEASE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RELEASE_COMPLETE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RELEASE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RELEASE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RELEASE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{127, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x08,  8, 351, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Cause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 240)) {
			ED_SIGNAL_ERROR ("<ERRID:352> Size error decoding IE Cause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x08, 352, (Destin->Cause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Cause (Buffer, CurrOfs, Destin->Cause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:353> Error decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 353, (Destin->Cause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:354> Message too short decoding subfield Cause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Cause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 353, (Destin->Cause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Facility
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 355, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Facility (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:356> Size error decoding IE Facility\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 356, (Destin->Facility))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16974=EDCore::TDMBinary) */Destin->Facility___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_COMPLETE_UP_Facility (Destin->Facility, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:357> Error decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 357, (Destin->Facility))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:358> Message too short decoding subfield Facility\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_Facility (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 357, (Destin->Facility))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 359, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1032)) {
			ED_SIGNAL_ERROR ("<ERRID:360> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 360, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16976=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_COMPLETE_UP_UserUser (Destin->UserUser, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:361> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 361, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:362> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 361, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 363, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:364> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 364, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16978=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_RELEASE_COMPLETE_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:365> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 365, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:366> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RELEASE_COMPLETE_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 365, (Destin->SsVer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RETRIEVE_UP (char* Buffer, ED_EXLONG BitOffset, const c_RETRIEVE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 28, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RETRIEVE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_RETRIEVE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RETRIEVE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RETRIEVE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_RETRIEVE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RETRIEVE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_RETRIEVE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RETRIEVE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RETRIEVE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RETRIEVE_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SETUP_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SETUP_UP (char* Buffer, ED_EXLONG BitOffset, const c_SETUP_UP* Source, int Mode)
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
				ED_SIGNAL_ERROR ("<ERRID:367> Error encoding subfield BcRepeatInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for BearerCpblty1 */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer IEI tag 0x04 */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x04), 8);
		CurrOfs += 8;TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->BearerCpblty1> DOT=<.> */
		Len = ENCODE_c_BearerCpblty (Buffer, CurrOfs+8, (&(Source->BearerCpblty1)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:368> Error encoding subfield BearerCpblty1\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:369> Error encoding subfield BearerCpblty2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for FacilitySimpleRecallAlignment */
	{
		int TLV_Base = CurrOfs;
		if (Source->FacilitySimpleRecallAlignment_Present) {
			/* Append to buffer IEI tag 0x1C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1C), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->FacilitySimpleRecallAlignment> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->FacilitySimpleRecallAlignment->value, 0, Source->FacilitySimpleRecallAlignment->usedBits);
			Len = Source->FacilitySimpleRecallAlignment->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:370> Error encoding subfield FacilitySimpleRecallAlignment\n");
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
				ED_SIGNAL_ERROR ("<ERRID:371> Error encoding subfield CallingPartySubAddr\n");
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
		/* Append to buffer IEI tag 0x5E */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5E), 8);
		CurrOfs += 8;TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->CalledPartyBcdNum> DOT=<.> */
		Len = ENCODE_c_CalledPartyBcdNum (Buffer, CurrOfs+8, (&(Source->CalledPartyBcdNum)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:372> Error encoding subfield CalledPartyBcdNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:373> Error encoding subfield CalledPartySubAddr\n");
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
				ED_SIGNAL_ERROR ("<ERRID:374> Error encoding subfield LlcRepeatInd\n");
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
				ED_SIGNAL_ERROR ("<ERRID:375> Error encoding subfield LowLayerCpbilityI\n");
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
				ED_SIGNAL_ERROR ("<ERRID:376> Error encoding subfield LowLayerCpbilityIi\n");
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
				ED_SIGNAL_ERROR ("<ERRID:377> Error encoding subfield HlcRepeatInd\n");
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
				ED_SIGNAL_ERROR ("<ERRID:378> Error encoding subfield HighLayerCpbilityI\n");
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
				ED_SIGNAL_ERROR ("<ERRID:379> Error encoding subfield HighLayerCpbilityIi\n");
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
				ED_SIGNAL_ERROR ("<ERRID:380> Error encoding subfield UserUser\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SsVer */
	{
		int TLV_Base = CurrOfs;
		if (Source->SsVer_Present) {
			/* Append to buffer IEI tag 0x7F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SsVer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->SsVer->value, 0, Source->SsVer->usedBits);
			Len = Source->SsVer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:381> Error encoding subfield SsVer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ClirSuppression */
	{
		if (Source->ClirSuppression_Present) {
			/* Append to buffer IEI tag 0xA1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA1), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for ClirInvocation */
	{
		if (Source->ClirInvocation_Present) {
			/* Append to buffer IEI tag 0xA2 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA2), 8);
			CurrOfs += 8;
		}
	}
	
	/* Code for CcCapabil */
	{
		int TLV_Base = CurrOfs;
		if (Source->CcCapabil_Present) {
			/* Append to buffer IEI tag 0x15 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x15), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CcCapabil> DOT=<->> */
			Len = ENCODE_c_CallControlCapabil (Buffer, CurrOfs+8, Source->CcCapabil);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:382> Error encoding subfield CcCapabil\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for FacilityCcbsAdvancedRecallAlignment */
	{
		int TLV_Base = CurrOfs;
		if (Source->FacilityCcbsAdvancedRecallAlignment_Present) {
			/* Append to buffer IEI tag 0x1D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->FacilityCcbsAdvancedRecallAlignment> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->FacilityCcbsAdvancedRecallAlignment->value, 0, Source->FacilityCcbsAdvancedRecallAlignment->usedBits);
			Len = Source->FacilityCcbsAdvancedRecallAlignment->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:383> Error encoding subfield FacilityCcbsAdvancedRecallAlignment\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for FacilityRecallAlignmentNotEssentialCcbs */
	{
		int TLV_Base = CurrOfs;
		if (Source->FacilityRecallAlignmentNotEssentialCcbs_Present) {
			/* Append to buffer IEI tag 0x1B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->FacilityRecallAlignmentNotEssentialCcbs> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->FacilityRecallAlignmentNotEssentialCcbs->value, 0, Source->FacilityRecallAlignmentNotEssentialCcbs->usedBits);
			Len = Source->FacilityRecallAlignmentNotEssentialCcbs->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:384> Error encoding subfield FacilityRecallAlignmentNotEssentialCcbs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for StreamId */
	{
		int TLV_Base = CurrOfs;
		if (Source->StreamId_Present) {
			/* Append to buffer IEI tag 0x2D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->StreamId> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->StreamId), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:385> Error encoding subfield StreamId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SupportedCodecs */
	{
		int TLV_Base = CurrOfs;
		if (Source->SupportedCodecs_Present) {
			/* Append to buffer IEI tag 0x40 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x40), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SupportedCodecs> DOT=<->> */
			Len = ENCODE_c_SupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:386> Error encoding subfield SupportedCodecs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for Redial */
	{
		if (Source->Redial_Present) {
			/* Append to buffer IEI tag 0xA3 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA3), 8);
			CurrOfs += 8;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_UP* ED_CONST Source))
{
	return L3_ENCODE_c_SETUP_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SETUP_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SETUP_UP* ED_CONST Source))
{
	return L3_ENCODE_c_SETUP_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_SETUP_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SETUP_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SETUP_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SETUP_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{4, 255, ED_SKIPLIST_MANDATORY},
		{4, 255, ED_SKIPLIST_OPTIONAL},
		{28, 255, ED_SKIPLIST_OPTIONAL},
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_MANDATORY},
		{109, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{124, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{125, 255, ED_SKIPLIST_OPTIONAL},
		{126, 255, ED_SKIPLIST_OPTIONAL},
		{127, 255, ED_SKIPLIST_OPTIONAL},
		{161, 255, ED_SKIPLIST_OPTIONAL},
		{162, 255, ED_SKIPLIST_OPTIONAL},
		{21, 255, ED_SKIPLIST_OPTIONAL},
		{29, 255, ED_SKIPLIST_OPTIONAL},
		{27, 255, ED_SKIPLIST_OPTIONAL},
		{45, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
		{163, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 387, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BcRepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->BcRepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-16990=EDCore::TDMInteger) */Destin->BcRepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:388> Error decoding subfield BcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 388, (Destin->BcRepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:389> Message too short decoding subfield BcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 388, (Destin->BcRepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty1
	------------------------------------------------------*/
	
	/* This is a mandatory field! Signal error if not found. */
	ED_EXPECT_MANDATORY_IE (0x04,  8, 390, KnownL3IEs_L3)
	CurrOfs += 8;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 112)) {
		ED_SIGNAL_ERROR ("<ERRID:391> Size error decoding IE BearerCpblty1\n");
		ED_HANDLE_IE_SIZE_ERROR (0x04, 391, (Destin->BearerCpblty1))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, (&(Destin->BearerCpblty1)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:392> Error decoding subfield BearerCpblty1\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR (0x04, 392, (Destin->BearerCpblty1))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:393> Message too short decoding subfield BearerCpblty1\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT (0x04, 392, (Destin->BearerCpblty1))
	} 
#endif
	
	
	
	
	/*----------------------------------------------------- 
		Code for IE BearerCpblty2
	------------------------------------------------------*/
	/* Detect IEI tag 0x04 */
	ED_EXPECT_OPTIONAL_IE (0x04,  8, 394, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x04) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BearerCpblty2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 112)) {
			ED_SIGNAL_ERROR ("<ERRID:395> Size error decoding IE BearerCpblty2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x04, 395, (Destin->BearerCpblty2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_BearerCpblty (Buffer, CurrOfs, Destin->BearerCpblty2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:396> Error decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x04, 396, (Destin->BearerCpblty2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:397> Message too short decoding subfield BearerCpblty2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_BearerCpblty2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x04, 396, (Destin->BearerCpblty2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE FacilitySimpleRecallAlignment
	------------------------------------------------------*/
	/* Detect IEI tag 0x1C */
	ED_EXPECT_OPTIONAL_IE (0x1C,  8, 398, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:399> Size error decoding IE FacilitySimpleRecallAlignment\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1C, 399, (Destin->FacilitySimpleRecallAlignment))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-16996=EDCore::TDMBinary) */Destin->FacilitySimpleRecallAlignment___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_FacilitySimpleRecallAlignment (Destin->FacilitySimpleRecallAlignment, Len);
		
			if (Destin->FacilitySimpleRecallAlignment->value) {
				EDCopyBits (Destin->FacilitySimpleRecallAlignment->value, 0, Buffer, CurrOfs, Len);
				Destin->FacilitySimpleRecallAlignment->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->FacilitySimpleRecallAlignment->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:400> Error decoding subfield FacilitySimpleRecallAlignment\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1C, 400, (Destin->FacilitySimpleRecallAlignment))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:401> Message too short decoding subfield FacilitySimpleRecallAlignment\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1C, 400, (Destin->FacilitySimpleRecallAlignment))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CallingPartySubAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 402, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CallingPartySubAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:403> Size error decoding IE CallingPartySubAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CallingPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 403, (Destin->CallingPartySubAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CallingPartySubaddr (Buffer, CurrOfs, Destin->CallingPartySubAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:404> Error decoding subfield CallingPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CallingPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 404, (Destin->CallingPartySubAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:405> Message too short decoding subfield CallingPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CallingPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 404, (Destin->CallingPartySubAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CalledPartyBcdNum
	------------------------------------------------------*/
	
	/* This is a mandatory field! Signal error if not found. */
	ED_EXPECT_MANDATORY_IE (0x5E,  8, 406, KnownL3IEs_L3)
	CurrOfs += 8;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 328)) {
		ED_SIGNAL_ERROR ("<ERRID:407> Size error decoding IE CalledPartyBcdNum\n");
		ED_HANDLE_IE_SIZE_ERROR (0x5E, 407, (Destin->CalledPartyBcdNum))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_CalledPartyBcdNum (Buffer, CurrOfs, (&(Destin->CalledPartyBcdNum)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:408> Error decoding subfield CalledPartyBcdNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR (0x5E, 408, (Destin->CalledPartyBcdNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:409> Message too short decoding subfield CalledPartyBcdNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT (0x5E, 408, (Destin->CalledPartyBcdNum))
	} 
#endif
	
	
	
	
	/*----------------------------------------------------- 
		Code for IE CalledPartySubAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x6D */
	ED_EXPECT_OPTIONAL_IE (0x6D,  8, 410, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CalledPartySubAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 168) {
			ED_SIGNAL_ERROR ("<ERRID:411> Size error decoding IE CalledPartySubAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CalledPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6D, 411, (Destin->CalledPartySubAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CalledPartySubaddr (Buffer, CurrOfs, Destin->CalledPartySubAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:412> Error decoding subfield CalledPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CalledPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6D, 412, (Destin->CalledPartySubAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:413> Message too short decoding subfield CalledPartySubAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CalledPartySubAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6D, 412, (Destin->CalledPartySubAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LlcRepeatInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 414, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LlcRepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->LlcRepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17004=EDCore::TDMInteger) */Destin->LlcRepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:415> Error decoding subfield LlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 415, (Destin->LlcRepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:416> Message too short decoding subfield LlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 415, (Destin->LlcRepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerCpbilityI
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 417, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:418> Size error decoding IE LowLayerCpbilityI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 418, (Destin->LowLayerCpbilityI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17006=EDCore::TDMBinary) */Destin->LowLayerCpbilityI___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_LowLayerCpbilityI (Destin->LowLayerCpbilityI, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:419> Error decoding subfield LowLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 419, (Destin->LowLayerCpbilityI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:420> Message too short decoding subfield LowLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 419, (Destin->LowLayerCpbilityI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LowLayerCpbilityIi
	------------------------------------------------------*/
	/* Detect IEI tag 0x7C */
	ED_EXPECT_OPTIONAL_IE (0x7C,  8, 421, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityIi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:422> Size error decoding IE LowLayerCpbilityIi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7C, 422, (Destin->LowLayerCpbilityIi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17008=EDCore::TDMBinary) */Destin->LowLayerCpbilityIi___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_LowLayerCpbilityIi (Destin->LowLayerCpbilityIi, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:423> Error decoding subfield LowLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7C, 423, (Destin->LowLayerCpbilityIi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:424> Message too short decoding subfield LowLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_LowLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7C, 423, (Destin->LowLayerCpbilityIi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HlcRepeatInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 425, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HlcRepeatInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->HlcRepeatInd = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17010=EDCore::TDMInteger) */Destin->HlcRepeatInd___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:426> Error decoding subfield HlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 426, (Destin->HlcRepeatInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:427> Message too short decoding subfield HlcRepeatInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HlcRepeatInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 426, (Destin->HlcRepeatInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerCpbilityI
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 428, 11, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:429> Size error decoding IE HighLayerCpbilityI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 429, (Destin->HighLayerCpbilityI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerCpbilityI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:430> Error decoding subfield HighLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 430, (Destin->HighLayerCpbilityI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:431> Message too short decoding subfield HighLayerCpbilityI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 430, (Destin->HighLayerCpbilityI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HighLayerCpbilityIi
	------------------------------------------------------*/
	/* Detect IEI tag 0x7D */
	ED_EXPECT_OPTIONAL_IE (0x7D,  8, 432, 12, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityIi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 24) {
			ED_SIGNAL_ERROR ("<ERRID:433> Size error decoding IE HighLayerCpbilityIi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7D, 433, (Destin->HighLayerCpbilityIi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HighLayerCpbility (Buffer, CurrOfs, Destin->HighLayerCpbilityIi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:434> Error decoding subfield HighLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7D, 434, (Destin->HighLayerCpbilityIi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:435> Message too short decoding subfield HighLayerCpbilityIi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_HighLayerCpbilityIi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7D, 434, (Destin->HighLayerCpbilityIi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	/* Detect IEI tag 0x7E */
	ED_EXPECT_OPTIONAL_IE (0x7E,  8, 436, 13, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_UserUser (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 264)) {
			ED_SIGNAL_ERROR ("<ERRID:437> Size error decoding IE UserUser\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7E, 437, (Destin->UserUser))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17016=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_UserUser (Destin->UserUser, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:438> Error decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7E, 438, (Destin->UserUser))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:439> Message too short decoding subfield UserUser\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_UserUser (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7E, 438, (Destin->UserUser))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SsVer
	------------------------------------------------------*/
	/* Detect IEI tag 0x7F */
	ED_EXPECT_OPTIONAL_IE (0x7F,  8, 440, 14, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x7F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SsVer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 8) {
			ED_SIGNAL_ERROR ("<ERRID:441> Size error decoding IE SsVer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7F, 441, (Destin->SsVer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17018=EDCore::TDMBinary) */Destin->SsVer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_SsVer (Destin->SsVer, Len);
		
			if (Destin->SsVer->value) {
				EDCopyBits (Destin->SsVer->value, 0, Buffer, CurrOfs, Len);
				Destin->SsVer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->SsVer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:442> Error decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7F, 442, (Destin->SsVer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:443> Message too short decoding subfield SsVer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SsVer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7F, 442, (Destin->SsVer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ClirSuppression
	------------------------------------------------------*/
	/* Detect IEI tag 0xA1 */
	ED_EXPECT_OPTIONAL_IE (0xA1,  8, 444, 15, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA1) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_ClirSuppression (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ClirInvocation
	------------------------------------------------------*/
	/* Detect IEI tag 0xA2 */
	ED_EXPECT_OPTIONAL_IE (0xA2,  8, 447, 16, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA2) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_ClirInvocation (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE CcCapabil
	------------------------------------------------------*/
	/* Detect IEI tag 0x15 */
	ED_EXPECT_OPTIONAL_IE (0x15,  8, 450, 17, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x15) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CcCapabil (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:451> Size error decoding IE CcCapabil\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x15, 451, (Destin->CcCapabil))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CallControlCapabil (Buffer, CurrOfs, Destin->CcCapabil, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:452> Error decoding subfield CcCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x15, 452, (Destin->CcCapabil))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:453> Message too short decoding subfield CcCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x15, 452, (Destin->CcCapabil))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE FacilityCcbsAdvancedRecallAlignment
	------------------------------------------------------*/
	/* Detect IEI tag 0x1D */
	ED_EXPECT_OPTIONAL_IE (0x1D,  8, 454, 18, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:455> Size error decoding IE FacilityCcbsAdvancedRecallAlignment\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1D, 455, (Destin->FacilityCcbsAdvancedRecallAlignment))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17026=EDCore::TDMBinary) */Destin->FacilityCcbsAdvancedRecallAlignment___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (Destin->FacilityCcbsAdvancedRecallAlignment, Len);
		
			if (Destin->FacilityCcbsAdvancedRecallAlignment->value) {
				EDCopyBits (Destin->FacilityCcbsAdvancedRecallAlignment->value, 0, Buffer, CurrOfs, Len);
				Destin->FacilityCcbsAdvancedRecallAlignment->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->FacilityCcbsAdvancedRecallAlignment->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:456> Error decoding subfield FacilityCcbsAdvancedRecallAlignment\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1D, 456, (Destin->FacilityCcbsAdvancedRecallAlignment))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:457> Message too short decoding subfield FacilityCcbsAdvancedRecallAlignment\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1D, 456, (Destin->FacilityCcbsAdvancedRecallAlignment))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE FacilityRecallAlignmentNotEssentialCcbs
	------------------------------------------------------*/
	/* Detect IEI tag 0x1B */
	ED_EXPECT_OPTIONAL_IE (0x1B,  8, 458, 19, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 4784) {
			ED_SIGNAL_ERROR ("<ERRID:459> Size error decoding IE FacilityRecallAlignmentNotEssentialCcbs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1B, 459, (Destin->FacilityRecallAlignmentNotEssentialCcbs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17028=EDCore::TDMBinary) */Destin->FacilityRecallAlignmentNotEssentialCcbs___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (Destin->FacilityRecallAlignmentNotEssentialCcbs, Len);
		
			if (Destin->FacilityRecallAlignmentNotEssentialCcbs->value) {
				EDCopyBits (Destin->FacilityRecallAlignmentNotEssentialCcbs->value, 0, Buffer, CurrOfs, Len);
				Destin->FacilityRecallAlignmentNotEssentialCcbs->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->FacilityRecallAlignmentNotEssentialCcbs->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:460> Error decoding subfield FacilityRecallAlignmentNotEssentialCcbs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1B, 460, (Destin->FacilityRecallAlignmentNotEssentialCcbs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:461> Message too short decoding subfield FacilityRecallAlignmentNotEssentialCcbs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1B, 460, (Destin->FacilityRecallAlignmentNotEssentialCcbs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE StreamId
	------------------------------------------------------*/
	/* Detect IEI tag 0x2D */
	ED_EXPECT_OPTIONAL_IE (0x2D,  8, 462, 20, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_StreamId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:463> Size error decoding IE StreamId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2D, 463, (Destin->StreamId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->StreamId = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17030=EDCore::TDMInteger) */Destin->StreamId___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:464> Error decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2D, 464, (Destin->StreamId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:465> Message too short decoding subfield StreamId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_StreamId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2D, 464, (Destin->StreamId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 466, 21, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:467> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 467, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:468> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 468, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:469> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SETUP_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 468, (Destin->SupportedCodecs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Redial
	------------------------------------------------------*/
	/* Detect IEI tag 0xA3 */
	ED_EXPECT_OPTIONAL_IE (0xA3,  8, 470, 22, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA3) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SETUP_UP_Redial (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_CC_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_START_CC_UP (char* Buffer, ED_EXLONG BitOffset, const c_START_CC_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 9, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CcCapabil */
	{
		int TLV_Base = CurrOfs;
		if (Source->CcCapabil_Present) {
			/* Append to buffer IEI tag 0x15 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x15), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CcCapabil> DOT=<->> */
			Len = ENCODE_c_CallControlCapabil (Buffer, CurrOfs+8, Source->CcCapabil);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:473> Error encoding subfield CcCapabil\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_CC_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_CC_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_CC_UP* ED_CONST Source))
{
	return L3_ENCODE_c_START_CC_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE START_CC_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_CC_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_CC_UP* ED_CONST Source))
{
	return L3_ENCODE_c_START_CC_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_CC_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_CC_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_CC_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_START_CC_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_CC_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_CC_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_CC_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{21, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE CcCapabil
	------------------------------------------------------*/
	/* Detect IEI tag 0x15 */
	ED_EXPECT_OPTIONAL_IE (0x15,  8, 474, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x15) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_START_CC_UP_CcCapabil (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:475> Size error decoding IE CcCapabil\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_START_CC_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x15, 475, (Destin->CcCapabil))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_CallControlCapabil (Buffer, CurrOfs, Destin->CcCapabil, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:476> Error decoding subfield CcCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_START_CC_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x15, 476, (Destin->CcCapabil))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:477> Message too short decoding subfield CcCapabil\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_START_CC_UP_CcCapabil (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x15, 476, (Destin->CcCapabil))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_START_DTMF_UP (char* Buffer, ED_EXLONG BitOffset, const c_START_DTMF_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 53, 8);
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
			ED_SIGNAL_ERROR ("<ERRID:478> Error encoding subfield KeypadFacility\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_START_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_UP* ED_CONST Source))
{
	return L3_ENCODE_c_START_DTMF_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_START_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_START_DTMF_UP* ED_CONST Source))
{
	return L3_ENCODE_c_START_DTMF_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_START_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_START_DTMF_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE START_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_START_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_START_DTMF_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ED_EXPECT_MANDATORY_IE (0x2C,  8, 479, KnownL3IEs_L3)
	CurrOfs += 8;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_KeypadFacility (Buffer, CurrOfs, (&(Destin->KeypadFacility)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:480> Error decoding subfield KeypadFacility\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR (0x2C, 480, (Destin->KeypadFacility))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:481> Message too short decoding subfield KeypadFacility\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT (0x2C, 480, (Destin->KeypadFacility))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STATUS
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_STATUS (char* Buffer, ED_EXLONG BitOffset, const c_STATUS* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 61, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->Cause> DOT=<.> */
		Len = ENCODE_c_Cause (Buffer, CurrOfs+8, (&(Source->Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:482> Error encoding subfield Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for CallState */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CallState> DOT=<.> */
		Len = ENCODE_c_CallState (Buffer, CurrOfs, (&(Source->CallState)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:483> Error encoding subfield CallState\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuxiliaryStates */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuxiliaryStates_Present) {
			/* Append to buffer IEI tag 0x24 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x24), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuxiliaryStates> DOT=<->> */
			Len = ENCODE_c_AuxiliaryStates (Buffer, CurrOfs+8, Source->AuxiliaryStates);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:484> Error encoding subfield AuxiliaryStates\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_STATUS (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_STATUS (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_STATUS (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS* ED_CONST Destin, ED_EXLONG Length))
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
		{36, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:485> Size error decoding IE Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 485, (Destin->Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_Cause (Buffer, CurrOfs, (&(Destin->Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:486> Error decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 486, (Destin->Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:487> Message too short decoding subfield Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 486, (Destin->Cause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE CallState
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_CallState (Buffer, CurrOfs, (&(Destin->CallState)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:488> Error decoding subfield CallState\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 488, (Destin->CallState))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:489> Message too short decoding subfield CallState\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 488, (Destin->CallState))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuxiliaryStates
	------------------------------------------------------*/
	/* Detect IEI tag 0x24 */
	ED_EXPECT_OPTIONAL_IE (0x24,  8, 490, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x24) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_STATUS_AuxiliaryStates (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:491> Size error decoding IE AuxiliaryStates\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_STATUS_AuxiliaryStates (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x24, 491, (Destin->AuxiliaryStates))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AuxiliaryStates (Buffer, CurrOfs, Destin->AuxiliaryStates, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:492> Error decoding subfield AuxiliaryStates\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_STATUS_AuxiliaryStates (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x24, 492, (Destin->AuxiliaryStates))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:493> Message too short decoding subfield AuxiliaryStates\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_STATUS_AuxiliaryStates (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x24, 492, (Destin->AuxiliaryStates))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STATUS_ENQUIRY
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_STATUS_ENQUIRY (char* Buffer, ED_EXLONG BitOffset, const c_STATUS_ENQUIRY* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 52, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STATUS_ENQUIRY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STATUS_ENQUIRY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS_ENQUIRY* ED_CONST Source))
{
	return L3_ENCODE_c_STATUS_ENQUIRY (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE STATUS_ENQUIRY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STATUS_ENQUIRY (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STATUS_ENQUIRY* ED_CONST Source))
{
	return L3_ENCODE_c_STATUS_ENQUIRY (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STATUS_ENQUIRY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STATUS_ENQUIRY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS_ENQUIRY* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_STATUS_ENQUIRY (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STATUS_ENQUIRY
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STATUS_ENQUIRY (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STATUS_ENQUIRY* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_STOP_DTMF_UP (char* Buffer, ED_EXLONG BitOffset, const c_STOP_DTMF_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 49, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_STOP_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_UP* ED_CONST Source))
{
	return L3_ENCODE_c_STOP_DTMF_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_STOP_DTMF_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_STOP_DTMF_UP* ED_CONST Source))
{
	return L3_ENCODE_c_STOP_DTMF_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_STOP_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_STOP_DTMF_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE STOP_DTMF_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_STOP_DTMF_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_STOP_DTMF_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE USER_INFORMATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_USER_INFORMATION (char* Buffer, ED_EXLONG BitOffset, const c_USER_INFORMATION* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 16, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for UserUser */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->UserUser> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, Source->UserUser.value, 0, Source->UserUser.usedBits);
		Len = Source->UserUser.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:494> Error encoding subfield UserUser\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for MoreData */
	{
		if (Source->MoreData_Present) {
			/* Append to buffer IEI tag 0xA0 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0xA0), 8);
			CurrOfs += 8;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE USER_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_USER_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_USER_INFORMATION* ED_CONST Source))
{
	return L3_ENCODE_c_USER_INFORMATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE USER_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_USER_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_USER_INFORMATION* ED_CONST Source))
{
	return L3_ENCODE_c_USER_INFORMATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE USER_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_USER_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_USER_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
	
	Len = DECODE_BODY_c_USER_INFORMATION (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE USER_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_USER_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_USER_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
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
		{160, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE UserUser
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 1040)) {
		ED_SIGNAL_ERROR ("<ERRID:495> Size error decoding IE UserUser\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 495, (Destin->UserUser))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17076=EDCore::TDMBinary) */Destin->UserUser___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_USER_INFORMATION_UserUser (&(Destin->UserUser), Len);
	
		if (Destin->UserUser.value) {
			EDCopyBits (Destin->UserUser.value, 0, Buffer, CurrOfs, Len);
			Destin->UserUser.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->UserUser.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:496> Error decoding subfield UserUser\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 496, (Destin->UserUser))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:497> Message too short decoding subfield UserUser\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 496, (Destin->UserUser))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MoreData
	------------------------------------------------------*/
	/* Detect IEI tag 0xA0 */
	ED_EXPECT_OPTIONAL_IE (0xA0,  8, 498, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0xA0) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_USER_INFORMATION_MoreData (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 0;
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_REQUEST_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for MsNetwkCpblty */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MsNetwkCpblty> DOT=<.> */
		Len = ENCODE_c_MsNetwkCpblty (Buffer, CurrOfs+8, (&(Source->MsNetwkCpblty)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:501> Error encoding subfield MsNetwkCpblty\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for AttachType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->AttachType> DOT=<.> */
		Len = ENCODE_c_AttachType (Buffer, (CurrOfs+4), (&(Source->AttachType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:502> Error encoding subfield AttachType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for GprsCiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GprsCiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->GprsCiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:503> Error encoding subfield GprsCiphKeySequenceNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for DrxParam */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->DrxParam> DOT=<.> */
		Len = ENCODE_c_DrxParam (Buffer, CurrOfs, (&(Source->DrxParam)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:504> Error encoding subfield DrxParam\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MobileIdentity */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileIdentity> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->MobileIdentity)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:505> Error encoding subfield MobileIdentity\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for OldRoutingAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->OldRoutingAreaId> DOT=<.> */
		Len = ENCODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Source->OldRoutingAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:506> Error encoding subfield OldRoutingAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MsRadioAccessCpblty */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MsRadioAccessCpblty> DOT=<.> */
		Len = ENCODE_c_MsRadioAccessCpblty (Buffer, CurrOfs+8, (&(Source->MsRadioAccessCpblty)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:507> Error encoding subfield MsRadioAccessCpblty\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for OldPTmsiSign */
	{
		if (Source->OldPTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->OldPTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->OldPTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:508> Error encoding subfield OldPTmsiSign\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ReqRdyTimerValue */
	{
		if (Source->ReqRdyTimerValue_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->ReqRdyTimerValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer (Buffer, CurrOfs, Source->ReqRdyTimerValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:509> Error encoding subfield ReqRdyTimerValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for TmsiStatus */
	{
		if (Source->TmsiStatus_Present) {
			/* Append to buffer IEI tag 0x09 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x09), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->TmsiStatus> DOT=<->> */
			Len = ENCODE_c_TmsiStatus (Buffer, CurrOfs, Source->TmsiStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:510> Error encoding subfield TmsiStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PSLCSCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->PSLCSCapability_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PSLCSCapability> DOT=<->> */
			Len = ENCODE_c_PSLCSCapabilit (Buffer, CurrOfs+8, Source->PSLCSCapability);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:511> Error encoding subfield PSLCSCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MobileStationClassmark2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->MobileStationClassmark2_Present) {
			/* Append to buffer IEI tag 0x11 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x11), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark2> DOT=<->> */
			Len = ENCODE_c_MobileStationClassmark2 (Buffer, CurrOfs+8, Source->MobileStationClassmark2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:512> Error encoding subfield MobileStationClassmark2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MobileStationClassmark3 */
	{
		int TLV_Base = CurrOfs;
		if (Source->MobileStationClassmark3_Present) {
			/* Append to buffer IEI tag 0x20 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x20), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark3> DOT=<->> */
			Len = ENCODE_c_Classmark3Value (Buffer, CurrOfs+8, Source->MobileStationClassmark3);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:513> Error encoding subfield MobileStationClassmark3\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SupportedCodecs */
	{
		int TLV_Base = CurrOfs;
		if (Source->SupportedCodecs_Present) {
			/* Append to buffer IEI tag 0x40 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x40), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SupportedCodecs> DOT=<->> */
			Len = ENCODE_c_SupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:514> Error encoding subfield SupportedCodecs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UENetworkCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->UENetworkCapability_Present) {
			/* Append to buffer IEI tag 0x58 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x58), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UENetworkCapability> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UENetworkCapability->value, 0, Source->UENetworkCapability->usedBits);
			Len = Source->UENetworkCapability->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:515> Error encoding subfield UENetworkCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalMobileIdentity */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalMobileIdentity_Present) {
			/* Append to buffer IEI tag 0x1A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalMobileIdentity> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->AdditionalMobileIdentity);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:516> Error encoding subfield AdditionalMobileIdentity\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalOldRoutingAreaId */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalOldRoutingAreaId_Present) {
			/* Append to buffer IEI tag 0x1B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalOldRoutingAreaId> DOT=<->> */
			Len = ENCODE_c_RoutingAreaIdenti2 (Buffer, CurrOfs+8, Source->AdditionalOldRoutingAreaId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:517> Error encoding subfield AdditionalOldRoutingAreaId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for VoiceDomainPrefUEUsageSetting */
	{
		int TLV_Base = CurrOfs;
		if (Source->VoiceDomainPrefUEUsageSetting_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->VoiceDomainPrefUEUsageSetting> DOT=<->> */
			Len = ENCODE_c_VoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs+8, Source->VoiceDomainPrefUEUsageSetting);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:518> Error encoding subfield VoiceDomainPrefUEUsageSetting\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for DeviceProperties */
	{
		if (Source->DeviceProperties_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:519> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PTMSI */
	{
		if (Source->PTMSI_Present) {
			/* Append to buffer IEI tag 0x0E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0E), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->PTMSI> DOT=<->> */
			Len = ENCODE_c_PTMSI_Type (Buffer, CurrOfs, Source->PTMSI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:520> Error encoding subfield PTMSI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for MSNetworkFeatureSupport */
	{
		if (Source->MSNetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->MSNetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_MSNetworkFeatureSupport (Buffer, CurrOfs, Source->MSNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:521> Error encoding subfield MSNetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for OldLocationAreaIdentification */
	{
		int TLV_Base = CurrOfs;
		if (Source->OldLocationAreaIdentification_Present) {
			/* Append to buffer IEI tag 0x14 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x14), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->OldLocationAreaIdentification> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->OldLocationAreaIdentification, 0, 40);
			Len = 40;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:522> Error encoding subfield OldLocationAreaIdentification\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalUpdateType */
	{
		if (Source->AdditionalUpdateType_Present) {
			/* Append to buffer IEI tag 0x0F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0F), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalUpdateType> DOT=<->> */
			Len = ENCODE_c_AdditionalUpdateType (Buffer, CurrOfs, Source->AdditionalUpdateType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:523> Error encoding subfield AdditionalUpdateType\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for TMSIBasedNRIContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->TMSIBasedNRIContainer_Present) {
			/* Append to buffer IEI tag 0x10 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x10), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TMSIBasedNRIContainer> DOT=<->> */
			Len = ENCODE_c_NetworkResourceIdContainer (Buffer, CurrOfs+8, Source->TMSIBasedNRIContainer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:524> Error encoding subfield TMSIBasedNRIContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:525> Error encoding subfield T3324Value\n");
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
				ED_SIGNAL_ERROR ("<ERRID:526> Error encoding subfield T3312ExtendedValue\n");
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
				ED_SIGNAL_ERROR ("<ERRID:527> Error encoding subfield ExtendedDRXParameters\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ATTACH_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{0, 0, ED_SKIPLIST_MANDATORY}, /* Untagged item, matches all! */
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{144, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{17, 255, ED_SKIPLIST_OPTIONAL},
		{32, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
		{88, 255, ED_SKIPLIST_OPTIONAL},
		{26, 255, ED_SKIPLIST_OPTIONAL},
		{27, 255, ED_SKIPLIST_OPTIONAL},
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{224, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{20, 255, ED_SKIPLIST_OPTIONAL},
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{16, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{57, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE MsNetwkCpblty
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 64)) {
		ED_SIGNAL_ERROR ("<ERRID:528> Size error decoding IE MsNetwkCpblty\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 528, (Destin->MsNetwkCpblty))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MsNetwkCpblty (Buffer, CurrOfs, (&(Destin->MsNetwkCpblty)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:529> Error decoding subfield MsNetwkCpblty\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 529, (Destin->MsNetwkCpblty))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:530> Message too short decoding subfield MsNetwkCpblty\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 529, (Destin->MsNetwkCpblty))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AttachType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_AttachType (Buffer, (CurrOfs+4), (&(Destin->AttachType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:531> Error decoding subfield AttachType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 531, (Destin->AttachType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:532> Message too short decoding subfield AttachType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 531, (Destin->AttachType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE GprsCiphKeySequenceNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->GprsCiphKeySequenceNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17085=EDCore::TDMInteger) */Destin->GprsCiphKeySequenceNum___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:533> Error decoding subfield GprsCiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 533, (Destin->GprsCiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:534> Message too short decoding subfield GprsCiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 533, (Destin->GprsCiphKeySequenceNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE DrxParam
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 16;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_DrxParam (Buffer, CurrOfs, (&(Destin->DrxParam)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:535> Error decoding subfield DrxParam\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 535, (Destin->DrxParam))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:536> Message too short decoding subfield DrxParam\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 535, (Destin->DrxParam))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MobileIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 40) || (Len > 64)) {
		ED_SIGNAL_ERROR ("<ERRID:537> Size error decoding IE MobileIdentity\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 537, (Destin->MobileIdentity))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileIdentity)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:538> Error decoding subfield MobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 538, (Destin->MobileIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:539> Message too short decoding subfield MobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 538, (Destin->MobileIdentity))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OldRoutingAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 48;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Destin->OldRoutingAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:540> Error decoding subfield OldRoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 540, (Destin->OldRoutingAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:541> Message too short decoding subfield OldRoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 540, (Destin->OldRoutingAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MsRadioAccessCpblty
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 40) || (Len > 400)) {
		ED_SIGNAL_ERROR ("<ERRID:542> Size error decoding IE MsRadioAccessCpblty\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 542, (Destin->MsRadioAccessCpblty))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MsRadioAccessCpblty (Buffer, CurrOfs, (&(Destin->MsRadioAccessCpblty)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:543> Error decoding subfield MsRadioAccessCpblty\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 543, (Destin->MsRadioAccessCpblty))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:544> Message too short decoding subfield MsRadioAccessCpblty\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 543, (Destin->MsRadioAccessCpblty))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OldPTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 545, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldPTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->OldPTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17095=EDCore::TDMBinary) */Destin->OldPTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:546> Error decoding subfield OldPTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldPTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 546, (Destin->OldPTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:547> Message too short decoding subfield OldPTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldPTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 546, (Destin->OldPTmsiSign))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReqRdyTimerValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 548, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ReqRdyTimerValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer (Buffer, CurrOfs, Destin->ReqRdyTimerValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:549> Error decoding subfield ReqRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ReqRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 549, (Destin->ReqRdyTimerValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:550> Message too short decoding subfield ReqRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ReqRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 549, (Destin->ReqRdyTimerValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TmsiStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x09 */
	ED_EXPECT_OPTIONAL_IE (0x09,  4, 551, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x09) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TmsiStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TmsiStatus (Buffer, CurrOfs, Destin->TmsiStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:552> Error decoding subfield TmsiStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TmsiStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x09, 552, (Destin->TmsiStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:553> Message too short decoding subfield TmsiStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TmsiStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x09, 552, (Destin->TmsiStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PSLCSCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 554, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:555> Size error decoding IE PSLCSCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 555, (Destin->PSLCSCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PSLCSCapabilit (Buffer, CurrOfs, Destin->PSLCSCapability, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:556> Error decoding subfield PSLCSCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 556, (Destin->PSLCSCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:557> Message too short decoding subfield PSLCSCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 556, (Destin->PSLCSCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark2
	------------------------------------------------------*/
	/* Detect IEI tag 0x11 */
	ED_EXPECT_OPTIONAL_IE (0x11,  8, 558, 11, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x11) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:559> Size error decoding IE MobileStationClassmark2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x11, 559, (Destin->MobileStationClassmark2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileStationClassmark2 (Buffer, CurrOfs, Destin->MobileStationClassmark2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:560> Error decoding subfield MobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x11, 560, (Destin->MobileStationClassmark2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:561> Message too short decoding subfield MobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x11, 560, (Destin->MobileStationClassmark2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark3
	------------------------------------------------------*/
	/* Detect IEI tag 0x20 */
	ED_EXPECT_OPTIONAL_IE (0x20,  8, 562, 12, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x20) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 256) {
			ED_SIGNAL_ERROR ("<ERRID:563> Size error decoding IE MobileStationClassmark3\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x20, 563, (Destin->MobileStationClassmark3))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Classmark3Value (Buffer, CurrOfs, Destin->MobileStationClassmark3, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:564> Error decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x20, 564, (Destin->MobileStationClassmark3))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:565> Message too short decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x20, 564, (Destin->MobileStationClassmark3))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 566, 13, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:567> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 567, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:568> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 568, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:569> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 568, (Destin->SupportedCodecs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UENetworkCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x58 */
	ED_EXPECT_OPTIONAL_IE (0x58,  8, 570, 14, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x58) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 104)) {
			ED_SIGNAL_ERROR ("<ERRID:571> Size error decoding IE UENetworkCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x58, 571, (Destin->UENetworkCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17109=EDCore::TDMBinary) */Destin->UENetworkCapability___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ATTACH_REQUEST_UP_UENetworkCapability (Destin->UENetworkCapability, Len);
		
			if (Destin->UENetworkCapability->value) {
				EDCopyBits (Destin->UENetworkCapability->value, 0, Buffer, CurrOfs, Len);
				Destin->UENetworkCapability->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UENetworkCapability->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:572> Error decoding subfield UENetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x58, 572, (Destin->UENetworkCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:573> Message too short decoding subfield UENetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x58, 572, (Destin->UENetworkCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalMobileIdentity
	------------------------------------------------------*/
	/* Detect IEI tag 0x1A */
	ED_EXPECT_OPTIONAL_IE (0x1A,  8, 574, 15, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:575> Size error decoding IE AdditionalMobileIdentity\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1A, 575, (Destin->AdditionalMobileIdentity))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->AdditionalMobileIdentity, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:576> Error decoding subfield AdditionalMobileIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1A, 576, (Destin->AdditionalMobileIdentity))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:577> Message too short decoding subfield AdditionalMobileIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1A, 576, (Destin->AdditionalMobileIdentity))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalOldRoutingAreaId
	------------------------------------------------------*/
	/* Detect IEI tag 0x1B */
	ED_EXPECT_OPTIONAL_IE (0x1B,  8, 578, 16, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 48) {
			ED_SIGNAL_ERROR ("<ERRID:579> Size error decoding IE AdditionalOldRoutingAreaId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1B, 579, (Destin->AdditionalOldRoutingAreaId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RoutingAreaIdenti2 (Buffer, CurrOfs, Destin->AdditionalOldRoutingAreaId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:580> Error decoding subfield AdditionalOldRoutingAreaId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1B, 580, (Destin->AdditionalOldRoutingAreaId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:581> Message too short decoding subfield AdditionalOldRoutingAreaId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1B, 580, (Destin->AdditionalOldRoutingAreaId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE VoiceDomainPrefUEUsageSetting
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 582, 17, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:583> Size error decoding IE VoiceDomainPrefUEUsageSetting\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 583, (Destin->VoiceDomainPrefUEUsageSetting))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_VoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs, Destin->VoiceDomainPrefUEUsageSetting, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:584> Error decoding subfield VoiceDomainPrefUEUsageSetting\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 584, (Destin->VoiceDomainPrefUEUsageSetting))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:585> Message too short decoding subfield VoiceDomainPrefUEUsageSetting\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 584, (Destin->VoiceDomainPrefUEUsageSetting))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 586, 18, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:587> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 587, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:588> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 587, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PTMSI
	------------------------------------------------------*/
	/* Detect IEI tag 0x0E */
	ED_EXPECT_OPTIONAL_IE (0x0E,  4, 589, 19, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PTMSI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PTMSI_Type (Buffer, CurrOfs, Destin->PTMSI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:590> Error decoding subfield PTMSI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PTMSI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0E, 590, (Destin->PTMSI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:591> Message too short decoding subfield PTMSI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_PTMSI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0E, 590, (Destin->PTMSI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 592, 20, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MSNetworkFeatureSupport (Buffer, CurrOfs, Destin->MSNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:593> Error decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 593, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:594> Message too short decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 593, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldLocationAreaIdentification
	------------------------------------------------------*/
	/* Detect IEI tag 0x14 */
	ED_EXPECT_OPTIONAL_IE (0x14,  8, 595, 21, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x14) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:596> Size error decoding IE OldLocationAreaIdentification\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x14, 596, (Destin->OldLocationAreaIdentification))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->OldLocationAreaIdentification, 0, Buffer, CurrOfs, 40);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17123=EDCore::TDMBinary) */Destin->OldLocationAreaIdentification___LOCATOR), CurrOfs, 40);
		RetLen = 40;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:597> Error decoding subfield OldLocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x14, 597, (Destin->OldLocationAreaIdentification))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:598> Message too short decoding subfield OldLocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x14, 597, (Destin->OldLocationAreaIdentification))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 599, 22, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalUpdateType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalUpdateType (Buffer, CurrOfs, Destin->AdditionalUpdateType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:600> Error decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 600, (Destin->AdditionalUpdateType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:601> Message too short decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 600, (Destin->AdditionalUpdateType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TMSIBasedNRIContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x10 */
	ED_EXPECT_OPTIONAL_IE (0x10,  8, 602, 23, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x10) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:603> Size error decoding IE TMSIBasedNRIContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x10, 603, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetworkResourceIdContainer (Buffer, CurrOfs, Destin->TMSIBasedNRIContainer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:604> Error decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x10, 604, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:605> Message too short decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x10, 604, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 606, 24, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3324Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:607> Size error decoding IE T3324Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 607, (Destin->T3324Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3324Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:608> Error decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 608, (Destin->T3324Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:609> Message too short decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 608, (Destin->T3324Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3312ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x39 */
	ED_EXPECT_OPTIONAL_IE (0x39,  8, 610, 25, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x39) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:611> Size error decoding IE T3312ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x39, 611, (Destin->T3312ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3312ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:612> Error decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x39, 612, (Destin->T3312ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:613> Message too short decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x39, 612, (Destin->T3312ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 614, 26, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:615> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 615, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:616> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 616, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:617> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 616, (Destin->ExtendedDRXParameters))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_COMPLETE_UP (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_COMPLETE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 3, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for InterRATHandoverInfo */
	{
		int TLV_Base = CurrOfs;
		if (Source->InterRATHandoverInfo_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->InterRATHandoverInfo> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->InterRATHandoverInfo->value, 0, Source->InterRATHandoverInfo->usedBits);
			Len = Source->InterRATHandoverInfo->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:618> Error encoding subfield InterRATHandoverInfo\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for E_UTRAN_InterRATHandoverInfo */
	{
		int TLV_Base = CurrOfs;
		if (Source->E_UTRAN_InterRATHandoverInfo_Present) {
			/* Append to buffer IEI tag 0x2B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->E_UTRAN_InterRATHandoverInfo> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->E_UTRAN_InterRATHandoverInfo->value, 0, Source->E_UTRAN_InterRATHandoverInfo->usedBits);
			Len = Source->E_UTRAN_InterRATHandoverInfo->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:619> Error encoding subfield E_UTRAN_InterRATHandoverInfo\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_COMPLETE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_COMPLETE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ATTACH_COMPLETE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{43, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE InterRATHandoverInfo
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 620, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1984)) {
			ED_SIGNAL_ERROR ("<ERRID:621> Size error decoding IE InterRATHandoverInfo\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 621, (Destin->InterRATHandoverInfo))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17136=EDCore::TDMBinary) */Destin->InterRATHandoverInfo___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (Destin->InterRATHandoverInfo, Len);
		
			if (Destin->InterRATHandoverInfo->value) {
				EDCopyBits (Destin->InterRATHandoverInfo->value, 0, Buffer, CurrOfs, Len);
				Destin->InterRATHandoverInfo->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->InterRATHandoverInfo->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:622> Error decoding subfield InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 622, (Destin->InterRATHandoverInfo))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:623> Message too short decoding subfield InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 622, (Destin->InterRATHandoverInfo))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE E_UTRAN_InterRATHandoverInfo
	------------------------------------------------------*/
	/* Detect IEI tag 0x2B */
	ED_EXPECT_OPTIONAL_IE (0x2B,  8, 624, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:625> Size error decoding IE E_UTRAN_InterRATHandoverInfo\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2B, 625, (Destin->E_UTRAN_InterRATHandoverInfo))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17138=EDCore::TDMBinary) */Destin->E_UTRAN_InterRATHandoverInfo___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin->E_UTRAN_InterRATHandoverInfo, Len);
		
			if (Destin->E_UTRAN_InterRATHandoverInfo->value) {
				EDCopyBits (Destin->E_UTRAN_InterRATHandoverInfo->value, 0, Buffer, CurrOfs, Len);
				Destin->E_UTRAN_InterRATHandoverInfo->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:626> Error decoding subfield E_UTRAN_InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2B, 626, (Destin->E_UTRAN_InterRATHandoverInfo))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:627> Message too short decoding subfield E_UTRAN_InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2B, 626, (Destin->E_UTRAN_InterRATHandoverInfo))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DETACH_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_DETACH_REQUEST_UP* Source, int Mode)
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
			ED_SIGNAL_ERROR ("<ERRID:628> Error encoding subfield DetachType\n");
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
			ED_SIGNAL_ERROR ("<ERRID:629> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PTmsi */
	{
		int TLV_Base = CurrOfs;
		if (Source->PTmsi_Present) {
			/* Append to buffer IEI tag 0x18 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x18), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsi> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->PTmsi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:630> Error encoding subfield PTmsi\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PTmsiSign */
	{
		int TLV_Base = CurrOfs;
		if (Source->PTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->PTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:631> Error encoding subfield PTmsiSign\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_DETACH_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{24, 255, ED_SKIPLIST_OPTIONAL},
		{25, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:632> Error decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 632, (Destin->DetachType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:633> Message too short decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 632, (Destin->DetachType))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17143=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:634> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 634, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:635> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 634, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsi
	------------------------------------------------------*/
	/* Detect IEI tag 0x18 */
	ED_EXPECT_OPTIONAL_IE (0x18,  8, 636, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x18) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:637> Size error decoding IE PTmsi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x18, 637, (Destin->PTmsi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->PTmsi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:638> Error decoding subfield PTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x18, 638, (Destin->PTmsi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:639> Message too short decoding subfield PTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x18, 638, (Destin->PTmsi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 640, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:641> Size error decoding IE PTmsiSign\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x19, 641, (Destin->PTmsiSign))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->PTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17147=EDCore::TDMBinary) */Destin->PTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:642> Error decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 642, (Destin->PTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:643> Message too short decoding subfield PTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 642, (Destin->PTmsiSign))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DETACH_ACCEPT_UP (char* Buffer, ED_EXLONG BitOffset, const c_DETACH_ACCEPT_UP* Source, int Mode)
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
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_ACCEPT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DETACH_ACCEPT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_DETACH_ACCEPT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_DETACH_ACCEPT_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMPLETE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (char* Buffer, ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMPLETE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 17, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_P_TMSI_REALLOCATION_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_P_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_P_TMSI_REALLOCATION_COMPLETE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE P_TMSI_REALLOCATION_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_P_TMSI_REALLOCATION_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_P_TMSI_REALLOCATION_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_RESPONSE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 19, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ACRefNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ACRefNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ACRefNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:644> Error encoding subfield ACRefNum\n");
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
			ED_SIGNAL_ERROR ("<ERRID:645> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthParamResp */
	{
		if (Source->AuthParamResp_Present) {
			/* Append to buffer IEI tag 0x22 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x22), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthParamResp> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->AuthParamResp), 32);
			Len = 32;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:646> Error encoding subfield AuthParamResp\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for Imeisv */
	{
		int TLV_Base = CurrOfs;
		if (Source->Imeisv_Present) {
			/* Append to buffer IEI tag 0x23 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x23), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Imeisv> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->Imeisv);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:647> Error encoding subfield Imeisv\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AuthRespParamExt */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthRespParamExt_Present) {
			/* Append to buffer IEI tag 0x29 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x29), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthRespParamExt> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthRespParamExt->value, 0, Source->AuthRespParamExt->usedBits);
			Len = Source->AuthRespParamExt->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:648> Error encoding subfield AuthRespParamExt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:649> Error encoding subfield MessageAuthCode\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_RESPONSE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{34, 255, ED_SKIPLIST_OPTIONAL},
		{35, 255, ED_SKIPLIST_OPTIONAL},
		{41, 255, ED_SKIPLIST_OPTIONAL},
		{67, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ACRefNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ACRefNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17152=EDCore::TDMInteger) */Destin->ACRefNum___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:650> Error decoding subfield ACRefNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 650, (Destin->ACRefNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:651> Message too short decoding subfield ACRefNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 650, (Destin->ACRefNum))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17154=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:652> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 652, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:653> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 652, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthParamResp
	------------------------------------------------------*/
	/* Detect IEI tag 0x22 */
	ED_EXPECT_OPTIONAL_IE (0x22,  8, 654, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x22) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 32;
		/* Read value part LOCATOR_16 */
		Destin->AuthParamResp = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17156=EDCore::TDMInteger) */Destin->AuthParamResp___LOCATOR), CurrOfs, 32);
		RetLen = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:655> Error decoding subfield AuthParamResp\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x22, 655, (Destin->AuthParamResp))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:656> Message too short decoding subfield AuthParamResp\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x22, 655, (Destin->AuthParamResp))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Imeisv
	------------------------------------------------------*/
	/* Detect IEI tag 0x23 */
	ED_EXPECT_OPTIONAL_IE (0x23,  8, 657, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x23) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 72) {
			ED_SIGNAL_ERROR ("<ERRID:658> Size error decoding IE Imeisv\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x23, 658, (Destin->Imeisv))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->Imeisv, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:659> Error decoding subfield Imeisv\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x23, 659, (Destin->Imeisv))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:660> Message too short decoding subfield Imeisv\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x23, 659, (Destin->Imeisv))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AuthRespParamExt
	------------------------------------------------------*/
	/* Detect IEI tag 0x29 */
	ED_EXPECT_OPTIONAL_IE (0x29,  8, 661, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x29) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 96)) {
			ED_SIGNAL_ERROR ("<ERRID:662> Size error decoding IE AuthRespParamExt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x29, 662, (Destin->AuthRespParamExt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17160=EDCore::TDMBinary) */Destin->AuthRespParamExt___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (Destin->AuthRespParamExt, Len);
		
			if (Destin->AuthRespParamExt->value) {
				EDCopyBits (Destin->AuthRespParamExt->value, 0, Buffer, CurrOfs, Len);
				Destin->AuthRespParamExt->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->AuthRespParamExt->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:663> Error decoding subfield AuthRespParamExt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x29, 663, (Destin->AuthRespParamExt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:664> Message too short decoding subfield AuthRespParamExt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x29, 663, (Destin->AuthRespParamExt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MessageAuthCode
	------------------------------------------------------*/
	/* Detect IEI tag 0x43 */
	ED_EXPECT_OPTIONAL_IE (0x43,  8, 665, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x43) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 32) {
			ED_SIGNAL_ERROR ("<ERRID:666> Size error decoding IE MessageAuthCode\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x43, 666, (Destin->MessageAuthCode))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->MessageAuthCode = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17162=EDCore::TDMInteger) */Destin->MessageAuthCode___LOCATOR), CurrOfs, 32);
		RetLen = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:667> Error decoding subfield MessageAuthCode\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x43, 667, (Destin->MessageAuthCode))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:668> Message too short decoding subfield MessageAuthCode\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x43, 667, (Destin->MessageAuthCode))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_FAILURE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 28, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GmmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:669> Error encoding subfield GmmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthFailureParam */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthFailureParam_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthFailureParam> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthFailureParam, 0, 112);
			Len = 112;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:670> Error encoding subfield AuthFailureParam\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_AND_CIPHERING_FAILURE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{48, 255, ED_SKIPLIST_OPTIONAL},
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17165=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:671> Error decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 671, (Destin->GmmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:672> Message too short decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 671, (Destin->GmmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthFailureParam
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 673, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 112) {
			ED_SIGNAL_ERROR ("<ERRID:674> Size error decoding IE AuthFailureParam\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 674, (Destin->AuthFailureParam))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->AuthFailureParam, 0, Buffer, CurrOfs, 112);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17167=EDCore::TDMBinary) */Destin->AuthFailureParam___LOCATOR), CurrOfs, 112);
		RetLen = 112;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:675> Error decoding subfield AuthFailureParam\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 675, (Destin->AuthFailureParam))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:676> Message too short decoding subfield AuthFailureParam\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 675, (Destin->AuthFailureParam))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_B_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IDENTITY_RESPONSE_B_UP (char* Buffer, ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_B_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 22, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for MobileId */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileId> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->MobileId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:677> Error encoding subfield MobileId\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_B_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_RESPONSE_B_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_B_UP* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_RESPONSE_B_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_B_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_RESPONSE_B_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE_B_UP* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_RESPONSE_B_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_B_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_RESPONSE_B_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_B_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_IDENTITY_RESPONSE_B_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE_B_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_RESPONSE_B_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE_B_UP* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE MobileId
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 72)) {
		ED_SIGNAL_ERROR ("<ERRID:678> Size error decoding IE MobileId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 678, (Destin->MobileId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->MobileId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:679> Error decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 679, (Destin->MobileId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:680> Message too short decoding subfield MobileId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 679, (Destin->MobileId))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REQUEST_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 8, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for UpdateType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->UpdateType> DOT=<.> */
		Len = ENCODE_c_UpdateType (Buffer, (CurrOfs+4), (&(Source->UpdateType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:681> Error encoding subfield UpdateType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for GprsCiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GprsCiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->GprsCiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:682> Error encoding subfield GprsCiphKeySequenceNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for OldRoutingAreaId */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->OldRoutingAreaId> DOT=<.> */
		Len = ENCODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Source->OldRoutingAreaId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:683> Error encoding subfield OldRoutingAreaId\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MsRadioAccessCpblty */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MsRadioAccessCpblty> DOT=<.> */
		Len = ENCODE_c_MsRadioAccessCpblty (Buffer, CurrOfs+8, (&(Source->MsRadioAccessCpblty)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:684> Error encoding subfield MsRadioAccessCpblty\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for OldPTmsiSign */
	{
		if (Source->OldPTmsiSign_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->OldPTmsiSign> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->OldPTmsiSign, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:685> Error encoding subfield OldPTmsiSign\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ReqRdyTimerValue */
	{
		if (Source->ReqRdyTimerValue_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->ReqRdyTimerValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer (Buffer, CurrOfs, Source->ReqRdyTimerValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:686> Error encoding subfield ReqRdyTimerValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DrxParam */
	{
		if (Source->DrxParam_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->DrxParam> DOT=<->> */
			Len = ENCODE_c_DrxParam (Buffer, CurrOfs, Source->DrxParam);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:687> Error encoding subfield DrxParam\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for TmsiStatus */
	{
		if (Source->TmsiStatus_Present) {
			/* Append to buffer IEI tag 0x09 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x09), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->TmsiStatus> DOT=<->> */
			Len = ENCODE_c_TmsiStatus (Buffer, CurrOfs, Source->TmsiStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:688> Error encoding subfield TmsiStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PTmsi */
	{
		int TLV_Base = CurrOfs;
		if (Source->PTmsi_Present) {
			/* Append to buffer IEI tag 0x18 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x18), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PTmsi> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->PTmsi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:689> Error encoding subfield PTmsi\n");
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
				ED_SIGNAL_ERROR ("<ERRID:690> Error encoding subfield MsNetwkCpblty\n");
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
				ED_SIGNAL_ERROR ("<ERRID:691> Error encoding subfield PdpContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PSLCSCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->PSLCSCapability_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PSLCSCapability> DOT=<->> */
			Len = ENCODE_c_PSLCSCapabilit (Buffer, CurrOfs+8, Source->PSLCSCapability);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:692> Error encoding subfield PSLCSCapability\n");
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
				ED_SIGNAL_ERROR ("<ERRID:693> Error encoding subfield MBMSContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UENetworkCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->UENetworkCapability_Present) {
			/* Append to buffer IEI tag 0x58 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x58), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UENetworkCapability> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->UENetworkCapability->value, 0, Source->UENetworkCapability->usedBits);
			Len = Source->UENetworkCapability->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:694> Error encoding subfield UENetworkCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalMobileIdentity */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalMobileIdentity_Present) {
			/* Append to buffer IEI tag 0x1A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalMobileIdentity> DOT=<->> */
			Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, Source->AdditionalMobileIdentity);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:695> Error encoding subfield AdditionalMobileIdentity\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalOldRoutingAreaIdent */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalOldRoutingAreaIdent_Present) {
			/* Append to buffer IEI tag 0x1B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x1B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalOldRoutingAreaIdent> DOT=<->> */
			Len = ENCODE_c_RoutingAreaIdenti2 (Buffer, CurrOfs+8, Source->AdditionalOldRoutingAreaIdent);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:696> Error encoding subfield AdditionalOldRoutingAreaIdent\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MobileStationClassmark2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->MobileStationClassmark2_Present) {
			/* Append to buffer IEI tag 0x11 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x11), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark2> DOT=<->> */
			Len = ENCODE_c_MobileStationClassmark2 (Buffer, CurrOfs+8, Source->MobileStationClassmark2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:697> Error encoding subfield MobileStationClassmark2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MobileStationClassmark3 */
	{
		int TLV_Base = CurrOfs;
		if (Source->MobileStationClassmark3_Present) {
			/* Append to buffer IEI tag 0x20 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x20), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MobileStationClassmark3> DOT=<->> */
			Len = ENCODE_c_Classmark3Value (Buffer, CurrOfs+8, Source->MobileStationClassmark3);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:698> Error encoding subfield MobileStationClassmark3\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SupportedCodecs */
	{
		int TLV_Base = CurrOfs;
		if (Source->SupportedCodecs_Present) {
			/* Append to buffer IEI tag 0x40 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x40), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SupportedCodecs> DOT=<->> */
			Len = ENCODE_c_SupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:699> Error encoding subfield SupportedCodecs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for VoiceDomainPrefUEUsageSetting */
	{
		int TLV_Base = CurrOfs;
		if (Source->VoiceDomainPrefUEUsageSetting_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->VoiceDomainPrefUEUsageSetting> DOT=<->> */
			Len = ENCODE_c_VoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs+8, Source->VoiceDomainPrefUEUsageSetting);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:700> Error encoding subfield VoiceDomainPrefUEUsageSetting\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PTMSI */
	{
		if (Source->PTMSI_Present) {
			/* Append to buffer IEI tag 0x0E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0E), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->PTMSI> DOT=<->> */
			Len = ENCODE_c_PTMSI_Type (Buffer, CurrOfs, Source->PTMSI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:701> Error encoding subfield PTMSI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DeviceProperties */
	{
		if (Source->DeviceProperties_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:702> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for MSNetworkFeatureSupport */
	{
		if (Source->MSNetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->MSNetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_MSNetworkFeatureSupport (Buffer, CurrOfs, Source->MSNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:703> Error encoding subfield MSNetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for OldLocationAreaId */
	{
		int TLV_Base = CurrOfs;
		if (Source->OldLocationAreaId_Present) {
			/* Append to buffer IEI tag 0x14 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x14), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->OldLocationAreaId> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->OldLocationAreaId, 0, 40);
			Len = 40;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:704> Error encoding subfield OldLocationAreaId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalUpdateType */
	{
		if (Source->AdditionalUpdateType_Present) {
			/* Append to buffer IEI tag 0x0F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0F), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalUpdateType> DOT=<->> */
			Len = ENCODE_c_AdditionalUpdateType (Buffer, CurrOfs, Source->AdditionalUpdateType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:705> Error encoding subfield AdditionalUpdateType\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for TMSIBasedNRIContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->TMSIBasedNRIContainer_Present) {
			/* Append to buffer IEI tag 0x10 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x10), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TMSIBasedNRIContainer> DOT=<->> */
			Len = ENCODE_c_NetworkResourceIdContainer (Buffer, CurrOfs+8, Source->TMSIBasedNRIContainer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:706> Error encoding subfield TMSIBasedNRIContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:707> Error encoding subfield T3324Value\n");
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
				ED_SIGNAL_ERROR ("<ERRID:708> Error encoding subfield T3312ExtendedValue\n");
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
				ED_SIGNAL_ERROR ("<ERRID:709> Error encoding subfield ExtendedDRXParameters\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ROUTING_AREA_UPDATE_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{144, 240, ED_SKIPLIST_OPTIONAL},
		{24, 255, ED_SKIPLIST_OPTIONAL},
		{49, 255, ED_SKIPLIST_OPTIONAL},
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{88, 255, ED_SKIPLIST_OPTIONAL},
		{26, 255, ED_SKIPLIST_OPTIONAL},
		{27, 255, ED_SKIPLIST_OPTIONAL},
		{17, 255, ED_SKIPLIST_OPTIONAL},
		{32, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{224, 240, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{20, 255, ED_SKIPLIST_OPTIONAL},
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{16, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{57, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE UpdateType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_UpdateType (Buffer, (CurrOfs+4), (&(Destin->UpdateType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:710> Error decoding subfield UpdateType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 710, (Destin->UpdateType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:711> Message too short decoding subfield UpdateType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 710, (Destin->UpdateType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE GprsCiphKeySequenceNum
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->GprsCiphKeySequenceNum = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs-4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17175=EDCore::TDMInteger) */Destin->GprsCiphKeySequenceNum___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:712> Error decoding subfield GprsCiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 712, (Destin->GprsCiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:713> Message too short decoding subfield GprsCiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 712, (Destin->GprsCiphKeySequenceNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OldRoutingAreaId
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 48;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_RoutingAreaIdenti (Buffer, CurrOfs, (&(Destin->OldRoutingAreaId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:714> Error decoding subfield OldRoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 714, (Destin->OldRoutingAreaId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:715> Message too short decoding subfield OldRoutingAreaId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 714, (Destin->OldRoutingAreaId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MsRadioAccessCpblty
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 40) || (Len > 400)) {
		ED_SIGNAL_ERROR ("<ERRID:716> Size error decoding IE MsRadioAccessCpblty\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 716, (Destin->MsRadioAccessCpblty))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MsRadioAccessCpblty (Buffer, CurrOfs, (&(Destin->MsRadioAccessCpblty)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:717> Error decoding subfield MsRadioAccessCpblty\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 717, (Destin->MsRadioAccessCpblty))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:718> Message too short decoding subfield MsRadioAccessCpblty\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 717, (Destin->MsRadioAccessCpblty))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OldPTmsiSign
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 719, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->OldPTmsiSign, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17181=EDCore::TDMBinary) */Destin->OldPTmsiSign___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:720> Error decoding subfield OldPTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 720, (Destin->OldPTmsiSign))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:721> Message too short decoding subfield OldPTmsiSign\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 720, (Destin->OldPTmsiSign))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReqRdyTimerValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 722, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer (Buffer, CurrOfs, Destin->ReqRdyTimerValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:723> Error decoding subfield ReqRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 723, (Destin->ReqRdyTimerValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:724> Message too short decoding subfield ReqRdyTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 723, (Destin->ReqRdyTimerValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DrxParam
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 725, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 16;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DrxParam (Buffer, CurrOfs, Destin->DrxParam, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:726> Error decoding subfield DrxParam\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 726, (Destin->DrxParam))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:727> Message too short decoding subfield DrxParam\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 726, (Destin->DrxParam))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TmsiStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x09 */
	ED_EXPECT_OPTIONAL_IE (0x09,  4, 728, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x09) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TmsiStatus (Buffer, CurrOfs, Destin->TmsiStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:729> Error decoding subfield TmsiStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x09, 729, (Destin->TmsiStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:730> Message too short decoding subfield TmsiStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x09, 729, (Destin->TmsiStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsi
	------------------------------------------------------*/
	/* Detect IEI tag 0x18 */
	ED_EXPECT_OPTIONAL_IE (0x18,  8, 731, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x18) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:732> Size error decoding IE PTmsi\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x18, 732, (Destin->PTmsi))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->PTmsi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:733> Error decoding subfield PTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x18, 733, (Destin->PTmsi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:734> Message too short decoding subfield PTmsi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x18, 733, (Destin->PTmsi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MsNetwkCpblty
	------------------------------------------------------*/
	/* Detect IEI tag 0x31 */
	ED_EXPECT_OPTIONAL_IE (0x31,  8, 735, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x31) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:736> Size error decoding IE MsNetwkCpblty\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x31, 736, (Destin->MsNetwkCpblty))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MsNetwkCpblty (Buffer, CurrOfs, Destin->MsNetwkCpblty, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:737> Error decoding subfield MsNetwkCpblty\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x31, 737, (Destin->MsNetwkCpblty))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:738> Message too short decoding subfield MsNetwkCpblty\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x31, 737, (Destin->MsNetwkCpblty))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PdpContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 739, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:740> Size error decoding IE PdpContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x32, 740, (Destin->PdpContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PdpContextStatus (Buffer, CurrOfs, Destin->PdpContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:741> Error decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 741, (Destin->PdpContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:742> Message too short decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 741, (Destin->PdpContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PSLCSCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 743, 11, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:744> Size error decoding IE PSLCSCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 744, (Destin->PSLCSCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PSLCSCapabilit (Buffer, CurrOfs, Destin->PSLCSCapability, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:745> Error decoding subfield PSLCSCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 745, (Destin->PSLCSCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:746> Message too short decoding subfield PSLCSCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 745, (Destin->PSLCSCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 747, 12, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:748> Size error decoding IE MBMSContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 748, (Destin->MBMSContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17197=EDCore::TDMBinary) */Destin->MBMSContextStatus___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (Destin->MBMSContextStatus, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:749> Error decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 749, (Destin->MBMSContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:750> Message too short decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 749, (Destin->MBMSContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UENetworkCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x58 */
	ED_EXPECT_OPTIONAL_IE (0x58,  8, 751, 13, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x58) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 104)) {
			ED_SIGNAL_ERROR ("<ERRID:752> Size error decoding IE UENetworkCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x58, 752, (Destin->UENetworkCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17199=EDCore::TDMBinary) */Destin->UENetworkCapability___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (Destin->UENetworkCapability, Len);
		
			if (Destin->UENetworkCapability->value) {
				EDCopyBits (Destin->UENetworkCapability->value, 0, Buffer, CurrOfs, Len);
				Destin->UENetworkCapability->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->UENetworkCapability->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:753> Error decoding subfield UENetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x58, 753, (Destin->UENetworkCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:754> Message too short decoding subfield UENetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x58, 753, (Destin->UENetworkCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalMobileIdentity
	------------------------------------------------------*/
	/* Detect IEI tag 0x1A */
	ED_EXPECT_OPTIONAL_IE (0x1A,  8, 755, 14, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:756> Size error decoding IE AdditionalMobileIdentity\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1A, 756, (Destin->AdditionalMobileIdentity))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileId (Buffer, CurrOfs, Destin->AdditionalMobileIdentity, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:757> Error decoding subfield AdditionalMobileIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1A, 757, (Destin->AdditionalMobileIdentity))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:758> Message too short decoding subfield AdditionalMobileIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1A, 757, (Destin->AdditionalMobileIdentity))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalOldRoutingAreaIdent
	------------------------------------------------------*/
	/* Detect IEI tag 0x1B */
	ED_EXPECT_OPTIONAL_IE (0x1B,  8, 759, 15, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x1B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 48) {
			ED_SIGNAL_ERROR ("<ERRID:760> Size error decoding IE AdditionalOldRoutingAreaIdent\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x1B, 760, (Destin->AdditionalOldRoutingAreaIdent))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RoutingAreaIdenti2 (Buffer, CurrOfs, Destin->AdditionalOldRoutingAreaIdent, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:761> Error decoding subfield AdditionalOldRoutingAreaIdent\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x1B, 761, (Destin->AdditionalOldRoutingAreaIdent))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:762> Message too short decoding subfield AdditionalOldRoutingAreaIdent\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x1B, 761, (Destin->AdditionalOldRoutingAreaIdent))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark2
	------------------------------------------------------*/
	/* Detect IEI tag 0x11 */
	ED_EXPECT_OPTIONAL_IE (0x11,  8, 763, 16, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x11) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:764> Size error decoding IE MobileStationClassmark2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x11, 764, (Destin->MobileStationClassmark2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MobileStationClassmark2 (Buffer, CurrOfs, Destin->MobileStationClassmark2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:765> Error decoding subfield MobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x11, 765, (Destin->MobileStationClassmark2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:766> Message too short decoding subfield MobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x11, 765, (Destin->MobileStationClassmark2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark3
	------------------------------------------------------*/
	/* Detect IEI tag 0x20 */
	ED_EXPECT_OPTIONAL_IE (0x20,  8, 767, 17, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x20) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 256) {
			ED_SIGNAL_ERROR ("<ERRID:768> Size error decoding IE MobileStationClassmark3\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x20, 768, (Destin->MobileStationClassmark3))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_Classmark3Value (Buffer, CurrOfs, Destin->MobileStationClassmark3, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:769> Error decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x20, 769, (Destin->MobileStationClassmark3))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:770> Message too short decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x20, 769, (Destin->MobileStationClassmark3))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 771, 18, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:772> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 772, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:773> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 773, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:774> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 773, (Destin->SupportedCodecs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE VoiceDomainPrefUEUsageSetting
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 775, 19, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:776> Size error decoding IE VoiceDomainPrefUEUsageSetting\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 776, (Destin->VoiceDomainPrefUEUsageSetting))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_VoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs, Destin->VoiceDomainPrefUEUsageSetting, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:777> Error decoding subfield VoiceDomainPrefUEUsageSetting\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 777, (Destin->VoiceDomainPrefUEUsageSetting))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:778> Message too short decoding subfield VoiceDomainPrefUEUsageSetting\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 777, (Destin->VoiceDomainPrefUEUsageSetting))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PTMSI
	------------------------------------------------------*/
	/* Detect IEI tag 0x0E */
	ED_EXPECT_OPTIONAL_IE (0x0E,  4, 779, 20, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PTMSI_Type (Buffer, CurrOfs, Destin->PTMSI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:780> Error decoding subfield PTMSI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0E, 780, (Destin->PTMSI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:781> Message too short decoding subfield PTMSI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0E, 780, (Destin->PTMSI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 782, 21, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:783> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 783, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:784> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 783, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 785, 22, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_MSNetworkFeatureSupport (Buffer, CurrOfs, Destin->MSNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:786> Error decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 786, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:787> Message too short decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 786, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldLocationAreaId
	------------------------------------------------------*/
	/* Detect IEI tag 0x14 */
	ED_EXPECT_OPTIONAL_IE (0x14,  8, 788, 23, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x14) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 40) {
			ED_SIGNAL_ERROR ("<ERRID:789> Size error decoding IE OldLocationAreaId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x14, 789, (Destin->OldLocationAreaId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->OldLocationAreaId, 0, Buffer, CurrOfs, 40);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17219=EDCore::TDMBinary) */Destin->OldLocationAreaId___LOCATOR), CurrOfs, 40);
		RetLen = 40;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:790> Error decoding subfield OldLocationAreaId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x14, 790, (Destin->OldLocationAreaId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:791> Message too short decoding subfield OldLocationAreaId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x14, 790, (Destin->OldLocationAreaId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 792, 24, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalUpdateType (Buffer, CurrOfs, Destin->AdditionalUpdateType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:793> Error decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 793, (Destin->AdditionalUpdateType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:794> Message too short decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 793, (Destin->AdditionalUpdateType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TMSIBasedNRIContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x10 */
	ED_EXPECT_OPTIONAL_IE (0x10,  8, 795, 25, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x10) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:796> Size error decoding IE TMSIBasedNRIContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x10, 796, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NetworkResourceIdContainer (Buffer, CurrOfs, Destin->TMSIBasedNRIContainer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:797> Error decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x10, 797, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:798> Message too short decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x10, 797, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 799, 26, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:800> Size error decoding IE T3324Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 800, (Destin->T3324Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer2 (Buffer, CurrOfs, Destin->T3324Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:801> Error decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 801, (Destin->T3324Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:802> Message too short decoding subfield T3324Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 801, (Destin->T3324Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3312ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x39 */
	ED_EXPECT_OPTIONAL_IE (0x39,  8, 803, 27, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x39) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:804> Size error decoding IE T3312ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x39, 804, (Destin->T3312ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3312ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:805> Error decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x39, 805, (Destin->T3312ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:806> Message too short decoding subfield T3312ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x39, 805, (Destin->T3312ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 807, 28, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:808> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 808, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:809> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 809, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:810> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 809, (Destin->ExtendedDRXParameters))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_COMPLETE_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (char* Buffer, ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_COMPLETE_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 8);
		CurrOfs += 8;
		
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
				ED_SIGNAL_ERROR ("<ERRID:811> Error encoding subfield ListOfReceiveNPduNumbers\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for InterRATHandoverInfo */
	{
		int TLV_Base = CurrOfs;
		if (Source->InterRATHandoverInfo_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->InterRATHandoverInfo> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->InterRATHandoverInfo->value, 0, Source->InterRATHandoverInfo->usedBits);
			Len = Source->InterRATHandoverInfo->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:812> Error encoding subfield InterRATHandoverInfo\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for E_UTRAN_InterRATHandoverInfo */
	{
		int TLV_Base = CurrOfs;
		if (Source->E_UTRAN_InterRATHandoverInfo_Present) {
			/* Append to buffer IEI tag 0x2B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->E_UTRAN_InterRATHandoverInfo> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->E_UTRAN_InterRATHandoverInfo->value, 0, Source->E_UTRAN_InterRATHandoverInfo->usedBits);
			Len = Source->E_UTRAN_InterRATHandoverInfo->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:813> Error encoding subfield E_UTRAN_InterRATHandoverInfo\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ROUTING_AREA_UPDATE_COMPLETE_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ROUTING_AREA_UPDATE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_ROUTING_AREA_UPDATE_COMPLETE_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ROUTING_AREA_UPDATE_COMPLETE_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ROUTING_AREA_UPDATE_COMPLETE_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ROUTING_AREA_UPDATE_COMPLETE_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{38, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{43, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ListOfReceiveNPduNumbers
	------------------------------------------------------*/
	/* Detect IEI tag 0x26 */
	ED_EXPECT_OPTIONAL_IE (0x26,  8, 814, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x26) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 136)) {
			ED_SIGNAL_ERROR ("<ERRID:815> Size error decoding IE ListOfReceiveNPduNumbers\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x26, 815, (Destin->ListOfReceiveNPduNumbers))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ReceiveNPduNumbersList (Buffer, CurrOfs, Destin->ListOfReceiveNPduNumbers, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:816> Error decoding subfield ListOfReceiveNPduNumbers\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x26, 816, (Destin->ListOfReceiveNPduNumbers))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:817> Message too short decoding subfield ListOfReceiveNPduNumbers\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x26, 816, (Destin->ListOfReceiveNPduNumbers))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE InterRATHandoverInfo
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 818, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 1984)) {
			ED_SIGNAL_ERROR ("<ERRID:819> Size error decoding IE InterRATHandoverInfo\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 819, (Destin->InterRATHandoverInfo))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17234=EDCore::TDMBinary) */Destin->InterRATHandoverInfo___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (Destin->InterRATHandoverInfo, Len);
		
			if (Destin->InterRATHandoverInfo->value) {
				EDCopyBits (Destin->InterRATHandoverInfo->value, 0, Buffer, CurrOfs, Len);
				Destin->InterRATHandoverInfo->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->InterRATHandoverInfo->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:820> Error decoding subfield InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 820, (Destin->InterRATHandoverInfo))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:821> Message too short decoding subfield InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 820, (Destin->InterRATHandoverInfo))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE E_UTRAN_InterRATHandoverInfo
	------------------------------------------------------*/
	/* Detect IEI tag 0x2B */
	ED_EXPECT_OPTIONAL_IE (0x2B,  8, 822, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:823> Size error decoding IE E_UTRAN_InterRATHandoverInfo\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2B, 823, (Destin->E_UTRAN_InterRATHandoverInfo))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17236=EDCore::TDMBinary) */Destin->E_UTRAN_InterRATHandoverInfo___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin->E_UTRAN_InterRATHandoverInfo, Len);
		
			if (Destin->E_UTRAN_InterRATHandoverInfo->value) {
				EDCopyBits (Destin->E_UTRAN_InterRATHandoverInfo->value, 0, Buffer, CurrOfs, Len);
				Destin->E_UTRAN_InterRATHandoverInfo->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->E_UTRAN_InterRATHandoverInfo->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:824> Error decoding subfield E_UTRAN_InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2B, 824, (Destin->E_UTRAN_InterRATHandoverInfo))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:825> Message too short decoding subfield E_UTRAN_InterRATHandoverInfo\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2B, 824, (Destin->E_UTRAN_InterRATHandoverInfo))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GMM_STATUS
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_GMM_STATUS (char* Buffer, ED_EXLONG BitOffset, const c_GMM_STATUS* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 32, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GmmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GmmCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GmmCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:826> Error encoding subfield GmmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_GMM_STATUS (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE GMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GMM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_GMM_STATUS (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_STATUS* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_GMM_STATUS (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GMM_STATUS* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE GmmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->GmmCause = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17239=EDCore::TDMInteger) */Destin->GmmCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:827> Error decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 827, (Destin->GmmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:828> Message too short decoding subfield GmmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 827, (Destin->GmmCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SERVICE_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_SERVICE_REQUEST_UP* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 12, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for CiphKeySequenceNum */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->CiphKeySequenceNum> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->CiphKeySequenceNum), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:829> Error encoding subfield CiphKeySequenceNum\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ServType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ServType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->ServType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:830> Error encoding subfield ServType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PTmsi */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->PTmsi> DOT=<.> */
		Len = ENCODE_c_MobileId (Buffer, CurrOfs+8, (&(Source->PTmsi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:831> Error encoding subfield PTmsi\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:832> Error encoding subfield PdpContextStatus\n");
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
				ED_SIGNAL_ERROR ("<ERRID:833> Error encoding subfield MBMSContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for UplinkDataStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->UplinkDataStatus_Present) {
			/* Append to buffer IEI tag 0x36 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x36), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->UplinkDataStatus> DOT=<->> */
			Len = ENCODE_c_UplinkDataStatus (Buffer, CurrOfs+8, Source->UplinkDataStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:834> Error encoding subfield UplinkDataStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for DeviceProperties */
	{
		if (Source->DeviceProperties_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:835> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_SERVICE_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{54, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17242=EDCore::TDMInteger) */Destin->CiphKeySequenceNum___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:836> Error decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 836, (Destin->CiphKeySequenceNum))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:837> Message too short decoding subfield CiphKeySequenceNum\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 836, (Destin->CiphKeySequenceNum))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ServType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ServType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs-4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17244=EDCore::TDMOctet) */Destin->ServType___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:838> Error decoding subfield ServType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 838, (Destin->ServType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:839> Message too short decoding subfield ServType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 838, (Destin->ServType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PTmsi
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 40) {
		ED_SIGNAL_ERROR ("<ERRID:840> Size error decoding IE PTmsi\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 840, (Destin->PTmsi))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MobileId (Buffer, CurrOfs, (&(Destin->PTmsi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:841> Error decoding subfield PTmsi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 841, (Destin->PTmsi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:842> Message too short decoding subfield PTmsi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 841, (Destin->PTmsi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PdpContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 843, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:844> Size error decoding IE PdpContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x32, 844, (Destin->PdpContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PdpContextStatus (Buffer, CurrOfs, Destin->PdpContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:845> Error decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 845, (Destin->PdpContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:846> Message too short decoding subfield PdpContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 845, (Destin->PdpContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 847, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:848> Size error decoding IE MBMSContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 848, (Destin->MBMSContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17250=EDCore::TDMBinary) */Destin->MBMSContextStatus___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_SERVICE_REQUEST_UP_MBMSContextStatus (Destin->MBMSContextStatus, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:849> Error decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 849, (Destin->MBMSContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:850> Message too short decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 849, (Destin->MBMSContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UplinkDataStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x36 */
	ED_EXPECT_OPTIONAL_IE (0x36,  8, 851, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x36) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:852> Size error decoding IE UplinkDataStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x36, 852, (Destin->UplinkDataStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_UplinkDataStatus (Buffer, CurrOfs, Destin->UplinkDataStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:853> Error decoding subfield UplinkDataStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x36, 853, (Destin->UplinkDataStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:854> Message too short decoding subfield UplinkDataStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x36, 853, (Destin->UplinkDataStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 855, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:856> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 856, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:857> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 856, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_AUTHENTICATION_RESPONSE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 20) /* message type */
	);
}

int Match_c_AUTHENTICATION_FAILURE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 28) /* message type */
	);
}

int Match_c_CM_RE_ESTABLISHMENT_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 40) /* message type */
	);
}

int Match_c_CM_SERVICE_ABORT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 35) /* message type */
	);
}

int Match_c_CM_SERVICE_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 36) /* message type */
	);
}

int Match_c_IDENTITY_RESPONSE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 25) /* message type */
	);
}

int Match_c_IMSI_DETACH_INDICATION_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 1) /* message type */
	);
}

int Match_c_LOCATION_UPDATING_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 8) /* message type */
	);
}

int Match_c_MM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 49) /* message type */
	);
}

int Match_c_TMSI_REALLOCATION_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 27) /* message type */
	);
}

int Match_c_MM_NULL_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 5) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 48) /* message type */
	);
}

int Match_c_ALERTING_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 1) /* message type */
	);
}

int Match_c_CALL_CONFIRMED_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 8) /* message type */
	);
}

int Match_c_CONNECT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 7) /* message type */
	);
}

int Match_c_CONNECT_ACKNOWLEDGE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 15) /* message type */
	);
}

int Match_c_DISCONNECT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 37) /* message type */
	);
}

int Match_c_EMERGENCY_SETUP_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 14) /* message type */
	);
}

int Match_c_FACILITY_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 58) /* message type */
	);
}

int Match_c_HOLD_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 24) /* message type */
	);
}

int Match_c_MODIFY (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 23) /* message type */
	);
}

int Match_c_MODIFY_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 31) /* message type */
	);
}

int Match_c_MODIFY_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 19) /* message type */
	);
}

int Match_c_NOTIFY (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 62) /* message type */
	);
}

int Match_c_CC_ESTABLISHMENT_CONFIRMED_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 6) /* message type */
	);
}

int Match_c_RELEASE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 45) /* message type */
	);
}

int Match_c_RELEASE_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 42) /* message type */
	);
}

int Match_c_RETRIEVE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 28) /* message type */
	);
}

int Match_c_SETUP_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 5) /* message type */
	);
}

int Match_c_START_CC_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 9) /* message type */
	);
}

int Match_c_START_DTMF_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 53) /* message type */
	);
}

int Match_c_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 61) /* message type */
	);
}

int Match_c_STATUS_ENQUIRY (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 52) /* message type */
	);
}

int Match_c_STOP_DTMF_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 49) /* message type */
	);
}

int Match_c_USER_INFORMATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 3) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8) & 0x3F) == 16) /* message type */
	);
}

int Match_c_ATTACH_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 1) /* message type */
	);
}

int Match_c_ATTACH_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 3) /* message type */
	);
}

int Match_c_DETACH_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 5) /* message type */
	);
}

int Match_c_DETACH_ACCEPT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 6) /* message type */
	);
}

int Match_c_P_TMSI_REALLOCATION_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 17) /* message type */
	);
}

int Match_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 19) /* message type */
	);
}

int Match_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 28) /* message type */
	);
}

int Match_c_IDENTITY_RESPONSE_B_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 22) /* message type */
	);
}

int Match_c_ROUTING_AREA_UPDATE_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 8) /* message type */
	);
}

int Match_c_ROUTING_AREA_UPDATE_COMPLETE_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 10) /* message type */
	);
}

int Match_c_GMM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 32) /* message type */
	);
}

int Match_c_SERVICE_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset+4, 4) == 8) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 12) /* message type */
	);
}

