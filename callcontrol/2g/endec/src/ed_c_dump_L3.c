/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-dump
	http://www.Dafocus.it/
**************************************************************************/


#include "ed_c_dump_L3.h"
#include "ed_dump_val.h"

#define DUMPSTR(a) OStream->WriteString (OStream, a)
void Dump_c_ServCategory (TEDOStream* OStream, const c_ServCategory* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ServCategory");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_ServCategory_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "AutomaticallyInitiatedECall");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<AutomaticallyInitiatedECall> ACCESS=<Data->AutomaticallyInitiatedECall>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->AutomaticallyInitiatedECall);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "AutomaticallyInitiatedECall");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "ManuallyInitiatedECall");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ManuallyInitiatedECall> ACCESS=<Data->ManuallyInitiatedECall>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ManuallyInitiatedECall);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "ManuallyInitiatedECall");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "MountainRescue");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MountainRescue> ACCESS=<Data->MountainRescue>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->MountainRescue);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "MountainRescue");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "MarineGuard");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MarineGuard> ACCESS=<Data->MarineGuard>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->MarineGuard);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "MarineGuard");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "FireBrigade");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FireBrigade> ACCESS=<Data->FireBrigade>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->FireBrigade);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "FireBrigade");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "Ambulance");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Ambulance> ACCESS=<Data->Ambulance>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Ambulance);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "Ambulance");
	ED_Dump_Struct_Begin_Field (OStream, "ServCategory", "Police");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Police> ACCESS=<Data->Police>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Police);
	ED_Dump_Struct_End_Field (OStream, "ServCategory", "Police");
	ED_Dump_Struct_End (OStream, "ServCategory");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TBCDArray (TEDOStream* OStream, const c_TBCDArray* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<32> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<ED_LONG> NAME=<data> ACCESS=<Data->data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->data [i0]);
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SupportedCodec (TEDOStream* OStream, const c_SupportedCodec* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SupportedCodec");
	ED_Dump_Struct_Begin_Field (OStream, "SupportedCodec", "SysId");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<SysId> ACCESS=<Data->SysId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SysId);
	ED_Dump_Struct_End_Field (OStream, "SupportedCodec", "SysId");
	ED_Dump_Struct_Begin_Field (OStream, "SupportedCodec", "CodecBitmap");
	  /* NAME=<CodecBitmap> ACCESS=<Data->CodecBitmap>  MAXBITSIZE=<64> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->CodecBitmap.value, Data->CodecBitmap.usedBits);
	ED_Dump_Struct_End_Field (OStream, "SupportedCodec", "CodecBitmap");
	ED_Dump_Struct_End (OStream, "SupportedCodec");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MobileId_TMGI (TEDOStream* OStream, const c_MobileId_TMGI* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MobileId_TMGI");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId_TMGI_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MBMSSessIdIndic");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MBMSSessIdIndic> ACCESS=<Data->MBMSSessIdIndic>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->MBMSSessIdIndic)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MBMS Session Identity is not present"); break;
				case 1: OStream->WriteString (OStream, "MBMS Session Identity is present"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MBMSSessIdIndic");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MCCMNCIndic");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MCCMNCIndic> ACCESS=<Data->MCCMNCIndic>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->MCCMNCIndic)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MCC/MNC is not present"); break;
				case 1: OStream->WriteString (OStream, "MCC/MNC is  present"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MCCMNCIndic");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "OddEven");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId_TMGI_OddEven> NAME=<OddEven> ACCESS=<Data->OddEven>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "OddEven");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "IdentityType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IdentityType> ACCESS=<Data->IdentityType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->IdentityType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No Identity"); break;
				case 1: OStream->WriteString (OStream, "IMSI"); break;
				case 2: OStream->WriteString (OStream, "IMEI"); break;
				case 3: OStream->WriteString (OStream, "IMEISV"); break;
				case 4: OStream->WriteString (OStream, "TMSI/P-TMSI/M-TMSI"); break;
				case 5: OStream->WriteString (OStream, "TMGI and optional MBMS Session Identity"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "IdentityType");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MBMSServiceID");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<MBMSServiceID> ACCESS=<Data->MBMSServiceID>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MBMSServiceID);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MBMSServiceID");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_TMGI", "MBMSSessionIdentity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MBMSSessionIdentity> ACCESS=<Data->MBMSSessionIdentity>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MBMSSessionIdentity);
	ED_Dump_Struct_End_Field (OStream, "MobileId_TMGI", "MBMSSessionIdentity");
	ED_Dump_Struct_End (OStream, "MobileId_TMGI");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_Plmn (TEDOStream* OStream, const c_Plmn* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "Plmn");
	ED_Dump_Struct_Begin_Field (OStream, "Plmn", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "Plmn", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "Plmn", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "Plmn", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "Plmn", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "Plmn", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "Plmn", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "Plmn", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "Plmn", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "Plmn", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "Plmn", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "Plmn", "MNC1");
	ED_Dump_Struct_End (OStream, "Plmn");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TempMobileNumbers (TEDOStream* OStream, const c_TempMobileNumbers* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TempMobileNumbers");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileNumbers", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "TempMobileNumbers", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileNumbers", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "TempMobileNumbers", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileNumbers", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "TempMobileNumbers", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileNumbers", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "TempMobileNumbers", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileNumbers", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "TempMobileNumbers", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileNumbers", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "TempMobileNumbers", "MNC1");
	ED_Dump_Struct_End (OStream, "TempMobileNumbers");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MobileId_Identity (TEDOStream* OStream, const c_MobileId_Identity* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MobileId_Identity");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_Identity", "IdentityDigit");
		/* SEQUENCE NAME=<IdentityDigit> ACCESS=<Data->IdentityDigit>  ITEMS=<17> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "IdentityDigit", Data->IdentityDigit.items);
		for (i0=0; i0<Data->IdentityDigit.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		  /* STRUCTURAL=<1> TYPE=<ED_LONG> NAME=<data> ACCESS=<Data->IdentityDigit.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
		  ED_Dump_Integer (OStream, Data->IdentityDigit.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "IdentityDigit", i0, Data->IdentityDigit.items);
		}
		ED_Dump_Sequence_End (OStream, "IdentityDigit", Data->IdentityDigit.items);
	ED_Dump_Struct_End_Field (OStream, "MobileId_Identity", "IdentityDigit");
	ED_Dump_Struct_Begin_Field (OStream, "MobileId_Identity", "IdentityType");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<IdentityType> ACCESS=<Data->IdentityType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->IdentityType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No Identity"); break;
				case 1: OStream->WriteString (OStream, "IMSI"); break;
				case 2: OStream->WriteString (OStream, "IMEI"); break;
				case 3: OStream->WriteString (OStream, "IMEISV"); break;
				case 4: OStream->WriteString (OStream, "TMSI/P-TMSI/M-TMSI"); break;
				case 5: OStream->WriteString (OStream, "TMGI and optional MBMS Session Identity"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileId_Identity", "IdentityType");
	ED_Dump_Struct_End (OStream, "MobileId_Identity");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TBCDEmergencyNumber (TEDOStream* OStream, const c_TBCDEmergencyNumber* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TBCDEmergencyNumber");
	ED_Dump_Struct_Begin_Field (OStream, "TBCDEmergencyNumber", "ServiceCategory");
	  /* STRUCTURAL=<0> TYPE=<c_ServCategory> NAME=<ServiceCategory> ACCESS=<Data->ServiceCategory>  OPTIONAL=<0> FUNC=<Dump_c_ServCategory> */
	  Dump_c_ServCategory (OStream, &(Data->ServiceCategory));
	ED_Dump_Struct_End_Field (OStream, "TBCDEmergencyNumber", "ServiceCategory");
	ED_Dump_Struct_Begin_Field (OStream, "TBCDEmergencyNumber", "Numbers");
		/* SEQUENCE NAME=<Numbers> ACCESS=<Data->Numbers>  ITEMS=<32> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Numbers", Data->Numbers.items);
		for (i0=0; i0<Data->Numbers.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Numbers", i0, Data->Numbers.items);
		  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->Numbers.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Numbers.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "Numbers", i0, Data->Numbers.items);
		}
		ED_Dump_Sequence_End (OStream, "Numbers", Data->Numbers.items);
	ED_Dump_Struct_End_Field (OStream, "TBCDEmergencyNumber", "Numbers");
	ED_Dump_Struct_End (OStream, "TBCDEmergencyNumber");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CallControlCapabil (TEDOStream* OStream, const c_CallControlCapabil* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CallControlCapabil");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "MaximumSupportedBearers");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumSupportedBearers> ACCESS=<Data->MaximumSupportedBearers>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaximumSupportedBearers);
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "MaximumSupportedBearers");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "MCAT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MCAT> ACCESS=<Data->MCAT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->MCAT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Mobile station does not support Multimedia CAT."); break;
				case 1: OStream->WriteString (OStream, "Mobile station supports Multimedia CAT"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "MCAT");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "ENICM");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ENICM> ACCESS=<Data->ENICM>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->ENICM)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Mobile station does not support the Enhanced Network-initiated In-Call Modification procedure."); break;
				case 1: OStream->WriteString (OStream, "Mobile station supports the Enhanced Network-initiated In-Call Modification procedure"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "ENICM");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "PCP");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PCP> ACCESS=<Data->PCP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->PCP)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Mobile station does not support the Prolonged Clearing Procedure"); break;
				case 1: OStream->WriteString (OStream, "Mobile station supports the Prolonged Clearing Procedure."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "PCP");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "DTMF");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DTMF> ACCESS=<Data->DTMF>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->DTMF)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Reserved for earlier versions of the protocol."); break;
				case 1: OStream->WriteString (OStream, "Mobile station supports"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "DTMF");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "spare2");
	  /* STRUCTURAL=<0> TYPE=<c_CallControlCapabil_spare2> NAME=<spare2> ACCESS=<Data->spare2>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "spare2");
	ED_Dump_Struct_Begin_Field (OStream, "CallControlCapabil", "MaximumNumOfBearers");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumNumOfBearers> ACCESS=<Data->MaximumNumOfBearers>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaximumNumOfBearers);
	ED_Dump_Struct_End_Field (OStream, "CallControlCapabil", "MaximumNumOfBearers");
	ED_Dump_Struct_End (OStream, "CallControlCapabil");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CalledPartySubaddr (TEDOStream* OStream, const c_CalledPartySubaddr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CalledPartySubaddr");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartySubaddr", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_CalledPartySubaddr_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "CalledPartySubaddr", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartySubaddr", "TypeOfSubaddress");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfSubaddress> ACCESS=<Data->TypeOfSubaddress>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfSubaddress)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "NSAP (X.213/ISO 8348 AD2)"); break;
				case 2: OStream->WriteString (OStream, "User specified"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CalledPartySubaddr", "TypeOfSubaddress");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartySubaddr", "OddEvenIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<OddEvenIndicator> ACCESS=<Data->OddEvenIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->OddEvenIndicator)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "even number of address signals"); break;
				case 1: OStream->WriteString (OStream, "odd number of address signals"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CalledPartySubaddr", "OddEvenIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartySubaddr", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_CalledPartySubaddr_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "CalledPartySubaddr", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartySubaddr", "SubaddressInformation");
	  /* NAME=<SubaddressInformation> ACCESS=<Data->SubaddressInformation>  MAXBITSIZE=<160> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->SubaddressInformation.value, Data->SubaddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "CalledPartySubaddr", "SubaddressInformation");
	ED_Dump_Struct_End (OStream, "CalledPartySubaddr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CallingPartySubaddr (TEDOStream* OStream, const c_CallingPartySubaddr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CallingPartySubaddr");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartySubaddr", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_CallingPartySubaddr_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "CallingPartySubaddr", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartySubaddr", "TypeOfSubaddress");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfSubaddress> ACCESS=<Data->TypeOfSubaddress>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfSubaddress)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "NSAP (X.213/ISO 8348 AD2)"); break;
				case 2: OStream->WriteString (OStream, "User specified"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallingPartySubaddr", "TypeOfSubaddress");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartySubaddr", "OddEvenIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<OddEvenIndicator> ACCESS=<Data->OddEvenIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->OddEvenIndicator)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "even number of address signals"); break;
				case 1: OStream->WriteString (OStream, "odd number of address signals"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallingPartySubaddr", "OddEvenIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartySubaddr", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_CallingPartySubaddr_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "CallingPartySubaddr", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartySubaddr", "SubaddressInformation");
	  /* NAME=<SubaddressInformation> ACCESS=<Data->SubaddressInformation>  MAXBITSIZE=<160> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->SubaddressInformation.value, Data->SubaddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "CallingPartySubaddr", "SubaddressInformation");
	ED_Dump_Struct_End (OStream, "CallingPartySubaddr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_BearerCpblty (TEDOStream* OStream, const c_BearerCpblty* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "BearerCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "RadioChannelRequirement");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioChannelRequirement> ACCESS=<Data->RadioChannelRequirement>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RadioChannelRequirement)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "reserved"); break;
				case 1: OStream->WriteString (OStream, "full rate support only MS"); break;
				case 2: OStream->WriteString (OStream, "dual rate support MS/half rate preferred"); break;
				case 3: OStream->WriteString (OStream, "dual rate support MS/full rate preferred"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "RadioChannelRequirement");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "CodingStd");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CodingStd> ACCESS=<Data->CodingStd>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CodingStd)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM standardized coding as described below"); break;
				case 1: OStream->WriteString (OStream, "reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "CodingStd");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TransferMode");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TransferMode> ACCESS=<Data->TransferMode>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->TransferMode)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "circuit mode"); break;
				case 1: OStream->WriteString (OStream, "packet mode"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TransferMode");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "InformationTransferCapability");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<InformationTransferCapability> ACCESS=<Data->InformationTransferCapability>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->InformationTransferCapability)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "speech"); break;
				case 1: OStream->WriteString (OStream, "unrestricted digital information"); break;
				case 2: OStream->WriteString (OStream, "3.1 kHz audio, ex PLMN"); break;
				case 3: OStream->WriteString (OStream, "facsimile group 3"); break;
				case 5: OStream->WriteString (OStream, "Other ITC (See Octet 5a)"); break;
				case 7: OStream->WriteString (OStream, "reserved, to be used in the network."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "InformationTransferCapability");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Coding1");
	if (!Data->Coding1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Coding1> ACCESS=<Data->Coding1>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Coding1)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "octet used for extension of information transfer capability"); break;
				case 1: OStream->WriteString (OStream, "octet used for other extension of octet 3"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Coding1");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "CTM");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CTM> ACCESS=<Data->CTM>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CTM)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "CTM text telephony is not supported"); break;
				case 1: OStream->WriteString (OStream, "CTM text telephony is supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "CTM");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare3a");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare3a> NAME=<spare3a> ACCESS=<Data->spare3a>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare3a");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "SpeechVersionIndicator1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpeechVersionIndicator1> ACCESS=<Data->SpeechVersionIndicator1>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SpeechVersionIndicator1)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM full rate speech version 1"); break;
				case 1: OStream->WriteString (OStream, "GSM half rate speech version 1"); break;
				case 2: OStream->WriteString (OStream, "GSM full rate speech version 2"); break;
				case 4: OStream->WriteString (OStream, "GSM full rate speech version 3"); break;
				case 5: OStream->WriteString (OStream, "GSM half rate speech version 3"); break;
				case 6: OStream->WriteString (OStream, "GSM full rate speech version 4"); break;
				case 7: OStream->WriteString (OStream, "GSM half rate speech version 4"); break;
				case 8: OStream->WriteString (OStream, "GSM full rate speech version 5"); break;
				case 11: OStream->WriteString (OStream, "GSM half rate speech version 6"); break;
				case 15: OStream->WriteString (OStream, "no speech version supported for GERAN"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "SpeechVersionIndicator1");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Coding2");
	if (!Data->Coding2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Coding2> ACCESS=<Data->Coding2>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Coding2)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "octet used for extension of information transfer capability"); break;
				case 1: OStream->WriteString (OStream, "octet used for other extension of octet 3"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Coding2");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare3b");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare3b> NAME=<spare3b> ACCESS=<Data->spare3b>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare3b");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "SpeechVersionIndicator2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpeechVersionIndicator2> ACCESS=<Data->SpeechVersionIndicator2>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SpeechVersionIndicator2)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM full rate speech version 1"); break;
				case 1: OStream->WriteString (OStream, "GSM half rate speech version 1"); break;
				case 2: OStream->WriteString (OStream, "GSM full rate speech version 2"); break;
				case 4: OStream->WriteString (OStream, "GSM full rate speech version 3"); break;
				case 5: OStream->WriteString (OStream, "GSM half rate speech version 3"); break;
				case 6: OStream->WriteString (OStream, "GSM full rate speech version 4"); break;
				case 7: OStream->WriteString (OStream, "GSM half rate speech version 4"); break;
				case 8: OStream->WriteString (OStream, "GSM full rate speech version 5"); break;
				case 11: OStream->WriteString (OStream, "GSM half rate speech version 6"); break;
				case 15: OStream->WriteString (OStream, "no speech version supported for GERAN"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "SpeechVersionIndicator2");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Coding3");
	if (!Data->Coding3_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Coding3> ACCESS=<Data->Coding3>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Coding3)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "octet used for extension of information transfer capability"); break;
				case 1: OStream->WriteString (OStream, "octet used for other extension of octet 3"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Coding3");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare3c");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare3c> NAME=<spare3c> ACCESS=<Data->spare3c>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare3c");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "SpeechVersionIndicator3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpeechVersionIndicator3> ACCESS=<Data->SpeechVersionIndicator3>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SpeechVersionIndicator3)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM full rate speech version 1"); break;
				case 1: OStream->WriteString (OStream, "GSM half rate speech version 1"); break;
				case 2: OStream->WriteString (OStream, "GSM full rate speech version 2"); break;
				case 4: OStream->WriteString (OStream, "GSM full rate speech version 3"); break;
				case 5: OStream->WriteString (OStream, "GSM half rate speech version 3"); break;
				case 6: OStream->WriteString (OStream, "GSM full rate speech version 4"); break;
				case 7: OStream->WriteString (OStream, "GSM half rate speech version 4"); break;
				case 8: OStream->WriteString (OStream, "GSM full rate speech version 5"); break;
				case 11: OStream->WriteString (OStream, "GSM half rate speech version 6"); break;
				case 15: OStream->WriteString (OStream, "no speech version supported for GERAN"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "SpeechVersionIndicator3");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Coding4");
	if (!Data->Coding4_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Coding4> ACCESS=<Data->Coding4>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Coding4)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "octet used for extension of information transfer capability"); break;
				case 1: OStream->WriteString (OStream, "octet used for other extension of octet 3"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Coding4");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare3d");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare3d> NAME=<spare3d> ACCESS=<Data->spare3d>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare3d");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "SpeechVersionIndicator4");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpeechVersionIndicator4> ACCESS=<Data->SpeechVersionIndicator4>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SpeechVersionIndicator4)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM full rate speech version 1"); break;
				case 1: OStream->WriteString (OStream, "GSM half rate speech version 1"); break;
				case 2: OStream->WriteString (OStream, "GSM full rate speech version 2"); break;
				case 4: OStream->WriteString (OStream, "GSM full rate speech version 3"); break;
				case 5: OStream->WriteString (OStream, "GSM half rate speech version 3"); break;
				case 6: OStream->WriteString (OStream, "GSM full rate speech version 4"); break;
				case 7: OStream->WriteString (OStream, "GSM half rate speech version 4"); break;
				case 8: OStream->WriteString (OStream, "GSM full rate speech version 5"); break;
				case 11: OStream->WriteString (OStream, "GSM half rate speech version 6"); break;
				case 15: OStream->WriteString (OStream, "no speech version supported for GERAN"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "SpeechVersionIndicator4");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Compress");
	if (!Data->Compress_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Compress> ACCESS=<Data->Compress>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Compress)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "data compression not possible"); break;
				case 1: OStream->WriteString (OStream, "data compression possible"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Compress");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Structure");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Structure> ACCESS=<Data->Structure>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Structure)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "service data unit integrity"); break;
				case 3: OStream->WriteString (OStream, "unstructured"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Structure");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "DuplMode");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DuplMode> ACCESS=<Data->DuplMode>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->DuplMode)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "half duplex"); break;
				case 1: OStream->WriteString (OStream, "full duplex"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "DuplMode");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Configuration");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Configuration> ACCESS=<Data->Configuration>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Configuration)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "point-to-point"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Configuration");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "NIRR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NIRR> ACCESS=<Data->NIRR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NIRR)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No meaning is associated with this value."); break;
				case 1: OStream->WriteString (OStream, "Data up to and including 4.8 kb/s, full rate, non-transparent, 6 kb/s radio interface rate is requested."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "NIRR");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Establishment");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Establishment> ACCESS=<Data->Establishment>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Establishment)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "demand"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Establishment");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "AccessId");
	if (!Data->AccessId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AccessId> ACCESS=<Data->AccessId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->AccessId);
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "AccessId");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "RateAdaption");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RateAdaption> ACCESS=<Data->RateAdaption>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RateAdaption)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no rate adaption"); break;
				case 1: OStream->WriteString (OStream, "V.110, I.460/X.30 rate adaptation"); break;
				case 2: OStream->WriteString (OStream, "ITU-T X.31 flag stuffing"); break;
				case 3: OStream->WriteString (OStream, "Other rate adaption"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "RateAdaption");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "SignallingAccessProtocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SignallingAccessProtocol> ACCESS=<Data->SignallingAccessProtocol>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SignallingAccessProtocol)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "I.440/450"); break;
				case 2: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 3: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 4: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 5: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 6: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "SignallingAccessProtocol");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "OtherITC");
	if (!Data->OtherITC_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OtherITC> ACCESS=<Data->OtherITC>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->OtherITC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "restricted digital information"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "OtherITC");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "OtherRateAdaption");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OtherRateAdaption> ACCESS=<Data->OtherRateAdaption>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->OtherRateAdaption)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "V.120"); break;
				case 1: OStream->WriteString (OStream, "H.223 & H.245"); break;
				case 2: OStream->WriteString (OStream, "PIAFS"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "OtherRateAdaption");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare5a");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare5a> NAME=<spare5a> ACCESS=<Data->spare5a>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare5a");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "HDR");
	if (!Data->HDR_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<HDR> ACCESS=<Data->HDR>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->HDR)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Rate adaption header not included"); break;
				case 1: OStream->WriteString (OStream, "Rate adaption header included"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "HDR");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "MultiFrame");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MultiFrame> ACCESS=<Data->MultiFrame>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->MultiFrame)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Multiple frame establishment not supported, only UI frames allowed"); break;
				case 1: OStream->WriteString (OStream, "Multiple frame establishment supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "MultiFrame");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Mode");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Mode> ACCESS=<Data->Mode>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Mode)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Bit transparent mode of operation"); break;
				case 1: OStream->WriteString (OStream, "Protocol sensitive mode of operation"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Mode");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "LLI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LLI> ACCESS=<Data->LLI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->LLI)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Default, LLI=256 only"); break;
				case 1: OStream->WriteString (OStream, "Full protocol negotiation, (note: A connection over which protocol negotiation will be executed is indicated in bit 2 of octet 5b)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "LLI");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "AssigNorE");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<AssigNorE> ACCESS=<Data->AssigNorE>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->AssigNorE)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Message originator is 'default assignee'"); break;
				case 1: OStream->WriteString (OStream, "Message originator is 'assignor only'"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "AssigNorE");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "IbmNeg");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<IbmNeg> ACCESS=<Data->IbmNeg>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->IbmNeg)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Negotiation is done in-band using logical link zero"); break;
				case 1: OStream->WriteString (OStream, "Negotiation is done with USER INFORMATION messages on a temporary signalling connection"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "IbmNeg");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare5b");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare5b> NAME=<spare5b> ACCESS=<Data->spare5b>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare5b");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Layer1ID");
	if (!Data->Layer1ID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Layer1ID> ACCESS=<Data->Layer1ID>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Layer1ID);
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Layer1ID");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "UserInfoLayer1Protocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UserInfoLayer1Protocol> ACCESS=<Data->UserInfoLayer1Protocol>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->UserInfoLayer1Protocol);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "UserInfoLayer1Protocol");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "ASync");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ASync> ACCESS=<Data->ASync>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->ASync)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "synchronous"); break;
				case 1: OStream->WriteString (OStream, "asynchronous"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "ASync");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "NumbStopBits");
	if (!Data->NumbStopBits_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumbStopBits> ACCESS=<Data->NumbStopBits>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NumbStopBits)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "2 bits"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "NumbStopBits");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Negotiation");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Negotiation> ACCESS=<Data->Negotiation>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Negotiation)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "in-band negotiation not possible"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Negotiation");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "NumbDataBits");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NumbDataBits> ACCESS=<Data->NumbDataBits>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NumbDataBits)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "7 bits"); break;
				case 1: OStream->WriteString (OStream, "8 bits (this value is also used in the case of bit oriented protocols)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "NumbDataBits");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "UserRate");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UserRate> ACCESS=<Data->UserRate>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UserRate)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, ".3 kbit/s Recommendation X.1 and V.110"); break;
				case 3: OStream->WriteString (OStream, "2.4 kbit/s Recommendation X.1 and V.110"); break;
				case 4: OStream->WriteString (OStream, "4.8 kbit/s Recommendation X.1 and V.110"); break;
				case 5: OStream->WriteString (OStream, "9.6 kbit/s Recommendation X.1 and V.110"); break;
				case 7: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol."); break;
				case 13: OStream->WriteString (OStream, "2.0 kbit/s transparent (non compliance with X.1 and V.110)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "UserRate");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "IntermediateRate");
	if (!Data->IntermediateRate_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IntermediateRate> ACCESS=<Data->IntermediateRate>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->IntermediateRate)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "reserved"); break;
				case 1: OStream->WriteString (OStream, "reserved"); break;
				case 2: OStream->WriteString (OStream, "8 kbit/s"); break;
				case 7: OStream->WriteString (OStream, "6 kbit/s"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "IntermediateRate");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "NICOnTX");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NICOnTX> ACCESS=<Data->NICOnTX>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NICOnTX)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "does not require to send data with network independent clock"); break;
				case 1: OStream->WriteString (OStream, "requires to send data with network independent clock"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "NICOnTX");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "NICOnRX");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NICOnRX> ACCESS=<Data->NICOnRX>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NICOnRX)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "cannot accept data with network independent clock (i.e. sender does not support this optional procedure)"); break;
				case 1: OStream->WriteString (OStream, "can accept data with network independent clock (i.e. sender does support this optional procedure)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "NICOnRX");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Parity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Parity> ACCESS=<Data->Parity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Parity)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "odd"); break;
				case 2: OStream->WriteString (OStream, "even"); break;
				case 3: OStream->WriteString (OStream, "none"); break;
				case 4: OStream->WriteString (OStream, "forced to 0"); break;
				case 5: OStream->WriteString (OStream, "forced to 1"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Parity");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "ConnectionElement");
	if (!Data->ConnectionElement_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ConnectionElement> ACCESS=<Data->ConnectionElement>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ConnectionElement)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "transparent"); break;
				case 1: OStream->WriteString (OStream, "non transparent (RLP)"); break;
				case 2: OStream->WriteString (OStream, "both, transparent preferred"); break;
				case 3: OStream->WriteString (OStream, "both, non transparent preferred"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "ConnectionElement");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "ModemType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ModemType> ACCESS=<Data->ModemType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ModemType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "none"); break;
				case 1: OStream->WriteString (OStream, "V.21 (note 1)"); break;
				case 2: OStream->WriteString (OStream, "V.22 (note 1)"); break;
				case 3: OStream->WriteString (OStream, "V.22 bis (note 1)"); break;
				case 4: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 5: OStream->WriteString (OStream, "V.26 ter (note 1)"); break;
				case 6: OStream->WriteString (OStream, "V.32"); break;
				case 7: OStream->WriteString (OStream, "modem for undefined interface"); break;
				case 8: OStream->WriteString (OStream, "autobauding type 1"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "ModemType");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "OtherModemType");
	if (!Data->OtherModemType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OtherModemType> ACCESS=<Data->OtherModemType>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->OtherModemType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no other modem type specified in this field"); break;
				case 2: OStream->WriteString (OStream, "V.34"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "OtherModemType");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "FixedNetworkUserRate");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<FixedNetworkUserRate> ACCESS=<Data->FixedNetworkUserRate>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->FixedNetworkUserRate)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Fixed network user rate not applicable/No meaning is associated with this value."); break;
				case 1: OStream->WriteString (OStream, "9.6 kbit/s Recommendation X.1 and V.110"); break;
				case 2: OStream->WriteString (OStream, "14.4 kbit/s Recommendation X.1 and V.110"); break;
				case 3: OStream->WriteString (OStream, "19.2 kbit/s Recommendation X.1 and V.110"); break;
				case 4: OStream->WriteString (OStream, "28.8 kbit/s Recommendation X.1 and V.110"); break;
				case 5: OStream->WriteString (OStream, "38.4 kbit/s Recommendation X.1 and V.110"); break;
				case 6: OStream->WriteString (OStream, "48.0 kbit/s Recommendation X.1 and V.110(synch) (note 1)"); break;
				case 7: OStream->WriteString (OStream, "56.0 kbit/s Recommendation X.1 and V.110(synch) /bit transparent"); break;
				case 8: OStream->WriteString (OStream, "64.0 kbit/s bit transparent"); break;
				case 9: OStream->WriteString (OStream, "33.6 kbit/s bit transparent (note 2)"); break;
				case 10: OStream->WriteString (OStream, "32.0 kbit/s Recommendation I.460"); break;
				case 11: OStream->WriteString (OStream, "31.2 kbit/s Recommendation V.34 (note 2)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "FixedNetworkUserRate");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TCH_F14_4_acceptable");
	if (!Data->TCH_F14_4_acceptable_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TCH_F14_4_acceptable> ACCESS=<Data->TCH_F14_4_acceptable>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TCH_F14_4_acceptable);
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TCH_F14_4_acceptable");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare6e");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare6e> NAME=<spare6e> ACCESS=<Data->spare6e>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare6e");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TCH_F9_6_acceptable");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TCH_F9_6_acceptable> ACCESS=<Data->TCH_F9_6_acceptable>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TCH_F9_6_acceptable);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TCH_F9_6_acceptable");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TCH_F4_8_acceptable");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TCH_F4_8_acceptable> ACCESS=<Data->TCH_F4_8_acceptable>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TCH_F4_8_acceptable);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TCH_F4_8_acceptable");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "MaxNumberOfTrafficChannels");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaxNumberOfTrafficChannels> ACCESS=<Data->MaxNumberOfTrafficChannels>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MaxNumberOfTrafficChannels)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "1 TCH"); break;
				case 1: OStream->WriteString (OStream, "2 TCH"); break;
				case 2: OStream->WriteString (OStream, "3 TCH"); break;
				case 3: OStream->WriteString (OStream, "4 TCH"); break;
				case 4: OStream->WriteString (OStream, "5 TCH"); break;
				case 5: OStream->WriteString (OStream, "6 TCH"); break;
				case 6: OStream->WriteString (OStream, "7 TCH"); break;
				case 7: OStream->WriteString (OStream, "8 TCH"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "MaxNumberOfTrafficChannels");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "UIMI");
	if (!Data->UIMI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UIMI> ACCESS=<Data->UIMI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UIMI)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "User initiated modification not allowed/required/applicable"); break;
				case 1: OStream->WriteString (OStream, "User initiated modification up to 1 TCH/F allowed/may be requested"); break;
				case 2: OStream->WriteString (OStream, "User initiated modification up to 2 TCH/F allowed/may be requested"); break;
				case 3: OStream->WriteString (OStream, "User initiated modification up to 3 TCH/F allowed/may be requested"); break;
				case 4: OStream->WriteString (OStream, "User initiated modification up to 4 TCH/F allowed/may be requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "UIMI");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "WantedAirInterfaceUserRate");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<WantedAirInterfaceUserRate> ACCESS=<Data->WantedAirInterfaceUserRate>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->WantedAirInterfaceUserRate)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Air interface user rate not applicable/No meaning associated with this value"); break;
				case 1: OStream->WriteString (OStream, "9.6 kbit/s"); break;
				case 2: OStream->WriteString (OStream, "14.4 kbit/s"); break;
				case 3: OStream->WriteString (OStream, "19.2 kbit/s"); break;
				case 5: OStream->WriteString (OStream, "28.8 kbit/s"); break;
				case 6: OStream->WriteString (OStream, "38.4 kbit/s"); break;
				case 7: OStream->WriteString (OStream, "43.2 kbit/s"); break;
				case 8: OStream->WriteString (OStream, "57.6 kbit/s"); break;
				case 9: OStream->WriteString (OStream, "interpreted by the network as 38.4 kbit/s in this version of the protocol"); break;
				case 10: OStream->WriteString (OStream, "interpreted by the network as 38.4 kbit/s in this version of the protocol"); break;
				case 11: OStream->WriteString (OStream, "interpreted by the network as 38.4 kbit/s in this version of the protocol"); break;
				case 12: OStream->WriteString (OStream, "interpreted by the network as 38.4 kbit/s in this version of the protocol"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "WantedAirInterfaceUserRate");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TCH_F28_8_acceptable");
	if (!Data->TCH_F28_8_acceptable_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TCH_F28_8_acceptable> ACCESS=<Data->TCH_F28_8_acceptable>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TCH_F28_8_acceptable);
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TCH_F28_8_acceptable");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TCH_F32_0_acceptable");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TCH_F32_0_acceptable> ACCESS=<Data->TCH_F32_0_acceptable>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TCH_F32_0_acceptable);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TCH_F32_0_acceptable");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "TCH_F43_2_acceptable");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TCH_F43_2_acceptable> ACCESS=<Data->TCH_F43_2_acceptable>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TCH_F43_2_acceptable);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "TCH_F43_2_acceptable");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "AsymmetryIndication");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AsymmetryIndication> ACCESS=<Data->AsymmetryIndication>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->AsymmetryIndication)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Channel coding symmetry preferred"); break;
				case 1: OStream->WriteString (OStream, "Uplink biased channel coding asymmetry is preferred"); break;
				case 2: OStream->WriteString (OStream, "Downlink biased channel coding asymmetry is preferred"); break;
				case 3: OStream->WriteString (OStream, "Unused, if received it shall be interpreted as 'Channel coding symmetry preferred'"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "AsymmetryIndication");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "spare6g");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_spare6g> NAME=<spare6g> ACCESS=<Data->spare6g>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "spare6g");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "Layer2ID");
	if (!Data->Layer2ID_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty_Layer2ID> NAME=<Layer2ID> ACCESS=<Data->Layer2ID>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "Layer2ID");
	ED_Dump_Struct_Begin_Field (OStream, "BearerCpblty", "UserInfoLayer2Protocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UserInfoLayer2Protocol> ACCESS=<Data->UserInfoLayer2Protocol>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UserInfoLayer2Protocol)
		{
			switch (DATA) {
				case 6: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 8: OStream->WriteString (OStream, "ISO 6429, codeset 0 (DC1/DC3)"); break;
				case 9: OStream->WriteString (OStream, "reserved: was allocated but never used in earlier phases of the protocol"); break;
				case 10: OStream->WriteString (OStream, "videotex profile 1"); break;
				case 12: OStream->WriteString (OStream, "COPnoFlCt (Character oriented Protocol with no Flow Control mechanism)"); break;
				case 13: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BearerCpblty", "UserInfoLayer2Protocol");
	ED_Dump_Struct_End (OStream, "BearerCpblty");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CalledPartyBcdNum (TEDOStream* OStream, const c_CalledPartyBcdNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CalledPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartyBcdNum", "TypeOfNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfNumber> ACCESS=<Data->TypeOfNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfNumber)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "unknown"); break;
				case 1: OStream->WriteString (OStream, "international number"); break;
				case 2: OStream->WriteString (OStream, "national number"); break;
				case 3: OStream->WriteString (OStream, "network specific number"); break;
				case 4: OStream->WriteString (OStream, "dedicated access, short code"); break;
				case 5: OStream->WriteString (OStream, "reserved"); break;
				case 6: OStream->WriteString (OStream, "reserved"); break;
				case 7: OStream->WriteString (OStream, "reserved for extension"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CalledPartyBcdNum", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartyBcdNum", "NumberingPlanIdent");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumberingPlanIdent> ACCESS=<Data->NumberingPlanIdent>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NumberingPlanIdent)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "unknown"); break;
				case 1: OStream->WriteString (OStream, "ISDN/telephony numbering plan (Rec. E.164/E.163)"); break;
				case 3: OStream->WriteString (OStream, "data numbering plan (Recommendation X.121)"); break;
				case 4: OStream->WriteString (OStream, "telex numbering plan (Recommendation F.69)"); break;
				case 8: OStream->WriteString (OStream, "national numbering plan"); break;
				case 9: OStream->WriteString (OStream, "private numbering plan"); break;
				case 11: OStream->WriteString (OStream, "reserved for CTS (see 3GPP TS 44.056 [91])"); break;
				case 15: OStream->WriteString (OStream, "reserved for extension"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CalledPartyBcdNum", "NumberingPlanIdent");
	ED_Dump_Struct_Begin_Field (OStream, "CalledPartyBcdNum", "Number");
	  /* STRUCTURAL=<0> TYPE=<c_TBCDArray> NAME=<Number> ACCESS=<Data->Number>  OPTIONAL=<0> FUNC=<Dump_c_TBCDArray> */
	  Dump_c_TBCDArray (OStream, &(Data->Number));
	ED_Dump_Struct_End_Field (OStream, "CalledPartyBcdNum", "Number");
	ED_Dump_Struct_End (OStream, "CalledPartyBcdNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_HighLayerCpbility (TEDOStream* OStream, const c_HighLayerCpbility* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "HighLayerCpbility");
	ED_Dump_Struct_Begin_Field (OStream, "HighLayerCpbility", "CodingStandard");
	if (!Data->CodingStandard_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CodingStandard> ACCESS=<Data->CodingStandard>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CodingStandard);
	}
	ED_Dump_Struct_End_Field (OStream, "HighLayerCpbility", "CodingStandard");
	ED_Dump_Struct_Begin_Field (OStream, "HighLayerCpbility", "Interpretation");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Interpretation> ACCESS=<Data->Interpretation>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Interpretation);
	ED_Dump_Struct_End_Field (OStream, "HighLayerCpbility", "Interpretation");
	ED_Dump_Struct_Begin_Field (OStream, "HighLayerCpbility", "PresentationMethod");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PresentationMethod> ACCESS=<Data->PresentationMethod>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->PresentationMethod);
	ED_Dump_Struct_End_Field (OStream, "HighLayerCpbility", "PresentationMethod");
	ED_Dump_Struct_Begin_Field (OStream, "HighLayerCpbility", "HighLayerCharacteristicsId");
	if (!Data->HighLayerCharacteristicsId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HighLayerCharacteristicsId> ACCESS=<Data->HighLayerCharacteristicsId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->HighLayerCharacteristicsId);
	}
	ED_Dump_Struct_End_Field (OStream, "HighLayerCpbility", "HighLayerCharacteristicsId");
	ED_Dump_Struct_Begin_Field (OStream, "HighLayerCpbility", "ExtHighLayerCharacteristicsId");
	if (!Data->ExtHighLayerCharacteristicsId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ExtHighLayerCharacteristicsId> ACCESS=<Data->ExtHighLayerCharacteristicsId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ExtHighLayerCharacteristicsId);
	}
	ED_Dump_Struct_End_Field (OStream, "HighLayerCpbility", "ExtHighLayerCharacteristicsId");
	ED_Dump_Struct_End (OStream, "HighLayerCpbility");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SupportedCodecList (TEDOStream* OStream, const c_SupportedCodecList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<6> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_SupportedCodec> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_SupportedCodec> */
	  Dump_c_SupportedCodec (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LocationAreaId (TEDOStream* OStream, const c_LocationAreaId* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "LocationAreaId", "LAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<LAC> ACCESS=<Data->LAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LAC);
	ED_Dump_Struct_End_Field (OStream, "LocationAreaId", "LAC");
	ED_Dump_Struct_End (OStream, "LocationAreaId");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MobileStationClassmark1 (TEDOStream* OStream, const c_MobileStationClassmark1* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MobileStationClassmark1");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark1", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark1_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark1", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark1", "RevisionLevel");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RevisionLevel> ACCESS=<Data->RevisionLevel>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RevisionLevel)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Reserved for GSM phase 1"); break;
				case 1: OStream->WriteString (OStream, "Used by GSM phase 2 mobile stations"); break;
				case 2: OStream->WriteString (OStream, "Used by mobile stations supporting R99 or later versions of the protocol"); break;
				case 3: OStream->WriteString (OStream, "Reserved for future use. If the network receives a revision level specified as 'reserved for future use', then it shall use the highest revision level supported by the network."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark1", "RevisionLevel");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark1", "EsInd");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EsInd> ACCESS=<Data->EsInd>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->EsInd)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "'Controlled Early Classmark Sending' option is not implemented in the MS"); break;
				case 1: OStream->WriteString (OStream, "'Controlled Early Classmark Sending' option is implemented in the MS"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark1", "EsInd");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark1", "A5_1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_1> ACCESS=<Data->A5_1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->A5_1)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "encryption algorithm A5/1 available"); break;
				case 1: OStream->WriteString (OStream, "encryption algorithm A5/1 not available"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark1", "A5_1");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark1", "RfPowerCapability");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RfPowerCapability> ACCESS=<Data->RfPowerCapability>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RfPowerCapability)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "class 1"); break;
				case 1: OStream->WriteString (OStream, "class 2"); break;
				case 2: OStream->WriteString (OStream, "class 3"); break;
				case 3: OStream->WriteString (OStream, "class 4"); break;
				case 4: OStream->WriteString (OStream, "class 5"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark1", "RfPowerCapability");
	ED_Dump_Struct_End (OStream, "MobileStationClassmark1");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MobileStationClassmark2 (TEDOStream* OStream, const c_MobileStationClassmark2* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MobileStationClassmark2");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "spare1");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2_spare1> NAME=<spare1> ACCESS=<Data->spare1>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "spare1");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "RevisionLevel");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RevisionLevel> ACCESS=<Data->RevisionLevel>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RevisionLevel)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Reserved for GSM phase 1"); break;
				case 1: OStream->WriteString (OStream, "Used by GSM phase 2 mobile stations"); break;
				case 2: OStream->WriteString (OStream, "Used by mobile stations supporting R99 or later versions of the protocol"); break;
				case 3: OStream->WriteString (OStream, "Reserved for future use. If the network receives a revision level specified as 'reserved for future use', then it shall use the highest revision level supported by the network."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "RevisionLevel");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "EsInd");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EsInd> ACCESS=<Data->EsInd>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->EsInd)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Controlled Early Classmark Sending option is not implemented in the MS"); break;
				case 1: OStream->WriteString (OStream, "Controlled Early Classmark Sending option is implemented in the MS"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "EsInd");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "A5_1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_1> ACCESS=<Data->A5_1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->A5_1)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "encryption algorithm A5/1 available"); break;
				case 1: OStream->WriteString (OStream, "encryption algorithm A5/1 not available"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "A5_1");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "RFPowerCapability");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RFPowerCapability> ACCESS=<Data->RFPowerCapability>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RFPowerCapability)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "class 1"); break;
				case 1: OStream->WriteString (OStream, "class 2"); break;
				case 2: OStream->WriteString (OStream, "class 3"); break;
				case 3: OStream->WriteString (OStream, "class 4"); break;
				case 4: OStream->WriteString (OStream, "class 5"); break;
				case 7: OStream->WriteString (OStream, "RF Power capability is irrelevant in this information element"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "RFPowerCapability");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "spare2");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2_spare2> NAME=<spare2> ACCESS=<Data->spare2>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "spare2");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "PSCapability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PSCapability> ACCESS=<Data->PSCapability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->PSCapability)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "PS capability not present"); break;
				case 1: OStream->WriteString (OStream, "PS capability present"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "PSCapability");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "SSScreenIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SSScreenIndicator> ACCESS=<Data->SSScreenIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SSScreenIndicator);
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "SSScreenIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "SMCapability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SMCapability> ACCESS=<Data->SMCapability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->SMCapability)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Mobile station does not support mobile terminated point to point SMS"); break;
				case 1: OStream->WriteString (OStream, "Mobile station supports mobile terminated point to point SMS"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "SMCapability");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "VBS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VBS> ACCESS=<Data->VBS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->VBS)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no VBS capability or no notifications wanted"); break;
				case 1: OStream->WriteString (OStream, "VBS capability and notifications wanted"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "VBS");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "VGCS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VGCS> ACCESS=<Data->VGCS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->VGCS)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no VGCS capability or no notifications wanted"); break;
				case 1: OStream->WriteString (OStream, "VGCS capability and notifications wanted"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "VGCS");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "FC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FC> ACCESS=<Data->FC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->FC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "The MS does not support the E-GSM or R-GSM band (For definition of frequency bands see 3GPP TS 45.005 [33])"); break;
				case 1: OStream->WriteString (OStream, "The MS does support the E-GSM or R-GSM (For definition of frequency bands see 3GPP TS 45.005 [33])"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "FC");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "CM3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CM3> ACCESS=<Data->CM3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CM3)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "The MS does not support any options that are indicated in CM3"); break;
				case 1: OStream->WriteString (OStream, "The MS supports options that are indicated in classmark 3 IE"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "CM3");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "spare3");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2_spare3> NAME=<spare3> ACCESS=<Data->spare3>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "spare3");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "LCSVA_CAP");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LCSVA_CAP> ACCESS=<Data->LCSVA_CAP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->LCSVA_CAP)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "location request notification via CS domain not supported"); break;
				case 1: OStream->WriteString (OStream, "location request notification via CS domain supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "LCSVA_CAP");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "UCS2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UCS2> ACCESS=<Data->UCS2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->UCS2)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "the ME has a preference for the default alphabet (defined in 3GPP TS 23.038 [8b]) over UCS2."); break;
				case 1: OStream->WriteString (OStream, "the ME has no preference between the use of the default alphabet and the use of UCS2."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "UCS2");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "SoLSA");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SoLSA> ACCESS=<Data->SoLSA>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->SoLSA)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "The ME does not support SoLSA."); break;
				case 1: OStream->WriteString (OStream, "The ME supports SoLSA."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "SoLSA");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "CMSP");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CMSP> ACCESS=<Data->CMSP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CMSP)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Network initiated MO CM connection request not supported."); break;
				case 1: OStream->WriteString (OStream, "Network initiated MO CM connection request supported for at least one CM protocol."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "CMSP");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "A5_3");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_3> ACCESS=<Data->A5_3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->A5_3)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "encryption algorithm A5/3 not available"); break;
				case 1: OStream->WriteString (OStream, "encryption algorithm A5/3 available"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "A5_3");
	ED_Dump_Struct_Begin_Field (OStream, "MobileStationClassmark2", "A5_2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_2> ACCESS=<Data->A5_2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->A5_2)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "encryption algorithm A5/2 not available"); break;
				case 1: OStream->WriteString (OStream, "Not used. This value was allocated in earlier versions of the protocol."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "MobileStationClassmark2", "A5_2");
	ED_Dump_Struct_End (OStream, "MobileStationClassmark2");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PdAndSapiCcbs (TEDOStream* OStream, const c_PdAndSapiCcbs* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PdAndSapiCcbs");
	ED_Dump_Struct_Begin_Field (OStream, "PdAndSapiCcbs", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PdAndSapiCcbs_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PdAndSapiCcbs", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PdAndSapiCcbs", "SAPI");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SAPI> ACCESS=<Data->SAPI>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SAPI);
	ED_Dump_Struct_End_Field (OStream, "PdAndSapiCcbs", "SAPI");
	ED_Dump_Struct_Begin_Field (OStream, "PdAndSapiCcbs", "PD");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PD> ACCESS=<Data->PD>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->PD);
	ED_Dump_Struct_End_Field (OStream, "PdAndSapiCcbs", "PD");
	ED_Dump_Struct_End (OStream, "PdAndSapiCcbs");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PriorityLevel (TEDOStream* OStream, const c_PriorityLevel* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PriorityLevel");
	ED_Dump_Struct_Begin_Field (OStream, "PriorityLevel", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PriorityLevel_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PriorityLevel", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PriorityLevel", "CallPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CallPriority> ACCESS=<Data->CallPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CallPriority)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no priority applied"); break;
				case 1: OStream->WriteString (OStream, "call priority level 4"); break;
				case 2: OStream->WriteString (OStream, "call priority level 3"); break;
				case 3: OStream->WriteString (OStream, "call priority level 2"); break;
				case 4: OStream->WriteString (OStream, "call priority level 1"); break;
				case 5: OStream->WriteString (OStream, "call priority level 0"); break;
				case 6: OStream->WriteString (OStream, "call priority level B"); break;
				case 7: OStream->WriteString (OStream, "call priority level A"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PriorityLevel", "CallPriority");
	ED_Dump_Struct_End (OStream, "PriorityLevel");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MSNetworkFeatureSupport (TEDOStream* OStream, const c_MSNetworkFeatureSupport* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "MSNetworkFeatureSupport", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_MSNetworkFeatureSupport_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "MSNetworkFeatureSupport", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "MSNetworkFeatureSupport", "ExtendedPeriodicTimers");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ExtendedPeriodicTimers> ACCESS=<Data->ExtendedPeriodicTimers>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ExtendedPeriodicTimers);
	ED_Dump_Struct_End_Field (OStream, "MSNetworkFeatureSupport", "ExtendedPeriodicTimers");
	ED_Dump_Struct_End (OStream, "MSNetworkFeatureSupport");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LocationUpdatingType (TEDOStream* OStream, const c_LocationUpdatingType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LocationUpdatingType");
	ED_Dump_Struct_Begin_Field (OStream, "LocationUpdatingType", "xFOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<xFOR> ACCESS=<Data->xFOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->xFOR)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No follow-on request pending"); break;
				case 1: OStream->WriteString (OStream, "Follow-on request pending"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "LocationUpdatingType", "xFOR");
	ED_Dump_Struct_Begin_Field (OStream, "LocationUpdatingType", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_LocationUpdatingType_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "LocationUpdatingType", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "LocationUpdatingType", "LUT");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LUT> ACCESS=<Data->LUT>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->LUT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Normal location updating"); break;
				case 1: OStream->WriteString (OStream, "Periodic updating"); break;
				case 2: OStream->WriteString (OStream, "IMSI attach"); break;
				case 3: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "LocationUpdatingType", "LUT");
	ED_Dump_Struct_End (OStream, "LocationUpdatingType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NetwkName (TEDOStream* OStream, const c_NetwkName* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NetwkName");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkName", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_NetwkName_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NetwkName", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkName", "CodingScheme");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CodingScheme> ACCESS=<Data->CodingScheme>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CodingScheme)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Cell Broadcast data coding scheme, GSM default alphabet, language unspecified, defined in 3GPP TS 23.038 [8b]"); break;
				case 1: OStream->WriteString (OStream, "UCS2 (16 bit) [72]"); break;
				default: OStream->WriteString (OStream, "reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetwkName", "CodingScheme");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkName", "AddCI");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<AddCI> ACCESS=<Data->AddCI>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->AddCI)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "The MS should not add the letters for the Country's Initials to the text string"); break;
				case 1: OStream->WriteString (OStream, "The MS should add the letters for the Country's Initials and a separator (e.g. a space) to the text string"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetwkName", "AddCI");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkName", "SpareBitsInLastOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareBitsInLastOctet> ACCESS=<Data->SpareBitsInLastOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SpareBitsInLastOctet)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "this field carries no information about the number of spare bits in octet n"); break;
				case 1: OStream->WriteString (OStream, "bit 8 is spare and set to '0' in octet n"); break;
				case 2: OStream->WriteString (OStream, "bits 7 and 8 are spare and set to '0' in octet n"); break;
				case 3: OStream->WriteString (OStream, "bits 6 to 8(inclusive) are spare and set to '0' in octet n"); break;
				case 4: OStream->WriteString (OStream, "bits 5 to 8(inclusive) are spare and set to '0' in octet n"); break;
				case 5: OStream->WriteString (OStream, "bits 4 to 8(inclusive) are spare and set to '0' in octet n"); break;
				case 6: OStream->WriteString (OStream, "bits 3 to 8(inclusive) are spare and set to '0' in octet n"); break;
				case 7: OStream->WriteString (OStream, "bits 2 to 8(inclusive) are spare and set to '0' in octet n"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetwkName", "SpareBitsInLastOctet");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkName", "TextString");
	  /* NAME=<TextString> ACCESS=<Data->TextString>  MAXBITSIZE=<1992> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TextString.value, Data->TextString.usedBits);
	ED_Dump_Struct_End_Field (OStream, "NetwkName", "TextString");
	ED_Dump_Struct_End (OStream, "NetwkName");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RejectCause (TEDOStream* OStream, const c_RejectCause* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RejectCause");
	ED_Dump_Struct_Begin_Field (OStream, "RejectCause", "Cause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Cause)
		{
			switch (DATA) {
				case 2: OStream->WriteString (OStream, "IMSI unknown in HLR"); break;
				case 3: OStream->WriteString (OStream, "Illegal MS"); break;
				case 4: OStream->WriteString (OStream, "IMSI unknown in VLR"); break;
				case 5: OStream->WriteString (OStream, "IMEI not accepted"); break;
				case 6: OStream->WriteString (OStream, "Illegal ME"); break;
				case 11: OStream->WriteString (OStream, "PLMN not allowed"); break;
				case 12: OStream->WriteString (OStream, "Location Area not allowed"); break;
				case 13: OStream->WriteString (OStream, "Roaming not allowed in this location area"); break;
				case 15: OStream->WriteString (OStream, "No Suitable Cells In Location Area"); break;
				case 17: OStream->WriteString (OStream, "Network failure"); break;
				case 20: OStream->WriteString (OStream, "MAC failure"); break;
				case 21: OStream->WriteString (OStream, "Synch failure"); break;
				case 22: OStream->WriteString (OStream, "Congestion"); break;
				case 23: OStream->WriteString (OStream, "GSM authentication unacceptable"); break;
				case 25: OStream->WriteString (OStream, "Not authorized for this CSG"); break;
				case 28: OStream->WriteString (OStream, "SMS provided via GPRS in this routing area"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 38: OStream->WriteString (OStream, "Call cannot be identified"); break;
				case 48: OStream->WriteString (OStream, "Retry upon entry into a new cell 0"); break;
				case 49: OStream->WriteString (OStream, "Retry upon entry into a new cell 1"); break;
				case 50: OStream->WriteString (OStream, "Retry upon entry into a new cell 2"); break;
				case 51: OStream->WriteString (OStream, "Retry upon entry into a new cell 3"); break;
				case 52: OStream->WriteString (OStream, "Retry upon entry into a new cell 4"); break;
				case 53: OStream->WriteString (OStream, "Retry upon entry into a new cell 5"); break;
				case 54: OStream->WriteString (OStream, "Retry upon entry into a new cell 6"); break;
				case 55: OStream->WriteString (OStream, "Retry upon entry into a new cell 7"); break;
				case 56: OStream->WriteString (OStream, "Retry upon entry into a new cell 8"); break;
				case 57: OStream->WriteString (OStream, "Retry upon entry into a new cell 9"); break;
				case 58: OStream->WriteString (OStream, "Retry upon entry into a new cell 10"); break;
				case 59: OStream->WriteString (OStream, "Retry upon entry into a new cell 11"); break;
				case 60: OStream->WriteString (OStream, "Retry upon entry into a new cell 12"); break;
				case 61: OStream->WriteString (OStream, "Retry upon entry into a new cell 13"); break;
				case 62: OStream->WriteString (OStream, "Retry upon entry into a new cell 14"); break;
				case 63: OStream->WriteString (OStream, "Retry upon entry into a new cell 15"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "RejectCause", "Cause");
	ED_Dump_Struct_End (OStream, "RejectCause");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TimeZoneAndTime (TEDOStream* OStream, const c_TimeZoneAndTime* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TimeZoneAndTime");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "Year");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Year> ACCESS=<Data->Year>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Year);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "Year");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "Month");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Month> ACCESS=<Data->Month>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Month);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "Month");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "Day");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Day> ACCESS=<Data->Day>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Day);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "Day");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "Hour");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Hour> ACCESS=<Data->Hour>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Hour);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "Hour");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "Minute");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Minute> ACCESS=<Data->Minute>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Minute);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "Minute");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "Second");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Second> ACCESS=<Data->Second>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Second);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "Second");
	ED_Dump_Struct_Begin_Field (OStream, "TimeZoneAndTime", "TimeZone");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimeZone> ACCESS=<Data->TimeZone>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimeZone);
	ED_Dump_Struct_End_Field (OStream, "TimeZoneAndTime", "TimeZone");
	ED_Dump_Struct_End (OStream, "TimeZoneAndTime");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DaylightSavingTime (TEDOStream* OStream, const c_DaylightSavingTime* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DaylightSavingTime");
	ED_Dump_Struct_Begin_Field (OStream, "DaylightSavingTime", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_DaylightSavingTime_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "DaylightSavingTime", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "DaylightSavingTime", "Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Value> ACCESS=<Data->Value>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Value)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No adjustment for Daylight Saving Time"); break;
				case 1: OStream->WriteString (OStream, "+1 hour adjustment for Daylight Saving Time"); break;
				case 2: OStream->WriteString (OStream, "+2 hours adjustment for Daylight Saving Time"); break;
				case 3: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DaylightSavingTime", "Value");
	ED_Dump_Struct_End (OStream, "DaylightSavingTime");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AdditionalUpdateParameters (TEDOStream* OStream, const c_AdditionalUpdateParameters* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AdditionalUpdateParameters");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateParameters", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateParameters_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateParameters", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateParameters", "CSMO");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CSMO> ACCESS=<Data->CSMO>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CSMO)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No additional information"); break;
				case 1: OStream->WriteString (OStream, "CS fallback mobile originating call"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateParameters", "CSMO");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateParameters", "CSMT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CSMT> ACCESS=<Data->CSMT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CSMT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No additional information"); break;
				case 1: OStream->WriteString (OStream, "CS fallback mobile terminating call"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateParameters", "CSMT");
	ED_Dump_Struct_End (OStream, "AdditionalUpdateParameters");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AuxiliaryStates (TEDOStream* OStream, const c_AuxiliaryStates* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AuxiliaryStates");
	ED_Dump_Struct_Begin_Field (OStream, "AuxiliaryStates", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_AuxiliaryStates_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AuxiliaryStates", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "AuxiliaryStates", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_AuxiliaryStates_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AuxiliaryStates", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "AuxiliaryStates", "HoldAuxState");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HoldAuxState> ACCESS=<Data->HoldAuxState>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->HoldAuxState)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "idle"); break;
				case 1: OStream->WriteString (OStream, "hold request"); break;
				case 2: OStream->WriteString (OStream, "call held"); break;
				case 3: OStream->WriteString (OStream, "retrieve request"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AuxiliaryStates", "HoldAuxState");
	ED_Dump_Struct_Begin_Field (OStream, "AuxiliaryStates", "MPTYAuxState");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MPTYAuxState> ACCESS=<Data->MPTYAuxState>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MPTYAuxState)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "idle"); break;
				case 1: OStream->WriteString (OStream, "MPTY request"); break;
				case 2: OStream->WriteString (OStream, "call in MPTY"); break;
				case 3: OStream->WriteString (OStream, "split request"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AuxiliaryStates", "MPTYAuxState");
	ED_Dump_Struct_End (OStream, "AuxiliaryStates");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CallState (TEDOStream* OStream, const c_CallState* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CallState");
	ED_Dump_Struct_Begin_Field (OStream, "CallState", "CodingStandard");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CodingStandard> ACCESS=<Data->CodingStandard>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CodingStandard)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "standardized coding as described in ITU-T Rec. Q.931"); break;
				case 1: OStream->WriteString (OStream, "reserved for other international standards"); break;
				case 2: OStream->WriteString (OStream, "national standard"); break;
				case 3: OStream->WriteString (OStream, "standard defined for the GSM PLMNS as described below"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallState", "CodingStandard");
	ED_Dump_Struct_Begin_Field (OStream, "CallState", "CallStateValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CallStateValue> ACCESS=<Data->CallStateValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CallStateValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "UO - null NO - null"); break;
				case 1: OStream->WriteString (OStream, "U1 - call initiated N1 - call initiated"); break;
				case 2: OStream->WriteString (OStream, "U0.1- MM connection pending N0.1- MM connection pending"); break;
				case 3: OStream->WriteString (OStream, "U3 - mobile originating call proceeding N3 - mobile originating call proceeding"); break;
				case 4: OStream->WriteString (OStream, "U4 - call delivered N4 - call delivered"); break;
				case 6: OStream->WriteString (OStream, "U6 - call present N6 - call present"); break;
				case 7: OStream->WriteString (OStream, "U7 - call received N7 - call received"); break;
				case 8: OStream->WriteString (OStream, "U8 - connect request N8 - connect request"); break;
				case 9: OStream->WriteString (OStream, "U9 - mobile terminating call confirmed N9 - mobile terminating call confirmed"); break;
				case 10: OStream->WriteString (OStream, "U10- active N10- active"); break;
				case 11: OStream->WriteString (OStream, "U11- disconnect request"); break;
				case 12: OStream->WriteString (OStream, "U12- disconnect indication N12-disconnect indication"); break;
				case 19: OStream->WriteString (OStream, "U19- release request N19- release request"); break;
				case 26: OStream->WriteString (OStream, "U26- mobile originating modify N26- mobile originating modify"); break;
				case 27: OStream->WriteString (OStream, "U27- mobile terminating modify N27- mobile terminating modify"); break;
				case 28: OStream->WriteString (OStream, "N28- connect indication"); break;
				case 34: OStream->WriteString (OStream, "U0.2- CC prompt present N0.2- CC connection pending"); break;
				case 35: OStream->WriteString (OStream, "U0.3- Wait for network information N0.3- Network answer pending"); break;
				case 36: OStream->WriteString (OStream, "U0.4- CC-Establishment present N0.4- CC-Establishment present"); break;
				case 37: OStream->WriteString (OStream, "U0.5- CC-Establishment confirmed N0.5- CC-Establishment confirmed"); break;
				case 38: OStream->WriteString (OStream, "U0.6- Recall present N0.6- Recall present"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallState", "CallStateValue");
	ED_Dump_Struct_End (OStream, "CallState");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ConnSubaddres (TEDOStream* OStream, const c_ConnSubaddres* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ConnSubaddres");
	ED_Dump_Struct_Begin_Field (OStream, "ConnSubaddres", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_ConnSubaddres_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ConnSubaddres", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "ConnSubaddres", "TypeOfSubaddress");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfSubaddress> ACCESS=<Data->TypeOfSubaddress>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TypeOfSubaddress);
	ED_Dump_Struct_End_Field (OStream, "ConnSubaddres", "TypeOfSubaddress");
	ED_Dump_Struct_Begin_Field (OStream, "ConnSubaddres", "OddEvenIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<OddEvenIndicator> ACCESS=<Data->OddEvenIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->OddEvenIndicator);
	ED_Dump_Struct_End_Field (OStream, "ConnSubaddres", "OddEvenIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "ConnSubaddres", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_ConnSubaddres_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ConnSubaddres", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "ConnSubaddres", "SubaddressInformation");
	  /* NAME=<SubaddressInformation> ACCESS=<Data->SubaddressInformation>  MAXBITSIZE=<160> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->SubaddressInformation.value, Data->SubaddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "ConnSubaddres", "SubaddressInformation");
	ED_Dump_Struct_End (OStream, "ConnSubaddres");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_KeypadFacility (TEDOStream* OStream, const c_KeypadFacility* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "KeypadFacility");
	ED_Dump_Struct_Begin_Field (OStream, "KeypadFacility", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_KeypadFacility_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "KeypadFacility", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "KeypadFacility", "KeypadInfo");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<KeypadInfo> ACCESS=<Data->KeypadInfo>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->KeypadInfo);
	ED_Dump_Struct_End_Field (OStream, "KeypadFacility", "KeypadInfo");
	ED_Dump_Struct_End (OStream, "KeypadFacility");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NotifInd (TEDOStream* OStream, const c_NotifInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NotifInd");
	ED_Dump_Struct_Begin_Field (OStream, "NotifInd", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_NotifInd_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NotifInd", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "NotifInd", "NotificationDescription");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NotificationDescription> ACCESS=<Data->NotificationDescription>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NotificationDescription)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "User suspended"); break;
				case 1: OStream->WriteString (OStream, "User resumed"); break;
				case 2: OStream->WriteString (OStream, "Bearer change"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NotifInd", "NotificationDescription");
	ED_Dump_Struct_End (OStream, "NotifInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ProgrInd (TEDOStream* OStream, const c_ProgrInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "ProgrInd", "ext1");
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd_ext1> NAME=<ext1> ACCESS=<Data->ext1>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ProgrInd", "ext1");
	ED_Dump_Struct_Begin_Field (OStream, "ProgrInd", "CodingStandard");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CodingStandard> ACCESS=<Data->CodingStandard>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CodingStandard)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Standardized coding, as described in ITU-T Rec. Q.931"); break;
				case 1: OStream->WriteString (OStream, "Reserved for other international standards"); break;
				case 2: OStream->WriteString (OStream, "National standard"); break;
				case 3: OStream->WriteString (OStream, "Standard defined for the GSM PLMNS as described below"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ProgrInd", "CodingStandard");
	ED_Dump_Struct_Begin_Field (OStream, "ProgrInd", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ProgrInd", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "ProgrInd", "location");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<location> ACCESS=<Data->location>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->location)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "User"); break;
				case 1: OStream->WriteString (OStream, "Private network serving the local user"); break;
				case 2: OStream->WriteString (OStream, "Public network serving the local user"); break;
				case 4: OStream->WriteString (OStream, "Public network serving the remote user"); break;
				case 5: OStream->WriteString (OStream, "Private network serving the remote user"); break;
				case 10: OStream->WriteString (OStream, "Network beyond interworking point"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ProgrInd", "location");
	ED_Dump_Struct_Begin_Field (OStream, "ProgrInd", "ext2");
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd_ext2> NAME=<ext2> ACCESS=<Data->ext2>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ProgrInd", "ext2");
	ED_Dump_Struct_Begin_Field (OStream, "ProgrInd", "ProgressDescription");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ProgressDescription> ACCESS=<Data->ProgressDescription>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ProgressDescription)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "1. Call is not end-to-end PLMN/ISDN, further call progress information may be available in-band"); break;
				case 2: OStream->WriteString (OStream, "2. Destination address in non-PLMN/ISDN"); break;
				case 3: OStream->WriteString (OStream, "3. Origination address in non-PLMN/ISDN"); break;
				case 4: OStream->WriteString (OStream, "4. Call has returned to the PLMN/ISDN"); break;
				case 8: OStream->WriteString (OStream, "8. In-band information or appropriate pattern now available"); break;
				case 9: OStream->WriteString (OStream, "9. In-band multimedia CAT available"); break;
				case 32: OStream->WriteString (OStream, "32. Call is end-to-end PLMN/ISDN"); break;
				case 64: OStream->WriteString (OStream, "64. Queueing"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ProgrInd", "ProgressDescription");
	ED_Dump_Struct_End (OStream, "ProgrInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RecallType (TEDOStream* OStream, const c_RecallType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RecallType");
	ED_Dump_Struct_Begin_Field (OStream, "RecallType", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_RecallType_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "RecallType", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "RecallType", "RecallType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RecallType> ACCESS=<Data->RecallType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RecallType);
	ED_Dump_Struct_End_Field (OStream, "RecallType", "RecallType");
	ED_Dump_Struct_End (OStream, "RecallType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RedirPartySubaddr (TEDOStream* OStream, const c_RedirPartySubaddr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RedirPartySubaddr");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartySubaddr", "ext");
	  /* STRUCTURAL=<0> TYPE=<c_RedirPartySubaddr_ext> NAME=<ext> ACCESS=<Data->ext>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "RedirPartySubaddr", "ext");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartySubaddr", "TypeOfSubaddress");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfSubaddress> ACCESS=<Data->TypeOfSubaddress>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TypeOfSubaddress);
	ED_Dump_Struct_End_Field (OStream, "RedirPartySubaddr", "TypeOfSubaddress");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartySubaddr", "OddEvenIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<OddEvenIndicator> ACCESS=<Data->OddEvenIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->OddEvenIndicator);
	ED_Dump_Struct_End_Field (OStream, "RedirPartySubaddr", "OddEvenIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartySubaddr", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_RedirPartySubaddr_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "RedirPartySubaddr", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartySubaddr", "SubaddressInformation");
	  /* NAME=<SubaddressInformation> ACCESS=<Data->SubaddressInformation>  MAXBITSIZE=<160> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->SubaddressInformation.value, Data->SubaddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "RedirPartySubaddr", "SubaddressInformation");
	ED_Dump_Struct_End (OStream, "RedirPartySubaddr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AlertingPattern (TEDOStream* OStream, const c_AlertingPattern* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AlertingPattern");
	ED_Dump_Struct_Begin_Field (OStream, "AlertingPattern", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_AlertingPattern_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AlertingPattern", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "AlertingPattern", "AlertingPatternValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AlertingPatternValue> ACCESS=<Data->AlertingPatternValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->AlertingPatternValue);
	ED_Dump_Struct_End_Field (OStream, "AlertingPattern", "AlertingPatternValue");
	ED_Dump_Struct_End (OStream, "AlertingPattern");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AllowedActionsCcbs (TEDOStream* OStream, const c_AllowedActionsCcbs* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AllowedActionsCcbs");
	ED_Dump_Struct_Begin_Field (OStream, "AllowedActionsCcbs", "CCBSAct");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CCBSAct> ACCESS=<Data->CCBSAct>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->CCBSAct);
	ED_Dump_Struct_End_Field (OStream, "AllowedActionsCcbs", "CCBSAct");
	ED_Dump_Struct_Begin_Field (OStream, "AllowedActionsCcbs", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_AllowedActionsCcbs_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AllowedActionsCcbs", "spare");
	ED_Dump_Struct_End (OStream, "AllowedActionsCcbs");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NetwkCallControlCapabil (TEDOStream* OStream, const c_NetwkCallControlCapabil* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NetwkCallControlCapabil");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkCallControlCapabil", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_NetwkCallControlCapabil_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NetwkCallControlCapabil", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkCallControlCapabil", "MCS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MCS> ACCESS=<Data->MCS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->MCS);
	ED_Dump_Struct_End_Field (OStream, "NetwkCallControlCapabil", "MCS");
	ED_Dump_Struct_End (OStream, "NetwkCallControlCapabil");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AdditionalUpdateType (TEDOStream* OStream, const c_AdditionalUpdateType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AdditionalUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateType", "PNB_CIoT");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PNB_CIoT> ACCESS=<Data->PNB_CIoT>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PNB_CIoT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no additional information"); break;
				case 1: OStream->WriteString (OStream, "control plane CIoT EPS optimization"); break;
				case 2: OStream->WriteString (OStream, "user plane CIoT EPS optimization"); break;
				case 3: OStream->WriteString (OStream, "reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateType", "PNB_CIoT");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateType", "SAF");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SAF> ACCESS=<Data->SAF>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->SAF)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "keeping the NAS signalling connection is not required"); break;
				case 1: OStream->WriteString (OStream, "keeping the NAS signalling connection is required"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateType", "SAF");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalUpdateType", "AUTV");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<AUTV> ACCESS=<Data->AUTV>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->AUTV)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no additional information"); break;
				case 1: OStream->WriteString (OStream, "SMS only"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AdditionalUpdateType", "AUTV");
	ED_Dump_Struct_End (OStream, "AdditionalUpdateType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AttachResult (TEDOStream* OStream, const c_AttachResult* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AttachResult");
	ED_Dump_Struct_Begin_Field (OStream, "AttachResult", "FOP");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FOP> ACCESS=<Data->FOP>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->FOP)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Follow-on proceed"); break;
				case 1: OStream->WriteString (OStream, "No follow-on proceed"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AttachResult", "FOP");
	ED_Dump_Struct_Begin_Field (OStream, "AttachResult", "ResultOfAttach");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ResultOfAttach> ACCESS=<Data->ResultOfAttach>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ResultOfAttach)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "GPRS only attached"); break;
				case 3: OStream->WriteString (OStream, "Combined GPRS/IMSI attached"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AttachResult", "ResultOfAttach");
	ED_Dump_Struct_End (OStream, "AttachResult");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AttachType (TEDOStream* OStream, const c_AttachType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AttachType");
	ED_Dump_Struct_Begin_Field (OStream, "AttachType", "xFOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<xFOR> ACCESS=<Data->xFOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->xFOR)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No follow-on request pending"); break;
				case 1: OStream->WriteString (OStream, "Follow-on request pending"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AttachType", "xFOR");
	ED_Dump_Struct_Begin_Field (OStream, "AttachType", "TypeOfAttach");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfAttach> ACCESS=<Data->TypeOfAttach>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfAttach)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "GPRS attach"); break;
				case 2: OStream->WriteString (OStream, "Not used. This value was allocated in earlier versions of the protocol (Note1)"); break;
				case 3: OStream->WriteString (OStream, "Combined GPRS/IMSI attach"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AttachType", "TypeOfAttach");
	ED_Dump_Struct_End (OStream, "AttachType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IntegrityProtectionAlgorithm (TEDOStream* OStream, const c_IntegrityProtectionAlgorithm* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IntegrityProtectionAlgorithm");
	ED_Dump_Struct_Begin_Field (OStream, "IntegrityProtectionAlgorithm", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_IntegrityProtectionAlgorithm_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "IntegrityProtectionAlgorithm", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "IntegrityProtectionAlgorithm", "TypeOfAlgorithm");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfAlgorithm> ACCESS=<Data->TypeOfAlgorithm>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfAlgorithm)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GPRS Integrity Algorithm GIA/4"); break;
				case 1: OStream->WriteString (OStream, "GPRS Integrity Algorithm GIA/5"); break;
				case 2: OStream->WriteString (OStream, "GPRS Integrity Algorithm GIA/6"); break;
				case 3: OStream->WriteString (OStream, "GPRS Integrity Algorithm GIA/7"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "IntegrityProtectionAlgorithm", "TypeOfAlgorithm");
	ED_Dump_Struct_End (OStream, "IntegrityProtectionAlgorithm");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TmsiStatus (TEDOStream* OStream, const c_TmsiStatus* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TmsiStatus");
	ED_Dump_Struct_Begin_Field (OStream, "TmsiStatus", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_TmsiStatus_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TmsiStatus", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "TmsiStatus", "TMSIFlag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TMSIFlag> ACCESS=<Data->TMSIFlag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TMSIFlag);
	ED_Dump_Struct_End_Field (OStream, "TmsiStatus", "TMSIFlag");
	ED_Dump_Struct_End (OStream, "TmsiStatus");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DetachType (TEDOStream* OStream, const c_DetachType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DetachType");
	ED_Dump_Struct_Begin_Field (OStream, "DetachType", "PowerOff");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PowerOff> ACCESS=<Data->PowerOff>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->PowerOff)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "normal detach"); break;
				case 1: OStream->WriteString (OStream, "power switched off"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DetachType", "PowerOff");
	ED_Dump_Struct_Begin_Field (OStream, "DetachType", "TypeOfDetach");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfDetach> ACCESS=<Data->TypeOfDetach>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfDetach)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "GPRS detach"); break;
				case 2: OStream->WriteString (OStream, "IMSI detach"); break;
				case 3: OStream->WriteString (OStream, "Combined GPRS/IMSI detach"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DetachType", "TypeOfDetach");
	ED_Dump_Struct_End (OStream, "DetachType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DrxParam (TEDOStream* OStream, const c_DrxParam* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DrxParam");
	ED_Dump_Struct_Begin_Field (OStream, "DrxParam", "SplitPgCycleCode");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SplitPgCycleCode> ACCESS=<Data->SplitPgCycleCode>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SplitPgCycleCode);
	ED_Dump_Struct_End_Field (OStream, "DrxParam", "SplitPgCycleCode");
	ED_Dump_Struct_Begin_Field (OStream, "DrxParam", "CNSpecDRX");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CNSpecDRX> ACCESS=<Data->CNSpecDRX>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CNSpecDRX)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "For Iu mode, CN Specific DRX cycle length coefficient not specified by the MS, ie. the system information value 'CN domain specific DRX cycle length' is used . For S1 mode, DRX value not specified by the MS."); break;
				case 6: OStream->WriteString (OStream, "CN Specific DRX cycle length coefficient 6 and T = 32"); break;
				case 7: OStream->WriteString (OStream, "CN Specific DRX cycle length coefficient 7 and T = 64"); break;
				case 8: OStream->WriteString (OStream, "CN Specific DRX cycle length coefficient 8 and T = 128"); break;
				case 9: OStream->WriteString (OStream, "CN Specific DRX cycle length coefficient 9 and T = 256"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DrxParam", "CNSpecDRX");
	ED_Dump_Struct_Begin_Field (OStream, "DrxParam", "SplitOnCCCH");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SplitOnCCCH> ACCESS=<Data->SplitOnCCCH>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->SplitOnCCCH)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Split pg cycle on CCCH is not supported by the mobile station"); break;
				case 1: OStream->WriteString (OStream, "Split pg cycle on CCCH is supported by the mobile station"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DrxParam", "SplitOnCCCH");
	ED_Dump_Struct_Begin_Field (OStream, "DrxParam", "nonDRXTimer");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<nonDRXTimer> ACCESS=<Data->nonDRXTimer>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->nonDRXTimer)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no non-DRX mode after transfer state"); break;
				case 1: OStream->WriteString (OStream, "max. 1 sec non-DRX mode after transfer state"); break;
				case 2: OStream->WriteString (OStream, "max. 2 sec non-DRX mode after transfer state"); break;
				case 3: OStream->WriteString (OStream, "max. 4 sec non-DRX mode after transfer state"); break;
				case 4: OStream->WriteString (OStream, "max. 8 sec non-DRX mode after transfer state"); break;
				case 5: OStream->WriteString (OStream, "max. 16 sec non-DRX mode after transfer state"); break;
				case 6: OStream->WriteString (OStream, "max. 32 sec non-DRX mode after transfer state"); break;
				case 7: OStream->WriteString (OStream, "max. 64 sec non-DRX mode after transfer state"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DrxParam", "nonDRXTimer");
	ED_Dump_Struct_End (OStream, "DrxParam");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RoutingAreaIdenti (TEDOStream* OStream, const c_RoutingAreaIdenti* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RoutingAreaIdenti");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "LAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<LAC> ACCESS=<Data->LAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LAC);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "LAC");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti", "RAC");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RAC> ACCESS=<Data->RAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RAC);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti", "RAC");
	ED_Dump_Struct_End (OStream, "RoutingAreaIdenti");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RoutingAreaIdenti2 (TEDOStream* OStream, const c_RoutingAreaIdenti2* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RoutingAreaIdenti2");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "MCC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC2> ACCESS=<Data->MCC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC2);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "MCC2");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "MCC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC1> ACCESS=<Data->MCC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC1);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "MCC1");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "MNC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC3> ACCESS=<Data->MNC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC3);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "MNC3");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "MCC3");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MCC3> ACCESS=<Data->MCC3>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MCC3);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "MCC3");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "MNC2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC2> ACCESS=<Data->MNC2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC2);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "MNC2");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "MNC1");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MNC1> ACCESS=<Data->MNC1>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MNC1);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "MNC1");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "LAC");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<LAC> ACCESS=<Data->LAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LAC);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "LAC");
	ED_Dump_Struct_Begin_Field (OStream, "RoutingAreaIdenti2", "RAC");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RAC> ACCESS=<Data->RAC>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RAC);
	ED_Dump_Struct_End_Field (OStream, "RoutingAreaIdenti2", "RAC");
	ED_Dump_Struct_End (OStream, "RoutingAreaIdenti2");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_UpdateType (TEDOStream* OStream, const c_UpdateType* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "UpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "UpdateType", "xFOR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<xFOR> ACCESS=<Data->xFOR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->xFOR)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "No follow-on request pending"); break;
				case 1: OStream->WriteString (OStream, "Follow-on request pending"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "UpdateType", "xFOR");
	ED_Dump_Struct_Begin_Field (OStream, "UpdateType", "UpdateTypeValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UpdateTypeValue> ACCESS=<Data->UpdateTypeValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UpdateTypeValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "RA updating"); break;
				case 1: OStream->WriteString (OStream, "combined RA/LA updating"); break;
				case 2: OStream->WriteString (OStream, "combined RA/LA updating with IMSI attach"); break;
				case 3: OStream->WriteString (OStream, "Periodic updating"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "UpdateType", "UpdateTypeValue");
	ED_Dump_Struct_End (OStream, "UpdateType");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PSLCSCapabilit (TEDOStream* OStream, const c_PSLCSCapabilit* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PSLCSCapabilit");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PSLCSCapabilit_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "APC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<APC> ACCESS=<Data->APC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->APC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Additional Positioning Capabilities which can be retrieved by RRLP are not supported"); break;
				case 1: OStream->WriteString (OStream, "Additional Positioning Capabilities which can be retrieved by RRLP are supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "APC");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "OTD_A");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<OTD_A> ACCESS=<Data->OTD_A>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->OTD_A)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MS assisted E-OTD not supported"); break;
				case 1: OStream->WriteString (OStream, "MS assisted E-OTD supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "OTD_A");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "OTD_B");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<OTD_B> ACCESS=<Data->OTD_B>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->OTD_B)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MS based E-OTD not supported"); break;
				case 1: OStream->WriteString (OStream, "MS based E-OTD supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "OTD_B");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "GPS_A");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GPS_A> ACCESS=<Data->GPS_A>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->GPS_A)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MS assisted GPS not supported"); break;
				case 1: OStream->WriteString (OStream, "MS assisted GPS supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "GPS_A");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "GPS_B");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GPS_B> ACCESS=<Data->GPS_B>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->GPS_B)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MS based GPS not supported"); break;
				case 1: OStream->WriteString (OStream, "MS based GPS supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "GPS_B");
	ED_Dump_Struct_Begin_Field (OStream, "PSLCSCapabilit", "GPS_C");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GPS_C> ACCESS=<Data->GPS_C>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->GPS_C)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Conventional GPS not supported"); break;
				case 1: OStream->WriteString (OStream, "Conventional GPS supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PSLCSCapabilit", "GPS_C");
	ED_Dump_Struct_End (OStream, "PSLCSCapabilit");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NetworkFeatureSupport (TEDOStream* OStream, const c_NetworkFeatureSupport* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "NetworkFeatureSupport", "LCS_MOLR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LCS_MOLR> ACCESS=<Data->LCS_MOLR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->LCS_MOLR)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "LCS-MOLR via PS domain not supported"); break;
				case 1: OStream->WriteString (OStream, "LCS-MOLR via PS domain supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetworkFeatureSupport", "LCS_MOLR");
	ED_Dump_Struct_Begin_Field (OStream, "NetworkFeatureSupport", "MBMS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MBMS> ACCESS=<Data->MBMS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->MBMS)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "MBMS not supported"); break;
				case 1: OStream->WriteString (OStream, "MBMS supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetworkFeatureSupport", "MBMS");
	ED_Dump_Struct_Begin_Field (OStream, "NetworkFeatureSupport", "IMSVoPS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<IMSVoPS> ACCESS=<Data->IMSVoPS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->IMSVoPS)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "IMS voice over PS session in Iu mode and A/Gb mode not supported"); break;
				case 1: OStream->WriteString (OStream, "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetworkFeatureSupport", "IMSVoPS");
	ED_Dump_Struct_Begin_Field (OStream, "NetworkFeatureSupport", "EMCBS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EMCBS> ACCESS=<Data->EMCBS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->EMCBS)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Emergency bearer services in Iu mode and A/Gb mode not supported"); break;
				case 1: OStream->WriteString (OStream, "Emergency bearer services supported in Iu mode, but not supported in A/Gb mode"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetworkFeatureSupport", "EMCBS");
	ED_Dump_Struct_End (OStream, "NetworkFeatureSupport");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AdditionalNetworkFeatureSupport (TEDOStream* OStream, const c_AdditionalNetworkFeatureSupport* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AdditionalNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalNetworkFeatureSupport", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalNetworkFeatureSupport_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "AdditionalNetworkFeatureSupport", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "AdditionalNetworkFeatureSupport", "GPRS_SMS");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GPRS_SMS> ACCESS=<Data->GPRS_SMS>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GPRS_SMS);
	ED_Dump_Struct_End_Field (OStream, "AdditionalNetworkFeatureSupport", "GPRS_SMS");
	ED_Dump_Struct_End (OStream, "AdditionalNetworkFeatureSupport");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RequestedMSInformation (TEDOStream* OStream, const c_RequestedMSInformation* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RequestedMSInformation");
	ED_Dump_Struct_Begin_Field (OStream, "RequestedMSInformation", "I_RAT");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<I_RAT> ACCESS=<Data->I_RAT>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->I_RAT)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Inter RAT information container IE not requested"); break;
				case 1: OStream->WriteString (OStream, "Inter RAT information container IE requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "RequestedMSInformation", "I_RAT");
	ED_Dump_Struct_Begin_Field (OStream, "RequestedMSInformation", "I_RAT2");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<I_RAT2> ACCESS=<Data->I_RAT2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->I_RAT2)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "E-UTRAN inter RAT information container IE not requested"); break;
				case 1: OStream->WriteString (OStream, "E-UTRAN inter RAT information container IE requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "RequestedMSInformation", "I_RAT2");
	ED_Dump_Struct_Begin_Field (OStream, "RequestedMSInformation", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_RequestedMSInformation_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "RequestedMSInformation", "spare");
	ED_Dump_Struct_End (OStream, "RequestedMSInformation");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_VoiceDomainPreferenceAndUEsUsageSetting (TEDOStream* OStream, const c_VoiceDomainPreferenceAndUEsUsageSetting* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "VoiceDomainPreferenceAndUEsUsageSetting");
	ED_Dump_Struct_Begin_Field (OStream, "VoiceDomainPreferenceAndUEsUsageSetting", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_VoiceDomainPreferenceAndUEsUsageSetting_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "VoiceDomainPreferenceAndUEsUsageSetting", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "VoiceDomainPreferenceAndUEsUsageSetting", "UEUsageSetting");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UEUsageSetting> ACCESS=<Data->UEUsageSetting>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->UEUsageSetting)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Voice centric"); break;
				case 1: OStream->WriteString (OStream, "Data centric"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "VoiceDomainPreferenceAndUEsUsageSetting", "UEUsageSetting");
	ED_Dump_Struct_Begin_Field (OStream, "VoiceDomainPreferenceAndUEsUsageSetting", "VoiceDomainPreferenceForEUTRAN");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<VoiceDomainPreferenceForEUTRAN> ACCESS=<Data->VoiceDomainPreferenceForEUTRAN>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->VoiceDomainPreferenceForEUTRAN)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "CS Voice only"); break;
				case 1: OStream->WriteString (OStream, "IMS PS Voice only"); break;
				case 2: OStream->WriteString (OStream, "CS voice preferred, IMS PS Voice as secondary"); break;
				case 3: OStream->WriteString (OStream, "IMS PS voice preferred, CS Voice as secondary"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "VoiceDomainPreferenceAndUEsUsageSetting", "VoiceDomainPreferenceForEUTRAN");
	ED_Dump_Struct_End (OStream, "VoiceDomainPreferenceAndUEsUsageSetting");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PTMSI_Type (TEDOStream* OStream, const c_PTMSI_Type* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PTMSI_Type");
	ED_Dump_Struct_Begin_Field (OStream, "PTMSI_Type", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PTMSI_Type_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PTMSI_Type", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PTMSI_Type", "PTMSI_Type");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PTMSI_Type> ACCESS=<Data->PTMSI_Type>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PTMSI_Type);
	ED_Dump_Struct_End_Field (OStream, "PTMSI_Type", "PTMSI_Type");
	ED_Dump_Struct_End (OStream, "PTMSI_Type");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NetworkResourceIdContainer (TEDOStream* OStream, const c_NetworkResourceIdContainer* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NetworkResourceIdContainer");
	ED_Dump_Struct_Begin_Field (OStream, "NetworkResourceIdContainer", "NRIContainerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<NRIContainerValue> ACCESS=<Data->NRIContainerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NRIContainerValue);
	ED_Dump_Struct_End_Field (OStream, "NetworkResourceIdContainer", "NRIContainerValue");
	ED_Dump_Struct_Begin_Field (OStream, "NetworkResourceIdContainer", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_NetworkResourceIdContainer_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NetworkResourceIdContainer", "spare");
	ED_Dump_Struct_End (OStream, "NetworkResourceIdContainer");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ExtendedDRXParameters (TEDOStream* OStream, const c_ExtendedDRXParameters* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ExtendedDRXParameters");
	ED_Dump_Struct_Begin_Field (OStream, "ExtendedDRXParameters", "PagingTimeWindow");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PagingTimeWindow> ACCESS=<Data->PagingTimeWindow>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PagingTimeWindow)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "0 seconds (PTW not used)"); break;
				case 1: OStream->WriteString (OStream, "1 second"); break;
				case 2: OStream->WriteString (OStream, "2 seconds"); break;
				case 3: OStream->WriteString (OStream, "3 seconds"); break;
				case 4: OStream->WriteString (OStream, "4 seconds"); break;
				case 5: OStream->WriteString (OStream, "5 seconds"); break;
				case 6: OStream->WriteString (OStream, "6 seconds"); break;
				case 7: OStream->WriteString (OStream, "7 seconds"); break;
				case 8: OStream->WriteString (OStream, "8 seconds"); break;
				case 9: OStream->WriteString (OStream, "9 seconds"); break;
				case 10: OStream->WriteString (OStream, "10 seconds"); break;
				case 11: OStream->WriteString (OStream, "12 seconds"); break;
				case 12: OStream->WriteString (OStream, "14 seconds"); break;
				case 13: OStream->WriteString (OStream, "16 seconds"); break;
				case 14: OStream->WriteString (OStream, "18 seconds"); break;
				case 15: OStream->WriteString (OStream, "20 seconds"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ExtendedDRXParameters", "PagingTimeWindow");
	ED_Dump_Struct_Begin_Field (OStream, "ExtendedDRXParameters", "eDRXValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<eDRXValue> ACCESS=<Data->eDRXValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->eDRXValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "1,28 seconds"); break;
				case 1: OStream->WriteString (OStream, "2,56 seconds"); break;
				case 2: OStream->WriteString (OStream, "3,84 seconds"); break;
				case 3: OStream->WriteString (OStream, "5,12 seconds"); break;
				case 4: OStream->WriteString (OStream, "6,4 seconds"); break;
				case 5: OStream->WriteString (OStream, "7,68 seconds"); break;
				case 6: OStream->WriteString (OStream, "8,96 seconds"); break;
				case 7: OStream->WriteString (OStream, "10,24 seconds"); break;
				case 8: OStream->WriteString (OStream, "11,52 seconds"); break;
				case 9: OStream->WriteString (OStream, "12,8 seconds"); break;
				case 10: OStream->WriteString (OStream, "14,08 seconds"); break;
				case 11: OStream->WriteString (OStream, "15,36 seconds"); break;
				case 12: OStream->WriteString (OStream, "16,64 seconds"); break;
				case 13: OStream->WriteString (OStream, "17,92 seconds"); break;
				case 14: OStream->WriteString (OStream, "19,20 seconds"); break;
				case 15: OStream->WriteString (OStream, "20,48 seconds"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ExtendedDRXParameters", "eDRXValue");
	ED_Dump_Struct_End (OStream, "ExtendedDRXParameters");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NetwkServAccessPointId (TEDOStream* OStream, const c_NetwkServAccessPointId* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NetwkServAccessPointId");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkServAccessPointId", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_NetwkServAccessPointId_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "NetwkServAccessPointId", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "NetwkServAccessPointId", "NSAPIValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NSAPIValue> ACCESS=<Data->NSAPIValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NSAPIValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "reserved"); break;
				case 1: OStream->WriteString (OStream, "reserved"); break;
				case 2: OStream->WriteString (OStream, "reserved"); break;
				case 3: OStream->WriteString (OStream, "reserved"); break;
				case 4: OStream->WriteString (OStream, "reserved"); break;
				case 5: OStream->WriteString (OStream, "NSAPI 5"); break;
				case 6: OStream->WriteString (OStream, "NSAPI 6"); break;
				case 7: OStream->WriteString (OStream, "NSAPI 7"); break;
				case 8: OStream->WriteString (OStream, "NSAPI 8"); break;
				case 9: OStream->WriteString (OStream, "NSAPI 9"); break;
				case 10: OStream->WriteString (OStream, "NSAPI 10"); break;
				case 11: OStream->WriteString (OStream, "NSAPI 11"); break;
				case 12: OStream->WriteString (OStream, "NSAPI 12"); break;
				case 13: OStream->WriteString (OStream, "NSAPI 13"); break;
				case 14: OStream->WriteString (OStream, "NSAPI 14"); break;
				case 15: OStream->WriteString (OStream, "NSAPI 15"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NetwkServAccessPointId", "NSAPIValue");
	ED_Dump_Struct_End (OStream, "NetwkServAccessPointId");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PacketDataProtocolAddr (TEDOStream* OStream, const c_PacketDataProtocolAddr* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PacketDataProtocolAddr");
	ED_Dump_Struct_Begin_Field (OStream, "PacketDataProtocolAddr", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PacketDataProtocolAddr", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PacketDataProtocolAddr", "PDPTypeOrganisation");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PDPTypeOrganisation> ACCESS=<Data->PDPTypeOrganisation>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PDPTypeOrganisation)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "ETSI allocated address"); break;
				case 1: OStream->WriteString (OStream, "IETF allocated address"); break;
				case 15: OStream->WriteString (OStream, "Empty PDP type"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PacketDataProtocolAddr", "PDPTypeOrganisation");
	ED_Dump_Struct_Begin_Field (OStream, "PacketDataProtocolAddr", "PDPTypeNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PDPTypeNumber> ACCESS=<Data->PDPTypeNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PDPTypeNumber)
		{
			switch (DATA) {
				case 33: OStream->WriteString (OStream, "IPv4 address"); break;
				case 87: OStream->WriteString (OStream, "IPv6 address"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PacketDataProtocolAddr", "PDPTypeNumber");
	ED_Dump_Struct_Begin_Field (OStream, "PacketDataProtocolAddr", "AddressInformation");
	  /* NAME=<AddressInformation> ACCESS=<Data->AddressInformation>  MAXBITSIZE=<128> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AddressInformation.value, Data->AddressInformation.usedBits);
	ED_Dump_Struct_End_Field (OStream, "PacketDataProtocolAddr", "AddressInformation");
	ED_Dump_Struct_End (OStream, "PacketDataProtocolAddr");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_QualityOfServ (TEDOStream* OStream, const c_QualityOfServ* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "QualityOfServ");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "spare1");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ_spare1> NAME=<spare1> ACCESS=<Data->spare1>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "spare1");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "DelayClass");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DelayClass> ACCESS=<Data->DelayClass>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->DelayClass)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed delay class"); break;
				case 1: OStream->WriteString (OStream, "Delay class 1"); break;
				case 2: OStream->WriteString (OStream, "Delay class 2"); break;
				case 3: OStream->WriteString (OStream, "Delay class 3"); break;
				case 4: OStream->WriteString (OStream, "Delay class 4 (best effort)"); break;
				case 7: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "DelayClass");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "ReliabilityClass");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ReliabilityClass> ACCESS=<Data->ReliabilityClass>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ReliabilityClass)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed reliability class"); break;
				case 1: OStream->WriteString (OStream, "Unused. If received, it shall be interpreted as '010' (Note)"); break;
				case 2: OStream->WriteString (OStream, "Unacknowledged GTP; Acknowledged LLC and RLC, Protected data"); break;
				case 3: OStream->WriteString (OStream, "Unacknowledged GTP and LLC; Acknowledged RLC, Protected data"); break;
				case 4: OStream->WriteString (OStream, "Unacknowledged GTP, LLC, and RLC, Protected data"); break;
				case 5: OStream->WriteString (OStream, "Unacknowledged GTP, LLC, and RLC, Unprotected data"); break;
				case 7: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "ReliabilityClass");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "PeakThroughput");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PeakThroughput> ACCESS=<Data->PeakThroughput>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PeakThroughput)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed peak throughput"); break;
				case 1: OStream->WriteString (OStream, "Up to 1 000 octet/s"); break;
				case 2: OStream->WriteString (OStream, "Up to 2 000 octet/s"); break;
				case 3: OStream->WriteString (OStream, "Up to 4 000 octet/s"); break;
				case 4: OStream->WriteString (OStream, "Up to 8 000 octet/s"); break;
				case 5: OStream->WriteString (OStream, "Up to 16 000 octet/s"); break;
				case 6: OStream->WriteString (OStream, "Up to 32 000 octet/s"); break;
				case 7: OStream->WriteString (OStream, "Up to 64 000 octet/s"); break;
				case 8: OStream->WriteString (OStream, "Up to 128 000 octet/s"); break;
				case 9: OStream->WriteString (OStream, "Up to 256 000 octet/s"); break;
				case 15: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "PeakThroughput");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "spare2");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ_spare2> NAME=<spare2> ACCESS=<Data->spare2>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "spare2");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "PrecedenceClass");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PrecedenceClass> ACCESS=<Data->PrecedenceClass>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PrecedenceClass)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed precedence"); break;
				case 1: OStream->WriteString (OStream, "High priority"); break;
				case 2: OStream->WriteString (OStream, "Normal priority"); break;
				case 3: OStream->WriteString (OStream, "Low priority"); break;
				case 7: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "PrecedenceClass");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "spare3");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ_spare3> NAME=<spare3> ACCESS=<Data->spare3>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "spare3");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MeanThroughput");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MeanThroughput> ACCESS=<Data->MeanThroughput>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MeanThroughput)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed mean throughput"); break;
				case 1: OStream->WriteString (OStream, "100 octet/h"); break;
				case 2: OStream->WriteString (OStream, "200 octet/h"); break;
				case 3: OStream->WriteString (OStream, "500 octet/h"); break;
				case 4: OStream->WriteString (OStream, "1000 octet/h"); break;
				case 5: OStream->WriteString (OStream, "2 000 octet/h"); break;
				case 6: OStream->WriteString (OStream, "5 000 octet/h"); break;
				case 7: OStream->WriteString (OStream, "10 000 octet/h"); break;
				case 8: OStream->WriteString (OStream, "20 000 octet/h"); break;
				case 9: OStream->WriteString (OStream, "50 000 octet/h"); break;
				case 10: OStream->WriteString (OStream, "100 000 octet/h"); break;
				case 11: OStream->WriteString (OStream, "200 000 octet/h"); break;
				case 12: OStream->WriteString (OStream, "500 000 octet/h"); break;
				case 13: OStream->WriteString (OStream, "1 000 000 octet/h"); break;
				case 14: OStream->WriteString (OStream, "2 000 000 octet/h"); break;
				case 15: OStream->WriteString (OStream, "5 000 000 octet/h"); break;
				case 16: OStream->WriteString (OStream, "10 000 000 octet/h"); break;
				case 17: OStream->WriteString (OStream, "20 000 000 octet/h"); break;
				case 18: OStream->WriteString (OStream, "50 000 000 octet/h"); break;
				case 30: OStream->WriteString (OStream, "Reserved"); break;
				case 31: OStream->WriteString (OStream, "Best effort"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MeanThroughput");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "TrafficClass");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TrafficClass> ACCESS=<Data->TrafficClass>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TrafficClass)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed traffic class"); break;
				case 1: OStream->WriteString (OStream, "Conversational class"); break;
				case 2: OStream->WriteString (OStream, "Streaming class"); break;
				case 3: OStream->WriteString (OStream, "Interactive class"); break;
				case 4: OStream->WriteString (OStream, "Background class"); break;
				case 7: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "TrafficClass");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "DeliveryOrder");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DeliveryOrder> ACCESS=<Data->DeliveryOrder>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->DeliveryOrder)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed delivery order"); break;
				case 1: OStream->WriteString (OStream, "With delivery order ('yes')"); break;
				case 2: OStream->WriteString (OStream, "Without delivery order ('no')"); break;
				case 3: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "DeliveryOrder");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "DeliveryOfErroneusSDU");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DeliveryOfErroneusSDU> ACCESS=<Data->DeliveryOfErroneusSDU>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->DeliveryOfErroneusSDU)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed delivery of erroneous SDUs"); break;
				case 1: OStream->WriteString (OStream, "No detect ('-')"); break;
				case 2: OStream->WriteString (OStream, "Erroneous SDUs are delivered ('yes')"); break;
				case 3: OStream->WriteString (OStream, "Erroneous SDUs are not delivered ('no')"); break;
				case 7: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "DeliveryOfErroneusSDU");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumSDUSize");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumSDUSize> ACCESS=<Data->MaximumSDUSize>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MaximumSDUSize)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed maximum SDU size"); break;
				case 151: OStream->WriteString (OStream, "1502 octets"); break;
				case 152: OStream->WriteString (OStream, "1510 octets"); break;
				case 153: OStream->WriteString (OStream, "1520 octets"); break;
				case 255: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumSDUSize");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumBitRateForUplink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplink> ACCESS=<Data->MaximumBitRateForUplink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MaximumBitRateForUplink)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed maximum bit rate for uplink"); break;
				case 1: OStream->WriteString (OStream, "The maximum bit rate is binary coded in 8 bits, using a granularity of 1 kbps"); break;
				case 63: OStream->WriteString (OStream, "giving a range of values from 1 kbps to 63 kbps in 1 kbps increments."); break;
				case 64: OStream->WriteString (OStream, "The maximum bit rate is 64 kbps + ((the binary coded value in 8 bits -01000000) * 8 kbps)"); break;
				case 127: OStream->WriteString (OStream, "giving a range of values from 64 kbps to 568 kbps in 8 kbps increments."); break;
				case 128: OStream->WriteString (OStream, "The maximum bit rate is 576 kbps + ((the binary coded value in 8 bits -10000000) * 64 kbps)"); break;
				case 254: OStream->WriteString (OStream, "giving a range of values from 576 kbps to 8640 kbps in 64 kbps increments."); break;
				case 255: OStream->WriteString (OStream, "0 kbps"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumBitRateForUplink");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumBitRateForDownlink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlink> ACCESS=<Data->MaximumBitRateForDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MaximumBitRateForDownlink)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed maximum bit rate for uplink"); break;
				case 1: OStream->WriteString (OStream, "The maximum bit rate is binary coded in 8 bits, using a granularity of 1 kbps"); break;
				case 63: OStream->WriteString (OStream, "giving a range of values from 1 kbps to 63 kbps in 1 kbps increments."); break;
				case 64: OStream->WriteString (OStream, "The maximum bit rate is 64 kbps + ((the binary coded value in 8 bits -01000000) * 8 kbps)"); break;
				case 127: OStream->WriteString (OStream, "giving a range of values from 64 kbps to 568 kbps in 8 kbps increments."); break;
				case 128: OStream->WriteString (OStream, "The maximum bit rate is 576 kbps + ((the binary coded value in 8 bits -10000000) * 64 kbps)"); break;
				case 254: OStream->WriteString (OStream, "giving a range of values from 576 kbps to 8640 kbps in 64 kbps increments."); break;
				case 255: OStream->WriteString (OStream, "0 kbps"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumBitRateForDownlink");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "ResidualBER");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ResidualBER> ACCESS=<Data->ResidualBER>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ResidualBER)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Reserved"); break;
				case 1: OStream->WriteString (OStream, "5*10-2"); break;
				case 2: OStream->WriteString (OStream, "1*10-2"); break;
				case 3: OStream->WriteString (OStream, "5*10-3"); break;
				case 4: OStream->WriteString (OStream, "4*10-3"); break;
				case 5: OStream->WriteString (OStream, "1*10-3"); break;
				case 6: OStream->WriteString (OStream, "1*10-4"); break;
				case 7: OStream->WriteString (OStream, "1*10-5"); break;
				case 8: OStream->WriteString (OStream, "1*10-6"); break;
				case 9: OStream->WriteString (OStream, "6*10-8"); break;
				case 15: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "ResidualBER");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "SDUErrorRatio");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SDUErrorRatio> ACCESS=<Data->SDUErrorRatio>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SDUErrorRatio)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed SDU error ratio"); break;
				case 1: OStream->WriteString (OStream, "1*10-2"); break;
				case 2: OStream->WriteString (OStream, "7*10-3"); break;
				case 3: OStream->WriteString (OStream, "1*10-3"); break;
				case 4: OStream->WriteString (OStream, "1*10-4"); break;
				case 5: OStream->WriteString (OStream, "1*10-5"); break;
				case 6: OStream->WriteString (OStream, "1*10-6"); break;
				case 7: OStream->WriteString (OStream, "1*10-1"); break;
				case 15: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "SDUErrorRatio");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "TransderDelay");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TransderDelay> ACCESS=<Data->TransderDelay>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TransderDelay);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "TransderDelay");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "TrafficHandlingPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TrafficHandlingPriority> ACCESS=<Data->TrafficHandlingPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TrafficHandlingPriority)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Subscribed traffic handling priority"); break;
				case 1: OStream->WriteString (OStream, "Priority level 1"); break;
				case 2: OStream->WriteString (OStream, "Priority level 2"); break;
				case 3: OStream->WriteString (OStream, "Priority level 3"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "TrafficHandlingPriority");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "GuaranteedBitRateForUplink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplink> ACCESS=<Data->GuaranteedBitRateForUplink>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GuaranteedBitRateForUplink);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "GuaranteedBitRateForUplink");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "GuaranteedBitRateForDownlink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlink> ACCESS=<Data->GuaranteedBitRateForDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GuaranteedBitRateForDownlink);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "GuaranteedBitRateForDownlink");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "spare4");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ_spare4> NAME=<spare4> ACCESS=<Data->spare4>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "spare4");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "SignalingIndication");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SignalingIndication> ACCESS=<Data->SignalingIndication>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->SignalingIndication)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Not optimised for signalling traffic"); break;
				case 1: OStream->WriteString (OStream, "Optimised for signalling traffic"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "SignalingIndication");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "SourceStatisticsDescriptor");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SourceStatisticsDescriptor> ACCESS=<Data->SourceStatisticsDescriptor>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SourceStatisticsDescriptor)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "unknown"); break;
				case 1: OStream->WriteString (OStream, "speech"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "SourceStatisticsDescriptor");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumBitRateForDownlinkExt");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlinkExt> ACCESS=<Data->MaximumBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaximumBitRateForDownlinkExt);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumBitRateForDownlinkExt");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "GuaranteedBitRateForDownlinkExt");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlinkExt> ACCESS=<Data->GuaranteedBitRateForDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GuaranteedBitRateForDownlinkExt);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "GuaranteedBitRateForDownlinkExt");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumBitRateForUplinkExt");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplinkExt> ACCESS=<Data->MaximumBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaximumBitRateForUplinkExt);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumBitRateForUplinkExt");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "GuaranteedBitRateForUplinkExt");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplinkExt> ACCESS=<Data->GuaranteedBitRateForUplinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GuaranteedBitRateForUplinkExt);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "GuaranteedBitRateForUplinkExt");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumBitRateForDownlinkExt2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForDownlinkExt2> ACCESS=<Data->MaximumBitRateForDownlinkExt2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaximumBitRateForDownlinkExt2);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumBitRateForDownlinkExt2");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "GuaranteedBitRateForDownlinkExt2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForDownlinkExt2> ACCESS=<Data->GuaranteedBitRateForDownlinkExt2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GuaranteedBitRateForDownlinkExt2);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "GuaranteedBitRateForDownlinkExt2");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "MaximumBitRateForUplinkExt2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateForUplinkExt2> ACCESS=<Data->MaximumBitRateForUplinkExt2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MaximumBitRateForUplinkExt2);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "MaximumBitRateForUplinkExt2");
	ED_Dump_Struct_Begin_Field (OStream, "QualityOfServ", "GuaranteedBitRateForUplinkExt2");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GuaranteedBitRateForUplinkExt2> ACCESS=<Data->GuaranteedBitRateForUplinkExt2>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GuaranteedBitRateForUplinkExt2);
	ED_Dump_Struct_End_Field (OStream, "QualityOfServ", "GuaranteedBitRateForUplinkExt2");
	ED_Dump_Struct_End (OStream, "QualityOfServ");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ReAttemptIndicator (TEDOStream* OStream, const c_ReAttemptIndicator* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "ReAttemptIndicator", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_ReAttemptIndicator_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ReAttemptIndicator", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "ReAttemptIndicator", "EPLMNC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EPLMNC> ACCESS=<Data->EPLMNC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EPLMNC);
	ED_Dump_Struct_End_Field (OStream, "ReAttemptIndicator", "EPLMNC");
	ED_Dump_Struct_Begin_Field (OStream, "ReAttemptIndicator", "RATC");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<RATC> ACCESS=<Data->RATC>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->RATC);
	ED_Dump_Struct_End_Field (OStream, "ReAttemptIndicator", "RATC");
	ED_Dump_Struct_End (OStream, "ReAttemptIndicator");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SMCause (TEDOStream* OStream, const c_SMCause* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SMCause");
	ED_Dump_Struct_Begin_Field (OStream, "SMCause", "Cause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Cause)
		{
			switch (DATA) {
				case 8: OStream->WriteString (OStream, "Operator Determined Barring"); break;
				case 24: OStream->WriteString (OStream, "MBMS bearer capabilities insufficient for the service"); break;
				case 25: OStream->WriteString (OStream, "LLC or SNDCP failure(A/Gb mode only)"); break;
				case 26: OStream->WriteString (OStream, "Insufficient resources"); break;
				case 27: OStream->WriteString (OStream, "Missing or unknown APN"); break;
				case 28: OStream->WriteString (OStream, "Unknown PDP address or PDP type"); break;
				case 29: OStream->WriteString (OStream, "User authentication failed"); break;
				case 30: OStream->WriteString (OStream, "Activation rejected by GGSN, Serving GW or PDN GW"); break;
				case 31: OStream->WriteString (OStream, "Activation rejected, unspecified"); break;
				case 32: OStream->WriteString (OStream, "Service option not supported"); break;
				case 33: OStream->WriteString (OStream, "Requested service option not subscribed"); break;
				case 34: OStream->WriteString (OStream, "Service option temporarily out of order"); break;
				case 35: OStream->WriteString (OStream, "NSAPI already used (not sent)"); break;
				case 36: OStream->WriteString (OStream, "Regular deactivation"); break;
				case 37: OStream->WriteString (OStream, "QoS not accepted"); break;
				case 38: OStream->WriteString (OStream, "Network failure"); break;
				case 39: OStream->WriteString (OStream, "Reactivation requested"); break;
				case 40: OStream->WriteString (OStream, "Feature not supported"); break;
				case 41: OStream->WriteString (OStream, "Semantic error in the TFT operation"); break;
				case 42: OStream->WriteString (OStream, "Syntactical error in the TFT operation"); break;
				case 43: OStream->WriteString (OStream, "Unknown PDP context"); break;
				case 44: OStream->WriteString (OStream, "Semantic errors in packet filter(s)"); break;
				case 45: OStream->WriteString (OStream, "Syntactical errors in packet filter(s)"); break;
				case 46: OStream->WriteString (OStream, "PDP context without TFT already activated"); break;
				case 47: OStream->WriteString (OStream, "Multicast group membership time-out"); break;
				case 48: OStream->WriteString (OStream, "Request rejected, BCM violation"); break;
				case 50: OStream->WriteString (OStream, "PDP type IPv4 only allowed"); break;
				case 51: OStream->WriteString (OStream, "PDP type IPv6 only allowed"); break;
				case 52: OStream->WriteString (OStream, "Single address bearers only allowed"); break;
				case 56: OStream->WriteString (OStream, "Collision with network initiated request"); break;
				case 60: OStream->WriteString (OStream, "Bearer handling not supported"); break;
				case 65: OStream->WriteString (OStream, "Maximum number of PDP contexts reached"); break;
				case 66: OStream->WriteString (OStream, "Requested APN not supported in current RAT and PLMN combination"); break;
				case 81: OStream->WriteString (OStream, "Invalid transaction identifier value"); break;
				case 95: OStream->WriteString (OStream, "Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "Message type not compatible with the protocol state"); break;
				case 99: OStream->WriteString (OStream, "Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "Message not compatible with the protocol state"); break;
				case 111: OStream->WriteString (OStream, "Protocol error, unspecified"); break;
				case 112: OStream->WriteString (OStream, "APN restriction value incompatible with active PDP context"); break;
				case 113: OStream->WriteString (OStream, "Multiple accesses to a PDN connection not allowed"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "SMCause", "Cause");
	ED_Dump_Struct_End (OStream, "SMCause");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LlcServAccessPointId (TEDOStream* OStream, const c_LlcServAccessPointId* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LlcServAccessPointId");
	ED_Dump_Struct_Begin_Field (OStream, "LlcServAccessPointId", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "LlcServAccessPointId", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "LlcServAccessPointId", "LLCSAPIValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LLCSAPIValue> ACCESS=<Data->LLCSAPIValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->LLCSAPIValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "LLC SAPI not assigned"); break;
				case 3: OStream->WriteString (OStream, "SAPI 3"); break;
				case 5: OStream->WriteString (OStream, "SAPI 5"); break;
				case 9: OStream->WriteString (OStream, "SAPI 9"); break;
				case 11: OStream->WriteString (OStream, "SAPI 11"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "LlcServAccessPointId", "LLCSAPIValue");
	ED_Dump_Struct_End (OStream, "LlcServAccessPointId");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TearDownInd (TEDOStream* OStream, const c_TearDownInd* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TearDownInd");
	ED_Dump_Struct_Begin_Field (OStream, "TearDownInd", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_TearDownInd_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "TearDownInd", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "TearDownInd", "TDIFlag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TDIFlag> ACCESS=<Data->TDIFlag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->TDIFlag)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "tear down not requested"); break;
				case 1: OStream->WriteString (OStream, "tear down requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TearDownInd", "TDIFlag");
	ED_Dump_Struct_End (OStream, "TearDownInd");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PacketFlowIdentifie (TEDOStream* OStream, const c_PacketFlowIdentifie* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PacketFlowIdentifie");
	ED_Dump_Struct_Begin_Field (OStream, "PacketFlowIdentifie", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_PacketFlowIdentifie_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "PacketFlowIdentifie", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "PacketFlowIdentifie", "PacketFlowIdentifierValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PacketFlowIdentifierValue> ACCESS=<Data->PacketFlowIdentifierValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PacketFlowIdentifierValue)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Best Effort"); break;
				case 1: OStream->WriteString (OStream, "Signaling"); break;
				case 2: OStream->WriteString (OStream, "SMS"); break;
				case 3: OStream->WriteString (OStream, "TOM8"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "PacketFlowIdentifie", "PacketFlowIdentifierValue");
	ED_Dump_Struct_End (OStream, "PacketFlowIdentifie");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TempMobileGroupId (TEDOStream* OStream, const c_TempMobileGroupId* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TempMobileGroupId");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileGroupId", "MBMSServiceId");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<MBMSServiceId> ACCESS=<Data->MBMSServiceId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MBMSServiceId);
	ED_Dump_Struct_End_Field (OStream, "TempMobileGroupId", "MBMSServiceId");
	ED_Dump_Struct_Begin_Field (OStream, "TempMobileGroupId", "Numbers");
	  /* STRUCTURAL=<0> TYPE=<c_TempMobileNumbers> NAME=<Numbers> ACCESS=<Data->Numbers>  OPTIONAL=<0> FUNC=<Dump_c_TempMobileNumbers> */
	  Dump_c_TempMobileNumbers (OStream, &(Data->Numbers));
	ED_Dump_Struct_End_Field (OStream, "TempMobileGroupId", "Numbers");
	ED_Dump_Struct_End (OStream, "TempMobileGroupId");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MBMSBearerCapabilities (TEDOStream* OStream, const c_MBMSBearerCapabilities* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MBMSBearerCapabilities");
	ED_Dump_Struct_Begin_Field (OStream, "MBMSBearerCapabilities", "MaximumBitRateDownlink");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateDownlink> ACCESS=<Data->MaximumBitRateDownlink>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MaximumBitRateDownlink);
	ED_Dump_Struct_End_Field (OStream, "MBMSBearerCapabilities", "MaximumBitRateDownlink");
	ED_Dump_Struct_Begin_Field (OStream, "MBMSBearerCapabilities", "MaximumBitRateDownlinkExt");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaximumBitRateDownlinkExt> ACCESS=<Data->MaximumBitRateDownlinkExt>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MaximumBitRateDownlinkExt);
	ED_Dump_Struct_End_Field (OStream, "MBMSBearerCapabilities", "MaximumBitRateDownlinkExt");
	ED_Dump_Struct_End (OStream, "MBMSBearerCapabilities");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_WLANOffloadAcceptability (TEDOStream* OStream, const c_WLANOffloadAcceptability* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "WLANOffloadAcceptability");
	ED_Dump_Struct_Begin_Field (OStream, "WLANOffloadAcceptability", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "WLANOffloadAcceptability", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "WLANOffloadAcceptability", "UTRANOffloadAcceptabilityValue");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRANOffloadAcceptabilityValue> ACCESS=<Data->UTRANOffloadAcceptabilityValue>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UTRANOffloadAcceptabilityValue);
	ED_Dump_Struct_End_Field (OStream, "WLANOffloadAcceptability", "UTRANOffloadAcceptabilityValue");
	ED_Dump_Struct_Begin_Field (OStream, "WLANOffloadAcceptability", "EUTRANOffloadAcceptabilityValue");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EUTRANOffloadAcceptabilityValue> ACCESS=<Data->EUTRANOffloadAcceptabilityValue>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EUTRANOffloadAcceptabilityValue);
	ED_Dump_Struct_End_Field (OStream, "WLANOffloadAcceptability", "EUTRANOffloadAcceptabilityValue");
	ED_Dump_Struct_End (OStream, "WLANOffloadAcceptability");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GprsTimer (TEDOStream* OStream, const c_GprsTimer* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GprsTimer");
	ED_Dump_Struct_Begin_Field (OStream, "GprsTimer", "Unit");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Unit> ACCESS=<Data->Unit>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Unit)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "value is incremented in multiples of 2 seconds"); break;
				case 1: OStream->WriteString (OStream, "value is incremented in multiples of 1 minute"); break;
				case 2: OStream->WriteString (OStream, "value is incremented in multiples of decihours"); break;
				case 7: OStream->WriteString (OStream, "value indicates that the timer is deactivated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "GprsTimer", "Unit");
	ED_Dump_Struct_Begin_Field (OStream, "GprsTimer", "TimerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimerValue> ACCESS=<Data->TimerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimerValue);
	ED_Dump_Struct_End_Field (OStream, "GprsTimer", "TimerValue");
	ED_Dump_Struct_End (OStream, "GprsTimer");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GprsTimer2 (TEDOStream* OStream, const c_GprsTimer2* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GprsTimer2");
	ED_Dump_Struct_Begin_Field (OStream, "GprsTimer2", "Unit");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Unit> ACCESS=<Data->Unit>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Unit)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "value is incremented in multiples of 2 seconds"); break;
				case 1: OStream->WriteString (OStream, "value is incremented in multiples of 1 minute"); break;
				case 2: OStream->WriteString (OStream, "value is incremented in multiples of decihours"); break;
				case 7: OStream->WriteString (OStream, "value indicates that the timer is deactivated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "GprsTimer2", "Unit");
	ED_Dump_Struct_Begin_Field (OStream, "GprsTimer2", "TimerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimerValue> ACCESS=<Data->TimerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimerValue);
	ED_Dump_Struct_End_Field (OStream, "GprsTimer2", "TimerValue");
	ED_Dump_Struct_End (OStream, "GprsTimer2");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GprsTimer3 (TEDOStream* OStream, const c_GprsTimer3* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GprsTimer3");
	ED_Dump_Struct_Begin_Field (OStream, "GprsTimer3", "Unit");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Unit> ACCESS=<Data->Unit>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Unit)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "value is incremented in multiples of 10 minutes"); break;
				case 1: OStream->WriteString (OStream, "value is incremented in multiples of 1 hour"); break;
				case 2: OStream->WriteString (OStream, "value is incremented in multiples of 10 hours"); break;
				case 3: OStream->WriteString (OStream, "value is incremented in multiples of 2 seconds"); break;
				case 4: OStream->WriteString (OStream, "value is incremented in multiples of 30 seconds"); break;
				case 5: OStream->WriteString (OStream, "value is incremented in multiples of 1 minute"); break;
				case 6: OStream->WriteString (OStream, "value is incremented in multiples of 320 hours"); break;
				case 7: OStream->WriteString (OStream, "value indicates that the timer is deactivated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "GprsTimer3", "Unit");
	ED_Dump_Struct_Begin_Field (OStream, "GprsTimer3", "TimerValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TimerValue> ACCESS=<Data->TimerValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TimerValue);
	ED_Dump_Struct_End_Field (OStream, "GprsTimer3", "TimerValue");
	ED_Dump_Struct_End (OStream, "GprsTimer3");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_UplinkDataStatus (TEDOStream* OStream, const c_UplinkDataStatus* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "UplinkDataStatus");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_07");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_07> ACCESS=<Data->NSAPI_07>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_07);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_07");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_06");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_06> ACCESS=<Data->NSAPI_06>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_06);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_06");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_05");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_05> ACCESS=<Data->NSAPI_05>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_05);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_05");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "spare1");
	  /* STRUCTURAL=<0> TYPE=<c_UplinkDataStatus_spare1> NAME=<spare1> ACCESS=<Data->spare1>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "spare1");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_15");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_15> ACCESS=<Data->NSAPI_15>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_15);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_15");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_14");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_14> ACCESS=<Data->NSAPI_14>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_14);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_14");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_13");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_13> ACCESS=<Data->NSAPI_13>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_13);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_13");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_12");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_12> ACCESS=<Data->NSAPI_12>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_12);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_12");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_11");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_11> ACCESS=<Data->NSAPI_11>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_11);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_11");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_10");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_10> ACCESS=<Data->NSAPI_10>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_10);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_10");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_09");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_09> ACCESS=<Data->NSAPI_09>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_09);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_09");
	ED_Dump_Struct_Begin_Field (OStream, "UplinkDataStatus", "NSAPI_08");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NSAPI_08> ACCESS=<Data->NSAPI_08>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NSAPI_08);
	ED_Dump_Struct_End_Field (OStream, "UplinkDataStatus", "NSAPI_08");
	ED_Dump_Struct_End (OStream, "UplinkDataStatus");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DeviceProperties (TEDOStream* OStream, const c_DeviceProperties* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "DeviceProperties", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "DeviceProperties", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "DeviceProperties", "LowPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LowPriority> ACCESS=<Data->LowPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->LowPriority);
	ED_Dump_Struct_End_Field (OStream, "DeviceProperties", "LowPriority");
	ED_Dump_Struct_End (OStream, "DeviceProperties");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ASCII (TEDOStream* OStream, const c_ASCII* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ASCII");
	ED_Dump_Struct_Begin_Field (OStream, "ASCII", "text");
	  /* NAME=<text> ACCESS=<Data->text>  MAXBITSIZE=<800> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->text.value, Data->text.usedBits);
	ED_Dump_Struct_End_Field (OStream, "ASCII", "text");
	ED_Dump_Struct_End (OStream, "ASCII");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_BackupBearerCapability (TEDOStream* OStream, const c_BackupBearerCapability* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "BackupBearerCapability");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "RadioChannelRequirement");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioChannelRequirement> ACCESS=<Data->RadioChannelRequirement>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioChannelRequirement);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "RadioChannelRequirement");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "CodingStd");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CodingStd> ACCESS=<Data->CodingStd>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->CodingStd)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "GSM standardized coding as described below"); break;
				case 1: OStream->WriteString (OStream, "reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "CodingStd");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "TransferMode");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TransferMode> ACCESS=<Data->TransferMode>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->TransferMode)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "circuit mode"); break;
				case 1: OStream->WriteString (OStream, "packet mode"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "TransferMode");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "InformationTransferCapability");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<InformationTransferCapability> ACCESS=<Data->InformationTransferCapability>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->InformationTransferCapability)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "speech"); break;
				case 1: OStream->WriteString (OStream, "unrestricted digital information"); break;
				case 2: OStream->WriteString (OStream, "3.1 kHz audio, ex PLMN"); break;
				case 3: OStream->WriteString (OStream, "facsimile group 3"); break;
				case 5: OStream->WriteString (OStream, "Other ITC (See Octet 5a)"); break;
				case 7: OStream->WriteString (OStream, "reserved, to be used in the network."); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "InformationTransferCapability");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Compress");
	if (!Data->Compress_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Compress> ACCESS=<Data->Compress>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Compress);
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Compress");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Structure");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Structure> ACCESS=<Data->Structure>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Structure)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "service data unit integrity"); break;
				case 3: OStream->WriteString (OStream, "unstructured"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Structure");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "DuplMode");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DuplMode> ACCESS=<Data->DuplMode>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->DuplMode)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "half duplex"); break;
				case 1: OStream->WriteString (OStream, "full duplex"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "DuplMode");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Configured");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Configured> ACCESS=<Data->Configured>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Configured);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Configured");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "NIRR");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NIRR> ACCESS=<Data->NIRR>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NIRR);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "NIRR");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Established");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Established> ACCESS=<Data->Established>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Established);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Established");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "AccessId");
	if (!Data->AccessId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BackupBearerCapability_AccessId> NAME=<AccessId> ACCESS=<Data->AccessId>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "AccessId");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "RateAdaption");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RateAdaption> ACCESS=<Data->RateAdaption>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RateAdaption)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no rate adaption"); break;
				case 1: OStream->WriteString (OStream, "V.110, I.460/X.30 rate adaptation"); break;
				case 2: OStream->WriteString (OStream, "ITU-T X.31 flag stuffing"); break;
				case 3: OStream->WriteString (OStream, "Other rate adaption (see octet 5a)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "RateAdaption");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "SignallinAccessProtocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SignallinAccessProtocol> ACCESS=<Data->SignallinAccessProtocol>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->SignallinAccessProtocol)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "I.440/450"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "SignallinAccessProtocol");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "OtherITC");
	if (!Data->OtherITC_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OtherITC> ACCESS=<Data->OtherITC>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->OtherITC)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "restricted digital information"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "OtherITC");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "OtherRateAdaption");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OtherRateAdaption> ACCESS=<Data->OtherRateAdaption>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->OtherRateAdaption)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "V.120"); break;
				case 1: OStream->WriteString (OStream, "H.223 & H.245"); break;
				case 2: OStream->WriteString (OStream, "PIAFS"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "OtherRateAdaption");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "spare5a");
	  /* STRUCTURAL=<0> TYPE=<c_BackupBearerCapability_spare5a> NAME=<spare5a> ACCESS=<Data->spare5a>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "spare5a");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Layer1id");
	if (!Data->Layer1id_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BackupBearerCapability_Layer1id> NAME=<Layer1id> ACCESS=<Data->Layer1id>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Layer1id");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "UserInfoLayer1Protocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UserInfoLayer1Protocol> ACCESS=<Data->UserInfoLayer1Protocol>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->UserInfoLayer1Protocol);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "UserInfoLayer1Protocol");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Asynchronous");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Asynchronous> ACCESS=<Data->Asynchronous>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Asynchronous)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "synchronous"); break;
				case 1: OStream->WriteString (OStream, "asynchronous"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Asynchronous");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "NumbStopBits");
	if (!Data->NumbStopBits_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumbStopBits> ACCESS=<Data->NumbStopBits>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NumbStopBits)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "2 bits"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "NumbStopBits");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Negotiations");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Negotiations> ACCESS=<Data->Negotiations>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->Negotiations)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "in-band negotiation not possible"); break;
				case 1: OStream->WriteString (OStream, "in-band negotiation possible"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Negotiations");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "NumbDataBits");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NumbDataBits> ACCESS=<Data->NumbDataBits>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NumbDataBits)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "7 bits"); break;
				case 1: OStream->WriteString (OStream, "8 bits (this value is also used in the case of bit oriented protocols)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "NumbDataBits");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "UserRate");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UserRate> ACCESS=<Data->UserRate>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UserRate)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "User rate unknown"); break;
				case 2: OStream->WriteString (OStream, ".3 kbit/s Recommendation X.1 and V.110"); break;
				case 3: OStream->WriteString (OStream, "2.4 kbit/s Recommendation X.1 and V.110"); break;
				case 4: OStream->WriteString (OStream, "4.8 kbit/s Recommendation X.1 and V.110"); break;
				case 5: OStream->WriteString (OStream, "9.6 kbit/s Recommendation X.1 and V.110"); break;
				case 7: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol."); break;
				case 13: OStream->WriteString (OStream, "2.0 kbit/s transparent (non compliance with X.1 and V.110)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "UserRate");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "IntermedRate");
	if (!Data->IntermedRate_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IntermedRate> ACCESS=<Data->IntermedRate>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->IntermedRate)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "reserved"); break;
				case 1: OStream->WriteString (OStream, "reserved"); break;
				case 2: OStream->WriteString (OStream, "8 kbit/s"); break;
				case 7: OStream->WriteString (OStream, "6 kbit/s"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "IntermedRate");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "NIConTX");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NIConTX> ACCESS=<Data->NIConTX>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NIConTX)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "does not require to send data with network independent clock"); break;
				case 1: OStream->WriteString (OStream, "requires to send data with network independent clock"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "NIConTX");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "NIConRX");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NIConRX> ACCESS=<Data->NIConRX>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->NIConRX)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "cannot accept data with network independent clock (i.e. sender does not 	support this optional procedure)"); break;
				case 1: OStream->WriteString (OStream, "can accept data with network independent clock (i.e. sender does support this 	optional procedure)"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "NIConRX");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Parity");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Parity> ACCESS=<Data->Parity>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Parity)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "odd"); break;
				case 2: OStream->WriteString (OStream, "even"); break;
				case 3: OStream->WriteString (OStream, "none"); break;
				case 4: OStream->WriteString (OStream, "forced to 0"); break;
				case 5: OStream->WriteString (OStream, "forced to 1"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Parity");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "ConnectionElement");
	if (!Data->ConnectionElement_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ConnectionElement> ACCESS=<Data->ConnectionElement>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ConnectionElement)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "transparent"); break;
				case 1: OStream->WriteString (OStream, "non transparent (RLP)"); break;
				case 2: OStream->WriteString (OStream, "both, transparent preferred"); break;
				case 3: OStream->WriteString (OStream, "both, non transparent preferred"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "ConnectionElement");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "ModemType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ModemType> ACCESS=<Data->ModemType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ModemType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "none"); break;
				case 1: OStream->WriteString (OStream, "V.21 (note 1)"); break;
				case 2: OStream->WriteString (OStream, "V.22 (note 1)"); break;
				case 3: OStream->WriteString (OStream, "V.22 bis (note 1)"); break;
				case 4: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 5: OStream->WriteString (OStream, "V.26 ter (note 1)"); break;
				case 6: OStream->WriteString (OStream, "V.32"); break;
				case 7: OStream->WriteString (OStream, "modem for undefined interface"); break;
				case 8: OStream->WriteString (OStream, "autobauding type 1"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "ModemType");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "OtherModemType");
	if (!Data->OtherModemType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<OtherModemType> ACCESS=<Data->OtherModemType>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->OtherModemType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "no other modem type specified in this field"); break;
				case 2: OStream->WriteString (OStream, "V.34"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "OtherModemType");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "FixedNetworkUserRate");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<FixedNetworkUserRate> ACCESS=<Data->FixedNetworkUserRate>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->FixedNetworkUserRate)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Fixed network user rate not applicable/No meaning is associated with this value."); break;
				case 1: OStream->WriteString (OStream, "9.6 kbit/s Recommendation X.1 and V.110"); break;
				case 4: OStream->WriteString (OStream, "28.8 kbit/s Recommendation X.1 and V.110"); break;
				case 5: OStream->WriteString (OStream, "38.4 kbit/s Recommendation X.1 and V.110"); break;
				case 6: OStream->WriteString (OStream, "48.0 kbit/s Recommendation X.1 and V.110(synch) (note 1)"); break;
				case 7: OStream->WriteString (OStream, "56.0 kbit/s Recommendation X.1 and V.110(synch) /bit transparent"); break;
				case 8: OStream->WriteString (OStream, "64.0 kbit/s bit transparent"); break;
				case 9: OStream->WriteString (OStream, "33.6 kbit/s bit transparent"); break;
				case 10: OStream->WriteString (OStream, "32.0 kbit/s Recommendation I.460"); break;
				case 11: OStream->WriteString (OStream, "31.2 kbit/s Recommendation V.34"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "FixedNetworkUserRate");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "AcceptableChannelCodings");
	if (!Data->AcceptableChannelCodings_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AcceptableChannelCodings> ACCESS=<Data->AcceptableChannelCodings>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->AcceptableChannelCodings);
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "AcceptableChannelCodings");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "MaxNumOfTrafficChannels");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MaxNumOfTrafficChannels> ACCESS=<Data->MaxNumOfTrafficChannels>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MaxNumOfTrafficChannels);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "MaxNumOfTrafficChannels");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "UIMI");
	if (!Data->UIMI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UIMI> ACCESS=<Data->UIMI>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->UIMI)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "User initiated modification not allowed/applicable"); break;
				case 1: OStream->WriteString (OStream, "User initiated modification up to 1 TCH/F allowed/may be requested"); break;
				case 2: OStream->WriteString (OStream, "User initiated modification up to 2 TCH/F allowed/may be requested"); break;
				case 3: OStream->WriteString (OStream, "User initiated modification up to 3 TCH/F allowed/may be requested"); break;
				case 4: OStream->WriteString (OStream, "User initiated modification up to 4 TCH/F allowed/may be requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "UIMI");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "WantedAirInterfUserRate");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<WantedAirInterfUserRate> ACCESS=<Data->WantedAirInterfUserRate>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->WantedAirInterfUserRate);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "WantedAirInterfUserRate");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "AcceptableChCodingsExt");
	if (!Data->AcceptableChCodingsExt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AcceptableChCodingsExt> ACCESS=<Data->AcceptableChCodingsExt>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->AcceptableChCodingsExt);
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "AcceptableChCodingsExt");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "AsymmetryInd");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<AsymmetryInd> ACCESS=<Data->AsymmetryInd>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->AsymmetryInd);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "AsymmetryInd");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "spare6g");
	  /* STRUCTURAL=<0> TYPE=<c_BackupBearerCapability_spare6g> NAME=<spare6g> ACCESS=<Data->spare6g>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "spare6g");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "Layer2id");
	if (!Data->Layer2id_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BackupBearerCapability_Layer2id> NAME=<Layer2id> ACCESS=<Data->Layer2id>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "Layer2id");
	ED_Dump_Struct_Begin_Field (OStream, "BackupBearerCapability", "USerInfoLayer2Protocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<USerInfoLayer2Protocol> ACCESS=<Data->USerInfoLayer2Protocol>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->USerInfoLayer2Protocol)
		{
			switch (DATA) {
				case 6: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				case 8: OStream->WriteString (OStream, "ISO 6429, codeset 0 (DC1/DC3)"); break;
				case 9: OStream->WriteString (OStream, "reserved: was allocated but never used in earlier phases of the protocol"); break;
				case 10: OStream->WriteString (OStream, "videotex profile 1"); break;
				case 12: OStream->WriteString (OStream, "COPnoFlCt (Character oriented Protocol with no Flow Control mechanism)"); break;
				case 13: OStream->WriteString (OStream, "reserved: was allocated in earlier phases of the protocol"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "BackupBearerCapability", "USerInfoLayer2Protocol");
	ED_Dump_Struct_End (OStream, "BackupBearerCapability");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CallingPartyBcdNum (TEDOStream* OStream, const c_CallingPartyBcdNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CallingPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartyBcdNum", "TypeOfNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfNumber> ACCESS=<Data->TypeOfNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TypeOfNumber)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "unknown"); break;
				case 1: OStream->WriteString (OStream, "international number"); break;
				case 2: OStream->WriteString (OStream, "national number"); break;
				case 3: OStream->WriteString (OStream, "network specific number"); break;
				case 4: OStream->WriteString (OStream, "dedicated access, short code"); break;
				case 5: OStream->WriteString (OStream, "reserved"); break;
				case 6: OStream->WriteString (OStream, "reserved"); break;
				case 7: OStream->WriteString (OStream, "reserved for extension"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallingPartyBcdNum", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartyBcdNum", "NumberingPlanIdent");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumberingPlanIdent> ACCESS=<Data->NumberingPlanIdent>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NumberingPlanIdent)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "unknown"); break;
				case 1: OStream->WriteString (OStream, "ISDN/telephony numbering plan (Rec. E.164/E.163)"); break;
				case 3: OStream->WriteString (OStream, "data numbering plan (Recommendation X.121)"); break;
				case 4: OStream->WriteString (OStream, "telex numbering plan (Recommendation F.69)"); break;
				case 8: OStream->WriteString (OStream, "national numbering plan"); break;
				case 9: OStream->WriteString (OStream, "private numbering plan"); break;
				case 11: OStream->WriteString (OStream, "reserved for CTS (see 3GPP TS 44.056 [91])"); break;
				case 15: OStream->WriteString (OStream, "reserved for extension"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallingPartyBcdNum", "NumberingPlanIdent");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartyBcdNum", "PresentationIndicator");
	if (!Data->PresentationIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PresentationIndicator> ACCESS=<Data->PresentationIndicator>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PresentationIndicator)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Presentation allowed"); break;
				case 1: OStream->WriteString (OStream, "Presentation restricted"); break;
				case 2: OStream->WriteString (OStream, "Number not available due to interworking"); break;
				case 3: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "CallingPartyBcdNum", "PresentationIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartyBcdNum", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_CallingPartyBcdNum_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "CallingPartyBcdNum", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartyBcdNum", "ScreeningIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ScreeningIndicator> ACCESS=<Data->ScreeningIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ScreeningIndicator)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "User-provided, not screened"); break;
				case 1: OStream->WriteString (OStream, "User-provided, verified and passed"); break;
				case 2: OStream->WriteString (OStream, "User-provided, verified and failed"); break;
				case 3: OStream->WriteString (OStream, "Network provided"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CallingPartyBcdNum", "ScreeningIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "CallingPartyBcdNum", "Number");
	  /* STRUCTURAL=<0> TYPE=<c_TBCDArray> NAME=<Number> ACCESS=<Data->Number>  OPTIONAL=<0> FUNC=<Dump_c_TBCDArray> */
	  Dump_c_TBCDArray (OStream, &(Data->Number));
	ED_Dump_Struct_End_Field (OStream, "CallingPartyBcdNum", "Number");
	ED_Dump_Struct_End (OStream, "CallingPartyBcdNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_Cause (TEDOStream* OStream, const c_Cause* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "Cause", "CodingStandard");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CodingStandard> ACCESS=<Data->CodingStandard>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CodingStandard)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Coding as specified in ITU-T Rec. Q.931"); break;
				case 1: OStream->WriteString (OStream, "Reserved for other international standards"); break;
				case 2: OStream->WriteString (OStream, "National standard"); break;
				case 3: OStream->WriteString (OStream, "Standard defined for the GSM PLMNs as described below and in table 10.5.123/3GPP TS 24.008"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "Cause", "CodingStandard");
	ED_Dump_Struct_Begin_Field (OStream, "Cause", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_Cause_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "Cause", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "Cause", "Location");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Location> ACCESS=<Data->Location>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Location)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "user"); break;
				case 1: OStream->WriteString (OStream, "private network serving the local user"); break;
				case 2: OStream->WriteString (OStream, "public network serving the local user"); break;
				case 3: OStream->WriteString (OStream, "transit network"); break;
				case 4: OStream->WriteString (OStream, "public network serving the remote user"); break;
				case 5: OStream->WriteString (OStream, "private network serving the remote user"); break;
				case 7: OStream->WriteString (OStream, "international network"); break;
				case 10: OStream->WriteString (OStream, "network beyond interworking point"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "Cause", "Location");
	ED_Dump_Struct_Begin_Field (OStream, "Cause", "Recommendation");
	if (!Data->Recommendation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Recommendation> ACCESS=<Data->Recommendation>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->Recommendation);
	}
	ED_Dump_Struct_End_Field (OStream, "Cause", "Recommendation");
	ED_Dump_Struct_Begin_Field (OStream, "Cause", "CauseValue");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CauseValue> ACCESS=<Data->CauseValue>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CauseValue)
		{
			switch (DATA) {
				case 3: OStream->WriteString (OStream, "3. No route to destination"); break;
				case 6: OStream->WriteString (OStream, "6. Channel unacceptable"); break;
				case 8: OStream->WriteString (OStream, "8. Operator determined barring"); break;
				case 16: OStream->WriteString (OStream, "16. Normal call clearing"); break;
				case 17: OStream->WriteString (OStream, "17. User busy"); break;
				case 18: OStream->WriteString (OStream, "18. No user responding"); break;
				case 19: OStream->WriteString (OStream, "19. User alerting, no answer"); break;
				case 21: OStream->WriteString (OStream, "21. Call rejected"); break;
				case 22: OStream->WriteString (OStream, "22. Number changed"); break;
				case 24: OStream->WriteString (OStream, "24. Call rejected due to feature at the destination"); break;
				case 25: OStream->WriteString (OStream, "25. Pre-emption"); break;
				case 26: OStream->WriteString (OStream, "26. Non selected user clearing"); break;
				case 27: OStream->WriteString (OStream, "27. Destination out of order"); break;
				case 28: OStream->WriteString (OStream, "28. Invalid number format (incomplete number)"); break;
				case 29: OStream->WriteString (OStream, "29. Facility rejected"); break;
				case 30: OStream->WriteString (OStream, "30. Response to STATUS ENQUIRY"); break;
				case 31: OStream->WriteString (OStream, "31. Normal, unspecified"); break;
				case 34: OStream->WriteString (OStream, "34. No circuit/channel available"); break;
				case 38: OStream->WriteString (OStream, "38. Network out of order"); break;
				case 41: OStream->WriteString (OStream, "41. Temporary failure"); break;
				case 42: OStream->WriteString (OStream, "42. Switching equipment congestion"); break;
				case 43: OStream->WriteString (OStream, "43. Access information discarded"); break;
				case 44: OStream->WriteString (OStream, "44. requested circuit/channel not available"); break;
				case 47: OStream->WriteString (OStream, "47. Resources unavailable, unspecified"); break;
				case 49: OStream->WriteString (OStream, "49. Quality of service unavailable"); break;
				case 50: OStream->WriteString (OStream, "50. Requested facility not subscribed"); break;
				case 55: OStream->WriteString (OStream, "55. Incoming calls barred within the CUG"); break;
				case 57: OStream->WriteString (OStream, "57. Bearer capability not authorized"); break;
				case 58: OStream->WriteString (OStream, "58. Bearer capability not presently available"); break;
				case 63: OStream->WriteString (OStream, "63. Service or option not available, unspecified"); break;
				case 65: OStream->WriteString (OStream, "65. Bearer service not implemented"); break;
				case 68: OStream->WriteString (OStream, "68. ACM equal to or greater than ACMmax"); break;
				case 69: OStream->WriteString (OStream, "69. Requested facility not implemented"); break;
				case 70: OStream->WriteString (OStream, "70. Only restricted digital information bearer capability is available"); break;
				case 79: OStream->WriteString (OStream, "79. Service or option not implemented, unspecified"); break;
				case 81: OStream->WriteString (OStream, "81. Invalid transaction identifier value"); break;
				case 87: OStream->WriteString (OStream, "87. User not member of CUG"); break;
				case 88: OStream->WriteString (OStream, "88. Incompatible destination"); break;
				case 91: OStream->WriteString (OStream, "91. Invalid transit network selection"); break;
				case 95: OStream->WriteString (OStream, "95. Semantically incorrect message"); break;
				case 96: OStream->WriteString (OStream, "96. Invalid mandatory information"); break;
				case 97: OStream->WriteString (OStream, "97. Message type non-existent or not implemented"); break;
				case 98: OStream->WriteString (OStream, "98. Message type not compatible with protocol state"); break;
				case 99: OStream->WriteString (OStream, "99. Information element non-existent or not implemented"); break;
				case 100: OStream->WriteString (OStream, "100. Conditional IE error"); break;
				case 101: OStream->WriteString (OStream, "101. Message not compatible with protocol state"); break;
				case 102: OStream->WriteString (OStream, "102. Recovery on timer expiry"); break;
				case 111: OStream->WriteString (OStream, "111. Protocol error, unspecified"); break;
				case 127: OStream->WriteString (OStream, "127. Interworking, unspecified"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "Cause", "CauseValue");
	ED_Dump_Struct_Begin_Field (OStream, "Cause", "diagnostic");
	  /* NAME=<diagnostic> ACCESS=<Data->diagnostic>  MAXBITSIZE=<239> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->diagnostic.value, Data->diagnostic.usedBits);
	ED_Dump_Struct_End_Field (OStream, "Cause", "diagnostic");
	ED_Dump_Struct_End (OStream, "Cause");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ConnNum (TEDOStream* OStream, const c_ConnNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ConnNum");
	ED_Dump_Struct_Begin_Field (OStream, "ConnNum", "TypeOfNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfNumber> ACCESS=<Data->TypeOfNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TypeOfNumber);
	ED_Dump_Struct_End_Field (OStream, "ConnNum", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "ConnNum", "NumberingPlanIdent");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumberingPlanIdent> ACCESS=<Data->NumberingPlanIdent>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NumberingPlanIdent);
	ED_Dump_Struct_End_Field (OStream, "ConnNum", "NumberingPlanIdent");
	ED_Dump_Struct_Begin_Field (OStream, "ConnNum", "PresentationIndicator");
	if (!Data->PresentationIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PresentationIndicator> ACCESS=<Data->PresentationIndicator>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->PresentationIndicator);
	}
	ED_Dump_Struct_End_Field (OStream, "ConnNum", "PresentationIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "ConnNum", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_ConnNum_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "ConnNum", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "ConnNum", "ScreeningIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ScreeningIndicator> ACCESS=<Data->ScreeningIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ScreeningIndicator);
	ED_Dump_Struct_End_Field (OStream, "ConnNum", "ScreeningIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "ConnNum", "Number");
	  /* STRUCTURAL=<0> TYPE=<c_TBCDArray> NAME=<Number> ACCESS=<Data->Number>  OPTIONAL=<0> FUNC=<Dump_c_TBCDArray> */
	  Dump_c_TBCDArray (OStream, &(Data->Number));
	ED_Dump_Struct_End_Field (OStream, "ConnNum", "Number");
	ED_Dump_Struct_End (OStream, "ConnNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RedirPartyBcdNum (TEDOStream* OStream, const c_RedirPartyBcdNum* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RedirPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartyBcdNum", "TypeOfNumber");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TypeOfNumber> ACCESS=<Data->TypeOfNumber>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TypeOfNumber);
	ED_Dump_Struct_End_Field (OStream, "RedirPartyBcdNum", "TypeOfNumber");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartyBcdNum", "NumberingPlanIdent");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NumberingPlanIdent> ACCESS=<Data->NumberingPlanIdent>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NumberingPlanIdent);
	ED_Dump_Struct_End_Field (OStream, "RedirPartyBcdNum", "NumberingPlanIdent");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartyBcdNum", "PresentationIndicator");
	if (!Data->PresentationIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PresentationIndicator> ACCESS=<Data->PresentationIndicator>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->PresentationIndicator);
	}
	ED_Dump_Struct_End_Field (OStream, "RedirPartyBcdNum", "PresentationIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartyBcdNum", "spare");
	  /* STRUCTURAL=<0> TYPE=<c_RedirPartyBcdNum_spare> NAME=<spare> ACCESS=<Data->spare>  OPTIONAL=<0> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	ED_Dump_Struct_End_Field (OStream, "RedirPartyBcdNum", "spare");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartyBcdNum", "ScreeningIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ScreeningIndicator> ACCESS=<Data->ScreeningIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ScreeningIndicator);
	ED_Dump_Struct_End_Field (OStream, "RedirPartyBcdNum", "ScreeningIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "RedirPartyBcdNum", "Number");
	  /* STRUCTURAL=<0> TYPE=<c_TBCDArray> NAME=<Number> ACCESS=<Data->Number>  OPTIONAL=<0> FUNC=<Dump_c_TBCDArray> */
	  Dump_c_TBCDArray (OStream, &(Data->Number));
	ED_Dump_Struct_End_Field (OStream, "RedirPartyBcdNum", "Number");
	ED_Dump_Struct_End (OStream, "RedirPartyBcdNum");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PlmnList (TEDOStream* OStream, const c_PlmnList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<5> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_Plmn> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_Plmn> */
	  Dump_c_Plmn (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EmergencyNumberList (TEDOStream* OStream, const c_EmergencyNumberList* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<6> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<c_TBCDEmergencyNumber> NAME=<data> ACCESS=<*(Data->data [i0])>  OPTIONAL=<0> FUNC=<Dump_c_TBCDEmergencyNumber> */
	  Dump_c_TBCDEmergencyNumber (OStream, &(*(Data->data [i0])));
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_Classmark3Value (TEDOStream* OStream, const c_Classmark3Value* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "Classmark3Value");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Multiband_supported");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Multiband_supported> ACCESS=<Data->Multiband_supported>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Multiband_supported);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Multiband_supported");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "A5_7");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_7> ACCESS=<Data->A5_7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_7);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "A5_7");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "A5_6");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_6> ACCESS=<Data->A5_6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_6);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "A5_6");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "A5_5");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_5> ACCESS=<Data->A5_5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_5);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "A5_5");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "A5_4");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_4> ACCESS=<Data->A5_4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->A5_4);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "A5_4");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Associated_Radio_Capability_2");
	if (!Data->Associated_Radio_Capability_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Associated_Radio_Capability_2> ACCESS=<Data->Associated_Radio_Capability_2>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Associated_Radio_Capability_2);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Associated_Radio_Capability_2");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Associated_Radio_Capability_1");
	if (!Data->Associated_Radio_Capability_1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Associated_Radio_Capability_1> ACCESS=<Data->Associated_Radio_Capability_1>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Associated_Radio_Capability_1);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Associated_Radio_Capability_1");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "R_GSM_band_Associated_Radio_Capability");
	if (!Data->R_GSM_band_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<R_GSM_band_Associated_Radio_Capability> ACCESS=<Data->R_GSM_band_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->R_GSM_band_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "R_GSM_band_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "HSCSD_Multi_Slot_Class");
	if (!Data->HSCSD_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HSCSD_Multi_Slot_Class> ACCESS=<Data->HSCSD_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->HSCSD_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "HSCSD_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "UCS2_treatment");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UCS2_treatment> ACCESS=<Data->UCS2_treatment>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UCS2_treatment);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "UCS2_treatment");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Extended_Measurement_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_Measurement_Capability> ACCESS=<Data->Extended_Measurement_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extended_Measurement_Capability);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Extended_Measurement_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "SMS_VALUE");
	if (!Data->SMS_VALUE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SMS_VALUE> ACCESS=<Data->SMS_VALUE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SMS_VALUE);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "SMS_VALUE");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "SM_VALUE");
	if (!Data->SM_VALUE_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SM_VALUE> ACCESS=<Data->SM_VALUE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SM_VALUE);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "SM_VALUE");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "MS_Positioning_Method");
	if (!Data->MS_Positioning_Method_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<MS_Positioning_Method> ACCESS=<Data->MS_Positioning_Method>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->MS_Positioning_Method);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "MS_Positioning_Method");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "ECSD_Multi_Slot_Class");
	if (!Data->ECSD_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ECSD_Multi_Slot_Class> ACCESS=<Data->ECSD_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->ECSD_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "ECSD_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Modulation_Capability");
	if (!Data->Modulation_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Modulation_Capability> ACCESS=<Data->Modulation_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Modulation_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Modulation_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "_8_PSK_RF_Power_Capability_1");
	if (!Data->_8_PSK_RF_Power_Capability_1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_RF_Power_Capability_1> ACCESS=<Data->_8_PSK_RF_Power_Capability_1>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->_8_PSK_RF_Power_Capability_1);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "_8_PSK_RF_Power_Capability_1");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "_8_PSK_RF_Power_Capability_2");
	if (!Data->_8_PSK_RF_Power_Capability_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_RF_Power_Capability_2> ACCESS=<Data->_8_PSK_RF_Power_Capability_2>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->_8_PSK_RF_Power_Capability_2);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "_8_PSK_RF_Power_Capability_2");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_400_Bands_Supported");
	if (!Data->GSM_400_Bands_Supported_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_400_Bands_Supported> ACCESS=<Data->GSM_400_Bands_Supported>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->GSM_400_Bands_Supported)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "T-GSM 380 supported, T-GSM 410 not supported"); break;
				case 2: OStream->WriteString (OStream, "T-GSM 410 supported, T-GSM 380 not supported"); break;
				case 3: OStream->WriteString (OStream, "T-GSM 410 supported, T-GSM 380 supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_400_Bands_Supported");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_400_Associated_Radio_Capability");
	if (!Data->GSM_400_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_400_Associated_Radio_Capability> ACCESS=<Data->GSM_400_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_400_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_400_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_850_Associated_Radio_Capability");
	if (!Data->GSM_850_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_850_Associated_Radio_Capability> ACCESS=<Data->GSM_850_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_850_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_850_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_1900_Associated_Radio_Capability");
	if (!Data->GSM_1900_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_1900_Associated_Radio_Capability> ACCESS=<Data->GSM_1900_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_1900_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_1900_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "UMTS_FDD_Radio_Access_Technology_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_FDD_Radio_Access_Technology_Capability> ACCESS=<Data->UMTS_FDD_Radio_Access_Technology_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UMTS_FDD_Radio_Access_Technology_Capability);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "UMTS_FDD_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> ACCESS=<Data->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "CDMA_2000_Radio_Access_Technology_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CDMA_2000_Radio_Access_Technology_Capability> ACCESS=<Data->CDMA_2000_Radio_Access_Technology_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->CDMA_2000_Radio_Access_Technology_Capability);
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "CDMA_2000_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "DTM_GPRS_Multi_Slot_Class");
	if (!Data->DTM_GPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_GPRS_Multi_Slot_Class> ACCESS=<Data->DTM_GPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_GPRS_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "DTM_GPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Single_Slot_DTM");
	if (!Data->Single_Slot_DTM_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Single_Slot_DTM> ACCESS=<Data->Single_Slot_DTM>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Single_Slot_DTM);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Single_Slot_DTM");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "DTM_EGPRS_Multi_Slot_Class");
	if (!Data->DTM_EGPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_EGPRS_Multi_Slot_Class> ACCESS=<Data->DTM_EGPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_EGPRS_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "DTM_EGPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_Band");
	if (!Data->GSM_Band_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_Band> ACCESS=<Data->GSM_Band>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->GSM_Band)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "E-GSM is supported"); break;
				case 1: OStream->WriteString (OStream, "P-GSM is supported"); break;
				case 2: OStream->WriteString (OStream, "GSM 1800 is supported"); break;
				case 3: OStream->WriteString (OStream, "GSM 450 is supported"); break;
				case 4: OStream->WriteString (OStream, "GSM 480 is supported"); break;
				case 5: OStream->WriteString (OStream, "GSM 850 is supported"); break;
				case 6: OStream->WriteString (OStream, "GSM 1900 is supported"); break;
				case 7: OStream->WriteString (OStream, "GSM 750 is supported"); break;
				case 8: OStream->WriteString (OStream, "GSM 710 is supported"); break;
				case 9: OStream->WriteString (OStream, "T-GSM 810 is supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_Band");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_750_Associated_Radio_Capability");
	if (!Data->GSM_750_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_750_Associated_Radio_Capability> ACCESS=<Data->GSM_750_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_750_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_750_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability");
	if (!Data->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> ACCESS=<Data->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GERAN_Feature_Package_1");
	if (!Data->GERAN_Feature_Package_1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Feature_Package_1> ACCESS=<Data->GERAN_Feature_Package_1>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_Feature_Package_1);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GERAN_Feature_Package_1");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Extended_DTM_GPRS_Multi_Slot_Class");
	if (!Data->Extended_DTM_GPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Extended_DTM_GPRS_Multi_Slot_Class> ACCESS=<Data->Extended_DTM_GPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Extended_DTM_GPRS_Multi_Slot_Class)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Unused. If received, the network shall interpret this as '01'"); break;
				case 1: OStream->WriteString (OStream, "Multislot class 5 supported"); break;
				case 2: OStream->WriteString (OStream, "Multislot class 9 supported"); break;
				case 3: OStream->WriteString (OStream, "Multislot class 11 supported"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Extended_DTM_GPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Extended_DTM_EGPRS_Multi_Slot_Class");
	if (!Data->Extended_DTM_EGPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Extended_DTM_EGPRS_Multi_Slot_Class> ACCESS=<Data->Extended_DTM_EGPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Extended_DTM_EGPRS_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Extended_DTM_EGPRS_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "High_Multislot_Capability");
	if (!Data->High_Multislot_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<High_Multislot_Capability> ACCESS=<Data->High_Multislot_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->High_Multislot_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "High_Multislot_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Length");
	if (!Data->Length_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->Length>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Length);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Length");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "FLO_Iu_Capability");
	if (!Data->FLO_Iu_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FLO_Iu_Capability> ACCESS=<Data->FLO_Iu_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->FLO_Iu_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "FLO_Iu_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GERAN_Feature_Package_2");
	if (!Data->GERAN_Feature_Package_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Feature_Package_2> ACCESS=<Data->GERAN_Feature_Package_2>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_Feature_Package_2);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GERAN_Feature_Package_2");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GMSK_Multislot_Power_Profile");
	if (!Data->GMSK_Multislot_Power_Profile_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GMSK_Multislot_Power_Profile> ACCESS=<Data->GMSK_Multislot_Power_Profile>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GMSK_Multislot_Power_Profile);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GMSK_Multislot_Power_Profile");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "_8_PSK_Multislot_Power_Profile");
	if (!Data->_8_PSK_Multislot_Power_Profile_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_Multislot_Power_Profile> ACCESS=<Data->_8_PSK_Multislot_Power_Profile>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->_8_PSK_Multislot_Power_Profile);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "_8_PSK_Multislot_Power_Profile");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "T_GSM_400_Bands_Supported");
	if (!Data->T_GSM_400_Bands_Supported_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_400_Bands_Supported> ACCESS=<Data->T_GSM_400_Bands_Supported>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_400_Bands_Supported);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "T_GSM_400_Bands_Supported");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "T_GSM_400_Associated_Radio_Capability");
	if (!Data->T_GSM_400_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_400_Associated_Radio_Capability> ACCESS=<Data->T_GSM_400_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_400_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "T_GSM_400_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "T_GSM_900_Associated_Radio_Capability");
	if (!Data->T_GSM_900_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_900_Associated_Radio_Capability> ACCESS=<Data->T_GSM_900_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_900_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "T_GSM_900_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Downlink_Advanced_Receiver_Performance");
	if (!Data->Downlink_Advanced_Receiver_Performance_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Downlink_Advanced_Receiver_Performance> ACCESS=<Data->Downlink_Advanced_Receiver_Performance>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->Downlink_Advanced_Receiver_Performance);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Downlink_Advanced_Receiver_Performance");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "DTM_Enhancements_Capability");
	if (!Data->DTM_Enhancements_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DTM_Enhancements_Capability> ACCESS=<Data->DTM_Enhancements_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->DTM_Enhancements_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "DTM_Enhancements_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "DTM_GPRS_High_Multi_Slot_Class");
	if (!Data->DTM_GPRS_High_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_GPRS_High_Multi_Slot_Class> ACCESS=<Data->DTM_GPRS_High_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_GPRS_High_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "DTM_GPRS_High_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Offset_required");
	if (!Data->Offset_required_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Offset_required> ACCESS=<Data->Offset_required>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Offset_required);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Offset_required");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "DTM_EGPRS_High_Multi_Slot_Class");
	if (!Data->DTM_EGPRS_High_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_EGPRS_High_Multi_Slot_Class> ACCESS=<Data->DTM_EGPRS_High_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->DTM_EGPRS_High_Multi_Slot_Class);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "DTM_EGPRS_High_Multi_Slot_Class");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Repeated_ACCH_Capability");
	if (!Data->Repeated_ACCH_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Repeated_ACCH_Capability> ACCESS=<Data->Repeated_ACCH_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Repeated_ACCH_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Repeated_ACCH_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GSM_710_Associated_Radio_Capability");
	if (!Data->GSM_710_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GSM_710_Associated_Radio_Capability> ACCESS=<Data->GSM_710_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->GSM_710_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GSM_710_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "T_GSM_810_Associated_Radio_Capability");
	if (!Data->T_GSM_810_Associated_Radio_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T_GSM_810_Associated_Radio_Capability> ACCESS=<Data->T_GSM_810_Associated_Radio_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T_GSM_810_Associated_Radio_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "T_GSM_810_Associated_Radio_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Ciphering_Mode_Setting_Capability");
	if (!Data->Ciphering_Mode_Setting_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Ciphering_Mode_Setting_Capability> ACCESS=<Data->Ciphering_Mode_Setting_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Ciphering_Mode_Setting_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Ciphering_Mode_Setting_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Additional_Positioning_Capabilities");
	if (!Data->Additional_Positioning_Capabilities_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Additional_Positioning_Capabilities> ACCESS=<Data->Additional_Positioning_Capabilities>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Additional_Positioning_Capabilities);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Additional_Positioning_Capabilities");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "E_UTRA_FDD_support");
	if (!Data->E_UTRA_FDD_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_FDD_support> ACCESS=<Data->E_UTRA_FDD_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_FDD_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "E_UTRA_FDD_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "E_UTRA_TDD_support");
	if (!Data->E_UTRA_TDD_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_TDD_support> ACCESS=<Data->E_UTRA_TDD_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_TDD_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "E_UTRA_TDD_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "E_UTRA_Measurement_and_Reporting_support");
	if (!Data->E_UTRA_Measurement_and_Reporting_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Measurement_and_Reporting_support> ACCESS=<Data->E_UTRA_Measurement_and_Reporting_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_Measurement_and_Reporting_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "E_UTRA_Measurement_and_Reporting_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Priority_based_reselection_support");
	if (!Data->Priority_based_reselection_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Priority_based_reselection_support> ACCESS=<Data->Priority_based_reselection_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Priority_based_reselection_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Priority_based_reselection_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "UTRA_CSG_Cells_Reporting");
	if (!Data->UTRA_CSG_Cells_Reporting_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRA_CSG_Cells_Reporting> ACCESS=<Data->UTRA_CSG_Cells_Reporting>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UTRA_CSG_Cells_Reporting);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "UTRA_CSG_Cells_Reporting");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "VAMOS_Level");
	if (!Data->VAMOS_Level_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<VAMOS_Level> ACCESS=<Data->VAMOS_Level>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->VAMOS_Level);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "VAMOS_Level");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "TIGHTER_Capability");
	if (!Data->TIGHTER_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIGHTER_Capability> ACCESS=<Data->TIGHTER_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->TIGHTER_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "TIGHTER_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Selective_Ciphering_of_Downlink_SACCH");
	if (!Data->Selective_Ciphering_of_Downlink_SACCH_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Selective_Ciphering_of_Downlink_SACCH> ACCESS=<Data->Selective_Ciphering_of_Downlink_SACCH>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Selective_Ciphering_of_Downlink_SACCH);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Selective_Ciphering_of_Downlink_SACCH");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_UTRA");
	if (!Data->CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CS_to_PS_SRVCC_from_GERAN_to_UTRA> ACCESS=<Data->CS_to_PS_SRVCC_from_GERAN_to_UTRA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->CS_to_PS_SRVCC_from_GERAN_to_UTRA);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_UTRA");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_E_UTRA");
	if (!Data->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CS_to_PS_SRVCC_from_GERAN_to_E_UTRA> ACCESS=<Data->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "CS_to_PS_SRVCC_from_GERAN_to_E_UTRA");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "GERAN_Network_Sharing_support");
	if (!Data->GERAN_Network_Sharing_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Network_Sharing_support> ACCESS=<Data->GERAN_Network_Sharing_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_Network_Sharing_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "GERAN_Network_Sharing_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "E_UTRA_Wideband_RSRQ_measurements_support");
	if (!Data->E_UTRA_Wideband_RSRQ_measurements_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Wideband_RSRQ_measurements_support> ACCESS=<Data->E_UTRA_Wideband_RSRQ_measurements_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_Wideband_RSRQ_measurements_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "E_UTRA_Wideband_RSRQ_measurements_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "ER_Band_Support");
	if (!Data->ER_Band_Support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ER_Band_Support> ACCESS=<Data->ER_Band_Support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ER_Band_Support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "ER_Band_Support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "UTRA_Multiple_Frequency_Band_Indicators_support");
	if (!Data->UTRA_Multiple_Frequency_Band_Indicators_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRA_Multiple_Frequency_Band_Indicators_support> ACCESS=<Data->UTRA_Multiple_Frequency_Band_Indicators_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UTRA_Multiple_Frequency_Band_Indicators_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "UTRA_Multiple_Frequency_Band_Indicators_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "E_UTRA_Multiple_Frequency_Band_Indicators_support");
	if (!Data->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Multiple_Frequency_Band_Indicators_support> ACCESS=<Data->E_UTRA_Multiple_Frequency_Band_Indicators_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->E_UTRA_Multiple_Frequency_Band_Indicators_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "E_UTRA_Multiple_Frequency_Band_Indicators_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Extended_TSC_Set_Capability_support");
	if (!Data->Extended_TSC_Set_Capability_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_TSC_Set_Capability_support> ACCESS=<Data->Extended_TSC_Set_Capability_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extended_TSC_Set_Capability_support);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Extended_TSC_Set_Capability_support");
	ED_Dump_Struct_Begin_Field (OStream, "Classmark3Value", "Extended_EARFCN_value_range");
	if (!Data->Extended_EARFCN_value_range_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_EARFCN_value_range> ACCESS=<Data->Extended_EARFCN_value_range>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Extended_EARFCN_value_range);
	}
	ED_Dump_Struct_End_Field (OStream, "Classmark3Value", "Extended_EARFCN_value_range");
	ED_Dump_Struct_End (OStream, "Classmark3Value");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ReceiveNPduNumbersList (TEDOStream* OStream, const c_ReceiveNPduNumbersList* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ReceiveNPduNumbersList");
	ED_Dump_Struct_Begin_Field (OStream, "ReceiveNPduNumbersList", "sapi");
		/* SEQUENCE NAME=<sapi> ACCESS=<Data->sapi>  ITEMS=<20> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "sapi", Data->sapi.items);
		for (i0=0; i0<Data->sapi.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "sapi", i0, Data->sapi.items);
		  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->sapi.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->sapi.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "sapi", i0, Data->sapi.items);
		}
		ED_Dump_Sequence_End (OStream, "sapi", Data->sapi.items);
	ED_Dump_Struct_End_Field (OStream, "ReceiveNPduNumbersList", "sapi");
	ED_Dump_Struct_Begin_Field (OStream, "ReceiveNPduNumbersList", "Receive_N_PDU_Number_value");
		/* SEQUENCE NAME=<Receive_N_PDU_Number_value> ACCESS=<Data->Receive_N_PDU_Number_value>  ITEMS=<20> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "Receive_N_PDU_Number_value", Data->Receive_N_PDU_Number_value.items);
		for (i0=0; i0<Data->Receive_N_PDU_Number_value.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "Receive_N_PDU_Number_value", i0, Data->Receive_N_PDU_Number_value.items);
		  /* STRUCTURAL=<1> TYPE=<ED_OCTET> NAME=<data> ACCESS=<Data->Receive_N_PDU_Number_value.data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
		  ED_Dump_Octet (OStream, Data->Receive_N_PDU_Number_value.data [i0]);
			ED_Dump_Sequence_End_Field (OStream, "Receive_N_PDU_Number_value", i0, Data->Receive_N_PDU_Number_value.items);
		}
		ED_Dump_Sequence_End (OStream, "Receive_N_PDU_Number_value", Data->Receive_N_PDU_Number_value.items);
	ED_Dump_Struct_End_Field (OStream, "ReceiveNPduNumbersList", "Receive_N_PDU_Number_value");
	ED_Dump_Struct_End (OStream, "ReceiveNPduNumbersList");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MsNetwkCpblty (TEDOStream* OStream, const c_MsNetwkCpblty* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MsNetwkCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_1");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_1> ACCESS=<Data->GEA_1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_1);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_1");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "SM_capabilities_via_dedicated_channels");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SM_capabilities_via_dedicated_channels> ACCESS=<Data->SM_capabilities_via_dedicated_channels>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SM_capabilities_via_dedicated_channels);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "SM_capabilities_via_dedicated_channels");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "SM_capabilities_via_GPRS_channels");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SM_capabilities_via_GPRS_channels> ACCESS=<Data->SM_capabilities_via_GPRS_channels>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SM_capabilities_via_GPRS_channels);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "SM_capabilities_via_GPRS_channels");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "UCS2_support");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UCS2_support> ACCESS=<Data->UCS2_support>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->UCS2_support);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "UCS2_support");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "SS_Screening_Indicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SS_Screening_Indicator> ACCESS=<Data->SS_Screening_Indicator>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->SS_Screening_Indicator);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "SS_Screening_Indicator");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "SoLSA_Capability");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SoLSA_Capability> ACCESS=<Data->SoLSA_Capability>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SoLSA_Capability);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "SoLSA_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "Revision_level_indicator");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Revision_level_indicator> ACCESS=<Data->Revision_level_indicator>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->Revision_level_indicator);
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "Revision_level_indicator");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "PFC_feature_mode");
	if (!Data->PFC_feature_mode_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PFC_feature_mode> ACCESS=<Data->PFC_feature_mode>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PFC_feature_mode);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "PFC_feature_mode");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_2");
	if (!Data->GEA_2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_2> ACCESS=<Data->GEA_2>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_2);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_2");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_3");
	if (!Data->GEA_3_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_3> ACCESS=<Data->GEA_3>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_3);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_3");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_4");
	if (!Data->GEA_4_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_4> ACCESS=<Data->GEA_4>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_4);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_4");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_5");
	if (!Data->GEA_5_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_5> ACCESS=<Data->GEA_5>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_5);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_5");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_6");
	if (!Data->GEA_6_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_6> ACCESS=<Data->GEA_6>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_6);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_6");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GEA_7");
	if (!Data->GEA_7_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GEA_7> ACCESS=<Data->GEA_7>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GEA_7);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GEA_7");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "LCS_VA_capability");
	if (!Data->LCS_VA_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<LCS_VA_capability> ACCESS=<Data->LCS_VA_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->LCS_VA_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "LCS_VA_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability");
	if (!Data->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability> ACCESS=<Data->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability");
	if (!Data->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability> ACCESS=<Data->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "EMM_Combined_procedures_Capability");
	if (!Data->EMM_Combined_procedures_Capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EMM_Combined_procedures_Capability> ACCESS=<Data->EMM_Combined_procedures_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EMM_Combined_procedures_Capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "EMM_Combined_procedures_Capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "ISR_support");
	if (!Data->ISR_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ISR_support> ACCESS=<Data->ISR_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->ISR_support);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "ISR_support");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "SRVCC_to_GERAN_UTRAN_capability");
	if (!Data->SRVCC_to_GERAN_UTRAN_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<SRVCC_to_GERAN_UTRAN_capability> ACCESS=<Data->SRVCC_to_GERAN_UTRAN_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->SRVCC_to_GERAN_UTRAN_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "SRVCC_to_GERAN_UTRAN_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "EPC_capability");
	if (!Data->EPC_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EPC_capability> ACCESS=<Data->EPC_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->EPC_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "EPC_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "NF_capability");
	if (!Data->NF_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<NF_capability> ACCESS=<Data->NF_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->NF_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "NF_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GERAN_network_sharing_capability");
	if (!Data->GERAN_network_sharing_capability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_network_sharing_capability> ACCESS=<Data->GERAN_network_sharing_capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GERAN_network_sharing_capability);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GERAN_network_sharing_capability");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "User_plane_integrity_protection_support");
	if (!Data->User_plane_integrity_protection_support_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<User_plane_integrity_protection_support> ACCESS=<Data->User_plane_integrity_protection_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->User_plane_integrity_protection_support);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "User_plane_integrity_protection_support");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GIA_4");
	if (!Data->GIA_4_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_4> ACCESS=<Data->GIA_4>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_4);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GIA_4");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GIA_5");
	if (!Data->GIA_5_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_5> ACCESS=<Data->GIA_5>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_5);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GIA_5");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GIA_6");
	if (!Data->GIA_6_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_6> ACCESS=<Data->GIA_6>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_6);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GIA_6");
	ED_Dump_Struct_Begin_Field (OStream, "MsNetwkCpblty", "GIA_7");
	if (!Data->GIA_7_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GIA_7> ACCESS=<Data->GIA_7>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->GIA_7);
	}
	ED_Dump_Struct_End_Field (OStream, "MsNetwkCpblty", "GIA_7");
	ED_Dump_Struct_End (OStream, "MsNetwkCpblty");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MsRadioAccessCpblty (TEDOStream* OStream, const c_MsRadioAccessCpblty* Data)
{
	int i0, i1;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty", "MS_RA_capability_value_part");
	  /* STRUCT */
		ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part");
		ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part", "MS_RA_capability_value");
			/* SEQUENCE NAME=<MS_RA_capability_value> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value>  ITEMS=<20> OPTIONAL=<0> */
			ED_Dump_Sequence_Begin (OStream, "MS_RA_capability_value", Data->MS_RA_capability_value_part.MS_RA_capability_value.items);
			for (i0=0; i0<Data->MS_RA_capability_value_part.MS_RA_capability_value.items; i0++) {
				ED_Dump_Sequence_Begin_Field (OStream, "MS_RA_capability_value", i0, Data->MS_RA_capability_value_part.MS_RA_capability_value.items);
			  /* STRUCT */
				ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data");
				ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Access_Technology_Type");
				  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Access_Technology_Type> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_Technology_Type>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_Technology_Type)
					{
						switch (DATA) {
							case 0: OStream->WriteString (OStream, "GSM P"); break;
							case 1: OStream->WriteString (OStream, "GSM E  --note that GSM E covers GSM P"); break;
							case 2: OStream->WriteString (OStream, "GSM R  --note that GSM R covers GSM E and GSM P"); break;
							case 3: OStream->WriteString (OStream, "GSM 1800"); break;
							case 4: OStream->WriteString (OStream, "GSM 1900"); break;
							case 5: OStream->WriteString (OStream, "GSM 450"); break;
							case 6: OStream->WriteString (OStream, "GSM 480"); break;
							case 7: OStream->WriteString (OStream, "GSM 850"); break;
							case 8: OStream->WriteString (OStream, "GSM 750"); break;
							case 9: OStream->WriteString (OStream, "GSM T 380"); break;
							case 10: OStream->WriteString (OStream, "GSM T 410"); break;
							case 11: OStream->WriteString (OStream, "GSM T 900"); break;
							case 12: OStream->WriteString (OStream, "GSM 710"); break;
							case 13: OStream->WriteString (OStream, "GSM T  810"); break;
							case 15: OStream->WriteString (OStream, "Indicates the presence of a list of Additional access technologies"); break;
							default: OStream->WriteString (OStream, "unknown");
						}
					}
#undef DATA
				ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Access_Technology_Type");
				ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Access_capabilities");
				if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities_Present) ED_Dump_Not_Present (OStream);
				else {
				  /* STRUCT */
					ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities");
					ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities", "Length");
					  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
					  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Length);
					ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities", "Length");
					ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities", "Access_capabilities");
					  /* STRUCT */
						ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "RF_Power_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.RF_Power_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RF_Power_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.RF_Power_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.RF_Power_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "RF_Power_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "A5_bits");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCT */
							ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_1");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_1> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_1>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_1);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_1");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_2");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_2> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_2>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_2);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_2");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_3");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_3> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_3>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_3);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_3");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_4");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_4> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_4>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_4);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_4");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_5");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_5> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_5>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_5);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_5");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_6");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_6> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_6>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_6);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_6");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_7");
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<A5_7> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_7>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.A5_bits->A5_7);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits", "A5_7");
							ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits");
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "A5_bits");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "ES_IND");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.ES_IND_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<ES_IND> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.ES_IND>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.ES_IND);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "ES_IND");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "PS");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.PS_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PS> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.PS>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.PS);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "PS");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "VGCS");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.VGCS_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VGCS> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.VGCS>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.VGCS);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "VGCS");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "VBS");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.VBS_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<VBS> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.VBS>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.VBS);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "VBS");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Multislot_capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCT */
							ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "HSCSD_multislot_class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HSCSD_multislot_class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->HSCSD_multislot_class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "HSCSD_multislot_class");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "GPRS_multislot_class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GPRS_multislot_class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_multislot_class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "GPRS_multislot_class");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "GPRS_Extended_Dynamic_Allocation_Capability");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GPRS_Extended_Dynamic_Allocation_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->GPRS_Extended_Dynamic_Allocation_Capability);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "GPRS_Extended_Dynamic_Allocation_Capability");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "SMS_VALUE");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SMS_VALUE> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->SMS_VALUE);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "SMS_VALUE");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "SM_VALUE");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SM_VALUE> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->SM_VALUE);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "SM_VALUE");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "ECSD_multislot_class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ECSD_multislot_class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->ECSD_multislot_class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "ECSD_multislot_class");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "EGPRS_multislot_class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EGPRS_multislot_class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_multislot_class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "EGPRS_multislot_class");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "EGPRS_Extended_Dynamic_Allocation_Capability");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EGPRS_Extended_Dynamic_Allocation_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->EGPRS_Extended_Dynamic_Allocation_Capability);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "EGPRS_Extended_Dynamic_Allocation_Capability");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "DTM_GPRS_Multi_Slot_Class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_GPRS_Multi_Slot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_GPRS_Multi_Slot_Class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "DTM_GPRS_Multi_Slot_Class");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "Single_Slot_DTM");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Single_Slot_DTM> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
#define DATA (Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->Single_Slot_DTM)
								{
									switch (DATA) {
										case 0: OStream->WriteString (OStream, "Single Slot DTM not supported"); break;
										case 1: OStream->WriteString (OStream, "Single Slot DTM supported"); break;
										default: OStream->WriteString (OStream, "unknown");
									}
								}
#undef DATA
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "Single_Slot_DTM");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "DTM_EGPRS_Multi_Slot_Class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_EGPRS_Multi_Slot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_capability->DTM_EGPRS_Multi_Slot_Class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability", "DTM_EGPRS_Multi_Slot_Class");
							ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability");
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Multislot_capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "_8PSK_Power_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities._8PSK_Power_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8PSK_Power_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities._8PSK_Power_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities._8PSK_Power_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "_8PSK_Power_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "COMPACT_Interference_Measurement_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<COMPACT_Interference_Measurement_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.COMPACT_Interference_Measurement_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "COMPACT_Interference_Measurement_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Revision_Level_Indicator");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Revision_Level_Indicator_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Revision_Level_Indicator> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Revision_Level_Indicator>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Revision_Level_Indicator);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Revision_Level_Indicator");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UMTS_FDD_Radio_Access_Technology_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_FDD_Radio_Access_Technology_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_FDD_Radio_Access_Technology_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UMTS_FDD_Radio_Access_Technology_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "CDMA_2000_Radio_Access_Technology_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<CDMA_2000_Radio_Access_Technology_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.CDMA_2000_Radio_Access_Technology_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "CDMA_2000_Radio_Access_Technology_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GERAN_Feature_Package_1");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Feature_Package_1> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_Feature_Package_1);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GERAN_Feature_Package_1");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_DTM_GPRS_Multi_Slot_Class");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Extended_DTM_GPRS_Multi_Slot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_DTM_GPRS_Multi_Slot_Class);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_DTM_GPRS_Multi_Slot_Class");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_DTM_EGPRS_Multi_Slot_Class");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Extended_DTM_EGPRS_Multi_Slot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_DTM_EGPRS_Multi_Slot_Class);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_DTM_EGPRS_Multi_Slot_Class");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Modulation_based_multislot_class_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Modulation_based_multislot_class_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Modulation_based_multislot_class_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Modulation_based_multislot_class_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "High_Multislot_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.High_Multislot_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<High_Multislot_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.High_Multislot_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.High_Multislot_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "High_Multislot_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Length");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Length_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Length>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Length);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Length");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "FLO_Iu_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.FLO_Iu_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FLO_Iu_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.FLO_Iu_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.FLO_Iu_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "FLO_Iu_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GMSK_Multislot_Power_Profile");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GMSK_Multislot_Power_Profile> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GMSK_Multislot_Power_Profile);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GMSK_Multislot_Power_Profile");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "_8_PSK_Multislot_Power_Profile");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8_PSK_Multislot_Power_Profile> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities._8_PSK_Multislot_Power_Profile);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "_8_PSK_Multislot_Power_Profile");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Multiple_TBF_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Multiple_TBF_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multiple_TBF_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Multiple_TBF_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Downlink_Advanced_Receiver_Performance");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Downlink_Advanced_Receiver_Performance> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_Advanced_Receiver_Performance);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Downlink_Advanced_Receiver_Performance");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_RLC_MAC_Control_Message_Segmentation_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_RLC_MAC_Control_Message_Segmentation_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_RLC_MAC_Control_Message_Segmentation_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_RLC_MAC_Control_Message_Segmentation_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_Enhancements_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DTM_Enhancements_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_Enhancements_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_Enhancements_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_GPRS_High_Multi_Slot_Class");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_GPRS_High_Multi_Slot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_GPRS_High_Multi_Slot_Class);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_GPRS_High_Multi_Slot_Class");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_EGPRS_High_Multi_Slot_Class");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DTM_EGPRS_High_Multi_Slot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_EGPRS_High_Multi_Slot_Class);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_EGPRS_High_Multi_Slot_Class");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "PS_Handover_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.PS_Handover_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<PS_Handover_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.PS_Handover_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.PS_Handover_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "PS_Handover_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_Handover_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_Handover_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DTM_Handover_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_Handover_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTM_Handover_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTM_Handover_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Multislot_Capability_Reduction_for_Downlink_Dual_Carrier");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Multislot_Capability_Reduction_for_Downlink_Dual_Carrier> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Multislot_Capability_Reduction_for_Downlink_Dual_Carrier);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Multislot_Capability_Reduction_for_Downlink_Dual_Carrier");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Downlink_Dual_Carrier_for_DTM_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Downlink_Dual_Carrier_for_DTM_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_Dual_Carrier_for_DTM_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Downlink_Dual_Carrier_for_DTM_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Flexible_Timeslot_Assignment");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Flexible_Timeslot_Assignment> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Flexible_Timeslot_Assignment);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Flexible_Timeslot_Assignment");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GAN_PS_Handover_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GAN_PS_Handover_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GAN_PS_Handover_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GAN_PS_Handover_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "RLC_Non_persistent_Mode");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<RLC_Non_persistent_Mode> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.RLC_Non_persistent_Mode);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "RLC_Non_persistent_Mode");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Reduced_Latency_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Reduced_Latency_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Reduced_Latency_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Reduced_Latency_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Uplink_EGPRS2");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Uplink_EGPRS2_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Uplink_EGPRS2> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Uplink_EGPRS2>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Uplink_EGPRS2);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Uplink_EGPRS2");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Downlink_EGPRS2");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_EGPRS2_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Downlink_EGPRS2> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_EGPRS2>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Downlink_EGPRS2);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Downlink_EGPRS2");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_FDD_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_FDD_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_FDD_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_FDD_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_TDD_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_TDD_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_TDD_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_TDD_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Priority_based_reselection_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Priority_based_reselection_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Priority_based_reselection_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Priority_based_reselection_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Priority_based_reselection_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Priority_based_reselection_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Enhanced_Flexible_Timeslot_Assignment");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCT */
							ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment", "Alternative_EFTA_Multislot_Class");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Alternative_EFTA_Multislot_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->Alternative_EFTA_Multislot_Class);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment", "Alternative_EFTA_Multislot_Class");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment", "EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Enhanced_Flexible_Timeslot_Assignment->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment", "EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier");
							ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment");
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Enhanced_Flexible_Timeslot_Assignment");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "EMST_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.EMST_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EMST_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.EMST_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.EMST_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "EMST_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "MTTI_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.MTTI_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<MTTI_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.MTTI_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.MTTI_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "MTTI_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UTRA_CSG_Cells_Reporting");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRA_CSG_Cells_Reporting> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UTRA_CSG_Cells_Reporting);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UTRA_CSG_Cells_Reporting");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_CSG_Cells_Reporting");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_CSG_Cells_Reporting> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_CSG_Cells_Reporting);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_CSG_Cells_Reporting");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTR_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTR_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DTR_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTR_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DTR_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DTR_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "EMSR_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.EMSR_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<EMSR_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.EMSR_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.EMSR_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "EMSR_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Fast_Downlink_Frequency_Switching_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Fast_Downlink_Frequency_Switching_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Fast_Downlink_Frequency_Switching_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Fast_Downlink_Frequency_Switching_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "TIGHTER_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.TIGHTER_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TIGHTER_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.TIGHTER_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.TIGHTER_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "TIGHTER_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "FANR_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.FANR_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<FANR_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.FANR_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.FANR_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "FANR_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "IPA_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.IPA_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<IPA_Capability> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.IPA_Capability>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.IPA_Capability);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "IPA_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GERAN_Network_Sharing_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<GERAN_Network_Sharing_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.GERAN_Network_Sharing_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "GERAN_Network_Sharing_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_Wideband_RSRQ_measurements_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Wideband_RSRQ_measurements_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_Wideband_RSRQ_measurements_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_Wideband_RSRQ_measurements_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UTRA_Multiple_Frequency_Band_Indicators_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<UTRA_Multiple_Frequency_Band_Indicators_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.UTRA_Multiple_Frequency_Band_Indicators_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "UTRA_Multiple_Frequency_Band_Indicators_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_Multiple_Frequency_Band_Indicators_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<E_UTRA_Multiple_Frequency_Band_Indicators_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.E_UTRA_Multiple_Frequency_Band_Indicators_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "E_UTRA_Multiple_Frequency_Band_Indicators_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DLMC_Capability");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCT */
							ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Non_contiguous_intra_band_reception");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DLMC_Non_contiguous_intra_band_reception> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Non_contiguous_intra_band_reception);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Non_contiguous_intra_band_reception");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Inter_band_reception");
							if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception_Present) ED_Dump_Not_Present (OStream);
							else {
							  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<DLMC_Inter_band_reception> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
							  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Inter_band_reception);
							}
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Inter_band_reception");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Maximum_Bandwidth");
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DLMC_Maximum_Bandwidth> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Bandwidth>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Bandwidth);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Maximum_Bandwidth");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Maximum_Number_of_Downlink_Timeslots");
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DLMC_Maximum_Number_of_Downlink_Timeslots> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Timeslots>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Timeslots);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Maximum_Number_of_Downlink_Timeslots");
							ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Maximum_Number_of_Downlink_Carriers");
							  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<DLMC_Maximum_Number_of_Downlink_Carriers> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Carriers>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
							  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.DLMC_Capability->DLMC_Maximum_Number_of_Downlink_Carriers);
							ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability", "DLMC_Maximum_Number_of_Downlink_Carriers");
							ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability");
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "DLMC_Capability");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_TSC_Set_Capability_support");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_TSC_Set_Capability_support> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_TSC_Set_Capability_support);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_TSC_Set_Capability_support");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_EARFCN_value_range");
						if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range_Present) ED_Dump_Not_Present (OStream);
						else {
						  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<Extended_EARFCN_value_range> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range>  OPTIONAL=<1> FUNC=<ED_Dump_Boolean> */
						  ED_Dump_Boolean (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Access_capabilities->Access_capabilities.Extended_EARFCN_value_range);
						}
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities", "Extended_EARFCN_value_range");
						ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities");
					ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities", "Access_capabilities");
					ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities");
				}
				ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Access_capabilities");
				ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Length");
				if (!Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Length_Present) ED_Dump_Not_Present (OStream);
				else {
				  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Length>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
				  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Length);
				}
				ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Length");
				ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Additional_access_technologies");
					/* SEQUENCE NAME=<Additional_access_technologies> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies>  ITEMS=<20> OPTIONAL=<0> */
					ED_Dump_Sequence_Begin (OStream, "Additional_access_technologies", Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.items);
					for (i1=0; i1<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.items; i1++) {
						ED_Dump_Sequence_Begin_Field (OStream, "Additional_access_technologies", i1, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.items);
					  /* STRUCT */
						ED_Dump_Struct_Begin (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data", "Access_Technology_Type");
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Access_Technology_Type> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.data [i1]->Access_Technology_Type>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.data [i1]->Access_Technology_Type);
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data", "Access_Technology_Type");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data", "GMSK_Power_Class");
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GMSK_Power_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.data [i1]->GMSK_Power_Class>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.data [i1]->GMSK_Power_Class);
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data", "GMSK_Power_Class");
						ED_Dump_Struct_Begin_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data", "_8PSK_Power_Class");
						  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<_8PSK_Power_Class> ACCESS=<Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.data [i1]->_8PSK_Power_Class>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
						  ED_Dump_Octet (OStream, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.data [i1]->_8PSK_Power_Class);
						ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data", "_8PSK_Power_Class");
						ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data");
						ED_Dump_Sequence_End_Field (OStream, "Additional_access_technologies", i1, Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.items);
					}
					ED_Dump_Sequence_End (OStream, "Additional_access_technologies", Data->MS_RA_capability_value_part.MS_RA_capability_value.data [i0]->Additional_access_technologies.items);
				ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data", "Additional_access_technologies");
				ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data");
				ED_Dump_Sequence_End_Field (OStream, "MS_RA_capability_value", i0, Data->MS_RA_capability_value_part.MS_RA_capability_value.items);
			}
			ED_Dump_Sequence_End (OStream, "MS_RA_capability_value", Data->MS_RA_capability_value_part.MS_RA_capability_value.items);
		ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part", "MS_RA_capability_value");
		ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty_MS_RA_capability_value_part");
	ED_Dump_Struct_End_Field (OStream, "MsRadioAccessCpblty", "MS_RA_capability_value_part");
	ED_Dump_Struct_End (OStream, "MsRadioAccessCpblty");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ProtocolCfgOpt (TEDOStream* OStream, const c_ProtocolCfgOpt* Data)
{
	int i0;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ProtocolCfgOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt", "ConfigurationProtocol");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ConfigurationProtocol> ACCESS=<Data->ConfigurationProtocol>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->ConfigurationProtocol);
	ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt", "ConfigurationProtocol");
	ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt", "ProtocolCfgs");
		/* SEQUENCE NAME=<ProtocolCfgs> ACCESS=<Data->ProtocolCfgs>  ITEMS=<20> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "ProtocolCfgs", Data->ProtocolCfgs.items);
		for (i0=0; i0<Data->ProtocolCfgs.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "ProtocolCfgs", i0, Data->ProtocolCfgs.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "ProtocolCfgOpt_ProtocolCfgs_data");
			ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt_ProtocolCfgs_data", "ProtocolId");
			  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<ProtocolId> ACCESS=<Data->ProtocolCfgs.data [i0]->ProtocolId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->ProtocolCfgs.data [i0]->ProtocolId)
				{
					switch (DATA) {
						case 32801: OStream->WriteString (OStream, "IPCP"); break;
						case 49185: OStream->WriteString (OStream, "LCP"); break;
						case 49187: OStream->WriteString (OStream, "PAP"); break;
						case 49699: OStream->WriteString (OStream, "CHAP"); break;
						default: OStream->WriteString (OStream, "unknown");
					}
				}
#undef DATA
			ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt_ProtocolCfgs_data", "ProtocolId");
			ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt_ProtocolCfgs_data", "Length");
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->ProtocolCfgs.data [i0]->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->ProtocolCfgs.data [i0]->Length);
			ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt_ProtocolCfgs_data", "Length");
			ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt_ProtocolCfgs_data", "Contents");
			  /* NAME=<Contents> ACCESS=<Data->ProtocolCfgs.data [i0]->Contents>  MAXBITSIZE=<64> OPTIONAL=<0> */
			  ED_Dump_Binary (OStream, Data->ProtocolCfgs.data [i0]->Contents.value, Data->ProtocolCfgs.data [i0]->Contents.usedBits);
			ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt_ProtocolCfgs_data", "Contents");
			ED_Dump_Struct_End (OStream, "ProtocolCfgOpt_ProtocolCfgs_data");
			ED_Dump_Sequence_End_Field (OStream, "ProtocolCfgs", i0, Data->ProtocolCfgs.items);
		}
		ED_Dump_Sequence_End (OStream, "ProtocolCfgs", Data->ProtocolCfgs.items);
	ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt", "ProtocolCfgs");
	ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt", "ContainerCfgs");
		/* SEQUENCE NAME=<ContainerCfgs> ACCESS=<Data->ContainerCfgs>  ITEMS=<20> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "ContainerCfgs", Data->ContainerCfgs.items);
		for (i0=0; i0<Data->ContainerCfgs.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "ContainerCfgs", i0, Data->ContainerCfgs.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "ProtocolCfgOpt_ContainerCfgs_data");
			ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt_ContainerCfgs_data", "ContainerId");
			  /* STRUCTURAL=<0> TYPE=<ED_SHORT> NAME=<ContainerId> ACCESS=<Data->ContainerCfgs.data [i0]->ContainerId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->ContainerCfgs.data [i0]->ContainerId)
				{
					switch (DATA) {
						case 1: OStream->WriteString (OStream, "P-CSCF Address Request"); break;
						case 2: OStream->WriteString (OStream, "IM CN Subsystem Signaling Flag"); break;
						case 3: OStream->WriteString (OStream, "DNS Server Address Request"); break;
						case 4: OStream->WriteString (OStream, "Policy Control rejection code"); break;
						case 5: OStream->WriteString (OStream, "MS Support of Network Requested Bearer Control indicator or Selected Bearer Control Mode"); break;
						case 6: OStream->WriteString (OStream, "Reserved"); break;
						case 7: OStream->WriteString (OStream, "DSMIPv6 Home Agent Address Request"); break;
						case 8: OStream->WriteString (OStream, "DSMIPv6 Home Network Prefix Request"); break;
						case 9: OStream->WriteString (OStream, "DSMIPv6 IPv4 Home Agent Address Request"); break;
						case 10: OStream->WriteString (OStream, "IP address allocation via NAS signalling"); break;
						case 11: OStream->WriteString (OStream, "IPv4 address allocation via DHCPv4"); break;
						case 12: OStream->WriteString (OStream, "P-CSCF IPv4 Address Request4"); break;
						case 13: OStream->WriteString (OStream, "DNS Server IPv4 Address Request"); break;
						case 14: OStream->WriteString (OStream, "MSISDN Request"); break;
						case 15: OStream->WriteString (OStream, "IFOM-Support-Request"); break;
						case 16: OStream->WriteString (OStream, "IPv4 Link MTU Request"); break;
						case 17: OStream->WriteString (OStream, "MS support of Local address in TFT indicator"); break;
						case 18: OStream->WriteString (OStream, "P-CSCF Re-selection support"); break;
						case 19: OStream->WriteString (OStream, "NBIFOM request/accepted indicator"); break;
						case 20: OStream->WriteString (OStream, "NBIFOM mode"); break;
						case 21: OStream->WriteString (OStream, "Non-IP Link MTU Request/Answer"); break;
						case 22: OStream->WriteString (OStream, "APN rate control support indicator/parameters"); break;
						default: OStream->WriteString (OStream, "unknown");
					}
				}
#undef DATA
			ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt_ContainerCfgs_data", "ContainerId");
			ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt_ContainerCfgs_data", "Length");
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Length> ACCESS=<Data->ContainerCfgs.data [i0]->Length>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->ContainerCfgs.data [i0]->Length);
			ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt_ContainerCfgs_data", "Length");
			ED_Dump_Struct_Begin_Field (OStream, "ProtocolCfgOpt_ContainerCfgs_data", "Contents");
			  /* NAME=<Contents> ACCESS=<Data->ContainerCfgs.data [i0]->Contents>  MAXBITSIZE=<64> OPTIONAL=<0> */
			  ED_Dump_Binary (OStream, Data->ContainerCfgs.data [i0]->Contents.value, Data->ContainerCfgs.data [i0]->Contents.usedBits);
			ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt_ContainerCfgs_data", "Contents");
			ED_Dump_Struct_End (OStream, "ProtocolCfgOpt_ContainerCfgs_data");
			ED_Dump_Sequence_End_Field (OStream, "ContainerCfgs", i0, Data->ContainerCfgs.items);
		}
		ED_Dump_Sequence_End (OStream, "ContainerCfgs", Data->ContainerCfgs.items);
	ED_Dump_Struct_End_Field (OStream, "ProtocolCfgOpt", "ContainerCfgs");
	ED_Dump_Struct_End (OStream, "ProtocolCfgOpt");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MobileId (TEDOStream* OStream, const c_MobileId* Data)
{
  /* UNION ACCESS=<*(Data)> */
	switch (Data->Present) {
	case U_c_MobileId_Identity: {
		ED_Dump_Union_Begin (OStream, "MobileId", "Identity");
		  /* STRUCTURAL=<0> TYPE=<c_MobileId_Identity> NAME=<Identity> ACCESS=<*(Data->u.Identity)>  OPTIONAL=<0> FUNC=<Dump_c_MobileId_Identity> */
		  Dump_c_MobileId_Identity (OStream, &(*(Data->u.Identity)));
	ED_Dump_Union_End (OStream, "MobileId", "Identity");
			break;
		}
	case U_c_MobileId_TMGI: {
		ED_Dump_Union_Begin (OStream, "MobileId", "TMGI");
		  /* STRUCTURAL=<0> TYPE=<c_MobileId_TMGI> NAME=<TMGI> ACCESS=<*(Data->u.TMGI)>  OPTIONAL=<0> FUNC=<Dump_c_MobileId_TMGI> */
		  Dump_c_MobileId_TMGI (OStream, &(*(Data->u.TMGI)));
	ED_Dump_Union_End (OStream, "MobileId", "TMGI");
			break;
		}
	default:;
}
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LinkedTi (TEDOStream* OStream, const c_LinkedTi* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LinkedTi");
	ED_Dump_Struct_Begin_Field (OStream, "LinkedTi", "TIValue");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TIValue> ACCESS=<Data->TIValue>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TIValue);
	ED_Dump_Struct_End_Field (OStream, "LinkedTi", "TIValue");
	ED_Dump_Struct_Begin_Field (OStream, "LinkedTi", "TIFlag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TIFlag> ACCESS=<Data->TIFlag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TIFlag);
	ED_Dump_Struct_End_Field (OStream, "LinkedTi", "TIFlag");
	ED_Dump_Struct_End (OStream, "LinkedTi");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TrafficFlowTemplate (TEDOStream* OStream, const c_TrafficFlowTemplate* Data)
{
	int i0, i1;
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TrafficFlowTemplate");
	ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate", "TFTOperationCode");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TFTOperationCode> ACCESS=<Data->TFTOperationCode>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->TFTOperationCode)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Spare"); break;
				case 1: OStream->WriteString (OStream, "Create new TFT"); break;
				case 2: OStream->WriteString (OStream, "Delete existing TFT"); break;
				case 3: OStream->WriteString (OStream, "Add packet filters to existing TFT"); break;
				case 4: OStream->WriteString (OStream, "Replace packet filters in existing TFT"); break;
				case 5: OStream->WriteString (OStream, "Delete packet filters from existing TFT"); break;
				case 6: OStream->WriteString (OStream, "No TFT operation"); break;
				case 7: OStream->WriteString (OStream, "Reserved"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate", "TFTOperationCode");
	ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate", "PacketFilters");
		/* SEQUENCE NAME=<PacketFilters> ACCESS=<Data->PacketFilters>  ITEMS=<8> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "PacketFilters", Data->PacketFilters.items);
		for (i0=0; i0<Data->PacketFilters.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "PacketFilters", i0, Data->PacketFilters.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "TrafficFlowTemplate_PacketFilters_data");
			ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "PacketFilterId");
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PacketFilterId> ACCESS=<Data->PacketFilters.data [i0]->PacketFilterId>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
			  ED_Dump_Octet (OStream, Data->PacketFilters.data [i0]->PacketFilterId);
			ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "PacketFilterId");
			ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "PacketFilterDirection");
			  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<PacketFilterDirection> ACCESS=<Data->PacketFilters.data [i0]->PacketFilterDirection>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PacketFilters.data [i0]->PacketFilterDirection)
				{
					switch (DATA) {
						case 0: OStream->WriteString (OStream, "pre Rel-7 TFT filter"); break;
						case 1: OStream->WriteString (OStream, "downlink only"); break;
						case 2: OStream->WriteString (OStream, "uplink only"); break;
						case 3: OStream->WriteString (OStream, "bidirectional"); break;
						default: OStream->WriteString (OStream, "unknown");
					}
				}
#undef DATA
			ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "PacketFilterDirection");
			ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "PacketFilterEvalPrecedence");
			  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<PacketFilterEvalPrecedence> ACCESS=<Data->PacketFilters.data [i0]->PacketFilterEvalPrecedence>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
			  ED_Dump_Integer (OStream, Data->PacketFilters.data [i0]->PacketFilterEvalPrecedence);
			ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "PacketFilterEvalPrecedence");
			ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "FilterContents");
				/* SEQUENCE NAME=<FilterContents> ACCESS=<Data->PacketFilters.data [i0]->FilterContents>  ITEMS=<7> OPTIONAL=<0> */
				ED_Dump_Sequence_Begin (OStream, "FilterContents", Data->PacketFilters.data [i0]->FilterContents.items);
				for (i1=0; i1<Data->PacketFilters.data [i0]->FilterContents.items; i1++) {
					ED_Dump_Sequence_Begin_Field (OStream, "FilterContents", i1, Data->PacketFilters.data [i0]->FilterContents.items);
				  /* STRUCT */
					ED_Dump_Struct_Begin (OStream, "TrafficFlowTemplate_PacketFilters_data_FilterContents_data");
					ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentTypeId");
					  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ComponentTypeId> ACCESS=<Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentTypeId>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentTypeId)
						{
							switch (DATA) {
								case 16: OStream->WriteString (OStream, "IPv4 remote address type"); break;
								case 17: OStream->WriteString (OStream, "IPv4 local address type"); break;
								case 32: OStream->WriteString (OStream, "IPv6 remote address type"); break;
								case 33: OStream->WriteString (OStream, "IPv6 remote address/prefix length type"); break;
								case 35: OStream->WriteString (OStream, "IPv6 local address/prefix length type"); break;
								case 48: OStream->WriteString (OStream, "Protocol identifier/Next header type"); break;
								case 64: OStream->WriteString (OStream, "Single local port type"); break;
								case 65: OStream->WriteString (OStream, "Local port range type"); break;
								case 80: OStream->WriteString (OStream, "Single remote port type"); break;
								case 81: OStream->WriteString (OStream, "Remote port range type"); break;
								case 96: OStream->WriteString (OStream, "Security parameter index type"); break;
								case 112: OStream->WriteString (OStream, "Type of service/Traffic class type"); break;
								case 128: OStream->WriteString (OStream, "Flow label type"); break;
								default: OStream->WriteString (OStream, "unknown");
							}
						}
#undef DATA
					ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentTypeId");
					ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentData");
					  /* NAME=<ComponentData> ACCESS=<Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentData>  MAXBITSIZE=<256> OPTIONAL=<0> */
					  ED_Dump_Binary (OStream, Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentData.value, Data->PacketFilters.data [i0]->FilterContents.data [i1]->ComponentData.usedBits);
					ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketFilters_data_FilterContents_data", "ComponentData");
					ED_Dump_Struct_End (OStream, "TrafficFlowTemplate_PacketFilters_data_FilterContents_data");
					ED_Dump_Sequence_End_Field (OStream, "FilterContents", i1, Data->PacketFilters.data [i0]->FilterContents.items);
				}
				ED_Dump_Sequence_End (OStream, "FilterContents", Data->PacketFilters.data [i0]->FilterContents.items);
			ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketFilters_data", "FilterContents");
			ED_Dump_Struct_End (OStream, "TrafficFlowTemplate_PacketFilters_data");
			ED_Dump_Sequence_End_Field (OStream, "PacketFilters", i0, Data->PacketFilters.items);
		}
		ED_Dump_Sequence_End (OStream, "PacketFilters", Data->PacketFilters.items);
	ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate", "PacketFilters");
	ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate", "PacketParameters");
		/* SEQUENCE NAME=<PacketParameters> ACCESS=<Data->PacketParameters>  ITEMS=<16> OPTIONAL=<0> */
		ED_Dump_Sequence_Begin (OStream, "PacketParameters", Data->PacketParameters.items);
		for (i0=0; i0<Data->PacketParameters.items; i0++) {
			ED_Dump_Sequence_Begin_Field (OStream, "PacketParameters", i0, Data->PacketParameters.items);
		  /* STRUCT */
			ED_Dump_Struct_Begin (OStream, "TrafficFlowTemplate_PacketParameters_data");
			ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketParameters_data", "ParameterId");
			  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<ParameterId> ACCESS=<Data->PacketParameters.data [i0]->ParameterId>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
			  ED_Dump_Integer (OStream, Data->PacketParameters.data [i0]->ParameterId);
			ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketParameters_data", "ParameterId");
			ED_Dump_Struct_Begin_Field (OStream, "TrafficFlowTemplate_PacketParameters_data", "Contents");
			  /* NAME=<Contents> ACCESS=<Data->PacketParameters.data [i0]->Contents>  MAXBITSIZE=<256> OPTIONAL=<0> */
			  ED_Dump_Binary (OStream, Data->PacketParameters.data [i0]->Contents.value, Data->PacketParameters.data [i0]->Contents.usedBits);
			ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate_PacketParameters_data", "Contents");
			ED_Dump_Struct_End (OStream, "TrafficFlowTemplate_PacketParameters_data");
			ED_Dump_Sequence_End_Field (OStream, "PacketParameters", i0, Data->PacketParameters.items);
		}
		ED_Dump_Sequence_End (OStream, "PacketParameters", Data->PacketParameters.items);
	ED_Dump_Struct_End_Field (OStream, "TrafficFlowTemplate", "PacketParameters");
	ED_Dump_Struct_End (OStream, "TrafficFlowTemplate");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PdpContextStatus (TEDOStream* OStream, const c_PdpContextStatus* Data)
{
	int i0;
	/* SEQUENCE NAME=<data> ACCESS=<*(Data)>  ITEMS=<16> OPTIONAL=<0> */
	ED_Dump_Sequence_Begin (OStream, "data", Data->items);
	for (i0=0; i0<Data->items; i0++) {
		ED_Dump_Sequence_Begin_Field (OStream, "data", i0, Data->items);
	  /* STRUCTURAL=<1> TYPE=<ED_BOOLEAN> NAME=<data> ACCESS=<Data->data [i0]>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->data [i0]);
		ED_Dump_Sequence_End_Field (OStream, "data", i0, Data->items);
	}
	ED_Dump_Sequence_End (OStream, "data", Data->items);
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SETUP_UP (TEDOStream* OStream, const c_SETUP_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SETUP_UP");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "BcRepeatInd");
	if (!Data->BcRepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<BcRepeatInd> ACCESS=<Data->BcRepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->BcRepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "BcRepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "BearerCpblty1");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty1> ACCESS=<Data->BearerCpblty1>  OPTIONAL=<0> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(Data->BearerCpblty1));
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "BearerCpblty1");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "BearerCpblty2");
	if (!Data->BearerCpblty2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty2> ACCESS=<*(Data->BearerCpblty2)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty2)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "BearerCpblty2");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "FacilitySimpleRecallAlignment");
	if (!Data->FacilitySimpleRecallAlignment_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<FacilitySimpleRecallAlignment> ACCESS=<*(Data->FacilitySimpleRecallAlignment)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->FacilitySimpleRecallAlignment->value, Data->FacilitySimpleRecallAlignment->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "FacilitySimpleRecallAlignment");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "CallingPartySubAddr");
	if (!Data->CallingPartySubAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CallingPartySubaddr> NAME=<CallingPartySubAddr> ACCESS=<*(Data->CallingPartySubAddr)>  OPTIONAL=<1> FUNC=<Dump_c_CallingPartySubaddr> */
	  Dump_c_CallingPartySubaddr (OStream, &(*(Data->CallingPartySubAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "CallingPartySubAddr");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "CalledPartyBcdNum");
	  /* STRUCTURAL=<0> TYPE=<c_CalledPartyBcdNum> NAME=<CalledPartyBcdNum> ACCESS=<Data->CalledPartyBcdNum>  OPTIONAL=<0> FUNC=<Dump_c_CalledPartyBcdNum> */
	  Dump_c_CalledPartyBcdNum (OStream, &(Data->CalledPartyBcdNum));
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "CalledPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "CalledPartySubAddr");
	if (!Data->CalledPartySubAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CalledPartySubaddr> NAME=<CalledPartySubAddr> ACCESS=<*(Data->CalledPartySubAddr)>  OPTIONAL=<1> FUNC=<Dump_c_CalledPartySubaddr> */
	  Dump_c_CalledPartySubaddr (OStream, &(*(Data->CalledPartySubAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "CalledPartySubAddr");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "LlcRepeatInd");
	if (!Data->LlcRepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LlcRepeatInd> ACCESS=<Data->LlcRepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LlcRepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "LlcRepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "LowLayerCpbilityI");
	if (!Data->LowLayerCpbilityI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerCpbilityI> ACCESS=<*(Data->LowLayerCpbilityI)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerCpbilityI->value, Data->LowLayerCpbilityI->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "LowLayerCpbilityI");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "LowLayerCpbilityIi");
	if (!Data->LowLayerCpbilityIi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerCpbilityIi> ACCESS=<*(Data->LowLayerCpbilityIi)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerCpbilityIi->value, Data->LowLayerCpbilityIi->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "LowLayerCpbilityIi");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "HlcRepeatInd");
	if (!Data->HlcRepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HlcRepeatInd> ACCESS=<Data->HlcRepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->HlcRepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "HlcRepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "HighLayerCpbilityI");
	if (!Data->HighLayerCpbilityI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerCpbilityI> ACCESS=<*(Data->HighLayerCpbilityI)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerCpbilityI)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "HighLayerCpbilityI");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "HighLayerCpbilityIi");
	if (!Data->HighLayerCpbilityIi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerCpbilityIi> ACCESS=<*(Data->HighLayerCpbilityIi)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerCpbilityIi)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "HighLayerCpbilityIi");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<264> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "SsVer");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "ClirSuppression");
	if (!Data->ClirSuppression_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SETUP_UP_ClirSuppression> NAME=<ClirSuppression> ACCESS=<Data->ClirSuppression>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "ClirSuppression");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "ClirInvocation");
	if (!Data->ClirInvocation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SETUP_UP_ClirInvocation> NAME=<ClirInvocation> ACCESS=<Data->ClirInvocation>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "ClirInvocation");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "CcCapabil");
	if (!Data->CcCapabil_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CallControlCapabil> NAME=<CcCapabil> ACCESS=<*(Data->CcCapabil)>  OPTIONAL=<1> FUNC=<Dump_c_CallControlCapabil> */
	  Dump_c_CallControlCapabil (OStream, &(*(Data->CcCapabil)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "CcCapabil");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "FacilityCcbsAdvancedRecallAlignment");
	if (!Data->FacilityCcbsAdvancedRecallAlignment_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<FacilityCcbsAdvancedRecallAlignment> ACCESS=<*(Data->FacilityCcbsAdvancedRecallAlignment)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->FacilityCcbsAdvancedRecallAlignment->value, Data->FacilityCcbsAdvancedRecallAlignment->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "FacilityCcbsAdvancedRecallAlignment");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "FacilityRecallAlignmentNotEssentialCcbs");
	if (!Data->FacilityRecallAlignmentNotEssentialCcbs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<FacilityRecallAlignmentNotEssentialCcbs> ACCESS=<*(Data->FacilityRecallAlignmentNotEssentialCcbs)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->FacilityRecallAlignmentNotEssentialCcbs->value, Data->FacilityRecallAlignmentNotEssentialCcbs->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "FacilityRecallAlignmentNotEssentialCcbs");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "StreamId");
	if (!Data->StreamId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StreamId> ACCESS=<Data->StreamId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StreamId);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "StreamId");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_SupportedCodecList> */
	  Dump_c_SupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "SupportedCodecs");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_UP", "Redial");
	if (!Data->Redial_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SETUP_UP_Redial> NAME=<Redial> ACCESS=<Data->Redial>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_UP", "Redial");
	ED_Dump_Struct_End (OStream, "SETUP_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_RESPONSE_UP (TEDOStream* OStream, const c_AUTHENTICATION_RESPONSE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_RESPONSE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_RESPONSE_UP", "AuthRespParam");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<AuthRespParam> ACCESS=<Data->AuthRespParam>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->AuthRespParam);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_RESPONSE_UP", "AuthRespParam");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_RESPONSE_UP", "AuthRespParamExt");
	if (!Data->AuthRespParamExt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthRespParamExt> ACCESS=<*(Data->AuthRespParamExt)>  MAXBITSIZE=<96> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthRespParamExt->value, Data->AuthRespParamExt->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_RESPONSE_UP", "AuthRespParamExt");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_RESPONSE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_FAILURE_UP (TEDOStream* OStream, const c_AUTHENTICATION_FAILURE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_FAILURE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_FAILURE_UP", "RejCause");
	  /* STRUCTURAL=<0> TYPE=<c_RejectCause> NAME=<RejCause> ACCESS=<Data->RejCause>  OPTIONAL=<0> FUNC=<Dump_c_RejectCause> */
	  Dump_c_RejectCause (OStream, &(Data->RejCause));
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_FAILURE_UP", "RejCause");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_FAILURE_UP", "AuthFailureParam");
	if (!Data->AuthFailureParam_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthFailureParam> ACCESS=<Data->AuthFailureParam>  MAXBITSIZE=<112> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthFailureParam, 112);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_FAILURE_UP", "AuthFailureParam");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_FAILURE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CM_RE_ESTABLISHMENT_REQUEST_UP (TEDOStream* OStream, const c_CM_RE_ESTABLISHMENT_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "CiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CiphKeySequenceNum> ACCESS=<Data->CiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "CiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "MobileStationClassmark");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2> NAME=<MobileStationClassmark> ACCESS=<Data->MobileStationClassmark>  OPTIONAL=<0> FUNC=<Dump_c_MobileStationClassmark2> */
	  Dump_c_MobileStationClassmark2 (OStream, &(Data->MobileStationClassmark));
	ED_Dump_Struct_End_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "MobileStationClassmark");
	ED_Dump_Struct_Begin_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "MobileId");
	ED_Dump_Struct_Begin_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "LocationAreaId");
	if (!Data->LocationAreaId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_LocationAreaId> NAME=<LocationAreaId> ACCESS=<*(Data->LocationAreaId)>  OPTIONAL=<1> FUNC=<Dump_c_LocationAreaId> */
	  Dump_c_LocationAreaId (OStream, &(*(Data->LocationAreaId)));
	}
	ED_Dump_Struct_End_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "LocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_End (OStream, "CM_RE_ESTABLISHMENT_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CM_SERVICE_ABORT_UP (TEDOStream* OStream, const c_CM_SERVICE_ABORT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CM_SERVICE_ABORT_UP");
	ED_Dump_Struct_End (OStream, "CM_SERVICE_ABORT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CM_SERVICE_REQUEST_UP (TEDOStream* OStream, const c_CM_SERVICE_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CM_SERVICE_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "CmServType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CmServType> ACCESS=<Data->CmServType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CmServType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "Mobile originating call establishment or packet mode connection establishment"); break;
				case 2: OStream->WriteString (OStream, "Emergency call establishment"); break;
				case 4: OStream->WriteString (OStream, "Short message service"); break;
				case 8: OStream->WriteString (OStream, "Supplementary service activation"); break;
				case 9: OStream->WriteString (OStream, "Voice group call establishment"); break;
				case 10: OStream->WriteString (OStream, "Voice broadcast call establishment"); break;
				case 11: OStream->WriteString (OStream, "Location Services"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "CmServType");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "CiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CiphKeySequenceNum> ACCESS=<Data->CiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "CiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "MobileStationClassmark");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2> NAME=<MobileStationClassmark> ACCESS=<Data->MobileStationClassmark>  OPTIONAL=<0> FUNC=<Dump_c_MobileStationClassmark2> */
	  Dump_c_MobileStationClassmark2 (OStream, &(Data->MobileStationClassmark));
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "MobileStationClassmark");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "MobileId");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "Priority");
	if (!Data->Priority_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PriorityLevel> NAME=<Priority> ACCESS=<*(Data->Priority)>  OPTIONAL=<1> FUNC=<Dump_c_PriorityLevel> */
	  Dump_c_PriorityLevel (OStream, &(*(Data->Priority)));
	}
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "Priority");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "AdditionalUpdateParameters");
	if (!Data->AdditionalUpdateParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateParameters> NAME=<AdditionalUpdateParameters> ACCESS=<*(Data->AdditionalUpdateParameters)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalUpdateParameters> */
	  Dump_c_AdditionalUpdateParameters (OStream, &(*(Data->AdditionalUpdateParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "AdditionalUpdateParameters");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_End (OStream, "CM_SERVICE_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IDENTITY_RESPONSE_UP (TEDOStream* OStream, const c_IDENTITY_RESPONSE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IDENTITY_RESPONSE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE_UP", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE_UP", "MobileId");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE_UP", "PTMSI");
	if (!Data->PTMSI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PTMSI_Type> NAME=<PTMSI> ACCESS=<*(Data->PTMSI)>  OPTIONAL=<1> FUNC=<Dump_c_PTMSI_Type> */
	  Dump_c_PTMSI_Type (OStream, &(*(Data->PTMSI)));
	}
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE_UP", "PTMSI");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE_UP", "AdditionalOldRoutingAreaIdent");
	if (!Data->AdditionalOldRoutingAreaIdent_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti2> NAME=<AdditionalOldRoutingAreaIdent> ACCESS=<*(Data->AdditionalOldRoutingAreaIdent)>  OPTIONAL=<1> FUNC=<Dump_c_RoutingAreaIdenti2> */
	  Dump_c_RoutingAreaIdenti2 (OStream, &(*(Data->AdditionalOldRoutingAreaIdent)));
	}
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE_UP", "AdditionalOldRoutingAreaIdent");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE_UP", "PTmsiSign");
	if (!Data->PTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<PTmsiSign> ACCESS=<Data->PTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->PTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE_UP", "PTmsiSign");
	ED_Dump_Struct_End (OStream, "IDENTITY_RESPONSE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IMSI_DETACH_INDICATION_UP (TEDOStream* OStream, const c_IMSI_DETACH_INDICATION_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IMSI_DETACH_INDICATION_UP");
	ED_Dump_Struct_Begin_Field (OStream, "IMSI_DETACH_INDICATION_UP", "MobileStationClassmark");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark1> NAME=<MobileStationClassmark> ACCESS=<Data->MobileStationClassmark>  OPTIONAL=<0> FUNC=<Dump_c_MobileStationClassmark1> */
	  Dump_c_MobileStationClassmark1 (OStream, &(Data->MobileStationClassmark));
	ED_Dump_Struct_End_Field (OStream, "IMSI_DETACH_INDICATION_UP", "MobileStationClassmark");
	ED_Dump_Struct_Begin_Field (OStream, "IMSI_DETACH_INDICATION_UP", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "IMSI_DETACH_INDICATION_UP", "MobileId");
	ED_Dump_Struct_End (OStream, "IMSI_DETACH_INDICATION_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LOCATION_UPDATING_REQUEST_UP (TEDOStream* OStream, const c_LOCATION_UPDATING_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LOCATION_UPDATING_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "LocationUpdatingType");
	  /* STRUCTURAL=<0> TYPE=<c_LocationUpdatingType> NAME=<LocationUpdatingType> ACCESS=<Data->LocationUpdatingType>  OPTIONAL=<0> FUNC=<Dump_c_LocationUpdatingType> */
	  Dump_c_LocationUpdatingType (OStream, &(Data->LocationUpdatingType));
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "LocationUpdatingType");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "CiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CiphKeySequenceNum> ACCESS=<Data->CiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "CiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "LocationAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_LocationAreaId> NAME=<LocationAreaId> ACCESS=<Data->LocationAreaId>  OPTIONAL=<0> FUNC=<Dump_c_LocationAreaId> */
	  Dump_c_LocationAreaId (OStream, &(Data->LocationAreaId));
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "LocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "MobileStationClassmark");
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark1> NAME=<MobileStationClassmark> ACCESS=<Data->MobileStationClassmark>  OPTIONAL=<0> FUNC=<Dump_c_MobileStationClassmark1> */
	  Dump_c_MobileStationClassmark1 (OStream, &(Data->MobileStationClassmark));
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "MobileStationClassmark");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "MobileId");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "MobileStationClassmarkForUmts");
	if (!Data->MobileStationClassmarkForUmts_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2> NAME=<MobileStationClassmarkForUmts> ACCESS=<*(Data->MobileStationClassmarkForUmts)>  OPTIONAL=<1> FUNC=<Dump_c_MobileStationClassmark2> */
	  Dump_c_MobileStationClassmark2 (OStream, &(*(Data->MobileStationClassmarkForUmts)));
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "MobileStationClassmarkForUmts");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "AdditionalUpdateParameters");
	if (!Data->AdditionalUpdateParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateParameters> NAME=<AdditionalUpdateParameters> ACCESS=<*(Data->AdditionalUpdateParameters)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalUpdateParameters> */
	  Dump_c_AdditionalUpdateParameters (OStream, &(*(Data->AdditionalUpdateParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REQUEST_UP", "AdditionalUpdateParameters");
	ED_Dump_Struct_End (OStream, "LOCATION_UPDATING_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MM_STATUS (TEDOStream* OStream, const c_MM_STATUS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MM_STATUS");
	ED_Dump_Struct_Begin_Field (OStream, "MM_STATUS", "RejCause");
	  /* STRUCTURAL=<0> TYPE=<c_RejectCause> NAME=<RejCause> ACCESS=<Data->RejCause>  OPTIONAL=<0> FUNC=<Dump_c_RejectCause> */
	  Dump_c_RejectCause (OStream, &(Data->RejCause));
	ED_Dump_Struct_End_Field (OStream, "MM_STATUS", "RejCause");
	ED_Dump_Struct_End (OStream, "MM_STATUS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TMSI_REALLOCATION_COMPLETE_UP (TEDOStream* OStream, const c_TMSI_REALLOCATION_COMPLETE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TMSI_REALLOCATION_COMPLETE_UP");
	ED_Dump_Struct_End (OStream, "TMSI_REALLOCATION_COMPLETE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MM_NULL_UP (TEDOStream* OStream, const c_MM_NULL_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MM_NULL_UP");
	ED_Dump_Struct_End (OStream, "MM_NULL_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ALERTING_UP (TEDOStream* OStream, const c_ALERTING_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ALERTING_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ALERTING_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ALERTING_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_UP", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ALERTING_UP", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_UP", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ALERTING_UP", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ALERTING_UP", "SsVer");
	ED_Dump_Struct_End (OStream, "ALERTING_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CALL_CONFIRMED_UP (TEDOStream* OStream, const c_CALL_CONFIRMED_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CALL_CONFIRMED_UP");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "RepeatInd");
	if (!Data->RepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RepeatInd> ACCESS=<Data->RepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "RepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "BearerCpblty1");
	if (!Data->BearerCpblty1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty1> ACCESS=<*(Data->BearerCpblty1)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty1)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "BearerCpblty1");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "BearerCpblty2");
	if (!Data->BearerCpblty2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty2> ACCESS=<*(Data->BearerCpblty2)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty2)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "BearerCpblty2");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "CcCapabil");
	if (!Data->CcCapabil_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CallControlCapabil> NAME=<CcCapabil> ACCESS=<*(Data->CcCapabil)>  OPTIONAL=<1> FUNC=<Dump_c_CallControlCapabil> */
	  Dump_c_CallControlCapabil (OStream, &(*(Data->CcCapabil)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "CcCapabil");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "StreamId");
	if (!Data->StreamId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StreamId> ACCESS=<Data->StreamId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StreamId);
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "StreamId");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_CONFIRMED_UP", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_SupportedCodecList> */
	  Dump_c_SupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_CONFIRMED_UP", "SupportedCodecs");
	ED_Dump_Struct_End (OStream, "CALL_CONFIRMED_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CONNECT_UP (TEDOStream* OStream, const c_CONNECT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CONNECT_UP");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "ConnSubaddr");
	if (!Data->ConnSubaddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ConnSubaddres> NAME=<ConnSubaddr> ACCESS=<*(Data->ConnSubaddr)>  OPTIONAL=<1> FUNC=<Dump_c_ConnSubaddres> */
	  Dump_c_ConnSubaddres (OStream, &(*(Data->ConnSubaddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "ConnSubaddr");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "SsVer");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_UP", "StreamId");
	if (!Data->StreamId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StreamId> ACCESS=<Data->StreamId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StreamId);
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_UP", "StreamId");
	ED_Dump_Struct_End (OStream, "CONNECT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CONNECT_ACKNOWLEDGE (TEDOStream* OStream, const c_CONNECT_ACKNOWLEDGE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CONNECT_ACKNOWLEDGE");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_ACKNOWLEDGE", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CONNECT_ACKNOWLEDGE", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_ACKNOWLEDGE", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CONNECT_ACKNOWLEDGE", "TI_Flag");
	ED_Dump_Struct_End (OStream, "CONNECT_ACKNOWLEDGE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DISCONNECT_UP (TEDOStream* OStream, const c_DISCONNECT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DISCONNECT_UP");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_UP", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_UP", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_UP", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_UP", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_UP", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_UP", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_UP", "SsVer");
	ED_Dump_Struct_End (OStream, "DISCONNECT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_EMERGENCY_SETUP_UP (TEDOStream* OStream, const c_EMERGENCY_SETUP_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "EMERGENCY_SETUP_UP");
	ED_Dump_Struct_Begin_Field (OStream, "EMERGENCY_SETUP_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "EMERGENCY_SETUP_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "EMERGENCY_SETUP_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "EMERGENCY_SETUP_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "EMERGENCY_SETUP_UP", "BearerCpblty");
	if (!Data->BearerCpblty_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty> ACCESS=<*(Data->BearerCpblty)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMERGENCY_SETUP_UP", "BearerCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "EMERGENCY_SETUP_UP", "StreamId");
	if (!Data->StreamId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<StreamId> ACCESS=<Data->StreamId>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->StreamId);
	}
	ED_Dump_Struct_End_Field (OStream, "EMERGENCY_SETUP_UP", "StreamId");
	ED_Dump_Struct_Begin_Field (OStream, "EMERGENCY_SETUP_UP", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_SupportedCodecList> */
	  Dump_c_SupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMERGENCY_SETUP_UP", "SupportedCodecs");
	ED_Dump_Struct_Begin_Field (OStream, "EMERGENCY_SETUP_UP", "EmergencyCategory");
	if (!Data->EmergencyCategory_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ServCategory> NAME=<EmergencyCategory> ACCESS=<*(Data->EmergencyCategory)>  OPTIONAL=<1> FUNC=<Dump_c_ServCategory> */
	  Dump_c_ServCategory (OStream, &(*(Data->EmergencyCategory)));
	}
	ED_Dump_Struct_End_Field (OStream, "EMERGENCY_SETUP_UP", "EmergencyCategory");
	ED_Dump_Struct_End (OStream, "EMERGENCY_SETUP_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_FACILITY_UP (TEDOStream* OStream, const c_FACILITY_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "FACILITY_UP");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "FACILITY_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "FACILITY_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_UP", "Facility");
	  /* NAME=<Facility> ACCESS=<Data->Facility>  MAXBITSIZE=<4792> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Facility.value, Data->Facility.usedBits);
	ED_Dump_Struct_End_Field (OStream, "FACILITY_UP", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "FACILITY_UP", "SsVer");
	ED_Dump_Struct_End (OStream, "FACILITY_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_HOLD_UP (TEDOStream* OStream, const c_HOLD_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "HOLD_UP");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "HOLD_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "HOLD_UP", "TI_Flag");
	ED_Dump_Struct_End (OStream, "HOLD_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY (TEDOStream* OStream, const c_MODIFY* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "BearerCpblty");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty> ACCESS=<Data->BearerCpblty>  OPTIONAL=<0> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(Data->BearerCpblty));
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "BearerCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "LowLayerComp");
	if (!Data->LowLayerComp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerComp> ACCESS=<*(Data->LowLayerComp)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerComp->value, Data->LowLayerComp->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "LowLayerComp");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "HighLayerComp");
	if (!Data->HighLayerComp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerComp> ACCESS=<*(Data->HighLayerComp)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerComp)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "HighLayerComp");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "ReverseCallSetupDir");
	if (!Data->ReverseCallSetupDir_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MODIFY_ReverseCallSetupDir> NAME=<ReverseCallSetupDir> ACCESS=<Data->ReverseCallSetupDir>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "ReverseCallSetupDir");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY", "ImmediateModifInd");
	if (!Data->ImmediateModifInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MODIFY_ImmediateModifInd> NAME=<ImmediateModifInd> ACCESS=<Data->ImmediateModifInd>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY", "ImmediateModifInd");
	ED_Dump_Struct_End (OStream, "MODIFY");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_COMPLETE (TEDOStream* OStream, const c_MODIFY_COMPLETE* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_COMPLETE");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_COMPLETE", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_COMPLETE", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_COMPLETE", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_COMPLETE", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_COMPLETE", "BearerCpblty");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty> ACCESS=<Data->BearerCpblty>  OPTIONAL=<0> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(Data->BearerCpblty));
	ED_Dump_Struct_End_Field (OStream, "MODIFY_COMPLETE", "BearerCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_COMPLETE", "LowLayerComp");
	if (!Data->LowLayerComp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerComp> ACCESS=<*(Data->LowLayerComp)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerComp->value, Data->LowLayerComp->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_COMPLETE", "LowLayerComp");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_COMPLETE", "HighLayerComp");
	if (!Data->HighLayerComp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerComp> ACCESS=<*(Data->HighLayerComp)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerComp)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_COMPLETE", "HighLayerComp");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_COMPLETE", "ReverseCallSetupDir");
	if (!Data->ReverseCallSetupDir_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MODIFY_COMPLETE_ReverseCallSetupDir> NAME=<ReverseCallSetupDir> ACCESS=<Data->ReverseCallSetupDir>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_COMPLETE", "ReverseCallSetupDir");
	ED_Dump_Struct_End (OStream, "MODIFY_COMPLETE");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_REJECT (TEDOStream* OStream, const c_MODIFY_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_REJECT", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_REJECT", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_REJECT", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_REJECT", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_REJECT", "BearerCpblty");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty> ACCESS=<Data->BearerCpblty>  OPTIONAL=<0> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(Data->BearerCpblty));
	ED_Dump_Struct_End_Field (OStream, "MODIFY_REJECT", "BearerCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_REJECT", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "MODIFY_REJECT", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_REJECT", "LowLayerComp");
	if (!Data->LowLayerComp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerComp> ACCESS=<*(Data->LowLayerComp)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerComp->value, Data->LowLayerComp->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_REJECT", "LowLayerComp");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_REJECT", "HighLayerComp");
	if (!Data->HighLayerComp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerComp> ACCESS=<*(Data->HighLayerComp)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerComp)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_REJECT", "HighLayerComp");
	ED_Dump_Struct_End (OStream, "MODIFY_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NOTIFY (TEDOStream* OStream, const c_NOTIFY* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NOTIFY");
	ED_Dump_Struct_Begin_Field (OStream, "NOTIFY", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "NOTIFY", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "NOTIFY", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "NOTIFY", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "NOTIFY", "NotifInd");
	  /* STRUCTURAL=<0> TYPE=<c_NotifInd> NAME=<NotifInd> ACCESS=<Data->NotifInd>  OPTIONAL=<0> FUNC=<Dump_c_NotifInd> */
	  Dump_c_NotifInd (OStream, &(Data->NotifInd));
	ED_Dump_Struct_End_Field (OStream, "NOTIFY", "NotifInd");
	ED_Dump_Struct_End (OStream, "NOTIFY");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CC_ESTABLISHMENT_CONFIRMED_UP (TEDOStream* OStream, const c_CC_ESTABLISHMENT_CONFIRMED_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "RepeatInd");
	if (!Data->RepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RepeatInd> ACCESS=<Data->RepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "RepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "BearerCpblty1");
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty1> ACCESS=<Data->BearerCpblty1>  OPTIONAL=<0> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(Data->BearerCpblty1));
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "BearerCpblty1");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "BearerCpblty2");
	if (!Data->BearerCpblty2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty2> ACCESS=<*(Data->BearerCpblty2)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty2)));
	}
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "BearerCpblty2");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_SupportedCodecList> */
	  Dump_c_SupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP", "SupportedCodecs");
	ED_Dump_Struct_End (OStream, "CC_ESTABLISHMENT_CONFIRMED_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RELEASE_UP (TEDOStream* OStream, const c_RELEASE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RELEASE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "SecondCause");
	if (!Data->SecondCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<SecondCause> ACCESS=<*(Data->SecondCause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->SecondCause)));
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "SecondCause");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_UP", "SsVer");
	ED_Dump_Struct_End (OStream, "RELEASE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RELEASE_COMPLETE_UP (TEDOStream* OStream, const c_RELEASE_COMPLETE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RELEASE_COMPLETE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_UP", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_UP", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_UP", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_UP", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_UP", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_UP", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_UP", "SsVer");
	if (!Data->SsVer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<SsVer> ACCESS=<*(Data->SsVer)>  MAXBITSIZE=<8> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->SsVer->value, Data->SsVer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_UP", "SsVer");
	ED_Dump_Struct_End (OStream, "RELEASE_COMPLETE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RETRIEVE_UP (TEDOStream* OStream, const c_RETRIEVE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RETRIEVE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_UP", "TI_Flag");
	ED_Dump_Struct_End (OStream, "RETRIEVE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_START_CC_UP (TEDOStream* OStream, const c_START_CC_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "START_CC_UP");
	ED_Dump_Struct_Begin_Field (OStream, "START_CC_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "START_CC_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "START_CC_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "START_CC_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "START_CC_UP", "CcCapabil");
	if (!Data->CcCapabil_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CallControlCapabil> NAME=<CcCapabil> ACCESS=<*(Data->CcCapabil)>  OPTIONAL=<1> FUNC=<Dump_c_CallControlCapabil> */
	  Dump_c_CallControlCapabil (OStream, &(*(Data->CcCapabil)));
	}
	ED_Dump_Struct_End_Field (OStream, "START_CC_UP", "CcCapabil");
	ED_Dump_Struct_End (OStream, "START_CC_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_START_DTMF_UP (TEDOStream* OStream, const c_START_DTMF_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "START_DTMF_UP");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_UP", "KeypadFacility");
	  /* STRUCTURAL=<0> TYPE=<c_KeypadFacility> NAME=<KeypadFacility> ACCESS=<Data->KeypadFacility>  OPTIONAL=<0> FUNC=<Dump_c_KeypadFacility> */
	  Dump_c_KeypadFacility (OStream, &(Data->KeypadFacility));
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_UP", "KeypadFacility");
	ED_Dump_Struct_End (OStream, "START_DTMF_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_STATUS (TEDOStream* OStream, const c_STATUS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "STATUS");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "STATUS", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "STATUS", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "STATUS", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS", "CallState");
	  /* STRUCTURAL=<0> TYPE=<c_CallState> NAME=<CallState> ACCESS=<Data->CallState>  OPTIONAL=<0> FUNC=<Dump_c_CallState> */
	  Dump_c_CallState (OStream, &(Data->CallState));
	ED_Dump_Struct_End_Field (OStream, "STATUS", "CallState");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS", "AuxiliaryStates");
	if (!Data->AuxiliaryStates_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AuxiliaryStates> NAME=<AuxiliaryStates> ACCESS=<*(Data->AuxiliaryStates)>  OPTIONAL=<1> FUNC=<Dump_c_AuxiliaryStates> */
	  Dump_c_AuxiliaryStates (OStream, &(*(Data->AuxiliaryStates)));
	}
	ED_Dump_Struct_End_Field (OStream, "STATUS", "AuxiliaryStates");
	ED_Dump_Struct_End (OStream, "STATUS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_STATUS_ENQUIRY (TEDOStream* OStream, const c_STATUS_ENQUIRY* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "STATUS_ENQUIRY");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS_ENQUIRY", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "STATUS_ENQUIRY", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "STATUS_ENQUIRY", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "STATUS_ENQUIRY", "TI_Flag");
	ED_Dump_Struct_End (OStream, "STATUS_ENQUIRY");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_STOP_DTMF_UP (TEDOStream* OStream, const c_STOP_DTMF_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "STOP_DTMF_UP");
	ED_Dump_Struct_Begin_Field (OStream, "STOP_DTMF_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "STOP_DTMF_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "STOP_DTMF_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "STOP_DTMF_UP", "TI_Flag");
	ED_Dump_Struct_End (OStream, "STOP_DTMF_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_USER_INFORMATION (TEDOStream* OStream, const c_USER_INFORMATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "USER_INFORMATION");
	ED_Dump_Struct_Begin_Field (OStream, "USER_INFORMATION", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "USER_INFORMATION", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "USER_INFORMATION", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "USER_INFORMATION", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "USER_INFORMATION", "UserUser");
	  /* NAME=<UserUser> ACCESS=<Data->UserUser>  MAXBITSIZE=<1040> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->UserUser.value, Data->UserUser.usedBits);
	ED_Dump_Struct_End_Field (OStream, "USER_INFORMATION", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "USER_INFORMATION", "MoreData");
	if (!Data->MoreData_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_USER_INFORMATION_MoreData> NAME=<MoreData> ACCESS=<Data->MoreData>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "USER_INFORMATION", "MoreData");
	ED_Dump_Struct_End (OStream, "USER_INFORMATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_REQUEST_UP (TEDOStream* OStream, const c_ATTACH_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "MsNetwkCpblty");
	  /* STRUCTURAL=<0> TYPE=<c_MsNetwkCpblty> NAME=<MsNetwkCpblty> ACCESS=<Data->MsNetwkCpblty>  OPTIONAL=<0> FUNC=<Dump_c_MsNetwkCpblty> */
	  Dump_c_MsNetwkCpblty (OStream, &(Data->MsNetwkCpblty));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "MsNetwkCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "AttachType");
	  /* STRUCTURAL=<0> TYPE=<c_AttachType> NAME=<AttachType> ACCESS=<Data->AttachType>  OPTIONAL=<0> FUNC=<Dump_c_AttachType> */
	  Dump_c_AttachType (OStream, &(Data->AttachType));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "AttachType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "GprsCiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GprsCiphKeySequenceNum> ACCESS=<Data->GprsCiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GprsCiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "GprsCiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "DrxParam");
	  /* STRUCTURAL=<0> TYPE=<c_DrxParam> NAME=<DrxParam> ACCESS=<Data->DrxParam>  OPTIONAL=<0> FUNC=<Dump_c_DrxParam> */
	  Dump_c_DrxParam (OStream, &(Data->DrxParam));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "DrxParam");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "MobileIdentity");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileIdentity> ACCESS=<Data->MobileIdentity>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileIdentity));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "MobileIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "OldRoutingAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti> NAME=<OldRoutingAreaId> ACCESS=<Data->OldRoutingAreaId>  OPTIONAL=<0> FUNC=<Dump_c_RoutingAreaIdenti> */
	  Dump_c_RoutingAreaIdenti (OStream, &(Data->OldRoutingAreaId));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "OldRoutingAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "MsRadioAccessCpblty");
	  /* STRUCTURAL=<0> TYPE=<c_MsRadioAccessCpblty> NAME=<MsRadioAccessCpblty> ACCESS=<Data->MsRadioAccessCpblty>  OPTIONAL=<0> FUNC=<Dump_c_MsRadioAccessCpblty> */
	  Dump_c_MsRadioAccessCpblty (OStream, &(Data->MsRadioAccessCpblty));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "MsRadioAccessCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "OldPTmsiSign");
	if (!Data->OldPTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<OldPTmsiSign> ACCESS=<Data->OldPTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->OldPTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "OldPTmsiSign");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "ReqRdyTimerValue");
	if (!Data->ReqRdyTimerValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer> NAME=<ReqRdyTimerValue> ACCESS=<*(Data->ReqRdyTimerValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer> */
	  Dump_c_GprsTimer (OStream, &(*(Data->ReqRdyTimerValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "ReqRdyTimerValue");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "TmsiStatus");
	if (!Data->TmsiStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TmsiStatus> NAME=<TmsiStatus> ACCESS=<*(Data->TmsiStatus)>  OPTIONAL=<1> FUNC=<Dump_c_TmsiStatus> */
	  Dump_c_TmsiStatus (OStream, &(*(Data->TmsiStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "TmsiStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "PSLCSCapability");
	if (!Data->PSLCSCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PSLCSCapabilit> NAME=<PSLCSCapability> ACCESS=<*(Data->PSLCSCapability)>  OPTIONAL=<1> FUNC=<Dump_c_PSLCSCapabilit> */
	  Dump_c_PSLCSCapabilit (OStream, &(*(Data->PSLCSCapability)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "PSLCSCapability");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "MobileStationClassmark2");
	if (!Data->MobileStationClassmark2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2> NAME=<MobileStationClassmark2> ACCESS=<*(Data->MobileStationClassmark2)>  OPTIONAL=<1> FUNC=<Dump_c_MobileStationClassmark2> */
	  Dump_c_MobileStationClassmark2 (OStream, &(*(Data->MobileStationClassmark2)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "MobileStationClassmark2");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "MobileStationClassmark3");
	if (!Data->MobileStationClassmark3_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Classmark3Value> NAME=<MobileStationClassmark3> ACCESS=<*(Data->MobileStationClassmark3)>  OPTIONAL=<1> FUNC=<Dump_c_Classmark3Value> */
	  Dump_c_Classmark3Value (OStream, &(*(Data->MobileStationClassmark3)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "MobileStationClassmark3");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_SupportedCodecList> */
	  Dump_c_SupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "SupportedCodecs");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "UENetworkCapability");
	if (!Data->UENetworkCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UENetworkCapability> ACCESS=<*(Data->UENetworkCapability)>  MAXBITSIZE=<104> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UENetworkCapability->value, Data->UENetworkCapability->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "UENetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "AdditionalMobileIdentity");
	if (!Data->AdditionalMobileIdentity_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<AdditionalMobileIdentity> ACCESS=<*(Data->AdditionalMobileIdentity)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->AdditionalMobileIdentity)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "AdditionalMobileIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "AdditionalOldRoutingAreaId");
	if (!Data->AdditionalOldRoutingAreaId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti2> NAME=<AdditionalOldRoutingAreaId> ACCESS=<*(Data->AdditionalOldRoutingAreaId)>  OPTIONAL=<1> FUNC=<Dump_c_RoutingAreaIdenti2> */
	  Dump_c_RoutingAreaIdenti2 (OStream, &(*(Data->AdditionalOldRoutingAreaId)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "AdditionalOldRoutingAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "VoiceDomainPrefUEUsageSetting");
	if (!Data->VoiceDomainPrefUEUsageSetting_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_VoiceDomainPreferenceAndUEsUsageSetting> NAME=<VoiceDomainPrefUEUsageSetting> ACCESS=<*(Data->VoiceDomainPrefUEUsageSetting)>  OPTIONAL=<1> FUNC=<Dump_c_VoiceDomainPreferenceAndUEsUsageSetting> */
	  Dump_c_VoiceDomainPreferenceAndUEsUsageSetting (OStream, &(*(Data->VoiceDomainPrefUEUsageSetting)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "VoiceDomainPrefUEUsageSetting");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "PTMSI");
	if (!Data->PTMSI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PTMSI_Type> NAME=<PTMSI> ACCESS=<*(Data->PTMSI)>  OPTIONAL=<1> FUNC=<Dump_c_PTMSI_Type> */
	  Dump_c_PTMSI_Type (OStream, &(*(Data->PTMSI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "PTMSI");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "MSNetworkFeatureSupport");
	if (!Data->MSNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MSNetworkFeatureSupport> NAME=<MSNetworkFeatureSupport> ACCESS=<*(Data->MSNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_MSNetworkFeatureSupport> */
	  Dump_c_MSNetworkFeatureSupport (OStream, &(*(Data->MSNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "MSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "OldLocationAreaIdentification");
	if (!Data->OldLocationAreaIdentification_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<OldLocationAreaIdentification> ACCESS=<Data->OldLocationAreaIdentification>  MAXBITSIZE=<40> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->OldLocationAreaIdentification, 40);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "OldLocationAreaIdentification");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "AdditionalUpdateType");
	if (!Data->AdditionalUpdateType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateType> NAME=<AdditionalUpdateType> ACCESS=<*(Data->AdditionalUpdateType)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalUpdateType> */
	  Dump_c_AdditionalUpdateType (OStream, &(*(Data->AdditionalUpdateType)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "AdditionalUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "TMSIBasedNRIContainer");
	if (!Data->TMSIBasedNRIContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetworkResourceIdContainer> NAME=<TMSIBasedNRIContainer> ACCESS=<*(Data->TMSIBasedNRIContainer)>  OPTIONAL=<1> FUNC=<Dump_c_NetworkResourceIdContainer> */
	  Dump_c_NetworkResourceIdContainer (OStream, &(*(Data->TMSIBasedNRIContainer)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "TMSIBasedNRIContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "T3324Value");
	if (!Data->T3324Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3324Value> ACCESS=<*(Data->T3324Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3324Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "T3324Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "T3312ExtendedValue");
	if (!Data->T3312ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3312ExtendedValue> ACCESS=<*(Data->T3312ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3312ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "T3312ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REQUEST_UP", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_ExtendedDRXParameters> */
	  Dump_c_ExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REQUEST_UP", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "ATTACH_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_COMPLETE_UP (TEDOStream* OStream, const c_ATTACH_COMPLETE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_COMPLETE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_COMPLETE_UP", "InterRATHandoverInfo");
	if (!Data->InterRATHandoverInfo_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<InterRATHandoverInfo> ACCESS=<*(Data->InterRATHandoverInfo)>  MAXBITSIZE=<1984> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->InterRATHandoverInfo->value, Data->InterRATHandoverInfo->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_COMPLETE_UP", "InterRATHandoverInfo");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_COMPLETE_UP", "E_UTRAN_InterRATHandoverInfo");
	if (!Data->E_UTRAN_InterRATHandoverInfo_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<E_UTRAN_InterRATHandoverInfo> ACCESS=<*(Data->E_UTRAN_InterRATHandoverInfo)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->E_UTRAN_InterRATHandoverInfo->value, Data->E_UTRAN_InterRATHandoverInfo->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_COMPLETE_UP", "E_UTRAN_InterRATHandoverInfo");
	ED_Dump_Struct_End (OStream, "ATTACH_COMPLETE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DETACH_REQUEST_UP (TEDOStream* OStream, const c_DETACH_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DETACH_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_UP", "DetachType");
	  /* STRUCTURAL=<0> TYPE=<c_DetachType> NAME=<DetachType> ACCESS=<Data->DetachType>  OPTIONAL=<0> FUNC=<Dump_c_DetachType> */
	  Dump_c_DetachType (OStream, &(Data->DetachType));
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_UP", "DetachType");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_UP", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_UP", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_UP", "PTmsi");
	if (!Data->PTmsi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<PTmsi> ACCESS=<*(Data->PTmsi)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->PTmsi)));
	}
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_UP", "PTmsi");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_UP", "PTmsiSign");
	if (!Data->PTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<PTmsiSign> ACCESS=<Data->PTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->PTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_UP", "PTmsiSign");
	ED_Dump_Struct_End (OStream, "DETACH_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DETACH_ACCEPT_UP (TEDOStream* OStream, const c_DETACH_ACCEPT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DETACH_ACCEPT_UP");
	ED_Dump_Struct_End (OStream, "DETACH_ACCEPT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_P_TMSI_REALLOCATION_COMPLETE_UP (TEDOStream* OStream, const c_P_TMSI_REALLOCATION_COMPLETE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "P_TMSI_REALLOCATION_COMPLETE_UP");
	ED_Dump_Struct_End (OStream, "P_TMSI_REALLOCATION_COMPLETE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (TEDOStream* OStream, const c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "ACRefNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ACRefNum> ACCESS=<Data->ACRefNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ACRefNum);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "ACRefNum");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "AuthParamResp");
	if (!Data->AuthParamResp_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<AuthParamResp> ACCESS=<Data->AuthParamResp>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->AuthParamResp);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "AuthParamResp");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "Imeisv");
	if (!Data->Imeisv_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<Imeisv> ACCESS=<*(Data->Imeisv)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->Imeisv)));
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "Imeisv");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "AuthRespParamExt");
	if (!Data->AuthRespParamExt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthRespParamExt> ACCESS=<*(Data->AuthRespParamExt)>  MAXBITSIZE=<96> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthRespParamExt->value, Data->AuthRespParamExt->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "AuthRespParamExt");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "MessageAuthCode");
	if (!Data->MessageAuthCode_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<MessageAuthCode> ACCESS=<Data->MessageAuthCode>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MessageAuthCode);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP", "MessageAuthCode");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_AND_CIPHERING_RESPONSE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (TEDOStream* OStream, const c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_AND_CIPHERING_FAILURE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_FAILURE_UP", "GmmCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_FAILURE_UP", "GmmCause");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_FAILURE_UP", "AuthFailureParam");
	if (!Data->AuthFailureParam_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthFailureParam> ACCESS=<Data->AuthFailureParam>  MAXBITSIZE=<112> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthFailureParam, 112);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_FAILURE_UP", "AuthFailureParam");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_AND_CIPHERING_FAILURE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IDENTITY_RESPONSE_B_UP (TEDOStream* OStream, const c_IDENTITY_RESPONSE_B_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IDENTITY_RESPONSE_B_UP");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_RESPONSE_B_UP", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_RESPONSE_B_UP", "MobileId");
	ED_Dump_Struct_End (OStream, "IDENTITY_RESPONSE_B_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ROUTING_AREA_UPDATE_REQUEST_UP (TEDOStream* OStream, const c_ROUTING_AREA_UPDATE_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "UpdateType");
	  /* STRUCTURAL=<0> TYPE=<c_UpdateType> NAME=<UpdateType> ACCESS=<Data->UpdateType>  OPTIONAL=<0> FUNC=<Dump_c_UpdateType> */
	  Dump_c_UpdateType (OStream, &(Data->UpdateType));
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "UpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "GprsCiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GprsCiphKeySequenceNum> ACCESS=<Data->GprsCiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GprsCiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "GprsCiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "OldRoutingAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti> NAME=<OldRoutingAreaId> ACCESS=<Data->OldRoutingAreaId>  OPTIONAL=<0> FUNC=<Dump_c_RoutingAreaIdenti> */
	  Dump_c_RoutingAreaIdenti (OStream, &(Data->OldRoutingAreaId));
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "OldRoutingAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MsRadioAccessCpblty");
	  /* STRUCTURAL=<0> TYPE=<c_MsRadioAccessCpblty> NAME=<MsRadioAccessCpblty> ACCESS=<Data->MsRadioAccessCpblty>  OPTIONAL=<0> FUNC=<Dump_c_MsRadioAccessCpblty> */
	  Dump_c_MsRadioAccessCpblty (OStream, &(Data->MsRadioAccessCpblty));
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MsRadioAccessCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "OldPTmsiSign");
	if (!Data->OldPTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<OldPTmsiSign> ACCESS=<Data->OldPTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->OldPTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "OldPTmsiSign");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "ReqRdyTimerValue");
	if (!Data->ReqRdyTimerValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer> NAME=<ReqRdyTimerValue> ACCESS=<*(Data->ReqRdyTimerValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer> */
	  Dump_c_GprsTimer (OStream, &(*(Data->ReqRdyTimerValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "ReqRdyTimerValue");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "DrxParam");
	if (!Data->DrxParam_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DrxParam> NAME=<DrxParam> ACCESS=<*(Data->DrxParam)>  OPTIONAL=<1> FUNC=<Dump_c_DrxParam> */
	  Dump_c_DrxParam (OStream, &(*(Data->DrxParam)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "DrxParam");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "TmsiStatus");
	if (!Data->TmsiStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TmsiStatus> NAME=<TmsiStatus> ACCESS=<*(Data->TmsiStatus)>  OPTIONAL=<1> FUNC=<Dump_c_TmsiStatus> */
	  Dump_c_TmsiStatus (OStream, &(*(Data->TmsiStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "TmsiStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PTmsi");
	if (!Data->PTmsi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<PTmsi> ACCESS=<*(Data->PTmsi)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->PTmsi)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PTmsi");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MsNetwkCpblty");
	if (!Data->MsNetwkCpblty_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MsNetwkCpblty> NAME=<MsNetwkCpblty> ACCESS=<*(Data->MsNetwkCpblty)>  OPTIONAL=<1> FUNC=<Dump_c_MsNetwkCpblty> */
	  Dump_c_MsNetwkCpblty (OStream, &(*(Data->MsNetwkCpblty)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MsNetwkCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PdpContextStatus");
	if (!Data->PdpContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PdpContextStatus> NAME=<PdpContextStatus> ACCESS=<*(Data->PdpContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_PdpContextStatus> */
	  Dump_c_PdpContextStatus (OStream, &(*(Data->PdpContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PdpContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PSLCSCapability");
	if (!Data->PSLCSCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PSLCSCapabilit> NAME=<PSLCSCapability> ACCESS=<*(Data->PSLCSCapability)>  OPTIONAL=<1> FUNC=<Dump_c_PSLCSCapabilit> */
	  Dump_c_PSLCSCapabilit (OStream, &(*(Data->PSLCSCapability)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PSLCSCapability");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MBMSContextStatus");
	if (!Data->MBMSContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSContextStatus> ACCESS=<*(Data->MBMSContextStatus)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSContextStatus->value, Data->MBMSContextStatus->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MBMSContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "UENetworkCapability");
	if (!Data->UENetworkCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UENetworkCapability> ACCESS=<*(Data->UENetworkCapability)>  MAXBITSIZE=<104> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UENetworkCapability->value, Data->UENetworkCapability->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "UENetworkCapability");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "AdditionalMobileIdentity");
	if (!Data->AdditionalMobileIdentity_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<AdditionalMobileIdentity> ACCESS=<*(Data->AdditionalMobileIdentity)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->AdditionalMobileIdentity)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "AdditionalMobileIdentity");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "AdditionalOldRoutingAreaIdent");
	if (!Data->AdditionalOldRoutingAreaIdent_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti2> NAME=<AdditionalOldRoutingAreaIdent> ACCESS=<*(Data->AdditionalOldRoutingAreaIdent)>  OPTIONAL=<1> FUNC=<Dump_c_RoutingAreaIdenti2> */
	  Dump_c_RoutingAreaIdenti2 (OStream, &(*(Data->AdditionalOldRoutingAreaIdent)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "AdditionalOldRoutingAreaIdent");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MobileStationClassmark2");
	if (!Data->MobileStationClassmark2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileStationClassmark2> NAME=<MobileStationClassmark2> ACCESS=<*(Data->MobileStationClassmark2)>  OPTIONAL=<1> FUNC=<Dump_c_MobileStationClassmark2> */
	  Dump_c_MobileStationClassmark2 (OStream, &(*(Data->MobileStationClassmark2)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MobileStationClassmark2");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MobileStationClassmark3");
	if (!Data->MobileStationClassmark3_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Classmark3Value> NAME=<MobileStationClassmark3> ACCESS=<*(Data->MobileStationClassmark3)>  OPTIONAL=<1> FUNC=<Dump_c_Classmark3Value> */
	  Dump_c_Classmark3Value (OStream, &(*(Data->MobileStationClassmark3)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MobileStationClassmark3");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "SupportedCodecs");
	if (!Data->SupportedCodecs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SupportedCodecList> NAME=<SupportedCodecs> ACCESS=<*(Data->SupportedCodecs)>  OPTIONAL=<1> FUNC=<Dump_c_SupportedCodecList> */
	  Dump_c_SupportedCodecList (OStream, &(*(Data->SupportedCodecs)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "SupportedCodecs");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "VoiceDomainPrefUEUsageSetting");
	if (!Data->VoiceDomainPrefUEUsageSetting_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_VoiceDomainPreferenceAndUEsUsageSetting> NAME=<VoiceDomainPrefUEUsageSetting> ACCESS=<*(Data->VoiceDomainPrefUEUsageSetting)>  OPTIONAL=<1> FUNC=<Dump_c_VoiceDomainPreferenceAndUEsUsageSetting> */
	  Dump_c_VoiceDomainPreferenceAndUEsUsageSetting (OStream, &(*(Data->VoiceDomainPrefUEUsageSetting)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "VoiceDomainPrefUEUsageSetting");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PTMSI");
	if (!Data->PTMSI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PTMSI_Type> NAME=<PTMSI> ACCESS=<*(Data->PTMSI)>  OPTIONAL=<1> FUNC=<Dump_c_PTMSI_Type> */
	  Dump_c_PTMSI_Type (OStream, &(*(Data->PTMSI)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "PTMSI");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MSNetworkFeatureSupport");
	if (!Data->MSNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MSNetworkFeatureSupport> NAME=<MSNetworkFeatureSupport> ACCESS=<*(Data->MSNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_MSNetworkFeatureSupport> */
	  Dump_c_MSNetworkFeatureSupport (OStream, &(*(Data->MSNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "MSNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "OldLocationAreaId");
	if (!Data->OldLocationAreaId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<OldLocationAreaId> ACCESS=<Data->OldLocationAreaId>  MAXBITSIZE=<40> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->OldLocationAreaId, 40);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "OldLocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "AdditionalUpdateType");
	if (!Data->AdditionalUpdateType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalUpdateType> NAME=<AdditionalUpdateType> ACCESS=<*(Data->AdditionalUpdateType)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalUpdateType> */
	  Dump_c_AdditionalUpdateType (OStream, &(*(Data->AdditionalUpdateType)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "AdditionalUpdateType");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "TMSIBasedNRIContainer");
	if (!Data->TMSIBasedNRIContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetworkResourceIdContainer> NAME=<TMSIBasedNRIContainer> ACCESS=<*(Data->TMSIBasedNRIContainer)>  OPTIONAL=<1> FUNC=<Dump_c_NetworkResourceIdContainer> */
	  Dump_c_NetworkResourceIdContainer (OStream, &(*(Data->TMSIBasedNRIContainer)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "TMSIBasedNRIContainer");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "T3324Value");
	if (!Data->T3324Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3324Value> ACCESS=<*(Data->T3324Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3324Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "T3324Value");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "T3312ExtendedValue");
	if (!Data->T3312ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3312ExtendedValue> ACCESS=<*(Data->T3312ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3312ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "T3312ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_ExtendedDRXParameters> */
	  Dump_c_ExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "ROUTING_AREA_UPDATE_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ROUTING_AREA_UPDATE_COMPLETE_UP (TEDOStream* OStream, const c_ROUTING_AREA_UPDATE_COMPLETE_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP", "ListOfReceiveNPduNumbers");
	if (!Data->ListOfReceiveNPduNumbers_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ReceiveNPduNumbersList> NAME=<ListOfReceiveNPduNumbers> ACCESS=<*(Data->ListOfReceiveNPduNumbers)>  OPTIONAL=<1> FUNC=<Dump_c_ReceiveNPduNumbersList> */
	  Dump_c_ReceiveNPduNumbersList (OStream, &(*(Data->ListOfReceiveNPduNumbers)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP", "ListOfReceiveNPduNumbers");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP", "InterRATHandoverInfo");
	if (!Data->InterRATHandoverInfo_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<InterRATHandoverInfo> ACCESS=<*(Data->InterRATHandoverInfo)>  MAXBITSIZE=<1984> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->InterRATHandoverInfo->value, Data->InterRATHandoverInfo->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP", "InterRATHandoverInfo");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP", "E_UTRAN_InterRATHandoverInfo");
	if (!Data->E_UTRAN_InterRATHandoverInfo_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<E_UTRAN_InterRATHandoverInfo> ACCESS=<*(Data->E_UTRAN_InterRATHandoverInfo)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->E_UTRAN_InterRATHandoverInfo->value, Data->E_UTRAN_InterRATHandoverInfo->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP", "E_UTRAN_InterRATHandoverInfo");
	ED_Dump_Struct_End (OStream, "ROUTING_AREA_UPDATE_COMPLETE_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GMM_STATUS (TEDOStream* OStream, const c_GMM_STATUS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GMM_STATUS");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_STATUS", "GmmCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	ED_Dump_Struct_End_Field (OStream, "GMM_STATUS", "GmmCause");
	ED_Dump_Struct_End (OStream, "GMM_STATUS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SERVICE_REQUEST_UP (TEDOStream* OStream, const c_SERVICE_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SERVICE_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "CiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CiphKeySequenceNum> ACCESS=<Data->CiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "CiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "ServType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ServType> ACCESS=<Data->ServType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ServType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Signalling"); break;
				case 1: OStream->WriteString (OStream, "Data"); break;
				case 2: OStream->WriteString (OStream, "Paging Response"); break;
				case 3: OStream->WriteString (OStream, "MBMS Multicast Service Reception"); break;
				case 4: OStream->WriteString (OStream, "MBMS Broadcast Service Reception"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "ServType");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "PTmsi");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<PTmsi> ACCESS=<Data->PTmsi>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->PTmsi));
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "PTmsi");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "PdpContextStatus");
	if (!Data->PdpContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PdpContextStatus> NAME=<PdpContextStatus> ACCESS=<*(Data->PdpContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_PdpContextStatus> */
	  Dump_c_PdpContextStatus (OStream, &(*(Data->PdpContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "PdpContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "MBMSContextStatus");
	if (!Data->MBMSContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSContextStatus> ACCESS=<*(Data->MBMSContextStatus)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSContextStatus->value, Data->MBMSContextStatus->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "MBMSContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "UplinkDataStatus");
	if (!Data->UplinkDataStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_UplinkDataStatus> NAME=<UplinkDataStatus> ACCESS=<*(Data->UplinkDataStatus)>  OPTIONAL=<1> FUNC=<Dump_c_UplinkDataStatus> */
	  Dump_c_UplinkDataStatus (OStream, &(*(Data->UplinkDataStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "UplinkDataStatus");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_End (OStream, "SERVICE_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_REJECT_DN (TEDOStream* OStream, const c_AUTHENTICATION_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_REJECT_DN");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_REQUEST_DN (TEDOStream* OStream, const c_AUTHENTICATION_REQUEST_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_REQUEST_DN");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST_DN", "CiphKeySequenceNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CiphKeySequenceNum> ACCESS=<Data->CiphKeySequenceNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CiphKeySequenceNum);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST_DN", "CiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST_DN", "AuthParamRandUmtsChallOrGsmChall");
	  /* NAME=<AuthParamRandUmtsChallOrGsmChall> ACCESS=<Data->AuthParamRandUmtsChallOrGsmChall>  MAXBITSIZE=<128> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AuthParamRandUmtsChallOrGsmChall, 128);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST_DN", "AuthParamRandUmtsChallOrGsmChall");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_REQUEST_DN", "AuthParamAutn");
	if (!Data->AuthParamAutn_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthParamAutn> ACCESS=<Data->AuthParamAutn>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthParamAutn, 128);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_REQUEST_DN", "AuthParamAutn");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_REQUEST_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CM_SERVICE_ACCEPT_DN (TEDOStream* OStream, const c_CM_SERVICE_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CM_SERVICE_ACCEPT_DN");
	ED_Dump_Struct_End (OStream, "CM_SERVICE_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CM_SERVICE_PROMPT_DN (TEDOStream* OStream, const c_CM_SERVICE_PROMPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CM_SERVICE_PROMPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_PROMPT_DN", "PdAndSapiOfCm");
	  /* STRUCTURAL=<0> TYPE=<c_PdAndSapiCcbs> NAME=<PdAndSapiOfCm> ACCESS=<Data->PdAndSapiOfCm>  OPTIONAL=<0> FUNC=<Dump_c_PdAndSapiCcbs> */
	  Dump_c_PdAndSapiCcbs (OStream, &(Data->PdAndSapiOfCm));
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_PROMPT_DN", "PdAndSapiOfCm");
	ED_Dump_Struct_End (OStream, "CM_SERVICE_PROMPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CM_SERVICE_REJECT_DN (TEDOStream* OStream, const c_CM_SERVICE_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CM_SERVICE_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REJECT_DN", "RejCause");
	  /* STRUCTURAL=<0> TYPE=<c_RejectCause> NAME=<RejCause> ACCESS=<Data->RejCause>  OPTIONAL=<0> FUNC=<Dump_c_RejectCause> */
	  Dump_c_RejectCause (OStream, &(Data->RejCause));
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REJECT_DN", "RejCause");
	ED_Dump_Struct_Begin_Field (OStream, "CM_SERVICE_REJECT_DN", "T3246Value");
	if (!Data->T3246Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<T3246Value> ACCESS=<Data->T3246Value>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
	  ED_Dump_Octet (OStream, Data->T3246Value);
	}
	ED_Dump_Struct_End_Field (OStream, "CM_SERVICE_REJECT_DN", "T3246Value");
	ED_Dump_Struct_End (OStream, "CM_SERVICE_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ABORT_DN (TEDOStream* OStream, const c_ABORT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ABORT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ABORT_DN", "RejCause");
	  /* STRUCTURAL=<0> TYPE=<c_RejectCause> NAME=<RejCause> ACCESS=<Data->RejCause>  OPTIONAL=<0> FUNC=<Dump_c_RejectCause> */
	  Dump_c_RejectCause (OStream, &(Data->RejCause));
	ED_Dump_Struct_End_Field (OStream, "ABORT_DN", "RejCause");
	ED_Dump_Struct_End (OStream, "ABORT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IDENTITY_REQUEST_DN (TEDOStream* OStream, const c_IDENTITY_REQUEST_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IDENTITY_REQUEST_DN");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST_DN", "IdType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IdType> ACCESS=<Data->IdType>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
#define DATA (Data->IdType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "IMSI"); break;
				case 2: OStream->WriteString (OStream, "IMEI"); break;
				case 3: OStream->WriteString (OStream, "IMEISV"); break;
				case 4: OStream->WriteString (OStream, "TMSI"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST_DN", "IdType");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST_DN", "SpareHalfOctet");
	ED_Dump_Struct_End (OStream, "IDENTITY_REQUEST_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LOCATION_UPDATING_ACCEPT_DN (TEDOStream* OStream, const c_LOCATION_UPDATING_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LOCATION_UPDATING_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "LocationAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_LocationAreaId> NAME=<LocationAreaId> ACCESS=<Data->LocationAreaId>  OPTIONAL=<0> FUNC=<Dump_c_LocationAreaId> */
	  Dump_c_LocationAreaId (OStream, &(Data->LocationAreaId));
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "LocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "MobileId");
	if (!Data->MobileId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<*(Data->MobileId)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->MobileId)));
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "MobileId");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "FollowOnProceed");
	if (!Data->FollowOnProceed_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_LOCATION_UPDATING_ACCEPT_DN_FollowOnProceed> NAME=<FollowOnProceed> ACCESS=<Data->FollowOnProceed>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "FollowOnProceed");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "CtsPermission");
	if (!Data->CtsPermission_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_LOCATION_UPDATING_ACCEPT_DN_CtsPermission> NAME=<CtsPermission> ACCESS=<Data->CtsPermission>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "CtsPermission");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "EquivPlmns");
	if (!Data->EquivPlmns_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PlmnList> NAME=<EquivPlmns> ACCESS=<*(Data->EquivPlmns)>  OPTIONAL=<1> FUNC=<Dump_c_PlmnList> */
	  Dump_c_PlmnList (OStream, &(*(Data->EquivPlmns)));
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "EquivPlmns");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "EmergencyNumberList");
	if (!Data->EmergencyNumberList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EmergencyNumberList> NAME=<EmergencyNumberList> ACCESS=<*(Data->EmergencyNumberList)>  OPTIONAL=<1> FUNC=<Dump_c_EmergencyNumberList> */
	  Dump_c_EmergencyNumberList (OStream, &(*(Data->EmergencyNumberList)));
	}
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_ACCEPT_DN", "EmergencyNumberList");
	ED_Dump_Struct_End (OStream, "LOCATION_UPDATING_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_LOCATION_UPDATING_REJECT_DN (TEDOStream* OStream, const c_LOCATION_UPDATING_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "LOCATION_UPDATING_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "LOCATION_UPDATING_REJECT_DN", "RejCause");
	  /* STRUCTURAL=<0> TYPE=<c_RejectCause> NAME=<RejCause> ACCESS=<Data->RejCause>  OPTIONAL=<0> FUNC=<Dump_c_RejectCause> */
	  Dump_c_RejectCause (OStream, &(Data->RejCause));
	ED_Dump_Struct_End_Field (OStream, "LOCATION_UPDATING_REJECT_DN", "RejCause");
	ED_Dump_Struct_End (OStream, "LOCATION_UPDATING_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MM_INFORMATION_DN (TEDOStream* OStream, const c_MM_INFORMATION_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MM_INFORMATION_DN");
	ED_Dump_Struct_Begin_Field (OStream, "MM_INFORMATION_DN", "FullNameForNetwk");
	if (!Data->FullNameForNetwk_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetwkName> NAME=<FullNameForNetwk> ACCESS=<*(Data->FullNameForNetwk)>  OPTIONAL=<1> FUNC=<Dump_c_NetwkName> */
	  Dump_c_NetwkName (OStream, &(*(Data->FullNameForNetwk)));
	}
	ED_Dump_Struct_End_Field (OStream, "MM_INFORMATION_DN", "FullNameForNetwk");
	ED_Dump_Struct_Begin_Field (OStream, "MM_INFORMATION_DN", "ShortNameForNetwk");
	if (!Data->ShortNameForNetwk_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetwkName> NAME=<ShortNameForNetwk> ACCESS=<*(Data->ShortNameForNetwk)>  OPTIONAL=<1> FUNC=<Dump_c_NetwkName> */
	  Dump_c_NetwkName (OStream, &(*(Data->ShortNameForNetwk)));
	}
	ED_Dump_Struct_End_Field (OStream, "MM_INFORMATION_DN", "ShortNameForNetwk");
	ED_Dump_Struct_Begin_Field (OStream, "MM_INFORMATION_DN", "LocalTimeZone");
	if (!Data->LocalTimeZone_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LocalTimeZone> ACCESS=<Data->LocalTimeZone>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LocalTimeZone);
	}
	ED_Dump_Struct_End_Field (OStream, "MM_INFORMATION_DN", "LocalTimeZone");
	ED_Dump_Struct_Begin_Field (OStream, "MM_INFORMATION_DN", "UniversalTimeAndLocalTimeZone");
	if (!Data->UniversalTimeAndLocalTimeZone_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TimeZoneAndTime> NAME=<UniversalTimeAndLocalTimeZone> ACCESS=<*(Data->UniversalTimeAndLocalTimeZone)>  OPTIONAL=<1> FUNC=<Dump_c_TimeZoneAndTime> */
	  Dump_c_TimeZoneAndTime (OStream, &(*(Data->UniversalTimeAndLocalTimeZone)));
	}
	ED_Dump_Struct_End_Field (OStream, "MM_INFORMATION_DN", "UniversalTimeAndLocalTimeZone");
	ED_Dump_Struct_Begin_Field (OStream, "MM_INFORMATION_DN", "LsaId");
	if (!Data->LsaId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LsaId> ACCESS=<*(Data->LsaId)>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LsaId->value, Data->LsaId->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MM_INFORMATION_DN", "LsaId");
	ED_Dump_Struct_Begin_Field (OStream, "MM_INFORMATION_DN", "NetwkDaylightSavingTime");
	if (!Data->NetwkDaylightSavingTime_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DaylightSavingTime> NAME=<NetwkDaylightSavingTime> ACCESS=<*(Data->NetwkDaylightSavingTime)>  OPTIONAL=<1> FUNC=<Dump_c_DaylightSavingTime> */
	  Dump_c_DaylightSavingTime (OStream, &(*(Data->NetwkDaylightSavingTime)));
	}
	ED_Dump_Struct_End_Field (OStream, "MM_INFORMATION_DN", "NetwkDaylightSavingTime");
	ED_Dump_Struct_End (OStream, "MM_INFORMATION_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_TMSI_REALLOCATION_COMMAND_DN (TEDOStream* OStream, const c_TMSI_REALLOCATION_COMMAND_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "TMSI_REALLOCATION_COMMAND_DN");
	ED_Dump_Struct_Begin_Field (OStream, "TMSI_REALLOCATION_COMMAND_DN", "LocationAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_LocationAreaId> NAME=<LocationAreaId> ACCESS=<Data->LocationAreaId>  OPTIONAL=<0> FUNC=<Dump_c_LocationAreaId> */
	  Dump_c_LocationAreaId (OStream, &(Data->LocationAreaId));
	ED_Dump_Struct_End_Field (OStream, "TMSI_REALLOCATION_COMMAND_DN", "LocationAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "TMSI_REALLOCATION_COMMAND_DN", "MobileId");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MobileId> ACCESS=<Data->MobileId>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->MobileId));
	ED_Dump_Struct_End_Field (OStream, "TMSI_REALLOCATION_COMMAND_DN", "MobileId");
	ED_Dump_Struct_End (OStream, "TMSI_REALLOCATION_COMMAND_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ALERTING_DN (TEDOStream* OStream, const c_ALERTING_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ALERTING_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ALERTING_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ALERTING_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ALERTING_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_DN", "ProgrInd");
	if (!Data->ProgrInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd> NAME=<ProgrInd> ACCESS=<*(Data->ProgrInd)>  OPTIONAL=<1> FUNC=<Dump_c_ProgrInd> */
	  Dump_c_ProgrInd (OStream, &(*(Data->ProgrInd)));
	}
	ED_Dump_Struct_End_Field (OStream, "ALERTING_DN", "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "ALERTING_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ALERTING_DN", "UserUser");
	ED_Dump_Struct_End (OStream, "ALERTING_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CALL_PROCEEDING_DN (TEDOStream* OStream, const c_CALL_PROCEEDING_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CALL_PROCEEDING_DN");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "RepeatInd");
	if (!Data->RepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RepeatInd> ACCESS=<Data->RepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "RepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "BearerCpblty1");
	if (!Data->BearerCpblty1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty1> ACCESS=<*(Data->BearerCpblty1)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty1)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "BearerCpblty1");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "BearerCpblty2");
	if (!Data->BearerCpblty2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty2> ACCESS=<*(Data->BearerCpblty2)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty2)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "BearerCpblty2");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "ProgrInd");
	if (!Data->ProgrInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd> NAME=<ProgrInd> ACCESS=<*(Data->ProgrInd)>  OPTIONAL=<1> FUNC=<Dump_c_ProgrInd> */
	  Dump_c_ProgrInd (OStream, &(*(Data->ProgrInd)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "PriorityGranted");
	if (!Data->PriorityGranted_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PriorityLevel> NAME=<PriorityGranted> ACCESS=<*(Data->PriorityGranted)>  OPTIONAL=<1> FUNC=<Dump_c_PriorityLevel> */
	  Dump_c_PriorityLevel (OStream, &(*(Data->PriorityGranted)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "PriorityGranted");
	ED_Dump_Struct_Begin_Field (OStream, "CALL_PROCEEDING_DN", "NetwkCallControlCapabil");
	if (!Data->NetwkCallControlCapabil_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetwkCallControlCapabil> NAME=<NetwkCallControlCapabil> ACCESS=<*(Data->NetwkCallControlCapabil)>  OPTIONAL=<1> FUNC=<Dump_c_NetwkCallControlCapabil> */
	  Dump_c_NetwkCallControlCapabil (OStream, &(*(Data->NetwkCallControlCapabil)));
	}
	ED_Dump_Struct_End_Field (OStream, "CALL_PROCEEDING_DN", "NetwkCallControlCapabil");
	ED_Dump_Struct_End (OStream, "CALL_PROCEEDING_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CONGESTION_CONTROL_DN (TEDOStream* OStream, const c_CONGESTION_CONTROL_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CONGESTION_CONTROL_DN");
	ED_Dump_Struct_Begin_Field (OStream, "CONGESTION_CONTROL_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CONGESTION_CONTROL_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CONGESTION_CONTROL_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CONGESTION_CONTROL_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CONGESTION_CONTROL_DN", "CongestionLevel");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CongestionLevel> ACCESS=<Data->CongestionLevel>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->CongestionLevel);
	ED_Dump_Struct_End_Field (OStream, "CONGESTION_CONTROL_DN", "CongestionLevel");
	ED_Dump_Struct_Begin_Field (OStream, "CONGESTION_CONTROL_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "CONGESTION_CONTROL_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "CONGESTION_CONTROL_DN", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONGESTION_CONTROL_DN", "Cause");
	ED_Dump_Struct_End (OStream, "CONGESTION_CONTROL_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CONNECT_DN (TEDOStream* OStream, const c_CONNECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CONNECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "ProgrInd");
	if (!Data->ProgrInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd> NAME=<ProgrInd> ACCESS=<*(Data->ProgrInd)>  OPTIONAL=<1> FUNC=<Dump_c_ProgrInd> */
	  Dump_c_ProgrInd (OStream, &(*(Data->ProgrInd)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "ConnNum");
	if (!Data->ConnNum_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ConnNum> NAME=<ConnNum> ACCESS=<*(Data->ConnNum)>  OPTIONAL=<1> FUNC=<Dump_c_ConnNum> */
	  Dump_c_ConnNum (OStream, &(*(Data->ConnNum)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "ConnNum");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "ConnSubaddr");
	if (!Data->ConnSubaddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ConnSubaddres> NAME=<ConnSubaddr> ACCESS=<*(Data->ConnSubaddr)>  OPTIONAL=<1> FUNC=<Dump_c_ConnSubaddres> */
	  Dump_c_ConnSubaddres (OStream, &(*(Data->ConnSubaddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "ConnSubaddr");
	ED_Dump_Struct_Begin_Field (OStream, "CONNECT_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "CONNECT_DN", "UserUser");
	ED_Dump_Struct_End (OStream, "CONNECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DISCONNECT_DN (TEDOStream* OStream, const c_DISCONNECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DISCONNECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "ProgrInd");
	if (!Data->ProgrInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd> NAME=<ProgrInd> ACCESS=<*(Data->ProgrInd)>  OPTIONAL=<1> FUNC=<Dump_c_ProgrInd> */
	  Dump_c_ProgrInd (OStream, &(*(Data->ProgrInd)));
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "DISCONNECT_DN", "AllowedActionsCcbs");
	if (!Data->AllowedActionsCcbs_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AllowedActionsCcbs> NAME=<AllowedActionsCcbs> ACCESS=<*(Data->AllowedActionsCcbs)>  OPTIONAL=<1> FUNC=<Dump_c_AllowedActionsCcbs> */
	  Dump_c_AllowedActionsCcbs (OStream, &(*(Data->AllowedActionsCcbs)));
	}
	ED_Dump_Struct_End_Field (OStream, "DISCONNECT_DN", "AllowedActionsCcbs");
	ED_Dump_Struct_End (OStream, "DISCONNECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_FACILITY_DN (TEDOStream* OStream, const c_FACILITY_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "FACILITY_DN");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "FACILITY_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "FACILITY_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "FACILITY_DN", "Facility");
	  /* NAME=<Facility> ACCESS=<Data->Facility>  MAXBITSIZE=<4792> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Facility.value, Data->Facility.usedBits);
	ED_Dump_Struct_End_Field (OStream, "FACILITY_DN", "Facility");
	ED_Dump_Struct_End (OStream, "FACILITY_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_HOLD_ACKNOWLEDGE_DN (TEDOStream* OStream, const c_HOLD_ACKNOWLEDGE_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "HOLD_ACKNOWLEDGE_DN");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_ACKNOWLEDGE_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "HOLD_ACKNOWLEDGE_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_ACKNOWLEDGE_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "HOLD_ACKNOWLEDGE_DN", "TI_Flag");
	ED_Dump_Struct_End (OStream, "HOLD_ACKNOWLEDGE_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_HOLD_REJECT_DN (TEDOStream* OStream, const c_HOLD_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "HOLD_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_REJECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "HOLD_REJECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_REJECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "HOLD_REJECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "HOLD_REJECT_DN", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "HOLD_REJECT_DN", "Cause");
	ED_Dump_Struct_End (OStream, "HOLD_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_PROGRESS_DN (TEDOStream* OStream, const c_PROGRESS_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "PROGRESS_DN");
	ED_Dump_Struct_Begin_Field (OStream, "PROGRESS_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "PROGRESS_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "PROGRESS_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "PROGRESS_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "PROGRESS_DN", "ProgrInd");
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd> NAME=<ProgrInd> ACCESS=<Data->ProgrInd>  OPTIONAL=<0> FUNC=<Dump_c_ProgrInd> */
	  Dump_c_ProgrInd (OStream, &(Data->ProgrInd));
	ED_Dump_Struct_End_Field (OStream, "PROGRESS_DN", "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "PROGRESS_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "PROGRESS_DN", "UserUser");
	ED_Dump_Struct_End (OStream, "PROGRESS_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_CC_ESTABLISHMENT_DN (TEDOStream* OStream, const c_CC_ESTABLISHMENT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "CC_ESTABLISHMENT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "CC_ESTABLISHMENT_DN", "SetupContainer");
	  /* STRUCTURAL=<0> TYPE=<c_SETUP_UP> NAME=<SetupContainer> ACCESS=<Data->SetupContainer>  OPTIONAL=<0> FUNC=<Dump_c_SETUP_UP> */
	  Dump_c_SETUP_UP (OStream, &(Data->SetupContainer));
	ED_Dump_Struct_End_Field (OStream, "CC_ESTABLISHMENT_DN", "SetupContainer");
	ED_Dump_Struct_End (OStream, "CC_ESTABLISHMENT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RELEASE_DN (TEDOStream* OStream, const c_RELEASE_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RELEASE_DN");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_DN", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_DN", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_DN", "SecondCause");
	if (!Data->SecondCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<SecondCause> ACCESS=<*(Data->SecondCause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->SecondCause)));
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_DN", "SecondCause");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_DN", "UserUser");
	ED_Dump_Struct_End (OStream, "RELEASE_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RECALL_DN (TEDOStream* OStream, const c_RECALL_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RECALL_DN");
	ED_Dump_Struct_Begin_Field (OStream, "RECALL_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RECALL_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RECALL_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RECALL_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "RECALL_DN", "RecallType");
	  /* STRUCTURAL=<0> TYPE=<c_RecallType> NAME=<RecallType> ACCESS=<Data->RecallType>  OPTIONAL=<0> FUNC=<Dump_c_RecallType> */
	  Dump_c_RecallType (OStream, &(Data->RecallType));
	ED_Dump_Struct_End_Field (OStream, "RECALL_DN", "RecallType");
	ED_Dump_Struct_Begin_Field (OStream, "RECALL_DN", "Facility");
	  /* NAME=<Facility> ACCESS=<Data->Facility>  MAXBITSIZE=<4792> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->Facility.value, Data->Facility.usedBits);
	ED_Dump_Struct_End_Field (OStream, "RECALL_DN", "Facility");
	ED_Dump_Struct_End (OStream, "RECALL_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RELEASE_COMPLETE_DN (TEDOStream* OStream, const c_RELEASE_COMPLETE_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RELEASE_COMPLETE_DN");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_DN", "Cause");
	if (!Data->Cause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<*(Data->Cause)>  OPTIONAL=<1> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(*(Data->Cause)));
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_DN", "Cause");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "RELEASE_COMPLETE_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<1032> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "RELEASE_COMPLETE_DN", "UserUser");
	ED_Dump_Struct_End (OStream, "RELEASE_COMPLETE_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RETRIEVE_ACKNOWLEDGE_DN (TEDOStream* OStream, const c_RETRIEVE_ACKNOWLEDGE_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RETRIEVE_ACKNOWLEDGE_DN");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_ACKNOWLEDGE_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_ACKNOWLEDGE_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_ACKNOWLEDGE_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_ACKNOWLEDGE_DN", "TI_Flag");
	ED_Dump_Struct_End (OStream, "RETRIEVE_ACKNOWLEDGE_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_RETRIEVE_REJECT_DN (TEDOStream* OStream, const c_RETRIEVE_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "RETRIEVE_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_REJECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_REJECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_REJECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_REJECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "RETRIEVE_REJECT_DN", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "RETRIEVE_REJECT_DN", "Cause");
	ED_Dump_Struct_End (OStream, "RETRIEVE_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SETUP_DN (TEDOStream* OStream, const c_SETUP_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SETUP_DN");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "BcRepeatInd");
	if (!Data->BcRepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<BcRepeatInd> ACCESS=<Data->BcRepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->BcRepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "BcRepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "BearerCpblty1");
	if (!Data->BearerCpblty1_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty1> ACCESS=<*(Data->BearerCpblty1)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty1)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "BearerCpblty1");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "BearerCpblty2");
	if (!Data->BearerCpblty2_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BearerCpblty> NAME=<BearerCpblty2> ACCESS=<*(Data->BearerCpblty2)>  OPTIONAL=<1> FUNC=<Dump_c_BearerCpblty> */
	  Dump_c_BearerCpblty (OStream, &(*(Data->BearerCpblty2)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "BearerCpblty2");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "Facility");
	if (!Data->Facility_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<Facility> ACCESS=<*(Data->Facility)>  MAXBITSIZE=<4784> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->Facility->value, Data->Facility->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "Facility");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "ProgrInd");
	if (!Data->ProgrInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProgrInd> NAME=<ProgrInd> ACCESS=<*(Data->ProgrInd)>  OPTIONAL=<1> FUNC=<Dump_c_ProgrInd> */
	  Dump_c_ProgrInd (OStream, &(*(Data->ProgrInd)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "ProgrInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "Signal");
	if (!Data->Signal_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<Signal> ACCESS=<Data->Signal>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->Signal)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "dial tone on"); break;
				case 1: OStream->WriteString (OStream, "ring back tone on"); break;
				case 2: OStream->WriteString (OStream, "intercept tone on"); break;
				case 3: OStream->WriteString (OStream, "network congestion tone on"); break;
				case 4: OStream->WriteString (OStream, "busy tone on"); break;
				case 5: OStream->WriteString (OStream, "confirm tone on"); break;
				case 6: OStream->WriteString (OStream, "answer tone on"); break;
				case 7: OStream->WriteString (OStream, "call waiting tone on"); break;
				case 8: OStream->WriteString (OStream, "off-hook warning tone on"); break;
				case 63: OStream->WriteString (OStream, "tones off"); break;
				case 79: OStream->WriteString (OStream, "alerting off"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "Signal");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "CallingPartyBcdNum");
	if (!Data->CallingPartyBcdNum_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CallingPartyBcdNum> NAME=<CallingPartyBcdNum> ACCESS=<*(Data->CallingPartyBcdNum)>  OPTIONAL=<1> FUNC=<Dump_c_CallingPartyBcdNum> */
	  Dump_c_CallingPartyBcdNum (OStream, &(*(Data->CallingPartyBcdNum)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "CallingPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "CallingPartySubAddr");
	if (!Data->CallingPartySubAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CallingPartySubaddr> NAME=<CallingPartySubAddr> ACCESS=<*(Data->CallingPartySubAddr)>  OPTIONAL=<1> FUNC=<Dump_c_CallingPartySubaddr> */
	  Dump_c_CallingPartySubaddr (OStream, &(*(Data->CallingPartySubAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "CallingPartySubAddr");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "CalledPartyBcdNum");
	if (!Data->CalledPartyBcdNum_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CalledPartyBcdNum> NAME=<CalledPartyBcdNum> ACCESS=<*(Data->CalledPartyBcdNum)>  OPTIONAL=<1> FUNC=<Dump_c_CalledPartyBcdNum> */
	  Dump_c_CalledPartyBcdNum (OStream, &(*(Data->CalledPartyBcdNum)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "CalledPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "CalledPartySubAddr");
	if (!Data->CalledPartySubAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_CalledPartySubaddr> NAME=<CalledPartySubAddr> ACCESS=<*(Data->CalledPartySubAddr)>  OPTIONAL=<1> FUNC=<Dump_c_CalledPartySubaddr> */
	  Dump_c_CalledPartySubaddr (OStream, &(*(Data->CalledPartySubAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "CalledPartySubAddr");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "RedirPartyBcdNum");
	if (!Data->RedirPartyBcdNum_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RedirPartyBcdNum> NAME=<RedirPartyBcdNum> ACCESS=<*(Data->RedirPartyBcdNum)>  OPTIONAL=<1> FUNC=<Dump_c_RedirPartyBcdNum> */
	  Dump_c_RedirPartyBcdNum (OStream, &(*(Data->RedirPartyBcdNum)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "RedirPartyBcdNum");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "RedirPartySubAddr");
	if (!Data->RedirPartySubAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RedirPartySubaddr> NAME=<RedirPartySubAddr> ACCESS=<*(Data->RedirPartySubAddr)>  OPTIONAL=<1> FUNC=<Dump_c_RedirPartySubaddr> */
	  Dump_c_RedirPartySubaddr (OStream, &(*(Data->RedirPartySubAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "RedirPartySubAddr");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "LlcRepeatInd");
	if (!Data->LlcRepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LlcRepeatInd> ACCESS=<Data->LlcRepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LlcRepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "LlcRepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "LowLayerCpbilityI");
	if (!Data->LowLayerCpbilityI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerCpbilityI> ACCESS=<*(Data->LowLayerCpbilityI)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerCpbilityI->value, Data->LowLayerCpbilityI->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "LowLayerCpbilityI");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "LowLayerCpbilityIi");
	if (!Data->LowLayerCpbilityIi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LowLayerCpbilityIi> ACCESS=<*(Data->LowLayerCpbilityIi)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LowLayerCpbilityIi->value, Data->LowLayerCpbilityIi->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "LowLayerCpbilityIi");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "HlcRepeatInd");
	if (!Data->HlcRepeatInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<HlcRepeatInd> ACCESS=<Data->HlcRepeatInd>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->HlcRepeatInd);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "HlcRepeatInd");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "HighLayerCpbilityI");
	if (!Data->HighLayerCpbilityI_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerCpbilityI> ACCESS=<*(Data->HighLayerCpbilityI)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerCpbilityI)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "HighLayerCpbilityI");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "HighLayerCpbilityIi");
	if (!Data->HighLayerCpbilityIi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_HighLayerCpbility> NAME=<HighLayerCpbilityIi> ACCESS=<*(Data->HighLayerCpbilityIi)>  OPTIONAL=<1> FUNC=<Dump_c_HighLayerCpbility> */
	  Dump_c_HighLayerCpbility (OStream, &(*(Data->HighLayerCpbilityIi)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "HighLayerCpbilityIi");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "UserUser");
	if (!Data->UserUser_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<UserUser> ACCESS=<*(Data->UserUser)>  MAXBITSIZE=<264> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->UserUser->value, Data->UserUser->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "UserUser");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "Priority");
	if (!Data->Priority_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PriorityLevel> NAME=<Priority> ACCESS=<*(Data->Priority)>  OPTIONAL=<1> FUNC=<Dump_c_PriorityLevel> */
	  Dump_c_PriorityLevel (OStream, &(*(Data->Priority)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "Priority");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "Alert");
	if (!Data->Alert_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AlertingPattern> NAME=<Alert> ACCESS=<*(Data->Alert)>  OPTIONAL=<1> FUNC=<Dump_c_AlertingPattern> */
	  Dump_c_AlertingPattern (OStream, &(*(Data->Alert)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "Alert");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "NetwkCallControlCapabil");
	if (!Data->NetwkCallControlCapabil_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetwkCallControlCapabil> NAME=<NetwkCallControlCapabil> ACCESS=<*(Data->NetwkCallControlCapabil)>  OPTIONAL=<1> FUNC=<Dump_c_NetwkCallControlCapabil> */
	  Dump_c_NetwkCallControlCapabil (OStream, &(*(Data->NetwkCallControlCapabil)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "NetwkCallControlCapabil");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "CauseOfNoCli");
	if (!Data->CauseOfNoCli_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CauseOfNoCli> ACCESS=<Data->CauseOfNoCli>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CauseOfNoCli)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Unavailable"); break;
				case 1: OStream->WriteString (OStream, "Reject by user"); break;
				case 2: OStream->WriteString (OStream, "Interaction with other service"); break;
				case 3: OStream->WriteString (OStream, "Coin line/payphone"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "CauseOfNoCli");
	ED_Dump_Struct_Begin_Field (OStream, "SETUP_DN", "BackupBearerCapability");
	if (!Data->BackupBearerCapability_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_BackupBearerCapability> NAME=<BackupBearerCapability> ACCESS=<*(Data->BackupBearerCapability)>  OPTIONAL=<1> FUNC=<Dump_c_BackupBearerCapability> */
	  Dump_c_BackupBearerCapability (OStream, &(*(Data->BackupBearerCapability)));
	}
	ED_Dump_Struct_End_Field (OStream, "SETUP_DN", "BackupBearerCapability");
	ED_Dump_Struct_End (OStream, "SETUP_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_START_DTMF_ACKNOWLEDGE_DN (TEDOStream* OStream, const c_START_DTMF_ACKNOWLEDGE_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "START_DTMF_ACKNOWLEDGE_DN");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_ACKNOWLEDGE_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_ACKNOWLEDGE_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_ACKNOWLEDGE_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_ACKNOWLEDGE_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_ACKNOWLEDGE_DN", "KeypadFacility");
	  /* STRUCTURAL=<0> TYPE=<c_KeypadFacility> NAME=<KeypadFacility> ACCESS=<Data->KeypadFacility>  OPTIONAL=<0> FUNC=<Dump_c_KeypadFacility> */
	  Dump_c_KeypadFacility (OStream, &(Data->KeypadFacility));
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_ACKNOWLEDGE_DN", "KeypadFacility");
	ED_Dump_Struct_End (OStream, "START_DTMF_ACKNOWLEDGE_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_START_DTMF_REJECT_DN (TEDOStream* OStream, const c_START_DTMF_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "START_DTMF_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_REJECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_REJECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_REJECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_REJECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "START_DTMF_REJECT_DN", "Cause");
	  /* STRUCTURAL=<0> TYPE=<c_Cause> NAME=<Cause> ACCESS=<Data->Cause>  OPTIONAL=<0> FUNC=<Dump_c_Cause> */
	  Dump_c_Cause (OStream, &(Data->Cause));
	ED_Dump_Struct_End_Field (OStream, "START_DTMF_REJECT_DN", "Cause");
	ED_Dump_Struct_End (OStream, "START_DTMF_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_STOP_DTMF_ACKNOWLEDGE_DN (TEDOStream* OStream, const c_STOP_DTMF_ACKNOWLEDGE_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "STOP_DTMF_ACKNOWLEDGE_DN");
	ED_Dump_Struct_Begin_Field (OStream, "STOP_DTMF_ACKNOWLEDGE_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "STOP_DTMF_ACKNOWLEDGE_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "STOP_DTMF_ACKNOWLEDGE_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "STOP_DTMF_ACKNOWLEDGE_DN", "TI_Flag");
	ED_Dump_Struct_End (OStream, "STOP_DTMF_ACKNOWLEDGE_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_ACCEPT_DN (TEDOStream* OStream, const c_ATTACH_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "AttachResult");
	  /* STRUCTURAL=<0> TYPE=<c_AttachResult> NAME=<AttachResult> ACCESS=<Data->AttachResult>  OPTIONAL=<0> FUNC=<Dump_c_AttachResult> */
	  Dump_c_AttachResult (OStream, &(Data->AttachResult));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "AttachResult");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "PeriodicRaUpdateTimer");
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer> NAME=<PeriodicRaUpdateTimer> ACCESS=<Data->PeriodicRaUpdateTimer>  OPTIONAL=<0> FUNC=<Dump_c_GprsTimer> */
	  Dump_c_GprsTimer (OStream, &(Data->PeriodicRaUpdateTimer));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "PeriodicRaUpdateTimer");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "RadioPriorityForSms");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriorityForSms> ACCESS=<Data->RadioPriorityForSms>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriorityForSms);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "RadioPriorityForSms");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "RoutingAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti> NAME=<RoutingAreaId> ACCESS=<Data->RoutingAreaId>  OPTIONAL=<0> FUNC=<Dump_c_RoutingAreaIdenti> */
	  Dump_c_RoutingAreaIdenti (OStream, &(Data->RoutingAreaId));
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "RoutingAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "PTmsiSign");
	if (!Data->PTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<PTmsiSign> ACCESS=<Data->PTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->PTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "PTmsiSign");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "NegotiatedRdyTimerValue");
	if (!Data->NegotiatedRdyTimerValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer> NAME=<NegotiatedRdyTimerValue> ACCESS=<*(Data->NegotiatedRdyTimerValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer> */
	  Dump_c_GprsTimer (OStream, &(*(Data->NegotiatedRdyTimerValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "NegotiatedRdyTimerValue");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "AllocatedPTmsi");
	if (!Data->AllocatedPTmsi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<AllocatedPTmsi> ACCESS=<*(Data->AllocatedPTmsi)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->AllocatedPTmsi)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "AllocatedPTmsi");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "MsId");
	if (!Data->MsId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MsId> ACCESS=<*(Data->MsId)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->MsId)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "MsId");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "GmmCause");
	if (!Data->GmmCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "GmmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "T3302Value");
	if (!Data->T3302Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3302Value> ACCESS=<*(Data->T3302Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3302Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "T3302Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "CellNotif");
	if (!Data->CellNotif_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ATTACH_ACCEPT_DN_CellNotif> NAME=<CellNotif> ACCESS=<Data->CellNotif>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "CellNotif");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "EquivPlmns");
	if (!Data->EquivPlmns_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PlmnList> NAME=<EquivPlmns> ACCESS=<*(Data->EquivPlmns)>  OPTIONAL=<1> FUNC=<Dump_c_PlmnList> */
	  Dump_c_PlmnList (OStream, &(*(Data->EquivPlmns)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "EquivPlmns");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "NetworkFeatureSupport");
	if (!Data->NetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetworkFeatureSupport> NAME=<NetworkFeatureSupport> ACCESS=<*(Data->NetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_NetworkFeatureSupport> */
	  Dump_c_NetworkFeatureSupport (OStream, &(*(Data->NetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "NetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "EmergencyNumberList");
	if (!Data->EmergencyNumberList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EmergencyNumberList> NAME=<EmergencyNumberList> ACCESS=<*(Data->EmergencyNumberList)>  OPTIONAL=<1> FUNC=<Dump_c_EmergencyNumberList> */
	  Dump_c_EmergencyNumberList (OStream, &(*(Data->EmergencyNumberList)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "EmergencyNumberList");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "RequestedMSInformation");
	if (!Data->RequestedMSInformation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RequestedMSInformation> NAME=<RequestedMSInformation> ACCESS=<*(Data->RequestedMSInformation)>  OPTIONAL=<1> FUNC=<Dump_c_RequestedMSInformation> */
	  Dump_c_RequestedMSInformation (OStream, &(*(Data->RequestedMSInformation)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "RequestedMSInformation");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "T3319Value");
	if (!Data->T3319Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3319Value> ACCESS=<*(Data->T3319Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3319Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "T3319Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "T3323Value");
	if (!Data->T3323Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3323Value> ACCESS=<*(Data->T3323Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3323Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "T3323Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "T3312ExtendedValue");
	if (!Data->T3312ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3312ExtendedValue> ACCESS=<*(Data->T3312ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3312ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "T3312ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "AdditionalNetworkFeatureSupport");
	if (!Data->AdditionalNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalNetworkFeatureSupport> NAME=<AdditionalNetworkFeatureSupport> ACCESS=<*(Data->AdditionalNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalNetworkFeatureSupport> */
	  Dump_c_AdditionalNetworkFeatureSupport (OStream, &(*(Data->AdditionalNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "AdditionalNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "T3324Value");
	if (!Data->T3324Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3324Value> ACCESS=<*(Data->T3324Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3324Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "T3324Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_ACCEPT_DN", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_ExtendedDRXParameters> */
	  Dump_c_ExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_ACCEPT_DN", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "ATTACH_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ATTACH_REJECT_DN (TEDOStream* OStream, const c_ATTACH_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ATTACH_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT_DN", "GmmCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT_DN", "GmmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT_DN", "T3302Value");
	if (!Data->T3302Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3302Value> ACCESS=<*(Data->T3302Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3302Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT_DN", "T3302Value");
	ED_Dump_Struct_Begin_Field (OStream, "ATTACH_REJECT_DN", "T3346Value");
	if (!Data->T3346Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3346Value> ACCESS=<*(Data->T3346Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3346Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ATTACH_REJECT_DN", "T3346Value");
	ED_Dump_Struct_End (OStream, "ATTACH_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DETACH_REQUEST_DN (TEDOStream* OStream, const c_DETACH_REQUEST_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DETACH_REQUEST_DN");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_DN", "DetachType");
	  /* STRUCTURAL=<0> TYPE=<c_DetachType> NAME=<DetachType> ACCESS=<Data->DetachType>  OPTIONAL=<0> FUNC=<Dump_c_DetachType> */
	  Dump_c_DetachType (OStream, &(Data->DetachType));
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_DN", "DetachType");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_REQUEST_DN", "GmmCause");
	if (!Data->GmmCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	}
	ED_Dump_Struct_End_Field (OStream, "DETACH_REQUEST_DN", "GmmCause");
	ED_Dump_Struct_End (OStream, "DETACH_REQUEST_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DETACH_ACCEPT_DN (TEDOStream* OStream, const c_DETACH_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DETACH_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_ACCEPT_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "DETACH_ACCEPT_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "DETACH_ACCEPT_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "DETACH_ACCEPT_DN", "SpareHalfOctet");
	ED_Dump_Struct_End (OStream, "DETACH_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_P_TMSI_REALLOCATION_COMMAND_DN (TEDOStream* OStream, const c_P_TMSI_REALLOCATION_COMMAND_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "P_TMSI_REALLOCATION_COMMAND_DN");
	ED_Dump_Struct_Begin_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "AllocatedPTmsi");
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<AllocatedPTmsi> ACCESS=<Data->AllocatedPTmsi>  OPTIONAL=<0> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(Data->AllocatedPTmsi));
	ED_Dump_Struct_End_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "AllocatedPTmsi");
	ED_Dump_Struct_Begin_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "RoutingAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti> NAME=<RoutingAreaId> ACCESS=<Data->RoutingAreaId>  OPTIONAL=<0> FUNC=<Dump_c_RoutingAreaIdenti> */
	  Dump_c_RoutingAreaIdenti (OStream, &(Data->RoutingAreaId));
	ED_Dump_Struct_End_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "RoutingAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "PTmsiSign");
	if (!Data->PTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<PTmsiSign> ACCESS=<Data->PTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->PTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "P_TMSI_REALLOCATION_COMMAND_DN", "PTmsiSign");
	ED_Dump_Struct_End (OStream, "P_TMSI_REALLOCATION_COMMAND_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (TEDOStream* OStream, const c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "CiphAlg");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<CiphAlg> ACCESS=<Data->CiphAlg>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->CiphAlg)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "ciphering not used"); break;
				case 1: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/1"); break;
				case 2: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/2"); break;
				case 3: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/3"); break;
				case 4: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/4"); break;
				case 5: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/5"); break;
				case 6: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/6"); break;
				case 7: OStream->WriteString (OStream, "GPRS Encryption Algorithm GEA/7"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "CiphAlg");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "ImeisvReq");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ImeisvReq> ACCESS=<Data->ImeisvReq>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ImeisvReq)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "IMEISV not requested"); break;
				case 1: OStream->WriteString (OStream, "IMEISV requested"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "ImeisvReq");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "ACRefNum");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ACRefNum> ACCESS=<Data->ACRefNum>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ACRefNum);
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "ACRefNum");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "AuthParamRand");
	if (!Data->AuthParamRand_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthParamRand> ACCESS=<Data->AuthParamRand>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthParamRand, 128);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "AuthParamRand");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "GprsCiphKeySequenceNum");
	if (!Data->GprsCiphKeySequenceNum_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GprsCiphKeySequenceNum> ACCESS=<Data->GprsCiphKeySequenceNum>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GprsCiphKeySequenceNum);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "GprsCiphKeySequenceNum");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "AuthParamAutn");
	if (!Data->AuthParamAutn_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AuthParamAutn> ACCESS=<Data->AuthParamAutn>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AuthParamAutn, 128);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "AuthParamAutn");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "MsNetwkCpblty");
	if (!Data->MsNetwkCpblty_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MsNetwkCpblty> NAME=<MsNetwkCpblty> ACCESS=<*(Data->MsNetwkCpblty)>  OPTIONAL=<1> FUNC=<Dump_c_MsNetwkCpblty> */
	  Dump_c_MsNetwkCpblty (OStream, &(*(Data->MsNetwkCpblty)));
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "MsNetwkCpblty");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "IntegrityProtectionAlgorithm");
	if (!Data->IntegrityProtectionAlgorithm_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_IntegrityProtectionAlgorithm> NAME=<IntegrityProtectionAlgorithm> ACCESS=<*(Data->IntegrityProtectionAlgorithm)>  OPTIONAL=<1> FUNC=<Dump_c_IntegrityProtectionAlgorithm> */
	  Dump_c_IntegrityProtectionAlgorithm (OStream, &(*(Data->IntegrityProtectionAlgorithm)));
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "IntegrityProtectionAlgorithm");
	ED_Dump_Struct_Begin_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "MessageAuthCode");
	if (!Data->MessageAuthCode_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<MessageAuthCode> ACCESS=<Data->MessageAuthCode>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->MessageAuthCode);
	}
	ED_Dump_Struct_End_Field (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN", "MessageAuthCode");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_AND_CIPHERING_REQUEST_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (TEDOStream* OStream, const c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "AUTHENTICATION_AND_CIPHERING_REJECT_DN");
	ED_Dump_Struct_End (OStream, "AUTHENTICATION_AND_CIPHERING_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_IDENTITY_REQUEST_B_DN (TEDOStream* OStream, const c_IDENTITY_REQUEST_B_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "IDENTITY_REQUEST_B_DN");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST_B_DN", "IdType");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<IdType> ACCESS=<Data->IdType>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->IdType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "IMSI"); break;
				case 2: OStream->WriteString (OStream, "IMEI"); break;
				case 3: OStream->WriteString (OStream, "IMEISV"); break;
				case 4: OStream->WriteString (OStream, "TMSI"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST_B_DN", "IdType");
	ED_Dump_Struct_Begin_Field (OStream, "IDENTITY_REQUEST_B_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "IDENTITY_REQUEST_B_DN", "ForceToStandby");
	ED_Dump_Struct_End (OStream, "IDENTITY_REQUEST_B_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ROUTING_AREA_UPDATE_ACCEPT_DN (TEDOStream* OStream, const c_ROUTING_AREA_UPDATE_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "UpdateResult");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<UpdateResult> ACCESS=<Data->UpdateResult>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->UpdateResult);
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "UpdateResult");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "PeriodicRaUpdateTimer");
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer> NAME=<PeriodicRaUpdateTimer> ACCESS=<Data->PeriodicRaUpdateTimer>  OPTIONAL=<0> FUNC=<Dump_c_GprsTimer> */
	  Dump_c_GprsTimer (OStream, &(Data->PeriodicRaUpdateTimer));
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "PeriodicRaUpdateTimer");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "RoutingAreaId");
	  /* STRUCTURAL=<0> TYPE=<c_RoutingAreaIdenti> NAME=<RoutingAreaId> ACCESS=<Data->RoutingAreaId>  OPTIONAL=<0> FUNC=<Dump_c_RoutingAreaIdenti> */
	  Dump_c_RoutingAreaIdenti (OStream, &(Data->RoutingAreaId));
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "RoutingAreaId");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "PTmsiSign");
	if (!Data->PTmsiSign_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<PTmsiSign> ACCESS=<Data->PTmsiSign>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->PTmsiSign, 24);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "PTmsiSign");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "AllocatedPTmsi");
	if (!Data->AllocatedPTmsi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<AllocatedPTmsi> ACCESS=<*(Data->AllocatedPTmsi)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->AllocatedPTmsi)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "AllocatedPTmsi");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "MsId");
	if (!Data->MsId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_MobileId> NAME=<MsId> ACCESS=<*(Data->MsId)>  OPTIONAL=<1> FUNC=<Dump_c_MobileId> */
	  Dump_c_MobileId (OStream, &(*(Data->MsId)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "MsId");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "ListOfReceiveNPduNumbers");
	if (!Data->ListOfReceiveNPduNumbers_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ReceiveNPduNumbersList> NAME=<ListOfReceiveNPduNumbers> ACCESS=<*(Data->ListOfReceiveNPduNumbers)>  OPTIONAL=<1> FUNC=<Dump_c_ReceiveNPduNumbersList> */
	  Dump_c_ReceiveNPduNumbersList (OStream, &(*(Data->ListOfReceiveNPduNumbers)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "ListOfReceiveNPduNumbers");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "NegotiatedRdyTimerValue");
	if (!Data->NegotiatedRdyTimerValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer> NAME=<NegotiatedRdyTimerValue> ACCESS=<*(Data->NegotiatedRdyTimerValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer> */
	  Dump_c_GprsTimer (OStream, &(*(Data->NegotiatedRdyTimerValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "NegotiatedRdyTimerValue");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "GmmCause");
	if (!Data->GmmCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "GmmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3302Value");
	if (!Data->T3302Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3302Value> ACCESS=<*(Data->T3302Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3302Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3302Value");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "CellNotif");
	if (!Data->CellNotif_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ROUTING_AREA_UPDATE_ACCEPT_DN_CellNotif> NAME=<CellNotif> ACCESS=<Data->CellNotif>  OPTIONAL=<1> FUNC=<ED_Dump_Void_Present> */
	  ED_Dump_Void_Present (OStream);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "CellNotif");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "EquivPlmns");
	if (!Data->EquivPlmns_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PlmnList> NAME=<EquivPlmns> ACCESS=<*(Data->EquivPlmns)>  OPTIONAL=<1> FUNC=<Dump_c_PlmnList> */
	  Dump_c_PlmnList (OStream, &(*(Data->EquivPlmns)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "EquivPlmns");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "PdpContextStatus");
	if (!Data->PdpContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PdpContextStatus> NAME=<PdpContextStatus> ACCESS=<*(Data->PdpContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_PdpContextStatus> */
	  Dump_c_PdpContextStatus (OStream, &(*(Data->PdpContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "PdpContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "NetworkFeatureSupport");
	if (!Data->NetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetworkFeatureSupport> NAME=<NetworkFeatureSupport> ACCESS=<*(Data->NetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_NetworkFeatureSupport> */
	  Dump_c_NetworkFeatureSupport (OStream, &(*(Data->NetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "NetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "EmergencyNumberList");
	if (!Data->EmergencyNumberList_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_EmergencyNumberList> NAME=<EmergencyNumberList> ACCESS=<*(Data->EmergencyNumberList)>  OPTIONAL=<1> FUNC=<Dump_c_EmergencyNumberList> */
	  Dump_c_EmergencyNumberList (OStream, &(*(Data->EmergencyNumberList)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "EmergencyNumberList");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "MBMSContextStatus");
	if (!Data->MBMSContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSContextStatus> ACCESS=<*(Data->MBMSContextStatus)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSContextStatus->value, Data->MBMSContextStatus->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "MBMSContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "RequestedMSInformation");
	if (!Data->RequestedMSInformation_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_RequestedMSInformation> NAME=<RequestedMSInformation> ACCESS=<*(Data->RequestedMSInformation)>  OPTIONAL=<1> FUNC=<Dump_c_RequestedMSInformation> */
	  Dump_c_RequestedMSInformation (OStream, &(*(Data->RequestedMSInformation)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "RequestedMSInformation");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3319Value");
	if (!Data->T3319Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3319Value> ACCESS=<*(Data->T3319Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3319Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3319Value");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3323Value");
	if (!Data->T3323Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3323Value> ACCESS=<*(Data->T3323Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3323Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3323Value");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3312ExtendedValue");
	if (!Data->T3312ExtendedValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3312ExtendedValue> ACCESS=<*(Data->T3312ExtendedValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3312ExtendedValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3312ExtendedValue");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "AdditionalNetworkFeatureSupport");
	if (!Data->AdditionalNetworkFeatureSupport_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_AdditionalNetworkFeatureSupport> NAME=<AdditionalNetworkFeatureSupport> ACCESS=<*(Data->AdditionalNetworkFeatureSupport)>  OPTIONAL=<1> FUNC=<Dump_c_AdditionalNetworkFeatureSupport> */
	  Dump_c_AdditionalNetworkFeatureSupport (OStream, &(*(Data->AdditionalNetworkFeatureSupport)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "AdditionalNetworkFeatureSupport");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3324Value");
	if (!Data->T3324Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3324Value> ACCESS=<*(Data->T3324Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3324Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "T3324Value");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "ExtendedDRXParameters");
	if (!Data->ExtendedDRXParameters_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ExtendedDRXParameters> NAME=<ExtendedDRXParameters> ACCESS=<*(Data->ExtendedDRXParameters)>  OPTIONAL=<1> FUNC=<Dump_c_ExtendedDRXParameters> */
	  Dump_c_ExtendedDRXParameters (OStream, &(*(Data->ExtendedDRXParameters)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN", "ExtendedDRXParameters");
	ED_Dump_Struct_End (OStream, "ROUTING_AREA_UPDATE_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ROUTING_AREA_UPDATE_REJECT_DN (TEDOStream* OStream, const c_ROUTING_AREA_UPDATE_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ROUTING_AREA_UPDATE_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "GmmCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "GmmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "ForceToStandby");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ForceToStandby> ACCESS=<Data->ForceToStandby>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ForceToStandby)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "Force to standby not indicated"); break;
				case 1: OStream->WriteString (OStream, "Force to standby indicated"); break;
				default: OStream->WriteString (OStream, "unknown");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "ForceToStandby");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "T3302Value");
	if (!Data->T3302Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3302Value> ACCESS=<*(Data->T3302Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3302Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "T3302Value");
	ED_Dump_Struct_Begin_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "T3346Value");
	if (!Data->T3346Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3346Value> ACCESS=<*(Data->T3346Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3346Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ROUTING_AREA_UPDATE_REJECT_DN", "T3346Value");
	ED_Dump_Struct_End (OStream, "ROUTING_AREA_UPDATE_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GMM_INFORMATION_DN (TEDOStream* OStream, const c_GMM_INFORMATION_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GMM_INFORMATION_DN");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_INFORMATION_DN", "FullNameForNetwk");
	if (!Data->FullNameForNetwk_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetwkName> NAME=<FullNameForNetwk> ACCESS=<*(Data->FullNameForNetwk)>  OPTIONAL=<1> FUNC=<Dump_c_NetwkName> */
	  Dump_c_NetwkName (OStream, &(*(Data->FullNameForNetwk)));
	}
	ED_Dump_Struct_End_Field (OStream, "GMM_INFORMATION_DN", "FullNameForNetwk");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_INFORMATION_DN", "ShortNameForNetwk");
	if (!Data->ShortNameForNetwk_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_NetwkName> NAME=<ShortNameForNetwk> ACCESS=<*(Data->ShortNameForNetwk)>  OPTIONAL=<1> FUNC=<Dump_c_NetwkName> */
	  Dump_c_NetwkName (OStream, &(*(Data->ShortNameForNetwk)));
	}
	ED_Dump_Struct_End_Field (OStream, "GMM_INFORMATION_DN", "ShortNameForNetwk");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_INFORMATION_DN", "LocalTimeZone");
	if (!Data->LocalTimeZone_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<LocalTimeZone> ACCESS=<Data->LocalTimeZone>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->LocalTimeZone);
	}
	ED_Dump_Struct_End_Field (OStream, "GMM_INFORMATION_DN", "LocalTimeZone");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_INFORMATION_DN", "UniversalTimeAndLocalTimeZone");
	if (!Data->UniversalTimeAndLocalTimeZone_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TimeZoneAndTime> NAME=<UniversalTimeAndLocalTimeZone> ACCESS=<*(Data->UniversalTimeAndLocalTimeZone)>  OPTIONAL=<1> FUNC=<Dump_c_TimeZoneAndTime> */
	  Dump_c_TimeZoneAndTime (OStream, &(*(Data->UniversalTimeAndLocalTimeZone)));
	}
	ED_Dump_Struct_End_Field (OStream, "GMM_INFORMATION_DN", "UniversalTimeAndLocalTimeZone");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_INFORMATION_DN", "LsaId");
	if (!Data->LsaId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<LsaId> ACCESS=<*(Data->LsaId)>  MAXBITSIZE=<24> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->LsaId->value, Data->LsaId->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "GMM_INFORMATION_DN", "LsaId");
	ED_Dump_Struct_Begin_Field (OStream, "GMM_INFORMATION_DN", "NetwkDaylightSavingTime");
	if (!Data->NetwkDaylightSavingTime_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DaylightSavingTime> NAME=<NetwkDaylightSavingTime> ACCESS=<*(Data->NetwkDaylightSavingTime)>  OPTIONAL=<1> FUNC=<Dump_c_DaylightSavingTime> */
	  Dump_c_DaylightSavingTime (OStream, &(*(Data->NetwkDaylightSavingTime)));
	}
	ED_Dump_Struct_End_Field (OStream, "GMM_INFORMATION_DN", "NetwkDaylightSavingTime");
	ED_Dump_Struct_End (OStream, "GMM_INFORMATION_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SERVICE_ACCEPT_DN (TEDOStream* OStream, const c_SERVICE_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SERVICE_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_ACCEPT_DN", "PdpContextStatus");
	if (!Data->PdpContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PdpContextStatus> NAME=<PdpContextStatus> ACCESS=<*(Data->PdpContextStatus)>  OPTIONAL=<1> FUNC=<Dump_c_PdpContextStatus> */
	  Dump_c_PdpContextStatus (OStream, &(*(Data->PdpContextStatus)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_ACCEPT_DN", "PdpContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_ACCEPT_DN", "MBMSContextStatus");
	if (!Data->MBMSContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSContextStatus> ACCESS=<*(Data->MBMSContextStatus)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSContextStatus->value, Data->MBMSContextStatus->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_ACCEPT_DN", "MBMSContextStatus");
	ED_Dump_Struct_End (OStream, "SERVICE_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SERVICE_REJECT_DN (TEDOStream* OStream, const c_SERVICE_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SERVICE_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REJECT_DN", "GmmCause");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<GmmCause> ACCESS=<Data->GmmCause>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->GmmCause);
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REJECT_DN", "GmmCause");
	ED_Dump_Struct_Begin_Field (OStream, "SERVICE_REJECT_DN", "T3346Value");
	if (!Data->T3346Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer2> NAME=<T3346Value> ACCESS=<*(Data->T3346Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer2> */
	  Dump_c_GprsTimer2 (OStream, &(*(Data->T3346Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "SERVICE_REJECT_DN", "T3346Value");
	ED_Dump_Struct_End (OStream, "SERVICE_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (TEDOStream* OStream, const c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqNsapi");
	  /* STRUCTURAL=<0> TYPE=<c_NetwkServAccessPointId> NAME=<ReqNsapi> ACCESS=<Data->ReqNsapi>  OPTIONAL=<0> FUNC=<Dump_c_NetwkServAccessPointId> */
	  Dump_c_NetwkServAccessPointId (OStream, &(Data->ReqNsapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqNsapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<ReqLlcSapi> ACCESS=<Data->ReqLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->ReqLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqQos");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<ReqQos> ACCESS=<Data->ReqQos>  OPTIONAL=<0> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(Data->ReqQos));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqQos");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqPdpAddr");
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr> NAME=<ReqPdpAddr> ACCESS=<Data->ReqPdpAddr>  OPTIONAL=<0> FUNC=<Dump_c_PacketDataProtocolAddr> */
	  Dump_c_PacketDataProtocolAddr (OStream, &(Data->ReqPdpAddr));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ReqPdpAddr");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "AccessPointName");
	if (!Data->AccessPointName_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ASCII> NAME=<AccessPointName> ACCESS=<*(Data->AccessPointName)>  OPTIONAL=<1> FUNC=<Dump_c_ASCII> */
	  Dump_c_ASCII (OStream, &(*(Data->AccessPointName)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ProtocolCfgOpt");
	if (!Data->ProtocolCfgOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolCfgOpt> ACCESS=<*(Data->ProtocolCfgOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolCfgOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "ProtocolCfgOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "RequestType");
	if (!Data->RequestType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RequestType> ACCESS=<Data->RequestType>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->RequestType)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "initial request"); break;
				case 2: OStream->WriteString (OStream, "Handover"); break;
				case 3: OStream->WriteString (OStream, "Unused. If received, the network shall interpret this as 'initial request'."); break;
				case 4: OStream->WriteString (OStream, "emergency"); break;
				default: OStream->WriteString (OStream, "initial attach");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "RequestType");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "ACTIVATE_PDP_CONTEXT_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (TEDOStream* OStream, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ReqNsapi");
	  /* STRUCTURAL=<0> TYPE=<c_NetwkServAccessPointId> NAME=<ReqNsapi> ACCESS=<Data->ReqNsapi>  OPTIONAL=<0> FUNC=<Dump_c_NetwkServAccessPointId> */
	  Dump_c_NetwkServAccessPointId (OStream, &(Data->ReqNsapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ReqNsapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ReqLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<ReqLlcSapi> ACCESS=<Data->ReqLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->ReqLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ReqLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ReqQos");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<ReqQos> ACCESS=<Data->ReqQos>  OPTIONAL=<0> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(Data->ReqQos));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ReqQos");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "LinkedTi");
	  /* STRUCTURAL=<0> TYPE=<c_LinkedTi> NAME=<LinkedTi> ACCESS=<Data->LinkedTi>  OPTIONAL=<0> FUNC=<Dump_c_LinkedTi> */
	  Dump_c_LinkedTi (OStream, &(Data->LinkedTi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "LinkedTi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "Tft");
	if (!Data->Tft_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TrafficFlowTemplate> NAME=<Tft> ACCESS=<*(Data->Tft)>  OPTIONAL=<1> FUNC=<Dump_c_TrafficFlowTemplate> */
	  Dump_c_TrafficFlowTemplate (OStream, &(*(Data->Tft)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "Tft");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (TEDOStream* OStream, const c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_PDP_CONTEXT_REQUEST_UP (TEDOStream* OStream, const c_MODIFY_PDP_CONTEXT_REQUEST_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "ReqLlcSapi");
	if (!Data->ReqLlcSapi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<ReqLlcSapi> ACCESS=<*(Data->ReqLlcSapi)>  OPTIONAL=<1> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(*(Data->ReqLlcSapi)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "ReqLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "ReqNewQos");
	if (!Data->ReqNewQos_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<ReqNewQos> ACCESS=<*(Data->ReqNewQos)>  OPTIONAL=<1> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(*(Data->ReqNewQos)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "ReqNewQos");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "NewTft");
	if (!Data->NewTft_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TrafficFlowTemplate> NAME=<NewTft> ACCESS=<*(Data->NewTft)>  OPTIONAL=<1> FUNC=<Dump_c_TrafficFlowTemplate> */
	  Dump_c_TrafficFlowTemplate (OStream, &(*(Data->NewTft)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "NewTft");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "DeviceProperties");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "MODIFY_PDP_CONTEXT_REQUEST_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (TEDOStream* OStream, const c_MODIFY_PDP_CONTEXT_ACCEPT_UP* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_UP");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DEACTIVATE_PDP_CONTEXT_REQUEST (TEDOStream* OStream, const c_DEACTIVATE_PDP_CONTEXT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "TearDownInd");
	if (!Data->TearDownInd_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TearDownInd> NAME=<TearDownInd> ACCESS=<*(Data->TearDownInd)>  OPTIONAL=<1> FUNC=<Dump_c_TearDownInd> */
	  Dump_c_TearDownInd (OStream, &(*(Data->TearDownInd)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "TearDownInd");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "MBMSContextStatus");
	if (!Data->MBMSContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSContextStatus> ACCESS=<*(Data->MBMSContextStatus)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSContextStatus->value, Data->MBMSContextStatus->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "MBMSContextStatus");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "T3396Value");
	if (!Data->T3396Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3396Value> ACCESS=<*(Data->T3396Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3396Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "T3396Value");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_WLANOffloadAcceptability> */
	  Dump_c_WLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST", "WLANOffloadIndication");
	ED_Dump_Struct_End (OStream, "DEACTIVATE_PDP_CONTEXT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (TEDOStream* OStream, const c_DEACTIVATE_PDP_CONTEXT_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "MBMSContextStatus");
	if (!Data->MBMSContextStatus_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSContextStatus> ACCESS=<*(Data->MBMSContextStatus)>  MAXBITSIZE=<128> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSContextStatus->value, Data->MBMSContextStatus->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT", "MBMSContextStatus");
	ED_Dump_Struct_End (OStream, "DEACTIVATE_PDP_CONTEXT_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (TEDOStream* OStream, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "ProtocolCfgOpt");
	if (!Data->ProtocolCfgOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolCfgOpt> ACCESS=<*(Data->ProtocolCfgOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolCfgOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "ProtocolCfgOpt");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_SM_STATUS (TEDOStream* OStream, const c_SM_STATUS* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "SM_STATUS");
	ED_Dump_Struct_Begin_Field (OStream, "SM_STATUS", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "SM_STATUS", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "SM_STATUS", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "SM_STATUS", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "SM_STATUS", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "SM_STATUS", "SmCause");
	ED_Dump_Struct_End (OStream, "SM_STATUS");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_MBMS_CONTEXT_REQUEST (TEDOStream* OStream, const c_ACTIVATE_MBMS_CONTEXT_REQUEST* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "ReqMbmsNsapi");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ReqMbmsNsapi> ACCESS=<Data->ReqMbmsNsapi>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->ReqMbmsNsapi);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "ReqMbmsNsapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "ReqLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<ReqLlcSapi> ACCESS=<Data->ReqLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->ReqLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "ReqLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "SupportedMBMSBearerCapabilities");
	  /* STRUCTURAL=<0> TYPE=<c_MBMSBearerCapabilities> NAME=<SupportedMBMSBearerCapabilities> ACCESS=<Data->SupportedMBMSBearerCapabilities>  OPTIONAL=<0> FUNC=<Dump_c_MBMSBearerCapabilities> */
	  Dump_c_MBMSBearerCapabilities (OStream, &(Data->SupportedMBMSBearerCapabilities));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "SupportedMBMSBearerCapabilities");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "RequestedMulticastAddress");
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr> NAME=<RequestedMulticastAddress> ACCESS=<Data->RequestedMulticastAddress>  OPTIONAL=<0> FUNC=<Dump_c_PacketDataProtocolAddr> */
	  Dump_c_PacketDataProtocolAddr (OStream, &(Data->RequestedMulticastAddress));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "RequestedMulticastAddress");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "AccessPointName");
	  /* NAME=<AccessPointName> ACCESS=<Data->AccessPointName>  MAXBITSIZE=<800> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AccessPointName.value, Data->AccessPointName.usedBits);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "MBMSProtocolConfigOpts");
	if (!Data->MBMSProtocolConfigOpts_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSProtocolConfigOpts> ACCESS=<*(Data->MBMSProtocolConfigOpts)>  MAXBITSIZE=<2008> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSProtocolConfigOpts->value, Data->MBMSProtocolConfigOpts->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "MBMSProtocolConfigOpts");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "DeviceProperties");
	if (!Data->DeviceProperties_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_DeviceProperties> NAME=<DeviceProperties> ACCESS=<*(Data->DeviceProperties)>  OPTIONAL=<1> FUNC=<Dump_c_DeviceProperties> */
	  Dump_c_DeviceProperties (OStream, &(*(Data->DeviceProperties)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST", "DeviceProperties");
	ED_Dump_Struct_End (OStream, "ACTIVATE_MBMS_CONTEXT_REQUEST");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (TEDOStream* OStream, const c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "MBMSProtocolConfigOpts");
	if (!Data->MBMSProtocolConfigOpts_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSProtocolConfigOpts> ACCESS=<*(Data->MBMSProtocolConfigOpts)>  MAXBITSIZE=<2008> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSProtocolConfigOpts->value, Data->MBMSProtocolConfigOpts->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT", "MBMSProtocolConfigOpts");
	ED_Dump_Struct_End (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (TEDOStream* OStream, const c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "NegotiatedLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<NegotiatedLlcSapi> ACCESS=<Data->NegotiatedLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->NegotiatedLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "NegotiatedLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "NegotiatedQos");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<NegotiatedQos> ACCESS=<Data->NegotiatedQos>  OPTIONAL=<0> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(Data->NegotiatedQos));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "NegotiatedQos");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "RadioPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriority> ACCESS=<Data->RadioPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriority);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "RadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "PdpAddr");
	if (!Data->PdpAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr> NAME=<PdpAddr> ACCESS=<*(Data->PdpAddr)>  OPTIONAL=<1> FUNC=<Dump_c_PacketDataProtocolAddr> */
	  Dump_c_PacketDataProtocolAddr (OStream, &(*(Data->PdpAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "PdpAddr");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "ProtocolCfgOpt");
	if (!Data->ProtocolCfgOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolCfgOpt> ACCESS=<*(Data->ProtocolCfgOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolCfgOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "ProtocolCfgOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "PacketFlowId");
	if (!Data->PacketFlowId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PacketFlowIdentifie> NAME=<PacketFlowId> ACCESS=<*(Data->PacketFlowId)>  OPTIONAL=<1> FUNC=<Dump_c_PacketFlowIdentifie> */
	  Dump_c_PacketFlowIdentifie (OStream, &(*(Data->PacketFlowId)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "PacketFlowId");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "SMCause");
	if (!Data->SMCause_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SMCause> ACCESS=<*(Data->SMCause)>  OPTIONAL=<1> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(*(Data->SMCause)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "SMCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "ConnectivityType");
	if (!Data->ConnectivityType_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<ConnectivityType> ACCESS=<Data->ConnectivityType>  OPTIONAL=<1> FUNC=<ED_Dump_Octet> */
#define DATA (Data->ConnectivityType)
		{
			switch (DATA) {
				case 0: OStream->WriteString (OStream, "The PDN connection type is not indicated"); break;
				case 1: OStream->WriteString (OStream, "The PDN connection is considered a LIPA PDN connection"); break;
				default: OStream->WriteString (OStream, "The PDN connection type is not indicated");
			}
		}
#undef DATA
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "ConnectivityType");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_WLANOffloadAcceptability> */
	  Dump_c_WLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "ACTIVATE_PDP_CONTEXT_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (TEDOStream* OStream, const c_ACTIVATE_PDP_CONTEXT_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "ProtocolCfgOpt");
	if (!Data->ProtocolCfgOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolCfgOpt> ACCESS=<*(Data->ProtocolCfgOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolCfgOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "ProtocolCfgOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "T3396Value");
	if (!Data->T3396Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3396Value> ACCESS=<*(Data->T3396Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3396Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "T3396Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_ReAttemptIndicator> */
	  Dump_c_ReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "ACTIVATE_PDP_CONTEXT_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (TEDOStream* OStream, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<NegotiatedLlcSapi> ACCESS=<Data->NegotiatedLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->NegotiatedLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedQos");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<NegotiatedQos> ACCESS=<Data->NegotiatedQos>  OPTIONAL=<0> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(Data->NegotiatedQos));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedQos");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "RadioPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriority> ACCESS=<Data->RadioPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriority);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "RadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "PacketFlowId");
	if (!Data->PacketFlowId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PacketFlowIdentifie> NAME=<PacketFlowId> ACCESS=<*(Data->PacketFlowId)>  OPTIONAL=<1> FUNC=<Dump_c_PacketFlowIdentifie> */
	  Dump_c_PacketFlowIdentifie (OStream, &(*(Data->PacketFlowId)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "PacketFlowId");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_WLANOffloadAcceptability> */
	  Dump_c_WLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (TEDOStream* OStream, const c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "T3396Value");
	if (!Data->T3396Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3396Value> ACCESS=<*(Data->T3396Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3396Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "T3396Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_ReAttemptIndicator> */
	  Dump_c_ReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (TEDOStream* OStream, const c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "OfferedPdpAddr");
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr> NAME=<OfferedPdpAddr> ACCESS=<Data->OfferedPdpAddr>  OPTIONAL=<0> FUNC=<Dump_c_PacketDataProtocolAddr> */
	  Dump_c_PacketDataProtocolAddr (OStream, &(Data->OfferedPdpAddr));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "OfferedPdpAddr");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "AccessPointName");
	if (!Data->AccessPointName_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<AccessPointName> ACCESS=<*(Data->AccessPointName)>  MAXBITSIZE=<800> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->AccessPointName->value, Data->AccessPointName->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "REQUEST_PDP_CONTEXT_ACTIVATION_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_PDP_CONTEXT_REQUEST_DN (TEDOStream* OStream, const c_MODIFY_PDP_CONTEXT_REQUEST_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "RadioPriority");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<RadioPriority> ACCESS=<Data->RadioPriority>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->RadioPriority);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "RadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "SpareHalfOctet");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<SpareHalfOctet> ACCESS=<Data->SpareHalfOctet>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->SpareHalfOctet);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "SpareHalfOctet");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "ReqLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<ReqLlcSapi> ACCESS=<Data->ReqLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->ReqLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "ReqLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "NewQos");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<NewQos> ACCESS=<Data->NewQos>  OPTIONAL=<0> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(Data->NewQos));
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "NewQos");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "PdpAddr");
	if (!Data->PdpAddr_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr> NAME=<PdpAddr> ACCESS=<*(Data->PdpAddr)>  OPTIONAL=<1> FUNC=<Dump_c_PacketDataProtocolAddr> */
	  Dump_c_PacketDataProtocolAddr (OStream, &(*(Data->PdpAddr)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "PdpAddr");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "PacketFlowId");
	if (!Data->PacketFlowId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PacketFlowIdentifie> NAME=<PacketFlowId> ACCESS=<*(Data->PacketFlowId)>  OPTIONAL=<1> FUNC=<Dump_c_PacketFlowIdentifie> */
	  Dump_c_PacketFlowIdentifie (OStream, &(*(Data->PacketFlowId)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "PacketFlowId");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "Tft");
	if (!Data->Tft_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TrafficFlowTemplate> NAME=<Tft> ACCESS=<*(Data->Tft)>  OPTIONAL=<1> FUNC=<Dump_c_TrafficFlowTemplate> */
	  Dump_c_TrafficFlowTemplate (OStream, &(*(Data->Tft)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "Tft");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_WLANOffloadAcceptability> */
	  Dump_c_WLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "MODIFY_PDP_CONTEXT_REQUEST_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (TEDOStream* OStream, const c_MODIFY_PDP_CONTEXT_ACCEPT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedQos");
	if (!Data->NegotiatedQos_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<NegotiatedQos> ACCESS=<*(Data->NegotiatedQos)>  OPTIONAL=<1> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(*(Data->NegotiatedQos)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedQos");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedLlcSapi");
	if (!Data->NegotiatedLlcSapi_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<NegotiatedLlcSapi> ACCESS=<*(Data->NegotiatedLlcSapi)>  OPTIONAL=<1> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(*(Data->NegotiatedLlcSapi)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NegotiatedLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NewRadioPriority");
	if (!Data->NewRadioPriority_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NewRadioPriority> ACCESS=<Data->NewRadioPriority>  OPTIONAL=<1> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->NewRadioPriority);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NewRadioPriority");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "PacketFlowId");
	if (!Data->PacketFlowId_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_PacketFlowIdentifie> NAME=<PacketFlowId> ACCESS=<*(Data->PacketFlowId)>  OPTIONAL=<1> FUNC=<Dump_c_PacketFlowIdentifie> */
	  Dump_c_PacketFlowIdentifie (OStream, &(*(Data->PacketFlowId)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "PacketFlowId");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_WLANOffloadAcceptability> */
	  Dump_c_WLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "MODIFY_PDP_CONTEXT_ACCEPT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_MODIFY_PDP_CONTEXT_REJECT_DN (TEDOStream* OStream, const c_MODIFY_PDP_CONTEXT_REJECT_DN* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "T3396Value");
	if (!Data->T3396Value_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<T3396Value> ACCESS=<*(Data->T3396Value)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->T3396Value)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "T3396Value");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_ReAttemptIndicator> */
	  Dump_c_ReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "ReAttemptIndicator");
	ED_Dump_Struct_Begin_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "MODIFY_PDP_CONTEXT_REJECT_DN");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (TEDOStream* OStream, const c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "ReqQos");
	  /* STRUCTURAL=<0> TYPE=<c_QualityOfServ> NAME=<ReqQos> ACCESS=<Data->ReqQos>  OPTIONAL=<0> FUNC=<Dump_c_QualityOfServ> */
	  Dump_c_QualityOfServ (OStream, &(Data->ReqQos));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "ReqQos");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "LinkedTi");
	  /* STRUCTURAL=<0> TYPE=<c_LinkedTi> NAME=<LinkedTi> ACCESS=<Data->LinkedTi>  OPTIONAL=<0> FUNC=<Dump_c_LinkedTi> */
	  Dump_c_LinkedTi (OStream, &(Data->LinkedTi));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "LinkedTi");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "Tft");
	if (!Data->Tft_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_TrafficFlowTemplate> NAME=<Tft> ACCESS=<*(Data->Tft)>  OPTIONAL=<1> FUNC=<Dump_c_TrafficFlowTemplate> */
	  Dump_c_TrafficFlowTemplate (OStream, &(*(Data->Tft)));
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "Tft");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "ProtocolConfigOpt");
	if (!Data->ProtocolConfigOpt_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ProtocolCfgOpt> NAME=<ProtocolConfigOpt> ACCESS=<*(Data->ProtocolConfigOpt)>  OPTIONAL=<1> FUNC=<Dump_c_ProtocolCfgOpt> */
	  Dump_c_ProtocolCfgOpt (OStream, &(*(Data->ProtocolConfigOpt)));
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "ProtocolConfigOpt");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "WLANOffloadIndication");
	if (!Data->WLANOffloadIndication_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_WLANOffloadAcceptability> NAME=<WLANOffloadIndication> ACCESS=<*(Data->WLANOffloadIndication)>  OPTIONAL=<1> FUNC=<Dump_c_WLANOffloadAcceptability> */
	  Dump_c_WLANOffloadAcceptability (OStream, &(*(Data->WLANOffloadIndication)));
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "WLANOffloadIndication");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "NBIFOMContainer");
	if (!Data->NBIFOMContainer_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<NBIFOMContainer> ACCESS=<*(Data->NBIFOMContainer)>  MAXBITSIZE=<2040> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->NBIFOMContainer->value, Data->NBIFOMContainer->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION", "NBIFOMContainer");
	ED_Dump_Struct_End (OStream, "REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_NOTIFICATION (TEDOStream* OStream, const c_NOTIFICATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "NOTIFICATION");
	ED_Dump_Struct_Begin_Field (OStream, "NOTIFICATION", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "NOTIFICATION", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "NOTIFICATION", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "NOTIFICATION", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "NOTIFICATION", "NotificationIndicator");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<NotificationIndicator> ACCESS=<Data->NotificationIndicator>  OPTIONAL=<0> FUNC=<ED_Dump_Octet> */
#define DATA (Data->NotificationIndicator)
		{
			switch (DATA) {
				case 1: OStream->WriteString (OStream, "SRVCC handover cancelled, IMS session re-establishment required"); break;
				default: OStream->WriteString (OStream, "Reserved");
			}
		}
#undef DATA
	ED_Dump_Struct_End_Field (OStream, "NOTIFICATION", "NotificationIndicator");
	ED_Dump_Struct_End (OStream, "NOTIFICATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (TEDOStream* OStream, const c_ACTIVATE_MBMS_CONTEXT_ACCEPT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "TempMobileGroupId");
	  /* STRUCTURAL=<0> TYPE=<c_TempMobileGroupId> NAME=<TempMobileGroupId> ACCESS=<Data->TempMobileGroupId>  OPTIONAL=<0> FUNC=<Dump_c_TempMobileGroupId> */
	  Dump_c_TempMobileGroupId (OStream, &(Data->TempMobileGroupId));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "TempMobileGroupId");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "NegotiatedLlcSapi");
	  /* STRUCTURAL=<0> TYPE=<c_LlcServAccessPointId> NAME=<NegotiatedLlcSapi> ACCESS=<Data->NegotiatedLlcSapi>  OPTIONAL=<0> FUNC=<Dump_c_LlcServAccessPointId> */
	  Dump_c_LlcServAccessPointId (OStream, &(Data->NegotiatedLlcSapi));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "NegotiatedLlcSapi");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "MBMSProtocolConfigOpts");
	if (!Data->MBMSProtocolConfigOpts_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSProtocolConfigOpts> ACCESS=<*(Data->MBMSProtocolConfigOpts)>  MAXBITSIZE=<2008> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSProtocolConfigOpts->value, Data->MBMSProtocolConfigOpts->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT", "MBMSProtocolConfigOpts");
	ED_Dump_Struct_End (OStream, "ACTIVATE_MBMS_CONTEXT_ACCEPT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_ACTIVATE_MBMS_CONTEXT_REJECT (TEDOStream* OStream, const c_ACTIVATE_MBMS_CONTEXT_REJECT* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "SmCause");
	  /* STRUCTURAL=<0> TYPE=<c_SMCause> NAME=<SmCause> ACCESS=<Data->SmCause>  OPTIONAL=<0> FUNC=<Dump_c_SMCause> */
	  Dump_c_SMCause (OStream, &(Data->SmCause));
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "SmCause");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "MBMSProtocolConfigOpts");
	if (!Data->MBMSProtocolConfigOpts_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSProtocolConfigOpts> ACCESS=<*(Data->MBMSProtocolConfigOpts)>  MAXBITSIZE=<2008> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSProtocolConfigOpts->value, Data->MBMSProtocolConfigOpts->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "MBMSProtocolConfigOpts");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "BackOffTimerValue");
	if (!Data->BackOffTimerValue_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_GprsTimer3> NAME=<BackOffTimerValue> ACCESS=<*(Data->BackOffTimerValue)>  OPTIONAL=<1> FUNC=<Dump_c_GprsTimer3> */
	  Dump_c_GprsTimer3 (OStream, &(*(Data->BackOffTimerValue)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "BackOffTimerValue");
	ED_Dump_Struct_Begin_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "ReAttemptIndicator");
	if (!Data->ReAttemptIndicator_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* STRUCTURAL=<0> TYPE=<c_ReAttemptIndicator> NAME=<ReAttemptIndicator> ACCESS=<*(Data->ReAttemptIndicator)>  OPTIONAL=<1> FUNC=<Dump_c_ReAttemptIndicator> */
	  Dump_c_ReAttemptIndicator (OStream, &(*(Data->ReAttemptIndicator)));
	}
	ED_Dump_Struct_End_Field (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT", "ReAttemptIndicator");
	ED_Dump_Struct_End (OStream, "ACTIVATE_MBMS_CONTEXT_REJECT");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_REQUEST_MBMS_CONTEXT_ACTIVATION (TEDOStream* OStream, const c_REQUEST_MBMS_CONTEXT_ACTIVATION* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "TI_Value");
	  /* STRUCTURAL=<0> TYPE=<ED_OCTET> NAME=<TI_Value> ACCESS=<Data->TI_Value>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TI_Value);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "TI_Value");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "TI_Flag");
	  /* STRUCTURAL=<0> TYPE=<ED_BOOLEAN> NAME=<TI_Flag> ACCESS=<Data->TI_Flag>  OPTIONAL=<0> FUNC=<ED_Dump_Boolean> */
	  ED_Dump_Boolean (OStream, Data->TI_Flag);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "TI_Flag");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "LinkedNSAPI");
	  /* STRUCTURAL=<0> TYPE=<c_NetwkServAccessPointId> NAME=<LinkedNSAPI> ACCESS=<Data->LinkedNSAPI>  OPTIONAL=<0> FUNC=<Dump_c_NetwkServAccessPointId> */
	  Dump_c_NetwkServAccessPointId (OStream, &(Data->LinkedNSAPI));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "LinkedNSAPI");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "OfferedMulticastAddr");
	  /* STRUCTURAL=<0> TYPE=<c_PacketDataProtocolAddr> NAME=<OfferedMulticastAddr> ACCESS=<Data->OfferedMulticastAddr>  OPTIONAL=<0> FUNC=<Dump_c_PacketDataProtocolAddr> */
	  Dump_c_PacketDataProtocolAddr (OStream, &(Data->OfferedMulticastAddr));
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "OfferedMulticastAddr");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "AccessPointName");
	  /* NAME=<AccessPointName> ACCESS=<Data->AccessPointName>  MAXBITSIZE=<800> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->AccessPointName.value, Data->AccessPointName.usedBits);
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "AccessPointName");
	ED_Dump_Struct_Begin_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "MBMSProtocolConfigOpts");
	if (!Data->MBMSProtocolConfigOpts_Present) ED_Dump_Not_Present (OStream);
	else {
	  /* NAME=<MBMSProtocolConfigOpts> ACCESS=<*(Data->MBMSProtocolConfigOpts)>  MAXBITSIZE=<2008> OPTIONAL=<1> */
	  ED_Dump_Binary (OStream, Data->MBMSProtocolConfigOpts->value, Data->MBMSProtocolConfigOpts->usedBits);
	}
	ED_Dump_Struct_End_Field (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION", "MBMSProtocolConfigOpts");
	ED_Dump_Struct_End (OStream, "REQUEST_MBMS_CONTEXT_ACTIVATION");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
void Dump_c_GenericTLV_L3 (TEDOStream* OStream, const c_GenericTLV_L3* Data)
{
  /* STRUCT */
	ED_Dump_Struct_Begin (OStream, "GenericTLV_L3");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_L3", "TLV_Tag");
	  /* STRUCTURAL=<0> TYPE=<ED_LONG> NAME=<TLV_Tag> ACCESS=<Data->TLV_Tag>  OPTIONAL=<0> FUNC=<ED_Dump_Integer> */
	  ED_Dump_Integer (OStream, Data->TLV_Tag);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_L3", "TLV_Tag");
	ED_Dump_Struct_Begin_Field (OStream, "GenericTLV_L3", "TLV_Data");
	  /* NAME=<TLV_Data> ACCESS=<Data->TLV_Data>  MAXBITSIZE=<8192> OPTIONAL=<0> */
	  ED_Dump_Binary (OStream, Data->TLV_Data.value, Data->TLV_Data.usedBits);
	ED_Dump_Struct_End_Field (OStream, "GenericTLV_L3", "TLV_Data");
	ED_Dump_Struct_End (OStream, "GenericTLV_L3");
	ED_WARNING_REMOVER (OStream);
	ED_WARNING_REMOVER (Data);
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_L3Uplink (TEDOStream* OStream, const TL3Uplink_Data* Data)
{
	switch (Data->Type) {
		case ID_L3Uplink_AUTHENTICATION_RESPONSE_UP: Dump_c_AUTHENTICATION_RESPONSE_UP (OStream, Data->Data.fld_c_AUTHENTICATION_RESPONSE_UP); break;
		case ID_L3Uplink_AUTHENTICATION_FAILURE_UP: Dump_c_AUTHENTICATION_FAILURE_UP (OStream, Data->Data.fld_c_AUTHENTICATION_FAILURE_UP); break;
		case ID_L3Uplink_CM_RE_ESTABLISHMENT_REQUEST_UP: Dump_c_CM_RE_ESTABLISHMENT_REQUEST_UP (OStream, Data->Data.fld_c_CM_RE_ESTABLISHMENT_REQUEST_UP); break;
		case ID_L3Uplink_CM_SERVICE_ABORT_UP: Dump_c_CM_SERVICE_ABORT_UP (OStream, Data->Data.fld_c_CM_SERVICE_ABORT_UP); break;
		case ID_L3Uplink_CM_SERVICE_REQUEST_UP: Dump_c_CM_SERVICE_REQUEST_UP (OStream, Data->Data.fld_c_CM_SERVICE_REQUEST_UP); break;
		case ID_L3Uplink_IDENTITY_RESPONSE_UP: Dump_c_IDENTITY_RESPONSE_UP (OStream, Data->Data.fld_c_IDENTITY_RESPONSE_UP); break;
		case ID_L3Uplink_IMSI_DETACH_INDICATION_UP: Dump_c_IMSI_DETACH_INDICATION_UP (OStream, Data->Data.fld_c_IMSI_DETACH_INDICATION_UP); break;
		case ID_L3Uplink_LOCATION_UPDATING_REQUEST_UP: Dump_c_LOCATION_UPDATING_REQUEST_UP (OStream, Data->Data.fld_c_LOCATION_UPDATING_REQUEST_UP); break;
		case ID_L3Uplink_MM_STATUS: Dump_c_MM_STATUS (OStream, Data->Data.fld_c_MM_STATUS); break;
		case ID_L3Uplink_TMSI_REALLOCATION_COMPLETE_UP: Dump_c_TMSI_REALLOCATION_COMPLETE_UP (OStream, Data->Data.fld_c_TMSI_REALLOCATION_COMPLETE_UP); break;
		case ID_L3Uplink_MM_NULL_UP: Dump_c_MM_NULL_UP (OStream, Data->Data.fld_c_MM_NULL_UP); break;
		case ID_L3Uplink_ALERTING_UP: Dump_c_ALERTING_UP (OStream, Data->Data.fld_c_ALERTING_UP); break;
		case ID_L3Uplink_CALL_CONFIRMED_UP: Dump_c_CALL_CONFIRMED_UP (OStream, Data->Data.fld_c_CALL_CONFIRMED_UP); break;
		case ID_L3Uplink_CONNECT_UP: Dump_c_CONNECT_UP (OStream, Data->Data.fld_c_CONNECT_UP); break;
		case ID_L3Uplink_CONNECT_ACKNOWLEDGE: Dump_c_CONNECT_ACKNOWLEDGE (OStream, Data->Data.fld_c_CONNECT_ACKNOWLEDGE); break;
		case ID_L3Uplink_DISCONNECT_UP: Dump_c_DISCONNECT_UP (OStream, Data->Data.fld_c_DISCONNECT_UP); break;
		case ID_L3Uplink_EMERGENCY_SETUP_UP: Dump_c_EMERGENCY_SETUP_UP (OStream, Data->Data.fld_c_EMERGENCY_SETUP_UP); break;
		case ID_L3Uplink_FACILITY_UP: Dump_c_FACILITY_UP (OStream, Data->Data.fld_c_FACILITY_UP); break;
		case ID_L3Uplink_HOLD_UP: Dump_c_HOLD_UP (OStream, Data->Data.fld_c_HOLD_UP); break;
		case ID_L3Uplink_MODIFY: Dump_c_MODIFY (OStream, Data->Data.fld_c_MODIFY); break;
		case ID_L3Uplink_MODIFY_COMPLETE: Dump_c_MODIFY_COMPLETE (OStream, Data->Data.fld_c_MODIFY_COMPLETE); break;
		case ID_L3Uplink_MODIFY_REJECT: Dump_c_MODIFY_REJECT (OStream, Data->Data.fld_c_MODIFY_REJECT); break;
		case ID_L3Uplink_NOTIFY: Dump_c_NOTIFY (OStream, Data->Data.fld_c_NOTIFY); break;
		case ID_L3Uplink_CC_ESTABLISHMENT_CONFIRMED_UP: Dump_c_CC_ESTABLISHMENT_CONFIRMED_UP (OStream, Data->Data.fld_c_CC_ESTABLISHMENT_CONFIRMED_UP); break;
		case ID_L3Uplink_RELEASE_UP: Dump_c_RELEASE_UP (OStream, Data->Data.fld_c_RELEASE_UP); break;
		case ID_L3Uplink_RELEASE_COMPLETE_UP: Dump_c_RELEASE_COMPLETE_UP (OStream, Data->Data.fld_c_RELEASE_COMPLETE_UP); break;
		case ID_L3Uplink_RETRIEVE_UP: Dump_c_RETRIEVE_UP (OStream, Data->Data.fld_c_RETRIEVE_UP); break;
		case ID_L3Uplink_SETUP_UP: Dump_c_SETUP_UP (OStream, Data->Data.fld_c_SETUP_UP); break;
		case ID_L3Uplink_START_CC_UP: Dump_c_START_CC_UP (OStream, Data->Data.fld_c_START_CC_UP); break;
		case ID_L3Uplink_START_DTMF_UP: Dump_c_START_DTMF_UP (OStream, Data->Data.fld_c_START_DTMF_UP); break;
		case ID_L3Uplink_STATUS: Dump_c_STATUS (OStream, Data->Data.fld_c_STATUS); break;
		case ID_L3Uplink_STATUS_ENQUIRY: Dump_c_STATUS_ENQUIRY (OStream, Data->Data.fld_c_STATUS_ENQUIRY); break;
		case ID_L3Uplink_STOP_DTMF_UP: Dump_c_STOP_DTMF_UP (OStream, Data->Data.fld_c_STOP_DTMF_UP); break;
		case ID_L3Uplink_USER_INFORMATION: Dump_c_USER_INFORMATION (OStream, Data->Data.fld_c_USER_INFORMATION); break;
		case ID_L3Uplink_ATTACH_REQUEST_UP: Dump_c_ATTACH_REQUEST_UP (OStream, Data->Data.fld_c_ATTACH_REQUEST_UP); break;
		case ID_L3Uplink_ATTACH_COMPLETE_UP: Dump_c_ATTACH_COMPLETE_UP (OStream, Data->Data.fld_c_ATTACH_COMPLETE_UP); break;
		case ID_L3Uplink_DETACH_REQUEST_UP: Dump_c_DETACH_REQUEST_UP (OStream, Data->Data.fld_c_DETACH_REQUEST_UP); break;
		case ID_L3Uplink_DETACH_ACCEPT_UP: Dump_c_DETACH_ACCEPT_UP (OStream, Data->Data.fld_c_DETACH_ACCEPT_UP); break;
		case ID_L3Uplink_P_TMSI_REALLOCATION_COMPLETE_UP: Dump_c_P_TMSI_REALLOCATION_COMPLETE_UP (OStream, Data->Data.fld_c_P_TMSI_REALLOCATION_COMPLETE_UP); break;
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP: Dump_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP (OStream, Data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP); break;
		case ID_L3Uplink_AUTHENTICATION_AND_CIPHERING_FAILURE_UP: Dump_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP (OStream, Data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP); break;
		case ID_L3Uplink_IDENTITY_RESPONSE_B_UP: Dump_c_IDENTITY_RESPONSE_B_UP (OStream, Data->Data.fld_c_IDENTITY_RESPONSE_B_UP); break;
		case ID_L3Uplink_ROUTING_AREA_UPDATE_REQUEST_UP: Dump_c_ROUTING_AREA_UPDATE_REQUEST_UP (OStream, Data->Data.fld_c_ROUTING_AREA_UPDATE_REQUEST_UP); break;
		case ID_L3Uplink_ROUTING_AREA_UPDATE_COMPLETE_UP: Dump_c_ROUTING_AREA_UPDATE_COMPLETE_UP (OStream, Data->Data.fld_c_ROUTING_AREA_UPDATE_COMPLETE_UP); break;
		case ID_L3Uplink_GMM_STATUS: Dump_c_GMM_STATUS (OStream, Data->Data.fld_c_GMM_STATUS); break;
		case ID_L3Uplink_SERVICE_REQUEST_UP: Dump_c_SERVICE_REQUEST_UP (OStream, Data->Data.fld_c_SERVICE_REQUEST_UP); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_DummyDownlink (TEDOStream* OStream, const TDummyDownlink_Data* Data)
{
	switch (Data->Type) {
		case ID_DummyDownlink_SETUP_UP: Dump_c_SETUP_UP (OStream, Data->Data.fld_c_SETUP_UP); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_L3Downlink (TEDOStream* OStream, const TL3Downlink_Data* Data)
{
	switch (Data->Type) {
		case ID_L3Downlink_AUTHENTICATION_REJECT_DN: Dump_c_AUTHENTICATION_REJECT_DN (OStream, Data->Data.fld_c_AUTHENTICATION_REJECT_DN); break;
		case ID_L3Downlink_AUTHENTICATION_REQUEST_DN: Dump_c_AUTHENTICATION_REQUEST_DN (OStream, Data->Data.fld_c_AUTHENTICATION_REQUEST_DN); break;
		case ID_L3Downlink_CM_SERVICE_ACCEPT_DN: Dump_c_CM_SERVICE_ACCEPT_DN (OStream, Data->Data.fld_c_CM_SERVICE_ACCEPT_DN); break;
		case ID_L3Downlink_CM_SERVICE_PROMPT_DN: Dump_c_CM_SERVICE_PROMPT_DN (OStream, Data->Data.fld_c_CM_SERVICE_PROMPT_DN); break;
		case ID_L3Downlink_CM_SERVICE_REJECT_DN: Dump_c_CM_SERVICE_REJECT_DN (OStream, Data->Data.fld_c_CM_SERVICE_REJECT_DN); break;
		case ID_L3Downlink_ABORT_DN: Dump_c_ABORT_DN (OStream, Data->Data.fld_c_ABORT_DN); break;
		case ID_L3Downlink_IDENTITY_REQUEST_DN: Dump_c_IDENTITY_REQUEST_DN (OStream, Data->Data.fld_c_IDENTITY_REQUEST_DN); break;
		case ID_L3Downlink_LOCATION_UPDATING_ACCEPT_DN: Dump_c_LOCATION_UPDATING_ACCEPT_DN (OStream, Data->Data.fld_c_LOCATION_UPDATING_ACCEPT_DN); break;
		case ID_L3Downlink_LOCATION_UPDATING_REJECT_DN: Dump_c_LOCATION_UPDATING_REJECT_DN (OStream, Data->Data.fld_c_LOCATION_UPDATING_REJECT_DN); break;
		case ID_L3Downlink_MM_INFORMATION_DN: Dump_c_MM_INFORMATION_DN (OStream, Data->Data.fld_c_MM_INFORMATION_DN); break;
		case ID_L3Downlink_MM_STATUS: Dump_c_MM_STATUS (OStream, Data->Data.fld_c_MM_STATUS); break;
		case ID_L3Downlink_TMSI_REALLOCATION_COMMAND_DN: Dump_c_TMSI_REALLOCATION_COMMAND_DN (OStream, Data->Data.fld_c_TMSI_REALLOCATION_COMMAND_DN); break;
		case ID_L3Downlink_ALERTING_DN: Dump_c_ALERTING_DN (OStream, Data->Data.fld_c_ALERTING_DN); break;
		case ID_L3Downlink_CALL_PROCEEDING_DN: Dump_c_CALL_PROCEEDING_DN (OStream, Data->Data.fld_c_CALL_PROCEEDING_DN); break;
		case ID_L3Downlink_CONGESTION_CONTROL_DN: Dump_c_CONGESTION_CONTROL_DN (OStream, Data->Data.fld_c_CONGESTION_CONTROL_DN); break;
		case ID_L3Downlink_CONNECT_DN: Dump_c_CONNECT_DN (OStream, Data->Data.fld_c_CONNECT_DN); break;
		case ID_L3Downlink_CONNECT_ACKNOWLEDGE: Dump_c_CONNECT_ACKNOWLEDGE (OStream, Data->Data.fld_c_CONNECT_ACKNOWLEDGE); break;
		case ID_L3Downlink_DISCONNECT_DN: Dump_c_DISCONNECT_DN (OStream, Data->Data.fld_c_DISCONNECT_DN); break;
		case ID_L3Downlink_FACILITY_DN: Dump_c_FACILITY_DN (OStream, Data->Data.fld_c_FACILITY_DN); break;
		case ID_L3Downlink_HOLD_ACKNOWLEDGE_DN: Dump_c_HOLD_ACKNOWLEDGE_DN (OStream, Data->Data.fld_c_HOLD_ACKNOWLEDGE_DN); break;
		case ID_L3Downlink_HOLD_REJECT_DN: Dump_c_HOLD_REJECT_DN (OStream, Data->Data.fld_c_HOLD_REJECT_DN); break;
		case ID_L3Downlink_MODIFY: Dump_c_MODIFY (OStream, Data->Data.fld_c_MODIFY); break;
		case ID_L3Downlink_MODIFY_COMPLETE: Dump_c_MODIFY_COMPLETE (OStream, Data->Data.fld_c_MODIFY_COMPLETE); break;
		case ID_L3Downlink_MODIFY_REJECT: Dump_c_MODIFY_REJECT (OStream, Data->Data.fld_c_MODIFY_REJECT); break;
		case ID_L3Downlink_NOTIFY: Dump_c_NOTIFY (OStream, Data->Data.fld_c_NOTIFY); break;
		case ID_L3Downlink_PROGRESS_DN: Dump_c_PROGRESS_DN (OStream, Data->Data.fld_c_PROGRESS_DN); break;
		case ID_L3Downlink_CC_ESTABLISHMENT_DN: Dump_c_CC_ESTABLISHMENT_DN (OStream, Data->Data.fld_c_CC_ESTABLISHMENT_DN); break;
		case ID_L3Downlink_RELEASE_DN: Dump_c_RELEASE_DN (OStream, Data->Data.fld_c_RELEASE_DN); break;
		case ID_L3Downlink_RECALL_DN: Dump_c_RECALL_DN (OStream, Data->Data.fld_c_RECALL_DN); break;
		case ID_L3Downlink_RELEASE_COMPLETE_DN: Dump_c_RELEASE_COMPLETE_DN (OStream, Data->Data.fld_c_RELEASE_COMPLETE_DN); break;
		case ID_L3Downlink_RETRIEVE_ACKNOWLEDGE_DN: Dump_c_RETRIEVE_ACKNOWLEDGE_DN (OStream, Data->Data.fld_c_RETRIEVE_ACKNOWLEDGE_DN); break;
		case ID_L3Downlink_RETRIEVE_REJECT_DN: Dump_c_RETRIEVE_REJECT_DN (OStream, Data->Data.fld_c_RETRIEVE_REJECT_DN); break;
		case ID_L3Downlink_SETUP_DN: Dump_c_SETUP_DN (OStream, Data->Data.fld_c_SETUP_DN); break;
		case ID_L3Downlink_START_DTMF_ACKNOWLEDGE_DN: Dump_c_START_DTMF_ACKNOWLEDGE_DN (OStream, Data->Data.fld_c_START_DTMF_ACKNOWLEDGE_DN); break;
		case ID_L3Downlink_START_DTMF_REJECT_DN: Dump_c_START_DTMF_REJECT_DN (OStream, Data->Data.fld_c_START_DTMF_REJECT_DN); break;
		case ID_L3Downlink_STATUS: Dump_c_STATUS (OStream, Data->Data.fld_c_STATUS); break;
		case ID_L3Downlink_STATUS_ENQUIRY: Dump_c_STATUS_ENQUIRY (OStream, Data->Data.fld_c_STATUS_ENQUIRY); break;
		case ID_L3Downlink_STOP_DTMF_ACKNOWLEDGE_DN: Dump_c_STOP_DTMF_ACKNOWLEDGE_DN (OStream, Data->Data.fld_c_STOP_DTMF_ACKNOWLEDGE_DN); break;
		case ID_L3Downlink_USER_INFORMATION: Dump_c_USER_INFORMATION (OStream, Data->Data.fld_c_USER_INFORMATION); break;
		case ID_L3Downlink_ATTACH_REQUEST_UP: Dump_c_ATTACH_REQUEST_UP (OStream, Data->Data.fld_c_ATTACH_REQUEST_UP); break;
		case ID_L3Downlink_ATTACH_ACCEPT_DN: Dump_c_ATTACH_ACCEPT_DN (OStream, Data->Data.fld_c_ATTACH_ACCEPT_DN); break;
		case ID_L3Downlink_ATTACH_REJECT_DN: Dump_c_ATTACH_REJECT_DN (OStream, Data->Data.fld_c_ATTACH_REJECT_DN); break;
		case ID_L3Downlink_DETACH_REQUEST_DN: Dump_c_DETACH_REQUEST_DN (OStream, Data->Data.fld_c_DETACH_REQUEST_DN); break;
		case ID_L3Downlink_DETACH_ACCEPT_DN: Dump_c_DETACH_ACCEPT_DN (OStream, Data->Data.fld_c_DETACH_ACCEPT_DN); break;
		case ID_L3Downlink_P_TMSI_REALLOCATION_COMMAND_DN: Dump_c_P_TMSI_REALLOCATION_COMMAND_DN (OStream, Data->Data.fld_c_P_TMSI_REALLOCATION_COMMAND_DN); break;
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REQUEST_DN: Dump_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN (OStream, Data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN); break;
		case ID_L3Downlink_AUTHENTICATION_AND_CIPHERING_REJECT_DN: Dump_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN (OStream, Data->Data.fld_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN); break;
		case ID_L3Downlink_IDENTITY_REQUEST_B_DN: Dump_c_IDENTITY_REQUEST_B_DN (OStream, Data->Data.fld_c_IDENTITY_REQUEST_B_DN); break;
		case ID_L3Downlink_ROUTING_AREA_UPDATE_ACCEPT_DN: Dump_c_ROUTING_AREA_UPDATE_ACCEPT_DN (OStream, Data->Data.fld_c_ROUTING_AREA_UPDATE_ACCEPT_DN); break;
		case ID_L3Downlink_ROUTING_AREA_UPDATE_REJECT_DN: Dump_c_ROUTING_AREA_UPDATE_REJECT_DN (OStream, Data->Data.fld_c_ROUTING_AREA_UPDATE_REJECT_DN); break;
		case ID_L3Downlink_GMM_STATUS: Dump_c_GMM_STATUS (OStream, Data->Data.fld_c_GMM_STATUS); break;
		case ID_L3Downlink_GMM_INFORMATION_DN: Dump_c_GMM_INFORMATION_DN (OStream, Data->Data.fld_c_GMM_INFORMATION_DN); break;
		case ID_L3Downlink_SERVICE_ACCEPT_DN: Dump_c_SERVICE_ACCEPT_DN (OStream, Data->Data.fld_c_SERVICE_ACCEPT_DN); break;
		case ID_L3Downlink_SERVICE_REJECT_DN: Dump_c_SERVICE_REJECT_DN (OStream, Data->Data.fld_c_SERVICE_REJECT_DN); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_XTIDUplink (TEDOStream* OStream, const TXTIDUplink_Data* Data)
{
	switch (Data->Type) {
		case ID_XTIDUplink_ACTIVATE_PDP_CONTEXT_REQUEST_UP: Dump_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP (OStream, Data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP); break;
		case ID_XTIDUplink_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP: Dump_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP (OStream, Data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP); break;
		case ID_XTIDUplink_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP: Dump_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP (OStream, Data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP); break;
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_REQUEST_UP: Dump_c_MODIFY_PDP_CONTEXT_REQUEST_UP (OStream, Data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_UP); break;
		case ID_XTIDUplink_MODIFY_PDP_CONTEXT_ACCEPT_UP: Dump_c_MODIFY_PDP_CONTEXT_ACCEPT_UP (OStream, Data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_UP); break;
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_REQUEST: Dump_c_DEACTIVATE_PDP_CONTEXT_REQUEST (OStream, Data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST); break;
		case ID_XTIDUplink_DEACTIVATE_PDP_CONTEXT_ACCEPT: Dump_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT); break;
		case ID_XTIDUplink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT: Dump_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT (OStream, Data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT); break;
		case ID_XTIDUplink_SM_STATUS: Dump_c_SM_STATUS (OStream, Data->Data.fld_c_SM_STATUS); break;
		case ID_XTIDUplink_ACTIVATE_MBMS_CONTEXT_REQUEST: Dump_c_ACTIVATE_MBMS_CONTEXT_REQUEST (OStream, Data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REQUEST); break;
		case ID_XTIDUplink_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT: Dump_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT (OStream, Data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT); break;
		default:;
	}
}
/* RECOGNIZER DUMP - <1> <0> */
void Dump_XTIDDownlink (TEDOStream* OStream, const TXTIDDownlink_Data* Data)
{
	switch (Data->Type) {
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_ACCEPT_DN: Dump_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN (OStream, Data->Data.fld_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN); break;
		case ID_XTIDDownlink_ACTIVATE_PDP_CONTEXT_REJECT_DN: Dump_c_ACTIVATE_PDP_CONTEXT_REJECT_DN (OStream, Data->Data.fld_c_ACTIVATE_PDP_CONTEXT_REJECT_DN); break;
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN: Dump_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN (OStream, Data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN); break;
		case ID_XTIDDownlink_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN: Dump_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN (OStream, Data->Data.fld_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN); break;
		case ID_XTIDDownlink_REQUEST_PDP_CONTEXT_ACTIVATION_DN: Dump_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN (OStream, Data->Data.fld_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN); break;
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REQUEST_DN: Dump_c_MODIFY_PDP_CONTEXT_REQUEST_DN (OStream, Data->Data.fld_c_MODIFY_PDP_CONTEXT_REQUEST_DN); break;
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_ACCEPT_DN: Dump_c_MODIFY_PDP_CONTEXT_ACCEPT_DN (OStream, Data->Data.fld_c_MODIFY_PDP_CONTEXT_ACCEPT_DN); break;
		case ID_XTIDDownlink_MODIFY_PDP_CONTEXT_REJECT_DN: Dump_c_MODIFY_PDP_CONTEXT_REJECT_DN (OStream, Data->Data.fld_c_MODIFY_PDP_CONTEXT_REJECT_DN); break;
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_REQUEST: Dump_c_DEACTIVATE_PDP_CONTEXT_REQUEST (OStream, Data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_REQUEST); break;
		case ID_XTIDDownlink_DEACTIVATE_PDP_CONTEXT_ACCEPT: Dump_c_DEACTIVATE_PDP_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_DEACTIVATE_PDP_CONTEXT_ACCEPT); break;
		case ID_XTIDDownlink_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION: Dump_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION (OStream, Data->Data.fld_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION); break;
		case ID_XTIDDownlink_NOTIFICATION: Dump_c_NOTIFICATION (OStream, Data->Data.fld_c_NOTIFICATION); break;
		case ID_XTIDDownlink_SM_STATUS: Dump_c_SM_STATUS (OStream, Data->Data.fld_c_SM_STATUS); break;
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_ACCEPT: Dump_c_ACTIVATE_MBMS_CONTEXT_ACCEPT (OStream, Data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_ACCEPT); break;
		case ID_XTIDDownlink_ACTIVATE_MBMS_CONTEXT_REJECT: Dump_c_ACTIVATE_MBMS_CONTEXT_REJECT (OStream, Data->Data.fld_c_ACTIVATE_MBMS_CONTEXT_REJECT); break;
		case ID_XTIDDownlink_REQUEST_MBMS_CONTEXT_ACTIVATION: Dump_c_REQUEST_MBMS_CONTEXT_ACTIVATION (OStream, Data->Data.fld_c_REQUEST_MBMS_CONTEXT_ACTIVATION); break;
		default:;
	}
}
