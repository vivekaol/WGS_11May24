/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "MS2MSC_SMS.h"
#include "ed_c_known_ie_SMS.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_SMS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_DATA_MS2MSC
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RP_DATA_MS2MSC (char* Buffer, ED_EXLONG BitOffset, const c_RP_DATA_MS2MSC* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 0, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RP_MessageReference */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RP_MessageReference> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->RP_MessageReference), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:43> Error encoding subfield RP_MessageReference\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for RP_OriginatorAddress */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->RP_OriginatorAddress> DOT=<.> */
		Len = ENCODE_c_T24011Address (Buffer, CurrOfs+8, (&(Source->RP_OriginatorAddress)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:44> Error encoding subfield RP_OriginatorAddress\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RP_DestinationAddress */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->RP_DestinationAddress> DOT=<.> */
		Len = ENCODE_c_T24011Address (Buffer, CurrOfs+8, (&(Source->RP_DestinationAddress)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:45> Error encoding subfield RP_DestinationAddress\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RP_UserData */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->RP_UserData> DOT=<.> */
		Len = ENCODE_c_SMS_MS2SC (Buffer, CurrOfs+8, (&(Source->RP_UserData)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:46> Error encoding subfield RP_UserData\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_DATA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_DATA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_DATA_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_DATA_MS2MSC (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_DATA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_DATA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_DATA_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_DATA_MS2MSC (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_DATA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_DATA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_DATA_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_RP_DATA_MS2MSC (Buffer, (BitOffset+8), Destin, Length-(8));
	if (Len < 0) return Len;
	
	return Len+8;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_DATA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_DATA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_DATA_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE RP_MessageReference
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->RP_MessageReference = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-2984=EDCore::TDMInteger) */Destin->RP_MessageReference___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:47> Error decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 47, (Destin->RP_MessageReference))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:48> Message too short decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 47, (Destin->RP_MessageReference))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RP_OriginatorAddress
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 0) {
		ED_SIGNAL_ERROR ("<ERRID:49> Size error decoding IE RP_OriginatorAddress\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 49, (Destin->RP_OriginatorAddress))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_T24011Address (Buffer, CurrOfs, (&(Destin->RP_OriginatorAddress)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:50> Error decoding subfield RP_OriginatorAddress\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 50, (Destin->RP_OriginatorAddress))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:51> Message too short decoding subfield RP_OriginatorAddress\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 50, (Destin->RP_OriginatorAddress))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RP_DestinationAddress
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 88) {
		ED_SIGNAL_ERROR ("<ERRID:52> Size error decoding IE RP_DestinationAddress\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 52, (Destin->RP_DestinationAddress))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_T24011Address (Buffer, CurrOfs, (&(Destin->RP_DestinationAddress)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:53> Error decoding subfield RP_DestinationAddress\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 53, (Destin->RP_DestinationAddress))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:54> Message too short decoding subfield RP_DestinationAddress\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 53, (Destin->RP_DestinationAddress))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RP_UserData
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 1856) {
		ED_SIGNAL_ERROR ("<ERRID:55> Size error decoding IE RP_UserData\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 55, (Destin->RP_UserData))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_SMS_MS2SC (Buffer, CurrOfs, (&(Destin->RP_UserData)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:56> Error decoding subfield RP_UserData\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 56, (Destin->RP_UserData))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:57> Message too short decoding subfield RP_UserData\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 56, (Destin->RP_UserData))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_SMMA_MS2MSC
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RP_RP_SMMA_MS2MSC (char* Buffer, ED_EXLONG BitOffset, const c_RP_RP_SMMA_MS2MSC* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 6, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RP_MessageReference */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RP_MessageReference> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->RP_MessageReference), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:58> Error encoding subfield RP_MessageReference\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_SMMA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_RP_SMMA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_SMMA_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_RP_SMMA_MS2MSC (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_SMMA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_RP_SMMA_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_SMMA_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_RP_SMMA_MS2MSC (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_SMMA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_RP_SMMA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_SMMA_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_RP_RP_SMMA_MS2MSC (Buffer, (BitOffset+8), Destin, Length-(8));
	if (Len < 0) return Len;
	
	return Len+8;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_SMMA_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_RP_SMMA_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_SMMA_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE RP_MessageReference
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->RP_MessageReference = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-2993=EDCore::TDMInteger) */Destin->RP_MessageReference___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:59> Error decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 59, (Destin->RP_MessageReference))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:60> Message too short decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 59, (Destin->RP_MessageReference))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ACK_MS2MSC
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RP_RP_ACK_MS2MSC (char* Buffer, ED_EXLONG BitOffset, const c_RP_RP_ACK_MS2MSC* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RP_MessageReference */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RP_MessageReference> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->RP_MessageReference), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:61> Error encoding subfield RP_MessageReference\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for RP_UserData */
	{
		int TLV_Base = CurrOfs;
		if (Source->RP_UserData_Present) {
			/* Append to buffer IEI tag 0x41 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x41), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RP_UserData> DOT=<->> */
			Len = ENCODE_c_SMS_MS2SC_ACK (Buffer, CurrOfs+8, Source->RP_UserData);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:62> Error encoding subfield RP_UserData\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ACK_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_RP_ACK_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ACK_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_RP_ACK_MS2MSC (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ACK_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_RP_ACK_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ACK_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_RP_ACK_MS2MSC (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ACK_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_RP_ACK_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ACK_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_RP_RP_ACK_MS2MSC (Buffer, (BitOffset+8), Destin, Length-(8));
	if (Len < 0) return Len;
	
	return Len+8;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ACK_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_RP_ACK_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ACK_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
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
		{65, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE RP_MessageReference
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->RP_MessageReference = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-2996=EDCore::TDMInteger) */Destin->RP_MessageReference___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:63> Error decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 63, (Destin->RP_MessageReference))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:64> Message too short decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 63, (Destin->RP_MessageReference))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RP_UserData
	------------------------------------------------------*/
	/* Detect IEI tag 0x41 */
	ED_EXPECT_OPTIONAL_IE (0x41,  8, 65, 1, KnownL3IEs_SMS)
	
	/* This is an optional field */
	if (Tag == 0x41) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 1856) {
			ED_SIGNAL_ERROR ("<ERRID:66> Size error decoding IE RP_UserData\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x41, 66, (Destin->RP_UserData))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SMS_MS2SC_ACK (Buffer, CurrOfs, Destin->RP_UserData, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:67> Error decoding subfield RP_UserData\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x41, 67, (Destin->RP_UserData))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:68> Message too short decoding subfield RP_UserData\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RP_RP_ACK_MS2MSC_RP_UserData (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x41, 67, (Destin->RP_UserData))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ERROR_MS2MSC
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_RP_RP_ERROR_MS2MSC (char* Buffer, ED_EXLONG BitOffset, const c_RP_RP_ERROR_MS2MSC* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 4, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RP_MessageReference */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RP_MessageReference> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->RP_MessageReference), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:69> Error encoding subfield RP_MessageReference\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for RP_Cause */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->RP_Cause> DOT=<.> */
		Len = ENCODE_c_TRPCause (Buffer, CurrOfs+8, (&(Source->RP_Cause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:70> Error encoding subfield RP_Cause\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RP_UserData */
	{
		int TLV_Base = CurrOfs;
		if (Source->RP_UserData_Present) {
			/* Append to buffer IEI tag 0x41 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x41), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RP_UserData> DOT=<->> */
			Len = ENCODE_c_SMS_MS2SC_ERR (Buffer, CurrOfs+8, Source->RP_UserData);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:71> Error encoding subfield RP_UserData\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ERROR_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_RP_RP_ERROR_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ERROR_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_RP_ERROR_MS2MSC (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ERROR_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_RP_RP_ERROR_MS2MSC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_RP_RP_ERROR_MS2MSC* ED_CONST Source))
{
	return L3_ENCODE_c_RP_RP_ERROR_MS2MSC (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ERROR_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_RP_RP_ERROR_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ERROR_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	
	Len = DECODE_BODY_c_RP_RP_ERROR_MS2MSC (Buffer, (BitOffset+8), Destin, Length-(8));
	if (Len < 0) return Len;
	
	return Len+8;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE RP_RP_ERROR_MS2MSC
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_RP_RP_ERROR_MS2MSC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_RP_RP_ERROR_MS2MSC* ED_CONST Destin, ED_EXLONG Length))
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
		{65, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE RP_MessageReference
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->RP_MessageReference = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-3001=EDCore::TDMInteger) */Destin->RP_MessageReference___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:72> Error decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 72, (Destin->RP_MessageReference))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:73> Message too short decoding subfield RP_MessageReference\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 72, (Destin->RP_MessageReference))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RP_Cause
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 16)) {
		ED_SIGNAL_ERROR ("<ERRID:74> Size error decoding IE RP_Cause\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 74, (Destin->RP_Cause))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_TRPCause (Buffer, CurrOfs, (&(Destin->RP_Cause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:75> Error decoding subfield RP_Cause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 75, (Destin->RP_Cause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:76> Message too short decoding subfield RP_Cause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 75, (Destin->RP_Cause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RP_UserData
	------------------------------------------------------*/
	/* Detect IEI tag 0x41 */
	ED_EXPECT_OPTIONAL_IE (0x41,  8, 77, 2, KnownL3IEs_SMS)
	
	/* This is an optional field */
	if (Tag == 0x41) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 1856) {
			ED_SIGNAL_ERROR ("<ERRID:78> Size error decoding IE RP_UserData\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x41, 78, (Destin->RP_UserData))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SMS_MS2SC_ERR (Buffer, CurrOfs, Destin->RP_UserData, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:79> Error decoding subfield RP_UserData\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x41, 79, (Destin->RP_UserData))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:80> Message too short decoding subfield RP_UserData\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_RP_RP_ERROR_MS2MSC_RP_UserData (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x41, 79, (Destin->RP_UserData))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_RP_DATA_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		((EDBitsToInt (Buffer, BitOffset, 8)) == 0) /* message type */
	);
}

int Match_c_RP_RP_SMMA_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		((EDBitsToInt (Buffer, BitOffset, 8)) == 6) /* message type */
	);
}

int Match_c_RP_RP_ACK_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		((EDBitsToInt (Buffer, BitOffset, 8)) == 2) /* message type */
	);
}

int Match_c_RP_RP_ERROR_MS2MSC (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		((EDBitsToInt (Buffer, BitOffset, 8)) == 4) /* message type */
	);
}

