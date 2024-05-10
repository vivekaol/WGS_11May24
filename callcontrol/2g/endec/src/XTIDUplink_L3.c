/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "XTIDUplink_L3.h"
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 65, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ReqNsapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ReqNsapi> DOT=<.> */
		Len = ENCODE_c_NetwkServAccessPointId (Buffer, CurrOfs, (&(Source->ReqNsapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1610> Error encoding subfield ReqNsapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ReqLlcSapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ReqLlcSapi> DOT=<.> */
		Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Source->ReqLlcSapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1611> Error encoding subfield ReqLlcSapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ReqQos */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ReqQos> DOT=<.> */
		Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, (&(Source->ReqQos)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1612> Error encoding subfield ReqQos\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for ReqPdpAddr */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ReqPdpAddr> DOT=<.> */
		Len = ENCODE_c_PacketDataProtocolAddr (Buffer, CurrOfs+8, (&(Source->ReqPdpAddr)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1613> Error encoding subfield ReqPdpAddr\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for AccessPointName */
	{
		int TLV_Base = CurrOfs;
		if (Source->AccessPointName_Present) {
			/* Append to buffer IEI tag 0x28 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x28), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AccessPointName> DOT=<->> */
			Len = ENCODE_c_ASCII (Buffer, CurrOfs+8, Source->AccessPointName);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1614> Error encoding subfield AccessPointName\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProtocolCfgOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolCfgOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolCfgOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolCfgOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1615> Error encoding subfield ProtocolCfgOpt\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for RequestType */
	{
		if (Source->RequestType_Present) {
			/* Append to buffer IEI tag 0x0A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0A), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RequestType> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->RequestType), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1616> Error encoding subfield RequestType\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DeviceProperties */
	{
		if (Source->DeviceProperties_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1617> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NBIFOMContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NBIFOMContainer_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NBIFOMContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NBIFOMContainer->value, 0, Source->NBIFOMContainer->usedBits);
			Len = Source->NBIFOMContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1618> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{40, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{160, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ReqNsapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NetwkServAccessPointId (Buffer, CurrOfs, (&(Destin->ReqNsapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1619> Error decoding subfield ReqNsapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1619, (Destin->ReqNsapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1620> Message too short decoding subfield ReqNsapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1619, (Destin->ReqNsapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReqLlcSapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Destin->ReqLlcSapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1621> Error decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1621, (Destin->ReqLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1622> Message too short decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1621, (Destin->ReqLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReqQos
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1623> Size error decoding IE ReqQos\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1623, (Destin->ReqQos))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, (&(Destin->ReqQos)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1624> Error decoding subfield ReqQos\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1624, (Destin->ReqQos))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1625> Message too short decoding subfield ReqQos\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1624, (Destin->ReqQos))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReqPdpAddr
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 176)) {
		ED_SIGNAL_ERROR ("<ERRID:1626> Size error decoding IE ReqPdpAddr\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1626, (Destin->ReqPdpAddr))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PacketDataProtocolAddr (Buffer, CurrOfs, (&(Destin->ReqPdpAddr)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1627> Error decoding subfield ReqPdpAddr\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1627, (Destin->ReqPdpAddr))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1628> Message too short decoding subfield ReqPdpAddr\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1627, (Destin->ReqPdpAddr))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AccessPointName
	------------------------------------------------------*/
	/* Detect IEI tag 0x28 */
	ED_EXPECT_OPTIONAL_IE (0x28,  8, 1629, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x28) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 800)) {
			ED_SIGNAL_ERROR ("<ERRID:1630> Size error decoding IE AccessPointName\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x28, 1630, (Destin->AccessPointName))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ASCII (Buffer, CurrOfs, Destin->AccessPointName, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1631> Error decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x28, 1631, (Destin->AccessPointName))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1632> Message too short decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x28, 1631, (Destin->AccessPointName))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolCfgOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1633, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1634> Size error decoding IE ProtocolCfgOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1634, (Destin->ProtocolCfgOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolCfgOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1635> Error decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1635, (Destin->ProtocolCfgOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1636> Message too short decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1635, (Destin->ProtocolCfgOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RequestType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0A */
	ED_EXPECT_OPTIONAL_IE (0x0A,  4, 1637, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RequestType = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17747=EDCore::TDMOctet) */Destin->RequestType___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1638> Error decoding subfield RequestType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0A, 1638, (Destin->RequestType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1639> Message too short decoding subfield RequestType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0A, 1638, (Destin->RequestType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1640, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1641> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1641, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1642> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1641, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1643, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1644> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1644, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17751=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
			if (Destin->NBIFOMContainer->value) {
				EDCopyBits (Destin->NBIFOMContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NBIFOMContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NBIFOMContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1645> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1645, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1646> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1645, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 77, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ReqNsapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ReqNsapi> DOT=<.> */
		Len = ENCODE_c_NetwkServAccessPointId (Buffer, CurrOfs, (&(Source->ReqNsapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1647> Error encoding subfield ReqNsapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ReqLlcSapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ReqLlcSapi> DOT=<.> */
		Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Source->ReqLlcSapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1648> Error encoding subfield ReqLlcSapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ReqQos */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ReqQos> DOT=<.> */
		Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, (&(Source->ReqQos)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1649> Error encoding subfield ReqQos\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for LinkedTi */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->LinkedTi> DOT=<.> */
		Len = ENCODE_c_LinkedTi (Buffer, CurrOfs+8, (&(Source->LinkedTi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1650> Error encoding subfield LinkedTi\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for Tft */
	{
		int TLV_Base = CurrOfs;
		if (Source->Tft_Present) {
			/* Append to buffer IEI tag 0x36 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x36), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->Tft> DOT=<->> */
			Len = ENCODE_c_TrafficFlowTemplate (Buffer, CurrOfs+8, Source->Tft);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1651> Error encoding subfield Tft\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProtocolConfigOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1652> Error encoding subfield ProtocolConfigOpt\n");
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
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1653> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NBIFOMContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NBIFOMContainer_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NBIFOMContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NBIFOMContainer->value, 0, Source->NBIFOMContainer->usedBits);
			Len = Source->NBIFOMContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1654> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{54, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ReqNsapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NetwkServAccessPointId (Buffer, CurrOfs, (&(Destin->ReqNsapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1655> Error decoding subfield ReqNsapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1655, (Destin->ReqNsapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1656> Message too short decoding subfield ReqNsapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1655, (Destin->ReqNsapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReqLlcSapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Destin->ReqLlcSapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1657> Error decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1657, (Destin->ReqLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1658> Message too short decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1657, (Destin->ReqLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReqQos
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1659> Size error decoding IE ReqQos\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1659, (Destin->ReqQos))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, (&(Destin->ReqQos)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1660> Error decoding subfield ReqQos\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1660, (Destin->ReqQos))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1661> Message too short decoding subfield ReqQos\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1660, (Destin->ReqQos))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE LinkedTi
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 16)) {
		ED_SIGNAL_ERROR ("<ERRID:1662> Size error decoding IE LinkedTi\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1662, (Destin->LinkedTi))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LinkedTi (Buffer, CurrOfs, (&(Destin->LinkedTi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1663> Error decoding subfield LinkedTi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1663, (Destin->LinkedTi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1664> Message too short decoding subfield LinkedTi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1663, (Destin->LinkedTi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Tft
	------------------------------------------------------*/
	/* Detect IEI tag 0x36 */
	ED_EXPECT_OPTIONAL_IE (0x36,  8, 1665, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x36) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 2040) {
			ED_SIGNAL_ERROR ("<ERRID:1666> Size error decoding IE Tft\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x36, 1666, (Destin->Tft))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TrafficFlowTemplate (Buffer, CurrOfs, Destin->Tft, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1667> Error decoding subfield Tft\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x36, 1667, (Destin->Tft))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1668> Message too short decoding subfield Tft\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x36, 1667, (Destin->Tft))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1669, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1670> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1670, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1671> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1671, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1672> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1671, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1673, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1674> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1674, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1675> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1674, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1676, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1677> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1677, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17772=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
			if (Destin->NBIFOMContainer->value) {
				EDCopyBits (Destin->NBIFOMContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NBIFOMContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NBIFOMContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1678> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1678, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1679> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1678, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (char* Buffer, ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 69, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1680> Error encoding subfield SmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolConfigOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1681> Error encoding subfield ProtocolConfigOpt\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NBIFOMContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NBIFOMContainer_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NBIFOMContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NBIFOMContainer->value, 0, Source->NBIFOMContainer->usedBits);
			Len = Source->NBIFOMContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1682> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE SmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_SMCause (Buffer, CurrOfs, (&(Destin->SmCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1683> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1683, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1684> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1683, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1685, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1686> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1686, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1687> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1687, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1688> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1687, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1689, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1690> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1690, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17783=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
			if (Destin->NBIFOMContainer->value) {
				EDCopyBits (Destin->NBIFOMContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NBIFOMContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NBIFOMContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1691> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1691, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1692> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1691, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_UP* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 74, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ReqLlcSapi */
	{
		if (Source->ReqLlcSapi_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->ReqLlcSapi> DOT=<->> */
			Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, Source->ReqLlcSapi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1693> Error encoding subfield ReqLlcSapi\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ReqNewQos */
	{
		int TLV_Base = CurrOfs;
		if (Source->ReqNewQos_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ReqNewQos> DOT=<->> */
			Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, Source->ReqNewQos);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1694> Error encoding subfield ReqNewQos\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NewTft */
	{
		int TLV_Base = CurrOfs;
		if (Source->NewTft_Present) {
			/* Append to buffer IEI tag 0x31 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x31), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NewTft> DOT=<->> */
			Len = ENCODE_c_TrafficFlowTemplate (Buffer, CurrOfs+8, Source->NewTft);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1695> Error encoding subfield NewTft\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProtocolConfigOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1696> Error encoding subfield ProtocolConfigOpt\n");
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
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1697> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NBIFOMContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NBIFOMContainer_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NBIFOMContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NBIFOMContainer->value, 0, Source->NBIFOMContainer->usedBits);
			Len = Source->NBIFOMContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1698> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_UP (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{48, 255, ED_SKIPLIST_OPTIONAL},
		{49, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ReqLlcSapi
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 1699, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, Destin->ReqLlcSapi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1700> Error decoding subfield ReqLlcSapi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 1700, (Destin->ReqLlcSapi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1701> Message too short decoding subfield ReqLlcSapi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 1700, (Destin->ReqLlcSapi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReqNewQos
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 1702, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:1703> Size error decoding IE ReqNewQos\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 1703, (Destin->ReqNewQos))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, Destin->ReqNewQos, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1704> Error decoding subfield ReqNewQos\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 1704, (Destin->ReqNewQos))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1705> Message too short decoding subfield ReqNewQos\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 1704, (Destin->ReqNewQos))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NewTft
	------------------------------------------------------*/
	/* Detect IEI tag 0x31 */
	ED_EXPECT_OPTIONAL_IE (0x31,  8, 1706, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x31) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 2040) {
			ED_SIGNAL_ERROR ("<ERRID:1707> Size error decoding IE NewTft\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x31, 1707, (Destin->NewTft))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TrafficFlowTemplate (Buffer, CurrOfs, Destin->NewTft, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1708> Error decoding subfield NewTft\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x31, 1708, (Destin->NewTft))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1709> Message too short decoding subfield NewTft\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x31, 1708, (Destin->NewTft))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1710, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1711> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1711, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1712> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1712, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1713> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1712, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1714, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1715> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1715, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1716> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1715, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1717, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1718> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1718, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17800=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
			if (Destin->NBIFOMContainer->value) {
				EDCopyBits (Destin->NBIFOMContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NBIFOMContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NBIFOMContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1719> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1719, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1720> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1719, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_UP* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 73, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ProtocolConfigOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1721> Error encoding subfield ProtocolConfigOpt\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NBIFOMContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NBIFOMContainer_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NBIFOMContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NBIFOMContainer->value, 0, Source->NBIFOMContainer->usedBits);
			Len = Source->NBIFOMContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1722> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length))
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
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1723, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1724> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1724, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1725> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1725, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1726> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1725, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1727, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1728> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1728, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17809=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
			if (Destin->NBIFOMContainer->value) {
				EDCopyBits (Destin->NBIFOMContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NBIFOMContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NBIFOMContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1729> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1729, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1730> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1729, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_DEACTIVATE_PDP_CONTEXT_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 70, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1731> Error encoding subfield SmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for TearDownInd */
	{
		if (Source->TearDownInd_Present) {
			/* Append to buffer IEI tag 0x09 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x09), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->TearDownInd> DOT=<->> */
			Len = ENCODE_c_TearDownInd (Buffer, CurrOfs, Source->TearDownInd);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1732> Error encoding subfield TearDownInd\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ProtocolConfigOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1733> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1734> Error encoding subfield MBMSContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3396Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3396Value_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3396Value> DOT=<->> */
			Len = ENCODE_c_GprsTimer3 (Buffer, CurrOfs+8, Source->T3396Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1735> Error encoding subfield T3396Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for WLANOffloadIndication */
	{
		if (Source->WLANOffloadIndication_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->WLANOffloadIndication> DOT=<->> */
			Len = ENCODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Source->WLANOffloadIndication);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1736> Error encoding subfield WLANOffloadIndication\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_PDP_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DEACTIVATE_PDP_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_PDP_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DEACTIVATE_PDP_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_PDP_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_DEACTIVATE_PDP_CONTEXT_REQUEST (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DEACTIVATE_PDP_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_PDP_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{144, 240, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE SmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_SMCause (Buffer, CurrOfs, (&(Destin->SmCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1737> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1737, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1738> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1737, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TearDownInd
	------------------------------------------------------*/
	/* Detect IEI tag 0x09 */
	ED_EXPECT_OPTIONAL_IE (0x09,  4, 1739, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x09) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TearDownInd (Buffer, CurrOfs, Destin->TearDownInd, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1740> Error decoding subfield TearDownInd\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x09, 1740, (Destin->TearDownInd))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1741> Message too short decoding subfield TearDownInd\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x09, 1740, (Destin->TearDownInd))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1742, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1743> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1743, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1744> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1744, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1745> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1744, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 1746, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:1747> Size error decoding IE MBMSContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 1747, (Destin->MBMSContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17822=EDCore::TDMBinary) */Destin->MBMSContextStatus___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (Destin->MBMSContextStatus, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1748> Error decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 1748, (Destin->MBMSContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1749> Message too short decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 1748, (Destin->MBMSContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3396Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1750, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1751> Size error decoding IE T3396Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1751, (Destin->T3396Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3396Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1752> Error decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1752, (Destin->T3396Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1753> Message too short decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1752, (Destin->T3396Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1754, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1755> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1755, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1756> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1755, (Destin->WLANOffloadIndication))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_DEACTIVATE_PDP_CONTEXT_ACCEPT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 71, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ProtocolConfigOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1757> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1758> Error encoding subfield MBMSContextStatus\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_PDP_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_PDP_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_PDP_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_PDP_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_PDP_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1759, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1760> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1760, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1761> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1761, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1762> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1761, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 1763, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 128) {
			ED_SIGNAL_ERROR ("<ERRID:1764> Size error decoding IE MBMSContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 1764, (Destin->MBMSContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17835=EDCore::TDMBinary) */Destin->MBMSContextStatus___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (Destin->MBMSContextStatus, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1765> Error decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 1765, (Destin->MBMSContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1766> Message too short decoding subfield MBMSContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 1765, (Destin->MBMSContextStatus))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 92, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1767> Error encoding subfield SmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolCfgOpt */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolCfgOpt_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolCfgOpt> DOT=<->> */
			Len = ENCODE_c_ProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolCfgOpt);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1768> Error encoding subfield ProtocolCfgOpt\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NBIFOMContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NBIFOMContainer_Present) {
			/* Append to buffer IEI tag 0x33 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x33), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NBIFOMContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NBIFOMContainer->value, 0, Source->NBIFOMContainer->usedBits);
			Len = Source->NBIFOMContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1769> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE SmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_SMCause (Buffer, CurrOfs, (&(Destin->SmCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1770> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1770, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1771> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1770, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolCfgOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1772, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1773> Size error decoding IE ProtocolCfgOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1773, (Destin->ProtocolCfgOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolCfgOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1774> Error decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1774, (Destin->ProtocolCfgOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1775> Message too short decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1774, (Destin->ProtocolCfgOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1776, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1777> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1777, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17846=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
			if (Destin->NBIFOMContainer->value) {
				EDCopyBits (Destin->NBIFOMContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NBIFOMContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NBIFOMContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1778> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1778, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1779> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1778, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SM_STATUS
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SM_STATUS (char* Buffer, ED_EXLONG BitOffset, const c_SM_STATUS* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 85, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1780> Error encoding subfield SmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_SM_STATUS (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_SM_STATUS (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SM_STATUS* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_SM_STATUS (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SM_STATUS* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE SmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_SMCause (Buffer, CurrOfs, (&(Destin->SmCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1781> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1781, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1782> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1781, (Destin->SmCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 86, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ReqMbmsNsapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ReqMbmsNsapi> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ReqMbmsNsapi), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1783> Error encoding subfield ReqMbmsNsapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ReqLlcSapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ReqLlcSapi> DOT=<.> */
		Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Source->ReqLlcSapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1784> Error encoding subfield ReqLlcSapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SupportedMBMSBearerCapabilities */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->SupportedMBMSBearerCapabilities> DOT=<.> */
		Len = ENCODE_c_MBMSBearerCapabilities (Buffer, CurrOfs+8, (&(Source->SupportedMBMSBearerCapabilities)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1785> Error encoding subfield SupportedMBMSBearerCapabilities\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RequestedMulticastAddress */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->RequestedMulticastAddress> DOT=<.> */
		Len = ENCODE_c_PacketDataProtocolAddr (Buffer, CurrOfs+8, (&(Source->RequestedMulticastAddress)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1786> Error encoding subfield RequestedMulticastAddress\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for AccessPointName */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->AccessPointName> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, Source->AccessPointName.value, 0, Source->AccessPointName.usedBits);
		Len = Source->AccessPointName.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1787> Error encoding subfield AccessPointName\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for MBMSProtocolConfigOpts */
	{
		int TLV_Base = CurrOfs;
		if (Source->MBMSProtocolConfigOpts_Present) {
			/* Append to buffer IEI tag 0x35 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x35), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MBMSProtocolConfigOpts> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->MBMSProtocolConfigOpts->value, 0, Source->MBMSProtocolConfigOpts->usedBits);
			Len = Source->MBMSProtocolConfigOpts->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1788> Error encoding subfield MBMSProtocolConfigOpts\n");
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
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->DeviceProperties> DOT=<->> */
			Len = ENCODE_c_DeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1789> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_MBMS_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REQUEST (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ReqMbmsNsapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ReqMbmsNsapi = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17860=EDCore::TDMInteger) */Destin->ReqMbmsNsapi___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1790> Error decoding subfield ReqMbmsNsapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1790, (Destin->ReqMbmsNsapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1791> Message too short decoding subfield ReqMbmsNsapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1790, (Destin->ReqMbmsNsapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReqLlcSapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Destin->ReqLlcSapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1792> Error decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1792, (Destin->ReqLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1793> Message too short decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1792, (Destin->ReqLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedMBMSBearerCapabilities
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 16)) {
		ED_SIGNAL_ERROR ("<ERRID:1794> Size error decoding IE SupportedMBMSBearerCapabilities\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1794, (Destin->SupportedMBMSBearerCapabilities))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_MBMSBearerCapabilities (Buffer, CurrOfs, (&(Destin->SupportedMBMSBearerCapabilities)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1795> Error decoding subfield SupportedMBMSBearerCapabilities\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1795, (Destin->SupportedMBMSBearerCapabilities))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1796> Message too short decoding subfield SupportedMBMSBearerCapabilities\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1795, (Destin->SupportedMBMSBearerCapabilities))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RequestedMulticastAddress
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 176)) {
		ED_SIGNAL_ERROR ("<ERRID:1797> Size error decoding IE RequestedMulticastAddress\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1797, (Destin->RequestedMulticastAddress))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PacketDataProtocolAddr (Buffer, CurrOfs, (&(Destin->RequestedMulticastAddress)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1798> Error decoding subfield RequestedMulticastAddress\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1798, (Destin->RequestedMulticastAddress))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1799> Message too short decoding subfield RequestedMulticastAddress\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1798, (Destin->RequestedMulticastAddress))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AccessPointName
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 800)) {
		ED_SIGNAL_ERROR ("<ERRID:1800> Size error decoding IE AccessPointName\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1800, (Destin->AccessPointName))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17868=EDCore::TDMBinary) */Destin->AccessPointName___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName (&(Destin->AccessPointName), Len);
	
		if (Destin->AccessPointName.value) {
			EDCopyBits (Destin->AccessPointName.value, 0, Buffer, CurrOfs, Len);
			Destin->AccessPointName.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->AccessPointName.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1801> Error decoding subfield AccessPointName\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1801, (Destin->AccessPointName))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1802> Message too short decoding subfield AccessPointName\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1801, (Destin->AccessPointName))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSProtocolConfigOpts
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 1803, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1804> Size error decoding IE MBMSProtocolConfigOpts\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 1804, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17870=EDCore::TDMBinary) */Destin->MBMSProtocolConfigOpts___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (Destin->MBMSProtocolConfigOpts, Len);
		
			if (Destin->MBMSProtocolConfigOpts->value) {
				EDCopyBits (Destin->MBMSProtocolConfigOpts->value, 0, Buffer, CurrOfs, Len);
				Destin->MBMSProtocolConfigOpts->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->MBMSProtocolConfigOpts->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1805> Error decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 1805, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1806> Message too short decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 1805, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1807, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_DeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1808> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1808, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1809> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1808, (Destin->DeviceProperties))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode extended transaction identifier (if < 7) */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->TI_Flag, 1);
		if (Source->TI_Value <= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 3);
		}
		else {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, 7, 3);
		}
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 10, 4);
		CurrOfs += 4;
		/* Encode extended transaction identifier (if >= 7) */
		if (Source->TI_Value >= 7) {
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 1, 1); /* 1ext bit must be set to 1 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs+1, Source->TI_Value, 7);
			CurrOfs += 8;
		}

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 90, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1810> Error encoding subfield SmCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MBMSProtocolConfigOpts */
	{
		int TLV_Base = CurrOfs;
		if (Source->MBMSProtocolConfigOpts_Present) {
			/* Append to buffer IEI tag 0x35 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x35), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MBMSProtocolConfigOpts> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->MBMSProtocolConfigOpts->value, 0, Source->MBMSProtocolConfigOpts->usedBits);
			Len = Source->MBMSProtocolConfigOpts->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1811> Error encoding subfield MBMSProtocolConfigOpts\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0, TransId, ExtraLen=0;
		/* Decode transaction idenfier */
	TransId = EDBitsToInt (Buffer, BitOffset+1, 3);
		/* Decode transaction idenfier */
	if (TransId == 7) {
		ExtraLen = 8;
		TransId = EDBitsToInt (Buffer, BitOffset+9, 7);
		while (EDBitsToInt (Buffer, BitOffset+ExtraLen, 1) == 0) ExtraLen += 8;
	}
	
	
	Len = DECODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE SmCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_SMCause (Buffer, CurrOfs, (&(Destin->SmCause)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1812> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1812, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1813> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1812, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSProtocolConfigOpts
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 1814, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1815> Size error decoding IE MBMSProtocolConfigOpts\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 1815, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17881=EDCore::TDMBinary) */Destin->MBMSProtocolConfigOpts___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (Destin->MBMSProtocolConfigOpts, Len);
		
			if (Destin->MBMSProtocolConfigOpts->value) {
				EDCopyBits (Destin->MBMSProtocolConfigOpts->value, 0, Buffer, CurrOfs, Len);
				Destin->MBMSProtocolConfigOpts->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->MBMSProtocolConfigOpts->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1816> Error decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 1816, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1817> Message too short decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 1816, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 65) /* message type */
		);
}

int Match_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 77) /* message type */
		);
}

int Match_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 69) /* message type */
		);
}

int Match_c_MODIFY_PDP_CONTEXT_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 74) /* message type */
		);
}

int Match_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 73) /* message type */
		);
}

int Match_c_DEACTIVATE_PDP_CONTEXT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 70) /* message type */
		);
}

int Match_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 71) /* message type */
		);
}

int Match_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 92) /* message type */
		);
}

int Match_c_SM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 85) /* message type */
		);
}

int Match_c_ACTIVATE_MBMS_CONTEXT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 86) /* message type */
		);
}

int Match_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 90) /* message type */
		);
}

