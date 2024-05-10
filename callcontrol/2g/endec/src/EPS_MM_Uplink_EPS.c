/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "EPS_MM_Uplink_EPS.h"
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_COMPLETE (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_COMPLETE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 67, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ESMMessageContainer */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->ESMMessageContainer> DOT=<.> */
		Len = ENCODE_c_ESMMessageUp (Buffer, CurrOfs+16, (&(Source->ESMMessageContainer)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:1> Error encoding subfield ESMMessageContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+16;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_COMPLETE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_COMPLETE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_ATTACH_COMPLETE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE ESMMessageContainer
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 16);
	CurrOfs += 16;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len > 4784) {
		ED_SIGNAL_ERROR ("<ERRID:2> Size error decoding IE ESMMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 2, (Destin->ESMMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_ESMMessageUp (Buffer, CurrOfs, (&(Destin->ESMMessageContainer)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:3> Error decoding subfield ESMMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 3, (Destin->ESMMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:4> Message too short decoding subfield ESMMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 3, (Destin->ESMMessageContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_ATTACH_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_ATTACH_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 65, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EPSAttachType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EPSAttachType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->EPSAttachType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:5> Error encoding subfield EPSAttachType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASKeySetIdentifier */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifier> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Source->NASKeySetIdentifier)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:6> Error encoding subfield NASKeySetIdentifier\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for EPSMobileIdentity */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->EPSMobileIdentity> DOT=<.> */
		Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, (&(Source->EPSMobileIdentity)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:7> Error encoding subfield EPSMobileIdentity\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for UENetworkCapability */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->UENetworkCapability> DOT=<.> */
		Len = ENCODE_c_UENetworkCapability (Buffer, CurrOfs+8, (&(Source->UENetworkCapability)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:8> Error encoding subfield UENetworkCapability\n");
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
		Len = ENCODE_c_ESMMessageUp (Buffer, CurrOfs+16, (&(Source->ESMMessageContainer)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:9> Error encoding subfield ESMMessageContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+16;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
	}
	
	/* Code for OldPTMSISignature */
	{
		if (Source->OldPTMSISignature_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->OldPTMSISignature> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->OldPTMSISignature, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:10> Error encoding subfield OldPTMSISignature\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AdditionalGUTI */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalGUTI_Present) {
			/* Append to buffer IEI tag 0x50 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x50), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalGUTI> DOT=<->> */
			Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, Source->AdditionalGUTI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:11> Error encoding subfield AdditionalGUTI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LastVisitedRegisteredTAI */
	{
		if (Source->LastVisitedRegisteredTAI_Present) {
			/* Append to buffer IEI tag 0x52 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x52), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LastVisitedRegisteredTAI> DOT=<->> */
			Len = ENCODE_c_TrackingAreaIdentity (Buffer, CurrOfs, Source->LastVisitedRegisteredTAI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:12> Error encoding subfield LastVisitedRegisteredTAI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DRXParameter */
	{
		if (Source->DRXParameter_Present) {
			/* Append to buffer IEI tag 0x5C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5C), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->DRXParameter> DOT=<->> */
			Len = ENCODE_c_epsDrxParam (Buffer, CurrOfs, Source->DRXParameter);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:13> Error encoding subfield DRXParameter\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for MSNetworkCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->MSNetworkCapability_Present) {
			/* Append to buffer IEI tag 0x31 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x31), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MSNetworkCapability> DOT=<->> */
			Len = ENCODE_c_epsMsNetwkCpblty (Buffer, CurrOfs+8, Source->MSNetworkCapability);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:14> Error encoding subfield MSNetworkCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for OldLocationAreaIdentification */
	{
		if (Source->OldLocationAreaIdentification_Present) {
			/* Append to buffer IEI tag 0x13 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x13), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->OldLocationAreaIdentification> DOT=<->> */
			Len = ENCODE_c_epsLocationAreaId (Buffer, CurrOfs, Source->OldLocationAreaIdentification);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:15> Error encoding subfield OldLocationAreaIdentification\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for TMSIStatus */
	{
		if (Source->TMSIStatus_Present) {
			/* Append to buffer IEI tag 0x09 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x09), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->TMSIStatus> DOT=<->> */
			Len = ENCODE_c_epsTmsiStatus (Buffer, CurrOfs, Source->TMSIStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:16> Error encoding subfield TMSIStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for epsMobileStationClassmark2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->epsMobileStationClassmark2_Present) {
			/* Append to buffer IEI tag 0x11 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x11), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->epsMobileStationClassmark2> DOT=<->> */
			Len = ENCODE_c_epsMobileStationClassmark2 (Buffer, CurrOfs+8, Source->epsMobileStationClassmark2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:17> Error encoding subfield epsMobileStationClassmark2\n");
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
			Len = ENCODE_c_epsClassmark3Value (Buffer, CurrOfs+8, Source->MobileStationClassmark3);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:18> Error encoding subfield MobileStationClassmark3\n");
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
			Len = ENCODE_c_epsSupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:19> Error encoding subfield SupportedCodecs\n");
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
			Len = ENCODE_c_epsAdditionalUpdateType (Buffer, CurrOfs, Source->AdditionalUpdateType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:20> Error encoding subfield AdditionalUpdateType\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for VoiceDomainPref */
	{
		int TLV_Base = CurrOfs;
		if (Source->VoiceDomainPref_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->VoiceDomainPref> DOT=<->> */
			Len = ENCODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs+8, Source->VoiceDomainPref);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:21> Error encoding subfield VoiceDomainPref\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:22> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for OldGUTIType */
	{
		if (Source->OldGUTIType_Present) {
			/* Append to buffer IEI tag 0x0E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0E), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->OldGUTIType> DOT=<->> */
			Len = ENCODE_c_GUTIType (Buffer, CurrOfs, Source->OldGUTIType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:23> Error encoding subfield OldGUTIType\n");
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
			Len = ENCODE_c_epsMSNetworkFeatureSupport (Buffer, CurrOfs, Source->MSNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:24> Error encoding subfield MSNetworkFeatureSupport\n");
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
			Len = ENCODE_c_epsNetworkResourceIdentifierContainer (Buffer, CurrOfs+8, Source->TMSIBasedNRIContainer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:25> Error encoding subfield TMSIBasedNRIContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:26> Error encoding subfield T3324ValueGPRSTimer2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:27> Error encoding subfield T3412ExtendedValue\n");
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
				ED_SIGNAL_ERROR ("<ERRID:28> Error encoding subfield ExtendedDRXParameters\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_ATTACH_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_ATTACH_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_ATTACH_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_ATTACH_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_ATTACH_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_ATTACH_REQUEST (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE ATTACH_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_ATTACH_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_ATTACH_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{80, 255, ED_SKIPLIST_OPTIONAL},
		{82, 255, ED_SKIPLIST_OPTIONAL},
		{92, 255, ED_SKIPLIST_OPTIONAL},
		{49, 255, ED_SKIPLIST_OPTIONAL},
		{19, 255, ED_SKIPLIST_OPTIONAL},
		{144, 240, ED_SKIPLIST_OPTIONAL},
		{17, 255, ED_SKIPLIST_OPTIONAL},
		{32, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{224, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{16, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EPSAttachType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->EPSAttachType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12764=EDCore::TDMOctet) */Destin->EPSAttachType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:29> Error decoding subfield EPSAttachType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 29, (Destin->EPSAttachType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:30> Message too short decoding subfield EPSAttachType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 29, (Destin->EPSAttachType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASKeySetIdentifier
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Destin->NASKeySetIdentifier)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:31> Error decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 31, (Destin->NASKeySetIdentifier))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:32> Message too short decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 31, (Destin->NASKeySetIdentifier))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE EPSMobileIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 32) || (Len > 88)) {
		ED_SIGNAL_ERROR ("<ERRID:33> Size error decoding IE EPSMobileIdentity\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 33, (Destin->EPSMobileIdentity))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, (&(Destin->EPSMobileIdentity)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:34> Error decoding subfield EPSMobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 34, (Destin->EPSMobileIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:35> Message too short decoding subfield EPSMobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 34, (Destin->EPSMobileIdentity))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE UENetworkCapability
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 16) || (Len > 104)) {
		ED_SIGNAL_ERROR ("<ERRID:36> Size error decoding IE UENetworkCapability\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 36, (Destin->UENetworkCapability))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_UENetworkCapability (Buffer, CurrOfs, (&(Destin->UENetworkCapability)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:37> Error decoding subfield UENetworkCapability\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 37, (Destin->UENetworkCapability))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:38> Message too short decoding subfield UENetworkCapability\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 37, (Destin->UENetworkCapability))
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
		ED_SIGNAL_ERROR ("<ERRID:39> Size error decoding IE ESMMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 39, (Destin->ESMMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_ESMMessageUp (Buffer, CurrOfs, (&(Destin->ESMMessageContainer)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:40> Error decoding subfield ESMMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 40, (Destin->ESMMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:41> Message too short decoding subfield ESMMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 40, (Destin->ESMMessageContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OldPTMSISignature
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 42, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldPTMSISignature (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->OldPTMSISignature, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12774=EDCore::TDMBinary) */Destin->OldPTMSISignature___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:43> Error decoding subfield OldPTMSISignature\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldPTMSISignature (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 43, (Destin->OldPTMSISignature))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:44> Message too short decoding subfield OldPTMSISignature\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldPTMSISignature (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 43, (Destin->OldPTMSISignature))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalGUTI
	------------------------------------------------------*/
	/* Detect IEI tag 0x50 */
	ED_EXPECT_OPTIONAL_IE (0x50,  8, 45, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x50) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 88) {
			ED_SIGNAL_ERROR ("<ERRID:46> Size error decoding IE AdditionalGUTI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x50, 46, (Destin->AdditionalGUTI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, Destin->AdditionalGUTI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:47> Error decoding subfield AdditionalGUTI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x50, 47, (Destin->AdditionalGUTI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:48> Message too short decoding subfield AdditionalGUTI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x50, 47, (Destin->AdditionalGUTI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LastVisitedRegisteredTAI
	------------------------------------------------------*/
	/* Detect IEI tag 0x52 */
	ED_EXPECT_OPTIONAL_IE (0x52,  8, 49, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x52) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_LastVisitedRegisteredTAI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TrackingAreaIdentity (Buffer, CurrOfs, Destin->LastVisitedRegisteredTAI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:50> Error decoding subfield LastVisitedRegisteredTAI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_LastVisitedRegisteredTAI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x52, 50, (Destin->LastVisitedRegisteredTAI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:51> Message too short decoding subfield LastVisitedRegisteredTAI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_LastVisitedRegisteredTAI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x52, 50, (Destin->LastVisitedRegisteredTAI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DRXParameter
	------------------------------------------------------*/
	/* Detect IEI tag 0x5C */
	ED_EXPECT_OPTIONAL_IE (0x5C,  8, 52, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_DRXParameter (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 16;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDrxParam (Buffer, CurrOfs, Destin->DRXParameter, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:53> Error decoding subfield DRXParameter\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_DRXParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5C, 53, (Destin->DRXParameter))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:54> Message too short decoding subfield DRXParameter\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_DRXParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5C, 53, (Destin->DRXParameter))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSNetworkCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x31 */
	ED_EXPECT_OPTIONAL_IE (0x31,  8, 55, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x31) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:56> Size error decoding IE MSNetworkCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x31, 56, (Destin->MSNetworkCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMsNetwkCpblty (Buffer, CurrOfs, Destin->MSNetworkCapability, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:57> Error decoding subfield MSNetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x31, 57, (Destin->MSNetworkCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:58> Message too short decoding subfield MSNetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x31, 57, (Destin->MSNetworkCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldLocationAreaIdentification
	------------------------------------------------------*/
	/* Detect IEI tag 0x13 */
	ED_EXPECT_OPTIONAL_IE (0x13,  8, 59, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x13) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldLocationAreaIdentification (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLocationAreaId (Buffer, CurrOfs, Destin->OldLocationAreaIdentification, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:60> Error decoding subfield OldLocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x13, 60, (Destin->OldLocationAreaIdentification))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:61> Message too short decoding subfield OldLocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x13, 60, (Destin->OldLocationAreaIdentification))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TMSIStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x09 */
	ED_EXPECT_OPTIONAL_IE (0x09,  4, 62, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x09) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsTmsiStatus (Buffer, CurrOfs, Destin->TMSIStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:63> Error decoding subfield TMSIStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x09, 63, (Destin->TMSIStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:64> Message too short decoding subfield TMSIStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x09, 63, (Destin->TMSIStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE epsMobileStationClassmark2
	------------------------------------------------------*/
	/* Detect IEI tag 0x11 */
	ED_EXPECT_OPTIONAL_IE (0x11,  8, 65, 12, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x11) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:66> Size error decoding IE epsMobileStationClassmark2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x11, 66, (Destin->epsMobileStationClassmark2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMobileStationClassmark2 (Buffer, CurrOfs, Destin->epsMobileStationClassmark2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:67> Error decoding subfield epsMobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x11, 67, (Destin->epsMobileStationClassmark2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:68> Message too short decoding subfield epsMobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x11, 67, (Destin->epsMobileStationClassmark2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark3
	------------------------------------------------------*/
	/* Detect IEI tag 0x20 */
	ED_EXPECT_OPTIONAL_IE (0x20,  8, 69, 13, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x20) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 256) {
			ED_SIGNAL_ERROR ("<ERRID:70> Size error decoding IE MobileStationClassmark3\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x20, 70, (Destin->MobileStationClassmark3))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsClassmark3Value (Buffer, CurrOfs, Destin->MobileStationClassmark3, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:71> Error decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x20, 71, (Destin->MobileStationClassmark3))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:72> Message too short decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x20, 71, (Destin->MobileStationClassmark3))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 73, 14, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:74> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 74, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsSupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:75> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 75, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:76> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 75, (Destin->SupportedCodecs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 77, 15, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalUpdateType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsAdditionalUpdateType (Buffer, CurrOfs, Destin->AdditionalUpdateType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:78> Error decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 78, (Destin->AdditionalUpdateType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:79> Message too short decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 78, (Destin->AdditionalUpdateType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE VoiceDomainPref
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 80, 16, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:81> Size error decoding IE VoiceDomainPref\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 81, (Destin->VoiceDomainPref))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs, Destin->VoiceDomainPref, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:82> Error decoding subfield VoiceDomainPref\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 82, (Destin->VoiceDomainPref))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:83> Message too short decoding subfield VoiceDomainPref\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 82, (Destin->VoiceDomainPref))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 84, 17, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:85> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 85, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:86> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 85, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldGUTIType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0E */
	ED_EXPECT_OPTIONAL_IE (0x0E,  4, 87, 18, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldGUTIType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GUTIType (Buffer, CurrOfs, Destin->OldGUTIType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:88> Error decoding subfield OldGUTIType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldGUTIType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0E, 88, (Destin->OldGUTIType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:89> Message too short decoding subfield OldGUTIType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_OldGUTIType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0E, 88, (Destin->OldGUTIType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 90, 19, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMSNetworkFeatureSupport (Buffer, CurrOfs, Destin->MSNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:91> Error decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 91, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:92> Message too short decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 91, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TMSIBasedNRIContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x10 */
	ED_EXPECT_OPTIONAL_IE (0x10,  8, 93, 20, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x10) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:94> Size error decoding IE TMSIBasedNRIContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x10, 94, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsNetworkResourceIdentifierContainer (Buffer, CurrOfs, Destin->TMSIBasedNRIContainer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:95> Error decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x10, 95, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:96> Message too short decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x10, 95, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324ValueGPRSTimer2
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 97, 21, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:98> Size error decoding IE T3324ValueGPRSTimer2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 98, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3324ValueGPRSTimer2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:99> Error decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 99, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:100> Message too short decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 99, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3412ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 101, 22, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:102> Size error decoding IE T3412ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 102, (Destin->T3412ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3412ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:103> Error decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 103, (Destin->T3412ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:104> Message too short decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 103, (Destin->T3412ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 105, 23, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:106> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 106, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:107> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 107, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:108> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 107, (Destin->ExtendedDRXParameters))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_FAILURE (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 92, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EMMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:109> Error encoding subfield EMMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for AuthenticationFailureParameter */
	{
		int TLV_Base = CurrOfs;
		if (Source->AuthenticationFailureParameter_Present) {
			/* Append to buffer IEI tag 0x30 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x30), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AuthenticationFailureParameter> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->AuthenticationFailureParameter, 0, 112);
			Len = 112;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:110> Error encoding subfield AuthenticationFailureParameter\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_FAILURE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_FAILURE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_FAILURE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_FAILURE* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_FAILURE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_FAILURE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_AUTHENTICATION_FAILURE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_FAILURE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_FAILURE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_FAILURE* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE EMMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12815=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:111> Error decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 111, (Destin->EMMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:112> Message too short decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 111, (Destin->EMMCause))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AuthenticationFailureParameter
	------------------------------------------------------*/
	/* Detect IEI tag 0x30 */
	ED_EXPECT_OPTIONAL_IE (0x30,  8, 113, 1, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x30) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 112) {
			ED_SIGNAL_ERROR ("<ERRID:114> Size error decoding IE AuthenticationFailureParameter\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x30, 114, (Destin->AuthenticationFailureParameter))
		} 
#endif
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->AuthenticationFailureParameter, 0, Buffer, CurrOfs, 112);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12817=EDCore::TDMBinary) */Destin->AuthenticationFailureParameter___LOCATOR), CurrOfs, 112);
		RetLen = 112;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:115> Error decoding subfield AuthenticationFailureParameter\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x30, 115, (Destin->AuthenticationFailureParameter))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:116> Message too short decoding subfield AuthenticationFailureParameter\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x30, 115, (Destin->AuthenticationFailureParameter))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_AUTHENTICATION_RESPONSE (char* Buffer, ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 83, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for AuthenticationResponseParameter */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->AuthenticationResponseParameter> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs+8, Source->AuthenticationResponseParameter.value, 0, Source->AuthenticationResponseParameter.usedBits);
		Len = Source->AuthenticationResponseParameter.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:117> Error encoding subfield AuthenticationResponseParameter\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_AUTHENTICATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_RESPONSE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_AUTHENTICATION_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_AUTHENTICATION_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_AUTHENTICATION_RESPONSE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_AUTHENTICATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_AUTHENTICATION_RESPONSE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE AUTHENTICATION_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_AUTHENTICATION_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_AUTHENTICATION_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE AuthenticationResponseParameter
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 32) || (Len > 128)) {
		ED_SIGNAL_ERROR ("<ERRID:118> Size error decoding IE AuthenticationResponseParameter\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 118, (Destin->AuthenticationResponseParameter))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12822=EDCore::TDMBinary) */Destin->AuthenticationResponseParameter___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter (&(Destin->AuthenticationResponseParameter), Len);
	
		if (Destin->AuthenticationResponseParameter.value) {
			EDCopyBits (Destin->AuthenticationResponseParameter.value, 0, Buffer, CurrOfs, Len);
			Destin->AuthenticationResponseParameter.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->AuthenticationResponseParameter.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:119> Error decoding subfield AuthenticationResponseParameter\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 119, (Destin->AuthenticationResponseParameter))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:120> Message too short decoding subfield AuthenticationResponseParameter\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 119, (Destin->AuthenticationResponseParameter))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EPS_DETACH_ACCEPT_UP (char* Buffer, ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_UP* Source, int Mode)
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_ACCEPT_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_ACCEPT_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_ACCEPT_UP* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_ACCEPT_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EPS_DETACH_ACCEPT_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_ACCEPT_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_ACCEPT_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_ACCEPT_UP* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_UP
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EPS_DETACH_REQUEST_UP (char* Buffer, ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_UP* Source, int Mode)
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
			ED_SIGNAL_ERROR ("<ERRID:121> Error encoding subfield DetachType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASKeySetIdentifier */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifier> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Source->NASKeySetIdentifier)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:122> Error encoding subfield NASKeySetIdentifier\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for EPSMobileIdentity */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->EPSMobileIdentity> DOT=<.> */
		Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, (&(Source->EPSMobileIdentity)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:123> Error encoding subfield EPSMobileIdentity\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EPS_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_REQUEST_UP (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EPS_DETACH_REQUEST_UP (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EPS_DETACH_REQUEST_UP* ED_CONST Source))
{
	return L3_ENCODE_c_EPS_DETACH_REQUEST_UP (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EPS_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EPS_DETACH_REQUEST_UP (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EPS_DETACH_REQUEST_UP
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EPS_DETACH_REQUEST_UP (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EPS_DETACH_REQUEST_UP* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE DetachType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPSDetachType (Buffer, (CurrOfs+4), (&(Destin->DetachType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:124> Error decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 124, (Destin->DetachType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:125> Message too short decoding subfield DetachType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 124, (Destin->DetachType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASKeySetIdentifier
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Destin->NASKeySetIdentifier)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:126> Error decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 126, (Destin->NASKeySetIdentifier))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:127> Message too short decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 126, (Destin->NASKeySetIdentifier))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE EPSMobileIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 32) || (Len > 88)) {
		ED_SIGNAL_ERROR ("<ERRID:128> Size error decoding IE EPSMobileIdentity\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 128, (Destin->EPSMobileIdentity))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, (&(Destin->EPSMobileIdentity)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:129> Error decoding subfield EPSMobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 129, (Destin->EPSMobileIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:130> Message too short decoding subfield EPSMobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 129, (Destin->EPSMobileIdentity))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EMM_STATUS
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EMM_STATUS (char* Buffer, ED_EXLONG BitOffset, const c_EMM_STATUS* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 96, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EMMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:131> Error encoding subfield EMMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_EMM_STATUS (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EMM_STATUS (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EMM_STATUS* ED_CONST Source))
{
	return L3_ENCODE_c_EMM_STATUS (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_STATUS* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EMM_STATUS (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EMM_STATUS
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EMM_STATUS (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EMM_STATUS* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE EMMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12839=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:132> Error decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 132, (Destin->EMMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:133> Message too short decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 132, (Destin->EMMCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EXTENDED_SERVICE_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_EXTENDED_SERVICE_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_EXTENDED_SERVICE_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 76, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for ServiceType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->ServiceType> DOT=<.> */
		EDIntToBits (Buffer, ((CurrOfs+4)), (int)(Source->ServiceType), 4);
		Len = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:134> Error encoding subfield ServiceType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASKeySetIdentifier */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifier> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Source->NASKeySetIdentifier)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:135> Error encoding subfield NASKeySetIdentifier\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MTMSI */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MTMSI> DOT=<.> */
		Len = ENCODE_c_epsMobileId (Buffer, CurrOfs+8, (&(Source->MTMSI)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:136> Error encoding subfield MTMSI\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for CSFBResponse */
	{
		if (Source->CSFBResponse_Present) {
			/* Append to buffer IEI tag 0x0B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0B), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->CSFBResponse> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->CSFBResponse), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:137> Error encoding subfield CSFBResponse\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
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
				ED_SIGNAL_ERROR ("<ERRID:138> Error encoding subfield EPSBearerContextStatus\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:139> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE EXTENDED_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_EXTENDED_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EXTENDED_SERVICE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_EXTENDED_SERVICE_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE EXTENDED_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_EXTENDED_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_EXTENDED_SERVICE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_EXTENDED_SERVICE_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EXTENDED_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_EXTENDED_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EXTENDED_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_EXTENDED_SERVICE_REQUEST (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE EXTENDED_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_EXTENDED_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_EXTENDED_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{176, 240, ED_SKIPLIST_OPTIONAL},
		{87, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE ServiceType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	Destin->ServiceType = (unsigned char)EDBitsToInt (Buffer, (CurrOfs+4), 4);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12844=EDCore::TDMOctet) */Destin->ServiceType___LOCATOR), (CurrOfs+4), 4);
	RetLen = 4;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:140> Error decoding subfield ServiceType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 140, (Destin->ServiceType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:141> Message too short decoding subfield ServiceType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 140, (Destin->ServiceType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASKeySetIdentifier
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Destin->NASKeySetIdentifier)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:142> Error decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 142, (Destin->NASKeySetIdentifier))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:143> Message too short decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 142, (Destin->NASKeySetIdentifier))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MTMSI
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 40) {
		ED_SIGNAL_ERROR ("<ERRID:144> Size error decoding IE MTMSI\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 144, (Destin->MTMSI))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_epsMobileId (Buffer, CurrOfs, (&(Destin->MTMSI)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:145> Error decoding subfield MTMSI\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 145, (Destin->MTMSI))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:146> Message too short decoding subfield MTMSI\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 145, (Destin->MTMSI))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE CSFBResponse
	------------------------------------------------------*/
	/* Detect IEI tag 0x0B */
	ED_EXPECT_OPTIONAL_IE (0x0B,  4, 147, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_CSFBResponse (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->CSFBResponse = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12850=EDCore::TDMOctet) */Destin->CSFBResponse___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:148> Error decoding subfield CSFBResponse\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_CSFBResponse (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0B, 148, (Destin->CSFBResponse))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:149> Message too short decoding subfield CSFBResponse\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_CSFBResponse (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0B, 148, (Destin->CSFBResponse))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EPSBearerContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x57 */
	ED_EXPECT_OPTIONAL_IE (0x57,  8, 150, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x57) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:151> Size error decoding IE EPSBearerContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x57, 151, (Destin->EPSBearerContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSBearerContextStatus (Buffer, CurrOfs, Destin->EPSBearerContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:152> Error decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x57, 152, (Destin->EPSBearerContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:153> Message too short decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x57, 152, (Destin->EPSBearerContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 154, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:155> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 155, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:156> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_EXTENDED_SERVICE_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 155, (Destin->DeviceProperties))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMPLETE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_GUTI_REALLOCATION_COMPLETE (char* Buffer, ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMPLETE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 81, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GUTI_REALLOCATION_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_GUTI_REALLOCATION_COMPLETE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_GUTI_REALLOCATION_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GUTI_REALLOCATION_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_GUTI_REALLOCATION_COMPLETE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GUTI_REALLOCATION_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_GUTI_REALLOCATION_COMPLETE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE GUTI_REALLOCATION_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_GUTI_REALLOCATION_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GUTI_REALLOCATION_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_IDENTITY_RESPONSE (char* Buffer, ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 86, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for MobileIdentity */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->MobileIdentity> DOT=<.> */
		Len = ENCODE_c_epsMobileId (Buffer, CurrOfs+8, (&(Source->MobileIdentity)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:157> Error encoding subfield MobileIdentity\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_IDENTITY_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_RESPONSE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_IDENTITY_RESPONSE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_IDENTITY_RESPONSE* ED_CONST Source))
{
	return L3_ENCODE_c_IDENTITY_RESPONSE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_IDENTITY_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_IDENTITY_RESPONSE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE IDENTITY_RESPONSE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_IDENTITY_RESPONSE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_IDENTITY_RESPONSE* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE MobileIdentity
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if ((Len < 24) || (Len > 72)) {
		ED_SIGNAL_ERROR ("<ERRID:158> Size error decoding IE MobileIdentity\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 158, (Destin->MobileIdentity))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_epsMobileId (Buffer, CurrOfs, (&(Destin->MobileIdentity)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:159> Error decoding subfield MobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 159, (Destin->MobileIdentity))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:160> Message too short decoding subfield MobileIdentity\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 159, (Destin->MobileIdentity))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMPLETE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SECURITY_MODE_COMPLETE (char* Buffer, ED_EXLONG BitOffset, const c_SECURITY_MODE_COMPLETE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 94, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for IMEISV */
	{
		int TLV_Base = CurrOfs;
		if (Source->IMEISV_Present) {
			/* Append to buffer IEI tag 0x23 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x23), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->IMEISV> DOT=<->> */
			Len = ENCODE_c_epsMobileId (Buffer, CurrOfs+8, Source->IMEISV);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:161> Error encoding subfield IMEISV\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_MODE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_MODE_COMPLETE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_MODE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_MODE_COMPLETE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_MODE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SECURITY_MODE_COMPLETE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_MODE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
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
		{35, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE IMEISV
	------------------------------------------------------*/
	/* Detect IEI tag 0x23 */
	ED_EXPECT_OPTIONAL_IE (0x23,  8, 162, 0, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x23) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 72) {
			ED_SIGNAL_ERROR ("<ERRID:163> Size error decoding IE IMEISV\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x23, 163, (Destin->IMEISV))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMobileId (Buffer, CurrOfs, Destin->IMEISV, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:164> Error decoding subfield IMEISV\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x23, 164, (Destin->IMEISV))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:165> Message too short decoding subfield IMEISV\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x23, 164, (Destin->IMEISV))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_REJECT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SECURITY_MODE_REJECT (char* Buffer, ED_EXLONG BitOffset, const c_SECURITY_MODE_REJECT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 95, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EMMCause */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EMMCause> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->EMMCause), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:166> Error encoding subfield EMMCause\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_MODE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_MODE_REJECT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_MODE_REJECT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_MODE_REJECT* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_MODE_REJECT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_MODE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_REJECT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SECURITY_MODE_REJECT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_MODE_REJECT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_MODE_REJECT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_MODE_REJECT* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE EMMCause
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->EMMCause = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12872=EDCore::TDMOctet) */Destin->EMMCause___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:167> Error decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 167, (Destin->EMMCause))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:168> Message too short decoding subfield EMMCause\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 167, (Destin->EMMCause))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_PROTECTED_NAS_MESSAGE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SECURITY_PROTECTED_NAS_MESSAGE (char* Buffer, ED_EXLONG BitOffset, const c_SECURITY_PROTECTED_NAS_MESSAGE* Source, int Mode)
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


	}
	
	
	/* Code for MessageAuthenticationCode */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->MessageAuthenticationCode> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs, (Source->MessageAuthenticationCode), 0, 32);
		Len = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:169> Error encoding subfield MessageAuthenticationCode\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for SequenceNumber */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->SequenceNumber> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs, (Source->SequenceNumber), 0, 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:170> Error encoding subfield SequenceNumber\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASMessage */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASMessage> DOT=<.> */
		EDCopyBits (Buffer, CurrOfs, Source->NASMessage.value, 0, Source->NASMessage.usedBits);
		Len = Source->NASMessage.usedBits;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:171> Error encoding subfield NASMessage\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_PROTECTED_NAS_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SECURITY_PROTECTED_NAS_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_PROTECTED_NAS_MESSAGE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_PROTECTED_NAS_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SECURITY_PROTECTED_NAS_MESSAGE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Source))
{
	return L3_ENCODE_c_SECURITY_PROTECTED_NAS_MESSAGE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_PROTECTED_NAS_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SECURITY_PROTECTED_NAS_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SECURITY_PROTECTED_NAS_MESSAGE (Buffer, (BitOffset+8), Destin, Length-(8));
	if (Len < 0) return Len;
	
	return Len+8;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SECURITY_PROTECTED_NAS_MESSAGE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SECURITY_PROTECTED_NAS_MESSAGE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SECURITY_PROTECTED_NAS_MESSAGE* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE MessageAuthenticationCode
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 32;
	/* Read value part LOCATOR_16 */
	EDCopyBits (Destin->MessageAuthenticationCode, 0, Buffer, CurrOfs, 32);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12877=EDCore::TDMBinary) */Destin->MessageAuthenticationCode___LOCATOR), CurrOfs, 32);
	RetLen = 32;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:172> Error decoding subfield MessageAuthenticationCode\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 172, (Destin->MessageAuthenticationCode))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:173> Message too short decoding subfield MessageAuthenticationCode\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 172, (Destin->MessageAuthenticationCode))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE SequenceNumber
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	EDCopyBits (Destin->SequenceNumber, 0, Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCBIN1 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12879=EDCore::TDMBinary) */Destin->SequenceNumber___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:174> Error decoding subfield SequenceNumber\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 174, (Destin->SequenceNumber))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:175> Message too short decoding subfield SequenceNumber\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 174, (Destin->SequenceNumber))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASMessage
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = Length + BitOffset - CurrOfs;
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12881=EDCore::TDMBinary) */Destin->NASMessage___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage (&(Destin->NASMessage), Len);
	
		if (Destin->NASMessage.value) {
			EDCopyBits (Destin->NASMessage.value, 0, Buffer, CurrOfs, Len);
			Destin->NASMessage.usedBits = Len;
			RetLen = Len;
	
		}
		else {
			Destin->NASMessage.usedBits = 0;
			RetLen = ED_OUT_OF_MEMORY;
		}
	}
	else {
		RetLen = Len;
	
	}
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:176> Error decoding subfield NASMessage\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 176, (Destin->NASMessage))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:177> Message too short decoding subfield NASMessage\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 176, (Destin->NASMessage))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_SERVICE_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_SERVICE_REQUEST* Source, int Mode)
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


	}
	
	
	/* Code for KSIAndSequenceNumber */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->KSIAndSequenceNumber> DOT=<.> */
		Len = ENCODE_c_KSIAndSequenceNumber (Buffer, CurrOfs, (&(Source->KSIAndSequenceNumber)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:178> Error encoding subfield KSIAndSequenceNumber\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for MessageAuthenticationCodeShort */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->MessageAuthenticationCodeShort> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->MessageAuthenticationCodeShort), 16);
		Len = 16;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:179> Error encoding subfield MessageAuthenticationCodeShort\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_SERVICE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_SERVICE_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_SERVICE_REQUEST (Buffer, (BitOffset+8), Destin, Length-(8));
	if (Len < 0) return Len;
	
	return Len+8;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		Code for IE KSIAndSequenceNumber
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_KSIAndSequenceNumber (Buffer, CurrOfs, (&(Destin->KSIAndSequenceNumber)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:180> Error decoding subfield KSIAndSequenceNumber\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 180, (Destin->KSIAndSequenceNumber))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:181> Message too short decoding subfield KSIAndSequenceNumber\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 180, (Destin->KSIAndSequenceNumber))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE MessageAuthenticationCodeShort
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 16;
	/* Read value part LOCATOR_16 */
	Destin->MessageAuthenticationCodeShort = (ED_SHORT)EDBitsToInt (Buffer, (CurrOfs), 16);
	/* LOCATOR SETTINGS LOCINT */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-12888=EDCore::TDMInteger) */Destin->MessageAuthenticationCodeShort___LOCATOR), CurrOfs, 16);
	RetLen = 16;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:182> Error decoding subfield MessageAuthenticationCodeShort\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 182, (Destin->MessageAuthenticationCodeShort))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:183> Message too short decoding subfield MessageAuthenticationCodeShort\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 182, (Destin->MessageAuthenticationCodeShort))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_COMPLETE
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_TRACKING_AREA_UPDATE_COMPLETE (char* Buffer, ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_COMPLETE* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 74, 8);
		CurrOfs += 8;
		
	}
	

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_COMPLETE (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_COMPLETE (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_COMPLETE (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_TRACKING_AREA_UPDATE_COMPLETE (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_COMPLETE
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_COMPLETE (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_COMPLETE* ED_CONST Destin, ED_EXLONG Length))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_TRACKING_AREA_UPDATE_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 72, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for EPSUpdateType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->EPSUpdateType> DOT=<.> */
		Len = ENCODE_c_EPSUpdateType (Buffer, (CurrOfs+4), (&(Source->EPSUpdateType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:184> Error encoding subfield EPSUpdateType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASKeySetIdentifier */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifier> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Source->NASKeySetIdentifier)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:185> Error encoding subfield NASKeySetIdentifier\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for OldGUTI */
	{
		int TLV_Base = CurrOfs;
		/* Append to buffer value part DEBUG FIELD=<Source->OldGUTI> DOT=<.> */
		Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, (&(Source->OldGUTI)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:186> Error encoding subfield OldGUTI\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for NonCurrentNativeNASKeySetId */
	{
		if (Source->NonCurrentNativeNASKeySetId_Present) {
			/* Append to buffer IEI tag 0x0B */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0B), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->NonCurrentNativeNASKeySetId> DOT=<->> */
			Len = ENCODE_c_NASKeySetIdentifier (Buffer, CurrOfs, Source->NonCurrentNativeNASKeySetId);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:187> Error encoding subfield NonCurrentNativeNASKeySetId\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for GPRSCipheringKeySequenceNumber */
	{
		if (Source->GPRSCipheringKeySequenceNumber_Present) {
			/* Append to buffer IEI tag 0x08 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x08), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->GPRSCipheringKeySequenceNumber> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->GPRSCipheringKeySequenceNumber), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:188> Error encoding subfield GPRSCipheringKeySequenceNumber\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for OldPTMSISignature */
	{
		if (Source->OldPTMSISignature_Present) {
			/* Append to buffer IEI tag 0x19 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x19), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->OldPTMSISignature> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs, Source->OldPTMSISignature, 0, 24);
			Len = 24;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:189> Error encoding subfield OldPTMSISignature\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for AdditionalGUTI */
	{
		int TLV_Base = CurrOfs;
		if (Source->AdditionalGUTI_Present) {
			/* Append to buffer IEI tag 0x50 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x50), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->AdditionalGUTI> DOT=<->> */
			Len = ENCODE_c_EPSMobileIdentity (Buffer, CurrOfs+8, Source->AdditionalGUTI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:190> Error encoding subfield AdditionalGUTI\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for NonceUE */
	{
		if (Source->NonceUE_Present) {
			/* Append to buffer IEI tag 0x55 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x55), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->NonceUE> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->NonceUE), 32);
			Len = 32;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:191> Error encoding subfield NonceUE\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
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
			Len = ENCODE_c_UENetworkCapability (Buffer, CurrOfs+8, Source->UENetworkCapability);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:192> Error encoding subfield UENetworkCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for LastVisitedRegisteredTAI */
	{
		if (Source->LastVisitedRegisteredTAI_Present) {
			/* Append to buffer IEI tag 0x52 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x52), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->LastVisitedRegisteredTAI> DOT=<->> */
			Len = ENCODE_c_TrackingAreaIdentity (Buffer, CurrOfs, Source->LastVisitedRegisteredTAI);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:193> Error encoding subfield LastVisitedRegisteredTAI\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for DRXParameter */
	{
		if (Source->DRXParameter_Present) {
			/* Append to buffer IEI tag 0x5C */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5C), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->DRXParameter> DOT=<->> */
			Len = ENCODE_c_epsDrxParam (Buffer, CurrOfs, Source->DRXParameter);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:194> Error encoding subfield DRXParameter\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for UERadioCapabilityInformationUpdateNeeded */
	{
		if (Source->UERadioCapabilityInformationUpdateNeeded_Present) {
			/* Append to buffer IEI tag 0x0A */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0A), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->UERadioCapabilityInformationUpdateNeeded> DOT=<.> */
			EDIntToBits (Buffer, (CurrOfs), (int)(Source->UERadioCapabilityInformationUpdateNeeded), 4);
			Len = 4;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:195> Error encoding subfield UERadioCapabilityInformationUpdateNeeded\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
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
				ED_SIGNAL_ERROR ("<ERRID:196> Error encoding subfield EPSBearerContextStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for MSNetworkCapability */
	{
		int TLV_Base = CurrOfs;
		if (Source->MSNetworkCapability_Present) {
			/* Append to buffer IEI tag 0x31 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x31), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->MSNetworkCapability> DOT=<->> */
			Len = ENCODE_c_epsMsNetwkCpblty (Buffer, CurrOfs+8, Source->MSNetworkCapability);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:197> Error encoding subfield MSNetworkCapability\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for OldLocationAreaIdentification */
	{
		if (Source->OldLocationAreaIdentification_Present) {
			/* Append to buffer IEI tag 0x13 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x13), 8);
			CurrOfs += 8;
			/* Append to buffer value part DEBUG FIELD=<Source->OldLocationAreaIdentification> DOT=<->> */
			Len = ENCODE_c_epsLocationAreaId (Buffer, CurrOfs, Source->OldLocationAreaIdentification);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:198> Error encoding subfield OldLocationAreaIdentification\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for TMSIStatus */
	{
		if (Source->TMSIStatus_Present) {
			/* Append to buffer IEI tag 0x09 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x09), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->TMSIStatus> DOT=<->> */
			Len = ENCODE_c_epsTmsiStatus (Buffer, CurrOfs, Source->TMSIStatus);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:199> Error encoding subfield TMSIStatus\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for epsMobileStationClassmark2 */
	{
		int TLV_Base = CurrOfs;
		if (Source->epsMobileStationClassmark2_Present) {
			/* Append to buffer IEI tag 0x11 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x11), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->epsMobileStationClassmark2> DOT=<->> */
			Len = ENCODE_c_epsMobileStationClassmark2 (Buffer, CurrOfs+8, Source->epsMobileStationClassmark2);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:200> Error encoding subfield epsMobileStationClassmark2\n");
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
			Len = ENCODE_c_epsClassmark3Value (Buffer, CurrOfs+8, Source->MobileStationClassmark3);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:201> Error encoding subfield MobileStationClassmark3\n");
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
			Len = ENCODE_c_epsSupportedCodecList (Buffer, CurrOfs+8, Source->SupportedCodecs);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:202> Error encoding subfield SupportedCodecs\n");
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
			Len = ENCODE_c_epsAdditionalUpdateType (Buffer, CurrOfs, Source->AdditionalUpdateType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:203> Error encoding subfield AdditionalUpdateType\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}
	
	/* Code for VoiceDomainPref */
	{
		int TLV_Base = CurrOfs;
		if (Source->VoiceDomainPref_Present) {
			/* Append to buffer IEI tag 0x5D */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x5D), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->VoiceDomainPref> DOT=<->> */
			Len = ENCODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs+8, Source->VoiceDomainPref);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:204> Error encoding subfield VoiceDomainPref\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
		}
	}
	
	/* Code for OldGUTIType */
	{
		if (Source->OldGUTIType_Present) {
			/* Append to buffer IEI tag 0x0E */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x0E), 4);
			CurrOfs += 4;
			/* Append to buffer value part DEBUG FIELD=<Source->OldGUTIType> DOT=<->> */
			Len = ENCODE_c_GUTIType (Buffer, CurrOfs, Source->OldGUTIType);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:205> Error encoding subfield OldGUTIType\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:206> Error encoding subfield DeviceProperties\n");
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
			Len = ENCODE_c_epsMSNetworkFeatureSupport (Buffer, CurrOfs, Source->MSNetworkFeatureSupport);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:207> Error encoding subfield MSNetworkFeatureSupport\n");
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
			Len = ENCODE_c_epsNetworkResourceIdentifierContainer (Buffer, CurrOfs+8, Source->TMSIBasedNRIContainer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:208> Error encoding subfield TMSIBasedNRIContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:209> Error encoding subfield T3324ValueGPRSTimer2\n");
				return -1;
			} 
#endif
			CurrOfs += Len+8;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
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
				ED_SIGNAL_ERROR ("<ERRID:210> Error encoding subfield T3412ExtendedValue\n");
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
				ED_SIGNAL_ERROR ("<ERRID:211> Error encoding subfield ExtendedDRXParameters\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_TRACKING_AREA_UPDATE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_TRACKING_AREA_UPDATE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_TRACKING_AREA_UPDATE_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_TRACKING_AREA_UPDATE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_TRACKING_AREA_UPDATE_REQUEST (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE TRACKING_AREA_UPDATE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_TRACKING_AREA_UPDATE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_TRACKING_AREA_UPDATE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{176, 240, ED_SKIPLIST_OPTIONAL},
		{128, 240, ED_SKIPLIST_OPTIONAL},
		{25, 255, ED_SKIPLIST_OPTIONAL},
		{80, 255, ED_SKIPLIST_OPTIONAL},
		{85, 255, ED_SKIPLIST_OPTIONAL},
		{88, 255, ED_SKIPLIST_OPTIONAL},
		{82, 255, ED_SKIPLIST_OPTIONAL},
		{92, 255, ED_SKIPLIST_OPTIONAL},
		{160, 240, ED_SKIPLIST_OPTIONAL},
		{87, 255, ED_SKIPLIST_OPTIONAL},
		{49, 255, ED_SKIPLIST_OPTIONAL},
		{19, 255, ED_SKIPLIST_OPTIONAL},
		{144, 240, ED_SKIPLIST_OPTIONAL},
		{17, 255, ED_SKIPLIST_OPTIONAL},
		{32, 255, ED_SKIPLIST_OPTIONAL},
		{64, 255, ED_SKIPLIST_OPTIONAL},
		{240, 240, ED_SKIPLIST_OPTIONAL},
		{93, 255, ED_SKIPLIST_OPTIONAL},
		{224, 240, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{192, 240, ED_SKIPLIST_OPTIONAL},
		{16, 255, ED_SKIPLIST_OPTIONAL},
		{106, 255, ED_SKIPLIST_OPTIONAL},
		{94, 255, ED_SKIPLIST_OPTIONAL},
		{110, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE EPSUpdateType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPSUpdateType (Buffer, (CurrOfs+4), (&(Destin->EPSUpdateType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:212> Error decoding subfield EPSUpdateType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 212, (Destin->EPSUpdateType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:213> Message too short decoding subfield EPSUpdateType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 212, (Destin->EPSUpdateType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASKeySetIdentifier
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Destin->NASKeySetIdentifier)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:214> Error decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 214, (Destin->NASKeySetIdentifier))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:215> Message too short decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 214, (Destin->NASKeySetIdentifier))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE OldGUTI
	------------------------------------------------------*/
	CurrOfs += 0;
	/* Insert into buffer LEN  */
	Len = EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (Len != 88) {
		ED_SIGNAL_ERROR ("<ERRID:216> Size error decoding IE OldGUTI\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 216, (Destin->OldGUTI))
	} 
#endif
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, (&(Destin->OldGUTI)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:217> Error decoding subfield OldGUTI\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 217, (Destin->OldGUTI))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:218> Message too short decoding subfield OldGUTI\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 217, (Destin->OldGUTI))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NonCurrentNativeNASKeySetId
	------------------------------------------------------*/
	/* Detect IEI tag 0x0B */
	ED_EXPECT_OPTIONAL_IE (0x0B,  4, 219, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0B) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_NASKeySetIdentifier (Buffer, CurrOfs, Destin->NonCurrentNativeNASKeySetId, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:220> Error decoding subfield NonCurrentNativeNASKeySetId\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0B, 220, (Destin->NonCurrentNativeNASKeySetId))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:221> Message too short decoding subfield NonCurrentNativeNASKeySetId\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0B, 220, (Destin->NonCurrentNativeNASKeySetId))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE GPRSCipheringKeySequenceNumber
	------------------------------------------------------*/
	/* Detect IEI tag 0x08 */
	ED_EXPECT_OPTIONAL_IE (0x08,  4, 222, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x08) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->GPRSCipheringKeySequenceNumber = (ED_OCTET)EDBitsToInt (Buffer, (CurrOfs), 4);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-12904=EDCore::TDMInteger) */Destin->GPRSCipheringKeySequenceNumber___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:223> Error decoding subfield GPRSCipheringKeySequenceNumber\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x08, 223, (Destin->GPRSCipheringKeySequenceNumber))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:224> Message too short decoding subfield GPRSCipheringKeySequenceNumber\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x08, 223, (Destin->GPRSCipheringKeySequenceNumber))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldPTMSISignature
	------------------------------------------------------*/
	/* Detect IEI tag 0x19 */
	ED_EXPECT_OPTIONAL_IE (0x19,  8, 225, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x19) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 24;
		/* Read value part LOCATOR_16 */
		EDCopyBits (Destin->OldPTMSISignature, 0, Buffer, CurrOfs, 24);
		/* LOCATOR SETTINGS LOCBIN1 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12906=EDCore::TDMBinary) */Destin->OldPTMSISignature___LOCATOR), CurrOfs, 24);
		RetLen = 24;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:226> Error decoding subfield OldPTMSISignature\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x19, 226, (Destin->OldPTMSISignature))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:227> Message too short decoding subfield OldPTMSISignature\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x19, 226, (Destin->OldPTMSISignature))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalGUTI
	------------------------------------------------------*/
	/* Detect IEI tag 0x50 */
	ED_EXPECT_OPTIONAL_IE (0x50,  8, 228, 6, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x50) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 88) {
			ED_SIGNAL_ERROR ("<ERRID:229> Size error decoding IE AdditionalGUTI\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x50, 229, (Destin->AdditionalGUTI))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSMobileIdentity (Buffer, CurrOfs, Destin->AdditionalGUTI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:230> Error decoding subfield AdditionalGUTI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x50, 230, (Destin->AdditionalGUTI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:231> Message too short decoding subfield AdditionalGUTI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x50, 230, (Destin->AdditionalGUTI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NonceUE
	------------------------------------------------------*/
	/* Detect IEI tag 0x55 */
	ED_EXPECT_OPTIONAL_IE (0x55,  8, 232, 7, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x55) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 32;
		/* Read value part LOCATOR_16 */
		Destin->NonceUE = (ED_LONG)EDBitsToInt (Buffer, (CurrOfs), 32);
		/* LOCATOR SETTINGS LOCINT */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMInteger'-12910=EDCore::TDMInteger) */Destin->NonceUE___LOCATOR), CurrOfs, 32);
		RetLen = 32;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:233> Error decoding subfield NonceUE\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x55, 233, (Destin->NonceUE))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:234> Message too short decoding subfield NonceUE\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x55, 233, (Destin->NonceUE))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UENetworkCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x58 */
	ED_EXPECT_OPTIONAL_IE (0x58,  8, 235, 8, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x58) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 104)) {
			ED_SIGNAL_ERROR ("<ERRID:236> Size error decoding IE UENetworkCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x58, 236, (Destin->UENetworkCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_UENetworkCapability (Buffer, CurrOfs, Destin->UENetworkCapability, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:237> Error decoding subfield UENetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x58, 237, (Destin->UENetworkCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:238> Message too short decoding subfield UENetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x58, 237, (Destin->UENetworkCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE LastVisitedRegisteredTAI
	------------------------------------------------------*/
	/* Detect IEI tag 0x52 */
	ED_EXPECT_OPTIONAL_IE (0x52,  8, 239, 9, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x52) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_TrackingAreaIdentity (Buffer, CurrOfs, Destin->LastVisitedRegisteredTAI, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:240> Error decoding subfield LastVisitedRegisteredTAI\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x52, 240, (Destin->LastVisitedRegisteredTAI))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:241> Message too short decoding subfield LastVisitedRegisteredTAI\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x52, 240, (Destin->LastVisitedRegisteredTAI))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DRXParameter
	------------------------------------------------------*/
	/* Detect IEI tag 0x5C */
	ED_EXPECT_OPTIONAL_IE (0x5C,  8, 242, 10, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 16;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDrxParam (Buffer, CurrOfs, Destin->DRXParameter, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:243> Error decoding subfield DRXParameter\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5C, 243, (Destin->DRXParameter))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:244> Message too short decoding subfield DRXParameter\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5C, 243, (Destin->DRXParameter))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE UERadioCapabilityInformationUpdateNeeded
	------------------------------------------------------*/
	/* Detect IEI tag 0x0A */
	ED_EXPECT_OPTIONAL_IE (0x0A,  4, 245, 11, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		Destin->UERadioCapabilityInformationUpdateNeeded = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 4);
		/* LOCATOR SETTINGS LOCOCTET */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12918=EDCore::TDMOctet) */Destin->UERadioCapabilityInformationUpdateNeeded___LOCATOR), CurrOfs, 4);
		RetLen = 4;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:246> Error decoding subfield UERadioCapabilityInformationUpdateNeeded\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0A, 246, (Destin->UERadioCapabilityInformationUpdateNeeded))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:247> Message too short decoding subfield UERadioCapabilityInformationUpdateNeeded\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0A, 246, (Destin->UERadioCapabilityInformationUpdateNeeded))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EPSBearerContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x57 */
	ED_EXPECT_OPTIONAL_IE (0x57,  8, 248, 12, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x57) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:249> Size error decoding IE EPSBearerContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x57, 249, (Destin->EPSBearerContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSBearerContextStatus (Buffer, CurrOfs, Destin->EPSBearerContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:250> Error decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x57, 250, (Destin->EPSBearerContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:251> Message too short decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x57, 250, (Destin->EPSBearerContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSNetworkCapability
	------------------------------------------------------*/
	/* Detect IEI tag 0x31 */
	ED_EXPECT_OPTIONAL_IE (0x31,  8, 252, 13, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x31) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 64)) {
			ED_SIGNAL_ERROR ("<ERRID:253> Size error decoding IE MSNetworkCapability\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x31, 253, (Destin->MSNetworkCapability))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMsNetwkCpblty (Buffer, CurrOfs, Destin->MSNetworkCapability, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:254> Error decoding subfield MSNetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x31, 254, (Destin->MSNetworkCapability))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:255> Message too short decoding subfield MSNetworkCapability\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x31, 254, (Destin->MSNetworkCapability))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldLocationAreaIdentification
	------------------------------------------------------*/
	/* Detect IEI tag 0x13 */
	ED_EXPECT_OPTIONAL_IE (0x13,  8, 256, 14, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x13) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		Len = 40;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsLocationAreaId (Buffer, CurrOfs, Destin->OldLocationAreaIdentification, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:257> Error decoding subfield OldLocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x13, 257, (Destin->OldLocationAreaIdentification))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:258> Message too short decoding subfield OldLocationAreaIdentification\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x13, 257, (Destin->OldLocationAreaIdentification))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TMSIStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x09 */
	ED_EXPECT_OPTIONAL_IE (0x09,  4, 259, 15, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x09) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsTmsiStatus (Buffer, CurrOfs, Destin->TMSIStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:260> Error decoding subfield TMSIStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x09, 260, (Destin->TMSIStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:261> Message too short decoding subfield TMSIStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x09, 260, (Destin->TMSIStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE epsMobileStationClassmark2
	------------------------------------------------------*/
	/* Detect IEI tag 0x11 */
	ED_EXPECT_OPTIONAL_IE (0x11,  8, 262, 16, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x11) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 24) {
			ED_SIGNAL_ERROR ("<ERRID:263> Size error decoding IE epsMobileStationClassmark2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x11, 263, (Destin->epsMobileStationClassmark2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMobileStationClassmark2 (Buffer, CurrOfs, Destin->epsMobileStationClassmark2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:264> Error decoding subfield epsMobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x11, 264, (Destin->epsMobileStationClassmark2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:265> Message too short decoding subfield epsMobileStationClassmark2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x11, 264, (Destin->epsMobileStationClassmark2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MobileStationClassmark3
	------------------------------------------------------*/
	/* Detect IEI tag 0x20 */
	ED_EXPECT_OPTIONAL_IE (0x20,  8, 266, 17, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x20) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len > 256) {
			ED_SIGNAL_ERROR ("<ERRID:267> Size error decoding IE MobileStationClassmark3\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x20, 267, (Destin->MobileStationClassmark3))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsClassmark3Value (Buffer, CurrOfs, Destin->MobileStationClassmark3, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:268> Error decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x20, 268, (Destin->MobileStationClassmark3))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:269> Message too short decoding subfield MobileStationClassmark3\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x20, 268, (Destin->MobileStationClassmark3))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE SupportedCodecs
	------------------------------------------------------*/
	/* Detect IEI tag 0x40 */
	ED_EXPECT_OPTIONAL_IE (0x40,  8, 270, 18, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x40) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 24) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:271> Size error decoding IE SupportedCodecs\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x40, 271, (Destin->SupportedCodecs))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsSupportedCodecList (Buffer, CurrOfs, Destin->SupportedCodecs, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:272> Error decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x40, 272, (Destin->SupportedCodecs))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:273> Message too short decoding subfield SupportedCodecs\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x40, 272, (Destin->SupportedCodecs))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalUpdateType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0F */
	ED_EXPECT_OPTIONAL_IE (0x0F,  4, 274, 19, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0F) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsAdditionalUpdateType (Buffer, CurrOfs, Destin->AdditionalUpdateType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:275> Error decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0F, 275, (Destin->AdditionalUpdateType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:276> Message too short decoding subfield AdditionalUpdateType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0F, 275, (Destin->AdditionalUpdateType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE VoiceDomainPref
	------------------------------------------------------*/
	/* Detect IEI tag 0x5D */
	ED_EXPECT_OPTIONAL_IE (0x5D,  8, 277, 20, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:278> Size error decoding IE VoiceDomainPref\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5D, 278, (Destin->VoiceDomainPref))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsVoiceDomainPreferenceAndUEsUsageSetting (Buffer, CurrOfs, Destin->VoiceDomainPref, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:279> Error decoding subfield VoiceDomainPref\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5D, 279, (Destin->VoiceDomainPref))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:280> Message too short decoding subfield VoiceDomainPref\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5D, 279, (Destin->VoiceDomainPref))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE OldGUTIType
	------------------------------------------------------*/
	/* Detect IEI tag 0x0E */
	ED_EXPECT_OPTIONAL_IE (0x0E,  4, 281, 21, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_GUTIType (Buffer, CurrOfs, Destin->OldGUTIType, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:282> Error decoding subfield OldGUTIType\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0E, 282, (Destin->OldGUTIType))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:283> Message too short decoding subfield OldGUTIType\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0E, 282, (Destin->OldGUTIType))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 284, 22, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:285> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 285, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:286> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 285, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE MSNetworkFeatureSupport
	------------------------------------------------------*/
	/* Detect IEI tag 0x0C */
	ED_EXPECT_OPTIONAL_IE (0x0C,  4, 287, 23, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0C) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsMSNetworkFeatureSupport (Buffer, CurrOfs, Destin->MSNetworkFeatureSupport, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:288> Error decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0C, 288, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:289> Message too short decoding subfield MSNetworkFeatureSupport\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0C, 288, (Destin->MSNetworkFeatureSupport))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE TMSIBasedNRIContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x10 */
	ED_EXPECT_OPTIONAL_IE (0x10,  8, 290, 24, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x10) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:291> Size error decoding IE TMSIBasedNRIContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x10, 291, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsNetworkResourceIdentifierContainer (Buffer, CurrOfs, Destin->TMSIBasedNRIContainer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:292> Error decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x10, 292, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:293> Message too short decoding subfield TMSIBasedNRIContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x10, 292, (Destin->TMSIBasedNRIContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3324ValueGPRSTimer2
	------------------------------------------------------*/
	/* Detect IEI tag 0x6A */
	ED_EXPECT_OPTIONAL_IE (0x6A,  8, 294, 25, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6A) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:295> Size error decoding IE T3324ValueGPRSTimer2\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6A, 295, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer2 (Buffer, CurrOfs, Destin->T3324ValueGPRSTimer2, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:296> Error decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6A, 296, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:297> Message too short decoding subfield T3324ValueGPRSTimer2\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2 (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6A, 296, (Destin->T3324ValueGPRSTimer2))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE T3412ExtendedValue
	------------------------------------------------------*/
	/* Detect IEI tag 0x5E */
	ED_EXPECT_OPTIONAL_IE (0x5E,  8, 298, 26, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x5E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:299> Size error decoding IE T3412ExtendedValue\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x5E, 299, (Destin->T3412ExtendedValue))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsGprsTimer (Buffer, CurrOfs, Destin->T3412ExtendedValue, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:300> Error decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x5E, 300, (Destin->T3412ExtendedValue))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:301> Message too short decoding subfield T3412ExtendedValue\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x5E, 300, (Destin->T3412ExtendedValue))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE ExtendedDRXParameters
	------------------------------------------------------*/
	/* Detect IEI tag 0x6E */
	ED_EXPECT_OPTIONAL_IE (0x6E,  8, 302, 27, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x6E) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 8) {
			ED_SIGNAL_ERROR ("<ERRID:303> Size error decoding IE ExtendedDRXParameters\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x6E, 303, (Destin->ExtendedDRXParameters))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsExtendedDRXParameters (Buffer, CurrOfs, Destin->ExtendedDRXParameters, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:304> Error decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x6E, 304, (Destin->ExtendedDRXParameters))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:305> Message too short decoding subfield ExtendedDRXParameters\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x6E, 304, (Destin->ExtendedDRXParameters))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_NAS_TRANSPORT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_UPLINK_NAS_TRANSPORT (char* Buffer, ED_EXLONG BitOffset, const c_UPLINK_NAS_TRANSPORT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 99, 8);
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
			ED_SIGNAL_ERROR ("<ERRID:306> Error encoding subfield NASMessageContainer\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UPLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_UPLINK_NAS_TRANSPORT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_UPLINK_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_UPLINK_NAS_TRANSPORT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UPLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_UPLINK_NAS_TRANSPORT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_UPLINK_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
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
		ED_SIGNAL_ERROR ("<ERRID:307> Size error decoding IE NASMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 307, (Destin->NASMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12955=EDCore::TDMBinary) */Destin->NASMessageContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_UPLINK_NAS_TRANSPORT_NASMessageContainer (&(Destin->NASMessageContainer), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:308> Error decoding subfield NASMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 308, (Destin->NASMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:309> Message too short decoding subfield NASMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 308, (Destin->NASMessageContainer))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_GENERIC_NAS_TRANSPORT
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_UPLINK_GENERIC_NAS_TRANSPORT (char* Buffer, ED_EXLONG BitOffset, const c_UPLINK_GENERIC_NAS_TRANSPORT* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 105, 8);
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
			ED_SIGNAL_ERROR ("<ERRID:310> Error encoding subfield NASMessageContainer\n");
			return -1;
		} 
#endif
		CurrOfs += Len+8;
		/* Insert into buffer LEN  */
		EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 8) >> 3), 8);
	}
	
	/* Code for GenericMessageContainerType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->GenericMessageContainerType> DOT=<.> */
		EDIntToBits (Buffer, (CurrOfs), (int)(Source->GenericMessageContainerType), 8);
		Len = 8;
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:311> Error encoding subfield GenericMessageContainerType\n");
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
			ED_SIGNAL_ERROR ("<ERRID:312> Error encoding subfield GenericMessageContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:313> Error encoding subfield AdditionalInformation\n");
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_UPLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_UPLINK_GENERIC_NAS_TRANSPORT (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_UPLINK_GENERIC_NAS_TRANSPORT (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Source))
{
	return L3_ENCODE_c_UPLINK_GENERIC_NAS_TRANSPORT (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_UPLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_UPLINK_GENERIC_NAS_TRANSPORT (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE UPLINK_GENERIC_NAS_TRANSPORT
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_UPLINK_GENERIC_NAS_TRANSPORT (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_UPLINK_GENERIC_NAS_TRANSPORT* ED_CONST Destin, ED_EXLONG Length))
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
		{101, 255, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
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
		ED_SIGNAL_ERROR ("<ERRID:314> Size error decoding IE NASMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 314, (Destin->NASMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12960=EDCore::TDMBinary) */Destin->NASMessageContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer (&(Destin->NASMessageContainer), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:315> Error decoding subfield NASMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 315, (Destin->NASMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:316> Message too short decoding subfield NASMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 315, (Destin->NASMessageContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE GenericMessageContainerType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 8;
	/* Read value part LOCATOR_16 */
	Destin->GenericMessageContainerType = (unsigned char)EDBitsToInt (Buffer, CurrOfs, 8);
	/* LOCATOR SETTINGS LOCOCTET */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMOctet'-12962=EDCore::TDMOctet) */Destin->GenericMessageContainerType___LOCATOR), CurrOfs, 8);
	RetLen = 8;
	
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:317> Error decoding subfield GenericMessageContainerType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 317, (Destin->GenericMessageContainerType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:318> Message too short decoding subfield GenericMessageContainerType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 317, (Destin->GenericMessageContainerType))
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
		ED_SIGNAL_ERROR ("<ERRID:319> Size error decoding IE GenericMessageContainer\n");
		ED_HANDLE_IE_SIZE_ERROR ((-1), 319, (Destin->GenericMessageContainer))
	} 
#endif
	/* Read value part LOCATOR_16 */
	/* LOCATOR SETTINGS LOCBIN2 */;
	ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12964=EDCore::TDMBinary) */Destin->GenericMessageContainer___LOCATOR), CurrOfs, Len);
	if (Len > 0) {
		/* BINDEC02 */
		ALLOC_c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer (&(Destin->GenericMessageContainer), Len);
	
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
		ED_SIGNAL_ERROR ("<ERRID:320> Error decoding subfield GenericMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 320, (Destin->GenericMessageContainer))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:321> Message too short decoding subfield GenericMessageContainer\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 320, (Destin->GenericMessageContainer))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE AdditionalInformation
	------------------------------------------------------*/
	/* Detect IEI tag 0x65 */
	ED_EXPECT_OPTIONAL_IE (0x65,  8, 322, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x65) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4784)) {
			ED_SIGNAL_ERROR ("<ERRID:323> Size error decoding IE AdditionalInformation\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x65, 323, (Destin->AdditionalInformation))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12966=EDCore::TDMBinary) */Destin->AdditionalInformation___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin->AdditionalInformation, Len);
		
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
			ED_SIGNAL_ERROR ("<ERRID:324> Error decoding subfield AdditionalInformation\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x65, 324, (Destin->AdditionalInformation))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:325> Message too short decoding subfield AdditionalInformation\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x65, 324, (Destin->AdditionalInformation))
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
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONTROL_PLANE_SERVICE_REQUEST
	Mode: 
		0=normal (full message)
		1=body only
-----------------------------------------------------------------*/
ED_EXLONG L3_ENCODE_c_CONTROL_PLANE_SERVICE_REQUEST (char* Buffer, ED_EXLONG BitOffset, const c_CONTROL_PLANE_SERVICE_REQUEST* Source, int Mode)
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
		EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, 77, 8);
		CurrOfs += 8;
		
	}
	
	
	/* Code for DataServiceType */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->DataServiceType> DOT=<.> */
		Len = ENCODE_c_DataServiceType (Buffer, (CurrOfs+4), (&(Source->DataServiceType)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:326> Error encoding subfield DataServiceType\n");
			return -1;
		} 
#endif
		CurrOfs += Len;
	}
	
	/* Code for NASKeySetIdentifier */
	{
		/* Append to buffer value part DEBUG FIELD=<Source->NASKeySetIdentifier> DOT=<.> */
		Len = ENCODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Source->NASKeySetIdentifier)));
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len < 0) {
			ED_SIGNAL_ERROR ("<ERRID:327> Error encoding subfield NASKeySetIdentifier\n");
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
			Len = ENCODE_c_ESMMessageUp (Buffer, CurrOfs+16, Source->ESMMessageContainer);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:328> Error encoding subfield ESMMessageContainer\n");
				return -1;
			} 
#endif
			CurrOfs += Len+16;
			/* Insert into buffer LEN  */
			EDIntToBits (Buffer, (ED_EXLONG)TLV_Base, (int)((CurrOfs - TLV_Base - 16) >> 3), 16);
		}
	}
	
	/* Code for NASMessageContainer */
	{
		int TLV_Base = CurrOfs;
		if (Source->NASMessageContainer_Present) {
			/* Append to buffer IEI tag 0x67 */
			EDIntToBits (Buffer, (ED_EXLONG)CurrOfs, (int)(0x67), 8);
			CurrOfs += 8;TLV_Base = CurrOfs;
			/* Append to buffer value part DEBUG FIELD=<Source->NASMessageContainer> DOT=<->> */
			EDCopyBits (Buffer, CurrOfs+8, Source->NASMessageContainer->value, 0, Source->NASMessageContainer->usedBits);
			Len = Source->NASMessageContainer->usedBits;
			
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:329> Error encoding subfield NASMessageContainer\n");
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
				ED_SIGNAL_ERROR ("<ERRID:330> Error encoding subfield EPSBearerContextStatus\n");
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
			Len = ENCODE_c_epsDeviceProperties (Buffer, CurrOfs, Source->DeviceProperties);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
			if (Len < 0) {
				ED_SIGNAL_ERROR ("<ERRID:331> Error encoding subfield DeviceProperties\n");
				return -1;
			} 
#endif
			CurrOfs += Len;
		}
	}

	return (CurrOfs - BitOffset);
}
/*-----------------------------------------------------------------
	ENCODING FUNCTION FOR GSM-L3 MESSAGE CONTROL_PLANE_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_CONTROL_PLANE_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_CONTROL_PLANE_SERVICE_REQUEST (Buffer, BitOffset, Source, 0);
}

/*-----------------------------------------------------------------
	BODY-ONLY ENCODING FUNCTION FOR GSM-L3 MESSAGE CONTROL_PLANE_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, ENCODE_BODY_c_CONTROL_PLANE_SERVICE_REQUEST (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Source))
{
	return L3_ENCODE_c_CONTROL_PLANE_SERVICE_REQUEST (Buffer, BitOffset, Source, 1);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONTROL_PLANE_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_CONTROL_PLANE_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
{
	int Len=0;
	/* Decode the security header type */
	Destin->SecurityHeaderType = (ED_OCTET)EDBitsToInt (Buffer, BitOffset, 4);

	Len = DECODE_BODY_c_CONTROL_PLANE_SERVICE_REQUEST (Buffer, (BitOffset+16), Destin, Length-(16));
	if (Len < 0) return Len;
	
	return Len+16;
}

/*-----------------------------------------------------------------
	DECODING FUNCTION FOR GSM-L3 MESSAGE CONTROL_PLANE_SERVICE_REQUEST
-----------------------------------------------------------------*/
ED_EXPORT_CALL (ED_EXLONG, DECODE_BODY_c_CONTROL_PLANE_SERVICE_REQUEST (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_CONTROL_PLANE_SERVICE_REQUEST* ED_CONST Destin, ED_EXLONG Length))
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
		{120, 255, ED_SKIPLIST_OPTIONAL},
		{103, 255, ED_SKIPLIST_OPTIONAL},
		{87, 255, ED_SKIPLIST_OPTIONAL},
		{208, 240, ED_SKIPLIST_OPTIONAL},
		{0, 0, ED_SKIPLIST_END_OF_LIST}
	};
	/* Stores temporary TAG values for tagged IEs */
	int Tag;
	/* Stores temporary len values for L-type IEs */
	int RetLen=0, Len=0;
	ED_WARNING_REMOVER (TLVSkipItems);
	
	/*----------------------------------------------------- 
		Code for IE DataServiceType
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_DataServiceType (Buffer, (CurrOfs+4), (&(Destin->DataServiceType)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:332> Error decoding subfield DataServiceType\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 332, (Destin->DataServiceType))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:333> Message too short decoding subfield DataServiceType\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 332, (Destin->DataServiceType))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE NASKeySetIdentifier
	------------------------------------------------------*/
	CurrOfs += 0;
	Len = 4;
	/* Read value part LOCATOR_16 */
	RetLen = DECODE_c_NASKeySetIdentifier (Buffer, (CurrOfs-4), (&(Destin->NASKeySetIdentifier)), Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (RetLen != Len) {
		ED_SIGNAL_ERROR ("<ERRID:334> Error decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_SYNTAX_ERROR ((-1), 334, (Destin->NASKeySetIdentifier))
	} 
#endif
	CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
	if (CurrOfs > (BitOffset+Length)) {
		ED_SIGNAL_ERROR ("<ERRID:335> Message too short decoding subfield NASKeySetIdentifier\n");
		ED_HANDLE_MANDATORY_IE_MSG_TOO_SHORT ((-1), 334, (Destin->NASKeySetIdentifier))
	} 
#endif
	
	
	
	/*----------------------------------------------------- 
		Code for IE ESMMessageContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x78 */
	ED_EXPECT_OPTIONAL_IE (0x78,  8, 336, 2, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x78) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 16);
		CurrOfs += 16;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 8) || (Len > 4776)) {
			ED_SIGNAL_ERROR ("<ERRID:337> Size error decoding IE ESMMessageContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x78, 337, (Destin->ESMMessageContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_ESMMessageUp (Buffer, CurrOfs, Destin->ESMMessageContainer, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:338> Error decoding subfield ESMMessageContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x78, 338, (Destin->ESMMessageContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:339> Message too short decoding subfield ESMMessageContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x78, 338, (Destin->ESMMessageContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE NASMessageContainer
	------------------------------------------------------*/
	/* Detect IEI tag 0x67 */
	ED_EXPECT_OPTIONAL_IE (0x67,  8, 340, 3, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x67) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if ((Len < 16) || (Len > 2008)) {
			ED_SIGNAL_ERROR ("<ERRID:341> Size error decoding IE NASMessageContainer\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x67, 341, (Destin->NASMessageContainer))
		} 
#endif
		/* Read value part LOCATOR_16 */
		/* LOCATOR SETTINGS LOCBIN2 */;
		ED_LOCATOR_SET (&(/*LOCATOR_16 ('TDMBinary'-12977=EDCore::TDMBinary) */Destin->NASMessageContainer___LOCATOR), CurrOfs, Len);
		if (Len > 0) {
			/* BINDEC02 */
			ALLOC_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (Destin->NASMessageContainer, Len);
		
			if (Destin->NASMessageContainer->value) {
				EDCopyBits (Destin->NASMessageContainer->value, 0, Buffer, CurrOfs, Len);
				Destin->NASMessageContainer->usedBits = Len;
				RetLen = Len;
		
			}
			else {
				Destin->NASMessageContainer->usedBits = 0;
				RetLen = ED_OUT_OF_MEMORY;
			}
		}
		else {
			RetLen = Len;
		
		}
		
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:342> Error decoding subfield NASMessageContainer\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x67, 342, (Destin->NASMessageContainer))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:343> Message too short decoding subfield NASMessageContainer\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x67, 342, (Destin->NASMessageContainer))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE EPSBearerContextStatus
	------------------------------------------------------*/
	/* Detect IEI tag 0x57 */
	ED_EXPECT_OPTIONAL_IE (0x57,  8, 344, 4, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x57) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 8;
		/* Insert into buffer LEN  */
		Len = EDBitsToInt (Buffer, CurrOfs, 8);
		CurrOfs += 8;
		Len <<= 3;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (Len != 16) {
			ED_SIGNAL_ERROR ("<ERRID:345> Size error decoding IE EPSBearerContextStatus\n");
#if ED_HANDLE_IE_SIZE_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
				ED_HANDLE_IE_SIZE_ERROR (0x57, 345, (Destin->EPSBearerContextStatus))
		} 
#endif
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_EPSBearerContextStatus (Buffer, CurrOfs, Destin->EPSBearerContextStatus, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:346> Error decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x57, 346, (Destin->EPSBearerContextStatus))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:347> Message too short decoding subfield EPSBearerContextStatus\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x57, 346, (Destin->EPSBearerContextStatus))
		} 
#endif
		
	
	}
	
	
	/*----------------------------------------------------- 
		Code for IE DeviceProperties
	------------------------------------------------------*/
	/* Detect IEI tag 0x0D */
	ED_EXPECT_OPTIONAL_IE (0x0D,  4, 348, 5, KnownL3IEs_EPS)
	
	/* This is an optional field */
	if (Tag == 0x0D) {
		ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK13*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties (Destin, ED_TRUE), != ED_NO_ERRORS)
		CurrOfs += 4;
		Len = 4;
		/* Read value part LOCATOR_16 */
		RetLen = DECODE_c_epsDeviceProperties (Buffer, CurrOfs, Destin->DeviceProperties, Len);
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (RetLen != Len) {
			ED_SIGNAL_ERROR ("<ERRID:349> Error decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_SYNTAX_ERROR (0x0D, 349, (Destin->DeviceProperties))
		} 
#endif
		CurrOfs += Len;
#ifndef ED_NO_EXTENSIVE_ERROR_LOGGING
		if (CurrOfs > (BitOffset+Length)) {
			ED_SIGNAL_ERROR ("<ERRID:350> Message too short decoding subfield DeviceProperties\n");
#if ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT_SET_MISSING
			ED_CHECK_OUT_OF_MEMORY_KEEP/*COOMK15*/(/*SETP2*/SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties (Destin, ED_FALSE), != ED_NO_ERRORS)
#endif
			ED_HANDLE_OPTIONAL_IE_MSG_TOO_SHORT (0x0D, 349, (Destin->DeviceProperties))
		} 
#endif
		
	
	}
	

	return (CurrOfs - BitOffset);
	}
}
#undef THIS
#undef ED_REMAINING_BITS
int Match_c_ATTACH_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 67) /* message type */
	);
}

int Match_c_ATTACH_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 65) /* message type */
	);
}

int Match_c_AUTHENTICATION_FAILURE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 92) /* message type */
	);
}

int Match_c_AUTHENTICATION_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 83) /* message type */
	);
}

int Match_c_EPS_DETACH_ACCEPT_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 70) /* message type */
	);
}

int Match_c_EPS_DETACH_REQUEST_UP (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 69) /* message type */
	);
}

int Match_c_EMM_STATUS (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 96) /* message type */
	);
}

int Match_c_EXTENDED_SERVICE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 76) /* message type */
	);
}

int Match_c_GUTI_REALLOCATION_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 81) /* message type */
	);
}

int Match_c_IDENTITY_RESPONSE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 86) /* message type */
	);
}

int Match_c_SECURITY_MODE_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 94) /* message type */
	);
}

int Match_c_SECURITY_MODE_REJECT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 95) /* message type */
	);
}

int Match_c_SECURITY_PROTECTED_NAS_MESSAGE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 99999) /* message type */
	);
}

int Match_c_SERVICE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 99999) /* message type */
	);
}

int Match_c_TRACKING_AREA_UPDATE_COMPLETE (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 74) /* message type */
	);
}

int Match_c_TRACKING_AREA_UPDATE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 72) /* message type */
	);
}

int Match_c_UPLINK_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 99) /* message type */
	);
}

int Match_c_UPLINK_GENERIC_NAS_TRANSPORT (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 105) /* message type */
	);
}

int Match_c_CONTROL_PLANE_SERVICE_REQUEST (const char* Buffer, ED_CONST ED_EXLONG BitOffset)
{
	return (
		(EDBitsToInt (Buffer, BitOffset, 8) == 7) /* protocol discriminator & skip indicator */
		&& ((EDBitsToInt (Buffer, BitOffset+8, 8)) == 77) /* message type */
	);
}

