/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "EPS_SM_Downlink_EPS.h"
#include "ed_c_known_ie_EPS.h"
#include "ed_tlv.h"
#include "CSN1DataTypes_EPS.h"
#include "UserDefinedDataTypes_EPS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 197, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for LinkedEPSBearerIdentity */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LinkedEPSBearerIdentity> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->LinkedEPSBearerIdentity), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:963> Error encoding subfield LinkedEPSBearerIdentity\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SpareHalfOctet */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SpareHalfOctet> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs-4), 0, 4);Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:964> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for EPSQoS */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->EPSQoS> DOT=<.> */
		Len = ENCODE_c_EPS_QOS (Buffer, CurrOfs+8, (&(Source->EPSQoS)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:965> Error encoding subfield EPSQoS\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for TFT */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->TFT> DOT=<.> */
		Len = ENCODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs+8, (&(Source->TFT)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:966> Error encoding subfield TFT\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for TransactionIdentifier */
	{
		int TLV_Base = CurrOfs;
		if (Source->TransactionIdentifier_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TransactionIdentifier> DOT=<->> */
			Len = ENCODE_c_epsLinkedTi (Buffer, CurrOfs+8, Source->TransactionIdentifier);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:967> Error encoding subfield TransactionIdentifier\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedQoS */
	{
		int TLV_Base = CurrOfs;
		if (Source->NegotiatedQoS_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedQoS> DOT=<->> */
			Len = ENCODE_c_epsQualityOfServ (Buffer, CurrOfs+8, Source->NegotiatedQoS);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:968> Error encoding subfield NegotiatedQoS\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedLLCSAPI */
	{
		if (Source->NegotiatedLLCSAPI_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLLCSAPI> DOT=<->> */
			Len = ENCODE_c_epsLlcServAccessPointId (Buffer, CurrOfs, Source->NegotiatedLLCSAPI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:969> Error encoding subfield NegotiatedLLCSAPI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for RadioPriority */
	{
		if (Source->RadioPriority_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RadioPriority> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->RadioPriority), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:970> Error encoding subfield RadioPriority\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PacketFlowIdentifier */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowIdentifier_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowIdentifier> DOT=<->> */
			Len = ENCODE_c_epsPacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowIdentifier);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:971> Error encoding subfield PacketFlowIdentifier\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:972> Error encoding subfield ProtocolConfigurationOptions\n");
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
			Len = ENCODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Source->WLANOffloadIndication);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:973> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:974> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:975> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{48, 255, ED_SKIPLIST_OPTIONAL},
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE LinkedEPSBearerIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->LinkedEPSBearerIdentity = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13408=EDCore::TDMOctet) */Destin->LinkedEPSBearerIdentity___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:976> Error decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 976, (Destin->LinkedEPSBearerIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:977> Message too short decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 976, (Destin->LinkedEPSBearerIdentity))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SpareHalfOctet
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:978> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 978, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:979> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 978, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE EPSQoS
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 104)) {
		ED_SIGNAL_ERROR ("<ERRID:980> Size error decoding IE EPSQoS\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 980, (Destin->EPSQoS))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPS_QOS (Buffer, CurrOfs, (&(Destin->EPSQoS)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:981> Error decoding subfield EPSQoS\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 981, (Destin->EPSQoS))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:982> Message too short decoding subfield EPSQoS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 981, (Destin->EPSQoS))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TFT
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 2040)) {
		ED_SIGNAL_ERROR ("<ERRID:983> Size error decoding IE TFT\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 983, (Destin->TFT))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs, (&(Destin->TFT)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:984> Error decoding subfield TFT\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 984, (Destin->TFT))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:985> Message too short decoding subfield TFT\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 984, (Destin->TFT))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TransactionIdentifier
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 986, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:987> Size error decoding IE TransactionIdentifier\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 987, (Destin->TransactionIdentifier))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLinkedTi (Buffer, CurrOfs, Destin->TransactionIdentifier, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:988> Error decoding subfield TransactionIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 988, (Destin->TransactionIdentifier))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:989> Message too short decoding subfield TransactionIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 988, (Destin->TransactionIdentifier))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedQoS
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 990, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 96) || (Len > 160)) {
			ED_SIGNAL_ERROR ("<ERRID:991> Size error decoding IE NegotiatedQoS\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 991, (Destin->NegotiatedQoS))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsQualityOfServ (Buffer, CurrOfs, Destin->NegotiatedQoS, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:992> Error decoding subfield NegotiatedQoS\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 992, (Destin->NegotiatedQoS))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:993> Message too short decoding subfield NegotiatedQoS\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 992, (Destin->NegotiatedQoS))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedLLCSAPI
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 994, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLlcServAccessPointId (Buffer, CurrOfs, Destin->NegotiatedLLCSAPI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:995> Error decoding subfield NegotiatedLLCSAPI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 995, (Destin->NegotiatedLLCSAPI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:996> Message too short decoding subfield NegotiatedLLCSAPI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 995, (Destin->NegotiatedLLCSAPI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RadioPriority
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 997, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RadioPriority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13422=EDCore::TDMInteger) */Destin->RadioPriority___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:998> Error decoding subfield RadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 998, (Destin->RadioPriority))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:999> Message too short decoding subfield RadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 998, (Destin->RadioPriority))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowIdentifier
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1000, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1001> Size error decoding IE PacketFlowIdentifier\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1001, (Destin->PacketFlowIdentifier))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsPacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowIdentifier, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1002> Error decoding subfield PacketFlowIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1002, (Destin->PacketFlowIdentifier))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1003> Message too short decoding subfield PacketFlowIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1002, (Destin->PacketFlowIdentifier))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1004, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1005> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1005, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1006> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1006, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1007> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1006, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1008, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1009> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1009, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1010> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1009, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1011, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1012> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1012, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13430=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1013> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1013, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1014> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1013, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1015, 12, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1016> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1016, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1017> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1017, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1018> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1017, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 193, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for EPSQoS */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->EPSQoS> DOT=<.> */
		Len = ENCODE_c_EPS_QOS (Buffer, CurrOfs+8, (&(Source->EPSQoS)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1019> Error encoding subfield EPSQoS\n");
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
			ED_SIGNAL_ERROR ("<ERRID:1020> Error encoding subfield AccessPointName\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for PDNAddress */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->PDNAddress> DOT=<.> */
		Len = ENCODE_c_PDNAddress (Buffer, CurrOfs+8, (&(Source->PDNAddress)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1021> Error encoding subfield PDNAddress\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for TransactionIdentifier */
	{
		int TLV_Base = CurrOfs;
		if (Source->TransactionIdentifier_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TransactionIdentifier> DOT=<->> */
			Len = ENCODE_c_epsLinkedTi (Buffer, CurrOfs+8, Source->TransactionIdentifier);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1022> Error encoding subfield TransactionIdentifier\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedQoS */
	{
		int TLV_Base = CurrOfs;
		if (Source->NegotiatedQoS_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedQoS> DOT=<->> */
			Len = ENCODE_c_epsQualityOfServ (Buffer, CurrOfs+8, Source->NegotiatedQoS);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1023> Error encoding subfield NegotiatedQoS\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedLLCSAPI */
	{
		if (Source->NegotiatedLLCSAPI_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLLCSAPI> DOT=<->> */
			Len = ENCODE_c_epsLlcServAccessPointId (Buffer, CurrOfs, Source->NegotiatedLLCSAPI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1024> Error encoding subfield NegotiatedLLCSAPI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for RadioPriority */
	{
		if (Source->RadioPriority_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RadioPriority> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->RadioPriority), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1025> Error encoding subfield RadioPriority\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PacketFlowIdentifier */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowIdentifier_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowIdentifier> DOT=<->> */
			Len = ENCODE_c_epsPacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowIdentifier);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1026> Error encoding subfield PacketFlowIdentifier\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for APNAMBR */
	{
		int TLV_Base = CurrOfs;
		if (Source->APNAMBR_Present) {
			/* Append to buffer IEI tag 0x5E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->APNAMBR> DOT=<->> */
			Len = ENCODE_c_APNAggregateMaxBitRate (Buffer, CurrOfs+8, Source->APNAMBR);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1027> Error encoding subfield APNAMBR\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ESMCause */
	{
		if (Source->ESMCause_Present) {
			/* Append to buffer IEI tag 0x58 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x58), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1028> Error encoding subfield ESMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1029> Error encoding subfield ProtocolConfigurationOptions\n");
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
			/* Append to buffer value part DEBUG FIELD=<Source->ConnectivityType> DOT=<->> */
			Len = ENCODE_c_epsConnectivityType (Buffer, CurrOfs, Source->ConnectivityType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1030> Error encoding subfield ConnectivityType\n");
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
			Len = ENCODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Source->WLANOffloadIndication);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1031> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1032> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HeaderCompressionCfg */
	{
		int TLV_Base = CurrOfs;
		if (Source->HeaderCompressionCfg_Present) {
			/* Append to buffer IEI tag 0x66 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x66), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HeaderCompressionCfg> DOT=<->> */
			Len = ENCODE_c_HeaderCompressionCfg (Buffer, CurrOfs+8, Source->HeaderCompressionCfg);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1033> Error encoding subfield HeaderCompressionCfg\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ControlPlaneOnlyIndication */
	{
		if (Source->ControlPlaneOnlyIndication_Present) {
			/* Append to buffer IEI tag 0x09 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x09), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ControlPlaneOnlyIndication> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ControlPlaneOnlyIndication), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1034> Error encoding subfield ControlPlaneOnlyIndication\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1035> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}
	
	/* Code for ServingPLMNRateControl */
	{
		int TLV_Base = CurrOfs;
		if (Source->ServingPLMNRateControl_Present) {
			/* Append to buffer IEI tag 0x6E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ServingPLMNRateControl> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs+8), (int)(Source->ServingPLMNRateControl), 16);
			Len = 16;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1036> Error encoding subfield ServingPLMNRateControl\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{48, 255, ED_SKIPLIST_OPTIONAL},
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
		{88, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{176, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{102, 255, ED_SKIPLIST_OPTIONAL},
		{144, 240, ED_SKIPLIST_OPTIONAL},
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EPSQoS
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 104)) {
		ED_SIGNAL_ERROR ("<ERRID:1037> Size error decoding IE EPSQoS\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1037, (Destin->EPSQoS))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPS_QOS (Buffer, CurrOfs, (&(Destin->EPSQoS)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1038> Error decoding subfield EPSQoS\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1038, (Destin->EPSQoS))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1039> Message too short decoding subfield EPSQoS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1038, (Destin->EPSQoS))
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
		ED_SIGNAL_ERROR ("<ERRID:1040> Size error decoding IE AccessPointName\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1040, (Destin->AccessPointName))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13441=EDCore::TDMBinary) */Destin->AccessPointName___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName (&(Destin->AccessPointName), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:1041> Error decoding subfield AccessPointName\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1041, (Destin->AccessPointName))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1042> Message too short decoding subfield AccessPointName\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1041, (Destin->AccessPointName))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PDNAddress
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 40) || (Len > 104)) {
		ED_SIGNAL_ERROR ("<ERRID:1043> Size error decoding IE PDNAddress\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1043, (Destin->PDNAddress))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PDNAddress (Buffer, CurrOfs, (&(Destin->PDNAddress)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1044> Error decoding subfield PDNAddress\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1044, (Destin->PDNAddress))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1045> Message too short decoding subfield PDNAddress\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1044, (Destin->PDNAddress))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TransactionIdentifier
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 1046, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:1047> Size error decoding IE TransactionIdentifier\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 1047, (Destin->TransactionIdentifier))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLinkedTi (Buffer, CurrOfs, Destin->TransactionIdentifier, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1048> Error decoding subfield TransactionIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 1048, (Destin->TransactionIdentifier))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1049> Message too short decoding subfield TransactionIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 1048, (Destin->TransactionIdentifier))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedQoS
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 1050, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 96) || (Len > 160)) {
			ED_SIGNAL_ERROR ("<ERRID:1051> Size error decoding IE NegotiatedQoS\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 1051, (Destin->NegotiatedQoS))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsQualityOfServ (Buffer, CurrOfs, Destin->NegotiatedQoS, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1052> Error decoding subfield NegotiatedQoS\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 1052, (Destin->NegotiatedQoS))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1053> Message too short decoding subfield NegotiatedQoS\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 1052, (Destin->NegotiatedQoS))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedLLCSAPI
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 1054, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLlcServAccessPointId (Buffer, CurrOfs, Destin->NegotiatedLLCSAPI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1055> Error decoding subfield NegotiatedLLCSAPI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 1055, (Destin->NegotiatedLLCSAPI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1056> Message too short decoding subfield NegotiatedLLCSAPI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 1055, (Destin->NegotiatedLLCSAPI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RadioPriority
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 1057, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RadioPriority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13451=EDCore::TDMInteger) */Destin->RadioPriority___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1058> Error decoding subfield RadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1058, (Destin->RadioPriority))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1059> Message too short decoding subfield RadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1058, (Destin->RadioPriority))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowIdentifier
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1060, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1061> Size error decoding IE PacketFlowIdentifier\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1061, (Destin->PacketFlowIdentifier))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsPacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowIdentifier, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1062> Error decoding subfield PacketFlowIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1062, (Destin->PacketFlowIdentifier))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1063> Message too short decoding subfield PacketFlowIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1062, (Destin->PacketFlowIdentifier))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE APNAMBR
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 1064, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 48)) {
			ED_SIGNAL_ERROR ("<ERRID:1065> Size error decoding IE APNAMBR\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 1065, (Destin->APNAMBR))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_APNAggregateMaxBitRate (Buffer, CurrOfs, Destin->APNAMBR, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1066> Error decoding subfield APNAMBR\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 1066, (Destin->APNAMBR))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1067> Message too short decoding subfield APNAMBR\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 1066, (Destin->APNAMBR))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x58 */
	ED_EXPECT_OPTIONAL_IE (0x58,  8, 1068, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x58) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13457=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1069> Error decoding subfield ESMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x58, 1069, (Destin->ESMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1070> Message too short decoding subfield ESMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x58, 1069, (Destin->ESMCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1071, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1072> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1072, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1073> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1073, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1074> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1073, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ConnectivityType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0B */
	ED_EXPECT_OPTIONAL_IE (0x0B,  4, 1075, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsConnectivityType (Buffer, CurrOfs, Destin->ConnectivityType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1076> Error decoding subfield ConnectivityType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0B, 1076, (Destin->ConnectivityType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1077> Message too short decoding subfield ConnectivityType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0B, 1076, (Destin->ConnectivityType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1078, 12, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1079> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1079, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1080> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1079, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1081, 13, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1082> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1082, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13465=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1083> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1083, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1084> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1083, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HeaderCompressionCfg
	------------------------------------------------------*/
	/* Detect IEI tag 0x66 */
	ED_EXPECT_OPTIONAL_IE (0x66,  8, 1085, 14, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x66) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 32) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1086> Size error decoding IE HeaderCompressionCfg\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x66, 1086, (Destin->HeaderCompressionCfg))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HeaderCompressionCfg (Buffer, CurrOfs, Destin->HeaderCompressionCfg, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1087> Error decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x66, 1087, (Destin->HeaderCompressionCfg))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1088> Message too short decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x66, 1087, (Destin->HeaderCompressionCfg))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ControlPlaneOnlyIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x09 */
	ED_EXPECT_OPTIONAL_IE (0x09,  4, 1089, 15, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x09) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->ControlPlaneOnlyIndication = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13469=EDCore::TDMOctet) */Destin->ControlPlaneOnlyIndication___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1090> Error decoding subfield ControlPlaneOnlyIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x09, 1090, (Destin->ControlPlaneOnlyIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1091> Message too short decoding subfield ControlPlaneOnlyIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x09, 1090, (Destin->ControlPlaneOnlyIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1092, 16, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1093> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1093, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1094> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1094, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1095> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1094, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ServingPLMNRateControl
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 1096, 17, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:1097> Size error decoding IE ServingPLMNRateControl\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 1097, (Destin->ServingPLMNRateControl))
		} 
#endif
		/* Read value part LOCATOR_16 */
		Destin->ServingPLMNRateControl = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 16);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13473=EDCore::TDMInteger) */Destin->ServingPLMNRateControl___LOCATOR), CurrOfs, 16);
		RetLen = 16;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1098> Error decoding subfield ServingPLMNRateControl\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 1098, (Destin->ServingPLMNRateControl))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1099> Message too short decoding subfield ServingPLMNRateControl\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 1098, (Destin->ServingPLMNRateControl))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 213, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1100> Error encoding subfield ESMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1101> Error encoding subfield ProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BackOffTimer */
	{
		int TLV_Base = CurrOfs;
		if (Source->BackOffTimer_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BackOffTimer> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs+8, Source->BackOffTimer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1102> Error encoding subfield BackOffTimer\n");
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
			Len = ENCODE_c_epsReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1103> Error encoding subfield ReAttemptIndicator\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1104> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1105> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BEARER_RESOURCE_ALLOCATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_ALLOCATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_ALLOCATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13480=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1106> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1106, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1107> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1106, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1108, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1109> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1109, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1110> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1110, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1111> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1110, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BackOffTimer
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1112, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1113> Size error decoding IE BackOffTimer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1113, (Destin->BackOffTimer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->BackOffTimer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1114> Error decoding subfield BackOffTimer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1114, (Destin->BackOffTimer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1115> Message too short decoding subfield BackOffTimer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1114, (Destin->BackOffTimer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 1116, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1117> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 1117, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1118> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 1118, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1119> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 1118, (Destin->ReAttemptIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1120, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1121> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1121, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13488=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1122> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1122, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1123> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1122, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1124, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1125> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1125, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1126> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1126, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1127> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1126, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 215, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1128> Error encoding subfield ESMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1129> Error encoding subfield ProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BackOffTimer */
	{
		int TLV_Base = CurrOfs;
		if (Source->BackOffTimer_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BackOffTimer> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs+8, Source->BackOffTimer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1130> Error encoding subfield BackOffTimer\n");
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
			Len = ENCODE_c_epsReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1131> Error encoding subfield ReAttemptIndicator\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1132> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1133> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BEARER_RESOURCE_MODIFICATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_MODIFICATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_MODIFICATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13497=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1134> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1134, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1135> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1134, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1136, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1137> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1137, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1138> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1138, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1139> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1138, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BackOffTimer
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1140, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1141> Size error decoding IE BackOffTimer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1141, (Destin->BackOffTimer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->BackOffTimer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1142> Error decoding subfield BackOffTimer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1142, (Destin->BackOffTimer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1143> Message too short decoding subfield BackOffTimer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1142, (Destin->BackOffTimer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 1144, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1145> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 1145, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1146> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 1146, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1147> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 1146, (Destin->ReAttemptIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1148, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1149> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1149, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13505=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1150> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1150, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1151> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1150, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1152, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1153> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1153, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1154> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1154, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1155> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1154, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 205, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1156> Error encoding subfield ESMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1157> Error encoding subfield ProtocolConfigurationOptions\n");
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
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs+8, Source->T3396Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1158> Error encoding subfield T3396Value\n");
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
			Len = ENCODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Source->WLANOffloadIndication);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1159> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1160> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1161> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13514=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1162> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1162, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1163> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1162, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1164, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1165> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1165, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1166> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1166, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1167> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1166, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3396Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1168, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1169> Size error decoding IE T3396Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1169, (Destin->T3396Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3396Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1170> Error decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1170, (Destin->T3396Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1171> Message too short decoding subfield T3396Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1170, (Destin->T3396Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1172, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1173> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1173, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1174> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1173, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1175, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1176> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1176, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13522=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1177> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1177, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1178> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1177, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1179, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1180> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1180, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1181> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1181, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1182> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1181, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ESM_INFORMATION_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_ESM_INFORMATION_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 217, 8);
		CurrOfs += 8;
		

	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_INFORMATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_INFORMATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_INFORMATION_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_INFORMATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_INFORMATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_INFORMATION_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_INFORMATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_INFORMATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ESM_INFORMATION_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_INFORMATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_INFORMATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 201, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for NewEPSQoS */
	{
		int TLV_Base = CurrOfs;
		if (Source->NewEPSQoS_Present) {
			/* Append to buffer IEI tag 0x5B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NewEPSQoS> DOT=<->> */
			Len = ENCODE_c_EPS_QOS (Buffer, CurrOfs+8, Source->NewEPSQoS);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1183> Error encoding subfield NewEPSQoS\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for TFT */
	{
		int TLV_Base = CurrOfs;
		if (Source->TFT_Present) {
			/* Append to buffer IEI tag 0x36 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x36), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TFT> DOT=<->> */
			Len = ENCODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs+8, Source->TFT);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1184> Error encoding subfield TFT\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NewQoS */
	{
		int TLV_Base = CurrOfs;
		if (Source->NewQoS_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NewQoS> DOT=<->> */
			Len = ENCODE_c_epsQualityOfServ (Buffer, CurrOfs+8, Source->NewQoS);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1185> Error encoding subfield NewQoS\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NegotiatedLLCSAPI */
	{
		if (Source->NegotiatedLLCSAPI_Present) {
			/* Append to buffer IEI tag 0x32 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x32), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NegotiatedLLCSAPI> DOT=<->> */
			Len = ENCODE_c_epsLlcServAccessPointId (Buffer, CurrOfs, Source->NegotiatedLLCSAPI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1186> Error encoding subfield NegotiatedLLCSAPI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for RadioPriority */
	{
		if (Source->RadioPriority_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->RadioPriority> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->RadioPriority), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1187> Error encoding subfield RadioPriority\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for PacketFlowIdentifier */
	{
		int TLV_Base = CurrOfs;
		if (Source->PacketFlowIdentifier_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->PacketFlowIdentifier> DOT=<->> */
			Len = ENCODE_c_epsPacketFlowIdentifie (Buffer, CurrOfs+8, Source->PacketFlowIdentifier);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1188> Error encoding subfield PacketFlowIdentifier\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for APNAMBR */
	{
		int TLV_Base = CurrOfs;
		if (Source->APNAMBR_Present) {
			/* Append to buffer IEI tag 0x5E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->APNAMBR> DOT=<->> */
			Len = ENCODE_c_APNAggregateMaxBitRate (Buffer, CurrOfs+8, Source->APNAMBR);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1189> Error encoding subfield APNAMBR\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1190> Error encoding subfield ProtocolConfigurationOptions\n");
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
			Len = ENCODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Source->WLANOffloadIndication);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1191> Error encoding subfield WLANOffloadIndication\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1192> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HeaderCompressionCfg */
	{
		int TLV_Base = CurrOfs;
		if (Source->HeaderCompressionCfg_Present) {
			/* Append to buffer IEI tag 0x66 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x66), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HeaderCompressionCfg> DOT=<->> */
			Len = ENCODE_c_HeaderCompressionCfg (Buffer, CurrOfs+8, Source->HeaderCompressionCfg);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1193> Error encoding subfield HeaderCompressionCfg\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1194> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{91, 255, ED_SKIPLIST_OPTIONAL},
		{54, 255, ED_SKIPLIST_OPTIONAL},
		{48, 255, ED_SKIPLIST_OPTIONAL},
		{50, 255, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
		{39, 255, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{51, 255, ED_SKIPLIST_OPTIONAL},
		{102, 255, ED_SKIPLIST_OPTIONAL},
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE NewEPSQoS
	------------------------------------------------------*/
	/* Detect IEI tag 0x5B */
	ED_EXPECT_OPTIONAL_IE (0x5B,  8, 1195, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 104)) {
			ED_SIGNAL_ERROR ("<ERRID:1196> Size error decoding IE NewEPSQoS\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5B, 1196, (Destin->NewEPSQoS))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPS_QOS (Buffer, CurrOfs, Destin->NewEPSQoS, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1197> Error decoding subfield NewEPSQoS\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5B, 1197, (Destin->NewEPSQoS))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1198> Message too short decoding subfield NewEPSQoS\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5B, 1197, (Destin->NewEPSQoS))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TFT
	------------------------------------------------------*/
	/* Detect IEI tag 0x36 */
	ED_EXPECT_OPTIONAL_IE (0x36,  8, 1199, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x36) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1200> Size error decoding IE TFT\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x36, 1200, (Destin->TFT))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs, Destin->TFT, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1201> Error decoding subfield TFT\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x36, 1201, (Destin->TFT))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1202> Message too short decoding subfield TFT\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x36, 1201, (Destin->TFT))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NewQoS
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 1203, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 96) || (Len > 160)) {
			ED_SIGNAL_ERROR ("<ERRID:1204> Size error decoding IE NewQoS\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 1204, (Destin->NewQoS))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsQualityOfServ (Buffer, CurrOfs, Destin->NewQoS, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1205> Error decoding subfield NewQoS\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 1205, (Destin->NewQoS))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1206> Message too short decoding subfield NewQoS\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 1205, (Destin->NewQoS))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NegotiatedLLCSAPI
	------------------------------------------------------*/
	/* Detect IEI tag 0x32 */
	ED_EXPECT_OPTIONAL_IE (0x32,  8, 1207, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x32) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLlcServAccessPointId (Buffer, CurrOfs, Destin->NegotiatedLLCSAPI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1208> Error decoding subfield NegotiatedLLCSAPI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x32, 1208, (Destin->NegotiatedLLCSAPI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1209> Message too short decoding subfield NegotiatedLLCSAPI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x32, 1208, (Destin->NegotiatedLLCSAPI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RadioPriority
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 1210, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->RadioPriority = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13544=EDCore::TDMInteger) */Destin->RadioPriority___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1211> Error decoding subfield RadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 1211, (Destin->RadioPriority))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1212> Message too short decoding subfield RadioPriority\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 1211, (Destin->RadioPriority))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE PacketFlowIdentifier
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 1213, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1214> Size error decoding IE PacketFlowIdentifier\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 1214, (Destin->PacketFlowIdentifier))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsPacketFlowIdentifie (Buffer, CurrOfs, Destin->PacketFlowIdentifier, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1215> Error decoding subfield PacketFlowIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 1215, (Destin->PacketFlowIdentifier))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1216> Message too short decoding subfield PacketFlowIdentifier\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 1215, (Destin->PacketFlowIdentifier))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE APNAMBR
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 1217, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 48)) {
			ED_SIGNAL_ERROR ("<ERRID:1218> Size error decoding IE APNAMBR\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 1218, (Destin->APNAMBR))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_APNAggregateMaxBitRate (Buffer, CurrOfs, Destin->APNAMBR, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1219> Error decoding subfield APNAMBR\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 1219, (Destin->APNAMBR))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1220> Message too short decoding subfield APNAMBR\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 1219, (Destin->APNAMBR))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1221, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1222> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1222, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1223> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1223, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1224> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1223, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE WLANOffloadIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 1225, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsWLANOffloadAcceptability (Buffer, CurrOfs, Destin->WLANOffloadIndication, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1226> Error decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 1226, (Destin->WLANOffloadIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1227> Message too short decoding subfield WLANOffloadIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 1226, (Destin->WLANOffloadIndication))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1228, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1229> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1229, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13554=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1230> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1230, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1231> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1230, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HeaderCompressionCfg
	------------------------------------------------------*/
	/* Detect IEI tag 0x66 */
	ED_EXPECT_OPTIONAL_IE (0x66,  8, 1232, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x66) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 32) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1233> Size error decoding IE HeaderCompressionCfg\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x66, 1233, (Destin->HeaderCompressionCfg))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HeaderCompressionCfg (Buffer, CurrOfs, Destin->HeaderCompressionCfg, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1234> Error decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x66, 1234, (Destin->HeaderCompressionCfg))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1235> Message too short decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x66, 1234, (Destin->HeaderCompressionCfg))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1236, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1237> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1237, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1238> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1238, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1239> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1238, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_NOTIFICATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EPS_NOTIFICATION (char* Buffer, ED_EXLONG BitOffset, const c_EPS_NOTIFICATION* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 219, 8);
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
			ED_SIGNAL_ERROR ("<ERRID:1240> Error encoding subfield NotificationIndicator\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_NOTIFICATION* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_NOTIFICATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_NOTIFICATION* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_NOTIFICATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_EPS_NOTIFICATION (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:1241> Size error decoding IE NotificationIndicator\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1241, (Destin->NotificationIndicator))
	} 
#endif
	/* Read value part LOCATOR_16 */
	Destin->NotificationIndicator = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13565=EDCore::TDMOctet) */Destin->NotificationIndicator___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1242> Error decoding subfield NotificationIndicator\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1242, (Destin->NotificationIndicator))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1243> Message too short decoding subfield NotificationIndicator\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1242, (Destin->NotificationIndicator))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_PDN_CONNECTIVITY_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 209, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1244> Error encoding subfield ESMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1245> Error encoding subfield ProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for BackOffTimer */
	{
		int TLV_Base = CurrOfs;
		if (Source->BackOffTimer_Present) {
			/* Append to buffer IEI tag 0x37 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x37), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->BackOffTimer> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs+8, Source->BackOffTimer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1246> Error encoding subfield BackOffTimer\n");
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
			Len = ENCODE_c_epsReAttemptIndicator (Buffer, CurrOfs+8, Source->ReAttemptIndicator);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1247> Error encoding subfield ReAttemptIndicator\n");
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
				ED_SIGNAL_ERROR ("<ERRID:1248> Error encoding subfield NBIFOMContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1249> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDN_CONNECTIVITY_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_CONNECTIVITY_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PDN_CONNECTIVITY_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_CONNECTIVITY_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDN_CONNECTIVITY_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_CONNECTIVITY_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_PDN_CONNECTIVITY_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PDN_CONNECTIVITY_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_CONNECTIVITY_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13572=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1250> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1250, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1251> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1250, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1252, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1253> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1253, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1254> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1254, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1255> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1254, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE BackOffTimer
	------------------------------------------------------*/
	/* Detect IEI tag 0x37 */
	ED_EXPECT_OPTIONAL_IE (0x37,  8, 1256, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x37) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1257> Size error decoding IE BackOffTimer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x37, 1257, (Destin->BackOffTimer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->BackOffTimer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1258> Error decoding subfield BackOffTimer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x37, 1258, (Destin->BackOffTimer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1259> Message too short decoding subfield BackOffTimer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x37, 1258, (Destin->BackOffTimer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReAttemptIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x6B */
	ED_EXPECT_OPTIONAL_IE (0x6B,  8, 1260, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:1261> Size error decoding IE ReAttemptIndicator\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6B, 1261, (Destin->ReAttemptIndicator))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsReAttemptIndicator (Buffer, CurrOfs, Destin->ReAttemptIndicator, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1262> Error decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6B, 1262, (Destin->ReAttemptIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1263> Message too short decoding subfield ReAttemptIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6B, 1262, (Destin->ReAttemptIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 1264, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:1265> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 1265, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13580=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:1266> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 1266, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1267> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 1266, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1268, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1269> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1269, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1270> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1270, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1271> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1270, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_PDN_DISCONNECT_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 211, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1272> Error encoding subfield ESMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x27 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x27), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+8, Source->ProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1273> Error encoding subfield ProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		int TLV_Base = CurrOfs;
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x7B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<->> */
			Len = ENCODE_c_epsProtocolCfgOpt (Buffer, CurrOfs+16, Source->ExtendedProtocolConfigurationOptions);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1274> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDN_DISCONNECT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_DISCONNECT_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PDN_DISCONNECT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_DISCONNECT_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDN_DISCONNECT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_DISCONNECT_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_PDN_DISCONNECT_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PDN_DISCONNECT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_DISCONNECT_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13589=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1275> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1275, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1276> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1275, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 1277, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:1278> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 1278, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1279> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 1279, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1280> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 1279, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 1281, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:1282> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 1282, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1283> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 1283, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1284> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 1283, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT_RESPONSE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REMOTE_UE_REPORT_RESPONSE (char* Buffer, ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT_RESPONSE* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the EPS bearer identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)Source->EPSBearerIdentity, 4);
		CurrOfs += 4;
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 2, 4);
		CurrOfs += 4;

		/* Encode the procedure transaction identity */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->ProcedureTransactionIdentity, 8);
		CurrOfs += 8;
		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 234, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for UserDataContainer */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->UserDataContainer> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+16, Source->UserDataContainer.value, 0, Source->UserDataContainer.usedBits);
		Len = Source->UserDataContainer.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1285> Error encoding subfield UserDataContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+16;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
	}
	
	/* Code for ExtendedProtocolConfigurationOptions */
	{
		if (Source->ExtendedProtocolConfigurationOptions_Present) {
			/* Append to buffer IEI tag 0x0F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0F), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedProtocolConfigurationOptions> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ExtendedProtocolConfigurationOptions), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:1286> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REMOTE_UE_REPORT_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_REMOTE_UE_REPORT_RESPONSE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REMOTE_UE_REPORT_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_REMOTE_UE_REPORT_RESPONSE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REMOTE_UE_REPORT_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REMOTE_UE_REPORT_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_REMOTE_UE_REPORT_RESPONSE (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REMOTE_UE_REPORT_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REMOTE_UE_REPORT_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
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
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE UserDataContainer
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 16);
	CurrOfs += 16;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 4784) {
		ED_SIGNAL_ERROR ("<ERRID:1287> Size error decoding IE UserDataContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 1287, (Destin->UserDataContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13600=EDCore::TDMBinary) */Destin->UserDataContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer (&(Destin->UserDataContainer), Len);
	
		if (Destin->UserDataContainer.value) {
			EDCopyBits (Destin->UserDataContainer.value, 0, Buffer, CurrOfs, Len);
			Destin->UserDataContainer.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->UserDataContainer.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:1288> Error decoding subfield UserDataContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 1288, (Destin->UserDataContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:1289> Message too short decoding subfield UserDataContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 1288, (Destin->UserDataContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 1290, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->ExtendedProtocolConfigurationOptions = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13602=EDCore::TDMOctet) */Destin->ExtendedProtocolConfigurationOptions___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:1291> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 1291, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:1292> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 1291, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 197) /* message type */
	);
}

int Match_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 193) /* message type */
	);
}

int Match_c_BEARER_RESOURCE_ALLOCATION_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 213) /* message type */
	);
}

int Match_c_BEARER_RESOURCE_MODIFICATION_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 215) /* message type */
	);
}

int Match_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 205) /* message type */
	);
}

int Match_c_ESM_INFORMATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 217) /* message type */
	);
}

int Match_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 201) /* message type */
	);
}

int Match_c_EPS_NOTIFICATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 219) /* message type */
	);
}

int Match_c_PDN_CONNECTIVITY_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 209) /* message type */
	);
}

int Match_c_PDN_DISCONNECT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 211) /* message type */
	);
}

int Match_c_REMOTE_UE_REPORT_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 234) /* message type */
	);
}

