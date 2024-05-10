/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "EPS_MM_Downlink_EPS.h"
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_ACCEPT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 66, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EPSAttachResult */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EPSAttachResult> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->EPSAttachResult), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:351> Error encoding subfield EPSAttachResult\n");
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
			ED_SIGNAL_ERROR ("<ERRID:352> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3412Value */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->T3412Value> DOT=<.> */
		Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, (&(Source->T3412Value)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:353> Error encoding subfield T3412Value\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for TAIList */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->TAIList> DOT=<.> */
		Len = ENCODE_c_PartialTrackingAreaIdentityList (Buffer, CurrOfs+8, (&(Source->TAIList)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:354> Error encoding subfield TAIList\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for ESMMessageContainer */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ESMMessageContainer> DOT=<.> */
		Len = ENCODE_c_ESMMessageDn (Buffer, CurrOfs+16, (&(Source->ESMMessageContainer)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:355> Error encoding subfield ESMMessageContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+16;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
	}
	
	/* Code for GUTI */
	{
		int TLV_Base = CurrOfs;
		if (Source->GUTI_Present) {
			/* Append to buffer IEI tag 0x50 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x50), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->GUTI> DOT=<->> */
			Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, Source->GUTI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:356> Error encoding subfield GUTI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LocationAreaIdentification */
	{
		if (Source->LocationAreaIdentification_Present) {
			/* Append to buffer IEI tag 0x13 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x13), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LocationAreaIdentification> DOT=<->> */
			Len = ENCODE_c_epsLocationAreaId (Buffer, CurrOfs, Source->LocationAreaIdentification);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:357> Error encoding subfield LocationAreaIdentification\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for MSIdentity */
	{
		int TLV_Base = CurrOfs;
		if (Source->MSIdentity_Present) {
			/* Append to buffer IEI tag 0x23 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x23), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MSIdentity> DOT=<->> */
			Len = ENCODE_c_epsMobileId (Buffer, CurrOfs+8, Source->MSIdentity);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:358> Error encoding subfield MSIdentity\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EMMCause */
	{
		if (Source->EMMCause_Present) {
			/* Append to buffer IEI tag 0x53 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x53), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:359> Error encoding subfield EMMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3402Value */
	{
		if (Source->T3402Value_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->T3402Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, Source->T3402Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:360> Error encoding subfield T3402Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3423Value */
	{
		if (Source->T3423Value_Present) {
			/* Append to buffer IEI tag 0x59 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x59), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->T3423Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, Source->T3423Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:361> Error encoding subfield T3423Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for EquivalentPLMNs */
	{
		int TLV_Base = CurrOfs;
		if (Source->EquivalentPLMNs_Present) {
			/* Append to buffer IEI tag 0x4A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EquivalentPLMNs> DOT=<->> */
			Len = ENCODE_c_epsPlmnList (Buffer, CurrOfs+8, Source->EquivalentPLMNs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:362> Error encoding subfield EquivalentPLMNs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for epsEmergencyNumberList */
	{
		int TLV_Base = CurrOfs;
		if (Source->epsEmergencyNumberList_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->epsEmergencyNumberList> DOT=<->> */
			Len = ENCODE_c_epsEmergencyNumberList (Buffer, CurrOfs+8, Source->epsEmergencyNumberList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:363> Error encoding subfield epsEmergencyNumberList\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EPSNetworkFeatureSupport */
	{
		int TLV_Base = CurrOfs;
		if (Source->EPSNetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x64 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x64), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EPSNetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_EPSNetworkFeatureSupport (Buffer, CurrOfs+8, Source->EPSNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:364> Error encoding subfield EPSNetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalUpdateResult */
	{
		if (Source->AdditionalUpdateResult_Present) {
			/* Append to buffer IEI tag 0x0F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0F), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalUpdateResult> DOT=<->> */
			Len = ENCODE_c_AdditionalUpdateResult (Buffer, CurrOfs, Source->AdditionalUpdateResult);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:365> Error encoding subfield AdditionalUpdateResult\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3412ExtendedValue */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3412ExtendedValue_Present) {
			/* Append to buffer IEI tag 0x5E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3412ExtendedValue> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs+8, Source->T3412ExtendedValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:366> Error encoding subfield T3412ExtendedValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3324ValueGPRSTimer2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3324ValueGPRSTimer2_Present) {
			/* Append to buffer IEI tag 0x6A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3324ValueGPRSTimer2> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer2 (Buffer, CurrOfs+8, Source->T3324ValueGPRSTimer2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:367> Error encoding subfield T3324ValueGPRSTimer2\n");
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
			Len = ENCODE_c_epsExtendedDRXParameters (Buffer, CurrOfs+8, Source->ExtendedDRXParameters);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:368> Error encoding subfield ExtendedDRXParameters\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_ATTACH_ACCEPT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{80, 255, ED_SKIPLIST_OPTIONAL},
		{19, 255, ED_SKIPLIST_OPTIONAL},
		{35, 255, ED_SKIPLIST_OPTIONAL},
		{83, 255, ED_SKIPLIST_OPTIONAL},
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{89, 255, ED_SKIPLIST_OPTIONAL},
		{74, 255, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{100, 255, ED_SKIPLIST_OPTIONAL},
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
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
		Code for IE EPSAttachResult
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->EPSAttachResult = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12987=EDCore::TDMOctet) */Destin->EPSAttachResult___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:369> Error decoding subfield EPSAttachResult\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 369, (Destin->EPSAttachResult))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:370> Message too short decoding subfield EPSAttachResult\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 369, (Destin->EPSAttachResult))
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
		ED_SIGNAL_ERROR ("<ERRID:371> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 371, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:372> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 371, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3412Value
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, (&(Destin->T3412Value)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:373> Error decoding subfield T3412Value\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 373, (Destin->T3412Value))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:374> Message too short decoding subfield T3412Value\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 373, (Destin->T3412Value))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TAIList
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 48) || (Len > 768)) {
		ED_SIGNAL_ERROR ("<ERRID:375> Size error decoding IE TAIList\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 375, (Destin->TAIList))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_PartialTrackingAreaIdentityList (Buffer, CurrOfs, (&(Destin->TAIList)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:376> Error decoding subfield TAIList\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 376, (Destin->TAIList))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:377> Message too short decoding subfield TAIList\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 376, (Destin->TAIList))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ESMMessageContainer
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 16);
	CurrOfs += 16;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 4784) {
		ED_SIGNAL_ERROR ("<ERRID:378> Size error decoding IE ESMMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 378, (Destin->ESMMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_ESMMessageDn (Buffer, CurrOfs, (&(Destin->ESMMessageContainer)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:379> Error decoding subfield ESMMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 379, (Destin->ESMMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:380> Message too short decoding subfield ESMMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 379, (Destin->ESMMessageContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE GUTI
	------------------------------------------------------*/
	/* Detect IEI tag 0x50 */
	ED_EXPECT_OPTIONAL_IE (0x50,  8, 381, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x50) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_GUTI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 88) {
			ED_SIGNAL_ERROR ("<ERRID:382> Size error decoding IE GUTI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_GUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x50, 382, (Destin->GUTI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, Destin->GUTI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:383> Error decoding subfield GUTI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_GUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x50, 383, (Destin->GUTI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:384> Message too short decoding subfield GUTI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_GUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x50, 383, (Destin->GUTI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LocationAreaIdentification
	------------------------------------------------------*/
	/* Detect IEI tag 0x13 */
	ED_EXPECT_OPTIONAL_IE (0x13,  8, 385, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x13) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_LocationAreaIdentification (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLocationAreaId (Buffer, CurrOfs, Destin->LocationAreaIdentification, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:386> Error decoding subfield LocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_LocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x13, 386, (Destin->LocationAreaIdentification))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:387> Message too short decoding subfield LocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_LocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x13, 386, (Destin->LocationAreaIdentification))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSIdentity
	------------------------------------------------------*/
	/* Detect IEI tag 0x23 */
	ED_EXPECT_OPTIONAL_IE (0x23,  8, 388, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x23) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_MSIdentity (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 40) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:389> Size error decoding IE MSIdentity\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_MSIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x23, 389, (Destin->MSIdentity))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMobileId (Buffer, CurrOfs, Destin->MSIdentity, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:390> Error decoding subfield MSIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_MSIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x23, 390, (Destin->MSIdentity))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:391> Message too short decoding subfield MSIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_MSIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x23, 390, (Destin->MSIdentity))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EMMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x53 */
	ED_EXPECT_OPTIONAL_IE (0x53,  8, 392, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x53) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EMMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13003=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:393> Error decoding subfield EMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x53, 393, (Destin->EMMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:394> Message too short decoding subfield EMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x53, 393, (Destin->EMMCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3402Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 395, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3402Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3402Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:396> Error decoding subfield T3402Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 396, (Destin->T3402Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:397> Message too short decoding subfield T3402Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 396, (Destin->T3402Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3423Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x59 */
	ED_EXPECT_OPTIONAL_IE (0x59,  8, 398, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x59) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3423Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3423Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:399> Error decoding subfield T3423Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3423Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x59, 399, (Destin->T3423Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:400> Message too short decoding subfield T3423Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3423Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x59, 399, (Destin->T3423Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EquivalentPLMNs
	------------------------------------------------------*/
	/* Detect IEI tag 0x4A */
	ED_EXPECT_OPTIONAL_IE (0x4A,  8, 401, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x4A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 360)) {
			ED_SIGNAL_ERROR ("<ERRID:402> Size error decoding IE EquivalentPLMNs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4A, 402, (Destin->EquivalentPLMNs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsPlmnList (Buffer, CurrOfs, Destin->EquivalentPLMNs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:403> Error decoding subfield EquivalentPLMNs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4A, 403, (Destin->EquivalentPLMNs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:404> Message too short decoding subfield EquivalentPLMNs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4A, 403, (Destin->EquivalentPLMNs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE epsEmergencyNumberList
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 405, 12, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 384)) {
			ED_SIGNAL_ERROR ("<ERRID:406> Size error decoding IE epsEmergencyNumberList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 406, (Destin->epsEmergencyNumberList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsEmergencyNumberList (Buffer, CurrOfs, Destin->epsEmergencyNumberList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:407> Error decoding subfield epsEmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 407, (Destin->epsEmergencyNumberList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:408> Message too short decoding subfield epsEmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 407, (Destin->epsEmergencyNumberList))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EPSNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x64 */
	ED_EXPECT_OPTIONAL_IE (0x64,  8, 409, 13, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x64) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:410> Size error decoding IE EPSNetworkFeatureSupport\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x64, 410, (Destin->EPSNetworkFeatureSupport))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSNetworkFeatureSupport (Buffer, CurrOfs, Destin->EPSNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:411> Error decoding subfield EPSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x64, 411, (Destin->EPSNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:412> Message too short decoding subfield EPSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x64, 411, (Destin->EPSNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateResult
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 413, 14, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_AdditionalUpdateResult (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalUpdateResult (Buffer, CurrOfs, Destin->AdditionalUpdateResult, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:414> Error decoding subfield AdditionalUpdateResult\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_AdditionalUpdateResult (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 414, (Destin->AdditionalUpdateResult))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:415> Message too short decoding subfield AdditionalUpdateResult\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_AdditionalUpdateResult (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 414, (Destin->AdditionalUpdateResult))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3412ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 416, 15, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:417> Size error decoding IE T3412ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 417, (Destin->T3412ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3412ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:418> Error decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 418, (Destin->T3412ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:419> Message too short decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 418, (Destin->T3412ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324ValueGPRSTimer2
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 420, 16, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:421> Size error decoding IE T3324ValueGPRSTimer2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 421, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3324ValueGPRSTimer2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:422> Error decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 422, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:423> Message too short decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 422, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 424, 17, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:425> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 425, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:426> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 426, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:427> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 426, (Destin->ExtendedDRXParameters))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 68, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EMMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:428> Error encoding subfield EMMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ESMMessageContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->ESMMessageContainer_Present) {
			/* Append to buffer IEI tag 0x78 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x78), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ESMMessageContainer> DOT=<->> */
			Len = ENCODE_c_ESMMessageDn (Buffer, CurrOfs+16, Source->ESMMessageContainer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:429> Error encoding subfield ESMMessageContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}
	
	/* Code for T3346Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3346Value_Present) {
			/* Append to buffer IEI tag 0x5F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3346Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer2 (Buffer, CurrOfs+8, Source->T3346Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:430> Error encoding subfield T3346Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3402Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3402Value_Present) {
			/* Append to buffer IEI tag 0x16 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x16), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3402Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer2 (Buffer, CurrOfs+8, Source->T3402Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:431> Error encoding subfield T3402Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedEMMCause */
	{
		if (Source->ExtendedEMMCause_Present) {
			/* Append to buffer IEI tag 0x0A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0A), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedEMMCause> DOT=<->> */
			Len = ENCODE_c_ExtendedEMMCause (Buffer, CurrOfs, Source->ExtendedEMMCause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:432> Error encoding subfield ExtendedEMMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_ATTACH_REJECT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{120, 255, ED_SKIPLIST_OPTIONAL},
		{95, 255, ED_SKIPLIST_OPTIONAL},
		{22, 255, ED_SKIPLIST_OPTIONAL},
		{160, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EMMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13026=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:433> Error decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 433, (Destin->EMMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:434> Message too short decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 433, (Destin->EMMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ESMMessageContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x78 */
	ED_EXPECT_OPTIONAL_IE (0x78,  8, 435, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x78) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ESMMessageContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:436> Size error decoding IE ESMMessageContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ESMMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x78, 436, (Destin->ESMMessageContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ESMMessageDn (Buffer, CurrOfs, Destin->ESMMessageContainer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:437> Error decoding subfield ESMMessageContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ESMMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x78, 437, (Destin->ESMMessageContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:438> Message too short decoding subfield ESMMessageContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ESMMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x78, 437, (Destin->ESMMessageContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3346Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x5F */
	ED_EXPECT_OPTIONAL_IE (0x5F,  8, 439, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3346Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:440> Size error decoding IE T3346Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5F, 440, (Destin->T3346Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3346Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:441> Error decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5F, 441, (Destin->T3346Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:442> Message too short decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5F, 441, (Destin->T3346Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3402Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x16 */
	ED_EXPECT_OPTIONAL_IE (0x16,  8, 443, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x16) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3402Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:444> Size error decoding IE T3402Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x16, 444, (Destin->T3402Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3402Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:445> Error decoding subfield T3402Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x16, 445, (Destin->T3402Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:446> Message too short decoding subfield T3402Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x16, 445, (Destin->T3402Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedEMMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x0A */
	ED_EXPECT_OPTIONAL_IE (0x0A,  4, 447, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ExtendedEMMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ExtendedEMMCause (Buffer, CurrOfs, Destin->ExtendedEMMCause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:448> Error decoding subfield ExtendedEMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ExtendedEMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0A, 448, (Destin->ExtendedEMMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:449> Message too short decoding subfield ExtendedEMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REJECT_ExtendedEMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0A, 448, (Destin->ExtendedEMMCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 84, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_AUTHENTICATION_REJECT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 82, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NASKeySetIdentifierASME */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifierASME> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs+4), (&(Source->NASKeySetIdentifierASME)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:450> Error encoding subfield NASKeySetIdentifierASME\n");
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
			ED_SIGNAL_ERROR ("<ERRID:451> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthenticationParameterRANDEPSChallenge */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->AuthenticationParameterRANDEPSChallenge> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs, (Source->AuthenticationParameterRANDEPSChallenge), 0, 128);
		Len = 128;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:452> Error encoding subfield AuthenticationParameterRANDEPSChallenge\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthenticationParameterAUTNEPSChallenge */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->AuthenticationParameterAUTNEPSChallenge> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, (Source->AuthenticationParameterAUTNEPSChallenge), 0, 128);
		Len = 128;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:453> Error encoding subfield AuthenticationParameterAUTNEPSChallenge\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_AUTHENTICATION_REQUEST (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE NASKeySetIdentifierASME
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs+4), (&(Destin->NASKeySetIdentifierASME)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:454> Error decoding subfield NASKeySetIdentifierASME\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 454, (Destin->NASKeySetIdentifierASME))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:455> Message too short decoding subfield NASKeySetIdentifierASME\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 454, (Destin->NASKeySetIdentifierASME))
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
		ED_SIGNAL_ERROR ("<ERRID:456> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 456, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:457> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 456, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthenticationParameterRANDEPSChallenge
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 128;
	/* Read value part LOCATOR_16 */
	EDCopyBits (Destin->AuthenticationParameterRANDEPSChallenge, 0, Buffer, CurrOfs, 128);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13046=EDCore::TDMBinary) */Destin->AuthenticationParameterRANDEPSChallenge___LOCATOR), CurrOfs, 128);
	RetLen = 128;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:458> Error decoding subfield AuthenticationParameterRANDEPSChallenge\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 458, (Destin->AuthenticationParameterRANDEPSChallenge))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:459> Message too short decoding subfield AuthenticationParameterRANDEPSChallenge\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 458, (Destin->AuthenticationParameterRANDEPSChallenge))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthenticationParameterAUTNEPSChallenge
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 128) {
		ED_SIGNAL_ERROR ("<ERRID:460> Size error decoding IE AuthenticationParameterAUTNEPSChallenge\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 460, (Destin->AuthenticationParameterAUTNEPSChallenge))
	} 
#endif
	/* Read value part LOCATOR_16 */
	EDCopyBits (Destin->AuthenticationParameterAUTNEPSChallenge, 0, Buffer, CurrOfs, 128);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13048=EDCore::TDMBinary) */Destin->AuthenticationParameterAUTNEPSChallenge___LOCATOR), CurrOfs, 128);
	RetLen = 128;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:461> Error decoding subfield AuthenticationParameterAUTNEPSChallenge\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 461, (Destin->AuthenticationParameterAUTNEPSChallenge))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:462> Message too short decoding subfield AuthenticationParameterAUTNEPSChallenge\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 461, (Destin->AuthenticationParameterAUTNEPSChallenge))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CS_SERVICE_NOTIFICATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CS_SERVICE_NOTIFICATION (char* Buffer, ED_EXLONG BitOffset, const c_CS_SERVICE_NOTIFICATION* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 100, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for PagingIdentity */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->PagingIdentity> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->PagingIdentity), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:463> Error encoding subfield PagingIdentity\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for CLI */
	{
		int TLV_Base = CurrOfs;
		if (Source->CLI_Present) {
			/* Append to buffer IEI tag 0x60 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x60), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->CLI> DOT=<->> */
			Len = ENCODE_c_epsCallingPartyBcdNum (Buffer, CurrOfs+8, Source->CLI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:464> Error encoding subfield CLI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for SSCode */
	{
		if (Source->SSCode_Present) {
			/* Append to buffer IEI tag 0x61 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x61), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->SSCode> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->SSCode), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:465> Error encoding subfield SSCode\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for LCSIndicator */
	{
		if (Source->LCSIndicator_Present) {
			/* Append to buffer IEI tag 0x62 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x62), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LCSIndicator> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->LCSIndicator), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:466> Error encoding subfield LCSIndicator\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for LCSClientId */
	{
		int TLV_Base = CurrOfs;
		if (Source->LCSClientId_Present) {
			/* Append to buffer IEI tag 0x63 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x63), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->LCSClientId> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->LCSClientId->value, 0, Source->LCSClientId->usedBits);
			Len = Source->LCSClientId->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:467> Error encoding subfield LCSClientId\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CS_SERVICE_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CS_SERVICE_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CS_SERVICE_NOTIFICATION* ED_CONST Source))
{
	return L3_ENCODE_c_CS_SERVICE_NOTIFICATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CS_SERVICE_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CS_SERVICE_NOTIFICATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CS_SERVICE_NOTIFICATION* ED_CONST Source))
{
	return L3_ENCODE_c_CS_SERVICE_NOTIFICATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CS_SERVICE_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CS_SERVICE_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CS_SERVICE_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_CS_SERVICE_NOTIFICATION (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CS_SERVICE_NOTIFICATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CS_SERVICE_NOTIFICATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CS_SERVICE_NOTIFICATION* ED_CONST Destin, ED_EXLONG Length))
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
		{96, 255, ED_SKIPLIST_OPTIONAL},
		{97, 255, ED_SKIPLIST_OPTIONAL},
		{98, 255, ED_SKIPLIST_OPTIONAL},
		{99, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE PagingIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->PagingIdentity = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13053=EDCore::TDMOctet) */Destin->PagingIdentity___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:468> Error decoding subfield PagingIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 468, (Destin->PagingIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:469> Message too short decoding subfield PagingIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 468, (Destin->PagingIdentity))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE CLI
	------------------------------------------------------*/
	/* Detect IEI tag 0x60 */
	ED_EXPECT_OPTIONAL_IE (0x60,  8, 470, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x60) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 96)) {
			ED_SIGNAL_ERROR ("<ERRID:471> Size error decoding IE CLI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x60, 471, (Destin->CLI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsCallingPartyBcdNum (Buffer, CurrOfs, Destin->CLI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:472> Error decoding subfield CLI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x60, 472, (Destin->CLI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:473> Message too short decoding subfield CLI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x60, 472, (Destin->CLI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SSCode
	------------------------------------------------------*/
	/* Detect IEI tag 0x61 */
	ED_EXPECT_OPTIONAL_IE (0x61,  8, 474, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x61) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_SSCode (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->SSCode = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13057=EDCore::TDMOctet) */Destin->SSCode___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:475> Error decoding subfield SSCode\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_SSCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x61, 475, (Destin->SSCode))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:476> Message too short decoding subfield SSCode\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_SSCode (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x61, 475, (Destin->SSCode))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LCSIndicator
	------------------------------------------------------*/
	/* Detect IEI tag 0x62 */
	ED_EXPECT_OPTIONAL_IE (0x62,  8, 477, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x62) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSIndicator (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->LCSIndicator = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13059=EDCore::TDMOctet) */Destin->LCSIndicator___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:478> Error decoding subfield LCSIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x62, 478, (Destin->LCSIndicator))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:479> Message too short decoding subfield LCSIndicator\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSIndicator (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x62, 478, (Destin->LCSIndicator))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LCSClientId
	------------------------------------------------------*/
	/* Detect IEI tag 0x63 */
	ED_EXPECT_OPTIONAL_IE (0x63,  8, 480, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x63) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 2040)) {
			ED_SIGNAL_ERROR ("<ERRID:481> Size error decoding IE LCSClientId\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x63, 481, (Destin->LCSClientId))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13061=EDCore::TDMBinary) */Destin->LCSClientId___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CS_SERVICE_NOTIFICATION_LCSClientId (Destin->LCSClientId, Len);
		
			if (Destin->LCSClientId->value) {
				EDCopyBits (Destin->LCSClientId->value, 0, Buffer, CurrOfs, Len);
				Destin->LCSClientId->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->LCSClientId->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:482> Error decoding subfield LCSClientId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x63, 482, (Destin->LCSClientId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:483> Message too short decoding subfield LCSClientId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x63, 482, (Destin->LCSClientId))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EPS_DETACH_ACCEPT_DN (char* Buffer, ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 70, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_ACCEPT_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_ACCEPT_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_DN* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_ACCEPT_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EPS_DETACH_ACCEPT_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_ACCEPT_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_DN* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_DN
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EPS_DETACH_REQUEST_DN (char* Buffer, ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_DN* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 69, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for DetachType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->DetachType> DOT=<.> */
		Len = ENCODE_c_EPSDetachType (Buffer, (CurrOfs+4), (&(Source->DetachType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:484> Error encoding subfield DetachType\n");
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
			ED_SIGNAL_ERROR ("<ERRID:485> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for EMMCause */
	{
		if (Source->EMMCause_Present) {
			/* Append to buffer IEI tag 0x53 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x53), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:486> Error encoding subfield EMMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_REQUEST_DN (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_REQUEST_DN (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_DN* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_REQUEST_DN (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EPS_DETACH_REQUEST_DN (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_DN
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_REQUEST_DN (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_DN* ED_CONST Destin, ED_EXLONG Length))
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
		{83, 255, ED_SKIPLIST_OPTIONAL},
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
	RetLen = DECODE_c_EPSDetachType (Buffer, (CurrOfs+4), (&(Destin->DetachType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:487> Error decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 487, (Destin->DetachType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:488> Message too short decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 487, (Destin->DetachType))
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
		ED_SIGNAL_ERROR ("<ERRID:489> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 489, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:490> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 489, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE EMMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x53 */
	ED_EXPECT_OPTIONAL_IE (0x53,  8, 491, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x53) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EPS_DETACH_REQUEST_DN_EMMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13073=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:492> Error decoding subfield EMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EPS_DETACH_REQUEST_DN_EMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x53, 492, (Destin->EMMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:493> Message too short decoding subfield EMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EPS_DETACH_REQUEST_DN_EMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x53, 492, (Destin->EMMCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_NAS_TRANSPORT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DOWNLINK_NAS_TRANSPORT (char* Buffer, ED_EXLONG BitOffset, const c_DOWNLINK_NAS_TRANSPORT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 98, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for NASMessageContainer */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->NASMessageContainer> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, Source->NASMessageContainer.value, 0, Source->NASMessageContainer.usedBits);
		Len = Source->NASMessageContainer.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:494> Error encoding subfield NASMessageContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DOWNLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_DOWNLINK_NAS_TRANSPORT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DOWNLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_DOWNLINK_NAS_TRANSPORT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DOWNLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_DOWNLINK_NAS_TRANSPORT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DOWNLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE NASMessageContainer
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 2008)) {
		ED_SIGNAL_ERROR ("<ERRID:495> Size error decoding IE NASMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 495, (Destin->NASMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13078=EDCore::TDMBinary) */Destin->NASMessageContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer (&(Destin->NASMessageContainer), Len);
	
		if (Destin->NASMessageContainer.value) {
			EDCopyBits (Destin->NASMessageContainer.value, 0, Buffer, CurrOfs, Len);
			Destin->NASMessageContainer.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->NASMessageContainer.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:496> Error decoding subfield NASMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 496, (Destin->NASMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:497> Message too short decoding subfield NASMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 496, (Destin->NASMessageContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EMM_INFORMATION
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EMM_INFORMATION (char* Buffer, ED_EXLONG BitOffset, const c_EMM_INFORMATION* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 97, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for FullNameForNetwork */
	{
		int TLV_Base = CurrOfs;
		if (Source->FullNameForNetwork_Present) {
			/* Append to buffer IEI tag 0x43 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x43), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->FullNameForNetwork> DOT=<->> */
			Len = ENCODE_c_epsNetwkName (Buffer, CurrOfs+8, Source->FullNameForNetwork);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:498> Error encoding subfield FullNameForNetwork\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ShortNameForNetwork */
	{
		int TLV_Base = CurrOfs;
		if (Source->ShortNameForNetwork_Present) {
			/* Append to buffer IEI tag 0x45 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x45), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->ShortNameForNetwork> DOT=<->> */
			Len = ENCODE_c_epsNetwkName (Buffer, CurrOfs+8, Source->ShortNameForNetwork);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:499> Error encoding subfield ShortNameForNetwork\n");
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
				ED_SIGNAL_ERROR ("<ERRID:500> Error encoding subfield LocalTimeZone\n");
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
			Len = ENCODE_c_epsTimeZoneAndTime (Buffer, CurrOfs, Source->UniversalTimeAndLocalTimeZone);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:501> Error encoding subfield UniversalTimeAndLocalTimeZone\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NetworkDaylightSavingTime */
	{
		int TLV_Base = CurrOfs;
		if (Source->NetworkDaylightSavingTime_Present) {
			/* Append to buffer IEI tag 0x49 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x49), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NetworkDaylightSavingTime> DOT=<->> */
			Len = ENCODE_c_epsDaylightSavingTime (Buffer, CurrOfs+8, Source->NetworkDaylightSavingTime);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:502> Error encoding subfield NetworkDaylightSavingTime\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EMM_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EMM_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_INFORMATION* ED_CONST Source))
{
	return L3_ENCODE_c_EMM_INFORMATION (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EMM_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EMM_INFORMATION (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_INFORMATION* ED_CONST Source))
{
	return L3_ENCODE_c_EMM_INFORMATION (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EMM_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EMM_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EMM_INFORMATION (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EMM_INFORMATION
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EMM_INFORMATION (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_INFORMATION* ED_CONST Destin, ED_EXLONG Length))
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
		{73, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE FullNameForNetwork
	------------------------------------------------------*/
	/* Detect IEI tag 0x43 */
	ED_EXPECT_OPTIONAL_IE (0x43,  8, 503, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x43) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_FullNameForNetwork (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:504> Size error decoding IE FullNameForNetwork\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_FullNameForNetwork (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x43, 504, (Destin->FullNameForNetwork))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsNetwkName (Buffer, CurrOfs, Destin->FullNameForNetwork, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:505> Error decoding subfield FullNameForNetwork\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_FullNameForNetwork (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x43, 505, (Destin->FullNameForNetwork))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:506> Message too short decoding subfield FullNameForNetwork\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_FullNameForNetwork (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x43, 505, (Destin->FullNameForNetwork))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ShortNameForNetwork
	------------------------------------------------------*/
	/* Detect IEI tag 0x45 */
	ED_EXPECT_OPTIONAL_IE (0x45,  8, 507, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x45) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:508> Size error decoding IE ShortNameForNetwork\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x45, 508, (Destin->ShortNameForNetwork))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsNetwkName (Buffer, CurrOfs, Destin->ShortNameForNetwork, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:509> Error decoding subfield ShortNameForNetwork\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x45, 509, (Destin->ShortNameForNetwork))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:510> Message too short decoding subfield ShortNameForNetwork\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x45, 509, (Destin->ShortNameForNetwork))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LocalTimeZone
	------------------------------------------------------*/
	/* Detect IEI tag 0x46 */
	ED_EXPECT_OPTIONAL_IE (0x46,  8, 511, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x46) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_LocalTimeZone (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->LocalTimeZone = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 8);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13087=EDCore::TDMInteger) */Destin->LocalTimeZone___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:512> Error decoding subfield LocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_LocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x46, 512, (Destin->LocalTimeZone))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:513> Message too short decoding subfield LocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_LocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x46, 512, (Destin->LocalTimeZone))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UniversalTimeAndLocalTimeZone
	------------------------------------------------------*/
	/* Detect IEI tag 0x47 */
	ED_EXPECT_OPTIONAL_IE (0x47,  8, 514, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x47) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 56;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsTimeZoneAndTime (Buffer, CurrOfs, Destin->UniversalTimeAndLocalTimeZone, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:515> Error decoding subfield UniversalTimeAndLocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x47, 515, (Destin->UniversalTimeAndLocalTimeZone))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:516> Message too short decoding subfield UniversalTimeAndLocalTimeZone\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x47, 515, (Destin->UniversalTimeAndLocalTimeZone))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NetworkDaylightSavingTime
	------------------------------------------------------*/
	/* Detect IEI tag 0x49 */
	ED_EXPECT_OPTIONAL_IE (0x49,  8, 517, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x49) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:518> Size error decoding IE NetworkDaylightSavingTime\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x49, 518, (Destin->NetworkDaylightSavingTime))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDaylightSavingTime (Buffer, CurrOfs, Destin->NetworkDaylightSavingTime, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:519> Error decoding subfield NetworkDaylightSavingTime\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x49, 519, (Destin->NetworkDaylightSavingTime))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:520> Message too short decoding subfield NetworkDaylightSavingTime\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x49, 519, (Destin->NetworkDaylightSavingTime))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMMAND
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_GUTI_REALLOCATION_COMMAND (char* Buffer, ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMMAND* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 80, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GUTI */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->GUTI> DOT=<.> */
		Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, (&(Source->GUTI)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:521> Error encoding subfield GUTI\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for TAIList */
	{
		int TLV_Base = CurrOfs;
		if (Source->TAIList_Present) {
			/* Append to buffer IEI tag 0x54 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x54), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TAIList> DOT=<->> */
			Len = ENCODE_c_PartialTrackingAreaIdentityList (Buffer, CurrOfs+8, Source->TAIList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:522> Error encoding subfield TAIList\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GUTI_REALLOCATION_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMMAND* ED_CONST Source))
{
	return L3_ENCODE_c_GUTI_REALLOCATION_COMMAND (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GUTI_REALLOCATION_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMMAND* ED_CONST Source))
{
	return L3_ENCODE_c_GUTI_REALLOCATION_COMMAND (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GUTI_REALLOCATION_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMMAND* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_GUTI_REALLOCATION_COMMAND (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GUTI_REALLOCATION_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMMAND* ED_CONST Destin, ED_EXLONG Length))
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
		{84, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE GUTI
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 88) {
		ED_SIGNAL_ERROR ("<ERRID:523> Size error decoding IE GUTI\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 523, (Destin->GUTI))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, (&(Destin->GUTI)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:524> Error decoding subfield GUTI\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 524, (Destin->GUTI))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:525> Message too short decoding subfield GUTI\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 524, (Destin->GUTI))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE TAIList
	------------------------------------------------------*/
	/* Detect IEI tag 0x54 */
	ED_EXPECT_OPTIONAL_IE (0x54,  8, 526, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x54) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 48) || (Len > 768)) {
			ED_SIGNAL_ERROR ("<ERRID:527> Size error decoding IE TAIList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x54, 527, (Destin->TAIList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PartialTrackingAreaIdentityList (Buffer, CurrOfs, Destin->TAIList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:528> Error decoding subfield TAIList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x54, 528, (Destin->TAIList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:529> Message too short decoding subfield TAIList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x54, 528, (Destin->TAIList))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IDENTITY_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_IDENTITY_REQUEST* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 85, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for IdentityType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->IdentityType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->IdentityType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:530> Error encoding subfield IdentityType\n");
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
			ED_SIGNAL_ERROR ("<ERRID:531> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_IDENTITY_REQUEST (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE IdentityType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->IdentityType = (ED_OCTET)EDBitsToInt (Buffer, ((CurrOfs+4)), 4);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13103=EDCore::TDMInteger) */Destin->IdentityType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:532> Error decoding subfield IdentityType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 532, (Destin->IdentityType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:533> Message too short decoding subfield IdentityType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 532, (Destin->IdentityType))
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
		ED_SIGNAL_ERROR ("<ERRID:534> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 534, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:535> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 534, (Destin->SpareHalfOctet))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMMAND
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SECURITY_MODE_COMMAND (char* Buffer, ED_EXLONG BitOffset, const c_SECURITY_MODE_COMMAND* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 93, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for SelectedNASSecurityAlgorithms */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SelectedNASSecurityAlgorithms> DOT=<.> */
		Len = ENCODE_c_NASSecurityAlgorithms (Buffer, CurrOfs, (&(Source->SelectedNASSecurityAlgorithms)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:536> Error encoding subfield SelectedNASSecurityAlgorithms\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASKeySetIdentifier */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifier> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs+4), (&(Source->NASKeySetIdentifier)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:537> Error encoding subfield NASKeySetIdentifier\n");
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
			ED_SIGNAL_ERROR ("<ERRID:538> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for ReplayedUESecurityCapabilities */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ReplayedUESecurityCapabilities> DOT=<.> */
		Len = ENCODE_c_UESecurityCapability (Buffer, CurrOfs+8, (&(Source->ReplayedUESecurityCapabilities)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:539> Error encoding subfield ReplayedUESecurityCapabilities\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for IMEISVRequest */
	{
		if (Source->IMEISVRequest_Present) {
			/* Append to buffer IEI tag 0x0C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0C), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->IMEISVRequest> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->IMEISVRequest), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:540> Error encoding subfield IMEISVRequest\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for ReplayedNonceUE */
	{
		if (Source->ReplayedNonceUE_Present) {
			/* Append to buffer IEI tag 0x55 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x55), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->ReplayedNonceUE> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->ReplayedNonceUE), 32);
			Len = 32;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:541> Error encoding subfield ReplayedNonceUE\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for NonceMME */
	{
		if (Source->NonceMME_Present) {
			/* Append to buffer IEI tag 0x56 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x56), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NonceMME> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->NonceMME), 32);
			Len = 32;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:542> Error encoding subfield NonceMME\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_MODE_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMMAND* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_MODE_COMMAND (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_MODE_COMMAND (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMMAND* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_MODE_COMMAND (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_MODE_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMMAND* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SECURITY_MODE_COMMAND (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMMAND
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_MODE_COMMAND (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMMAND* ED_CONST Destin, ED_EXLONG Length))
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
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{85, 255, ED_SKIPLIST_OPTIONAL},
		{86, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE SelectedNASSecurityAlgorithms
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASSecurityAlgorithms (Buffer, CurrOfs, (&(Destin->SelectedNASSecurityAlgorithms)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:543> Error decoding subfield SelectedNASSecurityAlgorithms\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 543, (Destin->SelectedNASSecurityAlgorithms))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:544> Message too short decoding subfield SelectedNASSecurityAlgorithms\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 543, (Destin->SelectedNASSecurityAlgorithms))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASKeySetIdentifier
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs+4), (&(Destin->NASKeySetIdentifier)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:545> Error decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 545, (Destin->NASKeySetIdentifier))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:546> Message too short decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 545, (Destin->NASKeySetIdentifier))
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
		ED_SIGNAL_ERROR ("<ERRID:547> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 547, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:548> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 547, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ReplayedUESecurityCapabilities
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 40)) {
		ED_SIGNAL_ERROR ("<ERRID:549> Size error decoding IE ReplayedUESecurityCapabilities\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 549, (Destin->ReplayedUESecurityCapabilities))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_UESecurityCapability (Buffer, CurrOfs, (&(Destin->ReplayedUESecurityCapabilities)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:550> Error decoding subfield ReplayedUESecurityCapabilities\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 550, (Destin->ReplayedUESecurityCapabilities))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:551> Message too short decoding subfield ReplayedUESecurityCapabilities\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 550, (Destin->ReplayedUESecurityCapabilities))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE IMEISVRequest
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 552, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_IMEISVRequest (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->IMEISVRequest = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13118=EDCore::TDMInteger) */Destin->IMEISVRequest___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:553> Error decoding subfield IMEISVRequest\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_IMEISVRequest (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 553, (Destin->IMEISVRequest))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:554> Message too short decoding subfield IMEISVRequest\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_IMEISVRequest (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 553, (Destin->IMEISVRequest))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ReplayedNonceUE
	------------------------------------------------------*/
	/* Detect IEI tag 0x55 */
	ED_EXPECT_OPTIONAL_IE (0x55,  8, 555, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x55) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_ReplayedNonceUE (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 32;
		/* Read value part LOCATOR_16 */
		Destin->ReplayedNonceUE = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13120=EDCore::TDMInteger) */Destin->ReplayedNonceUE___LOCATOR), CurrOfs, 32);
		RetLen = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:556> Error decoding subfield ReplayedNonceUE\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_ReplayedNonceUE (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x55, 556, (Destin->ReplayedNonceUE))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:557> Message too short decoding subfield ReplayedNonceUE\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_ReplayedNonceUE (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x55, 556, (Destin->ReplayedNonceUE))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NonceMME
	------------------------------------------------------*/
	/* Detect IEI tag 0x56 */
	ED_EXPECT_OPTIONAL_IE (0x56,  8, 558, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x56) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_NonceMME (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 32;
		/* Read value part LOCATOR_16 */
		Destin->NonceMME = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-13122=EDCore::TDMInteger) */Destin->NonceMME___LOCATOR), CurrOfs, 32);
		RetLen = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:559> Error decoding subfield NonceMME\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_NonceMME (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x56, 559, (Destin->NonceMME))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:560> Message too short decoding subfield NonceMME\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMMAND_NonceMME (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x56, 559, (Destin->NonceMME))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SERVICE_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_SERVICE_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 78, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EMMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:561> Error encoding subfield EMMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3442Value */
	{
		if (Source->T3442Value_Present) {
			/* Append to buffer IEI tag 0x5B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5B), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->T3442Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, Source->T3442Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:562> Error encoding subfield T3442Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3346Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3346Value_Present) {
			/* Append to buffer IEI tag 0x5F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3346Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer2 (Buffer, CurrOfs+8, Source->T3346Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:563> Error encoding subfield T3346Value\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SERVICE_REJECT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{91, 255, ED_SKIPLIST_OPTIONAL},
		{95, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EMMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13127=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:564> Error decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 564, (Destin->EMMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:565> Message too short decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 564, (Destin->EMMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3442Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x5B */
	ED_EXPECT_OPTIONAL_IE (0x5B,  8, 566, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3442Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3442Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:567> Error decoding subfield T3442Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3442Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5B, 567, (Destin->T3442Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:568> Message too short decoding subfield T3442Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3442Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5B, 567, (Destin->T3442Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3346Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x5F */
	ED_EXPECT_OPTIONAL_IE (0x5F,  8, 569, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3346Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:570> Size error decoding IE T3346Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5F, 570, (Destin->T3346Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3346Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:571> Error decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5F, 571, (Destin->T3346Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:572> Message too short decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5F, 571, (Destin->T3346Value))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_TRACKING_AREA_UPDATE_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_ACCEPT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 73, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EPSUpdateResult */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EPSUpdateResult> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->EPSUpdateResult), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:573> Error encoding subfield EPSUpdateResult\n");
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
			ED_SIGNAL_ERROR ("<ERRID:574> Error encoding subfield SpareHalfOctet\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3412Value */
	{
		if (Source->T3412Value_Present) {
			/* Append to buffer IEI tag 0x5A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5A), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->T3412Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, Source->T3412Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:575> Error encoding subfield T3412Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for GUTI */
	{
		int TLV_Base = CurrOfs;
		if (Source->GUTI_Present) {
			/* Append to buffer IEI tag 0x50 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x50), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->GUTI> DOT=<->> */
			Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, Source->GUTI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:576> Error encoding subfield GUTI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for TAIList */
	{
		int TLV_Base = CurrOfs;
		if (Source->TAIList_Present) {
			/* Append to buffer IEI tag 0x54 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x54), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->TAIList> DOT=<->> */
			Len = ENCODE_c_PartialTrackingAreaIdentityList (Buffer, CurrOfs+8, Source->TAIList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:577> Error encoding subfield TAIList\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EPSBearerContextStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->EPSBearerContextStatus_Present) {
			/* Append to buffer IEI tag 0x57 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x57), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EPSBearerContextStatus> DOT=<->> */
			Len = ENCODE_c_EPSBearerContextStatus (Buffer, CurrOfs+8, Source->EPSBearerContextStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:578> Error encoding subfield EPSBearerContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LocationAreaIdentification */
	{
		if (Source->LocationAreaIdentification_Present) {
			/* Append to buffer IEI tag 0x13 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x13), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LocationAreaIdentification> DOT=<->> */
			Len = ENCODE_c_epsLocationAreaId (Buffer, CurrOfs, Source->LocationAreaIdentification);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:579> Error encoding subfield LocationAreaIdentification\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for MSIdentity */
	{
		int TLV_Base = CurrOfs;
		if (Source->MSIdentity_Present) {
			/* Append to buffer IEI tag 0x23 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x23), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MSIdentity> DOT=<->> */
			Len = ENCODE_c_epsMobileId (Buffer, CurrOfs+8, Source->MSIdentity);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:580> Error encoding subfield MSIdentity\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EMMCause */
	{
		if (Source->EMMCause_Present) {
			/* Append to buffer IEI tag 0x53 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x53), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
			Len = 8;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:581> Error encoding subfield EMMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3402Value */
	{
		if (Source->T3402Value_Present) {
			/* Append to buffer IEI tag 0x17 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x17), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->T3402Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, Source->T3402Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:582> Error encoding subfield T3402Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3423Value */
	{
		if (Source->T3423Value_Present) {
			/* Append to buffer IEI tag 0x59 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x59), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->T3423Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs, Source->T3423Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:583> Error encoding subfield T3423Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for EquivalentPLMNs */
	{
		int TLV_Base = CurrOfs;
		if (Source->EquivalentPLMNs_Present) {
			/* Append to buffer IEI tag 0x4A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x4A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EquivalentPLMNs> DOT=<->> */
			Len = ENCODE_c_epsPlmnList (Buffer, CurrOfs+8, Source->EquivalentPLMNs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:584> Error encoding subfield EquivalentPLMNs\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for epsEmergencyNumberList */
	{
		int TLV_Base = CurrOfs;
		if (Source->epsEmergencyNumberList_Present) {
			/* Append to buffer IEI tag 0x34 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x34), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->epsEmergencyNumberList> DOT=<->> */
			Len = ENCODE_c_epsEmergencyNumberList (Buffer, CurrOfs+8, Source->epsEmergencyNumberList);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:585> Error encoding subfield epsEmergencyNumberList\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for EPSNetworkFeatureSupport */
	{
		int TLV_Base = CurrOfs;
		if (Source->EPSNetworkFeatureSupport_Present) {
			/* Append to buffer IEI tag 0x64 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x64), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EPSNetworkFeatureSupport> DOT=<->> */
			Len = ENCODE_c_EPSNetworkFeatureSupport (Buffer, CurrOfs+8, Source->EPSNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:586> Error encoding subfield EPSNetworkFeatureSupport\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for AdditionalUpdateResult */
	{
		if (Source->AdditionalUpdateResult_Present) {
			/* Append to buffer IEI tag 0x0F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0F), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalUpdateResult> DOT=<->> */
			Len = ENCODE_c_AdditionalUpdateResult (Buffer, CurrOfs, Source->AdditionalUpdateResult);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:587> Error encoding subfield AdditionalUpdateResult\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for T3412ExtendedValue */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3412ExtendedValue_Present) {
			/* Append to buffer IEI tag 0x5E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5E), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3412ExtendedValue> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer (Buffer, CurrOfs+8, Source->T3412ExtendedValue);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:588> Error encoding subfield T3412ExtendedValue\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for T3324ValueGPRSTimer2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3324ValueGPRSTimer2_Present) {
			/* Append to buffer IEI tag 0x6A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x6A), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3324ValueGPRSTimer2> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer2 (Buffer, CurrOfs+8, Source->T3324ValueGPRSTimer2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:589> Error encoding subfield T3324ValueGPRSTimer2\n");
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
			Len = ENCODE_c_epsExtendedDRXParameters (Buffer, CurrOfs+8, Source->ExtendedDRXParameters);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:590> Error encoding subfield ExtendedDRXParameters\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for HeaderCompressionCfgStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->HeaderCompressionCfgStatus_Present) {
			/* Append to buffer IEI tag 0x68 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x68), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->HeaderCompressionCfgStatus> DOT=<->> */
			Len = ENCODE_c_HeaderCompressionCfgStatus (Buffer, CurrOfs+8, Source->HeaderCompressionCfgStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:591> Error encoding subfield HeaderCompressionCfgStatus\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_TRACKING_AREA_UPDATE_ACCEPT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{90, 255, ED_SKIPLIST_OPTIONAL},
		{80, 255, ED_SKIPLIST_OPTIONAL},
		{84, 255, ED_SKIPLIST_OPTIONAL},
		{87, 255, ED_SKIPLIST_OPTIONAL},
		{19, 255, ED_SKIPLIST_OPTIONAL},
		{35, 255, ED_SKIPLIST_OPTIONAL},
		{83, 255, ED_SKIPLIST_OPTIONAL},
		{23, 255, ED_SKIPLIST_OPTIONAL},
		{89, 255, ED_SKIPLIST_OPTIONAL},
		{74, 255, ED_SKIPLIST_OPTIONAL},
		{52, 255, ED_SKIPLIST_OPTIONAL},
		{100, 255, ED_SKIPLIST_OPTIONAL},
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{104, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EPSUpdateResult
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->EPSUpdateResult = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13136=EDCore::TDMOctet) */Destin->EPSUpdateResult___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:592> Error decoding subfield EPSUpdateResult\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 592, (Destin->EPSUpdateResult))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:593> Message too short decoding subfield EPSUpdateResult\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 592, (Destin->EPSUpdateResult))
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
		ED_SIGNAL_ERROR ("<ERRID:594> Error decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 594, (Destin->SpareHalfOctet))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:595> Message too short decoding subfield SpareHalfOctet\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 594, (Destin->SpareHalfOctet))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3412Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x5A */
	ED_EXPECT_OPTIONAL_IE (0x5A,  8, 596, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3412Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:597> Error decoding subfield T3412Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5A, 597, (Destin->T3412Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:598> Message too short decoding subfield T3412Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5A, 597, (Destin->T3412Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE GUTI
	------------------------------------------------------*/
	/* Detect IEI tag 0x50 */
	ED_EXPECT_OPTIONAL_IE (0x50,  8, 599, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x50) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 88) {
			ED_SIGNAL_ERROR ("<ERRID:600> Size error decoding IE GUTI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x50, 600, (Destin->GUTI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, Destin->GUTI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:601> Error decoding subfield GUTI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x50, 601, (Destin->GUTI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:602> Message too short decoding subfield GUTI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x50, 601, (Destin->GUTI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TAIList
	------------------------------------------------------*/
	/* Detect IEI tag 0x54 */
	ED_EXPECT_OPTIONAL_IE (0x54,  8, 603, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x54) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 48) || (Len > 768)) {
			ED_SIGNAL_ERROR ("<ERRID:604> Size error decoding IE TAIList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x54, 604, (Destin->TAIList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_PartialTrackingAreaIdentityList (Buffer, CurrOfs, Destin->TAIList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:605> Error decoding subfield TAIList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x54, 605, (Destin->TAIList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:606> Message too short decoding subfield TAIList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x54, 605, (Destin->TAIList))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EPSBearerContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x57 */
	ED_EXPECT_OPTIONAL_IE (0x57,  8, 607, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x57) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:608> Size error decoding IE EPSBearerContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x57, 608, (Destin->EPSBearerContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSBearerContextStatus (Buffer, CurrOfs, Destin->EPSBearerContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:609> Error decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x57, 609, (Destin->EPSBearerContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:610> Message too short decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x57, 609, (Destin->EPSBearerContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LocationAreaIdentification
	------------------------------------------------------*/
	/* Detect IEI tag 0x13 */
	ED_EXPECT_OPTIONAL_IE (0x13,  8, 611, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x13) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLocationAreaId (Buffer, CurrOfs, Destin->LocationAreaIdentification, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:612> Error decoding subfield LocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x13, 612, (Destin->LocationAreaIdentification))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:613> Message too short decoding subfield LocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x13, 612, (Destin->LocationAreaIdentification))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSIdentity
	------------------------------------------------------*/
	/* Detect IEI tag 0x23 */
	ED_EXPECT_OPTIONAL_IE (0x23,  8, 614, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x23) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 40) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:615> Size error decoding IE MSIdentity\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x23, 615, (Destin->MSIdentity))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMobileId (Buffer, CurrOfs, Destin->MSIdentity, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:616> Error decoding subfield MSIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x23, 616, (Destin->MSIdentity))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:617> Message too short decoding subfield MSIdentity\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x23, 616, (Destin->MSIdentity))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EMMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x53 */
	ED_EXPECT_OPTIONAL_IE (0x53,  8, 618, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x53) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13152=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
		RetLen = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:619> Error decoding subfield EMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x53, 619, (Destin->EMMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:620> Message too short decoding subfield EMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x53, 619, (Destin->EMMCause))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3402Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x17 */
	ED_EXPECT_OPTIONAL_IE (0x17,  8, 621, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x17) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3402Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:622> Error decoding subfield T3402Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x17, 622, (Destin->T3402Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:623> Message too short decoding subfield T3402Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x17, 622, (Destin->T3402Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3423Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x59 */
	ED_EXPECT_OPTIONAL_IE (0x59,  8, 624, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x59) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 8;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3423Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:625> Error decoding subfield T3423Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x59, 625, (Destin->T3423Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:626> Message too short decoding subfield T3423Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x59, 625, (Destin->T3423Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EquivalentPLMNs
	------------------------------------------------------*/
	/* Detect IEI tag 0x4A */
	ED_EXPECT_OPTIONAL_IE (0x4A,  8, 627, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x4A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 360)) {
			ED_SIGNAL_ERROR ("<ERRID:628> Size error decoding IE EquivalentPLMNs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x4A, 628, (Destin->EquivalentPLMNs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsPlmnList (Buffer, CurrOfs, Destin->EquivalentPLMNs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:629> Error decoding subfield EquivalentPLMNs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x4A, 629, (Destin->EquivalentPLMNs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:630> Message too short decoding subfield EquivalentPLMNs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x4A, 629, (Destin->EquivalentPLMNs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE epsEmergencyNumberList
	------------------------------------------------------*/
	/* Detect IEI tag 0x34 */
	ED_EXPECT_OPTIONAL_IE (0x34,  8, 631, 12, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x34) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 384)) {
			ED_SIGNAL_ERROR ("<ERRID:632> Size error decoding IE epsEmergencyNumberList\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x34, 632, (Destin->epsEmergencyNumberList))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsEmergencyNumberList (Buffer, CurrOfs, Destin->epsEmergencyNumberList, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:633> Error decoding subfield epsEmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x34, 633, (Destin->epsEmergencyNumberList))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:634> Message too short decoding subfield epsEmergencyNumberList\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x34, 633, (Destin->epsEmergencyNumberList))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EPSNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x64 */
	ED_EXPECT_OPTIONAL_IE (0x64,  8, 635, 13, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x64) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 16)) {
			ED_SIGNAL_ERROR ("<ERRID:636> Size error decoding IE EPSNetworkFeatureSupport\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x64, 636, (Destin->EPSNetworkFeatureSupport))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSNetworkFeatureSupport (Buffer, CurrOfs, Destin->EPSNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:637> Error decoding subfield EPSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x64, 637, (Destin->EPSNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:638> Message too short decoding subfield EPSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x64, 637, (Destin->EPSNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateResult
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 639, 14, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_AdditionalUpdateResult (Buffer, CurrOfs, Destin->AdditionalUpdateResult, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:640> Error decoding subfield AdditionalUpdateResult\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 640, (Destin->AdditionalUpdateResult))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:641> Message too short decoding subfield AdditionalUpdateResult\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 640, (Destin->AdditionalUpdateResult))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3412ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 642, 15, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:643> Size error decoding IE T3412ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 643, (Destin->T3412ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3412ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:644> Error decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 644, (Destin->T3412ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:645> Message too short decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 644, (Destin->T3412ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324ValueGPRSTimer2
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 646, 16, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:647> Size error decoding IE T3324ValueGPRSTimer2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 647, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3324ValueGPRSTimer2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:648> Error decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 648, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:649> Message too short decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 648, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 650, 17, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:651> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 651, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:652> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 652, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:653> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 652, (Destin->ExtendedDRXParameters))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE HeaderCompressionCfgStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x68 */
	ED_EXPECT_OPTIONAL_IE (0x68,  8, 654, 18, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x68) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:655> Size error decoding IE HeaderCompressionCfgStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x68, 655, (Destin->HeaderCompressionCfgStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_HeaderCompressionCfgStatus (Buffer, CurrOfs, Destin->HeaderCompressionCfgStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:656> Error decoding subfield HeaderCompressionCfgStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x68, 656, (Destin->HeaderCompressionCfgStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:657> Message too short decoding subfield HeaderCompressionCfgStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x68, 656, (Destin->HeaderCompressionCfgStatus))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_TRACKING_AREA_UPDATE_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REJECT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 75, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EMMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:658> Error encoding subfield EMMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for T3346Value */
	{
		int TLV_Base = CurrOfs;
		if (Source->T3346Value_Present) {
			/* Append to buffer IEI tag 0x5F */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5F), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->T3346Value> DOT=<->> */
			Len = ENCODE_c_epsGprsTimer2 (Buffer, CurrOfs+8, Source->T3346Value);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:659> Error encoding subfield T3346Value\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for ExtendedEMMCause */
	{
		if (Source->ExtendedEMMCause_Present) {
			/* Append to buffer IEI tag 0x0A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0A), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->ExtendedEMMCause> DOT=<->> */
			Len = ENCODE_c_ExtendedEMMCause (Buffer, CurrOfs, Source->ExtendedEMMCause);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:660> Error encoding subfield ExtendedEMMCause\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_TRACKING_AREA_UPDATE_REJECT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		{95, 255, ED_SKIPLIST_OPTIONAL},
		{160, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EMMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13177=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:661> Error decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 661, (Destin->EMMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:662> Message too short decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 661, (Destin->EMMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE T3346Value
	------------------------------------------------------*/
	/* Detect IEI tag 0x5F */
	ED_EXPECT_OPTIONAL_IE (0x5F,  8, 663, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:664> Size error decoding IE T3346Value\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5F, 664, (Destin->T3346Value))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3346Value, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:665> Error decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5F, 665, (Destin->T3346Value))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:666> Message too short decoding subfield T3346Value\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5F, 665, (Destin->T3346Value))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedEMMCause
	------------------------------------------------------*/
	/* Detect IEI tag 0x0A */
	ED_EXPECT_OPTIONAL_IE (0x0A,  4, 667, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ExtendedEMMCause (Buffer, CurrOfs, Destin->ExtendedEMMCause, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:668> Error decoding subfield ExtendedEMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0A, 668, (Destin->ExtendedEMMCause))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:669> Message too short decoding subfield ExtendedEMMCause\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0A, 668, (Destin->ExtendedEMMCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_GENERIC_NAS_TRANSPORT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (char* Buffer, ED_EXLONG BitOffset, const c_DOWNLINK_GENERIC_NAS_TRANSPORT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 104, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for GenericMessageContainerType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GenericMessageContainerType> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GenericMessageContainerType), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:670> Error encoding subfield GenericMessageContainerType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for GenericMessageContainer */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->GenericMessageContainer> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+16, Source->GenericMessageContainer.value, 0, Source->GenericMessageContainer.usedBits);
		Len = Source->GenericMessageContainer.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:671> Error encoding subfield GenericMessageContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+16;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
	}
	
	/* Code for AdditionalInformation */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalInformation_Present) {
			/* Append to buffer IEI tag 0x65 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x65), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalInformation> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AdditionalInformation->value, 0, Source->AdditionalInformation->usedBits);
			Len = Source->AdditionalInformation->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:672> Error encoding subfield AdditionalInformation\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_DOWNLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_DOWNLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_DOWNLINK_GENERIC_NAS_TRANSPORT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE DOWNLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_DOWNLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_DOWNLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
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
		{101, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE GenericMessageContainerType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->GenericMessageContainerType = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-13186=EDCore::TDMOctet) */Destin->GenericMessageContainerType___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:673> Error decoding subfield GenericMessageContainerType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 673, (Destin->GenericMessageContainerType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:674> Message too short decoding subfield GenericMessageContainerType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 673, (Destin->GenericMessageContainerType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE GenericMessageContainer
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 16);
	CurrOfs += 16;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 8) || (Len > 4784)) {
		ED_SIGNAL_ERROR ("<ERRID:675> Size error decoding IE GenericMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 675, (Destin->GenericMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13188=EDCore::TDMBinary) */Destin->GenericMessageContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer (&(Destin->GenericMessageContainer), Len);
	
		if (Destin->GenericMessageContainer.value) {
			EDCopyBits (Destin->GenericMessageContainer.value, 0, Buffer, CurrOfs, Len);
			Destin->GenericMessageContainer.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->GenericMessageContainer.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:676> Error decoding subfield GenericMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 676, (Destin->GenericMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:677> Message too short decoding subfield GenericMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 676, (Destin->GenericMessageContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalInformation
	------------------------------------------------------*/
	/* Detect IEI tag 0x65 */
	ED_EXPECT_OPTIONAL_IE (0x65,  8, 678, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x65) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:679> Size error decoding IE AdditionalInformation\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x65, 679, (Destin->AdditionalInformation))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-13190=EDCore::TDMBinary) */Destin->AdditionalInformation___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin->AdditionalInformation, Len);
		
			if (Destin->AdditionalInformation->value) {
				EDCopyBits (Destin->AdditionalInformation->value, 0, Buffer, CurrOfs, Len);
				Destin->AdditionalInformation->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->AdditionalInformation->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:680> Error decoding subfield AdditionalInformation\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x65, 680, (Destin->AdditionalInformation))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:681> Message too short decoding subfield AdditionalInformation\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x65, 680, (Destin->AdditionalInformation))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SERVICE_ACCEPT (char* Buffer, ED_EXLONG BitOffset, const c_SERVICE_ACCEPT* Source, int Mode)
{
	int Len=0;
	ED_EXLONG CurrOfs = BitOffset+Len;
	ED_EXTRAPARAMS_CODE
						
	ED_WARNING_REMOVER (Buffer);
	ED_WARNING_REMOVER (BitOffset);
	ED_WARNING_REMOVER (Source);
	ED_WARNING_REMOVER (Mode);
	
	if (Mode == 0) {
		/* Encode the security header type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, Source->SecurityHeaderType, 4);
		CurrOfs += 4;
		
		/* Encode protocol discriminator */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 7, 4);
		CurrOfs += 4;

		/* Encode message type */
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 79, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EPSBearerContextStatus */
	{
		int TLV_Base = CurrOfs;
		if (Source->EPSBearerContextStatus_Present) {
			/* Append to buffer IEI tag 0x57 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x57), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->EPSBearerContextStatus> DOT=<->> */
			Len = ENCODE_c_EPSBearerContextStatus (Buffer, CurrOfs+8, Source->EPSBearerContextStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:682> Error encoding subfield EPSBearerContextStatus\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_ACCEPT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_ACCEPT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_ACCEPT* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_ACCEPT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SERVICE_ACCEPT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_ACCEPT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_ACCEPT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_ACCEPT* ED_CONST Destin, ED_EXLONG Length))
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
		{87, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EPSBearerContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x57 */
	ED_EXPECT_OPTIONAL_IE (0x57,  8, 683, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x57) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:684> Size error decoding IE EPSBearerContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x57, 684, (Destin->EPSBearerContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSBearerContextStatus (Buffer, CurrOfs, Destin->EPSBearerContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:685> Error decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x57, 685, (Destin->EPSBearerContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:686> Message too short decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x57, 685, (Destin->EPSBearerContextStatus))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_ATTACH_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 66) /* message type */
	);
}

int Match_c_ATTACH_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 68) /* message type */
	);
}

int Match_c_AUTHENTICATION_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 84) /* message type */
	);
}

int Match_c_AUTHENTICATION_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 82) /* message type */
	);
}

int Match_c_CS_SERVICE_NOTIFICATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 100) /* message type */
	);
}

int Match_c_EPS_DETACH_ACCEPT_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 70) /* message type */
	);
}

int Match_c_EPS_DETACH_REQUEST_DN (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 69) /* message type */
	);
}

int Match_c_DOWNLINK_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 98) /* message type */
	);
}

int Match_c_EMM_INFORMATION (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 97) /* message type */
	);
}

int Match_c_GUTI_REALLOCATION_COMMAND (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 80) /* message type */
	);
}

int Match_c_IDENTITY_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 85) /* message type */
	);
}

int Match_c_SECURITY_MODE_COMMAND (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 93) /* message type */
	);
}

int Match_c_SERVICE_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 78) /* message type */
	);
}

int Match_c_TRACKING_AREA_UPDATE_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 73) /* message type */
	);
}

int Match_c_TRACKING_AREA_UPDATE_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 75) /* message type */
	);
}

int Match_c_DOWNLINK_GENERIC_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 104) /* message type */
	);
}

int Match_c_SERVICE_ACCEPT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 79) /* message type */
	);
}

