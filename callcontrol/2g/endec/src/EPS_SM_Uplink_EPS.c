/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "EPS_SM_Uplink_EPS.h"
#include "ed_c_known_ie_EPS.h"
#include "ed_tlv.h"
#include "UserDefinedDataTypes_EPS.h"
#include "CSN1DataTypes_EPS.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 198, 8);
		CurrOfs += 8;
		

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
				ED_SIGNAL_ERROR ("<ERRID:687> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:688> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:689> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 690, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:691> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 691, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:692> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 692, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:693> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 692, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 694, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:695> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 695, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13205=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:696> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 696, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:697> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 696, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 698, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:699> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 699, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:700> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 700, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:701> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 700, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 199, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:702> Error encoding subfield ESMCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:703> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:704> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:705> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13214=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:706> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 706, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:707> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 706, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 708, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:709> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 709, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:710> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 710, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:711> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 710, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 712, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:713> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 713, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13218=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:714> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 714, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:715> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 714, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 716, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:717> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 717, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:718> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 718, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:719> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 718, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 194, 8);
		CurrOfs += 8;
		

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
				ED_SIGNAL_ERROR ("<ERRID:720> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:721> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 722, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:723> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 723, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:724> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 724, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:725> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 724, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 726, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:727> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 727, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:728> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 728, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:729> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 728, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 195, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:730> Error encoding subfield ESMCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:731> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:732> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13236=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:733> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 733, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:734> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 733, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 735, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:736> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 736, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:737> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 737, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:738> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 737, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 739, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:740> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 740, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:741> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 741, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:742> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 741, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 212, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for LinkedEPSBearerIdentity */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LinkedEPSBearerIdentity> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->LinkedEPSBearerIdentity), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:743> Error encoding subfield LinkedEPSBearerIdentity\n");
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
			ED_SIGNAL_ERROR ("<ERRID:744> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for TrafficFlowAggregate */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->TrafficFlowAggregate> DOT=<.> */
		Len = ENCODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs+8, (&(Source->TrafficFlowAggregate)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:745> Error encoding subfield TrafficFlowAggregate\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RequiredTrafficFlowQoS */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->RequiredTrafficFlowQoS> DOT=<.> */
		Len = ENCODE_c_EPS_QOS (Buffer, CurrOfs+8, (&(Source->RequiredTrafficFlowQoS)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:746> Error encoding subfield RequiredTrafficFlowQoS\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:747> Error encoding subfield ProtocolConfigurationOptions\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:748> Error encoding subfield DeviceProperties\n");
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
				ED_SIGNAL_ERROR ("<ERRID:749> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:750> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BEARER_RESOURCE_ALLOCATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_ALLOCATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_BEARER_RESOURCE_ALLOCATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_ALLOCATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13247=EDCore::TDMOctet) */Destin->LinkedEPSBearerIdentity___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:751> Error decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 751, (Destin->LinkedEPSBearerIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:752> Message too short decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 751, (Destin->LinkedEPSBearerIdentity))
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
		ED_SIGNAL_ERROR ("<ERRID:753> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 753, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:754> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 753, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TrafficFlowAggregate
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 2040)) {
		ED_SIGNAL_ERROR ("<ERRID:755> Size error decoding IE TrafficFlowAggregate\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 755, (Destin->TrafficFlowAggregate))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs, (&(Destin->TrafficFlowAggregate)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:756> Error decoding subfield TrafficFlowAggregate\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 756, (Destin->TrafficFlowAggregate))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:757> Message too short decoding subfield TrafficFlowAggregate\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 756, (Destin->TrafficFlowAggregate))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RequiredTrafficFlowQoS
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 104)) {
		ED_SIGNAL_ERROR ("<ERRID:758> Size error decoding IE RequiredTrafficFlowQoS\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 758, (Destin->RequiredTrafficFlowQoS))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPS_QOS (Buffer, CurrOfs, (&(Destin->RequiredTrafficFlowQoS)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:759> Error decoding subfield RequiredTrafficFlowQoS\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 759, (Destin->RequiredTrafficFlowQoS))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:760> Message too short decoding subfield RequiredTrafficFlowQoS\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 759, (Destin->RequiredTrafficFlowQoS))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 761, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:762> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 762, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:763> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 763, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:764> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 763, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 765, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:766> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 766, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:767> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 766, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 768, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:769> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 769, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13259=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:770> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 770, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:771> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 770, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 772, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:773> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 773, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:774> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 774, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:775> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 774, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 214, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for LinkedEPSBearerIdentity */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LinkedEPSBearerIdentity> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->LinkedEPSBearerIdentity), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:776> Error encoding subfield LinkedEPSBearerIdentity\n");
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
			ED_SIGNAL_ERROR ("<ERRID:777> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for TrafficFlowAggregate */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->TrafficFlowAggregate> DOT=<.> */
		Len = ENCODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs+8, (&(Source->TrafficFlowAggregate)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:778> Error encoding subfield TrafficFlowAggregate\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for RequiredTrafficFlowQoS */
	{
		int TLV_Base = CurrOfs;
		if (Source->RequiredTrafficFlowQoS_Present) {
			/* Append to buffer IEI tag 0x5B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5B), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RequiredTrafficFlowQoS> DOT=<->> */
			Len = ENCODE_c_EPS_QOS (Buffer, CurrOfs+8, Source->RequiredTrafficFlowQoS);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:779> Error encoding subfield RequiredTrafficFlowQoS\n");
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
				ED_SIGNAL_ERROR ("<ERRID:780> Error encoding subfield ESMCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:781> Error encoding subfield ProtocolConfigurationOptions\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:782> Error encoding subfield DeviceProperties\n");
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
				ED_SIGNAL_ERROR ("<ERRID:783> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:784> Error encoding subfield HeaderCompressionCfg\n");
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
				ED_SIGNAL_ERROR ("<ERRID:785> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_BEARER_RESOURCE_MODIFICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE BEARER_RESOURCE_MODIFICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_BEARER_RESOURCE_MODIFICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_BEARER_RESOURCE_MODIFICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{91, 255, ED_SKIPLIST_OPTIONAL},
		{88, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE LinkedEPSBearerIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->LinkedEPSBearerIdentity = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13268=EDCore::TDMOctet) */Destin->LinkedEPSBearerIdentity___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:786> Error decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 786, (Destin->LinkedEPSBearerIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:787> Message too short decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 786, (Destin->LinkedEPSBearerIdentity))
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
		ED_SIGNAL_ERROR ("<ERRID:788> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 788, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:789> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 788, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TrafficFlowAggregate
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 2040)) {
		ED_SIGNAL_ERROR ("<ERRID:790> Size error decoding IE TrafficFlowAggregate\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 790, (Destin->TrafficFlowAggregate))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_epsTrafficFlowTemplate (Buffer, CurrOfs, (&(Destin->TrafficFlowAggregate)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:791> Error decoding subfield TrafficFlowAggregate\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 791, (Destin->TrafficFlowAggregate))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:792> Message too short decoding subfield TrafficFlowAggregate\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 791, (Destin->TrafficFlowAggregate))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE RequiredTrafficFlowQoS
	------------------------------------------------------*/
	/* Detect IEI tag 0x5B */
	ED_EXPECT_OPTIONAL_IE (0x5B,  8, 793, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 104)) {
			ED_SIGNAL_ERROR ("<ERRID:794> Size error decoding IE RequiredTrafficFlowQoS\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5B, 794, (Destin->RequiredTrafficFlowQoS))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPS_QOS (Buffer, CurrOfs, Destin->RequiredTrafficFlowQoS, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:795> Error decoding subfield RequiredTrafficFlowQoS\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5B, 795, (Destin->RequiredTrafficFlowQoS))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:796> Message too short decoding subfield RequiredTrafficFlowQoS\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5B, 795, (Destin->RequiredTrafficFlowQoS))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ESMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x58 */
	ED_EXPECT_OPTIONAL_IE (0x58,  8, 797, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x58) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13276=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:798> Error decoding subfield ESMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x58, 798, (Destin->ESMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:799> Message too short decoding subfield ESMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x58, 798, (Destin->ESMCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 800, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:801> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 801, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:802> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 802, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:803> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 802, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 804, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:805> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 805, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:806> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 805, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 807, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:808> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 808, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13282=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:809> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 809, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:810> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 809, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HeaderCompressionCfg
	------------------------------------------------------*/
	/* Detect IEI tag 0x66 */
	ED_EXPECT_OPTIONAL_IE (0x66,  8, 811, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x66) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:812> Size error decoding IE HeaderCompressionCfg\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x66, 812, (Destin->HeaderCompressionCfg))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HeaderCompressionCfg (Buffer, CurrOfs, Destin->HeaderCompressionCfg, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:813> Error decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x66, 813, (Destin->HeaderCompressionCfg))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:814> Message too short decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x66, 813, (Destin->HeaderCompressionCfg))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 815, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:816> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 816, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:817> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 817, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:818> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 817, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 206, 8);
		CurrOfs += 8;
		

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
				ED_SIGNAL_ERROR ("<ERRID:819> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:820> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:821> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 822, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:823> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 823, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:824> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 824, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:825> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 824, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 826, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:827> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 827, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13295=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:828> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 828, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:829> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 828, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 830, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:831> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 831, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:832> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 832, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:833> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 832, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_DUMMY_MESSAGE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ESM_DUMMY_MESSAGE (char* Buffer, ED_EXLONG BitOffset, const c_ESM_DUMMY_MESSAGE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 220, 8);
		CurrOfs += 8;
		

	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_DUMMY_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_DUMMY_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DUMMY_MESSAGE* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_DUMMY_MESSAGE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_DUMMY_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_DUMMY_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DUMMY_MESSAGE* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_DUMMY_MESSAGE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_DUMMY_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_DUMMY_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DUMMY_MESSAGE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ESM_DUMMY_MESSAGE (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_DUMMY_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_DUMMY_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DUMMY_MESSAGE* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_RESPONSE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ESM_INFORMATION_RESPONSE (char* Buffer, ED_EXLONG BitOffset, const c_ESM_INFORMATION_RESPONSE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 218, 8);
		CurrOfs += 8;
		

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
				ED_SIGNAL_ERROR ("<ERRID:834> Error encoding subfield AccessPointName\n");
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
				ED_SIGNAL_ERROR ("<ERRID:835> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:836> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_INFORMATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_INFORMATION_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_INFORMATION_RESPONSE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_INFORMATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_INFORMATION_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_INFORMATION_RESPONSE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_INFORMATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_INFORMATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ESM_INFORMATION_RESPONSE (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_INFORMATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_INFORMATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_INFORMATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
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
		{40, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE AccessPointName
	------------------------------------------------------*/
	/* Detect IEI tag 0x28 */
	ED_EXPECT_OPTIONAL_IE (0x28,  8, 837, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x28) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 800) {
			ED_SIGNAL_ERROR ("<ERRID:838> Size error decoding IE AccessPointName\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x28, 838, (Destin->AccessPointName))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13309=EDCore::TDMBinary) */Destin->AccessPointName___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_ESM_INFORMATION_RESPONSE_AccessPointName (Destin->AccessPointName, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:839> Error decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x28, 839, (Destin->AccessPointName))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:840> Message too short decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x28, 839, (Destin->AccessPointName))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 841, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:842> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 842, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:843> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 843, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:844> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 843, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 845, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:846> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 846, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:847> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 847, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:848> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 847, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_STATUS
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ESM_STATUS (char* Buffer, ED_EXLONG BitOffset, const c_ESM_STATUS* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 232, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:849> Error encoding subfield ESMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_STATUS (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_STATUS (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_STATUS* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ESM_STATUS (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_STATUS* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE ESMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->ESMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13320=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:850> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 850, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:851> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 850, (Destin->ESMCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 202, 8);
		CurrOfs += 8;
		

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
				ED_SIGNAL_ERROR ("<ERRID:852> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:853> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:854> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{123, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 855, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:856> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 856, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:857> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 857, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:858> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 857, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 859, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:860> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 860, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13329=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:861> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 861, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:862> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 861, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 863, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:864> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 864, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:865> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 865, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:866> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 865, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REJECT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 203, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for ESMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ESMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:867> Error encoding subfield ESMCause\n");
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
				ED_SIGNAL_ERROR ("<ERRID:868> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:869> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:870> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE MODIFY_EPS_BEARER_CONTEXT_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_MODIFY_EPS_BEARER_CONTEXT_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13338=EDCore::TDMOctet) */Destin->ESMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:871> Error decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 871, (Destin->ESMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:872> Message too short decoding subfield ESMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 871, (Destin->ESMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 873, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:874> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 874, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:875> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 875, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:876> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 875, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 877, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:878> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 878, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13342=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:879> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 879, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:880> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 879, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 881, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:882> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 882, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:883> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 883, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:884> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 883, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_PDN_CONNECTIVITY_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 208, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for RequestType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->RequestType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->RequestType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:885> Error encoding subfield RequestType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for PDNType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->PDNType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs-4)), (int)(Source->PDNType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:886> Error encoding subfield PDNType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ESMInformationTransferFlag */
	{
		if (Source->ESMInformationTransferFlag_Present) {
			/* Append to buffer IEI tag 0x0D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0D), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ESMInformationTransferFlag> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ESMInformationTransferFlag), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:887> Error encoding subfield ESMInformationTransferFlag\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
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
				ED_SIGNAL_ERROR ("<ERRID:888> Error encoding subfield AccessPointName\n");
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
				ED_SIGNAL_ERROR ("<ERRID:889> Error encoding subfield ProtocolConfigurationOptions\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:890> Error encoding subfield DeviceProperties\n");
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
				ED_SIGNAL_ERROR ("<ERRID:891> Error encoding subfield NBIFOMContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:892> Error encoding subfield HeaderCompressionCfg\n");
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
				ED_SIGNAL_ERROR ("<ERRID:893> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDN_CONNECTIVITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_CONNECTIVITY_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PDN_CONNECTIVITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_CONNECTIVITY_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_CONNECTIVITY_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDN_CONNECTIVITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_CONNECTIVITY_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_PDN_CONNECTIVITY_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_CONNECTIVITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PDN_CONNECTIVITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_CONNECTIVITY_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{40, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE RequestType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->RequestType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13351=EDCore::TDMOctet) */Destin->RequestType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:894> Error decoding subfield RequestType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 894, (Destin->RequestType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:895> Message too short decoding subfield RequestType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 894, (Destin->RequestType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE PDNType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->PDNType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs-4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13353=EDCore::TDMOctet) */Destin->PDNType___LOCATOR), (CurrOfs-4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:896> Error decoding subfield PDNType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 896, (Destin->PDNType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:897> Message too short decoding subfield PDNType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 896, (Destin->PDNType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ESMInformationTransferFlag
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 898, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->ESMInformationTransferFlag = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13355=EDCore::TDMOctet) */Destin->ESMInformationTransferFlag___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:899> Error decoding subfield ESMInformationTransferFlag\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 899, (Destin->ESMInformationTransferFlag))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:900> Message too short decoding subfield ESMInformationTransferFlag\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 899, (Destin->ESMInformationTransferFlag))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AccessPointName
	------------------------------------------------------*/
	/* Detect IEI tag 0x28 */
	ED_EXPECT_OPTIONAL_IE (0x28,  8, 901, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x28) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 800)) {
			ED_SIGNAL_ERROR ("<ERRID:902> Size error decoding IE AccessPointName\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x28, 902, (Destin->AccessPointName))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13357=EDCore::TDMBinary) */Destin->AccessPointName___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (Destin->AccessPointName, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:903> Error decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x28, 903, (Destin->AccessPointName))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:904> Message too short decoding subfield AccessPointName\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x28, 903, (Destin->AccessPointName))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 905, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:906> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 906, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:907> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 907, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:908> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 907, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 909, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:910> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 910, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:911> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 910, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NBIFOMContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x33 */
	ED_EXPECT_OPTIONAL_IE (0x33,  8, 912, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x33) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:913> Size error decoding IE NBIFOMContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x33, 913, (Destin->NBIFOMContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13363=EDCore::TDMBinary) */Destin->NBIFOMContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (Destin->NBIFOMContainer, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:914> Error decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x33, 914, (Destin->NBIFOMContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:915> Message too short decoding subfield NBIFOMContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x33, 914, (Destin->NBIFOMContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HeaderCompressionCfg
	------------------------------------------------------*/
	/* Detect IEI tag 0x66 */
	ED_EXPECT_OPTIONAL_IE (0x66,  8, 916, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x66) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 32) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:917> Size error decoding IE HeaderCompressionCfg\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x66, 917, (Destin->HeaderCompressionCfg))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HeaderCompressionCfg (Buffer, CurrOfs, Destin->HeaderCompressionCfg, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:918> Error decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x66, 918, (Destin->HeaderCompressionCfg))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:919> Message too short decoding subfield HeaderCompressionCfg\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x66, 918, (Destin->HeaderCompressionCfg))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 920, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:921> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 921, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:922> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 922, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:923> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 922, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_PDN_DISCONNECT_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 210, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for LinkedEPSBearerIdentity */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->LinkedEPSBearerIdentity> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->LinkedEPSBearerIdentity), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:924> Error encoding subfield LinkedEPSBearerIdentity\n");
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
			ED_SIGNAL_ERROR ("<ERRID:925> Error encoding subfield SpareHalfOctet\n");
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
				ED_SIGNAL_ERROR ("<ERRID:926> Error encoding subfield ProtocolConfigurationOptions\n");
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
				ED_SIGNAL_ERROR ("<ERRID:927> Error encoding subfield ExtendedProtocolConfigurationOptions\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_PDN_DISCONNECT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_DISCONNECT_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_PDN_DISCONNECT_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_PDN_DISCONNECT_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_PDN_DISCONNECT_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_PDN_DISCONNECT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_DISCONNECT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_PDN_DISCONNECT_REQUEST (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE PDN_DISCONNECT_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_PDN_DISCONNECT_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_PDN_DISCONNECT_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE LinkedEPSBearerIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->LinkedEPSBearerIdentity = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13374=EDCore::TDMOctet) */Destin->LinkedEPSBearerIdentity___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:928> Error decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 928, (Destin->LinkedEPSBearerIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:929> Message too short decoding subfield LinkedEPSBearerIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 928, (Destin->LinkedEPSBearerIdentity))
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
		ED_SIGNAL_ERROR ("<ERRID:930> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 930, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:931> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 930, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x27 */
	ED_EXPECT_OPTIONAL_IE (0x27,  8, 932, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x27) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:933> Size error decoding IE ProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x27, 933, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:934> Error decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x27, 934, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:935> Message too short decoding subfield ProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x27, 934, (Destin->ProtocolConfigurationOptions))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedProtocolConfigurationOptions
	------------------------------------------------------*/
	/* Detect IEI tag 0x7B */
	ED_EXPECT_OPTIONAL_IE (0x7B,  8, 936, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:937> Size error decoding IE ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7B, 937, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsProtocolCfgOpt (Buffer, CurrOfs, Destin->ExtendedProtocolConfigurationOptions, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:938> Error decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7B, 938, (Destin->ExtendedProtocolConfigurationOptions))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:939> Message too short decoding subfield ExtendedProtocolConfigurationOptions\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7B, 938, (Destin->ExtendedProtocolConfigurationOptions))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_REMOTE_UE_REPORT (char* Buffer, ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 233, 8);
		CurrOfs += 8;
		

	}
	
	
	/* Code for RemoteUEContextConnected */
	{
		int TLV_Base = CurrOfs;
		if (Source->RemoteUEContextConnected_Present) {
			/* Append to buffer IEI tag 0x79 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x79), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RemoteUEContextConnected> DOT=<->> */
			Len = ENCODE_c_RemoteUEContext (Buffer, CurrOfs+16, Source->RemoteUEContextConnected);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:940> Error encoding subfield RemoteUEContextConnected\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}
	
	/* Code for RemoteUEContextDisconnected */
	{
		int TLV_Base = CurrOfs;
		if (Source->RemoteUEContextDisconnected_Present) {
			/* Append to buffer IEI tag 0x7A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x7A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->RemoteUEContextDisconnected> DOT=<->> */
			Len = ENCODE_c_RemoteUEContext (Buffer, CurrOfs+16, Source->RemoteUEContextDisconnected);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:941> Error encoding subfield RemoteUEContextDisconnected\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}
	
	/* Code for ProSeKeyManagementFunctionAddr */
	{
		int TLV_Base = CurrOfs;
		if (Source->ProSeKeyManagementFunctionAddr_Present) {
			/* Append to buffer IEI tag 0x6F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ProSeKeyManagementFunctionAddr> DOT=<->> */
			Len = ENCODE_c_PKMFAddress (Buffer, CurrOfs+8, Source->ProSeKeyManagementFunctionAddr);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:942> Error encoding subfield ProSeKeyManagementFunctionAddr\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_REMOTE_UE_REPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT* ED_CONST Source))
{
	return L3_ENCODE_c_REMOTE_UE_REPORT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_REMOTE_UE_REPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_REMOTE_UE_REPORT* ED_CONST Source))
{
	return L3_ENCODE_c_REMOTE_UE_REPORT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_REMOTE_UE_REPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REMOTE_UE_REPORT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_REMOTE_UE_REPORT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE REMOTE_UE_REPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_REMOTE_UE_REPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_REMOTE_UE_REPORT* ED_CONST Destin, ED_EXLONG Length))
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
		{121, 255, ED_SKIPLIST_OPTIONAL},
		{122, 255, ED_SKIPLIST_OPTIONAL},
		{111, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE RemoteUEContextConnected
	------------------------------------------------------*/
	/* Detect IEI tag 0x79 */
	ED_EXPECT_OPTIONAL_IE (0x79,  8, 943, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x79) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:944> Size error decoding IE RemoteUEContextConnected\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x79, 944, (Destin->RemoteUEContextConnected))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RemoteUEContext (Buffer, CurrOfs, Destin->RemoteUEContextConnected, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:945> Error decoding subfield RemoteUEContextConnected\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x79, 945, (Destin->RemoteUEContextConnected))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:946> Message too short decoding subfield RemoteUEContextConnected\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x79, 945, (Destin->RemoteUEContextConnected))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE RemoteUEContextDisconnected
	------------------------------------------------------*/
	/* Detect IEI tag 0x7A */
	ED_EXPECT_OPTIONAL_IE (0x7A,  8, 947, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x7A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:948> Size error decoding IE RemoteUEContextDisconnected\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x7A, 948, (Destin->RemoteUEContextDisconnected))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_RemoteUEContext (Buffer, CurrOfs, Destin->RemoteUEContextDisconnected, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:949> Error decoding subfield RemoteUEContextDisconnected\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x7A, 949, (Destin->RemoteUEContextDisconnected))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:950> Message too short decoding subfield RemoteUEContextDisconnected\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x7A, 949, (Destin->RemoteUEContextDisconnected))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ProSeKeyManagementFunctionAddr
	------------------------------------------------------*/
	/* Detect IEI tag 0x6F */
	ED_EXPECT_OPTIONAL_IE (0x6F,  8, 951, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 136)) {
			ED_SIGNAL_ERROR ("<ERRID:952> Size error decoding IE ProSeKeyManagementFunctionAddr\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6F, 952, (Destin->ProSeKeyManagementFunctionAddr))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PKMFAddress (Buffer, CurrOfs, Destin->ProSeKeyManagementFunctionAddr, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:953> Error decoding subfield ProSeKeyManagementFunctionAddr\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6F, 953, (Destin->ProSeKeyManagementFunctionAddr))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:954> Message too short decoding subfield ProSeKeyManagementFunctionAddr\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6F, 953, (Destin->ProSeKeyManagementFunctionAddr))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_DATA_TRANSPORT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ESM_DATA_TRANSPORT (char* Buffer, ED_EXLONG BitOffset, const c_ESM_DATA_TRANSPORT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 235, 8);
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
			ED_SIGNAL_ERROR ("<ERRID:955> Error encoding subfield UserDataContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+16;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
	}
	
	/* Code for ReleaseAssistanceIndication */
	{
		if (Source->ReleaseAssistanceIndication_Present) {
			/* Append to buffer IEI tag 0x0F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0F), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ReleaseAssistanceIndication> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ReleaseAssistanceIndication), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:956> Error encoding subfield ReleaseAssistanceIndication\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_DATA_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ESM_DATA_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DATA_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_DATA_TRANSPORT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ESM_DATA_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ESM_DATA_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ESM_DATA_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_ESM_DATA_TRANSPORT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_DATA_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ESM_DATA_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DATA_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the EPS bearer identity */
	Destin->EPSBearerIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

/* Decode the procedure transaction identity */
	Destin->ProcedureTransactionIdentity = (ED_OCTET)EDBitsToInt (Buffer, BitOffset+8, 8);

	Len = DECODE_BODY_c_ESM_DATA_TRANSPORT (Buffer, (BitOffset+24), Destin, Length-(24));
	if (Len < 0) return Len;
	
	return Len+24;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ESM_DATA_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ESM_DATA_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ESM_DATA_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:957> Size error decoding IE UserDataContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 957, (Destin->UserDataContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13398=EDCore::TDMBinary) */Destin->UserDataContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_ESM_DATA_TRANSPORT_UserDataContainer (&(Destin->UserDataContainer), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:958> Error decoding subfield UserDataContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 958, (Destin->UserDataContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:959> Message too short decoding subfield UserDataContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 958, (Destin->UserDataContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReleaseAssistanceIndication
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 960, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->ReleaseAssistanceIndication = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13400=EDCore::TDMOctet) */Destin->ReleaseAssistanceIndication___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:961> Error decoding subfield ReleaseAssistanceIndication\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 961, (Destin->ReleaseAssistanceIndication))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:962> Message too short decoding subfield ReleaseAssistanceIndication\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 961, (Destin->ReleaseAssistanceIndication))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 198) /* message type */
	);
}

int Match_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 199) /* message type */
	);
}

int Match_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 194) /* message type */
	);
}

int Match_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 195) /* message type */
	);
}

int Match_c_BEARER_RESOURCE_ALLOCATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 212) /* message type */
	);
}

int Match_c_BEARER_RESOURCE_MODIFICATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 214) /* message type */
	);
}

int Match_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 206) /* message type */
	);
}

int Match_c_ESM_DUMMY_MESSAGE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 220) /* message type */
	);
}

int Match_c_ESM_INFORMATION_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 218) /* message type */
	);
}

int Match_c_ESM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 232) /* message type */
	);
}

int Match_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 202) /* message type */
	);
}

int Match_c_MODIFY_EPS_BEARER_CONTEXT_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 203) /* message type */
	);
}

int Match_c_PDN_CONNECTIVITY_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 208) /* message type */
	);
}

int Match_c_PDN_DISCONNECT_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 210) /* message type */
	);
}

int Match_c_REMOTE_UE_REPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 233) /* message type */
	);
}

int Match_c_ESM_DATA_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 2) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 235) /* message type */
	);
}

