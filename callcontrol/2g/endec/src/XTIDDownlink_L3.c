/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "XTIDDownlink_L3.h"
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 66, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NegotiatedLlcSapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLlcSapi> DOT=<.> */
		Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Source->NegotiatedLlcSapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1818> Error encoding subfield NegotiatedLlcSapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NegotiatedQos */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedQos> DOT=<.> */
		Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, (&(Source->NegotiatedQos)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1819> Error encoding subfield NegotiatedQos\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RadioPriority */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RadioPriority> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->RadioPriority), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1820> Error encoding subfield RadioPriority\n");
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
			ED_SIGNAL_ERROR ("<ERRID:1821> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PdpAddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->PdpAddr_Present) {
			/* Append to buffer IEI tag 0x2B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PdpAddr> DOT=<->> */
			Len = ENCODE_c_PacketDataProtocolAddr (Buffer, CurrOfs+8, Source->PdpAddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1822> Error encoding subfield PdpAddr\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1823> Error encoding subfield ProtocolCfgOpt\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PacketFlowId */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowId_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowId> DOT=<->> */
			Len = ENCODE_c_PacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1824> Error encoding subfield PacketFlowId\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SMCause */
	{
		int TLV_Base = CurrOfs;
		if (Source->SMCause_Present) {
			/* Append to buffer IEI tag 0x39 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x39), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->SMCause> DOT=<->> */
			Len = ENCODE_c_SMCause (Buffer, CurrOfs+8, Source->SMCause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1825> Error encoding subfield SMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ConnectivityType */
	{
		if (Source->ConnectivityType_Present) {
			/* Append to buffer IEI tag 0x0B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0B), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ConnectivityType> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ConnectivityType), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1826> Error encoding subfield ConnectivityType\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
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
				ED_SIGNAL_ERROR ("<ERRID:1827> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1828> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{43, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{57, 255, ED_SKIPLIST_OPTIONAL},
		{176, 240, ED_SKIPLIST_OPTIONAL},
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
		Code for IE NegotiatedLlcSapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Destin->NegotiatedLlcSapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1829> Error decoding subfield NegotiatedLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1829, (Destin->NegotiatedLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1830> Message too short decoding subfield NegotiatedLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1829, (Destin->NegotiatedLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedQos
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1831> Size error decoding IE NegotiatedQos\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1831, (Destin->NegotiatedQos))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, (&(Destin->NegotiatedQos)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1832> Error decoding subfield NegotiatedQos\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1832, (Destin->NegotiatedQos))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1833> Message too short decoding subfield NegotiatedQos\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1832, (Destin->NegotiatedQos))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RadioPriority
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->RadioPriority = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17893=EDCore::TDMInteger) */Destin->RadioPriority___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1834> Error decoding subfield RadioPriority\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1834, (Destin->RadioPriority))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1835> Message too short decoding subfield RadioPriority\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1834, (Destin->RadioPriority))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17895=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1836> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1836, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1837> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1836, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PdpAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x2B */
	ED_EXPECT_OPTIONAL_IE (0x2B,  8, 1838, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 176)) {
			ED_SIGNAL_ERROR ("<ERRID:1839> Size error decoding IE PdpAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2B, 1839, (Destin->PdpAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PacketDataProtocolAddr (Buffer, CurrOfs, Destin->PdpAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1840> Error decoding subfield PdpAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2B, 1840, (Destin->PdpAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1841> Message too short decoding subfield PdpAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2B, 1840, (Destin->PdpAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolCfgOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1842, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1843> Size error decoding IE ProtocolCfgOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1843, (Destin->ProtocolCfgOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolCfgOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1844> Error decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1844, (Destin->ProtocolCfgOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1845> Message too short decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1844, (Destin->ProtocolCfgOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowId
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1846, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1847> Size error decoding IE PacketFlowId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1847, (Destin->PacketFlowId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1848> Error decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1848, (Destin->PacketFlowId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1849> Message too short decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1848, (Destin->PacketFlowId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x39 */
	ED_EXPECT_OPTIONAL_IE (0x39,  8, 1850, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x39) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1851> Size error decoding IE SMCause\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x39, 1851, (Destin->SMCause))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_SMCause (Buffer, CurrOfs, Destin->SMCause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1852> Error decoding subfield SMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x39, 1852, (Destin->SMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1853> Message too short decoding subfield SMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x39, 1852, (Destin->SMCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ConnectivityType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0B */
	ED_EXPECT_OPTIONAL_IE (0x0B,  4, 1854, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->ConnectivityType = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-17905=EDCore::TDMOctet) */Destin->ConnectivityType___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1855> Error decoding subfield ConnectivityType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0B, 1855, (Destin->ConnectivityType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1856> Message too short decoding subfield ConnectivityType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0B, 1855, (Destin->ConnectivityType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1857, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1858> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1858, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1859> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1858, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1860, 10, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1861> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1861, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17909=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1862> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1862, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1863> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1862, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REJECT_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 67, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1864> Error encoding subfield SmCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1865> Error encoding subfield ProtocolCfgOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1866> Error encoding subfield T3396Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ReAttemptIndicator */
	{
		int TLV_Base = CurrOfs;
		if (Source->ReAttemptIndicator_Present) {
			/* Append to buffer IEI tag 0x6B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ReAttemptIndicator> DOT=<->> */
			Len = ENCODE_c_ReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1867> Error encoding subfield ReAttemptIndicator\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1868> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{107, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:1869> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1869, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1870> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1869, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolCfgOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1871, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1872> Size error decoding IE ProtocolCfgOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1872, (Destin->ProtocolCfgOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolCfgOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1873> Error decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1873, (Destin->ProtocolCfgOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1874> Message too short decoding subfield ProtocolCfgOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1873, (Destin->ProtocolCfgOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3396Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1875, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1876> Size error decoding IE T3396Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1876, (Destin->T3396Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3396Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1877> Error decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1877, (Destin->T3396Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1878> Message too short decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1877, (Destin->T3396Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 1879, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1880> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 1880, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1881> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 1881, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1882> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 1881, (Destin->ReAttemptIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1883, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1884> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1884, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17924=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1885> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1885, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1886> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1885, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 78, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NegotiatedLlcSapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLlcSapi> DOT=<.> */
		Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Source->NegotiatedLlcSapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1887> Error encoding subfield NegotiatedLlcSapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NegotiatedQos */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedQos> DOT=<.> */
		Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, (&(Source->NegotiatedQos)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1888> Error encoding subfield NegotiatedQos\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RadioPriority */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RadioPriority> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->RadioPriority), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1889> Error encoding subfield RadioPriority\n");
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
			ED_SIGNAL_ERROR ("<ERRID:1890> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PacketFlowId */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowId_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowId> DOT=<->> */
			Len = ENCODE_c_PacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1891> Error encoding subfield PacketFlowId\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1892> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1893> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1894> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{52, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE NegotiatedLlcSapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Destin->NegotiatedLlcSapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1895> Error decoding subfield NegotiatedLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1895, (Destin->NegotiatedLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1896> Message too short decoding subfield NegotiatedLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1895, (Destin->NegotiatedLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedQos
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1897> Size error decoding IE NegotiatedQos\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1897, (Destin->NegotiatedQos))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, (&(Destin->NegotiatedQos)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1898> Error decoding subfield NegotiatedQos\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1898, (Destin->NegotiatedQos))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1899> Message too short decoding subfield NegotiatedQos\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1898, (Destin->NegotiatedQos))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RadioPriority
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->RadioPriority = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17935=EDCore::TDMInteger) */Destin->RadioPriority___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1900> Error decoding subfield RadioPriority\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1900, (Destin->RadioPriority))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1901> Message too short decoding subfield RadioPriority\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1900, (Destin->RadioPriority))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17937=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1902> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1902, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1903> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1902, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowId
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1904, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1905> Size error decoding IE PacketFlowId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1905, (Destin->PacketFlowId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1906> Error decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1906, (Destin->PacketFlowId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1907> Message too short decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1906, (Destin->PacketFlowId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1908, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1909> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1909, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1910> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1910, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1911> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1910, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1912, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1913> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1913, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1914> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1913, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1915, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1916> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1916, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17945=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1917> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1917, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1918> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1917, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 79, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1919> Error encoding subfield SmCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1920> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1921> Error encoding subfield T3396Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ReAttemptIndicator */
	{
		int TLV_Base = CurrOfs;
		if (Source->ReAttemptIndicator_Present) {
			/* Append to buffer IEI tag 0x6B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ReAttemptIndicator> DOT=<->> */
			Len = ENCODE_c_ReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1922> Error encoding subfield ReAttemptIndicator\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1923> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{107, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:1924> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1924, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1925> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1924, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1926, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1927> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1927, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1928> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1928, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1929> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1928, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3396Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1930, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1931> Size error decoding IE T3396Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1931, (Destin->T3396Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3396Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1932> Error decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1932, (Destin->T3396Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1933> Message too short decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1932, (Destin->T3396Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 1934, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1935> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 1935, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1936> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 1936, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1937> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 1936, (Destin->ReAttemptIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1938, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1939> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1939, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17960=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1940> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1940, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1941> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1940, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (char* Buffer, ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 68, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for OfferedPdpAddr */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->OfferedPdpAddr> DOT=<.> */
		Len = ENCODE_c_PacketDataProtocolAddr (Buffer, CurrOfs+8, (&(Source->OfferedPdpAddr)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1942> Error encoding subfield OfferedPdpAddr\n");
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
			EDCopyBits (Buffer, CurrOfs+8, Source->AccessPointName->value, 0, Source->AccessPointName->usedBits);
			Len = Source->AccessPointName->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1943> Error encoding subfield AccessPointName\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1944> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1945> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_PDP_CONTEXT_ACTIVATION_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{40, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE OfferedPdpAddr
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 176)) {
		ED_SIGNAL_ERROR ("<ERRID:1946> Size error decoding IE OfferedPdpAddr\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1946, (Destin->OfferedPdpAddr))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PacketDataProtocolAddr (Buffer, CurrOfs, (&(Destin->OfferedPdpAddr)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1947> Error decoding subfield OfferedPdpAddr\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1947, (Destin->OfferedPdpAddr))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1948> Message too short decoding subfield OfferedPdpAddr\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1947, (Destin->OfferedPdpAddr))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AccessPointName
	------------------------------------------------------*/
	/* Detect IEI tag 0x28 */
	ED_EXPECT_OPTIONAL_IE (0x28,  8, 1949, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x28) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 800)) {
			ED_SIGNAL_ERROR ("<ERRID:1950> Size error decoding IE AccessPointName\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x28, 1950, (Destin->AccessPointName))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17969=EDCore::TDMBinary) */Destin->AccessPointName___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (Destin->AccessPointName, Len);
		
			if (Destin->AccessPointName->value) {
				EDCopyBits (Destin->AccessPointName->value, 0, Buffer, CurrOfs, Len);
				Destin->AccessPointName->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->AccessPointName->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1951> Error decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x28, 1951, (Destin->AccessPointName))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1952> Message too short decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x28, 1951, (Destin->AccessPointName))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1953, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1954> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1954, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1955> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1955, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1956> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1955, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1957, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1958> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1958, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17973=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1959> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1959, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1960> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1959, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 72, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for RadioPriority */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RadioPriority> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->RadioPriority), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1961> Error encoding subfield RadioPriority\n");
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
			ED_SIGNAL_ERROR ("<ERRID:1962> Error encoding subfield SpareHalfOctet\n");
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
			ED_SIGNAL_ERROR ("<ERRID:1963> Error encoding subfield ReqLlcSapi\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NewQos */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->NewQos> DOT=<.> */
		Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, (&(Source->NewQos)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1964> Error encoding subfield NewQos\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for PdpAddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->PdpAddr_Present) {
			/* Append to buffer IEI tag 0x2B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x2B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PdpAddr> DOT=<->> */
			Len = ENCODE_c_PacketDataProtocolAddr (Buffer, CurrOfs+8, Source->PdpAddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1965> Error encoding subfield PdpAddr\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for PacketFlowId */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowId_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowId> DOT=<->> */
			Len = ENCODE_c_PacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1966> Error encoding subfield PacketFlowId\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1967> Error encoding subfield ProtocolConfigOpt\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
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
				ED_SIGNAL_ERROR ("<ERRID:1968> Error encoding subfield Tft\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1969> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1970> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{43, 255, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{54, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE RadioPriority
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->RadioPriority = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17980=EDCore::TDMInteger) */Destin->RadioPriority___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1971> Error decoding subfield RadioPriority\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1971, (Destin->RadioPriority))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1972> Message too short decoding subfield RadioPriority\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1971, (Destin->RadioPriority))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-17982=EDCore::TDMInteger) */Destin->SpareHalfOctet___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1973> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1973, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1974> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1973, (Destin->SpareHalfOctet))
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
		ED_SIGNAL_ERROR ("<ERRID:1975> Error decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1975, (Destin->ReqLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1976> Message too short decoding subfield ReqLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1975, (Destin->ReqLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NewQos
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:1977> Size error decoding IE NewQos\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1977, (Destin->NewQos))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, (&(Destin->NewQos)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1978> Error decoding subfield NewQos\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1978, (Destin->NewQos))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1979> Message too short decoding subfield NewQos\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1978, (Destin->NewQos))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PdpAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x2B */
	ED_EXPECT_OPTIONAL_IE (0x2B,  8, 1980, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x2B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 176)) {
			ED_SIGNAL_ERROR ("<ERRID:1981> Size error decoding IE PdpAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x2B, 1981, (Destin->PdpAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PacketDataProtocolAddr (Buffer, CurrOfs, Destin->PdpAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1982> Error decoding subfield PdpAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x2B, 1982, (Destin->PdpAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1983> Message too short decoding subfield PdpAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x2B, 1982, (Destin->PdpAddr))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowId
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1984, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1985> Size error decoding IE PacketFlowId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1985, (Destin->PacketFlowId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1986> Error decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1986, (Destin->PacketFlowId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1987> Message too short decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1986, (Destin->PacketFlowId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1988, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1989> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1989, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1990> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1990, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1991> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1990, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE Tft
	------------------------------------------------------*/
	/* Detect IEI tag 0x36 */
	ED_EXPECT_OPTIONAL_IE (0x36,  8, 1992, 7, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x36) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 2040) {
			ED_SIGNAL_ERROR ("<ERRID:1993> Size error decoding IE Tft\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x36, 1993, (Destin->Tft))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TrafficFlowTemplate (Buffer, CurrOfs, Destin->Tft, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1994> Error decoding subfield Tft\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x36, 1994, (Destin->Tft))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1995> Message too short decoding subfield Tft\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x36, 1994, (Destin->Tft))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1996, 8, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1997> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1997, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1998> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1997, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1999, 9, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:2000> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 2000, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-17998=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2001> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 2001, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2002> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 2001, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 75, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NegotiatedQos */
	{
		int TLV_Base = CurrOfs;
		if (Source->NegotiatedQos_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedQos> DOT=<->> */
			Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, Source->NegotiatedQos);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2003> Error encoding subfield NegotiatedQos\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedLlcSapi */
	{
		if (Source->NegotiatedLlcSapi_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLlcSapi> DOT=<->> */
			Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, Source->NegotiatedLlcSapi);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2004> Error encoding subfield NegotiatedLlcSapi\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NewRadioPriority */
	{
		if (Source->NewRadioPriority_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->NewRadioPriority> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->NewRadioPriority), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2005> Error encoding subfield NewRadioPriority\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PacketFlowId */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowId_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowId> DOT=<->> */
			Len = ENCODE_c_PacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2006> Error encoding subfield PacketFlowId\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2007> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2008> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2009> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{48, 255, ED_SKIPLIST_OPTIONAL},
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE NegotiatedQos
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 2010, 0, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:2011> Size error decoding IE NegotiatedQos\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 2011, (Destin->NegotiatedQos))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, Destin->NegotiatedQos, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2012> Error decoding subfield NegotiatedQos\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 2012, (Destin->NegotiatedQos))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2013> Message too short decoding subfield NegotiatedQos\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 2012, (Destin->NegotiatedQos))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedLlcSapi
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 2014, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, Destin->NegotiatedLlcSapi, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2015> Error decoding subfield NegotiatedLlcSapi\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 2015, (Destin->NegotiatedLlcSapi))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2016> Message too short decoding subfield NegotiatedLlcSapi\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 2015, (Destin->NegotiatedLlcSapi))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NewRadioPriority
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 2017, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->NewRadioPriority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-18009=EDCore::TDMInteger) */Destin->NewRadioPriority___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2018> Error decoding subfield NewRadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 2018, (Destin->NewRadioPriority))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2019> Message too short decoding subfield NewRadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 2018, (Destin->NewRadioPriority))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowId
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 2020, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:2021> Size error decoding IE PacketFlowId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 2021, (Destin->PacketFlowId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2022> Error decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 2022, (Destin->PacketFlowId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2023> Message too short decoding subfield PacketFlowId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 2022, (Destin->PacketFlowId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 2024, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:2025> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 2025, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2026> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 2026, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2027> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 2026, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 2028, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2029> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 2029, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2030> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 2029, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 2031, 6, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:2032> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 2032, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18017=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2033> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 2033, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2034> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 2033, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REJECT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REJECT_DN* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 76, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2035> Error encoding subfield SmCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2036> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2037> Error encoding subfield T3396Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ReAttemptIndicator */
	{
		int TLV_Base = CurrOfs;
		if (Source->ReAttemptIndicator_Present) {
			/* Append to buffer IEI tag 0x6B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ReAttemptIndicator> DOT=<->> */
			Len = ENCODE_c_ReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2038> Error encoding subfield ReAttemptIndicator\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2039> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_PDP_CONTEXT_REJECT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_MODIFY_PDP_CONTEXT_REJECT_DN (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_PDP_CONTEXT_REJECT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_PDP_CONTEXT_REJECT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_PDP_CONTEXT_REJECT_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{107, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:2040> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2040, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2041> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2040, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 2042, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:2043> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 2043, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2044> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 2044, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2045> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 2044, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3396Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 2046, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:2047> Size error decoding IE T3396Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 2047, (Destin->T3396Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->T3396Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2048> Error decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 2048, (Destin->T3396Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2049> Message too short decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 2048, (Destin->T3396Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 2050, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:2051> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 2051, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2052> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 2052, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2053> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 2052, (Destin->ReAttemptIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 2054, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:2055> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 2055, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18032=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2056> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 2056, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2057> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 2056, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (char* Buffer, ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 91, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ReqQos */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ReqQos> DOT=<.> */
		Len = ENCODE_c_QualityOfServ (Buffer, CurrOfs+8, (&(Source->ReqQos)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2058> Error encoding subfield ReqQos\n");
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
			ED_SIGNAL_ERROR ("<ERRID:2059> Error encoding subfield LinkedTi\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2060> Error encoding subfield Tft\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2061> Error encoding subfield ProtocolConfigOpt\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2062> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2063> Error encoding subfield NBIFOMContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE ReqQos
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 4792)) {
		ED_SIGNAL_ERROR ("<ERRID:2064> Size error decoding IE ReqQos\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2064, (Destin->ReqQos))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_QualityOfServ (Buffer, CurrOfs, (&(Destin->ReqQos)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2065> Error decoding subfield ReqQos\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2065, (Destin->ReqQos))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2066> Message too short decoding subfield ReqQos\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2065, (Destin->ReqQos))
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
		ED_SIGNAL_ERROR ("<ERRID:2067> Size error decoding IE LinkedTi\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2067, (Destin->LinkedTi))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LinkedTi (Buffer, CurrOfs, (&(Destin->LinkedTi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2068> Error decoding subfield LinkedTi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2068, (Destin->LinkedTi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2069> Message too short decoding subfield LinkedTi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2068, (Destin->LinkedTi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE Tft
	------------------------------------------------------*/
	/* Detect IEI tag 0x36 */
	ED_EXPECT_OPTIONAL_IE (0x36,  8, 2070, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x36) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 2040) {
			ED_SIGNAL_ERROR ("<ERRID:2071> Size error decoding IE Tft\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x36, 2071, (Destin->Tft))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TrafficFlowTemplate (Buffer, CurrOfs, Destin->Tft, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2072> Error decoding subfield Tft\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x36, 2072, (Destin->Tft))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2073> Message too short decoding subfield Tft\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x36, 2072, (Destin->Tft))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigOpt
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 2074, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:2075> Size error decoding IE ProtocolConfigOpt\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 2075, (Destin->ProtocolConfigOpt))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigOpt, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2076> Error decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 2076, (Destin->ProtocolConfigOpt))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2077> Message too short decoding subfield ProtocolConfigOpt\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 2076, (Destin->ProtocolConfigOpt))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 2078, 4, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_WLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2079> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 2079, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2080> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 2079, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 2081, 5, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:2082> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 2082, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18049=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2083> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 2083, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2084> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 2083, (Destin->NBIFOMContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE NOTIFICATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_NOTIFICATION (char* Buffer, ED_EXLONG BitOffset, const c_NOTIFICATION* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 93, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NotificationIndicator */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->NotificationIndicator> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->NotificationIndicator), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2085> Error encoding subfield NotificationIndicator\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFICATION* ED_CONST Source))
{
	return L3_ENCODE_c_NOTIFICATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_NOTIFICATION* ED_CONST Source))
{
	return L3_ENCODE_c_NOTIFICATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_NOTIFICATION (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE NotificationIndicator
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 8) {
		ED_SIGNAL_ERROR ("<ERRID:2086> Size error decoding IE NotificationIndicator\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2086, (Destin->NotificationIndicator))
	} 
#endif
	/* Read value part LOCATOR_16 */
	Destin->NotificationIndicator = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-18056=EDCore::TDMOctet) */Destin->NotificationIndicator___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2087> Error decoding subfield NotificationIndicator\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2087, (Destin->NotificationIndicator))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2088> Message too short decoding subfield NotificationIndicator\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2087, (Destin->NotificationIndicator))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_ACCEPT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 87, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for TempMobileGroupId */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->TempMobileGroupId> DOT=<.> */
		Len = ENCODE_c_TempMobileGroupId (Buffer, CurrOfs+8, (&(Source->TempMobileGroupId)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2089> Error encoding subfield TempMobileGroupId\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for NegotiatedLlcSapi */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLlcSapi> DOT=<.> */
		Len = ENCODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Source->NegotiatedLlcSapi)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2090> Error encoding subfield NegotiatedLlcSapi\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2091> Error encoding subfield MBMSProtocolConfigOpts\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE TempMobileGroupId
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 48)) {
		ED_SIGNAL_ERROR ("<ERRID:2092> Size error decoding IE TempMobileGroupId\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2092, (Destin->TempMobileGroupId))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_TempMobileGroupId (Buffer, CurrOfs, (&(Destin->TempMobileGroupId)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2093> Error decoding subfield TempMobileGroupId\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2093, (Destin->TempMobileGroupId))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2094> Message too short decoding subfield TempMobileGroupId\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2093, (Destin->TempMobileGroupId))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedLlcSapi
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_LlcServAccessPointId (Buffer, CurrOfs, (&(Destin->NegotiatedLlcSapi)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2095> Error decoding subfield NegotiatedLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2095, (Destin->NegotiatedLlcSapi))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2096> Message too short decoding subfield NegotiatedLlcSapi\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2095, (Destin->NegotiatedLlcSapi))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSProtocolConfigOpts
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 2097, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:2098> Size error decoding IE MBMSProtocolConfigOpts\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 2098, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18067=EDCore::TDMBinary) */Destin->MBMSProtocolConfigOpts___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (Destin->MBMSProtocolConfigOpts, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2099> Error decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 2099, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2100> Message too short decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 2099, (Destin->MBMSProtocolConfigOpts))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REJECT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 88, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SmCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SmCause> DOT=<.> */
		Len = ENCODE_c_SMCause (Buffer, CurrOfs, (&(Source->SmCause)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2101> Error encoding subfield SmCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2102> Error encoding subfield MBMSProtocolConfigOpts\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BackOffTimerValue */
	{
		int TLV_Base = CurrOfs;
		if (Source->BackOffTimerValue_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BackOffTimerValue> DOT=<->> */
			Len = ENCODE_c_GprsTimer3 (Buffer, CurrOfs+8, Source->BackOffTimerValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2103> Error encoding subfield BackOffTimerValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ReAttemptIndicator */
	{
		int TLV_Base = CurrOfs;
		if (Source->ReAttemptIndicator_Present) {
			/* Append to buffer IEI tag 0x6B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ReAttemptIndicator> DOT=<->> */
			Len = ENCODE_c_ReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:2104> Error encoding subfield ReAttemptIndicator\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_MBMS_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REJECT (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_MBMS_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_MBMS_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_MBMS_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{55, 255, ED_SKIPLIST_OPTIONAL},
		{107, 255, ED_SKIPLIST_OPTIONAL},
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
		ED_SIGNAL_ERROR ("<ERRID:2105> Error decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2105, (Destin->SmCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2106> Message too short decoding subfield SmCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2105, (Destin->SmCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSProtocolConfigOpts
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 2107, 1, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:2108> Size error decoding IE MBMSProtocolConfigOpts\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 2108, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18076=EDCore::TDMBinary) */Destin->MBMSProtocolConfigOpts___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (Destin->MBMSProtocolConfigOpts, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2109> Error decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 2109, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2110> Message too short decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 2109, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BackOffTimerValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 2111, 2, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:2112> Size error decoding IE BackOffTimerValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 2112, (Destin->BackOffTimerValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GprsTimer3 (Buffer, CurrOfs, Destin->BackOffTimerValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2113> Error decoding subfield BackOffTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 2113, (Destin->BackOffTimerValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2114> Message too short decoding subfield BackOffTimerValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 2113, (Destin->BackOffTimerValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 2115, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:2116> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 2116, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:2117> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 2117, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2118> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 2117, (Destin->ReAttemptIndicator))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (char* Buffer, ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 89, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for LinkedNSAPI */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LinkedNSAPI> DOT=<.> */
		Len = ENCODE_c_NetwkServAccessPointId (Buffer, CurrOfs, (&(Source->LinkedNSAPI)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2119> Error encoding subfield LinkedNSAPI\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for OfferedMulticastAddr */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->OfferedMulticastAddr> DOT=<.> */
		Len = ENCODE_c_PacketDataProtocolAddr (Buffer, CurrOfs+8, (&(Source->OfferedMulticastAddr)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:2120> Error encoding subfield OfferedMulticastAddr\n");
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
			ED_SIGNAL_ERROR ("<ERRID:2121> Error encoding subfield AccessPointName\n");
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
				ED_SIGNAL_ERROR ("<ERRID:2122> Error encoding subfield MBMSProtocolConfigOpts\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Source))
{
	return L3_ENCODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REQUEST_MBMS_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length))
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
	
	
	Len = DECODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION (Buffer, (BitOffset+16+ExtraLen), Destin, Length-(16+ExtraLen));
	if (Len < 0) return Len;
		/* Decode transaction idenfier */
	Destin->TI_Flag = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 1);
	Destin->TI_Value = (ED_OCTET)TransId;
	
	return Len+16+ExtraLen;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REQUEST_MBMS_CONTEXT_ACTIVATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REQUEST_MBMS_CONTEXT_ACTIVATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REQUEST_MBMS_CONTEXT_ACTIVATION* ED_CONST Destin, ED_EXLONG Length))
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
		{53, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE LinkedNSAPI
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NetwkServAccessPointId (Buffer, CurrOfs, (&(Destin->LinkedNSAPI)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2123> Error decoding subfield LinkedNSAPI\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2123, (Destin->LinkedNSAPI))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2124> Message too short decoding subfield LinkedNSAPI\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2123, (Destin->LinkedNSAPI))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OfferedMulticastAddr
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 176)) {
		ED_SIGNAL_ERROR ("<ERRID:2125> Size error decoding IE OfferedMulticastAddr\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2125, (Destin->OfferedMulticastAddr))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PacketDataProtocolAddr (Buffer, CurrOfs, (&(Destin->OfferedMulticastAddr)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:2126> Error decoding subfield OfferedMulticastAddr\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2126, (Destin->OfferedMulticastAddr))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2127> Message too short decoding subfield OfferedMulticastAddr\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2126, (Destin->OfferedMulticastAddr))
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
		ED_SIGNAL_ERROR ("<ERRID:2128> Size error decoding IE AccessPointName\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2128, (Destin->AccessPointName))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18091=EDCore::TDMBinary) */Destin->AccessPointName___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName (&(Destin->AccessPointName), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:2129> Error decoding subfield AccessPointName\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 2129, (Destin->AccessPointName))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:2130> Message too short decoding subfield AccessPointName\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 2129, (Destin->AccessPointName))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MBMSProtocolConfigOpts
	------------------------------------------------------*/
	/* Detect IEI tag 0x35 */
	ED_EXPECT_OPTIONAL_IE (0x35,  8, 2131, 3, KnownL3IEs_L3)
	
	/* This is an optional field */
	if (Tag == 0x35) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:2132> Size error decoding IE MBMSProtocolConfigOpts\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x35, 2132, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-18093=EDCore::TDMBinary) */Destin->MBMSProtocolConfigOpts___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (Destin->MBMSProtocolConfigOpts, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:2133> Error decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x35, 2133, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:2134> Message too short decoding subfield MBMSProtocolConfigOpts\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x35, 2133, (Destin->MBMSProtocolConfigOpts))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 66) /* message type */
		);
}

int Match_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 67) /* message type */
		);
}

int Match_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 78) /* message type */
		);
}

int Match_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 79) /* message type */
		);
}

int Match_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 68) /* message type */
		);
}

int Match_c_MODIFY_PDP_CONTEXT_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 72) /* message type */
		);
}

int Match_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 75) /* message type */
		);
}

int Match_c_MODIFY_PDP_CONTEXT_REJECT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 76) /* message type */
		);
}

int Match_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 91) /* message type */
		);
}

int Match_c_NOTIFICATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 93) /* message type */
		);
}

int Match_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 87) /* message type */
		);
}

int Match_c_ACTIVATE_MBMS_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 88) /* message type */
		);
}

int Match_c_REQUEST_MBMS_CONTEXT_ACTIVATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	int shift = 8;
	if (EDBitsToInt (Buffer, BitOffset+1, 3) == 7) do {
		shift += 8;
	} while (EDBitsToInt (Buffer, BitOffset+shift-8, 1) == 0);
	return (
			(EDBitsToInt (Buffer, BitOffset+4, 4) == 10) /* protocol discriminator & skip indicator */
			&& ((EDBitsToInt (Buffer, BitOffset+shift, 8)) == 89) /* message type */
		);
}

